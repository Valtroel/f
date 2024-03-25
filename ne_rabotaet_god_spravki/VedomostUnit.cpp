// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "VedomostUnit.h"
#include "DataModule.h"
#include "CalendarUnit.h"
#include "DM2Unit.h"
#include "VedUnit.h"
#include "DialogVed.h"
#include "DualList.h"
#include "DataModule_Card.h"
// ---------------------------------------------------------------------------
#pragma package (smart_init)
// !!!#pragma link "RXDBCtrl"
// !!!#pragma link "ToolEdit"
// !!!#pragma link "RxLookup"
// !!!#pragma link "MyList"
#pragma resource "*.dfm"
TVedomostForm *VedomostForm;
AnsiString *nom_peop[2]; // ������ ������� � ������� ���������
int *mas_nom_plan[2]; // ������ ������� ��������� � ������� �����

int ink_group; // ��������� ������
int count_rec; // ���������� ������� � Query (People_Part ��� People_Specializ)
int nom_plan1, zach;
// ��������� �������� �����, ��� �������� (����� ��� ���. �����)
int nom_predm; // �������� ��������
int n_spec;

bool del_mas_stud = false; // ���������� ���� �� ������� ������ ���������
bool del_mas_plan = false;
// ���������� ���� �� ������� ������ ��������� � ������� �����

// ---------------------------------------------------------------------------
__fastcall TVedomostForm::TVedomostForm (TComponent* Owner) : TForm (Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TVedomostForm::Edit1Enter (TObject *Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> ShowModal ();
    // Edit1 -> Text=cal_date;
    if (calendar)
        Edit1 -> Text = cal_date;
    if (DataModule1 -> VedomostFDQuery -> State == dsInsert)
        DBEdit2 -> SetFocus ();
}

// --------------------------------------------------------------------------------
void __fastcall TVedomostForm::BitBtn1Click (TObject *Sender) {
    // int state_quer=0;
    if (DataModule1 -> VedomostFDQuery -> State == dsEdit)
    { // ��� �������������� ��������� �������� ����� ������ 2 ���� ����, �  DBEdit ���
        DataModule1 -> VedomostFDQueryD_VED -> Value =
            StrToSQLTimeStamp (Edit1 -> Text);
        DataModule1 -> VedomostFDQuery -> ApplyUpdates ();
        DataModule1 -> VedomostFDQuery -> CommitUpdates ();
    } // end if Edit
    else { // else ���� ������� ����� ���������
        if (ComboBox1 -> Text == "") {
            ShowMessage ("�������� ����������!");
            return;
        }

        nom_plan1 = mas_nom_plan[0][ComboBox1 -> ItemIndex];
        zach = mas_nom_plan[1][ComboBox1 -> ItemIndex];

        if ( (!ComboBox2 -> ItemIndex && ( (zach == 1) || (zach == 3) ||
            (zach == 0))) || ComboBox2 -> ItemIndex) {
            OKBottomDlg = new TOKBottomDlg (this);
            if (!ComboBox2 -> ItemIndex)
                OKBottomDlg -> Label5 -> Caption =
                    "���� ���������\n�������� ������:";
            else
                OKBottomDlg -> Label5 -> Caption = "���� �����\n���������:";
            OKBottomDlg -> ShowModal ();

        }

        // if (DataModule1 -> VedomostQuery -> State==dsInsert) state_quer=1;
        DataModule1 -> VedomostFDQueryN_VEDOMOST -> Value =
            StrToInt (Label4 -> Caption);
        DataModule1 -> VedomostFDQueryD_VED -> Value =
            StrToSQLTimeStamp (Edit1 -> Text);
        DataModule1 -> VedomostFDQuerySEMESTR_VED -> Value = Edit3 -> Text.ToInt ();
        DataModule1 -> VedomostFDQueryN_PLAN -> Value = nom_plan1;
        DataModule1 -> VedomostFDQuerySTATUS -> Value = 0;
        DataModule1 -> VedomostFDQueryN_FAC -> Value = nom_fac;
        try { // try
            // ���������� ��������� ���������, ��� �� �������� � ������ ���� ����� ������������� ��������
            int nom_v = DataModule1 -> VedomostFDQueryN_VED -> Value;
            DataModule1 -> VedomostFDQueryINC_GROUP -> Value = ink_group;
            if (CheckBox1 -> Checked)
            { // ���� ������� ��������� �� �������������, �� ������� ��������� ������ ����.
                if (ComboBox3 -> Text != "") {
                    n_spec = DM2 -> SpecializFDTable -> Lookup ("SPECIAL",
                        ComboBox3 -> Text, "N_SPECIALIZ");
                    DataModule1 -> VedomostFDQueryN_SPECIALIZ -> Value = n_spec;
                }
                else // ���� �� �������  ��������� �� �������������
                {
                    ShowMessage (
                        "�� �� ������� �� ����� ������������� ������ ���������!");
                    // DataModule1 -> VedomostQuery -> CancelUpdates ();
                    return;

                }
            } // end if  ������� ��������� �� �������������
            if (DataModule1 -> VedomostFDQueryN_VEDOMOST -> Value !=
                Ved_Form -> max_ved (uch_god)) {
                DataModule1 -> VedomostFDQueryN_VEDOMOST -> Value =
                    Ved_Form -> max_ved (uch_god);
                ShowMessage ("����� ����� ��������� ��������� �� " +
                    AnsiString (DataModule1 -> VedomostFDQueryN_VEDOMOST -> Value));
            }

            DataModule1 -> VedomostFDQuery -> ApplyUpdates ();
            DataModule1 -> VedomostFDQuery -> CommitUpdates ();
            DataModule1 -> FDConnection1 -> Commit ();

            // if (state_quer==1)
            // {  //if Insert Vedomost
            // --------------------------------
            /* AnsiString str_sql="",temp;
             DataModule1 -> VedomostQuery -> Close ();
             DataModule1 -> VedomostQuery -> SQL -> Clear ();
             DataModule1 -> VedomostQuery -> SQL -> Add ("SELECT Vedomost.N_VED, Vedomost.N_VEDOMOST, Vedomost.D_VED, Vedomost.SEMESTR_VED, Vedomost.FIO_EXAM, Vedomost.STATUS, Vedomost.N_PLAN, Vedomost.N_FAC, Vedomost.END_D_EXAM, Vedomost.INC_GROUP, Vedomost.N_SPECIALIZ, Object_plan.NAME_OBJECT, Edu_plan.YEAR_PLAN, Edu_plan.VID_EDU_PLAN FROM VEDOMOST Vedomost INNER JOIN EDU_PLAN Edu_plan ON  (Vedomost.N_PLAN = Edu_plan.N_PLAN) INNER JOIN OBJECT_PLAN Object_plan ON  (Edu_plan.N_OBJECT = Object_plan.N_OBJECT) WHERE (N_FAC=:N_FAC) AND (Edu_plan.YEAR_PLAN=:PLAN) AND (N_PLAN="+AnsiString (nom_plan1)+")");
             DataModule1 -> VedomostQuery -> Params -> Items[0] -> AsInteger=nom_fac;
             DataModule1 -> VedomostQuery -> ParamByName ("PLAN") -> Value=uch_god;
             DataModule1 -> VedomostQuery -> Open (); */

            // -----------------------------------------------
            // &&&&&&&&&&&
            // --------------������� ���� ��������� �� ������ ���� �������
            // �������������� �������� ��������� � ���������
            DualListDlg = new TDualListDlg (this);
            DualListDlg -> Caption = "����� ��������� � �������� ���������";
            DualListDlg -> SrcList -> Items -> Clear ();
            DualListDlg -> DstList -> Items -> Clear ();

            // ---------------
            if (CheckBox1 -> State == cbUnchecked)
            { // ���� ��������� �� �� �������������, �.�. �������
                DataModule1 -> People_PartFDQuery -> Close ();
                DataModule1 -> People_PartFDQuery -> SQL -> Clear ();

                DataModule1 -> People_PartFDQuery -> SQL -> Add
                    ("SELECT NOMER, FAM, NAME, OTCH, INC_GROUP, N_GROUP, VID_EDU, KURS, N_FOUND FROM PEOPLE WHERE (N_FAC=" +
                    AnsiString (nom_fac) +
                    ") AND (PEOPLE.STATUS_PEOPLE=1) AND (PEOPLE.INC_GROUP=" +
                    AnsiString (ink_group) + ")");
                DataModule1 -> People_PartFDQuery -> Open ();
                count_rec = DataModule1 -> People_PartFDQuery -> RecordCount;
                if (count_rec)
                { // ���� �������� �� ������� �������� ��� �� �������� ���������

                    for (int i = 0; i < 2; i++) { // for1
                        nom_peop[i] = new AnsiString[count_rec];
                    } // end for1
                    del_mas_stud = true;
                    // ���������� ���� �� ������� ������ ���������
                    for (int i = 0; i < count_rec;
                    i++) // ������������ ������� ���������
                    { // for2
                        // ��� �������� � ����� ������
                        nom_peop[0][i] =
                            DataModule1 -> People_PartFDQueryFAM -> Value + " " +
                            DataModule1 -> People_PartFDQueryNAME -> Value + " " +
                            DataModule1 -> People_PartFDQueryOTCH -> Value;
                        // ����� ��������
                        nom_peop[1][i] =
                            AnsiString (DataModule1 -> People_PartFDQueryNOMER
                            -> Value);
                        // -----------
                        if (CheckBox2 -> State == cbChecked) {
                            DualListDlg -> SrcList -> Items -> AddObject
                                (DataModule1 -> People_PartFDQueryFAM -> Value +
                                " " + DataModule1 -> People_PartFDQueryNAME -> Value
                                + " " + DataModule1 -> People_PartFDQueryOTCH -> 
                                Value, (TObject *) (DataModule1 -> People_PartFDQueryNOMER -> Value));
                        }
                        // ------------

                        DataModule1 -> People_PartFDQuery -> Next ();
                    } // end for2
                } // end if  ���� �������� �� ������� �������� ��� �� �������� ���������
            } // end if ���� ��������� �� �� �������������, �.�. �������
            else // ���� ��������� �� �������������
            { // else
                DataModule1 -> People_SpecializFDQuery -> Close ();
                DataModule1 -> People_SpecializFDQuery -> SQL -> Clear ();
                DataModule1 -> People_SpecializFDQuery -> SQL -> Add
                    ("SELECT People.NOMER, People.FAM, People.NAME, People.OTCH, People.VID_EDU, People.KURS, People.INC_GROUP, People.N_GROUP, Specializ.SPECIAL FROM PEOPLE People INNER JOIN SPECIALIZ Specializ ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) WHERE  (People.N_FAC=" +
                    AnsiString (nom_fac) +
                    ") AND (People.STATUS_PEOPLE = 1) AND (People.INC_GROUP=:G) AND (Specializ.N_SPECIALIZ=:S) ORDER BY Specializ.SPECIAL, People.FAM, People.NAME, People.OTCH");
                DataModule1 -> People_SpecializFDQuery -> Params -> Items[0]
                    -> AsInteger = ink_group;
                DataModule1 -> People_SpecializFDQuery -> Params -> Items[1]
                    -> AsInteger = n_spec;
                DataModule1 -> People_SpecializFDQuery -> Open ();

                count_rec = DataModule1 -> People_SpecializFDQuery -> RecordCount;
                if (count_rec)
                { // ���� �������� �� ������� �������� ��� �� �������� ���������
                    for (int i = 0; i < 2; i++) { // for1
                        nom_peop[i] = new AnsiString[count_rec];
                    } // end for1
                    del_mas_stud = true;
                    for (int i = 0; i < count_rec;
                    i++) // ������������ ������� ��������� ��� �������������
                    { // for2
                        // ��� �������� � ����� ������
                        nom_peop[0][i] =
                            DataModule1 -> People_SpecializFDQueryFAM -> Value +
                            " " + DataModule1 -> People_SpecializFDQueryNAME -> 
                            Value + " " +
                            DataModule1 -> People_SpecializFDQueryOTCH -> Value;
                        // ����� ��������
                        nom_peop[1][i] =
                            AnsiString (DataModule1 -> People_SpecializFDQueryNOMER
                            -> Value);

                        // -----------
                        if (CheckBox2 -> State == cbChecked) {
                            DualListDlg -> SrcList -> Items -> AddObject
                                (DataModule1 -> People_SpecializFDQueryFAM -> Value
                                + " " + DataModule1 -> People_SpecializFDQueryNAME
                                -> Value + " " +
                                DataModule1 -> People_SpecializFDQueryOTCH -> Value,
                                (TObject *) (DataModule1 -> People_SpecializFDQueryNOMER -> Value));
                        }
                        // ------------

                        DataModule1 -> People_SpecializFDQuery -> Next ();
                    }
                } // end if ���� �������� �� ������� �������� ��� �� �������� ���������

            } // end esle ���� ��������� �� �������������

            // &&&&
            // ---------------------------------------
            /* for (int i=0;i<DataModule1 -> VedomostQuery -> RecordCount;i++)
             {
             temp=" (N_VED="+AnsiString (DataModule1 -> VedomostQueryN_VED -> Value);
             if (i!=DataModule1 -> VedomostQuery -> RecordCount-1)
             {
             str_sql+=temp+") OR ";
             }//if
             else  str_sql+=temp+")";
             DataModule1 -> VedomostQuery -> Next ();
             } //for */
            // -----------------------------------------

            // �������� ���� �� ������ ��������� ��� �������� ��� ��������� ����� ������
            DataModule1 -> Result_Ball_For_VedFDQuery -> Close ();
            DataModule1 -> Result_Ball_For_VedFDQuery -> ParamByName ("PLAN")
                -> AsInteger = nom_plan1;
            DataModule1 -> Result_Ball_For_VedFDQuery -> ParamByName ("INC_GR")
                -> AsInteger = ink_group;
            DataModule1 -> Result_Ball_For_VedFDQuery -> Open ();
            for (int i = 0;
            i < DataModule1 -> Result_Ball_For_VedFDQuery -> RecordCount; i++) {
                for (int j = 0; j < count_rec; j++) // &&&&&&&
                {
                    if (DataModule1 -> Result_Ball_For_VedFDQueryNOMER -> Value ==
                        nom_peop[1][j]) {
                        if ( (DataModule1 -> Result_Ball_For_VedFDQueryRESULT -> 
                            Value == 1) ||
                            (DataModule1 -> Result_Ball_For_VedFDQueryRESULT -> 
                            Value == 3) ||
                            (DataModule1 -> Result_Ball_For_VedFDQueryRESULT -> 
                            Value == 4) ||
                            (DataModule1 -> Result_Ball_For_VedFDQueryRESULT -> 
                            Value == 5) ||
                            (DataModule1 -> Result_Ball_For_VedFDQueryRESULT -> 
                            Value == 7) ||
                            (DataModule1 -> Result_Ball_For_VedFDQueryRESULT -> 
                            Value > 13))
                        { // 1- �����; 3 - �����.; 4 - ���.; 5 - ���.; 7 - ����������

                            nom_peop[1][j] = 0;
                        } // if 2
                    } // if 1
                } // for j
                DataModule1 -> Result_Ball_For_VedFDQuery -> Next ();
            } // for i

            // -------------------------------------------
            /* DataModule1 -> Edu_CardQuery -> Close ();
             DataModule1 -> Edu_CardQuery -> SQL -> Clear ();
             DataModule1 -> Edu_CardQuery -> SQL -> Add ("SELECT * FROM EDU_CARD WHERE "+str_sql+" ORDER BY NOMER,N_VED");
             DataModule1 -> Edu_CardQuery -> Open ();

             for (int i=0;i<DataModule1 -> Edu_CardQuery -> RecordCount;i++)
             {
             for (int j=0;j<count_rec;j++)//&&&&&&&
             {
             if (DataModule1 -> Edu_CardQueryNOMER -> Value==nom_peop[j])
             {
             if ( (DataModule1 -> Edu_CardQueryBALL -> Value==1) || (DataModule1 -> Edu_CardQueryBALL -> Value==3) || (DataModule1 -> Edu_CardQueryBALL -> Value==4) || (DataModule1 -> Edu_CardQueryBALL -> Value==5) || (DataModule1 -> Edu_CardQueryBALL -> Value==7))
             { //  1- �����; 3 - �����.; 4 - ���.; 5 - ���.; 7 - ����������

             nom_peop[j]=0;
             }     //if 2
             }   //if 1
             }//for j
             DataModule1 -> Edu_CardQuery -> Next ();
             }//for i */
            // ----------------------------------------------
            TLocateOptions Opt;
            DataModule1 -> VedomostFDQuery -> Locate ("N_VED", nom_v, Opt);
            if (DataModule1 -> Edu_CardFDQuery -> State == dsInactive)
                DataModule1 -> Edu_CardFDQuery -> Open ();
            // &&&&&&&&&&&&&&&&&&&&
            int chet = 0;
            // ���������� ��� ����������� ���� �� ������� �������� ��� ���������
            // -----------------
            if (CheckBox2 -> State == cbUnchecked)
                // ���� �� �������� ����������� ���������������� ������
            { // ��������� �������� �������������
                for (int i = 0; i < count_rec; i++) {
                    if (nom_peop[1][i] != 0) {
                        DataModule1 -> Edu_CardFDQuery -> Insert ();
                        DataModule1 -> Edu_CardFDQueryNOMER -> Value =
                            StrToInt (nom_peop[1][i]);
                        DataModule1 -> Edu_CardFDQueryN_VED -> Value =
                            DataModule1 -> VedomostFDQueryN_VED -> Value;
                        DataModule1 -> Edu_CardFDQueryD_EXAM -> Value =
                            DataModule1 -> VedomostFDQueryD_VED -> Value;
                        DataModule1 -> Edu_CardFDQuery -> ApplyUpdates ();
                        DataModule1 -> Edu_CardFDQuery -> CommitUpdates ();
                        chet++;
                    } // if
                } // for
            } // ��������� �������� �������������
            else { // ��������� � ��������� �������� ����
                DualListDlg -> ShowModal ();
                if (DataModule2 -> printdlg == true)
                { // if ������� ������ �� � ����������
                    if (DualListDlg -> DstList -> Count != 0)
                    { // if �������� �� ����� ���� �� ������ �������� � ���������
                        // ---------
                        for (int i = 0; i < DualListDlg -> DstList -> Count; i++)
                        { // for ������ ���� ��  FOutList
                            if ( (int) (DualListDlg -> DstList -> Items -> Objects[i]) != 0)
                            { // if �������� �� ��, ��� ������� �� ������������
                                // ������ ��� �� ���� �������
                                DataModule1 -> Edu_CardFDQuery -> Insert ();
                                DataModule1 -> Edu_CardFDQueryNOMER -> Value =
                                    Integer (DualListDlg -> DstList -> Items -> Objects[i]);
                                DataModule1 -> Edu_CardFDQueryN_VED -> Value =
                                    DataModule1 -> VedomostFDQueryN_VED -> Value;
                                DataModule1 -> Edu_CardFDQueryD_EXAM -> Value =
                                    DataModule1 -> VedomostFDQueryD_VED -> Value;
                                DataModule1 -> Edu_CardFDQuery -> ApplyUpdates ();
                                DataModule1 -> Edu_CardFDQuery -> CommitUpdates ();
                                chet++;
                            } // end if  ������ ��� �� ���� �������
                            else { // else
                                ShowMessage ("������� " + DualListDlg -> DstList -> Items -> Strings[i] +
                                    " ��� ������ ���� �������!");
                            } // end else
                        } // 1-�� for //for ������ ���� ��  FOutList

                        // ---------

                    } // end if �������� �� ����� ���� �� ������ �������� � ���������
                    else
                        chet = 0; // ��� ��������� ���������
                } // end if ������� ������ �� � ����������
                else { // else ���� �������� � ������ �� �������
                    chet = 0;
                } // end else ���� �������� � ������ �� �������

            } // ��������� � ��������� �������� ����
            // �������� ���� � Edu_CardQuery �� ���� �������� �� ����� ������, �� ��������� ���� �������
            if (!chet)
            { // else ���� ��������� �� chet �� ���������, �� ���� ������� ���������
                if (CheckBox2 -> State == cbUnchecked) {
                    ShowMessage (
                        "�� ����� �������� � ��� ���� ������ ��� ���� ������� ��������� ������!!!!");
                }
                else {
                    ShowMessage (
                        "�� �� ������� ��������� � ��������� ����� �������!");
                }
                TLocateOptions Op;
                DataModule1 -> VedomostFDQuery -> Locate ("N_VED", nom_v, Op);
                DataModule1 -> VedomostFDQuery -> Delete ();
                DataModule1 -> VedomostFDQuery -> ApplyUpdates ();
                DataModule1 -> VedomostFDQuery -> CommitUpdates ();

            } // end if  �� chet
        } // try
        catch (...) {
            ShowMessage ("��������� ������������ ���������� ������ ������!");
        }
        delete DualListDlg;
    } // end else -- ���� ������� ����� ���������

    // ������ ������� ��������� � �������
    if (del_mas_stud) {
        for (int i = 0; i < 2; i++)
            delete[]nom_peop[i];
        // delete[]nom_peop;
        del_mas_stud = false; // ���������� ���� �� ������� ������ ���������
    }
    Close ();
}
// ---------------------------------------------------------------------------

void __fastcall TVedomostForm::Edit2Exit (TObject *Sender) {
    if (Edit2 -> Text == "") // ���� ���� ������
    {
        // !!!if (Application -> MessageBox ("      ������� ����� ������", "", MB_OKCANCEL) == IDOK)
        if (MessageDlg ("      ������� ����� ������", mtCustom,
            TMsgDlgButtons () << mbOK << mbCancel, 0) == 1) {
            Edit2 -> SetFocus ();
        }
        else {
            DataModule1 -> VedomostFDQuery -> CancelUpdates ();
            Close ();
        }
    }
    else {
        if (nom_fac != DM2 -> FacultyFDTable -> Lookup ("KOD_FAC",
            Edit2 -> Text.SubString (1, 1).ToInt (), "N_FAC")) {
            ShowMessage ("����� ������ �� ������������� ������ ����������");
            Edit2 -> Text = "";
            Edit2 -> SetFocus ();
        }
    } // �������� �� �������� ����
}
// ---------------------------------------------------------------------------

void __fastcall TVedomostForm::FormClose (TObject *Sender, TCloseAction &Action)
{
    // DataModule1 -> VedomostQuery -> CancelUpdates ();
    if (DataModule1 -> VedomostFDQuery -> State == dsInsert ||
        DataModule1 -> VedomostFDQuery -> State == dsEdit)
        DataModule1 -> VedomostFDQuery -> CancelUpdates ();

    if (Ved_Form -> CheckBox1 -> Checked) {
        Ved_Form -> CheckBox1Click (this);
    }
    else {
        Ved_Form -> RadioGroup1Click (this);
    }

    // ������ ������� � �������� ��������� � ������� �����
    if (del_mas_plan) {
        for (int i = 0; i < 2; i++)
            delete[]mas_nom_plan[i];
        // delete[]mas_nom_plan;

    }

    del_mas_plan = false;
    // ���������� ���� �� ������� ������ ��������� � ������� �����
    del_mas_stud = false; // ���������� ���� �� ������� ������ ���������

    Action = caFree;
}
// ---------------------------------------------------------------------------

void __fastcall TVedomostForm::Panel2Click (TObject *Sender) {
    try {
        if (Edit3 -> Text != "" && ComboBox2 -> ItemIndex != -1) {
            ink_group = search_increment_group (Edit2 -> Text,
            ComboBox2 -> ItemIndex);
            ComboBox1 -> Items -> Clear ();

            // ------����� �����

            DataModule1 -> Edu_PlanFDQ -> Close ();
            DataModule1 -> Edu_PlanFDQ -> ParamByName ("N_FAC") -> AsSmallInt =
                nom_fac;
            DataModule1 -> Edu_PlanFDQ -> ParamByName ("PLAN") -> AsSmallInt = uch_god;
            DataModule1 -> Edu_PlanFDQ -> ParamByName ("SEM") -> AsSmallInt =
                StrToInt (Edit3 -> Text);
            DataModule1 -> Edu_PlanFDQ -> ParamByName ("VID") -> AsSmallInt =
                ComboBox2 -> ItemIndex;
            DataModule1 -> Edu_PlanFDQ -> Open ();

            ComboBox1 -> Enabled = true;
            Label6 -> Enabled = true;

            DataModule1 -> Edu_PlanFDQ -> Last ();
            // ��������� �� ��������� �.�. �� �������� RecordCount ??????
            int col_plan = DataModule1 -> Edu_PlanFDQ -> RecordCount;

            // ������ ������� � �������� ��������� � ������� �����
            for (int i = 0; i < 2; i++)
                mas_nom_plan[i] = new int[col_plan];
            del_mas_plan = true;
            // ���������� ���� �� ������� ������ ��������� � ������� �����
            for (int i = 0; i < col_plan; i++) {
                mas_nom_plan[0][i] = DataModule1 -> Edu_PlanFDQN_PLAN -> Value;
                // ����� � ������� ����� N_PLAN
                mas_nom_plan[1][i] = DataModule1 -> Edu_PlanFDQZACH_EXAM -> Value;
                // ��� �������� ZACH_EXAM
                AnsiString z = "";
                switch (DataModule1 -> Edu_PlanFDQZACH_EXAM -> Value) {
                case 0:
                    z = " (��� ��������)";
                    break;
                case 1:
                    z = " (���.)";
                    break;
                case 2:
                    z = " (���.)";
                    break;
                case 3:
                    z = " (���.���.)";
                    break;
                case 4:
                    z = " (���-�������)";
                    break;
                }
                ComboBox1 -> Items -> Add (DataModule1 -> Edu_PlanFDQPP -> Value + z);
                // ����� �������� + ����
                DataModule1 -> Edu_PlanFDQ -> Prior ();
            }

            ComboBox1 -> Style = Stdctrls::csDropDownList;
            CheckBox1 -> Enabled = true;
            // ����������� ������� ��������� �� �������������

        } // if
        else {
            ShowMessage ("��������� ������������ ��������� ������!");
        }
    } // try
    catch (...) {
        ShowMessage ("��������� ������������ ��������� ������!");
    }
}
// ---------------------------------------------------------------------------

void __fastcall TVedomostForm::CheckBox1Click (TObject *Sender) {
    if (CheckBox1 -> Checked) { // if ������� ��������� �� �������������
        ComboBox3 -> Items -> Clear ();
        ComboBox3 -> Style = Stdctrls::csDropDownList;
        ComboBox3 -> Visible = true;
        DataModule1 -> People_SpecializFDQuery -> Close ();
        DataModule1 -> People_SpecializFDQuery -> SQL -> Clear ();
        DataModule1 -> People_SpecializFDQuery -> SQL -> Add
            ("SELECT People.NOMER, People.FAM, People.NAME, People.OTCH, People.VID_EDU, People.KURS, People.INC_GROUP, People.N_GROUP, Specializ.SPECIAL FROM PEOPLE People INNER JOIN SPECIALIZ Specializ ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) WHERE  (People.STATUS_PEOPLE = 1) AND (People.INC_GROUP=:G) ORDER BY Specializ.SPECIAL, People.FAM, People.NAME, People.OTCH"
            );
        DataModule1 -> People_SpecializFDQuery -> Params -> Items[0] -> AsInteger =
            ink_group;
        DataModule1 -> People_SpecializFDQuery -> Open ();
        AnsiString sp = "";

        for (int i = 0;
        i < DataModule1 -> People_SpecializFDQuery -> RecordCount; i++)
        { // for ��� ������������ ������������� ������ ���� ������
            if (sp != DataModule1 -> People_SpecializFDQuerySPECIAL -> Value)
            { // �������� �� ������������� �������� �������������
                sp = DataModule1 -> People_SpecializFDQuerySPECIAL -> Value;
                ComboBox3 -> Items -> Add (sp);
            } // end if  ������������� ��������

            DataModule1 -> People_SpecializFDQuery -> Next ();
        } // end for
    } // end if ������� ��������� �� �������������
    else { // else
        ComboBox3 -> Visible = false;
    } // end else
}
// ---------------------------------------------------------------------------

void __fastcall TVedomostForm::FormShow (TObject *Sender) {
    if (DataModule1 -> VedomostFDQuery -> State != dsInsert)
        DBEdit2 -> SetFocus ();
}
// ---------------------------------------------------------------------------

void __fastcall TVedomostForm::Edit3Change (TObject *Sender) {
    if (ComboBox1 -> Enabled)
    { // if ������ �������, �� �������� �������� ������, �� ������� ������� ������� ����
        ComboBox1 -> Enabled = false;
        Label6 -> Enabled = false;
        ComboBox1 -> Items -> Clear ();
        DataModule1 -> Edu_PlanFDQuery -> Close ();

    } // end if ������ �������, �� �������� �������� ������, �� ������� ������� ������� ����
}
// ---------------------------------------------------------------------------

void __fastcall TVedomostForm::Edit2KeyPress (TObject *Sender, char &Key) {
    DataModule1 -> Edit_Key (Key);
    // ��� �������, ����� � TEdit ����� ���� ������� ������ �����?
}
// ---------------------------------------------------------------------------

void __fastcall TVedomostForm::BitBtn2Click (TObject *Sender) {
    ShowMessage ("����� ������ �� ������������� ������ ����������");
}
// ---------------------------------------------------------------------------
void __fastcall TVedomostForm::BitBtn3Click (TObject *Sender)
{
if (DataModule1 -> VedomostFDQuery -> State == dsEdit)
    {
        DataModule1 -> VedomostFDQueryINVALID -> Value = 1;
        DataModule1 -> VedomostFDQuery -> ApplyUpdates ();
        DataModule1 -> VedomostFDQuery -> CommitUpdates ();
        Close ();
    } // end if Edit
}
//---------------------------------------------------------------------------


void __fastcall TVedomostForm::Edit4Enter (TObject *Sender)
{
CalendarForm = new TCalendarForm (this);
    CalendarForm -> ShowModal ();
    // Edit1 -> Text=cal_date;
    if (calendar)
        Edit4 -> Text = cal_date;
    if (DataModule1 -> VedomostFDQuery -> State == dsInsert)
        DBEdit2 -> SetFocus ();
}
//---------------------------------------------------------------------------


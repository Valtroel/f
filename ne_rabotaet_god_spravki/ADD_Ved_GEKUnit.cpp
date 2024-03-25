#include <vcl.h>
#pragma hdrstop


#include "ADD_Ved_GEKUnit.h"
#include "DataModule_Card.h"
#include "DataModule.h"
#include "DM3Unit.h"
#include "DualList.h"
#include "Ved_GEKUnit.h"


#pragma package (smart_init)
// #pragma link     "MyList"
#pragma link     "frxClass"
// #pragma link     "ToolEdit"
// #pragma link     "RXCtrls"
#pragma resource "*.dfm"


TADD_VedGEK * ADD_VedGEK;


AnsiString inc_nomera_grupp,
           nomera_grupp;



// BitBtn1Click
// BitBtn2Click
// Button1Click
// ComboBox2Change
// DateTimePicker2Change
// Delete_VED
// Edit5KeyPress
// FormClose




// ��������� �������� ��������� � ��������� �����
void __fastcall TADD_VedGEK::Delete_VED (int num) {
    DataModule1 -> Vedomost_GEKFDQuery -> Open ();
    TLocateOptions Op;
    Variant d = DataModule1 -> Vedomost_GEKFDQuery -> Locate ("N_VED", num, Op);
    if (!d.IsNull ()) {
        DataModule1 -> Vedomost_GEKFDQuery -> Delete ();
        DataModule1 -> Vedomost_GEKFDQuery -> ApplyUpdates ();
        DataModule1 -> Vedomost_GEKFDQuery -> CommitUpdates ();
        DataModule1 -> Vedomost_GEKFDQuery -> Close ();
        // ������� �� ������� GEK ���� ��������� ���������
        DM3 -> GEK_PeopleFDQuery -> Close ();
        DM3 -> GEK_PeopleFDQuery -> ParamByName ("N_VED") -> Value = num;
        DM3 -> GEK_PeopleFDQuery -> Open ();
        for (int i = 0; i <= DM3 -> GEK_PeopleFDQuery -> RecordCount - 1; i++) {
            DM3 -> GEK_PeopleFDQuery -> ApplyUpdates ();
            DM3 -> GEK_PeopleFDQuery -> CommitUpdates ();
        } // for
        DM3 -> GEK_PeopleFDQuery -> Close ();
        DataModule1 -> Vedomost_GEKFDQuery -> Close ();
        DM3 -> VED_GEKGridFDQuery -> Close ();
    }
    // DM3 -> VED_GEKGrid -> Open ();
    if (!Ved_GEK -> Open_S (Ved_GEK -> CheckBox1 -> Checked))
        return;
}

__fastcall TADD_VedGEK::TADD_VedGEK (TComponent* Owner) : TForm (Owner) {
}

void __fastcall TADD_VedGEK::FormClose (TObject *Sender, TCloseAction &Action) {
    Action = caFree;
}

void __fastcall TADD_VedGEK::Button1Click (TObject *Sender)
{ // ������������� ��� ������������ ������������� �����
    bool R = true;
    nomera_grupp = ""; // �������� ����������
    inc_nomera_grupp = "";
    for (int i = 0; i < CheckListBox1 -> Items -> Count; i++) { // for
        if (CheckListBox1 -> Checked[i]) { // if ������� ��������� ������
            Variant V = search_increment_group (CheckListBox1 -> Items -> Strings[i],
                ComboBox2 -> ItemIndex);
            // --------
            if (V.IsNull ()) { // if �������� �� ������������ ������ ������
                ShowMessage ("��� ������ ������ ������!!!");
                R = false;
            } // end if �������� �� ������������ ������ ������
            nomera_grupp += CheckListBox1 -> Items -> Strings[i] + ",";
            inc_nomera_grupp += V.AsType (varString);
            inc_nomera_grupp += ",";
        } // end if ������� ��������� ������
    } // end for

    // �������� ���� � ����������� �� ������ ������
    // int n_k=0;
    // n_k=nomera_grupp.SubString (2,1).ToInt ();

    if (ComboBox2 -> Text == "") {
        ShowMessage ("������� ��� ��������");
        R = false;
    }
    if (Edit5 -> Text == "") {
        ShowMessage ("������� ����� ��������� ��� ���. ��������");
        R = false;
    }
    /* if (DateEdit1 -> Text=="  .  .    ")
     {
     ShowMessage ("������� ���� ��������� ��� ���. ��������");
     R=false;
     }

     if (Edit2 -> Text=="")
     {
     ShowMessage ("������� ����� ������");
     R=false;
     } */
    if (R) {
        // ����� ����� ����� ��� ������ ��������
        ADD_VedGEK -> Height = 331;
        Panel2 -> Enabled = true;
        DateTimePicker2 -> Date = Now ();
        // ������������ Query �� ���������
        DM3 -> Predmet_GEKFDQuery -> Close ();
        DM3 -> Predmet_GEKFDQuery -> ParamByName ("N_FAC") -> Value = nom_fac;
        if (ComboBox2 -> ItemIndex == 1) {
            DM3 -> Predmet_GEKFDQuery -> ParamByName ("VID_EDU_PLAN") -> Value = 1;
            // if (n_k==6) DM3 -> Predmet_GEK -> ParamByName ("semestr") -> Value=12;
            DM3 -> Predmet_GEKFDQuery -> ParamByName ("semestr") -> Value = 10;
        }
        else {
            DM3 -> Predmet_GEKFDQuery -> ParamByName ("VID_EDU_PLAN") -> Value = 0;
            DM3 -> Predmet_GEKFDQuery -> ParamByName ("semestr") -> Value = 8;
        }
        DM3 -> Predmet_GEKFDQuery -> ParamByName ("YEAR_PLAN") -> Value = uch_god;
        DM3 -> Predmet_GEKFDQuery -> Open ();
        Edit1 -> SetFocus ();
    }
}

void __fastcall TADD_VedGEK::BitBtn2Click (TObject *Sender) {
    ADD_VedGEK -> Close ();
}

void __fastcall TADD_VedGEK::BitBtn1Click (TObject *Sender)
{ // ������ ������� ���������
    // -----
    if (nomera_grupp == "" || inc_nomera_grupp == "")
    { // if ��������  �� ��������� ������
        ShowMessage ("�������� ����� (�) ������");
        return;
    } // end if ��������  �� ��������� ������
    int Leng_nomer_gr = nomera_grupp.Length () - 1;
    // ������ ����� ���� � �������� ��������� ������ (�������)
    int Leng_inc_nomer_gr = inc_nomera_grupp.Length () - 1;
    // -----
    if (Edit1 -> Text == "") // � ������ ��� ���
    { // if ��������  �������
        ShowMessage ("������� ����� ������ �� �����, ��������: 2!");
        return;
    } // end if �������� �������

    // -----
    if (DBLookupComboBox1 -> Text == "") // �������
    { // if ��������  �������
        ShowMessage ("�������� �������!");
        return;
    } // end if �������� �������
    // -----
    /* if (Edit7 -> Text=="")     //�����������
     {//if ��������  �����������
     ShowMessage ("������� ��� ������������!");
     return;
     }//end if �������� ����������� */
    // -----
    if (MaskEdit2 -> Text == "  :  ") // ������ ��������
    { // if ��������  ������ ��������
        ShowMessage ("�������� ������ ��������!");
        return;
    } // end if �������� ������ ��������
    // -----
    // ������� Query ��� Grid
    DM3 -> VED_GEKGridFDQuery -> Close ();
    ////////////////////////////
    DataModule1 -> Vedomost_GEKFDQuery -> Open ();
    DataModule1 -> Vedomost_GEKFDQuery -> Insert ();
    DM3 -> GET_N_VedGEKFDStoredProc -> Prepare ();
    DM3 -> GET_N_VedGEKFDStoredProc -> ExecProc ();
    int nomer = DM3 -> GET_N_VedGEKFDStoredProc -> ParamByName ("NVGEK") -> AsInteger;
    DataModule1 -> Vedomost_GEKFDQueryN_VED -> Value = nomer;
    try { // try �������� �� ���� ��������� ��������
        DataModule1 -> Vedomost_GEKFDQueryN_VEDOMOST -> Value = StrToInt (Edit5 -> Text);
    } // end try �������� �� ���� ��������� ��������
    catch (...) { // catch  � ������ ������
        ShowMessage ("����� ��������� ������ ���� �������� ���������!");
        DataModule1 -> Vedomost_GEKFDQuery -> CancelUpdates ();
        return;
    } // end catch � ������ ������
    DataModule1 -> Vedomost_GEKFDQueryN_GROUP_SP -> Value = Edit1 -> Text;
    // DM3 -> Vedomost_GEKD_VED -> Value=StrToDate (DateEdit1 -> Text); //�������� �����
    DataModule1 -> Vedomost_GEKFDQueryD_VED -> Value =
        DateTimeToSQLTimeStamp (DateTimePicker2 -> Date);
    // DM3 -> Vedomost_GEKFIO_EXAM -> Value=Edit7 -> Text; //�������� �����
    // ����� �������� �����
    DataModule1 -> Vedomost_GEKFDQueryN_PLAN -> Value = DBLookupComboBox1 -> KeyValue;
    DataModule1 -> Vedomost_GEKFDQueryN_FAC -> Value = nom_fac;
    DataModule1 -> Vedomost_GEKFDQueryINC_GROUP -> Value =
        nomera_grupp.SubString (1, Leng_nomer_gr);
    // --------
    try { // try �� ����������

        DataModule1 -> Vedomost_GEKFDQuery -> ApplyUpdates ();
        DataModule1 -> Vedomost_GEKFDQuery -> CommitUpdates ();
        DataModule1 -> Vedomost_GEKFDQuery -> Close ();
        DM3 -> GET_N_VedGEKFDStoredProc -> Unprepare ();
    } // end try �� ����������
    catch (...) {
        DataModule1 -> Vedomost_GEKFDQuery -> CancelUpdates ();
        ShowMessage ("���� � ������������");
        return;
    }
    // ���������� ��������������� ID

    ///���   ���������� Grid
    // DM3 -> VED_GEKGrid -> Open ();
    if (!Ved_GEK -> Open_S (Ved_GEK -> CheckBox1 -> Checked))
        return;
    // ������������ ��������������� Query
    DM3 -> VED_GEKPeopleFDQuery -> Close ();
    DM3 -> VED_GEKPeopleFDQuery -> SQL -> Clear ();

    /* ��-�� ��������� �������� ������� ��� (� ������� ��������� �������� �� ������ ���� SQL ������

     DM3 -> VED_GEKPeople -> SQL -> Add ("SELECT People.NOMER, People.FAM, People.NAME, People.OTCH, People.VID_EDU, People.N_FAC, People.KURS, People.N_SPEC, People.N_SPECIALIZ, People.N_PRIKAZ_KURS, People.N_GROUP, People.STATUS_PEOPLE, People.INC_GROUP, People.N_ZACHET, Increment_group.VID_EDU, Increment_group.GOD, Increment_group.N_GROUP, Public_prikaz.N_TYPE, Public_prikaz.N_PUBLIC_PRIKAZ, Public_prikaz.D_PUBLIC_PRIKAZ, Public_prikaz.DESCRIBE, Public_prikaz.NOMER, Specializ.SPECIAL\
     FROM PEOPLE People  INNER JOIN INCREMENT_GROUP Increment_group  ON  (People.INC_GROUP = Increment_group.INC_GROUP)\
     INNER JOIN PUBLIC_PRIKAZ Public_prikaz   ON  (People.NOMER = Public_prikaz.NOMER) INNER JOIN SPECIALIZ Specializ\
     ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) where (People.STATUS_PEOPLE=1) and (People.INC_GROUP IN ("+inc_nomera_grupp.SubString (1,Leng_inc_nomer_gr)+"))\
     and (People.N_FAC="+AnsiString (nom_fac)+") and   (Public_prikaz.N_TYPE=12) ORDER BY People.FAM, People.NAME, People.OTCH");

     //������ ������ SQL    ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) where (People.STATUS_PEOPLE=1) and (People.INC_GROUP="+AnsiString (Inc)+")\
     */

    // ����� SQL
    DM3 -> VED_GEKPeopleFDQuery -> SQL -> Add ("SELECT people.NOMER, People.FAM, People.NAME, People.OTCH, People.VID_EDU, People.N_FAC, \
              People.KURS, People.N_SPEC, People.N_SPECIALIZ, People.N_PRIKAZ_KURS, People.N_GROUP, \
              People.STATUS_PEOPLE, People.INC_GROUP, People.N_ZACHET, Specializ.SPECIAL  \
            FROM PEOPLE People  \
            left JOIN SPECIALIZ Specializ ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ)  \
            where (People.STATUS_PEOPLE=1) and (People.INC_GROUP IN (" +
        inc_nomera_grupp.SubString (1, Leng_inc_nomer_gr) + ")) \
            and (People.N_FAC=" + AnsiString (nom_fac) + ")  \
            and exists (select distinct public_prikaz.nomer from public_prikaz  where   public_prikaz.nomer=people.nomer and Public_prikaz.N_TYPE=12)  \
            ORDER BY People.FAM, People.NAME, People.OTCH");

    DM3 -> VED_GEKPeopleFDQuery -> Open ();
    DM3 -> VED_GEKPeopleFDQuery -> First ();

    // ���������� � MyList �����
    // ������������ �������� �������
    AnsiString *mas_stud[3]; // ������ ������� � ������� ���������
    for (int i = 0; i < 3; i++)
        mas_stud[i] = new AnsiString[DM3 -> VED_GEKPeopleFDQuery -> RecordCount];
    //////////////////////////////////////////////////////////////////////////
    DualListDlg = new TDualListDlg (this);
    DualListDlg -> SrcList -> Items -> Clear ();
    DualListDlg -> DstList -> Items -> Clear ();
    int jj = 0; // ���������� ��� �������
    ////////////////////////////////////////////////////
    // ��� ���������
    for (int j = 0; j <= DM3 -> VED_GEKPeopleFDQuery -> RecordCount - 1; j++) {
        DM3 -> Proverka_VED_GEKPeopleFDQuery -> Close ();
        DM3 -> Proverka_VED_GEKPeopleFDQuery -> ParamByName ("NOMER") -> Value =
            DM3 -> VED_GEKPeopleFDQueryNOMER -> Value;
        DM3 -> Proverka_VED_GEKPeopleFDQuery -> ParamByName ("N_PLAN") -> Value =
            DBLookupComboBox1 -> KeyValue;
        DM3 -> Proverka_VED_GEKPeopleFDQuery -> Open ();
        if ( (DM3 -> Proverka_VED_GEKPeopleFDQuery -> RecordCount == 0) ||
            (DM3 -> Proverka_VED_GEKPeopleFDQuery -> RecordCount == 1 &&
            DM3 -> Proverka_VED_GEKPeopleFDQueryBALL_GEK -> Value == 6)) {
            mas_stud[0][jj] = DM3 -> VED_GEKPeopleFDQueryFAM -> Value + " " +
                DM3 -> VED_GEKPeopleFDQueryNAME -> Value + " " +
                DM3 -> VED_GEKPeopleFDQueryOTCH -> Value;
            mas_stud[2][jj] = DM3 -> VED_GEKPeopleFDQuerySPECIAL -> Value;
            DualListDlg -> SrcList -> Items -> AddObject
                (mas_stud[0][jj] + " (" + mas_stud[2][jj] + ")",
                (TObject *) (DM3 -> VED_GEKPeopleFDQueryNOMER -> Value));
            mas_stud[1][jj] = AnsiString (DM3 -> VED_GEKPeopleFDQueryNOMER -> Value);

            jj++;
        } // if
        DM3 -> VED_GEKPeopleFDQuery -> Next ();
    } // for  ��� ���������

    DualListDlg -> ShowModal ();
    if (DataModule2 -> printdlg == true) {
        if (DualListDlg -> DstList -> Count != 0 && DualListDlg -> DstList -> Count <= 18) {

            // ������������ Query ��� ������ ���������
            AnsiString Str_Nomer = "";
            for (int i = 0; i <= DualListDlg -> DstList -> Items -> Count - 1; i++) {
                Str_Nomer += String ( (int) (DualListDlg -> DstList -> Items -> Objects[i])) + ",";
                // ���������� ����� ��������
            } // 1-�� for

            Str_Nomer.SetLength (Str_Nomer.Length () - 1);
            // ������������ Query ��� ������
            DM3 -> VED_GEKPeopleFDQuery -> Close ();
            DM3 -> VED_GEKPeopleFDQuery -> SQL -> Clear ();

            /* ��-�� ��������� �������� ������� ��� (� ������� ��������� �������� �� ������ ���� SQL ������

             DM3 -> VED_GEKPeople -> SQL -> Add ("SELECT People.NOMER, People.FAM, People.NAME, People.OTCH, People.VID_EDU, People.N_FAC, People.KURS, People.N_SPEC, People.N_SPECIALIZ, People.N_PRIKAZ_KURS, People.N_GROUP, People.STATUS_PEOPLE, People.INC_GROUP, People.N_ZACHET, Increment_group.VID_EDU, Increment_group.GOD, Increment_group.N_GROUP, Public_prikaz.N_TYPE, Public_prikaz.N_PUBLIC_PRIKAZ, Public_prikaz.D_PUBLIC_PRIKAZ, Public_prikaz.DESCRIBE, Public_prikaz.NOMER, Specializ.SPECIAL\
             FROM PEOPLE People  INNER JOIN INCREMENT_GROUP Increment_group  ON  (People.INC_GROUP = Increment_group.INC_GROUP)\
             INNER JOIN PUBLIC_PRIKAZ Public_prikaz   ON  (People.NOMER = Public_prikaz.NOMER) INNER JOIN SPECIALIZ Specializ\
             ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) where (People.STATUS_PEOPLE=1) and (People.INC_GROUP IN ("+inc_nomera_grupp.SubString (1,Leng_inc_nomer_gr)+"))\
             and (People.N_FAC="+AnsiString (nom_fac)+") and   (Public_prikaz.N_TYPE=12)\
             AND (NOMER IN ("+Str_Nomer+")) ORDER BY People.FAM, People.NAME, People.OTCH"); */

            // ����� SQL
            DM3 -> VED_GEKPeopleFDQuery -> SQL -> Add ("SELECT people.NOMER, People.FAM, People.NAME, People.OTCH, People.VID_EDU, People.N_FAC, \
              People.KURS, People.N_SPEC, People.N_SPECIALIZ, People.N_PRIKAZ_KURS, People.N_GROUP, \
              People.STATUS_PEOPLE, People.INC_GROUP, People.N_ZACHET, Specializ.SPECIAL  \
             FROM PEOPLE People  \
             left JOIN SPECIALIZ Specializ ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ)  \
             where (People.STATUS_PEOPLE=1) and (People.INC_GROUP IN (" +
                inc_nomera_grupp.SubString (1, Leng_inc_nomer_gr) + ")) \
             and (People.N_FAC=" + AnsiString (nom_fac) + ")  \
             AND (NOMER IN (" + Str_Nomer + "))  \
             and exists (select distinct public_prikaz.nomer from public_prikaz  where   public_prikaz.nomer=people.nomer and Public_prikaz.N_TYPE=12)  \
             ORDER BY People.FAM, People.NAME, People.OTCH");

            DM3 -> VED_GEKPeopleFDQuery -> Open ();

            // ������� ��������� � ������� GEK
            DM3 -> VED_GEKPeopleFDQuery -> First ();
            for (int i = 0; i <= DM3 -> VED_GEKPeopleFDQuery -> RecordCount -
                1; i++) {
                DataModule1 -> GEKFDQuery -> Open ();
                DataModule1 -> GEKFDQuery -> Insert ();
                DataModule1 -> GEKFDQueryNOMER -> Value =
                    DM3 -> VED_GEKPeopleFDQueryNOMER -> Value;
                DataModule1 -> GEKFDQueryN_VED -> Value = nomer;
                DataModule1 -> GEKFDQueryD_GEK -> Value =
                    StrToSQLTimeStamp (DateToStr (DateTimePicker2 -> Date) +
                    MaskEdit2 -> Text);

                try {
                    DataModule1 -> GEKFDQuery -> ApplyUpdates ();
                    DataModule1 -> GEKFDQuery -> CommitUpdates ();
                    DataModule1 -> GEKFDQuery -> Close ();
                }
                catch (...) {
                    ShowMessage ("���� � ������������");
                    //////////////////////////////////////////////////////////////////////
                    // ��� ���� ������������ ��������� �������
                    Delete_VED (nomer);
                    ADD_VedGEK -> Close ();
                }
                DM3 -> VED_GEKPeopleFDQuery -> Next ();
            }

            DM3 -> VED_GEKPeopleFDQuery -> Close ();
            ShowMessage (
                "������������ ��������� ���������! ��� ��������� ��� ������ ������� ������ ������");
            ADD_VedGEK -> Close ();
        } // if  MyList1 -> FOutList -> Count!=0  � >=14
        else {
            ShowMessage (
                "�� �� ������� �� ������ �������� ��� ��������� ������ 18! ���������� ��� ���");
            // ������� ��������� ���������
            Delete_VED (nomer);
            ADD_VedGEK -> Close ();
        }

    } // if MyList1 -> Execute (MyList1)
    else
        // ����������� �����, ����� ������ ������ � MyList
    {
        Delete_VED (nomer);
        ADD_VedGEK -> Close ();
    }
    delete DualListDlg;
}

void __fastcall TADD_VedGEK::ComboBox2Change (TObject *Sender) {
    DM3 -> Group_VipuskFDQuery -> Close ();
    DM3 -> Group_VipuskFDQuery -> SQL -> Clear ();
    DM3 -> Group_VipuskFDQuery -> Params -> Clear ();
    DM3 -> Group_VipuskFDQuery -> SQL -> Add (SQL_rem);
    DM3 -> Group_VipuskFDQuery -> ParamByName ("VID_EDU") -> Value =
        ComboBox2 -> ItemIndex;
    AnsiString Param_s = "", Param_b = "";
    if (nom_fac != 3) {
        Param_s = IntToStr (nom_fac);
        Param_b = IntToStr (nom_fac);
    }
    else {
        Param_s = "0";
        Param_b = "0";
    }
    if (ComboBox2 -> ItemIndex == 1) {
        Param_s += "";
        Param_b += "5_";
    }
    else {
        Param_s += "";
        Param_b += "4_";
    }
    DM3 -> Group_VipuskFDQuery -> ParamByName ("N_GROUP_S") -> Value = Param_s;
    DM3 -> Group_VipuskFDQuery -> ParamByName ("N_GROUP_B") -> Value = Param_b;
    DM3 -> Group_VipuskFDQuery -> Open ();

    CheckListBox1 -> Clear ();

    for (int i = 0; i < DM3 -> Group_VipuskFDQuery -> RecordCount; i++) {
        CheckListBox1 -> Items -> Add ( (DM3 -> Group_VipuskFDQueryN_GROUP -> Value)
            .SubString (1, 3));
        DM3 -> Group_VipuskFDQuery -> Next ();
    }

}

void __fastcall TADD_VedGEK::Edit5KeyPress (TObject *Sender, char &Key) {
    DataModule1 -> Edit_Key (Key);
    // ��� �������, ����� � TEdit ����� ���� ������� ������ �����?
}
void __fastcall TADD_VedGEK::DateTimePicker2Change (TObject *Sender)
{
DateTimePicker2 -> Time = StrToTime ("00:00");
}


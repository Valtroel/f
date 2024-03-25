#include <vcl.h>
#pragma hdrstop


#include "DataModule.h"
#include "DM2Unit.h"
#include "Func.h"
#include "SessionUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TSession_Form * Session_Form;


AnsiString *  predmet;

bool          del_mas_neud   = false,                                           // ���� ��� �������� ������� ses_neud (true - ������ ������)
              Grid_Clear     = true,                                            // ���� ������������� ������� StringGrid
              neud           = false;                                           // ���� �� ������������� ������

int           count_obj,
              count_peop_old = 0,
              count_peop;

int        *  nom_stud;

int        ** ses_neud;
int        ** ses;

TBookmark     Bookmark_ses;

Variant       ExApp;



__fastcall TSession_Form::TSession_Form (TComponent * Owner)
    : TForm (Owner)
{ }



// BitBtn1Click
// BitBtn2Click
// BitBtn3Click
// check_ball
// FormClose
// FormCreate
// MaskEdit1Change
// MaskEdit1Exit
// MaskEdit1MouseDown
// MaskEdit2KeyPress
// MaskEdit2MouseDown
// MaskEdit3Exit
// result_ses
// StringGrid1DrawCell






int __fastcall TSession_Form::check_ball (                                      // �������, ������������ ����
        int        ball,
        int        n_st,
        AnsiString predm
    )
{
    // syst_ball - ���������� ��� ����������� ������� ������
    // ball_int (syst_ball,ball) - �������, ������������ ���� � ������ �������

    Bookmark_ses = DataModule1 -> SessionFDQuery -> GetBookmark ();

    if (    ball == 0
         || ball == 2
         || ball == 11
         || ball == 12
         || ball == 13
       )
        neud = true;


    if (ball == 6) // �� ������
    {
        DataModule1 -> SessionFDQuery -> Prior ();
        while ( (n_st == DataModule1 -> SessionFDQueryNOMER -> Value) &&
            (!DataModule1 -> SessionFDQuery -> Bof)) {
            if (predm == DataModule1 -> SessionFDQueryNAME_OBJECT -> Value) {
                if (DataModule1 -> SessionFDQueryBALL -> Value == 1 ||
                    DataModule1 -> SessionFDQueryBALL -> Value == 3 ||
                    DataModule1 -> SessionFDQueryBALL -> Value == 4 ||
                    DataModule1 -> SessionFDQueryBALL -> Value == 5 ||
                    DataModule1 -> SessionFDQueryBALL -> Value >= 14)
                { // if  ���� ������ ���������� �������� �������������
                    int res = DataModule1 -> SessionFDQueryBALL -> Value;
                    DataModule1 -> SessionFDQuery -> GotoBookmark (Bookmark_ses);
                    DataModule1 -> SessionFDQuery -> FreeBookmark (Bookmark_ses);
                    return ball_int (syst_ball, res);
                } // end if  ���� ������ ���������� �������� �������������
                else
                    DataModule1 -> SessionFDQuery -> Prior ();
            }
            else
                break;
        }
        DataModule1 -> SessionFDQuery -> GotoBookmark (Bookmark_ses);
        DataModule1 -> SessionFDQuery -> FreeBookmark (Bookmark_ses);
        return ball_int (syst_ball, ball);

    }
    else {

        DataModule1 -> SessionFDQuery -> GotoBookmark (Bookmark_ses);
        DataModule1 -> SessionFDQuery -> FreeBookmark (Bookmark_ses);
        return ball_int (syst_ball, ball);
    }

}


bool __fastcall TSession_Form::result_ses (int i, int j) {
    // AnsiString name_obj=DataModule1 -> SessionQueryNAME_OBJECT -> Value;
    AnsiString predm = DataModule1 -> SessionFDQueryNAME_OBJECT -> Value;
    int n_st = DataModule1 -> SessionFDQueryNOMER -> Value;
    int ball;
    Variant ball_variant = DataModule1 -> SessionFDQueryBALL -> AsVariant;
    if (ball_variant != -1) { // if �������� �������� ����
        ball = ball_variant;
    } // end if �������� �������� ����
    else
        ball = 10;
    // �������� ������� ��� ������ ������ (��� ��� ���� ������ ���������)

    if (!DataModule1 -> SessionFDQuery -> Eof) {
        DataModule1 -> SessionFDQuery -> Next ();
        if (n_st == DataModule1 -> SessionFDQueryNOMER -> Value) {
            if (predm != DataModule1 -> SessionFDQueryNAME_OBJECT -> Value) { //
                if ( (predmet[j] == predm) && (nom_stud[i] == n_st)) {
                    ses[i][j] = check_ball (ball, n_st, predm);
                }
                else {
                    ses[i][j] = 8;

                    Variant s_p = DataModule1 -> Count_ObjectFDQuery -> Lookup
                        ("NAME_OBJECT", predm, "NAME_OBJECT");
                    if (!s_p.IsNull ())
                        DataModule1 -> SessionFDQuery -> Prior ();
                    // else  DataModule1 -> SessionQuery -> Next ();
                    // *******&&&&&&&
                    // DataModule1 -> SessionQuery -> Prior ();
                }

                if (ball == 0 || ball == 2 || ball == 11 || ball == 12 ||
                    ball == 13)
                    neud = true;
                if (neud) {
                    ses_neud[i][j] = 100;
                    neud = false;
                }

                return true;
            } // if pred
            else {
                if (ball == 0 || ball == 2 || ball == 11 || ball == 12 ||
                    ball == 13)
                    neud = true;
                if (neud) {
                    ses_neud[i][j] = 100;
                    neud = false;
                }
                return false;
            }

        } // if n_st
        else {
            if ( (predmet[j] == predm) && (nom_stud[i] == n_st)) {
                ses[i][j] = check_ball (ball, n_st, predm);
            }
            else {
                ses[i][j] = 8;
                Variant s_p = DataModule1 -> Count_ObjectFDQuery -> Lookup
                    ("NAME_OBJECT", predm, "NAME_OBJECT");
                if (!s_p.IsNull ())
                    DataModule1 -> SessionFDQuery -> Prior ();
                // DataModule1 -> SessionQuery -> Prior ();
            }

            if (ball == 0 || ball == 2 || ball == 11 || ball == 12 ||
                ball == 13)
                neud = true;
            if (neud) {
                ses_neud[i][j] = 100;
                neud = false;
            }

            return true;
        }
    } // if !Eof

    if ( (predmet[j] == predm) && (nom_stud[i] == n_st)) {
        ses[i][j] = check_ball (ball, n_st, predm);
    }
    else {
        ses[i][j] = 8;
    }

    if (ball == 0 || ball == 2 || ball == 11 || ball == 12 || ball == 13)
        neud = true;
    if (neud) {
        ses_neud[i][j] = 100;
        neud = false;
    }
    return true;
}

void __fastcall TSession_Form::BitBtn1Click (TObject *Sender) {
    // �������� �� ������ ��������
    // Variant locvalues[]={MaskEdit1 -> EditText,ComboBox1 -> ItemIndex};
    // Variant search_inc_group=DM2 -> Increment_GroupTable -> Lookup ("N_GROUP;VID_EDU",VarArrayOf (locvalues,1),"INC_GROUP");

    if (MaskEdit3 -> Text == "    ") {
        ShowMessage ("�������� ������� ���!");
        return;
    }
    Variant search_inc_group = search_increment_group (MaskEdit1 -> EditText,
        ComboBox1 -> ItemIndex);
    if (!search_inc_group.IsNull ()) {
        DataModule1 -> SessionFDQuery -> Close ();
        DataModule1 -> SessionFDQuery -> ParamByName ("INC_GROUP") -> AsInteger =
            search_inc_group.AsType (varInteger);
        // ����������� ����� �������� � �����, ������� �������
        if (Trim (MaskEdit2 -> EditText).IsEmpty ()) {
            MaskEdit2 -> SetFocus ();
            return;
        }
        int sem = Trim (MaskEdit2 -> EditText).ToInt ();

        AnsiString sp_string = "";
        // ���������� ��� ������������ ������ �� ���������������

        DataModule1 -> Specializ_GroupFDQuery -> Close ();
        DataModule1 -> Specializ_GroupFDQuery -> ParamByName ("G") -> AsInteger =
            search_inc_group;
        DataModule1 -> Specializ_GroupFDQuery -> ParamByName ("FAC") -> AsInteger =
            nom_fac;
        DataModule1 -> Specializ_GroupFDQuery -> Open ();

        if (!DataModule1 -> Specializ_GroupFDQuery -> RecordCount) {
            ShowMessage ("������ �� ������������� ������ ����������!");
            return;
        }
        ///---������������ ������ �� ���������������
        for (int i = 0; i < DataModule1 -> Specializ_GroupFDQuery -> RecordCount;
        i++) { // for
            sp_string +=
                AnsiString (DataModule1 -> Specializ_GroupFDQueryN_SPECIALIZ
                -> Value);
            sp_string += ",";
            DataModule1 -> Specializ_GroupFDQuery -> Next ();
        } // end for

        sp_string = sp_string.SubString (1, sp_string.Length () - 1);
        // ------
        DataModule1 -> Count_ObjectFDQuery -> Close ();
        DataModule1 -> Count_ObjectFDQuery -> SQL -> Clear ();
        DataModule1 -> Count_ObjectFDQuery -> SQL -> Add ("SELECT Object_plan.NAME_OBJECT, Object_plan.N_OBJECT, Edu_plan.ZACH_EXAM \
FROM EDU_PLAN Edu_plan \
   INNER JOIN OBJECT_PLAN Object_plan  \
   ON  (Edu_plan.N_OBJECT = Object_plan.N_OBJECT) \
WHERE (SEMESTR=:SEMESTR) AND (VID_EDU_PLAN=:VID_EDU) AND (N_FAC=:FAC) \
AND (Edu_Plan.YEAR_PLAN=:PLAN)  AND (ZACH_EXAM <>4) \
AND  (Edu_plan.N_PLAN  NOT IN (select SPEC_PLAN.N_PLAN from SPEC_PLAN) \
   or Edu_plan.N_PLAN IN (select SPEC_PLAN.N_PLAN from SPEC_PLAN \
   where spec_plan.n_specializ IN (" + sp_string + "))) \
ORDER BY Object_plan.NAME_OBJECT");
        DataModule1 -> Count_ObjectFDQuery -> ParamByName ("SEMESTR")
            -> AsInteger = sem;
        DataModule1 -> Count_ObjectFDQuery -> ParamByName ("VID_EDU") -> AsInteger =
            ComboBox1 -> ItemIndex;
        DataModule1 -> Count_ObjectFDQuery -> ParamByName ("FAC") -> AsInteger =
            nom_fac;
        DataModule1 -> Count_ObjectFDQuery -> ParamByName ("PLAN") -> Value =
            StrToInt (MaskEdit3 -> Text); // uch_god;
        DataModule1 -> Count_ObjectFDQuery -> Open ();
        count_obj = DataModule1 -> Count_ObjectFDQuery -> RecordCount;
        if (count_obj == 0) {
            ShowMessage ("���������� ������ ��� ������� �������� �� �������");
            return;
        }
        DataModule1 -> SessionFDQuery -> ParamByName ("SEMESTR_VED")
            -> AsInteger = sem;
        DataModule1 -> SessionFDQuery -> ParamByName ("PLAN") -> Value =
            StrToInt (MaskEdit3 -> Text); // uch_god;
        DataModule1 -> SessionFDQuery -> Open ();
        if (!DataModule1 -> SessionFDQuery -> RecordCount) {
            ShowMessage ("���������� ������ ��� ������� �������� �� �������");
            MaskEdit2 -> SetFocus ();
            return;
        }
        // ----����������� ������� ������ ������ (����������� ��� �������������)
        // !!!if (Application -> MessageBox ("���������� ����� �������� � ������������� �������?", "����� ������� ������", MB_YESNO) == mrYes)
        if (MessageDlg ("���������� ����� �������� � ������������� �������?",
            mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
        { // if � ������������� �������
            syst_ball = 10;
        } // end if � ������������� �������
        else { // else  � ����������� �������
            syst_ball = 5;
        } // end else  � ����������� �������

        DataModule1 -> People_CaseFDQuery -> Close ();
        DataModule1 -> People_CaseFDQuery -> ParamByName ("ST") -> AsString = "1";
        DataModule1 -> People_CaseFDQuery -> ParamByName ("FAC") -> AsSmallInt =
            nom_fac;
        DataModule1 -> People_CaseFDQuery -> ParamByName ("EDU") -> AsSmallInt =
            ComboBox1 -> ItemIndex;
        DataModule1 -> People_CaseFDQuery -> ParamByName ("GR") -> AsSmallInt =
            search_inc_group;
        DataModule1 -> People_CaseFDQuery -> Open ();
        /* DataModule1 -> People_PartQuery -> Close ();
         DataModule1 -> People_PartQuery -> SQL -> Clear ();
         DataModule1 -> People_PartQuery -> SQL -> Add ("SELECT NOMER, FAM, NAME, OTCH, INC_GROUP, N_GROUP, VID_EDU, KURS, N_FOUND FROM PEOPLE WHERE (N_FAC="+AnsiString (nom_fac)+") AND (STATUS_PEOPLE=1) AND (INC_GROUP=:INC_GROUP) ORDER BY FAM, NAME, OTCH");
         DataModule1 -> People_PartQuery -> ParamByName ("INC_GROUP") -> AsInteger=search_inc_group;//DM2 -> Increment_GroupTable -> Lookup ("N_GROUP;VID_EDU",VarArrayOf (locvalues,1),"INC_GROUP");
         DataModule1 -> People_PartQuery -> Open ();

         int count_peop=DataModule1 -> People_PartQuery -> RecordCount; */
        count_peop = DataModule1 -> People_CaseFDQuery -> RecordCount;
        if (!count_peop_old)
            count_peop_old = count_peop;

        nom_stud = new int[count_peop];

        for (int h = 0; h < count_peop; h++) {
            /* nom_stud[h]=DataModule1 -> People_PartQueryNOMER -> Value;
             DataModule1 -> People_PartQuery -> Next (); */

            nom_stud[h] = DataModule1 -> People_CaseFDQueryNOMER -> Value;
            DataModule1 -> People_CaseFDQuery -> Next ();

        }

        // DataModule1 -> People_PartQuery -> First ();
        DataModule1 -> People_CaseFDQuery -> First ();

        predmet = new AnsiString[count_obj];
        for (int k = 0; k < count_obj; k++)
        { // ��������� �������� ��������� �� ������ ������� � ������
            predmet[k] = DataModule1 -> Count_ObjectFDQueryNAME_OBJECT -> Value;
            DataModule1 -> Count_ObjectFDQuery -> Next ();
        }

        ses = new int* [count_peop];
        for (int i = 0; i < count_peop; i++)
            ses[i] = new int[count_obj];

        // ------ ses_neud
        if (del_mas_neud)
            // ���������� ��� �������� ������� ses_neud (true-������ ������)
        {

            for (int i = 0; i < count_peop_old; i++)
                delete[]ses_neud[i]; // STEP 1: DELETE THE COLUMNS
            delete[]ses_neud; // STEP 2: DELETE THE ROWS

            del_mas_neud = false;
            count_peop_old = count_peop;

        }

        ses_neud = new int* [count_peop];
        for (int i = 0; i < count_peop; i++)
            ses_neud[i] = new int[count_obj];

        del_mas_neud = true;
        // �������� �������  ses_neud
        for (int i = 0; i < count_peop; i++) { // ��� for i
             for (int j = 0; j < count_obj; j++) { // ��� fot j
                ses_neud[i][j] = 0;
            } // for j
        } // for i

        // -------- ses
        for (int i = 0; i < count_peop; i++) { // ��� for i
            for (int j = 0; j < count_obj; j++) { // ��� fot j
                while (!result_ses (i, j)); // result_ses (i,j);
            } // for j
        } // for i
        // ---------
        // ��������  StringGrid
        // StringGrid1 -> ColCount=0;
        // StringGrid1 -> RowCount=0;
        // StringGrid1 -> FixedRows=1;

        Grid_Clear = true;

        int st = 0; // ������ 0-�������������� ������
        float count0 = 0; // ���-�� ��������� �� �������� 0
        float count1 = 0; // ���-�� ��������� �� �������� 1
        float count2 = 0; // ���-�� ��������� �� �������� 2
        float count3 = 0; // ���-�� ��������� �� �������� 3
        float count4 = 0; // ���-�� ��������� �� �������� 4
        float count5 = 0; // ���-�� ��������� �� �������� 5
        float count6 = 0; // ���-�� ��������� �� �������� 6
        // ****
        StringGrid1 -> ColCount = count_obj + 5;
        StringGrid1 -> RowCount = count_peop + 1;
        StringGrid1 -> Cells[0][0] = "���";
        StringGrid1 -> Cells[1][0] = "������� ����";
        StringGrid1 -> Cells[2][0] = "�������������";
        StringGrid1 -> Cells[3][0] = "���������";
        // *****
        StringGrid2 -> ColCount = 8;
        StringGrid2 -> RowCount = 3;
        StringGrid2 -> Cells[0][0] = "�����";
        StringGrid2 -> Cells[5][0] = "���������";
        StringGrid2 -> Cells[6][0] = "����.";
        StringGrid2 -> Cells[7][0] = "��� ������";
        if (syst_ball == 5) { // if ����������� �������
            StringGrid2 -> Cells[1][0] = "���.";
            StringGrid2 -> Cells[2][0] = "���./���.";
            StringGrid2 -> Cells[3][0] = "���.";
            StringGrid2 -> Cells[4][0] = "��.";
        } // end if ����������� �������
        else { // else ������������� �������
            StringGrid2 -> Cells[1][0] = "9,10";
            StringGrid2 -> Cells[2][0] = "6,7,8,9,10";
            StringGrid2 -> Cells[3][0] = "6,7,8";
            StringGrid2 -> Cells[4][0] = "4,5";
        } // end else ������������� �������
        // *****
        for (int i = 0; i < count_peop; i++) { // ��� for i
            // -----������� ����� ��� ���������� ���������� �� ������������
            st = 0; // ������ 0-�������������� ������
            // 1-������������
            // 2-���������� �� ��������� ������
            // 3-���������� �� ����������������� ��� 4,5
            // 4-���������� �� ������ ��� 6,7,8
            // 5-���������� �� ������� ��� 9,10
            // 6-���������� �� ������ � ������� 6,7,8,9,10
            // -----
            for (int j = 0; j < count_obj; j++) { // ��� fot j
                // result_ses (i,j);
                if (ses[i][j] > 10) { // if ������������� ������
                    StringGrid1 -> Cells[j + 4][i + 1] = (ses[i][j] - 10);

                    if (st != 1) { // if ������� �� ��������� � ������������
                        switch (ses[i][j] - 10) { // switch
                        case 1:
                            st = 1; // ������������
                            break;
                        case 2:
                            st = 1; // ������������
                            break;
                        case 3:
                            st = 1; // ������������
                            break;
                        case 4:
                            if (st != 2) { // if ������ �� �������� ����������
                                if (st == 4 || st == 5 || st == 6)
                                    st = 2;
                                else
                                    st = 3;
                            } // end if ������ �� �������� ����������
                            break;
                        case 5:
                            if (st != 2) { // if ������ �� �������� ����������
                                if (st == 4 || st == 5 || st == 6)
                                    st = 2;
                                else
                                    st = 3;
                            } // end if ������ �� �������� ����������
                            break;
                        case 6:
                            if (st != 2) { // if ������ �� �������� ����������
                                if (st == 3 || st == 5 || st == 6) {
                                    if (st == 3)
                                        st = 2;
                                    if (st == 5)
                                        st = 6;
                                }
                                else
                                    st = 4;
                            } // end if ������ �� �������� ����������
                            break;
                        case 7:
                            if (st != 2) { // if ������ �� �������� ����������
                                if (st == 3 || st == 5 || st == 6) {
                                    if (st == 3)
                                        st = 2;
                                    if (st == 5)
                                        st = 6;
                                }
                                else
                                    st = 4;
                            } // end if ������ �� �������� ����������
                            break;
                        case 8:
                            if (st != 2) { // if ������ �� �������� ����������
                                if (st == 3 || st == 5 || st == 6) {
                                    if (st == 3)
                                        st = 2;
                                    if (st == 5)
                                        st = 6;
                                }
                                else
                                    st = 4;
                            } // end if ������ �� �������� ����������
                            break;
                        case 9:
                            if (st != 2) { // if ������ �� �������� ����������
                                if (st == 3 || st == 4 || st == 6) {
                                    if (st == 3)
                                        st = 2;
                                    if (st == 4)
                                        st = 6;
                                }
                                else
                                    st = 5;
                            } // end if ������ �� �������� ����������
                            break;
                        case 10:
                            if (st != 2) { // if ������ �� �������� ����������
                                if (st == 3 || st == 4 || st == 6) {
                                    if (st == 3)
                                        st = 2;
                                    if (st == 4)
                                        st = 6;
                                }
                                else
                                    st = 5;
                            } // end if ������ �� �������� ����������
                            break;
                        } // end switch
                    } // end if ������� �� ��������� � ������������

                } // end if ������������� ������
                else { // else ����������� + ������ + ������� + ����� + ���������� + ��������� ����
                    switch (ses[i][j]) { // switch
                    case 0:
                        StringGrid1 -> Cells[j + 4][i + 1] = "�������";
                        st = 1;
                        break;
                    case 1:
                        StringGrid1 -> Cells[j + 4][i + 1] = "�����";
                        break;
                    case 6:
                        StringGrid1 -> Cells[j + 4][i + 1] = "�� ������";
                        st = 1;
                        break;
                    case 7:
                        StringGrid1 -> Cells[j + 4][i + 1] = "����������";
                        break;
                    case 8:
                        StringGrid1 -> Cells[j + 4][i + 1] = " ";
                        break;
                    case 9:
                        StringGrid1 -> Cells[j + 4][i + 1] = "���������";
                        break;
                    case 10:
                        StringGrid1 -> Cells[j + 4][i + 1] = "������ ���������";
                        st = 1;
                        break;
                    default:
                        StringGrid1 -> Cells[j + 4][i + 1] = ses[i][j];
                        if (st != 1) { // if st!=1
                            switch (ses[i][j]) { // switch
                            case 2:
                                st = 1; // ������������
                                break;
                            case 3:
                                if (st != 2)
                                { // if ������ �� �������� ����������
                                    if (st == 4 || st == 5 || st == 6)
                                        st = 2;
                                    else
                                        st = 3;
                                } // end if ������ �� �������� ����������
                                break;
                            case 4:
                                if (st != 2)
                                { // if ������ �� �������� ����������
                                    if (st == 3 || st == 5 || st == 6) {
                                        if (st == 3)
                                        st = 2;
                                        if (st == 5)
                                        st = 6;
                                    }
                                    else
                                        st = 4;
                                } // end if ������ �� �������� ����������
                                break;
                            case 5:
                                if (st != 2)
                                { // if ������ �� �������� ����������
                                    if (st == 3 || st == 4 || st == 6) {
                                        if (st == 3)
                                        st = 2;
                                        if (st == 4)
                                        st = 6;
                                    }
                                    else
                                        st = 5;
                                } // end if ������ �� �������� ����������
                                break;
                            } // end switch
                        } // end if st!=1
                    } // end switch
                } // end else ����������� + ������ + ������� + ����� + ����������

            } // for j
            switch (st) {
                // ������ 0-�������������� ������
                // 1-������������
                // 2-���������� �� ��������� ������
                // 3-���������� �� ����������������� ��� 4,5
                // 4-���������� �� ������ ��� 6,7,8
                // 5-���������� �� ������� ��� 9,10
                // 6-���������� �� ������ � ������� 6,7,8,9,10
            case 0:
                StringGrid1 -> Cells[count_obj + 4][i + 1] = "";
                count0++;
                break;
            case 1:
                StringGrid1 -> Cells[count_obj + 4][i + 1] = "������������";
                count1++;
                break;
            case 2:
                StringGrid1 -> Cells[count_obj + 4][i + 1] = "���������";
                count2++;
                break;
            case 3:
                StringGrid1 -> Cells[count_obj + 4][i + 1] = "�����.: 4,5";
                count3++;
                break;
            case 4:
                StringGrid1 -> Cells[count_obj + 4][i + 1] = "���.: 6,7,8";
                count4++;
                break;
            case 5:
                StringGrid1 -> Cells[count_obj + 4][i + 1] = "���.: 9,10";
                count5++;
                break;
            case 6:
                StringGrid1 -> Cells[count_obj + 4][i + 1] =
                    "���. � ���.: 6,7,8,9,10";
                count6++;
                break;
            }
        } // for i

        for (int i = 0; i < count_obj; i++) {
            StringGrid1 -> Cells[i + 4][0] = predmet[i];
        } // for
        // AnsiString fam,name,otch;
        int all_col = 0;
        float all_sum = 0;
        for (int i = 0; i < count_peop; i++) {
            // fam=DataModule1 -> People_PartQueryFAM -> Value;
            // name=DataModule1 -> People_PartQueryNAME -> Value;
            // otch=DataModule1 -> People_PartQueryOTCH -> Value;
            // StringGrid1 -> Cells[0][i+1]=fam+" "+name.SubString (1,1)+"."+otch.SubString (1,1)+".";
            // StringGrid1 -> Cells[0][i+1]=DataModule1 -> People_PartQueryFAM -> Value+" "+DataModule1 -> People_PartQueryNAME -> Value+" "+DataModule1 -> People_PartQueryOTCH -> Value;

            StringGrid1 -> Cells[0][i + 1] =
                DataModule1 -> People_CaseFDQueryFIO -> Value;
            StringGrid1 -> Cells[2][i + 1] =
                DataModule1 -> People_CaseFDQueryN_SPECIALIZ1 -> Value;
            // ---�� ��������� ��������
            if (DataModule1 -> People_CaseFDQueryN_FOUND -> Value == 2)
            { // if 2 - ��� �������
                StringGrid1 -> Cells[3][i + 1] = "�������";
            }
            else
                StringGrid1 -> Cells[3][i + 1] = "";
            // ---
            // DataModule1 -> People_PartQuery -> Next ();
            DataModule1 -> People_CaseFDQuery -> Next ();

            int kol = 0, sum_ball = 0;
            bool stat = false;
            for (int j = 0; j < count_obj; j++)
            { // 11,12,13 - ��� 1,2 � 3 � ������������� �������; 2 � 0 - ��� 2 ����� � �������, 6 - �����; 10 - ������ ���������
                if ( (ses[i][j] == 0) || (ses[i][j] == 2) ||
                    (ses[i][j] == 6) || (ses[i][j] == 10) || (ses[i][j] == 11)
                    || (ses[i][j] == 12) || (ses[i][j] == 13))
                    stat = true; // || (ses[i][j]==8)) stat=true;
                else if (ses[i][j] == 1);
                else { // else  ���� �����������
                    if (ses[i][j] > 10) { // if ��� ������������� �������
                        sum_ball += (ses[i][j] - 10);
                        kol++;
                    } // end if ��� ������������� �������
                    else { // else ������� ������� �� ������ 10, ����� ���� ����������� ������ ��������
                        if (ses[i][j] != 8 && ses[i][j] != 9 && ses[i][j]
                            != 10 && ses[i][j] != 7)
                            // 7-���������� 10-������ ��������� 8-��������� �� �������� �� ���������� (�� ��������� ����.����) 9 - ��������� ����.����
                        { // if ��� ����������� �������
                            sum_ball += ses[i][j];
                            kol++;
                        } // end if ��� ����������� �������
                    } // end else ������� ������� �� ������ 10, ����� ���� ����������� ������ ��������
                } // end else  ���� �����������
            } // for j
            if (stat)
                StringGrid1 -> Cells[1][i + 1] = "������ �� �����";
            else {
                if (kol) {
                    float rez = (float)sum_ball / kol;
                    all_sum += rez;
                    all_col++;
                    StringGrid1 -> Cells[1][i + 1] =
                        FloatToStrF (rez, ffFixed, 7, 2);
                }
            }
        } // for i

        ///-----������ ���������

        if (count_peop == (count0 + count1 + count2 + count3 + count4 + count5 +
            count6)) { // if
            /* AnsiString raschet="����� "+AnsiString (count_peop)+
             + ";\n "+"�� ���: "+count5+" ���. - "+ FloatToStrF (count5*100/count_peop,ffFixed,7,3)+
             +"%;\n "+"�� ��� � ���: "+AnsiString (count6)+" ���. - "+ FloatToStrF (count6*100/count_peop,ffFixed,7,3)+
             +"%;\n  "+"�� ���: "+AnsiString (count4)+" ���. - "+ FloatToStrF (count4*100/count_peop,ffFixed,7,3)+
             +"%;\n  "+"�� ��: "+AnsiString (count3)+" ���. - "+ FloatToStrF (count3*100/count_peop,ffFixed,7,3)+
             +"%;\n  "+"�� ������: "+AnsiString (count2)+" ���. - "+ FloatToStrF (count2*100/count_peop,ffFixed,7,3)+
             +"%;\n  "+"������������: "+AnsiString (count1)+" ���. - "+ FloatToStrF (count1*100/count_peop,ffFixed,7,3)+
             +"%;\n  "+"��� ������:"+count0+" ���. - "+ FloatToStrF (count0*100/count_peop,ffFixed,7,3)+"%; ";
             */

            StringGrid2 -> Cells[0][1] = AnsiString (count_peop); // �����
            StringGrid2 -> Cells[0][2] =
                FloatToStrF (count_peop * 100 / count_peop, ffFixed, 7, 3);

            StringGrid2 -> Cells[1][1] = AnsiString (count5); // ���. 9,10
            StringGrid2 -> Cells[1][2] = FloatToStrF (count5 * 100 / count_peop,
                ffFixed, 7, 3);

            StringGrid2 -> Cells[2][1] = AnsiString (count6);
            // ���./���. 6,7,8,9,10
            StringGrid2 -> Cells[2][2] = FloatToStrF (count6 * 100 / count_peop,
                ffFixed, 7, 3);

            StringGrid2 -> Cells[3][1] = AnsiString (count4); // ���. 6,7,8
            StringGrid2 -> Cells[3][2] = FloatToStrF (count4 * 100 / count_peop,
                ffFixed, 7, 3);

            StringGrid2 -> Cells[4][1] = AnsiString (count3); // ��. 4,5
            StringGrid2 -> Cells[4][2] = FloatToStrF (count3 * 100 / count_peop,
                ffFixed, 7, 3);

            StringGrid2 -> Cells[5][1] = AnsiString (count2); // ���������
            StringGrid2 -> Cells[5][2] = FloatToStrF (count2 * 100 / count_peop,
                ffFixed, 7, 3);

            StringGrid2 -> Cells[6][1] = AnsiString (count1); // ����.
            StringGrid2 -> Cells[6][2] = FloatToStrF (count1 * 100 / count_peop,
                ffFixed, 7, 3);

            StringGrid2 -> Cells[7][1] = AnsiString (count0); // ��� ������
            StringGrid2 -> Cells[7][2] = FloatToStrF (count0 * 100 / count_peop,
                ffFixed, 7, 3);

            // Memo1 -> Text=raschet;
        } // end if
        else

            StringGrid1 -> FixedRows = 1;
        Height = 485;
        StringGrid1 -> Visible = true;
        Panel2 -> Visible = true;
        Label3 -> Visible = true;
        Panel3 -> Visible = true;
        Label4 -> Visible = true;
        if (all_col)
            Label4 -> Caption = FloatToStrF (all_sum / all_col, ffFixed, 7, 2);
        else
            Label4 -> Caption = "  ";

        for (int i = 0; i < count_peop; i++)
            delete[]ses[i]; // STEP 1: DELETE THE COLUMNS
        delete[]ses; // STEP 2: DELETE THE ROWS

        delete[]predmet;
        delete[]nom_stud;
        DataModule1 -> People_CaseFDQuery -> Close ();
    } // ���� ������ ��������� ������
    else {
        ShowMessage ("������ ������ ������ �� ����������!");
        MaskEdit1 -> SetFocus ();
    }
}


void __fastcall TSession_Form::BitBtn2Click (TObject *Sender) {
    Close ();
}


void __fastcall TSession_Form::MaskEdit1Change (TObject *Sender) {
    if (Grid_Clear) {
        Label3 -> Visible = false;
        Label4 -> Visible = false;
        StringGrid1 -> Visible = false;

        // ----�������� ����������� �������  StringGrid
        for (int i = 0; i < StringGrid1 -> ColCount + 1; i++)
        { // for  StringGrid1 -> RowCount
            for (int j = 0; j < StringGrid1 -> RowCount; j++)
            { // for  StringGrid1 -> RowCount
                StringGrid1 -> Cells[i][j] = "";
            } // end for  StringGrid1 -> RowCount
        } // end for  StringGrid1 -> ColCount

        // ----�������� ����������� �������  StringGrid
        for (int i = 0; i < StringGrid2 -> ColCount + 1; i++)
        { // for  StringGrid2 -> RowCount
            for (int j = 1; j < StringGrid2 -> RowCount; j++)
            { // for  StringGrid2 -> RowCount
                StringGrid2 -> Cells[i][j] = "";
            } // end for  StringGrid2 -> RowCount
        } // end for  StringGrid2 -> ColCount

        Panel2 -> Visible = false;
        Panel3 -> Visible = false;
        Height = 100;
        Grid_Clear = false;
    }
}


void __fastcall TSession_Form::MaskEdit1Exit (TObject *Sender) {
    if (MaskEdit1 -> EditText == "   ")
        return;

    if (nom_fac != DM2 -> FacultyFDTable -> Lookup ("KOD_FAC",
        MaskEdit1 -> EditText.SubString (1, 1).ToInt (), "N_FAC")) {
        ShowMessage ("����� ������ �� ������������� ������ ����������");
        MaskEdit1 -> SetFocus ();
    }
}


void __fastcall TSession_Form::FormClose (TObject *Sender, TCloseAction &Action)
{
    /* if (Bookmark_ses)
     { //if ��������
     DataModule1 -> SessionQuery -> GotoBookmark (Bookmark_ses);
     DataModule1 -> SessionQuery -> FreeBookmark (Bookmark_ses);
     }//end if �������� */

    if (del_mas_neud)
        // ���������� ��� �������� ������� ses_neud (true-������ ������)
    {

        for (int i = 0; i < count_peop_old; i++)
            delete[]ses_neud[i]; // STEP 1: DELETE THE COLUMNS
        delete[]ses_neud; // STEP 2: DELETE THE ROWS
        del_mas_neud = false;
        count_peop_old = 0;
    }

    Action = caFree;
}


void __fastcall TSession_Form::BitBtn3Click (TObject *Sender) {
    ExApp = Variant::CreateObject ("Excel.Application");
    Variant WBook = NewBook (ExApp);

    Variant WSheet = SelectSheet (WBook, "����1");
    AnsiString v_ed;
    if (ComboBox1 -> ItemIndex) {
        v_ed = "�";
    }
    else {
        v_ed = "��";
    }
    CellValue ("������ " + MaskEdit1 -> Text + v_ed, 1, 1);
    Variant Rang1 = Range2 (WSheet, "A1:D1");
    HorizontalAlign (Rang1, 3);
    CellFont ("Arial", 12, true, false, 2, 0, Rang1);
    M1 (Rang1);
    CellValue (MaskEdit2 -> Text + " �������", 1, 2);
    Rang1 = Range2 (WSheet, "A2:D2");
    HorizontalAlign (Rang1, 3);
    CellFont ("Arial", 12, true, false, 2, 0, Rang1);
    M1 (Rang1);
    // ��� �������������� ����� �� ��������� � �������� �� ������
    Rang1 = Range2 (WSheet, "A3:Z3");
    W1 (Rang1); // ������� �� ������
    HorizontalAlign (Rang1, 3); // ������������ �� ����������� �� ������
    VerticalAlign (Rang1, 2); // ������������ �� ��������� �� ������

    // ----��������� ����������� �������  StringGrid
    for (int i = 0; i < StringGrid1 -> ColCount + 1; i++)
    { // for  StringGrid1 -> ColCount
        CellOrient (i + 1, 3, 90);
        // ������� ����������� ������� ������ �� 90 ��������

        for (int j = 0; j < StringGrid1 -> RowCount; j++)
        { // for  StringGrid1 -> RowCount
            if (j != StringGrid1 -> RowCount - 1)
                CellValue (j + 1, 1, j + 4);

            CellValue (StringGrid1 -> Cells[i][j], i + 2, j + 3);
            if ( (StringGrid1 -> Cells[i][j] == "1") ||
                (StringGrid1 -> Cells[i][j] == "2") ||
                (StringGrid1 -> Cells[i][j] == "3") ||
                (StringGrid1 -> Cells[i][j] == "�� ������") ||
                (StringGrid1 -> Cells[i][j] == "�������"))
            { // ��������� ������� ������ ���������� 1,2,3 ��� �� ����
                Rang1 = Range2 (WSheet, mas_column[i + 1] + AnsiString (j + 3));
                CellFont ("Arial", 10, true, false, 1, 3, Rang1);
            }
            BorderCell (i + 1, j + 3, 1, 2);
        } // end for  StringGrid1 -> RowCount
    } // end for  StringGrid1 -> ColCount

    for (int i = 0; i < count_peop; i++) { // ��� for i
        for (int j = 0; j < count_obj; j++)
        { // ��� fot j             //ball==0 || ball==2 || ball==11 || ball==12 || ball==13
            if (ses_neud[i][j] == 100) { // ACol== (j+4)) && ARow== (i+1))
                Rang1 = Range2 (WSheet, "B" + AnsiString (i + 4) + ":C" +
                    AnsiString (i + 4));
                CellFont ("Arial", 10, true, false, 1, 5, Rang1);

                Rang1 = Range2 (WSheet, mas_column[j + 5] + AnsiString (i + 4));
                CellFont ("Arial", 10, true, false, 1, 5, Rang1);
            }
        } // end for j
    } // end for i

    Variant Ce1;
    // ----��������� ����������� �������  StringGrid
    for (int i = 0; i < StringGrid2 -> ColCount; i++)
    { // for  StringGrid2 -> RowCount
        for (int j = 0; j < StringGrid2 -> RowCount; j++)
        { // for  StringGrid2 -> RowCount
            if (j == StringGrid2 -> RowCount - 1)
            { // if ���� ������� �������� ������
                /* int ii=i+2;
                 int jj=StringGrid1 -> RowCount+5+j;
                 Ce1=SelectCell (jj,ii);
                 SheetFormat (Ce1,"0,000");     //    0.000 � ����� Excel ����� ����� ������
                 CellValue (StrToFloat (StringGrid2 -> Cells[i][j]),ii,jj); */
            } // end if ���� ������� �������� ������

            else
                CellValue (StringGrid2 -> Cells[i][j], i + 2,
                StringGrid1 -> RowCount + 5 + j);

            BorderCell (i + 2, StringGrid1 -> RowCount + 5 + j, 1, 2);
        } // end for  StringGrid2 -> RowCount
    } // end for  StringGrid2 -> ColCount

    for (int i = 0; i < StringGrid1 -> ColCount + 1; i++) { // for  AutoFitColumn
        AutoFitColumn (WSheet, i + 1);
    } // end for  AutoFitColumn

    AnsiString name_f = "���������� ������ " + MaskEdit1 -> Text + v_ed +
        " ������ �� " + MaskEdit2 -> Text + " ������� ��" + cur_d () + ".xls";
    Variant WorkSaveAs = SaveBookAs (WBook, "d:\\��� ���������\\" + name_f);
    OVisible (ExApp);
}


void __fastcall TSession_Form::FormCreate (TObject *Sender) {
    MaskEdit3 -> Text = AnsiString (uch_god); // ������� ������� ���
    Label7 -> Caption = "/" + AnsiString (uch_god + 1); // ������� ������� ��� +1
}


void __fastcall TSession_Form::MaskEdit3Exit (TObject *Sender) {
    Label7 -> Caption = "/" + AnsiString (StrToInt (MaskEdit3 -> Text) + 1);
    // ������� ������� ��� +1
}


void __fastcall TSession_Form::StringGrid1DrawCell (TObject *Sender, int ACol,
    int ARow, TRect &Rect, TGridDrawState State) {

    for (int i = 0; i < count_peop; i++) { // ��� for i
        for (int j = 0; j < count_obj; j++)
        { // ��� fot j             //ball==0 || ball==2 || ball==11 || ball==12 || ball==13
            if (ses_neud[i][j] == 100) {
                if ( (ACol == 0 || ACol == (j + 4)) && ARow == (i + 1)) {
                    StringGrid1 -> Canvas -> Font -> Color = clRed;
                    StringGrid1 -> Canvas -> FillRect (Rect);
                    StringGrid1 -> Canvas -> TextOut (Rect.Left + 2, Rect.Top + 2,
                        StringGrid1 -> Cells[ACol][ARow].c_str ());
                }
            }
        } // end for j
    } // end for i

    /* for (int i=0;i<count_peop;i++)
     delete[] ses_neud[i]; // STEP 1: DELETE THE COLUMNS
     delete[] ses_neud;   // STEP 2: DELETE THE ROWS */

}


void __fastcall TSession_Form::MaskEdit2KeyPress (TObject *Sender, char &Key) {
    DataModule1 -> Edit_Key (Key);
    // ��� �������, ����� � TEdit ����� ���� ������� ������ �����?
}


void __fastcall TSession_Form::MaskEdit1MouseDown (TObject *Sender,
    TMouseButton Button, TShiftState Shift, int X, int Y) {
    MaskEdit1 -> SelStart = 0;
}


void __fastcall TSession_Form::MaskEdit2MouseDown (TObject *Sender,
    TMouseButton Button, TShiftState Shift, int X, int Y) {
    MaskEdit2 -> SelStart = 0;
}


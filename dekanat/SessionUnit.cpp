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

bool          del_mas_neud   = false,                                           // флаг для удаления массива ses_neud (true - массив создан)
              Grid_Clear     = true,                                            // флаг необходимости очистки StringGrid
              neud           = false;                                           // была ли отрицательная оценка

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






int __fastcall TSession_Form::check_ball (                                      // функция, возвращающая балл
        int        ball,
        int        n_st,
        AnsiString predm
    )
{
    // syst_ball - переменная для определения системы оценки
    // ball_int (syst_ball,ball) - функция, возвращающая балл в нужной системе

    Bookmark_ses = DataModule1 -> SessionFDQuery -> GetBookmark ();

    if (    ball == 0
         || ball == 2
         || ball == 11
         || ball == 12
         || ball == 13
       )
        neud = true;


    if (ball == 6) // не явился
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
                { // if  если оценка предыдущая является положительной
                    int res = DataModule1 -> SessionFDQueryBALL -> Value;
                    DataModule1 -> SessionFDQuery -> GotoBookmark (Bookmark_ses);
                    DataModule1 -> SessionFDQuery -> FreeBookmark (Bookmark_ses);
                    return ball_int (syst_ball, res);
                } // end if  если оценка предыдущая является положительной
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
    if (ball_variant != -1) { // if непустое значение поля
        ball = ball_variant;
    } // end if непустое значение поля
    else
        ball = 10;
    // значение забитое для пустой ячейки (для тех кому выдана ведомость)

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
    // Действия по кнопке показать
    // Variant locvalues[]={MaskEdit1 -> EditText,ComboBox1 -> ItemIndex};
    // Variant search_inc_group=DM2 -> Increment_GroupTable -> Lookup ("N_GROUP;VID_EDU",VarArrayOf (locvalues,1),"INC_GROUP");

    if (MaskEdit3 -> Text == "    ") {
        ShowMessage ("Выберите учебный год!");
        return;
    }
    Variant search_inc_group = search_increment_group (MaskEdit1 -> EditText,
        ComboBox1 -> ItemIndex);
    if (!search_inc_group.IsNull ()) {
        DataModule1 -> SessionFDQuery -> Close ();
        DataModule1 -> SessionFDQuery -> ParamByName ("INC_GROUP") -> AsInteger =
            search_inc_group.AsType (varInteger);
        // преобразуем текст семестра в число, удаляем пробелы
        if (Trim (MaskEdit2 -> EditText).IsEmpty ()) {
            MaskEdit2 -> SetFocus ();
            return;
        }
        int sem = Trim (MaskEdit2 -> EditText).ToInt ();

        AnsiString sp_string = "";
        // переменная для формирования строки со специализациями

        DataModule1 -> Specializ_GroupFDQuery -> Close ();
        DataModule1 -> Specializ_GroupFDQuery -> ParamByName ("G") -> AsInteger =
            search_inc_group;
        DataModule1 -> Specializ_GroupFDQuery -> ParamByName ("FAC") -> AsInteger =
            nom_fac;
        DataModule1 -> Specializ_GroupFDQuery -> Open ();

        if (!DataModule1 -> Specializ_GroupFDQuery -> RecordCount) {
            ShowMessage ("Группа не соответствует Вашему факультету!");
            return;
        }
        ///---Формирование строки со специализациями
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
            ShowMessage ("Результаты сессии для данного семестра не найдены");
            return;
        }
        DataModule1 -> SessionFDQuery -> ParamByName ("SEMESTR_VED")
            -> AsInteger = sem;
        DataModule1 -> SessionFDQuery -> ParamByName ("PLAN") -> Value =
            StrToInt (MaskEdit3 -> Text); // uch_god;
        DataModule1 -> SessionFDQuery -> Open ();
        if (!DataModule1 -> SessionFDQuery -> RecordCount) {
            ShowMessage ("Результаты сессии для данного семестра не найдены");
            MaskEdit2 -> SetFocus ();
            return;
        }
        // ----определение системы выдачи оценки (пятибальная или десятибальная)
        // !!!if (Application -> MessageBox ("Результаты будут показаны в десятибальной системе?", "Выбор системы оценок", MB_YESNO) == mrYes)
        if (MessageDlg ("Результаты будут показаны в десятибальной системе?",
            mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
        { // if в десятибальной системе
            syst_ball = 10;
        } // end if в десятибальной системе
        else { // else  в пятибальной системе
            syst_ball = 5;
        } // end else  в пятибальной системе

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
        { // занесение названий предметов за данный семестр в массив
            predmet[k] = DataModule1 -> Count_ObjectFDQueryNAME_OBJECT -> Value;
            DataModule1 -> Count_ObjectFDQuery -> Next ();
        }

        ses = new int* [count_peop];
        for (int i = 0; i < count_peop; i++)
            ses[i] = new int[count_obj];

        // ------ ses_neud
        if (del_mas_neud)
            // переменная для удаления массива ses_neud (true-массив создан)
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
        // очищение массива  ses_neud
        for (int i = 0; i < count_peop; i++) { // для for i
             for (int j = 0; j < count_obj; j++) { // для fot j
                ses_neud[i][j] = 0;
            } // for j
        } // for i

        // -------- ses
        for (int i = 0; i < count_peop; i++) { // для for i
            for (int j = 0; j < count_obj; j++) { // для fot j
                while (!result_ses (i, j)); // result_ses (i,j);
            } // for j
        } // for i
        // ---------
        // очищение  StringGrid
        // StringGrid1 -> ColCount=0;
        // StringGrid1 -> RowCount=0;
        // StringGrid1 -> FixedRows=1;

        Grid_Clear = true;

        int st = 0; // статус 0-первоначальный статус
        float count0 = 0; // кол-во студентов со статусом 0
        float count1 = 0; // кол-во студентов со статусом 1
        float count2 = 0; // кол-во студентов со статусом 2
        float count3 = 0; // кол-во студентов со статусом 3
        float count4 = 0; // кол-во студентов со статусом 4
        float count5 = 0; // кол-во студентов со статусом 5
        float count6 = 0; // кол-во студентов со статусом 6
        // ****
        StringGrid1 -> ColCount = count_obj + 5;
        StringGrid1 -> RowCount = count_peop + 1;
        StringGrid1 -> Cells[0][0] = "ФИО";
        StringGrid1 -> Cells[1][0] = "Средний балл";
        StringGrid1 -> Cells[2][0] = "Специализация";
        StringGrid1 -> Cells[3][0] = "Основание";
        // *****
        StringGrid2 -> ColCount = 8;
        StringGrid2 -> RowCount = 3;
        StringGrid2 -> Cells[0][0] = "Всего";
        StringGrid2 -> Cells[5][0] = "смешанные";
        StringGrid2 -> Cells[6][0] = "неуд.";
        StringGrid2 -> Cells[7][0] = "без оценок";
        if (syst_ball == 5) { // if пятибальная система
            StringGrid2 -> Cells[1][0] = "отл.";
            StringGrid2 -> Cells[2][0] = "отл./хор.";
            StringGrid2 -> Cells[3][0] = "хор.";
            StringGrid2 -> Cells[4][0] = "уд.";
        } // end if пятибальная система
        else { // else десятибальная система
            StringGrid2 -> Cells[1][0] = "9,10";
            StringGrid2 -> Cells[2][0] = "6,7,8,9,10";
            StringGrid2 -> Cells[3][0] = "6,7,8";
            StringGrid2 -> Cells[4][0] = "4,5";
        } // end else десятибальная система
        // *****
        for (int i = 0; i < count_peop; i++) { // для for i
            // -----Пробный кусок для вычисления результата по успеваемости
            st = 0; // статус 0-первоначальный статус
            // 1-неуспевающий
            // 2-успевающий на смешанные оценки
            // 3-успевающий на удовлетворительно или 4,5
            // 4-успевающий на хорошо или 6,7,8
            // 5-успевающий на отлично или 9,10
            // 6-успевающий на хорошо и отлично 6,7,8,9,10
            // -----
            for (int j = 0; j < count_obj; j++) { // для fot j
                // result_ses (i,j);
                if (ses[i][j] > 10) { // if десятибальная систем
                    StringGrid1 -> Cells[j + 4][i + 1] = (ses[i][j] - 10);

                    if (st != 1) { // if студент не относится к неуспевающим
                        switch (ses[i][j] - 10) { // switch
                        case 1:
                            st = 1; // неуспевающий
                            break;
                        case 2:
                            st = 1; // неуспевающий
                            break;
                        case 3:
                            st = 1; // неуспевающий
                            break;
                        case 4:
                            if (st != 2) { // if оценки не являются смешанными
                                if (st == 4 || st == 5 || st == 6)
                                    st = 2;
                                else
                                    st = 3;
                            } // end if оценки не являются смешанными
                            break;
                        case 5:
                            if (st != 2) { // if оценки не являются смешанными
                                if (st == 4 || st == 5 || st == 6)
                                    st = 2;
                                else
                                    st = 3;
                            } // end if оценки не являются смешанными
                            break;
                        case 6:
                            if (st != 2) { // if оценки не являются смешанными
                                if (st == 3 || st == 5 || st == 6) {
                                    if (st == 3)
                                        st = 2;
                                    if (st == 5)
                                        st = 6;
                                }
                                else
                                    st = 4;
                            } // end if оценки не являются смешанными
                            break;
                        case 7:
                            if (st != 2) { // if оценки не являются смешанными
                                if (st == 3 || st == 5 || st == 6) {
                                    if (st == 3)
                                        st = 2;
                                    if (st == 5)
                                        st = 6;
                                }
                                else
                                    st = 4;
                            } // end if оценки не являются смешанными
                            break;
                        case 8:
                            if (st != 2) { // if оценки не являются смешанными
                                if (st == 3 || st == 5 || st == 6) {
                                    if (st == 3)
                                        st = 2;
                                    if (st == 5)
                                        st = 6;
                                }
                                else
                                    st = 4;
                            } // end if оценки не являются смешанными
                            break;
                        case 9:
                            if (st != 2) { // if оценки не являются смешанными
                                if (st == 3 || st == 4 || st == 6) {
                                    if (st == 3)
                                        st = 2;
                                    if (st == 4)
                                        st = 6;
                                }
                                else
                                    st = 5;
                            } // end if оценки не являются смешанными
                            break;
                        case 10:
                            if (st != 2) { // if оценки не являются смешанными
                                if (st == 3 || st == 4 || st == 6) {
                                    if (st == 3)
                                        st = 2;
                                    if (st == 4)
                                        st = 6;
                                }
                                else
                                    st = 5;
                            } // end if оценки не являются смешанными
                            break;
                        } // end switch
                    } // end if студент не относится к неуспевающим

                } // end if десятибальная систем
                else { // else пятибальная + неявки + незачет + зачет + освобожден + прослушал курс
                    switch (ses[i][j]) { // switch
                    case 0:
                        StringGrid1 -> Cells[j + 4][i + 1] = "Незачет";
                        st = 1;
                        break;
                    case 1:
                        StringGrid1 -> Cells[j + 4][i + 1] = "Зачет";
                        break;
                    case 6:
                        StringGrid1 -> Cells[j + 4][i + 1] = "Не явился";
                        st = 1;
                        break;
                    case 7:
                        StringGrid1 -> Cells[j + 4][i + 1] = "Освобожден";
                        break;
                    case 8:
                        StringGrid1 -> Cells[j + 4][i + 1] = " ";
                        break;
                    case 9:
                        StringGrid1 -> Cells[j + 4][i + 1] = "Прослушал";
                        break;
                    case 10:
                        StringGrid1 -> Cells[j + 4][i + 1] = "Выдана ведомость";
                        st = 1;
                        break;
                    default:
                        StringGrid1 -> Cells[j + 4][i + 1] = ses[i][j];
                        if (st != 1) { // if st!=1
                            switch (ses[i][j]) { // switch
                            case 2:
                                st = 1; // неуспевающий
                                break;
                            case 3:
                                if (st != 2)
                                { // if оценки не являются смешанными
                                    if (st == 4 || st == 5 || st == 6)
                                        st = 2;
                                    else
                                        st = 3;
                                } // end if оценки не являются смешанными
                                break;
                            case 4:
                                if (st != 2)
                                { // if оценки не являются смешанными
                                    if (st == 3 || st == 5 || st == 6) {
                                        if (st == 3)
                                        st = 2;
                                        if (st == 5)
                                        st = 6;
                                    }
                                    else
                                        st = 4;
                                } // end if оценки не являются смешанными
                                break;
                            case 5:
                                if (st != 2)
                                { // if оценки не являются смешанными
                                    if (st == 3 || st == 4 || st == 6) {
                                        if (st == 3)
                                        st = 2;
                                        if (st == 4)
                                        st = 6;
                                    }
                                    else
                                        st = 5;
                                } // end if оценки не являются смешанными
                                break;
                            } // end switch
                        } // end if st!=1
                    } // end switch
                } // end else пятибальная + неявки + незачет + зачет + освобожден

            } // for j
            switch (st) {
                // статус 0-первоначальный статус
                // 1-неуспевающий
                // 2-успевающий на смешанные оценки
                // 3-успевающий на удовлетворительно или 4,5
                // 4-успевающий на хорошо или 6,7,8
                // 5-успевающий на отлично или 9,10
                // 6-успевающий на хорошо и отлично 6,7,8,9,10
            case 0:
                StringGrid1 -> Cells[count_obj + 4][i + 1] = "";
                count0++;
                break;
            case 1:
                StringGrid1 -> Cells[count_obj + 4][i + 1] = "неуспевающий";
                count1++;
                break;
            case 2:
                StringGrid1 -> Cells[count_obj + 4][i + 1] = "смешанные";
                count2++;
                break;
            case 3:
                StringGrid1 -> Cells[count_obj + 4][i + 1] = "удовл.: 4,5";
                count3++;
                break;
            case 4:
                StringGrid1 -> Cells[count_obj + 4][i + 1] = "хор.: 6,7,8";
                count4++;
                break;
            case 5:
                StringGrid1 -> Cells[count_obj + 4][i + 1] = "отл.: 9,10";
                count5++;
                break;
            case 6:
                StringGrid1 -> Cells[count_obj + 4][i + 1] =
                    "хор. и отл.: 6,7,8,9,10";
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
            // ---по основанию обучения
            if (DataModule1 -> People_CaseFDQueryN_FOUND -> Value == 2)
            { // if 2 - это договор
                StringGrid1 -> Cells[3][i + 1] = "Договор";
            }
            else
                StringGrid1 -> Cells[3][i + 1] = "";
            // ---
            // DataModule1 -> People_PartQuery -> Next ();
            DataModule1 -> People_CaseFDQuery -> Next ();

            int kol = 0, sum_ball = 0;
            bool stat = false;
            for (int j = 0; j < count_obj; j++)
            { // 11,12,13 - это 1,2 и 3 в десятибальной системе; 2 и 0 - это 2 балла и незачет, 6 - неяка; 10 - выдана ведомость
                if ( (ses[i][j] == 0) || (ses[i][j] == 2) ||
                    (ses[i][j] == 6) || (ses[i][j] == 10) || (ses[i][j] == 11)
                    || (ses[i][j] == 12) || (ses[i][j] == 13))
                    stat = true; // || (ses[i][j]==8)) stat=true;
                else if (ses[i][j] == 1);
                else { // else  надо суммировать
                    if (ses[i][j] > 10) { // if для десятибальной системы
                        sum_ball += (ses[i][j] - 10);
                        kol++;
                    } // end if для десятибальной системы
                    else { // else элемент массива не больше 10, тогда надо просмотреть другие варианты
                        if (ses[i][j] != 8 && ses[i][j] != 9 && ses[i][j]
                            != 10 && ses[i][j] != 7)
                            // 7-освобожден 10-выдана ведомость 8-ведомость по предмету не выдавалась (не прослушал спец.курс) 9 - прослушал спец.курс
                        { // if для пятибальной системы
                            sum_ball += ses[i][j];
                            kol++;
                        } // end if для пятибальной системы
                    } // end else элемент массива не больше 10, тогда надо просмотреть другие варианты
                } // end else  надо суммировать
            } // for j
            if (stat)
                StringGrid1 -> Cells[1][i + 1] = "Сессия не сдана";
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

        ///-----Расчет процентов

        if (count_peop == (count0 + count1 + count2 + count3 + count4 + count5 +
            count6)) { // if
            /* AnsiString raschet="Всего "+AnsiString (count_peop)+
             + ";\n "+"на отл: "+count5+" чел. - "+ FloatToStrF (count5*100/count_peop,ffFixed,7,3)+
             +"%;\n "+"на отл и хор: "+AnsiString (count6)+" чел. - "+ FloatToStrF (count6*100/count_peop,ffFixed,7,3)+
             +"%;\n  "+"на хор: "+AnsiString (count4)+" чел. - "+ FloatToStrF (count4*100/count_peop,ffFixed,7,3)+
             +"%;\n  "+"на уд: "+AnsiString (count3)+" чел. - "+ FloatToStrF (count3*100/count_peop,ffFixed,7,3)+
             +"%;\n  "+"на смешан: "+AnsiString (count2)+" чел. - "+ FloatToStrF (count2*100/count_peop,ffFixed,7,3)+
             +"%;\n  "+"неуспевающие: "+AnsiString (count1)+" чел. - "+ FloatToStrF (count1*100/count_peop,ffFixed,7,3)+
             +"%;\n  "+"без оценок:"+count0+" чел. - "+ FloatToStrF (count0*100/count_peop,ffFixed,7,3)+"%; ";
             */

            StringGrid2 -> Cells[0][1] = AnsiString (count_peop); // Всего
            StringGrid2 -> Cells[0][2] =
                FloatToStrF (count_peop * 100 / count_peop, ffFixed, 7, 3);

            StringGrid2 -> Cells[1][1] = AnsiString (count5); // отл. 9,10
            StringGrid2 -> Cells[1][2] = FloatToStrF (count5 * 100 / count_peop,
                ffFixed, 7, 3);

            StringGrid2 -> Cells[2][1] = AnsiString (count6);
            // отл./хор. 6,7,8,9,10
            StringGrid2 -> Cells[2][2] = FloatToStrF (count6 * 100 / count_peop,
                ffFixed, 7, 3);

            StringGrid2 -> Cells[3][1] = AnsiString (count4); // хор. 6,7,8
            StringGrid2 -> Cells[3][2] = FloatToStrF (count4 * 100 / count_peop,
                ffFixed, 7, 3);

            StringGrid2 -> Cells[4][1] = AnsiString (count3); // уд. 4,5
            StringGrid2 -> Cells[4][2] = FloatToStrF (count3 * 100 / count_peop,
                ffFixed, 7, 3);

            StringGrid2 -> Cells[5][1] = AnsiString (count2); // смешанные
            StringGrid2 -> Cells[5][2] = FloatToStrF (count2 * 100 / count_peop,
                ffFixed, 7, 3);

            StringGrid2 -> Cells[6][1] = AnsiString (count1); // неуд.
            StringGrid2 -> Cells[6][2] = FloatToStrF (count1 * 100 / count_peop,
                ffFixed, 7, 3);

            StringGrid2 -> Cells[7][1] = AnsiString (count0); // без оценок
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
    } // если найден инкремент группы
    else {
        ShowMessage ("Такого номера группы не существует!");
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

        // ----очищение содержимого первого  StringGrid
        for (int i = 0; i < StringGrid1 -> ColCount + 1; i++)
        { // for  StringGrid1 -> RowCount
            for (int j = 0; j < StringGrid1 -> RowCount; j++)
            { // for  StringGrid1 -> RowCount
                StringGrid1 -> Cells[i][j] = "";
            } // end for  StringGrid1 -> RowCount
        } // end for  StringGrid1 -> ColCount

        // ----очищение содержимого второго  StringGrid
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
        ShowMessage ("Номер группы не соответствует вашему факультету");
        MaskEdit1 -> SetFocus ();
    }
}


void __fastcall TSession_Form::FormClose (TObject *Sender, TCloseAction &Action)
{
    /* if (Bookmark_ses)
     { //if закладка
     DataModule1 -> SessionQuery -> GotoBookmark (Bookmark_ses);
     DataModule1 -> SessionQuery -> FreeBookmark (Bookmark_ses);
     }//end if закладка */

    if (del_mas_neud)
        // переменная для удаления массива ses_neud (true-массив создан)
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

    Variant WSheet = SelectSheet (WBook, "Лист1");
    AnsiString v_ed;
    if (ComboBox1 -> ItemIndex) {
        v_ed = "з";
    }
    else {
        v_ed = "дн";
    }
    CellValue ("Группа " + MaskEdit1 -> Text + v_ed, 1, 1);
    Variant Rang1 = Range2 (WSheet, "A1:D1");
    HorizontalAlign (Rang1, 3);
    CellFont ("Arial", 12, true, false, 2, 0, Rang1);
    M1 (Rang1);
    CellValue (MaskEdit2 -> Text + " семестр", 1, 2);
    Rang1 = Range2 (WSheet, "A2:D2");
    HorizontalAlign (Rang1, 3);
    CellFont ("Arial", 12, true, false, 2, 0, Rang1);
    M1 (Rang1);
    // для форматирования ячеек по вертикали и переноса по словам
    Rang1 = Range2 (WSheet, "A3:Z3");
    W1 (Rang1); // перенос по словам
    HorizontalAlign (Rang1, 3); // выравнивание по горизонтали по центру
    VerticalAlign (Rang1, 2); // выравнивание по вертикали по центру

    // ----Занесение содержимого первого  StringGrid
    for (int i = 0; i < StringGrid1 -> ColCount + 1; i++)
    { // for  StringGrid1 -> ColCount
        CellOrient (i + 1, 3, 90);
        // поворот содержимого третьей строки на 90 градусов

        for (int j = 0; j < StringGrid1 -> RowCount; j++)
        { // for  StringGrid1 -> RowCount
            if (j != StringGrid1 -> RowCount - 1)
                CellValue (j + 1, 1, j + 4);

            CellValue (StringGrid1 -> Cells[i][j], i + 2, j + 3);
            if ( (StringGrid1 -> Cells[i][j] == "1") ||
                (StringGrid1 -> Cells[i][j] == "2") ||
                (StringGrid1 -> Cells[i][j] == "3") ||
                (StringGrid1 -> Cells[i][j] == "Не явился") ||
                (StringGrid1 -> Cells[i][j] == "Незачет"))
            { // выделение красным цветом результата 1,2,3 или не явка
                Rang1 = Range2 (WSheet, mas_column[i + 1] + AnsiString (j + 3));
                CellFont ("Arial", 10, true, false, 1, 3, Rang1);
            }
            BorderCell (i + 1, j + 3, 1, 2);
        } // end for  StringGrid1 -> RowCount
    } // end for  StringGrid1 -> ColCount

    for (int i = 0; i < count_peop; i++) { // для for i
        for (int j = 0; j < count_obj; j++)
        { // для fot j             //ball==0 || ball==2 || ball==11 || ball==12 || ball==13
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
    // ----Занесение содержимого второго  StringGrid
    for (int i = 0; i < StringGrid2 -> ColCount; i++)
    { // for  StringGrid2 -> RowCount
        for (int j = 0; j < StringGrid2 -> RowCount; j++)
        { // for  StringGrid2 -> RowCount
            if (j == StringGrid2 -> RowCount - 1)
            { // if надо сделать числовой формат
                /* int ii=i+2;
                 int jj=StringGrid1 -> RowCount+5+j;
                 Ce1=SelectCell (jj,ii);
                 SheetFormat (Ce1,"0,000");     //    0.000 в самом Excel пишет такой формат
                 CellValue (StrToFloat (StringGrid2 -> Cells[i][j]),ii,jj); */
            } // end if надо сделать числовой формат

            else
                CellValue (StringGrid2 -> Cells[i][j], i + 2,
                StringGrid1 -> RowCount + 5 + j);

            BorderCell (i + 2, StringGrid1 -> RowCount + 5 + j, 1, 2);
        } // end for  StringGrid2 -> RowCount
    } // end for  StringGrid2 -> ColCount

    for (int i = 0; i < StringGrid1 -> ColCount + 1; i++) { // for  AutoFitColumn
        AutoFitColumn (WSheet, i + 1);
    } // end for  AutoFitColumn

    AnsiString name_f = "Результаты сессии " + MaskEdit1 -> Text + v_ed +
        " группы за " + MaskEdit2 -> Text + " семестр за" + cur_d () + ".xls";
    Variant WorkSaveAs = SaveBookAs (WBook, "d:\\Мои документы\\" + name_f);
    OVisible (ExApp);
}


void __fastcall TSession_Form::FormCreate (TObject *Sender) {
    MaskEdit3 -> Text = AnsiString (uch_god); // заносим учебный год
    Label7 -> Caption = "/" + AnsiString (uch_god + 1); // заносим учебный год +1
}


void __fastcall TSession_Form::MaskEdit3Exit (TObject *Sender) {
    Label7 -> Caption = "/" + AnsiString (StrToInt (MaskEdit3 -> Text) + 1);
    // заносим учебный год +1
}


void __fastcall TSession_Form::StringGrid1DrawCell (TObject *Sender, int ACol,
    int ARow, TRect &Rect, TGridDrawState State) {

    for (int i = 0; i < count_peop; i++) { // для for i
        for (int j = 0; j < count_obj; j++)
        { // для fot j             //ball==0 || ball==2 || ball==11 || ball==12 || ball==13
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
    // Как сделать, чтобы в TEdit можно было вводить только числа?
}


void __fastcall TSession_Form::MaskEdit1MouseDown (TObject *Sender,
    TMouseButton Button, TShiftState Shift, int X, int Y) {
    MaskEdit1 -> SelStart = 0;
}


void __fastcall TSession_Form::MaskEdit2MouseDown (TObject *Sender,
    TMouseButton Button, TShiftState Shift, int X, int Y) {
    MaskEdit2 -> SelStart = 0;
}


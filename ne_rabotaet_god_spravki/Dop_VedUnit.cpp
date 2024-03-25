#include <vcl.h>
#pragma hdrstop


#include "CalendarUnit.h"
#include "DataModule_Card.h"
#include "DataModule.h"
#include "DM2Unit.h"
#include "Dop_VedUnit.h"
#include "DualList.h"
#include "VedUnit.h"


#pragma package (smart_init)
// #pragma link     "DualList"
// #pragma link     "MyList"
#pragma resource "*.dfm"


TDop_VedForm * Dop_VedForm;


AnsiString * mas_stud[2];                                                       // массив номеров и фамилий студентов

AnsiString   edu_temp,
             str_ball,
             str_edu,
             str_sql  = "",
             temp;

int        * mas_nom_plan_dop[1];                                               // массив номеров предметов в учебном плане

int          i_group,                                                           // инкремент группы
             mas_nom,                                                           // номер элемента в массиве
             nom_plan,
             rec_p,                                                             // количество записей в People_PartQuery
             ved_ink;




// BitBtn2Click
// BitBtn3Click
// CheckBox1Click
// ComboBox1Change
// ComboBox3Change
// Edit1Click
// Edit2Click
// Edit4KeyPress
// Edit5Change
// FormActivate
// FormClose
// Panel2Click
// search_fio
// search_nomer





__fastcall TDop_VedForm::TDop_VedForm (TComponent* Owner) : TForm (Owner) {
}

// ---------------Поиск ФИО студента по номеру
AnsiString TDop_VedForm::search_fio (int rec_p, int nomer) {
    AnsiString fio;
    for (int i = 0; i < rec_p; i++) {
        if (mas_stud[1][i] == nomer)
            fio = mas_stud[0][i]; // возвращаем ФИО и номер группы студента
    }
    return fio;
}

// --------------Поиск номера студента по ФИО
int TDop_VedForm::search_nomer (int rec_p, AnsiString fio) {
    int nomer;
    for (int i = 0; i < rec_p; i++) {
        if (mas_stud[0][i] == fio)
            nomer = StrToInt (mas_stud[1][i]); // возвращаем номер студента
    }
    return nomer;
}

void __fastcall TDop_VedForm::BitBtn2Click (TObject *Sender) {
    if (ComboBox1 -> Text == "") {
        ShowMessage ("Выберите дисциплину!");
        return;
    }

    if (Edit4 -> Text == "")
        ShowMessage ("Введите номер группы!");
    else {
        if ( (state_query) && (ComboBox3 -> ItemIndex != -1)) {
            DataModule1 -> VedomostFDQuery -> Insert ();
            if (Dop_VedForm -> Caption == "Добавление экзаменационного листа") {
                DataModule1 -> VedomostFDQuerySTATUS -> Value = 1;
            }
            if (Dop_VedForm -> Caption == "Добавление дополнительной ведомости") {
                DataModule1 -> VedomostFDQuerySTATUS -> Value = 2;
            }
            if (Dop_VedForm -> Caption ==
                "Добавление новой ведомости для досрочной сдачи сессии") {
                DataModule1 -> VedomostFDQuerySTATUS -> Value = 3;
            }
            DataModule1 -> VedomostFDQueryN_FAC -> Value = nom_fac;
        }

        // DataModule1 -> vozvrat_inc_ved ();
        DataModule1 -> VedomostFDQueryD_VED -> Value =
            StrToSQLTimeStamp (Edit1 -> Text);
        // ведомость действительна до ????? числа
        if (Edit2 -> Text != "") {
            DataModule1 -> VedomostFDQueryEND_D_EXAM -> Value =
                StrToSQLTimeStamp (Edit2 -> Text);
        }
        else // если не указано конкретное число, то для экзаменационного листа надо добавить + 10 дней
        {
            if (DataModule1 -> VedomostFDQuerySTATUS -> Value == 1 ||
                DataModule1 -> VedomostFDQuerySTATUS -> Value == 3)
            { // переводим текст в дату а дату в Int
                int dat = int (StrToDate (Edit1 -> Text));
                // добавляем + 10 дней
                dat += 10;
                // сохраняем Int сразу в поле
                DataModule1 -> VedomostFDQueryEND_D_EXAM -> Value =
                    StrToSQLTimeStamp (IntToStr (dat));
            }
        }

        DataModule1 -> VedomostFDQueryFIO_EXAM -> Value = Edit7 -> Text;

        if ( (state_query) && (ComboBox3 -> ItemIndex != -1)) {
            nom_plan = mas_nom_plan_dop[0][ComboBox1 -> ItemIndex];

            DataModule1 -> VedomostFDQuerySEMESTR_VED -> Value =
                Edit3 -> Text.ToInt ();
            //DataModule1 -> VedomostFDQueryINVALID -> Value = 0;
            DataModule1 -> VedomostFDQueryN_VEDOMOST -> Value =
                StrToInt (Label11 -> Caption);
            DataModule1 -> VedomostFDQueryN_PLAN -> Value = nom_plan;
            ved_ink = DataModule1 -> VedomostFDQueryN_VED -> Value;
            // нахождение инкремента группы по номеру и виду обучения
            i_group = search_increment_group (Edit4 -> Text, ComboBox2 -> ItemIndex);
            DataModule1 -> VedomostFDQueryINC_GROUP -> Value = i_group;

            if (DataModule1 -> VedomostFDQueryN_VEDOMOST -> Value !=
                Ved_Form -> max_ved (StrToInt (Edit5 -> Text))) {
                DataModule1 -> VedomostFDQueryN_VEDOMOST -> Value =
                    Ved_Form -> max_ved (StrToInt (Edit5 -> Text));
                ShowMessage ("Номер вашей ведомости изменился на " +
                    AnsiString (DataModule1 -> VedomostFDQueryN_VEDOMOST -> Value));
            }

            TLocateOptions K;
            DataModule1 -> VedomostFDQuery -> Locate ("N_VED", ved_ink, K);

            if (!DataModule1 -> Edu_CardFDQuery -> Active)
                DataModule1 -> Edu_CardFDQuery -> Active = true;
            DataModule1 -> Edu_CardFDQuery -> Insert ();
            DataModule1 -> Edu_CardFDQueryNOMER -> Value =
                (int) (ComboBox3 -> Items -> Objects[ComboBox3 -> ItemIndex]);
            DataModule1 -> Edu_CardFDQueryN_VED -> Value = ved_ink;
            DataModule1 -> Edu_CardFDQueryD_EXAM -> Value =
                DataModule1 -> VedomostFDQueryD_VED -> Value;

            DataModule1 -> Edu_CardFDQuery -> ApplyUpdates ();
            DataModule1 -> Edu_CardFDQuery -> CommitUpdates ();

            state_query = 0;

        }

        DataModule1 -> VedomostFDQuery -> ApplyUpdates ();
        DataModule1 -> VedomostFDQuery -> CommitUpdates ();
        DataModule1 -> FDConnection1 -> Commit ();
        Close ();
    }
}

void __fastcall TDop_VedForm::FormClose (TObject *Sender, TCloseAction &Action) {
    /* DataModule1 -> VedomostFDQuery -> Close ();
     DataModule1 -> VedomostFDQuery -> SQL -> Clear ();
     DataModule1 -> VedomostFDQuery -> SQL -> Add ("SELECT Vedomost.N_VED, Vedomost.N_VEDOMOST, Vedomost.D_VED, Vedomost.SEMESTR_VED, Vedomost.FIO_EXAM, Vedomost.STATUS, Vedomost.N_PLAN, Vedomost.N_FAC, Vedomost.END_D_EXAM, Object_plan.NAME_OBJECT, Edu_plan.YEAR_PLAN, Edu_plan.VID_EDU_PLAN FROM VEDOMOST Vedomost INNER JOIN EDU_PLAN Edu_plan ON  (Vedomost.N_PLAN = Edu_plan.N_PLAN) INNER JOIN OBJECT_PLAN Object_plan ON  (Edu_plan.N_OBJECT = Object_plan.N_OBJECT) WHERE (N_FAC=:N_FAC) AND (Edu_plan.YEAR_PLAN=:PLAN)");
     DataModule1 -> VedomostFDQuery -> Params -> Items[0] -> AsInteger=nom_fac;
     DataModule1 -> VedomostFDQuery -> ParamByName ("PLAN") -> Value=uch_god;
     DataModule1 -> VedomostFDQuery -> Open (); */

    if (DataModule1 -> VedomostFDQuery -> State == dsInsert ||
        DataModule1 -> VedomostFDQuery -> State == dsEdit) {
        DataModule1 -> VedomostFDQuery -> CancelUpdates ();
    }

    /* if (Ved_Form -> state_query && DataModule1 -> VedomostFDQuery -> State == dsBrowse)
     { // if сохраняли ведомость, но не выбрали студентов
     TLocateOptions Opts;
     Opts.Clear ();
     Ved_Form -> state_query = 0; // режим редактирования
     Variant s_v = DataModule1 -> VedomostFDQuery -> Locate ("N_VED",
     ved_ink, Opts);
     if (!s_v.IsNull ()) {
     DataModule1 -> VedomostFDQuery -> Delete ();
     }

     DataModule1 -> VedomostFDQuery -> ApplyUpdates ();
     DataModule1 -> VedomostFDQuery -> CommitUpdates ();
     } // end if сохраняли ведомость, но не выбрали студентов */

    if (Ved_Form -> CheckBox1 -> Checked) {
        Ved_Form -> CheckBox1Click (this);
    }
    else {
        Ved_Form -> RadioGroup1Click (this);
    }
    // массив номеров и названий предметов в учебном плане
    for (int i = 0; i < 1; i++)
        delete[]mas_nom_plan_dop[i];
    // delete[] mas_nom_plan_dop;

    Action = caFree;
}

void __fastcall TDop_VedForm::Edit1Click (TObject *Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> ShowModal ();
    if (calendar)
        Edit1 -> Text = cal_date;
    if (DataModule1 -> VedomostFDQuerySTATUS -> Value != 2 &&
        Dop_VedForm -> Caption == "Редактирование ведомости") {
        Edit2 -> SetFocus ();
    }
}

void __fastcall TDop_VedForm::Edit2Click (TObject *Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> ShowModal ();
    if (calendar)
        Edit2 -> Text = cal_date;
    if (DataModule1 -> VedomostFDQuery -> State == dsInsert)
        ComboBox2 -> SetFocus ();
}

void __fastcall TDop_VedForm::Panel2Click (TObject *Sender) {
    try {
        if (Edit5 -> Text != "" && Edit3 -> Text != "" &&
            ComboBox2 -> ItemIndex != -1) {
            ComboBox1 -> Enabled = true;
            Label6 -> Enabled = true;
            ComboBox1 -> Items -> Clear ();

            // ------НОВЫЙ КУСОК

            DataModule1 -> Edu_PlanFDQ -> Close ();
            DataModule1 -> Edu_PlanFDQ -> ParamByName ("N_FAC") -> AsSmallInt =
                nom_fac;
            DataModule1 -> Edu_PlanFDQ -> ParamByName ("PLAN") -> AsInteger =
                StrToInt (Edit5 -> Text);
            DataModule1 -> Edu_PlanFDQ -> ParamByName ("SEM") -> AsSmallInt =
                StrToInt (Edit3 -> Text);
            DataModule1 -> Edu_PlanFDQ -> ParamByName ("VID") -> AsSmallInt =
                ComboBox2 -> ItemIndex;
            DataModule1 -> Edu_PlanFDQ -> Open ();

            DataModule1 -> Edu_PlanFDQ -> Last ();
            // переходим на последнюю т.к. не считался RecordCount ??????
            int col_plan = DataModule1 -> Edu_PlanFDQ -> RecordCount;

            // массив номеров и названий предметов в учебном плане
            for (int i = 0; i < 1; i++)
                mas_nom_plan_dop[i] = new int[col_plan];

            for (int i = 0; i < col_plan; i++) {
                mas_nom_plan_dop[0][i] = DataModule1 -> Edu_PlanFDQN_PLAN -> Value;
                // номер в учебном плане N_PLAN

                AnsiString z = "";
                switch (DataModule1 -> Edu_PlanFDQZACH_EXAM -> Value) {
                case 0:
                    z = " (нет контроля)";
                    break;
                case 1:
                    z = " (зач.)";
                    break;
                case 2:
                    z = " (экз.)";
                    break;
                case 3:
                    z = " (диф.зач.)";
                    break;
                case 4:
                    z = " (ГОС-экзамен)";
                    break;
                }
                ComboBox1 -> Items -> Add (DataModule1 -> Edu_PlanFDQPP -> Value + z);
                // текст предмета + часы

                // ComboBox1 -> Items -> Add (DataModule1 -> Edu_PlanQPP -> Value);  //текст предмета + часы
                DataModule1 -> Edu_PlanFDQ -> Prior ();
            }

            ComboBox1 -> Style = Stdctrls::csDropDownList;
            // предлагаем номер ведомости за выбранный учебный год
            Label11 -> Caption =
                AnsiString (Ved_Form -> max_ved (StrToInt (Edit5 -> Text)));

        } // if
        else {
            ShowMessage ("Проверьте правильность введенных данных!");
        }
    } // try
    catch (...) {
        ShowMessage ("Проверьте правильность введенных данных!");
    }
}

void __fastcall TDop_VedForm::FormActivate (TObject *Sender) {
    if (state_query)
    { // если в Insert, то в Label11 заносится максимальный номер ведомости
        // Label11 -> Caption=AnsiString (Ved_Form -> max_ved ()); //не подходит, т.к. не знаем за какой учебный год ведомость
        Label11 -> Caption = "";
        BitBtn2 -> Enabled = False;
        BitBtn3 -> Enabled = False;
    }
    else // если в Edit, то  в Label11 заносится номер ведомости из Query
    {
        Label11 -> Caption =
            AnsiString (DataModule1 -> VedomostFDQueryN_VEDOMOST -> Value);

    }
}

void __fastcall TDop_VedForm::Edit5Change (TObject *Sender) {
    if (ComboBox1 -> Enabled)
    { // if выбран предмет, но меняется основные записи, от которых зависит учебный план
        ComboBox1 -> Enabled = false;
        Label6 -> Enabled = false;
        ComboBox1 -> Items -> Clear ();
        DataModule1 -> Edu_PlanFDQuery -> Close ();

    } // end if выбран предмет, но меняется основные записи, от которых зависит учебный план
}

void __fastcall TDop_VedForm::Edit4KeyPress (TObject *Sender, char &Key) {
    DataModule1 -> Edit_Key (Key);
    // Как сделать, чтобы в TEdit можно было вводить только числа?
}

void __fastcall TDop_VedForm::ComboBox1Change (TObject *Sender) {
    str_sql = "";
    temp = "";
    str_ball = "";
    edu_temp = "";
    str_edu = "";
    nom_plan = mas_nom_plan_dop[0][ComboBox1 -> ItemIndex];
    i_group = search_increment_group (Edit4 -> Text, ComboBox2 -> ItemIndex);

    DataModule1 -> VedomostFDQuery -> Close ();
    DataModule1 -> VedomostFDQuery -> SQL -> Clear ();
    DataModule1 -> VedomostFDQuery -> SQL -> Add ("SELECT Vedomost.N_VED, Vedomost.N_VEDOMOST, Vedomost.D_VED, Vedomost.SEMESTR_VED, Vedomost.FIO_EXAM,\
     Vedomost.STATUS, Vedomost.N_PLAN, Vedomost.N_FAC, Vedomost.END_D_EXAM, Vedomost.INC_GROUP,\
     Vedomost.N_SPECIALIZ, Object_plan.NAME_OBJECT, Edu_plan.YEAR_PLAN, Edu_plan.VID_EDU_PLAN, Vedomost.INVALID\
     FROM Vedomost, Edu_plan, Object_plan \
     WHERE (Vedomost.N_PLAN = Edu_plan.N_PLAN) AND (Edu_plan.N_OBJECT = Object_plan.N_OBJECT) AND (edu_plan.N_FAC=:N_FAC) AND (Edu_plan.YEAR_PLAN=:PLAN) AND (edu_plan.N_PLAN="
        + AnsiString (nom_plan) + ") AND (Vedomost.INVALID = 0)");

    DataModule1 -> VedomostFDQuery -> Params -> Items[0] -> AsInteger = nom_fac;
    DataModule1 -> VedomostFDQuery -> ParamByName ("PLAN") -> Value =
        Edit5 -> Text.ToInt ();
    DataModule1 -> VedomostFDQuery -> Open ();

    DataModule1 -> Vedomost_CountFDQuery -> Close ();
    DataModule1 -> Vedomost_CountFDQuery -> SQL -> Clear ();
    DataModule1 -> Vedomost_CountFDQuery -> SQL -> Add ("SELECT COUNT (Vedomost.N_VED) \
     FROM Vedomost, Edu_plan, Object_plan \
     WHERE (Vedomost.N_PLAN = Edu_plan.N_PLAN) AND (Edu_plan.N_OBJECT = Object_plan.N_OBJECT) AND (edu_plan.N_FAC=:N_FAC) AND (Edu_plan.YEAR_PLAN=:PLAN) AND (edu_plan.N_PLAN="
        + AnsiString (nom_plan) + ") AND (Vedomost.INVALID = 0)");

    DataModule1 -> Vedomost_CountFDQuery -> Params -> Items[0] -> AsInteger = nom_fac;
    DataModule1 -> Vedomost_CountFDQuery -> ParamByName ("PLAN") -> Value =
        Edit5 -> Text.ToInt ();
    DataModule1 -> Vedomost_CountFDQuery -> Open ();

    // изменения

    for (int i = 0; i < DataModule1 -> Vedomost_CountFDQueryCOUNT -> Value; i++) {
        temp = " (N_VED=" + AnsiString (DataModule1 -> VedomostFDQueryN_VED -> Value);
        if (i != DataModule1 -> Vedomost_CountFDQueryCOUNT -> Value - 1) {
            str_sql += temp + ") OR ";
        } // if
        else
            str_sql += temp + "))";
        DataModule1 -> VedomostFDQuery -> Next ();
    } // for
    str_sql = " and EDU_CARD.NOMER not in (select EDU_CARD.NOMER FROM EDU_CARD WHERE (" + str_sql;

    DataModule1 -> People_EduCardFDQuery -> Close ();
    DataModule1 -> People_EduCardFDQuery -> SQL -> Clear ();

    str_ball =
        " AND EDU_CARD.BALL in (1,3,4,5,7,14,15,16,17,18,19,20)) ";
    if ( (Dop_VedForm -> Caption ==
        "Добавление новой ведомости для досрочной сдачи сессии")) {
        DataModule1 -> People_PartFDQuery -> Close ();
        DataModule1 -> People_PartFDQuery -> SQL -> Clear ();
        DataModule1 -> People_PartFDQuery -> SQL -> Add
            ("SELECT NOMER, FAM, NAME, OTCH, INC_GROUP, N_GROUP, VID_EDU, KURS, N_FOUND FROM PEOPLE WHERE (N_FAC=" +
            AnsiString (nom_fac) + ") AND (STATUS_PEOPLE=1) AND (INC_GROUP=" +
            AnsiString (i_group) + ") ORDER BY FAM, NAME, OTCH");
        DataModule1 -> People_PartFDQuery -> Open ();

        ComboBox3 -> Items -> Clear ();
        while (!DataModule1 -> People_PartFDQuery -> Eof) {
            ComboBox3 -> Items -> AddObject
                (DataModule1 -> People_PartFDQueryFAM -> Value + " " +
                DataModule1 -> People_PartFDQueryNAME -> Value + " " +
                DataModule1 -> People_PartFDQueryOTCH -> Value + " " +
                DataModule1 -> People_PartFDQueryN_GROUP -> Value + " гр.",
                (TObject *) (DataModule1 -> People_PartFDQueryNOMER -> Value));
            DataModule1 -> People_PartFDQuery -> Next ();
        } // while

        Panel1 -> Visible = true;
        CheckBox1 -> Visible = false;
        Panel1 -> SetFocus ();
    }
    else {
        DataModule1 -> People_EduCardFDQuery -> SQL -> Add
            ("SELECT distinct EDU_CARD.NOMER, FAM, NAME, OTCH, INC_GROUP, N_GROUP, VID_EDU, KURS, N_FOUND FROM PEOPLE, EDU_CARD WHERE PEOPLE.NOMER = EDU_CARD.NOMER AND (N_FAC = " +
            AnsiString (nom_fac) + ") AND (STATUS_PEOPLE = 1) AND (INC_GROUP = " +
            AnsiString (i_group) + ")" + str_sql + str_ball +
            " ORDER BY FAM, NAME, OTCH ");
        if (DataModule1 -> Vedomost_CountFDQueryCOUNT -> Value != 0) {

            // DataModule1 -> People_PartQuery -> Params -> Items[0] -> AsInteger=nom_fac;
            DataModule1 -> People_EduCardFDQuery -> Open ();

            mas_nom = 0;

            // изменения
            ComboBox3 -> Items -> Clear ();
            ComboBox3 -> Text = "";
            while (!DataModule1 -> People_EduCardFDQuery -> Eof) {
                ComboBox3 -> Items -> AddObject
                    (DataModule1 -> People_EduCardFDQueryFAM -> Value + " " +
                    DataModule1 -> People_EduCardFDQueryNAME -> Value + " " +
                    DataModule1 -> People_EduCardFDQueryOTCH -> Value + " " +
                    DataModule1 -> People_EduCardFDQueryN_GROUP -> Value + " гр.",
                    (TObject *)
                    (DataModule1 -> People_EduCardFDQueryNOMER -> Value));
                DataModule1 -> People_EduCardFDQuery -> Next ();
            } // while

            Panel1 -> Visible = true;
            Panel1 -> SetFocus ();

        } // если есть записи в Edu_Card
        else {
            ShowMessage (
                " Основная ведомость по данному предмету не была создана.Повторите ввод ведомости еще раз !");
            state_query = 0; // режим редактирования
            Close ();
            return;
        }
    }

}

void __fastcall TDop_VedForm::CheckBox1Click (TObject *Sender) {
    BitBtn2 -> Enabled = False;
    str_ball = " ";
    edu_temp = " ";
    str_edu = " ";
    DataModule1 -> People_EduCardFDQuery -> Close ();
    DataModule1 -> People_EduCardFDQuery -> SQL -> Clear ();
    if (CheckBox1 -> Checked) {
        str_ball = " AND (EDU_CARD.BALL = -1) ";
    }
    else {
        str_ball =
            " AND (EDU_CARD.BALL = 0 OR EDU_CARD.BALL = 2 OR EDU_CARD.BALL = 6 OR EDU_CARD.BALL = 8 OR EDU_CARD.BALL = 11 OR EDU_CARD.BALL = 12 OR EDU_CARD.BALL = 13) ";
    }

    DataModule1 -> People_EduCardFDQuery -> SQL -> Add
        ("SELECT distinct EDU_CARD.NOMER, FAM, NAME, OTCH, INC_GROUP, N_GROUP, VID_EDU, KURS, N_FOUND FROM PEOPLE, EDU_CARD WHERE PEOPLE.NOMER = EDU_CARD.NOMER AND (N_FAC = " +
        AnsiString (nom_fac) + ") AND (STATUS_PEOPLE = 1) AND (INC_GROUP = " +
        AnsiString (i_group) + ")" + str_sql + str_ball +
        " ORDER BY FAM, NAME, OTCH ");

    if (DataModule1 -> Vedomost_CountFDQueryCOUNT -> Value != 0) {

        // DataModule1 -> People_PartQuery -> Params -> Items[0] -> AsInteger=nom_fac;
        DataModule1 -> People_EduCardFDQuery -> Open ();

        for (int i = 0; i < 2; i++) { // for1
            mas_stud[i] = new AnsiString[rec_p];
        }
        mas_nom = 0;

        // изменения
        ComboBox3 -> Items -> Clear ();
        ComboBox3 -> Text = "";
        while (!DataModule1 -> People_EduCardFDQuery -> Eof) {
            // ФИО студента и номер группы
            ComboBox3 -> Items -> AddObject
                (DataModule1 -> People_EduCardFDQueryFAM -> Value + " " +
                DataModule1 -> People_EduCardFDQueryNAME -> Value + " " +
                DataModule1 -> People_EduCardFDQueryOTCH -> Value + " " +
                DataModule1 -> People_EduCardFDQueryN_GROUP -> Value + " гр.",
                (TObject *) (DataModule1 -> People_EduCardFDQueryNOMER -> Value));
            DataModule1 -> People_EduCardFDQuery -> Next ();
        } // while

    } // если есть записи в Edu_Card
    else {
        ShowMessage (
            " Основная ведомость по данному предмету не была создана.Повторите ввод ведомости еще раз !");
        state_query = 0; // режим редактирования
        Close ();
        return;
    }
} // если есть записи в Edu_Card

void __fastcall TDop_VedForm::ComboBox3Change (TObject *Sender) {
    if (ComboBox3 -> ItemIndex != -1) {
        BitBtn2 -> Enabled = True;
    }
}
void __fastcall TDop_VedForm::BitBtn3Click (TObject *Sender)
{
   { // При редактировании ведомости изменять можно только 2 поля дату, и  DBEdit ФИО
        DataModule1 -> VedomostFDQueryINVALID -> Value = 1;
        DataModule1 -> VedomostFDQuery -> ApplyUpdates ();
        DataModule1 -> VedomostFDQuery -> CommitUpdates ();
        Close ();
    } // end if Edit
}


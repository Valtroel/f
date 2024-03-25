// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "CalendarUnit.h"
#include "Ved_RatingUnit.h"
#include "DataModule.h"
#include "Dop_Ved_RatingUnit.h"
#include "Rating_ReportUnit.h"
// ---------------------------------------------------------------------------
#pragma package (smart_init)
#pragma resource "*.dfm"
TVed_RatingForm *Ved_RatingForm;

// строка основного SQL

AnsiString sql_r = "SELECT Specializ.SPECIAL, Vedomost_rating.N_SPECIALIZ, \
Vedomost_rating.N_VED_RATING, Vedomost_rating.N_VEDOMOST_R, \
Vedomost_rating.N_FAC, Vedomost_rating.VID_EDU, Vedomost_rating.UCH_GOD, \
Vedomost_rating.SEMESTR, Vedomost_rating.SESSION, Vedomost_rating.INC_GROUP, \
Vedomost_rating.CURATOR, Vedomost_rating.D_VED, Vedomost_rating.END_D_VED, \
Increment_group.N_GROUP, Faculty.FAC1 \
FROM VEDOMOST_RATING Vedomost_rating  \
   INNER JOIN SPECIALIZ Specializ  \
   ON (Vedomost_rating.N_SPECIALIZ = Specializ.N_SPECIALIZ) \
   INNER JOIN INCREMENT_GROUP Increment_group \
   ON (Vedomost_rating.INC_GROUP = Increment_group.INC_GROUP) \
   INNER JOIN FACULTY Faculty \
   ON (Vedomost_rating.N_FAC = Faculty.N_FAC) \
WHERE (Vedomost_rating.N_FAC =:FAC)";

// часть строки SQl для формирования ведомости по учебному году
AnsiString god_r[3] = {
    " AND (Vedomost_rating.UCH_GOD=:GOD) AND (Vedomost_rating.SESSION in (1,2))",
    " AND (Vedomost_rating.UCH_GOD=:GOD) AND (Vedomost_rating.SESSION=1)",
    " AND (Vedomost_rating.UCH_GOD=:GOD) AND (Vedomost_rating.SESSION=2)"};

// часть строки SQL для сортировки
AnsiString sql_end = " order by Vedomost_rating.N_VEDOMOST_R ";

// массив строк для sql по виду обучения
AnsiString edu_r[2] = {
    " AND (Vedomost_rating.VID_EDU=0)", " AND (Vedomost_rating.VID_EDU=1)"};

// часть строки SQl для формирования ведомости по дате
AnsiString data_ved_r = "AND (Vedomost_rating.D_VED BETWEEN :D1 AND :D2)";

// часть строки SQl для формирования ведомости по номеру группы
AnsiString ved_gr = "AND (Vedomost_rating.INC_GROUP=:GR) ";

// ---------------------------------------------------------------------------
__fastcall TVed_RatingForm::TVed_RatingForm (TComponent* Owner) : TForm (Owner) {
}

// ---------------------------------------------------------------------------
int __fastcall TVed_RatingForm::max_ved_r ()
{ // вызов функции для нахождения максимального номера ведомости

    DataModule1 -> Max_Ved_RatingFDQuery -> Close ();
    DataModule1 -> Max_Ved_RatingFDQuery -> ParamByName ("N_FAC") -> AsSmallInt =
        nom_fac;
    DataModule1 -> Max_Ved_RatingFDQuery -> ParamByName ("GOD") -> AsSmallInt = uch_god;
    DataModule1 -> Max_Ved_RatingFDQuery -> Open ();
    return DataModule1 -> Max_Ved_RatingFDQueryMAX -> Value + 1;

}

// ---------------------------------------------------------------------------
void __fastcall TVed_RatingForm::ved_run_r () { // формирование SQL по параметрам

    AnsiString full_sql = "";
    int god_vibor = uch_god;

    full_sql = sql_r + god_r[RadioGroup1 -> ItemIndex] +
        edu_r[RadioGroup2 -> ItemIndex];

    DataModule1 -> Rating_GridFDQuery -> Close ();
    DataModule1 -> Rating_GridFDQuery -> SQL -> Clear ();

    if (CheckBox1 -> Checked) // Ведомости за период
    { // if Ch1  выбран период
        full_sql += data_ved_r;
    }

    if (CheckBox2 -> Checked) // По группе
    { // if Ch2
        full_sql += ved_gr;

    } // end if Ch2

    if (CheckBox3 -> Checked) { // if Ch3
        god_vibor = Edit4 -> Text.ToInt ();
    } // end if Ch3

    DataModule1 -> Rating_GridFDQuery -> SQL -> Add (full_sql + sql_end);
    DataModule1 -> Rating_GridFDQuery -> Params -> Items[0] -> AsInteger = nom_fac;
    DataModule1 -> Rating_GridFDQuery -> ParamByName ("GOD") -> AsSmallInt = god_vibor;

    // ---параметры
    if (CheckBox2 -> Checked) // По группе
    { // if Ch2
        Variant p_n = search_increment_group (Edit3 -> Text,
        RadioGroup2 -> ItemIndex); // функция, возвращающая инкремент группы
        if (!p_n.IsNull ()) { // if найдена такая группа
            DataModule1 -> Rating_GridFDQuery -> ParamByName ("GR") -> Value = p_n;
            Ved_RatingForm -> Caption = "Список ведомостей рейтинга по группе: " +
                Edit3 -> Text;
        } // end if найдена такая группа
        else {
            ShowMessage ("Такой группы на вашем факультете нет!");
            Edit3 -> Text = "";
            CheckBox2 -> Checked = false;
            DataModule1 -> Rating_GridFDQuery -> SQL -> Clear ();
            DataModule1 -> Rating_GridFDQuery -> SQL -> Add
               (sql_r + god_r[RadioGroup1 -> ItemIndex] +
                edu_r[RadioGroup2 -> ItemIndex] + sql_end);
            DataModule1 -> Rating_GridFDQuery -> Params -> Items[0] -> AsInteger =
                nom_fac;
            DataModule1 -> Rating_GridFDQuery -> ParamByName ("GOD") -> AsSmallInt =
                uch_god;
        }
    } // end if Ch2
    // ------
    if (CheckBox1 -> Checked) // Ведомости за период:
    { // if Ch3  указан конкретный период
        DataModule1 -> Rating_GridFDQuery -> ParamByName ("D1") -> AsDateTime =
            Edit1 -> Text;
        DataModule1 -> Rating_GridFDQuery -> ParamByName ("D2") -> AsDateTime =
            Edit2 -> Text;
        Ved_RatingForm -> Caption = "Список ведомостей рейтинга за период с " +
            Edit1 -> Text + " по " + Edit2 -> Text;
    } // end if Ch3

    if (!CheckBox1 -> Checked && !CheckBox2 -> Checked) { // if !Ch1 !Ch2
        // !Ch1 учебный год текущий
        Ved_RatingForm -> Caption = "";
        Ved_RatingForm -> Caption = "Список ведомостей рейтинга за " +
            IntToStr (god_vibor) + "/" + IntToStr (god_vibor + 1) +
            " учебный год";
    }

    DataModule1 -> Rating_GridFDQuery -> Open ();
    DataModule1 -> Rating_GridFDQuery -> Last ();

}

// -----------------------------------------------------------------------------
void __fastcall TVed_RatingForm::CheckBox2Click (TObject *Sender)
{ // ПО НОМЕРУ ГРУППЫ
    if (CheckBox2 -> Checked) { // if включили поиск по номеру группы
        // ----- отключаем
        CheckBox1 -> Enabled = false;
        BitBtn4 -> Enabled = false;

        CheckBox3 -> Enabled = false;
        BitBtn6 -> Enabled = false;
        // -----  включаем
        Edit3 -> Enabled = true;
        Label8 -> Enabled = true;
        BitBtn7 -> Enabled = true;
    } // end if включили поиск
    else { // else отключили
        ved_run_r ();

        CheckBox1 -> Enabled = true;
        CheckBox3 -> Enabled = true;
        // назад отключаем
        Label8 -> Enabled = false;
        Edit3 -> Text = "";
        Edit3 -> Enabled = false;
        BitBtn7 -> Enabled = false;
    } // end else отключили
}

// ---------------------------------------------------------------------------
void __fastcall TVed_RatingForm::CheckBox3Click (TObject *Sender)
{ // за учебный год
    if (CheckBox3 -> Checked) { // if включили поиск за учебный год
        // ----- отключаем
        CheckBox2 -> Enabled = false;
        BitBtn7 -> Enabled = false;

        CheckBox1 -> Enabled = false;
        BitBtn4 -> Enabled = false;
        // ----- включаем
        Edit4 -> Enabled = true;
        Label1 -> Enabled = true;
        BitBtn6 -> Enabled = true;
    } // end if включили поиск за учебный год
    else { // else отключили
        ved_run_r ();

        CheckBox2 -> Enabled = true;
        CheckBox1 -> Enabled = true;

        // назад отключаем
        UpDown1 -> Position = uch_god;
        Edit4 -> Text = AnsiString (uch_god);

        Edit4 -> Enabled = false;
        Label1 -> Enabled = false;
        BitBtn6 -> Enabled = false;

    } // end else отключили
}

// ---------------------------------------------------------------------------
void __fastcall TVed_RatingForm::CheckBox1Click (TObject *Sender) { // ЗА ПЕРИОД
    if (CheckBox1 -> Checked) { // if включили поиск за учебный год
        // ----- отключаем
        CheckBox2 -> Enabled = false;
        BitBtn7 -> Enabled = false;

        CheckBox3 -> Enabled = false;
        BitBtn6 -> Enabled = false;
        // ----- включаем
        Edit1 -> Enabled = true;
        Edit2 -> Enabled = true;
        Label3 -> Enabled = true;
        Label4 -> Enabled = true;
        BitBtn4 -> Enabled = true;
    } // end if включили поиск за учебный год
    else { // else отключили
        ved_run_r ();

        CheckBox2 -> Enabled = true;
        CheckBox3 -> Enabled = true;
        // назад отключаем
        Edit1 -> Text = "";
        Edit2 -> Text = "";
        Edit1 -> Enabled = false;
        Edit2 -> Enabled = false;
        Label3 -> Enabled = false;
        Label4 -> Enabled = false;
        BitBtn4 -> Enabled = false;

    } // end else отключили
}

// ---------------------------------------------------------------------------
void __fastcall TVed_RatingForm::Edit1Click (TObject *Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> ShowModal ();
    if (calendar)
        Edit1 -> Text = cal_date;
    Edit2 -> SetFocus ();
}

// ---------------------------------------------------------------------------
void __fastcall TVed_RatingForm::Edit2Click (TObject *Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> ShowModal ();
    if (calendar)
        Edit2 -> Text = cal_date;
    BitBtn4 -> SetFocus ();
}

// ---------------------------------------------------------------------------
void __fastcall TVed_RatingForm::BitBtn4Click (TObject *Sender) {
    if ( (Edit1 -> Text != "") && (Edit2 -> Text != "")) {
        ved_run_r ();
        CheckBox2 -> Enabled = true;
        CheckBox3 -> Enabled = true;
    }
    else
        ShowMessage ("Введите даты за период!");
}

// ---------------------------------------------------------------------------
void __fastcall TVed_RatingForm::BitBtn7Click (TObject *Sender) {
    if (Edit3 -> Text != "") {
        ved_run_r ();
        CheckBox1 -> Enabled = true;
        CheckBox3 -> Enabled = true;
    }
    else
        ShowMessage ("Введите номер группы!");
}

// ---------------------------------------------------------------------------
void __fastcall TVed_RatingForm::RadioGroup1Click (TObject *Sender) {
    ved_run_r ();
}
// ---------------------------------------------------------------------------

void __fastcall TVed_RatingForm::FormCreate (TObject *Sender) {
    // вызов SQL для формирования ведомостей

    UpDown1 -> Position = uch_god;
    Edit4 -> Text = AnsiString (uch_god);

}

// ---------------------------------------------------------------------------
void __fastcall TVed_RatingForm::BitBtn1Click (TObject *Sender) {
    Dop_Ved_RatingForm = new TDop_Ved_RatingForm (this);
    // Создание формы Формирование ведомости

    Dop_Ved_RatingForm -> Panel1 -> Visible = true;
    Dop_Ved_RatingForm -> Panel2 -> Visible = false;

    // вызов функции для нахождения максимального номера ведомости
    Dop_Ved_RatingForm -> Label4 -> Caption = AnsiString (max_ved_r ());

    Dop_Ved_RatingForm -> Caption = "Добавление ведомости рейтинга";
    Dop_Ved_RatingForm -> ShowModal ();
}

// ---------------------------------------------------------------------------
void __fastcall TVed_RatingForm::BitBtn2Click (TObject *Sender) {
    Rating_ReportForm = new TRating_ReportForm (this);
    DataModule1 -> Rating_ReportFDQuery -> Close ();
    DataModule1 -> Rating_ReportFDQuery -> ParamByName ("FAC") -> AsInteger = nom_fac;
    DataModule1 -> Rating_ReportFDQuery -> ParamByName ("N_VED") -> AsInteger =
        DataModule1 -> Rating_GridFDQueryN_VED_RATING -> Value;
    DataModule1 -> Rating_ReportFDQuery -> Open ();

    /* !!!//если в группе студентов мало, то расширяем межстрочные интервалы в ведомости
     if (DataModule1 -> Rating_ReportQuery -> RecordCount<27)
     {
     Rating_ReportForm -> DetailBand1 -> Height=25;

     Rating_ReportForm -> QRShape7 -> Height=25;
     Rating_ReportForm -> QRShape11 -> Height=25;

     Rating_ReportForm -> QRDBText4 -> Top=4;
     Rating_ReportForm -> QRSysData1 -> Top=4;

     }
     else
     {
     Rating_ReportForm -> DetailBand1 -> Height=20;

     Rating_ReportForm -> QRShape7 -> Height=20;
     Rating_ReportForm -> QRShape11 -> Height=20;

     Rating_ReportForm -> QRDBText4 -> Top=3;
     Rating_ReportForm -> QRSysData1 -> Top=3;
     } */

    if (Rating_ReportForm -> frxReport1 -> PrepareReport (true))
        Rating_ReportForm -> frxReport1 -> ShowPreparedReport ();

}

// ---------------------------------------------------------------------------
void __fastcall TVed_RatingForm::DBGrid1DblClick (TObject *Sender) {
    Dop_Ved_RatingForm = new TDop_Ved_RatingForm (this);
    // Создание формы Формирование ведомости
    // вызов функции для нахождения максимального номера ведомости

    Dop_Ved_RatingForm -> Panel1 -> Visible = false;
    Dop_Ved_RatingForm -> Panel2 -> Visible = true;

    Dop_Ved_RatingForm -> Caption = "Редактирование ведомости рейтинга";

    // Определение вида обучения
    if (DataModule1 -> Rating_GridFDQueryVID_EDU -> Value) { // if заочное
        Dop_Ved_RatingForm -> Label12 -> Caption = "Заочное";
    } // end if заочное
    else
        Dop_Ved_RatingForm -> Label12 -> Caption = "Дневное"; // else дневное

    // Передача параметров на форму
    Dop_Ved_RatingForm -> DateTimePicker3 -> Date =
        SQLTimeStampToDateTime (DataModule1 -> Rating_GridFDQueryD_VED -> Value);
    Dop_Ved_RatingForm -> DateTimePicker4 -> Date =
        SQLTimeStampToDateTime (DataModule1 -> Rating_GridFDQueryEND_D_VED -> Value);
    Dop_Ved_RatingForm -> Edit8 -> Text =
        DataModule1 -> Rating_GridFDQueryCURATOR -> Value;

    Dop_Ved_RatingForm -> ShowModal ();
}

void __fastcall TVed_RatingForm::BitBtn6Click (TObject *Sender) {
    if (Edit4 -> Text != "") {
        ved_run_r ();
        CheckBox1 -> Enabled = true;
        CheckBox2 -> Enabled = true;
    }
    else
        ShowMessage ("Введите другой учебный год!");
}
// ---------------------------------------------------------------------------

void __fastcall TVed_RatingForm::Edit3KeyPress (TObject *Sender, char &Key) {
    DataModule1 -> Edit_Key (Key);
    // Как сделать, чтобы в TEdit можно было вводить только числа?
}
// ---------------------------------------------------------------------------

void __fastcall TVed_RatingForm::ApplicationEvents1Message (tagMSG &Msg,
    bool &Handled) {
    // организовать нормальную работу мышиного колесика в DBGrid

    if (DBGrid1 -> Focused ()) {
        if (Msg.message == WM_MOUSEWHEEL) {
            Msg.message = WM_KEYDOWN;
            Msg.lParam = 0;
            short int i = HIWORD (Msg.wParam);
            Msg.wParam = (i > 0) ? VK_UP : VK_DOWN;
            Handled = false;
        }
    }

}
// ---------------------------------------------------------------------------

void __fastcall TVed_RatingForm::FormActivate (TObject *Sender) {
    ved_run_r ();
}
// ---------------------------------------------------------------------------

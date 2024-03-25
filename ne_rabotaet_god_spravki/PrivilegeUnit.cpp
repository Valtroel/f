#include <vcl.h>
#pragma hdrstop


#include "DataModule.h"
#include "MainUnit.h"
#include "PrivilegeUnit.h"


#pragma package (smart_init)
// #pragma link     "ToolEdit"
#pragma resource "*.dfm"


TPrivilegeForm * PrivilegeForm;


AnsiString sql_glav = "                                 \
    SELECT                                              \
        Priv.N_PRIV,                                    \
        Priv.NOMER,                                     \
        Priv.VID_PRIV,                                  \
        Priv.UCH_GOD,                                   \
        Priv.TEXT_PRIV,                                 \
        Priv.DOC_PRIV,                                  \
        Priv.DATA_C,                                    \
        Priv.DATA_PO,                                   \
        Priv.DESCRIBE,                                  \
        People.FAM,                                     \
        People.NAME,                                    \
        People.OTCH,                                    \
        People.VID_EDU,                                 \
        People.N_FAC,                                   \
        People.KURS,                                    \
        People.N_GROUP,                                 \
        People.STATUS_PEOPLE,                           \
        People.INC_GROUP                                \
    FROM                                                \
        PRIV Priv                                       \
            INNER JOIN                                  \
                PEOPLE People                           \
                    ON                                  \
                        (Priv.NOMER = People.NOMER)     \
    WHERE                                               \
            People.N_FAC         = :FAC                 \
        AND                                             \
            People.VID_EDU       = :EDU                 \
        AND                                             \
            People.STATUS_PEOPLE = 1                    \
        AND                                             \
            Priv.VID_PRIV        = :PRIV                \
    ";
AnsiString sql_god_date = "                             \
    AND                                                 \
        (                                               \
            Priv.UCH_GOD = :GOD                         \
         OR                                             \
            (:D BETWEEN Priv.data_c AND Priv.data_po)   \
        )                                               \
    ";
AnsiString sql_god  = "                                 \
    AND                                                 \
        Priv.UCH_GOD = :GOD                             \
    ";
AnsiString sql_date = "                                 \
    AND                                                 \
        (:D BETWEEN Priv.data_c AND Priv.data_po)       \
    ";
AnsiString sql_last = "                                 \
    ORDER BY                                            \
        People.KURS,                                    \
        People.FAM,                                     \
        People.NAME,                                    \
        People.OTCH                                     \
    ";

int vid_priv = 0;                                                               // вид привилегии




// ApplicationEvents1Message
// Button1Click
// Button2Click
// Button3Click
// CheckBox1Click
// DateTimePicker1Change
// DateTimePicker2Change
// DateTimePicker3Change
// DBGrid1DblClick
// FormClose
// FormCreate
// FormResize
// open_sql
// RadioGroup1Click
// RadioGroup2Click
// refrech_priv
// UpDown1Click




__fastcall TPrivilegeForm::TPrivilegeForm (TComponent* Owner) : TForm (Owner) {
}


void __fastcall TPrivilegeForm::open_sql () {

    AnsiString full_sql = sql_glav;
    DataModule1 -> Priv_AddFDQuery -> Close ();
    DataModule1 -> Priv_AddFDQuery -> SQL -> Clear ();
    DataModule1 -> Priv_AddFDQuery -> SQL -> Add (full_sql);

    if (CheckBox1 -> Checked) { // if включен критерий выбора по году
        DataModule1 -> Priv_AddFDQuery -> SQL -> Add (sql_god);
        DataModule1 -> Priv_AddFDQuery -> ParamByName ("GOD") -> AsSmallInt =
            Edit1 -> Text.ToInt ();
    }

    if (CheckBox2 -> Checked) { // if включен критерий выбора по конкретной дате
        DataModule1 -> Priv_AddFDQuery -> SQL -> Add (sql_date);
        DataModule1 -> Priv_AddFDQuery -> ParamByName ("D") -> AsDateTime =
            DateToStr (DateTimePicker3 -> Date);
    }

    if (!CheckBox1 -> Checked && !CheckBox2 -> Checked)
    { // if отключены все критерии
        DataModule1 -> Priv_AddFDQuery -> SQL -> Add (sql_god_date);
        DataModule1 -> Priv_AddFDQuery -> ParamByName ("GOD") -> AsSmallInt =
            Edit1 -> Text.ToInt ();
        DataModule1 -> Priv_AddFDQuery -> ParamByName ("D") -> AsDateTime =
            curent_date;
    }
    DataModule1 -> Priv_AddFDQuery -> SQL -> Add (sql_last);
    DataModule1 -> Priv_AddFDQuery -> ParamByName ("FAC") -> AsSmallInt = nom_fac;
    DataModule1 -> Priv_AddFDQuery -> ParamByName ("EDU") -> AsSmallInt =
        RadioGroup2 -> ItemIndex;
    DataModule1 -> Priv_AddFDQuery -> ParamByName ("PRIV") -> AsSmallInt =
        (70 - spisok_f1);

    DataModule1 -> Priv_AddFDQuery -> Open ();

}


void __fastcall TPrivilegeForm::refrech_priv (int r)
{ // функция заполнения полей в зависимости от выбора справки

    // int r - действие 0 -  добавление
    // 1 -  редактирование

    AnsiString text_priv = ""; // категория
    AnsiString doc_priv = ""; // документ
    AnsiString desc = ""; // примечание
    AnsiString data_c = "  .  .    "; // дата с ....
    AnsiString data_po = "  .  .    "; // дата по ....

    if (!r) { // if !r --  добавление

        data_c = DateToStr (curent_date);
        data_po = "30.06." + AnsiString (StrToInt (Edit1 -> Text) + 1);

        switch (spisok_f1) { // switch  добавление новой справки
        case 67: // инвалиды
            text_priv = "Инвалид __ гр.";
            doc_priv = "Удостоверение инвалида № ___";
            vid_priv = 3;
            break;
        case 68: // чернобыльцы
            text_priv = "ЧАЭС ст. __";
            doc_priv = "Справка № ___  от _________";
            vid_priv = 2;
            break;
        case 69: // сироты
            text_priv = "Сирота";
            doc_priv = "Справка № ___  от _________";
            vid_priv = 1;
            break;

        } // end switch добавление новой справки

    } // end if !r --  добавление
    else { // else --  редактирование
        text_priv = DataModule1 -> Priv_AddFDQueryTEXT_PRIV -> Value;
        doc_priv = DataModule1 -> Priv_AddFDQueryDOC_PRIV -> Value;
        desc = DataModule1 -> Priv_AddFDQueryDESCRIBE -> Value;
        data_c =
            DateToStr (SQLTimeStampToDateTime
            (DataModule1 -> Priv_AddFDQueryDATA_C -> Value));
        data_po =
            DateToStr (SQLTimeStampToDateTime
            (DataModule1 -> Priv_AddFDQueryDATA_PO -> Value));
    } // end else --  редактирование

    LabeledEdit1 -> Text = text_priv; // категория
    LabeledEdit2 -> Text = doc_priv; // документ
    LabeledEdit3 -> Text = desc; // Примечание
    DateTimePicker1 -> Date = StrToDate (data_c); // дата с ....
    DateTimePicker2 -> Date = StrToDate (data_po); // дата по ....

}


void __fastcall TPrivilegeForm::FormClose (TObject *Sender, TCloseAction &Action)
{
    Action = caFree;
}


void __fastcall TPrivilegeForm::UpDown1Click (TObject *Sender, TUDBtnType Button)
{
    Label2 -> Caption = "/" + AnsiString (StrToInt (Edit1 -> Text) + 1);

    if (DBGrid1 -> Visible) {
        if (!Panel3 -> Visible) {
            DBGrid1 -> Visible = false;
            DataModule1 -> Priv_AddFDQuery -> Close ();
        }

    }
}


void __fastcall TPrivilegeForm::RadioGroup1Click (TObject *Sender) {
    RadioGroup2 -> Visible = true;
    RadioGroup2 -> ItemIndex = -1;
    GroupBox1 -> Visible = false;

    Panel2 -> Visible = false;
    Button3 -> Visible = false;
    Panel3 -> Visible = false;
    Panel4 -> Visible = false;
    PrivilegeForm -> Height = 213;

    DataModule1 -> Priv_AddFDQuery -> Close ();
    DBGrid1 -> Enabled = true;
    DBGrid1 -> Visible = false;

}


void __fastcall TPrivilegeForm::RadioGroup2Click (TObject *Sender) {

    UpDown1 -> Position = uch_god;
    Edit1 -> Text = AnsiString (uch_god);
    Label2 -> Caption = "/" + AnsiString (uch_god + 1);

    DateTimePicker3 -> Date = StrToDate (curent_date);
    CheckBox1 -> State = cbUnchecked;
    CheckBox2 -> State = cbUnchecked;
    GroupBox1 -> Visible = true;

    DataModule1 -> Priv_AddFDQuery -> Close ();
    DBGrid1 -> Visible = false;

    Panel3 -> Visible = false;
    Panel4 -> Visible = false;

    switch (RadioGroup1 -> ItemIndex) {
    case 0: // Добавление
        Panel2 -> Visible = true;
        Panel1 -> Align = alTop;
        Panel1 -> Height = 185;
        Panel2 -> Align = alTop;
        Panel2 -> Height = 48;
        PrivilegeForm -> Height = 261;

        Button1 -> Caption = "Добавить";
        break;
    case 1: // Изменение
        Panel2 -> Visible = true;
        // Panel1 -> Align=alTop;
        // Panel1 -> Height=185;
        // Panel2 -> Align=alTop;
        // Panel2 -> Height=48;
        Panel2 -> Align = alBottom;
        Panel1 -> Align = alClient;
        Panel2 -> Height = 48;
        Panel1 -> Height = 185;
        PrivilegeForm -> Height = 261;

        Button1 -> Caption = "Показать";
        break;
    case 2: // Просмотр
        Panel2 -> Visible = true;
        Panel2 -> Align = alBottom;
        Panel1 -> Align = alClient;
        PrivilegeForm -> Height = 500;

        Button1 -> Caption = "Просмотр";
        break;
    }

}


void __fastcall TPrivilegeForm::Button1Click (TObject *Sender) {

    switch (RadioGroup1 -> ItemIndex) {
    case 0: // Добавление
        Panel2 -> Visible = false;

        Panel3 -> Visible = true;
        Panel4 -> Visible = true;
        PrivilegeForm -> Height = 500;

        Label6 -> Caption = "ФИО студента: ";
        DBLookupComboBox1 -> Visible = true;

        DataModule1 -> People_SpravkiFDQuery -> Close ();
        DataModule1 -> People_SpravkiFDQuery -> ParamByName ("FAC") -> AsSmallInt =
            nom_fac;
        DataModule1 -> People_SpravkiFDQuery -> ParamByName ("EDU") -> AsSmallInt =
            RadioGroup2 -> ItemIndex;
        DataModule1 -> People_SpravkiFDQuery -> Open ();

        refrech_priv (RadioGroup1 -> ItemIndex);
        break;

    default: // Изменение  Просмотр
        open_sql ();
        DBGrid1 -> Visible = true;
        break;
    }

}


void __fastcall TPrivilegeForm::FormCreate (TObject *Sender) {
    // текущая дата
    curent_date = cur_d ();
}



void __fastcall TPrivilegeForm::DBGrid1DblClick (TObject *Sender) {
    switch (RadioGroup1 -> ItemIndex) { // switch
    case 1: // Изменение
        // Panel2 -> Visible=false;
        Panel1 -> Align = alTop;
        Panel1 -> Height = 185;
        Panel2 -> Align = alTop;
        Panel2 -> Height = 48;

        Panel3 -> Visible = true;
        Panel4 -> Visible = true;
        PrivilegeForm -> Height = 500;

        Label6 -> Caption = "ФИО студента: " +
            DataModule1 -> Priv_AddFDQueryFAM -> Value + " " +
            DataModule1 -> Priv_AddFDQueryNAME -> Value + " " +
            DataModule1 -> Priv_AddFDQueryOTCH -> Value;
        DBLookupComboBox1 -> Visible = false;

        refrech_priv (RadioGroup1 -> ItemIndex);

        DBGrid1 -> Enabled = false;
        Button3 -> Visible = true;
        break;
    case 2: // Просмотр
        AnsiString f = "Удалить информацию по данному студенту: " +
            DataModule1 -> Priv_AddFDQueryFAM -> Value + " " +
            DataModule1 -> Priv_AddFDQueryNAME -> Value + " " +
            DataModule1 -> Priv_AddFDQueryOTCH -> Value + "?";
        // !!!if (Application -> MessageBox (f.c_str (), "Внимание", MB_YESNO) == mrYes)
        if (MessageDlg (f.c_str (), mtWarning, TMsgDlgButtons () << mbYes << mbNo,
            0) == mrYes) {
            try {
                DataModule1 -> Priv_AddFDQuery -> Delete ();
                DataModule1 -> Priv_AddFDQuery -> CommitUpdates ();
                Button1Click (this);
            }
            catch (...) {
                DataModule1 -> Priv_AddFDQuery -> CancelUpdates ();
                ShowMessage ("Произошел сбой при удалении!");
            }
        }
        break;
    } // end switch

}


void __fastcall TPrivilegeForm::Button2Click (TObject *Sender) {
    // --- Проверка на вшивость
    if (LabeledEdit1 -> Text == "") { // if категория
        ShowMessage ("Укажите категорию привилегии!");
        return;
    }
    ///
    if (LabeledEdit2 -> Text == "") { // if документ
        ShowMessage ("Укажите название документа!");
        return;
    }
    ////

    if (!RadioGroup1 -> ItemIndex) { // if Добавление
        if (DBLookupComboBox1 -> Text == "") { // if ФИО
            ShowMessage ("Выберите ФИО студента!");
            return;
        } // end if ФИО

        if (DataModule1 -> Priv_AddFDQuery -> State == dsInactive)
            DataModule1 -> Priv_AddFDQuery -> Open ();

        DataModule1 -> Priv_AddFDQuery -> Insert ();
        DataModule1 -> Priv_AddFDQueryNOMER -> Value =
            DBLookupComboBox1 -> KeyValue; // номер студента
        DataModule1 -> Priv_AddFDQueryVID_PRIV -> Value = vid_priv;
        DataModule1 -> Priv_AddFDQueryUCH_GOD -> Value = StrToInt (Edit1 -> Text);

    } // end if Добавление
    else { // else редактирование
        DataModule1 -> Priv_AddFDQuery -> Edit ();

    } // end else редактирование

    DataModule1 -> Priv_AddFDQueryTEXT_PRIV -> Value = LabeledEdit1 -> Text;
    DataModule1 -> Priv_AddFDQueryDOC_PRIV -> Value = LabeledEdit2 -> Text;
    DataModule1 -> Priv_AddFDQueryDESCRIBE -> Value = LabeledEdit3 -> Text;
    DataModule1 -> Priv_AddFDQueryDATA_C -> Value =
        DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);
    DataModule1 -> Priv_AddFDQueryDATA_PO -> Value =
        DateTimeToSQLTimeStamp (DateTimePicker2 -> Date);

    try { // try сохранить
        DataModule1 -> Priv_AddFDQuery -> ApplyUpdates ();
        DataModule1 -> Priv_AddFDQuery -> CommitUpdates ();
        ShowMessage ("Сохранение прошло успешно!");
        DataModule1 -> People_SpravkiFDQuery -> Close ();
        RadioGroup1 -> ItemIndex = -1;
        RadioGroup1Click (this);
    } // end try сохранить
    catch (...) { // catch произошел сбой
        DataModule1 -> Priv_AddFDQuery -> CancelUpdates ();
        ShowMessage ("Произошел сбой при сохранении! Попробуйте еще раз!");
    } // end catch произошел сбой

}


void __fastcall TPrivilegeForm::Button3Click (TObject *Sender) {
    DBGrid1 -> Enabled = true;
    Button3 -> Visible = false;

    Panel3 -> Visible = false;
    Panel4 -> Visible = false;
    PrivilegeForm -> Height = 261;

}


void __fastcall TPrivilegeForm::CheckBox1Click (TObject *Sender) {
    if (DBGrid1 -> Visible) {
        if (!Panel3 -> Visible) {
            DBGrid1 -> Visible = false;
            DataModule1 -> Priv_AddFDQuery -> Close ();
        }
    }
}


void __fastcall TPrivilegeForm::ApplicationEvents1Message (tagMSG &Msg,
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


void __fastcall TPrivilegeForm::DateTimePicker3Change (TObject *Sender) {
    DateTimePicker3 -> Time = StrToTime ("00:00");
}


void __fastcall TPrivilegeForm::DateTimePicker1Change (TObject *Sender) {
    DateTimePicker1 -> Time = StrToTime ("00:00");
}


void __fastcall TPrivilegeForm::DateTimePicker2Change (TObject *Sender) {
    DateTimePicker2 -> Time = StrToTime ("00:00");
}

void __fastcall TPrivilegeForm::FormResize (TObject *Sender)
{
    DBGrid1 -> Width = PrivilegeForm -> Width - 260;
}



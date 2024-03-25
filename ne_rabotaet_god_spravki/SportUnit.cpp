// Форма Спортивные достижения

// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <stdio.h>
#include <math.h>
#include "SportUnit.h"
#include "DataModule.h"
#include "DM2Unit.h"
// ---------------------------------------------------------------------------
#pragma package (smart_init)
// !!!#pragma link "ToolEdit"
#pragma resource "*.dfm"

int nom_sport;
// переменная для определения номера спорта для поиска значения в базе
int nom;
// переменная для определения номера студента для поиска значения в базе

int SportOpen = 0; // Определение переменных
TSportForm *SportForm;

// ---------------------------------------------------------------------------
__fastcall TSportForm::TSportForm (TComponent* Owner) : TForm (Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TSportForm::FormActivate (TObject *Sender)
    // При активизации формы
{
    DataModule1 -> SportFDQuery -> Close ();
    // Закрытие Query для установки параметров
    DataModule1 -> SportFDQuery -> Params -> Items[0] -> AsInteger =
        DataModule1 -> PeopleFDQueryNOMER -> Value;
    DataModule1 -> SportFDQuery -> Open (); // Выполнение запроса
    SportOpen = 1; // Для определения, что форма открыта
}

// ---------------------------------------------------------------------------
void __fastcall TSportForm::FormDeactivate (TObject *Sender)
    // При закрытии формы
{
    SportOpen = 0; // Для определения, что форма закрыта
}

// ---------------------------------------------------------------------------
void __fastcall TSportForm::FormClose (TObject *Sender, TCloseAction &Action) {
    Action = caFree;
}
// ---------------------------------------------------------------------------

void __fastcall TSportForm::RadioGroup1Click (TObject *Sender) {
    // ----очищение всех компонентов на Panel2

    DBLookupComboBox3 -> KeyValue = -1; // вид спорта
    ComboBox3 -> Items -> Clear (); // судейская категория или спортивный разряд
    ComboBox3 -> ItemIndex = -1;
    Edit1 -> Text = ""; // № приказа
    Edit2 -> Text = ""; // Кто присвоил спортивный разряд
    DateTimePicker1 -> Date = Now (); // Дата приказа
    DateTimePicker1 -> Time = StrToTime ("00:00");
    // -----

    if (RadioGroup1 -> ItemIndex) { // если добавление судейской категории
        Label7 -> Caption = "Судейская категория";
        ComboBox3 -> Items -> Add ("Судья по спорту");
        ComboBox3 -> Items -> Add ("Судья 1 категории");
        ComboBox3 -> Items -> Add ("Судья национальной категории");
        ComboBox3 -> Items -> Add ("Судья высшей национальной категории");
        ComboBox3 -> Items -> Add ("Судья международной категории");
    } // end if
    else { // если добавление спортивного разряда
        Label7 -> Caption = "Спортивный разряд";
        // -----занесение видов спорта в ComboBox
        DM2 -> CategoryFDTable -> First ();
        for (int i = 0; i < DM2 -> CategoryFDTable -> RecordCount; i++) { // for
            ComboBox3 -> Items -> Add
                (DM2 -> CategoryFDTableTEXT_SPORT_CATEGORY -> Value);
            DM2 -> CategoryFDTable -> Next ();
        } // end for
    } // end else
    Panel2 -> Visible = true;

}
// ---------------------------------------------------------------------------

void __fastcall TSportForm::BitBtn3Click (TObject *Sender) {
    // Действия по кнопке сохранить на форме Спортивные достижения
    if ( (DBLookupComboBox3 -> Text != "") && (ComboBox3 -> Text != "")) { // if

        nom_sport = DBLookupComboBox3 -> KeyValue; // запоминаем номер вида спорта
        nom = DataModule1 -> PeopleFDQueryNOMER -> Value;
        // Занесение в переменную номера текущего студента

        Set<TLocateOption, 0, 1>Flags; // Установка флага для поиска
        bool found = DataModule1 -> SportFDQuery -> Locate ("NOMER;N_VID_SPORT",
            VarArrayOf (OPENARRAY (Variant, (nom, nom_sport))), Flags);
        /* В переменную
         заносится результат поиска есть ли в БД запись с номером nom и
         видом спорта nom_sport */
        if (!found) { // if Insert
            // Если не запись не найдена

            DataModule1 -> SportFDQuery -> Insert ();
            // Query переходит в режим вставки

            DataModule1 -> SportFDQueryNOMER -> Value = nom;
            // В SportFDQuery заносится номер текущего студента

            DataModule1 -> SportFDQueryN_VID_SPORT -> Value = nom_sport;
            // В SportFDQuery заносится номер вида спорта
            if (RadioGroup1 -> ItemIndex) { // if судейская категория

                DataModule1 -> SportFDQuerySUD_CATEGORY -> Value =
                    ComboBox3 -> ItemIndex + 1; /* Занесение
                 значения из  ComboBox- а в БД */
                DataModule1 -> SportFDQuerySPORT_CATEGORY -> Value = 12;
                // заносим сразу спортивный разряд - нет,
                // т.к. это поле является обязательным в базе
                if (Edit1 -> Text != "")
                    DataModule1 -> SportFDQueryN_PRIKAZ_SUD -> Value =
                        Edit1 -> Text.ToInt ();
                DataModule1 -> SportFDQueryD_PRIKAZ_SUD -> Value =
                    DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);
                if (Edit2 -> Text != "")
                    DataModule1 -> SportFDQueryWHO_GIVE_SUD -> Value = Edit2 -> Text;

            } // end if  судейская категория
            else { // else спортивный разряд
                Variant sport_r =
                    DM2 -> CategoryFDTable -> Lookup ("TEXT_SPORT_CATEGORY",
                    ComboBox3 -> Text, "SPORT_CATEGORY");
                if (!sport_r.IsNull ())
                    DataModule1 -> SportFDQuerySPORT_CATEGORY -> Value =
                        sport_r.AsType (varInteger);
                else {
                    ShowMessage (
                        "Проверьте правильность введенный данных по спортивному разряду!");
                    return;
                }
                if (Edit1 -> Text != "")
                    DataModule1 -> SportFDQueryN_PRIKAZ_SPORT -> Value =
                        Edit1 -> Text.ToInt ();
                DataModule1 -> SportFDQueryD_PRIKAZ_SPORT -> Value =
                    DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);
                if (Edit2 -> Text != "")
                    DataModule1 -> SportFDQueryWHO_GIVE -> Value = Edit2 -> Text;
            } // end else спортивный разряд

        } // end if Insert
        else { // else Edit
            DataModule1 -> SportFDQuery -> Edit ();
            // иначе Query переходит в режим редактирования
            if (RadioGroup1 -> ItemIndex) { // if судейская категория

                DataModule1 -> SportFDQuerySUD_CATEGORY -> Value =
                    ComboBox3 -> ItemIndex + 1; /* Занесение
                 значения из  ComboBox- а в БД */

                if (Edit1 -> Text != "")
                    DataModule1 -> SportFDQueryN_PRIKAZ_SUD -> Value =
                        Edit1 -> Text.ToInt ();
                DataModule1 -> SportFDQueryD_PRIKAZ_SUD -> Value =
                    DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);
                if (Edit2 -> Text != "")
                    DataModule1 -> SportFDQueryWHO_GIVE_SUD -> Value = Edit2 -> Text;

            } // end if  судейская категория
            else { // else спортивный разряд
                Variant sport_r =
                    DM2 -> CategoryFDTable -> Lookup ("TEXT_SPORT_CATEGORY",
                    ComboBox3 -> Text, "SPORT_CATEGORY");
                if (!sport_r.IsNull ())
                    DataModule1 -> SportFDQuerySPORT_CATEGORY -> Value =
                        sport_r.AsType (varInteger);
                else {
                    ShowMessage (
                        "Проверьте правильность введенный данных по спортивному разряду!");
                    return;
                }
                if (Edit1 -> Text != "")
                    DataModule1 -> SportFDQueryN_PRIKAZ_SPORT -> Value =
                        Edit1 -> Text.ToInt ();
                DataModule1 -> SportFDQueryD_PRIKAZ_SPORT -> Value =
                    DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);
                if (Edit2 -> Text != "")
                    DataModule1 -> SportFDQueryWHO_GIVE -> Value = Edit2 -> Text;
            } // end else спортивный разряд

        } // end else Edit

        DataModule1 -> SportFDQuery -> ApplyUpdates ();
        DataModule1 -> SportFDQuery -> CommitUpdates ();
    } // end if
    else { // else проверка на ввод данных
        if (RadioGroup1 -> ItemIndex)
            ShowMessage (
            "Введите данные по виду спорта или судейской категории!");
        else
            ShowMessage (
            "Введите данные по виду спорта или спортивному разряду!");
    } // end else проверка на ввод данных
    RadioGroup1 -> ItemIndex = -1;
    Panel2 -> Visible = false;
}
// ---------------------------------------------------------------------------

void __fastcall TSportForm::BitBtn4Click (TObject *Sender) {
    // действия по кнопке Отменить
    DataModule1 -> SportFDQuery -> CancelUpdates ();
    Panel2 -> Visible = false;
    RadioGroup1 -> ItemIndex = -1;
}
// ---------------------------------------------------------------------------

void __fastcall TSportForm::BitBtn1Click (TObject *Sender) {
    // При нажатии на кнопку Закрыть
    // закрытие формы
    Close ();
}
// ---------------------------------------------------------------------------

void __fastcall TSportForm::BitBtn2Click (TObject *Sender) {
    // действие по кнопке удалить
    AnsiString box_sport =
        "Удаление " + DataModule1 -> SportFDQueryVID_SPORT1 -> Value +
        AnsiString (" ") + DataModule1 -> SportFDQuerySPORT_CATEGORY1 -> Value;
    // !!!if (Application -> MessageBox (box_sport.c_str (),"Удалить выбранные данные ?", MB_YESNO)== IDYES)
    if (MessageDlg (box_sport.c_str (), mtConfirmation,
        TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes) { // Удаление выбранной записи
        DataModule1 -> SportFDQuery -> Delete ();
        DataModule1 -> SportFDQuery -> ApplyUpdates ();
        DataModule1 -> SportFDQuery -> CommitUpdates ();
    }
}
// ---------------------------------------------------------------------------

void __fastcall TSportForm::Edit1KeyPress (TObject *Sender, char &Key) {
    DataModule1 -> Edit_Key (Key);
    // Как сделать, чтобы в TEdit можно было вводить только числа?
}
// ---------------------------------------------------------------------------
void __fastcall TSportForm::DateTimePicker1Change (TObject *Sender)
{
DateTimePicker1 -> Time = StrToTime ("00:00");
}
//---------------------------------------------------------------------------


#include <vcl.h>
#pragma hdrstop


#include "DataModule.h"
#include "Func.h"
#include "JournalUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TJournalForm * JournalForm;


TBookmark Bookmark;

Variant   ExApp;




// BitBtn1Click
// RadioGroup3Click




__fastcall TJournalForm::TJournalForm (TComponent* Owner) : TForm (Owner) {
}

void __fastcall TJournalForm::BitBtn1Click (TObject *Sender) {
    // RadioGroup1 -> ItemIndex: 0-Все вед-ти; 1-Основные вед-ти; 2-Экзам. листы
    // RadioGroup2 -> ItemIndex: 0-Все ведомости; 1-дневного; 2-заочного
    if (RadioGroup3 -> ItemIndex) {
        DataModule1 -> VedListJournal -> Close ();

        DataModule1 -> VedListJournal -> Params -> Items[0] -> AsInteger = nom_fac;
        DataModule1 -> VedListJournal -> Params -> ParamByName ("N_FAC") -> AsSmallInt =
            nom_fac;
        DataModule1 -> VedListJournal -> Params -> ParamByName ("VID_EDU")
            -> AsSmallInt = RadioGroup1 -> ItemIndex;
        DataModule1 -> VedListJournal -> Params -> ParamByName ("STATUS") -> AsSmallInt =
            RadioGroup1 -> ItemIndex;
        DataModule1 -> VedListJournal -> Params -> ParamByName ("D1") -> AsDateTime =
            StrToDate (Edit1 -> Text);
        DataModule1 -> VedListJournal -> Params -> ParamByName ("D2") -> AsDateTime =
            StrToDate (Edit2 -> Text);

        DataModule1 -> VedListJournal -> Open ();

        // вызываем Excel

        ExApp = Variant::CreateObject ("Excel.Application");
        Variant WBook = NewBook (ExApp);
        Variant WSheet = SelectSheet (WBook, "Лист1");

        Variant C1 = SelectCell (1, 1);
        Variant C2 = SelectCell (9, 1);
        Variant R = Range_Range (WSheet, C1, C2);
        M1 (R);
        CellValue (IntToStr (uch_god) + "/" + IntToStr (uch_god + 1) +
            " учебный год", 1, 1);
        // количество записей в Query
        int col_row = DataModule1 -> VedListJournal -> RecordCount;

        // Закладка, для того, чтобы вернуться на запись с которой ушли
        // !!!Bookmark=NULL;
        Bookmark = DataModule1 -> VedListJournal -> GetBookmark ();
        // переход на первую запись
        DataModule1 -> VedListJournal -> First ();
        OVisible (ExApp);
        CellValue ("№ ведомости", 1, 2);
        CellValue ("1", 1, 3);
        CellValue ("Учебная дисциплина, выносимая\nна экзаменную сессию", 2, 2);
        CellValue ("2", 2, 3);
        CellValue ("Семестр,\n№ группы", 3, 2);
        CellValue ("3", 3, 3);
        CellValue ("Фамилия, инициалы\nполучателя ведомости", 4, 2);
        CellValue ("4", 4, 3);
        CellValue ("Фамилия, инициалы\nстудента", 5, 2);
        CellValue ("5", 5, 3);
        CellValue ("Сумма\nоплаты", 6, 2);
        CellValue ("6", 6, 3);
        CellValue ("№ квитанции,\nдата оплаты", 7, 2);
        CellValue ("7", 7, 3);
        CellValue ("Дата\nвыдачи\nведомости ", 8, 2);
        CellValue ("8", 8, 3);
        CellValue ("Дата возврата\nведомости,\nподпись", 9, 2);
        CellValue ("9", 9, 3);

        // Цикл
        for (int i = 0; i <= col_row; i++) { // for1
            if (!i) {
                // if для шапочки (название колонок берется напрямую из Grid-a)
                /* CellValue (Grid -> Columns -> Items[j] -> Title -> Caption, j + 1,
                 i + 1);
                 BorderCell (j + 1, i + 1, 1, 2); */
            }
            // формат ячейки текстовый
            else { // else для остальных записей

                CellValue (DataModule1 -> VedListJournalN_VEDOMOST -> Value,
                1, i + 3);
                CellValue (DataModule1 -> VedListJournalNAME_OBJECT -> Value,
                    2, i + 3);
                CellValue (DataModule1 -> VedListJournalN_GROUP -> Value, 3, i + 3);
                CellValue (DataModule1 -> VedListJournalFIO_EXAM -> Value, 4, i + 3);
                CellValue (DataModule1 -> VedListJournalFIO -> Value, 5, i + 3);
                CellValue (DataModule1 -> VedListJournalD_VED -> AsDateTime,
                    8, i + 3);
            }

            if (i)
                DataModule1 -> VedListJournal -> Next ();
            // переходим на следующюю запись, если это не шапочка
        } // end for2

        CellOrient (1, 2, 90);
        CellOrient (3, 2, 90);
        CellOrient (9, 2, 90);

        // делаем автоширину столбцов
        // DataModule1 -> ExAutoFit (1, Grid -> FieldCount);
        for (int j = 1; j < DataModule1 -> VedListJournal -> FieldCount + 3; j++)
        { // for  AutoFitColumn
            AutoFitColumn (WSheet, j);
        } // end for  AutoFitColumn
        ColumnWidth (Range2 (WSheet, "G:G"), 13);
        ColumnWidth (Range2 (WSheet, "H:H"), 10);

        for (int i = 2; i <= col_row + 3; i++) {
            for (int j = 1; j < DataModule1 -> VedListJournal -> FieldCount +
                3; j++) {
                BorderCell (j, i, 1, 2);
            }
        }
        Variant C;
        C = SelectCell (2, 2);
        HorizontalAlign (C, 3);
        C = SelectCell (2, 3);
        HorizontalAlign (C, 3);
        C = SelectCell (1, 2);
        VerticalAlign (C, 2);
        C = SelectCell (2, 2);
        HorizontalAlign (C, 3);
        C = SelectCell (3, 2);
        VerticalAlign (C, 2);
        C = SelectCell (4, 2);
        HorizontalAlign (C, 3);
        C = SelectCell (5, 2);
        HorizontalAlign (C, 3);
        C = SelectCell (6, 2);
        HorizontalAlign (C, 3);
        C = SelectCell (7, 2);
        HorizontalAlign (C, 3);
        C = SelectCell (8, 2);
        HorizontalAlign (C, 3);
        C = SelectCell (9, 2);
        VerticalAlign (C, 2);

        for (int i = 1; i <= col_row + 3; i++) {
            C = SelectCell (1, i);
            HorizontalAlign (C, 3);
            for (int j = 3; j < DataModule1 -> VedListJournal -> FieldCount +
                3; j++) {
                C = SelectCell (j, i);
                HorizontalAlign (C, 3);
            }
        }

        // App_n.OlePropertySet ("Visible", true);
        // OVisible (ExApp);
        // переходим на закладку и очищаем её
        DataModule1 -> VedListJournal -> GotoBookmark (Bookmark);
        DataModule1 -> VedListJournal -> FreeBookmark (Bookmark);
    }
    else {
        DataModule1 -> VedJournal -> Close ();

        DataModule1 -> VedJournal -> Params -> Items[0] -> AsInteger = nom_fac;
        DataModule1 -> VedJournal -> Params -> ParamByName ("N_FAC") -> AsSmallInt =
            nom_fac;
        DataModule1 -> VedJournal -> Params -> ParamByName ("VID_EDU") -> AsSmallInt =
            RadioGroup1 -> ItemIndex;
        DataModule1 -> VedJournal -> Params -> ParamByName ("KURS") -> AsSmallInt =
            RadioGroup2 -> ItemIndex + 1;
        DataModule1 -> VedJournal -> Params -> ParamByName ("STATUS") -> AsSmallInt =
            RadioGroup1 -> ItemIndex;
        DataModule1 -> VedJournal -> Params -> ParamByName ("D1") -> AsDateTime =
            StrToDate (Edit1 -> Text);
        DataModule1 -> VedJournal -> Params -> ParamByName ("D2") -> AsDateTime =
            StrToDate (Edit2 -> Text);

        DataModule1 -> VedJournal -> Open ();

        // вызываем Excel

        ExApp = Variant::CreateObject ("Excel.Application");
        Variant WBook = NewBook (ExApp);
        Variant WSheet = SelectSheet (WBook, "Лист1");

        Variant C1 = SelectCell (1, 1);
        Variant C2 = SelectCell (7, 1);
        Variant R = Range_Range (WSheet, C1, C2);
        M1 (R);
        CellValue (IntToStr (RadioGroup2 -> ItemIndex + 1) + " курс (с " +
            Edit1 -> Text + " по " + Edit2 -> Text + ")", 1, 1);
        // количество записей в Query
        int col_row = DataModule1 -> VedJournal -> RecordCount;

        // Закладка, для того, чтобы вернуться на запись с которой ушли
        // !!!Bookmark=NULL;
        Bookmark = DataModule1 -> VedJournal -> GetBookmark ();
        // переход на первую запись
        DataModule1 -> VedJournal -> First ();
        OVisible (ExApp);
        CellValue ("№ ведомости", 1, 2);
        CellValue ("1", 1, 3);
        CellValue ("Учебная дисциплина, выносимая\nна экзаменную сессию", 2, 2);
        CellValue ("2", 2, 3);
        CellValue ("№ группы", 3, 2);
        CellValue ("3", 3, 3);
        CellValue ("Фамилия, инициалы\nполучателя ведомости", 4, 2);
        CellValue ("4", 4, 3);
        CellValue ("Дата выдачи\nведомости", 5, 2);
        CellValue ("5", 5, 3);
        CellValue ("Подпись в\nполучении", 6, 2);
        CellValue ("6", 6, 3);
        CellValue ("Дата возврата\nведомости,\nподпись", 7, 2);
        CellValue ("7", 7, 3);

        // Цикл
        for (int i = 0; i <= col_row; i++) { // for1
            if (!i) {
                // if для шапочки (название колонок берется напрямую из Grid-a)
                /* CellValue (Grid -> Columns -> Items[j] -> Title -> Caption, j + 1,
                 i + 1);
                 BorderCell (j + 1, i + 1, 1, 2); */
            }
            // формат ячейки текстовый
            else { // else для остальных записей

                CellValue (DataModule1 -> VedJournalN_VEDOMOST -> Value, 1, i + 3);
                CellValue (DataModule1 -> VedJournalNAME_OBJECT -> Value, 2, i + 3);
                WSheet.OlePropertyGet ("Cells", i + 3, 3).OlePropertySet (WideString ("NumberFormat"), WideString ("@"));
                CellValue (DataModule1 -> VedJournalN_GROUP -> AsString, 3, i + 3);
                CellValue (DataModule1 -> VedJournalFIO_EXAM -> Value, 4, i + 3);
                CellValue (DataModule1 -> VedJournalD_VED -> AsDateTime, 5, i + 3);
            }

            if (i)
                DataModule1 -> VedJournal -> Next ();
            // переходим на следующюю запись, если это не шапочка
        } // end for2

        CellOrient (1, 2, 90);
        CellOrient (3, 2, 90);
        CellOrient (7, 2, 90);

        // делаем автоширину столбцов
        // DataModule1 -> ExAutoFit (1, Grid -> FieldCount);
        for (int j = 0; j < DataModule1 -> VedJournal -> FieldCount + 2; j++)
        { // for  AutoFitColumn
            AutoFitColumn (WSheet, j + 1);
        } // end for  AutoFitColumn

        ColumnWidth (Range2 (WSheet, "E:E"), 10);
        ColumnWidth (Range2 (WSheet, "F:F"), 10);

        for (int i = 2; i <= col_row + 3; i++) {
            for (int j = 1; j < DataModule1 -> VedJournal -> FieldCount + 2; j++) {
                BorderCell (j, i, 1, 2);
            }
        }
        Variant C;
        C = SelectCell (2, 2);
        HorizontalAlign (C, 3);
        C = SelectCell (2, 3);
        HorizontalAlign (C, 3);
        C = SelectCell (1, 2);
        VerticalAlign (C, 2);
        C = SelectCell (2, 2);
        HorizontalAlign (C, 3);
        C = SelectCell (3, 2);
        VerticalAlign (C, 2);
        C = SelectCell (4, 2);
        HorizontalAlign (C, 3);
        C = SelectCell (5, 2);
        HorizontalAlign (C, 3);
        C = SelectCell (6, 2);
        HorizontalAlign (C, 3);
        C = SelectCell (7, 2);
        HorizontalAlign (C, 3);

        for (int i = 1; i <= col_row + 3; i++) {
            C = SelectCell (1, i);
            HorizontalAlign (C, 3);
            for (int j = 3; j < DataModule1 -> VedJournal -> FieldCount + 2; j++) {
                C = SelectCell (j, i);
                HorizontalAlign (C, 3);
            }
        }

        // App_n.OlePropertySet ("Visible", true);
        // OVisible (ExApp);
        // переходим на закладку и очищаем её
        DataModule1 -> VedJournal -> GotoBookmark (Bookmark);
        DataModule1 -> VedJournal -> FreeBookmark (Bookmark);
        // !!!Bookmark=NULL;
    }

    // очищаем память
    /* App_n.Clear ();
     Sh.Clear (); */
}

void __fastcall TJournalForm::RadioGroup3Click (TObject *Sender) {
    if (!RadioGroup3 -> ItemIndex) {
        RadioGroup2 -> ItemIndex = -1;
    }
}

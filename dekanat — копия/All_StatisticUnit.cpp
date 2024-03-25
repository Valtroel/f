#include <vcl.h>
#pragma hdrstop


#include "All_StatisticUnit.h"
#include "CalendarUnit.h"
#include "DataModule.h"
#include "DM2Unit.h"
#include "Func.h"


#pragma package (smart_init)
// #pragma link     "ToolEdit"
#pragma resource "*.dfm"


TAll_StatisticForm * All_StatisticForm;


int          col_pass;
Variant      ExcelApplication;
// AnsiString * mas_cause_pass;


// Button1Click
// DateTimePicker1Change
// DateTimePicker2Change
// FormClose
// next_group
// RadioGroup1Click



bool __fastcall TAll_StatisticForm::next_group (TDataSet *name_query,
    int nom_group) {
    name_query -> Next ();
    if (nom_group == name_query -> FieldByName ("INC_GROUP") -> Value)
        return false;
    else
        return true;
}

__fastcall TAll_StatisticForm::TAll_StatisticForm (TComponent* Owner)
    : TForm (Owner) {
}

void __fastcall TAll_StatisticForm::FormClose (TObject *Sender,
    TCloseAction &Action) {
    Action = caFree;
}

void __fastcall TAll_StatisticForm::Button1Click (TObject *Sender)
{ // кнопка ПОКАЗАТЬ РЕЗУЛЬТАТ

    // проверки
    if (RadioGroup1 -> ItemIndex == -1) {
        ShowMessage ("Укажите период показа пропусков!");
        return;
    }

    if (!RadioGroup1 -> ItemIndex && (MaskEdit1 -> Text == "  " ||
        ComboBox1 -> Text == "")) {
        ShowMessage ("Введите все данные"); // Проверка ввода даты периода
        return;
    }

    // end проверки

    AnsiString *mas_cause;
    int *mas_cause_st;

    try {
        ExcelApplication = Variant::CreateObject ("Excel.Application");
        // Variant Workbook=OpenBook (ExcelApplication, "C:\\Program Files\\Bgafk\\Dekanat\\1\\Статистика.xls");
        Variant Workbook = NewBook (ExcelApplication);
        ColWorkSheet (ExcelApplication, 1);
        OVisible (ExcelApplication);
        // -----------------------------------------------------------

        AnsiString facultet = DM2 -> FacultyFDTable -> Lookup ("N_FAC",
            nom_fac, "FAC");
        AnsiString period = "";
        if (RadioGroup1 -> ItemIndex)
            period = " период c " + DateToStr (DateTimePicker1 -> Date) + " по " +
                DateToStr (DateTimePicker2 -> Date);
        else
            period = ComboBox1 -> Text + " 20" + MaskEdit1 -> Text + " года";

        // Общая статистика пропусков по факультету (begin)
        Variant Sheet = NewSheet1 (ExcelApplication);
        NameSheet1 (Sheet, "По факультету");
        Sheet = SelectSheet (Workbook, "По факультету");

        // --- шапка таблицы
        CellValue ("Курс", 1, 6);
        BorderCell (1, 6, 1, 2);
        CellValue ("Кол-во студентов на курсе", 2, 6);
        BorderCell (2, 6, 1, 2);
        CellValue ("Общее кол-во пропущенных часов", 3, 6);
        BorderCell (3, 6, 1, 2);
        CellValue ("1", 1, 7);
        BorderCell (1, 7, 1, 2);
        CellValue ("2", 1, 8);
        BorderCell (1, 8, 1, 2);
        CellValue ("3", 1, 9);
        BorderCell (1, 9, 1, 2);
        CellValue ("4", 1, 10);
        BorderCell (1, 10, 1, 2);
        CellValue ("5", 1, 11);
        BorderCell (1, 11, 1, 2);
        CellValue ("Итого:", 1, 12);
        BorderCell (1, 12, 1, 2);
        CellFormula ("=СУММ (B7:B11)", 2, 12);
        BorderCell (2, 12, 1, 2);
        CellFormula ("=СУММ (C7:C11)", 3, 12);
        BorderCell (3, 12, 1, 2);
        Variant Range = Range2 (ExcelApplication, "A6:K6");
        W1 (Range);
        HorizontalAlign (Range, 3);
        VerticalAlign (Range, 2);
        // ----
        CellValue (facultet, 1, 2);
        CellValue ("Статистика пропусков по факультету за " + period, 1, 4);
        Range = Range2 (ExcelApplication, "A4:I4");
        M1 (Range);
        CellFont ("Arial", 10, true, false, 2, 0, Range);
        Range = Range2 (ExcelApplication, "A2:I2");
        M1 (Range);
        CellFont ("Arial", 12, true, false, 2, 0, Range);

        // Формирование массива для причин пропусков и занесения их в Excel
        // уже не надо DM2 -> Cause_PassTable -> Last ();
        int col_cause = DM2 -> Cause_PassFDTable -> RecordCount;
        DM2 -> Cause_PassFDTable -> First ();

        mas_cause = new AnsiString[col_cause];
        mas_cause_st = new int[col_cause];
        int st_cause = 4; // переменная для занесения причин через столбец

        for (int i = 0; i < col_cause; i++) {
            mas_cause[i] = DM2 -> Cause_PassFDTableCAUSE -> Value;
            mas_cause_st[i] = st_cause;
            st_cause += 2;

            DM2 -> Cause_PassFDTable -> Next ();
            CellValue (mas_cause[i], i + 4, 6);
            BorderCell (i + 4, 6, 1, 2);

            AnsiString stroka = "=СУММ (" + mas_column[i + 3] + "7:" +
                mas_column[i + 3] + "11)";

            CellFormula (stroka, 4 + i, 12);
            BorderCell (4 + i, 12, 1, 2);

        }

        int k = 7;
        DataModule1 -> Count_People_KursFDQuery -> Close ();
        DataModule1 -> Count_People_KursFDQuery -> Params -> ParamValues["N_FAC"] =
            nom_fac;
        DataModule1 -> Count_People_KursFDQuery -> Open ();
        for (int i = 1; i <= 5; i++) {
            int kurs = DataModule1 -> Count_People_KursFDQueryKURS -> Value;
            if (kurs == i) {
                CellValue (DataModule1 -> Count_People_KursFDQueryCOUNT -> 
                    Value, 2, k);
                BorderCell (2, k, 1, 2);
                DataModule1 -> Count_People_KursFDQuery -> Next ();
            }
            else {
                CellValue (0, 2, k);
                BorderCell (2, k, 1, 2);
            }
            k = k++;
        }
        k = 7;

        // Ввод периода
        AnsiString start, end;

        if (RadioGroup1 -> ItemIndex) { // if произвольный период
            start = DateToStr (DateTimePicker1 -> Date);
            end = DateToStr (DateTimePicker2 -> Date);
        } // end if произвольный период
        else { // else за  месяц
            int mon = ComboBox1 -> ItemIndex + 1;
            AnsiString mon_s;
            AnsiString year_s = MaskEdit1 -> Text;

            if (mon < 10)
                mon_s = "0" + AnsiString (mon);
            else
                mon_s = AnsiString (mon);

            start = "01." + mon_s + "." + year_s;

            if (mon + 1 < 10)
                mon_s = "0" + AnsiString (mon + 1);
            else if (mon == 12) {
                mon_s = "01";
                int year_int = year_s.ToInt ();
                year_int++;
                if (year_int < 10)
                    year_s = "0" + AnsiString (year_int);
                else
                    year_s = AnsiString (year_int);
            }
            else
                mon_s = AnsiString (mon + 1);
            end = "01." + mon_s + "." + year_s;
        } // end else за  месяц
        //

        DataModule1 -> Fac_AllFDQuery -> Close ();
        DataModule1 -> Fac_AllFDQuery -> Params -> ParamValues["START"] =
            StrToDate (start);
        DataModule1 -> Fac_AllFDQuery -> Params -> ParamValues["END"] =
            StrToDate (end);
        DataModule1 -> Fac_AllFDQuery -> Params -> ParamValues["N_FAC"] = nom_fac;
        DataModule1 -> Fac_AllFDQuery -> Open ();
        Variant locvalues[2];
        for (int i = 1; i <= 5; i++) {
            for (int j = 0; j < col_cause; j++) {
                locvalues[0] = i;
                locvalues[1] = mas_cause[j];
                Variant sum_hour = DataModule1 -> Fac_AllFDQuery -> Lookup
                    ("KURS;CAUSE", VarArrayOf (locvalues, 1), "SUM");
                if (!sum_hour.IsNull ())
                    CellValue (sum_hour, j + 4, k);
                else
                    CellValue (0, j + 4, k);
                BorderCell (j + 4, k, 1, 2);
            }
            AnsiString str = "=СУММ (D" + AnsiString (k) + ":" +
                mas_column[col_cause + 2] + AnsiString (k) + ")";
            CellFormula (str, 3, k);
            BorderCell (3, k, 1, 2);
            k = k++;
        }
        // Общая статистика пропусков по факультету (end)

        // ----------------------------------------------------------------

        // Общая статистика пропусков по курсу (begin)
        Sheet = NewSheet1 (ExcelApplication);
        NameSheet1 (Sheet, "По курсу");
        Sheet = SelectSheet (Workbook, "По курсу");

        // --- шапка таблицы
        CellValue ("Группа", 1, 7);
        BorderCell (1, 7, 1, 2);
        CellValue ("Кол-во студентов в группе", 2, 7);
        BorderCell (2, 7, 1, 2);
        CellValue ("Общее кол-во пропущенных часов", 3, 7);
        BorderCell (3, 7, 1, 2);

        Range = Range2 (ExcelApplication, "A7:O7");
        W1 (Range);
        HorizontalAlign (Range, 3);
        VerticalAlign (Range, 2);
        // ----
        CellValue (facultet, 1, 2);
        CellValue ("Статистика пропусков по курсу за " + period, 1, 4);
        Range = Range2 (ExcelApplication, "A4:O4");
        M1 (Range);
        CellFont ("Arial", 10, true, false, 2, 0, Range);
        Range = Range2 (ExcelApplication, "A2:O2");
        M1 (Range);
        CellFont ("Arial", 12, true, false, 2, 0, Range);

        for (int i = 0; i < col_cause; i++) {
            // CellValue (mas_cause[i],i+4,7); //Причины в Excel
            // BorderCell (i+4,7,1,2);
            CellValue (mas_cause[i], mas_cause_st[i], 7); // Причины в Excel
            BorderCell (mas_cause_st[i], 7, 1, 2);
            CellValue ("на 1 чел.", mas_cause_st[i] + 1, 7);
            BorderCell (mas_cause_st[i] + 1, 7, 1, 2);
        }

        DataModule1 -> Kurs_AllFDQuery -> Close ();
        DataModule1 -> Kurs_AllFDQuery -> Params -> ParamValues["START"] =
            StrToDate (start);
        DataModule1 -> Kurs_AllFDQuery -> Params -> ParamValues["END"] =
            StrToDate (end);
        DataModule1 -> Kurs_AllFDQuery -> Params -> ParamValues["N_FAC"] = nom_fac;
        DataModule1 -> Kurs_AllFDQuery -> Open ();

        DataModule1 -> Count_People_GroupFDQuery -> Close ();
        DataModule1 -> Count_People_GroupFDQuery -> ParamByName ("FAC") -> AsSmallInt =
            nom_fac;
        DataModule1 -> Count_People_GroupFDQuery -> Open ();

        AnsiString kurs =
            DataModule1 -> Count_People_GroupFDQueryN_GROUP -> Value.
            SubString (2, 1); // номер курса
        AnsiString n_gr = ""; // номер группы
        int str = 8; // номер строки для выброса
        int str_old = 8; // номер начальной строки для формирования суммы

        AnsiString vsego = "=СУММ (";

        for (int m = 0;
        m <= DataModule1 -> Count_People_GroupFDQuery -> RecordCount; m++) {
            if (kurs != DataModule1 -> Count_People_GroupFDQueryN_GROUP -> Value.
                SubString (2, 1) || DataModule1 -> Count_People_GroupFDQuery -> Eof)
            {
                CellValue ("Итого " + kurs + " курс:", 1, str);
                BorderCell (1, str, 1, 2);
                kurs = DataModule1 -> Count_People_GroupFDQueryN_GROUP -> Value.
                    SubString (2, 1);
                int k = 0; // для счетчика столбцов с процентами
                // for (int j=1; j<3+col_cause;j++)
                for (int j = 1; j < 3 + col_cause * 2; j++) {
                    AnsiString sum = "=СУММ (" + mas_column[j] +
                        AnsiString (str_old) + ":" + mas_column[j] +
                        AnsiString (str - 1) + ")";

                    if (j == mas_cause_st[k]) {
                        AnsiString procent =
                            "=" + mas_column[mas_cause_st[k] - 1] +
                            AnsiString (str) + "/$B" + AnsiString (str);
                        Variant Ce2 = SelectCell (j + 1, str);
                        SheetFormat (Ce2, "0,0");

                        CellFormula (procent, j + 1, str);
                        k++;
                    }
                    else
                        CellFormula (sum, j + 1, str);

                    BorderCell (j + 1, str, 1, 2);
                }
                vsego += "C" + AnsiString (str) + ";";

                str++;
                str_old = str;
                if (DataModule1 -> Count_People_GroupFDQuery -> Eof)
                    break;

            }

            Variant Ce1 = SelectCell (1, str);
            SheetFormat (Ce1, "@");
            n_gr = DataModule1 -> Count_People_GroupFDQueryN_GROUP -> Value;
            // номер группы
            CellValue (n_gr, 1, str); // номер группы
            CellValue (DataModule1 -> Count_People_GroupFDQueryCOUNT -> Value,
                2, str); // количество человек в группе
            AnsiString str1 = "=СУММ (";
            // "=СУММ (D"+AnsiString (str)+":"+mas_column[col_cause+2]+AnsiString (str)+")";
            for (int k = 0; k < col_cause; k++)
                str1 += mas_column[mas_cause_st[k] - 1] + AnsiString (str) + ";";

            str1 = str1.SubString (1, str1.Length () - 1) + ")";
            CellFormula (str1, 3, str); // формула суммирования
            // обрамление
            for (int n = 1; n <= 3 + col_cause * 2; n++)
                BorderCell (n, str, 1, 2);
            // -------------

            while (!DataModule1 -> Kurs_AllFDQuery -> Eof &&
                (n_gr == DataModule1 -> Kurs_AllFDQueryN_GROUP -> Value)) {
                // CellValue (DataModule1 -> Kurs_AllQuerySUM -> Value,DataModule1 -> Kurs_AllQueryN_CAUSE -> Value+3,str);
                CellValue (DataModule1 -> Kurs_AllFDQuerySUM -> Value,
                    mas_cause_st[DataModule1 -> Kurs_AllFDQueryN_CAUSE -> Value -
                    1], str);
                // процент
                AnsiString procent =
                    "=" + mas_column
                    [mas_cause_st[DataModule1 -> Kurs_AllFDQueryN_CAUSE -> Value -
                    1] - 1] + AnsiString (str) + "/$B" + AnsiString (str);
                Ce1 = SelectCell
                    (mas_cause_st[DataModule1 -> Kurs_AllFDQueryN_CAUSE -> Value -
                    1] + 1, str);
                SheetFormat (Ce1, "0,0");
                CellFormula (procent,
                    mas_cause_st[DataModule1 -> Kurs_AllFDQueryN_CAUSE -> Value -
                    1] + 1, str);
                DataModule1 -> Kurs_AllFDQuery -> Next ();
                st_cause++;
            }
            // -------------
            str++;
            DataModule1 -> Count_People_GroupFDQuery -> Next ();
        }

        AutoFitColumn (Sheet, 1);
        CellValue ("Всего:", 1, str);
        CellFormula (vsego.SubString (1, vsego.Length () - 1) + ")", 3, str);
        // формула суммирования
        DataModule1 -> Count_People_GroupFDQuery -> Close ();
        // Общая статистика пропусков по курсу (end)

        // ----------------------------------------------------------------
        if (!RadioGroup1 -> ItemIndex) { // if только за месяц
            // Общая статистика пропусков по группе (begin)
            Sheet = NewSheet1 (ExcelApplication);
            NameSheet1 (Sheet, "По группе");
            Sheet = SelectSheet (Workbook, "По группе");

            // --- шапка таблицы
            CellValue ("Группа", 1, 7);
            BorderCell (1, 7, 1, 2);
            CellValue ("Общее кол-во пропущенных часов", 2, 7);
            BorderCell (2, 7, 1, 2);

            Range = Range2 (ExcelApplication, "A7:K7");
            W1 (Range);
            HorizontalAlign (Range, 3);
            VerticalAlign (Range, 2);
            // ----
            CellValue (facultet, 1, 2);
            CellValue ("Статистика пропусков по группе за " + period, 1, 4);
            Range = Range2 (ExcelApplication, "A4:H4");
            M1 (Range);
            CellFont ("Arial", 10, true, false, 2, 0, Range);
            Range = Range2 (ExcelApplication, "A2:H2");
            M1 (Range);
            CellFont ("Arial", 12, true, false, 2, 0, Range);

            for (int i = 0; i < col_cause; i++) {
                CellValue (mas_cause[i], i + 3, 7); // Причины в Excel
                BorderCell (i + 3, 7, 1, 2);
            }

            DataModule1 -> Group_AllFDQuery -> Close ();
            DataModule1 -> Group_AllFDQuery -> Params -> ParamValues["START"] =
                StrToDate (start);
            DataModule1 -> Group_AllFDQuery -> Params -> ParamValues["END"] =
                StrToDate (end);
            DataModule1 -> Group_AllFDQuery -> Params -> ParamValues["N_FAC"] =
                nom_fac;
            DataModule1 -> Group_AllFDQuery -> Open ();

            int row = 8;
            int old_row = 8;
            Variant Ce2 = SelectCell (1, row);
            SheetFormat (Ce2, "@");
            CellValue (DM2 -> Increment_GroupFDTable -> Lookup ("INC_GROUP",
                DataModule1 -> Group_AllFDQueryINC_GROUP -> Value, "N_GROUP"),
                1, row);
            Range = Range2 (ExcelApplication, "A" + AnsiString (row) + ":" +
                mas_column[col_cause + 1] + AnsiString (row));
            M1 (Range);
            CellFont ("Arial", 10, true, false, 1, 0, Range);
            while (!DataModule1 -> Group_AllFDQuery -> Eof) {
                row++;
                AnsiString fam = DataModule1 -> Group_AllFDQueryFAM -> Value;
                AnsiString fio =
                    fam + " " + DataModule1 -> Group_AllFDQueryNAME -> Value + " " +
                    DataModule1 -> Group_AllFDQueryOTCH -> Value;
                CellValue (fio, 1, row);
                BorderCell (1, row, 1, 2);
                AnsiString str2 = "=СУММ (C" + AnsiString (row) + ":" +
                    mas_column[col_cause + 1] + AnsiString (row) + ")";
                CellFormula (str2, 2, row);
                BorderCell (2, row, 1, 2);

                for (int i = 0; i < col_cause; i++) {
                    if (DataModule1 -> Group_AllFDQueryCAUSE -> Value ==
                        mas_cause[i]) {
                        CellValue (DataModule1 -> Group_AllFDQuerySUM -> Value,
                            i + 3, row);
                        BorderCell (i + 3, row, 1, 2);
                        if (!next_group (DataModule1 -> Group_AllFDQuery,
                            DataModule1 -> Group_AllFDQueryINC_GROUP -> Value)) {
                            if (fam != DataModule1 -> Group_AllFDQueryFAM -> Value)
                            {
                                if (i < col_cause - 1) {
                                    for (int k = i + 1; k < col_cause; k++) {
                                        CellValue (0, k + 3, row);
                                        BorderCell (k + 3, row, 1, 2);
                                    } // for k
                                }
                                break;
                            }
                        }
                        else // next_group ()=true
                        {
                            if (i < col_cause - 1) {
                                for (int k = i + 1; k < col_cause; k++) {
                                    CellValue (0, k + 3, row);
                                    BorderCell (k + 3, row, 1, 2);
                                } // for k
                            }
                            row++;

                            CellValue ("Итого по группе", 1, row);
                            BorderCell (1, row, 1, 2);
                            for (int j = 1; j < 2 + col_cause; j++) {
                                AnsiString sum =
                                    "=СУММ (" + mas_column[j] +
                                    AnsiString (old_row + 1) + ":" +
                                    mas_column[j] + AnsiString (row - 1) + ")";
                                CellFormula (sum, j + 1, row);
                                BorderCell (j + 1, row, 1, 2);
                            }
                            row++;
                            old_row = row;
                            Ce2 = SelectCell (1, row);
                            SheetFormat (Ce2, "@");
                            CellValue (DM2 -> Increment_GroupFDTable -> Lookup
                                ("INC_GROUP",
                                DataModule1 -> Group_AllFDQueryINC_GROUP -> Value,
                                "N_GROUP"), 1, row);
                            Range = Range2 (ExcelApplication,
                                "A" + AnsiString (row) + ":" +
                                mas_column[col_cause + 1] + AnsiString (row));
                            M1 (Range);
                            CellFont ("Arial", 10, true, false, 1, 0, Range);
                            break;
                        }
                    }
                    else // QueryCause!=mas_cause
                            CellValue (0, i + 3, row);
                    BorderCell (i + 3, row, 1, 2);
                } // for i
            } // while

            row++;
            CellValue ("Итого по группе", 1, row);
            BorderCell (1, row, 1, 2);
            for (int j = 1; j < 2 + col_cause; j++) {
                AnsiString sum = "=СУММ (" + mas_column[j] + AnsiString (old_row)
                    + ":" + mas_column[j] + AnsiString (row - 1) + ")";
                CellFormula (sum, j + 1, row);
                BorderCell (j + 1, row, 1, 2);
            }

            AutoFitColumn (Sheet, 1);
            // Общая статистика пропусков по группе (end)
        } // end if только за месяц
        // ----------------------------------------------------------------

        AnsiString name_f = "Статистика пропусков по факультету за " +
            period + ".xls";
        Variant WorkSaveAs =
            SaveBookAs (Workbook, "d:\\Мои документы\\" + name_f);

        delete[]mas_cause;
        delete[]mas_cause_st;
        ExcelApplication.Clear ();

    } // end try
    catch (...) { // catch
        delete[]mas_cause;
        delete[]mas_cause_st;
        ExcelApplication.Clear ();
        ShowMessage ("Произошел сбой при формировании!");
    } // end catch
}

void __fastcall TAll_StatisticForm::RadioGroup1Click (TObject *Sender) {
    Panel2 -> Visible = true;

    switch (RadioGroup1 -> ItemIndex) {
    case 0: // Месяц
        Panel4 -> Visible = true;
        Panel5 -> Visible = false;
        ComboBox1 -> ItemIndex = -1;
        MaskEdit1 -> Text = "  ";
        break;

    case 1: // Произвольный
        Panel4 -> Visible = false;
        Panel5 -> Visible = true;
        DateTimePicker1 -> Date = Now () - 30;
        DateTimePicker1 -> Time = StrToTime ("00:00");
        DateTimePicker2 -> Date = Now ();
        DateTimePicker2 -> Time = StrToTime ("00:00");
        break;
    }

    All_StatisticForm -> Height = 214;
}
void __fastcall TAll_StatisticForm::DateTimePicker1Change (TObject *Sender)
{
DateTimePicker1 -> Time = StrToTime ("00:00");
}

void __fastcall TAll_StatisticForm::DateTimePicker2Change (TObject *Sender)
{
DateTimePicker2 -> Time = StrToTime ("00:00");
}


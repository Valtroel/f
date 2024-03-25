#include <vcl.h>
#pragma hdrstop


#include "DataModule.h"
#include "DM2Unit.h"
#include "Func.h"
#include "Semestr_SessionUnit.h"
#include "Svod_VedUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TSemestr_sessionForm * Semestr_sessionForm;


AnsiString * text_mass;                 // массив для занесения текстовых значений столбцов по системам

int          col2_zagolovok,                     // второй столбец для определения выделения в шапке (из-за 2-х систем)
             kol_text_mass,             // кол-во элементов в массиве text_mass (возможно 5 для пятибальной и 8 для десятибальной системы)
             razm_mas,                           // размер массива в зависимости от вида обучения
             uch_god_main, // учебный год, который занесли пользователи
             v_ed;                               // 0 - дневное, 1 - заочное

int        * n_sem; // массив номеров семестров в зависимости от сессии и вида обучения

Variant      ExAppl,
             WorBook,
             WorSheet;

AnsiString Sql_count_object = "                                     \
    SELECT                                                          \
        Object_plan.NAME_OBJECT,                                    \
        Edu_plan.ZACH_EXAM,                                         \
        Object_plan.N_OBJECT                                        \
    FROM                                                            \
        EDU_PLAN Edu_plan                                           \
            INNER JOIN                                              \
                OBJECT_PLAN Object_plan                             \
                    ON                                              \
                        (Edu_plan.N_OBJECT = Object_plan.N_OBJECT)  \
    WHERE                                                           \
            SEMESTR            =  :SEMESTR                          \
        AND                                                         \
            VID_EDU_PLAN       =  :VID_EDU                          \
        AND                                                         \
            N_FAC              =  :FAC                              \
        AND                                                         \
            Edu_Plan.YEAR_PLAN =  :PLAN                             \
        AND                                                         \
            ZACH_EXAM          <> 4                                 \
    ORDER BY                                                        \
        Object_plan.NAME_OBJECT                                     \
    ";



__fastcall TSemestr_sessionForm::TSemestr_sessionForm (TComponent * Owner)
    : TForm (Owner)
{ }




// BitBtn1Click
// BitBtn2Click
// Create_text_mass
// FormClose
// FormCreate
// Itogo_summ
// MaskEdit1Exit
// mass_sem
// Shapka_Tabl
// System_five
// System_ten




void __fastcall TSemestr_sessionForm::Itogo_summ (int n_r, int rec_gr)
{ // Процедура вынесения в Excel строчки ИТОГО по группам в зависимости от системы оценок
    // сумма по столбцам Кол-во студентов в группе, и явка на экзамен
    CellValue ("  ИТОГО:", 1, n_r);
    BorderCell (1, n_r, 1, 2);
    BorderCell (2, n_r, 1, 2);
    CellFormula ("=СУММ (C" + AnsiString (n_r - rec_gr) + ":C" +
        AnsiString (n_r - 1) + ")", 3, n_r);
    BorderCell (3, n_r, 1, 2);
    CellFormula ("=СУММ (D" + AnsiString (n_r - rec_gr) + ":D" +
        AnsiString (n_r - 1) + ")", 4, n_r);
    BorderCell (4, n_r, 1, 2);

    // занесение первых пяти столбцов

    // столбец: отл. (5) или Десять (10)
    CellFormula ("=СУММ (E" + AnsiString (n_r - rec_gr) + ":E" +
        AnsiString (n_r - 1) + ")", 5, n_r);
    BorderCell (5, n_r, 1, 2);
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "E" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 6, n_r);
    BorderCell (6, n_r, 1, 2);
    Variant Ce1 = SelectCell (6, n_r);
    SheetFormat (Ce1, "0,0");
    // столбец: хор. (5) или Девять (10)
    CellFormula ("=СУММ (G" + AnsiString (n_r - rec_gr) + ":G" +
        AnsiString (n_r - 1) + ")", 7, n_r);
    BorderCell (7, n_r, 1, 2);
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "G" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 8, n_r);
    BorderCell (8, n_r, 1, 2);
    Ce1 = SelectCell (8, n_r);
    SheetFormat (Ce1, "0,0");
    // столбец: удовл. (5) или Восемь (10)
    CellFormula ("=СУММ (I" + AnsiString (n_r - rec_gr) + ":I" +
        AnsiString (n_r - 1) + ")", 9, n_r);
    BorderCell (9, n_r, 1, 2);
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "I" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 10, n_r);
    BorderCell (10, n_r, 1, 2);
    Ce1 = SelectCell (10, n_r);
    SheetFormat (Ce1, "0,0");
    // столбец: неуд. (5) или Семь (10)
    CellFormula ("=СУММ (K" + AnsiString (n_r - rec_gr) + ":K" +
        AnsiString (n_r - 1) + ")", 11, n_r);
    BorderCell (11, n_r, 1, 2);
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "K" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 12, n_r);
    BorderCell (12, n_r, 1, 2);
    Ce1 = SelectCell (12, n_r);
    SheetFormat (Ce1, "0,0");
    // столбец: отл. и хор. (5) или Шесть (10)
    CellFormula ("=СУММ (M" + AnsiString (n_r - rec_gr) + ":M" +
        AnsiString (n_r - 1) + ")", 13, n_r);
    BorderCell (13, n_r, 1, 2);
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "M" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 14, n_r);
    BorderCell (14, n_r, 1, 2);
    Ce1 = SelectCell (14, n_r);
    SheetFormat (Ce1, "0,0");

    if (syst_ball == 5) { // if пятибальная система
        // столбец: ср. балл (5)
        CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + " (E" + AnsiString (n_r)
            + "*5+G" + AnsiString (n_r) + "*4+I" + AnsiString (n_r) + "*3)/D" +
            AnsiString (n_r) + ";0)", 15, n_r);
        BorderCell (15, n_r, 1, 2);
        Ce1 = SelectCell (15, n_r);
        SheetFormat (Ce1, "0,0");
    } // end if пятибальная система
    else { // else  десятибальная система
        // столбец: Пять (10)
        CellFormula ("=СУММ (O" + AnsiString (n_r - rec_gr) + ":O" +
            AnsiString (n_r - 1) + ")", 15, n_r);
        BorderCell (15, n_r, 1, 2);
        CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "O" + AnsiString (n_r)
            + "/D" + AnsiString (n_r) + "*100" + ";0)", 16, n_r);
        BorderCell (16, n_r, 1, 2);
        Ce1 = SelectCell (16, n_r);
        SheetFormat (Ce1, "0,0");
        // столбец: Четыре (10)
        CellFormula ("=СУММ (Q" + AnsiString (n_r - rec_gr) + ":Q" +
            AnsiString (n_r - 1) + ")", 17, n_r);
        BorderCell (17, n_r, 1, 2);
        CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "Q" + AnsiString (n_r)
            + "/D" + AnsiString (n_r) + "*100" + ";0)", 18, n_r);
        BorderCell (18, n_r, 1, 2);
        Ce1 = SelectCell (18, n_r);
        SheetFormat (Ce1, "0,0");
        // столбец: Не сдано (10)
        CellFormula ("=СУММ (S" + AnsiString (n_r - rec_gr) + ":S" +
            AnsiString (n_r - 1) + ")", 19, n_r);
        BorderCell (19, n_r, 1, 2);
        CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "S" + AnsiString (n_r)
            + "/D" + AnsiString (n_r) + "*100" + ";0)", 20, n_r);
        BorderCell (20, n_r, 1, 2);
        Ce1 = SelectCell (20, n_r);
        SheetFormat (Ce1, "0,0");
        // столбец: ср. балл (10)
        CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + " (E" + AnsiString (n_r)
            + "*10+G" + AnsiString (n_r) + "*9+I" + AnsiString (n_r) + "*8+K" +
            AnsiString (n_r) + "*7+M" + AnsiString (n_r) + "*6+O" +
            AnsiString (n_r) + "*5+Q" + AnsiString (n_r) + "*4)/D" +
            AnsiString (n_r) + ";0)", 21, n_r);
        BorderCell (21, n_r, 1, 2);
        Ce1 = SelectCell (21, n_r);
        SheetFormat (Ce1, "0,0");
    } // end else  десятибальная система
}


void __fastcall TSemestr_sessionForm::System_five (int n_r)
{ // Процедура пересмотра оценок для пятибальной системы

    int otl = 0, hor = 0, ud = 0, neud = 0;
    for (int i = 0; i < DataModule1 -> Semestr_Kurs_NewFDQuery -> RecordCount; i++)
    {
        switch (ball_int (5, DataModule1 -> Semestr_Kurs_NewFDQueryBALL -> Value)) {

        case 5:
            otl += DataModule1 -> Semestr_Kurs_NewFDQueryCOUNT -> Value;
            break;
        case 4:
            hor += DataModule1 -> Semestr_Kurs_NewFDQueryCOUNT -> Value;
            break;
        case 3:
            ud += DataModule1 -> Semestr_Kurs_NewFDQueryCOUNT -> Value;
            break;
        case 2:
            neud += DataModule1 -> Semestr_Kurs_NewFDQueryCOUNT -> Value;
            break;
        }

        DataModule1 -> Semestr_Kurs_NewFDQuery -> Next ();
    }
    // -----------------------------занесение формул в Excel по оценке и по проценту
    Variant Ce1;
    // ---пять
    CellValue (AnsiString (otl), 5, n_r);
    BorderCell (5, n_r, 1, 2);
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "E" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 6, n_r);
    BorderCell (6, n_r, 1, 2);
    Ce1 = SelectCell (6, n_r);
    SheetFormat (Ce1, "0,0");
    // ---четыре
    CellValue (AnsiString (hor), 7, n_r);
    BorderCell (7, n_r, 1, 2);
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "G" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 8, n_r);
    BorderCell (8, n_r, 1, 2);
    Ce1 = SelectCell (8, n_r);
    SheetFormat (Ce1, "0,0");
    // ---три
    CellValue (AnsiString (ud), 9, n_r);
    BorderCell (9, n_r, 1, 2);
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "I" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 10, n_r);
    BorderCell (10, n_r, 1, 2);
    Ce1 = SelectCell (10, n_r);
    SheetFormat (Ce1, "0,0");
    // ---два
    CellValue (AnsiString (neud), 11, n_r);
    BorderCell (11, n_r, 1, 2);
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "K" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 12, n_r);
    BorderCell (12, n_r, 1, 2);
    Ce1 = SelectCell (12, n_r);
    SheetFormat (Ce1, "0,0");
    // ---пять + четыре
    CellFormula ("=СУММ (E" + AnsiString (n_r) + ";G" + AnsiString (n_r) + ")",
        13, n_r);
    BorderCell (13, n_r, 1, 2);
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "M" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 14, n_r);
    BorderCell (14, n_r, 1, 2);
    Ce1 = SelectCell (14, n_r);
    SheetFormat (Ce1, "0,0");
    // ---средний балл по предмету
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + " (E" + AnsiString (n_r) +
        "*5+G" + AnsiString (n_r) + "*4+I" + AnsiString (n_r) + "*3)/D" +
        AnsiString (n_r) + ";0)", 15, n_r);
    BorderCell (15, n_r, 1, 2);
    Ce1 = SelectCell (15, n_r);
    SheetFormat (Ce1, "0,0");
}


void __fastcall TSemestr_sessionForm::System_ten (int n_r)
{ // Процедура пересмотра оценок для десятибальной системы
    // ten=10,nine=9,eight=8,seven=7,six=6,five=5,four=4,
    // neud=3,2,1 (three, two, one)
    int ten = 0, nine = 0, eight = 0, seven = 0, six = 0, five = 0, four = 0,
        neud = 0;
    for (int i = 0; i < DataModule1 -> Semestr_Kurs_NewFDQuery -> RecordCount; i++)
    {
        switch (ball_int (10, DataModule1 -> Semestr_Kurs_NewFDQueryBALL -> Value)) {
        case 11:
            neud += DataModule1 -> Semestr_Kurs_NewFDQueryCOUNT -> Value;
            break;
        case 12:
            neud += DataModule1 -> Semestr_Kurs_NewFDQueryCOUNT -> Value;
            break;
        case 13:
            neud += DataModule1 -> Semestr_Kurs_NewFDQueryCOUNT -> Value;
            break;
        case 14:
            four += DataModule1 -> Semestr_Kurs_NewFDQueryCOUNT -> Value;
            break;
        case 15:
            five += DataModule1 -> Semestr_Kurs_NewFDQueryCOUNT -> Value;
            break;
        case 16:
            six += DataModule1 -> Semestr_Kurs_NewFDQueryCOUNT -> Value;
            break;
        case 17:
            seven += DataModule1 -> Semestr_Kurs_NewFDQueryCOUNT -> Value;
            break;
        case 18:
            eight += DataModule1 -> Semestr_Kurs_NewFDQueryCOUNT -> Value;
            break;
        case 19:
            nine += DataModule1 -> Semestr_Kurs_NewFDQueryCOUNT -> Value;
            break;
        case 20:
            ten += DataModule1 -> Semestr_Kurs_NewFDQueryCOUNT -> Value;
            break;

        }

        DataModule1 -> Semestr_Kurs_NewFDQuery -> Next ();
    }

    // -----------------------------занесение формул в Excel по оценке и по проценту
    Variant Ce1;
    // ---десять
    CellValue (AnsiString (ten), 5, n_r);
    BorderCell (5, n_r, 1, 2);
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "E" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 6, n_r);
    BorderCell (6, n_r, 1, 2);
    Ce1 = SelectCell (6, n_r);
    SheetFormat (Ce1, "0,0");
    // ---девять
    CellValue (AnsiString (nine), 7, n_r);
    BorderCell (7, n_r, 1, 2);
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "G" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 8, n_r);
    BorderCell (8, n_r, 1, 2);
    Ce1 = SelectCell (8, n_r);
    SheetFormat (Ce1, "0,0");
    // ---восемь
    CellValue (AnsiString (eight), 9, n_r);
    BorderCell (9, n_r, 1, 2);
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "I" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 10, n_r);
    BorderCell (10, n_r, 1, 2);
    Ce1 = SelectCell (10, n_r);
    SheetFormat (Ce1, "0,0");
    // ---семь
    CellValue (AnsiString (seven), 11, n_r);
    BorderCell (11, n_r, 1, 2);
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "K" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 12, n_r);
    BorderCell (12, n_r, 1, 2);
    Ce1 = SelectCell (12, n_r);
    SheetFormat (Ce1, "0,0");
    // ---шесть
    CellValue (AnsiString (six), 13, n_r);
    BorderCell (13, n_r, 1, 2);
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "M" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 14, n_r);
    BorderCell (14, n_r, 1, 2);
    Ce1 = SelectCell (14, n_r);
    SheetFormat (Ce1, "0,0");
    // ---пять
    CellValue (AnsiString (five), 15, n_r);
    BorderCell (15, n_r, 1, 2);
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "O" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 16, n_r);
    BorderCell (16, n_r, 1, 2);
    Ce1 = SelectCell (16, n_r);
    SheetFormat (Ce1, "0,0");
    // ---четыре
    CellValue (AnsiString (four), 17, n_r);
    BorderCell (17, n_r, 1, 2);
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "Q" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 18, n_r);
    BorderCell (18, n_r, 1, 2);
    Ce1 = SelectCell (18, n_r);
    SheetFormat (Ce1, "0,0");
    // ---три+два+один
    CellValue (AnsiString (neud), 19, n_r);
    BorderCell (19, n_r, 1, 2);
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + "S" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 20, n_r);
    BorderCell (20, n_r, 1, 2);
    Ce1 = SelectCell (20, n_r);
    SheetFormat (Ce1, "0,0");
    // ---средний балл по предмету
    CellFormula ("=ЕСЛИ (D" + AnsiString (n_r) + ">0;" + " (E" + AnsiString (n_r) +
        "*10+G" + AnsiString (n_r) + "*9+I" + AnsiString (n_r) + "*8+K" +
        AnsiString (n_r) + "*7+M" + AnsiString (n_r) + "*6+O" + AnsiString (n_r) +
        "*5+Q" + AnsiString (n_r) + "*4)/D" + AnsiString (n_r) + ";0)", 21, n_r);
    BorderCell (21, n_r, 1, 2);
    Ce1 = SelectCell (21, n_r);
    SheetFormat (Ce1, "0,0");

}


void __fastcall TSemestr_sessionForm::Create_text_mass ()
{ // процедура создания массива текстовых столбцов в статистике
    int col1 = 5; // c какого столбца начинать проставлять
    if (syst_ball == 5) { // if пятибальная система
        kol_text_mass = 5;
        // размер массива
        text_mass = new AnsiString[kol_text_mass];
        text_mass[0] = "отл.";
        text_mass[1] = "хор.";
        text_mass[2] = "удовл.";
        text_mass[3] = "неуд.";
        text_mass[4] = "отл. и хор.";
    } // end if пятибальная система
    else { // else десятибальная система
        kol_text_mass = 8;
        text_mass = new AnsiString[kol_text_mass];
        text_mass[0] = "Десять";
        text_mass[1] = "Девять";
        text_mass[2] = "Восемь";
        text_mass[3] = "Семь";
        text_mass[4] = "Шесть";
        text_mass[5] = "Пять";
        text_mass[6] = "Четыре";
        text_mass[7] = "Не сдано";
    } // end else десятибальная система

    // занесение в ячейке Excel значений из массива
    for (int i = 0; i < kol_text_mass; i++) { // for
        Cell_2_Text (WorSheet, col1, (col1 + 1), 5, true, "Arial", 10, true, 3,
            2, true, false, text_mass[i]);
        // кол-во
        Coll_2_Text (WorSheet, col1, 6, 6, true, "Arial", 10, true, 3, 2, 90,
            false, false, "кол-во");
        // ячейка %
        Coll_2_Text (WorSheet, (col1 + 1), 6, 6, true, "Arial", 10, true, 3, 2,
            0, false, false, "%");

        col1 += 2;
    } // end for

    // Средний балл
    Coll_2_Text (WorSheet, col1, 5, 6, true, "Arial", 10, true, 3, 2, 90, true,
        false, "Ср. балл");

}


void __fastcall TSemestr_sessionForm::mass_sem (int vid_edu, int ses_edu)
{ // процедура создния массива по семестрам

    if (ses_edu != 3)
    { // if формирование с учетом сессии (летней или зимней, 1 или 0)
        if (!vid_edu) { // if дневное обучение
            razm_mas = 4;
            n_sem = new int[razm_mas];
            for (int i = 0; i < razm_mas; i++) { // for
                if (!ses_edu)
                    n_sem[i] = i * 2 + 1;
                else
                    n_sem[i] = i * 2 + 2;
            } // end for
        } // end if дневное обучение
        else { // else заочное обучение
            razm_mas = 5;
            n_sem = new int[razm_mas];
            for (int i = 0; i < razm_mas; i++) { // for
                if (!ses_edu)
                    n_sem[i] = i * 2 + 1;
                else
                    n_sem[i] = i * 2 + 2;
            } // end for
        } // end else заочное обучение
    } // end if формирование с учетом сессии (летней или зимней, 1 или 0)
    else { // else это формировние массива за весь год для обоих сессий
        if (!vid_edu) { // if дневное обучение
            razm_mas = 4;
        } // end if дневное обучение
        else { // else заочное обучение
            razm_mas = 5;
        } // end else заочное обучение

        n_sem = new int[razm_mas * 2];
        for (int i = 0; i < razm_mas * 2; i++) { // for
            n_sem[i] = i + 1;
        } // end for
    } // end else это формировние массива за весь год для обоих сессий

}


void __fastcall TSemestr_sessionForm::Shapka_Tabl ()
{ // процедура формирования шапки таблицы, т.к. она не изменяется в двух статистиках

    // --------------------------- образец
    // Cell_2_Text (Variant WorSheet,int col1, int col2, int st, bool Border, AnsiString Shrift, int kegl, bool Bold,
    // int AlignH, int AlignV, bool M_1, bool W_1, AnsiString TextCell);

    // --------------------------- образец
    // Coll_2_Text (Variant WorSheet,int col1, int st1, int st2, bool Border, AnsiString Shrift, int kegl, bool Bold,
    // int AlignH, int AlignV, int Orient, bool M_1, bool W_1, AnsiString TextCell);
    // ---------------------------

    if (syst_ball == 5) // пятибальная система
            col2_zagolovok = 15; // диапазон "A1:O1"
    else
        col2_zagolovok = 21; // диапазон "A1:U1" для десятибальной системы

    // 1-ая строка - учебный год
    Cell_2_Text (WorSheet, 1, col2_zagolovok, 1, false, "Arial", 11, true, 3, 0,
        true, false, AnsiString (uch_god_main) + "/" +
        AnsiString (uch_god_main + 1) + " учебный год");

    // Наименование дисциплины
    Coll_2_Text (WorSheet, 1, 5, 6, true, "Arial", 10, true, 3, 2, 0, true,
        false, "Наименование дисциплины");

    // № группы
    Coll_2_Text (WorSheet, 2, 5, 6, true, "Arial", 10, true, 3, 2, 90, true,
        false, "№ группы");

    // Кол-во студентов
    Coll_2_Text (WorSheet, 3, 5, 6, true, "Arial", 10, true, 3, 2, 90, true,
        true, "Кол-во студентов");

    // Явка на экзамен
    Coll_2_Text (WorSheet, 4, 5, 6, true, "Arial", 10, true, 3, 2, 90, true,
        true, "Явка на экзамен");

    // Установка альбомной ориентации листа
    SetOrientatSheet (WorSheet, 2);

    // Установка ширины столбцов в диапазоне с B по U
    ColumnWidth (Range2 (WorSheet, "B:U"), 5);

    // Установка высоты строки в заголовке таблицы  5 и 6
    HeightRow (Range2 (WorSheet, "5:5"), 20);
    HeightRow (Range2 (WorSheet, "6:6"), 45);
}


void __fastcall TSemestr_sessionForm::FormClose (TObject *Sender,
    TCloseAction &Action) {
    delete[]n_sem;
    delete[]text_mass;
    caFree;
}


void __fastcall TSemestr_sessionForm::BitBtn1Click (TObject *Sender)
{ // действие по кнопке РЕЗУЛЬТАТЫ ПО СЕМЕСТРУ
    // ----определение системы выдачи оценки (пятибальная или десятибальная)
    // !!!if (Application -> MessageBox ("Учебная карточка будет показана в десятибальной системе?", "Выбор системы оценок", MB_YESNO) == mrYes)
    if (MessageDlg ("Учебная карточка будет показана в десятибальной системе?",
        mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
    { // if в десятибальной системе
        syst_ball = 10;
    } // end if в десятибальной системе
    else { // else  в пятибальной системе
        syst_ball = 5;
    } // end else  в пятибальной системе

    uch_god_main = StrToInt (MaskEdit1 -> Text);

    if (ComboBox1 -> ItemIndex == -1 && ComboBox2 -> ItemIndex == -1)
    { // if проверка на ввод значений в вид обучения и сессию

        ShowMessage ("Введите все данные по виду обучения и сессии!");
        return;
    } // end if проверка на ввод значений в вид обучения и сессию

    AnsiString sem_text = "", v_ed_text = "";
    // переменные для текстового формирования вида обучения и сесии

    ExAppl = Variant::CreateObject ("Excel.Application");
    ColWorkSheet (ExAppl, (Variant)1);
    WorBook = NewBook (ExAppl);
    OVisible (ExAppl);
    v_ed = ComboBox1 -> ItemIndex; // 0-дневное, 1-заочное
    int ses = ComboBox2 -> ItemIndex; // 0- зимняя сессия, 1- летняя
    if (ses)
        sem_text = "летней";
    else
        sem_text = "зимней";
    if (v_ed)
        v_ed_text = "заочного";
    else
        v_ed_text = "дневного";

    // --определяем размер массива сессий   через процедуру
    mass_sem (v_ed, ses);

    // Формирование в Excel
    for (int i = 0; i < razm_mas; i++) { // for1 цикл по семестрам
        WorSheet = NewSheet1 (ExAppl);
        NameSheet1 (WorSheet, AnsiString (n_sem[i]) + " семестр");
        SelectSheet (WorBook, AnsiString (n_sem[i]) + " семестр");

        // шапка  таблицы формируется в процедуре
        Shapka_Tabl ();

        // 2-ая строка - Результаты сдачи
        Cell_2_Text (WorSheet, 1, col2_zagolovok, 2, false, "Arial", 11, false,
            3, 0, true, false, "Результаты сдачи " + sem_text +
            " экзаменационной сессии");

        // 3-я строка - студенты и факультет
        Cell_2_Text (WorSheet, 1, col2_zagolovok, 3, false, "Arial", 11, false,
            3, 0, true, false, "студентами " + AnsiString (i + 1) + " курса " +
            v_ed_text + " отделения факультета " + DM2 -> FacultyFDTable -> Lookup
            ("N_FAC", nom_fac, "FAC1"));

        // процедура занесение столбцов в зависимости от системы оценки
        Create_text_mass ();

        // -------
        int n_r = 7; // начальная строка для занесения

        // Занесение данных
        DataModule1 -> Count_ObjectFDQuery -> Close ();
        DataModule1 -> Count_ObjectFDQuery -> SQL -> Clear ();
        DataModule1 -> Count_ObjectFDQuery -> SQL -> Add (Sql_count_object);
        DataModule1 -> Count_ObjectFDQuery -> ParamByName ("SEMESTR") -> Value =
            n_sem[i];
        DataModule1 -> Count_ObjectFDQuery -> ParamByName ("VID_EDU") -> Value = v_ed;
        DataModule1 -> Count_ObjectFDQuery -> ParamByName ("FAC") -> Value = nom_fac;
        DataModule1 -> Count_ObjectFDQuery -> ParamByName ("PLAN") -> Value =
            uch_god_main;
        DataModule1 -> Count_ObjectFDQuery -> Open ();

        int rec_obj = DataModule1 -> Count_ObjectFDQuery -> RecordCount;
        int n_obj;
        AnsiString name_obj = ""; // Название предмета

        for (int o = 0; o < rec_obj; o++) { // for 2 цикл по предметам
            if ( (DataModule1 -> Count_ObjectFDQueryZACH_EXAM -> Value == 2) ||
                (DataModule1 -> Count_ObjectFDQueryZACH_EXAM -> Value == 3))
            { // if если экзамен  и диф.зачет
                n_obj = DataModule1 -> Count_ObjectFDQueryN_OBJECT -> Value;
                name_obj = DataModule1 -> Count_ObjectFDQueryNAME_OBJECT -> Value;
                CellValue (name_obj, 1, n_r);
                BorderCell (1, n_r, 1, 2);
                DataModule1 -> Inc_Group_SemestrFDQuery -> Close ();
                DataModule1 -> Inc_Group_SemestrFDQuery -> ParamByName ("V_E")
                    -> Value = v_ed;
                DataModule1 -> Inc_Group_SemestrFDQuery -> ParamByName ("KURS")
                    -> Value = i + 1;
                DataModule1 -> Inc_Group_SemestrFDQuery -> ParamByName ("FAC")
                    -> Value = nom_fac;
                DataModule1 -> Inc_Group_SemestrFDQuery -> ParamByName ("GOD")
                    -> Value = uch_god_main + 1;
                DataModule1 -> Inc_Group_SemestrFDQuery -> Open ();

                int rec_gr = DataModule1 -> Inc_Group_SemestrFDQuery -> RecordCount;
                int inc_gr; // инкремент группы

                for (int g = 0; g < rec_gr; g++) { // for 3 цикл по группам
                    inc_gr =
                        DataModule1 -> Inc_Group_SemestrFDQueryINC_GROUP -> Value;
                    Variant Ce1 = SelectCell (2, n_r);
                    SheetFormat (Ce1, "@");
                    CellValue (DataModule1 -> Inc_Group_SemestrFDQueryN_GROUP -> 
                        Value, 2, n_r);
                    BorderCell (2, n_r, 1, 2);
                    CellValue (int
                        (DataModule1 -> Inc_Group_SemestrFDQueryCOUNT -> Value),
                        3, n_r);
                    BorderCell (3, n_r, 1, 2);
                    BorderCell (1, n_r, 1, 2);

                    //
                    DataModule1 -> Semestr_Kurs_NewFDQuery -> Close ();
                    DataModule1 -> Semestr_Kurs_NewFDQuery -> ParamByName ("INC_GR")
                        -> Value = inc_gr;
                    DataModule1 -> Semestr_Kurs_NewFDQuery -> ParamByName ("N_OBJ")
                        -> Value = n_obj;
                    DataModule1 -> Semestr_Kurs_NewFDQuery -> ParamByName ("PLAN")
                        -> Value = uch_god_main;
                    DataModule1 -> Semestr_Kurs_NewFDQuery -> ParamByName ("SEM")
                        -> Value = n_sem[i];
                    DataModule1 -> Semestr_Kurs_NewFDQuery -> ParamByName ("GOD")
                        -> Value = uch_god_main + 1;
                    DataModule1 -> Semestr_Kurs_NewFDQuery -> Open ();

                    // выполняем процедуру разнесения оценок по конкретному предмету в зависимости от системы оценок
                    if (syst_ball == 5) { // if система оценок пятибальная
                        // разнесение количество явки на экзамен
                        CellFormula ("=СУММ (E" + AnsiString (n_r) + ";G" +
                            AnsiString (n_r) + ";I" + AnsiString (n_r) + ";K" +
                            AnsiString (n_r) + ")", 4, n_r);
                        BorderCell (4, n_r, 1, 2);
                        // разнесение оценок по предмету
                        System_five (n_r);
                    } // end if система оценок пятибальная
                    else { // else система оценок десятибальная
                        // разнесение количество явки на экзамен
                        CellFormula ("=СУММ (E" + AnsiString (n_r) + ";G" +
                            AnsiString (n_r) + ";I" + AnsiString (n_r) + ";K" +
                            AnsiString (n_r) + ";M" + AnsiString (n_r) + ";O" +
                            AnsiString (n_r) + ";Q" + AnsiString (n_r) + ";S" +
                            AnsiString (n_r) + ")", 4, n_r);
                        BorderCell (4, n_r, 1, 2);
                        // разнесение оценок по предмету
                        System_ten (n_r);
                    } // end else система оценок десятибальная

                    n_r++;
                    DataModule1 -> Inc_Group_SemestrFDQuery -> Next ();
                } // end for 3 цикл по группам
                Itogo_summ (n_r, rec_gr);
                n_r++;
            } // end if если экзамен  и диф.зачет
            DataModule1 -> Count_ObjectFDQuery -> Next ();
        } // end for 2 цикл по предметам
        // ------------------
        AutoFitColumn (WorSheet, 1);
        // ------------------
    } // end for1 цикл по семестрам

    AnsiString name_f = "Результаты сдачи " + sem_text + " сессии " +
        v_ed_text + " обучения  факультета " + DM2 -> FacultyFDTable -> Lookup
        ("N_FAC", nom_fac, "FAC1") + " за " + DateToStr (cur_d ()) + ".xls";
    Variant WorkSaveAs = SaveBookAs (WorBook, "d:\\Мои документы\\" + name_f);
    OVisible (ExAppl);
    Close ();

}


void __fastcall TSemestr_sessionForm::BitBtn2Click (TObject *Sender) {
    // ----определение системы выдачи оценки (пятибальная или десятибальная)
    // !!!if (Application -> MessageBox ("Учебная карточка будет показана в десятибальной системе?", "Выбор системы оценок", MB_YESNO) == mrYes)
    if (MessageDlg ("Учебная карточка будет показана в десятибальной системе?",
        mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
    { // if в десятибальной системе
        syst_ball = 10;
    } // end if в десятибальной системе
    else { // else  в пятибальной системе
        syst_ball = 5;
    } // end else  в пятибальной системе

    uch_god_main = StrToInt (MaskEdit1 -> Text);
    if (ComboBox1 -> ItemIndex == -1)
    { // if проверка на ввод значений в вид обучения

        ShowMessage ("Введите данные по виду обучения!");
        return;
    } // end if проверка на ввод значений в вид обучения

    // ---------
    AnsiString v_ed_text = "";
    // переменные для текстового формирования вида обучения

    ExAppl = Variant::CreateObject ("Excel.Application");
    ColWorkSheet (ExAppl, (Variant)1);
    WorBook = NewBook (ExAppl);
    OVisible (ExAppl);
    v_ed = ComboBox1 -> ItemIndex; // 0-дневное, 1-заочное

    if (v_ed)
        v_ed_text = "заочного";
    else
        v_ed_text = "дневного";

    // --определяем размер массива сессий   через процедуру
    mass_sem (v_ed, 3);

    // Формирование в Excel
    for (int i = 0; i < razm_mas; i++) { // for 1 цикл по курсам
        WorSheet = NewSheet1 (ExAppl);
        NameSheet1 (WorSheet, AnsiString (i + 1) + " курс");
        SelectSheet (WorBook, AnsiString (i + 1) + " курс");

        // шапка  таблицы формируется в процедуре
        Shapka_Tabl ();

        // 2-ая строка - Результаты сдачи
        Cell_2_Text (WorSheet, 1, col2_zagolovok, 2, false, "Arial", 11, false,
            3, 0, true, false, "Результаты сдачи экзаменационных сессий");

        // 3-я строка - студенты и факультет
        Cell_2_Text (WorSheet, 1, col2_zagolovok, 3, false, "Arial", 11, false,
            3, 0, true, false, "студентами " + AnsiString (i + 1) + " курса " +
            v_ed_text + " отделения факультета " + DM2 -> FacultyFDTable -> Lookup
            ("N_FAC", nom_fac, "FAC1"));

        // процедура занесение столбцов в зависимости от системы оценки
        Create_text_mass ();
        // -------

        int n_r = 7; // начальная строка для занесения

        // Занесение данных
        for (int se = 0; se < 2; se++)
        { // for 2 цикл по сессиям (0-зимняя, 1- летняя)
            if (!se)
                Cell_2_Text (WorSheet, 1, col2_zagolovok, n_r, true, "Arial", 10,
                true, 3, 2, true, false, "Зимняя сессия");
            else
                Cell_2_Text (WorSheet, 1, col2_zagolovok, n_r, true, "Arial", 10,
                true, 3, 2, true, false, "Летняя сессия");
            n_r++;

            DataModule1 -> Count_ObjectFDQuery -> Close ();
            DataModule1 -> Count_ObjectFDQuery -> SQL -> Clear ();
            DataModule1 -> Count_ObjectFDQuery -> SQL -> Add (Sql_count_object);
            if (!se)
                DataModule1 -> Count_ObjectFDQuery -> ParamByName ("SEMESTR")
                    -> Value = n_sem[i * 2];
            else
                DataModule1 -> Count_ObjectFDQuery -> ParamByName ("SEMESTR")
                    -> Value = n_sem[i * 2 + 1];

            DataModule1 -> Count_ObjectFDQuery -> ParamByName ("VID_EDU")
                -> Value = v_ed;
            DataModule1 -> Count_ObjectFDQuery -> ParamByName ("FAC") -> Value =
                nom_fac;
            DataModule1 -> Count_ObjectFDQuery -> ParamByName ("PLAN") -> Value =
                uch_god_main;
            DataModule1 -> Count_ObjectFDQuery -> Open ();

            int rec_obj = DataModule1 -> Count_ObjectFDQuery -> RecordCount;
            int n_obj;
            AnsiString name_obj = ""; // Название предмета
            int rec_gr = 0; // Кол-во групп на курсе

            for (int o = 0; o < rec_obj; o++) { // for 3 цикл по предметам
                if ( (DataModule1 -> Count_ObjectFDQueryZACH_EXAM -> Value == 2) ||
                    (DataModule1 -> Count_ObjectFDQueryZACH_EXAM -> Value == 3))
                { // if если экзамен  или диф. зачет

                    n_obj = DataModule1 -> Count_ObjectFDQueryN_OBJECT -> Value;
                    name_obj =
                        DataModule1 -> Count_ObjectFDQueryNAME_OBJECT -> Value;
                    CellValue (name_obj, 1, n_r);
                    BorderCell (1, n_r, 1, 2);
                    DataModule1 -> Inc_Group_SemestrFDQuery -> Close ();
                    DataModule1 -> Inc_Group_SemestrFDQuery -> ParamByName ("V_E")
                        -> Value = v_ed;
                    DataModule1 -> Inc_Group_SemestrFDQuery -> ParamByName ("KURS")
                        -> Value = i + 1;
                    DataModule1 -> Inc_Group_SemestrFDQuery -> ParamByName ("FAC")
                        -> Value = nom_fac;
                    DataModule1 -> Inc_Group_SemestrFDQuery -> Open ();

                    rec_gr = DataModule1 -> Inc_Group_SemestrFDQuery -> RecordCount;
                    int inc_gr; // инкремент группы

                    for (int g = 0; g < rec_gr; g++) { // for 4 цикл по группам
                        inc_gr =
                            DataModule1 -> 
                            Inc_Group_SemestrFDQueryINC_GROUP -> Value;
                        Variant Ce1 = SelectCell (2, n_r);
                        SheetFormat (Ce1, "@");
                        CellValue (DataModule1 -> Inc_Group_SemestrFDQueryN_GROUP -> 
                            Value, 2, n_r);
                        BorderCell (2, n_r, 1, 2);
                        CellValue (int
                            (DataModule1 -> Inc_Group_SemestrFDQueryCOUNT -> Value),
                            3, n_r);
                        BorderCell (3, n_r, 1, 2);
                        BorderCell (1, n_r, 1, 2);

                        DataModule1 -> Semestr_Kurs_NewFDQuery -> Close ();
                        DataModule1 -> Semestr_Kurs_NewFDQuery -> ParamByName
                            ("INC_GR") -> Value = inc_gr;
                        DataModule1 -> Semestr_Kurs_NewFDQuery -> ParamByName
                            ("N_OBJ") -> Value = n_obj;
                        DataModule1 -> Semestr_Kurs_NewFDQuery -> ParamByName
                            ("PLAN") -> Value = uch_god_main;

                        if (!se)
                            DataModule1 -> Semestr_Kurs_NewFDQuery -> ParamByName
                                ("SEM") -> Value = n_sem[i * 2];
                        else
                            DataModule1 -> Semestr_Kurs_NewFDQuery -> ParamByName
                                ("SEM") -> Value = n_sem[i * 2 + 1];
                        DataModule1 -> Semestr_Kurs_NewFDQuery -> Open ();

                        // выполняем процедуру разнесения оценок по конкретному предмету в зависимости от системы оценок
                        if (syst_ball == 5) { // if система оценок пятибальная
                            // разнесение количество явки на экзамен
                            CellFormula ("=СУММ (E" + AnsiString (n_r) + ";G" +
                                AnsiString (n_r) + ";I" + AnsiString (n_r) +
                                ";K" + AnsiString (n_r) + ")", 4, n_r);
                            BorderCell (4, n_r, 1, 2);
                            // разнесение оценок по предмету
                            System_five (n_r);
                        } // end if система оценок пятибальная
                        else { // else система оценок десятибальная
                            // разнесение количество явки на экзамен
                            CellFormula ("=СУММ (E" + AnsiString (n_r) + ";G" +
                                AnsiString (n_r) + ";I" + AnsiString (n_r) +
                                ";K" + AnsiString (n_r) + ";M" + AnsiString (n_r)
                                + ";O" + AnsiString (n_r) + ";Q" +
                                AnsiString (n_r) + ";S" + AnsiString (n_r) + ")",
                                4, n_r);
                            BorderCell (4, n_r, 1, 2);
                            // разнесение оценок по предмету
                            System_ten (n_r);
                        } // end else система оценок десятибальная

                        n_r++;
                        DataModule1 -> Inc_Group_SemestrFDQuery -> Next ();
                    } // end for 4 цикл по группам

                    Itogo_summ (n_r, rec_gr);
                    n_r++;
                } // end if если экзамен   или диф. зачет
                DataModule1 -> Count_ObjectFDQuery -> Next ();
            } // end for 3 цикл по предметам
        } // end for 2 цикл по сессиям

        // ------------------
        AutoFitColumn (WorSheet, 1);

    } // end for 1 цикл по курсам
    // ------------------

    AnsiString name_f = "Результаты сдачи экзаменационных сессий " + v_ed_text +
        " обучения  факультета " + DM2 -> FacultyFDTable -> Lookup ("N_FAC", nom_fac,
        "FAC1") + " за " + DateToStr (cur_d ()) + ".xls";
    Variant WorkSaveAs = SaveBookAs (WorBook, "d:\\Мои документы\\" + name_f);
    OVisible (ExAppl);
    Close ();

}


void __fastcall TSemestr_sessionForm::FormCreate (TObject *Sender) {
    MaskEdit1 -> Text = IntToStr (uch_god);
    // заносим значение учебного года для облегчения
    Label3 -> Caption = "/ " + IntToStr (uch_god + 1);
}


void __fastcall TSemestr_sessionForm::MaskEdit1Exit (TObject *Sender)
{ // занесение учебного года по потере фокуса  MaskEdit1
    Label3 -> Caption = "/ " + IntToStr (StrToInt (MaskEdit1 -> Text) + 1);
}


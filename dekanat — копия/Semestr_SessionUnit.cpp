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


AnsiString * text_mass;                 // ������ ��� ��������� ��������� �������� �������� �� ��������

int          col2_zagolovok,                     // ������ ������� ��� ����������� ��������� � ����� (��-�� 2-� ������)
             kol_text_mass,             // ���-�� ��������� � ������� text_mass (�������� 5 ��� ����������� � 8 ��� ������������� �������)
             razm_mas,                           // ������ ������� � ����������� �� ���� ��������
             uch_god_main, // ������� ���, ������� ������� ������������
             v_ed;                               // 0 - �������, 1 - �������

int        * n_sem; // ������ ������� ��������� � ����������� �� ������ � ���� ��������

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
{ // ��������� ��������� � Excel ������� ����� �� ������� � ����������� �� ������� ������
    // ����� �� �������� ���-�� ��������� � ������, � ���� �� �������
    CellValue ("  �����:", 1, n_r);
    BorderCell (1, n_r, 1, 2);
    BorderCell (2, n_r, 1, 2);
    CellFormula ("=���� (C" + AnsiString (n_r - rec_gr) + ":C" +
        AnsiString (n_r - 1) + ")", 3, n_r);
    BorderCell (3, n_r, 1, 2);
    CellFormula ("=���� (D" + AnsiString (n_r - rec_gr) + ":D" +
        AnsiString (n_r - 1) + ")", 4, n_r);
    BorderCell (4, n_r, 1, 2);

    // ��������� ������ ���� ��������

    // �������: ���. (5) ��� ������ (10)
    CellFormula ("=���� (E" + AnsiString (n_r - rec_gr) + ":E" +
        AnsiString (n_r - 1) + ")", 5, n_r);
    BorderCell (5, n_r, 1, 2);
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "E" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 6, n_r);
    BorderCell (6, n_r, 1, 2);
    Variant Ce1 = SelectCell (6, n_r);
    SheetFormat (Ce1, "0,0");
    // �������: ���. (5) ��� ������ (10)
    CellFormula ("=���� (G" + AnsiString (n_r - rec_gr) + ":G" +
        AnsiString (n_r - 1) + ")", 7, n_r);
    BorderCell (7, n_r, 1, 2);
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "G" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 8, n_r);
    BorderCell (8, n_r, 1, 2);
    Ce1 = SelectCell (8, n_r);
    SheetFormat (Ce1, "0,0");
    // �������: �����. (5) ��� ������ (10)
    CellFormula ("=���� (I" + AnsiString (n_r - rec_gr) + ":I" +
        AnsiString (n_r - 1) + ")", 9, n_r);
    BorderCell (9, n_r, 1, 2);
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "I" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 10, n_r);
    BorderCell (10, n_r, 1, 2);
    Ce1 = SelectCell (10, n_r);
    SheetFormat (Ce1, "0,0");
    // �������: ����. (5) ��� ���� (10)
    CellFormula ("=���� (K" + AnsiString (n_r - rec_gr) + ":K" +
        AnsiString (n_r - 1) + ")", 11, n_r);
    BorderCell (11, n_r, 1, 2);
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "K" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 12, n_r);
    BorderCell (12, n_r, 1, 2);
    Ce1 = SelectCell (12, n_r);
    SheetFormat (Ce1, "0,0");
    // �������: ���. � ���. (5) ��� ����� (10)
    CellFormula ("=���� (M" + AnsiString (n_r - rec_gr) + ":M" +
        AnsiString (n_r - 1) + ")", 13, n_r);
    BorderCell (13, n_r, 1, 2);
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "M" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 14, n_r);
    BorderCell (14, n_r, 1, 2);
    Ce1 = SelectCell (14, n_r);
    SheetFormat (Ce1, "0,0");

    if (syst_ball == 5) { // if ����������� �������
        // �������: ��. ���� (5)
        CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + " (E" + AnsiString (n_r)
            + "*5+G" + AnsiString (n_r) + "*4+I" + AnsiString (n_r) + "*3)/D" +
            AnsiString (n_r) + ";0)", 15, n_r);
        BorderCell (15, n_r, 1, 2);
        Ce1 = SelectCell (15, n_r);
        SheetFormat (Ce1, "0,0");
    } // end if ����������� �������
    else { // else  ������������� �������
        // �������: ���� (10)
        CellFormula ("=���� (O" + AnsiString (n_r - rec_gr) + ":O" +
            AnsiString (n_r - 1) + ")", 15, n_r);
        BorderCell (15, n_r, 1, 2);
        CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "O" + AnsiString (n_r)
            + "/D" + AnsiString (n_r) + "*100" + ";0)", 16, n_r);
        BorderCell (16, n_r, 1, 2);
        Ce1 = SelectCell (16, n_r);
        SheetFormat (Ce1, "0,0");
        // �������: ������ (10)
        CellFormula ("=���� (Q" + AnsiString (n_r - rec_gr) + ":Q" +
            AnsiString (n_r - 1) + ")", 17, n_r);
        BorderCell (17, n_r, 1, 2);
        CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "Q" + AnsiString (n_r)
            + "/D" + AnsiString (n_r) + "*100" + ";0)", 18, n_r);
        BorderCell (18, n_r, 1, 2);
        Ce1 = SelectCell (18, n_r);
        SheetFormat (Ce1, "0,0");
        // �������: �� ����� (10)
        CellFormula ("=���� (S" + AnsiString (n_r - rec_gr) + ":S" +
            AnsiString (n_r - 1) + ")", 19, n_r);
        BorderCell (19, n_r, 1, 2);
        CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "S" + AnsiString (n_r)
            + "/D" + AnsiString (n_r) + "*100" + ";0)", 20, n_r);
        BorderCell (20, n_r, 1, 2);
        Ce1 = SelectCell (20, n_r);
        SheetFormat (Ce1, "0,0");
        // �������: ��. ���� (10)
        CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + " (E" + AnsiString (n_r)
            + "*10+G" + AnsiString (n_r) + "*9+I" + AnsiString (n_r) + "*8+K" +
            AnsiString (n_r) + "*7+M" + AnsiString (n_r) + "*6+O" +
            AnsiString (n_r) + "*5+Q" + AnsiString (n_r) + "*4)/D" +
            AnsiString (n_r) + ";0)", 21, n_r);
        BorderCell (21, n_r, 1, 2);
        Ce1 = SelectCell (21, n_r);
        SheetFormat (Ce1, "0,0");
    } // end else  ������������� �������
}


void __fastcall TSemestr_sessionForm::System_five (int n_r)
{ // ��������� ���������� ������ ��� ����������� �������

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
    // -----------------------------��������� ������ � Excel �� ������ � �� ��������
    Variant Ce1;
    // ---����
    CellValue (AnsiString (otl), 5, n_r);
    BorderCell (5, n_r, 1, 2);
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "E" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 6, n_r);
    BorderCell (6, n_r, 1, 2);
    Ce1 = SelectCell (6, n_r);
    SheetFormat (Ce1, "0,0");
    // ---������
    CellValue (AnsiString (hor), 7, n_r);
    BorderCell (7, n_r, 1, 2);
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "G" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 8, n_r);
    BorderCell (8, n_r, 1, 2);
    Ce1 = SelectCell (8, n_r);
    SheetFormat (Ce1, "0,0");
    // ---���
    CellValue (AnsiString (ud), 9, n_r);
    BorderCell (9, n_r, 1, 2);
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "I" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 10, n_r);
    BorderCell (10, n_r, 1, 2);
    Ce1 = SelectCell (10, n_r);
    SheetFormat (Ce1, "0,0");
    // ---���
    CellValue (AnsiString (neud), 11, n_r);
    BorderCell (11, n_r, 1, 2);
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "K" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 12, n_r);
    BorderCell (12, n_r, 1, 2);
    Ce1 = SelectCell (12, n_r);
    SheetFormat (Ce1, "0,0");
    // ---���� + ������
    CellFormula ("=���� (E" + AnsiString (n_r) + ";G" + AnsiString (n_r) + ")",
        13, n_r);
    BorderCell (13, n_r, 1, 2);
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "M" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 14, n_r);
    BorderCell (14, n_r, 1, 2);
    Ce1 = SelectCell (14, n_r);
    SheetFormat (Ce1, "0,0");
    // ---������� ���� �� ��������
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + " (E" + AnsiString (n_r) +
        "*5+G" + AnsiString (n_r) + "*4+I" + AnsiString (n_r) + "*3)/D" +
        AnsiString (n_r) + ";0)", 15, n_r);
    BorderCell (15, n_r, 1, 2);
    Ce1 = SelectCell (15, n_r);
    SheetFormat (Ce1, "0,0");
}


void __fastcall TSemestr_sessionForm::System_ten (int n_r)
{ // ��������� ���������� ������ ��� ������������� �������
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

    // -----------------------------��������� ������ � Excel �� ������ � �� ��������
    Variant Ce1;
    // ---������
    CellValue (AnsiString (ten), 5, n_r);
    BorderCell (5, n_r, 1, 2);
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "E" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 6, n_r);
    BorderCell (6, n_r, 1, 2);
    Ce1 = SelectCell (6, n_r);
    SheetFormat (Ce1, "0,0");
    // ---������
    CellValue (AnsiString (nine), 7, n_r);
    BorderCell (7, n_r, 1, 2);
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "G" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 8, n_r);
    BorderCell (8, n_r, 1, 2);
    Ce1 = SelectCell (8, n_r);
    SheetFormat (Ce1, "0,0");
    // ---������
    CellValue (AnsiString (eight), 9, n_r);
    BorderCell (9, n_r, 1, 2);
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "I" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 10, n_r);
    BorderCell (10, n_r, 1, 2);
    Ce1 = SelectCell (10, n_r);
    SheetFormat (Ce1, "0,0");
    // ---����
    CellValue (AnsiString (seven), 11, n_r);
    BorderCell (11, n_r, 1, 2);
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "K" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 12, n_r);
    BorderCell (12, n_r, 1, 2);
    Ce1 = SelectCell (12, n_r);
    SheetFormat (Ce1, "0,0");
    // ---�����
    CellValue (AnsiString (six), 13, n_r);
    BorderCell (13, n_r, 1, 2);
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "M" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 14, n_r);
    BorderCell (14, n_r, 1, 2);
    Ce1 = SelectCell (14, n_r);
    SheetFormat (Ce1, "0,0");
    // ---����
    CellValue (AnsiString (five), 15, n_r);
    BorderCell (15, n_r, 1, 2);
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "O" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 16, n_r);
    BorderCell (16, n_r, 1, 2);
    Ce1 = SelectCell (16, n_r);
    SheetFormat (Ce1, "0,0");
    // ---������
    CellValue (AnsiString (four), 17, n_r);
    BorderCell (17, n_r, 1, 2);
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "Q" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 18, n_r);
    BorderCell (18, n_r, 1, 2);
    Ce1 = SelectCell (18, n_r);
    SheetFormat (Ce1, "0,0");
    // ---���+���+����
    CellValue (AnsiString (neud), 19, n_r);
    BorderCell (19, n_r, 1, 2);
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + "S" + AnsiString (n_r) +
        "/D" + AnsiString (n_r) + "*100" + ";0)", 20, n_r);
    BorderCell (20, n_r, 1, 2);
    Ce1 = SelectCell (20, n_r);
    SheetFormat (Ce1, "0,0");
    // ---������� ���� �� ��������
    CellFormula ("=���� (D" + AnsiString (n_r) + ">0;" + " (E" + AnsiString (n_r) +
        "*10+G" + AnsiString (n_r) + "*9+I" + AnsiString (n_r) + "*8+K" +
        AnsiString (n_r) + "*7+M" + AnsiString (n_r) + "*6+O" + AnsiString (n_r) +
        "*5+Q" + AnsiString (n_r) + "*4)/D" + AnsiString (n_r) + ";0)", 21, n_r);
    BorderCell (21, n_r, 1, 2);
    Ce1 = SelectCell (21, n_r);
    SheetFormat (Ce1, "0,0");

}


void __fastcall TSemestr_sessionForm::Create_text_mass ()
{ // ��������� �������� ������� ��������� �������� � ����������
    int col1 = 5; // c ������ ������� �������� �����������
    if (syst_ball == 5) { // if ����������� �������
        kol_text_mass = 5;
        // ������ �������
        text_mass = new AnsiString[kol_text_mass];
        text_mass[0] = "���.";
        text_mass[1] = "���.";
        text_mass[2] = "�����.";
        text_mass[3] = "����.";
        text_mass[4] = "���. � ���.";
    } // end if ����������� �������
    else { // else ������������� �������
        kol_text_mass = 8;
        text_mass = new AnsiString[kol_text_mass];
        text_mass[0] = "������";
        text_mass[1] = "������";
        text_mass[2] = "������";
        text_mass[3] = "����";
        text_mass[4] = "�����";
        text_mass[5] = "����";
        text_mass[6] = "������";
        text_mass[7] = "�� �����";
    } // end else ������������� �������

    // ��������� � ������ Excel �������� �� �������
    for (int i = 0; i < kol_text_mass; i++) { // for
        Cell_2_Text (WorSheet, col1, (col1 + 1), 5, true, "Arial", 10, true, 3,
            2, true, false, text_mass[i]);
        // ���-��
        Coll_2_Text (WorSheet, col1, 6, 6, true, "Arial", 10, true, 3, 2, 90,
            false, false, "���-��");
        // ������ %
        Coll_2_Text (WorSheet, (col1 + 1), 6, 6, true, "Arial", 10, true, 3, 2,
            0, false, false, "%");

        col1 += 2;
    } // end for

    // ������� ����
    Coll_2_Text (WorSheet, col1, 5, 6, true, "Arial", 10, true, 3, 2, 90, true,
        false, "��. ����");

}


void __fastcall TSemestr_sessionForm::mass_sem (int vid_edu, int ses_edu)
{ // ��������� ������� ������� �� ���������

    if (ses_edu != 3)
    { // if ������������ � ������ ������ (������ ��� ������, 1 ��� 0)
        if (!vid_edu) { // if ������� ��������
            razm_mas = 4;
            n_sem = new int[razm_mas];
            for (int i = 0; i < razm_mas; i++) { // for
                if (!ses_edu)
                    n_sem[i] = i * 2 + 1;
                else
                    n_sem[i] = i * 2 + 2;
            } // end for
        } // end if ������� ��������
        else { // else ������� ��������
            razm_mas = 5;
            n_sem = new int[razm_mas];
            for (int i = 0; i < razm_mas; i++) { // for
                if (!ses_edu)
                    n_sem[i] = i * 2 + 1;
                else
                    n_sem[i] = i * 2 + 2;
            } // end for
        } // end else ������� ��������
    } // end if ������������ � ������ ������ (������ ��� ������, 1 ��� 0)
    else { // else ��� ����������� ������� �� ���� ��� ��� ����� ������
        if (!vid_edu) { // if ������� ��������
            razm_mas = 4;
        } // end if ������� ��������
        else { // else ������� ��������
            razm_mas = 5;
        } // end else ������� ��������

        n_sem = new int[razm_mas * 2];
        for (int i = 0; i < razm_mas * 2; i++) { // for
            n_sem[i] = i + 1;
        } // end for
    } // end else ��� ����������� ������� �� ���� ��� ��� ����� ������

}


void __fastcall TSemestr_sessionForm::Shapka_Tabl ()
{ // ��������� ������������ ����� �������, �.�. ��� �� ���������� � ���� �����������

    // --------------------------- �������
    // Cell_2_Text (Variant WorSheet,int col1, int col2, int st, bool Border, AnsiString Shrift, int kegl, bool Bold,
    // int AlignH, int AlignV, bool M_1, bool W_1, AnsiString TextCell);

    // --------------------------- �������
    // Coll_2_Text (Variant WorSheet,int col1, int st1, int st2, bool Border, AnsiString Shrift, int kegl, bool Bold,
    // int AlignH, int AlignV, int Orient, bool M_1, bool W_1, AnsiString TextCell);
    // ---------------------------

    if (syst_ball == 5) // ����������� �������
            col2_zagolovok = 15; // �������� "A1:O1"
    else
        col2_zagolovok = 21; // �������� "A1:U1" ��� ������������� �������

    // 1-�� ������ - ������� ���
    Cell_2_Text (WorSheet, 1, col2_zagolovok, 1, false, "Arial", 11, true, 3, 0,
        true, false, AnsiString (uch_god_main) + "/" +
        AnsiString (uch_god_main + 1) + " ������� ���");

    // ������������ ����������
    Coll_2_Text (WorSheet, 1, 5, 6, true, "Arial", 10, true, 3, 2, 0, true,
        false, "������������ ����������");

    // � ������
    Coll_2_Text (WorSheet, 2, 5, 6, true, "Arial", 10, true, 3, 2, 90, true,
        false, "� ������");

    // ���-�� ���������
    Coll_2_Text (WorSheet, 3, 5, 6, true, "Arial", 10, true, 3, 2, 90, true,
        true, "���-�� ���������");

    // ���� �� �������
    Coll_2_Text (WorSheet, 4, 5, 6, true, "Arial", 10, true, 3, 2, 90, true,
        true, "���� �� �������");

    // ��������� ��������� ���������� �����
    SetOrientatSheet (WorSheet, 2);

    // ��������� ������ �������� � ��������� � B �� U
    ColumnWidth (Range2 (WorSheet, "B:U"), 5);

    // ��������� ������ ������ � ��������� �������  5 � 6
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
{ // �������� �� ������ ���������� �� ��������
    // ----����������� ������� ������ ������ (����������� ��� �������������)
    // !!!if (Application -> MessageBox ("������� �������� ����� �������� � ������������� �������?", "����� ������� ������", MB_YESNO) == mrYes)
    if (MessageDlg ("������� �������� ����� �������� � ������������� �������?",
        mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
    { // if � ������������� �������
        syst_ball = 10;
    } // end if � ������������� �������
    else { // else  � ����������� �������
        syst_ball = 5;
    } // end else  � ����������� �������

    uch_god_main = StrToInt (MaskEdit1 -> Text);

    if (ComboBox1 -> ItemIndex == -1 && ComboBox2 -> ItemIndex == -1)
    { // if �������� �� ���� �������� � ��� �������� � ������

        ShowMessage ("������� ��� ������ �� ���� �������� � ������!");
        return;
    } // end if �������� �� ���� �������� � ��� �������� � ������

    AnsiString sem_text = "", v_ed_text = "";
    // ���������� ��� ���������� ������������ ���� �������� � �����

    ExAppl = Variant::CreateObject ("Excel.Application");
    ColWorkSheet (ExAppl, (Variant)1);
    WorBook = NewBook (ExAppl);
    OVisible (ExAppl);
    v_ed = ComboBox1 -> ItemIndex; // 0-�������, 1-�������
    int ses = ComboBox2 -> ItemIndex; // 0- ������ ������, 1- ������
    if (ses)
        sem_text = "������";
    else
        sem_text = "������";
    if (v_ed)
        v_ed_text = "��������";
    else
        v_ed_text = "��������";

    // --���������� ������ ������� ������   ����� ���������
    mass_sem (v_ed, ses);

    // ������������ � Excel
    for (int i = 0; i < razm_mas; i++) { // for1 ���� �� ���������
        WorSheet = NewSheet1 (ExAppl);
        NameSheet1 (WorSheet, AnsiString (n_sem[i]) + " �������");
        SelectSheet (WorBook, AnsiString (n_sem[i]) + " �������");

        // �����  ������� ����������� � ���������
        Shapka_Tabl ();

        // 2-�� ������ - ���������� �����
        Cell_2_Text (WorSheet, 1, col2_zagolovok, 2, false, "Arial", 11, false,
            3, 0, true, false, "���������� ����� " + sem_text +
            " ��������������� ������");

        // 3-� ������ - �������� � ���������
        Cell_2_Text (WorSheet, 1, col2_zagolovok, 3, false, "Arial", 11, false,
            3, 0, true, false, "���������� " + AnsiString (i + 1) + " ����� " +
            v_ed_text + " ��������� ���������� " + DM2 -> FacultyFDTable -> Lookup
            ("N_FAC", nom_fac, "FAC1"));

        // ��������� ��������� �������� � ����������� �� ������� ������
        Create_text_mass ();

        // -------
        int n_r = 7; // ��������� ������ ��� ���������

        // ��������� ������
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
        AnsiString name_obj = ""; // �������� ��������

        for (int o = 0; o < rec_obj; o++) { // for 2 ���� �� ���������
            if ( (DataModule1 -> Count_ObjectFDQueryZACH_EXAM -> Value == 2) ||
                (DataModule1 -> Count_ObjectFDQueryZACH_EXAM -> Value == 3))
            { // if ���� �������  � ���.�����
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
                int inc_gr; // ��������� ������

                for (int g = 0; g < rec_gr; g++) { // for 3 ���� �� �������
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

                    // ��������� ��������� ���������� ������ �� ����������� �������� � ����������� �� ������� ������
                    if (syst_ball == 5) { // if ������� ������ �����������
                        // ���������� ���������� ���� �� �������
                        CellFormula ("=���� (E" + AnsiString (n_r) + ";G" +
                            AnsiString (n_r) + ";I" + AnsiString (n_r) + ";K" +
                            AnsiString (n_r) + ")", 4, n_r);
                        BorderCell (4, n_r, 1, 2);
                        // ���������� ������ �� ��������
                        System_five (n_r);
                    } // end if ������� ������ �����������
                    else { // else ������� ������ �������������
                        // ���������� ���������� ���� �� �������
                        CellFormula ("=���� (E" + AnsiString (n_r) + ";G" +
                            AnsiString (n_r) + ";I" + AnsiString (n_r) + ";K" +
                            AnsiString (n_r) + ";M" + AnsiString (n_r) + ";O" +
                            AnsiString (n_r) + ";Q" + AnsiString (n_r) + ";S" +
                            AnsiString (n_r) + ")", 4, n_r);
                        BorderCell (4, n_r, 1, 2);
                        // ���������� ������ �� ��������
                        System_ten (n_r);
                    } // end else ������� ������ �������������

                    n_r++;
                    DataModule1 -> Inc_Group_SemestrFDQuery -> Next ();
                } // end for 3 ���� �� �������
                Itogo_summ (n_r, rec_gr);
                n_r++;
            } // end if ���� �������  � ���.�����
            DataModule1 -> Count_ObjectFDQuery -> Next ();
        } // end for 2 ���� �� ���������
        // ------------------
        AutoFitColumn (WorSheet, 1);
        // ------------------
    } // end for1 ���� �� ���������

    AnsiString name_f = "���������� ����� " + sem_text + " ������ " +
        v_ed_text + " ��������  ���������� " + DM2 -> FacultyFDTable -> Lookup
        ("N_FAC", nom_fac, "FAC1") + " �� " + DateToStr (cur_d ()) + ".xls";
    Variant WorkSaveAs = SaveBookAs (WorBook, "d:\\��� ���������\\" + name_f);
    OVisible (ExAppl);
    Close ();

}


void __fastcall TSemestr_sessionForm::BitBtn2Click (TObject *Sender) {
    // ----����������� ������� ������ ������ (����������� ��� �������������)
    // !!!if (Application -> MessageBox ("������� �������� ����� �������� � ������������� �������?", "����� ������� ������", MB_YESNO) == mrYes)
    if (MessageDlg ("������� �������� ����� �������� � ������������� �������?",
        mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
    { // if � ������������� �������
        syst_ball = 10;
    } // end if � ������������� �������
    else { // else  � ����������� �������
        syst_ball = 5;
    } // end else  � ����������� �������

    uch_god_main = StrToInt (MaskEdit1 -> Text);
    if (ComboBox1 -> ItemIndex == -1)
    { // if �������� �� ���� �������� � ��� ��������

        ShowMessage ("������� ������ �� ���� ��������!");
        return;
    } // end if �������� �� ���� �������� � ��� ��������

    // ---------
    AnsiString v_ed_text = "";
    // ���������� ��� ���������� ������������ ���� ��������

    ExAppl = Variant::CreateObject ("Excel.Application");
    ColWorkSheet (ExAppl, (Variant)1);
    WorBook = NewBook (ExAppl);
    OVisible (ExAppl);
    v_ed = ComboBox1 -> ItemIndex; // 0-�������, 1-�������

    if (v_ed)
        v_ed_text = "��������";
    else
        v_ed_text = "��������";

    // --���������� ������ ������� ������   ����� ���������
    mass_sem (v_ed, 3);

    // ������������ � Excel
    for (int i = 0; i < razm_mas; i++) { // for 1 ���� �� ������
        WorSheet = NewSheet1 (ExAppl);
        NameSheet1 (WorSheet, AnsiString (i + 1) + " ����");
        SelectSheet (WorBook, AnsiString (i + 1) + " ����");

        // �����  ������� ����������� � ���������
        Shapka_Tabl ();

        // 2-�� ������ - ���������� �����
        Cell_2_Text (WorSheet, 1, col2_zagolovok, 2, false, "Arial", 11, false,
            3, 0, true, false, "���������� ����� ��������������� ������");

        // 3-� ������ - �������� � ���������
        Cell_2_Text (WorSheet, 1, col2_zagolovok, 3, false, "Arial", 11, false,
            3, 0, true, false, "���������� " + AnsiString (i + 1) + " ����� " +
            v_ed_text + " ��������� ���������� " + DM2 -> FacultyFDTable -> Lookup
            ("N_FAC", nom_fac, "FAC1"));

        // ��������� ��������� �������� � ����������� �� ������� ������
        Create_text_mass ();
        // -------

        int n_r = 7; // ��������� ������ ��� ���������

        // ��������� ������
        for (int se = 0; se < 2; se++)
        { // for 2 ���� �� ������� (0-������, 1- ������)
            if (!se)
                Cell_2_Text (WorSheet, 1, col2_zagolovok, n_r, true, "Arial", 10,
                true, 3, 2, true, false, "������ ������");
            else
                Cell_2_Text (WorSheet, 1, col2_zagolovok, n_r, true, "Arial", 10,
                true, 3, 2, true, false, "������ ������");
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
            AnsiString name_obj = ""; // �������� ��������
            int rec_gr = 0; // ���-�� ����� �� �����

            for (int o = 0; o < rec_obj; o++) { // for 3 ���� �� ���������
                if ( (DataModule1 -> Count_ObjectFDQueryZACH_EXAM -> Value == 2) ||
                    (DataModule1 -> Count_ObjectFDQueryZACH_EXAM -> Value == 3))
                { // if ���� �������  ��� ���. �����

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
                    int inc_gr; // ��������� ������

                    for (int g = 0; g < rec_gr; g++) { // for 4 ���� �� �������
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

                        // ��������� ��������� ���������� ������ �� ����������� �������� � ����������� �� ������� ������
                        if (syst_ball == 5) { // if ������� ������ �����������
                            // ���������� ���������� ���� �� �������
                            CellFormula ("=���� (E" + AnsiString (n_r) + ";G" +
                                AnsiString (n_r) + ";I" + AnsiString (n_r) +
                                ";K" + AnsiString (n_r) + ")", 4, n_r);
                            BorderCell (4, n_r, 1, 2);
                            // ���������� ������ �� ��������
                            System_five (n_r);
                        } // end if ������� ������ �����������
                        else { // else ������� ������ �������������
                            // ���������� ���������� ���� �� �������
                            CellFormula ("=���� (E" + AnsiString (n_r) + ";G" +
                                AnsiString (n_r) + ";I" + AnsiString (n_r) +
                                ";K" + AnsiString (n_r) + ";M" + AnsiString (n_r)
                                + ";O" + AnsiString (n_r) + ";Q" +
                                AnsiString (n_r) + ";S" + AnsiString (n_r) + ")",
                                4, n_r);
                            BorderCell (4, n_r, 1, 2);
                            // ���������� ������ �� ��������
                            System_ten (n_r);
                        } // end else ������� ������ �������������

                        n_r++;
                        DataModule1 -> Inc_Group_SemestrFDQuery -> Next ();
                    } // end for 4 ���� �� �������

                    Itogo_summ (n_r, rec_gr);
                    n_r++;
                } // end if ���� �������   ��� ���. �����
                DataModule1 -> Count_ObjectFDQuery -> Next ();
            } // end for 3 ���� �� ���������
        } // end for 2 ���� �� �������

        // ------------------
        AutoFitColumn (WorSheet, 1);

    } // end for 1 ���� �� ������
    // ------------------

    AnsiString name_f = "���������� ����� ��������������� ������ " + v_ed_text +
        " ��������  ���������� " + DM2 -> FacultyFDTable -> Lookup ("N_FAC", nom_fac,
        "FAC1") + " �� " + DateToStr (cur_d ()) + ".xls";
    Variant WorkSaveAs = SaveBookAs (WorBook, "d:\\��� ���������\\" + name_f);
    OVisible (ExAppl);
    Close ();

}


void __fastcall TSemestr_sessionForm::FormCreate (TObject *Sender) {
    MaskEdit1 -> Text = IntToStr (uch_god);
    // ������� �������� �������� ���� ��� ����������
    Label3 -> Caption = "/ " + IntToStr (uch_god + 1);
}


void __fastcall TSemestr_sessionForm::MaskEdit1Exit (TObject *Sender)
{ // ��������� �������� ���� �� ������ ������  MaskEdit1
    Label3 -> Caption = "/ " + IntToStr (StrToInt (MaskEdit1 -> Text) + 1);
}


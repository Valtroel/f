#include <vcl.h>
#pragma hdrstop


#include "DataModule_Card.h"
#include "DataModule.h"
#include "DiplomUnit.h"
#include "DM2Unit.h"
#include "DM3Unit.h"
#include "DualList.h"
#include "Func.h"


#pragma package (smart_init)
// #pragma link     "RXCtrls"
// #pragma link     "ToolEdit"
// #pragma link     "MyList"
#pragma resource "*.dfm"


TDiplomForm * DiplomForm;



AnsiString * mas_svod_nado[6];                                                  // ������ ������� �������� �����

AnsiString   count_sql_1    = "                                             \
    SELECT                                                                  \
        COUNT                                                               \
        (                                                                   \
            Edu_plan.N_OBJECT                                               \
        )                                                                   \
    FROM                                                                    \
        EDU_PLAN Edu_plan                                                   \
            INNER JOIN                                                      \
                OBJECT_PLAN Object_plan                                     \
                    ON                                                      \
                        (Edu_plan.N_OBJECT = Object_plan.N_OBJECT)          \
    WHERE                                                                   \
            Edu_plan.N_FAC        = :N_FAC                                  \
        AND                                                                 \
            Edu_plan.VID_EDU_PLAN = :VID_EDU                                \
    ";

AnsiString   count_sql_3    = "                                             \
    AND                                                                     \
        (                                                                   \
            N_PLAN  NOT IN                                                  \
            (                                                               \
                SELECT                                                      \
                    SPEC_PLAN.N_PLAN                                        \
                FROM                                                        \
                    SPEC_PLAN                                               \
                        INNER JOIN                                          \
                            EDU_PLAN                                        \
                                ON                                          \
                                    (SPEC_PLAN.N_PLAN = EDU_PLAN.N_PLAN)    \
            )                                                               \
         OR                                                                 \
            N_PLAN IN                                                       \
            (                                                               \
                SELECT                                                      \
                    SPEC_PLAN.N_PLAN                                        \
                FROM                                                        \
                    SPEC_PLAN                                               \
                        INNER JOIN                                          \
                            EDU_PLAN                                        \
                                ON                                          \
                                    (SPEC_PLAN.N_PLAN = EDU_PLAN.N_PLAN)    \
                WHERE                                                       \
                    spec_plan.n_specializ = :SPECIALIZ                      \
            )                                                               \
        )                                                                   \
    ";

AnsiString   sql_1          = "                                             \
    SELECT                                                                  \
        Edu_plan.N_OBJECT,                                                  \
        Edu_plan.N_PLAN,                                                    \
        Edu_plan.SEMESTR,                                                   \
        Edu_plan.CLOCK_PLAN,                                                \
        Edu_plan.CLOCK_PLAN_ALL,                                            \
        Edu_plan.YEAR_PLAN,                                                 \
        Edu_plan.N_FAC,                                                     \
        Edu_plan.ZACH_EXAM,                                                 \
        Edu_plan.VID_EDU_PLAN,                                              \
        EDU_PLAN.SPECKURS,                                                  \
        Object_plan.NAME_OBJECT                                             \
    FROM                                                                    \
        EDU_PLAN Edu_plan                                                   \
            INNER JOIN                                                      \
                OBJECT_PLAN Object_plan                                     \
                    ON                                                      \
                        (Edu_plan.N_OBJECT = Object_plan.N_OBJECT)          \
    WHERE                                                                   \
            Edu_plan.N_FAC        = :N_FAC                                  \
        AND                                                                 \
            Edu_plan.VID_EDU_PLAN = :VID_EDU                                \
    ";

AnsiString   sql_3          = "                                             \
    AND                                                                     \
        (                                                                   \
            N_PLAN NOT IN                                                   \
            (                                                               \
                select                                                      \
                    SPEC_PLAN.N_PLAN                                        \
                from                                                        \
                    SPEC_PLAN                                               \
                        INNER JOIN                                          \
                            EDU_PLAN                                        \
                                ON                                          \
                                    (SPEC_PLAN.N_PLAN = EDU_PLAN.N_PLAN)    \
            )                                                               \
         OR                                                                 \
            N_PLAN IN                                                       \
            (                                                               \
                SELECT                                                      \
                    SPEC_PLAN.N_PLAN                                        \
                FROM                                                        \
                    SPEC_PLAN                                               \
                        INNER JOIN                                          \
                            EDU_PLAN                                        \
                                ON                                          \
                                    (SPEC_PLAN.N_PLAN = EDU_PLAN.N_PLAN)    \
                WHERE                                                       \
                    spec_plan.n_specializ = :SPECIALIZ                      \
            )                                                               \
        )                                                                   \
    ORDER BY                                                                \
        Object_plan.NAME_OBJECT,                                            \
        Edu_plan.N_OBJECT,                                                  \
        edu_plan.semestr        DESC,                                       \
        edu_plan.zach_exam      DESC                                        \
    ";

AnsiString   sql_s_ved      = "                                             \
    AND                                                                     \
        Edu_plan.SPECKURS IN (0, 1, 2, 3, 4)                                \
    ";

AnsiString   ochenka_diplom = "",                                               // ������ �� ���������� �������
             Str_10,
             Str_11,
             tab            = " ",                                              // ��� ������� ��������
             thema_diplom   = "";                                               // ���� ���������� �������

bool         facultativ     = false;                                            // ���������� ��� ������������

int          god_first      = 0,                                                // �������������� ���
             len_str10,
             len_str11,
             max_len_str,
             nom_facultativ = 1,                                                // ���������� ��� ������ ������������
             nom_predmet,                                                       // ������� ���������
             str_r;
// int          uch_god        = 2011;                                             // �� ������ ���� ����� ������� ������� ���������� ������� ��� ���������� �������� �����

String       fam;




// BitBtn1Click
// BitBtn2Click
// BitBtn3Click
// CheckListBox1Click
// DateTimePicker1Change
// FormClose
// RadioGroup1Click
// RadioGroup2Click
// RadioGroup3Click
// RxCheckListBox1Click
// create_vid_control
// Predmet_svod
// Shapka_Diplom








__fastcall TDiplomForm::TDiplomForm (TComponent* Owner) : TForm (Owner) {
}

void __fastcall TDiplomForm::Shapka_Diplom (AnsiString text, bool clock)
{ // �����
    // AnsiString text - ����� � ������
    // bool clock   - true - ����� ���� ����
    // - false - ���� �� ����

    tab[1] = 0x0A; // Alt+Enter

    Cell_2_Text_Ole2 (1, 1, str_r, true, "TimesNewRoman", 10, true, 3, 2, 0,
        false, true, "� �/�");
    if (clock) {
        Cell_2_Text_Ole2 (2, 2, str_r, true, "TimesNewRoman", 10, true, 3, 2, 0,
            false, false, text);
        Cell_2_Text_Ole2 (3, 3, str_r, true, "TimesNewRoman", 10, true, 3, 2, 0,
            false, true, "����� ����������" + tab + "������������� �����");
        Cell_2_Text_Ole2 (4, 4, str_r, true, "TimesNewRoman", 10, true, 3, 2, 0,
            false, true, "���������� �������� ������");

    }
    else {
        Cell_2_Text_Ole2 (2, 4, str_r, true, "TimesNewRoman", 10, true, 3, 2, 0,
            true, false, text);

    }
    Cell_2_Text_Ole2 (5, 5, str_r, true, "TimesNewRoman", 10, true, 3, 2, 0,
        false, true, "�������, ������");
}

void __fastcall TDiplomForm::FormClose (TObject *Sender, TCloseAction &Action) {

    DM3 -> Detail_Svod_RealFDQuery -> Close ();
    DM3 -> Detail_Svod_RealFDQuery -> SQL -> Clear ();
    DM3 -> Detail_Svod_RealFDQuery -> SQL -> Add ("SELECT Object_plan.N_OBJECT, Object_plan.NAME_OBJECT, \
Edu_plan.N_PLAN, Edu_plan.SEMESTR, Edu_plan.CLOCK_PLAN, Edu_plan.CLOCK_PLAN_ALL,\
Edu_plan.YEAR_PLAN, Edu_plan.N_FAC, Edu_plan.ZACH_EXAM, \
Edu_plan.VID_EDU_PLAN, Edu_plan.SPECKURS, \
Result_ball.RESULT, \
Result_ball.DATE_RESULT, Result_ball.STATUS_RESULT,  \
People.NOMER, People.FAM, \
People.NAME, People.OTCH, People.STATUS_PEOPLE  \
FROM EDU_PLAN Edu_plan  \
   INNER JOIN OBJECT_PLAN Object_plan  \
   ON  (Edu_plan.N_OBJECT = Object_plan.N_OBJECT) \
   INNER JOIN RESULT_BALL Result_ball \
   ON  (Edu_plan.N_PLAN = Result_ball.N_PLAN)  \
   INNER JOIN PEOPLE People \
   ON  (Result_ball.NOMER = People.NOMER) \
where (People.STATUS_PEOPLE=1) and  \
People.NOMER=:NOMER and Object_plan.N_OBJECT=:N_OBJECT  \
and Edu_plan.N_FAC=:FAC  \
order by Edu_plan.SEMESTR");

    DM3 -> Name_SpecFDQuery -> Close ();
    DM3 -> Name_SpecFDQuery -> SQL -> Clear ();
    DM3 -> Name_SpecFDQuery -> SQL -> Add ("SELECT Distinct ( Specializ.N_SPECIALIZ), Specializ.SPECIAL \
FROM PEOPLE People \
   INNER JOIN INCREMENT_GROUP Increment_group \
   ON  (People.INC_GROUP = Increment_group.INC_GROUP) \
   INNER JOIN FACULTY Faculty  \
   ON  (People.N_FAC = Faculty.N_FAC) \
   INNER JOIN SPECIALIZ Specializ  \
   ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ)  \
where (People.STATUS_PEOPLE=1) and (People.INC_GROUP in (:INC_GROUP)) \
and (People.N_FAC=:N_FAC) \
ORDER BY People.FAM, People.NAME, People.OTCH");

    DM3 -> People_SvodReport_SpecFDQuery -> Close ();
    DM3 -> People_SvodReport_SpecFDQuery -> SQL -> Clear ();
    DM3 -> People_SvodReport_SpecFDQuery -> SQL -> Add ("SELECT People.NOMER, People.FAM, People.NAME, \
People.OTCH, People.VID_EDU, People.N_FAC, People.KURS, People.N_SPEC, \
People.N_SPECIALIZ, People.N_PRIKAZ_KURS, People.N_GROUP, People.STATUS_PEOPLE, \
People.INC_GROUP, People.N_ZACHET, Increment_group.VID_EDU, Increment_group.GOD, \
Increment_group.N_GROUP, Faculty.FAC1, Specializ.SPECIAL  \
FROM PEOPLE People \
   INNER JOIN INCREMENT_GROUP Increment_group  \
   ON  (People.INC_GROUP = Increment_group.INC_GROUP) \
   INNER JOIN FACULTY Faculty \
   ON  (People.N_FAC = Faculty.N_FAC)   \
   INNER JOIN SPECIALIZ Specializ   \
   ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) \
where (People.STATUS_PEOPLE=1) and (People.INC_GROUP in (:INC_GROUP)) \
and (People.N_FAC=:N_FAC)  and (People.N_SPECIALIZ in (:N_SPECIALIZ)) \
ORDER BY People.FAM, People.NAME, People.OTCH");

    Action = caFree;
}

void __fastcall TDiplomForm::RadioGroup1Click (TObject *Sender) {
    // �������
    RadioGroup2 -> Items -> Clear ();
    // � ���������
    RadioGroup2 -> Items -> Add ("1");
    RadioGroup2 -> Items -> Add ("2");
    RadioGroup2 -> Items -> Add ("3");
    RadioGroup2 -> Items -> Add ("4");

    if (RadioGroup1 -> ItemIndex) {
        RadioGroup2 -> Items -> Add ("5");
    }
    RadioGroup2 -> Visible = true;
    RadioGroup2 -> ItemIndex = -1;
    Panel2 -> Visible = false;
    Panel3 -> Visible = false;
    RadioGroup3 -> Visible = false;
    Label1 -> Visible = false;
    DateTimePicker1 -> Visible = false;

}

void __fastcall TDiplomForm::create_vid_control (int nomer_s, int col,
    AnsiString control, int stat) { // �������� � ����������� �� ���� ��������
    // int col  - ���������� ������� � �������
    // int n_p  - ����� ��������
    // int control - ��� �������� (�������, �����, ���.�����, ���, ���)
    // int stat - ������ (0 - �������, 1 - ����.����, �����������, ��������, ��������

    AnsiString sql_ball = "SELECT Object_plan.N_OBJECT, Object_plan.NAME_OBJECT, \
Edu_plan.N_PLAN, Edu_plan.SEMESTR, Edu_plan.CLOCK_PLAN, Edu_plan.CLOCK_PLAN_ALL,\
Edu_plan.YEAR_PLAN, Edu_plan.N_FAC, Edu_plan.ZACH_EXAM, \
Edu_plan.VID_EDU_PLAN, Edu_plan.SPECKURS, \
Result_ball.RESULT, Result_ball.DATE_RESULT, Result_ball.STATUS_RESULT, \
People.NOMER, People.FAM, People.NAME, People.OTCH, People.STATUS_PEOPLE  \
FROM EDU_PLAN Edu_plan \
INNER JOIN OBJECT_PLAN Object_plan \
   ON  (Edu_plan.N_OBJECT = Object_plan.N_OBJECT) \
   INNER JOIN RESULT_BALL Result_ball \
   ON  (Edu_plan.N_PLAN = Result_ball.N_PLAN)  \
   INNER JOIN PEOPLE People  \
   ON  (Result_ball.NOMER =  people.nomer) \
where (People.STATUS_PEOPLE=1)";

    AnsiString zach_spec = " and  (edu_plan.zach_exam in (" + control +
        ")) and People.NOMER=" + nomer_s + " and edu_plan.n_object in (";
    AnsiString n_pr = "";
    AnsiString sql_hv =
        ") order by edu_plan.n_object, Edu_plan.SEMESTR desc, edu_plan.n_plan desc";

    int sch = 0;
    int pr = 0; // ����� ��������
    int k = 0;
    AnsiString ocenky = "";
    bool b_10 = true; // 10-������� ������� ������
    int align_b = 2;
    // �������������� ������������ �� ������ ���� ��� ������������� �������

    for (int i = 0; i < col; i++) { // for �������, �����, ���.�����, ���, ���
        if (mas_svod_nado[1][i] == control && mas_svod_nado[2][i] == stat) {
            n_pr += mas_svod_nado[0][i] + ",";
            sch++;
        }
    } // end for �������, �����, ���.�����, ���, ���

    if (n_pr != "")
        n_pr = n_pr.SubString (1, (n_pr.Length () - 1));
    else
        return;

    DM3 -> Detail_Svod_RealFDQuery -> Close ();
    DM3 -> Detail_Svod_RealFDQuery -> SQL -> Clear ();
    DM3 -> Detail_Svod_RealFDQuery -> SQL -> Add (sql_ball + zach_spec + n_pr +
        sql_hv);
    DM3 -> Detail_Svod_RealFDQuery -> Open ();

    AnsiString *mas_real[4]; // ������ ������� �  ���������
    for (int i = 0; i < 4; i++) { // for1
        mas_real[i] = new AnsiString[sch];
    } // end for 1

    for (int z = 0; z < DM3 -> Detail_Svod_RealFDQuery -> RecordCount; z++) {
        if (pr != DM3 -> Detail_Svod_RealFDQueryN_OBJECT -> Value) {
            mas_real[0][k] =
                AnsiString (DM3 -> Detail_Svod_RealFDQueryN_OBJECT -> Value);
            // ����� ��������
            mas_real[1][k] =
                ball_string (syst_ball, ball_int (syst_ball,
                DM3 -> Detail_Svod_RealFDQueryRESULT -> Value), 1); // ������
            mas_real[2][k] =
                AnsiString (DM3 -> Detail_Svod_RealFDQueryCLOCK_PLAN_ALL -> Value);
            // ����� ���������� ����� ��������  ���
            mas_real[3][k] =
                AnsiString (DM3 -> Detail_Svod_RealFDQueryCLOCK_PLAN -> Value);
            // ����� ���������� �������� ������  �������
            pr = DM3 -> Detail_Svod_RealFDQueryN_OBJECT -> Value;
            k++;
        }
        else {
            mas_real[2][k - 1] =
                AnsiString (StrToInt (mas_real[2][k - 1]) +
                DM3 -> Detail_Svod_RealFDQueryCLOCK_PLAN_ALL -> Value); // ���
            mas_real[3][k - 1] =
                AnsiString (FormatFloat ("0.0", StrToFloat (mas_real[3][k - 1]) +
                DM3 -> Detail_Svod_RealFDQueryCLOCK_PLAN -> Value)); // �������
        }
        DM3 -> Detail_Svod_RealFDQuery -> Next ();
    }

    if (RadioGroup3 -> ItemIndex) // 5-�� �������
    {
        b_10 = false;
        align_b = 3;
        // �������������� ������������ �� ������ ��� ����������� �������
    }

    for (int i = 0; i < col; i++) { // for �������, �����, ���.�����, ���
        if (mas_svod_nado[1][i] == control && mas_svod_nado[2][i] == stat) {

            Cell_2_Text_Ole2 (1, 1, str_r, true, "Arial", 10, false, 3, 2, 0,
                false, false, IntToStr (nom_predmet));
            Cell_2_Text_Ole2 (2, 2, str_r, true, "Arial", 10, false, 0, 2, 0,
                false, true, Text_predmet (mas_svod_nado[3][i],
                DM3 -> People_SvodFDQueryN_SPECIALIZ -> Value));

            if (mas_svod_nado[1][i] == "5") { // if ��������� ������
                // ����������
                Border_IndentLeft (3, 3, str_r - 1, str_r, true, 4, 0);
                Border_IndentLeft (3, 3, str_r - 1, str_r, true, 2, 0);
                Border_IndentLeft (4, 4, str_r - 1, str_r, true, 4, 0);
                Border_IndentLeft (4, 4, str_r - 1, str_r, true, 1, 0);

            } // end if ��������� ������
            else {
                Cell_2_Text_Ole2 (3, 3, str_r, true, "Arial", 10, false, 3, 2, 0,
                    false, false, mas_svod_nado[4][i]);
                if (StrToFloat (mas_svod_nado[5][i])) {
                    Cell_2_Text_Ole2 (4, 4, str_r, true, "Arial", 10, false, 3,
                        2, 0, false, false, mas_svod_nado[5][i]);
                }
                else {
                    Cell_2_Text_Ole2 (4, 4, str_r, true, "Arial", 10, false, 3,
                        2, 0, false, false, "-");
                }
            }

            AnsiString Str_1 = mas_svod_nado[3][i];

            if (stat != 5) { // �� ���

                Cell_2_Text_Ole2 (5, 5, str_r, true, "Arial", 10, false, 2, 2, 0,
                    false, false, "");
                // end else ��� �� ��� �������

                Str_11 = mas_svod_nado[3][i];

                for (int j = 0; j < k; j++) {
                    if (mas_svod_nado[0][i] == mas_real[0][j]) {
                        // 04.2014 - ��������� ������� � �������

                        ocenky = "";
                        int n_ball; // ���������� ������ �� ��������
                        int zachet = 0; // ���-�� ������� �� ��������

                        DM3 -> FDQuery3 -> Close ();
                        DM3 -> FDQuery3 -> ParamByName ("nomer") -> Value = nomer_s;
                        DM3 -> FDQuery3 -> ParamByName ("n_object") -> Value =
                            StrToInt (mas_svod_nado[0][i]);
                        DM3 -> FDQuery3 -> Open ();

                        n_ball = DM3 -> FDQuery3 -> RecordCount;
                        int *balls = new int[n_ball];
                        // ���������� ������, � ������� ���������� ��� ������ �� ��������

                        for (int i = 0; i < n_ball; i++) {
                            balls[i] = DM3 -> FDQuery3 -> FieldValues["result"];

                            if (balls[i] == 1)

                                zachet = zachet + 1;
                            // ������������ ���-�� ������� �� ��������

                            if ( (zachet > 1) & (balls[i] == 1))
                                // ���� ��������� ���� �����, ��
                                // �� ������ ��� � ������
                                    ocenky = ocenky;

                            else
                                ocenky =
                                    ocenky + ball_string (syst_ball,
                                ball_int (syst_ball, balls[i]), 1) + ',' + " ";

                            DM3 -> FDQuery3 -> Next ();
                        }

                        ocenky.Delete (ocenky.Length (), 1);
                        // ����� ������ ��������� ������ ������� �������
                        ocenky.Delete (ocenky.Length (), 1); // � ������

                        Cell_2_Text_Ole2 (5, 5, str_r, true, "Arial", 10, false,
                            align_b, 2, 0, false, false, ocenky);

                        delete balls;
                    }
                }
            } // end if �� ���
            else { // ���
                // ������ �� ����
                DM3 -> GEK_VipiskaFDQuery -> Close ();
                DM3 -> GEK_VipiskaFDQuery -> SQL -> Clear ();
                DM3 -> GEK_VipiskaFDQuery -> SQL -> Add ("SELECT Gek.NOMER_GEK, Gek.NOMER, Gek.N_VED,\
                 Gek.THEME, Gek.D_GEK, Gek.BALL_GEK, Gek.N_PROTOCOL,\
                 Gek.D_PROTOCOL, Vedomost_gek.N_PLAN, Edu_plan.N_OBJECT, Object_plan.NAME_OBJECT \
                 FROM GEK Gek   \
                 INNER JOIN VEDOMOST_GEK Vedomost_gek \
                 ON  (Gek.N_VED = Vedomost_gek.N_VED) \
                 INNER JOIN EDU_PLAN Edu_plan   \
                 ON  (Vedomost_gek.N_PLAN = Edu_plan.N_PLAN)  \
                 INNER JOIN OBJECT_PLAN Object_plan \
                 ON  (Edu_plan.N_OBJECT = Object_plan.N_OBJECT)    \
                 where Gek.NOMER=:NOMER  \
                 and Gek.BALL_GEK<>6 and Gek.BALL_GEK<>2 and Gek.BALL_GEK<>11 and Gek.BALL_GEK<>12 and Gek.BALL_GEK<>13 \
                 and Edu_plan.N_OBJECT=:N_OBJECT  and edu_plan.zach_exam in (" +
                    control + ")");
                DM3 -> GEK_VipiskaFDQuery -> ParamByName ("NOMER") -> Value = nomer_s;
                DM3 -> GEK_VipiskaFDQuery -> ParamByName ("N_OBJECT") -> Value =
                    mas_svod_nado[0][i];
                DM3 -> GEK_VipiskaFDQuery -> Open ();

                if (mas_svod_nado[1][i] == "5") {
                    thema_diplom = DM3 -> GEK_VipiskaFDQueryTHEME -> Value;
                    ochenka_diplom =
                        ball_string (syst_ball,
                        ball_int (syst_ball,
                        DM3 -> GEK_VipiskaFDQueryBALL_GEK -> Value), 1);
                }

                Cell_2_Text_Ole2 (5, 5, str_r, true, "Arial", 10, false, align_b,
                    2, 0, false, false, ball_string (syst_ball,
                    ball_int (syst_ball,
                    DM3 -> GEK_VipiskaFDQueryBALL_GEK -> Value), 1));

                Str_11 = Text_predmet (mas_svod_nado[3][i],
                    DM3 -> People_SvodFDQueryN_SPECIALIZ -> Value);
            }

            Str_10 = ocenky;
            len_str10 = Str_10.Length ();
            len_str11 = Str_11.Length ();

            if (len_str10 * 3 > len_str11) {
                max_len_str = len_str10 * 3;
            }
            else
                max_len_str = len_str11;

            // ����������
            AnsiString diap = mas_column[1] + str_r + ":" +
                mas_column[3] + str_r;
            Variant Rang = App_n.OlePropertyGet ("Range", WideString (diap));

            int rowheight = 15;
            if (Str_1.Length () > 50)
                rowheight = 25;

            if (max_len_str < 69) {
                Rang.OlePropertySet ("RowHeight", rowheight);
            }

            if ( (max_len_str >= 69) & (max_len_str < 138)) {
                Rang.OlePropertySet ("RowHeight", 30);
            }

            if ( (max_len_str >= 138) & (max_len_str < 207)) {
                Rang.OlePropertySet ("RowHeight", 45);
            }

            if (max_len_str >= 207) {
                Rang.OlePropertySet ("RowHeight", 60);
            }

            Variant d16;
            d16 = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", str_r, 5);
            d16.OlePropertySet ("HorizontalAlignment", 3);
            d16.OlePropertySet ("VerticalAlignment", 4);

            str_r++;
            nom_predmet++;
        }
    }
    for (int i = 0; i < 3; i++)
        delete[]mas_real[i];
}

void __fastcall TDiplomForm::Predmet_svod (int col, AnsiString control, int stat)
{ // ������� ��� ��������� ��������� � ������� ���������
    // int col  - ���������� ������� � �������
    // int control - ��� �������� (�������, �����, ���.�����, ���, ���)
    // int stat - ������ (0 - �������, 1 - ����.����, �����������, ��������, ��������

    for (int i = 0; i < col; i++) { // for �������, �����, ���.�����, ���, ���
        if (!stat) { // if stat=0

            if (mas_svod_nado[1][i] == control && mas_svod_nado[2][i] == "0") {
                mas_svod_nado[4][i] = AnsiString (nom_predmet + 2);
                Cell_2_Text_Ole2 (nom_predmet + 2, nom_predmet + 2, str_r, true,
                    "Arial", 10, false, 3, 0, 90, false, false,
                    mas_svod_nado[3][i]);
                Cell_2_Text_Ole2 (nom_predmet + 2, nom_predmet + 2, str_r + 1,
                    true, "Arial", 10, false, 3, 2, 0, false, false,
                    IntToStr (nom_predmet));

                nom_predmet++;
            }

        } // end if stat=0
        else { // else stat=1
            if (mas_svod_nado[2][i] == control) {
                mas_svod_nado[4][i] = AnsiString (nom_predmet + 2);
                Cell_2_Text_Ole2 (nom_predmet + 2, nom_predmet + 2, str_r, true,
                    "Arial", 10, false, 3, 0, 90, false, false,
                    mas_svod_nado[3][i]);
                Cell_2_Text_Ole2 (nom_predmet + 2, nom_predmet + 2, str_r + 1,
                    true, "Arial", 10, false, 3, 2, 0, false, false,
                    IntToStr (nom_predmet));

                nom_predmet++;
            }
        } // end else stat=1
    } // for �������, �����, ���.�����, ���, ���
}

void __fastcall TDiplomForm::RadioGroup2Click (TObject *Sender) {
    if (RadioGroup2 -> ItemIndex != -1) {
        DM3 -> Check_Add_Group (RadioGroup1 -> ItemIndex,
            (RadioGroup2 -> ItemIndex + 1), CheckListBox1);
        Panel2 -> Visible = true;
        Panel3 -> Visible = false;
        RadioGroup3 -> Visible = false;
        Label1 -> Visible = false;
        DateTimePicker1 -> Visible = false;
    }
}

void __fastcall TDiplomForm::BitBtn1Click (TObject *Sender)
{ // ������ ������� � �������
    AnsiString inc_gr = DM3 -> Check_Return_Group (RadioGroup1 -> ItemIndex,
        CheckListBox1);

    if (inc_gr == "") { // �������� �� ��������
        ShowMessage ("�� �� ������� ����� ������!");
        return;
    }

    // ������������ Query
    DataModule1 -> People_KursFDQuery -> Close ();
    DataModule1 -> People_KursFDQuery -> SQL -> Clear ();
    DataModule1 -> People_KursFDQuery -> SQL -> Add ("SELECT NOMER, FAM, NAME, OTCH, \
KURS, INC_GROUP, STATUS_KURS, N_GROUP, STATUS_PEOPLE  \
FROM PEOPLE People WHERE (INC_GROUP in (" + inc_gr + ")) \
AND STATUS_PEOPLE = 1 \
ORDER BY N_GROUP, FAM, NAME, OTCH");
    DataModule1 -> People_KursFDQuery -> Open ();

    DualListDlg = new TDualListDlg (this);
    DualListDlg -> SrcList -> Items -> Clear ();
    DualListDlg -> DstList -> Items -> Clear ();
    // ��� ���������
    for (int i = 0; i < DataModule1 -> People_KursFDQuery -> RecordCount; i++) {
        DualListDlg -> SrcList -> Items -> AddObject
            (DataModule1 -> People_KursFDQueryFAM -> Value + " " +
            DataModule1 -> People_KursFDQueryNAME -> Value + " " +
            DataModule1 -> People_KursFDQueryOTCH -> Value + " " +
            DataModule1 -> People_KursFDQueryN_GROUP -> Value + " ��.",
            (TObject *) (DataModule1 -> People_KursFDQueryNOMER -> Value));
        DataModule1 -> People_KursFDQuery -> Next ();
    } // for

    DualListDlg -> ShowModal ();

    if (DataModule2 -> printdlg == true) { // if MyList1 -> Execute
        AnsiString Str_Nomer = "";
        for (int i = 0; i <= DualListDlg -> DstList -> Items -> Count - 1; i++) {
            Str_Nomer +=
                String ( (int) (DualListDlg -> DstList -> Items -> Objects[i])) + ",";
            // ���������� ����� ��������
        } // 1-�� for
        delete DualListDlg;
        Str_Nomer.SetLength (Str_Nomer.Length () - 1);

        DM3 -> People_SvodFDQuery -> Close ();
        DM3 -> People_SvodFDQuery -> SQL -> Clear ();
        DM3 -> People_SvodFDQuery -> SQL -> Add ("SELECT People.NOMER, People.FAM, People.NAME, People.OTCH, \
   People.POL, People.VID_EDU, People.N_FAC, \
   People.KURS, People.N_SPEC, People.N_SPECIALIZ, People.N_PRIKAZ_KURS, \
   People.N_FOUND, People.N_FOUND_INCLUDE, People.N_PRIKAZ_INCLUDE, People.D_PRIKAZ_INCLUDE, \
   People.N_GROUP, People.STATUS_PEOPLE, People.INC_GROUP,  \
   Speciality.SPEC, Specializ.SPECIAL, Specializ.SPECIAL_SKLON, Specializ.SPECIAL_DIRECTION, Faculty.FAC, Faculty.FAC1 \
   FROM PEOPLE People \
   INNER JOIN SPECIALITY Speciality ON  (People.N_SPEC = Speciality.N_SPEC) \
   INNER JOIN SPECIALIZ Specializ   ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ)   \
   INNER JOIN FACULTY Faculty ON  (People.N_FAC = Faculty.N_FAC) \
   where (People.NOMER IN (" + Str_Nomer + "))\
   Order by  People.N_SPECIALIZ, People.FAM, People.NAME, People.OTCH");
        DM3 -> People_SvodFDQuery -> Open ();

        // ���������  Exel
        DataModule1 -> ExelInit ();
        // ������ ���������� ������ � �����
        App_n.OlePropertySet ("SheetsInNewWorkbook", 1);

        int n_specializ = 0; // �������������
        int j = 0; // �������

        for (int i = 0; i < DM3 -> People_SvodFDQuery -> RecordCount;
        i++) // ������������ ������ � ����������� �� ���-�� ������!!
        {
            fam = DM3 -> People_SvodFDQueryFAM -> Value + String (i + 1);

            App_n.OlePropertyGet ("WorkSheets").OleProcedure ("add");
            Sh = App_n.OlePropertyGet ("WorkSheets").OlePropertyGet ("Item", 1);
            Sh.OlePropertySet ("Name", WideString (fam));

            Sh = App_n.OlePropertyGet ("ActiveSheet");
            str_r = 1;

            int nom = DM3 -> People_SvodFDQueryNOMER -> Value;

            if (n_specializ != DM3 -> People_SvodFDQueryN_SPECIALIZ -> Value) {
                god_first = uch_god - (DM3 -> People_SvodFDQueryKURS -> Value - 1);
                n_specializ = DM3 -> People_SvodFDQueryN_SPECIALIZ -> Value;
                AnsiString sql_2[2] = {
                    " and ( (Edu_plan.semestr in (1,2) and  Edu_plan.year_plan=" +
                        AnsiString (god_first) + " ) or \
               (Edu_plan.semestr in (3,4) and  Edu_plan.year_plan=" +
                        AnsiString (god_first + 1) + " ) or \
               (Edu_plan.semestr in (5,6) and Edu_plan.year_plan=" +
                        AnsiString (god_first + 2) + " ) or \
               (Edu_plan.semestr in (7,8) and  Edu_plan.year_plan=" +
                        AnsiString (god_first + 3) + " ))",

                    "and ( (Edu_plan.semestr in (1,2) and  Edu_plan.year_plan=" +
                        AnsiString (god_first) + " ) or \
               (Edu_plan.semestr in (3,4) and  Edu_plan.year_plan=" +
                        AnsiString (god_first + 1) + " ) or \
               (Edu_plan.semestr in (5,6) and Edu_plan.year_plan=" +
                        AnsiString (god_first + 2) + " ) or \
               (Edu_plan.semestr in (7,8) and  Edu_plan.year_plan=" +
                        AnsiString (god_first + 3) + " )  or \
               (Edu_plan.semestr in (9,10) and  Edu_plan.year_plan=" +
                        AnsiString (god_first + 4) + " ))"};

                DM3 -> Svod_NadoFDQuery -> Close ();
                DM3 -> Svod_NadoFDQuery -> SQL -> Clear ();
                DM3 -> Svod_NadoFDQuery -> SQL -> Add
                    (sql_1 + sql_2[RadioGroup1 -> ItemIndex] + sql_3);
                DM3 -> Svod_NadoFDQuery -> ParamByName ("N_FAC") -> AsSmallInt =
                    nom_fac;
                DM3 -> Svod_NadoFDQuery -> ParamByName ("VID_EDU") -> AsSmallInt =
                    RadioGroup1 -> ItemIndex;
                DM3 -> Svod_NadoFDQuery -> ParamByName ("SPECIALIZ") -> AsInteger =
                    n_specializ;
                DM3 -> Count_Svod_NadoFDQuery -> Close ();
                DM3 -> Count_Svod_NadoFDQuery -> SQL -> Clear ();
                DM3 -> Count_Svod_NadoFDQuery -> SQL -> Add
                    (count_sql_1 + sql_2[RadioGroup1 -> ItemIndex] + count_sql_3);
                DM3 -> Count_Svod_NadoFDQuery -> ParamByName ("N_FAC") -> AsSmallInt =
                    nom_fac;
                DM3 -> Count_Svod_NadoFDQuery -> ParamByName ("VID_EDU")
                    -> AsSmallInt = RadioGroup1 -> ItemIndex;
                DM3 -> Count_Svod_NadoFDQuery -> ParamByName ("SPECIALIZ")
                    -> AsInteger = n_specializ;
                DM3 -> Svod_NadoFDQuery -> Open ();
                DM3 -> Count_Svod_NadoFDQuery -> Open ();
                // --------
                for (int i = 0; i < 6; i++) { // for1
                    mas_svod_nado[i] =
                        new AnsiString[DM3 -> Count_Svod_NadoFDQueryCOUNT -> Value];
                } // end for 1

                j = 0; // �������
                int pr1 = 0; // ����� ��������
                for (int i = 0;
                i < DM3 -> Count_Svod_NadoFDQueryCOUNT -> Value; i++) { // for2

                    if (pr1 != DM3 -> Svod_NadoFDQueryN_OBJECT -> Value)
                    { // if ��������� �������
                        mas_svod_nado[0][j] =
                            AnsiString (DM3 -> Svod_NadoFDQueryN_OBJECT -> Value);
                        // ����� ��������
                        mas_svod_nado[1][j] =
                            AnsiString (DM3 -> Svod_NadoFDQueryZACH_EXAM -> Value);
                        // ��� ��������
                        mas_svod_nado[2][j] =
                            AnsiString (DM3 -> Svod_NadoFDQuerySPECKURS -> Value);
                        // spec_kurs
                        mas_svod_nado[3][j] =
                            DM3 -> Svod_NadoFDQueryNAME_OBJECT -> Value;
                        // �������� ��������
                        mas_svod_nado[4][j] =
                            AnsiString (DM3 -> Svod_NadoFDQueryCLOCK_PLAN_ALL
                            -> Value);
                        // ��� ����� ���-�� �����
                        mas_svod_nado[5][j] =
                            AnsiString (DM3 -> Svod_NadoFDQueryCLOCK_PLAN -> Value);
                        // ������� ����� ���-�� �.�.
                        pr1 = DM3 -> Svod_NadoFDQueryN_OBJECT -> Value;
                        j++;
                    } // end  if ��������� �������
                    else { // else ���� �� ������� � ���� ����������� � ������
                        mas_svod_nado[4][j - 1] =
                            AnsiString (StrToInt (mas_svod_nado[4][j - 1]) +
                            DM3 -> Svod_NadoFDQueryCLOCK_PLAN_ALL -> Value); // ���
                        mas_svod_nado[5][j - 1] =
                            AnsiString (FormatFloat ("0.0",
                            StrToFloat (mas_svod_nado[5][j - 1]) +
                            DM3 -> Svod_NadoFDQueryCLOCK_PLAN -> Value)); // �������
                    } // end else ���� �� ������� � ���� ����������� � ������
                    DM3 -> Svod_NadoFDQuery -> Next ();
                } // end for 2
            }

            // -----������

            // ������ �������������� ������������ ��������
            Sh.OlePropertyGet ("PageSetup").OlePropertySet
                ("CenterHorizontally", true);
            Sh.OlePropertyGet ("PageSetup").OlePropertySet ("Zoom", false);
            Sh.OlePropertyGet ("PageSetup").OlePropertySet ("FitToPagesWide", 1);
            Sh.OlePropertyGet ("PageSetup").OlePropertySet ("FitToPagesTall", 2);
            // ����
            Sh.OlePropertyGet ("PageSetup").OlePropertySet ("TopMargin", 46);
            Sh.OlePropertyGet ("PageSetup").OlePropertySet ("BottomMargin", 46);
            Sh.OlePropertyGet ("PageSetup").OlePropertySet ("LeftMargin", 52);
            Sh.OlePropertyGet ("PageSetup").OlePropertySet ("RightMargin", 52);

            // ������ �������
            Variant d;
            d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 1, 1);
            d.OlePropertySet ("ColumnWidth", 5);

            int srift = 12; // ����� ��� �������

            if (j > 73) { // if ����� ���������
                d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 1, 2);
                d.OlePropertySet ("ColumnWidth", 57);
                srift = 13; // ����� ��� �������
            }
            else {
                d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 1, 2);
                d.OlePropertySet ("ColumnWidth", 57);
            }

            d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 1, 3);
            d.OlePropertySet ("ColumnWidth", 13);
            d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 1, 4);
            d.OlePropertySet ("ColumnWidth", 10);
            d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 1, 5);
            d.OlePropertySet ("ColumnWidth", 19); // ���

            // ������ ������
            Cell_2_Text_Ole2 (1, 5, str_r, false, "TimesNewRoman", 10, false, 4,
                0, 0, true, false, "���������� � �������  A � _____________");
            str_r++;
            // ������ ������
            Cell_2_Text_Ole2 (1, 5, str_r, false, "TimesNewRoman", srift, true,
                3, 0, 0, true, false,
                "������� �� �������-��������������� ���������");
            str_r++;
            d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 2, 2);
            d.OlePropertySet ("RowHeight", 24);
            // ������ ������
            Cell_2_Text_Ole2 (1, 5, str_r, false, "TimesNewRoman", srift, false,
                3, 0, 0, true, false, " (��� ������� ���������������)");
            str_r++;
            str_r++;

            // ���������� ������
            // ����������� ���� ��������
            AnsiString St1 = "";
            AnsiString St2 = "";
            AnsiString St3 = "";
            AnsiString St4 = "";
            AnsiString St5 = "";
            AnsiString St6 = "";
            AnsiString St7 = "", St8 = "", St9 = "";
            if (DM3 -> People_SvodFDQueryPOL -> Value == "�") {
                St1 = "���������";
                St2 = "�����";
                St3 = "���������";
                St4 = "��������";
                St5 = "���������";
                St6 = "������";
                St7 = "�� ���������";
                St8 = "�������"; // ��� 2012 ����
                St9 = "��������";
            }
            else {
                St1 = "��������";
                St2 = "����";
                St3 = "�������";
                St4 = "�������";
                St5 = "��������";
                St6 = "������";
                St7 = "�� ��������";
                St8 = "������"; // ��� 2012 ����
                St9 = "�������";
            }

            // ����� ������
            AnsiString St = "      ";
            // ���������� ������������ ��������� ������� ��� ������� � �������
            // ���
            St += DM3 -> People_SvodFDQueryFAM -> Value + " " +
                DM3 -> People_SvodFDQueryNAME -> Value + " " +
                DM3 -> People_SvodFDQueryOTCH -> Value;

            // ���������� ��� ����������� ����� ������ ��� ���
            int len_St = St.Length ();

            // ���� ��������
            St += " �� ����� �������� � ";
            Variant V = SQLTimeStampToDateTime
                (DM3 -> People_SvodFDQueryD_PRIKAZ_INCLUDE -> Value);
            AnsiString god_postupl = V.AsType (varString);

            // ��� ��������� ������ �����
            int found_include = DM3 -> People_SvodFDQueryN_FOUND_INCLUDE -> Value;

            switch (found_include) {
            case 9: // ������� �� ������� ����
                DM3 -> Perevod_VUZFDQuery -> Close ();
                DM3 -> Perevod_VUZFDQuery -> ParamByName ("NOMER") -> AsInteger =
                    DM3 -> People_SvodFDQueryNOMER -> Value;
                DM3 -> Perevod_VUZFDQuery -> Open ();
                if (!DM3 -> Perevod_VUZFDQuery -> RecordCount)
                    St += "!!!!! ��� ������� �������� �� ������� ���� !!!! � ";
                else {
                    St += DM3 -> Perevod_VUZFDQueryDESCRIBE -> Value + " � ";
                    V = SQLTimeStampToDateTime
                        (DM3 -> Perevod_VUZFDQueryD_PUBLIC_PRIKAZ -> Value);
                }
                break;
            case 11: // �������������� �� ������� ����
                DM3 -> Vosstanovlenie_VUZFDQuery -> Close ();
                DM3 -> Vosstanovlenie_VUZFDQuery -> SQL -> Clear ();
                DM3 -> Vosstanovlenie_VUZFDQuery -> SQL -> Add ("select * from restore r   \
                                                   where r.n_cause_restore=17  \
                                                   and r.vid_restore=0 \
                                                   and r.NOMER=:NOMER");
                DM3 -> Vosstanovlenie_VUZFDQuery -> ParamByName ("NOMER")
                    -> AsInteger = DM3 -> People_SvodFDQueryNOMER -> Value;
                DM3 -> Vosstanovlenie_VUZFDQuery -> Open ();
                if (!DM3 -> Vosstanovlenie_VUZFDQuery -> RecordCount)
                    St += "!!!! ��� ������� � �������������� �� ������� ���� !!!! � ";
                else {
                    St += DM3 -> Vosstanovlenie_VUZFDQueryDESCRIBE -> Value + " � ";
                    V = SQLTimeStampToDateTime
                        (DM3 -> Vosstanovlenie_VUZFDQueryD_PRIKAZ_RES -> Value);
                }
                break;
            }

            int date_include = V.AsType (varInteger);

            // ---����--- �������� �� ���� ���������, � �������� ������
            DataModule1 -> Prikaz_LikvidFDQuery -> Close ();
            DataModule1 -> Prikaz_LikvidFDQuery -> SQL -> Clear ();
            DataModule1 -> Prikaz_LikvidFDQuery -> SQL -> Add
                ("SELECT * FROM PRIKAZ_LIKVID WHERE PRIKAZ_LIKVID.NOMER=:NOMER AND (PRIKAZ_LIKVID.N_TYPE_LIKVID=1 OR PRIKAZ_LIKVID.N_TYPE_LIKVID=5) and PRIKAZ_LIKVID.fac_do!=PRIKAZ_LIKVID.fac_po"
                );
            DataModule1 -> Prikaz_LikvidFDQuery -> ParamByName ("NOMER") -> AsInteger =
                DM3 -> People_SvodFDQueryNOMER -> Value;
            DataModule1 -> Prikaz_LikvidFDQuery -> Open ();
            if (DataModule1 -> Prikaz_LikvidFDQuery -> RecordCount > 0) {
                if (date_include) { // if �������� �� �������� �������� ����
                    if (date_include <= 33696) // ��� ���� 02.04.1992
                            St += "����������� ��������������� ������ ��������� �������� ������� ��������� ���������� ��������, ����� ��������� ����������� ����������� ";

                    if (date_include > 33696 && date_include <= 36966)
                        // ��� ���� c 02.04.1992  �� 16.03.2001
                            St += "�������� ����������� ���������� � ������ ���������� ��������, ����� ��������� ����������� ����������� ";

                    if (date_include > 36966 && date_include <= 37978)
                        // ��� ���� c 16.03.2001  �� 23.12.2003
                            St += "����������� ��������������� �������� ���������� ��������, ����� ��������� ����������� ����������� ";

                    if (date_include > 37978) // ��� ���� ����� 23.12.2003
                    {
                        St += "���������� ����������� ";
                    }
                } // end if �������� �� �������� �������� ����

                else
                    St += "!!!!!!!! � ��� �� ������� ���� ����������� � ���, ";

                // ----
                St += "\"����������� ��������������� ����������� ���������� ��������\" ";

                // ���������
                switch (DataModule1 -> Prikaz_LikvidFDQueryFAC_DO -> Value) {
                case 1:
                    St += "�� ���������-�������������� ���������� ���������� ��� � ����������� � ";
                    break;
                case 2:
                    St += "�� ���������-�������������� ���������� �������� ����� ������ � ";
                    break;
                case 3:
                    St += "�� ���������� ��������������� ���������� �������� � ������� � ";
                    break;
                case 4:
                    St += "�� ���������� ����������� ������, ������� � �������������� ��������� ����������� ������ � ������� � ";
                    break;
                }
            }
            // ----����----

            // ���

            if (date_include) { // if �������� �� �������� �������� ����
                if (date_include <= 33696) // ��� ���� 02.04.1992
                        St += "����������� ��������������� ������ ��������� �������� ������� ��������� ���������� ��������, ����� ��������� ����������� ����������� ";

                if (date_include > 33696 && date_include <= 36966)
                    // ��� ���� c 02.04.1992  �� 16.03.2001
                        St += "�������� ����������� ���������� � ������ ���������� ��������, ����� ��������� ����������� ����������� ";

                if (date_include > 36966 && date_include <= 37978)
                    // ��� ���� c 16.03.2001  �� 23.12.2003
                        St += "����������� ��������������� �������� ���������� ��������, ����� ��������� ����������� ����������� ";

                // ��������� ��� ��� ��
                if (date_include > 37978)
                    // ��� ���� ����� 23.12.2003
                {
                    St += "���������� ����������� ";
                }

            } // end if �������� �� �������� �������� ����

            else
                St += "!!!!!!!! � ��� �� ������� ���� ����������� � ���, ";

            // ----
            St += "\"����������� ��������������� ����������� ���������� ��������\" ";

            // if (nom_fac==4) St+="�������� �������, ";

            // ���������
            switch (nom_fac) {
            case 1:
                St += "�� ���������-�������������� ���������� ���������� ��� � ����������� � ";
                break;
            case 2:
                St += "�� ���������-�������������� ���������� �������� ����� ������ � ";
                break;
            case 3:
                St += "�� ���������� ��������������� ���������� �������� � ������� � ";
                break;
            case 4:
                St += "�� ���������� ����������� ������, ������� � �������������� ��������� ����������� ������ � ������� � ";
                break;
                // case 4: St+="�� ���������� ������� � �������������� ��������� ������� � "; break;
            }
            // ���� �������� � ����
            if (date_include)
                St += god_postupl.SubString (7, 4) + " ���� �� " +
                    IntToStr (uch_god + 1) + " ��� ";
            else {
                St += AnsiString (god_first);
                St += " ����  �� " + IntToStr (uch_god + 1) + " ��� ";
            }

            // ������������� ��� ����������� �������������

            if (DM3 -> People_SvodFDQueryN_SPEC -> Value == 1)
            { // if ������������� ���������� �������� � �����
                // �������������
                St += DM3 -> People_SvodFDQuerySPEC -> Value;
                St += "\", ������������� ";
                St += "\"";
                if (nom_fac == 1 || nom_fac == 2) {
                    St += "���������� ������ �� ";
                }
                St += DM3 -> People_SvodFDQuerySPECIAL_SKLON -> Value;
            } // end if ������������� ���������� �������� � �����
            else { // else ������ ����� �������������
                if (DM3 -> People_SvodFDQueryN_SPEC -> Value == 10 &&
                    DM3 -> People_SvodFDQueryVID_EDU -> Value == 0) {
                    St += "�� ������������� \"������ � ��������������\", ������������� \""
                        + DM3 -> People_SvodFDQuerySPECIAL_DIRECTION -> Value
                        + "\"";
                }
                else
                    St += "�� ������������� \"" +
                        DM3 -> People_SvodFDQuerySPECIAL_DIRECTION -> Value + "\"";
            } // else ������ ����� �������������

            St += " " + St8 + " ���������� � " + St9 + " ��������� ������:";

            Cell_2_Text_Ole2 (1, 5, str_r, false, "TimesNewRoman", srift, false,
                6, 1, 0, true, true, St);

            // ����� ��������� �������

            // ���������� � ���������� ������ � ������� Start ������� Length ������ �����
            d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", str_r, 1);
            d.OlePropertyGet ("Characters", 1, len_St).OlePropertyGet ("Font")
                .OlePropertySet ("FontStyle", L"����������");

            // ��������� ������ ������
            if (nom_fac == 4) {
            d.OlePropertySet ("RowHeight", 85);
            } else
            d.OlePropertySet ("RowHeight", 70);
            str_r++;

            // ���������� �������� ������
            /* AnsiString temp_text = "$" + AnsiString (str_r) + ":$" +
             AnsiString (str_r);
             Sh.OlePropertyGet ("PageSetup").OlePropertySet ("PrintTitleRows",
             WideString (temp_text)); */

            // �����
            Shapka_Diplom (
                "�������� ��������� � ������������� ������� ���������", true);
            str_r++;

            nom_predmet = 1; // ������� ���������

            create_vid_control (nom, j, "2", 0); // ��������
            create_vid_control (nom, j, "3", 0); // ���.������
            create_vid_control (nom, j, "1", 0); // ������
            create_vid_control (nom, j, "0", 0);
            str_r++;

            // ������� (��) ��� �������� (�)
            /* Cell_2_Text_Ole2 (1,4,str_r,false,"Arial",12,false,0,2,0,true,false,
             St3+" "+DM3 -> People_SvodFAM -> Value+" "+DM3 -> People_SvodNAME -> Value+
             " "+DM3 -> People_SvodOTCH -> Value); */
            // str_r++;

            // ���������
            int spec = 0;
            for (int i = 0; i < DM3 -> Count_Svod_NadoFDQueryCOUNT -> Value; i++) {
                if (mas_svod_nado[2][i] == 1)
                    spec++;
            }
            if (spec != 0)
                // ���������, �.�. �� � ���� ����������� ���� ���������
            {
                if (RadioGroup1 -> ItemIndex == 0)
                { // if ��������� ������ ��� ��������
                    // Cell_2_Text_Ole2 (1,4,str_r,false,"TimesNewRoman",12,false,0,2,0,true,false,St1+" ���������:"); str_r++;
                    // �����
                    Shapka_Diplom (
                        "�������� ��������� � ������������� ����������", true);
                    str_r++;
                    nom_predmet = 1; // ������� ���������
                    create_vid_control (nom, j, "2", 1); // ��������
                    create_vid_control (nom, j, "3", 1); // ���.������
                    create_vid_control (nom, j, "1", 1); // ������
                    create_vid_control (nom, j, "0", 1);
                    str_r++;
                } // end if ��������� ������ ��� ��������
            }

            // �������� ������
            // Cell_2_Text_Ole2 (1,4,str_r,false,"TimesNewRoman",12,false,0,2,0,true,false,St4+" �������� ������:");  str_r++;
            // �����
            // Shapka_Diplom ("�������� �������� ����� (��������)",false);
            Shapka_Diplom ("�������� ������� ��������� �� ����������� �" + tab +
                "������������� �������� �������", true);
            str_r++;
            // ���� ��� �������� ������ ���
            nom_predmet = 1; // ������� ���������
            create_vid_control (nom, j, "2", 2); // ��������
            create_vid_control (nom, j, "3", 2); // ���.������
            create_vid_control (nom, j, "1", 2); // ������
            create_vid_control (nom, j, "0", 2);
            str_r++;
            // ��������
            // Cell_2_Text_Ole2 (1,4,str_r,false,"TimesNewRoman",12,false,0,2,0,true,false,St6+" � "+St4+" ��������:");  str_r++;

            // �����
            Shapka_Diplom ("�������� ���������� � ������������� �������", true);
            str_r++;
            nom_predmet = 1; // ������� ���������
            create_vid_control (nom, j, "2", 3); // ��������
            create_vid_control (nom, j, "3", 3); // ���.������
            create_vid_control (nom, j, "1", 3); // ������
            create_vid_control (nom, j, "0", 3);
            str_r++;
            // }
            // else   str_r++;

            // �����
            Shapka_Diplom ("�������� ��������� � ������������� �������������",
                true);
            str_r++;
            nom_predmet = 1; // ������� ���������
            create_vid_control (nom, j, "2", 4); // ��������
            create_vid_control (nom, j, "3", 4); // ���.������
            create_vid_control (nom, j, "1", 4); // ������
            create_vid_control (nom, j, "0", 4);
            str_r++;

            // �����
            Shapka_Diplom ("�������� ������� ���������, �� �������" + tab +
                "����� ��������������� ��������", true);
            str_r++;
            nom_predmet = 1; // ������� ���������
            create_vid_control (nom, j, "4", 5); // ��������
            create_vid_control (nom, j, "5", 5); // ��������
            str_r++;

            if (thema_diplom != "" && ochenka_diplom != "")
            { // ��������� ���� �������

                // ��������� ���
                Cell_2_Text_Ole2 (1, 5, str_r, false, "Arial", 12, false, 0, 2,
                    0, true, false, St5 + " ��������� ������ �� ����:");
                str_r++;

                Cell_2_Text_Ole2 (1, 5, str_r, false, "Arial", 12, false, 0, 2,
                    0, true, true, "\"" + thema_diplom + "\"");
                // �������� �������� ��� ��������� ������ ������
                d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", str_r, 1);
                // ��������� ������ ������
                d.OlePropertySet ("RowHeight", 40);
                d.OlePropertyGet ("Font").OlePropertySet ("Italic", True);
                d.OlePropertyGet ("Font").OlePropertySet ("Underline", 2);
                // ��������� ������
                AnsiString two_str = "� " + St4 + " � �������� ";
                int dlina = two_str.Length ();
                str_r++;
                // �������� ��������
                d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", str_r, 1);
                Cell_2_Text_Ole2 (1, 5, str_r, false, "Arial", 12, false, 0, 2,
                    0, true, false, two_str + ochenka_diplom + ".");
                d.OlePropertyGet ("Characters", dlina,
                    ochenka_diplom.Length () + 1).OlePropertyGet ("Font")
                    .OlePropertySet ("Italic", True);
                d.OlePropertyGet ("Characters", dlina,
                    ochenka_diplom.Length () + 1).OlePropertyGet ("Font")
                    .OlePropertySet ("Underline", 2);
                str_r++;
                str_r++;
                str_r++;

            } // if
            /* else { // ��� �������

             // ��������� ���
             AnsiString dip_net = St5 + " ��������� ������ �� ����: ";
             int dl = dip_net.Length ();
             // �������� ��������
             d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", str_r, 1);
             Cell_2_Text_Ole2 (1, 5, str_r, false, "Arial", 12, false, 0, 2,
             0, true, false, dip_net + St7);
             d.OlePropertyGet ("Characters", dl, St7.Length () + 1)
             .OlePropertyGet ("Font").OlePropertySet ("Italic", True);
             d.OlePropertyGet ("Characters", dl, St7.Length () + 1)
             .OlePropertyGet ("Font").OlePropertySet ("Underline", 2);

             // Border_IndentLeft (1,4,str_r,str_r, false, 4, 0);//���������� ������ �� ����
             // Cell_2_Text_Ole2 (1,4,str_r,false,"Arial",12,false,0,0,0,false,false,"� "+St4+" � �������� _______________ ");
             str_r++;
             str_r++;
             str_r++;
             } */

            // ��������
            thema_diplom == ""; // ���� ���������� �������
            ochenka_diplom = ""; // ������ �� ���������� �������

            // ��������� ����
            // Cell_2_Text_Ole2 (1,1,str_r+3,false,"Arial",12,true,0,0,0,false,false,"�.�. ");
            // Cell_2_Text_Ole2 (1,1,str_r+7,false,"Arial",10,false,0,0,0,false,false,"�.�����");

            str_r++;

            AnsiString data_full = DateToStr (DateTimePicker1 -> Date);
            AnsiString month = data_full.SubString (4, 2);
            switch (StrToInt (month)) { // switch
            case 1:
                month = " ������ ";
                break;
            case 2:
                month = " ������� ";
                break;
            case 3:
                month = " ����� ";
                break;
            case 4:
                month = " ������ ";
                break;
            case 5:
                month = " ��� ";
                break;
            case 6:
                month = " ���� ";
                break;
            case 7:
                month = " ���� ";
                break;
            case 8:
                month = " ������� ";
                break;
            case 9:
                month = " �������� ";
                break;
            case 10:
                month = " ������� ";
                break;
            case 11:
                month = " ������ ";
                break;
            case 12:
                month = " ������� ";
                break;
            } // end switch
            // Cell_2_Text_Ole2 (4,4,str_r+6,false,"Arial",10,false,0,0,0,false,false,"\""+data_full.SubString (1,2)+"\""+month+data_full.SubString (7,4)+" �.");
            Cell_2_Text_Ole2 (1, 1, str_r + 6, false, "Arial", 10, false, 0, 0,
                0, false, false, "�.�����  \"" + data_full.SubString (1, 2) +
                "\"" + month + data_full.SubString (7, 4) + " �.");

            Cell_2_Text_Ole2 (1, 1, str_r, false, "Arial", 11, true, 0, 0, 0,
                false, false, "������������ ���������� ����������� ");
            Cell_2_Text_Ole2 (4, 4, str_r, false, "Arial", 11, true, 0, 0, 0,
                false, false, "�.�.������");
            str_r++;
            Cell_2_Text_Ole2 (2, 2, str_r, false, "Arial", 11, false, 0, 0, 0,
                false, false,
                "                                                                        �.�. ");
            str_r++;

            // if (nom_fac==4)
            // Cell_2_Text_Ole2 (2,2,str_r,false,"Arial",12,true,0,0,0,false,false,"              �������� ��������� �������");

            Cell_2_Text_Ole2 (1, 1, str_r, false, "Arial", 11, true, 0, 0, 0,
                false, false, "����� ���������� ");

            AnsiString dec_f = "", met_f = "";
            int v_edu = DM3 -> People_SvodFDQueryVID_EDU -> Value;
            switch (nom_fac) { // switch ����� ����������
            case 1:
                dec_f = "�.�.��������";
                if (v_edu == 1)
                    met_f = "�.�.��������";
                else
                    met_f = "�.�.���������";
                break;
            case 2:
                dec_f = "�.�.����������";
                if (v_edu == 1)
                    met_f = "�.�.��������";
                else
                    met_f = "�.�.�����";
                break;
            case 3:
                dec_f = "�.�.���������";
                if (v_edu == 1) {
                    if (DM3 -> People_SvodFDQueryKURS -> Value == 6)
                        met_f = "�.�.�����";
                    else
                        met_f = "�.�.�����";
                }
                else
                    met_f = "�.�.���������";
                break;
            case 4:
                dec_f = "�.�.���������";
                if (v_edu == 1)
                    met_f = "�.�.���������";
                else
                    met_f = "�.�.�������";
                break;
            }
            Cell_2_Text_Ole2 (4, 4, str_r, false, "Arial", 11, true, 0, 0, 0,
                false, false, dec_f);
            str_r++;
            str_r++;
            Cell_2_Text_Ole2 (1, 1, str_r, false, "Arial", 11, true, 0, 0, 0,
                false, false, "��������� ����������");
            Cell_2_Text_Ole2 (4, 4, str_r, false, "Arial", 11, true, 0, 0, 0,
                false, false, met_f);
            str_r++;
            str_r++;
            // str_r++; str_r++;  str_r++; str_r++;
            // Cell_2_Text_Ole2 (3,3,str_r,false,"Arial",10,false,4,0,0,false,false,"��������������� �");

            Cell_2_Text_Ole2 (4, 4, str_r, false, "Arial", 10, false, 4, 0, 0,
                false, false, "��������������� �");

            AnsiString reg = ""; // ��������������� �����
            // ������   0810/       08-��� �������,  1 (1.2.0.4) ���������, 0 (0.1) ��� ��������
            reg = AnsiString (uch_god + 1).SubString (3, 2);
            if (nom_fac != 3)
                reg += AnsiString (nom_fac);
            else
                reg += "0"; // ��������� �����
            reg += AnsiString (RadioGroup1 -> ItemIndex);
            reg += "/";

            Cell_2_Text_Ole2 (5, 5, str_r, false, "Arial", 10, false, 0, 0, 0,
                false, false, reg);
            Border_IndentLeft (5, 5, str_r, str_r, false, 4, 0);
            // ���������� ������ �� ����
            str_r++;
            str_r++;

            DM3 -> People_SvodFDQuery -> Next ();
        }
        // App_n.OlePropertySet ("Visible", True);
        App_n.Clear ();
        Sh.Clear ();
        for (int i = 0; i < 5; i++)
            delete[]mas_svod_nado[i];

    } // end if MyList1 -> Execute

}

void __fastcall TDiplomForm::RxCheckListBox1Click (TObject *Sender) {
    Panel3 -> Visible = true;
    RadioGroup3 -> Visible = true;
    Label1 -> Visible = true;
    DateTimePicker1 -> Visible = true;

}

void __fastcall TDiplomForm::RadioGroup3Click (TObject *Sender)
{ // �� ���������� ���������� ������������� �������
    switch (RadioGroup3 -> ItemIndex)
    { // switch ������������ ����� ��������� ������
    case 0:
        syst_ball = 10; // ������������� �������
        break;
    case 1:
        syst_ball = 5; // ����������� �������
        break;
    } // end switch ������������ ����� ��������� ������
}

void __fastcall TDiplomForm::BitBtn2Click (TObject *Sender)
{ // ������ ������� ���������
    AnsiString inc_gr = DM3 -> Check_Return_Group (RadioGroup1 -> ItemIndex,
        CheckListBox1);
    if (inc_gr == "") { // �������� �� ��������
        ShowMessage ("�� �� ������� ����� ������!");
        return;
    }

    DM3 -> Name_SpecFDQuery -> Close ();
    DM3 -> Name_SpecFDQuery -> SQL -> Clear ();
    DM3 -> Name_SpecFDQuery -> SQL -> Add ("SELECT Distinct ( Specializ.N_SPECIALIZ), Specializ.SPECIAL \
FROM PEOPLE People \
   INNER JOIN INCREMENT_GROUP Increment_group \
   ON  (People.INC_GROUP = Increment_group.INC_GROUP)  \
   INNER JOIN FACULTY Faculty \
   ON  (People.N_FAC = Faculty.N_FAC)  \
   INNER JOIN SPECIALIZ Specializ  \
   ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) \
where (People.STATUS_PEOPLE=1) and (People.INC_GROUP in (" + inc_gr + ")) \
and (People.N_FAC=" + nom_fac + ") \
ORDER BY Specializ.N_SPECIALIZ");
    DM3 -> Name_SpecFDQuery -> Open ();

    // ������������ �������� ������� �������������
    AnsiString *mas_spec[2]; // ������ ������� � �������� �������������
    for (int i = 0; i < 2; i++)
        mas_spec[i] = new AnsiString[DM3 -> Name_SpecFDQuery -> RecordCount];
    //////////////////////////////////////////////////////////////////////////
    DualListDlg = new TDualListDlg (this);
    DualListDlg -> SrcList -> Items -> Clear ();
    DualListDlg -> DstList -> Items -> Clear ();
    // ��� ���������
    for (int i = 0; i < DM3 -> Name_SpecFDQuery -> RecordCount; i++) {
        mas_spec[0][i] = DM3 -> Name_SpecFDQuerySPECIAL -> Value;
        DualListDlg -> SrcList -> Items -> AddObject (mas_spec[0][i],
            (TObject *) (DM3 -> Name_SpecFDQueryN_SPECIALIZ -> Value));
        mas_spec[1][i] = AnsiString (DM3 -> Name_SpecFDQueryN_SPECIALIZ -> Value);
        DM3 -> Name_SpecFDQuery -> Next ();
    } // for

    DualListDlg -> ShowModal ();

    if (DataModule2 -> printdlg == true) { // if MyList1 -> Execute
        AnsiString Str_Nomer = "";
        for (int i = 0; i <= DualListDlg -> DstList -> Items -> Count - 1; i++) {
            Str_Nomer +=
                String ( (int) (DualListDlg -> DstList -> Items -> Objects[i])) + ",";
            // ���������� ����� �������������
        } // 1-�� for
        delete DualListDlg;
        Str_Nomer.SetLength (Str_Nomer.Length () - 1);

        DM3 -> People_SvodReport_SpecFDQuery -> Close ();
        DM3 -> People_SvodReport_SpecFDQuery -> SQL -> Clear ();
        DM3 -> People_SvodReport_SpecFDQuery -> SQL -> Add ("SELECT People.NOMER, People.FAM, People.NAME, \
   People.OTCH, People.VID_EDU, People.N_FAC, People.KURS, People.N_SPEC, People.N_SPECIALIZ, \
   People.N_PRIKAZ_KURS, People.N_GROUP, People.STATUS_PEOPLE, People.INC_GROUP, \
   People.N_ZACHET, Increment_group.VID_EDU, Increment_group.GOD, Increment_group.N_GROUP, \
   Faculty.FAC1, Specializ.SPECIAL, Specializ.Special_Direction \
   FROM PEOPLE People \
   INNER JOIN INCREMENT_GROUP Increment_group  \
   ON  (People.INC_GROUP = Increment_group.INC_GROUP) \
   INNER JOIN FACULTY Faculty \
   ON  (People.N_FAC = Faculty.N_FAC) \
   INNER JOIN SPECIALIZ Specializ  \
   ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) \
   where (People.STATUS_PEOPLE=1) and (People.INC_GROUP in (" + inc_gr + ")) \
   and (People.N_FAC=" + nom_fac + ")  and (People.N_SPECIALIZ in (" +
            Str_Nomer + "))\
   ORDER BY People.N_SPECIALIZ, People.INC_GROUP,People.FAM, People.NAME, People.OTCH"
            );
        /* where (People.STATUS_PEOPLE=1) and (People.INC_GROUP in (" + inc_gr + ")) \
         and (People.N_FAC=" + nom_fac + ")  and (People.N_SPECIALIZ in (" +
         Str_Nomer + ")) */
        DM3 -> People_SvodReport_SpecFDQuery -> Open ();

        // ���������  Exel
        DataModule1 -> ExelInit ();
        // ������ ���������� ������ � �����

        App_n.OlePropertySet ("SheetsInNewWorkbook", 1);

        int n_specializ = 0; // �������������
        int j = 0; // �������  ���������� ���������
        int nnn = 1; // ������� ���������� ����� �� �������������
        AnsiString grup = ""; // ������
        int stolbec = 0;
        for (int i = 0;
        i < DM3 -> People_SvodReport_SpecFDQuery -> RecordCount;
        i++) // ������������ ������ � ����������� �� ���-�� ������!!
        { // for

            if (n_specializ != DM3 -> People_SvodReport_SpecFDQueryN_SPECIALIZ
                -> Value) {
                // if n_specializ!=DM3 -> People_SvodReport_SpecN_SPECIALIZ -> Value
                n_specializ =
                    DM3 -> People_SvodReport_SpecFDQueryN_SPECIALIZ -> Value;

                App_n.OlePropertyGet ("WorkSheets").OleProcedure ("add");
                Sh = App_n.OlePropertyGet ("WorkSheets").OlePropertyGet
                    ("Item", 1);

                // ������ �������������� ������������ ��������
                Sh.OlePropertyGet ("PageSetup").OlePropertySet ("Orientation", 2);
                Sh.OlePropertyGet ("PageSetup").OlePropertySet
                    ("CenterHorizontally", true);
                Sh.OlePropertyGet ("PageSetup").OlePropertySet ("Zoom", false);
                Sh.OlePropertyGet ("PageSetup").OlePropertySet
                    ("FitToPagesWide", 1);
                Sh.OlePropertyGet ("PageSetup").OlePropertySet
                    ("FitToPagesTall", 2);
                //

                nnn = 1; // ������� ���������� ����� �� �������������
                AnsiString name_spec =
                    DM3 -> People_SvodReport_SpecFDQuerySPECIAL -> Value;
                if (name_spec.Length () > 24)
                { // if ����� �������� ������� �� ������� �� �� 30 ��������
                    name_spec = name_spec.SubString (1, 20);
                } // end if ����� �������� ������� �� ������� �� �� 30 ��������

                Sh.OlePropertySet ("Name", WideString (name_spec));
                Sh = App_n.OlePropertyGet ("ActiveSheet");

                str_r = 1;

                god_first =
                    uch_god -
                    (DM3 -> People_SvodReport_SpecFDQueryKURS -> Value - 1);

                AnsiString sql_2[2] = {
                    " and ( (Edu_plan.semestr in (1,2) and  Edu_plan.year_plan=" +
                        AnsiString (god_first) + " ) or \
               (Edu_plan.semestr in (3,4) and  Edu_plan.year_plan=" +
                        AnsiString (god_first + 1) + " ) or \
               (Edu_plan.semestr in (5,6) and Edu_plan.year_plan=" +
                        AnsiString (god_first + 2) + " ) or \
               (Edu_plan.semestr in (7,8) and  Edu_plan.year_plan=" +
                        AnsiString (god_first + 3) + " ))",
                    // (Edu_plan.semestr in (9,10) and  Edu_plan.year_plan="+AnsiString (god_first+4)+" ))",

                    "and ( (Edu_plan.semestr in (1,2) and  Edu_plan.year_plan=" +
                        AnsiString (god_first) + " ) or \
               (Edu_plan.semestr in (3,4) and  Edu_plan.year_plan=" +
                        AnsiString (god_first + 1) + " ) or \
               (Edu_plan.semestr in (5,6) and Edu_plan.year_plan=" +
                        AnsiString (god_first + 2) + " ) or \
               (Edu_plan.semestr in (7,8) and  Edu_plan.year_plan=" +
                        AnsiString (god_first + 3) + " )  or \
               (Edu_plan.semestr in (9,10) and  Edu_plan.year_plan=" +
                        AnsiString (god_first + 4) + " ))"};
                // (Edu_plan.semestr in (11,12) and  Edu_plan.year_plan="+AnsiString (god_first+5)+" ))"};

                DM3 -> Svod_NadoFDQuery -> Close ();
                DM3 -> Svod_NadoFDQuery -> SQL -> Clear ();
                DM3 -> Svod_NadoFDQuery -> SQL -> Add
                    (sql_1 + sql_2[RadioGroup1 -> ItemIndex] + sql_s_ved + sql_3);
                /* DM3 -> Svod_NadoFDQuery -> SQL -> Add
                 (sql_1 + sql_2[RadioGroup1 -> ItemIndex] + sql_3); */
                DM3 -> Svod_NadoFDQuery -> ParamByName ("N_FAC") -> AsSmallInt =
                    nom_fac;
                DM3 -> Svod_NadoFDQuery -> ParamByName ("VID_EDU") -> AsSmallInt =
                    RadioGroup1 -> ItemIndex;
                DM3 -> Svod_NadoFDQuery -> ParamByName ("SPECIALIZ") -> AsInteger =
                    n_specializ;
                DM3 -> Svod_NadoFDQuery -> Open ();
                DM3 -> Count_Svod_NadoFDQuery -> Close ();
                DM3 -> Count_Svod_NadoFDQuery -> SQL -> Clear ();
                DM3 -> Count_Svod_NadoFDQuery -> SQL -> Add
                    (count_sql_1 + sql_2[RadioGroup1 -> ItemIndex] + count_sql_3);
                DM3 -> Count_Svod_NadoFDQuery -> ParamByName ("N_FAC") -> AsSmallInt =
                    nom_fac;
                DM3 -> Count_Svod_NadoFDQuery -> ParamByName ("VID_EDU")
                    -> AsSmallInt = RadioGroup1 -> ItemIndex;
                DM3 -> Count_Svod_NadoFDQuery -> ParamByName ("SPECIALIZ")
                    -> AsInteger = n_specializ;
                DM3 -> Count_Svod_NadoFDQuery -> Open ();
                // --------
                for (int i = 0; i < 5; i++) { // for1
                    mas_svod_nado[i] =
                        new AnsiString[DM3 -> Count_Svod_NadoFDQueryCOUNT -> Value];
                } // end for 1

                j = 0; // �������
                int pr1 = 0; // ����� ��������
                for (int i = 0;
                i < DM3 -> Count_Svod_NadoFDQueryCOUNT -> Value; i++) { // for2

                    if (pr1 != DM3 -> Svod_NadoFDQueryN_OBJECT -> Value) {
                        mas_svod_nado[0][j] =
                            AnsiString (DM3 -> Svod_NadoFDQueryN_OBJECT -> Value);
                        // ����� ��������
                        mas_svod_nado[1][j] =
                            AnsiString (DM3 -> Svod_NadoFDQueryZACH_EXAM -> Value);
                        // ��� ��������
                        mas_svod_nado[2][j] =
                            AnsiString (DM3 -> Svod_NadoFDQuerySPECKURS -> Value);
                        // spec_kurs
                        mas_svod_nado[3][j] =
                            DM3 -> Svod_NadoFDQueryNAME_OBJECT -> Value;
                        // �������� ��������
                        mas_svod_nado[4][j] = "";
                        // ������� � Excel ���������� �����
                        pr1 = DM3 -> Svod_NadoFDQueryN_OBJECT -> Value;
                        j++;
                    }
                    DM3 -> Svod_NadoFDQuery -> Next ();
                } // end for 2

                // ��������� �����
                AnsiString temp_text = "";

                // -------  �������� �� ��������� ���� 4 (��������) ��� 5 (��������)

                if ( (!RadioGroup1 -> ItemIndex && RadioGroup2 -> ItemIndex == 3) ||
                    (RadioGroup1 -> ItemIndex && RadioGroup2 -> ItemIndex == 4))
                { // if ��������� ����
                    temp_text = "������� ��������� ���������� ����� " +
                        AnsiString (uch_god + 1) + " ����";
                    stolbec = j;
                } // end if ��������� ����
                else { // else ������ �����
                    temp_text =
                        "������� ��������� �� ��������� �� ��������� �� " +
                        AnsiString (uch_god) + "/" + AnsiString (uch_god + 1) +
                        " ������� ���";
                    stolbec = j + 2;
                } // end else ������ �����
                // -------
                Cell_2_Text_Ole2 (1, stolbec, str_r, false, "Arial", 12, true, 3,
                    2, 0, true, false, temp_text);
                str_r++;

                // ����������� ����� ��������
                if (!RadioGroup1 -> ItemIndex)
                    temp_text = "������� ����� ��������� �����������";
                else
                    temp_text = "������� ����� ��������� �����������";
                Cell_2_Text_Ole2 (1, stolbec, str_r, false, "Arial", 12, true, 3,
                    2, 0, true, false, temp_text);
                str_r++;

                // ����������� �������� ����������
                switch (nom_fac) {
                case 1:
                    temp_text =
                        "���������-��������������� ���������� ���������� ��� � ����������� ";
                    break;
                case 2:
                    temp_text =
                        "���������-��������������� ���������� �������� ����� ������ ";
                    break;
                case 3:
                    temp_text =
                        "���������� ��������������� ���������� �������� � ������� ";
                    break;
                case 4:
                    temp_text =
                        "���������� ����������� ������, ������� � �������������� ";
                    break;
                }
                Cell_2_Text_Ole2 (1, stolbec, str_r, false, "Arial", 12, true, 3,
                    2, 0, true, false, temp_text);
                str_r++;

                // ����������� �������� ������������� ��� ����������� �������������
                if (DM3 -> People_SvodReport_SpecFDQueryN_SPEC -> Value == 1) {
                    temp_text = "������������� - " +
                        DM3 -> People_SvodReport_SpecFDQuerySPECIAL -> Value;
                }
                else {
                    if ( (nom_fac == 4 && RadioGroup1 -> ItemIndex == 0 &&
                        RadioGroup2 -> ItemIndex == 0) ||
                        (nom_fac == 4 && RadioGroup1 -> ItemIndex == 0 &&
                        RadioGroup2 -> ItemIndex == 1) ||
                        (nom_fac == 4 && RadioGroup1 -> ItemIndex == 1)) {
                        temp_text = "������������� - ";
                    }
                    else
                        temp_text = "����������� ������������� - ";
                    temp_text +=
                        DM3 -> People_SvodReport_SpecFDQuerySPECIAL_DIRECTION -> 
                        Value;
                }
                Cell_2_Text_Ole2 (1, stolbec, str_r, false, "Arial", 12, true, 3,
                    2, 0, true, false, temp_text);
                str_r++;
                str_r++;

                // �����
                // � �/�
                // ����������
                // ��������� ������ � ��������� ������ ��� ���������
                AnsiString diap = mas_column[0] + str_r + ":" + mas_column[0] +
                    (str_r + 2);

                // ��������
                Variant Rang1 = App_n.OlePropertyGet ("Range", WideString (diap));
                Rang1.OleProcedure ("Merge");
                DataModule1 -> ExBorder (Rang1);
                Cell_2_Text_Ole2 (1, 1, str_r, true, "Arial", 10, false, 3, 2, 0,
                    true, false, "� �/�");

                // ���
                // ����������
                diap = mas_column[1] + str_r + ":" + mas_column[1] +
                    (str_r + 2);
                Rang1 = App_n.OlePropertyGet ("Range", WideString (diap));
                Rang1.OleProcedure ("Merge");
                DataModule1 -> ExBorder (Rang1);
                Cell_2_Text_Ole2 (2, 2, str_r, true, "Arial", 10, false, 3, 2, 0,
                    true, false, "���");

                // ��������
                Cell_2_Text_Ole2 (3, stolbec, str_r, true, "Arial", 10, false, 3,
                    2, 0, true, false, "��������");
                str_r++;

                nom_predmet = 1; // ������� ���������
                // ������� ��� ��������� ��������� � ������� ���������

                // ��������
                Predmet_svod (j, "2", 0);

                // ���.������
                Predmet_svod (j, "3", 0);

                // �������� ������
                Predmet_svod (j, "2", 1);

                // ��������
                Predmet_svod (j, "3", 1);

                // ������
                Predmet_svod (j, "1", 0);
                Predmet_svod (j, "0", 0);

                // ������������ (������ ���� ������ �� �������) ���
                Predmet_svod (j, "4", 1);

                // ������������ �� ������
                Predmet_svod (j, "5", 1);

                // ���������
                if (!RadioGroup1 -> ItemIndex)
                { // if ��������� ������ ��� ��������
                    Predmet_svod (j, "1", 1);
                } // end if ��������� ������ ��� ��������

                // ������������
                /* if (!RadioGroup1 -> ItemIndex)
                 {//if ������������ ������ ��� ��������
                 Predmet_svod (j, "4", 1);
                 } */

                DataModule1 -> ExAutoFit (3, j + 2);

                str_r++;
                grup = "";
            } // end if n_specializ!=DM3 -> People_SvodReport_SpecN_SPECIALIZ -> Value
            str_r++;

            if (grup != DM3 -> People_SvodReport_SpecFDQueryN_GROUP -> Value) {
                grup = DM3 -> People_SvodReport_SpecFDQueryN_GROUP -> Value;
                Cell_2_Text_Ole2 (1, stolbec, str_r, true, "Arial", 12, true, 3,
                    2, 0, true, false, grup + " ������");
                str_r++;
            }

            int nomer_s = DM3 -> People_SvodReport_SpecFDQueryNOMER -> Value;

            // -----������
            DM3 -> Detail_Svod_RealFDQuery -> Close ();
            DM3 -> Detail_Svod_RealFDQuery -> SQL -> Clear ();
            DM3 -> Detail_Svod_RealFDQuery -> SQL -> Add ("SELECT Object_plan.N_OBJECT, Object_plan.NAME_OBJECT, \
      Edu_plan.N_PLAN, Edu_plan.SEMESTR, Edu_plan.CLOCK_PLAN, Edu_plan.CLOCK_PLAN_ALL,\
      Edu_plan.YEAR_PLAN, Edu_plan.N_FAC, Edu_plan.ZACH_EXAM, \
      Edu_plan.VID_EDU_PLAN, Edu_plan.SPECKURS, \
      Result_ball.RESULT, \
      Result_ball.DATE_RESULT, Result_ball.STATUS_RESULT, \
      People.NOMER, People.FAM, People.NAME, People.OTCH, People.STATUS_PEOPLE  \
      FROM EDU_PLAN Edu_plan \
      INNER JOIN OBJECT_PLAN Object_plan \
         ON  (Edu_plan.N_OBJECT = Object_plan.N_OBJECT) \
         INNER JOIN RESULT_BALL Result_ball \
         ON  (Edu_plan.N_PLAN = Result_ball.N_PLAN)  \
         INNER JOIN PEOPLE People  \
         ON  (Result_ball.NOMER =  people.nomer) \
      where (People.STATUS_PEOPLE=1)and People.NOMER=" + AnsiString (nomer_s) +
                " order by edu_plan.n_object, Edu_plan.SEMESTR desc, edu_plan.zach_exam desc");
            DM3 -> Detail_Svod_RealFDQuery -> Open ();

            // � �/�
            Cell_2_Text_Ole2 (1, 1, str_r, true, "Arial", 10, false, 3, 2, 0,
                false, false, nnn);

            // ���
            Cell_2_Text_Ole2 (2, 2, str_r, true, "Arial", 10, false, 0, 2, 0,
                false, false, DM3 -> People_SvodReport_SpecFDQueryFAM -> Value +
                " " + DM3 -> People_SvodReport_SpecFDQueryNAME -> Value + " " +
                DM3 -> People_SvodReport_SpecFDQueryOTCH -> Value);

            AnsiString pr = ""; // ����� ��������

            for (int k = 0; k < j; k++) { // for ���� �� ������� � �������
                pr = mas_svod_nado[0][k];
                // ��������� ������ ������
                if (mas_svod_nado[4][k] != "")
                    Cell_2_Text_Ole2 (StrToInt (mas_svod_nado[4][k]),
                    StrToInt (mas_svod_nado[4][k]), str_r, true, "Arial", 10,
                    false, 3, 2, 0, false, false, "");

                DM3 -> Detail_Svod_RealFDQuery -> First ();
                for (int z = 0;
                z < DM3 -> Detail_Svod_RealFDQuery -> RecordCount; z++)
                { // for ���� �� �������� �������

                    if (pr == DM3 -> Detail_Svod_RealFDQueryN_OBJECT -> Value)
                    { // if pr!
                        AnsiString St = "";
                        // --------����� ����� ��� ����������� ������� ������
                        int ball_baza =
                            ball_int (syst_ball,
                            DM3 -> Detail_Svod_RealFDQueryRESULT -> Value);
                        if (ball_baza > 10)
                        { // if �������� �� ����������� ����� �� ������������� �������
                            St = IntToStr (ball_baza - 10);

                        } // end if �������� �� ����������� ����� �� ������������� �������
                        else { // else �� ����������� ����� �� ����������� �������
                            switch (ball_baza)
                            { // switch ����� ����������� �������
                            case 0:
                                St = "";
                                // ������ ������ � ��� ������ ����� �� ����������� ������
                                break;
                            case 1:
                                St = "���"; // �����
                                break;
                            case 7:
                                St = "���"; // ����������
                                break;
                            case 9:
                                St = "+"; // ���������
                                break;
                            default:
                                St = IntToStr (ball_baza);
                                // ����� 2,3,4,5 �������������
                            } // end switch ����� ����������� �������
                        } // end else �� ����������� ����� �� ����������� �������
                        // -------
                        if (St == "���" || St == "���") {
                            Cell_2_Text_Ole2 (StrToInt (mas_svod_nado[4][k]),
                                StrToInt (mas_svod_nado[4][k]), str_r, true,
                                "Arial", 10, false, 3, 2, 90, false, false, St);

                        }
                        else {
                            Cell_2_Text_Ole2 (StrToInt (mas_svod_nado[4][k]),
                                StrToInt (mas_svod_nado[4][k]), str_r, true,
                                "Arial", 10, false, 3, 2, 0, false, false, St);

                        }

                        pr = "";
                    } // end if pr
                    DM3 -> Detail_Svod_RealFDQuery -> Next ();

                } // for ���� �� �������� �������

            } // for ���� �� ������� � �������

            nnn++;
            DM3 -> People_SvodReport_SpecFDQuery -> Next ();
            DataModule1 -> ExAutoFit (1, 2);
        } // end for
        App_n.Clear ();
        Sh.Clear ();
        for (int i = 0; i < 5; i++)
            delete[]mas_svod_nado[i];

    } // if MyList1 -> Execute
    for (int i = 0; i < 2; i++)
        delete[]mas_spec[i];

}

void __fastcall TDiplomForm::BitBtn3Click (TObject *Sender)
{ // ������ ������ �� �������������
    AnsiString inc_gr = DM3 -> Check_Return_Group (RadioGroup1 -> ItemIndex,
        CheckListBox1);
    if (inc_gr == "") { // �������� �� ��������
        ShowMessage ("�� �� ������� ����� ������!");
        return;
    }
    bool oplata = false; // ����������
    int stb_max; // ��������� ����� �������
    AnsiString text_found = "";
    // !!!if (Application -> MessageBox ("�� ������ ������ ��������� ����� ��������?", "", MB_YESNO) == mrYes)
    if (MessageDlg ("�� ������ ������ ��������� ����� ��������?", mtConfirmation,
        TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes) {
        text_found = " and (PEOPLE.n_found<>2) ";
        stb_max = 12;
    }
    else {
        text_found = " and (PEOPLE.n_found=2) ";
        oplata = true; // ��������
        stb_max = 11;
    }

    bool adress = false; // ������ � ��������� �����

    // !!!if (Application -> MessageBox ("�� ������ ������������ ����� �� ����������� - ������� Yes\n��� ����� � ��������� ����� - ������� No?", "", MB_YESNO) == mrYes)
    if (MessageDlg
        ("�� ������ ������������ ����� �� ����������� - ������� Yes\n��� ����� � ��������� ����� - ������� No?",
        mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes) {
        adress = true; // ������ ��������� (�� �����������)
    }

    DM3 -> Name_SpecFDQuery -> Close ();
    DM3 -> Name_SpecFDQuery -> SQL -> Clear ();
    DM3 -> Name_SpecFDQuery -> SQL -> Add ("SELECT Distinct ( Specializ.N_SPECIALIZ), Specializ.SPECIAL \
FROM PEOPLE People \
   INNER JOIN INCREMENT_GROUP Increment_group \
   ON  (People.INC_GROUP = Increment_group.INC_GROUP)  \
   INNER JOIN FACULTY Faculty \
   ON  (People.N_FAC = Faculty.N_FAC)  \
   INNER JOIN SPECIALIZ Specializ  \
   ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) \
where (People.STATUS_PEOPLE=1) and (People.INC_GROUP in (" + inc_gr + ")) \
and (People.N_FAC=" + nom_fac + ") \
ORDER BY Specializ.N_SPECIALIZ");
    DM3 -> Name_SpecFDQuery -> Open ();

    // ������������ �������� ������� �������������
    AnsiString *mas_spec[2]; // ������ ������� � �������� �������������
    for (int i = 0; i < 2; i++)
        mas_spec[i] = new AnsiString[DM3 -> Name_SpecFDQuery -> RecordCount];
    //////////////////////////////////////////////////////////////////////////
    DualListDlg = new TDualListDlg (this);
    DualListDlg -> SrcList -> Items -> Clear ();
    DualListDlg -> DstList -> Items -> Clear ();
    // ��� ���������
    for (int i = 0; i < DM3 -> Name_SpecFDQuery -> RecordCount; i++) {
        mas_spec[0][i] = DM3 -> Name_SpecFDQuerySPECIAL -> Value;
        DualListDlg -> SrcList -> Items -> AddObject (mas_spec[0][i],
            (TObject *) (DM3 -> Name_SpecFDQueryN_SPECIALIZ -> Value));
        mas_spec[1][i] = AnsiString (DM3 -> Name_SpecFDQueryN_SPECIALIZ -> Value);
        DM3 -> Name_SpecFDQuery -> Next ();
    } // for

    DualListDlg -> ShowModal ();
    if (DataModule2 -> printdlg == true) { // if MyList1 -> Execute
        AnsiString Str_Nomer = "";
        for (int i = 0; i <= DualListDlg -> DstList -> Items -> Count - 1; i++) {
            Str_Nomer +=
                String ( (int) (DualListDlg -> DstList -> Items -> Objects[i])) + ",";
            // ���������� ����� �������������
        } // 1-�� for
        delete DualListDlg;
        Str_Nomer.SetLength (Str_Nomer.Length () - 1);

        DM3 -> Spisok_raspFDQuery -> Close ();
        DM3 -> Spisok_raspFDQuery -> SQL -> Clear ();
        DM3 -> Spisok_raspFDQuery -> SQL -> Add ("SELECT PEOPLE.NOMER, PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH, PEOPLE.POL, PEOPLE.MARIAGE, \
    PEOPLE.N_CHILD, PEOPLE.N_VID_SPORT, PEOPLE.VID_EDU, PEOPLE.N_FAC, PEOPLE.KURS, \
    PEOPLE.N_SPEC, PEOPLE.N_SPECIALIZ, specializ.special, specializ.SPECIAL_SKLON, Specializ.Special_Direction, PEOPLE.N_FOUND, PEOPLE.N_GROUP, \
    PEOPLE.STATUS_PEOPLE, PEOPLE.INC_GROUP, \
    PEOPLE.ADDRESS_BEFORE,  PEOPLE.ADDRESS, PEOPLE.DATA_R \
    FROM PEOPLE \
      INNER JOIN specializ ON (people.n_specializ = specializ.n_specializ)  \
    where  (PEOPLE.n_fac=" + AnsiString (nom_fac) + ")  \
      and (PEOPLE.vid_edu=" + RadioGroup1 -> ItemIndex + " )" + text_found + "  \
      and (PEOPLE.inc_group in (" + inc_gr + "))  \
      and (PEOPLE.n_specializ in (" + Str_Nomer +
            ")) \
      and (PEOPLE.status_people=1)  \
      order by PEOPLE.n_spec, PEOPLE.n_specializ, PEOPLE.N_GROUP, PEOPLE.fam, PEOPLE.name, PEOPLE.otch");
        DM3 -> Spisok_raspFDQuery -> Open ();
        // text_found= and (PEOPLE.n_found <>2) ��� text_found= and (PEOPLE.n_found=2)

        if (!DM3 -> Spisok_raspFDQuery -> RecordCount) {
            ShowMessage ("��� ��������� �� ��������� ����������!");
            for (int i = 0; i < 2; i++)
                delete[]mas_spec[i];
            return;
        }

        // ����������� ������� ������
        AnsiString dekan = "";
        switch (nom_fac) {
        case 1:
            dekan = "�.�.��������";
            break;
        case 2:
            dekan = "�.�.����������";
            break;
        case 3:
            dekan = "�.�.���������";
            break;
        case 4:
            dekan = "�.�.���������";
            break;
        }

        // ���������  Exel
        DataModule1 -> ExelInit ();
        // ������ ���������� ������ � �����

        App_n.OlePropertySet ("SheetsInNewWorkbook", 1);

        int n_specializ = 0; // �������������

        int nnn = 1; // ������� ���������� ����� �� �������������
        AnsiString grup = ""; // ������

        for (int i = 0; i < DM3 -> Spisok_raspFDQuery -> RecordCount;
        i++) // ������������ ������ � ����������� �� ���-�� ������!!
        { // for
            int stb = 1; // ����� �������
            if (n_specializ != DM3 -> Spisok_raspFDQueryN_SPECIALIZ -> Value)
            { // if n_specializ!=DM3 -> People_SvodReport_SpecN_SPECIALIZ -> Value

                if (i) { // if �� ������ ����
                    str_r++;
                    str_r++;
                    str_r++;
                    Cell_2_Text_Ole2 (2, 2, str_r, false, "TimesNewRoman", 12,
                        false, 2, 2, 0, false, false,
                        "����� " + DM2 -> FacultyFDTable -> Lookup ("N_FAC", nom_fac,
                        "FAC1"));
                    Cell_2_Text_Ole2 (8, 8, str_r, false, "TimesNewRoman", 12,
                        false, 2, 2, 0, false, false, dekan);
                }
                n_specializ = DM3 -> Spisok_raspFDQueryN_SPECIALIZ -> Value;

                App_n.OlePropertyGet ("WorkSheets").OleProcedure ("add");
                Sh = App_n.OlePropertyGet ("WorkSheets").OlePropertyGet
                    ("Item", 1);

                // ������ �������������� ������������ ��������
                Sh.OlePropertyGet ("PageSetup").OlePropertySet ("Orientation", 2);
                Sh.OlePropertyGet ("PageSetup").OlePropertySet
                    ("CenterHorizontally", true);
                Sh.OlePropertyGet ("PageSetup").OlePropertySet ("Zoom", false);
                Sh.OlePropertyGet ("PageSetup").OlePropertySet
                    ("FitToPagesWide", 1);
                Sh.OlePropertyGet ("PageSetup").OlePropertySet
                    ("FitToPagesTall", 2);

                // ����
                Sh.OlePropertyGet ("PageSetup").OlePropertySet ("TopMargin", 58);
                Sh.OlePropertyGet ("PageSetup").OlePropertySet
                    ("BottomMargin", 14);
                Sh.OlePropertyGet ("PageSetup").OlePropertySet ("LeftMargin", 58);
                Sh.OlePropertyGet ("PageSetup").OlePropertySet
                    ("RightMargin", 26);

                //
                nnn = 1; // ������� ���������� ����� �� �������������
                AnsiString name_spec = DM3 -> Spisok_raspFDQuerySPECIAL -> Value;
                if (name_spec.Length () > 24)
                { // if ����� �������� ������� �� ������� �� �� 30 ��������
                    name_spec = name_spec.SubString (1, 20);
                } // end if ����� �������� ������� �� ������� �� �� 30 ��������

                try {
                    Sh.OlePropertySet ("Name", WideString (name_spec));
                }
                catch (...) {
                    name_spec = name_spec + AnsiString (i);
                    Sh.OlePropertySet ("Name", WideString (name_spec));
                }
                Sh = App_n.OlePropertyGet ("ActiveSheet");

                str_r = 1; // ����� ������

                AnsiString temp_text = "";

                Cell_2_Text_Ole2 (stb, stb_max, str_r, false, "TimesNewRoman",
                    18, true, 3, 2, 0, true, false, "������");
                str_r++;
                Cell_2_Text_Ole2 (stb, stb_max, str_r, false, "TimesNewRoman",
                    14, true, 3, 2, 0, true, false,
                    "��� ������������� ������������� �����������");
                str_r++;
                Cell_2_Text_Ole2 (stb, stb_max, str_r, false, "TimesNewRoman",
                    14, true, 3, 2, 0, true, false,
                    "���������� ����������� \"����������� ��������������� ����������� ���������� ��������\"");
                str_r++;

                // ����������� �������� ����������
                switch (nom_fac) {
                case 1:
                    temp_text =
                        "���������-�������������� ��������� ���������� ��� � �����������";
                    break;
                case 2:
                    temp_text =
                        "���������-�������������� ��������� �������� ����� ������";
                    break;
                case 3:
                    temp_text =
                        "��������� ��������������� ���������� �������� � �������";
                    break;
                case 4:
                    temp_text = "�������� ����������� ������ � �������";
                    break;
                }
                Cell_2_Text_Ole2 (stb, stb_max, str_r, false, "TimesNewRoman",
                    14, true, 3, 2, 0, true, false, temp_text);
                str_r++;

                // ����������� �������� �������������
                if ( (DM3 -> Spisok_raspFDQueryN_SPEC -> Value == 1) &&
                    (n_specializ != 52 && n_specializ != 56 && n_specializ !=
                    2 && n_specializ != 5 && n_specializ != 49 && n_specializ !=
                    48 && n_specializ != 6 && n_specializ != 3 &&
                    n_specializ != 4))
                { // if ���� ������ ���������� ������    2,5,49,48,6 - ����� � 52,56 - ���
                    temp_text = "�������������: ���������� ������ �� " +
                        DM3 -> Spisok_raspFDQuerySPECIAL_SKLON -> Value;
                } // end if ���� ������ ���������� ������
                else { // else ����� ������ ���� ������ �������������
                    if (DM3 -> Spisok_raspFDQueryN_SPEC -> Value == 1)
                        temp_text =
                            "�������������: " +
                            DM3 -> Spisok_raspFDQuerySPECIAL_SKLON -> Value;
                    else
                        temp_text = "����������� �������������: " +
                            DM3 -> Spisok_raspFDQuerySPECIAL_DIRECTION -> Value;
                } // end else ����� ������ ���� ������ �������������

                // temp_text="������������� - \""+ DM3 -> Spisok_raspQuerySPECIAL_SKLON -> Value+"\"";
                Cell_2_Text_Ole2 (stb, stb_max, str_r, false, "TimesNewRoman",
                    14, true, 3, 2, 0, true, false, temp_text);
                str_r++;

                temp_text = "������ " + AnsiString (uch_god + 1) + " ����";
                Cell_2_Text_Ole2 (stb, stb_max, str_r, false, "TimesNewRoman",
                    14, true, 3, 2, 0, true, false, temp_text);
                str_r++;

                if (oplata)
                    Cell_2_Text_Ole2 (stb, stb_max, str_r, false,
                    "TimesNewRoman", 14, true, 4, 2, 0, true, false,
                    "����������� �� �������� ������");
                str_r++;

                // �����
                // ������ �������
                Variant d;

                // � �/�
                Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 3,
                    2, 0, false, true, "�� �/�");
                Cell_2_Text_Ole2 (stb, stb, str_r + 1, true, "Arial", 10, false,
                    3, 2, 0, false, false, stb); // "1"
                d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 1, stb);
                d.OlePropertySet ("ColumnWidth", 4);
                stb++;
                // ���
                Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 3,
                    2, 0, false, true, "�������, ���, ��������");
                Cell_2_Text_Ole2 (stb, stb, str_r + 1, true, "Arial", 10, false,
                    3, 2, 0, false, false, stb); // "2"
                stb++;
                // ������� ����
                Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 3,
                    2, 0, false, true, "������� ����");
                Cell_2_Text_Ole2 (stb, stb, str_r + 1, true, "Arial", 10, false,
                    3, 2, 0, false, false, stb); // "3"
                d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 1, stb);
                d.OlePropertySet ("ColumnWidth", 8);
                stb++;
                // ���
                Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 3,
                    2, 0, false, false, "���");
                Cell_2_Text_Ole2 (stb, stb, str_r + 1, true, "Arial", 10, false,
                    3, 2, 0, false, false, stb); // "4"
                stb++;
                // ��� ��������
                Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 3,
                    2, 0, false, true, "��� ��������");
                Cell_2_Text_Ole2 (stb, stb, str_r + 1, true, "Arial", 10, false,
                    3, 2, 0, false, false, stb); // "5"
                d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 1, stb);
                d.OlePropertySet ("ColumnWidth", 9);
                stb++;
                // ������
                Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 3,
                    2, 0, false, false, "������");
                Cell_2_Text_Ole2 (stb, stb, str_r + 1, true, "Arial", 10, false,
                    3, 2, 0, false, false, stb); // "6"
                stb++;
                // �������� ���������
                Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 3,
                    2, 0, false, true,
                    "�������� ���������, ����� ������ ���� (����), ���-�� �����");
                Cell_2_Text_Ole2 (stb, stb, str_r + 1, true, "Arial", 10, false,
                    3, 2, 0, false, false, stb); // "7"
                d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 1, stb);
                d.OlePropertySet ("ColumnWidth", 12);
                stb++;

                // �����
                Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 3,
                    2, 0, false, true,
                    "����� ����������� ����� ���������� (����� ���������)");
                Cell_2_Text_Ole2 (stb, stb, str_r + 1, true, "Arial", 10, false,
                    3, 2, 0, false, false, stb); // "8"
                d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 1, stb);
                d.OlePropertySet ("ColumnWidth", 21);
                stb++;

                if (!oplata) {
                    // �����������
                    Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false,
                        3, 2, 0, false, true,
                        "�����������, ����������� �� ����� (��� ���������)");
                    Cell_2_Text_Ole2 (stb, stb, str_r + 1, true, "Arial", 10,
                        false, 3, 2, 0, false, false, stb); // "9"
                    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item",
                        1, stb);
                    d.OlePropertySet ("ColumnWidth", 21);
                    stb++;
                }
                // ���� ������������ �� ������
                Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 3,
                    2, 0, false, true, "���� ������������ �� ������");
                Cell_2_Text_Ole2 (stb, stb, str_r + 1, true, "Arial", 10, false,
                    3, 2, 0, false, false, stb); // "10"
                d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 1, stb);
                d.OlePropertySet ("ColumnWidth", 30);
                stb++;
                // ������� ����������"
                Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 3,
                    2, 0, false, true, "������� ����������");
                Cell_2_Text_Ole2 (stb, stb, str_r + 1, true, "Arial", 10, false,
                    3, 2, 0, false, false, stb); // "11"
                d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 1, stb);
                d.OlePropertySet ("ColumnWidth", 12);
                stb++;
                // ����������
                Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 3,
                    2, 0, false, true, "����������");
                Cell_2_Text_Ole2 (stb, stb, str_r + 1, true, "Arial", 10, false,
                    3, 2, 0, false, false, stb); // "12"
                d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 1, stb);
                d.OlePropertySet ("ColumnWidth", 11);

                // ���������� �������� ������
                temp_text = "$" + AnsiString (str_r) + ":$" +
                    AnsiString (str_r + 1);
                Sh.OlePropertyGet ("PageSetup").OlePropertySet ("PrintTitleRows",
                    WideString (temp_text));

                str_r++;
                grup = "";
            } // end if n_specializ!=DM3 -> Spisok_raspQueryN_SPECIALIZ -> Value
            str_r++;

            if (grup != DM3 -> Spisok_raspFDQueryN_GROUP -> Value) {
                grup = DM3 -> Spisok_raspFDQueryN_GROUP -> Value;
                Cell_2_Text_Ole2 (1, 11, str_r, true, "Arial", 12, true, 3, 2, 0,
                    true, false, grup + " ������");
                str_r++;
            }

            AnsiString temp_text = "";
            int nomer_s = DM3 -> Spisok_raspFDQueryNOMER -> Value;

            stb = 1; // ����� ������� ����� ������
            // � �/�
            Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 3, 2, 0,
                false, false, nnn); // 1
            stb++;
            // ���
            Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 0, 2, 0,
                false, false, DM3 -> Spisok_raspFDQueryFAM -> Value + " " +
                DM3 -> Spisok_raspFDQueryNAME -> Value + " " +
                DM3 -> Spisok_raspFDQueryOTCH -> Value); // 2
            stb++;
            // ������� ����
            Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 3, 2, 0,
                false, false, ""); // 3
            stb++;
            // ���
            Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 3, 2, 0,
                false, false, DM3 -> Spisok_raspFDQueryPOL -> Value); // 4
            stb++;
            // ��� ��������
            Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 3, 2, 0,
                false, false,
                SQLTimeStampToDateTime (DM3 -> Spisok_raspFDQueryDATA_R -> Value)
                .DateString ().SubString (7, 4)); // 5
            stb++;
            // ������
            DM3 -> Spisok_sportFDQuery -> Close ();
            DM3 -> Spisok_sportFDQuery -> ParamByName ("NOMER") -> AsInteger = nomer_s;
            DM3 -> Spisok_sportFDQuery -> Open ();
            temp_text = "";
            for (int i = 0; i < DM3 -> Spisok_sportFDQuery -> RecordCount; i++) {
                temp_text += DM3 -> Spisok_sportFDQueryVID_SPORT -> Value + " " +
                    DM3 -> Spisok_sportFDQueryTEXT_SPORT_CATEGORY -> Value + " ";
                DM3 -> Spisok_sportFDQuery -> Next ();
            }
            // ������
            Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 0, 2, 0,
                false, true, temp_text); // 6
            stb++;
            temp_text = "";
            if (DM3 -> Spisok_raspFDQueryPOL -> Value == '�') {
                switch (DM3 -> Spisok_raspFDQueryMARIAGE -> Value) {
                case 0:
                    temp_text = "�� �������";
                    break;
                case 1:
                    temp_text = "�������";
                    break;
                case 2:
                    temp_text = "���������";
                    break;
                case 3:
                    temp_text = "�����";
                    break;
                }
            }
            else if (DM3 -> Spisok_raspFDQueryPOL -> Value == '�') {
                switch (DM3 -> Spisok_raspFDQueryMARIAGE -> Value) {
                case 0:
                    temp_text = "������";
                    break;
                case 1:
                    temp_text = "�����";
                    break;
                case 2:
                    temp_text = "��������";
                    break;
                case 3:
                    temp_text = "������";
                    break;
                }
            }

            if (DM3 -> Spisok_raspFDQueryN_CHILD -> Value)
                temp_text +=
                    " ����: " + AnsiString
                    (DM3 -> Spisok_raspFDQueryN_CHILD -> Value);

            // �������� ���������
            Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 3, 2, 0,
                false, true, temp_text); // 7
            stb++;
            // �����
            if (adress) // ������ ��������� (�� �����������)
                    Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false,
                0, 2, 0, false, true,
                DM3 -> Spisok_raspFDQueryADDRESS_BEFORE -> Value); // 8
            else // //������ � ��������� �����
                    Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false,
                0, 2, 0, false, true,
                DM3 -> Spisok_raspFDQueryADDRESS -> Value); // 8
            stb++;

            if (!oplata) {
                // CK
                DM3 -> Spisok_CKFDQuery -> Close ();
                DM3 -> Spisok_CKFDQuery -> ParamByName ("NOMER") -> AsInteger =
                    nomer_s;
                DM3 -> Spisok_CKFDQuery -> Open ();
                temp_text = "";
                for (int i = 0; i < DM3 -> Spisok_CKFDQuery -> RecordCount; i++) {
                    if (DM3 -> Spisok_CKFDQueryN_SPECIALIZ -> Value == n_specializ)
                    {
                        temp_text += DM3 -> Spisok_CKFDQueryCENTRE -> Value + " ";
                        temp_text += Grid_V (DM3 -> Spisok_CKFDQuery, "CUSTOMER");
                    }
                    DM3 -> Spisok_CKFDQuery -> Next ();
                }

                // �����������
                Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 0,
                    2, 0, false, true, temp_text); // 9
                stb++;
            }
            // ���� ������������ �� ������
            Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 3, 2, 0,
                false, true, ""); // 10
            stb++;
            // ������� ����������"
            Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 3, 2, 0,
                false, false, ""); // 11
            stb++;
            // ����������
            Cell_2_Text_Ole2 (stb, stb, str_r, true, "Arial", 10, false, 3, 2, 0,
                false, false, ""); // 12

            nnn++;
            DM3 -> Spisok_raspFDQuery -> Next ();
            DataModule1 -> ExAutoFit (2, 6);
        } // end for

        str_r++;
        str_r++;
        str_r++;
        if (nom_fac == 4) {
          Cell_2_Text_Ole2 (2, 2, str_r, false, "TimesNewRoman", 12, false, 2, 2,
            0, false, false, "����� ���������� " + DM2 -> FacultyFDTable -> Lookup ("N_FAC",
            nom_fac, "FAC1"));
        }
        else
        Cell_2_Text_Ole2 (2, 2, str_r, false, "TimesNewRoman", 12, false, 2, 2,
            0, false, false, "����� " + DM2 -> FacultyFDTable -> Lookup ("N_FAC",
            nom_fac, "FAC1"));

        Cell_2_Text_Ole2 (8, 8, str_r, false, "TimesNewRoman", 12, false, 2, 2,
            0, false, false, dekan);
        App_n.Clear ();
        Sh.Clear ();

    } // if MyList1 -> Execute

    for (int i = 0; i < 2; i++)
        delete[]mas_spec[i];

}

void __fastcall TDiplomForm::CheckListBox1Click (TObject *Sender) {
    Panel3 -> Visible = true;
    RadioGroup3 -> Visible = true;
    Label1 -> Visible = true;
    DateTimePicker1 -> Visible = true;
}

void __fastcall TDiplomForm::DateTimePicker1Change (TObject *Sender) {
    DateTimePicker1 -> Time = StrToTime ("00:00");
}

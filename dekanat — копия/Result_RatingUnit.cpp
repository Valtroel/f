#include <vcl.h>
#pragma hdrstop


#include <comobj.hpp>
#include "DataModule.h"
#include "DM2Unit.h"
#include "Result_RatingUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TResult_RatingForm * Result_RatingForm;


AnsiString s_r = "                                                              \
    SELECT                                                                      \
        Rating.N_RATING,                                                        \
        Rating.N_VED_RATING,                                                    \
        Rating.NOMER,                                                           \
        Rating.BALL_R,                                                          \
        Rating.R_FAC,                                                           \
        Rating.R_KURS,                                                          \
        Rating.R_GROUP,                                                         \
        Rating.R_DOP,                                                           \
        People.FAM,                                                             \
        People.NAME,                                                            \
        People.OTCH,                                                            \
        Vedomost_rating.N_VEDOMOST_R,                                           \
        Vedomost_rating.N_FAC,                                                  \
        Vedomost_rating.VID_EDU,                                                \
        Vedomost_rating.UCH_GOD,                                                \
        Vedomost_rating.SEMESTR,                                                \
        Vedomost_rating.SESSION,                                                \
        Vedomost_rating.INC_GROUP,                                              \
        Vedomost_rating.N_SPECIALIZ,                                            \
        Specializ.SPECIAL,                                                      \
        Increment_group.N_GROUP,                                                \
        People.FAM|| ' ' || People.NAME || ' ' || People.OTCH as FIO            \
    FROM                                                                        \
        RATING Rating                                                           \
            INNER JOIN                                                          \
                PEOPLE People                                                   \
                    ON                                                          \
                        (Rating.NOMER = People.NOMER)                           \
            INNER JOIN                                                          \
                VEDOMOST_RATING Vedomost_rating                                 \
                    ON                                                          \
                        (Rating.N_VED_RATING = Vedomost_rating.N_VED_RATING)    \
            INNER JOIN                                                          \
                SPECIALIZ Specializ                                             \
                    ON                                                          \
                        (Vedomost_rating.N_SPECIALIZ = Specializ.N_SPECIALIZ)   \
            INNER JOIN                                                          \
                INCREMENT_GROUP Increment_group                                 \
                    ON                                                          \
                        (Vedomost_rating.INC_GROUP = Increment_group.INC_GROUP) \
    WHERE                                                                       \
            Vedomost_rating.N_FAC   = :FAC                                      \
        AND                                                                     \
            Vedomost_rating.UCH_GOD = :GOD                                      \
        AND                                                                     \
            Vedomost_rating.VID_EDU = :EDU                                      \
        AND                                                                     \
            Vedomost_rating.SESSION = :SES                                      \
    ";

AnsiString s_f = "                                                              \
    ORDER BY                                                                    \
        Rating.BALL_R DESC,                                                     \
        People.FAM,                                                             \
        People.NAME,                                                            \
        People.OTCH                                                             \
    ";

AnsiString s_k = "                                                              \
    ORDER BY                                                                    \
        Vedomost_rating.SEMESTR,                                                \
        Rating.BALL_R DESC,                                                     \
        People.FAM,                                                             \
        People.NAME,                                                            \
        People.OTCH                                                             \
    ";

AnsiString s_gr = "                                                             \
    ORDER BY                                                                    \
        Increment_group.N_GROUP,                                                \
        Rating.BALL_R DESC,                                                     \
        People.FAM,                                                             \
        People.NAME,                                                            \
        People.OTCH                                                             \
    ";


int rec_rat;                                                                    // ���������� ��� ����������� ���������� �������


__fastcall TResult_RatingForm::TResult_RatingForm (TComponent* Owner)
    : TForm (Owner) {
}





// ApplicationEvents1Message
// BitBtn1Click
// BitBtn2Click
// DBGrid1TitleClick
// Edit1Change
// Edit1KeyPress
// ExAutoFit
// ExBorder
// ExSave
// ExShapka
// FormActivate
// FormClose
// Open_SQL
// Save_Rat
// SpeedButton1Click
// toEx (AnsiString)
// toEx (Variant)









int __fastcall TResult_RatingForm::Open_SQL (AnsiString text_sql)               // ��������� �������� Query
{

    DataModule1 -> Rating_BallFDQuery -> Close ();
    DataModule1 -> Rating_BallFDQuery -> SQL -> Clear ();
    DataModule1 -> Rating_BallFDQuery -> SQL -> Add (text_sql);

    DataModule1 -> Rating_BallFDQuery ->
        ParamByName ("FAC") -> AsSmallInt =
                nom_fac;

    DataModule1 -> Rating_BallFDQuery ->
        ParamByName ("GOD") -> AsSmallInt =
                StrToInt (Edit2 -> Text);

    DataModule1 -> Rating_BallFDQuery ->
        ParamByName ("EDU") -> AsSmallInt =
                RadioGroup1 -> ItemIndex;

    DataModule1 -> Rating_BallFDQuery ->
        ParamByName ("SES") -> AsSmallInt =
                StrToInt (Edit1 -> Text);

    DataModule1 -> Rating_BallFDQuery -> Open ();

    return DataModule1 -> Rating_BallFDQuery -> RecordCount;
}


void __fastcall TResult_RatingForm::toEx (                                      // ������� ��������� ������ � Excel
        int        Row,
        int        Column,
        AnsiString data
    )
{
    try
    {
        Variant cur =
            Sh
            .OlePropertyGet (
                "Cells",
                Row,
                Column
            );

        cur.OlePropertySet (
            "Value",
            data.c_str ()
        );
    }
    catch (...)
    {
        ShowMessage (
			"�� ������� ������� Excel ����.\n��������� ������� ��������!"
        );
    }
}


void __fastcall TResult_RatingForm::toEx (                                      // ������� ��������� ������ � Excel
        int     Row,
        int     Column,
        Variant data
    )
{
    try
    {
        Variant cur =
            Sh
            .OlePropertyGet (
                "Cells",
                Row,
                Column
            );

        cur.OlePropertySet (
            "Value",
            data
        );
    }
    catch (...)
    {
        ShowMessage (
			"�� ������� ������� Excel ����.\n��������� ������� ��������!"
        );
    }
}


void __fastcall TResult_RatingForm::ExAutoFit (                                 // ��������� ��������� �������������� ������ �������
        int one,
        int two
    )
{
    for ( int i =  one;
              i <= two;
              ++i
        )
        Sh
        .OlePropertyGet ("Columns")
        .OlePropertyGet (
            "Item",
            i
        )
        .OleProcedure ("AutoFit");
}


void __fastcall TResult_RatingForm::Save_Rat (                                  // ��������� ���������� ��������
        int par,                                                                // 1 - �� ������, 2 - �� �����, 3 - �� ����������
        int rating                                                              // ������� �� ��������
    )
{
    DataModule1 -> Rating_BallFDQuery -> Edit ();

    switch (par)
    {
        case 1:
                DataModule1 ->
                    Rating_BallFDQueryR_GROUP ->
                        Value =
                            rating;
            break;
        case 2:
                DataModule1 ->
                    Rating_BallFDQueryR_KURS  ->
                        Value =
                            rating;
            break;
        case 3:
                DataModule1 ->
                    Rating_BallFDQueryR_FAC   ->
                        Value =
                            rating;
            break;
    }

    DataModule1 -> Rating_BallFDQuery -> Post ();
}


void __fastcall TResult_RatingForm::ExShapka (                                  // ��������� �������� ������� �������
        int        stroka,
        AnsiString text_zag,
        int        stat                                                         // ���� 0 - ����������� ����� ; 1 - ������
    )
{
    Variant range;
    AnsiString diap; // ��������
    // ���������
    toEx (stroka, 1, AnsiString (text_zag));

    if (stat) { // 1 - ������
        diap = "A" + AnsiString (stroka) + ":G" + AnsiString (stroka);
        range = App.OlePropertyGet ("Range", diap.c_str ());

    }
    else { // 0 - ����������� �����
        diap = "A" + AnsiString (stroka) + ":E" + AnsiString (stroka);
        range = App.OlePropertyGet ("Range", diap.c_str ());

    }

    // ����������� �����
    range.OleFunction ("Merge");
    // ��������� ������
    range.OlePropertyGet ("Font").OlePropertySet ("Name", "Arial");
    range.OlePropertyGet ("Font").OlePropertySet ("Size", 14);
    range.OlePropertyGet ("Font").OlePropertySet ("Bold", True);

    stroka++;
    // ������� ������� ������� Row,Column
    toEx (stroka, 1, AnsiString ("� �/�"));
    toEx (stroka, 2, AnsiString ("���"));
    toEx (stroka, 3, AnsiString ("� ������"));
    toEx (stroka, 4, AnsiString ("����"));
    if (stat) { // if  ������
        toEx (stroka, 5, AnsiString ("������� �� ����������"));
        toEx (stroka, 6, AnsiString ("������� �� �����"));
        toEx (stroka, 7, AnsiString ("������� �� ������"));
        diap = "A" + AnsiString (stroka) + ":G" + AnsiString (stroka);
        range = App.OlePropertyGet ("Range", diap.c_str ());
    } // end if  ������
    else { // else  ����������� �����
        toEx (stroka, 5, AnsiString ("�������"));
        diap = "A" + AnsiString (stroka) + ":E" + AnsiString (stroka);
        range = App.OlePropertyGet ("Range", diap.c_str ());
    } // end else  ����������� �����

    // ����������

    for (int i = 1; i <= 4; i++) { // for ����������
        range.OlePropertyGet ("Borders").OlePropertyGet ("Item", i).OlePropertySet
            ("LineStyle", 1);
    } // end for ����������

    for (int i = 1; i <= 7; i++)
    { // for  ����������� ������ � ������� ������� �������
        Sh.OlePropertyGet ("Cells", stroka, i).OlePropertySet
            ("HorizontalAlignment", 3);
    } // end for

}


void __fastcall TResult_RatingForm::ExBorder (int strok, int st)
{ // ������� ����������
    Variant range;
    AnsiString diap; // ��������

    if (st) { // 1 - ������
        diap = "A" + AnsiString (strok) + ":G" + AnsiString (strok);
        range = App.OlePropertyGet ("Range", diap.c_str ());
    }
    else { // 0 - ����������� �����
        diap = "A" + AnsiString (strok) + ":E" + AnsiString (strok);
        range = App.OlePropertyGet ("Range", diap.c_str ());
    }

    for (int i = 1; i <= 4; i++) { // for ����������
        range.OlePropertyGet ("Borders").OlePropertyGet ("Item", i).OlePropertySet
            ("LineStyle", 1);
    } // end for ����������
}


void __fastcall TResult_RatingForm::ExSave (int par) { // ������� ����������
    // int par  1 - �� ������, 2 - �� �����, 3 - �� ����������

    AnsiString name_f = "d:\\��� ���������\\������� " +
        DM2 -> FacultyFDTable -> Lookup ("N_FAC", nom_fac, "FAC1");

    switch (par) { // switch

    case 1:
        name_f += " �� ������� �� ";
        break;
    case 2:
        name_f += " �� ������ �� ";
        break;
    case 3:
        name_f += " �� ���������� �� ";
        break;
    } // end switch

    // ������� ����
    curent_date = cur_d ();

    name_f += DateToStr (curent_date) + ".xls"; ;

    App.OlePropertyGet ("WorkBooks", 1).OleProcedure ("SaveAs", name_f.c_str ());

}


void __fastcall TResult_RatingForm::FormClose (TObject *Sender,
    TCloseAction &Action) {
    Action = caFree;
}


void __fastcall TResult_RatingForm::FormActivate (TObject *Sender) {

    // ����� �����
    Result_RatingForm -> Height = 133;
    Panel2 -> Visible = false;
    Panel3 -> Visible = false;

    Edit2 -> Text = uch_god;
    Edit3 -> Text = uch_god + 1;

}


void __fastcall TResult_RatingForm::BitBtn1Click (TObject *Sender)
{ // ������ ����������

    Edit1Change (this);
    // ��������
    if (Edit1 -> Text == "") { // if  ���������
        ShowMessage ("������� ��������� 1 ��� 2!");
        return;
    } // end if  ���������
    else { // else �� ������
        if (Edit1 -> Text != "1" && Edit1 -> Text != "2")
        { // if �������� �� ���������� ����
            ShowMessage ("��������� ������ ���� 1 ��� 2!");
            Edit1 -> Text = "";
            Edit1 -> SetFocus ();
            return;
        } // end if �������� �� ���������� ����
    } // end else �� ������

    if (Edit2 -> Text == "") { // if ������� ���
        ShowMessage ("������� ������� ���!");
        return;
    } // end if ������� ���

    // ----------------------

    rec_rat = Open_SQL (s_r + s_gr);

    if (!rec_rat) { // if ��� �������
        ShowMessage ("��� �������!");
        return;
    } // end if ��� �������

    // ----------------�������� �����
    int rat; // �������������� �����
    int str; // ����� ������
    int np; // ����� �/�
    int ball; // ��������� ����

    AnsiString zag = ""; // �������� ������� �����

    // ---�� ������

    AnsiString gr_rat;
    DataModule1 -> ExelInit ();
    // ���������� � Excel ������
    while (!DataModule1 -> Rating_BallFDQuery -> Eof) { // while !Eof
        // �������� ����
        str = 2; // ����� ������
        np = 1; // ����� �/�
        gr_rat = DataModule1 -> Rating_BallFDQueryN_GROUP -> Value;
        App.OlePropertyGet ("WorkSheets").OleProcedure ("add");
        Sh = App.OlePropertyGet ("ActiveSheet");
        AnsiString n_list = "������ " + gr_rat;
        Sh.OlePropertySet ("Name", n_list.c_str ());
        zag = "������� ��������� �� ������ � " + gr_rat;
        ExShapka (str, zag, 0);
        rat = 1; // �������������� �����
        ball = DataModule1 -> Rating_BallFDQueryBALL_R -> Value;
        str += 2;

        while (gr_rat == DataModule1 -> Rating_BallFDQueryN_GROUP -> Value &&
            !DataModule1 -> Rating_BallFDQuery -> Eof) { // while sem  && !Eof
            toEx (str, 1, Variant (np));
            toEx (str, 2, AnsiString (DataModule1 -> Rating_BallFDQueryFIO -> Value));
            // ������ ������ ���������
            Sh.OlePropertyGet ("Cells", str, 3).OlePropertySet
                ("NumberFormat", "@");

            toEx (str, 3,
                AnsiString (DataModule1 -> Rating_BallFDQueryN_GROUP -> Value));
            Sh.OlePropertyGet ("Cells", str, 3).OlePropertySet
                ("HorizontalAlignment", 3);

            toEx (str, 4, Variant (DataModule1 -> Rating_BallFDQueryBALL_R -> Value));
            Sh.OlePropertyGet ("Cells", str, 4).OlePropertySet
                ("HorizontalAlignment", 3);

            if (ball != DataModule1 -> Rating_BallFDQueryBALL_R -> Value)
            { // if ball �� ����� ��
                ball = DataModule1 -> Rating_BallFDQueryBALL_R -> Value;
                rat++;
            } // end if ball �� ����� ��

            toEx (str, 5, Variant (rat));
            Sh.OlePropertyGet ("Cells", str, 5).OlePropertySet
                ("HorizontalAlignment", 3);
            Save_Rat (1, rat);
            ExBorder (str, 0);

            DataModule1 -> Rating_BallFDQuery -> Next ();

            str++;
            np++;
        } // end while sem  && !Eof

        // FormulaR1C1 = "=AVERAGE (R[-157]C:R[-1]C)"

        // ������ �������� ��������
        toEx (str, 2, AnsiString ("������� ���� �� ������:"));
        App.OlePropertyGet ("Cells", str, 4).OlePropertySet ("FormulaR1C1",
            ("=������ (R[-" + AnsiString (str - 4) + "]C:R[-1]C)").c_str ());

        ExAutoFit (1, 5);
    } // end while !Eof
    DataModule1 -> Rating_BallFDQuery -> ApplyUpdates ();
    ExSave (1);
    // ---end �� ������

    // ---�� �����
    rec_rat = Open_SQL (s_r + s_k);
    int sem;
    DataModule1 -> ExelInit ();

    // ���������� � Excel ������
    while (!DataModule1 -> Rating_BallFDQuery -> Eof) { // while !Eof
        // �������� ����

        str = 2; // ����� ������
        np = 1; // ����� �/�

        sem = DataModule1 -> Rating_BallFDQuerySEMESTR -> Value;

        App.OlePropertyGet ("WorkSheets").OleProcedure ("add");
        Sh = App.OlePropertyGet ("ActiveSheet");

        div_t kurs;
        kurs = div (sem + 1, 2);

        AnsiString k_list = "���� " + AnsiString (kurs.quot);
        Sh.OlePropertySet ("Name", k_list.c_str ());

        zag = "������� ��������� �� " + AnsiString (kurs.quot) + " �����";
        ExShapka (str, zag, 0);
        rat = 1; // �������������� �����
        ball = DataModule1 -> Rating_BallFDQueryBALL_R -> Value;
        str += 2;

        while (sem == DataModule1 -> Rating_BallFDQuerySEMESTR -> Value &&
            !DataModule1 -> Rating_BallFDQuery -> Eof) { // while sem  && !Eof
            toEx (str, 1, Variant (np));
            toEx (str, 2, AnsiString (DataModule1 -> Rating_BallFDQueryFIO -> Value));
            // ������ ������ ���������
            Sh.OlePropertyGet ("Cells", str, 3).OlePropertySet
                ("NumberFormat", "@");

            toEx (str, 3,
                AnsiString (DataModule1 -> Rating_BallFDQueryN_GROUP -> Value));
            Sh.OlePropertyGet ("Cells", str, 3).OlePropertySet
                ("HorizontalAlignment", 3);
            toEx (str, 4, Variant (DataModule1 -> Rating_BallFDQueryBALL_R -> Value));
            Sh.OlePropertyGet ("Cells", str, 4).OlePropertySet
                ("HorizontalAlignment", 3);

            if (ball != DataModule1 -> Rating_BallFDQueryBALL_R -> Value)
            { // if ball �� ����� ��
                ball = DataModule1 -> Rating_BallFDQueryBALL_R -> Value;
                rat++;
            } // end if ball �� ����� ��

            toEx (str, 5, Variant (rat));
            Sh.OlePropertyGet ("Cells", str, 5).OlePropertySet
                ("HorizontalAlignment", 3);
            Save_Rat (2, rat);
            ExBorder (str, 0);

            DataModule1 -> Rating_BallFDQuery -> Next ();
            str++;
            np++;
        } // end while sem  && !Eof

        // ������ �������� ��������
        toEx (str, 2, AnsiString ("������� ���� �� �����:"));
        App.OlePropertyGet ("Cells", str, 4).OlePropertySet ("FormulaR1C1",
            ("=������ (R[-" + AnsiString (str - 4) + "]C:R[-1]C)").c_str ());

        ExAutoFit (1, 5);
    } // end while !Eof
    DataModule1 -> Rating_BallFDQuery -> ApplyUpdates ();
    ExSave (2);
    // ---end �� �����

    // ---�� ����������
    rec_rat = Open_SQL (s_r + s_f);

    DataModule1 -> ExelInit ();

    str = 2; // ����� ������
    np = 1; // ����� �/�
    rat = 1; // �������������� �����

    ball = DataModule1 -> Rating_BallFDQueryBALL_R -> Value;

    zag = "������� ��������� �� ���������� ";
    ExShapka (str, zag, 1);
    str += 2;

    // ���������� � Excel ������
    while (!DataModule1 -> Rating_BallFDQuery -> Eof) { // while !Eof
        toEx (str, 1, Variant (np));
        toEx (str, 2, AnsiString (DataModule1 -> Rating_BallFDQueryFIO -> Value));

        // ������ ������ ���������
        Sh.OlePropertyGet ("Cells", str, 3).OlePropertySet ("NumberFormat", "@");

        toEx (str, 3, AnsiString (DataModule1 -> Rating_BallFDQueryN_GROUP -> Value));
        Sh.OlePropertyGet ("Cells", str, 3).OlePropertySet
            ("HorizontalAlignment", 3);
        toEx (str, 4, Variant (DataModule1 -> Rating_BallFDQueryBALL_R -> Value));
        Sh.OlePropertyGet ("Cells", str, 4).OlePropertySet
            ("HorizontalAlignment", 3);

        if (ball != DataModule1 -> Rating_BallFDQueryBALL_R -> Value)
        { // if ball �� ����� ��
            ball = DataModule1 -> Rating_BallFDQueryBALL_R -> Value;
            rat++;
        } // end if ball �� ����� ��

        toEx (str, 5, Variant (rat));
        Sh.OlePropertyGet ("Cells", str, 5).OlePropertySet
            ("HorizontalAlignment", 3);

        Save_Rat (3, rat);

        toEx (str, 6, Variant (DataModule1 -> Rating_BallFDQueryR_KURS -> Value));
        Sh.OlePropertyGet ("Cells", str, 6).OlePropertySet
            ("HorizontalAlignment", 3);
        toEx (str, 7, Variant (DataModule1 -> Rating_BallFDQueryR_GROUP -> Value));
        Sh.OlePropertyGet ("Cells", str, 7).OlePropertySet
            ("HorizontalAlignment", 3);

        ExBorder (str, 1);
        DataModule1 -> Rating_BallFDQuery -> Next ();
        str++;
        np++;
    } // end while !Eof
    // ������ �������� ��������
    toEx (str, 2, AnsiString ("������� ���� �� ����������:"));
    App.OlePropertyGet ("Cells", str, 4).OlePropertySet ("FormulaR1C1",
        ("=������ (R[-" + AnsiString (str - 4) + "]C:R[-1]C)").c_str ());

    ExAutoFit (1, 7);
    DataModule1 -> Rating_BallFDQuery -> ApplyUpdates ();
    DataModule1 -> Rating_BallFDQuery -> CommitUpdates ();
    ExSave (3);
    // ---end �� ����������

    // -----------end  �������� �����

    App.Clear ();
    Sh.Clear ();
}


void __fastcall TResult_RatingForm::BitBtn2Click (TObject *Sender) {
    // ��������
    if (Edit1 -> Text == "") { // if  ���������
        ShowMessage ("������� ��������� 1 ��� 2!");
        return;
    } // end if  ���������
    else { // else �� ������
        if (Edit1 -> Text != "1" && Edit1 -> Text != "2")
        { // if �������� �� ���������� ����
            ShowMessage ("��������� ������ ���� 1 ��� 2!");
            Edit1 -> Text = "";
            Edit1 -> SetFocus ();
            return;
        } // end if �������� �� ���������� ����
    } // end else �� ������

    if (Edit2 -> Text == "") { // if ������� ���
        ShowMessage ("������� ������� ���!");
        return;
    } // end if ������� ���

    // ----------------------

    rec_rat = Open_SQL (s_r + s_f);

    if (!rec_rat) { // if ��� �������
        ShowMessage ("��� �������!");
        return;
    } // end if ��� �������

    // ����� �����
    Result_RatingForm -> Height = 590;
    Panel2 -> Visible = true;
    Label2 -> Caption = "���������� �� ��������� ������ �� ����������";
    Panel3 -> Visible = true;
}


void __fastcall TResult_RatingForm::DBGrid1TitleClick (TColumn *Column) {
    AnsiString sql_hvost = "";
    // ���������� ��� ����������� ������� ���������� ��� ������ �� ����������

    switch (Column -> Index) { // switch

    case 6: // R_GROUP
        sql_hvost =
            " order by Rating.R_GROUP, People.FAM, People.NAME, People.OTCH";
        Label2 -> Caption = "���������� �� �������� �� ������";
        break;
    case 5: // R_KURS
        sql_hvost =
            " order by Rating.R_KURS, People.FAM, People.NAME, People.OTCH";
        Label2 -> Caption = "���������� �� �������� �� �����";
        break;
    case 4: // R_FAC
        sql_hvost =
            " order by Rating.R_FAC, People.FAM, People.NAME, People.OTCH";
        Label2 -> Caption = "���������� �� �������� �� ����������";
        break;
    case 3: // BALL_R
        sql_hvost = s_f;
        Label2 -> Caption = "���������� �� ��������� ������";
        break;
    case 2: // SPECIAL
        sql_hvost =
            " order by Specializ.SPECIAL, People.FAM, People.NAME, People.OTCH";
        Label2 -> Caption = "���������� �� �������������";
        break;
    case 1: // N_GROUP
        sql_hvost =
            " order by Increment_group.N_GROUP, Specializ.SPECIAL, People.FAM, People.NAME, People.OTCH";
        Label2 -> Caption = "���������� �� ������ ������, �������������";
        break;
    case 0: // FIO
        sql_hvost = " order by People.FAM, People.NAME, People.OTCH ";
        Label2 -> Caption = "���������� �� ���";
        break;
    } // end switch

    rec_rat = Open_SQL (s_r + sql_hvost);

}


void __fastcall TResult_RatingForm::Edit1Change (TObject *Sender) {
    // --����� �����
    Result_RatingForm -> Height = 133;
    Panel2 -> Visible = false;
    Panel3 -> Visible = false;

    // --
    DataModule1 -> Rating_BallFDQuery -> Close ();
}


void __fastcall TResult_RatingForm::SpeedButton1Click (TObject *Sender) {
    // �������� ������ �� DBGrid1 � Excel
    DBgrid_toEx (DBGrid1);
}


void __fastcall TResult_RatingForm::Edit1KeyPress (TObject *Sender, char &Key) {
    DataModule1 -> Edit_Key (Key);
    // ��� �������, ����� � TEdit ����� ���� ������� ������ �����?
}


void __fastcall TResult_RatingForm::ApplicationEvents1Message (tagMSG &Msg,
    bool &Handled) {
    // ������������ ���������� ������ �������� �������� � DBGrid

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


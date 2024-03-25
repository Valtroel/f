#include <vcl.h>
#pragma hdrstop


#include "AdressUnit.h"
#include <ComObj.hpp>
#include "DataModule.h"
#include "DM2Unit.h"
#include "DM3Unit.h"
#include "DM4Unit.h"
#include <Forms.hpp>
#include "Func.h"
#include "SpisocUnit.h"
#include "SplashUnit.h"
#include "SportUnit.h"
#include "SpravkiUnit.h"
#include "SpravUnit.h"
#include "StudUnit.h"
#include "systdate.h"
#include <utilcls.h>


#pragma package (smart_init)
// #pragma link     "DBSecur"
// #pragma link     "RxLogin"
#pragma resource "*.dfm"


TDataModule1 * DataModule1;


bool      result_itog  = false;                                                 // ���������� ��� �������� ������������, ����� calcfield �� ����������� �� ������ ������ ���� true, �� ����� ����������� � ��� ������ calculated ����� ����

int       nom_fac,
          state_query,
          syst_ball    = 10,                                                    // ���������� ���������� ��� ����������� ������� ������ (����������� (5) ��� ������������� (10)) - �� ��������� 10
          uch_god;

TBookmark Bookmark;                                                             // ���������� ��� �������� �������� �� ������ ������ �� ���� ���������

TDateTime curent_date;                                                          // ���������� ��� ������� ����
// curent_date = cur_d ();

// Variant   App_n;
Variant   ExApp;
// Variant   Sh;



// Ball_FDQueryCalcFields
// ball_int
// Ball_Query2CalcFields
// ball_string
// Border_IndentLeft
// Cell_2_Text
// Cell_2_Text_Ole2
// check_fac_group
// check_group_kurs
// Coll_2_Text
// cur_d
// DBgrid_toEx
// Edit_Key
// Edu_PlanFDQueryCalcFields
// Edu_PlanQuery2CalcFields
// EncourageFDQueryCalcFields
// EncourageQuery2CalcFields
// ExAutoFit
// ExBorder
// ExCell
// ExelInit
// ExelInitNoVisible
// FacFullFDQCalcFields
// Grid_V
// HolidayFDQueryCalcFields
// HolidayQuery2CalcFields
// LikvidFDQueryCalcFields
// LikvidQuery2CalcFields
// Mas_God_Semestr
// OpenChildForm
// People_SpravkiSourceDataChange
// People_VedFDQueryCalcFields
// People_VedQuery2CalcFields
// PeopleFDQueryAfterInsert
// PeopleFDQueryBeforePost
// PeopleFDQueryCalcFields
// PeopleFDQueryNewRecord
// PeopleQSourceDataChange
// PeopleQuery2AfterInsert
// PeopleQuery2AfterScroll
// PeopleQuery2CalcFields
// PeopleQuery2NewRecord
// PeopleUpFDQueryCalcFields
// PeopleUpQuery2CalcFields
// Prikaz_KursFDQueryCalcFields
// Prikaz_KursQuery2CalcFields
// Rating_BallFDQueryBeforePost
// Rating_BallQuery2BeforePost
// RegionFDTableNewRecord
// RegionSourceDataChange
// RestoreFDQueryCalcFields
// RestoreQuery2CalcFields
// Result_BallFDQueryCalcFields
// Result_BallQuery2CalcFields
// Search_CK
// search_increment_group
// Spisoc_FDQueryCalcFields
// Spisoc_Query2CalcFields
// SportFDQueryCalcFields
// SportQuery2CalcFields
// str_grid
// Text_predmet
// toEx (AnsiString)
// toEx (Variant)
// Ved_exlistFDQueryCalcFields
// Ved_exlistQuery2CalcFields
// Ved_LikvidGridFDQueryCalcFields
// Ved_LikvidGridQuery2CalcFields
// Ved_RatingFDQueryAfterInsert
// Ved_RatingQuery2AfterInsert
// Ved_RaznicaFDQueryAfterInsert
// Ved_RaznicaQuery2AfterInsert
// VedomostFDQueryAfterInsert
// VedomostFDQueryCalcFields
// VedomostQuery2AfterInsert
// VedomostQuery2CalcFields
// vozvrat_inc_edu_plan
// vozvrat_inc_people
// vozvrat_inc_ved
// vozvrat_inc_ved_rating
// vozvrat_inc_ved_raznica




__fastcall TDataModule1::TDataModule1 (TComponent* Owner) : TDataModule (Owner) {

}

bool __fastcall OpenChildForm (TForm* f, TForm* f_ch)
{ // ������� ������� ������� �������� �����, ���� ��� ������� ���
    // TForm* f - ������� �����
    // TForm* f_ch - �������� �����
    if (f_ch != NULL) {
        for (int i = 0; i < f -> MDIChildCount; i++)
        { // ���� ��� ��������� ���� �������� �������� ����
            if (f -> MDIChildren[i] -> Name == f_ch -> Name)
            { // ���� �����  �������, �� ������ �� Show
                f_ch -> Show ();
                return true;
            } // � ���������� true
        } // end for ����
    }
    // ���� ����� ����� �� �������, ���������� false, � ���� �� ������� ��������������
    return false;

}

void __fastcall Cell_2_Text (Variant WorkSheet, int col1, int col2, int st,
    bool Border, AnsiString Shrift, int kegl, bool Bold, int AlignH, int AlignV,
    bool M_1, bool W_1, AnsiString TextCell)
{ // ��������� ��� ��������� ��������� ����� � �������� � ���� �����, ������� ������, ���� ������������ � ������
    // Variant WorkSheet - ���������� ��� ������ Excel
    // int col1, int col2  - ����� ������� � ������� ������� ��� ��������� ���������
    // int st - ����� ������
    // bool Border - ���������� ������ true - ���������
    // AnsiString Shrift, int kegl - �������� ������ � ��� ������
    // int AlignH, int AlignV - �������������� � ������������ ������������ ������ � ������ (0 - �� ���� �����������)
    // AlignH  2-�� ������ ����, 3-�� ������, 4-�� �������, 6-�� ������
    // AlignV  1-�� ��������, 2-�� ������, 3-�� �������, 4-�� ������

    // bool M1, bool W1  - ����������� �����, ��������� �������� �� ������ (false - �� ���� ��������� ���� ��������)
    // AnsiString TextCell  - ����� � ������

    // ��������� ������ � ��������� ������ ��� ���������
    Variant C1 = SelectCell (col1, st);
    Variant C2 = SelectCell (col2, st);
    // ��������
    Variant Rang1 = Range_Range (WorkSheet, C1, C2);

    // ������� �� ������ � ������  - ���� false, �� �� ����������
    if (W_1)
        W1 (Rang1);

    // ����������� �����  - ���� false, �� �� ����������
    if (M_1)
        M1 (Rang1);

    // ��������� ������
    CellFont (Shrift, kegl, Bold, false, 1, 0, Rang1);

    // ��������� � ������ ��������
    CellValue (TextCell, col1, st);

    // ���������� ������
    if (Border) { // if true - �� ��������� ������
        if (col1 == col2)
            BorderCell (col1, st, 1, 2);
        else { // else ����� ��������� ������ ��� ���� ������
            for (col1; col1 <= col2; col1++) {
                BorderCell (col1, st, 1, 2);
            } // end else ����� ��������� ������ ��� ���� ������
        }
    } // end if true - �� ��������� ������
    // �������������� ������������   - ���  0 ����������� �� ����
    if (AlignH)
        HorizontalAlign (Rang1, AlignH);

    // ������������ ������������     - ���  0 ����������� �� ����
    if (AlignV)
        VerticalAlign (Rang1, AlignV);

}

void __fastcall Cell_2_Text_Ole2 (int col1, int col2, int st, bool Border,
    AnsiString Shrift, int kegl, bool Bold, int AlignH, int AlignV, int Orient,
    bool M_1, bool W_1, AnsiString TextCell)
{ // ��������� ��� ��������� ��������� ����� � �������� � ���� �����, ������� ������, ���� ������������ � ������
    // int col1, int col2  - ����� ������� � ������� ������� ��� ��������� ���������
    // int st - ����� ������
    // bool Border - ���������� ������ true - ���������
    // AnsiString Shrift, int kegl - �������� ������ � ��� ������
    // int AlignH, int AlignV - �������������� � ������������ ������������ ������ � ������ (0 - �� ���� �����������)
    // int Orient -- ��������� ������ � ������ (0 - �� ���� �����������)
    // bool M1, bool W1  - ����������� �����, ��������� �������� �� ������ (false - �� ���� ��������� ���� ��������)
    // AnsiString TextCell  - ����� � ������

    // ��������� ������ � ��������� ������ ��� ���������
    AnsiString diap = mas_column[col1 - 1] + st + ":" +
        mas_column[col2 - 1] + st;

    // ��������
    Variant Rang1 = App_n.OlePropertyGet ("Range", WideString (diap));

    // ��������� ������
    Rang1.OlePropertyGet ("Font").OlePropertySet ("Name", WideString (Shrift));
    Rang1.OlePropertyGet ("Font").OlePropertySet ("Size", kegl);

    if (Bold)
        Rang1.OlePropertyGet ("Font").OlePropertySet ("Bold", True);

    // ��������� � ������ ��������
    Variant cur = Sh.OlePropertyGet ("Cells", st, col1);
    cur.OlePropertySet ("Value", WideString (TextCell));

    // ����������� �����  - ���� false, �� �� ����������
    if (M_1)
        Rang1.OleProcedure ("Merge");

    // ������� �� ������ � ������  - ���� false, �� �� ����������
    if (W_1)
        cur.OlePropertySet ("WrapText", true);

    // ���������� ������
    if (Border) { // if true - �� ��������� ������
        for (int i = 1; i <= 4; i++) {
            Rang1.OlePropertyGet ("Borders").OlePropertyGet ("Item", i)
                .OlePropertySet ("LineStyle", 1);
        }
    } // end if true - �� ��������� ������
    // �������������� ������������   - ���  0 ����������� �� ����
    if (AlignH)
        Rang1.OlePropertySet ("HorizontalAlignment", AlignH);
    // HorizontalAlign (Rang1, AlignH);

    // ������������ ������������     - ���  0 ����������� �� ����
    if (AlignV)
        Rang1.OlePropertySet ("VerticalAlignment", AlignV);
    // VerticalAlign (Rang1, AlignV);

    // ���������� ������ � ������    - ���  0  �� ����
    if (Orient)
        Rang1.OlePropertySet ("Orientation", Orient);

}

void __fastcall Border_IndentLeft (int col1, int col2, int st1, int st2,
    bool M_1, int bord, int ind)
{ // ��������� ��� ��������� ��������� �����, ���������� ����� ������, �������������� ������������ � �������� ind

    // int col1, int col2  - ����� ������� � ������� ������� ��� ��������� ���������
    // int st1, int st2 - ����� ������ � ������ ������
    // bool M1  - ����������� ����� (false - �� ���� ��������� ���� ��������)
    // int bord - ���������� ����� ������ - ���  0 ��������� �� ����    1-�����; 2-������; 3-������; 4-����� ;
    // int ind -  �������������� ������������ � �������� ind - ���  0 ����������� �� ����
    /*
     typedef enum tagXlBordersIndex              typedef enum tagXlLineStyle              typedef enum tagXlBorderWeight
     {                                           {                                         {
     xlInsideHorizontal = 12,                      xlContinuous = 1,      //�������           xlHairline = 1,
     xlInsideVertical = 11,                        xlDash = 4294963181,                       xlMedium = 4294963158,  //����� �������
     xlDiagonalDown = 5,                           xlDashDot = 4,                             xlThick = 4,
     xlDiagonalUp = 6,                             xlDashDotDot = 5,                          xlThin = 2   //�������
     xlEdgeBottom = 9,                             xlDot = 4294963178,                    } XlBorderWeight;
     xlEdgeLeft = 7,                               xlDouble = 4294963177,
     xlEdgeRight = 10,                             xlSlantDashDot = 13,
     xlEdgeTop = 8                                 xlLineStyleNone = 4294963154
     } XlBordersIndex;                            } XlLineStyle;

     */

    // ��������� ������ � ��������� ������ ��� ���������
    AnsiString diap = mas_column[col1 - 1] + st1 + ":" +
        mas_column[col2 - 1] + st2;
    // ��������
    Variant Rang1 = App_n.OlePropertyGet ("Range", WideString (diap));

    // ����������� �����  - ���� false, �� �� ����������
    if (M_1)
        Rang1.OleProcedure ("Merge");

    // ��� �������������� ������������ � �������� ind   - ���  0 ����������� �� ����
    if (ind) {
        Rang1.OlePropertySet ("HorizontalAlignment", 2);
        // HorizontalAlign (2- �� ������ ����)
        Rang1.OlePropertySet ("IndentLevel", ind);
        // ind �� ������� ������ ������
    }

    // ���������� ������
    if (bord) { // if  ��������� ������

        Rang1.OlePropertyGet ("Borders").OlePropertyGet ("Item", bord)
            .OlePropertySet ("LineStyle", 1);

    } // end if ��������� ������
    /* ����� � �����
     //��������� ����� ( �� ����� ������ )
     //����������: �� ������ CellBorderSet () ������ ���� ������
     //            ��������������� ���� ������� SheetOpen ();

     bool ExServer::CellBorderSet ( AnsiString &CellName, int Border_Code,
     int Line_Style )
     {
     try
     {
     switch ( Line_Style )
     {
     //��������� ������ �����
     case LSingle:
     {
     //�������� � ����� ������������� ���������
     //����� � ������ ������� ������
     for ( int i=1; i <= 4; i++ )
     if ( Border_Code & (2<< (i-1)))
     var_Sheet.OlePropertyGet ("Range", CellName).
     OlePropertyGet ("Borders", i).
     OlePropertySet ("LineStyle", LSingle);
     return true;
     }
     //������ �����
     case LBold:
     {
     for ( int i=1; i <= 4; i++ )
     if ( Border_Code & (2<< (i-1)))
     {
     var_Cell = var_Sheet.OlePropertyGet ("Range", CellName);
     var_Cell.OlePropertyGet ("Borders", i).
     OlePropertySet ("LineStyle", LSingle);

     var_Cell.OlePropertyGet ("Borders", i).
     OlePropertySet ("LineStyle", LBold);
     }
     return true;
     }
     //������� ������
     case LDouble:
     {
     for ( int i=1; i <= 4; i++ )
     if ( Border_Code & (2<< (i-1)))
     var_Sheet.OlePropertyGet ("Range", CellName).
     OlePropertyGet ("Borders", i).
     OlePropertySet ("LineStyle", LDouble);
     return true;
     }

     //���� ����� ������ ����� ����� �����
     default:
     {
     for ( int i=1; i <= 4; i++ )
     if ( Border_Code & (2<< (i-1)))
     var_Sheet.OlePropertyGet ("Range", CellName).
     OlePropertyGet ("Borders", i).
     OlePropertySet ("LineStyle", Line_Style);
     return true;
     }
     }
     }
     catch (...)
     {
     MessageBox ( 0, "������ ��� ��������� ����� ������", "������", MB_OK );
     return false;
     }
     }
     */

}

void __fastcall Coll_2_Text (Variant WorkSheet, int col1, int st1, int st2,
    bool Border, AnsiString Shrift, int kegl, bool Bold, int AlignH, int AlignV,
    int Orient, bool M_1, bool W_1, AnsiString TextCell)
{ // ��������� ��� ��������� ��������� ����� � �������� � ���� �����, ������� ������, ���� ������������ � ������
    // Variant WorkSheet - ���������� ��� ������ Excel
    // int col1     - �����  ������� ��� ��������� ���������
    // int st1, st2 - ����� ������ � ������ ������
    // bool Border - ���������� ������ true - ���������
    // AnsiString Shrift, int kegl - �������� ������ � ��� ������
    // int AlignH, int AlignV - �������������� � ������������ ������������ ������ � ������ (0 - �� ���� �����������)
    // int Orient -  ���������� ������ � ������
    // bool M1, bool W1  - ����������� �����, ��������� �������� �� ������ (false - �� ���� ��������� ���� ��������)
    // AnsiString TextCell  - ����� � ������

    // ���������� ������ � ������ - ��� 0 ���������� ������ �� ����
    if (Orient)
        CellOrient (col1, st1, Orient);

    // ��������� ������ � ��������� ������ ��� ���������
    Variant C1 = SelectCell (col1, st1);
    Variant C2 = SelectCell (col1, st2);
    // ��������
    Variant Rang1 = Range_Range (WorkSheet, C1, C2);

    // ������� �� ������ � ������  - ���� false, �� �� ����������
    if (W_1)
        W1 (Rang1);

    // ����������� �����  - ���� false, �� �� ����������
    if (M_1)
        M1 (Rang1);

    // ��������� ������
    CellFont (Shrift, kegl, Bold, false, 1, 0, Rang1);

    // ��������� � ������ ��������
    CellValue (TextCell, col1, st1);

    // ���������� ������
    if (Border) { // if true - �� ��������� ������
        if (st1 == st2)
            BorderCell (col1, st1, 1, 2);
        else { // else ����� ��������� ������ ��� ���� ������
            for (st1; st1 <= st2; st1++) {
                BorderCell (col1, st1, 1, 2);
            } // end else ����� ��������� ������ ��� ���� ������
        }
    } // end if true - �� ��������� ������

    // �������������� ������������   - ���  0 ����������� �� ����
    if (AlignH)
        HorizontalAlign (Rang1, AlignH);

    // ������������ ������������     - ���  0 ����������� �� ����
    if (AlignV)
        VerticalAlign (Rang1, AlignV);

}

void __fastcall DBgrid_toEx (TDBGrid* Grid) { // ������ � Excel �� DBGrida

    // �������� Excel
    ExApp = Variant::CreateObject ("Excel.Application");
    Variant WBook = NewBook (ExApp);
    Variant WSheet = SelectSheet (WBook, "����1");
    // DataModule1 -> ExelInitNoVisible ();
    // Sh = App_n.OlePropertyGet ("ActiveSheet");
    Variant g; // ���������� ��� ����������� ��������� Range

    // ���������� ��� ����������� Query, ������������� � DBGrid-�
    TDataSet* q = Grid -> DataSource -> DataSet;

    // ���������� ������� � Query
    int col_row = q -> RecordCount;

    // ��������, ��� ����, ����� ��������� �� ������ � ������� ����
    // !!!Bookmark=NULL;
    Bookmark = q -> GetBookmark ();
    // ������� �� ������ ������
    q -> First ();
    OVisible (ExApp);
    // ����
    for (int i = 0; i <= col_row; i++) { // for1
        for (int j = 0; j < Grid -> FieldCount; j++) { // for2
            if (!i) {
                // if ��� ������� (�������� ������� ������� �������� �� Grid-a)
                /* DataModule1 -> toEx (i + 1, j + 1,
                 AnsiString (Grid -> Columns -> Items[j] -> Title -> Caption)); */
                CellValue (Grid -> Columns -> Items[j] -> Title -> Caption, j + 1,
                i + 1);
                BorderCell (j + 1, i + 1, 1, 2);
            }
            // ������ ������ ���������
            else { // else ��� ��������� �������
                /* Sh.OlePropertyGet ("Cells", i + 1, j + 1).OlePropertySet
                 ("NumberFormat", "@");
                 // �������� ������
                 DataModule1 -> toEx (i + 1, j + 1,
                 AnsiString (Grid -> Columns -> Items[j] -> Field -> AsString)); */
                if (Grid -> Columns -> Items[j] -> FieldName == "D_EXAM") {
                    CellValue (Grid -> Columns -> Items[j] -> Field -> AsDateTime,
                        j + 1, i + 1);
                }
                else {
                    CellValue (Grid -> Columns -> Items[j] -> Field -> Value,
                        j + 1, i + 1);
                }
                BorderCell (j + 1, i + 1, 1, 2);

            }
            // ���������� �������� ��� ���������� ������
            /* g = App_n.OlePropertyGet ("Range",
             (mas_column[j] + (i + 1)).c_str ()); */
            // ���������
            // DataModule1 -> ExBorder (g);

        } // end for1
        if (i)
            q -> Next (); // ��������� �� ��������� ������, ���� ��� �� �������
    } // end for2

    // ������ ���������� ��������
    // DataModule1 -> ExAutoFit (1, Grid -> FieldCount);
    for (int j = 0; j < Grid -> FieldCount; j++) { // for  AutoFitColumn
        AutoFitColumn (WSheet, j + 1);
    } // end for  AutoFitColumn
    // App_n.OlePropertySet ("Visible", true);
    // OVisible (ExApp);
    // ��������� �� �������� � ������� �
    q -> GotoBookmark (Bookmark);
    q -> FreeBookmark (Bookmark);
    // !!!Bookmark=NULL;

    // ������� ������
    /* App_n.Clear ();
     Sh.Clear (); */

}

void __fastcall str_grid (TStringGrid* SG1) { // ������ � Excel �� StringGrida

    int l; // Left
    int t; // Top
    int r; // Right
    int b; // Bottom

    int col_row;
    int col_col;

    // !!!if (Application -> MessageBox ("��� ������ - ������� Yes, ���������� ������� - ������� No", "������ ������ � Excel", MB_YESNO) == mrYes)
    if (MessageDlg ("��� ������ - ������� Yes, ���������� ������� - ������� No",
        mtConfirmation, TMsgDlgButtons () << mbYes, 0)) {
        t = 0; // Top
        l = 0; // Left
        col_row = SG1 -> RowCount + 1;
        col_col = SG1 -> ColCount;
    }
    else {
        l = SG1 -> Selection.Left;
        t = SG1 -> Selection.Top;
        r = SG1 -> Selection.Right;
        b = SG1 -> Selection.Bottom;

        col_row = b - t + 1;
        col_col = r - l + 1;
    }

    /* DataModule1 -> ExelInit ();
     Sh = App_n.OlePropertyGet ("ActiveSheet");
     Sh.OlePropertyGet ("PageSetup").OlePropertySet ("PrintTitleRows", "$1:$1"); */

    ExApp = Variant::CreateObject ("Excel.Application");
    Variant WBook = NewBook (ExApp);
    Variant WSheet = SelectSheet (WBook, "����1");

    for (int i = 0; i < col_row; i++) { // for1
        for (int j = 0; j < col_col; j++) { // for2
            /* // ������ ������ ���������
             Sh.OlePropertyGet ("Cells", i + 1, j + 1).OlePropertySet
             ("NumberFormat", "@");
             // �������� ������
             DataModule1 -> toEx (i + 1, j + 1,
             AnsiString (SG1 -> Cells[l + j][t + i])); */
            CellValue (SG1 -> Cells[l + j][t + i], j + 1, i + 1);

        } // end for1
    } // end for2

    for (int j = 0; j < col_col; j++) { // for  AutoFitColumn
        AutoFitColumn (WSheet, j + 1);
    } // end for  AutoFitColumn
    /* App_n.Clear ();
     Sh.Clear (); */
    OVisible (ExApp);
}

AnsiString Grid_V (TFDQuery* q, AnsiString f) { // ���������� �������� ����

    // ���������
    if (f == "N_FAC") { // if fac
        return DM2 -> FacultyFDTable -> Lookup ("N_FAC",
            q -> Fields -> FieldByName (f) -> Value, "FAC1");
    } // end if fac

    // �������������
    if (f == "N_SPEC") { // if SPEC
        if (q == DataModule1 -> DiplomREGFDQuery ||
            q == DM3 -> DiplomREG_estFDQuery)
        { // if ��� ��� ������������ ����� ��������
            Variant p = DM2 -> SpecialityFDTable -> Lookup ("N_SPEC",
                q -> Fields -> FieldByName (f) -> Value, "SPEC;CODE_SPEC");
            AnsiString cod_spec = p.GetElement (1);
            cod_spec += " " + p.GetElement (0);
            return cod_spec;
        }
        else
            return DM2 -> SpecialityFDTable -> Lookup ("N_SPEC",
            q -> Fields -> FieldByName (f) -> Value, "SPEC");
    } // end if SPEC

    // �������������
    if (f == "N_SPECIALIZ") { // if SPECIALIZ

        if (q == DataModule1 -> DiplomREGFDQuery ||
            q == DM3 -> DiplomREG_estFDQuery)
        { // if ��� ��� ������������  ��������
            int spec = q -> Fields -> FieldByName ("N_SPEC") -> Value; // N_SPEC
            int spec_v = q -> Fields -> FieldByName ("N_SPECIALIZ") -> Value;
            // N_SPECIALIZ
            int vid_edu_v = q -> Fields -> FieldByName ("VID_EDU") -> Value; // VID_EDU
            Variant d = q -> Fields -> FieldByName ("D_VIPUSK") -> Value; // D_VIPUSK
            bool spec_sport_igry = false;
            // ���������� ��� ����������� ���� �� ������ ������ �� ���������� �����
            // (������ �/� �� ������� 2003 ������������)

            AnsiString cod_specializ = ""; // � �����
            Variant p, v; // ��� ������

            if (spec != 1) { // if spec �����
                p = DM2 -> SpecializFDTable -> Lookup ("N_SPECIALIZ",
                    q -> Fields -> FieldByName (f) -> Value,
                    "SPECIAL_DIRECTION;N_SPEC_DIR");
                if (!p.IsNull ())
                    v = DM2 -> Special_DirFDTable -> Lookup ("N_SPEC_DIR",
                    p.GetElement (1), "CODE_SPEC_DIR");
                cod_specializ = v;
                cod_specializ += " " + p.GetElement (0);
                return cod_specializ;
            } // end if spec �����
            else { // else spec=���������� �������� � �����
                if (d.IsNull ())
                    spec_sport_igry = false;
                else { // else ���� �� ������
                    int dat = d.AsType (4);
                    if ( (spec_v == 24 || spec_v == 25 || spec_v == 20 ||
                        spec_v == 28) && vid_edu_v && dat < 37790)
                    { // 24-��������, 25-�������, 20-���������, 28-������  ������� ����� �� 2003 ����
                        spec_sport_igry = true;
                    }
                } // end else ���� �� ������

                if (spec_sport_igry) {
                    return "���������� ������ �� ���������� �����";
                }
                else {
                    AnsiString sp = DM2 -> SpecializFDTable -> Lookup ("N_SPECIALIZ",
                        q -> Fields -> FieldByName (f) -> Value, "SPECIAL");
                    AnsiString sp_sklon =
                        DM2 -> SpecializFDTable -> Lookup ("N_SPECIALIZ",
                        q -> Fields -> FieldByName (f) -> Value, "SPECIAL_SKLON");

                    if (sp != sp_sklon) {
                        return "���������� ������ �� " + sp_sklon;
                    }
                    else
                        return sp_sklon;
                }
            } // end else spec=���������� �������� � �����

        } // end if ��� ��� ������������ ����� ��������
        else
            return DM2 -> SpecializFDTable -> Lookup ("N_SPECIALIZ",
            q -> Fields -> FieldByName (f) -> Value, "SPECIAL");
    } // end if SPECIALIZ

    // ��� ��������
    if (f == "VID_EDU") { // if  VID_EDU
        // int edu=DM -> SPQuery -> Fields -> FieldByName (f) -> Value;
        int edu = q -> Fields -> FieldByName (f) -> Value;
        switch (edu) { // switch
        case 0:
            return "�/�";
        case 1:
            return "�/�";
        default:
            return "";
        } // end switch
    } // end if  VID_EDU

    // ��� �������� ��� ����������
    if (f == "VID_EDU_INCLUDE") { // if  VID_EDU_INCLUDE
        Variant edu_incl = q -> Fields -> FieldByName (f) -> Value;

        if (edu_incl.IsNull ())
            return "";

        switch (edu_incl.VSmallint) { // switch
        case 0:
            return "�/�";
        case 1:
            return "�/�";
        default:
            return "";
        } // end switch
    } // end if  VID_EDU_INCLUDE

    // ������ ��������
    if (f == "STATUS_PEOPLE") { // if  STATUS_PEOPLE
        int st = q -> Fields -> FieldByName (f) -> Value;
        switch (st) { // switch
        case 1:
            return "�����������";
        case 2:
            return "�����������";
        case 3:
            return "������.������";
        case 4:
            return "��������� ���";
        case 6:
            return "���������";
        default:
            return "";
        } // end switch
    } // end if  STATUS_PEOPLE

    // ��� ���� CK ���� ����� ����������� ��� ����� �� ���������� ��������
    if (f == "CUSTOMER") { // if  CUSTOMER
        int cust = q -> Fields -> FieldByName (f) -> Value;
        switch (cust) { // switch
        case 0:
            return "������";
        case 1:
            return "���";
        case 2:
            return "���";
        case 3:
            return "���";
        case 4:
            return "���";
        default:
            return "";
        } // end switch
    } // end if  CUSTOMER

    if (f == "LANGV_BALL") { // if LANGV_BALL
        int l = q -> Fields -> FieldByName (f) -> Value;
        switch (l) { // switch
        case 2:
            return "�� �����.";
        case 3:
            return "�����.";
        case 4:
            return "���.";
        case 5:
            return "���.";
        case 7:
            return "����������";

        default:
            return (q -> Fields -> FieldByName (f) -> Value - 10);
        } // end switch
    } // end if LANGV_BALL

    // ����
    if (f == "D_PRIKAZ_INCLUDE" || f == "D_VIPUSK" || f == "DATA_R" ||
        f == "D_PUBLIC_PRIKAZ" || f == "D_PRIKAZ_KURS")
    { // if  D_PRIKAZ_INCLUDE   D_VIPUSK
        Variant d = q -> Fields -> FieldByName (f) -> Value;
        if (d.IsNull ())
            return "";
        else {
            // ������ ����
            AnsiString val = d.AsType (varString);
            return val.SubString (0, 10);

            // ���
            /* AnsiString val=d.AsType (varString);
             return val.SubString (7,4); */
        }
    } // if  D_PRIKAZ_INCLUDE   D_VIPUSK

    // ������������
    if (f == "QUALIFICATION") { // if  QUALIFICATION

        AnsiString Qua = q -> Fields -> FieldByName (f) -> Value;
        AnsiString qa_n = "";
        AnsiString Str = "";
        TLocateOptions Flags;

        bool spec_sport_igry = false;
        // ���������� ��� ����������� ���� �� ������ ������ �� ���������� �����
        // (������ �/� �� ������� 2003 ������������)

        if (q == DataModule1 -> DiplomREGFDQuery ||
            q == DM3 -> DiplomREG_estFDQuery)
        { // if ��� ��� ������������ ����� ��������
            int spec_v = q -> Fields -> FieldByName ("N_SPECIALIZ") -> Value;
            int vid_edu_v = q -> Fields -> FieldByName ("VID_EDU") -> Value;
            Variant d = q -> Fields -> FieldByName ("D_VIPUSK") -> Value;
            if (d.IsNull ())
                spec_sport_igry = false;
            else { // else ���� �� ������
                int dat = d.AsType (4);
                if ( (spec_v == 24 || spec_v == 25 || spec_v == 20 ||
                    spec_v == 28) && vid_edu_v && dat < 37790)
                { // 24-��������, 25-�������, 20-���������, 28-������  ������� ����� �� 2003 ����
                    spec_sport_igry = true;
                }
            } // end else ���� �� ������

        }
        // DM1 -> Qalifikation -> Open ();
        for (int i = 1; i <= Qua.Length (); i++) { // for �� Qua
            if (Qua.SubString (i, 1) != ",") { // if Qua!=","
                qa_n = qa_n + Qua.SubString (i, 1);
                if (i == Qua.Length ()) {
                    DM2 -> QualificationFDTable -> First ();
                    DM2 -> QualificationFDTable -> Locate ("NOMER_QU",
                        StrToInt (qa_n), Flags);

                    if (qa_n == 2) {
                        if (spec_sport_igry) {
                            /* if (Str!="") Str=Str+"������ �� ���������� �����. ";
                             else  Str=Str+"������ �� ���������� �����. "; */
                            Str = Str + "������ �� ���������� �����. ";
                        }
                        else {
                            /* if (Str!="") Str=Str+"������ �� "+DM2 -> SpecializTable -> Lookup ("N_SPECIALIZ",q -> Fields -> FieldByName ("N_SPECIALIZ") -> Value,"SPECIAL_SKLON")+". ";
                             else  Str=Str+"������ �� "+DM2 -> SpecializTable -> Lookup ("N_SPECIALIZ",q -> Fields -> FieldByName ("N_SPECIALIZ") -> Value,"SPECIAL_SKLON")+". "; */
                            Str = Str + "������ �� " +
                                DM2 -> SpecializFDTable -> Lookup ("N_SPECIALIZ",
                                q -> Fields -> FieldByName ("N_SPECIALIZ") -> Value,
                                "SPECIAL_SKLON") + ". ";
                        }

                    }
                    else { // else �� ������
                        /* if (Str!="") Str=Str+DM2 -> QualificationTableNAME -> Value.LowerCase ()+". ";
                         else Str=Str+DM2 -> QualificationTableNAME -> Value+". "; */
                        Str = Str + DM2 -> QualificationFDTableNAME -> Value + ". ";
                    }
                    qa_n = "";
                }
            } // end if Qua!=","
            else { // else Qua==","

                DM2 -> QualificationFDTable -> First ();
                DM2 -> QualificationFDTable -> Locate ("NOMER_QU",
                    StrToInt (qa_n), Flags);

                if (qa_n == 2) {
                    if (spec_sport_igry) {
                        /* if (Str!="") Str=Str+"������ �� ���������� �����. ";
                         else  Str=Str+"������ �� ���������� �����. "; */
                        Str = Str + "������ �� ���������� �����. ";
                    }
                    else {
                        /* if (Str!="") Str=Str+"������ �� "+DM2 -> SpecializTable -> Lookup ("N_SPECIALIZ",q -> Fields -> FieldByName ("N_SPECIALIZ") -> Value,"SPECIAL_SKLON")+". ";
                         else  Str=Str+"������ �� "+DM2 -> SpecializTable -> Lookup ("N_SPECIALIZ",q -> Fields -> FieldByName ("N_SPECIALIZ") -> Value,"SPECIAL_SKLON")+". "; */
                        Str = Str + "������ �� " + DM2 -> SpecializFDTable -> Lookup
                            ("N_SPECIALIZ",
                            q -> Fields -> FieldByName ("N_SPECIALIZ") -> Value,
                            "SPECIAL_SKLON") + ". ";
                    }
                }
                else { // else �� ������
                    /* if (Str!="") Str=Str+DM2 -> QualificationTableNAME -> Value.LowerCase ()+". ";
                     else Str=Str+DM2 -> QualificationTableNAME -> Value+". "; */
                    Str = Str + DM2 -> QualificationFDTableNAME -> Value + ". ";
                }
                qa_n = "";
            } // end else Qua==","
        } // end  for �� Qua

        // DM1 -> Qalifikation -> Close ();
        if (Str.Length ())
            Str = Str.SubString (1, Str.Length () - 2);
        return Str;
    } // end if  QUALIFICATION

    Variant rez = q -> Fields -> FieldByName (f) -> Value;

    if (rez.IsNull ())
        return "";

    return rez.AsType (varString);
}

int TDataModule1::Search_CK (int n_s, int n_d, AnsiString n_prikaz,
    AnsiString date_prikaz) { // ��������� ������ � ��������� �������� ���������
    // int n_s - ����� ��������
    // int n_d - ����� ��������
    // 1 - ����������
    // 2 - ������� �� ������ �������������
    // 3 - ������� �� ������ ��� ��������
    // 4 - ������� �� ������ ���������

    // AnsiString n_prikaz    - ����� �������
    // AnsiString date_prikaz - ���� �������

    // *******
    // ���������� 0 - � ������ ������ ��������
    // ���������� 1 - � ������ ���������� �������� ���������
    // ���������� 2 - � ������ ����������� ���������

    int stat = 0; // ���������� ��� ��������

    DataModule1 -> CK_SearchFDQ -> Close ();
    DataModule1 -> CK_SearchFDQ -> ParamByName ("NOMER") -> AsInteger = n_s;
    DataModule1 -> CK_SearchFDQ -> Open ();

    if (DataModule1 -> CK_SearchFDQ -> RecordCount)
    { // if ����� ������� �������� - �� ��� ���� �����������
        // !!!if (Application -> MessageBox ("    � ����� �������� ���� ������� �������. ����������� ���?", "��������������", MB_YESNO) == mrYes)
        if (MessageDlg
            ("    � ����� �������� ���� ������� �������. ����������� ���?",
            mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
        { // if �������� ������������
            DataModule1 -> CK_SearchFDQ -> Edit ();
            DataModule1 -> CK_SearchFDQSTATUS_CK -> Value = 1;
            // ������ ������������� ���������
            AnsiString text = "";
            switch (n_d) {
            case 1:
                text = "�������� ���������� �� ������� ����������. ������ � ";
                break;
            case 2:
                text = "�������� ���������� ��� �������� �� ������ �������������. ������ � ";
                break;
            case 3:
                text = "�������� ���������� ��� �������� �� ������ ��� ��������. ������ � ";
                break;
            case 4:
                text = "�������� ���������� ��� �������� �� ������ ���������. ������ � ";
                break;
            default:
                text = "�������� ����������. ������ � ";
                break;
            }

            text += n_prikaz + " �� " + date_prikaz;
            DataModule1 -> CK_SearchFDQNOTE -> Value = text;

            try { // try ���������� �������
                DataModule1 -> CK_SearchFDQ -> ApplyUpdates ();
                DataModule1 -> CK_SearchFDQ -> CommitUpdates ();
                stat = 2;
            }
            catch (...) { // catch ��������� ����
                DataModule1 -> CK_SearchFDQ -> CancelUpdates ();
                stat = 0;
                ShowMessage (
                    "��� ����������� ��������� ��������� ����. ���������� ��� ���!");
            }

        } // end if �������� ������������
        else { // else �������� ��������  ����������  ������� �� ������ �������������   ������� �� ������ ��� ��������
            stat = 0;
        }
    } // end if ����� ������� �������� - �� ��� ���� �����������
    else
        stat = 1;

    return stat;

}

TDateTime cur_d () // ���������� ������� ����
{
    TDateTime ddd;
    return ddd.CurrentDate ();
}

AnsiString Text_predmet (AnsiString predmet, int specializ)
{ // ��������� ��� ��������� ������ �������� ��� ������ ������������� (��� ������� � ������� � ���-��)
    // --���������� ������ SQL ��� ����, ����� ��� �������
    AnsiString Old_SQL = "SELECT n_specializ, special,  SPECIAL_SKLON, N_SPEC, SPECIAL_DIRECTION FROM specializ \
                    where (n_fac=:FAC) \
                    order by special";

    // --------��������� Query � ����� SQL ������� �� ���������� � ������ �������������
    DataModule1 -> SpecializFDQuery -> Close ();
    DataModule1 -> SpecializFDQuery -> SQL -> Clear ();
    DataModule1 -> SpecializFDQuery -> SQL -> Add ("SELECT n_specializ, special, SPECIAL_SKLON, N_SPEC, SPECIAL_DIRECTION FROM specializ \
                                           where (n_fac=:FAC) and (n_specializ=:SP) \
                                           order by special");
    DataModule1 -> SpecializFDQuery -> ParamByName ("FAC") -> AsInteger = nom_fac;
    DataModule1 -> SpecializFDQuery -> ParamByName ("SP") -> AsInteger = specializ;
    DataModule1 -> SpecializFDQuery -> Open ();

    int N_spec = DataModule1 -> SpecializFDQueryN_SPEC -> Value;
    // ����� �������������
    AnsiString Name_special = DataModule1 -> SpecializFDQuerySPECIAL_SKLON -> Value;
    // �������� �������������

    // -******* ������� �������������
    if (predmet == "�������������") { // if  �������������

        if ( (N_spec == 1 || N_spec == 6) &&
            (specializ != 52 && specializ != 56 && specializ != 2 &&
            specializ != 5 && specializ != 49 && specializ != 48 &&
            specializ != 6))
        { // if ���� ������ ���������� ������    2,5,49,48,6 - ����� � 52,56 - ���
            predmet += " (���������� ������ �� " + Name_special + ")";
        } // end if ���� ������ ���������� ������
        else { // else ����� ������ ���� ������ �������������
            predmet += " (" + Name_special + ")";
        } // end else ����� ������ ���� ������ �������������
        return predmet;
    } // end if  �������������

    // -******* ������� ��� �� �������������
    if (predmet == "��� �� �������������") { // if  ��� �� �������������

        if ( (N_spec == 1 || N_spec == 6) &&
            (specializ != 52 && specializ != 56 && specializ != 2 &&
            specializ != 5 && specializ != 49 && specializ != 48 &&
            specializ != 6))
        { // if ���� ������ ���������� ������     2,5,49,48,6 - ����� � 52,56 - ���
            predmet = "�� �������������: ���������� ������ �� " + Name_special;
        } // end if ���� ������ ���������� ������
        else { // else ����� ������ ���� ������ �������������
            predmet = "�� ������������� " + Name_special;
        } // end else ����� ������ ���� ������ �������������

        return predmet;
    } // end if  ��� �� �������������

    // -******* ������� ��� �� ����������� �������������
    if (predmet == "��� �� ����������� �������������")
    { // if   ��� �� �������������
        predmet = "�� ����������� �������������";
        return predmet;
    } // end if   ��� �� �������������

    // -******* ������� ��� �� �������������
    if (predmet == "��� �� �������������") { // if   ��� �� �������������
        predmet = "�� ������������� (������ � �������� ����������� ����������)";
        return predmet;
    } // end if   ��� �� �������������
    // -*******

    // �������� ���
    // -******* ������� ��� �� ������������� ��� ��������� �������
    if (predmet == "��� �� �� �������������") { // if   ��� �� �� �������������
        predmet = "�� ������������� (������ � ��������������)";
        return predmet;
    } // end if   ��� �� �� �������������
    // -*******

    // �������� ���
    // -******* ������� ��� �� ������������� ��� ��������� �������
    if (predmet == "��������� ������ (�������� �������)")
    { // ��������� ������ (�������� �������)
        predmet = "��������� ������";
        return predmet;
    } // end if   ��� �� �� �������������
    // -*******

    // �������� ���
    if (predmet == "��������� ������ (��� ���)") { // ��������� ������ (��� ���)
        predmet = "��������� ������";
        return predmet;
    } // end if ��������� ������ (��� ���)
    // -*******

    // �������� ���
    if (predmet == "��������� ������ (��� ����)")
    { // ��������� ������ (��� ����)
        predmet = "��������� ������";
        return predmet;
    } // end if   ��������� ������ (��� ����)
    // -*******

    // �������� ���
    if (predmet == "��������� ������ (�����)") { // ��������� ������ (�����)
        predmet = "��������� ������";
        return predmet;
    } // end if ��������� ������ (�����)
    // -*******

    // ---���������� ����� ������ SQL
    DataModule1 -> SpecializFDQuery -> Close ();
    DataModule1 -> SpecializFDQuery -> SQL -> Clear ();
    DataModule1 -> SpecializFDQuery -> SQL -> Add (Old_SQL);

    return predmet;
}

int ball_int (int syst, int ball)
    // ������� ���������� ������ ���� Int, � ����������� �� ������� ������
{ // syst - ������� ������ 5 ��� 10
    // ball - �������� ����, ���������� �� ����
    int ball_return;

    // ----------------��� ������� ���� ������ � ����������� �������
    if (syst == 5) { // if ������� ���� ������ � ����������� �������
        switch (ball) { // switch
        case 11:
            ball_return = 2;
            // ������� 11 (��� 1 � �������������) � 2 � �����������
            break;
        case 12:
            ball_return = 2;
            // ������� 12 (��� 2 � �������������) � 2 � �����������
            break;
        case 13:
            ball_return = 2;
            // ������� 13 (��� 3 � �������������) � 2 � �����������
            break;
        case 14:
            ball_return = 3;
            // ������� 14 (��� 4 � �������������) � 3 � �����������
            break;
        case 15:
            ball_return = 3;
            // ������� 15 (��� 5 � �������������) � 3 � �����������
            break;
        case 16:
            ball_return = 4;
            // ������� 16 (��� 6 � �������������) � 4 � �����������
            break;
        case 17:
            ball_return = 4;
            // ������� 17 (��� 7 � �������������) � 4 � �����������
            break;
        case 18:
            ball_return = 4;
            // ������� 18 (��� 8 � �������������) � 4 � �����������
            break;
        case 19:
            ball_return = 5;
            // ������� 19 (��� 9 � �������������) � 5 � �����������
            break;
        case 20:
            ball_return = 5;
            // ������� 20 (��� 10 � �������������) � 5 � �����������
            break;
        default:
            ball_return = ball;
            // ��������� ������ ��������� � ����������� �������
        } // end switch
    } // end if ������� ���� ������ � ����������� �������

    // ----------------��� ������� ���� ������ � ������������� �������
    if (syst == 10) { // if ������� ���� ������ � ������������� �������
        if (ball > 10)
            ball_return = ball;
        else { // else ������� ����������� ������ � ������������� �������
            switch (ball) { // switch
            case 3:
                ball_return = 14;
                // ������� � ����������� 3 ��� 4 � �������������
                break;
            case 4:
                ball_return = 18;
                // ������� � ����������� 4 ��� 8 � �������������
                break;
            case 5:
                ball_return = 20;
                // ������� � ����������� 5 ��� 10 � �������������
                break;
            default:
                ball_return = ball;
                // ��������� ������ ��������� � ����� ��������
            } // end switch
        } // end else ������� ����������� ������ � ������������� �������

    } // end if ������� ���� ������ � ������������� �������

    if (syst == 15)
        ball_return = ball;

    return ball_return;
}

AnsiString ball_string (int syst, int ball, int full)
    // ������� ���������� ������ ���� AnsiString, � ����������� �� ������� ������
{ // syst - ������� ������ 5 ��� 10  (���� 15 - �� �������� )
    // ball - ����, ���������� ��� �������� ������
    // full - ����� ������� ��� ������������ �������� ������ 0 - �����������, 1 - ������

    AnsiString ball_return, ball_return_full;

    // --------------��� ��������� ������������ ��� �������� ������� ������
    if (syst == 15) { // if ������� ���� ������ � �������� �������
        switch (ball) { // switch

        case 2:
            ball_return = "�������.";
            ball_return_full = "�������������������";
            break;
        case 3:
            ball_return = "�����.";
            ball_return_full = "�����������������";
            break;
        case 4:
            ball_return = "���.";
            ball_return_full = "������";
            break;
        case 5:
            ball_return = "���.";
            ball_return_full = "�������";
            break;

        case 11:
            ball_return = "����";
            ball_return_full = "1 (����)";
            break;
        case 12:
            ball_return = "���";
            ball_return_full = "2 (���)";
            break;
        case 13:
            ball_return = "���";
            ball_return_full = "3 (���)";
            break;
        case 14:
            ball_return = "������";
            ball_return_full = "4 (������)";
            break;
        case 15:
            ball_return = "����";
            ball_return_full = "5 (����)";
            break;
        case 16:
            ball_return = "�����";
            ball_return_full = "6 (�����)";
            break;
        case 17:
            ball_return = "����";
            ball_return_full = "7 (����)";
            break;
        case 18:
            ball_return = "������";
            ball_return_full = "8 (������)";
            break;
        case 19:
            ball_return = "������";
            ball_return_full = "9 (������)";
            break;
        case 20:
            ball_return = "������";
            ball_return_full = "10 (������)";
            break;
        } // end switch
    } // end if ������� ���� ������ � �������� �������
    // --------------��� ��������� ������������ ��� ����������� �������
    if (syst == 5) { // if ������� ���� ������ � ����������� �������
        switch (ball) { // switch
        case 2:
            ball_return = "�������.";
            ball_return_full = "�������������������";
            break;
        case 3:
            ball_return = "�����.";
            ball_return_full = "�����������������";
            break;
        case 4:
            ball_return = "���.";
            ball_return_full = "������";
            break;
        case 5:
            ball_return = "���.";
            ball_return_full = "�������";
            break;

        } // end switch
    } // end if ������� ���� ������ � ����������� �������

    // --------------��� ��������� ������������ ��� ������������� �������
    if (syst == 10) { // if ������� ���� ������ � ������������� �������
        switch (ball) { // switch
        case 11:
            ball_return = "����";
            ball_return_full = "1 (����)";
            break;
        case 12:
            ball_return = "���";
            ball_return_full = "2 (���)";
            break;
        case 13:
            ball_return = "���";
            ball_return_full = "3 (���)";
            break;
        case 14:
            ball_return = "������";
            ball_return_full = "4 (������)";
            break;
        case 15:
            ball_return = "����";
            ball_return_full = "5 (����)";
            break;
        case 16:
            ball_return = "�����";
            ball_return_full = "6 (�����)";
            break;
        case 17:
            ball_return = "����";
            ball_return_full = "7 (����)";
            break;
        case 18:
            ball_return = "������";
            ball_return_full = "8 (������)";
            break;
        case 19:
            ball_return = "������";
            ball_return_full = "9 (������)";
            break;
        case 20:
            ball_return = "������";
            ball_return_full = "10 (������)";
            break;
        } // end switch
    } // end if ������� ���� ������ � ������������� �������
    switch (ball) { // switch
    case 0:
        ball_return = "�������"; // �����. ��� ��� ������
        ball_return_full = "�������"; // ���������  ��� ��� ������
        break;
    case 1:
        ball_return = "�������";
        ball_return_full = "�������";
        break;
    case 6:
        ball_return = "����.";
        ball_return_full = "�� ������";
        break;
    case 7:
        ball_return = "���.";
        ball_return_full = "����������";
        break;
    case 9:
        ball_return = "���������";
        ball_return_full = "���������";
        break;
    } // end switch
    if (full)
        return ball_return_full;
    else
        return ball_return;
}

Variant search_increment_group (AnsiString gr, int edu)
    // �������, ������������ ��������� ������
{
    // one --  �������� ������ ������
    // two --  �������� ���� ��������
    Variant val[2];
    val[0] = Variant (gr);
    val[1] = Variant (edu);
    Variant i_gr = DM2 -> Increment_GroupFDTable -> Lookup ("N_GROUP;VID_EDU",
        VarArrayOf (val, 1), "INC_GROUP");

    return i_gr;
}

bool check_fac_group (AnsiString group)
    // ������� �������� �� ������������ ������ ������ ���������� ����������
{
    AnsiString fac = group.SubString (1, 1);

    if (nom_fac == 3 && fac != "0") {
        ShowMessage ("����������� ������ ����� ������!");
        return false;
    }
    if (nom_fac != StrToInt (fac) && nom_fac != 3)
    { // if   �������� �� ������������ ������ ������ ������� �-��
        ShowMessage ("����������� ������ ����� ������!");
        return false;
    } //
    return true;
}

bool check_group_kurs (AnsiString group, AnsiString kurs)
    // ������� �������� ������������ ������ ������ � ������ �����
{
    if (group.SubString (2, 1) == kurs)
        return true;
    else {
        ShowMessage ("������������� ����� � ������ ������!");
        return false;
    }

}

// ��������� ������������ ������� ����� � ������������ � ��������� ���������
int Mas_God_Semestr (int n_kurs, int n_sem, int god) {
    int *God;
    God = new int[n_kurs];

    /* God[n_kurs-1]=uch_god;
     int sem= (n_sem+1)/2;
     int kurs=n_kurs-2;
     for (kurs; kurs>=0;kurs--)
     {
     God[kurs]=God[kurs+1]-1;
     if ( (sem-1)==kurs)   break;
     } */

    int sem = (n_sem + 1) / 2;
    int kurs = n_kurs - 1;

    God[kurs] = god;

    for (kurs; kurs >= 0; kurs--) {
        if ( (sem - 1) == kurs)
            break;
        else
            God[kurs - 1] = God[kurs] - 1;

    }

    return God[kurs];
}

void __fastcall TDataModule1::vozvrat_inc_ved ()
    // ������� ���������� ��������� ������ ���������
{
    DataModule1 -> FDStoredProcVed -> Prepare ();
    DataModule1 -> FDStoredProcVed -> ExecProc ();

    DataModule1 -> VedomostFDQueryN_VED -> Value =
        DataModule1 -> FDStoredProcVed -> ParamByName ("NV") -> AsInteger;
}

void __fastcall TDataModule1::vozvrat_inc_ved_rating ()
    // ������� ���������� ��������� ������ ��������� ��� ��������
{
    DataModule1 -> FDStoredProcVed_Rating -> Prepare ();
    DataModule1 -> FDStoredProcVed_Rating -> ExecProc ();

    DataModule1 -> Ved_RatingFDQueryN_VED_RATING -> Value =
        DataModule1 -> FDStoredProcVed_Rating -> ParamByName ("NVR") -> AsInteger;
}

void __fastcall TDataModule1::vozvrat_inc_ved_raznica ()
    // ������� ���������� ��������� ������ ��������� ��� ���������� �������
{
    DataModule1 -> FDStoredProcVed_Raznica -> Prepare ();
    DataModule1 -> FDStoredProcVed_Raznica -> ExecProc ();

    DataModule1 -> Ved_RaznicaFDQueryN_VED -> Value =
        DataModule1 -> FDStoredProcVed_Raznica -> ParamByName ("NV") -> AsInteger;
}

int __fastcall TDataModule1::vozvrat_inc_edu_plan ()
    // ������� ���������� ��������� ������ ������ �������� �����
{

    DataModule1 -> FDStoredProcEdu_Plan -> Prepare ();
    DataModule1 -> FDStoredProcEdu_Plan -> ExecProc ();

    return DataModule1 -> FDStoredProcEdu_Plan -> ParamByName ("NPL") -> AsInteger;
}

void __fastcall TDataModule1::vozvrat_inc_people ()
    // ������� ���������� ��������� ������ ��������
{
    DataModule1 -> FDStoredProcPeople -> Prepare ();
    DataModule1 -> FDStoredProcPeople -> ExecProc ();

    DataModule1 -> PeopleFDQueryNOMER -> Value =
        DataModule1 -> FDStoredProcPeople -> ParamByName ("NP") -> AsInteger;
    DataModule1 -> PeopleFDQueryNUMBER -> Value =
        DataModule1 -> FDStoredProcPeople -> ParamByName ("ND") -> AsInteger;
}

void __fastcall TDataModule1::PeopleQuery2NewRecord (TDataSet *DataSet) {
    StudForm -> DBEdit1 -> SetFocus ();
}

void __fastcall TDataModule1::PeopleQuery2AfterScroll (TDataSet *DataSet) {
    // StudForm -> RefreshControl ();
}

void __fastcall TDataModule1::PeopleFDQueryBeforePost (TDataSet *DataSet) {
    DataModule1 -> PeopleFDQueryMARIAGE -> Value = StudForm -> ComboBox1 -> ItemIndex;

    DataModule1 -> PeopleFDQueryEDUCATION -> Value =
        StudForm -> ComboBox2 -> ItemIndex + 1;

    DataModule1 -> PeopleFDQueryARMY -> Value = StudForm -> CheckBox1 -> Checked;

    DataModule1 -> PeopleFDQueryHOSTEL -> Value = StudForm -> CheckBox2 -> Checked;

    DataModule1 -> PeopleFDQueryVID_EDU -> Value = StudForm -> ComboBox3 -> ItemIndex;

    DataModule1 -> PeopleFDQueryVID_EDU_INCLUDE -> Value =
        StudForm -> ComboBox5 -> ItemIndex;
}

void __fastcall TDataModule1::SportQuery2CalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 0)
        DataSet -> FieldValues["SUD_CATEGORY1"] = "���";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 1)
        DataSet -> FieldValues["SUD_CATEGORY1"] = "����� �� ������";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 2)
        DataSet -> FieldValues["SUD_CATEGORY1"] = "����� 1 ���������";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 3)
        DataSet -> FieldValues["SUD_CATEGORY1"] = "����� ������������ ���������";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 4)
        DataSet -> FieldValues["SUD_CATEGORY1"] =
            "����� ������ ������������ ���������";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 5)
        DataSet -> FieldValues["SUD_CATEGORY1"] = "����� ������������� ���������";
}

void __fastcall TDataModule1::Edu_PlanQuery2CalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["ZACH_EXAM"] == 0)
        DataSet -> FieldValues["ZACH_EXAM1"] = "��� ���� ��������";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 1)
        DataSet -> FieldValues["ZACH_EXAM1"] = "�����";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 2)
        DataSet -> FieldValues["ZACH_EXAM1"] = "�������";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 3)
        DataSet -> FieldValues["ZACH_EXAM1"] = "���. �����";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 4)
        DataSet -> FieldValues["ZACH_EXAM1"] = "���";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 5)
        DataSet -> FieldValues["ZACH_EXAM1"] = "����.���.";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 6)
        DataSet -> FieldValues["ZACH_EXAM1"] = "����.���.���.";
}

void __fastcall TDataModule1::Ball_Query2CalcFields (TDataSet *DataSet) {

    if (!DataSet -> FieldValues["BALL"].IsNull ()) {

        if (DataSet -> FieldValues["BALL"] == 0)
            DataSet -> FieldValues["BALL1"] = "�������";
        if (DataSet -> FieldValues["BALL"] == 1)
            DataSet -> FieldValues["BALL1"] = "�����";
        if (DataSet -> FieldValues["BALL"] == 2)
            DataSet -> FieldValues["BALL1"] = "�������.";
        if (DataSet -> FieldValues["BALL"] == 3)
            DataSet -> FieldValues["BALL1"] = "�����.";
        if (DataSet -> FieldValues["BALL"] == 4)
            DataSet -> FieldValues["BALL1"] = "������";
        if (DataSet -> FieldValues["BALL"] == 5)
            DataSet -> FieldValues["BALL1"] = "�������";
        if (DataSet -> FieldValues["BALL"] == 6)
            DataSet -> FieldValues["BALL1"] = "�� ������";
        if (DataSet -> FieldValues["BALL"] == 7)
            DataSet -> FieldValues["BALL1"] = "����������";
        if (DataSet -> FieldValues["BALL"] == 9)
            DataSet -> FieldValues["BALL1"] = "���������";

        if (DataSet -> FieldValues["BALL"] > 10)
            DataSet -> FieldValues["BALL1"] = (DataSet -> FieldValues["BALL"] - 10);

    }
}

void __fastcall TDataModule1::VedomostQuery2CalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["STATUS"] == 0)
        DataSet -> FieldValues["STATUS1"] = "��������";
    if (DataSet -> FieldValues["STATUS"] == 1)
        DataSet -> FieldValues["STATUS1"] = "���������. ����";
    if (DataSet -> FieldValues["STATUS"] == 2)
        DataSet -> FieldValues["STATUS1"] = "��������������";
    if (DataSet -> FieldValues["STATUS"] == 3)
        DataSet -> FieldValues["STATUS1"] = "���������";

    if (DataSet -> FieldValues["VID_EDU_PLAN"] == 0)
        DataSet -> FieldValues["VID_EDU_PLAN1"] = "�������";
    if (DataSet -> FieldValues["VID_EDU_PLAN"] == 1)
        DataSet -> FieldValues["VID_EDU_PLAN1"] = "�������";
}

void __fastcall TDataModule1::PeopleQuery2CalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
}

void __fastcall TDataModule1::Spisoc_Query2CalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
}

void __fastcall TDataModule1::PeopleUpQuery2CalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
}

void __fastcall TDataModule1::VedomostQuery2AfterInsert (TDataSet *DataSet) {
    vozvrat_inc_ved ();
}

void __fastcall TDataModule1::Ved_exlistQuery2CalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
}

void __fastcall TDataModule1::Prikaz_KursQuery2CalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
}

void __fastcall TDataModule1::PeopleQuery2AfterInsert (TDataSet *DataSet) {
    vozvrat_inc_people ();
}

void __fastcall TDataModule1::Result_BallQuery2CalcFields (TDataSet *DataSet) {

    if (result_itog)
    { // �������� �������������� ������ ��� �������� ������������
        if (DataSet -> FieldValues["VID_EDU_PLAN"] == 0)
            DataSet -> FieldValues["VID_EDU_PLAN1"] = "�������";
        if (DataSet -> FieldValues["VID_EDU_PLAN"] == 1)
            DataSet -> FieldValues["VID_EDU_PLAN1"] = "�������";
        // ������ ����������� �������
        if (DataSet -> FieldValues["RESULT"] == 1)
            DataSet -> FieldValues["RESULT1"] = "�����";
        if (DataSet -> FieldValues["RESULT"] == 3)
            DataSet -> FieldValues["RESULT1"] = "3 (�����.)";
        if (DataSet -> FieldValues["RESULT"] == 4)
            DataSet -> FieldValues["RESULT1"] = "4 (���.)";
        if (DataSet -> FieldValues["RESULT"] == 5)
            DataSet -> FieldValues["RESULT1"] = "5 (���.)";
        if (DataSet -> FieldValues["RESULT"] == 7)
            DataSet -> FieldValues["RESULT1"] = "����������";
        if (DataSet -> FieldValues["RESULT"] == 9)
            DataSet -> FieldValues["RESULT1"] = "���������";
        // ������ ������������� �������

        if (!DataSet -> FieldValues["RESULT"].IsNull ()) { // if �������� �� Null
            AnsiString ball_new = "";
            if (DataSet -> FieldValues["RESULT"] >= 14) {
                ball_new =
                    IntToStr (DataModule1 -> Result_BallFDQueryRESULT -> Value - 10);
                DataSet -> FieldValues["RESULT1"] = ball_new;
            }
        } // end if �������� �� Null

        // STATUS_RESULT - ��� ������, ���������� ������
        if (DataSet -> FieldValues["STATUS_RESULT"] == 1)
            DataSet -> FieldValues["STATUS_RESULT1"] = "�������� ���������";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 2)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "���. ���� ��� ��������. ���������";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 3)
            DataSet -> FieldValues["STATUS_RESULT1"] = "��������� �����";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 4)
            DataSet -> FieldValues["STATUS_RESULT1"] = "���������� �������";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 5)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "��������� � �/� �� �/� ��� ��������";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 6)
            DataSet -> FieldValues["STATUS_RESULT1"] = "��������� ��� 2-�� �/�";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 7)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "��������� ��� ��������-����������. �� ��. ����";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 8)
            DataSet -> FieldValues["STATUS_RESULT1"] = "��������� ����� ����";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 9)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "��������� � ������� ����������";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 10)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "��������� ����� �����������";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 11)
            DataSet -> FieldValues["STATUS_RESULT1"] = "���������";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 12)
            DataSet -> FieldValues["STATUS_RESULT1"] = "��������� ����� ���, ���";
        // ���������� ��� ����������� �������� ����
        int p = DataModule1 -> Result_BallFDQueryYEAR_PLAN -> Value;
        AnsiString uch = AnsiString (p) + "-" + AnsiString (p + 1);
        DataSet -> FieldValues["YEAR_PLAN1"] = uch;
    }

}

void __fastcall TDataModule1::RestoreQuery2CalcFields (TDataSet *DataSet) {
    if (result_itog) { // �������� �������������� ������ �� StudForme
        if (DataSet -> FieldValues["VID_RESTORE"])
            DataSet -> FieldValues["VID_RESTORE1"] = "��������";
        else
            DataSet -> FieldValues["VID_RESTORE1"] = "������������";
    }
}

void __fastcall TDataModule1::HolidayQuery2CalcFields (TDataSet *DataSet) {
    if (result_itog) { // �������� �������������� ������ �� StudForme
        int type_hol = DataModule1 -> HolidayFDQueryTYPE_HOL -> Value;
        switch (type_hol) {
        case 1:
            DataSet -> FieldValues["TYPE_HOL1"] = "���� � �/�";
            break;
        case 2:
            DataSet -> FieldValues["TYPE_HOL1"] = "��������� �/�";
            break;
        case 3:
            DataSet -> FieldValues["TYPE_HOL1"] = "����� �� �/�";
            break;
        case 4:
            DataSet -> FieldValues["TYPE_HOL1"] = "������������� ������";
            break;
        case 5:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "��������� �������������� �������";
            break;
        case 6:
            DataSet -> FieldValues["TYPE_HOL1"] = "����� �� �������";
            break;
        case 7:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "������ �� ������������ � �����";
            break;
        case 8:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "������ �� ����� �� �������� �� 3-� ���";
            break;
        case 9:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "������ �� ����� �� �������� �� 3-� ��� �� ��. ����������";
            break;
        case 10:
            DataSet -> FieldValues["TYPE_HOL1"] = "������ �� �����������";
            break;
        case 11:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "������ ��� ����������� ������� ������"; // �������� ���
            break;
        }
    }
}

void __fastcall TDataModule1::EncourageQuery2CalcFields (TDataSet *DataSet) {
    if (result_itog) { // �������� �������������� ������ �� StudForme
        if (DataSet -> FieldValues["TYPE_EN"])
            DataSet -> FieldValues["TYPE_EN1"] = "���������";
        else
            DataSet -> FieldValues["TYPE_EN1"] = "���������";
    }
}

void __fastcall TDataModule1::Ved_RaznicaQuery2AfterInsert (TDataSet *DataSet) {
    vozvrat_inc_ved_raznica ();
}

void __fastcall TDataModule1::LikvidQuery2CalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU_DO"] == 0)
        DataSet -> FieldValues["VID_EDU_DO1"] = "�������";
    if (DataSet -> FieldValues["VID_EDU_DO"] == 1)
        DataSet -> FieldValues["VID_EDU_DO1"] = "�������";

    if (DataSet -> FieldValues["VID_EDU_PO"] == 0)
        DataSet -> FieldValues["VID_EDU_PO1"] = "�������";
    if (DataSet -> FieldValues["VID_EDU_PO"] == 1)
        DataSet -> FieldValues["VID_EDU_PO1"] = "�������";
}

void __fastcall TDataModule1::Ved_LikvidGridQuery2CalcFields (TDataSet *DataSet)
{
    if (DataSet -> FieldValues["VID_EDU_PLAN"] == 0)
        DataSet -> FieldValues["VID_EDU_PLAN1"] = "�������";
    if (DataSet -> FieldValues["VID_EDU_PLAN"] == 1)
        DataSet -> FieldValues["VID_EDU_PLAN1"] = "�������";

    if (!DataSet -> FieldValues["BALL"].IsNull ()) {

        if (DataSet -> FieldValues["BALL"] == 0)
            DataSet -> FieldValues["BALL1"] = "�������";
        if (DataSet -> FieldValues["BALL"] == 1)
            DataSet -> FieldValues["BALL1"] = "�����";
        if (DataSet -> FieldValues["BALL"] == 2)
            DataSet -> FieldValues["BALL1"] = "�������.";
        if (DataSet -> FieldValues["BALL"] == 3)
            DataSet -> FieldValues["BALL1"] = "�����.";
        if (DataSet -> FieldValues["BALL"] == 4)
            DataSet -> FieldValues["BALL1"] = "������";
        if (DataSet -> FieldValues["BALL"] == 5)
            DataSet -> FieldValues["BALL1"] = "�������";
        if (DataSet -> FieldValues["BALL"] == 6)
            DataSet -> FieldValues["BALL1"] = "�� ������";
        if (DataSet -> FieldValues["BALL"] == 7)
            DataSet -> FieldValues["BALL1"] = "����������";
        if (DataSet -> FieldValues["BALL"] == 8)
            DataSet -> FieldValues["BALL1"] = "�� ���������";
        if (DataSet -> FieldValues["BALL"] == 9)
            DataSet -> FieldValues["BALL1"] = "���������";

        if (DataSet -> FieldValues["BALL"] > 10)
            DataSet -> FieldValues["BALL1"] = (DataSet -> FieldValues["BALL"] - 10);

    }

}

void __fastcall TDataModule1::Ved_RatingQuery2AfterInsert (TDataSet *DataSet) {
    vozvrat_inc_ved_rating ();
}

void __fastcall TDataModule1::Rating_BallQuery2BeforePost (TDataSet *DataSet) {
    if (DataModule1 -> Rating_BallFDQueryBALL_R -> Value <
        0 || DataModule1 -> Rating_BallFDQueryBALL_R -> Value > 100) {
        ShowMessage ("������ ������ ���� � ��������� �� 0 �� 100!");
        DataModule1 -> Rating_BallFDQueryBALL_R -> Value = 0;
    }
}

void __fastcall TDataModule1::People_VedQuery2CalcFields (TDataSet *DataSet) {
    if (!DataSet -> FieldValues["BALL"].IsNull ()) {
        DataSet -> FieldValues["BALL1"] =
            ball_string (15, DataModule1 -> People_VedFDQueryBALL -> Value, 1);
        // ������� ���������� ������ ���� AnsiString
    }
    else
        DataSet -> FieldValues["BALL1"] = " ";

    // ���������� ��� ����������� �������� ����
    int p = DataModule1 -> People_VedFDQueryYEAR_PLAN -> Value;
    AnsiString uch = AnsiString (p) + "-" + AnsiString (p + 1);
    DataSet -> FieldValues["YEAR1"] = uch;

    int k = DataModule1 -> People_VedFDQueryZACH_EXAM -> Value;
    AnsiString kk = "";
    switch (k) {
    case 0:
        kk = "��� ��������";
        break;
    case 1:
        kk = "�����";
        break;
    case 2:
        kk = "�������";
        break;
    case 3:
        kk = "���. �����";
        break;
    case 4:
        kk = "��� ���.";
        break;
    }

    DataSet -> FieldValues["ZACH_EXAM1"] = kk;

}

void __fastcall TDataModule1::ExelInit () { // ������� ������� Excel
    try { // try

        App_n = Variant::CreateObject ("Excel.Application");
        App_n.OlePropertyGet ("WorkBooks").OleProcedure ("add");
        Sh = App_n.OlePropertyGet ("WorkSheets", 1);
        App_n.OlePropertySet ("Visible", True);

    } // end try
    catch (...) { // catch
        // !!!Application -> MessageBox ("������ �������� ����� Microsoft Excel!", "������",MB_OK+MB_ICONERROR);
        if (MessageDlg ("������ �������� ����� Microsoft Excel!", mtError,
            TMsgDlgButtons () << mbOK, 0));
    } // end catch
}

void __fastcall TDataModule1::ExelInitNoVisible ()
{ // ������� ������� Excel ��� ������ �����
    try { // try
        App_n = Variant::CreateObject ("Excel.Application");
        App_n.OlePropertyGet ("WorkBooks").OleProcedure ("add");
        Sh = App_n.OlePropertyGet ("WorkSheets", 1);
        App_n.OlePropertySet ("Visible", False);

    } // end try
    catch (...) { // catch
        // !!!Application -> MessageBox ("������ �������� ����� Microsoft Excel!", "������",MB_OK+MB_ICONERROR);
        if (MessageDlg ("������ �������� ����� Microsoft Excel!", mtError,
            TMsgDlgButtons () << mbOK, 0));
    } // end catch
}

void __fastcall TDataModule1::toEx (int Row, int Column, AnsiString data)
{ // ������� ��������� ������ � Excel

    try { // try
        Variant cur = Sh.OlePropertyGet ("Cells", Row, Column);
        cur.OlePropertySet ("Value", data.c_str ());

    } // end try
    catch (...) { // catch
        ;
    } // end catch
}

void __fastcall TDataModule1::toEx (int Row, int Column, Variant data)
{ // ������� ��������� ������ � Excel

    try { // try
        Variant cur = Sh.OlePropertyGet ("Cells", Row, Column);
        cur.OlePropertySet ("Value", data);

    } // end try
    catch (...) { // catch
        ;
    } // end catch
}

void __fastcall TDataModule1::ExAutoFit (int one, int two)
{ // ��������� ��������� �������������� ������ �������
    for (int i = one; i <= two; i++) { // for  AutoFit
        Sh.OlePropertyGet ("Columns").OlePropertyGet ("Item", i).OleProcedure
            ("AutoFit");
    } // end for
}

void __fastcall TDataModule1::ExBorder (Variant range) { // ������� ����������

    for (int i = 1; i <= 4; i++) { // for ����������
        range.OlePropertyGet ("Borders").OlePropertyGet ("Item", i).OlePropertySet
            ("LineStyle", 1);
    } // end for ����������
}

void __fastcall TDataModule1::Edit_Key (char &cyfra)
{ // ��� �������, ����� � TEdit ����� ���� ������� ������ �����?
    if ( (cyfra >= '0') && (cyfra <= '9')) {
    } // �����
    else {
        if (cyfra == 8) {
        } // Backspace (cyfra = '\b')
        else
            cyfra = 0; // �� �����
    }

}

void __fastcall TDataModule1::Ved_RatingFDQueryAfterInsert (TDataSet *DataSet) {
    vozvrat_inc_ved_rating ();
}

void __fastcall TDataModule1::Result_BallFDQueryCalcFields (TDataSet *DataSet) {
    if (result_itog)
    { // �������� �������������� ������ ��� �������� ������������
        if (DataSet -> FieldValues["VID_EDU_PLAN"] == 0)
            DataSet -> FieldValues["VID_EDU_PLAN1"] = "�������";
        if (DataSet -> FieldValues["VID_EDU_PLAN"] == 1)
            DataSet -> FieldValues["VID_EDU_PLAN1"] = "�������";
        // ������ ����������� �������
        if (DataSet -> FieldValues["RESULT"] == 1)
            DataSet -> FieldValues["RESULT1"] = "�����";
        if (DataSet -> FieldValues["RESULT"] == 3)
            DataSet -> FieldValues["RESULT1"] = "3 (�����.)";
        if (DataSet -> FieldValues["RESULT"] == 4)
            DataSet -> FieldValues["RESULT1"] = "4 (���.)";
        if (DataSet -> FieldValues["RESULT"] == 5)
            DataSet -> FieldValues["RESULT1"] = "5 (���.)";
        if (DataSet -> FieldValues["RESULT"] == 7)
            DataSet -> FieldValues["RESULT1"] = "����������";
        if (DataSet -> FieldValues["RESULT"] == 9)
            DataSet -> FieldValues["RESULT1"] = "���������";
        // ������ ������������� �������

        if (!DataSet -> FieldValues["RESULT"].IsNull ()) { // if �������� �� Null
            AnsiString ball_new = "";
            if (DataSet -> FieldValues["RESULT"] >= 14) {
                ball_new =
                    IntToStr (DataModule1 -> Result_BallFDQueryRESULT -> Value - 10);
                DataSet -> FieldValues["RESULT1"] = ball_new;
            }
        } // end if �������� �� Null

        // STATUS_RESULT - ��� ������, ���������� ������
        if (DataSet -> FieldValues["STATUS_RESULT"] == 1)
            DataSet -> FieldValues["STATUS_RESULT1"] = "�������� ���������";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 2)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "���. ���� ��� ��������. ���������";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 3)
            DataSet -> FieldValues["STATUS_RESULT1"] = "��������� �����";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 4)
            DataSet -> FieldValues["STATUS_RESULT1"] = "���������� �������";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 5)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "��������� � �/� �� �/� ��� ��������";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 6)
            DataSet -> FieldValues["STATUS_RESULT1"] = "��������� ��� 2-�� �/�";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 7)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "��������� ��� ��������-����������. �� ��. ����";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 8)
            DataSet -> FieldValues["STATUS_RESULT1"] = "��������� ����� ����";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 9)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "��������� � ������� ����������";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 10)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "��������� ����� �����������";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 11)
            DataSet -> FieldValues["STATUS_RESULT1"] = "���������";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 12)
            DataSet -> FieldValues["STATUS_RESULT1"] = "��������� ����� ���, ���";
        // ���������� ��� ����������� �������� ����
        int p = DataModule1 -> Result_BallFDQueryYEAR_PLAN -> Value;
        AnsiString uch = AnsiString (p) + "-" + AnsiString (p + 1);
        DataSet -> FieldValues["YEAR_PLAN1"] = uch;
    }

}

void __fastcall TDataModule1::Spisoc_FDQueryCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
}

void __fastcall TDataModule1::FacFullFDQCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
}

void __fastcall TDataModule1::Prikaz_KursFDQueryCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
}

void __fastcall TDataModule1::PeopleUpFDQueryCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
}

void __fastcall TDataModule1::RestoreFDQueryCalcFields (TDataSet *DataSet) {
    if (result_itog) { // �������� �������������� ������ �� StudForme
        if (DataSet -> FieldValues["VID_RESTORE"])
            DataSet -> FieldValues["VID_RESTORE1"] = "��������";
        else
            DataSet -> FieldValues["VID_RESTORE1"] = "������������";
    }
}

void __fastcall TDataModule1::EncourageFDQueryCalcFields (TDataSet *DataSet) {
    if (result_itog) { // �������� �������������� ������ �� StudForme
        if (DataSet -> FieldValues["TYPE_EN"])
            DataSet -> FieldValues["TYPE_EN1"] = "���������";
        else
            DataSet -> FieldValues["TYPE_EN1"] = "���������";
    }
}

void __fastcall TDataModule1::PeopleFDQueryCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
}

void __fastcall TDataModule1::SportFDQueryCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 0)
        DataSet -> FieldValues["SUD_CATEGORY1"] = "���";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 1)
        DataSet -> FieldValues["SUD_CATEGORY1"] = "����� �� ������";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 2)
        DataSet -> FieldValues["SUD_CATEGORY1"] = "����� 1 ���������";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 3)
        DataSet -> FieldValues["SUD_CATEGORY1"] = "����� ������������ ���������";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 4)
        DataSet -> FieldValues["SUD_CATEGORY1"] =
            "����� ������ ������������ ���������";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 5)
        DataSet -> FieldValues["SUD_CATEGORY1"] = "����� ������������� ���������";
}

void __fastcall TDataModule1::Ved_exlistFDQueryCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "�������";
}

void __fastcall TDataModule1::Edu_PlanFDQueryCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["ZACH_EXAM"] == 0)
        DataSet -> FieldValues["ZACH_EXAM1"] = "��� ���� ��������";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 1)
        DataSet -> FieldValues["ZACH_EXAM1"] = "�����";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 2)
        DataSet -> FieldValues["ZACH_EXAM1"] = "�������";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 3)
        DataSet -> FieldValues["ZACH_EXAM1"] = "���. �����";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 4)
        DataSet -> FieldValues["ZACH_EXAM1"] = "���";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 5)
        DataSet -> FieldValues["ZACH_EXAM1"] = "����.���.";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 6)
        DataSet -> FieldValues["ZACH_EXAM1"] = "����.���.���.";
}

void __fastcall TDataModule1::VedomostFDQueryAfterInsert (TDataSet *DataSet) {
    vozvrat_inc_ved ();
}

void __fastcall TDataModule1::Ball_FDQueryCalcFields (TDataSet *DataSet) {
    if (!DataSet -> FieldValues["BALL"].IsNull ()) {

        if (DataSet -> FieldValues["BALL"] == 0)
            DataSet -> FieldValues["BALL1"] = "�������";
        if (DataSet -> FieldValues["BALL"] == 1)
            DataSet -> FieldValues["BALL1"] = "�����";
        if (DataSet -> FieldValues["BALL"] == 2)
            DataSet -> FieldValues["BALL1"] = "�������.";
        if (DataSet -> FieldValues["BALL"] == 3)
            DataSet -> FieldValues["BALL1"] = "�����.";
        if (DataSet -> FieldValues["BALL"] == 4)
            DataSet -> FieldValues["BALL1"] = "������";
        if (DataSet -> FieldValues["BALL"] == 5)
            DataSet -> FieldValues["BALL1"] = "�������";
        if (DataSet -> FieldValues["BALL"] == 6)
            DataSet -> FieldValues["BALL1"] = "�� ������";
        if (DataSet -> FieldValues["BALL"] == 7)
            DataSet -> FieldValues["BALL1"] = "����������";
        if (DataSet -> FieldValues["BALL"] == 9)
            DataSet -> FieldValues["BALL1"] = "���������";

        if (DataSet -> FieldValues["BALL"] > 10)
            DataSet -> FieldValues["BALL1"] = (DataSet -> FieldValues["BALL"] - 10);

    }
}

void __fastcall TDataModule1::HolidayFDQueryCalcFields (TDataSet *DataSet) {
    if (result_itog) { // �������� �������������� ������ �� StudForme
        int type_hol = DataModule1 -> HolidayFDQueryTYPE_HOL -> Value;
        switch (type_hol) {
        case 1:
            DataSet -> FieldValues["TYPE_HOL1"] = "���� � �/�";
            break;
        case 2:
            DataSet -> FieldValues["TYPE_HOL1"] = "��������� �/�";
            break;
        case 3:
            DataSet -> FieldValues["TYPE_HOL1"] = "����� �� �/�";
            break;
        case 4:
            DataSet -> FieldValues["TYPE_HOL1"] = "������������� ������";
            break;
        case 5:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "��������� �������������� �������";
            break;
        case 6:
            DataSet -> FieldValues["TYPE_HOL1"] = "����� �� �������";
            break;
        case 7:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "������ �� ������������ � �����";
            break;
        case 8:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "������ �� ����� �� �������� �� 3-� ���";
            break;
        case 9:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "������ �� ����� �� �������� �� 3-� ��� �� ��. ����������";
            break;
        case 10:
            DataSet -> FieldValues["TYPE_HOL1"] = "������ �� �����������";
            break;
        case 11:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "������ ��� ����������� ������� ������"; // �������� ���
            break;
        }
    }
}

void __fastcall TDataModule1::People_VedFDQueryCalcFields (TDataSet *DataSet) {
    if (!DataSet -> FieldValues["BALL"].IsNull ()) {
        DataSet -> FieldValues["BALL1"] =
            ball_string (15, DataModule1 -> People_VedFDQueryBALL -> Value, 1);
        // ������� ���������� ������ ���� AnsiString
    }
    else
        DataSet -> FieldValues["BALL1"] = " ";

    // ���������� ��� ����������� �������� ����
    int p = DataModule1 -> People_VedFDQueryYEAR_PLAN -> Value;
    AnsiString uch = AnsiString (p) + "-" + AnsiString (p + 1);
    DataSet -> FieldValues["YEAR1"] = uch;

    int k = DataModule1 -> People_VedFDQueryZACH_EXAM -> Value;
    AnsiString kk = "";
    switch (k) {
    case 0:
        kk = "��� ��������";
        break;
    case 1:
        kk = "�����";
        break;
    case 2:
        kk = "�������";
        break;
    case 3:
        kk = "���. �����";
        break;
    case 4:
        kk = "��� ���.";
        break;
    }

    DataSet -> FieldValues["ZACH_EXAM1"] = kk;

}

void __fastcall TDataModule1::Ved_LikvidGridFDQueryCalcFields (TDataSet *DataSet)
{
    if (DataSet -> FieldValues["VID_EDU_PLAN"] == 0)
        DataSet -> FieldValues["VID_EDU_PLAN1"] = "�������";
    if (DataSet -> FieldValues["VID_EDU_PLAN"] == 1)
        DataSet -> FieldValues["VID_EDU_PLAN1"] = "�������";

    if (!DataSet -> FieldValues["BALL"].IsNull ()) {

        if (DataSet -> FieldValues["BALL"] == 0)
            DataSet -> FieldValues["BALL1"] = "�������";
        if (DataSet -> FieldValues["BALL"] == 1)
            DataSet -> FieldValues["BALL1"] = "�����";
        if (DataSet -> FieldValues["BALL"] == 2)
            DataSet -> FieldValues["BALL1"] = "�������.";
        if (DataSet -> FieldValues["BALL"] == 3)
            DataSet -> FieldValues["BALL1"] = "�����.";
        if (DataSet -> FieldValues["BALL"] == 4)
            DataSet -> FieldValues["BALL1"] = "������";
        if (DataSet -> FieldValues["BALL"] == 5)
            DataSet -> FieldValues["BALL1"] = "�������";
        if (DataSet -> FieldValues["BALL"] == 6)
            DataSet -> FieldValues["BALL1"] = "�� ������";
        if (DataSet -> FieldValues["BALL"] == 7)
            DataSet -> FieldValues["BALL1"] = "����������";
        if (DataSet -> FieldValues["BALL"] == 8)
            DataSet -> FieldValues["BALL1"] = "�� ���������";
        if (DataSet -> FieldValues["BALL"] == 9)
            DataSet -> FieldValues["BALL1"] = "���������";

        if (DataSet -> FieldValues["BALL"] > 10)
            DataSet -> FieldValues["BALL1"] = (DataSet -> FieldValues["BALL"] - 10);

    }

}

void __fastcall TDataModule1::Rating_BallFDQueryBeforePost (TDataSet *DataSet) {
    if (DataModule1 -> Rating_BallFDQueryBALL_R -> Value <
        0 || DataModule1 -> Rating_BallFDQueryBALL_R -> Value > 100) {
        ShowMessage ("������ ������ ���� � ��������� �� 0 �� 100!");
        DataModule1 -> Rating_BallFDQueryBALL_R -> Value = 0;
    }
}

void __fastcall TDataModule1::Ved_RaznicaFDQueryAfterInsert (TDataSet *DataSet) {
    vozvrat_inc_ved_raznica ();
}

void __fastcall TDataModule1::LikvidFDQueryCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU_DO"] == 0)
        DataSet -> FieldValues["VID_EDU_DO1"] = "�������";
    if (DataSet -> FieldValues["VID_EDU_DO"] == 1)
        DataSet -> FieldValues["VID_EDU_DO1"] = "�������";

    if (DataSet -> FieldValues["VID_EDU_PO"] == 0)
        DataSet -> FieldValues["VID_EDU_PO1"] = "�������";
    if (DataSet -> FieldValues["VID_EDU_PO"] == 1)
        DataSet -> FieldValues["VID_EDU_PO1"] = "�������";
}

void __fastcall TDataModule1::PeopleFDQueryAfterInsert (TDataSet *DataSet) {
    vozvrat_inc_people ();
}

void __fastcall TDataModule1::PeopleFDQueryNewRecord (TDataSet *DataSet) {
    StudForm -> DBEdit1 -> SetFocus ();
}

void __fastcall TDataModule1::VedomostFDQueryCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["STATUS"] == 0)
        DataSet -> FieldValues["STATUS1"] = "��������";
    if (DataSet -> FieldValues["STATUS"] == 1)
        DataSet -> FieldValues["STATUS1"] = "���������. ����";
    if (DataSet -> FieldValues["STATUS"] == 2)
        DataSet -> FieldValues["STATUS1"] = "��������������";
    if (DataSet -> FieldValues["STATUS"] == 3)
        DataSet -> FieldValues["STATUS1"] = "���������";

    if (DataSet -> FieldValues["VID_EDU_PLAN"] == 0)
        DataSet -> FieldValues["VID_EDU_PLAN1"] = "�������";
    if (DataSet -> FieldValues["VID_EDU_PLAN"] == 1)
        DataSet -> FieldValues["VID_EDU_PLAN1"] = "�������";
}

void __fastcall TDataModule1::People_SpravkiSourceDataChange (TObject *Sender,
    TField *Field)

{
    SpavkiForm -> Memo24 -> Text = "�������� �������� �� " +
        DateToStr (SQLTimeStampToDateTime
        (DataModule1 -> People_SpravkiFDQueryD_PRIKAZ_INCLUDE -> Value)) + " �" +
        IntToStr (DataModule1 -> People_SpravkiFDQueryN_PRIKAZ_INCLUDE -> Value)
        + " ��.";
}

void __fastcall TDataModule1::RegionFDTableNewRecord (TDataSet *DataSet) {
    RegionFDTableN_REGION -> Value = 32000;
}

void __fastcall TDataModule1::PeopleQSourceDataChange (TObject *Sender,
    TField *Field) {
    People_photoFDQuery -> Active = false;
    People_photoFDQuery -> ParamByName ("nomer") -> Value =
        PeopleFDQueryNOMER -> Value;
    People_photoFDQuery -> Active = true;
}

void __fastcall ExCell (Variant WSheet, int col1, int col2, int st, int st2,
    bool Border, AnsiString Shrift, int kegl, bool Bold, int AlignH, int AlignV,
    int Orient, bool M_1, bool W_1, AnsiString TextCell)
{ // ��������� ��� ��������� ��������� ����� � �������� � ���� �����, ������� ������, ���� ������������ � ������
    // int col1, int col2  - ����� ������� � ������� ������� ��� ��������� ���������
    // int st - ����� ������  , int st2 - ����� ��������� ������ ��� ����������� ����� ����
    // bool Border - ���������� ������ true - ���������
    // AnsiString Shrift, int kegl - �������� ������ � ��� ������
    // int AlignH, int AlignV - �������������� � ������������ ������������ ������ � ������ (0 - �� ���� �����������)
    // AlignH  2-�� ������ ����, 3-�� ������, 4-�� �������, 6-�� ������
    // AlignV  1-�� ��������, 2-�� ������, 3-�� �������, 4-�� ������

    // int Orient -- ��������� ������ � ������ (0 - �� ���� �����������)
    // bool M1, bool W1  - ����������� �����, ��������� �������� �� ������ (false - �� ���� ��������� ���� ��������)
    // AnsiString TextCell  - ����� � ������

    // ��������� ������ � ��������� ������ ��� ���������
    AnsiString diap = mas_column[col1 - 1] + st + ":" +
        mas_column[col2 - 1] + st2;

    // ��������
    // !!!Variant Rang1=App.OlePropertyGet ("Range",diap.c_str ());

    Variant Rang1 = Range2 (WSheet, diap);
    // ��������� ������
    CellFont (Shrift.c_str (), kegl, Bold, false, 1, 0, Rang1);
    /* !!!Rang1.OlePropertyGet ("Font").OlePropertySet ("Name",Shrift.c_str ());
     Rang1.OlePropertyGet ("Font").OlePropertySet ("Size",kegl);

     if (Bold)  Rang1.OlePropertyGet ("Font").OlePropertySet ("Bold",True); */

    // ��������� � ������ ��������

    /* Variant cur=Sh.OlePropertyGet ("Cells",st,col1);
     cur.OlePropertySet ("Value",TextCell.c_str ()); */
    CellValue (TextCell, col1, st);

    // ����������� �����  - ���� false, �� �� ����������
    if (M_1) // !!!Rang1.OleProcedure ("Merge");
            M1 (Rang1);
    // ������� �� ������ � ������  - ���� false, �� �� ����������
    if (W_1) // !!!cur.OlePropertySet ("WrapText",true);
            W1 (Rang1);
    // ���������� ������
    if (Border) { // if true - �� ��������� ������
        for (int i = 1; i <= 4; i++) {
            // !!!Rang1.OlePropertyGet ("Borders").OlePropertyGet ("Item",i).OlePropertySet ("LineStyle",1);
            BorderCell (col1, st, 1, 2);
        }
    } // end if true - �� ��������� ������
    // �������������� ������������   - ���  0 ����������� �� ����
    if (AlignH)
        Rang1.OlePropertySet ("HorizontalAlignment", AlignH);
    // HorizontalAlign (Rang1, AlignH);

    // ������������ ������������     - ���  0 ����������� �� ����
    if (AlignV)
        Rang1.OlePropertySet ("VerticalAlignment", AlignV);
    // VerticalAlign (Rang1, AlignV);

    // ���������� ������ � ������    - ���  0  �� ����
    if (Orient)
        Rang1.OlePropertySet ("Orientation", Orient);

}

void __fastcall TDataModule1::RegionSourceDataChange (TObject *Sender,
    TField *Field) {
 /*    if (up_reg) {

        if (region_id == 8) {
            StudForm -> DBEdit18 -> ReadOnly = false;
            StudForm -> DBEdit19 -> ReadOnly = false;
        }
        else {
            StudForm -> DBEdit18 -> ReadOnly = true;
            StudForm -> DBEdit19 -> ReadOnly = true;
            AdressForm = new TAdressForm (this);
            if (region_id == 5) {
                AdressForm -> Label48 -> Visible = false;
                AdressForm -> Label51 -> Visible = false;
                AdressForm -> Label54 -> Visible = false;
                AdressForm -> DistrictDBLkCmbBx -> Visible = false;
                AdressForm -> Type_localityDBLkCmbBx -> Visible = false;
                AdressForm -> LocalityDBLkCmbBx -> Visible = false;
                DataModule1 -> QType_street -> Close ();
                DataModule1 -> QType_street -> Open ();
                AdressForm -> Type_streetDBLkCmbBx -> KeyValue = 1;
            }
            else {
                AdressForm -> Label48 -> Visible = true;
                AdressForm -> Label51 -> Visible = true;
                AdressForm -> Label54 -> Visible = true;
                AdressForm -> DistrictDBLkCmbBx -> Visible = true;
                AdressForm -> Type_localityDBLkCmbBx -> Visible = true;
                AdressForm -> LocalityDBLkCmbBx -> Visible = true;
                DataModule1 -> QDistrict -> Close ();
                DataModule1 -> QDistrict -> ParamByName ("REGION") -> AsInteger =
                    DataModule1 -> RegionFDTableN_REGION -> Value;
                // StudForm -> DBLookupComboBox6 -> KeyValue;
                DataModule1 -> QDistrict -> Open ();
                if (DataModule1 -> PeopleFDQuery -> State == dsInsert) {
                    AdressForm -> DistrictDBLkCmbBx -> KeyValue = -1;
                }
            }
            AdressForm -> ShowModal ();
            if (AdressForm -> AdressSave) {
                StudForm -> DBEdit19 -> Text = AdressForm -> Adress;
            }
        }
    }              */
}

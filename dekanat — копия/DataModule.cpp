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


bool      result_itog  = false;                                                 // переменная для итоговой успеваемости, чтобы calcfield не срабатывало на других формах если true, то будет срабатывать и для других calculated полей тоже

int       nom_fac,
          state_query,
          syst_ball    = 10,                                                    // глобальная переменная для определения системы оценко (пятибальная (5) или десятибальная (10)) - по умолчанию 10
          uch_god;

TBookmark Bookmark;                                                             // переменная для создания закладок на наборы данных во всей программе

TDateTime curent_date;                                                          // переменная для текущей даты
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
{ // функция которая откроет дочернюю форму, если она открыта уже
    // TForm* f - главная форма
    // TForm* f_ch - дочерняя форма
    if (f_ch != NULL) {
        for (int i = 0; i < f -> MDIChildCount; i++)
        { // Цикл для просмотра всех открытых дочерних форм
            if (f -> MDIChildren[i] -> Name == f_ch -> Name)
            { // Если форма  открыта, то делаем ей Show
                f_ch -> Show ();
                return true;
            } // и возвращаем true
        } // end for цикл
    }
    // если такой формы не найдено, возвращаем false, и надо ее открыть самостоятельно
    return false;

}

void __fastcall Cell_2_Text (Variant WorkSheet, int col1, int col2, int st,
    bool Border, AnsiString Shrift, int kegl, bool Bold, int AlignH, int AlignV,
    bool M_1, bool W_1, AnsiString TextCell)
{ // Процедура для установки диапазона ячеек и передачи в него техта, размера шрифта, типа выравнивания в ячейке
    // Variant WorkSheet - переменная для листов Excel
    // int col1, int col2  - номер первого и второго столбца для выделения диапазона
    // int st - номер сторки
    // bool Border - обрамление ячейки true - обрамлять
    // AnsiString Shrift, int kegl - название шрифта и его размер
    // int AlignH, int AlignV - горизонтальное и вертикальное выравнивание текста в ячейке (0 - не надо выравнивать)
    // AlignH  2-по левому краю, 3-по центру, 4-по правому, 6-по ширине
    // AlignV  1-по верхнему, 2-по центру, 3-по нижнему, 4-по высоте

    // bool M1, bool W1  - объединение ячеек, установка переноса по словам (false - не надо выполнять этих действий)
    // AnsiString TextCell  - текст в ячейке

    // установка первой и последней ячейки для диапазона
    Variant C1 = SelectCell (col1, st);
    Variant C2 = SelectCell (col2, st);
    // диапазон
    Variant Rang1 = Range_Range (WorkSheet, C1, C2);

    // перенос по словам в ячейке  - если false, то не объединяем
    if (W_1)
        W1 (Rang1);

    // Объединение ячеек  - если false, то не объединяем
    if (M_1)
        M1 (Rang1);

    // установка шрифта
    CellFont (Shrift, kegl, Bold, false, 1, 0, Rang1);

    // установка в ячейку значения
    CellValue (TextCell, col1, st);

    // обрамление ячейки
    if (Border) { // if true - то обрамляем ячейки
        if (col1 == col2)
            BorderCell (col1, st, 1, 2);
        else { // else нужно обрамлять больше чем одну ячейку
            for (col1; col1 <= col2; col1++) {
                BorderCell (col1, st, 1, 2);
            } // end else нужно обрамлять больше чем одну ячейку
        }
    } // end if true - то обрамляем ячейки
    // горизонтальное выравнивание   - при  0 выравнивать не надо
    if (AlignH)
        HorizontalAlign (Rang1, AlignH);

    // вертикальное выравнивание     - при  0 выравнивать не надо
    if (AlignV)
        VerticalAlign (Rang1, AlignV);

}

void __fastcall Cell_2_Text_Ole2 (int col1, int col2, int st, bool Border,
    AnsiString Shrift, int kegl, bool Bold, int AlignH, int AlignV, int Orient,
    bool M_1, bool W_1, AnsiString TextCell)
{ // Процедура для установки диапазона ячеек и передачи в него техта, размера шрифта, типа выравнивания в ячейке
    // int col1, int col2  - номер первого и второго столбца для выделения диапазона
    // int st - номер сторки
    // bool Border - обрамление ячейки true - обрамлять
    // AnsiString Shrift, int kegl - название шрифта и его размер
    // int AlignH, int AlignV - горизонтальное и вертикальное выравнивание текста в ячейке (0 - не надо выравнивать)
    // int Orient -- оринтация текста в ячейке (0 - не надо выравнивать)
    // bool M1, bool W1  - объединение ячеек, установка переноса по словам (false - не надо выполнять этих действий)
    // AnsiString TextCell  - текст в ячейке

    // установка первой и последней ячейки для диапазона
    AnsiString diap = mas_column[col1 - 1] + st + ":" +
        mas_column[col2 - 1] + st;

    // диапазон
    Variant Rang1 = App_n.OlePropertyGet ("Range", WideString (diap));

    // установка шрифта
    Rang1.OlePropertyGet ("Font").OlePropertySet ("Name", WideString (Shrift));
    Rang1.OlePropertyGet ("Font").OlePropertySet ("Size", kegl);

    if (Bold)
        Rang1.OlePropertyGet ("Font").OlePropertySet ("Bold", True);

    // установка в ячейку значения
    Variant cur = Sh.OlePropertyGet ("Cells", st, col1);
    cur.OlePropertySet ("Value", WideString (TextCell));

    // Объединение ячеек  - если false, то не объединяем
    if (M_1)
        Rang1.OleProcedure ("Merge");

    // перенос по словам в ячейке  - если false, то не объединяем
    if (W_1)
        cur.OlePropertySet ("WrapText", true);

    // обрамление ячейки
    if (Border) { // if true - то обрамляем ячейки
        for (int i = 1; i <= 4; i++) {
            Rang1.OlePropertyGet ("Borders").OlePropertyGet ("Item", i)
                .OlePropertySet ("LineStyle", 1);
        }
    } // end if true - то обрамляем ячейки
    // горизонтальное выравнивание   - при  0 выравнивать не надо
    if (AlignH)
        Rang1.OlePropertySet ("HorizontalAlignment", AlignH);
    // HorizontalAlign (Rang1, AlignH);

    // вертикальное выравнивание     - при  0 выравнивать не надо
    if (AlignV)
        Rang1.OlePropertySet ("VerticalAlignment", AlignV);
    // VerticalAlign (Rang1, AlignV);

    // ориентация текста в ячейке    - при  0  не надо
    if (Orient)
        Rang1.OlePropertySet ("Orientation", Orient);

}

void __fastcall Border_IndentLeft (int col1, int col2, int st1, int st2,
    bool M_1, int bord, int ind)
{ // Процедура для установки диапазона ячеек, обрамление части ячейки, горизонтальное выравнивание с отступом ind

    // int col1, int col2  - номер первого и второго столбца для выделения диапазона
    // int st1, int st2 - номер первой и второй сторки
    // bool M1  - объединение ячеек (false - не надо выполнять этих действий)
    // int bord - обрамление части ячейки - при  0 обрамлять не надо    1-слева; 2-справа; 3-сверху; 4-снизу ;
    // int ind -  горизонтальное выравнивание с отступом ind - при  0 выравнивать не надо
    /*
     typedef enum tagXlBordersIndex              typedef enum tagXlLineStyle              typedef enum tagXlBorderWeight
     {                                           {                                         {
     xlInsideHorizontal = 12,                      xlContinuous = 1,      //обычная           xlHairline = 1,
     xlInsideVertical = 11,                        xlDash = 4294963181,                       xlMedium = 4294963158,  //очень толстая
     xlDiagonalDown = 5,                           xlDashDot = 4,                             xlThick = 4,
     xlDiagonalUp = 6,                             xlDashDotDot = 5,                          xlThin = 2   //обычная
     xlEdgeBottom = 9,                             xlDot = 4294963178,                    } XlBorderWeight;
     xlEdgeLeft = 7,                               xlDouble = 4294963177,
     xlEdgeRight = 10,                             xlSlantDashDot = 13,
     xlEdgeTop = 8                                 xlLineStyleNone = 4294963154
     } XlBordersIndex;                            } XlLineStyle;

     */

    // установка первой и последней ячейки для диапазона
    AnsiString diap = mas_column[col1 - 1] + st1 + ":" +
        mas_column[col2 - 1] + st2;
    // диапазон
    Variant Rang1 = App_n.OlePropertyGet ("Range", WideString (diap));

    // Объединение ячеек  - если false, то не объединяем
    if (M_1)
        Rang1.OleProcedure ("Merge");

    // при горизонтальном выравнивании с отступом ind   - при  0 выравнивать не надо
    if (ind) {
        Rang1.OlePropertySet ("HorizontalAlignment", 2);
        // HorizontalAlign (2- по левому краю)
        Rang1.OlePropertySet ("IndentLevel", ind);
        // ind на сколько делать отступ
    }

    // обрамление ячейки
    if (bord) { // if  обрамляем ячейки

        Rang1.OlePropertyGet ("Borders").OlePropertyGet ("Item", bord)
            .OlePropertySet ("LineStyle", 1);

    } // end if обрамляем ячейки
    /* Взяла в инете
     //Рисование рамки ( по имени ячейки )
     //Примечание: до вызова CellBorderSet () должен быть открыт
     //            соответствующий лист вызовом SheetOpen ();

     bool ExServer::CellBorderSet ( AnsiString &CellName, int Border_Code,
     int Line_Style )
     {
     try
     {
     switch ( Line_Style )
     {
     //одинарная тонкая линия
     case LSingle:
     {
     //проверим в цикле необходимость рисования
     //рамки с каждой стороны ячейки
     for ( int i=1; i <= 4; i++ )
     if ( Border_Code & (2<< (i-1)))
     var_Sheet.OlePropertyGet ("Range", CellName).
     OlePropertyGet ("Borders", i).
     OlePropertySet ("LineStyle", LSingle);
     return true;
     }
     //жирная линия
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
     //двойная тонкая
     case LDouble:
     {
     for ( int i=1; i <= 4; i++ )
     if ( Border_Code & (2<< (i-1)))
     var_Sheet.OlePropertyGet ("Range", CellName).
     OlePropertyGet ("Borders", i).
     OlePropertySet ("LineStyle", LDouble);
     return true;
     }

     //если задан другой стиль линии рамки
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
     MessageBox ( 0, "Ошибка при рисовании рамки ячейки", "Ошибка", MB_OK );
     return false;
     }
     }
     */

}

void __fastcall Coll_2_Text (Variant WorkSheet, int col1, int st1, int st2,
    bool Border, AnsiString Shrift, int kegl, bool Bold, int AlignH, int AlignV,
    int Orient, bool M_1, bool W_1, AnsiString TextCell)
{ // Процедура для установки диапазона ячеек и передачи в него техта, размера шрифта, типа выравнивания в ячейке
    // Variant WorkSheet - переменная для листов Excel
    // int col1     - номер  столбца для выделения диапазона
    // int st1, st2 - номер первой и второй сторки
    // bool Border - обрамление ячейки true - обрамлять
    // AnsiString Shrift, int kegl - название шрифта и его размер
    // int AlignH, int AlignV - горизонтальное и вертикальное выравнивание текста в ячейке (0 - не надо выравнивать)
    // int Orient -  ориентация текста в ячейке
    // bool M1, bool W1  - объединение ячеек, установка переноса по словам (false - не надо выполнять этих действий)
    // AnsiString TextCell  - текст в ячейке

    // ориентация текста в ячейке - при 0 ориентацию делать не надо
    if (Orient)
        CellOrient (col1, st1, Orient);

    // установка первой и последней ячейки для диапазона
    Variant C1 = SelectCell (col1, st1);
    Variant C2 = SelectCell (col1, st2);
    // диапазон
    Variant Rang1 = Range_Range (WorkSheet, C1, C2);

    // перенос по словам в ячейке  - если false, то не объединяем
    if (W_1)
        W1 (Rang1);

    // Объединение ячеек  - если false, то не объединяем
    if (M_1)
        M1 (Rang1);

    // установка шрифта
    CellFont (Shrift, kegl, Bold, false, 1, 0, Rang1);

    // установка в ячейку значения
    CellValue (TextCell, col1, st1);

    // обрамление ячейки
    if (Border) { // if true - то обрамляем ячейки
        if (st1 == st2)
            BorderCell (col1, st1, 1, 2);
        else { // else нужно обрамлять больше чем одну ячейку
            for (st1; st1 <= st2; st1++) {
                BorderCell (col1, st1, 1, 2);
            } // end else нужно обрамлять больше чем одну ячейку
        }
    } // end if true - то обрамляем ячейки

    // горизонтальное выравнивание   - при  0 выравнивать не надо
    if (AlignH)
        HorizontalAlign (Rang1, AlignH);

    // вертикальное выравнивание     - при  0 выравнивать не надо
    if (AlignV)
        VerticalAlign (Rang1, AlignV);

}

void __fastcall DBgrid_toEx (TDBGrid* Grid) { // печать в Excel из DBGrida

    // вызываем Excel
    ExApp = Variant::CreateObject ("Excel.Application");
    Variant WBook = NewBook (ExApp);
    Variant WSheet = SelectSheet (WBook, "Лист1");
    // DataModule1 -> ExelInitNoVisible ();
    // Sh = App_n.OlePropertyGet ("ActiveSheet");
    Variant g; // переменная для определения диапазона Range

    // переменная для определения Query, подключенного к DBGrid-у
    TDataSet* q = Grid -> DataSource -> DataSet;

    // количество записей в Query
    int col_row = q -> RecordCount;

    // Закладка, для того, чтобы вернуться на запись с которой ушли
    // !!!Bookmark=NULL;
    Bookmark = q -> GetBookmark ();
    // переход на первую запись
    q -> First ();
    OVisible (ExApp);
    // Цикл
    for (int i = 0; i <= col_row; i++) { // for1
        for (int j = 0; j < Grid -> FieldCount; j++) { // for2
            if (!i) {
                // if для шапочки (название колонок берется напрямую из Grid-a)
                /* DataModule1 -> toEx (i + 1, j + 1,
                 AnsiString (Grid -> Columns -> Items[j] -> Title -> Caption)); */
                CellValue (Grid -> Columns -> Items[j] -> Title -> Caption, j + 1,
                i + 1);
                BorderCell (j + 1, i + 1, 1, 2);
            }
            // формат ячейки текстовый
            else { // else для остальных записей
                /* Sh.OlePropertyGet ("Cells", i + 1, j + 1).OlePropertySet
                 ("NumberFormat", "@");
                 // передача данных
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
            // определяем диапазон для обрамления ячейки
            /* g = App_n.OlePropertyGet ("Range",
             (mas_column[j] + (i + 1)).c_str ()); */
            // обрамляем
            // DataModule1 -> ExBorder (g);

        } // end for1
        if (i)
            q -> Next (); // переходим на следующюю запись, если это не шапочка
    } // end for2

    // делаем автоширину столбцов
    // DataModule1 -> ExAutoFit (1, Grid -> FieldCount);
    for (int j = 0; j < Grid -> FieldCount; j++) { // for  AutoFitColumn
        AutoFitColumn (WSheet, j + 1);
    } // end for  AutoFitColumn
    // App_n.OlePropertySet ("Visible", true);
    // OVisible (ExApp);
    // переходим на закладку и очищаем её
    q -> GotoBookmark (Bookmark);
    q -> FreeBookmark (Bookmark);
    // !!!Bookmark=NULL;

    // очищаем память
    /* App_n.Clear ();
     Sh.Clear (); */

}

void __fastcall str_grid (TStringGrid* SG1) { // печать в Excel из StringGrida

    int l; // Left
    int t; // Top
    int r; // Right
    int b; // Bottom

    int col_row;
    int col_col;

    // !!!if (Application -> MessageBox ("Все записи - нажмите Yes, Выделенный фрамент - нажмите No", "Печать данных в Excel", MB_YESNO) == mrYes)
    if (MessageDlg ("Все записи - нажмите Yes, Выделенный фрамент - нажмите No",
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
    Variant WSheet = SelectSheet (WBook, "Лист1");

    for (int i = 0; i < col_row; i++) { // for1
        for (int j = 0; j < col_col; j++) { // for2
            /* // формат ячейки текстовый
             Sh.OlePropertyGet ("Cells", i + 1, j + 1).OlePropertySet
             ("NumberFormat", "@");
             // передача данных
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

AnsiString Grid_V (TFDQuery* q, AnsiString f) { // возвращает значение поля

    // факультет
    if (f == "N_FAC") { // if fac
        return DM2 -> FacultyFDTable -> Lookup ("N_FAC",
            q -> Fields -> FieldByName (f) -> Value, "FAC1");
    } // end if fac

    // Специальность
    if (f == "N_SPEC") { // if SPEC
        if (q == DataModule1 -> DiplomREGFDQuery ||
            q == DM3 -> DiplomREG_estFDQuery)
        { // if это для формирования банка дипломов
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

    // Специализация
    if (f == "N_SPECIALIZ") { // if SPECIALIZ

        if (q == DataModule1 -> DiplomREGFDQuery ||
            q == DM3 -> DiplomREG_estFDQuery)
        { // if это для формирования  дипломов
            int spec = q -> Fields -> FieldByName ("N_SPEC") -> Value; // N_SPEC
            int spec_v = q -> Fields -> FieldByName ("N_SPECIALIZ") -> Value;
            // N_SPECIALIZ
            int vid_edu_v = q -> Fields -> FieldByName ("VID_EDU") -> Value; // VID_EDU
            Variant d = q -> Fields -> FieldByName ("D_VIPUSK") -> Value; // D_VIPUSK
            bool spec_sport_igry = false;
            // переменная для определения надо ли писать тренер по спортивным играм
            // (только з/о до выпуска 2003 включительно)

            AnsiString cod_specializ = ""; // с кодом
            Variant p, v; // для поиска

            if (spec != 1) { // if spec НОВАЯ
                p = DM2 -> SpecializFDTable -> Lookup ("N_SPECIALIZ",
                    q -> Fields -> FieldByName (f) -> Value,
                    "SPECIAL_DIRECTION;N_SPEC_DIR");
                if (!p.IsNull ())
                    v = DM2 -> Special_DirFDTable -> Lookup ("N_SPEC_DIR",
                    p.GetElement (1), "CODE_SPEC_DIR");
                cod_specializ = v;
                cod_specializ += " " + p.GetElement (0);
                return cod_specializ;
            } // end if spec НОВАЯ
            else { // else spec=Физическая культура и спорт
                if (d.IsNull ())
                    spec_sport_igry = false;
                else { // else дата не пустая
                    int dat = d.AsType (4);
                    if ( (spec_v == 24 || spec_v == 25 || spec_v == 20 ||
                        spec_v == 28) && vid_edu_v && dat < 37790)
                    { // 24-волейбол, 25-гандбол, 20-баскетбол, 28-теннис  заочной формы до 2003 года
                        spec_sport_igry = true;
                    }
                } // end else дата не пустая

                if (spec_sport_igry) {
                    return "Тренерская работа по спортивным играм";
                }
                else {
                    AnsiString sp = DM2 -> SpecializFDTable -> Lookup ("N_SPECIALIZ",
                        q -> Fields -> FieldByName (f) -> Value, "SPECIAL");
                    AnsiString sp_sklon =
                        DM2 -> SpecializFDTable -> Lookup ("N_SPECIALIZ",
                        q -> Fields -> FieldByName (f) -> Value, "SPECIAL_SKLON");

                    if (sp != sp_sklon) {
                        return "Тренерская работа по " + sp_sklon;
                    }
                    else
                        return sp_sklon;
                }
            } // end else spec=Физическая культура и спорт

        } // end if это для формирования банка дипломов
        else
            return DM2 -> SpecializFDTable -> Lookup ("N_SPECIALIZ",
            q -> Fields -> FieldByName (f) -> Value, "SPECIAL");
    } // end if SPECIALIZ

    // Вид обучения
    if (f == "VID_EDU") { // if  VID_EDU
        // int edu=DM -> SPQuery -> Fields -> FieldByName (f) -> Value;
        int edu = q -> Fields -> FieldByName (f) -> Value;
        switch (edu) { // switch
        case 0:
            return "Д/о";
        case 1:
            return "З/о";
        default:
            return "";
        } // end switch
    } // end if  VID_EDU

    // Вид обучения при зачислении
    if (f == "VID_EDU_INCLUDE") { // if  VID_EDU_INCLUDE
        Variant edu_incl = q -> Fields -> FieldByName (f) -> Value;

        if (edu_incl.IsNull ())
            return "";

        switch (edu_incl.VSmallint) { // switch
        case 0:
            return "Д/о";
        case 1:
            return "З/о";
        default:
            return "";
        } // end switch
    } // end if  VID_EDU_INCLUDE

    // Статус студента
    if (f == "STATUS_PEOPLE") { // if  STATUS_PEOPLE
        int st = q -> Fields -> FieldByName (f) -> Value;
        switch (st) { // switch
        case 1:
            return "Действующий";
        case 2:
            return "Отчисленный";
        case 3:
            return "Академ.отпуск";
        case 4:
            return "Повторный год";
        case 6:
            return "Выпускник";
        default:
            return "";
        } // end switch
    } // end if  STATUS_PEOPLE

    // для табл CK поле отдел образования или отдел по физической культуре
    if (f == "CUSTOMER") { // if  CUSTOMER
        int cust = q -> Fields -> FieldByName (f) -> Value;
        switch (cust) { // switch
        case 0:
            return "ОФКСиТ";
        case 1:
            return "РОО";
        case 2:
            return "РУО";
        case 3:
            return "ГОО";
        case 4:
            return "ГУО";
        default:
            return "";
        } // end switch
    } // end if  CUSTOMER

    if (f == "LANGV_BALL") { // if LANGV_BALL
        int l = q -> Fields -> FieldByName (f) -> Value;
        switch (l) { // switch
        case 2:
            return "не удовл.";
        case 3:
            return "удовл.";
        case 4:
            return "хор.";
        case 5:
            return "отл.";
        case 7:
            return "освобожден";

        default:
            return (q -> Fields -> FieldByName (f) -> Value - 10);
        } // end switch
    } // end if LANGV_BALL

    // Даты
    if (f == "D_PRIKAZ_INCLUDE" || f == "D_VIPUSK" || f == "DATA_R" ||
        f == "D_PUBLIC_PRIKAZ" || f == "D_PRIKAZ_KURS")
    { // if  D_PRIKAZ_INCLUDE   D_VIPUSK
        Variant d = q -> Fields -> FieldByName (f) -> Value;
        if (d.IsNull ())
            return "";
        else {
            // полная дата
            AnsiString val = d.AsType (varString);
            return val.SubString (0, 10);

            // год
            /* AnsiString val=d.AsType (varString);
             return val.SubString (7,4); */
        }
    } // if  D_PRIKAZ_INCLUDE   D_VIPUSK

    // Квалификация
    if (f == "QUALIFICATION") { // if  QUALIFICATION

        AnsiString Qua = q -> Fields -> FieldByName (f) -> Value;
        AnsiString qa_n = "";
        AnsiString Str = "";
        TLocateOptions Flags;

        bool spec_sport_igry = false;
        // переменная для определения надо ли писать тренер по спортивным играм
        // (только з/о до выпуска 2003 включительно)

        if (q == DataModule1 -> DiplomREGFDQuery ||
            q == DM3 -> DiplomREG_estFDQuery)
        { // if это для формирования банка дипломов
            int spec_v = q -> Fields -> FieldByName ("N_SPECIALIZ") -> Value;
            int vid_edu_v = q -> Fields -> FieldByName ("VID_EDU") -> Value;
            Variant d = q -> Fields -> FieldByName ("D_VIPUSK") -> Value;
            if (d.IsNull ())
                spec_sport_igry = false;
            else { // else дата не пустая
                int dat = d.AsType (4);
                if ( (spec_v == 24 || spec_v == 25 || spec_v == 20 ||
                    spec_v == 28) && vid_edu_v && dat < 37790)
                { // 24-волейбол, 25-гандбол, 20-баскетбол, 28-теннис  заочной формы до 2003 года
                    spec_sport_igry = true;
                }
            } // end else дата не пустая

        }
        // DM1 -> Qalifikation -> Open ();
        for (int i = 1; i <= Qua.Length (); i++) { // for по Qua
            if (Qua.SubString (i, 1) != ",") { // if Qua!=","
                qa_n = qa_n + Qua.SubString (i, 1);
                if (i == Qua.Length ()) {
                    DM2 -> QualificationFDTable -> First ();
                    DM2 -> QualificationFDTable -> Locate ("NOMER_QU",
                        StrToInt (qa_n), Flags);

                    if (qa_n == 2) {
                        if (spec_sport_igry) {
                            /* if (Str!="") Str=Str+"тренер по спортивным играм. ";
                             else  Str=Str+"Тренер по спортивным играм. "; */
                            Str = Str + "Тренер по спортивным играм. ";
                        }
                        else {
                            /* if (Str!="") Str=Str+"тренер по "+DM2 -> SpecializTable -> Lookup ("N_SPECIALIZ",q -> Fields -> FieldByName ("N_SPECIALIZ") -> Value,"SPECIAL_SKLON")+". ";
                             else  Str=Str+"Тренер по "+DM2 -> SpecializTable -> Lookup ("N_SPECIALIZ",q -> Fields -> FieldByName ("N_SPECIALIZ") -> Value,"SPECIAL_SKLON")+". "; */
                            Str = Str + "Тренер по " +
                                DM2 -> SpecializFDTable -> Lookup ("N_SPECIALIZ",
                                q -> Fields -> FieldByName ("N_SPECIALIZ") -> Value,
                                "SPECIAL_SKLON") + ". ";
                        }

                    }
                    else { // else не тренер
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
                        /* if (Str!="") Str=Str+"тренер по спортивным играм. ";
                         else  Str=Str+"Тренер по спортивным играм. "; */
                        Str = Str + "Тренер по спортивным играм. ";
                    }
                    else {
                        /* if (Str!="") Str=Str+"тренер по "+DM2 -> SpecializTable -> Lookup ("N_SPECIALIZ",q -> Fields -> FieldByName ("N_SPECIALIZ") -> Value,"SPECIAL_SKLON")+". ";
                         else  Str=Str+"Тренер по "+DM2 -> SpecializTable -> Lookup ("N_SPECIALIZ",q -> Fields -> FieldByName ("N_SPECIALIZ") -> Value,"SPECIAL_SKLON")+". "; */
                        Str = Str + "Тренер по " + DM2 -> SpecializFDTable -> Lookup
                            ("N_SPECIALIZ",
                            q -> Fields -> FieldByName ("N_SPECIALIZ") -> Value,
                            "SPECIAL_SKLON") + ". ";
                    }
                }
                else { // else не тренер
                    /* if (Str!="") Str=Str+DM2 -> QualificationTableNAME -> Value.LowerCase ()+". ";
                     else Str=Str+DM2 -> QualificationTableNAME -> Value+". "; */
                    Str = Str + DM2 -> QualificationFDTableNAME -> Value + ". ";
                }
                qa_n = "";
            } // end else Qua==","
        } // end  for по Qua

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
    AnsiString date_prikaz) { // процедура поиска и изменения целевого контракта
    // int n_s - номер студента
    // int n_d - номер действия
    // 1 - отчисление
    // 2 - перевод на другую специализацию
    // 3 - перевод на другой вид обучения
    // 4 - перевод на другой факультет

    // AnsiString n_prikaz    - номер приказа
    // AnsiString date_prikaz - дата приказа

    // *******
    // возвращает 0 - в случае отмены действия
    // возвращает 1 - в случае отсутствия целевого контракта
    // возвращает 2 - в случае расторжения контракта

    int stat = 0; // переменная для возврата

    DataModule1 -> CK_SearchFDQ -> Close ();
    DataModule1 -> CK_SearchFDQ -> ParamByName ("NOMER") -> AsInteger = n_s;
    DataModule1 -> CK_SearchFDQ -> Open ();

    if (DataModule1 -> CK_SearchFDQ -> RecordCount)
    { // if нашли целевой контракт - то его надо расторгнуть
        // !!!if (Application -> MessageBox ("    У этого студента есть целевой контрак. Расторгнуть его?", "Предупреждение", MB_YESNO) == mrYes)
        if (MessageDlg
            ("    У этого студента есть целевой контрак. Расторгнуть его?",
            mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
        { // if контракт расторгается
            DataModule1 -> CK_SearchFDQ -> Edit ();
            DataModule1 -> CK_SearchFDQSTATUS_CK -> Value = 1;
            // статус расторгнутого контракта
            AnsiString text = "";
            switch (n_d) {
            case 1:
                text = "Контракт расторгнут по причине отчисления. Приказ № ";
                break;
            case 2:
                text = "Контракт расторгнут при переводе на другую специальность. Приказ № ";
                break;
            case 3:
                text = "Контракт расторгнут при переводе на другой вид обучения. Приказ № ";
                break;
            case 4:
                text = "Контракт расторгнут при переводе на другой факультет. Приказ № ";
                break;
            default:
                text = "Контракт расторгнут. Приказ № ";
                break;
            }

            text += n_prikaz + " от " + date_prikaz;
            DataModule1 -> CK_SearchFDQNOTE -> Value = text;

            try { // try сохранение удачное
                DataModule1 -> CK_SearchFDQ -> ApplyUpdates ();
                DataModule1 -> CK_SearchFDQ -> CommitUpdates ();
                stat = 2;
            }
            catch (...) { // catch произошел сбой
                DataModule1 -> CK_SearchFDQ -> CancelUpdates ();
                stat = 0;
                ShowMessage (
                    "При расторжении контракта произошел сбой. Попробуйте еще раз!");
            }

        } // end if контракт расторгается
        else { // else отменить действие  отчисление  перевод на другую специализацию   перевод на другой вид обучения
            stat = 0;
        }
    } // end if нашли целевой контракт - то его надо расторгнуть
    else
        stat = 1;

    return stat;

}

TDateTime cur_d () // возвращает текущую дату
{
    TDateTime ddd;
    return ddd.CurrentDate ();
}

AnsiString Text_predmet (AnsiString predmet, int specializ)
{ // процедура для изменения текста предмета для нужной специализации (Для выписки к диплому и ГОС-ов)
    // --запоминаем старый SQL для того, чтобы его вернуть
    AnsiString Old_SQL = "SELECT n_specializ, special,  SPECIAL_SKLON, N_SPEC, SPECIAL_DIRECTION FROM specializ \
                    where (n_fac=:FAC) \
                    order by special";

    // --------выполняем Query с новым SQL выборка по факультету и номеру специализации
    DataModule1 -> SpecializFDQuery -> Close ();
    DataModule1 -> SpecializFDQuery -> SQL -> Clear ();
    DataModule1 -> SpecializFDQuery -> SQL -> Add ("SELECT n_specializ, special, SPECIAL_SKLON, N_SPEC, SPECIAL_DIRECTION FROM specializ \
                                           where (n_fac=:FAC) and (n_specializ=:SP) \
                                           order by special");
    DataModule1 -> SpecializFDQuery -> ParamByName ("FAC") -> AsInteger = nom_fac;
    DataModule1 -> SpecializFDQuery -> ParamByName ("SP") -> AsInteger = specializ;
    DataModule1 -> SpecializFDQuery -> Open ();

    int N_spec = DataModule1 -> SpecializFDQueryN_SPEC -> Value;
    // номер специальности
    AnsiString Name_special = DataModule1 -> SpecializFDQuerySPECIAL_SKLON -> Value;
    // название специализации

    // -******* предмет Специализация
    if (predmet == "Специализация") { // if  Специализация

        if ( (N_spec == 1 || N_spec == 6) &&
            (specializ != 52 && specializ != 56 && specializ != 2 &&
            specializ != 5 && specializ != 49 && specializ != 48 &&
            specializ != 6))
        { // if надо писать тренерская работа    2,5,49,48,6 - ОФКиТ и 52,56 - МВС
            predmet += " (тренерская работа по " + Name_special + ")";
        } // end if надо писать тренерская работа
        else { // else когда писать надо тольку специализацию
            predmet += " (" + Name_special + ")";
        } // end else когда писать надо тольку специализацию
        return predmet;
    } // end if  Специализация

    // -******* предмет ГОС по специализации
    if (predmet == "ГОС по специализации") { // if  ГОС по специализации

        if ( (N_spec == 1 || N_spec == 6) &&
            (specializ != 52 && specializ != 56 && specializ != 2 &&
            specializ != 5 && specializ != 49 && specializ != 48 &&
            specializ != 6))
        { // if надо писать тренерская работа     2,5,49,48,6 - ОФКиТ и 52,56 - МВС
            predmet = "По специализации: Тренерская работа по " + Name_special;
        } // end if надо писать тренерская работа
        else { // else когда писать надо тольку специализацию
            predmet = "По специализации " + Name_special;
        } // end else когда писать надо тольку специализацию

        return predmet;
    } // end if  ГОС по специализации

    // -******* предмет ГОС по направлению специальности
    if (predmet == "ГОС по направлению специальности")
    { // if   ГОС по специальности
        predmet = "По направлению специальности";
        return predmet;
    } // end if   ГОС по специальности

    // -******* предмет ГОС по специальности
    if (predmet == "ГОС по специальности") { // if   ГОС по специальности
        predmet = "По специальности (теория и методика физического воспитания)";
        return predmet;
    } // end if   ГОС по специальности
    // -*******

    // добавила Оля
    // -******* предмет ГОС по специальности для Института туризма
    if (predmet == "ГОС ИТ по специальности") { // if   ГОС ИТ по специальности
        predmet = "По специальности (туризм и гостеприимство)";
        return predmet;
    } // end if   ГОС ИТ по специальности
    // -*******

    // добавила Оля
    // -******* предмет ГОС по специальности для Института туризма
    if (predmet == "Дипломная работа (Институт туризма)")
    { // Дипломная работа (Институт туризма)
        predmet = "Дипломная работа";
        return predmet;
    } // end if   ГОС ИТ по специальности
    // -*******

    // добавила Оля
    if (predmet == "Дипломная работа (СПФ МВС)") { // Дипломная работа (СПФ МВС)
        predmet = "Дипломная работа";
        return predmet;
    } // end if Дипломная работа (СПФ МВС)
    // -*******

    // добавила Оля
    if (predmet == "Дипломная работа (СПФ СИиЕ)")
    { // Дипломная работа (СПФ СИиЕ)
        predmet = "Дипломная работа";
        return predmet;
    } // end if   Дипломная работа (СПФ СИиЕ)
    // -*******

    // добавила Оля
    if (predmet == "Дипломная работа (ОФКиТ)") { // Дипломная работа (ОФКиТ)
        predmet = "Дипломная работа";
        return predmet;
    } // end if Дипломная работа (ОФКиТ)
    // -*******

    // ---возвращаем назад старый SQL
    DataModule1 -> SpecializFDQuery -> Close ();
    DataModule1 -> SpecializFDQuery -> SQL -> Clear ();
    DataModule1 -> SpecializFDQuery -> SQL -> Add (Old_SQL);

    return predmet;
}

int ball_int (int syst, int ball)
    // функция возвращает оценку типа Int, в зависимости от системы оценки
{ // syst - система оценки 5 или 10
    // ball - реальный балл, полученный из базы
    int ball_return;

    // ----------------ЭТО ПЕРЕВОД ВСЕХ ОЦЕНОК В ПЯТИБАЛЬНУЮ СИСТЕМУ
    if (syst == 5) { // if перевод всех оценок в пятибальную систему
        switch (ball) { // switch
        case 11:
            ball_return = 2;
            // перевод 11 (это 1 в десятибальной) в 2 в пятибальной
            break;
        case 12:
            ball_return = 2;
            // перевод 12 (это 2 в десятибальной) в 2 в пятибальной
            break;
        case 13:
            ball_return = 2;
            // перевод 13 (это 3 в десятибальной) в 2 в пятибальной
            break;
        case 14:
            ball_return = 3;
            // перевод 14 (это 4 в десятибальной) в 3 в пятибальной
            break;
        case 15:
            ball_return = 3;
            // перевод 15 (это 5 в десятибальной) в 3 в пятибальной
            break;
        case 16:
            ball_return = 4;
            // перевод 16 (это 6 в десятибальной) в 4 в пятибальной
            break;
        case 17:
            ball_return = 4;
            // перевод 17 (это 7 в десятибальной) в 4 в пятибальной
            break;
        case 18:
            ball_return = 4;
            // перевод 18 (это 8 в десятибальной) в 4 в пятибальной
            break;
        case 19:
            ball_return = 5;
            // перевод 19 (это 9 в десятибальной) в 5 в пятибальной
            break;
        case 20:
            ball_return = 5;
            // перевод 20 (это 10 в десятибальной) в 5 в пятибальной
            break;
        default:
            ball_return = ball;
            // остальные оценки относятся к пятибальной системе
        } // end switch
    } // end if перевод всех оценок в пятибальную систему

    // ----------------ЭТО ПЕРЕВОД ВСЕХ ОЦЕНОК В ДЕСЯТИБАЛЬНУЮ СИСТЕМУ
    if (syst == 10) { // if перевод всех оценок в десятибальную систему
        if (ball > 10)
            ball_return = ball;
        else { // else перевод пятибальных оценок в десятибальную систему
            switch (ball) { // switch
            case 3:
                ball_return = 14;
                // перевод в пятибальной 3 это 4 в десятибальной
                break;
            case 4:
                ball_return = 18;
                // перевод в пятибальной 4 это 8 в десятибальной
                break;
            case 5:
                ball_return = 20;
                // перевод в пятибальной 5 это 10 в десятибальной
                break;
            default:
                ball_return = ball;
                // остальные оценки относятся к обоим системам
            } // end switch
        } // end else перевод пятибальных оценок в десятибальную систему

    } // end if перевод всех оценок в десятибальную систему

    if (syst == 15)
        ball_return = ball;

    return ball_return;
}

AnsiString ball_string (int syst, int ball, int full)
    // функция возвращает оценку типа AnsiString, в зависимости от системы оценки
{ // syst - система оценки 5 или 10  (ЕСЛИ 15 - то реальные )
    // ball - балл, полученный при переводе оценок
    // full - выбор полного или сокращенного названия оценок 0 - сокращенное, 1 - полное

    AnsiString ball_return, ball_return_full;

    // --------------ЭТО ТЕКСТОВЫЕ ФОРМУЛИРОВКИ ДЛЯ РЕАЛЬНОЙ СИСТЕМЫ ОЦЕНОК
    if (syst == 15) { // if перевод всех оценок в реальную систему
        switch (ball) { // switch

        case 2:
            ball_return = "неудовл.";
            ball_return_full = "неудовлетворительно";
            break;
        case 3:
            ball_return = "удовл.";
            ball_return_full = "удовлетворительно";
            break;
        case 4:
            ball_return = "хор.";
            ball_return_full = "хорошо";
            break;
        case 5:
            ball_return = "отл.";
            ball_return_full = "отлично";
            break;

        case 11:
            ball_return = "один";
            ball_return_full = "1 (один)";
            break;
        case 12:
            ball_return = "два";
            ball_return_full = "2 (два)";
            break;
        case 13:
            ball_return = "три";
            ball_return_full = "3 (три)";
            break;
        case 14:
            ball_return = "четыре";
            ball_return_full = "4 (четыре)";
            break;
        case 15:
            ball_return = "пять";
            ball_return_full = "5 (пять)";
            break;
        case 16:
            ball_return = "шесть";
            ball_return_full = "6 (шесть)";
            break;
        case 17:
            ball_return = "семь";
            ball_return_full = "7 (семь)";
            break;
        case 18:
            ball_return = "восемь";
            ball_return_full = "8 (восемь)";
            break;
        case 19:
            ball_return = "девять";
            ball_return_full = "9 (девять)";
            break;
        case 20:
            ball_return = "десять";
            ball_return_full = "10 (десять)";
            break;
        } // end switch
    } // end if перевод всех оценок в реальную систему
    // --------------ЭТО ТЕКСТОВЫЕ ФОРМУЛИРОВКИ ДЛЯ ПЯТИБАЛЬНОЙ СИСТЕМЫ
    if (syst == 5) { // if перевод всех оценок в пятибальную систему
        switch (ball) { // switch
        case 2:
            ball_return = "неудовл.";
            ball_return_full = "неудовлетворительно";
            break;
        case 3:
            ball_return = "удовл.";
            ball_return_full = "удовлетворительно";
            break;
        case 4:
            ball_return = "хор.";
            ball_return_full = "хорошо";
            break;
        case 5:
            ball_return = "отл.";
            ball_return_full = "отлично";
            break;

        } // end switch
    } // end if перевод всех оценок в пятибальную систему

    // --------------ЭТО ТЕКСТОВЫЕ ФОРМУЛИРОВКИ ДЛЯ ДЕСЯТИБАЛЬНОЙ СИСТЕМЫ
    if (syst == 10) { // if перевод всех оценок в десятибальную систему
        switch (ball) { // switch
        case 11:
            ball_return = "один";
            ball_return_full = "1 (один)";
            break;
        case 12:
            ball_return = "два";
            ball_return_full = "2 (два)";
            break;
        case 13:
            ball_return = "три";
            ball_return_full = "3 (три)";
            break;
        case 14:
            ball_return = "четыре";
            ball_return_full = "4 (четыре)";
            break;
        case 15:
            ball_return = "пять";
            ball_return_full = "5 (пять)";
            break;
        case 16:
            ball_return = "шесть";
            ball_return_full = "6 (шесть)";
            break;
        case 17:
            ball_return = "семь";
            ball_return_full = "7 (семь)";
            break;
        case 18:
            ball_return = "восемь";
            ball_return_full = "8 (восемь)";
            break;
        case 19:
            ball_return = "девять";
            ball_return_full = "9 (девять)";
            break;
        case 20:
            ball_return = "десять";
            ball_return_full = "10 (десять)";
            break;
        } // end switch
    } // end if перевод всех оценок в десятибальную систему
    switch (ball) { // switch
    case 0:
        ball_return = "незачет"; // незач. или нет оценки
        ball_return_full = "незачет"; // незачтено  или нет оценки
        break;
    case 1:
        ball_return = "зачтено";
        ball_return_full = "зачтено";
        break;
    case 6:
        ball_return = "неяв.";
        ball_return_full = "не явился";
        break;
    case 7:
        ball_return = "осв.";
        ball_return_full = "освобожден";
        break;
    case 9:
        ball_return = "прослушан";
        ball_return_full = "прослушан";
        break;
    } // end switch
    if (full)
        return ball_return_full;
    else
        return ball_return;
}

Variant search_increment_group (AnsiString gr, int edu)
    // функция, возвращающая инкремент группы
{
    // one --  значение номера группы
    // two --  значиние вида обучения
    Variant val[2];
    val[0] = Variant (gr);
    val[1] = Variant (edu);
    Variant i_gr = DM2 -> Increment_GroupFDTable -> Lookup ("N_GROUP;VID_EDU",
        VarArrayOf (val, 1), "INC_GROUP");

    return i_gr;
}

bool check_fac_group (AnsiString group)
    // функция проверки на соответствие номера группы выбранному факультету
{
    AnsiString fac = group.SubString (1, 1);

    if (nom_fac == 3 && fac != "0") {
        ShowMessage ("Неправильно введен номер группы!");
        return false;
    }
    if (nom_fac != StrToInt (fac) && nom_fac != 3)
    { // if   проверка на соответствие номера группы данному ф-ту
        ShowMessage ("Неправильно введен номер группы!");
        return false;
    } //
    return true;
}

bool check_group_kurs (AnsiString group, AnsiString kurs)
    // функция проверки соответствия номера группы и номера курса
{
    if (group.SubString (2, 1) == kurs)
        return true;
    else {
        ShowMessage ("Несоответсвие курса и номера группы!");
        return false;
    }

}

// Процедура формирования массива годов в соответствии с выбранным семестром
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
    // функция возвращает инкремент номера ведомости
{
    DataModule1 -> FDStoredProcVed -> Prepare ();
    DataModule1 -> FDStoredProcVed -> ExecProc ();

    DataModule1 -> VedomostFDQueryN_VED -> Value =
        DataModule1 -> FDStoredProcVed -> ParamByName ("NV") -> AsInteger;
}

void __fastcall TDataModule1::vozvrat_inc_ved_rating ()
    // функция возвращает инкремент номера ведомости для рейтинга
{
    DataModule1 -> FDStoredProcVed_Rating -> Prepare ();
    DataModule1 -> FDStoredProcVed_Rating -> ExecProc ();

    DataModule1 -> Ved_RatingFDQueryN_VED_RATING -> Value =
        DataModule1 -> FDStoredProcVed_Rating -> ParamByName ("NVR") -> AsInteger;
}

void __fastcall TDataModule1::vozvrat_inc_ved_raznica ()
    // функция возвращает инкремент номера ведомости для ликвидации разницы
{
    DataModule1 -> FDStoredProcVed_Raznica -> Prepare ();
    DataModule1 -> FDStoredProcVed_Raznica -> ExecProc ();

    DataModule1 -> Ved_RaznicaFDQueryN_VED -> Value =
        DataModule1 -> FDStoredProcVed_Raznica -> ParamByName ("NV") -> AsInteger;
}

int __fastcall TDataModule1::vozvrat_inc_edu_plan ()
    // функция возвращает инкремент номера записи учебного плана
{

    DataModule1 -> FDStoredProcEdu_Plan -> Prepare ();
    DataModule1 -> FDStoredProcEdu_Plan -> ExecProc ();

    return DataModule1 -> FDStoredProcEdu_Plan -> ParamByName ("NPL") -> AsInteger;
}

void __fastcall TDataModule1::vozvrat_inc_people ()
    // функция возвращает инкремент номера студента
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
        DataSet -> FieldValues["SUD_CATEGORY1"] = "Нет";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 1)
        DataSet -> FieldValues["SUD_CATEGORY1"] = "Судья по спорту";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 2)
        DataSet -> FieldValues["SUD_CATEGORY1"] = "Судья 1 категории";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 3)
        DataSet -> FieldValues["SUD_CATEGORY1"] = "Судья национальной категории";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 4)
        DataSet -> FieldValues["SUD_CATEGORY1"] =
            "Судья высшей национальной категории";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 5)
        DataSet -> FieldValues["SUD_CATEGORY1"] = "Судья международной категории";
}

void __fastcall TDataModule1::Edu_PlanQuery2CalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["ZACH_EXAM"] == 0)
        DataSet -> FieldValues["ZACH_EXAM1"] = "Нет вида контроля";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 1)
        DataSet -> FieldValues["ZACH_EXAM1"] = "Зачет";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 2)
        DataSet -> FieldValues["ZACH_EXAM1"] = "Экзамен";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 3)
        DataSet -> FieldValues["ZACH_EXAM1"] = "Диф. зачет";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 4)
        DataSet -> FieldValues["ZACH_EXAM1"] = "ГЭК";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 5)
        DataSet -> FieldValues["ZACH_EXAM1"] = "Канд.экз.";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 6)
        DataSet -> FieldValues["ZACH_EXAM1"] = "Канд.диф.зач.";
}

void __fastcall TDataModule1::Ball_Query2CalcFields (TDataSet *DataSet) {

    if (!DataSet -> FieldValues["BALL"].IsNull ()) {

        if (DataSet -> FieldValues["BALL"] == 0)
            DataSet -> FieldValues["BALL1"] = "Незачет";
        if (DataSet -> FieldValues["BALL"] == 1)
            DataSet -> FieldValues["BALL1"] = "Зачет";
        if (DataSet -> FieldValues["BALL"] == 2)
            DataSet -> FieldValues["BALL1"] = "Неудовл.";
        if (DataSet -> FieldValues["BALL"] == 3)
            DataSet -> FieldValues["BALL1"] = "Удовл.";
        if (DataSet -> FieldValues["BALL"] == 4)
            DataSet -> FieldValues["BALL1"] = "Хорошо";
        if (DataSet -> FieldValues["BALL"] == 5)
            DataSet -> FieldValues["BALL1"] = "Отлично";
        if (DataSet -> FieldValues["BALL"] == 6)
            DataSet -> FieldValues["BALL1"] = "Не явился";
        if (DataSet -> FieldValues["BALL"] == 7)
            DataSet -> FieldValues["BALL1"] = "Освобожден";
        if (DataSet -> FieldValues["BALL"] == 9)
            DataSet -> FieldValues["BALL1"] = "Прослушан";

        if (DataSet -> FieldValues["BALL"] > 10)
            DataSet -> FieldValues["BALL1"] = (DataSet -> FieldValues["BALL"] - 10);

    }
}

void __fastcall TDataModule1::VedomostQuery2CalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["STATUS"] == 0)
        DataSet -> FieldValues["STATUS1"] = "Основная";
    if (DataSet -> FieldValues["STATUS"] == 1)
        DataSet -> FieldValues["STATUS1"] = "Экзаменац. лист";
    if (DataSet -> FieldValues["STATUS"] == 2)
        DataSet -> FieldValues["STATUS1"] = "Дополнительная";
    if (DataSet -> FieldValues["STATUS"] == 3)
        DataSet -> FieldValues["STATUS1"] = "Досрочная";

    if (DataSet -> FieldValues["VID_EDU_PLAN"] == 0)
        DataSet -> FieldValues["VID_EDU_PLAN1"] = "Дневное";
    if (DataSet -> FieldValues["VID_EDU_PLAN"] == 1)
        DataSet -> FieldValues["VID_EDU_PLAN1"] = "Заочное";
}

void __fastcall TDataModule1::PeopleQuery2CalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "Дневное";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "Заочное";
}

void __fastcall TDataModule1::Spisoc_Query2CalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "Дневное";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "Заочное";
}

void __fastcall TDataModule1::PeopleUpQuery2CalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "Дневное";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "Заочное";
}

void __fastcall TDataModule1::VedomostQuery2AfterInsert (TDataSet *DataSet) {
    vozvrat_inc_ved ();
}

void __fastcall TDataModule1::Ved_exlistQuery2CalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "Дневное";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "Заочное";
}

void __fastcall TDataModule1::Prikaz_KursQuery2CalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "Дневное";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "Заочное";
}

void __fastcall TDataModule1::PeopleQuery2AfterInsert (TDataSet *DataSet) {
    vozvrat_inc_people ();
}

void __fastcall TDataModule1::Result_BallQuery2CalcFields (TDataSet *DataSet) {

    if (result_itog)
    { // значения перечитываются только для итоговой успеваемости
        if (DataSet -> FieldValues["VID_EDU_PLAN"] == 0)
            DataSet -> FieldValues["VID_EDU_PLAN1"] = "Дневное";
        if (DataSet -> FieldValues["VID_EDU_PLAN"] == 1)
            DataSet -> FieldValues["VID_EDU_PLAN1"] = "Заочное";
        // оценки пятибальной системы
        if (DataSet -> FieldValues["RESULT"] == 1)
            DataSet -> FieldValues["RESULT1"] = "Зачет";
        if (DataSet -> FieldValues["RESULT"] == 3)
            DataSet -> FieldValues["RESULT1"] = "3 (Удовл.)";
        if (DataSet -> FieldValues["RESULT"] == 4)
            DataSet -> FieldValues["RESULT1"] = "4 (Хор.)";
        if (DataSet -> FieldValues["RESULT"] == 5)
            DataSet -> FieldValues["RESULT1"] = "5 (Отл.)";
        if (DataSet -> FieldValues["RESULT"] == 7)
            DataSet -> FieldValues["RESULT1"] = "Освобожден";
        if (DataSet -> FieldValues["RESULT"] == 9)
            DataSet -> FieldValues["RESULT1"] = "Прослушан";
        // оценки десятибальной системы

        if (!DataSet -> FieldValues["RESULT"].IsNull ()) { // if проверка на Null
            AnsiString ball_new = "";
            if (DataSet -> FieldValues["RESULT"] >= 14) {
                ball_new =
                    IntToStr (DataModule1 -> Result_BallFDQueryRESULT -> Value - 10);
                DataSet -> FieldValues["RESULT1"] = ball_new;
            }
        } // end if проверка на Null

        // STATUS_RESULT - это статус, полученной оценки
        if (DataSet -> FieldValues["STATUS_RESULT"] == 1)
            DataSet -> FieldValues["STATUS_RESULT1"] = "Основная ведомость";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 2)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "Экз. лист или дополнит. ведомость";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 3)
            DataSet -> FieldValues["STATUS_RESULT1"] = "Досрочная сдача";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 4)
            DataSet -> FieldValues["STATUS_RESULT1"] = "Ликвидация разницы";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 5)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "Перезачет с д/о на з/о или наоборот";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 6)
            DataSet -> FieldValues["STATUS_RESULT1"] = "Перезачет при 2-ом в/о";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 7)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "Перезачет при переводе-восстановл. из др. ВУЗа";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 8)
            DataSet -> FieldValues["STATUS_RESULT1"] = "Перезачет после РУОР";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 9)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "Перезачет с другого факультета";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 10)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "Перезачет после ПедКолледжа";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 11)
            DataSet -> FieldValues["STATUS_RESULT1"] = "Пересдача";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 12)
            DataSet -> FieldValues["STATUS_RESULT1"] = "Перезачет после ИПК, МКП";
        // переменная для определения учебного года
        int p = DataModule1 -> Result_BallFDQueryYEAR_PLAN -> Value;
        AnsiString uch = AnsiString (p) + "-" + AnsiString (p + 1);
        DataSet -> FieldValues["YEAR_PLAN1"] = uch;
    }

}

void __fastcall TDataModule1::RestoreQuery2CalcFields (TDataSet *DataSet) {
    if (result_itog) { // значения перечитываются только на StudForme
        if (DataSet -> FieldValues["VID_RESTORE"])
            DataSet -> FieldValues["VID_RESTORE1"] = "Отчислен";
        else
            DataSet -> FieldValues["VID_RESTORE1"] = "Восстановлен";
    }
}

void __fastcall TDataModule1::HolidayQuery2CalcFields (TDataSet *DataSet) {
    if (result_itog) { // значения перечитываются только на StudForme
        int type_hol = DataModule1 -> HolidayFDQueryTYPE_HOL -> Value;
        switch (type_hol) {
        case 1:
            DataSet -> FieldValues["TYPE_HOL1"] = "Уход в а/о";
            break;
        case 2:
            DataSet -> FieldValues["TYPE_HOL1"] = "Продление а/о";
            break;
        case 3:
            DataSet -> FieldValues["TYPE_HOL1"] = "Выход из а/о";
            break;
        case 4:
            DataSet -> FieldValues["TYPE_HOL1"] = "Академический отпуск";
            break;
        case 5:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "Продление академического отпуска";
            break;
        case 6:
            DataSet -> FieldValues["TYPE_HOL1"] = "Выход из отпуска";
            break;
        case 7:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "Отпуск по беременности и родам";
            break;
        case 8:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "Отпуск по уходу за ребенком до 3-х лет";
            break;
        case 9:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "Отпуск по уходу за ребенком до 3-х лет со св. посещением";
            break;
        case 10:
            DataSet -> FieldValues["TYPE_HOL1"] = "Отпуск по беремености";
            break;
        case 11:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "Отпуск для прохождения военной службы"; // Добавила Оля
            break;
        }
    }
}

void __fastcall TDataModule1::EncourageQuery2CalcFields (TDataSet *DataSet) {
    if (result_itog) { // значения перечитываются только на StudForme
        if (DataSet -> FieldValues["TYPE_EN"])
            DataSet -> FieldValues["TYPE_EN1"] = "Взыскание";
        else
            DataSet -> FieldValues["TYPE_EN1"] = "Поощрение";
    }
}

void __fastcall TDataModule1::Ved_RaznicaQuery2AfterInsert (TDataSet *DataSet) {
    vozvrat_inc_ved_raznica ();
}

void __fastcall TDataModule1::LikvidQuery2CalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU_DO"] == 0)
        DataSet -> FieldValues["VID_EDU_DO1"] = "Дневное";
    if (DataSet -> FieldValues["VID_EDU_DO"] == 1)
        DataSet -> FieldValues["VID_EDU_DO1"] = "Заочное";

    if (DataSet -> FieldValues["VID_EDU_PO"] == 0)
        DataSet -> FieldValues["VID_EDU_PO1"] = "Дневное";
    if (DataSet -> FieldValues["VID_EDU_PO"] == 1)
        DataSet -> FieldValues["VID_EDU_PO1"] = "Заочное";
}

void __fastcall TDataModule1::Ved_LikvidGridQuery2CalcFields (TDataSet *DataSet)
{
    if (DataSet -> FieldValues["VID_EDU_PLAN"] == 0)
        DataSet -> FieldValues["VID_EDU_PLAN1"] = "Дневное";
    if (DataSet -> FieldValues["VID_EDU_PLAN"] == 1)
        DataSet -> FieldValues["VID_EDU_PLAN1"] = "Заочное";

    if (!DataSet -> FieldValues["BALL"].IsNull ()) {

        if (DataSet -> FieldValues["BALL"] == 0)
            DataSet -> FieldValues["BALL1"] = "Незачет";
        if (DataSet -> FieldValues["BALL"] == 1)
            DataSet -> FieldValues["BALL1"] = "Зачет";
        if (DataSet -> FieldValues["BALL"] == 2)
            DataSet -> FieldValues["BALL1"] = "Неудовл.";
        if (DataSet -> FieldValues["BALL"] == 3)
            DataSet -> FieldValues["BALL1"] = "Удовл.";
        if (DataSet -> FieldValues["BALL"] == 4)
            DataSet -> FieldValues["BALL1"] = "Хорошо";
        if (DataSet -> FieldValues["BALL"] == 5)
            DataSet -> FieldValues["BALL1"] = "Отлично";
        if (DataSet -> FieldValues["BALL"] == 6)
            DataSet -> FieldValues["BALL1"] = "Не явился";
        if (DataSet -> FieldValues["BALL"] == 7)
            DataSet -> FieldValues["BALL1"] = "Освобожден";
        if (DataSet -> FieldValues["BALL"] == 8)
            DataSet -> FieldValues["BALL1"] = "Не прослушан";
        if (DataSet -> FieldValues["BALL"] == 9)
            DataSet -> FieldValues["BALL1"] = "Прослушан";

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
        ShowMessage ("Данные должны быть в диапазоне от 0 до 100!");
        DataModule1 -> Rating_BallFDQueryBALL_R -> Value = 0;
    }
}

void __fastcall TDataModule1::People_VedQuery2CalcFields (TDataSet *DataSet) {
    if (!DataSet -> FieldValues["BALL"].IsNull ()) {
        DataSet -> FieldValues["BALL1"] =
            ball_string (15, DataModule1 -> People_VedFDQueryBALL -> Value, 1);
        // функция возвращает оценку типа AnsiString
    }
    else
        DataSet -> FieldValues["BALL1"] = " ";

    // переменная для определения учебного года
    int p = DataModule1 -> People_VedFDQueryYEAR_PLAN -> Value;
    AnsiString uch = AnsiString (p) + "-" + AnsiString (p + 1);
    DataSet -> FieldValues["YEAR1"] = uch;

    int k = DataModule1 -> People_VedFDQueryZACH_EXAM -> Value;
    AnsiString kk = "";
    switch (k) {
    case 0:
        kk = "нет контроля";
        break;
    case 1:
        kk = "зачет";
        break;
    case 2:
        kk = "экзамен";
        break;
    case 3:
        kk = "диф. зачет";
        break;
    case 4:
        kk = "ГОС экз.";
        break;
    }

    DataSet -> FieldValues["ZACH_EXAM1"] = kk;

}

void __fastcall TDataModule1::ExelInit () { // функция запуска Excel
    try { // try

        App_n = Variant::CreateObject ("Excel.Application");
        App_n.OlePropertyGet ("WorkBooks").OleProcedure ("add");
        Sh = App_n.OlePropertyGet ("WorkSheets", 1);
        App_n.OlePropertySet ("Visible", True);

    } // end try
    catch (...) { // catch
        // !!!Application -> MessageBox ("Ошибка открытия книги Microsoft Excel!", "Ошибка",MB_OK+MB_ICONERROR);
        if (MessageDlg ("Ошибка открытия книги Microsoft Excel!", mtError,
            TMsgDlgButtons () << mbOK, 0));
    } // end catch
}

void __fastcall TDataModule1::ExelInitNoVisible ()
{ // функция запуска Excel без показа книги
    try { // try
        App_n = Variant::CreateObject ("Excel.Application");
        App_n.OlePropertyGet ("WorkBooks").OleProcedure ("add");
        Sh = App_n.OlePropertyGet ("WorkSheets", 1);
        App_n.OlePropertySet ("Visible", False);

    } // end try
    catch (...) { // catch
        // !!!Application -> MessageBox ("Ошибка открытия книги Microsoft Excel!", "Ошибка",MB_OK+MB_ICONERROR);
        if (MessageDlg ("Ошибка открытия книги Microsoft Excel!", mtError,
            TMsgDlgButtons () << mbOK, 0));
    } // end catch
}

void __fastcall TDataModule1::toEx (int Row, int Column, AnsiString data)
{ // функция занесения данных в Excel

    try { // try
        Variant cur = Sh.OlePropertyGet ("Cells", Row, Column);
        cur.OlePropertySet ("Value", data.c_str ());

    } // end try
    catch (...) { // catch
        ;
    } // end catch
}

void __fastcall TDataModule1::toEx (int Row, int Column, Variant data)
{ // функция занесения данных в Excel

    try { // try
        Variant cur = Sh.OlePropertyGet ("Cells", Row, Column);
        cur.OlePropertySet ("Value", data);

    } // end try
    catch (...) { // catch
        ;
    } // end catch
}

void __fastcall TDataModule1::ExAutoFit (int one, int two)
{ // процедура установки автоматической ширины столбца
    for (int i = one; i <= two; i++) { // for  AutoFit
        Sh.OlePropertyGet ("Columns").OlePropertyGet ("Item", i).OleProcedure
            ("AutoFit");
    } // end for
}

void __fastcall TDataModule1::ExBorder (Variant range) { // функция обрамления

    for (int i = 1; i <= 4; i++) { // for обрамление
        range.OlePropertyGet ("Borders").OlePropertyGet ("Item", i).OlePropertySet
            ("LineStyle", 1);
    } // end for обрамление
}

void __fastcall TDataModule1::Edit_Key (char &cyfra)
{ // Как сделать, чтобы в TEdit можно было вводить только числа?
    if ( (cyfra >= '0') && (cyfra <= '9')) {
    } // цифры
    else {
        if (cyfra == 8) {
        } // Backspace (cyfra = '\b')
        else
            cyfra = 0; // не цифра
    }

}

void __fastcall TDataModule1::Ved_RatingFDQueryAfterInsert (TDataSet *DataSet) {
    vozvrat_inc_ved_rating ();
}

void __fastcall TDataModule1::Result_BallFDQueryCalcFields (TDataSet *DataSet) {
    if (result_itog)
    { // значения перечитываются только для итоговой успеваемости
        if (DataSet -> FieldValues["VID_EDU_PLAN"] == 0)
            DataSet -> FieldValues["VID_EDU_PLAN1"] = "Дневное";
        if (DataSet -> FieldValues["VID_EDU_PLAN"] == 1)
            DataSet -> FieldValues["VID_EDU_PLAN1"] = "Заочное";
        // оценки пятибальной системы
        if (DataSet -> FieldValues["RESULT"] == 1)
            DataSet -> FieldValues["RESULT1"] = "Зачет";
        if (DataSet -> FieldValues["RESULT"] == 3)
            DataSet -> FieldValues["RESULT1"] = "3 (Удовл.)";
        if (DataSet -> FieldValues["RESULT"] == 4)
            DataSet -> FieldValues["RESULT1"] = "4 (Хор.)";
        if (DataSet -> FieldValues["RESULT"] == 5)
            DataSet -> FieldValues["RESULT1"] = "5 (Отл.)";
        if (DataSet -> FieldValues["RESULT"] == 7)
            DataSet -> FieldValues["RESULT1"] = "Освобожден";
        if (DataSet -> FieldValues["RESULT"] == 9)
            DataSet -> FieldValues["RESULT1"] = "Прослушан";
        // оценки десятибальной системы

        if (!DataSet -> FieldValues["RESULT"].IsNull ()) { // if проверка на Null
            AnsiString ball_new = "";
            if (DataSet -> FieldValues["RESULT"] >= 14) {
                ball_new =
                    IntToStr (DataModule1 -> Result_BallFDQueryRESULT -> Value - 10);
                DataSet -> FieldValues["RESULT1"] = ball_new;
            }
        } // end if проверка на Null

        // STATUS_RESULT - это статус, полученной оценки
        if (DataSet -> FieldValues["STATUS_RESULT"] == 1)
            DataSet -> FieldValues["STATUS_RESULT1"] = "Основная ведомость";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 2)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "Экз. лист или дополнит. ведомость";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 3)
            DataSet -> FieldValues["STATUS_RESULT1"] = "Досрочная сдача";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 4)
            DataSet -> FieldValues["STATUS_RESULT1"] = "Ликвидация разницы";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 5)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "Перезачет с д/о на з/о или наоборот";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 6)
            DataSet -> FieldValues["STATUS_RESULT1"] = "Перезачет при 2-ом в/о";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 7)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "Перезачет при переводе-восстановл. из др. ВУЗа";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 8)
            DataSet -> FieldValues["STATUS_RESULT1"] = "Перезачет после РУОР";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 9)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "Перезачет с другого факультета";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 10)
            DataSet -> FieldValues["STATUS_RESULT1"] =
                "Перезачет после ПедКолледжа";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 11)
            DataSet -> FieldValues["STATUS_RESULT1"] = "Пересдача";
        if (DataSet -> FieldValues["STATUS_RESULT"] == 12)
            DataSet -> FieldValues["STATUS_RESULT1"] = "Перезачет после ИПК, МКП";
        // переменная для определения учебного года
        int p = DataModule1 -> Result_BallFDQueryYEAR_PLAN -> Value;
        AnsiString uch = AnsiString (p) + "-" + AnsiString (p + 1);
        DataSet -> FieldValues["YEAR_PLAN1"] = uch;
    }

}

void __fastcall TDataModule1::Spisoc_FDQueryCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "Дневное";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "Заочное";
}

void __fastcall TDataModule1::FacFullFDQCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "Дневное";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "Заочное";
}

void __fastcall TDataModule1::Prikaz_KursFDQueryCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "Дневное";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "Заочное";
}

void __fastcall TDataModule1::PeopleUpFDQueryCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "Дневное";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "Заочное";
}

void __fastcall TDataModule1::RestoreFDQueryCalcFields (TDataSet *DataSet) {
    if (result_itog) { // значения перечитываются только на StudForme
        if (DataSet -> FieldValues["VID_RESTORE"])
            DataSet -> FieldValues["VID_RESTORE1"] = "Отчислен";
        else
            DataSet -> FieldValues["VID_RESTORE1"] = "Восстановлен";
    }
}

void __fastcall TDataModule1::EncourageFDQueryCalcFields (TDataSet *DataSet) {
    if (result_itog) { // значения перечитываются только на StudForme
        if (DataSet -> FieldValues["TYPE_EN"])
            DataSet -> FieldValues["TYPE_EN1"] = "Взыскание";
        else
            DataSet -> FieldValues["TYPE_EN1"] = "Поощрение";
    }
}

void __fastcall TDataModule1::PeopleFDQueryCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "Дневное";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "Заочное";
}

void __fastcall TDataModule1::SportFDQueryCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 0)
        DataSet -> FieldValues["SUD_CATEGORY1"] = "Нет";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 1)
        DataSet -> FieldValues["SUD_CATEGORY1"] = "Судья по спорту";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 2)
        DataSet -> FieldValues["SUD_CATEGORY1"] = "Судья 1 категории";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 3)
        DataSet -> FieldValues["SUD_CATEGORY1"] = "Судья национальной категории";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 4)
        DataSet -> FieldValues["SUD_CATEGORY1"] =
            "Судья высшей национальной категории";
    if (DataSet -> FieldValues["SUD_CATEGORY"] == 5)
        DataSet -> FieldValues["SUD_CATEGORY1"] = "Судья международной категории";
}

void __fastcall TDataModule1::Ved_exlistFDQueryCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU"] == 0)
        DataSet -> FieldValues["VID_EDU1"] = "Дневное";
    if (DataSet -> FieldValues["VID_EDU"] == 1)
        DataSet -> FieldValues["VID_EDU1"] = "Заочное";
}

void __fastcall TDataModule1::Edu_PlanFDQueryCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["ZACH_EXAM"] == 0)
        DataSet -> FieldValues["ZACH_EXAM1"] = "Нет вида контроля";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 1)
        DataSet -> FieldValues["ZACH_EXAM1"] = "Зачет";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 2)
        DataSet -> FieldValues["ZACH_EXAM1"] = "Экзамен";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 3)
        DataSet -> FieldValues["ZACH_EXAM1"] = "Диф. зачет";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 4)
        DataSet -> FieldValues["ZACH_EXAM1"] = "ГЭК";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 5)
        DataSet -> FieldValues["ZACH_EXAM1"] = "Канд.экз.";
    if (DataSet -> FieldValues["ZACH_EXAM"] == 6)
        DataSet -> FieldValues["ZACH_EXAM1"] = "Канд.диф.зач.";
}

void __fastcall TDataModule1::VedomostFDQueryAfterInsert (TDataSet *DataSet) {
    vozvrat_inc_ved ();
}

void __fastcall TDataModule1::Ball_FDQueryCalcFields (TDataSet *DataSet) {
    if (!DataSet -> FieldValues["BALL"].IsNull ()) {

        if (DataSet -> FieldValues["BALL"] == 0)
            DataSet -> FieldValues["BALL1"] = "Незачет";
        if (DataSet -> FieldValues["BALL"] == 1)
            DataSet -> FieldValues["BALL1"] = "Зачет";
        if (DataSet -> FieldValues["BALL"] == 2)
            DataSet -> FieldValues["BALL1"] = "Неудовл.";
        if (DataSet -> FieldValues["BALL"] == 3)
            DataSet -> FieldValues["BALL1"] = "Удовл.";
        if (DataSet -> FieldValues["BALL"] == 4)
            DataSet -> FieldValues["BALL1"] = "Хорошо";
        if (DataSet -> FieldValues["BALL"] == 5)
            DataSet -> FieldValues["BALL1"] = "Отлично";
        if (DataSet -> FieldValues["BALL"] == 6)
            DataSet -> FieldValues["BALL1"] = "Не явился";
        if (DataSet -> FieldValues["BALL"] == 7)
            DataSet -> FieldValues["BALL1"] = "Освобожден";
        if (DataSet -> FieldValues["BALL"] == 9)
            DataSet -> FieldValues["BALL1"] = "Прослушан";

        if (DataSet -> FieldValues["BALL"] > 10)
            DataSet -> FieldValues["BALL1"] = (DataSet -> FieldValues["BALL"] - 10);

    }
}

void __fastcall TDataModule1::HolidayFDQueryCalcFields (TDataSet *DataSet) {
    if (result_itog) { // значения перечитываются только на StudForme
        int type_hol = DataModule1 -> HolidayFDQueryTYPE_HOL -> Value;
        switch (type_hol) {
        case 1:
            DataSet -> FieldValues["TYPE_HOL1"] = "Уход в а/о";
            break;
        case 2:
            DataSet -> FieldValues["TYPE_HOL1"] = "Продление а/о";
            break;
        case 3:
            DataSet -> FieldValues["TYPE_HOL1"] = "Выход из а/о";
            break;
        case 4:
            DataSet -> FieldValues["TYPE_HOL1"] = "Академический отпуск";
            break;
        case 5:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "Продление академического отпуска";
            break;
        case 6:
            DataSet -> FieldValues["TYPE_HOL1"] = "Выход из отпуска";
            break;
        case 7:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "Отпуск по беременности и родам";
            break;
        case 8:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "Отпуск по уходу за ребенком до 3-х лет";
            break;
        case 9:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "Отпуск по уходу за ребенком до 3-х лет со св. посещением";
            break;
        case 10:
            DataSet -> FieldValues["TYPE_HOL1"] = "Отпуск по беремености";
            break;
        case 11:
            DataSet -> FieldValues["TYPE_HOL1"] =
                "Отпуск для прохождения военной службы"; // Добавила Оля
            break;
        }
    }
}

void __fastcall TDataModule1::People_VedFDQueryCalcFields (TDataSet *DataSet) {
    if (!DataSet -> FieldValues["BALL"].IsNull ()) {
        DataSet -> FieldValues["BALL1"] =
            ball_string (15, DataModule1 -> People_VedFDQueryBALL -> Value, 1);
        // функция возвращает оценку типа AnsiString
    }
    else
        DataSet -> FieldValues["BALL1"] = " ";

    // переменная для определения учебного года
    int p = DataModule1 -> People_VedFDQueryYEAR_PLAN -> Value;
    AnsiString uch = AnsiString (p) + "-" + AnsiString (p + 1);
    DataSet -> FieldValues["YEAR1"] = uch;

    int k = DataModule1 -> People_VedFDQueryZACH_EXAM -> Value;
    AnsiString kk = "";
    switch (k) {
    case 0:
        kk = "нет контроля";
        break;
    case 1:
        kk = "зачет";
        break;
    case 2:
        kk = "экзамен";
        break;
    case 3:
        kk = "диф. зачет";
        break;
    case 4:
        kk = "ГОС экз.";
        break;
    }

    DataSet -> FieldValues["ZACH_EXAM1"] = kk;

}

void __fastcall TDataModule1::Ved_LikvidGridFDQueryCalcFields (TDataSet *DataSet)
{
    if (DataSet -> FieldValues["VID_EDU_PLAN"] == 0)
        DataSet -> FieldValues["VID_EDU_PLAN1"] = "Дневное";
    if (DataSet -> FieldValues["VID_EDU_PLAN"] == 1)
        DataSet -> FieldValues["VID_EDU_PLAN1"] = "Заочное";

    if (!DataSet -> FieldValues["BALL"].IsNull ()) {

        if (DataSet -> FieldValues["BALL"] == 0)
            DataSet -> FieldValues["BALL1"] = "Незачет";
        if (DataSet -> FieldValues["BALL"] == 1)
            DataSet -> FieldValues["BALL1"] = "Зачет";
        if (DataSet -> FieldValues["BALL"] == 2)
            DataSet -> FieldValues["BALL1"] = "Неудовл.";
        if (DataSet -> FieldValues["BALL"] == 3)
            DataSet -> FieldValues["BALL1"] = "Удовл.";
        if (DataSet -> FieldValues["BALL"] == 4)
            DataSet -> FieldValues["BALL1"] = "Хорошо";
        if (DataSet -> FieldValues["BALL"] == 5)
            DataSet -> FieldValues["BALL1"] = "Отлично";
        if (DataSet -> FieldValues["BALL"] == 6)
            DataSet -> FieldValues["BALL1"] = "Не явился";
        if (DataSet -> FieldValues["BALL"] == 7)
            DataSet -> FieldValues["BALL1"] = "Освобожден";
        if (DataSet -> FieldValues["BALL"] == 8)
            DataSet -> FieldValues["BALL1"] = "Не прослушан";
        if (DataSet -> FieldValues["BALL"] == 9)
            DataSet -> FieldValues["BALL1"] = "Прослушан";

        if (DataSet -> FieldValues["BALL"] > 10)
            DataSet -> FieldValues["BALL1"] = (DataSet -> FieldValues["BALL"] - 10);

    }

}

void __fastcall TDataModule1::Rating_BallFDQueryBeforePost (TDataSet *DataSet) {
    if (DataModule1 -> Rating_BallFDQueryBALL_R -> Value <
        0 || DataModule1 -> Rating_BallFDQueryBALL_R -> Value > 100) {
        ShowMessage ("Данные должны быть в диапазоне от 0 до 100!");
        DataModule1 -> Rating_BallFDQueryBALL_R -> Value = 0;
    }
}

void __fastcall TDataModule1::Ved_RaznicaFDQueryAfterInsert (TDataSet *DataSet) {
    vozvrat_inc_ved_raznica ();
}

void __fastcall TDataModule1::LikvidFDQueryCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["VID_EDU_DO"] == 0)
        DataSet -> FieldValues["VID_EDU_DO1"] = "Дневное";
    if (DataSet -> FieldValues["VID_EDU_DO"] == 1)
        DataSet -> FieldValues["VID_EDU_DO1"] = "Заочное";

    if (DataSet -> FieldValues["VID_EDU_PO"] == 0)
        DataSet -> FieldValues["VID_EDU_PO1"] = "Дневное";
    if (DataSet -> FieldValues["VID_EDU_PO"] == 1)
        DataSet -> FieldValues["VID_EDU_PO1"] = "Заочное";
}

void __fastcall TDataModule1::PeopleFDQueryAfterInsert (TDataSet *DataSet) {
    vozvrat_inc_people ();
}

void __fastcall TDataModule1::PeopleFDQueryNewRecord (TDataSet *DataSet) {
    StudForm -> DBEdit1 -> SetFocus ();
}

void __fastcall TDataModule1::VedomostFDQueryCalcFields (TDataSet *DataSet) {
    if (DataSet -> FieldValues["STATUS"] == 0)
        DataSet -> FieldValues["STATUS1"] = "Основная";
    if (DataSet -> FieldValues["STATUS"] == 1)
        DataSet -> FieldValues["STATUS1"] = "Экзаменац. лист";
    if (DataSet -> FieldValues["STATUS"] == 2)
        DataSet -> FieldValues["STATUS1"] = "Дополнительная";
    if (DataSet -> FieldValues["STATUS"] == 3)
        DataSet -> FieldValues["STATUS1"] = "Досрочная";

    if (DataSet -> FieldValues["VID_EDU_PLAN"] == 0)
        DataSet -> FieldValues["VID_EDU_PLAN1"] = "Дневное";
    if (DataSet -> FieldValues["VID_EDU_PLAN"] == 1)
        DataSet -> FieldValues["VID_EDU_PLAN1"] = "Заочное";
}

void __fastcall TDataModule1::People_SpravkiSourceDataChange (TObject *Sender,
    TField *Field)

{
    SpavkiForm -> Memo24 -> Text = "Зачислен приказом от " +
        DateToStr (SQLTimeStampToDateTime
        (DataModule1 -> People_SpravkiFDQueryD_PRIKAZ_INCLUDE -> Value)) + " №" +
        IntToStr (DataModule1 -> People_SpravkiFDQueryN_PRIKAZ_INCLUDE -> Value)
        + " ст.";
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
{ // Процедура для установки диапазона ячеек и передачи в него техта, размера шрифта, типа выравнивания в ячейке
    // int col1, int col2  - номер первого и второго столбца для выделения диапазона
    // int st - номер сторки  , int st2 - номер следующей строки для объединения ячеек вниз
    // bool Border - обрамление ячейки true - обрамлять
    // AnsiString Shrift, int kegl - название шрифта и его размер
    // int AlignH, int AlignV - горизонтальное и вертикальное выравнивание текста в ячейке (0 - не надо выравнивать)
    // AlignH  2-по левому краю, 3-по центру, 4-по правому, 6-по ширине
    // AlignV  1-по верхнему, 2-по центру, 3-по нижнему, 4-по высоте

    // int Orient -- оринтация текста в ячейке (0 - не надо выравнивать)
    // bool M1, bool W1  - объединение ячеек, установка переноса по словам (false - не надо выполнять этих действий)
    // AnsiString TextCell  - текст в ячейке

    // установка первой и последней ячейки для диапазона
    AnsiString diap = mas_column[col1 - 1] + st + ":" +
        mas_column[col2 - 1] + st2;

    // диапазон
    // !!!Variant Rang1=App.OlePropertyGet ("Range",diap.c_str ());

    Variant Rang1 = Range2 (WSheet, diap);
    // установка шрифта
    CellFont (Shrift.c_str (), kegl, Bold, false, 1, 0, Rang1);
    /* !!!Rang1.OlePropertyGet ("Font").OlePropertySet ("Name",Shrift.c_str ());
     Rang1.OlePropertyGet ("Font").OlePropertySet ("Size",kegl);

     if (Bold)  Rang1.OlePropertyGet ("Font").OlePropertySet ("Bold",True); */

    // установка в ячейку значения

    /* Variant cur=Sh.OlePropertyGet ("Cells",st,col1);
     cur.OlePropertySet ("Value",TextCell.c_str ()); */
    CellValue (TextCell, col1, st);

    // Объединение ячеек  - если false, то не объединяем
    if (M_1) // !!!Rang1.OleProcedure ("Merge");
            M1 (Rang1);
    // перенос по словам в ячейке  - если false, то не объединяем
    if (W_1) // !!!cur.OlePropertySet ("WrapText",true);
            W1 (Rang1);
    // обрамление ячейки
    if (Border) { // if true - то обрамляем ячейки
        for (int i = 1; i <= 4; i++) {
            // !!!Rang1.OlePropertyGet ("Borders").OlePropertyGet ("Item",i).OlePropertySet ("LineStyle",1);
            BorderCell (col1, st, 1, 2);
        }
    } // end if true - то обрамляем ячейки
    // горизонтальное выравнивание   - при  0 выравнивать не надо
    if (AlignH)
        Rang1.OlePropertySet ("HorizontalAlignment", AlignH);
    // HorizontalAlign (Rang1, AlignH);

    // вертикальное выравнивание     - при  0 выравнивать не надо
    if (AlignV)
        Rang1.OlePropertySet ("VerticalAlignment", AlignV);
    // VerticalAlign (Rang1, AlignV);

    // ориентация текста в ячейке    - при  0  не надо
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

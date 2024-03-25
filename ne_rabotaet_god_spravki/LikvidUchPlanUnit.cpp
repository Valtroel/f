#include <vcl.h>
#pragma hdrstop


#include <ComObj.hpp>
#include "DataModule.h"
#include "DM3Unit.h"
#include "Func.h"
#include "LikvidUchPlanUnit.h"
#include <utilcls.h>


#pragma package (smart_init)
#pragma resource "*.dfm"


TLikvidUchPlanForm * LikvidUchPlanForm;


Variant ExApp;
Variant vApp, vDocs, vDoc, vPars, vPar, vv;
bool fStart2;
AnsiString sql_11 = "SELECT DISTINCT (Edu_plan.N_OBJECT), Edu_plan.N_PLAN, \
               Edu_plan.SEMESTR, Edu_plan.CLOCK_PLAN, Edu_plan.CLOCK_PLAN_ALL, \
               Edu_plan.YEAR_PLAN, Edu_plan.N_FAC, \
               Edu_plan.ZACH_EXAM, Edu_plan.VID_EDU_PLAN,   EDU_PLAN.SPECKURS, \
               Object_plan.NAME_OBJECT, object_plan.all_clock_plan  \
               FROM EDU_PLAN Edu_plan  \
               INNER JOIN OBJECT_PLAN Object_plan  \
               ON  (Edu_plan.N_OBJECT = Object_plan.N_OBJECT) \
               WHERE Edu_plan.N_FAC=:N_FAC AND Edu_plan.VID_EDU_PLAN=:VID_EDU ";

AnsiString sql_11_toExcel = "SELECT Edu_plan.SEMESTR, Object_plan.NAME_OBJECT, \
               Edu_plan.VID_EDU_PLAN, Edu_plan.CLOCK_PLAN, Edu_plan.CLOCK_PLAN_ALL, \
               Edu_plan.YEAR_PLAN, Edu_plan.ZACH_EXAM  \
               FROM EDU_PLAN Edu_plan  \
               INNER JOIN OBJECT_PLAN Object_plan  \
               ON  (Edu_plan.N_OBJECT = Object_plan.N_OBJECT) \
               WHERE Edu_plan.N_FAC=:N_FAC AND Edu_plan.VID_EDU_PLAN=:VID_EDU ";

AnsiString sql_33 = "                                                           \
    AND                                                                         \
        (                                                                       \
            N_PLAN NOT IN                                                       \
            (                                                                   \
                SELECT                                                          \
                    Edu_plan.N_PLAN                                             \
                FROM                                                            \
                    SPEC_PLAN                                                   \
                        INNER JOIN                                              \
                            EDU_PLAN                                            \
                                ON                                              \
                                    (SPEC_PLAN.N_PLAN = EDU_PLAN.N_PLAN)        \
            )                                                                   \
         OR                                                                     \
            NOT                                                                 \
            (                                                                   \
                N_PLAN NOT IN                                                   \
                (                                                               \
                    SELECT                                                      \
                        Edu_plan.N_PLAN                                         \
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
        )                                                                       \
    ORDER BY                                                                    \
        edu_plan.semestr,                                                       \
        edu_plan.zach_exam DESC,                                                \
        Object_plan.NAME_OBJECT                                                 \
    ";




// BitBtn1Click
// BitBtn2Click
// BitBtn3Click
// BitBtn4Click
// DBGrid1DblClick
// DBLookupComboBox1Click
// FormClose
// FormCreate
// FormMin
// RadioGroup1Click
// RadioGroup2Click
// SpeedButton1Click
// SpeedButton2Click
// SpeedButton3Click
// sql_sem





__fastcall TLikvidUchPlanForm::TLikvidUchPlanForm (TComponent* Owner)
    : TForm (Owner) {
}

void __fastcall TLikvidUchPlanForm::FormClose (TObject *Sender,
    TCloseAction &Action) {
    DataModule1 -> SpecializFDQuery -> Close ();
    DM3 -> Svod_NadoFDQuery -> Close ();

    // Закрытие формы, как буд-то она развертывается в середину
    TRect r1, r2;
    r1 = Rect (Left + Width / 2, Top + Height / 2, Left + Width / 2,
        Top + Height / 2);
    r2 = BoundsRect;
    DrawAnimatedRects (Handle, IDANI_CAPTION, &r2, &r1);
    // меняется только последовательность последних параметров
    Action = caFree;
}

void __fastcall TLikvidUchPlanForm::FormMin (int st) { // уменьшение формы
    // int st-статус чего прятать, а чего нет
    // 0-прятать всё, 1-прятать часть
    if (!st) { // if надо всё спрятать
        RadioGroup2 -> Visible = false;
        Label1 -> Visible = false;
        DBLookupComboBox1 -> Visible = false;
        BitBtn1 -> Visible = false;
    } // end if надо всё спрятать

    Panel2 -> Visible = false;
    Panel3 -> Visible = false;
    Panel4 -> Visible = false;
    LikvidUchPlanForm -> Height = 117;
    if (LikvidUchPlanForm -> Position != poMainFormCenter)
        LikvidUchPlanForm -> Position = poMainFormCenter;
}

AnsiString TLikvidUchPlanForm::sql_sem (int k, int god)
{ // функция возвращает часть SQL в зависимости от выбранного курса
    AnsiString sem1 = AnsiString (k * 2 + 1);
    AnsiString sem2 = AnsiString (k * 2 + 2);
    AnsiString god_plan = AnsiString (god + k);
    return " (Edu_plan.semestr in (" + sem1 + "," + sem2 +
        ") and  Edu_plan.year_plan=" + god_plan + ")";
}

void __fastcall TLikvidUchPlanForm::BitBtn1Click (TObject *Sender) {
    if (DBLookupComboBox1 -> KeyValue == -1 || DBLookupComboBox1 -> KeyValue.IsNull
        () || RadioGroup2 -> ItemIndex == -1) {
        ShowMessage ("Укажите все критерии выбора!");
        return;
    }

    int k = RadioGroup2 -> ItemIndex; // курс
    int god_one = uch_god - k;

    AnsiString sss = " and (";

    switch (k) { // switch курс-1
    case 5:
        sss += sql_sem (k, god_one) + " or ";
        k--;
    case 4:
        sss += sql_sem (k, god_one) + " or ";
        k--;
    case 3:
        sss += sql_sem (k, god_one) + " or ";
        k--;
    case 2:
        sss += sql_sem (k, god_one) + " or ";
        k--;
    case 1:
        sss += sql_sem (k, god_one) + " or ";
        k--;
    case 0:
        sss += sql_sem (k, god_one) + ") ";
    } // end switch курс-1

    DM3 -> Svod_NadoFDQuery -> Close ();
    DM3 -> Svod_NadoFDQuery -> SQL -> Clear ();
    DM3 -> Svod_NadoFDQuery -> SQL -> Add (sql_11 + sss + sql_33);
    DM3 -> Svod_NadoFDQuery -> ParamByName ("N_FAC") -> AsSmallInt = nom_fac;
    DM3 -> Svod_NadoFDQuery -> ParamByName ("VID_EDU") -> AsSmallInt =
        RadioGroup1 -> ItemIndex;
    DM3 -> Svod_NadoFDQuery -> ParamByName ("SPECIALIZ") -> AsInteger =
        DBLookupComboBox1 -> KeyValue;
    DM3 -> Svod_NadoFDQuery -> Open ();

    DM3 -> Svod_Nado_toExcelFDQuery -> Close ();
    DM3 -> Svod_Nado_toExcelFDQuery -> SQL -> Clear ();
    DM3 -> Svod_Nado_toExcelFDQuery -> SQL -> Add (sql_11_toExcel + sss + sql_33);
    DM3 -> Svod_Nado_toExcelFDQuery -> ParamByName ("N_FAC") -> AsSmallInt = nom_fac;
    DM3 -> Svod_Nado_toExcelFDQuery -> ParamByName ("VID_EDU") -> AsSmallInt =
        RadioGroup1 -> ItemIndex;
    DM3 -> Svod_Nado_toExcelFDQuery -> ParamByName ("SPECIALIZ") -> AsInteger =
        DBLookupComboBox1 -> KeyValue;
    DM3 -> Svod_Nado_toExcelFDQuery -> Open ();

    Memo1 -> Clear ();
    Memo1 -> Lines -> Add ("Для восстановления на " +
        AnsiString (RadioGroup2 -> ItemIndex + 1) +
        " курс необходимо сдать следующие дисциплины:");

    // ------
    Panel2 -> Visible = true;
    Panel3 -> Visible = true;
    Panel4 -> Visible = true;
    LikvidUchPlanForm -> Height = 406;
    if (LikvidUchPlanForm -> Position != poMainFormCenter)
        LikvidUchPlanForm -> Position = poMainFormCenter;
}

void __fastcall TLikvidUchPlanForm::FormCreate (TObject *Sender) {
    // Появление формы, как буд-то она развертывается из середины
    TRect r1, r2;
    r1 = Rect (Left + Width / 2, Top + Height / 2, Left + Width / 2,
        Top + Height / 2);
    r2 = BoundsRect;
    DrawAnimatedRects (Handle, IDANI_CAPTION, &r1, &r2);

    DataModule1 -> SpecializFDQuery -> Close ();
    DataModule1 -> SpecializFDQuery -> ParamByName ("FAC") -> AsInteger = nom_fac;
    DataModule1 -> SpecializFDQuery -> Open ();
}

/* void __fastcall TLikvidUchPlanForm::DBGrid1DrawColumnCell (TObject *Sender,
 const TRect &Rect, int DataCol, TColumn *Column,
 TGridDrawState State)
 {
 //Разные цвета, шрифты, размер
 //DBGrid1 -> Canvas -> Brush -> Color=clWhite; DBGrid1 -> Canvas -> Font -> Color=clRed; DBGrid1 -> Canvas -> Font -> Color=clBlack;
 //DBGrid1 -> Canvas -> Font -> Size=-14;
 //DBGrid1 -> Canvas -> Font -> Name="Wingdings";
 //DBGrid1 -> Canvas -> FillRect (Rect);


 if (Column -> FieldName=="ZACH_EXAM")
 {//if  "ZACH_EXAM"
 try
 {
 AnsiString zach="";
 int z=DM3 -> Svod_Nado -> FieldByName ("ZACH_EXAM") -> Value;
 switch (z)
 {
 case 0:  zach="нет контроля"; break;
 case 1:  zach="зачет"; break;
 case 2:  zach="экзамен"; break;
 case 3:  zach="диф.зачет"; break;
 case 4:  zach="ГОС экзамен"; break;
 }
 DBGrid1 -> Canvas -> FillRect (Rect);
 DBGrid1 -> Canvas -> TextOut (Rect.Right-2-DBGrid1 -> Canvas -> TextWidth (zach),Rect.Top+1,zach);
 }
 catch (...)
 {
 return;
 }
 }//end if  "ZACH_EXAM"

 if (Column -> FieldName=="YEAR_PLAN")
 {//if  "YEAR_PLAN"
 AnsiString god=AnsiString (DM3 -> Svod_Nado -> FieldByName ("YEAR_PLAN") -> Value)+"/"+AnsiString (DM3 -> Svod_Nado -> FieldByName ("YEAR_PLAN") -> Value+1);
 DBGrid1 -> Canvas -> FillRect (Rect);
 DBGrid1 -> Canvas -> TextOut (Rect.Right-2-DBGrid1 -> Canvas -> TextWidth (god),Rect.Top+1,god);
 }//end if  "YEAR_PLAN"
 } */
void __fastcall TLikvidUchPlanForm::BitBtn2Click (TObject *Sender) {
    // передача данных из DBGrid1 в Excel
    DBgrid_toEx (DBGrid1);
}

void __fastcall TLikvidUchPlanForm::BitBtn3Click (TObject *Sender) {
    // --- Проверка запущен ли Word, если нет - то создаем
    // try       { vApp=GetActiveOleObject ("Word.Application");}
    // catch (...){ vApp=CreateOleObject ("Word.Application");   }

    if (!fStart2) {
        try {
            vApp = CreateOleObject ("Word.Application");
            fStart2 = true;
        }
        catch (...) {
            MessageBox (0, "Ошибка при открытии сервера Word", "Ошибка", MB_OK);
            return;
        }
    }

    // --- Определяем объект - Документ
    vDocs = vApp.OlePropertyGet ("Documents");
    // --- Проверяем, создан ли такой  документ и его открываем, нет - создаем новый
    vDocs.OleProcedure ("Add");
    // --- Делаем его активным и видимым
    vDoc = vDocs.OleFunction ("Item", 1);
    vDoc.OleProcedure ("Activate");
    // vApp.OlePropertySet ("Visible",true);
    // --- Обращаемся к объекту Параграф
    vPars = vDoc.OlePropertyGet ("Paragraphs");
    // добавляем параграф
    vPars.OleProcedure ("Add");
    // устанавливаем текущий параграф
    vPar = vPars.OleFunction ("Item", 2); // 1
    vPar.OlePropertySet ("LineSpacingRule", 2);
    // wdLineSpaceDouble  межстрочный интервал -- двойной
    // шрифт и размер
    vv = vPar.OlePropertyGet ("Range").OlePropertyGet ("Font");
    vv.OlePropertySet ("Size", 11);
    vPar.OlePropertyGet ("Range").OlePropertySet ("Text",
        Memo1 -> Lines -> Text.c_str ());
    vApp.OlePropertySet ("Visible", true);

}

void __fastcall TLikvidUchPlanForm::SpeedButton1Click (TObject *Sender) {
    Memo1 -> Lines -> Add (AnsiString (DM3 -> Svod_NadoFDQuerySEMESTR -> Value) +
        " семестр " + DM3 -> Svod_NadoFDQueryYEAR1 -> Value + " " +
        DM3 -> Svod_NadoFDQueryNAME_OBJECT -> Value + " - " +
        DM3 -> Svod_NadoFDQueryZACH_EXAM1 -> Value + " (" +
        AnsiString (DM3 -> Svod_NadoFDQueryCLOCK_PLAN -> Value) + " ч.)");
}

void __fastcall TLikvidUchPlanForm::SpeedButton2Click (TObject *Sender) {
    DM3 -> Svod_NadoFDQuery -> First ();
    for (int i = 0; i < DM3 -> Svod_NadoFDQuery -> RecordCount; i++) {
        SpeedButton1Click (this);
        DM3 -> Svod_NadoFDQuery -> Next ();
    }
}

void __fastcall TLikvidUchPlanForm::DBGrid1DblClick (TObject *Sender) {
    SpeedButton1Click (this);
}

void __fastcall TLikvidUchPlanForm::RadioGroup1Click (TObject *Sender) {
    FormMin (0); // уменьшение формы

    RadioGroup2 -> Items -> Clear (); // oчищение курсов
    // ---
    if (RadioGroup1 -> ItemIndex) { // if    выбрана заочная форма
        RadioGroup2 -> Items -> Add ("1");
        RadioGroup2 -> Items -> Add ("2");
        RadioGroup2 -> Items -> Add ("3");
        RadioGroup2 -> Items -> Add ("4");
        RadioGroup2 -> Items -> Add ("5");
        RadioGroup2 -> Items -> Add ("6");
    } // end if  выбрана заочная форма
    else { // else  выбрана дневная форма
        RadioGroup2 -> Items -> Add ("1");
        RadioGroup2 -> Items -> Add ("2");
        RadioGroup2 -> Items -> Add ("3");
        RadioGroup2 -> Items -> Add ("4");
        RadioGroup2 -> Items -> Add ("5");
    } // end else выбрана дневная форма
    RadioGroup2 -> ItemIndex = -1;
    RadioGroup2 -> Visible = true; // становится видимым курсы
}

void __fastcall TLikvidUchPlanForm::RadioGroup2Click (TObject *Sender) {
    FormMin (1); // уменьшение формы
    Label1 -> Visible = true;
    DBLookupComboBox1 -> Visible = true;
    BitBtn1 -> Visible = true;
}

void __fastcall TLikvidUchPlanForm::DBLookupComboBox1Click (TObject *Sender) {
    FormMin (1); // уменьшение формы
}

void __fastcall TLikvidUchPlanForm::SpeedButton3Click (TObject *Sender)
{ // удаление строки из Memo
    // находим положение курсора в мемо
    TPoint Point;
    GetCaretPos (&Point);
    DWORD both;

    both = Memo1 -> Perform (EM_CHARFROMPOS, 0, MAKELPARAM (Point.x, Point.y));
    int indexLine = HIWORD (both); // позиция курсора -номер строки
    // int indexLength = LOWORD (both) - Memo1 -> Perform (EM_LINEINDEX, -1, 0);   //позиция курсора в строке

    // удаляем найденную строку
    Memo1 -> Lines -> Delete (indexLine);
}

void __fastcall TLikvidUchPlanForm::BitBtn4Click (TObject *Sender) {
    /* Variant App, Bks, Bk, Shts, Sht, Cll;
     App = CreateOleObject ("Excel.Application");

     Bks = App.OlePropertyGet ("WorkBooks");
     App.OlePropertySet ("SheetsInNewWorkbook", 1);
     Bks.OleProcedure ("Add");
     Bk = Bks.OlePropertyGet ("Item", 1);
     Shts = Bk.OlePropertyGet ("WorkSheets");
     Sht = Shts.OlePropertyGet ("Item", 1);
     Sht.OlePropertySet ("Name", WideString ("Листок"));

     for (int i = 1; i <= DM3 -> Svod_NadoFDQuery -> RecordCount; i++) { // for1
     for (int j = 1; j <= DBGrid1 -> Columns -> Count; j++) { // for2
     Cll = Sht.OlePropertyGet ("Cells").OlePropertyGet ("Item", i, j);
     Cll.OlePropertySet ("Value",
     DBGrid1 -> Columns -> Items[j] -> Field -> Value);
     }

     }
     App.OlePropertySet ("Visible", True); */

    // Bks.OleProcedure ("Add");

    ExApp = Variant::CreateObject ("Excel.Application");
    Variant WBook = NewBook (ExApp);
    Variant WSheet = SelectSheet (WBook, "Лист1");

    for (int i = 0; i < DM3 -> Svod_NadoFDQuery -> RecordCount; i++) { // for1

        for (int j = 0; j < DBGrid1 -> Columns -> Count; j++) { // for2
            if (!i) {
                // if для шапочки (название колонок берется напрямую из Grid-a)
                CellValue (DBGrid1 -> Columns -> Items[j] -> Title -> Caption, j+1, i+1);
            }
            else {
                CellValue (DBGrid1 -> Columns -> Items[j] -> Field -> Value, j+1, i+1);
            }
        }
        DM3 -> Svod_NadoFDQuery -> Next ();
    }

    OVisible (ExApp);
}

#include <vcl.h>
#pragma hdrstop


#include "Add_Edu_planUnit.h"
#include "DataModule.h"
#include "Edu_planUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TEdu_planForm * Edu_planForm;




// ApplicationEvents1Message
// BitBtn1Click
// CheckBox1Click
// DBGrid1DblClick
// FormActivate
// FormClose
// LabeledEdit1Change
// RadioGroup1Click
// RadioGroup2Click



__fastcall TEdu_planForm::TEdu_planForm (TComponent* Owner) : TForm (Owner) {
}


void __fastcall TEdu_planForm::RadioGroup1Click (TObject *Sender) {

    AnsiString s[6] = {
        " AND (SEMESTR=1 OR SEMESTR=2) ", " AND (SEMESTR=3 OR SEMESTR=4) ",
        " AND (SEMESTR=5 OR SEMESTR=6) ", " AND (SEMESTR=7 OR SEMESTR=8) ",
        " AND (SEMESTR=9 OR SEMESTR=10) ", " AND (SEMESTR=11 OR SEMESTR=12) "};
    DataModule1 -> Edu_PlanFDQuery -> Close ();
    DataModule1 -> Edu_PlanFDQuery -> SQL -> Clear ();
    DataModule1 -> Edu_PlanFDQuery -> SQL -> Add
        ("SELECT Edu_plan.*, object_PLAN.name_object||' '||Edu_plan.clock_plan_all||'ч' as name_plan, object_PLAN.name_object FROM EDU_PLAN, object_plan WHERE (YEAR_PLAN=:PLAN) and Edu_plan.n_object = object_plan.n_object AND (N_FAC=:N_FAC) AND (VID_EDU_PLAN=" +
        AnsiString (RadioGroup2 -> ItemIndex) + ")" + s[RadioGroup1 -> ItemIndex] +
        "ORDER BY SEMESTR");
    DataModule1 -> Edu_PlanFDQuery -> ParamByName ("N_FAC") -> AsInteger = nom_fac;
    DataModule1 -> Edu_PlanFDQuery -> ParamByName ("PLAN") -> Value = uch_god;
    DataModule1 -> Edu_PlanFDQuery -> Open ();
    CheckBox1 -> State = cbUnchecked;
    CheckBox1 -> Enabled = true;

}


void __fastcall TEdu_planForm::BitBtn1Click (TObject *Sender) {
    Add_Edu_planForm = new TAdd_Edu_planForm (this);
    Add_Edu_planForm -> Caption = "Добавление предмета в учебный план";
    // DataModule1 -> Edu_PlanQuery -> Insert ();
    Add_Edu_planForm -> ComboBox1 -> Text = "";
    Add_Edu_planForm -> ComboBox2 -> Text = "";
    Add_Edu_planForm -> DBLookupComboBox1 -> KeyValue = -1;
    Add_Edu_planForm -> Edit1 -> Text = "";
    Add_Edu_planForm -> Edit2 -> Text = "";
    Add_Edu_planForm -> Edit3 -> Text = "";
    Add_Edu_planForm -> CheckBox2 -> Checked = false;
    Add_Edu_planForm -> DBGrid1 -> Visible = false;
    Add_Edu_planForm -> ClientHeight = 410;
    Add_Edu_planForm -> FDTable1 -> Active = True;
    Add_Edu_planForm -> FDTable2 -> Active = True;
    Add_Edu_planForm -> FDQuery4 -> Active = True;
    Add_Edu_planForm -> FDQuery5 -> Active = True;
    Add_Edu_planForm -> CheckBox2 -> Enabled = True;
    Add_Edu_planForm -> ShowModal ();
}


void __fastcall TEdu_planForm::DBGrid1DblClick (TObject *Sender) {
    if (!DataModule1 -> Edu_PlanFDQuery -> RecordCount) { // if нет ни одной записи

        ShowMessage (
            "У вас еще нет записей в учебном плане для просмотра по заданному критерию!");
        return;
    } // end if нет ни одной записи

    Add_Edu_planForm = new TAdd_Edu_planForm (this);
    Add_Edu_planForm -> ClientHeight = 410;
    Add_Edu_planForm -> Caption = "Изменения в учебном плане";
    // занесение значений из базы данных в поля
    Add_Edu_planForm -> DBLookupComboBox1 -> KeyValue =
        DataModule1 -> Edu_PlanFDQueryN_OBJECT -> Value;
    Add_Edu_planForm -> Edit1 -> Text =
        AnsiString (DataModule1 -> Edu_PlanFDQuerySEMESTR -> Value);
    Add_Edu_planForm -> Edit2 -> Text =
        AnsiString (DataModule1 -> Edu_PlanFDQueryCLOCK_PLAN -> Value);
    Add_Edu_planForm -> Edit3 -> Text =
        AnsiString (DataModule1 -> Edu_PlanFDQueryCLOCK_PLAN_ALL -> Value);
    Add_Edu_planForm -> ComboBox1 -> ItemIndex =
        DataModule1 -> Edu_PlanFDQueryZACH_EXAM -> Value;
    Add_Edu_planForm -> MaskEdit1 -> EditText =
        AnsiString (DataModule1 -> Edu_PlanFDQueryYEAR_PLAN -> Value);
    Add_Edu_planForm -> MaskEdit2 -> EditText =
        AnsiString (DataModule1 -> Edu_PlanFDQueryYEAR_PLAN -> Value + 1);
    Add_Edu_planForm -> ComboBox2 -> ItemIndex =
        DataModule1 -> Edu_PlanFDQueryVID_EDU_PLAN -> Value;
    // спецкурс
    // if (DataModule1 -> Edu_PlanQuerySPECKURS -> Value) Add_Edu_planForm -> CheckBox1 -> State = cbChecked;
    // else  Add_Edu_planForm -> CheckBox1 -> State = cbUnchecked;
    Add_Edu_planForm -> RadioGroup2 -> ItemIndex =
        DataModule1 -> Edu_PlanFDQuerySPECKURS -> Value;
    if (DataModule1 -> Edu_PlanFDQueryTYPE_PLAN -> Value == 1) {
        Add_Edu_planForm -> CheckBox1 -> Checked = true;
    }
    else {
        Add_Edu_planForm -> CheckBox1 -> Checked = false;
    }
    Add_Edu_planForm -> CheckBox1 -> Enabled = false;
    Add_Edu_planForm -> FDTable1 -> Active = True;
    Add_Edu_planForm -> FDTable2 -> Active = True;
    Add_Edu_planForm -> FDQuery2 -> Active = False;
    Add_Edu_planForm -> FDQuery3 -> Active = False;
    Add_Edu_planForm -> FDQuery2 -> ParamByName ("PLAN") -> Value =
        DataModule1 -> Edu_PlanFDQueryN_PLAN -> Value;
    Add_Edu_planForm -> FDQuery3 -> ParamByName ("PLAN") -> Value =
        DataModule1 -> Edu_PlanFDQueryN_PLAN -> Value;
    Add_Edu_planForm -> FDQuery2 -> Active = True;
    Add_Edu_planForm -> FDQuery3 -> Active = True;
    Add_Edu_planForm -> DBLookupComboBox3 -> KeyValue =
        Add_Edu_planForm -> FDQuery2N_OBJECT -> Value;
    Add_Edu_planForm -> Edit4 -> Text =
        FloatToStr (Add_Edu_planForm -> FDQuery2PERC_SUB_PLAN -> Value);
    Add_Edu_planForm -> Edit6 -> Text =
        IntToStr (Add_Edu_planForm -> FDQuery2CLASSROOM_HOURS -> Value);
    Add_Edu_planForm -> Edit8 -> Text =
        IntToStr (Add_Edu_planForm -> FDQuery2LECTURE_HOURS -> Value);
    Add_Edu_planForm -> Edit10 -> Text =
        IntToStr (Add_Edu_planForm -> FDQuery2SEMINAR_HOURS -> Value);
    Add_Edu_planForm -> Edit12 -> Text =
        IntToStr (Add_Edu_planForm -> FDQuery2CLOCK_PLAN -> Value);
    Add_Edu_planForm -> DBLookupComboBox4 -> KeyValue =
        Add_Edu_planForm -> FDQuery3N_OBJECT -> Value;
    Add_Edu_planForm -> Edit5 -> Text =
        FloatToStr (Add_Edu_planForm -> FDQuery3PERC_SUB_PLAN -> Value);
    Add_Edu_planForm -> Edit7 -> Text =
        IntToStr (Add_Edu_planForm -> FDQuery3CLASSROOM_HOURS -> Value);
    Add_Edu_planForm -> Edit9 -> Text =
        IntToStr (Add_Edu_planForm -> FDQuery3LECTURE_HOURS -> Value);
    Add_Edu_planForm -> Edit11 -> Text =
        IntToStr (Add_Edu_planForm -> FDQuery3SEMINAR_HOURS -> Value);
    Add_Edu_planForm -> Edit13 -> Text =
        IntToStr (Add_Edu_planForm -> FDQuery3CLOCK_PLAN -> Value);

    // значения в случае последнего вида контроля
    if (DataModule1 -> Edu_PlanFDQuerySTATUS_CONTROL -> Value)
        Add_Edu_planForm -> CheckBox2 -> State = cbChecked;
    else
        Add_Edu_planForm -> CheckBox2 -> State = cbUnchecked;

    // DataModule1 -> Edu_PlanQuery -> Edit ();
    // ---------  Учебный план для определенных специализаций
    DataModule1 -> Spec_PlanFDQuery -> Close ();
    DataModule1 -> Spec_PlanFDQuery -> ParamByName ("PLAN") -> Value =
        DataModule1 -> Edu_PlanFDQueryN_PLAN -> Value;
    DataModule1 -> Spec_PlanFDQuery -> Open ();

    if (DataModule1 -> Spec_PlanFDQuery -> RecordCount)
    { // если нашли хотя бы одну запись по специализациям - показываем Grid
        Add_Edu_planForm -> DBGrid1 -> Visible = true;
        Add_Edu_planForm -> RadioGroup1 -> ItemIndex = -1;
    }
    else { // не нашли ни одной записи - Grid не виден
        Add_Edu_planForm -> DBGrid1 -> Visible = false;
    }
    // -----------
    Add_Edu_planForm -> ShowModal ();
}


void __fastcall TEdu_planForm::FormActivate (TObject *Sender) {
    LabeledEdit1 -> Text = IntToStr (uch_god);
    DataModule1 -> Edu_PlanFDQuery -> Close ();
    DataModule1 -> Edu_PlanFDQuery -> SQL -> Clear ();
    // ---------
    String s111 =
        "SELECT Edu_plan.*, object_PLAN.name_object||' '||Edu_plan.clock_plan_all||'ч' as name_plan, object_PLAN.name_object FROM EDU_PLAN, object_plan WHERE (YEAR_PLAN=:PLAN) and Edu_plan.n_object = object_plan.n_object AND (EDU_PLAN.N_FAC=:N_FAC) AND (EDU_PLAN.VID_EDU_PLAN=" +
        AnsiString (RadioGroup2 -> ItemIndex) + ") ORDER BY EDU_PLAN.SEMESTR";
    DataModule1 -> Edu_PlanFDQuery -> SQL -> Add (s111);
    DataModule1 -> Edu_PlanFDQuery -> ParamByName ("N_FAC") -> AsInteger = nom_fac;
    DataModule1 -> Edu_PlanFDQuery -> ParamByName ("PLAN") -> Value = uch_god;
    DataModule1 -> Edu_PlanFDQuery -> Open ();
}


void __fastcall TEdu_planForm::CheckBox1Click (TObject *Sender) {

    if (CheckBox1 -> Checked) {
        RadioGroup1 -> ItemIndex = -1;
        DataModule1 -> Edu_PlanFDQuery -> Close ();
        DataModule1 -> Edu_PlanFDQuery -> SQL -> Clear ();
        DataModule1 -> Edu_PlanFDQuery -> SQL -> Add
            ("SELECT Edu_plan.*, object_PLAN.name_object||' '||Edu_plan.clock_plan_all||'ч' as name_plan, object_PLAN.name_object FROM EDU_PLAN, object_plan WHERE (YEAR_PLAN=:PLAN) and Edu_plan.n_object = object_plan.n_object AND (N_FAC=:N_FAC) AND (VID_EDU_PLAN=" +
            AnsiString (RadioGroup2 -> ItemIndex) + ") ORDER BY SEMESTR");
        DataModule1 -> Edu_PlanFDQuery -> ParamByName ("N_FAC") -> AsInteger = nom_fac;
        DataModule1 -> Edu_PlanFDQuery -> ParamByName ("PLAN") -> Value = uch_god;
        DataModule1 -> Edu_PlanFDQuery -> Open ();
        CheckBox1 -> Enabled = false;
    }
}


void __fastcall TEdu_planForm::RadioGroup2Click (TObject *Sender) {

    RadioGroup1 -> ItemIndex = -1;
    // CheckBox1 -> Checked=true;
    DataModule1 -> Edu_PlanFDQuery -> Close ();
    DataModule1 -> Edu_PlanFDQuery -> SQL -> Clear ();
    DataModule1 -> Edu_PlanFDQuery -> SQL -> Add
        ("SELECT Edu_plan.*, object_PLAN.name_object||' '||Edu_plan.clock_plan_all||'ч' as name_plan, object_PLAN.name_object FROM EDU_PLAN, object_plan WHERE (YEAR_PLAN=:PLAN) and Edu_plan.n_object = object_plan.n_object AND (N_FAC=:N_FAC) AND (VID_EDU_PLAN=" +
        AnsiString (RadioGroup2 -> ItemIndex) + ") ORDER BY SEMESTR");
    DataModule1 -> Edu_PlanFDQuery -> ParamByName ("N_FAC") -> AsInteger = nom_fac;
    DataModule1 -> Edu_PlanFDQuery -> ParamByName ("PLAN") -> Value = uch_god;
    DataModule1 -> Edu_PlanFDQuery -> Open ();
}


void __fastcall TEdu_planForm::FormClose (TObject *Sender, TCloseAction &Action)
{
    TDateTime ddd;
    TDateTime fff = ddd.CurrentDate ();
    int mon = DateToStr (fff).SubString (4, 2).ToInt ();

    if (mon > 8)
        uch_god = DateToStr (fff).SubString (7, 4).ToInt ();
    else
        uch_god = DateToStr (fff).SubString (7, 4).ToInt () - 1;
    Action = caFree;
}


void __fastcall TEdu_planForm::ApplicationEvents1Message (tagMSG &Msg,
    bool &Handled) {
    // организовать нормальную работу мышиного колесика в DBGrid

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


void __fastcall TEdu_planForm::LabeledEdit1Change (TObject *Sender) {
    uch_god = StrToInt (LabeledEdit1 -> Text);
    DataModule1 -> Edu_PlanFDQuery -> Close ();
    DataModule1 -> Edu_PlanFDQuery -> SQL -> Clear ();
    // ---------
    String s111 =
        "SELECT Edu_plan.*, object_PLAN.name_object||' '||Edu_plan.clock_plan_all||'ч' as name_plan, object_PLAN.name_object FROM EDU_PLAN, object_plan WHERE (YEAR_PLAN=:PLAN) and Edu_plan.n_object = object_plan.n_object AND (EDU_PLAN.N_FAC=:N_FAC) AND (EDU_PLAN.VID_EDU_PLAN=" +
        AnsiString (RadioGroup2 -> ItemIndex) + ") ORDER BY EDU_PLAN.SEMESTR";
    DataModule1 -> Edu_PlanFDQuery -> SQL -> Add (s111);
    DataModule1 -> Edu_PlanFDQuery -> ParamByName ("N_FAC") -> AsInteger = nom_fac;
    DataModule1 -> Edu_PlanFDQuery -> ParamByName ("PLAN") -> Value = uch_god;
    DataModule1 -> Edu_PlanFDQuery -> Open ();
}



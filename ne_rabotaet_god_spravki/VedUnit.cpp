// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "VedUnit.h"
#include "DataModule.h"
#include "VedomostUnit.h"
#include "Ved_ReportUnit.h"
#include <stdlib.h>
#include "Dop_VedUnit.h"
#include "CalendarUnit.h"
#include "Dop_Ved_ReportUnit.h"
#include "DM2Unit.h"
#include "Dop_Ved_RaznicaUnit.h"
#include "JournalUnit.h"

// массив строк для sql по виду обучения
AnsiString v[3] = {
    "", " AND (Edu_plan.VID_EDU_PLAN=0)", " AND (Edu_plan.VID_EDU_PLAN=1)"};
// массив строк для sql по типам ведомостей
// ORDER BY N_VEDOMOST
AnsiString s[4] = {
    "", " AND (Vedomost.STATUS=0)", " AND (Vedomost.STATUS IN (1,3))",
    " AND (Vedomost.STATUS=2)"};
// часть строки SQl для формирования ведомости по учебному плану
AnsiString god_plan = "AND (Edu_plan.YEAR_PLAN=:PLAN)";
// часть строки SQl для формирования ведомости по дате
AnsiString data_ved = "AND (Vedomost.D_VED BETWEEN :D1 AND :D2)";

// часть строки SQl для формирования ведомости по номеру группы
AnsiString ved_group = "AND (Vedomost.INC_GROUP=:GR) ";

// формирование строки sql для Query по ведомости
AnsiString sql_ved =
    "SELECT Vedomost.N_VED, Vedomost.N_VEDOMOST, Vedomost.D_VED, Vedomost.SEMESTR_VED, Vedomost.FIO_EXAM, Vedomost.STATUS, Vedomost.N_PLAN, Vedomost.N_FAC, Vedomost.END_D_EXAM, Vedomost.INC_GROUP, Vedomost.N_SPECIALIZ, Object_plan.NAME_OBJECT, Edu_plan.YEAR_PLAN, Edu_plan.VID_EDU_PLAN, Vedomost.INVALID  FROM VEDOMOST Vedomost INNER JOIN EDU_PLAN Edu_plan ON  (Vedomost.N_PLAN = Edu_plan.N_PLAN) INNER JOIN OBJECT_PLAN Object_plan ON  (Edu_plan.N_OBJECT = Object_plan.N_OBJECT) WHERE (Vedomost.N_FAC=:N_FAC) AND (Vedomost.INVALID = 0)";

AnsiString sql_ved_exlist =
    "SELECT DISTINCT Vedomost.N_VED, Vedomost.N_VEDOMOST, Vedomost.D_VED, Vedomost.SEMESTR_VED, Vedomost.FIO_EXAM, Vedomost.N_PLAN, Vedomost.N_FAC, Vedomost.END_D_EXAM, People.FAM, People.NAME, People.OTCH, Object_plan.NAME_OBJECT, Edu_plan.SEMESTR, Edu_plan.YEAR_PLAN, People.VID_EDU, People.N_GROUP, Vedomost.INVALID FROM VEDOMOST Vedomost INNER JOIN EDU_CARD Edu_card ON (Vedomost.N_VED = Edu_card.N_VED) INNER JOIN EDU_PLAN Edu_plan ON  (Vedomost.N_PLAN = Edu_plan.N_PLAN) INNER JOIN PEOPLE People ON  (Edu_card.NOMER = People.NOMER) INNER JOIN OBJECT_PLAN Object_plan ON  (Edu_plan.N_OBJECT = Object_plan.N_OBJECT) WHERE  (Vedomost.N_FAC=:N_FAC)  AND (Vedomost.INVALID = 0)";

int integr_modul; // интегрированный модуль
int req_modul; // обязательный модуль

// ---------------------------------------------------------------------------

int __fastcall TVed_Form::max_ved (int god_real)
    // Функция, которая возвращает максимальный номер ведомости
{
    DataModule1 -> Max_N_VedomostFDQuery -> Close ();
    DataModule1 -> Max_N_VedomostFDQuery -> ParamByName ("N_FAC") -> AsSmallInt =
        nom_fac;
    DataModule1 -> Max_N_VedomostFDQuery -> ParamByName ("YEAR") -> AsSmallInt =
        god_real;
    DataModule1 -> Max_N_VedomostFDQuery -> Open ();
    return DataModule1 -> Max_N_VedomostFDQueryMAX -> Value + 1;
}
// ---------------------------------------------------------------------------
#pragma package (smart_init)
#pragma resource "*.dfm"
TVed_Form *Ved_Form;

// ---------------------------------------------------------------------------
__fastcall TVed_Form::TVed_Form (TComponent* Owner) : TForm (Owner) {
}

// -----------------------------------------
void __fastcall TVed_Form::ved_run () // выполнение Sql по ведомостям
{

    // RadioGroup1 -> ItemIndex: 0-Все вед-ти; 1-Основные вед-ти; 2-Экзам. листы
    // RadioGroup2 -> ItemIndex: 0-Все ведомости; 1-дневного; 2-заочного

    if (RadioGroup1 -> ItemIndex == 2) // экз. листы
    { // if RadioGroup1
        DBGrid1 -> Visible = false;
        DBGrid2 -> Visible = true;

        DataModule1 -> Ved_exlistFDQuery -> Close ();
        DataModule1 -> Ved_exlistFDQuery -> SQL -> Clear ();

        if (CheckBox1 -> Checked) // ведомости за период
        { // if CheckBox1
            if (!CheckBox2 -> Checked) // не выбран номер группы
            {
                DataModule1 -> Ved_exlistFDQuery -> SQL -> Add
                    (sql_ved_exlist + data_ved + v[RadioGroup2 -> ItemIndex] +
                    s[RadioGroup1 -> ItemIndex] + "ORDER BY N_VEDOMOST");
                DataModule1 -> Ved_exlistFDQuery -> Params -> Items[0] -> AsInteger =
                    nom_fac;
                DataModule1 -> Ved_exlistFDQuery -> Params -> ParamByName ("D1")
                    -> AsDateTime = StrToDate (Edit1 -> Text);
                DataModule1 -> Ved_exlistFDQuery -> Params -> ParamByName ("D2")
                    -> AsDateTime = StrToDate (Edit2 -> Text);

            }
            else { // выбран номер группы
                DataModule1 -> Ved_exlistFDQuery -> SQL -> Add
                    (sql_ved_exlist + data_ved + v[RadioGroup2 -> ItemIndex] +
                    s[RadioGroup1 -> ItemIndex] + ved_group +
                    "ORDER BY N_VEDOMOST");
                DataModule1 -> Ved_exlistFDQuery -> Params -> Items[0] -> AsInteger =
                    nom_fac;
                DataModule1 -> Ved_exlistFDQuery -> Params -> ParamByName ("D1")
                    -> AsDateTime = StrToDate (Edit1 -> Text);
                DataModule1 -> Ved_exlistFDQuery -> Params -> ParamByName ("D2")
                    -> AsDateTime = StrToDate (Edit2 -> Text);
                // Variant lvalues[]={Edit3 -> Text,RadioGroup2 -> ItemIndex-1};
                // Variant V=DM2 -> Increment_GroupTable -> Lookup ("N_GROUP;VID_EDU",
                // VarArrayOf (lvalues,1),"INC_GROUP");

                Variant V = search_increment_group (Edit3 -> Text,
                    RadioGroup2 -> ItemIndex - 1);
                if (!V.IsNull ())
                    DataModule1 -> Ved_exlistFDQuery -> Params -> ParamByName ("GR")
                        -> AsInteger = V.AsType (varInteger);
                else {
                    ShowMessage (
                        "Такого номера группы нет! Проверьте правильность введенных данных");
                    DataModule1 -> Ved_exlistFDQuery -> SQL -> Clear ();
                    DataModule1 -> Ved_exlistFDQuery -> SQL -> Add
                        (sql_ved_exlist + data_ved + v[RadioGroup2 -> ItemIndex] +
                        s[RadioGroup1 -> ItemIndex] + "ORDER BY N_VEDOMOST");
                    DataModule1 -> Ved_exlistFDQuery -> Params -> Items[0]
                        -> AsInteger = nom_fac;
                    DataModule1 -> Ved_exlistFDQuery -> Params -> ParamByName ("D1")
                        -> AsDateTime = StrToDate (Edit1 -> Text);
                    DataModule1 -> Ved_exlistFDQuery -> Params -> ParamByName ("D2")
                        -> AsDateTime = StrToDate (Edit2 -> Text);
                    Edit3 -> Text = "";
                    CheckBox2 -> State = cbUnchecked;
                }
            }

            Ved_Form -> Caption = "Список ведомостей за период с " + Edit1 -> Text +
                " по " + Edit2 -> Text;
        } // end if CheckBox1
        else { // else CheckBox1   -- UnCheked
            if (!CheckBox2 -> Checked) // не выбран номер группы
            {
                DataModule1 -> Ved_exlistFDQuery -> SQL -> Add
                    (sql_ved_exlist + god_plan + data_ved +
                    v[RadioGroup2 -> ItemIndex] + s[RadioGroup1 -> ItemIndex] +
                    "ORDER BY N_VEDOMOST");
                DataModule1 -> Ved_exlistFDQuery -> Params -> Items[0] -> AsInteger =
                    nom_fac;
                DataModule1 -> Ved_exlistFDQuery -> ParamByName ("PLAN") -> Value =
                    uch_god;
                DataModule1 -> Ved_exlistFDQuery -> ParamByName ("D1") -> AsDateTime =
                    curent_date - 10;
                DataModule1 -> Ved_exlistFDQuery -> ParamByName ("D2") -> AsDateTime =
                    curent_date + 30;
            }
            else { // выбран номер группы
                DataModule1 -> Ved_exlistFDQuery -> SQL -> Add
                    (sql_ved_exlist + god_plan + data_ved +
                    v[RadioGroup2 -> ItemIndex] + s[RadioGroup1 -> ItemIndex] +
                    ved_group + "ORDER BY N_VEDOMOST");
                DataModule1 -> Ved_exlistFDQuery -> Params -> Items[0] -> AsInteger =
                    nom_fac;
                DataModule1 -> Ved_exlistFDQuery -> ParamByName ("PLAN") -> Value =
                    uch_god;
                DataModule1 -> Ved_exlistFDQuery -> ParamByName ("D1") -> AsDateTime =
                    curent_date - 10;
                DataModule1 -> Ved_exlistFDQuery -> ParamByName ("D2") -> AsDateTime =
                    curent_date + 30;
                // Variant lvalues[]={Edit3 -> Text,RadioGroup2 -> ItemIndex-1};
                // Variant V=DM2 -> Increment_GroupTable -> Lookup ("N_GROUP;VID_EDU",
                // VarArrayOf (lvalues,1),"INC_GROUP");

                Variant V = search_increment_group (Edit3 -> Text,
                    RadioGroup2 -> ItemIndex - 1);
                if (!V.IsNull ())
                    DataModule1 -> Ved_exlistFDQuery -> Params -> ParamByName ("GR")
                        -> AsInteger = V.AsType (varInteger);
                else {
                    ShowMessage (
                        "Такого номера группы нет! Проверьте правильность введенных данных");
                    DataModule1 -> Ved_exlistFDQuery -> SQL -> Clear ();
                    DataModule1 -> Ved_exlistFDQuery -> SQL -> Add
                        (sql_ved_exlist + god_plan + data_ved +
                        v[RadioGroup2 -> ItemIndex] + s[RadioGroup1 -> ItemIndex] +
                        "ORDER BY N_VEDOMOST");
                    DataModule1 -> Ved_exlistFDQuery -> Params -> Items[0]
                        -> AsInteger = nom_fac;
                    DataModule1 -> Ved_exlistFDQuery -> ParamByName ("PLAN") -> Value =
                        uch_god;
                    DataModule1 -> Ved_exlistFDQuery -> ParamByName ("D1")
                        -> AsDateTime = curent_date - 10;
                    DataModule1 -> Ved_exlistFDQuery -> ParamByName ("D2")
                        -> AsDateTime = curent_date + 30;
                    Edit3 -> Text = "";
                    CheckBox2 -> State = cbUnchecked;
                }
            }
            Ved_Form -> Caption = "Список ведомостей за период с " +
                DateToStr (curent_date - 10) + " по " +
                DateToStr (curent_date + 30);
        } // end else CheckBox1    -- UnCheked

        DataModule1 -> Ved_exlistFDQuery -> Open ();
        // DataModule1 -> Ved_exlistQuery -> Last ();

    } // ind if RadioGroup1
    else // ведомости все и основные
    { // else RadioGroup1
        DBGrid1 -> Visible = true;
        DBGrid2 -> Visible = false;
    } // else END RadioGroup1

    DataModule1 -> VedomostFDQuery -> Close ();
    DataModule1 -> VedomostFDQuery -> SQL -> Clear ();
    if (CheckBox1 -> Checked) { // if CheckBox1
        if (!CheckBox2 -> Checked) // не выбран номер группы
        {
            DataModule1 -> VedomostFDQuery -> SQL -> Add
                (sql_ved + data_ved + v[RadioGroup2 -> ItemIndex] +
                s[RadioGroup1 -> ItemIndex] + "ORDER BY N_VEDOMOST");
            DataModule1 -> VedomostFDQuery -> Params -> Items[0] -> AsInteger = nom_fac;
            DataModule1 -> VedomostFDQuery -> Params -> Items[1] -> AsDateTime =
                StrToDate (Edit1 -> Text);
            DataModule1 -> VedomostFDQuery -> Params -> Items[2] -> AsDateTime =
                StrToDate (Edit2 -> Text);
        }
        else {
            DataModule1 -> VedomostFDQuery -> SQL -> Add
                (sql_ved + data_ved + v[RadioGroup2 -> ItemIndex] +
                s[RadioGroup1 -> ItemIndex] + ved_group + "ORDER BY N_VEDOMOST");
            DataModule1 -> VedomostFDQuery -> Params -> Items[0] -> AsInteger = nom_fac;
            DataModule1 -> VedomostFDQuery -> Params -> Items[1] -> AsDateTime =
                StrToDate (Edit1 -> Text);
            DataModule1 -> VedomostFDQuery -> Params -> Items[2] -> AsDateTime =
                StrToDate (Edit2 -> Text);

            // Variant lvalues[]={Edit3 -> Text,RadioGroup2 -> ItemIndex-1};
            // Variant V=DM2 -> Increment_GroupTable -> Lookup ("N_GROUP;VID_EDU",
            // VarArrayOf (lvalues,1),"INC_GROUP");
            // Variant V=DM2 -> Increment_GroupTable -> Lookup ("N_GROUP",Edit3 -> Text,"INC_GROUP");

            Variant V = search_increment_group (Edit3 -> Text,
                RadioGroup2 -> ItemIndex - 1);
            if (!V.IsNull ())
                DataModule1 -> VedomostFDQuery -> Params -> ParamByName ("GR")
                    -> AsInteger = V.AsType (varInteger);
            else {
                ShowMessage (
                    "Такого номера группы нет! Проверьте правильность введенных данных");
                DataModule1 -> VedomostFDQuery -> SQL -> Clear ();
                DataModule1 -> VedomostFDQuery -> SQL -> Add
                    (sql_ved + data_ved + v[RadioGroup2 -> ItemIndex] +
                    s[RadioGroup1 -> ItemIndex] + "ORDER BY N_VEDOMOST");
                DataModule1 -> VedomostFDQuery -> Params -> Items[0] -> AsInteger =
                    nom_fac;
                DataModule1 -> VedomostFDQuery -> Params -> Items[1] -> AsDateTime =
                    StrToDate (Edit1 -> Text);
                DataModule1 -> VedomostFDQuery -> Params -> Items[2] -> AsDateTime =
                    StrToDate (Edit2 -> Text);
                Edit3 -> Text = "";
                CheckBox2 -> State = cbUnchecked;
            }
        }
        Ved_Form -> Caption = "Список ведомостей за период с " + Edit1 -> Text +
            " по " + Edit2 -> Text;
    } // end if CheckBox1
    else { // else CheckBox1   -- UnCheked
        if (!CheckBox2 -> Checked) // не выбран номер группы
        {
            DataModule1 -> VedomostFDQuery -> SQL -> Add
                (sql_ved + god_plan + data_ved + v[RadioGroup2 -> ItemIndex] +
                s[RadioGroup1 -> ItemIndex] + "ORDER BY N_VEDOMOST");
            DataModule1 -> VedomostFDQuery -> Params -> Items[0] -> AsInteger = nom_fac;
            DataModule1 -> VedomostFDQuery -> ParamByName ("PLAN") -> Value = uch_god;
            DataModule1 -> VedomostFDQuery -> ParamByName ("D1") -> AsDateTime =
                curent_date - 10;
            DataModule1 -> VedomostFDQuery -> ParamByName ("D2") -> AsDateTime =
                curent_date + 30;
        }
        else {
            DataModule1 -> VedomostFDQuery -> SQL -> Add
                (sql_ved + god_plan + data_ved + v[RadioGroup2 -> ItemIndex] +
                s[RadioGroup1 -> ItemIndex] + ved_group + "ORDER BY N_VEDOMOST");
            DataModule1 -> VedomostFDQuery -> Params -> Items[0] -> AsInteger = nom_fac;
            DataModule1 -> VedomostFDQuery -> ParamByName ("PLAN") -> Value = uch_god;
            DataModule1 -> VedomostFDQuery -> ParamByName ("D1") -> AsDateTime =
                curent_date - 10;
            DataModule1 -> VedomostFDQuery -> ParamByName ("D2") -> AsDateTime =
                curent_date + 30;

            // Variant lvalues[]={Edit3 -> Text,RadioGroup2 -> ItemIndex-1};
            // Variant V=DM2 -> Increment_GroupTable -> Lookup ("N_GROUP;VID_EDU",
            // VarArrayOf (lvalues,1),"INC_GROUP");

            Variant V = search_increment_group (Edit3 -> Text,
                RadioGroup2 -> ItemIndex - 1);
            // Variant V=DM2 -> Increment_GroupTable -> Lookup ("N_GROUP",Edit3 -> Text,"INC_GROUP");
            if (!V.IsNull ())
                DataModule1 -> VedomostFDQuery -> Params -> ParamByName ("GR")
                    -> AsInteger = V.AsType (varInteger);
            else {
                ShowMessage (
                    "Такого номера группы нет! Проверьте правильность введенных данных");
                DataModule1 -> VedomostFDQuery -> SQL -> Clear ();
                DataModule1 -> VedomostFDQuery -> SQL -> Add
                    (sql_ved + god_plan + data_ved + v[RadioGroup2 -> ItemIndex] +
                    s[RadioGroup1 -> ItemIndex] + "ORDER BY N_VEDOMOST");
                DataModule1 -> VedomostFDQuery -> Params -> Items[0] -> AsInteger =
                    nom_fac;
                DataModule1 -> VedomostFDQuery -> ParamByName ("PLAN") -> Value =
                    uch_god;
                DataModule1 -> VedomostFDQuery -> ParamByName ("D1") -> AsDateTime =
                    curent_date - 10;
                DataModule1 -> VedomostFDQuery -> ParamByName ("D2") -> AsDateTime =
                    curent_date + 30;
                Edit3 -> Text = "";
                CheckBox2 -> State = cbUnchecked;
            }
        }
        this -> Caption = "Список ведомостей за период с " +
            DateToStr (curent_date - 10) + " по " + DateToStr (curent_date + 30);
    } // end else CheckBox1    -- UnCheked

    DataModule1 -> VedomostFDQuery -> Open ();
    DataModule1 -> VedomostFDQuery -> Last ();
    // } else END RadioGroup1

    // DataModule1 -> VedomostFDQuery -> First ();

    RadioGroup1 -> Enabled = true;
    RadioGroup2 -> Enabled = true;
}

// ---------------------------------------------------------------------------
void __fastcall TVed_Form::DBGrid1DblClick (TObject *Sender) {

    if (!DataModule1 -> VedomostFDQuerySTATUS -> Value) {
        VedomostForm = new TVedomostForm (this);
        // Создание формы Формирование ведомости
        VedomostForm -> Caption = "Редактирование ведомости";
        // занесение в Edit1  даты экзамена
        BitBtn3 -> Enabled = False;
        VedomostForm -> Edit1 -> Text =
            DateToStr (SQLTimeStampToDateTime
            (DataModule1 -> VedomostFDQueryD_VED -> Value));
        VedomostForm -> Edit4 -> Text =
            DateToStr (SQLTimeStampToDateTime
            (DataModule1 -> VedomostFDQueryEND_D_EXAM -> Value));
        if (!DataModule1 -> Edu_CardFDQuery -> Active) {
            DataModule1 -> Edu_CardFDQuery -> SQL -> Clear ();
            DataModule1 -> Edu_CardFDQuery -> SQL -> Add
                ("SELECT * FROM EDU_CARD ORDER BY N_VED");
            DataModule1 -> Edu_CardFDQuery -> Open ();
        }
        if (DataModule1 -> VedomostFDQueryN_SPECIALIZ -> Value) {
            VedomostForm -> ComboBox3 -> Visible = true;
            VedomostForm -> ComboBox3 -> Enabled = false;
            VedomostForm -> ComboBox3 -> Text =
                DM2 -> SpecializFDTable -> Lookup ("N_SPECIALIZ",
                DataModule1 -> VedomostFDQueryN_SPECIALIZ -> Value, "SPECIAL");
        }
        // занесение номера ведомости в Label4
        VedomostForm -> Label4 -> Caption =
            AnsiString (DataModule1 -> VedomostFDQueryN_VEDOMOST -> Value);

        if (DataModule1 -> VedomostFDQueryINC_GROUP -> Value)
        { // занесение в  Edit2  номера группы

            VedomostForm -> Edit2 -> Text =
                DM2 -> Increment_GroupFDTable -> Lookup ("INC_GROUP",
                DataModule1 -> VedomostFDQueryINC_GROUP -> Value, "N_GROUP");
            // занесение в ComboBox2 вида обучения
            VedomostForm -> ComboBox2 -> ItemIndex =
                DM2 -> Increment_GroupFDTable -> Lookup ("INC_GROUP",
                DataModule1 -> VedomostFDQueryINC_GROUP -> Value, "VID_EDU");

        } // end if
        else { // занесение в  Edit2  номера группы  если не было сохранено в ведомости инкремента группы (в старых ведомостях)
            try { // try
                int nom_group = DataModule1 -> Edu_CardFDQuery -> Lookup ("N_VED",
                    DataModule1 -> VedomostFDQueryN_VED -> Value, "NOMER");
                DataModule1 -> People_PartFDQuery -> Active = true;
                DataModule1 -> People_PartFDQuery -> Close ();
                DataModule1 -> People_PartFDQuery -> SQL -> Clear ();
                DataModule1 -> People_PartFDQuery -> SQL -> Add
                    ("SELECT NOMER, FAM, NAME, OTCH, INC_GROUP, N_GROUP, VID_EDU, KURS, N_FOUND FROM PEOPLE WHERE (N_FAC=" +
                    AnsiString (nom_fac) + ") AND (STATUS_PEOPLE=1)");
                DataModule1 -> People_PartFDQuery -> Open ();
                VedomostForm -> Edit2 -> Text =
                    DataModule1 -> People_PartFDQuery -> Lookup ("NOMER", nom_group,
                    "N_GROUP");
                // занесение в ComboBox2 вида обучения
                VedomostForm -> ComboBox2 -> ItemIndex =
                    DataModule1 -> People_PartFDQuery -> Lookup ("NOMER", nom_group,
                    "VID_EDU");
                DataModule1 -> People_PartFDQuery -> Active = false;
            } // end try
            catch (...) { // catch
                ShowMessage (
                    "Эта ведомость была создана неправильно. Удалите ведомость!");
            } // catch
        } // end else

        // занесение в Edit3  номера семестра
        VedomostForm -> Edit3 -> Text =
            AnsiString (DataModule1 -> VedomostFDQuerySEMESTR_VED -> Value);

        VedomostForm -> ComboBox1 -> Items -> Clear ();

        DataModule1 -> Edu_PlanFDQuery -> Close ();
        DataModule1 -> Edu_PlanFDQuery -> SQL -> Clear ();
        DataModule1 -> Edu_PlanFDQuery -> SQL -> Add
            ("SELECT Edu_plan.*, object_PLAN.name_object||' '||Edu_plan.clock_plan_all||'ч' as name_plan, object_PLAN.name_object FROM EDU_PLAN, object_plan WHERE (N_FAC=:N_FAC) and Edu_plan.n_object = object_plan.n_object AND (SEMESTR=" +
            VedomostForm -> Edit3 -> Text + ")");
        DataModule1 -> Edu_PlanFDQuery -> Params -> Items[0] -> AsInteger = nom_fac;
        DataModule1 -> Edu_PlanFDQuery -> Open ();
        int nom_pred = DataModule1 -> Edu_PlanFDQuery -> Lookup ("N_PLAN",
            DataModule1 -> VedomostFDQueryN_PLAN -> Value, "N_OBJECT");
        // Dop_VedForm -> ComboBox1 -> Text=DM2 -> Object_PlanTable -> Lookup ("N_OBJECT",nom_predmet,"NAME_OBJECT");
        // занесение в ComboBox1 предмета
        VedomostForm -> ComboBox1 -> Text =
            DataModule1 -> Edu_PlanFDQueryNAME_PLAN -> Value;
        for (int i = 0; i < DataModule1 -> Edu_PlanFDQuery -> RecordCount; i++) {
            VedomostForm -> ComboBox1 -> Items -> Add
                (DataModule1 -> Edu_PlanFDQueryNAME_PLAN -> Value);
            DataModule1 -> Edu_PlanFDQuery -> Next ();
        }
        DataModule1 -> Edu_PlanFDQuery -> Close ();
        DataModule1 -> Edu_PlanFDQuery -> SQL -> Clear ();
        DataModule1 -> Edu_PlanFDQuery -> SQL -> Add
            ("SELECT Edu_plan.*, object_PLAN.name_object||' '||Edu_plan.clock_plan_all||'ч' as name_plan, object_PLAN.name_object FROM EDU_PLAN, object_plan WHERE N_FAC=:N_FAC and Edu_plan.n_object = object_plan.n_object ORDER BY SEMESTR"
            );
        DataModule1 -> Edu_PlanFDQuery -> Params -> Items[0] -> AsInteger = nom_fac;
        DataModule1 -> Edu_PlanFDQuery -> Open ();
        DataModule1 -> VedomostFDQuery -> Edit ();
        DataModule1 -> Edu_Card_CountFDQuery -> Active = False;
        DataModule1 -> Edu_Card_CountFDQuery -> ParamByName ("N_VED") -> AsInteger =
            DataModule1 -> VedomostFDQueryN_VED -> Value;
        DataModule1 -> Edu_Card_CountFDQuery -> Active = True;
        /* if (DataModule1 -> Edu_Card_CountFDQueryCOUNT -> Value) {
         VedomostForm -> Edit1 -> Enabled = false;
         VedomostForm -> DBEdit2 -> Enabled = false;
         } */
        VedomostForm -> Edit2 -> Enabled = false;
        VedomostForm -> ComboBox2 -> Enabled = false;
        VedomostForm -> Panel2 -> Enabled = false;
        VedomostForm -> ComboBox1 -> Enabled = false;
        VedomostForm -> Label6 -> Enabled = false;
        VedomostForm -> Edit3 -> Enabled = false;

        VedomostForm -> ShowModal (); // Показ формы Формирование ведомости
    }
    else {

        Dop_VedForm = new TDop_VedForm (this);
        Dop_VedForm -> Caption = "Редактирование ведомости";
        Dop_VedForm -> Edit1 -> Text =
            DateToStr (SQLTimeStampToDateTime
            (DataModule1 -> VedomostFDQueryD_VED -> Value));
        Variant search_date =
            SQLTimeStampToDateTime (DataModule1 -> VedomostFDQueryEND_D_EXAM
            -> Value);
        if (search_date != 0) // если нет последней даты
        {
            Dop_VedForm -> Edit2 -> Text =
                DateToStr (SQLTimeStampToDateTime
                (DataModule1 -> VedomostFDQueryEND_D_EXAM -> Value));
        }
        else
            Dop_VedForm -> Edit2 -> Text = "";

        Variant V = DM2 -> Increment_GroupFDTable -> Lookup ("INC_GROUP",
            DataModule1 -> VedomostFDQueryINC_GROUP -> Value, "N_GROUP");
        if (!V.IsNull ())
            Dop_VedForm -> Edit4 -> Text = VarToStr (V);
        Dop_VedForm -> Edit4 -> Enabled = false;
        Dop_VedForm -> Edit3 -> Text =
            AnsiString (DataModule1 -> VedomostFDQuerySEMESTR_VED -> Value);
        Dop_VedForm -> Edit5 -> Text = DataModule1 -> VedomostFDQueryYEAR_PLAN -> Value;
        Dop_VedForm -> Edit6 -> Text =
            DataModule1 -> VedomostFDQueryYEAR_PLAN -> Value + 1;
        Dop_VedForm -> ComboBox1 -> Items -> Clear ();

        DataModule1 -> Edu_PlanFDQuery -> Close ();
        DataModule1 -> Edu_PlanFDQuery -> SQL -> Clear ();
        DataModule1 -> Edu_PlanFDQuery -> SQL -> Add
            ("SELECT Edu_plan.*, object_PLAN.name_object||' '||Edu_plan.clock_plan_all||'ч' as name_plan, object_PLAN.name_object FROM EDU_PLAN, object_plan WHERE (N_FAC=:N_FAC) and Edu_plan.n_object = object_plan.n_object AND (SEMESTR=" +
            Dop_VedForm -> Edit3 -> Text + ")");
        DataModule1 -> Edu_PlanFDQuery -> Params -> Items[0] -> AsInteger = nom_fac;
        DataModule1 -> Edu_PlanFDQuery -> Open ();

        int nom_predmet = DataModule1 -> Edu_PlanFDQuery -> Lookup ("N_PLAN",
            DataModule1 -> VedomostFDQueryN_PLAN -> Value, "N_OBJECT");
        Dop_VedForm -> ComboBox1 -> Text =
            DataModule1 -> Edu_PlanFDQueryNAME_PLAN -> Value;
        Dop_VedForm -> ComboBox2 -> ItemIndex =
            DataModule1 -> Edu_PlanFDQuery -> Lookup ("N_PLAN",
            DataModule1 -> VedomostFDQueryN_PLAN -> Value, "VID_EDU_PLAN");

        for (int i = 0; i < DataModule1 -> Edu_PlanFDQuery -> RecordCount; i++) {
            Dop_VedForm -> ComboBox1 -> Items -> Add
                (DataModule1 -> Edu_PlanFDQueryNAME_PLAN -> Value);
            DataModule1 -> Edu_PlanFDQuery -> Next ();
        }
        DataModule1 -> Edu_PlanFDQuery -> Close ();
        DataModule1 -> Edu_PlanFDQuery -> SQL -> Clear ();
        DataModule1 -> Edu_PlanFDQuery -> SQL -> Add
            ("SELECT Edu_plan.*, object_PLAN.name_object||' '||Edu_plan.clock_plan_all||'ч' as name_plan, object_PLAN.name_object FROM EDU_PLAN, object_plan WHERE N_FAC=:N_FAC and Edu_plan.n_object = object_plan.n_object ORDER BY SEMESTR"
            );
        DataModule1 -> Edu_PlanFDQuery -> Params -> Items[0] -> AsInteger = nom_fac;
        DataModule1 -> Edu_PlanFDQuery -> Open ();
        state_query = 0;
        Dop_VedForm -> Edit7 -> Text = DataModule1 -> VedomostFDQueryFIO_EXAM -> Value;
        DataModule1 -> VedomostFDQuery -> Edit ();
        if (DataModule1 -> VedomostFDQuerySTATUS -> Value == 2) {
            Dop_VedForm -> Label3 -> Visible = false;
            Dop_VedForm -> Edit2 -> Visible = false;
        }
        DataModule1 -> Edu_Card_CountFDQuery -> Active = False;
        DataModule1 -> Edu_Card_CountFDQuery -> ParamByName ("N_VED") -> AsInteger =
            DataModule1 -> VedomostFDQueryN_VED -> Value;
        DataModule1 -> Edu_Card_CountFDQuery -> Active = True;
        /* if (DataModule1 -> Edu_Card_CountFDQueryCOUNT -> Value) {
         Dop_VedForm -> Edit1 -> Enabled = false;
         Dop_VedForm -> Edit2 -> Enabled = false;
         Dop_VedForm -> DBEdit3 -> Enabled = false;
         } */
        Dop_VedForm -> Edit5 -> Enabled = false;
        Dop_VedForm -> Edit6 -> Enabled = false;
        Dop_VedForm -> ComboBox2 -> Enabled = false;
        Dop_VedForm -> ComboBox1 -> Enabled = false;
        Dop_VedForm -> Label6 -> Enabled = false;
        Dop_VedForm -> Panel2 -> Enabled = false;
        Dop_VedForm -> Edit3 -> Enabled = false;
        Dop_VedForm -> ShowModal ();

    }

}

// ---------------------------------------------------------------------------
void __fastcall TVed_Form::BitBtn3Click (TObject *Sender) {
    Close ();
}

// ---------------------------------------------------------------------------
void __fastcall TVed_Form::BitBtn1Click (TObject *Sender) {
    VedomostForm = new TVedomostForm (this);
    // Создание формы Формирование ведомости
    VedomostForm -> Caption = "Добавление новой ведомости";
    DataModule1 -> VedomostFDQuery -> Insert ();
    VedomostForm -> Edit1 -> Text = "";
    VedomostForm -> Edit2 -> Enabled = true;
    VedomostForm -> ComboBox2 -> Enabled = true;
    VedomostForm -> Edit2 -> Text = "";
    VedomostForm -> Edit3 -> Text = "";
    VedomostForm -> ComboBox2 -> ItemIndex = -1;
    VedomostForm -> ComboBox1 -> ItemIndex = -1;
    VedomostForm -> ComboBox1 -> Items -> Clear ();
    VedomostForm -> ComboBox1 -> Enabled = false;
    VedomostForm -> Label6 -> Enabled = false;
    // вызов функции для нахождения максимального номера ведомости
    VedomostForm -> Label4 -> Caption = AnsiString (max_ved (uch_god));

    VedomostForm -> Panel2 -> Enabled = true;
    VedomostForm -> Edit3 -> Enabled = true;
    VedomostForm -> BitBtn3 -> Visible = false;
    VedomostForm -> ShowModal ();
}

// ---------------------------------------------------------------------------
void __fastcall TVed_Form::BitBtn2Click (TObject *Sender) {
    /* //
     // 10.05.2014 - интегрированный модуль, 02.12.2014 - обязательный модуль

     if (DBGrid1 -> Visible)

     {
     DataModule1 -> Integr_modulFDQuery -> Close ();

     DataModule1 -> Integr_modulFDQuery -> ParamByName ("n_ved") -> AsInteger =
     DBGrid1 -> Columns -> Items[8] -> Field -> AsInteger;
     DataModule1 -> Integr_modulFDQuery -> Open ();

     //  if ( (DataModule1 -> Integr_modulN_OBJECT -> AsInteger==398) || (DataModule1 -> Integr_modulN_OBJECT -> AsInteger==415))

     //     integr_modul=1;
     //     else integr_modul=0;

     //     if ( (DataModule1 -> Integr_modulN_OBJECT -> AsInteger==446)|| (DataModule1 -> Integr_modulN_OBJECT -> AsInteger==451) || (DataModule1 -> Integr_modulN_OBJECT -> AsInteger==444)|| (DataModule1 -> Integr_modulN_OBJECT -> AsInteger==456))

     //     req_modul=1;
     //     else req_modul=0;

     }

     if (DBGrid2 -> Visible)

     {

     DataModule1 -> Integr_modulFDQuery -> Close ();

     DataModule1 -> Integr_modulFDQuery -> ParamByName ("n_ved") -> AsInteger =
     DBGrid2 -> Columns -> Items[9] -> Field -> AsInteger;
     DataModule1 -> Integr_modulFDQuery -> Open ();

     TLocateOptions Opts;
     Variant poisk;
     poisk = DataModule1 -> VedomostFDQuery -> Locate ("N_VED",
     DataModule1 -> Ved_exlistFDQueryN_VED -> Value, Opts);

     if (poisk.IsNull ())
     return;
     }

     if ( (DataModule1 -> VedomostFDQuerySTATUS -> Value == 0) ||
     (DataModule1 -> VedomostFDQuerySTATUS -> Value == 2))
     { // формирование основной или дополнительной ведомости в Reporte
     if () {

     }
     Ved_ReportForm = new TVed_ReportForm (this);
     DataModule1 -> Vedomost_ReportFDQuery -> Close ();
     DataModule1 -> Vedomost_ReportFDQuery -> ParamByName ("N_FAC") -> AsInteger =
     nom_fac;
     DataModule1 -> Vedomost_ReportFDQuery -> ParamByName ("N_VEDOM") -> AsInteger =
     DataModule1 -> VedomostFDQueryN_VED -> Value;
     DataModule1 -> Vedomost_ReportFDQuery -> Open ();
     if (Ved_ReportForm -> frxReport1 -> PrepareReport (true))
     Ved_ReportForm -> frxReport1 -> ShowPreparedReport ();
     }
     else { // формирование экзаменационного листа (или ведомости для досрочной сдачи)
     Ved_ReportForm = new TVed_ReportForm (this);

     // нахождение нужной записи в  VedomostFDQuery, т.к. в этом Gride открыт  Ved_exlistQuery

     DataModule1 -> Vedomost_ReportFDQuery -> Close ();
     DataModule1 -> Vedomost_ReportFDQuery -> ParamByName ("N_FAC") -> AsInteger =
     nom_fac;
     DataModule1 -> Vedomost_ReportFDQuery -> ParamByName ("N_VEDOM") -> AsInteger =
     DataModule1 -> VedomostFDQueryN_VED -> Value;
     DataModule1 -> Vedomost_ReportFDQuery -> Open ();
     // занесение названия факультета

     DataModule1 -> Integr_modulFDQuery -> Open ();

     }

     if (Ved_ReportForm -> frxReport2 -> PrepareReport (true))
     Ved_ReportForm -> frxReport2 -> ShowPreparedReport ();
     }
     */
    Ved_ReportForm = new TVed_ReportForm (this);
    Ved_ReportForm -> FDQuery3 -> Close ();
    Ved_ReportForm -> FDQuery3 -> SQL -> Add
        (" and y.N_OBJECT = ( select first 1 y.N_OBJECT from VEDOMOST, EDU_PLAN, OBJECT_PLAN a, SUB_EDU_PLAN y, OBJECT_PLAN b, SUB_EDU_PLAN z, OBJECT_PLAN c, EDU_CARD, PEOPLE, FACULTY, inc_group_old where VEDOMOST.N_PLAN = EDU_PLAN.N_PLAN and EDU_PLAN.N_PLAN = y.N_PLAN_PARENT and EDU_PLAN.N_PLAN = z.N_PLAN_PARENT and y.N_OBJECT = b.N_OBJECT and z.N_OBJECT = c.N_OBJECT and y.N_PLAN <> z.N_PLAN and VEDOMOST.N_VED = :N_VED  AND (Vedomost.INVALID = 0)  ) ORDER BY PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH"
        );

    TfrxReportTitle * ReportTitle1 =
        dynamic_cast<TfrxReportTitle*> (Ved_ReportForm -> frxReport1 -> FindObject
        ("ReportTitle1"));
    TfrxHeader * Header1 = dynamic_cast<TfrxHeader*>
        (Ved_ReportForm -> frxReport1 -> FindObject ("Header2"));
    TfrxMasterData * MasterData1 =
        dynamic_cast<TfrxMasterData*> (Ved_ReportForm -> frxReport1 -> FindObject
        ("MasterData1"));
    TfrxFooter * Footer1 = dynamic_cast<TfrxFooter*>
        (Ved_ReportForm -> frxReport1 -> FindObject ("Footer1"));
    TfrxReportSummary * ReportSummary1 =
        dynamic_cast<TfrxReportSummary*>
        (Ved_ReportForm -> frxReport1 -> FindObject ("ReportSummary1"));
    TfrxMemoView * Memo1 = dynamic_cast<TfrxMemoView*>
        (Ved_ReportForm -> frxReport1 -> FindObject ("Memo41"));
    TfrxMemoView * Memo2 = dynamic_cast<TfrxMemoView*>
        (Ved_ReportForm -> frxReport1 -> FindObject ("Memo42"));
    TfrxLineView * Line1 = dynamic_cast<TfrxLineView*>
        (Ved_ReportForm -> frxReport1 -> FindObject ("Line4"));
    TfrxMemoView * Memo3 = dynamic_cast<TfrxMemoView*>
        (Ved_ReportForm -> frxReport1 -> FindObject ("Memo48"));
    TfrxMemoView * Memo4 = dynamic_cast<TfrxMemoView*>
        (Ved_ReportForm -> frxReport1 -> FindObject ("Memo49"));
    TfrxLineView * Line2 = dynamic_cast<TfrxLineView*>
        (Ved_ReportForm -> frxReport1 -> FindObject ("Line2"));
    TfrxMemoView * Memo5 = dynamic_cast<TfrxMemoView*>
        (Ved_ReportForm -> frxReport1 -> FindObject ("Memo21"));
    TfrxMemoView * Memo6 = dynamic_cast<TfrxMemoView*>
        (Ved_ReportForm -> frxReport1 -> FindObject ("Memo25"));
    TfrxMemoView * Memo7 = dynamic_cast<TfrxMemoView*>
        (Ved_ReportForm -> frxReport1 -> FindObject ("Memo26"));
    TfrxReportTitle * ReportTitle3 =
        dynamic_cast<TfrxReportTitle*> (Ved_ReportForm -> frxReport3 -> FindObject
        ("ReportTitle1"));
    TfrxFooter * Footer3 = dynamic_cast<TfrxFooter*>
        (Ved_ReportForm -> frxReport3 -> FindObject ("Footer1"));
    TfrxReportSummary * ReportSummary3 =
        dynamic_cast<TfrxReportSummary*>
        (Ved_ReportForm -> frxReport3 -> FindObject ("ReportSummary1"));
    TfrxMemoView * Memo33 = dynamic_cast<TfrxMemoView*>
        (Ved_ReportForm -> frxReport3 -> FindObject ("Memo70"));
    TfrxMemoView * Memo34 = dynamic_cast<TfrxMemoView*>
        (Ved_ReportForm -> frxReport3 -> FindObject ("Memo71"));
    TfrxLineView * Line32 = dynamic_cast<TfrxLineView*>
        (Ved_ReportForm -> frxReport3 -> FindObject ("Line22"));
    TfrxMemoView * Memo35 = dynamic_cast<TfrxMemoView*>
        (Ved_ReportForm -> frxReport3 -> FindObject ("Memo24"));
    TfrxMemoView * Memo36 = dynamic_cast<TfrxMemoView*>
        (Ved_ReportForm -> frxReport3 -> FindObject ("Memo43"));
    TfrxMemoView * Memo37 = dynamic_cast<TfrxMemoView*>
        (Ved_ReportForm -> frxReport3 -> FindObject ("Memo54"));

    Ved_ReportForm -> FDQuery5 -> Close ();
    Ved_ReportForm -> FDQuery5 -> ParamByName ("N_VED") -> AsInteger =
        DBGrid1 -> Columns -> Items[8] -> Field -> AsInteger;
    Ved_ReportForm -> FDQuery5 -> Open ();
    if (DataModule1 -> VedomostFDQuerySTATUS -> Value == 0) {
        Header1 -> Visible = true;
        MasterData1 -> Visible = true;
        Footer1 -> Visible = false;
        ReportTitle1 -> Height = 500;
        ReportSummary1 -> Visible = true;
        Memo1 -> Visible = false;
        Memo2 -> Visible = false;
        Line1 -> Visible = false;
        Memo3 -> Visible = true;
        Memo4 -> Visible = true;
        Line2 -> Visible = true;
        Memo5 -> Visible = false;
        Memo6 -> Visible = false;
        Memo7 -> Visible = false;

        Footer3 -> Visible = false;
        ReportTitle3 -> Height = 500;
        ReportSummary3 -> Visible = true;
        Memo33 -> Visible = true;
        Memo34 -> Visible = true;
        Line32 -> Visible = true;
        Memo35 -> Visible = false;
        Memo36 -> Visible = false;
        Memo37 -> Visible = false;
    }
    else {
        Header1 -> Visible = false;
        MasterData1 -> Visible = false;
        Footer1 -> Visible = true;
        ReportTitle1 -> Height = 460;
        ReportSummary1 -> Visible = false;
        Memo1 -> Visible = true;
        Memo2 -> Visible = true;
        Line1 -> Visible = true;
        Memo3 -> Visible = false;
        Memo4 -> Visible = false;
        Line2 -> Visible = false;
        Memo5 -> Visible = true;
        Memo6 -> Visible = true;
        Memo7 -> Visible = true;

        Footer3 -> Visible = true;
        ReportTitle3 -> Height = 460;
        ReportSummary3 -> Visible = false;
        Memo33 -> Visible = false;
        Memo34 -> Visible = false;
        Line32 -> Visible = false;
        Memo35 -> Visible = true;
        Memo36 -> Visible = true;
        Memo37 -> Visible = true;
    }
    TDateTime CurrentDate;
    CurrentDate = Date ();
    if (Ved_ReportForm -> FDQuery5COUNT -> Value) {
        Ved_ReportForm -> FDQuery3 -> Close ();
        Ved_ReportForm -> FDQuery3 -> ParamByName ("N_VED") -> AsInteger =
            DBGrid1 -> Columns -> Items[8] -> Field -> AsInteger;
        Ved_ReportForm -> FDQuery3 -> Open ();
        /* if (SQLTimeStampToDateTime (Ved_ReportForm -> FDQuery3D_VED -> Value) >=
         CurrentDate - 7) { */
        if (Ved_ReportForm -> frxReport3 -> PrepareReport (true))
            Ved_ReportForm -> frxReport3 -> ShowPreparedReport ();
        /* }
         else {
         ShowMessage ("Вы не можете позже недели после создания!");
         } */
        Ved_ReportForm -> FDQuery3 -> Close ();
    }
    else {
        Ved_ReportForm -> FDQuery1 -> Close ();
        Ved_ReportForm -> FDQuery1 -> ParamByName ("N_VED") -> AsInteger =
            DBGrid1 -> Columns -> Items[8] -> Field -> AsInteger;
        Ved_ReportForm -> FDQuery1 -> Open ();
        /* if (SQLTimeStampToDateTime (Ved_ReportForm -> FDQuery1D_VED -> Value) >=
         CurrentDate - 7) { */
        if (Ved_ReportForm -> frxReport1 -> PrepareReport (true))
            Ved_ReportForm -> frxReport1 -> ShowPreparedReport ();
        /* }
         else {
         ShowMessage ("Вы не можете позже недели после создания!");
         } */
        Ved_ReportForm -> FDQuery1 -> Close ();
    }
}

// ---------------------------------------------------------------------------

void __fastcall TVed_Form::SpeedButton1Click (TObject * Sender) {
    Dop_VedForm = new TDop_VedForm (this);
    // Создание формы Формирование ведомости
    Dop_VedForm -> Caption = "Добавление экзаменационного листа";
    // DataModule1 -> VedomostFDQuery -> Insert ();
    state_query = 1;
    Dop_VedForm -> Edit1 -> Text = "";
    Dop_VedForm -> Edit3 -> Text = "";
    Dop_VedForm -> Edit4 -> Text = "";
    Dop_VedForm -> Edit4 -> Enabled = true;
    Dop_VedForm -> ComboBox1 -> ItemIndex = -1;
    Dop_VedForm -> ComboBox2 -> ItemIndex = -1;
    Dop_VedForm -> ComboBox1 -> Items -> Clear ();
    Dop_VedForm -> Edit5 -> Text = uch_god;
    Dop_VedForm -> Edit6 -> Text = uch_god + 1;
    Dop_VedForm -> ComboBox1 -> Enabled = false;
    Dop_VedForm -> Label6 -> Enabled = false;
    Dop_VedForm -> BitBtn3 -> Visible = false;
    Dop_VedForm -> ShowModal ();
}
// ---------------------------------------------------------------------------

void __fastcall TVed_Form::RadioGroup1Click (TObject * Sender) {
    ved_run ();
}
// ---------------------------------------------------------------------------

void __fastcall TVed_Form::CheckBox1Click (TObject * Sender) {
    if (CheckBox1 -> Checked) {
        RadioGroup1 -> Enabled = false;
        RadioGroup2 -> Enabled = false;
        Label3 -> Enabled = true;
        Edit1 -> Enabled = true;
        Label4 -> Enabled = true;
        Edit2 -> Enabled = true;
        BitBtn4 -> Enabled = true;
        Edit1 -> SetFocus ();
    }
    else {
        Label3 -> Enabled = false;
        Edit1 -> Enabled = false;
        Label4 -> Enabled = false;
        Edit2 -> Enabled = false;
        BitBtn4 -> Enabled = false;
        Edit1 -> Text = "";
        Edit2 -> Text = "";
        RadioGroup1 -> Enabled = true;
        RadioGroup2 -> Enabled = true;
        ved_run ();
    }

}
// ---------------------------------------------------------------------------

void __fastcall TVed_Form::BitBtn4Click (TObject * Sender) {
    if ( (Edit1 -> Text != "") && (Edit2 -> Text != "")) {
        ved_run ();
    }
}
// ---------------------------------------------------------------------------

void __fastcall TVed_Form::FormCreate (TObject * Sender) {
    // текущая дата
    curent_date = cur_d ();
    // ved_run ();

}
// ---------------------------------------------------------------------------

void __fastcall TVed_Form::SpeedButton2Click (TObject * Sender) {
    Dop_VedForm = new TDop_VedForm (this);
    // Создание формы Формирование ведомости
    Dop_VedForm -> Caption =
        "Добавление новой ведомости для досрочной сдачи сессии";
    // DataModule1 -> VedomostFDQuery -> Insert ();
    state_query = 1;
    Dop_VedForm -> Edit1 -> Text = "";
    Dop_VedForm -> Edit3 -> Text = "";
    Dop_VedForm -> Edit4 -> Text = "";
    Dop_VedForm -> Edit4 -> Enabled = true;
    Dop_VedForm -> ComboBox1 -> Text = "";
    Dop_VedForm -> ComboBox2 -> Text = "";
    Dop_VedForm -> ComboBox1 -> Items -> Clear ();
    Dop_VedForm -> Edit4 -> Text = "";
    Dop_VedForm -> Edit5 -> Text = uch_god;
    Dop_VedForm -> Edit6 -> Text = uch_god + 1;

    Dop_VedForm -> ComboBox1 -> Enabled = false;
    Dop_VedForm -> Label6 -> Enabled = false;
    Dop_VedForm -> ShowModal ();
}
// ---------------------------------------------------------------------------

void __fastcall TVed_Form::Edit1Click (TObject * Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> ShowModal ();
    if (calendar)
        Edit1 -> Text = cal_date;
    Edit2 -> SetFocus ();
}
// ---------------------------------------------------------------------------

void __fastcall TVed_Form::Edit2Click (TObject * Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> ShowModal ();
    if (calendar)
        Edit2 -> Text = cal_date;
    BitBtn4 -> SetFocus ();
}
// ---------------------------------------------------------------------------

void __fastcall TVed_Form::FormClose (TObject * Sender, TCloseAction & Action) {
    Action = caFree;
}
// ---------------------------------------------------------------------------

void __fastcall TVed_Form::BitBtn5Click (TObject * Sender)
{ // кнопка удалить ведомость

    // действие по кнопке удалить
    AnsiString box = "Удаление ведомости № " +
        AnsiString (DataModule1 -> VedomostFDQueryN_VEDOMOST -> Value) + " " +
        DataModule1 -> VedomostFDQueryNAME_OBJECT -> Value;
    // !!!if (Application -> MessageBox (box.c_str (),"Удалить выбранную ведомость?", MB_YESNO)== IDYES)
    if (MessageDlg (box.c_str (), mtConfirmation,
        TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
    { // Удаление выбранной записи

        DataModule1 -> Ball_FDQuery -> Close ();
        DataModule1 -> Ball_FDQuery -> ParamByName ("N_FAC") -> AsInteger = nom_fac;
        DataModule1 -> Ball_FDQuery -> ParamByName ("N_VEDOM") -> AsInteger =
            DataModule1 -> VedomostFDQueryN_VED -> Value;
        DataModule1 -> Ball_FDQuery -> Open ();
        int kol_rec = DataModule1 -> Ball_FDQuery -> RecordCount;

        if (kol_rec) {
            for (int i = 0; i < kol_rec; i++) {
                if (!DataModule1 -> Ball_FDQueryBALL -> IsNull) {
                    ShowMessage (
                        "Не возможно удалить ведомость, содержащую оценки!");
                    return;
                }
                DataModule1 -> Ball_FDQuery -> Next ();
            }
        }

        DataModule1 -> VedomostFDQuery -> Delete ();
        DataModule1 -> VedomostFDQuery -> ApplyUpdates ();
        DataModule1 -> VedomostFDQuery -> CommitUpdates ();
        DataModule1 -> Ball_FDQuery -> Close ();
    }
}
// ---------------------------------------------------------------------------

void __fastcall TVed_Form::RadioGroup2Click (TObject * Sender) {

    if (RadioGroup2 -> ItemIndex)
        CheckBox2 -> Enabled = true;
    else {
        CheckBox2 -> State = cbUnchecked;
        CheckBox2 -> Enabled = false;
    }
    ved_run ();
}
// ---------------------------------------------------------------------------

void __fastcall TVed_Form::IO_EXAM (TObject * Sender) {
    // нахождение нужной записи в  VedomostFDQuery, т.к. в этом Gride открыт  Ved_exlistQuery
    TLocateOptions Opts;

    DataModule1 -> VedomostFDQuery -> Locate ("N_VED",
        DataModule1 -> Ved_exlistFDQueryN_VED -> Value, Opts);

    Dop_VedForm = new TDop_VedForm (this);
    Dop_VedForm -> Caption = "Редактирование ведомости";
    Dop_VedForm -> Edit1 -> Text =
        DateToStr (SQLTimeStampToDateTime
        (DataModule1 -> VedomostFDQueryD_VED -> Value));
    Variant search_date =
        SQLTimeStampToDateTime (DataModule1 -> VedomostFDQueryEND_D_EXAM -> Value);
    if (search_date != 0) // если нет последней даты
    {
        Dop_VedForm -> Edit2 -> Text =
            DateToStr (SQLTimeStampToDateTime
            (DataModule1 -> VedomostFDQueryEND_D_EXAM -> Value));
    }
    else
        Dop_VedForm -> Edit2 -> Text = "";

    Variant V = DM2 -> Increment_GroupFDTable -> Lookup ("INC_GROUP",
        DataModule1 -> VedomostFDQueryINC_GROUP -> Value, "N_GROUP");
    if (!V.IsNull ())
        Dop_VedForm -> Edit4 -> Text = VarToStr (V);
    Dop_VedForm -> Edit4 -> Enabled = false;
    Dop_VedForm -> Edit3 -> Text =
        AnsiString (DataModule1 -> VedomostFDQuerySEMESTR_VED -> Value);
    Dop_VedForm -> Edit5 -> Text = DataModule1 -> VedomostFDQueryYEAR_PLAN -> Value;
    Dop_VedForm -> Edit6 -> Text = DataModule1 -> VedomostFDQueryYEAR_PLAN -> Value + 1;
    Dop_VedForm -> ComboBox1 -> Items -> Clear ();

    DataModule1 -> Edu_PlanFDQuery -> Close ();
    DataModule1 -> Edu_PlanFDQuery -> SQL -> Clear ();
    DataModule1 -> Edu_PlanFDQuery -> SQL -> Add
        ("SELECT Edu_plan.*, object_PLAN.name_object||' '||Edu_plan.clock_plan_all||'ч' as name_plan, object_PLAN.name_object FROM EDU_PLAN, object_plan WHERE N_FAC=:N_FAC and Edu_plan.n_object = object_plan.n_object AND (SEMESTR=" +
        Dop_VedForm -> Edit3 -> Text + ")");
    DataModule1 -> Edu_PlanFDQuery -> Params -> Items[0] -> AsInteger = nom_fac;
    DataModule1 -> Edu_PlanFDQuery -> Open ();

    int nom_predmet = DataModule1 -> Edu_PlanFDQuery -> Lookup ("N_PLAN",
        DataModule1 -> VedomostFDQueryN_PLAN -> Value, "N_OBJECT");
    Dop_VedForm -> ComboBox1 -> Text = DataModule1 -> Edu_PlanFDQueryNAME_PLAN -> Value;
    Dop_VedForm -> ComboBox2 -> ItemIndex =
        DataModule1 -> Edu_PlanFDQuery -> Lookup ("N_PLAN",
        DataModule1 -> VedomostFDQueryN_PLAN -> Value, "VID_EDU_PLAN");

    for (int i = 0; i < DataModule1 -> Edu_PlanFDQuery -> RecordCount; i++) {
        Dop_VedForm -> ComboBox1 -> Items -> Add
            (DataModule1 -> Edu_PlanFDQueryNAME_OBJECT -> Value);
        DataModule1 -> Edu_PlanFDQuery -> Next ();
    }
    DataModule1 -> Edu_PlanFDQuery -> Close ();
    DataModule1 -> Edu_PlanFDQuery -> SQL -> Clear ();
    DataModule1 -> Edu_PlanFDQuery -> SQL -> Add
        ("SELECT Edu_plan.*, object_PLAN.name_object||' '||Edu_plan.clock_plan_all||'ч' as name_plan, object_PLAN.name_object FROM EDU_PLAN, object_plan WHERE N_FAC=:N_FAC and Edu_plan.n_object = object_plan.n_object ORDER BY SEMESTR"
        );
    DataModule1 -> Edu_PlanFDQuery -> Params -> Items[0] -> AsInteger = nom_fac;
    DataModule1 -> Edu_PlanFDQuery -> Open ();
    state_query = 0;
    Dop_VedForm -> Edit7 -> Text = DataModule1 -> VedomostFDQueryFIO_EXAM -> Value;
    DataModule1 -> VedomostFDQuery -> Edit ();
    if (DataModule1 -> VedomostFDQuerySTATUS -> Value == 2) {
        Dop_VedForm -> Label3 -> Visible = false;
        Dop_VedForm -> Edit2 -> Visible = false;
    }
    Dop_VedForm -> Edit5 -> Enabled = false;
    Dop_VedForm -> Edit6 -> Enabled = false;
    Dop_VedForm -> ComboBox2 -> Enabled = false;
    Dop_VedForm -> ComboBox1 -> Enabled = false;
    Dop_VedForm -> Label6 -> Enabled = false;
    Dop_VedForm -> Panel2 -> Enabled = false;
    Dop_VedForm -> Edit3 -> Enabled = false;
    Dop_VedForm -> ShowModal ();
}

// ---------------------------------------------------------------------------

void __fastcall TVed_Form::CheckBox2Click (TObject * Sender) {
    if (CheckBox2 -> Checked) {
        RadioGroup1 -> Enabled = false;
        RadioGroup2 -> Enabled = false;
        Label8 -> Enabled = true;
        Edit3 -> Enabled = true;
        BitBtn7 -> Enabled = true;
    }
    else {
        ved_run ();
        Label8 -> Enabled = false;
        Edit3 -> Text = "";
        Edit3 -> Enabled = false;
        BitBtn7 -> Enabled = false;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TVed_Form::BitBtn7Click (TObject * Sender) {
    if (Edit3 -> Text != "")
        ved_run ();
    else
        ShowMessage ("Проверьте введен ли номер группы");
}
// ---------------------------------------------------------------------------

void __fastcall TVed_Form::SpeedButton3Click (TObject * Sender) {
    /* Dop_Ved_RaznicaForm = new TDop_Ved_RaznicaForm (this); //Создание формы Формирование ведомости для ликвидации разницы
     Dop_Ved_RaznicaForm -> Caption="Добавление новой ведомости для ликвидации разницы";
     Dop_Ved_RaznicaForm -> Height=220;
     Dop_Ved_RaznicaForm -> ShowModal (); */ }
// ---------------------------------------------------------------------------

void __fastcall TVed_Form::Edit3KeyPress (TObject * Sender, char &Key) {
    DataModule1 -> Edit_Key (Key);
    // Как сделать, чтобы в TEdit можно было вводить только числа?
}
// ---------------------------------------------------------------------------

void __fastcall TVed_Form::ApplicationEvents1Message (tagMSG & Msg,
    bool &Handled)
{ // организовать нормальную работу мышиного колесика в DBGrid

    if (DBGrid1 -> Focused () || DBGrid2 -> Focused ()) {
        if (Msg.message == WM_MOUSEWHEEL) {
            Msg.message = WM_KEYDOWN;
            Msg.lParam = 0;
            short int i = HIWORD (Msg.wParam);
            Msg.wParam = (i > 0) ? VK_UP : VK_DOWN;
            Handled = false;
        }
    }
}
// ---------------------------------------------------------------------------

void __fastcall TVed_Form::FormActivate (TObject * Sender) {
    // вызов SQL для формирования ведомостей
    ved_run ();
}

// ---------------------------------------------------------------------------
void __fastcall TVed_Form::BitBtn6Click (TObject *Sender) {
    JournalForm = new TJournalForm (this);
    JournalForm -> Show ();
}
// ---------------------------------------------------------------------------

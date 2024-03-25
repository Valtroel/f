#include <vcl.h>
#pragma hdrstop


#include "Add_UchKartUnit.h"
#include "CalendarUnit.h"
#include "DataModule.h"
#include "DM2Unit.h"


#pragma package (smart_init)
// #pragma link     "ToolEdit"
#pragma resource "*.dfm"


TAdd_UchKartForm *Add_UchKartForm;


bool add_card = false;                                                          // заносили ли запись в учебную карточку (true - внесено)
int  res_ball;                                                                  // оценка в RadioGroup1


// BitBtn1Click
// BitBtn3Click
// DateTimePicker1Change
// Edit1Click
// Edit2Exit
// Edit2KeyPress
// FormActivate
// FormClose
// RadioGroup2Click


__fastcall TAdd_UchKartForm::TAdd_UchKartForm (TComponent * Owner)
    : TForm (Owner)
{ }




void __fastcall TAdd_UchKartForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    this -> Close ();
}


void __fastcall TAdd_UchKartForm::Edit1Click (TObject *Sender) {
    // -----открытие формы календаря для ускорения выбора учебного года
    /*
    CalendarForm = new  TCalendarForm (this);
    CalendarForm -> Label2 -> Visible=false;
    CalendarForm -> ComboBox1 -> Visible=false;
    CalendarForm -> CCalendar1 -> Visible=false;

    CalendarForm -> Height=113;
    CalendarForm -> BitBtn1 -> Top=8;
    CalendarForm -> BitBtn1 -> Left=95;
    CalendarForm -> BitBtn1 -> Width=82;
    CalendarForm -> BitBtn2 -> Top=48;
    CalendarForm -> BitBtn2 -> Left=95;

    CalendarForm -> ShowModal ();
    //-------
    //Установка выбранного в календаре года в  Edit1  и автоматический пересчет
    //второго значения учебного года в  Label2
    if (calendar)
    {
    Edit1 -> Text=cal_year;
    Label2 -> Caption="-- "+AnsiString (cal_year+1);
    Add_UchKartForm -> Edit2 -> SetFocus ();
    }
    else ShowMessage ("Введите значение учебного года!");
     //-------
    */

}

void __fastcall TAdd_UchKartForm::BitBtn3Click (TObject *Sender) {

    // ----- проверка на допустимость значений семестра
    try { // try
        if (StrToInt (Edit2 -> Text) > 12 || StrToInt (Edit2 -> Text) <= 0)
        { // if   вышли за пределы значения семестра
            ShowMessage ("Вы ввели недопустимое значение семестра!");
            Edit2 -> Text = "";
            Edit2 -> SetFocus ();
            return;
        } // end if  вышли за пределы значения семестра
        else { // else проверим на допустимость в зависимость от вида обучения
            if (StrToInt (Edit2 -> Text) > 11 && ComboBox1 -> ItemIndex == 0)
            { // if если вид обучения - дневное, то семестр не должен превышать 10
                ShowMessage (
                    "Вы ввели недопустимое значение семестра для дневного обучения!");
                Edit2 -> Text = "";
                Edit2 -> SetFocus ();
                return;
            } // end if если вид обучения - дневное, то семестр не должен превышать 10
        } // end else проверим на допустимость в зависимость от вида обучения
    } // end try
    catch (EConvertError&) { // catch   ошибка конверсия типов
        ShowMessage ("Вы ввели недопустимое значение семестра!");
        Edit2 -> Text = "";
        Edit2 -> SetFocus ();
        return;
    } // end catch ошибка конверсия типов
    // -------

    if (Edit1 -> Text == "" || ComboBox1 -> ItemIndex == -1)
    { // if если учебный годи или вид обучения пустые
        ShowMessage ("Введите значение учебного года или вида обучения!");
    } // end if  если учебный годи или вид обучения пустые
    else { // else  основной алгоритм

        DataModule1 -> Edu_PlanFDQuery -> Close ();
        DataModule1 -> Edu_PlanFDQuery -> SQL -> Clear ();
        DataModule1 -> Edu_PlanFDQuery -> SQL -> Add
            ("SELECT Edu_plan.*, object_PLAN.name_object||' '||Edu_plan.clock_plan_all||'ч' as name_plan, object_plan.name_object FROM EDU_PLAN, object_plan WHERE (N_FAC=:N_FAC) and Edu_plan.n_object = object_plan.n_object AND (YEAR_PLAN=:PLAN) AND (SEMESTR=" +
            Edit2 -> Text + ")" + " AND (VID_EDU_PLAN=" +
            AnsiString (ComboBox1 -> ItemIndex) + ")");
        DataModule1 -> Edu_PlanFDQuery -> Params -> Items[0] -> AsInteger = nom_fac;
        DataModule1 -> Edu_PlanFDQuery -> ParamByName ("PLAN") -> AsInteger =
            StrToInt (Edit1 -> Text);
        DataModule1 -> Edu_PlanFDQuery -> Open ();
        if (DataModule1 -> Edu_PlanFDQuery -> RecordCount) {
            Panel4 -> Enabled = true;
            ComboBox2 -> ItemIndex = 0;
        }
        else {
            ShowMessage ("Нет предметов по данному учебному году и семестру");
        }
    } // end else основной алгоритм
}

void __fastcall TAdd_UchKartForm::BitBtn1Click (TObject *Sender)
{ // Действия по кнопке сохранить
    res_ball = 0;
    if (RadioGroup1 -> ItemIndex == -1 || DBLookupComboBox1 -> Text == "")
    { // if  проверка на невведенные значения предмета и оценки по этому предмету
        ShowMessage (
            "Проверьте выбрали ли Вы предмет, оценку и дату экзамена (зачета)!");
    } // end if  проверка на невведенные значения предмета и оценки по этому предмету
    else { // else  основная часть
        if (!RadioGroup2 -> ItemIndex)
        { // if RadioGroup2 -> ItemIndex==0 10-ти бальная система
            switch (RadioGroup1 -> ItemIndex)
            { // switch перевод значений из RadioGroup1 -> ItemIndex  в значения для базы
            case 7:
                res_ball = 1; // зачет
                break;
            case 8:
                res_ball = 7; // освобожден
                break;
            case 9:
                res_ball = 9; // прослушан
                break;
                // остальные оценки 10-ти бальной системы начиная с 4 (для базы 14) до 10 (для базы 20)
            default:
                res_ball = (RadioGroup1 -> ItemIndex + 14);
                break;
            } // end switch
        } // end if RadioGroup2 -> ItemIndex==0 10-ти бальная система
        else { // else if RadioGroup2 -> ItemIndex==1 5-ти бальная система
            switch (RadioGroup1 -> ItemIndex)
            { // switch перевод значений из RadioGroup1 -> ItemIndex  в значения для базы
            case 0:
                res_ball = 3; // удовл.
                break;
            case 1:
                res_ball = 4; // хорошо
                break;
            case 2:
                res_ball = 5; // отлично
                break;
            case 3:
                res_ball = 1; // зачет
                break;
            case 4:
                res_ball = 7; // освобожден
                break;
            case 5:
                res_ball = 9; // прослушан
                break;
            } // end switch перевод значений из RadioGroup1 -> ItemIndex  в значения для базы
        } // end else if RadioGroup2 -> ItemIndex==1 5-ти бальная система

        // ------проверка на то, чтобы для зачета было выбрано только значение зачет или освобожден
        Variant control = DataModule1 -> Edu_PlanFDQuery -> Lookup ("N_PLAN",
            DBLookupComboBox1 -> KeyValue, "ZACH_EXAM");
        if ( ( (control == 1) && (res_ball != 1)) &&
            ( (control == 1) && (res_ball != 7)))
        { // if несоответствие выбранной оценки для зачета (ZACH_EXAM=1 это зачет)
            ShowMessage (
                "Для зачета допустимо выбрать только оценку: зачет или освобожден!");
            return;
        } // end if несоответствие выбранной оценки для зачета (ZACH_EXAM=1 это зачет)
        else {
            // control==0 это предмет без вида контроля
            if ( (control == 0) && (res_ball != 9))
            { // if несоответствие выбранной оценки для предмета без вида контроля
                ShowMessage (
                    "Для предмета без вида контроля допустимо выбрать только прослушан!");
                return;
            } // end if несоответствие выбранной оценки для предмета без вида контроля

            // control==2 это экзамен
            if ( ( (control == 2) && (res_ball != 3)) && // удовл. в 5-ти бальной
                ( (control == 2) && (res_ball != 4)) && // хор. в 5-ти бальной
                ( (control == 2) && (res_ball != 5)) && // отл. в 5-ти бальной
                ( (control == 2) && (res_ball != 7)) && // освобожден
                ( (control == 2) && (res_ball != 14)) && // 4 в 10-ти бальной
                ( (control == 2) && (res_ball != 15)) && // 5 в 10-ти бальной
                ( (control == 2) && (res_ball != 16)) && // 6 в 10-ти бальной
                ( (control == 2) && (res_ball != 17)) && // 7 в 10-ти бальной
                ( (control == 2) && (res_ball != 18)) && // 8 в 10-ти бальной
                ( (control == 2) && (res_ball != 19)) && // 9 в 10-ти бальной
                ( (control == 2) && (res_ball != 20))) // 10 в 10-ти бальной

            { // if несоответствие выбранной оценки для экзамена (ZACH_EXAM=2 это экзамен)
                ShowMessage (
                    "Для экзамена допустимо выбрать только оценку или освобожден!");
                return;
            } // end if несоответствие выбранной оценки для экзамена (ZACH_EXAM=2 это экзамен)

            // control==3 это диф.зачет
            if // ( ( (control==3) && (res_ball!=3)) && ( (control==3) && (res_ball!=4)) && ( (control==3) && (res_ball!=5)) && ( (control==3) && (res_ball!=7)))
                ( ( (control == 3) && (res_ball != 3)) && // удовл. в 5-ти бальной
                ( (control == 3) && (res_ball != 4)) && // хор. в 5-ти бальной
                ( (control == 3) && (res_ball != 5)) && // отл. в 5-ти бальной
                ( (control == 3) && (res_ball != 7)) && // освобожден
                ( (control == 3) && (res_ball != 14)) && // 4 в 10-ти бальной
                ( (control == 3) && (res_ball != 15)) && // 5 в 10-ти бальной
                ( (control == 3) && (res_ball != 16)) && // 6 в 10-ти бальной
                ( (control == 3) && (res_ball != 17)) && // 7 в 10-ти бальной
                ( (control == 3) && (res_ball != 18)) && // 8 в 10-ти бальной
                ( (control == 3) && (res_ball != 19)) && // 9 в 10-ти бальной
                ( (control == 3) && (res_ball != 20))) // 10 в 10-ти бальной

            { // if несоответствие выбранной оценки для диф. зачета (ZACH_EXAM=3 это диф. зачет)
                ShowMessage (
                    "Для диф.зачета допустимо выбрать только оценку или освобожден!");
                return;
            } // end if несоответствие выбранной оценки для диф. зачета (ZACH_EXAM=3 это диф. зачет)

        }
        // -------

        // поиск по номеру студента  и номеру учебного плана
        // TLocateOptions Opts;
        // Opts.Clear ();
        // Variant lv[2];
        // lv[0] = Variant (DataModule1 -> Spisoc_QueryNOMER -> Value);
        // lv[1] = DBLookupComboBox1 -> KeyValue;       //  N_PLAN

        // поиск по номеру студента  и номеру учебного плана
        DataModule1 -> Result_Ball_LocateFDQuery -> Close ();
        DataModule1 -> Result_Ball_LocateFDQuery -> ParamByName ("NOM") -> AsInteger =
            DataModule1 -> Spisoc_FDQueryNOMER -> Value;
        DataModule1 -> Result_Ball_LocateFDQuery -> ParamByName ("PLAN") -> AsInteger =
            DBLookupComboBox1 -> KeyValue; // N_PLAN
        DataModule1 -> Result_Ball_LocateFDQuery -> Open ();

        // DataModule1 -> Result_BallQuery -> Close ();
        // DataModule1 -> Result_BallQuery -> ParamByName ("NOM") -> AsInteger=DataModule1 -> Spisoc_QueryNOMER -> Value;
        // DataModule1 -> Result_BallQuery -> Open ();

        // if (DataModule1 -> Result_BallQuery -> Locate ("NOMER;N_PLAN", VarArrayOf (lv, 1), Opts))
        if (DataModule1 -> Result_Ball_LocateFDQuery -> RecordCount)
        { // если найдена запись для данного студента по этому учебному плану
            DataModule1 -> Result_Ball_LocateFDQuery -> Edit ();
        } // end if
        else { // если такой записи не найдено, то нужно перейти в режим вставки и ее добавить
            DataModule1 -> Result_Ball_LocateFDQuery -> Insert ();
            DataModule1 -> Result_Ball_LocateFDQueryNOMER -> Value =
                DataModule1 -> Spisoc_FDQueryNOMER -> Value;
            DataModule1 -> Result_Ball_LocateFDQueryN_PLAN -> Value =
                DBLookupComboBox1 -> KeyValue;
        } // end else
        // --------продолжение записи значений в  Result_BallQuery

        DataModule1 -> Result_Ball_LocateFDQueryRESULT -> Value = res_ball;
        DateTimePicker1 -> Time = StrToTime ("00:00");
        DataModule1 -> Result_Ball_LocateFDQueryDATE_RESULT -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);
        DataModule1 -> Result_Ball_LocateFDQuerySTATUS_RESULT -> Value =
            ComboBox2 -> ItemIndex + 1;

        // ------ Проверка в правильности занесенных данных по MessageBox
        AnsiString box_res = "Сохранение студент: " +
            DataModule1 -> Spisoc_FDQueryFAM -> Value + " " +
            DataModule1 -> Spisoc_FDQueryNAME -> Value + " " +
            DataModule1 -> Spisoc_FDQueryOTCH -> Value + " по предмету " +
            AnsiString (DBLookupComboBox1 -> Text) + " Оценка: " +
            RadioGroup1 -> Items -> Strings[RadioGroup1 -> ItemIndex];
        // !!!if (Application -> MessageBox (box_res.c_str (),"Сохранить данные ?", MB_YESNO)== IDYES)
        if (MessageDlg (box_res.c_str (), mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
        { // Сохранение выбранной записи

            DataModule1 -> Result_Ball_LocateFDQuery -> ApplyUpdates ();
            DataModule1 -> Result_Ball_LocateFDQuery -> CommitUpdates ();
            add_card = true;
            // ---
            // Text=" ";
            // DBLookupComboBox1 -> ItemIndex=-1;
            RadioGroup1 -> ItemIndex = -1;
            DateTimePicker1 -> Date = Now ();
            DateTimePicker1 -> Time = StrToTime ("00:00");
        }
        else { // Удаление выбранной записи
            DataModule1 -> Result_Ball_LocateFDQuery -> CancelUpdates ();

        }

        // -------
    } // end else  основная часть

}

void __fastcall TAdd_UchKartForm::RadioGroup2Click (TObject *Sender) {
    RadioGroup1 -> Items -> Clear ();
    if (!RadioGroup2 -> ItemIndex) // проверка на систему оценок
    { // if если система 10-ти бальная

        RadioGroup1 -> Items -> Add ("Четыре");
        RadioGroup1 -> Items -> Add ("Пять");
        RadioGroup1 -> Items -> Add ("Шесть");
        RadioGroup1 -> Items -> Add ("Семь");
        RadioGroup1 -> Items -> Add ("Восемь");
        RadioGroup1 -> Items -> Add ("Девять");
        RadioGroup1 -> Items -> Add ("Десять");
        RadioGroup1 -> Items -> Add ("Зачет");
        RadioGroup1 -> Items -> Add ("Освобожден");
        RadioGroup1 -> Items -> Add ("Прослушан");

    } // end if если система 10-ти бальная
    else { // else если система 5-ти бальная

        RadioGroup1 -> Items -> Add ("Удовл.");
        RadioGroup1 -> Items -> Add ("Хорошо");
        RadioGroup1 -> Items -> Add ("Отлично");
        RadioGroup1 -> Items -> Add ("Зачет");
        RadioGroup1 -> Items -> Add ("Освобожден");
        RadioGroup1 -> Items -> Add ("Прослушан");

    } // end else если система 5-ти бальная
}

void __fastcall TAdd_UchKartForm::Edit2Exit (TObject *Sender) {
    if (Edit2 -> Text != "") {
        try {
            Edit1 -> Text =
                AnsiString (Mas_God_Semestr
                (DataModule1 -> Spisoc_FDQueryKURS -> Value, StrToInt (Edit2 -> Text),
                uch_god));
            Label2 -> Caption = "-- " + AnsiString (Edit1 -> Text.ToInt () + 1);
        }
        catch (...) {
            ShowMessage ("Значение семестра должно быть числовым!");
            return;
        }

    }
}

void __fastcall TAdd_UchKartForm::FormActivate (TObject *Sender) {
    ComboBox1 -> ItemIndex = DataModule1 -> Spisoc_FDQueryVID_EDU -> Value;
    Edit2 -> SetFocus ();
    DateTimePicker1 -> Date = Now ();
    DateTimePicker1 -> Time = StrToTime ("00:00");
}

void __fastcall TAdd_UchKartForm::Edit2KeyPress (TObject *Sender, char &Key) {
    DataModule1 -> Edit_Key (Key);
    // Как сделать, чтобы в TEdit можно было вводить только числа?
}
void __fastcall TAdd_UchKartForm::DateTimePicker1Change (TObject *Sender)
{
   DateTimePicker1 -> Time = StrToTime ("00:00");
}


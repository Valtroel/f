#include <vcl.h>
#pragma hdrstop


#include "CalendarUnit.h"
#include "DataModule.h"
#include "DM2Unit.h"
#include "Dop_Ved_RaznicaUnit.h"
#include "Ved_LikvidUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TDop_Ved_RaznicaForm *Dop_Ved_RaznicaForm;


int * mas_nom_plan_raznica[1];                                                  // массив номеров предметов в учебном плане

int   h = 27;





// BitBtn1Click
// BitBtn2Click
// DBLookupComboBox1CloseUp
// Edit1Click
// Edit2Click
// Edit3Exit
// Edit3KeyPress
// Edit5Exit
// FormClose
// FormShow
// max_ved_likvid
// Panel5Click








int __fastcall TDop_Ved_RaznicaForm::max_ved_likvid (int god_real)
    // Функция, которая возвращает максимальный номер ведомости
{
    DataModule1 -> Max_N_Ved_LikvidFDQuery -> Close ();
    DataModule1 -> Max_N_Ved_LikvidFDQuery -> ParamByName ("N_FAC") -> AsSmallInt =
        nom_fac;
    DataModule1 -> Max_N_Ved_LikvidFDQuery -> ParamByName ("YEAR") -> AsSmallInt =
        god_real;
    DataModule1 -> Max_N_Ved_LikvidFDQuery -> Open ();
    return DataModule1 -> Max_N_Ved_LikvidFDQueryMAX -> Value + 1;
}

__fastcall TDop_Ved_RaznicaForm::TDop_Ved_RaznicaForm (TComponent* Owner)
    : TForm (Owner) {
}

void __fastcall TDop_Ved_RaznicaForm::FormClose (TObject *Sender,
    TCloseAction &Action) {

    // массив номеров и названий предметов в учебном плане
    for (int i = 0; i < 1; i++)
        delete[]mas_nom_plan_raznica[i];
    // delete[] mas_nom_plan_raznica;

    Action = caFree;
}

void __fastcall TDop_Ved_RaznicaForm::Edit1Click (TObject *Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> ShowModal ();
    if (calendar)
        Edit1 -> Text = cal_date;
}

void __fastcall TDop_Ved_RaznicaForm::Edit2Click (TObject *Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> ShowModal ();
    if (calendar)
        Edit2 -> Text = cal_date;
}

void __fastcall TDop_Ved_RaznicaForm::Panel5Click (TObject *Sender)
{ // Выбрать предмет
    try { // try
        if (Edit5 -> Text != "" && Edit3 -> Text != "" && Edit1 -> Text != "" &&
            ComboBox2 -> ItemIndex != -1) { // if Ввод данных по параметрам

            Panel4 -> Visible = true;
            Panel3 -> Visible = true;

            Dop_Ved_RaznicaForm -> Height = 447;
            // Panel1 -> Height+Panel2 -> Height+Panel3 -> Height+Panel4 -> Height+h;//размер формы
            Dop_Ved_RaznicaForm -> Top = 100;
            // TPosition ppp=poScreenCenter;
            // Dop_Ved_RaznicaForm -> Position=ppp;

            ComboBox1 -> Enabled = true;
            Label6 -> Enabled = true;
            ComboBox1 -> Items -> Clear ();

            // ------НОВЫЙ КУСОК

            DataModule1 -> Edu_PlanFDQ -> Close ();
            DataModule1 -> Edu_PlanFDQ -> ParamByName ("N_FAC") -> AsSmallInt =
                nom_fac;
            DataModule1 -> Edu_PlanFDQ -> ParamByName ("PLAN") -> AsInteger =
                StrToInt (Edit5 -> Text);
            DataModule1 -> Edu_PlanFDQ -> ParamByName ("SEM") -> AsSmallInt =
                StrToInt (Edit3 -> Text);
            if (ComboBox2 -> Text == "Дневное")
                DataModule1 -> Edu_PlanFDQ -> ParamByName ("VID") -> AsSmallInt = 0;
            if (ComboBox2 -> Text == "Заочное")
                DataModule1 -> Edu_PlanFDQ -> ParamByName ("VID") -> AsSmallInt = 1;

            DataModule1 -> Edu_PlanFDQ -> Open ();

            DataModule1 -> Edu_PlanFDQ -> Last ();
            // переходим на последнюю т.к. не считался RecordCount ??????
            int col_plan = DataModule1 -> Edu_PlanFDQ -> RecordCount;

            // массив номеров и названий предметов в учебном плане
            for (int i = 0; i < 1; i++)
                mas_nom_plan_raznica[i] = new int[col_plan];

            for (int i = 0; i < col_plan; i++) {
                mas_nom_plan_raznica[0][i] =
                    DataModule1 -> Edu_PlanFDQN_PLAN -> Value;
                // номер в учебном плане N_PLAN

                AnsiString z = "";
                switch (DataModule1 -> Edu_PlanFDQZACH_EXAM -> Value) {
                case 0:
                    z = " (нет контроля)";
                    break;
                case 1:
                    z = " (зач.)";
                    break;
                case 2:
                    z = " (экз.)";
                    break;
                case 3:
                    z = " (диф.зач.)";
                    break;
                case 4:
                    z = " (ГОС-экзамен)";
                    break;
                }
                ComboBox1 -> Items -> Add (DataModule1 -> Edu_PlanFDQPP -> Value + z);
                // текст предмета + часы

                // ComboBox1 -> Items -> Add (DataModule1 -> Edu_PlanQPP -> Value);  //текст предмета + часы
                DataModule1 -> Edu_PlanFDQ -> Prior ();
            }

            ComboBox1 -> Style = Stdctrls::csDropDownList;
            // предлагаем номер ведомости за выбранный учебный год
            // Label11 -> Caption=AnsiString (Ved_Form -> max_ved (StrToInt (Edit5 -> Text)));

        } // end if Ввод данных по параметрам
        else { // else  Введены не все данные
            ShowMessage ("Проверьте правильность введенных данных!");
        } // end else  Введены не все данные
    } // end try
    catch (...) { // catch
        ShowMessage ("Проверьте правильность введенных данных!");
    } // end catch
}

void __fastcall TDop_Ved_RaznicaForm::BitBtn2Click (TObject *Sender)
{ // Действие по кнопке сохранить ведомость для ликвидации разницы

    // int plan_year;//переменная для учебного года
    int semestr; // переменная для семестра
    int dat = 0; // дата выдачи ведомости
    int kurs; // переменная для  курса

    // Проверки на заполненность полей
    // ------
    if (DBLookupComboBox1 -> Text == "") { // if фамилия
        ShowMessage ("Выберите фамилию студента!");
        return;
    } // end if фамилия
    // ------
    if (ComboBox2 -> ItemIndex == -1) { // if  Вид обучения
        ShowMessage ("Выберите вид обучения!");
        return;
    } // end if Вид обучения
    // ------
    if (Edit5 -> Text == "") { // if Учебный год
        ShowMessage ("Введите учебный год!");
        return;
    } // end if Учебный год
    // ------
    /* try
     {//try переводим текст в число
     plan_year=StrToInt (Edit5 -> Text);
     }//end try переводим текст в число
     catch (...)
     {//catch Проверка на цифровое значение
     ShowMessage ("Учебный год должен быть числовым значением!");
     return;
     }//end catch Проверка на цифровое значение */
    // ------
    if (Edit3 -> Text == "") { // if Семестр
        ShowMessage ("Введите семестр!");
        return;
    } // end if Семестр
    // ------
    try { // try переводим текст в число

        semestr = StrToInt (Edit3 -> Text);
        // ---проверка на дневное обучение
        if ( (semestr < 1 || semestr > 10) && ComboBox2 -> ItemIndex == 0)
        { // if для дневного значение семестра должно быть в диапазоне от 1 до 10
            ShowMessage ("Семестр должен быть в диапазоне от 1 до 10!");
            return;
        } // end if для дневного значение семестра должно быть в диапазоне от 1 до 10

        // ---проверка на заочное обучение
        if ( (semestr < 1 || semestr > 12) && ComboBox2 -> ItemIndex == 1)
        { // if для заочного значение семестра должно быть в диапазоне от 1 до 12
            ShowMessage ("Семестр должен быть в диапазоне от 1 до 12!");
            return;
        } // end if для заочного значение семестра должно быть в диапазоне от 1 до 12

    } // end try переводим текст в число
    catch (...) { // catch Проверка на цифровое значение
        ShowMessage ("Семестр должен быть числовым значением!");
        return;
    } // end catch Проверка на цифровое значение

    // ------
    if (Edit1 -> Text == "") { // if  дата выдачи ведомости
        ShowMessage ("Введите дату выдачи ведомости!");
        return;
    } // end if  дата выдачи ведомости

    // ------
    // ведомость действительна до ????? числа
    if (Edit2 -> Text == "")
    { // if если не указано конкретное число, то для экзаменационного листа надо добавить + 10 дней
        // переводим текст в дату а дату в Int
        dat = int (StrToDate (Edit1 -> Text));
        // добавляем + 10 дней
        dat += 10;
    } // end if если не указано конкретное число, то для экзаменационного листа надо добавить + 10 дней
    else
        dat = int (StrToDate (Edit2 -> Text));
    // ------
    if (Edit7 -> Text == "") { // if Экзаменатор
        ShowMessage ("Введите Фамилию экзаменатора!");
        return;
    } // end if Экзаменатор

    // ------
    if (ComboBox1 -> Text == "") { // if Предмет
        ShowMessage ("Выберите дисциплину!");
        return;
    } // end if Предмет
    // ------
    if (Edit8 -> Text == "") { // if  Курс
        ShowMessage ("Введите на какой курс ликвидация разницы!");
        return;
    } // end if Курс
    // ------
    try { // try переводим текст в число
        kurs = StrToInt (Edit8 -> Text);
    } // end try переводим текст в число
    catch (...) { // catch Проверка на цифровое значение
        ShowMessage ("Курс ликвидации разницы должен быть числовым значением!");
        return;
    } // end catch Проверка на цифровое значение
    // ------
    // ---Основной блок сохранения ведомости для ликвидации разницы
    try { // try сохраняем
        if (DataModule1 -> Ved_RaznicaFDQuery -> State == dsInactive)
            DataModule1 -> Ved_RaznicaFDQuery -> Open ();

        DataModule1 -> Ved_RaznicaFDQuery -> Insert ();

        DataModule1 -> Ved_RaznicaFDQueryN_VEDOMOST -> Value =
            StrToInt (Label11 -> Caption); // номер ведомости
        DataModule1 -> Ved_RaznicaFDQueryD_VED -> Value =
            StrToSQLTimeStamp (Edit1 -> Text);
        DataModule1 -> Ved_RaznicaFDQuerySEMESTR_VED -> Value = Edit3 -> Text.ToInt ();
        DataModule1 -> Ved_RaznicaFDQueryFIO_EXAM -> Value = Edit7 -> Text;
        DataModule1 -> Ved_RaznicaFDQuerySTATUS -> Value = 4; // ликвидация разницы
        DataModule1 -> Ved_RaznicaFDQueryN_PLAN -> Value =
            mas_nom_plan_raznica[0][ComboBox1 -> ItemIndex];
        DataModule1 -> Ved_RaznicaFDQueryN_FAC -> Value = nom_fac;

        DataModule1 -> Ved_RaznicaFDQueryEND_D_EXAM -> Value =
            StrToSQLTimeStamp (Edit2 -> Text);

        DataModule1 -> Ved_RaznicaFDQueryNOMER -> Value =
            DBLookupComboBox1 -> KeyValue;
        DataModule1 -> Ved_RaznicaFDQuerySTATUS_NOMER -> Value =
            DataModule1 -> Ved_Raznica_People_CaseFDQuerySTATUS_NOMER -> Value;
        DataModule1 -> Ved_RaznicaFDQueryYEAR_UCH -> Value =
            DataModule1 -> Ved_Raznica_People_CaseFDQueryYEAR_UCH -> Value;
        DataModule1 -> Ved_RaznicaFDQueryKURS -> Value = kurs;

        if (DataModule1 -> Ved_RaznicaFDQueryN_VEDOMOST -> Value != max_ved_likvid
            (uch_god)) {
            DataModule1 -> Ved_RaznicaFDQueryN_VEDOMOST -> Value =
                max_ved_likvid (uch_god);
            ShowMessage ("Номер вашей ведомости изменился на " +
                AnsiString (DataModule1 -> Ved_RaznicaFDQueryN_VEDOMOST -> Value));
        }

        DataModule1 -> Ved_RaznicaFDQuery -> ApplyUpdates ();
        DataModule1 -> Ved_RaznicaFDQuery -> CommitUpdates ();
        DataModule1 -> FDConnection1 -> Commit ();
        Dop_Ved_RaznicaForm -> ModalResult = 1;
    } // end try сохраняем
    catch (...) { // catch произошел сбой при сохранении
        DataModule1 -> Ved_RaznicaFDQuery -> CancelUpdates ();
        ShowMessage ("Произошел сбой при сохранении. Попробуйте еще раз!");
        Dop_Ved_RaznicaForm -> ModalResult = 0;
    } // end catch произошел сбой при сохранении

    // вызов SQL для формирования ведомостей
    if (Dop_Ved_RaznicaForm -> ModalResult)
        Ved_LikvidForm -> ved_run_L ();

}

void __fastcall TDop_Ved_RaznicaForm::DBLookupComboBox1CloseUp (TObject *Sender)
{

    Label11 -> Caption = AnsiString (max_ved_likvid (uch_god));
    Dop_Ved_RaznicaForm -> Height = Panel1 -> Height + Panel2 -> Height + h;
    // размер формы сокращенный
    // ----
    Panel2 -> Visible = true;
    ComboBox2 -> Clear ();
    // Вид обучения
    if (DataModule1 -> Ved_Raznica_People_CaseFDQueryVID_EDU_PO -> Value)
        ComboBox2 -> Items -> Add ("Заочное");
    else
        ComboBox2 -> Items -> Add ("Дневное");
    ComboBox2 -> ItemIndex = 0;

    // Курс ликвидации разницы
    Edit8 -> Text =
        IntToStr (DataModule1 -> Ved_Raznica_People_CaseFDQueryKURS_PO -> Value);
    Edit8 -> Enabled = false;

    DBLookupComboBox1 -> Enabled = false;
    Edit3 -> SetFocus ();
}

void __fastcall TDop_Ved_RaznicaForm::FormShow (TObject *Sender) {
    Dop_Ved_RaznicaForm -> Height = Panel1 -> Height + h;

}

void __fastcall TDop_Ved_RaznicaForm::BitBtn1Click (TObject *Sender) {
    // вызов SQL для формирования ведомостей
    Ved_LikvidForm -> ved_run_L ();
}

void __fastcall TDop_Ved_RaznicaForm::Edit3Exit (TObject *Sender) {
    Edit5 -> Text = AnsiString (Mas_God_Semestr (StrToInt (Edit8 -> Text),
        StrToInt (Edit3 -> Text), uch_god));
}

void __fastcall TDop_Ved_RaznicaForm::Edit5Exit (TObject *Sender) {
    Edit6 -> Text = AnsiString (Edit5 -> Text.ToInt () + 1);
}

void __fastcall TDop_Ved_RaznicaForm::Edit3KeyPress (TObject *Sender, char &Key)
{
    DataModule1 -> Edit_Key (Key);
    // Как сделать, чтобы в TEdit можно было вводить только числа?
}

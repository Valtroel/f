#include <vcl.h>
#pragma hdrstop


#include "DataModule.h"
#include "DialogPassUnit.h"
#include "DM2Unit.h"
#include "PassUnit.h"
#include "StatisticUnit.h"
// #include <vcl/dstring.h>


#pragma package (smart_init)
#pragma link     "ccalendr"
#pragma link     "CCALENDR"
#pragma resource "*.dfm"


TPassForm * PassForm;


int nom_rows; // номер строки при занесении данных по пропускам в StringGrid




// BitBtn1Click
// BitBtn2Click
// CCalendar1DblClick
// ComboBox1Change
// DBGrid1DblClick
// DBNavigator1Click
// Edit1Change
// FormActivate
// FormClose
// FormCreate
// pass_month
// RadioGroup1Click



__fastcall TPassForm::TPassForm (TComponent* Owner) : TForm (Owner) {
}

void __fastcall TPassForm::pass_month (AnsiString month_en, AnsiString month_rus,
    int year)
{ // функци€ дл€ заполнени€ StringGrid1 значени€ми пропусков за каждый мес€ц
    DataModule1 -> Statistic_Pass_MonthFDQuery -> Close ();
    // DataModule1 -> StatisticQuery -> SQL -> Clear ();
    // DataModule1 -> StatisticQuery -> SQL -> Add ("Select pass.n_cause, SUM ( HOUR_PASS ) from Pass where NOMER=:n and D_Pass Like :m and D_Pass like :g  group by  pass.n_cause");
    DataModule1 -> Statistic_Pass_MonthFDQuery -> ParamByName ("n") -> AsInteger =
        DataModule1 -> PeopleFDQueryNOMER -> Value;
    DataModule1 -> Statistic_Pass_MonthFDQuery -> ParamByName ("m") -> AsString =
        "%" + month_en + "%";
    DataModule1 -> Statistic_Pass_MonthFDQuery -> ParamByName ("g") -> AsString =
        "%" + AnsiString (year) + "%";
    DataModule1 -> Statistic_Pass_MonthFDQuery -> Open ();
    if (!DataModule1 -> Statistic_Pass_MonthFDQuery -> RecordCount)
    { // if проверка на наличие записей
        nom_rows++;
        StringGrid1 -> Cells[0][nom_rows] = month_rus;
        StringGrid1 -> Cells[1][nom_rows] = "";
        StringGrid1 -> Cells[2][nom_rows] = "";
    } // end if проверка на наличие записей
    else { // else если записи есть, то организуем цикл по причинам
        for (int i = 0;
        i < DataModule1 -> Statistic_Pass_MonthFDQuery -> RecordCount; i++)
        { // for цикл по значени€м
            nom_rows++;
            StringGrid1 -> Cells[0][nom_rows] = month_rus;
            StringGrid1 -> Cells[1][nom_rows] =
                VarToStr (DM2 -> Cause_PassFDTable -> Lookup ("N_CAUSE",
                DataModule1 -> Statistic_Pass_MonthFDQueryN_CAUSE -> Value,
                "CAUSE"));
            StringGrid1 -> Cells[2][nom_rows] =
                AnsiString (DataModule1 -> Statistic_Pass_MonthFDQuerySUM -> Value);
            DataModule1 -> Statistic_Pass_MonthFDQuery -> Next ();
        } // end for цикл по значени€м
    } // end else  если записи есть, то организуем цикл по причинам
} // end функции

void __fastcall TPassForm::UpDown1Click (TObject *Sender, TUDBtnType Button) {
    // »зменение значени€ года при помощи компонента UpDown
    // и установка фокуса на поле √од
    switch (Button) {
    case Comctrls::btNext:
        CCalendar1 -> NextYear ();
        break;
    case Comctrls::btPrev:
        CCalendar1 -> PrevYear ();
        break;
    }
    CCalendar1 -> Year = Edit1 -> Text.ToInt ();
    Edit1 -> SetFocus ();
}

void __fastcall TPassForm::FormCreate (TObject *Sender) {
    // ”становка текущей даты в календарь
    UpDown1 -> Position = CCalendar1 -> Year;
    Edit1 -> Text = CCalendar1 -> Year;
    ComboBox1 -> ItemIndex = CCalendar1 -> Month - 1;
}

void __fastcall TPassForm::ComboBox1Change (TObject *Sender) {
    // ”становка мес€ца в календаре
    if (CCalendar1 -> Month != ComboBox1 -> ItemIndex + 1) {
        CCalendar1 -> Day = 1;
        CCalendar1 -> Month = ComboBox1 -> ItemIndex + 1;
    }
}

void __fastcall TPassForm::Edit1Change (TObject *Sender) {
    try {
        if (Edit1 -> Text != "")
            CCalendar1 -> Year = Edit1 -> Text.ToInt ();
    }
    catch (...) {
        MessageBox (0, "Ќеверно задано значение года", "ќшибка!!!", MB_OK);
    }

}

void __fastcall TPassForm::CCalendar1DblClick (TObject *Sender) {
    Set<TLocateOption, 0, 1>flags;
    bool found = DataModule1 -> PassFDQuery -> Locate ("D_PASS",
        CCalendar1 -> CalendarDate, flags);
    if (found == false) {
        DataModule1 -> PassFDQuery -> Insert ();
        // DataModule1 -> PassQueryNOMER -> Value=DataModule1 -> PeopleQueryNOMER -> Value;
        // DataModule1 -> PassQueryD_PASS -> Value=PassForm -> CCalendar1 -> CalendarDate;

    }
    DialogPass = new TDialogPass (this);
    DialogPass -> ShowModal ();
}

void __fastcall TPassForm::FormActivate (TObject *Sender) {
    DataModule1 -> PassFDQuery -> Close ();
    DataModule1 -> PassFDQuery -> Params -> Items[0] -> AsInteger =
        DataModule1 -> PeopleFDQueryNOMER -> Value;
    DataModule1 -> PassFDQuery -> Open ();
}

void __fastcall TPassForm::BitBtn1Click (TObject *Sender) {
    if (DataModule1 -> PassFDQuery -> RecordCount != 0) {
        if (MessageBox (0, "”далить выбранные данные по пропускам?", "",
            MB_YESNO + MB_TASKMODAL) == IDYES) {
            DataModule1 -> PassFDQuery -> Delete ();
            DataModule1 -> PassFDQuery -> ApplyUpdates ();
            DataModule1 -> PassFDQuery -> CommitUpdates ();
        }
    }
    else
        MessageBox (0, "Ќет сведений по пропускам!",
        "”даление невозможно", MB_OK);
}

void __fastcall TPassForm::BitBtn2Click (TObject *Sender) {
    StatisticForm = new TStatisticForm (this);
    StatisticForm -> ShowModal ();
}

void __fastcall TPassForm::DBNavigator1Click (TObject *Sender,
    TNavigateBtn Button) {
    DataModule1 -> PassFDQuery -> Close ();
    DataModule1 -> PassFDQuery -> Params -> Items[0] -> AsInteger =
        DataModule1 -> PeopleFDQueryNOMER -> Value;
    DataModule1 -> PassFDQuery -> Open ();
    RadioGroup1Click (this);
}

void __fastcall TPassForm::FormClose (TObject *Sender, TCloseAction &Action) {
    Action = caFree;
}

void __fastcall TPassForm::RadioGroup1Click (TObject *Sender)
{ // выбор типов пропусков
    nom_rows = 0; // обнул€ем переменную номера строки в StringGrid1

    switch (RadioGroup1 -> ItemIndex) {
    case -1: // выключены все кнопки
        CCalendar1 -> Visible = false;

        // PassForm -> Width=262; //уменьшаем форму
        DBGrid1 -> Visible = false; // пропуски за каждый день
        StringGrid1 -> Visible = false; // пропуски за мес€ц

        Label2 -> Visible = false; // метка год
        Edit1 -> Visible = false; // год
        UpDown1 -> Visible = false; // компонент изменени€ года
        Label1 -> Visible = false; // метка мес€ц
        ComboBox1 -> Visible = false; // список мес€цев

        break;
    case 0: // включен тип пропусков за мес€ц
        CCalendar1 -> Visible = false;
        if (PassForm -> Width != 587) {
            PassForm -> Width = 587; // расшир€ем форму
            PassForm -> Position = poScreenCenter;
        }
        DBGrid1 -> Visible = false; // пропуски за каждый день

        Label2 -> Visible = false; // метка год
        Edit1 -> Visible = false; // год
        UpDown1 -> Visible = false; // компонент изменени€ года
        Label1 -> Visible = false; // метка мес€ц
        ComboBox1 -> Visible = false; // список мес€цев

        StringGrid1 -> Visible = true; // пропуски за мес€ц
        StringGrid1 -> Cells[1][0] = "ѕричина пропусков";
        StringGrid1 -> Cells[2][0] = " оличество";

        pass_month ("SEP", "—ент€брь", uch_god);
        pass_month ("OCT", "ќкт€брь", uch_god);
        pass_month ("NOV", "Ќо€брь", uch_god);
        pass_month ("DEC", "ƒекабрь", uch_god);
        pass_month ("JAN", "январь", uch_god + 1);
        pass_month ("FEB", "‘евраль", uch_god + 1);
        pass_month ("MAR", "ћарт", uch_god + 1);
        pass_month ("APR", "јпрель", uch_god + 1);
        pass_month ("MAY", "ћай", uch_god + 1);
        pass_month ("JUN", "»юнь", uch_god + 1);
        pass_month ("JUL", "»юль", uch_god + 1);

        StringGrid1 -> RowCount = nom_rows + 1;
        // ”станавливаем кол-во строк в Grid'е
        break;
    case 1: // включен тип пропусков за каждый день
        CCalendar1 -> Visible = true;
        if (PassForm -> Width != 587) {
            PassForm -> Width = 587; // расшир€ем форму
            PassForm -> Position = poScreenCenter;
        }
        DBGrid1 -> Visible = true; // пропуски за каждый день
        StringGrid1 -> Visible = false; // пропуски за мес€ц

        Label2 -> Visible = true; // метка год
        Edit1 -> Visible = true; // год
        UpDown1 -> Visible = true; // компонент изменени€ года
        Label1 -> Visible = true; // метка мес€ц
        ComboBox1 -> Visible = true; // список мес€цев

        break;
    }
}

void __fastcall TPassForm::DBGrid1DblClick (TObject *Sender) {
    DialogPass = new TDialogPass (this);
    DialogPass -> DBLookupComboBox1 -> KeyValue =
        DataModule1 -> PassFDQueryN_CAUSE -> Value;
    DialogPass -> Edit1 -> Text = DataModule1 -> PassFDQueryHOUR_PASS -> Value;
    DialogPass -> OKBtn -> Visible = true;
    DialogPass -> ShowModal ();
}

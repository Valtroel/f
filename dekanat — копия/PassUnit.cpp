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


int nom_rows; // ����� ������ ��� ��������� ������ �� ��������� � StringGrid




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
{ // ������� ��� ���������� StringGrid1 ���������� ��������� �� ������ �����
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
    { // if �������� �� ������� �������
        nom_rows++;
        StringGrid1 -> Cells[0][nom_rows] = month_rus;
        StringGrid1 -> Cells[1][nom_rows] = "";
        StringGrid1 -> Cells[2][nom_rows] = "";
    } // end if �������� �� ������� �������
    else { // else ���� ������ ����, �� ���������� ���� �� ��������
        for (int i = 0;
        i < DataModule1 -> Statistic_Pass_MonthFDQuery -> RecordCount; i++)
        { // for ���� �� ���������
            nom_rows++;
            StringGrid1 -> Cells[0][nom_rows] = month_rus;
            StringGrid1 -> Cells[1][nom_rows] =
                VarToStr (DM2 -> Cause_PassFDTable -> Lookup ("N_CAUSE",
                DataModule1 -> Statistic_Pass_MonthFDQueryN_CAUSE -> Value,
                "CAUSE"));
            StringGrid1 -> Cells[2][nom_rows] =
                AnsiString (DataModule1 -> Statistic_Pass_MonthFDQuerySUM -> Value);
            DataModule1 -> Statistic_Pass_MonthFDQuery -> Next ();
        } // end for ���� �� ���������
    } // end else  ���� ������ ����, �� ���������� ���� �� ��������
} // end �������

void __fastcall TPassForm::UpDown1Click (TObject *Sender, TUDBtnType Button) {
    // ��������� �������� ���� ��� ������ ���������� UpDown
    // � ��������� ������ �� ���� ���
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
    // ��������� ������� ���� � ���������
    UpDown1 -> Position = CCalendar1 -> Year;
    Edit1 -> Text = CCalendar1 -> Year;
    ComboBox1 -> ItemIndex = CCalendar1 -> Month - 1;
}

void __fastcall TPassForm::ComboBox1Change (TObject *Sender) {
    // ��������� ������ � ���������
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
        MessageBox (0, "������� ������ �������� ����", "������!!!", MB_OK);
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
        if (MessageBox (0, "������� ��������� ������ �� ���������?", "",
            MB_YESNO + MB_TASKMODAL) == IDYES) {
            DataModule1 -> PassFDQuery -> Delete ();
            DataModule1 -> PassFDQuery -> ApplyUpdates ();
            DataModule1 -> PassFDQuery -> CommitUpdates ();
        }
    }
    else
        MessageBox (0, "��� �������� �� ���������!",
        "�������� ����������", MB_OK);
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
{ // ����� ����� ���������
    nom_rows = 0; // �������� ���������� ������ ������ � StringGrid1

    switch (RadioGroup1 -> ItemIndex) {
    case -1: // ��������� ��� ������
        CCalendar1 -> Visible = false;

        // PassForm -> Width=262; //��������� �����
        DBGrid1 -> Visible = false; // �������� �� ������ ����
        StringGrid1 -> Visible = false; // �������� �� �����

        Label2 -> Visible = false; // ����� ���
        Edit1 -> Visible = false; // ���
        UpDown1 -> Visible = false; // ��������� ��������� ����
        Label1 -> Visible = false; // ����� �����
        ComboBox1 -> Visible = false; // ������ �������

        break;
    case 0: // ������� ��� ��������� �� �����
        CCalendar1 -> Visible = false;
        if (PassForm -> Width != 587) {
            PassForm -> Width = 587; // ��������� �����
            PassForm -> Position = poScreenCenter;
        }
        DBGrid1 -> Visible = false; // �������� �� ������ ����

        Label2 -> Visible = false; // ����� ���
        Edit1 -> Visible = false; // ���
        UpDown1 -> Visible = false; // ��������� ��������� ����
        Label1 -> Visible = false; // ����� �����
        ComboBox1 -> Visible = false; // ������ �������

        StringGrid1 -> Visible = true; // �������� �� �����
        StringGrid1 -> Cells[1][0] = "������� ���������";
        StringGrid1 -> Cells[2][0] = "����������";

        pass_month ("SEP", "��������", uch_god);
        pass_month ("OCT", "�������", uch_god);
        pass_month ("NOV", "������", uch_god);
        pass_month ("DEC", "�������", uch_god);
        pass_month ("JAN", "������", uch_god + 1);
        pass_month ("FEB", "�������", uch_god + 1);
        pass_month ("MAR", "����", uch_god + 1);
        pass_month ("APR", "������", uch_god + 1);
        pass_month ("MAY", "���", uch_god + 1);
        pass_month ("JUN", "����", uch_god + 1);
        pass_month ("JUL", "����", uch_god + 1);

        StringGrid1 -> RowCount = nom_rows + 1;
        // ������������� ���-�� ����� � Grid'�
        break;
    case 1: // ������� ��� ��������� �� ������ ����
        CCalendar1 -> Visible = true;
        if (PassForm -> Width != 587) {
            PassForm -> Width = 587; // ��������� �����
            PassForm -> Position = poScreenCenter;
        }
        DBGrid1 -> Visible = true; // �������� �� ������ ����
        StringGrid1 -> Visible = false; // �������� �� �����

        Label2 -> Visible = true; // ����� ���
        Edit1 -> Visible = true; // ���
        UpDown1 -> Visible = true; // ��������� ��������� ����
        Label1 -> Visible = true; // ����� �����
        ComboBox1 -> Visible = true; // ������ �������

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

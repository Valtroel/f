// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "CalendarUnit.h"
#include "Ved_LikvidUnit.h"
#include "DataModule.h"
#include "Dop_Ved_RaznicaUnit.h"
#include "DM2Unit.h"
#include "Dop_Ved_LikvidReportUnit.h"
#include "Ball_LikvidUnit.h"
// ---------------------------------------------------------------------------
#pragma package (smart_init)
#pragma resource "*.dfm"
TVed_LikvidForm *Ved_LikvidForm;

// ������ ��������� SQL
AnsiString sql1 = "SELECT VEDOMOST_LIKVID.N_VED, VEDOMOST_LIKVID.N_VEDOMOST, VEDOMOST_LIKVID.D_VED, \
VEDOMOST_LIKVID.SEMESTR_VED, VEDOMOST_LIKVID.FIO_EXAM, VEDOMOST_LIKVID.STATUS, \
VEDOMOST_LIKVID.N_PLAN, VEDOMOST_LIKVID.N_FAC, VEDOMOST_LIKVID.END_D_EXAM,  \
VEDOMOST_LIKVID.NOMER, VEDOMOST_LIKVID.STATUS_NOMER, VEDOMOST_LIKVID.KURS, VEDOMOST_LIKVID.YEAR_UCH, \
VEDOMOST_LIKVID.BALL, VEDOMOST_LIKVID.D_EXAM, \
PEOPLE.FAM || ' ' || PEOPLE.NAME || ' ' || PEOPLE.OTCH as FIO,  \
OBJECT_PLAN.NAME_OBJECT, EDU_PLAN.YEAR_PLAN, EDU_PLAN.VID_EDU_PLAN, EDU_PLAN.ZACH_EXAM \
FROM  VEDOMOST_LIKVID  \
INNER JOIN EDU_PLAN ON (VEDOMOST_LIKVID.N_PLAN=EDU_PLAN.N_PLAN)  \
INNER JOIN OBJECT_PLAN ON (EDU_PLAN.N_OBJECT = OBJECT_PLAN.N_OBJECT) \
INNER JOIN PEOPLE ON (VEDOMOST_LIKVID.NOMER = PEOPLE.NOMER) \
WHERE (VEDOMOST_LIKVID.N_FAC = :N_FAC) ";

// ����� ������ SQl ��� ������������ ��������� �� �������� �����
AnsiString god_plan_l = " and (EDU_PLAN.YEAR_PLAN = :YEAR) ";

// ����� ������ SQL ��� ����������
AnsiString sql3 = " order by VEDOMOST_LIKVID.N_VEDOMOST ";

// ������ ����� ��� sql �� ���� ��������
AnsiString vl[3] = {
    "", " AND (Edu_plan.VID_EDU_PLAN=0)", " AND (Edu_plan.VID_EDU_PLAN=1)"};

// ����� ������ SQl ��� ������������ ��������� �� ����
AnsiString data_vedl = "AND (Vedomost_LIKVID.D_VED BETWEEN :D1 AND :D2)";

// ����� ������ SQl ��� ������������ ��������� �� ������ ��������
AnsiString ved_stud = "AND (Vedomost_LIKVID.NOMER=:NOM) ";

TBookmark Bookmark_ved_likvid;

// ---------------------------------------------------------------------------
__fastcall TVed_LikvidForm::TVed_LikvidForm (TComponent* Owner) : TForm (Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TVed_LikvidForm::ved_run_L () // ���������� Sql �� ����������
{ // ������������ SQL �� ����������

    AnsiString full_sql = "";
    full_sql = sql1 + vl[RadioGroup2 -> ItemIndex];

    DataModule1 -> Ved_LikvidGridFDQuery -> Close ();
    DataModule1 -> Ved_LikvidGridFDQuery -> SQL -> Clear ();

    if (CheckBox1 -> Checked) // ��������� �� ������� ���:
    { // if Ch1  ������ ������� ���
        full_sql += god_plan_l;
    }

    if (CheckBox2 -> Checked) // �� ��������:
    { // if Ch2
        full_sql += ved_stud;

    } // end if Ch2

    if (CheckBox3 -> Checked) // ��������� �� ������:
    { // if Ch3  ������ ���������� ������
        full_sql += data_vedl;
    }

    if (!CheckBox1 -> Checked && !CheckBox2 -> Checked && !CheckBox3 -> Checked)
    { // if !Ch1 !Ch2  !Ch3
        full_sql = "";
        full_sql = sql1 + vl[RadioGroup2 -> ItemIndex] + data_vedl;

    }

    DataModule1 -> Ved_LikvidGridFDQuery -> SQL -> Add (full_sql + sql3);
    DataModule1 -> Ved_LikvidGridFDQuery -> Params -> Items[0] -> AsInteger = nom_fac;

    // ---���������
    if (CheckBox1 -> Checked) // ��������� �� ������� ���:
    { // if Ch1  ������ ������� ���
        DataModule1 -> Ved_LikvidGridFDQuery -> ParamByName ("YEAR") -> Value =
            Edit1 -> Text;
        Ved_LikvidForm -> Caption = "������ ���������� �� " + Edit1 -> Text +
            " ������� ���";
    } // end if Ch1
    ///-----
    if (CheckBox2 -> Checked) // �� ��������:
    { // if Ch2
        DataModule1 -> Ved_LikvidGridFDQuery -> ParamByName ("NOM") -> Value =
            DBLookupComboBox1 -> KeyValue;
        Ved_LikvidForm -> Caption = "������ ���������� c�������: " +
            DBLookupComboBox1 -> Text;
    } // end if Ch2
    // ------
    if (CheckBox3 -> Checked) // ��������� �� ������:
    { // if Ch3  ������ ���������� ������
        DataModule1 -> Ved_LikvidGridFDQuery -> ParamByName ("D1") -> AsDateTime =
            Edit2 -> Text;
        DataModule1 -> Ved_LikvidGridFDQuery -> ParamByName ("D2") -> AsDateTime =
            Edit3 -> Text;
        Ved_LikvidForm -> Caption = "������ ���������� �� ������ � " +
            Edit2 -> Text + " �� " + Edit3 -> Text;
    } // end if Ch3

    if (!CheckBox1 -> Checked && !CheckBox2 -> Checked && !CheckBox3 -> Checked)
    { // if !Ch1 !Ch2  !Ch3
        // !Ch1 ������� ��� �������
        // DataModule1 -> Ved_LikvidGridQuery -> ParamByName ("YEAR") -> Value=uch_god;

        // !Ch3 ������ �� ������
        DataModule1 -> Ved_LikvidGridFDQuery -> ParamByName ("D1") -> AsDateTime =
            curent_date - 10;
        DataModule1 -> Ved_LikvidGridFDQuery -> ParamByName ("D2") -> AsDateTime =
            curent_date + 30;
        Ved_LikvidForm -> Caption = "";
        Ved_LikvidForm -> Caption = "������ ���������� �� ������ � " +
            DateToStr (curent_date - 10) + " �� " + DateToStr (curent_date + 30);
    }

    DataModule1 -> Ved_LikvidGridFDQuery -> Open ();
    DataModule1 -> Ved_LikvidGridFDQuery -> Last ();
}

// ---------------------------------------------------------------------------
void __fastcall TVed_LikvidForm::FormClose (TObject *Sender,
    TCloseAction &Action) {
    // !!!if (Bookmark_ved_likvid) { // if ��������
    /* DataModule1 -> Ved_LikvidGridQuery -> GotoBookmark (Bookmark_ved_likvid);
     DataModule1 -> Ved_LikvidGridQuery -> FreeBookmark (Bookmark_ved_likvid); */

    DataModule1 -> Ved_LikvidGridFDQuery -> FreeBookmark (Bookmark_ved_likvid);
    // !!!    } // end if ��������

    Action = caFree;
}

// ---------------------------------------------------------------------------
void __fastcall TVed_LikvidForm::FormCreate (TObject *Sender) {
    // ������� ����
    curent_date = cur_d ();

}
// ---------------------------------------------------------------------------

void __fastcall TVed_LikvidForm::CheckBox2Click (TObject *Sender)
{ // �� ��������
    if (CheckBox2 -> Checked) { // if �������� ����� �� ��������
        DataModule1 -> Ved_Raznica_People_CaseFDQuery -> Close ();
        DataModule1 -> Ved_Raznica_People_CaseFDQuery -> SQL -> Clear ();
        DataModule1 -> Ved_Raznica_People_CaseFDQuery -> SQL -> Add ("SELECT distinct Prikaz_likvid.NOMER,  \
        People.FAM || ' ' || People.NAME || ' ' || People.OTCH as FIO, Prikaz_likvid.YEAR_UCH, \
        Prikaz_likvid.DATE_C, Prikaz_likvid.DATE_PO, Prikaz_likvid.FAC_PO, Prikaz_likvid.VID_EDU_PO, \
        Prikaz_likvid.SPECIALIZ_PO, Prikaz_likvid.KURS_PO, Prikaz_likvid.N_FOUND_PO, Prikaz_likvid.STATUS_NOMER  \
        FROM PRIKAZ_LIKVID Prikaz_likvid \
        INNER JOIN PEOPLE People  \
        ON (Prikaz_likvid.NOMER = People.NOMER)  \
        Where Prikaz_likvid.FAC_PO=:FAC and   \
        Prikaz_likvid.YEAR_UCH=:YEAR  \
        order by  People.FAM,  People.NAME, People.OTCH");
        DataModule1 -> Ved_Raznica_People_CaseFDQuery -> ParamByName ("FAC")
            -> AsSmallInt = nom_fac;
        DataModule1 -> Ved_Raznica_People_CaseFDQuery -> ParamByName ("YEAR")
            -> AsSmallInt = uch_god;
        DataModule1 -> Ved_Raznica_People_CaseFDQuery -> Open ();
        // -----
        CheckBox1 -> Enabled = false;
        CheckBox3 -> Enabled = false;
        BitBtn4 -> Enabled = false;
        BitBtn1 -> Enabled = false;
        // -----

        DBLookupComboBox1 -> Enabled = true;
        BitBtn5 -> Enabled = true;
    } // end if �������� ����� �� ��������
    else { // else ���������
        ved_run_L ();

        CheckBox1 -> Enabled = true;
        CheckBox3 -> Enabled = true;
        DBLookupComboBox1 -> KeyValue = -1;
        DBLookupComboBox1 -> Enabled = false;
        BitBtn5 -> Enabled = false;
    } // end else ���������
}
// ---------------------------------------------------------------------------

void __fastcall TVed_LikvidForm::Edit2Click (TObject *Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> ShowModal ();
    if (calendar)
        Edit2 -> Text = cal_date;
    Edit3 -> SetFocus ();
}
// ---------------------------------------------------------------------------

void __fastcall TVed_LikvidForm::Edit3Click (TObject *Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> ShowModal ();
    if (calendar)
        Edit3 -> Text = cal_date;
    BitBtn1 -> SetFocus ();
}
// ---------------------------------------------------------------------------

void __fastcall TVed_LikvidForm::CheckBox3Click (TObject *Sender) { // �� ������
    if (CheckBox3 -> Checked) { // if �������� ����� �� ������
        // -----
        CheckBox1 -> Enabled = false;
        CheckBox2 -> Enabled = false;
        BitBtn5 -> Enabled = false;
        BitBtn1 -> Enabled = false;
        // -----
        Edit2 -> Enabled = true;
        Edit3 -> Enabled = true;
        Label3 -> Enabled = true;
        Label4 -> Enabled = true;
        BitBtn1 -> Enabled = true;
    } // end if �������� ����� �� ������
    else { // else ���������
        ved_run_L ();

        CheckBox1 -> Enabled = true;
        CheckBox2 -> Enabled = true;

        Edit2 -> Text = "";
        Edit2 -> Enabled = false;
        Edit3 -> Text = "";
        Edit3 -> Enabled = false;
        Label3 -> Enabled = false;
        Label4 -> Enabled = false;
        BitBtn1 -> Enabled = false;
    } // end else ���������
}
// ---------------------------------------------------------------------------

void __fastcall TVed_LikvidForm::CheckBox1Click (TObject *Sender)
{ // �� ������� ���
    if (CheckBox1 -> Checked) { // if �������� ����� �� ������� ���
        // -----
        CheckBox2 -> Enabled = false;
        CheckBox3 -> Enabled = false;
        BitBtn5 -> Enabled = false;
        BitBtn1 -> Enabled = false;
        // -----
        Edit1 -> Enabled = true;
        BitBtn4 -> Enabled = true;
    } // end if �������� ����� �� ������� ���
    else { // else ���������
        ved_run_L ();

        CheckBox3 -> Enabled = true;
        CheckBox2 -> Enabled = true;

        Edit1 -> Text = "";
        Edit1 -> Enabled = false;

        BitBtn4 -> Enabled = false;
    } // end else ���������
}
// ---------------------------------------------------------------------------

void __fastcall TVed_LikvidForm::BitBtn1Click (TObject *Sender) {
    if ( (Edit2 -> Text != "") && (Edit3 -> Text != "")) {
        ved_run_L ();
        CheckBox1 -> Enabled = true;
        CheckBox2 -> Enabled = true;
    }
    else
        ShowMessage ("������� ���� �� ������!");
}
// ---------------------------------------------------------------------------

void __fastcall TVed_LikvidForm::BitBtn5Click (TObject *Sender) {
    if (DBLookupComboBox1 -> Text != "") {
        ved_run_L ();
        CheckBox1 -> Enabled = true;
        CheckBox3 -> Enabled = true;
    }
    else
        ShowMessage ("�������� ��� ��������!");
}
// ---------------------------------------------------------------------------

void __fastcall TVed_LikvidForm::BitBtn4Click (TObject *Sender) {
    if (Edit1 -> Text != "") {
        ved_run_L ();
        CheckBox2 -> Enabled = true;
        CheckBox3 -> Enabled = true;
    }
    else
        ShowMessage ("�������� ������� ���!");
}
// ---------------------------------------------------------------------------

void __fastcall TVed_LikvidForm::Edit1Click (TObject *Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> Label2 -> Visible = false;
    CalendarForm -> ComboBox1 -> Visible = false;
    CalendarForm -> CCalendar1 -> Visible = false;

    CalendarForm -> Height = 113;
    CalendarForm -> BitBtn1 -> Top = 8;
    CalendarForm -> BitBtn1 -> Left = 95;
    CalendarForm -> BitBtn1 -> Width = 82;
    CalendarForm -> BitBtn2 -> Top = 48;
    CalendarForm -> BitBtn2 -> Left = 95;

    CalendarForm -> ShowModal ();

    if (calendar)
        Edit1 -> Text = cal_year;

    BitBtn4 -> SetFocus ();

}
// ---------------------------------------------------------------------------

void __fastcall TVed_LikvidForm::RadioGroup2Click (TObject *Sender) {
    ved_run_L ();
}
// ---------------------------------------------------------------------------

void __fastcall TVed_LikvidForm::SpeedButton3Click (TObject *Sender) {

    DataModule1 -> Ved_Raznica_People_CaseFDQuery -> Close ();
    DataModule1 -> Ved_Raznica_People_CaseFDQuery -> SQL -> Clear ();
    DataModule1 -> Ved_Raznica_People_CaseFDQuery -> SQL -> Add ("SELECT Prikaz_likvid.NOMER, \
People.FAM || ' ' || People.NAME || ' ' || People.OTCH as FIO, Prikaz_likvid.YEAR_UCH, \
Prikaz_likvid.DATE_C, Prikaz_likvid.DATE_PO, Prikaz_likvid.FAC_PO, Prikaz_likvid.VID_EDU_PO, \
Prikaz_likvid.SPECIALIZ_PO, Prikaz_likvid.KURS_PO, Prikaz_likvid.N_FOUND_PO, Prikaz_likvid.STATUS_NOMER  \
FROM PRIKAZ_LIKVID Prikaz_likvid  \
   INNER JOIN PEOPLE People   \
   ON (Prikaz_likvid.NOMER = People.NOMER) \
Where Prikaz_likvid.FAC_PO=:FAC and  Prikaz_likvid.YEAR_UCH=:YEAR \
and (:D between Prikaz_likvid.DATE_C and Prikaz_likvid.DATE_PO) \
order by  People.FAM,  People.NAME, People.OTCH");
    DataModule1 -> Ved_Raznica_People_CaseFDQuery -> ParamByName ("FAC")
        -> AsSmallInt = nom_fac;
    DataModule1 -> Ved_Raznica_People_CaseFDQuery -> ParamByName ("YEAR")
        -> AsSmallInt = uch_god;
    DataModule1 -> Ved_Raznica_People_CaseFDQuery -> ParamByName ("D") -> AsDateTime =
        curent_date;
    DataModule1 -> Ved_Raznica_People_CaseFDQuery -> Open ();

    if (DataModule1 -> Ved_Raznica_People_CaseFDQuery -> RecordCount)
    { // if ���� �������� �� ������� �� ���������� �������
        Dop_Ved_RaznicaForm = new TDop_Ved_RaznicaForm (this);
        // �������� ����� ������������ ��������� ��� ���������� �������
        Dop_Ved_RaznicaForm -> Caption =
            "���������� ����� ��������� ��� ���������� �������";
        Dop_Ved_RaznicaForm -> ShowModal ();
    } // end if ���� �������� �� ������� �� ���������� �������
    else
        ShowMessage (
        "��� �� ������ ��������, �������� ����� ������������� �������. ��������� ������� �� ����������!");
}
// ---------------------------------------------------------------------------

void __fastcall TVed_LikvidForm::BitBtn2Click (TObject *Sender)
{ /* // ������ ������
     // �������� �� ������ Grida
     Bookmark_ved_likvid = DataModule1 -> Ved_LikvidGridFDQuery -> GetBookmark ();

     // ������������ ���������������� ����� (��� ��������� ��� ��������� �����)
     Dop_Ved_LikvidReportForm = new TDop_Ved_LikvidReportForm (this);

     // Ved_Likvid_ReportQuery
     DataModule1 -> Ved_Likvid_ReportFDQuery -> Close ();
     DataModule1 -> Ved_Likvid_ReportFDQuery -> ParamByName ("N_FAC") -> AsSmallInt =
     nom_fac;
     DataModule1 -> Ved_Likvid_ReportFDQuery -> ParamByName ("VED") -> AsInteger =
     DataModule1 -> Ved_LikvidGridFDQueryN_VED -> Value;
     DataModule1 -> Ved_Likvid_ReportFDQuery -> Open ();

     if (Dop_Ved_LikvidReportForm -> frxReport1 -> PrepareReport (true))
     Dop_Ved_LikvidReportForm -> frxReport1 -> ShowPreparedReport (); */

    Dop_Ved_LikvidReportForm = new TDop_Ved_LikvidReportForm (this);
    Dop_Ved_LikvidReportForm -> FDQuery3 -> Close ();
    Dop_Ved_LikvidReportForm -> FDQuery3 -> SQL -> Add
       (" and y.N_OBJECT = ( select first 1 y.N_OBJECT from vedomost_likvid, EDU_PLAN, OBJECT_PLAN a, SUB_EDU_PLAN y, OBJECT_PLAN b, SUB_EDU_PLAN z, OBJECT_PLAN c, PEOPLE, FACULTY where vedomost_likvid.N_PLAN = EDU_PLAN.N_PLAN and EDU_PLAN.N_PLAN = y.N_PLAN_PARENT and EDU_PLAN.N_PLAN = z.N_PLAN_PARENT and y.N_OBJECT = b.N_OBJECT and z.N_OBJECT = c.N_OBJECT and y.N_PLAN <> z.N_PLAN and vedomost_likvid.N_VED = :N_VED )"
        );
    Dop_Ved_LikvidReportForm -> FDQuery5 -> Close ();
    Dop_Ved_LikvidReportForm -> FDQuery5 -> ParamByName ("N_VED") -> AsInteger =
            DBGrid1 -> Columns -> Items[11] -> Field -> AsInteger;
    Dop_Ved_LikvidReportForm -> FDQuery5 -> Open ();
    if (Dop_Ved_LikvidReportForm -> FDQuery5COUNT -> Value) {
        Dop_Ved_LikvidReportForm -> FDQuery3 -> Close ();
        Dop_Ved_LikvidReportForm -> FDQuery3 -> ParamByName ("N_VED") -> AsInteger =
            DBGrid1 -> Columns -> Items[11] -> Field -> AsInteger;
        Dop_Ved_LikvidReportForm -> FDQuery3 -> Open ();
        if (Dop_Ved_LikvidReportForm -> frxReport3 -> PrepareReport (true))
            Dop_Ved_LikvidReportForm -> frxReport3 -> ShowPreparedReport ();
        Dop_Ved_LikvidReportForm -> FDQuery3 -> Close ();
    }
    else {
        Dop_Ved_LikvidReportForm -> FDQuery1 -> Close ();
        Dop_Ved_LikvidReportForm -> FDQuery1 -> ParamByName ("N_VED") -> AsInteger =
            DBGrid1 -> Columns -> Items[11] -> Field -> AsInteger;
        Dop_Ved_LikvidReportForm -> FDQuery1 -> Open ();
        if (Dop_Ved_LikvidReportForm -> frxReport1 -> PrepareReport (true))
            Dop_Ved_LikvidReportForm -> frxReport1 -> ShowPreparedReport ();
        Dop_Ved_LikvidReportForm -> FDQuery1 -> Close ();
    }
}

// ---------------------------------------------------------------------------

void __fastcall TVed_LikvidForm::FormActivate (TObject * Sender) {
    // ���� ���� ��������, �� ��������� �� ���
    // !!!    if (Bookmark_ved_likvid) { // if ��������
    DataModule1 -> Ved_LikvidGridFDQuery -> GotoBookmark (Bookmark_ved_likvid);
    DataModule1 -> Ved_LikvidGridFDQuery -> FreeBookmark (Bookmark_ved_likvid);
    // !!!    Bookmark_ved_likvid = NULL;
    // !!!    } // end if ��������

    ved_run_L (); // ����� SQL ��� ������������ ����������
}
// ---------------------------------------------------------------------------

void __fastcall TVed_LikvidForm::DBGrid1DblClick (TObject * Sender) {

    AnsiString box_text =
        "��� ��������� ���� ��� ��� ������������� -- ������� YES; ��� ��������� ���������� -- ������� NO.";

    // !!!int fl=Application -> MessageBox (box_text.c_str (),"�������������� ���������", MB_YESNOCANCEL);
    int fl = MessageDlg (box_text.c_str (), mtInformation,
        TMsgDlgButtons () << mbYes << mbNo << mbCancel, 0);
    if (fl == mrCancel) { // if ������ CANCEL

    } // end if ������ CANCEL
    else { // else ������ YES  ��� NO
        Ball_LikvidForm = new TBall_LikvidForm (this);
        Ball_LikvidForm -> DateTimePicker1 -> Date = Now ();
        Ball_LikvidForm -> DateTimePicker1 -> Time = StrToTime ("00:00");
        Ball_LikvidForm -> DateTimePicker2 -> Date = Now ();
        Ball_LikvidForm -> DateTimePicker2 -> Time = StrToTime ("00:00");
        Ball_LikvidForm -> DateTimePicker3 -> Date = Now ();
        Ball_LikvidForm -> DateTimePicker3 -> Time = StrToTime ("00:00");
        switch (fl) { // switch
        case 6: // if �������������� ���������
            Ball_LikvidForm -> DateTimePicker1 -> Enabled = true;
            Ball_LikvidForm -> DateTimePicker2 -> Enabled = true;
            Ball_LikvidForm -> Edit3 -> Enabled = true;
            Ball_LikvidForm -> Panel2 -> Visible = false;
            Ball_LikvidForm -> Height = Ball_LikvidForm -> Panel1 -> Height +
                Ball_LikvidForm -> Panel3 -> Height + 27;
            Ball_LikvidForm -> Caption = "�������������� ���������";
            break;
        case 7: // else �������������� ������
            Ball_LikvidForm -> DateTimePicker1 -> Enabled = false;
            Ball_LikvidForm -> DateTimePicker2 -> Enabled = false;
            Ball_LikvidForm -> Edit3 -> Enabled = false;
            Ball_LikvidForm -> Panel2 -> Visible = true;
            Ball_LikvidForm -> Height = Ball_LikvidForm -> Panel1 -> Height +
                Ball_LikvidForm -> Panel2 -> Height +
                Ball_LikvidForm -> Panel3 -> Height + 27;
            Ball_LikvidForm -> Caption = "��������� ����������";
            break;
        } // end switch
        Ball_LikvidForm -> DateTimePicker1 -> Date =
            SQLTimeStampToDateTime (DataModule1 -> Ved_LikvidGridFDQueryD_VED
            -> Value);
        Ball_LikvidForm -> DateTimePicker2 -> Date =
            SQLTimeStampToDateTime (DataModule1 -> Ved_LikvidGridFDQueryEND_D_EXAM
            -> Value);
        Ball_LikvidForm -> Edit3 -> Text =
            DataModule1 -> Ved_LikvidGridFDQueryFIO_EXAM -> Value;

        int uch_g = DataModule1 -> Ved_LikvidGridFDQueryYEAR_PLAN -> Value;
        Ball_LikvidForm -> Label10 -> Caption = IntToStr (uch_g) + " / " +
            IntToStr (uch_g + 1);

        Ball_LikvidForm -> ShowModal ();
    } // end else ������ YES  ��� NO

}
// ---------------------------------------------------------------------------

void __fastcall TVed_LikvidForm::Edit1KeyPress (TObject * Sender, char &Key) {
    DataModule1 -> Edit_Key (Key);
    // ��� �������, ����� � TEdit ����� ���� ������� ������ �����?
}
// ---------------------------------------------------------------------------

void __fastcall TVed_LikvidForm::BitBtn3Click (TObject * Sender) {
    Close ();
}
// ---------------------------------------------------------------------------

void __fastcall TVed_LikvidForm::ApplicationEvents1Message (tagMSG & Msg,
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
// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "Add_UchKartUnit.h"
#include "CalendarUnit.h"
#include "DataModule.h"
#include "Perezach_UchKartUnit.h"


#pragma package (smart_init)
// #pragma link     "ToolEdit"
#pragma resource "*.dfm"


TPerezach_UchKartForm * Perezach_UchKartForm;


int ball_do;                                                                    // ������ �������� �� �������� �� ����������




// BitBtn1Click
// BitBtn2Click
// BitBtn3Click
// DateTimePicker1Change
// Edit1Click
// Edit2Exit
// Edit2KeyPress
// FormActivate
// FormClose
// return_ball




__fastcall TPerezach_UchKartForm::TPerezach_UchKartForm (TComponent* Owner)
    : TForm (Owner) {
}

int TPerezach_UchKartForm::return_ball (int ball, int Index)
{ // ��������� ��� ���������� � ������ ������� ���������
    // int ball  - ���������� ����
    // int Index - �������� RadioGroup2 -> ItemIndex (0 - ������������� �������, 1 - ����������� �������
    int syst; // ���������� ��� ����������� ������� ������

    // ---���������� � ����� ������� ������� ������
    if (Index)
        syst = 5;
    else
        syst = 10;
    // ----
    if ( (ball > 10 && Index == 1) || (ball < 10 && Index == 0))
    { // if  ball>10 && Index==1 ������ �  ������������� ������� � ������� ����������� �������
        // ball<10 && Index==0 ������ � �����������  ������� � ������� ������������� �������

        ball = ball_int (syst, ball);
    } // end if
    // -----
    // if ( (ball<10 && Index==1) || (ball>10 && Index==0))
    // if  ball<10 && Index==1 ������ � ����������� ������� � ������� ����������� �������
    // ball>10 && Index==0 ������ � ������������� ������� � ������� ������������� �������
    return ball;

}

void __fastcall TPerezach_UchKartForm::FormClose (TObject *Sender,
    TCloseAction &Action) {
    add_card = true;
    Action = caFree;
}

void __fastcall TPerezach_UchKartForm::BitBtn2Click (TObject *Sender)
{ // �������� �� ������ ���������
    if (DBLookupComboBox1 -> Text == "") { // if �������� �������� �������
        ShowMessage ("�������� �������� �������� ��� ����������!");
        return;
    } // end if �������� �������� �������
    // -----------
   /*    if (ComboBox2 -> ItemIndex != 4 && ComboBox2 -> ItemIndex != 8)
    { // if ������� ��������� ��������� ������ �� ���������
        // ----4 ��� 8  ���   ComboBox2 ��������� ��������� ������
        // 4- ��������� � �/� �� �/� ��� �������� 8 - ��������� � ������� ����������
        ShowMessage (
            "�������� ��������� ��������� ������: ��������� � �/� �� �/� ��� �������� ��� ��������� � ������� ����������");
        return;
    } // end if ������� ��������� ��������� ������ �� ���������   */
    // ----------
    if (DBLookupComboBox1 -> Text != DBText4 -> Field -> AsString)
    { // if �������������� � ������ ������ ������� ��������
        // !!!if (Application -> MessageBox ("��������! �� ������� ������ �������� ��������. ���������� ���������?", "��������������", MB_YESNO) == mrNo)
        if (MessageDlg
            ("��������! �� ������� ������ �������� ��������. ���������� ���������?",
            mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrNo)
        { // if ����������� �������� ��������
            return;
        } // end if ����������� �������� ��������
    } // end if �������������� � ������ ������ ������� ��������

    // ---------�������� �����

    // TLocateOptions Opts;
    // Opts.Clear ();
    // Variant lv[2];
    // lv[0] = Variant (DataModule1 -> Spisoc_QueryNOMER -> Value);
    // lv[1] = DBLookupComboBox1 -> KeyValue;       //  N_PLAN

    // DataModule1 -> Result_BallQuery -> Close ();
    // DataModule1 -> Result_BallQuery -> ParamByName ("NOM") -> AsInteger=DataModule1 -> Spisoc_QueryNOMER -> Value;
    // DataModule1 -> Result_BallQuery -> Open ();

    // ����� �� ������ ��������  � ������ �������� �����
    DataModule1 -> Result_Ball_LocateFDQuery -> Close ();
    DataModule1 -> Result_Ball_LocateFDQuery -> ParamByName ("NOM") -> AsInteger =
        DataModule1 -> Spisoc_FDQueryNOMER -> Value;
    DataModule1 -> Result_Ball_LocateFDQuery -> ParamByName ("PLAN") -> AsInteger =
        DBLookupComboBox1 -> KeyValue; // N_PLAN
    DataModule1 -> Result_Ball_LocateFDQuery -> Open ();

    // if (DataModule1 -> Result_BallQuery -> Locate ("NOMER;N_PLAN", VarArrayOf (lv, 1), Opts))
    if (DataModule1 -> Result_Ball_LocateFDQuery -> RecordCount)
    { // ���� ������� ������ ��� ������� �������� �� ����� �������� �����
        ShowMessage ("� ��� �������� ��� ���� ������ �� ���������� ��������!");
        return;

    } // end if
    else { // ���� ����� ������ �� �������, �� ����� ������� � ����� ������� � �� ��������
        DataModule1 -> Result_Ball_LocateFDQuery -> Insert ();
        DataModule1 -> Result_Ball_LocateFDQueryNOMER -> Value =
            DataModule1 -> Spisoc_FDQueryNOMER -> Value;
        DataModule1 -> Result_Ball_LocateFDQueryN_PLAN -> Value =
            DBLookupComboBox1 -> KeyValue;

        DataModule1 -> Result_Ball_LocateFDQueryRESULT -> Value =
            return_ball (ball_do, RadioGroup2 -> ItemIndex);

        DataModule1 -> Result_Ball_LocateFDQueryDATE_RESULT -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);
        DataModule1 -> Result_Ball_LocateFDQuerySTATUS_RESULT -> Value =
            ComboBox2 -> ItemIndex + 1;

        // ------ �������� ������������ ���������� ������ �� MessageBox
        AnsiString box_res =
            "C�������: " + DataModule1 -> Spisoc_FDQueryFAM -> Value + " " +
            DataModule1 -> Spisoc_FDQueryNAME -> Value + " " +
            DataModule1 -> Spisoc_FDQueryOTCH -> Value + " �� �������� " +
            AnsiString (DBLookupComboBox1 -> Text) + " ��������� ������";
        // !!!if (Application -> MessageBox (box_res.c_str (),"��������� ������ ?", MB_YESNO)== IDYES)
        if (MessageDlg (box_res.c_str (), mtConfirmation,
            TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes) { // ���������� ��������� ������

            DataModule1 -> Result_Ball_LocateFDQuery -> ApplyUpdates ();
            DataModule1 -> Result_Ball_LocateFDQuery -> CommitUpdates ();

        }
        else { // �������� ��������� ������
            DataModule1 -> Result_Ball_LocateFDQuery -> CancelUpdates ();

        }

    } // end else

    Perezach_UchKartForm -> Close (); // ��������� �����

}

void __fastcall TPerezach_UchKartForm::Edit1Click (TObject *Sender) {
    // -----�������� ����� ��������� ��� ��������� ������ �������� ����
    /* CalendarForm = new  TCalendarForm (this);
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
     //��������� ���������� � ��������� ���� �  Edit1  � �������������� ��������
     //������� �������� �������� ���� �  Label2
     if (calendar)
     {
     Edit1 -> Text=cal_year;
     Label2 -> Caption="-- "+AnsiString (cal_year+1);
     Perezach_UchKartForm -> Edit2 -> SetFocus ();
     }
     else ShowMessage ("������� �������� �������� ����!"); */
    // -------

}

void __fastcall TPerezach_UchKartForm::BitBtn3Click (TObject *Sender) {

    // ----- �������� �� ������������ �������� ��������
    try { // try
        if (StrToInt (Edit2 -> Text) > 12 || StrToInt (Edit2 -> Text) <= 0)
        { // if   ����� �� ������� �������� ��������
            ShowMessage ("�� ����� ������������ �������� ��������!");
            Edit2 -> Text = "";
            Edit2 -> SetFocus ();
            return;
        } // end if  ����� �� ������� �������� ��������
        else { // else �������� �� ������������ � ����������� �� ���� ��������
            if (StrToInt (Edit2 -> Text) > 11 && ComboBox1 -> ItemIndex == 0)
            { // if ���� ��� �������� - �������, �� ������� �� ������ ��������� 10
                ShowMessage (
                    "�� ����� ������������ �������� �������� ��� �������� ��������!");
                Edit2 -> Text = "";
                Edit2 -> SetFocus ();
                return;
            } // end if ���� ��� �������� - �������, �� ������� �� ������ ��������� 10
        } // end else �������� �� ������������ � ����������� �� ���� ��������
    } // end try
    catch (EConvertError&) { // catch   ������ ��������� �����
        ShowMessage ("�� ����� ������������ �������� ��������!");
        Edit2 -> Text = "";
        Edit2 -> SetFocus ();
        return;
    } // end catch ������ ��������� �����
    // -------
    /* if (DBText7 -> Text==ComboBox1 -> Text)
     { //if ���� ������� ���� ��� ��� �������� ������
     ShowMessage ("������� �������� �������� ���� ��� ���� ��������!");
     } */

    if (Edit1 -> Text == "" || ComboBox1 -> ItemIndex == -1)
    { // if ���� ������� ���� ��� ��� �������� ������
        ShowMessage ("������� �������� �������� ���� ��� ���� ��������!");
    } // end if  ���� ������� ���� ��� ��� �������� ������
    else { // else  �������� ��������

        DataModule1 -> Edu_PlanFDQuery -> Close ();
        DataModule1 -> Edu_PlanFDQuery -> SQL -> Clear ();
        DataModule1 -> Edu_PlanFDQuery -> SQL -> Add
            ("SELECT Edu_plan.*, object_PLAN.name_object||' '||Edu_plan.clock_plan_all||'�' as name_plan, object_PLAN.name_object FROM EDU_PLAN, OBJECT_PLAN WHERE (N_FAC=:N_FAC) and Edu_plan.n_object = object_plan.n_object AND (YEAR_PLAN=:PLAN) AND (SEMESTR=" +
            Edit2 -> Text + ")" + " AND (VID_EDU_PLAN=" +
            AnsiString (ComboBox1 -> ItemIndex) + ")");
        DataModule1 -> Edu_PlanFDQuery -> Params -> Items[0] -> AsInteger = nom_fac;
        DataModule1 -> Edu_PlanFDQuery -> ParamByName ("PLAN") -> AsInteger =
            StrToInt (Edit1 -> Text);
        DataModule1 -> Edu_PlanFDQuery -> Open ();
        if (DataModule1 -> Edu_PlanFDQuery -> RecordCount) {
            ball_do = DataModule1 -> Result_BallFDQueryRESULT -> Value;
            // ������ ������ ��������
            if (ball_do <= 10)
                RadioGroup2 -> ItemIndex = 1; // ��� ����������� �������
            else
                RadioGroup2 -> ItemIndex = 0; // ��� ������������� �������

            Panel4 -> Enabled = true;
            ComboBox2 -> ItemIndex = 4;
        }
        else {
            ShowMessage ("��� ��������� �� ������� �������� ���� � ��������");
        }
    } // end else �������� ��������
}

void __fastcall TPerezach_UchKartForm::BitBtn1Click (TObject *Sender) {
    Close ();
}

void __fastcall TPerezach_UchKartForm::Edit2Exit (TObject *Sender) {
    Edit1 -> Text =
        AnsiString (Mas_God_Semestr (DataModule1 -> Spisoc_FDQueryKURS -> Value,
        StrToInt (Edit2 -> Text), uch_god));
    Label2 -> Caption = "-- " + AnsiString (Edit1 -> Text.ToInt () + 1);
}

void __fastcall TPerezach_UchKartForm::FormActivate (TObject *Sender) {
    ComboBox1 -> ItemIndex = DataModule1 -> Spisoc_FDQueryVID_EDU -> Value;
    Edit2 -> SetFocus ();
}

void __fastcall TPerezach_UchKartForm::Edit2KeyPress (TObject *Sender, char &Key)
{
    DataModule1 -> Edit_Key (Key);
    // ��� �������, ����� � TEdit ����� ���� ������� ������ �����?
}
void __fastcall TPerezach_UchKartForm::DateTimePicker1Change (TObject *Sender)
{
DateTimePicker1 -> Time = StrToTime ("00:00");
}
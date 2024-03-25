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


bool add_card = false;                                                          // �������� �� ������ � ������� �������� (true - �������)
int  res_ball;                                                                  // ������ � RadioGroup1


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
    // -----�������� ����� ��������� ��� ��������� ������ �������� ����
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
    //��������� ���������� � ��������� ���� �  Edit1  � �������������� ��������
    //������� �������� �������� ���� �  Label2
    if (calendar)
    {
    Edit1 -> Text=cal_year;
    Label2 -> Caption="-- "+AnsiString (cal_year+1);
    Add_UchKartForm -> Edit2 -> SetFocus ();
    }
    else ShowMessage ("������� �������� �������� ����!");
     //-------
    */

}

void __fastcall TAdd_UchKartForm::BitBtn3Click (TObject *Sender) {

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

    if (Edit1 -> Text == "" || ComboBox1 -> ItemIndex == -1)
    { // if ���� ������� ���� ��� ��� �������� ������
        ShowMessage ("������� �������� �������� ���� ��� ���� ��������!");
    } // end if  ���� ������� ���� ��� ��� �������� ������
    else { // else  �������� ��������

        DataModule1 -> Edu_PlanFDQuery -> Close ();
        DataModule1 -> Edu_PlanFDQuery -> SQL -> Clear ();
        DataModule1 -> Edu_PlanFDQuery -> SQL -> Add
            ("SELECT Edu_plan.*, object_PLAN.name_object||' '||Edu_plan.clock_plan_all||'�' as name_plan, object_plan.name_object FROM EDU_PLAN, object_plan WHERE (N_FAC=:N_FAC) and Edu_plan.n_object = object_plan.n_object AND (YEAR_PLAN=:PLAN) AND (SEMESTR=" +
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
            ShowMessage ("��� ��������� �� ������� �������� ���� � ��������");
        }
    } // end else �������� ��������
}

void __fastcall TAdd_UchKartForm::BitBtn1Click (TObject *Sender)
{ // �������� �� ������ ���������
    res_ball = 0;
    if (RadioGroup1 -> ItemIndex == -1 || DBLookupComboBox1 -> Text == "")
    { // if  �������� �� ����������� �������� �������� � ������ �� ����� ��������
        ShowMessage (
            "��������� ������� �� �� �������, ������ � ���� �������� (������)!");
    } // end if  �������� �� ����������� �������� �������� � ������ �� ����� ��������
    else { // else  �������� �����
        if (!RadioGroup2 -> ItemIndex)
        { // if RadioGroup2 -> ItemIndex==0 10-�� ������� �������
            switch (RadioGroup1 -> ItemIndex)
            { // switch ������� �������� �� RadioGroup1 -> ItemIndex  � �������� ��� ����
            case 7:
                res_ball = 1; // �����
                break;
            case 8:
                res_ball = 7; // ����������
                break;
            case 9:
                res_ball = 9; // ���������
                break;
                // ��������� ������ 10-�� ������� ������� ������� � 4 (��� ���� 14) �� 10 (��� ���� 20)
            default:
                res_ball = (RadioGroup1 -> ItemIndex + 14);
                break;
            } // end switch
        } // end if RadioGroup2 -> ItemIndex==0 10-�� ������� �������
        else { // else if RadioGroup2 -> ItemIndex==1 5-�� ������� �������
            switch (RadioGroup1 -> ItemIndex)
            { // switch ������� �������� �� RadioGroup1 -> ItemIndex  � �������� ��� ����
            case 0:
                res_ball = 3; // �����.
                break;
            case 1:
                res_ball = 4; // ������
                break;
            case 2:
                res_ball = 5; // �������
                break;
            case 3:
                res_ball = 1; // �����
                break;
            case 4:
                res_ball = 7; // ����������
                break;
            case 5:
                res_ball = 9; // ���������
                break;
            } // end switch ������� �������� �� RadioGroup1 -> ItemIndex  � �������� ��� ����
        } // end else if RadioGroup2 -> ItemIndex==1 5-�� ������� �������

        // ------�������� �� ��, ����� ��� ������ ���� ������� ������ �������� ����� ��� ����������
        Variant control = DataModule1 -> Edu_PlanFDQuery -> Lookup ("N_PLAN",
            DBLookupComboBox1 -> KeyValue, "ZACH_EXAM");
        if ( ( (control == 1) && (res_ball != 1)) &&
            ( (control == 1) && (res_ball != 7)))
        { // if �������������� ��������� ������ ��� ������ (ZACH_EXAM=1 ��� �����)
            ShowMessage (
                "��� ������ ��������� ������� ������ ������: ����� ��� ����������!");
            return;
        } // end if �������������� ��������� ������ ��� ������ (ZACH_EXAM=1 ��� �����)
        else {
            // control==0 ��� ������� ��� ���� ��������
            if ( (control == 0) && (res_ball != 9))
            { // if �������������� ��������� ������ ��� �������� ��� ���� ��������
                ShowMessage (
                    "��� �������� ��� ���� �������� ��������� ������� ������ ���������!");
                return;
            } // end if �������������� ��������� ������ ��� �������� ��� ���� ��������

            // control==2 ��� �������
            if ( ( (control == 2) && (res_ball != 3)) && // �����. � 5-�� �������
                ( (control == 2) && (res_ball != 4)) && // ���. � 5-�� �������
                ( (control == 2) && (res_ball != 5)) && // ���. � 5-�� �������
                ( (control == 2) && (res_ball != 7)) && // ����������
                ( (control == 2) && (res_ball != 14)) && // 4 � 10-�� �������
                ( (control == 2) && (res_ball != 15)) && // 5 � 10-�� �������
                ( (control == 2) && (res_ball != 16)) && // 6 � 10-�� �������
                ( (control == 2) && (res_ball != 17)) && // 7 � 10-�� �������
                ( (control == 2) && (res_ball != 18)) && // 8 � 10-�� �������
                ( (control == 2) && (res_ball != 19)) && // 9 � 10-�� �������
                ( (control == 2) && (res_ball != 20))) // 10 � 10-�� �������

            { // if �������������� ��������� ������ ��� �������� (ZACH_EXAM=2 ��� �������)
                ShowMessage (
                    "��� �������� ��������� ������� ������ ������ ��� ����������!");
                return;
            } // end if �������������� ��������� ������ ��� �������� (ZACH_EXAM=2 ��� �������)

            // control==3 ��� ���.�����
            if // ( ( (control==3) && (res_ball!=3)) && ( (control==3) && (res_ball!=4)) && ( (control==3) && (res_ball!=5)) && ( (control==3) && (res_ball!=7)))
                ( ( (control == 3) && (res_ball != 3)) && // �����. � 5-�� �������
                ( (control == 3) && (res_ball != 4)) && // ���. � 5-�� �������
                ( (control == 3) && (res_ball != 5)) && // ���. � 5-�� �������
                ( (control == 3) && (res_ball != 7)) && // ����������
                ( (control == 3) && (res_ball != 14)) && // 4 � 10-�� �������
                ( (control == 3) && (res_ball != 15)) && // 5 � 10-�� �������
                ( (control == 3) && (res_ball != 16)) && // 6 � 10-�� �������
                ( (control == 3) && (res_ball != 17)) && // 7 � 10-�� �������
                ( (control == 3) && (res_ball != 18)) && // 8 � 10-�� �������
                ( (control == 3) && (res_ball != 19)) && // 9 � 10-�� �������
                ( (control == 3) && (res_ball != 20))) // 10 � 10-�� �������

            { // if �������������� ��������� ������ ��� ���. ������ (ZACH_EXAM=3 ��� ���. �����)
                ShowMessage (
                    "��� ���.������ ��������� ������� ������ ������ ��� ����������!");
                return;
            } // end if �������������� ��������� ������ ��� ���. ������ (ZACH_EXAM=3 ��� ���. �����)

        }
        // -------

        // ����� �� ������ ��������  � ������ �������� �����
        // TLocateOptions Opts;
        // Opts.Clear ();
        // Variant lv[2];
        // lv[0] = Variant (DataModule1 -> Spisoc_QueryNOMER -> Value);
        // lv[1] = DBLookupComboBox1 -> KeyValue;       //  N_PLAN

        // ����� �� ������ ��������  � ������ �������� �����
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
        { // ���� ������� ������ ��� ������� �������� �� ����� �������� �����
            DataModule1 -> Result_Ball_LocateFDQuery -> Edit ();
        } // end if
        else { // ���� ����� ������ �� �������, �� ����� ������� � ����� ������� � �� ��������
            DataModule1 -> Result_Ball_LocateFDQuery -> Insert ();
            DataModule1 -> Result_Ball_LocateFDQueryNOMER -> Value =
                DataModule1 -> Spisoc_FDQueryNOMER -> Value;
            DataModule1 -> Result_Ball_LocateFDQueryN_PLAN -> Value =
                DBLookupComboBox1 -> KeyValue;
        } // end else
        // --------����������� ������ �������� �  Result_BallQuery

        DataModule1 -> Result_Ball_LocateFDQueryRESULT -> Value = res_ball;
        DateTimePicker1 -> Time = StrToTime ("00:00");
        DataModule1 -> Result_Ball_LocateFDQueryDATE_RESULT -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);
        DataModule1 -> Result_Ball_LocateFDQuerySTATUS_RESULT -> Value =
            ComboBox2 -> ItemIndex + 1;

        // ------ �������� � ������������ ���������� ������ �� MessageBox
        AnsiString box_res = "���������� �������: " +
            DataModule1 -> Spisoc_FDQueryFAM -> Value + " " +
            DataModule1 -> Spisoc_FDQueryNAME -> Value + " " +
            DataModule1 -> Spisoc_FDQueryOTCH -> Value + " �� �������� " +
            AnsiString (DBLookupComboBox1 -> Text) + " ������: " +
            RadioGroup1 -> Items -> Strings[RadioGroup1 -> ItemIndex];
        // !!!if (Application -> MessageBox (box_res.c_str (),"��������� ������ ?", MB_YESNO)== IDYES)
        if (MessageDlg (box_res.c_str (), mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
        { // ���������� ��������� ������

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
        else { // �������� ��������� ������
            DataModule1 -> Result_Ball_LocateFDQuery -> CancelUpdates ();

        }

        // -------
    } // end else  �������� �����

}

void __fastcall TAdd_UchKartForm::RadioGroup2Click (TObject *Sender) {
    RadioGroup1 -> Items -> Clear ();
    if (!RadioGroup2 -> ItemIndex) // �������� �� ������� ������
    { // if ���� ������� 10-�� �������

        RadioGroup1 -> Items -> Add ("������");
        RadioGroup1 -> Items -> Add ("����");
        RadioGroup1 -> Items -> Add ("�����");
        RadioGroup1 -> Items -> Add ("����");
        RadioGroup1 -> Items -> Add ("������");
        RadioGroup1 -> Items -> Add ("������");
        RadioGroup1 -> Items -> Add ("������");
        RadioGroup1 -> Items -> Add ("�����");
        RadioGroup1 -> Items -> Add ("����������");
        RadioGroup1 -> Items -> Add ("���������");

    } // end if ���� ������� 10-�� �������
    else { // else ���� ������� 5-�� �������

        RadioGroup1 -> Items -> Add ("�����.");
        RadioGroup1 -> Items -> Add ("������");
        RadioGroup1 -> Items -> Add ("�������");
        RadioGroup1 -> Items -> Add ("�����");
        RadioGroup1 -> Items -> Add ("����������");
        RadioGroup1 -> Items -> Add ("���������");

    } // end else ���� ������� 5-�� �������
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
            ShowMessage ("�������� �������� ������ ���� ��������!");
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
    // ��� �������, ����� � TEdit ����� ���� ������� ������ �����?
}
void __fastcall TAdd_UchKartForm::DateTimePicker1Change (TObject *Sender)
{
   DateTimePicker1 -> Time = StrToTime ("00:00");
}


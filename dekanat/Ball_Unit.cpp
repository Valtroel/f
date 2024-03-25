#include <vcl.h>
#pragma hdrstop


#include "Ball_Unit.h"
#include "CalendarUnit.h"
#include "DataModule.h"
#include "Result_VedUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TBall_Form * Ball_Form;


// BitBtn1Click
// BitBtn2Click
// DBNavigator1Click
// Edit1Change
// Edit1Click
// FormActivate
// FormClose
// Radio_ball
// Radio_setup
// RadioGroup1Click
// RadioGroup2Click



int __fastcall TBall_Form::Radio_setup ()
{ // ��������� RadioGroup1 -> ItemIndex � �������� �� ���� ������ � ���� ��������
    int b = DataModule1 -> Ball_FDQueryBALL -> Value;
    if (b != -1) { // ���� ���� �� ������
        if (b >= 10) { // if 10-�� ������� �������
            RadioGroup1 -> ItemIndex = b - 11;
            RadioGroup2 -> ItemIndex = 0;
        } // end if 10-�� ������� �������
        else { // else 5-�� ������� �������
            switch (DataModule1 -> Ball_FDQueryBALL -> Value) { // switch
            case 1:
                RadioGroup1 -> ItemIndex = 2; // �����
                RadioGroup2 -> ItemIndex = 0;
                break;
            case 2:
                RadioGroup1 -> ItemIndex = 0; // �������.
                RadioGroup2 -> ItemIndex = 1;
                break;
            case 6:
                if (DataModule1 -> Ball_FDQueryZACH_EXAM -> Value == 1)
                    RadioGroup1 -> ItemIndex = 1; // �������� �� �����
                else { // else �� ������ �� �������
                    if (RadioGroup2 -> ItemIndex) // ���������
                            RadioGroup1 -> ItemIndex = 1;
                    // �� ������  �� �����   ��� �������
                    else // ���� �����������
                            RadioGroup1 -> ItemIndex = 10;
                    // �� ������  �� �����   ��� �������
                } // end else �� ������ �� �������
                break;
            case 7:
                if (DataModule1 -> Ball_FDQueryZACH_EXAM -> Value == 1)
                    RadioGroup1 -> ItemIndex = 3; // ���������� �� ������
                else { // else ���������� �� ��������
                    if (RadioGroup2 -> ItemIndex) // ���������
                            RadioGroup1 -> ItemIndex = 2;
                    else // ���� �����������
                            RadioGroup1 -> ItemIndex = 11;
                } // end else ���������� �� ��������
                break;
            default:
                RadioGroup1 -> ItemIndex = b;
                RadioGroup2 -> ItemIndex = 1;
                break;
            } // switch
        } // end else 5-�� ������� �������
    }
    else
        RadioGroup1 -> ItemIndex = -1; // ���� ������ ���, �� ������ �� �������
    // ��������� ���� �������� � Edit1
    Edit1 -> Text =
        DateToStr (SQLTimeStampToDateTime
        (DataModule1 -> Ball_FDQueryD_EXAM -> Value));
    DBNavigator1 -> Enabled = true;
    return RadioGroup1 -> ItemIndex;
}

int __fastcall TBall_Form::Radio_ball ()
{ // �������� �������� ����� � ����������� �� RadioGroup1 -> ItemIndex � ���� ��������
    int ball_radio;
    if (DataModule1 -> Ball_FDQueryZACH_EXAM -> Value == 1) // ��� �����
    { // ���� �����
        switch (RadioGroup1 -> ItemIndex) { // switch
        case 1:
            ball_radio = 6; // �� ������
            break;
        case 2:
            ball_radio = 1; // �����
            break;
        case 3:
            ball_radio = 7; // ����������
            break;
        default:
            ball_radio = RadioGroup1 -> ItemIndex; // �������
            break;
        } // end switch
    } // end if �����
    else { // ���� ������� ��� ���. �����
        if (!RadioGroup2 -> ItemIndex) // �������� �� ������� ������
        { // if ���� ������� 10-�� �������
            switch (RadioGroup1 -> ItemIndex) { // switch

            case 10:
                ball_radio = 6; // �� ������
                break;
            case 11:
                ball_radio = 7; // ����������
                break;
            default:
                ball_radio = RadioGroup1 -> ItemIndex + 11;
                // ������ 3,4,5 ������� �������������  RadioGroup1 -> ItemIndex
                break;
            } // end switch
        } // end if ���� ������� 10-�� �������
        else { // else ���� ������� 5-�� �������
            switch (RadioGroup1 -> ItemIndex) { // switch
            case 0:
                ball_radio = 2; // �������������������
                break;
            case 1:
                ball_radio = 6; // �� ������
                break;
            case 2:
                ball_radio = 7; // ����������
                break;
            default:
                ball_radio = RadioGroup1 -> ItemIndex;
                // ������ 3,4,5 ������� �������������  RadioGroup1 -> ItemIndex
                break;
            } // end switch
        } // end else ���� ������� 5-�� �������
    } // end else  ������� ��� ���. �����
    return ball_radio;
}

__fastcall TBall_Form::TBall_Form (TComponent* Owner) : TForm (Owner) {
}

void __fastcall TBall_Form::BitBtn2Click (TObject *Sender)
{ // �������� �� ������ �������
    DataModule1 -> Ball_FDQuery -> Close ();
    DataModule1 -> Ball_FDQuery -> ParamByName ("N_FAC") -> AsInteger = nom_fac;
    DataModule1 -> Ball_FDQuery -> ParamByName ("N_VEDOM") -> AsInteger = inc_ved;
    DataModule1 -> Ball_FDQuery -> Open ();
    Close ();
}

void __fastcall TBall_Form::BitBtn1Click (TObject *Sender)
{ // �������� �� ������ ���������
    // ��������� Query � ����� �������������� � ��������� �������� ������ � ���� ��������
    if (RadioGroup1 -> ItemIndex == -1) {
        ShowMessage ("���������� ���������� ������!");
        return;
    }
    DataModule1 -> Ball_FDQuery -> Edit ();
    DataModule1 -> Ball_FDQueryBALL -> Value = Radio_ball ();
    // ���������� ������ � ����������� �� ���������
    // RadioGroup1 -> ItemIndex
    DataModule1 -> Ball_FDQueryD_EXAM -> Value = StrToSQLTimeStamp (Edit1 -> Text);
    if ( (DataModule1 -> Ball_FDQueryBALL -> Value >= 14) ||
        (DataModule1 -> Ball_FDQueryBALL -> Value == 1) ||
        (DataModule1 -> Ball_FDQueryBALL -> Value == 3) ||
        (DataModule1 -> Ball_FDQueryBALL -> Value == 4) ||
        (DataModule1 -> Ball_FDQueryBALL -> Value == 5) ||
        (DataModule1 -> Ball_FDQueryBALL -> Value == 7) ||
        (DataModule1 -> Ball_FDQueryBALL -> Value == 6))
    { // �������� ����������� ����� 1-�����, 3-�����., 4-���., 5-���., 7-����������
        // 6 - ��� ������, �� ���� ���������, ����� ��� �� ������ ������� ������ ������
        // �������� Query ��� ��������� ����������� � �������� ������� ��� ������� �������� RESULT_BALL
        // DataModule1 -> Result_BallQuery -> Close ();
        // DataModule1 -> Result_BallQuery -> ParamByName ("NOM") -> AsInteger=DataModule1 -> Ball_QueryNOMER -> Value;
        // DataModule1 -> Result_BallQuery -> Open ();
        // ����� �� ������ ��������  � ������ �������� �����
        DataModule1 -> Result_Ball_LocateFDQuery -> Close ();
        DataModule1 -> Result_Ball_LocateFDQuery -> ParamByName ("NOM") -> AsInteger =
            DataModule1 -> Ball_FDQueryNOMER -> Value;
        DataModule1 -> Result_Ball_LocateFDQuery -> ParamByName ("PLAN") -> AsInteger =
            DataModule1 -> Ball_FDQueryN_PLAN -> Value;
        DataModule1 -> Result_Ball_LocateFDQuery -> Open ();

        // TLocateOptions Opts;
        // Opts.Clear ();
        // Variant lv[2];
        // lv[0] = Variant (DataModule1 -> Ball_QueryNOMER -> Value);
        // lv[1] = Variant (DataModule1 -> Ball_QueryN_PLAN -> Value);
        // -----����� �� ���������� ��������� ������� ���������
        int st; // ���������� ��� ���������� Status_result �  Result_BallQuery
        Variant st_ved = DataModule1 -> VedomostFDQuery -> Lookup ("N_VED",
            DataModule1 -> Ball_FDQueryN_VED -> Value, "STATUS");
        if (!st_ved.IsNull ())
        { // ���� ������ ������, �� ��������� ����� ��������� ����
            int v = st_ved.AsType (varInteger);
            switch (v) {
            case 0:
                st = 1; // Status=0 - ��� �������� ���������
                break;
            case 3:
                st = 3; // Status=3 - ��� ��������� �� ��������� �����
                break;
            case 4:
                st = 4; // Status=4 - ��� ��������� �� ���������� �������
                break;
            default:
                st = 2; // Status=1 � 2 - ��� ��������. ��������� ��� ���.����
                break;
            }
        }
        // -----
        // if (DataModule1 -> Result_BallQuery -> Locate ("NOMER;N_PLAN", VarArrayOf (lv, 1), Opts))
        if (DataModule1 -> Result_Ball_LocateFDQuery -> RecordCount)
        { // ���� ������� ������ ��� ������� �������� �� ����� �������� �����
            if (DataModule1 -> Ball_FDQueryBALL -> Value == 6) { // if
                // !!!if (Application -> MessageBox ("�� ����� �������� � �������� ���� ������. ������� ��?", "��������!!!!", MB_YESNO) == mrYes)
                if (MessageDlg
                    ("�� ����� �������� � �������� ���� ������. ������� ��?",
                    mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes) { // if

                    DataModule1 -> Result_Ball_LocateFDQuery -> Delete ();
                    DataModule1 -> Result_Ball_LocateFDQuery -> ApplyUpdates ();
                    DataModule1 -> Result_Ball_LocateFDQuery -> CommitUpdates ();
                } // end if
            } // end if
            else
                DataModule1 -> Result_Ball_LocateFDQuery -> Edit ();
        } // end if
        else { // ���� ����� ������ �� �������, �� ����� ������� � ����� ������� � �� ��������
            if (DataModule1 -> Ball_FDQueryBALL -> Value != 6) {
                DataModule1 -> Result_Ball_LocateFDQuery -> Insert ();
                DataModule1 -> Result_Ball_LocateFDQueryNOMER -> Value =
                    DataModule1 -> Ball_FDQueryNOMER -> Value;
                DataModule1 -> Result_Ball_LocateFDQueryN_PLAN -> Value =
                    DataModule1 -> Ball_FDQueryN_PLAN -> Value;
            }
        } // end else

        if (DataModule1 -> Ball_FDQueryBALL -> Value != 6)
        { // if ----- ����������� ������ �������� Result_BallQuery
            DataModule1 -> Result_Ball_LocateFDQueryRESULT -> Value =
                DataModule1 -> Ball_FDQueryBALL -> Value;
            DataModule1 -> Result_Ball_LocateFDQueryDATE_RESULT -> Value =
                DataModule1 -> Ball_FDQueryD_EXAM -> Value;
            DataModule1 -> Result_Ball_LocateFDQuerySTATUS_RESULT -> Value = st;
            // ----
            try { // try �������� �� ������������ ���������� � Result_BallQuery
                DataModule1 -> Result_Ball_LocateFDQuery -> ApplyUpdates ();
                DataModule1 -> Result_Ball_LocateFDQuery -> CommitUpdates ();
            } // end tre
            catch (...) { // catch
                ShowMessage ("�� ��������� ������ � ������� ��������");

                DataModule1 -> Result_Ball_LocateFDQuery -> CancelUpdates ();
            } // end catch
        } // end if ----- ����������� ������ �������� Result_BallQuery
        // ------
    }
    try {
        DataModule1 -> Ball_FDQuery -> ApplyUpdates ();
        DataModule1 -> Ball_FDQuery -> CommitUpdates ();

    }
    catch (...) {
        ShowMessage ("�� ��������� ������ ��������!");
        DataModule1 -> Ball_FDQuery -> CancelUpdates ();

    }
    DBNavigator1 -> Enabled = true;
}

void __fastcall TBall_Form::DBNavigator1Click (TObject *Sender,
    TNavigateBtn Button)
{ // ��������� �������� RadioGroup1 -> ItemIndex - ������ ���������� �� ��������
    Radio_setup ();
}

void __fastcall TBall_Form::Edit1Click (TObject *Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> ShowModal ();
    Edit1 -> Text = cal_date;
}

void __fastcall TBall_Form::Edit1Change (TObject *Sender) {
    DBNavigator1 -> Enabled = false;
}

void __fastcall TBall_Form::FormActivate (TObject *Sender) {
    /* DataModule1 -> Edu_CardQuery -> Close ();
     DataModule1 -> Edu_CardQuery -> SQL -> Clear ();
     DataModule1 -> Edu_CardQuery -> SQL -> Add ("SELECT * FROM EDU_CARD ORDER BY N_VED");
     DataModule1 -> Edu_CardQuery -> Open (); */
}

void __fastcall TBall_Form::FormClose (TObject *Sender, TCloseAction &Action) {
    Action = caFree;
}

void __fastcall TBall_Form::RadioGroup1Click (TObject *Sender) {
    DBNavigator1 -> Enabled = false;
}

void __fastcall TBall_Form::RadioGroup2Click (TObject *Sender) {
    Result_VedForm -> RadioGroup_Ball ();
    // ��������� ��� ��������� Items-�� �  RadioGroup1
    Radio_setup ();
    // � ����������� �� ���� �������� � ������� ������
}

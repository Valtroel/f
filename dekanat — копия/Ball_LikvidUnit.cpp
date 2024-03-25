#include <vcl.h>
#pragma hdrstop


#include "Ball_LikvidUnit.h"
#include "DataModule.h"


#pragma package (smart_init)
// !!!#pragma link "ToolEdit"
#pragma resource "*.dfm"


TBall_LikvidForm *Ball_LikvidForm;



// BitBtn1Click
// DateTimePicker1Change
// DateTimePicker2Change
// DateTimePicker3Change
// FormClose
// Radio1_ball
// Radio1_base
// radio1_setup
// RadioGroup2Click




__fastcall TBall_LikvidForm::TBall_LikvidForm (TComponent* Owner) : TForm (Owner)
{
}

void __fastcall TBall_LikvidForm::radio1_setup ()
{ // ��������� ��� ��������� Items-�� �  RadioGroup1
    // ��� ��������  0 - ��� ��������
    // 1 - �����
    // 2 - �������
    // 3 - ���. �����

    RadioGroup1 -> Items -> Clear ();

    if (DataModule1 -> Ved_LikvidGridFDQueryZACH_EXAM -> Value)
    { // if ���� ��� ��������
        if (DataModule1 -> Ved_LikvidGridFDQueryZACH_EXAM -> Value == 1)
            // ��� �����
        { // if  �����
            RadioGroup1 -> Caption = "�����:";

            RadioGroup1 -> Items -> Add ("�������");
            RadioGroup1 -> Items -> Add ("�� ������");
            RadioGroup1 -> Items -> Add ("�����");
            RadioGroup1 -> Items -> Add ("����������");
        } // end if  �����
        else { // else  �������    ���. �����
            if (DataModule1 -> Ved_LikvidGridFDQueryZACH_EXAM -> Value == 2)
                RadioGroup1 -> Caption = "�������:";
            else
                RadioGroup1 -> Caption = "���. �����:";

            if (!RadioGroup2 -> ItemIndex) // �������� �� ������� ������
            { // if ���� ������� 10-�� �������
                RadioGroup1 -> Items -> Add ("����");
                RadioGroup1 -> Items -> Add ("���");
                RadioGroup1 -> Items -> Add ("���");
                RadioGroup1 -> Items -> Add ("������");
                RadioGroup1 -> Items -> Add ("����");
                RadioGroup1 -> Items -> Add ("�����");
                RadioGroup1 -> Items -> Add ("����");
                RadioGroup1 -> Items -> Add ("������");
                RadioGroup1 -> Items -> Add ("������");
                RadioGroup1 -> Items -> Add ("������");
                RadioGroup1 -> Items -> Add ("�� ������");
                RadioGroup1 -> Items -> Add ("����������");
                RadioGroup1 -> Columns = 3;
                RadioGroup1 -> Width = 290;
            } // end if ���� ������� 10-�� �������
            else { // else ���� ������� 5-�� �������
                RadioGroup1 -> Items -> Add ("�������.");
                RadioGroup1 -> Items -> Add ("�� ������");
                RadioGroup1 -> Items -> Add ("����������");
                RadioGroup1 -> Items -> Add ("�����.");
                RadioGroup1 -> Items -> Add ("������");
                RadioGroup1 -> Items -> Add ("�������");
                RadioGroup1 -> Columns = 2;
                RadioGroup1 -> Width = 217;
            } // end else ���� ������� 5-�� �������
        } // end else  �������    ���. �����
    } // end if ���� ��� ��������
    else { // else ��� ���� ��������
        RadioGroup1 -> Caption = "��� ���� ��������:";

        RadioGroup1 -> Items -> Add ("�� ���������");
        RadioGroup1 -> Items -> Add ("���������");

        RadioGroup1 -> Columns = 1;
    } // else ��� ���� ��������

}

int __fastcall TBall_LikvidForm::Radio1_ball ()
{ // �������� �������� ����� � ����������� �� RadioGroup1 -> ItemIndex � ���� ��������
    int ball_radio;

    if (DataModule1 -> Ved_LikvidGridFDQueryZACH_EXAM -> Value)
    { // if ���� ��� ��������
        if (DataModule1 -> Ved_LikvidGridFDQueryZACH_EXAM -> Value == 1)
            // ��� �����
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
    } // end if ���� ��� ��������
    else { // else ��� ���� ��������
        switch (RadioGroup1 -> ItemIndex) { // switch
        case 0:
            ball_radio = 8; // �� ���������
            break;
        case 1:
            ball_radio = 9; // ���������
            break;
        } // end switch

    } // else ��� ���� ��������

    return ball_radio;
}

int __fastcall TBall_LikvidForm::Radio1_base ()
{ // ��������� RadioGroup1 -> ItemIndex � �������� �� ���� ������
    // � ���� ��������
    Variant b = DataModule1 -> Ved_LikvidGridFDQueryBALL -> AsVariant;
    if (!b.IsNull ()) { // ���� ���� �� ������
        if (b >= 10) { // if 10-�� ������� �������
            RadioGroup1 -> ItemIndex = b - 11;
            RadioGroup2 -> ItemIndex = 0;
        } // end if 10-�� ������� �������
        else { // else 5-�� ������� �������
            switch (DataModule1 -> Ved_LikvidGridFDQueryBALL -> Value)
                // (DataModule1 -> Ball_QueryBALL -> Value)
            { // switch
            case 1:
                RadioGroup1 -> ItemIndex = 2; // �����
                RadioGroup2 -> ItemIndex = 0;
                break;
            case 2:
                RadioGroup1 -> ItemIndex = 0; // �������.
                RadioGroup2 -> ItemIndex = 1;
                break;
            case 6:
                if (RadioGroup2 -> ItemIndex) // ���������
                        RadioGroup1 -> ItemIndex = 1;
                // �� ������  �� �����   ��� �������
                else // ���� �����������
                        RadioGroup1 -> ItemIndex = 10;
                // �� ������  �� �����   ��� �������
                break;
            case 7:
                if (DataModule1 -> Ved_LikvidGridFDQueryZACH_EXAM -> Value == 1)
                    RadioGroup1 -> ItemIndex = 3; // ���������� �� ������
                else { // else ���������� �� ��������
                    if (RadioGroup2 -> ItemIndex) // ���������
                            RadioGroup1 -> ItemIndex = 2;
                    else // ���� �����������
                            RadioGroup1 -> ItemIndex = 11;
                } // end else ���������� �� ��������
                break;
            case 8:
                RadioGroup1 -> ItemIndex = 0; // �� ���������
                RadioGroup2 -> ItemIndex = 0;
                break;
            case 9:
                RadioGroup1 -> ItemIndex = 1; // ���������
                RadioGroup2 -> ItemIndex = 0;
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

    // ��������� ���� �������� � DateEdit3
    Variant date_ex = DataModule1 -> Ved_LikvidGridFDQueryD_EXAM -> AsVariant;
    if (!date_ex.IsNull ()) {
        DateTimePicker3 -> Date =
            SQLTimeStampToDateTime (DataModule1 -> Ved_LikvidGridFDQueryD_EXAM
            -> Value);
    }
    else {
        DateTimePicker3 -> Date = Now ();
        DateTimePicker3 -> Time = StrToTime ("00:00");
    }
    return RadioGroup1 -> ItemIndex;
}

void __fastcall TBall_LikvidForm::FormClose (TObject *Sender,
    TCloseAction &Action) {
    Action = caFree;
}

void __fastcall TBall_LikvidForm::RadioGroup2Click (TObject *Sender) {
    radio1_setup (); // ��������� ��� ��������� Items-�� �  RadioGroup1
    Radio1_base ();
}

void __fastcall TBall_LikvidForm::BitBtn1Click (TObject *Sender)
{ // ������ ���������
    if (Panel2 -> Visible) { // if �������������� ������

        if (RadioGroup1 -> ItemIndex == -1) { // if ���� ������
            ShowMessage ("������� ������!");
            Ball_LikvidForm -> ModalResult = 0;
            return;
        } // end if ���� ������

        // ���������� ������ �� ���������
        DataModule1 -> Ved_LikvidGridFDQuery -> Edit ();
        int Ball_Q = Radio1_ball ();
        DataModule1 -> Ved_LikvidGridFDQueryBALL -> Value = Ball_Q;
        DataModule1 -> Ved_LikvidGridFDQueryD_EXAM -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker3 -> Date);

        // �������� � ������� �������� ����������
        if ( (Ball_Q >= 14) || (Ball_Q == 1) || (Ball_Q == 3) || (Ball_Q == 4) ||
            (Ball_Q == 5) || (Ball_Q == 7) || (Ball_Q == 6) || (Ball_Q == 9))
        { // if �������� ����������� ����� 1-�����, 3-�����., 4-���., 5-���., 7-���������� , 9-���������
            // 6 - ��� ������, �� ���� ���������, ����� ��� �� ������ ������� ������ ������
            // �������� Query ��� ��������� ����������� � �������� ������� ��� ������� �������� RESULT_BALL
            // DataModule1 -> Result_BallQuery -> Close ();
            // DataModule1 -> Result_BallQuery -> ParamByName ("NOM") -> AsInteger=DataModule1 -> Ved_LikvidGridQueryNOMER -> Value;
            // DataModule1 -> Result_BallQuery -> Open ();

            // ����� �� ������ ��������  � ������ �������� �����
            DataModule1 -> Result_Ball_LocateFDQuery -> Close ();
            DataModule1 -> Result_Ball_LocateFDQuery -> ParamByName ("NOM")
                -> AsInteger = DataModule1 -> Ved_LikvidGridFDQueryNOMER -> Value;
            DataModule1 -> Result_Ball_LocateFDQuery -> ParamByName ("PLAN")
                -> AsInteger = DataModule1 -> Ved_LikvidGridFDQueryN_PLAN -> Value;
            DataModule1 -> Result_Ball_LocateFDQuery -> Open ();

            // TLocateOptions Opts;
            // Opts.Clear ();
            // Variant lv[2];
            // lv[0] = Variant (DataModule1 -> Ved_LikvidGridQueryNOMER -> Value);
            // lv[1] = Variant (DataModule1 -> Ved_LikvidGridQueryN_PLAN -> Value);

            // -----
            // if (DataModule1 -> Result_BallQuery -> Locate ("NOMER;N_PLAN", VarArrayOf (lv, 1), Opts))
            if (DataModule1 -> Result_Ball_LocateFDQuery -> RecordCount)
            { // ���� ������� ������ ��� ������� �������� �� ����� �������� �����
                if (Ball_Q == 6) { // if
                    // !!!if (Application -> MessageBox ("�� ����� �������� � �������� ���� ������. ������� ��?", "��������!!!!", MB_YESNO) == mrYes)
                    if (MessageDlg
                        ("�� ����� �������� � �������� ���� ������. ������� ��?"
                        , mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes) { // if

                        DataModule1 -> Result_Ball_LocateFDQuery -> Delete ();
                        DataModule1 -> Result_Ball_LocateFDQuery -> ApplyUpdates ();
                        DataModule1 -> Result_Ball_LocateFDQuery -> CommitUpdates ();
                    } // end if
                } // end if
                else
                    DataModule1 -> Result_Ball_LocateFDQuery -> Edit ();
            } // end if
            else { // ���� ����� ������ �� �������, �� ����� ������� � ����� ������� � �� ��������
                if (Ball_Q != 6) {
                    DataModule1 -> Result_Ball_LocateFDQuery -> Insert ();
                    DataModule1 -> Result_Ball_LocateFDQueryNOMER -> Value =
                        DataModule1 -> Ved_LikvidGridFDQueryNOMER -> Value;
                    DataModule1 -> Result_Ball_LocateFDQueryN_PLAN -> Value =
                        DataModule1 -> Ved_LikvidGridFDQueryN_PLAN -> Value;

                    DataModule1 -> Result_Ball_LocateFDQuerySTATUS_RESULT -> 
                        Value = 4;
                    // Status=4 - ��� ��������� �� ���������� �������
                }
            } // end else
            if (Ball_Q != 6) { // if ����������� ���������� � Result_Ball
                DataModule1 -> Result_Ball_LocateFDQueryRESULT -> Value =
                    DataModule1 -> Ved_LikvidGridFDQueryBALL -> Value;
                DataModule1 -> Result_Ball_LocateFDQueryDATE_RESULT -> Value =
                    DataModule1 -> Ved_LikvidGridFDQueryD_EXAM -> Value;
                try { // try ���������

                    // try �������� �� ������������ ���������� � Result_BallQuery
                    DataModule1 -> Result_Ball_LocateFDQuery -> ApplyUpdates ();
                    DataModule1 -> Result_Ball_LocateFDQuery -> CommitUpdates ();
                } // end try ���������
                catch (...) { // catch �������� ��������������

                    DataModule1 -> Result_Ball_LocateFDQuery -> CancelUpdates ();

                    ShowMessage (
                        "��������� ���� ��� ����������. ���������� ��� ���!");
                } // end catch �������� ��������������

            } // end if ����������� ���������� � Result_Ball
        } // end  if �������� ����������� ����� 1-�����, 3-�����., 4-���., 5-���., 7-����������
        // ---

        try { // try ���������
            DataModule1 -> Ved_LikvidGridFDQuery -> ApplyUpdates ();
            DataModule1 -> Ved_LikvidGridFDQuery -> CommitUpdates ();

            ShowMessage ("���������� ������ �������!");
        } // end try ���������
        catch (...) { // catch �������� ��������������
            DataModule1 -> Ved_LikvidGridFDQuery -> CancelUpdates ();

            ShowMessage ("��������� ���� ��� ����������. ���������� ��� ���!");
        } // end catch �������� ��������������

    } // end if �������������� ������
    else { // else �������������� ���������

        if (Edit3 -> Text == "") { // if ��� ������������
            ShowMessage ("������� ������� ������������!");
            Ball_LikvidForm -> ModalResult = 0;
            return;
        } // if ��� ������������

        // ���������� ������ �� ���������
        DataModule1 -> Ved_LikvidGridFDQuery -> Edit ();
        DataModule1 -> Ved_LikvidGridFDQueryD_VED -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);
        DataModule1 -> Ved_LikvidGridFDQueryEND_D_EXAM -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker2 -> Date);
        DataModule1 -> Ved_LikvidGridFDQueryFIO_EXAM -> Value = Edit3 -> Text;

        try { // try ���������
            DataModule1 -> Ved_LikvidGridFDQuery -> ApplyUpdates ();
            DataModule1 -> Ved_LikvidGridFDQuery -> CommitUpdates ();

            ShowMessage ("���������� ������ �������!");
        } // end try ���������
        catch (...) { // catch �������� ��������������
            DataModule1 -> Ved_LikvidGridFDQuery -> CancelUpdates ();

            ShowMessage ("��������� ���� ��� ����������. ���������� ��� ���!");
        } // end catch �������� ��������������

    } // end else �������������� ���������
}
void __fastcall TBall_LikvidForm::DateTimePicker1Change (TObject *Sender)
{
DateTimePicker1 -> Time = StrToTime ("00:00");
}

void __fastcall TBall_LikvidForm::DateTimePicker2Change (TObject *Sender)
{
DateTimePicker2 -> Time = StrToTime ("00:00");
}

void __fastcall TBall_LikvidForm::DateTimePicker3Change (TObject *Sender)
{
DateTimePicker3 -> Time = StrToTime ("00:00");
}


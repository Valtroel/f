#include <vcl.h>
#pragma hdrstop


#include "DataModule.h"
#include "DM2Unit.h"
#include "DM4Unit.h"
#include "PasportUnit.h"
#include "StudUnit.h"


#pragma package (smart_init)
// #pragma link     "DBGridEh"
// #pragma link     "GridsEh"
// #pragma link     "ToolEdit"
#pragma resource "*.dfm"


TPasportForm * PasportForm;


int nomer,                                                                      // id ��������
    statUpdate = 0;                                                             // 0 - ���������� ������, 1 - ��������������




// AreaDisplay
// BitBtn1Click
// BitBtn2Click
// ClearComponent
// ComboBox1Exit
// DateTimePicker1Change
// DateTimePicker2Change
// DBLookupComboBox2CloseUp
// DBLookupComboBox2Exit
// Edit2KeyPress
// FormActivate
// FormClose 
// PressBtn
// SaveData
// SpeedButton1Click
// SpeedButton2Click
// SpeedButton3Click





__fastcall TPasportForm::TPasportForm (TComponent* Owner) : TForm (Owner) {
}

void __fastcall TPasportForm::AreaDisplay ()
{ // ��������� ������� � ������� ������
    if (DBLookupComboBox2 -> KeyValue == 5) {
        ComboBox1 -> Enabled = true;
        ComboBox1 -> Items -> BeginUpdate ();
        ComboBox1 -> Items -> Clear ();
        ComboBox1 -> Items -> Add ("���������");
        ComboBox1 -> Items -> Add ("���������");
        ComboBox1 -> Items -> Add ("����������");
        ComboBox1 -> Items -> Add ("�����������");
        ComboBox1 -> Items -> Add ("������������");
        ComboBox1 -> Items -> Add ("������������");
        ComboBox1 -> Items -> Add ("���������");
        ComboBox1 -> Items -> Add ("�����������");
        ComboBox1 -> Items -> Add ("�����������");
        ComboBox1 -> Items -> EndUpdate ();
    }
    else {
        ComboBox1 -> Clear ();
        ComboBox1 -> Enabled = false;
    }
} // end ��������� ������� � ������� ������

void __fastcall TPasportForm::FormActivate (TObject *Sender) {
    // �������� Query � ���������� ����� ��������� ��������
    DataModule1 -> PasportFDQ -> Close ();
    DataModule1 -> PasportFDQ -> ParamByName ("NOM") -> AsInteger =
        DataModule1 -> PeopleFDQueryNOMER -> Value;
    DataModule1 -> PasportFDQ -> Open ();

    // �������� Query ��� ���������
    DataModule1 -> PasportTypeFDQ -> Close ();
    DataModule1 -> PasportTypeFDQ -> Open ();

    if (!est_pas)
        PressBtn (1); // ������ ��������
}

void __fastcall TPasportForm::ClearComponent ()
{ // ��������� ������� ����������� Panel2
    Edit1 -> Text = "";
    Edit2 -> Text = "";
    Edit3 -> Text = "";
    Memo1 -> Text = "";
    DateTimePicker1 -> Date = Now ();
    DateTimePicker1 -> Time = StrToTime ("00:00");
    DateTimePicker2 -> Date = Now ();
    DateTimePicker2 -> Time = StrToTime ("00:00");
    DBLookupComboBox1 -> KeyValue = -1;
    DBLookupComboBox2 -> KeyValue = -1;
    ComboBox1 -> Text = "";
} // end ��������� ������� ����������� Panel2

void __fastcall TPasportForm::SaveData ()
{ // ��������� ���������� ������ ��������
    // �������� �� ���������� �����������
    if (DBLookupComboBox1 -> Text == "") {
        ShowMessage ("�� ������ ��� ���������!");
        PasportForm -> ModalResult = 0;
        DBLookupComboBox1 -> SetFocus ();
        return;
    }
    if (DBLookupComboBox1 -> KeyValue == 1) {
        if (Edit1 -> Text == "") {
            ShowMessage ("������� ����� ��������!");
            PasportForm -> ModalResult = 0;
            Edit1 -> SetFocus ();
            return;
        }
        if (Edit2 -> Text == "") {
            ShowMessage ("������� ����� ��������!");
            PasportForm -> ModalResult = 0;
            Edit2 -> SetFocus ();
            return;
        }
        if (Edit3 -> Text == "") {
            ShowMessage ("������� ����������������� �!");
            PasportForm -> ModalResult = 0;
            Edit3 -> SetFocus ();
            return;
        }

        AnsiString kol_simvol = "";
        kol_simvol = Edit2 -> Text.Length ();
        if (kol_simvol != 7) {
            ShowMessage ("��������� ����� � ��� ��������!");
            PasportForm -> ModalResult = 0;
            Edit2 -> SetFocus ();
            return;
        }
        // �������� �� ������ �����
        AnsiString pers = Edit3 -> Text;
        if (pers != "") {
            if (pers.Length () != 14)
                ShowMessage (
                "��������� ������ �����, �� ������ ��������� 14 ��������!");
           /*    if ( (StudForm -> DBComboBox1 -> Text == "�" && pers.SubString (1,
                1) != "3") ||
                (StudForm -> DBComboBox1 -> Text == "�" && pers.SubString (1,
                1) != "4"))
                ShowMessage (
                "��������� ������ �����, ������ ����� �� ������������� ����!");*/
            AnsiString datR = StudForm -> DBEdit5 -> Text; // 23.11.1981
            datR = datR.Delete (3, 1);
            datR = datR.Delete (5, 3);
           /*    if (datR != pers.SubString (2, 6))
                ShowMessage (
                "��������� ������ �����, ���� �������� �� ������������� ������ � ������ ������!");  */
        }
    }
    if (Memo1 -> Text == "") {
        ShowMessage ("������� ������: ��� �����!");
        PasportForm -> ModalResult = 0;
        Memo1 -> SetFocus ();
        return;
    }
    if (DBLookupComboBox2 -> Text == "") {
        ShowMessage ("�� ������ ������/�������!");
        PasportForm -> ModalResult = 0;
        return;
    }

    // end �������� �� ���������� �����������

    // ���������� ����� ��������
    nomer = DataModule1 -> PeopleFDQueryNOMER -> Value;

    if (!statUpdate)
        DataModule1 -> PasportFDQ -> Insert ();
    else
        DataModule1 -> PasportFDQ -> Edit ();

    DataModule1 -> PasportFDQNOMER -> Value = nomer;
    DataModule1 -> PasportFDQID_TYPE -> Value = DBLookupComboBox1 -> KeyValue;
    DataModule1 -> PasportFDQSERIES -> Value = Edit1 -> Text;
    DataModule1 -> PasportFDQNUMBER -> Value = Edit2 -> Text;
    DataModule1 -> PasportFDQPERSONAL_NUMBER -> Value = Edit3 -> Text;
    DataModule1 -> PasportFDQWHO_GIVE -> Value = Memo1 -> Text;
    DataModule1 -> PasportFDQN_REGION -> Value = DBLookupComboBox2 -> KeyValue;
    DataModule1 -> PasportFDQDATE_GIVE -> Value =
        DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);
    DataModule1 -> PasportFDQDATE_VALID -> Value =
        DateTimeToSQLTimeStamp (DateTimePicker2 -> Date);

    try {
        DataModule1 -> PasportFDQ -> ApplyUpdates ();
        DataModule1 -> PasportFDQ -> CommitUpdates ();
        DataModule1 -> PasportFDQ -> Close ();
    }
    catch (...) {
        ShowMessage ("������� �� ��� �������� ������");
        return;
    }
    DataModule1 -> PasportFDQ -> Close ();
    DataModule1 -> PasportFDQ -> Open ();

    PressBtn (4); // ������ ���������

} // end ��������� ���������� ������ ��������

void __fastcall TPasportForm::PressBtn (int press_btn) { // ������� ������ ������
    switch (press_btn) { // switch
        // case 0:
    case 1: // ������ ������ ��������
        if (!est_pas) // ���������� ���� �� �������
        {
            statUpdate = 0; // ���������� �������� ��� �������� ������

            PasportForm -> Width = 225;
            Panel1 -> Visible = false;
            Panel2 -> Visible = true;
            Panel3 -> Visible = false;

            Label1 -> Caption = "��������";
            BitBtn1 -> Caption = "���������";

            ClearComponent (); // ������ �����������
            DBLookupComboBox1 -> KeyValue = 1;
            DBLookupComboBox1 -> SetFocus ();
        }
        else {
            // !!!Application -> MessageBox ("� �������� ������ ���� ���� ��������, �������������� ��������!", "") == mrYes;
            MessageDlg (
                "� �������� ������ ���� ���� ��������, �������������� ��������!",
                mtWarning, TMsgDlgButtons () << mbOK, 0);
        }
        break;

    case 2: // ������ ������ ��������
        statUpdate = 1; // ���������� �������� ��� �������� ������

        PasportForm -> Width = 225;
        Panel1 -> Visible = false;
        Panel2 -> Visible = true;
        Panel3 -> Visible = false;

        Label1 -> Caption = "��������";
        BitBtn1 -> Caption = "��������";

        // �������� ������ � ���������� ��� ���������
        DBLookupComboBox1 -> KeyValue = DataModule1 -> PasportFDQID_TYPE -> Value;
        Edit1 -> Text = DataModule1 -> PasportFDQSERIES -> Value;
        Edit2 -> Text = DataModule1 -> PasportFDQNUMBER -> Value;
        Edit3 -> Text = DataModule1 -> PasportFDQPERSONAL_NUMBER -> Value;
        Memo1 -> Text = DataModule1 -> PasportFDQWHO_GIVE -> Value;
        DBLookupComboBox2 -> KeyValue = DataModule1 -> PasportFDQN_REGION -> Value;
        DateTimePicker1 -> Date =
            SQLTimeStampToDateTime (DataModule1 -> PasportFDQDATE_GIVE -> Value);
        DateTimePicker2 -> Date =
            SQLTimeStampToDateTime (DataModule1 -> PasportFDQDATE_VALID -> Value);

        if (DBLookupComboBox2 -> KeyValue == 5)
            ComboBox1 -> Enabled = true;
        AreaDisplay ();
        break;

    case 3: // ������� ������
        // !!!if (Application -> MessageBox ("�� ������������� ������ ������� ������?","��������������!", MB_YESNO)== IDYES)
        if (MessageDlg ("�� ������������� ������ ������� ������?",
            mtConfirmation, TMsgDlgButtons () << mbOK, 0))
        { // �������� ��������� ������
            DataModule1 -> PasportFDQ -> Delete ();
            DataModule1 -> PasportFDQ -> ApplyUpdates ();
            DataModule1 -> PasportFDQ -> CommitUpdates ();
            PasportForm -> Close ();
            // !!!Application -> MessageBox ("�������� ������ �������!", "",MB_OK);
            MessageDlg ("�������� ������ �������!", mtInformation,
                TMsgDlgButtons () << mbOK, 0);
        }
        break;

    case 4: // ������ ������ ���������
        est_pas = true;
        PasportForm -> Width = 280;
        Panel1 -> Visible = true;
        Panel2 -> Visible = false;
        Panel3 -> Visible = true;
        ClearComponent (); // ��������� ������� �����������
        break;

    case 5: // ������ ������ ��������
        if (!statUpdate)
            PasportForm -> Close ();
        else {
            PasportForm -> Width = 280;
            Panel1 -> Visible = true;
            Panel2 -> Visible = false;
            Panel3 -> Visible = true;
            ClearComponent (); // ��������� ������� �����������
        }
        break;
    } // end switch
} // end ������� ������ ������

void __fastcall TPasportForm::FormClose (TObject *Sender, TCloseAction &Action) {
    Action = caFree;
}

void __fastcall TPasportForm::SpeedButton1Click (TObject *Sender) {
    PressBtn (1); // ������ ��������
}

void __fastcall TPasportForm::SpeedButton2Click (TObject *Sender) {
    PressBtn (2); // ������ ��������
}

void __fastcall TPasportForm::SpeedButton3Click (TObject *Sender) {
    PressBtn (3); // ������ �������
}

void __fastcall TPasportForm::BitBtn1Click (TObject *Sender) {
    SaveData ();
}

void __fastcall TPasportForm::BitBtn2Click (TObject *Sender) {
    PressBtn (5); // ������ ��������
}

void __fastcall TPasportForm::Edit2KeyPress (TObject *Sender, char &Key) {
    if (DBLookupComboBox1 -> KeyValue == 1)
    { // if ������� ��  ���� � Edit2 ������ ����
        if ( (Key >= '0') && (Key <= '9') || Key == VK_BACK) {
        } // �����
        // else if ( (Key == '.') || (Key == ',')){} // ������� (��� ������� �����)
        else
            Key = 0; // �� �����
        // 7 ���� ��� �������� ��
        Edit2 -> MaxLength = 7;
    } // end if ������� ��
}

void __fastcall TPasportForm::DBLookupComboBox2Exit (TObject *Sender) {
    AreaDisplay ();

}

void __fastcall TPasportForm::DBLookupComboBox2CloseUp (TObject *Sender) {
    AreaDisplay ();
    Memo1 -> Clear ();
}

void __fastcall TPasportForm::ComboBox1Exit (TObject *Sender) {
    // ���������� ��� ������������ ��� ����� ������� (��� �.������)
    AnsiString who_give = "";
    AnsiString area = "";
    area = ComboBox1 -> Text;
    who_give = area + " ���� �.������";
    Memo1 -> Text = who_give;
}
void __fastcall TPasportForm::DateTimePicker1Change (TObject *Sender)
{
DateTimePicker1 -> Time = StrToTime ("00:00");
}

void __fastcall TPasportForm::DateTimePicker2Change (TObject *Sender)
{
DateTimePicker2 -> Time = StrToTime ("00:00");
}


#include <vcl.h>
#pragma hdrstop


#include "DataModule.h"
#include "PeopleVedUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TPeopleVedForm * PeopleVedForm;



// ApplicationEvents1Message
// BitBtn1Click
// BitBtn3Click
// ComboBox3Change
// DBLookupComboBox1Click
// Edit7KeyPress
// FormActivate
// FormClose
// RadioGroup2Click
// SpeedButton1Click





__fastcall TPeopleVedForm::TPeopleVedForm (TComponent* Owner) : TForm (Owner) {
}

void __fastcall TPeopleVedForm::FormClose (TObject *Sender, TCloseAction &Action)
{
    Action = caFree;
}

void __fastcall TPeopleVedForm::BitBtn3Click (TObject *Sender) {
    // ----------
    if (ComboBox3 -> Text == "") { // if  ��� ��������
        ShowMessage ("�������� ��� ��������");
        return;
    } // end if ��� ��������
    // ----------
    if ( (!RadioGroup2 -> ItemIndex) && (Edit7 -> Text == "")) { // if � ������
        ShowMessage ("�������� � ������");
        return;
    } // end if � ������
    // ----------
    DataModule1 -> People_CaseFDQuery -> Close ();
    AnsiString s = "";
    int inc_gr;
    switch (RadioGroup2 -> ItemIndex)
    { // switch ����� ������������ ��� ������������ ��������
    case 0: // �����������
        s = "1";
        // �������, ������������ ��������� ������
        inc_gr = search_increment_group (Edit7 -> Text, ComboBox3 -> ItemIndex);
        break;
    case 1: // �����������
        s = "2";
        inc_gr = 18;
        break;
    case 2: // ���������
        s = "3";
        inc_gr = 18;
        break;
    case 3: // ����. ���
        s = "4";
        inc_gr = 18;
        break;
    } // end switch ����� ������������ ��� ������������ ��������

    DataModule1 -> People_CaseFDQuery -> ParamByName ("ST") -> AsString = s;
    DataModule1 -> People_CaseFDQuery -> ParamByName ("FAC") -> AsSmallInt = nom_fac;
    DataModule1 -> People_CaseFDQuery -> ParamByName ("EDU") -> AsSmallInt =
        ComboBox3 -> ItemIndex;
    DataModule1 -> People_CaseFDQuery -> ParamByName ("GR") -> AsSmallInt = inc_gr;
    DataModule1 -> People_CaseFDQuery -> Open ();

    if (DataModule1 -> People_CaseFDQuery -> RecordCount)
    { // if ���� �������� �� ��������� ����������
        // ---�������
        Label7 -> Visible = true;
        DBLookupComboBox1 -> Visible = true;

        // Panel1 -> Visible=true;
        // PeopleVedForm -> Height=205;
        PeopleVedForm -> Height = 164;
    } // end if ���� �������� �� ��������� ����������
    else { // else ��� �� ������ ��������
        // ---�������
        Label7 -> Visible = false;
        DBLookupComboBox1 -> Visible = false;
        PeopleVedForm -> Height = 164;
        Panel1 -> Visible = false;
        ShowMessage ("��� ��������� �� �������� ��������");
        return;
    } // end else ��� �� ������ ��������
}

void __fastcall TPeopleVedForm::BitBtn1Click (TObject *Sender) {

    if (DBLookupComboBox1 -> Text != "") { // if ��� ������ �������
        DataModule1 -> People_VedFDQuery -> Close ();
        DataModule1 -> People_VedFDQuery -> ParamByName ("NOMER") -> AsInteger =
            DBLookupComboBox1 -> KeyValue;
        DataModule1 -> People_VedFDQuery -> Open ();

        if (DataModule1 -> People_VedFDQuery -> RecordCount) { // if ����� ������
            Panel2 -> Visible = true;
            PeopleVedForm -> Height = 540;
            // if (PeopleVedForm -> Position!=poMainFormCenter) PeopleVedForm -> Position=poMainFormCenter;
        } // if ����� ������
        else { // else ��� �� ����� ������
            ShowMessage ("��� �� ����� ��������� �� ������� ��������");
            Panel2 -> Visible = false;
            return;
        } // end else ��� �� ����� ������
    } // end if ��� ������ �������
}

void __fastcall TPeopleVedForm::RadioGroup2Click (TObject *Sender)
{ // ����� ������������ ��� ������������ ��������

    // ---�������
    Label7 -> Visible = false;
    DBLookupComboBox1 -> Visible = false;
    // ---��� ��������
    Label12 -> Visible = true;
    ComboBox3 -> Visible = true;
    // ---����� ��������
    BitBtn3 -> Visible = true;

    // �������� �������
    Panel1 -> Visible = false;
    Panel2 -> Visible = false;
    PeopleVedForm -> Height = 164;

    switch (RadioGroup2 -> ItemIndex) { // switch ����������� ��� �����������

    case 0: // �����������
        // ---� ������
        Label13 -> Visible = true;
        Edit7 -> Text = "";
        Edit7 -> Visible = true;
        break;

    default: // �����������, ����������, ��������� ���
        // ---� ������
        Label13 -> Visible = false;
        Edit7 -> Visible = false;
        Edit7 -> Text = "";
        break;

    } // end switch ����������� ��� �����������
}

void __fastcall TPeopleVedForm::DBLookupComboBox1Click (TObject *Sender) {
    Panel2 -> Visible = false;
    PeopleVedForm -> Height = 205;
    Panel1 -> Visible = true;
}

void __fastcall TPeopleVedForm::FormActivate (TObject *Sender) {
    PeopleVedForm -> Height = 164;
}

void __fastcall TPeopleVedForm::SpeedButton1Click (TObject *Sender)
{ // �������� ������ �� DBGrid1 � Excel
    DBgrid_toEx (DBGrid1);
}

void __fastcall TPeopleVedForm::ComboBox3Change (TObject *Sender) {
    Panel1 -> Visible = false;
    Panel2 -> Visible = false;
    PeopleVedForm -> Height = 164;
}

void __fastcall TPeopleVedForm::Edit7KeyPress (TObject *Sender, char &Key) {
    DataModule1 -> Edit_Key (Key);
    // ��� �������, ����� � TEdit ����� ���� ������� ������ �����?
}

void __fastcall TPeopleVedForm::ApplicationEvents1Message (tagMSG &Msg,
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

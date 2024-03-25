#include <vcl.h>
#pragma hdrstop


#include "DataModule.h"
#include "DM2Unit.h"
#include "Prikaz_LikvidUnit.h"


#pragma package (smart_init)
// #pragma link     "ToolEdit"
#pragma resource "*.dfm"


TPrikaz_LikvidForm * Prikaz_LikvidForm;


int hhh     = 28,
    hhh_all = 0;





// BitBtn3Click
// Button1Click
// DateTimePicker1Change
// DateTimePicker2Change
// DateTimePicker3Change
// Edit7KeyPress
// FormClose
// FormShow
// RadioGroup1Click
// RadioGroup2Click
// RadioGroup6Click





__fastcall TPrikaz_LikvidForm::TPrikaz_LikvidForm (TComponent* Owner)
    : TForm (Owner) {
}


void __fastcall TPrikaz_LikvidForm::FormClose (TObject *Sender,
    TCloseAction &Action) {
    DM2 -> SpecializFDTable -> Filtered = true;
    Action = caFree;
}


void __fastcall TPrikaz_LikvidForm::RadioGroup2Click (TObject *Sender) {
    // ����� ������������ ��� ������������ ��������

    // ---�������
    Label7 -> Visible = false;
    DBLookupComboBox1 -> Visible = false;

    // ---���������
    Label14 -> Visible = true;
    ComboBox4 -> Visible = true;
    // ---��� ��������
    Label12 -> Visible = true;
    ComboBox3 -> Visible = true;
    // ---����� ��������
    BitBtn3 -> Visible = true;

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


void __fastcall TPrikaz_LikvidForm::RadioGroup1Click (TObject *Sender) {
    switch (RadioGroup1 -> ItemIndex) { // switch

    case 0: // ���� ������ �� ���������� �������
        Panel4 -> Visible = true;

        // ---� ������
        Label13 -> Visible = false;
        Edit7 -> Visible = false;
        Edit7 -> Text = "";

        // ---�������
        Label7 -> Visible = false;
        DBLookupComboBox1 -> Visible = false;
        DBLookupComboBox1 -> KeyValue = -1;

        // ---���������
        Label14 -> Visible = false;
        ComboBox4 -> Visible = false;
        ComboBox4 -> ItemIndex = -1;

        // ---��� ��������
        Label12 -> Visible = false;
        ComboBox3 -> Visible = false;
        ComboBox3 -> ItemIndex = -1;

        // ---����� ��������
        BitBtn3 -> Visible = false;

        RadioGroup2 -> ItemIndex = -1;

        // ----
        Panel2 -> Visible = false;
        GroupBox1 -> Visible = false;
        Panel6 -> Visible = false;

        if (DataModule1 -> People_CaseFDQuery -> State != dsInactive)
            DataModule1 -> People_CaseFDQuery -> Close ();
        if (DataModule1 -> Prikaz_LikvidFDQuery -> State != dsInactive)
            DataModule1 -> Prikaz_LikvidFDQuery -> Close ();

        hhh_all = Panel1 -> Height + Panel4 -> Height + hhh;
        if (hhh_all > 600)
            Prikaz_LikvidForm -> Height = 600;
        else
            Prikaz_LikvidForm -> Height = hhh_all;

        break;
    case 1: // �������� ������ �� ���������� �������
        Panel2 -> Visible = true;

        // DBGrid1 ������ ���������
        DBGrid1 -> Enabled = true;

        Panel4 -> Visible = false;
        GroupBox1 -> Visible = false;
        Panel6 -> Visible = false;
        DM2 -> SpecializFDTable -> Filtered = false;

        // �������� ��: ����
        Label8 -> Visible = false;
        DateTimePicker3 -> Visible = false;
        DateTimePicker3 -> Date = Now ();
        DateTimePicker3 -> Time = StrToTime ("00:00");
        DateTimePicker3 -> Date.operator++ (10);
        // ���������: ��� ���������� �������
        Label6 -> Visible = false;
        Edit2 -> Visible = false;
        Edit2 -> Text = "";

        // ������ � ����������
        Panel3 -> Visible = false;

        // Prikaz_LikvidForm -> Height=Panel1 -> Height+Panel2 -> Height+Panel5 -> Height+DBGrid1 -> Height+hhh;
        hhh_all = Panel1 -> Height + Panel2 -> Height + Panel5 -> Height +
            DBGrid1 -> Height + hhh;
        if (hhh_all > 600)
            Prikaz_LikvidForm -> Height = 600;
        else
            Prikaz_LikvidForm -> Height = hhh_all;

        DataModule1 -> LikvidFDQuery -> Close ();
        DataModule1 -> LikvidFDQuery -> ParamByName ("FAC") -> AsSmallInt = nom_fac;
        DataModule1 -> LikvidFDQuery -> ParamByName ("YEAR") -> AsSmallInt = uch_god;
        DataModule1 -> LikvidFDQuery -> Open ();
        break;
    }
}


void __fastcall TPrikaz_LikvidForm::BitBtn3Click (TObject *Sender)
{ // ����� ��������
    int fac_old; // ���������

    // ---------�������� �� ��������
    if (ComboBox4 -> Text == "") { // if ���������
        ShowMessage ("�������� ���������");
        return;
    } // end if ���������
    else {
        // ����� ����������
        fac_old = ComboBox4 -> ItemIndex + 1;
    }
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
    DataModule1 -> People_CaseFDQuery -> ParamByName ("FAC") -> AsSmallInt = fac_old;
    DataModule1 -> People_CaseFDQuery -> ParamByName ("EDU") -> AsSmallInt =
        ComboBox3 -> ItemIndex;
    DataModule1 -> People_CaseFDQuery -> ParamByName ("GR") -> AsSmallInt = inc_gr;
    DataModule1 -> People_CaseFDQuery -> Open ();
    if (DataModule1 -> People_CaseFDQuery -> RecordCount)
    { // if ���� �������� �� ��������� ����������
        // ---�������
        Label7 -> Visible = true;
        DBLookupComboBox1 -> Visible = true;

        // Prikaz_LikvidForm -> Height=Panel1 -> Height+Panel4 -> Height+GroupBox1 -> Height+Panel3 -> Height+hhh;
        hhh_all = Panel1 -> Height + Panel4 -> Height + GroupBox1 -> Height +
            Panel3 -> Height + hhh;
        if (hhh_all > 600)
            Prikaz_LikvidForm -> Height = 600;
        else
            Prikaz_LikvidForm -> Height = hhh_all;

        // ---������ ���������� �������
        Panel6 -> Visible = true;
        Panel6 -> Align = alClient;
        GroupBox1 -> Visible = true;
        // ---������ � ����������
        Panel3 -> Visible = true;

        // ---������� ���������� �������
        DataModule1 -> Type_LikvidFDQuery -> Close ();
        DataModule1 -> Type_LikvidFDQuery -> Open ();

        // ---�������������
        DataModule1 -> SpecializFDQuery -> Close ();
        DataModule1 -> SpecializFDQuery -> ParamByName ("FAC") -> AsInteger = nom_fac;
        DataModule1 -> SpecializFDQuery -> Open ();

    } // end if ���� �������� �� ��������� ����������
    else { // else ��� �� ������ ��������
        // ---�������
        Label7 -> Visible = false;
        DBLookupComboBox1 -> Visible = false;
        // ---������ ���������� �������
        GroupBox1 -> Visible = false;
        Panel6 -> Visible = false;
        // ---������ � ����������
        Panel3 -> Visible = false;

        ShowMessage ("��� ��������� �� �������� ��������");
        return;
    } // end else ��� �� ������ ��������
}


void __fastcall TPrikaz_LikvidForm::RadioGroup6Click (TObject *Sender)
{ // ��������� ������ ������� ��� ��������� ����������
    AnsiString fio = "C������� " + DataModule1 -> LikvidFDQueryFIO -> Value;
    switch (RadioGroup6 -> ItemIndex) { // switch
    case 0: // �������� ����� �������
        fio += " �������� ����� ������� �� ���������� �������?";
        // !!!if (Application -> MessageBox (fio.c_str (), "", MB_YESNO) == mrYes)
        if (MessageDlg (fio.c_str (), mtConfirmation,
            TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
        { // if ����� �������� ������ �� ����������

            // ���������: ��� ���������� �������
            Label6 -> Visible = true;
            Edit2 -> Visible = true;
            Edit2 -> Text = DataModule1 -> LikvidFDQueryPRIKAZ -> Value;

            // �������� ��: ����
            Label8 -> Visible = false;
            DateTimePicker3 -> Visible = false;
            DateTimePicker3 -> DateTime = Now () + 10;
            DateTimePicker3 -> Time = StrToTime ("00:00");
            // ������ � ����������
            Panel3 -> Visible = true;

            // DBGrid1 ������ �����������, ����� �� ���������� �� ��������� ������
            DBGrid1 -> Enabled = false;
            // Prikaz_LikvidForm -> Height=Panel1 -> Height+Panel2 -> Height+Panel3 -> Height+hhh;

            hhh_all = Panel1 -> Height + Panel2 -> Height + Panel3 -> Height + hhh;
            if (hhh_all > 600)
                Prikaz_LikvidForm -> Height = 600;
            else
                Prikaz_LikvidForm -> Height = hhh_all;

        } // end if ����� �������� ������ �� ����������
        else
            RadioGroup6 -> ItemIndex = -1;
        break;
    case 1: // �������� ���������� �������
        fio += " �������� ���������� �������?";
        // !!!if (Application -> MessageBox (fio.c_str (), "", MB_YESNO) == mrYes)
        if (MessageDlg (fio.c_str (), mtConfirmation,
            TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
        { // if ����� �������� ���������� �������
            // �������� ��: ����
            Label8 -> Visible = true;
            DateTimePicker3 -> Visible = true;
            DateTimePicker3 -> DateTime = Now () + 10;
            DateTimePicker3 -> Time = StrToTime ("00:00");
            // ���������: ��� ���������� �������
            Label6 -> Visible = true;
            Edit2 -> Visible = true;
            Edit2 -> Text = "";

            // ������ � ����������
            Panel3 -> Visible = true;

            // Prikaz_LikvidForm -> Height=Panel1 -> Height+Panel2 -> Height+Panel3 -> Height+hhh;
            hhh_all = Panel1 -> Height + Panel2 -> Height + Panel3 -> Height + hhh;
            if (hhh_all > 600)
                Prikaz_LikvidForm -> Height = 600;
            else
                Prikaz_LikvidForm -> Height = hhh_all;

            // DBGrid1 ������ �����������, ����� �� ���������� �� ��������� ������
            DBGrid1 -> Enabled = false;
        } // end if ����� �������� ���������� �������
        else
            RadioGroup6 -> ItemIndex = -1;
        break;
    } // end switch

}


void __fastcall TPrikaz_LikvidForm::FormShow (TObject *Sender) {
    // Prikaz_LikvidForm -> Height=Panel1 -> Height+hhh;
    // Prikaz_LikvidForm -> Top=100;
    // Prikaz_LikvidForm -> Left=50;
    // Prikaz_LikvidForm -> Width=616;

}


void __fastcall TPrikaz_LikvidForm::Button1Click (TObject *Sender) {
    // ���������� ������� ��� �������������� �������

    switch (RadioGroup1 -> ItemIndex)
    { // switch ���������� ������� ��� �������������� �������
    case 0: // ���������� ������� �� ���������� �������
        { // case 0
            // ---�������� �� ��������
            if (DBLookupComboBox1 -> Text == "") { // if �������
                ShowMessage ("�������� ������� �������� ");
                return;
            } // end if �������

            if (DBLookupComboBox2 -> Text == "")
            { // if ������� ��� ���������� �������
                ShowMessage ("�������� ������� ���������� �������");
                return;
            } // end if ������� ��� ���������� �������

            if (RadioGroup3 -> ItemIndex == -1) { // if ��� ��������
                ShowMessage ("�������� ��� ��������");
                return;
            } // end if ��� ��������

            if (RadioGroup4 -> ItemIndex == -1) { // if ����
                ShowMessage ("�������� ���� ��������");
                return;
            } // end if ����

            if (!RadioGroup3 -> ItemIndex && RadioGroup4 -> ItemIndex == 5)
            { // if ���� 6  � ������� ��������
                ShowMessage ("�� ������� ���� �������� �� ����� ���� 6 �����");
                return;
            } // end if ���� 6  � ������� ��������

            if (RadioGroup5 -> ItemIndex == -1) { // if ��������� ��������
                ShowMessage ("�������� ��������� �������� (������ ��� �������)");
                return;
            } // end if ��������� ��������

            if (DBLookupComboBox3 -> Text == "") { // if �������������
                ShowMessage (
                    "�������� �������������, �� ������� ��������� �������");
                return;
            } // end if �������������

            // ���� ��������� �� ������� �������� ���������
            int who = 0;
            int prichina = DBLookupComboBox2 -> KeyValue;
            switch (prichina) {
            case 1: // ������� �� ������ ���������
                who = 4;
                break;
            case 2: // ������� �� ������ ��� ��������
                who = 3;
                break;
            case 3: // ������� �� ������ �������������
                who = 2;
                break;
            default:
                who = 0;
                break;
            }

            DataModule1 -> Prikaz_LikvidFDQuery -> Close ();
            DataModule1 -> Prikaz_LikvidFDQuery -> Open ();
            DataModule1 -> Prikaz_LikvidFDQuery -> Insert ();
            // ����� ��������
            DataModule1 -> Prikaz_LikvidFDQueryNOMER -> Value =
                DBLookupComboBox1 -> KeyValue;

            // ������� ���, ����� �� ��������� ������������� �������
            DataModule1 -> Prikaz_LikvidFDQueryYEAR_UCH -> Value = uch_god;

            // �� ��������� ������ ������� ������� � ����������
            DataModule1 -> Prikaz_LikvidFDQueryPRIKAZ -> Value = Edit1 -> Text;

            // ������ �������� (����������� ��� �����������)
            DataModule1 -> Prikaz_LikvidFDQuerySTATUS_NOMER -> Value =
                DataModule1 -> People_CaseFDQuerySTATUS_PEOPLE -> Value;

            // ���� ��� ��������� ���������� ������� �... � ��....
            DataModule1 -> Prikaz_LikvidFDQueryDATE_C -> Value =
                DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);
            DataModule1 -> Prikaz_LikvidFDQueryDATE_PO -> Value =
                DateTimeToSQLTimeStamp (DateTimePicker2 -> Date);

            // ������� ���������� �������
            DataModule1 -> Prikaz_LikvidFDQueryN_TYPE_LIKVID -> Value =
                DBLookupComboBox2 -> KeyValue;

            // ��������� �� � ����� ���������� �������
            DataModule1 -> Prikaz_LikvidFDQueryFAC_DO -> Value =
                DataModule1 -> People_CaseFDQueryN_FAC -> Value;
            DataModule1 -> Prikaz_LikvidFDQueryFAC_PO -> Value = nom_fac;

            // ��� �������� �� � �����
            DataModule1 -> Prikaz_LikvidFDQueryVID_EDU_DO -> Value =
                DataModule1 -> People_CaseFDQueryVID_EDU -> Value;
            DataModule1 -> Prikaz_LikvidFDQueryVID_EDU_PO -> Value =
                RadioGroup3 -> ItemIndex;

            // ������������� �� � �����
            DataModule1 -> Prikaz_LikvidFDQuerySPECIALIZ_DO -> Value =
                DataModule1 -> People_CaseFDQueryN_SPECIALIZ -> Value;
            DataModule1 -> Prikaz_LikvidFDQuerySPECIALIZ_PO -> Value =
                DBLookupComboBox3 -> KeyValue;

            // ���� �� � �����
            DataModule1 -> Prikaz_LikvidFDQueryKURS_DO -> Value =
                DataModule1 -> People_CaseFDQueryKURS -> Value;
            DataModule1 -> Prikaz_LikvidFDQueryKURS_PO -> Value =
                RadioGroup4 -> ItemIndex + 1;

            // ��������� �������� �� � �����
            DataModule1 -> Prikaz_LikvidFDQueryN_FOUND_DO -> Value =
                DataModule1 -> People_CaseFDQueryN_FOUND -> Value;
            if (RadioGroup5 -> ItemIndex) { // if �������
                DataModule1 -> Prikaz_LikvidFDQueryN_FOUND_PO -> Value = 2;
            } // end if �������
            else { // else   ������
                DataModule1 -> Prikaz_LikvidFDQueryN_FOUND_PO -> Value = 6;
            } // end else   ������

            try { // try ����������
                DataModule1 -> Prikaz_LikvidFDQuery -> ApplyUpdates ();
                DataModule1 -> Prikaz_LikvidFDQuery -> CommitUpdates ();
                ShowMessage ("���������� ������ �������!");

                RadioGroup1 -> ItemIndex = -1;
                // Prikaz_LikvidForm -> Height=Panel1 -> Height+hhh;
                hhh_all = Panel1 -> Height + hhh;
                if (hhh_all > 600)
                    Prikaz_LikvidForm -> Height = 600;
                else
                    Prikaz_LikvidForm -> Height = hhh_all;

                Panel2 -> Visible = false;
                Panel3 -> Visible = false;
                Panel4 -> Visible = false;

                GroupBox1 -> Visible = false;
                Panel6 -> Visible = false;
                DBLookupComboBox2 -> KeyValue = -1;
                DBLookupComboBox3 -> KeyValue = -1;
                Edit1 -> Text = "������ � ";
                DateTimePicker1 -> Date = Now ();
                DateTimePicker1 -> Time = StrToTime ("00:00");
                DateTimePicker2 -> Date = Now () + 10;
                DateTimePicker2 -> Time = StrToTime ("00:00");
                RadioGroup3 -> ItemIndex = -1;
                RadioGroup4 -> ItemIndex = -1;
                RadioGroup5 -> ItemIndex = -1;

                DataModule1 -> People_statusFDQuery -> Close ();
                DataModule1 -> People_statusFDQuery -> SQL -> Text = "SELECT NOMER, STATUS_PEOPLE \
                    FROM PEOPLE \
                where people.nomer = " + DBLookupComboBox1 -> KeyValue +
                    " ORDER BY FAM";
                DataModule1 -> People_statusFDQuery -> Open ();
                DataModule1 -> People_statusFDQuery -> Edit ();
                if (DataModule1 -> People_statusFDQuerySTATUS_PEOPLE -> Value ==
                    2 || DataModule1 -> People_statusFDQuerySTATUS_PEOPLE -> 
                    Value == 3) {
                    DataModule1 -> People_statusFDQuerySTATUS_PEOPLE -> Value = 7;
                }
                DataModule1 -> People_statusFDQuery -> Post ();
                DataModule1 -> People_statusFDQuery -> Close ();
            } // end try ����������
            catch (...) { // catch ������
                // DataModule1 -> Prikaz_LikvidFDQuery -> CancelUpdates ();
                ShowMessage (
                    "��������� ���� ��� ����������. ���������� ��� ���!");

            } // end catch ������
            break;
        } // end case 0
    case 1: // �������������� ������� �� ���������� �������
        DataModule1 -> LikvidFDQuery -> Edit ();
        if (!RadioGroup6 -> ItemIndex) { // if  �������� ����� �������

            DataModule1 -> LikvidFDQueryPRIKAZ -> Value = Edit2 -> Text;

        } // end if  �������� ����� �������
        else { // else �������� ���������� �������
            DataModule1 -> LikvidFDQueryDESCRIBE -> Value =
                DataModule1 -> LikvidFDQueryDESCRIBE -> Value + "�� " +
                DataModule1 -> LikvidFDQueryPRIKAZ -> Value + " ���������� �� " +
                DateToStr (SQLTimeStampToDateTime
                (DataModule1 -> LikvidFDQueryDATE_PO -> Value)) + " ��������� �� " +
                Edit2 -> Text + " �� " + DateToStr (DateTimePicker3 -> Date);
            DataModule1 -> LikvidFDQueryDATE_PO -> Value =
                DateTimeToSQLTimeStamp (DateTimePicker3 -> Date);
        } // end else �������� ���������� �������

        try { // try ����������
            DataModule1 -> LikvidFDQuery -> ApplyUpdates ();
            DataModule1 -> LikvidFDQuery -> CommitUpdates ();
            ShowMessage ("�������������� ������ �������!");

            RadioGroup1 -> ItemIndex = -1;
            RadioGroup6 -> ItemIndex = -1;
            DateTimePicker3 -> Date = Now () + 10;
            DateTimePicker3 -> Time = StrToTime ("00:00");
            Edit2 -> Text = "";

            // Prikaz_LikvidForm -> Height=Panel1 -> Height+hhh;
            hhh_all = Panel1 -> Height + hhh;
            if (hhh_all > 600)
                Prikaz_LikvidForm -> Height = 600;
            else
                Prikaz_LikvidForm -> Height = hhh_all;

            Panel2 -> Visible = false;
            Panel3 -> Visible = false;
            Panel4 -> Visible = false;

            GroupBox1 -> Visible = false;
            Panel6 -> Visible = false;
            DBLookupComboBox2 -> KeyValue = -1;
            DBLookupComboBox3 -> KeyValue = -1;
            Edit1 -> Text = "������ � ";
            DateTimePicker1 -> Date = Now ();
            DateTimePicker1 -> Time = StrToTime ("00:00");
            DateTimePicker2 -> Date = Now () + 10;
            DateTimePicker2 -> Time = StrToTime ("00:00");
            RadioGroup3 -> ItemIndex = -1;
            RadioGroup4 -> ItemIndex = -1;
            RadioGroup5 -> ItemIndex = -1;

        } // end try ����������
        catch (...) { // catch ������
            DataModule1 -> LikvidFDQuery -> CancelUpdates ();
            ShowMessage ("��������� ���� ��� ����������. ���������� ��� ���!");

        } // end catch ������

    } // end switch ���������� ������� ��� �������������� �������

}


void __fastcall TPrikaz_LikvidForm::Edit7KeyPress (TObject *Sender, char &Key) {
    DataModule1 -> Edit_Key (Key);
    // ��� �������, ����� � TEdit ����� ���� ������� ������ �����?
}


void __fastcall TPrikaz_LikvidForm::DateTimePicker1Change (TObject *Sender) {
    DateTimePicker1 -> Time = StrToTime ("00:00");
}


void __fastcall TPrikaz_LikvidForm::DateTimePicker2Change (TObject *Sender) {
    DateTimePicker2 -> Time = StrToTime ("00:00");
}


void __fastcall TPrikaz_LikvidForm::DateTimePicker3Change (TObject *Sender) {
    DateTimePicker3 -> Time = StrToTime ("00:00");
}



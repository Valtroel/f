// ����� ���������� ����������

// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <stdio.h>
#include <math.h>
#include "SportUnit.h"
#include "DataModule.h"
#include "DM2Unit.h"
// ---------------------------------------------------------------------------
#pragma package (smart_init)
// !!!#pragma link "ToolEdit"
#pragma resource "*.dfm"

int nom_sport;
// ���������� ��� ����������� ������ ������ ��� ������ �������� � ����
int nom;
// ���������� ��� ����������� ������ �������� ��� ������ �������� � ����

int SportOpen = 0; // ����������� ����������
TSportForm *SportForm;

// ---------------------------------------------------------------------------
__fastcall TSportForm::TSportForm (TComponent* Owner) : TForm (Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TSportForm::FormActivate (TObject *Sender)
    // ��� ����������� �����
{
    DataModule1 -> SportFDQuery -> Close ();
    // �������� Query ��� ��������� ����������
    DataModule1 -> SportFDQuery -> Params -> Items[0] -> AsInteger =
        DataModule1 -> PeopleFDQueryNOMER -> Value;
    DataModule1 -> SportFDQuery -> Open (); // ���������� �������
    SportOpen = 1; // ��� �����������, ��� ����� �������
}

// ---------------------------------------------------------------------------
void __fastcall TSportForm::FormDeactivate (TObject *Sender)
    // ��� �������� �����
{
    SportOpen = 0; // ��� �����������, ��� ����� �������
}

// ---------------------------------------------------------------------------
void __fastcall TSportForm::FormClose (TObject *Sender, TCloseAction &Action) {
    Action = caFree;
}
// ---------------------------------------------------------------------------

void __fastcall TSportForm::RadioGroup1Click (TObject *Sender) {
    // ----�������� ���� ����������� �� Panel2

    DBLookupComboBox3 -> KeyValue = -1; // ��� ������
    ComboBox3 -> Items -> Clear (); // ��������� ��������� ��� ���������� ������
    ComboBox3 -> ItemIndex = -1;
    Edit1 -> Text = ""; // � �������
    Edit2 -> Text = ""; // ��� �������� ���������� ������
    DateTimePicker1 -> Date = Now (); // ���� �������
    DateTimePicker1 -> Time = StrToTime ("00:00");
    // -----

    if (RadioGroup1 -> ItemIndex) { // ���� ���������� ��������� ���������
        Label7 -> Caption = "��������� ���������";
        ComboBox3 -> Items -> Add ("����� �� ������");
        ComboBox3 -> Items -> Add ("����� 1 ���������");
        ComboBox3 -> Items -> Add ("����� ������������ ���������");
        ComboBox3 -> Items -> Add ("����� ������ ������������ ���������");
        ComboBox3 -> Items -> Add ("����� ������������� ���������");
    } // end if
    else { // ���� ���������� ����������� �������
        Label7 -> Caption = "���������� ������";
        // -----��������� ����� ������ � ComboBox
        DM2 -> CategoryFDTable -> First ();
        for (int i = 0; i < DM2 -> CategoryFDTable -> RecordCount; i++) { // for
            ComboBox3 -> Items -> Add
                (DM2 -> CategoryFDTableTEXT_SPORT_CATEGORY -> Value);
            DM2 -> CategoryFDTable -> Next ();
        } // end for
    } // end else
    Panel2 -> Visible = true;

}
// ---------------------------------------------------------------------------

void __fastcall TSportForm::BitBtn3Click (TObject *Sender) {
    // �������� �� ������ ��������� �� ����� ���������� ����������
    if ( (DBLookupComboBox3 -> Text != "") && (ComboBox3 -> Text != "")) { // if

        nom_sport = DBLookupComboBox3 -> KeyValue; // ���������� ����� ���� ������
        nom = DataModule1 -> PeopleFDQueryNOMER -> Value;
        // ��������� � ���������� ������ �������� ��������

        Set<TLocateOption, 0, 1>Flags; // ��������� ����� ��� ������
        bool found = DataModule1 -> SportFDQuery -> Locate ("NOMER;N_VID_SPORT",
            VarArrayOf (OPENARRAY (Variant, (nom, nom_sport))), Flags);
        /* � ����������
         ��������� ��������� ������ ���� �� � �� ������ � ������� nom �
         ����� ������ nom_sport */
        if (!found) { // if Insert
            // ���� �� ������ �� �������

            DataModule1 -> SportFDQuery -> Insert ();
            // Query ��������� � ����� �������

            DataModule1 -> SportFDQueryNOMER -> Value = nom;
            // � SportFDQuery ��������� ����� �������� ��������

            DataModule1 -> SportFDQueryN_VID_SPORT -> Value = nom_sport;
            // � SportFDQuery ��������� ����� ���� ������
            if (RadioGroup1 -> ItemIndex) { // if ��������� ���������

                DataModule1 -> SportFDQuerySUD_CATEGORY -> Value =
                    ComboBox3 -> ItemIndex + 1; /* ���������
                 �������� ��  ComboBox- � � �� */
                DataModule1 -> SportFDQuerySPORT_CATEGORY -> Value = 12;
                // ������� ����� ���������� ������ - ���,
                // �.�. ��� ���� �������� ������������ � ����
                if (Edit1 -> Text != "")
                    DataModule1 -> SportFDQueryN_PRIKAZ_SUD -> Value =
                        Edit1 -> Text.ToInt ();
                DataModule1 -> SportFDQueryD_PRIKAZ_SUD -> Value =
                    DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);
                if (Edit2 -> Text != "")
                    DataModule1 -> SportFDQueryWHO_GIVE_SUD -> Value = Edit2 -> Text;

            } // end if  ��������� ���������
            else { // else ���������� ������
                Variant sport_r =
                    DM2 -> CategoryFDTable -> Lookup ("TEXT_SPORT_CATEGORY",
                    ComboBox3 -> Text, "SPORT_CATEGORY");
                if (!sport_r.IsNull ())
                    DataModule1 -> SportFDQuerySPORT_CATEGORY -> Value =
                        sport_r.AsType (varInteger);
                else {
                    ShowMessage (
                        "��������� ������������ ��������� ������ �� ����������� �������!");
                    return;
                }
                if (Edit1 -> Text != "")
                    DataModule1 -> SportFDQueryN_PRIKAZ_SPORT -> Value =
                        Edit1 -> Text.ToInt ();
                DataModule1 -> SportFDQueryD_PRIKAZ_SPORT -> Value =
                    DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);
                if (Edit2 -> Text != "")
                    DataModule1 -> SportFDQueryWHO_GIVE -> Value = Edit2 -> Text;
            } // end else ���������� ������

        } // end if Insert
        else { // else Edit
            DataModule1 -> SportFDQuery -> Edit ();
            // ����� Query ��������� � ����� ��������������
            if (RadioGroup1 -> ItemIndex) { // if ��������� ���������

                DataModule1 -> SportFDQuerySUD_CATEGORY -> Value =
                    ComboBox3 -> ItemIndex + 1; /* ���������
                 �������� ��  ComboBox- � � �� */

                if (Edit1 -> Text != "")
                    DataModule1 -> SportFDQueryN_PRIKAZ_SUD -> Value =
                        Edit1 -> Text.ToInt ();
                DataModule1 -> SportFDQueryD_PRIKAZ_SUD -> Value =
                    DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);
                if (Edit2 -> Text != "")
                    DataModule1 -> SportFDQueryWHO_GIVE_SUD -> Value = Edit2 -> Text;

            } // end if  ��������� ���������
            else { // else ���������� ������
                Variant sport_r =
                    DM2 -> CategoryFDTable -> Lookup ("TEXT_SPORT_CATEGORY",
                    ComboBox3 -> Text, "SPORT_CATEGORY");
                if (!sport_r.IsNull ())
                    DataModule1 -> SportFDQuerySPORT_CATEGORY -> Value =
                        sport_r.AsType (varInteger);
                else {
                    ShowMessage (
                        "��������� ������������ ��������� ������ �� ����������� �������!");
                    return;
                }
                if (Edit1 -> Text != "")
                    DataModule1 -> SportFDQueryN_PRIKAZ_SPORT -> Value =
                        Edit1 -> Text.ToInt ();
                DataModule1 -> SportFDQueryD_PRIKAZ_SPORT -> Value =
                    DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);
                if (Edit2 -> Text != "")
                    DataModule1 -> SportFDQueryWHO_GIVE -> Value = Edit2 -> Text;
            } // end else ���������� ������

        } // end else Edit

        DataModule1 -> SportFDQuery -> ApplyUpdates ();
        DataModule1 -> SportFDQuery -> CommitUpdates ();
    } // end if
    else { // else �������� �� ���� ������
        if (RadioGroup1 -> ItemIndex)
            ShowMessage (
            "������� ������ �� ���� ������ ��� ��������� ���������!");
        else
            ShowMessage (
            "������� ������ �� ���� ������ ��� ����������� �������!");
    } // end else �������� �� ���� ������
    RadioGroup1 -> ItemIndex = -1;
    Panel2 -> Visible = false;
}
// ---------------------------------------------------------------------------

void __fastcall TSportForm::BitBtn4Click (TObject *Sender) {
    // �������� �� ������ ��������
    DataModule1 -> SportFDQuery -> CancelUpdates ();
    Panel2 -> Visible = false;
    RadioGroup1 -> ItemIndex = -1;
}
// ---------------------------------------------------------------------------

void __fastcall TSportForm::BitBtn1Click (TObject *Sender) {
    // ��� ������� �� ������ �������
    // �������� �����
    Close ();
}
// ---------------------------------------------------------------------------

void __fastcall TSportForm::BitBtn2Click (TObject *Sender) {
    // �������� �� ������ �������
    AnsiString box_sport =
        "�������� " + DataModule1 -> SportFDQueryVID_SPORT1 -> Value +
        AnsiString (" ") + DataModule1 -> SportFDQuerySPORT_CATEGORY1 -> Value;
    // !!!if (Application -> MessageBox (box_sport.c_str (),"������� ��������� ������ ?", MB_YESNO)== IDYES)
    if (MessageDlg (box_sport.c_str (), mtConfirmation,
        TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes) { // �������� ��������� ������
        DataModule1 -> SportFDQuery -> Delete ();
        DataModule1 -> SportFDQuery -> ApplyUpdates ();
        DataModule1 -> SportFDQuery -> CommitUpdates ();
    }
}
// ---------------------------------------------------------------------------

void __fastcall TSportForm::Edit1KeyPress (TObject *Sender, char &Key) {
    DataModule1 -> Edit_Key (Key);
    // ��� �������, ����� � TEdit ����� ���� ������� ������ �����?
}
// ---------------------------------------------------------------------------
void __fastcall TSportForm::DateTimePicker1Change (TObject *Sender)
{
DateTimePicker1 -> Time = StrToTime ("00:00");
}
//---------------------------------------------------------------------------


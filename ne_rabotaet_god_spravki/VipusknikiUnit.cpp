// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "VipusknikiUnit.h"
#include "DataModule.h"
#include "DM2Unit.h"
#include "DM3Unit.h"
#include "func.h"
#include "FileCtrl.hpp";
// ---------------------------------------------------------------------------
#pragma package (smart_init)
// !!!#pragma link "ToolEdit"
// !!!#pragma link "RXSpin"
#pragma resource "*.dfm"
TVipusknikiForm *VipusknikiForm;

AnsiString *mas_specializ[2]; // ������ ������� � �������� �������������
bool m_s = false; // ���������� �������� �� �������� �������
int rec_q = 0; // ���-�� ������������ � ��������� � ������� �������
int rec_q_2 = 0; // ���-�� ������������ � ��������� � ������� �������
int rec_z = 0; // ���������� �������
TFDQuery *d; // ������
TFDQuery *dip_vip;
Variant ExApp;
Variant ExApp1;
Variant ExApp2;
Variant WSheet1;
Variant WSheet2;
Variant WBook1;
Variant WBook2;
AnsiString n_file = ""; // �������� �����
String InFolderName;

// ---------------------------------------------------------------------------
__fastcall TVipusknikiForm::TVipusknikiForm (TComponent* Owner) : TForm (Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::Form_min () { // ������� ���������� �����

    if (Panel2 -> Visible) {
        Panel2 -> Visible = false;
        CheckBox1 -> Checked = false;
        VipusknikiForm -> Height = Panel1 -> Height + 28;

        if (VipusknikiForm -> Position != poMainFormCenter)
            VipusknikiForm -> Position = poMainFormCenter;
    }
}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::Form_max () { // ������� ���������� �����

    if (!Panel2 -> Visible) {
        Panel2 -> Visible = true;

        VipusknikiForm -> Height = 500;

        if (VipusknikiForm -> Position != poMainFormCenter)
            VipusknikiForm -> Position = poMainFormCenter;
        Edit3 -> SetFocus ();
    }
}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::ShowDiplom ()
{ // ������� ������ ������ �� �������

    // � ��������
    if (!DM3 -> EditDiplomFDQueryN_PROTOKOL -> AsVariant.IsNull ())
        Edit1 -> Text = AnsiString (DM3 -> EditDiplomFDQueryN_PROTOKOL -> Value);
    else if (!CheckBox2 -> Checked)
        Edit1 -> Text = "";
    // ���� ���������
    if (!DM3 -> EditDiplomFDQueryD_PROTOKOL -> AsVariant.IsNull ())
        DateTimePicker1 -> Date =
            SQLTimeStampToDateTime (DM3 -> EditDiplomFDQueryD_PROTOKOL -> Value);
    else if (!CheckBox2 -> Checked)
        DateTimePicker1 -> Date = Now ();
    DateTimePicker1 -> Time = StrToTime ("00:00");

    // � �������
    if (!DM3 -> EditDiplomFDQueryN_DIPLOM -> AsVariant.IsNull ())
        Edit2 -> Text = DM3 -> EditDiplomFDQueryN_DIPLOM -> Value;
    else
        Edit2 -> Text = "";
    // ����� �������
    if (!DM3 -> EditDiplomFDQuerySERIA -> AsVariant.IsNull ())
        Edit5 -> Text = DM3 -> EditDiplomFDQuerySERIA -> Value;
    else
        Edit2 -> Text = "";
    // ������ � �������
    if (!DM3 -> EditDiplomFDQueryNOM_DIPLOM -> AsVariant.IsNull ())
        Edit6 -> Text = DM3 -> EditDiplomFDQueryNOM_DIPLOM -> Value;
    else
        Edit2 -> Text = "";

    // ���� �������
    if (!DM3 -> EditDiplomFDQueryD_VIPUSK -> AsVariant.IsNull ())
        DateTimePicker2 -> Date =
            SQLTimeStampToDateTime (DM3 -> EditDiplomFDQueryD_VIPUSK -> Value);
    else if (!CheckBox2 -> Checked)
        DateTimePicker2 -> Date = Now ();
    DateTimePicker2 -> Time = StrToTime ("00:00");

    // QUALIFICATION
    ListBox1 -> Clear ();
    AnsiString Qua = DM3 -> EditDiplomFDQueryQUALIFICATION -> Value;
    if (Qua != "") { // if DM3 -> EditDiplomQUALIFICATION -> Value ���� ��������
        AnsiString qa_n = "";

        for (int i = 1; i <= Qua.Length (); i++) { // for �� Qua
            if (Qua.SubString (i, 1) != ",") { // if Qua!=","
                qa_n = qa_n + Qua.SubString (i, 1);
                if (i == Qua.Length ()) {
                    for (int j = 0; j < rec_q; j++) { // for �� j
                        if (qa_n == mas_specializ[0][j])
                            ListBox1 -> Items -> Add (mas_specializ[1][j]);
                    } // end for �� j
                    qa_n = "";
                }
            } // end if Qua!=","
            else { // else Qua==","
                for (int j = 0; j < rec_q; j++) { // for �� j
                    if (qa_n == mas_specializ[0][j])
                        ListBox1 -> Items -> Add (mas_specializ[1][j]);
                } // end for �� j
                qa_n = "";
            } // end else Qua==","
        } // end  for �� Qua
    } // end if DM3 -> EditDiplomQUALIFICATION -> Value ���� ��������
}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::FormClose (TObject *Sender,
    TCloseAction &Action) {
    // �������� �����, ��� ���-�� ��� �������������� � ��������
    TRect r1, r2;
    r1 = Rect (Left + Width / 2, Top + Height / 2, Left + Width / 2,
        Top + Height / 2);
    r2 = BoundsRect;
    DrawAnimatedRects (Handle, IDANI_CAPTION, &r2, &r1);
    // �������� ������ ������������������ ��������� ����������

    if (m_s) { // if true - ���� ������� ������
        for (int i = 0; i < 2; i++)
            delete[]mas_specializ[i];
        // delete[]mas_specializ;
        m_s = false;
    }

    Action = caFree;
}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::Edit1KeyPress (TObject *Sender, char &Key) {
    DataModule1 -> Edit_Key (Key);
    // ��� �������, ����� � TEdit ����� ���� ������� ������ �����?
}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::FormActivate (TObject *Sender) {
    UpDown1 -> Position = uch_god;
    Edit4 -> Text = AnsiString (uch_god);

    DM3 -> QUALIFICFDQuery -> Open ();
    DM3 -> QUALIFICFDQuery2 -> Open ();

    ////������������
    DM3 -> QUALIFICFDQuery -> First ();
    DM3 -> QUALIFICFDQuery2 -> First ();
    rec_q = DM3 -> QUALIFICFDQuery -> RecordCount;
    rec_q_2 = DM3 -> QUALIFICFDQuery2 -> RecordCount;
    if (m_s) { // if true - ���� ������� ������
        for (int i = 0; i < 2; i++)
            delete[]mas_specializ[i];
        // delete[]mas_specializ;
        m_s = false;
    }

    // �������� ������� ������� � �������� �������������
    for (int i = 0; i < 2; i++)
        mas_specializ[i] = new AnsiString[rec_q];
    m_s = true; // ���������� �������� �� �������� �������

    ListBox2 -> Clear ();

    for (int i = 0; i < rec_q; i++) { // for ��������� ������
        mas_specializ[0][i] =
            AnsiString (DM3 -> QUALIFICFDQueryNOMER_QU -> Value); // ���������
        mas_specializ[1][i] = DM3 -> QUALIFICFDQueryNAME -> Value; // ��������
        ListBox2 -> Items -> Add (mas_specializ[1][i]);

        DM3 -> QUALIFICFDQuery -> Next ();
    } // end for ��������� ������

}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::BitBtn1Click (TObject *Sender) {
    /* // ��������
     if (RadioGroup1 -> ItemIndex == -1) {
     ShowMessage ("������� ����� ��������!");
     return;
     }

     DM3 -> VipusknikiFDQuery -> Close ();
     DM3 -> VipusknikiFDQuery -> ParamByName ("FAC") -> AsSmallInt = nom_fac;
     DM3 -> VipusknikiFDQuery -> ParamByName ("EDU") -> AsSmallInt =
     RadioGroup1 -> ItemIndex;
     DM3 -> VipusknikiFDQuery -> ParamByName ("D") -> AsString =
     "%" + Edit4 -> Text + "%";
     // DM3 -> VipusknikiFDQuery -> ParamByName ("D") -> AsString = "%" + Edit4 -> Text;
     DM3 -> VipusknikiFDQuery -> Open ();

     if (DM3 -> VipusknikiFDQuery -> RecordCount) { // if ���� ������
     DM3 -> EditDiplomFDQuery -> Open ();
     Form_max (); // ������� ���������� �����
     Edit3 -> Text = "";
     Edit3 -> SetFocus ();
     CheckBox2 -> Checked = false;
     }
     else { // else ��� �������
     Form_min (); // ������� ���������� �����
     DM3 -> VipusknikiFDQuery -> Close ();
     ShowMessage ("��� ������ �� �������� ���������!");
     }


     // �������� �����������   StringGrid
     if (!Clear_StringGrid ())
     return; */

    d = DM3 -> VipusknikiFDQuery;
    d -> Close ();
    d -> SQL -> Clear ();
    // ���
    d -> SQL -> Add ("SELECT PEOPLE.NOMER, PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH, PEOPLE.VID_EDU, PEOPLE.N_FAC, \
 PEOPLE.N_SPEC, PEOPLE.N_SPECIALIZ, PEOPLE.D_PRIKAZ_KURS, PEOPLE.STATUS_PEOPLE,\
PEOPLE.D_PRIKAZ_INCLUDE    \
   FROM   DIPLOMA  \
   INNER JOIN  PEOPLE ON (PEOPLE.NOMER = DIPLOMA.NOMER)\
   left join personal_docum on (people.nomer = personal_docum.nomer)\
   WHERE");

    if (RadioGroup1 -> ItemIndex == 0)
        // ���� �������
    {
        d -> SQL -> Add (" PEOPLE.VID_EDU=0 and ");
    }
    if (RadioGroup1 -> ItemIndex == 1)
        // ���� �������
    {
        d -> SQL -> Add (" PEOPLE.VID_EDU=1 and ");
    }

    d -> SQL -> Add ("     PEOPLE.N_FAC = " + IntToStr (nom_fac));

    if (RadioGroup3 -> ItemIndex == 0) {
        d -> SQL -> Add (" and diploma.D_VIPUSK between '" + DateTimeToStr
            (DateTimePicker3 -> DateTime) + "' and '" + DateTimeToStr
            (DateTimePicker4 -> DateTime) + "'");
    }
    if (RadioGroup3 -> ItemIndex == 1) {
        d -> SQL -> Add (" and diploma.D_VIPUSK between '01.01." + Edit4 -> Text +
            "' and '31.12." + Edit4 -> Text + "'");
    }

    d -> SQL -> Add (" order by  PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH");

    d -> Open ();

    rec_z = d -> RecordCount;

    if (!rec_z) {
        ShowMessage ("��� ���������� �� ��������� ���������!");
        d -> Close ();
        Form_min ();
        return;
    }

    Form_max ();
}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::DBGrid1CellClick (TColumn *Column) {
    if (Panel3 -> Visible)
        ShowDiplom ();
}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::SpeedButton1Click (TObject *Sender) { // �����
    for (int i = 0; i < ListBox1 -> Items -> Count; i++) {
        if (ListBox1 -> Selected[i] && i) {
            ListBox1 -> Items -> Move (ListBox1 -> ItemIndex, i - 1);
        }
    }

}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::SpeedButton2Click (TObject *Sender) { // ����
    for (int i = 0; i < ListBox1 -> Items -> Count; i++) {
        if (ListBox1 -> Selected[i] && i != ListBox1 -> Items -> Count - 1) {
            ListBox1 -> Items -> Move (ListBox1 -> ItemIndex, i + 1);
        }
    }
}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::SpeedButton3Click (TObject *Sender)
{ // ������ ���������
    for (int i = 0; i < ListBox1 -> Items -> Count; i++) {
        if (ListBox1 -> Selected[i]) {
            ListBox1 -> Items -> Delete (i);
        }
    }
}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::SpeedButton4Click (TObject *Sender)
{ // �������� ���������
    for (int i = 0; i < ListBox2 -> Items -> Count; i++) {
        if (ListBox2 -> Selected[i]) {
            bool search = false;
            for (int j = 0; j < ListBox1 -> Items -> Count; j++) {
                if (ListBox1 -> Items -> Strings[j] == ListBox2 -> Items -> Strings[i])
                    search = true;
            }
            if (!search)
                ListBox1 -> Items -> Add (ListBox2 -> Items -> Strings[i]);
        }
    }
}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::DBGrid1KeyDown (TObject *Sender, WORD &Key,
    TShiftState Shift) {
    if (Panel3 -> Visible)
        ShowDiplom ();
}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::CheckBox1Click (TObject *Sender) {
    if (CheckBox1 -> Checked) { // if �������� �������� ���������� �� �������
        Panel3 -> Visible = true;
        Splitter2 -> Visible = true;
        ShowDiplom ();
    }
    else {
        Splitter2 -> Visible = false;
        Panel3 -> Visible = false;
    }
}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::RadioGroup1Click (TObject *Sender) {
    Form_min (); // ������� ���������� �����
}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::UpDown1Click (TObject *Sender,
    TUDBtnType Button) {
    Form_min (); // ������� ���������� �����
}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::Edit3Change (TObject *Sender) {
    Set<TLocateOption, 0, 1>flags;
    flags << loCaseInsensitive << loPartialKey;
    DM3 -> VipusknikiFDQuery -> Locate ("FAM", Edit3 -> Text, flags);
}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::FormCreate (TObject *Sender) {
    // ��������� �����, ��� ���-�� ��� �������������� �� ��������
    TRect r1, r2;
    r1 = Rect (Left + Width / 2, Top + Height / 2, Left + Width / 2,
        Top + Height / 2);
    r2 = BoundsRect;
    DrawAnimatedRects (Handle, IDANI_CAPTION, &r1, &r2);

}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::BitBtn2Click (TObject *Sender)
{ // ������ ���������

    // ��������
    if (Edit1 -> Text == "") {
        ShowMessage ("������� � � ���� ���������!");
        return;
    }

    if (Edit5 -> Text == "" || Edit6 -> Text == "") {
        ShowMessage ("������� � ������� � ���� �������!");
        return;
    }

    if (ListBox1 -> Items -> Count != 2) {
        ShowMessage ("��������� ������������ ��������� ������������!");
        return;
    }

    AnsiString qualif = "";
    for (int i = 0; i < ListBox1 -> Items -> Count; i++)
    { // for �� ListBox1 -> Items -> Count
        for (int j = 0; j < rec_q; j++) { // for �� rec_q
            if (ListBox1 -> Items -> Strings[i] == mas_specializ[1][j])
                qualif += mas_specializ[0][j] + ",";
        } // end for �� rec_q
    } // end for �� ListBox1 -> Items -> Count

    if (qualif != "")
        qualif = qualif.SubString (1, qualif.Length () - 1);
    else {
        ShowMessage (
            "��������� ���� ��� ���������� ������������\n���������� �� ����������!");
        return;
    }

    if (DM3 -> EditDiplomFDQuery -> RecordCount)
        DM3 -> EditDiplomFDQuery -> Edit ();
    else
        DM3 -> EditDiplomFDQuery -> Insert ();

    DM3 -> EditDiplomFDQueryNOMER -> Value = DM3 -> VipusknikiFDQueryNOMER -> Value;
    DM3 -> EditDiplomFDQueryN_PROTOKOL -> Value = Edit1 -> Text.ToInt (); // � ��������
    DM3 -> EditDiplomFDQueryD_PROTOKOL -> Value =
        DateTimeToSQLTimeStamp (DateTimePicker1 -> Date); // ���� ���������
    DM3 -> EditDiplomFDQuerySERIA -> Value = Edit5 -> Text; // ����� �������
    DM3 -> EditDiplomFDQueryNOM_DIPLOM -> Value = Edit6 -> Text;
    // ������ ����� �������
    AnsiString text = "";
    if (DM3 -> EditDiplomFDQueryTYPE_DIPLOM -> Value == 2)
        text = "� �������� ";

    DM3 -> EditDiplomFDQueryN_DIPLOM -> Value = text + Edit5 -> Text + " �" +
        Edit6 -> Text;
    // � �������
    DM3 -> EditDiplomFDQueryD_VIPUSK -> Value =
        DateTimeToSQLTimeStamp (DateTimePicker2 -> Date);
    // ���� �������
    DM3 -> EditDiplomFDQueryQUALIFICATION -> Value = qualif; // ������������

    try {
        DM3 -> EditDiplomFDQuery -> ApplyUpdates ();
        DM3 -> EditDiplomFDQuery -> CommitUpdates ();
        DM3 -> EditDiplomFDQuery -> Close ();
        DM3 -> EditDiplomFDQuery -> Open ();
        ShowMessage ("���������� ������ �������");
        DBGrid1 -> SetFocus ();
        if (Panel3 -> Visible)
            ShowDiplom ();
    }
    catch (...) {
        DM3 -> EditDiplomFDQuery -> CancelUpdates ();
        ShowMessage ("��������� ���� ��� ����������!\n���������� ��� ���.");
    }

}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::DBGrid1DblClick (TObject *Sender) {
    CheckBox1 -> Checked = true;
}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::Panel9CanResize (TObject *Sender, int &NewWidth,
    int &NewHeight, bool &Resize) {
    if (NewHeight > 141)
        BitBtn2 -> Top = NewHeight - 37;
    else
        BitBtn2 -> Top = 104;
}
// ---------------------------------------------------------------------------

void __fastcall TVipusknikiForm::ApplicationEvents1Message (tagMSG &Msg,
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

void __fastcall TVipusknikiForm::Panel9DblClick (TObject *Sender) {
    if (BitBtn2 -> Visible)
        BitBtn2 -> Visible = false;
    else
        BitBtn2 -> Visible = true;

}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::DateTimePicker2Change (TObject *Sender) {
    DateTimePicker2 -> Time = StrToTime ("00:00");
}
// ---------------------------------------------------------------------------

void __fastcall TVipusknikiForm::DateTimePicker1Change (TObject *Sender) {
    DateTimePicker1 -> Time = StrToTime ("00:00");
}
// ---------------------------------------------------------------------------

void __fastcall TVipusknikiForm::RadioGroup3Click (TObject *Sender) {
    if (RadioGroup1 -> ItemIndex) {
        Panel10 -> Visible = false;
        Panel11 -> Visible = true;
    }
    else {
        Panel10 -> Visible = true;
        Panel11 -> Visible = false;
    }
}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::BitBtn3Click (TObject *Sender) {
    /* if (!CheckBox1 -> Checked) {
     ShowMessage ("������� ���� ����������!");
     return;
     } */

    // Label8 -> Caption = "����������� ������";
    dip_vip = DataModule1 -> StatementDiplomFDQuery;
    dip_vip -> Close ();
    dip_vip -> SQL -> Clear ();
    dip_vip -> SQL -> Add ("SELECT  People.NOMER, PEOPLE.FAM, PEOPLE.NAME, \
            PEOPLE.OTCH, personal_docum.personal_number, DIPLOMA.UROVEN, \
            PEOPLE.D_INCLUDE, PEOPLE.D_PRIKAZ_KURS, DIPLOMA.TYPE_DIPLOM, \
            DIPLOMA.SERIA, DIPLOMA.NOM_DIPLOM, DIPLOMA.REGISTRATION, \
            DIPLOMA.D_VIPUSK, speciality.code_spec, speciality.spec_reg, \
            specializ.special_direction, DIPLOMA.QUALIFICATION, \
            PEOPLE.n_specializ, PEOPLE.VID_EDU, specializ.special_direction_sokr \
        FROM DIPLOMA \
            INNER JOIN  PEOPLE \
            ON (PEOPLE.NOMER = DIPLOMA.NOMER) \
            inner join specializ \
            on (specializ.n_specializ = people.n_specializ) \
            inner join speciality \
            on (people.n_spec = speciality.n_spec) \
            left join personal_docum \
            on (people.nomer = personal_docum.nomer) \
        WHERE");

    if (RadioGroup1 -> ItemIndex == 0)
        // ���� �������
    {
        dip_vip -> SQL -> Add (" PEOPLE.VID_EDU=0 and ");
    }
    if (RadioGroup1 -> ItemIndex == 1)
        // ���� �������
    {
        dip_vip -> SQL -> Add (" PEOPLE.VID_EDU=1 and ");
    }

    dip_vip -> SQL -> Add ("     PEOPLE.N_FAC = " + IntToStr (nom_fac));

    if (RadioGroup3 -> ItemIndex == 0) {
        dip_vip -> SQL -> Add (" and D_VIPUSK between '" + DateTimeToStr
            (DateTimePicker3 -> DateTime) + "' and '" + DateTimeToStr
            (DateTimePicker4 -> DateTime) + "'");
    }
    if (RadioGroup3 -> ItemIndex == 1) {
        dip_vip -> SQL -> Add (" and D_VIPUSK between '01.01." + Edit4 -> Text +
            "' and '31.12." + Edit4 -> Text + "'");
    }

    dip_vip -> SQL -> Add (" order by  PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH");
    dip_vip -> Open ();

    int col_row = dip_vip -> RecordCount;

    ProgressBar1 -> Max = col_row;

    // Label8 -> Caption = "���������� � excel";

    // ������� ��� ����� � ������� ������
    int x = 1;
    // ������� ��� ����� ��� ������ �����
    int y = 1;

    bool flag = false;
    // ��������� ����������

    for (int i = 1; i <= col_row; i++) { // for1
        if (dip_vip -> Fields -> FieldByName ("PERSONAL_NUMBER")
             -> Value != "" && !dip_vip -> Fields -> FieldByName ("D_INCLUDE")
             -> Value.IsNull () && !dip_vip -> Fields -> FieldByName ("D_PRIKAZ_KURS")
             -> Value.IsNull () && dip_vip -> Fields -> FieldByName ("TYPE_DIPLOM")
             -> Value >= 0 && dip_vip -> Fields -> FieldByName ("TYPE_DIPLOM")
             -> Value <= 11 && dip_vip -> Fields -> FieldByName ("SERIA")
             -> Value != "" && dip_vip -> Fields -> FieldByName ("NOM_DIPLOM")
             -> Value != "" && dip_vip -> Fields -> FieldByName ("REGISTRATION")
             -> Value != "" && !dip_vip -> Fields -> FieldByName ("D_VIPUSK")
             -> Value.IsNull () && dip_vip -> Fields -> FieldByName ("CODE_SPEC")
             -> Value != "" && dip_vip -> Fields -> FieldByName ("SPEC_REG")
             -> Value != "" && dip_vip -> Fields -> FieldByName ("SPECIAL_DIRECTION_SOKR")
             -> Value != "" && dip_vip -> Fields -> FieldByName ("QUALIFICATION")
             -> Value != "") {
            if (!flag) {
                flag = true;
                ExApp1 = Variant::CreateObject ("Excel.Application");
                WBook1 = NewBook (ExApp1);
                WSheet1 = SelectSheet (WBook1, "����1");

                SetOrientatSheet (WSheet1, 2);
                columnWidth (WSheet1);
                // OVisible (ExApp1);
            }
            if (flag) {
                // ��� ������ �����
                writeExcel (WSheet1, dip_vip, y);
                y++;
                ProgressBar1 -> StepBy (1);
            }
        }
        dip_vip -> Next ();
    } // end for2

    if (y != 1) // ����������
    {
        AnsiString file_s1 = Edit7 -> Text + "\\������� �� ������� " +
            getFac (nom_fac) + " " + getForm (RadioGroup1 -> ItemIndex) + " " +
            getPeriod (RadioGroup3 -> ItemIndex) + " " + n_file + ".xls";
        try {
            SaveBookAs (WBook1, file_s1.c_str ());

            ExApp1.OlePropertyGet ("WorkBooks", 1).OleProcedure ("Close");
            ExApp1.OleProcedure ("Quit");
            ExApp1.Clear ();
            WSheet1.Clear ();
        }
        catch (...) {
            ShowMessage ("��������� ���� �������������� �� �������.\n \
     �������� ��� ��������������!");
        }
    }

    if (y - 1 == col_row) {
        dip_vip -> Close ();
        ProgressBar1 -> Position = 0;
        ShowMessage ("���������� � ���� ��������");
        return;
    }

    flag = false;

    dip_vip -> First ();
    for (int i = 1; i <= col_row; i++) { // for1
        if (dip_vip -> Fields -> FieldByName ("PERSONAL_NUMBER") -> Value == "" ||
            dip_vip -> Fields -> FieldByName ("D_INCLUDE") -> Value.IsNull () ||
            dip_vip -> Fields -> FieldByName ("D_PRIKAZ_KURS") -> Value.IsNull () ||
            ! (dip_vip -> Fields -> FieldByName ("TYPE_DIPLOM") -> Value >=
            0 && dip_vip -> Fields -> FieldByName ("TYPE_DIPLOM") -> Value <= 11) ||
            dip_vip -> Fields -> FieldByName ("SERIA") -> Value == "" ||
            dip_vip -> Fields -> FieldByName ("NOM_DIPLOM") -> Value == "" ||
            dip_vip -> Fields -> FieldByName ("REGISTRATION") -> Value == "" ||
            dip_vip -> Fields -> FieldByName ("D_VIPUSK") -> Value.IsNull () ||
            dip_vip -> Fields -> FieldByName ("CODE_SPEC") -> Value == "" ||
            dip_vip -> Fields -> FieldByName ("SPEC_REG") -> Value == "" ||
            dip_vip -> Fields -> FieldByName ("SPECIAL_DIRECTION_SOKR") -> Value == "" ||
            dip_vip -> Fields -> FieldByName ("QUALIFICATION") -> Value == "") {
            if (!flag) {
                flag = true;
                ExApp2 = Variant::CreateObject ("Excel.Application");
                WBook2 = NewBook (ExApp2);
                WSheet2 = SelectSheet (WBook2, "����1");

                SetOrientatSheet (WSheet2, 2);
                columnWidth (WSheet2);
            }
            if (flag) {
                // ���� ������ ����
                writeExcel (WSheet2, dip_vip, x);
                x++;
                ProgressBar1 -> StepBy (1);
            }
        }
        dip_vip -> Next ();
    } // end for2

    if (x != 1) // ����������
    {
        AnsiString file_s2 = Edit7 -> Text + "\\������� �� ������� �� ������ " +
            getFac (nom_fac) + " " + getForm (RadioGroup1 -> ItemIndex) + " " +
            getPeriod (RadioGroup3 -> ItemIndex) + " " + n_file + ".xls";

        try {
            SaveBookAs (WBook2, file_s2.c_str ());

            ExApp2.OlePropertyGet ("WorkBooks", 1).OleProcedure ("Close");
            ExApp2.OleProcedure ("Quit");
            ExApp2.Clear ();
            WSheet2.Clear ();
        }
        catch (...) {
            ShowMessage ("��������� ���� �������������� �� �������.\n \
     �������� ��� ��������������!");
        }
    }

    // ShowMessage ("��������� � ��� ���������");
    // Label8 -> Caption = "";
    dip_vip -> Close ();

    ProgressBar1 -> Position = 0;
}
// ---------------------------------------------------------------------------

void TVipusknikiForm::columnWidth (Variant WSheet) {
    ColumnWidth (Range2 (WSheet, "A:A"), 15);
    ColumnWidth (Range2 (WSheet, "B:B"), 15);
    ColumnWidth (Range2 (WSheet, "C:C"), 15);
    ColumnWidth (Range2 (WSheet, "D:D"), 15);
    ColumnWidth (Range2 (WSheet, "E:E"), 15);
    ColumnWidth (Range2 (WSheet, "F:F"), 80);
    ColumnWidth (Range2 (WSheet, "G:G"), 15);
    ColumnWidth (Range2 (WSheet, "H:H"), 15);
    ColumnWidth (Range2 (WSheet, "I:I"), 50);
    ColumnWidth (Range2 (WSheet, "J:J"), 10);
    ColumnWidth (Range2 (WSheet, "K:K"), 10);
    ColumnWidth (Range2 (WSheet, "L:L"), 10);
    ColumnWidth (Range2 (WSheet, "M:M"), 15);
    ColumnWidth (Range2 (WSheet, "N:N"), 15);
    ColumnWidth (Range2 (WSheet, "O:O"), 50);
    ColumnWidth (Range2 (WSheet, "P:P"), 70);
    ColumnWidth (Range2 (WSheet, "Q:Q"), 70);
    ColumnWidth (Range2 (WSheet, "R:R"), 10);
}
// ---------------------------------------------------------------------------

void TVipusknikiForm::writeExcel (Variant WSheet, TFDQuery* query, int i) {
    // �������
    ExCell (WSheet, 1, 1, i, i, false, "Calibri", 10, false, 2, 2, 0, false,
        false, query -> Fields -> FieldByName ("FAM") -> Value);

    // ���
    ExCell (WSheet, 2, 2, i, i, false, "Calibri", 10, false, 2, 2, 0, false,
        false, query -> Fields -> FieldByName ("NAME") -> Value);

    // ��������
    AnsiString otch = "-";
    if (query -> Fields -> FieldByName ("OTCH") -> Value != "") {
        otch = query -> Fields -> FieldByName ("OTCH") -> Value;
    }
    ExCell (WSheet, 3, 3, i, i, false, "Calibri", 10, false, 2, 2, 0, false,
        false, otch);

    // ������������ ����� ��������
    AnsiString iNomer = "�� ����������";
    if (dip_vip -> Fields -> FieldByName ("PERSONAL_NUMBER") -> Value != "") {
        iNomer = query -> Fields -> FieldByName ("PERSONAL_NUMBER") -> Value;
    }
    ExCell (WSheet, 4, 4, i, i, false, "Calibri", 10, false, 2, 2, 0, false,
        false, iNomer);

    // ������� �����������
    ExCell (WSheet, 5, 5, i, i, false, "Calibri", 10, false, 2, 2, 0, false,
        false, "������");

    // ������� ���������
    ExCell (WSheet, 6, 6, i, i, false, "Calibri", 10, false, 2, 2, 0, false,
        false, "���������� ����������� ������������ ��������������� ����������� ���������� ���������"
        );

    // ���� �����������
    AnsiString dataInc = "�� �����������";
    if (!query -> Fields -> FieldByName ("D_INCLUDE") -> Value.IsNull ()) {
        dataInc = query -> Fields -> FieldByName ("D_INCLUDE") -> Value;
    }
    ExCell (WSheet, 7, 7, i, i, false, "Calibri", 10, false, 2, 2, 0, false,
        false, dataInc);

    // ���� ���������
    AnsiString dataOut = "�� �����������";
    if (!query -> Fields -> FieldByName ("D_PRIKAZ_KURS") -> Value.IsNull ()) {
        dataOut = query -> Fields -> FieldByName ("D_PRIKAZ_KURS") -> Value;
    }
    ExCell (WSheet, 8, 8, i, i, false, "Calibri", 10, false, 2, 2, 0, false,
        false, dataOut);

    // ��� �������
    ExCell (WSheet, 9, 9, i, i, false, "Calibri", 10, false, 2, 2, 0, false,
        false, getDiplomType (StrToInt (query -> Fields -> FieldByName ("TYPE_DIPLOM")
         -> Value)));

    // ����� �������
    AnsiString seria = "�� �����������";
    if (query -> Fields -> FieldByName ("SERIA") -> Value != "") {
        seria = query -> Fields -> FieldByName ("SERIA") -> Value;
    }
    ExCell (WSheet, 10, 10, i, i, false, "Calibri", 10, false, 2, 2, 0, false,
        false, seria);

    // ����� �������
    AnsiString nomDip = "�� �����������";
    if (query -> Fields -> FieldByName ("NOM_DIPLOM") -> Value != "") {
        nomDip = query -> Fields -> FieldByName ("NOM_DIPLOM") -> Value;
    }
    WSheet.OlePropertyGet ("Cells", i, 11).OlePropertySet
        (WideString ("NumberFormat"), WideString ("@"));
    ExCell (WSheet, 11, 11, i, i, false, "Calibri", 10, false, 2, 2, 0, false,
        false, nomDip);

    // ����� ������ � ������� �����������
    AnsiString reg = "�� �����������";
    if (!query -> Fields -> FieldByName ("REGISTRATION") -> Value.IsNull ()) {
        reg = query -> Fields -> FieldByName ("REGISTRATION") -> Value;
    }
    ExCell (WSheet, 12, 12, i, i, false, "Calibri", 10, false, 2, 2, 0, false,
        false, reg);

    // ���� ������ �������
    AnsiString dataVip = "�� �����������";
    if (!query -> Fields -> FieldByName ("D_VIPUSK") -> Value.IsNull ()) {
        dataVip = query -> Fields -> FieldByName ("D_VIPUSK") -> Value;
    }
    ExCell (WSheet, 13, 13, i, i, false, "Calibri", 10, false, 2, 2, 0, false,
        false, dataVip);

    // ��� �������������
    ExCell (WSheet, 14, 14, i, i, false, "Calibri", 10, false, 2, 2, 0, false,
        false, query -> Fields -> FieldByName ("CODE_SPEC") -> Value);

    // �������������
    ExCell (WSheet, 15, 15, i, i, false, "Calibri", 10, false, 2, 2, 0, false,
        false, dip_vip -> Fields -> FieldByName ("SPEC_REG") -> Value);

    // ����������� �������������
    ExCell (WSheet, 16, 16, i, i, false, "Calibri", 10, false, 2, 2, 0, false,
        false, query -> Fields -> FieldByName ("SPECIAL_DIRECTION_SOKR") -> Value);

    // ������������
    AnsiString q = "�� �����������";
    if (query -> Fields -> FieldByName ("QUALIFICATION") -> Value != "") {
        q = getQualification (query -> Fields -> FieldByName ("QUALIFICATION") -> Value,
            StrToInt (query -> Fields -> FieldByName ("N_SPECIALIZ") -> Value),
            StrToInt (query -> Fields -> FieldByName ("VID_EDU") -> Value),
            query -> Fields -> FieldByName ("D_VIPUSK") -> Value);
    }
    ExCell (WSheet, 17, 17, i, i, false, "Calibri", 10, false, 2, 2, 0, false,
        false, q);

    // �������� �� ����������� ��
    AnsiString gragdan = "��";
    if (query -> Fields -> FieldByName ("SERIA") -> Value == "��") {
        gragdan = "���";
    }
    else if (query -> Fields -> FieldByName ("SERIA") -> Value == "") {
        gragdan = "�� �����������";
    }
    ExCell (WSheet, 18, 18, i, i, false, "Calibri", 10, false, 2, 2, 0, false,
        false, gragdan);
}
// ---------------------------------------------------------------------------

AnsiString TVipusknikiForm::getFac (int itemIndex) {
    switch (itemIndex) {
    case 1:
        return "����";
    case 2:
        return "���";
    case 3:
        return "�����";
    case 4:
        return "��";
    }
}

AnsiString TVipusknikiForm::getForm (int item_index) {
    switch (item_index) {
    case 0:
        return "�������";
    case 1:
        return "�������";
    case 2:
        return "������� + �������";
    }
}

AnsiString TVipusknikiForm::getPeriod (int item_index) {
    switch (item_index) {
    case 0:
        return "c " + DateTimePicker1 -> Date.DateString () + " �� " +
            DateTimePicker2 -> Date.DateString ();
    case 1:
        return "�� " + Edit1 -> Text + " ���";
    }
}
// ---------------------------------------------------------------------------

AnsiString TVipusknikiForm::getDiplomType (int diplomId) {
    switch (diplomId) {
    case 0:
        return "������ � ������ �����������";
    case 1:
        return "������ � ������ ����������� (��������)";
    case 2:
        return "������ � ������ ����������� � ��������";
    case 3:
        return "������ � ������ ����������� � �������� (��������)";
    case 4:
        return "������ � ������ ����������� (��� ����������� �������)";
    case 5:
        return "������ � ������ ����������� (��� ����������� �������) (��������)";
    case 6:
        return "������ � ������ ����������� � �������� (��� ����������� �������)";
    case 7:
        return "������ � ������ ����������� � �������� (��� ����������� �������) (��������)";
    case 8:
        return "������ ���������";
    case 9:
        return "������ ��������� (��������)";
    case 10:
        return "������ ��������";
    case 11:
        return "������ �������� (��������)";
    default:
        return "�� �����������";
    }
}
// ---------------------------------------------------------------------------

AnsiString TVipusknikiForm::getQualification (AnsiString q, int spec_v,
    int vid_edu_v, Variant d) {
    AnsiString Qua = q;
    AnsiString qa_n = "";
    AnsiString Str = "";
    TLocateOptions Flags;

    bool spec_sport_igry = false;
    // ���������� ��� ����������� ���� �� ������ ������ �� ���������� �����
    // (������ �/� �� ������� 2003 ������������)

    if (d.IsNull ()) {
        spec_sport_igry = false;
    }
    else { // else ���� �� ������
        int dat = d.AsType (4);
        if ( (spec_v == 24 || spec_v == 25 || spec_v == 20 || spec_v == 28)
            && vid_edu_v && dat < 37790)
        { // 24-��������, 25-�������, 20-���������, 28-������  ������� ����� �� 2003 ����
            spec_sport_igry = true;
        }
    } // end else ���� �� ������

    DM2 -> QualificationFDTable -> Open ();
    for (int i = 1; i <= Qua.Length (); i++) { // for �� Qua
        if (Qua.SubString (i, 1) != ",") { // if Qua!=","
            qa_n = qa_n + Qua.SubString (i, 1);
            if (i == Qua.Length ()) {
                DM2 -> QualificationFDTable -> First ();
                DM2 -> QualificationFDTable -> Locate ("NOMER_QU",
                    StrToInt (qa_n), Flags);
                if (qa_n == 2) {
                    if (spec_sport_igry) {
                        if (Str != "") {
                            Str = Str + "������ �� ���������� �����, ";
                        }
                        else {
                            Str = Str + "������ �� ���������� �����, ";
                        }
                    }
                    else {
                        if (Str != "") {
                            Str = Str + "������ �� " +
                                DM2 -> SpecializFDTable -> Lookup ("N_SPECIALIZ",
                                spec_v, "SPECIAL_SKLON") + ", ";
                        }
                        else {
                            Str = Str + "������ �� " +
                                DM2 -> SpecializFDTable -> Lookup ("N_SPECIALIZ",
                                spec_v, "SPECIAL_SKLON") + ", ";
                        }
                    }

                }
                else { // else �� ������
                    if (Str != "") {
                        Str = Str +
                            DM2 -> QualificationFDTableNAME -> Value.LowerCase
                            () + ", ";
                    }
                    else {
                        Str = Str + DM2 -> QualificationFDTableNAME -> Value + ", ";
                    }
                }
                qa_n = "";
            }
        } // end if Qua!=","
        else { // else Qua==","
            DM2 -> QualificationFDTable -> First ();
            DM2 -> QualificationFDTable -> Locate ("NOMER_QU", StrToInt (qa_n),
                Flags);
            if (qa_n == 2) {
                if (spec_sport_igry) {
                    if (Str != "") {
                        Str = Str + "������ �� ���������� �����, ";
                    }
                    else {
                        Str = Str + "������ �� ���������� �����, ";
                    }
                }
                else {
                    if (Str != "") {
                        Str = Str + "������ �� " + DM2 -> SpecializFDTable -> Lookup
                            ("N_SPECIALIZ", spec_v, "SPECIAL_SKLON") + ", ";
                    }
                    else {
                        Str = Str + "������ �� " + DM2 -> SpecializFDTable -> Lookup
                            ("N_SPECIALIZ", spec_v, "SPECIAL_SKLON") + ", ";
                    }
                }
            }
            else { // else �� ������
                if (Str != "") {
                    Str = Str + DM2 -> QualificationFDTableNAME -> Value.LowerCase
                        () + ", ";
                }
                else {
                    Str = Str + DM2 -> QualificationFDTableNAME -> Value + ", ";
                }
            }
            qa_n = "";
        } // end else Qua==","
    } // end  for �� Qua

    DM2 -> QualificationFDTable -> Close ();
    if (Str.Length ()) {
        Str = Str.SubString (1, Str.Length () - 2);
    }
    return Str;
}

// ---------------------------------------------------------------------------
void __fastcall TVipusknikiForm::Button1Click (TObject *Sender) {
    InFolderName = Edit7 -> Text;
    // �������� ���� � ����� � ����
    if (SelectDirectory ("�������� �������", "", InFolderName)) {
        Edit7 -> Text = InFolderName;
    }
}
// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "DataModule_Card.h"
#include "DataModule.h"
#include "DeloUnit.h"
#include "DM2Unit.h"
#include "DM3Unit.h"
#include "StudUnit.h"


#pragma package (smart_init)
// #pragma link     "DualList"
// #pragma link     "RXDBCtrl"
// #pragma link     "ToolEdit"
// #pragma link     "RxLookup"
// #pragma link     "MyList"
#pragma resource "*.dfm"


TDeloForm *DeloForm;


AnsiString * mas_fio_nomer[2];                                                  // ������ ������� � ������� ���������

AnsiString   kurs,                                                              // ����� �����
             sql_dop,                                                           // ���������� ��� �������� ���������������� SQL ���������� �� 2-� ������
             sql_head;                                                          // ���������� ��� �������� ���������������� SQL ���������� �� 2-� ������

AnsiString   sql_old = "            \
                SELECT              \
                    NOMER,          \
                    VID_EDU,        \
                    N_FAC,          \
                    KURS,           \
                    N_SPEC,         \
                    N_SPECIALIZ,    \
                    N_PRIKAZ_KURS,  \
                    D_PRIKAZ_KURS,  \
                    D_INCLUDE,      \
                    DATE_END,       \
                    N_GROUP,        \
                    INC_GROUP,      \
                    F_OLD,          \
                    STATUS_PEOPLE,  \
                    FAM,            \
                    NAME,           \
                    OTCH,           \
                    DATA_R,         \
                    STATUS_KURS,    \
                    N_FOUND         \
                FROM                \
                    PEOPLE People   \
                ";                                                              // ��� �������������� ���������� ������ SQL PeopleUpQuery

bool         correct = false,
             found,
             t       = true;

int          mas     = 0,                                                       // ���������� ��� ����������� ���� �� ������ � ������� 0 - ������ ���  1 - ������ ����
             rec;                                                               // ���������� ��������� � ������

Variant      i_gr;




// BitBtn1Click
// BitBtn2Click
// BitBtn3Click
// BitBtn4Click
// BitBtn5Click
// BitBtn6Click
// BitBtn7Click
// BitBtn8Click
// BitBtn9Click
// BitBtn10Click
// BitBtn11Click
// BitBtn12Click
// BitBtn13Click
// BitBtn14Click
// BitBtn15Click
// BitBtn16Click
// BitBtn17Click
// BitBtn18Click
// BitBtn19Click
// BitBtn20Click
// BitBtn21Click
// BitBtn22Click
// BitBtn23Click
// BitBtn24Click
// BitBtn25Click
// BitBtn26Click
// BitBtn27Click
// BitBtn28Click
// BitBtn29Click
// BitBtn30Click
// BitBtn31Click
// BitBtn128Click
// Button1Click
// Button2Click
// Button3Click
// Button4Click
// Button5Click
// Button111Click
// ComboBox1Change
// ComboBox2Change
// ComboBox4Change
// ComboBox5Change
// ComboBox6Change
// ComboBox7Change
// ComboBox8Change
// ComboBox9Change
// ComboBox10Change
// ComboBox14Change
// DateTimePicker1Change
// DateTimePicker2Change
// DateTimePicker3Change
// DateTimePicker4Change
// DateTimePicker5Change
// DateTimePicker6Change
// DateTimePicker7Change
// DateTimePicker8Change
// DateTimePicker9Change
// DateTimePicker10Change
// DateTimePicker11Change
// DateTimePicker12Change
// DateTimePicker13Change
// DateTimePicker14Change
// DateTimePicker15Change
// DateTimePicker16Change
// DateTimePicker17Change
// DateTimePicker18Change
// DateTimePicker19Change
// DateTimePicker20Change
// DateTimePicker21Change
// DateTimePicker22Change
// DateTimePicker23Change
// DateTimePicker112Change
// DBLookupComboBox16Click
// DBLookupComboBox22CloseUp
// Edit3Change
// Edit23KeyPress
// Edit35Change
// FormClose
// FormCreate
// Image1Click
// Label35Click
// PageControl1Change
// Panel1Click
// RadioGroup1Click
// RadioGroup2Click
// RadioGroup3Click
// RadioGroup4Click
// RadioGroup5Click
// RadioGroup8Click
// RadioGroup10Click
// RadioGroup12Click
// RadioGroup13Click
// RadioGroup18Click
// TabSheet8Exit
// TabSheet11Show
// TabSheet111Show
// Clear_Holiday
// Otkat
// Save_PrikazVipusk



__fastcall TDeloForm::TDeloForm (TComponent* Owner) : TForm (Owner) {
}

void __fastcall TDeloForm::FormClose (TObject *Sender, TCloseAction &Action) {
    // !!!if (Application -> MessageBox ("    ������� ����� �������?", "", MB_YESNO) == mrYes)
    if (MessageDlg ("    ������� ����� �������?", mtConfirmation,
        TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes) {
        if (mas) {
            for (int i = 0; i < 2; i++)
                delete[]mas_fio_nomer[i];
            // delete[]mas_fio_nomer;
            mas = 0;
        }
        DataModule1 -> People_PartFDQuery -> Close ();
        DataModule1 -> PeopleUpFDQuery -> Close ();
        Action = caFree;
    }
    else
        Action = caNone;
}

void __fastcall TDeloForm::BitBtn1Click (TObject *Sender)
{ // �������� ���������� -- �������� �� ������ ������� ��������
    if ( (ComboBox2 -> ItemIndex == -1) && (Edit2 -> Text == "") &&
        (RadioGroup10 -> ItemIndex == 1)) {
        ShowMessage ("��������� ������������ ��������� ������!");
        return;
    }

    i_gr = search_increment_group (Edit2 -> Text, ComboBox2 -> ItemIndex);
    if (!i_gr.IsNull ()) {
        /* DataModule1 -> People_PartFDQuery -> Close ();
         DataModule1 -> People_PartFDQuery -> SQL -> Clear ();
         DataModule1 -> People_PartFDQuery -> SQL -> Add ("SELECT NOMER, FAM, NAME, OTCH, INC_GROUP, N_GROUP, VID_EDU, KURS, N_FOUND FROM PEOPLE WHERE (N_FAC="+AnsiString (nom_fac)+") AND (STATUS_PEOPLE=1) AND (INC_GROUP=:INC_GROUP) ORDER BY FAM, NAME, OTCH");
         DataModule1 -> People_PartFDQuery -> ParamByName ("INC_GROUP") -> AsInteger=i_gr;
         DataModule1 -> People_PartFDQuery -> Open (); */

        DataModule1 -> PeopleUpFDQuery -> Close ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Clear ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Add ("SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, \
   N_PRIKAZ_KURS, D_PRIKAZ_KURS, D_INCLUDE, DATE_END, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, \
   STATUS_KURS, N_FOUND, FAM ||' '|| NAME ||' ' || OTCH as FIO  \
   FROM PEOPLE People WHERE (N_FAC=" + AnsiString (nom_fac) +
            ") AND (STATUS_PEOPLE=1) AND (INC_GROUP=:I_GR) ORDER BY FAM, NAME, OTCH");
        DataModule1 -> PeopleUpFDQuery -> ParamByName ("I_GR") -> AsInteger = i_gr;
        DataModule1 -> PeopleUpFDQuery -> Open ();

        // if (DataModule1 -> People_PartFDQuery -> RecordCount)
        if (DataModule1 -> PeopleUpFDQuery -> RecordCount)
        { // ���� �������� �������, �� ���������� ������ � ��������� Query � ����� �������
            Panel2 -> Visible = true;
            DataModule1 -> RestoreFDQuery -> Open ();
            // DataModule1 -> RestoreFDQuery -> Insert ();
        }
        else { // ���� ������� �� ����������
            ShowMessage (
                "��������� ��������� ������, �������� �� ������� ������ ������� ����������!");
            Edit2 -> SetFocus ();
        }
    }
    else {
        ShowMessage ("������ ������ � ����� ����� �������� �� ����������");
        Edit2 -> SetFocus ();
    }
}

void __fastcall TDeloForm::ComboBox2Change (TObject *Sender) {
    Panel2 -> Visible = false;
}

void __fastcall TDeloForm::BitBtn2Click (TObject *Sender)
{ // �������� ����������, �������� �� ������ ���������
    if (FIOLook -> KeyValue == -1) {
        ShowMessage ("�������� ��� ��������!");
        return;
    }
    if (DBLookupComboBox1 -> KeyValue == -1) {
        ShowMessage ("�������� ������� ���������� ��������!");
        return;
    }
    if (Edit28 -> Text == "") {
        ShowMessage ("�������� � ������� �� ����������!");
        return;
    }

    // ��������� ������ �������� ���������
    if (!DataModule1 -> Search_CK (FIOLook -> KeyValue, 1, Edit28 -> Text,
        DateTimePicker13 -> Date.DateString ()))
    { // if �� ��������� �������� 0 - ��� �������� �������� ��������

        ShowMessage (
            "���������� �������������� ��-�� ������� � ������� ����������!");
        return;
    }
    // ---
    try {
        if (DataModule1 -> RestoreFDQuery -> State != dsInsert)
            DataModule1 -> RestoreFDQuery -> Insert ();

        TLocateOptions fl;
        int n_st = FIOLook -> KeyValue;
        DataModule1 -> RestoreFDQueryNOMER -> Value = n_st; // ����� �����������
        DataModule1 -> RestoreFDQueryN_CAUSE_RESTORE -> Value =
            DBLookupComboBox1 -> KeyValue; // ������� ����������
        try { // �������� �� ���� � � ������� ��������� ��������
            DataModule1 -> RestoreFDQueryN_PRIKAZ_RES -> Value =
                StrToInt (Edit28 -> Text); // � ������� �� ����������
        }
        catch (...) {
            DataModule1 -> RestoreFDQuery -> CancelUpdates ();
            ShowMessage ("������� ������ � �������!");
            return;
        }

        DataModule1 -> RestoreFDQueryD_PRIKAZ_RES -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker13 -> Date);
        // ���� ������� �� ����������
        DataModule1 -> RestoreFDQueryVID_RESTORE -> Value = 1; // ����������

        // DataModule1 -> PeopleUpQuery -> Open ();
        // DataModule1 -> PeopleUpQuery -> Locate ("NOMER",n_st,fl);
        DataModule1 -> PeopleUpFDQuery -> Edit ();
        // �������� �� Status_kurs ���� 0, �� ��� � �������
        // ���� 1, �� ������� ������� �� ��������� �� ��������� ����
        // ����� ���� ���������� �������� �� ����� ������ � ����
        if (DataModule1 -> PeopleUpFDQuerySTATUS_KURS -> Value == 1) {
            /* !!!if (Application -> MessageBox ("���� ������� ��� ������� ��������� �� ��������� ����. �������� ����� ������ � ����?",
             "��������", MB_OKCANCEL) == IDOK) */
            if (MessageDlg
                ("���� ������� ��� ������� ��������� �� ��������� ����. �������� ����� ������ � ����?",
                mtConfirmation, TMsgDlgButtons () << mbOK << mbCancel, 0) == 1)
            { // if �������� ����� ������ � ���� �� ���� ������
                int old_kurs = DataModule1 -> PeopleUpFDQueryKURS -> Value;
                int old_gr =
                    StrToInt (DataModule1 -> PeopleUpFDQueryN_GROUP -> Value);
                if (old_kurs != 1) {
                    DataModule1 -> PeopleUpFDQueryKURS -> Value = (old_kurs - 1);
                    if (nom_fac == 3)
                    { // if ��� ����� - �� ���� ������� ��������� 0
                        DataModule1 -> PeopleUpFDQueryN_GROUP -> Value =
                            "0" + IntToStr (old_gr - 10);
                    }
                    else
                        DataModule1 -> PeopleUpFDQueryN_GROUP -> Value =
                            IntToStr (old_gr - 10);
                }
            }

            DataModule1 -> PeopleUpFDQuerySTATUS_KURS -> Value = 0;
        }

        DataModule1 -> PeopleUpFDQuerySTATUS_PEOPLE -> Value = 2;
        // ������ ��� �����������
        DataModule1 -> PeopleUpFDQueryINC_GROUP -> Value = 18;
        // ���������� ��� ������ � ������� 000
        try { // try
            DataModule1 -> PeopleUpFDQuery -> ApplyUpdates ();
            DataModule1 -> RestoreFDQuery -> ApplyUpdates ();
            DataModule1 -> PeopleUpFDQuery -> CommitUpdates ();
            DataModule1 -> RestoreFDQuery -> CommitUpdates ();
            DataModule1 -> PeopleUpFDQuery -> Close ();
            DataModule1 -> RestoreFDQuery -> Close ();
            DataModule1 -> People_PartFDQuery -> Close ();
        } // end try
        catch (...) {
            DataModule1 -> RestoreFDQuery -> CancelUpdates ();
            DataModule1 -> PeopleUpFDQuery -> CancelUpdates ();
            DataModule1 -> PeopleUpFDQuery -> Close ();
            DataModule1 -> RestoreFDQuery -> Close ();

            ShowMessage ("��������� ������!");

        }
        // -----
        ComboBox2 -> ItemIndex = -1;
        Edit2 -> Text = "";
        ComboBox2 -> Visible = false; // ��� ��������
        Edit2 -> Visible = false; // ������
        BitBtn1 -> Visible = false; // ������ ������
        Label4 -> Visible = false;
        Label5 -> Visible = false;
        // --------------
        Panel2 -> Visible = false;
        FIOLook -> KeyValue = -1; // ������� ���
        DBLookupComboBox1 -> KeyValue = -1; // ������� ������� ����������
        Edit28 -> Text = ""; // ������� � �������
        DateTimePicker13 -> Date = Now (); // ������� ���� �������
        DateTimePicker13 -> Time = StrToTime ("00:00");
        // -*----
        RadioGroup10 -> ItemIndex = -1;
    }
    catch (...) {
        DataModule1 -> RestoreFDQuery -> CancelUpdates ();
        DataModule1 -> PeopleUpFDQuery -> CancelUpdates ();
        DataModule1 -> PeopleUpFDQuery -> Close ();
        DataModule1 -> RestoreFDQuery -> Close ();

        ShowMessage ("��������� ������!");
    }
}

void __fastcall TDeloForm::BitBtn3Click (TObject *Sender)
{ // �������� �������������� - ����� ������������ ��������

    Panel4 -> Visible = false;
    Edit3 -> Text = "";
    Edit3 -> Visible = false;
    Label10 -> Visible = false;
    Panel3 -> Visible = false;

    try {

        // sql_old="SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND FROM PEOPLE People";

        DataModule1 -> PeopleUpFDQuery -> Close ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Clear ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Add
            ("SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_INCLUDE, DATE_END, D_PRIKAZ_KURS, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND, FAM ||' '|| NAME ||' ' || OTCH as FIO  FROM PEOPLE People WHERE (STATUS_PEOPLE=2) OR (STATUS_PEOPLE=7) ORDER BY FAM, NAME, OTCH"
            );
        DataModule1 -> PeopleUpFDQuery -> Open ();

        if (DataModule1 -> PeopleUpFDQuery -> RecordCount) {
            Panel3 -> Visible = true;
            Edit3 -> Visible = true;
            Label10 -> Visible = true;
            DM2 -> SpecializFDTable -> Filtered = false;
            DataModule1 -> PeopleUpFDQuery -> Last ();
            DataModule1 -> PeopleUpFDQuery -> First ();
        }
        else {
            ShowMessage (
                "� ���� ������ ������ �������� ���. ��������� ������������ ��������� ������!");
        }

    } // try
    catch (...) {
        ShowMessage (
            "��������� ��������� ������������ �������� � ����� �������. ��� ������������� ������ ����� ��������. ���� ������ ����� ���������� � ����������, ����������� � ������������� ������� ��������!!!");
    }
}

void __fastcall TDeloForm::Edit3Change (TObject *Sender)
{ // ������� ����� �� �������
    if (DataModule1 -> PeopleUpFDQuery -> State != dsInactive) { // if Query ������
        Set<TLocateOption, 0, 1>flags;
        flags << loCaseInsensitive << loPartialKey;
        DataModule1 -> PeopleUpFDQuery -> Locate ("FAM", Edit3 -> Text, flags);
    } // end if Query ������
}

void __fastcall TDeloForm::BitBtn4Click (TObject *Sender)
{ // �������� ��������������, �������� �� ������ -- ������������
    Label15 -> Caption = DM2 -> FacultyFDTable -> Lookup ("N_FAC", nom_fac, "FAC1");
    Panel4 -> Visible = true;
    DM2 -> SpecializFDTable -> Filtered = true;
    // Panel3 -> Visible=false;
    DataModule1 -> RestoreFDQuery -> Open ();
    Edit3 -> Text = DataModule1 -> PeopleUpFDQueryFAM -> Value + " " +
        DataModule1 -> PeopleUpFDQueryNAME -> Value + " " +
        DataModule1 -> PeopleUpFDQueryOTCH -> Value;
    DateTimePicker16 -> Date = Now (); // ���� �������
    DateTimePicker16 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::BitBtn5Click (TObject *Sender)
{ // �������� �������������� - �������������� ��������
    // -------------
    if (ComboBox3 -> ItemIndex == -1) {
        ShowMessage ("�������� ��� ��������!");
        return;
    }
    // --------------
    if (Edit6 -> Text == "") {
        ShowMessage ("������� ����� ������!");
        return;
    }
    // --------------
    if (Edit7 -> Text == "") {
        ShowMessage ("������� ����!");
        return;
    }
    // --------------
    if (Edit31 -> Text == "") {
        ShowMessage ("������� � �������!");
        return;
    }

    // ------------------
    if (DBLookupComboBox2 -> KeyValue == -1) {
        ShowMessage ("�������� ������������� (����������� �������������)!");
        return;
    }
    // ---------------------

    if (DBLookupComboBox20 -> KeyValue == -1) {
        ShowMessage ("�������� �������������!");
        return;
    }
    // ---------------------

    if ( (ComboBox3 -> ItemIndex != -1) && (Edit6 -> Text != "") &&
        (Edit7 -> Text != "") && (DBLookupComboBox2 -> Text != ""))
    { // if �������� �� ���� ���� ������
        if (!check_fac_group (Edit6 -> Text))
            return; // �������� �� ����� ������ � ���������
        if (!check_group_kurs (Edit6 -> Text, Edit7 -> Text))
            return; // �������� �� ����� ������ � ����

        // ����� ������������� ������ ������
        i_gr = search_increment_group (Edit6 -> Text, ComboBox3 -> ItemIndex);
        if (i_gr.IsNull ()) {
            ShowMessage ("������ ������ � ����� ����� �������� �� ����������!");
            Edit6 -> Text = "";
            Edit6 -> SetFocus ();
            return;
        }

        int n_prikaz = 0; // ����� �������
        try { // �������� �� ���� � � ������� ��������� ��������
            n_prikaz = StrToInt (Edit31 -> Text); // � ������� �� ��������������
        }
        catch (...) {
            ShowMessage ("������� ������ � �������!");
            return;
        }
        //////////////////////////////////
        // ��������� ������ �� ��������
        if (DataModule1 -> PeopleUpFDQuery -> State == dsInactive)
            DataModule1 -> PeopleUpFDQuery -> Open ();
        if (DataModule1 -> PeopleUpFDQuery -> State != dsEdit)
            DataModule1 -> PeopleUpFDQuery -> Edit ();
        DataModule1 -> PeopleUpFDQueryINC_GROUP -> Value = i_gr; // ��������� ������
        DataModule1 -> PeopleUpFDQueryN_GROUP -> Value = Edit6 -> Text;
        // ����� ������
        DataModule1 -> PeopleUpFDQueryVID_EDU -> Value = ComboBox3 -> ItemIndex;
        // ��� ��������
        DataModule1 -> PeopleUpFDQueryKURS -> Value = Edit7 -> Text.ToInt (); // ����
        DataModule1 -> PeopleUpFDQueryN_FAC -> Value = nom_fac; // ���������
        DataModule1 -> PeopleUpFDQuerySTATUS_PEOPLE -> Value = 1;
        // ������ ������������ ��������
        DataModule1 -> PeopleUpFDQuerySTATUS_KURS -> Value = 0;
        // ��� ��������������
        DataModule1 -> PeopleUpFDQueryN_SPECIALIZ -> Value =
            DBLookupComboBox2 -> KeyValue; // �������������
        // ������������� ��������, ����������, ���� ���������� �������������
        DataModule1 -> PeopleUpFDQueryN_SPEC -> Value =
            DBLookupComboBox20 -> KeyValue; // �������������

        DataModule1 -> PeopleUpFDQueryD_INCLUDE -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker16 -> Date);
        // ���� ������ ��������

        // ���� ��������� 30.06.2___ //���������!!!!! �� ������ ���������!!!!
        AnsiString kurs_uch = "", year_end = "", date_end = "";

        if (DataModule1 -> PeopleUpFDQueryVID_EDU -> Value == 1) { // �������
            kurs_uch = 6 - DataModule1 -> PeopleUpFDQueryKURS -> Value;
            // ������� ������ �������
            year_end = uch_god + kurs_uch; // ��� ���������
            if (kurs_uch == 0)
                year_end = uch_god + 1; // ��� ���������
        }
        else { // �������
            kurs_uch = 5 - DataModule1 -> PeopleUpFDQueryKURS -> Value;
            // ������� ������ �������
            year_end = uch_god + kurs_uch; // ��� ���������
            if (kurs_uch == 0)
                year_end = uch_god + 1; // ��� ���������
        }
        date_end = "30.06." + year_end;
        DataModule1 -> PeopleUpFDQueryDATE_END -> Value =
            DateTimeToSQLTimeStamp (StrToDate (date_end));

        // �������   ���  ������
        if (RadioGroup9 -> ItemIndex) // �������
        {
            DataModule1 -> PeopleUpFDQueryN_FOUND -> Value = 2; // ��������� �������
        }
        else { // ������
            DataModule1 -> PeopleUpFDQueryN_FOUND -> Value = 6; // ������
        }

        // ���������� �� ��������
        if (RadioGroup12 -> ItemIndex == 3)
        { // if ������� �� ������� ���� - �� ���� ������� � ��������������
            if (DataModule1 -> Public_PrikazFDQuery -> State == dsInactive)
                DataModule1 -> Public_PrikazFDQuery -> Open ();
            DataModule1 -> Public_PrikazFDQuery -> Insert ();
            DataModule1 -> Public_PrikazFDQueryNOMER -> Value =
                DataModule1 -> PeopleUpFDQueryNOMER -> Value; // ����� ��������
            DataModule1 -> Public_PrikazFDQueryN_PUBLIC_PRIKAZ -> Value =
                n_prikaz; // � �������
            DataModule1 -> Public_PrikazFDQueryD_PUBLIC_PRIKAZ -> Value =
                DateTimeToSQLTimeStamp (DateTimePicker16 -> Date); // ���� �������
            DataModule1 -> Public_PrikazFDQueryN_TYPE -> Value = 7;
            // ��� ������� ������� �� ������� ����
            DataModule1 -> Public_PrikazFDQueryDESCRIBE -> Value =
                LabeledEdit1 -> Text; // ����������
        } // end if ������� �� ������� ���� - �� ���� ������� � ��������������
        else { // else ������ ��� �������������� - ���� ������ � ��������������

            // ��������� ������ � ������� ����������/��������������
            if (DataModule1 -> RestoreFDQuery -> State == dsInactive)
                DataModule1 -> RestoreFDQuery -> Open ();
            if (DataModule1 -> RestoreFDQuery -> State != dsInsert)
                DataModule1 -> RestoreFDQuery -> Insert ();

            DataModule1 -> RestoreFDQueryNOMER -> Value =
                DataModule1 -> PeopleUpFDQueryNOMER -> Value;
            DataModule1 -> RestoreFDQueryVID_RESTORE -> Value = 0;
            // 0 - ��������������
            DataModule1 -> RestoreFDQueryN_PRIKAZ_RES -> Value = n_prikaz;
            // � ������� �� ��������������
            DataModule1 -> RestoreFDQueryD_PRIKAZ_RES -> Value =
                DateTimeToSQLTimeStamp (DateTimePicker16 -> Date);
            // ���� ������� �� ��������������
            // ������� ��������������
            switch (RadioGroup12 -> ItemIndex) { // switch
            case 0:
                DataModule1 -> RestoreFDQueryN_CAUSE_RESTORE -> Value = 4;
                // ������� �� ������. ������� = 4
                break;
            case 1:
                DataModule1 -> RestoreFDQueryN_CAUSE_RESTORE -> Value = 12;
                // ������� �� ������� ������� = 12
                break;
            case 2:
                DataModule1 -> RestoreFDQueryN_CAUSE_RESTORE -> Value = 17;
                // �������� � ������ ���� = 17
                break;
            } // end switch

            // ����������
            if (RadioGroup12 -> ItemIndex == 2)
                DataModule1 -> RestoreFDQueryDESCRIBE -> Value = LabeledEdit1 -> Text;
            else
                DataModule1 -> RestoreFDQueryDESCRIBE -> Value =
                    "������������ �� " + Edit7 -> Text + " ���� �� " +
                    RadioGroup9 -> Items -> Strings[RadioGroup9 -> ItemIndex];
        } // end else ������ ��� �������������� - ���� ������ � ��������������

        try { // try ���������� ������
            if (RadioGroup12 -> ItemIndex == 3)
            { // if ������� �� ������� ���� - �� ���� ������� � ��������������
                DataModule1 -> Public_PrikazFDQuery -> ApplyUpdates ();
                DataModule1 -> Public_PrikazFDQuery -> CommitUpdates ();
            }
            else { // else ������ ��� �������������� - ���� ������ � ��������������
                DataModule1 -> RestoreFDQuery -> ApplyUpdates ();
                DataModule1 -> RestoreFDQuery -> CommitUpdates ();
            }

            DataModule1 -> PeopleUpFDQuery -> ApplyUpdates ();
            DataModule1 -> PeopleUpFDQuery -> CommitUpdates ();

            ShowMessage (DataModule1 -> PeopleUpFDQueryFAM -> Value + " " +
                DataModule1 -> PeopleUpFDQueryNAME -> Value + " " +
                DataModule1 -> PeopleUpFDQueryOTCH -> Value + " ������������");
            DM2 -> SpecializFDTable -> Filtered = true;
        } // end try ���������� ������
        catch (...) { // catch �� ���������� ���������

            if (RadioGroup12 -> ItemIndex == 3)
            { // if ������� �� ������� ���� - �� ���� ������� � ��������������
                DataModule1 -> Public_PrikazFDQuery -> CancelUpdates ();
                ShowMessage (
                    "�� ������� ��������� ������ �� ������� �� ������� ����!");
            }
            else { // else ������ ��� �������������� - ���� ������ � ��������������
                DataModule1 -> RestoreFDQuery -> CancelUpdates ();
                ShowMessage (
                    "�� ������ �������������� ��������. ���������� � �������������!");
            }
            DataModule1 -> PeopleUpFDQuery -> CancelUpdates ();
            return;
        } // end catch �� ���������� ���������

        DataModule1 -> Public_PrikazFDQuery -> Close ();
        DataModule1 -> RestoreFDQuery -> Close ();
        DataModule1 -> PeopleUpFDQuery -> Close ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Clear ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Add (sql_old);

        // -----
        Edit3 -> Visible = true; // ������� ����� �� �������
        Label10 -> Visible = true; // ������� ����� �� �������
        Panel3 -> Visible = false;
        // -------
        Panel4 -> Visible = false;
        Edit6 -> Text = ""; // � ������
        Edit7 -> Text = ""; // ����
        Edit31 -> Text = ""; // � �������
        DateTimePicker16 -> Date = Now (); // ���� �������
        DateTimePicker16 -> Time = StrToTime ("00:00");
        ComboBox3 -> ItemIndex = -1; // ��� ��������
        DBLookupComboBox2 -> KeyValue = -1; // �������������
        // -------
        Edit3 -> Text = ""; // �������
    } // end if �������� �� ���� ���� ������
    else {
        ShowMessage ("������� �� ��� ������.");
    }

}

void __fastcall TDeloForm::ComboBox4Change (TObject *Sender) {
    Panel5 -> Visible = false;
}

void __fastcall TDeloForm::BitBtn6Click (TObject *Sender)
{ // �������� ��������� �������, �������� �� ������ -- ������� ��������

    i_gr = search_increment_group (Edit8 -> Text, ComboBox4 -> ItemIndex);
    if (!i_gr.IsNull ()) {
        // sql_old="SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND FROM PEOPLE People";

        DataModule1 -> PeopleUpFDQuery -> Close ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Clear ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Add ("SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, \
    N_PRIKAZ_KURS, D_PRIKAZ_KURS, D_INCLUDE, DATE_END, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, \
    FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND, FAM ||' '|| NAME ||' ' || OTCH as FIO \
    FROM PEOPLE People WHERE (N_FAC=" + AnsiString (nom_fac) + ") AND ( (STATUS_PEOPLE=1 AND INC_GROUP=:I_GR) \
    or (STATUS_PEOPLE=3 AND N_GROUP=" + Edit8 -> Text +
            ")) ORDER BY FAM, NAME, OTCH");
        DataModule1 -> PeopleUpFDQuery -> ParamByName ("I_GR") -> AsInteger = i_gr;
        DataModule1 -> PeopleUpFDQuery -> Open ();

        if (DataModule1 -> PeopleUpFDQuery -> RecordCount) {
            Panel5 -> Visible = true;
            DateTimePicker14 -> Date = Now ();
            DataModule1 -> Public_PrikazFDQuery -> Open ();
            // DataModule1 -> Public_PrikazQuery -> Insert ();
        }
        else {
            ShowMessage ("�� ������ ����� ������!");
            Edit8 -> SetFocus ();
        }

    }
    else {
        ShowMessage ("�� ������ ����� ������!");
        Edit8 -> SetFocus ();
    }
}

void __fastcall TDeloForm::BitBtn7Click (TObject *Sender) {
    if (DBLookupComboBox4 -> KeyValue == -1) {
        ShowMessage ("�������� ��� ��������!");
        return;
    }
    if (DBLookupComboBox5 -> KeyValue == -1) {
        ShowMessage ("�������� ��� ������� �� ��������� �������!");
        return;
    }
    if (Edit29 -> Text == "") {
        ShowMessage ("������� � ������� �� ��������� �������!");
        return;
    }
    try { // try
        if (Edit9 -> Text != "") { // �������� �� �������� ���� ����� �������
            if (DBLookupComboBox5 -> KeyValue == 2)
            { // if �������� �� ����� ���� �������: ��������� �������
                // ���������  ������� � ���������� Public_Prikaz ������ �������

                if (DataModule1 -> Public_PrikazFDQuery -> State != dsInsert)
                    DataModule1 -> Public_PrikazFDQuery -> Insert ();

                DataModule1 -> Public_PrikazFDQueryNOMER -> Value =
                    DBLookupComboBox4 -> KeyValue; // ��� �������� �� ���. �������
                DataModule1 -> Public_PrikazFDQueryN_TYPE -> Value =
                    DBLookupComboBox5 -> KeyValue; // ��� ������� ==2
                try { // �������� �� ���� � � ������� ��������� ��������
                    DataModule1 -> Public_PrikazFDQueryN_PUBLIC_PRIKAZ -> Value =
                        StrToInt (Edit29 -> Text); // � ������� �� ���.�������
                }
                catch (...) {
                    DataModule1 -> Public_PrikazFDQuery -> CancelUpdates ();
                    ShowMessage ("������� ������ � �������!");
                    return;
                }
                DataModule1 -> Public_PrikazFDQueryD_PUBLIC_PRIKAZ -> Value =
                    DateTimeToSQLTimeStamp (DateTimePicker14 -> Date);
                // ���� ������� �� ���. �������
                DataModule1 -> Public_PrikazFDQueryDESCRIBE -> Value =
                    DataModule1 -> PeopleUpFDQueryFAM -> Value;
                // ���������� ������ �������
                DataModule1 -> Public_PrikazFDQuery -> ApplyUpdates ();

                // ��������� ������� � ����������� ������ ������� �  F_OLD
                // (�� � ������ ��������� ������� ��������� ��� - �� �������� � DESCRIBE)

                DataModule1 -> PeopleUpFDQuery -> Edit ();
                DataModule1 -> PeopleUpFDQueryF_OLD -> Value =
                    DataModule1 -> PeopleUpFDQueryFAM -> Value;
                DataModule1 -> PeopleUpFDQueryFAM -> Value = Edit9 -> Text;
                DataModule1 -> PeopleUpFDQuery -> ApplyUpdates ();

                DataModule1 -> PeopleUpFDQuery -> CommitUpdates ();
                DataModule1 -> Public_PrikazFDQuery -> CommitUpdates ();

                ShowMessage ("������� �������� �� " + Edit9 -> Text);

                Panel5 -> Visible = false;
                ComboBox4 -> ItemIndex = -1;
                Edit8 -> Text = ""; // � ������
                Edit29 -> Text = ""; // � �������
                Edit9 -> Text = ""; // ����� �������
                DateTimePicker14 -> Date = Now (); // ���� �������
                DateTimePicker14 -> Time = StrToTime ("00:00");
                DBLookupComboBox4 -> KeyValue = -1; // ��� ��������
                DBLookupComboBox5 -> KeyValue = -1; // ��� �������

                Edit8 -> SetFocus ();

                DataModule1 -> Public_PrikazFDQuery -> Close ();
                DataModule1 -> PeopleUpFDQuery -> Close ();
                DataModule1 -> PeopleUpFDQuery -> SQL -> Clear ();
                DataModule1 -> PeopleUpFDQuery -> SQL -> Add (sql_old);
            } // end if  �������� �� ����� ���� �������: ��������� �������
            else
                ShowMessage ("�������� ��� �������: ��������� �������!!!");
        } // end if ���� �� ������� ����� �������
        else
            ShowMessage ("������� ����� �������!!!");
    } // end try
    catch (...) { // catch � ������ ������������� ������
        DataModule1 -> PeopleUpFDQuery -> CancelUpdates ();
        DataModule1 -> Public_PrikazFDQuery -> CancelUpdates ();
    } // end catch
}

void __fastcall TDeloForm::Button2Click (TObject *Sender)
{ // �������� ������� �������������, �������� �� ������ ����� ���������
    if (ComboBox5 -> Text == "" || Edit11 -> Text == "")
        ShowMessage ("������� ��� ������");
    else { // else if �������� �� ���� ������
        // ����� ���������� ������ �� ������ � ���� ��������
        i_gr = search_increment_group (Edit11 -> Text, ComboBox5 -> ItemIndex);
        if (!i_gr.IsNull ()) { // if IsNull
            DataModule1 -> People_PartFDQuery -> Close ();
            DataModule1 -> People_PartFDQuery -> SQL -> Clear ();
            DataModule1 -> People_PartFDQuery -> SQL -> Add
                ("SELECT NOMER, FAM, NAME, OTCH, INC_GROUP, N_GROUP, KURS, VID_EDU, N_FOUND FROM PEOPLE WHERE (N_FAC=" +
                AnsiString (nom_fac) +
                ") AND (STATUS_PEOPLE=1) AND (STATUS_KURS=1) AND (INC_GROUP=" +
                VarToStr (i_gr) + ") ORDER BY FAM, NAME, OTCH");
            DataModule1 -> People_PartFDQuery -> Open ();

            rec = DataModule1 -> People_PartFDQuery -> RecordCount;
            if (!rec) {
                DataModule1 -> People_PartFDQuery -> Close ();
                ShowMessage (
                    "� ���� ������ ��� ��������� �� ������������ �� ��������� ����!");
                Edit11 -> SetFocus ();
                return;
            }
            for (int i = 0; i < 2; i++) { // for1
                mas_fio_nomer[i] = new AnsiString[rec];
            } // end for 1
            DualListDlg = new TDualListDlg (this);
            DualListDlg -> Caption = "����� ��������� ��� ��������";
            DualListDlg -> SrcList -> Items -> Clear ();
            DualListDlg -> DstList -> Items -> Clear ();

            AnsiString s1, s2, ol_fam, n_fam;
            ol_fam = "";
            for (int i = 0; i < rec; i++) { // for 2
                s1 = " " + DataModule1 -> People_PartFDQueryNAME -> Value.SubString
                    (1, 1) + ".";
                s2 = " " + DataModule1 -> People_PartFDQueryOTCH -> Value.SubString
                    (1, 1) + ".";
                n_fam = DataModule1 -> People_PartFDQueryFAM -> Value + s1 + s2;

                if (n_fam == ol_fam) { // if
                    mas_fio_nomer[0][i] =
                        AnsiString (DataModule1 -> People_PartFDQueryFAM -> Value +
                        " " + DataModule1 -> People_PartFDQueryNAME -> Value + " " +
                        DataModule1 -> People_PartFDQueryOTCH -> Value);
                    DualListDlg -> SrcList -> Items -> AddObject
                        (DataModule1 -> People_PartFDQueryFAM -> Value + " " +
                        DataModule1 -> People_PartFDQueryNAME -> Value + " " +
                        DataModule1 -> People_PartFDQueryOTCH -> Value,
                        (TObject *)
                        (DataModule1 -> People_PartFDQueryNOMER -> Value));

                } // end if
                else { // else
                    mas_fio_nomer[0][i] = n_fam;
                    // DualListDialog2 -> List1 -> Add (n_fam);
                    DualListDlg -> SrcList -> Items -> AddObject (n_fam,
                        (TObject *)
                        (DataModule1 -> People_PartFDQueryNOMER -> Value));

                } // end else
                mas_fio_nomer[1][i] =
                    AnsiString (DataModule1 -> People_PartFDQueryNOMER -> Value);
                ol_fam = n_fam;
                DataModule1 -> People_PartFDQuery -> Next ();
            } // end for 2

            DualListDlg -> ShowModal ();

            if (DataModule2 -> printdlg == true) {
                if (0 == DualListDlg -> DstList -> Items -> Count)
                { // if  ���� �� ������� �� ������ �������� �   FOutList
                    DataModule1 -> People_PartFDQuery -> Close ();
                    ShowMessage ("�� �� ������� �� ������ ��������!");
                    Edit11 -> Text = "";
                    ComboBox5 -> ItemIndex = -1;
                    // ������� ������
                    for (int i = 0; i < 2; i++)
                        delete[]mas_fio_nomer[i];
                    // delete[]mas_fio_nomer;
                    return;
                } // end if  �� ������� �� ������ �������� �   FOutList

                ListBox2 -> Visible = true;
                for (int i = 0; i < DualListDlg -> DstList -> Items -> Count;
                i++) // (int i = 0; i < DualListDialog2 -> List2 -> Count; i++)
                { // for 3
                    if (i < 9) {
                        // ListBox2 -> Items -> Add ("0"+AnsiString (i+1)+". "+DualListDialog2 -> List2 -> Strings[i]);
                        ListBox2 -> Items -> AddObject
                            ("0" + AnsiString (i + 1) + ". " +
                            DualListDlg -> DstList -> Items -> Strings[i],
                            DualListDlg -> DstList -> Items -> Objects[i]);
                    }
                    else {
                        // ListBox2 -> Items -> Add (AnsiString (i+1)+". "+DualListDialog2 -> List2 -> Strings[i]);
                        ListBox2 -> Items -> AddObject
                            (AnsiString (i + 1) + ". " +
                            DualListDlg -> DstList -> Items -> Strings[i],
                            DualListDlg -> DstList -> Items -> Objects[i]);
                    }
                } // end for 3
            } // Execute ();
            else { // else  ���� ������ ������ ��������, �� ������ �� ������ ��������
                DataModule1 -> People_PartFDQuery -> Close ();
                ShowMessage ("�� �� ������� �� ������ ��������!");
                Edit11 -> Text = "";
                ComboBox5 -> ItemIndex = -1;
                // ������� ������
                delete DualListDlg;
                for (int i = 0; i < 2; i++)
                    delete[]mas_fio_nomer[i];
                // delete[]mas_fio_nomer;

                return;
            } // end  else
            Label35 -> Visible = true;
            Panel6 -> Visible = true;
            Label33 -> Enabled = true;
            Label34 -> Enabled = true;
            Edit12 -> Enabled = true;
            DateTimePicker2 -> Enabled = true;

        } // end if IsNull
        else
            MessageBox (0, "�� ������ ��������� ����� ������", "", MB_OK);
    } // else if �������� �� ���� ������
}

void __fastcall TDeloForm::Label35Click (TObject *Sender) {

    DataModule1 -> Prikaz_KursFDQuery -> Close ();
    DataModule1 -> Prikaz_KursFDQuery -> SQL -> Clear ();
    DataModule1 -> Prikaz_KursFDQuery -> SQL -> Add
        ("SELECT NOMER, N_KURS, D_PRIKAZ_KURS, N_PRIKAZ_KURS, N_FAC, VID_EDU FROM PRIKAZ_KURS Prikaz_kurs"
        );
    DataModule1 -> Prikaz_KursFDQuery -> Open ();

    DataModule1 -> People_KursFDQuery -> Close ();
    DataModule1 -> People_KursFDQuery -> ParamByName ("GROUP") -> AsInteger = i_gr;
    DataModule1 -> People_KursFDQuery -> Open ();

    for (int i = 0; i < ListBox2 -> Items -> Count; i++) { // for i
        AnsiString List_text = ListBox2 -> Items -> Strings[i];
        int j = List_text.Pos ('.'); // ������� ������ �� ������ ��� ���� ������
        List_text.Delete (1, j + 1);
        for (int j = 0; j < rec; j++) { // for j
            TLocateOptions Opts;
            DataModule1 -> People_KursFDQuery -> Locate ("NOMER",
                (int) (ListBox2 -> Items -> Objects[i]), Opts);
            DataModule1 -> People_KursFDQuery -> Edit ();
            DataModule1 -> People_KursFDQuerySTATUS_KURS -> Value = 0;
            // ��������� �� ��������� ����
            int n = DataModule1 -> People_KursFDQueryNOMER -> Value;
            int k = DataModule1 -> People_KursFDQueryKURS -> Value;
            DataModule1 -> People_KursFDQuery -> ApplyUpdates ();
            DataModule1 -> People_KursFDQuery -> CommitUpdates ();

            DataModule1 -> Prikaz_KursFDQuery -> Insert ();
            DataModule1 -> Prikaz_KursFDQueryNOMER -> Value = n;
            DataModule1 -> Prikaz_KursFDQueryN_KURS -> Value = k;
            DataModule1 -> Prikaz_KursFDQueryD_PRIKAZ_KURS -> Value =
                DateTimeToSQLTimeStamp (DateTimePicker2 -> Date);
            DataModule1 -> Prikaz_KursFDQueryN_PRIKAZ_KURS -> Value =
                StrToInt (Edit12 -> Text);
            DataModule1 -> Prikaz_KursFDQueryN_FAC -> Value = nom_fac;
            DataModule1 -> Prikaz_KursFDQueryVID_EDU -> Value =
                ComboBox5 -> ItemIndex;
            DataModule1 -> Prikaz_KursFDQuery -> ApplyUpdates ();
            DataModule1 -> Prikaz_KursFDQuery -> CommitUpdates ();
            break;
        } // end for j
    } // end for i

    for (int i = 0; i < 2; i++)
        delete[]mas_fio_nomer[i]; // delete[] mas_fio_nomer;

    // �������� ���� ������ �� ����������� � �������� ������ �� ��� ��������
    ListBox2 -> Visible = false;
    ListBox2 -> Clear ();
    Label35 -> Visible = false;
    Panel6 -> Visible = false;
    // -----
    Label33 -> Enabled = false;
    Label34 -> Enabled = false;
    Edit12 -> Enabled = false;
    Edit12 -> Text = "";
    DateTimePicker2 -> Enabled = false;
    DateTimePicker2 -> Date = Now ();
    DateTimePicker2 -> Time = StrToTime ("00:00");
    // -----
    Edit11 -> Text = "";
    ComboBox5 -> ItemIndex = -1;
    ComboBox5 -> SetFocus ();
    DataModule1 -> People_KursFDQuery -> Close ();
    DataModule1 -> Prikaz_KursFDQuery -> Close ();

}

void __fastcall TDeloForm::ComboBox1Change (TObject *Sender) {
    ListBox1 -> Clear ();
    DualListDlg = new TDualListDlg (this);
    DualListDlg -> SrcList -> Items -> Clear ();
    DualListDlg -> DstList -> Items -> Clear ();

    Panel7 -> Visible = True;
}
/*
 void __fastcall TDeloForm::Edit1Change (TObject *Sender)
 {
 ListBox1 -> Clear ();
 DualListDialog1 -> List2 -> Clear ();
 } */

void __fastcall TDeloForm::BitBtn8Click (TObject *Sender) {
    if (MessageDlg
        ("�� ������� ��� ������, ��������� ���� ��������� �� ��������� ����?",
        mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
        { // if
        if (MessageDlg ("���������� ������� ��������� � ��� � �����?",
            mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
        { // if
            DateTimePicker1 -> Date = Now ();
            DateTimePicker1 -> Time = 0;
            if (ComboBox1 -> ItemIndex == -1)
                ShowMessage ("������� ��� ��������");
            else { // else �������� �� ��� ��������
                curent_date = cur_d (); // ������� ������� ����
                String year_cur = DateToStr (curent_date).SubString (7, 4);
                // ������� ������� ���

                sql_head =
                    "SELECT INC_GROUP, VID_EDU, GOD, N_GROUP FROM INCREMENT_GROUP WHERE N_GROUP<>'000' and (VID_EDU=:EDU)";
                AnsiString sql_end;
                if (ComboBox1 -> ItemIndex)
                    sql_end = " N_GROUP NOT LIKE '_6_' ORDER BY N_GROUP";
                // �������
                else
                    sql_end = " N_GROUP NOT LIKE '_5_' ORDER BY N_GROUP";
                // �������
                switch (nom_fac) { // switch
                case 1:
                    sql_dop = "AND N_GROUP STARTING WITH '1' AND"; // ����
                    break;
                case 2:
                    sql_dop = "AND N_GROUP STARTING WITH '2' AND"; // ���
                    break;
                case 3:
                    sql_dop = "AND N_GROUP STARTING WITH '0' AND";
                    // �����
                    break;
                case 4:
                    sql_dop = "AND N_GROUP STARTING WITH '4' AND";
                    // �������� �������
                    break;

                } // end switch

                DataModule1 -> Increment_GroupFDQuery -> SQL -> Clear ();
                DataModule1 -> Increment_GroupFDQuery -> SQL -> Add
                    (sql_head + sql_dop + sql_end);
                DataModule1 -> Increment_GroupFDQuery -> ParamByName ("EDU")
                    -> AsSmallInt = ComboBox1 -> ItemIndex;
                DataModule1 -> Increment_GroupFDQuery -> Open ();
                DataModule1 -> Increment_GroupFDQuery -> Last ();
                // ---�������� Query ��� ��������� ������� �����
                if (year_cur.ToInt ()
                    == DataModule1 -> Increment_GroupFDQueryGOD -> Value)
                { // if ���� ������� ��� = ���� � ������� ����������� �����, �� ��������� �� ��������� ����
                    DataModule1 -> Inc_Group_OldFDQuery -> Open ();
                    // �������� Query ��� ���������� ������ ������� �����
                    for (int i = 0;
                    i < DataModule1 -> Increment_GroupFDQuery -> RecordCount; i++)
                    { // for �� ���������� ����� �� �����
                        AnsiString grup =
                            DataModule1 -> Increment_GroupFDQueryN_GROUP -> Value;
                        AnsiString kurs = grup.SubString (2, 1);
                        kurs = IntToStr (kurs.ToInt () + 1);
                        grup.Delete (2, 1).Insert (kurs, 2);
                        // ����������� 2-�� ������ � ������ ������ �� �������� kurs

                        DataModule1 -> Increment_GroupFDQuery -> Edit ();

                        DataModule1 -> Increment_GroupFDQueryN_GROUP -> Value
                            = grup;
                        DataModule1 -> Increment_GroupFDQueryGOD -> Value =
                            year_cur.ToInt () + 1;
                        // ---  ����� ������� �����
                        DataModule1 -> Inc_Group_OldFDQuery -> Insert ();
                        DataModule1 -> Inc_Group_OldFDQueryINC_GROUP -> Value =
                            DataModule1 -> Increment_GroupFDQueryINC_GROUP -> Value;
                        DataModule1 -> Inc_Group_OldFDQueryN_GROUP -> Value = grup;
                        DataModule1 -> Inc_Group_OldFDQueryVID_EDU -> Value =
                            DataModule1 -> Increment_GroupFDQueryVID_EDU -> Value;
                        DataModule1 -> Inc_Group_OldFDQueryGOD -> Value =
                            year_cur.ToInt () + 1;
                        DataModule1 -> Inc_Group_OldFDQueryDESCRIBE -> Value =
                            year_cur + "/" + (year_cur.ToInt () + 1) +
                            " ������� ���";
                        DataModule1 -> Inc_Group_OldFDQuery -> Post ();
                        // ------
                        DataModule1 -> Increment_GroupFDQuery -> Post ();
                        DataModule1 -> Increment_GroupFDQuery -> Prior ();
                    } // end for

                    DataModule1 -> Increment_GroupFDQuery -> ApplyUpdates ();
                    DataModule1 -> Increment_GroupFDQuery -> CommitUpdates ();

                    DataModule1 -> Inc_Group_OldFDQuery -> ApplyUpdates ();
                    DataModule1 -> Inc_Group_OldFDQuery -> CommitUpdates ();

                    DM2 -> Increment_GroupFDTable -> Close ();
                    DM2 -> Increment_GroupFDTable -> Open ();

                    // SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND
                    // FROM PEOPLE People

                    DataModule1 -> PeopleUpFDQuery -> Close ();
                    DataModule1 -> PeopleUpFDQuery -> SQL -> Clear ();
                    DataModule1 -> PeopleUpFDQuery -> SQL -> Add
                        ("SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND, FAM ||' '|| NAME ||' ' || OTCH as FIO, D_INCLUDE, DATE_END FROM PEOPLE WHERE (STATUS_PEOPLE=1) AND (N_FAC=:FAC) AND (VID_EDU=:EDU) ORDER BY N_GROUP"
                        );
                    DataModule1 -> PeopleUpFDQuery -> ParamByName ("FAC")
                        -> AsSmallInt = nom_fac;
                    DataModule1 -> PeopleUpFDQuery -> ParamByName ("EDU")
                        -> AsSmallInt = ComboBox1 -> ItemIndex;
                    DataModule1 -> PeopleUpFDQuery -> Open ();
                    DataModule1 -> PeopleUp_CountFDQuery -> Close ();
                    DataModule1 -> PeopleUp_CountFDQuery -> SQL -> Clear ();
                    DataModule1 -> PeopleUp_CountFDQuery -> SQL -> Add
                        ("SELECT COUNT (NOMER) FROM PEOPLE WHERE (STATUS_PEOPLE=1) AND (N_FAC=:FAC) AND (VID_EDU=:EDU)"
                        );
                    DataModule1 -> PeopleUp_CountFDQuery -> ParamByName ("FAC")
                        -> AsSmallInt = nom_fac;
                    DataModule1 -> PeopleUp_CountFDQuery -> ParamByName ("EDU")
                        -> AsSmallInt = ComboBox1 -> ItemIndex;
                    DataModule1 -> PeopleUp_CountFDQuery -> Open ();
                    // ---- �������� ��� ������������ ������� �������� N_Group and KURS
                    ProgressBar1 -> Visible = true;
                    ProgressBar1 -> Min = 0;
                    ProgressBar1 -> Max =
                        DataModule1 -> PeopleUp_CountFDQueryCOUNT -> Value;
                    DataModule1 -> PeopleUpFDQuery -> First ();
                    for (int i = ProgressBar1 -> Min; i < ProgressBar1 -> Max; i++)
                    {
                        ProgressBar1 -> Position = i;
                        if (!DataModule1 -> Increment_GroupFDQuery -> Active)
                            DataModule1 -> Increment_GroupFDQuery -> Open ();

                        Variant v = DataModule1 -> Increment_GroupFDQuery -> Lookup
                            ("INC_GROUP",
                            DataModule1 -> PeopleUpFDQueryINC_GROUP -> Value,
                            "N_GROUP");
                        if (!v.IsNull ()) {
                            DataModule1 -> PeopleUpFDQuery -> Edit ();
                            DataModule1 -> PeopleUpFDQueryKURS -> Value =
                                DataModule1 -> PeopleUpFDQueryKURS -> Value + 1;
                            DataModule1 -> PeopleUpFDQueryN_GROUP -> Value =
                                v.AsType (varString);
                            DataModule1 -> PeopleUpFDQuerySTATUS_KURS -> Value = 1;
                            // ������� �������
                            DataModule1 -> PeopleUpFDQuery -> Post ();
                        }
                        DataModule1 -> PeopleUpFDQuery -> Next ();
                        // do something with record...
                    }
                    // -----
                    DataModule1 -> PeopleUpFDQuery -> ApplyUpdates ();
                    DataModule1 -> PeopleUpFDQuery -> CommitUpdates ();
                    ProgressBar1 -> Visible = false;
                } // end if ������� ���
                else { // else ������ �� ������ ��� ��������
                    ShowMessage ("�� ��� �������� ������ �����!");

                } // end else
                Panel7 -> Visible = true;
                if (ComboBox1 -> ItemIndex) { // ���� ��� �������� �������
                    RadioGroup1 -> Items -> Clear ();
                    RadioGroup1 -> Items -> Add ("2 ����");
                    RadioGroup1 -> Items -> Add ("3 ����");
                    RadioGroup1 -> Items -> Add ("4 ����");
                    RadioGroup1 -> Items -> Add ("5 ����");
                    RadioGroup1 -> ItemIndex = -1;
                } // end if
                else { // ���� ��� �������� �������
                    RadioGroup1 -> Items -> Clear ();
                    RadioGroup1 -> Items -> Add ("2 ����");
                    RadioGroup1 -> Items -> Add ("3 ����");
                    RadioGroup1 -> Items -> Add ("4 ����");
                    RadioGroup1 -> ItemIndex = -1;
                } // end else

            } // end else �������� �� ��� ��������
        }
    }
}

void __fastcall TDeloForm::RadioGroup1Click (TObject * Sender) {
    if (RadioGroup1 -> ItemIndex != -1) { // ���� ������� ������ ����
        kurs = AnsiString (RadioGroup1 -> ItemIndex + 2);
        // ���������� ��� ������ ����� ��� �������������
        if (mas) { // ������  ��������
            for (int i = 0; i < 2; i++)
                delete[]mas_fio_nomer[i];
            // delete[]mas_fio_nomer;
            mas = 0;
        } // ����� ����� ������

        DataModule1 -> People_PartFDQuery -> Close ();
        DataModule1 -> People_PartFDQuery -> SQL -> Clear ();
        DataModule1 -> People_PartFDQuery -> SQL -> Add
           // ("SELECT NOMER, FAM, NAME, OTCH, INC_GROUP, N_GROUP, KURS, VID_EDU, N_FOUND FROM PEOPLE WHERE (STATUS_KURS=1) AND (STATUS_PEOPLE=1) AND (N_FAC=:FAC) AND (VID_EDU=:EDU) AND (KURS=:K) ORDER BY FAM, NAME, OTCH"
           // );
            ("SELECT NOMER, FAM, NAME, OTCH, INC_GROUP, N_GROUP, KURS, VID_EDU, N_FOUND FROM PEOPLE WHERE (STATUS_KURS=0) AND (STATUS_PEOPLE=1) AND (N_FAC=4) AND (VID_EDU=0) AND (KURS=3) ORDER BY FAM, NAME, OTCH"
            );
        DataModule1 -> People_PartFDQuery -> ParamByName ("FAC") -> AsSmallInt =
            nom_fac;
        DataModule1 -> People_PartFDQuery -> ParamByName ("EDU") -> AsSmallInt =
            ComboBox1 -> ItemIndex;
        DataModule1 -> People_PartFDQuery -> ParamByName ("K") -> AsSmallInt =
            RadioGroup1 -> ItemIndex + 2;
        DataModule1 -> People_PartFDQuery -> Open ();

        DataModule1 -> People_Part_CountFDQuery -> Close ();
        DataModule1 -> People_Part_CountFDQuery -> SQL -> Clear ();
        DataModule1 -> People_Part_CountFDQuery -> SQL -> Add
            //("SELECT COUNT (NOMER) FROM PEOPLE WHERE (STATUS_KURS=1) AND (STATUS_PEOPLE=1) AND (N_FAC=:FAC) AND (VID_EDU=:EDU) AND (KURS=:K)"
            //);
            ("SELECT COUNT (NOMER) FROM PEOPLE WHERE (STATUS_KURS=0) AND (STATUS_PEOPLE=1) AND (N_FAC=4) AND (VID_EDU=0) AND (KURS=3)"
            );
        DataModule1 -> People_Part_CountFDQuery -> ParamByName ("FAC") -> AsSmallInt =
            nom_fac;
        DataModule1 -> People_Part_CountFDQuery -> ParamByName ("EDU") -> AsSmallInt =
            ComboBox1 -> ItemIndex;
        DataModule1 -> People_Part_CountFDQuery -> ParamByName ("K") -> AsSmallInt =
            RadioGroup1 -> ItemIndex + 2;
        DataModule1 -> People_Part_CountFDQuery -> Open ();

        rec = DataModule1 -> People_Part_CountFDQueryCOUNT -> Value;

        for (int i = 0; i < 2; i++) { // for1
            mas_fio_nomer[i] = new AnsiString[rec];
            mas = 1;
        } // end for 1

        DualListDlg = new TDualListDlg (this);
        DualListDlg -> SrcList -> Items -> Clear ();
        DualListDlg -> DstList -> Items -> Clear ();

        for (int i = 0; i < rec; i++) { // for 2

            mas_fio_nomer[0][i] =
                AnsiString (DataModule1 -> People_PartFDQueryFAM -> Value + " " +
                DataModule1 -> People_PartFDQueryNAME -> Value + " " +
                DataModule1 -> People_PartFDQueryOTCH -> Value + " " +
                DataModule1 -> People_PartFDQueryN_GROUP -> Value + " ��.");
            // DualListDialog1 -> List1 -> Add (mas_fio_nomer[0][i]);

            DualListDlg -> SrcList -> Items -> AddObject (mas_fio_nomer[0][i],
                (TObject*) (DataModule1 -> People_PartFDQueryNOMER -> Value));

            mas_fio_nomer[1][i] =
                AnsiString (DataModule1 -> People_PartFDQueryNOMER -> Value);
            DataModule1 -> People_PartFDQuery -> Next ();
        } // end for 2

        // -------------

        DualListDlg -> ShowModal ();

        if (DataModule2 -> printdlg == true)
            // (DualListDialog1 -> Execute ())
        { // if  Execute
            ListBox1 -> Visible = true;
            for (int i = 0; i < DualListDlg -> DstList -> Items -> Count;
            i++) // (int i = 0; i < DualListDialog1 -> List2 -> Count; i++)
            { // for 3
                // if (i<9) ListBox1 -> Items -> Add ("0"+AnsiString (i+1)+". "+DualListDialog1 -> List2 -> Strings[i]);
                // else    ListBox1 -> Items -> Add (AnsiString (i+1)+". "+DualListDialog1 -> List2 -> Strings[i]);

                if (i < 9)
                    ListBox1 -> Items -> Add ("0" + AnsiString (i + 1) + ". " +
                    DualListDlg -> DstList -> Items -> Strings[i]);
                else
                    ListBox1 -> Items -> Add (AnsiString (i + 1) + ". " +
                    DualListDlg -> DstList -> Items -> Strings[i]);

            } // end for 3
            // ------------
            if (DualListDlg -> DstList -> Items -> Count > 0)
                // (DualListDialog1 -> List2 -> Count>0)
            { // ���� ������ ������ ���� �������
                Panel1 -> Visible = true;
                Label29 -> Enabled = true;
                Label30 -> Enabled = true;
                Edit10 -> Enabled = true;
                DateTimePicker1 -> Enabled = true;
            } // end if ������ �������
        } // end if   Execute
        else { // else - ���� � ������� ������ �������, �� ���� ������� ������
            delete DualListDlg;
            if (mas) {
                for (int i = 0; i < 2; i++)
                    delete[]mas_fio_nomer[i];
                // delete[]mas_fio_nomer;
                mas = 0;
            }
            DataModule1 -> People_PartFDQuery -> Close ();
        } // end else

    } // ���� ������� ������ ����
}

void __fastcall TDeloForm::Panel1Click (TObject * Sender) {
    if (Edit10 -> Text == "")
        ShowMessage ("������� ������ �� ���� � ������ �������");
    else { // else �������� �� ���� ������
        DataModule1 -> Prikaz_KursFDQuery -> Close ();
        DataModule1 -> Prikaz_KursFDQuery -> SQL -> Clear ();
        DataModule1 -> Prikaz_KursFDQuery -> SQL -> Add
            ("SELECT NOMER, N_KURS, D_PRIKAZ_KURS, N_PRIKAZ_KURS, N_FAC, VID_EDU FROM PRIKAZ_KURS Prikaz_kurs"
            );
        DataModule1 -> Prikaz_KursFDQuery -> Open ();

        DataModule1 -> PeopleUpFDQuery -> Close ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Clear ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Add
            ("SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, N_GROUP, D_INCLUDE, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND, FAM ||' '|| NAME ||' ' || OTCH as FIO, D_INCLUDE, DATE_END FROM PEOPLE WHERE (STATUS_PEOPLE=1) AND (N_FAC=4) AND (VID_EDU=0) ORDER BY N_GROUP"
            );
        DataModule1 -> PeopleUpFDQuery -> ParamByName ("FAC") -> AsSmallInt = nom_fac;
        DataModule1 -> PeopleUpFDQuery -> ParamByName ("EDU") -> AsSmallInt =
            ComboBox1 -> ItemIndex;
        DataModule1 -> PeopleUpFDQuery -> Open ();

        // -------
        ProgressBar1 -> Visible = true;
        ProgressBar1 -> Min = 0;
        // -------

        for (int i = 0; i < ListBox1 -> Items -> Count; i++) { // for i

            ProgressBar1 -> Max = ListBox1 -> Items -> Count;
            ProgressBar1 -> Position = i;
            AnsiString List_text = ListBox1 -> Items -> Strings[i];
            int j = List_text.Pos ('.');
            // ������� ������ �� ������ ��� ���� ������
            List_text.Delete (1, j + 1);
            for (int j = 0; j < rec; j++) { // for j
                if (List_text == mas_fio_nomer[0][j]) { // if
                    int n = mas_fio_nomer[1][j].ToInt ();
                    int k = kurs.ToInt ();
                    // �������� �� ��������� ������� �� ���� �� ����
                    Variant prov[2];
                    prov[0] = Variant (n);
                    // ����� ��������
                    prov[1] = Variant (k); // ����� �����
                    Variant LookupResults =
                        DataModule1 -> Prikaz_KursFDQuery -> Lookup ("NOMER;N_KURS",
                        VarArrayOf (prov, 1), "NOMER;N_KURS");
                    if (LookupResults.IsNull ())
                    { // �������� �� ��������� ������� �� ���� �� ����
                        DataModule1 -> Prikaz_KursFDQuery -> Insert ();
                        DataModule1 -> Prikaz_KursFDQueryNOMER -> Value = n;
                        DataModule1 -> Prikaz_KursFDQueryN_KURS -> Value = k;
                        DataModule1 -> Prikaz_KursFDQueryD_PRIKAZ_KURS -> Value =
                            DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);
                        DataModule1 -> Prikaz_KursFDQueryN_PRIKAZ_KURS -> Value =
                            StrToInt (Edit10 -> Text);
                        DataModule1 -> Prikaz_KursFDQueryN_FAC -> Value = nom_fac;
                        DataModule1 -> Prikaz_KursFDQueryVID_EDU -> Value =
                            ComboBox1 -> ItemIndex;
                        DataModule1 -> Prikaz_KursFDQuery -> ApplyUpdates ();
                        DataModule1 -> Prikaz_KursFDQuery -> CommitUpdates ();

                        /* mas_fio_nomer[0][j]="";
                         mas_fio_nomer[1][j]=""; */ break;
                    } // �������� �� ��������� ������� �� ���� �� ����
                    else {
                        AnsiString mes = "������� " + List_text +
                            " ��� ��� ��������� �� " + kurs +
                            " ����.\n�������� ����� ������?";
                        // !!!if (Application -> MessageBox (mes.c_str (),"��������", MB_OKCANCEL) == IDOK)
                        if (MessageDlg (mes.c_str (), mtWarning,
                            TMsgDlgButtons () << mbOK << mbCancel, 0) == 1)
                            // ShowMessage ("������� "+List_text+" ��� ��� ��������� �� "+kurs+" ����!");
                        {
                            DataModule1 -> Prikaz_KursFDQuery -> Insert ();
                            DataModule1 -> Prikaz_KursFDQueryNOMER -> Value = n;
                            DataModule1 -> Prikaz_KursFDQueryN_KURS -> Value = k;
                            DataModule1 -> Prikaz_KursFDQueryD_PRIKAZ_KURS -> Value
                                = DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);
                            DataModule1 -> Prikaz_KursFDQueryN_PRIKAZ_KURS -> Value
                                = StrToInt (Edit10 -> Text);
                            DataModule1 -> Prikaz_KursFDQueryN_FAC -> Value =
                                nom_fac;
                            DataModule1 -> Prikaz_KursFDQueryVID_EDU -> Value =
                                ComboBox1 -> ItemIndex;
                            DataModule1 -> Prikaz_KursFDQuery -> ApplyUpdates ();
                            DataModule1 -> Prikaz_KursFDQuery -> CommitUpdates ();

                            /* mas_fio_nomer[0][j]="";
                             mas_fio_nomer[1][j]=""; */ break;
                        }
                        else {
                            /* mas_fio_nomer[0][j]="";
                             mas_fio_nomer[1][j]=""; */ break;
                        }
                    }

                } // end if
            } // end for j
        } // end for i
        ProgressBar1 -> Visible = false;
        // -----------------
        /* for (int kkk=0;kkk<rec;kkk++)
         { //for kkk
         if (mas_fio_nomer[0][kkk]!="")
         { //if
         int nom=mas_fio_nomer[1][kkk].ToInt ();
         int k=kurs.ToInt ();
         //�������� �� ��������� ������� �� ���� �� ����
         Variant proverka[2];
         proverka[0] = Variant (nom);    // ����� ��������
         proverka[1] = Variant (k);    // ����� �����
         Variant Results=DataModule1 -> Prikaz_KursQuery -> Lookup ("NOMER;N_KURS", VarArrayOf (proverka, 1), "NOMER;N_KURS");
         if (!Results.IsNull ())
         {  //���� ��� ������
         TLocateOptions Opts;
         DataModule1 -> PeopleUpQuery -> Locate ("NOMER", (mas_fio_nomer[1][kkk]).ToInt (), Opts);
         DataModule1 -> PeopleUpQuery -> Edit ();
         DataModule1 -> PeopleUpQuerySTATUS_KURS -> Value=0;  //   ��������� �� ��������� ����

         DataModule1 -> PeopleUpQuery -> ApplyUpdates ();
         DataModule1 -> PeopleUpQuery -> CommitUpdates ();
         mas_fio_nomer[0][kkk]="";
         mas_fio_nomer[1][kkk]="";
         } //����� �������� �� ���������� ������
         else
         {
         mas_fio_nomer[0][kkk]="";
         mas_fio_nomer[1][kkk]="";
         }
         }//end if
         }//end for kkk */
        // ----------------
        for (int i = 0; i < ListBox1 -> Items -> Count; i++) {
            AnsiString List_text = ListBox1 -> Items -> Strings[i];
            int j = List_text.Pos ('.');
            // ������� ������ �� ������ ��� ���� ������
            List_text.Delete (1, j + 1);
            for (int kkk = 0; kkk < rec; kkk++) {
                if (List_text == mas_fio_nomer[0][kkk]) {
                    FDStoredProc1 -> ParamByName ("NOMER") -> AsString =
                        mas_fio_nomer[1][kkk];
                    FDStoredProc1 -> Prepare ();
                    FDStoredProc1 -> ExecProc ();
                    FDStoredProc1 -> Unprepare ();
                    FDStoredProc1 -> Close ();
                }
            }
        }

        if (mas) {
            for (int i = 0; i < 2; i++)
                delete[]mas_fio_nomer[i];
            // delete[]mas_fio_nomer;
            mas = 0;
        }

        // �������� ���� ������ �� ����������� � �������� ������ �� ��� ��������
        ListBox1 -> Clear ();
        ListBox1 -> Visible = false;
        // Label3 -> Visible=false;
        Panel1 -> Visible = true;
        // -----
        Label29 -> Enabled = false;
        Label30 -> Enabled = false;
        Edit10 -> Enabled = false;
        Edit10 -> Text = "";
        DateTimePicker1 -> Enabled = false;
        DateTimePicker1 -> Date = Now ();
        DateTimePicker1 -> Time = StrToTime ("00:00");
        // -----
        DataModule1 -> PeopleUpFDQuery -> Close ();
        DataModule1 -> Prikaz_KursFDQuery -> Close ();
        DataModule1 -> People_PartFDQuery -> Close ();
    } // else �������� �� ���� ������
}

void __fastcall TDeloForm::BitBtn9Click (TObject * Sender)
{ // �� �������� ������������� �������, �������� �� ������
    // ������� �������� ��� ����������� ��� � ������������� ������

    i_gr = search_increment_group (Edit1 -> Text, ComboBox6 -> ItemIndex);
    if (!i_gr.IsNull ()) { // �������� ��������� ������ ���� ������
        // sql_old="SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND FROM PEOPLE People";

        DataModule1 -> PeopleUpFDQuery -> Close ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Clear ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Add
            ("SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND, FAM ||' '|| NAME ||' ' || OTCH as FIO, D_INCLUDE, DATE_END FROM PEOPLE People WHERE (N_FAC=" +
            AnsiString (nom_fac) +
            ") AND (STATUS_PEOPLE=1) AND (INC_GROUP=:I_GR) ORDER BY FAM, NAME, OTCH");
        DataModule1 -> PeopleUpFDQuery -> ParamByName ("I_GR") -> AsInteger = i_gr;
        DataModule1 -> PeopleUpFDQuery -> Open ();

        if (DataModule1 -> PeopleUpFDQuery -> RecordCount)
        { // ���� � ������ ���� ��������, �� ���������:
            Panel8 -> Visible = true; // ������ � ������ � �/�

            DataModule1 -> HolidayFDQuery -> Open ();
            DataModule1 -> HolidayFDQuery -> Insert ();
        }
        else { // � ��������� ������ ��� �� ������ ��������
            ShowMessage (
                "� ��������� ������ ��� �� ������ �������� ��� ������� ������ �� � ������ ����������!");
            Edit1 -> SetFocus ();
        }

    }
    else { // ���� �� ������� ��������� ������, �� ����� ������ ���
        ShowMessage ("�� ������ ����� ������!");
        Edit1 -> SetFocus ();
    }

}

void __fastcall TDeloForm::RadioGroup2Click (TObject * Sender)
{ // �������� ������������� ������� -- ������� �� RadioGroup ���������� ������ ������
    switch (RadioGroup2 -> ItemIndex) { // switch
    case -1: // ������ ���� ��������
        Panel9 -> Visible = false;
        // ����� ������ ������ � ���� ��������
        Panel10 -> Visible = false;
        // ������ ��� ��������� � ������ �� �/�
        Panel8 -> Visible = false; // ���� � �/�
        break;
    case 0: // ���� � ������������� ������
        Panel9 -> Visible = true;
        // ����� ������ ������ � ���� ��������
        Panel10 -> Visible = false;
        // ������ ��� ��������� � ������ �� �/�
        break;
        /* case 1: //��������� �������������� �������
         Panel9 -> Visible=false; //����� ������ ������ � ���� ��������
         Panel8 -> Visible=false; //������ ��� ����� � �/�
         Panel10 -> Visible=true; //����� ������ ��� ��������� � ������ �� �/�
         //��������� � Label50 ������ ���������� ��������
         Label50 -> Caption=RadioGroup2 -> Items -> Strings[RadioGroup2 -> ItemIndex];

         break; */ default: // ����� �� �������������� �������
        Panel9 -> Visible = false;
        // ����� ������ ������ � ���� ��������
        Panel8 -> Visible = false; // ������ ��� ����� � �/�

        DataModule1 -> PeopleUpFDQuery -> Close ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Clear ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Add
            ("SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND, FAM ||' '|| NAME ||' ' || OTCH as FIO, D_INCLUDE, DATE_END FROM PEOPLE People WHERE (N_FAC=" +
            AnsiString (nom_fac) + ") AND (STATUS_PEOPLE=3)");
        DataModule1 -> PeopleUpFDQuery -> Open ();

        if (DataModule1 -> PeopleUpFDQuery -> RecordCount)
        { // ���� � ������ ���� ��������, �� ���������:

            Panel10 -> Visible = true;
            // ����� ������ ��� ��������� � ������ �� �/�
            // ��������� � Label50 ������ ���������� ��������
            Label50 -> Caption =
                RadioGroup2 -> Items -> Strings[RadioGroup2 -> ItemIndex];
            if (RadioGroup2 -> ItemIndex == 1)
            { // if ��������� �������������� �������
                Edit15 -> Visible = false; // ����� ������
                Label49 -> Caption = "������� ���������:";
                Label48 -> Visible = true;
                // �/� �������        ��: (�����)
                DateTimePicker8 -> Visible = true;
                // �/� �������        ��:
                Label47 -> Caption = "�/� �������         c:";
                DBLookupComboBox8 -> Visible = true; // ������� �������
            } // end if ��������� �������������� �������
            else { // else ����� �� �������������� �������
                Edit15 -> Visible = true; // ����� ������
                Label49 -> Caption = "� ������:";
                Label48 -> Visible = false;
                // �/� �������        ��: (�����)
                DateTimePicker8 -> Visible = false;
                // �/� �������        ��:
                Label47 -> Caption = "������� ����������� �:";
                DBLookupComboBox8 -> Visible = false; // ������� �������
            } // end else ����� �� �������������� �������

            DataModule1 -> HolidayFDQuery -> Open ();
            DataModule1 -> HolidayFDQuery -> Insert ();
        }
        else { // � ��������� ������ ��� �� ������ ��������
            ShowMessage (
                "�� ����� ���������� ��� ��������� � ������������� �������!");
            RadioGroup2 -> ItemIndex = -1;
        }

        break;
    } // end switch
}

void __fastcall TDeloForm::BitBtn11Click (TObject * Sender)
{ // �������� ������������� �������, �������� �� ������ ��������
    // ��� ������ ����� � ������������� ������
    DataModule1 -> HolidayFDQuery -> CancelUpdates ();
    DataModule1 -> PeopleUpFDQuery -> Close ();
    // ----------
    Panel9 -> Visible = false;
    Edit1 -> Text = ""; // � ������
    ComboBox6 -> ItemIndex = -1; // ����� ��������
    // --------------------
    Panel8 -> Visible = false;
    DBLookupComboBox3 -> KeyValue = -1; // ���
    DBLookupComboBox6 -> KeyValue = -1; // ������� �����
    Edit13 -> Text = ""; // �������� � �������
    DateTimePicker3 -> Date = Now (); // �������� ���� �������
    DateTimePicker3 -> Time = StrToTime ("00:00");
    DateTimePicker4 -> Date = Now ();
    // �������� ���� ������ �/�
    DateTimePicker4 -> Time = StrToTime ("00:00");
    DateTimePicker5 -> Date = Now ();
    // �������� ���� ��������� �/�
    DateTimePicker5 -> Time = StrToTime ("00:00");
    // ----------------------
    RadioGroup2 -> ItemIndex = -1; // ����������  RadioGroup2
}

void __fastcall TDeloForm::BitBtn10Click (TObject * Sender)
{ // �������� ������������� �������, �������� �� ������ ���������
    // ��� ����� � ������������� ������
    try {
        TLocateOptions fl;
        if (DataModule1 -> HolidayFDQuery -> State != dsInsert)
            DataModule1 -> HolidayFDQuery -> Insert ();
        // ���������� � ���� Holiday ������ ��������
        DataModule1 -> HolidayFDQueryNOMER -> Value = DBLookupComboBox3 -> KeyValue;
        // ��� 1 -- ���� � �/�; 2-- ������� �/�;  3-- ����� �� �/�
        DataModule1 -> HolidayFDQueryTYPE_HOL -> Value = RadioGroup2 -> ItemIndex + 1;
        DataModule1 -> HolidayFDQueryN_HOL -> Value = DBLookupComboBox6 -> KeyValue;
        // �����  �������
        DataModule1 -> HolidayFDQueryN_PRIKAZ_HOL -> Value = StrToInt (Edit13 -> Text);
        // ���� �������
        DataModule1 -> HolidayFDQueryD_PRIKAZ_HOL -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker3 -> Date);
        // ���� ������ �/�
        DataModule1 -> HolidayFDQueryD_BEGIN_HOL -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker4 -> Date);
        // ���� ��������� �/�
        DataModule1 -> HolidayFDQueryD_END_HOL -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker5 -> Date);

        DataModule1 -> HolidayFDQuery -> ApplyUpdates ();

        DataModule1 -> PeopleUpFDQuery -> Open ();
        DataModule1 -> PeopleUpFDQuery -> Locate ("NOMER",
            DBLookupComboBox3 -> KeyValue, fl);
        DataModule1 -> PeopleUpFDQuery -> Edit ();
        if (DataModule1 -> PeopleUpFDQuerySTATUS_KURS -> Value == 1) {
            if (MessageDlg
                ("���� ������� ��� ������� ��������� �� ��������� ����. �������� ����� ������ � ����?",
                mtConfirmation, TMsgDlgButtons () << mbOK << mbCancel, 0) == 1)
            { // if �������� ����� ������ � ���� �� ���� ������
                int old_kurs = DataModule1 -> PeopleUpFDQueryKURS -> Value;
                int old_gr =
                    StrToInt (DataModule1 -> PeopleUpFDQueryN_GROUP -> Value);
                if (old_kurs != 1) {
                    DataModule1 -> PeopleUpFDQueryKURS -> Value = (old_kurs - 1);
                    if (nom_fac == 3)
                    { // if ��� ����� - �� ���� ������� ��������� 0
                        DataModule1 -> PeopleUpFDQueryN_GROUP -> Value =
                            "0" + IntToStr (old_gr - 10);
                    }
                    else
                        DataModule1 -> PeopleUpFDQueryN_GROUP -> Value =
                            IntToStr (old_gr - 10);
                }
            }

            DataModule1 -> PeopleUpFDQuerySTATUS_KURS -> Value = 0;
        }
        DataModule1 -> PeopleUpFDQuerySTATUS_PEOPLE -> Value = 3;
        // ������ ��� �����������
        DataModule1 -> PeopleUpFDQueryINC_GROUP -> Value = 18;
        // ���������� ��� ������ � ������� 000
        DataModule1 -> PeopleUpFDQuery -> ApplyUpdates ();

        DataModule1 -> PeopleUpFDQuery -> CommitUpdates ();
        DataModule1 -> PeopleUpFDQuery -> Close ();
        DataModule1 -> HolidayFDQuery -> CommitUpdates ();
        // -----

        Panel9 -> Visible = false;
        Edit1 -> Text = ""; // � ������
        ComboBox6 -> ItemIndex = -1; // ����� ��������
        // ---------
        Panel8 -> Visible = false;
        Edit13 -> Text = "";
        // �������� � �������
        DateTimePicker3 -> Date = Now (); // �������� ���� �������
        DateTimePicker3 -> Time = StrToTime ("00:00");
        DateTimePicker4 -> Date = Now (); // �������� ���� ������ �/�
        DateTimePicker4 -> Time = StrToTime ("00:00");
        DateTimePicker5 -> Date = Now (); // �������� ���� ��������� �/�
        DateTimePicker5 -> Time = StrToTime ("00:00");
        RadioGroup2 -> ItemIndex = -1;
        // ����������  RadioGroup2
        // -----
    }
    catch (...) {
        ShowMessage (
            "�������� ������, ��������� ��� ������ � ���������� ��� ���!");
        DataModule1 -> HolidayFDQuery -> CancelUpdates ();
    }

}

void __fastcall TDeloForm::ComboBox6Change (TObject * Sender) {
    Panel8 -> Visible = false;
}

void __fastcall TDeloForm::BitBtn13Click (TObject * Sender)
{ // �������� ������������� �������, �������� �� ������ ��������
    // ��� ������ ������ �� �������������� ������� ��� ��� ���������
    DataModule1 -> HolidayFDQuery -> CancelUpdates ();
    DataModule1 -> PeopleUpFDQuery -> Close ();
    // -------------
    Panel9 -> Visible = false;
    Edit1 -> Text = ""; // �������� � ������
    ComboBox6 -> ItemIndex = -1; // ��� ��������
    // -------------
    Panel10 -> Visible = false;
    DBLookupComboBox7 -> KeyValue = -1; // ���
    DBLookupComboBox8 -> KeyValue = -1; // �������
    Edit14 -> Text = ""; // �������� � �������
    Edit15 -> Text = ""; // �������� � ������
    DateTimePicker6 -> Date = Now (); // �������� ���� �������
    DateTimePicker6 -> Time = StrToTime ("00:00");
    DateTimePicker7 -> Date = Now ();
    // �������� ���� ��������� �/�  �:
    DateTimePicker7 -> Time = StrToTime ("00:00");
    DateTimePicker8 -> Date = Now ();
    // �������� ���� �/� ��������� ��:
    DateTimePicker8 -> Time = StrToTime ("00:00");
    RadioGroup2 -> ItemIndex = -1;
    // ����������  RadioGroup2
    // -----

}

void __fastcall TDeloForm::BitBtn12Click (TObject * Sender)
{ // �������� ������������� �������, �������� �� ������ ���������
    // ��� ��������� �������������� ������� ��� ������ �� �/�
    try {
        TLocateOptions fl;
        if (DataModule1 -> HolidayFDQuery -> State != dsInsert)
            DataModule1 -> HolidayFDQuery -> Insert ();

        // ���������� � ���� Holiday ������ ��������
        DataModule1 -> HolidayFDQueryNOMER -> Value = DBLookupComboBox7 -> KeyValue;
        // ��� 1 -- ���� � �/�; 2-- ������� �/�;  3-- ����� �� �/�
        DataModule1 -> HolidayFDQueryTYPE_HOL -> Value = RadioGroup2 -> ItemIndex + 1;

        // �����  �������
        DataModule1 -> HolidayFDQueryN_PRIKAZ_HOL -> Value = StrToInt (Edit14 -> Text);
        // ���� �������
        DataModule1 -> HolidayFDQueryD_PRIKAZ_HOL -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker6 -> Date);

        if (RadioGroup2 -> ItemIndex == 2) { // if ����� �� �������������� �������

            if (!check_fac_group (Edit15 -> Text))
                return; // �������� �� ����� ������ � ���������

            DataModule1 -> PeopleUpFDQuery -> Open ();
            DataModule1 -> PeopleUpFDQuery -> Locate ("NOMER",
                DBLookupComboBox7 -> KeyValue, fl);
            Variant i_gr = search_increment_group (Edit15 -> Text,
                DataModule1 -> PeopleUpFDQueryVID_EDU -> Value);
            // ---------
            DataModule1 -> PeopleUpFDQuery -> Edit ();
            DataModule1 -> PeopleUpFDQuerySTATUS_PEOPLE -> Value = 1;
            // ������ ��� ������������ ��������
            DataModule1 -> PeopleUpFDQueryINC_GROUP -> Value = i_gr;
            // ���������� ������
            DataModule1 -> PeopleUpFDQueryN_GROUP -> Value = Edit15 -> Text;
            // ����� ������
            DataModule1 -> PeopleUpFDQueryKURS -> Value =
                StrToInt (Edit15 -> Text.SubString (2, 1));
            // ---------

            // ������� ������ ���, ������� � ���� ������ -- ���
            DataModule1 -> HolidayFDQueryN_HOL -> Value =
                DM2 -> Cause_HolidayFDTable -> Lookup ("CAUSE_HOL", "���", "N_HOL");
            // ���� � ������� ������� �� �������, �� �������  � D_END_HOL
            DataModule1 -> HolidayFDQueryD_END_HOL -> Value =
                DateTimeToSQLTimeStamp (DateTimePicker7 -> Date);
        } // end if  ����� �� �������������� �������
        else { // else -- ��������� �/�
            DataModule1 -> HolidayFDQueryN_HOL -> Value =
                DBLookupComboBox8 -> KeyValue;
            // ���� ������ �/�
            DataModule1 -> HolidayFDQueryD_BEGIN_HOL -> Value =
                DateTimeToSQLTimeStamp (DateTimePicker7 -> Date);
            // ���� ��������� �/�
            DataModule1 -> HolidayFDQueryD_END_HOL -> Value =
                DateTimeToSQLTimeStamp (DateTimePicker8 -> Date);

        } // end else -- ��������� �/�
        // ---------
        DataModule1 -> PeopleUpFDQuery -> ApplyUpdates ();
        DataModule1 -> PeopleUpFDQuery -> CommitUpdates ();
        DataModule1 -> HolidayFDQuery -> ApplyUpdates ();
        DataModule1 -> HolidayFDQuery -> CommitUpdates ();
        // -----
        DataModule1 -> PeopleUpFDQuery -> Close ();
        // -------------
        Panel9 -> Visible = false;
        Edit1 -> Text = ""; // �������� � ������
        ComboBox6 -> ItemIndex = -1; // ��� ��������
        // -------------
        Panel10 -> Visible = false;
        DBLookupComboBox7 -> KeyValue = -1; // ���
        DBLookupComboBox8 -> KeyValue = -1; // �������
        Edit14 -> Text = ""; // �������� � �������
        Edit15 -> Text = ""; // �������� � ������
        DateTimePicker6 -> Date = Now (); // �������� ���� �������
        DateTimePicker6 -> Time = StrToTime ("00:00");
        DateTimePicker7 -> Date = Now ();
        // �������� ���� ��������� �/�  �:
        DateTimePicker7 -> Time = StrToTime ("00:00");
        DateTimePicker8 -> Date = Now ();
        // �������� ���� �/� ��������� ��:
        DateTimePicker8 -> Time = StrToTime ("00:00");
        RadioGroup2 -> ItemIndex = -1;
        // ����������  RadioGroup2
        // -----

    } // end try
    catch (...) { // catch
        ShowMessage (
            "�������� ������, ��������� ��� ������ � ���������� ��� ���!");
        DataModule1 -> HolidayFDQuery -> CancelUpdates ();
    } // end catch

}

void __fastcall TDeloForm::RadioGroup3Click (TObject * Sender)
{ // ��������  ���������/���������
    // ������ �� ������ ��� ��������� ��� ���������
    /* AnsiString sql_encourage="SELECT Encourage.NOMER, Encourage.N_TYPE_EN, Encourage.WHAT, \
     Encourage.WHO_TAKE, Encourage.N_PRIKAZ, Encourage.D_PRIKAZ, Type_encourage.VID_EN, \
     Type_encourage.TYPE_EN FROM ENCOURAGE Encourage INNER JOIN TYPE_ENCOURAGE Type_encourage \
     ON  (Encourage.N_TYPE_EN = Type_encourage.N_TYPE_EN)  "; */

    // Query  ��� ������ � DBLookupComboBox10 ��� ���� ���������, ���� ���������
    DataModule1 -> Type_EncourageFDQuery -> Close ();
    DataModule1 -> Type_EncourageFDQuery -> ParamByName ("TYP") -> AsSmallInt =
        RadioGroup3 -> ItemIndex;
    DataModule1 -> Type_EncourageFDQuery -> Open ();
    if (RadioGroup3 -> ItemIndex)
        Label64 -> Caption = "��� ���������";
    else
        Label64 -> Caption = "��� ���������";
    ComboBox12 -> Items -> Clear ();
    if (RadioGroup3 -> ItemIndex) { // if ���������
        ComboBox12 -> Items -> Add ("�� ��������������� �������� ������� �������");
        ComboBox12 -> Items -> Add ("�� ��������� ������ ���������� � ���������");
        ComboBox12 -> Items -> Add ("�� ������������ �������� ������");
        ComboBox12 -> Items -> Add ("�� ��������� ������ ����������� ����������");
    } // end if  ���������
    else { // else  ���������
        ComboBox12 -> Items -> Add
            ("�� �������� �����, �������� ������� � ������������ � ���������� ����� ������������"
            );
        ComboBox12 -> Items -> Add
            ("�� ������� �����, �������� ������� � ������������ � ���������� ����� ������������"
            );
    } // end else ���������
    ComboBox13 -> Items -> Clear ();
    ComboBox13 -> Items -> Add ("������");
    ComboBox13 -> Items -> Add ("�����");
    DBLookupComboBox10 -> Visible = true;
}

void __fastcall TDeloForm::BitBtn14Click (TObject * Sender)
{ // �������� ���������/���������, �������� �� ������ -- ������� ��������

    i_gr = search_increment_group (Edit16 -> Text, ComboBox7 -> ItemIndex);
    if (!i_gr.IsNull ()) {
        // sql_old="SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND FROM PEOPLE People";

        DataModule1 -> PeopleUpFDQuery -> Close ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Clear ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Add
            ("SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND, FAM ||' '|| NAME ||' ' || OTCH as FIO, D_INCLUDE, DATE_END FROM PEOPLE People WHERE (N_FAC=" +
            AnsiString (nom_fac) +
            ") AND (STATUS_PEOPLE=1) AND (INC_GROUP=:I_GR) ORDER BY FAM, NAME, OTCH");
        DataModule1 -> PeopleUpFDQuery -> ParamByName ("I_GR") -> AsInteger = i_gr;
        DataModule1 -> PeopleUpFDQuery -> Open ();

        if (DataModule1 -> PeopleUpFDQuery -> RecordCount) {
            Panel11 -> Visible = true;
            DataModule1 -> EncourageFDQuery -> Open ();
            // DataModule1 -> EncourageFDQuery -> Insert ();
        }
        else {
            ShowMessage ("�������� �� ������� ������ �� ������ ����������!");
            Edit16 -> SetFocus ();
        }

    }
    else {
        ShowMessage ("�� ������ ����� ������!");
        Edit16 -> SetFocus ();
    }

}

void __fastcall TDeloForm::BitBtn15Click (TObject * Sender)
{ // �������� ���������/���������, �������� �� ������ -- ���������
    try { // try
        if (DataModule1 -> EncourageFDQuery -> State != dsInsert)
            DataModule1 -> EncourageFDQuery -> Insert ();

        // ���� ����� �������� �� DBLookupComboBox9
        DataModule1 -> EncourageFDQueryNOMER -> Value = DBLookupComboBox9 -> KeyValue;
        // ���� ����� ��������� ��� ���������
        DataModule1 -> EncourageFDQueryN_TYPE_EN -> Value =
            DBLookupComboBox10 -> KeyValue;
        // ���� ����� � ���� �������, ��� �������, �� ��� �� ��-�����������

        // N_PRIKAZ, D_PRIKAZ,  WHO_TAKE, WHAT
        try {
            DataModule1 -> EncourageFDQueryN_PRIKAZ -> Value =
                StrToInt (Edit33 -> Text);
        }
        catch (...) {
            DataModule1 -> EncourageFDQuery -> Cancel ();
            ShowMessage (
                "����������� ������ ����� �������. ���������� ��� ���!");
            return;
        }
        DataModule1 -> EncourageFDQueryD_PRIKAZ -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker18 -> Date);
        // WHO_TAKE-��� �������
        DataModule1 -> EncourageFDQueryWHO_TAKE -> Value = ComboBox13 -> Text;

        // WHAT - �� ���
        if (correct) {
            DataModule1 -> EncourageFDQueryWHAT -> Value = Edit37 -> Text;
        }
        else {
            DataModule1 -> EncourageFDQueryWHAT -> Value = ComboBox12 -> Text;
        }

        DataModule1 -> EncourageFDQuery -> ApplyUpdates ();
        DataModule1 -> EncourageFDQuery -> CommitUpdates ();
        // ----
        ComboBox7 -> ItemIndex = -1; // ��� ��������
        Edit16 -> Text = ""; // � ������ �� ������
        // ----
        Panel11 -> Visible = false;

        RadioGroup3 -> ItemIndex = -1;
        // ����� ���� ��������� ��� ���������
        DBLookupComboBox10 -> Visible = false;
        // ���������� ��� ��������� ��� ���������
        Label64 -> Caption = "";
        // Label ���   ���������� ��� ��������� ��� ���������
        DBLookupComboBox10 -> KeyValue = -1;
        // �������� ��������� ��� ���������
        DBLookupComboBox9 -> KeyValue = -1; // ���
        ComboBox12 -> Items -> Clear (); // �� ���
        ComboBox13 -> Items -> Clear (); // ��� �������
        DateTimePicker18 -> Date = Now (); // ���� �������
        Edit33 -> Text = ""; // ����� �������
        // -----
        DataModule1 -> EncourageFDQuery -> Close ();
        DataModule1 -> PeopleUpFDQuery -> Close ();
        // ----
    } // end try
    catch (...) { // catch
        ShowMessage (
            "�������� ������, ��������� ��� ������ � ���������� ��� ���!");
        DataModule1 -> EncourageFDQuery -> CancelUpdates ();
    } // end catch
}

void __fastcall TDeloForm::BitBtn16Click (TObject * Sender)
{ // //�������� ���������/���������, �������� �� ������ -- ��������
    if (DataModule1 -> EncourageFDQuery -> State == dsInsert)
        DataModule1 -> EncourageFDQuery -> CancelUpdates ();
    // ----
    // ----
    ComboBox7 -> ItemIndex = -1; // ��� ��������
    Edit16 -> Text = ""; // � ������ �� ������
    // ----
    Panel11 -> Visible = false;

    RadioGroup3 -> ItemIndex = -1; // ����� ���� ��������� ��� ���������
    DBLookupComboBox10 -> Visible = false;
    // ���������� ��� ��������� ��� ���������
    Label64 -> Caption = "";
    // Label ���   ���������� ��� ��������� ��� ���������
    DBLookupComboBox10 -> KeyValue = -1;
    // �������� ��������� ��� ���������
    DBLookupComboBox9 -> KeyValue = -1; // ���
    ComboBox12 -> Items -> Clear (); // �� ���
    ComboBox13 -> Items -> Clear (); // ��� �������
    DateTimePicker18 -> Date = Now (); // ���� �������
    DateTimePicker18 -> Time = StrToTime ("00:00");
    Edit33 -> Text = "";
    // ����� �������
    // -----
    DataModule1 -> EncourageFDQuery -> Close ();
    DataModule1 -> PeopleUpFDQuery -> Close ();

    /* Panel11 -> Visible=false;
     RadioGroup3 -> ItemIndex=-1;
     Label64 -> Caption="";
     DBLookupComboBox10 -> Visible=false;
     // ComboBox7 -> ItemIndex=-1;//��� ��������
     //  Edit16 -> Text="";//  � ������ �� ������ */
    // ----
}

void __fastcall TDeloForm::RadioGroup4Click (TObject * Sender) {
    // �������� �������, ����� ��������� ��������
    // ------
    Panel12 -> Visible = false; // ������ ����� ��������
    Panel12 -> Height = 61; // ���������� ������ � �������������� ��������
    ComboBox8 -> ItemIndex = -1; // ��� ��������  �� ������   Panel12
    Edit17 -> Text = ""; // � ������ �� ������   Panel12
    // -----
    Panel13 -> Visible = false; // ������ ��������
    DBLookupComboBox11 -> KeyValue = -1; // �������������
    DBLookupComboBox12 -> KeyValue = -1; // ���
    RadioGroup6 -> ItemIndex = -1; // ��������� ��������
    RadioGroup7 -> ItemIndex = -1; // ��� ��������  �� ������   Panel13
    Edit18 -> Text = ""; // � ������ �� ������   Panel13
    Edit19 -> Text = ""; // ����
    Edit32 -> Text = ""; // � �������
    DateTimePicker17 -> Date = Now (); // ���� �������
    DateTimePicker17 -> Time = StrToTime ("00:00");
    // ------
    RadioGroup5 -> Visible = true;
    RadioGroup5 -> ItemIndex = -1;
    RadioGroup5 -> Items -> Clear ();
    if (RadioGroup4 -> ItemIndex) { // if ������� � �������� ����������

        RadioGroup5 -> Items -> Add ("������ ��� �������� ��� ������� ��������");
        RadioGroup5 -> Items -> Add
            ("������ ����������� ������������� (�������������)");

    } // end if ������� � �������� ����������
    else { // else ������� ����� ������������

        RadioGroup5 -> Items -> Add ("������� �� ������ ���������");
        RadioGroup5 -> Items -> Add ("������� � ������� ����������");

    } // end else ������� ����� ������������
    if ( (RadioGroup4 -> ItemIndex == 1) & (RadioGroup5 -> ItemIndex == 1)) {
        RadioGroup18 -> Visible = True;
        RadioGroup18 -> ItemIndex = 0;
    }
    else {
        RadioGroup18 -> Visible = False;
        RadioGroup18 -> ItemIndex = 0;
    }
}

void __fastcall TDeloForm::RadioGroup5Click (TObject * Sender) {
    Edit17 -> Text = "";
    RadioGroup6 -> Visible = True;
    RadioGroup7 -> Visible = True;
    Label72 -> Visible = True;
    Label73 -> Visible = True;
    Edit19 -> Visible = True;
    DBLookupComboBox12 -> Visible = True;
    ListBox5 -> Visible = False;
    // �������� �������, ����� ���� ��������
    if (RadioGroup4 -> ItemIndex) // =1
    { // if ������� � �������� ����������
        Panel12 -> Visible = true; // ������ ������ ��������
    } // end if ������� � �������� ����������
    else // =0
    { // else ������� ����� ������������
        if (RadioGroup5 -> ItemIndex) // =1
        { // if � ������� ����������
            Panel13 -> Visible = true; // ������ ��������
            Panel12 -> Visible = false; // ������ ������ ��������
            DataModule1 -> PeopleUpFDQuery -> Close ();
            DataModule1 -> PeopleUpFDQuery -> SQL -> Clear ();
            DataModule1 -> PeopleUpFDQuery -> SQL -> Add
                ("SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND, FAM ||' '|| NAME ||' ' || OTCH as FIO, D_INCLUDE, DATE_END FROM PEOPLE People WHERE (STATUS_PEOPLE=4) ORDER BY FAM"
                );
            // STATUS_PEOPLE=4 ��� �������� � ��� ����� ������ ����������
            DataModule1 -> PeopleUpFDQuery -> Open ();
            DataModule1 -> Public_PrikazFDQuery -> Open ();
            // DataModule1 -> Public_PrikazQuery -> Insert ();
        } // end if  � ������� ����������
        else // =0
        { // else  �� ������ ���������
            Panel12 -> Visible = true; // ������ ������ ��������
            Panel13 -> Visible = false; // ������ ��������
        } // end else �� ������ ���������
    } // end else  ������� ����� ������������
    if ( (RadioGroup4 -> ItemIndex == 1) & (RadioGroup5 -> ItemIndex == 1)) {
        RadioGroup18 -> Visible = True;
        RadioGroup18 -> ItemIndex = 0;
    }
    else {
        RadioGroup18 -> Visible = False;
        RadioGroup18 -> ItemIndex = 0;
    }
}

void __fastcall TDeloForm::BitBtn17Click (TObject * Sender) {
    RadioGroup6 -> Visible = True;
    RadioGroup7 -> Visible = True;
    Label72 -> Visible = True;
    Label73 -> Visible = True;
    Edit19 -> Visible = True;
    DBLookupComboBox12 -> Visible = True;
    ListBox5 -> Visible = False;
    // �������� �������, �������� �� ������ ������� ��������
    if (ComboBox8 -> Text == "" || Edit17 -> Text == "")
    { // if �������� �� ���� ���� ������
        ShowMessage ("������� ��� ������!");
        return;
    } // end if �������� �� ���� ���� ������

    i_gr = search_increment_group (Edit17 -> Text, ComboBox8 -> ItemIndex);
    if (!i_gr.IsNull ()) { // if �������� �� IsNull ()
        // sql_old="SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND FROM PEOPLE People";

        DataModule1 -> PeopleUpFDQuery -> Close ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Clear ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Add
            ("SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, D_INCLUDE, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND, FAM ||' '|| NAME ||' ' || OTCH as FIO, DATE_END  FROM PEOPLE People WHERE (N_FAC=" +
            AnsiString (nom_fac) +
            ") AND (STATUS_PEOPLE=1) AND (INC_GROUP=:I_GR) ORDER BY FAM, NAME, OTCH");
        DataModule1 -> PeopleUpFDQuery -> ParamByName ("I_GR") -> AsInteger = i_gr;
        DataModule1 -> PeopleUpFDQuery -> Open ();

        if (DataModule1 -> PeopleUpFDQuery -> RecordCount)
        { // if �������� ��   RecordCount

            if (RadioGroup4 -> ItemIndex == 0 && RadioGroup5 -> ItemIndex == 0)
            { // if ���� ������� �� ������ ���������
                Panel12 -> Height = 134;
                // ����������� ������ ������ ��������
            } // end if ���� ������� �� ������ ���������
            else { // else ���� ������� ������� ����
                Panel12 -> Height = 61;
                // ���������� ������ � �������������� ��������
                Panel13 -> Visible = true; // ������ ��������
                DataModule1 -> Public_PrikazFDQuery -> Open ();
                DataModule1 -> Public_PrikazFDQuery -> Insert ();
            } // end else ���� ������� ������� ����
        } // end if �������� ��   RecordCount
        else { // else �������� ��   RecordCount
            ShowMessage ("��� �� ������ �������� �� ��������� �������!");
            Edit17 -> SetFocus ();
        } // end else �������� ��   RecordCount

    } // end if  �������� �� IsNull ()
    else { // else �������� �� IsNull ()
        ShowMessage ("�� ������ ����� ������!");
        Edit17 -> SetFocus ();
    } // end else   �������� �� IsNull ()

}

void __fastcall TDeloForm::BitBtn20Click (TObject * Sender)
{ // �������� �������, �������� �� ������ ���������
    // ��� �������� �� ������ ���������

    if (DBLookupComboBox13 -> Text != "") { // if �������� �� ���� ������

        DataModule1 -> PeopleUpFDQuery -> Edit ();
        try { // try
            // ���������� ��� �������� �� ������ ���������
            DataModule1 -> PeopleUpFDQuerySTATUS_PEOPLE -> Value = 4;
            // ������ ��������������
            DataModule1 -> PeopleUpFDQueryINC_GROUP -> Value = 18;
            // ��������� ������ 000
            DataModule1 -> PeopleUpFDQuery -> ApplyUpdates ();
            DataModule1 -> PeopleUpFDQuery -> CommitUpdates ();

            // ------
            Panel12 -> Visible = false; // ������ ����� ��������
            ComboBox8 -> ItemIndex = -1;
            // ��� ��������  �� ������   Panel12
            Edit17 -> Text = ""; // � ������ �� ������   Panel12

            // ------
            RadioGroup4 -> ItemIndex = -1; // ����� ��������� ��������
            RadioGroup5 -> ItemIndex = -1; // ����� ���� ��������
        } // end try
        catch (...) { // catch
            ShowMessage ("��������� ���� ��� ����������, ���������� ��� ���!");
        } // end catch
    } // end if �������� �� ���� ������
    else { // else �������� �� ���� ������
        ShowMessage ("�������� ������� ��������!");
    } // end else �������� �� ���� ������
}

void __fastcall TDeloForm::BitBtn18Click (TObject * Sender) {
    int n;
    if (RadioGroup18 -> ItemIndex == 1) {
        n = ListBox5 -> Items -> Count;
        for (int i = 0; i < n; i++) {
            // �������� �������, �������� �� ������ ���������
            try { // try
                AnsiString describe = "";
                // ------���������� ��������� �  PeopleUpQuery
                if (Edit18 -> Text == "") { // if  �������� �� � ������ � ����
                    ShowMessage ("������� ����� �����!");
                    return;
                } // end if  �������� �� � ������ � ����

                if (Edit32 -> Text == "") { // if  �������� �� � � ���� �������
                    ShowMessage ("������� ����� ��� ���� �������!");
                    return;
                } // end if  �������� �� � � ���� �������

                if (DBLookupComboBox11 -> Text == "")
                { // if  �������� �� ����� �������������
                    ShowMessage ("�������� ������������� ��������!");
                    return;
                } // end if  �������� �� ����� �������������

                if (!check_fac_group (Edit18 -> Text))
                    return; // �������� �� ����� ������ � ���������
                if (!check_group_kurs (Edit18 -> Text, Edit17 -> Text))
                    return; // �������� �� ����� ������ � ����

                i_gr = search_increment_group (Edit18 -> Text,
                    ComboBox8 -> ItemIndex);
                int nomer = (int) (ListBox5 -> Items -> Objects[i]);
                int c_k = 0;
                // ���������� ��� ����������� ����� �������� ���� ������� �������������

                if (!RadioGroup4 -> ItemIndex)
                    c_k = 4; // �������� ������� �� ������ ���������
                if (RadioGroup4 -> ItemIndex && !RadioGroup5 -> ItemIndex)
                    c_k = 3; // �������� ������� �� ������ ��� ��������
                if (RadioGroup4 -> ItemIndex && RadioGroup5 -> ItemIndex)
                    c_k = 0; // �������� ������� �� ������ �������������

                if (c_k) {
                    if (!DataModule1 -> Search_CK (nomer, 2, Edit32 -> Text,
                        DateTimePicker17 -> Date.DateString ()))
                    { // if �� ��������� �������� 0 - ��� �������� �������� ��������
                        ShowMessage (
                            "������� ������������� ��-�� ������� � ������� ����������!");
                        return;
                    }
                }

                if (!i_gr.IsNull ())
                { // if �������� �� ���������� ���������� ������

                    // ----��������� ���������� �� ��������
                    DataModule1 -> PeopleUpFDQuery -> Close ();
                    DataModule1 -> PeopleUpFDQuery -> SQL -> Clear ();
                    DataModule1 -> PeopleUpFDQuery -> SQL -> Add
                        ("SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND, FAM ||' '|| NAME ||' ' || OTCH as FIO, D_INCLUDE, DATE_END FROM PEOPLE People WHERE (N_FAC=" +
                        AnsiString (nom_fac) +
                        ") AND (STATUS_PEOPLE=1) AND (KURS=:KURS) AND (NOMER=:NOMER) ORDER BY FAM, NAME, OTCH");
                    DataModule1 -> PeopleUpFDQuery -> ParamByName ("KURS")
                        -> AsInteger = Variant (Edit17 -> Text);
                    DataModule1 -> PeopleUpFDQuery -> ParamByName ("NOMER")
                        -> AsInteger = nomer;
                    DataModule1 -> PeopleUpFDQuery -> Open ();
                    // ----��������� ���������� �� ��������

                    describe += " � ";
                    describe += DM2 -> SpecializFDTable -> Lookup ("N_SPECIALIZ",
                        DataModule1 -> PeopleUpFDQueryN_SPECIALIZ -> Value,
                        "SPECIAL");
                    describe += " �� ";
                    describe += DBLookupComboBox11 -> Text;

                    DataModule1 -> PeopleUpFDQuery -> Edit ();
                    // �������� �� ������� ������������ ������ ��������

                    if (DataModule1 -> PeopleUpFDQuerySTATUS_KURS -> Value == 1)
                    { // if  STATUS_KURS =1
                        DataModule1 -> PeopleUpFDQuerySTATUS_KURS -> Value = 0;
                    } // end if  STATUS_KURS =1

                    // ����� � ��������� ������
                    DataModule1 -> PeopleUpFDQueryN_GROUP -> Value = Edit18 -> Text;
                    DataModule1 -> PeopleUpFDQueryINC_GROUP -> Value = i_gr;
                    // ������������� ��������
                    DataModule1 -> PeopleUpFDQueryN_SPECIALIZ -> Value =
                        DBLookupComboBox11 -> KeyValue;

                    // ������������� ��������� ������������� ��  DBLookupComboBox11

                    // ������������� ��������, ����������, ���� ���������� �������������
                    DataModule1 -> PeopleUpFDQueryN_SPEC -> Value =
                        DM2 -> SpecializFDTable -> Lookup ("N_SPECIALIZ",
                        DBLookupComboBox11 -> KeyValue, "N_SPEC");

                    // ----
                }

                else { // else  �������� �� ���������� ���������� ������
                    ShowMessage ("����������� ������ ����� ������!");
                    return;
                }
                // end else �������� �� ���������� ���������� ������

                // ------��������� ������ �  Public_PrikazQuery
                if (DataModule1 -> Public_PrikazFDQuery -> State == dsInactive)
                    DataModule1 -> Public_PrikazFDQuery -> Open ();
                if (DataModule1 -> Public_PrikazFDQuery -> State != dsInsert)
                    DataModule1 -> Public_PrikazFDQuery -> Insert ();
                // ��������� N_PUBLIC_PRIKAZ  ������ �������
                try { // try �������� �� ����� ������� � �������� �����
                    DataModule1 -> Public_PrikazFDQueryN_PUBLIC_PRIKAZ -> Value =
                        StrToInt (Edit32 -> Text);
                } // end try �������� �� ����� ������� � �������� �����
                catch (...) { // catch ����� �� �����
                    DataModule1 -> Public_PrikazFDQuery -> CancelUpdates ();
                    DataModule1 -> PeopleUpFDQuery -> CancelUpdates ();
                    ShowMessage ("� ������� ������ ���� � �������� �����!");
                    return;
                } // end catch
                // D_PUBLIC_PRIKAZ   ���� �������
                DataModule1 -> Public_PrikazFDQueryD_PUBLIC_PRIKAZ -> Value =
                    DateTimeToSQLTimeStamp (DateTimePicker17 -> Date);
                DataModule1 -> Public_PrikazFDQueryNOMER -> Value = nomer;
                DataModule1 -> Public_PrikazFDQueryDESCRIBE -> Value = describe;
                DataModule1 -> Public_PrikazFDQueryN_TYPE -> Value =
                    DM2 -> Type_PrikazFDTable -> Lookup ("TYPE_PRIKAZ", "�������",
                    "N_TYPE");
                // ----------

                DataModule1 -> Public_PrikazFDQuery -> ApplyUpdates ();
                DataModule1 -> Public_PrikazFDQuery -> CommitUpdates ();
                DataModule1 -> Public_PrikazFDQuery -> Close ();

                DataModule1 -> PeopleUpFDQuery -> ApplyUpdates ();
                DataModule1 -> PeopleUpFDQuery -> CommitUpdates ();
                DataModule1 -> PeopleUpFDQuery -> Close ();

            } // end try
            catch (...) { // catch

                ShowMessage (
                    "��������� ���� ��� ����������, ���������� ��� ���!");
                DataModule1 -> Public_PrikazFDQuery -> CancelUpdates ();

                DataModule1 -> PeopleUpFDQuery -> CancelUpdates ();
            } // end catch

        }
        // ------
        Panel12 -> Visible = false; // ������ ����� ��������
        ComboBox8 -> ItemIndex = -1; // ��� ��������  �� ������   Panel12
        Edit17 -> Text = ""; // � ������ �� ������   Panel12
        // -----
        Panel13 -> Visible = false; // ������ ��������
        DBLookupComboBox11 -> KeyValue = -1; // �������������
        DBLookupComboBox12 -> KeyValue = -1; // ���

        RadioGroup6 -> ItemIndex = -1; // ��������� ��������
        RadioGroup7 -> ItemIndex = -1;
        // ��� ��������  �� ������   Panel13
        Edit18 -> Text = ""; // � ������ �� ������   Panel13
        Edit19 -> Text = ""; // ����
        Edit32 -> Text = ""; // � �������
        DateTimePicker17 -> Date = Now (); // ���� �������
        DateTimePicker17 -> Time = StrToTime ("00:00");
        // ------
        RadioGroup4 -> ItemIndex = -1; // ����� ��������� ��������
        RadioGroup5 -> ItemIndex = -1; // ����� ���� ��������
        RadioGroup5 -> Visible = false;
        RadioGroup18 -> Visible = false;
        // ------
    }
    else
        // �������� �������, �������� �� ������ ���������
        try { // try
        AnsiString describe = "";
        // ------���������� ��������� �  PeopleUpQuery
        if (Edit18 -> Text == "" || Edit19 -> Text == "")
        { // if  �������� �� � ������ � ����
            ShowMessage ("������� ����� ������ � ����� �����!");
            return;
        } // end if  �������� �� � ������ � ����

        if (Edit32 -> Text == "") { // if  �������� �� � � ���� �������
            ShowMessage ("������� ����� ��� ���� �������!");
            return;
        } // end if  �������� �� � � ���� �������

        if (DBLookupComboBox11 -> Text == "")
        { // if  �������� �� ����� �������������
            ShowMessage ("�������� ������������� ��������!");
            return;
        } // end if  �������� �� ����� �������������

        if (DBLookupComboBox12 -> Text == "") { // if  �������� �� ����� ���
            ShowMessage ("�������� ������� ��������!");
            return;
        } // end if  �������� �� ����� ���

        if (RadioGroup6 -> ItemIndex == -1 || RadioGroup7 -> ItemIndex == -1)
        { // if  �������� �� ��� �������� � ��������� ����� (������ ��� �������)
            ShowMessage ("������� ��� �������� ��� ��������� ��������!");
            return;
        }
        // end if �������� �� ��� �������� � ��������� ����� (������ ��� �������)

        if (!check_fac_group (Edit18 -> Text))
            return; // �������� �� ����� ������ � ���������
        if (!check_group_kurs (Edit18 -> Text, Edit19 -> Text))
            return; // �������� �� ����� ������ � ����

        i_gr = search_increment_group (Edit18 -> Text, RadioGroup7 -> ItemIndex);

        int c_k = 0;
        // ���������� ��� ����������� ����� �������� ���� ������� �������������

        if (!RadioGroup4 -> ItemIndex)
            c_k = 4; // �������� ������� �� ������ ���������
        if (RadioGroup4 -> ItemIndex && !RadioGroup5 -> ItemIndex)
            c_k = 3; // �������� ������� �� ������ ��� ��������
        if (RadioGroup4 -> ItemIndex && RadioGroup5 -> ItemIndex)
            c_k = 0; // �������� ������� �� ������ �������������

        if (c_k) {
            if (!DataModule1 -> Search_CK (DBLookupComboBox12 -> KeyValue, c_k,
                Edit32 -> Text, DateTimePicker17 -> Date.DateString ()))
            { // if �� ��������� �������� 0 - ��� �������� �������� ��������
                ShowMessage (
                    "������� ������������� ��-�� ������� � ������� ����������!");
                return;
            }
        }

        if (!i_gr.IsNull ()) { // if �������� �� ���������� ���������� ������
            if (RadioGroup4 -> ItemIndex == 0 && RadioGroup5 -> ItemIndex == 1)
            { // if ������� �� ������ ���������

                if (DataModule1 -> PeopleUpFDQueryVID_EDU -> Value)
                { // if ������� ��������
                    describe = "� �������� "; // �������
                } // end if ������� ��������
                else { // else ������� ��������
                    describe = "� �������� ";
                } // end else ������� ��������

                describe += DM2 -> FacultyFDTable -> Lookup ("N_FAC",
                    DataModule1 -> PeopleUpFDQueryN_FAC -> Value, "FAC1");
                describe += " �� ";
                // ������������ ������ �� ���� �������� � ����������
                describe += RadioGroup7 -> Items -> Strings[RadioGroup7 -> ItemIndex]
                    + " " + DM2 -> FacultyFDTable -> Lookup ("N_FAC", nom_fac,
                    "FAC1");
                // ��������� �������� - ������, �������
                describe += " � " + DM2 -> FoundationFDTable -> Lookup ("N_FOUND",
                    DataModule1 -> PeopleUpFDQueryN_FOUND -> Value, "VID_FOUND") +
                    " �� " + RadioGroup6 -> Items -> Strings
                    [RadioGroup7 -> ItemIndex];

            } // end if ������� �� ������ ���������
            else { // else ��� ��������� �������
                if (DataModule1 -> PeopleUpFDQueryVID_EDU -> Value)
                    describe = "� �������� �� "; // �������
                else
                    describe = "� �������� �� "; // �������
                // ������������ ������ �� ���� �������� + ��������� �������� - ������, �������
                describe += RadioGroup7 -> Items -> Strings[RadioGroup7 -> ItemIndex]
                    + " � " + DM2 -> FoundationFDTable -> Lookup ("N_FOUND",
                    DataModule1 -> PeopleUpFDQueryN_FOUND -> Value, "VID_FOUND") +
                    " �� " + RadioGroup6 -> Items -> Strings
                    [RadioGroup6 -> ItemIndex];

            } // end else ��� ��������� �������

            if (RadioGroup4 -> ItemIndex == 1 && RadioGroup5 -> ItemIndex == 1)
            { // if ������� �� ������ ������������� � �������� ����������
                describe += " � ";
                describe += DM2 -> SpecializFDTable -> Lookup ("N_SPECIALIZ",
                    DataModule1 -> PeopleUpFDQueryN_SPECIALIZ -> Value, "SPECIAL");
                describe += " �� ";
                describe += DBLookupComboBox11 -> Text;
            } // end if ������� �� ������ ������������� � �������� ����������
            // ----��������� ���������� �� ��������
            DataModule1 -> PeopleUpFDQuery -> Edit ();
            // �������� �� ������� ������������ ������ ��������
            if (DataModule1 -> PeopleUpFDQuerySTATUS_KURS -> Value == 1)
            { // if  STATUS_KURS =1
                DataModule1 -> PeopleUpFDQuerySTATUS_KURS -> Value = 0;
            } // end if  STATUS_KURS =1

            // ���������
            DataModule1 -> PeopleUpFDQueryN_FAC -> Value = nom_fac;
            // ��� ��������
            DataModule1 -> PeopleUpFDQueryVID_EDU -> Value = RadioGroup7 -> ItemIndex;
            // ����� � ��������� ������
            DataModule1 -> PeopleUpFDQueryN_GROUP -> Value = Edit18 -> Text;
            DataModule1 -> PeopleUpFDQueryINC_GROUP -> Value = i_gr;
            // ����
            DataModule1 -> PeopleUpFDQueryKURS -> Value = StrToInt (Edit19 -> Text);
            // ��������� �������� -- ������ ��� �������
            DataModule1 -> PeopleUpFDQueryN_FOUND -> Value =
                DM2 -> FoundationFDTable -> Lookup ("VID_FOUND",
                RadioGroup6 -> Items -> Strings[RadioGroup6 -> ItemIndex], "N_FOUND");
            // ������ ������������ ��������
            DataModule1 -> PeopleUpFDQuerySTATUS_PEOPLE -> Value = 1;
            // ������������� ��������
            DataModule1 -> PeopleUpFDQueryN_SPECIALIZ -> Value =
                DBLookupComboBox11 -> KeyValue;

            // ������������� ��������� ������������� ��  DBLookupComboBox11

            // ������������� ��������, ����������, ���� ���������� �������������
            DataModule1 -> PeopleUpFDQueryN_SPEC -> Value =
                DM2 -> SpecializFDTable -> Lookup ("N_SPECIALIZ",
                DBLookupComboBox11 -> KeyValue, "N_SPEC");

            // ----
        } // end if �������� �� ���������� ���������� ������
        else { // else  �������� �� ���������� ���������� ������
            ShowMessage ("����������� ������ ����� ������!");
            return;
        } // end else �������� �� ���������� ���������� ������
        // ------��������� ������ �  Public_PrikazQuery
        if (DataModule1 -> Public_PrikazFDQuery -> State == dsInactive)
            DataModule1 -> Public_PrikazFDQuery -> Open ();
        if (DataModule1 -> Public_PrikazFDQuery -> State != dsInsert)
            DataModule1 -> Public_PrikazFDQuery -> Insert ();
        // ��������� N_PUBLIC_PRIKAZ  ������ �������
        try { // try �������� �� ����� ������� � �������� �����
            DataModule1 -> Public_PrikazFDQueryN_PUBLIC_PRIKAZ -> Value =
                StrToInt (Edit32 -> Text);
        } // end try �������� �� ����� ������� � �������� �����
        catch (...) { // catch ����� �� �����
            DataModule1 -> Public_PrikazFDQuery -> CancelUpdates ();
            DataModule1 -> PeopleUpFDQuery -> CancelUpdates ();
            ShowMessage ("� ������� ������ ���� � �������� �����!");
            return;
        } // end catch
        // D_PUBLIC_PRIKAZ   ���� �������
        DataModule1 -> Public_PrikazFDQueryD_PUBLIC_PRIKAZ -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker17 -> Date);
        DataModule1 -> Public_PrikazFDQueryNOMER -> Value =
            DBLookupComboBox12 -> KeyValue;
        DataModule1 -> Public_PrikazFDQueryDESCRIBE -> Value = describe;
        DataModule1 -> Public_PrikazFDQueryN_TYPE -> Value =
            DM2 -> Type_PrikazFDTable -> Lookup ("TYPE_PRIKAZ", "�������", "N_TYPE");
        // ----------

        DataModule1 -> Public_PrikazFDQuery -> ApplyUpdates ();
        DataModule1 -> Public_PrikazFDQuery -> CommitUpdates ();
        DataModule1 -> Public_PrikazFDQuery -> Close ();

        DataModule1 -> PeopleUpFDQuery -> ApplyUpdates ();
        DataModule1 -> PeopleUpFDQuery -> CommitUpdates ();
        DataModule1 -> PeopleUpFDQuery -> Close ();

        // ------
        Panel12 -> Visible = false; // ������ ����� ��������
        ComboBox8 -> ItemIndex = -1; // ��� ��������  �� ������   Panel12
        Edit17 -> Text = ""; // � ������ �� ������   Panel12
        // -----
        Panel13 -> Visible = false; // ������ ��������
        DBLookupComboBox11 -> KeyValue = -1; // �������������
        DBLookupComboBox12 -> KeyValue = -1; // ���

        RadioGroup6 -> ItemIndex = -1; // ��������� ��������
        RadioGroup7 -> ItemIndex = -1;
        // ��� ��������  �� ������   Panel13
        Edit18 -> Text = ""; // � ������ �� ������   Panel13
        Edit19 -> Text = ""; // ����
        Edit32 -> Text = ""; // � �������
        DateTimePicker17 -> Date = Now (); // ���� �������
        DateTimePicker17 -> Time = StrToTime ("00:00");
        // ------
        RadioGroup4 -> ItemIndex = -1; // ����� ��������� ��������
        RadioGroup5 -> ItemIndex = -1; // ����� ���� ��������
        RadioGroup5 -> Visible = false;
        // ------
        } // end try
    catch (...) { // catch

        ShowMessage ("��������� ���� ��� ����������, ���������� ��� ���!");
        DataModule1 -> Public_PrikazFDQuery -> CancelUpdates ();

        DataModule1 -> PeopleUpFDQuery -> CancelUpdates ();
    } // end catch
}

void __fastcall TDeloForm::BitBtn19Click (TObject * Sender)
{ // �������� �������, �������� �� ������ ��������
    DataModule1 -> Public_PrikazFDQuery -> CancelUpdates ();
    DataModule1 -> Public_PrikazFDQuery -> Close ();
    DataModule1 -> PeopleUpFDQuery -> CancelUpdates ();
    DataModule1 -> PeopleUpFDQuery -> Close ();
    // ------
    Panel12 -> Visible = false; // ������ ����� ��������
    ComboBox8 -> ItemIndex = -1; // ��� ��������  �� ������   Panel12
    Edit17 -> Text = ""; // � ������ �� ������   Panel12
    // -----
    Panel13 -> Visible = false; // ������ ��������

    DBLookupComboBox11 -> KeyValue = -1; // �������������
    DBLookupComboBox12 -> KeyValue = -1; // ���

    RadioGroup6 -> ItemIndex = -1; // ��������� ��������
    RadioGroup7 -> ItemIndex = -1; // ��� ��������  �� ������   Panel13
    Edit18 -> Text = ""; // � ������ �� ������   Panel13
    Edit19 -> Text = ""; // ����
    Edit32 -> Text = ""; // � �������
    DateTimePicker17 -> Date = Now (); // ���� �������
    DateTimePicker17 -> Time = StrToTime ("00:00");

    // ------
    RadioGroup4 -> ItemIndex = -1; // ����� ��������� ��������
    RadioGroup5 -> ItemIndex = -1; // ����� ���� ��������
    RadioGroup5 -> Visible = false;
    RadioGroup18 -> Visible = false;
}

void __fastcall TDeloForm::ComboBox8Change (TObject * Sender)
{ // ��������� �� ���� �������� ��� ������ ������

    Panel13 -> Visible = false; // ������ ��������
    RadioGroup6 -> ItemIndex = -1; // ��������� ��������
    RadioGroup7 -> ItemIndex = -1; // ��� ��������  �� ������   Panel13
    Edit18 -> Text = ""; // � ������ �� ������   Panel13
    Edit19 -> Text = ""; // ����
    if (DataModule1 -> PeopleUpFDQuery -> State == dsEdit)
        DataModule1 -> PeopleUpFDQuery -> CancelUpdates ();
    if (DataModule1 -> Public_PrikazFDQuery -> State == dsInsert)
        DataModule1 -> Public_PrikazFDQuery -> CancelUpdates ();
}

void __fastcall TDeloForm::ComboBox9Change (TObject * Sender)
{ // ��������� �� ���� �������� ��� ������ ������
    // -----
    Panel14 -> Visible = false;
    Edit21 -> Text = ""; // � ������
    Edit22 -> Text = ""; // ����
    // -------
    if (DataModule1 -> Public_PrikazFDQuery -> State == dsInsert)
        DataModule1 -> Public_PrikazFDQuery -> CancelUpdates ();
}

void __fastcall TDeloForm::BitBtn23Click (TObject * Sender)
{ // �������� ��������� ��� ��������, �������� �� ������ ��������
    DataModule1 -> Public_PrikazFDQuery -> CancelUpdates ();
    DataModule1 -> PeopleUpFDQuery -> CancelUpdates ();
    DataModule1 -> Public_PrikazFDQuery -> Close ();
    DataModule1 -> PeopleUpFDQuery -> Close ();

    // -----
    Panel14 -> Visible = false;
    DBLookupComboBox14 -> KeyValue = -1; // ���
    Edit21 -> Text = ""; // � ������
    Edit22 -> Text = ""; // ����
    Edit30 -> Text = ""; // � �������
    DateTimePicker15 -> Date = Now (); // ���� �������
    DateTimePicker15 -> Time = StrToTime ("00:00");
    // -------
    Panel15 -> Visible = false;
    Edit20 -> Text = ""; // � ������
    ComboBox9 -> ItemIndex = -1; // ��� ��������
    // -------------
    RadioGroup8 -> ItemIndex = -1;
}

void __fastcall TDeloForm::BitBtn21Click (TObject * Sender)
{ // �������� ��������� ��� ��������, �������� �� ������ -- ������� ��������

    i_gr = search_increment_group (Edit20 -> Text, ComboBox9 -> ItemIndex);
    if (!i_gr.IsNull ()) {
        // sql_old="SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND FROM PEOPLE People";

        DataModule1 -> PeopleUpFDQuery -> Close ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Clear ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Add
            ("SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, D_INCLUDE, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND, FAM ||' '|| NAME ||' ' || OTCH as FIO, DATE_END FROM PEOPLE People WHERE (N_FAC=" +
            AnsiString (nom_fac) +
            ") AND (STATUS_PEOPLE=1) AND (INC_GROUP=:I_GR) ORDER BY FAM, NAME, OTCH");
        DataModule1 -> PeopleUpFDQuery -> ParamByName ("I_GR") -> AsInteger = i_gr;
        DataModule1 -> PeopleUpFDQuery -> Open ();

        if (!DataModule1 -> PeopleUpFDQuery -> RecordCount) {
            ShowMessage ("�� ������ ����� ������!");
            Edit20 -> SetFocus ();
        }
    }
    else {
        ShowMessage ("�� ������ ����� ������!");
        Edit20 -> SetFocus ();
    }
}

void __fastcall TDeloForm::BitBtn22Click (TObject * Sender)
{ // �������� ��������� ��� ��������, �������� �� ������ -- ���������
    try { // try
        if (Edit21 -> Text == "" || Edit22 -> Text == "")
        { // if �������� �� ���� ������ �� ������ ������ ��� �����
            ShowMessage ("������� ����� ������ ��� ����� �����");
            return;
        } // end if

        if (!check_fac_group (Edit21 -> Text))
            return; // �������� �� ����� ������ � ���������
        if (!check_group_kurs (Edit21 -> Text, Edit22 -> Text))
            return; // �������� �� ����� ������ � ����
        i_gr = search_increment_group (Edit21 -> Text,
            DataModule1 -> PeopleUpFDQueryVID_EDU -> Value);
        if (i_gr.IsNull ()) { // if �������� �� ��������� ����� ������
            ShowMessage ("����������� ������ ����� ������!");
            return;
        } // end if �������� �� ��������� ����� ������
        if (DBLookupComboBox14 -> KeyValue == -1) {
            ShowMessage ("�������� ��� ��������!");
            return;
        }
        if (Edit30 -> Text == "") {
            ShowMessage ("������� � ������� �� ��������� ��� ��������!");
            return;
        }
        // ------ ������� ������ � Public_PrikazQuery
        if (DataModule1 -> Public_PrikazFDQuery -> State == dsInactive)
            DataModule1 -> Public_PrikazFDQuery -> Open ();
        if (DataModule1 -> Public_PrikazFDQuery -> State != dsInsert)
            DataModule1 -> Public_PrikazFDQuery -> Insert ();

        DataModule1 -> Public_PrikazFDQueryNOMER -> Value =
            DBLookupComboBox14 -> KeyValue; // ����� ��������
        // ��������� N_PUBLIC_PRIKAZ � D_PUBLIC_PRIKAZ

        try { // �������� �� ���� � � ������� ��������� ��������
            DataModule1 -> Public_PrikazFDQueryN_PUBLIC_PRIKAZ -> Value =
                StrToInt (Edit30 -> Text);
            // � ������� �� ����. ��� ��������
        }
        catch (...) {
            DataModule1 -> Public_PrikazFDQuery -> CancelUpdates ();
            ShowMessage ("������� ������ � �������!");
            return;
        }

        DataModule1 -> Public_PrikazFDQueryD_PUBLIC_PRIKAZ -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker15 -> Date);
        // ���� ������� �� ��������������
        if ( (DataModule1 -> PeopleUpFDQueryN_FOUND -> Value != 2) &&
            (RadioGroup11 -> ItemIndex == 1))
        { // if  ������� ��� �� ������� �� �� ��������� ��� �������� �� �������
            DataModule1 -> Public_PrikazFDQueryDESCRIBE -> Value =
                "�������� �� " + Edit22 -> Text + " ����� �� ���������� ��������";
        } // end if
        else { // else  ������ ��������
            AnsiString text_dogovor = "";
            if (RadioGroup11 -> ItemIndex)
                text_dogovor = "  �� ���������� ��������";
            else
                text_dogovor = " �� ���� ��������� �������";

            DataModule1 -> Public_PrikazFDQueryDESCRIBE -> Value =
                "�������� �� " + Edit22 -> Text + " �����" + text_dogovor;
        } // end else
        DataModule1 -> Public_PrikazFDQueryN_TYPE -> Value =
            DM2 -> Type_PrikazFDTable -> Lookup ("TYPE_PRIKAZ",
            "��������� ��� ��������", "N_TYPE");
        DataModule1 -> Public_PrikazFDQuery -> ApplyUpdates ();
        // ---- ���������� ��������� �  PeopleUpQuery
        // if (DataModule1 -> PeopleUpQuery -> State==dsInactive) DataModule1 -> PeopleUpQuery -> Open ();
        DataModule1 -> PeopleUpFDQuery -> Edit ();
        // ����� �����
        DataModule1 -> PeopleUpFDQueryKURS -> Value = StrToInt (Edit22 -> Text);
        // ��������� ������
        DataModule1 -> PeopleUpFDQueryINC_GROUP -> Value = i_gr;
        // ����� ������
        DataModule1 -> PeopleUpFDQueryN_GROUP -> Value = Edit21 -> Text;
        // ������ �������� ��������
        DataModule1 -> PeopleUpFDQuerySTATUS_PEOPLE -> Value = 1;
        // ������� ������������ ������� ������ ����� �������
        DataModule1 -> PeopleUpFDQuerySTATUS_KURS -> Value = 0;
        // �������� ��������� �������� ������ � ������ ���� ����� �������
        if ( (DataModule1 -> PeopleUpFDQueryN_FOUND -> Value != 2) &&
            (RadioGroup11 -> ItemIndex == 1)) {
            DataModule1 -> PeopleUpFDQueryN_FOUND -> Value = 2;
        }
        DataModule1 -> PeopleUpFDQuery -> ApplyUpdates ();

        // -----------------
        // �� ��������� ���� ��� ��������� ���� �������� ������� ��� ������ � ����� ��������

        DataModule1 -> Result_Ball_ThreeFDQuery -> Close ();
        DataModule1 -> Result_Ball_ThreeFDQuery -> ParamByName ("S1") -> AsSmallInt =
            StrToInt (Edit22 -> Text) * 2;
        DataModule1 -> Result_Ball_ThreeFDQuery -> ParamByName ("S2") -> AsSmallInt =
            StrToInt (Edit22 -> Text) * 2 - 1;
        DataModule1 -> Result_Ball_ThreeFDQuery -> ParamByName ("FAC") -> AsSmallInt =
            nom_fac;
        DataModule1 -> Result_Ball_ThreeFDQuery -> ParamByName ("EDU") -> AsSmallInt =
            DataModule1 -> PeopleUpFDQueryVID_EDU -> Value;
        DataModule1 -> Result_Ball_ThreeFDQuery -> ParamByName ("NOMER") -> AsInteger =
            DataModule1 -> PeopleUpFDQueryNOMER -> Value;
        DataModule1 -> Result_Ball_ThreeFDQuery -> Open ();
        int col_three = DataModule1 -> Result_Ball_ThreeFDQuery -> RecordCount;
        // ���������� ������� � ��������� Query
        for (int i = 0; i < col_three; i++)
        { // for ���� ������� ������ �� ��������� �� ��������� ���� ��������
            AnsiString box_delete = "";
            switch (DataModule1 -> Result_Ball_ThreeFDQueryRESULT -> Value)
            { // switch ����� ���� ������

            case 3:
                box_delete =
                    "� ����� �������� ���� ������ 3 (�����.) �� �������� " +
                    DataModule1 -> Result_Ball_ThreeFDQueryNAME_OBJECT -> Value +
                    " � " + DataModule1 -> Result_Ball_ThreeFDQuerySEMESTR -> Value
                    + " ��������. ������� ��� ������?";
                break;
            case 14:
                box_delete =
                    "� ����� �������� ���� ������ 4 (������) �� �������� " +
                    DataModule1 -> Result_Ball_ThreeFDQueryNAME_OBJECT -> Value +
                    " � " + DataModule1 -> Result_Ball_ThreeFDQuerySEMESTR -> Value
                    + " ��������. ������� ��� ������?";
                break;
            case 15:
                box_delete =
                    "� ����� �������� ���� ������ 5 (����) �� �������� " +
                    DataModule1 -> Result_Ball_ThreeFDQueryNAME_OBJECT -> Value +
                    " � " + DataModule1 -> Result_Ball_ThreeFDQuerySEMESTR -> Value
                    + " ��������. ������� ��� ������?";
                break;
            } // end switch ����� ���� ������

            // !!!if (Application -> MessageBox (box_delete.c_str (),"��������", MB_OKCANCEL) == IDOK)
            if (MessageDlg (box_delete.c_str (), mtWarning,
                TMsgDlgButtons () << mbOK << mbCancel, 0) == 1)
            { // if   �������� ������ �� �������  Result_Ball
                DataModule1 -> Result_Ball_ThreeFDQuery -> Delete ();
                DataModule1 -> Result_Ball_ThreeFDQuery -> ApplyUpdates ();
            } // end if   �������� ������ �� �������  Result_Ball
            DataModule1 -> Result_Ball_ThreeFDQuery -> Next ();
        } // end for ���� ������� ������ �� ��������� �� ��������� ���� ��������
        // ------------------
        DataModule1 -> Result_Ball_ThreeFDQuery -> CommitUpdates ();
        DataModule1 -> Public_PrikazFDQuery -> CommitUpdates ();
        DataModule1 -> PeopleUpFDQuery -> CommitUpdates ();
        DataModule1 -> PeopleUpFDQuery -> Close ();
        DataModule1 -> Public_PrikazFDQuery -> Close ();

        // --------------
        Panel14 -> Visible = false;
        Edit21 -> Text = ""; // � ������
        Edit22 -> Text = ""; // ����
        Edit30 -> Text = ""; // � �������
        DateTimePicker15 -> Date = Now (); // ���� �������
        DateTimePicker15 -> Time = StrToTime ("00:00");
        DBLookupComboBox14 -> KeyValue = -1; // ���
        // --------------
        Panel15 -> Visible = false;
        Edit20 -> Text = ""; // � ������
        ComboBox9 -> ItemIndex = -1; // ��� ��������
        // -----
        RadioGroup8 -> ItemIndex = -1;
    } // end try
    catch (...) { // catch
        ShowMessage ("��������� ���� ��� ����������, ���������� ��� ���!");
        DataModule1 -> Public_PrikazFDQuery -> CancelUpdates ();
        DataModule1 -> PeopleUpFDQuery -> CancelUpdates ();
    } // end catch
}

void __fastcall TDeloForm::RadioGroup8Click (TObject * Sender)
{ // �������� ��������� ��� �������� - ����� ��������� ������ ���� ��� �������
    if (RadioGroup8 -> ItemIndex != -1)
    { // if ������ ��� �������� ������ �� �������
        Panel14 -> Visible = false;
        Panel15 -> Visible = false;
        if (RadioGroup8 -> ItemIndex)
        { // if ������� �������� � ������ � ������� ��� �����������

            DataModule1 -> PeopleUpFDQuery -> Close ();
            DataModule1 -> PeopleUpFDQuery -> SQL -> Clear ();
            DataModule1 -> PeopleUpFDQuery -> SQL -> Add
                ("SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND, FAM ||' '|| NAME ||' ' || OTCH as FIO, D_INCLUDE, DATE_END FROM PEOPLE People WHERE (N_FAC=" +
                AnsiString (nom_fac) + ") AND (STATUS_PEOPLE=4) ORDER BY FAM");
            DataModule1 -> PeopleUpFDQuery -> Open ();

            if (DataModule1 -> PeopleUpFDQuery -> RecordCount) {
                Panel14 -> Visible = true;
                DataModule1 -> Public_PrikazFDQuery -> Open ();
                // DataModule1 -> Public_PrikazQuery -> Insert ();
            }
            else {
                ShowMessage ("��� ��������� ��� �����������!");
                RadioGroup8 -> ItemIndex = -1;
            }
        } // end if
        else { // else ��������� �������� �� ��������� ��� ��������
            Panel15 -> Visible = true;
            // Panel15 -> Top=112;
            Panel15 -> Height = 185;
        } // end else
    } // end if ������ ��� �������� ������ �� �������
}

void __fastcall TDeloForm::BitBtn24Click (TObject * Sender)
{ // �������� ��������� ��� �������� - ��������� ��� ����� �� ��������� ��� ��������
    // ---- ���������� ��������� �  PeopleUpQuery
    try { // try
        if (DBLookupComboBox15 -> Text != "") { // if ���
            if (DataModule1 -> PeopleUpFDQuery -> State == dsInactive)
                DataModule1 -> PeopleUpFDQuery -> Open ();
            if (DataModule1 -> PeopleUpFDQuery -> State != dsEdit)
                DataModule1 -> PeopleUpFDQuery -> Edit ();
            // ������ �������� ��������
            DataModule1 -> PeopleUpFDQuerySTATUS_PEOPLE -> Value = 4;
            // �������� ��������� ������
            DataModule1 -> PeopleUpFDQueryINC_GROUP -> Value = 18;
            DataModule1 -> PeopleUpFDQuery -> ApplyUpdates ();
            DataModule1 -> PeopleUpFDQuery -> CommitUpdates ();
            DataModule1 -> PeopleUpFDQuery -> Close ();
            // --------
            Panel15 -> Visible = false;

            ComboBox9 -> ItemIndex = -1; // ��� ��������
            Edit20 -> Text = ""; // ����� ������
            DBLookupComboBox15 -> KeyValue = -1; // ���
            Panel15 -> Height = 72;

            // ---------
            RadioGroup8 -> ItemIndex = -1;
        } // end if
        else { // else
            ShowMessage ("�������� ������� ��������!");
        } // end else
    } // end try
    catch (...) { // catch
        ShowMessage ("������� ���� ��� ����������, ���������� ��� ���");
        DataModule1 -> PeopleUpFDQuery -> CancelUpdates ();
    } // end catch
}

void __fastcall TDeloForm::BitBtn25Click (TObject * Sender)
{ // �������� ��������� ��� �������� - �������� ��� ����� �� ��������� ��� ��������
    try {
        DataModule1 -> PeopleUpFDQuery -> CancelUpdates ();
        DataModule1 -> PeopleUpFDQuery -> Close ();
        DataModule1 -> Public_PrikazFDQuery -> Close ();
        // --------
        Panel15 -> Visible = false;
        Panel15 -> Height = 72;
        ComboBox9 -> ItemIndex = -1; // ��� ��������
        Edit20 -> Text = ""; // ����� ������
        DBLookupComboBox15 -> KeyValue = -1; // ���
        // --------
        RadioGroup8 -> ItemIndex = -1;
    }
    catch (...) {
        DataModule1 -> PeopleUpFDQuery -> Close ();
        DataModule1 -> Public_PrikazFDQuery -> Close ();
        // --------
        Panel15 -> Visible = false;
        Panel15 -> Height = 72;
        ComboBox9 -> ItemIndex = -1; // ��� ��������
        Edit20 -> Text = ""; // ����� ������
        DBLookupComboBox15 -> KeyValue = -1; // ���
        // -------------
        RadioGroup8 -> ItemIndex = -1;
        ShowMessage ("��� ������ ��� ����������!!!!!");
        return;
    }
}

void __fastcall TDeloForm::BitBtn26Click (TObject * Sender) {
    DM3 -> PeopleDiplomFDQuery -> Close ();
    DM3 -> PeopleDiplomFDQuery -> ParamByName ("N_GROUP") -> Value =
        DBLookupComboBox16 -> KeyValue;
    DM3 -> PeopleDiplomFDQuery -> ParamByName ("VID_EDU") -> Value =
        ComboBox10 -> ItemIndex;
    DM3 -> PeopleDiplomFDQuery -> Open ();

    if (DM3 -> PeopleDiplomFDQuery -> RecordCount != 0) {
        DM3 -> QUALIFICFDQuery -> Close ();
        DM3 -> QUALIFICFDQuery -> Open ();
        DM3 -> QUALIFICFDQuery2 -> Close ();
        DM3 -> QUALIFICFDQuery2 -> Open ();
        Panel16 -> Visible = true;
    }
    else {
        ShowMessage (
            "� ��� ��� �� ������ �������� � ���� ������ ������� ���. ��� ������");
        DM3 -> PeopleDiplomFDQuery -> Close ();

    }

}

void __fastcall TDeloForm::BitBtn27Click (TObject * Sender)
{ // �������� ������ - ������ ������� �����������
    // ��������
    if (DBLookupComboBox17 -> Text == "") {
        ShowMessage ("�������� ��� ��������!");
        return;
    }
    /* if ( (Edit23 -> Text=="")|| (DateEdit9 -> Text=="  .  .    "))
     {
     ShowMessage ("������� ����� � ���� �������!");
     return;
     } */
    if (nom_fac != 4 && (DBLookupComboBox18 -> Text == "" ||
        DBLookupComboBox19 -> Text == "")) {
        ShowMessage ("������� ������������ ��������!");
        return;
    }
    if (DBLookupComboBox18 -> Text == DBLookupComboBox19 -> Text) {
        ShowMessage (
            "�� �� ������ ��������� ��� ���������� ������������ ��������!");
        return;
    }

    if (Edit24 -> Text == "") {
        ShowMessage ("������� ����� � ���� ���������!");
        return;
    }
    if ( (Edit35 -> Text == "") || (Edit25 -> Text == "")) {
        ShowMessage ("������� �����, � ������� � ���� �������� �������!");
        return;
    }
    // ����� ��������
    DM3 -> DiplomFDQuery -> Close ();
    DM3 -> DiplomFDQuery -> ParamByName ("NOMER") -> Value =
        DBLookupComboBox17 -> KeyValue;
    DM3 -> DiplomFDQuery -> Open ();

    if (!DM3 -> DiplomFDQuery -> RecordCount) { // if   !DM3 -> Diplom -> RecordCount
        /* //������ � ������� Public_Prikaz
         DM3 -> Publik_PrikazFDQuery -> Open ();
         DM3 -> Publik_PrikazFDQuery -> Insert ();
         DM3 -> Publik_PrikazN_TYPE -> Value=9;
         DM3 -> Publik_PrikazN_PUBLIC_PRIKAZ -> Value=StrToInt (Edit23 -> Text);
         DM3 -> Publik_PrikazD_PUBLIC_PRIKAZ -> Value=DateEdit9 -> Text;
         DM3 -> Publik_PrikazNOMER -> Value=DBLookupComboBox17 -> KeyValue;
         DM3 -> Publik_PrikazDESCRIBE -> Value=DBLookupComboBox17 -> Text;
         try
         {//try ���������� �������
         DM3 -> Publik_PrikazFDQuery -> ApplyUpdates ();
         DM3 -> Publik_PrikazFDQuery -> CommitUpdates ();
         DM3 -> Publik_PrikazFDQuery -> Close ();
         }//end try ���������� �������
         catch (...)
         {//catch ������
         DM3 -> Publik_PrikazFDQuery -> CancelUpdates ();
         ShowMessage ("���� � ���������. ���������� � ��������������. �� ���������� ������ � �������");
         }//end catch ������ */

        // ������������
        AnsiString Qu = "";
        if (DBLookupComboBox18 -> Text != "")
            Qu = Qu + DBLookupComboBox18 -> KeyValue + ",";
        if (DBLookupComboBox19 -> Text != "")
            Qu = Qu + DBLookupComboBox19 -> KeyValue;
        // �������� �������, ���� ������� ���� ������������
        if (DBLookupComboBox18 -> Text != "" && DBLookupComboBox19 -> Text == "")
            Qu = Qu.SubString (1, Qu.Length () - 1);

        // ������ � ������� Diploma
        DM3 -> DiplomFDQuery -> Insert ();
        DM3 -> DiplomFDQueryNOMER -> Value = DBLookupComboBox17 -> KeyValue;
        // ����� ��������
        DM3 -> DiplomFDQueryQUALIFICATION -> Value = Qu; // ������������
        DM3 -> DiplomFDQueryN_PROTOKOL -> Value = StrToInt (Edit24 -> Text);
        // ����� ���������
        DM3 -> DiplomFDQueryD_PROTOKOL -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker10 -> Date);
        // ���� ���������

        DM3 -> DiplomFDQueryD_VIPUSK -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker11 -> Date);
        // ���� �������� �������
        DM3 -> DiplomFDQueryN_RASPRED_WORK -> Value = 0;
        DM3 -> DiplomFDQueryDIRECTION_WORK -> Value = "";

        // ---�����
        DM3 -> DiplomFDQueryUROVEN -> Value = RadioGroup15 -> ItemIndex;
        // ������� �����������
        /* ���� ��� ����� ������� ���������� RadioGroup16 -> ItemIndex �� 2
         int type_d=0;//��� �������
         switch (RadioGroup16 -> ItemIndex)
         {
         case 0: type_d=0; break; // 0-������ � ������ �����������
         case 1: type_d=2; break; // 2-������ � ������ ����������� � ��������
         case 2: type_d=4; break; // 4-������ � ������ ����������� (��� ����������� �������)
         case 3: type_d=6; break; // 6-������ � ������ ����������� � �������� (��� ����������� �������)
         case 4: type_d=8; break; // 8-������ ���������
         case 5: type_d=10; break; // 10-������ ��������

         0-������ � ������ �����������
         1-������ � ������ ����������� (��������)
         2-������ � ������ ����������� � ��������
         3-������ � ������ ����������� � �������� (��������)
         4-������ � ������ ����������� (��� ����������� �������)
         5-������ � ������ ����������� (��� ����������� �������) (��������)
         6-������ � ������ ����������� � �������� (��� ����������� �������)
         7-������ � ������ ����������� � �������� (��� ����������� �������) (��������)
         8-������ ���������
         9-������ ��������� (��������)
         10-������ ��������
         11-������ �������� (��������)
         12-������ ��������� � ��������

         } */

        DM3 -> DiplomFDQueryTYPE_DIPLOM -> Value = RadioGroup16 -> ItemIndex * 2;
        // ��� �������
        DM3 -> DiplomFDQuerySERIA -> Value = Edit35 -> Text; // ����� �������
        DM3 -> DiplomFDQueryNOM_DIPLOM -> Value = Edit25 -> Text; // � �������
        // ��������� ������ � ����� ������� ��� ������� ����, ����� �� ������������ ������� �����
        if (RadioGroup16 -> ItemIndex == 1 || RadioGroup16 -> ItemIndex == 3 ||
            RadioGroup16 -> ItemIndex == 6) { // if ������ � ��������
            DM3 -> DiplomFDQueryN_DIPLOM -> Value = "� �������� " + Edit35 -> Text +
                " �" + Edit25 -> Text;
        }
        else
            DM3 -> DiplomFDQueryN_DIPLOM -> Value =
                Edit35 -> Text + " �" + Edit25 -> Text;

        try { // try ���������� �������
            DM3 -> DiplomFDQuery -> ApplyUpdates ();
            DM3 -> DiplomFDQuery -> CommitUpdates ();
            DM3 -> DiplomFDQuery -> Close ();
            Edit25 -> Text = "";
            // �������� ������ �������
            DM3 -> PeopleDiplomFDQuery -> Close ();
            DM3 -> PeopleDiplomFDQuery -> Open ();
        } // end try ���������� �������
        catch (...) { // catch ���� ��� ���������� �������
            DM3 -> DiplomFDQuery -> CancelUpdates ();
            // Otkat (); ���� ������� ���������� ������� � ������� - �� � ������� ��� �� ����!!!!!!!!!!!
            ShowMessage (
                "���� � ���������!\n���������� � ��������������.\n�� ��������� ���������� �� �������!");
        } // end catch ���� ��� ���������� �������
    } // end if   !DM3 -> Diplom -> RecordCount
    else { // else ���� ������ � �������
        ShowMessage (
            "� ����� �������� ��� ���� ���������� � �������!\n���������� � ��������������");
    }

}

void __fastcall TDeloForm::Otkat () { // ����� ���������� ������ � ��������
    // �������� �������
    DataModule1 -> Publik_PrikazFDQuery -> Close ();
    DataModule1 -> Publik_PrikazFDQuery -> Open ();
    TLocateOptions fl;
    Variant loc[2];
    loc[0] = Variant (DBLookupComboBox17 -> KeyValue);
    loc[1] = Variant ("9");
    if (DataModule1 -> Publik_PrikazFDQuery -> Locate ("NOMER;N_TYPE",
        VarArrayOf (loc, 1), fl)) { // if ����� ��� ������
        DataModule1 -> Publik_PrikazFDQuery -> Delete ();
        try { // try ������������� ��������
            DataModule1 -> Publik_PrikazFDQuery -> ApplyUpdates ();
            DataModule1 -> Publik_PrikazFDQuery -> CommitUpdates ();
            DataModule1 -> Publik_PrikazFDQuery -> Close ();
        } // end try ������������� ��������
        catch (...) { // catch �������� � ���������
            DataModule1 -> Publik_PrikazFDQuery -> CancelUpdates ();
            ShowMessage ("�� ���� �������  ������ � �������");
        }
    } // end if ����� ��� ������
}

void __fastcall TDeloForm::ComboBox10Change (TObject * Sender) {
    Panel16 -> Visible = false;
    DM3 -> Group_VipuskFDQuery -> Close ();
    DM3 -> Group_VipuskFDQuery -> SQL -> Clear ();
    DM3 -> Group_VipuskFDQuery -> Params -> Clear ();
    DM3 -> Group_VipuskFDQuery -> SQL -> Add (SQL_rem);
    DM3 -> Group_VipuskFDQuery -> ParamByName ("VID_EDU") -> Value =
        ComboBox10 -> ItemIndex;
    AnsiString Param_s = "", Param_b = "";
    /* if (ComboBox10 -> ItemIndex==0)
     {
     Param=IntToStr (nom_fac)+"5_";
     }
     if (ComboBox10 -> ItemIndex==1)
     {
     Param=IntToStr (nom_fac)+"6_";
     } */

    if (nom_fac != 3) {
        Param_s = IntToStr (nom_fac);
        Param_b = IntToStr (nom_fac);
    }
    else {
        Param_s = "0";
        Param_b = "0";
    }

    if (ComboBox10 -> ItemIndex) {
        Param_s += "6_";
        Param_b += "5_";
    }
    else {
        Param_s += "5_";
        Param_b += "4_";
    }

    DM3 -> Group_VipuskFDQuery -> ParamByName ("N_GROUP_S") -> Value = Param_s;
    DM3 -> Group_VipuskFDQuery -> ParamByName ("N_GROUP_B") -> Value = Param_b;
    DM3 -> Group_VipuskFDQuery -> Open ();
}

void __fastcall TDeloForm::DBLookupComboBox16Click (TObject * Sender) {
    Panel16 -> Visible = false;
}

void __fastcall TDeloForm::BitBtn28Click (TObject * Sender) {
    if (ComboBox11 -> Text == "" || Edit26 -> Text == "")
        ShowMessage ("������� ��� ������");
    else { //
        Variant sea[2];
        sea[0] = Variant (Edit26 -> Text);
        sea[1] = Variant (ComboBox11 -> ItemIndex);
        i_gr = DM2 -> Increment_GroupFDTable -> Lookup ("N_GROUP;VID_EDU",
            VarArrayOf (sea, 1), "INC_GROUP");
        if (!i_gr.IsNull ()) { // if IsNull
            DM3 -> Prikaz_DopuskPeopleFDQuery -> Close ();
            DM3 -> Prikaz_DopuskPeopleFDQuery -> SQL -> Clear ();
            DM3 -> Prikaz_DopuskPeopleFDQuery -> SQL -> Add ("SELECT NOMER, FAM, NAME, OTCH, POL, NAZ, PAPA, MAMA, MARIAGE, N_CHILD, EDUCATION, ARMY, SCHOLARSHIP, HOSTEL, NAME_EDUC, WHEN_EDUC, WHERE_EDUC, PHOTO, MIDDLE_B, N_VID_SPORT, N_DELA, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, EDU_WORK, D_PRIKAZ_KURS, N_FOUND, N_PRIKAZ_INCLUDE, D_PRIKAZ_INCLUDE, N_GROUP, STATUS_PEOPLE, INC_GROUP, WORK_BEFORE, ADDRESS_BEFORE, ADDRESS, ADDRESS_LIFE, DATA_R, F_OLD, PHONE, STATUS_KURS, N_ZACHET \
             FROM PEOPLE  where (STATUS_PEOPLE=1) and (INC_GROUP=" +
                VarToStr (i_gr) + ") AND (VID_EDU=" + ComboBox11 -> ItemIndex +
                ") ORDER BY FAM, NAME, OTCH");

            // DM3 -> Prikaz_DopuskPeople -> ParamByName ("INC_GROUP") -> Value=i_gr;
            // DM3 -> Prikaz_DopuskPeopleFDQuery -> ParamByName ("VID_EDU") -> Value=ComboBox6 -> ItemIndex;
            DM3 -> Prikaz_DopuskPeopleFDQuery -> Open ();
            if (DM3 -> Prikaz_DopuskPeopleFDQuery -> RecordCount != 0) {
                // ������������ �������� �������
                AnsiString *mas_stud[2];
                // ������ ������� � ������� ���������
                for (int i = 0; i < 2; i++)
                    mas_stud[i] =
                        new AnsiString
                        [DM3 -> Prikaz_DopuskPeopleFDQuery -> RecordCount];
                //////////////////////////////////////////////////////////////////////////
                DM3 -> Prikaz_DopuskPeopleFDQuery -> First ();
                DualListDlg = new TDualListDlg (this);
                DualListDlg -> SrcList -> Items -> Clear ();
                DualListDlg -> DstList -> Items -> Clear ();
                // ������������ �������� �������
                for (int j = 0;
                j <= DM3 -> Prikaz_DopuskPeopleFDQuery -> RecordCount - 1; j++) {
                    mas_stud[0][j] = DM3 -> Prikaz_DopuskPeopleFDQueryFAM -> Value +
                        " " + DM3 -> Prikaz_DopuskPeopleFDQueryNAME -> Value + " " +
                        DM3 -> Prikaz_DopuskPeopleFDQueryOTCH -> Value;
                    DualListDlg -> SrcList -> Items -> AddObject (mas_stud[0][j],
                        (TObject*)
                        (DM3 -> Prikaz_DopuskPeopleFDQueryNOMER -> Value));
                    mas_stud[1][j] =
                        AnsiString (DM3 -> Prikaz_DopuskPeopleFDQueryNOMER -> Value);
                    DM3 -> Prikaz_DopuskPeopleFDQuery -> Next ();

                } // for  ������������ �������� �������
                // ��� ���������

                DualListDlg -> ShowModal ();

                if (DataModule2 -> printdlg == true) {
                    if (DualListDlg -> DstList -> Items -> Count != 0) {
                        // ������������ Query ��� ������ ���������
                        AnsiString Str_Nomer = "";
                        for (int i = 0;
                        i <= DualListDlg -> DstList -> Items -> Count - 1; i++) {
                            Str_Nomer += mas_stud[1][i] + ",";
                            // ���������� ����� ��������
                        } // 1-�� for

                        Str_Nomer.SetLength (Str_Nomer.Length () - 1);
                        // ������������ Query ��� ������
                        DM3 -> Prikaz_DopuskPeopleFDQuery -> Close ();
                        DM3 -> Prikaz_DopuskPeopleFDQuery -> SQL -> Clear ();
                        DM3 -> Prikaz_DopuskPeopleFDQuery -> SQL -> Add ("SELECT NOMER, FAM, NAME, OTCH, POL, NAZ, PAPA, MAMA, MARIAGE, N_CHILD, EDUCATION, ARMY, SCHOLARSHIP, HOSTEL, NAME_EDUC, WHEN_EDUC, WHERE_EDUC, PHOTO, MIDDLE_B, N_VID_SPORT, N_DELA, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, EDU_WORK, D_PRIKAZ_KURS, N_FOUND, N_PRIKAZ_INCLUDE, D_PRIKAZ_INCLUDE, N_GROUP, STATUS_PEOPLE, INC_GROUP, WORK_BEFORE, ADDRESS_BEFORE, ADDRESS, ADDRESS_LIFE, DATA_R, F_OLD, PHONE, STATUS_KURS, N_ZACHET \
                         FROM PEOPLE  where (STATUS_PEOPLE=1) and (INC_GROUP=" +
                            VarToStr (i_gr) + ") AND (NOMER IN (" + Str_Nomer +
                            ")) ORDER BY FAM, NAME, OTCH");

                        Label97 -> Enabled = true;
                        Edit27 -> Enabled = true;
                        Label98 -> Enabled = true;
                        DateTimePicker12 -> Enabled = true;
                        ListBox3 -> Clear ();
                        ListBox3 -> Visible = true;
                        Button1 -> Visible = true;

                        for (int i = 0;
                        i <= DualListDlg -> DstList -> Items -> Count - 1; i++) {

                            ListBox3 -> Items -> AddObject
                                (DualListDlg -> DstList -> Items -> Strings[i],
                                DualListDlg -> DstList -> Items -> Objects[i]);

                        }

                        //

                    } // if MyList1 -> FOutList -> Count!=0
                    else {
                        ShowMessage ("�� �� ������� �� ������ ��������!");
                    }
                } // if MyList1 -> Execute (MyList1)
                delete DualListDlg;
            } // if  DM3 -> Prikaz_DopuskPeopleFDQuery -> RecordCount!=0

        } // if i_gr.IsNull ()
        else {
            MessageBox (0, "�� ������ ��������� ����� ������", "", MB_OK);

        } // else i_gr.IsNull ()

    } // else
}

// ������ �� ������ � �����

void __fastcall TDeloForm::Button111Click (TObject * Sender) {
    DataModule1 -> Publik_PrikazFDQuery -> Close ();
    DataModule1 -> Publik_PrikazFDQuery -> Open ();
    DM3 -> Prikaz_DopuskPeopleFDQuery -> First ();
    for (int i = 0; i <= ListBox113 -> Items -> Count - 1; i++) { // for
        bool save_pr = true; // ���������� ���� �� ��������� ������

        Variant dopusk = DataModule1 -> Publik_PrikazFDQuery -> Lookup
            ("NOMER;N_TYPE", VarArrayOf (OPENARRAY (Variant,
            ( (int) (ListBox113 -> Items -> Objects[i]), 12))),
            "N_PUBLIC_PRIKAZ;D_PUBLIC_PRIKAZ");
        if (!dopusk.IsNull ()) { // if ���� ������
            AnsiString s = "������� " + ListBox113 -> Items -> Strings[i] +
                "\n��� ����� ������ � ��� ��������� �" +
                VarToStr (dopusk.GetElement (0)) + " �� " +
                VarToStr (dopusk.GetElement (1)) +
                ".\nC�������� ��� ����� ������?";
            // !!!if (Application -> MessageBox (s.c_str (),"��������������", MB_YESNO) == mrYes)
            if (MessageDlg (s.c_str (), mtWarning,
                TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
                save_pr = true;
            else
                save_pr = false; // �� ���������
        } // end if ���� ������
        ///����������
        if (save_pr) { // if ���� ��������� ������
            DataModule1 -> Publik_PrikazFDQuery -> Insert ();
            DataModule1 -> Publik_PrikazFDQueryN_TYPE -> Value = 12;
            DataModule1 -> Publik_PrikazFDQueryN_PUBLIC_PRIKAZ -> Value =
                StrToInt (Edit127 -> Text);
            DataModule1 -> Publik_PrikazFDQueryD_PUBLIC_PRIKAZ -> Value =
                DateTimeToSQLTimeStamp (DateTimePicker112 -> Date);
            DataModule1 -> Publik_PrikazFDQueryNOMER -> Value =
                (int) (ListBox113 -> Items -> Objects[i]);
            DataModule1 -> Publik_PrikazFDQueryDESCRIBE -> Value =
                ListBox113 -> Items -> Strings[i];
            try {
                DataModule1 -> Publik_PrikazFDQuery -> ApplyUpdates ();
                DataModule1 -> Publik_PrikazFDQuery -> CommitUpdates ();
            }
            catch (...) {
                DataModule1 -> Publik_PrikazFDQuery -> CancelUpdates ();
                ShowMessage ("���� � ������������");
            }
        } // if ���� ��������� ������
        DM3 -> Prikaz_DopuskPeopleFDQuery -> Next ();
    } // end for

    ListBox113 -> Clear ();
    ListBox113 -> Visible = false;
    Button111 -> Visible = false;
    ComboBox111 -> ItemIndex = -1;
    Edit126 -> Clear ();
    Label197 -> Enabled = false;
    Label198 -> Enabled = false;
    Edit127 -> Clear ();
    DateTimePicker112 -> Date = Now ();
    DateTimePicker112 -> Time = StrToTime ("00:00");
    Edit127 -> Enabled = false;
    DateTimePicker112 -> Enabled = false;
    DataModule1 -> Publik_PrikazFDQuery -> Close ();
    DM3 -> Prikaz_DopuskPeopleFDQuery -> Close ();

}

// ������ �� ������ � �������

void __fastcall TDeloForm::Button1Click (TObject * Sender) {
    DataModule1 -> Publik_PrikazFDQuery -> Close ();
    DataModule1 -> Publik_PrikazFDQuery -> Open ();
    for (int i = 0; i <= ListBox3 -> Items -> Count - 1; i++) { // for
        bool save_pr = true; // ���������� ���� �� ��������� ������

        Variant dopusk = DataModule1 -> Publik_PrikazFDQuery -> Lookup
            ("NOMER;N_TYPE", VarArrayOf (OPENARRAY (Variant,
            ( (int) (ListBox3 -> Items -> Objects[i]), 13))),
            "N_PUBLIC_PRIKAZ;D_PUBLIC_PRIKAZ");
        if (!dopusk.IsNull ()) { // if ���� ������
            AnsiString s =
                "������� " + DM3 -> Prikaz_DopuskPeopleFDQueryFAM -> Value + " " +
                DM3 -> Prikaz_DopuskPeopleFDQueryNAME -> Value + " " +
                DM3 -> Prikaz_DopuskPeopleFDQueryOTCH -> Value + +
                "\n��� ����� ������ � ������ ������� �" +
                VarToStr (dopusk.GetElement (0)) + " �� " +
                VarToStr (dopusk.GetElement (1)) +
                ".\nC�������� ��� ����� ������?";
            // !!!if (Application -> MessageBox (s.c_str (),"��������������", MB_YESNO) == mrYes)
            if (MessageDlg (s.c_str (), mtWarning,
                TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
                save_pr = true;
            else
                save_pr = false; // �� ���������
        } // end if ���� ������
        ///����������
        if (save_pr) { // if ���� ��������� ������
            DataModule1 -> Publik_PrikazFDQuery -> Insert ();
            DataModule1 -> Publik_PrikazFDQueryN_TYPE -> Value = 13;
            DataModule1 -> Publik_PrikazFDQueryN_PUBLIC_PRIKAZ -> Value =
                StrToInt (Edit27 -> Text);
            DataModule1 -> Publik_PrikazFDQueryD_PUBLIC_PRIKAZ -> Value =
                DateTimeToSQLTimeStamp (DateTimePicker12 -> Date);
            DataModule1 -> Publik_PrikazFDQueryNOMER -> Value =
                (int) (ListBox3 -> Items -> Objects[i]);
            DataModule1 -> Publik_PrikazFDQueryDESCRIBE -> Value =
                ListBox3 -> Items -> Strings[i];
            try {
                DataModule1 -> Publik_PrikazFDQuery -> ApplyUpdates ();
                DataModule1 -> Publik_PrikazFDQuery -> CommitUpdates ();
            }
            catch (...) {
                DataModule1 -> Publik_PrikazFDQuery -> CancelUpdates ();
                ShowMessage ("���� � ������������");
            }
        } // if ���� ��������� ������
    } // end for

    ListBox3 -> Clear ();
    ListBox3 -> Visible = false;
    Button1 -> Visible = false;
    ComboBox11 -> ItemIndex = -1;
    Edit26 -> Clear ();
    Label97 -> Enabled = false;
    Label98 -> Enabled = false;
    Edit27 -> Clear ();
    DateTimePicker12 -> Date = Now ();
    DateTimePicker12 -> Time = StrToTime ("00:00");
    Edit27 -> Enabled = false;
    DateTimePicker12 -> Enabled = false;
    DataModule1 -> Publik_PrikazFDQuery -> Close ();
}

void __fastcall TDeloForm::RadioGroup10Click (TObject * Sender) {
    // ShowMessage ("�������� ����� ������ ��������. �������� �������� � ����������� ��������.");
    switch (RadioGroup10 -> ItemIndex)
    { // switch ����� ��������� ����������� ��� �����������
    case -1: // ��� ������
        // --------
        ComboBox2 -> ItemIndex = -1;
        Edit2 -> Text = "";
        ComboBox2 -> Visible = false; // ��� ��������
        Edit2 -> Visible = false; // ������
        BitBtn1 -> Visible = false; // ������ ������
        Label4 -> Visible = false;
        Label5 -> Visible = false;
        // ComboBox2 -> SetFocus ();
        // -------------

        Panel2 -> Visible = false;
        FIOLook -> KeyValue = -1; // ������� ���
        DBLookupComboBox1 -> KeyValue = -1; // ������� ������� ����������
        Edit28 -> Text = ""; // ������� � �������
        DateTimePicker13 -> Date = Now (); // ������� ���� �������
        DateTimePicker13 -> Time = StrToTime ("00:00");
        break;
    case 0: // ����������� ��������

        // --------
        ComboBox2 -> ItemIndex = -1;
        Edit2 -> Text = "";
        ComboBox2 -> Visible = true; // ��� ��������
        Edit2 -> Visible = true; // ������
        BitBtn1 -> Visible = true; // ������ ������
        Label4 -> Visible = true;
        Label5 -> Visible = true;
        ComboBox2 -> SetFocus ();
        // ---
        Panel2 -> Visible = false;
        FIOLook -> KeyValue = -1; // ������� ���
        DBLookupComboBox1 -> KeyValue = -1; // ������� ������� ����������
        Edit28 -> Text = ""; // ������� � �������
        DateTimePicker13 -> Date = Now (); // ������� ���� �������
        DateTimePicker13 -> Time = StrToTime ("00:00");
        break;
    case 1: // �������� ����������
        // --------
        ComboBox2 -> ItemIndex = -1;
        Edit2 -> Text = "";
        ComboBox2 -> Visible = false; // ��� ��������
        Edit2 -> Visible = false; // ������
        BitBtn1 -> Visible = false; // ������ ������
        Label4 -> Visible = false;
        Label5 -> Visible = false;
        // -------------
        /*
         DataModule1 -> People_PartFDQuery -> Close ();
         DataModule1 -> People_PartFDQuery -> SQL -> Clear ();
         DataModule1 -> People_PartFDQuery -> SQL -> Add ("SELECT NOMER, FAM, NAME, OTCH, INC_GROUP, N_GROUP, VID_EDU, KURS, N_FOUND FROM PEOPLE WHERE (N_FAC="+AnsiString (nom_fac)+") AND (STATUS_PEOPLE=3) AND (INC_GROUP=:INC_GROUP) ORDER BY FAM, NAME, OTCH");
         DataModule1 -> People_PartFDQuery -> ParamByName ("INC_GROUP") -> AsInteger=18;
         DataModule1 -> People_PartFDQuery -> Open (); */

        DataModule1 -> PeopleUpFDQuery -> Close ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Clear ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Add
            ("SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, D_INCLUDE, DATE_END, STATUS_KURS, N_FOUND, FAM ||' '|| NAME ||' ' || OTCH as FIO  FROM PEOPLE People WHERE (N_FAC=" +
            AnsiString (nom_fac) +
            ") AND (STATUS_PEOPLE=3) AND (INC_GROUP=:I_GR) ORDER BY FAM, NAME, OTCH");
        DataModule1 -> PeopleUpFDQuery -> ParamByName ("I_GR") -> AsInteger = 18;
        DataModule1 -> PeopleUpFDQuery -> Open ();

        // if (DataModule1 -> People_PartFDQuery -> RecordCount)
        if (DataModule1 -> PeopleUpFDQuery -> RecordCount)
        { // ���� �������� �������, �� ���������� ������ � ��������� Query � ����� �������
            Panel2 -> Visible = true;
            DataModule1 -> RestoreFDQuery -> Open ();
            // DataModule1 -> RestoreFDQuery -> Insert ();
        }
        else { // ���� ������� �� ����������
            ShowMessage ("��� ���������, ����������� � ������������� �������!");

        }
        break;

    } // end switch ����� ��������� ����������� ��� �����������
}

void __fastcall TDeloForm::TabSheet8Exit (TObject * Sender)
{ // ��� Exit �  TabSheet ��������� Query  ��� ������ ������ �� ���������
    if (DataModule1 -> PeopleUpFDQuery -> State != dsInactive)
        DataModule1 -> PeopleUpFDQuery -> Close ();
    if (DataModule1 -> People_PartFDQuery -> State != dsInactive)
        DataModule1 -> People_PartFDQuery -> Close ();
    DM2 -> SpecializFDTable -> Filtered = true;
}

void __fastcall TDeloForm::ComboBox7Change (TObject * Sender) {
    Panel11 -> Visible = false;
    RadioGroup3 -> ItemIndex = -1;
    Label64 -> Caption = "";
    DBLookupComboBox10 -> Visible = false;
    // ComboBox7 -> ItemIndex=-1;//��� ��������
    // Edit16 -> Text="";//  � ������ �� ������
}

void __fastcall TDeloForm::ComboBox5Change (TObject * Sender) {
    // �������� ���� ������ �� ����������� � �������� ������ �� ��� ��������
    ListBox2 -> Visible = false;
    ListBox2 -> Clear ();
    Label35 -> Visible = false;
    Panel6 -> Visible = false;
    // -----
    Label33 -> Enabled = false;
    Label34 -> Enabled = false;
    Edit12 -> Enabled = false;
    Edit12 -> Text = "";
    DateTimePicker2 -> Enabled = false;
    DateTimePicker2 -> Date = Now ();
    DateTimePicker112 -> Date = Now ();
    DateTimePicker2 -> Time = StrToTime ("00:00");
    DateTimePicker112 -> Time = StrToTime ("00:00");
    // -----

    DataModule1 -> People_KursFDQuery -> Close ();
    DataModule1 -> Prikaz_KursFDQuery -> Close ();
    DataModule1 -> People_PartFDQuery -> Close ();
}

void __fastcall TDeloForm::FormCreate (TObject * Sender) {
    ShowMessage (
        "��������! ������ �������� ��� ����������� �������� ������ ���� �������.");
    DateTimePicker9 -> DateTime = Now ();
    DateTimePicker9 -> Time = 0;
    DateTimePicker10 -> DateTime = Now ();
    DateTimePicker10 -> Time = 0;
    DateTimePicker11 -> DateTime = Now ();
    DateTimePicker11 -> Time = 0;
    DateTimePicker18 -> DateTime = Now ();
    DateTimePicker18 -> Time = 0;
}

void __fastcall TDeloForm::RadioGroup12Click (TObject * Sender) {
    if (RadioGroup12 -> ItemIndex == 2 || RadioGroup12 -> ItemIndex == 3)
    { // if ������� �������� � ������ ����
        LabeledEdit1 -> Text = "";
        LabeledEdit1 -> Visible = true;
    }
    else
        LabeledEdit1 -> Visible = false;
}

void __fastcall TDeloForm::RadioGroup13Click (TObject * Sender)
{ // �������� ������
    // ����� ���� �������

    Clear_Holiday (); // �������� ����������� �� �������� �������

    if (RadioGroup13 -> ItemIndex != -1) {
        DataModule1 -> PeopleUpFDQuery -> Close ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Clear ();
        DataModule1 -> PeopleUpFDQuery -> SQL -> Add
            ("SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, D_INCLUDE, DATE_END, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND, FAM ||' '|| NAME ||' ' || OTCH as FIO  FROM PEOPLE People WHERE (N_FAC=" +
            AnsiString (nom_fac) +
            ") AND (STATUS_PEOPLE in (1,3)) ORDER BY FAM, NAME, OTCH");
        DataModule1 -> PeopleUpFDQuery -> Open ();

        Label99 -> Visible = true;
        DBLookupComboBox22 -> Visible = true;
        if (RadioGroup13 -> ItemIndex == 2) {
            Label102 -> Caption = "�����        �:";
            Label103 -> Enabled = false;
            DateTimePicker20 -> Enabled = false;
        }
        else {
            Label102 -> Caption = "������        �:";
            Label103 -> Enabled = true;
            DateTimePicker20 -> Enabled = true;
        }
    }

}

void __fastcall TDeloForm::Clear_Holiday ()
{ // �������� ����������� �� �������� �������
    // ���
    Label99 -> Visible = true;
    DBLookupComboBox22 -> Visible = true;
    DBLookupComboBox22 -> KeyValue = -1;
    // ------
    Panel17 -> Visible = false;
    Edit4 -> Text = ""; // � �������
    DateTimePicker19 -> Date = Now (); // ���� �������
    DateTimePicker19 -> Time = StrToTime ("00:00");
    DBLookupComboBox21 -> KeyValue = -1; // �������

    DateTimePicker20 -> Date = Now (); // ���� ������ �������
    DateTimePicker20 -> Time = StrToTime ("00:00");
    DateTimePicker21 -> Date = Now ();
    // ���� ��������� �������
    DateTimePicker21 -> Time = StrToTime ("00:00");
    // --------
    Panel18 -> Visible = false;
    // �������������
    DBLookupComboBox23 -> KeyValue = -1;
    // �������������
    DBLookupComboBox24 -> KeyValue = -1;
    // � ������
    Edit5 -> Text = "";
    // ����
    Edit34 -> Text = "";
    // ����� ��������
    RadioGroup14 -> ItemIndex = -1;

    DataModule1 -> PeopleUpFDQuery -> Close ();

}

void __fastcall TDeloForm::DBLookupComboBox22CloseUp (TObject * Sender) {
    Panel17 -> Visible = true;

    switch (RadioGroup13 -> ItemIndex) { // switch
    case 2:
    case 5:
        Panel18 -> Visible = true;
        // �������������
        DBLookupComboBox23 -> KeyValue =
            DataModule1 -> PeopleUpFDQueryN_SPEC -> Value;
        // �������������
        DBLookupComboBox24 -> KeyValue =
            DataModule1 -> PeopleUpFDQueryN_SPECIALIZ -> Value;
        // � ������
        Edit5 -> Text = DataModule1 -> PeopleUpFDQueryN_GROUP -> Value;
        // ����
        Edit34 -> Text = AnsiString (DataModule1 -> PeopleUpFDQueryKURS -> Value);
        // ����� ��������
        RadioGroup14 -> ItemIndex = DataModule1 -> PeopleUpFDQueryVID_EDU -> Value;
        break;

    default:
        Panel18 -> Visible = false;
        break;

    } // end switch
}

void __fastcall TDeloForm::BitBtn30Click (TObject * Sender)
{ // ������ �������� �� �������� ������
    Clear_Holiday ();
    RadioGroup13 -> ItemIndex = -1;
    // ���
    Label99 -> Visible = false;
    DBLookupComboBox22 -> Visible = false;
}

void __fastcall TDeloForm::BitBtn29Click (TObject * Sender)
{ // ������ ��������� �� �������� ������

    // ---�������� �� ��������
    if (Edit4 -> Text == "") {
        ShowMessage ("������� ����� � ���� �������!");
        return;
    }

    if (DBLookupComboBox21 -> KeyValue == -1) {
        ShowMessage ("������� �������!");
        return;
    }

    // --------

    switch (RadioGroup13 -> ItemIndex) { // switch
    case 2:
    case 5: // ����� ������� ���������� �����������
        {
            // �������� �� ����� ������ � ���������
            if (!check_fac_group (Edit5 -> Text))
                return;
            // ������� �������� ������������ ������ ������ � ������ �����
            if (!check_group_kurs (Edit5 -> Text, Edit34 -> Text))
                return;
            DataModule1 -> PeopleUpFDQuery -> Edit ();
            Variant i_gr = search_increment_group (Edit5 -> Text,
                RadioGroup14 -> ItemIndex);
            // ---------
            DataModule1 -> PeopleUpFDQuerySTATUS_PEOPLE -> Value = 1;
            // ������ ��� ������������ ��������
            try { // ��������� ������
                DataModule1 -> PeopleUpFDQueryINC_GROUP -> Value = i_gr;
            }
            catch (...) { // catch ������
                ShowMessage ("����� ������ �� ����������!");
            } // end catch ������
            DataModule1 -> PeopleUpFDQueryN_GROUP -> Value = Edit5 -> Text;
            // ����� ������
            DataModule1 -> PeopleUpFDQueryKURS -> Value =
                StrToInt (Edit34 -> Text); // ����
            DataModule1 -> PeopleUpFDQueryN_SPEC -> Value =
                DBLookupComboBox23 -> KeyValue; // �������������
            DataModule1 -> PeopleUpFDQueryN_SPECIALIZ -> Value =
                DBLookupComboBox24 -> KeyValue; // �������������
            DataModule1 -> PeopleUpFDQueryVID_EDU -> Value =
                RadioGroup14 -> ItemIndex; // ����� ��������

            // ���� ��������� 30.06.2___ //���������!!!!! �� ������ ���������!!!!
            AnsiString kurs_uch = "", year_end = "", date_end = "";

            if (DataModule1 -> PeopleUpFDQueryVID_EDU -> Value == 1) { // �������
                kurs_uch = 6 - DataModule1 -> PeopleUpFDQueryKURS -> Value;
                // ������� ������ �������
                year_end = uch_god + kurs_uch; // ��� ���������
                if (kurs_uch == 0)
                    year_end = uch_god + 1; // ��� ���������
            }
            else { // �������
                kurs_uch = 5 - DataModule1 -> PeopleUpFDQueryKURS -> Value;
                // ������� ������ �������
                year_end = uch_god + kurs_uch; // ��� ���������
                if (kurs_uch == 0)
                    year_end = uch_god + 1; // ��� ���������
            }
            date_end = "30.06." + year_end;
            DataModule1 -> PeopleUpFDQueryDATE_END -> Value =
                DateTimeToSQLTimeStamp (StrToDate (date_end));

            break;
        }
    default: // ������� ���������� �� �������� ����������
        {
            DataModule1 -> PeopleUpFDQuery -> Edit ();
            if (DataModule1 -> PeopleUpFDQuerySTATUS_KURS -> Value == 1) {
                /* !!!if (Application -> MessageBox ("���� ������� ��� ������� ��������� �� ��������� ����. �������� ����� ������ � ����?",
                 "��������", MB_OKCANCEL) == IDOK) */
                if (MessageDlg
                    ("���� ������� ��� ������� ��������� �� ��������� ����. �������� ����� ������ � ����?",
                    mtConfirmation, TMsgDlgButtons () << mbOK << mbCancel,
                    0) == 1) { // if �������� ����� ������ � ���� �� ���� ������
                    int old_kurs = DataModule1 -> PeopleUpFDQueryKURS -> Value;
                    int old_gr =
                        StrToInt (DataModule1 -> PeopleUpFDQueryN_GROUP -> Value);
                    if (old_kurs != 1) {
                        DataModule1 -> PeopleUpFDQueryKURS -> Value =
                            (old_kurs - 1);
                        if (nom_fac == 3)
                        { // if ��� ����� - �� ���� ������� ��������� 0
                            DataModule1 -> PeopleUpFDQueryN_GROUP -> Value =
                                "0" + IntToStr (old_gr - 10);
                        }
                        else
                            DataModule1 -> PeopleUpFDQueryN_GROUP -> Value =
                                IntToStr (old_gr - 10);
                    }
                }

                DataModule1 -> PeopleUpFDQuerySTATUS_KURS -> Value = 0;
            }
            DataModule1 -> PeopleUpFDQuerySTATUS_PEOPLE -> Value = 3;
            // ������ ���  �������� � ������������� �������
            DataModule1 -> PeopleUpFDQueryINC_GROUP -> Value = 18;
            // ��������� ������
            break;
        }
    } // end switch
    if (DataModule1 -> HolidayFDQuery -> State == dsInactive)
        DataModule1 -> HolidayFDQuery -> Open ();
    if (DataModule1 -> HolidayFDQuery -> State != dsInsert)
        DataModule1 -> HolidayFDQuery -> Insert ();
    // ���������� � ���� Holiday ������ ��������
    DataModule1 -> HolidayFDQueryNOMER -> Value = DBLookupComboBox22 -> KeyValue;

    // ���� �������
    DataModule1 -> HolidayFDQueryD_PRIKAZ_HOL -> Value =
        DateTimeToSQLTimeStamp (DateTimePicker19 -> Date);

    ///---�������� �� ����� �������
    try { // �����  �������
        DataModule1 -> HolidayFDQueryN_PRIKAZ_HOL -> Value = StrToInt (Edit4 -> Text);
    }
    catch (...) { // catch ������
        DataModule1 -> PeopleUpFDQuery -> CancelUpdates ();
        DataModule1 -> HolidayFDQuery -> CancelUpdates ();
        ShowMessage ("����� ������� ������ ���� �������� ���������!");
        return;
    } // end catch ������

    // �������
    DataModule1 -> HolidayFDQueryN_HOL -> Value = DBLookupComboBox21 -> KeyValue;

    // ��� 1 -- ���� � �/�; 2-- ������� �/�;  3-- ����� �� �/�
    // 4  --  ������������� ������
    // 5  --  ��������� �������������� �������
    // 6  --  ����� �� �������
    // 7  --  ������ �� ������������ � �����
    // 8  --  ������ �� ����� �� �������� �� 3-� ���
    // 9  --  ������ �� ����� �� ���. �� 3-� ��� �� ��. �����.
    // 10 -- ������ �� ������������
    // 11 -- ������ ��� ����������� ������� ������
    DataModule1 -> HolidayFDQueryTYPE_HOL -> Value = RadioGroup13 -> ItemIndex + 4;

    // ���� ������ �/�
    if (RadioGroup13 -> ItemIndex != 2) {
        DateTimePicker20 -> Time = StrToTime ("00:00");
        DataModule1 -> HolidayFDQueryD_BEGIN_HOL -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker20 -> Date);
    }
    else {
        // ���� � ������� ������� �� �������, �� �������  � D_END_HOL
        DataModule1 -> HolidayFDQueryD_END_HOL -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker20 -> Date);
    }

    // ���� ��������� �/�
    if (t) {
        DataModule1 -> HolidayFDQueryD_END_HOL -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker21 -> Date);
    }

    // ---------
    try { // try ���������� �����������
        DataModule1 -> PeopleUpFDQuery -> ApplyUpdates ();
        DataModule1 -> PeopleUpFDQuery -> CommitUpdates ();
        DataModule1 -> HolidayFDQuery -> ApplyUpdates ();
        DataModule1 -> HolidayFDQuery -> CommitUpdates ();
        Clear_Holiday ();
        RadioGroup13 -> ItemIndex = -1;
        // ���
        Label99 -> Visible = false;
        DBLookupComboBox22 -> Visible = false;
        ShowMessage ("���������� ������ ������!");
    } // end try ���������� �����������
    catch (...) { // catch ������
        DataModule1 -> PeopleUpFDQuery -> CancelUpdates ();
        DataModule1 -> HolidayFDQuery -> CancelUpdates ();
        ShowMessage ("��������� ���� ��� ����������!");
    } // end catch ������

}

void __fastcall TDeloForm::Edit23KeyPress (TObject * Sender, char &Key) {
    DataModule1 -> Edit_Key (Key);
    // ��� �������, ����� � TEdit ����� ���� ������� ������ �����?
}

void __fastcall TDeloForm::BitBtn31Click (TObject * Sender)
{ // ������� ��������� �� ������������ ������� � �������

    if (ComboBox14 -> Text == "") {
        ShowMessage ("�������� ����� ��������!");
        return;
    }
    int kurs_v = 4; // ��������� ����
    if (ComboBox14 -> ItemIndex)
        kurs_v = 5;

    // switch (RadioGroup17 -> ItemIndex)
    // { //switch
    // case 0:
    // kurs_v=6;
    // break;
    // case 1:
    // kurs_v=5;
    // break;
    // }//end switch

    // if (RadioGroup17 -> ItemIndex)
    // {
    // if (ComboBox14 -> ItemIndex) kurs_v=5;
    // else kurs_v=4;//��������� ����
    // }
    // else
    // {
    // if (ComboBox14 -> ItemIndex) kurs_v=6;
    // else kurs_v=5;//��������� ����
    // }

    DataModule1 -> Diplom_Prikaz_vipuskFDQuery -> Close ();
    DataModule1 -> Diplom_Prikaz_vipuskFDQuery -> ParamByName ("N_FAC") -> AsSmallInt =
        nom_fac;
    DataModule1 -> Diplom_Prikaz_vipuskFDQuery -> ParamByName ("EDU") -> AsSmallInt =
        ComboBox14 -> ItemIndex;
    DataModule1 -> Diplom_Prikaz_vipuskFDQuery -> ParamByName ("KURS") -> AsSmallInt =
        kurs_v;
    DataModule1 -> Diplom_Prikaz_vipuskFDQuery -> Open ();
    DataModule1 -> Diplom_Prikaz_vipusk_countFDQuery -> Close ();
    DataModule1 -> Diplom_Prikaz_vipusk_countFDQuery -> ParamByName ("N_FAC")
        -> AsSmallInt = nom_fac;
    DataModule1 -> Diplom_Prikaz_vipusk_countFDQuery -> ParamByName ("EDU")
        -> AsSmallInt = ComboBox14 -> ItemIndex;
    DataModule1 -> Diplom_Prikaz_vipusk_countFDQuery -> ParamByName ("KURS")
        -> AsSmallInt = kurs_v;
    DataModule1 -> Diplom_Prikaz_vipusk_countFDQuery -> Open ();
    if (DataModule1 -> Diplom_Prikaz_vipusk_countFDQueryCOUNT -> Value) {
        // ������������ �������� �������

        for (int i = 0; i < 2; i++) { // for1
            mas_fio_nomer[i] =
                new AnsiString
                [DataModule1 -> Diplom_Prikaz_vipusk_countFDQueryCOUNT -> Value];
        } // end for 1
        mas = 1; // ��������, ��� ������ ������
        //////////////////////////////////////////////////////////////////////////
        DualListDlg = new TDualListDlg (this);
        DualListDlg -> SrcList -> Items -> Clear ();
        DualListDlg -> DstList -> Items -> Clear ();
        // ������������ �������� �������
        for (int j = 0;
        j <= DataModule1 -> Diplom_Prikaz_vipusk_countFDQueryCOUNT -> Value -
            1; j++) {
            mas_fio_nomer[0][j] =
                DataModule1 -> Diplom_Prikaz_vipuskFDQueryFAM -> Value + " " +
                DataModule1 -> Diplom_Prikaz_vipuskFDQueryNAME -> Value + " " +
                DataModule1 -> Diplom_Prikaz_vipuskFDQueryOTCH -> Value;
            DualListDlg -> SrcList -> Items -> AddObject (mas_fio_nomer[0][j],
                (TObject*)
                (DataModule1 -> Diplom_Prikaz_vipuskFDQueryNOMER -> Value));
            mas_fio_nomer[1][j] =
                AnsiString (DataModule1 -> Diplom_Prikaz_vipuskFDQueryNOMER
                -> Value);
            DataModule1 -> Diplom_Prikaz_vipuskFDQuery -> Next ();

        } // for  ������������ �������� �������
        // ��� ���������
        ListBox4 -> Clear ();
        DualListDlg -> ShowModal ();
        if (DataModule2 -> printdlg == true) {
            if (DualListDlg -> DstList -> Count != 0) {
                for (int i = 0; i <= DualListDlg -> DstList -> Count - 1; i++) {
                    ListBox4 -> Items -> AddObject
                        (AnsiString (i + 1) + ". " + mas_fio_nomer[0][i],
                        DualListDlg -> DstList -> Items -> Objects[i]);
                } // 1-�� for
                // ------
                Label112 -> Enabled = true;
                Edit36 -> Enabled = true;
                Label113 -> Enabled = true;
                DateTimePicker22 -> Enabled = true;
                Label114 -> Enabled = true;
                DateTimePicker23 -> Enabled = true;
                ListBox4 -> Visible = true;
                Button3 -> Visible = true;

            } // if MyList1 -> FOutList -> Count!=0
            else {
                ShowMessage ("�� �� ������� �� ������ ��������!");
            }
        } // if MyList1 -> Execute (MyList1)
        delete DualListDlg;
    }

}

void __fastcall TDeloForm::ComboBox14Change (TObject * Sender)
{ // ��������� ����� ��������
    Label112 -> Enabled = false;
    Edit36 -> Enabled = false;
    Label113 -> Enabled = false;
    DateTimePicker22 -> Enabled = false;
    Label114 -> Enabled = false;
    DateTimePicker23 -> Enabled = false;
    ListBox4 -> Visible = false;
    Button3 -> Visible = false;

    Edit36 -> Text = "";
    DateTimePicker22 -> Date = Now ();
    DateTimePicker22 -> Time = StrToTime ("00:00");
    DateTimePicker23 -> Date = Now ();
    DateTimePicker23 -> Time = StrToTime ("00:00");

    // if (ComboBox14 -> ItemIndex==0) RadioGroup17 -> Visible=false;
    // else RadioGroup17 -> Visible=true;
}

void __fastcall TDeloForm::Button3Click (TObject * Sender)
{ // ��������� ������ �� ������

    for (int i = 0; i < ListBox4 -> Items -> Count; i++) { // for i
        AnsiString List_text = ListBox4 -> Items -> Strings[i];
        int k = List_text.Pos ('.');
        // ������� ������ �� ������ ��� ���� ������
        List_text.Delete (1, k + 1);
        Save_PrikazVipusk (List_text, i);
        // ���������� ������� �� ������
    } // for i
    // ------------------
    Label112 -> Enabled = false;
    Edit36 -> Enabled = false;
    Label113 -> Enabled = false;
    DateTimePicker22 -> Enabled = false;
    Label114 -> Enabled = false;
    DateTimePicker23 -> Enabled = false;
    ListBox4 -> Visible = false;
    Button3 -> Visible = false;

    Edit36 -> Text = "";
    DateTimePicker22 -> Date = Now ();
    DateTimePicker22 -> Time = StrToTime ("00:00");
    DateTimePicker23 -> Date = Now ();
    DateTimePicker23 -> Time = StrToTime ("00:00");
}


void __fastcall TDeloForm::BitBtn128Click (TObject * Sender) {

    if (ComboBox111 -> Text == "" || Edit126 -> Text == "")
        ShowMessage ("������� ��� ������");
    else { //
        Variant sea2[2];
        sea2[0] = Variant (Edit126 -> Text);
        sea2[1] = Variant (ComboBox111 -> ItemIndex);
        i_gr = DM2 -> Increment_GroupFDTable -> Lookup ("N_GROUP;VID_EDU",
            VarArrayOf (sea2, 1), "INC_GROUP");
        if (!i_gr.IsNull ()) { // if IsNull
            DM3 -> Prikaz_DopuskPeopleFDQuery -> Close ();
            DM3 -> Prikaz_DopuskPeopleFDQuery -> SQL -> Clear ();
            DM3 -> Prikaz_DopuskPeopleFDQuery -> SQL -> Add ("SELECT NOMER, FAM, NAME, OTCH, POL, NAZ, PAPA, MAMA, MARIAGE, N_CHILD, EDUCATION, ARMY, SCHOLARSHIP, HOSTEL, NAME_EDUC, WHEN_EDUC, WHERE_EDUC, PHOTO, MIDDLE_B, N_VID_SPORT, N_DELA, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, EDU_WORK, D_PRIKAZ_KURS, N_FOUND, N_PRIKAZ_INCLUDE, D_PRIKAZ_INCLUDE, N_GROUP, STATUS_PEOPLE, INC_GROUP, WORK_BEFORE, ADDRESS_BEFORE, ADDRESS, ADDRESS_LIFE, DATA_R, F_OLD, PHONE, STATUS_KURS, N_ZACHET \
             FROM PEOPLE  where (STATUS_PEOPLE=1) and (INC_GROUP=" +
                VarToStr (i_gr) + ") AND (VID_EDU=" + ComboBox111 -> ItemIndex +
                ") ORDER BY FAM, NAME, OTCH");

            // DM3 -> Prikaz_DopuskPeopleFDQuery -> ParamByName ("INC_GROUP") -> Value=i_gr;
            // DM3 -> Prikaz_DopuskPeopleFDQuery -> ParamByName ("VID_EDU") -> Value=ComboBox6 -> ItemIndex;
            DM3 -> Prikaz_DopuskPeopleFDQuery -> Open ();
            if (DM3 -> Prikaz_DopuskPeopleFDQuery -> RecordCount != 0) {
                // ������������ �������� �������
                AnsiString *mas_stud2[2];
                // ������ ������� � ������� ���������
                for (int i = 0; i < 2; i++)
                    mas_stud2[i] =
                        new AnsiString
                        [DM3 -> Prikaz_DopuskPeopleFDQuery -> RecordCount];
                //////////////////////////////////////////////////////////////////////////
                DM3 -> Prikaz_DopuskPeopleFDQuery -> First ();
                DualListDlg = new TDualListDlg (this);
                DualListDlg -> SrcList -> Items -> Clear ();
                DualListDlg -> DstList -> Items -> Clear ();
                // ������������ �������� �������
                for (int j = 0;
                j <= DM3 -> Prikaz_DopuskPeopleFDQuery -> RecordCount - 1; j++) {
                    mas_stud2[0][j] =
                        DM3 -> Prikaz_DopuskPeopleFDQueryFAM -> Value + " " +
                        DM3 -> Prikaz_DopuskPeopleFDQueryNAME -> Value + " " +
                        DM3 -> Prikaz_DopuskPeopleFDQueryOTCH -> Value;
                    DualListDlg -> SrcList -> Items -> AddObject (mas_stud2[0][j],
                        (TObject*)
                        (DM3 -> Prikaz_DopuskPeopleFDQueryNOMER -> Value));
                    mas_stud2[1][j] =
                        AnsiString (DM3 -> Prikaz_DopuskPeopleFDQueryNOMER -> Value);
                    DM3 -> Prikaz_DopuskPeopleFDQuery -> Next ();

                } // for  ������������ �������� �������
                // ��� ���������

                DualListDlg -> ShowModal ();

                if (DataModule2 -> printdlg == true) {
                    if (DualListDlg -> DstList -> Items -> Count != 0) {
                        // ������������ Query ��� ������ ���������
                        AnsiString Str_Nomer = "";
                        for (int i = 0;
                        i <= DualListDlg -> DstList -> Count - 1; i++) {
                            Str_Nomer += mas_stud2[1][i] + ",";
                            // ���������� ����� ��������
                        } // 1-�� for

                        Str_Nomer.SetLength (Str_Nomer.Length () - 1);
                        // ������������ Query ��� ������
                        DM3 -> Prikaz_DopuskPeopleFDQuery -> Close ();
                        DM3 -> Prikaz_DopuskPeopleFDQuery -> SQL -> Clear ();
                        DM3 -> Prikaz_DopuskPeopleFDQuery -> SQL -> Add ("SELECT NOMER, FAM, NAME, OTCH, POL, NAZ, PAPA, MAMA, MARIAGE, N_CHILD, EDUCATION, ARMY, SCHOLARSHIP, HOSTEL, NAME_EDUC, WHEN_EDUC, WHERE_EDUC, PHOTO, MIDDLE_B, N_VID_SPORT, N_DELA, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, EDU_WORK, D_PRIKAZ_KURS, N_FOUND, N_PRIKAZ_INCLUDE, D_PRIKAZ_INCLUDE, N_GROUP, STATUS_PEOPLE, INC_GROUP, WORK_BEFORE, ADDRESS_BEFORE, ADDRESS, ADDRESS_LIFE, DATA_R, F_OLD, PHONE, STATUS_KURS, N_ZACHET \
                         FROM PEOPLE  where (STATUS_PEOPLE=1) and (INC_GROUP=" +
                            VarToStr (i_gr) + ") AND (NOMER IN (" + Str_Nomer +
                            ")) ORDER BY FAM, NAME, OTCH");
                        DM3 -> Prikaz_DopuskPeopleFDQuery -> Open ();
                        Label197 -> Enabled = true;
                        Edit127 -> Enabled = true;
                        Label198 -> Enabled = true;
                        DateTimePicker112 -> Enabled = true;
                        ListBox113 -> Clear ();
                        ListBox113 -> Visible = true;
                        Button111 -> Visible = true;

                        for (int i = 0;
                        i <= DM3 -> Prikaz_DopuskPeopleFDQuery -> RecordCount -
                            1; i++) {

                            ListBox113 -> Items -> AddObject
                                (DualListDlg -> DstList -> Items -> Strings[i],
                                DualListDlg -> DstList -> Items -> Objects[i]);
                            DM3 -> Prikaz_DopuskPeopleFDQuery -> Next ();
                        }
                        DataModule1 -> Publik_PrikazFDQuery -> Close ();
                        //

                    } // if MyList1 -> FOutList -> Count!=0
                    else {
                        ShowMessage ("�� �� ������� �� ������ ��������!");
                    }
                } // if MyList1 -> Execute (MyList1)
                delete DualListDlg;
            } // if  DM3 -> Prikaz_DopuskPeopleFDQuery -> RecordCount!=0

        } // if i_gr.IsNull ()
        else {
            MessageBox (0, "�� ������ ��������� ����� ������", "", MB_OK);

        } // else i_gr.IsNull ()

    } // else

}

void __fastcall TDeloForm::Save_PrikazVipusk (AnsiString Fio, int j)
{ // ���������� ������� �� ������
    TLocateOptions Opts;
    Variant v;
    v = DataModule1 -> Diplom_Prikaz_vipuskFDQuery -> Locate ("NOMER",
        (int) (ListBox4 -> Items -> Objects[j]), Opts);

    if (v.IsNull ()) {
        AnsiString text = "�� ������� ��������� ������ ��� ��������: " +
            ListBox4 -> Items -> Strings[j];
        ShowMessage (text.c_str ());
        return;
    }
    DataModule1 -> Diplom_Prikaz_vipuskFDQuery -> Edit ();
    DataModule1 -> Diplom_Prikaz_vipuskFDQueryD_PRIKAZ_KURS -> Value =
        DateTimeToSQLTimeStamp (DateTimePicker23 -> Date);
    // ������� ���������� �...
    DataModule1 -> Diplom_Prikaz_vipuskFDQuery -> ApplyUpdates ();
    DataModule1 -> Diplom_Prikaz_vipuskFDQuery -> CommitUpdates ();

    // ������ � ������� Public_Prikaz
    DataModule1 -> Publik_PrikazFDQuery -> Open ();
    DataModule1 -> Publik_PrikazFDQuery -> Insert ();
    DataModule1 -> Publik_PrikazFDQueryN_TYPE -> Value = 9;
    DataModule1 -> Publik_PrikazFDQueryN_PUBLIC_PRIKAZ -> Value =
        StrToInt (Edit36 -> Text);
    DataModule1 -> Publik_PrikazFDQueryD_PUBLIC_PRIKAZ -> Value =
        DateTimeToSQLTimeStamp (DateTimePicker22 -> Date);
    DataModule1 -> Publik_PrikazFDQueryNOMER -> Value =
        (int) (ListBox4 -> Items -> Objects[j]);
    DataModule1 -> Publik_PrikazFDQueryDESCRIBE -> Value =
        ListBox4 -> Items -> Strings[j];
    try { // try ���������� �������
        DataModule1 -> Publik_PrikazFDQuery -> ApplyUpdates ();
        DataModule1 -> Publik_PrikazFDQuery -> CommitUpdates ();
        DataModule1 -> Publik_PrikazFDQuery -> Close ();
    } // end try ���������� �������
    catch (...) { // catch ������
        DataModule1 -> Publik_PrikazFDQuery -> CancelUpdates ();
        ShowMessage (
            "���� � ���������. ���������� � ��������������. �� ���������� ������ � �������");
    } // end catch ������
    return;

    }

void __fastcall TDeloForm::RadioGroup18Click (TObject * Sender) {
    if (RadioGroup18 -> ItemIndex == 1) {
        Label66 -> Caption = "����:";
        Button4 -> Visible = True;
        BitBtn17 -> Visible = False;
        Panel13 -> Visible = False;
        Edit17 -> Text = "";
    }
    else {
        Label66 -> Caption = "������:";
        Button4 -> Visible = False;
        BitBtn17 -> Visible = True;
        Panel13 -> Visible = False;
        Edit17 -> Text = "";
    }
}

void __fastcall TDeloForm::Button4Click (TObject * Sender) {
    ListBox5 -> Clear ();
    ListBox5 -> Visible = True;
    ListBox5 -> Top = 10;
    RadioGroup6 -> Visible = False;
    RadioGroup7 -> Visible = False;
    Label72 -> Visible = False;
    Label73 -> Visible = False;
    Edit19 -> Visible = False;
    DBLookupComboBox12 -> Visible = False;

    // �������� �������, �������� �� ������ ������� ��������
    if (ComboBox8 -> Text == "" || Edit17 -> Text == "")
    { // if �������� �� ���� ���� ������
        ShowMessage ("������� ��� ������!");
        return;
    } // end if �������� �� ���� ���� ������

    // sql_old="SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND FROM PEOPLE People";

    DataModule1 -> PeopleUpFDQuery -> Close ();
    DataModule1 -> PeopleUpFDQuery -> SQL -> Clear ();
    DataModule1 -> PeopleUpFDQuery -> SQL -> Add
        ("SELECT NOMER, VID_EDU, N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, D_PRIKAZ_KURS, D_INCLUDE, DATE_END, N_GROUP, INC_GROUP, F_OLD, STATUS_PEOPLE, FAM, NAME, OTCH, DATA_R, STATUS_KURS, N_FOUND, FAM ||' '|| NAME ||' ' || OTCH as FIO  FROM PEOPLE People WHERE (N_FAC=" +
        AnsiString (nom_fac) +
        ") AND (STATUS_PEOPLE=1) AND (KURS=:KURS) AND (VID_EDU=:VID_EDU)  ORDER BY FAM, NAME, OTCH");
    DataModule1 -> PeopleUpFDQuery -> ParamByName ("KURS") -> AsInteger =
        Variant (Edit17 -> Text);
    DataModule1 -> PeopleUpFDQuery -> ParamByName ("VID_EDU") -> AsInteger =
        ComboBox8 -> ItemIndex;
    DataModule1 -> PeopleUpFDQuery -> Open ();

    if (DataModule1 -> PeopleUpFDQuery -> RecordCount)
    { // if �������� ��   RecordCount
        Panel12 -> Height = 61;
        // ���������� ������ � �������������� ��������
        Panel13 -> Visible = true; // ������ �������� �������
        DataModule1 -> Public_PrikazFDQuery -> Open ();
        DataModule1 -> Public_PrikazFDQuery -> Insert ();
    } // end if �������� ��   RecordCount
    else { // else �������� ��   RecordCount
        ShowMessage ("��� �� ������ �������� �� ��������� �������!");
        Edit17 -> SetFocus ();
    } // end else �������� ��   RecordCount
    DualListDlg = new TDualListDlg (this);
    DualListDlg -> SrcList -> Items -> Clear ();
    DualListDlg -> DstList -> Items -> Clear ();
    for (int i = 0; i < DataModule1 -> PeopleUpFDQuery -> RecordCount; i++) {
        DualListDlg -> SrcList -> Items -> AddObject
            (DataModule1 -> PeopleUpFDQueryFAM -> Value + ' ' +
            DataModule1 -> PeopleUpFDQueryNAME -> Value + ' ' +
            DataModule1 -> PeopleUpFDQueryOTCH -> Value + ", " +
            DataModule1 -> PeopleUpFDQueryNOMER -> Value,
            (TObject*) (DataModule1 -> PeopleUpFDQueryNOMER -> Value));
        DataModule1 -> PeopleUpFDQuery -> Next ();
    }

    DualListDlg -> ShowModal ();

    if (DataModule2 -> printdlg == true) {
        if (!DualListDlg -> DstList -> Items -> Count)
        { // if  ���� �� ������� �� ������ �������� �   FOutList
            DataModule1 -> PeopleUpFDQuery -> Close ();
            DataModule1 -> Public_PrikazFDQuery -> Close ();
            ShowMessage ("�� �� ������� �� ������ ��������!");
        } // end if  �� ������� �� ������ �������� �   FOutList

        ListBox5 -> Visible = true;
        for (int i = 0; i < DualListDlg -> DstList -> Items -> Count; i++) {
            ListBox5 -> Items -> AddObject (AnsiString (i + 1) + ". " +
                DualListDlg -> DstList -> Items -> Strings[i],
                DualListDlg -> DstList -> Items -> Objects[i]);
        }
    } // Execute ();
    delete DualListDlg;
}

void __fastcall TDeloForm::DateTimePicker1Change (TObject * Sender) {
    DateTimePicker1 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker10Change (TObject * Sender) {
    DateTimePicker10 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker11Change (TObject * Sender) {
    DateTimePicker11 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker112Change (TObject * Sender) {
    DateTimePicker112 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker12Change (TObject * Sender) {
    DateTimePicker12 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker13Change (TObject * Sender) {
    DateTimePicker13 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker14Change (TObject * Sender) {
    DateTimePicker14 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker15Change (TObject * Sender) {
    DateTimePicker15 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker16Change (TObject * Sender) {
    DateTimePicker16 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker17Change (TObject * Sender) {
    DateTimePicker17 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker18Change (TObject * Sender) {
    DateTimePicker18 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker19Change (TObject * Sender) {
    DateTimePicker19 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker2Change (TObject * Sender) {
    DateTimePicker2 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker20Change (TObject * Sender) {
    DateTimePicker20 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker21Change (TObject * Sender) {
    DateTimePicker21 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker22Change (TObject * Sender) {
    DateTimePicker22 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker23Change (TObject * Sender) {
    DateTimePicker23 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker3Change (TObject * Sender) {
    DateTimePicker3 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker4Change (TObject * Sender) {
    DateTimePicker4 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker5Change (TObject * Sender) {
    DateTimePicker5 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker6Change (TObject * Sender) {
    DateTimePicker6 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker7Change (TObject * Sender) {
    DateTimePicker7 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker8Change (TObject * Sender) {
    DateTimePicker8 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::DateTimePicker9Change (TObject * Sender) {
    DateTimePicker9 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::Button5Click (TObject * Sender) {
    if (Button5 -> Caption == "������") {
        Button5 -> Caption = "����������";
        t = false;
        DateTimePicker21 -> Visible = False;
    }
    else {
        Button5 -> Caption = "������";
        t = true;
        DateTimePicker21 -> Visible = True;
    }
}


void __fastcall TDeloForm::PageControl1Change (TObject * Sender) {
    DateTimePicker14 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::TabSheet111Show (TObject * Sender) {
    DateTimePicker112 -> Date = Now ();
    DateTimePicker112 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::TabSheet11Show (TObject * Sender) {
    DateTimePicker12 -> Date = Now ();
    DateTimePicker12 -> Time = StrToTime ("00:00");
}

void __fastcall TDeloForm::Image1Click (TObject * Sender) {
    correct = !correct;
    ComboBox12 -> Visible = !ComboBox12 -> Visible;
    Edit37 -> Visible = !Edit37 -> Visible;
}

void __fastcall TDeloForm::Edit35Change (TObject * Sender) {
    AnsiString serial = Edit35 -> Text;
    AnsiString key;
    key = serial.SubString (serial.Length (), 1);
    if ( (key < '�' || key > '�')) {
        serial = serial.SubString (1, serial.Length () - 1);
        Edit35 -> Text = serial;
        ShowMessage (
            "����� ������� ������ ��������� ������ ������������� �����!");
    }
}

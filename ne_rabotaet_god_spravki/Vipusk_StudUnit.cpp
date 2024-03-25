// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Vipusk_StudUnit.h"
#include "DM3Unit.h"
#include "DataModule.h"
#include "CalendarUnit.h"
#include "DualList.h"
#include "DataModule_Card.h"
// ---------------------------------------------------------------------------
#pragma package (smart_init)
// !!!#pragma link "MyList"
#pragma resource "*.dfm"
TVipusk_Stud *Vipusk_Stud;
int kurs_v = 0; // ��������� ����
AnsiString *mas_fio_vip[2]; // ������ ������� � ������� ���������
int mas_vip = 0;
// ���������� ��� ����������� ���� �� ������ � ������� 0 - ������ ���

// 1 - ������ ����
// ---------------------------------------------------------------------------
__fastcall TVipusk_Stud::TVipusk_Stud (TComponent* Owner) : TForm (Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TVipusk_Stud::BitBtn1Click (TObject *Sender) {
    Vipusk_Stud -> Close ();
}

// ---------------------------------------------------------------------------
void __fastcall TVipusk_Stud::FormClose (TObject *Sender, TCloseAction &Action) {

    if (mas_vip) {
        for (int i = 0; i < 2; i++)
            delete[]mas_fio_vip[i];
        //delete[]mas_fio_vip;
        mas_vip = 0;
    }

    DataModule1 -> Inc_Group_OldFDQuery -> Close ();
    DataModule1 -> VipuskFDQuery -> Close ();
    Action = caFree;
}

// ---------------------------------------------------------------------------
void __fastcall TVipusk_Stud::Save_Vipusk (AnsiString Fio)
{ // ���������� �������

        /*TLocateOptions Opts;
        Variant v;
        v = DataModule1 -> VipuskFDQuery -> Locate ("NOMER",
            (int) (ListBox1 -> Items -> Objects[j]), Opts);

        if (v.IsNull ()) {
            AnsiString text = "�� ������� ��������� ��������: " +
                ListBox1 -> Items -> Strings[j];
            ShowMessage (text.c_str ());
            return;
        }

        DataModule1 -> VipuskFDQuery -> Edit ();
        DataModule1 -> VipuskFDQuerySTATUS_PEOPLE -> Value = 6;
        DataModule1 -> VipuskFDQueryINC_GROUP -> Value = 18;

        try {
            DataModule1 -> VipuskFDQuery -> ApplyUpdates ();
            DataModule1 -> VipuskFDQuery -> CommitUpdates ();
        } // try
        catch (...) {
            DataModule1 -> VipuskFDQuery -> CancelUpdates ();
            ShowMessage ("��������� ������!");
        } // cahth
        return;  */


}

// ---------------------------------------------------------------------------
void __fastcall TVipusk_Stud::Delete_IncGroup (int inc_gr, AnsiString nom_gr,
    int edu, int god) { // �������� ����������� �����

    // Delete_IncGroup (DM3 -> Delete_IncrementINC_GROUP -> Value,DM3 -> Delete_IncrementN_GROUP -> Value,
    // DM3 -> Delete_IncrementVID_EDU -> Value,DM3 -> Delete_IncrementGOD -> Value)
    TLocateOptions Opts;
    Opts.Clear ();
    Opts << loPartialKey;
    Variant locvalues[4];
    locvalues[0] = Variant (inc_gr);
    locvalues[1] = Variant (nom_gr);
    locvalues[2] = Variant (edu);
    locvalues[3] = Variant (god);
    // ---  ����� ������� �����
    if (DataModule1 -> Inc_Group_OldFDQuery -> Locate
        ("INC_GROUP;N_GROUP;VID_EDU;GOD", VarArrayOf (locvalues, 3), Opts))
    { // if ����� ��� ������
        DataModule1 -> Inc_Group_OldFDQuery -> Edit ();
        // ���������� �������� 2002/2003 �������� ����
        AnsiString text = "���������� ";
        if (edu)
            text += "�������� ";
        else
            text += "�������� ";
        text += IntToStr (uch_god) + "/" + IntToStr (uch_god + 1) +
            " �������� ����";
        DataModule1 -> Inc_Group_OldFDQueryDESCRIBE -> Value = text;
        DataModule1 -> Inc_Group_OldFDQuery -> Post ();
        DataModule1 -> Inc_Group_OldFDQuery -> ApplyUpdates ();
        DataModule1 -> Inc_Group_OldFDQuery -> CommitUpdates ();
    } // end if ����� ��� ������

    try { // try
        // ���������� ������
        DataModule1 -> Delete_IncrementFDQuery -> Delete ();
    }
    catch (...) {
        DataModule1 -> Inc_Group_OldFDQuery -> CancelUpdates ();
        DataModule1 -> Delete_IncrementFDQuery -> Cancel ();
        ShowMessage ("��������� ����!");
    }

}

// ---------------------------------------------------------------------------
void __fastcall TVipusk_Stud::BitBtn2Click (TObject *Sender)
{ // ��������� ���������
    ProgressBar1 -> Visible = true;
    ProgressBar1 -> Min = 0;
    ProgressBar1 -> Max = ListBox1 -> Items -> Count;

    // ------------
    for (int i = 0; i < ListBox1 -> Items -> Count; i++) { // for i
        ProgressBar1 -> Position = i;
        AnsiString List_text = ListBox1 -> Items -> Strings[i];
        int k = List_text.Pos ('.'); // ������� ������ �� ������ ��� ���� ������
        List_text.Delete (1, k + 1);
        TLocateOptions Opts;
        Variant v;
        v = DataModule1 -> VipuskFDQuery -> Locate ("NOMER",
            (int) (ListBox1 -> Items -> Objects[i]), Opts);

        if (v.IsNull ()) {
            AnsiString text = "�� ������� ��������� ��������: " +
                ListBox1 -> Items -> Strings[i];
            ShowMessage (text.c_str ());
            return;
        }

        DataModule1 -> VipuskFDQuery -> Edit ();
        DataModule1 -> VipuskFDQuerySTATUS_PEOPLE -> Value = 6;
        DataModule1 -> VipuskFDQueryINC_GROUP -> Value = 18;

        try {
            DataModule1 -> VipuskFDQuery -> ApplyUpdates ();
            DataModule1 -> VipuskFDQuery -> CommitUpdates ();
        } // try
        catch (...) {
            DataModule1 -> VipuskFDQuery -> CancelUpdates ();
            ShowMessage ("��������� ������!");
        } // cahth // ���������� �������
    } // for i

    // -------------�������� ����������� �����
    // ��� ���������� ������
    AnsiString fac = "";
    switch (nom_fac) {
    case 1:
        fac = "1";
        break;
    case 2:
        fac = "2";
        break;
    case 3:
        fac = "0";
        break;
    case 4:
        fac = "4";
        break;
    }
    // ��� ������ ���������� �����
    DataModule1 -> Delete_IncrementFDQuery -> Close ();
    DataModule1 -> Delete_IncrementFDQuery -> SQL -> Clear ();
    DataModule1 -> Delete_IncrementFDQuery -> SQL -> Add
        ("SELECT * FROM INCREMENT_GROUP  where N_GROUP like ('" + fac + kurs_v +
        "_')and VID_EDU=" + AnsiString (ComboBox1 -> ItemIndex));
    DataModule1 -> Delete_IncrementFDQuery -> Open ();
    int rec_gr = DataModule1 -> Delete_IncrementFDQuery -> RecordCount;

    // -�������� ���� �� ���� � ���� �������
    DM3 -> CountVipuskGroupFDQuery -> Close ();
    DM3 -> CountVipuskGroupFDQuery -> ParamByName ("FAC") -> AsSmallInt = nom_fac;
    DM3 -> CountVipuskGroupFDQuery -> ParamByName ("EDU") -> AsSmallInt =
        ComboBox1 -> ItemIndex;
    DM3 -> CountVipuskGroupFDQuery -> ParamByName ("KURS") -> AsSmallInt = kurs_v;
    DM3 -> CountVipuskGroupFDQuery -> Open ();

    // �������� Query ��� ���������� ������ ������� �����
    DataModule1 -> Inc_Group_OldFDQuery -> Open ();

    // ���� �� ���� ������� ���������� �����
    for (int i = 0; i < rec_gr; i++) { // for �� i ��� ������
        Variant vg = DM3 -> CountVipuskGroupFDQuery -> Lookup ("INC_GROUP",
            DataModule1 -> Delete_IncrementFDQueryINC_GROUP -> Value, "COUNT");
        // int kol=vg.AsType (varInteger);
        // if (!kol)
        if (vg.IsNull ()) { // if ��� ��������� � ������

            Delete_IncGroup (DataModule1 -> Delete_IncrementFDQueryINC_GROUP -> Value,
                DataModule1 -> Delete_IncrementFDQueryN_GROUP -> Value,
                DataModule1 -> Delete_IncrementFDQueryVID_EDU -> Value,
                DataModule1 -> Delete_IncrementFDQueryGOD -> Value);
        }
        else
            DataModule1 -> Delete_IncrementFDQuery -> Next ();
    } // end for �� i ��� ������
    // -------------
    try { // try
        // ���������� ������
        DataModule1 -> Delete_IncrementFDQuery -> ApplyUpdates ();
        DataModule1 -> Delete_IncrementFDQuery -> CommitUpdates ();
    }
    catch (...) {
        DataModule1 -> Delete_IncrementFDQuery -> CancelUpdates ();
        ShowMessage ("");
    }

    ProgressBar1 -> Visible = false;
    DataModule1 -> VipuskFDQuery -> Close ();
    ListBox1 -> Visible = false;
    Panel2 -> Visible = false;
}

// ---------------------------------------------------------------------------
void __fastcall TVipusk_Stud::BitBtn31Click (TObject *Sender) {
    // ������� ���������
    if (ComboBox1 -> Text == "") {
        ShowMessage ("�������� ����� ��������!");
        return;
    }
    /////////////-----------------------------

    if (ComboBox1 -> ItemIndex == 1)
        kurs_v = 5;
    else
        kurs_v = 4; // ��������� ����

    // if (ComboBox1 -> ItemIndex==0) kurs_v=4;
    //
    // if (ComboBox1 -> ItemIndex==1)   //��������� ����
    // {
    // if (RadioGroup17 -> ItemIndex==0) kurs_v=6;
    // else kurs_v=5;//��������� ����
    // }

    DataModule1 -> VipuskFDQuery -> Close ();
    DataModule1 -> VipuskFDQuery -> ParamByName ("N_FAC") -> Value = nom_fac;
    DataModule1 -> VipuskFDQuery -> ParamByName ("VID_EDU") -> Value = ComboBox1 -> ItemIndex;
    DataModule1 -> VipuskFDQuery -> ParamByName ("KURS") -> Value = kurs_v;
    DataModule1 -> VipuskFDQuery -> Open ();
    DataModule1 -> Count_VipuskFDQuery2 -> Close ();
    DataModule1 -> Count_VipuskFDQuery2 -> ParamByName ("N_FAC") -> Value = nom_fac;
    DataModule1 -> Count_VipuskFDQuery2 -> ParamByName ("VID_EDU") -> Value = ComboBox1 -> ItemIndex;
    DataModule1 -> Count_VipuskFDQuery2 -> ParamByName ("KURS") -> Value = kurs_v;
    DataModule1 -> Count_VipuskFDQuery2 -> Open ();

    if (DataModule1 -> Count_VipuskFDQuery2COUNT -> Value) { // if  DM3 -> VipuskQuery -> RecordCount
        // ������������ �������� �������
        for (int i = 0; i < 2; i++) { // for1
            mas_fio_vip[i] = new AnsiString[DataModule1 -> Count_VipuskFDQuery2COUNT -> Value];
        } // end for 1
        mas_vip = 1; // ��������, ��� ������ ������
        //////////////////////////////////////////////////////////////////////////

        DualListDlg = new TDualListDlg (this);
        DualListDlg -> Caption = "����� ��������� ��� ������";
        DualListDlg -> SrcList -> Items -> Clear ();
        DualListDlg -> DstList -> Items -> Clear ();
        // ������������ �������� �������
        for (int j = 0; j <= DataModule1 -> Count_VipuskFDQuery2COUNT -> Value - 1; j++) {
            mas_fio_vip[0][j] = DataModule1 -> VipuskFDQueryFAM -> Value + " " +
                DataModule1 -> VipuskFDQueryNAME -> Value + " " +
                DataModule1 -> VipuskFDQueryOTCH -> Value;
            // MyList1 -> SourceList -> Add (mas_fio_vip[0][j]);
            mas_fio_vip[1][j] = AnsiString (DataModule1 -> VipuskFDQueryNOMER -> Value);
            DualListDlg -> SrcList -> Items -> AddObject
                (DataModule1 -> VipuskFDQueryFAM -> Value + " " +
                DataModule1 -> VipuskFDQueryNAME -> Value + " " +
                DataModule1 -> VipuskFDQueryOTCH -> Value,
                (TObject *) (DataModule1 -> VipuskFDQueryNOMER -> Value));
            DataModule1 -> VipuskFDQuery -> Next ();

        } // for  ������������ �������� �������
        // ��� ���������
        ListBox1 -> Clear ();
        DualListDlg -> ShowModal ();
        if (DataModule2 -> printdlg == true) {
            if (DualListDlg -> DstList -> Count != 0) {
                for (int i = 0; i <= DualListDlg -> DstList -> Count-1; i++) {
                    ListBox1 -> Items -> AddObject
                        (AnsiString (i+1) + ". " +
                        DualListDlg -> DstList -> Items -> Strings[i],
                        DualListDlg -> DstList -> Items -> Objects[i]);
                }
                // 1-�� for
                // ------
                ListBox1 -> Visible = true;
                Panel2 -> Visible = true;
            } // if MyList1 -> FOutList -> Count!=0
            else {
                ShowMessage ("�� �� ������� �� ������ ��������!");
            }
        } // end if MyList1 -> Execute (MyList1)
    } // end if  DM3 -> VipuskQuery -> RecordCount
    else
        ShowMessage ("��� ��������� ��� �������!");
    delete DualListDlg;
}
// ---------------------------------------------------------------------------

void __fastcall TVipusk_Stud::ComboBox1Change (TObject *Sender) {
    // if (ComboBox1 -> ItemIndex==0) RadioGroup17 -> Visible=false;
    // else RadioGroup17 -> Visible=true;
}
// ---------------------------------------------------------------------------

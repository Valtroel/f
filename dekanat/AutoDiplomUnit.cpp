#include <vcl.h>
#pragma hdrstop


#include "AutoDiplomUnit.h"
#include "DataModule.h"
#include "DM3Unit.h"
#include "Func.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TAutoDiplomForm * AutoDiplomForm;


AnsiString par_god = "",                                                        // �������� �������
           reg     = "",                                                        // ��������������� �����
           tab1    = " ";                                                       // ��� ������� ��������

int        n_reg   = 0,                                                         // ���������� ���������������
           reg_5   = 0,                                                         // ����� ��� 5-�� �����
           reg_6   = 0,                                                         // ����� ��� 6-�� �����
           str_rr  = 1;                                                         // ����� ������

TFDQuery * qd,
         * qd_count;

Variant    App_n,
           Sh;


// BitBtn1Click
// BitBtn2Click
// Diplom_Shapka
// Diplom_text
// Diplom_Titul
// FormClose
// FormCreate
// MaxReg
// QOpen
// RadioGroup1Click
// RadioGroup2Click



__fastcall TAutoDiplomForm::TAutoDiplomForm (TComponent* Owner) : TForm (Owner) {
}

void __fastcall TAutoDiplomForm::FormClose (TObject *Sender,
    TCloseAction &Action) {
    Action = caFree;

    DM3 -> Count_VipuskFDQuery -> Close ();
    DM3 -> MaxRegFDQuery -> Close ();
    DataModule1 -> DiplomREGFDQuery -> Close ();
    DM3 -> DiplomREG_estFDQuery -> Close ();
}

void __fastcall TAutoDiplomForm::RadioGroup1Click (TObject *Sender) {
    Label11 -> Visible = false;

    reg = ""; // ��������������� �����
    // ������   0810/001       08-��� �������,  1 (1.2.0.4) ���������, 0 (0.1) ��� ��������
    reg = AnsiString (uch_god + 1).SubString (3, 2);
    if (nom_fac != 3)
        reg += AnsiString (nom_fac);
    else
        reg += "0"; // ��������� �����
    reg += AnsiString (RadioGroup1 -> ItemIndex);
    reg += "/";

    QOpen (4); // 4 ���� - �/�
    MaxReg (4); // ������������ ���.�����
    // ------

    Label9 -> Caption = reg + "001"; // ������ ���������������� ������:

    if (DM3 -> MaxRegFDQueryMAX -> Value != "") {
        n_reg = DM3 -> MaxRegFDQueryMAX -> Value.SubString (6, 3).ToInt ();
        AnsiString new_nom1 = "";
        n_reg++;
        switch (IntToStr (n_reg).Length ()) {
        case 1:
            new_nom1 = "00" + IntToStr (n_reg);
            break;
        case 2:
            new_nom1 = "0" + IntToStr (n_reg);
            break;
        case 3:
            new_nom1 = IntToStr (n_reg);
            break;
        }
        Label10 -> Caption = reg + new_nom1; // ��������� �������� � ������:
    }
    else {
        Label10 -> Caption = Label9 -> Caption; // ��������� �������� � ������:
        n_reg++;
    }
    Panel2 -> Visible = true;
}

void __fastcall TAutoDiplomForm::QOpen (int kurs) {
    // -----���������� ��������� �� ��������� �����
    DM3 -> Count_VipuskFDQuery -> Close ();
    DM3 -> Count_VipuskFDQuery -> ParamByName ("N_FAC") -> AsSmallInt = nom_fac;
    DM3 -> Count_VipuskFDQuery -> ParamByName ("EDU") -> AsSmallInt =
        RadioGroup1 -> ItemIndex;
    DM3 -> Count_VipuskFDQuery -> ParamByName ("KURS") -> AsSmallInt =
        RadioGroup1 -> ItemIndex + kurs;
    DM3 -> Count_VipuskFDQuery -> Open ();
    // -----
    // ������������ ����������� ���.����� (�������� 1240/002)
    /* DM3 -> MaxRegQuery -> Close ();
     DM3 -> MaxRegQuery -> ParamByName ("N_FAC") -> AsSmallInt=nom_fac;
     DM3 -> MaxRegQuery -> ParamByName ("EDU") -> AsSmallInt=RadioGroup1 -> ItemIndex;
     DM3 -> MaxRegQuery -> ParamByName ("KURS") -> AsSmallInt=RadioGroup1 -> ItemIndex+kurs;
     DM3 -> MaxRegQuery -> ParamByName ("GOD") -> AsString=par_god;
     DM3 -> MaxRegQuery -> Open (); */

    // ---DiplomREGQuery
    DataModule1 -> DiplomREGFDQuery -> Close ();
    DataModule1 -> DiplomREGFDQuery -> ParamByName ("N_FAC") -> AsSmallInt = nom_fac;
    DataModule1 -> DiplomREGFDQuery -> ParamByName ("EDU") -> AsSmallInt =
        RadioGroup1 -> ItemIndex;
    DataModule1 -> DiplomREGFDQuery -> ParamByName ("KURS") -> AsSmallInt =
        RadioGroup1 -> ItemIndex + kurs;
    DataModule1 -> DiplomREGFDQuery -> ParamByName ("GOD") -> AsString = par_god;
    DataModule1 -> DiplomREGFDQuery -> Open ();
    DataModule1 -> DiplomREG_countFDQuery -> Close ();
    DataModule1 -> DiplomREG_countFDQuery -> ParamByName ("N_FAC") -> AsSmallInt =
        nom_fac;
    DataModule1 -> DiplomREG_countFDQuery -> ParamByName ("EDU") -> AsSmallInt =
        RadioGroup1 -> ItemIndex;
    DataModule1 -> DiplomREG_countFDQuery -> ParamByName ("KURS") -> AsSmallInt =
        RadioGroup1 -> ItemIndex + kurs;
    DataModule1 -> DiplomREG_countFDQuery -> ParamByName ("GOD") -> AsString = par_god;
    DataModule1 -> DiplomREG_countFDQuery -> Open ();

    // ----DiplomREG_estQuery
    DM3 -> DiplomREG_estFDQuery -> Close ();
    DM3 -> DiplomREG_estFDQuery -> ParamByName ("N_FAC") -> AsSmallInt = nom_fac;
    DM3 -> DiplomREG_estFDQuery -> ParamByName ("EDU") -> AsSmallInt =
        RadioGroup1 -> ItemIndex;
    DM3 -> DiplomREG_estFDQuery -> ParamByName ("KURS") -> AsSmallInt =
        RadioGroup1 -> ItemIndex + kurs;
    DM3 -> DiplomREG_estFDQuery -> ParamByName ("GOD") -> AsString = par_god;
    DM3 -> DiplomREG_estFDQuery -> Open ();

    Label2 -> Caption = AnsiString (DM3 -> Count_VipuskFDQueryCOUNT -> Value);
    // ���������� ��������� �� ��������� �����:
    Label4 -> Caption = AnsiString (DM3 -> DiplomREG_estFDQuery -> RecordCount);
    // ���������� �������� � ��������������� �������:
    Label6 -> Caption =
        AnsiString (DataModule1 -> DiplomREG_countFDQueryCOUNT -> Value);
    // ���������� �������� ��� ���������������� ������:

}

void __fastcall TAutoDiplomForm::MaxReg (int kurs) {
    // ������������ ����������� ���.����� (�������� 1240/002)
    DM3 -> MaxRegFDQuery -> Close ();
    DM3 -> MaxRegFDQuery -> ParamByName ("N_FAC") -> AsSmallInt = nom_fac;
    DM3 -> MaxRegFDQuery -> ParamByName ("EDU") -> AsSmallInt = RadioGroup1 -> ItemIndex;
    DM3 -> MaxRegFDQuery -> ParamByName ("KURS") -> AsSmallInt =
        RadioGroup1 -> ItemIndex + kurs;
    DM3 -> MaxRegFDQuery -> ParamByName ("GOD") -> AsString = par_god;
    DM3 -> MaxRegFDQuery -> Open ();
}

void __fastcall TAutoDiplomForm::RadioGroup2Click (TObject *Sender) {
    Label11 -> Visible = false;
    n_reg = 0;
    reg = ""; // ��������������� �����
    // ������   0810/001       08-��� �������,  1 (1.2.0.4) ���������, 0 (0.1) ��� ��������
    reg = AnsiString (uch_god + 1).SubString (3, 2);
    if (nom_fac != 3)
        reg += AnsiString (nom_fac);
    else
        reg += "0"; // ��������� �����
    reg += AnsiString (RadioGroup1 -> ItemIndex);
    reg += "/";

    Label9 -> Caption = reg + "001"; // ������ ���������������� ������:

    if (RadioGroup2 -> ItemIndex) { // if ��������
        QOpen (4); // 5 - ���� - �������

        MaxReg (5); // ������������ ���.����� 6 �����
        if (DM3 -> MaxRegFDQueryMAX -> Value != "")
            reg_6 = DM3 -> MaxRegFDQueryMAX -> Value.SubString (6, 3).ToInt ();

        MaxReg (4); // ������������ ���.����� 5 �����
        if (DM3 -> MaxRegFDQueryMAX -> Value != "")
            reg_5 = DM3 -> MaxRegFDQueryMAX -> Value.SubString (6, 3).ToInt ();

        if (!reg_6) { // if � 6-�� ����� ��� ���.�������
            ShowMessage ("������� ������������ ������ ��� ������������!");
            RadioGroup1 -> ItemIndex = -1;
            RadioGroup2 -> ItemIndex = -1;
            RadioGroup2 -> Visible = false;
            Panel2 -> Visible = false;
            return;
        } // end if � 6-�� ����� ��� ���.�������

        if (!reg_5)
            n_reg = reg_6; // if ���.������ ���  (5 ����)

        if (reg_6 != 0 && reg_5 != 0)
        { // if ���� � � 5-�� � � 6-�� ����� - ����� ������������
            if (reg_6 > reg_5)
                n_reg = reg_6;
            else
                n_reg = reg_5;
        } // end if ���� � � 5-�� � � 6-�� ����� - ����� ������������

    } // and if ��������
    else { // else ����������
        QOpen (5); // 6 - ���� - �������

        MaxReg (4); // ������������ ���.����� 5 �����
        if (DM3 -> MaxRegFDQueryMAX -> Value != "")
            reg_5 = DM3 -> MaxRegFDQueryMAX -> Value.SubString (6, 3).ToInt ();

        MaxReg (5); // ������������ ���.����� 6 �����
        if (DM3 -> MaxRegFDQueryMAX -> Value != "")
            reg_6 = DM3 -> MaxRegFDQueryMAX -> Value.SubString (6, 3).ToInt ();

        if (reg_6)
            n_reg = reg_6;
    } // end else ����������

    if (n_reg) { // if n_reg
        AnsiString new_nom1 = "";
        n_reg++;
        switch (IntToStr (n_reg).Length ()) {
        case 1:
            new_nom1 = "00" + IntToStr (n_reg);
            break;
        case 2:
            new_nom1 = "0" + IntToStr (n_reg);
            break;
        case 3:
            new_nom1 = IntToStr (n_reg);
            break;
        }
        Label10 -> Caption = reg + new_nom1; // ��������� �������� � ������:
    } // end if n_reg
    else { // else
        Label10 -> Caption = Label9 -> Caption; // ��������� �������� � ������:
        n_reg++;
    } // end else
    Panel2 -> Visible = true;
}

void __fastcall TAutoDiplomForm::BitBtn1Click (TObject *Sender)
{ // ������������� �����
    // ---��������
    if (!DataModule1 -> DiplomREG_countFDQueryCOUNT -> Value) {
        ShowMessage ("��� �����������, � ������� ����� ������������ �����!");
        return;
    }

    // if (reg_5 && !RadioGroup2 -> ItemIndex)
    // {
    // ShowMessage ("�� ��� �� ������ ������������ ������ ��� ������������! ���������� � ������������!");
    // return;
    // }
    // --------
    AnsiString new_n_reg = "";
    for (int i = 0; i < DataModule1 -> DiplomREG_countFDQueryCOUNT -> Value; i++)
    { // for ���� �� ���������
        switch (IntToStr (n_reg).Length ()) {
        case 1:
            new_n_reg = "00" + IntToStr (n_reg);
            break;
        case 2:
            new_n_reg = "0" + IntToStr (n_reg);
            break;
        case 3:
            new_n_reg = IntToStr (n_reg);
            break;
        }
        DataModule1 -> DiplomREGFDQuery -> Edit ();
        DataModule1 -> DiplomREGFDQueryREGISTRATION -> Value = reg + new_n_reg;
        DataModule1 -> DiplomREGFDQuery -> Post ();
        DataModule1 -> DiplomREGFDQuery -> Next ();
        n_reg++;
    } // end for ���� �� ���������
    DataModule1 -> DiplomREGFDQuery -> ApplyUpdates ();
    DataModule1 -> DiplomREGFDQuery -> CommitUpdates ();

    Label11 -> Caption = "��������� ��������������� �����: " + reg + new_n_reg;
    Label11 -> Visible = true;
}

void __fastcall TAutoDiplomForm::BitBtn2Click (TObject *Sender)
{ // �������� � Excel

    tab1[1] = 0x0A; // Alt+Enter
    str_rr = 1; // ����� ������

    int str_otl = 1; // ����� ������ ��� �������� � ��������

    // !!!if (Application -> MessageBox ("������ ����������� ���� - ������� Yes,\n������ ���, ������� ������ ������������� ����� - ������� No?", "", MB_YESNO) == mrYes)
    if (MessageDlg
        ("������ ����������� ���� - ������� Yes,\n������ ���, ������� ������ ������������� ����� - ������� No?",
        mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
    { // if ��� ������� �����������
        qd = DM3 -> DiplomREG_estFDQuery;
        qd -> Close ();
        qd -> ParamByName ("N_FAC") -> AsSmallInt = nom_fac;
        qd -> ParamByName ("EDU") -> AsSmallInt = RadioGroup1 -> ItemIndex;
        qd -> ParamByName ("KURS") -> AsSmallInt = RadioGroup1 -> ItemIndex + 4;
        qd -> ParamByName ("GOD") -> AsString = par_god;
        qd -> Open ();
    }
    else { // else ������ ��, ������� ������ ���� �����
        qd = DataModule1 -> DiplomREGExcelFDQuery;
        qd -> Close ();
        qd -> ParamByName ("N_FAC") -> AsSmallInt = nom_fac;
        qd -> ParamByName ("EDU") -> AsSmallInt = RadioGroup1 -> ItemIndex;
        qd -> ParamByName ("KURS") -> AsSmallInt = RadioGroup1 -> ItemIndex + 4;
        qd -> ParamByName ("GOD") -> AsString = AnsiString (uch_god);
        qd -> Open ();
        qd -> First ();
    }

    if (qd -> RecordCount == 0) { // ��� �����
        ShowMessage ("��� ������ ��� �������� � Excel!");
        return;
    }

    // ���������  Exel
    DataModule1 -> ExelInit ();
    // ������ ���������� ������ � �����
    App_n.OlePropertySet ("SheetsInNewWorkbook", 1);

    // �����
    Diplom_Shapka (false); // ������� ��� �������
    if (CheckBox1 -> Checked)
        Diplom_Shapka (true); // ������� c ��������

    str_rr++;
    str_rr++;
    str_otl = str_rr;

    for (int i = 0; i < qd -> RecordCount; i++) {

        if ( (qd -> FieldByName ("TYPE_DIPLOM") -> Value == 2 || qd -> FieldByName
            ("TYPE_DIPLOM") -> Value == 6 || qd -> FieldByName ("TYPE_DIPLOM")
            -> Value == 12) && (CheckBox1 -> Checked))
        { // if ������ � �������� 2 ��� ������ ����������� � �������� 6 � �������� ����� � ��������� ������
            Diplom_text (str_otl, true);
            str_otl++;
        }
        else { // else ��� ��������� ������� � ���� ������ ��� ����
            Diplom_text (str_rr, false);
            str_rr++;
        }
        qd -> Next ();
    }

    // ����������, ����� ���������� ��� �� ������� ��
    AnsiString dec_f = "", met_f = "";
    int v_edu = DM3 -> DiplomREG_estFDQueryVID_EDU -> Value;
    switch (nom_fac) { // switch ����� ����������
    case 1:
        dec_f = "�.�.��������";
        if (v_edu == 1)
            met_f = "�.�.��������";
        else
            met_f = "�.�.���������";
        break;
    case 2:
        dec_f = "�.�.����������";
        if (v_edu == 1)
            met_f = "�.�.��������";
        else
            met_f = "�.�.�����";
        break;
    case 3:
        dec_f = "�.�.���������";
        if (v_edu == 1)
            met_f = "�.�.��������";
        else
            met_f = "�.�. ���������";
        break;
    case 4:
        dec_f = "�.�.���������";
        if (v_edu == 1)
            met_f = "�.�.���������";
        else
            met_f = "�.�.�������";
        break;
    }

    str_rr++;
    str_rr++;
    str_rr++;
    // �������
    Cell_2_Text_Ole2 (1, 3, str_rr, false, "Arial", 12, false, 0, 2, 0, true,
        true, "������������ ���������� ����������� ");
    Cell_2_Text_Ole2 (5, 6, str_rr, false, "Arial", 12, false, 0, 2, 0, true,
        true, "�.�.������");
    str_rr++;
    str_rr++;
    str_rr++;
    Cell_2_Text_Ole2 (1, 2, str_rr, false, "Arial", 12, false, 0, 2, 0, true,
        true, "������������ ���");
    Cell_2_Text_Ole2 (5, 6, str_rr, false, "Arial", 12, false, 0, 2, 0, true,
        true, "");
    str_rr++;
    str_rr++;
    str_rr++;
    Cell_2_Text_Ole2 (1, 2, str_rr, false, "Arial", 12, false, 0, 2, 0, true,
        true, "����� ����������");
    Cell_2_Text_Ole2 (5, 6, str_rr, false, "Arial", 12, false, 0, 2, 0, true,
        true, dec_f);
    str_rr++;
    str_rr++;
    str_rr++;
    Cell_2_Text_Ole2 (1, 2, str_rr, false, "Arial", 12, false, 0, 2, 0, true,
        true, "��������� ����������");
    Cell_2_Text_Ole2 (5, 6, str_rr, false, "Arial", 12, false, 0, 2, 0, true,
        true, met_f);

    Diplom_Titul (false); // ������� ��� �������

    if (CheckBox1 -> Checked)
        Diplom_Titul (true); // ������� c ��������

    // ���������� ����� Excel
    App_n.OlePropertySet ("Visible", true);

    App_n.Clear ();
    Sh.Clear ();

}

void __fastcall TAutoDiplomForm::Diplom_text (int str, bool otl)
{ // ����� �� ������� �������

    AnsiString name = "�������";
    if (otl)
        name = "������� � ��������";

    // �������� ����
    Sh = App_n.OlePropertyGet ("WorkSheets", WideString (name));

    // ������� ��� ��������
    Sh.OleProcedure ("Activate");

    // ������ ������
    Variant dd = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", str, str);
    dd.OlePropertySet ("RowHeight", 75);

    // ��������������� �����
    Cell_2_Text_Ole2 (1, 1, str, true, "Arial", 12, false, 3, 2, 0, false, true,
        qd -> FieldByName ("REGISTRATION") -> Value);
    // ���
    Cell_2_Text_Ole2 (2, 2, str, true, "Arial", 12, false, 2, 2, 0, false, true,
        qd -> FieldByName ("FAM") -> Value + tab1 + qd -> FieldByName ("NAME") -> Value +
        tab1 + qd -> FieldByName ("OTCH") -> Value + tab1 + qd -> FieldByName
        ("N_ZACHET") -> Value);
    Border_IndentLeft (2, 2, str, str, false, 0, 1); // ������ ����� �� 1 �������

    // ���������
    Cell_2_Text_Ole2 (3, 3, str, true, "Arial", 12, false, 3, 2, 0, false, true,
        Grid_V (qd, "N_FAC"));
    // ������������� + ������������
    // Cell_2_Text_Ole2 (4,4,str,true,"Arial",12,false,2,2,0,false,true,Grid_V (qd,"N_SPEC")+tab1+Grid_V (qd,"N_SPECIALIZ"));
    Cell_2_Text_Ole2 (4, 4, str, true, "Arial", 12, false, 2, 2, 0, false, true,
        Grid_V (qd, "N_SPECIALIZ") + tab1 + Grid_V (qd, "QUALIFICATION"));
    Border_IndentLeft (4, 4, str, str, false, 0, 1); // ������ ����� �� 1 �������

    // ���� ����������� �� �������� (���� �� ������� �� ����������)
    // Cell_2_Text_Ole2 (5,5,str,true,"Arial",12,false,3,2,0,false,true,Grid_V (qd,"D_PRIKAZ_INCLUDE"));
    // ��� ����������� �� �������� (���� �� ������� �� ����������)
    String data_str1 = Grid_V (qd, "D_PRIKAZ_INCLUDE");
    int data_lng = data_str1.Length ();
    String data_str2 = data_str1.SubString (data_lng - 3, 4);
    Cell_2_Text_Ole2 (5, 5, str, true, "Arial", 12, false, 3, 2, 0, false, true,
        data_str2);

    // ���� ��������� ��������
    // Cell_2_Text_Ole2 (6,6,str,true,"Arial",12,false,3,2,0,false,true,qd -> FieldByName ("D_PRIKAZ_KURS") -> Value);
    TDateTime date1 = qd -> FieldByName ("D_PRIKAZ_KURS") -> Value;
    unsigned short year1, month1, day1;
    date1.DecodeDate (&year1, &month1, &day1);
    Cell_2_Text_Ole2 (6, 6, str, true, "Arial", 12, false, 3, 2, 0, false,
        true, year1);

    // ���� � ����� ������� �� ��������� ��������
    // Cell_2_Text_Ole2 (7,7,str,true,"Arial",12,false,3,2,0,false,true,"� "+qd -> FieldByName ("N_PUBLIC_PRIKAZ") -> Value+tab1+" �� "+Grid_V (qd,"D_PUBLIC_PRIKAZ"));
    Cell_2_Text_Ole2 (7, 7, str, true, "Arial", 12, false, 3, 2, 0, false, true,
        Grid_V (qd, "D_PUBLIC_PRIKAZ") + tab1 + "� " + qd -> FieldByName
        ("N_PUBLIC_PRIKAZ") -> Value);

    // ������������ ���� ������� �� ����
    // Cell_2_Text_Ole2 (6,6,str_r,true,"Arial",12,false,2,2,0,false,true,Grid_V (q,"QUALIFICATION"));

    // ���� � ����� ���������
    // Cell_2_Text_Ole2 (8,8,str,true,"Arial",12,false,3,2,0,false,true,"� "+qd -> FieldByName ("N_PROTOKOL") -> Value+tab1+" �� "+qd -> FieldByName ("D_PROTOKOL") -> Value);
    Cell_2_Text_Ole2 (8, 8, str, true, "Arial", 12, false, 3, 2, 0, false, true,
        "" + qd -> FieldByName ("D_PROTOKOL") -> Value + tab1 + "� " +
        qd -> FieldByName ("N_PROTOKOL") -> Value);

    // ����� �������
    AnsiString dip = "";
    if (qd -> FieldByName ("TYPE_DIPLOM") -> Value == 2 || qd -> FieldByName
        ("TYPE_DIPLOM") -> Value == 6)
        dip = "� ��������" + tab1;
    dip += qd -> FieldByName ("SERIA") -> Value;
    dip += " � " + qd -> FieldByName ("NOM_DIPLOM") -> Value;
    Cell_2_Text_Ole2 (9, 9, str, true, "Arial", 12, false, 3, 2, 0, false,
        true, dip);

    // ���� ������ �������
    Cell_2_Text_Ole2 (10, 10, str, true, "Arial", 12, false, 3, 2, 0, false,
        true, qd -> FieldByName ("D_VIPUSK") -> Value);

    // ���������� ������ ����, ����������� ������
    /* AnsiString pasp=Grid_V (qd,"PASPORT");
     if (pasp!="") pasp+=tab1;
     pasp+=Grid_V (qd,"PERSONAL_NOMER"); */
    // Cell_2_Text_Ole2 (11,11,str,true,"Arial",12,false,3,2,0,false,true,pasp+tab1+""+tab1+"");

    // �� ������� PERSONAL_DOCUM
    AnsiString pasp = Grid_V (qd, "SERIES") + " ";
    pasp += Grid_V (qd, "NUMBER") + tab1;
    pasp += Grid_V (qd, "PERSONAL_NUMBER") + " ����� ";
    pasp += Grid_V (qd, "WHO_GIVE") + tab1;
    pasp += Grid_V (qd, "DATE_GIVE").SubString(0, 10);
    Cell_2_Text_Ole2 (11, 11, str, true, "Arial", 12, false, 3, 2, 0, false,
        true, pasp);

    // �������� � ������� �� ����� ��� ������ �� ������������ (����� � ����)
    Cell_2_Text_Ole2 (12, 12, str, true, "Arial", 12, false, 0, 2, 0, false,
        true, "");

    // ������� ����, ����������� ������
    Cell_2_Text_Ole2 (13, 13, str, true, "Arial", 12, false, 0, 2, 0, false,
        true, "");
}

void __fastcall TAutoDiplomForm::Diplom_Shapka (bool otl) { // ����� ��������

    // ���������  ����
    App_n.OlePropertyGet ("WorkSheets").OleProcedure ("add");
    Sh = App_n.OlePropertyGet ("WorkSheets").OlePropertyGet ("Item", 1);

    AnsiString name = "�������";
    if (otl)
        name = "������� � ��������";

    Sh.OlePropertySet ("Name", WideString (name));
    Sh = App_n.OlePropertyGet ("ActiveSheet");

    // ������ �������������� ������������ ��������
    Sh.OlePropertyGet ("PageSetup").OlePropertySet ("Orientation", 2);
    Sh.OlePropertyGet ("PageSetup").OlePropertySet ("CenterHorizontally", true);
    Sh.OlePropertyGet ("PageSetup").OlePropertySet ("Zoom", false);
    Sh.OlePropertyGet ("PageSetup").OlePropertySet ("FitToPagesWide", 1);
    Sh.OlePropertyGet ("PageSetup").OlePropertySet ("FitToPagesTall", 100);

    // ���� ������� � ������
    Sh.OlePropertyGet ("PageSetup").OlePropertySet ("TopMargin", 36);
    Sh.OlePropertyGet ("PageSetup").OlePropertySet ("BottomMargin", 30);

    // ���� ����� � ������
    Sh.OlePropertyGet ("PageSetup").OlePropertySet ("LeftMargin", 58);
    Sh.OlePropertyGet ("PageSetup").OlePropertySet ("RightMargin", 10);

    Variant d; // ������ �������
    int stb = 1; // ����� �������

    // ������ ������
    // d=Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item",1,1);d.OlePropertySet ("RowHeight",82);
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 1, 1);
    d.OlePropertySet ("RowHeight", 93);
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 2, 2);
    d.OlePropertySet ("RowHeight", 15);

    // �����
    Cell_2_Text_Ole2 (stb, stb, str_rr, true, "Times New Roman CYR", 12, false,
        3, 2, 0, false, true,
        "��������-������� ����� ��������� �� �����������");
    Cell_2_Text_Ole2 (stb, stb, str_rr + 1, true, "Arial", 12, false, 3, 2, 0,
        false, true, stb);
    // d=Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item",stb,stb);d.OlePropertySet ("ColumnWidth",11);
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", stb, stb);
    d.OlePropertySet ("ColumnWidth", 13);
    stb++;

    // Cell_2_Text_Ole2 (stb,stb,str_rr,true,"Times New Roman CYR",12,false,3,2,0,false,true,"�������, ���, �������� ����������");
    Cell_2_Text_Ole2 (stb, stb, str_rr, true, "Times New Roman CYR", 12, false,
        3, 2, 0, false, true,
        "�������, ����������� ���, ��������, ����������������� ����� ������������");
    Cell_2_Text_Ole2 (stb, stb, str_rr + 1, true, "Arial", 12, false, 3, 2, 0,
        false, false, stb);
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", stb, stb);
    d.OlePropertySet ("ColumnWidth", 26);
    stb++;

    Cell_2_Text_Ole2 (stb, stb, str_rr, true, "Times New Roman CYR", 12, false,
        3, 2, 0, false, true, "���������");
    Cell_2_Text_Ole2 (stb, stb, str_rr + 1, true, "Arial", 12, false, 3, 2, 0,
        false, true, stb);
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", stb, stb);
    d.OlePropertySet ("ColumnWidth", 11);
    stb++;

    Cell_2_Text_Ole2 (stb, stb, str_rr, true, "Times New Roman CYR", 12, false,
        3, 2, 0, false, true,
        "������������� (����������� �������������), ������������");
    Cell_2_Text_Ole2 (stb, stb, str_rr + 1, true, "Arial", 12, false, 3, 2, 0,
        false, true, stb);
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", stb, stb);
    d.OlePropertySet ("ColumnWidth", 60);
    stb++;

    Cell_2_Text_Ole2 (stb, stb, str_rr, true, "Times New Roman CYR", 12, false,
        3, 2, 0, false, true, "��� ����������� ��� ��������� �����������");
    Cell_2_Text_Ole2 (stb, stb, str_rr + 1, true, "Arial", 12, false, 3, 2, 0,
        false, false, stb);
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", stb, stb);
    d.OlePropertySet ("ColumnWidth", 13);
    stb++;

    Cell_2_Text_Ole2 (stb, stb, str_rr, true, "Times New Roman CYR", 12, false,
        3, 2, 0, false, true, "��� ��������� ��������");
    Cell_2_Text_Ole2 (stb, stb, str_rr + 1, true, "Arial", 12, false, 3, 2, 0,
        false, false, stb);
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", stb, stb);
    d.OlePropertySet ("ColumnWidth", 12);
    stb++;

    Cell_2_Text_Ole2 (stb, stb, str_rr, true, "Times New Roman CYR", 12, false,
        3, 2, 0, false, true, "���� � ����� ������� �� ��������� ��������");
    Cell_2_Text_Ole2 (stb, stb, str_rr + 1, true, "Arial", 12, false, 3, 2, 0,
        false, false, stb);
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", stb, stb);
    d.OlePropertySet ("ColumnWidth", 16);
    stb++;

    // Cell_2_Text_Ole2 (7,7,str_r,true,"Times New Roman CYR",12,false,3,2,0,false,true,"��������� ������������");
    // Cell_2_Text_Ole2 (7,7,str_r+1,true,"Arial",12,false,3,2,0,false,false,"6");

    Cell_2_Text_Ole2 (stb, stb, str_rr, true, "Times New Roman CYR", 12, false,
        3, 2, 0, false, true,
        "���� � ����� ��������� ��������� ��������������� ��������������� ��������");
    Cell_2_Text_Ole2 (stb, stb, str_rr + 1, true, "Arial", 12, false, 3, 2, 0,
        false, false, stb);
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", stb, stb);
    d.OlePropertySet ("ColumnWidth", 21);
    stb++;

    Cell_2_Text_Ole2 (stb, stb, str_rr, true, "Times New Roman CYR", 12, false,
        3, 2, 0, false, true, "����� � ����� ������ ��������� �� �����������");
    Cell_2_Text_Ole2 (stb, stb, str_rr + 1, true, "Arial", 12, false, 3, 2, 0,
        false, false, stb);
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", stb, stb);
    d.OlePropertySet ("ColumnWidth", 18);
    stb++;

    Cell_2_Text_Ole2 (stb, stb, str_rr, true, "Times New Roman CYR", 12, false,
        3, 2, 0, false, true, "���� ������ ��������� �� �����������");
    Cell_2_Text_Ole2 (stb, stb, str_rr + 1, true, "Arial", 12, false, 3, 2, 0,
        false, false, stb);
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", stb, stb);
    d.OlePropertySet ("ColumnWidth", 13);
    stb++;

    Cell_2_Text_Ole2 (stb, stb, str_rr, true, "Times New Roman CYR", 12, false,
        3, 2, 0, false, true, "������ ���������, ��������������� ��������");
    Cell_2_Text_Ole2 (stb, stb, str_rr + 1, true, "Arial", 12, false, 3, 2, 0,
        false, false, stb);
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", stb, stb);
    d.OlePropertySet ("ColumnWidth", 25);
    stb++;

    Cell_2_Text_Ole2 (stb, stb, str_rr, true, "Times New Roman CYR", 12, false,
        3, 2, 0, false, true,
        "�������� � ������� �� ����� ��� ������ �� ������������");
    Cell_2_Text_Ole2 (stb, stb, str_rr + 1, true, "Arial", 12, false, 3, 2, 0,
        false, false, stb);
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", stb, stb);
    d.OlePropertySet ("ColumnWidth", 19);
    stb++;

    Cell_2_Text_Ole2 (stb, stb, str_rr, true, "Times New Roman CYR", 12, false,
        3, 2, 0, false, true,
        "������� ����, ����������� �������� �� �����������");
    Cell_2_Text_Ole2 (stb, stb, str_rr + 1, true, "Arial", 12, false, 3, 2, 0,
        false, false, stb);
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", stb, stb);
    d.OlePropertySet ("ColumnWidth", 19);
    stb++;

    // ���������� �������� ������
    AnsiString temp_text = "$" + AnsiString (str_rr) + ":$" +
        AnsiString (str_rr + 1);
    Sh.OlePropertyGet ("PageSetup").OlePropertySet ("PrintTitleRows",
        WideString (temp_text));
}

void __fastcall TAutoDiplomForm::Diplom_Titul (bool otl)
{ // ��������� ���� ��������
    // bool otl ������� � �������� - true, ��� ������� - false

    // ��������� �� ������ ���� � �����, ��� �� �� ���� ������� ��� ����������
    Sh = App_n.OlePropertyGet ("WorkSheets", 1);
    Sh.OleProcedure ("Select");

    // ��������� ��������� ����
    App_n.OlePropertyGet ("WorkSheets").OleProcedure ("add");
    Sh = App_n.OlePropertyGet ("WorkSheets").OlePropertyGet ("Item", 1);

    AnsiString name = "����� �������";
    if (otl)
        name = "����� ������� � ��������";

    // ��������������� ���� � ������ ��� ��������
    Sh.OlePropertySet ("Name", WideString (name));
    Sh = App_n.OlePropertyGet ("ActiveSheet");

    // ������ �������������� ������������ ��������
    Sh.OlePropertyGet ("PageSetup").OlePropertySet ("Orientation", 2);
    Sh.OlePropertyGet ("PageSetup").OlePropertySet ("CenterHorizontally", true);
    Sh.OlePropertyGet ("PageSetup").OlePropertySet ("Zoom", false);
    Sh.OlePropertyGet ("PageSetup").OlePropertySet ("FitToPagesWide", 1);
    Sh.OlePropertyGet ("PageSetup").OlePropertySet ("FitToPagesTall", 1);

    // ���� ������� � ������
    Sh.OlePropertyGet ("PageSetup").OlePropertySet ("TopMargin", 36);
    Sh.OlePropertyGet ("PageSetup").OlePropertySet ("BottomMargin", 30);
    // ���� ����� � ������
    Sh.OlePropertyGet ("PageSetup").OlePropertySet ("LeftMargin", 58);
    Sh.OlePropertyGet ("PageSetup").OlePropertySet ("RightMargin", 10);

    Variant d;
    // ������ ������
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 1, 1);
    d.OlePropertySet ("RowHeight", 20);
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 2, 2);
    d.OlePropertySet ("RowHeight", 20);
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 3, 3);
    d.OlePropertySet ("RowHeight", 20);
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 4, 4);
    d.OlePropertySet ("RowHeight", 20);
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 5, 5);
    d.OlePropertySet ("RowHeight", 20);

    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 6, 6);
    d.OlePropertySet ("RowHeight", 47);
    Cell_2_Text_Ole2 (1, 15, 6, false, "Times New Roman CYR", 16, true, 3, 3, 0,
        true, false, "������������ ������ � ������� ���������� ��������");
    // Border_IndentLeft (1,15,6,6, false, 4, 0);//���������� ������ �� ����

    // d=Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item",7,7);d.OlePropertySet ("RowHeight",16);
    // Cell_2_Text_Ole2 (1,15,7,false,"Times New Roman CYR",12,false,3,0,0,true,false,"������������ (���������)");

    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 7, 7);
    d.OlePropertySet ("RowHeight", 30);
    Cell_2_Text_Ole2 (1, 15, 7, false, "Times New Roman CYR", 16, true, 3, 3, 0,
        true, false,
        "���������� ����������� \"����������� ��������������� ����������� ���������� ��������\"");
    // Border_IndentLeft (1,15,8,8, false, 4, 0);//���������� ������ �� ����

    DataModule1 -> FacFullFDQ -> Close ();
    DataModule1 -> FacFullFDQ -> ParamByName ("nom_fac") -> AsSmallInt = nom_fac;
    DataModule1 -> FacFullFDQ -> Open ();
    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 8, 8);
    d.OlePropertySet ("RowHeight", 30);
    Cell_2_Text_Ole2 (1, 15, 8, false, "Times New Roman CYR", 16, true, 3, 3, 0,
        true, false, DataModule1 -> FacFullFDQFAC -> AsString);
    DataModule1 -> FacFullFDQ -> Close ();

    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 9, 9);
    d.OlePropertySet ("RowHeight", 68);
    Cell_2_Text_Ole2 (1, 15, 9, false, "Times New Roman CYR", 20, true, 3, 0, 0,
        true, false, "�����");

    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 10, 10);
    d.OlePropertySet ("RowHeight", 26);
    if (otl)
        Cell_2_Text_Ole2 (1, 15, 10, false, "Times New Roman CYR", 20, true, 3,
        0, 0, true, false,
        "����� � ������ ���������� �� ����������� � ��������");
    else
        Cell_2_Text_Ole2 (1, 15, 10, false, "Times New Roman CYR", 20, true, 3,
        0, 0, true, false, "����� � ������ ���������� �� �����������");

    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 11, 11);
    d.OlePropertySet ("RowHeight", 185);

    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 12, 12);
    d.OlePropertySet ("RowHeight", 20);
    Cell_2_Text_Ole2 (11, 11, 12, false, "Times New Roman CYR", 12, false, 0, 0,
        0, false, false, "�����");
    Cell_2_Text_Ole2 (12, 12, 12, false, "Times New Roman CYR", 12, false, 0, 0,
        0, false, false, "\"_____\" _____________ 20____ �.");

    d = Sh.OlePropertyGet ("Cells").OlePropertyGet ("Item", 13, 13);
    d.OlePropertySet ("RowHeight", 20);
    Cell_2_Text_Ole2 (11, 11, 13, false, "Times New Roman CYR", 12, false, 0, 0,
        0, false, false, "�������");
    Cell_2_Text_Ole2 (12, 12, 13, false, "Times New Roman CYR", 12, false, 0, 0,
        0, false, false, "\"_____\" _____________ 20____ �.");

}

void __fastcall TAutoDiplomForm::FormCreate (TObject *Sender) {
    par_god = "%" + AnsiString (uch_god + 1) + "%";
}

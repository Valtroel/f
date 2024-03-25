#include <vcl.h>
#pragma hdrstop


#include "DataModule_Card.h"
#include "DataModule.h"
#include "DM2Unit.h"
#include "DM4Unit.h"
#include "DualList.h"
#include "Func.h"
#include "InfoUnit.h"


#pragma package (smart_init)
// #pragma link     "MyList"
#pragma resource "*.dfm"


TInfoForm * InfoForm;


AnsiString     * mas_nomer_zach[2];                                             // ������ ������� ��������� � ���, � ��, � NOMER ��� �������

AnsiString       god_two;                                                       // ���������� ���� ��������� ���� ����

bool             mas_ch      = false,                                           // ���������� ��� ����������� ������ ������ ��� ���// false - ������� ���// true - ������ ���� �������
                 mas_none    = false,                                           // ���������� ���� ��� ��������������� �������, �� ����� ������ ������ � Excel// false - ���������� �������// true - ������� �� ����������
                 n_r,                                                           // ��������� ��� ����������� ������
                 up_stud     = false,
                 well        = false;

int              incr_gr,                                                       // ��������� ������
                 nomer_st,
                 record_zach,                                                   // ���������� �������, �� ������� ������ �������
                 year_add    = 0,
                 zach        = 0;                                               // 0 - 01.09+��� �����������; 1 - ������ ����

String           year_uch;

TDateTime        ggg,
                 yyy;

TLocateOptions   Flags;

Variant          ExPril,
                 PrilBook,                                                      // ���������� ��� Excel WBook � WSheet
                 PrilSheet;                                                     // ���������� ��� Excel WBook � WSheet





// BitBtn1Click
// BitBtn2Click
// BitBtn3Click
// Create_Shapka
// Create_Spisok_Zachetka
// del_mas
// FormClose
// FormCreate
// MaskEdit1Exit
// MaskEdit2Change
// RadioGroup1Click
// RadioGroup2Click
// RadioGroup3Click
// RadioGroup4Click
// SaveTrStud
// SpeedButton1Click
// StateQ
// UpStud




__fastcall TInfoForm::TInfoForm (TComponent* Owner) : TForm (Owner) {
}


void __fastcall TInfoForm::del_mas (bool mas_chek)
{ // �������� ������� ���������
    // mas_chek = true ������� ������
    // mas_chek = false ������ ��� ������

    /* if (mas_chek) { // if
     for (int i = 0; i < 2; i++)
     delete[]mas_nomer_zach[i];
     //delete[]mas_nomer_zach;
     } // end if */
}


void __fastcall TInfoForm::Create_Spisok_Zachetka ()
{ // �������� ������ ��������� � �������� �������� ������
    // ��� ������ �����
    PrilSheet = NewSheet1 (ExPril);
    incr_gr = DataModule1 -> Zachetka_All_KursFDQueryINC_GROUP -> Value;
    Variant cell;
    NameSheet1 (PrilSheet, DataModule1 -> Zachetka_All_KursFDQueryN_GROUP -> Value);
    SelectSheet (PrilBook, DataModule1 -> Zachetka_All_KursFDQueryN_GROUP -> Value);
    Variant Rang2;
    // -- ����� ������
    Rang2 = Range2 (PrilSheet, "B2:D2");
    CellFont ("Arial", 12, true, false, 1, 0, Rang2);
    // ������������� ����� Arial 10 �/�
    SheetFormat (Rang2, "@"); // ��������� ������

    CellValue (DataModule1 -> Zachetka_All_KursFDQueryN_GROUP -> Value, 2, 2);
    CellValue (RadioGroup1 -> Items -> Strings[RadioGroup1 -> ItemIndex], 3, 2);
    // --
    // ��������� ������ ������ �� ����
    // CellValue ("������ "+n_gr+v_e,1,1);
    Create_Shapka ();
    int str = 3; // ���������� ��� ������ ������
    while (incr_gr == DataModule1 -> Zachetka_All_KursFDQueryINC_GROUP -> Value &&
        !DataModule1 -> Zachetka_All_KursFDQuery -> Eof)
    { // ���� ���������� ����� ������
        CellValue (str - 2, 1, str + 1);
        BorderCell (1, str + 1, 1, 2);
        CellValue (DataModule1 -> Zachetka_All_KursFDQueryFAM -> Value + " " +
            DataModule1 -> Zachetka_All_KursFDQueryNAME -> Value + " " +
            DataModule1 -> Zachetka_All_KursFDQueryOTCH -> Value, 2, str + 1);
        BorderCell (2, str + 1, 1, 2);
        cell = SelectCell (3, str + 1);
        SheetFormat (cell, "@"); // ��������� ������
        CellValue (DataModule1 -> Zachetka_All_KursFDQueryN_ZACHET -> Value, 3,
            str + 1);
        BorderCell (3, str + 1, 1, 2);
        // ���������� ���������� ��������
        BorderCell (4, str + 1, 1, 2); // ����
        BorderCell (5, str + 1, 1, 2); // �������

        if (!DataModule1 -> Zachetka_All_KursFDQuery -> Eof)
            DataModule1 -> Zachetka_All_KursFDQuery -> Next ();
        else {
            AutoFitColumn (PrilSheet, 2); // ���������� ������ ������� ���
            // ��������� ��������� ������� � ������� ������� ��� ��������� �� �����
            Variant Cell1 = "C3";
            Variant Cell2 = "C" + IntToStr (str);
            Rang2 = Range_Range (PrilSheet, Cell1, Cell2);
            HorizontalAlign (Rang2, 3); // ������������ �� ������ */
            return;
        }
        str++;
    } // ���� ���������� ����� ������
    AutoFitColumn (PrilSheet, 2); // ���������� ������ ������� ���
    // ��������� ��������� ������� � ������� ������� ��� ��������� �� �����
    Variant Cell1 = "C3";
    Variant Cell2 = "C" + IntToStr (str);
    Rang2 = Range_Range (PrilSheet, Cell1, Cell2);
    HorizontalAlign (Rang2, 3); // ������������ �� ������ */
}


void __fastcall TInfoForm::Create_Shapka () { // -----����� �������
    Variant Rang3;
    int col = 1; // ����� �������
    // -- ���������
    Rang3 = Range2 (PrilSheet, "B1");
    CellFont ("Arial", 14, true, false, 1, 0, Rang3);
    // ������������� ����� Arial 10 �/�
    CellValue (DM2 -> FacultyFDTable -> Lookup ("N_FAC", nom_fac, "FAC1"), 2, 1);
    // --
    Rang3 = Range2 (PrilSheet, "A3:F3");
    CellFont ("Arial", 12, true, false, 1, 0, Rang3);
    // ������������� ����� Arial 10 �/�
    HorizontalAlign (Rang3, 3); // �� ������ �� �����������
    VerticalAlign (Rang3, 2); // �� ������ �� ���������
    CellValue ("� �/�", col, 3);
    col++;
    CellValue ("���", col, 3);
    col++;
    CellValue ("� ������������� ������, �������", col, 3);
    col++;
    if (RadioGroup4 -> ItemIndex && !mas_none)
    { // if ������������ ������ �� �������
        CellValue ("������", col, 3);
        col++;
        CellValue ("����", col, 3);
        col++;
        CellValue ("�������", col, 3);
    } // end if
    else { // else ���� ��������� ���������� �����
        CellValue ("����", col, 3);
        col++;
        CellValue ("�������", col, 3);
    } // end else

    Rang3 = Range2 (PrilSheet, "C3");
    W1 (Rang3); // ������� �� ������
    for (int i = 1; i <= col; i++) {
        BorderCell (i, 3, 1, 2);
        AutoFitColumn (PrilSheet, i);
    }
    ColumnWidth (Rang3, 22);
    HeightRow (Rang3, 32);

}


void __fastcall TInfoForm::FormClose (TObject *Sender, TCloseAction &Action) {
    // ------
    // del_mas (mas_ch); // �������� �������
    // mas_ch = false; // ��������� ���������� � ��������� ���������� �������
    // ------
    Action = caFree;
}


void __fastcall TInfoForm::FormCreate (TObject *Sender) {
    /* MaskEdit1 -> EditMask = "!\ (999\)000-0000;1";   �������
     MaskEdit1 -> Text = ""; */
    AnsiString mask_god = IntToStr (uch_god); // ��������� ������� ��� � Int
    if (nom_fac != 3) { // if  ���� � ���, �� ������� �������� ���   MaskEdit
        // MaskEdit1 -> EditMask = "\"+mask_god.SubString (3,1)+"\"+mask_god.SubString (4,1)+"\"+nom_fac+"000;_";
    } // end if
    else { // else �����, �� ������� �������� ���   MaskEdit
        // MaskEdit1 -> EditMask = "\"+mask_god.SubString (3,1)+"\"+mask_god.SubString (4,1)+"\0000;_";
    } // end else
    MaskEdit1 -> Text = "";
}


void __fastcall TInfoForm::RadioGroup2Click (TObject *Sender) {
    MaskEdit1 -> Text = "";
    MaskEdit2 -> Text = "";

    // ------
    // del_mas (mas_ch); // �������� �������
    // mas_ch = false; // ��������� ���������� � ��������� ���������� �������
    // ------
    Label6 -> Visible = false; // Label  ���a �����������
    MaskEdit2 -> Visible = false; // ��� �����������

    Label1 -> Visible = false;
    Label2 -> Visible = false;
    Label3 -> Visible = false;
    Label4 -> Visible = false; // ��������� ����� �������� ������ ��� ����� ����
    Label5 -> Visible = false;
    // ���������� ��������� ��������� � ������� ��� ������ �������� ������
    MaskEdit1 -> Visible = false; // ����������������� ����� �������� ������

    Label6 -> Visible = false; // Label    ����
    MaskEdit2 -> Visible = false; // ����������������� ���
    SpeedButton1 -> Visible = false;
    // ������ ������ ������������� �������� ������� �� ��������� ���
    RadioGroup3 -> Visible = false; // ����� ���� ��� �� ���������
    RadioGroup3 -> ItemIndex = -1;

    BitBtn1 -> Visible = false;
    BitBtn2 -> Visible = false;
    RadioGroup4 -> Visible = false;
    // ------

    // ������� ����������������� ��� ����������� ���������
    MaskEdit2 -> Text = IntToStr (uch_god - RadioGroup2 -> ItemIndex);

    Label6 -> Visible = true; // Label  ���a �����������
    MaskEdit2 -> Visible = true; // ��� �����������
    SpeedButton1 -> Visible = true;
    // ------

    // ------
}


void __fastcall TInfoForm::RadioGroup1Click (TObject *Sender) {
    // ------
    // del_mas (mas_ch); // �������� �������
    // mas_ch = false; // ��������� ���������� � ��������� ���������� �������

    // -----
    Label6 -> Visible = false; // Label  ���a �����������
    MaskEdit2 -> Visible = false; // ��� �����������

    Label1 -> Visible = false;
    Label2 -> Visible = false;
    Label3 -> Visible = false;
    Label4 -> Visible = false; // ��������� ����� �������� ������ ��� ����� ����
    Label5 -> Visible = false;
    // ���������� ��������� ��������� � ������� ��� ������ �������� ������
    MaskEdit1 -> Visible = false; // ����������������� ����� �������� ������

    Label6 -> Visible = false; // Label    ����
    MaskEdit2 -> Visible = false; // ����������������� ���
    SpeedButton1 -> Visible = false;
    // ������ ������ ������������� �������� ������� �� ��������� ���
    RadioGroup3 -> Visible = false; // ����� ���� ��� �� ���������
    RadioGroup3 -> ItemIndex = -1;

    BitBtn1 -> Visible = false;
    BitBtn2 -> Visible = false;
    RadioGroup4 -> Visible = false;
    // ------
    RadioGroup2 -> Items -> Clear (); // o������� ������
    // ---
    if (RadioGroup1 -> ItemIndex) { // if    ������� ������� �����
        RadioGroup2 -> Items -> Add ("1 ����");
        RadioGroup2 -> Items -> Add ("2 ����");
        RadioGroup2 -> Items -> Add ("3 ����");
        RadioGroup2 -> Items -> Add ("4 ����");
        RadioGroup2 -> Items -> Add ("5 ����");
        RadioGroup2 -> Items -> Add ("6 ����");
    } // end if  ������� ������� �����
    else { // else  ������� ������� �����
        RadioGroup2 -> Items -> Add ("1 ����");
        RadioGroup2 -> Items -> Add ("2 ����");
        RadioGroup2 -> Items -> Add ("3 ����");
        RadioGroup2 -> Items -> Add ("4 ����");
        RadioGroup2 -> Items -> Add ("5 ����");
    } // end else ������� ������� �����
    RadioGroup2 -> ItemIndex = -1;
    RadioGroup2 -> Visible = true; // ���������� ������� �����
}


void __fastcall TInfoForm::SpeedButton1Click (TObject *Sender) {
    // -
    BitBtn1 -> Visible = false;
    BitBtn2 -> Visible = false;
    RadioGroup4 -> Visible = false;
    RadioGroup3 -> Visible = false;
    Label1 -> Visible = false;
    Label2 -> Visible = false;
    Label3 -> Visible = false;
    Label4 -> Visible = false;
    Label5 -> Visible = false;
    MaskEdit1 -> Visible = false;
    // -
    // 03%
    yyy = ggg.CurrentDate ();
    god_two = DateToStr (yyy.CurrentDate ()).SubString (7, 4);
    //god_two = MaskEdit2 -> Text;
    AnsiString Par_GOD = god_two.SubString (3, 2) + "%";
    // ��������� ���������� ��� ������ � ������� ����
    // Query, ������������ ������������ ����� �������� ������ �� ����������
    DataModule1 -> Max_ZachetkaFDQuery -> Close ();
    DataModule1 -> Max_ZachetkaFDQuery -> ParamByName ("FAC") -> AsSmallInt = nom_fac;
    DataModule1 -> Max_ZachetkaFDQuery -> ParamByName ("GOD") -> AsString = Par_GOD;
    DataModule1 -> Max_ZachetkaFDQuery -> Open ();

    // --
    Label1 -> Visible = true;
    Label4 -> Visible = true;
    // --
    Variant max_zach = DataModule1 -> Max_ZachetkaFDQueryMAX -> AsVariant;
    if (!max_zach.IsNull ())
    { // if ���� ������ ������� �� ���� �����, ���� �� � ������ ��������
        Label4 -> Caption = DataModule1 -> Max_ZachetkaFDQueryMAX -> Value;
    } // end if  ���� ������ ������� �� ���� �����, ���� �� � ������ ��������
    else { // else  ��� ������� �������
        Label4 -> Caption = "���";
    } // end else ��� ������� �������
    AnsiString new_nom; // ��������� �� ������� ����� �������
    Par_GOD = "\\" + god_two.SubString (3, 1) + "\\" + god_two.SubString (4, 1);
    // -----
    if (StrToInt (MaskEdit2 -> Text) >= 2003)
    { // if ����� ������� � 2003 ���� 6-�� ������� �� �������
        // 2 ����� - ������� ���; 1 ����� - ���������; 3 ����� ����� �/�
        AnsiString new_nom1 = "";
        if (!max_zach.IsNull ()) {
            new_nom = (Label4 -> Caption).SubString (4, 3);
            int n_n = (StrToInt (new_nom) + 1);

            switch (IntToStr (n_n).Length ()) {
            case 1:
                new_nom1 = "00" + IntToStr (n_n);
                break;
            case 2:
                new_nom1 = "0" + IntToStr (n_n);
                break;
            case 3:
                new_nom1 = IntToStr (n_n);
                break;
            }
        }

        if (nom_fac != 3)
        { // if  ���� � ���, �� ������� �������� ���   MaskEdit
            // MaskEdit1 -> EditMask = "\\"+god_two.SubString (3,1)+"\\"+god_two.SubString (4,1)+"\\"+nom_fac+"000;_";
            // MaskEdit1 -> Text="\\"+god_two.SubString (3,1)+"\\"+god_two.SubString (4,1)+"\\"+nom_fac+IntToStr (StrToInt (DataModule1 -> Max_ZachetkaQueryMAX -> Value)+1).SubString (4,3);
            MaskEdit1 -> EditMask = Par_GOD + nom_fac + "999;_";
            if (!max_zach.IsNull ()) {
                MaskEdit1 -> Text = Par_GOD + nom_fac + new_nom1;
            }
            else
                MaskEdit1 -> Text = Par_GOD + nom_fac + "001";
        } // end if
        else { // else �����, �� ������� �������� ���   MaskEdit
            // MaskEdit1 -> EditMask = "\\"+god_two.SubString (3,1)+"\\"+god_two.SubString (4,1)+"\0000;_";
            MaskEdit1 -> EditMask = Par_GOD + "\\0" + "999;_";
            if (!max_zach.IsNull ()) {
                MaskEdit1 -> Text = Par_GOD + "\\0" + new_nom1;
            }
            else
                MaskEdit1 -> Text = Par_GOD + "\\0" + "001";
        } // end else

        // MaskEdit1 -> Text=IntToStr (StrToInt (DataModule1 -> Max_ZachetkaQueryMAX -> Value)+1).SubString (4,3);
    } // end if ����� ������� � 2003 ���� 6-�� ������� �� �������
    else { // else �� 2003 ���� ����� ������� ��� 5-�� �������: 2 ����� - ���; 3 ����� - � �/�
        // MaskEdit1 -> EditMask = "\\"+god_two.SubString (3,1)+"\\"+god_two.SubString (4,1)+"\000;_";
        // MaskEdit1 -> Text=StrToInt (Label4 -> Caption.SubString (3,3))+1;
        new_nom = (Label4 -> Caption).SubString (3, 3);
        int n_n = (StrToInt (new_nom) + 1);
        AnsiString new_nom1 = "";
        switch (IntToStr (n_n).Length ()) {
        case 1:
            new_nom1 = "00" + IntToStr (n_n);
            break;
        case 2:
            new_nom1 = "0" + IntToStr (n_n);
            break;
        case 3:
            new_nom1 = IntToStr (n_n);
            break;
        }

        MaskEdit1 -> EditMask = Par_GOD + "999;_";
        if (!max_zach.IsNull ()) {
            MaskEdit1 -> Text = Par_GOD + new_nom1;
        }
        else
            MaskEdit1 -> Text = Par_GOD + "001";
    } // end else �� 2003 ���� ����� ������� ��� 5-�� �������
    // --
    // Label2 -> Visible=true;
    // MaskEdit1 -> Visible=true;
    // RadioGroup3 -> Visible=true;//����� ���� ��� �� ���������
    // RadioGroup3 -> Enabled=true;
    // --
    DataModule1 -> ZachetkaFDQuery -> Close ();
    DataModule1 -> ZachetkaFDQuery -> ParamByName ("FAC") -> AsSmallInt = nom_fac;
    // ���������
    DataModule1 -> ZachetkaFDQuery -> ParamByName ("EDU") -> AsSmallInt =
        RadioGroup1 -> ItemIndex; // ��� ��������
    DataModule1 -> ZachetkaFDQuery -> ParamByName ("KURS") -> AsInteger =
        RadioGroup2 -> ItemIndex + 1; // ����
    DataModule1 -> ZachetkaFDQuery -> ParamByName ("YEAR_INCLUDE") -> AsInteger =
        StrToInt (MaskEdit2 -> Text); // ��� �����������
    DataModule1 -> ZachetkaFDQuery -> Open ();
    DataModule1 -> ZachetkaFDQuery_Count -> Close ();
    DataModule1 -> ZachetkaFDQuery_Count -> ParamByName ("FAC") -> AsSmallInt = nom_fac;
    // ���������
    DataModule1 -> ZachetkaFDQuery_Count -> ParamByName ("EDU") -> AsSmallInt =
        RadioGroup1 -> ItemIndex; // ��� ��������
    DataModule1 -> ZachetkaFDQuery_Count -> ParamByName ("KURS") -> AsInteger =
        RadioGroup2 -> ItemIndex + 1; // ����
    DataModule1 -> ZachetkaFDQuery_Count -> ParamByName ("YEAR_INCLUDE") -> AsInteger =
        StrToInt (MaskEdit2 -> Text); // ��� �����������
    DataModule1 -> ZachetkaFDQuery_Count -> Open ();

    record_zach = DataModule1 -> ZachetkaFDQuery_CountCOUNT -> Value;
    Label3 -> Visible = true;
    Label5 -> Visible = true;
    Label5 -> Caption = IntToStr (record_zach);
    // ���������� ��������� ��������� ��� ������� �������
    // ------
    if (!record_zach) { // if  ���� ��� ��������� ��� ������� �������� ������
        BitBtn2 -> Visible = true; // ���������� ������� ������ �������� � Excel
        mas_none = true;
        return;
    } // end if
    Label2 -> Visible = true;
    MaskEdit1 -> Visible = true;
    RadioGroup3 -> Visible = true; // ����� ���� ��� �� ���������
    RadioGroup3 -> Enabled = true;

    // ������������ ������� ��������� ��� �������
    /* for (int i = 0; i < 2; i++) { // for ���������� �������
     mas_nomer_zach[i] = new AnsiString[record_zach];
     } // end for ���������� ������� */
    // ---
    DataModule1 -> ZachetkaFDQuery -> First (); // ���������� �� ������ ������
    // ---������� � MyList1  ����� � ������ ������
    DualListDlg = new TDualListDlg (this);
    DualListDlg -> SrcList -> Items -> Clear ();
    DualListDlg -> DstList -> Items -> Clear ();
    // ---
    for (int i = 0; i < record_zach; i++) { // for ����������� ������� �������
        // ������ ������ � ������� ����� ��������
        /* mas_nomer_zach[0][i] =
         IntToStr (DataModule1 -> ZachetkaFDQueryNOMER -> Value);
         // ��������� ������ ��� � ����� ������
         mas_nomer_zach[1][i] = DataModule1 -> ZachetkaFDQueryFAM -> Value + " " +
         DataModule1 -> ZachetkaFDQueryNAME -> Value + " " +
         DataModule1 -> ZachetkaFDQueryOTCH -> Value + " " +
         DataModule1 -> ZachetkaFDQueryN_GROUP -> Value + " ��."; */
        // ������� �� ������ ������ (���� ������� ��������������� ����� ���������)
        // � MyList1 ��� ��������
        DualListDlg -> SrcList -> Items -> AddObject
            (DataModule1 -> ZachetkaFDQueryFAM -> Value + " " +
            DataModule1 -> ZachetkaFDQueryNAME -> Value + " " +
            DataModule1 -> ZachetkaFDQueryOTCH -> Value + " " +
            DataModule1 -> ZachetkaFDQueryN_GROUP -> Value + " ��.",
            (TObject *) (DataModule1 -> ZachetkaFDQueryNOMER -> Value));
        DataModule1 -> ZachetkaFDQuery -> Next ();
    } // end for ����������� ������� �������
    // mas_ch = true; // ���������� � ��� ��� ������ ������
    // -------
}


void __fastcall TInfoForm::MaskEdit1Exit (TObject *Sender) {
    if ( ( (StrToInt (MaskEdit2 -> Text) >= 2003) && ( (MaskEdit1 -> Text).Trim () != 6))
        || ( (StrToInt (MaskEdit2 -> Text) < 2003) && ( (MaskEdit1 -> Text).Trim ()
        != 5))) {

        // !!!if (Application -> MessageBox ("�� ����� ������������ ����� �������. ������ ��� ���������?", "������", MB_YESNO) == mrYes)
        if (MessageDlg
            ("�� ����� ������������ ����� �������. ������ ��� ���������?",
            mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes) {
            MaskEdit1 -> SetFocus ();
        }
        else {
            MaskEdit1 -> Text = "";
        }

    }
}


void __fastcall TInfoForm::MaskEdit2Change (TObject *Sender) {
    // ------
    // del_mas (mas_ch); // �������� �������
    // mas_ch = false; // ��������� ���������� � ��������� ���������� �������
    // -----
    Label1 -> Visible = false;
    Label2 -> Visible = false;
    Label3 -> Visible = false;
    Label4 -> Visible = false; // ��������� ����� �������� ������ ��� ����� ����
    Label5 -> Visible = false;
    // ���������� ��������� ��������� � ������� ��� ������ �������� ������
    MaskEdit1 -> Visible = false; // ����������������� ����� �������� ������
    RadioGroup3 -> Visible = false; // ����� ���� ��� �� ���������
    RadioGroup3 -> ItemIndex = -1;

    BitBtn1 -> Visible = false;
    BitBtn2 -> Visible = false;
    RadioGroup4 -> Visible = false;
    // ------
}


void __fastcall TInfoForm::RadioGroup3Click (TObject *Sender) {

    switch (RadioGroup3 -> ItemIndex)
    { // switch  ����������� ������ ������������ ��������� ��� ��������� �������� ������
    case 1: // ��� ���������
        DualListDlg -> ShowModal ();
        if (DataModule2 -> printdlg == true) { // if ����������� ���������
            if (DualListDlg -> DstList -> Items -> Count != 0) {
                /* for (int i = 0; i < DualListDlg -> SrcList -> Items -> Count - 1; i++)
                 { //
                 for (int j = 0; j < record_zach; j++)
                 { // for j  ���� �� ���������� ���� ��������� ���������
                 if (DualListDlg -> SrcList -> Items -> Strings[i]
                 == mas_nomer_zach[1][j]) {
                 // if �������� ��������� ������� ��� ����������� ���������
                 mas_nomer_zach[0][j] = "";
                 mas_nomer_zach[1][j] = "";
                 } // end if �������� ��������� ������� ��� ����������� ���������
                 } // end for j ���� �� ���������� ���� ��������� ���������

                 } // end  for i  ���� �� ���������� ��������� � ��������� ������ */
                BitBtn1 -> Visible = true;
            }
        } // end if ����������� ���������
        else { // else �������� � ���������� ����� ���������
            BitBtn1 -> Visible = false;
        } // end else �������� � ���������� ����� ���������
        Label5 -> Caption = IntToStr (DualListDlg -> DstList -> Items -> Count);
        RadioGroup3 -> Enabled = false;

        break;
    case 0: // ����� ���� ��� ���������
        BitBtn1 -> Visible = true;
        // ���������� ������� ������ ������������� �������
        break;
    } // end switch  ����������� ������ ������������ ��������� ��� ��������� �������� ������

}


void __fastcall TInfoForm::BitBtn1Click (TObject *Sender)
{ // ������������� �������
    if (Label5 -> Caption == "0") {
        ShowMessage ("�� ���� ������� ��������� ��� ��������� �������!");
        return;
    }
    AnsiString zach1 = MaskEdit1 -> Text; // ������ ����� �������
    int n_zach; // ����� ������� � �/�
    if (StrToInt (MaskEdit2 -> Text) >= 2003)
    { // if ��� ������������� ������ �������
        n_zach = StrToInt (zach1.SubString (4, 3));
        zach1 = zach1.SubString (1, 3);

    } // end if ��� ������������� ������ �������
    else { // else if ��� ������������ ������ �������
        n_zach = StrToInt (zach1.SubString (3, 3));
        zach1 = zach1.SubString (1, 2);

    } // end else if ��� ������������ ������ �������

    try { // try
        switch (RadioGroup3 -> ItemIndex)
        { // switch  ����������� ������ ������������ ��������� ��� ��������� �������� ������
        case 1: // ��� ���������
            for (int i = 0; i < DualListDlg -> DstList -> Items -> Count; i++)
            { // for i

                AnsiString new_n_zach = "";
                TLocateOptions Opts;
                Opts.Clear ();
                DataModule1 -> ZachetkaFDQuery -> Locate ("NOMER",
                    (int) (DualListDlg -> DstList -> Items -> Objects[i]), Opts);
                DataModule1 -> ZachetkaFDQuery -> Edit ();
                switch (IntToStr (n_zach).Length ()) {
                case 1:
                    new_n_zach = zach1 + "00" + IntToStr (n_zach);
                    break;
                case 2:
                    new_n_zach = zach1 + "0" + IntToStr (n_zach);
                    break;
                case 3:
                    new_n_zach = zach1 + IntToStr (n_zach);
                    break;
                }
                DataModule1 -> ZachetkaFDQueryN_ZACHET -> Value = new_n_zach;
                DataModule1 -> ZachetkaFDQuery -> ApplyUpdates ();
                DataModule1 -> ZachetkaFDQuery -> CommitUpdates ();
                // ShowMessage ("� �������� "+mas_nomer_zach[1][i]+" ����� ������� "+new_n_zach);
                n_zach++;

            } // end for i

            BitBtn1 -> Visible = false;
            // ������ ��������� ������ ������������� �������
            RadioGroup4 -> Visible = true; // ������� ������� ��� �������� � Excel

            // -
            // BitBtn1 -> Visible=false;
            BitBtn2 -> Visible = false;
            // RadioGroup4 -> Visible=false;
            RadioGroup3 -> Visible = false;
            Label1 -> Visible = false;
            Label2 -> Visible = false;
            Label3 -> Visible = false;
            Label4 -> Visible = false;
            Label5 -> Visible = false;
            MaskEdit1 -> Visible = false;
            // -
            break;
        case 0: // ����� ���� ��� ���������
        DataModule1 -> ZachetkaFDQuery -> First ();
            for (int i = 0; i < record_zach; i++) { // for i
                AnsiString new_n_zach = "";
                TLocateOptions Opts;
                Opts.Clear ();
                DataModule1 -> ZachetkaFDQuery -> Edit ();
                switch (IntToStr (n_zach).Length ()) {
                case 1:
                    new_n_zach = zach1 + "00" + IntToStr (n_zach);
                    break;
                case 2:
                    new_n_zach = zach1 + "0" + IntToStr (n_zach);
                    break;
                case 3:
                    new_n_zach = zach1 + IntToStr (n_zach);
                    break;
                }
                DataModule1 -> ZachetkaFDQueryN_ZACHET -> Value = new_n_zach;
                DataModule1 -> ZachetkaFDQuery -> ApplyUpdates ();
                DataModule1 -> ZachetkaFDQuery -> CommitUpdates ();
                // ShowMessage ("� �������� "+mas_nomer_zach[1][i]+" ����� ������� "+new_n_zach);
                n_zach++;
                DataModule1 -> ZachetkaFDQuery -> Next ();
            } // end for i

            BitBtn1 -> Visible = false;
            // ������ ��������� ������ ������������� �������
            RadioGroup4 -> Visible = true; // ������� ������� ��� �������� � Excel

            // -
            // BitBtn1 -> Visible=false;
            BitBtn2 -> Visible = false;
            // RadioGroup4 -> Visible=false;
            RadioGroup3 -> Visible = false;
            Label1 -> Visible = false;
            Label2 -> Visible = false;
            Label3 -> Visible = false;
            Label4 -> Visible = false;
            Label5 -> Visible = false;
            MaskEdit1 -> Visible = false;
            // -
            break;
        } // end switch  ����������� ������ ������������ ��������� ��� ��������� �������� ������

    } // end try
    catch (...) {
        DataModule1 -> ZachetkaFDQuery -> CancelUpdates ();
        ShowMessage ("��������� ����! ���������� ��� ���.");
    }
}


void __fastcall TInfoForm::RadioGroup4Click (TObject *Sender) {
    switch (RadioGroup4 -> ItemIndex) { // switch
    case 0: // ���� ���������, ���������� �����
        DataModule1 -> Zachetka_All_KursFDQuery -> Close ();

        DataModule1 -> Zachetka_All_KursFDQuery -> ParamByName ("FAC") -> AsSmallInt =
            nom_fac; // ���������
        DataModule1 -> Zachetka_All_KursFDQuery -> ParamByName ("EDU") -> AsSmallInt =
            RadioGroup1 -> ItemIndex; // ��� ��������
        DataModule1 -> Zachetka_All_KursFDQuery -> ParamByName ("KURS") -> AsInteger =
            RadioGroup2 -> ItemIndex + 1; // ����

        DataModule1 -> Zachetka_All_KursFDQuery -> Open ();
        break;
    case 1: // ������ ���������, ������� ������ ���� ������ �������

        break;
    } // end switch
    BitBtn2 -> Visible = true;
    RadioGroup4 -> Visible = false;
}


void __fastcall TInfoForm::BitBtn2Click (TObject *Sender)
{ // ������ �������� � Excel
    // ExPril , PrilBook, PrilSheet
    ExPril = Variant::CreateObject ("Excel.Application");
    ColWorkSheet (ExPril, (Variant)1);
    PrilBook = NewBook (ExPril);
    // 
    Variant Rang1; // ���������� ��� ��������� �����

    if (RadioGroup4 -> ItemIndex && !mas_none)
    { // if ������� ��������� �� �������
        int str = 3;
        PrilSheet = NewSheet1 (ExPril);
        NameSheet1 (PrilSheet, "������ �������� ������");
        SelectSheet (PrilBook, "������ �������� ������");
        Create_Shapka ();
        for (int i = 0; i < DualListDlg -> DstList -> Items -> Count; i++) { // for i

            TLocateOptions Opts;
            Opts.Clear ();
            DataModule1 -> ZachetkaFDQuery -> Locate ("NOMER",
                (int) (DualListDlg -> DstList -> Items -> Objects[i]), Opts);

            CellValue (str - 2, 1, str + 1);
            BorderCell (1, str + 1, 1, 2); // ����� �/�
            CellValue (DataModule1 -> ZachetkaFDQueryFAM -> Value + " " +
                DataModule1 -> ZachetkaFDQueryNAME -> Value + " " +
                DataModule1 -> ZachetkaFDQueryOTCH -> Value, 2, str + 1);
            BorderCell (2, str + 1, 1, 2); // ���
            ///����� �������� ������
            Variant cell = SelectCell (3, str + 1);
            SheetFormat (cell, "@");
            // ������ ������  ��� ������ ������� - ���������
            CellValue (DataModule1 -> ZachetkaFDQueryN_ZACHET -> Value, 3, str + 1);
            BorderCell (3, str + 1, 1, 2); // � �������
            ///����� ������
            cell = SelectCell (4, str + 1);
            SheetFormat (cell, "@");
            // ������ ������  ��� ������ ������� - ���������
            CellValue (DataModule1 -> ZachetkaFDQueryN_GROUP -> Value, 4,
                str + 1); // ������

            // ���������� ���������� ��������
            BorderCell (4, str + 1, 1, 2); // ������
            BorderCell (5, str + 1, 1, 2); // ����
            BorderCell (6, str + 1, 1, 2); // �������

            str++;

        } // end for i
        // ��������� ��������� ������� � ������� ������� ��� ��������� �� �����
        Variant Cell1 = "C3";
        Variant Cell2 = "C" + IntToStr (str);
        Rang1 = Range_Range (PrilSheet, Cell1, Cell2);
        HorizontalAlign (Rang1, 3); // ������������ �� ������ */
        AutoFitColumn (PrilSheet, 2); // ���������� ������ ������� ���
    } // end if ������� ��������� �� �������
    else { // else  ������� ��������� ����� �����

        if (DataModule1 -> Zachetka_All_KursFDQuery -> State == dsInactive)
        { // if  ���� �� ���� ��������� ��� ���������, �� ���� ������� ����� ������
            DataModule1 -> Zachetka_All_KursFDQuery -> Close ();
            DataModule1 -> Zachetka_All_KursFDQuery -> ParamByName ("FAC")
                -> AsSmallInt = nom_fac; // ���������
            DataModule1 -> Zachetka_All_KursFDQuery -> ParamByName ("EDU")
                -> AsSmallInt = RadioGroup1 -> ItemIndex; // ��� ��������
            DataModule1 -> Zachetka_All_KursFDQuery -> ParamByName ("KURS")
                -> AsInteger = RadioGroup2 -> ItemIndex + 1; // ����
            DataModule1 -> Zachetka_All_KursFDQuery -> Open ();
        } // end if  ���� �� ���� ��������� ��� ���������, �� ���� ������� ����� ������

        while (!DataModule1 -> Zachetka_All_KursFDQuery -> Eof) { // while
            Create_Spisok_Zachetka ();
            // �������� ������ ���� ��������� ����� � �������� �������
        } // end while

        DataModule1 -> Zachetka_All_KursFDQuery -> Close ();

    } // end else ������� ��������� ����� �����
    // ---���������� �����
    AnsiString name_f = "������ ������� ��������� ���������� " +
        DM2 -> FacultyFDTable -> Lookup ("N_FAC", nom_fac, "FAC1") + " �� " +
        cur_d () + ".xls";
    Variant WorkSaveAs = SaveBookAs (PrilBook, "d:\\��� ���������\\" + name_f);
    OVisible (ExPril);

    ExPril.Clear ();
    // ------
    // del_mas (mas_ch); // �������� �������
    // mas_ch = false; // ��������� ���������� � ��������� ���������� �������

    // -----
    Label6 -> Visible = false; // Label  ���a �����������
    MaskEdit2 -> Visible = false; // ��� �����������

    Label1 -> Visible = false;
    Label2 -> Visible = false;
    Label3 -> Visible = false;
    Label4 -> Visible = false; // ��������� ����� �������� ������ ��� ����� ����
    Label5 -> Visible = false;
    // ���������� ��������� ��������� � ������� ��� ������ �������� ������
    MaskEdit1 -> Visible = false; // ����������������� ����� �������� ������

    Label6 -> Visible = false; // Label    ����
    MaskEdit2 -> Visible = false; // ����������������� ���
    SpeedButton1 -> Visible = false;
    // ������ ������ ������������� �������� ������� �� ��������� ���
    RadioGroup3 -> Visible = false; // ����� ���� ��� �� ���������
    RadioGroup3 -> ItemIndex = -1;

    RadioGroup1 -> ItemIndex = -1;
    RadioGroup2 -> ItemIndex = -1;
    RadioGroup4 -> ItemIndex = -1;

    BitBtn1 -> Visible = false;
    BitBtn2 -> Visible = false;
    RadioGroup4 -> Visible = false;

    mas_none = false;
    // ------

}



void __fastcall TInfoForm::BitBtn3Click (TObject *Sender) {
    year_uch = "'" + IntToStr (uch_god) + "/" + (uch_god + 1) + "'";

    DM4 -> FDConnectionCards_TR -> Connected = true;
    DM4 -> FDConnectionCards -> Connected = true;
    // ��������� Q ����� ����������� CARDSTRANSFER
    DM4 -> VidEduQ -> Close ();
    DM4 -> VidEduQ -> Open ();
    // ��������� Q �������� CARDSTRANSFER
    DM4 -> TrStudQ -> Close ();
    DM4 -> TrStudQ -> Open ();
    DM4 -> TrStudQ_Count -> Close ();
    DM4 -> TrStudQ_Count -> Open ();
    DM4 -> FDTable1 -> Close ();
    DM4 -> FDTable1 -> Open ();
    DataModule1 -> StudQ -> Close ();
    DataModule1 -> StudQ -> ParamByName ("fac") -> AsInteger = nom_fac;
    DataModule1 -> StudQ -> Open ();
    DataModule1 -> StudQ_Count -> Close ();
    DataModule1 -> StudQ_Count -> ParamByName ("fac") -> AsInteger = nom_fac;
    DataModule1 -> StudQ_Count -> Open ();
    String msg = "";
    String msgTitle = "";
    msg = "�� ������������� ������ �������� ������!";
    msgTitle = "��������!";
    if (Application -> MessageBox (msg.w_str (), msgTitle.w_str (),
        MB_YESNO + MB_ICONWARNING) == mrYes) { // if msg
        up_stud = true; // ������ �����������
        DataModule1 -> StudQ -> First ();
        for (int i = 0; i < DataModule1 -> StudQ_CountCOUNT -> Value; i++) { // for StudQ
            nomer_st = DataModule1 -> StudQNOMER -> Value; // ID ��������
            UpStud (); // ����� ���������
            DM4 -> FDTable1PHOTO -> Value = DataModule1 -> StudQPHOTO -> Value;
            DM4 -> FDTable1SIGNATURE -> Value = DataModule1 -> StudQDIGIT_SIGN -> Value;
            SaveTrStud ();
            DataModule1 -> StudQ -> Next (); // ������� �� ����. ��������
        } // end for StudQ

        up_stud = false; // ���������� ���������
        // ���������� ���������, ���� ��� ��
        if (well == true)
            ShowMessage ("���������� ������ ������!");
        DataModule1 -> StudQ -> Close (); // ��������� Q ������ ��������� �� ��������
        DataModule1 -> StudQ_Count -> Close ();
    } // end if msg
    else { // else msg
        up_stud = false; // ������ �� �����������
       } // end else msg
}

void __fastcall TInfoForm::UpStud () {
    DM4 -> TrStudQ -> First ();
    for (int j = 0; j <= DM4 -> TrStudQ_CountCOUNT -> Value; j++)
    { // for TrStudQ (���� �� ����� ID � �� CARDSTRANSFER)
        Flags.Clear ();
        if (DM4 -> TrStudQ -> Locate ("ROWGUID", nomer_st, Flags)) { // if ����
            n_r = true; // Q Edit ();
            break;
        } // end if ����
        else { // else ���
            n_r = false;
            break;
        } // end else ���
    } // end for TrStudQ (���� �� ����� ID � �� CARDSTRANSFER)

    // ---������� PASPORT_TR
    DM4 -> TrPasportQ -> Close ();
    DM4 -> TrPasportQ -> ParamByName ("rowguid") -> AsInteger = nomer_st;
    DM4 -> TrPasportQ -> Open ();

    // ---������� PERS_STUD_TR
    DM4 -> TrPersQ -> Close ();
    DM4 -> TrPersQ -> ParamByName ("rowguid") -> AsInteger = nomer_st;
    DM4 -> TrPersQ -> Open ();

    StateQ (); // ��������� Q
    // ������� STUDENT_TR
    nomer_st = DataModule1 -> StudQNOMER -> Value; // ���������� ID ��������
    DM4 -> TrStudQROWGUID -> Value = nomer_st; // ID ��������
    DM4 -> TrStudQFAM_TR -> Value = DataModule1 -> StudQFAM -> Value; // �������
    DM4 -> TrStudQNAME_TR -> Value = DataModule1 -> StudQNAME -> Value; // ���
    DM4 -> TrStudQOTCH_TR -> Value = DataModule1 -> StudQOTCH -> Value; // ��������
    // ---
    int status_stud = 0;
    status_stud = DataModule1 -> StudQSTATUS_PEOPLE -> Value;
    // ACTIVE_STUDENT=1,
    if (status_stud == 1)
        DM4 -> TrStudQACTIVE_STUDENT -> Value = 1; // 1-�� ������������, 0-������������
    else
        DM4 -> TrStudQACTIVE_STUDENT -> Value = 0;

    DM4 -> TrStudQID_FAC -> Value = DataModule1 -> StudQN_FAC -> Value; // ID ����������
    // ---����� �������� ID
    int vid_edu = DataModule1 -> StudQVID_EDU -> Value;
    DM4 -> TrStudQID_VID_EDU -> Value = vid_edu; // ID ����� ��������
    // ---
    DM4 -> TrStudQID_SPEC -> Value = DataModule1 -> StudQN_SPECIALIZ -> Value; // ID �������������
    // ---���� (ID==����)
    int kurs = DataModule1 -> StudQKURS -> Value;
    DM4 -> TrStudQID_KURS -> Value = kurs; // ID ����=����
    // ---
    DM4 -> TrStudQID_STUD_TYPE -> Value = 1; // 1-�������, 2-����������
    DM4 -> TrStudQNOM_Z -> Value = DataModule1 -> StudQN_ZACHET -> Value;
    // ����� �������=����� ����.������
    // ---���
    AnsiString pol = "";
    pol = DataModule1 -> StudQPOL -> Value;
    if (pol != "" & pol == "�")
        DM4 -> TrStudQPOL -> Value = 1;
    else if (pol != "" & pol == "�")
        DM4 -> TrStudQPOL -> Value = 0;
    // ---
    DM4 -> TrStudQCITYZENSHIP -> Value = DataModule1 -> StudQGRAGDAN -> Value; // �����������
    DM4 -> TrStudQN_GROUP -> Value = DataModule1 -> StudQN_GROUP -> Value; // ����� ������

    // ---��� �����������
    AnsiString date_include =
        DateTimeToStr (SQLTimeStampToDateTime (DataModule1 -> StudQD_PRIKAZ_INCLUDE -> Value));
    int year_include = date_include.SubString (7, 4).ToInt ();
    DM4 -> TrStudQADD_YEAR -> Value = year_include;

    // DM -> TrStudQDATE_ZACH -> Value=DM -> StudQD_PRIKAZ_INCLUDE -> Value;     //���� ������� � ����������
    // ---���� ����������
    AnsiString date_zac = "";

    date_zac = "01.09." + IntToStr (year_include);
    // year_include �� ������� � ����������!!!!

    DM4 -> TrStudQDATE_ZACH -> Value = DateTimeToSQLTimeStamp (StrToDate (date_zac));

    // ---
    DM4 -> TrStudQUCH_YEAR -> Value =year_uch;
    // ������� ������� ��� �� ������ ����������

    // ���� ��������� 30.06.2___ //���������!!!!! �� ������ ���������!!!!
    AnsiString kurs_uch = "", year_end = "", date_end = "";
     year_add = uch_god;
    if (vid_edu == 1) { // �������
        kurs_uch = 6 - kurs; // ������� ������ �������
        year_end = year_add + kurs_uch; // ��� ���������
        if (kurs_uch == 0)
            year_end = year_add + 1; // ��� ���������
    }
    else { // �������
        kurs_uch = 5 - kurs; // ������� ������ �������
        year_end = year_add + kurs_uch; // ��� ���������
        if (kurs_uch == 0)
            year_end = year_add + 1; // ��� ���������
    }
    date_end = "30.06." + year_end;
    DM4 -> TrStudQDATE_END -> Value = DateTimeToSQLTimeStamp (StrToDate (date_end));
    DM4 -> TrStudQID_VUZ -> Value = 1; // ���
    DM4 -> TrStudQDEKAN -> Value = DataModule1 -> StudQN_FAC -> Value; // �����
    // ---������� PASPORT_TR

    AnsiString pasport = "", series = "", number = "";
    pasport = DataModule1 -> StudQPASPORT -> Value; // �����+����� ��������
    DM4 -> TrPasportQROWGUID -> Value = nomer_st; // ID ��������
    DM4 -> TrPasportQPERSONAL_NUMBER -> Value = DataModule1 -> StudQPERSONAL_NOMER -> Value;
    DM4 -> TrPasportQPASPORT -> Value = pasport;
    int index = pasport.Pos (" "); // ���� ���� ������
    if (index != 0) {
        series = pasport.SubString (0, pasport.Pos (" ") - 1); // �������� �����
        number = pasport.SubString (pasport.Pos (" ") + 1, pasport.Length ());
        // �������� �����
    }
    else { // else ��� ������� - �������� ������ ��� ������� � �����
        series = pasport.SubString (1, 2); // �������� �����
        number = pasport.SubString (3, pasport.Length ()); // �������� �����
    }
    DM4 -> TrPasportQSERIES -> Value = series;
    DM4 -> TrPasportQNUMBER -> Value = number;
    // ---������� PERS_STUD_TR

    DM4 -> TrPersQROWGUID -> Value = nomer_st; // ID ��������
    DM4 -> TrPersQLOGIN -> Value = nomer_st; // �����
    DM4 -> TrPersQE_MAIL -> Value = ""; // e-mail

    DM4 -> FDTable1IDDATABASES -> Value = 1;
    DM4 -> FDTable1IDPERSON -> Value = nomer_st;
    DM4 -> FDTable1PHOTO -> Value = DataModule1 -> StudQPHOTO -> Value;
    DM4 -> FDTable1SIGNATURE -> Value =
            DataModule1 -> StudQDIGIT_SIGN -> Value;
    // ����� ��������� ���������� ��������� � ��
}


void __fastcall TInfoForm::SaveTrStud ()
{
// ��������� ���������� ������� � �� CARDSTRANSFER
    try { // ���������� � ��
        DM4 -> TrStudQ -> ApplyUpdates ();
        DM4 -> TrStudQ -> CommitUpdates ();

        DM4 -> TrPasportQ -> ApplyUpdates ();
        DM4 -> TrPasportQ -> CommitUpdates ();

        DM4 -> TrPersQ -> ApplyUpdates ();
        DM4 -> TrPersQ -> CommitUpdates ();

        DM4 -> FDTable1 -> ApplyUpdates ();
        DM4 -> FDTable1 -> CommitUpdates ();

    }
    catch (...) { // catch
        ShowMessage ("��������� ���� ��� ����������!");
        DM4 -> TrStudQ -> CancelUpdates ();
        DM4 -> TrPasportQ -> CancelUpdates ();
        DM4 -> TrPersQ -> CancelUpdates ();
        DM4 -> FDTable1 -> CommitUpdates ();
        well = false; // ���� ��� ����������
        return;
    } // end catch
} // end ��������� ���������� ������� � �� CARDSTRANSFER


void __fastcall TInfoForm::StateQ () { // ��������� ��������� Q
    if (n_r == true) {
        DM4 -> TrStudQ -> Edit ();
        DM4 -> TrPersQ -> Edit ();
        DM4 -> TrPasportQ -> Edit ();

    }
    else {
        DM4 -> TrStudQ -> Insert ();
        DM4 -> TrPersQ -> Insert ();
        DM4 -> TrPasportQ -> Insert ();
    }
    if (DM4 -> FDTable1 -> Locate ("IDPERSON", nomer_st, Flags)) { // if ����
        DM4 -> FDTable1 -> Edit (); // Q Edit ();
        // break;
    } // end if ����
    else { // else ���
        DM4 -> FDTable1 -> Insert ();
        // break;
    } // end else ���
} // end ��������� ��������� Q

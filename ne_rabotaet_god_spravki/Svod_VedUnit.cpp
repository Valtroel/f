// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Svod_VedUnit.h"
#include "func.h"
#include "DM3Unit.h"
#include "DM2Unit.h"
#include "DataModule.h"
#include "MainUnit.h"
// #include <oleauto.hpp>
#include <comobj.hpp>
// --
// #include <Classes.hpp>
// #include <Controls.hpp>
// #include <StdCtrls.hpp>

#include "Excel_2K_SRVR.h"
// #include <OleServer.hpp>
// #include <Buttons.hpp>
// ----
// ---------------------------------------------------------------------------
#pragma package (smart_init)
// !!!#pragma link "MyList"
// !!!#pragma link "ToolEdit"
#pragma resource "*.dfm"
TSvod_Ved *Svod_Ved;
// ���������� ��� ������� � Excel
Variant XLApp;
Variant XLSh;
Variant XLBook;
// ��������� ���������� ��� �������� ������� ���������
int *predmet1;
int kol_predmet; // ���������� ���������
// ��������� ������ ����� ������� ������ ������ ������ �� ������ ��������
// ���������� �������
int *God_ob;
// ������� ��� ���������
AnsiString ut_god;
//
int *mas_pred[4];
// ������ ��������� �� ��������:���, ��������, ��������, ������������
int *Count_pred; // ������ ���������� ��������� �� ��������
// int *Spec; //������ �������������
// int kol_spec; //���������� �������������

AnsiString kurs_text; // ����� �����

// ---------------------------------------------------------------------------
__fastcall TSvod_Ved::TSvod_Ved (TComponent* Owner) : TForm (Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TSvod_Ved::FormClose (TObject *Sender, TCloseAction &Action) {
    Action = caFree;
}

// ---------------------------------------------------------------------------
void __fastcall TSvod_Ved::Cell_2_Text_Ole (Variant XLApp, Variant XLSh,
    int col1, int col2, int st, bool Border, AnsiString Shrift, int kegl,
    bool Bold, int AlignH, int AlignV, bool M_1, bool W_1, AnsiString TextCell)
{ // ��������� ��� ��������� ��������� ����� � �������� � ���� �����, ������� ������, ���� ������������ � ������
    // Variant WorkSheet - ���������� ��� ������ Excel
    // int col1, int col2  - ����� ������� � ������� ������� ��� ��������� ���������
    // int st - ����� ������
    // bool Border - ���������� ������ true - ���������
    // AnsiString Shrift, int kegl - �������� ������ � ��� ������
    // int AlignH, int AlignV - �������������� � ������������ ������������ ������ � ������ (0 - �� ���� �����������)
    // bool M1, bool W1  - ����������� �����, ��������� �������� �� ������ (false - �� ���� ��������� ���� ��������)
    // AnsiString TextCell  - ����� � ������

    // ��������� ������ � ��������� ������ ��� ���������
    // Variant C1=SelectCell (col1,st);
    // Variant C2=SelectCell (col2,st);

    AnsiString diap = mas_column[col1 - 1] + st + ":" +
        mas_column[col2 - 1] + st;

    // ��������
    Variant Rang1 = XLApp.OlePropertyGet ("Range", diap.c_str ());
    // Range_Range (WorkSheet,C1,C2);

    // Variant Rang1=XLSh.OlePropertyGet ("Cells",st,col1);
    // ������� �� ������ � ������  - ���� false, �� �� ����������
    if (W_1)
        W1 (Rang1);

    // ����������� �����  - ���� false, �� �� ����������
    if (M_1)
        M1 (Rang1);

    // ��������� ������
    // CellFont (Shrift,kegl,Bold,false,1,0,Rang1);
    Rang1.OlePropertyGet ("Font").OlePropertySet ("Name", Shrift.c_str ());
    Rang1.OlePropertyGet ("Font").OlePropertySet ("Size", kegl);

    if (Bold)
        Rang1.OlePropertyGet ("Font").OlePropertySet ("Bold", True);

    // ��������� � ������ ��������
    // CellValue (TextCell,col1,st);
    Variant cur = XLSh.OlePropertyGet ("Cells", st, col1);
    cur.OlePropertySet ("Value", TextCell.c_str ());

    // ���������� ������
    if (Border) { // if true - �� ��������� ������
        // if (col1==col2) BorderCell (col1, st, 1, 2);
        // else
        // { //else ����� ��������� ������ ��� ���� ������
        // for (col1;col1<=col2;col1++)
        // {
        for (int i = 1; i <= 4; i++) {
            Rang1.OlePropertyGet ("Borders").OlePropertyGet ("Item", i)
                .OlePropertySet ("LineStyle", 1);
        }
        // BorderCell (col1, st, 1, 2);
        // }
        // } //end else ����� ��������� ������ ��� ���� ������

    } // end if true - �� ��������� ������
    // �������������� ������������   - ���  0 ����������� �� ����
    if (AlignH)
        HorizontalAlign (Rang1, AlignH);

    // ������������ ������������     - ���  0 ����������� �� ����
    if (AlignV)
        VerticalAlign (Rang1, AlignV);

}

// ---------------------------------------------------------------------------
// ��������� ������������ ������� �����
void __fastcall TSvod_Ved::Mas_God (int n_kurs) {
    God_ob = new int[n_kurs];
    // God_ob[0]=StrToInt (ut_god);
    God_ob[0] = uch_god;
    for (int kur = 1; kur < n_kurs; kur++)
        God_ob[kur] = God_ob[kur - 1] - 1;

}

// ---------------------------------------------------------------------------
// ��������� ������������ ������� ���������
void __fastcall TSvod_Ved::Mas_Predmet (int n_kurs, int n_vid_edu, int specializ)
{
    // ��������� � ��������� ������������ ������� �����
    Mas_God (n_kurs);
    // ���������� ���������
    int semestr = n_kurs * 2;

    predmet1 = new int[200];
    kol_predmet = 0;
    // �������� �������� ������� ������ ������� ������
    // ������� �� ���������
    // �� ���������� ����
    int *vid;
    vid = new int[4];
    vid[0] = 2;
    vid[1] = 3;
    vid[2] = 1;
    vid[3] = 0;
    // ���� �� 2--��������, 3-- ���. ������, 1 -- �����, 0 - �������� ��� ���� ��������
    for (int m = 0; m < 4; m++) {
        int kur = n_kurs - 1;
        for (int sem = 1; sem <= semestr; sem++) {

            DM3 -> Detail_Svod_NadoFDQuery -> Close ();
            DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("N_FAC") -> Value = nom_fac;
            DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("VID_EDU") -> Value =
                n_vid_edu;
            // ����� ���. �� �������
            DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("VID") -> Value = vid[m];
            DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("YEAR_PLAN") -> Value =
                StrToInt (God_ob[kur]);
            DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("SEMESTR") -> Value = sem;
            DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("SPECIALIZ") -> Value =
                specializ;
            DM3 -> Detail_Svod_NadoFDQuery -> Open ();
            DM3 -> Detail_Svod_NadoFDQuery -> First ();
            //////////////////////////////////
            // ������� �� ��������� ������� ���

            if (sem % 2 == 0)
                kur = kur - 1;
            //////////////////////////////////
            // ������������ ���-�� ���������
            for (int kk = 0; kk < DM3 -> Detail_Svod_NadoFDQuery -> RecordCount;
            kk++) { // ��������� �������� ������� ��������� �� ��������� ���������
                DM3 -> PredmetFDQuery -> Close ();
                DM3 -> PredmetFDQuery -> ParamByName ("N_FAC") -> Value = nom_fac;
                DM3 -> PredmetFDQuery -> ParamByName ("VID_EDU") -> Value =
                    DM3 -> Detail_Svod_NadoFDQueryVID_EDU_PLAN -> Value;
                DM3 -> PredmetFDQuery -> ParamByName ("N_OBJECT") -> Value =
                    DM3 -> Detail_Svod_NadoFDQueryN_OBJECT -> Value;
                DM3 -> PredmetFDQuery -> Open ();
                if (DM3 -> PredmetFDQuery -> RecordCount == 1) {
                    predmet1[kol_predmet] = DM3 -> PredmetFDQueryN_OBJECT -> Value;
                    kol_predmet = kol_predmet++;
                } // if
                else {
                    bool R = true;
                    for (int ii = 0; ii < kol_predmet; ii++) {
                        if (DM3 -> PredmetFDQueryN_OBJECT -> Value == predmet1[ii])
                            R = false;
                    }
                    if (R) {
                        predmet1[kol_predmet] =
                            DM3 -> PredmetFDQueryN_OBJECT -> Value;
                        kol_predmet = kol_predmet++;
                    }

                } // else
                DM3 -> Detail_Svod_NadoFDQuery -> Next ();
            } // ����� ����� �� ���������
        } // ����� ����� �� ���������

    } // for ���.���
    delete[]vid;
}

// ---------------------------------------------------------------------------
// ��������� ������������ ������� ��������� �� �����������
// pred[0]-- ��������, ������
// pred[1]-- ��������, pred[2]-- ��������, pred[3]--���  , pred[4]--������������
void __fastcall TSvod_Ved::Mas_Pred (int n_kurs, int n_vid_edu, int specializ) {

    // ��� ����� ������� ���������� ����� ������ ��������� ��� ���������� ��������
    Mas_Predmet (n_kurs, n_vid_edu, specializ);
    // ������������ ���������� �������
    for (int i = 0; i < 4; i++) {
        mas_pred[i] = new int[kol_predmet];
    }
    // ������������ ������� ���������� ���������
    Count_pred = new int[4];
    // ��������� ��������
    for (int i = 0; i < 4; i++) {
        Count_pred[i] = 0;
    }
    // int j=0;
    for (int i = 0; i < kol_predmet; i++) {
        DM3 -> Name_PredmetFDQuery -> Close ();
        DM3 -> Name_PredmetFDQuery -> ParamByName ("N_OBJECT") -> Value = predmet1[i];
        DM3 -> Name_PredmetFDQuery -> Open ();
        if ( (DM3 -> Name_PredmetFDQueryNAME_OBJECT -> Value.Pos ("��������")) ||
            (DM3 -> Name_PredmetFDQueryNAME_OBJECT -> Value.Pos ("��������"))) {
            mas_pred[2][Count_pred[2]] =
                DM3 -> Name_PredmetFDQueryN_OBJECT -> Value;
            Count_pred[2] = Count_pred[2] + 1;

        }
        if (DM3 -> Name_PredmetFDQueryNAME_OBJECT -> Value.Pos ("��������")) {
            mas_pred[1][Count_pred[1]] =
                DM3 -> Name_PredmetFDQueryN_OBJECT -> Value;
            Count_pred[1] = Count_pred[1] + 1;

        }
        if ( (!DM3 -> Name_PredmetFDQueryNAME_OBJECT -> Value.Pos ("��������")) &&
            (!DM3 -> Name_PredmetFDQueryNAME_OBJECT -> Value.Pos ("��������")) &&
            (!DM3 -> Name_PredmetFDQueryNAME_OBJECT -> Value.Pos ("��������"))) {
            mas_pred[0][Count_pred[0]] =
                DM3 -> Name_PredmetFDQueryN_OBJECT -> Value;
            Count_pred[0] = Count_pred[0] + 1;
        }

    } // for
    // �������� ��� ���.

    /* //�������� ������, ����� ���������, ������������ ����������
     int kur=n_kurs-1;
     DM3 -> Detail_Svod_Nado -> Close ();
     DM3 -> Detail_Svod_Nado -> ParamByName ("N_FAC") -> Value=nom_fac;
     DM3 -> Detail_Svod_Nado -> ParamByName ("VID_EDU") -> Value=n_vid_edu;
     DM3 -> Detail_Svod_Nado -> ParamByName ("VID") -> Value=4;//�������  4-- ��� ���.
     DM3 -> Detail_Svod_Nado -> ParamByName ("YEAR_PLAN") -> Value=StrToInt (God_ob[kur]);
     DM3 -> Detail_Svod_Nado -> ParamByName ("SEMESTR") -> Value=kur*2; */
    // ---------����� ��c��
    DM3 -> Detail_Svod_NadoFDQuery -> Close ();
    DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("N_FAC") -> Value = nom_fac;
    DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("VID_EDU") -> Value = n_vid_edu;
    DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("VID") -> Value = 4;
    // �������  4-- ��� ���.
    DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("YEAR_PLAN") -> Value =
        StrToInt (God_ob[0]);
    DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("SEMESTR") -> Value = n_kurs * 2;
    DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("SPECIALIZ") -> Value = specializ;
    // ---------
    DM3 -> Detail_Svod_NadoFDQuery -> Open ();
    DM3 -> Detail_Svod_NadoFDQuery -> First ();
    for (int i = 0; i < DM3 -> Detail_Svod_NadoFDQuery -> RecordCount; i++) {
        mas_pred[3][i] = DM3 -> Detail_Svod_NadoFDQueryN_OBJECT -> Value;
        DM3 -> Detail_Svod_NadoFDQuery -> Next ();
        Count_pred[3] = Count_pred[3] + 1;
    }

}

// ---------------------------------------------------------------------------
void __fastcall TSvod_Ved::BitBtn1Click (TObject *Sender) {
    syst_ball = 10; // �� �������� ����� ���������� ������������� ������� ������

    Svod_Ved -> Close ();
}
// ---------------------------------------------------------------------------
/* AnsiString __fastcall TSvod_Ved::Str (int result)
 {
 AnsiString St="";
 switch (result)
 {
 case 1 :  St="�������";
 break;
 case 3 :  St="�����������������";
 break;
 case 4 :  St="������";
 break;
 case 5 :  St="�������";
 break;
 case 7 :  St="����������";
 break;
 }
 return St;

 }
 */

// ---------------------------------------------------------------------------

void __fastcall TSvod_Ved::BitBtn2Click (TObject *Sender) {
   /*    if ( (Edit2 -> Text == "") || (ComboBox2 -> Text == "")) {
        ShowMessage ("������� �������� ������ ������ � ����� ��������!!!");
        return;
    }
    else {

        Variant i_gr = search_increment_group (Edit2 -> Text,
        ComboBox2 -> ItemIndex);
        if (!i_gr.IsNull ()) {
            // ������������ Query ��� �������
            DM3 -> People_SvodReportFDQuery -> Close ();
            DM3 -> People_SvodReportFDQuery -> SQL -> Clear ();
            DM3 -> People_SvodReportFDQuery -> SQL -> Add ("SELECT People.NOMER, People.FAM, People.NAME, People.OTCH, People.POL, People.PLACE_R, People.NAZ, People.MARIAGE, People.N_CHILD, People.EDUCATION, People.ARMY, People.SCHOLARSHIP, People.HOSTEL, People.NAME_EDUC, People.WHEN_EDUC, People.WHERE_EDUC, People.PHOTO, People.MIDDLE_B, People.N_VID_SPORT, People.N_DELA, People.VID_EDU, People.N_FAC, People.KURS, People.N_SPEC, People.N_SPECIALIZ, People.N_PRIKAZ_KURS, People.EDU_WORK, People.D_PRIKAZ_KURS, People.N_FOUND, People.N_PRIKAZ_INCLUDE, People.D_PRIKAZ_INCLUDE, People.N_GROUP, People.STATUS_PEOPLE, People.INC_GROUP, People.ADDRESS, People.DATA_R, People.F_OLD, People.PHONE, People.STATUS_KURS, People.N_ZACHET, Speciality.SPEC, Specializ.SPECIAL, Specializ.SPECIAL_SKLON, Faculty.FAC, Faculty.FAC1, Increment_group.GOD, Increment_group.N_GROUP\
         FROM PEOPLE People INNER JOIN SPECIALITY Speciality ON  (People.N_SPEC = Speciality.N_SPEC) INNER JOIN SPECIALIZ Specializ   ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ)   INNER JOIN FACULTY Faculty\
         ON  (People.N_FAC = Faculty.N_FAC) INNER JOIN INCREMENT_GROUP Increment_group ON  (People.INC_GROUP = Increment_group.INC_GROUP) where (People.STATUS_PEOPLE=1) and (People.INC_GROUP="
                + VarToStr (i_gr) + ")\
         and (People.N_FAC=" + AnsiString (nom_fac) +
                ") Order by      People.N_SPECIALIZ");
            DM3 -> People_SvodReportFDQuery -> Open ();
            ////////////////////////////////////////////////////////////////
            if (!DM3 -> People_SvodReportFDQuery -> RecordCount) {
                ShowMessage ("��� ������ �� ������ ����������!");
                return;
            }

            else // ������ ��������� ���� ��� ������� � Excel
            { // ---------------------------------------------
                //////��� ������� ���������
                if (Vibor == 1) {
                    ////////�������� � ��������� ��������
                    /////Mas_Spec ();
                    DM3 -> Name_SpecFDQuery -> Close ();
                    DM3 -> Name_SpecFDQuery -> ParamByName ("INC_GROUP") -> Value =
                        search_increment_group (Svod_Ved -> Edit2 -> Text,
                        Svod_Ved -> ComboBox2 -> ItemIndex); ;
                    DM3 -> Name_SpecFDQuery -> ParamByName ("N_FAC") -> Value =
                        nom_fac;
                    DM3 -> Name_SpecFDQuery -> Open ();

                    // ����������  ����� �����
                    XLApp = Variant::CreateObject ("Excel.Application");
                    XLBook = NewBook (XLApp);

                    //////////////
                    TDateTime data;
                    ut_god = DateToStr (data.CurrentDate ());
                    // ������� ������� ���
                    // int month=AnsiString (ut_god).SubString (4,2).ToInt ();
                    // if (month>8) ut_god=AnsiString (ut_god).SubString (7,4);
                    // else ut_god=AnsiString (AnsiString (ut_god).SubString (7,4).ToInt ()-1);
                    ut_god = ut_god.SubString (7, 4);

                    // ������������ ������
                    for (int i = 0;
                    i < DM3 -> Name_SpecFDQuery -> RecordCount;
                    i++) // ���� �� ��������������
                    {
                        // ������������ Query �� ��������������
                        DM3 -> People_SvodReport_SpecFDQuery -> Close ();
                        DM3 -> People_SvodReport_SpecFDQuery -> ParamByName ("N_FAC")
                            -> Value = nom_fac;
                        DM3 -> People_SvodReport_SpecFDQuery -> ParamByName
                            ("INC_GROUP") -> Value = i_gr;
                        DM3 -> People_SvodReport_SpecFDQuery -> ParamByName
                            ("N_SPECIALIZ") -> Value =
                            DM3 -> Name_SpecFDQueryN_SPECIALIZ -> Value;
                        DM3 -> People_SvodReport_SpecFDQuery -> Open ();

                        XLSh = NewSheet1 (XLApp);
                        AnsiString name_spec =
                            DM3 -> People_SvodReport_SpecFDQuerySPECIAL -> Value;
                        if (name_spec.Length () > 24)
                        { // if ����� �������� ������� �� ������� �� �� 30 ��������
                            NameSheet1 (XLSh,
                                Edit2 -> Text + "��. " + name_spec.SubString
                                (1, 20));
                            SelectSheet (XLBook,
                                Edit2 -> Text + "��. " + name_spec.SubString
                                (1, 20));
                        } // end if ����� �������� ������� �� ������� �� �� 30 ��������
                        else { // else �� �������� 30 �������� - ��������� ��� ���������
                            NameSheet1 (XLSh, Edit2 -> Text + "��. " + name_spec);
                            SelectSheet (XLBook,
                                Edit2 -> Text + "��. " + name_spec);
                        }

                        SetOrientatSheet (XLSh, 2);

                        // ��������� ��������� �����
                        Variant Rang1 = Range2 (XLSh, "A1:Z1");
                        // ������������ �� �����������
                        HorizontalAlign (Rang1, 3);
                        // ��������� ������
                        CellFont ("Arial", 12, true, false, 1, 0, Rang1);
                        // ����������� �����
                        M1 (Rang1);

                        // ��������� �����
                        // -------  �������� �� ��������� ���� 5 (��������) ��� 6 (��������)
                        kurs_text = (Edit2 -> Text).SubString (2, 1);
                        // �������� ����� �����
                        if ( (ComboBox2 -> ItemIndex == 0 && kurs_text == 5) ||
                            (ComboBox2 -> ItemIndex == 1 && kurs_text == 6))
                        { // if ��������� ����
                            CellValue ("������� ��������� ���������� ����� " +
                                ut_god + " ����", 1, 1);
                        } // end if ��������� ����
                        else { // else ������ �����
                            CellValue (
                                "������� ��������� �� ��������� �� ��������� �� " +
                                ut_god + " ���", 1, 1);
                        } // end else ������ �����
                        // -------
                        // ����������� ����� �������� � �������� ����������
                        AnsiString St = "";
                        if (ComboBox2 -> Text == "�������")
                            St = "�������� ��������� ";
                        if (ComboBox2 -> Text == "�������")
                            St = "�������� ��������� ";
                        switch (nom_fac) {
                        case 1:
                            St = St +
                                "���������-��������������� ���������� ���������� ��� � ����������� ";
                            break;
                        case 2:
                            St = St +
                                "���������-��������������� ���������� �������� ����� ������ ";
                            break;
                        case 3:
                            St = St +
                                "���������� ��������������� ���������� �������� � ������� ";
                            break;
                        case 4:
                            St = St + "��������� ������� ";
                            break;
                        }
                        Rang1 = Range2 (XLSh, "A2:Z2");
                        CellFont ("Arial", 12, true, false, 1, 0, Rang1);
                        HorizontalAlign (Rang1, 3);
                        M1 (Rang1);
                        CellValue (St, 1, 2);

                        Rang1 = Range2 (XLSh, "A3:Z3");
                        CellFont ("Arial", 12, true, false, 1, 0, Rang1);
                        HorizontalAlign (Rang1, 3);
                        M1 (Rang1);
                        St = Edit2 -> Text + " ������. ������������� - " +
                            DM3 -> People_SvodReport_SpecFDQuerySPECIAL -> Value;
                        CellValue (St, 1, 3);
                        // �����

                        Rang1 = Range2 (XLSh, "A5:A7");
                        CellValue ("� �/�", 1, 5);
                        M1 (Rang1);
                        AutoFitColumn (XLSh, 1);
                        HorizontalAlign (Rang1, 3);
                        VerticalAlign (Rang1, 2);

                        Rang1 = Range2 (XLSh, "B5:B7");
                        CellValue ("�.�.�.", 2, 5);
                        M1 (Rang1);
                        VerticalAlign (Rang1, 2);
                        HorizontalAlign (Rang1, 3);
                        // AutoFitColumn (XLSh,2);
                        // ���������� ����� ��� ���������
                        BorderCell (1, 5, 1, 2);
                        BorderCell (2, 5, 1, 2);
                        BorderCell (1, 6, 1, 2);
                        BorderCell (2, 6, 1, 2);
                        BorderCell (1, 7, 1, 2);
                        BorderCell (2, 7, 1, 2);
                        // ��������� � ��������� ������������ ������� ��������� (���. ����)
                        Mas_Predmet (DM3 -> People_SvodReport_SpecFDQueryKURS -> 
                            Value, DM3 -> People_SvodReport_SpecFDQueryVID_EDU -> 
                            Value, DM3 -> People_SvodReport_SpecFDQueryN_SPECIALIZ
                            -> Value);

                        // ������ � Excel ���������
                        for (int j = 0; j < kol_predmet; j++) {
                            DM3 -> Name_PredmetFDQuery -> Close ();
                            DM3 -> Name_PredmetFDQuery -> ParamByName ("N_OBJECT")
                                -> Value = predmet1[j];
                            DM3 -> Name_PredmetFDQuery -> Open ();
                            CellValue (DM3 -> Name_PredmetFDQueryNAME_OBJECT -> 
                                Value, 3 + j, 6);
                            BorderCell (3 + j, 6, 1, 2);
                            CellOrient (3 + j, 6, 90);
                            AutoFitColumn (XLSh, 3 + j);
                            CellValue (IntToStr (j + 1), 3 + j, 7);
                            BorderCell (3 + j, 7, 1, 2);
                            BorderCell (3 + j, 5, 1, 2);

                        }
                        Variant C1 = SelectCell (3, 5);
                        Variant C2 = SelectCell (2 + kol_predmet, 5);
                        Rang1 = Range_Range (XLSh, C1, C2);
                        CellValue ("��������", 3, 5);
                        M1 (Rang1);
                        HorizontalAlign (Rang1, 3);

                        ////�� �����
                        DM3 -> People_SvodReport_SpecFDQuery -> First ();
                        for (int j = 1;
                        j <= DM3 -> People_SvodReport_SpecFDQuery -> 
                            RecordCount; j++) {
                            // ��������� �����
                            BorderCell (1, j + 7, 1, 2);
                            Variant C1 = SelectCell (1, j + 7);
                            Variant C2 = SelectCell (1, j + 7);
                            Rang1 = Range_Range (XLSh, C1, C2);
                            CellValue (IntToStr (j), 1, j + 7);
                            VerticalAlign (Rang1, 2);
                            AutoFitColumn (XLSh, 1);
                            // �������
                            BorderCell (2, j + 7, 1, 2);
                            C1 = SelectCell (2, j + 7);
                            C2 = SelectCell (2, j + 7);
                            Rang1 = Range_Range (XLSh, C1, C2);
                            CellValue (DM3 -> People_SvodReport_SpecFDQueryFAM -> 
                                Value + " " +
                                DM3 -> People_SvodReport_SpecFDQueryNAME -> Value +
                                " " + DM3 -> People_SvodReport_SpecFDQueryOTCH -> 
                                Value, 2, j + 7);
                            VerticalAlign (Rang1, 2);
                            AutoFitColumn (XLSh, 2);
                            W1 (Rang1);

                            // ���������� �� ���������
                            ///�������� �������� ������� �� ���� �������
                            for (int jj = 0; jj < kol_predmet; jj++) {
                                DM3 -> Detail_Svod_RealFDQuery -> Close ();
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName
                                    ("N_OBJECT") -> Value = predmet1[jj];
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName
                                    ("NOMER") -> Value =
                                    DM3 -> People_SvodReport_SpecFDQueryNOMER -> 
                                    Value;
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName ("FAC")
                                    -> Value = nom_fac;
                                DM3 -> Detail_Svod_RealFDQuery -> Open ();
                                DM3 -> Detail_Svod_RealFDQuery -> Last ();
                                AnsiString St = "";
                                /*
                                 switch (DM3 -> Detail_Svod_RealRESULT -> Value)
                                 {
                                 case 1 :  St="���";
                                 break;
                                 case 3 :  St="3";
                                 break;
                                 case 4 :  St="4";
                                 break;
                                 case 5 :  St="5";
                                 break;
                                 case 7 :  St="";
                                 break;
                                 } */

                             /*    // --------����� ����� ��� ����������� ������� ������
                                int ball_baza =
                                    ball_int (syst_ball,
                                    DM3 -> Detail_Svod_RealFDQueryRESULT -> Value);
                                if (ball_baza > 10)
                                { // if �������� �� ����������� ����� �� ������������� �������
                                    St = IntToStr (ball_baza - 10);

                                } // end if �������� �� ����������� ����� �� ������������� �������
                                else { // else �� ����������� ����� �� ����������� �������
                                    switch (ball_baza)
                                    { // switch ����� ����������� �������
                                    case 0:
                                        St = "";
                                        // ������ ������ � ��� ������ ����� �� ����������� ������
                                        break;
                                    case 1:
                                        St = "���"; // �����
                                        break;
                                    case 7:
                                        St = ""; // ����������
                                        break;
                                    case 9:
                                        St = "+"; // ���������
                                        break;
                                    default:
                                        St = IntToStr (ball_baza);
                                        // ����� 2,3,4,5 �������������
                                    } // end switch ����� ����������� �������
                                } // end else �� ����������� ����� �� ����������� �������
                                // -------
                                if (St == "���" || St == "��") {
                                    CellValue (St, 3 + jj, j + 7);
                                    CellOrient (3 + jj, j + 7, 90);
                                    BorderCell (3 + jj, j + 7, 1, 2);
                                }
                                else {
                                    CellValue (St, 3 + jj, j + 7);
                                    BorderCell (3 + jj, j + 7, 1, 2);
                                }
                            } // for �� ���������
                            ///////////////////////////
                            // ����� ���� ���������� ������
                            DM3 -> People_SvodReport_SpecFDQuery -> Next ();
                        } // for �� �����
                        ///////�������� Query � ����������
                        // �������� �������� ��� � �������
                        delete[]God_ob;
                        delete[]predmet1;
                        DM3 -> Name_SpecFDQuery -> Next ();
                    } // ���� �� ��������������

                    AnsiString name_f; // �������� ����� � Excel

                    if ( (ComboBox2 -> ItemIndex == 0 && kurs_text == 5) ||
                        (ComboBox2 -> ItemIndex == 1 && kurs_text == 6))
                    { // if ��������� ����
                        name_f = "������� ��������� ������� " +
                            DM2 -> FacultyFDTable -> Lookup ("N_FAC", nom_fac,
                        "FAC1") + " " + Edit2 -> Text + " �� " + ut_god +
                            " ����.xls";
                    } // end if ��������� ����
                    else { // else ������ �����
                        name_f = "������� ��������� �� ��������� " +
                            DM2 -> FacultyFDTable -> Lookup ("N_FAC", nom_fac,
                        "FAC1") + " " + Edit2 -> Text + " �� �� " + ut_god +
                            " ���.xls";
                    } // end else ������ �����

                    Variant WorkSaveAs =
                        SaveBookAs (XLBook, "d:\\��� ���������\\" + name_f);
                    OVisible (XLApp); // �������� �������
                    // XLApp = Unassigned;
                    // �������� ������� �������������
                    // delete[] Spec;

                    DM3 -> People_SvodReportFDQuery -> Close ();
                } // if  Vibor ==1
                //////////����� ��� ������� ���������
                /////////////////////////////////////////////////
                ///////////////////��� ������� �� �������

                ///----������� � �������

                if (Vibor == 2) {
                    // ���������� � MyList �����
                    AnsiString Str_Fam = "";
                    // ���������� ��� ���������� ����� � ��������� ��� �������
                    // ������������ �������� �������
                    AnsiString *mas_stud[3];
                    // ������ ������� � ������� ���������
                    for (int i = 0; i < 3; i++)
                        mas_stud[i] =
                            new AnsiString
                            [DM3 -> People_SvodReportFDQuery -> RecordCount];
                    //////////////////////////////////////////////////////////////////////////
                    DM3 -> People_SvodReportFDQuery -> First ();

                    // ��� ���������
                    for (int i = 0;
                    i <= DM3 -> People_SvodReportFDQuery -> RecordCount - 1; i++) {
                        mas_stud[0][i] =
                            DM3 -> People_SvodReportFDQueryFAM -> Value + " " +
                            DM3 -> People_SvodReportFDQueryNAME -> Value + " " +
                            DM3 -> People_SvodReportFDQueryOTCH -> Value;
                        MyList1 -> SourceList -> Add (mas_stud[0][i]);
                        mas_stud[1][i] =
                            AnsiString (DM3 -> People_SvodReportFDQueryNOMER
                            -> Value);
                        mas_stud[2][i] =
                            DM3 -> People_SvodReportFDQueryFAM -> Value;

                        DM3 -> People_SvodReportFDQuery -> Next ();
                    } // for

                    if (DataModule2 -> printdlg == true) {
                        AnsiString Str_Nomer = "";
                        for (int i = 0; i <= MyList1 -> FOutList -> Count - 1; i++)
                        {
                            for (int j = 0;
                            j <= MyList1 -> SourceList -> Count - 1; j++) {
                                if (mas_stud[0][j]
                                    == MyList1 -> FOutList -> Strings[i]) {
                                    Str_Nomer += mas_stud[1][j] + ",";
                                    // ���������� ����� ��������
                                    Str_Fam += mas_stud[2][j] + ",";
                                    // ���������� ������� ���������
                                    j = MyList1 -> SourceList -> Count - 1;
                                    // ���� ����� �� ������ �� �����
                                }
                            } // 2-�� for
                        } // 1-�� for

                        Str_Nomer.SetLength (Str_Nomer.Length () - 1);
                        // ������������ Query ��� ������
                        DM3 -> People_SvodReportFDQuery -> Close ();
                        DM3 -> People_SvodReportFDQuery -> SQL -> Clear ();
                        DM3 -> People_SvodReportFDQuery -> SQL -> Add ("SELECT People.NOMER, People.FAM, People.NAME, People.OTCH, People.POL, People.PLACE_R, People.NAZ, People.MARIAGE, People.N_CHILD, People.EDUCATION, People.ARMY, People.SCHOLARSHIP, People.HOSTEL, People.NAME_EDUC, People.WHEN_EDUC, People.WHERE_EDUC, People.PHOTO, People.MIDDLE_B, People.N_VID_SPORT, People.N_DELA, People.VID_EDU, People.N_FAC, People.KURS, People.N_SPEC, People.N_SPECIALIZ, People.N_PRIKAZ_KURS, People.EDU_WORK, People.D_PRIKAZ_KURS, People.N_FOUND, People.N_PRIKAZ_INCLUDE, People.D_PRIKAZ_INCLUDE, People.N_GROUP, People.STATUS_PEOPLE, People.INC_GROUP, People.ADDRESS, People.DATA_R, People.F_OLD, People.PHONE, People.STATUS_KURS, People.N_ZACHET, Speciality.SPEC, Specializ.SPECIAL, Specializ.SPECIAL_SKLON, Faculty.FAC, Faculty.FAC1, Increment_group.GOD, Increment_group.N_GROUP\
              FROM PEOPLE People INNER JOIN SPECIALITY Speciality  ON  (People.N_SPEC = Speciality.N_SPEC)INNER JOIN SPECIALIZ Specializ   ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ)    INNER JOIN FACULTY Faculty   ON  (People.N_FAC = Faculty.N_FAC)   INNER JOIN INCREMENT_GROUP Increment_group\
              ON  (People.INC_GROUP = Increment_group.INC_GROUP)where (People.STATUS_PEOPLE=1) and (People.INC_GROUP="
                            + VarToStr (i_gr) + ")\
              and (People.N_FAC=" + AnsiString (nom_fac) +
                            ")and (People.NOMER IN (" + Str_Nomer + "))\
              Order by People.FAM, People.NAME, People.OTCH");
                        DM3 -> People_SvodReportFDQuery -> Open ();
                        /////////////////////////////////////
                        // ������ ������� � Excel ������� � �������
                        // ����������  ����� �����
                        // Variant XLApp, XLSh;
                        XLApp = Variant::CreateObject ("Excel.Application");
                        XLApp.OlePropertyGet ("WorkBooks").OleProcedure ("add");
                        XLSh = XLApp.OlePropertyGet ("WorkSheets", 1);

                        // XLApp = Variant::CreateObject ("Excel.Application");
                        // XLBook=NewBook (XLApp);
                        for (int i = 0;
                        i <= DM3 -> People_SvodReportFDQuery -> RecordCount -
                            1; i++) // ������������ ������ � ����������� �� ���-�� ������!!
                        {
                            XLSh = NewSheet1 (XLApp);
                            NameSheet1 (XLSh,
                                Edit2 -> Text + "��. " +
                                DM3 -> People_SvodReportFDQueryFAM -> Value + " " +
                                IntToStr (i + 1));
                            // SelectSheet (XLBook,Edit2 -> Text+"��. "+DM3 -> People_SvodReportFAM -> Value+" "+IntToStr (i+1));
                            // XLApp.OlePropertyGet ("WorkSheets",Edit2 -> Text+"��. "+DM3 -> People_SvodReportFAM -> Value+" "+IntToStr (i+1)).OleProcedure ("Select");
                            // XLApp.OlePropertyGet ("WorkSheets")
                            XLSh = XLApp.OlePropertyGet ("ActiveSheet");

                            // Sheets ("����1").Select
                            // Sheets.Add
                            // Sheets ("����2").Select
                            // Sheets ("����2").Name = "ggggg"
                            // Sheets ("����1").Select

                            ///������������ ������
                            // ��������� ������ �����
                            Variant Rang1 = Range2 (XLSh, "A1:A1");
                            ColumnWidth (Rang1, 4);
                            Rang1 = Range2 (XLSh, "B1:B1");
                            ColumnWidth (Rang1, 53);
                            Rang1 = Range2 (XLSh, "C1:C1");
                            ColumnWidth (Rang1, 9);
                            Rang1 = Range2 (XLSh, "D1:D1");
                            ColumnWidth (Rang1, 18);

                            // ���������
                            // ��������� ������ �������
                            DM3 -> DiplomFDQuery -> Close ();
                            DM3 -> DiplomFDQuery -> ParamByName ("NOMER") -> Value =
                                DM3 -> People_SvodReportFDQueryNOMER -> Value;
                            DM3 -> DiplomFDQuery -> Open ();

                            // ������ ������
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, 1, false,
                                "TimesNewRoman", 12, true, 3, 0, true, false,
                                "���������� � ������� _____ � _____________" +
                                DM3 -> DiplomFDQueryN_DIPLOM -> Value);

                            // ������ ������
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, 2, false,
                                "TimesNewRoman", 12, true, 3, 0, true, false,
                                "������� �� �������-��������������� ���������");
                            HeightRow (Range2 (XLSh, "2:2"), 24);
                            // ������ ������
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, 3, false,
                                "TimesNewRoman", 12, false, 3, 0, true, false,
                                " (��� ������� ���������������)");

                            // ���������� ������
                            // ����������� ���� ��������
                            AnsiString St1 = "";
                            AnsiString St2 = "";
                            AnsiString St3 = "";
                            AnsiString St4 = "";
                            AnsiString St5 = "";
                            if (DM3 -> People_SvodReportFDQueryPOL -> Value == "�")
                            {
                                St1 = "���������";
                                St2 = "�����";
                                St3 = "���������";
                                St4 = "��������";
                                St5 = "���������";
                            }
                            if (DM3 -> People_SvodReportFDQueryPOL -> Value == "�")
                            {
                                St1 = "��������";
                                St2 = "����";
                                St3 = "�������";
                                St4 = "�������";
                                St5 = "��������";
                            }

                            // ��������� ������ �����
                            //////////////
                            // TDateTime data;
                            // ut_god=data.CurrentDate ();//������� ������� ���
                            // int month=AnsiString (ut_god).SubString (4,2).ToInt ();
                            // if (month>8) ut_god=AnsiString (ut_god).SubString (7,4);
                            // else ut_god=AnsiString (AnsiString (ut_god).SubString (7,4).ToInt ()-1);

                            Mas_God (DM3 -> People_SvodReportFDQueryKURS -> Value);
                            // --------
                            // ����� ������
                            AnsiString St = "      ";
                            // ���������� ������������ ��������� ������� ��� ������� � �������
                            // ���
                            St += DM3 -> People_SvodReportFDQueryFAM -> Value +
                                " " + DM3 -> People_SvodReportFDQueryNAME -> Value +
                                " " + DM3 -> People_SvodReportFDQueryOTCH -> Value;

                            // ���������� ��� ����������� ����� ������ ��� ���
                            int len_St = St.Length ();

                            // ���� ��������
                            St += " �� ����� �������� � ";
                            Variant V =
                                SQLTimeStampToDateTime (DM3 -> 
                                People_SvodReportFDQueryD_PRIKAZ_INCLUDE -> Value
                                );
                            int date_include = V.AsType (varInteger);
                            if (date_include)
                            { // if �������� �� �������� �������� ����
                                if (date_include <= 33844)
                                    // ��� ���� 28.08.1992
                                        St += "����������� ��������������� ������ ��������� �������� ������� ��������� ���������� ��������, ����� ���������  ";

                                if (date_include >
                                    33844 && date_include <= 36966)
                                    // ��� ���� c 28.08.1992  �� 16.03.2001
                                        St += "�������� ����������� ���������� � ������ ���������� ��������, ����� ���������  ";

                                if (date_include >
                                    36966 && date_include <= 37983)
                                    // ��� ���� c 16.03.2001  �� 28.12.2003
                                        St += "����������� ��������������� �������� ���������� ��������, ����� ���������  ";

                                if (date_include > 37983)
                                    // ��� ���� ����� 28.12.2003
                                        St += "����������� ��������������� ������������ ���������� ��������, ����� ���������  ";
                            } // end if �������� �� �������� �������� ����
                            else
                                St += "!!!!!!!! � ��� �� ������� ���� ����������� � ���, ";

                            // ----
                            St += "���������� ����������� \"����������� ��������������� ����������� ���������� ��������\", � ";
                            AnsiString god_postupl = V.AsType (varString);
                            // ���� �������� � ����
                            if (date_include)
                                St += god_postupl.SubString (7, 4) +
                                    " ���� �� " +
                                    IntToStr (StrToInt (God_ob[0]) + 1) + " ��� ";
                            else {
                                St += God_ob
                                    [DM3 -> People_SvodReportFDQueryKURS -> 
                                    Value - 1];
                                St += " ����  �� " +
                                    IntToStr (StrToInt (God_ob[0]) + 1) + " ��� ";
                            }
                            // �������������
                            St += St1 + " ������� ���� �� ������������� \"" +
                                DM3 -> People_SvodReportFDQuerySPEC -> Value;

                            // ������������� ��� ����������� �������������

                            if (DM3 -> People_SvodReportFDQueryN_SPEC -> Value == 1)
                            { // if ������������� ���������� �������� � �����
                                St += "\", ������������� ";
                                St += "\"";
                                if (nom_fac == 1 || nom_fac == 2) {
                                    St += "���������� ������ �� ";
                                }
                                St += DM3 -> 
                                    People_SvodReportFDQuerySPECIAL_SKLON -> 
                                    Value;
                            } // end if ������������� ���������� �������� � �����
                            else { // else ������ ����� �������������
                                St += "\", ����������� ������������� \"";
                                if (DM3 -> People_SvodReportFDQueryN_SPEC -> Value
                                    == 6) { // if  ���������-�������������� ������������
                                    if (DM3 -> People_SvodReportFDQueryN_SPECIALIZ
                                        -> Value != 52 &&
                                        DM3 -> People_SvodReportFDQueryN_SPECIALIZ
                                        -> Value != 56) {
                                        // if 52-���������� ����������, 56 - ���������� ���������

                                        St += "���������� ������ �� ";
                                    }

                                } // end if  ���������-�������������� ������������
                                St += DM3 -> 
                                    People_SvodReportFDQuerySPECIAL_SKLON -> 
                                    Value;
                            } // else ������ ����� �������������

                            // ����� ��������� �������
                            St += "\" � " + St2 +
                                " �������� � ������ �� ��������� �����������:";

                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, 5, false,
                                "TimesNewRoman", 12, false, 6, 1, true,
                                true, St);
                            Rang1 = Range2 (XLSh, "A5:D5");
                            Variant cur = XLSh.OlePropertyGet ("Cells", 5, 1);
                            cur.OlePropertyGet ("Characters", 1, len_St)
                                .OlePropertyGet ("Font").OlePropertySet
                                ("FontStyle", "����������");
                            // ���������� � ���������� ������ � ������� Start ������� Length ������ �����
                            // CellFontChar (1,len_St,"Arial",5,1,XLSh);
                            HeightRow (Rang1, 100); // ��������� ������ ������

                            // ������������ �������� ��������� �� ��������:
                            // ��������, ������
                            // ��������
                            // ��������
                            // ���
                            Mas_Pred (DM3 -> People_SvodReportFDQueryKURS -> Value,
                                DM3 -> People_SvodReportFDQueryVID_EDU -> Value,
                                DM3 -> People_SvodReportFDQueryN_SPECIALIZ
                                -> Value);
                            // ������ ��������� � �����

                            // �����
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 1, 6, true, "Arial",
                                12, true, 3, 2, false, true, "� �/�");
                            Cell_2_Text_Ole (XLApp, XLSh, 2, 2, 6, true, "Arial",
                                12, true, 3, 2, false, false,
                                "������������ ����������");
                            Cell_2_Text_Ole (XLApp, XLSh, 3, 3, 6, true, "Arial",
                                12, true, 3, 2, false, true, "���-�� �����");
                            Cell_2_Text_Ole (XLApp, XLSh, 4, 4, 6, true, "Arial",
                                12, true, 3, 2, false, false, "������");

                            int jj = 0;
                            int kol_spec = 0;
                            // ���������� ��� ����������� ������ � ������� ����������

                            int mas_spec[10];
                            // ������ ��������� � �����
                            for (jj = 0; jj < Count_pred[0]; jj++) {

                                // ������������ ��������
                                DM3 -> Detail_Svod_RealFDQuery -> Close ();
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName
                                    ("N_OBJECT") -> Value = mas_pred[0][jj];
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName
                                    ("NOMER") -> Value =
                                    DM3 -> People_SvodReportFDQueryNOMER -> Value;
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName ("FAC")
                                    -> Value = nom_fac;
                                DM3 -> Detail_Svod_RealFDQuery -> Open ();

                                // ������� ������� ��� ��������� ���������� � ��������� ������

                                /* //��������� ���������� �����
                                 int kol=0;
                                 for (int jjj=0; jjj<DM3 -> Detail_Svod_Real -> RecordCount;jjj++)
                                 {
                                 kol=kol+DM3 -> Detail_Svod_RealCLOCK_PLAN -> Value;
                                 } */
                                /////////////////////////////////////////////////////////////
                                // ������� ���� ���� ��� ��� � �������
                          /*        DM3 -> Name_PredmetFDQuery -> Close ();
                                DM3 -> Name_PredmetFDQuery -> ParamByName
                                    ("N_OBJECT") -> Value = mas_pred[0][jj];
                                DM3 -> Name_PredmetFDQuery -> Open ();

                                if (DM3 -> Detail_Svod_RealFDQuerySPECKURS -> Value
                                    == 1) { // if ��� ��������
                                    mas_spec[kol_spec] =
                                        DM3 -> Name_PredmetFDQueryN_OBJECT -> Value;
                                    kol_spec++;

                                } // end if ��� ��������

                                else { // else ��� �� ��������

                                    // ����������� �����
                                    Cell_2_Text_Ole (XLApp, XLSh, 1, 1,
                                        jj + 7 - kol_spec, true, "Arial", 10,
                                        false, 3, 2, false, false,
                                        IntToStr (jj + 1 - kol_spec));

                                    // �������� ��������
                                    Cell_2_Text_Ole (XLApp, XLSh, 2, 2,
                                        jj + 7 - kol_spec, true, "Arial", 10,
                                        false, 0, 2, false, true,
                                        Text_predmet (DM3 -> 
                                        Name_PredmetFDQueryNAME_OBJECT -> Value,
                                        DM3 -> People_SvodReportFDQueryN_SPECIALIZ
                                        -> Value));

                                    // ���������� �����
                                    Cell_2_Text_Ole (XLApp, XLSh, 3, 3,
                                        jj + 7 - kol_spec, true, "Arial", 10,
                                        false, 3, 2, false, false,
                                        DM3 -> Name_PredmetFDQueryALL_CLOCK_PLAN
                                        -> Value);

                                    // �� ��������� ����� ����� ��������� ������
                                    // ������ �� ��������
                                    DM3 -> Detail_Svod_RealFDQuery -> Last ();
                                    Cell_2_Text_Ole (XLApp, XLSh, 4, 4,
                                        jj + 7 - kol_spec, true, "Arial", 10,
                                        false, 2, 2, false, false,
                                        ball_string (syst_ball,
                                        ball_int (syst_ball,
                                        DM3 -> Detail_Svod_RealFDQueryRESULT -> 
                                        Value), 1));
                                    // CellValue (ball_string (syst_ball,ball_int (syst_ball,DM3 -> Detail_Svod_RealRESULT -> Value), 1),4,jj+7);
                                    // BorderCell (4, jj+7, 1, 2);
                                } // else ��� �� ��������
                            } // for jj ��� ������� ���������

                            jj -= kol_spec;
                            // �������� ���������� ����������, ����� ��� �� ������� � Excel
                            // ������� (��) ��� �������� (�)
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, jj + 8, false,
                                "Arial", 12, false, 0, 2, true, false,
                                " " + St3 + " " +
                                DM3 -> People_SvodReportFDQueryFAM -> Value + " " +
                                DM3 -> People_SvodReportFDQueryNAME -> Value + " " +
                                DM3 -> People_SvodReportFDQueryOTCH -> Value +
                                " " + St1);
                            // jj--;//� ����� � ��������� �������   ������� (��) ��� �������� (�)

                            // ���������   ��� �������� ��������, � ��� �������� ���
                            if (!DM3 -> 
                                Detail_Svod_RealFDQueryVID_EDU_PLAN -> Value)
                                Cell_2_Text_Ole (XLApp, XLSh, 1, 4, jj + 9,
                                false, "Arial", 12, false, 0, 2, true, false,
                                " ���������:");
                            else
                                jj--; // ��������� ���������� �� 1 ��� ��������, ����� �� ������� ���������
                            // ������� ����������
                            for (int k = 0; k < kol_spec; k++) {
                                // ������������ ��������
                                DM3 -> Detail_Svod_RealFDQuery -> Close ();
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName
                                    ("N_OBJECT") -> Value = mas_spec[k];
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName
                                    ("NOMER") -> Value =
                                    DM3 -> People_SvodReportFDQueryNOMER -> Value;
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName ("FAC")
                                    -> Value = nom_fac;
                                DM3 -> Detail_Svod_RealFDQuery -> Open ();
                                /////////////////////////////////////////////////////////////

                                if (!DM3 -> Detail_Svod_RealFDQueryZACH_EXAM
                                    -> Value) {
                                    // if ������� ��� ���� ��������, �������� ������ ������ ���, ��� ��� ���������
                                    if (DM3 -> Detail_Svod_RealFDQuery -> 
                                        RecordCount) { // if ���� ������
                                        // ����������� �����
                                        Cell_2_Text_Ole (XLApp, XLSh, 1, 1,
                                        jj + 10, true, "Arial", 10, false, 3, 2,
                                        false, false, IntToStr (k + 1));
                                        // �������� ��������
                                        Cell_2_Text_Ole (XLApp, XLSh, 2, 2,
                                        jj + 10, true, "Arial", 10, false, 0, 2,
                                        false, true,
                                        Text_predmet (DM3 -> 
                                        Detail_Svod_RealFDQueryNAME_OBJECT -> 
                                        Value, DM3 -> 
                                        People_SvodReportFDQueryN_SPECIALIZ -> 
                                        Value));
                                        // ���������� �����
                                        int sum_clock = 0;
                                        for (int s = 0;
                                        s < DM3 -> Detail_Svod_RealFDQuery -> 
                                        RecordCount; s++)
                                        { // for ��������� ���������� �����
                                        sum_clock +=
                                        DM3 -> Detail_Svod_RealFDQueryCLOCK_PLAN -> 
                                        Value;
                                        } // end for ��������� ���������� �����

                                        Cell_2_Text_Ole (XLApp, XLSh, 3, 3,
                                        jj + 10, true, "Arial", 10, false, 3, 2,
                                        false, false, sum_clock);
                                        // ������
                                        Cell_2_Text_Ole (XLApp, XLSh, 4, 4,
                                        jj + 10, true, "Arial", 10, false, 2, 2,
                                        false, false,
                                        ball_string (syst_ball,
                                        ball_int (syst_ball,
                                        DM3 -> Detail_Svod_RealFDQueryRESULT -> 
                                        Value), 1));

                                        jj++; // ������� �� ��������� ����
                                    } // end if ���� ������

                                } // end if ������� ��� ���� ��������, �������� ������ ������ ���, ��� ��� ���������
                                else { // else ������� ����.����
                                    // ������� ���� ���� ��� ��� � �������
                                    DM3 -> Name_PredmetFDQuery -> Close ();
                                    DM3 -> Name_PredmetFDQuery -> ParamByName
                                        ("N_OBJECT") -> Value = mas_spec[k];
                                    DM3 -> Name_PredmetFDQuery -> Open ();

                                    // ����������� �����
                                    Cell_2_Text_Ole (XLApp, XLSh, 1, 1, jj + 10,
                                        true, "Arial", 10, false, 3, 2, false,
                                        false, IntToStr (k + 1));
                                    // �������� ��������
                                    Cell_2_Text_Ole (XLApp, XLSh, 2, 2, jj + 10,
                                        true, "Arial", 10, false, 0, 2, false,
                                        true, Text_predmet
                                        (DM3 -> Name_PredmetFDQueryNAME_OBJECT -> 
                                        Value, DM3 -> 
                                        People_SvodReportFDQueryN_SPECIALIZ -> 
                                        Value));

                                    // ���������� �����
                                    Cell_2_Text_Ole (XLApp, XLSh, 3, 3, jj + 10,
                                        true, "Arial", 10, false, 3, 2, false,
                                        false, DM3 -> 
                                        Name_PredmetFDQueryALL_CLOCK_PLAN -> Value
                                        );

                                    // ������
                                    DM3 -> Detail_Svod_RealFDQuery -> Last ();
                                    Cell_2_Text_Ole (XLApp, XLSh, 4, 4, jj + 10,
                                        true, "Arial", 10, false, 2, 2, false,
                                        false, ball_string (syst_ball,
                                        ball_int (syst_ball,
                                        DM3 -> Detail_Svod_RealFDQueryRESULT -> 
                                        Value), 1));
                                    // CellValue (ball_string (syst_ball,ball_int (syst_ball,DM3 -> Detail_Svod_RealRESULT -> Value), 1),4,jj+9);
                                    // BorderCell (4, jj+9, 1, 2);
                                    jj++; // ������� �� ��������� ����
                                } // end else ������� ����.����
                            } // for �� ��������
                            ///////////////////////////////////////////////////////////////////

                            // �������� ������
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, jj + 10, false,
                                "Arial", 12, false, 0, 2, true, false,
                                " �������� ������:");

                            // ������� ��������
                            for (int jjj = 0; jjj < Count_pred[1]; jjj++) {
                                // ����������� �����
                                Cell_2_Text_Ole (XLApp, XLSh, 1, 1, jj + 11,
                                    true, "Arial", 10, false, 3, 2, false,
                                    false, IntToStr (jjj + 1));

                                // ������������ ��������
                                DM3 -> Detail_Svod_RealFDQuery -> Close ();
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName
                                    ("N_OBJECT") -> Value = mas_pred[1][jjj];
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName
                                    ("NOMER") -> Value =
                                    DM3 -> People_SvodReportFDQueryNOMER -> Value;
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName ("FAC")
                                    -> Value = nom_fac;
                                DM3 -> Detail_Svod_RealFDQuery -> Open ();
                                /////////////////////////////////////////////////////////////
                                // ������� ���� ���� ��� ��� � �������
                                DM3 -> Name_PredmetFDQuery -> Close ();
                                DM3 -> Name_PredmetFDQuery -> ParamByName
                                    ("N_OBJECT") -> Value = mas_pred[1][jjj];
                                DM3 -> Name_PredmetFDQuery -> Open ();

                                // �������� ��������
                                Cell_2_Text_Ole (XLApp, XLSh, 2, 3, jj + 11,
                                    true, "Arial", 10, false, 0, 2, true, true,
                                    Text_predmet (DM3 -> 
                                    Name_PredmetFDQueryNAME_OBJECT -> Value,
                                    DM3 -> People_SvodReportFDQueryN_SPECIALIZ
                                    -> Value));

                                // ������
                                DM3 -> Detail_Svod_RealFDQuery -> Last ();
                                Cell_2_Text_Ole (XLApp, XLSh, 4, 4, jj + 11,
                                    true, "Arial", 10, false, 2, 2, false,
                                    false, ball_string (syst_ball,
                                    ball_int (syst_ball,
                                    DM3 -> Detail_Svod_RealFDQueryRESULT -> 
                                    Value), 1));
                                // CellValue (ball_string (syst_ball,ball_int (syst_ball,DM3 -> Detail_Svod_RealRESULT -> Value), 1),4,jj+9);
                                // BorderCell (4, jj+9, 1, 2);
                                jj++; // ������� �� ��������� ����
                            } // for �� ��������
                            ///////////////////////////////////////////////////////////////////

                            // ��������
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, jj + 11, false,
                                "Arial", 12, false, 0, 2, true, false,
                                " ��������:");

                            // ������� ��������
                            for (int jjj = 0; jjj < Count_pred[2]; jjj++) {
                                // ����������� �����
                                Cell_2_Text_Ole (XLApp, XLSh, 1, 1, jj + 12,
                                    true, "Arial", 10, false, 3, 2, false,
                                    false, IntToStr (jjj + 1));

                                // ������������ ��������
                                DM3 -> Detail_Svod_RealFDQuery -> Close ();
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName
                                    ("N_OBJECT") -> Value = mas_pred[2][jjj];
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName
                                    ("NOMER") -> Value =
                                    DM3 -> People_SvodReportFDQueryNOMER -> Value;
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName ("FAC")
                                    -> Value = nom_fac;
                                DM3 -> Detail_Svod_RealFDQuery -> Open ();

                                // ��������� ���������� ������
                                int kol = 0;
                                /* for (int jjjj=0; jjjj<DM3 -> Detail_Svod_Real -> RecordCount;jjjj++)
                                 {
                                 kol=kol+DM3 -> Detail_Svod_RealCLOCK_PLAN -> Value;
                                 } */

                                /////////////////////////////////////////////////////////////
                           /*        DM3 -> Name_PredmetFDQuery -> Close ();
                                DM3 -> Name_PredmetFDQuery -> ParamByName
                                    ("N_OBJECT") -> Value = mas_pred[2][jjj];
                                DM3 -> Name_PredmetFDQuery -> Open ();

                                // ���������� �����
                                kol = DM3 -> 
                                    Name_PredmetFDQueryALL_CLOCK_PLAN -> Value;
                                // ����� �� �������, ��� � ��� ��������

                                // �������� ��������
                                Cell_2_Text_Ole (XLApp, XLSh, 2, 2, jj + 12,
                                    true, "Arial", 10, false, 0, 2, false, true,
                                    Text_predmet (DM3 -> 
                                    Name_PredmetFDQueryNAME_OBJECT -> Value,
                                    DM3 -> People_SvodReportFDQueryN_SPECIALIZ
                                    -> Value));

                                // ���������� ������
                                AnsiString nedel = "";
                                switch (kol)
                                { // switch ���������� �� ���������� �����
                                case 1:
                                    nedel = " ������";
                                    break;
                                case 2:
                                    nedel = " ������";
                                    break;
                                case 3:
                                    nedel = " ������";
                                    break;
                                case 4:
                                    nedel = " ������";
                                    break;
                                default:
                                    nedel = " ������";
                                    break;

                                } // switch ���������� �� ���������� �����
                                Cell_2_Text_Ole (XLApp, XLSh, 3, 3, jj + 12,
                                    true, "Arial", 10, false, 3, 2, false,
                                    false, IntToStr (kol) + nedel);

                                // ������ �� ��������
                                DM3 -> Detail_Svod_RealFDQuery -> Last ();
                                Cell_2_Text_Ole (XLApp, XLSh, 4, 4, jj + 12,
                                    true, "Arial", 10, false, 2, 2, false,
                                    false, ball_string (syst_ball,
                                    ball_int (syst_ball,
                                    DM3 -> Detail_Svod_RealFDQueryRESULT -> 
                                    Value), 1));
                                // CellValue (ball_string (syst_ball,ball_int (syst_ball,DM3 -> Detail_Svod_RealRESULT -> Value), 1),4,jj+10);
                                // BorderCell (4, jj+10, 1, 2);
                                jj++; // ������� �� ��������� ����

                            } // for �� ��������
                            /////////////////////////////////////////////////////////////////////
                            // ���. ��������
                            /////////////////////////////////////////////////////////////////////

                            // DM3 -> GEK_Vipiska -> Close ();
                            // DM3 -> GEK_Vipiska -> ParamByName ("NOMER") -> Value=DM3 -> People_SvodReportNOMER -> Value;
                            // DM3 -> GEK_Vipiska -> Open ();

                            // �������� ���������
                            // if (DM3 -> GEK_Vipiska -> RecordCount!=0)
                            // { // if  DM3 -> GEK_Vipiska -> RecordCount!=0

                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, jj + 13, false,
                                "Arial", 12, false, 0, 2, true, false,
                                " ��������������� ��������:");
                            AnsiString thema, ochenka;
                            thema = "";
                            ochenka = "";
                            // ������� ���.
                            for (int jjj = 0; jjj < Count_pred[3]; jjj++)
                            { // for �� ���
                                DM3 -> Name_PredmetFDQuery -> Close ();
                                DM3 -> Name_PredmetFDQuery -> ParamByName
                                    ("N_OBJECT") -> Value = mas_pred[3][jjj];
                                DM3 -> Name_PredmetFDQuery -> Open ();

                                // ����������� �����
                                Cell_2_Text_Ole (XLApp, XLSh, 1, 1, jj + 14,
                                    true, "Arial", 10, false, 3, 2, false,
                                    false, IntToStr (jjj + 1));

                                // ����������� �������� ��������
                                Cell_2_Text_Ole (XLApp, XLSh, 2, 3, jj + 14,
                                    true, "Arial", 10, false, 0, 2, true, true,
                                    Text_predmet (DM3 -> 
                                    Name_PredmetFDQueryNAME_OBJECT -> Value,
                                    DM3 -> People_SvodReportFDQueryN_SPECIALIZ
                                    -> Value));
                                Variant v1, v2;
                                // v1-������, v2-�������� � ������
                                v1 = XLSh.OlePropertyGet ("Cells",
                                    jj + 14, 2); // ��������� ������
                                v2 = v1.OlePropertyGet ("Value");
                                // ����� �������� �� ������
                                AnsiString v2_count = v2.AsType (varString);
                                // ��������� �������� � AnsiString
                                if (v2_count.Length () > 65) // ��������� �����
                                { // if ������� �����, ������� �� ������ � ���� ������
                                    // ����������� ������ ������
                                    v1.OlePropertySet ("RowHeight", 27);

                                } // end if ������� �����, ������� �� ������ � ���� ������
                                // ��������� ������
                                Cell_2_Text_Ole (XLApp, XLSh, 4, 4, jj + 14,
                                    true, "Arial", 10, false, 2, 2, false,
                                    false, " ");

                                // ������ �� ����

                                DM3 -> GEK_VipiskaFDQuery -> Close ();
                                DM3 -> GEK_VipiskaFDQuery -> ParamByName ("NOMER")
                                    -> Value =
                                    DM3 -> People_SvodReportFDQueryNOMER -> Value;
                                DM3 -> GEK_VipiskaFDQuery -> ParamByName ("N_OBJECT")
                                    -> Value =
                                    DM3 -> Name_PredmetFDQueryN_OBJECT -> Value;
                                DM3 -> GEK_VipiskaFDQuery -> Open ();
                                if (!DM3 -> GEK_VipiskaFDQuery -> RecordCount)
                                { // if ��� ������� �� ������� ��������

                                    Cell_2_Text_Ole (XLApp, XLSh, 4, 4, jj + 14,
                                        true, "Arial", 10, false, 2, 2, false,
                                        false, " ");

                                } // end if ��� ������� �� ������� ��������
                                else { // else ���� ������
                                    if (DM3 -> GEK_VipiskaFDQueryTHEME -> Value
                                        == "") {
                                        // if  DM3 -> GEK_VipiskaTHEME -> Value=""
                                        Cell_2_Text_Ole (XLApp, XLSh, 4, 4,
                                        jj + 14, true, "Arial", 10, false, 2, 2,
                                        false, false,
                                        ball_string (syst_ball,
                                        ball_int (syst_ball,
                                        DM3 -> GEK_VipiskaFDQueryBALL_GEK -> 
                                        Value), 1));

                                    } // end if  DM3 -> GEK_VipiskaTHEME -> Value=""
                                    else { // else DM3 -> GEK_VipiskaTHEME -> Value!=""
                                        thema = DM3 -> 
                                        GEK_VipiskaFDQueryTHEME -> Value;
                                        ochenka =
                                        ball_string (syst_ball,
                                        ball_int (syst_ball,
                                        DM3 -> GEK_VipiskaFDQueryBALL_GEK -> 
                                        Value), 1);
                                    } // end else DM3 -> GEK_VipiskaTHEME -> Value!=""
                                } // end else ���� ������
                                jj++; // ������� �� ��������� ����

                            } // end for �� ���
                            // } //end if  DM3 -> GEK_Vipiska -> RecordCount!=0

                            ///////////////////////////////////////////////////////////////////
                            // ������
                            // DM3 -> GEK_Vipiska -> First ();
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, jj + 15, false,
                                "Arial", 12, false, 0, 2, true, false,
                                St5 + " ��������� ������ �� ����:");
                            // ��� �������
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, jj + 16, false,
                                "Arial", 12, false, 0, 0, true, false,
                                "_____________________________________________________________________________________");
                            Cell_2_Text_Ole (XLSh, XLApp, 1, 4, jj + 17, false,
                                "Arial", 12, false, 0, 0, false, false,
                                "� " + St4 + " � ������� _______________ ");

                            // for (int jjj=0; jjj< DM3 -> GEK_Vipiska -> RecordCount; jjj++)
                            // {
                            if (thema != "")
                                // (DM3 -> GEK_VipiskaTHEME -> Value!="")
                            {
                                // ��������� ���� �������
                                // Cell_2_Text_Ole (XLApp,XLSh,1,4,jj+16,false,"Arial",12,false,0,2,true,true,DM3 -> GEK_VipiskaTHEME -> Value);
                                Cell_2_Text_Ole (XLApp, XLSh, 1, 4, jj + 16,
                                    false, "Arial", 12, false, 0, 2, true, true,
                                    "\"" + thema + "\"");
                                // �������� �������� ��� ��������� ������ ������
                                Rang1 = Range2 (XLSh, "A" + IntToStr (jj + 16));
                                HeightRow (Rang1, (40));
                                // Selection.Font.Italic = True
                                // Variant cur=XLSh.OlePropertyGet ("Cells",5,1);
                                // cur.OlePropertyGet ("Characters",1,len_St).OlePropertyGet ("Font").OlePropertySet ("FontStyle","����������");
                                // Selection.Font.Underline = xlUnderlineStyleSingle
                                Rang1.OlePropertyGet ("Font").OlePropertySet
                                    ("Italic", True);
                                Rang1.OlePropertyGet ("Font").OlePropertySet
                                    ("Underline", 1);
                                // ��������� ������
                                AnsiString two_str = "� " + St4 + " � ������� ";
                                int dlina = two_str.Length ();
                                Rang1 = Range2 (XLSh, "A" + IntToStr (jj + 17));
                                // Cell_2_Text_Ole (XLApp,XLSh,1,4,jj+17,false,"Arial",12,false,0,2,true,false,"� ������� "+ball_string (syst_ball,ball_int (syst_ball,DM3 -> GEK_VipiskaBALL_GEK -> Value), 1));
                                Cell_2_Text_Ole (XLApp, XLSh, 1, 4, jj + 17,
                                    false, "Arial", 12, false, 0, 2, true,
                                    false, two_str + ochenka + ".");
                                Rang1.OlePropertyGet ("Characters", dlina,
                                    ochenka.Length () + 1).OlePropertyGet ("Font")
                                    .OlePropertySet ("Italic", True);
                                Rang1.OlePropertyGet ("Characters", dlina,
                                    ochenka.Length () + 1).OlePropertyGet ("Font")
                                    .OlePropertySet ("Underline", 1);
                            } // if
                            // DM3 -> GEK_Vipiska -> Next ();
                            // } //For

                            Cell_2_Text_Ole (XLApp, XLSh, 1, 1, jj + 22, false,
                                "Arial", 12, true, 0, 0, false, false, "�.�. ");
                            AnsiString data_full =
                                DateTimePicker1 -> Date.DateString ();
                            AnsiString month = data_full.SubString (4, 2);
                            switch (StrToInt (month)) { // switch
                            case 1:
                                month = " ������ ";
                                break;
                            case 2:
                                month = " ������� ";
                                break;
                            case 3:
                                month = " ����� ";
                                break;
                            case 4:
                                month = " ������ ";
                                break;
                            case 5:
                                month = " ��� ";
                                break;
                            case 6:
                                month = " ���� ";
                                break;
                            case 7:
                                month = " ���� ";
                                break;
                            case 8:
                                month = " ������� ";
                                break;
                            case 9:
                                month = " �������� ";
                                break;
                            case 10:
                                month = " ������� ";
                                break;
                            case 11:
                                month = " ������ ";
                                break;
                            case 12:
                                month = " ������� ";
                                break;
                            } // end switch
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 1, jj + 26, false,
                                "Arial", 10, false, 0, 0, false, false,
                                "�.����� \"" + data_full.SubString (1, 2) +
                                "\"" + month + data_full.SubString (7, 4));
                            Cell_2_Text_Ole (XLApp, XLSh, 2, 2, jj + 20, false,
                                "Arial", 12, true, 0, 0, false, false,
                                "              ������ ");
                            Cell_2_Text_Ole (XLApp, XLSh, 2, 2, jj + 22, false,
                                "Arial", 12, true, 0, 0, false, false,
                                "              ����� ");
                            Cell_2_Text_Ole (XLApp, XLSh, 2, 2, jj + 24, false,
                                "Arial", 12, true, 0, 0, false, false,
                                "              ��������� ");
                            Cell_2_Text_Ole (XLApp, XLSh, 3, 3, jj + 26, false,
                                "Arial", 10, false, 0, 0, false, false,
                                "��������������� �_________ ");

                            // ������ �������������� ������������ ��������
                            XLSh.OlePropertyGet ("PageSetup").OlePropertySet
                                ("CenterHorizontally", true);
                            XLSh.OlePropertyGet ("PageSetup").OlePropertySet
                                ("Zoom", false);
                            XLSh.OlePropertyGet ("PageSetup").OlePropertySet
                                ("FitToPagesWide", 1);
                            XLSh.OlePropertyGet ("PageSetup").OlePropertySet
                                ("FitToPagesTall", 2);

                            DM3 -> People_SvodReportFDQuery -> Next ();
                        } // for  i<DM3 -> People_SvodReportFDQuery-1

                    } // if MyList1 -> Execute (MyList1)

                    // AnsiString name_f="������� � ������� "+DM2 -> FacultyTable -> Lookup ("N_FAC",nom_fac,"FAC1")+" "+Edit2 -> Text+"�� "+Str_Fam.SubString (1,Str_Fam.Length ()-1)+".xls";
                    // Variant WorkSaveAs=SaveBookAs (XLBook,"c:\\��� ���������\\"+name_f);
                    // OVisible (XLApp); //�������� �������

                    AnsiString name_f =
                        "d:\\��� ���������\\������� � ������� " +
                        DM2 -> FacultyFDTable -> Lookup ("N_FAC", nom_fac, "FAC1") +
                        " " + Edit2 -> Text + "�� " + Str_Fam.SubString (1,
                        Str_Fam.Length () - 1) + ".xls";

                    XLApp.OlePropertyGet ("WorkBooks", 1).OleProcedure ("SaveAs",
                        name_f.c_str ());
                    // XLApp.OlePropertyGet ("WorkBooks",1).OleProcedure ("SaveAs","c:\\��� ���������\\"+name_f.c_str ());
                    XLApp.OlePropertySet ("Visible", true);
                    // XLApp = Unassigned;

                    // �������� ������� ���������
                    for (int i = 0; i < 3; i++)
                        delete[]mas_stud[i];
                    DM3 -> People_SvodReportFDQuery -> Close ();
                    // �������� �������� ��� � �������
                    delete[]God_ob;
                    delete[]predmet1;
                    delete[]Count_pred;
                    for (int i = 0; i < 3; i++)
                        delete[]mas_pred[i];
                    XLSh.Clear ();
                    XLApp.Clear ();
                } // Vibor==2
                ///////////////////////////////////////////////////////
                ///����� ��� �������

            } // else (!DM3 -> People_SvodReportFDQuery -> RecordCount)
        } // if !i_gr.IsNull
        else
            ShowMessage (
            "��� ����� ������! �������� ������������ �������� ������");
    } // else
    Svod_Ved -> Close ();
   */
}
// ---------------------------------------------------------------------------

void __fastcall TSvod_Ved::RadioGroup2Click (TObject *Sender)
{ // �� ���������� ���������� ������������� �������
    switch (RadioGroup2 -> ItemIndex)
    { // switch ������������ ����� ��������� ������
    case 0:
        syst_ball = 10; // ������������� �������
        break;
    case 1:
        syst_ball = 5; // ����������� �������
        break;
    } // end switch ������������ ����� ��������� ������
}
// ---------------------------------------------------------------------------
void __fastcall TSvod_Ved::DateTimePicker1Change (TObject *Sender)
{
DateTimePicker1 -> Time = StrToTime ("00:00");
}
//---------------------------------------------------------------------------


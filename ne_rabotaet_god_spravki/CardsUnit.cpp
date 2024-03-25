#include <vcl.h>
#pragma hdrstop


#include "CardsUnit.h"
#include "DataModule.h"
#include "DM4Unit.h"
#include "StudUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TCardsForm * CardsForm;


bool           n_r,                                                             // ��������� ��� ����������� ������
               up_stud     = false,
               well        = false;

int            nomer_stud,
               year_add    = 0,
               zach        = 0;                                                 // 0 - 01.09+��� �����������; 1 - ������ ����

String         year_uch;

TLocateOptions Flags;



// Button1Click
// FormCreate
// SaveTrStud
// StateQ
// UpStud


__fastcall TCardsForm::TCardsForm (TComponent* Owner) : TForm (Owner) {
}

void __fastcall TCardsForm::Button1Click (TObject *Sender) {
    /* DataModule1 -> StudQ -> Close ();
     DataModule1 -> StudQ -> Open ();
     DataModule1 -> StudQ_Count -> Close ();
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
     nomer = DataModule1 -> StudQNOMER -> Value; // ID ��������
     UpStud (); // ����� ���������
     DM4 -> FDTablePhotosPHOTO -> Value = DataModule1 -> StudQPHOTO -> Value;
     DM4 -> FDTablePhotosSIGNATURE -> Value = DataModule1 -> StudQDIGIT_SIGN -> Value;
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
     CardsForm -> ModalResult = 0;
     } // end else msg */
}

void __fastcall TCardsForm::UpStud () {
    DM4 -> TrStudQ -> First ();
    for (int j = 0; j <= DM4 -> TrStudQ_CountCOUNT -> Value; j++)
    { // for TrStudQ (���� �� ����� ID � �� CARDSTRANSFER)
        Flags.Clear ();
        if (DM4 -> TrStudQ -> Locate ("ROWGUID", nomer_stud, Flags)) { // if ����
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
    DM4 -> TrPasportQ -> ParamByName ("rowguid") -> AsInteger = nomer_stud;
    DM4 -> TrPasportQ -> Open ();

    // ---������� PERS_STUD_TR
    DM4 -> TrPersQ -> Close ();
    DM4 -> TrPersQ -> ParamByName ("rowguid") -> AsInteger = nomer_stud;
    DM4 -> TrPersQ -> Open ();

    StateQ (); // ��������� Q
    // ������� STUDENT_TR
    nomer_stud = DataModule1 -> PeopleFDQueryNOMER -> Value; // ���������� ID ��������
    DM4 -> TrStudQROWGUID -> Value = nomer_stud; // ID ��������
    DM4 -> TrStudQFAM_TR -> Value = DataModule1 -> PeopleFDQueryFAM -> Value; // �������
    DM4 -> TrStudQNAME_TR -> Value = DataModule1 -> PeopleFDQueryNAME -> Value; // ���
    DM4 -> TrStudQOTCH_TR -> Value = DataModule1 -> PeopleFDQueryOTCH -> Value;
    // ��������
    // ---
    int status_stud = 0;
    status_stud = DataModule1 -> PeopleFDQuerySTATUS_PEOPLE -> Value;
    // ACTIVE_STUDENT=1,
    if (status_stud == 1)
        DM4 -> TrStudQACTIVE_STUDENT -> Value = 1;
    // 1-�� ������������, 0-������������
    else
        DM4 -> TrStudQACTIVE_STUDENT -> Value = 0;

    DM4 -> TrStudQID_FAC -> Value = DataModule1 -> PeopleFDQueryN_FAC -> Value;
    // ID ����������
    // ---����� �������� ID
    int vid_edu = DataModule1 -> PeopleFDQueryVID_EDU -> Value;
    DM4 -> TrStudQID_VID_EDU -> Value = vid_edu; // ID ����� ��������
    // ---
    DM4 -> TrStudQID_SPEC -> Value =
        DataModule1 -> PeopleFDQueryN_SPECIALIZ -> Value; // ID �������������
    // ---���� (ID==����)
    int kurs = DataModule1 -> PeopleFDQueryKURS -> Value;
    DM4 -> TrStudQID_KURS -> Value = kurs; // ID ����=����
    // ---
    DM4 -> TrStudQID_STUD_TYPE -> Value = 1; // 1-�������, 2-����������
    DM4 -> TrStudQNOM_Z -> Value = DataModule1 -> PeopleFDQueryN_ZACHET -> Value;
    // ����� �������=����� ����.������
    // ---���
    AnsiString pol = "";
    pol = DataModule1 -> PeopleFDQueryPOL -> Value;
    if (pol != "" & pol == "�")
        DM4 -> TrStudQPOL -> Value = 1;
    else if (pol != "" & pol == "�")
        DM4 -> TrStudQPOL -> Value = 0;
    // ---
    DM4 -> TrStudQCITYZENSHIP -> Value =
        DataModule1 -> PeopleFDQueryGRAGDAN -> Value; // �����������
    DM4 -> TrStudQN_GROUP -> Value = DataModule1 -> PeopleFDQueryN_GROUP -> Value;
    // ����� ������

    // ---��� �����������
    AnsiString date_include =
        DateTimeToStr (SQLTimeStampToDateTime
        (DataModule1 -> PeopleFDQueryD_PRIKAZ_INCLUDE -> Value));
    int year_include = date_include.SubString (7, 4).ToInt ();
    DM4 -> TrStudQADD_YEAR -> Value = year_include;

    // DM -> TrStudQDATE_ZACH -> Value=DM -> StudQD_PRIKAZ_INCLUDE -> Value;     //���� ������� � ����������
    // ---���� ����������
    AnsiString date_zac = "";

    date_zac = "01.09." + IntToStr (year_include);
    // year_include �� ������� � ����������!!!!

    DM4 -> TrStudQDATE_ZACH -> Value = DateTimeToSQLTimeStamp (StrToDate (date_zac));

    // ---
    DM4 -> TrStudQUCH_YEAR -> Value = year_uch;
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
    DM4 -> TrStudQDEKAN -> Value = DataModule1 -> PeopleFDQueryN_FAC -> Value; // �����
    // ---������� PASPORT_TR

    AnsiString pasport = "", series = "", number = "";
    pasport = DataModule1 -> PeopleFDQueryPASPORT -> Value; // �����+����� ��������
    DM4 -> TrPasportQROWGUID -> Value = nomer_stud; // ID ��������
    DM4 -> TrPasportQPERSONAL_NUMBER -> Value =
        DataModule1 -> PeopleFDQueryPERSONAL_NOMER -> Value;
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

    DM4 -> TrPersQROWGUID -> Value = nomer_stud; // ID ��������
    DM4 -> TrPersQLOGIN -> Value = nomer_stud; // �����
    DM4 -> TrPersQE_MAIL -> Value = ""; // e-mail

    /*DM4 -> FDTable1IDDATABASES -> Value = 1;
    DM4 -> FDTable1IDPERSON -> Value = nomer;
    DM4 -> FDTable1PHOTO -> Value = DataModule1 -> PeopleFDQueryPHOTO -> Value;
    DM4 -> FDTable1SIGNATURE -> Value = DataModule1 -> PeopleFDQueryDIGIT_SIGN -> Value;*/
    // ����� ��������� ���������� ��������� � ��
}

void __fastcall TCardsForm::FormCreate (TObject *Sender) {
    year_uch = "'" + IntToStr (uch_god) + "/" + (uch_god + 1) + "'";

    /* DM4 -> FDConnectionCards_TR -> Connected = true;
     DM4 -> FDConnectionCards -> Connected = true;
     // ��������� Q ����� ����������� CARDSTRANSFER
     DM4 -> VidEduQ -> Close ();
     DM4 -> VidEduQ -> Open ();
     // ��������� Q �������� CARDSTRANSFER
     DM4 -> TrStudQ -> Close ();
     DM4 -> TrStudQ -> Open ();
     DM4 -> TrStudQ_Count -> Close ();
     DM4 -> TrStudQ_Count -> Open ();
     DataModule1 -> StudQ -> Close ();
     DM4 -> FDTable1 -> Close ();
     DM4 -> FDTable1 -> Open (); */
}

void __fastcall TCardsForm::SaveTrStud () {
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
        well = true;
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

void __fastcall TCardsForm::StateQ () { // ��������� ��������� Q
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
    if (DM4 -> FDTable1 -> Locate ("IDPERSON", nomer_stud, Flags)) { // if ����
        DM4 -> FDTable1 -> Edit (); // Q Edit ();
        // break;
    } // end if ����
    else { // else ���
       /*    DM4 -> FDStoredProcPhotos -> ParamByName ("IDPERSON") -> AsInteger = nomer;
        DM4 -> FDStoredProcPhotos -> ParamByName ("PHOTO") -> AsBlob =
            DataModule1 -> PeopleFDQueryPHOTO -> Value;
        DM4 -> FDStoredProcPhotos -> ParamByName ("SIGNATURE") -> AsBlob =
            DataModule1 -> PeopleFDQueryDIGIT_SIGN -> Value;
        DM4 -> FDStoredProcPhotos -> Prepare ();
        DM4 -> FDStoredProcPhotos -> ExecProc (); */
        DM4 -> FDTable1 -> Insert ();
        // break;
    } // end else ���
    DM4 -> FDTable1IDPHOTOS -> Value = 99999;
    DM4 -> FDTable1IDDATABASES -> Value = 1;
    DM4 -> FDTable1IDPERSON -> Value = nomer_stud;
    DM4 -> FDTable1PHOTO -> Value = DataModule1 -> People_photoFDQueryPHOTO -> Value;
    DM4 -> FDTable1SIGNATURE -> Value = DataModule1 -> People_photoFDQueryDIGIT_SIGN -> Value;
        DM4 -> FDTable1 -> Post ();
} // end ��������� ��������� Q


#include <vcl.h>
#pragma hdrstop


#include "CardsUnit.h"
#include "DataModule.h"
#include "DM4Unit.h"
#include "StudUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TCardsForm * CardsForm;


bool           n_r,                                                             // добавляем или редактируем запись
               up_stud     = false,
               well        = false;

int            nomer_stud,
               year_add    = 0,
               zach        = 0;                                                 // 0 - 01.09+год поступления; 1 - вводим дату

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
     msg = "Вы действительно хотите обновить данные!";
     msgTitle = "Внимание!";
     if (Application -> MessageBox (msg.w_str (), msgTitle.w_str (),
     MB_YESNO + MB_ICONWARNING) == mrYes) { // if msg
     up_stud = true; // данные обновляются
     DataModule1 -> StudQ -> First ();
     for (int i = 0; i < DataModule1 -> StudQ_CountCOUNT -> Value; i++) { // for StudQ
     nomer = DataModule1 -> StudQNOMER -> Value; // ID студента
     UpStud (); // вызов процедуры
     DM4 -> FDTablePhotosPHOTO -> Value = DataModule1 -> StudQPHOTO -> Value;
     DM4 -> FDTablePhotosSIGNATURE -> Value = DataModule1 -> StudQDIGIT_SIGN -> Value;
     SaveTrStud ();
     DataModule1 -> StudQ -> Next (); // переход на след. студента
     } // end for StudQ

     up_stud = false; // обновления завершено
     // показывать сообщение, если все ОК
     if (well == true)
     ShowMessage ("Обновление прошло удачно!");
     DataModule1 -> StudQ -> Close (); // закрываем Q выбора студентов из деканата
     DataModule1 -> StudQ_Count -> Close ();
     } // end if msg
     else { // else msg
     up_stud = false; // данные не обновляются
     CardsForm -> ModalResult = 0;
     } // end else msg */
}

void __fastcall TCardsForm::UpStud () {
    DM4 -> TrStudQ -> First ();
    for (int j = 0; j <= DM4 -> TrStudQ_CountCOUNT -> Value; j++)
    { // for TrStudQ (есть ли такой ID в БД CARDSTRANSFER)
        Flags.Clear ();
        if (DM4 -> TrStudQ -> Locate ("ROWGUID", nomer_stud, Flags)) { // if есть
            n_r = true; // Q Edit ();
            break;
        } // end if есть
        else { // else нет
            n_r = false;
            break;
        } // end else нет
    } // end for TrStudQ (есть ли такой ID в БД CARDSTRANSFER)

    // ---таблица PASPORT_TR
    DM4 -> TrPasportQ -> Close ();
    DM4 -> TrPasportQ -> ParamByName ("rowguid") -> AsInteger = nomer_stud;
    DM4 -> TrPasportQ -> Open ();

    // ---таблица PERS_STUD_TR
    DM4 -> TrPersQ -> Close ();
    DM4 -> TrPersQ -> ParamByName ("rowguid") -> AsInteger = nomer_stud;
    DM4 -> TrPersQ -> Open ();

    StateQ (); // состояние Q
    // таблица STUDENT_TR
    nomer_stud = DataModule1 -> PeopleFDQueryNOMER -> Value; // запоминаем ID студента
    DM4 -> TrStudQROWGUID -> Value = nomer_stud; // ID студента
    DM4 -> TrStudQFAM_TR -> Value = DataModule1 -> PeopleFDQueryFAM -> Value; // Фамилия
    DM4 -> TrStudQNAME_TR -> Value = DataModule1 -> PeopleFDQueryNAME -> Value; // Имя
    DM4 -> TrStudQOTCH_TR -> Value = DataModule1 -> PeopleFDQueryOTCH -> Value;
    // Отчетсво
    // ---
    int status_stud = 0;
    status_stud = DataModule1 -> PeopleFDQuerySTATUS_PEOPLE -> Value;
    // ACTIVE_STUDENT=1,
    if (status_stud == 1)
        DM4 -> TrStudQACTIVE_STUDENT -> Value = 1;
    // 1-не заблокирован, 0-заблокирован
    else
        DM4 -> TrStudQACTIVE_STUDENT -> Value = 0;

    DM4 -> TrStudQID_FAC -> Value = DataModule1 -> PeopleFDQueryN_FAC -> Value;
    // ID факультета
    // ---Форма обучения ID
    int vid_edu = DataModule1 -> PeopleFDQueryVID_EDU -> Value;
    DM4 -> TrStudQID_VID_EDU -> Value = vid_edu; // ID форма обучения
    // ---
    DM4 -> TrStudQID_SPEC -> Value =
        DataModule1 -> PeopleFDQueryN_SPECIALIZ -> Value; // ID специальность
    // ---Курс (ID==курс)
    int kurs = DataModule1 -> PeopleFDQueryKURS -> Value;
    DM4 -> TrStudQID_KURS -> Value = kurs; // ID курс=курс
    // ---
    DM4 -> TrStudQID_STUD_TYPE -> Value = 1; // 1-Студент, 2-Магистрант
    DM4 -> TrStudQNOM_Z -> Value = DataModule1 -> PeopleFDQueryN_ZACHET -> Value;
    // Номер зачетки=номер студ.билета
    // ---Пол
    AnsiString pol = "";
    pol = DataModule1 -> PeopleFDQueryPOL -> Value;
    if (pol != "" & pol == "М")
        DM4 -> TrStudQPOL -> Value = 1;
    else if (pol != "" & pol == "Ж")
        DM4 -> TrStudQPOL -> Value = 0;
    // ---
    DM4 -> TrStudQCITYZENSHIP -> Value =
        DataModule1 -> PeopleFDQueryGRAGDAN -> Value; // Гражданство
    DM4 -> TrStudQN_GROUP -> Value = DataModule1 -> PeopleFDQueryN_GROUP -> Value;
    // Номер группы

    // ---Год поступления
    AnsiString date_include =
        DateTimeToStr (SQLTimeStampToDateTime
        (DataModule1 -> PeopleFDQueryD_PRIKAZ_INCLUDE -> Value));
    int year_include = date_include.SubString (7, 4).ToInt ();
    DM4 -> TrStudQADD_YEAR -> Value = year_include;

    // DM -> TrStudQDATE_ZACH -> Value=DM -> StudQD_PRIKAZ_INCLUDE -> Value;     //Дата приказа о зачислении
    // ---ДАТА ЗАЧИСЛЕНИЯ
    AnsiString date_zac = "";

    date_zac = "01.09." + IntToStr (year_include);
    // year_include из приказа о зачислении!!!!

    DM4 -> TrStudQDATE_ZACH -> Value = DateTimeToSQLTimeStamp (StrToDate (date_zac));

    // ---
    DM4 -> TrStudQUCH_YEAR -> Value = year_uch;
    // Текущий учебный год на момент обновления

    // Дата окончания 30.06.2___ //ПРОВЕРИТЬ!!!!! Не всегда привилоно!!!!
    AnsiString kurs_uch = "", year_end = "", date_end = "";
    year_add = uch_god;
    if (vid_edu == 1) { // заочная
        kurs_uch = 6 - kurs; // сколько курсов учиться
        year_end = year_add + kurs_uch; // год окончания
        if (kurs_uch == 0)
            year_end = year_add + 1; // год окончания
    }
    else { // дневная
        kurs_uch = 5 - kurs; // сколько курсов учиться
        year_end = year_add + kurs_uch; // год окончания
        if (kurs_uch == 0)
            year_end = year_add + 1; // год окончания
    }
    date_end = "30.06." + year_end;
    DM4 -> TrStudQDATE_END -> Value = DateTimeToSQLTimeStamp (StrToDate (date_end));
    DM4 -> TrStudQID_VUZ -> Value = 1; // ВУЗ
    DM4 -> TrStudQDEKAN -> Value = DataModule1 -> PeopleFDQueryN_FAC -> Value; // Декан
    // ---таблица PASPORT_TR

    AnsiString pasport = "", series = "", number = "";
    pasport = DataModule1 -> PeopleFDQueryPASPORT -> Value; // серия+номер паспорта
    DM4 -> TrPasportQROWGUID -> Value = nomer_stud; // ID студента
    DM4 -> TrPasportQPERSONAL_NUMBER -> Value =
        DataModule1 -> PeopleFDQueryPERSONAL_NOMER -> Value;
    DM4 -> TrPasportQPASPORT -> Value = pasport;
    int index = pasport.Pos (" "); // если есть пробел
    if (index != 0) {
        series = pasport.SubString (0, pasport.Pos (" ") - 1); // отрезаем серию
        number = pasport.SubString (pasport.Pos (" ") + 1, pasport.Length ());
        // отрезаем номер
    }
    else { // else нет пробела - отрезаем первые два символа в серию
        series = pasport.SubString (1, 2); // отрезаем серию
        number = pasport.SubString (3, pasport.Length ()); // отрезаем номер
    }
    DM4 -> TrPasportQSERIES -> Value = series;
    DM4 -> TrPasportQNUMBER -> Value = number;
    // ---таблица PERS_STUD_TR

    DM4 -> TrPersQROWGUID -> Value = nomer_stud; // ID студента
    DM4 -> TrPersQLOGIN -> Value = nomer_stud; // Логин
    DM4 -> TrPersQE_MAIL -> Value = ""; // e-mail

    /*DM4 -> FDTable1IDDATABASES -> Value = 1;
    DM4 -> FDTable1IDPERSON -> Value = nomer;
    DM4 -> FDTable1PHOTO -> Value = DataModule1 -> PeopleFDQueryPHOTO -> Value;
    DM4 -> FDTable1SIGNATURE -> Value = DataModule1 -> PeopleFDQueryDIGIT_SIGN -> Value;*/
    // вызов процедуры сохранения студентов в БД
}

void __fastcall TCardsForm::FormCreate (TObject *Sender) {
    year_uch = "'" + IntToStr (uch_god) + "/" + (uch_god + 1) + "'";

    /* DM4 -> FDConnectionCards_TR -> Connected = true;
     DM4 -> FDConnectionCards -> Connected = true;
     // открываем Q Форма образования CARDSTRANSFER
     DM4 -> VidEduQ -> Close ();
     DM4 -> VidEduQ -> Open ();
     // открываем Q Студенты CARDSTRANSFER
     DM4 -> TrStudQ -> Close ();
     DM4 -> TrStudQ -> Open ();
     DM4 -> TrStudQ_Count -> Close ();
     DM4 -> TrStudQ_Count -> Open ();
     DataModule1 -> StudQ -> Close ();
     DM4 -> FDTable1 -> Close ();
     DM4 -> FDTable1 -> Open (); */
}

void __fastcall TCardsForm::SaveTrStud () {
    // процедура сохранения студета в БД CARDSTRANSFER
    try { // сохранение в БД
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
        ShowMessage ("Произошел сбой при обновлении!");
        DM4 -> TrStudQ -> CancelUpdates ();
        DM4 -> TrPasportQ -> CancelUpdates ();
        DM4 -> TrPersQ -> CancelUpdates ();
        DM4 -> FDTable1 -> CommitUpdates ();
        well = false; // сбой при обновлении
        return;
    } // end catch
} // end процедура сохранения студета в БД CARDSTRANSFER

void __fastcall TCardsForm::StateQ () { // процедура состояний Q
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
    if (DM4 -> FDTable1 -> Locate ("IDPERSON", nomer_stud, Flags)) { // if есть
        DM4 -> FDTable1 -> Edit (); // Q Edit ();
        // break;
    } // end if есть
    else { // else нет
       /*    DM4 -> FDStoredProcPhotos -> ParamByName ("IDPERSON") -> AsInteger = nomer;
        DM4 -> FDStoredProcPhotos -> ParamByName ("PHOTO") -> AsBlob =
            DataModule1 -> PeopleFDQueryPHOTO -> Value;
        DM4 -> FDStoredProcPhotos -> ParamByName ("SIGNATURE") -> AsBlob =
            DataModule1 -> PeopleFDQueryDIGIT_SIGN -> Value;
        DM4 -> FDStoredProcPhotos -> Prepare ();
        DM4 -> FDStoredProcPhotos -> ExecProc (); */
        DM4 -> FDTable1 -> Insert ();
        // break;
    } // end else нет
    DM4 -> FDTable1IDPHOTOS -> Value = 99999;
    DM4 -> FDTable1IDDATABASES -> Value = 1;
    DM4 -> FDTable1IDPERSON -> Value = nomer_stud;
    DM4 -> FDTable1PHOTO -> Value = DataModule1 -> People_photoFDQueryPHOTO -> Value;
    DM4 -> FDTable1SIGNATURE -> Value = DataModule1 -> People_photoFDQueryDIGIT_SIGN -> Value;
        DM4 -> FDTable1 -> Post ();
} // end процедура состояний Q


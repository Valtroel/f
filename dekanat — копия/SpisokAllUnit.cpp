#include <vcl.h>
#pragma hdrstop


#include "DataModule.h"
#include "MainUnit.h"
#include "SpisokAllUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TSpisokAllForm * SpisokAllForm;


AnsiString   k[7]           = {"1", "2", "3", "4", "5", "6", "1,2,3,4,5,6"},    // массив строк для параметра по курсу
             text_sql       = "",                                               // текст SQL который будем очищать
             text_sql_count = "",
             ve[3]          = {"0,1", "0", "1"};

int          rec_z          = 0;                                                // переменная количества записей в Query

TFDQuery   * q;                                                                 // Query с которым будем работать
TFDQuery   * q_count;                                                           // Query с которым будем работатьмассив строк для параметра по виду обучения



__fastcall TSpisokAllForm::TSpisokAllForm (TComponent * Owner)
    : TForm (Owner)
{ }



// BitBtn1Click
// BitBtn2Click
// Create_Spisok
// FormClose
// FormCreate
// RadioGroup2Click




void __fastcall TSpisokAllForm::Create_Spisok ()
{ // процедура создания и заполнения StringGrida на форме список в зависимости от выбора пункта меню

    if (text_sql == "") { // if проверка
        ShowMessage ("Этот пункт еще не реализован!");
        return;
    } // end if проверка

    // ----очищение содержимого   StringGrid
    for (int i = 0; i < StringGrid1 -> ColCount; i++)
    { // for  StringGrid1 -> RowCount
        for (int j = 0; j < StringGrid1 -> RowCount + 1; j++)
        { // for  StringGrid1 -> RowCount
            StringGrid1 -> Cells[i][j] = "";
        } // end for  StringGrid1 -> RowCount
    } // end for  StringGrid1 -> ColCount

    // Открываем Query в зависимости от выбранного
    q -> Close ();
    q -> SQL -> Clear ();
    q -> SQL -> Add (text_sql);
    q -> Open ();
    q_count -> Close ();
    q_count -> SQL -> Clear ();
    q_count -> SQL -> Add (text_sql_count);
    q_count -> Open ();
    rec_z = q_count -> Fields -> Fields[0] -> Value;
    if (rec_z == 0) { // if проверка
        ShowMessage ("По данному запросу информации не найдено!");
        return;
    } // end if проверка

    for (int i = 0; i < q -> FieldCount; i++) { // for занесение названия полей
        StringGrid1 -> Cols[i] -> Text = q -> Fields -> Fields[i] -> DisplayName;
    } // end for занесение названия полей

    // определение количества строк
    StringGrid1 -> RowCount = rec_z + 1;
    StringGrid1 -> ColCount = q -> FieldCount;

    for (int i = 1; i <= rec_z; i++) {
        for (int j = 0; j < q -> FieldCount; j++) { // for занесение  полей
            StringGrid1 -> Cells[j][i] =
                Grid_V (q, q -> Fields -> Fields[j] -> FieldName);
        }
        q -> Next ();
    }
    text_sql = "";
    Panel2 -> Visible = true;
    Panel3 -> Visible = true;
    Label2 -> Caption = IntToStr (rec_z);
    SpisokAllForm -> Height = 510;
    if (SpisokAllForm -> Position != poMainFormCenter)
        SpisokAllForm -> Position = poMainFormCenter;

}


void __fastcall TSpisokAllForm::FormClose (TObject *Sender, TCloseAction &Action)
{
    Action = caFree;
}


void __fastcall TSpisokAllForm::BitBtn1Click (TObject *Sender)
{ // кнопка ВЫПОЛНИТЬ
    // проверки
    // ---
    if (RadioGroup2 -> ItemIndex == -1) { // if вид обучения
        ShowMessage ("Выберите вид обучения!");
        return;
    } // end if вид обучения
    // ----
    if (RadioGroup3 -> ItemIndex == -1) { // if курс
        ShowMessage ("Выберите курс!");
        return;
    } // end if курс

    // *******************
    switch (spisok_f) {
    case 14: // целевики
        q = DataModule1 -> CK_FDQuery;
        text_sql = "SELECT PEOPLE.FAM ||' '|| PEOPLE.NAME ||' ' || people.otch as FIO, \
                SPECIALIZ.SPECIAL, people.n_group,  REGIONAL_CENTRE.CENTRE, CK.CUSTOMER,  PEOPLE.N_FAC \
                FROM  PEOPLE \
                        INNER JOIN CK  ON (PEOPLE.NOMER = CK.NOMER) \
                        INNER JOIN SPECIALIZ ON (CK.N_SPECIALIZ = SPECIALIZ.N_SPECIALIZ) \
                        INNER JOIN REGION ON (CK.N_REGION = REGION.N_REGION) \
                        INNER JOIN REGIONAL_CENTRE ON (CK.N_CENTRE = REGIONAL_CENTRE.N_CENTRE) \
                and (PEOPLE.kurs in (" + k[RadioGroup3 -> ItemIndex] + ")) \
                and (PEOPLE.N_FAC in (" + nom_fac + ")) \
                and (PEOPLE.vid_edu in  (" + ve[RadioGroup2 -> ItemIndex] +
            ")) \
                and People.STATUS_PEOPLE=1  \
                and PEOPLE.n_found_include=1 \
                and PEOPLE.n_found=6 \
                and people.n_specializ=ck.n_specializ \
                and CK.STATUS_CK=0 \
                ORDER BY PEOPLE.N_FAC, PEOPLE.kurs, SPECIALIZ.N_SPECIALIZ, PEOPLE.FAM";
        q_count = DataModule1 -> CK_CountFDQuery;
        text_sql_count = "SELECT COUNT (PEOPLE.FAM)    FROM  PEOPLE \
                        INNER JOIN CK  ON (PEOPLE.NOMER = CK.NOMER) \
                        INNER JOIN SPECIALIZ ON (CK.N_SPECIALIZ = SPECIALIZ.N_SPECIALIZ) \
                        INNER JOIN REGION ON (CK.N_REGION = REGION.N_REGION) \
                        INNER JOIN REGIONAL_CENTRE ON (CK.N_CENTRE = REGIONAL_CENTRE.N_CENTRE) \
                and (PEOPLE.kurs in (" + k[RadioGroup3 -> ItemIndex] + ")) \
                and (PEOPLE.N_FAC in (" + nom_fac + ")) \
                and (PEOPLE.vid_edu in  (" + ve[RadioGroup2 -> ItemIndex] + ")) \
                and People.STATUS_PEOPLE=1  \
                and PEOPLE.n_found_include=1 \
                and PEOPLE.n_found=6 \
                and people.n_specializ=ck.n_specializ \
                and CK.STATUS_CK=0";

        break;
    case 15: // чернобыльцы
        q = DataModule1 -> PrivFDQuery;
        // Priv.VID_PRIV=2  это для ЧАЭС

        text_sql = "SELECT  (People.FAM || ' '  || People.NAME)  || ' '  || People.otch as  FIO, \
              People.N_FAC, People.KURS, People.N_GROUP, People.VID_EDU, Specializ.SPECIAL, People.ADDRESS_BEFORE, \
              Priv.UCH_GOD, Priv.TEXT_PRIV, Priv.DOC_PRIV, Priv.DATA_C, Priv.DATA_PO, Priv.DESCRIBE  \
              FROM PEOPLE People  \
                INNER JOIN SPECIALIZ Specializ  \
                ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) \
                INNER JOIN PRIV Priv  \
                ON  (People.NOMER = Priv.NOMER)  \
              and (PEOPLE.kurs in (" + k[RadioGroup3 -> ItemIndex] + "))  \
              and (PEOPLE.N_FAC in (" + nom_fac + ")) \
              and (PEOPLE.vid_edu in (" + ve[RadioGroup2 -> ItemIndex] + "))  \
              and People.STATUS_PEOPLE=1   \
              and Priv.VID_PRIV=2   \
              and ('" + curent_date.DateString () + "'>= Priv.data_c and '" +
            curent_date.DateString () + "' <= Priv.data_po) \
              ORDER BY PEOPLE.N_FAC, PEOPLE.kurs, PEOPLE.N_GROUP, PEOPLE.FAM";

        q_count = DataModule1 -> Priv_CountFDQuery;
        // Priv.VID_PRIV=2  это для ЧАЭС

        text_sql_count = "SELECT  COUNT (People.FAM) \
              FROM PEOPLE People  \
                INNER JOIN SPECIALIZ Specializ  \
                ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) \
                INNER JOIN PRIV Priv  \
                ON  (People.NOMER = Priv.NOMER)  \
              and (PEOPLE.kurs in (" + k[RadioGroup3 -> ItemIndex] + "))  \
              and (PEOPLE.N_FAC in (" + nom_fac + ")) \
              and (PEOPLE.vid_edu in (" + ve[RadioGroup2 -> ItemIndex] + "))  \
              and People.STATUS_PEOPLE=1   \
              and Priv.VID_PRIV=2   \
              and ('" + curent_date.DateString () + "'>= Priv.data_c and '" +
            curent_date.DateString () + "' <= Priv.data_po)";
        /* and Priv.UCH_GOD="+uch_god+"  \ */
        break;
    case 16: // сироты
        q = DataModule1 -> PrivFDQuery;
        // Priv.VID_PRIV=1  это для сирот

        text_sql = "SELECT  (People.FAM || ' '  || People.NAME)  || ' '  || People.otch as FIO, \
              People.N_FAC, People.KURS, People.N_GROUP, People.VID_EDU, Specializ.SPECIAL, People.ADDRESS_BEFORE, \
              Priv.UCH_GOD, Priv.TEXT_PRIV, Priv.DOC_PRIV, Priv.DATA_C, Priv.DATA_PO, Priv.DESCRIBE  \
              FROM PEOPLE People  \
                INNER JOIN SPECIALIZ Specializ  \
                ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) \
                INNER JOIN PRIV Priv  \
                ON  (People.NOMER = Priv.NOMER)  \
              and (PEOPLE.kurs in (" + k[RadioGroup3 -> ItemIndex] + "))  \
              and (PEOPLE.N_FAC in (" + nom_fac + ")) \
              and (PEOPLE.vid_edu in (" + ve[RadioGroup2 -> ItemIndex] + "))  \
              and People.STATUS_PEOPLE=1   \
              and Priv.VID_PRIV=1   \
              and ('" + curent_date.DateString () + "'>= Priv.data_c and '" +
            curent_date.DateString () + "' <= Priv.data_po) \
              ORDER BY PEOPLE.N_FAC, PEOPLE.kurs, PEOPLE.N_GROUP, PEOPLE.FAM";

        q_count = DataModule1 -> Priv_CountFDQuery;
        // Priv.VID_PRIV=1  это для сирот

        text_sql_count = "SELECT  COUNT (People.FAM) FROM PEOPLE People  \
                INNER JOIN SPECIALIZ Specializ  \
                ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) \
                INNER JOIN PRIV Priv  \
                ON  (People.NOMER = Priv.NOMER)  \
              and (PEOPLE.kurs in (" + k[RadioGroup3 -> ItemIndex] + "))  \
              and (PEOPLE.N_FAC in (" + nom_fac + ")) \
              and (PEOPLE.vid_edu in (" + ve[RadioGroup2 -> ItemIndex] + "))  \
              and People.STATUS_PEOPLE=1   \
              and Priv.VID_PRIV=1   \
              and ('" + curent_date.DateString () + "'>= Priv.data_c and '" +
            curent_date.DateString () + "' <= Priv.data_po)";

        /* and Priv.UCH_GOD="+uch_god+"  \ */
        break;
    case 17: // платники
        q = DataModule1 -> People_DogovorFDQuery;
        text_sql = "SELECT  People.FAM || ' '  || People.NAME  || ' '  || People.otch as FIO, \
              People.N_FAC, People.KURS, People.N_GROUP, People.VID_EDU, People.N_DOGOVOR, People.N_ZACHET, Specializ.SPECIAL  \
              FROM PEOPLE People \
                INNER JOIN SPECIALIZ Specializ \
                ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) \
              and (PEOPLE.kurs in (" + k[RadioGroup3 -> ItemIndex] + "))  \
              and (PEOPLE.N_FAC in (" + nom_fac + ")) \
              and (PEOPLE.vid_edu in (" + ve[RadioGroup2 -> ItemIndex] + ")) \
              and People.STATUS_PEOPLE=1  \
              and People.N_FOUND=2   \
              ORDER BY PEOPLE.N_FAC, PEOPLE.kurs, PEOPLE.N_GROUP, PEOPLE.FAM";

        q_count = DataModule1 -> People_Dogovor_CountFDQuery;
        text_sql_count = "SELECT  COUNT (People.FAM) FROM PEOPLE People \
                INNER JOIN SPECIALIZ Specializ \
                ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) \
              and (PEOPLE.kurs in (" + k[RadioGroup3 -> ItemIndex] + "))  \
              and (PEOPLE.N_FAC in (" + nom_fac + ")) \
              and (PEOPLE.vid_edu in (" + ve[RadioGroup2 -> ItemIndex] + ")) \
              and People.STATUS_PEOPLE=1  \
              and People.N_FOUND=2";
        break;
    case 18: // отчисленные
        q = DataModule1 -> Status_2FDQuery;
        text_sql="SELECT PEOPLE.FAM ||' '|| PEOPLE.NAME ||' ' || people.otch as FIO, \
              People.PAPA, People.MAMA, People.VID_EDU, People.N_FAC, \
              People.KURS, Specializ.SPECIAL, People.N_PRIKAZ_INCLUDE, People.D_PRIKAZ_INCLUDE, \
              People.N_GROUP, People.ADDRESS_BEFORE, People.ADDRESS, People.DATA_R, \
              People.F_OLD, People.VID_EDU_INCLUDE, \
              Cause_restore.CAUSE_RES, Restore.N_PRIKAZ_RES, Restore.D_PRIKAZ_RES, Restore.DESCRIBE   \
              FROM PEOPLE People \
                INNER JOIN SPECIALIZ Specializ  \
                ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ)  \
                INNER JOIN RESTORE Restore \
                ON  (People.NOMER = Restore.NOMER)  \
                INNER JOIN CAUSE_RESTORE Cause_restore  \
                ON  (Restore.N_CAUSE_RESTORE = Cause_restore.N_CAUSE_RESTORE) \
              and (PEOPLE.kurs in ("+k[RadioGroup3 -> ItemIndex]+")) \
              and (PEOPLE.N_FAC in ("+nom_fac+"))  \
              and (PEOPLE.vid_edu in ("+ve[RadioGroup2 -> ItemIndex]+")) \
              and People.STATUS_PEOPLE=2  \
              and Restore.VID_RESTORE=1   \
              ORDER BY Restore.D_PRIKAZ_RES DESC, PEOPLE.FAM";
        q_count = DataModule1 -> Status_2_CountFDQuery;
        text_sql_count = "SELECT COUNT (PEOPLE.FAM) FROM PEOPLE People \
                INNER JOIN SPECIALIZ Specializ  \
                ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ)  \
                INNER JOIN RESTORE Restore \
                ON  (People.NOMER = Restore.NOMER)  \
                INNER JOIN CAUSE_RESTORE Cause_restore  \
                ON  (Restore.N_CAUSE_RESTORE = Cause_restore.N_CAUSE_RESTORE) \
              and (PEOPLE.kurs in (" + k[RadioGroup3 -> ItemIndex] + ")) \
              and (PEOPLE.N_FAC in (" + nom_fac + "))  \
              and (PEOPLE.vid_edu in (" + ve[RadioGroup2 -> ItemIndex] + ")) \
              and People.STATUS_PEOPLE=2  \
              and Restore.VID_RESTORE=1";
        break;
    case 19: // иностранные языки
        q = DataModule1 -> LangvFDQuery;
        text_sql = "SELECT Langvich.LANGV, \
              PEOPLE.FAM ||' '|| PEOPLE.NAME ||' ' || people.otch as FIO, \
              People.N_FAC, People.KURS, People.N_GROUP, People. VID_EDU,  Specializ.SPECIAL, \
              People.NAME_EDUC, People.WHEN_EDUC, People.WHERE_EDUC  \
              FROM PEOPLE People \
                INNER JOIN LANGVICH_BALL Langvich_ball \
                ON  (People.NOMER = Langvich_ball.NOMER) \
                INNER JOIN SPECIALIZ Specializ \
                ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ)  \
                INNER JOIN LANGVICH Langvich  \
                ON  (Langvich_ball.N_LANGVICH = Langvich.N_LANGVICH) \
              and (PEOPLE.kurs in (" + k[RadioGroup3 -> ItemIndex] + "))  \
              and (PEOPLE.N_FAC in (" + nom_fac + "))  \
              and (PEOPLE.vid_edu in (" + ve[RadioGroup2 -> ItemIndex] +
            "))   \
              and People.STATUS_PEOPLE=1  \
              ORDER BY PEOPLE.N_FAC, PEOPLE.kurs, PEOPLE.N_GROUP, Langvich_ball.N_LANGVICH, PEOPLE.FAM";
        q_count = DataModule1 -> Langv_CountFDQuery;
        text_sql_count = "SELECT COUNT (Langvich.LANGV) FROM PEOPLE People \
                INNER JOIN LANGVICH_BALL Langvich_ball \
                ON  (People.NOMER = Langvich_ball.NOMER) \
                INNER JOIN SPECIALIZ Specializ \
                ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ)  \
                INNER JOIN LANGVICH Langvich  \
                ON  (Langvich_ball.N_LANGVICH = Langvich.N_LANGVICH) \
              and (PEOPLE.kurs in (" + k[RadioGroup3 -> ItemIndex] + "))  \
              and (PEOPLE.N_FAC in (" + nom_fac + "))  \
              and (PEOPLE.vid_edu in (" + ve[RadioGroup2 -> ItemIndex] + "))   \
              and People.STATUS_PEOPLE=1";
        break;
    case 20: // инвалиды
        q = DataModule1 -> PrivFDQuery;
        // Priv.VID_PRIV=3  это инвалиды

        text_sql = "SELECT  (People.FAM || ' '  || People.NAME)  || ' '  || People.otch as FIO, \
              People.N_FAC, People.KURS, People.N_GROUP, People.VID_EDU, Specializ.SPECIAL, People.ADDRESS_BEFORE, \
              Priv.UCH_GOD, Priv.TEXT_PRIV, Priv.DOC_PRIV, Priv.DATA_C, Priv.DATA_PO, Priv.DESCRIBE  \
              FROM PEOPLE People  \
                INNER JOIN SPECIALIZ Specializ  \
                ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) \
                INNER JOIN PRIV Priv  \
                ON  (People.NOMER = Priv.NOMER)  \
              and (PEOPLE.kurs in (" + k[RadioGroup3 -> ItemIndex] + "))  \
              and (PEOPLE.N_FAC in (" + nom_fac + ")) \
              and (PEOPLE.vid_edu in (" + ve[RadioGroup2 -> ItemIndex] + "))  \
              and People.STATUS_PEOPLE=1   \
              and Priv.VID_PRIV=3   \
              and ('" + curent_date.DateString () + "'>= Priv.data_c and '" +
            curent_date.DateString () + "' <= Priv.data_po) \
              ORDER BY PEOPLE.N_FAC, PEOPLE.kurs, PEOPLE.N_GROUP, PEOPLE.FAM";

        q_count = DataModule1 -> Priv_CountFDQuery;
        // Priv.VID_PRIV=3  это инвалиды

        text_sql_count = "SELECT  COUNT (People.FAM) FROM PEOPLE People  \
                INNER JOIN SPECIALIZ Specializ  \
                ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) \
                INNER JOIN PRIV Priv  \
                ON  (People.NOMER = Priv.NOMER)  \
              and (PEOPLE.kurs in (" + k[RadioGroup3 -> ItemIndex] + "))  \
              and (PEOPLE.N_FAC in (" + nom_fac + ")) \
              and (PEOPLE.vid_edu in (" + ve[RadioGroup2 -> ItemIndex] + "))  \
              and People.STATUS_PEOPLE=1   \
              and Priv.VID_PRIV=3   \
              and ('" + curent_date.DateString () + "'>= Priv.data_c and '" +
            curent_date.DateString () + "' <= Priv.data_po)";

        /* and Priv.UCH_GOD="+uch_god+"  \ */
        break;
    case 21: // Общежитие
        q = DataModule1 -> People_HostelFDQuery;
        text_sql = "SELECT  People.FAM || ' '  || People.NAME  || ' '  || People.otch as FIO, \
              People.N_FAC, People.KURS, People.N_GROUP, People.VID_EDU, Specializ.SPECIAL,  \
              r.text_region, People.address \
              FROM PEOPLE People \
                INNER JOIN SPECIALIZ Specializ \
                ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) \
                inner join region r on (r.n_region=people.scholarship) \
              and (PEOPLE.kurs in (" + k[RadioGroup3 -> ItemIndex] + "))  \
              and (PEOPLE.N_FAC in (" + nom_fac + ")) \
              and (PEOPLE.vid_edu in (" + ve[RadioGroup2 -> ItemIndex] + ")) \
              and People.STATUS_PEOPLE=1  \
              and People.hostel=1   \
              ORDER BY PEOPLE.N_FAC, PEOPLE.kurs, PEOPLE.N_GROUP, PEOPLE.FAM";

        q_count = DataModule1 -> People_Hostel_CountFDQuery;
        text_sql_count = "SELECT  COUNT (People.FAM) FROM PEOPLE People \
                INNER JOIN SPECIALIZ Specializ \
                ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) \
                inner join region r on (r.n_region=people.scholarship) \
              and (PEOPLE.kurs in (" + k[RadioGroup3 -> ItemIndex] + "))  \
              and (PEOPLE.N_FAC in (" + nom_fac + ")) \
              and (PEOPLE.vid_edu in (" + ve[RadioGroup2 -> ItemIndex] + ")) \
              and People.STATUS_PEOPLE=1  \
              and People.hostel=1";
        break;

    }

    Create_Spisok ();
}


void __fastcall TSpisokAllForm::BitBtn2Click (TObject *Sender)
{ // передача данных в Excel
    str_grid (StringGrid1);
}


void __fastcall TSpisokAllForm::RadioGroup2Click (TObject *Sender)
{ // изменение условий по факультету, виду обучения и курсу
    Panel2 -> Visible = false;
    Panel3 -> Visible = false;
    SpisokAllForm -> Height = 118;
    if (SpisokAllForm -> Position != poMainFormCenter)
        SpisokAllForm -> Position = poMainFormCenter;
}


void __fastcall TSpisokAllForm::FormCreate (TObject *Sender) {
    // текущая дата
    curent_date = cur_d ();
}


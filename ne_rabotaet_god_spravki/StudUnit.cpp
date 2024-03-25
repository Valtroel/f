// ---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <stdio.h>
#include <jpeg.hpp>
#include <graphics.hpp>
// #include <dbtables.hpp>
#include "StudUnit.h"
#include "DataModule.h"
#include "CalendarUnit.h"
#include <math.h>
#include "SportUnit.h"
#include "PassUnit.h"
#include "MainUnit.h"
#include "DM2Unit.h"
#include "People_Card_ReportUnit.h"
#include "DataModule_Card.h"
#include "Stud_Pr_RestoreUnit.h"
#include "PasportUnit.h"
#include "DM4Unit.h"
#include "DualList.h"
#include "DataModule_Card.h"
#include "QueueUnit.h"
#include "AdressUnit.h"
// ---------------------------------------------------------------------------
#pragma package (smart_init)
// !!!#pragma link "MyList"
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma resource "*.dfm"
int cal_year, cal_month, cal_day, status_people_query;
int open = 0;
// int KeyDelet=0,
int KeyPressAd = 0; // режим редактирования данных по студенту

Dbctrls::TNavButtonSet btn;
// переменная для переопределения кнопок на навигаторе
// для формирования фотографии на личной карточке

// TMemoryStream* pms;
Jpeg::TJPEGImage *jp;
Jpeg::TJPEGImage *jp1;
TMemoryStream *pms;
TMemoryStream *ds_pms;
// ----Переменные для личной карточки
TFDBlobStream *pot;
Jpeg::TJPEGImage *jpga;
AnsiString ph;
// TfrView *viw;
TfrxReportPage *Page;
TfrxReportPage *Page1;
TfrxReportPage *Page2;
TfrxReportPage *Page3;
// TfrView *f;
TfrxPictureView *pic;
// ---

TStudForm *StudForm;

// переменная для определения
// занесен ли документ, удостоверяющий личность
bool est_pas;
int id_ab;
bool well = false;
int g;
int region_id;
bool up_reg;

// ---------------------------------------
/* ///////Процедура тани
 AnsiString __fastcall TStudForm::Ocenka (AnsiString result)
 {
 int res=StrToInt (result);
 AnsiString St="";
 switch (res)
 {
 case 3: St="3 (удовлетв.)";
 break;
 case 4: St="4 (хор.)";
 break;
 case 5: St="5 (отл.)";
 break;
 }
 return St;

 }
 */
// -----------------------------------
void __fastcall TStudForm::RefreshControl () {
    // if (open){
    if (DataModule1 -> PeopleFDQuery -> State != dsInsert) {
        if (DataModule1 -> PeopleFDQueryPOL -> Value == 'Ж') {
            ComboBox1 -> Items -> BeginUpdate ();
            ComboBox1 -> Items -> Clear ();
            ComboBox1 -> Items -> Add ("Не замужем");
            ComboBox1 -> Items -> Add ("Замужем");
            ComboBox1 -> Items -> Add ("Разведена");
            ComboBox1 -> Items -> Add ("Вдова");
            ComboBox1 -> Items -> EndUpdate ();
        }
        else if (DataModule1 -> PeopleFDQueryPOL -> Value == 'М') {
            ComboBox1 -> Items -> BeginUpdate ();
            ComboBox1 -> Items -> Clear ();
            ComboBox1 -> Items -> Add ("Холост");
            ComboBox1 -> Items -> Add ("Женат");
            ComboBox1 -> Items -> Add ("Разведен");
            ComboBox1 -> Items -> Add ("Вдовец");
            ComboBox1 -> Items -> EndUpdate ();
        }
        ComboBox1 -> ItemIndex = DataModule1 -> PeopleFDQueryMARIAGE -> Value;
        ComboBox2 -> ItemIndex = DataModule1 -> PeopleFDQueryEDUCATION -> Value - 1;
        ComboBox3 -> ItemIndex = DataModule1 -> PeopleFDQueryVID_EDU -> Value;
        // вид обучения реальный
        Variant edu_zach = DataModule1 -> PeopleFDQueryVID_EDU_INCLUDE -> AsVariant;
        if (!edu_zach.IsNull ())
            ComboBox5 -> ItemIndex =
                DataModule1 -> PeopleFDQueryVID_EDU_INCLUDE -> Value;
        // вид обучения при зачислении
        else { // если значения в поле VID_EDU_INCLUDE  отсутствует - ничего не показывать
            ComboBox5 -> ItemIndex = -1;
            ComboBox5 -> Text = "";
        }

        if (DataModule1 -> PeopleFDQueryARMY -> Value)
            CheckBox1 -> Checked = true;
        else
            CheckBox1 -> Checked = false;
        if (DataModule1 -> PeopleFDQueryHOSTEL -> Value)
            CheckBox2 -> Checked = true;
        else
            CheckBox2 -> Checked = false;

        if (DataModule1 -> PeopleFDQuerySTATUS_KURS -> Value)
            // если студент не переведен на след. курс
        {
            Label11 -> Visible = true;
            DBText1 -> Font -> Color = clRed;
            DBText2 -> Font -> Color = clRed;
            DBText3 -> Font -> Color = clRed;
            DBEdit25 -> Color = clMenu;
            DBEdit26 -> Color = clMenu;

        }
        else // студент переведен на след. курс
        {
            Label11 -> Visible = false;
            DBText1 -> Font -> Color = clNavy;
            DBText2 -> Font -> Color = clNavy;
            DBText3 -> Font -> Color = clNavy;
            DBEdit25 -> Color = clBtnFace;
            DBEdit26 -> Color = clBtnFace;
        }

        pms = new TMemoryStream ();
        jp = new TJPEGImage ();
        ds_pms = new TMemoryStream ();
        jp1 = new TJPEGImage ();
        /* Variant photo = & (DataModule1 -> PeopleFDQueryPHOTO -> Value);
         AnsiString ph = photo.AsType (varString); */
        if (!DataModule1 -> People_photoFDQueryPHOTO -> IsNull)
        { // показ Image картинки из базы
            pms -> Clear ();
            DataModule1 -> People_photoFDQueryPHOTO -> SaveToStream (pms);
            pms -> Position = 0;
            jp -> LoadFromStream (pms);
            Image1 -> Picture -> Assign (jp);
        }
        else
            Image1 -> Picture = NULL;

        // --------
      /*    // № договора виден только для студентов платников
        if (DBLookupComboBox1 -> KeyValue == 2) {
            DBEdit6 -> Visible = true;
            Label3 -> Visible = true;
        }
        else {
            DBEdit6 -> Visible = false;
            Label3 -> Visible = false;
        }  */
        // -----
        // переводные приказы
        DataModule1 -> Prikaz_KursFDQuery -> Close ();
        DataModule1 -> Prikaz_KursFDQuery -> SQL -> Clear ();
        DataModule1 -> Prikaz_KursFDQuery -> SQL -> Add
            ("SELECT * FROM PRIKAZ_KURS WHERE NOMER=:NOM ORDER BY N_KURS, D_PRIKAZ_KURS"
            );
        DataModule1 -> Prikaz_KursFDQuery -> ParamByName ("NOM") -> AsInteger =
            DataModule1 -> PeopleFDQueryNOMER -> Value;
        DataModule1 -> Prikaz_KursFDQuery -> Open ();
        // академические отпуска
        DataModule1 -> HolidayFDQuery -> Close ();
        DataModule1 -> HolidayFDQuery -> SQL -> Clear ();
        DataModule1 -> HolidayFDQuery -> SQL -> Add ("SELECT Holiday.NOMER, Holiday.N_PRIKAZ_HOL, \
Holiday.D_PRIKAZ_HOL, Holiday.D_BEGIN_HOL, Holiday.D_END_HOL, Holiday.N_HOL, \
Cause_holiday.CAUSE_HOL, Holiday.TYPE_HOL FROM HOLIDAY Holiday \
INNER JOIN CAUSE_HOLIDAY Cause_holiday ON  (Holiday.N_HOL = Cause_holiday.N_HOL) \
WHERE NOMER=:NOM ORDER BY D_PRIKAZ_HOL");
        DataModule1 -> HolidayFDQuery -> ParamByName ("NOM") -> AsInteger =
            DataModule1 -> PeopleFDQueryNOMER -> Value;
        DataModule1 -> HolidayFDQuery -> Open ();
        // приказы на отчисление / восстановление
        DataModule1 -> RestoreFDQuery -> Close ();
        DataModule1 -> RestoreFDQuery -> SQL -> Clear ();
        DataModule1 -> RestoreFDQuery -> SQL -> Add ("SELECT NOMER, N_CAUSE_RESTORE, VID_RESTORE, \
N_PRIKAZ_RES, D_PRIKAZ_RES, DESCRIBE FROM RESTORE WHERE NOMER=:NOM ORDER BY D_PRIKAZ_RES"
            );
        DataModule1 -> RestoreFDQuery -> ParamByName ("NOM") -> AsInteger =
            DataModule1 -> PeopleFDQueryNOMER -> Value;
        DataModule1 -> RestoreFDQuery -> Open ();
        // разные приказы
        DataModule1 -> Public_PrikazFDQuery -> Close ();
        DataModule1 -> Public_PrikazFDQuery -> SQL -> Clear ();
        DataModule1 -> Public_PrikazFDQuery -> SQL -> Add ("SELECT N_TYPE, N_PUBLIC_PRIKAZ, \
D_PUBLIC_PRIKAZ, NOMER, DESCRIBE  FROM PUBLIC_PRIKAZ Public_prikaz \
WHERE NOMER=:NOM ORDER BY D_PUBLIC_PRIKAZ");
        DataModule1 -> Public_PrikazFDQuery -> ParamByName ("NOM") -> AsInteger =
            DataModule1 -> PeopleFDQueryNOMER -> Value;
        DataModule1 -> Public_PrikazFDQuery -> Open ();
        // приказы о поощрении / взыскании
        DataModule1 -> EncourageFDQuery -> Close ();
        DataModule1 -> EncourageFDQuery -> SQL -> Clear ();
        DataModule1 -> EncourageFDQuery -> SQL -> Add ("SELECT Encourage.NOMER, \
Encourage.N_TYPE_EN, Encourage.WHAT, Encourage.WHO_TAKE, Encourage.N_PRIKAZ, \
Encourage.D_PRIKAZ, Type_encourage.VID_EN, Type_encourage.TYPE_EN  \
FROM ENCOURAGE Encourage  INNER JOIN TYPE_ENCOURAGE Type_encourage  \
ON  (Encourage.N_TYPE_EN = Type_encourage.N_TYPE_EN)  \
WHERE NOMER=:NOM ORDER BY D_PRIKAZ");
        DataModule1 -> EncourageFDQuery -> ParamByName ("NOM") -> AsInteger =
            DataModule1 -> PeopleFDQueryNOMER -> Value;
        DataModule1 -> EncourageFDQuery -> Open ();

        // адрес
        DBEdit18 -> Text = DataModule1 -> PeopleFDQueryADDRESS_BEFORE -> Value;
        DBEdit19 -> Text = DataModule1 -> PeopleFDQueryADDRESS -> Value;

        DataModule1 -> QAdress -> Close ();
        DataModule1 -> QAdress -> ParamByName ("ID") -> AsInteger =
            DataModule1 -> PeopleFDQueryID_STREET -> Value;
        DataModule1 -> QAdress -> Active = true;

    } // если данные находятся не в режиме вставки

    // }
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::Print_To ()
{ // функция печати второй стороны личной карточки
    int nom = 1;
    // int k=0;//Переменная для смещения 2 карточки на лист
    // DataModule2 -> frxReport1 -> Clear ();
    // Добовление первой страницы
    // create page
    // !!!Page=frxReport1 -> Pages -> Pages[nom];
    // Page = new TfrxReportPage (DataModule2 -> frxReport1);
    // bool R=true; //Переключатель для 2 кар. на лист
    DataModule2 -> Report_CardFDQuery -> First ();
    for (int i = 0; i < DataModule2 -> Report_CardFDQuery -> RecordCount; i++)
    { // Вставляем ФИО на второй стороне
        int nom = DataModule2 -> Report_CardFDQuery -> RecordCount + i;
        Page1 = new TfrxReportPage (DataModule2 -> frxReport1);

        P_F (36, 36, 683, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (),
            DataModule2 -> Report_CardFDQueryFAM -> Value + " " +
            (DataModule2 -> Report_CardFDQueryNAME -> Value.SubString (1, 1)) +
            ". " + DataModule2 -> Report_CardFDQueryOTCH -> Value.SubString (1, 1) +
            ". ", nom, DataModule2 -> frxReport1, 0);
        P_F (36, 54, 126, 19, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "Зачислен на", nom,
            DataModule2 -> frxReport1, 0);

        // , People.VID_EDU_INCLUDE, People.N_FOUND_INCLUDE - добавлены поля вид обучения при зачислении и причина зачисления
        AnsiString St = "";
        St = AnsiString (DataModule2 -> Report_CardFDQueryN_PRIKAZ_KURS -> Value) +
            " курс";
        if (DataModule2 -> Report_CardFDQueryVID_EDU_INCLUDE -> Value == 1) {
            St += " заочной формы получения образования";

        }
        else {
            Variant vid_enc =
                DataModule2 -> Report_CardFDQueryVID_EDU_INCLUDE -> AsVariant;
            if (!vid_enc.IsNull ())
                St += " дневной формы получения образования";
            else
                St += "";
        }
        P_F (126, 52, 400, 25, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom,
            DataModule2 -> Report_CardFDQueryFAC1 -> Value + ", " + St, nom,
            DataModule2 -> frxReport1, 0);
        // Вторая строка
        /* if (DataModule2 -> Report_CardQuerySPECIAL -> Value!="")
         {
         Page -> Objects -> Add (P_F (36,73,308,30,2,10,"Arial",2+16,2,DataModule2 -> Report_CardQuerySPECIAL -> Value));
         } */

        if (DataModule2 -> Report_CardFDQueryN_SPEC -> Value == 1) {
            if (DataModule2 -> Report_CardFDQuerySPECIAL -> Value != "")
                P_F (36, 73, 308, 30, TFontStyles (), 8, "Arial", haLeft,
                vaCenter, TfrxFrameTypes () << ftBottom,
                DataModule2 -> Report_CardFDQuerySPECIAL -> Value, nom,
                DataModule2 -> frxReport1, 0);
        }
        else {
            if (DataModule2 -> Report_CardFDQuerySPECIAL_DIRECTION -> Value != "")
                P_F (36, 73, 308, 30, TFontStyles (), 8, "Arial", haLeft,
                vaCenter, TfrxFrameTypes () << ftBottom,
                DataModule2 -> Report_CardFDQuerySPECIAL_DIRECTION -> Value, nom,
                DataModule2 -> frxReport1, 0);
        }

        //

        P_F (345, 73, 211, 30, TFontStyles () << fsBold, 10, "Arial", haCenter,
            vaCenter, TfrxFrameTypes (), "Дата зачисления и № приказа", nom,
            DataModule2 -> frxReport1, 0);
        //

        if (!DataModule2 -> Report_CardFDQueryN_PRIKAZ_INCLUDE -> Value == 0) {
            P_F (558, 73, 153 + 3, 30, TFontStyles (), 10, "Arial", haCenter,
                vaBottom, TfrxFrameTypes () << ftBottom,
                "№" + IntToStr
                (DataModule2 -> Report_CardFDQueryN_PRIKAZ_INCLUDE -> Value) +
                " от " + DateToStr (SQLTimeStampToDateTime
                (DataModule2 -> Report_CardFDQueryD_PRIKAZ_INCLUDE -> Value)), nom,
                DataModule2 -> frxReport1, 0);
        }
        else {
            P_F (558, 73, 153 + 3, 30, TFontStyles (), 10, "Arial", haCenter,
                vaBottom, TfrxFrameTypes () << ftBottom, "", nom,
                DataModule2 -> frxReport1, 0);
        }

        // Третья строка
        P_F (235, 112, 288, 19, TFontStyles () << fsBold, 10, "Arial", haCenter,
            vaCenter, TfrxFrameTypes (), "Регистрация прохождения обучения", nom,
            DataModule2 -> frxReport1, 0);

        // Шапка таблицы
        P_F (36, 136, 60, 38, TFontStyles () << fsBold, 8, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "Курс",
            nom, DataModule2 -> frxReport1, 0);
        //
        P_F (97, 136, 177, 38, TFontStyles () << fsBold, 8, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "Наименование факультета", nom, DataModule2 -> frxReport1, 0);
        //
        P_F (275, 136, 164, 19, TFontStyles () << fsBold, 8, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "Год",
            nom, DataModule2 -> frxReport1, 0);
        P_F (275, 155, 82, 19, TFontStyles () << fsBold, 8, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "поступления", nom, DataModule2 -> frxReport1, 0);
        P_F (357, 155, 82, 19, TFontStyles () << fsBold, 8, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "окончания", nom, DataModule2 -> frxReport1, 0);
        P_F (440, 136, 105, 38, TFontStyles () << fsBold, 8, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "Форма получения образования", nom, DataModule2 -> frxReport1, 0);
        P_F (546, 136, 175, 38, TFontStyles () << fsBold, 8, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "Дата и № приказа о переводе на следующий курс", nom,
            DataModule2 -> frxReport1, 0);
        int kof = 0;

        DataModule2 -> Report_Prikaz_KursFDQuery -> ParamByName ("NOMER") -> Value =
            DataModule2 -> Report_CardFDQueryNOMER -> Value;
        int kol = 0;
        if ( (DataModule2 -> Report_CardFDQueryVID_EDU -> Value == 0) &&
            (DataModule2 -> Report_CardFDQueryKURS -> Value == 4))
            kol = 4; // (2/3/4)
        if ( (DataModule2 -> Report_CardFDQueryVID_EDU -> Value == 0) &&
            (DataModule2 -> Report_CardFDQueryKURS -> Value == 4))
            kol = 4;
        if (DataModule2 -> Report_CardFDQueryVID_EDU -> Value == 1)
            kol = 5; // (2/3/4/5)
        if ( (DataModule2 -> Report_CardFDQueryVID_EDU -> Value == 0) &&
            (DataModule2 -> Report_CardFDQueryKURS -> Value == 3))
            kol = 3;
        if ( (DataModule2 -> Report_CardFDQueryVID_EDU -> Value == 0) &&
            (DataModule2 -> Report_CardFDQueryKURS -> Value == 2))
            kol = 2;
        if ( (DataModule2 -> Report_CardFDQueryVID_EDU -> Value == 0) &&
            (DataModule2 -> Report_CardFDQueryKURS -> Value == 1))
            kol = 1;

        // Печать самой таблицы Prikaz_Kurs
        for (int tab = 2; tab <= kol; tab++) { // Печать первого столбца
            P_F (36, 175 + kof, 60, 18, TFontStyles () << fsBold, 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                IntToStr (tab - 1), nom, DataModule2 -> frxReport1, 0);
            // Печать второго столбца
            DataModule2 -> Report_Prikaz_KursFDQuery -> Close ();
            DataModule2 -> Report_Prikaz_KursFDQuery -> ParamByName ("N_KURS")
                -> Value = tab;
            DataModule2 -> Report_Prikaz_KursFDQuery -> Open ();
            if (DataModule2 -> Report_Prikaz_KursFDQuery -> RecordCount != 0)
                P_F (97, 175 + kof, 177, 18, TFontStyles (), 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                DataModule2 -> Report_Prikaz_KursFDQueryFAC1 -> Value, nom,
                DataModule2 -> frxReport1, 0);
            else
                P_F (97, 175 + kof, 177, 18, TFontStyles (), 10, "Arial", haLeft,
                vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
            // Перевод даты в строку
            TDateTime my_date =
                SQLTimeStampToDateTime (DataModule2 -> 
                Report_Prikaz_KursFDQueryD_PRIKAZ_KURS -> Value);
            AnsiString god = my_date.DateString ().SubString (7, 4);
            // Печать третьего столбца
            if (StrToFloat (god) != 1899)
                P_F (275, 175 + kof, 82, 18, TFontStyles (), 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                FloatToStr (StrToFloat (god) - 1), nom,
                DataModule2 -> frxReport1, 0);
            else
                P_F (275, 175 + kof, 82, 18, TFontStyles (), 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
            // Печать четвертого столбца
            if (StrToFloat (god) != 1899)
                P_F (357, 175 + kof, 82, 18, TFontStyles (), 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                FloatToStr (StrToFloat (god)), nom, DataModule2 -> frxReport1, 0);
            else
                P_F (357, 175 + kof, 82, 18, TFontStyles (), 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
            // Печать пятого столбца
            if (DataModule2 -> Report_Prikaz_KursFDQuery -> RecordCount != 0) {
                if (DataModule2 -> Report_Prikaz_KursFDQueryVID_EDU -> Value == 1)
                    P_F (440, 175 + kof, 105, 18, TFontStyles (), 10, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "заочное", nom, DataModule2 -> frxReport1, 0);
                else
                    P_F (440, 175 + kof, 105, 18, TFontStyles (), 10, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "дневное", nom, DataModule2 -> frxReport1, 0);
            }
            else // Нет вида обучения
                    P_F (440, 175 + kof, 105, 18, TFontStyles (), 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);

            // Печать шестого столбца
            if (!DataModule2 -> Report_Prikaz_KursFDQueryN_PRIKAZ_KURS -> 
                Value == 0)
                P_F (546, 175 + kof, 175, 18, TFontStyles (), 10, "Arial", haLeft,
                vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                " №" + IntToStr
                (DataModule2 -> Report_Prikaz_KursFDQueryN_PRIKAZ_KURS -> Value) +
                " от " + DateToStr (SQLTimeStampToDateTime
                (DataModule2 -> Report_Prikaz_KursFDQueryD_PRIKAZ_KURS -> Value)),
                nom, DataModule2 -> frxReport1, 0);
            else
                P_F (546, 175 + kof, 175, 18, TFontStyles (), 10, "Arial", haLeft,
                vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);

            kof = kof + 18;
        } // For в таблице
        // Печать последней строки с приказом о выпуске
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Close ();
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("NOMER")
            -> Value = DataModule2 -> Report_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("TYPE")
            -> Value = 9;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Open ();
        // if ( (DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount!=0)&& kol==5)
        // {
        // первый
        P_F (36, 175 + kof, 60, 18, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            IntToStr (kol), nom, DataModule2 -> frxReport1, 0);
        if (DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount != 0)
            // второй
                P_F (97, 175 + kof, 177, 18, TFontStyles (), 10, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            DataModule2 -> Report_CardFDQueryFAC1 -> Value, nom,
            DataModule2 -> frxReport1, 0);
        else
            P_F (97, 175 + kof, 177, 18, TFontStyles (), 10, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);
        // третий четвертого столбца
        if (DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount != 0) {
            TDateTime my_date =
                SQLTimeStampToDateTime (DataModule2 -> 
                Report_Ut_Public_PrikazFDQueryD_PUBLIC_PRIKAZ -> Value);
            AnsiString god = my_date.DateString ().SubString (7, 4);
            P_F (275, 175 + kof, 82, 18, TFontStyles (), 10, "Arial", haCenter,
                vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                FloatToStr (StrToFloat (god) - 1), nom,
                DataModule2 -> frxReport1, 0);
            P_F (357, 175 + kof, 82, 18, TFontStyles (), 10, "Arial", haCenter,
                vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                FloatToStr (StrToFloat (god)), nom, DataModule2 -> frxReport1, 0);

        } // if
        else {
            P_F (275, 175 + kof, 82, 18, TFontStyles (), 10, "Arial", haCenter,
                vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
            P_F (357, 175 + kof, 82, 18, TFontStyles (), 10, "Arial", haCenter,
                vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
        }

        // пятый столбец
        if (DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount != 0) {
            if (DataModule2 -> Report_CardFDQueryVID_EDU -> Value == 1)
                P_F (440, 175 + kof, 105, 18, TFontStyles (), 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                "заочное", nom, DataModule2 -> frxReport1, 0);
            else
                P_F (440, 175 + kof, 105, 18, TFontStyles (), 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                "дневное", nom, DataModule2 -> frxReport1, 0);
        }
        else
            P_F (440, 175 + kof, 105, 18, TFontStyles (), 10, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);
        // шестой
        if (DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount != 0) {
            P_F (546, 175 + kof, 175, 18, TFontStyles (), 8, "Arial", haCenter,
                vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                "прик о вып. №" + IntToStr
                (DataModule2 -> Report_Ut_Public_PrikazFDQueryN_PUBLIC_PRIKAZ -> 
                Value) + " от " + DateToStr (SQLTimeStampToDateTime
                (DataModule2 -> Report_Ut_Public_PrikazFDQueryD_PUBLIC_PRIKAZ -> 
                Value)), nom, DataModule2 -> frxReport1, 0);
        }
        else
            P_F (546, 175 + kof, 175, 18, TFontStyles (), 10, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);

        // }

        // else
        // Page -> Objects -> Add (P_F (546,193,175,18,0,10,"Arial",0,15,""));

        // Печать столбца о разрядах
        DataModule2 -> Report_SportFDQuery -> Close ();
        DataModule2 -> Report_SportFDQuery -> ParamByName ("NOMER") -> Value =
            DataModule2 -> Report_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_SportFDQuery -> Open ();
        // Цикл
        kof = 0;
        AnsiString St1 = "";
        for (int raz = 1; raz <= DataModule2 -> Report_SportFDQuery -> RecordCount;
        raz++) {
            if (DataModule2 -> Report_SportFDQueryTEXT_SPORT_CATEGORY -> Value !=
                "" && DataModule2 -> Report_SportFDQueryTEXT_SPORT_CATEGORY -> Value
                != "нет") {
                St1 = St1 + DataModule2 -> Report_SportFDQueryVID_SPORT -> Value;
                if (DataModule2 -> Report_SportFDQueryTEXT_SPORT_CATEGORY -> 
                    Value != "")
                    St1 = St1 + ", " +
                        DataModule2 -> 
                        Report_SportFDQueryTEXT_SPORT_CATEGORY -> Value;
                if (DataModule2 -> Report_SportFDQueryWHO_GIVE -> Value != "")
                    St1 = St1 + ", " +
                        DataModule2 -> Report_SportFDQueryWHO_GIVE -> Value;
                if (DataModule2 -> Report_SportFDQueryN_PRIKAZ_SPORT -> Value != 0)
                    St1 = St1 + " №" +
                        IntToStr (DataModule2 -> Report_SportFDQueryN_PRIKAZ_SPORT
                    -> Value);
                if (!DataModule2 -> Report_SportFDQueryD_PRIKAZ_SPORT -> AsVariant.
                    IsNull ())
                    St1 = St1 + " " + DateToStr
                        (SQLTimeStampToDateTime
                    (DataModule2 -> Report_SportFDQueryD_PRIKAZ_SPORT -> Value));
                // Проставляю точку с запятой
                if (raz < DataModule2 -> Report_SportFDQuery -> RecordCount)
                    St1 = St1 + ". ";
            }

            DataModule2 -> Report_SportFDQuery -> Next ();
        } // конец цикл разряд

        // Page -> Objects -> Add (P_F (36,283,683,18,0,10,"Arial",0,2,St1));
        // Page -> Objects -> Add (P_F (36,301,683,12,0,7,"Arial",2,0,"Вид спорта, разряд, кем присвоен, номер и дата приказа")); //683/2=342
        // new
        P_F (36, 283, 342, 36, TFontStyles (), 9, "Arial", haCenter, vaCenter,
            TfrxFrameTypes () << ftBottom, St1, nom,
            DataModule2 -> frxReport1, 0); // 18+18=36

        P_F (36, 301 + 18, 342, 12, TFontStyles (), 7, "Arial", haLeft, vaCenter,
            TfrxFrameTypes (),
            "Вид спорта, разряд, кем присвоен, номер и дата приказа", nom,
            DataModule2 -> frxReport1, 0);

        // kof=kof+30;

        // Печать строки о судейской категории
        St1 = "";
        DataModule2 -> Report_SportFDQuery -> First ();
        for (int sud = 1; sud <= DataModule2 -> Report_SportFDQuery -> RecordCount;
        sud++) {
            if ( (DataModule2 -> Report_SportFDQuerySUD_CATEGORY -> Value != 0) &&
                (!DataModule2 -> Report_SportFDQuerySUD_CATEGORY -> IsNull)) {
                St1 = St1 +
                    DataModule2 -> Report_SportFDQueryVID_SPORT -> Value + " - ";
                switch (DataModule2 -> Report_SportFDQuerySUD_CATEGORY -> Value) {
                case 1:
                    St1 = St1 + "Судья по спорту";
                    break;
                case 2:
                    St1 = St1 + "Судья 1 категории";
                    break;
                case 3:
                    St1 = St1 + "Судья национальной категории";
                    break;
                case 4:
                    St1 = St1 + "Судья высшей национальной категории";
                    break;
                case 5:
                    St1 = St1 + "Судья международной категории";
                    break;
                }

                if (DataModule2 -> Report_SportFDQueryWHO_GIVE_SUD -> Value != "")
                    St1 = St1 + ", " +
                        DataModule2 -> Report_SportFDQueryWHO_GIVE_SUD -> Value;
                if (DataModule2 -> Report_SportFDQueryN_PRIKAZ_SUD -> Value != 0)
                    St1 = St1 + " №" +
                        IntToStr (DataModule2 -> Report_SportFDQueryN_PRIKAZ_SUD
                    -> Value);
                if (!DataModule2 -> Report_SportFDQueryD_PRIKAZ_SUD -> AsVariant.
                    IsNull ())
                    St1 = St1 + " " + DateToStr
                        (SQLTimeStampToDateTime
                    (DataModule2 -> Report_SportFDQueryD_PRIKAZ_SUD -> Value));
                // Проставить запятую
                if (sud < DataModule2 -> Report_SportFDQuery -> RecordCount)
                    St1 = St1 + ". ";
            }

            DataModule2 -> Report_SportFDQuery -> Next ();
        } // конец цикл суд. категория

        P_F (378, 283, 341, 36, TFontStyles (), 9, "Arial", haCenter, vaCenter,
            TfrxFrameTypes () << ftBottom, St1, nom,
            DataModule2 -> frxReport1, 0); // 18+18=36
        P_F (378, 301 + 18, 341, 12, TFontStyles (), 7, "Arial", haCenter,
            vaCenter, TfrxFrameTypes (),
            "Судейская категория, кем присвоена категория, номер и дата приказа",
            nom, DataModule2 -> frxReport1, 0);

        // Page -> Objects -> Add (P_F (36,283+kof,683,18,0,10,"Arial",0,2,St1));
        // Page -> Objects -> Add (P_F (36,301+kof,683,12,0,7,"Arial",2,0,"Судейская категория, кем присвоена категория, номер и дата приказа"));
        kof = kof + 12 + 18;
        // DataModule2 -> Report_SportFDQuery -> Next ();

        /////Таблицы из учебной карточки
        // Приказы на отчисление или восстановление
        P_F (235, 301 + kof, 288, 19, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaTop, TfrxFrameTypes (),
            "Приказы на отчисление и восстановление", nom,
            DataModule2 -> frxReport1, 0);
        kof = kof + 19;
        // Формирование Query приказов для отчисленных
        DataModule2 -> Report_Ut_Prik_Restore_OtFDQuery -> Close ();
        DataModule2 -> Report_Ut_Prik_Restore_OtFDQuery -> ParamByName ("NOMER")
            -> Value = DataModule2 -> Report_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Ut_Prik_Restore_OtFDQuery -> Open ();
        // Формирование Query приказов для восстановленных
        DataModule2 -> Report_Ut_Prik_Restore_VosFDQuery -> Close ();
        DataModule2 -> Report_Ut_Prik_Restore_VosFDQuery -> ParamByName ("NOMER")
            -> Value = DataModule2 -> Report_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Ut_Prik_Restore_VosFDQuery -> Open ();
        // Шапка таблицы
        P_F (36, 301 + kof, 60, 36, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "№",
            nom, DataModule2 -> frxReport1, 0);
        P_F (97, 301 + kof, 177, 36, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "№ и дата приказа на отчисление", nom, DataModule2 -> frxReport1, 0);
        P_F (275, 301 + kof, 272, 36, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "Причина отчисления", nom, DataModule2 -> frxReport1, 0);
        P_F (546, 301 + kof, 176, 36, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "№ и дата приказа на восстанов.", nom, DataModule2 -> frxReport1, 0);
        DataModule2 -> Report_Ut_Prik_Restore_OtFDQuery -> First ();
        kof = kof + 36;
        for (int ot = 1; ot <= 3; ot++) // было до 5
        {
            /* Page -> Objects -> Add (P_F (36,301+kof,60,30,2,10,"Arial",2+8,15,IntToStr (ot)));  //везде высота была 18, теперь 30
             //Определение приказав на отчисление
             if (!DataModule2 -> Report_Ut_Prik_Restore_OtFDQuery -> Eof)
             Page -> Objects -> Add (P_F (97,301+kof,177,30,0,9,"Arial",0+8,15,"№"+IntToStr (DataModule2 -> Report_Ut_Prik_Restore_OtN_PRIKAZ_RES -> Value)+" от "+DateToStr (DataModule2 -> Report_Ut_Prik_Restore_OtD_PRIKAZ_RES -> Value)));
             //Определение приказав на отчисление если нет уже записей
             else
             Page -> Objects -> Add (P_F (97,301+kof,177,30,0,10,"Arial",0,15,""));
             //Причина отчисления
             if (!DataModule2 -> Report_Ut_Prik_Restore_OtFDQuery -> Eof)   //был шрифт 8 стал 7
             Page -> Objects -> Add (P_F (275,301+kof,272,30,0,7,"Arial",0+8,15,DataModule2 -> Report_Ut_Prik_Restore_OtCAUSE_RES -> Value+" "+DataModule2 -> Report_Ut_Prik_Restore_OtDESCRIBE -> Value));
             //Определение причины отчисление если нет уже записей
             else
             Page -> Objects -> Add (P_F (275,301+kof,272,30,0,10,"Arial",0,15,""));
             //Определение приказов на востановление
             if (!DataModule2 -> Report_Ut_Prik_Restore_VosFDQuery -> Eof)
             Page -> Objects -> Add (P_F (546,301+kof,176,30,0,9,"Arial",0+8,15,"№"+IntToStr (DataModule2 -> Report_Ut_Prik_Restore_VosN_PRIKAZ_RES -> Value)+" от "+DateToStr (DataModule2 -> Report_Ut_Prik_Restore_VosD_PRIKAZ_RES -> Value)));
             //Определение приказов на востановление если нет уже записей
             else
             Page -> Objects -> Add (P_F (546,301+kof,176,30,0,10,"Arial",0,15,"")); */

            AnsiString desc = "";
            P_F (36, 301 + kof, 60, 30, TFontStyles () << fsBold, 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                IntToStr (ot), nom, DataModule2 -> frxReport1, 0);
            // везде высота была 18, теперь 30
            // Определение приказав на отчисление
            if (!DataModule2 -> Report_Ut_Prik_Restore_OtFDQuery -> Eof) {
                P_F (97, 301 + kof, 177, 30, TFontStyles (), 9, "Arial", haCenter,
                    vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "№" + IntToStr
                    (DataModule2 -> Report_Ut_Prik_Restore_OtFDQueryN_PRIKAZ_RES -> 
                    Value) + " от " + DateToStr
                    (SQLTimeStampToDateTime
                    (DataModule2 -> Report_Ut_Prik_Restore_OtFDQueryD_PRIKAZ_RES -> 
                    Value)), nom, DataModule2 -> frxReport1, 0);
                desc = DataModule2 -> 
                    Report_Ut_Prik_Restore_OtFDQueryCAUSE_RES -> Value;
                if (DataModule2 -> Report_Ut_Prik_Restore_OtFDQueryDESCRIBE -> 
                    Value != "")
                    desc += " " +
                        DataModule2 -> 
                        Report_Ut_Prik_Restore_OtFDQueryDESCRIBE -> Value;
            }
            // Определение приказав на отчисление если нет уже записей
            else
                P_F (97, 301 + kof, 177, 30, TFontStyles (), 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);

            // Определение приказов на востановление
            if (!DataModule2 -> Report_Ut_Prik_Restore_VosFDQuery -> Eof) {
                P_F (546, 301 + kof, 176, 30, TFontStyles (), 9, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "№" + IntToStr
                    (DataModule2 -> Report_Ut_Prik_Restore_VosFDQueryN_PRIKAZ_RES
                    -> Value) + " от " + DateToStr
                    (SQLTimeStampToDateTime
                    (DataModule2 -> Report_Ut_Prik_Restore_VosFDQueryD_PRIKAZ_RES
                    -> Value)), nom, DataModule2 -> frxReport1, 0);
                if (desc != "")
                    desc += "; ";
                desc += DataModule2 -> 
                    Report_Ut_Prik_Restore_VosFDQueryDESCRIBE -> Value;
            }
            // Определение приказов на востановление если нет уже записей
            else
                P_F (546, 301 + kof, 176, 30, TFontStyles (), 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);

            // Причина отчисления
            if (desc != "")
                P_F (275, 301 + kof, 272, 30, TFontStyles (), 7, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                desc, nom, DataModule2 -> frxReport1, 0);
            // Определение причины отчисление если нет уже записей
            else
                P_F (275, 301 + kof, 272, 30, TFontStyles (), 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);

            // Формирование след. строки
            kof = kof + 30; // было  +18
            // На следующую запись по отчисленным
            if (!DataModule2 -> Report_Ut_Prik_Restore_OtFDQuery -> Eof)
                DataModule2 -> Report_Ut_Prik_Restore_OtFDQuery -> Next ();
            // На следующую запись по востановленным
            if (!DataModule2 -> Report_Ut_Prik_Restore_VosFDQuery -> Eof)
                DataModule2 -> Report_Ut_Prik_Restore_VosFDQuery -> Next ();

        }

        // Академические отпуска
        P_F (235, 301 + kof, 288, 19, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaTop, TfrxFrameTypes (), "Отпуска", nom,
            DataModule2 -> frxReport1, 0);
        kof = kof + 19;

        // Шапка таблицы
        P_F (36, 301 + kof, 60, 36, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "№",
            nom, DataModule2 -> frxReport1, 0);
        P_F (97, 301 + kof, 177, 36, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "Тип",
            nom, DataModule2 -> frxReport1, 0);
        P_F (275, 301 + kof, 164, 18, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "Дата",
            nom, DataModule2 -> frxReport1, 0);
        P_F (275, 301 + kof + 18, 82, 18, TFontStyles () << fsBold, 8, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "с",
            nom, DataModule2 -> frxReport1, 0);
        P_F (357, 301 + kof + 18, 82, 18, TFontStyles () << fsBold, 8, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "по",
            nom, DataModule2 -> frxReport1, 0);
        P_F (440, 301 + kof, 105, 36, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "№ и дата приказа", nom, DataModule2 -> frxReport1, 0);
        P_F (546, 301 + kof, 176, 36, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "Причина", nom, DataModule2 -> frxReport1, 0);
        // Подготовка Query по академ. отпускам
        DataModule2 -> Report_Ut_HolidayFDQuery -> Close ();
        DataModule2 -> Report_Ut_HolidayFDQuery -> ParamByName ("NOMER") -> Value =
            DataModule2 -> Report_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Ut_HolidayFDQuery -> Open ();
        DataModule2 -> Report_Ut_HolidayFDQuery -> First ();
        kof = kof + 36;
        for (int holiday = 1; holiday <= 5; holiday++) {
            P_F (36, 301 + kof, 60, 18, TFontStyles () << fsBold, 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                IntToStr (holiday), nom, DataModule2 -> frxReport1, 0);
            // Тип а/о
            if (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof) {
                switch (DataModule2 -> Report_Ut_HolidayFDQueryTYPE_HOL -> Value)
                { // ---старая часть по приказам до сентября 2006 года
                case 1:
                    P_F (97, 301 + kof, 177, 18, TFontStyles (), 8, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Уход в академ. отпуск", nom,
                        DataModule2 -> frxReport1, 0);
                    break;
                case 2:
                    P_F (97, 301 + kof, 177, 18, TFontStyles (), 8, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Академ. отпуск продлен", nom,
                        DataModule2 -> frxReport1, 0);
                    break;
                case 3:
                    P_F (97, 301 + kof, 177, 18, TFontStyles (), 8, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Считать вернувшимся из а/о", nom,
                        DataModule2 -> frxReport1, 0);
                    break;
                    // ------новая часть
                case 4:
                    P_F (97, 301 + kof, 177, 18, TFontStyles (), 8, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Академический отпуск", nom,
                        DataModule2 -> frxReport1, 0);
                    break;
                case 5:
                    P_F (97, 301 + kof, 177, 18, TFontStyles (), 8, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Продление академ. отпуска", nom,
                        DataModule2 -> frxReport1, 0);
                    break;
                case 6:
                    P_F (97, 301 + kof, 177, 18, TFontStyles (), 8, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Выход из отпуска", nom, DataModule2 -> frxReport1, 0);
                    break;
                case 7:
                    P_F (97, 301 + kof, 177, 18, TFontStyles (), 8, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Отпуск по беременности и родам", nom,
                        DataModule2 -> frxReport1, 0);
                    break;
                case 8:
                    P_F (97, 301 + kof, 177, 18, TFontStyles (), 6, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Отпуск по уходу за ребенком до 3-х лет", nom,
                        DataModule2 -> frxReport1, 0);
                    break;
                case 9:
                    P_F (97, 301 + kof, 177, 18, TFontStyles (), 5, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Отпуск по уходу за ребенком до 3-х лет со свободным посещением",
                        nom, DataModule2 -> frxReport1, 0);
                    break;

                case 10:
                    P_F (97, 301 + kof, 177, 18, TFontStyles (), 8, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Отпуск по беременности", nom,
                        DataModule2 -> frxReport1, 0);
                    break;
                case 11:
                    P_F (97, 301 + kof, 177, 18, TFontStyles (), 7, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Отпуск для прохождения военной службы", nom,
                        DataModule2 -> frxReport1, 0);
                    break;
                } // switch
            }
            else
                P_F (97, 301 + kof, 177, 18, TFontStyles (), 9, "Arial", haCenter,
                vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);

            if (DataModule2 -> Report_Ut_HolidayFDQueryTYPE_HOL -> Value == 3 ||
                DataModule2 -> Report_Ut_HolidayFDQueryTYPE_HOL -> Value == 6)
            { // if  выбран приказ выход из а/о
                // Дата с
                if (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof)
                    P_F (275, 301 + kof, 82, 18, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    SQLTimeStampToDateTime (DataModule2 -> 
                    Report_Ut_HolidayFDQueryD_END_HOL -> Value).DateString (), nom,
                    DataModule2 -> frxReport1, 0);
                else
                    P_F (275, 301 + kof, 82, 18, TFontStyles (), 9, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                // Дата по
                if ( (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof) &&
                    (DataModule2 -> Report_Ut_HolidayFDQueryD_END_HOL -> 
                    AsString != ""))
                    P_F (357, 301 + kof, 82, 18, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                else
                    P_F (357, 301 + kof, 82, 18, TFontStyles (), 9, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                // Номер и дата приказа
                if (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof)
                    P_F (440, 301 + kof, 105, 18, TFontStyles (), 7, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "№" + IntToStr
                    (DataModule2 -> Report_Ut_HolidayFDQueryN_PRIKAZ_HOL -> Value) +
                    " от " + DateToStr (SQLTimeStampToDateTime
                    (DataModule2 -> Report_Ut_HolidayFDQueryD_PRIKAZ_HOL -> Value)),
                    nom, DataModule2 -> frxReport1, 0);
                else
                    P_F (440, 301 + kof, 105, 18, TFontStyles (), 9, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                // Причина
                if ( (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof) &&
                    (DataModule2 -> Report_Ut_HolidayFDQueryCAUSE_HOL -> Value
                    != "Нет"))
                    P_F (546, 301 + kof, 176, 18, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    DataModule2 -> Report_Ut_HolidayFDQueryCAUSE_HOL -> Value, nom,
                    DataModule2 -> frxReport1, 0);
                else
                    P_F (546, 301 + kof, 176, 18, TFontStyles (), 9, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
            } // end if выбран приказ выход из а/о
            else { // else если выбран тип приказа НЕ выход из а/о
                // Дата с
                if ( (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof) &&
                    (DataModule2 -> Report_Ut_HolidayFDQueryD_BEGIN_HOL -> 
                    AsString != ""))
                    P_F (275, 301 + kof, 82, 18, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    SQLTimeStampToDateTime (DataModule2 -> 
                    Report_Ut_HolidayFDQueryD_BEGIN_HOL -> Value).DateString (),
                    nom, DataModule2 -> frxReport1, 0);
                else
                    P_F (275, 301 + kof, 82, 18, TFontStyles (), 9, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                // Дата по
                if ( (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof) &&
                    (DataModule2 -> Report_Ut_HolidayFDQueryD_END_HOL -> 
                    AsString != ""))
                    P_F (357, 301 + kof, 82, 18, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    SQLTimeStampToDateTime (DataModule2 -> 
                    Report_Ut_HolidayFDQueryD_END_HOL -> Value).DateString (), nom,
                    DataModule2 -> frxReport1, 0);
                else
                    P_F (357, 301 + kof, 82, 18, TFontStyles (), 9, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                // Номер и дата приказа
                if (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof)
                    P_F (440, 301 + kof, 105, 18, TFontStyles (), 7, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "№" + IntToStr
                    (DataModule2 -> Report_Ut_HolidayFDQueryN_PRIKAZ_HOL -> Value) +
                    " от " + DateToStr (SQLTimeStampToDateTime
                    (DataModule2 -> Report_Ut_HolidayFDQueryD_PRIKAZ_HOL -> Value)),
                    nom, DataModule2 -> frxReport1, 0);
                else
                    P_F (440, 301 + kof, 105, 18, TFontStyles (), 9, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                // Причина
                if ( (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof) &&
                    (DataModule2 -> Report_Ut_HolidayFDQueryCAUSE_HOL -> Value
                    != "Нет"))
                    P_F (546, 301 + kof, 176, 18, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    DataModule2 -> Report_Ut_HolidayFDQueryCAUSE_HOL -> Value, nom,
                    DataModule2 -> frxReport1, 0);
                else
                    P_F (546, 301 + kof, 176, 18, TFontStyles (), 9, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);

            } // end else если выбран тип приказа НЕ выход из а/о

            // Формирование след. строки
            kof = kof + 18;
            // На следующую запись по академистам
            if (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof)
                DataModule2 -> Report_Ut_HolidayFDQuery -> Next ();

        }

        // Разные приказы
        P_F (235, 301 + kof, 288, 19, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaTop, TfrxFrameTypes (), "Разные приказы", nom,
            DataModule2 -> frxReport1, 0);
        kof = kof + 19;

        // Шапка таблицы
        P_F (36, 301 + kof, 60, 36, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "№",
            nom, DataModule2 -> frxReport1, 0);
        P_F (97, 301 + kof, 177, 36, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "Тип приказа", nom, DataModule2 -> frxReport1, 0);
        P_F (275, 301 + kof, 272, 36, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "Примечание", nom, DataModule2 -> frxReport1, 0);
        P_F (546, 301 + kof, 176, 36, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "№ и дата приказа", nom, DataModule2 -> frxReport1, 0);
        DataModule2 -> Report_Ut_Prik_Restore_OtFDQuery -> First ();
        kof = kof + 36;
        int ch = 1;
        // Изменение фамилии
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Close ();
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("NOMER")
            -> Value = DataModule2 -> Report_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("TYPE")
            -> Value = 2;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Open ();
        if (DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount != 0) {
            for (int raz = 1;
            raz <= DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount;
            raz++) {
                P_F (36, 301 + kof, 60, 18, TFontStyles () << fsBold, 10, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    IntToStr (ch), nom, DataModule2 -> frxReport1, 0);
                P_F (97, 301 + kof, 177, 18, TFontStyles (), 8, "Arial", haCenter,
                    vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "Изменение фамилии", nom, DataModule2 -> frxReport1, 0);
                // Describe
                P_F (275, 301 + kof, 272, 18, TFontStyles (), 7, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "Старая фамилия " +
                    DataModule2 -> Report_Ut_Public_PrikazFDQueryDESCRIBE -> Value,
                    nom, DataModule2 -> frxReport1, 0);
                P_F (546, 301 + kof, 176, 18, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "№" + IntToStr
                    (DataModule2 -> Report_Ut_Public_PrikazFDQueryN_PUBLIC_PRIKAZ
                    -> Value) + " от " + DateToStr
                    (SQLTimeStampToDateTime
                    (DataModule2 -> Report_Ut_Public_PrikazFDQueryD_PUBLIC_PRIKAZ
                    -> Value)), nom, DataModule2 -> frxReport1, 0);
                // Формирование след. строки
                kof = kof + 18;
                DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Next ();
                ch = ch + 1;
            } // for
        } // if DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount!=0
        // Перевод
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Close ();
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("NOMER")
            -> Value = DataModule2 -> Report_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("TYPE")
            -> Value = 6;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Open ();
        if (DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount != 0) {
            for (int raz1 = 1;
            raz1 <= DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount;
            raz1++) {
                P_F (36, 301 + kof, 60, 18, TFontStyles () << fsBold, 10, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    IntToStr (ch), nom, DataModule2 -> frxReport1, 0);
                P_F (97, 301 + kof, 177, 18, TFontStyles (), 8, "Arial", haCenter,
                    vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "Перевод", nom, DataModule2 -> frxReport1, 0);
                // Describe
                P_F (275, 301 + kof, 272, 18, TFontStyles (), 7, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "Переведен " +
                    DataModule2 -> Report_Ut_Public_PrikazFDQueryDESCRIBE -> Value,
                    nom, DataModule2 -> frxReport1, 0);
                P_F (546, 301 + kof, 176, 18, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "№" + IntToStr
                    (DataModule2 -> Report_Ut_Public_PrikazFDQueryN_PUBLIC_PRIKAZ
                    -> Value) + " от " + DateToStr
                    (SQLTimeStampToDateTime
                    (DataModule2 -> Report_Ut_Public_PrikazFDQueryD_PUBLIC_PRIKAZ
                    -> Value)), nom, DataModule2 -> frxReport1, 0);
                // Формирование след. строки
                kof = kof + 18;
                DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Next ();
                ch = ch + 1;
            } // for
        } // if DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount!=0
        // Индивидуальный график
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Close ();
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("NOMER")
            -> Value = DataModule2 -> Report_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("TYPE")
            -> Value = 4;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Open ();
        if (DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount != 0) {
            for (int raz2 = 1;
            raz2 <= DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount;
            raz2++) {
                P_F (36, 301 + kof, 60, 18, TFontStyles () << fsBold, 10, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    IntToStr (ch), nom, DataModule2 -> frxReport1, 0);
                P_F (97, 301 + kof, 177, 18, TFontStyles (), 8, "Arial", haCenter,
                    vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "Индивидуальный график", nom, DataModule2 -> frxReport1, 0);
                // Describe
                P_F (275, 301 + kof, 272, 18, TFontStyles (), 7, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    DataModule2 -> Report_Ut_Public_PrikazFDQueryDESCRIBE -> Value,
                    nom, DataModule2 -> frxReport1, 0);
                P_F (546, 301 + kof, 176, 18, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    " №" + IntToStr
                    (DataModule2 -> Report_Ut_Public_PrikazFDQueryN_PUBLIC_PRIKAZ
                    -> Value) + " от " + DateToStr
                    (SQLTimeStampToDateTime
                    (DataModule2 -> Report_Ut_Public_PrikazFDQueryD_PUBLIC_PRIKAZ
                    -> Value)), nom, DataModule2 -> frxReport1, 0);
                // Формирование след. строки
                kof = kof + 18;
                DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Next ();
                ch = ch + 1;

            } // for
        } // if DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount!=0
        // Перевод из друго вуза
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Close ();
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("NOMER")
            -> Value = DataModule2 -> Report_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("TYPE")
            -> Value = 7;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Open ();
        if (DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount != 0) {
            for (int raz3 = 1;
            raz3 <= DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount;
            raz3++) {
                P_F (36, 301 + kof, 60, 18, TFontStyles () << fsBold, 10, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    IntToStr (ch), nom, DataModule2 -> frxReport1, 0);
                P_F (97, 301 + kof, 177, 18, TFontStyles (), 8, "Arial", haCenter,
                    vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "Перевод из другого Вуза", nom, DataModule2 -> frxReport1, 0);
                // Describe
                P_F (275, 301 + kof, 272, 18, TFontStyles (), 7, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    DataModule2 -> Report_Ut_Public_PrikazFDQueryDESCRIBE -> Value,
                    nom, DataModule2 -> frxReport1, 0);
                P_F (546, 301 + kof, 176, 18, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "№" + IntToStr
                    (DataModule2 -> Report_Ut_Public_PrikazFDQueryN_PUBLIC_PRIKAZ
                    -> Value) + " от " + DateToStr
                    (SQLTimeStampToDateTime
                    (DataModule2 -> Report_Ut_Public_PrikazFDQueryD_PUBLIC_PRIKAZ
                    -> Value)), nom, DataModule2 -> frxReport1, 0);
                // Формирование след. строки
                kof = kof + 18;
                DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Next ();
                ch = ch + 1;

            } // for
        } // if DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount!=0

        // Допуск к ГОС-экзамену
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Close ();
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("NOMER")
            -> Value = DataModule2 -> Report_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("TYPE")
            -> Value = 12;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Open ();
        if (DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount != 0) {
            for (int raz3 = 1;
            raz3 <= DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount;
            raz3++) {
                P_F (36, 301 + kof, 60, 18, TFontStyles () << fsBold, 10, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    IntToStr (ch), nom, DataModule2 -> frxReport1, 0);
                P_F (97, 301 + kof, 177, 18, TFontStyles (), 8, "Arial", haCenter,
                    vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "Приказ на допуск", nom, DataModule2 -> frxReport1, 0);
                // Describe
                P_F (275, 301 + kof, 272, 18, TFontStyles (), 7, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "К сдаче государственных экзаменов", nom,
                    DataModule2 -> frxReport1, 0);
                P_F (546, 301 + kof, 176, 18, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "№" + IntToStr
                    (DataModule2 -> Report_Ut_Public_PrikazFDQueryN_PUBLIC_PRIKAZ
                    -> Value) + " от " + DateToStr
                    (SQLTimeStampToDateTime
                    (DataModule2 -> Report_Ut_Public_PrikazFDQueryD_PUBLIC_PRIKAZ
                    -> Value)), nom, DataModule2 -> frxReport1, 0);
                // Формирование след. строки
                kof = kof + 18;
                DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Next ();
                ch = ch + 1;

            } // for
        } // if DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount!=0

        // 25.03.2014 - на допуск к защите диплома

        // Допуск к ГОС-экзамену
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Close ();
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("NOMER")
            -> Value = DataModule2 -> Report_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("TYPE")
            -> Value = 13;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Open ();
        if (DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount != 0) {
            for (int raz3 = 1;
            raz3 <= DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount;
            raz3++) {
                P_F (36, 301 + kof, 60, 18, TFontStyles () << fsBold, 10, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    IntToStr (ch), nom, DataModule2 -> frxReport1, 0);
                P_F (97, 301 + kof, 177, 18, TFontStyles (), 8, "Arial", haCenter,
                    vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "Приказ на допуск", nom, DataModule2 -> frxReport1, 0);
                // Describe
                P_F (275, 301 + kof, 272, 18, TFontStyles (), 7, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "К защите диплома", nom, DataModule2 -> frxReport1, 0);
                P_F (546, 301 + kof, 176, 18, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "№" + IntToStr
                    (DataModule2 -> Report_Ut_Public_PrikazFDQueryN_PUBLIC_PRIKAZ
                    -> Value) + " от " + DateToStr
                    (SQLTimeStampToDateTime
                    (DataModule2 -> Report_Ut_Public_PrikazFDQueryD_PUBLIC_PRIKAZ
                    -> Value)), nom, DataModule2 -> frxReport1, 0);
                // Формирование след. строки
                kof = kof + 18;
                DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Next ();
                ch = ch + 1;

            } // for
        } // if DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount!=0

        if (ch <= 5) {
            for (int raz4 = ch; raz4 <= 5; raz4++) {
                P_F (36, 301 + kof, 60, 18, TFontStyles () << fsBold, 10, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    IntToStr (ch), nom, DataModule2 -> frxReport1, 0);
                P_F (97, 301 + kof, 177, 18, TFontStyles (), 8, "Arial", haCenter,
                    vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                // Describe
                P_F (275, 301 + kof, 272, 18, TFontStyles (), 7, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                P_F (546, 301 + kof, 176, 18, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                // Формирование след. строки
                kof = kof + 18;
                ch = ch + 1;

            } // for

        }

        /////////////////////////////////////////////////
        // Строки по диплому
        int k = 520; // 500;
        DataModule2 -> Report_DiplomaFDQuery -> Close ();
        DataModule2 -> Report_DiplomaFDQuery -> ParamByName ("NOMER") -> Value =
            DataModule2 -> Report_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_DiplomaFDQuery -> Open ();

        P_F (36, 450 + k, 290, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "Дата окончания учреждения образования",
            nom, DataModule2 -> frxReport1, 0);
        /* было раньше; теперь   D_VIPUSK-дата вручения диплома, D_PRIKAZ_KURS-дата окончания учебного заведения
         if (!DataModule2 -> Report_DiplomaQueryD_VIPUSK -> AsVariant.IsNull ())
         Page -> Objects -> Add (P_F (286,450+k,124,18,0,10,"Arial",0,2,DateToStr (DataModule2 -> Report_DiplomaQueryD_VIPUSK -> Value)));
         */
        if (!DataModule2 -> Report_CardFDQueryD_PRIKAZ_KURS -> AsVariant.IsNull ())
            P_F (326, 450 + k, 124, 18, TFontStyles (), 10, "Arial", haCenter,
            vaCenter, TfrxFrameTypes () << ftBottom,
            DateToStr (SQLTimeStampToDateTime
            (DataModule2 -> Report_CardFDQueryD_PRIKAZ_KURS -> Value)), nom,
            DataModule2 -> frxReport1, 0);
        else
            P_F (326, 450 + k, 124, 18, TFontStyles (), 10, "Arial", haCenter,
            vaCenter, TfrxFrameTypes () << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);

        P_F (450, 450 + k, 90, 18, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter, TfrxFrameTypes (), "№ Диплома", nom,
            DataModule2 -> frxReport1, 0);

        if (DataModule2 -> Report_DiplomaFDQueryN_DIPLOM -> Value != "")
            P_F (540, 450 + k, 181, 18, TFontStyles (), 10, "Arial", haCenter,
            vaCenter, TfrxFrameTypes () << ftBottom,
            DataModule2 -> Report_DiplomaFDQueryN_DIPLOM -> Value, nom,
            DataModule2 -> frxReport1, 0);
        else
            P_F (540, 450 + k, 181, 18, TFontStyles (), 10, "Arial", haCenter,
            vaCenter, TfrxFrameTypes () << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);

        P_F (36, 468 + k, 225, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "Куда направлен на работу", nom,
            DataModule2 -> frxReport1, 0);

        if (DataModule2 -> Report_DiplomaFDQueryN_RASPRED_WORK -> Value != 0)
            P_F (241, 468 + k, 460, 18, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter, TfrxFrameTypes () << ftBottom,
            IntToStr (DataModule2 -> Report_DiplomaFDQueryN_RASPRED_WORK -> Value),
            nom, DataModule2 -> frxReport1, 0);
        else
            P_F (241, 468 + k, 460, 18, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter, TfrxFrameTypes () << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);

        P_F (216, 486 + k, 138, 18, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter, TfrxFrameTypes (), "Нач. отдела кадров", nom,
            DataModule2 -> frxReport1, 0);
        // Для подписи
        P_F (356, 486 + k, 225, 18, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter, TfrxFrameTypes () << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);
        // Проверка   на 2 карточки на страницу
        /* if (R)
         {  k=500;
         R=false;

         }
         else
         { */
        /* if (i < DataModule2 -> Report_CardFDQuery -> RecordCount - 1) {
         // R=true;
         // k=0;
         nom = nom + 1;
         TfrxReportPage * Page =
         dynamic_cast<TfrxReportPage*> (frxReport1 -> Pages[nom]);
         // create page
         // !!!Page=frxReport1 -> Pages -> Pages[nom];
         } */
        // }

        DataModule2 -> Report_CardFDQuery -> Next ();

    } // for

}

// -----------------------------------------------------------------------------
void __fastcall TStudForm::Print_First ()
{ // функция печати первой стороны личной карточки
    TfrxReportPage * Page;
    // int k=0;//Переменная для смещения 2 карточки на лист
    // Добавление первой страницы
    // Page = new TfrxReportPage (DataModule2 -> frxReport1);
    /* TfrxReportPage * Page = dynamic_cast<TfrxReportPage*>
     (DataModule2 -> frxReport1 -> Pages[nom]); // create page */
    // DataModule2 -> frxReport1 -> Pages -> Add ();  // create page
    // Page=DataModule2 -> frxReport1 -> Pages[nom];

    // bool R=true; //Переключатель для 2 кар. на лист
    for (int i = 0; i < DataModule2 -> Report_CardFDQuery -> RecordCount; i++) {
        int nom = i;
        Page = new TfrxReportPage (DataModule2 -> frxReport1);

        P_F (222, 61, 312, 26, TFontStyles () << fsBold, 16, "", haCenter,
            vaCenter, TfrxFrameTypes (), "Личная карточка студента", nom,
            DataModule2 -> frxReport1, 0);

        pic = new TfrxPictureView (DataModule2 -> frxReport1 -> Pages[nom]);

        pic -> SetBounds (648, 55, 73, 102);

        // Формирование входного массива
        /* Variant photo = & (DataModule2 -> Report_CardFDQueryPHOTO -> Value);
         ph = photo.AsType (varString); */

        if (! (TBlobField*)DataModule2 -> Report_CardFDQueryPHOTO -> IsNull) {
            pot = new TFDBlobStream (DataModule2 -> Report_CardFDQueryPHOTO,
            bmRead);
            jpga = new Jpeg::TJPEGImage ();
            // показ Image картинки из базы
            pot -> Position = 0;
            // DataModule2 -> Report_CardQueryPHOTO -> SaveToStream (pot)
            jpga -> LoadFromStream (pot);
            pic -> Picture -> Assign (jpga);
        }
        else
            P_F (648, 55, 73, 102, TFontStyles (), 10, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "Нет фото", nom, DataModule2 -> frxReport1, 0);

        P_F (107, 113, 542, 18, TFontStyles () << fsBold, 12, "", haCenter,
            vaCenter, TfrxFrameTypes (),
            "Белорусский государственный университет физической культуры", nom,
            DataModule2 -> frxReport1, 0);

        P_F (36, 159, 84, 18, TFontStyles () << fsBold, 10, "Arial", haCenter,
            vaCenter, TfrxFrameTypes (), "1. Фамилия", nom,
            DataModule2 -> frxReport1, 0);

        if (DataModule2 -> Report_CardFDQueryFAM -> Value != "")
            P_F (120, 159, 178, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom,
            DataModule2 -> Report_CardFDQueryFAM -> Value, nom,
            DataModule2 -> frxReport1, 0);
        else
            P_F (120, 159, 178, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

        P_F (295, 159, 31, 18, TFontStyles () << fsBold, 10, "Arial", haCenter,
            vaCenter, TfrxFrameTypes (), "Имя", nom, DataModule2 -> frxReport1, 0);

        if (DataModule2 -> Report_CardFDQueryNAME -> Value != "")
            P_F (329, 159, 136, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom,
            DataModule2 -> Report_CardFDQueryNAME -> Value, nom,
            DataModule2 -> frxReport1, 0);
        else
            P_F (329, 159, 136, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

        P_F (466, 159, 65, 18, TFontStyles () << fsBold, 10, "Arial", haCenter,
            vaCenter, TfrxFrameTypes (), "Отчество", nom,
            DataModule2 -> frxReport1, 0);

        if (DataModule2 -> Report_CardFDQueryOTCH -> Value != "")
            P_F (536, 159, 191, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom,
            DataModule2 -> Report_CardFDQueryOTCH -> Value, nom,
            DataModule2 -> frxReport1, 0);
        else
            P_F (536, 159, 191, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

        P_F (36, 201, 55, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "2. Пол", nom,
            DataModule2 -> frxReport1, 0);

        if (DataModule2 -> Report_CardFDQueryPOL -> Value != "")
            P_F (87, 201, 56, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom,
            DataModule2 -> Report_CardFDQueryPOL -> Value, nom,
            DataModule2 -> frxReport1, 0);
        else
            P_F (87, 201, 56, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

        P_F (145, 201, 122, 18, TFontStyles () << fsBold, 10, "Arial", haCenter,
            vaCenter, TfrxFrameTypes (), "3. Дата рождения", nom,
            DataModule2 -> frxReport1, 0);

        if (DataModule2 -> Report_CardFDQueryDATA_R -> AsString != "")
            P_F (267, 201, 77, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom,
            DateToStr (SQLTimeStampToDateTime
            (DataModule2 -> Report_CardFDQueryDATA_R -> Value)), nom,
            DataModule2 -> frxReport1, 0);
        else
            P_F (267, 201, 77, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

        P_F (342, 201, 129, 18, TFontStyles () << fsBold, 10, "Arial", haCenter,
            vaCenter, TfrxFrameTypes (), "4. Место рождения", nom,
            DataModule2 -> frxReport1, 0);

        if (DataModule2 -> Report_CardFDQueryPLACE_R -> Value != "")
            P_F (472, 181, 249, 38, TFontStyles (), 10, "Arial", haLeft, vaBottom,
            TfrxFrameTypes () << ftBottom,
            DataModule2 -> Report_CardFDQueryPLACE_R -> Value, nom,
            DataModule2 -> frxReport1, 0);
        else
            P_F (472, 181, 249, 38, TFontStyles (), 10, "Arial", haLeft, vaBottom,
            TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

        P_F (36, 231, 132, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "5. Национальность", nom,
            DataModule2 -> frxReport1, 0);

        if (DataModule2 -> Report_CardFDQueryNAZ -> Value != "")
            P_F (166, 231, 555, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom,
            DataModule2 -> Report_CardFDQueryNAZ -> Value, nom,
            DataModule2 -> frxReport1, 0);
        else
            P_F (166, 231, 555, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes (), "", nom, DataModule2 -> frxReport1, 0);

        P_F (36, 267, 128, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "6. Образование", nom,
            DataModule2 -> frxReport1, 0);

        AnsiString obr = "";
        if (DataModule2 -> Report_CardFDQueryEDUCATION -> Value != Null ()) {
            switch (DataModule2 -> Report_CardFDQueryEDUCATION -> Value) {
            case 1:
                obr = "среднее";
                break;
            case 2:
                obr = "среднее специальное";
                break;
            case 3:
                obr = "незаконченное высшее";
                break;
            case 4:
                obr = "высшее";
                break;
            case 5:
                obr = "профессионально-техническое";
                break;
            }
        }
        if (DataModule2 -> Report_CardFDQueryNAME_EDUC -> Value != "")
            obr = obr + ", " + DataModule2 -> Report_CardFDQueryNAME_EDUC -> Value;

        if (DataModule2 -> Report_CardFDQueryWHEN_EDUC -> Value != Null ())
            obr = obr + ", " + DataModule2 -> Report_CardFDQueryWHEN_EDUC -> Value;

        if (DataModule2 -> Report_CardFDQueryWHERE_EDUC -> Value != "")
            obr = obr + ", " + DataModule2 -> Report_CardFDQueryWHERE_EDUC -> Value;

        P_F (165, 252, 556, 34, TFontStyles (), 10, "Arial", haLeft, vaBottom,
            TfrxFrameTypes () << ftBottom, obr, nom, DataModule2 -> frxReport1, 0);

        P_F (164, 287, 557, 12, TFontStyles () << fsBold, 7, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (),
            "Какое учебное заведение закончил, когда и где", nom,
            DataModule2 -> frxReport1, 0);

        P_F (36, 303, 383, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (),
            "7. Выполняемая работа к моменту поступления в БГУФК", nom,
            DataModule2 -> frxReport1, 0);

        if (DataModule2 -> Report_CardFDQueryWORK_BEFORE -> Value != "")
            P_F (420, 303, 301, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom,
            DataModule2 -> Report_CardFDQueryWORK_BEFORE -> Value, nom,
            DataModule2 -> frxReport1, 0);
        else
            P_F (420, 303, 301, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

        P_F (36, 335, 149, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "8. Занятие родителей", nom,
            DataModule2 -> frxReport1, 0);

        if (DataModule2 -> Report_CardFDQueryPAPA -> Value != "")
            P_F (186, 335, 535, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom,
            "отец -- " + DataModule2 -> Report_CardFDQueryPAPA -> Value + ", " +
            DataModule2 -> Report_CardFDQueryWORK_PAPA -> Value, nom,
            DataModule2 -> frxReport1, 0);
        else
            P_F (186, 335, 535, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

        P_F (186, 355, 535, 12, TFontStyles () << fsBold, 7, "Arial", haCenter,
            vaCenter, TfrxFrameTypes (), "место работы с указанием должности",
            nom, DataModule2 -> frxReport1, 0);

        if (DataModule2 -> Report_CardFDQueryMAMA -> Value != "")
            P_F (186, 369, 535, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom,
            "мать -- " + DataModule2 -> Report_CardFDQueryMAMA -> Value + ", " +
            DataModule2 -> Report_CardFDQueryWORK_MAMA -> Value, nom,
            DataModule2 -> frxReport1, 0);
        else
            P_F (186, 369, 535, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

        P_F (36, 407, 132, 70, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaTop, TfrxFrameTypes (), "9. Домашний адрес", nom,
            DataModule2 -> frxReport1, 0);

        if (DataModule2 -> Report_CardFDQueryADDRESS_BEFORE -> Value != "")
            P_F (167, 407, 554, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom,
            "а) " + DataModule2 -> Report_CardFDQueryADDRESS_BEFORE -> Value, nom,
            DataModule2 -> frxReport1, 0);
        else
            P_F (167, 407, 554, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

        P_F (167, 426, 554, 12, TFontStyles () << fsBold, 7, "Arial", haCenter,
            vaCenter, TfrxFrameTypes (), "до поступления в БГУФК", nom,
            DataModule2 -> frxReport1, 0);

        if (DataModule2 -> Report_CardFDQueryADDRESS -> Value != "")
            P_F (167, 443, 554, 36, TFontStyles (), 10, "Arial", haLeft, vaTop,
            TfrxFrameTypes () << ftBottom,
            "б) " + DataModule2 -> Report_CardFDQueryADDRESS -> Value, nom,
            DataModule2 -> frxReport1, 0);
        else
            P_F (167, 443, 554, 36, TFontStyles (), 10, "Arial", haLeft, vaTop,
            TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

        // Линия
        TfrxLineView *Line4;
        Line4 = new TfrxLineView (Page);
        Line4 -> SetBounds (167, 461, 554, 36);

        P_F (167, 481, 554, 12, TFontStyles () << fsBold, 7, "Arial", haCenter,
            vaCenter, TfrxFrameTypes (), "прописка в настоящее время", nom,
            DataModule2 -> frxReport1, 0);
        // Page -> Objects -> Add (P_F (444,496,120,18,2,10,"Arial",0,0,"Личная подпись"));
        // Page -> Objects -> Add (P_F (564,496,160,18,0,10,"Arial",0,2,""));
        ////////////////////////////////////////////////////////////////////////////////////////
        int kof = 0;

        P_F (36, 561 + kof, 683, 18, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter, TfrxFrameTypes (),
            "Отметки о поощрениях и взысканиях", nom,
            DataModule2 -> frxReport1, 0);

        //
        P_F (36, 579 + kof, 683, 12, TFontStyles () << fsBold, 7, "Arial",
            haCenter, vaCenter, TfrxFrameTypes (),
            "Когда, за что и какое объявлено поощрение или наложено взыскание",
            nom, DataModule2 -> frxReport1, 0);

        // Цикл поощрений и взысканий
        DataModule2 -> Report_EncourageFDQuery -> Close ();
        DataModule2 -> Report_EncourageFDQuery -> ParamByName ("NOMER") -> Value =
            DataModule2 -> Report_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_EncourageFDQuery -> Open ();
        ///
        AnsiString St1 = "";
        kof = 12;
        for (int vz = 1; vz <= 24; vz++) {
            if ( (DataModule2 -> Report_EncourageFDQueryVID_EN -> Value != "") &&
                (!DataModule2 -> Report_EncourageFDQuery -> Eof)) {
                St1 = DataModule2 -> Report_EncourageFDQueryVID_EN -> Value;
                if (DataModule2 -> Report_EncourageFDQueryN_PRIKAZ -> Value != 0)
                    St1 = St1 + " Пр.№" +
                        IntToStr (DataModule2 -> Report_EncourageFDQueryN_PRIKAZ
                    -> Value);

                if (!DataModule2 -> Report_EncourageFDQueryD_PRIKAZ -> AsVariant.
                    IsNull ())
                    St1 = St1 + " от" + DateToStr
                        (SQLTimeStampToDateTime
                    (DataModule2 -> Report_EncourageFDQueryD_PRIKAZ -> Value));
                if (DataModule2 -> Report_EncourageFDQueryWHAT -> Value != "")
                    St1 = St1 + ", " +
                        DataModule2 -> Report_EncourageFDQueryWHAT -> Value;
                if (DataModule2 -> Report_EncourageFDQueryWHO_TAKE -> Value != "")
                    St1 = St1 + ", выносит: " +
                        DataModule2 -> Report_EncourageFDQueryWHO_TAKE -> Value;
                P_F (36, 579 + kof, 683, 18, TFontStyles (), 6, "Arial", haLeft,
                    vaCenter, TfrxFrameTypes () << ftBottom, St1, nom,
                    DataModule2 -> frxReport1, 0);
            } // if
            else {

                P_F (36, 579 + kof, 683, 18, TFontStyles (), 6, "Arial", haLeft,
                    vaCenter, TfrxFrameTypes () << ftBottom, "", nom,
                    DataModule2 -> frxReport1, 0);

            }
            kof = kof + 18; // было    kof=kof+18;
            DataModule2 -> Report_EncourageFDQuery -> Next ();

        } // конец цикл поощрений и взысканий

        ////////////////////////////////////////////////////////////////////////////////////////
        // Проверка   на 2 карточки на страницу

        /* if (i < DataModule2 -> Report_CardFDQuery -> RecordCount - 1) {
         // R=true;
         // k=0;
         TfrxReportPage * Page =
         dynamic_cast<TfrxReportPage*>
         (DataModule2 -> frxReport1 -> Pages[++nom]);
         } */
        // }

        DataModule2 -> Report_CardFDQuery -> Next ();

    } // for

}

// ---------------------------------------------------------------------------
__fastcall TStudForm::TStudForm (TComponent * Owner) : TForm (Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TStudForm::FormClose (TObject * Sender, TCloseAction & Action) {
    syst_ball = 10; // возвращаем 10-ти бальную систему по умолчанию
    KeyPressAd = 0; // режим редактирования данных по студенту
    // !!!if (Application -> MessageBox ("    Закрыть форму по личной карточке?", "", MB_YESNO) == mrYes)
    if (MessageDlg ("    Закрыть форму по личной карточке?", mtConfirmation,
        TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes) {

        if (DataModule1 -> PeopleFDQuery -> State != dsBrowse) {
            // !!!int fl=Application -> MessageBox ("    Сохранить изменения в личной карточке студента?", "", MB_YESNOCANCEL);
            int fl =
                MessageDlg ("    Сохранить изменения в личной карточке студента?"
                , mtCustom, TMsgDlgButtons () << mbYes << mbNo << mbCancel, 0);
            if (fl == mrYes) {
                DataModule1 -> PeopleFDQuery -> ApplyUpdates ();
                DataModule1 -> PeopleFDQuery -> CommitUpdates ();
                delete pms;
                delete jp;
                result_itog = false;
                Action = caFree;
                DataModule1 -> Prikaz_KursFDQuery -> Close ();
                // академические отпуска
                DataModule1 -> HolidayFDQuery -> Close ();
                // приказы на отчисление / восстановление
                DataModule1 -> PeopleFDQuery -> Close ();
                // приказы о поощрениях / взысканиях
                DataModule1 -> EncourageFDQuery -> Close ();
                // разные приказы
                DataModule1 -> Public_PrikazFDQuery -> Close ();

            } // 2 -yes
            else if (fl == mrNo) {
                DataModule1 -> PeopleFDQuery -> CancelUpdates ();
                /* if (Bookmark)
                 { //if закладка

                 DataModule1 -> PeopleFDQuery -> FreeBookmark (Bookmark);
                 }//end if закладка */
                delete pms;
                delete jp;
                Action = caFree;
                result_itog = false;
                DataModule1 -> Prikaz_KursFDQuery -> Close ();
                // академические отпуска
                DataModule1 -> HolidayFDQuery -> Close ();
                // приказы на отчисление / восстановление
                DataModule1 -> PeopleFDQuery -> Close ();
                // приказы о поощрениях / взысканиях
                DataModule1 -> EncourageFDQuery -> Close ();
                // разные приказы
                DataModule1 -> Public_PrikazFDQuery -> Close ();
            } // 2- no
            else {
                Action = caNone;
            } // 2- cancel
        } // !dsBrowse
        else {

            /* if (Bookmark)
             { //if закладка

             DataModule1 -> PeopleFDQuery -> FreeBookmark (Bookmark);
             }//end if закладка */

            delete pms;
            delete jp;
            Action = caFree; // dsBrowse
            result_itog = false;
            DataModule1 -> Prikaz_KursFDQuery -> Close ();
            // академические отпуска
            DataModule1 -> HolidayFDQuery -> Close ();
            // приказы на отчисление / восстановление
            DataModule1 -> PeopleFDQuery -> Close ();
            // приказы о поощрениях / взысканиях
            DataModule1 -> EncourageFDQuery -> Close ();
            // разные приказы
            DataModule1 -> Public_PrikazFDQuery -> Close ();
        }
    }
    else
        Action = caNone;
}

// ---------------------------------------------------------------------------
void __fastcall TStudForm::TabSheet1Enter (TObject * Sender) {
    TabSheet1 -> Visible = true;
    // open=1;
    RefreshControl ();
    Button1 -> Enabled = true;
    Button2 -> Enabled = true;
    Button1 -> Visible = true;
    Button2 -> Visible = true;

}

// ---------------------------------------------------------------------------
void __fastcall TStudForm::DBImage1Click (TObject * Sender) {
    /* if (OpenPictureDialog1 -> Execute ()) {
     try {
     DataModule1 -> PeopleFDQuery -> Edit ();
     }
     catch (...) {
     DataModule1 -> PeopleFDQuery -> Insert ();
     }

     Image1 -> Picture -> LoadFromFile (OpenPictureDialog1 -> FileName);

    /* if (OpenDialog1 -> Execute ())
     {
     Image1 -> Picture -> LoadFromFile (OpenDialog1 -> FileName);
     BitBtn1 -> Enabled=true;
     } */

    /* pms -> Clear ();
     jp -> Assign (Image1 -> Picture);
     jp -> SaveToStream (pms);
     pms -> Position = 0;
     DataModule1 -> PeopleFDQueryPHOTO -> LoadFromStream (pms);

     DataModule1 -> PeopleFDQuery -> Post ();
     } */
}

// ---------------------------------------------------------------------------
void __fastcall TStudForm::Button1Click (TObject * Sender) {
    // проверка на ввод ФИО
    if ( (DBEdit1 -> EditText == "") || (DBEdit2 -> EditText == "")) {
        ShowMessage ("Введите данные: Фамилия, Имя, Отчество");
        return;
    }
    // проверка на ввод даты и места рождения
    if (DBEdit5 -> EditText == "") {
        ShowMessage ("Введите данные: Дата рождения");
        return;
    }
    // проверка на ввод данных семейное положение, национальность, пол
    if ( (ComboBox1 -> ItemIndex == -1) || (DBComboBox1 -> ItemIndex == -1)) {
        ShowMessage (
            "Введите данные: Семейное положение, пол или национальность");
        return;
    }
    // проверка на ввод данных по образованию
    if ( (DBEdit11 -> EditText == "") || (DBEdit12 -> EditText == "") ||
        (DBEdit13 -> EditText == "") || (ComboBox2 -> ItemIndex == -1)) {
        ShowMessage ("Введите данные об образовании");
        return;
    }
    // проверка на ввод данных по адресам до и после поступления
    if ( (DBEdit18 -> EditText == "") || (DBEdit19 -> EditText == "")) {
        ShowMessage ("Введите данные по адресам до и после поступления");
        return;
    }
    // проверка на ввод данных по виду спорта
    if (DBLookupComboBox5 -> Text == "") {
        ShowMessage ("Проверьте ввод данных по виду спорта!");
        return;
    }

    // проверка на личный номер
    AnsiString personal = DBEdit24 -> EditText;
    if (personal != "") {
        if (personal.Length () != 14)
            ShowMessage (
            "Проверьте личный номер, он должен содержать 14 символов!");
        // if ( (DBComboBox1 -> Text == "М" && personal.SubString (1, 1) != "3") ||
        // (DBComboBox1 -> Text == "Ж" && personal.SubString (1, 1) != "4"))
        // ShowMessage (
        // "Проверьте личный номер, первая цифра не соответствует полу!");
        /* AnsiString dat = DBEdit5 -> Text; // 23.11.1981
         dat = dat.Delete (3, 1);
         dat = dat.Delete (5, 3);
         if (dat != personal.SubString (2, 6))
         ShowMessage (
         "Проверьте личный номер, дата рождения не соответствует данным в личном номере!"); */
    }
    // проверка на ввод данных по специальности и направлению специальности, условию обучения
    if ( (DBLookupComboBox3 -> Text == "") || (DBLookupComboBox4 -> Text == "") ||
        (DBLookupComboBox1 -> Text == "")) {
        ShowMessage (
            "Введите данные на закладке 'Прохождение обучения': специальность, направление специальности и условия обучения!");
        return;
    }
    // проверка на ввод данных номера группа, курса и вида обучения
    if ( (DBEdit26 -> EditText == "") || (DBEdit25 -> EditText == "") ||
        (ComboBox3 -> ItemIndex == -1)) {
        ShowMessage (
            "Введите данные на закладке 'Прохождение обучения': номер группы, курс или вид обучения");
        return;
    }
    // проверка на ввод нужного курса
    AnsiString grupp_nomer = DBEdit25 -> EditText.SubString (2, 1);
    if (grupp_nomer != AnsiString (DBEdit26 -> EditText)) {
        ShowMessage ("Номер группы не соответствует курсу!");
        return;
    }

    // проверка на то, что если KeyPressAd=0 (режим Редактирования) и PeopleFDQuery не в режиме редактирования
    if (!KeyPressAd && DataModule1 -> PeopleFDQuery -> State != dsEdit) {
        ShowMessage ("Вы ничего не изменяли, поэтому сохранение невозможно!");
        return;
    }
    // проверка на ввод данных виду обучения при зачислении и основании зачисления, регион
    if ( (DBLookupComboBox2 -> Text == "") || (ComboBox5 -> ItemIndex == -1)) {
        ShowMessage (
            "Введите данные на закладке 'Прохождение обучения': вид обучения при зачислении или основание зачисления");
        return;
    }
    // Проверка на ввод данных по Регион/Область или Город/Район
    // if ( (DBLookupComboBox6 -> Text == "") ||
    // (DBLookupComboBox6 -> KeyValue != 1 && DBLookupComboBox7 -> Text == "")) {
    // ShowMessage ("Введите данные: Регион/Область или Город/Район");
    // return;
    // }

    // Проверка на гражданство
    if (DBLookupComboBox2 -> Text == "") {
        ShowMessage (
            "Не заполнено поле Гражданство");
    }

    // Проверка на ввод данных на какой курс зачислен
    if (DBEdit7 -> EditText == "") {
        UnicodeString InStr = "1";
        if (InputQuery ("", "Не заполнено поле: На какой курс зачислен:", InStr))
        {
            DataModule1 -> PeopleFDQueryN_PRIKAZ_KURS -> Value = StrToInt (InStr);
        }
        else {
            ShowMessage ("Данные не были сохранены!");
            return;
        }
    }

    // Проверка на поле Условия обучения
    if (DBLookupComboBox1 -> KeyValue != 2 && DBLookupComboBox1 -> KeyValue != 6) {
        ShowMessage (
            "Данные по условию обучения на закладке 'Прохождение обучения' могут быть Договор или Бюджет!");
        return;
    }

    // ----------
    if (KeyPressAd) { // если режим добавления нового студента
        // DataModule1 -> PeopleQuerySTATUS_PEOPLE -> Value=1; раньше добавляли действующих - сейчас отчисленных

        DataModule1 -> PeopleFDQuerySTATUS_PEOPLE -> Value = 2;
        DataModule1 -> PeopleFDQueryN_FAC -> Value = nom_fac;
        DataModule1 -> PeopleFDQueryINC_GROUP -> Value = 18;
        String d_end;
        if (ComboBox5 -> ItemIndex) {
            d_end = "30.04." + IntToStr
                (uch_god + 6 - DataModule1 -> PeopleFDQueryKURS -> Value);
        }
        else
            d_end = "30.06." + IntToStr
                (uch_god + 5 - DataModule1 -> PeopleFDQueryKURS -> Value);
        DataModule1 -> PeopleFDQueryDATE_END -> Value =
            DateTimeToSQLTimeStamp (StrToDate (d_end));

    } // if   если режим добавления нового студента
    // Поиск существующего номера группы  -- временно убираем этот кусок
    /* Variant i_gr=search_increment_group (DBEdit25 -> EditText,ComboBox3 -> ItemIndex);
     if (!i_gr.IsNull ())
     DataModule1 -> PeopleQueryINC_GROUP -> Value=i_gr;
     else
     {
     if (Application -> MessageBox ("Такого номера группы нет. Создать группу с таким номером?", "Предупреждение", MB_YESNO) == mrYes)
     {
     DM2 -> Increment_GroupTable -> Insert ();
     DM2 -> Increment_GroupTableN_GROUP -> Value=DBEdit25 -> EditText;
     DM2 -> Increment_GroupTableVID_EDU -> Value=ComboBox3 -> ItemIndex;
     int year_cur;
     TDateTime ddd;
     TDateTime fff=ddd.CurrentDate ();
     int mon=AnsiString (fff).SubString (4,2).ToInt ();
     if (mon>8) year_cur=AnsiString (fff).SubString (7,4).ToInt ()+1;
     else year_cur=AnsiString (fff).SubString (7,4).ToInt ();
     DM2 -> Increment_GroupTableGOD -> Value=year_cur;

     DM2 -> Increment_GroupTable -> ApplyUpdates ();
     DM2 -> Increment_groupT -> CommitRetaining ();
     DM2 -> Increment_GroupTable -> Active=false;
     DM2 -> Increment_GroupTable -> Active=true;
     DM2 -> Increment_GroupTable -> Last ();
     DataModule1 -> PeopleQueryINC_GROUP -> Value=DM2 -> Increment_GroupTableINC_GROUP -> Value;
     }
     else
     {
     ShowMessage ("Введите другой номер группы");
     DBEdit25 -> EditText="";
     DBEdit25 -> SetFocus ();
     return;
     }
     } //else i_gr.IsNull */

    int nomer;
    nomer = DataModule1 -> PeopleFDQueryNOMER -> Value;
    try {
        DataModule1 -> PeopleFDQuery -> ApplyUpdates ();
        DataModule1 -> PeopleFDQuery -> CommitUpdates ();
        DataModule1 -> PeopleFDQuery -> Close ();
        if (DataModule1 -> QueueFDQuery -> Active == true) {
            DataModule1 -> People_photoFDQuery -> Active = false;
            DataModule1 -> People_photoFDQuery -> ParamByName ("nomer")
                -> Value = nomer;
            DataModule1 -> People_photoFDQuery -> Open ();
            DataModule1 -> People_photoFDQuery -> Edit ();
            DataModule1 -> People_photoFDQueryPHOTO -> Value =
                DataModule1 -> QueueFDQueryPHOTO -> Value;
            DataModule1 -> People_photoFDQueryDIGIT_SIGN -> Value =
                DataModule1 -> QueueFDQueryDIGIT_SIGN -> Value;
            DataModule1 -> People_photoFDQuery -> Post ();
            DataModule1 -> People_photoFDQuery -> ApplyUpdates ();
            DataModule1 -> People_photoFDQuery -> CommitUpdates ();
            DataModule1 -> People_photoFDQuery -> Close ();
            DataModule1 -> QueueFDQuery -> Close ();
        }

        if (KeyPressAd == 1) {
            DataModule1 -> Queue_UpFDQuery -> ParamByName ("id_ab")
                -> AsInteger = id_ab;
            DataModule1 -> Queue_UpFDQuery -> ExecSQL ();
        }

    }
    catch (...) {
        ShowMessage ("Введены не все исходные данные");
        return;
    }

    DataModule1 -> PeopleFDQuery -> SQL -> Clear ();

    TLocateOptions Flags;
    if (KeyPressAd == 1) { // if Добавление нового студента
        // DataModule1 -> Max_Nomer_peopleQuery -> ParamByName ("N_FAC") -> AsInteger=nom_fac;
        // DataModule1 -> Max_Nomer_peopleQuery -> Open ();
        // DataModule1 -> PeopleFDQuery -> Locate ("NOMER",DataModule1 -> Max_Nomer_peopleQueryMAX -> Value,Flags);

        // DataModule1 -> Max_Nomer_peopleQuery -> Close ();

        // --новый кусок
        CheckBox4 -> Checked = true; // включаем показ отчисленных
        // открытие PeopleFDQuery  по отчисленным сделается по  CheckBox4 -> Checked
        DataModule1 -> PeopleFDQuery -> Locate ("NOMER", nomer, Flags);

    } // end if Добавление нового студента

    else { // else сохранение студента
        // TLocateOptions Flags;
        DataModule1 -> PeopleFDQuery -> SQL -> Add ("SELECT NOMER, N_ZACHET, FAM, NAME, OTCH, STATUS_KURS, POL, NAZ, PAPA, MAMA, \
                    MARIAGE, N_CHILD, EDUCATION, ARMY, SCHOLARSHIP, HOSTEL, \
                    NAME_EDUC, WHEN_EDUC, WHERE_EDUC, MIDDLE_B, N_VID_SPORT, N_DELA, VID_EDU,  \
                    N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, EDU_WORK, D_PRIKAZ_KURS, \
                    N_FOUND, N_PRIKAZ_INCLUDE, D_PRIKAZ_INCLUDE, N_GROUP, STATUS_PEOPLE,   \
                    INC_GROUP, WORK_BEFORE, ADDRESS_BEFORE, ADDRESS, ADDRESS_LIFE, DATA_R, F_OLD, PHONE,  \
                    VID_EDU_INCLUDE, N_FOUND_INCLUDE, N_CENTRE, CITIZENSHIP, RASPREDELENIE, N_DOGOVOR,  \
                    CONFIRM_RASPRED, ADDRESS_POSLE, PHONE_POSLE, PASPORT, PERSONAL_NOMER, \
                    D_INCLUDE, MOODLE_PASSWORD, ADDRESS_PAPA, ADDRESS_MAMA, N_ROOM, DATE_END, NUMBER, HOUSE, FLAT, POSTCODE, ID_STREET, N_ADD_AGREE FROM PEOPLE WHERE (N_FAC="
            + AnsiString (nom_fac) + ")");
        if (CheckBox3 -> Checked) { // if включен выбор номера группы
            Variant search_inc_group =
                search_increment_group (Edit2 -> Text, ComboBox4 -> ItemIndex);
            DataModule1 -> PeopleFDQuery -> SQL -> Add
                (" AND (STATUS_PEOPLE=1) AND (INC_GROUP=" +
                VarToStr (search_inc_group) + ") ORDER BY FAM");
        } // end if включен выбор номера группы
        if (CheckBox4 -> Checked) { // if включены отчисленные
            DataModule1 -> PeopleFDQuery -> SQL -> Add
                (" AND (STATUS_PEOPLE=2) ORDER BY FAM, NAME, OTCH");
        } // end if включены отчисленные
        if (CheckBox5 -> Checked) { // if включены академисты
            DataModule1 -> PeopleFDQuery -> SQL -> Add
                (" AND (STATUS_PEOPLE=3) ORDER BY FAM, NAME, OTCH");
        } // end if включены академисты

        if (!CheckBox3 -> Checked && !CheckBox4 -> Checked && !CheckBox5 -> Checked)
            DataModule1 -> PeopleFDQuery -> SQL -> Add
                (" AND (STATUS_PEOPLE=1) ORDER BY FAM, NAME, OTCH");

        DataModule1 -> PeopleFDQuery -> Open (); // Выполнить команду SELECT
        DataModule1 -> PeopleFDQuery -> Locate ("NOMER", nomer, Flags);
    } // end else сохранение студента

    // при добавлении нового студента в табл. Спорт заносится осн.вид спорта без разряда
    if (KeyPressAd) {
        DataModule1 -> SportFDQuery -> Close ();
        // Закрытие Query для установки параметров
        DataModule1 -> SportFDQuery -> Params -> Items[0] -> AsInteger =
            DataModule1 -> PeopleFDQueryNOMER -> Value;
        DataModule1 -> SportFDQuery -> Open (); // Выполнение запроса
        DataModule1 -> SportFDQuery -> Insert ();
        DataModule1 -> SportFDQueryNOMER -> Value =
            DataModule1 -> PeopleFDQueryNOMER -> Value;
        DataModule1 -> SportFDQueryN_VID_SPORT -> Value =
            DataModule1 -> PeopleFDQueryN_VID_SPORT -> Value;
        DataModule1 -> SportFDQuerySPORT_CATEGORY -> Value = 12;
        DataModule1 -> SportFDQuery -> ApplyUpdates ();
        DataModule1 -> SportFDQuery -> CommitUpdates ();
        DataModule1 -> SportFDQuery -> Close ();
        result_itog = false;
        // ---если было добавление нового отчисленного, то надо спросить номер приказа об отчислении
        AnsiString fno = "Cтудент (ка) " + DataModule1 -> PeopleFDQueryFAM -> Value +
            " " + DataModule1 -> PeopleFDQueryNAME -> Value + " " +
            DataModule1 -> PeopleFDQueryOTCH -> Value +
            " сохранен (а) как отчисленный (ая). Добавить приказ об отчислении?";
        // !!!if (Application -> MessageBox (fno.c_str (), "", MB_YESNO) == mrYes)
        if (MessageDlg (fno.c_str (), mtConfirmation,
            TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
        { // if нужно добавить приказ об отчислении
            Bookmark = DataModule1 -> PeopleFDQuery -> GetBookmark ();
            Stud_Pr_RestoreForm = new TStud_Pr_RestoreForm (this);
            // Создание формы для введения номера приказа отчисления
            Stud_Pr_RestoreForm -> ShowModal (); // Показ формы
        } // end if нужно добавить приказ об отчислении
    }
    // ------------------------

    DBNavigator1 -> Enabled = true;
    TabSheet3 -> TabVisible = true;
    DBNavigator3 -> Enabled = true;
    BitBtn1 -> Enabled = true;
    KeyPressAd = 0;
    result_itog = true;
    RefreshControl ();
    // open=1;
    DBEdit25 -> ReadOnly = true;
    DBEdit26 -> ReadOnly = true;
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::Button2Click (TObject * Sender) {
    KeyPressAd = 0;
    DataModule1 -> PeopleFDQuery -> CancelUpdates ();
    RefreshControl ();
    DBNavigator1 -> Enabled = true;
    TabSheet3 -> TabVisible = true;
    DBNavigator3 -> Enabled = true;
    BitBtn1 -> Enabled = true;
    DBEdit25 -> ReadOnly = true;
    DBEdit26 -> ReadOnly = true;
    // open=1;
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::TabSheet1Show (TObject * Sender) {
    DBEdit1 -> SetFocus ();
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::TabSheet1Exit (TObject * Sender) {
    // open=0;
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::DBComboBox1Change (TObject * Sender) {
    int oldIndex = ComboBox1 -> ItemIndex;
    if (DBComboBox1 -> ItemIndex == 1) {
        ComboBox1 -> Items -> BeginUpdate ();
        ComboBox1 -> Items -> Clear ();
        ComboBox1 -> Items -> Add ("Не замужем");
        ComboBox1 -> Items -> Add ("Замужем");
        ComboBox1 -> Items -> Add ("Разведена");
        ComboBox1 -> Items -> Add ("Вдова");
        ComboBox1 -> Items -> EndUpdate ();
    }
    else if (DBComboBox1 -> ItemIndex == 0) {
        ComboBox1 -> Items -> BeginUpdate ();
        ComboBox1 -> Items -> Clear ();
        ComboBox1 -> Items -> Add ("Холост");
        ComboBox1 -> Items -> Add ("Женат");
        ComboBox1 -> Items -> Add ("Разведен");
        ComboBox1 -> Items -> Add ("Вдовец");
        ComboBox1 -> Items -> EndUpdate ();
    }

    ComboBox1 -> ItemIndex = oldIndex;
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::DBEdit5Enter (TObject * Sender) {

    CalendarForm = new TCalendarForm (this);
    CalendarForm -> Label2 -> Visible = true;
    CalendarForm -> ComboBox1 -> Visible = true;
    CalendarForm -> CCalendar1 -> Visible = true;

    CalendarForm -> Height = 222;
    CalendarForm -> BitBtn1 -> Top = 169;
    CalendarForm -> BitBtn1 -> Left = 7;
    CalendarForm -> BitBtn1 -> Width = 82;
    CalendarForm -> BitBtn2 -> Top = 169;
    CalendarForm -> BitBtn2 -> Left = 111;
    CalendarForm -> ShowModal ();
    try {
        DataModule1 -> PeopleFDQuery -> Edit ();
    }
    catch (...) {
        DataModule1 -> PeopleFDQuery -> Insert ();
    }
    if (calendar) {
        /* DataModule1 -> PeopleFDQuery -> FieldValues["YEAR_R"]=cal_year;
         //установка в БД выбранного месяца
         DataModule1 -> PeopleFDQuery -> FieldValues["MONTH_R"]=cal_month;
         //установка в БД выбранной даты
         DataModule1 -> PeopleFDQuery -> FieldValues["DATE_R"]=cal_day; */
        DataModule1 -> PeopleFDQuery -> FieldValues["DATA_R"] =
            cal_date.DateString ();
    }
}

// ---------------------------------------------------------------------------
void __fastcall TStudForm::DBEdit12Enter (TObject * Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> Label2 -> Visible = false;
    CalendarForm -> ComboBox1 -> Visible = false;
    CalendarForm -> CCalendar1 -> Visible = false;

    CalendarForm -> Height = 113;
    CalendarForm -> BitBtn1 -> Top = 8;
    CalendarForm -> BitBtn1 -> Left = 95;
    CalendarForm -> BitBtn1 -> Width = 82;
    CalendarForm -> BitBtn2 -> Top = 48;
    CalendarForm -> BitBtn2 -> Left = 95;

    CalendarForm -> ShowModal ();
    try {
        DataModule1 -> PeopleFDQuery -> Edit ();
    }
    catch (...) {
        DataModule1 -> PeopleFDQuery -> Insert ();
    }
    if (calendar)
        DataModule1 -> PeopleFDQuery -> FieldValues["WHEN_EDUC"] = cal_year;
    StudForm -> DBEdit13 -> SetFocus ();

}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::Edit1Change (TObject * Sender) {
    Set<TLocateOption, 0, 1>flags;
    flags << loCaseInsensitive << loPartialKey;
    DataModule1 -> PeopleFDQuery -> Locate ("FAM", Edit1 -> Text, flags);
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::TabSheet3Show (TObject * Sender) {
    Edit1 -> SetFocus ();
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::TabSheet2Show (TObject * Sender) {
    DBEdit22 -> SetFocus ();
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::BitBtn1Click (TObject * Sender) {
    status_people_query = 0;
    DataModule1 -> SportFDQuery -> Close ();
    DataModule1 -> SportFDQuery -> Params -> Items[0] -> AsInteger =
        DataModule1 -> PeopleFDQueryNOMER -> Value;
    DataModule1 -> SportFDQuery -> Open ();
    SportForm = new TSportForm (this);
    SportForm -> ShowModal ();
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::CheckBox3Click (TObject * Sender) {
    if (CheckBox3 -> Checked) {
        DataModule2 -> frxReport1 -> PrintOptions -> Duplex = dmVertical;
        if ( (Edit2 -> Text != "") && (ComboBox4 -> ItemIndex != -1)) {

            Variant search_inc_group =
                search_increment_group (Edit2 -> Text, ComboBox4 -> ItemIndex);
            if (!search_inc_group.IsNull ()) {
                DataModule1 -> PeopleFDQuery -> Close ();
                DataModule1 -> PeopleFDQuery -> SQL -> Clear ();
                DataModule1 -> PeopleFDQuery -> SQL -> Add ("SELECT NOMER, N_ZACHET, FAM, NAME, OTCH, STATUS_KURS, POL, NAZ, PAPA, MAMA, \
                    MARIAGE, N_CHILD, EDUCATION, ARMY, SCHOLARSHIP, HOSTEL, \
                    NAME_EDUC, WHEN_EDUC, WHERE_EDUC, MIDDLE_B, N_VID_SPORT, N_DELA, VID_EDU,  \
                    N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, EDU_WORK, D_PRIKAZ_KURS, \
                    N_FOUND, N_PRIKAZ_INCLUDE, D_PRIKAZ_INCLUDE, N_GROUP, STATUS_PEOPLE,   \
                    INC_GROUP, WORK_BEFORE, ADDRESS_BEFORE, ADDRESS, ADDRESS_LIFE, DATA_R, F_OLD, PHONE,  \
                    VID_EDU_INCLUDE, N_FOUND_INCLUDE, N_CENTRE, CITIZENSHIP, RASPREDELENIE, N_DOGOVOR,  \
                    CONFIRM_RASPRED, ADDRESS_POSLE, PHONE_POSLE, PASPORT, PERSONAL_NOMER, \
                    D_INCLUDE, MOODLE_PASSWORD, ADDRESS_PAPA, ADDRESS_MAMA, N_ROOM, DATE_END, NUMBER, HOUSE, FLAT, POSTCODE, ID_STREET, N_ADD_AGREE FROM PEOPLE WHERE (N_FAC="
                    + AnsiString (nom_fac) +
                    ") AND (STATUS_PEOPLE=1) AND (INC_GROUP=" +
                    VarToStr (search_inc_group) + ") ORDER BY FAM");
                DataModule1 -> PeopleFDQuery -> Open ();

                Label48 -> Visible = true;
                Label49 -> Caption = DataModule1 -> PeopleFDQuery -> RecordCount;
                Label49 -> Visible = true;
            }
            else {
                ShowMessage (
                    "Номера группы с таким видом обучения не существует");
                Edit2 -> SetFocus ();
                CheckBox3 -> Checked = false;
            }
        }
        else {
            ShowMessage ("Введите номер группы и вид обучения");
            Edit2 -> SetFocus ();
            CheckBox3 -> Checked = false;
        }

    }
    else {
        DataModule2 -> frxReport1 -> PrintOptions -> Duplex = dmSimplex;
        // DataModule1 -> PeopleFDQuery -> Filtered=false;
        Edit2 -> Text = "";
        ComboBox4 -> ItemIndex = -1;
        DataModule1 -> PeopleFDQuery -> Close ();
        DataModule1 -> PeopleFDQuery -> SQL -> Clear ();
        DataModule1 -> PeopleFDQuery -> SQL -> Add ("SELECT NOMER, N_ZACHET, FAM, NAME, OTCH, STATUS_KURS, POL, NAZ, PAPA, MAMA, \
                    MARIAGE, N_CHILD, EDUCATION, ARMY, SCHOLARSHIP, HOSTEL, \
                    NAME_EDUC, WHEN_EDUC, WHERE_EDUC, MIDDLE_B, N_VID_SPORT, N_DELA, VID_EDU,  \
                    N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, EDU_WORK, D_PRIKAZ_KURS, \
                    N_FOUND, N_PRIKAZ_INCLUDE, D_PRIKAZ_INCLUDE, N_GROUP, STATUS_PEOPLE,   \
                    INC_GROUP, WORK_BEFORE, ADDRESS_BEFORE, ADDRESS, ADDRESS_LIFE, DATA_R, F_OLD, PHONE,  \
                    VID_EDU_INCLUDE, N_FOUND_INCLUDE, N_CENTRE, CITIZENSHIP, RASPREDELENIE, N_DOGOVOR,  \
                    CONFIRM_RASPRED, ADDRESS_POSLE, PHONE_POSLE, PASPORT, PERSONAL_NOMER, \
                    D_INCLUDE, MOODLE_PASSWORD, ADDRESS_PAPA, ADDRESS_MAMA, N_ROOM, DATE_END, NUMBER, HOUSE, FLAT, POSTCODE, ID_STREET, N_ADD_AGREE FROM PEOPLE WHERE (N_FAC="
            + AnsiString (nom_fac) + ") AND (STATUS_PEOPLE=1) ORDER BY FAM");
        DataModule1 -> PeopleFDQuery -> Open ();

        Label48 -> Visible = false;
        Label49 -> Visible = false;
    }

}

// ---------------------------------------------------------------------------
void __fastcall TStudForm::FormActivate (TObject * Sender) {
    if (status_people_query && !KeyPressAd) {
        DataModule1 -> PeopleFDQuery -> Close ();

        if (nom_fac != 0) {
            AnsiString kr = AnsiString (nom_fac) + ") ORDER BY FAM";
            DataModule1 -> PeopleFDQuery -> SQL -> Clear ();

            DataModule1 -> PeopleFDQuery -> SQL -> Add ("SELECT NOMER, N_ZACHET, FAM, NAME, OTCH, STATUS_KURS, POL, NAZ, PAPA, MAMA, \
                    MARIAGE, N_CHILD, EDUCATION, ARMY, SCHOLARSHIP, HOSTEL, \
                    NAME_EDUC, WHEN_EDUC, WHERE_EDUC, MIDDLE_B, N_VID_SPORT, N_DELA, VID_EDU,  \
                    N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, EDU_WORK, D_PRIKAZ_KURS, \
                    N_FOUND, N_PRIKAZ_INCLUDE, D_PRIKAZ_INCLUDE, N_GROUP, STATUS_PEOPLE,   \
                    INC_GROUP, WORK_BEFORE, ADDRESS_BEFORE, ADDRESS, ADDRESS_LIFE, DATA_R, F_OLD, PHONE,  \
                    VID_EDU_INCLUDE, N_FOUND_INCLUDE, N_CENTRE, CITIZENSHIP, RASPREDELENIE, N_DOGOVOR,  \
                    CONFIRM_RASPRED, ADDRESS_POSLE, PHONE_POSLE, PASPORT, PERSONAL_NOMER, \
                    D_INCLUDE, MOODLE_PASSWORD, ADDRESS_PAPA, ADDRESS_MAMA, N_ROOM, DATE_END, NUMBER, HOUSE, FLAT, POSTCODE, ID_STREET, N_ADD_AGREE FROM PEOPLE WHERE (STATUS_PEOPLE=1) AND (N_FAC="
                + kr);
        }
        DataModule1 -> PeopleFDQuery -> Open ();
        // Выполнить команду SELECT

    }
    // TabSheet3 -> Show ();

}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::DBNavigator1Click (TObject * Sender,
    TNavigateBtn Button) {
    // KeyDelet=0;
    switch (Button) {
    case nbFirst:
        RefreshControl ();
        break;
    case nbPrior:
        RefreshControl ();
        break;
    case nbNext:
        RefreshControl ();
        break;
    case nbLast:
        RefreshControl ();
        break;
    case nbInsert:
        DataModule1 -> QueueFDQuery -> Open ();
        KeyPressAd = 1;
        QueueForm = new TQueueForm (this);
        QueueForm -> Show ();
        break;
    case nbDelete: // KeyDelet=1;
        break;
    case nbEdit:
        break;
    case nbCancel:
        break;
    case nbRefresh:
        break;
    }

}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::TabSheet3Enter (TObject * Sender) {
    Button1 -> Enabled = false;
    Button2 -> Enabled = false;
    Button1 -> Visible = false;
    Button2 -> Visible = false;
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::BitBtn2Click (TObject * Sender) {
    status_people_query = 0;
    PassForm = new TPassForm (this);
    PassForm -> Show ();
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::DBEdit23Enter (TObject * Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> ShowModal ();
    try {
        DataModule1 -> PeopleFDQuery -> Edit ();
    }
    catch (...) {
        DataModule1 -> PeopleFDQuery -> Insert ();
    }
    if (calendar)
        DataModule1 -> PeopleFDQuery -> FieldValues["D_INCLUDE"] =
            cal_date.DateString ();
    // StudForm -> DBLookupComboBox1 -> SetFocus ();
    StudForm -> DBEdit7 -> SetFocus ();
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::DBGrid1DblClick (TObject * Sender)
{ // При двойном щелчке на списке студентов
    PageControl1 -> ActivePage = TabSheet1; // переходит на личную карту
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::ComboBox2Change (TObject * Sender) {
    if (DataModule1 -> PeopleFDQuery -> State != dsInsert) {
        DataModule1 -> PeopleFDQuery -> Edit ();
        DataModule1 -> PeopleFDQueryEDUCATION -> Value = ComboBox2 -> ItemIndex + 1;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::CheckBox1Click (TObject * Sender) {
    if (DataModule1 -> PeopleFDQuery -> State != dsInsert) {
        DataModule1 -> PeopleFDQuery -> Edit ();
        DataModule1 -> PeopleFDQueryARMY -> Value = CheckBox1 -> Checked;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::ComboBox1Change (TObject * Sender) {
    if (DataModule1 -> PeopleFDQuery -> State != dsInsert) {
        DataModule1 -> PeopleFDQuery -> Edit ();
        DataModule1 -> PeopleFDQueryMARIAGE -> Value = ComboBox1 -> ItemIndex;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::CheckBox2Click (TObject * Sender) {
    if (DataModule1 -> PeopleFDQuery -> State != dsInsert) {
        DataModule1 -> PeopleFDQuery -> Edit ();
        DataModule1 -> PeopleFDQueryHOSTEL -> Value = CheckBox2 -> Checked;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::ComboBox3Change (TObject * Sender) {
    if (DataModule1 -> PeopleFDQuery -> State != dsInsert) {
        DataModule1 -> PeopleFDQuery -> Edit ();
        DataModule1 -> PeopleFDQueryVID_EDU -> Value = ComboBox3 -> ItemIndex;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::Edit2Change (TObject * Sender) {
    CheckBox3 -> Checked = false;
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::TabSheet2Enter (TObject * Sender) {
    Button1 -> Enabled = true;
    Button2 -> Enabled = true;
    Button1 -> Visible = true;
    Button2 -> Visible = true;
    RefreshControl ();
    Label46 -> Caption = DM2 -> FacultyFDTable -> Lookup ("N_FAC", nom_fac, "FAC1");
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::Button3Click (TObject * Sender) {
    Variant search_inc_group;
    // Формирование Query для печати...
    if (CheckBox3 -> Checked) { // если включен выбор студентов из одной группы
        if ( (Edit2 -> Text != "") && (ComboBox4 -> ItemIndex != -1))
        { // проверка на непустые значения номера группы и вида обучения
            Variant locvalues[] = {Edit2 -> Text, ComboBox4 -> ItemIndex};
            search_inc_group = DM2 -> Increment_GroupFDTable -> Lookup
                ("N_GROUP;VID_EDU", VarArrayOf (locvalues, 1), "INC_GROUP");
            if (!search_inc_group.IsNull ())
            { // проверка на правильный ввод группы
                // PHOTO Is Null
                DataModule2 -> Report_CardFDQuery -> Close ();
                DataModule2 -> Report_CardFDQuery -> SQL -> Clear ();
                DataModule2 -> Report_CardFDQuery -> SQL -> Add ("SELECT People.NOMER, People.FAM, People.NAME, People.OTCH, People.POL, People.PLACE_R, People.NAZ, People.PAPA, People.MAMA, People.MARIAGE, People.EDUCATION, People.ARMY, People.HOSTEL,\
                 People.WORK_PAPA, People.WORK_MAMA, People.NAME_EDUC, People.WHEN_EDUC, People.WHERE_EDUC, People.PHOTO, People.MIDDLE_B, People.N_DELA, People.VID_EDU, People.KURS, People.N_PRIKAZ_KURS, People.EDU_WORK, People.D_PRIKAZ_KURS,\
                 People.N_PRIKAZ_INCLUDE, People.D_PRIKAZ_INCLUDE, People.N_GROUP, People.STATUS_PEOPLE, People.WORK_BEFORE, People.ADDRESS_BEFORE, People.ADDRESS, People.DATA_R, People.F_OLD, People.PHONE, People.STATUS_KURS, People.N_ZACHET,\
                 Vid_sport.VID_SPORT, Faculty.FAC1, People.INC_GROUP, Speciality.SPEC, Specializ.SPECIAL, People.N_SPEC, Specializ.SPECIAL_DIRECTION,  Foundation.VID_FOUND, People.VID_EDU_INCLUDE, People.N_FOUND_INCLUDE FROM PEOPLE People LEFT OUTER JOIN VID_SPORT Vid_sport ON  (People.N_VID_SPORT = Vid_sport.N_VID_SPORT)\
                 LEFT OUTER JOIN FACULTY Faculty ON  (People.N_FAC = Faculty.N_FAC) LEFT OUTER JOIN SPECIALITY Speciality ON  (People.N_SPEC = Speciality.N_SPEC) LEFT OUTER JOIN SPECIALIZ Specializ ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ)\
                 LEFT OUTER JOIN FOUNDATION Foundation ON  (People.N_FOUND = Foundation.N_FOUND) WHERE \
                 (People.N_FAC=" + AnsiString (nom_fac) +
                    ") AND (People.STATUS_PEOPLE=1) AND (People.INC_GROUP=" +
                    VarToStr (search_inc_group) + ") ORDER BY People.FAM");
                DataModule2 -> Report_CardFDQuery -> Open ();

            } // end if проверка на правильный ввод группы
        } // end if проверка на непустые значения номера группы и вида обучения
    } // end if если включен выбор студентов из одной группы
    else { // если выбран только один студент
        Edit2 -> Text = "";
        ComboBox4 -> ItemIndex = -1;
        DataModule2 -> Report_CardFDQuery -> Close ();
        if ( (!CheckBox4 -> Checked) && (!CheckBox5 -> Checked))
            // отключен выбор отчисленных и академистов
        { // PHOTO is NULL
            DataModule2 -> Report_CardFDQuery -> SQL -> Clear ();
            DataModule2 -> Report_CardFDQuery -> SQL -> Add ("SELECT People.NOMER, People.FAM, People.NAME, People.OTCH, People.POL, People.PLACE_R, People.NAZ, People.PAPA, People.MAMA, People.MARIAGE, People.EDUCATION, People.ARMY, People.HOSTEL, People.WORK_PAPA,\
      People.WORK_MAMA, People.NAME_EDUC, People.WHEN_EDUC, People.WHERE_EDUC, People.PHOTO, People.MIDDLE_B, People.N_DELA, People.VID_EDU, People.KURS, People.N_PRIKAZ_KURS, People.EDU_WORK, People.D_PRIKAZ_KURS, People.N_PRIKAZ_INCLUDE, People.D_PRIKAZ_INCLUDE,\
      People.N_GROUP, People.STATUS_PEOPLE, People.WORK_BEFORE, People.ADDRESS_BEFORE, People.ADDRESS, People.DATA_R, People.F_OLD, People.PHONE, People.STATUS_KURS, People.N_ZACHET, Vid_sport.VID_SPORT, Faculty.FAC1, People.INC_GROUP, Speciality.SPEC, Specializ.SPECIAL, People.N_SPEC, Specializ.SPECIAL_DIRECTION, Foundation.VID_FOUND, People.VID_EDU_INCLUDE, People.N_FOUND_INCLUDE \
      FROM PEOPLE People  LEFT OUTER JOIN VID_SPORT Vid_sport ON  (People.N_VID_SPORT = Vid_sport.N_VID_SPORT) LEFT OUTER JOIN FACULTY Faculty  ON  (People.N_FAC = Faculty.N_FAC) LEFT OUTER JOIN SPECIALITY Speciality ON  (People.N_SPEC = Speciality.N_SPEC)\
      LEFT OUTER JOIN SPECIALIZ Specializ ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) LEFT OUTER JOIN FOUNDATION Foundation  ON  (People.N_FOUND = Foundation.N_FOUND) WHERE  People.STATUS_PEOPLE = 1  AND PEOPLE.NOMER=:NOMER ORDER BY People.FAM"
                );
            DataModule2 -> Report_CardFDQuery -> ParamByName ("NOMER") -> Value =
                DataModule1 -> PeopleFDQueryNOMER -> Value;
            DataModule2 -> Report_CardFDQuery -> Open ();
        } // end if выбран только один студент и он не отчислен и не в академ. отпуске
        else { // если это не действующий студент
            if (CheckBox4 -> Checked) { // отчисленные студенты
                DataModule2 -> Report_CardFDQuery -> SQL -> Clear ();
                // ---убрали кусок если надо показать в MyList всех отчисленных
                /* DataModule2 -> Report_CardFDQuery -> SQL -> Add ("SELECT People.NOMER, People.FAM, People.NAME, People.OTCH, People.POL, People.PLACE_R, People.NAZ, People.PAPA, People.MAMA, People.MARIAGE, People.EDUCATION, People.ARMY, People.HOSTEL, People.WORK_PAPA,\
                 People.WORK_MAMA, People.NAME_EDUC, People.WHEN_EDUC, People.WHERE_EDUC, People.PHOTO, People.MIDDLE_B, People.N_DELA, People.VID_EDU, People.KURS, People.N_PRIKAZ_KURS, People.EDU_WORK, People.D_PRIKAZ_KURS, People.N_PRIKAZ_INCLUDE, People.D_PRIKAZ_INCLUDE,\
                 People.N_GROUP, People.STATUS_PEOPLE, People.WORK_BEFORE, People.ADDRESS_BEFORE, People.ADDRESS, People.DATA_R, People.F_OLD, People.PHONE, People.STATUS_KURS, People.N_ZACHET, Vid_sport.VID_SPORT, Faculty.FAC1, People.INC_GROUP, Speciality.SPEC, Specializ.SPECIAL, Foundation.VID_FOUND, People.VID_EDU_INCLUDE, People.N_FOUND_INCLUDE\
                 FROM PEOPLE People  LEFT OUTER JOIN VID_SPORT Vid_sport ON  (People.N_VID_SPORT = Vid_sport.N_VID_SPORT) LEFT OUTER JOIN FACULTY Faculty  ON  (People.N_FAC = Faculty.N_FAC) LEFT OUTER JOIN SPECIALITY Speciality ON  (People.N_SPEC = Speciality.N_SPEC)\
                 LEFT OUTER JOIN SPECIALIZ Specializ ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) LEFT OUTER JOIN FOUNDATION Foundation  ON  (People.N_FOUND = Foundation.N_FOUND) \
                 WHERE  (N_FAC="+AnsiString (nom_fac)+") AND (People.STATUS_PEOPLE = 2) ORDER BY People.FAM"); */

                DataModule2 -> Report_CardFDQuery -> SQL -> Add ("SELECT People.NOMER, People.FAM, People.NAME, People.OTCH, People.POL, People.PLACE_R, People.NAZ, People.PAPA, People.MAMA, People.MARIAGE, People.EDUCATION, People.ARMY, People.HOSTEL, People.WORK_PAPA,\
           People.WORK_MAMA, People.NAME_EDUC, People.WHEN_EDUC, People.WHERE_EDUC, People.PHOTO, People.MIDDLE_B, People.N_DELA, People.VID_EDU, People.KURS, People.N_PRIKAZ_KURS, People.EDU_WORK, People.D_PRIKAZ_KURS, People.N_PRIKAZ_INCLUDE, People.D_PRIKAZ_INCLUDE,\
           People.N_GROUP, People.STATUS_PEOPLE, People.WORK_BEFORE, People.ADDRESS_BEFORE, People.ADDRESS, People.DATA_R, People.F_OLD, People.PHONE, People.STATUS_KURS, People.N_ZACHET, Vid_sport.VID_SPORT, Faculty.FAC1, People.INC_GROUP, Speciality.SPEC, Specializ.SPECIAL, People.N_SPEC, Specializ.SPECIAL_DIRECTION,  Foundation.VID_FOUND, People.VID_EDU_INCLUDE, People.N_FOUND_INCLUDE\
           FROM PEOPLE People  LEFT OUTER JOIN VID_SPORT Vid_sport ON  (People.N_VID_SPORT = Vid_sport.N_VID_SPORT) LEFT OUTER JOIN FACULTY Faculty  ON  (People.N_FAC = Faculty.N_FAC) LEFT OUTER JOIN SPECIALITY Speciality ON  (People.N_SPEC = Speciality.N_SPEC)\
           LEFT OUTER JOIN SPECIALIZ Specializ ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) LEFT OUTER JOIN FOUNDATION Foundation  ON  (People.N_FOUND = Foundation.N_FOUND) WHERE  People.STATUS_PEOPLE = 2  AND PEOPLE.NOMER=:NOMER ORDER BY People.FAM"
                    );
                DataModule2 -> Report_CardFDQuery -> ParamByName ("NOMER") -> Value =
                    DataModule1 -> PeopleFDQueryNOMER -> Value;

                DataModule2 -> Report_CardFDQuery -> Open ();
            } // end if  отчисленные студенты
            if (CheckBox5 -> Checked)
            { // студенты, находящиеся в академическом отпуске

                DataModule2 -> Report_CardFDQuery -> SQL -> Clear ();
                DataModule2 -> Report_CardFDQuery -> SQL -> Add ("SELECT People.NOMER, People.FAM, People.NAME, People.OTCH, People.POL, People.PLACE_R, People.NAZ, People.PAPA, People.MAMA, People.MARIAGE, People.EDUCATION, People.ARMY, People.HOSTEL, People.WORK_PAPA,\
           People.WORK_MAMA, People.NAME_EDUC, People.WHEN_EDUC, People.WHERE_EDUC, People.PHOTO, People.MIDDLE_B, People.N_DELA, People.VID_EDU, People.KURS, People.N_PRIKAZ_KURS, People.EDU_WORK, People.D_PRIKAZ_KURS, People.N_PRIKAZ_INCLUDE, People.D_PRIKAZ_INCLUDE,\
           People.N_GROUP, People.STATUS_PEOPLE, People.WORK_BEFORE, People.ADDRESS_BEFORE, People.ADDRESS, People.DATA_R, People.F_OLD, People.PHONE, People.STATUS_KURS, People.N_ZACHET, Vid_sport.VID_SPORT, Faculty.FAC1, People.INC_GROUP, Speciality.SPEC, Specializ.SPECIAL, People.N_SPEC, Specializ.SPECIAL_DIRECTION,  Foundation.VID_FOUND, People.VID_EDU_INCLUDE, People.N_FOUND_INCLUDE\
           FROM PEOPLE People  LEFT OUTER JOIN VID_SPORT Vid_sport ON  (People.N_VID_SPORT = Vid_sport.N_VID_SPORT) LEFT OUTER JOIN FACULTY Faculty  ON  (People.N_FAC = Faculty.N_FAC) LEFT OUTER JOIN SPECIALITY Speciality ON  (People.N_SPEC = Speciality.N_SPEC)\
           LEFT OUTER JOIN SPECIALIZ Specializ ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) LEFT OUTER JOIN FOUNDATION Foundation  ON  (People.N_FOUND = Foundation.N_FOUND) \
           WHERE  (People.N_FAC=" + AnsiString (nom_fac) +
                    ") AND (People.STATUS_PEOPLE = 3) ORDER BY People.FAM");
                DataModule2 -> Report_CardFDQuery -> Open ();

            } // end if студенты, находящиеся в академическом отпуске
        } // end else это не действующий студент
    } // end else если выбран только один студент (только для действующего студента)
    // Формирование входного массива
    AnsiString *mas_stud[2]; // массив номеров и фамилий студентов
    // TObject *mas_stud[2];
    for (int i = 0; i < 2; i++) { // for1
        mas_stud[i] =
            new AnsiString[DataModule2 -> Report_CardFDQuery -> RecordCount];
    }

    // Мой компонент
    DataModule2 -> Report_CardFDQuery -> First ();
    /* MyList1 -> FormCaption = "Печать личной карточки";
     MyList1 -> SourceList -> Clear ();
     MyList1 -> FOutList -> Clear (); */ int i = 0;

    // MyList1 -> String=DataModule2 -> Report_CardQueryFAM -> Value     +" "+DataModule2 -> Report_CardQueryNAME -> Value+" "+DataModule2 -> Report_CardQueryOTCH -> Value;
    /* while (i <= DataModule2 -> Report_CardFDQuery -> RecordCount - 1) {
     mas_stud[0][i] = DataModule2 -> Report_CardQueryFAM -> Value + " " +
     DataModule2 -> Report_CardQueryNAME -> Value + " " +
     DataModule2 -> Report_CardQueryOTCH -> Value;
     MyList1 -> SourceList -> Add (mas_stud[0][i]);
     mas_stud[1][i] = AnsiString (DataModule2 -> Report_CardQueryNOMER -> Value);
     DataModule2 -> Report_CardFDQuery -> Next ();
     i++;
     } */

    DualListDlg = new TDualListDlg (this);
    DualListDlg -> Caption = "Выбор студентов для печати";
    DualListDlg -> SrcList -> Items -> Clear ();
    DualListDlg -> DstList -> Items -> Clear ();
    // int num_list = DM -> QLetterSourceKolCOUNT -> Value;
    for (int i = 0; i < DataModule2 -> Report_CardFDQuery -> RecordCount; i++) {
        mas_stud[0][i] = DataModule2 -> Report_CardFDQueryFAM -> Value + " " +
            DataModule2 -> Report_CardFDQueryNAME -> Value + " " +
            DataModule2 -> Report_CardFDQueryOTCH -> Value;
        mas_stud[1][i] =
            AnsiString (DataModule2 -> Report_CardFDQueryNOMER -> Value);
        DualListDlg -> SrcList -> Items -> AddObject
            (DataModule2 -> Report_CardFDQueryFAM -> Value + " " +
            DataModule2 -> Report_CardFDQueryNAME -> Value + " " +
            DataModule2 -> Report_CardFDQueryOTCH -> Value,
            (TObject*) (DataModule2 -> Report_CardFDQueryNOMER -> Value));
        DataModule2 -> Report_CardFDQuery -> Next ();
    }

    /* SrcLabel -> Caption = "Список поступивших (" + IntToStr (SrcList -> Items -> Count)
     + " чел.)";
     DstLabel -> Caption = "Список для печати (" + IntToStr (DstList -> Items -> Count)
     + " чел.)"; */

    DualListDlg -> ShowModal ();

    // Мой компонент
    if (DataModule2 -> printdlg == true) {
        if (DualListDlg -> DstList -> Items -> Count != 0) {
            // Отчет
            if (0 == DualListDlg -> SrcList -> Items -> Count) {
                DataModule2 -> Report_CardFDQuery -> First ();
                // Print_First ();
                for (int i = 0;
                i < DataModule2 -> Report_CardFDQuery -> RecordCount; i++) {
                    DataModule2 -> Report_EncourageFDQuery -> Close ();
                    DataModule2 -> Report_EncourageFDQuery -> ParamByName ("NOMER")
                        -> Value = DataModule2 -> Report_CardFDQueryNOMER -> Value;
                    DataModule2 -> Report_Prikaz_KursFDQuery -> Open ();
                    DataModule2 -> Report_SportFDQuery -> Open ();
                    DataModule2 -> Report_EncourageFDQuery -> Open ();
                    DataModule2 -> Report_DiplomaFDQuery -> Open ();
                }
                // DataModule2 -> frxReport1 -> PrepareReport ();
                // DataModule2 -> frxReport1 -> ShowPreparedReport ();
                if (! (TBlobField*)DataModule2 -> Report_CardFDQueryPHOTO -> IsNull)
                {
                    delete pot;
                    delete jpga;
                }
                DataModule2 -> frxReport1 -> Clear ();

                Print_First ();
                Print_To ();
                DataModule2 -> frxReport1 -> PrepareReport ();
                DataModule2 -> frxReport1 -> ShowPreparedReport ();

            } // А если не всех студентов....
            else {
                AnsiString Str_Nomer = "";
                for (int i = 0;
                i <= DualListDlg -> DstList -> Items -> Count - 1; i++) {
                    Str_Nomer +=
                        String ( (int) (DualListDlg -> DstList -> Items -> Objects[i]
                        )) + ",";
                    // возвращаем номер студента
                } // 1-ый for

                Str_Nomer.SetLength (Str_Nomer.Length () - 1);
                // Формирование Query для выхода
                DataModule2 -> Report_CardFDQuery -> Close ();
                DataModule2 -> Report_CardFDQuery -> SQL -> Clear ();

                if ( (!CheckBox4 -> Checked) && (!CheckBox5 -> Checked))
                { // отключен выбор отчисленных и академистов
                    DataModule2 -> Report_CardFDQuery -> SQL -> Add ("SELECT People.NOMER, People.FAM, People.NAME, People.OTCH, People.POL, People.PLACE_R, People.NAZ, People.PAPA, People.MAMA, People.MARIAGE, People.EDUCATION, People.ARMY, People.HOSTEL,\
                 People.WORK_PAPA, People.WORK_MAMA, People.NAME_EDUC, People.WHEN_EDUC, People.WHERE_EDUC, People.PHOTO, People.MIDDLE_B, People.N_DELA, People.VID_EDU, People.KURS, People.N_PRIKAZ_KURS, People.EDU_WORK, People.D_PRIKAZ_KURS,\
                 People.N_PRIKAZ_INCLUDE, People.D_PRIKAZ_INCLUDE, People.N_GROUP, People.STATUS_PEOPLE, People.WORK_BEFORE, People.ADDRESS_BEFORE, People.ADDRESS, People.DATA_R, People.F_OLD, People.PHONE, People.STATUS_KURS, People.N_ZACHET,\
                 Vid_sport.VID_SPORT, Faculty.FAC1, People.INC_GROUP, Speciality.SPEC, Specializ.SPECIAL, People.N_SPEC, Specializ.SPECIAL_DIRECTION, Foundation.VID_FOUND, People.VID_EDU_INCLUDE, People.N_FOUND_INCLUDE FROM PEOPLE People LEFT OUTER JOIN VID_SPORT Vid_sport ON  (People.N_VID_SPORT = Vid_sport.N_VID_SPORT)\
                 LEFT OUTER JOIN FACULTY Faculty ON  (People.N_FAC = Faculty.N_FAC) LEFT OUTER JOIN SPECIALITY Speciality ON  (People.N_SPEC = Speciality.N_SPEC) LEFT OUTER JOIN SPECIALIZ Specializ ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ)\
                 LEFT OUTER JOIN FOUNDATION Foundation ON  (People.N_FOUND = Foundation.N_FOUND) WHERE \
                 (People.N_FAC=" + AnsiString (nom_fac) +
                        ") AND (People.STATUS_PEOPLE=1) AND (People.INC_GROUP=" +
                        VarToStr (search_inc_group) + ") and (People.NOMER IN (" +
                        Str_Nomer + "))   ORDER BY People.FAM");
                } // end if отключен выбор отчисленных и академистов
                else { // если выбраны или отлисленные или академисты
                    DataModule2 -> Report_CardFDQuery -> SQL -> Add ("SELECT People.NOMER, People.FAM, People.NAME, People.OTCH, People.POL, People.PLACE_R, People.NAZ, People.PAPA, People.MAMA, People.MARIAGE, People.EDUCATION, People.ARMY, People.HOSTEL,\
                 People.WORK_PAPA, People.WORK_MAMA, People.NAME_EDUC, People.WHEN_EDUC, People.WHERE_EDUC, People.PHOTO, People.MIDDLE_B, People.N_DELA, People.VID_EDU, People.KURS, People.N_PRIKAZ_KURS, People.EDU_WORK, People.D_PRIKAZ_KURS,\
                 People.N_PRIKAZ_INCLUDE, People.D_PRIKAZ_INCLUDE, People.N_GROUP, People.STATUS_PEOPLE, People.WORK_BEFORE, People.ADDRESS_BEFORE, People.ADDRESS, People.DATA_R, People.F_OLD, People.PHONE, People.STATUS_KURS, People.N_ZACHET,\
                 Vid_sport.VID_SPORT, Faculty.FAC1, People.INC_GROUP, Speciality.SPEC, Specializ.SPECIAL, People.N_SPEC, Specializ.SPECIAL_DIRECTION, Foundation.VID_FOUND, People.VID_EDU_INCLUDE, People.N_FOUND_INCLUDE FROM PEOPLE People LEFT OUTER JOIN VID_SPORT Vid_sport ON  (People.N_VID_SPORT = Vid_sport.N_VID_SPORT)\
                 LEFT OUTER JOIN FACULTY Faculty ON  (People.N_FAC = Faculty.N_FAC) LEFT OUTER JOIN SPECIALITY Speciality ON  (People.N_SPEC = Speciality.N_SPEC) LEFT OUTER JOIN SPECIALIZ Specializ ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ)\
                 LEFT OUTER JOIN FOUNDATION Foundation ON  (People.N_FOUND = Foundation.N_FOUND) WHERE \
                 (People.N_FAC=" + AnsiString (nom_fac) +
                        ") AND (People.NOMER IN (" + Str_Nomer +
                        "))   ORDER BY People.FAM");

                } // end else eсли выбраны или отлисленные или академисты
                DataModule2 -> Report_CardFDQuery -> Open ();

                // Печать отчета
                DataModule2 -> Report_CardFDQuery -> First ();
                DataModule2 -> Report_EncourageFDQuery -> Close ();
                DataModule2 -> Report_EncourageFDQuery -> ParamByName ("NOMER")
                    -> Value = DataModule2 -> Report_CardFDQueryNOMER -> Value;
                DataModule2 -> Report_Prikaz_KursFDQuery -> Open ();
                DataModule2 -> Report_SportFDQuery -> Open ();
                DataModule2 -> Report_EncourageFDQuery -> Open ();
                DataModule2 -> Report_DiplomaFDQuery -> Open ();
                // Print_First ();
                if (! (TBlobField*)DataModule2 -> Report_CardFDQueryPHOTO -> IsNull)
                {
                    delete pot;
                    delete jpga;
                }
                DataModule2 -> frxReport1 -> Clear ();

                Print_First ();
                Print_To ();
                DataModule2 -> frxReport1 -> PrepareReport ();
                DataModule2 -> frxReport1 -> ShowPreparedReport ();

            } // else Если не всех

        } // if (MyList1 -> FOutList -> Count!=0)
        else {
            ShowMessage ("Вы не выбрали для печати ни одного студента!!!");
        }
    } // if execute

    delete DualListDlg;
    // удаление массива студентов
    for (int i = 0; i < 2; i++)
        delete[]mas_stud[i];
    DataModule2 -> Report_CardFDQuery -> Close ();
    DataModule2 -> Report_Prikaz_KursFDQuery -> Close ();
    DataModule2 -> Report_SportFDQuery -> Close ();
    DataModule2 -> Report_EncourageFDQuery -> Close ();
    DataModule2 -> Report_DiplomaFDQuery -> Close ();

}

// ---------------------------------------------------------------------------
void __fastcall TStudForm::DBEdit1KeyDown (TObject * Sender, WORD & Key,
    TShiftState Shift) {
    if (Key == 32) {
        DBEdit2 -> SetFocus ();
    }
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::DBEdit2KeyDown (TObject * Sender, WORD & Key,
    TShiftState Shift) {
    if (Key == 32) {
        DBEdit3 -> SetFocus ();
    }
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::DBNavigator3Click (TObject * Sender,
    TNavigateBtn Button) {
    RefreshControl ();
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::Image1Click (TObject * Sender) {
    if (OpenPictureDialog1 -> Execute ()) {
        try {
            DataModule1 -> People_photoFDQuery -> Edit ();
        }
        catch (...) {
            DataModule1 -> People_photoFDQuery -> Insert ();
        }

        Image1 -> Picture -> LoadFromFile (OpenPictureDialog1 -> FileName);

        /* if (OpenDialog1 -> Execute ())
         {
         Image1 -> Picture -> LoadFromFile (OpenDialog1 -> FileName);
         BitBtn1 -> Enabled=true;
         } */

        pms -> Clear ();
        jp -> Assign (Image1 -> Picture);
        jp -> SaveToStream (pms);
        pms -> Position = 0;
        DataModule1 -> People_photoFDQueryPHOTO -> LoadFromStream (pms);

        // DataModule1 -> PeopleFDQuery -> Post ();
    }
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::FormCreate (TObject * Sender) {
    result_itog = true;
    pms = new TMemoryStream ();
    jp = new Jpeg::TJPEGImage ();
    DataModule1 -> Region_CentreFDQuery -> Close ();
    DataModule1 -> Region_CentreFDQuery -> Open ();

}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::CheckBox4Click (TObject * Sender)
{ // Выбор отчисленных студентов
    if (CheckBox4 -> Checked) {
        CheckBox5 -> Enabled = false; // недоступен выбор студентов академистов
        GroupBox1 -> Visible = false;
        // недоступен выбор по группе и виду обучения
        // --- очищение элементов GroupBox1
        Edit2 -> Text = "";
        ComboBox4 -> Text = "";
        CheckBox3 -> State = cbUnchecked;
        // ---
        Label48 -> Visible = false; // текст для заголовка кол-ва студентов
        Label49 -> Visible = false; // количество студентов в группе
        Label49 -> Caption = "";
        // -------
        // [nbFirst,nbPrior,nbNext,nbLast]  в навигаторе без кнопки Insert
        btn.Clear ();
        btn << nbFirst << nbPrior << nbNext << nbLast;
        DBNavigator1 -> VisibleButtons = btn;
        // ------
        DataModule1 -> PeopleFDQuery -> Close ();
        DataModule1 -> PeopleFDQuery -> SQL -> Clear ();
        DataModule1 -> PeopleFDQuery -> SQL -> Add ("SELECT NOMER, N_ZACHET, FAM, NAME, OTCH, STATUS_KURS, POL, NAZ, PAPA, MAMA, \
                    MARIAGE, N_CHILD, EDUCATION, ARMY, SCHOLARSHIP, HOSTEL, \
                    NAME_EDUC, WHEN_EDUC, WHERE_EDUC, MIDDLE_B, N_VID_SPORT, N_DELA, VID_EDU,  \
                    N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, EDU_WORK, D_PRIKAZ_KURS, \
                    N_FOUND, N_PRIKAZ_INCLUDE, D_PRIKAZ_INCLUDE, N_GROUP, STATUS_PEOPLE,   \
                    INC_GROUP, WORK_BEFORE, ADDRESS_BEFORE, ADDRESS, ADDRESS_LIFE, DATA_R, F_OLD, PHONE,  \
                    VID_EDU_INCLUDE, N_FOUND_INCLUDE, N_CENTRE, CITIZENSHIP, RASPREDELENIE, N_DOGOVOR,  \
                    CONFIRM_RASPRED, ADDRESS_POSLE, PHONE_POSLE, PASPORT, PERSONAL_NOMER, \
                    D_INCLUDE, MOODLE_PASSWORD, ADDRESS_PAPA, ADDRESS_MAMA, N_ROOM, DATE_END, NUMBER, HOUSE, FLAT, POSTCODE, ID_STREET, N_ADD_AGREE FROM PEOPLE WHERE (N_FAC="
            + AnsiString (nom_fac) +
            ") AND (STATUS_PEOPLE=2 OR STATUS_PEOPLE=7) ORDER BY FAM, NAME, OTCH");
        DataModule1 -> PeopleFDQuery -> Open ();
        // STATUS_PEOPLE=2 означает отчисленные студенты

    }
    else {
        CheckBox5 -> Enabled = true; // доступен выбор студентов академистов
        GroupBox1 -> Visible = true; // доступен выбор по группе и виду обучения
        // Label48 -> Visible=true; //текст для заголовка кол-ва студентов
        // Label49 -> Visible=true; //количество студентов в группе
        // ------
        // [nbFirst,nbPrior,nbNext,nbLast,nbInsert]
        btn.Clear ();
        btn << nbFirst << nbPrior << nbNext << nbLast << nbInsert;
        DBNavigator1 -> VisibleButtons = btn;
        // -------
        DataModule1 -> PeopleFDQuery -> Close ();
        DataModule1 -> PeopleFDQuery -> SQL -> Clear ();
        DataModule1 -> PeopleFDQuery -> SQL -> Add ("SELECT NOMER, N_ZACHET, FAM, NAME, OTCH, STATUS_KURS, POL, NAZ, PAPA, MAMA, \
                    MARIAGE, N_CHILD, EDUCATION, ARMY, SCHOLARSHIP, HOSTEL, \
                    NAME_EDUC, WHEN_EDUC, WHERE_EDUC, MIDDLE_B, N_VID_SPORT, N_DELA, VID_EDU,  \
                    N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, EDU_WORK, D_PRIKAZ_KURS, \
                    N_FOUND, N_PRIKAZ_INCLUDE, D_PRIKAZ_INCLUDE, N_GROUP, STATUS_PEOPLE,   \
                    INC_GROUP, WORK_BEFORE, ADDRESS_BEFORE, ADDRESS, ADDRESS_LIFE, DATA_R, F_OLD, PHONE,  \
                    VID_EDU_INCLUDE, N_FOUND_INCLUDE, N_CENTRE, CITIZENSHIP, RASPREDELENIE, N_DOGOVOR,  \
                    CONFIRM_RASPRED, ADDRESS_POSLE, PHONE_POSLE, PASPORT, PERSONAL_NOMER, \
                    D_INCLUDE, MOODLE_PASSWORD, ADDRESS_PAPA, ADDRESS_MAMA, N_ROOM, DATE_END, NUMBER, HOUSE, FLAT, POSTCODE, ID_STREET, N_ADD_AGREE FROM PEOPLE WHERE (N_FAC="
            + AnsiString (nom_fac) +
            ") AND (STATUS_PEOPLE=1) ORDER BY FAM, NAME, OTCH");
        DataModule1 -> PeopleFDQuery -> Open ();
    }
}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::CheckBox5Click (TObject * Sender)
{ // Выбор студентов, находящихся в академическом отпуске
    if (CheckBox5 -> Checked) {
        CheckBox4 -> Enabled = false; // недоступен выбор студентов отчисленных

        GroupBox1 -> Visible = false;
        // недоступен выбор по группе и виду обучения
        // --- очищение элементов GroupBox1
        Edit2 -> Text = "";
        ComboBox4 -> Text = "";
        CheckBox3 -> State = cbUnchecked;
        // ---
        Label48 -> Visible = false; // текст для заголовка кол-ва студентов
        Label49 -> Visible = false; // количество студентов в группе
        Label49 -> Caption = "";
        // -------
        // [nbFirst,nbPrior,nbNext,nbLast]  в навигаторе без кнопки Insert
        btn.Clear ();
        btn << nbFirst << nbPrior << nbNext << nbLast;
        DBNavigator1 -> VisibleButtons = btn;
        // ------
        DataModule1 -> PeopleFDQuery -> Close ();
        DataModule1 -> PeopleFDQuery -> SQL -> Clear ();
        DataModule1 -> PeopleFDQuery -> SQL -> Add ("SELECT NOMER, N_ZACHET, FAM, NAME, OTCH, STATUS_KURS, POL, NAZ, PAPA, MAMA, \
                    MARIAGE, N_CHILD, EDUCATION, ARMY, SCHOLARSHIP, HOSTEL, \
                    NAME_EDUC, WHEN_EDUC, WHERE_EDUC, MIDDLE_B, N_VID_SPORT, N_DELA, VID_EDU,  \
                    N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, EDU_WORK, D_PRIKAZ_KURS, \
                    N_FOUND, N_PRIKAZ_INCLUDE, D_PRIKAZ_INCLUDE, N_GROUP, STATUS_PEOPLE,   \
                    INC_GROUP, WORK_BEFORE, ADDRESS_BEFORE, ADDRESS, ADDRESS_LIFE, DATA_R, F_OLD, PHONE,  \
                    VID_EDU_INCLUDE, N_FOUND_INCLUDE, N_CENTRE, CITIZENSHIP, RASPREDELENIE, N_DOGOVOR,  \
                    CONFIRM_RASPRED, ADDRESS_POSLE, PHONE_POSLE, PASPORT, PERSONAL_NOMER, \
                    D_INCLUDE, MOODLE_PASSWORD, ADDRESS_PAPA, ADDRESS_MAMA, N_ROOM, DATE_END, NUMBER, HOUSE, FLAT, POSTCODE, ID_STREET, N_ADD_AGREE FROM PEOPLE WHERE (N_FAC="
            + AnsiString (nom_fac) +
            ") AND (STATUS_PEOPLE=3) ORDER BY FAM, NAME, OTCH");
        DataModule1 -> PeopleFDQuery -> Open ();
        // STATUS_PEOPLE=3 означает студенты в академическом отпуске
    }
    else {
        CheckBox4 -> Enabled = true; // доступен выбор отчисленных студентов
        GroupBox1 -> Visible = true; // доступен выбор по группе и виду обучения
        // Label48 -> Visible=true; //текст для заголовка кол-ва студентов
        // Label49 -> Visible=true; //количество студентов в группе
        // ------
        // [nbFirst,nbPrior,nbNext,nbLast,nbInsert]
        btn.Clear ();
        btn << nbFirst << nbPrior << nbNext << nbLast << nbInsert;
        DBNavigator1 -> VisibleButtons = btn;
        // -------
        DataModule1 -> PeopleFDQuery -> Close ();
        DataModule1 -> PeopleFDQuery -> SQL -> Clear ();
        DataModule1 -> PeopleFDQuery -> SQL -> Add ("SELECT NOMER, N_ZACHET, FAM, NAME, OTCH, STATUS_KURS, POL, NAZ, PAPA, MAMA, \
                    MARIAGE, N_CHILD, EDUCATION, ARMY, SCHOLARSHIP, HOSTEL, \
                    NAME_EDUC, WHEN_EDUC, WHERE_EDUC, MIDDLE_B, N_VID_SPORT, N_DELA, VID_EDU,  \
                    N_FAC, KURS, N_SPEC, N_SPECIALIZ, N_PRIKAZ_KURS, EDU_WORK, D_PRIKAZ_KURS, \
                    N_FOUND, N_PRIKAZ_INCLUDE, D_PRIKAZ_INCLUDE, N_GROUP, STATUS_PEOPLE,   \
                    INC_GROUP, WORK_BEFORE, ADDRESS_BEFORE, ADDRESS, ADDRESS_LIFE, DATA_R, F_OLD, PHONE,  \
                    VID_EDU_INCLUDE, N_FOUND_INCLUDE, N_CENTRE, CITIZENSHIP, RASPREDELENIE, N_DOGOVOR,  \
                    CONFIRM_RASPRED, ADDRESS_POSLE, PHONE_POSLE, PASPORT, PERSONAL_NOMER, \
                    D_INCLUDE, MOODLE_PASSWORD, ADDRESS_PAPA, ADDRESS_MAMA, N_ROOM, DATE_END, NUMBER, HOUSE, FLAT, POSTCODE, ID_STREET, N_ADD_AGREE FROM PEOPLE WHERE (N_FAC="
            + AnsiString (nom_fac) +
            ") AND (STATUS_PEOPLE=1) ORDER BY FAM, NAME, OTCH");
        DataModule1 -> PeopleFDQuery -> Open ();

    }

}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::TabSheet4Enter (TObject * Sender) {
    RefreshControl ();
}

// ---------------------------------------------------------------------------
void __fastcall TStudForm::Button4Click (TObject * Sender) {
    // ----определение системы выдачи оценки (пятибальная или десятибальная)
    /* if (Application -> MessageBox ("Учебная карточка будет показана в десятибальной системе?", "Выбор системы оценок", MB_YESNO) == mrYes)
     {//if в десятибальной системе
     syst_ball=10;
     } //end if в десятибальной системе
     else
     {//else  в пятибальной системе
     syst_ball=5;
     }//end else  в пятибальной системе */

    // !!!int fl=Application -> MessageBox ("Учебная карточка будет показана: YES - в десятибальной системе; NO - в пятибальной системе; CANCEL - в реальной", "Выбор системы оценок", MB_YESNOCANCEL);
    int fl =
        MessageDlg (
        "Учебная карточка будет показана: YES - в десятибальной системе; NO - в пятибальной системе; CANCEL - в реальной",
        mtConfirmation, TMsgDlgButtons () << mbYes << mbNo << mbCancel, 0);
    switch (fl) { // switch
    case 2:
        syst_ball = 15; // cancel в реальной системе
        break;
    case 6:
        syst_ball = 10; // yes  в десятибальной системе
        break;
    case 7:
        syst_ball = 5; // no   в пятибальной системе
        break;
    } // switch

    // --------- начало процедуры
    Variant search_inc_group;
    // Формирование Query для печати учебной карточки...
    if (CheckBox3 -> Checked) { // если включен выбор студентов из одной группы
        if ( (Edit2 -> Text != "") && (ComboBox4 -> ItemIndex != -1))
        { // проверка на непустые значения номера группы и вида обучения
            Variant locvalues[] = {Edit2 -> Text, ComboBox4 -> ItemIndex};
            search_inc_group = DM2 -> Increment_GroupFDTable -> Lookup
                ("N_GROUP;VID_EDU", VarArrayOf (locvalues, 1), "INC_GROUP");
            if (!search_inc_group.IsNull ())
            { // проверка на правильный ввод группы
                DataModule2 -> Report_Ut_CardFDQuery -> Close ();
                DataModule2 -> Report_Ut_CardFDQuery -> SQL -> Clear ();
                DataModule2 -> Report_Ut_CardFDQuery -> SQL -> Add ("SELECT PEOPLE.NOMER, PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH, PEOPLE.POL, PEOPLE.NAZ, PEOPLE.PAPA, PEOPLE.MAMA, PEOPLE.MARIAGE, PEOPLE.N_CHILD, PEOPLE.EDUCATION, PEOPLE.ARMY, PEOPLE.SCHOLARSHIP, PEOPLE.HOSTEL, PEOPLE.NAME_EDUC, PEOPLE.WHEN_EDUC, PEOPLE.WHERE_EDUC, PEOPLE.PHOTO, PEOPLE.MIDDLE_B, PEOPLE.N_VID_SPORT, PEOPLE.N_DELA, PEOPLE.VID_EDU, PEOPLE.KURS, PEOPLE.N_SPEC, PEOPLE.N_PRIKAZ_KURS, PEOPLE.EDU_WORK, PEOPLE.D_PRIKAZ_KURS, PEOPLE.N_FOUND, PEOPLE.N_PRIKAZ_INCLUDE, PEOPLE.D_PRIKAZ_INCLUDE, PEOPLE.N_GROUP, PEOPLE.STATUS_PEOPLE, PEOPLE.INC_GROUP, PEOPLE.WORK_BEFORE, PEOPLE.ADDRESS_BEFORE, PEOPLE.ADDRESS, PEOPLE.DATA_R, PEOPLE.F_OLD, PEOPLE.PHONE, PEOPLE.STATUS_KURS, PEOPLE.N_ZACHET, Specializ.SPECIAL, Specializ.SPECIAL_DIRECTION, Faculty.FAC1, PEOPLE.VID_EDU_INCLUDE, PEOPLE.N_FOUND_INCLUDE, PEOPLE.N_SPECIALIZ \
                 FROM PEOPLE   INNER JOIN SPECIALIZ Specializ  ON  (PEOPLE.N_SPECIALIZ = Specializ.N_SPECIALIZ)   INNER JOIN FACULTY Faculty   ON  (PEOPLE.N_FAC = Faculty.N_FAC) WHERE\
                 (PEOPLE.N_FAC=" + AnsiString (nom_fac) +
                    ") AND (PEOPLE.STATUS_PEOPLE=1) AND (PEOPLE.INC_GROUP=" +
                    VarToStr (search_inc_group) + ") ORDER BY People.FAM");
                DataModule2 -> Report_Ut_CardFDQuery -> Open ();
            } // end if проверка на правильный ввод группы
        } // end if проверка на непустые значения номера группы и вида обучения
    } // end if если включен выбор студентов из одной группы
    else { // если выбран только один студент
        Edit2 -> Text = "";
        ComboBox4 -> ItemIndex = -1;
        DataModule2 -> Report_Ut_CardFDQuery -> Close ();
        if ( (!CheckBox4 -> Checked) && (!CheckBox5 -> Checked))
            // отключен выбор отчисленных и академистов
        {
            DataModule2 -> Report_Ut_CardFDQuery -> SQL -> Clear ();
            DataModule2 -> Report_Ut_CardFDQuery -> SQL -> Add ("SELECT PEOPLE.NOMER, PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH, PEOPLE.POL, PEOPLE.NAZ, PEOPLE.PAPA, PEOPLE.MAMA, PEOPLE.MARIAGE, PEOPLE.N_CHILD, PEOPLE.EDUCATION, PEOPLE.ARMY, PEOPLE.SCHOLARSHIP, PEOPLE.HOSTEL, PEOPLE.NAME_EDUC, PEOPLE.WHEN_EDUC, PEOPLE.WHERE_EDUC, PEOPLE.PHOTO, PEOPLE.MIDDLE_B, PEOPLE.N_VID_SPORT, PEOPLE.N_DELA, PEOPLE.VID_EDU, PEOPLE.KURS, PEOPLE.N_SPEC, PEOPLE.N_PRIKAZ_KURS, PEOPLE.EDU_WORK, PEOPLE.D_PRIKAZ_KURS, PEOPLE.N_FOUND, PEOPLE.N_PRIKAZ_INCLUDE, PEOPLE.D_PRIKAZ_INCLUDE, PEOPLE.N_GROUP, PEOPLE.STATUS_PEOPLE, PEOPLE.INC_GROUP, PEOPLE.WORK_BEFORE, PEOPLE.ADDRESS_BEFORE, PEOPLE.ADDRESS, PEOPLE.DATA_R, PEOPLE.F_OLD, PEOPLE.PHONE, PEOPLE.STATUS_KURS, PEOPLE.N_ZACHET, Specializ.SPECIAL, Specializ.SPECIAL_DIRECTION, Faculty.FAC1, PEOPLE.VID_EDU_INCLUDE, PEOPLE.N_FOUND_INCLUDE, PEOPLE.N_SPECIALIZ \
                 FROM PEOPLE   INNER JOIN SPECIALIZ Specializ  ON  (PEOPLE.N_SPECIALIZ = Specializ.N_SPECIALIZ)   INNER JOIN FACULTY Faculty   ON  (PEOPLE.N_FAC = Faculty.N_FAC) \
                 WHERE  People.STATUS_PEOPLE = 1  AND PEOPLE.NOMER=:NOMER ORDER BY People.FAM"
                );
            DataModule2 -> Report_Ut_CardFDQuery -> ParamByName ("NOMER") -> Value =
                DataModule1 -> PeopleFDQueryNOMER -> Value;
            DataModule2 -> Report_Ut_CardFDQuery -> Open ();
        } // end if выбран только один студент и он не отчислен и не в академ. отпуске
        else { // если это не действующий студент
            if (CheckBox4 -> Checked) { // отчисленные студенты
                DataModule2 -> Report_Ut_CardFDQuery -> SQL -> Clear ();
                // ---убрали кусок если надо показать в MyList всех отчисленных
                /* DataModule2 -> Report_Ut_CardFDQuery -> SQL -> Add ("SELECT PEOPLE.NOMER, PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH, PEOPLE.POL, PEOPLE.PLACE_R, PEOPLE.NAZ, PEOPLE.PAPA, PEOPLE.MAMA, PEOPLE.MARIAGE, PEOPLE.N_CHILD, PEOPLE.EDUCATION, PEOPLE.ARMY, PEOPLE.SCHOLARSHIP, PEOPLE.HOSTEL, PEOPLE.WORK_PAPA, PEOPLE.WORK_MAMA, PEOPLE.NAME_EDUC, PEOPLE.WHEN_EDUC, PEOPLE.WHERE_EDUC, PEOPLE.PHOTO, PEOPLE.MIDDLE_B, PEOPLE.N_VID_SPORT, PEOPLE.N_DELA, PEOPLE.VID_EDU, PEOPLE.KURS, PEOPLE.N_SPEC, PEOPLE.N_PRIKAZ_KURS, PEOPLE.EDU_WORK, PEOPLE.D_PRIKAZ_KURS, PEOPLE.N_FOUND, PEOPLE.N_PRIKAZ_INCLUDE, PEOPLE.D_PRIKAZ_INCLUDE, PEOPLE.N_GROUP, PEOPLE.STATUS_PEOPLE, PEOPLE.INC_GROUP, PEOPLE.WORK_BEFORE, PEOPLE.ADDRESS_BEFORE, PEOPLE.ADDRESS, PEOPLE.DATA_R, PEOPLE.F_OLD, PEOPLE.PHONE, PEOPLE.STATUS_KURS, PEOPLE.N_ZACHET, Specializ.SPECIAL, Faculty.FAC1, PEOPLE.VID_EDU_INCLUDE, PEOPLE.N_FOUND_INCLUDE, PEOPLE.N_SPECIALIZ \
                 FROM PEOPLE   INNER JOIN SPECIALIZ Specializ  ON  (PEOPLE.N_SPECIALIZ = Specializ.N_SPECIALIZ)   INNER JOIN FACULTY Faculty   ON  (PEOPLE.N_FAC = Faculty.N_FAC) \
                 WHERE  (People.N_FAC="+AnsiString (nom_fac)+") AND (People.STATUS_PEOPLE = 2) ORDER BY People.FAM"); */

                DataModule2 -> Report_Ut_CardFDQuery -> SQL -> Add ("SELECT PEOPLE.NOMER, PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH, PEOPLE.POL, PEOPLE.NAZ, PEOPLE.PAPA, PEOPLE.MAMA, PEOPLE.MARIAGE, PEOPLE.N_CHILD, PEOPLE.EDUCATION, PEOPLE.ARMY, PEOPLE.SCHOLARSHIP, PEOPLE.HOSTEL, PEOPLE.NAME_EDUC, PEOPLE.WHEN_EDUC, PEOPLE.WHERE_EDUC, PEOPLE.PHOTO, PEOPLE.MIDDLE_B, PEOPLE.N_VID_SPORT, PEOPLE.N_DELA, PEOPLE.VID_EDU, PEOPLE.KURS, PEOPLE.N_SPEC, PEOPLE.N_PRIKAZ_KURS, PEOPLE.EDU_WORK, PEOPLE.D_PRIKAZ_KURS, PEOPLE.N_FOUND, PEOPLE.N_PRIKAZ_INCLUDE, PEOPLE.D_PRIKAZ_INCLUDE, PEOPLE.N_GROUP, PEOPLE.STATUS_PEOPLE, PEOPLE.INC_GROUP, PEOPLE.WORK_BEFORE, PEOPLE.ADDRESS_BEFORE, PEOPLE.ADDRESS, PEOPLE.DATA_R, PEOPLE.F_OLD, PEOPLE.PHONE, PEOPLE.STATUS_KURS, PEOPLE.N_ZACHET, Specializ.SPECIAL, Specializ.SPECIAL_DIRECTION, Faculty.FAC1, PEOPLE.VID_EDU_INCLUDE, PEOPLE.N_FOUND_INCLUDE, PEOPLE.N_SPECIALIZ \
                 FROM PEOPLE   INNER JOIN SPECIALIZ Specializ  ON  (PEOPLE.N_SPECIALIZ = Specializ.N_SPECIALIZ)   INNER JOIN FACULTY Faculty   ON  (PEOPLE.N_FAC = Faculty.N_FAC) \
                 WHERE  People.STATUS_PEOPLE = 2  AND PEOPLE.NOMER=:NOMER ORDER BY People.FAM"
                    );
                DataModule2 -> Report_Ut_CardFDQuery -> ParamByName ("NOMER")
                    -> Value = DataModule1 -> PeopleFDQueryNOMER -> Value;

                DataModule2 -> Report_Ut_CardFDQuery -> Open ();
            } // end if  отчисленные студенты
            if (CheckBox5 -> Checked)
            { // студенты, находящиеся в академическом отпуске
                DataModule2 -> Report_Ut_CardFDQuery -> SQL -> Clear ();
                DataModule2 -> Report_Ut_CardFDQuery -> SQL -> Add ("SELECT PEOPLE.NOMER, PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH, PEOPLE.POL, PEOPLE.NAZ, PEOPLE.PAPA, PEOPLE.MAMA, PEOPLE.MARIAGE, PEOPLE.N_CHILD, PEOPLE.EDUCATION, PEOPLE.ARMY, PEOPLE.SCHOLARSHIP, PEOPLE.HOSTEL, PEOPLE.NAME_EDUC, PEOPLE.WHEN_EDUC, PEOPLE.WHERE_EDUC, PEOPLE.PHOTO, PEOPLE.MIDDLE_B, PEOPLE.N_VID_SPORT, PEOPLE.N_DELA, PEOPLE.VID_EDU, PEOPLE.KURS, PEOPLE.N_SPEC, PEOPLE.N_PRIKAZ_KURS, PEOPLE.EDU_WORK, PEOPLE.D_PRIKAZ_KURS, PEOPLE.N_FOUND, PEOPLE.N_PRIKAZ_INCLUDE, PEOPLE.D_PRIKAZ_INCLUDE, PEOPLE.N_GROUP, PEOPLE.STATUS_PEOPLE, PEOPLE.INC_GROUP, PEOPLE.WORK_BEFORE, PEOPLE.ADDRESS_BEFORE, PEOPLE.ADDRESS, PEOPLE.DATA_R, PEOPLE.F_OLD, PEOPLE.PHONE, PEOPLE.STATUS_KURS, PEOPLE.N_ZACHET, Specializ.SPECIAL, Specializ.SPECIAL_DIRECTION, Faculty.FAC1, PEOPLE.VID_EDU_INCLUDE, PEOPLE.N_FOUND_INCLUDE, PEOPLE.N_SPECIALIZ \
                 FROM PEOPLE   INNER JOIN SPECIALIZ Specializ  ON  (PEOPLE.N_SPECIALIZ = Specializ.N_SPECIALIZ)   INNER JOIN FACULTY Faculty   ON  (PEOPLE.N_FAC = Faculty.N_FAC) WHERE\
                (People.N_FAC=" + AnsiString (nom_fac) +
                    ") AND (People.STATUS_PEOPLE = 3) ORDER BY People.FAM");
                DataModule2 -> Report_Ut_CardFDQuery -> Open ();
            } // end if студенты, находящиеся в академическом отпуске
        } // end else это не действующий студент
    } // end else если выбран только один студент (только для действующего студента)
    // Формирование входного массива
    AnsiString *mas_stud[2]; // массив номеров и фамилий студентов
    for (int i = 0; i < 2; i++) { // for1
        mas_stud[i] =
            new AnsiString[DataModule2 -> Report_Ut_CardFDQuery -> RecordCount];
    }

    // Мой компонент
    DataModule2 -> Report_Ut_CardFDQuery -> First ();
    /* MyList1 -> FormCaption = "Печать учебной карточки";
     MyList1 -> SourceList -> Clear ();
     MyList1 -> FOutList -> Clear ();
     int i = 0;

     // MyList1 -> String=DataModule2 -> Report_CardQueryFAM -> Value     +" "+DataModule2 -> Report_CardQueryNAME -> Value+" "+DataModule2 -> Report_CardQueryOTCH -> Value;
     while (i <= DataModule2 -> Report_Ut_CardFDQuery -> RecordCount - 1) {
     mas_stud[0][i] = DataModule2 -> Report_Ut_CardFDQueryFAM -> Value + " " +
     DataModule2 -> Report_Ut_CardFDQueryNAME -> Value + " " +
     DataModule2 -> Report_Ut_CardFDQueryOTCH -> Value;
     MyList1 -> SourceList -> Add (mas_stud[0][i]);
     mas_stud[1][i] =
     AnsiString (DataModule2 -> Report_Ut_CardFDQueryNOMER -> Value);
     DataModule2 -> Report_Ut_CardFDQuery -> Next ();
     i++;
     } */

    DualListDlg = new TDualListDlg (this);
    DualListDlg -> Caption = "Выбор студентов для печати";
    DualListDlg -> SrcList -> Items -> Clear ();
    // int num_list = DM -> QLetterSourceKolCOUNT -> Value;
    for (int i = 0; i < DataModule2 -> Report_Ut_CardFDQuery -> RecordCount; i++) {
        mas_stud[0][i] = DataModule2 -> Report_Ut_CardFDQueryFAM -> Value + " " +
            DataModule2 -> Report_Ut_CardFDQueryNAME -> Value + " " +
            DataModule2 -> Report_Ut_CardFDQueryOTCH -> Value;
        mas_stud[1][i] =
            AnsiString (DataModule2 -> Report_Ut_CardFDQueryNOMER -> Value);
        DualListDlg -> SrcList -> Items -> AddObject
            (DataModule2 -> Report_Ut_CardFDQueryFAM -> Value + " " +
            DataModule2 -> Report_Ut_CardFDQueryNAME -> Value + " " +
            DataModule2 -> Report_Ut_CardFDQueryOTCH -> Value,
            (TObject*) (DataModule2 -> Report_Ut_CardFDQueryNOMER -> Value));
        DataModule2 -> Report_Ut_CardFDQuery -> Next ();
    }

    DualListDlg -> ShowModal ();

    if (DataModule2 -> printdlg == true) {
        if (DualListDlg -> DstList -> Count != 0) {
            // Отчет
            if (0 == DualListDlg -> SrcList -> Items -> Count) {
                // Процедура печати первой стороны учебной карточки

                DataModule2 -> Report_Ut_CardFDQuery -> First ();

                DataModule2 -> frxReport1 -> Clear ();
                // Процедура печати первой стороны учебной карточки
                Print_First_UtCard ();
                Print_To_UtCard ();
                Print_Three_UtCard ();
                if (DataModule2 -> Report_Ut_CardFDQueryVID_EDU -> Value == 1) {
                    Print_Four_UtCard ();
                }
                /* else { TfrxReportPage * Page3 = dynamic_cast<TfrxReportPage*>
                 (DataModule2 -> frxReport1 -> Pages[4]);
                 Page -> Visible = false; */

                DataModule2 -> frxReport1 -> PrepareReport ();
                DataModule2 -> frxReport1 -> ShowPreparedReport ();

            } // А если не всех студентов....
            else {
                AnsiString Str_Nomer = "";
                /* for (int i = 0; i <= MyList1 -> FOutList -> Count - 1; i++) {
                 for (int j = 0; j <= MyList1 -> SourceList -> Count - 1; j++) {
                 if (mas_stud[0][j] == MyList1 -> FOutList -> Strings[i]) {
                 Str_Nomer += mas_stud[1][j] + ",";
                 // возвращаем номер студента
                 j = MyList1 -> SourceList -> Count - 1;
                 // если нашли то уходим из цикла
                 }
                 } // 2-ой for
                 } // 1-ый for */

                for (int i = 0;
                i <= DualListDlg -> DstList -> Items -> Count - 1; i++) {
                    int Nomer_st =
                        (int) (DualListDlg -> DstList -> Items -> Objects[i]);
                    // int Nomer_st2 = DualListDlg -> DstList -> Items -> Objects[i] -> Value;
                    Str_Nomer += String (Nomer_st) + ",";
                    // возвращаем номер студента
                } // 1-ый for

                Str_Nomer.SetLength (Str_Nomer.Length () - 1);
                // Формирование Query для выхода
                DataModule2 -> Report_Ut_CardFDQuery -> Close ();
                DataModule2 -> Report_Ut_CardFDQuery -> SQL -> Clear ();

                if ( (!CheckBox4 -> Checked) && (!CheckBox5 -> Checked))
                { // отключен выбор отчисленных и академистов
                    DataModule2 -> Report_Ut_CardFDQuery -> SQL -> Add ("SELECT PEOPLE.NOMER, PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH, PEOPLE.POL, PEOPLE.NAZ, PEOPLE.PAPA, PEOPLE.MAMA, PEOPLE.MARIAGE, PEOPLE.N_CHILD, PEOPLE.EDUCATION, PEOPLE.ARMY, PEOPLE.SCHOLARSHIP, PEOPLE.HOSTEL, PEOPLE.NAME_EDUC, PEOPLE.WHEN_EDUC, PEOPLE.WHERE_EDUC, PEOPLE.PHOTO, PEOPLE.MIDDLE_B, PEOPLE.N_VID_SPORT, PEOPLE.N_DELA, PEOPLE.VID_EDU, PEOPLE.KURS, PEOPLE.N_SPEC, PEOPLE.N_PRIKAZ_KURS, PEOPLE.EDU_WORK, PEOPLE.D_PRIKAZ_KURS, PEOPLE.N_FOUND, PEOPLE.N_PRIKAZ_INCLUDE, PEOPLE.D_PRIKAZ_INCLUDE, PEOPLE.N_GROUP, PEOPLE.STATUS_PEOPLE, PEOPLE.INC_GROUP, PEOPLE.WORK_BEFORE, PEOPLE.ADDRESS_BEFORE, PEOPLE.ADDRESS, PEOPLE.ADDRESS_LIFE, PEOPLE.DATA_R, PEOPLE.F_OLD, PEOPLE.PHONE, PEOPLE.STATUS_KURS, PEOPLE.N_ZACHET, Specializ.SPECIAL, Specializ.SPECIAL_DIRECTION, Faculty.FAC1, PEOPLE.VID_EDU_INCLUDE, PEOPLE.N_FOUND_INCLUDE, PEOPLE.N_SPECIALIZ \
                 FROM PEOPLE   INNER JOIN SPECIALIZ Specializ  ON  (PEOPLE.N_SPECIALIZ = Specializ.N_SPECIALIZ)   INNER JOIN FACULTY Faculty   ON  (PEOPLE.N_FAC = Faculty.N_FAC) WHERE\
                 (PEOPLE.N_FAC=" + AnsiString (nom_fac) +
                        ") AND (PEOPLE.STATUS_PEOPLE=1) AND (PEOPLE.INC_GROUP=" +
                        VarToStr (search_inc_group) +
                        ")  and (People.NOMER IN (" + Str_Nomer +
                        "))   ORDER BY People.FAM");
                } // end if отключен выбор отчисленных и академистов
                else { // если выбраны или отлисленные или академисты
                    DataModule2 -> Report_Ut_CardFDQuery -> SQL -> Add ("SELECT PEOPLE.NOMER, PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH, PEOPLE.POL, PEOPLE.NAZ, PEOPLE.PAPA, PEOPLE.MAMA, PEOPLE.MARIAGE, PEOPLE.N_CHILD, PEOPLE.EDUCATION, PEOPLE.ARMY, PEOPLE.SCHOLARSHIP, PEOPLE.HOSTEL, PEOPLE.NAME_EDUC, PEOPLE.WHEN_EDUC, PEOPLE.WHERE_EDUC, PEOPLE.PHOTO, PEOPLE.MIDDLE_B, PEOPLE.N_VID_SPORT, PEOPLE.N_DELA, PEOPLE.VID_EDU, PEOPLE.KURS, PEOPLE.N_SPEC, PEOPLE.N_PRIKAZ_KURS, PEOPLE.EDU_WORK, PEOPLE.D_PRIKAZ_KURS, PEOPLE.N_FOUND, PEOPLE.N_PRIKAZ_INCLUDE, PEOPLE.D_PRIKAZ_INCLUDE, PEOPLE.N_GROUP, PEOPLE.STATUS_PEOPLE, PEOPLE.INC_GROUP, PEOPLE.WORK_BEFORE, PEOPLE.ADDRESS_BEFORE, PEOPLE.ADDRESS, PEOPLE.ADDRESS_LIFE, PEOPLE.DATA_R, PEOPLE.F_OLD, PEOPLE.PHONE, PEOPLE.STATUS_KURS, PEOPLE.N_ZACHET, Specializ.SPECIAL, Specializ.SPECIAL_DIRECTION, Faculty.FAC1, PEOPLE.VID_EDU_INCLUDE, PEOPLE.N_FOUND_INCLUDE, PEOPLE.N_SPECIALIZ \
                 FROM PEOPLE   INNER JOIN SPECIALIZ Specializ  ON  (PEOPLE.N_SPECIALIZ = Specializ.N_SPECIALIZ)   INNER JOIN FACULTY Faculty   ON  (PEOPLE.N_FAC = Faculty.N_FAC) WHERE\
                 (People.N_FAC=" + AnsiString (nom_fac) +
                        ")  and (People.NOMER IN (" + Str_Nomer +
                        "))   ORDER BY People.FAM");

                } // end else eсли выбраны или отлисленные или академисты
                DataModule2 -> Report_Ut_CardFDQuery -> Open ();

                // Печать отчета
                DataModule2 -> Report_Ut_CardFDQuery -> First ();

                DataModule2 -> frxReport1 -> Clear ();
                // Процедура печати первой стороны учебной карточки
                Print_First_UtCard ();
                Print_To_UtCard ();
                Print_Three_UtCard ();
                if (DataModule2 -> Report_Ut_CardFDQueryVID_EDU -> Value == 1) {
                    Print_Four_UtCard ();
                } /*
                 else { TfrxReportPage * Page3 = dynamic_cast<TfrxReportPage*>
                 (DataModule2 -> frxReport1 -> Pages[4]);
                 Page -> Visible = false;
                 } */
                DataModule2 -> frxReport1 -> PrepareReport ();
                DataModule2 -> frxReport1 -> ShowPreparedReport ();

            } // else Если не всех

        } // if (MyList1 -> FOutList -> Count!=0)
        else {
            ShowMessage ("Вы не выбрали для печати ни одного студента!!!");
        }
    } // if execute

    delete DualListDlg;
    // удаление массива студентов
    for (int i = 0; i < 2; i++)
        delete[]mas_stud[i];
    DataModule2 -> Report_Ut_CardFDQuery -> Close ();
    // Закрыть  все Query

}
// ---------------------------------------------------------------------------

void __fastcall TStudForm::Print_First_UtCard () {
    // функция печати первой стороны учебной карточки
    TfrxReportPage * Page;
    // DataModule2 -> frxReport1 -> Clear ();
    // Добовление первой страницы
    /* TfrxReportPage * Page = dynamic_cast<TfrxReportPage*>
     (DataModule2 -> frxReport1 -> Pages[nom]); */

    /* TPrinterOrientation land;
     land = poLandscape;
     // !!!Page -> ChangePaper (9,255,255,255,land);
     Page -> PaperSize = DMPAPER_A4;
     Page -> Orientation = land; */

    for (int i = 0; i < DataModule2 -> Report_Ut_CardFDQuery -> RecordCount; i++) {
        int nom = i;
        Page = new TfrxReportPage (DataModule2 -> frxReport1);
        Page -> Orientation = poLandscape;
        P_F (50, 20, 512, 30, TFontStyles () << fsBold, 20, "", haLeft, vaCenter,
            TfrxFrameTypes (), "Учебная карточка студента", nom,
            DataModule2 -> frxReport1, 0);
        // Линия
        TfrxLineView *Line1;
        Line1 = new TfrxLineView (Page);
        Line1 -> SetBounds (56, 60, 958, 6);
        Line1 -> Width = 3, 00;
        // Page -> Objects -> Add (Line1);
        // Зачетная книжка
        P_F (670, 20, 200, 20, TFontStyles () << fsBold, 14, "", haLeft, vaCenter,
            TfrxFrameTypes (), "№  зачетной книжки", nom,
            DataModule2 -> frxReport1, 0);
        P_F (870, 20, 134, 20, TFontStyles (), 14, "", haLeft, vaCenter,
            TfrxFrameTypes () << ftBottom,
            DataModule2 -> Report_Ut_CardFDQueryN_ZACHET -> Value, nom,
            DataModule2 -> frxReport1, 0);

        // Первая строка фамилия
        P_F (46, 66, 30, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (), "1.", nom,
            DataModule2 -> frxReport1, 0);
        P_F (72, 66, 434, 22, TFontStyles (), 14, "Arial", haCenter, vaCenter,
            TfrxFrameTypes () << ftBottom,
            DataModule2 -> Report_Ut_CardFDQueryFAM -> Value + "  " +
            DataModule2 -> Report_Ut_CardFDQueryNAME -> Value + "  " +
            DataModule2 -> Report_Ut_CardFDQueryOTCH -> Value, nom,
            DataModule2 -> frxReport1, 0);
        P_F (46, 88, 510, 12, TFontStyles () << fsItalic, 7, "Arial", haCenter,
            vaCenter, TfrxFrameTypes (), " (фамилия, имя, отчество)", nom,
            DataModule2 -> frxReport1, 0);
        // Вторая строка Адрес
        P_F (46, 100, 80, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (), "2. Адрес ", nom,
            DataModule2 -> frxReport1, 0);
        P_F (126, 100, 384, 36, TFontStyles (), 10, "Arial", haLeft, vaTop,
            TfrxFrameTypes () << ftBottom,
            DataModule2 -> Report_Ut_CardFDQueryADDRESS -> Value, nom,
            DataModule2 -> frxReport1, 0);
        TfrxLineView *Line2;
        Line2 = new TfrxLineView (Page);
        Line2 -> SetBounds (126, 118, 384, 366);
        // старый кусок

        // новый кусок  Третья строка
        P_F (46, 136, 250, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (),
            "3. Зачислен в УВО приказом №  ", nom, DataModule2 -> frxReport1, 0);
        P_F (256, 136, 40, 18, TFontStyles (), 10, "Arial", haCenter, vaCenter,
            TfrxFrameTypes () << ftBottom,
            IntToStr (DataModule2 -> Report_Ut_CardFDQueryN_PRIKAZ_INCLUDE -> Value),
            nom, DataModule2 -> frxReport1, 0);
        P_F (296, 136, 26, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haCenter, vaCenter, TfrxFrameTypes (), "от", nom,
            DataModule2 -> frxReport1, 0);
        P_F (322, 136, 100, 18, TFontStyles (), 10, "Arial", haCenter, vaCenter,
            TfrxFrameTypes () << ftBottom,
            DateToStr (SQLTimeStampToDateTime
            (DataModule2 -> Report_Ut_CardFDQueryD_PRIKAZ_INCLUDE -> Value)), nom,
            DataModule2 -> frxReport1, 0);
        P_F (422, 136, 20, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haCenter, vaCenter, TfrxFrameTypes (), "на", nom,
            DataModule2 -> frxReport1, 0);
        P_F (442, 136, 28, 18, TFontStyles (), 10, "Arial", haCenter, vaCenter,
            TfrxFrameTypes () << ftBottom,
            IntToStr (DataModule2 -> Report_Ut_CardFDQueryN_PRIKAZ_KURS -> Value),
            nom, DataModule2 -> frxReport1, 0);
        P_F (470, 136, 40, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haCenter, vaCenter, TfrxFrameTypes (), " курс", nom,
            DataModule2 -> frxReport1, 0);

        Variant vid_enc =
            DataModule2 -> Report_Ut_CardFDQueryVID_EDU_INCLUDE -> AsVariant;
        if (!vid_enc.IsNull ()) { // if если непустое значение поля
            if (!DataModule2 -> Report_Ut_CardFDQueryVID_EDU_INCLUDE -> Value)
                // =0 дневное
            { // if дневное обучение при зачислении
                P_F (46, 154, 55, 18, TFontStyles (), 10, "Arial", haCenter,
                    vaCenter, TfrxFrameTypes () << ftBottom, "дневной", nom,
                    DataModule2 -> frxReport1, 0);
            } // end if дневное обучение при зачислении
            else // =1 заочное
            { // else заочное обучение при зачислении
                P_F (46, 154, 55, 18, TFontStyles (), 10, "Arial", haCenter,
                    vaCenter, TfrxFrameTypes () << ftBottom, "заочной", nom,
                    DataModule2 -> frxReport1, 0);
            } // end else заочное обучение при зачислении
        } // end if если непустое значение поля
        else
            P_F (46, 154, 55, 18, TFontStyles (), 10, "Arial", haCenter, vaCenter,
            TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);
        // пустое поле

        P_F (101, 154, 224, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haCenter, vaCenter, TfrxFrameTypes (),
            "формы получения образования ", nom, DataModule2 -> frxReport1, 0);
        P_F (325, 154, 74, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haCenter, vaCenter, TfrxFrameTypes (), "основание", nom,
            DataModule2 -> frxReport1, 0);
        // N_FOUND_INCLUDE   основание зачисления
        Variant found_enc = DM2 -> FoundationFDTable -> Lookup ("N_FOUND",
            DataModule2 -> Report_Ut_CardFDQueryN_FOUND_INCLUDE -> Value,
            "VID_FOUND");
        if (!found_enc.IsNull ()) { // if если непустое значение поля
            P_F (399, 154, 110, 18, TFontStyles (), 10, "Arial", haCenter,
                vaCenter, TfrxFrameTypes () << ftBottom, found_enc, nom,
                DataModule2 -> frxReport1, 0);
        } // if если непустое значение поля
        else
            P_F (399, 154, 110, 18, TFontStyles (), 10, "Arial", haCenter,
            vaCenter, TfrxFrameTypes () << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);
        // пустое поле

        if (nom_fac == 4)
            P_F (46, 172, 140, 18, TFontStyles () << fsBold << fsItalic, 8,
            "Arial", haCenter, vaCenter, TfrxFrameTypes () << ftBottom,
            DataModule2 -> Report_Ut_CardFDQueryFAC1 -> Value, nom,
            DataModule2 -> frxReport1, 0);
        else {
            P_F (46, 172, 50, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haCenter, vaCenter, TfrxFrameTypes (), "фак-т", nom,
                DataModule2 -> frxReport1, 0);
            P_F (96, 172, 90, 18, TFontStyles (), 10, "Arial", haCenter, vaCenter,
                TfrxFrameTypes () << ftBottom,
                DataModule2 -> Report_Ut_CardFDQueryFAC1 -> Value, nom,
                DataModule2 -> frxReport1, 0);
        }
        // по специализации  или направлению специальности

        if (DataModule2 -> Report_Ut_CardFDQueryN_SPEC -> Value == 1) {
            P_F (46, 190, 130, 36, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haCenter, vaCenter, TfrxFrameTypes (),
                "по специализации", nom, DataModule2 -> frxReport1, 0);
            P_F (166, 190, 334, 36, TFontStyles (), 10, "Arial", haLeft, vaCenter,
                TfrxFrameTypes () << ftBottom,
                DataModule2 -> Report_Ut_CardFDQuerySPECIAL -> Value, nom,
                DataModule2 -> frxReport1, 0);
            TfrxLineView *Line3;
            Line3 = new TfrxLineView (Page);
            Line3 -> SetBounds (166, 208, 334, 36);
        }

        else {
            P_F (46, 190, 120, 36, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haLeft, vaCenter, TfrxFrameTypes (),
                "по направлению специальности", nom,
            DataModule2 -> frxReport1, 0);
            P_F (166, 190, 344, 36, TFontStyles (), 10, "Arial", haLeft, vaCenter,
                TfrxFrameTypes () << ftBottom,
                DataModule2 -> Report_Ut_CardFDQuerySPECIAL_DIRECTION -> Value, nom,
                DataModule2 -> frxReport1, 0);
            TfrxLineView *Line3;
            Line3 = new TfrxLineView (Page);
            Line3 -> SetBounds (166, 208, 344, 36);
        }

        // в порядке перевода
        P_F (46, 226, 100, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (), "- обучался в ", nom,
            DataModule2 -> frxReport1, 0);

        // Передача параметров номера студента и типа прика о переводе из другого ВУЗа (7)
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Close ();
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("NOMER")
            -> Value = DataModule2 -> Report_Ut_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("TYPE")
            -> Value = 7;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Open ();
        // Если Query получено не пустое
        if (DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount != 0) {
            P_F (146, 208, 364, 18, TFontStyles (), 7, "Arial", haCenter,
                vaCenter, TfrxFrameTypes () << ftBottom,
                DataModule2 -> Report_Ut_Public_PrikazFDQueryDESCRIBE -> Value, nom,
                DataModule2 -> frxReport1, 0);
        }

        // ------------------------------------
        // Академические отпуска
        P_F (46, 262, 464, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (), "4. Отпуска", nom,
            DataModule2 -> frxReport1, 0);
        // Шапка таблицы
        P_F (46, 280, 20, 36, TFontStyles () << fsBold, 10, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "№",
            nom, DataModule2 -> frxReport1, 0);
        P_F (66, 280, 122, 36, TFontStyles () << fsBold, 10, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "Тип",
            nom, DataModule2 -> frxReport1, 0);
        P_F (188, 280, 120, 18, TFontStyles () << fsBold, 10, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "Дата",
            nom, DataModule2 -> frxReport1, 0);
        P_F (188, 298, 60, 18, TFontStyles () << fsBold, 8, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "с",
            nom, DataModule2 -> frxReport1, 0);
        P_F (248, 298, 60, 18, TFontStyles () << fsBold, 8, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "по",
            nom, DataModule2 -> frxReport1, 0);
        P_F (308, 280, 80, 36, TFontStyles () << fsBold, 10, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "№ и дата приказа", nom, DataModule2 -> frxReport1, 0);
        P_F (388, 280, 122, 36, TFontStyles () << fsBold, 10, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "Причина", nom, DataModule2 -> frxReport1, 0);
        // Подготовка Query по академ. отпускам
        DataModule2 -> Report_Ut_HolidayFDQuery -> Close ();
        DataModule2 -> Report_Ut_HolidayFDQuery -> ParamByName ("NOMER") -> Value =
            DataModule2 -> Report_Ut_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Ut_HolidayFDQuery -> Open ();
        DataModule2 -> Report_Ut_HolidayFDQuery -> First ();
        int k = 0;
        for (int i = 1; i <= 5; i++) {
            P_F (46, 316 + k, 20, 36, TFontStyles () << fsBold, 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                IntToStr (i), nom, DataModule2 -> frxReport1, 0);
            // Тип а/о
            if (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof) {
                switch (DataModule2 -> Report_Ut_HolidayFDQueryTYPE_HOL -> Value)
                { // ---старая часть по приказам до сентября 2006 года
                case 1:
                    P_F (66, 316 + k, 122, 36, TFontStyles (), 8, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Уход в академ. отпуск", nom,
                        DataModule2 -> frxReport1, 0);
                    break;
                case 2:
                    P_F (66, 316 + k, 122, 36, TFontStyles (), 8, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Академ. отпуск продлен", nom,
                        DataModule2 -> frxReport1, 0);
                    break;
                case 3:
                    P_F (66, 316 + k, 122, 36, TFontStyles (), 8, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Считать вернувшимся из а/о", nom,
                        DataModule2 -> frxReport1, 0);
                    break;

                    // ------новая часть
                case 4:
                    P_F (66, 316 + k, 122, 36, TFontStyles (), 8, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Академический отпуск", nom,
                        DataModule2 -> frxReport1, 0);
                    break;
                case 5:
                    P_F (66, 316 + k, 122, 36, TFontStyles (), 8, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Продление академ. отпуска", nom,
                        DataModule2 -> frxReport1, 0);
                    break;
                case 6:
                    P_F (66, 316 + k, 122, 36, TFontStyles (), 8, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Выход из отпуска", nom, DataModule2 -> frxReport1, 0);
                    break;
                case 7:
                    P_F (66, 316 + k, 122, 36, TFontStyles (), 8, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Отпуск по беременности и родам", nom,
                        DataModule2 -> frxReport1, 0);
                    break;
                case 8:
                    P_F (66, 316 + k, 122, 36, TFontStyles (), 8, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Отпуск по уходу за ребенком до 3-х лет", nom,
                        DataModule2 -> frxReport1, 0);
                    break;
                case 9:
                    P_F (66, 316 + k, 122, 36, TFontStyles (), 7, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Отпуск по уходу за ребенком до 3-х лет со свободным посещением",
                        nom, DataModule2 -> frxReport1, 0);
                    break;

                case 10:
                    P_F (66, 316 + k, 122, 36, TFontStyles (), 7, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Отпуск по беременности", nom,
                        DataModule2 -> frxReport1, 0);
                    break;
                case 11:
                    P_F (66, 316 + k, 122, 36, TFontStyles (), 8, "Arial",
                        haCenter, vaCenter,
                        TfrxFrameTypes ()
                        << ftLeft << ftRight << ftTop << ftBottom,
                        "Отпуск для прохождения военной службы", nom,
                        DataModule2 -> frxReport1, 0);
                    break;
                } // switch
            }
            else
                P_F (66, 316 + k, 122, 36, TFontStyles (), 9, "Arial", haCenter,
                vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);

            if (DataModule2 -> Report_Ut_HolidayFDQueryTYPE_HOL -> Value == 3 ||
                DataModule2 -> Report_Ut_HolidayFDQueryTYPE_HOL -> Value == 6)
            { // if  выбран тип приказа выход из а/о
                // Дата с
                if (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof)
                    P_F (188, 316 + k, 60, 36, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    SQLTimeStampToDateTime (DataModule2 -> 
                    Report_Ut_HolidayFDQueryD_END_HOL -> Value).DateString (), nom,
                    DataModule2 -> frxReport1, 0);
                else
                    P_F (188, 316 + k, 60, 36, TFontStyles (), 9, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                // Дата по
                if (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof)
                    P_F (248, 316 + k, 60, 36, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                else
                    P_F (248, 316 + k, 60, 36, TFontStyles (), 9, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                // Номер и дата приказа
                if (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof)
                    P_F (308, 316 + k, 80, 36, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "№" + IntToStr
                    (DataModule2 -> Report_Ut_HolidayFDQueryN_PRIKAZ_HOL -> Value) +
                    " от " + DateToStr (SQLTimeStampToDateTime
                    (DataModule2 -> Report_Ut_HolidayFDQueryD_PRIKAZ_HOL -> Value)),
                    nom, DataModule2 -> frxReport1, 0);
                else
                    P_F (308, 316 + k, 80, 36, TFontStyles (), 9, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                // Причина
                if ( (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof) &&
                    (DataModule2 -> Report_Ut_HolidayFDQueryCAUSE_HOL -> Value
                    != "Нет"))
                    P_F (388, 316 + k, 122, 36, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    DataModule2 -> Report_Ut_HolidayFDQueryCAUSE_HOL -> Value, nom,
                    DataModule2 -> frxReport1, 0);
                else
                    P_F (388, 316 + k, 122, 36, TFontStyles (), 9, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
            } // end if выбран тип приказа выход из а/о
            else { // else если выбран тип приказа НЕ выход из а/о
                // Дата с
                if ( (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof) &&
                    (DataModule2 -> Report_Ut_HolidayFDQueryD_BEGIN_HOL -> 
                    AsString != ""))
                    P_F (188, 316 + k, 60, 36, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    SQLTimeStampToDateTime (DataModule2 -> 
                    Report_Ut_HolidayFDQueryD_BEGIN_HOL -> Value).DateString (),
                    nom, DataModule2 -> frxReport1, 0);
                else
                    P_F (188, 316 + k, 60, 36, TFontStyles (), 9, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                // Дата по
                if ( (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof) &&
                    (DataModule2 -> Report_Ut_HolidayFDQueryD_END_HOL -> 
                    AsString != ""))
                    P_F (248, 316 + k, 60, 36, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    SQLTimeStampToDateTime (DataModule2 -> 
                    Report_Ut_HolidayFDQueryD_END_HOL -> Value).DateString (), nom,
                    DataModule2 -> frxReport1, 0);
                else
                    P_F (248, 316 + k, 60, 36, TFontStyles (), 9, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                // Номер и дата приказа
                if (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof)
                    P_F (308, 316 + k, 80, 36, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "№" + IntToStr
                    (DataModule2 -> Report_Ut_HolidayFDQueryN_PRIKAZ_HOL -> Value) +
                    " от " + DateToStr (SQLTimeStampToDateTime
                    (DataModule2 -> Report_Ut_HolidayFDQueryD_PRIKAZ_HOL -> Value)),
                    nom, DataModule2 -> frxReport1, 0);
                else
                    P_F (308, 316 + k, 80, 36, TFontStyles (), 9, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                // Причина
                if ( (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof) &&
                    (DataModule2 -> Report_Ut_HolidayFDQueryCAUSE_HOL -> Value
                    != "Нет"))
                    P_F (388, 316 + k, 122, 36, TFontStyles (), 8, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    DataModule2 -> Report_Ut_HolidayFDQueryCAUSE_HOL -> Value, nom,
                    DataModule2 -> frxReport1, 0);
                else
                    P_F (388, 316 + k, 122, 36, TFontStyles (), 9, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
            } // end else  если выбран тип приказа НЕ выход из а/о

            // Формирование след. строки
            k = k + 36;
            // На следующую запись по академистам
            if (!DataModule2 -> Report_Ut_HolidayFDQuery -> Eof)
                DataModule2 -> Report_Ut_HolidayFDQuery -> Next ();

        }
        // ---------------------------------------------------
        // Таблица Отчислений/востановлений
        P_F (46, 532, 510, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (),
            "5. Приказы на отчисление и восстановление", nom,
            DataModule2 -> frxReport1, 0);
        // Формирование Query приказов для отчисленных
        DataModule2 -> Report_Ut_Prik_Restore_OtFDQuery -> Close ();
        DataModule2 -> Report_Ut_Prik_Restore_OtFDQuery -> ParamByName ("NOMER")
            -> Value = DataModule2 -> Report_Ut_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Ut_Prik_Restore_OtFDQuery -> Open ();
        // Формирование Query приказов для восстановленных
        DataModule2 -> Report_Ut_Prik_Restore_VosFDQuery -> Close ();
        DataModule2 -> Report_Ut_Prik_Restore_VosFDQuery -> ParamByName ("NOMER")
            -> Value = DataModule2 -> Report_Ut_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Ut_Prik_Restore_VosFDQuery -> Open ();
        // Шапка таблицы
        P_F (46, 550, 20, 36, TFontStyles () << fsBold, 10, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "№",
            nom, DataModule2 -> frxReport1, 0);
        P_F (66, 550, 122, 36, TFontStyles () << fsBold, 10, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "№ и дата приказа на отчисление", nom, DataModule2 -> frxReport1, 0);
        P_F (188, 550, 200, 36, TFontStyles () << fsBold, 10, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "Причина отчисления", nom, DataModule2 -> frxReport1, 0);
        P_F (388, 550, 122, 36, TFontStyles () << fsBold, 10, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "№ и дата приказа на восстанов.", nom, DataModule2 -> frxReport1, 0);
        DataModule2 -> Report_Ut_Prik_Restore_OtFDQuery -> First ();
        k = 0;
        for (int i = 1; i <= 3; i++) {

            AnsiString desc = "";

            P_F (46, 586 + k, 20, 36, TFontStyles () << fsBold, 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                IntToStr (i), nom, DataModule2 -> frxReport1, 0);
            // Определение приказав на отчисление
            if (!DataModule2 -> Report_Ut_Prik_Restore_OtFDQuery -> Eof) {
                P_F (66, 586 + k, 122, 36, TFontStyles (), 9, "Arial", haCenter,
                    vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "№" + IntToStr
                    (DataModule2 -> Report_Ut_Prik_Restore_OtFDQueryN_PRIKAZ_RES -> 
                    Value) + " от " + DateToStr
                    (SQLTimeStampToDateTime
                    (DataModule2 -> Report_Ut_Prik_Restore_OtFDQueryD_PRIKAZ_RES -> 
                    Value)), nom, DataModule2 -> frxReport1, 0);
                desc = DataModule2 -> 
                    Report_Ut_Prik_Restore_OtFDQueryCAUSE_RES -> Value;
                if (DataModule2 -> Report_Ut_Prik_Restore_OtFDQueryDESCRIBE -> 
                    Value != "")
                    desc += " " +
                        DataModule2 -> 
                        Report_Ut_Prik_Restore_OtFDQueryDESCRIBE -> Value;

            }
            // Определение приказав на отчисление если нет уже записей
            else
                P_F (66, 586 + k, 122, 36, TFontStyles (), 9, "Arial", haCenter,
                vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);

            // Определение приказов на востановление
            if (!DataModule2 -> Report_Ut_Prik_Restore_VosFDQuery -> Eof) {

                P_F (388, 586 + k, 122, 36, TFontStyles (), 9, "Arial", haCenter,
                    vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "№" + IntToStr
                    (DataModule2 -> Report_Ut_Prik_Restore_VosFDQueryN_PRIKAZ_RES
                    -> Value) + " от " + DateToStr
                    (SQLTimeStampToDateTime
                    (DataModule2 -> Report_Ut_Prik_Restore_VosFDQueryD_PRIKAZ_RES
                    -> Value)), nom, DataModule2 -> frxReport1, 0);

                if (desc != "")
                    desc += "; ";
                desc += DataModule2 -> 
                    Report_Ut_Prik_Restore_VosFDQueryDESCRIBE -> Value;

                if (DataModule2 -> 
                    Report_Ut_Prik_Restore_VosFDQueryN_CAUSE_RESTORE -> 
                    Value == 17)
                    P_F (46, 586, 364, 18, TFontStyles (), 7, "Arial", haCenter,
                    vaCenter, TfrxFrameTypes () << ftBottom,
                    DataModule2 -> Report_Ut_Prik_Restore_VosFDQueryDESCRIBE -> 
                    Value, nom, DataModule2 -> frxReport1, 0);
            }
            // Определение приказов на востановление если нет уже записей
            else
                P_F (388, 586 + k, 122, 36, TFontStyles (), 9, "Arial", haCenter,
                vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
            ////---------------------------------
            // Причина отчисления  и восстановления

            if (desc != "")
                P_F (188, 586 + k, 200, 36, TFontStyles (), 7, "Arial", haCenter,
                vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                desc, nom, DataModule2 -> frxReport1, 0);
            // Определение причины отчисление если нет уже записей
            else
                P_F (188, 586 + k, 200, 36, TFontStyles (), 8, "Arial", haCenter,
                vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);

            // Формирование след. строки
            k = k + 36;
            // На следующую запись по отчисленным
            if (!DataModule2 -> Report_Ut_Prik_Restore_OtFDQuery -> Eof)
                DataModule2 -> Report_Ut_Prik_Restore_OtFDQuery -> Next ();
            // На следующую запись по востановленным
            if (!DataModule2 -> Report_Ut_Prik_Restore_VosFDQuery -> Eof)
                DataModule2 -> Report_Ut_Prik_Restore_VosFDQuery -> Next ();

        }

        // -----------------------------------
        // Сдано за весь курс обучения
        P_F (560, 66, 225, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (),
            "6. Сдано за весь срок обучения", nom, DataModule2 -> frxReport1, 0);
        P_F (785, 66, 100, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haCenter, vaCenter, TfrxFrameTypes () << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);
        P_F (885, 66, 125, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (), "предметов", nom,
            DataModule2 -> frxReport1, 0);
        P_F (560, 84, 50, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haCenter, vaCenter, TfrxFrameTypes (), "из них:", nom,
            DataModule2 -> frxReport1, 0);
        if (syst_ball == 5) { // ---для пятибальной системы
            P_F (785, 102, 100, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haCenter, vaCenter, TfrxFrameTypes () << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
            P_F (885, 102, 150, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haCenter, vaCenter, TfrxFrameTypes (), "отлично", nom,
                DataModule2 -> frxReport1, 0);

            P_F (785, 120, 100, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haCenter, vaCenter, TfrxFrameTypes () << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
            P_F (885, 120, 150, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haCenter, vaCenter, TfrxFrameTypes (), "хорошо", nom,
                DataModule2 -> frxReport1, 0);

            P_F (785, 138, 100, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haCenter, vaCenter, TfrxFrameTypes () << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
            P_F (885, 138, 150, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haCenter, vaCenter, TfrxFrameTypes (),
                "удовлетворительно", nom, DataModule2 -> frxReport1, 0);
        }
        else { // ---для десятибальной системы
            P_F (610, 84, 100, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haCenter, vaCenter, TfrxFrameTypes () << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
            P_F (710, 84, 75, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haLeft, vaCenter, TfrxFrameTypes (), "четыре", nom,
                DataModule2 -> frxReport1, 0);

            P_F (610, 102, 100, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haCenter, vaCenter, TfrxFrameTypes () << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
            P_F (710, 102, 75, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haLeft, vaCenter, TfrxFrameTypes (), "пять", nom,
                DataModule2 -> frxReport1, 0);

            P_F (610, 120, 100, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haCenter, vaCenter, TfrxFrameTypes () << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
            P_F (710, 120, 75, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haLeft, vaCenter, TfrxFrameTypes (), "шесть", nom,
                DataModule2 -> frxReport1, 0);

            P_F (610, 138, 100, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haCenter, vaCenter, TfrxFrameTypes () << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
            P_F (710, 138, 75, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haLeft, vaCenter, TfrxFrameTypes (), "семь", nom,
                DataModule2 -> frxReport1, 0);
            // ----
            P_F (785, 102, 100, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haCenter, vaCenter, TfrxFrameTypes () << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
            P_F (885, 102, 75, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haLeft, vaCenter, TfrxFrameTypes (), "восемь", nom,
                DataModule2 -> frxReport1, 0);

            P_F (785, 120, 100, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haCenter, vaCenter, TfrxFrameTypes () << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
            P_F (885, 120, 75, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haLeft, vaCenter, TfrxFrameTypes (), "девять", nom,
                DataModule2 -> frxReport1, 0);

            P_F (785, 138, 100, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haCenter, vaCenter, TfrxFrameTypes () << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
            P_F (885, 138, 75, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haLeft, vaCenter, TfrxFrameTypes (), "десять", nom,
                DataModule2 -> frxReport1, 0);
        } // ------

        // 25.03.2014 - Приказ о докуске к ГОС
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Close ();
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("NOMER")
            -> Value = DataModule2 -> Report_Ut_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("TYPE")
            -> Value = 12;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Open ();
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Last ();
        if (DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount != 0) {
            P_F (670, 167, 122, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
                TfrxFrameTypes () << ftBottom,
                IntToStr (DataModule2 -> 
                Report_Ut_Public_PrikazFDQueryN_PUBLIC_PRIKAZ -> Value) + " от " +
                DateToStr (SQLTimeStampToDateTime
                (DataModule2 -> Report_Ut_Public_PrikazFDQueryD_PUBLIC_PRIKAZ -> 
                Value)), nom, DataModule2 -> frxReport1, 0);
        }
        else {
            P_F (670, 170, 122, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
                TfrxFrameTypes () << ftBottom, " от ", nom,
                DataModule2 -> frxReport1, 0);
        }

        // 25.03.2014 - приказ о допуске к диплому

        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Close ();
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("NOMER")
            -> Value = DataModule2 -> Report_Ut_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("TYPE")
            -> Value = 13;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Open ();
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Last ();
        if (DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount != 0) {
            P_F (670, 185, 122, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
                TfrxFrameTypes () << ftBottom,
                IntToStr (DataModule2 -> 
                Report_Ut_Public_PrikazFDQueryN_PUBLIC_PRIKAZ -> Value) + " от " +
                DateToStr (SQLTimeStampToDateTime
                (DataModule2 -> Report_Ut_Public_PrikazFDQueryD_PUBLIC_PRIKAZ -> 
                Value)), nom, DataModule2 -> frxReport1, 0);
        }
        else {
            P_F (670, 190, 122, 18, TFontStyles (), 10, "Arial", haLeft, vaCenter,
                TfrxFrameTypes () << ftBottom, " от ", nom,
                DataModule2 -> frxReport1, 0);
        }

        P_F (560, 171, 110, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (), "7. Приказом №", nom,
            DataModule2 -> frxReport1, 0);
        P_F (792, 174, 220, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haCenter, vaCenter, TfrxFrameTypes (),
            "допущен к сдаче госэкзаменов, ", nom, DataModule2 -> frxReport1, 0);
        P_F (560, 189, 540, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (), "    приказом №", nom,
            DataModule2 -> frxReport1, 0);
        P_F (792, 189, 540, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (), "допущен к защите диплома", nom,
            DataModule2 -> frxReport1, 0);

        // Государственные экзамены
        P_F (560, 216, 510, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (), "8. Государственные экзамены",
            nom, DataModule2 -> frxReport1, 0);
        // Шапка таблицы
        P_F (560, 234, 252, 36, TFontStyles () << fsBold, 10, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "Название дисциплины", nom, DataModule2 -> frxReport1, 0);
        P_F (812, 234, 90, 36, TFontStyles () << fsBold, 10, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "Дата",
            nom, DataModule2 -> frxReport1, 0);
        P_F (902, 234, 122, 36, TFontStyles () << fsBold, 10, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "Оценка", nom, DataModule2 -> frxReport1, 0);
        k = 0;
        // Печать таб по госам

        DataModule2 -> Report_Ut_DiplomFDQuery -> Close ();
        DataModule2 -> Report_Ut_DiplomFDQuery -> SQL -> Clear ();
        DataModule2 -> Report_Ut_DiplomFDQuery -> SQL -> Add ("SELECT Gek.NOMER_GEK, Gek.NOMER, Gek.N_VED, Gek.THEME, Gek.D_GEK, \
                                                 Gek.BALL_GEK, Gek.D_PROTOCOL, Gek.N_PROTOCOL, Object_plan.NAME_OBJECT \
                                                 FROM GEK Gek   \
                                                  INNER JOIN VEDOMOST_GEK Vedomost_gek  \
                                                  ON  (Gek.N_VED = Vedomost_gek.N_VED)\
                                                  INNER JOIN EDU_PLAN Edu_plan   \
                                                  ON  (Vedomost_gek.N_PLAN = Edu_plan.N_PLAN)\
                                                  INNER JOIN OBJECT_PLAN Object_plan      \
                                                  ON  (Edu_plan.N_OBJECT = Object_plan.N_OBJECT)  \
                                                 Where Gek.NOMER=:NOMER and Gek.BALL_GEK<>6 and Gek.BALL_GEK<>11 and Gek.BALL_GEK<>12 and Gek.BALL_GEK<>13 \
                                                 order by Gek.d_gek");
        DataModule2 -> Report_Ut_DiplomFDQuery -> ParamByName ("NOMER") -> Value =
            DataModule2 -> Report_Ut_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Ut_DiplomFDQuery -> Open ();

        for (int i = 1; i <= 2; i++) {
            if ( (!DataModule2 -> Report_Ut_DiplomFDQuery -> Eof) &&
                (DataModule2 -> Report_Ut_DiplomFDQueryTHEME -> Value == ""))
            { // ---изменения для выбора названия предмета
                // Page -> Objects -> Add (P_F (570,484+k,225,36,0,10,"Arial",2+8,15,DataModule2 -> Report_Ut_DiplomNAME_OBJECT -> Value));
                P_F (560, 270 + k, 252, 40, TFontStyles (), 8, "Arial", haCenter,
                    vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    Text_predmet (DataModule2 -> Report_Ut_DiplomFDQueryNAME_OBJECT
                    -> Value,
                    DataModule2 -> Report_Ut_CardFDQueryN_SPECIALIZ -> Value), nom,
                    DataModule2 -> frxReport1, 0);

                P_F (812, 270 + k, 90, 40, TFontStyles (), 8, "Arial", haCenter,
                    vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    DateToStr (SQLTimeStampToDateTime
                    (DataModule2 -> Report_Ut_DiplomFDQueryD_GEK -> Value)), nom,
                    DataModule2 -> frxReport1, 0);
                ///-----старый кусок
                // Page -> Objects -> Add (P_F (885,484+k,135,36,0,10,"Arial",2+8,15,Ocenka (IntToStr (DataModule2 -> Report_Ut_DiplomBALL_GEK -> Value))));
                // ---
                // новый
                P_F (902, 270 + k, 122, 40, TFontStyles (), 8, "Arial", haCenter,
                    vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    ball_string (syst_ball, ball_int (syst_ball,
                    DataModule2 -> Report_Ut_DiplomFDQueryBALL_GEK -> Value), 1),
                    nom, DataModule2 -> frxReport1, 0);
                // -----
            }
            else {
                P_F (560, 270 + k, 252, 40, TFontStyles () << fsBold, 10, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                P_F (812, 270 + k, 90, 40, TFontStyles () << fsBold, 10, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                P_F (902, 270 + k, 122, 40, TFontStyles () << fsBold, 10, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
            }
            // Формирование след. строки
            k = k + 40; // k=k+36;
            if (!DataModule2 -> Report_Ut_DiplomFDQuery -> Eof)
                DataModule2 -> Report_Ut_DiplomFDQuery -> Next ();

        }

        // Дипломный проект выполнил на тему

        P_F (560, 352, 510, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (),
            "9. Дипломную работу выполнил на тему:", nom,
            DataModule2 -> frxReport1, 0);

        // тема диплома
        P_F (560, 370, 464, 54, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haCenter, vaCenter, TfrxFrameTypes (), "", nom,
            DataModule2 -> frxReport1, 0);
        P_F (560, 424, 90, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (), "и защитил", nom,
            DataModule2 -> frxReport1, 0);
        // дата
        P_F (650, 424, 100, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haCenter, vaCenter, TfrxFrameTypes () << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);
        // оценка
        P_F (750, 424, 90, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (), "с отметкой", nom,
            DataModule2 -> frxReport1, 0);
        P_F (840, 424, 184, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haCenter, vaCenter, TfrxFrameTypes () << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);

        DataModule2 -> Report_Ut_DiplomFDQuery -> First ();

        while (!DataModule2 -> Report_Ut_DiplomFDQuery -> Eof) {
            if (DataModule2 -> Report_Ut_DiplomFDQueryTHEME -> Value != "") {
                // тема
                P_F (560, 370, 464, 54, TFontStyles () << fsUnderline, 10,
                    "Arial", haCenter, vaCenter, TfrxFrameTypes (),
                    DataModule2 -> Report_Ut_DiplomFDQueryTHEME -> Value, nom,
                    DataModule2 -> frxReport1, 0);
                // Дата
                P_F (660, 424, 100, 18, TFontStyles (), 10, "Arial", haCenter,
                    vaCenter, TfrxFrameTypes () << ftBottom,
                    DateToStr (SQLTimeStampToDateTime
                    (DataModule2 -> Report_Ut_DiplomFDQueryD_GEK -> Value)), nom,
                    DataModule2 -> frxReport1, 0);
                // оценка
                // ----старый кусок
                // Page -> Objects -> Add (P_F (850,610,170,18,0,10,"Arial",0,2,Ocenka (IntToStr (DataModule2 -> Report_Ut_DiplomBALL_GEK -> Value))));
                // ----------
                // новый
                P_F (840, 424, 184, 18, TFontStyles (), 10, "Arial", haCenter,
                    vaCenter, TfrxFrameTypes () << ftBottom,
                    ball_string (syst_ball, ball_int (syst_ball,
                    DataModule2 -> Report_Ut_DiplomFDQueryBALL_GEK -> Value), 1),
                    nom, DataModule2 -> frxReport1, 0);
                // -----
                break;
            }
            DataModule2 -> Report_Ut_DiplomFDQuery -> Next ();
        }

        // ---------------------------------------------
        // Дипломный проект выполнил на тему
        P_F (560, 454, 464, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (),
            "10. Постановление государственной экзаменационной комиссии", nom,
            DataModule2 -> frxReport1, 0);
        DataModule2 -> Report_Ut_VipFDQuery -> Close ();
        DataModule2 -> Report_Ut_VipFDQuery -> ParamByName ("NOMER") -> Value =
            DataModule2 -> Report_Ut_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Ut_VipFDQuery -> Open ();
        if (DataModule2 -> Report_Ut_VipFDQuery -> RecordCount > 0) {
            P_F (640, 472, 130, 18, TFontStyles (), 10, "Arial", haCenter,
                vaCenter, TfrxFrameTypes () << ftBottom,
                "№ " + IntToStr
                (DataModule2 -> Report_Ut_VipFDQueryN_PROTOKOL -> Value) + " от " +
                DateToStr (SQLTimeStampToDateTime
                (DataModule2 -> Report_Ut_VipFDQueryD_PROTOKOL -> Value)), nom,
                DataModule2 -> frxReport1, 0);
            AnsiString Qua =
                DataModule2 -> Report_Ut_VipFDQueryQUALIFICATION -> Value;
            AnsiString qa_n = "";
            AnsiString Str = "";
            TLocateOptions Flags;
            DataModule2 -> QalifikationFDQuery -> Open ();
            for (int i = 1; i <= Qua.Length (); i++)
            { // for цикл по квалификации
                if (Qua.SubString (i, 1) != ",") { // if Qua!=","
                    qa_n = qa_n + Qua.SubString (i, 1);
                    if (i == Qua.Length ()) { // if i==Qua
                        DataModule2 -> QalifikationFDQuery -> First ();
                        DataModule2 -> QalifikationFDQuery -> Locate ("NOMER_QU",
                            StrToInt (qa_n), Flags);

                        if (qa_n == 2)
                            Str = Str +
                                DataModule2 -> QalifikationFDQueryNAME -> Value +
                                " (" + DataModule2 -> Report_Ut_CardFDQuerySPECIAL
                                -> Value + "). ";
                        else
                            Str = Str +
                                DataModule2 -> QalifikationFDQueryNAME -> 
                                Value + ". ";

                        qa_n = "";
                    } // end if i==Qua

                } // end if Qua!=","
                else {
                    DataModule2 -> QalifikationFDQuery -> First ();
                    DataModule2 -> QalifikationFDQuery -> Locate ("NOMER_QU",
                        StrToInt (qa_n), Flags);
                    if (qa_n == 2)
                        Str = Str +
                            DataModule2 -> QalifikationFDQueryNAME -> Value + " (" +
                            DataModule2 -> Report_Ut_CardFDQuerySPECIAL -> Value
                            + "). ";
                    else
                        Str = Str +
                            DataModule2 -> QalifikationFDQueryNAME -> Value + ". ";
                    qa_n = "";
                }
            }

            if (Str.Length ())
                Str = Str.SubString (1, Str.Length () - 2);

            // вывод полученной строки о квалификации
            P_F (560, 490, 464, 28, TFontStyles (), 8, "Arial", haCenter,
                vaCenter, TfrxFrameTypes () << ftTop << ftBottom, Str, nom,
                DataModule2 -> frxReport1, 0);
            // шрифт был 10 стал 7
        }
        else {
            // пустой протокол
            P_F (640, 472, 130, 18, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haCenter, vaCenter, TfrxFrameTypes () << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
            // пустая квалификаци
            P_F (560, 474, 464, 28, TFontStyles () << fsBold << fsItalic, 10,
                "Arial", haCenter, vaCenter, TfrxFrameTypes (), "", nom,
                DataModule2 -> frxReport1, 0);
        }
        DataModule2 -> QalifikationFDQuery -> Close ();
        // Номер и дата протокола
        P_F (560, 472, 80, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (), " (протокол", nom,
            DataModule2 -> frxReport1, 0);
        // квалификация
        P_F (770, 472, 200, 18, TFontStyles () << fsBold << fsItalic, 10, "Arial",
            haLeft, vaBottom, TfrxFrameTypes (), ") присвоена квалификация: ",
            nom, DataModule2 -> frxReport1, 0);

        // ---------------------

        // Подпись декана
        P_F (640, 521, 185, 18, TFontStyles () << fsBold << fsItalic, 12, "Arial",
            haCenter, vaCenter, TfrxFrameTypes (), "Декан факультета", nom,
            DataModule2 -> frxReport1, 0);
        // 690 стал 695
        P_F (825, 521, 199, 18, TFontStyles () << fsBold << fsItalic, 12, "Arial",
            haCenter, vaCenter, TfrxFrameTypes () << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);

        // На след. запись по выбранным студентам
        if (i < DataModule2 -> Report_Ut_CardFDQuery -> RecordCount - 1) {
            TfrxReportPage * Page =
                dynamic_cast<TfrxReportPage*>
                (DataModule2 -> frxReport1 -> FindObject ("Page1"));
            // !!!frReport1 -> Pages -> Add ();    // create page
            // !!!Page=frReport1 -> Pages -> Pages[++nom];
            // !!!Page -> ChangePaper (9,255,255,255,land);
            /* Page -> PaperSize = DMPAPER_A4;
             Page -> Orientation = land; */
            DataModule2 -> Report_Ut_CardFDQuery -> Next ();
        }

    }

}

// ----------------------------------------------------------------------------
void __fastcall TStudForm::Print_To_UtCard () {
    // функция печати второй стороны учебной карточки
    TfrxReportPage * Page;
    // Добовление второй страницы
    /* TfrxReportPage * Page = dynamic_cast<TfrxReportPage*>
     (frxReport2 -> Pages[nom]); // create page */
    /* TfrxReportPage * Page;
     Page = new TfrxReportPage (frxReport4); */
    // !!!frReport1 -> Pages -> Add ();    // create page
    // !!!Page=frReport1 -> Pages -> Pages[nom];
    DataModule2 -> Report_Ut_CardFDQuery -> First ();
    for (int i = 0; i < DataModule2 -> Report_Ut_CardFDQuery -> RecordCount; i++) {
        int nom = DataModule2 -> Report_Ut_CardFDQuery -> RecordCount + i;
        Page = new TfrxReportPage (DataModule2 -> frxReport1);
        Page -> Orientation = poLandscape;
        P_F (80, 24, 1000, 20, TFontStyles () << fsBold, 14, "", haLeft, vaCenter,
            TfrxFrameTypes (), "Выполнение учебного плана: " +
            DataModule2 -> Report_Ut_CardFDQueryFAM -> Value + " " +
            DataModule2 -> Report_Ut_CardFDQueryNAME -> Value + " " +
            DataModule2 -> Report_Ut_CardFDQueryOTCH -> Value, nom,
            DataModule2 -> frxReport1, 0);

        Print_Zag_Tab_UtCard (36, "Первый", "Второй", "ПЕРВЫЙ", nom);
        Print_Zag_Tab_UtCard (540, "Третий", "Четвертый", "ВТОРОЙ", nom);
        // int k=0;
        // bool R=true; //Если R=true, то это левая сторона листа
        for (int j = 1; j <= 4; j++) {

            switch (j) {
            case 1:
                Query_UtCard (j, 76, nom);
                Print__Tab_UtCard (76, 0, nom);
                break;

            case 2:
                Query_UtCard (j, 76, nom);
                Print__Tab_UtCard (76, 289, nom);
                break;

            case 3:
                Query_UtCard (j, 580, nom);
                Print__Tab_UtCard (580, 0, nom);
                break;

            case 4:
                Query_UtCard (j, 580, nom);
                Print__Tab_UtCard (580, 289, nom);
                break;

            }

        } // for по 4 семестр

        // На след. запись по выбранным студентам
        /* if (i < DataModule2 -> Report_Ut_CardFDQuery -> RecordCount - 1) {
         TfrxReportPage * Page =
         dynamic_cast<TfrxReportPage*>
         (DataModule2 -> frxReport1 -> Pages[++nom]);
         // create page
         // !!!frReport1 -> Pages -> Add ();    // create page
         // !!!Page=frReport1 -> Pages -> Pages[++nom];
         // !!!Page -> ChangePaper (9,255,255,255,land);
         */ DataModule2 -> Report_Ut_CardFDQuery -> Next ();

    }
}
// --------------------------------------------------------------------------

void __fastcall TStudForm::Print_Zag_Tab_UtCard (int Left, AnsiString Str1,
    AnsiString Str2, AnsiString Str3, int nom) {

    // Процедура для формирования шапки таблицы

    P_F (Left, 44, 20, 72, TFontStyles () << fsBold, 10, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
        "Курс", nom, DataModule2 -> frxReport1, 90);
    P_F (Left + 20, 44, 20, 72, TFontStyles () << fsBold, 10, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
        "Семестр", nom, DataModule2 -> frxReport1, 90);
    // Page -> Objects -> Add (P_F (Left+40,44,250,72,2,10,"Arial",2+8,15,"Наименование предмета"));
    P_F (Left + 40, 44, 250, 72, TFontStyles () << fsBold, 10, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
        "Наименование предмета", nom, DataModule2 -> frxReport1, 0);
    // Page -> Objects -> Add (P_F (Left+290,44,40,72,2,8,"Arial",2+8,15,"Число часов по плану"));
    P_F (Left + 290, 44, 40, 72, TFontStyles () << fsBold, 7, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
        "Общее кол-во часов/ зач. единиц", nom, DataModule2 -> frxReport1,
        0); // Оля
    P_F (Left + 330, 44, 110, 18, TFontStyles () << fsBold, 8, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
        "Оценка", nom, DataModule2 -> frxReport1, 0);
    P_F (Left + 330, 62, 55, 54, TFontStyles () << fsBold, 8, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
        "Экзамен", nom, DataModule2 -> frxReport1, 0);
    P_F (Left + 385, 62, 55, 54, TFontStyles () << fsBold, 8, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
        "Зачет", nom, DataModule2 -> frxReport1, 0);
    P_F (Left + 440, 44, 64, 72, TFontStyles () << fsBold, 8, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
        "Дата", nom, DataModule2 -> frxReport1, 0);

    P_F (Left, 116, 20, 578, TFontStyles () << fsBold, 10, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
        Str3, nom, DataModule2 -> frxReport1, 90);
    P_F (Left + 20, 116, 20, 289, TFontStyles () << fsBold, 10, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
        Str1, nom, DataModule2 -> frxReport1, 90);
    P_F (Left + 20, 405, 20, 289, TFontStyles () << fsBold, 10, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
        Str2, nom, DataModule2 -> frxReport1, 90);
}

// --------------------------------------------------------------------------
void __fastcall TStudForm::Print__Tab_UtCard (int Left, int k, int nom) {

    for (int i = 1; i <= 17; i++) { // Названия предметов
        if (!DataModule2 -> Report_Ut_Card_PlanFDQuery -> Eof)
            P_F (Left, 116 + k, 250, 17, TFontStyles (), 6, "Arial", haLeft,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            DataModule2 -> Report_Ut_Card_PlanFDQueryNAME_OBJECT -> Value, nom,
            DataModule2 -> frxReport1, 0);

        // Определение приказав на отчисление если нет уже записей
        else
            P_F (Left, 116 + k, 250, 17, TFontStyles (), 6, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);

        // Кол-во часов по плану
        if (!DataModule2 -> Report_Ut_Card_PlanFDQuery -> Eof)
            // аудитерные часы
            // Page -> Objects -> Add (P_F (Left+250,116+k,40,17,0,7,"Arial",2+8,15,IntToStr (DataModule2 -> Report_Ut_Card_PlanCLOCK_PLAN -> Value)));
            // общее кол-во часов
                P_F (Left + 250, 116 + k, 40, 17, TFontStyles (), 7, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            IntToStr (DataModule2 -> Report_Ut_Card_PlanFDQueryCLOCK_PLAN_ALL -> 
            Value) + "/" + FloatToStr
            (DataModule2 -> Report_Ut_Card_PlanFDQueryCLOCK_PLAN -> Value), nom,
            DataModule2 -> frxReport1, 0);
        // Определение если записей нет
        else
            P_F (Left + 250, 116 + k, 40, 17, TFontStyles (), 7, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);

        // Оценка
        if (!DataModule2 -> Report_Ut_Card_PlanFDQuery -> Eof) { // if   Оценка
            // ------- кусок для системы перевода оценок
            int one;
            // временные переменные для того, чтобы оценка за зачет выносилась в другую графу
            int two;
            // временные переменные для того, чтобы оценка за зачет выносилась в другую графу   или диф.зачет
            if (DataModule2 -> Report_Ut_Card_PlanFDQueryZACH_EXAM -> Value == 1 ||
                DataModule2 -> Report_Ut_Card_PlanFDQueryZACH_EXAM -> Value == 0 ||
                DataModule2 -> Report_Ut_Card_PlanFDQueryZACH_EXAM -> Value == 3)
            { // if это зачет
                one = Left + 345;
                // для зачета в эту ячейку  заносится "зачтено"
                two = Left + 290;
                // для зачета в эту ячейку ничего не  заносится
            } // end if это зачет
            if (DataModule2 -> Report_Ut_Card_PlanFDQueryZACH_EXAM -> Value == 2)
            { // if это экзамен
                two = Left + 345;
                // для экзамена в эту ячейку ничего не  заносится
                one = Left + 290; // для экзамена в эту ячейку  заносится оценка
            } // end if это экзамен или диф.зачет

            // ----первая строка заносит пробел в ячейку
            // ----вторая строка заносит результат экзамена, диф. зачета или зачета из процедуры на  DataModule1
            // ----syst_ball - это глобальная переменная, определяется перед выполнением учебный карточки и означает систему оценок
            P_F (two, 116 + k, 55, 17, TFontStyles (), 7, "Arial", haCenter,
                vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
            // Page -> Objects -> Add (P_F (one,116+k,55,17,0,7,"Arial",2+8,15,ball_string (syst_ball, ball_int (syst_ball, DataModule2 -> Report_Ut_Card_PlanRESULT -> Value),0)));

            if (DataModule2 -> Report_Ut_Card_PlanFDQuerySPECKURS -> Value == 4 ||
                DataModule2 -> Report_Ut_Card_PlanFDQuerySPECKURS -> Value == 5) {
                if (ball_string (syst_ball, ball_int (syst_ball,
                    DataModule2 -> Report_Ut_Card_PlanFDQueryRESULT -> Value),
                    1) == "прослушан")
                    P_F (one, 116 + k, 55, 17, TFontStyles (), 7, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "прослушан", nom, DataModule2 -> frxReport1, 0);
                // Было прослушан
                else
                    P_F (one, 116 + k, 55, 17, TFontStyles (), 7, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    ball_string (syst_ball, ball_int (syst_ball,
                    DataModule2 -> Report_Ut_Card_PlanFDQueryRESULT -> Value), 1),
                    nom, DataModule2 -> frxReport1, 0);
            }
            else
                P_F (one, 116 + k, 55, 17, TFontStyles (), 7, "Arial", haCenter,
                vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                ball_string (syst_ball, ball_int (syst_ball,
                DataModule2 -> Report_Ut_Card_PlanFDQueryRESULT -> Value), 1), nom,
                DataModule2 -> frxReport1, 0);
            // -----------------------------------------------
            /* if ( (DataModule2 -> Report_Ut_Card_PlanZACH_EXAM -> Value==1)|| (DataModule2 -> Report_Ut_Card_PlanZACH_EXAM -> Value==2))
             {
             switch (DataModule2 -> Report_Ut_Card_PlanRESULT -> Value)
             {
             case 1: Page -> Objects -> Add (P_F (Left+345,116+k,55,17,0,7,"Arial",2+8,15,"зачтено"));
             Page -> Objects -> Add (P_F (Left+290,116+k,55,17,0,7,"Arial",2,15,""));
             break;
             case 3: Page -> Objects -> Add (P_F (Left+345,116+k,55,17,0,7,"Arial",2,15,""));
             Page -> Objects -> Add (P_F (Left+290,116+k,55,17,0,7,"Arial",2+8,15,"удовл."));
             break;
             case 4: Page -> Objects -> Add (P_F (Left+345,116+k,55,17,0,7,"Arial",2,15,""));
             Page -> Objects -> Add (P_F (Left+290,116+k,55,17,0,7,"Arial",2+8,15,"хор."));
             break;
             case 5: Page -> Objects -> Add (P_F (Left+345,116+k,55,17,0,7,"Arial",2,15,""));
             Page -> Objects -> Add (P_F (Left+290,116+k,55,17,0,7,"Arial",2+8,15,"отл."));
             break;
             case 7: Page -> Objects -> Add (P_F (Left+345,116+k,55,17,0,7,"Arial",2,15,""));
             Page -> Objects -> Add (P_F (Left+290,116+k,55,17,0,7,"Arial",2+8,15,"осв."));
             break;
             }  //switch
             } //if */
            /* if ( (DataModule2 -> Report_Ut_Card_PlanZACH_EXAM -> Value==3))
             {
             switch (DataModule2 -> Report_Ut_Card_PlanRESULT -> Value)
             {
             case 3: Page -> Objects -> Add (P_F (Left+345,116+k,55,17,0,7,"Arial",2,15,""));
             Page -> Objects -> Add (P_F (Left+290,116+k,55,17,0,7,"Arial",2+8,15,"удовл."));
             break;
             case 4: Page -> Objects -> Add (P_F (Left+345,116+k,55,17,0,7,"Arial",2,15,""));
             Page -> Objects -> Add (P_F (Left+290,116+k,55,17,0,7,"Arial",2+8,15,"хор."));
             break;
             case 5: Page -> Objects -> Add (P_F (Left+345,116+k,55,17,0,7,"Arial",2,15,""));
             Page -> Objects -> Add (P_F (Left+290,116+k,55,17,0,7,"Arial",2+8,15,"отл."));
             break;
             case 7: Page -> Objects -> Add (P_F (Left+345,116+k,55,17,0,7,"Arial",2,15,""));
             Page -> Objects -> Add (P_F (Left+290,116+k,55,17,0,7,"Arial",2+8,15,"осв."));
             break;

             }  //switch
             } //DataModule2 -> Report_Ut_Card_PlanZACH_EXAM -> Value==3 */

        } // end if  Оценка

        // Определение если записей нет
        else { // else
            P_F (Left + 290, 116 + k, 55, 17, TFontStyles (), 7, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
            P_F (Left + 345, 116 + k, 55, 17, TFontStyles (), 7, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
        } // end else

        // Дата
        if (!DataModule2 -> Report_Ut_Card_PlanFDQuery -> Eof) { // if Дата
            if (DataModule2 -> Report_Ut_Card_PlanFDQuerySTATUS_RESULT -> Value > 3)
            { // if  1,2,3 - основная (1), экз.лист или дополнительная (2), досрочная (3)
                // 4,5,6,7,8 - перезачеты разного рода
                AnsiString data_perezach = "";
                switch (DataModule2 -> Report_Ut_Card_PlanFDQuerySTATUS_RESULT -> 
                    Value) { // switch
                case 4:
                    data_perezach = "ликвидация разницы";
                    break;
                case 5:
                    data_perezach = "перезачет д/о-з/о";
                    break;
                case 6:
                    data_perezach = "перезачет 2-ое в/о";
                    break;
                case 7:
                    data_perezach = "перезачет др. ВУЗ";
                    break;
                case 8:
                    data_perezach = "перезачет РУОР";
                    break;
                case 9:
                    data_perezach = "перезачет др.фак-т";
                    break;
                case 10:
                    data_perezach = "перезачет ПедКолледж";
                    break;
                case 11:
                    data_perezach = "пересдача";
                    break;
                case 12:
                    data_perezach = "после ИПК,МКП";
                    break;
                } // end switch
                P_F (Left + 400, 116 + k, 64, 17, TFontStyles (), 5, "Arial",
                    haCenter, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    data_perezach, nom, DataModule2 -> frxReport1, 0);
            }
            else
                P_F (Left + 400, 116 + k, 64, 17, TFontStyles (), 7, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                DateToStr (SQLTimeStampToDateTime
                (DataModule2 -> Report_Ut_Card_PlanFDQueryDATE_RESULT -> Value)),
                nom, DataModule2 -> frxReport1, 0);
        } // end if Дата
        // Определение если записей нет
        else
            P_F (Left + 400, 116 + k, 64, 17, TFontStyles (), 7, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);

        // Формирование след. строки
        k = k + 17;
        // На следующую запись по предмету
        if (!DataModule2 -> Report_Ut_Card_PlanFDQuery -> Eof)
            DataModule2 -> Report_Ut_Card_PlanFDQuery -> Next ();
    } // for
    // Линия   жирная
    // TfrxLineView *Line1 = dynamic_cast <TfrxLineView *> (DataModule2 -> frxReport1 -> FindObject ("Line1"));
    TfrxLineView *Line1;
    Line1 = new TfrxLineView (Page);
    Line1 -> SetBounds (Left - 20, 404, 484, 6);
    Line1 -> Width = 2, 00;
    // Page -> Objects -> Add (Line1);
}

// ------------------------------------------------------------------------------
void __fastcall TStudForm::Query_UtCard (int Sem, int Left, int nom) {
    DataModule2 -> Report_Ut_Card_PlanFDQuery -> Close ();
    DataModule2 -> Report_Ut_Card_PlanFDQuery -> SQL -> Clear ();
    if (DataModule2 -> Report_Ut_CardFDQuerySTATUS_PEOPLE -> Value == 2 ||
        CheckBox6 -> Checked)
    { // if если студент отчислен, то показывать все оценки для обоих видов обучения
        DataModule2 -> Report_Ut_Card_PlanFDQuery -> SQL -> Add ("\
             SELECT Result_ball.NOMER, Result_ball.N_PLAN, Result_ball.RESULT, \
             Result_ball.DATE_RESULT, Result_ball.STATUS_RESULT, Edu_plan.SEMESTR, Edu_plan.CLOCK_PLAN,Edu_plan.CLOCK_PLAN_ALL, \
             Edu_plan.YEAR_PLAN, Edu_plan.ZACH_EXAM, Edu_plan.VID_EDU_PLAN, \
             Object_plan.NAME_OBJECT, Faculty.FAC1, Edu_plan.N_FAC, Edu_plan.SPECKURS  \
             FROM RESULT_BALL Result_ball    INNER JOIN EDU_PLAN Edu_plan \
             ON  (Result_ball.N_PLAN = Edu_plan.N_PLAN)INNER JOIN OBJECT_PLAN Object_plan \
             ON  (Edu_plan.N_OBJECT = Object_plan.N_OBJECT) INNER JOIN FACULTY Faculty \
             ON  (Edu_plan.N_FAC = Faculty.N_FAC) \
             Where  Result_ball.NOMER=:NOMER \
               and  Edu_plan.SEMESTR=:SEMESTR \
               and (Edu_plan.VID_EDU_PLAN IN (0, 1)) \
             ORDER by Edu_plan.ZACH_EXAM,  Object_plan.NAME_OBJECT");

    } // end if если студент отчислен, то показывать все оценки для обоих видов обучения
    else { // else для действующих студентов
        DataModule2 -> Report_Ut_Card_PlanFDQuery -> SQL -> Add ("\
             SELECT Result_ball.NOMER, Result_ball.N_PLAN, Result_ball.RESULT, \
             Result_ball.DATE_RESULT, Result_ball.STATUS_RESULT,  Edu_plan.SEMESTR, Edu_plan.CLOCK_PLAN, Edu_plan.CLOCK_PLAN_ALL,  \
             Edu_plan.YEAR_PLAN, Edu_plan.ZACH_EXAM, Edu_plan.VID_EDU_PLAN, \
             Object_plan.NAME_OBJECT, Faculty.FAC1, Edu_plan.N_FAC, Edu_plan.SPECKURS \
             FROM RESULT_BALL Result_ball    INNER JOIN EDU_PLAN Edu_plan \
             ON  (Result_ball.N_PLAN = Edu_plan.N_PLAN)INNER JOIN OBJECT_PLAN Object_plan \
             ON  (Edu_plan.N_OBJECT = Object_plan.N_OBJECT) INNER JOIN FACULTY Faculty \
             ON  (Edu_plan.N_FAC = Faculty.N_FAC) \
             Where  Result_ball.NOMER=:NOMER \
               and  Edu_plan.SEMESTR=:SEMESTR \
               and (Edu_plan.VID_EDU_PLAN=:EDU) \
               and (Edu_plan.N_FAC=:FAC) \
             ORDER by Edu_plan.ZACH_EXAM,  Object_plan.NAME_OBJECT");
        DataModule2 -> Report_Ut_Card_PlanFDQuery -> ParamByName ("EDU") -> AsString =
            IntToStr (DataModule2 -> Report_Ut_CardFDQueryVID_EDU -> Value);
        DataModule2 -> Report_Ut_Card_PlanFDQuery -> ParamByName ("FAC") -> AsInteger =
            nom_fac;
    } // else для действующих студентов

    DataModule2 -> Report_Ut_Card_PlanFDQuery -> ParamByName ("NOMER") -> Value =
        DataModule2 -> Report_Ut_CardFDQueryNOMER -> Value;
    DataModule2 -> Report_Ut_Card_PlanFDQuery -> ParamByName ("SEMESTR")
        -> Value = Sem;

    DataModule2 -> Report_Ut_Card_PlanFDQuery -> Open ();
    int a = Sem % 2;
    if ( ( (a == 0) && (Sem != 12) &&
        (DataModule2 -> Report_Ut_CardFDQueryVID_EDU -> Value == 1)) ||
        ( (a == 0) && (Sem != 8) &&
        (DataModule2 -> Report_Ut_CardFDQueryVID_EDU -> Value == 0))) {
        // Приказ о переводе на j курс
        DataModule2 -> Report_Prikaz_KursFDQuery -> Close ();
        DataModule2 -> Report_Prikaz_KursFDQuery -> ParamByName ("NOMER") -> Value =
            DataModule2 -> Report_Ut_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Prikaz_KursFDQuery -> ParamByName ("N_KURS") -> Value =
            (Sem / 2) + 1;
        DataModule2 -> Report_Prikaz_KursFDQuery -> Open ();
        P_F (Left, 694, 250, 18, TFontStyles (), 10, "Arial", haCenter, vaCenter,
            TfrxFrameTypes (), "Отметка о переводе на  " +
            IntToStr ( (Sem / 2) + 1) + "  курс. Приказ", nom,
            DataModule2 -> frxReport1, 0);
        if (!DataModule2 -> Report_Prikaz_KursFDQuery -> Eof) {
            P_F (Left + 250, 694, 60, 18, TFontStyles (), 10, "Arial", haLeft,
                vaCenter, TfrxFrameTypes () << ftBottom,
                "№" + IntToStr
                (DataModule2 -> Report_Prikaz_KursFDQueryN_PRIKAZ_KURS -> Value),
                nom, DataModule2 -> frxReport1, 0);
            P_F (Left + 310, 694, 20, 18, TFontStyles (), 10, "Arial", haCenter,
                vaCenter, TfrxFrameTypes (), "от", nom,
                DataModule2 -> frxReport1, 0);
            P_F (Left + 330, 694, 100, 18, TFontStyles (), 10, "Arial", haCenter,
                vaCenter, TfrxFrameTypes () << ftBottom,
                SQLTimeStampToDateTime (DataModule2 -> 
                Report_Prikaz_KursFDQueryD_PRIKAZ_KURS -> Value).DateString (),
                nom, DataModule2 -> frxReport1, 0);

        }
        else {
            P_F (Left + 250, 694, 40, 18, TFontStyles (), 10, "Arial", haLeft,
                vaCenter, TfrxFrameTypes () << ftBottom, "№", nom,
                DataModule2 -> frxReport1, 0);
            P_F (Left + 310, 694, 20, 18, TFontStyles (), 10, "Arial", haCenter,
                vaCenter, TfrxFrameTypes (), "от", nom,
                DataModule2 -> frxReport1, 0);
            P_F (Left + 330, 694, 100, 18, TFontStyles (), 10, "Arial", haCenter,
                vaCenter, TfrxFrameTypes () << ftBottom, "", nom,
                DataModule2 -> frxReport1, 0);
        }
    } // if a==0
    // Приказ о выпуске
    if ( ( (Sem == 12) && (DataModule2 -> Report_Ut_CardFDQueryVID_EDU -> Value == 1))
        || ( (Sem == 8) &&
        (DataModule2 -> Report_Ut_CardFDQueryVID_EDU -> Value == 0))) {
        // Приказ о выпуске
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Close ();
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("NOMER")
            -> Value = DataModule2 -> Report_Ut_CardFDQueryNOMER -> Value;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> ParamByName ("TYPE")
            -> Value = 9;
        DataModule2 -> Report_Ut_Public_PrikazFDQuery -> Open ();
        P_F (Left, 694, 150, 18, TFontStyles (), 10, "Arial", haCenter, vaCenter,
            TfrxFrameTypes (), "Приказ о выпуске ", nom,
            DataModule2 -> frxReport1, 0);
        if (DataModule2 -> Report_Ut_Public_PrikazFDQuery -> RecordCount != 0) {
            P_F (Left + 150, 694, 60, 18, TFontStyles (), 10, "Arial", haLeft,
                vaCenter, TfrxFrameTypes () << ftBottom,
                "№ " + IntToStr
                (DataModule2 -> Report_Ut_Public_PrikazFDQueryN_PUBLIC_PRIKAZ -> 
                Value), nom, DataModule2 -> frxReport1, 0);
            P_F (Left + 230, 694, 100, 18, TFontStyles (), 10, "Arial", haCenter,
                vaCenter, TfrxFrameTypes () << ftBottom,
                DateToStr (SQLTimeStampToDateTime
                (DataModule2 -> Report_Ut_Public_PrikazFDQueryD_PUBLIC_PRIKAZ -> 
                Value)), nom, DataModule2 -> frxReport1, 0);
        }
        else {
            P_F (Left + 150, 694, 60, 18, TFontStyles (), 10, "Arial", haLeft,
                vaCenter, TfrxFrameTypes () << ftBottom, "№ ", nom,
                DataModule2 -> frxReport1, 0);
            P_F (Left + 230, 694, 100, 18, TFontStyles (), 10, "Arial", haCenter,
                vaCenter, TfrxFrameTypes () << ftBottom, "", nom,
                DataModule2 -> frxReport1, 0);
        }
        P_F (Left + 210, 694, 20, 18, TFontStyles (), 10, "Arial", haCenter,
            vaCenter, TfrxFrameTypes (), "от ", nom, DataModule2 -> frxReport1, 0);

        P_F (Left + 150, 712, 70, 18, TFontStyles () << fsBold << fsItalic, 10,
            "Arial", haCenter, vaCenter, TfrxFrameTypes (), "Декан", nom,
            DataModule2 -> frxReport1, 0);
        P_F (Left + 220, 712, 120, 18, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter, TfrxFrameTypes () << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);
    }

}

// ------------------------------------------------------------------------------
void __fastcall TStudForm::Print_Three_UtCard () {
    // функция печати третьей стороны учебной карточки
    TfrxReportPage * Page;
    // Добовление второй страницы
    /* TfrxReportPage * Page = dynamic_cast<TfrxReportPage*>
     (frxReport2 -> Pages[nom]); */ // create page
    // !!!frReport1 -> Pages -> Add ();    // create page
    // !!!Page=frReport1 -> Pages -> Pages[nom];
    /* !!!    TPrinterOrientation land;
     land = poLandscape;
     Page -> ChangePaper (9,255,255,255,land);
     Page -> PaperSize = DMPAPER_A4;
     Page -> Orientation = land; */ DataModule2 -> Report_Ut_CardFDQuery -> First ();
    for (int i = 0; i < DataModule2 -> Report_Ut_CardFDQuery -> RecordCount; i++) {
        int nom = DataModule2 -> Report_Ut_CardFDQuery -> RecordCount * 2 + i;
        Page = new TfrxReportPage (DataModule2 -> frxReport1);
        Page -> Orientation = poLandscape;
        P_F (80, 24, 1000, 20, TFontStyles () << fsBold, 14, "", haLeft, vaCenter,
            TfrxFrameTypes (), "Выполнение учебного плана: " +
            DataModule2 -> Report_Ut_CardFDQueryFAM -> Value + " " +
            DataModule2 -> Report_Ut_CardFDQueryNAME -> Value + " " +
            DataModule2 -> Report_Ut_CardFDQueryOTCH -> Value, nom,
            DataModule2 -> frxReport1, 0);
        Print_Zag_Tab_UtCard (36, "Пятый", "Шестой", "ТРЕТИЙ", nom);
        Print_Zag_Tab_UtCard (540, "Седьмой", "Восьмой", "ЧЕТВЕРТЫЙ", nom);
        // int k=0;
        // bool R=true; //Если R=true, то это левая сторона листа
        for (int j = 5; j <= 8; j++) {

            switch (j) {
            case 5:
                Query_UtCard (j, 76, nom);
                Print__Tab_UtCard (76, 0, nom);
                break;

            case 6:
                Query_UtCard (j, 76, nom);
                Print__Tab_UtCard (76, 289, nom);
                break;

            case 7:
                Query_UtCard (j, 580, nom);
                Print__Tab_UtCard (580, 0, nom);
                break;

            case 8:
                Query_UtCard (j, 580, nom);
                Print__Tab_UtCard (580, 289, nom);
                break;

            }

        } // for по 8 семестр

        // На след. запись по выбранным студентам
        /* if (i < DataModule2 -> Report_Ut_CardFDQuery -> RecordCount - 1) {
         TfrxReportPage * Page =
         dynamic_cast<TfrxReportPage*>
         (DataModule2 -> frxReport1 -> Pages[++nom]);
         // create page
         // !!!frReport1 -> Pages -> Add ();    // create page
         // !!!Page=frReport1 -> Pages -> Pages[++nom];
         // !!!Page -> ChangePaper (9,255,255,255,land);
         Page -> PaperSize = DMPAPER_A4;
         Page -> Orientation = land; */
        DataModule2 -> Report_Ut_CardFDQuery -> Next ();

    }

}

// ------------------------------------------------------------------------------
void __fastcall TStudForm::Print_Four_UtCard () {
    // функция печати второй стороны учебной карточки
    TfrxReportPage * Page;
    // DataModule2 -> frxReport1 -> Clear ();
    // Добовление второй страницы
    /* TfrxReportPage * Page = dynamic_cast<TfrxReportPage*>
     (DataModule2 -> frxReport1 -> Pages[nom]); */ // create page
    // !!!frReport1 -> Pages -> Add ();    // create page
    // !!!Page=frReport1 -> Pages -> Pages[nom];
    /* TPrinterOrientation land;
     land = poLandscape;
     // !!!Page -> ChangePaper (9,255,255,255,land);
     Page -> PaperSize = DMPAPER_A4;
     Page -> Orientation = land; */ DataModule2 -> Report_Ut_CardFDQuery -> First ();
    for (int i = 0; i < DataModule2 -> Report_Ut_CardFDQuery -> RecordCount; i++) {
        int nom = DataModule2 -> Report_Ut_CardFDQuery -> RecordCount * 3 + i;
        Page = new TfrxReportPage (DataModule2 -> frxReport1);
        Page -> Orientation = poLandscape;
        P_F (80, 24, 1000, 20, TFontStyles () << fsBold, 14, "", haLeft, vaCenter,
            TfrxFrameTypes (), "Выполнение учебного плана: " +
            DataModule2 -> Report_Ut_CardFDQueryFAM -> Value + " " +
            DataModule2 -> Report_Ut_CardFDQueryNAME -> Value + " " +
            DataModule2 -> Report_Ut_CardFDQueryOTCH -> Value, nom,
            DataModule2 -> frxReport1, 0);
        Print_Zag_Tab_UtCard (36, "Девятый", "Десятый", "ПЯТЫЙ", nom);
        Print_Zag_Tab_UtCard (540, "Одиннадцатый", "Двенадцатый", "ШЕСТОЙ", nom);

        for (int j = 9; j <= 12; j++) {

            switch (j) {
            case 9:
                Query_UtCard (j, 76, nom);
                Print__Tab_UtCard (76, 0, nom);
                break;

            case 10:
                Query_UtCard (j, 76, nom);
                Print__Tab_UtCard (76, 289, nom);
                break;

            case 11:
                Query_UtCard (j, 580, nom);
                Print__Tab_UtCard (580, 0, nom);
                break;

            case 12:
                Query_UtCard (j, 580, nom);
                Print__Tab_UtCard (580, 289, nom);
                break;

            }

        } // for по 12 семестр
        // На след. запись по выбранным студентам
        /* if (i < DataModule2 -> Report_Ut_CardFDQuery -> RecordCount - 1) {
         TfrxReportPage * Page =
         dynamic_cast<TfrxReportPage*>
         (DataModule2 -> frxReport1 -> Pages[++nom]);
         // create page
         // !!!frReport1 -> Pages -> Add ();    // create page
         // !!!Page=frReport1 -> Pages -> Pages[++nom];
         // !!!Page -> ChangePaper (9,255,255,255,land);
         // Page -> PaperSize = DMPAPER_A4;
         // Page -> Orientation = land; */
        DataModule2 -> Report_Ut_CardFDQuery -> Next ();

    }
}

// ---------------------------------------------------------------------------
void __fastcall TStudForm::ComboBox5Change (TObject * Sender) {
    if (DataModule1 -> PeopleFDQuery -> State != dsInsert) {
        DataModule1 -> PeopleFDQuery -> Edit ();
        DataModule1 -> PeopleFDQueryVID_EDU_INCLUDE -> Value = ComboBox5 -> ItemIndex;
    }
}

// ---------------------------------------------------------------------------
void __fastcall TStudForm::FormCanResize (TObject * Sender, int &NewWidth,
    int &NewHeight, bool &Resize) {
    if (StudForm != NULL) {
        Button1 -> Top = StudForm -> Height - 77;
        Button2 -> Top = StudForm -> Height - 77;
    }

}

// ---------------------------------------------------------------------------
void __fastcall TStudForm::DBGrid1TitleClick (TColumn * Column) {
    AnsiString s = DataModule1 -> PeopleFDQuery -> SQL -> Text;

    int p = s.Pos ("ORDER");
    s.SetLength (p - 1);
    AnsiString sql_hvost = "";

    switch (Column -> Index) { // switch
    case 5: // SPECIALIZ1
        sql_hvost =
            " ORDER BY  People.N_SPECIALIZ, People.NAME, People.FAM, People.OTCH";
        break;
    case 4: // VID_EDU1
        sql_hvost =
            " ORDER BY People.VID_EDU, People.FAM, People.NAME, People.OTCH";
        break;
    case 3: // OTCH
        sql_hvost = " ORDER BY People.OTCH, People.FAM, People.NAME";
        break;
    case 2: // NAME
        sql_hvost = " ORDER BY People.NAME, People.FAM, People.OTCH";
        break;
    case 1: // FAM
        sql_hvost = " ORDER BY People.FAM, People.NAME, People.OTCH";
        break;
    case 0: // N_GROUP
        sql_hvost =
            " ORDER BY People.N_GROUP, People.FAM, People.NAME, People.OTCH";
        break;
    } // end switch

    DataModule1 -> PeopleFDQuery -> Close ();
    DataModule1 -> PeopleFDQuery -> SQL -> Clear ();
    DataModule1 -> PeopleFDQuery -> SQL -> Add (s + sql_hvost);
    DataModule1 -> PeopleFDQuery -> Open ();
}

// ---------------------------------------------------------------------------
void __fastcall TStudForm::ApplicationEvents1Message (tagMSG & Msg,
    bool &Handled) {
    // организовать нормальную работу мышиного колесика в DBGrid

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
void __fastcall TStudForm::SpeedButton1Click (TObject * Sender)
{ // вызов формы PasportForm
    status_people_query = 0;
    DataModule1 -> PasportFDQ -> Close ();
    DataModule1 -> PasportFDQ -> Params -> Items[0] -> AsInteger =
        DataModule1 -> PeopleFDQueryNOMER -> Value;
    DataModule1 -> PasportFDQ -> Open ();

    int nom = DataModule1 -> PeopleFDQueryNOMER -> Value;
    Variant pasport = DataModule1 -> PasportFDQ -> Lookup ("NOMER", nom, "NOMER");

    if (!pasport.IsNull ()) { // if паспорт есть
        est_pas = true;
        PasportForm = new TPasportForm (this); // Создание формы
        PasportForm -> Panel2 -> Visible = false;
        PasportForm -> Panel1 -> Visible = true;
        PasportForm -> ShowModal ();
    } // end if паспорт есть
    else { // else паспорта нет предлагаю добавить
        // !!!if (Application -> MessageBox ("У студента нет паспорта!Добавить?", "", MB_YESNO) == mrYes)
        if (MessageDlg ("У студента нет паспорта!Добавить?", mtConfirmation,
            TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes) {
            est_pas = false;
            PasportForm = new TPasportForm (this);
            // Создание формы
            PasportForm -> Panel2 -> Visible = true;
            PasportForm -> Panel1 -> Visible = false;
            // PasportForm -> DBLookupComboBox1 -> KeyValue=1;
            PasportForm -> ShowModal ();
        }
    } // end else паспорта нет предлагаю добавить
} // end вызов формы PasportForm

// ---------------------------------------------------------------------------
void __fastcall TStudForm::DBEdit28Enter (TObject * Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> ShowModal ();
    try {
        DataModule1 -> PeopleFDQuery -> Edit ();
    }
    catch (...) {
        DataModule1 -> PeopleFDQuery -> Insert ();
    }
    if (calendar)
        DataModule1 -> PeopleFDQuery -> FieldValues["D_PRIKAZ_INCLUDE"] =
            cal_date.DateString ();
    // StudForm -> DBLookupComboBox1 -> SetFocus ();
    StudForm -> DBEdit7 -> SetFocus ();
}

// ---------------------------------------------------------------------------
void __fastcall TStudForm::DBLookupComboBox6CloseUp (TObject *Sender) {
    /* if (region_id != DBLookupComboBox6 -> KeyValue && DBLookupComboBox6 -> KeyValue != NULL) {
     AdressForm -> DistrictDBLkCmbBx -> KeyValue = 0;
     AdressForm -> Type_localityDBLkCmbBx -> KeyValue = 0;
     AdressForm -> LocalityDBLkCmbBx -> KeyValue = 0;
     AdressForm -> Type_streetDBLkCmbBx -> KeyValue = 0;
     AdressForm -> StreetDBLkCmbBx -> KeyValue = 0;
     } */
    // up_reg = true;
    if (!DBLookupComboBox6 -> KeyValue.IsNull ()) {
        if (region_id == 8) {
            StudForm -> DBEdit18 -> ReadOnly = false;
            StudForm -> DBEdit19 -> ReadOnly = false;
        }
        else {
            StudForm -> DBEdit18 -> ReadOnly = true;
            StudForm -> DBEdit19 -> ReadOnly = true;
            AdressForm = new TAdressForm (this);
            if (region_id == 5) {
                AdressForm -> Label48 -> Visible = false;
                AdressForm -> Label51 -> Visible = false;
                AdressForm -> Label54 -> Visible = false;
                AdressForm -> DistrictDBLkCmbBx -> Visible = false;
                AdressForm -> Type_localityDBLkCmbBx -> Visible = false;
                AdressForm -> LocalityDBLkCmbBx -> Visible = false;
                DataModule1 -> QType_street -> Close ();
                DataModule1 -> QType_street -> Open ();
                AdressForm -> Type_streetDBLkCmbBx -> KeyValue = 1;
            }
            else {
                AdressForm -> Label48 -> Visible = true;
                AdressForm -> Label51 -> Visible = true;
                AdressForm -> Label54 -> Visible = true;
                AdressForm -> DistrictDBLkCmbBx -> Visible = true;
                AdressForm -> Type_localityDBLkCmbBx -> Visible = true;
                AdressForm -> LocalityDBLkCmbBx -> Visible = true;
                DataModule1 -> QDistrict -> Close ();
                DataModule1 -> QDistrict -> ParamByName ("REGION") -> AsInteger =
                    DataModule1 -> RegionFDTableN_REGION -> Value;
                // StudForm -> DBLookupComboBox6 -> KeyValue;
                DataModule1 -> QDistrict -> Open ();
                if (DataModule1 -> PeopleFDQuery -> State == dsInsert) {
                    AdressForm -> DistrictDBLkCmbBx -> KeyValue = -1;
                }
            }
            AdressForm -> ShowModal ();
            if (AdressForm -> AdressSave) {
                if (DataModule1 -> PeopleFDQuery -> State == dsInsert) {
                    StudForm -> DBEdit18 -> Text = AdressForm -> Adress;
                }
                StudForm -> DBEdit19 -> Text = AdressForm -> Adress;
            }
        }
    }
}

// ---------------------------------------------------------------------------
void __fastcall TStudForm::DBLookupComboBox6MouseDown (TObject *Sender,
    TMouseButton Button, TShiftState Shift, int X, int Y) {
    if (!DBLookupComboBox6 -> KeyValue.IsNull ()) {
        region_id = DBLookupComboBox6 -> KeyValue;
    }

}
// ---------------------------------------------------------------------------



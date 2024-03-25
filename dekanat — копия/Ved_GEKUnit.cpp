// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Ved_GEKUnit.h"
#include "CalendarUnit.h"
#include "DM3Unit.h"
#include "DataModule.h"
#include "DataModule_Card.h"
#include "ADD_Ved_GEKUnit.h"
#include "MainUnit.h"
#include "DualList.h"
// #include "Och_GEK.h"
// ---------------------------------------------------------------------------
#pragma package (smart_init)
#pragma link "frxClass"
// !!!#pragma link "MyList"
#pragma resource "*.dfm"
TVed_GEK *Ved_GEK;
// ----Переменные для печати экзаменационной ведомости на Гос.
TfrxReportPage *PageGEK;
int *Nomer; // массив номеров
bool sport;
// переменная для определения надо ли печатать разряд в очередности true - надо спортивный разряд
int Count_OutList; // переменная для определения количества выбранных студентов

// ---------------------------------------------------------------------------
__fastcall TVed_GEK::TVed_GEK (TComponent* Owner) : TForm (Owner) {
}

// ---------------------------------------------------------------------------
bool __fastcall TVed_GEK::Open_S (bool p) { // функция, открытия SQL
    // bool p -параметр, определяющий включен ли выбор за период

    AnsiString s1 = "SELECT VEDOMOST_GEK.N_VED, VEDOMOST_GEK.N_VEDOMOST, VEDOMOST_GEK.D_VED, \
  VEDOMOST_GEK.FIO_EXAM, VEDOMOST_GEK.N_PLAN, VEDOMOST_GEK.N_FAC,  \
  VEDOMOST_GEK.INC_GROUP, VEDOMOST_GEK.N_GROUP_SP, \
  EDU_PLAN.N_OBJECT, OBJECT_PLAN.NAME_OBJECT, EDU_PLAN.VID_EDU_PLAN  \
FROM  VEDOMOST_GEK  \
   left JOIN EDU_PLAN  ON (VEDOMOST_GEK.N_PLAN=EDU_PLAN.N_PLAN) \
   inner JOIN OBJECT_PLAN ON (EDU_PLAN.N_OBJECT=OBJECT_PLAN.N_OBJECT) ";

    AnsiString s2 = "WHERE (VEDOMOST_GEK.N_FAC = :N_FAC and  EDU_PLAN.YEAR_PLAN=:YEAR_PLAN) \
               ORDER BY VEDOMOST_GEK.N_VEDOMOST";

    AnsiString s3 = "WHERE (VEDOMOST_GEK.N_FAC = :N_FAC and  vedomost_gek.d_ved between :D1 and :D2) \
               ORDER BY VEDOMOST_GEK.N_VEDOMOST";

    DM3 -> VED_GEKGridFDQuery -> Close ();
    DM3 -> VED_GEKGridFDQuery -> SQL -> Clear ();
    DM3 -> VED_GEKGridFDQuery -> SQL -> Add (s1);
    if (p) {
        if (Edit1 -> Text == "" || Edit2 -> Text == "") {
            ShowMessage ("Укажите период с... и по...");
            return false;
        }
        DM3 -> VED_GEKGridFDQuery -> SQL -> Add (s3);
        DM3 -> VED_GEKGridFDQuery -> ParamByName ("D1") -> Value = Edit1 -> Text;
        DM3 -> VED_GEKGridFDQuery -> ParamByName ("D2") -> Value = Edit2 -> Text;
    }
    else {
        DM3 -> VED_GEKGridFDQuery -> SQL -> Add (s2);
        DM3 -> VED_GEKGridFDQuery -> ParamByName ("YEAR_PLAN") -> Value = uch_god;
    }

    DM3 -> VED_GEKGridFDQuery -> ParamByName ("N_FAC") -> Value = nom_fac;
    DM3 -> VED_GEKGridFDQuery -> Open ();
    DM3 -> VED_GEKGridFDQuery -> Last ();
    if (DM3 -> VED_GEKGridFDQuery -> State)
        return true;
    else
        return false;
}

// ----------------------------------------------------------------------------
AnsiString TVed_GEK::Text_predmet_GOS (AnsiString predmet, int specializ,
    bool G_P)
{ // процедура для изменения текста предмета для нужной специализации (Для  ГОС-ов)
    // AnsiString predmet  - текст предмета на ГОС
    // int specializ   - номер специализации
    // bool G_P      - определяем ГОС (true), очередность (false)

    // --запоминаем старый SQL для того, чтобы его вернуть
    AnsiString Old_SQL = "SELECT n_specializ, special,  SPECIAL_SKLON, N_SPEC, SPECIAL_DIRECTION FROM specializ \
                    where (n_fac=:FAC) \
                    order by special";

    // --------выполняем Query с новым SQL выборка по факультету и номеру специализации
    DataModule1 -> SpecializFDQuery -> Close ();
    DataModule1 -> SpecializFDQuery -> SQL -> Clear ();
    DataModule1 -> SpecializFDQuery -> SQL -> Add ("SELECT n_specializ, special, SPECIAL_SKLON, N_SPEC, SPECIAL_DIRECTION  FROM specializ \
                                           where (n_fac=:FAC) and (n_specializ=:SP) \
                                           order by special");
    DataModule1 -> SpecializFDQuery -> ParamByName ("FAC") -> AsInteger = nom_fac;
    DataModule1 -> SpecializFDQuery -> ParamByName ("SP") -> AsInteger = specializ;
    DataModule1 -> SpecializFDQuery -> Open ();

    int N_spec = DataModule1 -> SpecializFDQueryN_SPEC -> Value;
    // номер специальности
    AnsiString Name_special = DataModule1 -> SpecializFDQuerySPECIAL_SKLON -> Value;
    // название специализации

    // -******* предмет ГОС по специализации

    if (predmet == "ГОС по специализации") { // if  ГОС по специализации

        if ( (N_spec == 1 || N_spec == 6) &&
            (specializ != 52 && specializ != 56 && specializ != 2 &&
            specializ != 5 && specializ != 49 && specializ != 48 &&
            specializ != 6))
        { // if надо писать тренерская работа    2,5,49,48,6 - ОФКиТ и 52,56 - МВС
            if (G_P) { // if это ГОС- экзамен
                predmet = "Специализация (Тренерская работа по " +
                    Name_special + ")";
            } // end if это ГОС- экзамен
            else
                predmet = "Специализация (Тренерская работа по виду спорта)";
        } // end if надо писать тренерская работа
        else { // else когда писать надо тольку специализацию
            if (G_P) { // if это ГОС- экзамен
                predmet = "Cпециализация (" + Name_special + ")";
            } // end if это ГОС- экзамен
            else
                predmet = "Специализация";
        } // end else когда писать надо тольку специализацию

        return predmet;
    } // end if  ГОС по специализации

    // -******* предмет ГОС по направлению специальности
    if (predmet == "ГОС по направлению специальности")
    { // if   ГОС по специальности
        predmet = "По направлению специальности";
        return predmet;
    } // end if   ГОС по специальности

    // -******* предмет ГОС по специальности
    if (predmet == "ГОС по специальности") { // if   ГОС по специальности
        predmet = "Cпециальность (Теория и методика физического воспитания)";
        return predmet;
    } // end if   ГОС по специальности
    // -*******

    // Добавила Оля
    // -******* предмет ГОС ИТ по специальности
    if (predmet == "ГОС ИТ по специальности") { // if   ГОС по специальности
        predmet = "Cпециальность (Туризм и гостеприимство)";
        return predmet;
    } // end if   ГОС ИТ по специальности
    // -*******

    // Добавила Оля
    // -******* предмет ГОС по специальности для Института туризма
    if (predmet == "Дипломная работа (Институт туризма)")
    { // Дипломное проектирование  (Институт туризма)
        predmet = "Дипломная работа";
        return predmet;
    } // end if   ГОС ИТ по специальности
    // -*******

    // добавила Оля
    if (predmet == "Дипломная работа (СПФ МВС)") { // Дипломная работа (СПФ МВС)
        predmet = "Дипломная работа";
        return predmet;
    } // end if Дипломная работа (СПФ МВС)
    // -*******

    // добавила Оля
    if (predmet == "Дипломная работа (СПФ СИиЕ)")
    { // Дипломная работа (СПФ СИиЕ)
        predmet = "Дипломная работа";
        return predmet;
    } // end if   Дипломная работа (СПФ СИиЕ)
    // -*******

    // добавила Оля
    if (predmet == "Дипломная работа (ОФКиТ)") { // Дипломная работа (ОФКиТ)
        predmet = "Дипломная работа";
        return predmet;
    } // end if Дипломная работа (ОФКиТ)
    // -*******

    // ---возвращаем назад старый SQL
    DataModule1 -> SpecializFDQuery -> Close ();
    DataModule1 -> SpecializFDQuery -> SQL -> Clear ();
    DataModule1 -> SpecializFDQuery -> SQL -> Add (Old_SQL);

    return predmet;
}

// ---------------------------------------------------------------------------
void __fastcall TVed_GEK::Print_Ochered ()
{ // функция печати Очередности на Гос.
     DataModule2 -> frxReport1 -> Clear ();
     //add page
     PageGEK = new TfrxReportPage (DataModule2 -> frxReport1);

    int nom = 0;
    P_F (70, 36, 683, 20, TFontStyles () << fsItalic, 16, "Arial", haCenter,
        vaCenter, TfrxFrameTypes (), "ОЧЕРЕДНОСТЬ", nom,
        DataModule2 -> frxReport1, 0);
    P_F (70, 66, 626, 20, TFontStyles (), 12, "Arial", haCenter, vaCenter,
        TfrxFrameTypes (), "явки на Государственный экзамен по дисциплине:", nom,
        DataModule2 -> frxReport1, 0);
    // Text_predmet (DM3 -> VED_GEKPrintNAME_OBJECT -> Value, DM3 -> VED_GEKPrintN_SPECIALIZ -> Value)
    // предмет или несколько предметов
    AnsiString Name_Predmet = "";
        Name_Predmet = Text_predmet_GOS
            (DM3 -> VED_GEKPrintFDQueryNAME_OBJECT -> Value,
        DM3 -> VED_GEKPrintFDQueryN_SPECIALIZ -> Value, false);
    
    int nom_predmet = DM3 -> VED_GEKPrintFDQueryN_SPECIALIZ -> Value;
    for (int i = 0; i < DM3 -> VED_GEKPrintFDQuery -> RecordCount; i++)
    { // Добавила Таня
        if (DM3 -> VED_GEKPrintFDQueryN_SPECIALIZ -> Value != nom_predmet) {
            if (!Name_Predmet.Pos (Text_predmet_GOS
                (DM3 -> VED_GEKPrintFDQueryNAME_OBJECT -> Value,
                DM3 -> VED_GEKPrintFDQueryN_SPECIALIZ -> Value, false)))
                Name_Predmet = Name_Predmet + ", " + Text_predmet_GOS
                    (DM3 -> VED_GEKPrintFDQueryNAME_OBJECT -> Value,
                DM3 -> VED_GEKPrintFDQueryN_SPECIALIZ -> Value, false);

        }
        DM3 -> VED_GEKPrintFDQuery -> Next ();
    }
    P_F (70, 86, 626, 60, TFontStyles () << fsBold, 10, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftBottom, Name_Predmet, nom,
        DataModule2 -> frxReport1, 0);

    AnsiString St = "";
    switch (DM3 -> VED_GEKPrintFDQueryN_FAC -> Value) {
    case 1:
        St = "спортивно-педагогического факультета СИиЕ";
        break;
    case 2:
        St = "спортивно-педагогического факультета МВС";
        break;
    case 3:
        St = "факультета ОФК";
        break;
    case 4:
        St = "Института менеджмента спорта и туризма";
        break;
    }

    // студентов   // факультета
    P_F (70, 146, 640, 20, TFontStyles (), 12, "Arial", haCenter, vaCenter,
        TfrxFrameTypes (), "студентов выпускного курса " + St, nom,
        DataModule2 -> frxReport1, 0);
       // университет
    P_F (70, 166, 683, 15, TFontStyles (), 12, "Arial", haCenter, vaCenter,
        TfrxFrameTypes (),
        "Белорусского государственного университета физической культуры", nom,
        DataModule2 -> frxReport1, 0);

    TDateTime data;
    AnsiString year_cur = data.CurrentDate ();
    year_cur = year_cur.SubString (7, 4); // находим текущий год
    St = year_cur;
    AnsiString St1 = IntToStr (StrToInt (year_cur) - 1);
    // учебный год
    P_F (70, 190, 683, 18, TFontStyles () << fsBold, 10, "Arial", haCenter,
        vaCenter, TfrxFrameTypes (), St1 + " / " + St + " учебный год", nom,
        DataModule2 -> frxReport1, 0);
    // дата
    P_F (70, 216, 50, 18, TFontStyles () << fsBold, 12, "Arial", haCenter,
        vaCenter, TfrxFrameTypes (), "Дата", nom, DataModule2 -> frxReport1, 0);
    if (DM3 -> VED_GEKPrintFDQuery -> RecordCount > 1)
    { // if когда несколько ведомостей на одну группу
        UnicodeString InputString =
            DM3 -> VED_GEKPrintFDQueryD_GEK -> AsString.SetLength
            (DM3 -> VED_GEKPrintFDQueryD_GEK -> AsString.Length () - 8);

        if (InputQuery ("", "У вас несколько ведомостей: укажите дату",
            InputString)) {
        }

        P_F (120, 216, 200, 18, TFontStyles (), 12, "Arial", haCenter, vaCenter,
            TfrxFrameTypes () << ftBottom, InputString, nom,
            DataModule2 -> frxReport1, 0);
    }
    else
        P_F (120, 216, 200, 18, TFontStyles (), 12, "Arial", haCenter, vaCenter,
        TfrxFrameTypes () << ftBottom,
        DM3 -> VED_GEKPrintFDQueryD_GEK -> AsString.SetLength
        (DM3 -> VED_GEKPrintFDQueryD_GEK -> AsString.Length () - 8), nom,
        DataModule2 -> frxReport1, 0);
    // Время начала экзамена
    P_F (320, 216, 150, 18, TFontStyles () << fsBold, 12, "Arial", haCenter,
        vaCenter, TfrxFrameTypes (), "Начало экзамена", nom,
        DataModule2 -> frxReport1, 0);
    St = DM3 -> VED_GEKPrintFDQueryD_GEK -> AsString.Delete (1, 11);
    St = St.SetLength (St.Length () - 3);
    P_F (470, 216, 227, 18, TFontStyles (), 12, "Arial", haCenter, vaCenter,
        TfrxFrameTypes () << ftBottom, St, nom, DataModule2 -> frxReport1, 0);

    // ШАПКА таблицы
    P_F (70, 260, 56, 40, TFontStyles () << fsBold, 10, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
        "№ п/п", nom, DataModule2 -> frxReport1, 0);
    P_F (126, 260, 300, 40, TFontStyles () << fsBold, 10, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
        "Фамилия, имя, отчество", nom, DataModule2 -> frxReport1, 0);
    if (sport)
        P_F (426, 260, 110, 40, TFontStyles () << fsBold, 10, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
        "Спортивный разряд", nom, DataModule2 -> frxReport1, 0);
    else
        P_F (426, 260, 110, 40, TFontStyles () << fsBold, 10, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
        "Оценка", nom, DataModule2 -> frxReport1, 0);
    P_F (536, 260, 160, 40, TFontStyles () << fsBold, 10, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
        "Примечание", nom, DataModule2 -> frxReport1, 0);

    // Печать самой таблицы
    TLocateOptions Op;
    int k1 = 300;
    for (int i = 0; i <= DualListDlg -> DstList -> Count - 1; i++) // DM3 -> VED_GEKPrint -> RecordCount
    {
        int p = (int) (DualListDlg -> DstList -> Items -> Objects[i]);
        DM3 -> VED_GEKPrintFDQuery -> Locate ("NOMER", (int) (DualListDlg -> DstList -> Items -> Objects[i]), Op);
        P_F (70, k1, 56, 36, TFontStyles (), 12, "Arial", haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            IntToStr (i + 1), nom, DataModule2 -> frxReport1, 0);
        P_F (126, k1, 300, 36, TFontStyles (), 12, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "  " + DM3 -> VED_GEKPrintFDQueryFAM -> Value + " " +
            DM3 -> VED_GEKPrintFDQueryNAME -> Value + " " +
            DM3 -> VED_GEKPrintFDQueryOTCH -> Value + " ", nom,
            DataModule2 -> frxReport1, 0);

        /* if (sport) PageGEK -> Objects -> Add (P_F (412,k1,110,36,0,12,"Arial",2+8,15,DM3 -> VED_GEKPrintTEXT_SPORT_CATEGORY -> Value));
         else  PageGEK -> Objects -> Add (P_F (412,k1,110,36,0,12,"Arial",2+8,15,"")); */
        if (sport) { // if  нужен спортивный разряд
            DM3 -> SportFDQuery -> Close ();
            DM3 -> SportFDQuery -> ParamByName ("NOMER") -> AsInteger =
                DM3 -> VED_GEKPrintFDQueryNOMER -> Value;
            DM3 -> SportFDQuery -> Open ();
            if (DM3 -> SportFDQuery -> RecordCount) {
                P_F (426, k1, 110, 36, TFontStyles (), 12, "Arial", haCenter,
                    vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    DM3 -> SportFDQueryTEXT_SPORT_CATEGORY -> Value, nom,
                    DataModule2 -> frxReport1, 0);
            }
            else
                P_F (426, k1, 110, 36, TFontStyles (), 12, "Arial", haCenter,
                vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
        } // end
        else
            P_F (426, k1, 110, 36, TFontStyles (), 12, "Arial", haCenter,
            vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);

        P_F (536, k1, 160, 36, TFontStyles (), 12, "Arial", haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);
        k1 = k1 + 36;
        // DM3 -> VED_GEKPrint -> Next ();
    } // for
}
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------
void __fastcall TVed_GEK::Print_VED ()
{ // функция печати экзаменационной ведомости на Гос.
    int nom = 0;
    // !!!if (Application -> MessageBox ("Ведомость будет показана для десятибальной системы?", "Выбор системы оценок", MB_YESNO) == mrYes)
    if (MessageDlg ("Ведомость будет показана для десятибальной системы?",
        mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
    { // if в десятибальной системе
        syst_ball = 10;
    }
    else
        syst_ball = 5; // пятибальная система

    DataModule2 -> frxReport1 -> Clear ();
    /*TfrxReportPage * PageGEK = dynamic_cast<TfrxReportPage*>
        (frxReport1 -> Pages[nom]); */
    // !!!DataModule2 -> frxReport1 -> Pages -> Add (); // create page
    // !!!PageGEK = DataModule2 -> frxReport1 -> Pages -> Pages[0];
    PageGEK = new TfrxReportPage (DataModule2 -> frxReport1);

    P_F (50, 25, 683, 20, TFontStyles () << fsItalic, 16, "Arial", haCenter,
        vaCenter, TfrxFrameTypes (), "УЧРЕЖДЕНИЕ ОБРАЗОВАНИЯ", nom, DataModule2 -> frxReport1, 0);
    P_F (50, 48, 683, 30, TFontStyles () << fsBold, 10, "Arial", haCenter,
        vaCenter, TfrxFrameTypes (), "", nom, DataModule2 -> frxReport1, 0);
    P_F (50, 58, 683, 20, TFontStyles () << fsItalic, 16, "Arial", haCenter,
        vaCenter, TfrxFrameTypes (), "«БЕЛОРУССКИЙ ГОСУДАРСТВЕННЫЙ УНИВЕРСИТЕТ",
        nom, DataModule2 -> frxReport1, 0);
    P_F (50, 85, 683, 20, TFontStyles () << fsItalic, 16, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftBottom, "ФИЗИЧЕСКОЙ КУЛЬТУРЫ»", nom,
        DataModule2 -> frxReport1, 0);

    TDateTime data;
    AnsiString year_cur = data.CurrentDate ();
    year_cur = year_cur.SubString (7, 4); // находим текущий год
    AnsiString St = year_cur;
    AnsiString St1 = IntToStr (StrToInt (year_cur) - 1);
    P_F (50, 120, 683, 18, TFontStyles () << fsBold, 12, "Arial", haCenter,
        vaCenter, TfrxFrameTypes (), "Государственные экзамены " + St1 + " / " +
        St + " уч.г.", nom, DataModule2 -> frxReport1, 0);
    // форма обучения
    // дневная форма обучения
    // заочная форма обучения
    if (DM3 -> VED_GEKPrintFDQueryVID_EDU -> Value)
        P_F (50, 138, 683, 18, TFontStyles () << fsBold, 12, "Arial", haCenter,
        vaCenter, TfrxFrameTypes (), "заочная форма получения образования", nom,
        DataModule2 -> frxReport1, 0);
    else
        P_F (50, 138, 683, 18, TFontStyles () << fsBold, 12, "Arial", haCenter,
        vaCenter, TfrxFrameTypes (), "дневная форма получения образования", nom,
        DataModule2 -> frxReport1, 0);

    P_F (50, 168, 683, 30, TFontStyles () << fsBold, 16, "Arial", haCenter,
        vaCenter, TfrxFrameTypes (), "ЭКЗАМЕНАЦИОННАЯ ВЕДОМОСТЬ №" +
        IntToStr (DM3 -> VED_GEKPrintFDQueryN_VEDOMOST -> Value), nom, DataModule2 -> frxReport1, 0);
    P_F (50, 360, 683, 30, TFontStyles () << fsBold, 10, "Arial", haCenter,
        vaCenter, TfrxFrameTypes (), "         ", nom, DataModule2 -> frxReport1, 0);
    P_F (50, 200, 683, 30, TFontStyles () << fsBold, 12, "Arial", haCenter,
        vaCenter, TfrxFrameTypes (), "итоговой аттестации", nom, DataModule2 -> frxReport1, 0);
    P_F (50, 380, 683, 30, TFontStyles () << fsBold, 10, "Arial", haLeft,
        vaCenter, TfrxFrameTypes (), "         ", nom, DataModule2 -> frxReport1, 0);

    P_F (50, 238, 70, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
        vaCenter, TfrxFrameTypes (), "Группа №", nom, DataModule2 -> frxReport1, 0);
    P_F (130, 238, 440, 18, TFontStyles (), 12, "Arial", haLeft, vaCenter,
        TfrxFrameTypes () << ftBottom, DM3 -> VED_GEKPrintFDQueryN_GROUP_SP -> Value,
        nom, DataModule2 -> frxReport1, 0);
    P_F (570, 238, 40, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
        vaCenter, TfrxFrameTypes (), "Дата", nom, DataModule2 -> frxReport1, 0);
    P_F (610, 238, 93, 18, TFontStyles (), 12, "Arial", haLeft, vaCenter,
        TfrxFrameTypes () << ftBottom,
        DateToStr (SQLTimeStampToDateTime (DM3 -> VED_GEKPrintFDQueryD_VED -> Value)),
        nom, DataModule2 -> frxReport1, 0);

    P_F (50, 260, 100, 40, TFontStyles () << fsBold, 10, "Arial", haLeft,
        vaBottom, TfrxFrameTypes (), "Дисциплина", nom, DataModule2 -> frxReport1, 0);

    AnsiString pr = ""; // переменная для запоминания дисциплины в ГОС ведомости
    pr=Text_predmet_GOS (DM3 -> VED_GEKPrintFDQueryNAME_OBJECT -> Value, DM3 -> VED_GEKPrintFDQueryN_SPECIALIZ -> Value,true);
    P_F (150, 260, 547, 40, TFontStyles (), 12, "Arial", haLeft, vaBottom,
        TfrxFrameTypes () << ftBottom, pr, nom, DataModule2 -> frxReport1, 0);

    // Шапка
    P_F (50, 325, 36, 50, TFontStyles () << fsBold, 10, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
        "№ п/п", nom, DataModule2 -> frxReport1, 0);
    P_F (86, 325, 356, 50, TFontStyles () << fsBold, 10, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
        "Фамилия, имя, отчество", nom, DataModule2 -> frxReport1, 0);
    if (pr != "Дипломная работа")
        P_F (442, 325, 117, 50, TFontStyles () << fsBold, 10, "Arial", haCenter,
        vaCenter, TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
        "№ экзаменацион-  ного билета", nom, DataModule2 -> frxReport1, 0);

    // оля - печать ГОС ведомости (ДП или ГОС)
    if (syst_ball == 10)
    { // шапка для ведомости по дипломному проектированию (Добавила Оля)

        if (pr == "Дипломная работа") {
            P_F (442, 325, 270, 32, TFontStyles () << fsBold, 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                "Экзаменационная оценка", nom, DataModule2 -> frxReport1, 0);
            P_F (442, 357, 80, 18, TFontStyles () << fsBold, 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                "цифрой", nom, DataModule2 -> frxReport1, 0);
            P_F (522, 357, 190, 18, TFontStyles () << fsBold, 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                "прописью", nom, DataModule2 -> frxReport1, 0);
        }
        else {
            P_F (559, 325, 160, 32, TFontStyles () << fsBold, 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                "Экзаменационная оценка", nom, DataModule2 -> frxReport1, 0);
            P_F (559, 357, 60, 18, TFontStyles () << fsBold, 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                "цифрой", nom, DataModule2 -> frxReport1, 0);
            P_F (619, 357, 100, 18, TFontStyles () << fsBold, 10, "Arial",
                haCenter, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                "прописью", nom, DataModule2 -> frxReport1, 0);
        }
    }
    else {
        if (pr != "Дипломная работа")
            P_F (559, 325, 160, 50, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "Экзаменационная оценка", nom, DataModule2 -> frxReport1, 0);
        else
            P_F (442, 325, 270, 50, TFontStyles () << fsBold, 10, "Arial",
            haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "Экзаменационная оценка", nom, DataModule2 -> frxReport1, 0);
    }

    int k1 = 375;
    DM3 -> VED_GEKPrintFDQuery -> First ();
    for (int i = 1; i <= DM3 -> VED_GEKPrintFDQuery -> RecordCount; i++) {
        P_F (50, k1, 36, 25, TFontStyles (), 12, "Arial", haCenter, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            IntToStr (i), nom, DataModule2 -> frxReport1, 0);
        P_F (86, k1, 356, 25, TFontStyles (), 12, "Arial", haLeft, vaCenter,
            TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
            "  " + DM3 -> VED_GEKPrintFDQueryFAM -> Value + " " +
            DM3 -> VED_GEKPrintFDQueryNAME -> Value + " " +
            DM3 -> VED_GEKPrintFDQueryOTCH -> Value + " ", nom, DataModule2 -> frxReport1, 0);

        if (syst_ball == 10) { // if в десятибальной системе
            // два столбца
            if (pr != "Дипломная работа") {
                P_F (442, k1, 117, 25, TFontStyles (), 12, "Arial", haLeft,
                    vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                P_F (559, k1, 60, 25, TFontStyles (), 12, "Arial", haLeft,
                    vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                P_F (619, k1, 100, 25, TFontStyles (), 12, "Arial", haLeft,
                    vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
            }
            else { // если Диплом
                P_F (442, k1, 80, 25, TFontStyles () << fsBold, 10, "Arial",
                    haLeft, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                P_F (522, k1, 190, 25, TFontStyles () << fsBold, 10, "Arial",
                    haLeft, vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
            }
            // PageGEK -> Objects -> Add (P_F (543,k1,60,25,0,12,"Arial",0+8,15,""));
        }
        else {
            if (pr != "Дипломная работа") {
                P_F (442, k1, 117, 25, TFontStyles (), 12, "Arial", haLeft,
                    vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
                P_F (559, k1, 160, 25, TFontStyles (), 12, "Arial", haLeft,
                    vaCenter,
                    TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom,
                    "", nom, DataModule2 -> frxReport1, 0);
            }
            else
                P_F (442, k1, 270, 25, TFontStyles () << fsBold, 10, "Arial",
                haLeft, vaCenter,
                TfrxFrameTypes () << ftLeft << ftRight << ftTop << ftBottom, "",
                nom, DataModule2 -> frxReport1, 0);
        }

        k1 = k1 + 25;
        DM3 -> VED_GEKPrintFDQuery -> Next ();
    }
    // ----определение системы выдачи ведомости (пятибальная или десятибальная)
    if (syst_ball == 10) { // if в десятибальной системе
        // ---для десятибальной системы
        P_F (265, k1 + 36, 70, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "ИТОГО", nom, DataModule2 -> frxReport1, 0);
        P_F (335, k1 + 36, 100, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

        P_F (493, k1 + 36, 100, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "пять", nom, DataModule2 -> frxReport1, 0);
        P_F (593, k1 + 36, 100, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

        P_F (265, k1 + 54, 70, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "десять", nom, DataModule2 -> frxReport1, 0);
        P_F (335, k1 + 54, 100, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

        P_F (493, k1 + 54, 100, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "четыре", nom, DataModule2 -> frxReport1, 0);
        P_F (593, k1 + 54, 100, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

        P_F (265, k1 + 72, 70, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "девять", nom, DataModule2 -> frxReport1, 0);
        P_F (335, k1 + 72, 100, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

        P_F (493, k1 + 72, 100, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "три", nom, DataModule2 -> frxReport1, 0);
        P_F (593, k1 + 72, 100, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

        P_F (265, k1 + 90, 70, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "восемь", nom, DataModule2 -> frxReport1, 0);
        P_F (335, k1 + 90, 100, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

        P_F (493, k1 + 90, 100, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "два", nom, DataModule2 -> frxReport1, 0);
        P_F (593, k1 + 90, 100, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

        P_F (265, k1 + 108, 70, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "семь", nom, DataModule2 -> frxReport1, 0);
        P_F (335, k1 + 108, 100, 18, TFontStyles () << fsBold, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes () << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);

        P_F (493, k1 + 108, 100, 18, TFontStyles () << fsBold, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (), "один", nom, DataModule2 -> frxReport1, 0);
        P_F (593, k1 + 108, 100, 18, TFontStyles () << fsBold, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes () << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);

        P_F (265, k1 + 126, 70, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "шесть", nom, DataModule2 -> frxReport1, 0);
        P_F (335, k1 + 126, 100, 18, TFontStyles () << fsBold, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes () << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);

        P_F (493, k1 + 126, 100, 18, TFontStyles () << fsBold, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (), "Не явились", nom, DataModule2 -> frxReport1, 0);
        P_F (593, k1 + 126, 100, 18, TFontStyles () << fsBold, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes () << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);

        k1 += 18;
    } // end if в десятибальной системе
    else { // else  в пятибальной системе
        // ---для пятибальной системы
        P_F (105, k1 + 72, 200, 40, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "ИТОГО", nom, DataModule2 -> frxReport1, 0);
        P_F (305, k1 + 36, 70, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "Отлично", nom, DataModule2 -> frxReport1, 0);
        P_F (375, k1 + 36, 240, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);
        P_F (305, k1 + 54, 70, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "Хорошо", nom, DataModule2 -> frxReport1, 0);
        P_F (365, k1 + 54, 240, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);
        P_F (305, k1 + 72, 160, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "Удовлетворительно", nom, DataModule2 -> frxReport1, 0);
        P_F (465, k1 + 72, 150, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);
        P_F (305, k1 + 90, 160, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes (), "Неудовлетворительно", nom, DataModule2 -> frxReport1, 0);
        P_F (465, k1 + 90, 150, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
            vaCenter, TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);
        P_F (305, k1 + 108, 160, 18, TFontStyles () << fsBold, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes (), "Не явились", nom, DataModule2 -> frxReport1, 0);
        P_F (465, k1 + 108, 150, 18, TFontStyles () << fsBold, 10, "Arial",
            haLeft, vaCenter, TfrxFrameTypes () << ftBottom, "", nom,
            DataModule2 -> frxReport1, 0);
    } // end else  в пятибальной системе

    k1 = k1 + 110;
    // Подписи
    P_F (105, k1 + 36, 260, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
        vaCenter, TfrxFrameTypes (), "Председатель ГЭК", nom, DataModule2 -> frxReport1, 0);
    P_F (265, k1 + 36, 340, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
        vaCenter, TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);
    P_F (105, k1 + 54, 260, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
        vaCenter, TfrxFrameTypes (), "Члены ГЭК", nom, DataModule2 -> frxReport1, 0);
    P_F (265, k1 + 54, 340, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
        vaCenter, TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);
    P_F (105, k1 + 72, 260, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
        vaCenter, TfrxFrameTypes (), "Секретарь ГЭК", nom, DataModule2 -> frxReport1, 0);
    P_F (265, k1 + 72, 340, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
        vaCenter, TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0);

    /*P_F (105, k1 + 112, 260, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
        vaCenter, TfrxFrameTypes (), "Экзаменатор", nom, DataModule2 -> frxReport1, 0);
    P_F (265, k1 + 112, 340, 18, TFontStyles () << fsBold, 10, "Arial", haLeft,
        vaCenter, TfrxFrameTypes () << ftBottom, "", nom, DataModule2 -> frxReport1, 0); */

}

// ---------------------------------------------------------------------------
void __fastcall TVed_GEK::Edit1Enter (TObject *Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> ShowModal ();
    if (calendar)
        Edit1 -> Text = cal_date;
    BitBtn4 -> SetFocus ();
}

// ---------------------------------------------------------------------------
void __fastcall TVed_GEK::BitBtn1Click (TObject *Sender) {
    if (MessageBox (0, "Не забудьте внести студентам приказ на допуск!!", "",
        MB_OKCANCEL) == IDOK) {

        ADD_VedGEK = new TADD_VedGEK (this);
        // Создание формы для формирования ведомости
        ADD_VedGEK -> Height = 140;
        ADD_VedGEK -> ShowModal ();

    } // if
}

// ---------------------------------------------------------------------------
void __fastcall TVed_GEK::FormClose (TObject *Sender, TCloseAction &Action) {
    Action = caFree;
}

// ---------------------------------------------------------------------------
void __fastcall TVed_GEK::FormActivate (TObject *Sender) {
    /* DM3 -> VED_GEKGrid -> Close ();
     DM3 -> VED_GEKGrid -> ParamByName ("N_FAC") -> Value=nom_fac;
     DM3 -> VED_GEKGrid -> ParamByName ("YEAR_PLAN") -> Value=uch_god;
     DM3 -> VED_GEKGrid -> Open (); */

    if (!Ved_GEK -> Open_S (CheckBox1 -> Checked))
        return;

    // DM3 -> VED_GEKGrid -> Last ();
}
// ---------------------------------------------------------------------------

void __fastcall TVed_GEK::BitBtn3Click (TObject *Sender) {
    Ved_GEK -> Close ();
}
// ---------------------------------------------------------------------------

void __fastcall TVed_GEK::RadioGroup2Click (TObject *Sender) {
    CheckBox2 -> Checked = false;
    Edit3 -> Text = ""; // очищение номера группы (фильтр)
    // Показ в Grid по виду обучения
    if (RadioGroup2 -> ItemIndex == 1) {
        DM3 -> VED_GEKGridFDQuery -> Filter = "VID_EDU_PLAN=0";
        DM3 -> VED_GEKGridFDQuery -> Filtered = true;
        CheckBox2 -> Enabled = true;
    }
    if (RadioGroup2 -> ItemIndex == 2) {
        DM3 -> VED_GEKGridFDQuery -> Filter = "VID_EDU_PLAN=1";
        DM3 -> VED_GEKGridFDQuery -> Filtered = true;
        CheckBox2 -> Enabled = true;
    }
    if (RadioGroup2 -> ItemIndex == 0) {
        DM3 -> VED_GEKGridFDQuery -> Filtered = false;
        CheckBox2 -> Enabled = false;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TVed_GEK::CheckBox2Click (TObject *Sender) {
    if (CheckBox2 -> Checked) {
        Label8 -> Enabled = true;
        Edit3 -> Enabled = true;
        BitBtn7 -> Enabled = true;

    }
    else {
        DM3 -> VED_GEKGridFDQuery -> Filtered = false;
        Label8 -> Enabled = false;
        Edit3 -> Clear ();
        Edit3 -> Enabled = false;
        BitBtn7 -> Enabled = false;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TVed_GEK::BitBtn7Click (TObject *Sender) {
    if (Edit3 -> Text == "") { // if проверка на ввод номера группы для ГОС
        ShowMessage ("Вы не ввели номер группы для ГОСа (например: 2)!");
        return;
    } // end if проверка на ввод номера группы для ГОС
    int vid = -1;
    if (RadioGroup2 -> ItemIndex)
        vid = RadioGroup2 -> ItemIndex - 1;
    try { // try проверка на ввод правильных значений
        DM3 -> VED_GEKGridFDQuery -> Filtered = false;
        DM3 -> VED_GEKGridFDQuery -> Filter = "N_GROUP_SP=" + Edit3 -> Text +
            "and VID_EDU_PLAN=" + IntToStr (vid);
        DM3 -> VED_GEKGridFDQuery -> Filtered = true;
    } // end try проверка на ввод правильных значений
    catch (...) { // catch
        ShowMessage ("Неправильно введен номер группы для ГОСа!");
        return;
    } // end catch
}
// ---------------------------------------------------------------------------

void __fastcall TVed_GEK::CheckBox1Click (TObject *Sender) {
    if (CheckBox1 -> Checked) {
        Label3 -> Enabled = true;
        Label4 -> Enabled = true;
        Edit1 -> Enabled = true;
        Edit2 -> Enabled = true;
        BitBtn4 -> Enabled = true;

    }
    else {
        // DM3 -> VED_GEKGrid -> Filtered=false;
        if (!Ved_GEK -> Open_S (CheckBox1 -> Checked))
            return;
        Label3 -> Enabled = false;
        Label4 -> Enabled = false;
        Edit1 -> Enabled = false;
        Edit2 -> Enabled = false;
        Edit1 -> Clear ();
        Edit2 -> Clear ();
        BitBtn4 -> Enabled = false;
    }

}
// ---------------------------------------------------------------------------

void __fastcall TVed_GEK::BitBtn4Click (TObject *Sender) {
    if (Edit1 -> Text == "" || Edit2 -> Text == "") { // if проверка на ввод даты
        ShowMessage (
            "Вы не ввели дату с какого периода и по какой показывать ведомости!");
        return;
    } // end if проверка на ввод даты

    /* DM3 -> VED_GEKGrid -> Filtered=false;
     DM3 -> VED_GEKGrid -> Filter="D_VED>='"+Edit1 -> Text+"' and D_VED<='"+Edit2 -> Text+"'";
     DM3 -> VED_GEKGrid -> Filtered=true; */

    if (!Ved_GEK -> Open_S (CheckBox1 -> Checked))
        return;
}
// ---------------------------------------------------------------------------

void __fastcall TVed_GEK::Edit2Enter (TObject *Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> ShowModal ();
    if (calendar)
        Edit2 -> Text = cal_date;
    BitBtn4 -> SetFocus ();
}
// ---------------------------------------------------------------------------

void __fastcall TVed_GEK::BitBtn2Click (TObject *Sender) {

    // Печать отчета
    // Формирование Query
    DM3 -> VED_GEKPrintFDQuery -> Close ();
    DM3 -> VED_GEKPrintFDQuery -> SQL -> Clear ();
    /* DM3 -> VED_GEKPrint -> SQL -> Add ("SELECT People.NOMER, People.FAM
     , People.NAME, People.OTCH, People.VID_EDU, \
     People.N_FAC, People.N_SPECIALIZ, People.STATUS_PEOPLE, Gek.NOMER_GEK, Gek.N_VED, Gek.D_GEK, Gek.BALL_GEK, \
     Vedomost_gek.N_VEDOMOST, Vedomost_gek.N_GROUP_SP, Vedomost_gek.D_VED, Vedomost_gek.FIO_EXAM, Vedomost_gek.N_PLAN, \
     Increment_group.N_GROUP, People.INC_GROUP, Edu_plan.N_OBJECT, Object_plan.NAME_OBJECT, \
     Sport.SPORT_CATEGORY, Category.TEXT_SPORT_CATEGORY \
     FROM PEOPLE People  \
     INNER JOIN GEK Gek  \
     ON  (Gek.NOMER = People.NOMER)  \
     INNER JOIN INCREMENT_GROUP Increment_group  \
     ON  (People.INC_GROUP = Increment_group.INC_GROUP) \
     INNER JOIN SPORT Sport  \
     ON  (People.NOMER = Sport.NOMER)   \
     INNER JOIN VEDOMOST_GEK Vedomost_gek   \
     ON  (Gek.N_VED = Vedomost_gek.N_VED) \
     INNER JOIN CATEGORY Category   \
     ON  (Sport.SPORT_CATEGORY = Category.SPORT_CATEGORY) \
     INNER JOIN EDU_PLAN Edu_plan   \
     ON  (Vedomost_gek.N_PLAN = Edu_plan.N_PLAN)   \
     INNER JOIN OBJECT_PLAN Object_plan  \
     ON  (Edu_plan.N_OBJECT = Object_plan.N_OBJECT) \
     where People.INC_GROUP=:INC_GROUP and   \
     Gek.N_VED=:N_VED    order by People.FAM, People.NAME, People.OTCH "); */

    /* DM3 -> VED_GEKPrint -> SQL -> Add ("SELECT distinct PEOPLE.NOMER, PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH, \
     PEOPLE.VID_EDU, PEOPLE.N_FAC, PEOPLE.N_SPECIALIZ, PEOPLE.STATUS_PEOPLE, GEK.NOMER_GEK, \
     GEK.N_VED, GEK.D_GEK, GEK.BALL_GEK, VEDOMOST_GEK.N_VEDOMOST, VEDOMOST_GEK.N_GROUP_SP, \
     VEDOMOST_GEK.D_VED, VEDOMOST_GEK.N_PLAN, EDU_PLAN.N_OBJECT, OBJECT_PLAN.NAME_OBJECT, \
     SPORT.SPORT_CATEGORY, CATEGORY.TEXT_SPORT_CATEGORY, PEOPLE.N_GROUP  \
     FROM EDU_PLAN  \
     INNER JOIN VEDOMOST_GEK ON (EDU_PLAN.N_PLAN = VEDOMOST_GEK.N_PLAN)  \
     INNER JOIN GEK ON (VEDOMOST_GEK.N_VED = GEK.N_VED) \
     INNER JOIN PEOPLE ON (GEK.NOMER = PEOPLE.NOMER)  \
     INNER JOIN SPORT ON (PEOPLE.NOMER = SPORT.NOMER)  \
     INNER JOIN CATEGORY ON (SPORT.SPORT_CATEGORY = CATEGORY.SPORT_CATEGORY)  \
     INNER JOIN OBJECT_PLAN ON (EDU_PLAN.N_OBJECT = OBJECT_PLAN.N_OBJECT) \
     WHERE   ( (GEK.N_VED = :N_VED)) ORDER BY PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH "); */

    DM3 -> VED_GEKPrintFDQuery -> SQL -> Add ("SELECT distinct (PEOPLE.NOMER), PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH, \
    PEOPLE.VID_EDU, PEOPLE.N_FAC, PEOPLE.N_SPECIALIZ, PEOPLE.STATUS_PEOPLE, GEK.NOMER_GEK, \
    GEK.N_VED, GEK.D_GEK, GEK.BALL_GEK, VEDOMOST_GEK.N_VEDOMOST, VEDOMOST_GEK.N_GROUP_SP,  \
    VEDOMOST_GEK.D_VED, VEDOMOST_GEK.N_PLAN, EDU_PLAN.N_OBJECT, OBJECT_PLAN.NAME_OBJECT,  \
    PEOPLE.N_GROUP  \
    FROM EDU_PLAN  \
   INNER JOIN VEDOMOST_GEK ON (EDU_PLAN.N_PLAN = VEDOMOST_GEK.N_PLAN) \
   INNER JOIN GEK ON (VEDOMOST_GEK.N_VED = GEK.N_VED) \
   INNER JOIN PEOPLE ON (GEK.NOMER = PEOPLE.NOMER) \
   INNER JOIN OBJECT_PLAN ON (EDU_PLAN.N_OBJECT = OBJECT_PLAN.N_OBJECT)  \
    WHERE   ( (GEK.N_VED = :N_VED)) \
     ORDER BY PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH");

    // DM3 -> VED_GEKPrint -> ParamByName ("INC_GROUP") -> Value=DM3 -> VED_GEKGridINC_GROUP -> Value;
    DM3 -> VED_GEKPrintFDQuery -> ParamByName ("N_VED") -> Value =
        DM3 -> VED_GEKGridFDQueryN_VED -> Value;

    DM3 -> VED_GEKPrintFDQuery -> Open ();
    DM3 -> VED_GEKPrintFDQuery -> First ();
    Print_VED ();
    DataModule2 -> frxReport1 -> PrepareReport ();
    DataModule2 -> frxReport1 -> ShowPreparedReport ();
}
// ---------------------------------------------------------------------------

void __fastcall TVed_GEK::BitBtn5Click (TObject *Sender) {
    ADD_VedGEK -> Delete_VED (DM3 -> VED_GEKGridFDQueryN_VED -> Value);
}
// ---------------------------------------------------------------------------

void __fastcall TVed_GEK::BitBtn6Click (TObject *Sender) {
    if (MessageBox (0, "Перед формированием очередности сформируйте ведомость!",
        "", MB_OKCANCEL) == IDOK) {

        // !!!if (Application -> MessageBox ("В очередности показывать спортивный разряд?", "Выбор вида очередности", MB_YESNO) == mrYes)
        if (MessageDlg ("В очередности показывать спортивный разряд?",
            mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
        { // if в десятибальной системе
            sport = true;
        } // end if в десятибальной системе
        else { // else  в пятибальной системе
            sport = false;
        } // end else  в пятибальной системе

        // Печать отчета
        // Формирование Query
        DM3 -> VED_GEKPrintFDQuery -> Close ();
        DM3 -> VED_GEKPrintFDQuery -> SQL -> Clear ();
        /* DM3 -> VED_GEKPrint -> SQL -> Add ("SELECT People.NOMER, People.FAM, People.NAME, People.OTCH, People.VID_EDU, \
         People.N_FAC, People.N_SPECIALIZ, People.STATUS_PEOPLE, Gek.NOMER_GEK, Gek.N_VED, Gek.D_GEK, Gek.BALL_GEK, \
         Vedomost_gek.N_VEDOMOST, Vedomost_gek.N_GROUP_SP, Vedomost_gek.D_VED, Vedomost_gek.FIO_EXAM, Vedomost_gek.N_PLAN, \
         Increment_group.N_GROUP, People.INC_GROUP, Edu_plan.N_OBJECT, Object_plan.NAME_OBJECT, \
         Sport.SPORT_CATEGORY, Category.TEXT_SPORT_CATEGORY \
         FROM PEOPLE People  \
         INNER JOIN GEK Gek  \
         ON  (Gek.NOMER = People.NOMER)  \
         INNER JOIN INCREMENT_GROUP Increment_group  \
         ON  (People.INC_GROUP = Increment_group.INC_GROUP) \
         INNER JOIN SPORT Sport  \
         ON  (People.NOMER = Sport.NOMER)   \
         INNER JOIN VEDOMOST_GEK Vedomost_gek   \
         ON  (Gek.N_VED = Vedomost_gek.N_VED) \
         INNER JOIN CATEGORY Category   \
         ON  (Sport.SPORT_CATEGORY = Category.SPORT_CATEGORY) \
         INNER JOIN EDU_PLAN Edu_plan   \
         ON  (Vedomost_gek.N_PLAN = Edu_plan.N_PLAN)   \
         INNER JOIN OBJECT_PLAN Object_plan  \
         ON  (Edu_plan.N_OBJECT = Object_plan.N_OBJECT) \
         where People.INC_GROUP=:INC_GROUP and   \
         Vedomost_gek.N_GROUP_SP=:N_GROUP_SP and \
         People.VID_EDU=:EDU  order by People.FAM, People.NAME, People.OTCH "); */

        /* DM3 -> VED_GEKPrint -> SQL -> Add ("SELECT distinct PEOPLE.NOMER, PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH, \
         PEOPLE.VID_EDU, PEOPLE.N_FAC, PEOPLE.N_SPECIALIZ, PEOPLE.STATUS_PEOPLE, GEK.NOMER_GEK, \
         GEK.N_VED, GEK.D_GEK, GEK.BALL_GEK, VEDOMOST_GEK.N_VEDOMOST, VEDOMOST_GEK.N_GROUP_SP, \
         VEDOMOST_GEK.D_VED, VEDOMOST_GEK.N_PLAN, EDU_PLAN.N_OBJECT, OBJECT_PLAN.NAME_OBJECT, \
         SPORT.SPORT_CATEGORY, CATEGORY.TEXT_SPORT_CATEGORY, PEOPLE.N_GROUP  \
         FROM EDU_PLAN  \
         INNER JOIN VEDOMOST_GEK ON (EDU_PLAN.N_PLAN = VEDOMOST_GEK.N_PLAN)  \
         INNER JOIN GEK ON (VEDOMOST_GEK.N_VED = GEK.N_VED) \
         INNER JOIN PEOPLE ON (GEK.NOMER = PEOPLE.NOMER)  \
         INNER JOIN SPORT ON (PEOPLE.NOMER = SPORT.NOMER)  \
         INNER JOIN CATEGORY ON (SPORT.SPORT_CATEGORY = CATEGORY.SPORT_CATEGORY)  \
         INNER JOIN OBJECT_PLAN ON (EDU_PLAN.N_OBJECT = OBJECT_PLAN.N_OBJECT) \
         WHERE   (Vedomost_gek.N_GROUP_SP=:N_GROUP_SP and People.VID_EDU=:EDU  \
         and VEDOMOST_GEK.N_PLAN=:N_PLAN  )     \
         ORDER BY PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH "); */

        DM3 -> VED_GEKPrintFDQuery -> SQL -> Add ("SELECT distinct (PEOPLE.NOMER), PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH, \
    PEOPLE.VID_EDU, PEOPLE.N_FAC, PEOPLE.N_SPECIALIZ, PEOPLE.STATUS_PEOPLE, GEK.NOMER_GEK, \
    GEK.N_VED, GEK.D_GEK, GEK.BALL_GEK, VEDOMOST_GEK.N_VEDOMOST, VEDOMOST_GEK.N_GROUP_SP,  \
    VEDOMOST_GEK.D_VED, VEDOMOST_GEK.N_PLAN, EDU_PLAN.N_OBJECT, OBJECT_PLAN.NAME_OBJECT,  \
    PEOPLE.N_GROUP  \
    FROM EDU_PLAN  \
   INNER JOIN VEDOMOST_GEK ON (EDU_PLAN.N_PLAN = VEDOMOST_GEK.N_PLAN) \
   INNER JOIN GEK ON (VEDOMOST_GEK.N_VED = GEK.N_VED) \
   INNER JOIN PEOPLE ON (GEK.NOMER = PEOPLE.NOMER) \
   INNER JOIN OBJECT_PLAN ON (EDU_PLAN.N_OBJECT = OBJECT_PLAN.N_OBJECT)  \
    WHERE   (Vedomost_gek.N_GROUP_SP=:N_GROUP_SP and People.VID_EDU=:EDU  \
          and VEDOMOST_GEK.N_PLAN=:N_PLAN  )  \
     ORDER BY PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH");

        // DM3 -> VED_GEKPrint -> ParamByName ("INC_GROUP") -> Value=DM3 -> VED_GEKGridINC_GROUP -> Value;
        DM3 -> VED_GEKPrintFDQuery -> ParamByName ("N_GROUP_SP") -> Value =
            DM3 -> VED_GEKGridFDQueryN_GROUP_SP -> Value;
        DM3 -> VED_GEKPrintFDQuery -> ParamByName ("EDU") -> Value =
            DM3 -> VED_GEKGridFDQueryVID_EDU_PLAN -> Value;
        DM3 -> VED_GEKPrintFDQuery -> ParamByName ("N_PLAN") -> Value =
            DM3 -> VED_GEKGridFDQueryN_PLAN -> Value;
        DM3 -> VED_GEKPrintFDQuery -> Open ();
        DM3 -> VED_GEKPrintFDQuery -> First ();
        // Добавление в MyList людей
        // Формирование входного массива
        AnsiString *mas_stud[2]; // массив номеров и фамилий студентов
        for (int i = 0; i < 2; i++)
            mas_stud[i] = new AnsiString[DM3 -> VED_GEKPrintFDQuery -> RecordCount];
        //////////////////////////////////////////////////////////////////////////
        DualListDlg = new TDualListDlg (this);
        DualListDlg -> Caption = "Формирование очередности на ГОС";
        DualListDlg -> SrcList -> Clear ();
        DualListDlg -> DstList -> Clear ();
        //int jj = 0; // Переменная для массива
        // Мой компонент
        for (int j = 0; j <= DM3 -> VED_GEKPrintFDQuery -> RecordCount - 1; j++) {
            mas_stud[0][j] = DM3 -> VED_GEKPrintFDQueryFAM -> Value + " " +
                DM3 -> VED_GEKPrintFDQueryNAME -> Value + " " +
                DM3 -> VED_GEKPrintFDQueryOTCH -> Value;
            DualListDlg -> SrcList -> Items -> AddObject
                (IntToStr (j + 1) + " " + mas_stud[0][j],
                (TObject *) (DM3 -> VED_GEKPrintFDQueryNOMER -> Value));
            mas_stud[1][j] = IntToStr (DM3 -> VED_GEKPrintFDQueryNOMER -> Value);

            DM3 -> VED_GEKPrintFDQuery -> Next ();
        } // for  Мой компонент

        DualListDlg -> ShowModal ();

        if (DataModule2 -> printdlg == true) {
            if ( (DualListDlg -> DstList -> Count != 0))
                // && (MyList1 -> FOutList -> Count==MyList1 -> SourceList -> Count))
            {
                // Формирование Query для выбора студентов
              /*    Nomer = new int[DM3 -> VED_GEKPrintFDQuery -> RecordCount];
                Count_OutList = DualListDlg -> DstList -> Count - 1;
                for (int i = 0; i <= Count_OutList; i++) {
                    for (int j = 0; j <= DualListDlg -> SrcList -> Count - 1; j++) {
                        if (IntToStr (j + 1) + " " +
                            mas_stud[0][j]
                            == DualListDlg -> DstList -> Items -> Strings[i]) {
                            Nomer[i] = StrToInt (mas_stud[1][j]);
                            // возвращаем номер студента
                            j = DualListDlg -> SrcList -> Count - 1;
                            // если нашли то уходим из цикла
                        }

                    } // 2-ой for
                } // 1-ый for          */

                // Формирование Query для выхода
                DM3 -> VED_GEKPrintFDQuery -> First ();
                // Печать
                Print_Ochered ();
                DataModule2 -> frxReport1 -> PrepareReport ();
                DataModule2 -> frxReport1 -> ShowPreparedReport ();

            }
            else {
                ShowMessage (
                    "Количество студентов в Ведомости не совпадает с выбранным");
            }
        } // MyList -> Execute

    } // if MessageBox
}
// ---------------------------------------------------------------------------

void __fastcall TVed_GEK::ApplicationEvents1Message (tagMSG &Msg, bool &Handled)
{
    // организовать нормальную работу мышиного колесика в DBGrid

    if (DBGrid2 -> Focused ()) {
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

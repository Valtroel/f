#include <vcl.h>
#pragma hdrstop


#include "AboutUnit.h"
#include "All_StatisticUnit.h"
#include "AutoDiplomUnit.h"
#include "Ball_Unit.h"
#include "DataModule.h"
#include "DeloUnit.h"
#include "DiplomUnit.h"
#include "DM2Unit.h"
#include "Edu_planUnit.h"
#include "Func.h"
#include "InfoUnit.h"
#include "LikvidUchPlanUnit.h"
#include "MainUnit.h"
#include "Medical_СhecklistUnit.h"
#include "NK_3Unit.h"
#include "PassDlgUnit.h"
#include "PeopleVedUnit.h"
#include "Prikaz_LikvidUnit.h"
#include "PrivilegeUnit.h"
#include "Raspred_StateUnit.h"
#include "Result_Ball_RatingUnit.h"
#include "Result_RatingUnit.h"
#include "Result_VedUnit.h"
#include "Semestr_SessionUnit.h"
#include "SessionUnit.h"
#include "SpisocUnit.h"
#include "SpisokAllUnit.h"
#include "SplashUnit.h"
#include "Spravka_vyzovUnit.h"
#include "SpravkaUnit.h"
#include "SpravkiUnit.h"
#include "SpravUnit.h"
#include "StudUnit.h"
#include "Svod_VedUnit.h"
#include "systdate.h"
#include "VED_GEKResultUnit.h"
#include "Ved_GEKUnit.h"
#include "Ved_LikvidUnit.h"
#include "Ved_RatingUnit.h"
#include "VedUnit.h"
#include "Vipusk_StudUnit.h"
#include "VipusknikiUnit.h"


#pragma package (smart_init)
// #pragma link     "RxLogin"
#pragma resource "*.dfm"


TMainForm * MainForm;


AnsiString n_gr     = "",   // номер группы
           Us_Name,
           Us_Pas,
           v_e      = "",   // вид обучения
           vid_razr = "";   // формирование строки для вида спорта и разряда

int        n_stud,          // номер студента
           spisok_f,        // переменная для определения какой пунк меню выбрали из списка
           spisok_f1,       // переменная для определения какой пунк меню выбрали для привилегий
           Vibor,           // Переключатель между формами Сводной и выписки к диплому
           vid_e;           // переменная для определения вида обучения для списка студентов

Variant    ExcelApp,
           WBook,
           WSheet;




// Create_Spisok
// Data_Refresh
// FormActivate
// FormClose
// FormCreate
// N1Click
// N4Click
// N6Click
// N8Click
// N11Click
// N12Click
// N13Click
// N14Click
// N16Click
// N17Click
// N18Click
// N19Click
// N22Click
// N23Click
// N24Click
// N25Click
// N26Click
// N27Click
// N29Click
// N30Click
// N31Click
// N32Click
// N33Click
// N34Click
// N35Click
// N36Click
// N37Click
// N39Click
// N40Click
// N42Click
// N43Click
// N45Click
// N46Click
// N48Click
// N49Click
// N50Click
// N52Click
// N53Click
// N54Click
// N56Click
// N57Click
// N58Click
// N60Click
// N61Click
// N62Click
// N63Click
// N64Click
// N65Click
// N66Click
// N67Click
// N68Click
// N69Click
// N70Click
// N71Click
// N72Click
// N73Click
// N74Click
// N75Click
// N76Click
// N77Click
// N78Click
// N79Click
// N80Click
// N81Click
// N82Click
// N83Click
// N84Click
// N85Click
// Open_PrivilegeForm
// Open_SpisokForm
// prikaz_search
// SearchChild
// SpeedButton1Click
// Spisok





__fastcall TMainForm::TMainForm (TComponent* Owner) : TForm (Owner) {
}


void __fastcall TMainForm::prikaz_search (int n_menu)
{ // процедура поиска активной страницы на форме приказов
    bool found = 0; // Переменная для поиска уже открыта или нет форма Приказы
    for (int i = 0; i < MDIChildCount; i++)
    { // for      //Цикл для просмотра всех открытых дочерних форм
        if (MDIChildren[i] -> Name == "DeloForm") {
            found = 1;
            break;
        } // Если форма Приказы открыта, то переменной присваивается 1
    } // end for
    if (!found) { // Если форма Приказы не найдена, то
        DeloForm = new TDeloForm (this);
    } // Создание формы Приказы

    switch (n_menu)
    { // switch  в зависимости от нажатого пункта меню - делаем определенную
        // страницу открытой
    case 35: // академ.отпуск N35, TabSheet-6, PageIndex-5
        DeloForm -> PageControl1 -> ActivePageIndex = 5;
        break;
    case 36: // повторный год N36, TabSheet-7, PageIndex-6
        DeloForm -> PageControl1 -> ActivePageIndex = 6;
        break;
    case 37: // изменение фамилии N37, TabSheet-4, PageIndex-4
        DeloForm -> PageControl1 -> ActivePageIndex = 4;
        break;
    case 39: // отчисление N39, TabSheet-2, PageIndex-2
        DeloForm -> PageControl1 -> ActivePageIndex = 2;
        break;
    case 40: // восстановление N40, TabSheet-3, PageIndex-3
        DeloForm -> PageControl1 -> ActivePageIndex = 3;
        break;
    case 42: // перевод на след.курс N42, TabSheet-1, PageIndex-0
        DeloForm -> PageControl1 -> ActivePageIndex = 0;
        break;
    case 43: // перевод задолженников N43, TabSheet-5, PageIndex-1
        DeloForm -> PageControl1 -> ActivePageIndex = 1;
        break;
    case 45: // Перевод N45, TabSheet-9, PageIndex-8
        DeloForm -> PageControl1 -> ActivePageIndex = 8;
        break;
    case 46: // Поощрения/Взыскания N46, TabSheet-8, PageIndex-7
        DeloForm -> PageControl1 -> ActivePageIndex = 7;
        break;
    case 48: // Приказ на допуск к Гос или диплом N48, TabSheet-11, PageIndex-10
        DeloForm -> PageControl1 -> ActivePageIndex = 10;
        break;
    case 49: // Диплом N49, TabSheet-10, PageIndex-9
        DeloForm -> PageControl1 -> ActivePageIndex = 9;
        break;
    case 78: // отпуска N78, TabSheet-12, PageIndex-11
        DeloForm -> PageControl1 -> ActivePageIndex = 12;
        break;

    case 82: // приказ на выпуск N82, TabSheet-13, PageIndex-12
        DeloForm -> PageControl1 -> ActivePageIndex = 13;
        break;
    } // end switch

    DeloForm -> Show (); // Показ формы Приказы
}


void __fastcall TMainForm::Open_SpisokForm (int n_menu)
{ // процедура открытия формы для формирования списка

    spisok_f = n_menu;
    // переменная для определения какой пунк меню выбрали из списка
    // ------
    bool found = 0;
    // Переменная для поиска уже открыта или нет форма поис по критериям
    for (int i = 0; i < MDIChildCount; i++)
    { // Цикл для просмотра всех открытых дочерних форм
        if (MDIChildren[i] -> Name == "SpisokAllForm") {
            found = 1;
            break;
        } // Если форма открыта, то переменной присваивается 1
    }
    if (!found) { // Если форма  не найдена, то
        SpisokAllForm = new TSpisokAllForm (this); // Создание формы
        SpisokAllForm -> Show (); // Показ формы
    }
    else
        SpisokAllForm -> Show (); // если найдена, то показ формы
    // -------
    switch (n_menu)
    { // switch  в зависимости от нажатого пункта меню - открываем нужный Query

    case 14: // целевики
        SpisokAllForm -> Caption = "Cписок студентов с целевыми контрактами";
        break;
    case 15: // чернобыльцы
        SpisokAllForm -> Caption = "Cписок студентов с Чернобыльской зоны";
        break;
    case 16: // сироты
        SpisokAllForm -> Caption = "Cписок студентов-сирот";
        break;
    case 17: // платники
        SpisokAllForm -> Caption = "Cписок студентов, обучающихся по договору";
        break;
    case 18: // отчисленные
        SpisokAllForm -> Caption = "Cписок отчисленных студентов";
        break;
    case 19: // иностранные языки
        SpisokAllForm -> Caption =
            "Cписок студентов с указанием иностранного языка";
        break;
    case 20: // иностранные языки
        SpisokAllForm -> Caption = "Cписок студентов инвалидов";
        break;
    case 21: // общежитие
        SpisokAllForm -> Caption = "Cписок студентов, проживающих в общежитии";
        break;
    } // switch  в зависимости от нажатого пункта меню - открываем нужный Query

    // ----очищение содержимого   StringGrid
    for (int i = 0; i < SpisokAllForm -> StringGrid1 -> ColCount; i++)
    { // for  StringGrid1 -> RowCount
        for (int j = 0; j < SpisokAllForm -> StringGrid1 -> RowCount + 1; j++)
        { // for  StringGrid1 -> RowCount
            SpisokAllForm -> StringGrid1 -> Cells[i][j] = "";
        } // end for  StringGrid1 -> RowCount
    } // end for  StringGrid1 -> ColCount

    SpisokAllForm -> Panel2 -> Visible = false;
    SpisokAllForm -> Panel3 -> Visible = false;
    SpisokAllForm -> Height = 118;
    if (SpisokAllForm -> Position != poMainFormCenter)
        SpisokAllForm -> Position = poMainFormCenter;

}


void __fastcall TMainForm::Open_PrivilegeForm (int n_menu)
{ // процедура открытия формы для формирования справок инвалидов, сирот, ЧАЭС

    spisok_f1 = n_menu;
    // переменная для определения какой пунк меню выбрали из списка
    // ------
    bool found = 0; // Переменная для поиска уже открыта или нет форма
    for (int i = 0; i < MDIChildCount; i++)
    { // Цикл для просмотра всех открытых дочерних форм
        if (MDIChildren[i] -> Name == "PrivilegeForm") {
            found = 1;
            break;
        } // Если форма открыта, то переменной присваивается 1
    }
    if (!found) { // Если форма  не найдена, то
        PrivilegeForm = new TPrivilegeForm (this); // Создание формы
        PrivilegeForm -> DateTimePicker1 -> Date = Now ();
        PrivilegeForm -> DateTimePicker1 -> Time = StrToTime ("00:00");
        PrivilegeForm -> DateTimePicker2 -> Date = Now ();
        PrivilegeForm -> DateTimePicker1 -> Time = StrToTime ("00:00");
        PrivilegeForm -> DateTimePicker3 -> Date = Now ();
        PrivilegeForm -> DateTimePicker1 -> Time = StrToTime ("00:00");
        PrivilegeForm -> Show (); // Показ формы
    }
    else
        PrivilegeForm -> Show (); // если найдена, то показ формы
    // -------
    switch (n_menu)
    { // switch  в зависимости от нажатого пункта меню - открываем нужный Query

    case 67: // инвалиды
        PrivilegeForm -> Caption = "Добавление справок студентов-инвалидов";
        break;
    case 68: // чернобыльцы
        PrivilegeForm -> Caption =
            "Добавление справок студентов с Чернобыльской зоны";
        break;
    case 69: // сироты
        PrivilegeForm -> Caption = "Добавление справок студентов-сирот";
        break;

    } // switch  в зависимости от нажатого пункта меню - открываем нужный Query

    // ---- Очищение на форме
    PrivilegeForm -> RadioGroup1 -> ItemIndex = -1;

    PrivilegeForm -> RadioGroup2 -> ItemIndex = -1;
    PrivilegeForm -> DBGrid1 -> Visible = false;
    PrivilegeForm -> GroupBox1 -> Visible = false;

    PrivilegeForm -> Panel2 -> Visible = false;
    PrivilegeForm -> Panel3 -> Visible = false;
    PrivilegeForm -> Panel4 -> Visible = false;

    DataModule1 -> People_SpravkiFDQuery -> Close ();
    DataModule1 -> Priv_AddFDQuery -> Close ();

    PrivilegeForm -> Height = 213;
    // ----

}


void __fastcall TMainForm::Create_Spisok () {
    // для одного листа
    WSheet = NewSheet1 (ExcelApp);

    if ( (DataModule1 -> Spisoc_All_StudFDQueryVID_EDU -> AsVariant.IsNull ()) &&
        (vid_e == 0))
        v_e = "дн";
    if ( (DataModule1 -> Spisoc_All_StudFDQueryVID_EDU -> AsVariant.IsNull ()) &&
        (vid_e == 1))
        v_e = "з";
    if (DataModule1 -> Spisoc_All_StudFDQueryVID_EDU -> Value == 0)
        v_e = "дн";
    if (DataModule1 -> Spisoc_All_StudFDQueryVID_EDU -> Value == 1)
        v_e = "з";

    n_gr = DataModule1 -> Spisoc_All_StudFDQueryN_GROUP -> Value;
    if (n_gr == "000") {
        NameSheet1 (WSheet, "Академ-отпуск");
        SelectSheet (WBook, "Академ-отпуск");
        // Занесение номера группы на лист
        CellValue ("Студенты, находящиеся в академическом отпуске", 1, 1);
    }
    else {
        NameSheet1 (WSheet, n_gr + v_e);
        SelectSheet (WBook, n_gr + v_e);
        // Занесение номера группы на лист
        CellValue ("Группа " + n_gr + v_e, 1, 1);
    }

    Variant C1 = SelectCell (1, 1);
    Variant C2 = SelectCell (9, 1);
    Variant R = Range_Range (WSheet, C1, C2);
    M1 (R);
    HorizontalAlign (R, 3);
    CellFont ("Arial", 14, true, false, 1, 0, R);
    // ----
    // Занесение шапки таблицы
    CellValue ("№ п/п", 1, 3);
    BorderCell (1, 3, 1, 2);
    CellValue ("ФИО", 2, 3);
    BorderCell (2, 3, 1, 2);
    if (nom_fac != 4)
        CellValue ("Направление специальности", 3, 3);
    else
        CellValue ("Cпециальность/Специализация", 3, 3);
    BorderCell (3, 3, 1, 2);
    CellValue ("Пол", 4, 3);
    BorderCell (4, 3, 1, 2);
    CellValue ("Дата рождения", 5, 3);
    BorderCell (5, 3, 1, 2);
    CellValue ("Вид спорта, разряд", 6, 3);
    BorderCell (6, 3, 1, 2);
    CellValue ("Откуда прибыл", 7, 3);
    BorderCell (7, 3, 1, 2);
    CellValue ("Основание зачисления", 8, 3);
    BorderCell (8, 3, 1, 2);
    CellValue ("Телефон", 9, 3);
    BorderCell (9, 3, 1, 2);
    CellValue ("Примечания", 10, 3);
    BorderCell (10, 3, 1, 2);
    C1 = SelectCell (1, 3);
    if (n_gr == "000") {
        CellValue ("№ гр.", 11, 3);
        BorderCell (11, 3, 1, 2);
        C2 = SelectCell (11, 3);
    }
    else {
        C2 = SelectCell (10, 3);
    }
    R = Range_Range (WSheet, C1, C2);
    HorizontalAlign (R, 3);
    VerticalAlign (R, 2);
    CellFont ("Arial", 12, true, false, 1, 0, R);
    // ----
    // занесение данных

    int n_st = 4; // переменная для номера строки
    while (n_gr == DataModule1 -> Spisoc_All_StudFDQueryN_GROUP -> Value) {
        n_stud = DataModule1 -> Spisoc_All_StudFDQueryNOMER -> Value;
        CellValue (AnsiString (n_st - 3), 1, n_st);
        BorderCell (1, n_st, 1, 2);
        CellValue (DataModule1 -> Spisoc_All_StudFDQueryFAM -> Value + " " +
            DataModule1 -> Spisoc_All_StudFDQueryNAME -> Value + " " +
            DataModule1 -> Spisoc_All_StudFDQueryOTCH -> Value, 2, n_st);
        BorderCell (2, n_st, 1, 2);
        CellValue (DataModule1 -> Spisoc_All_StudFDQuerySPECIAL -> Value, 3, n_st);
        BorderCell (3, n_st, 1, 2);
        CellValue (DataModule1 -> Spisoc_All_StudFDQueryPOL -> Value, 4, n_st);
        BorderCell (4, n_st, 1, 2);
        CellValue (SQLTimeStampToDateTime
            (DataModule1 -> Spisoc_All_StudFDQueryDATA_R -> Value), 5, n_st);
        BorderCell (5, n_st, 1, 2);
        vid_razr = DataModule1 -> Spisoc_All_StudFDQueryVID_SPORT -> Value + " " +
            DataModule1 -> Spisoc_All_StudFDQueryTEXT_SPORT_CATEGORY -> Value;
        CellValue (DataModule1 -> Spisoc_All_StudFDQueryADDRESS_BEFORE -> Value,
            7, n_st);
        BorderCell (7, n_st, 1, 2);
        CellValue (DataModule1 -> Spisoc_All_StudFDQueryVID_FOUND -> Value, 8, n_st);
        BorderCell (8, n_st, 1, 2);
        CellValue (DataModule1 -> Spisoc_All_StudFDQueryPHONE -> Value, 9, n_st);
        BorderCell (9, n_st, 1, 2);
        if (n_gr == "000")
        { // занесение номера группы для студентов академистов
            DataModule1 -> PeopleFDQuery -> Close ();
            DataModule1 -> PeopleFDQuery -> SQL -> Clear ();
            int count = DataModule1 -> PeopleFDQuery -> SQL -> Add
                ("SELECT COUNT (*) FROM PEOPLE WHERE N_GROUP=000");
            // количество студентов академистов
            if (count != 0) {
                DataModule1 -> PeopleFDQuery -> SQL -> Add
                    ("SELECT * FROM PEOPLE WHERE (STATUS_PEOPLE in (3,4)) AND (N_FAC=" +
                    AnsiString (nom_fac) + ") ORDER BY FAM");
                DataModule1 -> PeopleFDQuery -> Open ();
                // AnsiString nomer_grupp=DataModule1 -> PeopleQuery -> Lookup ("NOMER",DataModule1 -> Spisoc_All_StudQueryNOMER -> Value,"N_GROUP");
                Variant nomer_grupp =
                    DataModule1 -> PeopleFDQuery -> Lookup ("NOMER", n_stud,
                    "N_GROUP");
                CellValue (nomer_grupp.AsType (varString), 10, n_st);
                BorderCell (11, n_st, 1, 2);
                DataModule1 -> PeopleFDQuery -> Close ();
            }
        }
        switch (DataModule1 -> Spisoc_All_StudFDQuerySTATUS_PEOPLE -> Value) {
        case 1:
            // CellValue ("Действующий",9,n_st);
            BorderCell (10, n_st, 1, 2);
            break;
        case 3:
            CellValue ("Академ. отпуск", 9, n_st);
            BorderCell (10, n_st, 1, 2);
            break;
        case 4:
            CellValue ("Повтор.год обуч.", 9, n_st);
            BorderCell (10, n_st, 1, 2);
            break;
        }
        if (!DataModule1 -> Spisoc_All_StudFDQuery -> Eof)
            DataModule1 -> Spisoc_All_StudFDQuery -> Next ();
        else {
            return;
        }
        while (n_stud == DataModule1 -> Spisoc_All_StudFDQueryNOMER -> Value) {
            if (!DataModule1 -> Spisoc_All_StudFDQuery -> Eof) {
                vid_razr +=
                    " " + DataModule1 -> Spisoc_All_StudFDQueryVID_SPORT -> Value +
                    " " + DataModule1 -> 
                    Spisoc_All_StudFDQueryTEXT_SPORT_CATEGORY -> Value;
                DataModule1 -> Spisoc_All_StudFDQuery -> Next ();
            }
            else {
                CellValue (vid_razr, 6, n_st);
                BorderCell (6, n_st, 1, 2);
                for (int i = 1; i < 10; i++) {
                    AutoFitColumn (WSheet, i);
                }

                return;
            }

        }

        CellValue (vid_razr, 6, n_st);
        BorderCell (6, n_st, 1, 2);
        n_st++;
    } // пока одинаковый номер группы
    // ------
    for (int i = 1; i < 12; i++) {
        AutoFitColumn (WSheet, i);
    }

    // для одного листа
}


bool __fastcall TMainForm::SearchChild (AnsiString FormName) {
    for (int i = 0; i < MDIChildCount; i++)
        // Цикл для просмотра всех открытых дочерних форм
        if (MDIChildren[i] -> Name == FormName)
            return true; // Если форма открыта
    return false; // Если форма не найдена
}


void __fastcall TMainForm::N1Click (TObject *Sender)
    // Вызов формы "Справочники" из меню
{
    bool found = 0;
    // Переменная для поиска уже открыта или нет форма Справочники
    for (int i = 0; i < MDIChildCount; i++)
    { // Цикл для просмотра всех открытых дочерних форм
        if (MDIChildren[i] -> Name == "SpravForm") {
            found = 1;
            break;
        } // Если форма Справочники открыта, то переменной присваивается 1
    }
    if (!found) { // Если форма Справочники не найдена, то
        /* SpravForm = new TSpravForm (this);//Создание формы Справочники
         SpravForm -> Show ();  //Показ формы Справочники */
        PassDlg = new TPassDlg (this);
        PassDlg -> ShowModal ();
    }
    else
        SpravForm -> Show (); // если найдена, то показ формы

}


void __fastcall TMainForm::N6Click (TObject *Sender)
    // Вызов формы "О программе" из меню
{
    AboutBox = new TAboutBox (this);
    AboutBox -> ShowModal ();
}


void __fastcall TMainForm::N8Click (TObject *Sender)
    // Вызов формы "Приказы" из меню Делопроизводство
{
    /*
     void __fastcall  TMainForm::prikaz_search (int n_menu)
     { //процедура поиска активной страницы на форме приказов
     bool found=0; //Переменная для поиска уже открыта или нет форма Приказы
     for (int i = 0; i < MDIChildCount; i++)
     { //for      //Цикл для просмотра всех открытых дочерних форм
     if (MDIChildren[i] -> Name=="DeloForm")
     { found=1;break;} //Если форма Приказы открыта, то переменной присваивается 1
     } //end for
     if (!found){ //Если форма Приказы не найдена, то
     DeloForm = new TDeloForm (this);} //Создание формы Приказы

     switch (n_menu)
     {//switch  в зависимости от нажатого пункта меню - делаем определенную
     //страницу открытой
     case 35:  //академ.отпуск N35, TabSheet-6, PageIndex-5
     DeloForm -> PageControl1 -> ActivePageIndex=5;
     break;
     case 36:  //повторный год N36, TabSheet-7, PageIndex-6
     DeloForm -> PageControl1 -> ActivePageIndex=6;
     break;
     case 37:  //изменение фамилии N37, TabSheet-4, PageIndex-4
     DeloForm -> PageControl1 -> ActivePageIndex=4;
     break;
     case 39:  //отчисление N39, TabSheet-2, PageIndex-2
     DeloForm -> PageControl1 -> ActivePageIndex=2;
     break;
     case 40:  //восстановление N40, TabSheet-3, PageIndex-3
     DeloForm -> PageControl1 -> ActivePageIndex=3;
     break;
     case 42:  //перевод на след.курс N42, TabSheet-1, PageIndex-0
     DeloForm -> PageControl1 -> ActivePageIndex=0;
     break;
     case 43:  //перевод задолженников N43, TabSheet-5, PageIndex-1
     DeloForm -> PageControl1 -> ActivePageIndex=1;
     break;
     case 45:  //Перевод N45, TabSheet-9, PageIndex-8
     DeloForm -> PageControl1 -> ActivePageIndex=8;
     break;
     case 46:  //Поощрения/Взыскания N46, TabSheet-8, PageIndex-7
     DeloForm -> PageControl1 -> ActivePageIndex=7;
     break;
     case 48:  //Приказ на допуск к Гос или диплом N48, TabSheet-11, PageIndex-10
     DeloForm -> PageControl1 -> ActivePageIndex=10;
     break;
     case 49:  //Диплом (приказ о выпуске) N49, TabSheet-10, PageIndex-9
     DeloForm -> PageControl1 -> ActivePageIndex=9;
     break;
     }//end switch


     DeloForm -> Show ();  // Показ формы Приказы



     }
     //---------
     */
}


void __fastcall TMainForm::FormClose (TObject *Sender, TCloseAction &Action)
{ // При закрытии формы
    // Диалоговое окно
    // !!!if (Application -> MessageBox ("    Закрыть программу?", "", MB_YESNO) == mrYes)
    if (MessageDlg ("    Закрыть программу?", mtConfirmation,
        TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes) {
        // DM2 -> IBTransaction1 -> Commit ();
        Action = caFree; // Закрытие программы
    }
    else
        Action = caNone;
}


void __fastcall TMainForm::N11Click (TObject *Sender)
{ // Выход из программы при выборе в меню пункта Выход
    Close ();
}


void __fastcall TMainForm::FormCreate (TObject *Sender) { // При создании формы

    LoadKeyboardLayout ("00000419", KLF_ACTIVATE); // Русская

    FormatSettings.DateSeparator = '.'; // Устанвка разделителя даты
    FormatSettings.ShortDateFormat = "dd.mm.yyyy"; // Устанвка формата даты
    // определение даты и учебного года
    Data_Refresh ();
}

// --------------------------------------------------------------------------
void __fastcall TMainForm::Data_Refresh ()
{ // переопределение даты и учебного года
    AnsiString data_cur = "", year_cur = "";
    TDateTime ddd;
    data_cur += "Сегодня " + DateToStr (ddd.CurrentDate ()) + " ";
    TDateTime fff = ddd.CurrentDate ();
    switch (fff.DayOfWeek ()) {
    case 1:
        data_cur += "воскресенье";
        break;
    case 2:
        data_cur += "понедельник";
        break;
    case 3:
        data_cur += "вторник";
        break;
    case 4:
        data_cur += "среда";
        break;
    case 5:
        data_cur += "четверг";
        break;
    case 6:
        data_cur += "пятница";
        break;
    case 7:
        data_cur += "суббота";
        break;

    }
    // Panel1 -> Caption=data_cur;
    int mon = DateToStr (fff).SubString (4, 2).ToInt ();
    if (mon > 7)
        year_cur = DateToStr (fff).SubString (7, 4) + "/ " +
            AnsiString (DateToStr (fff).SubString (7, 4).ToInt () + 1);
    else
        year_cur = AnsiString (DateToStr (fff).SubString (7, 4).ToInt () - 1) +
            "/ " + DateToStr (fff).SubString (7, 4);
    Label1 -> Caption = data_cur;
    Label2 -> Caption = "Учебный год " + year_cur;
    uch_god = year_cur.SubString (1, 4).ToInt ();

}


void __fastcall TMainForm::N14Click (TObject *Sender) {
    if (!OpenChildForm (MainForm, Edu_planForm)) {
        Edu_planForm = new TEdu_planForm (this); // Создание формы
        Edu_planForm -> Show (); // Показ формы
    }
}


void __fastcall TMainForm::N13Click (TObject *Sender) {

    if (!OpenChildForm (MainForm, Result_VedForm)) {
        Result_VedForm = new TResult_VedForm (this); // Создание формы
        DataModule1 -> Ball_FDQuery -> Close ();
        Result_VedForm -> DateTimePicker1 -> Date = Now ();
        Result_VedForm -> DateTimePicker1 -> Time = StrToTime ("00:00");
        Result_VedForm -> Show (); // Показ формы
    }
    /*
     Result_VedForm=new TResult_VedForm (this);
     DataModule1 -> Ball_Query -> Close ();
     Result_VedForm -> ShowModal (); */
}


void __fastcall TMainForm::N12Click (TObject *Sender) {
    Ved_Form = new TVed_Form (this); // Создание формы Формирование ведомости
    Ved_Form -> ShowModal (); // Показ формы Формирование ведомости
}


void __fastcall TMainForm::N17Click (TObject *Sender) {
    status_people_query = 1;
    if (!OpenChildForm (MainForm, StudForm)) {
        StudForm = new TStudForm (this); // Создание формы
        StudForm -> PageControl1 -> ActivePageIndex = 0;
        StudForm -> Show (); // Показ формы
    }

}


void __fastcall TMainForm::N16Click (TObject *Sender) {
    if (!OpenChildForm (MainForm, SpisocForm)) {
        SpisocForm = new TSpisocForm (this); // Создание формы
        SpisocForm -> Show (); // Показ формы
    }
}


void __fastcall TMainForm::N18Click (TObject *Sender) {
    All_StatisticForm = new TAll_StatisticForm (this);

    All_StatisticForm -> Height = All_StatisticForm -> Height -
        All_StatisticForm -> Panel2 -> Height;
    All_StatisticForm -> ShowModal ();
}


void __fastcall TMainForm::N19Click (TObject *Sender) {
    if (!OpenChildForm (MainForm, SpavkiForm)) {
        SpavkiForm = new TSpavkiForm (this); // Создание формы
        SpavkiForm -> Show (); // Показ формы
    }

}


void __fastcall TMainForm::Spisok () {
    ExcelApp = Variant::CreateObject ("Excel.Application");
    ColWorkSheet (ExcelApp, (Variant)1);
    WBook = NewBook (ExcelApp);

    WSheet = SelectSheet (WBook, "Лист1");
    // OVisible (ExcelApp);

    DataModule1 -> Spisoc_All_StudFDQuery -> ParamByName ("N_F") -> Value = nom_fac;
    DataModule1 -> Spisoc_All_StudFDQuery -> ParamByName ("V_E") -> Value = vid_e;
    DataModule1 -> Spisoc_All_StudFDQuery -> Open ();

    while (!DataModule1 -> Spisoc_All_StudFDQuery -> Eof) {
        Create_Spisok ();
    }

    DataModule1 -> Spisoc_All_StudFDQuery -> Close ();
    if (!vid_e)
        v_e = "дн";
    else
        v_e = "з";

    AnsiString name_f = "Список студентов (" + v_e +
        ") по группам факультета " + DM2 -> FacultyFDTable -> Lookup ("N_FAC",
        nom_fac, "FAC1") + " за " + DateToStr (cur_d ()) + ".xls";
    Variant WorkSaveAs = SaveBookAs (WBook, "d:\\Мои документы\\" + name_f);
    OVisible (ExcelApp);
}


void __fastcall TMainForm::N22Click (TObject *Sender) {
    vid_e = 0;
    Spisok ();
}


void __fastcall TMainForm::N23Click (TObject *Sender) {
    vid_e = 1;
    Spisok ();
}


void __fastcall TMainForm::N24Click (TObject *Sender) {
    Session_Form = new TSession_Form (this); // Создание формы Итоги сессии
    Session_Form -> ShowModal (); // Показ формы Итоги сессии
}


void __fastcall TMainForm::N25Click (TObject *Sender) {

    Semestr_sessionForm = new TSemestr_sessionForm (this);
    // Создание формы Итоги сессии по семестру
    Semestr_sessionForm -> Caption = "Итоговая по семестру";
    Semestr_sessionForm -> ComboBox1 -> ItemIndex = -1;
    Semestr_sessionForm -> ComboBox2 -> ItemIndex = -1;
    Semestr_sessionForm -> ComboBox2 -> Visible = true;
    Semestr_sessionForm -> Label2 -> Visible = true;
    Semestr_sessionForm -> BitBtn1 -> Visible = true;
    Semestr_sessionForm -> BitBtn2 -> Visible = false;
    Semestr_sessionForm -> Panel1 -> Visible = true;
    Semestr_sessionForm -> Panel2 -> Visible = false;
    Semestr_sessionForm -> Height = 184;
    Semestr_sessionForm -> ShowModal (); // Показ формы Итоги сессии по семестру
}


void __fastcall TMainForm::N26Click (TObject *Sender) {
    Semestr_sessionForm = new TSemestr_sessionForm (this);
    // Создание формы Итоги сессии за год
    Semestr_sessionForm -> Caption = "Итоговая за год";
    Semestr_sessionForm -> ComboBox1 -> ItemIndex = -1;
    Semestr_sessionForm -> ComboBox2 -> ItemIndex = -1;
    Semestr_sessionForm -> ComboBox2 -> Visible = false;
    Semestr_sessionForm -> Label2 -> Visible = false;
    Semestr_sessionForm -> BitBtn1 -> Visible = false;
    Semestr_sessionForm -> BitBtn2 -> Visible = true;
    Semestr_sessionForm -> Panel1 -> Visible = false;
    Semestr_sessionForm -> Panel2 -> Visible = true;
    Semestr_sessionForm -> Height = 184;
    Semestr_sessionForm -> ShowModal (); // Показ формы Итоги сессии за год
}

/*
 void __fastcall TMainForm::RxLoginDialog1CheckUser (TObject *Sender,
 const AnsiString UserName, const AnsiString Password,
 bool &AllowLogin)
 {
 TLocateOptions flags;
 if (DM2 -> Table1 -> Locate ("USER_NAME",UserName,flags))
 {
 Us_Pas=DM2 -> Table1 -> Lookup ("USER_NAME",UserName,"USER_PASSWORD");
 if (Us_Pas==Password)
 {
 Us_Name=DM2 -> Table1 -> FieldByName ("USER_NAME") -> AsString;
 nom_fac=DM2 -> Table1 -> FieldByName ("N_FAC") -> AsInteger;
 DM2 -> SpecializTable -> Filter="N_FAC="+AnsiString (nom_fac);
 DM2 -> SpecializTable -> Filtered=true;
 AllowLogin=true;
 }
 else
 {
 ShowMessage ("Неверный пароль");
 AllowLogin=false;
 }
 }
 else
 {
 ShowMessage ("Неверное имя пользователя");
 AllowLogin=false;
 }



 } */


void __fastcall TMainForm::FormActivate (TObject *Sender) {
    MainForm -> Caption = "ДЕКАНАТ (v." + DM2 -> get_version () + ") - " +
        DM2 -> FacultyFDTable -> Lookup ("N_FAC", nom_fac, "FAC1") + " - " +
        DataModule1 -> testDB_str;
}


void __fastcall TMainForm::N27Click (TObject *Sender) {
    /* SpisocForm=new TSpisocForm (this);
     SpisocForm -> Show (); */

    if (!OpenChildForm (MainForm, SpisocForm)) {
        SpisocForm = new TSpisocForm (this); // Создание формы
        SpisocForm -> Show (); // Показ формы
    }

}


void __fastcall TMainForm::N29Click (TObject *Sender) {
    /*

     if (Application -> MessageBox ("    Воспользоваться старым вариантом сводной ведомости?", "", MB_YESNO) == mrYes)
     {
     Svod_Ved = new TSvod_Ved (this); //Создание формы для формирования сводной ведомости
     Vibor=1;  //Переключатель на сводную ведомоть
     Svod_Ved -> Label1 -> Visible=false;
     Svod_Ved -> DateEdit1 -> Visible=false; //дата вручения диплома
     Svod_Ved -> Show ();         //Показ формы для формирования сводной ведомости
     }
     else
     { */

    if (!OpenChildForm (MainForm, DiplomForm)) {
        DiplomForm = new TDiplomForm (this); // Создание формы
        DiplomForm -> DateTimePicker1 -> Date = Now ();
        DiplomForm -> DateTimePicker1 -> Time = StrToTime ("00:00");
        DiplomForm -> Show (); // Показ формы
    }
    // }
}


void __fastcall TMainForm::N31Click (TObject *Sender) {
    /*

     if (Application -> MessageBox ("    Воспользоваться старым вариантом выписки?", "", MB_YESNO) == mrYes)
     {
     Svod_Ved = new TSvod_Ved (this); //Создание формы для формирования выписки
     Svod_Ved -> Caption="Формирование выписки к диплому";
     Svod_Ved -> Label1 -> Visible=true;
     Svod_Ved -> DateEdit1 -> Visible=true; //дата вручения диплома
     Vibor=2;  //Переключатель на выписку
     Svod_Ved -> Show ();         //Показ формы для выписки
     }
     else
     { */

    if (!OpenChildForm (MainForm, DiplomForm)) {
        DiplomForm = new TDiplomForm (this); // Создание формы
        DiplomForm -> DateTimePicker1 -> Date = Now ();
        DiplomForm -> DateTimePicker1 -> Time = StrToTime ("00:00");
        DiplomForm -> Show (); // Показ формы
    }
    // }

}


void __fastcall TMainForm::N32Click (TObject *Sender) {
    Vipusk_Stud = new TVipusk_Stud (this);
    // Создание формы для выпуска студентов
    Vipusk_Stud -> ShowModal (); // Показ формы для выпуска студенто

}


void __fastcall TMainForm::N33Click (TObject *Sender)
{ // Ведомости государственных экзаменов
    if (!OpenChildForm (MainForm, Ved_GEK)) {
        Ved_GEK = new TVed_GEK (this);
        // Создание формы для формирования ведомости
        Ved_GEK -> Show (); // Показ формы ведомости
    }
}


void __fastcall TMainForm::N34Click (TObject *Sender)
{ // Результаты государственных экзаменов

    if (!OpenChildForm (MainForm, VED_GEKResult)) {
        VED_GEKResult = new TVED_GEKResult (this);
        // Создание формы для формирования ведомости
        VED_GEKResult -> Show (); // Показ формы ведомости
    }
}


void __fastcall TMainForm::N35Click (TObject *Sender) { // академический отпуск
    prikaz_search (35);
}


void __fastcall TMainForm::N36Click (TObject *Sender) { // Повторный год обучения
    prikaz_search (36);
}


void __fastcall TMainForm::N37Click (TObject *Sender) { // Изменение фамилии
    prikaz_search (37);
}


void __fastcall TMainForm::N45Click (TObject *Sender) { // Перевод
    prikaz_search (45);
}


void __fastcall TMainForm::N39Click (TObject *Sender) { // Отчисление
    prikaz_search (39);
}


void __fastcall TMainForm::N40Click (TObject *Sender) { // Восстановление
    prikaz_search (40);
}


void __fastcall TMainForm::N42Click (TObject *Sender)
{ // Перевод на следующий курс
    prikaz_search (42);
}


void __fastcall TMainForm::N43Click (TObject *Sender) { // Перевод задолженников
    prikaz_search (43);
}


void __fastcall TMainForm::N46Click (TObject *Sender) { // Поощрения/Взыскания
    prikaz_search (46);
}


void __fastcall TMainForm::N48Click (TObject *Sender)
{ // Приказ на допуск к ГОСу или диплому
    prikaz_search (48);
}


void __fastcall TMainForm::N49Click (TObject *Sender) { // Диплом
    prikaz_search (49);
}


void __fastcall TMainForm::N50Click (TObject *Sender) {
    InfoForm = new TInfoForm (this);
    InfoForm -> ShowModal ();
}


void __fastcall TMainForm::N52Click (TObject *Sender) {
    if (!OpenChildForm (MainForm, Prikaz_LikvidForm)) {
        Prikaz_LikvidForm = new TPrikaz_LikvidForm (this); // Создание формы
        Prikaz_LikvidForm -> DateTimePicker1 -> Date = Now ();
        Prikaz_LikvidForm -> DateTimePicker1 -> Time = StrToTime ("00:00");
        Prikaz_LikvidForm -> DateTimePicker2 -> Date = Now () + 10;
        Prikaz_LikvidForm -> DateTimePicker2 -> Time = StrToTime ("00:00");
        Prikaz_LikvidForm -> DateTimePicker3 -> Date = Now () + 10;
        Prikaz_LikvidForm -> DateTimePicker3 -> Time = StrToTime ("00:00");
        Prikaz_LikvidForm -> Show (); // Показ формы
    }
    Prikaz_LikvidForm -> Height = 101;
}


void __fastcall TMainForm::N54Click (TObject *Sender) {
    Ved_LikvidForm = new TVed_LikvidForm (this);
    Ved_LikvidForm -> Caption = "Список ведомостей за период с " +
        DateToStr (curent_date - 10) + " по " + DateToStr (curent_date + 30);
    Ved_LikvidForm -> ShowModal ();
}


void __fastcall TMainForm::N56Click (TObject *Sender) {
    Ved_RatingForm = new TVed_RatingForm (this);
    Ved_RatingForm -> Caption = "Список ведомостей рейтинга за " +
        IntToStr (uch_god) + "/" + IntToStr (uch_god + 1) + " учебный год";
    Ved_RatingForm -> ShowModal ();
}


void __fastcall TMainForm::N57Click (TObject *Sender) {
    Result_Ball_RatingForm = new TResult_Ball_RatingForm (this);
    Result_Ball_RatingForm -> ShowModal ();

}


void __fastcall TMainForm::N58Click (TObject *Sender) {
    Result_RatingForm = new TResult_RatingForm (this);
    Result_RatingForm -> ShowModal ();

}


void __fastcall TMainForm::N4Click (TObject *Sender) {

    Application -> HelpFile = "DEKANAT.HLP";
    Application -> HelpCommand (HELP_CONTENTS, 0);

}


void __fastcall TMainForm::N53Click (TObject *Sender) {
    PeopleVedForm = new TPeopleVedForm (this);
    PeopleVedForm -> ShowModal ();
}


void __fastcall TMainForm::N60Click (TObject *Sender) {
    // Целевики
    Open_SpisokForm (14);
}


void __fastcall TMainForm::N61Click (TObject *Sender) { // Чернобыльцы
    Open_SpisokForm (15);

}


void __fastcall TMainForm::N62Click (TObject *Sender) { // Сироты
    Open_SpisokForm (16);

}


void __fastcall TMainForm::N63Click (TObject *Sender) { // Платники
    Open_SpisokForm (17);

}


void __fastcall TMainForm::N64Click (TObject *Sender) {
    // Отчисленные
    Open_SpisokForm (18);
}


void __fastcall TMainForm::N65Click (TObject *Sender) {
    // Иностранные языки
    Open_SpisokForm (19);
}


void __fastcall TMainForm::N66Click (TObject *Sender) {
    // Инвалиды
    Open_SpisokForm (20);
}


void __fastcall TMainForm::N67Click (TObject *Sender) { // Справки Инвалидов
    Open_PrivilegeForm (67);
}


void __fastcall TMainForm::N68Click (TObject *Sender) { // Справки   ЧАЭС
    Open_PrivilegeForm (68);
}


void __fastcall TMainForm::N69Click (TObject *Sender) { // Справки   сирот
    Open_PrivilegeForm (69);
}


void __fastcall TMainForm::N70Click (TObject *Sender) {
    if (!OpenChildForm (MainForm, DiplomForm)) {
        DiplomForm = new TDiplomForm (this); // Создание формы
        DiplomForm -> DateTimePicker1 -> Date = Now ();
        DiplomForm -> DateTimePicker1 -> Time = StrToTime ("00:00");
        DiplomForm -> Show (); // Показ формы
    }
}


void __fastcall TMainForm::N71Click (TObject *Sender) {
    if (!OpenChildForm (MainForm, NK_3Form)) {
        NK_3Form = new TNK_3Form (this); // Создание формы
        NK_3Form -> Show (); // Показ формы
    }
    NK_3Form -> Caption = "Распределение студентов по возрасту";
    // уменьшение формы
    NK_3Form -> Form_Min ();
    NK_3Form -> BitBtn1 -> Visible = true;
    NK_3Form -> BitBtn1 -> Left = 360;
    NK_3Form -> BitBtn3 -> Visible = false;
    NK_3Form -> BitBtn4 -> Visible = false;
    NK_3Form -> BitBtn5 -> Visible = false;
    NK_3Form -> BitBtn6 -> Visible = false;
    NK_3Form -> BitBtn7 -> Visible = false;
    NK_3Form -> BitBtn8 -> Visible = false;
}


void __fastcall TMainForm::N72Click (TObject *Sender) {
    N71Click (this);
    NK_3Form -> Caption = "Распределение студентов по специальностям";
    NK_3Form -> BitBtn1 -> Visible = false;
    NK_3Form -> BitBtn3 -> Visible = true;
    NK_3Form -> BitBtn3 -> Left = 360;
    NK_3Form -> BitBtn4 -> Visible = false;
    NK_3Form -> BitBtn5 -> Visible = false;
    NK_3Form -> BitBtn6 -> Visible = false;
    NK_3Form -> BitBtn7 -> Visible = false;
    NK_3Form -> BitBtn8 -> Visible = false;
}


void __fastcall TMainForm::N73Click (TObject *Sender) {
    N71Click (this);
    NK_3Form -> Caption = "Распределение студентов по форме оплаты";
    NK_3Form -> BitBtn1 -> Visible = false;
    NK_3Form -> BitBtn3 -> Visible = false;
    NK_3Form -> BitBtn4 -> Visible = true;
    NK_3Form -> BitBtn4 -> Left = 360;
    NK_3Form -> BitBtn5 -> Visible = false;
    NK_3Form -> BitBtn6 -> Visible = false;
    NK_3Form -> BitBtn7 -> Visible = false;
    NK_3Form -> BitBtn8 -> Visible = false;
}


void __fastcall TMainForm::SpeedButton1Click (TObject *Sender)
{ // переопределить дату
    // Как отобразить Диспетчер Задач?
    // SendMessage (HWND_BRODCAST,WM_SYSCOMMAND,SC_TASKLIST,-1);

    // "поиск" часов
    // HWND hClockWnd = FindWindowEx (FindWindowEx (FindWindowEx (NULL,NULL,"Shell_TrayWnd",NULL),NULL,"TrayNotifyWnd",NULL),NULL,"TrayClockWClass",NULL);
    // if (hClockWnd) //ShowWindow (hClockWnd,SW_SHOW); // прячем сами часы

    // запустить браузер по умолчанию с указанной страницей:
    // ShellExecute (Handle, "Open", (hClockWnd, NULL, NULL, SW_SHOW));

    Data_Refresh ();
    ShowMessage ("Изменилась системная дата!");
}


void __fastcall TMainForm::N74Click (TObject *Sender) {
    N71Click (this);
    NK_3Form -> Caption = "Распределение выпускников по специальностям";
    NK_3Form -> BitBtn1 -> Visible = false;
    NK_3Form -> BitBtn3 -> Visible = false;
    NK_3Form -> BitBtn4 -> Visible = false;
    NK_3Form -> BitBtn5 -> Visible = true;
    NK_3Form -> BitBtn5 -> Left = 360;
    NK_3Form -> BitBtn6 -> Visible = false;
    NK_3Form -> BitBtn7 -> Visible = false;
    NK_3Form -> BitBtn8 -> Visible = false;
}


void __fastcall TMainForm::N75Click (TObject *Sender) {
    N71Click (this);
    NK_3Form -> Caption = "На условиях целевой подготовки";
    NK_3Form -> BitBtn1 -> Visible = false;
    NK_3Form -> BitBtn3 -> Visible = false;
    NK_3Form -> BitBtn4 -> Visible = false;
    NK_3Form -> BitBtn5 -> Visible = false;
    NK_3Form -> BitBtn6 -> Visible = true;
    NK_3Form -> BitBtn6 -> Left = 360;
    NK_3Form -> BitBtn7 -> Visible = false;
    NK_3Form -> BitBtn8 -> Visible = false;
}


void __fastcall TMainForm::N76Click (TObject *Sender) {
    N71Click (this);
    NK_3Form -> Caption = "По сокращенному сроку обучения";
    NK_3Form -> BitBtn1 -> Visible = false;
    NK_3Form -> BitBtn3 -> Visible = false;
    NK_3Form -> BitBtn4 -> Visible = false;
    NK_3Form -> BitBtn5 -> Visible = false;
    NK_3Form -> BitBtn6 -> Visible = false;
    NK_3Form -> BitBtn7 -> Visible = true;
    NK_3Form -> BitBtn7 -> Left = 360;
    NK_3Form -> BitBtn8 -> Visible = false;
}


void __fastcall TMainForm::N77Click (TObject *Sender) {
    if (!OpenChildForm (MainForm, LikvidUchPlanForm)) {
        LikvidUchPlanForm = new TLikvidUchPlanForm (this); // Создание формы
        LikvidUchPlanForm -> Show (); // Показ формы
    }
    LikvidUchPlanForm -> FormMin (0); // уменьшение формы
}


void __fastcall TMainForm::N78Click (TObject *Sender) { // отпуска
    prikaz_search (78);
}


void __fastcall TMainForm::N79Click (TObject *Sender) { // Общежитие
    Open_SpisokForm (21);
}


void __fastcall TMainForm::N81Click (TObject *Sender) { // Список выпускников
    if (!OpenChildForm (MainForm, VipusknikiForm)) {
        VipusknikiForm = new TVipusknikiForm (this); // Создание формы
        VipusknikiForm -> Show (); // Показ формы
    }

    VipusknikiForm -> Form_min (); // Функция уменьшения формы
}


void __fastcall TMainForm::N30Click (TObject *Sender) {
    N71Click (this);
    NK_3Form -> Caption = "По направлениям специальностей";
    NK_3Form -> BitBtn1 -> Visible = false;
    NK_3Form -> BitBtn3 -> Visible = false;
    NK_3Form -> BitBtn4 -> Visible = false;
    NK_3Form -> BitBtn5 -> Visible = false;
    NK_3Form -> BitBtn6 -> Visible = false;
    NK_3Form -> BitBtn7 -> Visible = false;
    NK_3Form -> BitBtn8 -> Left = 360;
    NK_3Form -> BitBtn8 -> Visible = true;
}


void __fastcall TMainForm::N80Click (TObject *Sender)
{ // Генерация регистрационного номера
    if (!OpenChildForm (MainForm, AutoDiplomForm)) {
        AutoDiplomForm = new TAutoDiplomForm (this); // Создание формы
        AutoDiplomForm -> Show (); // Показ формы
    }

    // AutoDiplomForm -> Form_min ();//Функция уменьшения формы
}


void __fastcall TMainForm::N82Click (TObject *Sender) { // приказ на выпуск
    prikaz_search (82);
}


void __fastcall TMainForm::N83Click (TObject *Sender) {
    Spravka_vyzovForm = new TSpravka_vyzovForm (this); // Создание формы
    Spravka_vyzovForm -> Show (); // Показ формы
}


void __fastcall TMainForm::N84Click (TObject *Sender) {
    Medical_Checklist_Form = new TMedical_Checklist_Form (this);
    // Создание формы
    Medical_Checklist_Form -> Show (); // Показ формы
}


void __fastcall TMainForm::N85Click (TObject *Sender) {
    SpravkaForm = new TSpravkaForm (this); // Создание формы
    SpravkaForm -> Show (); // Показ формы
}






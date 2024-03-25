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
// Переменные для выброса в Excel
Variant XLApp;
Variant XLSh;
Variant XLBook;
// объявляем переменную для создания массива предметов
int *predmet1;
int kol_predmet; // Количество предметов
// Формируем массив годов которые должна пройти группа за период обучения
// объявление массива
int *God_ob;
// Текущий год строковый
AnsiString ut_god;
//
int *mas_pred[4];
// массив предметов по разделам:экз, курсовые, практика, факультативы
int *Count_pred; // массив количества предметов по разделам
// int *Spec; //массив специализаций
// int kol_spec; //Количество специализаций

AnsiString kurs_text; // номер курса

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
{ // Процедура для установки диапазона ячеек и передачи в него техта, размера шрифта, типа выравнивания в ячейке
    // Variant WorkSheet - переменная для листов Excel
    // int col1, int col2  - номер первого и второго столбца для выделения диапазона
    // int st - номер сторки
    // bool Border - обрамление ячейки true - обрамлять
    // AnsiString Shrift, int kegl - название шрифта и его размер
    // int AlignH, int AlignV - горизонтальное и вертикальное выравнивание текста в ячейке (0 - не надо выравнивать)
    // bool M1, bool W1  - объединение ячеек, установка переноса по словам (false - не надо выполнять этих действий)
    // AnsiString TextCell  - текст в ячейке

    // установка первой и последней ячейки для диапазона
    // Variant C1=SelectCell (col1,st);
    // Variant C2=SelectCell (col2,st);

    AnsiString diap = mas_column[col1 - 1] + st + ":" +
        mas_column[col2 - 1] + st;

    // диапазон
    Variant Rang1 = XLApp.OlePropertyGet ("Range", diap.c_str ());
    // Range_Range (WorkSheet,C1,C2);

    // Variant Rang1=XLSh.OlePropertyGet ("Cells",st,col1);
    // перенос по словам в ячейке  - если false, то не объединяем
    if (W_1)
        W1 (Rang1);

    // Объединение ячеек  - если false, то не объединяем
    if (M_1)
        M1 (Rang1);

    // установка шрифта
    // CellFont (Shrift,kegl,Bold,false,1,0,Rang1);
    Rang1.OlePropertyGet ("Font").OlePropertySet ("Name", Shrift.c_str ());
    Rang1.OlePropertyGet ("Font").OlePropertySet ("Size", kegl);

    if (Bold)
        Rang1.OlePropertyGet ("Font").OlePropertySet ("Bold", True);

    // установка в ячейку значения
    // CellValue (TextCell,col1,st);
    Variant cur = XLSh.OlePropertyGet ("Cells", st, col1);
    cur.OlePropertySet ("Value", TextCell.c_str ());

    // обрамление ячейки
    if (Border) { // if true - то обрамляем ячейки
        // if (col1==col2) BorderCell (col1, st, 1, 2);
        // else
        // { //else нужно обрамлять больше чем одну ячейку
        // for (col1;col1<=col2;col1++)
        // {
        for (int i = 1; i <= 4; i++) {
            Rang1.OlePropertyGet ("Borders").OlePropertyGet ("Item", i)
                .OlePropertySet ("LineStyle", 1);
        }
        // BorderCell (col1, st, 1, 2);
        // }
        // } //end else нужно обрамлять больше чем одну ячейку

    } // end if true - то обрамляем ячейки
    // горизонтальное выравнивание   - при  0 выравнивать не надо
    if (AlignH)
        HorizontalAlign (Rang1, AlignH);

    // вертикальное выравнивание     - при  0 выравнивать не надо
    if (AlignV)
        VerticalAlign (Rang1, AlignV);

}

// ---------------------------------------------------------------------------
// Процедура формирования массива годов
void __fastcall TSvod_Ved::Mas_God (int n_kurs) {
    God_ob = new int[n_kurs];
    // God_ob[0]=StrToInt (ut_god);
    God_ob[0] = uch_god;
    for (int kur = 1; kur < n_kurs; kur++)
        God_ob[kur] = God_ob[kur - 1] - 1;

}

// ---------------------------------------------------------------------------
// Процедура формирования массива предметов
void __fastcall TSvod_Ved::Mas_Predmet (int n_kurs, int n_vid_edu, int specializ)
{
    // Обращение к процедуре формирования учебных годов
    Mas_God (n_kurs);
    // Количество семестров
    int semestr = n_kurs * 2;

    predmet1 = new int[200];
    kol_predmet = 0;
    // Выбираем предметы которые должна сдавать группа
    // Сначала по экзаменам
    // по последнему году
    int *vid;
    vid = new int[4];
    vid[0] = 2;
    vid[1] = 3;
    vid[2] = 1;
    vid[3] = 0;
    // Цикл по 2--экзамены, 3-- диф. зачеты, 1 -- зачет, 0 - предметы без вида контроля
    for (int m = 0; m < 4; m++) {
        int kur = n_kurs - 1;
        for (int sem = 1; sem <= semestr; sem++) {

            DM3 -> Detail_Svod_NadoFDQuery -> Close ();
            DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("N_FAC") -> Value = nom_fac;
            DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("VID_EDU") -> Value =
                n_vid_edu;
            // Здесь Гос. не берется
            DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("VID") -> Value = vid[m];
            DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("YEAR_PLAN") -> Value =
                StrToInt (God_ob[kur]);
            DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("SEMESTR") -> Value = sem;
            DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("SPECIALIZ") -> Value =
                specializ;
            DM3 -> Detail_Svod_NadoFDQuery -> Open ();
            DM3 -> Detail_Svod_NadoFDQuery -> First ();
            //////////////////////////////////
            // Переход на следующий учебный год

            if (sem % 2 == 0)
                kur = kur - 1;
            //////////////////////////////////
            // Подсчитываем кол-во предметов
            for (int kk = 0; kk < DM3 -> Detail_Svod_NadoFDQuery -> RecordCount;
            kk++) { // Проверяем предметы которые разнесены на несколько семестров
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
            } // конец цикла по предметам
        } // конец цикла по семестрам

    } // for зач.экз
    delete[]vid;
}

// ---------------------------------------------------------------------------
// Процедура формирования массива предметов по отдельности
// pred[0]-- экзамены, зачеты
// pred[1]-- Курсовые, pred[2]-- Практика, pred[3]--Гос  , pred[4]--Факультативы
void __fastcall TSvod_Ved::Mas_Pred (int n_kurs, int n_vid_edu, int specializ) {

    // Для этого сначала сформируем общий массив предметов без повторений названий
    Mas_Predmet (n_kurs, n_vid_edu, specializ);
    // Формирование двумерного массива
    for (int i = 0; i < 4; i++) {
        mas_pred[i] = new int[kol_predmet];
    }
    // Формирование массива количества предметов
    Count_pred = new int[4];
    // Первичные значения
    for (int i = 0; i < 4; i++) {
        Count_pred[i] = 0;
    }
    // int j=0;
    for (int i = 0; i < kol_predmet; i++) {
        DM3 -> Name_PredmetFDQuery -> Close ();
        DM3 -> Name_PredmetFDQuery -> ParamByName ("N_OBJECT") -> Value = predmet1[i];
        DM3 -> Name_PredmetFDQuery -> Open ();
        if ( (DM3 -> Name_PredmetFDQueryNAME_OBJECT -> Value.Pos ("Практика")) ||
            (DM3 -> Name_PredmetFDQueryNAME_OBJECT -> Value.Pos ("практика"))) {
            mas_pred[2][Count_pred[2]] =
                DM3 -> Name_PredmetFDQueryN_OBJECT -> Value;
            Count_pred[2] = Count_pred[2] + 1;

        }
        if (DM3 -> Name_PredmetFDQueryNAME_OBJECT -> Value.Pos ("Курсовая")) {
            mas_pred[1][Count_pred[1]] =
                DM3 -> Name_PredmetFDQueryN_OBJECT -> Value;
            Count_pred[1] = Count_pred[1] + 1;

        }
        if ( (!DM3 -> Name_PredmetFDQueryNAME_OBJECT -> Value.Pos ("Курсовая")) &&
            (!DM3 -> Name_PredmetFDQueryNAME_OBJECT -> Value.Pos ("Практика")) &&
            (!DM3 -> Name_PredmetFDQueryNAME_OBJECT -> Value.Pos ("практика"))) {
            mas_pred[0][Count_pred[0]] =
                DM3 -> Name_PredmetFDQueryN_OBJECT -> Value;
            Count_pred[0] = Count_pred[0] + 1;
        }

    } // for
    // Отдельно для Гос.

    /* //временно убрала, чтобы проверить, избыточность переменных
     int kur=n_kurs-1;
     DM3 -> Detail_Svod_Nado -> Close ();
     DM3 -> Detail_Svod_Nado -> ParamByName ("N_FAC") -> Value=nom_fac;
     DM3 -> Detail_Svod_Nado -> ParamByName ("VID_EDU") -> Value=n_vid_edu;
     DM3 -> Detail_Svod_Nado -> ParamByName ("VID") -> Value=4;//Признак  4-- это Гос.
     DM3 -> Detail_Svod_Nado -> ParamByName ("YEAR_PLAN") -> Value=StrToInt (God_ob[kur]);
     DM3 -> Detail_Svod_Nado -> ParamByName ("SEMESTR") -> Value=kur*2; */
    // ---------новый куcок
    DM3 -> Detail_Svod_NadoFDQuery -> Close ();
    DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("N_FAC") -> Value = nom_fac;
    DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("VID_EDU") -> Value = n_vid_edu;
    DM3 -> Detail_Svod_NadoFDQuery -> ParamByName ("VID") -> Value = 4;
    // Признак  4-- это Гос.
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
    syst_ball = 10; // по закрытию формы возвращаем десятибальную систему оценок

    Svod_Ved -> Close ();
}
// ---------------------------------------------------------------------------
/* AnsiString __fastcall TSvod_Ved::Str (int result)
 {
 AnsiString St="";
 switch (result)
 {
 case 1 :  St="зачтено";
 break;
 case 3 :  St="удовлетворительно";
 break;
 case 4 :  St="хорошо";
 break;
 case 5 :  St="отлично";
 break;
 case 7 :  St="освобожден";
 break;
 }
 return St;

 }
 */

// ---------------------------------------------------------------------------

void __fastcall TSvod_Ved::BitBtn2Click (TObject *Sender) {
   /*    if ( (Edit2 -> Text == "") || (ComboBox2 -> Text == "")) {
        ShowMessage ("Введите значения номера группы и формы обучения!!!");
        return;
    }
    else {

        Variant i_gr = search_increment_group (Edit2 -> Text,
        ComboBox2 -> ItemIndex);
        if (!i_gr.IsNull ()) {
            // Формирования Query для сводной
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
                ShowMessage ("Эта группа не Вашего факультета!");
                return;
            }

            else // Начало основного кода для выброса в Excel
            { // ---------------------------------------------
                //////Для сводной ведомости
                if (Vibor == 1) {
                    ////////Оформила в процедуру отдельно
                    /////Mas_Spec ();
                    DM3 -> Name_SpecFDQuery -> Close ();
                    DM3 -> Name_SpecFDQuery -> ParamByName ("INC_GROUP") -> Value =
                        search_increment_group (Svod_Ved -> Edit2 -> Text,
                        Svod_Ved -> ComboBox2 -> ItemIndex); ;
                    DM3 -> Name_SpecFDQuery -> ParamByName ("N_FAC") -> Value =
                        nom_fac;
                    DM3 -> Name_SpecFDQuery -> Open ();

                    // Объявление  новой книги
                    XLApp = Variant::CreateObject ("Excel.Application");
                    XLBook = NewBook (XLApp);

                    //////////////
                    TDateTime data;
                    ut_god = DateToStr (data.CurrentDate ());
                    // находим текущий год
                    // int month=AnsiString (ut_god).SubString (4,2).ToInt ();
                    // if (month>8) ut_god=AnsiString (ut_god).SubString (7,4);
                    // else ut_god=AnsiString (AnsiString (ut_god).SubString (7,4).ToInt ()-1);
                    ut_god = ut_god.SubString (7, 4);

                    // Формирование листов
                    for (int i = 0;
                    i < DM3 -> Name_SpecFDQuery -> RecordCount;
                    i++) // цикл по специализациям
                    {
                        // формирование Query по специализациям
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
                        { // if длина названия большая то урезаем ее до 30 символов
                            NameSheet1 (XLSh,
                                Edit2 -> Text + "гр. " + name_spec.SubString
                                (1, 20));
                            SelectSheet (XLBook,
                                Edit2 -> Text + "гр. " + name_spec.SubString
                                (1, 20));
                        } // end if длина названия большая то урезаем ее до 30 символов
                        else { // else не превышат 30 символов - оставляем без изменений
                            NameSheet1 (XLSh, Edit2 -> Text + "гр. " + name_spec);
                            SelectSheet (XLBook,
                                Edit2 -> Text + "гр. " + name_spec);
                        }

                        SetOrientatSheet (XLSh, 2);

                        // Заголовок Выделение ячеек
                        Variant Rang1 = Range2 (XLSh, "A1:Z1");
                        // выравнивание по горизонтали
                        HorizontalAlign (Rang1, 3);
                        // установка шрифта
                        CellFont ("Arial", 12, true, false, 1, 0, Rang1);
                        // Объединение ячеек
                        M1 (Rang1);

                        // Поместить текст
                        // -------  проверка на выпускной курс 5 (дневного) или 6 (заочного)
                        kurs_text = (Edit2 -> Text).SubString (2, 1);
                        // выбираем номер курса
                        if ( (ComboBox2 -> ItemIndex == 0 && kurs_text == 5) ||
                            (ComboBox2 -> ItemIndex == 1 && kurs_text == 6))
                        { // if выпускной курс
                            CellValue ("Сводная ведомость выпускного курса " +
                                ut_god + " года", 1, 1);
                        } // end if выпускной курс
                        else { // else другие курсы
                            CellValue (
                                "Сводная ведомость по предметам по состоянию на " +
                                ut_god + " год", 1, 1);
                        } // end else другие курсы
                        // -------
                        // Определение формы обучения и названия факультета
                        AnsiString St = "";
                        if (ComboBox2 -> Text == "дневная")
                            St = "дневного отделения ";
                        if (ComboBox2 -> Text == "заочная")
                            St = "заочного отделения ";
                        switch (nom_fac) {
                        case 1:
                            St = St +
                                "спортивно-педагогического факультета спортивных игр и единоборств ";
                            break;
                        case 2:
                            St = St +
                                "спортивно-педагогического факультета массовых видов спорта ";
                            break;
                        case 3:
                            St = St +
                                "факультета оздоровительной физической культуры и туризма ";
                            break;
                        case 4:
                            St = St + "института туризма ";
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
                        St = Edit2 -> Text + " группа. Специализация - " +
                            DM3 -> People_SvodReport_SpecFDQuerySPECIAL -> Value;
                        CellValue (St, 1, 3);
                        // Шапка

                        Rang1 = Range2 (XLSh, "A5:A7");
                        CellValue ("№ п/п", 1, 5);
                        M1 (Rang1);
                        AutoFitColumn (XLSh, 1);
                        HorizontalAlign (Rang1, 3);
                        VerticalAlign (Rang1, 2);

                        Rang1 = Range2 (XLSh, "B5:B7");
                        CellValue ("Ф.И.О.", 2, 5);
                        M1 (Rang1);
                        VerticalAlign (Rang1, 2);
                        HorizontalAlign (Rang1, 3);
                        // AutoFitColumn (XLSh,2);
                        // Обрамление ячеек над фамилиями
                        BorderCell (1, 5, 1, 2);
                        BorderCell (2, 5, 1, 2);
                        BorderCell (1, 6, 1, 2);
                        BorderCell (2, 6, 1, 2);
                        BorderCell (1, 7, 1, 2);
                        BorderCell (2, 7, 1, 2);
                        // Обращение к процедуре формирования массива предметов (кот. надо)
                        Mas_Predmet (DM3 -> People_SvodReport_SpecFDQueryKURS -> 
                            Value, DM3 -> People_SvodReport_SpecFDQueryVID_EDU -> 
                            Value, DM3 -> People_SvodReport_SpecFDQueryN_SPECIALIZ
                            -> Value);

                        // Выброс в Excel предметов
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
                        CellValue ("Предметы", 3, 5);
                        M1 (Rang1);
                        HorizontalAlign (Rang1, 3);

                        ////По людям
                        DM3 -> People_SvodReport_SpecFDQuery -> First ();
                        for (int j = 1;
                        j <= DM3 -> People_SvodReport_SpecFDQuery -> 
                            RecordCount; j++) {
                            // Порядковы номер
                            BorderCell (1, j + 7, 1, 2);
                            Variant C1 = SelectCell (1, j + 7);
                            Variant C2 = SelectCell (1, j + 7);
                            Rang1 = Range_Range (XLSh, C1, C2);
                            CellValue (IntToStr (j), 1, j + 7);
                            VerticalAlign (Rang1, 2);
                            AutoFitColumn (XLSh, 1);
                            // Фамилия
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

                            // Переделать на процедуру
                            ///Выбираем предметы которые он сдал реально
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
                                 case 1 :  St="зач";
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

                             /*    // --------новый кусок для определения системы оценок
                                int ball_baza =
                                    ball_int (syst_ball,
                                    DM3 -> Detail_Svod_RealFDQueryRESULT -> Value);
                                if (ball_baza > 10)
                                { // if проверка на возвращение балла из десятибальной системы
                                    St = IntToStr (ball_baza - 10);

                                } // end if проверка на возвращение балла из десятибальной системы
                                else { // else на возвращение балла из пятибальной системы
                                    switch (ball_baza)
                                    { // switch баллы пятибальной системы
                                    case 0:
                                        St = "";
                                        // пустая ячейка в том случае когда не проставлена оценка
                                        break;
                                    case 1:
                                        St = "зач"; // зачет
                                        break;
                                    case 7:
                                        St = ""; // освобожден
                                        break;
                                    case 9:
                                        St = "+"; // прослушан
                                        break;
                                    default:
                                        St = IntToStr (ball_baza);
                                        // баллы 2,3,4,5 соответствуют
                                    } // end switch баллы пятибальной системы
                                } // end else на возвращение балла из пятибальной системы
                                // -------
                                if (St == "зач" || St == "пр") {
                                    CellValue (St, 3 + jj, j + 7);
                                    CellOrient (3 + jj, j + 7, 90);
                                    BorderCell (3 + jj, j + 7, 1, 2);
                                }
                                else {
                                    CellValue (St, 3 + jj, j + 7);
                                    BorderCell (3 + jj, j + 7, 1, 2);
                                }
                            } // for по предметам
                            ///////////////////////////
                            // Далее надо проставить оценки
                            DM3 -> People_SvodReport_SpecFDQuery -> Next ();
                        } // for по людям
                        ///////Получить Query с предметами
                        // Удаление массивов год и предмет
                        delete[]God_ob;
                        delete[]predmet1;
                        DM3 -> Name_SpecFDQuery -> Next ();
                    } // цикл по специализациям

                    AnsiString name_f; // название файла в Excel

                    if ( (ComboBox2 -> ItemIndex == 0 && kurs_text == 5) ||
                        (ComboBox2 -> ItemIndex == 1 && kurs_text == 6))
                    { // if выпускной курс
                        name_f = "Сводная ведомость выпуска " +
                            DM2 -> FacultyFDTable -> Lookup ("N_FAC", nom_fac,
                        "FAC1") + " " + Edit2 -> Text + " гр " + ut_god +
                            " года.xls";
                    } // end if выпускной курс
                    else { // else другие курсы
                        name_f = "Сводная ведомость по предметам " +
                            DM2 -> FacultyFDTable -> Lookup ("N_FAC", nom_fac,
                        "FAC1") + " " + Edit2 -> Text + " гр за " + ut_god +
                            " год.xls";
                    } // end else другие курсы

                    Variant WorkSaveAs =
                        SaveBookAs (XLBook, "d:\\Мои документы\\" + name_f);
                    OVisible (XLApp); // Создание объекта
                    // XLApp = Unassigned;
                    // удаление массива специализаций
                    // delete[] Spec;

                    DM3 -> People_SvodReportFDQuery -> Close ();
                } // if  Vibor ==1
                //////////Конец для сводной ведомости
                /////////////////////////////////////////////////
                ///////////////////Для выписки из диплома

                ///----ВЫПИСКА К ДИПЛОМУ

                if (Vibor == 2) {
                    // Добавление в MyList людей
                    AnsiString Str_Fam = "";
                    // переменная для сохранения файла с фамилиями для выписки
                    // Формирование входного массива
                    AnsiString *mas_stud[3];
                    // массив номеров и фамилий студентов
                    for (int i = 0; i < 3; i++)
                        mas_stud[i] =
                            new AnsiString
                            [DM3 -> People_SvodReportFDQuery -> RecordCount];
                    //////////////////////////////////////////////////////////////////////////
                    DM3 -> People_SvodReportFDQuery -> First ();

                    // Мой компонент
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
                                    // возвращаем номер студента
                                    Str_Fam += mas_stud[2][j] + ",";
                                    // возвращаем фамилии студентов
                                    j = MyList1 -> SourceList -> Count - 1;
                                    // если нашли то уходим из цикла
                                }
                            } // 2-ой for
                        } // 1-ый for

                        Str_Nomer.SetLength (Str_Nomer.Length () - 1);
                        // Формирование Query для выхода
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
                        // Начало выброса в Excel выписок к диплому
                        // Объявление  новой книги
                        // Variant XLApp, XLSh;
                        XLApp = Variant::CreateObject ("Excel.Application");
                        XLApp.OlePropertyGet ("WorkBooks").OleProcedure ("add");
                        XLSh = XLApp.OlePropertyGet ("WorkSheets", 1);

                        // XLApp = Variant::CreateObject ("Excel.Application");
                        // XLBook=NewBook (XLApp);
                        for (int i = 0;
                        i <= DM3 -> People_SvodReportFDQuery -> RecordCount -
                            1; i++) // формирование листов в зависимости от кол-ва народу!!
                        {
                            XLSh = NewSheet1 (XLApp);
                            NameSheet1 (XLSh,
                                Edit2 -> Text + "гр. " +
                                DM3 -> People_SvodReportFDQueryFAM -> Value + " " +
                                IntToStr (i + 1));
                            // SelectSheet (XLBook,Edit2 -> Text+"гр. "+DM3 -> People_SvodReportFAM -> Value+" "+IntToStr (i+1));
                            // XLApp.OlePropertyGet ("WorkSheets",Edit2 -> Text+"гр. "+DM3 -> People_SvodReportFAM -> Value+" "+IntToStr (i+1)).OleProcedure ("Select");
                            // XLApp.OlePropertyGet ("WorkSheets")
                            XLSh = XLApp.OlePropertyGet ("ActiveSheet");

                            // Sheets ("Лист1").Select
                            // Sheets.Add
                            // Sheets ("Лист2").Select
                            // Sheets ("Лист2").Name = "ggggg"
                            // Sheets ("Лист1").Select

                            ///Формирование текста
                            // Установка ширины ячеек
                            Variant Rang1 = Range2 (XLSh, "A1:A1");
                            ColumnWidth (Rang1, 4);
                            Rang1 = Range2 (XLSh, "B1:B1");
                            ColumnWidth (Rang1, 53);
                            Rang1 = Range2 (XLSh, "C1:C1");
                            ColumnWidth (Rang1, 9);
                            Rang1 = Range2 (XLSh, "D1:D1");
                            ColumnWidth (Rang1, 18);

                            // Заголовок
                            // Получение номера диплома
                            DM3 -> DiplomFDQuery -> Close ();
                            DM3 -> DiplomFDQuery -> ParamByName ("NOMER") -> Value =
                                DM3 -> People_SvodReportFDQueryNOMER -> Value;
                            DM3 -> DiplomFDQuery -> Open ();

                            // Первая строка
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, 1, false,
                                "TimesNewRoman", 12, true, 3, 0, true, false,
                                "Приложение к диплому _____ № _____________" +
                                DM3 -> DiplomFDQueryN_DIPLOM -> Value);

                            // Вторая строка
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, 2, false,
                                "TimesNewRoman", 12, true, 3, 0, true, false,
                                "ВЫПИСКА ИЗ ЗАЧЕТНО-ЭКЗАМЕНАЦИОННОЙ ВЕДОМОСТИ");
                            HeightRow (Range2 (XLSh, "2:2"), 24);
                            // Третья строка
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, 3, false,
                                "TimesNewRoman", 12, false, 3, 0, true, false,
                                " (без диплома недействительна)");

                            // Пропустить строку
                            // Определение пола человека
                            AnsiString St1 = "";
                            AnsiString St2 = "";
                            AnsiString St3 = "";
                            AnsiString St4 = "";
                            AnsiString St5 = "";
                            if (DM3 -> People_SvodReportFDQueryPOL -> Value == "Ж")
                            {
                                St1 = "выполнила";
                                St2 = "сдала";
                                St3 = "Студентка";
                                St4 = "защитила";
                                St5 = "Выполнила";
                            }
                            if (DM3 -> People_SvodReportFDQueryPOL -> Value == "М")
                            {
                                St1 = "выполнил";
                                St2 = "сдал";
                                St3 = "Студент";
                                St4 = "защитил";
                                St5 = "Выполнил";
                            }

                            // Формируем массив годов
                            //////////////
                            // TDateTime data;
                            // ut_god=data.CurrentDate ();//находим текущий год
                            // int month=AnsiString (ut_god).SubString (4,2).ToInt ();
                            // if (month>8) ut_god=AnsiString (ut_god).SubString (7,4);
                            // else ut_god=AnsiString (AnsiString (ut_god).SubString (7,4).ToInt ()-1);

                            Mas_God (DM3 -> People_SvodReportFDQueryKURS -> Value);
                            // --------
                            // Пятая строка
                            AnsiString St = "      ";
                            // переменная формирования текстовой шапочки для выписки к диплому
                            // ФИО
                            St += DM3 -> People_SvodReportFDQueryFAM -> Value +
                                " " + DM3 -> People_SvodReportFDQueryNAME -> Value +
                                " " + DM3 -> People_SvodReportFDQueryOTCH -> Value;

                            // Переменная для определения длины строки для ФИО
                            int len_St = St.Length ();

                            // куда поступал
                            St += " за время обучения в ";
                            Variant V =
                                SQLTimeStampToDateTime (DM3 -> 
                                People_SvodReportFDQueryD_PRIKAZ_INCLUDE -> Value
                                );
                            int date_include = V.AsType (varInteger);
                            if (date_include)
                            { // if проверки на непустое значение поля
                                if (date_include <= 33844)
                                    // это дата 28.08.1992
                                        St += "Белорусском государственном ордена Трудового Красного Знамени институте физической культуры, далее именуемом  ";

                                if (date_include >
                                    33844 && date_include <= 36966)
                                    // это дата c 28.08.1992  по 16.03.2001
                                        St += "Академии физического воспитания и спорта Республики Беларусь, далее именуемой  ";

                                if (date_include >
                                    36966 && date_include <= 37983)
                                    // это дата c 16.03.2001  по 28.12.2003
                                        St += "Белорусской государственной академии физической культуры, далее именуемой  ";

                                if (date_include > 37983)
                                    // это дата после 28.12.2003
                                        St += "Белорусском государственном университете физической культуры, далее именуемом  ";
                            } // end if проверки на непустое значение поля
                            else
                                St += "!!!!!!!! У Вас не введена дата поступления в ВУЗ, ";

                            // ----
                            St += "Учреждение образования \"Белорусский государственный университет физической культуры\", с ";
                            AnsiString god_postupl = V.AsType (varString);
                            // года обучения в ВУЗе
                            if (date_include)
                                St += god_postupl.SubString (7, 4) +
                                    " года по " +
                                    IntToStr (StrToInt (God_ob[0]) + 1) + " год ";
                            else {
                                St += God_ob
                                    [DM3 -> People_SvodReportFDQueryKURS -> 
                                    Value - 1];
                                St += " года  по " +
                                    IntToStr (StrToInt (God_ob[0]) + 1) + " год ";
                            }
                            // специальность
                            St += St1 + " учебный план по специальности \"" +
                                DM3 -> People_SvodReportFDQuerySPEC -> Value;

                            // специализация или направление специальности

                            if (DM3 -> People_SvodReportFDQueryN_SPEC -> Value == 1)
                            { // if специальность физическая культура и спорт
                                St += "\", специализации ";
                                St += "\"";
                                if (nom_fac == 1 || nom_fac == 2) {
                                    St += "Тренерская работа по ";
                                }
                                St += DM3 -> 
                                    People_SvodReportFDQuerySPECIAL_SKLON -> 
                                    Value;
                            } // end if специальность физическая культура и спорт
                            else { // else другие новые специальности
                                St += "\", направлению специальности \"";
                                if (DM3 -> People_SvodReportFDQueryN_SPEC -> Value
                                    == 6) { // if  Спортивно-педагогическая деятельность
                                    if (DM3 -> People_SvodReportFDQueryN_SPECIALIZ
                                        -> Value != 52 &&
                                        DM3 -> People_SvodReportFDQueryN_SPECIALIZ
                                        -> Value != 56) {
                                        // if 52-Спортивная психология, 56 - Спортивная режиссура

                                        St += "Тренерская работа по ";
                                    }

                                } // end if  Спортивно-педагогическая деятельность
                                St += DM3 -> 
                                    People_SvodReportFDQuerySPECIAL_SKLON -> 
                                    Value;
                            } // else другие новые специальности

                            // конец текстовой вставки
                            St += "\" и " + St2 +
                                " экзамены и зачеты по следующим дисциплинам:";

                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, 5, false,
                                "TimesNewRoman", 12, false, 6, 1, true,
                                true, St);
                            Rang1 = Range2 (XLSh, "A5:D5");
                            Variant cur = XLSh.OlePropertyGet ("Cells", 5, 1);
                            cur.OlePropertyGet ("Characters", 1, len_St)
                                .OlePropertyGet ("Font").OlePropertySet
                                ("FontStyle", "полужирный");
                            // Установить в выделенной ячейке с позиции Start длинной Length другой шрифт
                            // CellFontChar (1,len_St,"Arial",5,1,XLSh);
                            HeightRow (Rang1, 100); // установка высоты строки

                            // формирование массивов предметов по разделам:
                            // экзамены, зачеты
                            // Курсовые
                            // Практика
                            // Гос
                            Mas_Pred (DM3 -> People_SvodReportFDQueryKURS -> Value,
                                DM3 -> People_SvodReportFDQueryVID_EDU -> Value,
                                DM3 -> People_SvodReportFDQueryN_SPECIALIZ
                                -> Value);
                            // Выброс предметов в отчет

                            // Шапка
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 1, 6, true, "Arial",
                                12, true, 3, 2, false, true, "№ п/п");
                            Cell_2_Text_Ole (XLApp, XLSh, 2, 2, 6, true, "Arial",
                                12, true, 3, 2, false, false,
                                "Наименование дисциплины");
                            Cell_2_Text_Ole (XLApp, XLSh, 3, 3, 6, true, "Arial",
                                12, true, 3, 2, false, true, "Кол-во часов");
                            Cell_2_Text_Ole (XLApp, XLSh, 4, 4, 6, true, "Arial",
                                12, true, 3, 2, false, false, "Оценка");

                            int jj = 0;
                            int kol_spec = 0;
                            // переменная для определения номера в массиве спецкурсов

                            int mas_spec[10];
                            // Выброс предметов в отчет
                            for (jj = 0; jj < Count_pred[0]; jj++) {

                                // Наименование предмета
                                DM3 -> Detail_Svod_RealFDQuery -> Close ();
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName
                                    ("N_OBJECT") -> Value = mas_pred[0][jj];
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName
                                    ("NOMER") -> Value =
                                    DM3 -> People_SvodReportFDQueryNOMER -> Value;
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName ("FAC")
                                    -> Value = nom_fac;
                                DM3 -> Detail_Svod_RealFDQuery -> Open ();

                                // Пробный вариант для вынесения спецкурсов в отдельный массив

                                /* //Расчитать количество часов
                                 int kol=0;
                                 for (int jjj=0; jjj<DM3 -> Detail_Svod_Real -> RecordCount;jjj++)
                                 {
                                 kol=kol+DM3 -> Detail_Svod_RealCLOCK_PLAN -> Value;
                                 } */
                                /////////////////////////////////////////////////////////////
                                // Предмет даже если его нет в сданных
                          /*        DM3 -> Name_PredmetFDQuery -> Close ();
                                DM3 -> Name_PredmetFDQuery -> ParamByName
                                    ("N_OBJECT") -> Value = mas_pred[0][jj];
                                DM3 -> Name_PredmetFDQuery -> Open ();

                                if (DM3 -> Detail_Svod_RealFDQuerySPECKURS -> Value
                                    == 1) { // if это спецкурс
                                    mas_spec[kol_spec] =
                                        DM3 -> Name_PredmetFDQueryN_OBJECT -> Value;
                                    kol_spec++;

                                } // end if это спецкурс

                                else { // else это не спецкурс

                                    // Проставляем номер
                                    Cell_2_Text_Ole (XLApp, XLSh, 1, 1,
                                        jj + 7 - kol_spec, true, "Arial", 10,
                                        false, 3, 2, false, false,
                                        IntToStr (jj + 1 - kol_spec));

                                    // название предмета
                                    Cell_2_Text_Ole (XLApp, XLSh, 2, 2,
                                        jj + 7 - kol_spec, true, "Arial", 10,
                                        false, 0, 2, false, true,
                                        Text_predmet (DM3 -> 
                                        Name_PredmetFDQueryNAME_OBJECT -> Value,
                                        DM3 -> People_SvodReportFDQueryN_SPECIALIZ
                                        -> Value));

                                    // Количество часов
                                    Cell_2_Text_Ole (XLApp, XLSh, 3, 3,
                                        jj + 7 - kol_spec, true, "Arial", 10,
                                        false, 3, 2, false, false,
                                        DM3 -> Name_PredmetFDQueryALL_CLOCK_PLAN
                                        -> Value);

                                    // На последнюю чтобы взять последнюю оценку
                                    // Оценка по предмету
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
                                } // else это не спецкурс
                            } // for jj для выброса предметов

                            jj -= kol_spec;
                            // вычитаем количество спецкурсов, чтобы все не поплыло в Excel
                            // Студент (ка) ФИО выполнил (а)
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, jj + 8, false,
                                "Arial", 12, false, 0, 2, true, false,
                                " " + St3 + " " +
                                DM3 -> People_SvodReportFDQueryFAM -> Value + " " +
                                DM3 -> People_SvodReportFDQueryNAME -> Value + " " +
                                DM3 -> People_SvodReportFDQueryOTCH -> Value +
                                " " + St1);
                            // jj--;//в связи с удалением строчки   Студент (ка) ФИО выполнил (а)

                            // Спецкурсы   для дневного печатаем, а для заочного нет
                            if (!DM3 -> 
                                Detail_Svod_RealFDQueryVID_EDU_PLAN -> Value)
                                Cell_2_Text_Ole (XLApp, XLSh, 1, 4, jj + 9,
                                false, "Arial", 12, false, 0, 2, true, false,
                                " спецкурсы:");
                            else
                                jj--; // уменьшаем переменную на 1 для заочного, чтобы не поплыло остальное
                            // Таблица спецкурсов
                            for (int k = 0; k < kol_spec; k++) {
                                // Наименование предмета
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
                                    // if предмет без вида контроля, выдавать запись только тем, кто его прослушал
                                    if (DM3 -> Detail_Svod_RealFDQuery -> 
                                        RecordCount) { // if есть запись
                                        // Проставляем номер
                                        Cell_2_Text_Ole (XLApp, XLSh, 1, 1,
                                        jj + 10, true, "Arial", 10, false, 3, 2,
                                        false, false, IntToStr (k + 1));
                                        // название предмета
                                        Cell_2_Text_Ole (XLApp, XLSh, 2, 2,
                                        jj + 10, true, "Arial", 10, false, 0, 2,
                                        false, true,
                                        Text_predmet (DM3 -> 
                                        Detail_Svod_RealFDQueryNAME_OBJECT -> 
                                        Value, DM3 -> 
                                        People_SvodReportFDQueryN_SPECIALIZ -> 
                                        Value));
                                        // Количество часов
                                        int sum_clock = 0;
                                        for (int s = 0;
                                        s < DM3 -> Detail_Svod_RealFDQuery -> 
                                        RecordCount; s++)
                                        { // for суммируем количество часов
                                        sum_clock +=
                                        DM3 -> Detail_Svod_RealFDQueryCLOCK_PLAN -> 
                                        Value;
                                        } // end for суммируем количество часов

                                        Cell_2_Text_Ole (XLApp, XLSh, 3, 3,
                                        jj + 10, true, "Arial", 10, false, 3, 2,
                                        false, false, sum_clock);
                                        // Оценка
                                        Cell_2_Text_Ole (XLApp, XLSh, 4, 4,
                                        jj + 10, true, "Arial", 10, false, 2, 2,
                                        false, false,
                                        ball_string (syst_ball,
                                        ball_int (syst_ball,
                                        DM3 -> Detail_Svod_RealFDQueryRESULT -> 
                                        Value), 1));

                                        jj++; // переход на следующий лист
                                    } // end if есть запись

                                } // end if предмет без вида контроля, выдавать запись только тем, кто его прослушал
                                else { // else обычный спец.курс
                                    // Предмет даже если его нет в сданных
                                    DM3 -> Name_PredmetFDQuery -> Close ();
                                    DM3 -> Name_PredmetFDQuery -> ParamByName
                                        ("N_OBJECT") -> Value = mas_spec[k];
                                    DM3 -> Name_PredmetFDQuery -> Open ();

                                    // Проставляем номер
                                    Cell_2_Text_Ole (XLApp, XLSh, 1, 1, jj + 10,
                                        true, "Arial", 10, false, 3, 2, false,
                                        false, IntToStr (k + 1));
                                    // название предмета
                                    Cell_2_Text_Ole (XLApp, XLSh, 2, 2, jj + 10,
                                        true, "Arial", 10, false, 0, 2, false,
                                        true, Text_predmet
                                        (DM3 -> Name_PredmetFDQueryNAME_OBJECT -> 
                                        Value, DM3 -> 
                                        People_SvodReportFDQueryN_SPECIALIZ -> 
                                        Value));

                                    // Количество часов
                                    Cell_2_Text_Ole (XLApp, XLSh, 3, 3, jj + 10,
                                        true, "Arial", 10, false, 3, 2, false,
                                        false, DM3 -> 
                                        Name_PredmetFDQueryALL_CLOCK_PLAN -> Value
                                        );

                                    // Оценка
                                    DM3 -> Detail_Svod_RealFDQuery -> Last ();
                                    Cell_2_Text_Ole (XLApp, XLSh, 4, 4, jj + 10,
                                        true, "Arial", 10, false, 2, 2, false,
                                        false, ball_string (syst_ball,
                                        ball_int (syst_ball,
                                        DM3 -> Detail_Svod_RealFDQueryRESULT -> 
                                        Value), 1));
                                    // CellValue (ball_string (syst_ball,ball_int (syst_ball,DM3 -> Detail_Svod_RealRESULT -> Value), 1),4,jj+9);
                                    // BorderCell (4, jj+9, 1, 2);
                                    jj++; // переход на следующий лист
                                } // end else обычный спец.курс
                            } // for по курсовым
                            ///////////////////////////////////////////////////////////////////

                            // Курсовые работы
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, jj + 10, false,
                                "Arial", 12, false, 0, 2, true, false,
                                " курсовые работы:");

                            // Таблица курсовых
                            for (int jjj = 0; jjj < Count_pred[1]; jjj++) {
                                // Проставляем номер
                                Cell_2_Text_Ole (XLApp, XLSh, 1, 1, jj + 11,
                                    true, "Arial", 10, false, 3, 2, false,
                                    false, IntToStr (jjj + 1));

                                // Наименование предмета
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
                                // Предмет даже если его нет в сданных
                                DM3 -> Name_PredmetFDQuery -> Close ();
                                DM3 -> Name_PredmetFDQuery -> ParamByName
                                    ("N_OBJECT") -> Value = mas_pred[1][jjj];
                                DM3 -> Name_PredmetFDQuery -> Open ();

                                // название предмета
                                Cell_2_Text_Ole (XLApp, XLSh, 2, 3, jj + 11,
                                    true, "Arial", 10, false, 0, 2, true, true,
                                    Text_predmet (DM3 -> 
                                    Name_PredmetFDQueryNAME_OBJECT -> Value,
                                    DM3 -> People_SvodReportFDQueryN_SPECIALIZ
                                    -> Value));

                                // Оценка
                                DM3 -> Detail_Svod_RealFDQuery -> Last ();
                                Cell_2_Text_Ole (XLApp, XLSh, 4, 4, jj + 11,
                                    true, "Arial", 10, false, 2, 2, false,
                                    false, ball_string (syst_ball,
                                    ball_int (syst_ball,
                                    DM3 -> Detail_Svod_RealFDQueryRESULT -> 
                                    Value), 1));
                                // CellValue (ball_string (syst_ball,ball_int (syst_ball,DM3 -> Detail_Svod_RealRESULT -> Value), 1),4,jj+9);
                                // BorderCell (4, jj+9, 1, 2);
                                jj++; // переход на следующий лист
                            } // for по курсовым
                            ///////////////////////////////////////////////////////////////////

                            // Практика
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, jj + 11, false,
                                "Arial", 12, false, 0, 2, true, false,
                                " практики:");

                            // Таблица практики
                            for (int jjj = 0; jjj < Count_pred[2]; jjj++) {
                                // Проставляем номер
                                Cell_2_Text_Ole (XLApp, XLSh, 1, 1, jj + 12,
                                    true, "Arial", 10, false, 3, 2, false,
                                    false, IntToStr (jjj + 1));

                                // Наименование предмета
                                DM3 -> Detail_Svod_RealFDQuery -> Close ();
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName
                                    ("N_OBJECT") -> Value = mas_pred[2][jjj];
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName
                                    ("NOMER") -> Value =
                                    DM3 -> People_SvodReportFDQueryNOMER -> Value;
                                DM3 -> Detail_Svod_RealFDQuery -> ParamByName ("FAC")
                                    -> Value = nom_fac;
                                DM3 -> Detail_Svod_RealFDQuery -> Open ();

                                // Расчитать количество недель
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

                                // Количество часов
                                kol = DM3 -> 
                                    Name_PredmetFDQueryALL_CLOCK_PLAN -> Value;
                                // берем из таблицы, как и для дневного

                                // название предмета
                                Cell_2_Text_Ole (XLApp, XLSh, 2, 2, jj + 12,
                                    true, "Arial", 10, false, 0, 2, false, true,
                                    Text_predmet (DM3 -> 
                                    Name_PredmetFDQueryNAME_OBJECT -> Value,
                                    DM3 -> People_SvodReportFDQueryN_SPECIALIZ
                                    -> Value));

                                // Количество недель
                                AnsiString nedel = "";
                                switch (kol)
                                { // switch определяем по количеству текст
                                case 1:
                                    nedel = " неделя";
                                    break;
                                case 2:
                                    nedel = " недели";
                                    break;
                                case 3:
                                    nedel = " недели";
                                    break;
                                case 4:
                                    nedel = " недели";
                                    break;
                                default:
                                    nedel = " недель";
                                    break;

                                } // switch определяем по количеству текст
                                Cell_2_Text_Ole (XLApp, XLSh, 3, 3, jj + 12,
                                    true, "Arial", 10, false, 3, 2, false,
                                    false, IntToStr (kol) + nedel);

                                // Оценка по предмету
                                DM3 -> Detail_Svod_RealFDQuery -> Last ();
                                Cell_2_Text_Ole (XLApp, XLSh, 4, 4, jj + 12,
                                    true, "Arial", 10, false, 2, 2, false,
                                    false, ball_string (syst_ball,
                                    ball_int (syst_ball,
                                    DM3 -> Detail_Svod_RealFDQueryRESULT -> 
                                    Value), 1));
                                // CellValue (ball_string (syst_ball,ball_int (syst_ball,DM3 -> Detail_Svod_RealRESULT -> Value), 1),4,jj+10);
                                // BorderCell (4, jj+10, 1, 2);
                                jj++; // переход на следующий лист

                            } // for по практике
                            /////////////////////////////////////////////////////////////////////
                            // Гос. экзамены
                            /////////////////////////////////////////////////////////////////////

                            // DM3 -> GEK_Vipiska -> Close ();
                            // DM3 -> GEK_Vipiska -> ParamByName ("NOMER") -> Value=DM3 -> People_SvodReportNOMER -> Value;
                            // DM3 -> GEK_Vipiska -> Open ();

                            // печатаем заголовок
                            // if (DM3 -> GEK_Vipiska -> RecordCount!=0)
                            // { // if  DM3 -> GEK_Vipiska -> RecordCount!=0

                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, jj + 13, false,
                                "Arial", 12, false, 0, 2, true, false,
                                " Государственные экзамены:");
                            AnsiString thema, ochenka;
                            thema = "";
                            ochenka = "";
                            // Таблица Гос.
                            for (int jjj = 0; jjj < Count_pred[3]; jjj++)
                            { // for по Гос
                                DM3 -> Name_PredmetFDQuery -> Close ();
                                DM3 -> Name_PredmetFDQuery -> ParamByName
                                    ("N_OBJECT") -> Value = mas_pred[3][jjj];
                                DM3 -> Name_PredmetFDQuery -> Open ();

                                // Проставляем номер
                                Cell_2_Text_Ole (XLApp, XLSh, 1, 1, jj + 14,
                                    true, "Arial", 10, false, 3, 2, false,
                                    false, IntToStr (jjj + 1));

                                // Проставляем название предмета
                                Cell_2_Text_Ole (XLApp, XLSh, 2, 3, jj + 14,
                                    true, "Arial", 10, false, 0, 2, true, true,
                                    Text_predmet (DM3 -> 
                                    Name_PredmetFDQueryNAME_OBJECT -> Value,
                                    DM3 -> People_SvodReportFDQueryN_SPECIALIZ
                                    -> Value));
                                Variant v1, v2;
                                // v1-ячейка, v2-значение в ячейке
                                v1 = XLSh.OlePropertyGet ("Cells",
                                    jj + 14, 2); // указываем ячейку
                                v2 = v1.OlePropertyGet ("Value");
                                // берем значение из ячейки
                                AnsiString v2_count = v2.AsType (varString);
                                // переводим значение в AnsiString
                                if (v2_count.Length () > 65) // проверяем длину
                                { // if большая длина, которая не влазит в одну строку
                                    // увеличиваем ширину строки
                                    v1.OlePropertySet ("RowHeight", 27);

                                } // end if большая длина, которая не влазит в одну строку
                                // Обрамляем ячейку
                                Cell_2_Text_Ole (XLApp, XLSh, 4, 4, jj + 14,
                                    true, "Arial", 10, false, 2, 2, false,
                                    false, " ");

                                // Оценка по ГОСу

                                DM3 -> GEK_VipiskaFDQuery -> Close ();
                                DM3 -> GEK_VipiskaFDQuery -> ParamByName ("NOMER")
                                    -> Value =
                                    DM3 -> People_SvodReportFDQueryNOMER -> Value;
                                DM3 -> GEK_VipiskaFDQuery -> ParamByName ("N_OBJECT")
                                    -> Value =
                                    DM3 -> Name_PredmetFDQueryN_OBJECT -> Value;
                                DM3 -> GEK_VipiskaFDQuery -> Open ();
                                if (!DM3 -> GEK_VipiskaFDQuery -> RecordCount)
                                { // if нет записей по данному предмету

                                    Cell_2_Text_Ole (XLApp, XLSh, 4, 4, jj + 14,
                                        true, "Arial", 10, false, 2, 2, false,
                                        false, " ");

                                } // end if нет записей по данному предмету
                                else { // else есть записи
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
                                } // end else есть записи
                                jj++; // переход на следующий лист

                            } // end for по Гос
                            // } //end if  DM3 -> GEK_Vipiska -> RecordCount!=0

                            ///////////////////////////////////////////////////////////////////
                            // Диплом
                            // DM3 -> GEK_Vipiska -> First ();
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, jj + 15, false,
                                "Arial", 12, false, 0, 2, true, false,
                                St5 + " дипломную работу на тему:");
                            // нет диплома
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 4, jj + 16, false,
                                "Arial", 12, false, 0, 0, true, false,
                                "_____________________________________________________________________________________");
                            Cell_2_Text_Ole (XLSh, XLApp, 1, 4, jj + 17, false,
                                "Arial", 12, false, 0, 0, false, false,
                                "и " + St4 + " с оценкой _______________ ");

                            // for (int jjj=0; jjj< DM3 -> GEK_Vipiska -> RecordCount; jjj++)
                            // {
                            if (thema != "")
                                // (DM3 -> GEK_VipiskaTHEME -> Value!="")
                            {
                                // получение темы диплома
                                // Cell_2_Text_Ole (XLApp,XLSh,1,4,jj+16,false,"Arial",12,false,0,2,true,true,DM3 -> GEK_VipiskaTHEME -> Value);
                                Cell_2_Text_Ole (XLApp, XLSh, 1, 4, jj + 16,
                                    false, "Arial", 12, false, 0, 2, true, true,
                                    "\"" + thema + "\"");
                                // Выделяем диапазон для изменения высоты строки
                                Rang1 = Range2 (XLSh, "A" + IntToStr (jj + 16));
                                HeightRow (Rang1, (40));
                                // Selection.Font.Italic = True
                                // Variant cur=XLSh.OlePropertyGet ("Cells",5,1);
                                // cur.OlePropertyGet ("Characters",1,len_St).OlePropertyGet ("Font").OlePropertySet ("FontStyle","полужирный");
                                // Selection.Font.Underline = xlUnderlineStyleSingle
                                Rang1.OlePropertyGet ("Font").OlePropertySet
                                    ("Italic", True);
                                Rang1.OlePropertyGet ("Font").OlePropertySet
                                    ("Underline", 1);
                                // Получение оценки
                                AnsiString two_str = "и " + St4 + " с оценкой ";
                                int dlina = two_str.Length ();
                                Rang1 = Range2 (XLSh, "A" + IntToStr (jj + 17));
                                // Cell_2_Text_Ole (XLApp,XLSh,1,4,jj+17,false,"Arial",12,false,0,2,true,false,"с оценкой "+ball_string (syst_ball,ball_int (syst_ball,DM3 -> GEK_VipiskaBALL_GEK -> Value), 1));
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
                                "Arial", 12, true, 0, 0, false, false, "М.П. ");
                            AnsiString data_full =
                                DateTimePicker1 -> Date.DateString ();
                            AnsiString month = data_full.SubString (4, 2);
                            switch (StrToInt (month)) { // switch
                            case 1:
                                month = " января ";
                                break;
                            case 2:
                                month = " февраля ";
                                break;
                            case 3:
                                month = " марта ";
                                break;
                            case 4:
                                month = " апреля ";
                                break;
                            case 5:
                                month = " мая ";
                                break;
                            case 6:
                                month = " июня ";
                                break;
                            case 7:
                                month = " июля ";
                                break;
                            case 8:
                                month = " августа ";
                                break;
                            case 9:
                                month = " сентября ";
                                break;
                            case 10:
                                month = " октября ";
                                break;
                            case 11:
                                month = " ноября ";
                                break;
                            case 12:
                                month = " декабря ";
                                break;
                            } // end switch
                            Cell_2_Text_Ole (XLApp, XLSh, 1, 1, jj + 26, false,
                                "Arial", 10, false, 0, 0, false, false,
                                "г.Минск \"" + data_full.SubString (1, 2) +
                                "\"" + month + data_full.SubString (7, 4));
                            Cell_2_Text_Ole (XLApp, XLSh, 2, 2, jj + 20, false,
                                "Arial", 12, true, 0, 0, false, false,
                                "              Ректор ");
                            Cell_2_Text_Ole (XLApp, XLSh, 2, 2, jj + 22, false,
                                "Arial", 12, true, 0, 0, false, false,
                                "              Декан ");
                            Cell_2_Text_Ole (XLApp, XLSh, 2, 2, jj + 24, false,
                                "Arial", 12, true, 0, 0, false, false,
                                "              Секретарь ");
                            Cell_2_Text_Ole (XLApp, XLSh, 3, 3, jj + 26, false,
                                "Arial", 10, false, 0, 0, false, false,
                                "Регистрационный №_________ ");

                            // делаем горизонтальное выравнивание страницы
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

                    // AnsiString name_f="Выписка к диплому "+DM2 -> FacultyTable -> Lookup ("N_FAC",nom_fac,"FAC1")+" "+Edit2 -> Text+"гр "+Str_Fam.SubString (1,Str_Fam.Length ()-1)+".xls";
                    // Variant WorkSaveAs=SaveBookAs (XLBook,"c:\\Мои документы\\"+name_f);
                    // OVisible (XLApp); //Создание объекта

                    AnsiString name_f =
                        "d:\\Мои документы\\Выписка к диплому " +
                        DM2 -> FacultyFDTable -> Lookup ("N_FAC", nom_fac, "FAC1") +
                        " " + Edit2 -> Text + "гр " + Str_Fam.SubString (1,
                        Str_Fam.Length () - 1) + ".xls";

                    XLApp.OlePropertyGet ("WorkBooks", 1).OleProcedure ("SaveAs",
                        name_f.c_str ());
                    // XLApp.OlePropertyGet ("WorkBooks",1).OleProcedure ("SaveAs","c:\\Мои документы\\"+name_f.c_str ());
                    XLApp.OlePropertySet ("Visible", true);
                    // XLApp = Unassigned;

                    // удаление массива студентов
                    for (int i = 0; i < 3; i++)
                        delete[]mas_stud[i];
                    DM3 -> People_SvodReportFDQuery -> Close ();
                    // Удаление массивов год и предмет
                    delete[]God_ob;
                    delete[]predmet1;
                    delete[]Count_pred;
                    for (int i = 0; i < 3; i++)
                        delete[]mas_pred[i];
                    XLSh.Clear ();
                    XLApp.Clear ();
                } // Vibor==2
                ///////////////////////////////////////////////////////
                ///Конец для выписки

            } // else (!DM3 -> People_SvodReportFDQuery -> RecordCount)
        } // if !i_gr.IsNull
        else
            ShowMessage (
            "Нет такой группы! Проверте правильность введения данных");
    } // else
    Svod_Ved -> Close ();
   */
}
// ---------------------------------------------------------------------------

void __fastcall TSvod_Ved::RadioGroup2Click (TObject *Sender)
{ // по умолчаниюд предлагает десятибальную систему
    switch (RadioGroup2 -> ItemIndex)
    { // switch переключение между системами оценок
    case 0:
        syst_ball = 10; // десятибальная система
        break;
    case 1:
        syst_ball = 5; // пятибальная система
        break;
    } // end switch переключение между системами оценок
}
// ---------------------------------------------------------------------------
void __fastcall TSvod_Ved::DateTimePicker1Change (TObject *Sender)
{
DateTimePicker1 -> Time = StrToTime ("00:00");
}
//---------------------------------------------------------------------------


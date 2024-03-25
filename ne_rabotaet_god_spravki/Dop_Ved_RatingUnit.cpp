#include <vcl.h>
#pragma hdrstop


#include "DataModule_Card.h"
#include "DataModule.h"
#include "DM2Unit.h"
#include "Dop_Ved_RatingUnit.h"
#include "DualList.h"
#include "Ved_RatingUnit.h"


#pragma package (smart_init)
// #pragma link     "ToolEdit"
// #pragma link     "MyList"
#pragma resource "*.dfm"


TDop_Ved_RatingForm * Dop_Ved_RatingForm;


AnsiString * nom_p[2];                                                          // массив номеров и фамилий студентов

int          i_gr_rat;                                                          // инкремент группы




// BitBtn1Click
// DateTimePicker1Change
// DateTimePicker2Change
// DateTimePicker3Change
// DateTimePicker4Change
// Edit1Exit
// Edit2Exit
// FormActivate
// FormClose






__fastcall TDop_Ved_RatingForm::TDop_Ved_RatingForm (TComponent* Owner)
    : TForm (Owner) {
}


void __fastcall TDop_Ved_RatingForm::FormClose (TObject *Sender,
    TCloseAction &Action) {
    Ved_RatingForm -> ved_run_r ();
    Action = caFree;
}


void __fastcall TDop_Ved_RatingForm::Edit2Exit (TObject *Sender) {
    if (Edit2 -> Text == "") {
        ShowMessage ("Выберите номер группы!");
        return;
    }

    if (!check_fac_group (Edit2 -> Text))
    { // if функция проверки на соответствие номера группы выбранному факультету
        ShowMessage (
            "Выберите номер группы, соответствующий Вашему факультету!");
        Edit2 -> Text = "";
        Edit2 -> SetFocus ();
        return;
    } // end if функция проверки на соответствие номера группы выбранному факультету

    // инкремент группы
    Variant p = search_increment_group (Edit2 -> Text, ComboBox2 -> ItemIndex);
    if (!p.IsNull ())
        i_gr_rat = p.AsType (varInteger);
    else {
        ShowMessage ("Нет такого номера группы!");
        return;
    }

    ComboBox1 -> Items -> Clear ();

    DataModule1 -> People_SpecializFDQuery -> Close ();
    DataModule1 -> People_SpecializFDQuery -> SQL -> Clear ();
    DataModule1 -> People_SpecializFDQuery -> SQL -> Add
        ("SELECT People.NOMER, People.FAM, People.NAME, People.OTCH, People.VID_EDU, People.KURS, People.INC_GROUP, People.N_GROUP, Specializ.SPECIAL FROM PEOPLE People INNER JOIN SPECIALIZ Specializ ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) WHERE (N_FAC=" +
        AnsiString (nom_fac) +
        ") AND (People.STATUS_PEOPLE = 1) AND (People.INC_GROUP=:G) ORDER BY Specializ.SPECIAL, People.FAM, People.NAME, People.OTCH");
    DataModule1 -> People_SpecializFDQuery -> Params -> Items[0] -> AsInteger =
        i_gr_rat;
    DataModule1 -> People_SpecializFDQuery -> Open ();
    AnsiString sp = "";

    for (int i = 0; i < DataModule1 -> People_SpecializFDQuery -> RecordCount; i++)
    { // for Для формирования специализаций только этой группы
        if (sp != DataModule1 -> People_SpecializFDQuerySPECIAL -> Value)
        { // проверка на повторяющиеся значения специализации
            sp = DataModule1 -> People_SpecializFDQuerySPECIAL -> Value;
            ComboBox1 -> Items -> Add (sp);
        } // end if  повторяющихся значений

        DataModule1 -> People_SpecializFDQuery -> Next ();
    } // end for

}


void __fastcall TDop_Ved_RatingForm::Edit1Exit (TObject *Sender) {
    // полугодие
    if (Edit1 -> Text != "1" && Edit1 -> Text != "2") {
        ShowMessage ("Полугодие должно быть 1 или 2!");
        Edit1 -> Text = "";
        Edit1 -> SetFocus ();
        return;
    }

}


void __fastcall TDop_Ved_RatingForm::BitBtn1Click (TObject *Sender)
{ // кнопка ОК (сохранить)

    if (Panel2 -> Visible) { // if редактирование ведомости
        DataModule1 -> Rating_GridFDQuery -> Edit ();

        DataModule1 -> Rating_GridFDQueryD_VED -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker3 -> Date);
        DataModule1 -> Rating_GridFDQueryEND_D_VED -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker4 -> Date);
        DataModule1 -> Rating_GridFDQueryCURATOR -> Value = Edit8 -> Text;

        DataModule1 -> Rating_GridFDQuery -> ApplyUpdates ();
        DataModule1 -> Rating_GridFDQuery -> CommitUpdates ();
        Close ();
        return;

    } // end if редактирование ведомости

    // Проверки
    if (ComboBox1 -> Text == "") { // if  направление специальности
        ShowMessage ("Выберите направление специальности (специализацию)!");
        return;
    } // end if  направление специальности

    if (Edit4 -> Text == "") { // if ФИО куратора
        ShowMessage ("Введите ФИО куратора!");
        return;
    } // end if ФИО куратора

    if (Edit1 -> Text == "") { // if полугодие
        ShowMessage ("Введите полугодие 1 или 2!");
        return;
    } // end if полугодие

    try { // try  числовым
        if (StrToInt (Edit3 -> Text) < 1 || StrToInt (Edit3 -> Text) > 12)
        { // if  в диапазоне от 1 до 12
            ShowMessage (
                "Значение семестра должно быть в диапазоне от 1 до 12!");
            return;
        } // end if  в диапазоне от 1 до 12
    } // end try  числовым
    catch (...) { // catch !числовым
        ShowMessage ("Значение семестра должно быть числовым!");
        return;
    } // end catch !числовым

    // ---------------

    bool save = false; // переменная для спешного выполнения
    int count_rec; // переменная для определения количества студентов
    int nom_ved;

    DataModule1 -> People_SpecializFDQuery -> Close ();
    DataModule1 -> People_SpecializFDQuery -> SQL -> Clear ();
    DataModule1 -> People_SpecializFDQuery -> SQL -> Add
        ("SELECT People.NOMER, People.FAM, People.NAME, People.OTCH, People.VID_EDU, People.KURS, People.INC_GROUP, People.N_GROUP, Specializ.SPECIAL FROM PEOPLE People INNER JOIN SPECIALIZ Specializ ON  (People.N_SPECIALIZ = Specializ.N_SPECIALIZ) WHERE  (N_FAC=" +
        AnsiString (nom_fac) +
        ") AND (People.STATUS_PEOPLE = 1) AND (People.INC_GROUP=:G) AND (Specializ.SPECIAL=:S) ORDER BY Specializ.SPECIAL, People.FAM, People.NAME, People.OTCH");
    DataModule1 -> People_SpecializFDQuery -> Params -> Items[0] -> AsInteger =
        i_gr_rat;
    DataModule1 -> People_SpecializFDQuery -> Params -> Items[1] -> AsString =
        ComboBox1 -> Text;
    DataModule1 -> People_SpecializFDQuery -> Open ();

    count_rec = DataModule1 -> People_SpecializFDQuery -> RecordCount;
    if (count_rec) { // если есть студенты для выбранной специализации
        for (int i = 0; i < 2; i++) { // for1
            nom_p[i] = new AnsiString[count_rec];
        } // end for1

        for (int i = 0; i < count_rec;
        i++) // формирование массива студентов для специализации
        { // for2
            // ФИО студента и номер группы
            nom_p[0][i] = DataModule1 -> People_SpecializFDQueryFAM -> Value + " " +
                DataModule1 -> People_SpecializFDQueryNAME -> Value + " " +
                DataModule1 -> People_SpecializFDQueryOTCH -> Value;
            // номер студента
            nom_p[1][i] =
                AnsiString (DataModule1 -> People_SpecializFDQueryNOMER -> Value);

            // проверка на то, была ли создана на этого студента ведомость
            DataModule1 -> Rating_SearchFDQuery -> Close ();

            DataModule1 -> Rating_SearchFDQuery -> ParamByName ("NOM") -> AsInteger =
                StrToInt (nom_p[1][i]);
            DataModule1 -> Rating_SearchFDQuery -> ParamByName ("FAC") -> AsInteger =
                nom_fac;
            DataModule1 -> Rating_SearchFDQuery -> ParamByName ("EDU") -> AsSmallInt =
                ComboBox2 -> ItemIndex;
            DataModule1 -> Rating_SearchFDQuery -> ParamByName ("SEM") -> AsSmallInt =
                StrToInt (Edit3 -> Text);
            DataModule1 -> Rating_SearchFDQuery -> ParamByName ("GOD") -> AsSmallInt =
                uch_god;
            DataModule1 -> Rating_SearchFDQuery -> ParamByName ("SES") -> AsSmallInt =
                StrToInt (Edit1 -> Text);
            DataModule1 -> Rating_SearchFDQuery -> Open ();

            if (DataModule1 -> Rating_SearchFDQuery -> RecordCount)
                nom_p[1][i] = 0;

            // -----------
            if (CheckBox2 -> State == cbChecked) {
                DualListDlg -> SrcList -> Items -> AddObject (nom_p[0][i],
                    (TObject *)
                    (DataModule1 -> People_SpecializFDQueryNOMER -> Value));
            }
            // ------------

            DataModule1 -> People_SpecializFDQuery -> Next ();
        } // end for2
    } // end if  есть студенты для выбранной специализации

    ///----сохранение ведомости
    if (DataModule1 -> Ved_RatingFDQuery -> State == dsInactive)
        DataModule1 -> Ved_RatingFDQuery -> Open ();
    DataModule1 -> Ved_RatingFDQuery -> Insert ();

    try { // try сохранение
        DataModule1 -> Ved_RatingFDQueryN_VEDOMOST_R -> Value =
            StrToInt (Label4 -> Caption);
        DataModule1 -> Ved_RatingFDQueryN_FAC -> Value = nom_fac;
        DataModule1 -> Ved_RatingFDQueryVID_EDU -> Value = ComboBox2 -> ItemIndex;
        DataModule1 -> Ved_RatingFDQueryUCH_GOD -> Value = uch_god;
        DataModule1 -> Ved_RatingFDQuerySEMESTR -> Value = Edit3 -> Text.ToInt ();
        DataModule1 -> Ved_RatingFDQuerySESSION -> Value = Edit1 -> Text.ToInt ();
        DataModule1 -> Ved_RatingFDQueryINC_GROUP -> Value = i_gr_rat;
        DataModule1 -> Ved_RatingFDQueryN_SPECIALIZ -> Value =
            DM2 -> SpecializFDTable -> Lookup ("SPECIAL", ComboBox1 -> Text,
            "N_SPECIALIZ"); ;
        DataModule1 -> Ved_RatingFDQueryD_VED -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);
        DataModule1 -> Ved_RatingFDQueryEND_D_VED -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker2 -> Date);

        DataModule1 -> Ved_RatingFDQueryCURATOR -> Value = Edit4 -> Text;

        // запоминаем инкремент ведомости, для ее удаления в случае если будут отсутствовать студенты
        nom_ved = DataModule1 -> Ved_RatingFDQueryN_VED_RATING -> Value;

        if (DataModule1 -> Ved_RatingFDQueryN_VEDOMOST_R -> Value !=
            Ved_RatingForm -> max_ved_r ()) {
            DataModule1 -> Ved_RatingFDQueryN_VEDOMOST_R -> Value =
                Ved_RatingForm -> max_ved_r ();
            ShowMessage ("Номер вашей ведомости изменился на " +
                AnsiString (DataModule1 -> Ved_RatingFDQueryN_VEDOMOST_R -> Value));
        }
        DataModule1 -> Ved_RatingFDQuery -> Post ();

    } // end try сохранение
    catch (...) {
        ShowMessage (
            "Произошла ошибка при сохранении ведомости. Попробуйте еще раз!");
        DataModule1 -> Ved_RatingFDQuery -> CancelUpdates ();
        return;
    }

    if (DataModule1 -> RatingFDQuery -> State == dsInactive)
        DataModule1 -> RatingFDQuery -> Open ();

    if (CheckBox2 -> State == cbUnchecked)
        // если не включена возможность самостоятельного выбора
    { // ведомость делается автоматически
        for (int i = 0; i < count_rec; i++) {
            if (nom_p[1][i] != 0) {
                DataModule1 -> RatingFDQuery -> Insert ();
                DataModule1 -> RatingFDQueryNOMER -> Value = StrToInt (nom_p[1][i]);
                DataModule1 -> RatingFDQueryN_VED_RATING -> Value = nom_ved;

                DataModule1 -> RatingFDQuery -> ApplyUpdates ();
                save = true;

            }
        } // for
    } // ведомость делается автоматически
    else { // студентов в ведомость выбирают сами

        DualListDlg -> ShowModal ();

        if (DataModule2 -> printdlg == true)
        { // if нажатие кнопки ОК в компоненте
            if (DualListDlg -> DstList -> Items -> Count != 0)
            { // if проверка на выбор хотя бы одного студента в ведомость
                // ---------
                for (int i = 0; i < DualListDlg -> DstList -> Items -> Count; i++)
                { // for первый цикл по  FOutList

                            if (StrToInt (nom_p[1][i]) != 0) { // if   !=0
                                DataModule1 -> RatingFDQuery -> Insert ();
                                DataModule1 -> RatingFDQueryNOMER -> Value =
                                    StrToInt (nom_p[1][i]);
                                DataModule1 -> RatingFDQueryN_VED_RATING -> Value =
                                    nom_ved;

                                DataModule1 -> RatingFDQuery -> ApplyUpdates ();
                                save = true;

                            } // end  if   !=0
                            else { // else
                                ShowMessage ("Студент " + DualListDlg -> DstList -> Items -> Strings[i] +
                                    " уже имеет ведомость!");
                            } // end else


                } // end for первый цикл по  FOutList
            } // if проверка на выбор хотя бы одного студента в ведомость
            else { // else никого не выбрали
                save = false; // переменная для спешного выполнения
            } // end else никого не выбрали
        } // end if нажатие кнопки ОК в компоненте
        else { // else нажали кнопку ОТМЕНИТь
            save = false; // переменная для спешного выполнения

        } // end else нажали кнопку ОТМЕНИТь
    } // студентов в ведомость выбирают сами

    if (save) { // if успешно

        DataModule1 -> Ved_RatingFDQuery -> ApplyUpdates ();
        DataModule1 -> Ved_RatingFDQuery -> CommitUpdates ();
        DataModule1 -> RatingFDQuery -> CommitUpdates ();
    }
    else { // else отменить
        DataModule1 -> Ved_RatingFDQuery -> CancelUpdates ();
    }

    // массив номеров студентов и фамилий
    for (int i = 0; i < 2; i++)
        delete[]nom_p[i];
    // delete[] nom_p;

    // Ved_RatingForm -> ved_run_r ();
    Close ();
}


void __fastcall TDop_Ved_RatingForm::FormActivate (TObject *Sender) {
    if (Panel1 -> Visible)
        Edit2 -> SetFocus ();
}

void __fastcall TDop_Ved_RatingForm::DateTimePicker3Change (TObject *Sender)
{
DateTimePicker3 -> Time = StrToTime ("00:00");
}


void __fastcall TDop_Ved_RatingForm::DateTimePicker4Change (TObject *Sender)
{
          DateTimePicker4 -> Time = StrToTime ("00:00");
}


void __fastcall TDop_Ved_RatingForm::DateTimePicker1Change (TObject *Sender)
{
DateTimePicker1 -> Time = StrToTime ("00:00");
}


void __fastcall TDop_Ved_RatingForm::DateTimePicker2Change (TObject *Sender)
{
DateTimePicker2 -> Time = StrToTime ("00:00");
}



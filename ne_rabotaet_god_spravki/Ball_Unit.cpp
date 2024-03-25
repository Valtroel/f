#include <vcl.h>
#pragma hdrstop


#include "Ball_Unit.h"
#include "CalendarUnit.h"
#include "DataModule.h"
#include "Result_VedUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TBall_Form * Ball_Form;


// BitBtn1Click
// BitBtn2Click
// DBNavigator1Click
// Edit1Change
// Edit1Click
// FormActivate
// FormClose
// Radio_ball
// Radio_setup
// RadioGroup1Click
// RadioGroup2Click



int __fastcall TBall_Form::Radio_setup ()
{ // установка RadioGroup1 -> ItemIndex в значение из базы данных и даты экзамена
    int b = DataModule1 -> Ball_FDQueryBALL -> Value;
    if (b != -1) { // если поле не пустое
        if (b >= 10) { // if 10-ти бальная система
            RadioGroup1 -> ItemIndex = b - 11;
            RadioGroup2 -> ItemIndex = 0;
        } // end if 10-ти бальная система
        else { // else 5-ти бальная система
            switch (DataModule1 -> Ball_FDQueryBALL -> Value) { // switch
            case 1:
                RadioGroup1 -> ItemIndex = 2; // зачет
                RadioGroup2 -> ItemIndex = 0;
                break;
            case 2:
                RadioGroup1 -> ItemIndex = 0; // неудовл.
                RadioGroup2 -> ItemIndex = 1;
                break;
            case 6:
                if (DataModule1 -> Ball_FDQueryZACH_EXAM -> Value == 1)
                    RadioGroup1 -> ItemIndex = 1; // неявился на зачет
                else { // else не явился на экзамен
                    if (RadioGroup2 -> ItemIndex) // пятибалка
                            RadioGroup1 -> ItemIndex = 1;
                    // не явился  на зачет   или экзамен
                    else // если десятибалка
                            RadioGroup1 -> ItemIndex = 10;
                    // не явился  на зачет   или экзамен
                } // end else не явился на экзамен
                break;
            case 7:
                if (DataModule1 -> Ball_FDQueryZACH_EXAM -> Value == 1)
                    RadioGroup1 -> ItemIndex = 3; // освобожден от зачета
                else { // else освобожден от экзамена
                    if (RadioGroup2 -> ItemIndex) // пятибалка
                            RadioGroup1 -> ItemIndex = 2;
                    else // если десятибалка
                            RadioGroup1 -> ItemIndex = 11;
                } // end else освобожден от экзамена
                break;
            default:
                RadioGroup1 -> ItemIndex = b;
                RadioGroup2 -> ItemIndex = 1;
                break;
            } // switch
        } // end else 5-ти бальная система
    }
    else
        RadioGroup1 -> ItemIndex = -1; // если оценки нет, то ничего не выбрано
    // Занесение даты экзамена в Edit1
    Edit1 -> Text =
        DateToStr (SQLTimeStampToDateTime
        (DataModule1 -> Ball_FDQueryD_EXAM -> Value));
    DBNavigator1 -> Enabled = true;
    return RadioGroup1 -> ItemIndex;
}

int __fastcall TBall_Form::Radio_ball ()
{ // передача значения балла в зависимости от RadioGroup1 -> ItemIndex и вида контроля
    int ball_radio;
    if (DataModule1 -> Ball_FDQueryZACH_EXAM -> Value == 1) // это зачет
    { // если зачет
        switch (RadioGroup1 -> ItemIndex) { // switch
        case 1:
            ball_radio = 6; // не явился
            break;
        case 2:
            ball_radio = 1; // зачет
            break;
        case 3:
            ball_radio = 7; // освобожден
            break;
        default:
            ball_radio = RadioGroup1 -> ItemIndex; // незачет
            break;
        } // end switch
    } // end if зачет
    else { // если экзамен или диф. зачет
        if (!RadioGroup2 -> ItemIndex) // проверка на систему оценок
        { // if если система 10-ти бальная
            switch (RadioGroup1 -> ItemIndex) { // switch

            case 10:
                ball_radio = 6; // не явился
                break;
            case 11:
                ball_radio = 7; // освобожден
                break;
            default:
                ball_radio = RadioGroup1 -> ItemIndex + 11;
                // оценки 3,4,5 которые соответствуют  RadioGroup1 -> ItemIndex
                break;
            } // end switch
        } // end if если система 10-ти бальная
        else { // else если система 5-ти бальная
            switch (RadioGroup1 -> ItemIndex) { // switch
            case 0:
                ball_radio = 2; // неудовлетворительно
                break;
            case 1:
                ball_radio = 6; // не явился
                break;
            case 2:
                ball_radio = 7; // освобожден
                break;
            default:
                ball_radio = RadioGroup1 -> ItemIndex;
                // оценки 3,4,5 которые соответствуют  RadioGroup1 -> ItemIndex
                break;
            } // end switch
        } // end else если система 5-ти бальная
    } // end else  экзамен или диф. зачет
    return ball_radio;
}

__fastcall TBall_Form::TBall_Form (TComponent* Owner) : TForm (Owner) {
}

void __fastcall TBall_Form::BitBtn2Click (TObject *Sender)
{ // действия по кнопке Закрыть
    DataModule1 -> Ball_FDQuery -> Close ();
    DataModule1 -> Ball_FDQuery -> ParamByName ("N_FAC") -> AsInteger = nom_fac;
    DataModule1 -> Ball_FDQuery -> ParamByName ("N_VEDOM") -> AsInteger = inc_ved;
    DataModule1 -> Ball_FDQuery -> Open ();
    Close ();
}

void __fastcall TBall_Form::BitBtn1Click (TObject *Sender)
{ // действия по кнопке сохранить
    // переводим Query в режим редактирования и сохраняем значения оценки и дату экзамена
    if (RadioGroup1 -> ItemIndex == -1) {
        ShowMessage ("Проставьте пожалуйста оценку!");
        return;
    }
    DataModule1 -> Ball_FDQuery -> Edit ();
    DataModule1 -> Ball_FDQueryBALL -> Value = Radio_ball ();
    // возвращаем оценку в зависимости от положения
    // RadioGroup1 -> ItemIndex
    DataModule1 -> Ball_FDQueryD_EXAM -> Value = StrToSQLTimeStamp (Edit1 -> Text);
    if ( (DataModule1 -> Ball_FDQueryBALL -> Value >= 14) ||
        (DataModule1 -> Ball_FDQueryBALL -> Value == 1) ||
        (DataModule1 -> Ball_FDQueryBALL -> Value == 3) ||
        (DataModule1 -> Ball_FDQueryBALL -> Value == 4) ||
        (DataModule1 -> Ball_FDQueryBALL -> Value == 5) ||
        (DataModule1 -> Ball_FDQueryBALL -> Value == 7) ||
        (DataModule1 -> Ball_FDQueryBALL -> Value == 6))
    { // значения полученного балла 1-зачет, 3-удовл., 4-хор., 5-отл., 7-освобожден
        // 6 - это неявка, но надо проверить, вдруг они по ошибке занесли другую оценку
        // открытие Query для занесения результатов в итоговую таблицу для учебной карточки RESULT_BALL
        // DataModule1 -> Result_BallQuery -> Close ();
        // DataModule1 -> Result_BallQuery -> ParamByName ("NOM") -> AsInteger=DataModule1 -> Ball_QueryNOMER -> Value;
        // DataModule1 -> Result_BallQuery -> Open ();
        // поиск по номеру студента  и номеру учебного плана
        DataModule1 -> Result_Ball_LocateFDQuery -> Close ();
        DataModule1 -> Result_Ball_LocateFDQuery -> ParamByName ("NOM") -> AsInteger =
            DataModule1 -> Ball_FDQueryNOMER -> Value;
        DataModule1 -> Result_Ball_LocateFDQuery -> ParamByName ("PLAN") -> AsInteger =
            DataModule1 -> Ball_FDQueryN_PLAN -> Value;
        DataModule1 -> Result_Ball_LocateFDQuery -> Open ();

        // TLocateOptions Opts;
        // Opts.Clear ();
        // Variant lv[2];
        // lv[0] = Variant (DataModule1 -> Ball_QueryNOMER -> Value);
        // lv[1] = Variant (DataModule1 -> Ball_QueryN_PLAN -> Value);
        // -----поиск по инкременту ведомости статуса ведомости
        int st; // переменная для сохранения Status_result в  Result_BallQuery
        Variant st_ved = DataModule1 -> VedomostFDQuery -> Lookup ("N_VED",
            DataModule1 -> Ball_FDQueryN_VED -> Value, "STATUS");
        if (!st_ved.IsNull ())
        { // если статус найден, то проверяем какая ведомость была
            int v = st_ved.AsType (varInteger);
            switch (v) {
            case 0:
                st = 1; // Status=0 - это основная ведомость
                break;
            case 3:
                st = 3; // Status=3 - это ведомость на досрочную сдачу
                break;
            case 4:
                st = 4; // Status=4 - это ведомость на ликвидацию разницы
                break;
            default:
                st = 2; // Status=1 и 2 - это дополнит. ведомость или экз.лист
                break;
            }
        }
        // -----
        // if (DataModule1 -> Result_BallQuery -> Locate ("NOMER;N_PLAN", VarArrayOf (lv, 1), Opts))
        if (DataModule1 -> Result_Ball_LocateFDQuery -> RecordCount)
        { // если найдена запись для данного студента по этому учебному плану
            if (DataModule1 -> Ball_FDQueryBALL -> Value == 6) { // if
                // !!!if (Application -> MessageBox ("По этому предмету у студента была оценка. Удалить ее?", "Внимание!!!!", MB_YESNO) == mrYes)
                if (MessageDlg
                    ("По этому предмету у студента была оценка. Удалить ее?",
                    mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes) { // if

                    DataModule1 -> Result_Ball_LocateFDQuery -> Delete ();
                    DataModule1 -> Result_Ball_LocateFDQuery -> ApplyUpdates ();
                    DataModule1 -> Result_Ball_LocateFDQuery -> CommitUpdates ();
                } // end if
            } // end if
            else
                DataModule1 -> Result_Ball_LocateFDQuery -> Edit ();
        } // end if
        else { // если такой записи не найдено, то нужно перейти в режим вставки и ее добавить
            if (DataModule1 -> Ball_FDQueryBALL -> Value != 6) {
                DataModule1 -> Result_Ball_LocateFDQuery -> Insert ();
                DataModule1 -> Result_Ball_LocateFDQueryNOMER -> Value =
                    DataModule1 -> Ball_FDQueryNOMER -> Value;
                DataModule1 -> Result_Ball_LocateFDQueryN_PLAN -> Value =
                    DataModule1 -> Ball_FDQueryN_PLAN -> Value;
            }
        } // end else

        if (DataModule1 -> Ball_FDQueryBALL -> Value != 6)
        { // if ----- продолжение записи значений Result_BallQuery
            DataModule1 -> Result_Ball_LocateFDQueryRESULT -> Value =
                DataModule1 -> Ball_FDQueryBALL -> Value;
            DataModule1 -> Result_Ball_LocateFDQueryDATE_RESULT -> Value =
                DataModule1 -> Ball_FDQueryD_EXAM -> Value;
            DataModule1 -> Result_Ball_LocateFDQuerySTATUS_RESULT -> Value = st;
            // ----
            try { // try проверка на правильность сохранения в Result_BallQuery
                DataModule1 -> Result_Ball_LocateFDQuery -> ApplyUpdates ();
                DataModule1 -> Result_Ball_LocateFDQuery -> CommitUpdates ();
            } // end tre
            catch (...) { // catch
                ShowMessage ("Не сохранены данные в учебную карточку");

                DataModule1 -> Result_Ball_LocateFDQuery -> CancelUpdates ();
            } // end catch
        } // end if ----- продолжение записи значений Result_BallQuery
        // ------
    }
    try {
        DataModule1 -> Ball_FDQuery -> ApplyUpdates ();
        DataModule1 -> Ball_FDQuery -> CommitUpdates ();

    }
    catch (...) {
        ShowMessage ("Не сохранена оценка студента!");
        DataModule1 -> Ball_FDQuery -> CancelUpdates ();

    }
    DBNavigator1 -> Enabled = true;
}

void __fastcall TBall_Form::DBNavigator1Click (TObject *Sender,
    TNavigateBtn Button)
{ // установка значения RadioGroup1 -> ItemIndex - оценка полученная на экзамене
    Radio_setup ();
}

void __fastcall TBall_Form::Edit1Click (TObject *Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> ShowModal ();
    Edit1 -> Text = cal_date;
}

void __fastcall TBall_Form::Edit1Change (TObject *Sender) {
    DBNavigator1 -> Enabled = false;
}

void __fastcall TBall_Form::FormActivate (TObject *Sender) {
    /* DataModule1 -> Edu_CardQuery -> Close ();
     DataModule1 -> Edu_CardQuery -> SQL -> Clear ();
     DataModule1 -> Edu_CardQuery -> SQL -> Add ("SELECT * FROM EDU_CARD ORDER BY N_VED");
     DataModule1 -> Edu_CardQuery -> Open (); */
}

void __fastcall TBall_Form::FormClose (TObject *Sender, TCloseAction &Action) {
    Action = caFree;
}

void __fastcall TBall_Form::RadioGroup1Click (TObject *Sender) {
    DBNavigator1 -> Enabled = false;
}

void __fastcall TBall_Form::RadioGroup2Click (TObject *Sender) {
    Result_VedForm -> RadioGroup_Ball ();
    // процедура для установки Items-ов в  RadioGroup1
    Radio_setup ();
    // в зависимости от вида контроля и системы оценок
}

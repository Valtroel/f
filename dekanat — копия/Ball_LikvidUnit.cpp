#include <vcl.h>
#pragma hdrstop


#include "Ball_LikvidUnit.h"
#include "DataModule.h"


#pragma package (smart_init)
// !!!#pragma link "ToolEdit"
#pragma resource "*.dfm"


TBall_LikvidForm *Ball_LikvidForm;



// BitBtn1Click
// DateTimePicker1Change
// DateTimePicker2Change
// DateTimePicker3Change
// FormClose
// Radio1_ball
// Radio1_base
// radio1_setup
// RadioGroup2Click




__fastcall TBall_LikvidForm::TBall_LikvidForm (TComponent* Owner) : TForm (Owner)
{
}

void __fastcall TBall_LikvidForm::radio1_setup ()
{ // процедура для установки Items-ов в  RadioGroup1
    // Вид контроля  0 - нет контроля
    // 1 - зачет
    // 2 - экзамен
    // 3 - диф. зачет

    RadioGroup1 -> Items -> Clear ();

    if (DataModule1 -> Ved_LikvidGridFDQueryZACH_EXAM -> Value)
    { // if есть вид контролЯ
        if (DataModule1 -> Ved_LikvidGridFDQueryZACH_EXAM -> Value == 1)
            // это зачет
        { // if  зачет
            RadioGroup1 -> Caption = "Зачет:";

            RadioGroup1 -> Items -> Add ("Незачет");
            RadioGroup1 -> Items -> Add ("Не явился");
            RadioGroup1 -> Items -> Add ("Зачет");
            RadioGroup1 -> Items -> Add ("Освобожден");
        } // end if  зачет
        else { // else  Экзамен    Диф. зачет
            if (DataModule1 -> Ved_LikvidGridFDQueryZACH_EXAM -> Value == 2)
                RadioGroup1 -> Caption = "Экзамен:";
            else
                RadioGroup1 -> Caption = "Диф. зачет:";

            if (!RadioGroup2 -> ItemIndex) // проверка на систему оценок
            { // if если система 10-ти бальная
                RadioGroup1 -> Items -> Add ("Один");
                RadioGroup1 -> Items -> Add ("Два");
                RadioGroup1 -> Items -> Add ("Три");
                RadioGroup1 -> Items -> Add ("Четыре");
                RadioGroup1 -> Items -> Add ("Пять");
                RadioGroup1 -> Items -> Add ("Шесть");
                RadioGroup1 -> Items -> Add ("Семь");
                RadioGroup1 -> Items -> Add ("Восемь");
                RadioGroup1 -> Items -> Add ("Девять");
                RadioGroup1 -> Items -> Add ("Десять");
                RadioGroup1 -> Items -> Add ("Не явился");
                RadioGroup1 -> Items -> Add ("Освобожден");
                RadioGroup1 -> Columns = 3;
                RadioGroup1 -> Width = 290;
            } // end if если система 10-ти бальная
            else { // else если система 5-ти бальная
                RadioGroup1 -> Items -> Add ("Неудовл.");
                RadioGroup1 -> Items -> Add ("Не явился");
                RadioGroup1 -> Items -> Add ("Освобожден");
                RadioGroup1 -> Items -> Add ("Удовл.");
                RadioGroup1 -> Items -> Add ("Хорошо");
                RadioGroup1 -> Items -> Add ("Отлично");
                RadioGroup1 -> Columns = 2;
                RadioGroup1 -> Width = 217;
            } // end else если система 5-ти бальная
        } // end else  Экзамен    Диф. зачет
    } // end if есть вид контролЯ
    else { // else нет вида контроля
        RadioGroup1 -> Caption = "Без вида контроля:";

        RadioGroup1 -> Items -> Add ("Не прослушан");
        RadioGroup1 -> Items -> Add ("Прослушан");

        RadioGroup1 -> Columns = 1;
    } // else нет вида контроля

}

int __fastcall TBall_LikvidForm::Radio1_ball ()
{ // передача значения балла в зависимости от RadioGroup1 -> ItemIndex и вида контроля
    int ball_radio;

    if (DataModule1 -> Ved_LikvidGridFDQueryZACH_EXAM -> Value)
    { // if есть вид контролЯ
        if (DataModule1 -> Ved_LikvidGridFDQueryZACH_EXAM -> Value == 1)
            // это зачет
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
    } // end if есть вид контролЯ
    else { // else нет вида контроля
        switch (RadioGroup1 -> ItemIndex) { // switch
        case 0:
            ball_radio = 8; // не прослушан
            break;
        case 1:
            ball_radio = 9; // прослушан
            break;
        } // end switch

    } // else нет вида контроля

    return ball_radio;
}

int __fastcall TBall_LikvidForm::Radio1_base ()
{ // установка RadioGroup1 -> ItemIndex в значение из базы данных
    // и даты экзамена
    Variant b = DataModule1 -> Ved_LikvidGridFDQueryBALL -> AsVariant;
    if (!b.IsNull ()) { // если поле не пустое
        if (b >= 10) { // if 10-ти бальная система
            RadioGroup1 -> ItemIndex = b - 11;
            RadioGroup2 -> ItemIndex = 0;
        } // end if 10-ти бальная система
        else { // else 5-ти бальная система
            switch (DataModule1 -> Ved_LikvidGridFDQueryBALL -> Value)
                // (DataModule1 -> Ball_QueryBALL -> Value)
            { // switch
            case 1:
                RadioGroup1 -> ItemIndex = 2; // зачет
                RadioGroup2 -> ItemIndex = 0;
                break;
            case 2:
                RadioGroup1 -> ItemIndex = 0; // неудовл.
                RadioGroup2 -> ItemIndex = 1;
                break;
            case 6:
                if (RadioGroup2 -> ItemIndex) // пятибалка
                        RadioGroup1 -> ItemIndex = 1;
                // не явился  на зачет   или экзамен
                else // если десятибалка
                        RadioGroup1 -> ItemIndex = 10;
                // не явился  на зачет   или экзамен
                break;
            case 7:
                if (DataModule1 -> Ved_LikvidGridFDQueryZACH_EXAM -> Value == 1)
                    RadioGroup1 -> ItemIndex = 3; // освобожден от зачета
                else { // else освобожден от экзамена
                    if (RadioGroup2 -> ItemIndex) // пятибалка
                            RadioGroup1 -> ItemIndex = 2;
                    else // если десятибалка
                            RadioGroup1 -> ItemIndex = 11;
                } // end else освобожден от экзамена
                break;
            case 8:
                RadioGroup1 -> ItemIndex = 0; // не прослушан
                RadioGroup2 -> ItemIndex = 0;
                break;
            case 9:
                RadioGroup1 -> ItemIndex = 1; // прослушан
                RadioGroup2 -> ItemIndex = 0;
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

    // Занесение даты экзамена в DateEdit3
    Variant date_ex = DataModule1 -> Ved_LikvidGridFDQueryD_EXAM -> AsVariant;
    if (!date_ex.IsNull ()) {
        DateTimePicker3 -> Date =
            SQLTimeStampToDateTime (DataModule1 -> Ved_LikvidGridFDQueryD_EXAM
            -> Value);
    }
    else {
        DateTimePicker3 -> Date = Now ();
        DateTimePicker3 -> Time = StrToTime ("00:00");
    }
    return RadioGroup1 -> ItemIndex;
}

void __fastcall TBall_LikvidForm::FormClose (TObject *Sender,
    TCloseAction &Action) {
    Action = caFree;
}

void __fastcall TBall_LikvidForm::RadioGroup2Click (TObject *Sender) {
    radio1_setup (); // процедура для установки Items-ов в  RadioGroup1
    Radio1_base ();
}

void __fastcall TBall_LikvidForm::BitBtn1Click (TObject *Sender)
{ // кнопка СОХРАНИТЬ
    if (Panel2 -> Visible) { // if редактирование оценки

        if (RadioGroup1 -> ItemIndex == -1) { // if Ввод оценки
            ShowMessage ("Введите оценку!");
            Ball_LikvidForm -> ModalResult = 0;
            return;
        } // end if Ввод оценки

        // сохранение данных по ведомости
        DataModule1 -> Ved_LikvidGridFDQuery -> Edit ();
        int Ball_Q = Radio1_ball ();
        DataModule1 -> Ved_LikvidGridFDQueryBALL -> Value = Ball_Q;
        DataModule1 -> Ved_LikvidGridFDQueryD_EXAM -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker3 -> Date);

        // сохрание в учебную карточку результата
        if ( (Ball_Q >= 14) || (Ball_Q == 1) || (Ball_Q == 3) || (Ball_Q == 4) ||
            (Ball_Q == 5) || (Ball_Q == 7) || (Ball_Q == 6) || (Ball_Q == 9))
        { // if значения полученного балла 1-зачет, 3-удовл., 4-хор., 5-отл., 7-освобожден , 9-прослушан
            // 6 - это неявка, но надо проверить, вдруг они по ошибке занесли другую оценку
            // открытие Query для занесения результатов в итоговую таблицу для учебной карточки RESULT_BALL
            // DataModule1 -> Result_BallQuery -> Close ();
            // DataModule1 -> Result_BallQuery -> ParamByName ("NOM") -> AsInteger=DataModule1 -> Ved_LikvidGridQueryNOMER -> Value;
            // DataModule1 -> Result_BallQuery -> Open ();

            // поиск по номеру студента  и номеру учебного плана
            DataModule1 -> Result_Ball_LocateFDQuery -> Close ();
            DataModule1 -> Result_Ball_LocateFDQuery -> ParamByName ("NOM")
                -> AsInteger = DataModule1 -> Ved_LikvidGridFDQueryNOMER -> Value;
            DataModule1 -> Result_Ball_LocateFDQuery -> ParamByName ("PLAN")
                -> AsInteger = DataModule1 -> Ved_LikvidGridFDQueryN_PLAN -> Value;
            DataModule1 -> Result_Ball_LocateFDQuery -> Open ();

            // TLocateOptions Opts;
            // Opts.Clear ();
            // Variant lv[2];
            // lv[0] = Variant (DataModule1 -> Ved_LikvidGridQueryNOMER -> Value);
            // lv[1] = Variant (DataModule1 -> Ved_LikvidGridQueryN_PLAN -> Value);

            // -----
            // if (DataModule1 -> Result_BallQuery -> Locate ("NOMER;N_PLAN", VarArrayOf (lv, 1), Opts))
            if (DataModule1 -> Result_Ball_LocateFDQuery -> RecordCount)
            { // если найдена запись для данного студента по этому учебному плану
                if (Ball_Q == 6) { // if
                    // !!!if (Application -> MessageBox ("По этому предмету у студента была оценка. Удалить ее?", "Внимание!!!!", MB_YESNO) == mrYes)
                    if (MessageDlg
                        ("По этому предмету у студента была оценка. Удалить ее?"
                        , mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes) { // if

                        DataModule1 -> Result_Ball_LocateFDQuery -> Delete ();
                        DataModule1 -> Result_Ball_LocateFDQuery -> ApplyUpdates ();
                        DataModule1 -> Result_Ball_LocateFDQuery -> CommitUpdates ();
                    } // end if
                } // end if
                else
                    DataModule1 -> Result_Ball_LocateFDQuery -> Edit ();
            } // end if
            else { // если такой записи не найдено, то нужно перейти в режим вставки и ее добавить
                if (Ball_Q != 6) {
                    DataModule1 -> Result_Ball_LocateFDQuery -> Insert ();
                    DataModule1 -> Result_Ball_LocateFDQueryNOMER -> Value =
                        DataModule1 -> Ved_LikvidGridFDQueryNOMER -> Value;
                    DataModule1 -> Result_Ball_LocateFDQueryN_PLAN -> Value =
                        DataModule1 -> Ved_LikvidGridFDQueryN_PLAN -> Value;

                    DataModule1 -> Result_Ball_LocateFDQuerySTATUS_RESULT -> 
                        Value = 4;
                    // Status=4 - это ведомость на ликвидацию разницы
                }
            } // end else
            if (Ball_Q != 6) { // if продолжение сохранения в Result_Ball
                DataModule1 -> Result_Ball_LocateFDQueryRESULT -> Value =
                    DataModule1 -> Ved_LikvidGridFDQueryBALL -> Value;
                DataModule1 -> Result_Ball_LocateFDQueryDATE_RESULT -> Value =
                    DataModule1 -> Ved_LikvidGridFDQueryD_EXAM -> Value;
                try { // try сохранить

                    // try проверка на правильность сохранения в Result_BallQuery
                    DataModule1 -> Result_Ball_LocateFDQuery -> ApplyUpdates ();
                    DataModule1 -> Result_Ball_LocateFDQuery -> CommitUpdates ();
                } // end try сохранить
                catch (...) { // catch отменить редактирование

                    DataModule1 -> Result_Ball_LocateFDQuery -> CancelUpdates ();

                    ShowMessage (
                        "Произошел сбой при сохранении. Попробуйте еще раз!");
                } // end catch отменить редактирование

            } // end if продолжение сохранения в Result_Ball
        } // end  if значения полученного балла 1-зачет, 3-удовл., 4-хор., 5-отл., 7-освобожден
        // ---

        try { // try сохранить
            DataModule1 -> Ved_LikvidGridFDQuery -> ApplyUpdates ();
            DataModule1 -> Ved_LikvidGridFDQuery -> CommitUpdates ();

            ShowMessage ("Сохранение прошло успешно!");
        } // end try сохранить
        catch (...) { // catch отменить редактирование
            DataModule1 -> Ved_LikvidGridFDQuery -> CancelUpdates ();

            ShowMessage ("Произошел сбой при сохранении. Попробуйте еще раз!");
        } // end catch отменить редактирование

    } // end if редактирование оценки
    else { // else редактирование ведомости

        if (Edit3 -> Text == "") { // if ФИО экзаменатора
            ShowMessage ("Введите фамилию экзаменатора!");
            Ball_LikvidForm -> ModalResult = 0;
            return;
        } // if ФИО экзаменатора

        // сохранение данных по ведомости
        DataModule1 -> Ved_LikvidGridFDQuery -> Edit ();
        DataModule1 -> Ved_LikvidGridFDQueryD_VED -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);
        DataModule1 -> Ved_LikvidGridFDQueryEND_D_EXAM -> Value =
            DateTimeToSQLTimeStamp (DateTimePicker2 -> Date);
        DataModule1 -> Ved_LikvidGridFDQueryFIO_EXAM -> Value = Edit3 -> Text;

        try { // try сохранить
            DataModule1 -> Ved_LikvidGridFDQuery -> ApplyUpdates ();
            DataModule1 -> Ved_LikvidGridFDQuery -> CommitUpdates ();

            ShowMessage ("Сохранение прошло успешно!");
        } // end try сохранить
        catch (...) { // catch отменить редактирование
            DataModule1 -> Ved_LikvidGridFDQuery -> CancelUpdates ();

            ShowMessage ("Произошел сбой при сохранении. Попробуйте еще раз!");
        } // end catch отменить редактирование

    } // end else редактирование ведомости
}
void __fastcall TBall_LikvidForm::DateTimePicker1Change (TObject *Sender)
{
DateTimePicker1 -> Time = StrToTime ("00:00");
}

void __fastcall TBall_LikvidForm::DateTimePicker2Change (TObject *Sender)
{
DateTimePicker2 -> Time = StrToTime ("00:00");
}

void __fastcall TBall_LikvidForm::DateTimePicker3Change (TObject *Sender)
{
DateTimePicker3 -> Time = StrToTime ("00:00");
}


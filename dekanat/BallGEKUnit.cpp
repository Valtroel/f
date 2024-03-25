#include <vcl.h>
#pragma hdrstop


#include "BallGEKUnit.h"
#include "DataModule.h"
#include "DM3Unit.h"
#include "VED_GEKResultUnit.h"


#pragma package (smart_init)
// #pragma link     "ToolEdit"
#pragma resource "*.dfm"


TBall_GEK * Ball_GEK;


// BitBtn1Click
// BitBtn2Click
// DBNavigator1Click
// FormActivate
// FormClose
// Radio_ball_baza
// Radio_setup_baza
// RadioButton1Click
// RadioButton2Click
// RadioGroup2Click



int __fastcall TBall_GEK::Radio_setup_baza ()
{ // установка RadioGroup1 -> ItemIndex в значение из базы данных
//и даты экзамена
//-----открываем  GEKResultBall  по параметрам для просмотра  результатов
DataModule1 -> GEKResultBallFDQuery -> Close ();
DataModule1 -> GEKResultBallFDQuery -> ParamByName ("N_VED") -> Value=DM3 -> GEKResultGridFDQueryN_VED -> Value;
DataModule1 -> GEKResultBallFDQuery -> ParamByName ("NOMER") -> Value=DM3 -> GEKResultGridFDQueryNOMER -> Value;
DataModule1 -> GEKResultBallFDQuery -> Open ();
//-----
Variant b=DataModule1 -> GEKResultBallFDQueryBALL_GEK -> AsVariant;
if (!b.IsNull ())
{//if если поле не пустое и имеет значение
   if (b>=10)
   { //if 10-ти бальная система
     RadioGroup2 -> ItemIndex=0;
     RadioGroup2Click (this);//заполнение RadioGroup2 Items-ами
     RadioGroup1 -> ItemIndex=b-11;

   } //end if 10-ти бальная система
   else
   {//else 5-ти бальная система
         RadioGroup2 -> ItemIndex=1;
         RadioGroup2Click (this);//заполнение RadioGroup2 Items-ами
         RadioGroup1 -> ItemIndex=b-2;   //все значения соответствуют значениям из базы - 2
         

    }//end else 5-ти бальная система

//Занесение даты и номера протокола
//Edit2 -> Text=IntToStr (DM3 -> GEKResultBallN_PROTOCOL -> Value);        //номер протокола
//DateEdit1 -> Text=DM3 -> GEKResultBallD_PROTOCOL -> Value;    //дата протокола

}//end if если поле не пустое и имеет значение
else
{//else значений нет никаких установки по умолчанию
 RadioGroup1 -> ItemIndex=-1; //если оценки нет, то ничего не выбрано
 RadioGroup2 -> ItemIndex=0;//Устанавливаем по умолчанию 10-ти бальную систему
 RadioGroup2Click (this);
 //Edit2 -> Text="";//пустое значение номера протокола
// DateEdit1 -> Text="  .  .    ";     //пустое значение даты протокола
}//end else значений нет никаких установки по умолчанию

DBNavigator1 -> Enabled=true;
return RadioGroup1 -> ItemIndex; //возвращаем положение в  RadioGroup1 в зависимости от оценки
}
int __fastcall TBall_GEK::Radio_ball_baza ()
{//передача значения балла в зависимости от RadioGroup1 -> ItemIndex и системы оценок
int ball_radio;

     if (!RadioGroup2 -> ItemIndex)//проверка на систему оценок
      { //if если система 10-ти бальная
          switch (RadioGroup1 -> ItemIndex)
                {//switch

                case 10:  ball_radio=6; //не явился
                        break;
                
                default: ball_radio=RadioGroup1 -> ItemIndex+11; //оценки соответствуют  RadioGroup1 -> ItemIndex +11
                        break;
                }//end switch
      }//end if если система 10-ти бальная
      else
      {//else если система 5-ти бальная

          ball_radio=RadioGroup1 -> ItemIndex+2; //оценки 2,3,4,5 и 6 (неявка) соответствуют  RadioGroup1 -> ItemIndex+2

      }//end else если система 5-ти бальная

return ball_radio;
}
__fastcall TBall_GEK::TBall_GEK (TComponent* Owner)
        : TForm (Owner)
{
}
void __fastcall TBall_GEK::FormClose (TObject *Sender, TCloseAction &Action)
{
    Action=caFree;    
}
void __fastcall TBall_GEK::FormActivate (TObject *Sender)
{

Radio_setup_baza ();//процедура установки значений из базы, если они существуют

    if ( (DM3 -> GEKResultGridFDQueryTHEME -> Value=="")|| (DM3 -> GEKResultGridFDQueryTHEME -> AsVariant.IsNull ()))
    {
        RadioButton2 -> Checked=false;
        RadioButton1 -> Checked=true;
        Memo1 -> Clear ();
        Label2 -> Visible=false;
        Memo1 -> Visible=false;
     }
    else
    {
       RadioButton2 -> Checked=true;
       RadioButton1 -> Checked=false;
       Label2 -> Visible=true;
       Memo1 -> Visible=true;
       Memo1 -> Text=DM3 -> GEKResultGridFDQueryTHEME -> Value;
    }

}          
void __fastcall TBall_GEK::RadioButton2Click (TObject *Sender)
{  //щелчек на дипломе
   Label2 -> Visible=true;
   Memo1 -> Visible=true;
}
void __fastcall TBall_GEK::RadioButton1Click (TObject *Sender)
{  //щелчек на ГОСе
      Label2 -> Visible=false;
      Memo1 -> Clear ();
      Memo1 -> Visible=false;
}

void __fastcall TBall_GEK::BitBtn1Click (TObject *Sender)
{  //Действие по кнопке СОХРАНИТЬ
//----
if  (!RadioButton2 -> Checked &&  !RadioButton1 -> Checked)
  { //if проверка чтобы было выбрано одно из значений (диплом или ГОС)
    ShowMessage ("Выберите статус : Диплом  или Гос. экзамен!!!");
    return;
  }//end if проверка чтобы было выбрано одно из значений (диплом или ГОС)
//----
if (RadioGroup1 -> ItemIndex==-1)
  { //if    проверка на проставленную оценку
    ShowMessage ("Проставьте оценку по ГОС. экзамену или диплому");
    return;
  }//end if  проверка на проставленную оценку
//-----
if  (RadioButton2 -> Checked  &&  Memo1 -> Text=="")
  { //if    проверка на ввод темы диплома, если выбран экзамен диплом
    ShowMessage ("Вы выбрали диплом, но забыли ввести тему диплома!");
    return;
  }//end if  проверка на ввод темы диплома, если выбран экзамен диплом

    DataModule1 -> GEKResultBallFDQuery -> Close ();
    DataModule1 -> GEKResultBallFDQuery -> ParamByName ("N_VED") -> Value=DM3 -> GEKResultGridFDQueryN_VED -> Value;
    DataModule1 -> GEKResultBallFDQuery -> ParamByName ("NOMER") -> Value=DM3 -> GEKResultGridFDQueryNOMER -> Value;
    DataModule1 -> GEKResultBallFDQuery -> Open ();
    DataModule1 -> GEKResultBallFDQuery -> Edit ();
    if (Memo1 -> Text!="")
       {//if сдавали диплом на тему
          DataModule1 -> GEKResultBallFDQueryTHEME -> Value=Memo1 -> Text;
       }//end if сдавали диплом на тему
    else
       {//else сдавали ГОС, то в это поле ничего не заносится
       DataModule1 -> GEKResultBallFDQueryTHEME -> Value="";
       }//end else сдавали ГОС, то в это поле ничего не заносится

     //--сохранение балла из процедуры, возвращающей оценку по состоянию RadioGroup1
     //-- и выбранной системы оценки
     DataModule1 -> GEKResultBallFDQueryBALL_GEK -> Value=Radio_ball_baza ();

  /*   //--- сохранение номера протокола и даты протокола
     try
       {//try проверка на введенную цифру
         DM3 -> GEKResultBallN_PROTOCOL -> Value=StrToInt (Edit2 -> Text);
       }//end try проверка на введенную цифру
     catch (...)
       { //catch если возникла ошибка конверсии типов
        ShowMessage ("Номер протокола должен содержать цифровое значение!");
        DM3 -> GEKResultBall -> CancelUpdates ();
        return;
       }//end catch если возникла ошибка конверсии типов   */
   //  DM3 -> GEKResultBallD_PROTOCOL -> Value=DateEdit1 -> Text;

       try
        {//try проверка на удачное сохранение оценки
          DataModule1 -> GEKResultBallFDQuery -> ApplyUpdates ();
          DataModule1 -> GEKResultBallFDQuery -> CommitUpdates ();
          DataModule1 -> GEKResultBallFDQuery -> Close ();
         // Memo1 -> Clear ();
        } //end try проверка на удачное сохранение оценки
       catch (...)
        { //catch
           DataModule1 -> GEKResultBallFDQuery -> CancelUpdates ();
           ShowMessage ("Произошел сбой при сохранении. Попробуйте еще раз!");
        } //end catch
DBNavigator1 -> Enabled=true;        
}

void __fastcall TBall_GEK::BitBtn2Click (TObject *Sender)
{ //Действие по кнопке ЗАКРЫТЬ
     Ball_GEK -> Close ();
     DM3 -> GEKResultGridFDQuery -> Close ();
     DM3 -> GEKResultGridFDQuery -> Open ();

}

void __fastcall TBall_GEK::DBNavigator1Click (TObject *Sender,
      TNavigateBtn Button)
{
     FormActivate (Sender);
}

void __fastcall TBall_GEK::RadioGroup2Click (TObject *Sender)
{//переключение между системами оценок
RadioGroup1 -> Items -> Clear ();
if (!RadioGroup2 -> ItemIndex)//проверка на систему оценок
      { //if если система 10-ти бальная
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
        RadioGroup1 -> Columns=3;
      }//end if если система 10-ти бальная
      else
      {//else если система 5-ти бальная
        RadioGroup1 -> Items -> Add ("Неудовл.");
        RadioGroup1 -> Items -> Add ("Удовл.");
        RadioGroup1 -> Items -> Add ("Хорошо");
        RadioGroup1 -> Items -> Add ("Отлично");
        RadioGroup1 -> Items -> Add ("Не явился");
        RadioGroup1 -> Columns=2;
       }//end else если система 5-ти бальная
}



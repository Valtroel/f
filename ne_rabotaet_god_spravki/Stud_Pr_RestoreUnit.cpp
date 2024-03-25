//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Stud_Pr_RestoreUnit.h"
#include "DataModule.h"
#include "DM2Unit.h"
//---------------------------------------------------------------------------
#pragma package (smart_init)
//!!!#pragma link "ToolEdit"
#pragma resource "*.dfm"
TStud_Pr_RestoreForm *Stud_Pr_RestoreForm;
int nom_student;//номер студента
//---------------------------------------------------------------------------
__fastcall TStud_Pr_RestoreForm::TStud_Pr_RestoreForm (TComponent* Owner)
        : TForm (Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TStud_Pr_RestoreForm::FormClose (TObject *Sender, TCloseAction &Action)
{
/*if (Bookmark)
   { //if закладка

        DataModule1 -> PeopleQuery -> FreeBookmark (Bookmark);
   }//end if закладка    */


Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TStud_Pr_RestoreForm::BitBtn1Click (TObject *Sender)
{//Действие по кнопке СОХРАНИТЬ приказ на отчисление
//-------
/*if (RadioGroup1 -> ItemIndex==-1)
{
 ShowMessage ("Выберите вид приказа!");
 return;
}      */
//-------
if (DBLookupComboBox1 -> Text=="")
{
 ShowMessage ("Выберите причину отчисления студента!");
 return;
}
//-------
if (Edit1 -> Text=="")
{
ShowMessage ("Выберите № приказа на отчисление!");
 return;
}
//-------
/*!!!if (DateTimePicker1 -> Value=="  .  .    ")
{
ShowMessage ("Выберите дату приказа на отчисление!");
 return;
}  */
//-------
int n_prikaz;//переменная для номера приказа
try
{//try на ввод цифрового значения приказа
  n_prikaz=StrToInt (Edit1 -> Text); //№ приказа
}//end try на ввод цифрового значения приказа
catch (...)
{//catch неверно введен номер приказа
  ShowMessage ("Неверно введен № приказа!");
  return;
}//end catch неверно введен номер приказа
//-----------------

try
 {//try Insert
   if (DataModule1 -> RestoreFDQuery -> State==dsInactive) DataModule1 -> RestoreFDQuery -> Open ();
   DataModule1 -> RestoreFDQuery -> Insert ();
   DataModule1 -> RestoreFDQueryNOMER -> Value=nom_student; //номер студента
   DataModule1 -> RestoreFDQueryN_CAUSE_RESTORE -> Value=DBLookupComboBox1 -> KeyValue;//причина отчисления
   DataModule1 -> RestoreFDQueryN_PRIKAZ_RES -> Value=n_prikaz;//№ приказа на отчисление
   DataModule1 -> RestoreFDQueryD_PRIKAZ_RES -> Value=DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);//Дата приказа на отчисление
   DataModule1 -> RestoreFDQueryVID_RESTORE -> Value=1; //отчисление
   DataModule1 -> RestoreFDQueryDESCRIBE -> Value=Edit2 -> Text;//примечания
   try
     { //try проверка на ввод в № приказа числового значения
         DataModule1 -> RestoreFDQuery -> ApplyUpdates ();
         DataModule1 -> RestoreFDQuery -> CommitUpdates ();
     }//end try проверка на ввод в № приказа
   catch (...)
     {//catch неверно введен приказ
         DataModule1 -> RestoreFDQuery -> CancelUpdates ();
         ShowMessage ("Не удалось сохранить приказ на отчисление!");

     }//end catch неверно введен приказ

     
  /* switch (RadioGroup1 -> ItemIndex)
           {//switch выбор вида приказа
            case 0: //приказ на отчисление
                  if (DataModule1 -> RestoreQuery -> State==dsInactive) DataModule1 -> RestoreQuery -> Open ();
                  DataModule1 -> RestoreQuery -> Insert ();
                  DataModule1 -> RestoreQueryNOMER -> Value=nom_student; //номер студента
                  DataModule1 -> RestoreQueryN_CAUSE_RESTORE -> Value=DBLookupComboBox1 -> KeyValue;//причина отчисления
                  DataModule1 -> RestoreQueryN_PRIKAZ_RES -> Value=n_prikaz;//№ приказа на отчисление
                  DataModule1 -> RestoreQueryD_PRIKAZ_RES -> Value=DateEdit1 -> Text;//Дата приказа на отчисление
                  DataModule1 -> RestoreQueryVID_RESTORE -> Value=1; //отчисление
                  DataModule1 -> RestoreQueryDESCRIBE -> Value=Edit2 -> Text;//примечания
                  try
                    { //try проверка на ввод в № приказа числового значения
                        DataModule1 -> RestoreQuery -> ApplyUpdates ();
                        DataModule1 -> RestoreQuery -> CommitUpdates ();
                    }//end try проверка на ввод в № приказа
                  catch (...)
                    {//catch неверно введен приказ
                        DataModule1 -> RestoreQuery -> CancelUpdates ();
                        ShowMessage ("Не удалось сохранить приказ на отчисление!");

                    }//end catch неверно введен приказ

                  break;
            case 1: //приказ на перевод из другого ВУЗа
                  if (DataModule1 -> Public_PrikazQuery -> State==dsInactive) DataModule1 -> Public_PrikazQuery -> Open ();
                  DataModule1 -> Public_PrikazQuery -> Insert ();
                  DataModule1 -> Public_PrikazQueryNOMER -> Value=nom_student; //номер студента
                  DataModule1 -> Public_PrikazQueryN_PUBLIC_PRIKAZ -> Value=n_prikaz;//№ приказа
                  DataModule1 -> Public_PrikazQueryD_PUBLIC_PRIKAZ -> Value=DateEdit1 -> Text;//Дата приказа
                  DataModule1 -> Public_PrikazQueryN_TYPE -> Value=7; //Тип приказа перевод из другого ВУЗа
                  DataModule1 -> Public_PrikazQueryDESCRIBE -> Value=Edit2 -> Text;//примечания
                  try
                    { //try проверка на ввод в № приказа числового значения
                        DataModule1 -> Public_PrikazQuery -> ApplyUpdates ();
                        DataModule1 -> Public_PrikazQuery -> CommitUpdates ();
                    }//end try проверка на ввод в № приказа
                  catch (...)
                    {//catch неверно введен приказ
                        DataModule1 -> Public_PrikazQuery -> CancelUpdates ();
                        ShowMessage ("Не удалось сохранить приказ на перевод из другого ВУЗа!");

                    }//end catch неверно введен приказ
                  break;
           }//end switch выбор вида приказа   */
Stud_Pr_RestoreForm -> Close ();
 }//end try Insert
catch (...)
 {//catch не получилось сохранить
    ShowMessage ("Произошла ошибка при сохранении приказа!");
 }//end catch не получилось сохранить



}
//---------------------------------------------------------------------------
void __fastcall TStud_Pr_RestoreForm::RadioGroup1Click (TObject *Sender)
{//выбор вида приказа
   switch (RadioGroup1 -> ItemIndex)
           {//switch выбор вида приказа
            case 0: //приказ на отчисление
                    Label4 -> Visible=true;
                    DBLookupComboBox1 -> Visible=true;
                    Label3 -> Caption="Примечания:";
                    break;
            case 1: //приказ на отчисление
                    Label4 -> Visible=false;
                    DBLookupComboBox1 -> Visible=false;
                    Label3 -> Caption="Обучался в:";
                    break;
           }//end switch выбор вида приказа
}
//---------------------------------------------------------------------------

void __fastcall TStud_Pr_RestoreForm::FormCreate (TObject *Sender)
{
//переход по закладке на нужную запись студента
DataModule1 -> PeopleFDQuery -> GotoBookmark (Bookmark);
nom_student=DataModule1 -> PeopleFDQueryNOMER -> Value;
DataModule1 -> PeopleFDQuery -> FreeBookmark (Bookmark);
DateTimePicker1 -> Date = Now ();
DateTimePicker1 -> Time = StrToTime ("00:00");
}
//---------------------------------------------------------------------------

void __fastcall TStud_Pr_RestoreForm::Edit1KeyPress (TObject *Sender,
      char &Key)
{
DataModule1 -> Edit_Key (Key); //Как сделать, чтобы в TEdit можно было вводить только числа?        
}
//---------------------------------------------------------------------------

void __fastcall TStud_Pr_RestoreForm::DateTimePicker1Change (TObject *Sender)
{
DateTimePicker1 -> Time = StrToTime ("00:00");
}
//---------------------------------------------------------------------------


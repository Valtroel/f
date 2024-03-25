
//Форма Статистика

//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "StatisticUnit.h"
#include "CalendarUnit.h"
#include "DataModule.h"
#include "DM2Unit.h"
#include "Func.h"
//---------------------------------------------------------------------------
#pragma package (smart_init)
#pragma resource "*.dfm"

TStatisticForm *StatisticForm;
//---------------------------------------------------------------------------
__fastcall TStatisticForm::TStatisticForm (TComponent* Owner)
    : TForm (Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TStatisticForm::Edit1Click (TObject *Sender)
{   //Вызов календаря по щелчку мышью
 CalendarForm = new  TCalendarForm (this); //Создание формы Календарь
  CalendarForm -> ShowModal (); //Активизация формы Календарь
  if (calendar) Edit1 -> Text=cal_date.DateString (); //Проверка выбрана дата в календаре или нет
  Edit2 -> SetFocus (); //Передача фокуса
 if ( (Edit1 -> Text!="")& (Edit2 -> Text!="")) BitBtn1 -> Visible=True;/*Проверка введены ли обе даты,
   если да,то кнопка Вывести становится видимой*/

 }
 //---------------------------------------------------------------------------

void __fastcall TStatisticForm::Edit2Click (TObject *Sender)
{   //Вызов календаря по щелчку мышью
  CalendarForm = new  TCalendarForm (this); //Создание формы Календарь
  CalendarForm -> ShowModal ();//Активизация формы Календарь
 if (calendar) Edit2 -> Text=cal_date.DateString ();//Проверка выбрана дата в календаре или нет

if ( (Edit1 -> Text!="")& (Edit2 -> Text!="")) BitBtn1 -> Visible=True;/*Проверка введены ли обе даты,
   если да,то кнопка Вывести становится видимой*/
}
//---------------------------------------------------------------------------



void __fastcall TStatisticForm::BitBtn1Click (TObject *Sender)
{ //При нажатии кнопки Вывести
  Set<TLocateOption,0,1> flags;//Установка флага для поиска
  DM2 -> Cause_PassFDTable -> Last ();
  int nom_rec=DM2 -> Cause_PassFDTable -> RecordCount;/*Заносим в переменную
    кол-во записей в таблице Причины пропусков*/
  DM2 -> Cause_PassFDTable -> First ();

  StatisticGrid -> RowCount=nom_rec+1;/*Устанавливаем кол-во строк в Grid'е равным числу
           записей в таблице Причины пропусков */
DataModule1 -> Statistic_Pass_DateFDQuery -> Close ();//Закрытие Query для установки параметров
//DataModule1 -> StatisticQuery -> SQL -> Clear ();
//DataModule1 -> StatisticQuery -> SQL -> Add ("SELECT  SUM ( HOUR_PASS ) FROM PASS Pass WHERE (Pass.NOMER=:NOMER) AND (Pass.D_PASS BETWEEN :START AND :END) AND (Pass.N_CAUSE=:CAUSE)");
DataModule1 -> Statistic_Pass_DateFDQuery -> Params -> ParamValues["NOMER"]=DataModule1 -> PeopleFDQueryNOMER -> Value;
DataModule1 -> Statistic_Pass_DateFDQuery -> Params -> ParamValues["START"]=StrToDate (Edit1 -> Text);
DataModule1 -> Statistic_Pass_DateFDQuery -> Params -> ParamValues["END"]=StrToDate (Edit2 -> Text);
 for (int i=1;i<=nom_rec;i++)
 {//Цикл для установки параметров
   DataModule1 -> Statistic_Pass_DateFDQuery -> Params -> ParamValues["CAUSE"]=i;
   DataModule1 -> Statistic_Pass_DateFDQuery -> Open ();//Выполнение запроса
    DM2 -> Cause_PassFDTable -> Locate ("N_CAUSE",i,flags);/*Установка
      указателя на запись в таблице Причины пропусков с i-м номером*/
    StatisticGrid -> Cells[0][i]=
            DM2 -> Cause_PassFDTableCAUSE -> Value;/*Занесение в Grid причин
             пропусков*/
    StatisticGrid -> Cells[1][i]=
            DataModule1 -> Statistic_Pass_DateFDQuerySUM -> Value;/*Занесение в Grid суммы часов
              часов пропусков для каждой причины*/
   DataModule1 -> Statistic_Pass_DateFDQuery -> Close (); //Закрытие Query
   }

  StatisticGrid -> Visible=true;//Показ выполненного запроса в Grid'е
   }
//---------------------------------------------------------------------------

void __fastcall TStatisticForm::FormActivate (TObject *Sender)
{ //При активизации формы
//Установка в Grid названия столбцов
StatisticGrid -> Cells[0][0]="Причина пропуска";
StatisticGrid -> Cells[1][0]="Кол-во пропущ.часов";
}
//---------------------------------------------------------------------------

void __fastcall TStatisticForm::Edit1Change (TObject *Sender)
{  //При изменении Edit1
//Кнопка Вывести и Grid становятся невидимыми
 BitBtn1 -> Visible=false;
 StatisticGrid -> Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TStatisticForm::Edit2Change (TObject *Sender)
{  //При изменении Edit2
//Кнопка Вывести и Grid становятся невидимыми
 BitBtn1 -> Visible=false;
 StatisticGrid -> Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TStatisticForm::BitBtn2Click (TObject *Sender)
{  //При нажатии кнопки Закрыть
//Закрытие формы Статистика
Close ();    
}
//---------------------------------------------------------------------------


void __fastcall TStatisticForm::FormClose (TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;       
}
//---------------------------------------------------------------------------


#include <vcl.h>
#pragma hdrstop


#include "CalendarUnit.h"
// #include <vcl/dstring.h>


#pragma package (smart_init)
#pragma link     "ccalendr"
#pragma link     "CCALENDR"
#pragma resource "*.dfm"


TCalendarForm * CalendarForm;


bool      calendar;
TDateTime cal_date;



// BitBtn1Click
// BitBtn2Click
// ComboBox1Change
// Edit1Change
// FormClose
// FormCreate
// UpDown1Click




__fastcall TCalendarForm::TCalendarForm(TComponent* Owner)
    : TForm(Owner)
{

}
void __fastcall TCalendarForm::UpDown1Click(TObject *Sender,
      TUDBtnType Button)
// Изменение значения года при помощи компонента UpDown
// и установка фокуса на поле Год
{
switch (Button)
 {
   case Comctrls::btNext: CCalendar1->NextYear();
   break;
   case Comctrls::btPrev: CCalendar1->PrevYear();
   break;
  }
  CCalendar1->Year=Edit1->Text.ToInt();
  Edit1->SetFocus();    
}

void __fastcall TCalendarForm::FormCreate(TObject *Sender)
// Установка текущей даты в календарь
{
UpDown1->Position=CCalendar1->Year;
Edit1->Text=CCalendar1->Year;
ComboBox1->ItemIndex=CCalendar1->Month-1;
}

void __fastcall TCalendarForm::ComboBox1Change(TObject *Sender)
//Установка месяца в календаре
{
if (CCalendar1->Month!=ComboBox1->ItemIndex+1)
  {
    CCalendar1->Day=1;
    CCalendar1->Month=ComboBox1->ItemIndex+1;
  }
}

void __fastcall TCalendarForm::BitBtn1Click(TObject *Sender)
//Установка выбранной даты в календаре
//в соответствующие переменные
{
  calendar=true;
 if (ComboBox1->Visible)
    //установка  выбранного месяца
   cal_month=ComboBox1->ItemIndex+1;
 if (Edit1->Visible)
 //установка  выбранного года
 cal_year=CCalendar1->Year;

 if ( CCalendar1->Visible)
 //установка в БД выбранной даты
cal_day=CCalendar1->Day;

 cal_date=CCalendar1->CalendarDate;

 
}

void __fastcall TCalendarForm::Edit1Change(TObject *Sender)
{
try {
if (Edit1->Text!="")
CCalendar1->Year=Edit1->Text.ToInt();
     }
catch (...)
     {
     MessageBox(0, "Неверно задано значение года", "Ошибка!!!",
               MB_OK);
      }
}


void __fastcall TCalendarForm::BitBtn2Click(TObject *Sender)
{
calendar=false;
}

void __fastcall TCalendarForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;        
}


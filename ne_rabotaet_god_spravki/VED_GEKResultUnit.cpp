//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "VED_GEKResultUnit.h"
#include "DM3Unit.h"
#include "DataModule.h"
#include "CalendarUnit.h"
#include "BallGEKUnit.h"
#include "MainUnit.h"
//---------------------------------------------------------------------------
#pragma package (smart_init)
//!!!#pragma link "ToolEdit"
#pragma resource "*.dfm"
TVED_GEKResult *VED_GEKResult;
//---------------------------------------------------------------------------
__fastcall TVED_GEKResult::TVED_GEKResult (TComponent* Owner)
        : TForm (Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TVED_GEKResult::FormClose (TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------

void __fastcall TVED_GEKResult::BitBtn2Click (TObject *Sender)
{
 

     DM3 -> GEK_VEDResultFDQuery -> Close ();
     DM3 -> GEK_VEDResultFDQuery -> ParamByName ("VID_EDU") -> Value=ComboBox2 -> ItemIndex;
     DM3 -> GEK_VEDResultFDQuery -> ParamByName ("N_VEDOMOST") -> Value=StrToInt (Edit1 -> Text);
     DM3 -> GEK_VEDResultFDQuery -> ParamByName ("N_FAC") -> Value=nom_fac;
     DM3 -> GEK_VEDResultFDQuery -> ParamByName ("YEAR_PLAN") -> Value=Edit5 -> Text;
     DM3 -> GEK_VEDResultFDQuery -> Open ();

     DM3 -> GEKResultGridFDQuery -> Close ();
     DM3 -> GEKResultGridFDQuery -> ParamByName ("N_VED") -> Value=DM3 -> GEK_VEDResultFDQueryN_VED -> Value;
     DM3 -> GEKResultGridFDQuery -> Open ();


}
//---------------------------------------------------------------------------

void __fastcall TVED_GEKResult::FormActivate (TObject *Sender)
{
   /*  Edit5 -> Text=IntToStr (uch_god);
     Edit6 -> Text=IntToStr (uch_god+1);
     DM3 -> GEK_VEDResult -> Close ();
     DM3 -> GEKResultGrid -> Close ();     */
}
//---------------------------------------------------------------------------

void __fastcall TVED_GEKResult::Edit5Change (TObject *Sender)
{
    if (Edit6 -> Text!="")
    {
      Edit6 -> Text=IntToStr (StrToInt (Edit5 -> Text)+1);
     }

   
     DM3 -> GEK_VEDResultFDQuery -> Close ();
     DM3 -> GEKResultGridFDQuery -> Close ();

}
//---------------------------------------------------------------------------


void __fastcall TVED_GEKResult::DBGrid1DblClick (TObject *Sender)
{
  if (DM3 -> GEKResultGridFDQuery -> RecordCount!=0)
  {

             Ball_GEK = new TBall_GEK (this); //—оздание формы дл€ балла ведомости
             Ball_GEK -> Visible=false;
             Ball_GEK -> ShowModal ();         //ѕоказ формы  балла ведомости
   }
}
//---------------------------------------------------------------------------

void __fastcall TVED_GEKResult::FormCreate (TObject *Sender)
{
Edit5 -> Text=IntToStr (uch_god);
Edit6 -> Text=IntToStr (uch_god+1);
DM3 -> GEK_VEDResultFDQuery -> Close ();
DM3 -> GEKResultGridFDQuery -> Close ();
}
//---------------------------------------------------------------------------

void __fastcall TVED_GEKResult::ComboBox2Change (TObject *Sender)
{

     DM3 -> GEK_VEDResultFDQuery -> Close ();
     DM3 -> GEKResultGridFDQuery -> Close ();
}
//---------------------------------------------------------------------------

void __fastcall TVED_GEKResult::Edit1KeyPress (TObject *Sender, char &Key)
{
DataModule1 -> Edit_Key (Key); // ак сделать, чтобы в TEdit можно было вводить только числа?        
}
//---------------------------------------------------------------------------

void __fastcall TVED_GEKResult::ApplicationEvents1Message (tagMSG &Msg,
      bool &Handled)
{
 //организовать нормальную работу мышиного колесика в DBGrid

if (DBGrid1 -> Focused ())
{
 if (Msg.message == WM_MOUSEWHEEL)
 {
    Msg.message = WM_KEYDOWN;
    Msg.lParam = 0;
    short int i = HIWORD (Msg.wParam);
    Msg.wParam = (i > 0)?VK_UP:VK_DOWN;
    Handled = false;
  }
}  
}
//---------------------------------------------------------------------------


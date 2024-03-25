//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Sub_Edu_planUnit.h"
#include "Add_Edu_planUnit.h"
#include "DataModule.h"
#include "DM2Unit.h"
//---------------------------------------------------------------------------
#pragma package (smart_init)
#pragma resource "*.dfm"
TSub_Edu_planForm *Sub_Edu_planForm;
//---------------------------------------------------------------------------
__fastcall TSub_Edu_planForm::TSub_Edu_planForm (TComponent* Owner)
    : TForm (Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSub_Edu_planForm::Edit1Change (TObject *Sender)
{
Edit2 -> Text = FloatToStr (1-StrToFloat (Edit1 -> Text));
}
//---------------------------------------------------------------------------
void __fastcall TSub_Edu_planForm::Edit2Change (TObject *Sender)
{
Edit1 -> Text = FloatToStr (1-StrToFloat (Edit2 -> Text));
}
//---------------------------------------------------------------------------
void __fastcall TSub_Edu_planForm::BitBtn1Click (TObject *Sender)
{
   Sub_Edu_planForm -> Close ();
}
//---------------------------------------------------------------------------

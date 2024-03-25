#include <vcl.h>
#pragma hdrstop


#include "AboutUnit.h"
#include "DM2Unit.h"


#pragma resource "*.dfm"


TAboutBox * AboutBox;



__fastcall TAboutBox::TAboutBox (TComponent * AOwner)
    : TForm (AOwner)
{ }



void __fastcall TAboutBox::BitBtn1Click (TObject * Sender)
{
    this -> Close ();    
}



void __fastcall TAboutBox::FormActivate (TObject * Sender)
{
    Version -> Caption = "Версия " + DM2 -> get_version ();
}



void __fastcall TAboutBox::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    this -> Close ();        
}
#include <vcl.h>
#pragma hdrstop


#include "DataModule.h"
#include "Dop_Ved_ReportUnit.h"


#pragma package (smart_init)
#pragma link     "frxClass"
#pragma resource "*.dfm"


TSpravka_vyzovForm * Spravka_vyzovForm;



__fastcall TSpravka_vyzovForm::TSpravka_vyzovForm (TComponent * Owner)
    : TForm (Owner)
{ }



void __fastcall TSpravka_vyzovForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    this -> Close ();
}
#include <vcl.h>
#pragma hdrstop


#include "DataModule.h"
#include "Rating_ReportUnit.h"


#pragma package (smart_init)
#pragma link     "frxClass"
#pragma link     "frxDBSet"
#pragma resource "*.dfm"


TRating_ReportForm * Rating_ReportForm;



__fastcall TRating_ReportForm::TRating_ReportForm (TComponent * Owner)
    : TForm (Owner)
{ }



void __fastcall TRating_ReportForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    this -> Close ();
}
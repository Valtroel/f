#include <vcl.h>
#pragma hdrstop


#include "DataModule.h"
#include "Dop_Ved_LikvidReportUnit.h"


#pragma package (smart_init)
#pragma link     "frxClass"
#pragma link     "frxDBSet"
#pragma link     "frxPreview"
#pragma resource "*.dfm"


TDop_Ved_LikvidReportForm * Dop_Ved_LikvidReportForm;



__fastcall TDop_Ved_LikvidReportForm::TDop_Ved_LikvidReportForm (TComponent * Owner)
    : TForm (Owner)
{ }



void __fastcall TDop_Ved_LikvidReportForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    this -> Close ();       
}
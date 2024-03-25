#include <vcl.h>
#pragma hdrstop


#include "DataModule.h"
#include "People_Card_ReportUnit.h"


#pragma package (smart_init)
#pragma link     "frxClass"
#pragma resource "*.dfm"


TPeople_card_ReportForm * People_card_ReportForm;



__fastcall TPeople_card_ReportForm::TPeople_card_ReportForm (TComponent * Owner)
    : TForm (Owner)
{ }



void __fastcall TPeople_card_ReportForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    DataModule1 -> People_Card_ReportQuery -> Close();

    this -> Close ();
}
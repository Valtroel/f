//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Ved_ReportUnit.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma link "frxPreview"
#pragma link "frxRich"
#pragma resource "*.dfm"
TVed_ReportForm *Ved_ReportForm;
//---------------------------------------------------------------------------
__fastcall TVed_ReportForm::TVed_ReportForm(TComponent* Owner)
    : TForm(Owner)
{ }
//---------------------------------------------------------------------------

void __fastcall TVed_ReportForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;
}
//---------------------------------------------------------------------------





















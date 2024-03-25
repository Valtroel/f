#include <vcl.h>
#pragma hdrstop


#include "ReferenceUnit.h"
#include "Spravka_vyzovUnit.h"
#include "SpravkaUnit.h"


#pragma package (smart_init)
#pragma link     "frxClass"
#pragma link     "frxDBSet"
#pragma link     "frxPreview"
#pragma resource "*.dfm"


TReferenceForm * ReferenceForm;



__fastcall TReferenceForm::TReferenceForm (TComponent * Owner)
    : TForm (Owner)
{ }
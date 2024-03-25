
#include <vcl.h>
#pragma hdrstop


#include "KartaUnit.h"
#include "Medical_ÑhecklistUnit.h"


#pragma package (smart_init)
#pragma link     "frxClass"
#pragma link     "frxDBSet"
#pragma link     "frxPreview"
#pragma resource "*.dfm"


TMedical_checklist_print_Form * Medical_checklist_print_Form;



__fastcall TMedical_checklist_print_Form::TMedical_checklist_print_Form (TComponent * Owner)
    : TForm (Owner)
{ }
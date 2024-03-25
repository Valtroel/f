#include <vcl.h>
#pragma hdrstop


#include "DataModule.h"
#include "DM4Unit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TDM4 * DM4;



__fastcall TDM4::TDM4 (TComponent * Owner)
    : TDataModule (Owner)
{ }
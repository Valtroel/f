#include <vcl.h>
#pragma hdrstop


#include "LogPassUnit.h"


#pragma resource "*.dfm"


TLogPassForm * LogPassForm;



__fastcall TLogPassForm::TLogPassForm (TComponent * AOwner)
    : TForm (AOwner)
{ }



void __fastcall TLogPassForm::CancelBtnClick (TObject * Sender)
{
    Application -> Terminate ();
}



void __fastcall TLogPassForm::FormActivate (TObject * Sender)                   // Перевести фокус на пароль при наличии логина
{
    if (Login -> Text != "")
        LogPassForm -> Password -> SetFocus ();
    else
        LogPassForm -> Login    -> SetFocus ();
}



void __fastcall TLogPassForm::FormCreate (TObject * Sender)
{
    LoadKeyboardLayout (                                                        // Английская
        "00000409",
        KLF_ACTIVATE
    );
}



void __fastcall TLogPassForm::OKBtnClick (TObject * Sender)
{
    // loginUser = Login    -> Text;
    // pswdUser  = Password -> Text;
}
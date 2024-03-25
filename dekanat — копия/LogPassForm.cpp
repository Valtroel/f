#include <vcl.h>
#pragma hdrstop


#include "LogPassForm.h"


#pragma resource "*.dfm"


TPasswordDlg * PasswordDlg;



__fastcall TPasswordDlg::TPasswordDlg (TComponent * AOwner)
    : TForm (AOwner)
{ }



void __fastcall TPasswordDlg::CancelBtnClick (TObject * Sender)
{
    Application -> Terminate ();
}



void __fastcall TPasswordDlg::FormActivate (TObject * Sender)                   // Перевести фокус на пароль при наличии логина
{
    if (loginUser != "")
        LogPassForm -> Password -> SetFocus ();
    else
        LogPassForm -> login    -> SetFocus ();
}



void __fastcall TPasswordDlg::OKBtnClick (TObject * Sender)
{
    loginUser = Login    -> Text;
    pswdUser  = Password -> Text;
}
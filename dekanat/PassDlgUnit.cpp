#include <vcl.h>
#pragma hdrstop


#include "PassDlgUnit.h"
#include "SpravUnit.h"


#pragma resource "*.dfm"


TPassDlg * PassDlg;



__fastcall TPassDlg::TPassDlg (TComponent * AOwner)
    : TForm (AOwner)
{ }



void __fastcall TPassDlg::BitBtn1Click (TObject * Sender)
{
    AnsiString Pass = "��_�������",
               UsN  = "�������";

    if (    User     -> Text == UsN
         && Password -> Text == Pass
       )
    {
        Close ();

        SpravForm = new TSpravForm (this);

        SpravForm -> Show ();
    }
    else
        ShowMessage (
            "�������� ��� ������������ ��� ������"
        );
}



void __fastcall TPassDlg::BitBtn2Click (TObject * Sender)
{
    this -> Close ();
}



void __fastcall TPassDlg::FormActivate (TObject * Sender)
{
    User     -> Text = "";
    Password -> Text = "";        
}



void __fastcall TPassDlg::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    this -> Close ();
}
#pragma once
#ifndef LOG_PASS_FORM_H
#define LOG_PASS_FORM_H


#include <System.Classes.hpp>
#include <System.hpp>
#include <System.SysUtils.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Winapi.Windows.hpp>


class TPasswordDlg
    : public TForm
{
__published:
    TButton * CancelBtn;
    TButton * OKBtn;

    TEdit   * login;
    TEdit   * LogPassForm;

    TLabel  * Label1;
    TLabel  * Label2;


    void __fastcall CancelBtnClick (TObject * Sender);
    void __fastcall FormActivate   (TObject * Sender);
    void __fastcall OKBtnClick     (TObject * Sender);
private:
public:
    virtual __fastcall TPasswordDlg (TComponent * AOwner);
};

extern PACKAGE TPasswordDlg * PasswordDlg;

#endif  // LOG_PASS_FORM_H
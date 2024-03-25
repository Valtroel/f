#pragma once
#ifndef PASS_DLG_UNIT_H
#define PASS_DLG_UNIT_H


#include <System.Classes.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
// #include <vcl\Buttons.hpp>
// #include <vcl\Classes.hpp>
// #include <vcl\Controls.hpp>
// #include <vcl\Forms.hpp>
// #include <vcl\Graphics.hpp>
// #include <vcl\StdCtrls.hpp>
// #include <vcl\System.hpp>
// #include <vcl\SysUtils.hpp>
// #include <vcl\Windows.hpp>


class TPassDlg
    : public TForm
{
__published:
    TBitBtn * BitBtn1;
    TBitBtn * BitBtn2;

    TEdit   * Password;
    TEdit   * User;

    TLabel  * Label1;
    TLabel  * Label2;

    void __fastcall BitBtn1Click (TObject * Sender);
    void __fastcall BitBtn2Click (TObject * Sender);
    void __fastcall FormActivate (TObject * Sender);
    void __fastcall FormClose    (
        TObject      * Sender,
        TCloseAction & Action
    );
private:
public:
    virtual __fastcall TPassDlg (TComponent * AOwner);
};

extern PACKAGE TPassDlg * PassDlg;

#endif  // PASS_DLG_UNIT_H
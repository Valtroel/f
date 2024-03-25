#pragma once
#ifndef DIALOG_PASS_H
#define DIALOG_PASS_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <Mask.hpp>
#include <StdCtrls.hpp>
#include <System.hpp>
#include <SysUtils.hpp>
#include <Windows.hpp>


class TDialogPass
    : public TForm
{
__published:
    TButton           * CancelBtn;
    TButton           * OKBtn;

    TDBLookupComboBox * DBLookupComboBox1;

    TEdit             * Edit1;

    TLabel            * Label1;
    TLabel            * Label2;


    void __fastcall CancelBtnClick           (TObject * Sender);
    void __fastcall DBLookupComboBox1CloseUp (TObject * Sender);
    void __fastcall Edit1Change              (TObject * Sender);
    void __fastcall Edit1KeyPress            (
            TObject * Sender,
            char    & Key
        );
    void __fastcall FormClose                (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall OKBtnClick               (TObject * Sender);
private:
public:
    virtual __fastcall TDialogPass (TComponent * AOwner);
};

extern PACKAGE TDialogPass * DialogPass;

#endif  // DIALOG_PASS_H
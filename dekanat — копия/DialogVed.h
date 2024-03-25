#pragma once
#ifndef DIALOG_VED_H
#define DIALOG_VED_H


#include <Mask.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
// #include <vcl\Buttons.hpp>
// #include <vcl\Classes.hpp>
// #include <vcl\Controls.hpp>
// #include <vcl\ExtCtrls.hpp>
// #include <vcl\Forms.hpp>
// #include <vcl\Graphics.hpp>
// #include <vcl\StdCtrls.hpp>
// #include <vcl\System.hpp>
// #include <vcl\SysUtils.hpp>
// #include <vcl\Windows.hpp>


class TOKBottomDlg
    : public TForm
{
__published:        
    TBevel    * Bevel1;

    TButton   * OKBtn;

    TLabel    * Label5;

    TMaskEdit * MaskEdit1;


    void __fastcall Edit4Click       (TObject * Sender);
    void __fastcall FormClose        (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall MaskEdit1Click   (TObject * Sender);
    void __fastcall MaskEdit1KeyDown (
            TObject     * Sender,
            WORD        & Key,
            TShiftState   Shift
        );
    void __fastcall OKBtnClick       (TObject * Sender);
private:
public:
    virtual __fastcall TOKBottomDlg (TComponent * AOwner);
};

extern PACKAGE TOKBottomDlg * OKBottomDlg;

#endif  // DIALOG_VED_H
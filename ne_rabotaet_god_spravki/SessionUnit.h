#pragma once
#ifndef SESSION_UNIT_H
#define SESSION_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <StdCtrls.hpp>


class TSession_Form
    : public TForm
{
__published:
    TBitBtn     * BitBtn1;
    TBitBtn     * BitBtn2;
    TBitBtn     * BitBtn3;

    TComboBox   * ComboBox1;

    TLabel      * Label1;
    TLabel      * Label2;
    TLabel      * Label3;
    TLabel      * Label4;
    TLabel      * Label5;
    TLabel      * Label6;
    TLabel      * Label7;

    TMaskEdit   * MaskEdit1;
    TMaskEdit   * MaskEdit2;
    TMaskEdit   * MaskEdit3;

    TPanel      * Panel1;
    TPanel      * Panel2;
    TPanel      * Panel3;

    TStringGrid * StringGrid1;
    TStringGrid * StringGrid2;


    void __fastcall BitBtn1Click        (TObject * Sender);
    void __fastcall BitBtn2Click        (TObject * Sender);
    void __fastcall BitBtn3Click        (TObject * Sender);
    void __fastcall FormClose           (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate          (TObject * Sender);
    void __fastcall MaskEdit1Change     (TObject * Sender);
    void __fastcall MaskEdit1Exit       (TObject * Sender);
    void __fastcall MaskEdit1MouseDown  (
            TObject      * Sender,
            TMouseButton   Button,
            TShiftState    Shift,
            int            X,
            int            Y
        );
    void __fastcall MaskEdit2KeyPress   (
            TObject * Sender,
            char    & Key
        );
    void __fastcall MaskEdit2MouseDown  (
            TObject      * Sender,
            TMouseButton   Button,
            TShiftState    Shift,
            int            X,
            int            Y
        );
    void __fastcall MaskEdit3Exit       (TObject * Sender);
    void __fastcall StringGrid1DrawCell (
            TObject        * Sender,
            int              ACol,
            int              ARow,
            TRect          & Rect,
            TGridDrawState   State
        );
private:
public:
    __fastcall TSession_Form (TComponent * Owner);

    int  __fastcall check_ball (                                                // функция,возвращающая балл
            int        ball,
            int        n_st,
            AnsiString predm
        );
    bool __fastcall result_ses (
            int i,
            int j
        );
};

extern PACKAGE TSession_Form * Session_Form;

#endif  // SESSION_UNIT_H
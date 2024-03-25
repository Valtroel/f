#pragma once
#ifndef PEREZACH_UCHKART_UNIT_H
#define PEREZACH_UCHKART_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
#include <StdCtrls.hpp>
// #include "ToolEdit.hpp"
#include <Vcl.ComCtrls.hpp>


class TPerezach_UchKartForm
    : public TForm
{
__published:
    TBitBtn           * BitBtn1;
    TBitBtn           * BitBtn2;
    TBitBtn           * BitBtn3;

    TComboBox         * ComboBox1;
    TComboBox         * ComboBox2;

    TDateTimePicker   * DateTimePicker1;

    TDBLookupComboBox * DBLookupComboBox1;

    TDBText           * DBText1;
    TDBText           * DBText2;
    TDBText           * DBText3;
    TDBText           * DBText4;
    TDBText           * DBText5;
    TDBText           * DBText6;
    TDBText           * DBText7;
    TDBText           * DBText8;
    TDBText           * DBText9;

    TEdit             * Edit1;
    TEdit             * Edit2;

    TLabel            * Label1;
    TLabel            * Label2;
    TLabel            * Label3;
    TLabel            * Label4;
    TLabel            * Label5;
    TLabel            * Label6;
    TLabel            * Label7;
    TLabel            * Label8;
    TLabel            * Label9;
    TLabel            * Label10;
    TLabel            * Label11;
    TLabel            * Label12;
    TLabel            * Label13;

    TPanel            * Panel1;
    TPanel            * Panel2;
    TPanel            * Panel3;
    TPanel            * Panel4;

    TRadioGroup       * RadioGroup2;


    void __fastcall BitBtn1Click          (TObject * Sender);
    void __fastcall BitBtn2Click          (TObject * Sender);
    void __fastcall BitBtn3Click          (TObject * Sender);
    void __fastcall DateTimePicker1Change (TObject * Sender);
    void __fastcall Edit1Click            (TObject * Sender);
    void __fastcall Edit2Exit             (TObject * Sender);
    void __fastcall Edit2KeyPress         (
            TObject * Sender,
            char    & Key
        );
    void __fastcall FormActivate          (TObject * Sender);
    void __fastcall FormClose             (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TPerezach_UchKartForm (TComponent * Owner);

    int return_ball (                                                           // ПРОЦЕДУРА для перезачета в другую систему счисления
        int ball,
        int Index
    );
};

extern PACKAGE TPerezach_UchKartForm * Perezach_UchKartForm;

#endif  // PEREZACH_UCHKART_UNIT_H
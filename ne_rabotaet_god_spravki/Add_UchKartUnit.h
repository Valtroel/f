#pragma once
#ifndef ADD_UCH_KART_UNIT_H
#define ADD_UCH_KART_UNIT_H


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


extern bool add_card;                                                           // флаг указывающий на добавление записи в карточку (true - добавлена)


class TAdd_UchKartForm
    : public TForm
{
__published:
    TBitBtn           * BitBtn1;
    TBitBtn           * BitBtn2;
    TBitBtn           * BitBtn3;

    TComboBox         * ComboBox1;
    TComboBox         * ComboBox2;

    // TDateEdit         * DateEdit1;

    TDateTimePicker   * DateTimePicker1;

    TDBLookupComboBox * DBLookupComboBox1;

    TDBNavigator      * DBNavigator1;

    TDBText           * DBText1;
    TDBText           * DBText2;
    TDBText           * DBText3;

    TEdit             * Edit1;
    TEdit             * Edit2;

    TLabel            * Label1;
    TLabel            * Label2;
    TLabel            * Label3;
    TLabel            * Label4;
    TLabel            * Label5;
    TLabel            * Label6;
    TLabel            * Label7;

    TPanel            * Panel1;
    TPanel            * Panel2;
    TPanel            * Panel3;
    TPanel            * Panel4;

    TRadioGroup       * RadioGroup1;
    TRadioGroup       * RadioGroup2;


    void __fastcall BitBtn1Click          (TObject * Sender);
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
    void __fastcall RadioGroup2Click      (TObject * Sender);
private:
public:
    __fastcall TAdd_UchKartForm (TComponent * Owner);
};

extern PACKAGE TAdd_UchKartForm * Add_UchKartForm;

#endif  // ADD_UCH_KART_UNIT_H
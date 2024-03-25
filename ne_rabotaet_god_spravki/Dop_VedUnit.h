#pragma once
#ifndef DOP_VED_UNIT_H
#define DOP_VED_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
// #include "DualList.hpp"
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
// #include "MyList.h"
#include <StdCtrls.hpp>


class TDop_VedForm
    : public TForm
{
__published:
    TBitBtn         * BitBtn1;
    TBitBtn         * BitBtn2;
    TBitBtn         * BitBtn3;

    TCheckBox       * CheckBox1;

    TComboBox       * ComboBox1;
    TComboBox       * ComboBox2;
    TComboBox       * ComboBox3;

    // TDualListDialog * DualListDialog1;

    TEdit           * Edit1;
    TEdit           * Edit2;
    TEdit           * Edit3;
    TEdit           * Edit4;
    TEdit           * Edit5;
    TEdit           * Edit6;
    TEdit           * Edit7;

    TLabel          * Label1;
    TLabel          * Label2;
    TLabel          * Label3;
    TLabel          * Label4;
    TLabel          * Label5;
    TLabel          * Label6;
    TLabel          * Label7;
    TLabel          * Label8;
    TLabel          * Label9;
    TLabel          * Label10;
    TLabel          * Label11;

    TPanel          * Panel1;
    TPanel          * Panel2;
    TPanel          * Panel3;
    TPanel          * Panel4;
    TPanel          * Panel5;


    void __fastcall BitBtn2Click    (TObject * Sender);
    void __fastcall BitBtn3Click    (TObject * Sender);
    void __fastcall CheckBox1Click  (TObject * Sender);
    void __fastcall ComboBox1Change (TObject * Sender);
    void __fastcall ComboBox3Change (TObject * Sender);
    void __fastcall Edit1Click      (TObject * Sender);
    void __fastcall Edit2Click      (TObject * Sender);
    void __fastcall Edit4KeyPress   (
            TObject * Sender,
            char    & Key
        );
    void __fastcall Edit5Change     (TObject * Sender);
    void __fastcall FormActivate    (TObject * Sender);
    void __fastcall FormClose       (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall Panel2Click     (TObject * Sender);
private:
public:
    __fastcall TDop_VedForm (TComponent * Owner);

    AnsiString search_fio   (                                                   // Поиск ФИО студента по номеру
            int rec_p,
            int nomer
        );
    int        search_nomer (                                                   // Поиск номера студента по ФИО
            int        rec_p,
            AnsiString fio
        );
};

extern PACKAGE TDop_VedForm * Dop_VedForm;

#endif  // DOP_VED_UNIT_H
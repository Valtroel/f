#pragma once
#ifndef ADD_VED_GEK_UNIT_H
#define ADD_VED_GEK_UNIT_H


#include <Buttons.hpp>
#include <CheckLst.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include "frxClass.hpp"
#include <Mask.hpp>
// #include "MyList.h"
#include <StdCtrls.hpp>
// #include "ToolEdit.hpp"
#include <Vcl.ComCtrls.hpp>


class TADD_VedGEK
    : public TForm
{
__published:
    TBitBtn           * BitBtn1;
    TBitBtn           * BitBtn2;

    TButton           * Button2;

    TCheckListBox     * CheckListBox1;

    TComboBox         * ComboBox2;

    TDateTimePicker   * DateTimePicker2;

    TDBLookupComboBox * DBLookupComboBox1;

    TEdit             * Edit1;
    TEdit             * Edit5;
    TEdit             * Edit7;

    TLabel            * Label1;
    TLabel            * Label2;
    TLabel            * Label3;
    TLabel            * Label4;
    TLabel            * Label5;
    TLabel            * Label6;
    TLabel            * Label7;
    TLabel            * Label8;
    TLabel            * Label9;

    TMaskEdit         * MaskEdit2;

    TPanel            * Panel1;
    TPanel            * Panel2;
    TPanel            * Panel3;


    void __fastcall BitBtn1Click          (TObject * Sender);
    void __fastcall BitBtn2Click          (TObject * Sender);
    void __fastcall Button1Click          (TObject * Sender);
    void __fastcall ComboBox2Change       (TObject * Sender);
    void __fastcall DateTimePicker2Change (TObject * Sender);
    void __fastcall Edit5KeyPress         (
        TObject * Sender,
        char    & Key
    );
    void __fastcall FormClose             (
        TObject      * Sender,
        TCloseAction & Action
    );
private:
public:
__fastcall TADD_VedGEK (TComponent * Owner);

    void __fastcall Delete_VED (int num);                                       // Процедура удаления ведомости и всех людей при сбое
};

extern PACKAGE TADD_VedGEK * ADD_VedGEK;

#endif  // ADD_VED_GEK_UNIT_H
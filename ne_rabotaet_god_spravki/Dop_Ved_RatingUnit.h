#pragma once
#ifndef DOP_VED_RATING_UNIT_H
#define DOP_VED_RATING_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
// #include "MyList.h"
#include <StdCtrls.hpp>
// #include "ToolEdit.hpp"
#include <Vcl.ComCtrls.hpp>
#include <Vcl.DBCtrls.hpp>


class TDop_Ved_RatingForm
    : public TForm
{
__published:
    TBitBtn         * BitBtn1;
    TBitBtn         * BitBtn2;

    TCheckBox       * CheckBox2;

    TComboBox       * ComboBox1;
    TComboBox       * ComboBox2;

    TDateTimePicker * DateTimePicker1;
    TDateTimePicker * DateTimePicker2;
    TDateTimePicker * DateTimePicker3;
    TDateTimePicker * DateTimePicker4;

    TDBText         * DBText1;
    TDBText         * DBText2;
    TDBText         * DBText3;
    TDBText         * DBText4;
    TDBText         * DBText5;

    TEdit           * Edit1;
    TEdit           * Edit2;
    TEdit           * Edit3;
    TEdit           * Edit4;
    TEdit           * Edit8;

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
    TLabel          * Label12;
    TLabel          * Label13;
    TLabel          * Label14;
    TLabel          * Label15;
    TLabel          * Label16;
    TLabel          * Label17;
    TLabel          * Label18;
    TLabel          * Label19;
    TLabel          * Label20;

    TPanel          * Panel1;
    TPanel          * Panel2;
    TPanel          * Panel4;


    void __fastcall BitBtn1Click          (TObject * Sender);
    void __fastcall DateTimePicker1Change (TObject * Sender);
    void __fastcall DateTimePicker2Change (TObject * Sender);
    void __fastcall DateTimePicker3Change (TObject * Sender);
    void __fastcall DateTimePicker4Change (TObject * Sender);
    void __fastcall Edit1Exit             (TObject * Sender);
    void __fastcall Edit2Exit             (TObject * Sender);
    void __fastcall FormActivate          (TObject * Sender);
    void __fastcall FormClose             (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TDop_Ved_RatingForm (TComponent * Owner);
};

extern PACKAGE TDop_Ved_RatingForm * Dop_Ved_RatingForm;

#endif  // DOP_VED_RATING_UNIT_H
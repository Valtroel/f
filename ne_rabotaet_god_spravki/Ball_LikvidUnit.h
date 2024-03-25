#pragma once
#ifndef BALL_LIKVID_UNIT_H
#define BALL_LIKVID_UNIT_H


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


class TBall_LikvidForm
    : public TForm
{
__published:
    TBitBtn         * BitBtn1;
    TBitBtn         * BitBtn2;

    TDateTimePicker * DateTimePicker1;
    TDateTimePicker * DateTimePicker2;
    TDateTimePicker * DateTimePicker3;

    TDBText         * DBText1;
    TDBText         * DBText2;
    TDBText         * DBText3;
    TDBText         * DBText4;
    TDBText         * DBText5;
    TDBText         * DBText6;

    TEdit           * Edit3;

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
    TLabel          * Label15;

    TPanel          * Panel1;
    TPanel          * Panel2;
    TPanel          * Panel3;

    TRadioGroup     * RadioGroup1;
    TRadioGroup     * RadioGroup2;


    void __fastcall BitBtn1Click          (TObject * Sender);
    void __fastcall DateTimePicker1Change (TObject * Sender);
    void __fastcall DateTimePicker2Change (TObject * Sender);
    void __fastcall DateTimePicker3Change (TObject * Sender);                   // установка значений из базы данных в RadioGroup1 -> ItemIndex
    void __fastcall FormClose             (
            TObject      * Sender,
            TCloseAction & Action
        );
    int  __fastcall Radio1_ball           ();                                   // передача балла и вида контроля в зависимости от RadioGroup1 -> ItemIndex
    int  __fastcall Radio1_base           ();
    void __fastcall RadioGroup2Click      (TObject * Sender);
    void __fastcall radio1_setup          ();                                   // установка значений Items-ов в RadioGroup1
private:
public:
    __fastcall TBall_LikvidForm (TComponent * Owner);
};

extern PACKAGE TBall_LikvidForm * Ball_LikvidForm;

#endif  // BALL_LIKVID_UNIT_H
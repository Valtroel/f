#pragma once
#ifndef RESULT_VED_UNIT_H
#define RESULT_VED_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <StdCtrls.hpp>
// #include "ToolEdit.hpp"
#include <Vcl.CheckLst.hpp>
#include <Vcl.ComCtrls.hpp>


extern int inc_ved;


class TResult_VedForm
    : public TForm
{
__published:
    TBitBtn         * BitBtn1;
    TBitBtn         * BitBtn2;

    TButton         * Button1;

    TCheckListBox   * CheckListBox1;

    TDateTimePicker * DateTimePicker1;

    TDBGrid         * DBGrid1;

    TDBText         * DBText1;

    TEdit           * Edit1;
    TEdit           * Edit2;
    TEdit           * Edit5;
    TEdit           * Edit6;

    TLabel          * Label1;
    TLabel          * Label2;
    TLabel          * Label3;
    TLabel          * Label4;
    TLabel          * Label9;
    TLabel          * Label10;

    TPanel          * Panel1;
    TPanel          * Panel2;
    TPanel          * Panel3;


    void __fastcall BitBtn1Click            (TObject * Sender);
    void __fastcall BitBtn2Click            (TObject * Sender);
    void __fastcall Button1Click            (TObject * Sender);
    void __fastcall DateTimePicker1Change   (TObject * Sender);
    void __fastcall DBGrid1DblClick         (TObject * Sender);
    // void __fastcall DBGrid1DrawColumnCell   (
    //           TObject        * Sender,
    //     const TRect          & Rect,
    //           int              DataCol,
    //           TColumn        * Column,
    //           TGridDrawState   State
    //     );
    void __fastcall Edit1Change             (TObject * Sender);
    void __fastcall Edit1KeyPress           (
            TObject * Sender,
            char    & Key
        );
    void __fastcall Edit5KeyPress           (
            TObject * Sender,
            char    & Key
        );
    void __fastcall FormActivate            (TObject * Sender);
    void __fastcall FormClose               (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate              (TObject * Sender);
    void __fastcall RxCheckListBox1DblClick (TObject * Sender);
private:
public:
    __fastcall TResult_VedForm (TComponent * Owner);

    void __fastcall RadioGroup_Ball ();                                         // установка Items-ов в RadioGroup1 на Ball_Form (зависит от вида контроля и системы оценок)
};

extern PACKAGE TResult_VedForm * Result_VedForm;

#endif  // RESULT_VED_UNIT_H
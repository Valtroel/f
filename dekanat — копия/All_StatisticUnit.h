#pragma once
#ifndef ALL_STATISTIC_UNIT_H
#define ALL_STATISTIC_UNIT_H


#include <Classes.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <StdCtrls.hpp>
// #include "ToolEdit.hpp"
#include <Vcl.ComCtrls.hpp>


class TAll_StatisticForm
    : public TForm
{
__published:
    TButton         * Button1;

    TComboBox       * ComboBox1;

    TDateTimePicker * DateTimePicker1;
    TDateTimePicker * DateTimePicker2;

    TLabel          * Label1;
    TLabel          * Label2;
    TLabel          * Label3;
    TLabel          * Label4;
    TLabel          * Label5;
    TLabel          * Label6;

    TMaskEdit       * MaskEdit1;

    TPanel          * Panel1;
    TPanel          * Panel2;
    TPanel          * Panel3;
    TPanel          * Panel4;
    TPanel          * Panel5;

    TRadioGroup     * RadioGroup1;


    void __fastcall Button1Click          (TObject * Sender);
    void __fastcall DateTimePicker1Change (TObject * Sender);
    void __fastcall DateTimePicker2Change (TObject * Sender);
    void __fastcall FormClose             (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall RadioGroup1Click      (TObject * Sender);
private:
public:
    __fastcall TAll_StatisticForm (TComponent * Owner);

    bool __fastcall next_group (
            TDataSet * name_query,
            int        nom_group
        );
};

extern PACKAGE TAll_StatisticForm * All_StatisticForm;

#endif  // ALL_STATISTIC_UNIT_H
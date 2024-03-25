#pragma once
#ifndef STATISTIC_UNIT_H
#define STATISTIC_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
// #include <mxgrid.hpp>
// #include <mxpivsrc.hpp>
#include <StdCtrls.hpp>


class TStatisticForm
    : public TForm
{
__published:
    TBitBtn     * BitBtn1;
    TBitBtn     * BitBtn2;

    TDBText     * DBText1;
    TDBText     * DBText2;
    TDBText     * DBText3;

    TEdit       * Edit1;
    TEdit       * Edit2;

    TLabel      * Label1;
    TLabel      * Label2;
    TLabel      * Label3;

    TPanel      * Panel1;
    TPanel      * Panel2;

    TStringGrid * StatisticGrid;


    void __fastcall BitBtn1Click (TObject * Sender);
    void __fastcall BitBtn2Click (TObject * Sender);
    void __fastcall Edit1Change  (TObject * Sender);
    void __fastcall Edit1Click   (TObject * Sender);
    void __fastcall Edit2Change  (TObject * Sender);
    void __fastcall Edit2Click   (TObject * Sender);
    void __fastcall FormActivate (TObject * Sender);
    void __fastcall FormClose    (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TStatisticForm (TComponent * Owner);
};

extern PACKAGE TStatisticForm * StatisticForm;

#endif  // STATISTIC_UNIT_H
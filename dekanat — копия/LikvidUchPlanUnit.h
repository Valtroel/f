#pragma once
#ifndef LIKVID_UCH_PLAN_UNIT_H
#define LIKVID_UCH_PLAN_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>


class TLikvidUchPlanForm
    : public TForm
{
__published:
    TBitBtn           * BitBtn1;
    TBitBtn           * BitBtn2;
    TBitBtn           * BitBtn3;
    TBitBtn           * BitBtn4;

    TDBGrid           * DBGrid1;

    TDBLookupComboBox * DBLookupComboBox1;

    TLabel            * Label1;

    TMemo             * Memo1;

    TPanel            * Panel1;
    TPanel            * Panel2;
    TPanel            * Panel3;
    TPanel            * Panel4;
    TPanel            * Panel5;

    TRadioGroup       * RadioGroup1;
    TRadioGroup       * RadioGroup2;

    TSpeedButton      * SpeedButton1;
    TSpeedButton      * SpeedButton2;
    TSpeedButton      * SpeedButton3;

    TSplitter         * Splitter1;


    void __fastcall BitBtn1Click           (TObject * Sender);
    void __fastcall BitBtn2Click           (TObject * Sender);
    void __fastcall BitBtn3Click           (TObject * Sender);
    void __fastcall BitBtn4Click           (TObject * Sender);
    void __fastcall DBGrid1DblClick        (TObject * Sender);
    // void __fastcall DBGrid1DrawColumnCell  (
    //               TObject        * Sender,
    //         const TRect          & Rect,
    //               int              DataCol,
    //               TColumn        * Column,
    //               TGridDrawState   State
    //     );
    void __fastcall DBLookupComboBox1Click (TObject * Sender);
    void __fastcall FormClose              (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate             (TObject * Sender);
    void __fastcall RadioGroup1Click       (TObject * Sender);
    void __fastcall RadioGroup2Click       (TObject * Sender);
    void __fastcall SpeedButton1Click      (TObject * Sender);
    void __fastcall SpeedButton2Click      (TObject * Sender);
    void __fastcall SpeedButton3Click      (TObject * Sender);
private:
public:
    __fastcall TLikvidUchPlanForm (TComponent * Owner);

    void       __fastcall FormMin (int st);                                     //уменьшение формы
    AnsiString            sql_sem (
            int k,
            int god
        );
};

extern PACKAGE TLikvidUchPlanForm * LikvidUchPlanForm;

#endif  // LIKVID_UCH_PLAN_UNIT_H
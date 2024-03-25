#pragma once
#ifndef EDU_PLAN_UNIT_H
#define EDU_PLAN_UNIT_H


#include <AppEvnts.hpp>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>


class TEdu_planForm
    : public TForm
{
__published:
    TApplicationEvents * ApplicationEvents1;

    TBitBtn            * BitBtn1;
    TBitBtn            * BitBtn2;

    TCheckBox          * CheckBox1;

    TDBGrid            * DBGrid1;

    TLabeledEdit       * LabeledEdit1;

    TPanel             * Panel1;
    TPanel             * Panel2;

    TRadioGroup        * RadioGroup1;
    TRadioGroup        * RadioGroup2;


    void __fastcall ApplicationEvents1Message (
            tagMSG & Msg,
            bool   & Handled
        );
    void __fastcall BitBtn1Click              (TObject * Sender);
    void __fastcall CheckBox1Click            (TObject * Sender);
    void __fastcall DBGrid1DblClick           (TObject * Sender);
    void __fastcall FormActivate              (TObject * Sender);
    void __fastcall FormClose                 (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall LabeledEdit1Change        (TObject * Sender);
    void __fastcall RadioGroup1Click          (TObject * Sender);
    void __fastcall RadioGroup2Click          (TObject * Sender);
private:
public:
    __fastcall TEdu_planForm  (TComponent * Owner);
};

extern PACKAGE TEdu_planForm * Edu_planForm;

#endif  // EDU_PLAN_UNIT_H
#pragma once
#ifndef JOURNAL_UNIT_H
#define JOURNAL_UNIT_H


#include <System.Classes.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>


class TJournalForm
    : public TForm
{
__published:
    TBitBtn     * BitBtn1;

    TEdit       * Edit1;
    TEdit       * Edit2;

    TLabel      * Label1;
    TLabel      * Label3;
    TLabel      * Label4;

    TRadioGroup * RadioGroup1;
    TRadioGroup * RadioGroup2;
    TRadioGroup * RadioGroup3;


    void __fastcall BitBtn1Click     (TObject * Sender);
    void __fastcall RadioGroup3Click (TObject * Sender);
private:
public:
    __fastcall TJournalForm (TComponent * Owner);
};

extern PACKAGE TJournalForm * JournalForm;

#endif  // JOURNAL_UNIT_H
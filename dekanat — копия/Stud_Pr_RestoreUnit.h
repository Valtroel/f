#pragma once
#ifndef STUD_PR_RESTORE_UNIT_H
#define STUD_PR_RESTORE_UNIT_H


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


class TStud_Pr_RestoreForm
    : public TForm
{
__published:
    TBitBtn           * BitBtn1;
    TBitBtn           * BitBtn2;

    TDateTimePicker   * DateTimePicker1;

    TDBLookupComboBox * DBLookupComboBox1;

    TEdit             * Edit1;
    TEdit             * Edit2;

    TLabel            * Label1;
    TLabel            * Label2;
    TLabel            * Label3;
    TLabel            * Label4;

    TPanel            * Panel1;
    TPanel            * Panel2;

    TRadioGroup       * RadioGroup1;


    void __fastcall BitBtn1Click          (TObject * Sender);
    void __fastcall DateTimePicker1Change (TObject * Sender);
    void __fastcall Edit1KeyPress         (
            TObject * Sender,
            char    & Key
        );
    void __fastcall FormClose             (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate            (TObject * Sender);
    void __fastcall RadioGroup1Click      (TObject * Sender);
private:
public:
    __fastcall TStud_Pr_RestoreForm (TComponent * Owner);
};

extern PACKAGE TStud_Pr_RestoreForm * Stud_Pr_RestoreForm;

#endif  // STUD_PR_RESTORE_UNIT_H
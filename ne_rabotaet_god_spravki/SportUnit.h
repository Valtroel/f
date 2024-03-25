#pragma once
#ifndef SPORT_UNIT_H
#define SPORT_UNIT_H


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
#include <Vcl.ComCtrls.hpp>


class TSportForm
    : public TForm
{
__published:
    TBitBtn           * BitBtn1;
    TBitBtn           * BitBtn2;
    TBitBtn           * BitBtn3;
    TBitBtn           * BitBtn4;

    TComboBox         * ComboBox3;

    TDateTimePicker   * DateTimePicker1;

    TDBGrid           * DBGrid2;

    TDBLookupComboBox * DBLookupComboBox3;

    TDBText           * DBText1;
    TDBText           * DBText2;
    TDBText           * DBText3;

    TEdit             * Edit1;
    TEdit             * Edit2;

    TLabel            * Label1;
    TLabel            * Label2;
    TLabel            * Label6;
    TLabel            * Label7;
    TLabel            * Label8;

    TPanel            * Panel1;
    TPanel            * Panel2;

    TRadioGroup       * RadioGroup1;


    void __fastcall BitBtn1Click          (TObject * Sender);
    void __fastcall BitBtn2Click          (TObject * Sender);
    void __fastcall BitBtn3Click          (TObject * Sender);
    void __fastcall BitBtn4Click          (TObject * Sender);
    void __fastcall DateTimePicker1Change (TObject * Sender);
    void __fastcall Edit1KeyPress         (
            TObject * Sender,
            char    & Key
        );
    void __fastcall FormActivate          (TObject * Sender);
    void __fastcall FormClose             (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormDeactivate        (TObject * Sender);
    void __fastcall RadioGroup1Click      (TObject * Sender);
private:
public:
    __fastcall TSportForm (TComponent * Owner);
};

extern PACKAGE TSportForm * SportForm;

#endif  // SPORT_UNIT_H
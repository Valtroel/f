#pragma once
#ifndef VED_GEK_RESULT_UNIT_H
#define VED_GEK_RESULT_UNIT_H


#include <AppEvnts.hpp>
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


class TVED_GEKResult
    : public TForm
{
__published:
    TApplicationEvents * ApplicationEvents1;

    TBitBtn            * BitBtn1;
    TBitBtn            * BitBtn2;

    TComboBox          * ComboBox2;

    TDBGrid            * DBGrid1;

    TDBText            * DBText1;

    TEdit              * Edit1;
    TEdit              * Edit5;
    TEdit              * Edit6;

    TLabel             * Label1;
    TLabel             * Label4;
    TLabel             * Label9;
    TLabel             * Label10;

    TPanel             * Panel1;


    void __fastcall ApplicationEvents1Message (
            tagMSG & Msg,
            bool   & Handled
        );
    void __fastcall BitBtn2Click              (TObject * Sender);
    void __fastcall ComboBox2Change           (TObject * Sender);
    void __fastcall DBGrid1DblClick           (TObject * Sender);
    void __fastcall Edit1KeyPress             (
            TObject * Sender,
            char    & Key
        );
    void __fastcall Edit5Change               (TObject * Sender);
    void __fastcall FormActivate              (TObject * Sender);
    void __fastcall FormClose                 (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate                (TObject * Sender);
private:
public:
    __fastcall TVED_GEKResult (TComponent * Owner);
};

extern PACKAGE TVED_GEKResult * VED_GEKResult;

#endif  // VED_GEK_RESULT_UNIT_H
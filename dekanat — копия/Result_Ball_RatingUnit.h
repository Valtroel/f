#pragma once
#ifndef RESULT_BALL_RATING_UNIT_H
#define RESULT_BALL_RATING_UNIT_H


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
#include <StdCtrls.hpp>


class TResult_Ball_RatingForm
    : public TForm
{
__published:
    TApplicationEvents * ApplicationEvents1;

    TBitBtn            * BitBtn1;
    TBitBtn            * BitBtn2;

    TDBGrid            * DBGrid1;

    TDBText            * DBText1;
    TDBText            * DBText2;
    TDBText            * DBText3;
    TDBText            * DBText4;

    TEdit              * Edit1;
    TEdit              * Edit2;
    TEdit              * Edit3;

    TLabel             * Label1;
    TLabel             * Label2;
    TLabel             * Label3;
    TLabel             * Label4;
    TLabel             * Label5;
    TLabel             * Label9;
    TLabel             * Label10;

    TPanel             * Panel1;
    TPanel             * Panel2;
    TPanel             * Panel3;
    TPanel             * Panel4;


    void __fastcall ApplicationEvents1Message (
            tagMSG & Msg,
            bool   & Handled
        );
    void __fastcall BitBtn1Click              (TObject * Sender);
    void __fastcall BitBtn2Click              (TObject * Sender);
    void __fastcall Edit1Change               (TObject * Sender);
    void __fastcall Edit1KeyPress             (
            TObject * Sender,
            char    & Key
        );
    void __fastcall Edit2KeyPress             (
            TObject * Sender,
            char    & Key
        );
    void __fastcall FormActivate              (TObject * Sender);
    void __fastcall FormClose                 (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TResult_Ball_RatingForm (TComponent * Owner);
};

extern PACKAGE TResult_Ball_RatingForm * Result_Ball_RatingForm;

#endif  // RESULT_BALL_RATING_UNIT_H
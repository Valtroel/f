#pragma once
#ifndef RESULT_RATING_UNIT_H
#define RESULT_RATING_UNIT_H


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


class TResult_RatingForm
    : public TForm
{
__published:
    TApplicationEvents * ApplicationEvents1;

    TBitBtn            * BitBtn1;
    TBitBtn            * BitBtn2;

    TDBGrid            * DBGrid1;

    TEdit              * Edit1;
    TEdit              * Edit2;
    TEdit              * Edit3;

    TLabel             * Label1;
    TLabel             * Label2;
    TLabel             * Label9;
    TLabel             * Label10;

    TPanel             * Panel1;
    TPanel             * Panel2;
    TPanel             * Panel3;

    TRadioGroup        * RadioGroup1;

    TSpeedButton       * SpeedButton1;


    void __fastcall ApplicationEvents1Message (
            tagMSG & Msg,
            bool   & Handled
        );
    void __fastcall BitBtn1Click              (TObject * Sender);
    void __fastcall BitBtn2Click              (TObject * Sender);
    void __fastcall DBGrid1TitleClick         (TColumn * Column);
    void __fastcall Edit1Change               (TObject * Sender);
    void __fastcall Edit1KeyPress             (
            TObject * Sender,
            char    & Key
        );
    void __fastcall FormActivate              (TObject * Sender);
    void __fastcall FormClose                 (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall SpeedButton1Click         (TObject * Sender);
private:
    Variant App,Sh;

    void __fastcall ExAutoFit (                                                 // процедура установки автоматической ширины столбца
            int one,
            int two
        );
    void __fastcall ExBorder  (                                                 // функция обрамления
            int strok,
            int st
        );
    void __fastcall ExSave    (int par);                                        // функция сохранения
    void __fastcall ExShapka  (                                                 // процедура создания шапочки таблицы
            int        stroka,
            AnsiString text_zag,
            int        stat
        );
    void __fastcall Save_Rat  (                                                 // процедура сохранения рейтинга
            int par,
            int rating
        );
    void __fastcall toEx      (                                                 // функция занесения данных в Excel
            int        Row,
            int        Column,
            AnsiString data
        );
    void __fastcall toEx      (                                                 // функция занесения данных в Excel
            int        Row,
            int        Column,
            Variant    data
        );
public:
    __fastcall TResult_RatingForm (TComponent * Owner);

    int __fastcall Open_SQL (AnsiString text_sql);                              // процедура открытия Query
};

extern PACKAGE TResult_RatingForm * Result_RatingForm;

#endif  // RESULT_RATING_UNIT_H
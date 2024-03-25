#pragma once
#ifndef VED_RATING_UNIT_H
#define VED_RATING_UNIT_H


#include <AppEvnts.hpp>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>


class TVed_RatingForm
    : public TForm
{
__published:
    TApplicationEvents * ApplicationEvents1;

    TBitBtn            * BitBtn1;
    TBitBtn            * BitBtn2;
    TBitBtn            * BitBtn3;
    TBitBtn            * BitBtn4;
    TBitBtn            * BitBtn5;
    TBitBtn            * BitBtn6;
    TBitBtn            * BitBtn7;

    TCheckBox          * CheckBox1;
    TCheckBox          * CheckBox2;
    TCheckBox          * CheckBox3;

    TDBGrid            * DBGrid1;

    TEdit              * Edit1;
    TEdit              * Edit2;
    TEdit              * Edit3;
    TEdit              * Edit4;

    TLabel             * Label1;
    TLabel             * Label3;
    TLabel             * Label4;
    TLabel             * Label7;

    TLabel             * Label8;
    TPanel             * Panel1;
    TPanel             * Panel2;
    TPanel             * Panel3;

    TRadioGroup        * RadioGroup1;
    TRadioGroup        * RadioGroup2;

    TUpDown            * UpDown1;


    void __fastcall ApplicationEvents1Message (
            tagMSG & Msg,
            bool   & Handled
        );
    void __fastcall BitBtn1Click              (TObject * Sender);
    void __fastcall BitBtn2Click              (TObject * Sender);
    void __fastcall BitBtn4Click              (TObject * Sender);
    void __fastcall BitBtn6Click              (TObject * Sender);
    void __fastcall BitBtn7Click              (TObject * Sender);
    void __fastcall CheckBox1Click            (TObject * Sender);
    void __fastcall CheckBox2Click            (TObject * Sender);
    void __fastcall CheckBox3Click            (TObject * Sender);
    void __fastcall DBGrid1DblClick           (TObject * Sender);
    void __fastcall Edit1Click                (TObject * Sender);
    void __fastcall Edit2Click                (TObject * Sender);
    void __fastcall Edit3KeyPress             (
            TObject * Sender,
            char    & Key
        );
    void __fastcall FormActivate              (TObject * Sender);
    void __fastcall FormCreate                (TObject * Sender);
    void __fastcall RadioGroup1Click          (TObject * Sender);
private:
public:
    __fastcall TVed_RatingForm (TComponent * Owner);

    int  __fastcall max_ved_r ();                                               // вызов функции для нахождения максимального номера ведомости
    void __fastcall ved_run_r ();                                               // формирование SQL по параметрам
};

extern PACKAGE TVed_RatingForm * Ved_RatingForm;

#endif  // VED_RATING_UNIT_H
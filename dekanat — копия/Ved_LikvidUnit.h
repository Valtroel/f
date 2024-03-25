#pragma once
#ifndef VED_LIKVID_UNIT_H
#define VED_LIKVID_UNIT_H


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


class TVed_LikvidForm
    : public TForm
{
__published:
    TApplicationEvents * ApplicationEvents1;

    TBitBtn            * BitBtn1;
    TBitBtn            * BitBtn2;
    TBitBtn            * BitBtn3;
    TBitBtn            * BitBtn4;
    TBitBtn            * BitBtn5;

    TCheckBox          * CheckBox1;
    TCheckBox          * CheckBox2;
    TCheckBox          * CheckBox3;

    TDBGrid            * DBGrid1;

    TDBLookupComboBox  * DBLookupComboBox1;

    TEdit              * Edit1;
    TEdit              * Edit2;
    TEdit              * Edit3;

    TGroupBox          * GroupBox1;

    TLabel             * Label3;
    TLabel             * Label4;
    TLabel             * Label7;

    TPanel             * Panel1;
    TPanel             * Panel2;
    TPanel             * Panel3;

    TRadioGroup        * RadioGroup2;

    TSpeedButton       * SpeedButton3;


    void __fastcall ApplicationEvents1Message (
            tagMSG & Msg,
            bool   & Handled
        );
    void __fastcall BitBtn1Click              (TObject * Sender);
    void __fastcall BitBtn2Click              (TObject * Sender);
    void __fastcall BitBtn3Click              (TObject * Sender);
    void __fastcall BitBtn4Click              (TObject * Sender);
    void __fastcall BitBtn5Click              (TObject * Sender);
    void __fastcall CheckBox1Click            (TObject * Sender);
    void __fastcall CheckBox2Click            (TObject * Sender);
    void __fastcall CheckBox3Click            (TObject * Sender);
    void __fastcall DBGrid1DblClick           (TObject * Sender);
    void __fastcall Edit1Click                (TObject * Sender);
    void __fastcall Edit1KeyPress             (
            TObject * Sender,
            char    & Key
        );
    void __fastcall Edit2Click                (TObject * Sender);
    void __fastcall Edit3Click                (TObject * Sender);
    void __fastcall FormActivate              (TObject * Sender);
    void __fastcall FormClose                 (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate                (TObject * Sender);
    void __fastcall RadioGroup2Click          (TObject * Sender);
    void __fastcall SpeedButton3Click         (TObject * Sender);
private:
public:
    __fastcall TVed_LikvidForm (TComponent * Owner);

    void __fastcall ved_run_L ();                                               // выполнение Sql по ведомостям
};

extern PACKAGE TVed_LikvidForm * Ved_LikvidForm;

#endif  // VED_LIKVID_UNIT_H
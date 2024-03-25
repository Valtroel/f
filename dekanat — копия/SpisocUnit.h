#pragma once
#ifndef SPISOC_UNIT_H
#define SPISOC_UNIT_H


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


class TSpisocForm
    : public TForm
{
__published:
    TApplicationEvents * ApplicationEvents1;

    TBitBtn            * BitBtn1;
    TBitBtn            * BitBtn2;

    TCheckBox          * CheckBox1;
    TCheckBox          * CheckBox2;
    TCheckBox          * CheckBox3;
    TCheckBox          * CheckBox4;
    TCheckBox          * CheckBox5;
    TCheckBox          * CheckBox6;

    TComboBox          * ComboBox4;

    TDBGrid            * DBGrid1;
    TDBGrid            * DBGrid2;

    TEdit              * Edit1;
    TEdit              * Edit2;

    TGroupBox          * GroupBox1;
    TGroupBox          * GroupBox2;

    TLabel             * Label1;
    TLabel             * Label2;
    TLabel             * Label3;
    TLabel             * Label4;
    TLabel             * Label5;
    TLabel             * Label10;
    TLabel             * Label47;

    TPanel             * Panel1;
    TPanel             * Panel2;
    TPanel             * Panel3;

    TRadioGroup        * RadioGroup1;
    TRadioGroup        * RadioGroup2;
    TRadioGroup        * RG1;
    TRadioGroup        * RG2;


    void __fastcall ApplicationEvents1Message (
            tagMSG & Msg,
            bool   & Handled
        );
    void __fastcall BitBtn1Click              (TObject * Sender);
    void __fastcall BitBtn2Click              (TObject * Sender);
    void __fastcall CheckBox1Click            (TObject * Sender);
    void __fastcall CheckBox2Click            (TObject * Sender);
    void __fastcall CheckBox3Click            (TObject * Sender);
    void __fastcall CheckBox4Click            (TObject * Sender);
    void __fastcall CheckBox5Click            (TObject * Sender);
    void __fastcall CheckBox6Click            (TObject * Sender);
    void __fastcall DBGrid1CellClick          (TColumn * Column);
    void __fastcall DBGrid1DblClick           (TObject * Sender);
    void __fastcall DBGrid2CellClick          (TColumn * Column);
    void __fastcall DBGrid2DblClick           (TObject * Sender);
    void __fastcall Edit1Change               (TObject * Sender);
    void __fastcall Edit2Change               (TObject * Sender);
    void __fastcall Edit2KeyPress             (
            TObject * Sender,
            char    & Key
        );
    void __fastcall FormActivate              (TObject * Sender);
    void __fastcall FormClose                 (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall RadioGroup1Click          (TObject * Sender);
    void __fastcall RadioGroup2Click          (TObject * Sender);
    void __fastcall RG1Click                  (TObject * Sender);
    void __fastcall RG2Click                  (TObject * Sender);
private:
public:
    __fastcall TSpisocForm (TComponent * Owner);
};

extern PACKAGE TSpisocForm * SpisocForm;

#endif  // SPISOC_UNIT_H
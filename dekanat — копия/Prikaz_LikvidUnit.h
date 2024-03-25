#pragma once
#ifndef PRIKAZ_LIKVID_UNIT_H
#define PRIKAZ_LIKVID_UNIT_H


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


class TPrikaz_LikvidForm
    : public TForm
{
__published:
    TBitBtn           * BitBtn2;
    TBitBtn           * BitBtn3;
    TButton           * Button1;

    TComboBox         * ComboBox3;
    TComboBox         * ComboBox4;

    // TDateEdit         * DateEdit1;
    // TDateEdit         * DateEdit2;
    // TDateEdit         * DateEdit3;

    TDateTimePicker   * DateTimePicker1;
    TDateTimePicker   * DateTimePicker2;
    TDateTimePicker   * DateTimePicker3;

    TDBGrid           * DBGrid1;

    TDBLookupComboBox * DBLookupComboBox1;
    TDBLookupComboBox * DBLookupComboBox2;
    TDBLookupComboBox * DBLookupComboBox3;

    TEdit             * Edit1;
    TEdit             * Edit2;
    TEdit             * Edit7;

    TGroupBox         * GroupBox1;

    TLabel            * Label1;
    TLabel            * Label2;
    TLabel            * Label3;
    TLabel            * Label4;
    TLabel            * Label5;
    TLabel            * Label6;
    TLabel            * Label7;
    TLabel            * Label8;
    TLabel            * Label12;
    TLabel            * Label13;
    TLabel            * Label14;

    TPanel            * Panel1;
    TPanel            * Panel2;
    TPanel            * Panel3;
    TPanel            * Panel4;
    TPanel            * Panel5;
    TPanel            * Panel6;

    TRadioGroup       * RadioGroup1;
    TRadioGroup       * RadioGroup2;
    TRadioGroup       * RadioGroup3;
    TRadioGroup       * RadioGroup4;
    TRadioGroup       * RadioGroup5;
    TRadioGroup       * RadioGroup6;


    void __fastcall BitBtn3Click          (TObject * Sender);
    void __fastcall Button1Click          (TObject * Sender);
    void __fastcall DateTimePicker1Change (TObject * Sender);
    void __fastcall DateTimePicker2Change (TObject * Sender);
    void __fastcall DateTimePicker3Change (TObject * Sender);
    void __fastcall Edit7KeyPress         (
            TObject * Sender,
            char    & Key
        );
    void __fastcall FormClose             (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormShow              (TObject * Sender);
    void __fastcall RadioGroup1Click      (TObject * Sender);
    void __fastcall RadioGroup2Click      (TObject * Sender);
    void __fastcall RadioGroup6Click      (TObject * Sender);
private:
public:
    __fastcall TPrikaz_LikvidForm (TComponent * Owner);
};

extern PACKAGE TPrikaz_LikvidForm * Prikaz_LikvidForm;

#endif  // PRIKAZ_LIKVID_UNIT_H
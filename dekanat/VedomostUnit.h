#pragma once
#ifndef VEDOMOST_UNIT_H
#define VEDOMOST_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
// #include "MyList.h"
#include <StdCtrls.hpp>
// #include "Tooledit.hpp"


class TVedomostForm
    : public TForm
{
__published:
    TBitBtn   * BitBtn1;
    TBitBtn   * BitBtn2;
    TBitBtn   * BitBtn3;

    TCheckBox * CheckBox1;
    TCheckBox * CheckBox2;

    TComboBox * ComboBox1;
    TComboBox * ComboBox2;
    TComboBox * ComboBox3;

    TDBEdit   * DBEdit2;

    TEdit     * Edit1;
    TEdit     * Edit2;
    TEdit     * Edit3;
    TEdit     * Edit4;

    TLabel    * Label1;
    TLabel    * Label2;
    TLabel    * Label3;
    TLabel    * Label4;
    TLabel    * Label5;
    TLabel    * Label6;
    TLabel    * Label7;
    TLabel    * Label8;
    TLabel    * Label9;

    TPanel    * Panel1;
    TPanel    * Panel2;
    TPanel    * Panel3;
    TPanel    * Panel4;
    TPanel    * Panel5;


    void __fastcall BitBtn1Click   (TObject * Sender);
    void __fastcall BitBtn2Click   (TObject * Sender);
    void __fastcall BitBtn3Click   (TObject * Sender);
    void __fastcall CheckBox1Click (TObject * Sender);
    void __fastcall Edit1Enter     (TObject * Sender);
    void __fastcall Edit2Exit      (TObject * Sender);
    void __fastcall Edit2KeyPress  (
            TObject * Sender,
            char    & Key
        );
    void __fastcall Edit3Change    (TObject * Sender);
    void __fastcall Edit4Enter     (TObject * Sender);
    void __fastcall FormClose      (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormShow       (TObject * Sender);
    void __fastcall Panel2Click    (TObject * Sender);
private:
public:
    __fastcall TVedomostForm (TComponent * Owner);
};

extern PACKAGE TVedomostForm * VedomostForm;

#endif  // VEDOMOST_UNIT_H
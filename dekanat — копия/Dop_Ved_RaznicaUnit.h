#pragma once
#ifndef DOP_VED_RAZNICA_UNIT_H
#define DOP_VED_RAZNICA_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <StdCtrls.hpp>


class TDop_Ved_RaznicaForm
    : public TForm
{
__published:
    TBitBtn           * BitBtn1;
    TBitBtn           * BitBtn2;

    TComboBox         * ComboBox1;
    TComboBox         * ComboBox2;

    TDBLookupComboBox * DBLookupComboBox1;

    TEdit             * Edit1;
    TEdit             * Edit2;
    TEdit             * Edit3;
    TEdit             * Edit5;
    TEdit             * Edit6;
    TEdit             * Edit7;
    TEdit             * Edit8;

    TLabel            * Label1;
    TLabel            * Label2;
    TLabel            * Label3;
    TLabel            * Label4;
    TLabel            * Label5;
    TLabel            * Label6;
    TLabel            * Label7;
    TLabel            * Label8;
    TLabel            * Label9;
    TLabel            * Label10;
    TLabel            * Label11;
    TLabel            * Label12;
    TLabel            * Label15;

    TPanel            * Panel1;
    TPanel            * Panel2;
    TPanel            * Panel3;
    TPanel            * Panel4;
    TPanel            * Panel5;


    void __fastcall BitBtn1Click             (TObject * Sender  );
    void __fastcall BitBtn2Click             (TObject * Sender  );
    void __fastcall DBLookupComboBox1CloseUp (TObject * Sender  );
    void __fastcall Edit1Click               (TObject * Sender  );
    void __fastcall Edit2Click               (TObject * Sender  );
    void __fastcall Edit3Exit                (TObject * Sender  );
    void __fastcall Edit3KeyPress            (
            TObject * Sender,
            char    & Key
        );
    void __fastcall Edit5Exit                (TObject * Sender  );
    void __fastcall FormClose                (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormShow                 (TObject * Sender  );
    int  __fastcall max_ved_likvid           (int       god_real);              // возвращает максимальный номер ведомости
    void __fastcall Panel5Click              (TObject * Sender  );
private:
public:
    __fastcall TDop_Ved_RaznicaForm (TComponent * Owner);
};

extern PACKAGE TDop_Ved_RaznicaForm * Dop_Ved_RaznicaForm;

#endif  // DOP_VED_RAZNICA_UNIT_H
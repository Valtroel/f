#pragma once
#ifndef SPRAVKI_UNIT_H
#define SPRAVKI_UNIT_H


#include <AppEvnts.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>
#include <Vcl.Buttons.hpp>


class TSpavkiForm
    : public TForm
{
__published:
    TApplicationEvents * ApplicationEvents1;

    TButton            * Button1;

    TCheckBox          * CheckBox1;
    TCheckBox          * CheckBox2;
    TCheckBox          * CheckBox3;
    TCheckBox          * CheckBox4;
    TCheckBox          * CheckBox5;
    TCheckBox          * CheckBox6;
    TCheckBox          * CheckBox7;
    TCheckBox          * CheckBox8;
    TCheckBox          * CheckBox9;
    TCheckBox          * CheckBox10;
    TCheckBox          * CheckBox11;
    TCheckBox          * CheckBox12;
    TCheckBox          * CheckBox13;
    TCheckBox          * CheckBox14;
    TCheckBox          * CheckBox15;
    TCheckBox          * CheckBox16;
    TCheckBox          * CheckBox17;
    TCheckBox          * CheckBox18;
    TCheckBox          * CheckBox19;
    TCheckBox          * CheckBox20;
    TCheckBox          * CheckBox21;
    TCheckBox          * CheckBox22;
    TCheckBox          * CheckBox23;
    TCheckBox          * CheckBox24;

    TComboBox          * ComboBox1;
    TComboBox          * ComboBox2;

    TDBGrid            * DBGrid1;

    TLabel             * Label1;
    TLabel             * Label2;

    TLabeledEdit       * LabeledEdit1;

    TMemo              * Memo1;
    TMemo              * Memo2;
    TMemo              * Memo3;
    TMemo              * Memo4;
    TMemo              * Memo5;
    TMemo              * Memo6;
    TMemo              * Memo7;
    TMemo              * Memo8;
    TMemo              * Memo9;
    TMemo              * Memo10;
    TMemo              * Memo11;
    TMemo              * Memo12;
    TMemo              * Memo13;
    TMemo              * Memo14;
    TMemo              * Memo15;
    TMemo              * Memo16;
    TMemo              * Memo17;
    TMemo              * Memo18;
    TMemo              * Memo19;
    TMemo              * Memo20;
    TMemo              * Memo21;
    TMemo              * Memo22;
    TMemo              * Memo23;
    TMemo              * Memo24;

    TPanel             * Panel1;
    TPanel             * Panel2;
    TPanel             * Panel3;
    TPanel             * Panel4;

    TRadioGroup        * RadioGroup1;


    void __fastcall ApplicationEvents1Message (
            tagMSG & Msg,
            bool   & Handled
        );
    void __fastcall Button1Click              (TObject * Sender);
    void __fastcall CheckBox17Click           (TObject * Sender);
    void __fastcall CheckBox18Click           (TObject * Sender);
    void __fastcall FormClose                 (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall LabeledEdit1Change        (TObject * Sender);
    void __fastcall RadioGroup1Click          (TObject * Sender);
private:
public:
    __fastcall TSpavkiForm (TComponent * Owner);

    void memo_ch (
            TCheckBox * ch,
            TMemo     * m,
            int         par
        );
    void refrech_memo_ch ();
};

extern PACKAGE TSpavkiForm * SpavkiForm;

#endif  // SPRAVKI_UNIT_H
#pragma once
#ifndef PRIVILEGE_UNIT_H
#define PRIVILEGE_UNIT_H


#include <AppEvnts.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
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


class TPrivilegeForm
    : public TForm
{
__published:
    TApplicationEvents * ApplicationEvents1;

    TButton            * Button1;
    TButton            * Button2;
    TButton            * Button3;

    TCheckBox          * CheckBox1;
    TCheckBox          * CheckBox2;

    TDateTimePicker    * DateTimePicker1;
    TDateTimePicker    * DateTimePicker2;
    TDateTimePicker    * DateTimePicker3;

    TDBGrid            * DBGrid1;

    TDBLookupComboBox  * DBLookupComboBox1;

    TEdit              * Edit1;

    TGroupBox          * GroupBox1;

    TLabel             * Label2;
    TLabel             * Label3;
    TLabel             * Label4;
    TLabel             * Label5;
    TLabel             * Label6;

    TLabeledEdit       * LabeledEdit1;
    TLabeledEdit       * LabeledEdit2;
    TLabeledEdit       * LabeledEdit3;

    TPanel             * Panel1;
    TPanel             * Panel2;
    TPanel             * Panel3;
    TPanel             * Panel4;

    TRadioGroup        * RadioGroup1;
    TRadioGroup        * RadioGroup2;

    TUpDown            * UpDown1;


    void __fastcall ApplicationEvents1Message (
            tagMSG & Msg,
            bool   & Handled
        );
    void __fastcall Button1Click              (TObject * Sender);
    void __fastcall Button2Click              (TObject * Sender);
    void __fastcall Button3Click              (TObject * Sender);
    void __fastcall CheckBox1Click            (TObject * Sender);
    void __fastcall DateTimePicker1Change     (TObject * Sender);
    void __fastcall DateTimePicker2Change     (TObject * Sender);
    void __fastcall DateTimePicker3Change     (TObject * Sender);
    void __fastcall DBGrid1DblClick           (TObject * Sender);
    void __fastcall FormClose                 (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate                (TObject * Sender);
    void __fastcall FormResize                (TObject * Sender);
    void __fastcall RadioGroup1Click          (TObject * Sender);
    void __fastcall RadioGroup2Click          (TObject * Sender);
    void __fastcall UpDown1Click              (
            TObject    * Sender,
            TUDBtnType   Button
        );
private:
    void __fastcall open_sql     ();
    void __fastcall refrech_priv (int r);                                       // заполнение полей в зависимости от выбора справки
public:
    __fastcall TPrivilegeForm (TComponent * Owner);
};

extern PACKAGE TPrivilegeForm * PrivilegeForm;

#endif  // PRIVILEGE_UNIT_H
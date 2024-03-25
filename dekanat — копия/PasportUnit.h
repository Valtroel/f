#pragma once
#ifndef PASSPORT_UNIT_H
#define PASSPORT_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
// #include "DBGridEh.hpp"
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
// #include "GridsEh.hpp"
#include <Mask.hpp>
#include <StdCtrls.hpp>
// #include "ToolEdit.hpp"
#include <Vcl.ComCtrls.hpp>



class TPasportForm
    : public TForm
{
__published:
    TBitBtn           * BitBtn1;
    TBitBtn           * BitBtn2;
    TBitBtn           * BitBtn3;

    TComboBox         * ComboBox1;

    TDateTimePicker   * DateTimePicker1;
    TDateTimePicker   * DateTimePicker2;

    TDBEdit           * DBEdit1;
    TDBEdit           * DBEdit2;
    TDBEdit           * DBEdit3;
    TDBEdit           * DBEdit6;
    TDBEdit           * DBEdit7;

    TDBLookupComboBox * DBLookupComboBox1;
    TDBLookupComboBox * DBLookupComboBox2;
    TDBLookupComboBox * DBLookupComboBox3;
    TDBLookupComboBox * DBLookupComboBox4;

    TDBMemo           * DBMemo1;

    TDBText           * DBText1;
    TDBText           * DBText2;
    TDBText           * DBText3;

    TEdit             * Edit1;
    TEdit             * Edit2;
    TEdit             * Edit3;

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
    TLabel            * Label13;
    TLabel            * Label14;
    TLabel            * Label15;
    TLabel            * Label16;
    TLabel            * Label17;
    TLabel            * Label18;

    TMemo             * Memo1;

    TPanel            * Panel1;
    TPanel            * Panel2;
    TPanel            * Panel3;
    TPanel            * Panel4;
    TPanel            * Panel5;
    TPanel            * Panel6;

    TSpeedButton      * SpeedButton1;
    TSpeedButton      * SpeedButton2;
    TSpeedButton      * SpeedButton3;


    void __fastcall BitBtn1Click             (TObject * Sender);
    void __fastcall BitBtn2Click             (TObject * Sender);
    void __fastcall ComboBox1Exit            (TObject * Sender);
    void __fastcall DateTimePicker1Change    (TObject * Sender);
    void __fastcall DateTimePicker2Change    (TObject * Sender);
    void __fastcall DBLookupComboBox2CloseUp (TObject * Sender);
    void __fastcall DBLookupComboBox2Exit    (TObject * Sender);
    void __fastcall Edit2KeyPress            (
            TObject * Sender,
            char    & Key
        );
    void __fastcall FormActivate             (TObject * Sender);
    void __fastcall FormClose                (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall SpeedButton1Click        (TObject * Sender);
    void __fastcall SpeedButton2Click        (TObject * Sender);
    void __fastcall SpeedButton3Click        (TObject * Sender);
private:
public:
    __fastcall TPasportForm (TComponent * Owner);

    void __fastcall AreaDisplay    ();                                          // процедура доступа к районам Минска
    void __fastcall ClearComponent ();                                          // процедура очистки компонентов
    void __fastcall PressBtn       (int press_btn);                             // функция выбора
    void __fastcall SaveData       ();                                          // процедура сохранения данных паспорта
};

extern PACKAGE TPasportForm * PasportForm;

#endif  // PASSPORT_UNIT_H
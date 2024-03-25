#pragma once
#ifndef VIPUSKNIKI_UNIT_H
#define VIPUSKNIKI_UNIT_H


#include <AppEvnts.hpp>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBGrids.hpp>
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
#include <Grids.hpp>
#include <Mask.hpp>
#include <StdCtrls.hpp>
// #include "ToolEdit.hpp"


class TVipusknikiForm
    : public TForm
{
__published:
    TApplicationEvents * ApplicationEvents1;

    TBitBtn            * BitBtn1;
    TBitBtn            * BitBtn2;
    TBitBtn            * BitBtn3;

    TButton            * Button1;

    TCheckBox          * CheckBox1;
    TCheckBox          * CheckBox2;

    TDateTimePicker    * DateTimePicker1;
    TDateTimePicker    * DateTimePicker2;
    TDateTimePicker    * DateTimePicker3;
    TDateTimePicker    * DateTimePicker4;

    TDBGrid            * DBGrid1;

    TEdit              * Edit1;
    TEdit              * Edit2;
    TEdit              * Edit3;
    TEdit              * Edit4;
    TEdit              * Edit5;
    TEdit              * Edit6;
    TEdit              * Edit7;

    TLabel             * Label1;
    TLabel             * Label2;
    TLabel             * Label3;
    TLabel             * Label4;
    TLabel             * Label5;
    TLabel             * Label6;
    TLabel             * Label7;
    TLabel             * Label8;
    TLabel             * Label9;
    TLabel             * Label10;
    TLabel             * Label11;
    TLabel             * Label12;
    TLabel             * Label13;

    TListBox           * ListBox1;
    TListBox           * ListBox2;

    TPanel             * Panel1;
    TPanel             * Panel2;
    TPanel             * Panel3;
    TPanel             * Panel4;
    TPanel             * Panel5;
    TPanel             * Panel6;
    TPanel             * Panel7;
    TPanel             * Panel8;
    TPanel             * Panel9;
    TPanel             * Panel10;
    TPanel             * Panel11;

    TProgressBar       * ProgressBar1;

    TRadioGroup        * RadioGroup1;
    TRadioGroup        * RadioGroup3;

    TSpeedButton       * SpeedButton1;
    TSpeedButton       * SpeedButton2;
    TSpeedButton       * SpeedButton3;
    TSpeedButton       * SpeedButton4;

    TSplitter          * Splitter1;
    TSplitter          * Splitter2;

    TUpDown            * UpDown1;


    void __fastcall ApplicationEvents1Message (
            tagMSG & Msg,
            bool   & Handled
        );
    void __fastcall BitBtn1Click              (TObject * Sender);
    void __fastcall BitBtn2Click              (TObject * Sender);
    void __fastcall BitBtn3Click              (TObject * Sender);
    void __fastcall Button1Click              (TObject * Sender);
    void __fastcall CheckBox1Click            (TObject * Sender);
    void __fastcall DateTimePicker1Change     (TObject * Sender);
    void __fastcall DateTimePicker2Change     (TObject * Sender);
    void __fastcall DBGrid1CellClick          (TColumn * Column);
    void __fastcall DBGrid1DblClick           (TObject * Sender);
    void __fastcall DBGrid1KeyDown            (
            TObject     * Sender,
            WORD        & Key,
            TShiftState   Shift
        );
    void __fastcall Edit1KeyPress             (
            TObject * Sender,
            char    & Key
        );
    void __fastcall Edit3Change               (TObject * Sender);
    void __fastcall FormActivate              (TObject * Sender);
    void __fastcall FormClose                 (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate                (TObject * Sender);
    void __fastcall Panel9CanResize           (
            TObject * Sender,
            int     & NewWidth,
            int     & NewHeight,
            bool    & Resize
        );
    void __fastcall Panel9DblClick            (TObject * Sender);
    void __fastcall RadioGroup1Click          (TObject * Sender);
    void __fastcall RadioGroup3Click          (TObject * Sender);
    void __fastcall SpeedButton1Click         (TObject * Sender);
    void __fastcall SpeedButton2Click         (TObject * Sender);
    void __fastcall SpeedButton3Click         (TObject * Sender);
    void __fastcall SpeedButton4Click         (TObject * Sender);
    void __fastcall UpDown1Click              (
            TObject    * Sender,
            TUDBtnType   Button
        );
private:
public:
    __fastcall TVipusknikiForm (TComponent * Owner);

    void                  columnWidth      (Variant WSheet    );
    void       __fastcall Form_max         ();                                  // Функция увеличения формы
    void       __fastcall Form_min         ();                                  // Функция уменьшения формы
    AnsiString            getDiplomType    (int     idDiplom  );
    AnsiString            getFac           (int     item_index);
    AnsiString            getForm          (int     item_index);
    AnsiString            getPeriod        (int     item_index);
    AnsiString            getQualification (
            AnsiString q,
            int        spec_v,
            int        vid_edu_v,
            Variant    d
        );
    void       __fastcall ShowDiplom       ();                                  // функция показа данных по диплому
    void                  writeExcel       (
            Variant    WSheet,
            TFDQuery * q,
            int        i
        );
};

extern PACKAGE TVipusknikiForm * VipusknikiForm;

#endif  // VIPUSKNIKI_UNIT_H
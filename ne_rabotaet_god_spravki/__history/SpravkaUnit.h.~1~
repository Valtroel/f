#pragma once
#ifndef SPRAVKA_UNIT_H
#define SPRAVKA_UNIT_H


#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include <Data.DB.hpp>
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
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.StdCtrls.hpp>


class TSpravkaForm
    : public TForm
{
__published:
    TButton            * Ïå÷àòü;

    TCheckBox          * CheckBox1;
    TCheckBox          * CheckBox2;
    TCheckBox          * CheckBox3;
    TCheckBox          * CheckBox4;
    TCheckBox          * CheckBox5;
    TCheckBox          * CheckBox6;

    TDataSource        * DataSource1;
    TDataSource        * DataSource2;

    TDBGrid            * DBGrid1;

    TEdit              * Edit1;
    TEdit              * Edit2;
    TEdit              * Edit3;
    TEdit              * Edit4;
    TEdit              * Edit5;
    TEdit              * Edit6;
    TEdit              * Edit7;
    TEdit              * Edit8;
    TEdit              * Edit9;

    TFDQuery           * FDQuery1;
    TFDQuery           * FDQuery2;
    TFDQuery           * FDQuery3;
    TFDQuery           * FDQuery4;
    TFDQuery           * FDQuery5;

    TIntegerField      * FDQuery1NOMER;
    TIntegerField      * FDQuery2NOMER;
    TIntegerField      * FDQuery3NOMER;
    TIntegerField      * FDQuery4NOMER;

    TLabel             * Label1;
    TLabel             * Label2;
    TLabel             * Label3;
    TLabel             * Label4;

    TLargeintField     * FDQuery5COUNT;

    TMemo              * Memo1;
    TMemo              * Memo2;

    TRadioGroup        * RadioGroup1;

    TSmallintField     * FDQuery1KURS;
    TSmallintField     * FDQuery1N_FOUND;
    TSmallintField     * FDQuery1N_PRIKAZ_INCLUDE;
    TSmallintField     * FDQuery1VID_EDU;
    TSmallintField     * FDQuery2KURS;

    TSQLTimeStampField * FDQuery1D_PRIKAZ_INCLUDE;
    TSQLTimeStampField * FDQuery3MAX;
    TSQLTimeStampField * FDQuery4MAX;

    TStringField       * FDQuery1CODE_SPEC_DIR;
    TStringField       * FDQuery1DEAN;
    TStringField       * FDQuery1FAC_RP;
    TStringField       * FDQuery1FAM;
    TStringField       * FDQuery1N_GROUP;
    TStringField       * FDQuery1NAME;
    TStringField       * FDQuery1OTCH;
    TStringField       * FDQuery1SPECIAL_DIRECTION;
    TStringField       * FDQuery1SPECIAL;
    TStringField       * FDQuery2DEAN;
    TStringField       * FDQuery2FAM;
    TStringField       * FDQuery2N_GROUP;
    TStringField       * FDQuery2NAME;
    TStringField       * FDQuery2OTCH;


    void __fastcall CheckBox1Click        (TObject * Sender);
    void __fastcall CheckBox2Click        (TObject * Sender);
    void __fastcall CheckBox3Click        (TObject * Sender);
    void __fastcall CheckBox4Click        (TObject * Sender);
    void __fastcall CheckBox6Click        (TObject * Sender);
    void __fastcall DataSource2DataChange (
            TObject * Sender,
            TField  * Field
        );
    void __fastcall Edit1Change           (TObject * Sender);
    void __fastcall FormActivate          (TObject * Sender);
    void __fastcall FormClose             (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate            (TObject * Sender);
    void __fastcall Ïå÷àòüClick           (TObject * Sender);
private:
public:
    __fastcall TSpravkaForm (TComponent * Owner);

    void __fastcall Dop_text ();
};

extern PACKAGE TSpravkaForm * SpravkaForm;

#endif  // SPRAVKA_UNIT_H
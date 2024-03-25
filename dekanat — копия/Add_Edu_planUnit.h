#pragma once
#ifndef ADD_EDU_PLAN_UNIT_H
#define ADD_EDU_PLAN_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
// #include <DBTables.hpp>
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
// #include "MyList.h"
#include <StdCtrls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.DBGrids.hpp>


class TAdd_Edu_planForm
    : public TForm
{
__published:
    TBitBtn           * BitBtn1;
    TBitBtn           * BitBtn2;

    TCheckBox         * CheckBox1;
    TCheckBox         * CheckBox2;

    TComboBox         * ComboBox1;
    TComboBox         * ComboBox2;

    TDataSource       * DataSource1;
    TDataSource       * DataSource2;

    TDBGrid           * DBGrid1;

    TDBLookupComboBox * DBLookupComboBox1;
    TDBLookupComboBox * DBLookupComboBox3;
    TDBLookupComboBox * DBLookupComboBox4;

    TEdit             * Edit1;
    TEdit             * Edit2;
    TEdit             * Edit3;
    TEdit             * Edit4;
    TEdit             * Edit5;
    TEdit             * Edit6;
    TEdit             * Edit7;
    TEdit             * Edit8;
    TEdit             * Edit9;
    TEdit             * Edit10;
    TEdit             * Edit11;
    TEdit             * Edit12;
    TEdit             * Edit13;

    TFDQuery          * FDQuery1;
    TFDQuery          * FDQuery2;
    TFDQuery          * FDQuery3;
    TFDQuery          * FDQuery4;
    TFDQuery          * FDQuery5;

    TFDTable          * FDTable1;
    TFDTable          * FDTable2;

    TFDUpdateSQL      * FDUpdateSQL1;
    TFDUpdateSQL      * FDUpdateSQL2;

    TIntegerField     * FDQuery2N_PLAN_PARENT;
    TIntegerField     * FDQuery2N_PLAN;
    TIntegerField     * FDQuery3N_PLAN_PARENT;
    TIntegerField     * FDQuery3N_PLAN;

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
    TLabel            * Label19;
    TLabel            * Label20;

    TLargeintField    * FDQuery1COUNT;

    TMaskEdit         * MaskEdit1;
    TMaskEdit         * MaskEdit2;

    TPanel            * Panel1;
    TPanel            * Panel2;

    TRadioGroup       * RadioGroup1;
    TRadioGroup       * RadioGroup2;

    TSingleField      * FDQuery2PERC_SUB_PLAN;
    TSingleField      * FDQuery3PERC_SUB_PLAN;

    TSmallintField    * FDQuery2CLASSROOM_HOURS;
    TSmallintField    * FDQuery2CLOCK_PLAN;
    TSmallintField    * FDQuery2IND_NUMB;
    TSmallintField    * FDQuery2LECTURE_HOURS;
    TSmallintField    * FDQuery2N_OBJECT;
    TSmallintField    * FDQuery2SEMINAR_HOURS;
    TSmallintField    * FDQuery3CLASSROOM_HOURS;
    TSmallintField    * FDQuery3CLOCK_PLAN;
    TSmallintField    * FDQuery3IND_NUMB;
    TSmallintField    * FDQuery3LECTURE_HOURS;
    TSmallintField    * FDQuery3N_OBJECT;
    TSmallintField    * FDQuery3SEMINAR_HOURS;
    TSmallintField    * FDQuery4ALL_CLOCK_PLAN;
    TSmallintField    * FDQuery4INTEGR_MODUL;
    TSmallintField    * FDQuery4N_OBJECT;
    TSmallintField    * FDQuery5ALL_CLOCK_PLAN;
    TSmallintField    * FDQuery5INTEGR_MODUL;
    TSmallintField    * FDQuery5N_OBJECT;
    TSmallintField    * FDTable1ALL_CLOCK_PLAN;
    TSmallintField    * FDTable1INTEGR_MODUL;
    TSmallintField    * FDTable1N_OBJECT;
    TSmallintField    * FDTable2ALL_CLOCK_PLAN;
    TSmallintField    * FDTable2INTEGR_MODUL;
    TSmallintField    * FDTable2N_OBJECT;

    TStringField      * FDQuery4NAME_OBJECT;
    TStringField      * FDQuery4SHORT_NAME;
    TStringField      * FDQuery5NAME_OBJECT;
    TStringField      * FDQuery5SHORT_NAME;
    TStringField      * FDTable1NAME_OBJECT;
    TStringField      * FDTable1SHORT_NAME;
    TStringField      * FDTable2NAME_OBJECT;
    TStringField      * FDTable2SHORT_NAME;

    void __fastcall BitBtn1Click     (TObject * Sender);
    void __fastcall BitBtn2Click     (TObject * Sender);
    void __fastcall CheckBox1Click   (TObject * Sender);
    void __fastcall Edit1KeyPress    (
            TObject * Sender,
            char    & Key
        );
    void __fastcall Edit4Change      (TObject * Sender);
    void __fastcall Edit5Change      (TObject * Sender);
    void __fastcall Edit6Exit        (TObject * Sender);
    void __fastcall Edit7Exit        (TObject * Sender);
    void __fastcall Edit8Exit        (TObject * Sender);
    void __fastcall Edit9Exit        (TObject * Sender);
    void __fastcall Edit10Exit       (TObject * Sender);
    void __fastcall Edit11Exit       (TObject * Sender);
    void __fastcall Edit12Exit       (TObject * Sender);
    void __fastcall Edit13Exit       (TObject * Sender);
    void __fastcall FormClose        (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall RadioGroup1Click (TObject * Sender);
private:
public:
    __fastcall TAdd_Edu_planForm (TComponent * Owner);
};

extern PACKAGE TAdd_Edu_planForm * Add_Edu_planForm;

#endif  // ADD_EDU_PLAN_UNIT_H
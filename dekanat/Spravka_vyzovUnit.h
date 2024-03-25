#pragma once
#ifndef SPRAVKA_VYZOV_UNIT_H
#define SPRAVKA_VYZOV_UNIT_H


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
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include <System.Classes.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>


class TSpravka_vyzovForm
    : public TForm
{
__published:
    TButton          * Button1;

    TDataSource      * DataSource1;
    TDataSource      * DataSource2;

    TDateTimePicker  * DateTimePicker1;
    TDateTimePicker  * DateTimePicker2;
    TDateTimePicker  * DateTimePicker3;

    TDBLookupListBox * DBLookupListBox1;

    TEdit            * Edit1;

    TFDQuery         * FDQuery1;
    TFDQuery         * FDQuery2;

    TIntegerField    * FDQuery2NOMER;

    TLabel           * Label1;
    TLabel           * Label2;
    TLabel           * Label3;
    TLabel           * Label4;
    TLabel           * Label5;
    TLabel           * Label6;

    TListBox         * ListBox1;
    TListBox         * ListBox2;

    TSmallintField   * FDQuery1INC_GROUP;

    TStringField     * FDQuery1N_GROUP;
    TStringField     * FDQuery2FAM;
    TStringField     * FDQuery2NAME;
    TStringField     * FDQuery2OTCH;


    void __fastcall Button1Click  (TObject * Sender);
    void __fastcall FormActivate  (TObject * Sender);
    void __fastcall ListBox1Click (TObject * Sender);
private:
public:
    __fastcall TSpravka_vyzovForm (TComponent * Owner);
};

extern PACKAGE TSpravka_vyzovForm * Spravka_vyzovForm;

#endif  // SPRAVKA_VYZOV_UNIT_H
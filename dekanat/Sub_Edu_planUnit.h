#pragma once
#ifndef SUB_EDU_PLAN_UNIT_H
#define SUB_EDU_PLAN_UNIT_H


#include <Data.DB.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <DBTables.hpp>
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
#include <StdCtrls.hpp>
#include <System.Classes.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>


class TSub_Edu_planForm
    : public TForm
{
__published:
    TEdit  * Edit1;
    TEdit  * Edit2;
    TEdit  * Edit3;
    TEdit  * Edit4;
    TEdit  * Edit5;
    TEdit  * Edit6;
    TEdit  * Edit7;
    TEdit  * Edit8;

    TLabel * Label1;
    TLabel * Label2;
    TLabel * Label3;
    TLabel * Label4;
    TLabel * Label5;
    TLabel * Label6;
    TLabel * Label7;
    TLabel * Label8;
    TLabel * Label9;
    TLabel * Label10;


    void __fastcall BitBtn1Click (TObject * Sender);
    void __fastcall Edit1Change  (TObject * Sender);
    void __fastcall Edit2Change  (TObject * Sender);
private:
public:
    __fastcall TSub_Edu_planForm (TComponent * Owner);
};

extern PACKAGE TSub_Edu_planForm * Sub_Edu_planForm;

#endif  // SUB_EDU_PLAN_UNIT_H
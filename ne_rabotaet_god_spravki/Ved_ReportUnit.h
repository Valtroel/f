#pragma once
#ifndef VED_REPORT_UNIT_H
#define VED_REPORT_UNIT_H


#include <Classes.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
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
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxPreview.hpp"
#include "frxRich.hpp"
#include <Graphics.hpp>
#include <StdCtrls.hpp>


class TVed_ReportForm
    : public TForm
{
__published:
    TDataSource        * DataSource1;
    TDataSource        * DataSource3;

    TFDQuery           * FDQuery1;
    TFDQuery           * FDQuery3;
    TFDQuery           * FDQuery5;

    TFloatField        * FDQuery1CLOCK_PLAN;
    TFloatField        * FDQuery3CLOCK_PLAN;

    TfrxDBDataset      * frxDBDataset1;
    TfrxDBDataset      * frxDBDataset3;

    TfrxPreview        * frxPreview1;

    TfrxReport         * frxReport1;
    TfrxReport         * frxReport3;

    TLargeintField     * FDQuery5COUNT;

    TSingleField       * FDQuery3PERC_SUB_PLAN_1;
    TSingleField       * FDQuery3PERC_SUB_PLAN;

    TSmallintField     * FDQuery1CLOCK_PLAN_ALL;
    TSmallintField     * FDQuery1N_FAC;
    TSmallintField     * FDQuery1N_VEDOMOST;
    TSmallintField     * FDQuery1SEMESTR_VED;
    TSmallintField     * FDQuery1STATUS;
    TSmallintField     * FDQuery1VID_EDU_PLAN;
    TSmallintField     * FDQuery1YEAR_PLAN;
    TSmallintField     * FDQuery1ZACH_EXAM;
    TSmallintField     * FDQuery3CLOCK_PLAN_ALL;
    TSmallintField     * FDQuery3N_FAC;
    TSmallintField     * FDQuery3N_VEDOMOST;
    TSmallintField     * FDQuery3SEMESTR_VED;
    TSmallintField     * FDQuery3STATUS;
    TSmallintField     * FDQuery3VID_EDU_PLAN;
    TSmallintField     * FDQuery3YEAR_PLAN;
    TSmallintField     * FDQuery3ZACH_EXAM;

    TSQLTimeStampField * FDQuery1D_VED;
    TSQLTimeStampField * FDQuery1END_D_EXAM;
    TSQLTimeStampField * FDQuery3D_VED;
    TSQLTimeStampField * FDQuery3END_D_EXAM;

    TStringField       * FDQuery1DEAN;
    TStringField       * FDQuery1FAC1;
    TStringField       * FDQuery1FAM;
    TStringField       * FDQuery1FIO_EXAM;
    TStringField       * FDQuery1N_GROUP;
    TStringField       * FDQuery1N_ZACHET;
    TStringField       * FDQuery1NAME_OBJECT;
    TStringField       * FDQuery1NAME;
    TStringField       * FDQuery1OTCH;
    TStringField       * FDQuery3DEAN;
    TStringField       * FDQuery3FAC1;
    TStringField       * FDQuery3FAM;
    TStringField       * FDQuery3FIO_EXAM;
    TStringField       * FDQuery3N_GROUP;
    TStringField       * FDQuery3N_ZACHET;
    TStringField       * FDQuery3NAME_OBJECT_1;
    TStringField       * FDQuery3NAME_OBJECT_2;
    TStringField       * FDQuery3NAME_OBJECT;
    TStringField       * FDQuery3NAME;
    TStringField       * FDQuery3OTCH;


    void __fastcall FormClose (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TVed_ReportForm (TComponent * Owner);
};

extern PACKAGE TVed_ReportForm * Ved_ReportForm;

#endif  // VED_REPORT_UNIT_H
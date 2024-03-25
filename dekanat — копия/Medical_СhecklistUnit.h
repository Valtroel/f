#pragma once
#ifndef MEDICAL_ÑHECKLIST_UNIT_H
#define MEDICAL_ÑHECKLIST_UNIT_H


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
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>


class TMedical_Checklist_Form
    : public TForm
{
__published:
    TBlobField         * FDQuery1PHOTO;

    TButton            * Button1;

    TDataSource        * DataSource1;
    TDataSource        * DataSource2;

    TDBLookupListBox   * DBLookupListBox1;

    TFDQuery           * FDQuery1;
    TFDQuery           * FDQuery2;

    TIntegerField      * FDQuery1NOMER;

    TSmallintField     * FDQuery2INC_GROUP;

    TSQLTimeStampField * FDQuery1DATA_R;

    TStringField       * FDQuery1ADDRESS;
    TStringField       * FDQuery1FAC1;
    TStringField       * FDQuery1FAM;
    TStringField       * FDQuery1N_GROUP;
    TStringField       * FDQuery1NAME_EDUC;
    TStringField       * FDQuery1NAME;
    TStringField       * FDQuery1OTCH;
    TStringField       * FDQuery1PHONE;
    TStringField       * FDQuery1POL;
    TStringField       * FDQuery1TEXT_SPORT_CATEGORY;
    TStringField       * FDQuery1VID_SPORT;
    TStringField       * FDQuery2N_GROUP;


    void __fastcall Button1Click (TObject * Sender);
    void __fastcall FormCreate   (TObject * Sender);
private:
public:
    __fastcall TMedical_Checklist_Form (TComponent * Owner);
};

extern PACKAGE TMedical_Checklist_Form * Medical_Checklist_Form;

#endif  // MEDICAL_ÑHECKLIST_UNIT_H
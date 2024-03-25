#pragma once
#ifndef DM4_UNIT_H
#define DM4_UNIT_H


#include <Classes.hpp>
#include <Controls.hpp>
#include <DB.hpp>
// #include <DBTables.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.FB.hpp>
#include <FireDAC.Phys.FBDef.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.IBBase.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <Forms.hpp>
#include <StdCtrls.hpp>


class TDM4
    : public TDataModule
{
__published:
    TBlobField         * FDTable1PHOTO;
    TBlobField         * FDTable1SIGNATURE;

    TDataSource        * DataSource1;

    TFDConnection      * FDConnectionCards_TR;
    TFDConnection      * FDConnectionCards;

    TFDQuery           * TrPasportQ;
    TFDQuery           * TrPersQ;
    TFDQuery           * TrStudQ_Count;
    TFDQuery           * TrStudQ;
    TFDQuery           * VidEduQ;

    TFDStoredProc      * FDStoredProcPhotos;

    TFDTable           * FDTable1;

    TFDUpdateSQL       * TrStudUp;

    TIntegerField      * FDTable1IDDATABASES;
    TIntegerField      * FDTable1IDPERSON;
    TIntegerField      * FDTable1IDPHOTOS;
    TIntegerField      * TrPasportQROWGUID;
    TIntegerField      * TrPersQROWGUID;
    TIntegerField      * TrStudQACTIVE_STUDENT;
    TIntegerField      * TrStudQADD_YEAR;
    TIntegerField      * TrStudQDEKAN;
    TIntegerField      * TrStudQID_FAC;
    TIntegerField      * TrStudQID_KURS;
    TIntegerField      * TrStudQID_SPEC;
    TIntegerField      * TrStudQID_STUD_TYPE;
    TIntegerField      * TrStudQID_VID_EDU;
    TIntegerField      * TrStudQID_VUZ;
    TIntegerField      * TrStudQPOL;
    TIntegerField      * TrStudQROWGUID_1;
    TIntegerField      * TrStudQROWGUID_2;
    TIntegerField      * TrStudQROWGUID;

    TLargeintField     * TrStudQ_CountCOUNT;

    TSQLTimeStampField * FDTable1CREATEDATE;
    TSQLTimeStampField * FDTable1EDITDATE;
    TSQLTimeStampField * TrStudQDATE_END;
    TSQLTimeStampField * TrStudQDATE_ZACH;

    TStringField       * FDTable1CREATEUSER;
    TStringField       * FDTable1EDITUSER;
    TStringField       * TrPasportQNUMBER;
    TStringField       * TrPasportQPASPORT;
    TStringField       * TrPasportQPERSONAL_NUMBER;
    TStringField       * TrPasportQSERIES;
    TStringField       * TrPersQE_MAIL;
    TStringField       * TrPersQLOGIN;
    TStringField       * TrStudQCITYZENSHIP;
    TStringField       * TrStudQE_MAIL;
    TStringField       * TrStudQFAM_TR;
    TStringField       * TrStudQLOGIN;
    TStringField       * TrStudQN_GROUP;
    TStringField       * TrStudQNAME_TR;
    TStringField       * TrStudQNOM_Z;
    TStringField       * TrStudQNUMBER;
    TStringField       * TrStudQOTCH_TR;
    TStringField       * TrStudQPASPORT;
    TStringField       * TrStudQPERSONAL_NUMBER;
    TStringField       * TrStudQSERIES;
    TStringField       * TrStudQUCH_YEAR;
private:
public:
    __fastcall TDM4 (TComponent * Owner);
};

extern PACKAGE TDM4 * DM4;

#endif  // DM4_UNIT_H
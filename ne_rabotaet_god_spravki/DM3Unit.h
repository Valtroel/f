#pragma once
#ifndef DM3_UNIT_H
#define DM3_UNIT_H


#include <Classes.hpp>
#include <Controls.hpp>
#include <Db.hpp>
#include <DB.hpp>
// #include <DBTables.hpp>
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
// #include "RXCtrls.hpp"
#include <StdCtrls.hpp>
#include <Vcl.CheckLst.hpp>


extern AnsiString SQL_rem;


class TDM3
    : public TDataModule
{
__published:
    TBlobField         * People_SvodReportFDQueryPHOTO;
    TBlobField         * Prikaz_DopuskPeopleFDQueryPHOTO;
    TBlobField         * StatusUpdateFDQueryPHOTO;

    TDataSource        * DataSource1;
    TDataSource        * DiplomPeopleSource;
    TDataSource        * DSEditDiplom;
    TDataSource        * DSVipuskniki;
    TDataSource        * GEKResultSource;
    TDataSource        * Group_VipuskDataSource;
    TDataSource        * Min_OrgDataSource;
    TDataSource        * Predmet_GEKSource;
    TDataSource        * QUALIFICSource;
    TDataSource        * QUALIFICSource2;
    TDataSource        * Raspred_StateGridDataSource;
    TDataSource        * Svod_Nado_toExcelSource;
    TDataSource        * Svod_NadoSource;
    TDataSource        * Ved_GEKSource;

    TFDQuery           * Count_Svod_NadoFDQuery;
    TFDQuery           * Count_VipuskFDQuery;
    TFDQuery           * Count_VipuskFDQuery2;
    TFDQuery           * CountVipuskGroupFDQuery;
    TFDQuery           * Delete_IncrementFDQuery;
    TFDQuery           * Detail_Svod_NadoFDQuery;
    TFDQuery           * Detail_Svod_RealFDQuery;
    TFDQuery           * DiplomFDQuery;
    TFDQuery           * DiplomREG_estFDQuery;
    TFDQuery           * EditDiplomFDQuery;
    TFDQuery           * FDQuery1;
    TFDQuery           * FDQuery2;
    TFDQuery           * FDQuery3;
    TFDQuery           * GEK_PeopleFDQuery;
    TFDQuery           * GEK_VEDResultFDQuery;
    TFDQuery           * GEK_VipiskaFDQuery;
    TFDQuery           * GEKResultGridFDQuery;
    TFDQuery           * Group_VipuskFDQuery;
    TFDQuery           * MaxRegFDQuery;
    TFDQuery           * Min_OrgFDQuery;
    TFDQuery           * Name_PredmetFDQuery;
    TFDQuery           * Name_SpecFDQuery;
    TFDQuery           * People_SvodFDQuery;
    TFDQuery           * People_SvodReport_SpecFDQuery;
    TFDQuery           * People_SvodReportFDQuery;
    TFDQuery           * PeopleDiplomFDQuery;
    TFDQuery           * Perevod_VUZFDQuery;
    TFDQuery           * Predmet_GEKFDQuery;
    TFDQuery           * PredmetFDQuery;
    TFDQuery           * Prikaz_DopuskPeopleFDQuery;
    TFDQuery           * Proverka_VED_GEKPeopleFDQuery;
    TFDQuery           * QUALIFICFDQuery;
    TFDQuery           * QUALIFICFDQuery2;
    TFDQuery           * Raspred_StateGridFDQuery;
    TFDQuery           * Spisok_CKFDQuery;
    TFDQuery           * Spisok_raspFDQuery;
    TFDQuery           * Spisok_sportFDQuery;
    TFDQuery           * SportFDQuery;
    TFDQuery           * StatusUpdateFDQuery;
    TFDQuery           * Svod_Nado_toExcelFDQuery;
    TFDQuery           * Svod_NadoFDQuery;
    TFDQuery           * VED_GEKGridFDQuery;
    TFDQuery           * VED_GEKPeople_oldFDQuery;
    TFDQuery           * VED_GEKPeopleFDQuery;
    TFDQuery           * VED_GEKPrintFDQuery;
    TFDQuery           * VipuskFDQuery;
    TFDQuery           * VipusknikiFDQuery;
    TFDQuery           * Vosstanovlenie_VUZFDQuery;

    TFDStoredProc      * GET_N_VedGEKFDStoredProc;

    TFDUpdateSQL       * Delete_IncrementFDUpdateSQL;
    TFDUpdateSQL       * DIPLOMAFDUpdateSQL;
    TFDUpdateSQL       * FDUpdateSQLEditDiplom;
    TFDUpdateSQL       * FDUpdateSQLGEK;
    TFDUpdateSQL       * StatisFDUpdateSQL;
    TFDUpdateSQL       * VipuskFDUpdateSQL;

    TFloatField        * Detail_Svod_NadoFDQueryCLOCK_PLAN;
    TFloatField        * Detail_Svod_RealFDQueryCLOCK_PLAN;
    TFloatField        * People_SvodReportFDQueryMIDDLE_B;
    TFloatField        * PredmetFDQueryCLOCK_PLAN;
    TFloatField        * Prikaz_DopuskPeopleFDQueryMIDDLE_B;
    TFloatField        * StatusUpdateFDQueryMIDDLE_B;
    TFloatField        * Svod_Nado_toExcelFDQueryCLOCK_PLAN;
    TFloatField        * Svod_NadoFDQueryCLOCK_PLAN;

    TIntegerField      * Delete_IncrementFDQueryGOD;
    TIntegerField      * Detail_Svod_NadoFDQueryN_PLAN;
    TIntegerField      * Detail_Svod_RealFDQueryN_PLAN;
    TIntegerField      * Detail_Svod_RealFDQueryNOMER;
    TIntegerField      * DiplomFDQueryNOMER;
    TIntegerField      * DiplomREG_estFDQueryNOMER;
    TIntegerField      * EditDiplomFDQueryNOMER;
    TIntegerField      * GEK_PeopleFDQueryNOMER_GEK;
    TIntegerField      * GEK_PeopleFDQueryNOMER;
    TIntegerField      * GEK_VEDResultFDQueryN_PLAN;
    TIntegerField      * GEK_VEDResultFDQueryN_VED;
    TIntegerField      * GEK_VipiskaFDQueryN_PLAN;
    TIntegerField      * GEK_VipiskaFDQueryNOMER_GEK;
    TIntegerField      * GEK_VipiskaFDQueryNOMER;
    TIntegerField      * GEKResultGridFDQueryNOMER;
    TIntegerField      * Min_OrgFDQueryID;
    TIntegerField      * People_SvodFDQueryNOMER;
    TIntegerField      * People_SvodReport_SpecFDQueryGOD;
    TIntegerField      * People_SvodReport_SpecFDQueryNOMER;
    TIntegerField      * People_SvodReportFDQueryGOD;
    TIntegerField      * People_SvodReportFDQueryNOMER;
    TIntegerField      * People_SvodReportFDQuerySTATUS_KURS;
    TIntegerField      * PeopleDiplomFDQueryNOMER;
    TIntegerField      * Perevod_VUZFDQueryNOMER;
    TIntegerField      * Predmet_GEKFDQueryN_PLAN;
    TIntegerField      * PredmetFDQueryN_PLAN;
    TIntegerField      * Prikaz_DopuskPeopleFDQueryNOMER;
    TIntegerField      * Prikaz_DopuskPeopleFDQuerySTATUS_KURS;
    TIntegerField      * Proverka_VED_GEKPeopleFDQueryN_PLAN;
    TIntegerField      * Proverka_VED_GEKPeopleFDQueryN_VED;
    TIntegerField      * Proverka_VED_GEKPeopleFDQueryNOMER;
    TIntegerField      * Raspred_StateGridFDQueryCOUNT_SPEC;
    TIntegerField      * Raspred_StateGridFDQueryID_MIN_ORG_LETTER;
    TIntegerField      * Raspred_StateGridFDQueryID;
    TIntegerField      * Raspred_StateGridFDQueryN_CENTRE;
    TIntegerField      * Raspred_StateGridFDQueryNOMER_STUD;
    TIntegerField      * Raspred_StateGridFDQueryUCH_GOD;
    TIntegerField      * Spisok_CKFDQueryCUSTOMER;
    TIntegerField      * Spisok_CKFDQueryN_SPECIALIZ;
    TIntegerField      * Spisok_CKFDQueryNOMER;
    TIntegerField      * Spisok_raspFDQueryNOMER;
    TIntegerField      * Spisok_sportFDQueryNOMER;
    TIntegerField      * SportFDQueryNOMER;
    TIntegerField      * StatusUpdateFDQueryNOMER;
    TIntegerField      * StatusUpdateFDQuerySTATUS_KURS;
    TIntegerField      * Svod_NadoFDQueryN_PLAN;
    TIntegerField      * VED_GEKGridFDQueryN_PLAN;
    TIntegerField      * VED_GEKGridFDQueryN_VED;
    TIntegerField      * VED_GEKPeopleFDQueryNOMER;
    TIntegerField      * VED_GEKPrintFDQueryN_PLAN;
    TIntegerField      * VED_GEKPrintFDQueryNOMER_GEK;
    TIntegerField      * VED_GEKPrintFDQueryNOMER;
    TIntegerField      * VipuskFDQueryNOMER;
    TIntegerField      * VipusknikiFDQueryNOMER;
    TIntegerField      * Vosstanovlenie_VUZFDQueryNOMER;

    TLargeintField     * Count_Svod_NadoFDQueryCOUNT;
    TLargeintField     * Count_VipuskFDQuery2COUNT;
    TLargeintField     * Count_VipuskFDQueryCOUNT;
    TLargeintField     * CountVipuskGroupFDQueryCOUNT;

    TSingleField       * People_SvodReportFDQuerySCHOLARSHIP;
    TSingleField       * Prikaz_DopuskPeopleFDQuerySCHOLARSHIP;
    TSingleField       * StatusUpdateFDQuerySCHOLARSHIP;

    TSmallintField     * CountVipuskGroupFDQueryINC_GROUP;
    TSmallintField     * Delete_IncrementFDQueryINC_GROUP;
    TSmallintField     * Delete_IncrementFDQueryVID_EDU;
    TSmallintField     * Detail_Svod_NadoFDQueryCLOCK_PLAN_ALL;
    TSmallintField     * Detail_Svod_NadoFDQueryN_FAC;
    TSmallintField     * Detail_Svod_NadoFDQueryN_OBJECT;
    TSmallintField     * Detail_Svod_NadoFDQuerySEMESTR;
    TSmallintField     * Detail_Svod_NadoFDQueryVID_EDU_PLAN;
    TSmallintField     * Detail_Svod_NadoFDQueryYEAR_PLAN;
    TSmallintField     * Detail_Svod_NadoFDQueryZACH_EXAM;
    TSmallintField     * Detail_Svod_RealFDQueryCLOCK_PLAN_ALL;
    TSmallintField     * Detail_Svod_RealFDQueryN_FAC;
    TSmallintField     * Detail_Svod_RealFDQueryN_OBJECT;
    TSmallintField     * Detail_Svod_RealFDQueryRESULT;
    TSmallintField     * Detail_Svod_RealFDQuerySEMESTR;
    TSmallintField     * Detail_Svod_RealFDQuerySPECKURS;
    TSmallintField     * Detail_Svod_RealFDQuerySTATUS_PEOPLE;
    TSmallintField     * Detail_Svod_RealFDQuerySTATUS_RESULT;
    TSmallintField     * Detail_Svod_RealFDQueryVID_EDU_PLAN;
    TSmallintField     * Detail_Svod_RealFDQueryYEAR_PLAN;
    TSmallintField     * Detail_Svod_RealFDQueryZACH_EXAM;
    TSmallintField     * DiplomFDQueryN_PROTOKOL;
    TSmallintField     * DiplomFDQueryN_RASPRED_WORK;
    TSmallintField     * DiplomFDQueryTYPE_DIPLOM;
    TSmallintField     * DiplomFDQueryUROVEN;
    TSmallintField     * DiplomREG_estFDQueryN_FAC;
    TSmallintField     * DiplomREG_estFDQueryN_PROTOKOL;
    TSmallintField     * DiplomREG_estFDQueryN_PUBLIC_PRIKAZ;
    TSmallintField     * DiplomREG_estFDQueryN_SPEC;
    TSmallintField     * DiplomREG_estFDQueryN_SPECIALIZ;
    TSmallintField     * DiplomREG_estFDQueryTYPE_DIPLOM;
    TSmallintField     * DiplomREG_estFDQueryVID_EDU;
    TSmallintField     * EditDiplomFDQueryN_PROTOKOL;
    TSmallintField     * EditDiplomFDQueryN_RASPRED_WORK;
    TSmallintField     * EditDiplomFDQueryTYPE_DIPLOM;
    TSmallintField     * EditDiplomFDQueryUROVEN;
    TSmallintField     * FDQuery2RESULT;
    TSmallintField     * FDQuery3RESULT;
    TSmallintField     * FDQuery3SEMESTR;
    TSmallintField     * FDQuery3ZACH_EXAM;
    TSmallintField     * GEK_PeopleFDQueryBALL_GEK;
    TSmallintField     * GEK_PeopleFDQueryN_VED;
    TSmallintField     * GEK_VEDResultFDQueryN_FAC;
    TSmallintField     * GEK_VEDResultFDQueryN_VEDOMOST;
    TSmallintField     * GEK_VEDResultFDQueryVID_EDU_PLAN;
    TSmallintField     * GEK_VEDResultFDQueryYEAR_PLAN;
    TSmallintField     * GEK_VEDResultFDQueryZACH_EXAM;
    TSmallintField     * GEK_VipiskaFDQueryBALL_GEK;
    TSmallintField     * GEK_VipiskaFDQueryN_OBJECT;
    TSmallintField     * GEK_VipiskaFDQueryN_PROTOCOL;
    TSmallintField     * GEK_VipiskaFDQueryN_VED;
    TSmallintField     * GEKResultGridFDQueryBALL_GEK;
    TSmallintField     * GEKResultGridFDQueryN_PROTOCOL;
    TSmallintField     * GEKResultGridFDQueryN_VED;
    TSmallintField     * Group_VipuskFDQueryINC_GROUP;
    TSmallintField     * Group_VipuskFDQueryVID_EDU;
    TSmallintField     * Name_PredmetFDQueryALL_CLOCK_PLAN;
    TSmallintField     * Name_PredmetFDQueryN_OBJECT;
    TSmallintField     * Name_SpecFDQueryN_SPECIALIZ;
    TSmallintField     * People_SvodFDQueryINC_GROUP;
    TSmallintField     * People_SvodFDQueryKURS;
    TSmallintField     * People_SvodFDQueryN_FAC;
    TSmallintField     * People_SvodFDQueryN_FOUND_INCLUDE;
    TSmallintField     * People_SvodFDQueryN_FOUND;
    TSmallintField     * People_SvodFDQueryN_PRIKAZ_INCLUDE;
    TSmallintField     * People_SvodFDQueryN_PRIKAZ_KURS;
    TSmallintField     * People_SvodFDQueryN_SPEC;
    TSmallintField     * People_SvodFDQueryN_SPECIALIZ;
    TSmallintField     * People_SvodFDQuerySTATUS_PEOPLE;
    TSmallintField     * People_SvodFDQueryVID_EDU;
    TSmallintField     * People_SvodReport_SpecFDQueryINC_GROUP;
    TSmallintField     * People_SvodReport_SpecFDQueryKURS;
    TSmallintField     * People_SvodReport_SpecFDQueryN_FAC;
    TSmallintField     * People_SvodReport_SpecFDQueryN_PRIKAZ_KURS;
    TSmallintField     * People_SvodReport_SpecFDQueryN_SPEC;
    TSmallintField     * People_SvodReport_SpecFDQueryN_SPECIALIZ;
    TSmallintField     * People_SvodReport_SpecFDQuerySTATUS_PEOPLE;
    TSmallintField     * People_SvodReport_SpecFDQueryVID_EDU_1;
    TSmallintField     * People_SvodReport_SpecFDQueryVID_EDU;
    TSmallintField     * People_SvodReportFDQueryARMY;
    TSmallintField     * People_SvodReportFDQueryEDUCATION;
    TSmallintField     * People_SvodReportFDQueryHOSTEL;
    TSmallintField     * People_SvodReportFDQueryINC_GROUP;
    TSmallintField     * People_SvodReportFDQueryKURS;
    TSmallintField     * People_SvodReportFDQueryMARIAGE;
    TSmallintField     * People_SvodReportFDQueryN_CHILD;
    TSmallintField     * People_SvodReportFDQueryN_DELA;
    TSmallintField     * People_SvodReportFDQueryN_FAC;
    TSmallintField     * People_SvodReportFDQueryN_FOUND;
    TSmallintField     * People_SvodReportFDQueryN_PRIKAZ_INCLUDE;
    TSmallintField     * People_SvodReportFDQueryN_PRIKAZ_KURS;
    TSmallintField     * People_SvodReportFDQueryN_SPEC;
    TSmallintField     * People_SvodReportFDQueryN_SPECIALIZ;
    TSmallintField     * People_SvodReportFDQueryN_VID_SPORT;
    TSmallintField     * People_SvodReportFDQuerySTATUS_PEOPLE;
    TSmallintField     * People_SvodReportFDQueryVID_EDU;
    TSmallintField     * People_SvodReportFDQueryWHEN_EDUC;
    TSmallintField     * PeopleDiplomFDQueryINC_GROUP;
    TSmallintField     * PeopleDiplomFDQueryN_FAC;
    TSmallintField     * PeopleDiplomFDQueryVID_EDU;
    TSmallintField     * Perevod_VUZFDQueryN_PUBLIC_PRIKAZ;
    TSmallintField     * Perevod_VUZFDQueryN_TYPE;
    TSmallintField     * Predmet_GEKFDQueryN_FAC;
    TSmallintField     * Predmet_GEKFDQueryN_OBJECT;
    TSmallintField     * Predmet_GEKFDQuerySEMESTR;
    TSmallintField     * Predmet_GEKFDQueryVID_EDU_PLAN;
    TSmallintField     * Predmet_GEKFDQueryYEAR_PLAN;
    TSmallintField     * Predmet_GEKFDQueryZACH_EXAM;
    TSmallintField     * PredmetFDQueryALL_CLOCK_PLAN;
    TSmallintField     * PredmetFDQueryN_FAC;
    TSmallintField     * PredmetFDQueryN_OBJECT;
    TSmallintField     * PredmetFDQuerySEMESTR;
    TSmallintField     * PredmetFDQuerySPECKURS;
    TSmallintField     * PredmetFDQuerySTATUS_CONTROL;
    TSmallintField     * PredmetFDQueryVID_EDU_PLAN;
    TSmallintField     * PredmetFDQueryYEAR_PLAN;
    TSmallintField     * PredmetFDQueryZACH_EXAM;
    TSmallintField     * Prikaz_DopuskPeopleFDQueryARMY;
    TSmallintField     * Prikaz_DopuskPeopleFDQueryEDUCATION;
    TSmallintField     * Prikaz_DopuskPeopleFDQueryHOSTEL;
    TSmallintField     * Prikaz_DopuskPeopleFDQueryINC_GROUP;
    TSmallintField     * Prikaz_DopuskPeopleFDQueryKURS;
    TSmallintField     * Prikaz_DopuskPeopleFDQueryMARIAGE;
    TSmallintField     * Prikaz_DopuskPeopleFDQueryN_CHILD;
    TSmallintField     * Prikaz_DopuskPeopleFDQueryN_DELA;
    TSmallintField     * Prikaz_DopuskPeopleFDQueryN_FAC;
    TSmallintField     * Prikaz_DopuskPeopleFDQueryN_FOUND;
    TSmallintField     * Prikaz_DopuskPeopleFDQueryN_PRIKAZ_INCLUDE;
    TSmallintField     * Prikaz_DopuskPeopleFDQueryN_PRIKAZ_KURS;
    TSmallintField     * Prikaz_DopuskPeopleFDQueryN_SPEC;
    TSmallintField     * Prikaz_DopuskPeopleFDQueryN_SPECIALIZ;
    TSmallintField     * Prikaz_DopuskPeopleFDQueryN_VID_SPORT;
    TSmallintField     * Prikaz_DopuskPeopleFDQuerySTATUS_PEOPLE;
    TSmallintField     * Prikaz_DopuskPeopleFDQueryVID_EDU;
    TSmallintField     * Prikaz_DopuskPeopleFDQueryWHEN_EDUC;
    TSmallintField     * Proverka_VED_GEKPeopleFDQueryBALL_GEK;
    TSmallintField     * Proverka_VED_GEKPeopleFDQueryN_FAC;
    TSmallintField     * Proverka_VED_GEKPeopleFDQueryN_SPECIALIZ;
    TSmallintField     * Proverka_VED_GEKPeopleFDQueryN_VEDOMOST;
    TSmallintField     * QUALIFICFDQuery2NOMER_QU;
    TSmallintField     * QUALIFICFDQueryNOMER_QU;
    TSmallintField     * Raspred_StateGridFDQueryFLAT;
    TSmallintField     * Raspred_StateGridFDQueryN_FAC;
    TSmallintField     * Spisok_CKFDQuerySTATUS_CK;
    TSmallintField     * Spisok_raspFDQueryINC_GROUP;
    TSmallintField     * Spisok_raspFDQueryKURS;
    TSmallintField     * Spisok_raspFDQueryMARIAGE;
    TSmallintField     * Spisok_raspFDQueryN_CHILD;
    TSmallintField     * Spisok_raspFDQueryN_FAC;
    TSmallintField     * Spisok_raspFDQueryN_FOUND;
    TSmallintField     * Spisok_raspFDQueryN_SPEC;
    TSmallintField     * Spisok_raspFDQueryN_SPECIALIZ;
    TSmallintField     * Spisok_raspFDQueryN_VID_SPORT;
    TSmallintField     * Spisok_raspFDQuerySTATUS_PEOPLE;
    TSmallintField     * Spisok_raspFDQueryVID_EDU;
    TSmallintField     * SportFDQuerySPORT_CATEGORY;
    TSmallintField     * StatusUpdateFDQueryARMY;
    TSmallintField     * StatusUpdateFDQueryEDUCATION;
    TSmallintField     * StatusUpdateFDQueryHOSTEL;
    TSmallintField     * StatusUpdateFDQueryINC_GROUP;
    TSmallintField     * StatusUpdateFDQueryKURS;
    TSmallintField     * StatusUpdateFDQueryMARIAGE;
    TSmallintField     * StatusUpdateFDQueryN_CHILD;
    TSmallintField     * StatusUpdateFDQueryN_DELA;
    TSmallintField     * StatusUpdateFDQueryN_FAC;
    TSmallintField     * StatusUpdateFDQueryN_FOUND;
    TSmallintField     * StatusUpdateFDQueryN_PRIKAZ_INCLUDE;
    TSmallintField     * StatusUpdateFDQueryN_PRIKAZ_KURS;
    TSmallintField     * StatusUpdateFDQueryN_SPEC;
    TSmallintField     * StatusUpdateFDQueryN_SPECIALIZ;
    TSmallintField     * StatusUpdateFDQueryN_VID_SPORT;
    TSmallintField     * StatusUpdateFDQuerySTATUS_PEOPLE;
    TSmallintField     * StatusUpdateFDQueryVID_EDU;
    TSmallintField     * StatusUpdateFDQueryWHEN_EDUC;
    TSmallintField     * Svod_Nado_toExcelFDQueryCLOCK_PLAN_ALL;
    TSmallintField     * Svod_Nado_toExcelFDQuerySEMESTR;
    TSmallintField     * Svod_Nado_toExcelFDQueryYEAR_PLAN;
    TSmallintField     * Svod_Nado_toExcelFDQueryZACH_EXAM;
    TSmallintField     * Svod_NadoFDQueryCLOCK_PLAN_ALL;
    TSmallintField     * Svod_NadoFDQueryN_FAC;
    TSmallintField     * Svod_NadoFDQueryN_OBJECT;
    TSmallintField     * Svod_NadoFDQuerySEMESTR;
    TSmallintField     * Svod_NadoFDQuerySPECKURS;
    TSmallintField     * Svod_NadoFDQueryVID_EDU_PLAN;
    TSmallintField     * Svod_NadoFDQueryYEAR_PLAN;
    TSmallintField     * Svod_NadoFDQueryZACH_EXAM;
    TSmallintField     * VED_GEKGridFDQueryN_FAC;
    TSmallintField     * VED_GEKGridFDQueryN_OBJECT;
    TSmallintField     * VED_GEKGridFDQueryN_VEDOMOST;
    TSmallintField     * VED_GEKGridFDQueryVID_EDU_PLAN;
    TSmallintField     * VED_GEKPeopleFDQueryINC_GROUP;
    TSmallintField     * VED_GEKPeopleFDQueryKURS;
    TSmallintField     * VED_GEKPeopleFDQueryN_FAC;
    TSmallintField     * VED_GEKPeopleFDQueryN_PRIKAZ_KURS;
    TSmallintField     * VED_GEKPeopleFDQueryN_SPEC;
    TSmallintField     * VED_GEKPeopleFDQueryN_SPECIALIZ;
    TSmallintField     * VED_GEKPeopleFDQuerySTATUS_PEOPLE;
    TSmallintField     * VED_GEKPeopleFDQueryVID_EDU;
    TSmallintField     * VED_GEKPrintFDQueryBALL_GEK;
    TSmallintField     * VED_GEKPrintFDQueryN_FAC;
    TSmallintField     * VED_GEKPrintFDQueryN_OBJECT;
    TSmallintField     * VED_GEKPrintFDQueryN_SPECIALIZ;
    TSmallintField     * VED_GEKPrintFDQueryN_VED;
    TSmallintField     * VED_GEKPrintFDQueryN_VEDOMOST;
    TSmallintField     * VED_GEKPrintFDQuerySTATUS_PEOPLE;
    TSmallintField     * VED_GEKPrintFDQueryVID_EDU;
    TSmallintField     * VipuskFDQueryINC_GROUP;
    TSmallintField     * VipuskFDQueryKURS;
    TSmallintField     * VipuskFDQueryN_FAC;
    TSmallintField     * VipuskFDQuerySTATUS_PEOPLE;
    TSmallintField     * VipuskFDQueryVID_EDU;
    TSmallintField     * VipusknikiFDQueryN_FAC;
    TSmallintField     * VipusknikiFDQueryN_SPEC;
    TSmallintField     * VipusknikiFDQueryN_SPECIALIZ;
    TSmallintField     * VipusknikiFDQuerySTATUS_PEOPLE;
    TSmallintField     * VipusknikiFDQueryVID_EDU;
    TSmallintField     * Vosstanovlenie_VUZFDQueryN_CAUSE_RESTORE;
    TSmallintField     * Vosstanovlenie_VUZFDQueryN_PRIKAZ_RES;
    TSmallintField     * Vosstanovlenie_VUZFDQueryVID_RESTORE;

    TSQLTimeStampField * Detail_Svod_RealFDQueryDATE_RESULT;
    TSQLTimeStampField * DiplomFDQueryD_PROTOKOL;
    TSQLTimeStampField * DiplomFDQueryD_VIPUSK;
    TSQLTimeStampField * DiplomREG_estFDQueryD_PRIKAZ_INCLUDE;
    TSQLTimeStampField * DiplomREG_estFDQueryD_PRIKAZ_KURS;
    TSQLTimeStampField * DiplomREG_estFDQueryD_PROTOKOL;
    TSQLTimeStampField * DiplomREG_estFDQueryD_PUBLIC_PRIKAZ;
    TSQLTimeStampField * DiplomREG_estFDQueryD_VIPUSK;
    TSQLTimeStampField * DiplomREG_estFDQueryDATA_R;
    TSQLTimeStampField * DiplomREG_estFDQueryDATE_GIVE;
    TSQLTimeStampField * EditDiplomFDQueryD_PROTOKOL;
    TSQLTimeStampField * EditDiplomFDQueryD_VIPUSK;
    TSQLTimeStampField * GEK_PeopleFDQueryD_GEK;
    TSQLTimeStampField * GEK_VipiskaFDQueryD_GEK;
    TSQLTimeStampField * GEK_VipiskaFDQueryD_PROTOCOL;
    TSQLTimeStampField * GEKResultGridFDQueryD_GEK;
    TSQLTimeStampField * GEKResultGridFDQueryD_PROTOCOL;
    TSQLTimeStampField * People_SvodFDQueryD_PRIKAZ_INCLUDE;
    TSQLTimeStampField * People_SvodReportFDQueryD_PRIKAZ_INCLUDE;
    TSQLTimeStampField * People_SvodReportFDQueryD_PRIKAZ_KURS;
    TSQLTimeStampField * People_SvodReportFDQueryDATA_R;
    TSQLTimeStampField * Perevod_VUZFDQueryD_PUBLIC_PRIKAZ;
    TSQLTimeStampField * Prikaz_DopuskPeopleFDQueryD_PRIKAZ_INCLUDE;
    TSQLTimeStampField * Prikaz_DopuskPeopleFDQueryD_PRIKAZ_KURS;
    TSQLTimeStampField * Prikaz_DopuskPeopleFDQueryDATA_R;
    TSQLTimeStampField * Proverka_VED_GEKPeopleFDQueryD_VED;
    TSQLTimeStampField * Raspred_StateGridFDQueryD_LETTER;
    TSQLTimeStampField * Spisok_raspFDQueryDATA_R;
    TSQLTimeStampField * StatusUpdateFDQueryD_PRIKAZ_INCLUDE;
    TSQLTimeStampField * StatusUpdateFDQueryD_PRIKAZ_KURS;
    TSQLTimeStampField * StatusUpdateFDQueryDATA_R;
    TSQLTimeStampField * VED_GEKGridFDQueryD_VED;
    TSQLTimeStampField * VED_GEKPrintFDQueryD_GEK;
    TSQLTimeStampField * VED_GEKPrintFDQueryD_VED;
    TSQLTimeStampField * VipuskFDQueryD_PRIKAZ_KURS;
    TSQLTimeStampField * VipusknikiFDQueryD_PRIKAZ_INCLUDE;
    TSQLTimeStampField * VipusknikiFDQueryD_PRIKAZ_KURS;
    TSQLTimeStampField * Vosstanovlenie_VUZFDQueryD_PRIKAZ_RES;

    TStringField       * CountVipuskGroupFDQueryN_GROUP;
    TStringField       * Delete_IncrementFDQueryN_GROUP;
    TStringField       * Detail_Svod_NadoFDQueryNAME_OBJECT;
    TStringField       * Detail_Svod_RealFDQueryFAM;
    TStringField       * Detail_Svod_RealFDQueryNAME_OBJECT;
    TStringField       * Detail_Svod_RealFDQueryNAME;
    TStringField       * Detail_Svod_RealFDQueryOTCH;
    TStringField       * DiplomFDQueryDIRECTION_WORK;
    TStringField       * DiplomFDQueryN_DIPLOM;
    TStringField       * DiplomFDQueryNOM_DIPLOM;
    TStringField       * DiplomFDQueryQUALIFICATION;
    TStringField       * DiplomFDQueryREGISTRATION;
    TStringField       * DiplomFDQuerySERIA;
    TStringField       * DiplomREG_estFDQueryFAM;
    TStringField       * DiplomREG_estFDQueryN_DIPLOM;
    TStringField       * DiplomREG_estFDQueryN_ZACHET;
    TStringField       * DiplomREG_estFDQueryNAME;
    TStringField       * DiplomREG_estFDQueryNOM_DIPLOM;
    TStringField       * DiplomREG_estFDQueryNUMBER;
    TStringField       * DiplomREG_estFDQueryOTCH;
    TStringField       * DiplomREG_estFDQueryPERSONAL_NUMBER;
    TStringField       * DiplomREG_estFDQueryQUALIFICATION;
    TStringField       * DiplomREG_estFDQueryREGISTRATION;
    TStringField       * DiplomREG_estFDQuerySERIA;
    TStringField       * DiplomREG_estFDQuerySERIES;
    TStringField       * DiplomREG_estFDQueryWHO_GIVE;
    TStringField       * EditDiplomFDQueryDIRECTION_WORK;
    TStringField       * EditDiplomFDQueryN_DIPLOM;
    TStringField       * EditDiplomFDQueryNOM_DIPLOM;
    TStringField       * EditDiplomFDQueryQUALIFICATION;
    TStringField       * EditDiplomFDQueryREGISTRATION;
    TStringField       * EditDiplomFDQuerySERIA;
    TStringField       * FDQuery3NAME_OBJECT;
    TStringField       * GEK_PeopleFDQueryTHEME;
    TStringField       * GEK_VipiskaFDQueryNAME_OBJECT;
    TStringField       * GEK_VipiskaFDQueryTHEME;
    TStringField       * GEKResultGridFDQueryBALL_GEK1;
    TStringField       * GEKResultGridFDQueryFAM;
    TStringField       * GEKResultGridFDQueryNAME_OBJECT;
    TStringField       * GEKResultGridFDQueryNAME;
    TStringField       * GEKResultGridFDQueryOTCH;
    TStringField       * GEKResultGridFDQueryTHEME;
    TStringField       * Group_VipuskFDQueryN_GROUP;
    TStringField       * MaxRegFDQueryMAX;
    TStringField       * Min_OrgFDQueryDESCRIBE;
    TStringField       * Min_OrgFDQueryNAME_MIN_ORG;
    TStringField       * Name_PredmetFDQueryNAME_OBJECT;
    TStringField       * Name_SpecFDQuerySPECIAL;
    TStringField       * People_SvodFDQueryFAC;
    TStringField       * People_SvodFDQueryFAC1;
    TStringField       * People_SvodFDQueryFAM;
    TStringField       * People_SvodFDQueryN_GROUP;
    TStringField       * People_SvodFDQueryNAME;
    TStringField       * People_SvodFDQueryOTCH;
    TStringField       * People_SvodFDQueryPOL;
    TStringField       * People_SvodFDQuerySPEC;
    TStringField       * People_SvodFDQuerySPECIAL_DIRECTION;
    TStringField       * People_SvodFDQuerySPECIAL_SKLON;
    TStringField       * People_SvodFDQuerySPECIAL;
    TStringField       * People_SvodReport_SpecFDQueryFAC1;
    TStringField       * People_SvodReport_SpecFDQueryFAM;
    TStringField       * People_SvodReport_SpecFDQueryN_GROUP_1;
    TStringField       * People_SvodReport_SpecFDQueryN_GROUP;
    TStringField       * People_SvodReport_SpecFDQueryN_ZACHET;
    TStringField       * People_SvodReport_SpecFDQueryNAME;
    TStringField       * People_SvodReport_SpecFDQueryOTCH;
    TStringField       * People_SvodReport_SpecFDQuerySPECIAL_DIRECTION;
    TStringField       * People_SvodReport_SpecFDQuerySPECIAL;
    TStringField       * People_SvodReportFDQueryADDRESS;
    TStringField       * People_SvodReportFDQueryEDU_WORK;
    TStringField       * People_SvodReportFDQueryF_OLD;
    TStringField       * People_SvodReportFDQueryFAC;
    TStringField       * People_SvodReportFDQueryFAC1;
    TStringField       * People_SvodReportFDQueryFAM;
    TStringField       * People_SvodReportFDQueryN_GROUP_1;
    TStringField       * People_SvodReportFDQueryN_GROUP;
    TStringField       * People_SvodReportFDQueryN_ZACHET;
    TStringField       * People_SvodReportFDQueryNAME_EDUC;
    TStringField       * People_SvodReportFDQueryNAME;
    TStringField       * People_SvodReportFDQueryNAZ;
    TStringField       * People_SvodReportFDQueryOTCH;
    TStringField       * People_SvodReportFDQueryPHONE;
    TStringField       * People_SvodReportFDQueryPLACE_R;
    TStringField       * People_SvodReportFDQueryPOL;
    TStringField       * People_SvodReportFDQuerySPEC;
    TStringField       * People_SvodReportFDQuerySPECIAL_SKLON;
    TStringField       * People_SvodReportFDQuerySPECIAL;
    TStringField       * People_SvodReportFDQueryWHERE_EDUC;
    TStringField       * PeopleDiplomFDQueryFAM;
    TStringField       * PeopleDiplomFDQueryFIO;
    TStringField       * PeopleDiplomFDQueryN_GROUP;
    TStringField       * PeopleDiplomFDQueryNAME;
    TStringField       * PeopleDiplomFDQueryOTCH;
    TStringField       * Perevod_VUZFDQueryDESCRIBE;
    TStringField       * Predmet_GEKFDQueryNAME_OBJECT;
    TStringField       * PredmetFDQueryNAME_OBJECT;
    TStringField       * Prikaz_DopuskPeopleFDQueryADDRESS_BEFORE;
    TStringField       * Prikaz_DopuskPeopleFDQueryADDRESS_LIFE;
    TStringField       * Prikaz_DopuskPeopleFDQueryADDRESS;
    TStringField       * Prikaz_DopuskPeopleFDQueryEDU_WORK;
    TStringField       * Prikaz_DopuskPeopleFDQueryF_OLD;
    TStringField       * Prikaz_DopuskPeopleFDQueryFAM;
    TStringField       * Prikaz_DopuskPeopleFDQueryMAMA;
    TStringField       * Prikaz_DopuskPeopleFDQueryN_GROUP;
    TStringField       * Prikaz_DopuskPeopleFDQueryN_ZACHET;
    TStringField       * Prikaz_DopuskPeopleFDQueryNAME_EDUC;
    TStringField       * Prikaz_DopuskPeopleFDQueryNAME;
    TStringField       * Prikaz_DopuskPeopleFDQueryNAZ;
    TStringField       * Prikaz_DopuskPeopleFDQueryOTCH;
    TStringField       * Prikaz_DopuskPeopleFDQueryPAPA;
    TStringField       * Prikaz_DopuskPeopleFDQueryPHONE;
    TStringField       * Prikaz_DopuskPeopleFDQueryPOL;
    TStringField       * Prikaz_DopuskPeopleFDQueryWHERE_EDUC;
    TStringField       * Prikaz_DopuskPeopleFDQueryWORK_BEFORE;
    TStringField       * QUALIFICFDQuery2DESCRIBE;
    TStringField       * QUALIFICFDQuery2NAME;
    TStringField       * QUALIFICFDQueryDESCRIBE;
    TStringField       * QUALIFICFDQueryNAME;
    TStringField       * Raspred_StateGridFDQueryCENTRE;
    TStringField       * Raspred_StateGridFDQueryCUSTOMER;
    TStringField       * Raspred_StateGridFDQueryDESCRIBE;
    TStringField       * Raspred_StateGridFDQueryFIO;
    TStringField       * Raspred_StateGridFDQueryN_LETTER;
    TStringField       * Raspred_StateGridFDQueryNAME_MIN_ORG_1;
    TStringField       * Raspred_StateGridFDQueryNAME_MIN_ORG;
    TStringField       * Raspred_StateGridFDQueryORG_ADRESS;
    TStringField       * Raspred_StateGridFDQueryORG_NAME;
    TStringField       * Raspred_StateGridFDQueryORG_TEL;
    TStringField       * Raspred_StateGridFDQueryPOL;
    TStringField       * Raspred_StateGridFDQueryPOST;
    TStringField       * Raspred_StateGridFDQuerySPECIAL;
    TStringField       * Raspred_StateGridFDQuerySVOD;
    TStringField       * Raspred_StateGridFDQueryTEXT_REGION;
    TStringField       * Spisok_CKFDQueryCENTRE;
    TStringField       * Spisok_raspFDQueryADDRESS_BEFORE;
    TStringField       * Spisok_raspFDQueryADDRESS;
    TStringField       * Spisok_raspFDQueryFAM;
    TStringField       * Spisok_raspFDQueryN_GROUP;
    TStringField       * Spisok_raspFDQueryNAME;
    TStringField       * Spisok_raspFDQueryOTCH;
    TStringField       * Spisok_raspFDQueryPOL;
    TStringField       * Spisok_raspFDQuerySPECIAL_DIRECTION;
    TStringField       * Spisok_raspFDQuerySPECIAL_SKLON;
    TStringField       * Spisok_raspFDQuerySPECIAL;
    TStringField       * Spisok_sportFDQueryTEXT_SPORT_CATEGORY;
    TStringField       * Spisok_sportFDQueryVID_SPORT;
    TStringField       * SportFDQueryTEXT_SPORT_CATEGORY;
    TStringField       * StatusUpdateFDQueryADDRESS_BEFORE;
    TStringField       * StatusUpdateFDQueryADDRESS;
    TStringField       * StatusUpdateFDQueryEDU_WORK;
    TStringField       * StatusUpdateFDQueryF_OLD;
    TStringField       * StatusUpdateFDQueryFAM;
    TStringField       * StatusUpdateFDQueryMAMA;
    TStringField       * StatusUpdateFDQueryN_GROUP;
    TStringField       * StatusUpdateFDQueryN_ZACHET;
    TStringField       * StatusUpdateFDQueryNAME_EDUC;
    TStringField       * StatusUpdateFDQueryNAME;
    TStringField       * StatusUpdateFDQueryNAZ;
    TStringField       * StatusUpdateFDQueryOTCH;
    TStringField       * StatusUpdateFDQueryPAPA;
    TStringField       * StatusUpdateFDQueryPHONE;
    TStringField       * StatusUpdateFDQueryPLACE_R;
    TStringField       * StatusUpdateFDQueryPOL;
    TStringField       * StatusUpdateFDQueryWHERE_EDUC;
    TStringField       * StatusUpdateFDQueryWORK_BEFORE;
    TStringField       * StatusUpdateFDQueryWORK_MAMA;
    TStringField       * StatusUpdateFDQueryWORK_PAPA;
    TStringField       * Svod_Nado_toExcelFDQueryNAME_OBJECT;
    TStringField       * Svod_Nado_toExcelFDQueryYYEAR1;
    TStringField       * Svod_Nado_toExcelFDQueryZACH_EXAM1;
    TStringField       * Svod_NadoFDQueryNAME_OBJECT;
    TStringField       * Svod_NadoFDQueryYEAR1;
    TStringField       * Svod_NadoFDQueryZACH_EXAM1;
    TStringField       * VED_GEKGridFDQueryFIO_EXAM;
    TStringField       * VED_GEKGridFDQueryINC_GROUP;
    TStringField       * VED_GEKGridFDQueryN_GROUP_SP;
    TStringField       * VED_GEKGridFDQueryNAME_OBJECT;
    TStringField       * VED_GEKGridFDQueryVID_EDU1;
    TStringField       * VED_GEKPeopleFDQueryFAM;
    TStringField       * VED_GEKPeopleFDQueryN_GROUP;
    TStringField       * VED_GEKPeopleFDQueryN_ZACHET;
    TStringField       * VED_GEKPeopleFDQueryNAME;
    TStringField       * VED_GEKPeopleFDQueryOTCH;
    TStringField       * VED_GEKPeopleFDQuerySPECIAL;
    TStringField       * VED_GEKPrintFDQueryFAM;
    TStringField       * VED_GEKPrintFDQueryN_GROUP_SP;
    TStringField       * VED_GEKPrintFDQueryN_GROUP;
    TStringField       * VED_GEKPrintFDQueryNAME_OBJECT;
    TStringField       * VED_GEKPrintFDQueryNAME;
    TStringField       * VED_GEKPrintFDQueryOTCH;
    TStringField       * VipuskFDQueryFAM;
    TStringField       * VipuskFDQueryN_GROUP;
    TStringField       * VipuskFDQueryNAME;
    TStringField       * VipuskFDQueryOTCH;
    TStringField       * VipusknikiFDQueryDATA1;
    TStringField       * VipusknikiFDQueryFAM;
    TStringField       * VipusknikiFDQueryNAME;
    TStringField       * VipusknikiFDQueryOTCH;
    TStringField       * VipusknikiFDQuerySPEC1;
    TStringField       * VipusknikiFDQuerySPECIALIZ1;
    TStringField       * Vosstanovlenie_VUZFDQueryDESCRIBE;


    void __fastcall GEKResultGrid2CalcFields           (TDataSet * DataSet);
    void __fastcall GEKResultGridFDQueryCalcFields     (TDataSet * DataSet);
    void __fastcall Svod_Nado_toExcelFDQueryCalcFields (TDataSet * DataSet);
    void __fastcall Svod_Nado2CalcFields               (TDataSet * DataSet);
    void __fastcall Svod_NadoFDQueryCalcFields         (TDataSet * DataSet);
    void __fastcall VED_GEKGrid2CalcFields             (TDataSet * DataSet);
    void __fastcall VED_GEKGridFDQueryCalcFields       (TDataSet * DataSet);
    void __fastcall Vipuskniki2CalcFields              (TDataSet * DataSet);
    void __fastcall VipusknikiFDQueryCalcFields        (TDataSet * DataSet);
private:
public:
    __fastcall TDM3 (TComponent * Owner);


    void       __fastcall Check_Add_Group    (                                  // ������������� ������ ����� � RxCheckListBox (�� ���� �������� � �����)
            int             edu,
            int             kurs,
            TCheckListBox * ch
        );
    AnsiString            Check_Return_Group (                                  // �������� ����������� ������� ����� �� RxCheckListBox-� (�� ���� ��������)
            int             edu,
            TCheckListBox * ch
        );
};

extern PACKAGE TDM3 * DM3;

#endif  // DM3_UNIT_H
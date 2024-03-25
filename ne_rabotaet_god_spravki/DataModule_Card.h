#pragma once
#ifndef DATA_MODULE_CARD_H
#define DATA_MODULE_CARD_H


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
#include "frxClass.hpp"
#include <StdCtrls.hpp>

        
TfrxMemoView * __fastcall P_F (
        int              L,         // Left
        int              T,         // Top,
        int              W,         // Width
        int              H,         // Height (pixels) to convert in millimeters need to multiply on 5/18
        TFontStyles      Style,     // Font style (0 - normal, 1 - italic, 2 - bold, 3 - italic + bold, 4 - underscore) 
        int              Size,
        AnsiString       Name_F,
        TfrxHAlign       Halign,    // Horizontal align (1 - right, 2 - center, 3  - width)
        TfrxVAlign       Valign,    // Vertical aligh (4 - top,   8 - center, 16 - bottom)
        TfrxFrameTypes   Fram,      // Border location (0 - without, 1 - right side, 2 - bottom, 4 - left side, 8 - top) to mix you have to sum of the values (exp.: 15 - around)
        AnsiString       Tex,       // input string
        int              nom,
        TfrxReport     * frxReport,
        int              rot
    );



class TDataModule2
    : public TDataModule
{
__published:
    TBlobField         * Report_CardFDQueryPHOTO;
    TBlobField         * Report_Ut_CardFDQueryPHOTO;

    TDataSource        * Report_CardFDSource;

    TFDQuery           * QalifikationFDQuery;
    TFDQuery           * Report_CardFDQuery;
    TFDQuery           * Report_DiplomaFDQuery;
    TFDQuery           * Report_EncourageFDQuery;
    TFDQuery           * Report_Prikaz_KursFDQuery;
    TFDQuery           * Report_SportFDQuery;
    TFDQuery           * Report_Ut_Card_PlanFDQuery;
    TFDQuery           * Report_Ut_CardFDQuery;
    TFDQuery           * Report_Ut_DiplomFDQuery;
    TFDQuery           * Report_Ut_HolidayFDQuery;
    TFDQuery           * Report_Ut_Prik_Restore_OtFDQuery;
    TFDQuery           * Report_Ut_Prik_Restore_VosFDQuery;
    TFDQuery           * Report_Ut_Public_PrikazFDQuery;
    TFDQuery           * Report_Ut_VipFDQuery;

    TFloatField        * Report_CardFDQueryMIDDLE_B;
    TFloatField        * Report_Ut_Card_PlanFDQueryCLOCK_PLAN;
    TFloatField        * Report_Ut_CardFDQueryMIDDLE_B;

    TfrxReport         * frxReport1;

    TIntegerField      * Report_CardFDQueryNOMER;
    TIntegerField      * Report_CardFDQuerySTATUS_KURS;
    TIntegerField      * Report_DiplomaFDQueryNOMER;
    TIntegerField      * Report_EncourageFDQueryNOMER;
    TIntegerField      * Report_Prikaz_KursFDQueryNOMER;
    TIntegerField      * Report_SportFDQueryNOMER;
    TIntegerField      * Report_Ut_Card_PlanFDQueryN_PLAN;
    TIntegerField      * Report_Ut_Card_PlanFDQueryNOMER;
    TIntegerField      * Report_Ut_CardFDQueryNOMER;
    TIntegerField      * Report_Ut_CardFDQuerySTATUS_KURS;
    TIntegerField      * Report_Ut_DiplomFDQueryNOMER_GEK;
    TIntegerField      * Report_Ut_DiplomFDQueryNOMER;
    TIntegerField      * Report_Ut_HolidayFDQueryNOMER;
    TIntegerField      * Report_Ut_Prik_Restore_OtFDQueryNOMER;
    TIntegerField      * Report_Ut_Prik_Restore_VosFDQueryNOMER;
    TIntegerField      * Report_Ut_Public_PrikazFDQueryNOMER;
    TIntegerField      * Report_Ut_VipFDQueryNOMER;

    TSingleField       * Report_Ut_CardFDQuerySCHOLARSHIP;

    TSmallintField     * QalifikationFDQueryNOMER_QU;
    TSmallintField     * Report_CardFDQueryARMY;
    TSmallintField     * Report_CardFDQueryEDUCATION;
    TSmallintField     * Report_CardFDQueryHOSTEL;
    TSmallintField     * Report_CardFDQueryINC_GROUP;
    TSmallintField     * Report_CardFDQueryKURS;
    TSmallintField     * Report_CardFDQueryMARIAGE;
    TSmallintField     * Report_CardFDQueryN_DELA;
    TSmallintField     * Report_CardFDQueryN_FOUND_INCLUDE;
    TSmallintField     * Report_CardFDQueryN_PRIKAZ_INCLUDE;
    TSmallintField     * Report_CardFDQueryN_PRIKAZ_KURS;
    TSmallintField     * Report_CardFDQueryN_SPEC;
    TSmallintField     * Report_CardFDQuerySTATUS_PEOPLE;
    TSmallintField     * Report_CardFDQueryVID_EDU_INCLUDE;
    TSmallintField     * Report_CardFDQueryVID_EDU;
    TSmallintField     * Report_CardFDQueryWHEN_EDUC;
    TSmallintField     * Report_DiplomaFDQueryN_RASPRED_WORK;
    TSmallintField     * Report_EncourageFDQueryN_PRIKAZ;
    TSmallintField     * Report_EncourageFDQueryTYPE_EN;
    TSmallintField     * Report_Prikaz_KursFDQueryN_KURS;
    TSmallintField     * Report_Prikaz_KursFDQueryN_PRIKAZ_KURS;
    TSmallintField     * Report_Prikaz_KursFDQueryVID_EDU;
    TSmallintField     * Report_SportFDQueryN_PRIKAZ_SPORT;
    TSmallintField     * Report_SportFDQueryN_PRIKAZ_SUD;
    TSmallintField     * Report_SportFDQuerySUD_CATEGORY;
    TSmallintField     * Report_Ut_Card_PlanFDQueryCLOCK_PLAN_ALL;
    TSmallintField     * Report_Ut_Card_PlanFDQueryN_FAC;
    TSmallintField     * Report_Ut_Card_PlanFDQueryRESULT;
    TSmallintField     * Report_Ut_Card_PlanFDQuerySEMESTR;
    TSmallintField     * Report_Ut_Card_PlanFDQuerySPECKURS;
    TSmallintField     * Report_Ut_Card_PlanFDQuerySTATUS_RESULT;
    TSmallintField     * Report_Ut_Card_PlanFDQueryVID_EDU_PLAN;
    TSmallintField     * Report_Ut_Card_PlanFDQueryYEAR_PLAN;
    TSmallintField     * Report_Ut_Card_PlanFDQueryZACH_EXAM;
    TSmallintField     * Report_Ut_CardFDQueryARMY;
    TSmallintField     * Report_Ut_CardFDQueryEDUCATION;
    TSmallintField     * Report_Ut_CardFDQueryHOSTEL;
    TSmallintField     * Report_Ut_CardFDQueryINC_GROUP;
    TSmallintField     * Report_Ut_CardFDQueryKURS;
    TSmallintField     * Report_Ut_CardFDQueryMARIAGE;
    TSmallintField     * Report_Ut_CardFDQueryN_CHILD;
    TSmallintField     * Report_Ut_CardFDQueryN_DELA;
    TSmallintField     * Report_Ut_CardFDQueryN_FOUND_INCLUDE;
    TSmallintField     * Report_Ut_CardFDQueryN_FOUND;
    TSmallintField     * Report_Ut_CardFDQueryN_PRIKAZ_INCLUDE;
    TSmallintField     * Report_Ut_CardFDQueryN_PRIKAZ_KURS;
    TSmallintField     * Report_Ut_CardFDQueryN_SPEC;
    TSmallintField     * Report_Ut_CardFDQueryN_SPECIALIZ;
    TSmallintField     * Report_Ut_CardFDQueryN_VID_SPORT;
    TSmallintField     * Report_Ut_CardFDQuerySTATUS_PEOPLE;
    TSmallintField     * Report_Ut_CardFDQueryVID_EDU_INCLUDE;
    TSmallintField     * Report_Ut_CardFDQueryVID_EDU;
    TSmallintField     * Report_Ut_CardFDQueryWHEN_EDUC;
    TSmallintField     * Report_Ut_DiplomFDQueryBALL_GEK;
    TSmallintField     * Report_Ut_DiplomFDQueryN_PROTOCOL;
    TSmallintField     * Report_Ut_DiplomFDQueryN_VED;
    TSmallintField     * Report_Ut_HolidayFDQueryN_HOL;
    TSmallintField     * Report_Ut_HolidayFDQueryN_PRIKAZ_HOL;
    TSmallintField     * Report_Ut_HolidayFDQueryTYPE_HOL;
    TSmallintField     * Report_Ut_Prik_Restore_OtFDQueryN_CAUSE_RESTORE;
    TSmallintField     * Report_Ut_Prik_Restore_OtFDQueryN_PRIKAZ_RES;
    TSmallintField     * Report_Ut_Prik_Restore_OtFDQueryVID_RESTORE;
    TSmallintField     * Report_Ut_Prik_Restore_VosFDQueryN_CAUSE_RESTORE;
    TSmallintField     * Report_Ut_Prik_Restore_VosFDQueryN_PRIKAZ_RES;
    TSmallintField     * Report_Ut_Prik_Restore_VosFDQueryVID_RESTORE;
    TSmallintField     * Report_Ut_Public_PrikazFDQueryN_PUBLIC_PRIKAZ;
    TSmallintField     * Report_Ut_Public_PrikazFDQueryN_TYPE;
    TSmallintField     * Report_Ut_VipFDQueryN_PROTOKOL;
    TSmallintField     * Report_Ut_VipFDQueryN_RASPRED_WORK;

    TSQLTimeStampField * Report_CardFDQueryD_PRIKAZ_INCLUDE;
    TSQLTimeStampField * Report_CardFDQueryD_PRIKAZ_KURS;
    TSQLTimeStampField * Report_CardFDQueryDATA_R;
    TSQLTimeStampField * Report_DiplomaFDQueryD_VIPUSK;
    TSQLTimeStampField * Report_EncourageFDQueryD_PRIKAZ;
    TSQLTimeStampField * Report_Prikaz_KursFDQueryD_PRIKAZ_KURS;
    TSQLTimeStampField * Report_SportFDQueryD_PRIKAZ_SPORT;
    TSQLTimeStampField * Report_SportFDQueryD_PRIKAZ_SUD;
    TSQLTimeStampField * Report_Ut_Card_PlanFDQueryDATE_RESULT;
    TSQLTimeStampField * Report_Ut_CardFDQueryD_PRIKAZ_INCLUDE;
    TSQLTimeStampField * Report_Ut_CardFDQueryD_PRIKAZ_KURS;
    TSQLTimeStampField * Report_Ut_CardFDQueryDATA_R;
    TSQLTimeStampField * Report_Ut_DiplomFDQueryD_GEK;
    TSQLTimeStampField * Report_Ut_DiplomFDQueryD_PROTOCOL;
    TSQLTimeStampField * Report_Ut_HolidayFDQueryD_BEGIN_HOL;
    TSQLTimeStampField * Report_Ut_HolidayFDQueryD_END_HOL;
    TSQLTimeStampField * Report_Ut_HolidayFDQueryD_PRIKAZ_HOL;
    TSQLTimeStampField * Report_Ut_Prik_Restore_OtFDQueryD_PRIKAZ_RES;
    TSQLTimeStampField * Report_Ut_Prik_Restore_VosFDQueryD_PRIKAZ_RES;
    TSQLTimeStampField * Report_Ut_Public_PrikazFDQueryD_PUBLIC_PRIKAZ;
    TSQLTimeStampField * Report_Ut_VipFDQueryD_PROTOKOL;
    TSQLTimeStampField * Report_Ut_VipFDQueryD_VIPUSK;

    TStringField       * QalifikationFDQueryDESCRIBE;
    TStringField       * QalifikationFDQueryNAME;
    TStringField       * Report_CardFDQueryADDRESS_BEFORE;
    TStringField       * Report_CardFDQueryADDRESS;
    TStringField       * Report_CardFDQueryEDU_WORK;
    TStringField       * Report_CardFDQueryF_OLD;
    TStringField       * Report_CardFDQueryFAC1;
    TStringField       * Report_CardFDQueryFAM;
    TStringField       * Report_CardFDQueryMAMA;
    TStringField       * Report_CardFDQueryN_GROUP;
    TStringField       * Report_CardFDQueryN_ZACHET;
    TStringField       * Report_CardFDQueryNAME_EDUC;
    TStringField       * Report_CardFDQueryNAME;
    TStringField       * Report_CardFDQueryNAZ;
    TStringField       * Report_CardFDQueryOTCH;
    TStringField       * Report_CardFDQueryPAPA;
    TStringField       * Report_CardFDQueryPHONE;
    TStringField       * Report_CardFDQueryPLACE_R;
    TStringField       * Report_CardFDQueryPOL;
    TStringField       * Report_CardFDQuerySPEC;
    TStringField       * Report_CardFDQuerySPECIAL_DIRECTION;
    TStringField       * Report_CardFDQuerySPECIAL;
    TStringField       * Report_CardFDQueryVID_FOUND;
    TStringField       * Report_CardFDQueryVID_SPORT;
    TStringField       * Report_CardFDQueryWHERE_EDUC;
    TStringField       * Report_CardFDQueryWORK_BEFORE;
    TStringField       * Report_CardFDQueryWORK_MAMA;
    TStringField       * Report_CardFDQueryWORK_PAPA;
    TStringField       * Report_DiplomaFDQueryDIRECTION_WORK;
    TStringField       * Report_DiplomaFDQueryN_DIPLOM;
    TStringField       * Report_DiplomaFDQueryQUALIFICATION;
    TStringField       * Report_EncourageFDQueryVID_EN;
    TStringField       * Report_EncourageFDQueryWHAT;
    TStringField       * Report_EncourageFDQueryWHO_TAKE;
    TStringField       * Report_Prikaz_KursFDQueryFAC1;
    TStringField       * Report_SportFDQueryTEXT_SPORT_CATEGORY;
    TStringField       * Report_SportFDQueryVID_SPORT;
    TStringField       * Report_SportFDQueryWHO_GIVE_SUD;
    TStringField       * Report_SportFDQueryWHO_GIVE;
    TStringField       * Report_Ut_Card_PlanFDQueryFAC1;
    TStringField       * Report_Ut_Card_PlanFDQueryNAME_OBJECT;
    TStringField       * Report_Ut_CardFDQueryADDRESS_BEFORE;
    TStringField       * Report_Ut_CardFDQueryADDRESS;
    TStringField       * Report_Ut_CardFDQueryEDU_WORK;
    TStringField       * Report_Ut_CardFDQueryF_OLD;
    TStringField       * Report_Ut_CardFDQueryFAC1;
    TStringField       * Report_Ut_CardFDQueryFAM;
    TStringField       * Report_Ut_CardFDQueryMAMA;
    TStringField       * Report_Ut_CardFDQueryN_GROUP;
    TStringField       * Report_Ut_CardFDQueryN_ZACHET;
    TStringField       * Report_Ut_CardFDQueryNAME_EDUC;
    TStringField       * Report_Ut_CardFDQueryNAME;
    TStringField       * Report_Ut_CardFDQueryNAZ;
    TStringField       * Report_Ut_CardFDQueryOTCH;
    TStringField       * Report_Ut_CardFDQueryPAPA;
    TStringField       * Report_Ut_CardFDQueryPHONE;
    TStringField       * Report_Ut_CardFDQueryPOL;
    TStringField       * Report_Ut_CardFDQuerySPECIAL_DIRECTION;
    TStringField       * Report_Ut_CardFDQuerySPECIAL;
    TStringField       * Report_Ut_CardFDQueryWHERE_EDUC;
    TStringField       * Report_Ut_CardFDQueryWORK_BEFORE;
    TStringField       * Report_Ut_DiplomFDQueryNAME_OBJECT;
    TStringField       * Report_Ut_DiplomFDQueryTHEME;
    TStringField       * Report_Ut_HolidayFDQueryCAUSE_HOL;
    TStringField       * Report_Ut_Prik_Restore_OtFDQueryCAUSE_RES;
    TStringField       * Report_Ut_Prik_Restore_OtFDQueryDESCRIBE;
    TStringField       * Report_Ut_Prik_Restore_VosFDQueryCAUSE_RES;
    TStringField       * Report_Ut_Prik_Restore_VosFDQueryDESCRIBE;
    TStringField       * Report_Ut_Public_PrikazFDQueryDESCRIBE;
    TStringField       * Report_Ut_Public_PrikazFDQueryTYPE_PRIKAZ;
    TStringField       * Report_Ut_VipFDQueryDIRECTION_WORK;
    TStringField       * Report_Ut_VipFDQueryN_DIPLOM;
    TStringField       * Report_Ut_VipFDQueryQUALIFICATION;
private:
public:
    __fastcall TDataModule2 (TComponent * Owner);

    bool printdlg;
};

extern PACKAGE TDataModule2 * DataModule2;

#endif  // DATA_MODULE_CARD_H
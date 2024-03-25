#pragma once
#ifndef DM2_UNIT_H
#define DM2_UNIT_H


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
// #include <IBCustomDataSet.hpp>
// #include <IBDatabase.hpp>
// #include <IBTable.hpp>
#include <IBX.IBCustomDataSet.hpp>
#include <IBX.IBDatabase.hpp>
#include <IBX.IBTable.hpp>
// #include "RxLogin.hpp"
#include <StdCtrls.hpp>


extern int splash;


TDateTime __fastcall Date_return (                                              // Функция возвращает дату со сдвигом от текущей
        int f,
        int k
    );


class TDM2
    : public TDataModule
{
__published:
    TDataSource        * CategorySource;
    TDataSource        * Cause_HolidaySource;
    TDataSource        * Cause_PassSource;
    TDataSource        * Cause_RestoreSource;
    TDataSource        * DataSource1;
    TDataSource        * DataSourceQualification;
    TDataSource        * DSCountries_ocrb;
    TDataSource        * FacultySource;
    TDataSource        * FoundationSource;
    TDataSource        * Increment_GroupSource;
    TDataSource        * Object_PlanSource;
    TDataSource        * Prikaz_KursSource;
    TDataSource        * SpecialitySource;
    TDataSource        * SpecializSource;
    TDataSource        * Type_EncourageSource;
    TDataSource        * Type_PrikazSource;
    TDataSource        * Vid_SportSource;

    TFDTable           * CategoryFDTable;
    TFDTable           * Cause_HolidayFDTable;
    TFDTable           * Cause_PassFDTable;
    TFDTable           * Cause_RestoreFDTable;
    TFDTable           * Countries_ocrbTable;
    TFDTable           * FacultyFDTable;
    TFDTable           * FDTable1;
    TFDTable           * FoundationFDTable;
    TFDTable           * Increment_GroupFDTable;
    TFDTable           * Object_PlanFDTable;
    TFDTable           * Prikaz_KursFDTable;
    TFDTable           * QualificationFDTable;
    TFDTable           * Special_DirFDTable;
    TFDTable           * SpecialityFDTable;
    TFDTable           * SpecializFDTable;
    TFDTable           * Type_EncourageFDTable;
    TFDTable           * Type_PrikazFDTable;
    TFDTable           * Vid_SportFDTable;

    TIntegerField      * Countries_ocrbTableDIGITAL_CODE;
    TIntegerField      * Increment_GroupFDTableGOD;
    TIntegerField      * Prikaz_KursFDTableNOMER;
    TIntegerField      * Special_DirFDTableN_SPEC_DIR;
    TIntegerField      * Special_DirFDTableN_SPEC;
    TIntegerField      * SpecializFDTableN_SPEC_DIR;

    TSmallintField     * CategoryFDTableSPORT_CATEGORY;
    TSmallintField     * Cause_HolidayFDTableN_HOL;
    TSmallintField     * Cause_PassFDTableN_CAUSE;
    TSmallintField     * Cause_RestoreFDTableN_CAUSE_RESTORE;
    TSmallintField     * FacultyFDTableKOD_FAC;
    TSmallintField     * FacultyFDTableN_FAC;
    TSmallintField     * FDTable1N_FAC;
    TSmallintField     * FoundationFDTableN_FOUND;
    TSmallintField     * Increment_GroupFDTableINC_GROUP;
    TSmallintField     * Increment_GroupFDTableVID_EDU;
    TSmallintField     * Object_PlanFDTableALL_CLOCK_PLAN;
    TSmallintField     * Object_PlanFDTableINTEGR_MODUL;
    TSmallintField     * Object_PlanFDTableN_OBJECT;
    TSmallintField     * Prikaz_KursFDTableN_FAC;
    TSmallintField     * Prikaz_KursFDTableN_KURS;
    TSmallintField     * Prikaz_KursFDTableN_PRIKAZ_KURS;
    TSmallintField     * Prikaz_KursFDTableVID_EDU;
    TSmallintField     * QualificationFDTableNOMER_QU;
    TSmallintField     * SpecialityFDTableN_SPEC;
    TSmallintField     * SpecialityFDTableOLD_NUM;
    TSmallintField     * SpecializFDTableN_FAC;
    TSmallintField     * SpecializFDTableN_SPEC;
    TSmallintField     * SpecializFDTableN_SPECIALIZ;
    TSmallintField     * Type_EncourageFDTableN_TYPE_EN;
    TSmallintField     * Type_EncourageFDTableTYPE_EN;
    TSmallintField     * Type_PrikazFDTableN_TYPE;
    TSmallintField     * Vid_SportFDTableN_VID_SPORT;

    TSQLTimeStampField * Prikaz_KursFDTableD_PRIKAZ_KURS;

    TStringField       * CategoryFDTableTEXT_SPORT_CATEGORY;
    TStringField       * Cause_HolidayFDTableCAUSE_HOL;
    TStringField       * Cause_PassFDTableCAUSE;
    TStringField       * Cause_RestoreFDTableCAUSE_RES;
    TStringField       * Countries_ocrbTableFULL_NAME;
    TStringField       * Countries_ocrbTableLETTER_CODE_2;
    TStringField       * Countries_ocrbTableLETTER_CODE_3;
    TStringField       * Countries_ocrbTableSHORT_NAME;
    TStringField       * FacultyFDTableDEAN;
    TStringField       * FacultyFDTableFAC_PP;
    TStringField       * FacultyFDTableFAC_RP;
    TStringField       * FacultyFDTableFAC;
    TStringField       * FacultyFDTableFAC1;
    TStringField       * FacultyFDTableFAC2;
    TStringField       * FDTable1USER_NAME;
    TStringField       * FDTable1USER_PASSWORD;
    TStringField       * FoundationFDTableVID_FOUND;
    TStringField       * Increment_GroupFDTableN_GROUP;
    TStringField       * Object_PlanFDTableNAME_OBJECT;
    TStringField       * Object_PlanFDTableSHORT_NAME;
    TStringField       * QualificationFDTableDESCRIBE;
    TStringField       * QualificationFDTableNAME;
    TStringField       * Special_DirFDTableCODE_SPEC_DIR;
    TStringField       * Special_DirFDTableSPEC_DIR_FULL;
    TStringField       * Special_DirFDTableSPEC_DIR;
    TStringField       * SpecialityFDTableCODE_SPEC;
    TStringField       * SpecialityFDTableSPEC;
    TStringField       * SpecializFDTableCODE_SPECIALIZ;
    TStringField       * SpecializFDTableSPECIAL_DIRECTION;
    TStringField       * SpecializFDTableSPECIAL_SKLON;
    TStringField       * SpecializFDTableSPECIAL;
    TStringField       * Type_EncourageFDTableVID_EN;
    TStringField       * Type_PrikazFDTableTYPE_PRIKAZ;
    TStringField       * Vid_SportFDTableVID_SPORT;


    void __fastcall Cause_HolidayFDTableAfterOpen   (TDataSet * DataSet);
    void __fastcall Cause_HolidayFDTableNewRecord   (TDataSet * DataSet);
    void __fastcall Cause_HolidayTable2NewRecord    (TDataSet * DataSet);
    void __fastcall Cause_HolidayTable3AfterOpen    (TDataSet * DataSet);
    void __fastcall Cause_PassFDTableAfterOpen      (TDataSet * DataSet);
    void __fastcall Cause_PassFDTableNewRecord      (TDataSet * DataSet);
    void __fastcall Cause_PassTable2NewRecord       (TDataSet * DataSet);
    void __fastcall Cause_PassTable3AfterOpen       (TDataSet * DataSet);
    void __fastcall Cause_RestoreFDTableAfterOpen   (TDataSet * DataSet);
    void __fastcall Cause_RestoreFDTableNewRecord   (TDataSet * DataSet);
    void __fastcall Cause_RestoreTable2AfterOpen    (TDataSet * DataSet);
    void __fastcall Cause_RestoreTable2NewRecord    (TDataSet * DataSet);
    void __fastcall Cause_RestoreTable3AfterOpen    (TDataSet * DataSet);
    void __fastcall FacultyFDTableAfterOpen         (TDataSet * DataSet);
    void __fastcall FacultyFDTableNewRecord         (TDataSet * DataSet);
    void __fastcall FacultyTable2NewRecord          (TDataSet * DataSet);
    void __fastcall FacultyTable3AfterOpen          (TDataSet * DataSet);
    void __fastcall FDTable1AfterOpen               (TDataSet * DataSet);
    void __fastcall FoundationFDTableAfterOpen      (TDataSet * DataSet);
    void __fastcall FoundationFDTableNewRecord      (TDataSet * DataSet);
    void __fastcall FoundationTable2AfterOpen       (TDataSet * DataSet);
    void __fastcall FoundationTable2NewRecord       (TDataSet * DataSet);
    void __fastcall Increment_GroupFDTableNewRecord (TDataSet * DataSet);
    void __fastcall Increment_GroupTable2NewRecord  (TDataSet * DataSet);
    void __fastcall Object_PlanFDTableAfterOpen     (TDataSet * DataSet);
    void __fastcall Object_PlanFDTableNewRecord     (TDataSet * DataSet);
    void __fastcall Object_PlanTable2NewRecord      (TDataSet * DataSet);
    void __fastcall Object_PlanTable3AfterOpen      (TDataSet * DataSet);
    void __fastcall Prikaz_KursFDTableAfterOpen     (TDataSet * DataSet);
    void __fastcall Prikaz_KursTable3AfterOpen      (TDataSet * DataSet);
    void __fastcall RegionFDTableAfterOpen          (TDataSet * DataSet);
    // void __fastcall RxLoginDialog1CheckUser         (
    //               TObject    * Sender,
    //         const AnsiString   UserName,
    //         const AnsiString   Password,
    //               bool       & AllowLogin
    //     );
    void __fastcall Special_DirFDTableAfterOpen     (TDataSet * DataSet);
    void __fastcall Special_DirFDTableNewRecord     (TDataSet * DataSet);
    void __fastcall Special_DirTable2AfterOpen      (TDataSet * DataSet);
    void __fastcall SpecialityFDTableAfterOpen      (TDataSet * DataSet);
    void __fastcall SpecialityFDTableNewRecord      (TDataSet * DataSet);
    void __fastcall SpecialityTable2NewRecord       (TDataSet * DataSet);
    void __fastcall SpecialityTable3AfterOpen       (TDataSet * DataSet);
    void __fastcall SpecializFDTableAfterOpen       (TDataSet * DataSet);
    void __fastcall SpecializFDTableNewRecord       (TDataSet * DataSet);
    void __fastcall SpecializTable2NewRecord        (TDataSet * DataSet);
    void __fastcall SpecializTable3AfterOpen        (TDataSet * DataSet);
    void __fastcall Table13AfterOpen                (TDataSet * DataSet);
    void __fastcall Type_EncourageFDTableAfterOpen  (TDataSet * DataSet);
    void __fastcall Type_EncourageFDTableNewRecord  (TDataSet * DataSet);
    void __fastcall Type_EncourageTable2NewRecord   (TDataSet * DataSet);
    void __fastcall Type_EncourageTable3AfterOpen   (TDataSet * DataSet);
    void __fastcall Type_PrikazFDTableNewRecord     (TDataSet * DataSet);
    void __fastcall Type_PrikazTable2NewRecord      (TDataSet * DataSet);
    void __fastcall Vid_SportFDTableAfterOpen       (TDataSet * DataSet);
    void __fastcall Vid_SportFDTableNewRecord       (TDataSet * DataSet);
    void __fastcall Vid_SportTable2NewRecord        (TDataSet * DataSet);
    void __fastcall Vid_SportTable3AfterOpen        (TDataSet * DataSet);
private:
public:
    __fastcall TDM2 (TComponent * Owner);

    AnsiString get_version ();                                                  //функция возвращает версию программы
};

extern PACKAGE TDM2 * DM2;

#endif  // DM2_UNIT_H
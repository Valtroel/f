#pragma once
#ifndef DATA_MODULE_H
#define DATA_MODULE_H


#include <Classes.hpp>
#include <Controls.hpp>
#include <Db.hpp>
#include <DB.hpp>
#include <DBGrids.hpp>
// #include "DBSecur.hpp"
// #include <DBTables.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.FB.hpp>
#include <FireDAC.Phys.FBDef.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.IB.hpp>
#include <FireDAC.Phys.IBBase.hpp>
#include <FireDAC.Phys.IBDef.hpp>
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
#include <Grids.hpp>
// #include <IBCustomDataSet.hpp>
// #include <IBDatabase.hpp>
// #include <IBTable.hpp>
#include <IBX.IBCustomDataSet.hpp>
#include <IBX.IBTable.hpp>
// #include <mxDB.hpp>
// #include <mxstore.hpp>
// #include <mxtables.hpp>
// #include "RxLogin.hpp"
#include <StdCtrls.hpp>


extern bool            result_itog;                                             // переменная для итоговой успеваемости, чтобы calcfield не срабатывало на других формах
extern int             nom_fac,
                       state_query,                                             // статус режима ведомости (Insert или Edit)
                       syst_ball,                                               // глобальная переменная для определения системы оценко (пятибальная или десятибальная)
                       uch_god;
extern TBookmark       Bookmark;
extern TDateTime       curent_date;
// extern TMemoryStream * ds_pms;
extern Variant         App_n,
                       Sh;


int                   ball_int               (                                  // возврат оценки как int (зависит от системы 5, 10 или 100 баллов)
        int syst,
        int ball
    );
AnsiString            ball_string            (                                  // возврат оценки как AnsiString (зависит от системы 5, 10 или 100 баллов)
        int syst,
        int ball,
        int full
    );
void       __fastcall Border_IndentLeft      (                                  // выбор диапазона ячеек, обрамление ячейки, выравнивание с отступом
        int  col1,                                                              // номер столбца начала выделения
        int  col2,                                                              // номер столбца окончания выделения
        int  st1,                                                               // номер сторки начала выделения
        int  st2,                                                               // номер сторки окончания окончания выделения
        bool M_1,                                                               // объединение ячеек (false - не надо объединять)
        int  bord,                                                              // обрамление части ячейки - при  0 обрамлять не надо 1- 2- 3- 4- сторона обрамления
        int  ind                                                                // горизонтальное выравнивание с отступом ind - при  0 выравнивать не надо
    );
void       __fastcall Cell_2_Text            (                                  // выбор ячеек и передача в них текста, размера шрифта, выравнивания
        Variant    WorkSheet,                                                   // выбор рабочего листа
        int        col1,                                                        // номер столбца начала выделения
        int        col2,                                                        // номер столбца окончания выделения
        int        st,                                                          // номер сторки в которой будем выделять
        bool       Border,                                                      // обрамление ячейки true - обрамлять
        AnsiString Shrift,                                                      // название шрифта
        int        kegl,                                                        // размер шрифта
        bool       Bold,                                                        // нормальный или утолщенный шрифт
        int        AlignH,                                                      // горизонтальное выравнивание текста в ячейке (0 - не надо выравнивать)
        int        AlignV,                                                      // вертикальное выравнивание текста в ячейке (0 - не надо выравнивать)
        bool       M_1,                                                         // объединение ячеек (false - не надо объединять)
        bool       W_1,                                                         // перенос по словам (false - не надо переносить)
        AnsiString TextCell                                                     // текст в ячейке
    );
void       __fastcall Cell_2_Text_Ole2       (
        int        col1,                                                        // номер столбца начала выделения
        int        col2,                                                        // номер столбца окончания выделения
        int        st,                                                          // номер сторки в которой будем выделять
        bool       Border,                                                      // обрамление ячейки true - обрамлять
        AnsiString Shrift,                                                      // название шрифта
        int        kegl,                                                        // размер шрифта
        bool       Bold,                                                        // нормальный или утолщенный шрифт
        int        AlignH,                                                      // горизонтальное выравнивание текста в ячейке (0 - не надо выравнивать)
        int        AlignV,                                                      // вертикальное выравнивание текста в ячейке (0 - не надо выравнивать)
        int        Orient,                                                      // ориентация текста в ячейке
        bool       M_1,                                                         // объединение ячеек (false - не надо объединять)
        bool       W_1,                                                         // перенос по словам (false - не надо переносить)
        AnsiString TextCell                                                     // текст в ячейке
    );
bool                  check_fac_group        (AnsiString group);                // функция проверки на соответствие номера группы выбранному факультету
bool                  check_group_kurs       (                                  // функция проверки соответствия номера группы и номера курса
        AnsiString group,
        AnsiString kurs
    );
void       __fastcall Coll_2_Text            (                                  // установка диапазона ячеек и передачи в него текста (СТОЛБЕЦ)
        Variant    WorkSheet,                                                   // выбор рабочего листа
        int        col1,                                                        // номер столбца в котором будет выделение
        int        st1,                                                         // номер сторки начала выделения
        int        st2,                                                         // номер сторки окончания окончания выделения
        bool       Border,                                                      // обрамление ячейки true - обрамлять
        AnsiString Shrift,                                                      // название шрифта
        int        kegl,                                                        // размер шрифта
        bool       Bold,                                                        // нормальный или утолщенный шрифт
        int        AlignH,                                                      // горизонтальное выравнивание текста в ячейке (0 - не надо выравнивать)
        int        AlignV,                                                      // вертикальное выравнивание текста в ячейке (0 - не надо выравнивать)
        int        Orient,                                                      // ориентация текста в ячейке
        bool       M_1,                                                         // объединение ячеек (false - не надо объединять)
        bool       W_1,                                                         // перенос по словам (false - не надо переносить)
        AnsiString TextCell                                                     // текст в ячейке
    );
TDateTime             cur_d                  ();                                // возвращает текущую дату
void       __fastcall DBgrid_toEx            (TDBGrid * Grid);                  // печать в Excel из DBGrida (РАМКА)
void       __fastcall ExCell                 (                                  // функция для Excel
        Variant    WSheet,                                                      // выбор рабочего листа
        int        col1,                                                        // номер столбца начала выделения
        int        col2,                                                        // номер столбца окончания выделения
        int        st,                                                          // номер сторки начала выделения
        int        st2,                                                         // номер сторки окончания окончания выделения
        bool       Border,                                                      // обрамление ячейки true - обрамлять
        AnsiString Shrift,                                                      // название шрифта
        int        kegl,                                                        // размер шрифта
        bool       Bold,                                                        // нормальный или утолщенный шрифт
        int        AlignH,                                                      // горизонтальное выравнивание текста в ячейке (0 - не надо выравнивать)
        int        AlignV,                                                      // вертикальное выравнивание текста в ячейке (0 - не надо выравнивать)
        int        Orient,                                                      // ориентация текста в ячейке
        bool       M_1,                                                         // объединение ячеек (false - не надо объединять)
        bool       W_1,                                                         // перенос по словам (false - не надо переносить)
        AnsiString TextCell                                                     // текст в ячейке
    );
AnsiString            Grid_V                 (                                  // возвращает значение поля
        TFDQuery   * q,
        AnsiString   f
    );
int                   Mas_God_Semestr        (                                  // возврат массива годов в соответствии с выбранным семестром
        int n_kurs,
        int n_sem,
        int god
    );
bool       __fastcall OpenChildForm          (                                  // вместо создания новой формы активирует дочернюю
        TForm * f,
        TForm * f_ch
    );
Variant               search_increment_group (                                  // возврат инкремента группы
        AnsiString gr,
        int        edu
    );
void       __fastcall str_grid               (TStringGrid * SG1);               // передача в Excel из StringGrida
AnsiString            Text_predmet           (                                  // измененяет название предмета для специализации (Используется в выписке к диплому и ГОС-ов)
        AnsiString predmet,
        int        specializ
    );



class TDataModule1
    : public TDataModule
{
__published:
    TBlobField          * People_photoFDQueryDIGIT_SIGN;
    TBlobField          * People_photoFDQueryPHOTO;
    TBlobField          * QueueFDQueryDIGIT_SIGN;
    TBlobField          * QueueFDQueryPHOTO;
    TBlobField          * StudQDIGIT_SIGN;
    TBlobField          * StudQPHOTO;

    TDataSource         * BallQSource;
    TDataSource         * CK_SearchSource;
    TDataSource         * CK_Source;
    TDataSource         * Count_ObjectSource;
    TDataSource         * Count_People_GroupSource;
    TDataSource         * Count_People_KursSource;
    TDataSource         * Count_PeopleSource;
    TDataSource         * DataSource1;
    TDataSource         * DSAdress;
    TDataSource         * DSDiplom_Prikaz_vipusk;
    TDataSource         * DSDistrict;
    TDataSource         * DSLocality;
    TDataSource         * DSStreet;
    TDataSource         * DSType_locality;
    TDataSource         * DSType_street;
    TDataSource         * Edu_CardQSource;
    TDataSource         * Edu_PlanQDSource;
    TDataSource         * Edu_PlanQSource;
    TDataSource         * EncourageSource;
    TDataSource         * Fac_AllSource;
    TDataSource         * FacultySource;
    TDataSource         * FoundationSource;
    TDataSource         * Group_All_PeopleSource;
    TDataSource         * Group_AllSource;
    TDataSource         * HolidaySource;
    TDataSource         * Inc_Group_OldSource;
    TDataSource         * Inc_Group_SemestrSource;
    TDataSource         * Increment_GroupSource;
    TDataSource         * Kafedra_SpecSource;
    TDataSource         * KafedraSource;
    TDataSource         * Kurs_AllSource;
    TDataSource         * LangvSource;
    TDataSource         * LikvidSource;
    TDataSource         * Max_N_Ved_LikvidSource;
    TDataSource         * Max_N_VedomostQSource;
    TDataSource         * Max_Nomer_peopleSource;
    TDataSource         * PasportDS;
    TDataSource         * PasportTypeDS;
    TDataSource         * PassQSource;
    TDataSource         * People_Card_ReportSource;
    TDataSource         * People_CaseSource;
    TDataSource         * People_DogovorSource;
    TDataSource         * People_HostelSource;
    TDataSource         * People_KursSource;
    TDataSource         * People_PartSource;
    TDataSource         * People_SpecializQuerySource;
    TDataSource         * People_SpravkiSource;
    TDataSource         * People_VedSource;
    TDataSource         * PeopleQSource;
    TDataSource         * PeopleUpQSource;
    TDataSource         * Prikaz_KursSource;
    TDataSource         * Prikaz_LikvidSource;
    TDataSource         * Priv_AddSource;
    TDataSource         * PrivSource;
    TDataSource         * Public_PrikazSource;
    TDataSource         * QueueDataSource1;
    TDataSource         * Rating_BallSource;
    TDataSource         * Rating_GridSource;
    TDataSource         * Rating_ReportSource;
    TDataSource         * RatingSource;
    TDataSource         * Region_CentreSource;
    TDataSource         * RegionSource;
    TDataSource         * RestoreQSource;
    TDataSource         * Result_Ball_3Source;
    TDataSource         * Result_Ball_For_VedSource;
    TDataSource         * Result_Ball_LocateSource;
    TDataSource         * Result_BallSource;
    TDataSource         * Semestr_KursQSource;
    TDataSource         * SessionSource;
    TDataSource         * Spec_PlanQSource;
    TDataSource         * SpecializQSource;
    TDataSource         * Spisoc_All_StudSource;
    TDataSource         * SpisocQSource;
    TDataSource         * SportQSource;
    TDataSource         * Statistic_Pass_DateSource;
    TDataSource         * Statistic_Pass_MonthSource;
    TDataSource         * Status_2Source;
    TDataSource         * Sub_Edu_PlanSource;
    TDataSource         * Type_EncourageSource;
    TDataSource         * Type_LikvidSource;
    TDataSource         * Ved_exlistQSource;
    TDataSource         * Ved_Likvid_ReportSource;
    TDataSource         * Ved_LikvidGridSource;
    TDataSource         * Ved_RatingSource;
    TDataSource         * Ved_Raznica_People_CaseSource;
    TDataSource         * Ved_RaznicaSource;
    TDataSource         * Vedomost_ReportSource;
    TDataSource         * VedomostQSource;
    TDataSource         * Vozrast3NKSource;
    TDataSource         * ZachetkaQSource;

    TFDConnection       * FDConnection1;
    TFDConnection       * FDConnection2;

    TFDPhysFBDriverLink * FDPhysFBDriverLink1;

    TFDQuery            * Ball_FDQuery;
    TFDQuery            * CK_CountFDQuery;
    TFDQuery            * CK_FDQuery;
    TFDQuery            * CK_SearchFDQ;
    TFDQuery            * Count_ObjectFDQuery;
    TFDQuery            * Count_People_GroupFDQuery;
    TFDQuery            * Count_People_KursFDQuery;
    TFDQuery            * Count_PeopleFDQuery;
    TFDQuery            * Count_VipuskFDQuery2;
    TFDQuery            * Delete_IncrementFDQuery;
    TFDQuery            * Diplom_Prikaz_vipusk_countFDQuery;
    TFDQuery            * Diplom_Prikaz_vipuskFDQuery;
    TFDQuery            * DiplomREG_countFDQuery;
    TFDQuery            * DiplomREGExcelFDQuery;
    TFDQuery            * DiplomREGFDQuery;
    TFDQuery            * Edu_Card_CountFDQuery;
    TFDQuery            * Edu_CardFDQuery;
    TFDQuery            * Edu_PlanFDQ;
    TFDQuery            * Edu_PlanFDQuery;
    TFDQuery            * EncourageFDQuery;
    TFDQuery            * Fac_AllFDQuery;
    TFDQuery            * FacFullFDQ;
    TFDQuery            * FDQIP;
    TFDQuery            * GEKFDQuery;
    TFDQuery            * GEKResultBallFDQuery;
    TFDQuery            * Group_All_PeopleFDQuery;
    TFDQuery            * Group_AllFDQuery;
    TFDQuery            * HolidayFDQuery;
    TFDQuery            * Inc_Group_OldFDQuery;
    TFDQuery            * Inc_Group_SemestrFDQuery;
    TFDQuery            * Increment_GroupFDQuery;
    TFDQuery            * Integr_modulFDQuery;
    TFDQuery            * IP2FDQ;
    TFDQuery            * Kafedra_SpecFDQuery;
    TFDQuery            * KafedraFDQuery;
    TFDQuery            * Kurs_AllFDQuery;
    TFDQuery            * Langv_CountFDQuery;
    TFDQuery            * LangvFDQuery;
    TFDQuery            * LikvidFDQuery;
    TFDQuery            * Max_N_Ved_LikvidFDQuery;
    TFDQuery            * Max_N_VedomostFDQuery;
    TFDQuery            * Max_Nomer_peopleFDQuery;
    TFDQuery            * Max_Ved_RatingFDQuery;
    TFDQuery            * Max_ZachetkaFDQuery;
    TFDQuery            * PasportFDQ;
    TFDQuery            * PasportTypeFDQ;
    TFDQuery            * PassFDQuery;
    TFDQuery            * People_Card_ReportFDQuery;
    TFDQuery            * People_CaseFDQuery;
    TFDQuery            * People_Dogovor_CountFDQuery;
    TFDQuery            * People_DogovorFDQuery;
    TFDQuery            * People_EduCardFDQuery;
    TFDQuery            * People_Hostel_CountFDQuery;
    TFDQuery            * People_HostelFDQuery;
    TFDQuery            * People_KursFDQuery;
    TFDQuery            * People_Part_CountFDQuery;
    TFDQuery            * People_PartFDQuery;
    TFDQuery            * People_photoFDQuery;
    TFDQuery            * People_SpecializFDQuery;
    TFDQuery            * People_SpravkiFDQuery;
    TFDQuery            * People_statusFDQuery;
    TFDQuery            * People_VedFDQuery;
    TFDQuery            * PeopleFDQuery;
    TFDQuery            * PeopleUp_CountFDQuery;
    TFDQuery            * PeopleUpFDQuery;
    TFDQuery            * Prikaz_kurs_OFKiT_MSTiGFDQuery;
    TFDQuery            * Prikaz_KursFDQuery;
    TFDQuery            * Prikaz_LikvidFDQuery;
    TFDQuery            * Priv_AddFDQuery;
    TFDQuery            * Priv_CountFDQuery;
    TFDQuery            * PrivFDQuery;
    TFDQuery            * Public_PrikazFDQuery;
    TFDQuery            * Publik_PrikazFDQuery;
    TFDQuery            * QAdress;
    TFDQuery            * QDistrict;
    TFDQuery            * QLocality;
    TFDQuery            * QStreet;
    TFDQuery            * QType_locality;
    TFDQuery            * QType_street;
    TFDQuery            * Queue_UpFDQuery;
    TFDQuery            * QueueFDQuery;
    TFDQuery            * Rating_BallFDQuery;
    TFDQuery            * Rating_GridFDQuery;
    TFDQuery            * Rating_ReportFDQuery;
    TFDQuery            * Rating_SearchFDQuery;
    TFDQuery            * RatingFDQuery;
    TFDQuery            * Region_CentreFDQuery;
    TFDQuery            * RestoreFDQuery;
    TFDQuery            * Result_Ball_For_VedFDQuery;
    TFDQuery            * Result_Ball_LocateFDQuery;
    TFDQuery            * Result_Ball_ThreeFDQuery;
    TFDQuery            * Result_BallFDQuery;
    TFDQuery            * Semestr_Kurs_NewFDQuery;
    TFDQuery            * Semestr_KursFDQuery;
    TFDQuery            * SessionFDQuery;
    TFDQuery            * Spec_PlanFDQuery;
    TFDQuery            * Specializ_GroupFDQuery;
    TFDQuery            * SpecializFDQuery;
    TFDQuery            * Spisoc_All_StudFDQuery;
    TFDQuery            * Spisoc_FDQuery;
    TFDQuery            * SportFDQuery;
    TFDQuery            * StatementDiplomFDQuery;
    TFDQuery            * Statistic_Pass_DateFDQuery;
    TFDQuery            * Statistic_Pass_MonthFDQuery;
    TFDQuery            * Status_2_CountFDQuery;
    TFDQuery            * Status_2FDQuery;
    TFDQuery            * StudQ_Count;
    TFDQuery            * StudQ;
    TFDQuery            * Sub_Edu_PlanFDQuery;
    TFDQuery            * Type_EncourageFDQuery;
    TFDQuery            * Type_LikvidFDQuery;
    TFDQuery            * Ved_exlistFDQuery;
    TFDQuery            * Ved_Likvid_ReportFDQuery;
    TFDQuery            * Ved_LikvidGridFDQuery;
    TFDQuery            * Ved_RatingFDQuery;
    TFDQuery            * Ved_Raznica_People_CaseFDQuery;
    TFDQuery            * Ved_RaznicaFDQuery;
    TFDQuery            * VedJournal;
    TFDQuery            * VedListJournal;
    TFDQuery            * Vedomost_CountFDQuery;
    TFDQuery            * Vedomost_GEKFDQuery;
    TFDQuery            * Vedomost_ReportFDQuery;
    TFDQuery            * Vedomost2FDQuery;
    TFDQuery            * VedomostFDQuery;
    TFDQuery            * VipuskFDQuery;
    TFDQuery            * Vozrast3NKFDQuery;
    TFDQuery            * Zachetka_All_KursFDQuery;
    TFDQuery            * ZachetkaFDQuery_Count;
    TFDQuery            * ZachetkaFDQuery;

    TFDStoredProc       * FDStoredProcEdu_Plan;
    TFDStoredProc       * FDStoredProcPeople;
    TFDStoredProc       * FDStoredProcVed_Rating;
    TFDStoredProc       * FDStoredProcVed_Raznica;
    TFDStoredProc       * FDStoredProcVed;

    TFDTable            * FacultyFDTable;
    TFDTable            * FoundationFDTable;
    TFDTable            * RegionFDTable;

    TFDUpdateSQL        * Ball_FDUpdateSQL;
    TFDUpdateSQL        * CK_SearchFDUpdateSQL;
    TFDUpdateSQL        * Delete_IncrementFDUpdateSQL;
    TFDUpdateSQL        * Diplom_Prikaz_vipuskFDUpdateSQL;
    TFDUpdateSQL        * DiplomREGFDUpdateSQL;
    TFDUpdateSQL        * Edu_CardFDUpdateSQL;
    TFDUpdateSQL        * Edu_PlanFDUpdateSQL;
    TFDUpdateSQL        * EncourageFDUpdateSQL;
    TFDUpdateSQL        * FDUpdateSQLInsGEK;
    TFDUpdateSQL        * FDUpdateSQLVedomost_GEK;
    TFDUpdateSQL        * HolidayFDUpdateSQL;
    TFDUpdateSQL        * Inc_Group_OldFDUpdateSQL;
    TFDUpdateSQL        * Increment_GroupFDUpdateSQL;
    TFDUpdateSQL        * LikvidFDUpdateSQL;
    TFDUpdateSQL        * PasportFDUp;
    TFDUpdateSQL        * PassFDUpdateSQL;
    TFDUpdateSQL        * People_KursFDSQL;
    TFDUpdateSQL        * People_photoFDUpdateSQL;
    TFDUpdateSQL        * PeopleFDUpdateSQL;
    TFDUpdateSQL        * PeopleUpFDUpdateSQL;
    TFDUpdateSQL        * Prikaz_KursFDSQL;
    TFDUpdateSQL        * Prikaz_LikvidFDUpdateSQL;
    TFDUpdateSQL        * Priv_AddFDUpdateSQL;
    TFDUpdateSQL        * Public_PrikazFDUpdateSQL;
    TFDUpdateSQL        * Publik_PrikazFDUpdateSQL;
    TFDUpdateSQL        * Rating_BallFDUpdateSQL;
    TFDUpdateSQL        * Rating_GridFDUpdateSQL;
    TFDUpdateSQL        * RatingFDUpdateSQL;
    TFDUpdateSQL        * RestoreFDUpdateSQL;
    TFDUpdateSQL        * Result_Ball_LocateFDUpdateSQL;
    TFDUpdateSQL        * Result_Ball_ThreeFDUpdateSQL;
    TFDUpdateSQL        * Result_BallFDUpdateSQL;
    TFDUpdateSQL        * ResultFDUpdateSQL;
    TFDUpdateSQL        * Spec_PlanFDUpdateSQL;
    TFDUpdateSQL        * SportFDUpdateSQL;
    TFDUpdateSQL        * Sub_Edu_PlanFDUpdateSQL;
    TFDUpdateSQL        * Ved_LikvidGridFDUpdateSQL;
    TFDUpdateSQL        * Ved_RatingFDUpdateSQL;
    TFDUpdateSQL        * Ved_RaznicaFDUpdateSQL;
    TFDUpdateSQL        * VedomostFDUpdateSQL;
    TFDUpdateSQL        * VipuskFDUpdateSQL;
    TFDUpdateSQL        * ZachetkaFDUpdateSQL;

    TFloatField         * Edu_PlanFDQCLOCK_PLAN;
    TFloatField         * Edu_PlanFDQueryCLOCK_PLAN;
    TFloatField         * People_VedFDQueryCLOCK_PLAN;
    TFloatField         * PeopleFDQueryMIDDLE_B;
    TFloatField         * Result_BallFDQueryCLOCK_PLAN;
    TFloatField         * Ved_Likvid_ReportFDQueryCLOCK_PLAN;
    TFloatField         * Vedomost_ReportFDQueryCLOCK_PLAN;

    TIntegerField       * Ball_FDQueryN_PLAN;
    TIntegerField       * Ball_FDQueryN_VED;
    TIntegerField       * Ball_FDQueryNOMER;
    TIntegerField       * CK_FDQueryCUSTOMER;
    TIntegerField       * CK_SearchFDQCUSTOMER;
    TIntegerField       * CK_SearchFDQN_CENTRE;
    TIntegerField       * CK_SearchFDQN_CK;
    TIntegerField       * CK_SearchFDQN_REGION;
    TIntegerField       * CK_SearchFDQN_SPECIALIZ;
    TIntegerField       * CK_SearchFDQNOMER;
    TIntegerField       * Delete_IncrementFDQueryGOD;
    TIntegerField       * Diplom_Prikaz_vipuskFDQueryNOMER;
    TIntegerField       * DiplomREGExcelFDQueryNOMER;
    TIntegerField       * DiplomREGFDQueryNOMER;
    TIntegerField       * Edu_CardFDQueryN_VED;
    TIntegerField       * Edu_CardFDQueryNOMER;
    TIntegerField       * Edu_PlanFDQN_PLAN;
    TIntegerField       * Edu_PlanFDQueryN_PLAN;
    TIntegerField       * EncourageFDQueryNOMER;
    TIntegerField       * GEKFDQueryNOMER_GEK;
    TIntegerField       * GEKFDQueryNOMER;
    TIntegerField       * GEKResultBallFDQueryNOMER_GEK;
    TIntegerField       * GEKResultBallFDQueryNOMER;
    TIntegerField       * HolidayFDQueryNOMER;
    TIntegerField       * Inc_Group_OldFDQueryGOD;
    TIntegerField       * Inc_Group_OldFDQueryINC_GROUP;
    TIntegerField       * Increment_GroupFDQueryGOD;
    TIntegerField       * Kafedra_SpecFDQueryN_KAF_SPEC;
    TIntegerField       * Kafedra_SpecFDQueryN_KAFEDRA;
    TIntegerField       * Kafedra_SpecFDQueryN_SPECIALIZ;
    TIntegerField       * KafedraFDQueryN_FAC;
    TIntegerField       * KafedraFDQueryN_KAFEDRA;
    TIntegerField       * LikvidFDQueryN_PRIKAZ_KIKVID;
    TIntegerField       * LikvidFDQueryNOMER;
    TIntegerField       * Max_Ved_RatingFDQueryMAX;
    TIntegerField       * PasportFDQNOMER;
    TIntegerField       * PasportTypeFDQID_TYPE;
    TIntegerField       * PassFDQueryNOMER;
    TIntegerField       * People_CaseFDQueryNOMER;
    TIntegerField       * People_EduCardFDQueryNOMER;
    TIntegerField       * People_KursFDQueryNOMER;
    TIntegerField       * People_KursFDQuerySTATUS_KURS;
    TIntegerField       * People_PartFDQueryNOMER;
    TIntegerField       * People_photoFDQueryNOMER;
    TIntegerField       * People_SpecializFDQueryNOMER;
    TIntegerField       * People_SpravkiFDQueryNOMER;
    TIntegerField       * People_SpravkiFDQuerySTATUS_KURS;
    TIntegerField       * People_statusFDQueryNOMER;
    TIntegerField       * People_VedFDQueryNOMER;
    TIntegerField       * PeopleFDQueryCITIZENSHIP;
    TIntegerField       * PeopleFDQueryID_STREET;
    TIntegerField       * PeopleFDQueryN_CENTRE;
    TIntegerField       * PeopleFDQueryNOMER;
    TIntegerField       * PeopleFDQueryNUMBER;
    TIntegerField       * PeopleFDQueryPOSTCODE;
    TIntegerField       * PeopleFDQuerySTATUS_KURS;
    TIntegerField       * PeopleUpFDQueryNOMER;
    TIntegerField       * PeopleUpFDQuerySTATUS_KURS;
    TIntegerField       * Prikaz_KursFDQueryNOMER;
    TIntegerField       * Prikaz_LikvidFDQueryN_PRIKAZ_KIKVID;
    TIntegerField       * Prikaz_LikvidFDQueryNOMER;
    TIntegerField       * Priv_AddFDQueryN_PRIV;
    TIntegerField       * Priv_AddFDQueryNOMER;
    TIntegerField       * Public_PrikazFDQueryNOMER;
    TIntegerField       * Publik_PrikazFDQueryNOMER;
    TIntegerField       * QAdressLOCAL_ID;
    TIntegerField       * QAdressN_DISTRICT;
    TIntegerField       * QAdressN_REGION;
    TIntegerField       * QAdressN_TYPE;
    TIntegerField       * QAdressTYPE_STREET;
    TIntegerField       * QDistrictN_DISTRICT;
    TIntegerField       * QDistrictN_REGION;
    TIntegerField       * QLocalityID;
    TIntegerField       * QLocalityN_DISTRICT;
    TIntegerField       * QStreetID;
    TIntegerField       * QType_localityN_TYPE;
    TIntegerField       * QType_streetID;
    TIntegerField       * QueueFDQueryID_AB;
    TIntegerField       * Rating_BallFDQueryBALL_R;
    TIntegerField       * Rating_BallFDQueryINC_GROUP;
    TIntegerField       * Rating_BallFDQueryN_FAC;
    TIntegerField       * Rating_BallFDQueryN_RATING;
    TIntegerField       * Rating_BallFDQueryN_SPECIALIZ;
    TIntegerField       * Rating_BallFDQueryN_VED_RATING;
    TIntegerField       * Rating_BallFDQueryN_VEDOMOST_R;
    TIntegerField       * Rating_BallFDQueryNOMER;
    TIntegerField       * Rating_BallFDQueryR_DOP;
    TIntegerField       * Rating_BallFDQueryR_FAC;
    TIntegerField       * Rating_BallFDQueryR_GROUP;
    TIntegerField       * Rating_BallFDQueryR_KURS;
    TIntegerField       * Rating_GridFDQueryINC_GROUP;
    TIntegerField       * Rating_GridFDQueryN_FAC;
    TIntegerField       * Rating_GridFDQueryN_SPECIALIZ;
    TIntegerField       * Rating_GridFDQueryN_VED_RATING;
    TIntegerField       * Rating_GridFDQueryN_VEDOMOST_R;
    TIntegerField       * Rating_ReportFDQueryINC_GROUP;
    TIntegerField       * Rating_ReportFDQueryN_FAC;
    TIntegerField       * Rating_ReportFDQueryN_SPECIALIZ;
    TIntegerField       * Rating_ReportFDQueryN_VED_RATING;
    TIntegerField       * Rating_ReportFDQueryN_VEDOMOST_R;
    TIntegerField       * Rating_ReportFDQueryNOMER;
    TIntegerField       * Rating_SearchFDQueryN_FAC;
    TIntegerField       * Rating_SearchFDQueryN_VED_RATING;
    TIntegerField       * Rating_SearchFDQueryN_VEDOMOST_R;
    TIntegerField       * Rating_SearchFDQueryNOMER;
    TIntegerField       * RatingFDQueryBALL_R;
    TIntegerField       * RatingFDQueryN_RATING;
    TIntegerField       * RatingFDQueryN_VED_RATING;
    TIntegerField       * RatingFDQueryNOMER;
    TIntegerField       * RatingFDQueryR_DOP;
    TIntegerField       * RatingFDQueryR_FAC;
    TIntegerField       * RatingFDQueryR_GROUP;
    TIntegerField       * RatingFDQueryR_KURS;
    TIntegerField       * RestoreFDQueryNOMER;
    TIntegerField       * Result_Ball_For_VedFDQueryN_PLAN;
    TIntegerField       * Result_Ball_For_VedFDQueryNOMER;
    TIntegerField       * Result_Ball_LocateFDQueryN_PLAN;
    TIntegerField       * Result_Ball_LocateFDQueryNOMER;
    TIntegerField       * Result_Ball_ThreeFDQueryN_PLAN;
    TIntegerField       * Result_Ball_ThreeFDQueryNOMER;
    TIntegerField       * Result_BallFDQueryN_PLAN;
    TIntegerField       * Result_BallFDQueryNOMER;
    TIntegerField       * Semestr_KursFDQueryNOMER;
    TIntegerField       * SessionFDQueryN_VED;
    TIntegerField       * SessionFDQueryNOMER;
    TIntegerField       * Spec_PlanFDQueryN_PLAN;
    TIntegerField       * Spec_PlanFDQueryN_SPEC_PLAN;
    TIntegerField       * Spisoc_All_StudFDQueryNOMER;
    TIntegerField       * Spisoc_FDQueryNOMER;
    TIntegerField       * SportFDQueryNOMER;
    TIntegerField       * StudQNOMER;
    TIntegerField       * StudQSTATUS_KURS;
    TIntegerField       * Sub_Edu_PlanFDQueryN_PLAN_PARENT;
    TIntegerField       * Ved_exlistFDQueryN_PLAN;
    TIntegerField       * Ved_exlistFDQueryN_VED;
    TIntegerField       * Ved_Likvid_ReportFDQueryN_PLAN;
    TIntegerField       * Ved_Likvid_ReportFDQueryN_VED;
    TIntegerField       * Ved_Likvid_ReportFDQueryNOMER;
    TIntegerField       * Ved_LikvidGridFDQueryN_PLAN;
    TIntegerField       * Ved_LikvidGridFDQueryN_VED;
    TIntegerField       * Ved_LikvidGridFDQueryNOMER;
    TIntegerField       * Ved_RatingFDQueryINC_GROUP;
    TIntegerField       * Ved_RatingFDQueryN_FAC;
    TIntegerField       * Ved_RatingFDQueryN_SPECIALIZ;
    TIntegerField       * Ved_RatingFDQueryN_VED_RATING;
    TIntegerField       * Ved_RatingFDQueryN_VEDOMOST_R;
    TIntegerField       * Ved_Raznica_People_CaseFDQueryNOMER;
    TIntegerField       * Ved_RaznicaFDQueryN_PLAN;
    TIntegerField       * Ved_RaznicaFDQueryN_VED;
    TIntegerField       * Ved_RaznicaFDQueryNOMER;
    TIntegerField       * VedJournalN_VED;
    TIntegerField       * VedListJournalN_VED;
    TIntegerField       * Vedomost_GEKFDQueryN_PLAN;
    TIntegerField       * Vedomost_GEKFDQueryN_VED;
    TIntegerField       * Vedomost_ReportFDQueryN_VED;
    TIntegerField       * Vedomost2FDQueryN_PLAN;
    TIntegerField       * Vedomost2FDQueryN_VED;
    TIntegerField       * VedomostFDQueryN_PLAN;
    TIntegerField       * VedomostFDQueryN_VED;
    TIntegerField       * VipuskFDQueryNOMER;
    TIntegerField       * Zachetka_All_KursFDQueryNOMER;
    TIntegerField       * ZachetkaFDQueryNOMER;

    TLargeintField      * CK_CountFDQueryCOUNT;
    TLargeintField      * Count_People_GroupFDQueryCOUNT;
    TLargeintField      * Count_People_KursFDQueryCOUNT;
    TLargeintField      * Count_PeopleFDQueryCOUNT;
    TLargeintField      * Count_VipuskFDQuery2COUNT;
    TLargeintField      * Diplom_Prikaz_vipusk_countFDQueryCOUNT;
    TLargeintField      * DiplomREG_countFDQueryCOUNT;
    TLargeintField      * Edu_Card_CountFDQueryCOUNT;
    TLargeintField      * Fac_AllFDQuerySUM;
    TLargeintField      * Group_AllFDQuerySUM;
    TLargeintField      * Inc_Group_SemestrFDQueryCOUNT;
    TLargeintField      * Kurs_AllFDQuerySUM;
    TLargeintField      * Langv_CountFDQueryCOUNT;
    TLargeintField      * People_Dogovor_CountFDQueryCOUNT;
    TLargeintField      * People_Hostel_CountFDQueryCOUNT;
    TLargeintField      * People_Part_CountFDQueryCOUNT;
    TLargeintField      * PeopleUp_CountFDQueryCOUNT;
    TLargeintField      * Priv_CountFDQueryCOUNT;
    TLargeintField      * Semestr_Kurs_NewFDQueryCOUNT;
    TLargeintField      * Statistic_Pass_DateFDQuerySUM;
    TLargeintField      * Statistic_Pass_MonthFDQuerySUM;
    TLargeintField      * Status_2_CountFDQueryCOUNT;
    TLargeintField      * StudQ_CountCOUNT;
    TLargeintField      * Vedomost_CountFDQueryCOUNT;
    TLargeintField      * ZachetkaFDQuery_CountCOUNT;

    TSingleField        * PeopleFDQuerySCHOLARSHIP;
    TSingleField        * Sub_Edu_PlanFDQueryPERC_SUB_PLAN;

    TSmallintField      * Ball_FDQueryBALL;
    TSmallintField      * Ball_FDQueryN_FAC;
    TSmallintField      * Ball_FDQueryN_VEDOMOST;
    TSmallintField      * Ball_FDQueryZACH_EXAM;
    TSmallintField      * CK_FDQueryN_FAC;
    TSmallintField      * CK_SearchFDQSTATUS_CK;
    TSmallintField      * Count_ObjectFDQueryN_OBJECT;
    TSmallintField      * Count_ObjectFDQueryZACH_EXAM;
    TSmallintField      * Count_People_GroupFDQueryINC_GROUP;
    TSmallintField      * Count_People_KursFDQueryKURS;
    TSmallintField      * Delete_IncrementFDQueryINC_GROUP;
    TSmallintField      * Delete_IncrementFDQueryVID_EDU;
    TSmallintField      * DiplomREGExcelFDQueryN_FAC;
    TSmallintField      * DiplomREGExcelFDQueryN_PROTOKOL;
    TSmallintField      * DiplomREGExcelFDQueryN_PUBLIC_PRIKAZ;
    TSmallintField      * DiplomREGExcelFDQueryN_SPEC;
    TSmallintField      * DiplomREGExcelFDQueryN_SPECIALIZ;
    TSmallintField      * DiplomREGExcelFDQueryTYPE_DIPLOM;
    TSmallintField      * DiplomREGExcelFDQueryVID_EDU;
    TSmallintField      * DiplomREGFDQueryN_FAC;
    TSmallintField      * DiplomREGFDQueryN_PROTOKOL;
    TSmallintField      * DiplomREGFDQueryN_PUBLIC_PRIKAZ;
    TSmallintField      * DiplomREGFDQueryN_SPEC;
    TSmallintField      * DiplomREGFDQueryN_SPECIALIZ;
    TSmallintField      * DiplomREGFDQueryTYPE_DIPLOM;
    TSmallintField      * DiplomREGFDQueryVID_EDU;
    TSmallintField      * Edu_CardFDQueryBALL;
    TSmallintField      * Edu_PlanFDQN_FAC;
    TSmallintField      * Edu_PlanFDQN_OBJECT;
    TSmallintField      * Edu_PlanFDQSEMESTR;
    TSmallintField      * Edu_PlanFDQSPECKURS;
    TSmallintField      * Edu_PlanFDQSTATUS_CONTROL;
    TSmallintField      * Edu_PlanFDQueryALL_HOURS;
    TSmallintField      * Edu_PlanFDQueryCLASSROOM_HOURS;
    TSmallintField      * Edu_PlanFDQueryCLOCK_PLAN_ALL;
    TSmallintField      * Edu_PlanFDQueryLABORATORY_HOURS;
    TSmallintField      * Edu_PlanFDQueryLECTURE_HOURS;
    TSmallintField      * Edu_PlanFDQueryN_FAC;
    TSmallintField      * Edu_PlanFDQueryN_OBJECT;
    TSmallintField      * Edu_PlanFDQueryPRACTICAL_HOURS;
    TSmallintField      * Edu_PlanFDQuerySEMESTR;
    TSmallintField      * Edu_PlanFDQuerySEMINAR_HOURS;
    TSmallintField      * Edu_PlanFDQuerySPECKURS;
    TSmallintField      * Edu_PlanFDQuerySTATUS_CONTROL;
    TSmallintField      * Edu_PlanFDQueryTYPE_PLAN;
    TSmallintField      * Edu_PlanFDQueryVID_EDU_PLAN;
    TSmallintField      * Edu_PlanFDQueryYEAR_PLAN;
    TSmallintField      * Edu_PlanFDQueryZACH_EXAM;
    TSmallintField      * Edu_PlanFDQVID_EDU_PLAN;
    TSmallintField      * Edu_PlanFDQYEAR_PLAN;
    TSmallintField      * Edu_PlanFDQZACH_EXAM;
    TSmallintField      * EncourageFDQueryN_PRIKAZ;
    TSmallintField      * EncourageFDQueryN_TYPE_EN;
    TSmallintField      * EncourageFDQueryTYPE_EN;
    TSmallintField      * Fac_AllFDQueryKURS;
    TSmallintField      * FacultyFDTableKOD_FAC;
    TSmallintField      * FacultyFDTableN_FAC;
    TSmallintField      * FoundationFDTableN_FOUND;
    TSmallintField      * GEKFDQueryBALL_GEK;
    TSmallintField      * GEKFDQueryN_PROTOCOL;
    TSmallintField      * GEKFDQueryN_VED;
    TSmallintField      * GEKResultBallFDQueryBALL_GEK;
    TSmallintField      * GEKResultBallFDQueryN_PROTOCOL;
    TSmallintField      * GEKResultBallFDQueryN_VED;
    TSmallintField      * Group_AllFDQueryINC_GROUP;
    TSmallintField      * Group_AllFDQueryN_CAUSE;
    TSmallintField      * HolidayFDQueryN_HOL;
    TSmallintField      * HolidayFDQueryN_PRIKAZ_HOL;
    TSmallintField      * HolidayFDQueryTYPE_HOL;
    TSmallintField      * Inc_Group_OldFDQueryVID_EDU;
    TSmallintField      * Inc_Group_SemestrFDQueryINC_GROUP;
    TSmallintField      * Increment_GroupFDQueryINC_GROUP;
    TSmallintField      * Increment_GroupFDQueryVID_EDU;
    TSmallintField      * Integr_modulFDQueryN_OBJECT;
    TSmallintField      * Kafedra_SpecFDQuerySTATUS;
    TSmallintField      * KafedraFDQueryVIPUSK;
    TSmallintField      * Kurs_AllFDQueryINC_GROUP;
    TSmallintField      * Kurs_AllFDQueryKURS;
    TSmallintField      * Kurs_AllFDQueryN_CAUSE;
    TSmallintField      * LangvFDQueryKURS;
    TSmallintField      * LangvFDQueryN_FAC;
    TSmallintField      * LangvFDQueryVID_EDU;
    TSmallintField      * LangvFDQueryWHEN_EDUC;
    TSmallintField      * LikvidFDQueryFAC_DO;
    TSmallintField      * LikvidFDQueryFAC_PO;
    TSmallintField      * LikvidFDQueryKURS_DO;
    TSmallintField      * LikvidFDQueryKURS_PO;
    TSmallintField      * LikvidFDQueryN_FOUND_DO;
    TSmallintField      * LikvidFDQueryN_FOUND_PO;
    TSmallintField      * LikvidFDQuerySPECIALIZ_DO;
    TSmallintField      * LikvidFDQuerySPECIALIZ_PO;
    TSmallintField      * LikvidFDQuerySTATUS_NOMER;
    TSmallintField      * LikvidFDQueryVID_EDU_DO;
    TSmallintField      * LikvidFDQueryVID_EDU_PO;
    TSmallintField      * LikvidFDQueryYEAR_UCH;
    TSmallintField      * Max_N_Ved_LikvidFDQueryMAX;
    TSmallintField      * Max_N_VedomostFDQueryMAX;
    TSmallintField      * PasportFDQID_TYPE;
    TSmallintField      * PasportFDQN_REGION;
    TSmallintField      * PassFDQueryHOUR_PASS;
    TSmallintField      * PassFDQueryN_CAUSE;
    TSmallintField      * People_CaseFDQueryINC_GROUP;
    TSmallintField      * People_CaseFDQueryKURS;
    TSmallintField      * People_CaseFDQueryN_FAC;
    TSmallintField      * People_CaseFDQueryN_FOUND;
    TSmallintField      * People_CaseFDQueryN_SPECIALIZ;
    TSmallintField      * People_CaseFDQuerySTATUS_PEOPLE;
    TSmallintField      * People_CaseFDQueryVID_EDU;
    TSmallintField      * People_DogovorFDQueryKURS;
    TSmallintField      * People_DogovorFDQueryN_FAC;
    TSmallintField      * People_DogovorFDQueryVID_EDU;
    TSmallintField      * People_EduCardFDQueryINC_GROUP;
    TSmallintField      * People_EduCardFDQueryKURS;
    TSmallintField      * People_EduCardFDQueryN_FOUND;
    TSmallintField      * People_EduCardFDQueryVID_EDU;
    TSmallintField      * People_HostelFDQueryKURS;
    TSmallintField      * People_HostelFDQueryN_FAC;
    TSmallintField      * People_HostelFDQueryVID_EDU;
    TSmallintField      * People_KursFDQueryINC_GROUP;
    TSmallintField      * People_KursFDQueryKURS;
    TSmallintField      * People_PartFDQueryINC_GROUP;
    TSmallintField      * People_PartFDQueryKURS;
    TSmallintField      * People_PartFDQueryN_FOUND;
    TSmallintField      * People_PartFDQueryVID_EDU;
    TSmallintField      * People_SpecializFDQueryINC_GROUP;
    TSmallintField      * People_SpecializFDQueryKURS;
    TSmallintField      * People_SpecializFDQueryVID_EDU;
    TSmallintField      * People_SpravkiFDQueryINC_GROUP;
    TSmallintField      * People_SpravkiFDQueryKURS;
    TSmallintField      * People_SpravkiFDQueryN_FAC;
    TSmallintField      * People_SpravkiFDQueryN_FOUND_INCLUDE;
    TSmallintField      * People_SpravkiFDQueryN_FOUND;
    TSmallintField      * People_SpravkiFDQueryN_PRIKAZ_INCLUDE;
    TSmallintField      * People_SpravkiFDQuerySTATUS_PEOPLE;
    TSmallintField      * People_SpravkiFDQueryVID_EDU_INCLUDE;
    TSmallintField      * People_SpravkiFDQueryVID_EDU;
    TSmallintField      * People_statusFDQuerySTATUS_PEOPLE;
    TSmallintField      * People_VedFDQueryBALL;
    TSmallintField      * People_VedFDQueryCLOCK_PLAN_ALL;
    TSmallintField      * People_VedFDQueryN_OBJECT;
    TSmallintField      * People_VedFDQueryN_VEDOMOST;
    TSmallintField      * People_VedFDQuerySEMESTR_VED;
    TSmallintField      * People_VedFDQuerySTATUS;
    TSmallintField      * People_VedFDQueryYEAR_PLAN;
    TSmallintField      * People_VedFDQueryZACH_EXAM;
    TSmallintField      * PeopleFDQueryARMY;
    TSmallintField      * PeopleFDQueryEDUCATION;
    TSmallintField      * PeopleFDQueryFLAT;
    TSmallintField      * PeopleFDQueryHOSTEL;
    TSmallintField      * PeopleFDQueryINC_GROUP;
    TSmallintField      * PeopleFDQueryKURS;
    TSmallintField      * PeopleFDQueryMARIAGE;
    TSmallintField      * PeopleFDQueryN_ADD_AGREE;
    TSmallintField      * PeopleFDQueryN_CHILD;
    TSmallintField      * PeopleFDQueryN_DELA;
    TSmallintField      * PeopleFDQueryN_FAC;
    TSmallintField      * PeopleFDQueryN_FOUND_INCLUDE;
    TSmallintField      * PeopleFDQueryN_FOUND;
    TSmallintField      * PeopleFDQueryN_PRIKAZ_INCLUDE;
    TSmallintField      * PeopleFDQueryN_PRIKAZ_KURS;
    TSmallintField      * PeopleFDQueryN_SPEC;
    TSmallintField      * PeopleFDQueryN_SPECIALIZ;
    TSmallintField      * PeopleFDQueryN_VID_SPORT;
    TSmallintField      * PeopleFDQuerySTATUS_PEOPLE;
    TSmallintField      * PeopleFDQueryVID_EDU_INCLUDE;
    TSmallintField      * PeopleFDQueryVID_EDU;
    TSmallintField      * PeopleFDQueryWHEN_EDUC;
    TSmallintField      * PeopleUpFDQueryINC_GROUP;
    TSmallintField      * PeopleUpFDQueryKURS;
    TSmallintField      * PeopleUpFDQueryN_FAC;
    TSmallintField      * PeopleUpFDQueryN_FOUND;
    TSmallintField      * PeopleUpFDQueryN_PRIKAZ_KURS;
    TSmallintField      * PeopleUpFDQueryN_SPEC;
    TSmallintField      * PeopleUpFDQueryN_SPECIALIZ;
    TSmallintField      * PeopleUpFDQuerySTATUS_PEOPLE;
    TSmallintField      * PeopleUpFDQueryVID_EDU;
    TSmallintField      * Prikaz_KursFDQueryN_FAC;
    TSmallintField      * Prikaz_KursFDQueryN_KURS;
    TSmallintField      * Prikaz_KursFDQueryN_PRIKAZ_KURS;
    TSmallintField      * Prikaz_KursFDQueryVID_EDU;
    TSmallintField      * Prikaz_LikvidFDQueryFAC_DO;
    TSmallintField      * Prikaz_LikvidFDQueryFAC_PO;
    TSmallintField      * Prikaz_LikvidFDQueryKURS_DO;
    TSmallintField      * Prikaz_LikvidFDQueryKURS_PO;
    TSmallintField      * Prikaz_LikvidFDQueryN_FOUND_DO;
    TSmallintField      * Prikaz_LikvidFDQueryN_FOUND_PO;
    TSmallintField      * Prikaz_LikvidFDQueryN_TYPE_LIKVID;
    TSmallintField      * Prikaz_LikvidFDQuerySPECIALIZ_DO;
    TSmallintField      * Prikaz_LikvidFDQuerySPECIALIZ_PO;
    TSmallintField      * Prikaz_LikvidFDQuerySTATUS_NOMER;
    TSmallintField      * Prikaz_LikvidFDQueryVID_EDU_DO;
    TSmallintField      * Prikaz_LikvidFDQueryVID_EDU_PO;
    TSmallintField      * Prikaz_LikvidFDQueryYEAR_UCH;
    TSmallintField      * Priv_AddFDQueryINC_GROUP;
    TSmallintField      * Priv_AddFDQueryKURS;
    TSmallintField      * Priv_AddFDQueryN_FAC;
    TSmallintField      * Priv_AddFDQuerySTATUS_PEOPLE;
    TSmallintField      * Priv_AddFDQueryUCH_GOD;
    TSmallintField      * Priv_AddFDQueryVID_EDU;
    TSmallintField      * Priv_AddFDQueryVID_PRIV;
    TSmallintField      * PrivFDQueryKURS;
    TSmallintField      * PrivFDQueryN_FAC;
    TSmallintField      * PrivFDQueryUCH_GOD;
    TSmallintField      * PrivFDQueryVID_EDU;
    TSmallintField      * Public_PrikazFDQueryN_PUBLIC_PRIKAZ;
    TSmallintField      * Public_PrikazFDQueryN_TYPE;
    TSmallintField      * Publik_PrikazFDQueryN_PUBLIC_PRIKAZ;
    TSmallintField      * Publik_PrikazFDQueryN_TYPE;
    TSmallintField      * Rating_BallFDQuerySEMESTR;
    TSmallintField      * Rating_BallFDQuerySESSION;
    TSmallintField      * Rating_BallFDQueryUCH_GOD;
    TSmallintField      * Rating_BallFDQueryVID_EDU;
    TSmallintField      * Rating_GridFDQuerySEMESTR;
    TSmallintField      * Rating_GridFDQuerySESSION;
    TSmallintField      * Rating_GridFDQueryUCH_GOD;
    TSmallintField      * Rating_GridFDQueryVID_EDU;
    TSmallintField      * Rating_ReportFDQuerySEMESTR;
    TSmallintField      * Rating_ReportFDQuerySESSION;
    TSmallintField      * Rating_ReportFDQueryUCH_GOD;
    TSmallintField      * Rating_ReportFDQueryVID_EDU;
    TSmallintField      * Rating_SearchFDQuerySEMESTR;
    TSmallintField      * Rating_SearchFDQuerySESSION;
    TSmallintField      * Rating_SearchFDQueryUCH_GOD;
    TSmallintField      * Rating_SearchFDQueryVID_EDU;
    TSmallintField      * Region_CentreFDQueryFLAG;
    TSmallintField      * Region_CentreFDQueryN_CENTRE;
    TSmallintField      * Region_CentreFDQueryN_REGION;
    TSmallintField      * RegionFDTableN_REGION;
    TSmallintField      * RestoreFDQueryN_CAUSE_RESTORE;
    TSmallintField      * RestoreFDQueryN_PRIKAZ_RES;
    TSmallintField      * RestoreFDQueryVID_RESTORE;
    TSmallintField      * Result_Ball_For_VedFDQueryINC_GROUP;
    TSmallintField      * Result_Ball_For_VedFDQueryN_FAC;
    TSmallintField      * Result_Ball_For_VedFDQueryRESULT;
    TSmallintField      * Result_Ball_For_VedFDQuerySTATUS_PEOPLE;
    TSmallintField      * Result_Ball_For_VedFDQueryVID_EDU;
    TSmallintField      * Result_Ball_LocateFDQueryRESULT;
    TSmallintField      * Result_Ball_LocateFDQuerySTATUS_RESULT;
    TSmallintField      * Result_Ball_ThreeFDQueryRESULT;
    TSmallintField      * Result_Ball_ThreeFDQuerySEMESTR;
    TSmallintField      * Result_Ball_ThreeFDQuerySTATUS_RESULT;
    TSmallintField      * Result_BallFDQueryCLOCK_PLAN_ALL;
    TSmallintField      * Result_BallFDQueryN_FAC;
    TSmallintField      * Result_BallFDQueryN_OBJECT;
    TSmallintField      * Result_BallFDQueryRESULT;
    TSmallintField      * Result_BallFDQuerySEMESTR;
    TSmallintField      * Result_BallFDQuerySTATUS_RESULT;
    TSmallintField      * Result_BallFDQueryVID_EDU_PLAN;
    TSmallintField      * Result_BallFDQueryYEAR_PLAN;
    TSmallintField      * Result_BallFDQueryZACH_EXAM;
    TSmallintField      * Semestr_Kurs_NewFDQueryBALL;
    TSmallintField      * Semestr_KursFDQueryBALL;
    TSmallintField      * SessionFDQueryBALL;
    TSmallintField      * SessionFDQueryN_OBJECT;
    TSmallintField      * Spec_PlanFDQueryN_SPECIALIZ;
    TSmallintField      * Specializ_GroupFDQueryN_SPECIALIZ;
    TSmallintField      * SpecializFDQueryN_SPEC;
    TSmallintField      * SpecializFDQueryN_SPECIALIZ;
    TSmallintField      * Spisoc_All_StudFDQueryINC_GROUP;
    TSmallintField      * Spisoc_All_StudFDQuerySTATUS_PEOPLE;
    TSmallintField      * Spisoc_All_StudFDQueryVID_EDU;
    TSmallintField      * Spisoc_FDQueryINC_GROUP;
    TSmallintField      * Spisoc_FDQueryKURS;
    TSmallintField      * Spisoc_FDQueryN_FAC;
    TSmallintField      * Spisoc_FDQueryVID_EDU;
    TSmallintField      * SportFDQueryN_PRIKAZ_SPORT;
    TSmallintField      * SportFDQueryN_PRIKAZ_SUD;
    TSmallintField      * SportFDQueryN_VID_SPORT;
    TSmallintField      * SportFDQuerySPORT_CATEGORY;
    TSmallintField      * SportFDQuerySUD_CATEGORY;
    TSmallintField      * Statistic_Pass_MonthFDQueryN_CAUSE;
    TSmallintField      * Status_2FDQueryKURS;
    TSmallintField      * Status_2FDQueryN_FAC;
    TSmallintField      * Status_2FDQueryN_PRIKAZ_INCLUDE;
    TSmallintField      * Status_2FDQueryN_PRIKAZ_RES;
    TSmallintField      * Status_2FDQueryVID_EDU_INCLUDE;
    TSmallintField      * Status_2FDQueryVID_EDU;
    TSmallintField      * StudQKURS;
    TSmallintField      * StudQN_FAC;
    TSmallintField      * StudQN_SPECIALIZ;
    TSmallintField      * StudQSTATUS_PEOPLE;
    TSmallintField      * StudQVID_EDU;
    TSmallintField      * Sub_Edu_PlanFDQueryCLASSROOM_HOURS;
    TSmallintField      * Sub_Edu_PlanFDQueryCLOCK_PLAN;
    TSmallintField      * Sub_Edu_PlanFDQueryIND_NUMB;
    TSmallintField      * Sub_Edu_PlanFDQueryLECTURE_HOURS;
    TSmallintField      * Sub_Edu_PlanFDQueryN_OBJECT;
    TSmallintField      * Sub_Edu_PlanFDQuerySEMINAR_HOURS;
    TSmallintField      * Type_EncourageFDQueryN_TYPE_EN;
    TSmallintField      * Type_EncourageFDQueryTYPE_EN;
    TSmallintField      * Type_LikvidFDQueryN_TYPE_LIKVID;
    TSmallintField      * Ved_exlistFDQueryN_FAC;
    TSmallintField      * Ved_exlistFDQueryN_VEDOMOST;
    TSmallintField      * Ved_exlistFDQuerySEMESTR_VED;
    TSmallintField      * Ved_exlistFDQuerySEMESTR;
    TSmallintField      * Ved_exlistFDQueryVID_EDU;
    TSmallintField      * Ved_exlistFDQueryYEAR_PLAN;
    TSmallintField      * Ved_Likvid_ReportFDQueryCLOCK_PLAN_ALL;
    TSmallintField      * Ved_Likvid_ReportFDQueryKURS;
    TSmallintField      * Ved_Likvid_ReportFDQueryN_FAC;
    TSmallintField      * Ved_Likvid_ReportFDQueryN_VEDOMOST;
    TSmallintField      * Ved_Likvid_ReportFDQuerySEMESTR_VED;
    TSmallintField      * Ved_Likvid_ReportFDQuerySTATUS_NOMER;
    TSmallintField      * Ved_Likvid_ReportFDQuerySTATUS;
    TSmallintField      * Ved_Likvid_ReportFDQueryVID_EDU_PLAN;
    TSmallintField      * Ved_Likvid_ReportFDQueryYEAR_PLAN;
    TSmallintField      * Ved_Likvid_ReportFDQueryYEAR_UCH;
    TSmallintField      * Ved_Likvid_ReportFDQueryZACH_EXAM;
    TSmallintField      * Ved_LikvidGridFDQueryBALL;
    TSmallintField      * Ved_LikvidGridFDQueryKURS;
    TSmallintField      * Ved_LikvidGridFDQueryN_FAC;
    TSmallintField      * Ved_LikvidGridFDQueryN_VEDOMOST;
    TSmallintField      * Ved_LikvidGridFDQuerySEMESTR_VED;
    TSmallintField      * Ved_LikvidGridFDQuerySTATUS_NOMER;
    TSmallintField      * Ved_LikvidGridFDQuerySTATUS;
    TSmallintField      * Ved_LikvidGridFDQueryVID_EDU_PLAN;
    TSmallintField      * Ved_LikvidGridFDQueryYEAR_PLAN;
    TSmallintField      * Ved_LikvidGridFDQueryYEAR_UCH;
    TSmallintField      * Ved_LikvidGridFDQueryZACH_EXAM;
    TSmallintField      * Ved_RatingFDQuerySEMESTR;
    TSmallintField      * Ved_RatingFDQuerySESSION;
    TSmallintField      * Ved_RatingFDQueryUCH_GOD;
    TSmallintField      * Ved_RatingFDQueryVID_EDU;
    TSmallintField      * Ved_Raznica_People_CaseFDQueryFAC_PO;
    TSmallintField      * Ved_Raznica_People_CaseFDQueryKURS_PO;
    TSmallintField      * Ved_Raznica_People_CaseFDQueryN_FOUND_PO;
    TSmallintField      * Ved_Raznica_People_CaseFDQuerySPECIALIZ_PO;
    TSmallintField      * Ved_Raznica_People_CaseFDQuerySTATUS_NOMER;
    TSmallintField      * Ved_Raznica_People_CaseFDQueryVID_EDU_PO;
    TSmallintField      * Ved_Raznica_People_CaseFDQueryYEAR_UCH;
    TSmallintField      * Ved_RaznicaFDQueryKURS;
    TSmallintField      * Ved_RaznicaFDQueryN_FAC;
    TSmallintField      * Ved_RaznicaFDQueryN_VEDOMOST;
    TSmallintField      * Ved_RaznicaFDQuerySEMESTR_VED;
    TSmallintField      * Ved_RaznicaFDQuerySTATUS_NOMER;
    TSmallintField      * Ved_RaznicaFDQuerySTATUS;
    TSmallintField      * Ved_RaznicaFDQueryYEAR_UCH;
    TSmallintField      * VedJournalN_VEDOMOST;
    TSmallintField      * VedListJournalN_VEDOMOST;
    TSmallintField      * Vedomost_GEKFDQueryN_FAC;
    TSmallintField      * Vedomost_GEKFDQueryN_VEDOMOST;
    TSmallintField      * Vedomost_ReportFDQueryCLOCK_PLAN_ALL;
    TSmallintField      * Vedomost_ReportFDQueryN_FAC;
    TSmallintField      * Vedomost_ReportFDQueryN_SPECIALIZ;
    TSmallintField      * Vedomost_ReportFDQueryN_VEDOMOST;
    TSmallintField      * Vedomost_ReportFDQuerySEMESTR_VED;
    TSmallintField      * Vedomost_ReportFDQuerySTATUS;
    TSmallintField      * Vedomost_ReportFDQueryVID_EDU;
    TSmallintField      * Vedomost_ReportFDQueryYEAR_PLAN;
    TSmallintField      * Vedomost_ReportFDQueryZACH_EXAM;
    TSmallintField      * Vedomost2FDQueryINC_GROUP;
    TSmallintField      * Vedomost2FDQueryN_FAC;
    TSmallintField      * Vedomost2FDQueryN_SPECIALIZ;
    TSmallintField      * Vedomost2FDQueryN_VEDOMOST;
    TSmallintField      * Vedomost2FDQuerySEMESTR_VED;
    TSmallintField      * Vedomost2FDQuerySTATUS;
    TSmallintField      * Vedomost2FDQueryVID_EDU_PLAN;
    TSmallintField      * Vedomost2FDQueryYEAR_PLAN;
    TSmallintField      * VedomostFDQueryINC_GROUP;
    TSmallintField      * VedomostFDQueryINVALID;
    TSmallintField      * VedomostFDQueryN_FAC;
    TSmallintField      * VedomostFDQueryN_SPECIALIZ;
    TSmallintField      * VedomostFDQueryN_VEDOMOST;
    TSmallintField      * VedomostFDQuerySEMESTR_VED;
    TSmallintField      * VedomostFDQuerySTATUS;
    TSmallintField      * VedomostFDQueryVID_EDU_PLAN;
    TSmallintField      * VedomostFDQueryYEAR_PLAN;
    TSmallintField      * VipuskFDQueryINC_GROUP;
    TSmallintField      * VipuskFDQueryKURS;
    TSmallintField      * VipuskFDQueryN_FAC;
    TSmallintField      * VipuskFDQuerySTATUS_PEOPLE;
    TSmallintField      * VipuskFDQueryVID_EDU;
    TSmallintField      * Zachetka_All_KursFDQueryINC_GROUP;
    TSmallintField      * ZachetkaFDQueryINC_GROUP;
    TSmallintField      * ZachetkaFDQueryN_SPECIALIZ;

    TSQLTimeStampField  * Ball_FDQueryD_EXAM;
    TSQLTimeStampField  * Diplom_Prikaz_vipuskFDQueryD_PRIKAZ_KURS;
    TSQLTimeStampField  * DiplomREGExcelFDQueryD_PRIKAZ_INCLUDE;
    TSQLTimeStampField  * DiplomREGExcelFDQueryD_PRIKAZ_KURS;
    TSQLTimeStampField  * DiplomREGExcelFDQueryD_PROTOKOL;
    TSQLTimeStampField  * DiplomREGExcelFDQueryD_PUBLIC_PRIKAZ;
    TSQLTimeStampField  * DiplomREGExcelFDQueryD_VIPUSK;
    TSQLTimeStampField  * DiplomREGExcelFDQueryDATA_R;
    TSQLTimeStampField  * DiplomREGExcelFDQueryDATE_GIVE;
    TSQLTimeStampField  * DiplomREGFDQueryD_PRIKAZ_INCLUDE;
    TSQLTimeStampField  * DiplomREGFDQueryD_PRIKAZ_KURS;
    TSQLTimeStampField  * DiplomREGFDQueryD_PROTOKOL;
    TSQLTimeStampField  * DiplomREGFDQueryD_PUBLIC_PRIKAZ;
    TSQLTimeStampField  * DiplomREGFDQueryD_VIPUSK;
    TSQLTimeStampField  * DiplomREGFDQueryDATA_R;
    TSQLTimeStampField  * DiplomREGFDQueryDATE_GIVE;
    TSQLTimeStampField  * Edu_CardFDQueryD_EXAM;
    TSQLTimeStampField  * EncourageFDQueryD_PRIKAZ;
    TSQLTimeStampField  * GEKFDQueryD_GEK;
    TSQLTimeStampField  * GEKFDQueryD_PROTOCOL;
    TSQLTimeStampField  * GEKResultBallFDQueryD_GEK;
    TSQLTimeStampField  * GEKResultBallFDQueryD_PROTOCOL;
    TSQLTimeStampField  * HolidayFDQueryD_BEGIN_HOL;
    TSQLTimeStampField  * HolidayFDQueryD_END_HOL;
    TSQLTimeStampField  * HolidayFDQueryD_PRIKAZ_HOL;
    TSQLTimeStampField  * LikvidFDQueryDATE_C;
    TSQLTimeStampField  * LikvidFDQueryDATE_PO;
    TSQLTimeStampField  * PasportFDQDATE_GIVE;
    TSQLTimeStampField  * PasportFDQDATE_VALID;
    TSQLTimeStampField  * PassFDQueryD_PASS;
    TSQLTimeStampField  * People_SpravkiFDQueryD_PRIKAZ_INCLUDE;
    TSQLTimeStampField  * People_VedFDQueryD_EXAM;
    TSQLTimeStampField  * PeopleFDQueryD_INCLUDE;
    TSQLTimeStampField  * PeopleFDQueryD_PRIKAZ_INCLUDE;
    TSQLTimeStampField  * PeopleFDQueryD_PRIKAZ_KURS;
    TSQLTimeStampField  * PeopleFDQueryDATA_R;
    TSQLTimeStampField  * PeopleFDQueryDATE_END;
    TSQLTimeStampField  * PeopleUpFDQueryD_INCLUDE;
    TSQLTimeStampField  * PeopleUpFDQueryD_PRIKAZ_KURS;
    TSQLTimeStampField  * PeopleUpFDQueryDATA_R;
    TSQLTimeStampField  * PeopleUpFDQueryDATE_END;
    TSQLTimeStampField  * Prikaz_KursFDQueryD_PRIKAZ_KURS;
    TSQLTimeStampField  * Prikaz_LikvidFDQueryDATE_C;
    TSQLTimeStampField  * Prikaz_LikvidFDQueryDATE_PO;
    TSQLTimeStampField  * Priv_AddFDQueryDATA_C;
    TSQLTimeStampField  * Priv_AddFDQueryDATA_PO;
    TSQLTimeStampField  * PrivFDQueryDATA_C;
    TSQLTimeStampField  * PrivFDQueryDATA_PO;
    TSQLTimeStampField  * Public_PrikazFDQueryD_PUBLIC_PRIKAZ;
    TSQLTimeStampField  * Publik_PrikazFDQueryD_PUBLIC_PRIKAZ;
    TSQLTimeStampField  * Rating_GridFDQueryD_VED;
    TSQLTimeStampField  * Rating_GridFDQueryEND_D_VED;
    TSQLTimeStampField  * Rating_ReportFDQueryD_VED;
    TSQLTimeStampField  * Rating_ReportFDQueryEND_D_VED;
    TSQLTimeStampField  * RestoreFDQueryD_PRIKAZ_RES;
    TSQLTimeStampField  * Result_Ball_LocateFDQueryDATE_RESULT;
    TSQLTimeStampField  * Result_Ball_ThreeFDQueryDATE_RESULT;
    TSQLTimeStampField  * Result_BallFDQueryDATE_RESULT;
    TSQLTimeStampField  * Semestr_KursFDQueryD_EXAM;
    TSQLTimeStampField  * Spisoc_All_StudFDQueryDATA_R;
    TSQLTimeStampField  * SportFDQueryD_PRIKAZ_SPORT;
    TSQLTimeStampField  * SportFDQueryD_PRIKAZ_SUD;
    TSQLTimeStampField  * Status_2FDQueryD_PRIKAZ_INCLUDE;
    TSQLTimeStampField  * Status_2FDQueryD_PRIKAZ_RES;
    TSQLTimeStampField  * Status_2FDQueryDATA_R;
    TSQLTimeStampField  * StudQD_PRIKAZ_INCLUDE;
    TSQLTimeStampField  * Ved_exlistFDQueryD_VED;
    TSQLTimeStampField  * Ved_exlistFDQueryEND_D_EXAM;
    TSQLTimeStampField  * Ved_Likvid_ReportFDQueryD_VED;
    TSQLTimeStampField  * Ved_Likvid_ReportFDQueryEND_D_EXAM;
    TSQLTimeStampField  * Ved_LikvidGridFDQueryD_EXAM;
    TSQLTimeStampField  * Ved_LikvidGridFDQueryD_VED;
    TSQLTimeStampField  * Ved_LikvidGridFDQueryEND_D_EXAM;
    TSQLTimeStampField  * Ved_RatingFDQueryD_VED;
    TSQLTimeStampField  * Ved_RatingFDQueryEND_D_VED;
    TSQLTimeStampField  * Ved_Raznica_People_CaseFDQueryDATE_C;
    TSQLTimeStampField  * Ved_Raznica_People_CaseFDQueryDATE_PO;
    TSQLTimeStampField  * Ved_RaznicaFDQueryD_VED;
    TSQLTimeStampField  * Ved_RaznicaFDQueryEND_D_EXAM;
    TSQLTimeStampField  * VedJournalD_VED;
    TSQLTimeStampField  * VedListJournalD_VED;
    TSQLTimeStampField  * Vedomost_GEKFDQueryD_VED;
    TSQLTimeStampField  * Vedomost_ReportFDQueryD_VED;
    TSQLTimeStampField  * Vedomost_ReportFDQueryEND_D_EXAM;
    TSQLTimeStampField  * Vedomost2FDQueryD_VED;
    TSQLTimeStampField  * Vedomost2FDQueryEND_D_EXAM;
    TSQLTimeStampField  * VedomostFDQueryD_VED;
    TSQLTimeStampField  * VedomostFDQueryEND_D_EXAM;
    TSQLTimeStampField  * VipuskFDQueryD_PRIKAZ_KURS;
    TSQLTimeStampField  * ZachetkaFDQueryD_PRIKAZ_INCLUDE;

    TStringField        * Ball_FDQueryBALL1;
    TStringField        * Ball_FDQueryFAM;
    TStringField        * Ball_FDQueryNAME_OBJECT;
    TStringField        * Ball_FDQueryNAME;
    TStringField        * Ball_FDQueryOTCH;
    TStringField        * CK_FDQueryCENTRE;
    TStringField        * CK_FDQueryFIO;
    TStringField        * CK_FDQueryN_GROUP;
    TStringField        * CK_FDQuerySPECIAL;
    TStringField        * CK_SearchFDQNOTE;
    TStringField        * Count_ObjectFDQueryNAME_OBJECT;
    TStringField        * Count_People_GroupFDQueryN_GROUP;
    TStringField        * Delete_IncrementFDQueryN_GROUP;
    TStringField        * Diplom_Prikaz_vipuskFDQueryFAM;
    TStringField        * Diplom_Prikaz_vipuskFDQueryN_GROUP;
    TStringField        * Diplom_Prikaz_vipuskFDQueryNAME;
    TStringField        * Diplom_Prikaz_vipuskFDQueryOTCH;
    TStringField        * DiplomREGExcelFDQueryFAM;
    TStringField        * DiplomREGExcelFDQueryN_DIPLOM;
    TStringField        * DiplomREGExcelFDQueryN_ZACHET;
    TStringField        * DiplomREGExcelFDQueryNAME;
    TStringField        * DiplomREGExcelFDQueryNOM_DIPLOM;
    TStringField        * DiplomREGExcelFDQueryNUMBER;
    TStringField        * DiplomREGExcelFDQueryOTCH;
    TStringField        * DiplomREGExcelFDQueryPERSONAL_NUMBER;
    TStringField        * DiplomREGExcelFDQueryQUALIFICATION;
    TStringField        * DiplomREGExcelFDQueryREGISTRATION;
    TStringField        * DiplomREGExcelFDQuerySERIA;
    TStringField        * DiplomREGExcelFDQuerySERIES;
    TStringField        * DiplomREGExcelFDQueryWHO_GIVE;
    TStringField        * DiplomREGFDQueryFAM;
    TStringField        * DiplomREGFDQueryN_DIPLOM;
    TStringField        * DiplomREGFDQueryN_ZACHET;
    TStringField        * DiplomREGFDQueryNAME;
    TStringField        * DiplomREGFDQueryNOM_DIPLOM;
    TStringField        * DiplomREGFDQueryNUMBER;
    TStringField        * DiplomREGFDQueryOTCH;
    TStringField        * DiplomREGFDQueryPERSONAL_NUMBER;
    TStringField        * DiplomREGFDQueryQUALIFICATION;
    TStringField        * DiplomREGFDQueryREGISTRATION;
    TStringField        * DiplomREGFDQuerySERIA;
    TStringField        * DiplomREGFDQuerySERIES;
    TStringField        * DiplomREGFDQueryWHO_GIVE;
    TStringField        * Edu_PlanFDQNAME_OBJECT;
    TStringField        * Edu_PlanFDQPP;
    TStringField        * Edu_PlanFDQueryNAME_OBJECT;
    TStringField        * Edu_PlanFDQueryNAME_PLAN;
    TStringField        * Edu_PlanFDQueryZACH_EXAM1;
    TStringField        * EncourageFDQueryVID_EN;
    TStringField        * EncourageFDQueryWHAT;
    TStringField        * EncourageFDQueryWHO_TAKE;
    TStringField        * Fac_AllFDQueryCAUSE;
    TStringField        * FacFullFDQFAC;
    TStringField        * FacultyFDTableDEAN;
    TStringField        * FacultyFDTableFAC_PP;
    TStringField        * FacultyFDTableFAC_RP;
    TStringField        * FacultyFDTableFAC;
    TStringField        * FacultyFDTableFAC1;
    TStringField        * FacultyFDTableFAC2;
    TStringField        * FoundationFDTableVID_FOUND;
    TStringField        * GEKFDQueryTHEME;
    TStringField        * GEKResultBallFDQueryTHEME;
    TStringField        * Group_AllFDQueryCAUSE;
    TStringField        * Group_AllFDQueryFAM;
    TStringField        * Group_AllFDQueryN_GROUP;
    TStringField        * Group_AllFDQueryNAME;
    TStringField        * Group_AllFDQueryOTCH;
    TStringField        * HolidayFDQueryCAUSE_HOL;
    TStringField        * HolidayFDQueryTYPE_HOL1;
    TStringField        * Inc_Group_OldFDQueryDESCRIBE;
    TStringField        * Inc_Group_OldFDQueryN_GROUP;
    TStringField        * Inc_Group_SemestrFDQueryN_GROUP;
    TStringField        * Increment_GroupFDQueryN_GROUP;
    TStringField        * Integr_modulFDQueryNAME_OBJECT;
    TStringField        * Kafedra_SpecFDQueryNOTE;
    TStringField        * Kafedra_SpecFDQuerySPECIAL;
    TStringField        * KafedraFDQueryNAME_KAFEDRA;
    TStringField        * KafedraFDQueryNOTE;
    TStringField        * Kurs_AllFDQueryCAUSE;
    TStringField        * Kurs_AllFDQueryN_GROUP;
    TStringField        * LangvFDQueryFIO;
    TStringField        * LangvFDQueryLANGV;
    TStringField        * LangvFDQueryN_GROUP;
    TStringField        * LangvFDQueryNAME_EDUC;
    TStringField        * LangvFDQuerySPECIAL;
    TStringField        * LangvFDQueryWHERE_EDUC;
    TStringField        * LikvidFDQueryDESCRIBE;
    TStringField        * LikvidFDQueryFIO;
    TStringField        * LikvidFDQueryPRIKAZ;
    TStringField        * LikvidFDQueryTEXT_LIKVID;
    TStringField        * Max_ZachetkaFDQueryMAX;
    TStringField        * PasportFDQNOTE;
    TStringField        * PasportFDQNUMBER;
    TStringField        * PasportFDQPERSONAL_NUMBER;
    TStringField        * PasportFDQSERIES;
    TStringField        * PasportFDQWHO_GIVE;
    TStringField        * PasportTypeFDQNAME_TYPE;
    TStringField        * People_CaseFDQueryFIO;
    TStringField        * People_CaseFDQueryN_GROUP;
    TStringField        * People_CaseFDQueryN_SPECIALIZ1;
    TStringField        * People_DogovorFDQueryFIO;
    TStringField        * People_DogovorFDQueryN_DOGOVOR;
    TStringField        * People_DogovorFDQueryN_GROUP;
    TStringField        * People_DogovorFDQueryN_ZACHET;
    TStringField        * People_DogovorFDQuerySPECIAL;
    TStringField        * People_EduCardFDQueryFAM;
    TStringField        * People_EduCardFDQueryN_GROUP;
    TStringField        * People_EduCardFDQueryNAME;
    TStringField        * People_EduCardFDQueryOTCH;
    TStringField        * People_HostelFDQueryADDRESS;
    TStringField        * People_HostelFDQueryFIO;
    TStringField        * People_HostelFDQueryN_GROUP;
    TStringField        * People_HostelFDQuerySPECIAL;
    TStringField        * People_HostelFDQueryTEXT_REGION;
    TStringField        * People_KursFDQueryFAM;
    TStringField        * People_KursFDQueryN_GROUP;
    TStringField        * People_KursFDQueryNAME;
    TStringField        * People_KursFDQueryOTCH;
    TStringField        * People_PartFDQueryFAM;
    TStringField        * People_PartFDQueryN_GROUP;
    TStringField        * People_PartFDQueryNAME;
    TStringField        * People_PartFDQueryOTCH;
    TStringField        * People_SpecializFDQueryFAM;
    TStringField        * People_SpecializFDQueryN_GROUP;
    TStringField        * People_SpecializFDQueryNAME;
    TStringField        * People_SpecializFDQueryOTCH;
    TStringField        * People_SpecializFDQuerySPECIAL;
    TStringField        * People_SpravkiFDQueryFAM;
    TStringField        * People_SpravkiFDQueryFIO;
    TStringField        * People_SpravkiFDQueryN_GROUP;
    TStringField        * People_SpravkiFDQueryNAME;
    TStringField        * People_SpravkiFDQueryOTCH;
    TStringField        * People_VedFDQueryBALL1;
    TStringField        * People_VedFDQueryFIO_EXAM;
    TStringField        * People_VedFDQueryNAME_OBJECT;
    TStringField        * People_VedFDQueryYEAR1;
    TStringField        * People_VedFDQueryZACH_EXAM1;
    TStringField        * PeopleFDQueryADDRESS_BEFORE;
    TStringField        * PeopleFDQueryADDRESS_LIFE;
    TStringField        * PeopleFDQueryADDRESS;
    TStringField        * PeopleFDQueryEDU_WORK;
    TStringField        * PeopleFDQueryF_OLD;
    TStringField        * PeopleFDQueryFAM;
    TStringField        * PeopleFDQueryHOUSE;
    TStringField        * PeopleFDQueryMAMA;
    TStringField        * PeopleFDQueryN_DOGOVOR;
    TStringField        * PeopleFDQueryN_FOUND1;
    TStringField        * PeopleFDQueryN_GROUP;
    TStringField        * PeopleFDQueryN_VID_SPORT1;
    TStringField        * PeopleFDQueryN_ZACHET;
    TStringField        * PeopleFDQueryNAME_EDUC;
    TStringField        * PeopleFDQueryNAME;
    TStringField        * PeopleFDQueryNAZ;
    TStringField        * PeopleFDQueryOTCH;
    TStringField        * PeopleFDQueryPAPA;
    TStringField        * PeopleFDQueryPASPORT;
    TStringField        * PeopleFDQueryPERSONAL_NOMER;
    TStringField        * PeopleFDQueryPHONE;
    TStringField        * PeopleFDQueryPOL;
    TStringField        * PeopleFDQuerySPECIALIZ1;
    TStringField        * PeopleFDQueryVID_EDU1;
    TStringField        * PeopleFDQueryWHERE_EDUC;
    TStringField        * PeopleFDQueryWORK_BEFORE;
    TStringField        * PeopleUpFDQueryF_OLD;
    TStringField        * PeopleUpFDQueryFAM;
    TStringField        * PeopleUpFDQueryFIO;
    TStringField        * PeopleUpFDQueryN_GROUP;
    TStringField        * PeopleUpFDQueryNAME;
    TStringField        * PeopleUpFDQueryOTCH;
    TStringField        * Prikaz_KursFDQueryN_FAC1;
    TStringField        * Prikaz_KursFDQueryVID_EDU1;
    TStringField        * Prikaz_LikvidFDQueryDESCRIBE;
    TStringField        * Prikaz_LikvidFDQueryPRIKAZ;
    TStringField        * Priv_AddFDQueryDESCRIBE;
    TStringField        * Priv_AddFDQueryDOC_PRIV;
    TStringField        * Priv_AddFDQueryFAM;
    TStringField        * Priv_AddFDQueryN_GROUP;
    TStringField        * Priv_AddFDQueryNAME;
    TStringField        * Priv_AddFDQueryOTCH;
    TStringField        * Priv_AddFDQueryTEXT_PRIV;
    TStringField        * PrivFDQueryADDRESS_BEFORE;
    TStringField        * PrivFDQueryDESCRIBE;
    TStringField        * PrivFDQueryDOC_PRIV;
    TStringField        * PrivFDQueryFIO;
    TStringField        * PrivFDQueryN_GROUP;
    TStringField        * PrivFDQuerySPECIAL;
    TStringField        * PrivFDQueryTEXT_PRIV;
    TStringField        * Public_PrikazFDQueryDESCRIBE;
    TStringField        * Public_PrikazFDQueryN_TYPE1;
    TStringField        * Publik_PrikazFDQueryDESCRIBE;
    TStringField        * QAdressNAME_DISTRICT;
    TStringField        * QAdressNAME_LOCALITY;
    TStringField        * QAdressNAME_TYPE;
    TStringField        * QAdressTYPE;
    TStringField        * QDistrictNAME_DISTRICT;
    TStringField        * QLocalityNAME_LOCALITY;
    TStringField        * QStreetNAME_IN_RUS;
    TStringField        * QType_localityNAME_TYPE;
    TStringField        * QType_localitySHORT_TYPE_NAME;
    TStringField        * QType_streetSHORT_TYPE;
    TStringField        * QType_streetTYPE;
    TStringField        * QueueFDQueryCONCATENATION;
    TStringField        * QueueFDQueryFAM;
    TStringField        * QueueFDQueryNAME;
    TStringField        * QueueFDQueryOTCH;
    TStringField        * Rating_BallFDQueryFAM;
    TStringField        * Rating_BallFDQueryFIO;
    TStringField        * Rating_BallFDQueryN_GROUP;
    TStringField        * Rating_BallFDQueryNAME;
    TStringField        * Rating_BallFDQueryOTCH;
    TStringField        * Rating_BallFDQuerySPECIAL;
    TStringField        * Rating_GridFDQueryCURATOR;
    TStringField        * Rating_GridFDQueryFAC1;
    TStringField        * Rating_GridFDQueryN_GROUP;
    TStringField        * Rating_GridFDQuerySPECIAL;
    TStringField        * Rating_ReportFDQueryCURATOR;
    TStringField        * Rating_ReportFDQueryFAC1;
    TStringField        * Rating_ReportFDQueryFAM;
    TStringField        * Rating_ReportFDQueryFIO;
    TStringField        * Rating_ReportFDQueryN_GROUP;
    TStringField        * Rating_ReportFDQueryNAME;
    TStringField        * Rating_ReportFDQueryOTCH;
    TStringField        * Rating_ReportFDQuerySPECIAL;
    TStringField        * Region_CentreFDQueryCENTRE;
    TStringField        * RegionFDTableTEXT_REGION;
    TStringField        * RestoreFDQueryDESCRIBE;
    TStringField        * RestoreFDQueryN_CAUSE_RESTORE1;
    TStringField        * RestoreFDQueryVID_RESTORE1;
    TStringField        * Result_Ball_For_VedFDQueryFAM;
    TStringField        * Result_Ball_For_VedFDQueryN_GROUP;
    TStringField        * Result_Ball_For_VedFDQueryNAME;
    TStringField        * Result_Ball_For_VedFDQueryOTCH;
    TStringField        * Result_Ball_ThreeFDQueryNAME_OBJECT;
    TStringField        * Result_BallFDQueryN_FAC1;
    TStringField        * Result_BallFDQueryNAME_OBJECT;
    TStringField        * Result_BallFDQueryRESULT1;
    TStringField        * Result_BallFDQuerySTATUS_RESULT1;
    TStringField        * Result_BallFDQueryVID_EDU_PLAN1;
    TStringField        * Result_BallFDQueryYEAR_PLAN1;
    TStringField        * SessionFDQueryFAM;
    TStringField        * SessionFDQueryNAME_OBJECT;
    TStringField        * SessionFDQueryNAME;
    TStringField        * SessionFDQueryOTCH;
    TStringField        * Spec_PlanFDQueryDESCRIBE;
    TStringField        * Spec_PlanFDQuerySPECIAL;
    TStringField        * SpecializFDQuerySPECIAL_DIRECTION;
    TStringField        * SpecializFDQuerySPECIAL_SKLON;
    TStringField        * SpecializFDQuerySPECIAL;
    TStringField        * Spisoc_All_StudFDQueryADDRESS_BEFORE;
    TStringField        * Spisoc_All_StudFDQueryFAM;
    TStringField        * Spisoc_All_StudFDQueryN_GR;
    TStringField        * Spisoc_All_StudFDQueryN_GROUP;
    TStringField        * Spisoc_All_StudFDQueryNAME;
    TStringField        * Spisoc_All_StudFDQueryOTCH;
    TStringField        * Spisoc_All_StudFDQueryPHONE;
    TStringField        * Spisoc_All_StudFDQueryPOL;
    TStringField        * Spisoc_All_StudFDQuerySPECIAL;
    TStringField        * Spisoc_All_StudFDQueryTEXT_SPORT_CATEGORY;
    TStringField        * Spisoc_All_StudFDQueryVID_FOUND;
    TStringField        * Spisoc_All_StudFDQueryVID_SPORT;
    TStringField        * Spisoc_FDQueryFAM;
    TStringField        * Spisoc_FDQueryN_GROUP;
    TStringField        * Spisoc_FDQueryNAME;
    TStringField        * Spisoc_FDQueryOTCH;
    TStringField        * SportFDQuerySPORT_CATEGORY1;
    TStringField        * SportFDQuerySUD_CATEGORY1;
    TStringField        * SportFDQueryVID_SPORT1;
    TStringField        * SportFDQueryWHO_GIVE_SUD;
    TStringField        * SportFDQueryWHO_GIVE;
    TStringField        * Status_2FDQueryADDRESS_BEFORE;
    TStringField        * Status_2FDQueryADDRESS;
    TStringField        * Status_2FDQueryCAUSE_RES;
    TStringField        * Status_2FDQueryDESCRIBE;
    TStringField        * Status_2FDQueryF_OLD;
    TStringField        * Status_2FDQueryFIO;
    TStringField        * Status_2FDQueryMAMA;
    TStringField        * Status_2FDQueryN_GROUP;
    TStringField        * Status_2FDQueryPAPA;
    TStringField        * Status_2FDQuerySPECIAL;
    TStringField        * StudQFAM;
    TStringField        * StudQGRAGDAN;
    TStringField        * StudQN_GROUP;
    TStringField        * StudQN_ZACHET;
    TStringField        * StudQNAME;
    TStringField        * StudQOTCH;
    TStringField        * StudQPASPORT;
    TStringField        * StudQPERSONAL_NOMER;
    TStringField        * StudQPOL;
    TStringField        * Type_EncourageFDQueryVID_EN;
    TStringField        * Type_LikvidFDQueryTEXT_LIKVID;
    TStringField        * Ved_exlistFDQueryFAM;
    TStringField        * Ved_exlistFDQueryFIO_EXAM;
    TStringField        * Ved_exlistFDQueryN_GROUP;
    TStringField        * Ved_exlistFDQueryNAME_OBJECT;
    TStringField        * Ved_exlistFDQueryNAME;
    TStringField        * Ved_exlistFDQueryOTCH;
    TStringField        * Ved_exlistFDQueryVID_EDU1;
    TStringField        * Ved_Likvid_ReportFDQueryFIO_EXAM;
    TStringField        * Ved_Likvid_ReportFDQueryFIO;
    TStringField        * Ved_Likvid_ReportFDQueryN_GROUP;
    TStringField        * Ved_Likvid_ReportFDQueryN_ZACHET;
    TStringField        * Ved_Likvid_ReportFDQueryNAME_OBJECT;
    TStringField        * Ved_LikvidGridFDQueryBALL1;
    TStringField        * Ved_LikvidGridFDQueryFIO_EXAM;
    TStringField        * Ved_LikvidGridFDQueryFIO;
    TStringField        * Ved_LikvidGridFDQueryNAME_OBJECT;
    TStringField        * Ved_LikvidGridFDQueryVID_EDU_PLAN1;
    TStringField        * Ved_RatingFDQueryCURATOR;
    TStringField        * Ved_Raznica_People_CaseFDQueryFIO;
    TStringField        * Ved_RaznicaFDQueryFIO_EXAM;
    TStringField        * VedJournalFIO_EXAM;
    TStringField        * VedJournalN_GROUP;
    TStringField        * VedJournalNAME_OBJECT;
    TStringField        * VedListJournalFIO_EXAM;
    TStringField        * VedListJournalFIO;
    TStringField        * VedListJournalN_GROUP;
    TStringField        * VedListJournalNAME_OBJECT;
    TStringField        * Vedomost_GEKFDQueryINC_GROUP;
    TStringField        * Vedomost_GEKFDQueryN_GROUP_SP;
    TStringField        * Vedomost_ReportFDQueryFAC;
    TStringField        * Vedomost_ReportFDQueryFAM;
    TStringField        * Vedomost_ReportFDQueryFIO_EXAM;
    TStringField        * Vedomost_ReportFDQueryN_GROUP;
    TStringField        * Vedomost_ReportFDQueryN_SPECIALIZ1;
    TStringField        * Vedomost_ReportFDQueryN_ZACHET;
    TStringField        * Vedomost_ReportFDQueryNAME_OBJECT;
    TStringField        * Vedomost_ReportFDQueryNAME;
    TStringField        * Vedomost_ReportFDQueryOTCH;
    TStringField        * Vedomost2FDQueryFIO_EXAM;
    TStringField        * Vedomost2FDQueryNAME_OBJECT;
    TStringField        * VedomostFDQueryFIO_EXAM;
    // TStringField        * VedomostFDQueryN_GROUP1;
    TStringField        * VedomostFDQueryN_SPECIALIZ1;
    TStringField        * VedomostFDQueryNAME_OBJECT;
    TStringField        * VedomostFDQuerySTATUS1;
    TStringField        * VedomostFDQueryVID_EDU_PLAN1;
    TStringField        * VipuskFDQueryFAM;
    TStringField        * VipuskFDQueryN_GROUP;
    TStringField        * VipuskFDQueryNAME;
    TStringField        * VipuskFDQueryOTCH;
    TStringField        * Zachetka_All_KursFDQueryFAM;
    TStringField        * Zachetka_All_KursFDQueryN_GROUP;
    TStringField        * Zachetka_All_KursFDQueryN_ZACHET;
    TStringField        * Zachetka_All_KursFDQueryNAME;
    TStringField        * Zachetka_All_KursFDQueryOTCH;
    TStringField        * ZachetkaFDQueryFAM;
    TStringField        * ZachetkaFDQueryN_GROUP;
    TStringField        * ZachetkaFDQueryN_ZACHET;
    TStringField        * ZachetkaFDQueryNAME;
    TStringField        * ZachetkaFDQueryOTCH;


    void __fastcall Ball_FDQueryCalcFields          (TDataSet * DataSet);
    void __fastcall Ball_Query2CalcFields           (TDataSet * DataSet);
    void __fastcall Edu_PlanFDQueryCalcFields       (TDataSet * DataSet);
    void __fastcall Edu_PlanQuery2CalcFields        (TDataSet * DataSet);
    void __fastcall EncourageFDQueryCalcFields      (TDataSet * DataSet);
    void __fastcall EncourageQuery2CalcFields       (TDataSet * DataSet);
    void __fastcall FacFullFDQCalcFields            (TDataSet * DataSet);
    void __fastcall HolidayFDQueryCalcFields        (TDataSet * DataSet);
    void __fastcall HolidayQuery2CalcFields         (TDataSet * DataSet);
    void __fastcall LikvidFDQueryCalcFields         (TDataSet * DataSet);
    void __fastcall LikvidQuery2CalcFields          (TDataSet * DataSet);
    void __fastcall People_SpravkiSourceDataChange  (
            TObject * Sender,
            TField  * Field
        );
    void __fastcall People_VedFDQueryCalcFields     (TDataSet * DataSet);
    void __fastcall People_VedQuery2CalcFields      (TDataSet * DataSet);
    void __fastcall PeopleFDQueryAfterInsert        (TDataSet * DataSet);
    void __fastcall PeopleFDQueryBeforePost         (TDataSet * DataSet);
    void __fastcall PeopleFDQueryCalcFields         (TDataSet * DataSet);
    void __fastcall PeopleFDQueryNewRecord          (TDataSet * DataSet);
    void __fastcall PeopleQSourceDataChange         (
            TObject * Sender,
            TField  * Field
        );
    void __fastcall PeopleQuery2AfterInsert         (TDataSet * DataSet);
    void __fastcall PeopleQuery2AfterScroll         (TDataSet * DataSet);
    void __fastcall PeopleQuery2CalcFields          (TDataSet * DataSet);
    void __fastcall PeopleQuery2NewRecord           (TDataSet * DataSet);
    void __fastcall PeopleUpFDQueryCalcFields       (TDataSet * DataSet);
    void __fastcall PeopleUpQuery2CalcFields        (TDataSet * DataSet);
    void __fastcall Prikaz_KursFDQueryCalcFields    (TDataSet * DataSet);
    void __fastcall Prikaz_KursQuery2CalcFields     (TDataSet * DataSet);
    void __fastcall Rating_BallFDQueryBeforePost    (TDataSet * DataSet);
    void __fastcall Rating_BallQuery2BeforePost     (TDataSet * DataSet);
    void __fastcall RegionFDTableNewRecord          (TDataSet * DataSet);
    void __fastcall RegionSourceDataChange          (
            TObject * Sender,
            TField  * Field
        );
    void __fastcall RestoreFDQueryCalcFields        (TDataSet * DataSet);
    void __fastcall RestoreQuery2CalcFields         (TDataSet * DataSet);
    void __fastcall Result_BallFDQueryCalcFields    (TDataSet * DataSet);
    void __fastcall Result_BallQuery2CalcFields     (TDataSet * DataSet);
    void __fastcall Spisoc_FDQueryCalcFields        (TDataSet * DataSet);
    void __fastcall Spisoc_Query2CalcFields         (TDataSet * DataSet);
    void __fastcall SportFDQueryCalcFields          (TDataSet * DataSet);
    void __fastcall SportQuery2CalcFields           (TDataSet * DataSet);
    void __fastcall Ved_exlistFDQueryCalcFields     (TDataSet * DataSet);
    void __fastcall Ved_exlistQuery2CalcFields      (TDataSet * DataSet);
    void __fastcall Ved_LikvidGridFDQueryCalcFields (TDataSet * DataSet);
    void __fastcall Ved_LikvidGridQuery2CalcFields  (TDataSet * DataSet);
    void __fastcall Ved_RatingFDQueryAfterInsert    (TDataSet * DataSet);
    void __fastcall Ved_RatingQuery2AfterInsert     (TDataSet * DataSet);
    void __fastcall Ved_RaznicaFDQueryAfterInsert   (TDataSet * DataSet);
    void __fastcall Ved_RaznicaQuery2AfterInsert    (TDataSet * DataSet);
    void __fastcall VedomostFDQueryAfterInsert      (TDataSet * DataSet);
    void __fastcall VedomostFDQueryCalcFields       (TDataSet * DataSet);
    void __fastcall VedomostQuery2AfterInsert       (TDataSet * DataSet);
    void __fastcall VedomostQuery2CalcFields        (TDataSet * DataSet);
private:
public:
    __fastcall TDataModule1 (TComponent * Owner);

    int  __fastcall vozvrat_inc_edu_plan    ();                                 // функция возвращает инкремент номера записи учебного плана
    void __fastcall Edit_Key                (char    & cyfra);                  // Как сделать, чтобы в TEdit можно было вводить только числа?
    void __fastcall ExAutoFit               (                                   // процедура установки автоматической ширины столбца
            int one,
            int two
        );
    void __fastcall ExBorder                (Variant   range);                  // функция обрамления
    void __fastcall ExelInit                ();                                 // функция запуска Excel
    void __fastcall ExelInitNoVisible       ();                                 // функция запуска Excel без показа книги
    int             Search_CK               (                                   // процедура поиска и изменения целевого контракта
            int        n_s,
            int        n_d,
            AnsiString n_prikaz,
            AnsiString date_prikaz
        );
    void __fastcall toEx                    (                                   // функция занесения данных в Excel
            int        Row,
            int        Column,
            AnsiString data
        );
    void __fastcall toEx                    (                                   // функция занесения данных в Excel
            int     Row,
            int     Column,
            Variant data
        );
    void __fastcall vozvrat_inc_people      ();                                 // возврат инкремента номера студента
    void __fastcall vozvrat_inc_ved_rating  ();                                 // возврат инкремента номера ведомости для рейтинга
    void __fastcall vozvrat_inc_ved_raznica ();                                 // возврат инкремента номера ведомости для ликвидации разницы
    void __fastcall vozvrat_inc_ved         ();                                 // возврат инкремента номера ведомости

    AnsiString testDB_str;
};

extern PACKAGE TDataModule1 * DataModule1;

#endif  // DATA_MODULE_H
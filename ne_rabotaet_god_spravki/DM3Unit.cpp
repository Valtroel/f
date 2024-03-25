#include <vcl.h>
#pragma hdrstop


#include "DataModule.h"
#include "DM2Unit.h"
#include "DM3Unit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TDM3 * DM3;


AnsiString SQL_rem = "                      \
    SELECT                                  \
        INC_GROUP,                          \
        VID_EDU,                            \
        N_GROUP                             \
    FROM                                    \
        INCREMENT_GROUP Increment_group     \
    WHERE                                   \
            VID_EDU = :VID_EDU              \
        AND                                 \
            (                               \
                N_GROUP LIKE (:N_GROUP_S)   \
             OR                             \
                N_GROUP LIKE (:N_GROUP_B)   \
            )                               \
    ORDER BY                                \
        N_GROUP                             \
    ";




// Check_Add_Group
// Check_Return_Group
// GEKResultGrid2CalcFields
// GEKResultGridFDQueryCalcFields
// Svod_Nado_toExcelFDQueryCalcFields
// Svod_Nado2CalcFields
// Svod_NadoFDQueryCalcFields
// VED_GEKGrid2CalcFields
// VED_GEKGridFDQueryCalcFields
// Vipuskniki2CalcFields
// VipusknikiFDQueryCalcFields




__fastcall TDM3::TDM3 (TComponent* Owner) : TDataModule (Owner) {
}

void __fastcall TDM3::VED_GEKGrid2CalcFields (TDataSet *DataSet) {
    if (VED_GEKGridFDQuery -> FieldValues["VID_EDU_PLAN"] == 0)
        VED_GEKGridFDQuery -> FieldValues["VID_EDU1"] = "Дневное";
    if (VED_GEKGridFDQuery -> FieldValues["VID_EDU_PLAN"] == 1)
        VED_GEKGridFDQuery -> FieldValues["VID_EDU1"] = "Заочное";
}

void __fastcall TDM3::GEKResultGrid2CalcFields (TDataSet *DataSet) {

    if (!DataSet -> FieldValues["BALL_GEK"].IsNull ()) {

        if (DataSet -> FieldValues["BALL_GEK"] > 10)
            DataSet -> FieldValues["BALL_GEK1"] =
                (DataSet -> FieldValues["BALL_GEK"] - 10);
        else {
            if (DataSet -> FieldValues["BALL_GEK"] == 2)
                DataSet -> FieldValues["BALL_GEK1"] = "Неудовл.";
            if (DataSet -> FieldValues["BALL_GEK"] == 3)
                DataSet -> FieldValues["BALL_GEK1"] = "Удовл.";
            if (DataSet -> FieldValues["BALL_GEK"] == 4)
                DataSet -> FieldValues["BALL_GEK1"] = "Хорошо";
            if (DataSet -> FieldValues["BALL_GEK"] == 5)
                DataSet -> FieldValues["BALL_GEK1"] = "Отлично";
            if (DataSet -> FieldValues["BALL_GEK"] == 6)
                DataSet -> FieldValues["BALL_GEK1"] = "Не явился";

        }
    }
}

void __fastcall TDM3::Check_Add_Group (int edu, int kurs, TCheckListBox* ch)
{ // функция, которая в переданный  RxCheckListBox  заносит номера групп, в зависимости от вида обучения и курса

    AnsiString Param = "";

    if (nom_fac != 3)
        Param = IntToStr (nom_fac);
    else
        Param = "0";
    Param += AnsiString (kurs) + "_";

    DM3 -> Group_VipuskFDQuery -> Close ();
    DM3 -> Group_VipuskFDQuery -> SQL -> Clear ();
    DM3 -> Group_VipuskFDQuery -> Params -> Clear ();
    DM3 -> Group_VipuskFDQuery -> SQL -> Add
        ("SELECT INC_GROUP, VID_EDU, N_GROUP FROM INCREMENT_GROUP Increment_group Where VID_EDU=:VID_EDU and N_GROUP like (:N_GROUP) order by N_GROUP"
        );
    DM3 -> Group_VipuskFDQuery -> ParamByName ("VID_EDU") -> Value = edu;
    DM3 -> Group_VipuskFDQuery -> ParamByName ("N_GROUP") -> Value = Param;
    DM3 -> Group_VipuskFDQuery -> Open ();

    ch -> Clear ();
    for (int i = 0; i < DM3 -> Group_VipuskFDQuery -> RecordCount; i++) {
        ch -> Items -> Add ( (DM3 -> Group_VipuskFDQueryN_GROUP -> Value).SubString (1, 3));
        DM3 -> Group_VipuskFDQuery -> Next ();
    }
}


AnsiString TDM3::Check_Return_Group (int edu, TCheckListBox* ch)
{ // функция, которая из RxCheckListBox-а  передает инкременты номеров групп, в зависимости от вида обучения

    AnsiString inc_nomera_grupp = "";

    for (int i = 0; i < ch -> Items -> Count; i++) { // for
        if (ch -> Checked[i]) { // if находим выбранные группы

            Variant V = search_increment_group (ch -> Items -> Strings[i], edu);
            // --------
            if (!V.IsNull ()) { // if проверка на соответствие номера группы
                inc_nomera_grupp += V.AsType (varString);
                inc_nomera_grupp += ",";
            } // end if проверка на соответствие номера группы
        } // end if находим выбранные группы
    } // end for

    return inc_nomera_grupp.SubString (1, inc_nomera_grupp.Length () - 1);
}


void __fastcall TDM3::Svod_Nado2CalcFields (TDataSet *DataSet) {
    // переменная для определения учебного года
    int p = DM3 -> Svod_NadoFDQueryYEAR_PLAN -> Value;
    AnsiString uch = AnsiString (p) + "/" + AnsiString (p + 1);
    DataSet -> FieldValues["YEAR1"] = uch;

    int k = DM3 -> Svod_NadoFDQueryZACH_EXAM -> Value;
    AnsiString kk = "";
    switch (k) {
    case 0:
        kk = "нет контроля";
        break;
    case 1:
        kk = "зачет";
        break;
    case 2:
        kk = "экзамен";
        break;
    case 3:
        kk = "диф. зачет";
        break;
    case 4:
        kk = "ГОС экз.";
        break;
    }
    DataSet -> FieldValues["ZACH_EXAM1"] = kk;
}

void __fastcall TDM3::Vipuskniki2CalcFields (TDataSet *DataSet) {
    AnsiString d =
        DateToStr (SQLTimeStampToDateTime
        (DM3 -> VipusknikiFDQueryD_PRIKAZ_INCLUDE -> Value));
    if (d != "")
        DataSet -> FieldValues["DATA1"] = d.SubString (7, 4);
    else
        DataSet -> FieldValues["DATA1"] = "";
}
void __fastcall TDM3::VED_GEKGridFDQueryCalcFields (TDataSet *DataSet)
{
    if (VED_GEKGridFDQuery -> FieldValues["VID_EDU_PLAN"] == 0)
        VED_GEKGridFDQuery -> FieldValues["VID_EDU1"] = "Дневное";
    if (VED_GEKGridFDQuery -> FieldValues["VID_EDU_PLAN"] == 1)
        VED_GEKGridFDQuery -> FieldValues["VID_EDU1"] = "Заочное";
}

void __fastcall TDM3::VipusknikiFDQueryCalcFields (TDataSet *DataSet)
{
   AnsiString d =
        DateToStr (SQLTimeStampToDateTime
        (DM3 -> VipusknikiFDQueryD_PRIKAZ_INCLUDE -> Value));
    if (d != "")
        DataSet -> FieldValues["DATA1"] = d.SubString (7, 4);
    else
        DataSet -> FieldValues["DATA1"] = "";
}

void __fastcall TDM3::GEKResultGridFDQueryCalcFields (TDataSet *DataSet)
{
        if (!DataSet -> FieldValues["BALL_GEK"].IsNull ()) {

        if (DataSet -> FieldValues["BALL_GEK"] > 10)
            DataSet -> FieldValues["BALL_GEK1"] =
                (DataSet -> FieldValues["BALL_GEK"] - 10);
        else {
            if (DataSet -> FieldValues["BALL_GEK"] == 2)
                DataSet -> FieldValues["BALL_GEK1"] = "Неудовл.";
            if (DataSet -> FieldValues["BALL_GEK"] == 3)
                DataSet -> FieldValues["BALL_GEK1"] = "Удовл.";
            if (DataSet -> FieldValues["BALL_GEK"] == 4)
                DataSet -> FieldValues["BALL_GEK1"] = "Хорошо";
            if (DataSet -> FieldValues["BALL_GEK"] == 5)
                DataSet -> FieldValues["BALL_GEK1"] = "Отлично";
            if (DataSet -> FieldValues["BALL_GEK"] == 6)
                DataSet -> FieldValues["BALL_GEK1"] = "Не явился";

        }
    }
}

void __fastcall TDM3::Svod_NadoFDQueryCalcFields (TDataSet *DataSet)
{
    int p = DM3 -> Svod_NadoFDQueryYEAR_PLAN -> Value;
    AnsiString uch = AnsiString (p) + "/" + AnsiString (p + 1);
    DataSet -> FieldValues["YEAR1"] = uch;

    int k = DM3 -> Svod_NadoFDQueryZACH_EXAM -> Value;
    AnsiString kk = "";
    switch (k) {
    case 0:
        kk = "нет контроля";
        break;
    case 1:
        kk = "зачет";
        break;
    case 2:
        kk = "экзамен";
        break;
    case 3:
        kk = "диф. зачет";
        break;
    case 4:
        kk = "ГОС экз.";
        break;
    }
    DataSet -> FieldValues["ZACH_EXAM1"] = kk;
}




void __fastcall TDM3::Svod_Nado_toExcelFDQueryCalcFields (TDataSet *DataSet)
{
int p = DM3 -> Svod_Nado_toExcelFDQueryYEAR_PLAN -> Value;
    AnsiString uch = AnsiString (p) + "/" + AnsiString (p + 1);
    DataSet -> FieldValues["YEAR1"] = uch;

    int k = DM3 -> Svod_Nado_toExcelFDQueryZACH_EXAM -> Value;
    AnsiString kk = "";
    switch (k) {
    case 0:
        kk = "нет контроля";
        break;
    case 1:
        kk = "зачет";
        break;
    case 2:
        kk = "экзамен";
        break;
    case 3:
        kk = "диф. зачет";
        break;
    case 4:
        kk = "ГОС экз.";
        break;
    }
    DataSet -> FieldValues["ZACH_EXAM1"] = kk;
}




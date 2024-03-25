#include <vcl.h>
#pragma hdrstop


#include "DM2Unit.h"
#include "DataModule.h"
#include "SpravUnit.h"
#include "SplashUnit.h"
#include "SpisocUnit.h"
#include <DateUtils.hpp>


#pragma package (smart_init)
// #pragma link     "RxLogin"
#pragma resource "*.dfm"


TDM2 * DM2;


int splash;




// Cause_HolidayFDTableAfterOpen
// Cause_HolidayFDTableNewRecord
// Cause_HolidayTable2NewRecord
// Cause_HolidayTable3AfterOpen
// Cause_PassFDTableAfterOpen
// Cause_PassFDTableNewRecord
// Cause_PassTable2NewRecord
// Cause_PassTable3AfterOpen
// Cause_RestoreFDTableAfterOpen
// Cause_RestoreFDTableNewRecord
// Cause_RestoreTable2AfterOpen
// Cause_RestoreTable2NewRecord
// Cause_RestoreTable3AfterOpen
// FacultyFDTableAfterOpen
// FacultyFDTableNewRecord
// FacultyTable2NewRecord
// FacultyTable3AfterOpen
// FDTable1AfterOpen
// FoundationFDTableAfterOpen
// FoundationFDTableNewRecord
// FoundationTable2AfterOpen
// FoundationTable2NewRecord
// get_version
// Increment_GroupFDTableNewRecord
// Increment_GroupTable2NewRecord
// Object_PlanFDTableAfterOpen
// Object_PlanFDTableNewRecord
// Object_PlanTable2NewRecord
// Object_PlanTable3AfterOpen
// Prikaz_KursFDTableAfterOpen
// Prikaz_KursTable3AfterOpen
// RegionFDTableAfterOpen
// Special_DirFDTableAfterOpen
// Special_DirFDTableNewRecord
// Special_DirTable2AfterOpen
// SpecialityFDTableAfterOpen
// SpecialityFDTableNewRecord
// SpecialityTable2NewRecord
// SpecialityTable3AfterOpen
// SpecializFDTableAfterOpen
// SpecializFDTableNewRecord
// SpecializTable2NewRecord
// SpecializTable3AfterOpen
// Table13AfterOpen
// Type_EncourageFDTableAfterOpen
// Type_EncourageFDTableNewRecord
// Type_EncourageTable2NewRecord
// Type_EncourageTable3AfterOpen
// Type_PrikazFDTableNewRecord
// Type_PrikazTable2NewRecord
// Vid_SportFDTableAfterOpen
// Vid_SportFDTableNewRecord
// Vid_SportTable2NewRecord
// Vid_SportTable3AfterOpen









__fastcall TDM2::TDM2 (TComponent* Owner) : TDataModule (Owner) {

}


TDateTime __fastcall Date_return (int f, int k)
{ // ������� ���������� ���� �� ������� �� �������
    // int f -��� ��������� 0-������� ������� ����, 1-���, 2-�����, 3 - ����
    // int k -�� ������� ��������� (����������)
    TDateTime dd;
    dd = dd.CurrentDate ();

    switch (f) { // switch �� ��� ��������
    case 1: // ���
        dd = IncYear (dd, k);
        break;
    case 2: // �����
        dd = IncMonth (dd, k);
        break;
    case 3: // ����
        dd = IncDay (dd, k);
        break;
    } // END switch �� ��� ��������
    return dd;
}


void __fastcall TDM2::FoundationTable2NewRecord (TDataSet *DataSet) {
    DM2 -> FoundationFDTableN_FOUND -> Value = 32000;
}


void __fastcall TDM2::SpecialityTable2NewRecord (TDataSet *DataSet) {
    DM2 -> SpecialityFDTableN_SPEC -> Value = 32000;
}


void __fastcall TDM2::Cause_HolidayTable2NewRecord (TDataSet *DataSet) {
    DM2 -> Cause_HolidayFDTableN_HOL -> Value = 32000;
}


void __fastcall TDM2::Vid_SportTable2NewRecord (TDataSet *DataSet) {
    DM2 -> Vid_SportFDTableN_VID_SPORT -> Value = 32000;
}


void __fastcall TDM2::FacultyTable2NewRecord (TDataSet *DataSet) {
    DM2 -> FacultyFDTableN_FAC -> Value = 32000;
}


void __fastcall TDM2::Object_PlanTable2NewRecord (TDataSet *DataSet) {
    DM2 -> Object_PlanFDTableN_OBJECT -> Value = 32000;
}


void __fastcall TDM2::Cause_PassTable2NewRecord (TDataSet *DataSet) {
    DM2 -> Cause_PassFDTableN_CAUSE -> Value = 32000;
}


void __fastcall TDM2::Type_EncourageTable2NewRecord (TDataSet *DataSet) {
    DM2 -> Type_EncourageFDTableN_TYPE_EN -> Value = 32000;
    DM2 -> Type_EncourageFDTableTYPE_EN -> Value = SpravForm -> ComboBox1 -> ItemIndex;
}


void __fastcall TDM2::SpecializTable2NewRecord (TDataSet *DataSet) {
    DM2 -> SpecializFDTableN_SPECIALIZ -> Value = 32000;
}


void __fastcall TDM2::Cause_RestoreTable2NewRecord (TDataSet *DataSet) {
    DM2 -> Cause_RestoreFDTableN_CAUSE_RESTORE -> Value = 32000;
}


void __fastcall TDM2::Cause_RestoreTable2AfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::Increment_GroupTable2NewRecord (TDataSet *DataSet) {
    DM2 -> Increment_GroupFDTableINC_GROUP -> Value = 32000;
}


void __fastcall TDM2::Type_PrikazTable2NewRecord (TDataSet *DataSet) {
    DM2 -> Type_PrikazFDTableN_TYPE -> Value = 32000;
}


void __fastcall TDM2::Table13AfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::FoundationTable2AfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::SpecializTable3AfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}



void __fastcall TDM2::Cause_RestoreTable3AfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::FacultyTable3AfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::SpecialityTable3AfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::Object_PlanTable3AfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::Cause_HolidayTable3AfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::Vid_SportTable3AfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::Prikaz_KursTable3AfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::Cause_PassTable3AfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::Type_EncourageTable3AfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::Special_DirTable2AfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


AnsiString TDM2::get_version () // ������� ���������� ������ ���������
{
    DWORD h;
    AnsiString ver;
    const AnsiString sFileName = Application -> ExeName;
    DWORD Size = GetFileVersionInfoSizeA (sFileName.c_str (), &h);
    if (Size == 0)
        return "";
    char *buf;
    buf = (char *)GlobalAlloc (GMEM_FIXED, Size);
    if (GetFileVersionInfoA (sFileName.c_str (), h, Size, buf) != 0) {
        char *ValueBuf;
        UINT Len;
        VerQueryValueA (buf, "\\VarFileInfo\\Translation",
            & (void *)ValueBuf, &Len);
        if (Len >= 4) {
            AnsiString CharSet =
                IntToHex ( (int)MAKELONG (* (int *) (ValueBuf + 2),
                * (int *)ValueBuf), 8);

            if (VerQueryValueA (buf, AnsiString ("\\StringFileInfo\\" + CharSet +
                "\\FileVersion").c_str (), & (void *)ValueBuf, &Len) != 0)
                ver = ValueBuf;
        }
    }

	GlobalFree (buf);
    // ver.Delete (ver.Length () - 1, 2);                                          // delete tweak number
    return ver;
}



void __fastcall TDM2::SpecializFDTableAfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::SpecializFDTableNewRecord (TDataSet *DataSet) {
    DM2 -> SpecializFDTableN_SPECIALIZ -> Value = 32000;
}


void __fastcall TDM2::FoundationFDTableAfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::FoundationFDTableNewRecord (TDataSet *DataSet) {
    DM2 -> FoundationFDTableN_FOUND -> Value = 32000;
}


void __fastcall TDM2::Increment_GroupFDTableNewRecord (TDataSet *DataSet) {
    DM2 -> Increment_GroupFDTableINC_GROUP -> Value = 32000;
}


void __fastcall TDM2::Vid_SportFDTableAfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::Vid_SportFDTableNewRecord (TDataSet *DataSet) {
    DM2 -> Vid_SportFDTableN_VID_SPORT -> Value = 32000;
}



void __fastcall TDM2::Special_DirFDTableAfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }

}


void __fastcall TDM2::Special_DirFDTableNewRecord (TDataSet *DataSet) {
    DM2 -> SpecialityFDTableN_SPEC -> Value = 32000;
}


void __fastcall TDM2::SpecialityFDTableAfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::SpecialityFDTableNewRecord (TDataSet *DataSet) {
    DM2 -> SpecialityFDTableN_SPEC -> Value = 32000;
}


void __fastcall TDM2::Object_PlanFDTableAfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::Object_PlanFDTableNewRecord (TDataSet *DataSet) {
    DM2 -> Object_PlanFDTableN_OBJECT -> Value = 32000;
}


void __fastcall TDM2::Prikaz_KursFDTableAfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::Type_EncourageFDTableAfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::Type_EncourageFDTableNewRecord (TDataSet *DataSet) {
    DM2 -> Type_EncourageFDTableN_TYPE_EN -> Value = 32000;
    DM2 -> Type_EncourageFDTableTYPE_EN -> Value = SpravForm -> ComboBox1 -> ItemIndex;
}


void __fastcall TDM2::FDTable1AfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::Cause_RestoreFDTableAfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::Cause_RestoreFDTableNewRecord (TDataSet *DataSet) {
    DM2 -> Cause_RestoreFDTableN_CAUSE_RESTORE -> Value = 32000;
}


void __fastcall TDM2::FacultyFDTableAfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::FacultyFDTableNewRecord (TDataSet *DataSet) {
    DM2 -> FacultyFDTableN_FAC -> Value = 32000;
}


void __fastcall TDM2::Cause_HolidayFDTableAfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::Cause_HolidayFDTableNewRecord (TDataSet *DataSet) {
    DM2 -> Cause_HolidayFDTableN_HOL -> Value = 32000;
}


void __fastcall TDM2::Cause_PassFDTableAfterOpen (TDataSet *DataSet) {
    if (splash) {
        SplashForm -> ProgressBar1 -> StepBy (8);
    }
}


void __fastcall TDM2::Cause_PassFDTableNewRecord (TDataSet *DataSet) {
    DM2 -> Cause_PassFDTableN_CAUSE -> Value = 32000;
}


void __fastcall TDM2::Type_PrikazFDTableNewRecord (TDataSet *DataSet) {
    DM2 -> Type_PrikazFDTableN_TYPE -> Value = 32000;
}


void __fastcall TDM2::RegionFDTableAfterOpen (TDataSet *DataSet)
{
  if (splash)
  {
    SplashForm -> ProgressBar1 -> StepBy (8);
  }
}
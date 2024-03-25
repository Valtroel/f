//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "SpravUnit.h"
#include "DM2Unit.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package (smart_init)
#pragma resource "*.dfm"
TSpravForm *SpravForm;
//---------------------------------------------------------------------------
__fastcall TSpravForm::TSpravForm (TComponent* Owner)
    : TForm (Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSpravForm::FormClose (TObject *Sender,
      TCloseAction &Action)
{
  //   DM2 -> IBTransaction1 -> CommitRetaining ();
    //Диалоговое окно при выходе из Справочника
//!!!if (Application -> MessageBox ("    Закрыть Справочник?", "", MB_YESNO) == mrYes)
if (MessageDlg ("    Закрыть Справочник?", mtCustom, TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes)
            Action = caFree;
      else
            Action = caNone;

}
//---------------------------------------------------------------------------



void __fastcall TSpravForm::Button1Click (TObject *Sender)
{
DM2 -> Cause_PassFDTable -> ApplyUpdates ();
//DM2 -> Cause_PassT -> Commit ();
DM2 -> Cause_PassFDTable -> Open ();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::Button2Click (TObject *Sender)
{
DM2 -> Cause_PassFDTable -> CancelUpdates ();
}

//---------------------------------------------------------------------------

void __fastcall TSpravForm::TabSheet1Enter (TObject *Sender)
{
 DBNavigator1 -> DataSource=DM2 -> Cause_PassSource;
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::Button3Click (TObject *Sender)
{

DM2 -> FacultyFDTable -> ApplyUpdates ();
//DM2 -> FacultyT -> Commit ();
DM2 -> FacultyFDTable -> Open ();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::Button4Click (TObject *Sender)
{
DM2 -> FacultyFDTable -> CancelUpdates ();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::TabSheet3Enter (TObject *Sender)
{
 DBNavigator1 -> DataSource=DM2 -> FacultySource;
}
//---------------------------------------------------------------------------


void __fastcall TSpravForm::Button6Click (TObject *Sender)
{
DM2 -> Cause_RestoreFDTable -> CancelUpdates ();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::Button5Click (TObject *Sender)
{
DM2 -> Cause_RestoreFDTable -> ApplyUpdates ();
//DM2 -> Cause_RestoreT -> Commit ();
DM2 -> Cause_RestoreFDTable -> Open ();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::TabSheet2Enter (TObject *Sender)
{
DBNavigator1 -> DataSource=DM2 -> Cause_RestoreSource;
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::Button7Click (TObject *Sender)
{
DM2 -> Cause_HolidayFDTable -> ApplyUpdates ();
//DM2 -> Cause_HolidayT -> Commit ();
DM2 -> Cause_HolidayFDTable -> Open ();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::Button8Click (TObject *Sender)
{
DM2 -> Cause_HolidayFDTable -> CancelUpdates ();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::TabSheet7Enter (TObject *Sender)
{
DBNavigator1 -> DataSource=DM2 -> Cause_HolidaySource;
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::TabSheet4Enter (TObject *Sender)
{
  DBNavigator1 -> DataSource=DM2 -> SpecializSource;
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::Button9Click (TObject *Sender)
{

DM2 -> SpecializFDTableN_FAC -> Value=nom_fac;
DM2 -> SpecializFDTableN_SPEC -> Value=DM2 -> SpecialityFDTableN_SPEC -> Value;
DM2 -> SpecialityFDTable -> ApplyUpdates ();
DM2 -> SpecializFDTable -> ApplyUpdates ();
//DM2 -> SpecialityT -> Commit ();
//DM2 -> SpecializT -> Commit ();
DM2 -> SpecialityFDTable -> Open ();
DM2 -> SpecializFDTable -> Open ();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::Button10Click (TObject *Sender)
{
 DM2 -> SpecialityFDTable -> CancelUpdates ();
 DM2 -> SpecializFDTable -> CancelUpdates ();
}
//---------------------------------------------------------------------------


void __fastcall TSpravForm::DBGrid5Enter (TObject *Sender)
{
  DBNavigator1 -> DataSource=DM2 -> SpecialitySource;
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::DBGrid6Enter (TObject *Sender)
{
  DBNavigator1 -> DataSource=DM2 -> SpecializSource;
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::TabSheet6Enter (TObject *Sender)
{
 DBNavigator1 -> DataSource=DM2 -> Object_PlanSource;
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::Button11Click (TObject *Sender)
{
DM2 -> Object_PlanFDTable -> ApplyUpdates ();
//DM2 -> Object_PlanT -> Commit ();
DM2 -> Object_PlanFDTable -> Open ();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::Button12Click (TObject *Sender)
{
 DM2 -> Object_PlanFDTable -> CancelUpdates ();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::TabSheet8Enter (TObject *Sender)
{
DBNavigator1 -> DataSource=DM2 -> Type_EncourageSource;

}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::Button13Click (TObject *Sender)
{
DM2 -> Type_EncourageFDTable -> ApplyUpdates ();
//DM2 -> Type_EncourageT -> Commit ();
DM2 -> Type_EncourageFDTable -> Open ();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::Button14Click (TObject *Sender)
{
 DM2 -> Type_EncourageFDTable -> CancelUpdates ();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::TabSheet5Enter (TObject *Sender)
{
DBNavigator1 -> DataSource=DM2 -> Vid_SportSource;
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::Button15Click (TObject *Sender)
{
DM2 -> Vid_SportFDTable -> ApplyUpdates ();
//DM2 -> Vid_SportT -> Commit ();
DM2 -> Vid_SportFDTable -> Open ();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::Button16Click (TObject *Sender)
{
DM2 -> Vid_SportFDTable -> CancelUpdates ();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::ComboBox1Change (TObject *Sender)
{
 int i=ComboBox1 -> ItemIndex;
      switch  (i) {
      case 0 : DM2 -> Type_EncourageFDTable -> Filter="TYPE_EN=0";
      break;
      case 1 : DM2 -> Type_EncourageFDTable -> Filter="TYPE_EN=1";
      break;
      }

}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::TabSheet9Enter (TObject *Sender)
{
 DBNavigator1 -> DataSource=DM2 -> FoundationSource;
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::Button17Click (TObject *Sender)
{
DM2 -> FoundationFDTable -> ApplyUpdates ();
//DM2 -> FoundationT -> Commit ();
DM2 -> FoundationFDTable -> Open ();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::Button18Click (TObject *Sender)
{
DM2 -> FoundationFDTable -> CancelUpdates ();
}
//---------------------------------------------------------------------------


void __fastcall TSpravForm::TabSheet8Exit (TObject *Sender)
{
 DM2 -> Type_EncourageFDTable -> Filtered=false;
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::TabSheet8Show (TObject *Sender)
{
if (ComboBox1 -> ItemIndex==-1) ComboBox1 -> ItemIndex=0;
int i=ComboBox1 -> ItemIndex;
      switch  (i) {
      case -1: break;
      case 0 : DM2 -> Type_EncourageFDTable -> Filter="TYPE_EN=0";
      break;
      case 1 : DM2 -> Type_EncourageFDTable -> Filter="TYPE_EN=1";
      break;
      }
DM2 -> Type_EncourageFDTable -> Filtered=true;
}
//---------------------------------------------------------------------------



void __fastcall TSpravForm::Button19Click (TObject *Sender)
{
DM2 -> Type_PrikazFDTable -> ApplyUpdates ();
//DM2 -> Type_PrikazT -> Commit ();
DM2 -> Type_PrikazFDTable -> Open ();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::TabSheet10Enter (TObject *Sender)
{
DBNavigator1 -> DataSource=DM2 -> Type_PrikazSource;
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::Button20Click (TObject *Sender)
{
DM2 -> Type_PrikazFDTable -> CancelUpdates ();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::Button21Click (TObject *Sender)
{
   DM2 -> QualificationFDTable -> ApplyUpdates ();
   //DM2 -> IB_QualificationT -> Commit ();
   DM2 -> QualificationFDTable -> Open ();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::Button22Click (TObject *Sender)
{
     DM2 -> QualificationFDTable -> CancelUpdates ();
}
//---------------------------------------------------------------------------

void __fastcall TSpravForm::TabSheet11Enter (TObject *Sender)
{
     DBNavigator1 -> DataSource=DM2 -> DataSourceQualification;   
}
//---------------------------------------------------------------------------


void __fastcall TSpravForm::TabSheet12Show (TObject *Sender)
{
DataModule1 -> KafedraFDQuery -> Close ();
DataModule1 -> KafedraFDQuery -> ParamByName ("FAC") -> AsInteger=nom_fac;
DataModule1 -> KafedraFDQuery -> Open ();

DataModule1 -> Kafedra_SpecFDQuery -> Close ();
DataModule1 -> Kafedra_SpecFDQuery -> Open ();
}
//---------------------------------------------------------------------------


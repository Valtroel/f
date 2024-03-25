//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Stud_Pr_RestoreUnit.h"
#include "DataModule.h"
#include "DM2Unit.h"
//---------------------------------------------------------------------------
#pragma package (smart_init)
//!!!#pragma link "ToolEdit"
#pragma resource "*.dfm"
TStud_Pr_RestoreForm *Stud_Pr_RestoreForm;
int nom_student;//����� ��������
//---------------------------------------------------------------------------
__fastcall TStud_Pr_RestoreForm::TStud_Pr_RestoreForm (TComponent* Owner)
        : TForm (Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TStud_Pr_RestoreForm::FormClose (TObject *Sender, TCloseAction &Action)
{
/*if (Bookmark)
   { //if ��������

        DataModule1 -> PeopleQuery -> FreeBookmark (Bookmark);
   }//end if ��������    */


Action=caFree;
}
//---------------------------------------------------------------------------
void __fastcall TStud_Pr_RestoreForm::BitBtn1Click (TObject *Sender)
{//�������� �� ������ ��������� ������ �� ����������
//-------
/*if (RadioGroup1 -> ItemIndex==-1)
{
 ShowMessage ("�������� ��� �������!");
 return;
}      */
//-------
if (DBLookupComboBox1 -> Text=="")
{
 ShowMessage ("�������� ������� ���������� ��������!");
 return;
}
//-------
if (Edit1 -> Text=="")
{
ShowMessage ("�������� � ������� �� ����������!");
 return;
}
//-------
/*!!!if (DateTimePicker1 -> Value=="  .  .    ")
{
ShowMessage ("�������� ���� ������� �� ����������!");
 return;
}  */
//-------
int n_prikaz;//���������� ��� ������ �������
try
{//try �� ���� ��������� �������� �������
  n_prikaz=StrToInt (Edit1 -> Text); //� �������
}//end try �� ���� ��������� �������� �������
catch (...)
{//catch ������� ������ ����� �������
  ShowMessage ("������� ������ � �������!");
  return;
}//end catch ������� ������ ����� �������
//-----------------

try
 {//try Insert
   if (DataModule1 -> RestoreFDQuery -> State==dsInactive) DataModule1 -> RestoreFDQuery -> Open ();
   DataModule1 -> RestoreFDQuery -> Insert ();
   DataModule1 -> RestoreFDQueryNOMER -> Value=nom_student; //����� ��������
   DataModule1 -> RestoreFDQueryN_CAUSE_RESTORE -> Value=DBLookupComboBox1 -> KeyValue;//������� ����������
   DataModule1 -> RestoreFDQueryN_PRIKAZ_RES -> Value=n_prikaz;//� ������� �� ����������
   DataModule1 -> RestoreFDQueryD_PRIKAZ_RES -> Value=DateTimeToSQLTimeStamp (DateTimePicker1 -> Date);//���� ������� �� ����������
   DataModule1 -> RestoreFDQueryVID_RESTORE -> Value=1; //����������
   DataModule1 -> RestoreFDQueryDESCRIBE -> Value=Edit2 -> Text;//����������
   try
     { //try �������� �� ���� � � ������� ��������� ��������
         DataModule1 -> RestoreFDQuery -> ApplyUpdates ();
         DataModule1 -> RestoreFDQuery -> CommitUpdates ();
     }//end try �������� �� ���� � � �������
   catch (...)
     {//catch ������� ������ ������
         DataModule1 -> RestoreFDQuery -> CancelUpdates ();
         ShowMessage ("�� ������� ��������� ������ �� ����������!");

     }//end catch ������� ������ ������

     
  /* switch (RadioGroup1 -> ItemIndex)
           {//switch ����� ���� �������
            case 0: //������ �� ����������
                  if (DataModule1 -> RestoreQuery -> State==dsInactive) DataModule1 -> RestoreQuery -> Open ();
                  DataModule1 -> RestoreQuery -> Insert ();
                  DataModule1 -> RestoreQueryNOMER -> Value=nom_student; //����� ��������
                  DataModule1 -> RestoreQueryN_CAUSE_RESTORE -> Value=DBLookupComboBox1 -> KeyValue;//������� ����������
                  DataModule1 -> RestoreQueryN_PRIKAZ_RES -> Value=n_prikaz;//� ������� �� ����������
                  DataModule1 -> RestoreQueryD_PRIKAZ_RES -> Value=DateEdit1 -> Text;//���� ������� �� ����������
                  DataModule1 -> RestoreQueryVID_RESTORE -> Value=1; //����������
                  DataModule1 -> RestoreQueryDESCRIBE -> Value=Edit2 -> Text;//����������
                  try
                    { //try �������� �� ���� � � ������� ��������� ��������
                        DataModule1 -> RestoreQuery -> ApplyUpdates ();
                        DataModule1 -> RestoreQuery -> CommitUpdates ();
                    }//end try �������� �� ���� � � �������
                  catch (...)
                    {//catch ������� ������ ������
                        DataModule1 -> RestoreQuery -> CancelUpdates ();
                        ShowMessage ("�� ������� ��������� ������ �� ����������!");

                    }//end catch ������� ������ ������

                  break;
            case 1: //������ �� ������� �� ������� ����
                  if (DataModule1 -> Public_PrikazQuery -> State==dsInactive) DataModule1 -> Public_PrikazQuery -> Open ();
                  DataModule1 -> Public_PrikazQuery -> Insert ();
                  DataModule1 -> Public_PrikazQueryNOMER -> Value=nom_student; //����� ��������
                  DataModule1 -> Public_PrikazQueryN_PUBLIC_PRIKAZ -> Value=n_prikaz;//� �������
                  DataModule1 -> Public_PrikazQueryD_PUBLIC_PRIKAZ -> Value=DateEdit1 -> Text;//���� �������
                  DataModule1 -> Public_PrikazQueryN_TYPE -> Value=7; //��� ������� ������� �� ������� ����
                  DataModule1 -> Public_PrikazQueryDESCRIBE -> Value=Edit2 -> Text;//����������
                  try
                    { //try �������� �� ���� � � ������� ��������� ��������
                        DataModule1 -> Public_PrikazQuery -> ApplyUpdates ();
                        DataModule1 -> Public_PrikazQuery -> CommitUpdates ();
                    }//end try �������� �� ���� � � �������
                  catch (...)
                    {//catch ������� ������ ������
                        DataModule1 -> Public_PrikazQuery -> CancelUpdates ();
                        ShowMessage ("�� ������� ��������� ������ �� ������� �� ������� ����!");

                    }//end catch ������� ������ ������
                  break;
           }//end switch ����� ���� �������   */
Stud_Pr_RestoreForm -> Close ();
 }//end try Insert
catch (...)
 {//catch �� ���������� ���������
    ShowMessage ("��������� ������ ��� ���������� �������!");
 }//end catch �� ���������� ���������



}
//---------------------------------------------------------------------------
void __fastcall TStud_Pr_RestoreForm::RadioGroup1Click (TObject *Sender)
{//����� ���� �������
   switch (RadioGroup1 -> ItemIndex)
           {//switch ����� ���� �������
            case 0: //������ �� ����������
                    Label4 -> Visible=true;
                    DBLookupComboBox1 -> Visible=true;
                    Label3 -> Caption="����������:";
                    break;
            case 1: //������ �� ����������
                    Label4 -> Visible=false;
                    DBLookupComboBox1 -> Visible=false;
                    Label3 -> Caption="�������� �:";
                    break;
           }//end switch ����� ���� �������
}
//---------------------------------------------------------------------------

void __fastcall TStud_Pr_RestoreForm::FormCreate (TObject *Sender)
{
//������� �� �������� �� ������ ������ ��������
DataModule1 -> PeopleFDQuery -> GotoBookmark (Bookmark);
nom_student=DataModule1 -> PeopleFDQueryNOMER -> Value;
DataModule1 -> PeopleFDQuery -> FreeBookmark (Bookmark);
DateTimePicker1 -> Date = Now ();
DateTimePicker1 -> Time = StrToTime ("00:00");
}
//---------------------------------------------------------------------------

void __fastcall TStud_Pr_RestoreForm::Edit1KeyPress (TObject *Sender,
      char &Key)
{
DataModule1 -> Edit_Key (Key); //��� �������, ����� � TEdit ����� ���� ������� ������ �����?        
}
//---------------------------------------------------------------------------

void __fastcall TStud_Pr_RestoreForm::DateTimePicker1Change (TObject *Sender)
{
DateTimePicker1 -> Time = StrToTime ("00:00");
}
//---------------------------------------------------------------------------


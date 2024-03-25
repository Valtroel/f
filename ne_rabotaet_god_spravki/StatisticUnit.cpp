
//����� ����������

//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "StatisticUnit.h"
#include "CalendarUnit.h"
#include "DataModule.h"
#include "DM2Unit.h"
#include "Func.h"
//---------------------------------------------------------------------------
#pragma package (smart_init)
#pragma resource "*.dfm"

TStatisticForm *StatisticForm;
//---------------------------------------------------------------------------
__fastcall TStatisticForm::TStatisticForm (TComponent* Owner)
    : TForm (Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TStatisticForm::Edit1Click (TObject *Sender)
{   //����� ��������� �� ������ �����
 CalendarForm = new  TCalendarForm (this); //�������� ����� ���������
  CalendarForm -> ShowModal (); //����������� ����� ���������
  if (calendar) Edit1 -> Text=cal_date.DateString (); //�������� ������� ���� � ��������� ��� ���
  Edit2 -> SetFocus (); //�������� ������
 if ( (Edit1 -> Text!="")& (Edit2 -> Text!="")) BitBtn1 -> Visible=True;/*�������� ������� �� ��� ����,
   ���� ��,�� ������ ������� ���������� �������*/

 }
 //---------------------------------------------------------------------------

void __fastcall TStatisticForm::Edit2Click (TObject *Sender)
{   //����� ��������� �� ������ �����
  CalendarForm = new  TCalendarForm (this); //�������� ����� ���������
  CalendarForm -> ShowModal ();//����������� ����� ���������
 if (calendar) Edit2 -> Text=cal_date.DateString ();//�������� ������� ���� � ��������� ��� ���

if ( (Edit1 -> Text!="")& (Edit2 -> Text!="")) BitBtn1 -> Visible=True;/*�������� ������� �� ��� ����,
   ���� ��,�� ������ ������� ���������� �������*/
}
//---------------------------------------------------------------------------



void __fastcall TStatisticForm::BitBtn1Click (TObject *Sender)
{ //��� ������� ������ �������
  Set<TLocateOption,0,1> flags;//��������� ����� ��� ������
  DM2 -> Cause_PassFDTable -> Last ();
  int nom_rec=DM2 -> Cause_PassFDTable -> RecordCount;/*������� � ����������
    ���-�� ������� � ������� ������� ���������*/
  DM2 -> Cause_PassFDTable -> First ();

  StatisticGrid -> RowCount=nom_rec+1;/*������������� ���-�� ����� � Grid'� ������ �����
           ������� � ������� ������� ��������� */
DataModule1 -> Statistic_Pass_DateFDQuery -> Close ();//�������� Query ��� ��������� ����������
//DataModule1 -> StatisticQuery -> SQL -> Clear ();
//DataModule1 -> StatisticQuery -> SQL -> Add ("SELECT  SUM ( HOUR_PASS ) FROM PASS Pass WHERE (Pass.NOMER=:NOMER) AND (Pass.D_PASS BETWEEN :START AND :END) AND (Pass.N_CAUSE=:CAUSE)");
DataModule1 -> Statistic_Pass_DateFDQuery -> Params -> ParamValues["NOMER"]=DataModule1 -> PeopleFDQueryNOMER -> Value;
DataModule1 -> Statistic_Pass_DateFDQuery -> Params -> ParamValues["START"]=StrToDate (Edit1 -> Text);
DataModule1 -> Statistic_Pass_DateFDQuery -> Params -> ParamValues["END"]=StrToDate (Edit2 -> Text);
 for (int i=1;i<=nom_rec;i++)
 {//���� ��� ��������� ����������
   DataModule1 -> Statistic_Pass_DateFDQuery -> Params -> ParamValues["CAUSE"]=i;
   DataModule1 -> Statistic_Pass_DateFDQuery -> Open ();//���������� �������
    DM2 -> Cause_PassFDTable -> Locate ("N_CAUSE",i,flags);/*���������
      ��������� �� ������ � ������� ������� ��������� � i-� �������*/
    StatisticGrid -> Cells[0][i]=
            DM2 -> Cause_PassFDTableCAUSE -> Value;/*��������� � Grid ������
             ���������*/
    StatisticGrid -> Cells[1][i]=
            DataModule1 -> Statistic_Pass_DateFDQuerySUM -> Value;/*��������� � Grid ����� �����
              ����� ��������� ��� ������ �������*/
   DataModule1 -> Statistic_Pass_DateFDQuery -> Close (); //�������� Query
   }

  StatisticGrid -> Visible=true;//����� ������������ ������� � Grid'�
   }
//---------------------------------------------------------------------------

void __fastcall TStatisticForm::FormActivate (TObject *Sender)
{ //��� ����������� �����
//��������� � Grid �������� ��������
StatisticGrid -> Cells[0][0]="������� ��������";
StatisticGrid -> Cells[1][0]="���-�� ������.�����";
}
//---------------------------------------------------------------------------

void __fastcall TStatisticForm::Edit1Change (TObject *Sender)
{  //��� ��������� Edit1
//������ ������� � Grid ���������� ����������
 BitBtn1 -> Visible=false;
 StatisticGrid -> Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TStatisticForm::Edit2Change (TObject *Sender)
{  //��� ��������� Edit2
//������ ������� � Grid ���������� ����������
 BitBtn1 -> Visible=false;
 StatisticGrid -> Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TStatisticForm::BitBtn2Click (TObject *Sender)
{  //��� ������� ������ �������
//�������� ����� ����������
Close ();    
}
//---------------------------------------------------------------------------


void __fastcall TStatisticForm::FormClose (TObject *Sender,
      TCloseAction &Action)
{
Action=caFree;       
}
//---------------------------------------------------------------------------


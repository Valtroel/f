#include <vcl.h>
#pragma hdrstop


#include "BallGEKUnit.h"
#include "DataModule.h"
#include "DM3Unit.h"
#include "VED_GEKResultUnit.h"


#pragma package (smart_init)
// #pragma link     "ToolEdit"
#pragma resource "*.dfm"


TBall_GEK * Ball_GEK;


// BitBtn1Click
// BitBtn2Click
// DBNavigator1Click
// FormActivate
// FormClose
// Radio_ball_baza
// Radio_setup_baza
// RadioButton1Click
// RadioButton2Click
// RadioGroup2Click



int __fastcall TBall_GEK::Radio_setup_baza ()
{ // ��������� RadioGroup1 -> ItemIndex � �������� �� ���� ������
//� ���� ��������
//-----���������  GEKResultBall  �� ���������� ��� ���������  �����������
DataModule1 -> GEKResultBallFDQuery -> Close ();
DataModule1 -> GEKResultBallFDQuery -> ParamByName ("N_VED") -> Value=DM3 -> GEKResultGridFDQueryN_VED -> Value;
DataModule1 -> GEKResultBallFDQuery -> ParamByName ("NOMER") -> Value=DM3 -> GEKResultGridFDQueryNOMER -> Value;
DataModule1 -> GEKResultBallFDQuery -> Open ();
//-----
Variant b=DataModule1 -> GEKResultBallFDQueryBALL_GEK -> AsVariant;
if (!b.IsNull ())
{//if ���� ���� �� ������ � ����� ��������
   if (b>=10)
   { //if 10-�� ������� �������
     RadioGroup2 -> ItemIndex=0;
     RadioGroup2Click (this);//���������� RadioGroup2 Items-���
     RadioGroup1 -> ItemIndex=b-11;

   } //end if 10-�� ������� �������
   else
   {//else 5-�� ������� �������
         RadioGroup2 -> ItemIndex=1;
         RadioGroup2Click (this);//���������� RadioGroup2 Items-���
         RadioGroup1 -> ItemIndex=b-2;   //��� �������� ������������� ��������� �� ���� - 2
         

    }//end else 5-�� ������� �������

//��������� ���� � ������ ���������
//Edit2 -> Text=IntToStr (DM3 -> GEKResultBallN_PROTOCOL -> Value);        //����� ���������
//DateEdit1 -> Text=DM3 -> GEKResultBallD_PROTOCOL -> Value;    //���� ���������

}//end if ���� ���� �� ������ � ����� ��������
else
{//else �������� ��� ������� ��������� �� ���������
 RadioGroup1 -> ItemIndex=-1; //���� ������ ���, �� ������ �� �������
 RadioGroup2 -> ItemIndex=0;//������������� �� ��������� 10-�� ������� �������
 RadioGroup2Click (this);
 //Edit2 -> Text="";//������ �������� ������ ���������
// DateEdit1 -> Text="  .  .    ";     //������ �������� ���� ���������
}//end else �������� ��� ������� ��������� �� ���������

DBNavigator1 -> Enabled=true;
return RadioGroup1 -> ItemIndex; //���������� ��������� �  RadioGroup1 � ����������� �� ������
}
int __fastcall TBall_GEK::Radio_ball_baza ()
{//�������� �������� ����� � ����������� �� RadioGroup1 -> ItemIndex � ������� ������
int ball_radio;

     if (!RadioGroup2 -> ItemIndex)//�������� �� ������� ������
      { //if ���� ������� 10-�� �������
          switch (RadioGroup1 -> ItemIndex)
                {//switch

                case 10:  ball_radio=6; //�� ������
                        break;
                
                default: ball_radio=RadioGroup1 -> ItemIndex+11; //������ �������������  RadioGroup1 -> ItemIndex +11
                        break;
                }//end switch
      }//end if ���� ������� 10-�� �������
      else
      {//else ���� ������� 5-�� �������

          ball_radio=RadioGroup1 -> ItemIndex+2; //������ 2,3,4,5 � 6 (������) �������������  RadioGroup1 -> ItemIndex+2

      }//end else ���� ������� 5-�� �������

return ball_radio;
}
__fastcall TBall_GEK::TBall_GEK (TComponent* Owner)
        : TForm (Owner)
{
}
void __fastcall TBall_GEK::FormClose (TObject *Sender, TCloseAction &Action)
{
    Action=caFree;    
}
void __fastcall TBall_GEK::FormActivate (TObject *Sender)
{

Radio_setup_baza ();//��������� ��������� �������� �� ����, ���� ��� ����������

    if ( (DM3 -> GEKResultGridFDQueryTHEME -> Value=="")|| (DM3 -> GEKResultGridFDQueryTHEME -> AsVariant.IsNull ()))
    {
        RadioButton2 -> Checked=false;
        RadioButton1 -> Checked=true;
        Memo1 -> Clear ();
        Label2 -> Visible=false;
        Memo1 -> Visible=false;
     }
    else
    {
       RadioButton2 -> Checked=true;
       RadioButton1 -> Checked=false;
       Label2 -> Visible=true;
       Memo1 -> Visible=true;
       Memo1 -> Text=DM3 -> GEKResultGridFDQueryTHEME -> Value;
    }

}          
void __fastcall TBall_GEK::RadioButton2Click (TObject *Sender)
{  //������ �� �������
   Label2 -> Visible=true;
   Memo1 -> Visible=true;
}
void __fastcall TBall_GEK::RadioButton1Click (TObject *Sender)
{  //������ �� ����
      Label2 -> Visible=false;
      Memo1 -> Clear ();
      Memo1 -> Visible=false;
}

void __fastcall TBall_GEK::BitBtn1Click (TObject *Sender)
{  //�������� �� ������ ���������
//----
if  (!RadioButton2 -> Checked &&  !RadioButton1 -> Checked)
  { //if �������� ����� ���� ������� ���� �� �������� (������ ��� ���)
    ShowMessage ("�������� ������ : ������  ��� ���. �������!!!");
    return;
  }//end if �������� ����� ���� ������� ���� �� �������� (������ ��� ���)
//----
if (RadioGroup1 -> ItemIndex==-1)
  { //if    �������� �� ������������� ������
    ShowMessage ("���������� ������ �� ���. �������� ��� �������");
    return;
  }//end if  �������� �� ������������� ������
//-----
if  (RadioButton2 -> Checked  &&  Memo1 -> Text=="")
  { //if    �������� �� ���� ���� �������, ���� ������ ������� ������
    ShowMessage ("�� ������� ������, �� ������ ������ ���� �������!");
    return;
  }//end if  �������� �� ���� ���� �������, ���� ������ ������� ������

    DataModule1 -> GEKResultBallFDQuery -> Close ();
    DataModule1 -> GEKResultBallFDQuery -> ParamByName ("N_VED") -> Value=DM3 -> GEKResultGridFDQueryN_VED -> Value;
    DataModule1 -> GEKResultBallFDQuery -> ParamByName ("NOMER") -> Value=DM3 -> GEKResultGridFDQueryNOMER -> Value;
    DataModule1 -> GEKResultBallFDQuery -> Open ();
    DataModule1 -> GEKResultBallFDQuery -> Edit ();
    if (Memo1 -> Text!="")
       {//if ������� ������ �� ����
          DataModule1 -> GEKResultBallFDQueryTHEME -> Value=Memo1 -> Text;
       }//end if ������� ������ �� ����
    else
       {//else ������� ���, �� � ��� ���� ������ �� ���������
       DataModule1 -> GEKResultBallFDQueryTHEME -> Value="";
       }//end else ������� ���, �� � ��� ���� ������ �� ���������

     //--���������� ����� �� ���������, ������������ ������ �� ��������� RadioGroup1
     //-- � ��������� ������� ������
     DataModule1 -> GEKResultBallFDQueryBALL_GEK -> Value=Radio_ball_baza ();

  /*   //--- ���������� ������ ��������� � ���� ���������
     try
       {//try �������� �� ��������� �����
         DM3 -> GEKResultBallN_PROTOCOL -> Value=StrToInt (Edit2 -> Text);
       }//end try �������� �� ��������� �����
     catch (...)
       { //catch ���� �������� ������ ��������� �����
        ShowMessage ("����� ��������� ������ ��������� �������� ��������!");
        DM3 -> GEKResultBall -> CancelUpdates ();
        return;
       }//end catch ���� �������� ������ ��������� �����   */
   //  DM3 -> GEKResultBallD_PROTOCOL -> Value=DateEdit1 -> Text;

       try
        {//try �������� �� ������� ���������� ������
          DataModule1 -> GEKResultBallFDQuery -> ApplyUpdates ();
          DataModule1 -> GEKResultBallFDQuery -> CommitUpdates ();
          DataModule1 -> GEKResultBallFDQuery -> Close ();
         // Memo1 -> Clear ();
        } //end try �������� �� ������� ���������� ������
       catch (...)
        { //catch
           DataModule1 -> GEKResultBallFDQuery -> CancelUpdates ();
           ShowMessage ("��������� ���� ��� ����������. ���������� ��� ���!");
        } //end catch
DBNavigator1 -> Enabled=true;        
}

void __fastcall TBall_GEK::BitBtn2Click (TObject *Sender)
{ //�������� �� ������ �������
     Ball_GEK -> Close ();
     DM3 -> GEKResultGridFDQuery -> Close ();
     DM3 -> GEKResultGridFDQuery -> Open ();

}

void __fastcall TBall_GEK::DBNavigator1Click (TObject *Sender,
      TNavigateBtn Button)
{
     FormActivate (Sender);
}

void __fastcall TBall_GEK::RadioGroup2Click (TObject *Sender)
{//������������ ����� ��������� ������
RadioGroup1 -> Items -> Clear ();
if (!RadioGroup2 -> ItemIndex)//�������� �� ������� ������
      { //if ���� ������� 10-�� �������
        RadioGroup1 -> Items -> Add ("����");
        RadioGroup1 -> Items -> Add ("���");
        RadioGroup1 -> Items -> Add ("���");
        RadioGroup1 -> Items -> Add ("������");
        RadioGroup1 -> Items -> Add ("����");
        RadioGroup1 -> Items -> Add ("�����");
        RadioGroup1 -> Items -> Add ("����");
        RadioGroup1 -> Items -> Add ("������");
        RadioGroup1 -> Items -> Add ("������");
        RadioGroup1 -> Items -> Add ("������");
        RadioGroup1 -> Items -> Add ("�� ������");
        RadioGroup1 -> Columns=3;
      }//end if ���� ������� 10-�� �������
      else
      {//else ���� ������� 5-�� �������
        RadioGroup1 -> Items -> Add ("�������.");
        RadioGroup1 -> Items -> Add ("�����.");
        RadioGroup1 -> Items -> Add ("������");
        RadioGroup1 -> Items -> Add ("�������");
        RadioGroup1 -> Items -> Add ("�� ������");
        RadioGroup1 -> Columns=2;
       }//end else ���� ������� 5-�� �������
}



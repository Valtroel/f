
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include <ComObj.hpp>
#include <utilcls.h>
#include "SpravkiUnit.h"
#include "DataModule.h"
//---------------------------------------------------------------------------
#pragma package (smart_init)
#pragma resource "*.dfm"
TSpavkiForm *SpavkiForm;
Variant vApp, vDocs, vDoc, vPars, vPar, vv;
bool fStart1;
AnsiString str;

//������� ������ � �������
AnsiString mas_memo[20];
int n_ch=0;//���������� ������� ������ �������
AnsiString WorkDir="D:\\��� ���������\\";
int s_a=0;//����� ������

//---------------------------------------------------------------------------
__fastcall TSpavkiForm::TSpavkiForm (TComponent* Owner)
        : TForm (Owner)
{
}
//---------------------------------------------------------------------------
void TSpavkiForm::refrech_memo_ch ()
{ //������� �������� ����� Memo � CheckBox-��
//---MEMO
//--- ����� �������
/*Memo1 -> Text="�� ����� ������ ���������.";
Memo2 -> Text="�� ����� ������.";
Memo3 -> Text="�� ����� ����������.";
Memo4 -> Text="�� ����� ����������.";
Memo5 -> Text="� ���, ���.";
Memo6 -> Text="� �����������.";
Memo7 -> Text="� ������� ���������.";
Memo8 -> Text="� ������������ ���� �����.";
Memo9 -> Text="� ������������.";
Memo10 -> Text="� ������.";
Memo11 -> Text="� ���.";
Memo12 -> Text="� ����������.";
Memo13 -> Text="� ����� �� ���������� � ������� ������ � �������.";
Memo14 -> Text="� ����� ���������� ��������� ��������.";
Memo15 -> Text="� �������� �����.";
Memo16 -> Text="� ������ ��������������� ������.";
Memo17 -> Text="� ���� ";
Memo18 -> Text="� ������������� ";
Memo19 -> Text="� �������� �����.";
Memo20 -> Text="";
//--- �������������� ����������
Memo21 -> Text="�������� ������ ������ �����������. ";
Memo22 -> Text="��������� �� ������ ��� �� ���� ��������� �������. ";
Memo23 -> Text="����������� ���� ��������� �������� ���������";
Memo24 -> Text=""; */

Memo1 -> Text="�� ����� ������ ���������";
Memo2 -> Text="�� ����� ������";
Memo3 -> Text="�� ����� ����������";
Memo4 -> Text="�� ����� ����������";
Memo5 -> Text="���, ���";
Memo6 -> Text="�����������";
Memo7 -> Text="������� ���������";
Memo8 -> Text="������������ ���� �����";
Memo9 -> Text="������������";
Memo10 -> Text="������";
Memo11 -> Text="���";
Memo12 -> Text="����������";
Memo13 -> Text="����� �� ���������� � ������� ������ � �������";
Memo14 -> Text="����� ���������� ��������� ��������";
Memo15 -> Text="�������� �����";
Memo16 -> Text="������ ��������������� ������";
Memo17 -> Text="���� ";
Memo18 -> Text="������������� ";
Memo19 -> Text="�������� �����";
Memo20 -> Text="";
//--- �������������� ����������
Memo21 -> Text="�������� ������ ������ �����������. ";
Memo22 -> Text="��������� �� ������ ��� �� ���� ��������� �������. ";
Memo23 -> Text="����������� ���� ��������� �������� ���������";
Memo24 -> Text="�������� �������� �� " + DateToStr (SQLTimeStampToDateTime (DataModule1 -> People_SpravkiFDQueryD_PRIKAZ_INCLUDE -> Value)) + " �" + IntToStr (DataModule1 -> People_SpravkiFDQueryN_PRIKAZ_INCLUDE -> Value) + "��.";


//----  �� �������� ��������
CheckBox1 -> Checked=false;
CheckBox2 -> Checked=false;
CheckBox3 -> Checked=false;
CheckBox4 -> Checked=false;
CheckBox5 -> Checked=false;
CheckBox6 -> Checked=false;
CheckBox7 -> Checked=false;
CheckBox8 -> Checked=false;
CheckBox9 -> Checked=false;
CheckBox10 -> Checked=false;
CheckBox11 -> Checked=false;
CheckBox12 -> Checked=false;
CheckBox13 -> Checked=false;
CheckBox14 -> Checked=false;
CheckBox15 -> Checked=false;
CheckBox16 -> Checked=false;
CheckBox17 -> Checked=false;
CheckBox18 -> Checked=false;
CheckBox19 -> Checked=false;
CheckBox20 -> Checked=false;
//---- �� �������������� ����������
CheckBox21 -> Checked=false;
CheckBox22 -> Checked=false;
CheckBox23 -> Checked=false;
CheckBox24 -> Checked=false;
}
//----------------------------------------------------------------------------
void TSpavkiForm::memo_ch (TCheckBox *ch, TMemo *m, int par)
{ // ������������ ������� ��� ������ ������ �������
//par- 0 ������ ������ �� ����
//par - 1 ���� ������� Memo  � ComboBox1
//par - 2 ���� ������� Memo  � ComboBox2


AnsiString text=m -> Text;
if (ch -> Checked)
   {
     switch (par)
        {
          //case 1: text="� "+ComboBox1 -> Text+" ����.";
          case 1: text=ComboBox1 -> Text+" ����";
                  break;

          //case 2: text+=ComboBox2 -> Text+".";
          case 2: text+=ComboBox2 -> Text;
                  break;
         }
      mas_memo[n_ch]=text;
      n_ch++;  //������� �� ���������� �������
   }
}
//----------------------------------------------------------------------------
void __fastcall TSpavkiForm::Button1Click (TObject *Sender)
{//������ ������ �������


//----  ���������� ����� �� ������� ������� �������������
memo_ch (CheckBox1, Memo1,0);
memo_ch (CheckBox2, Memo2,0);
memo_ch (CheckBox3, Memo3,0);
memo_ch (CheckBox4, Memo4,0);
memo_ch (CheckBox5, Memo5,0);
memo_ch (CheckBox6, Memo6,0);
memo_ch (CheckBox7, Memo7,0);
memo_ch (CheckBox8, Memo8,0);
memo_ch (CheckBox9, Memo9,0);
memo_ch (CheckBox10, Memo10,0);
memo_ch (CheckBox11, Memo11,0);
memo_ch (CheckBox12, Memo12,0);
memo_ch (CheckBox13, Memo13,0);
memo_ch (CheckBox14, Memo14,0);
memo_ch (CheckBox15, Memo15,0);
memo_ch (CheckBox16, Memo16,0);
memo_ch (CheckBox17, Memo17,1);
memo_ch (CheckBox18, Memo18,2);
memo_ch (CheckBox19, Memo19,0);
memo_ch (CheckBox20, Memo20,0);
//-----


//--- ���������� ��� ��������� Word �� ����������� �����
//������� ����
curent_date=cur_d ();
AnsiString s_name="D:\\��� ���������\\������� ��������� �� "+DateToStr (curent_date)+".doc";


//--- �������� ������� �� Word, ���� ��� - �� �������
//try       { vApp=GetActiveOleObject ("Word.Application");}
//catch (...){ vApp=CreateOleObject ("Word.Application");   }

if (!fStart1)
 {
  try
  {
   vApp=CreateOleObject ("Word.Application");
   fStart1=true;
  }
  catch (...)
  {
   MessageBox (0, "������ ��� �������� ������� Word",
                 "������", MB_OK);
  return;
  }
 }

//--- ���������� ������ - ��������

try{vDocs=vApp.OlePropertyGet ("Documents");}
catch (...) {
  try
    {
      vApp=CreateOleObject ("Word.Application");
      fStart1=true;
    }
  catch (...)
  {
   MessageBox (0, "������ ��� �������� ������� Word",
                 "������", MB_OK);
  return;
  }
  vDocs=vApp.OlePropertyGet ("Documents");
}
//--- ���������, ������ �� �����  �������� � ��� ���������, ��� - ������� �����
try       { vDocs.OleProcedure ("Open",WideString (s_name));}
catch (...){ vDocs.OleProcedure ("Add");                }

//--- ������ ��� �������� � �������
vDoc=vDocs.OleFunction ("Item",1);
vDoc.OleProcedure ("Activate");
vApp.OlePropertySet ("Visible",true);
 
Variant ssss=vDoc.OlePropertyGet ("PageSetup");
//��������� ���
ssss.OlePropertySet ("TopMargin",30);
ssss.OlePropertySet ("BottomMargin",15);
//ssss.OlePropertySet ("TopMargin",110);
//ssss.OlePropertySet ("Orientation",1);

//--- ���������� � ������� ��������
vPars=vDoc.OlePropertyGet ("Paragraphs");

//--- ���������� ������� �����
vv=vApp.OlePropertyGet ("Selection");

//--- ��������� ����������: 4- �������, 1 - ����� � ���������
s_a=vDoc.OleFunction ("ComputeStatistics",4);

//s_a=vDoc.OleFunction ("ComputeStatistics",1);

//--- ���������� ������ ����: 4 - �� �������, 5 - �� ��������; �� s_a - ����������
//vv.OleFunction ("MoveDown",4,s_a);
//vv.OleFunction ("MoveDown",5,s_a);

//--- ���������� ����������  Paragraphs:                   //12  �  5 �������
// ���������� ������� + ���������� ������ ������� (6 (������ 11))* �� ���������� ������� (� ������ ������� �� 4 ������)
//s_a=s_a+ (s_a/4*6);

//s_a=s_a+ (s_a/4*11);

//��� ���������� ������� + ���������� ������ ������� (6 (������ 13))* �� ���������� ������� (� ������ ������� �� 4 ������)�
s_a=s_a+ (s_a/4*12);

//---------�������� ����-----
for (int i=0;i<n_ch;i++)
{//for ������ �����


//��������� ��������
vPars.OleProcedure ("Add"); s_a++;
//������������� ������� ��������
vPar=vPars.OleFunction ("Item",s_a);   //1

//--------------- ���
//������� �����  ���� ��������������� �������
str=mas_memo[i];
//������� �����
vPar.OlePropertyGet ("Range").OlePropertySet ("Text",WideString (str));
//������� (PageBreakBefore) � ����� �������� - ������ �������� (& 1 - ������ ��� =1)
//if (i % 2 == 0) vPar.OlePropertySet ("PageBreakBefore",true);
//else vPar.OlePropertySet ("PageBreakBefore",false);
vPar.OlePropertySet ("Alignment",2);
vPar=vPar.OlePropertyGet ("Range").OlePropertyGet ("Font");
vPar.OlePropertySet ("Size",15);

vPars.OleProcedure ("Add"); s_a++;

vPar=vPars.OleFunction ("Item",s_a);   //2
str="";
//������� �����
vPar.OlePropertyGet ("Range").OlePropertySet ("Text",WideString (str));
vPar.OlePropertySet ("PageBreakBefore",false);
Variant vr=vDoc.OlePropertyGet ("PageSetup");
vr.OlePropertySet ("TopMargin",0);
vr.OlePropertySet ("BottomMargin",0);
vPars.OleProcedure ("Add"); s_a++;
//vPars.OleProcedure ("Add"); s_a++;
//vPars.OleProcedure ("Add"); s_a++;
//vPars.OleProcedure ("Add"); s_a++;
//vPars.OleProcedure ("Add"); s_a++;
//vPars.OleProcedure ("Add"); s_a++;
//vPars.OleProcedure ("Add"); s_a++;



//------------------
vPar=vPars.OleFunction ("Item",s_a); //3
str="�������";
vPar.OlePropertySet ("FirstLineIndent",0);
vPar.OlePropertyGet ("Range").OlePropertySet ("Text",WideString (str));
//��������� ������  ��� ���������
vPar.OlePropertySet ("Alignment",1);
vPar.OlePropertySet ("LeftIndent",0);
vPar.OlePropertySet ("RightIndent",0);


//��������� ������ - �� �������� �� ����������
vPar.OlePropertySet ("KeepWithNext",true);
vPar.OlePropertySet ("KeepTogether",true);
//����� � ������
vv=vPar.OlePropertyGet ("Range").OlePropertyGet ("Font");
vv.OlePropertySet ("Size",15);
Variant vv=vDoc.OlePropertyGet ("PageSetup");
vv.OlePropertySet ("TopMargin",30);
vv.OlePropertySet ("BottomMargin",15);
//vv.OlePropertySet ("Bold",true);

//��������� ��������  �  ������������� ������� ��������
vPars.OleProcedure ("Add"); s_a++;
vPars.OleProcedure ("Add"); s_a++;
vPar=vPars.OleFunction ("Item",s_a);  //4

//��������� ������  ��� ������
vPar.OlePropertySet ("Alignment",3);
vPar.OlePropertySet ("LeftIndent",0);
vPar.OlePropertySet ("RightIndent",0);

vPar.OlePropertySet ("FirstLineIndent",170);
//vPar.OlePropertySet ("FirstLineIndent",100);

vv=vPar.OlePropertyGet ("Range").OlePropertyGet ("Font");
vv.OlePropertySet ("Size",15);
vv.OlePropertySet ("Bold",false);

//������� �����

//str="���� � ���, ��� ";  //+ ���
str="";
str+=   DataModule1 -> People_SpravkiFDQueryFAM -> Value+" "+
        DataModule1 -> People_SpravkiFDQueryNAME -> Value+" "+
        DataModule1 -> People_SpravkiFDQueryOTCH -> Value;
str+=" �������� ��������� (��) "+AnsiString (DataModule1 -> People_SpravkiFDQueryKURS -> Value); //+����
str+=" ����� "; //+��������, ��������
str+=DataModule1 -> People_SpravkiFDQueryN_GROUP -> Value+" ������ "; //+ ���������

if (DataModule1 -> People_SpravkiFDQueryVID_EDU -> Value) str+="������� ����� ��������� ����������� ";
else  str+="������� ����� ��������� ����������� ";

AnsiString decan="";
AnsiString fac_short="";
//���������� ���������
switch (nom_fac)
   { //switch  ���������
      case 1: str+="���������-��������������� ���������� ���������� ��� � �����������";
              decan="�.�.��������";
              fac_short="��� ����";
              break;
      case 2: str+="���������-��������������� ���������� �������� ����� ������";
              decan="�.�.����������";
              fac_short="��� ���";
              break;
      case 3: str+="���������� ��������������� ���������� �������� � �������";
              decan="�.�.���������";
              fac_short="���������� �����";
              break;
      case 4: str+="��������� ����������� ������ � �������";
              decan="�.�.���������";
              fac_short="";
              break;
   }//end switch  ���������

//str+=" �� \"����������� ��������������� ����������� ���������� ��������\". ";
str+=" ���������� ����������� \"����������� ��������������� ����������� ���������� ��������\". ";

if (CheckBox21 -> Checked) str+=Memo21 -> Text; //�������� 1-�� �/�
if (CheckBox22 -> Checked)  //  ��������� �� ���� ������� ��� �� ��������
   {//if ��������� �� ���� ������� ��� �� ��������
        if (DataModule1 -> People_SpravkiFDQueryN_FOUND -> Value==2)  str+="��������� �� ������ �� ��������. ";
        else str+="��������� �� ���� ������� ���������������� �������. ";
   }//end if

if (CheckBox23 -> Checked) //  ��������������� ���� ��������� �������� ���������
   { //if ��������������� ���� ��������� �������� ���������
       AnsiString konec="";
       if (DataModule1 -> People_SpravkiFDQueryVID_EDU -> Value)
           {//if   �������� ���������
              //!!!!!!���������� ������ ���!!!!!!!!!!!!!
              switch (DataModule1 -> People_SpravkiFDQueryKURS -> Value)
                 { //switch  ����
                  case 1:
                  konec="������ " +IntToStr (uch_god+5)+ " ����.";
                  break;
                  case 2:
                  konec="������ " +IntToStr (uch_god+4)+ " ����.";
                  break;
                  case 3:
                  konec="������ " +IntToStr (uch_god+3)+ " ����.";
                  break;
                  case 4:
                  konec="������ " +IntToStr (uch_god+2)+ " ����.";
                  break;
                  case 5:
                  konec="������ " +IntToStr (uch_god+1)+ " ����.";
                  break;
                 }

          /*    if (DataModule1 -> People_SpravkiQueryKURS -> Value>4)
              {
                 konec="������ "+
                 AnsiString (uch_god+ (8-DataModule1 -> People_SpravkiQueryKURS -> Value))+
              " ����. ";
              }
              else
              {
                 konec="������ "+
                 AnsiString (uch_god+ (7-DataModule1 -> People_SpravkiQueryKURS -> Value))+
              " ����. ";
              }     */
           }//end if   �������� ���������
       else
           {//else  �������� ���������
               //!!!!!!���������� ������ ���!!!!!!!!!!!!!
               switch (DataModule1 -> People_SpravkiFDQueryKURS -> Value)
                 { //switch  ����
                  case 1:
                  konec="���� " +IntToStr (uch_god+4)+ " ����.";
                  break;
                  case 2:
                  konec="���� " +IntToStr (uch_god+3)+ " ����.";
                  break;
                  case 3:
                  konec="���� " +IntToStr (uch_god+2)+ " ����.";
                  break;
                  case 4:
                  konec="���� " +IntToStr (uch_god+1)+ " ����.";
                  break;
                }
              /*   if (DataModule1 -> People_SpravkiQueryKURS -> Value>4)
              {
                 konec="���� "+
                 AnsiString (uch_god+ (7-DataModule1 -> People_SpravkiQueryKURS -> Value))+
                 " ����. ";
              }
               else
              {
                 konec="���� "+
                 AnsiString (uch_god+ (6-DataModule1 -> People_SpravkiQueryKURS -> Value))+
              " ����. ";
              }   */
           }//end else  �������� ���������

      str+=Memo23 -> Text+" - "+konec;
   }
if (CheckBox24 -> Checked) str+=" "+Memo24 -> Text;   //��������������� ����� ������

//������� �����
vPar.OlePropertyGet ("Range").OlePropertySet ("Text",WideString (str));

//��������� ��������  �  ������������� ������� ��������
vPars.OleProcedure ("Add"); s_a++;

vPar=vPars.OleFunction ("Item",s_a);  //5

vPar.OlePropertySet ("Alignment",3);
vPar.OlePropertySet ("LeftIndent",0);
vPar.OlePropertySet ("RightIndent",0);
vPars.OleProcedure ("Add"); s_a++;
//vPar.OlePropertySet ("FirstLineIndent",40);     //FirstLineIndent

 //-------------
//vPar.OlePropertySet ("FirstLineIndent",0);
//������� �����
//str="������ ��� ������������� "+mas_memo[i];

//������� �����
//vPar.OlePropertyGet ("Range").OlePropertySet ("Text",str.c_str ());
//-------------------
//��������� ��������   �  ������������� ������� ��������

vPar=vPars.OleFunction ("Item",s_a);    //8 6
vPar.OlePropertySet ("FirstLineIndent",0);
str="����� "+fac_short+"                                                  " + decan;

//str="����� "+fac_short+"\t"+decan;
//vPar.OlePropertyGet ("FormatTabs").OlePropertySet ("Position",12.00);

vPar.OlePropertyGet ("Range").OlePropertySet ("Text",WideString (str));
//vPars.OleProcedure ("Add"); s_a++;
vPar.OlePropertySet ("KeepWithNext",false);
vPar.OlePropertySet ("KeepTogether",false);
Variant vt=vDoc.OlePropertyGet ("PageSetup");
vt.OlePropertySet ("TopMargin",40);
vt.OlePropertySet ("BottomMargin",30);
vPars.OleProcedure ("Add"); s_a++;
vPars.OleProcedure ("Add"); s_a++;
vPars.OleProcedure ("Add"); s_a++;
vPars.OleProcedure ("Add"); s_a++;
vPars.OleProcedure ("Add"); s_a++;
vPars.OleProcedure ("Add"); s_a++;
vPars.OleProcedure ("Add"); s_a++;
vPars.OleProcedure ("Add"); s_a++;
vPars.OleProcedure ("Add"); s_a++;



/*
//���������� ��������� �������
v=vApp.OlePropertyGet ("Selection");
//�������� ������ �� �������� (4) ���� �� 9
v.OleProcedure ("MoveDown",4,s_a);   //9
//��������� ������ ��������
v.OleFunction ("InsertBreak",0);   */

}//end for ����� �����

AnsiString name="D:\\��� ���������\\������� ��������� �� ";
name+=DateToStr (curent_date)+".doc";
vDoc.OleProcedure ("SaveAs",WideString (name));

ShowMessage ("������� �������� � Word �������!");

LabeledEdit1 -> Text="";
LabeledEdit1 -> SetFocus ();
refrech_memo_ch ();

for (int j=0;j<20;j++) mas_memo[j]="";
n_ch=0;

}
//---------------------------------------------------------------------------

void __fastcall TSpavkiForm::CheckBox17Click (TObject *Sender)
{

if (CheckBox17 -> Checked) ComboBox1 -> Visible=true;
else ComboBox1 -> Visible=false;

ComboBox1 -> ItemIndex=-1;
}
//---------------------------------------------------------------------------
void __fastcall TSpavkiForm::CheckBox18Click (TObject *Sender)
{
if (CheckBox18 -> Checked) ComboBox2 -> Visible=true;
else ComboBox2 -> Visible=false;

ComboBox2 -> ItemIndex=-1;

}
//---------------------------------------------------------------------------
void __fastcall TSpavkiForm::FormClose (TObject *Sender,
      TCloseAction &Action)
{
s_a=0;
Action=caFree;
}
//---------------------------------------------------------------------------

void __fastcall TSpavkiForm::RadioGroup1Click (TObject *Sender)
{
LabeledEdit1 -> Visible=true;
DBGrid1 -> Visible=true;
Panel2 -> Visible=true;
Panel3 -> Visible=true;
Panel4 -> Visible=true;

DataModule1 -> People_SpravkiFDQuery -> Close ();
DataModule1 -> People_SpravkiFDQuery -> ParamByName ("FAC") -> AsSmallInt=nom_fac;
DataModule1 -> People_SpravkiFDQuery -> ParamByName ("EDU") -> AsSmallInt=RadioGroup1 -> ItemIndex;
DataModule1 -> People_SpravkiFDQuery -> Open ();
refrech_memo_ch ();
SpavkiForm -> Height=620;
LabeledEdit1 -> SetFocus ();
}
//---------------------------------------------------------------------------

void __fastcall TSpavkiForm::LabeledEdit1Change (TObject *Sender)
{
Set<TLocateOption,0,1> f;
f << loCaseInsensitive << loPartialKey;
DataModule1 -> People_SpravkiFDQuery -> Locate ("FAM", LabeledEdit1 -> Text, f);
}
//---------------------------------------------------------------------------
void __fastcall TSpavkiForm::ApplicationEvents1Message (tagMSG &Msg,
      bool &Handled)
{
 //������������ ���������� ������ �������� �������� � DBGrid

if (DBGrid1 -> Focused ())
{
 if (Msg.message == WM_MOUSEWHEEL)
 {
    Msg.message = WM_KEYDOWN;
    Msg.lParam = 0;
    short int i = HIWORD (Msg.wParam);
    Msg.wParam = (i > 0)?VK_UP:VK_DOWN;
    Handled = false;
  }
}
}
//---------------------------------------------------------------------------







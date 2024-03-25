#include <vcl.h>
#pragma hdrstop


#include "Add_UchKartUnit.h"
#include "DataModule.h"
#include "DM2Unit.h"
#include "MainUnit.h"
#include "Perezach_UchKartUnit.h"
#include "SpisocUnit.h"
#include "StudUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TSpisocForm * SpisocForm;


// AnsiString SQLText = "                                                  \
//     SELECT                                                              \
//         People.NOMER,                                                   \
//         People.FAM,                                                     \
//         People.OTCH,                                                    \
//         People.NAME,                                                    \
//         People.VID_EDU,                                                 \
//         People.N_FAC,                                                   \
//         People.KURS,                                                    \
//         People.N_GROUP,                                                 \
//         People.INC_GROUP,                                               \
//         Sport.SPORT_CATEGORY,                                           \
//         Vid_sport.VID_SPORT,                                            \
//         Foundation.VID_FOUND                                            \
//     FROM                                                                \
//         PEOPLE People                                                   \
//             INNER JOIN                                                  \
//                 SPORT Sport                                             \
//                     ON                                                  \
//                         (People.NOMER = Sport.NOMER)                    \
//             INNER JOIN                                                  \
//                 VID_SPORT Vid_sport                                     \
//                     ON                                                  \
//                         (People.N_VID_SPORT = Vid_sport.N_VID_SPORT)    \
//             INNER JOIN                                                  \
//                 FOUNDATION Foundation                                   \
//                     ON                                                  \
//                         (People.N_FOUND = Foundation.N_FOUND)           \
//     ";

AnsiString SQLText = "                                                  \
    SELECT                                                              \
        NOMER,                                                          \
        FAM,                                                            \
        OTCH,                                                           \
        NAME,                                                           \
        VID_EDU,                                                        \
        N_FAC,                                                          \
        KURS,                                                           \
        N_GROUP,                                                        \
        INC_GROUP                                                       \
    FROM                                                                \
        PEOPLE                                                          \
    ";

AnsiString Old_sql_result_head = "                                      \
    SELECT                                                              \
        Result_ball.NOMER,                                              \
        Result_ball.RESULT,                                             \
        Result_ball.DATE_RESULT,                                        \
        Result_ball.STATUS_RESULT,                                      \
        Result_ball.N_PLAN,                                             \
        Edu_plan.SEMESTR,                                               \
        Edu_plan.N_FAC,                                                 \
        Edu_plan.ZACH_EXAM,                                             \
        Edu_plan.VID_EDU_PLAN,                                          \
        Edu_plan.YEAR_PLAN,                                             \
        Edu_plan.CLOCK_PLAN,                                            \
        Edu_plan.CLOCK_PLAN_ALL,                                        \
        Edu_plan.N_OBJECT,                                              \
        Object_plan.NAME_OBJECT                                         \
    FROM                                                                \
        RESULT_BALL Result_ball                                         \
            INNER JOIN                                                  \
                EDU_PLAN Edu_plan                                       \
                    ON                                                  \
                        (Result_ball.N_PLAN = Edu_plan.N_PLAN)          \
            INNER JOIN                                                  \
                OBJECT_PLAN Object_plan                                 \
                    ON                                                  \
                        (Edu_plan.N_OBJECT  = Object_plan.N_OBJECT)     \
    WHERE                                                               \
        Result_ball.NOMER = :NOM                                        \
    ";

AnsiString Old_sql_result = "                                           \
    ORDER BY                                                            \
        Result_ball.NOMER,                                              \
        Edu_plan.SEMESTR,                                               \
        Edu_plan.ZACH_EXAM,                                             \
        Object_plan.NAME_OBJECT                                         \
    ";

int       status            = 1;                                                // статус студента (1 - действующий, 2 - отчисленный)

TBookmark Bookmark_spisok;



__fastcall TSpisocForm::TSpisocForm (TComponent * Owner)
    : TForm (Owner)
{ }



// ApplicationEvents1Message
// BitBtn1Click
// BitBtn2Click
// CheckBox1Click
// CheckBox2Click
// CheckBox3Click
// CheckBox4Click
// CheckBox5Click
// CheckBox6Click
// DBGrid1CellClick
// DBGrid1DblClick
// DBGrid2CellClick
// DBGrid2DblClick
// Edit1Change
// Edit2Change
// Edit2KeyPress
// FormActivate
// FormClose
// RadioGroup1Click
// RadioGroup2Click
// RG1Click
// RG2Click





void __fastcall TSpisocForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
//!!!if (Application -> MessageBox ("    Закрыть форму по итоговой успеваемости?", "", MB_YESNO) == mrYes)
if (MessageDlg ("    Закрыть форму по итоговой успеваемости?", mtConfirmation, TMsgDlgButtons () << mbYes << mbNo,0) == mrYes)
                {
                /*if (Bookmark_spisok)
                        { //if закладка
        
                                DataModule1 -> Spisoc_Query -> FreeBookmark (Bookmark_spisok);
                        }//end if закладка      */

                //!!!Bookmark_spisok=NULL;
            Action = caFree;
                result_itog=false;//переменная которая определяет нужно ли использовать калькулейтед-поля
                add_card=false;//переменная для перехода на студента после добавления записей в учебную карточку
                }
      else
            Action = caNone;
}

void __fastcall TSpisocForm::CheckBox1Click (TObject *Sender)
{
if (CheckBox1 -> Checked)
 {
  RG1 -> ItemIndex=-1;
  DataModule1 -> Spisoc_FDQuery -> Close ();
  DataModule1 -> Spisoc_FDQuery -> SQL -> Clear ();
  DataModule1 -> Spisoc_FDQuery -> SQL -> Add (SQLText+"WHERE  (STATUS_PEOPLE=:NOMER) AND (N_FAC=:N_FAC) AND (VID_EDU="+AnsiString (RG2 -> ItemIndex)+") ORDER BY FAM");
  DataModule1 -> Spisoc_FDQuery -> Params -> Items[0] -> AsInteger=status;
  DataModule1 -> Spisoc_FDQuery -> Params -> Items[1] -> AsInteger=nom_fac;
  DataModule1 -> Spisoc_FDQuery -> Open ();
  CheckBox1 -> Enabled = false;
  }
}




void __fastcall TSpisocForm::RG1Click (TObject *Sender)
{
 DataModule1 -> Spisoc_FDQuery -> Close ();
  DataModule1 -> Spisoc_FDQuery -> SQL -> Clear ();
  DataModule1 -> Spisoc_FDQuery -> SQL -> Add (SQLText+"WHERE (STATUS_PEOPLE=:NOMER) AND (N_FAC=:N_FAC) AND (VID_EDU="+AnsiString (RG2 -> ItemIndex)+") AND (KURS="+AnsiString (RG1 -> ItemIndex+1)+") ORDER BY FAM");
  DataModule1 -> Spisoc_FDQuery -> Params -> Items[0] -> AsInteger=status;
  DataModule1 -> Spisoc_FDQuery -> Params -> Items[1] -> AsInteger=nom_fac;
  DataModule1 -> Spisoc_FDQuery -> Open ();
 CheckBox1 -> State = cbUnchecked;
 CheckBox1 -> Enabled = true;

   Panel2 -> Visible=false;
}


void __fastcall TSpisocForm::RG2Click (TObject *Sender)
{
RG1 -> ItemIndex=-1;
//CheckBox1 -> Checked=true;
  DataModule1 -> Spisoc_FDQuery -> Close ();
  DataModule1 -> Spisoc_FDQuery -> SQL -> Clear ();
  DataModule1 -> Spisoc_FDQuery -> SQL -> Add (SQLText+"WHERE  (STATUS_PEOPLE=:NOMER) AND (N_FAC=:N_FAC) AND (VID_EDU="+AnsiString (RG2 -> ItemIndex)+") ORDER BY FAM");
  DataModule1 -> Spisoc_FDQuery -> Params -> Items[0] -> AsInteger=status;
  DataModule1 -> Spisoc_FDQuery -> Params -> Items[1] -> AsInteger=nom_fac;
  DataModule1 -> Spisoc_FDQuery -> Open ();

  Panel2 -> Visible=false;  
}



void __fastcall TSpisocForm::DBGrid1DblClick (TObject *Sender)
{
/*status_people_query=1;
if (!MainForm -> SearchChild ("StudForm"))//Если форма не найдена, то
      StudForm = new TStudForm (Application);
  StudForm -> Show ();

  


if (StudForm -> CheckBox3 -> Checked==true)
  StudForm -> CheckBox3 -> Checked=false;

Set<TLocateOption,0,1> flags;
DataModule1 -> PeopleQuery -> Locate ("NOMER",DataModule1 -> Spisoc_QueryNOMER -> Value,flags);
StudForm -> TabSheet1 -> Show (); 
DataModule1 -> Result_BallQuery -> Close ();
DataModule1 -> Result_BallQuery -> ParamByName ("NOM") -> AsInteger=DataModule1 -> Spisoc_QueryNOMER -> Value;
DataModule1 -> Result_BallQuery -> Open ();    */

}


void __fastcall TSpisocForm::FormActivate (TObject *Sender)
{
Edit1 -> SetFocus ();
if (add_card /*!!!&& Bookmark_spisok*/) //переменная если заносили записи в учебную карточку,
{  //то Query закрывать не надо

     DataModule1 -> Spisoc_FDQuery -> GotoBookmark (Bookmark_spisok);
     DataModule1 -> Spisoc_FDQuery -> FreeBookmark (Bookmark_spisok);
     //!!!Bookmark_spisok=NULL;

 if (!Panel2 -> Visible) Panel2 -> Visible=true;
 GroupBox2 -> Visible=true;
DataModule1 -> Result_BallFDQuery -> Close ();
DataModule1 -> Result_BallFDQuery -> ParamByName ("NOM") -> AsInteger=DataModule1 -> Spisoc_FDQueryNOMER -> Value;
DataModule1 -> Result_BallFDQuery -> Open ();
//------  Занесение в Label значение ФИО
Label1 -> Caption=DataModule1 -> Spisoc_FDQueryFAM -> Value;
Label2 -> Caption=DataModule1 -> Spisoc_FDQueryNAME -> Value;
Label3 -> Caption=DataModule1 -> Spisoc_FDQueryOTCH -> Value;
//------

}
else
{
DataModule1 -> Spisoc_FDQuery -> Close ();
DataModule1 -> Spisoc_FDQuery -> Params -> Items[0] -> AsInteger=status;
DataModule1 -> Spisoc_FDQuery -> Params -> Items[1] -> AsInteger=nom_fac;
DataModule1 -> Spisoc_FDQuery -> Open ();
DataModule1 -> Result_BallFDQuery -> Close ();
}
result_itog=true;
}


void __fastcall TSpisocForm::DBGrid1CellClick (TColumn *Column)
{

if (!Panel2 -> Visible) Panel2 -> Visible=true;
GroupBox2 -> Visible=true;
BitBtn2 -> Visible=false;//кнопка Перезачет  
DataModule1 -> Result_BallFDQuery -> Close ();
DataModule1 -> Result_BallFDQuery -> ParamByName ("NOM") -> AsInteger=DataModule1 -> Spisoc_FDQueryNOMER -> Value;
DataModule1 -> Result_BallFDQuery -> Open ();
//------  Занесение в Label значение ФИО
Label1 -> Caption=DataModule1 -> Spisoc_FDQueryFAM -> Value;
Label2 -> Caption=DataModule1 -> Spisoc_FDQueryNAME -> Value;
Label3 -> Caption=DataModule1 -> Spisoc_FDQueryOTCH -> Value;
//------

}


void __fastcall TSpisocForm::DBGrid2DblClick (TObject *Sender)
{
if (DataModule1 -> Spisoc_FDQuery -> RecordCount)
{
//Добавление записей в учебную карточку
Panel2 -> Visible=false;
GroupBox2 -> Visible=false;
Bookmark_spisok=DataModule1 -> Spisoc_FDQuery -> GetBookmark ();
Add_UchKartForm=new TAdd_UchKartForm (this);
Add_UchKartForm -> Show ();
}
else
{
ShowMessage ("Не выбран студент для добавления записей в учебную карточку!");
}

}


void __fastcall TSpisocForm::Edit1Change (TObject *Sender)
{
 Set<TLocateOption,0,1> flags;
    flags << loCaseInsensitive << loPartialKey;
  DataModule1 -> Spisoc_FDQuery -> Locate ("FAM", Edit1 -> Text, flags);
}


void __fastcall TSpisocForm::Edit2Change (TObject *Sender)
{
 CheckBox3 -> Checked=false;        
}


void __fastcall TSpisocForm::CheckBox3Click (TObject *Sender)
{
 if (CheckBox3 -> Checked)
 {  //if если включили выборку студентов по группе
    if ( (Edit2 -> Text!="") && (ComboBox4 -> ItemIndex!=-1))
        { //if проверка на непустые поля номера группы и вида обучения
       // Variant locvalues[]={Edit2 -> Text,ComboBox4 -> ItemIndex};
      //  Variant search_inc_group=DM2 -> Increment_GroupTable -> Lookup ("N_GROUP;VID_EDU",VarArrayOf (locvalues,1),"INC_GROUP");
      Variant search_inc_group;//переменная, которая возвращает инкремент группы

      if (status==1)
        {//if сразу действующий студент
         search_inc_group=search_increment_group (Edit2 -> Text,ComboBox4 -> ItemIndex);
         if (search_inc_group.IsNull ())
            {//if  такой группы не нашлось
                ShowMessage ("Номера группы с таким видом обучения не существует");
                Edit2 -> SetFocus ();
                CheckBox3 -> Checked=false;
                return;
            }//end if такой группы не нашлось
         else
            {//else есть такая группа
             //----
                DataModule1 -> Spisoc_FDQuery -> Close ();
                DataModule1 -> Spisoc_FDQuery -> SQL -> Clear ();
                DataModule1 -> Spisoc_FDQuery -> SQL -> Add (SQLText+"WHERE (STATUS_PEOPLE=:NOMER) AND (N_FAC=:N_FAC) AND (INC_GROUP="+VarToStr (search_inc_group)+") ORDER BY FAM");
                DataModule1 -> Spisoc_FDQuery -> Params -> Items[0] -> AsInteger=status;
                DataModule1 -> Spisoc_FDQuery -> Params -> Items[1] -> AsInteger=nom_fac;
                DataModule1 -> Spisoc_FDQuery -> Open ();
            } //end else есть такая группа
         }//if сразу действующий студент
      else
         {//else студент не действующий
          search_inc_group=18;
          DataModule1 -> Spisoc_FDQuery -> Close ();
          DataModule1 -> Spisoc_FDQuery -> SQL -> Clear ();
          DataModule1 -> Spisoc_FDQuery -> SQL -> Add (SQLText+"WHERE (STATUS_PEOPLE=:NOMER) AND (N_FAC=:N_FAC) AND (INC_GROUP="+VarToStr (search_inc_group)+") AND (N_GROUP="+Edit2 -> Text+") AND (VID_EDU="+AnsiString (ComboBox4 -> ItemIndex)+") ORDER BY FAM");
          DataModule1 -> Spisoc_FDQuery -> Params -> Items[0] -> AsInteger=status;
          DataModule1 -> Spisoc_FDQuery -> Params -> Items[1] -> AsInteger=nom_fac;
          DataModule1 -> Spisoc_FDQuery -> Open ();
         }//end else студент не действующий

         //---
         RG1 -> Enabled=false;
         RG1 -> ItemIndex=-1;
         RG2 -> Enabled=false;
         CheckBox1 -> Enabled=false;
         


        }//end if проверка на непустые поля номера группы и вида обучения
    else
        { //else повторный ввод вслучае пустых полей
        ShowMessage ("Введите номер группы и вид обучения");
        Edit2 -> SetFocus ();
        CheckBox3 -> Checked=false;
        } //end else  повторный ввод вслучае пустых полей

  }//end if если включили выборку студентов по группе
else
 {//else отключили выбор по группе
   Edit2 -> Text="";
   ComboBox4 -> ItemIndex=-1;

  RG1 -> Enabled=true;
  RG2 -> Enabled=true;
  CheckBox1 -> Enabled=true;

  DataModule1 -> Spisoc_FDQuery -> Close ();
  DataModule1 -> Spisoc_FDQuery -> SQL -> Clear ();
  DataModule1 -> Spisoc_FDQuery -> SQL -> Add (SQLText+"WHERE (STATUS_PEOPLE=:NOMER) AND (N_FAC=:N_FAC) AND (VID_EDU="+AnsiString (RG2 -> ItemIndex)+") ORDER BY FAM");
  DataModule1 -> Spisoc_FDQuery -> Params -> Items[0] -> AsInteger=status;
  DataModule1 -> Spisoc_FDQuery -> Params -> Items[1] -> AsInteger=nom_fac;
  DataModule1 -> Spisoc_FDQuery -> Open ();

 }//end else отключили выбор по группе
  Panel2 -> Visible=false; 
}


void __fastcall TSpisocForm::RadioGroup1Click (TObject *Sender)
{
CheckBox2 -> State=cbUnchecked;
RadioGroup2 -> Visible=true;
RadioGroup2 -> ItemIndex=-1;
RadioGroup2 -> Items -> Clear ();
int sem1=RadioGroup1 -> ItemIndex*2+1;
RadioGroup2 -> Items -> Add (IntToStr (sem1));
RadioGroup2 -> Items -> Add (IntToStr (sem1+1));
DataModule1 -> Result_BallFDQuery -> Close ();
DataModule1 -> Result_BallFDQuery -> SQL -> Clear ();
DataModule1 -> Result_BallFDQuery -> SQL -> Add (Old_sql_result_head+" AND (Edu_plan.SEMESTR IN ("+RadioGroup2 -> Items -> Strings[0]+","+RadioGroup2 -> Items -> Strings[1]+"))"+Old_sql_result);
DataModule1 -> Result_BallFDQuery -> ParamByName ("NOM") -> AsInteger=DataModule1 -> Spisoc_FDQueryNOMER -> Value;
DataModule1 -> Result_BallFDQuery -> Open ();


}


void __fastcall TSpisocForm::CheckBox2Click (TObject *Sender)
{
if (CheckBox2 -> Checked)
{
RadioGroup2 -> Visible=false;
RadioGroup1 -> ItemIndex=-1;
DataModule1 -> Result_BallFDQuery -> Close ();
DataModule1 -> Result_BallFDQuery -> SQL -> Clear ();
DataModule1 -> Result_BallFDQuery -> SQL -> Add (Old_sql_result_head+Old_sql_result);
DataModule1 -> Result_BallFDQuery -> ParamByName ("NOM") -> AsInteger=DataModule1 -> Spisoc_FDQueryNOMER -> Value;
DataModule1 -> Result_BallFDQuery -> Open ();
}

}


void __fastcall TSpisocForm::RadioGroup2Click (TObject *Sender)
{
DataModule1 -> Result_BallFDQuery -> Close ();
DataModule1 -> Result_BallFDQuery -> SQL -> Clear ();
DataModule1 -> Result_BallFDQuery -> SQL -> Add (Old_sql_result_head+" AND (Edu_plan.SEMESTR="+AnsiString (RadioGroup2 -> Items -> Strings[RadioGroup2 -> ItemIndex])+")"+Old_sql_result);
DataModule1 -> Result_BallFDQuery -> ParamByName ("NOM") -> AsInteger=DataModule1 -> Spisoc_FDQueryNOMER -> Value;

DataModule1 -> Result_BallFDQuery -> Open ();
}


void __fastcall TSpisocForm::BitBtn1Click (TObject *Sender)
{
Close ();        
}




void __fastcall TSpisocForm::DBGrid2CellClick (TColumn *Column)
{
BitBtn2 -> Visible=true;        
}


void __fastcall TSpisocForm::BitBtn2Click (TObject *Sender)
{//действие по кнопке ПЕРЕЗАЧЕТ

if (DataModule1 -> Result_BallFDQuery -> RecordCount)
{//if есть записи в учебной карточке для данного студента
Bookmark_spisok=DataModule1 -> Spisoc_FDQuery -> GetBookmark ();
Perezach_UchKartForm = new TPerezach_UchKartForm (this);
Perezach_UchKartForm -> DateTimePicker1 -> Date = Now ();
Perezach_UchKartForm -> DateTimePicker1 -> Time = StrToTime ("00:00");
Perezach_UchKartForm -> Show ();

}//end if есть записи в учебной карточке для данного студента
else
{
ShowMessage ("Нет предметов, которые можно перезачесть!");
}


}


void __fastcall TSpisocForm::CheckBox4Click (TObject *Sender)
{ //выбор студентов, не относящихся к действующим

// CheckBox4 --  Отчисленные студенты
// CheckBox5 --  Студенты в академ.отпуске
// CheckBox6 --  Студенты повт. года обучения


if (!CheckBox4 -> Checked  && !CheckBox5 -> Checked && !CheckBox6 -> Checked) status=1; //переменная для определения статуса действующего студента
//-------------------------------------
if (CheckBox4 -> Checked)
    {//if  Отчисленные студенты
       CheckBox5 -> Checked=false;
       CheckBox6 -> Checked=false;
       //----
       CheckBox5 -> Enabled=false;
       CheckBox6 -> Enabled=false;
       //----
       status=2; //переменная для определения статуса студента
       //закончили определять статус студента и после этого выполняем Query

       /*DataModule1 -> Spisoc_Query -> Close ();
       DataModule1 -> Spisoc_Query -> Params -> Items[0] -> AsInteger=status;
       DataModule1 -> Spisoc_Query -> Params -> Items[1] -> AsInteger=nom_fac;
       DataModule1 -> Spisoc_Query -> Open ();
       DataModule1 -> Result_BallQuery -> Close ();  */
    }//end if  Отчисленные студенты
else
    {//else  Отчисленные студенты
       CheckBox4 -> Enabled=true;
       CheckBox5 -> Enabled=true;
       CheckBox6 -> Enabled=true;
    }//else  Отчисленные студенты

//-------------------------
  CheckBox3 -> Checked=false;
  CheckBox3Click (this);

}


void __fastcall TSpisocForm::CheckBox5Click (TObject *Sender)
{
if (!CheckBox4 -> Checked  && !CheckBox5 -> Checked && !CheckBox6 -> Checked) status=1; //переменная для определения статуса действующего студента

//-------------------------------------
if (CheckBox5 -> Checked)
    {//if   Студенты в академ.отпуске
       CheckBox4 -> Checked=false;
       CheckBox6 -> Checked=false;
       //----
       CheckBox4 -> Enabled=false;
       CheckBox6 -> Enabled=false;
       //----
       status=3; //переменная для определения статуса студента

    }//end if  Студенты в академ.отпуске
else
    {//else  Студенты в академ.отпуске
       CheckBox4 -> Enabled=true;
       CheckBox5 -> Enabled=true;
       CheckBox6 -> Enabled=true;
    }//else Студенты в академ.отпуске

//-------------------------
    CheckBox3 -> Checked=false;
    CheckBox3Click (this);

}


void __fastcall TSpisocForm::CheckBox6Click (TObject *Sender)
{
if (!CheckBox4 -> Checked  && !CheckBox5 -> Checked && !CheckBox6 -> Checked) status=1; //переменная для определения статуса действующего студента

//-------------------------------------
if (CheckBox6 -> Checked)
    {//if  Студенты повт. года обучения
       CheckBox4 -> Checked=false;
       CheckBox5 -> Checked=false;
       //----
       CheckBox4 -> Enabled=false;
       CheckBox5 -> Enabled=false;
       //----
       status=4; //переменная для определения статуса студента
    }//end if  Студенты повт. года обучения
else
    {//else    Студенты повт. года обучения
       CheckBox4 -> Enabled=true;
       CheckBox5 -> Enabled=true;
       CheckBox6 -> Enabled=true;
    }//else  Студенты повт. года обучения

//-------------------------
   CheckBox3 -> Checked=false;
   CheckBox3Click (this);

}


void __fastcall TSpisocForm::Edit2KeyPress (TObject *Sender, char &Key)
{
DataModule1 -> Edit_Key (Key); //Как сделать, чтобы в TEdit можно было вводить только числа?        
}


void __fastcall TSpisocForm::ApplicationEvents1Message (tagMSG &Msg,
      bool &Handled)
{
 //организовать нормальную работу мышиного колесика в DBGrid

if (DBGrid1 -> Focused () || DBGrid2 -> Focused ())
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



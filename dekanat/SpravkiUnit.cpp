
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

//Сначала массив с данными
AnsiString mas_memo[20];
int n_ch=0;//переменная сколько делать справок
AnsiString WorkDir="D:\\Мои документы\\";
int s_a=0;//номер абзаца

//---------------------------------------------------------------------------
__fastcall TSpavkiForm::TSpavkiForm (TComponent* Owner)
        : TForm (Owner)
{
}
//---------------------------------------------------------------------------
void TSpavkiForm::refrech_memo_ch ()
{ //функция очищения полей Memo и CheckBox-ов
//---MEMO
//--- выбор справок
/*Memo1 -> Text="по месту работы родителей.";
Memo2 -> Text="по месту работы.";
Memo3 -> Text="по месту требования.";
Memo4 -> Text="по месту жительства.";
Memo5 -> Text="в ЖКХ, ЖЭС.";
Memo6 -> Text="в бухгалтерию.";
Memo7 -> Text="в учебное заведение.";
Memo8 -> Text="в студенческое бюро услуг.";
Memo9 -> Text="в горводоканал.";
Memo10 -> Text="в горгаз.";
Memo11 -> Text="в суд.";
Memo12 -> Text="в посольство.";
Memo13 -> Text="в центр по начислению и выплате пенсий и пособий.";
Memo14 -> Text="в центр социальной занятости молодежи.";
Memo15 -> Text="в билетные кассы.";
Memo16 -> Text="в летний оздоровительный лагерь.";
Memo17 -> Text="в РУВД ";
Memo18 -> Text="в администрацию ";
Memo19 -> Text="в сельский совет.";
Memo20 -> Text="";
//--- дополнительная информация
Memo21 -> Text="Получает первое высшее образование. ";
Memo22 -> Text="Обучается за оплату или за счет бюджетных средств. ";
Memo23 -> Text="Планируемый срок окончания учебного заведения";
Memo24 -> Text=""; */

Memo1 -> Text="По месту работы родителей";
Memo2 -> Text="По месту работы";
Memo3 -> Text="По месту требования";
Memo4 -> Text="По месту жительства";
Memo5 -> Text="ЖКХ, ЖЭС";
Memo6 -> Text="Бухгалтерия";
Memo7 -> Text="Учебное заведение";
Memo8 -> Text="Студенческое бюро услуг";
Memo9 -> Text="Горводоканал";
Memo10 -> Text="Горгаз";
Memo11 -> Text="Суд";
Memo12 -> Text="Посольство";
Memo13 -> Text="Центр по начислению и выплате пенсий и пособий";
Memo14 -> Text="Центр социальной занятости молодежи";
Memo15 -> Text="Билетные кассы";
Memo16 -> Text="Летний оздоровительный лагерь";
Memo17 -> Text="РУВД ";
Memo18 -> Text="Администрация ";
Memo19 -> Text="Сельский совет";
Memo20 -> Text="";
//--- дополнительная информация
Memo21 -> Text="Получает первое высшее образование. ";
Memo22 -> Text="Обучается за оплату или за счет бюджетных средств. ";
Memo23 -> Text="Планируемый срок окончания учебного заведения";
Memo24 -> Text="Зачислен приказом от " + DateToStr (SQLTimeStampToDateTime (DataModule1 -> People_SpravkiFDQueryD_PRIKAZ_INCLUDE -> Value)) + " №" + IntToStr (DataModule1 -> People_SpravkiFDQueryN_PRIKAZ_INCLUDE -> Value) + "ст.";


//----  по основным справкам
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
//---- по дополнительной информации
CheckBox21 -> Checked=false;
CheckBox22 -> Checked=false;
CheckBox23 -> Checked=false;
CheckBox24 -> Checked=false;
}
//----------------------------------------------------------------------------
void TSpavkiForm::memo_ch (TCheckBox *ch, TMemo *m, int par)
{ // формирование массива для выдачи нужных справок
//par- 0 ничего делать не надо
//par - 1 надо слепить Memo  и ComboBox1
//par - 2 надо слепить Memo  и ComboBox2


AnsiString text=m -> Text;
if (ch -> Checked)
   {
     switch (par)
        {
          //case 1: text="в "+ComboBox1 -> Text+" РУВД.";
          case 1: text=ComboBox1 -> Text+" РУВД";
                  break;

          //case 2: text+=ComboBox2 -> Text+".";
          case 2: text+=ComboBox2 -> Text;
                  break;
         }
      mas_memo[n_ch]=text;
      n_ch++;  //счетчик по количеству справок
   }
}
//----------------------------------------------------------------------------
void __fastcall TSpavkiForm::Button1Click (TObject *Sender)
{//Кнопка выдать справку


//----  Определяем какие из справок выбраны пользователем
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


//--- определяем имя документа Word за сегодняшнее число
//текущая дата
curent_date=cur_d ();
AnsiString s_name="D:\\Мои документы\\Справки студентов за "+DateToStr (curent_date)+".doc";


//--- Проверка запущен ли Word, если нет - то создаем
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
   MessageBox (0, "Ошибка при открытии сервера Word",
                 "Ошибка", MB_OK);
  return;
  }
 }

//--- Определяем объект - Документ

try{vDocs=vApp.OlePropertyGet ("Documents");}
catch (...) {
  try
    {
      vApp=CreateOleObject ("Word.Application");
      fStart1=true;
    }
  catch (...)
  {
   MessageBox (0, "Ошибка при открытии сервера Word",
                 "Ошибка", MB_OK);
  return;
  }
  vDocs=vApp.OlePropertyGet ("Documents");
}
//--- Проверяем, создан ли такой  документ и его открываем, нет - создаем новый
try       { vDocs.OleProcedure ("Open",WideString (s_name));}
catch (...){ vDocs.OleProcedure ("Add");                }

//--- Делаем его активным и видимым
vDoc=vDocs.OleFunction ("Item",1);
vDoc.OleProcedure ("Activate");
vApp.OlePropertySet ("Visible",true);
 
Variant ssss=vDoc.OlePropertyGet ("PageSetup");
//Исправила Оля
ssss.OlePropertySet ("TopMargin",30);
ssss.OlePropertySet ("BottomMargin",15);
//ssss.OlePropertySet ("TopMargin",110);
//ssss.OlePropertySet ("Orientation",1);

//--- Обращаемся к объекту Параграф
vPars=vDoc.OlePropertyGet ("Paragraphs");

//--- Запоминаем текущий абзац
vv=vApp.OlePropertyGet ("Selection");

//--- Возвращем количество: 4- абзацев, 1 - линий в документе
s_a=vDoc.OleFunction ("ComputeStatistics",4);

//s_a=vDoc.OleFunction ("ComputeStatistics",1);

//--- Перемещаем курсор вниз: 4 - по абзацам, 5 - по строчкам; на s_a - количество
//vv.OleFunction ("MoveDown",4,s_a);
//vv.OleFunction ("MoveDown",5,s_a);

//--- Определяем количество  Paragraphs:                   //12  и  5 абзацев
// количество абзацев + количество пустых строчек (6 (теперь 11))* на количество справок (в каждой справке по 4 абзаца)
//s_a=s_a+ (s_a/4*6);

//s_a=s_a+ (s_a/4*11);

//Оля количество абзацев + количество пустых строчек (6 (теперь 13))* на количество справок (в каждой справке по 4 абзаца)я
s_a=s_a+ (s_a/4*12);

//---------НАЧИНАЕМ ЦИКЛ-----
for (int i=0;i<n_ch;i++)
{//for начало цикла


//добавляем параграф
vPars.OleProcedure ("Add"); s_a++;
//устанавливаем текущий параграф
vPar=vPars.OleFunction ("Item",s_a);   //1

//--------------- Оля
//заносим текст  куда предоставляется справка
str=mas_memo[i];
//заносим текст
vPar.OlePropertyGet ("Range").OlePropertySet ("Text",WideString (str));
//праметр (PageBreakBefore) с новой страницы - каждый нечетный (& 1 - первый бит =1)
//if (i % 2 == 0) vPar.OlePropertySet ("PageBreakBefore",true);
//else vPar.OlePropertySet ("PageBreakBefore",false);
vPar.OlePropertySet ("Alignment",2);
vPar=vPar.OlePropertyGet ("Range").OlePropertyGet ("Font");
vPar.OlePropertySet ("Size",15);

vPars.OleProcedure ("Add"); s_a++;

vPar=vPars.OleFunction ("Item",s_a);   //2
str="";
//заносим текст
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
str="СПРАВКА";
vPar.OlePropertySet ("FirstLineIndent",0);
vPar.OlePropertyGet ("Range").OlePropertySet ("Text",WideString (str));
//параметры шрифта  для заголовка
vPar.OlePropertySet ("Alignment",1);
vPar.OlePropertySet ("LeftIndent",0);
vPar.OlePropertySet ("RightIndent",0);


//параметры абзаца - не отрывать от следующего
vPar.OlePropertySet ("KeepWithNext",true);
vPar.OlePropertySet ("KeepTogether",true);
//шрифт и размер
vv=vPar.OlePropertyGet ("Range").OlePropertyGet ("Font");
vv.OlePropertySet ("Size",15);
Variant vv=vDoc.OlePropertyGet ("PageSetup");
vv.OlePropertySet ("TopMargin",30);
vv.OlePropertySet ("BottomMargin",15);
//vv.OlePropertySet ("Bold",true);

//добавляем параграф  и  устанавливаем текущий параграф
vPars.OleProcedure ("Add"); s_a++;
vPars.OleProcedure ("Add"); s_a++;
vPar=vPars.OleFunction ("Item",s_a);  //4

//параметры шрифта  для текста
vPar.OlePropertySet ("Alignment",3);
vPar.OlePropertySet ("LeftIndent",0);
vPar.OlePropertySet ("RightIndent",0);

vPar.OlePropertySet ("FirstLineIndent",170);
//vPar.OlePropertySet ("FirstLineIndent",100);

vv=vPar.OlePropertyGet ("Range").OlePropertyGet ("Font");
vv.OlePropertySet ("Size",15);
vv.OlePropertySet ("Bold",false);

//заносим текст

//str="Дана в том, что ";  //+ ФИО
str="";
str+=   DataModule1 -> People_SpravkiFDQueryFAM -> Value+" "+
        DataModule1 -> People_SpravkiFDQueryNAME -> Value+" "+
        DataModule1 -> People_SpravkiFDQueryOTCH -> Value;
str+=" является студентом (ой) "+AnsiString (DataModule1 -> People_SpravkiFDQueryKURS -> Value); //+курс
str+=" курса "; //+дневного, заочного
str+=DataModule1 -> People_SpravkiFDQueryN_GROUP -> Value+" группы "; //+ факультет

if (DataModule1 -> People_SpravkiFDQueryVID_EDU -> Value) str+="заочной формы получения образования ";
else  str+="дневной формы получения образования ";

AnsiString decan="";
AnsiString fac_short="";
//определяем факультет
switch (nom_fac)
   { //switch  факультет
      case 1: str+="спортивно-педагогического факультета спортивных игр и единоборств";
              decan="В.И.Новицкая";
              fac_short="СПФ СИиЕ";
              break;
      case 2: str+="спортивно-педагогического факультета массовых видов спорта";
              decan="И.И.Гуслистова";
              fac_short="СПФ МВС";
              break;
      case 3: str+="факультета оздоровительной физической культуры и туризма";
              decan="Н.М.Машарская";
              fac_short="факультета ОФКиТ";
              break;
      case 4: str+="института менеджмента спорта и туризма";
              decan="О.Н.Михайлова";
              fac_short="";
              break;
   }//end switch  факультет

//str+=" УО \"Белорусский государственный университет физической культуры\". ";
str+=" учреждения образования \"Белорусский государственный университет физической культуры\". ";

if (CheckBox21 -> Checked) str+=Memo21 -> Text; //Получает 1-ое в/о
if (CheckBox22 -> Checked)  //  Обучается за счет бюджета или по договору
   {//if Обучается за счет бюджета или по договору
        if (DataModule1 -> People_SpravkiFDQueryN_FOUND -> Value==2)  str+="Обучается за оплату по договору. ";
        else str+="Обучается за счет средств республиканского бюджета. ";
   }//end if

if (CheckBox23 -> Checked) //  Приблизительный срок окончания учебного заведения
   { //if Приблизительный срок окончания учебного заведения
       AnsiString konec="";
       if (DataModule1 -> People_SpravkiFDQueryVID_EDU -> Value)
           {//if   заочного отделения
              //!!!!!!Исправлять каждый год!!!!!!!!!!!!!
              switch (DataModule1 -> People_SpravkiFDQueryKURS -> Value)
                 { //switch  курс
                  case 1:
                  konec="апрель " +IntToStr (uch_god+5)+ " года.";
                  break;
                  case 2:
                  konec="апрель " +IntToStr (uch_god+4)+ " года.";
                  break;
                  case 3:
                  konec="апрель " +IntToStr (uch_god+3)+ " года.";
                  break;
                  case 4:
                  konec="апрель " +IntToStr (uch_god+2)+ " года.";
                  break;
                  case 5:
                  konec="апрель " +IntToStr (uch_god+1)+ " года.";
                  break;
                 }

          /*    if (DataModule1 -> People_SpravkiQueryKURS -> Value>4)
              {
                 konec="апрель "+
                 AnsiString (uch_god+ (8-DataModule1 -> People_SpravkiQueryKURS -> Value))+
              " года. ";
              }
              else
              {
                 konec="апрель "+
                 AnsiString (uch_god+ (7-DataModule1 -> People_SpravkiQueryKURS -> Value))+
              " года. ";
              }     */
           }//end if   заочного отделения
       else
           {//else  дневного отделения
               //!!!!!!Исправлять каждый год!!!!!!!!!!!!!
               switch (DataModule1 -> People_SpravkiFDQueryKURS -> Value)
                 { //switch  курс
                  case 1:
                  konec="июнь " +IntToStr (uch_god+4)+ " года.";
                  break;
                  case 2:
                  konec="июнь " +IntToStr (uch_god+3)+ " года.";
                  break;
                  case 3:
                  konec="июнь " +IntToStr (uch_god+2)+ " года.";
                  break;
                  case 4:
                  konec="июнь " +IntToStr (uch_god+1)+ " года.";
                  break;
                }
              /*   if (DataModule1 -> People_SpravkiQueryKURS -> Value>4)
              {
                 konec="июнь "+
                 AnsiString (uch_god+ (7-DataModule1 -> People_SpravkiQueryKURS -> Value))+
                 " года. ";
              }
               else
              {
                 konec="июнь "+
                 AnsiString (uch_god+ (6-DataModule1 -> People_SpravkiQueryKURS -> Value))+
              " года. ";
              }   */
           }//end else  дневного отделения

      str+=Memo23 -> Text+" - "+konec;
   }
if (CheckBox24 -> Checked) str+=" "+Memo24 -> Text;   //самостоятельный выбор текста

//заносим текст
vPar.OlePropertyGet ("Range").OlePropertySet ("Text",WideString (str));

//добавляем параграф  и  устанавливаем текущий параграф
vPars.OleProcedure ("Add"); s_a++;

vPar=vPars.OleFunction ("Item",s_a);  //5

vPar.OlePropertySet ("Alignment",3);
vPar.OlePropertySet ("LeftIndent",0);
vPar.OlePropertySet ("RightIndent",0);
vPars.OleProcedure ("Add"); s_a++;
//vPar.OlePropertySet ("FirstLineIndent",40);     //FirstLineIndent

 //-------------
//vPar.OlePropertySet ("FirstLineIndent",0);
//заносим текст
//str="Выдана для представления "+mas_memo[i];

//заносим текст
//vPar.OlePropertyGet ("Range").OlePropertySet ("Text",str.c_str ());
//-------------------
//добавляем параграф   и  устанавливаем текущий параграф

vPar=vPars.OleFunction ("Item",s_a);    //8 6
vPar.OlePropertySet ("FirstLineIndent",0);
str="Декан "+fac_short+"                                                  " + decan;

//str="Декан "+fac_short+"\t"+decan;
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
//запоминаем положение курсора
v=vApp.OlePropertyGet ("Selection");
//сдвигаем курсор на параграф (4) вниз на 9
v.OleProcedure ("MoveDown",4,s_a);   //9
//вставляем разрыв страницы
v.OleFunction ("InsertBreak",0);   */

}//end for конец цикла

AnsiString name="D:\\Мои документы\\Справки студентов за ";
name+=DateToStr (curent_date)+".doc";
vDoc.OleProcedure ("SaveAs",WideString (name));

ShowMessage ("Справка передана в Word успешно!");

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
 //организовать нормальную работу мышиного колесика в DBGrid

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







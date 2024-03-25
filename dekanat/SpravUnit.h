#pragma once
#ifndef SPRAV_UNIT_H
#define SPRAV_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>


class TSpravForm
    : public TForm
{
__published:
    TBitBtn      * BitBtn1;

    TButton      * Button1;
    TButton      * Button2;
    TButton      * Button3;
    TButton      * Button4;
    TButton      * Button5;
    TButton      * Button6;
    TButton      * Button7;
    TButton      * Button8;
    TButton      * Button9;
    TButton      * Button10;
    TButton      * Button11;
    TButton      * Button12;
    TButton      * Button13;
    TButton      * Button14;
    TButton      * Button15;
    TButton      * Button16;
    TButton      * Button17;
    TButton      * Button18;
    TButton      * Button19;
    TButton      * Button20;
    TButton      * Button21;
    TButton      * Button22;

    TComboBox    * ComboBox1;

    TDBGrid      * DBGrid1;
    TDBGrid      * DBGrid2;
    TDBGrid      * DBGrid3;
    TDBGrid      * DBGrid4;
    TDBGrid      * DBGrid5;
    TDBGrid      * DBGrid6;
    TDBGrid      * DBGrid7;
    TDBGrid      * DBGrid8;
    TDBGrid      * DBGrid9;
    TDBGrid      * DBGrid10;
    TDBGrid      * DBGrid11;
    TDBGrid      * DBGrid12;
    TDBGrid      * DBGrid13;
    TDBGrid      * DBGrid14;

    TDBNavigator * DBNavigator1;

    TLabel       * Label1;
    TLabel       * Label2;
    TLabel       * Label3;
    TLabel       * Label4;
    TLabel       * Label5;
    TLabel       * Label6;
    TLabel       * Label7;
    TLabel       * Label8;
    TLabel       * Label9;
    TLabel       * Label10;
    TLabel       * Label11;
    TLabel       * Label12;
    TLabel       * Label13;
    TLabel       * Label14;

    TPageControl * PageControl1;

    TPanel       * Panel1;
    TPanel       * Panel2;
    TPanel       * Panel3;
    TPanel       * Panel4;
    TPanel       * Panel5;
    TPanel       * Panel6;
    TPanel       * Panel7;
    TPanel       * Panel8;
    TPanel       * Panel9;
    TPanel       * Panel10;
    TPanel       * Panel11;
    TPanel       * Panel12;
    TPanel       * Panel13;
    TPanel       * Panel14;
    TPanel       * Panel15;
    TPanel       * Panel16;
    TPanel       * Panel17;
    TPanel       * Panel18;
    TPanel       * Panel19;
    TPanel       * Panel20;
    TPanel       * Panel21;
    TPanel       * Panel22;
    TPanel       * Panel23;
    TPanel       * Panel24;
    TPanel       * Panel25;
    TPanel       * Panel26;
    TPanel       * Panel27;

    TTabSheet    * TabSheet1;
    TTabSheet    * TabSheet2;
    TTabSheet    * TabSheet3;
    TTabSheet    * TabSheet4;
    TTabSheet    * TabSheet5;
    TTabSheet    * TabSheet6;
    TTabSheet    * TabSheet7;
    TTabSheet    * TabSheet8;
    TTabSheet    * TabSheet9;
    TTabSheet    * TabSheet10;
    TTabSheet    * TabSheet11;
    TTabSheet    * TabSheet12;


    void __fastcall Button1Click    (TObject * Sender);
    void __fastcall Button2Click    (TObject * Sender);
    void __fastcall Button3Click    (TObject * Sender);
    void __fastcall Button4Click    (TObject * Sender);
    void __fastcall Button5Click    (TObject * Sender);
    void __fastcall Button6Click    (TObject * Sender);
    void __fastcall Button7Click    (TObject * Sender);
    void __fastcall Button8Click    (TObject * Sender);
    void __fastcall Button9Click    (TObject * Sender);
    void __fastcall Button10Click   (TObject * Sender);
    void __fastcall Button11Click   (TObject * Sender);
    void __fastcall Button12Click   (TObject * Sender);
    void __fastcall Button13Click   (TObject * Sender);
    void __fastcall Button14Click   (TObject * Sender);
    void __fastcall Button15Click   (TObject * Sender);
    void __fastcall Button16Click   (TObject * Sender);
    void __fastcall Button17Click   (TObject * Sender);
    void __fastcall Button18Click   (TObject * Sender);
    void __fastcall Button19Click   (TObject * Sender);
    void __fastcall Button20Click   (TObject * Sender);
    void __fastcall Button21Click   (TObject * Sender);
    void __fastcall Button22Click   (TObject * Sender);
    void __fastcall ComboBox1Change (TObject * Sender);
    void __fastcall DBGrid5Enter    (TObject * Sender);
    void __fastcall DBGrid6Enter    (TObject * Sender);
    void __fastcall FormClose       (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall TabSheet1Enter  (TObject * Sender);
    void __fastcall TabSheet2Enter  (TObject * Sender);
    void __fastcall TabSheet3Enter  (TObject * Sender);
    void __fastcall TabSheet4Enter  (TObject * Sender);
    void __fastcall TabSheet5Enter  (TObject * Sender);
    void __fastcall TabSheet6Enter  (TObject * Sender);
    void __fastcall TabSheet7Enter  (TObject * Sender);
    void __fastcall TabSheet8Enter  (TObject * Sender);
    void __fastcall TabSheet8Exit   (TObject * Sender);
    void __fastcall TabSheet8Show   (TObject * Sender);
    void __fastcall TabSheet9Enter  (TObject * Sender);
    void __fastcall TabSheet10Enter (TObject * Sender);
    void __fastcall TabSheet11Enter (TObject * Sender);
    void __fastcall TabSheet12Show  (TObject * Sender);
private:
public:
    __fastcall TSpravForm (TComponent * Owner);
};

extern PACKAGE TSpravForm * SpravForm;

#endif  // SPRAV_UNIT_H
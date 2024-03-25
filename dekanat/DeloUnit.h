#pragma once
#ifndef DELO_UNIT_H
#define DELO_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
// #include <DBTables.hpp>
// #include "DualList.hpp"
#include <ExtCtrls.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
// #include "MyList.h"
// #include "RXDBCtrl.hpp"
#include <StdCtrls.hpp>
// #include "ToolEdit.hpp"
#include <Vcl.Imaging.jpeg.hpp>


class TDeloForm
    : public TForm
{
__published:
    TBevel            * Bevel1;

    TBitBtn           * BitBtn1;
    TBitBtn           * BitBtn2;
    TBitBtn           * BitBtn3;
    TBitBtn           * BitBtn4;
    TBitBtn           * BitBtn5;
    TBitBtn           * BitBtn6;
    TBitBtn           * BitBtn7;
    TBitBtn           * BitBtn8;
    TBitBtn           * BitBtn9;
    TBitBtn           * BitBtn10;
    TBitBtn           * BitBtn11;
    TBitBtn           * BitBtn12;
    TBitBtn           * BitBtn13;
    TBitBtn           * BitBtn14;
    TBitBtn           * BitBtn15;
    TBitBtn           * BitBtn16;
    TBitBtn           * BitBtn17;
    TBitBtn           * BitBtn18;
    TBitBtn           * BitBtn19;
    TBitBtn           * BitBtn20;
    TBitBtn           * BitBtn21;
    TBitBtn           * BitBtn22;
    TBitBtn           * BitBtn23;
    TBitBtn           * BitBtn24;
    TBitBtn           * BitBtn25;
    TBitBtn           * BitBtn26;
    TBitBtn           * BitBtn27;
    TBitBtn           * BitBtn28;
    TBitBtn           * BitBtn29;
    TBitBtn           * BitBtn30;
    TBitBtn           * BitBtn31;
    TBitBtn           * BitBtn128;
    TButton           * Button1;
    TButton           * Button2;
    TButton           * Button3;
    TButton           * Button4;
    TButton           * Button5;
    TButton           * Button111;

    TComboBox         * ComboBox1;
    TComboBox         * ComboBox2;
    TComboBox         * ComboBox3;
    TComboBox         * ComboBox4;
    TComboBox         * ComboBox5;
    TComboBox         * ComboBox6;
    TComboBox         * ComboBox7;
    TComboBox         * ComboBox8;
    TComboBox         * ComboBox9;
    TComboBox         * ComboBox10;
    TComboBox         * ComboBox11;
    TComboBox         * ComboBox12;
    TComboBox         * ComboBox13;
    TComboBox         * ComboBox14;
    TComboBox         * ComboBox111;

    TDateTimePicker   * DateTimePicker1;
    TDateTimePicker   * DateTimePicker2;
    TDateTimePicker   * DateTimePicker3;
    TDateTimePicker   * DateTimePicker4;
    TDateTimePicker   * DateTimePicker5;
    TDateTimePicker   * DateTimePicker6;
    TDateTimePicker   * DateTimePicker7;
    TDateTimePicker   * DateTimePicker8;
    TDateTimePicker   * DateTimePicker9;
    TDateTimePicker   * DateTimePicker10;
    TDateTimePicker   * DateTimePicker11;
    TDateTimePicker   * DateTimePicker12;
    TDateTimePicker   * DateTimePicker13;
    TDateTimePicker   * DateTimePicker14;
    TDateTimePicker   * DateTimePicker15;
    TDateTimePicker   * DateTimePicker16;
    TDateTimePicker   * DateTimePicker17;
    TDateTimePicker   * DateTimePicker18;
    TDateTimePicker   * DateTimePicker19;
    TDateTimePicker   * DateTimePicker20;
    TDateTimePicker   * DateTimePicker21;
    TDateTimePicker   * DateTimePicker22;
    TDateTimePicker   * DateTimePicker23;
    TDateTimePicker   * DateTimePicker112;

    TDBGrid           * DBGrid1;

    TDBLookupComboBox * DBLookupComboBox1;
    TDBLookupComboBox * DBLookupComboBox2;
    TDBLookupComboBox * DBLookupComboBox3;
    TDBLookupComboBox * DBLookupComboBox4;
    TDBLookupComboBox * DBLookupComboBox5;
    TDBLookupComboBox * DBLookupComboBox6;
    TDBLookupComboBox * DBLookupComboBox7;
    TDBLookupComboBox * DBLookupComboBox8;
    TDBLookupComboBox * DBLookupComboBox9;
    TDBLookupComboBox * DBLookupComboBox10;
    TDBLookupComboBox * DBLookupComboBox11;
    TDBLookupComboBox * DBLookupComboBox12;
    TDBLookupComboBox * DBLookupComboBox13;
    TDBLookupComboBox * DBLookupComboBox14;
    TDBLookupComboBox * DBLookupComboBox15;
    TDBLookupComboBox * DBLookupComboBox16;
    TDBLookupComboBox * DBLookupComboBox17;
    TDBLookupComboBox * DBLookupComboBox18;
    TDBLookupComboBox * DBLookupComboBox19;
    TDBLookupComboBox * DBLookupComboBox20;
    TDBLookupComboBox * DBLookupComboBox21;
    TDBLookupComboBox * DBLookupComboBox22;
    TDBLookupComboBox * DBLookupComboBox23;
    TDBLookupComboBox * DBLookupComboBox24;
    TDBLookupComboBox * FIOLook;

    // TDualListDialog   * DualListDialog1;
    // TDualListDialog   * DualListDialog2;

    TEdit             * Edit1;
    TEdit             * Edit2;
    TEdit             * Edit3;
    TEdit             * Edit4;
    TEdit             * Edit5;
    TEdit             * Edit6;
    TEdit             * Edit7;
    TEdit             * Edit8;
    TEdit             * Edit9;
    TEdit             * Edit10;
    TEdit             * Edit11;
    TEdit             * Edit12;
    TEdit             * Edit13;
    TEdit             * Edit14;
    TEdit             * Edit15;
    TEdit             * Edit16;
    TEdit             * Edit17;
    TEdit             * Edit18;
    TEdit             * Edit19;
    TEdit             * Edit20;
    TEdit             * Edit21;
    TEdit             * Edit22;
    TEdit             * Edit23;
    TEdit             * Edit24;
    TEdit             * Edit25;
    TEdit             * Edit26;
    TEdit             * Edit27;
    TEdit             * Edit28;
    TEdit             * Edit29;
    TEdit             * Edit30;
    TEdit             * Edit31;
    TEdit             * Edit32;
    TEdit             * Edit33;
    TEdit             * Edit34;
    TEdit             * Edit35;
    TEdit             * Edit36;
    TEdit             * Edit37;
    TEdit             * Edit126;
    TEdit             * Edit127;

    TFDStoredProc     * FDStoredProc1;

    TGroupBox         * GroupBox1;

    TImage            * Image1;

    TLabel            * Label1;
    TLabel            * Label2;
    TLabel            * Label3;
    TLabel            * Label4;
    TLabel            * Label5;
    TLabel            * Label6;
    TLabel            * Label7;
    TLabel            * Label8;
    TLabel            * Label9;
    TLabel            * Label10;
    TLabel            * Label11;
    TLabel            * Label12;
    TLabel            * Label13;
    TLabel            * Label14;
    TLabel            * Label15;
    TLabel            * Label16;
    TLabel            * Label17;
    TLabel            * Label18;
    TLabel            * Label19;
    TLabel            * Label20;
    TLabel            * Label21;
    TLabel            * Label22;
    TLabel            * Label23;
    TLabel            * Label24;
    TLabel            * Label25;
    TLabel            * Label26;
    TLabel            * Label27;
    TLabel            * Label28;
    TLabel            * Label29;
    TLabel            * Label30;
    TLabel            * Label31;
    TLabel            * Label32;
    TLabel            * Label33;
    TLabel            * Label34;
    TLabel            * Label35;
    TLabel            * Label36;
    TLabel            * Label37;
    TLabel            * Label38;
    TLabel            * Label39;
    TLabel            * Label40;
    TLabel            * Label41;
    TLabel            * Label42;
    TLabel            * Label43;
    TLabel            * Label44;
    TLabel            * Label45;
    TLabel            * Label46;
    TLabel            * Label47;
    TLabel            * Label48;
    TLabel            * Label49;
    TLabel            * Label50;
    TLabel            * Label51;
    TLabel            * Label52;
    TLabel            * Label53;
    TLabel            * Label54;
    TLabel            * Label55;
    TLabel            * Label56;
    TLabel            * Label57;
    TLabel            * Label58;
    TLabel            * Label59;
    TLabel            * Label60;
    TLabel            * Label61;
    TLabel            * Label62;
    TLabel            * Label63;
    TLabel            * Label64;
    TLabel            * Label65;
    TLabel            * Label66;
    TLabel            * Label67;
    TLabel            * Label68;
    TLabel            * Label69;
    TLabel            * Label70;
    TLabel            * Label71;
    TLabel            * Label72;
    TLabel            * Label73;
    TLabel            * Label74;
    TLabel            * Label75;
    TLabel            * Label76;
    TLabel            * Label77;
    TLabel            * Label78;
    TLabel            * Label79;
    TLabel            * Label80;
    TLabel            * Label81;
    TLabel            * Label82;
    TLabel            * Label83;
    TLabel            * Label84;
    TLabel            * Label85;
    TLabel            * Label86;
    TLabel            * Label87;
    TLabel            * Label88;
    TLabel            * Label89;
    TLabel            * Label90;
    TLabel            * Label91;
    TLabel            * Label92;
    TLabel            * Label93;
    TLabel            * Label94;
    TLabel            * Label95;
    TLabel            * Label96;
    TLabel            * Label97;
    TLabel            * Label98;
    TLabel            * Label99;
    TLabel            * Label100;
    TLabel            * Label101;
    TLabel            * Label102;
    TLabel            * Label103;
    TLabel            * Label104;
    TLabel            * Label105;
    TLabel            * Label106;
    TLabel            * Label107;
    TLabel            * Label108;
    TLabel            * Label109;
    TLabel            * Label110;
    TLabel            * Label111;
    TLabel            * Label112;
    TLabel            * Label113;
    TLabel            * Label114;
    TLabel            * Label115;
    TLabel            * Label194;
    TLabel            * Label195;
    TLabel            * Label196;
    TLabel            * Label197;
    TLabel            * Label198;

    TLabeledEdit      * LabeledEdit1;

    TListBox          * ListBox1;
    TListBox          * ListBox2;
    TListBox          * ListBox3;
    TListBox          * ListBox4;
    TListBox          * ListBox5;
    TListBox          * ListBox113;

    TPageControl      * PageControl1;

    TPanel            * Panel1;
    TPanel            * Panel2;
    TPanel            * Panel3;
    TPanel            * Panel4;
    TPanel            * Panel5;
    TPanel            * Panel6;
    TPanel            * Panel7;
    TPanel            * Panel8;
    TPanel            * Panel9;
    TPanel            * Panel10;
    TPanel            * Panel11;
    TPanel            * Panel12;
    TPanel            * Panel13;
    TPanel            * Panel14;
    TPanel            * Panel15;
    TPanel            * Panel16;
    TPanel            * Panel17;
    TPanel            * Panel18;
    TPanel            * Panel19;

    TProgressBar      * ProgressBar1;

    TRadioGroup       * RadioGroup1;
    TRadioGroup       * RadioGroup2;
    TRadioGroup       * RadioGroup3;
    TRadioGroup       * RadioGroup4;
    TRadioGroup       * RadioGroup5;
    TRadioGroup       * RadioGroup6;
    TRadioGroup       * RadioGroup7;
    TRadioGroup       * RadioGroup8;
    TRadioGroup       * RadioGroup9;
    TRadioGroup       * RadioGroup10;
    TRadioGroup       * RadioGroup11;
    TRadioGroup       * RadioGroup12;
    TRadioGroup       * RadioGroup13;
    TRadioGroup       * RadioGroup14;
    TRadioGroup       * RadioGroup15;
    TRadioGroup       * RadioGroup16;
    TRadioGroup       * RadioGroup17;
    TRadioGroup       * RadioGroup18;

    TTabSheet         * TabSheet1;
    TTabSheet         * TabSheet2;
    TTabSheet         * TabSheet3;
    TTabSheet         * TabSheet4;
    TTabSheet         * TabSheet5;
    TTabSheet         * TabSheet6;
    TTabSheet         * TabSheet7;
    TTabSheet         * TabSheet8;
    TTabSheet         * TabSheet9;
    TTabSheet         * TabSheet10;
    TTabSheet         * TabSheet11;
    TTabSheet         * TabSheet12;
    TTabSheet         * TabSheet13;


    void __fastcall BitBtn1Click              (TObject * Sender);
    void __fastcall BitBtn2Click              (TObject * Sender);
    void __fastcall BitBtn3Click              (TObject * Sender);
    void __fastcall BitBtn4Click              (TObject * Sender);
    void __fastcall BitBtn5Click              (TObject * Sender);
    void __fastcall BitBtn6Click              (TObject * Sender);
    void __fastcall BitBtn7Click              (TObject * Sender);
    void __fastcall BitBtn8Click              (TObject * Sender);
    void __fastcall BitBtn9Click              (TObject * Sender);
    void __fastcall BitBtn10Click             (TObject * Sender);
    void __fastcall BitBtn11Click             (TObject * Sender);
    void __fastcall BitBtn12Click             (TObject * Sender);
    void __fastcall BitBtn13Click             (TObject * Sender);
    void __fastcall BitBtn14Click             (TObject * Sender);
    void __fastcall BitBtn15Click             (TObject * Sender);
    void __fastcall BitBtn16Click             (TObject * Sender);
    void __fastcall BitBtn17Click             (TObject * Sender);
    void __fastcall BitBtn18Click             (TObject * Sender);
    void __fastcall BitBtn19Click             (TObject * Sender);
    void __fastcall BitBtn20Click             (TObject * Sender);
    void __fastcall BitBtn21Click             (TObject * Sender);
    void __fastcall BitBtn22Click             (TObject * Sender);
    void __fastcall BitBtn23Click             (TObject * Sender);
    void __fastcall BitBtn24Click             (TObject * Sender);
    void __fastcall BitBtn25Click             (TObject * Sender);
    void __fastcall BitBtn26Click             (TObject * Sender);
    void __fastcall BitBtn27Click             (TObject * Sender);
    void __fastcall BitBtn28Click             (TObject * Sender);
    void __fastcall BitBtn29Click             (TObject * Sender);
    void __fastcall BitBtn30Click             (TObject * Sender);
    void __fastcall BitBtn31Click             (TObject * Sender);
    void __fastcall BitBtn128Click            (TObject * Sender);
    void __fastcall Button1Click              (TObject * Sender);
    void __fastcall Button2Click              (TObject * Sender);
    void __fastcall Button3Click              (TObject * Sender);
    void __fastcall Button4Click              (TObject * Sender);
    void __fastcall Button5Click              (TObject * Sender);
    void __fastcall Button111Click            (TObject * Sender);
    void __fastcall ComboBox1Change           (TObject * Sender);
    void __fastcall ComboBox2Change           (TObject * Sender);
    void __fastcall ComboBox4Change           (TObject * Sender);
    void __fastcall ComboBox5Change           (TObject * Sender);
    void __fastcall ComboBox6Change           (TObject * Sender);
    void __fastcall ComboBox7Change           (TObject * Sender);
    void __fastcall ComboBox8Change           (TObject * Sender);
    void __fastcall ComboBox9Change           (TObject * Sender);
    void __fastcall ComboBox10Change          (TObject * Sender);
    void __fastcall ComboBox14Change          (TObject * Sender);
    void __fastcall DateTimePicker1Change     (TObject * Sender);
    void __fastcall DateTimePicker2Change     (TObject * Sender);
    void __fastcall DateTimePicker3Change     (TObject * Sender);
    void __fastcall DateTimePicker4Change     (TObject * Sender);
    void __fastcall DateTimePicker5Change     (TObject * Sender);
    void __fastcall DateTimePicker6Change     (TObject * Sender);
    void __fastcall DateTimePicker7Change     (TObject * Sender);
    void __fastcall DateTimePicker8Change     (TObject * Sender);
    void __fastcall DateTimePicker9Change     (TObject * Sender);
    void __fastcall DateTimePicker10Change    (TObject * Sender);
    void __fastcall DateTimePicker11Change    (TObject * Sender);
    void __fastcall DateTimePicker12Change    (TObject * Sender);
    void __fastcall DateTimePicker13Change    (TObject * Sender);
    void __fastcall DateTimePicker14Change    (TObject * Sender);
    void __fastcall DateTimePicker15Change    (TObject * Sender);
    void __fastcall DateTimePicker16Change    (TObject * Sender);
    void __fastcall DateTimePicker17Change    (TObject * Sender);
    void __fastcall DateTimePicker18Change    (TObject * Sender);
    void __fastcall DateTimePicker19Change    (TObject * Sender);
    void __fastcall DateTimePicker20Change    (TObject * Sender);
    void __fastcall DateTimePicker21Change    (TObject * Sender);
    void __fastcall DateTimePicker22Change    (TObject * Sender);
    void __fastcall DateTimePicker23Change    (TObject * Sender);
    void __fastcall DateTimePicker112Change   (TObject * Sender);
    void __fastcall DBLookupComboBox16Click   (TObject * Sender);
    void __fastcall DBLookupComboBox22CloseUp (TObject * Sender);
    // void __fastcall Edit1Change               (TObject * Sender);
    void __fastcall Edit3Change               (TObject * Sender);
    void __fastcall Edit23KeyPress            (
            TObject * Sender,
            char    & Key
        );
    void __fastcall Edit35Change              (TObject * Sender);
    void __fastcall FormClose                 (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate                (TObject * Sender);
    void __fastcall Image1Click               (TObject * Sender);
    // void __fastcall Label3Click               (TObject * Sender);
    void __fastcall Label35Click              (TObject * Sender);
    void __fastcall PageControl1Change        (TObject * Sender);
    void __fastcall Panel1Click               (TObject * Sender);
    void __fastcall RadioGroup1Click          (TObject * Sender);
    void __fastcall RadioGroup2Click          (TObject * Sender);
    void __fastcall RadioGroup3Click          (TObject * Sender);
    void __fastcall RadioGroup4Click          (TObject * Sender);
    void __fastcall RadioGroup5Click          (TObject * Sender);
    void __fastcall RadioGroup8Click          (TObject * Sender);
    void __fastcall RadioGroup10Click         (TObject * Sender);
    void __fastcall RadioGroup12Click         (TObject * Sender);
    void __fastcall RadioGroup13Click         (TObject * Sender);
    void __fastcall RadioGroup18Click         (TObject * Sender);
    void __fastcall TabSheet8Exit             (TObject * Sender);
    void __fastcall TabSheet11Show            (TObject * Sender);
    void __fastcall TabSheet111Show           (TObject * Sender);
private:
public:
    __fastcall TDeloForm (TComponent * Owner);

    void __fastcall Clear_Holiday     ();                                       // очищение компонентов на закладке ОТПУСКА
    void __fastcall Otkat             ();
    void __fastcall Save_PrikazVipusk (                                         // Сохранение приказа на выпуск
            AnsiString Fio,
            int        j
        );
};

extern PACKAGE TDeloForm * DeloForm;

#endif  // DELO_UNIT_H
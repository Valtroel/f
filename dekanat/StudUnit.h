#pragma once
#ifndef STUD_UNIT_H
#define STUD_UNIT_H


#include <AppEvnts.hpp>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <Dialogs.hpp>
#include "DualList.h"
#include <ExtCtrls.hpp>
#include <ExtDlgs.hpp>
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
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include <Grids.hpp>
#include <Mask.hpp>
// #include "MyList.h"
#include "QueueUnit.h"
#include <StdCtrls.hpp>


extern bool est_pas,                                                            // переменная для определения занесен ли документ, удостоверяющий личность
            up_reg;
extern int  id_ab,
            KeyPressAd,
            nomer_stud,
            region_id,
            status_people_query;


class TStudForm
    : public TForm
{
__published:
    TApplicationEvents * ApplicationEvents1;

    TBevel             * Bevel1;

    TBitBtn            * BitBtn1;

    TButton            * Button1;
    TButton            * Button2;
    TButton            * Button3;
    TButton            * Button4;

    TCheckBox          * CheckBox1;
    TCheckBox          * CheckBox2;
    TCheckBox          * CheckBox3;
    TCheckBox          * CheckBox4;
    TCheckBox          * CheckBox5;
    TCheckBox          * CheckBox6;

    TComboBox          * ComboBox1;
    TComboBox          * ComboBox2;
    TComboBox          * ComboBox3;
    TComboBox          * ComboBox4;
    TComboBox          * ComboBox5;

    TDBComboBox        * DBComboBox1;

    TDBEdit            * DBEdit1;
    TDBEdit            * DBEdit2;
    TDBEdit            * DBEdit3;
    TDBEdit            * DBEdit4;
    TDBEdit            * DBEdit5;
    TDBEdit            * DBEdit6;
    TDBEdit            * DBEdit7;
    TDBEdit            * DBEdit8;
    TDBEdit            * DBEdit9;
    TDBEdit            * DBEdit10;
    TDBEdit            * DBEdit11;
    TDBEdit            * DBEdit12;
    TDBEdit            * DBEdit13;
    TDBEdit            * DBEdit14;
    TDBEdit            * DBEdit15;
    TDBEdit            * DBEdit18;
    TDBEdit            * DBEdit19;
    TDBEdit            * DBEdit20;
    TDBEdit            * DBEdit21;
    TDBEdit            * DBEdit22;
    TDBEdit            * DBEdit23;
    TDBEdit            * DBEdit24;
    TDBEdit            * DBEdit25;
    TDBEdit            * DBEdit26;
    TDBEdit            * DBEdit27;
    TDBEdit            * DBEdit28;
    TDBEdit            * DBEdit30;
    TDBGrid            * DBGrid1;
    TDBGrid            * DBGrid2;
    TDBGrid            * DBGrid3;
    TDBGrid            * DBGrid4;
    TDBGrid            * DBGrid5;
    TDBGrid            * DBGrid6;

    TDBLookupComboBox  * DBLookupComboBox1;
    TDBLookupComboBox  * DBLookupComboBox2;
    TDBLookupComboBox  * DBLookupComboBox3;
    TDBLookupComboBox  * DBLookupComboBox4;
    TDBLookupComboBox  * DBLookupComboBox5;
    TDBLookupComboBox  * DBLookupComboBox6;
    TDBLookupComboBox  * DBLookupComboBox7;

    TDBNavigator       * DBNavigator1;
    TDBNavigator       * DBNavigator2;
    TDBNavigator       * DBNavigator3;
    TDBNavigator       * DBNavigator4;

    TDBText            * DBText1;
    TDBText            * DBText2;
    TDBText            * DBText3;
    TDBText            * DBText4;
    TDBText            * DBText5;
    TDBText            * DBText6;

    TEdit              * Edit1;
    TEdit              * Edit2;

    TfrxDBDataset      * frxDBDataset1;
    TfrxDBDataset      * frxDBDataset2;
    TfrxDBDataset      * frxDBDataset3;
    TfrxDBDataset      * frxDBDataset4;

    TfrxReport         * frxReport1;
    TfrxReport         * frxReport2;

    TGroupBox          * GroupBox1;
    TGroupBox          * GroupBox2;

    TImage             * Image1;
    TImage             * Image2;

    TLabel             * Label1;
    TLabel             * Label2;
    TLabel             * Label3;
    TLabel             * Label4;
    TLabel             * Label5;
    TLabel             * Label6;
    TLabel             * Label7;
    TLabel             * Label8;
    TLabel             * Label9;
    TLabel             * Label10;
    TLabel             * Label11;
    TLabel             * Label13;
    TLabel             * Label14;
    TLabel             * Label15;
    TLabel             * Label16;
    TLabel             * Label17;
    TLabel             * Label18;
    TLabel             * Label19;
    TLabel             * Label20;
    TLabel             * Label21;
    TLabel             * Label22;
    TLabel             * Label25;
    TLabel             * Label26;
    TLabel             * Label27;
    TLabel             * Label28;
    TLabel             * Label30;
    TLabel             * Label31;
    TLabel             * Label32;
    TLabel             * Label33;
    TLabel             * Label34;
    TLabel             * Label35;
    TLabel             * Label36;
    TLabel             * Label37;
    TLabel             * Label38;
    TLabel             * Label39;
    TLabel             * Label40;
    TLabel             * Label41;
    TLabel             * Label42;
    TLabel             * Label43;
    TLabel             * Label44;
    TLabel             * Label45;
    TLabel             * Label46;
    TLabel             * Label47;
    TLabel             * Label48;
    TLabel             * Label49;
    TLabel             * Label50;
    TLabel             * Label51;
    TLabel             * Label52;
    TLabel             * Label53;
    TLabel             * Label54;
    TLabel             * Label55;
    TLabel             * Label57;
    TLabel             * Label58;
    TLabel             * Label59;

    TOpenPictureDialog * OpenPictureDialog1;

    TPageControl       * PageControl1;

    TPanel             * Panel1;
    TPanel             * Panel2;
    TPanel             * Panel4;
    TPanel             * Panel5;
    TPanel             * Panel6;
    TPanel             * Panel7;
    TPanel             * Panel8;
    TPanel             * Panel9;
    TPanel             * Panel10;
    TPanel             * Panel11;
    TPanel             * Panel12;
    TPanel             * Panel14;
    TPanel             * Panel15;
    TPanel             * Panel16;
    TPanel             * Panel17;
    TPanel             * Panel18;
    TPanel             * Panel19;
    TPanel             * Panel20;
    TPanel             * Panel21;
    TPanel             * Panel22;
    TPanel             * Panel23;

    TSpeedButton       * SpeedButton1;

    TSplitter          * Splitter1;
    TSplitter          * Splitter2;
    TSplitter          * Splitter3;
    TSplitter          * Splitter4;

    TTabSheet          * TabSheet1;
    TTabSheet          * TabSheet2;
    TTabSheet          * TabSheet3;
    TTabSheet          * TabSheet4;


    void __fastcall ApplicationEvents1Message  (
            tagMSG & Msg,
            bool   & Handled
        );
    void __fastcall BitBtn1Click               (TObject * Sender);
    void __fastcall BitBtn2Click               (TObject * Sender);
    void __fastcall Button1Click               (TObject * Sender);
    void __fastcall Button2Click               (TObject * Sender);
    void __fastcall Button3Click               (TObject * Sender);
    void __fastcall Button4Click               (TObject * Sender);
    void __fastcall CheckBox1Click             (TObject * Sender);
    void __fastcall CheckBox2Click             (TObject * Sender);
    void __fastcall CheckBox3Click             (TObject * Sender);
    void __fastcall CheckBox4Click             (TObject * Sender);
    void __fastcall CheckBox5Click             (TObject * Sender);
    void __fastcall ComboBox1Change            (TObject * Sender);
    void __fastcall ComboBox2Change            (TObject * Sender);
    void __fastcall ComboBox3Change            (TObject * Sender);
    void __fastcall ComboBox5Change            (TObject * Sender);
    void __fastcall DBComboBox1Change          (TObject * Sender);
    void __fastcall DBEdit1KeyDown             (
            TObject     * Sender,
            WORD        & Key,
            TShiftState   Shift
        );
    void __fastcall DBEdit2KeyDown             (
            TObject     * Sender,
            WORD        & Key,
            TShiftState   Shift
        );
    void __fastcall DBEdit5Enter               (TObject * Sender);
    void __fastcall DBEdit12Enter              (TObject * Sender);
    void __fastcall DBEdit23Enter              (TObject * Sender);
    void __fastcall DBEdit28Enter              (TObject * Sender);
    void __fastcall DBGrid1DblClick            (TObject * Sender);
    void __fastcall DBGrid1TitleClick          (TColumn * Column);
    void __fastcall DBImage1Click              (TObject * Sender);
    void __fastcall DBLookupComboBox6CloseUp   (TObject * Sender);
    void __fastcall DBLookupComboBox6MouseDown (
            TObject      * Sender,
            TMouseButton   Button,
            TShiftState    Shift,
            int            X,
            int            Y
        );
    void __fastcall DBNavigator1Click          (
            TObject      * Sender,
            TNavigateBtn   Button
        );
    void __fastcall DBNavigator3Click          (
            TObject      * Sender,
            TNavigateBtn   Button
        );
    void __fastcall Edit1Change                (TObject * Sender);
    void __fastcall Edit2Change                (TObject * Sender);
    void __fastcall FormActivate               (TObject * Sender);
    void __fastcall FormCanResize              (
            TObject * Sender,
            int     & NewWidth,
            int     & NewHeight,
            bool    & Resize
        );
    void __fastcall FormClose                  (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate                 (TObject * Sender);
    void __fastcall Image1Click                (TObject * Sender);
    void __fastcall SpeedButton1Click          (TObject * Sender);
    void __fastcall TabSheet1Enter             (TObject * Sender);
    void __fastcall TabSheet1Exit              (TObject * Sender);
    void __fastcall TabSheet1Show              (TObject * Sender);
    void __fastcall TabSheet2Enter             (TObject * Sender);
    void __fastcall TabSheet2Show              (TObject * Sender);
    void __fastcall TabSheet3Enter             (TObject * Sender);
    void __fastcall TabSheet3Show              (TObject * Sender);
    void __fastcall TabSheet4Enter             (TObject * Sender);
private:
public:
    __fastcall TStudForm (TComponent * Owner);

    // AnsiString __fastcall Ocenka (AnsiString result);                           // оценка прописью
    void       __fastcall Print__Tab_UtCard    (
            int Left,
            int k,
            int nom
        );
    void       __fastcall Print_First          ();                              // печать первой стороны личной карточки
    void       __fastcall Print_First_UtCard   ();                              // печать первой стороны учебной карточки
    void       __fastcall Print_Four_UtCard    ();                              // печать четвертой стороны учебной карточки
    void       __fastcall Print_Three_UtCard   ();                              // печать третьей стороны учебной карточки
    void       __fastcall Print_To             ();                              // печать второй стороны личной карточки
    void       __fastcall Print_To_UtCard      ();                              // печать второй стороны учебной карточки
    void       __fastcall Print_Zag_Tab_UtCard (                                // печать шапки таблицы
            int        Left,
            AnsiString Str1,
            AnsiString Str2,
            AnsiString Str3,
            int        nom
        );
    void       __fastcall Query_UtCard         (
            int Sem,
            int Left,
            int nom
        );
    void       __fastcall RefreshControl       ();
};

extern PACKAGE TStudForm * StudForm;

#endif  // STUD_UNIT_H
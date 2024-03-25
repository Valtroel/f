#pragma once
#ifndef VED_UNIT_H
#define VED_UNIT_H


#include <AppEvnts.hpp>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
// #include <QuickRpt.hpp>
#include <StdCtrls.hpp>


class TVed_Form
    : public TForm
{
__published:
    TApplicationEvents * ApplicationEvents1;

    TBitBtn            * BitBtn1;
    TBitBtn            * BitBtn2;
    TBitBtn            * BitBtn3;
    TBitBtn            * BitBtn4;
    TBitBtn            * BitBtn5;
    TBitBtn            * BitBtn6;
    TBitBtn            * BitBtn7;

    TCheckBox          * CheckBox1;
    TCheckBox          * CheckBox2;

    TDBGrid            * DBGrid1;
    TDBGrid            * DBGrid2;

    TEdit              * Edit1;
    TEdit              * Edit2;
    TEdit              * Edit3;

    TLabel             * Label1;
    TLabel             * Label2;
    TLabel             * Label3;
    TLabel             * Label4;
    TLabel             * Label5;
    TLabel             * Label7;
    TLabel             * Label8;
    TLabel             * Label9;

    TPanel             * Panel1;
    TPanel             * Panel2;
    TPanel             * Panel3;

    // TQRCompositeReport * QRCompositeReport1;

    TRadioGroup        * RadioGroup1;
    TRadioGroup        * RadioGroup2;

    TSpeedButton       * SpeedButton1;
    TSpeedButton       * SpeedButton2;
    TSpeedButton       * SpeedButton3;


    void __fastcall ApplicationEvents1Message (
            tagMSG & Msg,
            bool   & Handled
        );
    void __fastcall BitBtn1Click              (TObject * Sender);
    void __fastcall BitBtn2Click              (TObject * Sender);
    void __fastcall BitBtn3Click              (TObject * Sender);
    void __fastcall BitBtn4Click              (TObject * Sender);
    void __fastcall BitBtn5Click              (TObject * Sender);
    void __fastcall BitBtn6Click              (TObject * Sender);
    void __fastcall BitBtn7Click              (TObject * Sender);
    void __fastcall CheckBox1Click            (TObject * Sender);
    void __fastcall CheckBox2Click            (TObject * Sender);
    void __fastcall DBGrid1DblClick           (TObject * Sender);
    void __fastcall Edit1Click                (TObject * Sender);
    void __fastcall Edit2Click                (TObject * Sender);
    void __fastcall Edit3KeyPress             (
            TObject * Sender,
            char    & Key
        );
    void __fastcall FormActivate              (TObject * Sender);
    void __fastcall FormClose                 (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate                (TObject * Sender);
    void __fastcall IO_EXAM                   (TObject * Sender);
    void __fastcall RadioGroup1Click          (TObject * Sender);
    void __fastcall RadioGroup2Click          (TObject * Sender);
    void __fastcall SpeedButton1Click         (TObject * Sender);
    void __fastcall SpeedButton2Click         (TObject * Sender);
    void __fastcall SpeedButton3Click         (TObject * Sender);
private:
       void __fastcall ved_run ();
public:
    __fastcall TVed_Form (TComponent * Owner);

    int __fastcall max_ved (                                                    // возвращает максимальный номер ведомости
            int god_real                                                        // реальный учебный год,выбранный пользователем
        );
};

extern PACKAGE TVed_Form * Ved_Form;

#endif  // VED_UNIT_H
#pragma once
#ifndef BALL_GEK_UNIT_H
#define BALL_GEK_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
#include <StdCtrls.hpp>
// #include "ToolEdit.hpp"


class TBall_GEK
    : public TForm
{
__published:
    TBitBtn      * BitBtn1;
    TBitBtn      * BitBtn2;

    TDBNavigator * DBNavigator1;

    TDBText      * DBText1;
    TDBText      * DBText2;
    TDBText      * DBText3;

    TLabel       * Label1;
    TLabel       * Label2;

    TMemo        * Memo1;

    TPanel       * Panel1;

    TRadioButton * RadioButton1;
    TRadioButton * RadioButton2;

    TRadioGroup  * RadioGroup1;
    TRadioGroup  * RadioGroup2;


    void __fastcall BitBtn1Click      (TObject * Sender);
    void __fastcall BitBtn2Click      (TObject * Sender);
    void __fastcall DBNavigator1Click (
            TObject      * Sender,
            TNavigateBtn   Button
        );
    void __fastcall FormActivate      (TObject * Sender);
    void __fastcall FormClose         (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall RadioButton1Click (TObject * Sender);
    void __fastcall RadioButton2Click (TObject * Sender);
    void __fastcall RadioGroup2Click  (TObject * Sender);
private:
public:
    __fastcall TBall_GEK (TComponent * Owner);

    int __fastcall Radio_ball_baza  ();                                         // передача значения балла в зависимости от RadioGroup1->ItemIndex и системы оценок
    int __fastcall Radio_setup_baza ();                                         // установка RadioGroup1->ItemIndex в значение из базы данных
};

extern PACKAGE TBall_GEK * Ball_GEK;

#endif  // BALL_GEK_UNIT_H
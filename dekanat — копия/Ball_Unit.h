#pragma once
#ifndef BALL_UNIT_H
#define BALL_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
#include <StdCtrls.hpp>


class TBall_Form
    : public TForm
{
__published:
    TBitBtn      * BitBtn1;
    TBitBtn      * BitBtn2;

    TDBNavigator * DBNavigator1;

    TDBText      * DBText1;
    TDBText      * DBText2;
    TDBText      * DBText3;

    TEdit        * Edit1;

    TLabel       * Label1;
    TLabel       * Label2;

    TPanel       * Panel1;

    TRadioGroup  * RadioGroup1;
    TRadioGroup  * RadioGroup2;


    void __fastcall BitBtn1Click      (TObject * Sender);
    void __fastcall BitBtn2Click      (TObject * Sender);
    void __fastcall DBNavigator1Click (
            TObject      * Sender,
            TNavigateBtn   Button
        );
    void __fastcall Edit1Change       (TObject * Sender);
    void __fastcall Edit1Click        (TObject * Sender);
    void __fastcall FormActivate      (TObject * Sender);
    void __fastcall FormClose         (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall RadioGroup1Click  (TObject * Sender);
    void __fastcall RadioGroup2Click  (TObject * Sender);
private:
public:
    __fastcall TBall_Form (TComponent * Owner);

    int __fastcall Radio_setup ();                                              // установка RadioGroup1->ItemIndex в значение из базы данных
    int __fastcall Radio_ball  ();                                              //передача значения балла в зависимости от RadioGroup1->ItemIndex и вида контроля
};

extern PACKAGE TBall_Form * Ball_Form;

#endif  // BALL_UNIT_H
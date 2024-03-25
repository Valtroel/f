#pragma once
#ifndef AUTO_DIPLOM_UNIT_H
#define AUTO_DIPLOM_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <StdCtrls.hpp>


class TAutoDiplomForm
    : public TForm
{
__published:
    TBitBtn     * BitBtn1;
    TBitBtn     * BitBtn2;

    TCheckBox   * CheckBox1;

    TLabel      * Label1;
    TLabel      * Label2;
    TLabel      * Label3;
    TLabel      * Label4;
    TLabel      * Label5;
    TLabel      * Label6;
    TLabel      * Label7;
    TLabel      * Label8;
    TLabel      * Label9;
    TLabel      * Label10;
    TLabel      * Label11;
    TLabel      * Label12;

    TPanel      * Panel1;
    TPanel      * Panel2;
    TPanel      * Panel3;

    TRadioGroup * RadioGroup1;
    TRadioGroup * RadioGroup2;


    void __fastcall BitBtn1Click     (TObject * Sender);
    void __fastcall BitBtn2Click     (TObject * Sender);
    void __fastcall FormClose        (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate       (TObject * Sender);
    void __fastcall RadioGroup1Click (TObject * Sender);
    void __fastcall RadioGroup2Click (TObject * Sender);
private:
public:
    __fastcall TAutoDiplomForm (TComponent * Owner);

    void __fastcall Diplom_Shapka (bool otl );                                  // Шапка дипломов
    void __fastcall Diplom_text   (                                             // Текст по строкам диплома
            int  str,
            bool otl
        );
    void __fastcall Diplom_Titul  (bool otl );                                  // Титульный лист дипломов
    void __fastcall MaxReg        (int  kurs);
    void __fastcall QOpen         (int  kurs);
};

extern PACKAGE TAutoDiplomForm * AutoDiplomForm;

#endif  // AUTO_DIPLOM_UNIT_H
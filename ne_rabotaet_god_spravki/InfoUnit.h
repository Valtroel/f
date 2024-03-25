#pragma once
#ifndef INFO_UNIT_H
#define INFO_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
// #include "MyList.h"
#include <StdCtrls.hpp>


class TInfoForm
    : public TForm
{
__published:
    TBitBtn      * BitBtn1;
    TBitBtn      * BitBtn2;
    TBitBtn      * BitBtn3;

    TLabel       * Label1;
    TLabel       * Label2;
    TLabel       * Label3;
    TLabel       * Label4;
    TLabel       * Label5;
    TLabel       * Label6;

    TMaskEdit    * MaskEdit1;
    TMaskEdit    * MaskEdit2;

    TPanel       * Panel1;
    TPanel       * Panel2;

    TRadioGroup  * RadioGroup1;
    TRadioGroup  * RadioGroup2;
    TRadioGroup  * RadioGroup3;
    TRadioGroup  * RadioGroup4;

    TSpeedButton * SpeedButton1;


    void __fastcall BitBtn1Click      (TObject * Sender);
    void __fastcall BitBtn2Click      (TObject * Sender);
    void __fastcall BitBtn3Click      (TObject * Sender);
    void __fastcall FormClose         (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate        (TObject * Sender);
    void __fastcall MaskEdit1Exit     (TObject * Sender);
    void __fastcall MaskEdit2Change   (TObject * Sender);
    void __fastcall RadioGroup1Click  (TObject * Sender);
    void __fastcall RadioGroup2Click  (TObject * Sender);
    void __fastcall RadioGroup3Click  (TObject * Sender);
    void __fastcall RadioGroup4Click  (TObject * Sender);
    void __fastcall SpeedButton1Click (TObject * Sender);
private:
public:
    __fastcall TInfoForm (TComponent * Owner);

    void __fastcall Create_Shapka          ();                                  // создание шапки таблицы
    void __fastcall Create_Spisok_Zachetka ();                                  // создание списка студентов с номерами зачетных книжек
    void __fastcall del_mas                (bool mas_chek);                     // удаление массива студентов
    void __fastcall SaveTrStud             ();
    void __fastcall StateQ                 ();
    void __fastcall UpStud                 ();
};

extern PACKAGE TInfoForm * InfoForm;

#endif  // INFO_UNIT_H
#pragma once
#ifndef NK_3_UNIT_H
#define NK_3_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>


class TNK_3Form
    : public TForm
{
__published:
    TBitBtn     * BitBtn1;
    TBitBtn     * BitBtn2;
    TBitBtn     * BitBtn3;
    TBitBtn     * BitBtn4;
    TBitBtn     * BitBtn5;
    TBitBtn     * BitBtn6;
    TBitBtn     * BitBtn7;
    TBitBtn     * BitBtn8;

    TCheckBox   * CheckBox1;

    TPanel      * Panel1;
    TPanel      * Panel2;
    TPanel      * Panel3;

    TRadioGroup * RadioGroup1;
    TRadioGroup * RadioGroup2;

    TStringGrid * StringGrid1;


    void __fastcall BitBtn1Click     (TObject * Sender);
    void __fastcall BitBtn2Click     (TObject * Sender);
    void __fastcall BitBtn3Click     (TObject * Sender);
    void __fastcall BitBtn4Click     (TObject * Sender);
    void __fastcall BitBtn5Click     (TObject * Sender);
    void __fastcall BitBtn6Click     (TObject * Sender);
    void __fastcall BitBtn7Click     (TObject * Sender);
    void __fastcall BitBtn8Click     (TObject * Sender);
    void __fastcall CheckBox1Click   (TObject * Sender);
    void __fastcall FormClose        (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate       (TObject * Sender);
    void __fastcall RadioGroup1Click (TObject * Sender);
    void __fastcall RadioGroup2Click (TObject * Sender);
private:
public:
    __fastcall TNK_3Form (TComponent * Owner);

    bool       __fastcall Clear_StringGrid  ();                                 // разные проверки и очистка StringGrida
    void       __fastcall Create_StringGrid ();                                 // Формирование заполненного StringGrid-a
    AnsiString            Date_Diap         (int let);                          // возвращает диапазон для рассчета возраста студентов
    void       __fastcall Form_Max          ();                                 // Увеличение размера формы
    void       __fastcall Form_Min          ();                                 // Уменьшение размера формы
};

extern PACKAGE TNK_3Form * NK_3Form;

#endif  // NK_3_UNIT_H
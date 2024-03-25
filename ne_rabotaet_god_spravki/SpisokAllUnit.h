#pragma once
#ifndef SPISOK_UNIT_H
#define SPISOK_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>


class TSpisokAllForm
    : public TForm
{
__published:
    TBitBtn     * BitBtn1;
    TBitBtn     * BitBtn2;

    TLabel      * Label1;
    TLabel      * Label2;

    TPanel      * Panel1;
    TPanel      * Panel2;
    TPanel      * Panel3;

    TRadioGroup * RadioGroup2;
    TRadioGroup * RadioGroup3;

    TStringGrid * StringGrid1;


    void __fastcall BitBtn1Click     (TObject * Sender);
    void __fastcall BitBtn2Click     (TObject * Sender);
    void __fastcall FormClose        (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate       (TObject * Sender);
    void __fastcall RadioGroup2Click (TObject * Sender);
private:
    void  __fastcall Create_Spisok ();                                          // создает и заполняет StringGrida на форме (зависимость от выбора пункта меню)
public:
    __fastcall TSpisokAllForm (TComponent * Owner);
};

extern PACKAGE TSpisokAllForm * SpisokAllForm;

#endif  // SPISOK_UNIT_H
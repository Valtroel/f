#pragma once
#ifndef DIPLOM_UNIT_H
#define DIPLOM_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
// #include "MyList.h"
#include <StdCtrls.hpp>
// #include "ToolEdit.hpp"
#include <Vcl.CheckLst.hpp>
#include <Vcl.ComCtrls.hpp>


class TDiplomForm
    : public TForm
{
__published:
    TBitBtn         * BitBtn1;
    TBitBtn         * BitBtn2;
    TBitBtn         * BitBtn3;

    TCheckListBox   * CheckListBox1;

    TDateTimePicker * DateTimePicker1;

    TLabel          * Label1;

    TPanel          * Panel1;
    TPanel          * Panel2;
    TPanel          * Panel3;

    TRadioGroup     * RadioGroup1;
    TRadioGroup     * RadioGroup2;
    TRadioGroup     * RadioGroup3;


    void __fastcall BitBtn1Click          (TObject * Sender);
    void __fastcall BitBtn2Click          (TObject * Sender);
    void __fastcall BitBtn3Click          (TObject * Sender);
    void __fastcall CheckListBox1Click    (TObject * Sender);
    void __fastcall DateTimePicker1Change (TObject * Sender);
    void __fastcall FormClose             (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall RadioGroup1Click      (TObject * Sender);
    void __fastcall RadioGroup2Click      (TObject * Sender);
    void __fastcall RadioGroup3Click      (TObject * Sender);
    void __fastcall RxCheckListBox1Click  (TObject * Sender);
private:
public:
    __fastcall TDiplomForm (TComponent * Owner);

    void __fastcall create_vid_control (                                        // создание в зависимости от вида контроля
            int        nomer_s,
            int        col,
            AnsiString control,
            int        stat
        );
    void __fastcall Predmet_svod       (                                        // функция для занесения предметов в сводную ведомость
            int        col,
            AnsiString control,
            int        stat
        );
    void __fastcall Shapka_Diplom      (                                        // Шапка в дипломе
            AnsiString text,
            bool       clock
        );
};

extern PACKAGE TDiplomForm * DiplomForm;

#endif  // DIPLOM_UNIT_H
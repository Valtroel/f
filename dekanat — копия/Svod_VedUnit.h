#pragma once
#ifndef SVOD_VED_UNIT_H
#define SVOD_VED_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
// #include "MyList.h"
#include <StdCtrls.hpp>
// #include "ToolEdit.hpp"
#include <Vcl.ComCtrls.hpp>


class TSvod_Ved
    : public TForm
{
__published:
    TBitBtn         * BitBtn1;
    TBitBtn         * BitBtn2;

    TComboBox       * ComboBox2;

    TDateTimePicker * DateTimePicker1;

    TEdit           * Edit2;

    TLabel          * Label1;
    TLabel          * Label4;
    TLabel          * Label5;

    TPanel          * Panel1;
    TPanel          * Panel2;

    TRadioGroup     * RadioGroup2;


    void __fastcall BitBtn1Click          (TObject * Sender);
    void __fastcall BitBtn2Click          (TObject * Sender);
    void __fastcall DateTimePicker1Change (TObject * Sender);
    void __fastcall FormClose             (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall RadioGroup2Click      (TObject * Sender);
private:
public:
    __fastcall TSvod_Ved (TComponent * Owner);

    void       __fastcall Cell_2_Text_Ole (
            Variant    XLApp,
            Variant    XLSh,
            int        col1,
            int        col2,
            int        st,
            bool       Border,
            AnsiString Shrift,
            int        kegl,
            bool       Bold,
            int        AlignH,
            int        AlignV,
            bool       M_1,
            bool       W_1,
            AnsiString TextCell
        );
    void       __fastcall Mas_God         (int n_kurs);                         // формирует учебные года
    void       __fastcall Mas_Pred        (                                     // формирует массивы экз, курсовые, практика, Гос
            int n_kurs,
            int n_vid_edu,
            int specializ
        );
    void       __fastcall Mas_Predmet     (                                     // формирует массив предметов
            int n_kurs,
            int n_vid_edu,
            int specializ
        );
    void       __fastcall Mas_Spec        ();                                   // Формирование массива специализаций
    // AnsiString __fastcall Str             (int result);                         // Вывод оценки прописью
};

extern PACKAGE TSvod_Ved * Svod_Ved;

#endif  // SVOD_VED_UNIT_H
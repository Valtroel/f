#pragma once
#ifndef SEMESTR_SESSION_UNIT_H
#define SEMESTR_SESSION_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
#include <StdCtrls.hpp>


class TSemestr_sessionForm
    : public TForm
{
__published:
    TBitBtn   * BitBtn1;
    TBitBtn   * BitBtn2;

    TComboBox * ComboBox1;
    TComboBox * ComboBox2;

    TLabel    * Label1;
    TLabel    * Label2;
    TLabel    * Label3;
    TLabel    * Label4;

    TMaskEdit * MaskEdit1;

    TPanel    * Panel1;
    TPanel    * Panel2;
    TPanel    * Panel3;


    void __fastcall BitBtn1Click  (TObject * Sender);
    void __fastcall BitBtn2Click  (TObject * Sender);
    void __fastcall FormClose     (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate    (TObject * Sender);
    void __fastcall MaskEdit1Exit (TObject * Sender);
private:
public:
    __fastcall TSemestr_sessionForm (TComponent * Owner);

    void __fastcall Create_text_mass ();                                        // создает массив текстовых столбцов в статистике
    void __fastcall Itogo_summ       (                                          // внесение в Excel строчки ИТОГО по группам (зависит от системы оценок)
            int n_r,
            int rec_gr
        );
    void __fastcall mass_sem         (                                          // создние массива по семестрам
            int vid_edu,
            int ses_edu
        );
    void __fastcall Shapka_Tabl      ();                                        // формирование шапки таблицы (используется в двух статистиках)
    void __fastcall System_five      (int n_r);                                 // пересмотр оценок для пятибальной системы
    void __fastcall System_ten       (int n_r);                                 // пересмотр оценок для десятибальной системы
};

extern PACKAGE TSemestr_sessionForm * Semestr_sessionForm;

#endif  // SEMESTR_SESSION_UNIT_H
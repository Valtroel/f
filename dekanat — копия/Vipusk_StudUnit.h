#pragma once
#ifndef VIPUSK_STUD_UNIT_H
#define VIPUSK_STUD_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
// #include "MyList.h"
#include <StdCtrls.hpp>


class TVipusk_Stud
    : public TForm
{
__published:
    TBitBtn      * BitBtn1;
    TBitBtn      * BitBtn2;
    TBitBtn      * BitBtn31;

    TComboBox    * ComboBox1;

    TLabel       * Label1;
    TLabel       * Label2;
    TLabel       * Label3;
    TLabel       * Label4;
    TLabel       * Label5;

    TListBox     * ListBox1;

    TPanel       * Panel1;
    TPanel       * Panel2;

    TProgressBar * ProgressBar1;

    TRadioGroup  * RadioGroup17;


    void __fastcall BitBtn1Click    (TObject * Sender);
    void __fastcall BitBtn2Click    (TObject * Sender);
    void __fastcall BitBtn31Click   (TObject * Sender);
    void __fastcall ComboBox1Change (TObject * Sender);
    void __fastcall FormClose       (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TVipusk_Stud (TComponent * Owner);

    void __fastcall Delete_IncGroup (                                           // Удаление инкрементов групп
            int        inc_gr,
            AnsiString nom_gr,
            int        edu,
            int        god
        );
    void __fastcall Save_Vipusk     (AnsiString Fio);                           // Сохранение выпуска
};

extern PACKAGE TVipusk_Stud * Vipusk_Stud;

#endif  // VIPUSK_STUD_UNIT_H
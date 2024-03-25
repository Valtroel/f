#pragma once
#ifndef VED_GEK_UNIT_H
#define VED_GEK_UNIT_H


#include "frxClass.hpp"
#include <AppEvnts.hpp>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
// #include "MyList.h"
#include <StdCtrls.hpp>


class TVed_GEK
    : public TForm
{
__published:
    TApplicationEvents * ApplicationEvents1;

    TBitBtn            * BitBtn1;
    TBitBtn            * BitBtn2;
    TBitBtn            * BitBtn3;
    TBitBtn            * BitBtn4;
    TBitBtn            * BitBtn5;
    TBitBtn            * BitBtn6;
    TBitBtn            * BitBtn7;

    TCheckBox          * CheckBox1;
    TCheckBox          * CheckBox2;

    TDBGrid            * DBGrid2;

    TEdit              * Edit1;
    TEdit              * Edit2;
    TEdit              * Edit3;

    TfrxReport         * frxReport1;

    TLabel             * Label1;
    TLabel             * Label2;
    TLabel             * Label3;
    TLabel             * Label4;
    TLabel             * Label7;
    TLabel             * Label8;

    TPanel             * Panel1;
    TPanel             * Panel2;

    TRadioGroup        * RadioGroup2;


    void __fastcall ApplicationEvents1Message (
            tagMSG & Msg,
            bool   & Handled
        );
    void __fastcall BitBtn1Click              (TObject * Sender);
    void __fastcall BitBtn2Click              (TObject * Sender);
    void __fastcall BitBtn3Click              (TObject * Sender);
    void __fastcall BitBtn4Click              (TObject * Sender);
    void __fastcall BitBtn5Click              (TObject * Sender);
    void __fastcall BitBtn6Click              (TObject * Sender);
    void __fastcall BitBtn7Click              (TObject * Sender);
    void __fastcall CheckBox1Click            (TObject * Sender);
    void __fastcall CheckBox2Click            (TObject * Sender);
    void __fastcall Edit1Enter                (TObject * Sender);
    void __fastcall Edit2Enter                (TObject * Sender);
    void __fastcall FormActivate              (TObject * Sender);
    void __fastcall FormClose                 (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall RadioGroup2Click          (TObject * Sender);
private:
public:
    __fastcall TVed_GEK (TComponent * Owner);

    bool       __fastcall Open_S           (bool p);                            // открывает SQL
    void       __fastcall Print_Ochered    ();
    void       __fastcall Print_VED        ();                                  // печать экзаменационной ведомости на Гос.
    AnsiString            Text_predmet_GOS (                                    // измененяет текст предмета исходя из специализации (Для ГОС-ов)
            AnsiString predmet,
            int        specializ,
            bool       G_P
        );
};

extern PACKAGE TVed_GEK * Ved_GEK;

#endif  // VED_GEK_UNIT_H
#pragma once
#ifndef PASS_UNIT_H
#define PASS_UNIT_H


#include <Buttons.hpp>
#include "ccalendr.h"
#include "CCALENDR.h"
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>


class TPassForm
    : public TForm
{
__published:
    TBitBtn      * BitBtn1;
    TBitBtn      * BitBtn2;
    TBitBtn      * BitBtn3;

    TCCalendar   * CCalendar1;

    TComboBox    * ComboBox1;

    TDBGrid      * DBGrid1;

    TDBNavigator * DBNavigator1;

    TDBText      * DBText1;
    TDBText      * DBText2;
    TDBText      * DBText3;

    TEdit        * Edit1;

    TLabel       * Label1;
    TLabel       * Label2;

    TPanel       * Panel1;
    TPanel       * Panel2;

    TRadioGroup  * RadioGroup1;

    TStringGrid  * StringGrid1;

    TUpDown      * UpDown1;


    void __fastcall BitBtn1Click       (TObject * Sender);
    void __fastcall BitBtn2Click       (TObject * Sender);
    void __fastcall CCalendar1DblClick (TObject * Sender);
    void __fastcall ComboBox1Change    (TObject * Sender);
    void __fastcall DBGrid1DblClick    (TObject * Sender);
    void __fastcall DBNavigator1Click  (
            TObject      * Sender,
            TNavigateBtn   Button
        );
    void __fastcall Edit1Change        (TObject * Sender);
    void __fastcall FormActivate       (TObject * Sender);
    void __fastcall FormClose          (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate         (TObject * Sender);
    void __fastcall RadioGroup1Click   (TObject * Sender);
    void __fastcall UpDown1Click       (
            TObject    * Sender,
            TUDBtnType   Button
        );
private:
public:
    __fastcall TPassForm (TComponent * Owner);

    void __fastcall pass_month (                                                // заполнение StringGrid1 пропусками за каждый мес€ц
        AnsiString month_en,                                                    // мес€ц по английски
        AnsiString month_rus,                                                   // мес€ц по русски
        int        year                                                         // учебный год
    );
};

extern PACKAGE TPassForm * PassForm;

#endif  // PASS_UNIT_H
#pragma once
#ifndef CALENDAR_UNIT_H
#define CALENDAR_UNIT_H


#include "ccalendr.h"
#include "CCALENDR.h"
#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>


extern bool       calendar;
extern TDateTime  cal_date;
extern int        cal_day,
                  cal_month,
                  cal_year;


class TCalendarForm
    : public TForm
{
__published:
    TBitBtn    * BitBtn1;
    TBitBtn    * BitBtn2;

    TCCalendar * CCalendar1;

    TComboBox  * ComboBox1;

    TEdit      * Edit1;

    TLabel     * Label1;
    TLabel     * Label2;

    TUpDown    * UpDown1;


    void __fastcall BitBtn1Click    (TObject * Sender);
    void __fastcall BitBtn2Click    (TObject * Sender);
    void __fastcall ComboBox1Change (TObject * Sender);
    void __fastcall Edit1Change     (TObject * Sender);
    void __fastcall FormClose       (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate      (TObject * Sender);
    void __fastcall UpDown1Click    (
            TObject    * Sender,
            TUDBtnType   Button
        );
private:
public:
    __fastcall TCalendarForm (TComponent * Owner);
};

extern PACKAGE TCalendarForm * CalendarForm;

#endif  // CALENDAR_UNIT_H
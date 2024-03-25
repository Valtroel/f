#pragma once
#ifndef PEOPLE_CARD_REPORT_UNIT_H
#define PEOPLE_CARD_REPORT_UNIT_H


#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include "frxClass.hpp"
#include <StdCtrls.hpp>


class TPeople_card_ReportForm
    : public TForm
{
__published:
    TfrxReport * frxReport1;


    void __fastcall FormClose (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TPeople_card_ReportForm (TComponent * Owner);
};

extern PACKAGE TPeople_card_ReportForm * People_card_ReportForm;

#endif  // PEOPLE_CARD_REPORT_UNIT_H
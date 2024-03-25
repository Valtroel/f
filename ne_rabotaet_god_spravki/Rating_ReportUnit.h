#pragma once
#ifndef RATING_REPORT_UNIT_H
#define RATING_REPORT_UNIT_H


#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include <StdCtrls.hpp>


class TRating_ReportForm
    : public TForm
{
__published:
    TfrxDBDataset * frxDBDataset1;

    TfrxReport    * frxReport1;


    void __fastcall FormClose (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TRating_ReportForm (TComponent * Owner);
};

extern PACKAGE TRating_ReportForm * Rating_ReportForm;

#endif  // RATING_REPORT_UNIT_H
#pragma once
#ifndef DOP_VED_REPORT_UNIT_H
#define DOP_VED_REPORT_UNIT_H


#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include "frxClass.hpp"
#include <StdCtrls.hpp>


class TSpravka_vyzovForm
    : public TForm
{
__published:
    TButton * Button1;


    void __fastcall FormClose (
            TObject      * Sender,
            TCloseAction & Action
        );
private:
public:
    __fastcall TSpravka_vyzovForm (TComponent * Owner);
};

extern PACKAGE TSpravka_vyzovForm * Spravka_vyzovForm;

#endif  // DOP_VED_REPORT_UNIT_H
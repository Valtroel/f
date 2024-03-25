#pragma once
#ifndef KARTA_UNIT_H
#define KARTA_UNIT_H


#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxPreview.hpp"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>


class TMedical_checklist_print_Form
    : public TForm
{
__published:
    TfrxDBDataset * frxDBDataset1;

    TfrxPreview   * frxPreview1;

    TfrxReport    * frxReport1;
private:
public:
    __fastcall TMedical_checklist_print_Form (TComponent * Owner);
};

extern PACKAGE TMedical_checklist_print_Form * Medical_checklist_print_Form;

#endif  // KARTA_UNIT_H
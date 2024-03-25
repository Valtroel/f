#pragma once
#ifndef REFERENCE_UNIT_H
#define REFERENCE_UNIT_H


#include "frxClass.hpp"
#include "frxDBSet.hpp"
#include "frxPreview.hpp"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>


class TReferenceForm
    : public TForm
{
__published:
    TfrxDBDataset * frxDBDataset1;
    TfrxDBDataset * frxDBDataset2;
    TfrxDBDataset * frxDBDataset3;

    TfrxPreview   * frxPreview1;

    TfrxReport    * frxReport1;
    TfrxReport    * frxReport2;
    TfrxReport    * frxReport3;
private:
public:
    __fastcall TReferenceForm (TComponent * Owner);
};

extern PACKAGE TReferenceForm * ReferenceForm;

#endif  // REFERENCE_UNIT_H
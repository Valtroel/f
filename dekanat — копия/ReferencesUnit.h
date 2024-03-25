#pragma once
#ifndef REFERENCES_UNIT_H
#define REFERENCES_UNIT_H


#include "frxClass.hpp"
#include "frxPreview.hpp"
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>


class TForm1
    : public TForm
{
__published:
    TfrxReport  * frxReport1;

    TfrxPreview * frxPreview1;
private:
public:
    __fastcall TForm1 (TComponent * Owner);
};

extern PACKAGE TForm1 * Form1;

#endif  // REFERENCES_UNIT_H
#pragma once
#ifndef QUEUE_UNIT_H
#define QUEUE_UNIT_H


#include <System.Classes.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.StdCtrls.hpp>


class TQueueForm
    : public TForm
{
__published:
    TBitBtn           * BitBtn1;

    TButton           * Добавить;

    TDBLookupComboBox * DBLookupComboBox1;

    TLabel            * Label1;


    void __fastcall BitBtn1Click  (TObject * Sender);
    void __fastcall ДобавитьClick (TObject * Sender);
private:
public:
    __fastcall TQueueForm (TComponent * Owner);
};

extern PACKAGE TQueueForm * QueueForm;

#endif  // QUEUE_UNIT_H
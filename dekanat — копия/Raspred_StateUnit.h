#pragma once
#ifndef RASPRED_STATE_UNIT_H
#define RASPRED_STATE_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <ComCtrls.hpp>
#include <Controls.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
// #include "DBGridEh.hpp"
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
// #include "GridsEh.hpp"
#include <Mask.hpp>
#include <StdCtrls.hpp>
// #include "ToolEdit.hpp"


class TRaspred_StateForm
    : public TForm
{
__published:
    TBitBtn   * BitBtn8;

    TDBGrid   * DBGrid1;

    TEdit     * Edit6;

    TGroupBox * GroupBox2;

    TPanel    * Panel2;
    TPanel    * Panel6;


    void __fastcall BitBtn1Click                (TObject * Sender);
    void __fastcall BitBtn8Click                (TObject * Sender);
    void __fastcall DBGridEh1SortMarkingChanged (TObject * Sender);
    void __fastcall Edit6Change                 (TObject * Sender);
    void __fastcall FormClose                   (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate                  (TObject * Sender);
private:
public:
    __fastcall TRaspred_StateForm (TComponent * Owner);
};

extern PACKAGE TRaspred_StateForm * Raspred_StateForm;

#endif  // RASPRED_STATE_UNIT_H
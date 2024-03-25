#include <vcl.h>
#pragma hdrstop


#include "DataModule.h"
#include "DialogPassUnit.h"
#include "DM2Unit.h"
#include <math.h>
#include "PassUnit.h"
#include <stdio.h>
// #include "vcl/sysdefs.h"


#pragma resource "*.dfm"


TDialogPass * DialogPass;


int cause,
    i,
    status_locate = 0;


// CancelBtnClick
// DBLookupComboBox1CloseUp
// Edit1Change
// Edit1KeyPress
// FormClose
// OKBtnClick



__fastcall TDialogPass::TDialogPass (TComponent* AOwner) : TForm (AOwner) {
}

void __fastcall TDialogPass::CancelBtnClick (TObject *Sender) {
    DataModule1 -> PassFDQuery -> CancelUpdates ();
    Close ();
}

void __fastcall TDialogPass::OKBtnClick (TObject *Sender) {
    if (i <= 0)
        // || (i>12)) убрали проверку на часы за один день, т.к. будем делать на одно число
    {
        Edit1 -> Text = "0";
        Edit1 -> SetFocus ();
    }
    else {
        if (status_locate == 2) {
            if (DataModule1 -> PassFDQuery -> State != dsInsert)
                DataModule1 -> PassFDQuery -> Insert ();
            DataModule1 -> PassFDQueryNOMER -> Value =
                DataModule1 -> PeopleFDQueryNOMER -> Value;
            DataModule1 -> PassFDQueryD_PASS -> Value =
                DateTimeToSQLTimeStamp (PassForm -> CCalendar1 -> CalendarDate);
            DataModule1 -> PassFDQueryN_CAUSE -> Value = cause;
        }
        else
            DataModule1 -> PassFDQuery -> Edit ();
        DataModule1 -> PassFDQueryHOUR_PASS -> Value = i;
        DataModule1 -> PassFDQuery -> ApplyUpdates ();
        DataModule1 -> PassFDQuery -> CommitUpdates ();
        status_locate = 0;
        Close ();
    }
}
void __fastcall TDialogPass::DBLookupComboBox1CloseUp (TObject *Sender) {
    OKBtn -> Visible = true;
    cause = DM2 -> Cause_PassFDTableN_CAUSE -> Value;
    Set<TLocateOption, 0, 1>Flags;

    bool found = DataModule1 -> PassFDQuery -> Locate ("N_CAUSE;D_PASS",
        VarArrayOf (OPENARRAY (Variant,
        (cause, PassForm -> CCalendar1 -> CalendarDate))), Flags);
    if (found) {
        status_locate = 1;
        Edit1 -> Text = AnsiString (DataModule1 -> PassFDQueryHOUR_PASS -> Value);
        Edit1 -> SetFocus (); // edit
    }
    else {
        status_locate = 2;
        Edit1 -> Text = "";
        Edit1 -> SetFocus (); // insert
    }
}

void __fastcall TDialogPass::Edit1Change (TObject *Sender) {
    // try {
    i = Edit1 -> Text.ToIntDef (0);

    /* }
     catch (...) {
     Edit1 -> Clear ();
     Edit1 -> Text="0";
     } */
}

void __fastcall TDialogPass::FormClose (TObject *Sender, TCloseAction &Action) {
    Action = caFree;
}

void __fastcall TDialogPass::Edit1KeyPress (TObject *Sender, char &Key) {
    DataModule1 -> Edit_Key (Key);
    // Как сделать, чтобы в TEdit можно было вводить только числа?
}

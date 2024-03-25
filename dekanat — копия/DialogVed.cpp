#include <vcl.h>
#pragma hdrstop


#include "CalendarUnit.h"
#include "DataModule.h"
#include "DialogVed.h"


#pragma resource "*.dfm"


TOKBottomDlg * OKBottomDlg;




// Edit4Click
// FormClose
// MaskEdit1Click
// MaskEdit1KeyDown
// OKBtnClick






__fastcall TOKBottomDlg::TOKBottomDlg (TComponent* AOwner) : TForm (AOwner) {
}

void __fastcall TOKBottomDlg::FormClose (TObject *Sender, TCloseAction &Action) {
    Action = caFree;
}

void __fastcall TOKBottomDlg::Edit4Click (TObject *Sender) {
    /* CalendarForm = new  TCalendarForm (this);
     CalendarForm -> ShowModal ();

     if (calendar) Edit4 -> Text=cal_date;
     OKBtn -> Enabled=true; */
}

void __fastcall TOKBottomDlg::OKBtnClick (TObject *Sender) {
    if (MaskEdit1 -> Text != "  .  .    ") {
        DataModule1 -> VedomostFDQueryEND_D_EXAM -> Value =
            StrToSQLTimeStamp (MaskEdit1 -> Text);
        Close ();
    }
    else {
        ShowMessage ("Введите дату окончания зачетной недели!");
        // Edit4 -> SetFocus ();
    }
}

void __fastcall TOKBottomDlg::MaskEdit1KeyDown (TObject *Sender, WORD &Key,
    TShiftState Shift) {

    if ( (MaskEdit1 -> Text != "  .  .  ") && (Key == VK_RETURN))
    { // проверка на непустой текст и на нажатие клавиши Tab или Enter

        OKBtn -> Enabled = true;
    }
    if ( (MaskEdit1 -> Text != "  .  .  ") && (Key == VK_LBUTTON))
    { // проверка на непустой текст и на нажатие левой кнопки мыши

        OKBtn -> Enabled = true;
    }
}

void __fastcall TOKBottomDlg::MaskEdit1Click (TObject *Sender) {
    CalendarForm = new TCalendarForm (this);
    CalendarForm -> ShowModal ();

    if (calendar) {
        MaskEdit1 -> Text = cal_date;
        OKBtn -> Enabled = true;
    }
}

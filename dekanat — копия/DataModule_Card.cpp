#include <vcl.h>
#pragma hdrstop


#include "DataModule_Card.h"
#include "DataModule.h"
#include "StudUnit.h"


#pragma package (smart_init)
#pragma link     "frxClass"
#pragma resource "*.dfm"


TDataModule2   * DataModule2;


TfrxMemoView   * MemoView;
TfrxReportPage * Page;



__fastcall TDataModule2::TDataModule2 (TComponent * Owner)
    : TDataModule (Owner)
{ }



TfrxMemoView * __fastcall P_F (
        int              L,                                                     // Left
        int              T,                                                     // Top,
        int              W,                                                     // Width
        int              H,                                                     // Height (pixels) to convert in millimeters need to multiply on 5/18
        TFontStyles      Style,                                                 // Font style (0 - normal, 1 - italic, 2 - bold, 3 - italic + bold, 4 - underscore) 
        int              Size,
        AnsiString       Name_F,
        TfrxHAlign       Halign,                                                // Horizontal align (1 - right, 2 - center, 3  - width)
        TfrxVAlign       Valign,                                                // Vertical aligh (4 - top,   8 - center, 16 - bottom)
        TfrxFrameTypes   Fram,                                                  // Border location (0 - without, 1 - right side, 2 - bottom, 4 - left side, 8 - top) to mix you have to sum of the values (exp.: 15 - around)
        AnsiString       Tex,                                                   // input string
        int              nom,
        TfrxReport     * frxReport,
        int              rot
    )
{
    TfrxReportPage * Page =
        dynamic_cast
            <TfrxReportPage *> (
                frxReport -> Pages[nom]
            );

    // MemoView =
    //    dynamic_cast
    //         <TfrxMemoView *> (
    //             DataModule2 ->
    //                 frxReport1 ->
    //                     FindObject (
    //                         "MemoView"
    //                     )
    //         );

    MemoView = new TfrxMemoView (Page);

    MemoView ->
        SetBounds (
            L,
            T,
            W,
            H
        );

    MemoView -> Font -> Style = Style;

    MemoView -> HAlign = Halign;
    MemoView -> VAlign = Valign;

    MemoView -> Font -> Size = Size;

    if (Name_F != "")
        MemoView -> Font -> Name = Name_F;
    else
        MemoView -> Font -> Name = "Times New Roman";

    MemoView -> Frame -> Typ = Fram;

    MemoView -> Text     = Tex;
    MemoView -> Rotation = rot;

    return MemoView;
}
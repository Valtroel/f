#pragma once
#ifndef FUNC_H
#define FUNC_H


extern const AnsiString mas_column[];                                           // = {"A", ..., "AZ"};
extern       Variant    CurCell,                                                // текуща€ €чейка
                        CurSheet;                                               // текуща€ таблица


void    __fastcall AutoFitColumn        (                                       // јвтоподбор ширины столбца
        Variant    Sheet,
        int        Col
    );
void    __fastcall BorderCell           (                                       // обрамление €чейки
        int        col,
        int        row,
        int        typeline,
        int        weightline
    );
void    __fastcall CellFont             (                                       // установить параметры шрифта
        AnsiString NameFont,
        int        SizeFont,
        bool       BoldFont,
        bool       ItalicFont,
        int        UnderlineFont,
        int        ColorIndexFont,
        Variant    Range
    );
void     _fastcall CellFormula          (                                       // ввод формулы в €чейку
        AnsiString formula,
        int        column = 0,
        int        row    = 0,
        Variant    sheet  = 0
    );
void    __fastcall CellOrient           (                                       // ќриентаци€ текста в €чейке
        int        col,
        int        row,
        int        grad
    );
void     _fastcall CellValue            (                                       // ввод значени€ в €чейку
        Variant    value,
        int        column = 0,
        int        row    = 0,
        Variant    sheet  = 0
    );
void    __fastcall ColumnWidth          (                                       // установка ширины столбца
        Variant    Range,
        int        Width
    );
void    __fastcall ColWorkSheet         (                                       // ”становка кол-ва листов в книге
        Variant    excel_app,
        Variant    colSh
    );
void    __fastcall DeleteSheet          (Variant sheet     );                   // ”даление листа
Variant  _fastcall GetCellValue         (                                       // получение  значени€ из €чейки
        int        column = 0,
        int        row    = 0,
        Variant    sheet  = 0
    );
void    __fastcall HeightRow            (                                       // установка ширины строки
        Variant    Range,
        int        height
    );
void    __fastcall HorizontalAlign      (                                       // ¬ыравнивание содержимого €чейки по горизонтали
        Variant    Range,
        int        nom_align
    );
// void    __fastcall HorizontalAlignSheet (                                       // ¬ыравнивание содержимого €чейки по горизонтали
//         Variant    sheet,
//         int        nom_align
//     );
void    __fastcall M1                   (Variant Range     );                   // ќбъединение €чеек
void     _fastcall NameSheet1           (                                       // переименование листа
        Variant    sheet,
        AnsiString name
    );
Variant __fastcall NewBook              (Variant excel_app );                   // Ќова€ книга
Variant  _fastcall NewSheet1            (Variant excel_app );                   // ƒобавление нового листа
Variant  _fastcall OpenBook             (                                       // Open WorkBook
        Variant    excel_app,
        AnsiString full_name
    );
void     _fastcall OVisible             (Variant ole_obj   );                   // set Visible to Ole object
void    __fastcall Quit_ex              (Variant excel_app );                   // delete Excel
Variant __fastcall Range2               (                                       // ¬ыделение €чеек (new)
        Variant    Sheet,
        AnsiString Ran
    );
Variant __fastcall Range_Range          (                                       // ¬ыделение €чеек
        Variant    Sheet,
        Variant    Cell1,
        Variant    Cell2
    );
Variant  _fastcall SaveBookAs           (                                       // —охранение книги c новым именем
        Variant    excel_book,
        AnsiString name
    );
Variant  _fastcall SelectCell           (                                       // ¬ыбор €чейки по адресу
        int        column,
        int        row,
        Variant    sheet  = 0
    );
Variant __fastcall SelectColumn         (                                       // выбрать столбец
        Variant    sheet,
        int        column
    );
Variant  _fastcall SelectSheet          (                                       // Select WorkSheet by Name
        Variant    excel_book,
        AnsiString name
    );
void    __fastcall SetOrientatSheet     (                                       // ”становка ориентации листа grad 1 - книжна€, 2 - альбомна€
        Variant    sheet,
        int        grad
    );
void    __fastcall SheetFormat          (                                       // ‘ормат €чейки
        Variant    cell,
        AnsiString Format
    );
void    __fastcall VerticalAlign        (                                       // ¬ыравнивание содержимого €чейки по вертикали
        Variant    Range,
        int        nom_align
    );
void    __fastcall W1                   (Variant Range     );                   // ѕернос по словам

#endif // FUNC_H
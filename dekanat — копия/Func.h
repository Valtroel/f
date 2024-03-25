#pragma once
#ifndef FUNC_H
#define FUNC_H


extern const AnsiString mas_column[];                                           // = {"A", ..., "AZ"};
extern       Variant    CurCell,                                                // ������� ������
                        CurSheet;                                               // ������� �������


void    __fastcall AutoFitColumn        (                                       // ���������� ������ �������
        Variant    Sheet,
        int        Col
    );
void    __fastcall BorderCell           (                                       // ���������� ������
        int        col,
        int        row,
        int        typeline,
        int        weightline
    );
void    __fastcall CellFont             (                                       // ���������� ��������� ������
        AnsiString NameFont,
        int        SizeFont,
        bool       BoldFont,
        bool       ItalicFont,
        int        UnderlineFont,
        int        ColorIndexFont,
        Variant    Range
    );
void     _fastcall CellFormula          (                                       // ���� ������� � ������
        AnsiString formula,
        int        column = 0,
        int        row    = 0,
        Variant    sheet  = 0
    );
void    __fastcall CellOrient           (                                       // ���������� ������ � ������
        int        col,
        int        row,
        int        grad
    );
void     _fastcall CellValue            (                                       // ���� �������� � ������
        Variant    value,
        int        column = 0,
        int        row    = 0,
        Variant    sheet  = 0
    );
void    __fastcall ColumnWidth          (                                       // ��������� ������ �������
        Variant    Range,
        int        Width
    );
void    __fastcall ColWorkSheet         (                                       // ��������� ���-�� ������ � �����
        Variant    excel_app,
        Variant    colSh
    );
void    __fastcall DeleteSheet          (Variant sheet     );                   // �������� �����
Variant  _fastcall GetCellValue         (                                       // ���������  �������� �� ������
        int        column = 0,
        int        row    = 0,
        Variant    sheet  = 0
    );
void    __fastcall HeightRow            (                                       // ��������� ������ ������
        Variant    Range,
        int        height
    );
void    __fastcall HorizontalAlign      (                                       // ������������ ����������� ������ �� �����������
        Variant    Range,
        int        nom_align
    );
// void    __fastcall HorizontalAlignSheet (                                       // ������������ ����������� ������ �� �����������
//         Variant    sheet,
//         int        nom_align
//     );
void    __fastcall M1                   (Variant Range     );                   // ����������� �����
void     _fastcall NameSheet1           (                                       // �������������� �����
        Variant    sheet,
        AnsiString name
    );
Variant __fastcall NewBook              (Variant excel_app );                   // ����� �����
Variant  _fastcall NewSheet1            (Variant excel_app );                   // ���������� ������ �����
Variant  _fastcall OpenBook             (                                       // Open WorkBook
        Variant    excel_app,
        AnsiString full_name
    );
void     _fastcall OVisible             (Variant ole_obj   );                   // set Visible to Ole object
void    __fastcall Quit_ex              (Variant excel_app );                   // delete Excel
Variant __fastcall Range2               (                                       // ��������� ����� (new)
        Variant    Sheet,
        AnsiString Ran
    );
Variant __fastcall Range_Range          (                                       // ��������� �����
        Variant    Sheet,
        Variant    Cell1,
        Variant    Cell2
    );
Variant  _fastcall SaveBookAs           (                                       // ���������� ����� c ����� ������
        Variant    excel_book,
        AnsiString name
    );
Variant  _fastcall SelectCell           (                                       // ����� ������ �� ������
        int        column,
        int        row,
        Variant    sheet  = 0
    );
Variant __fastcall SelectColumn         (                                       // ������� �������
        Variant    sheet,
        int        column
    );
Variant  _fastcall SelectSheet          (                                       // Select WorkSheet by Name
        Variant    excel_book,
        AnsiString name
    );
void    __fastcall SetOrientatSheet     (                                       // ��������� ���������� ����� grad 1 - �������, 2 - ���������
        Variant    sheet,
        int        grad
    );
void    __fastcall SheetFormat          (                                       // ������ ������
        Variant    cell,
        AnsiString Format
    );
void    __fastcall VerticalAlign        (                                       // ������������ ����������� ������ �� ���������
        Variant    Range,
        int        nom_align
    );
void    __fastcall W1                   (Variant Range     );                   // ������ �� ������

#endif // FUNC_H
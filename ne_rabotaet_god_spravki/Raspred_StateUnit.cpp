#include <vcl.h>
#pragma hdrstop


#include "DataModule.h"
#include "DM3Unit.h"
#include "Raspred_StateUnit.h"


#pragma package (smart_init)
#pragma link     "ToolEdit"
// #pragma link     "DBGridEh"
// #pragma link     "DBGridEh"
// #pragma link     "GridsEh"
#pragma resource "*.dfm"


TRaspred_StateForm * Raspred_StateForm;



__fastcall TRaspred_StateForm::TRaspred_StateForm (TComponent * Owner)
    : TForm (Owner)
{ }



void __fastcall TRaspred_StateForm::BitBtn1Click (TObject * Sender)             // Сохранение результатов в базу
{ }



void __fastcall TRaspred_StateForm::BitBtn8Click (TObject * Sender)
{
    DataModule1 -> ExelInit ();                                                 // формирование файла

    App_n                                                                       // делаем количество листов в книге
    .OlePropertySet (
        "SheetsInNewWorkbook",
        1                                  
    );

    Sh =                                                                        // делаем текущий лист активным
        App_n
        .OlePropertyGet ("WorkSheets")
        .OlePropertyGet (
            "Item",
            1
        );

    Sh = App_n.OlePropertyGet ("ActiveSheet");

    Sh                                                                          // установить не более чем на одну страницу в ширину и 100 в высоту
    .OlePropertyGet ("PageSetup")
    .OlePropertySet (
        "Zoom",
        false
    );

    Sh
    .OlePropertyGet ("PageSetup")
    .OlePropertySet (
        "FitToPagesWide",
        1
    );

    Sh
    .OlePropertyGet ("PageSetup")
    .OlePropertySet (
        "FitToPagesTall",
        100
    );

    Sh                                                                          // делаем горизонтальное выравнивание страницы
    .OlePropertyGet ("PageSetup")
    .OlePropertySet (
        "Orientation",
        2
    );

    // Sh                                                                          // делаем горизонтальное выравнивание страницы
    // .OlePropertyGet ("PageSetup")
    // .OlePropertySet (
    //     "CenterHorizontally",
    //     true
    // );

    // Sh                                                                          // делаем горизонтальное выравнивание страницы
    // .OlePropertyGet ("PageSetup")
    // .OlePropertySet (
    //     "Zoom",
    //     100
    // );


    AnsiString st =                                                             // BEGIN > CREATE TABLE HEADER
        "Список заявок на распределение выпускников "           +
            DM3 -> Raspred_StateGridQueryUCH_GOD -> AsString    +
        " года УО \"БГУФК\"";

    AnsiString tab    = " ";                                                    // Переменная для вставки ALT + Enter в строку Excel (принудительный перенос на следующую строку)
               tab[1] = 0x0A;                                                   // шестнадцатиричный код этой комбинации (десятичный код 10)
    int        str_r = 2;                                                       // номер строки
    Variant    d;                                                               // Excel OLE Object


    Cell_2_Text_Ole2 (                                                          // "Список заявок на распределение выпускников ____ года УО "БГУФК""
        1,
        10,
        1,
        false,
        "Arial",
        14,
        false,
        3,
        2,
        0,
        true,
        true,
        st
    );


    Cell_2_Text_Ole2 (                                                          // "№№ п/п"
        1,
        1,
        str_r,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        true,
        "№"     +\
            tab +\
        "п/п"
    );
    Cell_2_Text_Ole2 (
        1,
        1,
        str_r+1,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        false,
        "1"                                                                     // column No "[ 1 ]"
    );
    d = Sh
        .OlePropertyGet ("Cells")
        .OlePropertyGet (
            "Item",
            1,
            1
        );
    d.OlePropertySet (
        "ColumnWidth",
        9
    );


    Cell_2_Text_Ole2 (                                                          // Факультет
        2,
        2,
        str_r,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        true,
        "Факультет"
    );
    Cell_2_Text_Ole2 (
        2,
        2,
        str_r+1,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        false,
        "2"                                                                     // column No "[ 2 ]"
    );
    d = Sh
        .OlePropertyGet ("Cells")
        .OlePropertyGet (
            "Item",
            2,
            2
        );
    d.OlePropertySet (
        "ColumnWidth",
        20
    );


    Cell_2_Text_Ole2 (                                                          // Специализация
        3,
        3,
        str_r,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        true,
        "Специализация"
    );
    Cell_2_Text_Ole2 (
        3,
        3,
        str_r+1,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        false,
        "3"                                                                     // column No "[ 3 ]"
    );
    d = Sh
        .OlePropertyGet ("Cells")
        .OlePropertyGet (
            "Item",
            3,
            3
        );
    d.OlePropertySet (
        "ColumnWidth",
        30
    );


    Cell_2_Text_Ole2 (                                                          // Заявка
        4,
        4,
        str_r,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        true,
        "Заявка"
    );
    Cell_2_Text_Ole2 (
        4,
        4,
        str_r+1,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        false,
        "4"                                                                     // column No "[ 4 ]"
    );
    d = Sh
        .OlePropertyGet ("Cells")
        .OlePropertyGet (
            "Item",
            4,
            4
        );
    d.OlePropertySet (
        "ColumnWidth",
        30
    );


    Cell_2_Text_Ole2 (                                                          // Кол-во мест
        5,
        5,
        str_r,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        true,
        "Кол-во мест"
    );
    Cell_2_Text_Ole2 (
        5,
        5,
        str_r+1,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        false,
        "5"                                                                     // column No "[ 5 ]"
    );
    d = Sh
        .OlePropertyGet ("Cells")
        .OlePropertyGet (
            "Item",
            5,
            5
        );
    d.OlePropertySet (
        "ColumnWidth",
        10
    );


    Cell_2_Text_Ole2 (                                                          // Принадлежность министерств
        6,
        6,
        str_r,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        true,
        "Принадлеж-ность министерству"
    );
    Cell_2_Text_Ole2 (
        6,
        6,
        str_r+1,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        false,
        "6"                                                                     // column No "[ 6 ]"
    );
    d= Sh
        .OlePropertyGet ("Cells")
        .OlePropertyGet (
            "Item",
            6,
            6
        );
    d.OlePropertySet (
        "ColumnWidth",
        15
    );


    Cell_2_Text_Ole2 (                                                          // Ф.И.О. студента
        7,
        7,
        str_r,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        true,
        "Ф.И.О. студента"
    );
    Cell_2_Text_Ole2 (
        7,
        7,
        str_r+1,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        false,
        "7"                                                                     // column No "[ 7 ]"
    );
    d = Sh
        .OlePropertyGet ("Cells")
        .OlePropertyGet (
            "Item",
            7,
            7
        );
    d.OlePropertySet (
        "ColumnWidth",
        30
    );


    Cell_2_Text_Ole2 (                                                          // Должность
        8,
        8,
        str_r,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        true,
        "Должность"
    );
    Cell_2_Text_Ole2 (
        8,
        8,
        str_r+1,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        false,
        "8"                                                                     // column No "[ 8 ]"
    );
    d = Sh
        .OlePropertyGet ("Cells")
        .OlePropertyGet (
            "Item",
            8,
            8
        );
    d.OlePropertySet (
        "ColumnWidth",
        20
    );


    Cell_2_Text_Ole2 (                                                          // Жилье
        9,
        9,
        str_r,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        true,
        "Жилье"
    );
    Cell_2_Text_Ole2 (
        9,
        9,
        str_r+1,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        false,
        "9"                                                                     // column No "[ 9 ]"
    );
    d = Sh
        .OlePropertyGet ("Cells")
        .OlePropertyGet (
            "Item",
            9,
            9
        );
    d.OlePropertySet (
        "ColumnWidth",
        20
    );


    Cell_2_Text_Ole2 (                                                          // Примечание
        10,
        10,
        str_r,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        true,
        "Свод"
    );
    Cell_2_Text_Ole2 (
        10,
        10,
        str_r+1,
        true,
        "Arial",
        11,
        false,
        3,
        2,
        0,
        false,
        false,
        "10"                                                                    // column No "[ 10 ]"
    );
    d = Sh
        .OlePropertyGet ("Cells")
        .OlePropertyGet (
            "Item",
            10,
            10
        );
    d.OlePropertySet (
        "ColumnWidth",
        20
    );                                                                          // END >   CREATE TABLE HEADER



    d = Sh                                                                      // установка высоты строки
        .OlePropertyGet ("Cells")
        .OlePropertyGet (
            "Item",
            str_r,
            1
        );
    d.OlePropertySet (
        "RowHeight",
        57
    );

    AnsiString temp_text = "";

    temp_text =                                                                 // определяем сквозные строки
        "$"                         +
            AnsiString (str_r)      +
        ":$"                        +
            AnsiString (str_r + 1);
    
    Sh
    .OlePropertyGet ("PageSetup")
    .OlePropertySet (
        "PrintTitleRows",
        temp_text.c_str ()
    );

    str_r++;
    str_r++;

    DM3 -> Raspred_StateGridQuery -> First ();



    for ( int i = 0;                                                            // BEGIN > FILL THE DATA
              i < DM3 -> Raspred_StateGridQuery -> RecordCount;
              ++i
        )
    {
        Cell_2_Text_Ole2 (
            1,
            1,
            str_r,
            true,
            "Arial",
            11,
            false,
            2,
            2,
            0,
            false,
            true,
            IntToStr (i + 1)                                                    // №№ п/п
        );

        switch (DM3 -> Raspred_StateGridQueryN_FAC -> Value)                    // Факультет
        {
            case 1:                                                             // СИиЕ
                    Cell_2_Text_Ole2 (
                        2,
                        2,
                        str_r,
                        true,
                        "Arial",
                        11,
                        false,
                        2,
                        2,
                        0,
                        false,
                        true,
                        "СПФ СИиЕ"
                    );
                break;
            case 2:                                                             // МВС
                    Cell_2_Text_Ole2 (
                        2,
                        2,
                        str_r,
                        true,
                        "Arial",
                        11,
                        false,
                        2,
                        2,
                        0,
                        false,
                        true,
                        "СПФ МВС"
                    );
                break;
            case 3:                                                             // ОФК
                    Cell_2_Text_Ole2 (
                        2,
                        2,
                        str_r,
                        true,
                        "Arial",
                        11,
                        false,
                        2,
                        2,
                        0,
                        false,
                        true,
                        "ОФКиТ"
                    );
                break;
            case 4:                                                             // МСТиГ
                    Cell_2_Text_Ole2 (
                        2,
                        2,
                        str_r,
                        true,
                        "Arial",
                        11,
                        false,
                        2,
                        2,
                        0,
                        false,
                        true,
                        "Институт туризма"
                    );
                break;
        }


        Cell_2_Text_Ole2 (
            3,
            3,
            str_r,
            true,
            "Arial",
            11,
            false,
            2,
            2,
            0,
            false,
            true,
            DM3 -> Raspred_StateGridQuerySPECIAL -> Value                       // Специализация
        );


        Cell_2_Text_Ole2 (
            4,
            4,
            str_r,
            true,
            "Arial",
            11,
            false,
            2,
            2,
            0,
            false,
            true,
                DM3 -> Raspred_StateGridQueryORG_NAME   -> Value    +\          // Заявка
                tab                                                 +\
                DM3 -> Raspred_StateGridQueryORG_ADRESS -> Value    +\
            ", тел. "                                               +\
                DM3 -> Raspred_StateGridQueryORG_TEL    -> Value
        );

        Cell_2_Text_Ole2 (
            5,
            5,
            str_r,
            true,
            "Arial",
            11,
            false,
            3,
            2,
            0,
            false,
            true,
            DM3 -> Raspred_StateGridQueryCOUNT_SPEC -> Value                    // Кол-во мест
        );

        Cell_2_Text_Ole2 (
            6,
            6,
            str_r,
            true,
            "Arial",
            11,
            false,
            3,
            2,
            0,
            false,
            true,
            DM3 -> Raspred_StateGridQueryNAME_MIN_ORG_1 -> Value                // Принадлежность министерств
        );

        Cell_2_Text_Ole2 (
            7,
            7,
            str_r,
            true,
            "Arial",
            11,
            false,
            3,
            2,
            0,
            false,
            true,
            DM3 -> Raspred_StateGridQueryFIO -> Value                           // Ф.И.О. студента
        );

        Cell_2_Text_Ole2 (
            8,
            8,
            str_r,
            true,
            "Arial",
            11,
            false,
            3,
            2,
            0,
            false,
            true,
                DM3 -> Raspred_StateGridQueryPOST -> Value  +\                  // Должность
            " "                                             +\
                DM3 -> Raspred_StateGridQueryPOL  -> Value
            );

        Cell_2_Text_Ole2 (
            9,
            9,
            str_r,
            true,
            "Arial",
            11,
            false,
            3,
            2,
            0,
            false,
            true,
            DM3 -> Raspred_StateGridQueryFLAT1 -> Value                         // Жилье
        );

        Cell_2_Text_Ole2 (
            10,
            10,
            str_r,
            true,
            "Arial",
            11,
            false,
            3,
            2,
            0,
            false,
            true,
            DM3 -> Raspred_StateGridQueryNAME_MIN_ORG -> Value                  // Примечание
        );

        str_r++;

        DM3 -> Raspred_StateGridQuery -> Next ();
    }                                                                           // END >   FILL THE DATA

    App_n.Clear ();
    Sh.Clear ();
}



// void __fastcall TRaspred_StateForm::DBGrid1SortMarkingChanged (TObject * Sender)
// {
//     DBGrid1 -> DefaultApplySorting ();
// }



void __fastcall TRaspred_StateForm::Edit6Change (TObject * Sender)              // Процедура обработки поиска записи
{
    Set <TLocateOption, loCaseInsensitive, loPartialKey> flags;

    flags << loCaseInsensitive << loPartialKey;

    DM3 ->
        Raspred_StateGridQuery ->
            Locate (
                DBGrid1 ->  SortMarkedColumns -> Items[0] -> FieldName,
                Edit6 -> Text,
                flags
            );
}



void __fastcall TRaspred_StateForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    DM3 -> Raspred_StateGridQuery -> Close ();

    this -> Close ();
}



void __fastcall TRaspred_StateForm::FormCreate (TObject * Sender)
{
    DM3 -> Raspred_StateGridQuery -> Close ();

    DM3 -> Raspred_StateGridQuery ->
        ParamByName ("N_FAC")   -> Value =
                nom_fac;

    DM3 -> Raspred_StateGridQuery ->
        ParamByName ("uch_god") -> Value =
                uch_god + 1;

    DM3 -> Raspred_StateGridQuery -> Open ();
}
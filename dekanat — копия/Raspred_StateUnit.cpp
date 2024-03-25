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



void __fastcall TRaspred_StateForm::BitBtn1Click (TObject * Sender)             // ���������� ����������� � ����
{ }



void __fastcall TRaspred_StateForm::BitBtn8Click (TObject * Sender)
{
    DataModule1 -> ExelInit ();                                                 // ������������ �����

    App_n                                                                       // ������ ���������� ������ � �����
    .OlePropertySet (
        "SheetsInNewWorkbook",
        1                                  
    );

    Sh =                                                                        // ������ ������� ���� ��������
        App_n
        .OlePropertyGet ("WorkSheets")
        .OlePropertyGet (
            "Item",
            1
        );

    Sh = App_n.OlePropertyGet ("ActiveSheet");

    Sh                                                                          // ���������� �� ����� ��� �� ���� �������� � ������ � 100 � ������
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

    Sh                                                                          // ������ �������������� ������������ ��������
    .OlePropertyGet ("PageSetup")
    .OlePropertySet (
        "Orientation",
        2
    );

    // Sh                                                                          // ������ �������������� ������������ ��������
    // .OlePropertyGet ("PageSetup")
    // .OlePropertySet (
    //     "CenterHorizontally",
    //     true
    // );

    // Sh                                                                          // ������ �������������� ������������ ��������
    // .OlePropertyGet ("PageSetup")
    // .OlePropertySet (
    //     "Zoom",
    //     100
    // );


    AnsiString st =                                                             // BEGIN > CREATE TABLE HEADER
        "������ ������ �� ������������� ����������� "           +
            DM3 -> Raspred_StateGridQueryUCH_GOD -> AsString    +
        " ���� �� \"�����\"";

    AnsiString tab    = " ";                                                    // ���������� ��� ������� ALT + Enter � ������ Excel (�������������� ������� �� ��������� ������)
               tab[1] = 0x0A;                                                   // ����������������� ��� ���� ���������� (���������� ��� 10)
    int        str_r = 2;                                                       // ����� ������
    Variant    d;                                                               // Excel OLE Object


    Cell_2_Text_Ole2 (                                                          // "������ ������ �� ������������� ����������� ____ ���� �� "�����""
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


    Cell_2_Text_Ole2 (                                                          // "�� �/�"
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
        "�"     +\
            tab +\
        "�/�"
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


    Cell_2_Text_Ole2 (                                                          // ���������
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
        "���������"
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


    Cell_2_Text_Ole2 (                                                          // �������������
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
        "�������������"
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


    Cell_2_Text_Ole2 (                                                          // ������
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
        "������"
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


    Cell_2_Text_Ole2 (                                                          // ���-�� ����
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
        "���-�� ����"
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


    Cell_2_Text_Ole2 (                                                          // �������������� �����������
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
        "���������-����� ������������"
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


    Cell_2_Text_Ole2 (                                                          // �.�.�. ��������
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
        "�.�.�. ��������"
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


    Cell_2_Text_Ole2 (                                                          // ���������
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
        "���������"
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


    Cell_2_Text_Ole2 (                                                          // �����
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
        "�����"
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


    Cell_2_Text_Ole2 (                                                          // ����������
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
        "����"
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



    d = Sh                                                                      // ��������� ������ ������
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

    temp_text =                                                                 // ���������� �������� ������
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
            IntToStr (i + 1)                                                    // �� �/�
        );

        switch (DM3 -> Raspred_StateGridQueryN_FAC -> Value)                    // ���������
        {
            case 1:                                                             // ����
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
                        "��� ����"
                    );
                break;
            case 2:                                                             // ���
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
                        "��� ���"
                    );
                break;
            case 3:                                                             // ���
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
                        "�����"
                    );
                break;
            case 4:                                                             // �����
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
                        "�������� �������"
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
            DM3 -> Raspred_StateGridQuerySPECIAL -> Value                       // �������������
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
                DM3 -> Raspred_StateGridQueryORG_NAME   -> Value    +\          // ������
                tab                                                 +\
                DM3 -> Raspred_StateGridQueryORG_ADRESS -> Value    +\
            ", ���. "                                               +\
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
            DM3 -> Raspred_StateGridQueryCOUNT_SPEC -> Value                    // ���-�� ����
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
            DM3 -> Raspred_StateGridQueryNAME_MIN_ORG_1 -> Value                // �������������� �����������
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
            DM3 -> Raspred_StateGridQueryFIO -> Value                           // �.�.�. ��������
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
                DM3 -> Raspred_StateGridQueryPOST -> Value  +\                  // ���������
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
            DM3 -> Raspred_StateGridQueryFLAT1 -> Value                         // �����
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
            DM3 -> Raspred_StateGridQueryNAME_MIN_ORG -> Value                  // ����������
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



void __fastcall TRaspred_StateForm::Edit6Change (TObject * Sender)              // ��������� ��������� ������ ������
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
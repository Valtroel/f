#include <vcl.h>
#pragma hdrstop


#include "DataModule.h"
#include <jpeg.hpp>
#include "QueueUnit.h"
#include "StudUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TQueueForm * QueueForm;


// Jpeg::TJPEGImage * ds_jp;
Jpeg::TJPEGImage * jp;
Jpeg::TJPEGImage * jp1;

TMemoryStream    * ds_pms;
TMemoryStream    * pms;



__fastcall TQueueForm::TQueueForm (TComponent * Owner)
    : TForm (Owner)
{ }



void __fastcall TQueueForm::��������Click (TObject * Sender)
{
    StudForm -> DBEdit1 -> ReadOnly = false;
    StudForm -> DBEdit2 -> ReadOnly = false;
    StudForm -> DBEdit3 -> ReadOnly = false;

    StudForm -> Label11 -> Visible  = false;

    StudForm -> CheckBox1    -> Checked    = false;                             // ������� �� ��������� �� ��������� ����
    StudForm -> CheckBox2    -> Checked    = false;
    StudForm -> ComboBox1    -> ItemIndex  = -1;
    StudForm -> ComboBox2    -> ItemIndex  = -1;
    StudForm -> ComboBox3    -> ItemIndex  = -1;
    StudForm -> ComboBox5    -> ItemIndex  = -1;
    StudForm -> DBEdit25     -> ReadOnly   = false;
    StudForm -> DBEdit26     -> ReadOnly   = false;
    StudForm -> DBNavigator1 -> Enabled    = false;
    StudForm -> TabSheet3    -> TabVisible = false;
    StudForm -> DBNavigator3 -> Enabled    = false;
    StudForm -> BitBtn1      -> Enabled    = false;


    DataModule1 -> Prikaz_KursFDQuery   -> Close ();
    DataModule1 -> HolidayFDQuery       -> Close ();                            // ������������� �������
    DataModule1 -> RestoreFDQuery       -> Close ();                            // ������� �� ���������� / ��������������
    DataModule1 -> EncourageFDQuery     -> Close ();                            // ������� � ���������� / ����������
    DataModule1 -> Public_PrikazFDQuery -> Close ();                            // ������ �������


    StudForm -> DBEdit1 -> Text =
        DataModule1 -> QueueFDQueryFAM  -> Value;

    StudForm -> DBEdit2 -> Text =
        DataModule1 -> QueueFDQueryNAME -> Value;

    StudForm -> DBEdit3 -> Text =
        DataModule1 -> QueueFDQueryOTCH -> Value;


    pms    = new TMemoryStream ();
    ds_pms = new TMemoryStream ();
    jp     = new TJPEGImage ();
    jp1    = new TJPEGImage ();


    if ( ! DataModule1 -> QueueFDQueryPHOTO -> IsNull)                          // ����� Image �������� �� ����
    {
        pms -> Clear ();

        DataModule1 ->
            QueueFDQueryPHOTO ->
                SaveToStream (
                    pms
                );

        pms -> Position = 0;

        jp ->   LoadFromStream (pms);

        StudForm ->
            Image1 ->
                Picture ->
                    Assign (
                        jp
                    );
    }
    else
        StudForm -> Image1 -> Picture = NULL;


    if ( ! DataModule1 -> QueueFDQueryDIGIT_SIGN -> IsNull)                     // ����� Image �������� �� ����
    {
        ds_pms -> Clear ();

        DataModule1 ->
            QueueFDQueryDIGIT_SIGN ->
                SaveToStream (
                    ds_pms
                );

        ds_pms -> Position = 0;

        StudForm ->
            Image2 ->
                Picture ->
                    Metafile ->
                        LoadFromStream (
                            ds_pms
                        );
    }

    id_ab = DataModule1 -> QueueFDQueryID_AB -> Value;

    QueueForm -> Close ();
}



void __fastcall TQueueForm::BitBtn1Click (TObject * Sender)
{
    KeyPressAd = 1;

    DataModule1 -> PeopleFDQuery -> CancelUpdates ();

    StudForm -> RefreshControl ();
    StudForm -> DBNavigator1 -> Enabled    = true;
    StudForm -> TabSheet3    -> TabVisible = true;
    StudForm -> DBNavigator3 -> Enabled    = true;
    StudForm -> BitBtn1      -> Enabled    = true;
    StudForm -> DBEdit25     -> ReadOnly   = true;
    StudForm -> DBEdit26     -> ReadOnly   = true;

    QueueForm -> Close ();
}
#include <vcl.h>
#pragma hdrstop


#include "DataModule_Card.h"
#include "DataModule.h"
#include <jpeg.hpp>
#include "KartaUnit.h"
#include "Medical_СhecklistUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TMedical_Checklist_Form * Medical_Checklist_Form;


Jpeg::TJPEGImage * jpga;

TFDBlobStream    * pot;

TfrxPictureView  * pic;





// Button1Click
// FormCreate






__fastcall TMedical_Checklist_Form::TMedical_Checklist_Form (TComponent* Owner)
    : TForm (Owner) {
}

void __fastcall TMedical_Checklist_Form::FormCreate (TObject *Sender) {
    FDQuery2 -> Active = False;
    AnsiString str_nom_fac = AnsiString (nom_fac);
    if (nom_fac == 3) {
        str_nom_fac = "0";
    }
    FDQuery2 -> SQL -> Text = "select increment_group.n_group, increment_group.inc_group from increment_group\
 where substring (increment_group.n_group from 1 for 1) = '" + str_nom_fac + "' \
and increment_group.vid_edu = 0 \
order by increment_group.n_group";
    FDQuery2 -> Active = True;
}

void __fastcall TMedical_Checklist_Form::Button1Click (TObject *Sender) {
    FDQuery1 -> Close ();
    FDQuery1 -> ParamByName ("inc_group") -> AsInteger = DBLookupListBox1 -> KeyValue;
    FDQuery1 -> ParamByName ("year") -> AsDate = StrToDate ("01.05." + IntToStr (uch_god));
    FDQuery1 -> Open ();
    Medical_checklist_print_Form = new TMedical_checklist_print_Form (this);
    while (!FDQuery1 -> Eof) {
        TfrxMemoView * Memo15 =
            dynamic_cast<TfrxMemoView*>
            (Medical_checklist_print_Form -> frxReport1 -> FindObject ("Memo15"));
        Memo15 -> Text = FDQuery1FAC1 -> Value;

        TfrxMemoView * Memo16 =
            dynamic_cast<TfrxMemoView*>
            (Medical_checklist_print_Form -> frxReport1 -> FindObject ("Memo16"));
        Memo16 -> Text = "группа " + FDQuery1N_GROUP -> Value;

        TfrxMemoView * Memo18 =
            dynamic_cast<TfrxMemoView*>
            (Medical_checklist_print_Form -> frxReport1 -> FindObject ("Memo18"));
        Memo18 -> Text = FDQuery1VID_SPORT -> Value;

        TfrxMemoView * Memo19 =
            dynamic_cast<TfrxMemoView*>
            (Medical_checklist_print_Form -> frxReport1 -> FindObject ("Memo19"));
        Memo19 -> Text = FDQuery1FAM -> Value + ' ' + FDQuery1NAME -> Value + ' ' +
            FDQuery1OTCH -> Value;

        TfrxMemoView * Memo20 =
            dynamic_cast<TfrxMemoView*>
            (Medical_checklist_print_Form -> frxReport1 -> FindObject ("Memo20"));
        Memo20 -> Text =
            DateTimeToStr (SQLTimeStampToDateTime (FDQuery1DATA_R -> Value));

        TfrxMemoView * Memo21 =
            dynamic_cast<TfrxMemoView*>
            (Medical_checklist_print_Form -> frxReport1 -> FindObject ("Memo21"));
        if (FDQuery1POL -> Value == "М") {
            Memo21 -> Text = "мужской";
        }
        else
            Memo21 -> Text = "женский";

        TfrxMemoView * Memo22 =
            dynamic_cast<TfrxMemoView*>
            (Medical_checklist_print_Form -> frxReport1 -> FindObject ("Memo22"));
        Memo22 -> Text = FDQuery1NAME_EDUC -> Value;

        TfrxMemoView * Memo23 =
            dynamic_cast<TfrxMemoView*>
            (Medical_checklist_print_Form -> frxReport1 -> FindObject ("Memo23"));
        Memo23 -> Text = FDQuery1TEXT_SPORT_CATEGORY -> Value;

        TfrxMemoView * Memo17 =
            dynamic_cast<TfrxMemoView*>
            (Medical_checklist_print_Form -> frxReport1 -> FindObject ("Memo17"));
        Memo17 -> Text = FDQuery1PHONE -> Value;

        TfrxMemoView * Memo7 =
            dynamic_cast<TfrxMemoView*>
            (Medical_checklist_print_Form -> frxReport1 -> FindObject ("Memo7"));
        Memo7 -> Text = "4. Домашний адрес    " + FDQuery1ADDRESS -> Value;

        TfrxPictureView * pic = dynamic_cast<TfrxPictureView*>
            (Medical_checklist_print_Form -> frxReport1 -> FindObject ("Picture1"));

        if (! (TBlobField*)FDQuery1PHOTO -> IsNull) {
            pot = new TFDBlobStream (FDQuery1PHOTO, bmRead);
            jpga = new Jpeg::TJPEGImage ();
            // показ Image картинки из базы
            pot -> Position = 0;
            // DataModule2 -> Report_CardQueryPHOTO -> SaveToStream (pot)
            jpga -> LoadFromStream (pot);
            pic -> Picture -> Assign (jpga);
            delete pot;
            delete jpga;
        }

        Medical_checklist_print_Form -> frxReport1 -> PrepareReport (False);
        FDQuery1 -> Next ();
    }
    Medical_checklist_print_Form -> frxReport1 -> ShowPreparedReport ();
    delete Medical_checklist_print_Form;
}

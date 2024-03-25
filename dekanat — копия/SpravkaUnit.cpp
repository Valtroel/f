// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SpravkaUnit.h"
#include "ReferenceUnit.h"
#include "DataModule.h"
// ---------------------------------------------------------------------------
#pragma package (smart_init)
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma resource "*.dfm"
TSpravkaForm *SpravkaForm;

// ---------------------------------------------------------------------------
__fastcall TSpravkaForm::TSpravkaForm (TComponent* Owner) : TForm (Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TSpravkaForm::ПечатьClick (TObject *Sender) {
        ReferenceForm = new TReferenceForm (this);
        ReferenceForm -> frxDBDataset2 -> DataSource = SpravkaForm -> DataSource1;
    if (CheckBox5 -> Checked == False) {

        TfrxMemoView * Memo42 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport2 -> FindObject ("Memo42"));
        Memo42 -> Text = Memo2 -> Text;

        TfrxMemoView * Memo19 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport2 -> FindObject ("Memo19"));
        Memo19 -> Text = Edit9 -> Text;

        TfrxMemoView * Memo27 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport2 -> FindObject ("Memo27"));
        Memo27 -> Text = Edit2 -> Text;

        TfrxMemoView * Memo20 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport2 -> FindObject ("Memo20"));
        Memo20 -> Text = Edit3 -> Text;

        TfrxMemoView * Memo21 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport2 -> FindObject ("Memo21"));
        Memo21 -> Text = Edit4 -> Text;

        TfrxMemoView * Memo22 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport2 -> FindObject ("Memo22"));
        Memo22 -> Text = Edit5 -> Text;

        if (Memo1 -> Lines -> Count > 0) {
            TfrxMemoView * Memo28 =
                dynamic_cast<TfrxMemoView*>
                (ReferenceForm -> frxReport2 -> FindObject ("Memo28"));
            Memo28 -> Text = Memo1 -> Lines -> Strings[0];
        }
        if (Memo1 -> Lines -> Count > 1) {
            TfrxMemoView * Memo31 =
                dynamic_cast<TfrxMemoView*>
                (ReferenceForm -> frxReport2 -> FindObject ("Memo31"));
            Memo31 -> Text = Memo1 -> Lines -> Strings[1];
        }
        if (Memo1 -> Lines -> Count > 2) {
            TfrxMemoView * Memo32 =
                dynamic_cast<TfrxMemoView*>
                (ReferenceForm -> frxReport2 -> FindObject ("Memo32"));
            Memo32 -> Text = Memo1 -> Lines -> Strings[2];
        }
        if (Memo1 -> Lines -> Count > 3) {
            TfrxMemoView * Memo33 =
                dynamic_cast<TfrxMemoView*>
                (ReferenceForm -> frxReport2 -> FindObject ("Memo33"));
            Memo33 -> Text = Memo1 -> Lines -> Strings[3];
        }
        if (Memo1 -> Lines -> Count > 4) {
            TfrxMemoView * Memo34 =
                dynamic_cast<TfrxMemoView*>
                (ReferenceForm -> frxReport2 -> FindObject ("Memo34"));
            Memo34 -> Text = Memo1 -> Lines -> Strings[4];
        }
        if (Memo1 -> Lines -> Count > 5) {
            TfrxMemoView * Memo12 =
                dynamic_cast<TfrxMemoView*>
                (ReferenceForm -> frxReport2 -> FindObject ("Memo12"));
            Memo12 -> Text = Memo1 -> Lines -> Strings[5];
        }
        if (Memo1 -> Lines -> Count > 6) {

            TfrxMemoView * Memo35 =
                dynamic_cast<TfrxMemoView*>
                (ReferenceForm -> frxReport2 -> FindObject ("Memo35"));
            Memo35 -> Text = Memo1 -> Lines -> Strings[6];
        }
        if (Memo1 -> Lines -> Count > 7) {
            TfrxMemoView * Memo36 =
                dynamic_cast<TfrxMemoView*>
                (ReferenceForm -> frxReport2 -> FindObject ("Memo36"));
            Memo36 -> Text = Memo1 -> Lines -> Strings[7];
        }
        if (Memo1 -> Lines -> Count > 8) {
            TfrxMemoView * Memo36 =
                dynamic_cast<TfrxMemoView*>
                (ReferenceForm -> frxReport2 -> FindObject ("Memo1"));
            Memo1 -> Text = Memo1 -> Lines -> Strings[8];
        }

        TfrxLineView * Line20 =
            dynamic_cast<TfrxLineView*>
            (ReferenceForm -> frxReport2 -> FindObject ("Line20"));

        TfrxLineView * Line21 =
            dynamic_cast<TfrxLineView*>
            (ReferenceForm -> frxReport2 -> FindObject ("Line21"));
        Line21 -> Top = (Memo1 -> Lines -> Count * 0.6 + 14.8) * 38.5;

        TfrxLineView * Line22 =
            dynamic_cast<TfrxLineView*>
            (ReferenceForm -> frxReport2 -> FindObject ("Line22"));
        Line22 -> Top = (Memo1 -> Lines -> Count * 0.6 + 14.8) * 38.5;

        TfrxMemoView * Memo14 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport2 -> FindObject ("Memo14"));
        Memo14 -> Top = (Memo1 -> Lines -> Count * 0.6 + 12.7) * 38.5;

        TfrxMemoView * Memo15 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport2 -> FindObject ("Memo15"));
        Memo15 -> Top = (Memo1 -> Lines -> Count * 0.6 + 14.2) * 38.5;
        Memo15 -> Text = RadioGroup1 -> Items -> Strings[RadioGroup1 -> ItemIndex];

        TfrxMemoView * Memo16 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport2 -> FindObject ("Memo16"));
        Memo16 -> Top = (Memo1 -> Lines -> Count * 0.6 + 14.8) * 38.5;

        TfrxMemoView * Memo17 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport2 -> FindObject ("Memo17"));
        Memo17 -> Top = (Memo1 -> Lines -> Count * 0.6 + 14.8) * 38.5;

        TfrxMemoView * Memo18 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport2 -> FindObject ("Memo18"));
        Memo18 -> Top = (Memo1 -> Lines -> Count * 0.6 + 14.8) * 38.5;

        TfrxMemoView * Memo26 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport2 -> FindObject ("Memo26"));
        Memo26 -> Top = (Memo1 -> Lines -> Count * 0.6 + 14.2) * 38.5;

        if (RadioGroup1 -> ItemIndex) {
            Memo26 -> Text = Edit6 -> Text;
        }
        else {
            Memo26 -> Text = Edit8 -> Text;
        }

        if (ReferenceForm -> frxReport2 -> PrepareReport (true))
        ReferenceForm -> frxReport2 -> ShowPreparedReport ();
        delete ReferenceForm -> frxReport2;
        delete ReferenceForm;
    }
    else {

        TfrxMemoView * Memo19 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Memo19"));
        Memo19 -> Text = Edit9 -> Text;

        TfrxMemoView * Memo27 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Memo27"));
        Memo27 -> Text = Edit2 -> Text;

        TfrxMemoView * Memo20 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Memo20"));
        Memo20 -> Text = Edit3 -> Text;

        TfrxMemoView * Memo21 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Memo21"));
        Memo21 -> Text = Edit4 -> Text;

        TfrxMemoView * Memo22 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Memo22"));
        Memo22 -> Text = Edit5 -> Text;

        if (Memo1 -> Lines -> Count > 0) {
            TfrxMemoView * Memo28 =
                dynamic_cast<TfrxMemoView*>
                (ReferenceForm -> frxReport3 -> FindObject ("Memo28"));
            Memo28 -> Text = Memo1 -> Lines -> Strings[0];
        }
        if (Memo1 -> Lines -> Count > 1) {
            TfrxMemoView * Memo31 =
                dynamic_cast<TfrxMemoView*>
                (ReferenceForm -> frxReport3 -> FindObject ("Memo31"));
            Memo31 -> Text = Memo1 -> Lines -> Strings[1];
        }
        if (Memo1 -> Lines -> Count > 2) {
            TfrxMemoView * Memo32 =
                dynamic_cast<TfrxMemoView*>
                (ReferenceForm -> frxReport3 -> FindObject ("Memo32"));
            Memo32 -> Text = Memo1 -> Lines -> Strings[2];
        }
        if (Memo1 -> Lines -> Count > 3) {
            TfrxMemoView * Memo33 =
                dynamic_cast<TfrxMemoView*>
                (ReferenceForm -> frxReport3 -> FindObject ("Memo33"));
            Memo33 -> Text = Memo1 -> Lines -> Strings[3];
        }
        if (Memo1 -> Lines -> Count > 4) {
            TfrxMemoView * Memo34 =
                dynamic_cast<TfrxMemoView*>
                (ReferenceForm -> frxReport3 -> FindObject ("Memo34"));
            Memo34 -> Text = Memo1 -> Lines -> Strings[4];
        }
        if (Memo1 -> Lines -> Count > 5) {
            TfrxMemoView * Memo12 =
                dynamic_cast<TfrxMemoView*>
                (ReferenceForm -> frxReport3 -> FindObject ("Memo12"));
            Memo12 -> Text = Memo1 -> Lines -> Strings[5];
        }
        if (Memo1 -> Lines -> Count > 6) {

            TfrxMemoView * Memo35 =
                dynamic_cast<TfrxMemoView*>
                (ReferenceForm -> frxReport3 -> FindObject ("Memo35"));
            Memo35 -> Text = Memo1 -> Lines -> Strings[6];
        }
        if (Memo1 -> Lines -> Count > 7) {
            TfrxMemoView * Memo36 =
                dynamic_cast<TfrxMemoView*>
                (ReferenceForm -> frxReport3 -> FindObject ("Memo36"));
            Memo36 -> Text = Memo1 -> Lines -> Strings[7];
        }
        if (Memo1 -> Lines -> Count > 8) {
            TfrxMemoView * Memo36 =
                dynamic_cast<TfrxMemoView*>
                (ReferenceForm -> frxReport3 -> FindObject ("Memo1"));
            Memo1 -> Text = Memo1 -> Lines -> Strings[8];
        }

        TfrxLineView * Line20 =
            dynamic_cast<TfrxLineView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Line20"));

        TfrxLineView * Line21 =
            dynamic_cast<TfrxLineView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Line21"));
        Line21 -> Top = (Memo1 -> Lines -> Count * 0.6 + 19.1) * 38.5;

        TfrxLineView * Line22 =
            dynamic_cast<TfrxLineView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Line22"));
        Line22 -> Top = (Memo1 -> Lines -> Count * 0.6 + 19.1) * 38.5;

        TfrxMemoView * Memo14 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Memo14"));
        Memo14 -> Top = (Memo1 -> Lines -> Count * 0.6 + 17.2) * 38.5;

        TfrxMemoView * Memo15 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Memo15"));
        Memo15 -> Top = (Memo1 -> Lines -> Count * 0.6 + 18.5) * 38.5;

        TfrxMemoView * Memo17 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Memo17"));
        Memo17 -> Top = (Memo1 -> Lines -> Count * 0.6 + 19.1) * 38.5;

        TfrxMemoView * Memo18 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Memo18"));
        Memo18 -> Top = (Memo1 -> Lines -> Count * 0.6 + 19.1) * 38.5;

        TfrxMemoView * Memo26 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Memo26"));
        Memo26 -> Top = (Memo1 -> Lines -> Count * 0.6 + 18.5) * 38.5;

        TfrxLineView * Line7 =
            dynamic_cast<TfrxLineView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Line7"));
        Line7 -> Top = (Memo1 -> Lines -> Count * 0.6 + 20.7) * 38.5;

        TfrxLineView * Line8 =
            dynamic_cast<TfrxLineView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Line8"));
        Line8 -> Top = (Memo1 -> Lines -> Count * 0.6 + 20.7) * 38.5;

        TfrxMemoView * Memo41 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Memo41"));
        Memo41 -> Top = (Memo1 -> Lines -> Count * 0.6 + 20.1) * 38.5;
        Memo41 -> Text = RadioGroup1 -> Items -> Strings[RadioGroup1 -> ItemIndex];

        TfrxMemoView * Memo7 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Memo7"));
        Memo7 -> Top = (Memo1 -> Lines -> Count * 0.6 + 20.7) * 38.5;

        TfrxMemoView * Memo10 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Memo10"));
        Memo10 -> Top = (Memo1 -> Lines -> Count * 0.6 + 20.7) * 38.5;

        TfrxMemoView * Memo11 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Memo11"));
        Memo11 -> Top = (Memo1 -> Lines -> Count * 0.6 + 20.7) * 38.5;

        TfrxMemoView * Memo13 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Memo13"));
        Memo13 -> Top = (Memo1 -> Lines -> Count * 0.6 + 20.1) * 38.5;

        if (RadioGroup1 -> ItemIndex) {
            Memo13 -> Text = Edit6 -> Text;
        }
        else {
            Memo13 -> Text = Edit8 -> Text;
        }

        TfrxMemoView * Memo42 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport3 -> FindObject ("Memo42"));
        Memo42 -> Text = Memo2 -> Text;

        if (ReferenceForm -> frxReport3 -> PrepareReport (true))
        ReferenceForm -> frxReport3 -> ShowPreparedReport ();
        delete ReferenceForm -> frxReport3;
        delete ReferenceForm;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TSpravkaForm::FormCreate (TObject *Sender) {
    Edit5 -> Text = IntToStr (uch_god);
    FDQuery2 -> ParamByName ("fac") -> Value = nom_fac;
    FDQuery2 -> Active = true;
    Edit8 -> Text = FDQuery2DEAN -> Value;
}
// ---------------------------------------------------------------------------

void __fastcall TSpravkaForm::Edit1Change (TObject *Sender) {
    Set<TLocateOption, 0, 1>f;
    f << loCaseInsensitive << loPartialKey;
    FDQuery2 -> Locate ("FAM", Edit1 -> Text, f);
}

// ---------------------------------------------------------------------------
void __fastcall TSpravkaForm::DataSource2DataChange (TObject *Sender,
    TField *Field) {
    TDateTime dat_start;
    FDQuery1 -> Active = False;
    FDQuery1 -> ParamByName ("NOMER") -> Value = FDQuery2NOMER -> Value;
    FDQuery1 -> Active = True;
    FDQuery3 -> Active = False;
    FDQuery3 -> ParamByName ("NOMER") -> Value = FDQuery2NOMER -> Value;
    FDQuery3 -> Active = True;
    FDQuery4 -> Active = False;
    FDQuery4 -> ParamByName ("NOMER") -> Value = FDQuery2NOMER -> Value;
    FDQuery4 -> Active = True;
    FDQuery5 -> Active = False;
    FDQuery5 -> ParamByName ("NOMER") -> Value = FDQuery2NOMER -> Value;
    FDQuery5 -> Active = True;
    if (SQLTimeStampToDateTime (FDQuery3MAX -> Value) >
        SQLTimeStampToDateTime (FDQuery4MAX -> Value)) {
        dat_start = SQLTimeStampToDateTime (FDQuery3MAX -> Value);
    }
    else
        dat_start = SQLTimeStampToDateTime (FDQuery4MAX -> Value);
    if (FDQuery3MAX -> AsVariant.IsNull () && FDQuery4MAX -> AsVariant.IsNull ()) {
        dat_start = SQLTimeStampToDateTime (FDQuery1D_PRIKAZ_INCLUDE -> Value);
    }

    String year = DateToStr (dat_start).SubString (7, 4);
    Edit5 -> Text = year;

    CheckBox4 -> Caption = "Зачислен приказом от " +
        DateToStr (SQLTimeStampToDateTime (FDQuery1D_PRIKAZ_INCLUDE -> Value)) +
        " № " + IntToStr (FDQuery1N_PRIKAZ_INCLUDE -> Value) + "ст.";
    Edit9 -> Text = FDQuery2FAM -> Value + " " + FDQuery2NAME -> Value + " " +
        FDQuery2OTCH -> Value;
    CheckBox1 -> Checked = false;
    CheckBox2 -> Checked = false;
    CheckBox3 -> Checked = false;
    CheckBox4 -> Checked = false;
    CheckBox6 -> Checked = false;
    Memo1 -> Text = "";
}
// ---------------------------------------------------------------------------

void __fastcall TSpravkaForm::CheckBox1Click (TObject *Sender) {
    Dop_text ();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravkaForm::Dop_text () {
    Memo1 -> Lines -> Clear ();
    if (CheckBox1 -> Checked)
        Memo1 -> Lines -> Add ("          " + CheckBox1 -> Caption);
    // Получает 1-ое в/о
    if (CheckBox2 -> Checked) // Обучается за счет бюджета или по договору
    { // if Обучается за счет бюджета или по договору
        if (FDQuery1N_FOUND -> Value == 2)
            Memo1 -> Lines -> Add
                ("          Обучается по договору о подготовке специалиста с высшим образованием на платной основе."
                );
        else
            Memo1 -> Lines -> Add
                ("          Обучается по договору о подготовке специалиста с высшим образованием за счет средств республиканского бюджета."
                );
    } // end if

    if (CheckBox6 -> Checked)
        Memo1 -> Lines -> Add ("          " + CheckBox6 -> Caption);

    if (CheckBox4 -> Checked)
        Memo1 -> Lines -> Add ("          " + CheckBox4 -> Caption);

    if (CheckBox3 -> Checked) // Приблизительный срок окончания учебного заведения
    { // if Приблизительный срок окончания учебного заведения
        AnsiString konec = "";
        if (FDQuery1VID_EDU -> Value) { // if   заочного отделения
            // !!!!!!Исправлять каждый год!!!!!!!!!!!!!
            switch (FDQuery1KURS -> Value) { // switch  курс
            case 1:
                konec = "апрель " +IntToStr (uch_god+5)+ " года.";
                break;
            case 2:
                konec = "апрель " +IntToStr (uch_god+4)+ " года.";;
                break;
            case 3:
                konec = "апрель " +IntToStr (uch_god+3)+ " года.";;
                break;
            case 4:
                konec = "апрель " +IntToStr (uch_god+2)+ " года.";;
                break;
            case 5:
                konec = "апрель " +IntToStr (uch_god+1)+ " года.";;
                break;
            }

            /* if (DataModule1 -> People_SpravkiQueryKURS -> Value>4)
             {
             konec="апрель "+
             AnsiString (uch_god+ (8-DataModule1 -> People_SpravkiQueryKURS -> Value))+
             " года. ";
             }
             else
             {
             konec="апрель "+
             AnsiString (uch_god+ (7-DataModule1 -> People_SpravkiQueryKURS -> Value))+
             " года. ";
             } */
        } // end if   заочного отделения
        else { // else  дневного отделения
            // !!!!!!Исправлять каждый год!!!!!!!!!!!!!
            switch (FDQuery1KURS -> Value) { // switch  курс
            case 1:
                konec = "30 июня " +IntToStr (uch_god+4)+ " года.";;
                break;
            case 2:
                konec = "30 июня " +IntToStr (uch_god+3)+ " года.";;
                break;
            case 3:
                konec = "30 июня " +IntToStr (uch_god+2)+ " года.";;
                break;
            case 4:
                konec = "30 июня " +IntToStr (uch_god+1)+ " года.";;
                break;
            }
            /* if (DataModule1 -> People_SpravkiQueryKURS -> Value>4)
             {
             konec="июнь "+
             AnsiString (uch_god+ (7-DataModule1 -> People_SpravkiQueryKURS -> Value))+
             " года. ";
             }
             else
             {
             konec="июнь "+
             AnsiString (uch_god+ (6-DataModule1 -> People_SpravkiQueryKURS -> Value))+
             " года. ";
             } */
        } // end else  дневного отделения
        Memo1 -> Lines -> Add ("          " + CheckBox3 -> Caption + " - " + konec);
    }
    // самостоятельный выбор текста
}
// ---------------------------------------------------------------------------

void __fastcall TSpravkaForm::CheckBox2Click (TObject *Sender) {
    Dop_text ();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravkaForm::CheckBox3Click (TObject *Sender) {
    Dop_text ();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravkaForm::CheckBox4Click (TObject *Sender) {
    Dop_text ();
}

// ---------------------------------------------------------------------------
void __fastcall TSpravkaForm::FormActivate (TObject *Sender) {
    Edit1 -> SetFocus ();
}

// ---------------------------------------------------------------------------
void __fastcall TSpravkaForm::CheckBox6Click (TObject *Sender) {
    if (FDQuery5COUNT -> Value == 0) {
        Dop_text ();
    }
    else
        CheckBox6 -> Checked = false;
}
// ---------------------------------------------------------------------------
void __fastcall TSpravkaForm::FormClose (TObject *Sender, TCloseAction &Action)
{
   FDQuery1 -> Active = False;
   FDQuery2 -> Active = False;

}
//---------------------------------------------------------------------------


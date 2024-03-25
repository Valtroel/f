// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "ReferenceUnit.h"
#include "Spravka_vyzovUnit.h"
#include "DataModule.h"
#include "DualList.h"
#include "DataModule_Card.h"
// ---------------------------------------------------------------------------
#pragma package (smart_init)
#pragma link "frxClass"
#pragma link "frxDBSet"
#pragma resource "*.dfm"
TSpravka_vyzovForm *Spravka_vyzovForm;

// ---------------------------------------------------------------------------
__fastcall TSpravka_vyzovForm::TSpravka_vyzovForm (TComponent* Owner)
    : TForm (Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TSpravka_vyzovForm::Button1Click (TObject *Sender) {
    if (DBLookupListBox1 -> KeyValue.IsNull ()) {
        ShowMessage ("¬ыберите группу!");
    }
    else {
        FDQuery2 -> Close ();
        FDQuery2 -> ParamByName ("inc_group") -> AsInteger =
            DBLookupListBox1 -> KeyValue;
        FDQuery2 -> Open ();

        ReferenceForm = new TReferenceForm (this);

        String str_date = DateTimeToStr (DateTimePicker1 -> DateTime);
        String str_date_day = str_date.SubString (1, 2);
        String str_date_month = str_date.SubString (4, 2);
        String str_date_year = str_date.SubString (9, 2);
        int date_month = StrToInt (str_date_month);
        TfrxMemoView * Memo21 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo21"));
        Memo21 -> Text = str_date_day;
        TfrxMemoView * Memo22 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo22"));
        TfrxMemoView * Memo23 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo23"));
        Memo23 -> Text = str_date_year;
        switch (date_month) {
        case 1:
            Memo22 -> Text = "€нвар€";
            break;
        case 2:
            Memo22 -> Text = "феврал€";
            break;
        case 3:
            Memo22 -> Text = "марта";
            break;
        case 4:
            Memo22 -> Text = "апрел€";
            break;
        case 5:
            Memo22 -> Text = "ма€";
            break;
        case 6:
            Memo22 -> Text = "июн€";
            break;
        case 7:
            Memo22 -> Text = "июл€";
            break;
        case 8:
            Memo22 -> Text = "августа";
            break;
        case 9:
            Memo22 -> Text = "сент€бр€";
            break;
        case 10:
            Memo22 -> Text = "окт€бр€";
            break;
        case 11:
            Memo22 -> Text = "но€бр€";
            break;
        case 12:
            Memo22 -> Text = "декабр€";
            break;
        }

        String str_date_from = DateTimeToStr (DateTimePicker2 -> DateTime);
        String str_date_day_from = str_date_from.SubString (1, 2);
        String str_date_month_from = str_date_from.SubString (4, 2);
        String str_date_year_from = str_date_from.SubString (9, 2);
        int date_month_from = StrToInt (str_date_month_from);
        TfrxMemoView * Memo30 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo30"));
        Memo30 -> Text = str_date_day_from;
        TfrxMemoView * Memo31 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo31"));
        TfrxMemoView * Memo32 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo32"));
        Memo32 -> Text = str_date_year_from;
        TfrxMemoView * Memo44 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo44"));
        Memo44 -> Text = str_date_day_from;
        TfrxMemoView * Memo45 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo45"));
        TfrxMemoView * Memo46 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo46"));
        Memo46 -> Text = str_date_year_from;

        switch (date_month_from) {
        case 1:
            Memo31 -> Text = "€нвар€";
            Memo45 -> Text = "€нвар€";
            break;
        case 2:
            Memo31 -> Text = "феврал€";
            Memo45 -> Text = "феврал€";
            break;
        case 3:
            Memo31 -> Text = "марта";
            Memo45 -> Text = "марта";
            break;
        case 4:
            Memo31 -> Text = "апрел€";
            Memo45 -> Text = "апрел€";
            break;
        case 5:
            Memo31 -> Text = "ма€";
            Memo45 -> Text = "ма€";
            break;
        case 6:
            Memo31 -> Text = "июн€";
            Memo45 -> Text = "июн€";
            break;
        case 7:
            Memo31 -> Text = "июл€";
            Memo45 -> Text = "июл€";
            break;
        case 8:
            Memo31 -> Text = "августа";
            Memo45 -> Text = "августа";
            break;
        case 9:
            Memo31 -> Text = "сент€бр€";
            Memo45 -> Text = "сент€бр€";
            break;
        case 10:
            Memo31 -> Text = "окт€бр€";
            Memo45 -> Text = "окт€бр€";
            break;
        case 11:
            Memo31 -> Text = "но€бр€";
            Memo45 -> Text = "но€бр€";
            break;
        case 12:
            Memo31 -> Text = "декабр€";
            Memo45 -> Text = "декабр€";
            break;
        }

        String str_date_by = DateTimeToStr (DateTimePicker3 -> DateTime);
        String str_date_day_by = str_date_by.SubString (1, 2);
        String str_date_month_by = str_date_by.SubString (4, 2);
        String str_date_year_by = str_date_by.SubString (9, 2);
        int date_month_by = StrToInt (str_date_month_by);
        TfrxMemoView * Memo35 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo35"));
        Memo35 -> Text = str_date_day_by;
        TfrxMemoView * Memo36 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo36"));
        TfrxMemoView * Memo37 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo37"));
        Memo37 -> Text = str_date_year_by;
        TfrxMemoView * Memo49 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo49"));
        Memo49 -> Text = str_date_day_by;
        TfrxMemoView * Memo50 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo50"));
        TfrxMemoView * Memo51 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo51"));
        Memo51 -> Text = str_date_year_by;
        switch (date_month_by) {
        case 1:
            Memo36 -> Text = "€нвар€";
            Memo50 -> Text = "€нвар€";
            break;
        case 2:
            Memo36 -> Text = "феврал€";
            Memo50 -> Text = "феврал€";
            break;
        case 3:
            Memo36 -> Text = "марта";
            Memo50 -> Text = "марта";
            break;
        case 4:
            Memo36 -> Text = "апрел€";
            Memo50 -> Text = "апрел€";
            break;
        case 5:
            Memo36 -> Text = "ма€";
            Memo50 -> Text = "ма€";
            break;
        case 6:
            Memo36 -> Text = "июн€";
            Memo50 -> Text = "июн€";
            break;
        case 7:
            Memo36 -> Text = "июл€";
            Memo50 -> Text = "июл€";
            break;
        case 8:
            Memo36 -> Text = "августа";
            Memo50 -> Text = "августа";
            break;
        case 9:
            Memo36 -> Text = "сент€бр€";
            Memo50 -> Text = "сент€бр€";
            break;
        case 10:
            Memo36 -> Text = "окт€бр€";
            Memo50 -> Text = "окт€бр€";
            break;
        case 11:
            Memo36 -> Text = "но€бр€";
            Memo50 -> Text = "но€бр€";
            break;
        case 12:
            Memo36 -> Text = "декабр€";
            Memo50 -> Text = "декабр€";
            break;
        }

        TfrxMemoView * Memo7 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo7"));
        TfrxMemoView * Memo8 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo8"));
        TfrxMemoView * Memo9 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo9"));
        TfrxMemoView * Memo10 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo10"));
        TfrxMemoView * Memo11 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo11"));
        TfrxMemoView * Memo60 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo60"));
        TfrxMemoView * Memo59 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo59"));
        TfrxMemoView * Memo62 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo62"));
        TfrxMemoView * Memo61 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo61"));
        Memo7 -> Underlines = False;
        Memo8 -> Underlines = False;
        Memo9 -> Underlines = False;
        Memo10 -> Underlines = False;
        Memo11 -> Underlines = False;
        Memo60 -> Underlines = False;
        Memo59 -> Underlines = False;
        Memo62 -> Underlines = False;
        Memo61 -> Underlines = False;
        TfrxMemoView * Memo63 =
            dynamic_cast<TfrxMemoView*>
            (ReferenceForm -> frxReport1 -> FindObject ("Memo63"));
        Memo63 -> Text = "";
        switch (ListBox2 -> ItemIndex) {
        case 0:
            Memo7 -> Underlines = True;
            Memo63 -> Text = "установочной сессии";
            break;
        case 1:
            Memo8 -> Underlines = True;
            Memo63 -> Text = "сдаче экзаменов и зачЄтов";
            break;
        case 2:
            Memo9 -> Underlines = True;
            Memo63 -> Text = "государственных экзаменах";
            break;
        case 3:
            Memo10 -> Underlines = True;
            Memo63 -> Text = "обзорных лекци€х";
            break;
        case 4:
            Memo60 -> Underlines = True;
            Memo63 -> Text = "учебной практике по лыжному спорту";
            break;
        case 5:
            Memo11 -> Underlines = True;
            Memo63 -> Text = "учебной практике по туризму";
            break;
        case 6:
            Memo59 -> Underlines = True;
            Memo63 -> Text = "учебной практике";
            break;
        case 7:
            Memo62 -> Underlines = True;
            Memo63 -> Text = "профессионально-ориентированной учебной практике";
            break;
        case 8:
            Memo61 -> Underlines = True;
            Memo63 -> Text = "производственной практике";
            break;
        }

        if (MessageDlg ("¬ы хотите напечатать справки дл€ всей группы?",
            mtConfirmation, TMsgDlgButtons () << mbYes << mbNo, 0) == mrNo) {

            DualListDlg = new TDualListDlg (this);
            DualListDlg -> SrcList -> Items -> Clear ();
            DualListDlg -> DstList -> Items -> Clear ();

            // -------
            for (int i = 0; i < FDQuery2 -> RecordCount; i++)
            { // заносим записи специализаций в компонент
                DualListDlg -> SrcList -> Items -> AddObject
                    (FDQuery2FAM -> Value + " " + FDQuery2NAME -> Value + " " +
                    FDQuery2OTCH -> Value, (TObject *) (FDQuery2NOMER -> Value));
                FDQuery2 -> Next ();
            }
            // -------

            DualListDlg -> ShowModal ();
            if (DataModule2 -> printdlg == true) {
                int k = 0;
                if (DualListDlg -> DstList -> Items -> Count != 0) {
                    for (int i = 0; i < DualListDlg -> DstList -> Items -> Count; i++)
                    {
                        FDQuery2 -> First ();
                        while (!FDQuery2 -> Eof) {
                            if (FDQuery2NOMER -> Value == (int)
                                (DualListDlg -> DstList -> Items -> Objects[i])) {
                                TfrxMemoView * Memo1 =
                                    dynamic_cast<TfrxMemoView*>
                                    (ReferenceForm -> frxReport1 -> FindObject
                                    ("Memo1"));
                                Memo1 -> Text =
                                    Label2 -> Caption +
                                    IntToStr (StrToInt (Edit1 -> Text) + k);
                                TfrxMemoView * Memo5 =
                                    dynamic_cast<TfrxMemoView*>
                                    (ReferenceForm -> frxReport1 -> FindObject
                                    ("Memo5"));
                                Memo5 -> Text =
                                    DualListDlg -> DstList -> Items -> Strings[i];
                                TfrxMemoView * Memo58 =
                                    dynamic_cast<TfrxMemoView*>
                                    (ReferenceForm -> frxReport1 -> FindObject
                                    ("Memo58"));
                                Memo58 -> Text =
                                    DualListDlg -> DstList -> Items -> Strings[i];
                                ReferenceForm -> frxReport1 -> PrepareReport (False);
                                FDQuery2 -> Next ();
                                k++;
                            }
                            FDQuery2 -> Next ();
                        }

                    }

                }
            }
        }
        else {

            int i = 0;
            while (!FDQuery2 -> Eof) {
                TfrxMemoView * Memo1 =
                    dynamic_cast<TfrxMemoView*>
                    (ReferenceForm -> frxReport1 -> FindObject ("Memo1"));
                Memo1 -> Text = Label2 -> Caption +
                    IntToStr (StrToInt (Edit1 -> Text) + i);
                TfrxMemoView * Memo5 =
                    dynamic_cast<TfrxMemoView*>
                    (ReferenceForm -> frxReport1 -> FindObject ("Memo5"));
                Memo5 -> Text = FDQuery2FAM -> Value + " " + FDQuery2NAME -> Value +
                    " " + FDQuery2OTCH -> Value;
                TfrxMemoView * Memo58 =
                    dynamic_cast<TfrxMemoView*>
                    (ReferenceForm -> frxReport1 -> FindObject ("Memo58"));
                Memo58 -> Text = FDQuery2FAM -> Value + " " + FDQuery2NAME -> Value +
                    " " + FDQuery2OTCH -> Value;
                ReferenceForm -> frxReport1 -> PrepareReport (False);
                FDQuery2 -> Next ();
                i++;
            }

        }

        ReferenceForm -> frxReport1 -> ShowPreparedReport ();
        FDQuery2 -> Close ();
        FDQuery1 -> Close ();
        delete ReferenceForm;
    }
}
// ---------------------------------------------------------------------------

void __fastcall TSpravka_vyzovForm::FormActivate (TObject *Sender) {
    Label2 -> Caption = "є 07/0" + IntToStr (nom_fac) + "-";
    if (nom_fac == 4) {
        Label2 -> Caption = "";
    }
    DateTimePicker1 -> Date = Now ();
    DateTimePicker2 -> Date = Now ();
    DateTimePicker3 -> Date = Now ();
}
// ---------------------------------------------------------------------------

void __fastcall TSpravka_vyzovForm::ListBox1Click (TObject *Sender) {
    FDQuery1 -> Active = False;
    FDQuery1 -> SQL -> Clear ();
    AnsiString str_nom_fac = AnsiString (nom_fac);
    int gr_uch_god = uch_god + 1;
    if (nom_fac == 3) {
        str_nom_fac = "0";
    }
    FDQuery1 -> SQL -> Text = "select increment_group.n_group, increment_group.inc_group from increment_group\
 where substring (increment_group.n_group from 1 for 1) = '" + str_nom_fac +
        "' and increment_group.god = " + gr_uch_god + " and increment_group.vid_edu = 1  \
and substring (increment_group.n_group from 2 for 1) = '" +
        ListBox1 -> Items -> Strings[ListBox1 -> ItemIndex] + "' \
order by increment_group.n_group";
    FDQuery1 -> Active = True;
}

// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop


#include "Ball_Unit.h"
#include "DataModule.h"
#include "MainUnit.h"
#include "Result_VedUnit.h"


#pragma package (smart_init)
// #pragma link     "ToolEdit"
// #pragma link     "RXCtrls"
#pragma resource "*.dfm"


TResult_VedForm * Result_VedForm;


bool   check    = false,                                                        // ���� ��������� ���� �������
       del_mas  = false;                                                        // ���� �������� ������� ���������

int    inc_ved;

int  * inc_stud;                                                                // ������ ��� ������� ���������



__fastcall TResult_VedForm::TResult_VedForm (TComponent * Owner)
    : TForm (Owner)
{ }






// BitBtn1Click
// BitBtn2Click
// Button1Click
// DateTimePicker1Change
// DBGrid1DblClick
// Edit1Change
// Edit1KeyPress
// Edit5KeyPress
// FormActivate
// FormClose
// FormCreate
// RadioGroup_Ball
// RxCheckListBox1DblClick







void __fastcall TResult_VedForm::RadioGroup_Ball ()
{ // ��������� ��� ��������� Items-�� �  RadioGroup1 �� Ball_Form
    // � ����������� �� ���� �������� � ������� ������
    // ��� ��������  0 - ��� ��������
    // 1 - �����
    // 2 - �������
    // 3 - ���. �����
    Ball_Form -> RadioGroup1 -> Items -> Clear ();
    if (DataModule1 -> Ball_FDQueryZACH_EXAM -> Value == 1) // ��� �����
    { // if  �����
        Ball_Form -> RadioGroup1 -> Caption = "�����:";

        Ball_Form -> RadioGroup1 -> Items -> Add ("�������");
        Ball_Form -> RadioGroup1 -> Items -> Add ("�� ������");
        Ball_Form -> RadioGroup1 -> Items -> Add ("�����");
        Ball_Form -> RadioGroup1 -> Items -> Add ("����������");
    } // end if  �����
    else { // else  �������    ���. �����
        if (DataModule1 -> Ball_FDQueryZACH_EXAM -> Value == 2)
            Ball_Form -> RadioGroup1 -> Caption = "�������:";
        else
            Ball_Form -> RadioGroup1 -> Caption = "���. �����:";
        if (!Ball_Form -> RadioGroup2 -> ItemIndex) // �������� �� ������� ������
        { // if ���� ������� 10-�� �������
            Ball_Form -> RadioGroup1 -> Items -> Add ("����");
            Ball_Form -> RadioGroup1 -> Items -> Add ("���");
            Ball_Form -> RadioGroup1 -> Items -> Add ("���");
            Ball_Form -> RadioGroup1 -> Items -> Add ("������");
            Ball_Form -> RadioGroup1 -> Items -> Add ("����");
            Ball_Form -> RadioGroup1 -> Items -> Add ("�����");
            Ball_Form -> RadioGroup1 -> Items -> Add ("����");
            Ball_Form -> RadioGroup1 -> Items -> Add ("������");
            Ball_Form -> RadioGroup1 -> Items -> Add ("������");
            Ball_Form -> RadioGroup1 -> Items -> Add ("������");
            Ball_Form -> RadioGroup1 -> Items -> Add ("�� ������");
            Ball_Form -> RadioGroup1 -> Items -> Add ("����������");
            Ball_Form -> RadioGroup1 -> Columns = 3;
            Ball_Form -> RadioGroup1 -> Width = 290;
        } // end if ���� ������� 10-�� �������
        else { // else ���� ������� 5-�� �������
            Ball_Form -> RadioGroup1 -> Items -> Add ("�������.");
            Ball_Form -> RadioGroup1 -> Items -> Add ("�� ������");
            Ball_Form -> RadioGroup1 -> Items -> Add ("����������");
            Ball_Form -> RadioGroup1 -> Items -> Add ("�����.");
            Ball_Form -> RadioGroup1 -> Items -> Add ("������");
            Ball_Form -> RadioGroup1 -> Items -> Add ("�������");
            Ball_Form -> RadioGroup1 -> Columns = 2;
            Ball_Form -> RadioGroup1 -> Width = 217;
        } // end else ���� ������� 5-�� �������
    } // end else  �������    ���. �����

} // ��������� ��� ��������� Items-�� �  RadioGroup1 �� Ball_Form


void __fastcall TResult_VedForm::DBGrid1DblClick (TObject *Sender) {
    /*
     if (!OpenChildForm (Result_VedForm,Ball_Form))//MainForm,Ball_Form))
     {
     Ball_Form = new TBall_Form (this);//�������� �����
     RadioGroup_Ball (); //��������� ��� ��������� Items-�� �  RadioGroup1 �� Ball_Form

     Ball_Form -> Radio_setup (); //��������� � RadioGroup1 � Edit1 �� ����� Ball_Form
     //�������� �� ���� ������
     Ball_Form -> Show ();   //����� �����
     }

     */
    Ball_Form = new TBall_Form (this);

    RadioGroup_Ball ();
    // ��������� ��� ��������� Items-�� �  RadioGroup1 �� Ball_Form

    Ball_Form -> Radio_setup ();
    // ��������� � RadioGroup1 � Edit1 �� ����� Ball_Form

    // �������� �� ���� ������

    Ball_Form -> Visible = false;
    // ��� ShowModal ����� ������ ����  Visible=false
    Ball_Form -> ShowModal ();
}


void __fastcall TResult_VedForm::BitBtn1Click (TObject *Sender) {
    Close ();
}


void __fastcall TResult_VedForm::FormClose (TObject *Sender,
    TCloseAction &Action) {

    if (del_mas)
        delete inc_stud; // if ��� ������ ������ �� ���������, ��� ���� �������
    Action = caFree;
}


void __fastcall TResult_VedForm::BitBtn2Click (TObject *Sender) {

    // if (Edit1 -> Text!="" && DateEdit1 -> Text!="  .  .    " && Edit2 -> Text!="")

    if (del_mas) { // if ��� ������ ������ �� ���������, ��� ���� �������
        delete inc_stud;
        del_mas = false;
    }

    if (Edit1 -> Text != "") {
        DataModule1 -> VedomostFDQuery -> Close ();
        DataModule1 -> VedomostFDQuery -> SQL -> Clear ();
        DataModule1 -> VedomostFDQuery -> SQL -> Add
            ("SELECT Vedomost.N_VED, Vedomost.N_VEDOMOST, Vedomost.D_VED, Vedomost.SEMESTR_VED, Vedomost.FIO_EXAM, Vedomost.STATUS, Vedomost.N_PLAN, Vedomost.N_FAC, Vedomost.END_D_EXAM, Vedomost.INC_GROUP, Vedomost.N_SPECIALIZ, Vedomost.INVALID, Object_plan.NAME_OBJECT, Edu_plan.YEAR_PLAN, Edu_plan.VID_EDU_PLAN FROM VEDOMOST Vedomost INNER JOIN EDU_PLAN Edu_plan ON  (Vedomost.N_PLAN = Edu_plan.N_PLAN) INNER JOIN OBJECT_PLAN Object_plan ON  (Edu_plan.N_OBJECT = Object_plan.N_OBJECT) WHERE (Vedomost.N_FAC=:N_FAC) AND (Edu_plan.YEAR_PLAN=:PLAN) AND (Vedomost.INVALID = 0)  ORDER BY Vedomost.N_VEDOMOST"
            );
        DataModule1 -> VedomostFDQuery -> Params -> Items[0] -> AsInteger = nom_fac;
        DataModule1 -> VedomostFDQuery -> ParamByName ("PLAN") -> Value =
            Edit5 -> Text.ToInt ();
        DataModule1 -> VedomostFDQuery -> Open ();
        /*
         Variant locvalues[]={Edit1 -> Text.ToInt (),DateEdit1 -> Text,Edit2 -> Text.ToInt ()};
         Variant kkk=DataModule1 -> VedomostQuery -> Lookup ("N_VEDOMOST;D_VED;SEMESTR_VED",VarArrayOf (locvalues,2),"N_VED");
         */

        Variant kkk = DataModule1 -> VedomostFDQuery -> Lookup ("N_VEDOMOST",
            Edit1 -> Text.ToInt (), "N_VED");
        if (kkk.IsNull ()) {
            ShowMessage ("��� ����� ���������!");
            Edit1 -> Text = "";
            Edit1 -> SetFocus ();
            return;
        }
        inc_ved = kkk;
        DataModule1 -> Ball_FDQuery -> Close ();
        DataModule1 -> Ball_FDQuery -> ParamByName ("N_FAC") -> AsInteger = nom_fac;
        DataModule1 -> Ball_FDQuery -> ParamByName ("N_VEDOM") -> AsInteger = inc_ved;
        DataModule1 -> Ball_FDQuery -> Open ();
        // ---����� ����� ��� �������� ��� ���� ��������  ��� ������������
        if (!DataModule1 -> Ball_FDQueryZACH_EXAM -> Value ||
            DataModule1 -> Ball_FDQueryZACH_EXAM -> Value == 5)
        { // if  ��� ���� ��������
            inc_stud = new int[DataModule1 -> Ball_FDQuery -> RecordCount];
            CheckListBox1 -> Clear ();
            for (int i = 0; i < DataModule1 -> Ball_FDQuery -> RecordCount; i++) {
                CheckListBox1 -> Items -> Add (DataModule1 -> Ball_FDQueryFAM -> Value +
                    " " + DataModule1 -> Ball_FDQueryNAME -> Value + " " +
                    DataModule1 -> Ball_FDQueryOTCH -> Value);
                inc_stud[i] = DataModule1 -> Ball_FDQueryNOMER -> Value;
                if (DataModule1 -> Ball_FDQueryBALL -> Value == 9)
                    CheckListBox1 -> Checked[i] = true;
                else
                    CheckListBox1 -> Checked[i] = false;
                DataModule1 -> Ball_FDQuery -> Next ();

            }
            Panel2 -> Visible = true;
            DBGrid1 -> Visible = false;
            del_mas = true;
        } // end if  ��� ���� ��������
        else { // else �������� ������� ���������
            Panel2 -> Visible = false;
            DBGrid1 -> Visible = true;
        } // end else �������� ������� ���������
        // -----
        Panel1 -> Visible = true;
        Result_VedForm -> Height = 309;
    }
    else {
        ShowMessage ("������� �� ��� ������!");
    }

}


void __fastcall TResult_VedForm::Edit1Change (TObject *Sender) {
    Panel1 -> Visible = false;
    Result_VedForm -> Height = 158;
    DataModule1 -> Ball_FDQuery -> Close ();
}


void __fastcall TResult_VedForm::FormActivate (TObject *Sender) {
    // Edit5 -> Text=uch_god;
    // Edit6 -> Text=uch_god+1;
}


/*
 void __fastcall TResult_VedForm::DBGrid1DrawColumnCell (TObject *Sender,
 const TRect &Rect, int DataCol, TColumn *Column,
 TGridDrawState State)
 {
 if (DataModule1 -> Ball_QueryBALL1 -> Value=="�������")
 {
 DBGrid1 -> Canvas -> Font -> Color=clRed;
 }
 if (DataModule1 -> Ball_QueryBALL1 -> Value=="������")
 {
 DBGrid1 -> Canvas -> Font -> Color=clBlue;
 }
 if (DataModule1 -> Ball_QueryBALL1 -> Value=="�����.")
 {
 DBGrid1 -> Canvas -> Font -> Color=clGreen;
 }
 if (DataModule1 -> Ball_QueryBALL1 -> Value=="�������.")
 {
 DBGrid1 -> Canvas -> Font -> Color=clBlack;
 }
 if (DataModule1 -> Ball_QueryBALL1 -> Value=="�� ������")
 {
 DBGrid1 -> Canvas -> Font -> Color=clBlack;
 }
 if (DataModule1 -> Ball_QueryBALL1 -> Value=="�����")
 {
 DBGrid1 -> Canvas -> Font -> Color=clRed;
 }
 if (DataModule1 -> Ball_QueryBALL1 -> Value=="�������")
 {
 DBGrid1 -> Canvas -> Font -> Color=clBlack;
 }
 if (Column -> FieldName!="BALL1")
 {
 DBGrid1 -> Canvas -> Font -> Color=clBlack;
 }
 DBGrid1 -> DefaultDrawColumnCell (Rect, DataCol, Column, State);

 } */


void __fastcall TResult_VedForm::FormCreate (TObject *Sender) {
    Edit5 -> Text = uch_god;
    Edit6 -> Text = uch_god + 1;
}


void __fastcall TResult_VedForm::Edit1KeyPress (TObject *Sender, char &Key) {
    if (Key == 13) { // if ���� ������ ������� Enter
        BitBtn2Click (Sender);
    } // end if ���� ������ ������� Enter
    DataModule1 -> Edit_Key (Key);
    // ��� �������, ����� � TEdit ����� ���� ������� ������ �����?
}


void __fastcall TResult_VedForm::Button1Click (TObject *Sender) {
    TLocateOptions n_s;
    for (int i = 0; i < CheckListBox1 -> Items -> Count; i++)
    { // if �������� �� ���� ���������
        if (DataModule1 -> Ball_FDQuery -> Locate ("NOMER", inc_stud[i], n_s))
        { // if ����� ��������

            // ����� �� ������ ��������  � ������ �������� �����
            DataModule1 -> Result_Ball_LocateFDQuery -> Close ();
            DataModule1 -> Result_Ball_LocateFDQuery -> ParamByName ("NOM")
                -> AsInteger = inc_stud[i];
            DataModule1 -> Result_Ball_LocateFDQuery -> ParamByName ("PLAN")
                -> AsInteger = DataModule1 -> Ball_FDQueryN_PLAN -> Value;
            DataModule1 -> Result_Ball_LocateFDQuery -> Open ();

            // ���������� ��� ����������� ���
            AnsiString fio = "�� ����� �������� ������� " +
                CheckListBox1 -> Items -> Strings[i] + " ����� ������. ������� ��?";

            DataModule1 -> Ball_FDQuery -> Edit ();

            if (CheckListBox1 -> Checked[i])
            { // if ������ ������� - ��������� ���� ����
                if (!DataModule1 -> Result_Ball_LocateFDQuery -> RecordCount)
                { // if ��� � ������� �������� ������ �� ������� ��������
                    // ���������
                    DataModule1 -> Result_Ball_LocateFDQuery -> Insert ();
                    DataModule1 -> Result_Ball_LocateFDQueryNOMER -> Value =
                        inc_stud[i];
                    DataModule1 -> Result_Ball_LocateFDQueryN_PLAN -> Value =
                        DataModule1 -> Ball_FDQueryN_PLAN -> Value;
                    DataModule1 -> Result_Ball_LocateFDQueryRESULT -> Value = 9;
                    DataModule1 -> Result_Ball_LocateFDQueryDATE_RESULT -> Value =
                        DataModule1 -> Ball_FDQueryD_EXAM -> Value;
                    DataModule1 -> Result_Ball_LocateFDQuerySTATUS_RESULT -> 
                        Value = 0;
                } // end if ��� � ������� �������� ������ �� ������� ��������
                DataModule1 -> Ball_FDQueryBALL -> Value = 9;
                // ������ ��������� ����
            } // end if ������ ������� - ��������� ���� ����
            else { // else �� ���������
                if (DataModule1 -> Result_Ball_LocateFDQuery -> RecordCount)
                { // if ���� ������� ������ ��� ������� �������� �� ����� �������� �����
                    // !!!if (Application -> MessageBox (fio.c_str (), "��������!!!!", MB_YESNO) == mrYes)
                    if (MessageDlg (fio.c_str (), mtConfirmation,
                        TMsgDlgButtons () << mbYes << mbNo, 0) == mrYes) { // if
                        DataModule1 -> Result_Ball_LocateFDQuery -> Delete ();
                        DataModule1 -> Result_Ball_LocateFDQuery -> ApplyUpdates ();
                        DataModule1 -> Result_Ball_LocateFDQuery -> CommitUpdates ();
                    } // end if
                } // end if ���� ������� ������ ��� ������� �������� �� ����� �������� �����
                DataModule1 -> Ball_FDQueryBALL -> Value = 8;
                // ������ �� ��������� ����
            } // end else �� ���������
            // ------
            try { // try �������� �� ������������ ���������� � Result_BallQuery  - ������� ��������
                DataModule1 -> Result_Ball_LocateFDQuery -> ApplyUpdates ();
                DataModule1 -> Result_Ball_LocateFDQuery -> CommitUpdates ();
            } // end try
            catch (...) { // catch
                ShowMessage (
                    "�� ��������� ������ � ������� ��������. ��������� �������!");
                DataModule1 -> Result_Ball_LocateFDQuery -> CancelUpdates ();
                DataModule1 -> Ball_FDQuery -> Cancel ();
                return;
            } // end catch
            // -------
            try { // try �������� �� ������������ ���������� �   Ball_Query - ���������� ���������
                DataModule1 -> Ball_FDQuery -> ApplyUpdates ();
                DataModule1 -> Ball_FDQuery -> CommitUpdates ();
            }
            catch (...) { // catch
                DataModule1 -> Ball_FDQuery -> CancelUpdates ();
                ShowMessage ("��������� ����! ��������� �������");
                return;
            } // end catch
        } // end if ����� ��������
        n_s.Clear ();
    } // end if �������� �� ���� ���������

}


void __fastcall TResult_VedForm::RxCheckListBox1DblClick (TObject *Sender) {
    for (int i = 0; i < CheckListBox1 -> Items -> Count; i++)
    { // if �������� �� ����
        // check=false -- ���������� ��� ������������ ���� ������ ( ������ �� ����� )
        if (check)
            CheckListBox1 -> Checked[i] = false;
        else
            CheckListBox1 -> Checked[i] = true;
    }
    check = !check;

}


void __fastcall TResult_VedForm::Edit5KeyPress (TObject *Sender, char &Key) {
    DataModule1 -> Edit_Key (Key);
    // ��� �������, ����� � TEdit ����� ���� ������� ������ �����?
}


void __fastcall TResult_VedForm::DateTimePicker1Change (TObject *Sender) {
    DateTimePicker1 -> Time = StrToTime ("00:00");
}


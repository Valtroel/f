#include <vcl.h>
#pragma hdrstop


#include "NK_3Unit.h"
#include "DataModule.h"
#include <DateUtils.hpp>


#pragma package (smart_init)
#pragma resource "*.dfm"


TNK_3Form * NK_3Form;


AnsiString   sql_group_by = "",                                                 // ����� ��������� SQL ������� ����� �������
             sql_text     = "";                                                 // ����� ��������� SQL ������� ����� �������

TFDQuery   * q1;                                                                // Query � ������� ����� ��������





// BitBtn1Click
// BitBtn2Click
// BitBtn3Click
// BitBtn4Click
// BitBtn5Click
// BitBtn6Click
// BitBtn7Click
// BitBtn8Click
// CheckBox1Click
// Clear_StringGrid
// Create_StringGrid
// Date_Diap
// Form_Max
// Form_Min
// FormClose
// FormCreate
// RadioGroup1Click
// RadioGroup2Click








__fastcall TNK_3Form::TNK_3Form (TComponent* Owner) : TForm (Owner) {
}


void __fastcall TNK_3Form::Form_Min () { // ���������� ������� �����

    Panel2 -> Visible = false;
    Panel3 -> Visible = false;
    CheckBox1 -> Visible = false;

    NK_3Form -> Height = 117;
    if (NK_3Form -> Position != poMainFormCenter)
        NK_3Form -> Position = poMainFormCenter;
}


void __fastcall TNK_3Form::Form_Max () { // ���������� ������� �����

    Panel2 -> Visible = true;
    Panel3 -> Visible = true;
    StringGrid1 -> Visible = true;
    NK_3Form -> Height = 500;
    if (NK_3Form -> Position != poMainFormCenter)
        NK_3Form -> Position = poMainFormCenter;
}


bool __fastcall TNK_3Form::Clear_StringGrid ()
{ // ������ �������� � ������� StringGrida
    //////////��������
    if (RadioGroup1 -> ItemIndex == -1 || RadioGroup2 -> ItemIndex == -1)
    { // if ����� �������� � �������� �� ���-�� ��� �����
        ShowMessage ("������� ��� �������� ������!");
        return false;
    }

    // ----�������� �����������   StringGrid
    for (int i = 0; i < StringGrid1 -> ColCount; i++)
    { // for  StringGrid1 -> RowCount
        for (int j = 0; j < StringGrid1 -> RowCount + 1; j++)
        { // for  StringGrid1 -> RowCount
            StringGrid1 -> Cells[i][j] = "";
        } // end for  StringGrid1 -> RowCount
    } // end for  StringGrid1 -> ColCount

    return true;
}


void __fastcall TNK_3Form::Create_StringGrid ()
{ // ������������ ������������ StringGrid-a

    q1 = DataModule1 -> Vozrast3NKFDQuery;
    // ��������� Query � ����������� �� ����������
    q1 -> Close ();
    q1 -> SQL -> Clear ();
    q1 -> SQL -> Add (sql_text + sql_group_by);
    q1 -> ParamByName ("FAC") -> AsSmallInt = nom_fac;
    q1 -> ParamByName ("EDU") -> AsSmallInt = RadioGroup1 -> ItemIndex;
    q1 -> Open ();
    int rec_z = q1 -> RecordCount;

    if (!rec_z || (rec_z == 1 && q1 -> FieldByName ("COUNT") -> Value == 0)) {
        ShowMessage ("��� ������ �� ��������� ���������");
        return;
    }

    StringGrid1 -> RowCount = rec_z + 2;
    if (CheckBox1 -> Checked) {
        StringGrid1 -> ColCount = 3;
        StringGrid1 -> Cells[2][0] = "���";
    }
    else
        StringGrid1 -> ColCount = 2;

    if (RadioGroup2 -> ItemIndex)
        StringGrid1 -> Cells[0][0] = "����";
    StringGrid1 -> ColWidths[1] = 64;
    StringGrid1 -> Cells[1][0] = "���-��";

    for (int k = 1; k <= rec_z; k++) { // for �� ���������� ������� � Query

        // ���� ������� ����� �� ������, �� ������� ����
        if (RadioGroup2 -> ItemIndex)
            StringGrid1 -> Cells[0][k] =
                AnsiString (q1 -> FieldByName ("KURS") -> AsString) + " ����";
        // ���� ������� ����� �� ����
        if (CheckBox1 -> Checked)
            StringGrid1 -> Cells[2][k] = q1 -> FieldByName ("POL") -> AsString;
        // ��������� ���������� ���������
        StringGrid1 -> Cells[1][k] =
            AnsiString (q1 -> FieldByName ("COUNT") -> AsString);
        q1 -> Next ();
    } // end for �� ���������� ������� � Query

    int sum = 0;
    // ������� ����� �� �������� �����
    for (int g = 1; g < StringGrid1 -> RowCount-1; g++) { // for �����
        sum += StrToInt (StringGrid1 -> Cells[1][g]);
    } // end for �����

    StringGrid1 -> Cells[0][StringGrid1 -> RowCount - 1] = "�����:";
    // ��������� ����� � ��������� ������
    StringGrid1 -> Cells[1][StringGrid1 -> RowCount - 1] = AnsiString (sum);

    // ���������� �����
    Form_Max ();

}


AnsiString TNK_3Form::Date_Diap (int let)
{ // ������� ���������� �������� ��� �������� �������� ���������
    // ���� ��������: and  people.data_r between '07.09.1987' and '06.09.1988'

    AnsiString r1 = ""; // ���� ����� sql
    AnsiString r2 = ""; // ������ ����
    // ����� ������� ���� �� ���������� let �����
    TDateTime d = IncYear (curent_date, -let);
    // ������ ����
    r2 = DateToStr (d);

    switch (let) { // switch �� ��������
    case 16: // 16 � ������
        d = IncYear (d, -1); // ����� ������� ���� �� ��� �����
        r1 = " and  p.data_r > '" + DateToStr (d) + "' ";
        break;
    case 60: // 60 � ������
        d += 1.0; // ����� ������� ���� �� ���� ���� ������
        r1 = " and  p.data_r < '" + DateToStr (d) + "' ";
        break;
    default: // 16-59
        d = IncYear (d, -1);
        d += 1.0;
        // d= IncMonth (d,-1); //����� ������� ���� �� ���� ����� �����
        r1 = " and  p.data_r between '" + DateToStr (d) + "' and '" +
            r2 + "' ";
        break;
    } // end switch �� ��������
    return r1; // ���������� ����� SQL
}


void __fastcall TNK_3Form::FormClose (TObject *Sender, TCloseAction &Action) {
    // �������� �����, ��� ���-�� ��� �������������� � ��������
    TRect r1, r2;
    r1 = Rect (Left + Width / 2, Top + Height / 2, Left + Width / 2,
        Top + Height / 2);
    r2 = BoundsRect;
    DrawAnimatedRects (Handle, IDANI_CAPTION, &r2, &r1);
    // �������� ������ ������������������ ��������� ����������

    Action = caFree;
}


void __fastcall TNK_3Form::BitBtn1Click (TObject *Sender)
{ // �������� �� ��������

    NK_3Form -> Caption = "������������� ��������� �� ��������";
    // �������� �����������   StringGrid
    if (!Clear_StringGrid ())
        return;
    ////////
    q1 = DataModule1 -> Vozrast3NKFDQuery;

    switch (RadioGroup2 -> ItemIndex) { // switch ����� �� ���������
    case 0: // �� ����������
        sql_text = "select count (*), pol from people  p  \
                     where p.n_fac=:FAC \
                     and   p.vid_edu=:EDU  \
                     and p.status_people in (1,3) ";
        sql_group_by = " group by  pol";
        break;
    case 1: // �� ������
        sql_text = "select count (*), pol, kurs from people  p  \
                     where p.n_fac=:FAC \
                     and   p.vid_edu=:EDU  \
                     and p.status_people in (1,3) ";
        sql_group_by = " group by  kurs, pol";
        break;
    } // end switch ����� �� ���������

    if (RadioGroup1 -> ItemIndex && RadioGroup2 -> ItemIndex)
    { // if ������� � �� ������
        StringGrid1 -> RowCount = 13;
        StringGrid1 -> Cells[0][11] = "6 ���� �";
        StringGrid1 -> Cells[0][12] = "6 ���� �";
    } // end if ������� � �� ������
    else { // else
        if (RadioGroup2 -> ItemIndex)
            StringGrid1 -> RowCount = 11; // �� ������
        else
            StringGrid1 -> RowCount = 3; // �� �����������
    } // end else

    StringGrid1 -> ColCount = 46;
    StringGrid1 -> Cells[45][0] = "�����";
    StringGrid1 -> ColWidths[1] = 64;

    if (RadioGroup2 -> ItemIndex) { // if �� ������
        for (int l = 10; l >= 2; l -= 2) {
            StringGrid1 -> Cells[0][l] = AnsiString (l / 2) + " ���� �";
        }
        for (int m = 9; m >= 1; m -= 2) {
            StringGrid1 -> Cells[0][m] = AnsiString (m / 2 + 1) + " ���� �";
        }
    } // end if �� ������
    else { // else �� �����������
        StringGrid1 -> Cells[0][1] = "�";
        StringGrid1 -> Cells[0][2] = "�";
    } // end else �� �����������

    for (int i = 16; i <= 60; i++) { // for ��� ������ ��������
        // ��������� Query � ����������� �� ����������
        q1 -> Close ();
        q1 -> SQL -> Clear ();
        q1 -> SQL -> Add (sql_text + Date_Diap (i) + sql_group_by);
        q1 -> ParamByName ("FAC") -> AsSmallInt = nom_fac;
        q1 -> ParamByName ("EDU") -> AsSmallInt = RadioGroup1 -> ItemIndex;
        q1 -> Open ();
        int rec_z = q1 -> RecordCount;
        switch (i) { // switch �������
        case 16:
            StringGrid1 -> Cells[i - 15][0] = AnsiString (i) + " � ������";
            break;
        case 60:
            StringGrid1 -> Cells[i - 15][0] = AnsiString (i) + " � ������";
            break;
        default:
            StringGrid1 -> Cells[i - 15][0] = AnsiString (i);
            break;
        } // end switch �������

        for (int k = 1; k <= rec_z; k++) { // for �� ���������� ������� � Query
            int col;
            if (RadioGroup2 -> ItemIndex) { // if �� ������
                col = q1 -> FieldByName ("KURS") -> AsInteger * 2;
                if (q1 -> FieldByName ("POL") -> AsString == "�")
                    col--;
            }
            else { // else �� �����������
                if (q1 -> FieldByName ("POL") -> AsString == "�")
                    col = 1;
                else
                    col = 2;
            }
            // ��������� ���������� ���������
            StringGrid1 -> Cells[i - 15][col] =
                AnsiString (q1 -> FieldByName ("COUNT") -> AsString);
            q1 -> Next ();
        } // end for �� ���������� ������� � Query
    } // end for ����� ��������

    // ������� ����� �� ������� �����
    for (int g = 1; g <= StringGrid1 -> RowCount - 1; g++) { // for �����
        int sum = 0;
        for (int t = 1; t < StringGrid1 -> ColCount - 1; t++)
        { // for �� ������� ����� ������
            if (!StringGrid1 -> Cells[t][g].IsEmpty ())
                sum += StrToInt (StringGrid1 -> Cells[t][g]);
        } // end for �� ������� ����� ������

        // ��������� ����� �� ����� ������
        StringGrid1 -> Cells[45][g] = AnsiString (sum);
    } // end for �����

    // ���������� �����
    Form_Max ();
}


void __fastcall TNK_3Form::RadioGroup2Click (TObject *Sender) {
    // ���������� �����
    if (NK_3Form -> Height > 120)
        Form_Min ();
}


void __fastcall TNK_3Form::FormCreate (TObject *Sender) {
    // ������� ����
    curent_date = cur_d ();

    // ��������� �����, ��� ���-�� ��� �������������� �� ��������
    TRect r1, r2;
    r1 = Rect (Left + Width / 2, Top + Height / 2, Left + Width / 2,
        Top + Height / 2);
    r2 = BoundsRect;
    DrawAnimatedRects (Handle, IDANI_CAPTION, &r1, &r2);
    // ��� ������� �� ������ ������������� �������?
    // SetWindowLong (BitBtn1 -> Handle,GWL_STYLE,GetWindowLong (Button1 -> Handle,GWL_STYLE)|BS_MULTILINE);
    // BitBtn1 -> Caption="a\nlot\nof\nstrings";

}


void __fastcall TNK_3Form::BitBtn2Click (TObject *Sender)
{ // �������� ������ � Excel
    str_grid (StringGrid1);
}


void __fastcall TNK_3Form::RadioGroup1Click (TObject *Sender) {
    // ���������� �����
    if (NK_3Form -> Height > 120)
        Form_Min ();
}


void __fastcall TNK_3Form::BitBtn3Click (TObject *Sender)
{ // �������� �� ��������������
    CheckBox1 -> Visible = true;

    if (CheckBox1 -> Checked)
        NK_3Form -> Caption = "������������� ��������� �� �������������� � ����";
    else
        NK_3Form -> Caption = "������������� ��������� �� ��������������";
    // �������� �����������   StringGrid
    if (!Clear_StringGrid ())
        return;
    ////////
    q1 = DataModule1 -> Vozrast3NKFDQuery;
    switch (RadioGroup2 -> ItemIndex) { // switch ����� �� ���������
    case 0: // �� ����������
        if (CheckBox1 -> Checked) { // if ������� � ������ ����
            sql_text = "select count (*), s.spec, s.code_spec, pol from people  p  \
                           inner join speciality s on (p.n_spec=s.n_spec) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people in (1,3) ";
            sql_group_by = " group by  s.spec, pol, s.code_spec";
        } // end if ������� � ������ ����
        else { // else �������� ����� �� ����
            sql_text = "select count (*), s.spec, s.code_spec from people  p  \
                           inner join speciality s on (p.n_spec=s.n_spec) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people in (1,3) ";
            sql_group_by = " group by  s.spec, s.code_spec";
        } // end else �������� ����� �� ����
        break;
    case 1: // �� ������
        if (CheckBox1 -> Checked) { // if ������� � ������ ����
            sql_text = "select count (*), s.spec, kurs, pol from people  p  \
                           inner join speciality s on (p.n_spec=s.n_spec) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people in (1,3) ";
            sql_group_by = " group by  kurs, s.spec, pol";
        } // end if ������� � ������ ����
        else { // else �������� ����� �� ����
            sql_text = "select count (*), s.spec, kurs from people  p  \
                           inner join speciality s on (p.n_spec=s.n_spec) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people in (1,3) ";
            sql_group_by = " group by  kurs, s.spec";
        } // end else �������� ����� �� ����
        break;
    } // end switch ����� �� ���������

    // ��������� Query � ����������� �� ����������
    q1 -> Close ();
    q1 -> SQL -> Clear ();
    q1 -> SQL -> Add (sql_text + sql_group_by);
    q1 -> ParamByName ("FAC") -> AsSmallInt = nom_fac;
    q1 -> ParamByName ("EDU") -> AsSmallInt = RadioGroup1 -> ItemIndex;
    q1 -> Open ();
    int rec_z = q1 -> RecordCount;

    StringGrid1 -> RowCount = rec_z + 2;
    if (CheckBox1 -> Checked) {
        StringGrid1 -> ColCount = 4;
        StringGrid1 -> Cells[3][0] = "���";
    }
    else
        StringGrid1 -> ColCount = 3;

    if (RadioGroup2 -> ItemIndex)
        StringGrid1 -> Cells[0][0] = "����";
    else
        StringGrid1 -> Cells[0][0] = "���";
    StringGrid1 -> Cells[1][0] = "�������������";
    StringGrid1 -> ColWidths[1] = 230;
    StringGrid1 -> Cells[2][0] = "���-��";

    for (int k = 1; k <= rec_z; k++) { // for �� ���������� ������� � Query

        // ���� ������� ����� �� ������, �� ������� ����
        if (RadioGroup2 -> ItemIndex)
            StringGrid1 -> Cells[0][k] =
                AnsiString (q1 -> FieldByName ("KURS") -> AsString) + " ����";
        else
            StringGrid1 -> Cells[0][k] = q1 -> FieldByName ("CODE_SPEC") -> AsString;
        // ���� ������� ����� �� ����
        if (CheckBox1 -> Checked)
            StringGrid1 -> Cells[3][k] = q1 -> FieldByName ("POL") -> AsString;
        // ��������� ����������� �������������
        StringGrid1 -> Cells[1][k] = q1 -> FieldByName ("SPEC") -> AsString;

        // ��������� ���������� ���������
        StringGrid1 -> Cells[2][k] =
            AnsiString (q1 -> FieldByName ("COUNT") -> AsString);
        q1 -> Next ();
    } // end for �� ���������� ������� � Query

    int sum = 0;
    // ������� ����� �� �������� �����
    for (int g = 1; g < StringGrid1 -> RowCount - 1; g++) { // for �����
        sum += StrToInt (StringGrid1 -> Cells[2][g]);
    } // end for �����

    StringGrid1 -> Cells[1][StringGrid1 -> RowCount - 1] = "�����:";
    // ��������� ����� � ��������� ������
    StringGrid1 -> Cells[2][StringGrid1 -> RowCount - 1] = AnsiString (sum);

    // ���������� �����
    Form_Max ();
}


void __fastcall TNK_3Form::CheckBox1Click (TObject *Sender) {
    // � ������ ������ ����
    if (NK_3Form -> Caption == "������������� ��������� �� ��������������" ||
        NK_3Form -> Caption == "������������� ��������� �� �������������� � ����")
        BitBtn3Click (this);

    if (NK_3Form -> Caption == "������������� ��������� �� ����� ������" ||
        NK_3Form -> Caption == "������������� ��������� �� ����� ������ � ����")
        BitBtn4Click (this);

    if (NK_3Form -> Caption == "������������� ����������� �� ��������������" ||
        NK_3Form -> Caption ==
        "������������� ����������� �� �������������� � ����")
        BitBtn5Click (this);

    if (NK_3Form -> Caption == "�� �������� ������� ����������" ||
        NK_3Form -> Caption == "�� �������� ������� ���������� � ������ ����")
        BitBtn6Click (this);

    if (NK_3Form -> Caption == "�� ������������ ����� ��������" ||
        NK_3Form -> Caption == "�� ������������ ����� �������� � ������ ����")
        BitBtn7Click (this);

    if (NK_3Form -> Caption ==
        "������������� ��������� �� ������������ ��������������" ||
        NK_3Form -> Caption ==
        "������������� ��������� �� ������������ �������������� � ����")
        BitBtn8Click (this);

}


void __fastcall TNK_3Form::BitBtn4Click (TObject *Sender)
{ // �������� �� ����� ������
    CheckBox1 -> Visible = true;

    if (CheckBox1 -> Checked)
        NK_3Form -> Caption = "������������� ��������� �� ����� ������ � ����";
    else
        NK_3Form -> Caption = "������������� ��������� �� ����� ������";

    // �������� �����������   StringGrid
    if (!Clear_StringGrid ())
        return;
    ////////
    q1 = DataModule1 -> Vozrast3NKFDQuery;

    switch (RadioGroup2 -> ItemIndex) { // switch ����� �� ���������
    case 0: // �� ����������
        if (CheckBox1 -> Checked) { // if ������� � ������ ����
            sql_text = "select count (*), f.vid_found, pol from people  p  \
                           inner join foundation f on (p.n_found=f.n_found) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people in (1,3) ";
            sql_group_by = " group by  f.vid_found, pol";
        } // end if ������� � ������ ����
        else { // else �������� ����� �� ����
            sql_text = "select count (*), f.vid_found from people  p  \
                           inner join foundation f on (p.n_found=f.n_found) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people in (1,3) ";
            sql_group_by = " group by  f.vid_found";
        } // end else �������� ����� �� ����
        break;
    case 1: // �� ������
        if (CheckBox1 -> Checked) { // if ������� � ������ ����
            sql_text = "select count (*), kurs, f.vid_found, pol from people  p  \
                           inner join foundation f on (p.n_found=f.n_found) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people in (1,3) ";
            sql_group_by = " group by  kurs, f.vid_found, pol";
        } // end if ������� � ������ ����
        else { // else �������� ����� �� ����
            sql_text = "select count (*), kurs, f.vid_found  from people  p  \
                           inner join foundation f on (p.n_found=f.n_found) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people in (1,3) ";
            sql_group_by = " group by  kurs, f.vid_found";
        } // end else �������� ����� �� ����
        break;
    } // end switch ����� �� ���������

    // ��������� Query � ����������� �� ����������
    q1 -> Close ();
    q1 -> SQL -> Clear ();
    q1 -> SQL -> Add (sql_text + sql_group_by);
    q1 -> ParamByName ("FAC") -> AsSmallInt = nom_fac;
    q1 -> ParamByName ("EDU") -> AsSmallInt = RadioGroup1 -> ItemIndex;
    q1 -> Open ();
    int rec_z = q1 -> RecordCount;

    StringGrid1 -> RowCount = rec_z + 2;
    if (CheckBox1 -> Checked) {
        StringGrid1 -> ColCount = 4;
        StringGrid1 -> Cells[3][0] = "���";
    }
    else
        StringGrid1 -> ColCount = 3;

    if (RadioGroup2 -> ItemIndex)
        StringGrid1 -> Cells[0][0] = "����";
    StringGrid1 -> Cells[1][0] = "�����";
    StringGrid1 -> ColWidths[1] = 64;
    StringGrid1 -> Cells[2][0] = "���-��";

    for (int k = 1; k <= rec_z; k++) { // for �� ���������� ������� � Query

        // ���� ������� ����� �� ������, �� ������� ����
        if (RadioGroup2 -> ItemIndex)
            StringGrid1 -> Cells[0][k] =
                AnsiString (q1 -> FieldByName ("KURS") -> AsString) + " ����";
        // ���� ������� ����� �� ����
        if (CheckBox1 -> Checked)
            StringGrid1 -> Cells[3][k] = q1 -> FieldByName ("POL") -> AsString;
        // ��������� ����� ������
        StringGrid1 -> Cells[1][k] = q1 -> FieldByName ("VID_FOUND") -> AsString;

        // ��������� ���������� ���������
        StringGrid1 -> Cells[2][k] =
            AnsiString (q1 -> FieldByName ("COUNT") -> AsString);
        q1 -> Next ();
    } // end for �� ���������� ������� � Query

    int sum = 0;
    // ������� ����� �� �������� �����
    for (int g = 1; g < StringGrid1 -> RowCount - 1; g++) { // for �����
        sum += StrToInt (StringGrid1 -> Cells[2][g]);
    } // end for �����

    StringGrid1 -> Cells[1][StringGrid1 -> RowCount - 1] = "�����:";
    // ��������� ����� � ��������� ������
    StringGrid1 -> Cells[2][StringGrid1 -> RowCount - 1] = AnsiString (sum);

    // ���������� �����
    Form_Max ();

}


void __fastcall TNK_3Form::BitBtn5Click (TObject *Sender)
{ // �������� �� �����������
    CheckBox1 -> Visible = true;

    if (CheckBox1 -> Checked)
        NK_3Form -> Caption =
            "������������� ����������� �� �������������� � ����";
    else
        NK_3Form -> Caption = "������������� ����������� �� ��������������";

    // �������� �����������   StringGrid
    if (!Clear_StringGrid ())
        return;
    ////////
    q1 = DataModule1 -> Vozrast3NKFDQuery;
    // ------
    switch (RadioGroup2 -> ItemIndex) { // switch ����� �� ���������
    case 0: // �� ����������
        if (CheckBox1 -> Checked) { // if ������� � ������ ����
            sql_text = "select count (*), s.spec, pol, s.code_spec from people  p  \
                           inner join speciality s on (p.n_spec=s.n_spec) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people=6 \
                           and p.D_PRIKAZ_KURS like '%" +
                AnsiString (uch_god) + "' ";
            sql_group_by = " group by  s.spec, pol, s.code_spec";
        } // end if ������� � ������ ����
        else { // else �������� ����� �� ����
            sql_text = "select count (*), s.spec, s.code_spec from people  p  \
                           inner join speciality s on (p.n_spec=s.n_spec) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people=6 \
                           and p.D_PRIKAZ_KURS like '%" +
                AnsiString (uch_god) + "' ";
            sql_group_by = " group by  s.spec, s.code_spec";
        } // end else �������� ����� �� ����
        break;
    case 1: // �� ������
        if (CheckBox1 -> Checked) { // if ������� � ������ ����
            sql_text = "select count (*), s.spec, kurs, pol from people  p  \
                           inner join speciality s on (p.n_spec=s.n_spec) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people=6 \
                           and p.D_PRIKAZ_KURS like '%" +
                AnsiString (uch_god) + "' ";
            sql_group_by = " group by  kurs, s.spec, pol";
        } // end if ������� � ������ ����
        else { // else �������� ����� �� ����
            sql_text = "select count (*), s.spec, kurs from people  p  \
                           inner join speciality s on (p.n_spec=s.n_spec) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people=6 \
                           and p.D_PRIKAZ_KURS like '%" +
                AnsiString (uch_god) + "' ";
            sql_group_by = " group by  kurs, s.spec";
        } // end else �������� ����� �� ����
        break;
    } // end switch ����� �� ���������

    // ��������� Query � ����������� �� ����������
    q1 -> Close ();
    q1 -> SQL -> Clear ();
    q1 -> SQL -> Add (sql_text + sql_group_by);
    q1 -> ParamByName ("FAC") -> AsSmallInt = nom_fac;
    q1 -> ParamByName ("EDU") -> AsSmallInt = RadioGroup1 -> ItemIndex;
    q1 -> Open ();
    int rec_z = q1 -> RecordCount;

    StringGrid1 -> RowCount = rec_z + 2;
    if (CheckBox1 -> Checked) {
        StringGrid1 -> ColCount = 4;
        StringGrid1 -> Cells[3][0] = "���";
    }
    else
        StringGrid1 -> ColCount = 3;

    if (RadioGroup2 -> ItemIndex)
        StringGrid1 -> Cells[0][0] = "����";
    else
        StringGrid1 -> Cells[0][0] = "���";
    StringGrid1 -> Cells[1][0] = "�������������";
    StringGrid1 -> ColWidths[1] = 230;
    StringGrid1 -> Cells[2][0] = AnsiString (uch_god) + "-������";

    for (int k = 1; k <= rec_z; k++) { // for �� ���������� ������� � Query

        // ���� ������� ����� �� ������, �� ������� ����
        if (RadioGroup2 -> ItemIndex)
            StringGrid1 -> Cells[0][k] =
                AnsiString (q1 -> FieldByName ("KURS") -> AsString) + " ����";
        else
            StringGrid1 -> Cells[0][k] = q1 -> FieldByName ("CODE_SPEC") -> AsString;
        // ���� ������� ����� �� ����
        if (CheckBox1 -> Checked)
            StringGrid1 -> Cells[3][k] = q1 -> FieldByName ("POL") -> AsString;
        // ��������� ����������� �������������
        StringGrid1 -> Cells[1][k] = q1 -> FieldByName ("SPEC") -> AsString;

        // ��������� ���������� ���������
        StringGrid1 -> Cells[2][k] =
            AnsiString (q1 -> FieldByName ("COUNT") -> AsString);
        q1 -> Next ();
    } // end for �� ���������� ������� � Query

    int sum = 0;
    // ������� ����� �� �������� �����
    for (int g = 1; g < StringGrid1 -> RowCount - 1; g++) { // for �����
        sum += StrToInt (StringGrid1 -> Cells[2][g]);
    } // end for �����

    StringGrid1 -> Cells[1][StringGrid1 -> RowCount - 1] = "�����:";
    // ��������� ����� � ��������� ������
    StringGrid1 -> Cells[2][StringGrid1 -> RowCount - 1] = AnsiString (sum);

    // ���������� �����
    Form_Max ();
}


void __fastcall TNK_3Form::BitBtn6Click (TObject *Sender)
{ // �������� �� �������� ������� ����������
    CheckBox1 -> Visible = true;

    if (CheckBox1 -> Checked)
        NK_3Form -> Caption = "�� �������� ������� ���������� � ������ ����";
    else
        NK_3Form -> Caption = "�� �������� ������� ����������";

    // �������� �����������   StringGrid
    if (!Clear_StringGrid ())
        return;

    // ------
    switch (RadioGroup2 -> ItemIndex) { // switch ����� �� ���������
    case 0: // �� ����������
        if (CheckBox1 -> Checked) { // if ������� � ������ ����
            sql_text = "select count (*), pol from people  p  \
                           INNER JOIN CK  ON (P.NOMER = CK.NOMER) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people=1 \
                           and p.n_found_include=1 \
                           and p.n_found=6 \
                           and p.n_specializ=ck.n_specializ  \
                           and CK.STATUS_CK=0 ";
            sql_group_by = " group by  pol";
        } // end if ������� � ������ ����
        else { // else �������� ����� �� ����
            sql_text = "select count (*) from people  p  \
                           INNER JOIN CK  ON (P.NOMER = CK.NOMER) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people=1 \
                           and p.n_found_include=1 \
                           and p.n_found=6 \
                           and p.n_specializ=ck.n_specializ  \
                           and CK.STATUS_CK=0 ";
            sql_group_by = " ";
        } // end else �������� ����� �� ����
        break;
    case 1: // �� ������
        if (CheckBox1 -> Checked) { // if ������� � ������ ����
            sql_text = "select count (*), kurs, pol from people  p  \
                           INNER JOIN CK  ON (P.NOMER = CK.NOMER) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people=1 \
                           and p.n_found_include=1 \
                           and p.n_found=6 \
                           and p.n_specializ=ck.n_specializ  \
                           and CK.STATUS_CK=0 ";
            sql_group_by = " group by  kurs, pol";
        } // end if ������� � ������ ����
        else { // else �������� ����� �� ����
            sql_text = "select count (*), kurs from people  p  \
                           INNER JOIN CK  ON (P.NOMER = CK.NOMER) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people=1 \
                           and p.n_found_include=1 \
                           and p.n_found=6 \
                           and p.n_specializ=ck.n_specializ  \
                           and CK.STATUS_CK=0 ";
            sql_group_by = " group by  kurs";
        } // end else �������� ����� �� ����
        break;
    } // end switch ����� �� ���������
    Create_StringGrid ();
}


void __fastcall TNK_3Form::BitBtn7Click (TObject *Sender)
{ // �������� �� ������������ ����� ��������
    CheckBox1 -> Visible = true;

    if (CheckBox1 -> Checked)
        NK_3Form -> Caption = "�� ������������ ����� �������� � ������ ����";
    else
        NK_3Form -> Caption = "�� ������������ ����� ��������";

    // �������� �����������   StringGrid
    if (!Clear_StringGrid ())
        return;

    // ------
    switch (RadioGroup2 -> ItemIndex) { // switch ����� �� ���������
    case 0: // �� ����������
        if (CheckBox1 -> Checked) { // if ������� � ������ ����
            sql_text =
                "select count (*), pol from people  p  \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people=1 \
                           and p.vid_edu=p.vid_edu_include  \
                           and not exists (select res.nomer   from restore  res where res.nomer=p.nomer)  \
                           and  not exists (select  h.nomer   from  holiday h   where h.nomer=p.nomer)  \
                           and (p.n_found_include in (3,10,12,13,14,15) or p.n_found in (3,10,12,13,14,15))";
            sql_group_by = " group by  pol";
        } // end if ������� � ������ ����
        else { // else �������� ����� �� ����
            sql_text =
                "select count (*) from people  p  \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people=1 \
                           and p.vid_edu=p.vid_edu_include  \
                           and not exists (select res.nomer   from restore  res where res.nomer=p.nomer)  \
                           and  not exists (select  h.nomer   from  holiday h   where h.nomer=p.nomer) \
                           and (p.n_found_include in (3,10,12,13,14,15) or p.n_found in (3,10,12,13,14,15))";
            sql_group_by = " ";
        } // end else �������� ����� �� ����
        break;
    case 1: // �� ������
        if (CheckBox1 -> Checked) { // if ������� � ������ ����
            sql_text =
                "select count (*), kurs, pol from people  p  \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people=1 \
                           and p.vid_edu=p.vid_edu_include  \
                           and not exists (select res.nomer   from restore  res where res.nomer=p.nomer)  \
                           and  not exists (select  h.nomer   from  holiday h   where h.nomer=p.nomer)  \
                           and (p.n_found_include in (3,10,12,13,14,15) or p.n_found in (3,10,12,13,14,15))";
            sql_group_by = " group by  kurs, pol";
        } // end if ������� � ������ ����
        else { // else �������� ����� �� ����
            sql_text =
                "select count (*), kurs from people  p  \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people=1 \
                           and p.vid_edu=p.vid_edu_include  \
                           and not exists (select res.nomer   from restore  res where res.nomer=p.nomer)  \
                           and  not exists (select  h.nomer   from  holiday h   where h.nomer=p.nomer)  \
                           and (p.n_found_include in (3,10,12,13,14,15) or p.n_found in (3,10,12,13,14,15))";
            sql_group_by = " group by  kurs";
        } // end else �������� ����� �� ����
        break;
    } // end switch ����� �� ���������

    Create_StringGrid ();

}


void __fastcall TNK_3Form::BitBtn8Click (TObject *Sender)
{ // �������� �� ������������ ��������������
    CheckBox1 -> Visible = true;

    if (CheckBox1 -> Checked)
        NK_3Form -> Caption =
            "������������� ��������� �� ������������ �������������� � ����";
    else
        NK_3Form -> Caption =
            "������������� ��������� �� ������������ ��������������";
    // �������� �����������   StringGrid
    if (!Clear_StringGrid ())
        return;
    ////////
    q1 = DataModule1 -> Vozrast3NKFDQuery;
    switch (RadioGroup2 -> ItemIndex) { // switch ����� �� ���������
    case 0: // �� ����������
        if (CheckBox1 -> Checked) { // if ������� � ������ ����
            sql_text = "select count (*), s_p.spec_dir_full, s_p.code_spec_dir, pol from people  p  \
                           inner join specializ s on (p.n_specializ=s.n_specializ) \
                           inner join special_direction s_p on (s_p.n_spec_dir=s.n_spec_dir) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people in (1,3) ";
            sql_group_by =
                " group by  s_p.code_spec_dir, s_p.spec_dir_full, pol";
        } // end if ������� � ������ ����
        else { // else �������� ����� �� ����
            sql_text = "select count (*), s_p.spec_dir_full, s_p.code_spec_dir from people  p  \
                           inner join specializ s on (p.n_specializ=s.n_specializ) \
                           inner join special_direction s_p on (s_p.n_spec_dir=s.n_spec_dir) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people in (1,3) ";
            sql_group_by = " group by  s_p.code_spec_dir, s_p.spec_dir_full";
        } // end else �������� ����� �� ����
        break;
    case 1: // �� ������
        if (CheckBox1 -> Checked) { // if ������� � ������ ����
            sql_text = "select count (*), s_p.spec_dir_full, kurs, pol from people  p  \
                           inner join specializ s on (p.n_specializ=s.n_specializ) \
                           inner join special_direction s_p on (s_p.n_spec_dir=s.n_spec_dir) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people in (1,3) ";
            sql_group_by = " group by  kurs, s_p.spec_dir_full, pol";
        } // end if ������� � ������ ����
        else { // else �������� ����� �� ����
            sql_text = "select count (*), s_p.spec_dir_full, kurs from people  p  \
                           inner join specializ s on (p.n_specializ=s.n_specializ) \
                           inner join special_direction s_p on (s_p.n_spec_dir=s.n_spec_dir) \
                           where p.n_fac=:FAC \
                           and   p.vid_edu=:EDU  \
                           and p.status_people in (1,3) ";
            sql_group_by = " group by  kurs, s_p.spec_dir_full";
        } // end else �������� ����� �� ����
        break;
    } // end switch ����� �� ���������

    // ��������� Query � ����������� �� ����������
    q1 -> Close ();
    q1 -> SQL -> Clear ();
    q1 -> SQL -> Add (sql_text + sql_group_by);
    q1 -> ParamByName ("FAC") -> AsSmallInt = nom_fac;
    q1 -> ParamByName ("EDU") -> AsSmallInt = RadioGroup1 -> ItemIndex;
    q1 -> Open ();
    int rec_z = q1 -> RecordCount;

    StringGrid1 -> RowCount = rec_z + 2;
    if (CheckBox1 -> Checked) {
        StringGrid1 -> ColCount = 4;
        StringGrid1 -> Cells[3][0] = "���";
    }
    else
        StringGrid1 -> ColCount = 3;

    if (RadioGroup2 -> ItemIndex)
        StringGrid1 -> Cells[0][0] = "����";
    else
        StringGrid1 -> Cells[0][0] = "���";
    StringGrid1 -> Cells[1][0] = "����������� �������������";
    StringGrid1 -> ColWidths[1] = 430;
    StringGrid1 -> Cells[2][0] = "���-��";

    for (int k = 1; k <= rec_z; k++) { // for �� ���������� ������� � Query

        // ���� ������� ����� �� ������, �� ������� ����
        if (RadioGroup2 -> ItemIndex)
            StringGrid1 -> Cells[0][k] =
                AnsiString (q1 -> FieldByName ("KURS") -> AsString) + " ����";
        else
            StringGrid1 -> Cells[0][k] =
                q1 -> FieldByName ("CODE_SPEC_DIR") -> AsString;
        // ���� ������� ����� �� ����
        if (CheckBox1 -> Checked)
            StringGrid1 -> Cells[3][k] = q1 -> FieldByName ("POL") -> AsString;
        // ��������� ����������� �������������
        StringGrid1 -> Cells[1][k] = q1 -> FieldByName ("SPEC_DIR_FULL") -> AsString;

        // ��������� ���������� ���������
        StringGrid1 -> Cells[2][k] =
            AnsiString (q1 -> FieldByName ("COUNT") -> AsString);
        q1 -> Next ();
    } // end for �� ���������� ������� � Query

    int sum = 0;
    // ������� ����� �� �������� �����
    for (int g = 1; g < StringGrid1 -> RowCount - 1; g++) { // for �����
        sum += StrToInt (StringGrid1 -> Cells[2][g]);
    } // end for �����

    StringGrid1 -> Cells[1][StringGrid1 -> RowCount - 1] = "�����:";
    // ��������� ����� � ��������� ������
    StringGrid1 -> Cells[2][StringGrid1 -> RowCount - 1] = AnsiString (sum);

    // ���������� �����
    Form_Max ();
}

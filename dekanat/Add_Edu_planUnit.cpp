#include <vcl.h>
#pragma hdrstop


#include "Add_Edu_planUnit.h"
#include "DataModule_Card.h"
#include "DataModule.h"
#include "DM2Unit.h"
#include "DualList.h"
#include "Edu_planUnit.h"


#pragma package (smart_init)
// #pragma link     "MyList"
#pragma resource "*.dfm"


TAdd_Edu_planForm * Add_Edu_planForm;


int n_plan = 0;                                                                 // инкремент учебного плана, получаемый процедурой



__fastcall TAdd_Edu_planForm::TAdd_Edu_planForm (TComponent * Owner)
    : TForm (Owner)
{ }



void __fastcall TAdd_Edu_planForm::BitBtn1Click (TObject * Sender)
{
    int k = 0;
                                                                                // ПРОВЕРКИ НА ВВОД ВСЕХ ДАННЫХ
    if (ComboBox2 -> Text == "")                                                // проверка наличия "Вида обучения"
    {
        ShowMessage (
            "Введите вид обучения!"
        );

        Add_Edu_planForm -> ModalResult = 0;
        
        ComboBox2 -> SetFocus ();

        return;
    }


    if (DBLookupComboBox1 -> Text == "")                                        // проверка наличия "Названия предмета"
    {
        ShowMessage (
            "Введите название предмета!"
        );

        Add_Edu_planForm  -> ModalResult = 0;

        DBLookupComboBox1 -> SetFocus ();

        return;
    }


    if (Edit1 -> Text == "")                                                    // проверка наличия "Семестр"
    {
        ShowMessage (
            "Введите cеместр!"
        );

        Add_Edu_planForm -> ModalResult = 0;

        Edit1 -> SetFocus ();

        return;
    }

    try                                                                         // проверка на ввод числового значения
    {
        StrToInt (Edit1 -> Text);
    }
    catch (...)                                                                 // ошибка ввода числа
    {
        ShowMessage (
            "Значение в cеместре должно быть числовым!"
        );

        Add_Edu_planForm -> ModalResult = 0;

        Edit1 -> SetFocus ();

        return;
    }


    if (Edit2 -> Text == "")                                                    // проверка наличия "Часов в семестре аудиторных"
    {
        ShowMessage (
            "Введите количество аудиторных часов в cеместре!"
        );

        Add_Edu_planForm -> ModalResult = 0;

        Edit2 -> SetFocus ();

        return;
    }

    if (Edit3 -> Text == "")                                                    // проверка наличия "Часов в семестре всего"
    {
        ShowMessage (
            "Введите общее количество часов в cеместре!"
        );

        Add_Edu_planForm -> ModalResult = 0;

        Edit3 -> SetFocus ();

        return;
    }


    if (ComboBox1 -> Text == "")                                                // проверка наличия "Вид контроля"
    {
        ShowMessage (
            "Введите вид контроля!"
        );

        Add_Edu_planForm -> ModalResult = 0;

        ComboBox1 -> SetFocus ();

        return;
    }

    if (MaskEdit1 -> Text == "20  ")                                            // проверка наличия "Учебный год"
    {
        ShowMessage (
            "Введите учебный год!"
        );

        Add_Edu_planForm -> ModalResult = 0;

        MaskEdit1 -> SetFocus ();

        return;
    }

    if (MaskEdit2 -> Text == "20  ")                                            // проверка наличия "Учебный год"
    {
        ShowMessage (
            "Введите учебный год!"
        );

        Add_Edu_planForm -> ModalResult = 0;

        MaskEdit2 -> SetFocus ();

        return;
    }

    if (    ComboBox2 -> ItemIndex                                              // проверяем, правильно ли указан семестр (Для заочного)
         && (    StrToInt (Edit1 -> Text) < 1
              || StrToInt (Edit1 -> Text) > 12
            )
       )
    {
        ShowMessage (
            "Значение в Семестре для заочного обучения должно быть в диапазоне от 1 до 12!"
        );

        Add_Edu_planForm -> ModalResult = 0;

        Edit1 -> SetFocus ();

        return;
    }


    if (    ! ComboBox2 -> ItemIndex                                            // проверяем, правильно ли указан семестр (Для дневного)
         && (    StrToInt (Edit1 -> Text) < 1
              || StrToInt (Edit1 -> Text) > 10
            )
       )
    {
        ShowMessage (
            "Значение в Семестре для дневного обучения должно быть в диапазоне от 1 до 10!"
        );

        Add_Edu_planForm -> ModalResult = 0;

        Edit1 -> SetFocus ();

        return;
    }


    if (    Add_Edu_planForm -> Caption                                         // ОСНОВНОЙ БЛОК
         == "Добавление предмета в учебный план"                                // режим добавления новой записи
       )
    {
        FDQuery1 -> SQL -> Text = "\
            SELECT                                              \
                COUNT (*)                                       \
            FROM                                                \
                edu_plan                                        \
            WHERE                                               \
                    n_object     = "                            +
                        DBLookupComboBox1 -> KeyValue           +
                    "                                           \
                AND                                             \
                    semestr      = "                            +
                        Edit1 -> Text                           +
                    "                                           \
                AND                                             \
                    year_plan    = "                            +
                        MaskEdit1 -> Text                       +
                    "                                           \
                AND                                             \
                    vid_edu_plan = "                            +
                       (IntToStr) (ComboBox2 -> ItemIndex)     +
                    "                                           \
                AND                                             \
                    n_fac        = "                            +
                       (IntToStr) (nom_fac);

        FDQuery1 -> Open ();

        k = FDQuery1COUNT -> Value;

        FDQuery1 -> Close ();

        DataModule1 -> Edu_PlanFDQuery -> Insert ();

        DataModule1 -> Edu_PlanFDQueryN_FAC -> Value = nom_fac;

        if ( ! n_plan)                                                          // если не сработала процедура по добавлению инкремента
            n_plan = DataModule1 -> vozvrat_inc_edu_plan ();

        DataModule1 -> Edu_PlanFDQueryN_PLAN -> Value = n_plan;
    }
    else                                                                        // режим редактирования
        DataModule1 -> Edu_PlanFDQuery -> Edit ();


    DataModule1 -> Edu_PlanFDQueryN_OBJECT       -> Value =
        DBLookupComboBox1 -> KeyValue;

    DataModule1 -> Edu_PlanFDQuerySEMESTR        -> Value =
        StrToInt  (Edit1 -> Text);

    DataModule1 -> Edu_PlanFDQueryCLOCK_PLAN     -> Value =
        StrToFloat (Edit2 -> Text);

    DataModule1 -> Edu_PlanFDQueryCLOCK_PLAN_ALL -> Value =
        StrToInt  (Edit3 -> Text);

    DataModule1 -> Edu_PlanFDQueryYEAR_PLAN      -> Value =
        MaskEdit1 -> Text.ToInt ();

    DataModule1 -> Edu_PlanFDQueryZACH_EXAM      -> Value =
        ComboBox1 -> ItemIndex;

    DataModule1 -> Edu_PlanFDQueryVID_EDU_PLAN   -> Value =
        ComboBox2 -> ItemIndex;


    // if (CheckBox1 -> Checked)                                                   // сохранение спецкурса
    //     DataModule1 -> Edu_PlanQuerySPECKURS -> Value = 1;
    // else
    //     DataModule1 -> Edu_PlanQuerySPECKURS -> Value = 0;


    if (CheckBox1 -> Checked)
        DataModule1 -> Edu_PlanFDQueryTYPE_PLAN -> Value = 1;
    else
        DataModule1 -> Edu_PlanFDQueryTYPE_PLAN -> Value = 0;


    DataModule1 -> Edu_PlanFDQuerySPECKURS -> Value =
        RadioGroup2 -> ItemIndex;


    if (CheckBox2 -> Checked)                                                   // сохранение значения в случае последнего вида контроля
        DataModule1 -> Edu_PlanFDQuerySTATUS_CONTROL -> Value = 1;
    else
        DataModule1 -> Edu_PlanFDQuerySTATUS_CONTROL -> Value = 0;


    if (CheckBox1 -> Checked)
    {
        DataModule1 -> Sub_Edu_PlanFDQuery -> Active = True;

        if (    Add_Edu_planForm -> Caption
             == "Добавление предмета в учебный план"
           )
        {
            DataModule1 -> Sub_Edu_PlanFDQuery -> Insert ();

            DataModule1 -> Sub_Edu_PlanFDQueryN_OBJECT        -> Value =
                DBLookupComboBox3 -> KeyValue;

            DataModule1 -> Sub_Edu_PlanFDQueryN_PLAN_PARENT   -> Value =
                DataModule1       -> Edu_PlanFDQueryN_PLAN -> Value;

            DataModule1 -> Sub_Edu_PlanFDQueryPERC_SUB_PLAN   -> Value =
                StrToFloat (Edit4  -> Text);

            DataModule1 -> Sub_Edu_PlanFDQueryCLASSROOM_HOURS -> Value =
                StrToInt   (Edit6  -> Text);

            DataModule1 -> Sub_Edu_PlanFDQueryLECTURE_HOURS   -> Value =
                StrToInt   (Edit8  -> Text);

            DataModule1 -> Sub_Edu_PlanFDQuerySEMINAR_HOURS   -> Value =
                StrToInt   (Edit10 -> Text);

            DataModule1 -> Sub_Edu_PlanFDQueryCLOCK_PLAN      -> Value =
                StrToInt   (Edit12 -> Text);

            DataModule1 -> Sub_Edu_PlanFDQueryIND_NUMB        -> Value =
                1;

            try
            {
                FDQuery2 -> Active = False;

                DataModule1 -> Sub_Edu_PlanFDQuery -> ApplyUpdates ();
                DataModule1 -> Sub_Edu_PlanFDQuery -> CommitUpdates ();
            }
            catch (...)
            {
                DataModule1 -> Sub_Edu_PlanFDQuery -> CancelUpdates ();

                ShowMessage (
                    "Произошел сбой попробуйте еще раз!"
                );
            }
        }
        else
        {
            FDQuery2 -> Active = True;
            FDQuery2 -> Edit ();

            FDQuery2N_OBJECT        -> Value = DBLookupComboBox3 -> KeyValue;

            FDQuery2PERC_SUB_PLAN   -> Value = StrToFloat (Edit4  -> Text);
            FDQuery2CLASSROOM_HOURS -> Value = StrToInt  (Edit6  -> Text);
            FDQuery2LECTURE_HOURS   -> Value = StrToInt  (Edit8  -> Text);
            FDQuery2SEMINAR_HOURS   -> Value = StrToInt  (Edit10 -> Text);
            FDQuery2CLOCK_PLAN      -> Value = StrToInt  (Edit12 -> Text);

            try
            {
                FDQuery2 -> ApplyUpdates ();
                FDQuery2 -> CommitUpdates ();
            }
            catch (...)
            {
                FDQuery2 -> CancelUpdates ();

                ShowMessage (
                    "Произошел сбой попробуйте еще раз!"
                );
            }
        }

        if (    Add_Edu_planForm -> Caption
             == "Добавление предмета в учебный план"
           )
        {
            DataModule1 -> Sub_Edu_PlanFDQuery -> Insert ();

            DataModule1 -> Sub_Edu_PlanFDQueryN_OBJECT        -> Value =
                DBLookupComboBox4 -> KeyValue;

            DataModule1 -> Sub_Edu_PlanFDQueryN_PLAN_PARENT   -> Value =
                DataModule1       -> Edu_PlanFDQueryN_PLAN -> Value;

            DataModule1 -> Sub_Edu_PlanFDQueryPERC_SUB_PLAN   -> Value =
                StrToFloat (Edit5  -> Text);

            DataModule1 -> Sub_Edu_PlanFDQueryCLASSROOM_HOURS -> Value =
                StrToInt   (Edit7  -> Text);

            DataModule1 -> Sub_Edu_PlanFDQueryLECTURE_HOURS   -> Value =
                StrToInt   (Edit9  -> Text);

            DataModule1 -> Sub_Edu_PlanFDQuerySEMINAR_HOURS   -> Value =
                StrToInt   (Edit11 -> Text);

            DataModule1 -> Sub_Edu_PlanFDQueryCLOCK_PLAN      -> Value =
                StrToInt   (Edit13 -> Text);

            DataModule1 -> Sub_Edu_PlanFDQueryIND_NUMB        -> Value =
                2;

            try
            {
                FDQuery3 -> Active = False;

                DataModule1 -> Sub_Edu_PlanFDQuery -> ApplyUpdates ();
                DataModule1 -> Sub_Edu_PlanFDQuery -> CommitUpdates ();
            }
            catch (...)
            {
                DataModule1 -> Sub_Edu_PlanFDQuery -> CancelUpdates ();

                ShowMessage (
                    "Произошел сбой попробуйте еще раз!"
                );
            }
        }
        else
        {
            FDQuery3 -> Active = True;
            FDQuery3 -> Edit ();

            FDQuery3N_OBJECT        -> Value = DBLookupComboBox4 -> KeyValue;

            FDQuery3PERC_SUB_PLAN   -> Value = StrToFloat (Edit5  -> Text);
            FDQuery3CLASSROOM_HOURS -> Value = StrToInt  (Edit7  -> Text);
            FDQuery3LECTURE_HOURS   -> Value = StrToInt  (Edit9  -> Text);
            FDQuery3SEMINAR_HOURS   -> Value = StrToInt  (Edit11 -> Text);
            FDQuery3CLOCK_PLAN      -> Value = StrToInt  (Edit13 -> Text);

            try
            {
                FDQuery3 -> ApplyUpdates ();
                FDQuery3 -> CommitUpdates ();
            }
            catch (...)
            {
                FDQuery3 -> CancelUpdates ();

                ShowMessage (
                    "Произошел сбой попробуйте еще раз!"
                );
            }
        }
    }

    try
    {
        DataModule1 -> Edu_PlanFDQuery -> ApplyUpdates ();
        DataModule1 -> Edu_PlanFDQuery -> CommitUpdates ();

        n_plan = 0;
    }
    catch (...)
    {
        DataModule1 -> Edu_PlanFDQuery -> CancelUpdates ();

        n_plan = 0;

        ShowMessage (
            "Произошел сбой попробуйте еще раз!"
        );
    }

    DataModule1 -> Edu_PlanFDQuery -> Close ();
    DataModule1 -> Edu_PlanFDQuery -> SQL -> Clear ();

    if (Edu_planForm -> RadioGroup1 -> ItemIndex != -1)                         // если выбран курс, то SQL надо открывать по конкретному курсу
    {
        AnsiString s[6] =
        {
            " AND (semestr = 1  OR semestr = 2) ",
            " AND (semestr = 3  OR semestr = 4) ",
            " AND (semestr = 5  OR semestr = 6) ",
            " AND (semestr = 7  OR semestr = 8) ",
            " AND (semestr = 9  OR semestr = 10) ",
            " AND (semestr = 11 OR semestr = 12) "
        };

        DataModule1 -> Edu_PlanFDQuery -> SQL ->
            Add (
                "SELECT Edu_plan.* , object_PLAN.name_object||' '||Edu_plan.clock_plan_all||'ч' AS name_plan, object_PLAN.name_object FROM EDU_PLAN, object_plan WHERE (YEAR_PLAN=:PLAN) and Edu_plan.n_object = object_plan.n_object AND (N_FAC=:N_FAC) AND (VID_EDU_PLAN=" +
                    AnsiString (Edu_planForm -> RadioGroup2 -> ItemIndex) +
                ")" +
                    s[Edu_planForm -> RadioGroup1 -> ItemIndex] +
                "ORDER BY SEMESTR"
            );
    }
    else                                                                        // если не выбран конкретный курс
    {
        DataModule1 -> Edu_PlanFDQuery -> SQL ->
            Add (
                "SELECT Edu_plan. * , object_PLAN.name_object||' '||Edu_plan.clock_plan_all||'ч' AS name_plan, object_PLAN.name_object FROM EDU_PLAN, object_plan WHERE (YEAR_PLAN=:PLAN) and Edu_plan.n_object = object_plan.n_object AND (N_FAC=:N_FAC) AND (VID_EDU_PLAN=" +
                    AnsiString (Edu_planForm -> RadioGroup2 -> ItemIndex) +
                ") ORDER BY SEMESTR"
            );
    }

    DataModule1 -> Edu_PlanFDQuery ->
        ParamByName ("N_FAC") -> AsInteger = nom_fac;
    DataModule1 -> Edu_PlanFDQuery ->
        ParamByName ("PLAN")  -> Value     = uch_god;

    DataModule1 -> Edu_PlanFDQuery -> Open ();
}



void __fastcall TAdd_Edu_planForm::BitBtn2Click (TObject * Sender)
{
    // DataModule1 -> Edu_PlanQuery -> CancelUpdates ();

    if (    Add_Edu_planForm -> Caption == "Добавление предмета в учебный план" // если добавили запись по специализациям и ее надо удалить
         && DataModule1 -> Spec_PlanFDQuery -> State == dsBrowse
       )
    {
        int col_rec = DataModule1 -> Spec_PlanFDQuery -> RecordCount;

        for ( int i = 0;                                                        // удаляем все что не сохраняли
                  i < col_rec;
                  ++i
            )
            DataModule1 -> Spec_PlanFDQuery -> Delete ();

        DataModule1 -> Spec_PlanFDQuery -> ApplyUpdates ();
        DataModule1 -> Spec_PlanFDQuery -> CommitUpdates ();
    }

    DataModule1 -> Spec_PlanFDQuery -> Close ();

    this -> Close ();
}



void __fastcall TAdd_Edu_planForm::CheckBox1Click (TObject * Sender)
{
    if (CheckBox1 -> Checked == true)
    {
        BitBtn1 -> Top = Panel2 -> Top + Panel2 -> Height;
        BitBtn2 -> Top = Panel2 -> Top + Panel2 -> Height;

        Panel2 -> Visible = True;

        ClientHeight = ClientHeight + Panel2 -> Height;

        Edit6  -> Text = 0;
        Edit7  -> Text = 0;
        Edit8  -> Text = 0;
        Edit9  -> Text = 0;
        Edit10 -> Text = 0;
        Edit11 -> Text = 0;
        Edit12 -> Text = 0;
        Edit13 -> Text = 0;
    }
    else
    {
        // BitBtn1 -> Top = BitBtn1 -> Top - Panel2 -> Height;
        // BitBtn2 -> Top = BitBtn2 -> Top - Panel2 -> Height;

        Panel2 -> Visible = False;

        ClientHeight = ClientHeight - Panel2 -> Height;
    }
}



void __fastcall TAdd_Edu_planForm::Edit1KeyPress (
        TObject * Sender,
        char    & Key
    )
{
    DataModule1 -> Edit_Key (Key);                                              // Как сделать, чтобы в TEdit можно было вводить только числа?
}



void __fastcall TAdd_Edu_planForm::Edit4Change (TObject * Sender)
{
    Edit5 -> Text = FloatToStr (1 - StrToFloat (Edit4 -> Text));
}



void __fastcall TAdd_Edu_planForm::Edit5Change (TObject * Sender)
{
    Edit4 -> Text = FloatToStr (1 - StrToFloat (Edit5 -> Text));
}



void __fastcall TAdd_Edu_planForm::Edit6Exit (TObject * Sender)
{
    if (Edit6 -> Text == "")
        Edit6 -> Text = "0";
}



void __fastcall TAdd_Edu_planForm::Edit7Exit (TObject * Sender)
{
    if (Edit7 -> Text == "")
        Edit7 -> Text = "0";
}



void __fastcall TAdd_Edu_planForm::Edit8Exit (TObject * Sender)
{
    if (Edit8 -> Text == "")
        Edit8 -> Text = "0";
}



void __fastcall TAdd_Edu_planForm::Edit9Exit (TObject * Sender)
{
    if (Edit9 -> Text == "")
        Edit9 -> Text = "0";
}



void __fastcall TAdd_Edu_planForm::Edit10Exit (TObject * Sender)
{
    if (Edit10 -> Text == "")
        Edit10 -> Text = "0";
}



void __fastcall TAdd_Edu_planForm::Edit11Exit (TObject * Sender)
{
    if (Edit11 -> Text == "")
        Edit11 -> Text = "0";
}



void __fastcall TAdd_Edu_planForm::Edit12Exit (TObject * Sender)
{
    if (Edit12 -> Text == "")
        Edit12 -> Text = "0";
}



void __fastcall TAdd_Edu_planForm::Edit13Exit (TObject * Sender)
{
    if (Edit13 -> Text == "")
        Edit13 -> Text = "0";
}



void __fastcall TAdd_Edu_planForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    this -> Close ();
}



void __fastcall TAdd_Edu_planForm::RadioGroup1Click (TObject * Sender)
{
    if (    Add_Edu_planForm -> Caption
         == "Добавление предмета в учебный план"
       )
        n_plan = DataModule1 -> vozvrat_inc_edu_plan ();
    else
        n_plan = DataModule1 -> Edu_PlanFDQueryN_PLAN -> Value;


    if (RadioGroup1 -> ItemIndex)                                               // if если выбрали специализации
    {
        DualListDlg = new TDualListDlg (this);


        DualListDlg -> SrcList -> Items -> Clear ();
        DualListDlg -> DstList -> Items -> Clear ();


        DataModule1 -> SpecializFDQuery -> Close ();
        DataModule1 -> SpecializFDQuery ->
            ParamByName ("FAC") -> AsInteger =
                    nom_fac;
        DataModule1 -> SpecializFDQuery -> Open ();


        for ( int i = 0;                                                        // заносим записи специализаций в компонент
                  i < DataModule1 -> SpecializFDQuery -> RecordCount;
                  ++i
            )
        {
            DualListDlg ->
                SrcList ->
                    Items ->
                        AddObject (
                            DataModule1 ->
                                SpecializFDQuerySPECIAL ->
                                    Value,
                           (TObject *) (
                                DataModule1 ->
                                    SpecializFDQueryN_SPECIALIZ ->
                                        Value
                            )
                        );

            DataModule1 -> SpecializFDQuery -> Next ();
        }

        DualListDlg -> ShowModal ();

        if (DataModule2 -> printdlg == true)                                    // если нажата кнопка ОК
        {
            if (DualListDlg -> DstList -> Items -> Count != 0)                  // если выбрали хотя бы одну специализацию
            {
                for ( int j = 0;                                                // for выборка по выбранным специализациям
                          j < DualListDlg -> DstList -> Items -> Count;
                          ++j
                    )
                {
                    int spec_plan =
                        DataModule1 ->
                            SpecializFDQuery ->
                                Lookup (
                                    "SPECIAL",
                                    DualListDlg ->
                                        DstList ->
                                            Items ->
                                                Strings[j],
                                    "N_SPECIALIZ"
                                );


                    if (    DataModule1 -> Spec_PlanFDQuery -> State
                         == dsInactive
                       )
                        DataModule1 -> Spec_PlanFDQuery -> Open ();


                    Variant V =                                                 // переменная для поиска записи
                        DataModule1 ->
                            Spec_PlanFDQuery ->
                                Lookup (
                                    "N_PLAN;N_SPECIALIZ",
                                    VarArrayOf (
                                        OPENARRAY (
                                            Variant,
                                           (
                                                n_plan,
                                                spec_plan
                                            )
                                        )
                                    ),
                                    "N_SPEC_PLAN"
                                );


                    if (VarType (V) == varNull)                                 // если такой записи не нашлось - сохраняем ее в набор данных
                    {
                        DataModule1 -> Spec_PlanFDQuery -> Insert ();

                        DataModule1 -> Spec_PlanFDQueryN_PLAN      -> Value =
                            n_plan;

                        DataModule1 -> Spec_PlanFDQueryN_SPECIALIZ -> Value =
                            spec_plan;
                    }
                }

                DataModule1 -> Spec_PlanFDQuery -> ApplyUpdates ();
                DataModule1 -> Spec_PlanFDQuery -> CommitUpdates ();

                DataModule1 -> Spec_PlanFDQuery -> Close ();
                DataModule1 -> Spec_PlanFDQuery ->
                    ParamByName ("PLAN") -> Value =
                            n_plan;
                DataModule1 -> Spec_PlanFDQuery -> Open ();

                DBGrid1 -> Visible = true;
            }
            else                                                                // усли не выбрана специализация
            {
                ShowMessage (
                    "Вы не выбрали ни одной специализации!"
                );

                return;
            }
        }
        else                                                                    // если нажата кнопка Отменить
            ShowMessage (
                "Вы не выбрали ни одной специализации!"
            );

        delete DualListDlg;
    }
    else                                                                        // если нажали кнопку ВСЕ СПЕЦИАЛИЗАЦИИ
    {
        DataModule1 -> Spec_PlanFDQuery -> Close ();
        DataModule1 -> Spec_PlanFDQuery ->
            ParamByName ("PLAN") -> Value =
                    n_plan;
        DataModule1 -> Spec_PlanFDQuery -> Open ();

        int rec_spec = DataModule1 -> Spec_PlanFDQuery -> RecordCount;

        if (rec_spec)                                                           // если есть специализации, у которых сохранен этот учебный план
        {
            if (    MessageDlg (
                        "Вы хотите, чтобы этот предмет был для всех специализаций?",
                        mtConfirmation,
                        TMsgDlgButtons () << mbYes << mbNo,
                        0
                    ) == mrYes
                )
            {
                for ( int i = 0;                                                // удаление записей
                          i < rec_spec;
                          ++i
                    )
                    DataModule1 -> Spec_PlanFDQuery -> Delete ();

                DataModule1 -> Spec_PlanFDQuery -> ApplyUpdates ();
                DataModule1 -> Spec_PlanFDQuery -> CommitUpdates ();
            }
        }
    }
}
#include <vcl.h>
#pragma hdrstop


#include "DataModule.h"
#include "Result_Ball_RatingUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TResult_Ball_RatingForm * Result_Ball_RatingForm;  


AnsiString s1 = "                                           \
    SELECT                                                  \
        r.n_rating,                                         \
        r.n_ved_rating,                                     \
        r.nomer,                                            \
        r.ball_r,                                           \
        r.r_fac,                                            \
        r.r_kurs,                                           \
        r.r_group,                                          \
        r.r_dop,                                            \
        p.fam,                                              \
        p.name,                                             \
        p.otch,                                             \
        v.n_vedomost_r,                                     \
        v.n_fac,                                            \
        v.vid_edu,                                          \
        v.uch_god,                                          \
        v.semestr,                                          \
        v.session,                                          \
        v.inc_group,                                        \
        v.n_specializ,                                      \
        s.special,                                          \
        i.n_group,                                          \
        p.fam || ' ' || p.name || ' ' || p.otch AS fio      \
    FROM                                                    \
        rating AS r                                         \
            INNER JOIN                                      \
                people AS p                                 \
                    ON                                      \
                        (r.nomer        = p.nomer)          \
            INNER JOIN                                      \
                vedomost_rating AS v                        \
                    ON                                      \
                        (r.n_ved_rating = v.n_ved_rating)   \
            INNER JOIN                                      \
                specializ AS s                              \
                    ON                                      \
                        (v.n_specializ  = s.n_specializ)    \
            INNER JOIN                                      \
                increment_group AS i                        \
                    ON                                      \
                        (v.inc_group    = i.inc_group)      \
    WHERE                                                   \
        v.n_fac = :FAC                                      \
    ";

AnsiString s2 = "                                           \
    AND                                                     \
        v.n_vedomost_r = :VED                               \
    ";

AnsiString s3 = "                                           \
    AND                                                     \
        v.uch_god = :GOD                                    \
    ";

AnsiString s4 = "                                           \
    ORDER BY                                                \
        p.fam,                                              \
        p.name,                                             \
        p.otch                                              \
    ";



__fastcall TResult_Ball_RatingForm::TResult_Ball_RatingForm (TComponent * Owner)
    : TForm (Owner)
{ }



void __fastcall TResult_Ball_RatingForm::ApplicationEvents1Message (            // организовать нормальную работу мышиного колесика в DBGrid
        tagMSG & Msg,
        bool   & Handled
    )
{
    if (DBGrid1 -> Focused ())
    {
        if (Msg.message == WM_MOUSEWHEEL)
        {
            Msg.message = WM_KEYDOWN;

            Msg.lParam  = 0;

            short int i = HIWORD (Msg.wParam);

            Msg.wParam  = (i > 0) ? VK_UP : VK_DOWN;

            Handled = false;
        }
    }                   
}



void __fastcall TResult_Ball_RatingForm::BitBtn1Click (TObject * Sender)
{
    if (Edit1 -> Text == "")
        return
            ShowMessage (
                "Введите номер ведомости!"
            );

    if (Edit2 -> Text == "")
        return
            ShowMessage (
                "Введите Учебный год!"
            );


    DataModule1 -> Rating_BallFDQuery -> Close ();
    DataModule1 -> Rating_BallFDQuery -> SQL -> Clear ();

    DataModule1 ->
        Rating_BallFDQuery ->
            SQL ->
                Add (
                    s1 +
                    s2 +
                    s3
                );

    DataModule1 -> Rating_BallFDQuery ->
        ParamByName ("FAC") -> AsSmallInt =
                nom_fac;

    DataModule1 -> Rating_BallFDQuery ->
        ParamByName ("VED") -> AsSmallInt =
                StrToInt (Edit1 -> Text);

    DataModule1 -> Rating_BallFDQuery ->
        ParamByName ("GOD") -> AsSmallInt =
                StrToInt (Edit2 -> Text);

    DataModule1 -> Rating_BallFDQuery -> Open ();


    if (DataModule1 -> Rating_BallFDQuery -> RecordCount)                       // проверка наличия записи - показ формы
    {
        Result_Ball_RatingForm -> Height = 498;

        Panel2 -> Visible = true;
        Panel3 -> Visible = true;
        Panel4 -> Visible = true;
    }
    else                                                                        // нет записей
        return
            ShowMessage (
                "Нет записей!"
            );
}



void __fastcall TResult_Ball_RatingForm::BitBtn2Click (TObject *Sender)
{
    try
    {
        DataModule1 -> Rating_BallFDQuery -> ApplyUpdates ();
        DataModule1 -> Rating_BallFDQuery -> CommitUpdates ();
    }
    catch (...)
    {
        ShowMessage (
            "Данные не сохранены. Исправьте баллы (диапазон от 0 до 100). Сохраните еще раз!"
        );
    
    }
}



void __fastcall TResult_Ball_RatingForm::Edit1Change (TObject * Sender)
{
    Result_Ball_RatingForm -> Height = 100;                                     // показ формы

    Panel2 -> Visible = false;
    Panel3 -> Visible = false;
    Panel4 -> Visible = false;
}



void __fastcall TResult_Ball_RatingForm::Edit1KeyPress (
        TObject * Sender,
        char    & Key
    )
{
    if (Key == 13)                                                              // проверка нажатия клавиши ВВОД
        BitBtn1Click (this);

    DataModule1 -> Edit_Key (Key);                                              // Как сделать, чтобы в TEdit можно было вводить только числа?
}



void __fastcall TResult_Ball_RatingForm::Edit2KeyPress (
        TObject * Sender,
        char    & Key
    )
{
    DataModule1 -> Edit_Key (Key);                                              // Как сделать, чтобы в TEdit можно было вводить только числа?        
}



void __fastcall TResult_Ball_RatingForm::FormActivate (TObject *Sender)
{
    Result_Ball_RatingForm -> Height = 100;                                     // показ формы

    Panel2 -> Visible = false;
    Panel3 -> Visible = false;
    Panel4 -> Visible = false;

    Edit2 -> Text = uch_god;
    Edit3 -> Text = uch_god + 1;
}



void __fastcall TResult_Ball_RatingForm::FormClose (
        TObject      * Sender,
        TCloseAction & Action
    )
{
    DataModule1 -> Rating_BallFDQuery -> Close ();

    this -> Close (); 
}
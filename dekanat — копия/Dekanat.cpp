#include <vcl.h>
#pragma hdrstop


#include "DM2Unit.h"
#include "IniFiles.hpp"
#include "SplashUnit.h"


USEFORM ("AboutUnit.cpp",                AboutBox                    );
USEFORM ("Add_Edu_planUnit.cpp",         Add_Edu_planForm            );
USEFORM ("Add_UchKartUnit.cpp",          Add_UchKartForm             );
USEFORM ("ADD_Ved_GEKUnit.cpp",          ADD_VedGEK                  );
USEFORM ("AdressUnit.cpp",               AdressForm                  );
USEFORM ("All_StatisticUnit.cpp",        All_StatisticForm           );
USEFORM ("AutoDiplomUnit.cpp",           AutoDiplomForm              );
USEFORM ("Ball_LikvidUnit.cpp",          Ball_LikvidForm             );
USEFORM ("Ball_Unit.cpp",                Ball_Form                   );
USEFORM ("BallGEKUnit.cpp",              Ball_GEK                    );
USEFORM ("CalendarUnit.cpp",             CalendarForm                );
USEFORM ("DataModule_Card.cpp",          DataModule2                 );         // TDataModule: File Type
USEFORM ("DataModule.cpp",               DataModule1                 );
USEFORM ("DeloUnit.cpp",                 DeloForm                    );
USEFORM ("DialogPassUnit.cpp",           DialogPass                  );
USEFORM ("DialogVed.cpp",                OKBottomDlg                 );
USEFORM ("DiplomUnit.cpp",               DiplomForm                  );
USEFORM ("DM2Unit.cpp",                  DM2                         );         // TDataModule: File Type
USEFORM ("DM3Unit.cpp",                  DM3                         );         // TDataModule: File Type
USEFORM ("DM4Unit.cpp",                  DM4                         );         // TDataModule: File Type
USEFORM ("Dop_Ved_LikvidReportUnit.cpp", Dop_Ved_LikvidReportForm    );
USEFORM ("Dop_Ved_RatingUnit.cpp",       Dop_Ved_RatingForm          );
USEFORM ("Dop_Ved_RaznicaUnit.cpp",      Dop_Ved_RaznicaForm         );
USEFORM ("Dop_VedUnit.cpp",              Dop_VedForm                 );
USEFORM ("DUALLIST.cpp",                 DualListDlg                 );
USEFORM ("Edu_planUnit.cpp",             Edu_planForm                );
USEFORM ("InfoUnit.cpp",                 InfoForm                    );
USEFORM ("JournalUnit.cpp",              JournalForm                 );
USEFORM ("KartaUnit.cpp",                Medical_checklist_print_Form);
USEFORM ("LikvidUchPlanUnit.cpp",        LikvidUchPlanForm           );
USEFORM ("LogPassUnit.cpp",              LogPassForm                 );
USEFORM ("MainUnit.cpp",                 MainForm                    );
USEFORM ("Medical_СhecklistUnit.cpp",    Medical_Checklist_Form      );
USEFORM ("NK_3Unit.cpp",                 NK_3Form                    );
USEFORM ("PasportUnit.cpp",              PasportForm                 );
USEFORM ("PassDlgUnit.cpp",              PassDlg                     );
USEFORM ("PassUnit.cpp",                 PassForm                    );
USEFORM ("PeopleVedUnit.cpp",            PeopleVedForm               );
USEFORM ("Perezach_UchKartUnit.cpp",     Perezach_UchKartForm        );
USEFORM ("Prikaz_LikvidUnit.cpp",        Prikaz_LikvidForm           );
USEFORM ("PrivilegeUnit.cpp",            PrivilegeForm               );
USEFORM ("QueueUnit.cpp",                QueueForm                   );
USEFORM ("Rating_ReportUnit.cpp",        Rating_ReportForm           );
USEFORM ("ReferencesUnit.cpp",           Form1                       );
USEFORM ("ReferenceUnit.cpp",            ReferenceForm               );
USEFORM ("Result_Ball_RatingUnit.cpp",   Result_Ball_RatingForm      );
USEFORM ("Result_RatingUnit.cpp",        Result_RatingForm           );
USEFORM ("Result_VedUnit.cpp",           Result_VedForm              );
USEFORM ("Semestr_SessionUnit.cpp",      Semestr_sessionForm         );
USEFORM ("SessionUnit.cpp",              Session_Form                );
USEFORM ("SpisocUnit.cpp",               SpisocForm                  );
USEFORM ("SpisokAllUnit.cpp",            SpisokAllForm               );
USEFORM ("SplashUnit.cpp",               SplashForm                  );
USEFORM ("SportUnit.cpp",                SportForm                   );
USEFORM ("Spravka_vyzovUnit.cpp",        Spravka_vyzovForm           );
USEFORM ("SpravkaUnit.cpp",              SpravkaForm                 );
USEFORM ("SpravkiUnit.cpp",              SpavkiForm                  );
USEFORM ("SpravUnit.cpp",                SpravForm                   );
USEFORM ("StatisticUnit.cpp",            StatisticForm               );
USEFORM ("Stud_Pr_RestoreUnit.cpp",      Stud_Pr_RestoreForm         );
USEFORM ("StudUnit.cpp",                 StudForm                    );
USEFORM ("Svod_VedUnit.cpp",             Svod_Ved                    );
USEFORM ("VED_GEKResultUnit.cpp",        VED_GEKResult               );
USEFORM ("Ved_GEKUnit.cpp",              Ved_GEK                     );
USEFORM ("Ved_LikvidUnit.cpp",           Ved_LikvidForm              );
USEFORM ("Ved_RatingUnit.cpp",           Ved_RatingForm              );
USEFORM ("Ved_ReportUnit.cpp",           Ved_ReportForm              );
USEFORM ("VedomostUnit.cpp",             VedomostForm                );
USEFORM ("VedUnit.cpp",                  Ved_Form                    );
USEFORM ("Vipusk_StudUnit.cpp",          Vipusk_Stud                 );
USEFORM ("VipusknikiUnit.cpp",           VipusknikiForm              );



WINAPI WinMain (
        // HINSTANCE,
        // HINSTANCE,
        // LPSTR,
        // int
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR     lpCmdLine,
        int       nCmdShow
    )
{
    TIniFile * Inifile =
        new TIniFile (
            "o:\\Обмен_БГУФК\\Dekanat\\Version.ini"
        );


    AnsiString FromPath,
               ToPath;
    String     str,
               text,
               v;


    try
    {
        // if (ExtractFileName (GetModuleName (0)) != "Dekanat_up.exe")            // автомотическое обновление программы 23.05.2016 ____Черепанов
        // {
        //     v    = DM2 -> get_version ();

        //     text =
        //         Inifile ->
        //             ReadString  (
        //                 "Comment",
        //                 "Comment",
        //                 ""
        //             );
        //     str  =
        //         Inifile ->
        //             ReadString  (
        //                 "Version",
        //                 "Version",
        //                 ""
        //             );

        //     if (str != v)
        //     {
        //         if (    MessageDlg (
        //                     "Вышла новая версия программы\n\nИзменение: "   +
        //                         text                                        +
        //                     "\n\nОбновить сейчас?",
        //                     mtConfirmation,
        //                     TMsgDlgButtons () << mbYes << mbNo,
        //                     0
        //                 ) == mrYes
        //            )
        //         {
        //             FromPath =
        //                 AnsiString (
        //                     "o:\\Обмен_БГУФК\\Dekanat\\Dekanat.exe"
        //                 );
        //             ToPath =
        //                 AnsiString (
        //                     ExtractFilePath (
        //                         GetModuleName (0)
        //                     )                       +
        //                     "\\Dekanat_up.exe"
        //                 );


        //             CopyFile (
        //                 FromPath.c_str (),
        //                 ToPath.c_str (),
        //                 false
        //             );
        //             WinExec (
        //                 ToPath.c_str (),
        //                 SW_RESTORE
        //             );
                    

        //             exit (0);
        //         }
        //     }
        // }
        // else
        // {
        //     if (    MessageDlg (
        //                 "Программа обновлена",
        //                 mtConfirmation,
        //                 TMsgDlgButtons () << mbOK,
        //                 0
        //             ) == 1
        //        )
        //     {
        //         DeleteFile (
        //             ExtractFilePath (
        //                 GetModuleName (0)
        //             )                       +
        //             "\\Dekanat.exe"
        //         );

        //         vers = DM2 -> get_version ();

        //         RenameFile (
        //             "Dekanat_up.exe",
        //             "Dekanat.exe"
        //         );
        //     }
        // }                                                                       // Конец блока автоматического обновления


        SplashForm = new TSplashForm (Application);

        SplashForm -> Show ();
        SplashForm -> Update ();

        Application -> Initialize ();
        Application -> Title    = "АСУ Деканат";
        Application -> HelpFile = "DEKANAT.HLP";

        delete SplashForm;

        Application -> Run ();
    }
    catch (Exception & exception)
    {
        Application -> ShowException (& exception);
    }

    return 0;
}
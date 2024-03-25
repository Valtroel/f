// #define NO_WIN32_LEAN_AND_MEAN                                                  // � ����� �� ������ [bcc32 Error] Winapi.ShlObj.hpp (592): E2257 , expected,  ���������� ������ ��� "���� �������� ���������� ������� ��������� ::BROWSEINFO"
// #include <shlobj.h>                                                             // ������ ���� ��� � �������� ����, �� ����� ������ ������������� ������� ��� ��� ������� ����������, � �������������� ��������


#include <vcl.h>
#pragma hdrstop


#include "DataModule_Card.h"
#include "DataModule.h"
#include "DM2Unit.h"
#include "DM3Unit.h"
#include "DM4Unit.h"
#include "LogPassUnit.h"
#include "MainUnit.h"
#include "SplashUnit.h"
// #include <winsock2.h>


#pragma package (smart_init)
// #pragma link     "MyDialogPass"
#pragma resource "*.dfm"


TSplashForm * SplashForm;


AnsiString user_name;                                                           // ������� ��� ������������, ��� ������� ����� �� ����

String     loginUser,
           pswdUser,
           vers;



__fastcall TSplashForm::TSplashForm (TComponent * Owner)
    : TForm (Owner)
{ }



// FormActivate
// FormCreate
// FormDestroy





// AnsiString GetMyIP ()
// {
//     struct ipconvert
//     {
//         unsigned char ip[4];
//                  char name[100];
//     } * ipname;

//     AnsiString iplong="";

//     int version = 0x101;

//     char Hostname[100];

//     HOSTENT * pHostEnt = 0;

//     WSADATA WSAData;

//     WSAStartup (
//         version,
//         & WSAData
//     );

//     gethostname (
//         Hostname,
//         sizeof (Hostname)
//     );

//     pHostEnt = gethostbyname (Hostname);

//     ipname   = (ipconvert *) pHostEnt -> h_addr_list[0];

//     for ( int i = 0;
//               i < 4;
//               ++i
//         )
//         iplong += AnsiString (int (ipname -> ip[i])) + ".";

//     iplong =
//         iplong
//         .SubString (
//             1,
//             (iplong.Length () - 1)
//         );

//     WSACleanup ();

//     return iplong;
// }




void __fastcall DB_Params (                                                     // ���������� ���������� � Database1
        AnsiString Login,
        AnsiString Pass
    )
{
    // AnsiString Login,                                                           // �������� ��� ������������
    //            Pass,                                                            // �������� ������
    //            s;                                                               // �������� �������� �� ini ����� � �������

    if (    Login == "1231"                                                     // if �������� ���� � ���� ����� ��������� �� Database �� ���������
         || Login == "1232"
         || Login == "1233"
         || Login == "1234"
         || Login == "1235"
         || Login == "SYSDBA"
       )
    {
        Login = "DEVELOPER";

        DataModule1 -> testDB_str = "";                                         // �������� ���������� Database1

        DataModule1 -> FDConnection1 -> Connected = false;
        DataModule1 -> FDConnection1 -> Params -> Clear ();

        DataModule1 -> FDConnection1 -> Params ->
            Add (
                // "Database=D:\\BGUFK\\Dekanat\\IB_DEKANAT.gdb"
                // "Database=dekanat_test"
                "Database=dekanat"
            );
        DataModule1 -> FDConnection1 -> Params ->
            Add (
                // "Server = localhost"
                "Server=172.16.1.30"
            );
        DataModule1 -> FDConnection1 -> Params ->
            Add (
                "User_Name=" + Login
            );
        DataModule1 -> FDConnection1 -> Params ->
            Add (
                "Password=" + Pass
            );
        DataModule1 -> FDConnection1 -> Params ->
            Add (
                "DriverID=FB"
            );
    }
    else                                                                        // else �������� ������
    {
        DataModule1 -> testDB_str = "";                                         // �������� ���������� Database1

        DataModule1 -> FDConnection1 -> Connected = false;

        // DataModule1 -> Database1 -> AliasName = "Dekanat_vmain1";               // ���������� � ������ ������� main2
        // "SERVER NAME=vmain1:D:/Bgufk/Dekanat/IB_DEKANAT.GDB"
        // "Database=dekanat"
        // "Server=172.16.1.30"

        DataModule1 -> FDConnection1 -> Params -> Clear ();
        DataModule1 -> FDConnection1 -> Params -> Add ("Database=dekanat");
        DataModule1 -> FDConnection1 -> Params -> Add ("Server=172.16.1.30");
        DataModule1 -> FDConnection1 -> Params -> Add ("User_Name=" + Login);
        DataModule1 -> FDConnection1 -> Params -> Add ("Password="  + Pass);
        DataModule1 -> FDConnection1 -> Params -> Add ("DriverID=FB");


        // DM2 -> IBDatabase1 -> Params -> Add ("lc_ctype = WIN1251");
    }

    // DM2         -> IBDatabase1 -> Params -> Add ("user_name=" + Login);
    // DM2         -> IBDatabase1 -> Params -> Add ("password=" + Pass);

    // DataModule1 -> Database1   -> Params -> Add ("USER NAME=" + Login);
    // DataModule1 -> Database1   -> Params -> Add ("PASSWORD=" + Pass);
}





void __fastcall TSplashForm::FormCreate (TObject * Sender)
{
    splash = 1;

    TCHAR szUserName[256];              

    DWORD dwSize = sizeof (szUserName);

    GetUserName (                                                               // ��������� ����� ������������, ��� ������� ����� �� ���������
        szUserName,
        & dwSize
    );

    user_name = szUserName;
}


void __fastcall TSplashForm::FormDestroy (TObject * Sender)
{
    splash = 0;
}


void __fastcall TSplashForm::FormActivate (TObject * Sender)
{
    if (ExtractFileName (GetModuleName (0)) == "Dekanat.exe")
        Version -> Caption = "������ " + DM2 -> get_version ();
    else
        Version -> Caption = "������ " + vers;

    int fac_nomer;                                                              // ����� ���������� ���� �������� ��� Developer-��

    try
    {
        LogPassForm = new TLogPassForm (Application);                           // ��������� ������ � ������

        TIniFile * inif =                                                       // ��� ������� ������� � ini ��������� � ���
            new TIniFile (
                ChangeFileExt (
                    Application -> ExeName,
                    ".INI"
                )
            );

        LogPassForm -> Login -> Text =
            inif -> ReadString (
                "Edit1",
                "Text",
                ""
            );

        LogPassForm -> ShowModal ();

        loginUser = LogPassForm -> Login    -> Text;
        pswdUser  = LogPassForm -> Password -> Text;

        delete LogPassForm;

        inif ->
            WriteString (
                "Edit1",
                "Text",
                loginUser
            );

        delete inif;


        Application ->                                                          // ������� �����  TDataModule1 ��� ����������� � ��
            CreateForm (
                __classid (TDataModule1),
                & DataModule1
            );


        DataModule1 -> FDPhysFBDriverLink1 -> VendorLib =                       // ������� �����  TDM2 ��� ����������� � IBDatabase1
            AnsiString (
                ExtractFilePath (GetModuleName (0)) +
                "fbclient\\fbclient.dll"
            );

        Application ->
            CreateForm (
                __classid (TDM2),
                & DM2
            );

        if (    loginUser == "1"                                                // �������� ��������� � LogPassForm ��� ������������ � ������ (������ ��� DEVELOPER)
             || loginUser == "2"
             || loginUser == "3"
             || loginUser == "4"
             || loginUser == "5"
           )
        {
            fac_nomer = StrToInt (loginUser);

            loginUser = "DEVELOPER";
        }


        // AnsiString   p        = "\\\\vmain1\\Config\\Dekanat.INI",
        //              St_name;

        // TIniFile   * ini      = new TIniFile (p);

        // St_name =
        //     ini ->
        //         ReadString (
        //             "Server",
        //             "Text",
        //             St_name
        //         );

        // if (St_name == "")
        // {
        //     p = "\\\\main5\\Config\\Dekanat.INI";
        //     delete ini;

        //     ini = new TIniFile (p);

        //     St_name =
        //         ini ->
        //             ReadString (
        //                 "Server",
        //                 "Text",
        //                 St_name
        //             );
        // }


        DB_Params (
            loginUser,
            pswdUser
        );


        if (    loginUser == "1231"                                             // ������ ��� DEVELOPER
             || loginUser == "1232"
             || loginUser == "1233"
             || loginUser == "1234"
             || loginUser == "1235"
           )
        {
            fac_nomer =
                StrToInt (
                    loginUser.SubString (
                        4,
                        1
                    )
                );

            loginUser = "DEVELOPER";
        }

        // delete ini;

        try
        {
            DataModule1 -> FDConnection1 -> Open ();                            // �������� ���������� ������������ � ������
        }
        catch (...)
        {
            return
                ShowMessage (
                    "�������� ��� ������������ ��� ������"
                );
        }


        if (DataModule1 -> FDConnection1 -> Connected)                          // �������� �������� � ��, ���� ������ ������
        {
            // DataModule1 -> QIP ->                                               // ��������, ��������� �� � ����� ���������� ��������� ���������
            //     ParamByName ("IP_N") -> AsString =
            //             GetMyIP ();

            // DataModule1 -> IP2FDQ ->                                            // ��������, ��������� �� ����� ������������ ��������� ���������
            //     ParamByName ("IP_NAME") -> AsString =
            //         user_name;
            DataModule1 -> IP2FDQ -> Open ();


            if (DataModule1 -> IP2FDQ -> RecordCount)                           // ������������ ������
            {
                // DM2 -> IBDatabase1 -> Open ();                                  // ����� �������� IBDatabase1 ��������� ���  Table

                DM2 -> CategoryFDTable        -> Active = true;
                DM2 -> FacultyFDTable         -> Active = true;
                DM2 -> Cause_HolidayFDTable   -> Active = true;
                DM2 -> Cause_PassFDTable      -> Active = true;
                DM2 -> Cause_RestoreFDTable   -> Active = true;
                DM2 -> FoundationFDTable      -> Active = true;
                DM2 -> Countries_ocrbTable    -> Active = true;
                DM2 -> Increment_GroupFDTable -> Active = true;
                DM2 -> Object_PlanFDTable     -> Active = true;
                DM2 -> Prikaz_KursFDTable     -> Active = true;
                DM2 -> SpecialityFDTable      -> Active = true;
                DM2 -> SpecializFDTable       -> Active = true;
                DM2 -> FDTable1               -> Active = true;
                DM2 -> Type_EncourageFDTable  -> Active = true;
                DM2 -> Type_PrikazFDTable     -> Active = true;
                DM2 -> Vid_SportFDTable       -> Active = true;
                DM2 -> QualificationFDTable   -> Active = true;
                DataModule1 -> RegionFDTable  -> Active = true;
                DM2 -> Special_DirFDTable     -> Active = true;


                if (loginUser == "DEVELOPER")                                   // ���������� ���������� ���������� nom_fac (����� � ������) (������������ � MyDialogPass1)
                    nom_fac = fac_nomer;
                else
                    nom_fac =
                        DM2 -> FDTable1 ->
                            Lookup (
                                "USER_NAME",
                                loginUser,
                                "N_FAC"
                            );

                DM2 -> SpecializFDTable -> Filter   =                           // ������ ���� � ������� ���� ����� ������ ������������� ���������� ����������
                    "N_FAC = "              +
                    AnsiString (nom_fac);
                DM2 -> SpecializFDTable -> Filtered = true;


                Application ->
                    CreateForm (                                                // ������� ����� ��� ������� TMainForm, TDM3, TDataModule2
                        __classid (TMainForm),
                        & MainForm
                    );
                Application ->
                    CreateForm (
                        __classid (TDM3),
                        & DM3
                    );
                Application ->
                    CreateForm (
                        __classid (TDataModule2),
                        & DataModule2
                    );
                Application ->
                    CreateForm (
                        __classid (TDM4),
                        & DM4
                    );

                // Application -> Run ();
            }
            else
            {
                ShowMessage (
                    "�� �� ������ ����� ��������� ���������.\n���������� � ������������!"
                );

                Application -> Terminate ();
            }
        }
        else
            return
                ShowMessage (
                    "�������� ��� ������������ ��� ������"
                );
    }
    catch (Exception & exception)
    {
        Application -> ShowException (& exception);
    }
}
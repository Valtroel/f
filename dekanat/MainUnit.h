#pragma once
#ifndef MAIN_UNIT_H
#define MAIN_UNIT_H


#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <StdCtrls.hpp>


extern int spisok_f,                                                            // номер выбранного пунка меню из списка
           spisok_f1,                                                           // номер выбранного пунка меню из списка
           Vibor;                                                               // ѕереключатель между формами —водной и выписки к диплому


class TMainForm
    : public TForm
{
__published:
    TLabel         * Label1;
    TLabel         * Label2;

    TMainMenu      * MainMenu1;

    TMenuItem      * N1;
    TMenuItem      * N2;
    TMenuItem      * N3;
    TMenuItem      * N4;
    TMenuItem      * N5;
    TMenuItem      * N6;
    TMenuItem      * N7;
    TMenuItem      * N8;
    TMenuItem      * N9;
    TMenuItem      * N10;
    TMenuItem      * N11;
    TMenuItem      * N12;
    TMenuItem      * N13;
    TMenuItem      * N14;
    TMenuItem      * N15;
    TMenuItem      * N16;
    TMenuItem      * N17;
    TMenuItem      * N18;
    TMenuItem      * N19;
    TMenuItem      * N21;
    TMenuItem      * N22;
    TMenuItem      * N23;
    TMenuItem      * N24;
    TMenuItem      * N25;
    TMenuItem      * N26;
    TMenuItem      * N27;
    TMenuItem      * N28;
    TMenuItem      * N29;
    TMenuItem      * N30;
    TMenuItem      * N31;
    TMenuItem      * N32;
    TMenuItem      * N33;
    TMenuItem      * N34;
    TMenuItem      * N35;
    TMenuItem      * N36;
    TMenuItem      * N37;
    TMenuItem      * N38;
    TMenuItem      * N39;
    TMenuItem      * N40;
    TMenuItem      * N41;
    TMenuItem      * N42;
    TMenuItem      * N43;
    TMenuItem      * N44;
    TMenuItem      * N45;
    TMenuItem      * N46;
    TMenuItem      * N47;
    TMenuItem      * N48;
    TMenuItem      * N49;
    TMenuItem      * N50;
    TMenuItem      * N51;
    TMenuItem      * N52;
    TMenuItem      * N53;
    TMenuItem      * N54;
    TMenuItem      * N55;
    TMenuItem      * N56;
    TMenuItem      * N57;
    TMenuItem      * N58;
    TMenuItem      * N59;
    TMenuItem      * N60;
    TMenuItem      * N61;
    TMenuItem      * N62;
    TMenuItem      * N63;
    TMenuItem      * N64;
    TMenuItem      * N65;
    TMenuItem      * N66;
    TMenuItem      * N67;
    TMenuItem      * N68;
    TMenuItem      * N69;
    TMenuItem      * N70;
    TMenuItem      * N71;
    TMenuItem      * N72;
    TMenuItem      * N73;
    TMenuItem      * N74;
    TMenuItem      * N75;
    TMenuItem      * N76;
    TMenuItem      * N77;
    TMenuItem      * N78;
    TMenuItem      * N79;
    TMenuItem      * N80;
    TMenuItem      * N81;
    TMenuItem      * N82;
    TMenuItem      * N83;
    TMenuItem      * N84;
    TMenuItem      * N85;
    TMenuItem      * N310;

    TPanel         * Panel1;

    // TRxLoginDialog * RxLoginDialog1;

    TSpeedButton   * SpeedButton1;


    void __fastcall FormActivate            (TObject * Sender);
    void __fastcall FormClose               (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall FormCreate              (TObject * Sender);
    void __fastcall N1Click                 (TObject * Sender);
    void __fastcall N4Click                 (TObject * Sender);
    void __fastcall N6Click                 (TObject * Sender);
    void __fastcall N8Click                 (TObject * Sender);
    void __fastcall N11Click                (TObject * Sender);
    void __fastcall N12Click                (TObject * Sender);
    void __fastcall N13Click                (TObject * Sender);
    void __fastcall N14Click                (TObject * Sender);
    void __fastcall N16Click                (TObject * Sender);
    void __fastcall N17Click                (TObject * Sender);
    void __fastcall N18Click                (TObject * Sender);
    void __fastcall N19Click                (TObject * Sender);
    void __fastcall N22Click                (TObject * Sender);
    void __fastcall N23Click                (TObject * Sender);
    void __fastcall N24Click                (TObject * Sender);
    void __fastcall N25Click                (TObject * Sender);
    void __fastcall N26Click                (TObject * Sender);
    void __fastcall N27Click                (TObject * Sender);
    void __fastcall N29Click                (TObject * Sender);
    void __fastcall N30Click                (TObject * Sender);
    void __fastcall N31Click                (TObject * Sender);
    void __fastcall N32Click                (TObject * Sender);
    void __fastcall N33Click                (TObject * Sender);
    void __fastcall N34Click                (TObject * Sender);
    void __fastcall N35Click                (TObject * Sender);
    void __fastcall N36Click                (TObject * Sender);
    void __fastcall N37Click                (TObject * Sender);
    void __fastcall N39Click                (TObject * Sender);
    void __fastcall N40Click                (TObject * Sender);
    void __fastcall N42Click                (TObject * Sender);
    void __fastcall N43Click                (TObject * Sender);
    void __fastcall N45Click                (TObject * Sender);
    void __fastcall N46Click                (TObject * Sender);
    void __fastcall N48Click                (TObject * Sender);
    void __fastcall N49Click                (TObject * Sender);
    void __fastcall N50Click                (TObject * Sender);
    void __fastcall N52Click                (TObject * Sender);
    void __fastcall N53Click                (TObject * Sender);
    void __fastcall N54Click                (TObject * Sender);
    void __fastcall N56Click                (TObject * Sender);
    void __fastcall N57Click                (TObject * Sender);
    void __fastcall N58Click                (TObject * Sender);
    void __fastcall N60Click                (TObject * Sender);
    void __fastcall N61Click                (TObject * Sender);
    void __fastcall N62Click                (TObject * Sender);
    void __fastcall N63Click                (TObject * Sender);
    void __fastcall N64Click                (TObject * Sender);
    void __fastcall N65Click                (TObject * Sender);
    void __fastcall N66Click                (TObject * Sender);
    void __fastcall N67Click                (TObject * Sender);
    void __fastcall N68Click                (TObject * Sender);
    void __fastcall N69Click                (TObject * Sender);
    void __fastcall N70Click                (TObject * Sender);
    void __fastcall N71Click                (TObject * Sender);
    void __fastcall N72Click                (TObject * Sender);
    void __fastcall N73Click                (TObject * Sender);
    void __fastcall N74Click                (TObject * Sender);
    void __fastcall N75Click                (TObject * Sender);
    void __fastcall N76Click                (TObject * Sender);
    void __fastcall N77Click                (TObject * Sender);
    void __fastcall N78Click                (TObject * Sender);
    void __fastcall N79Click                (TObject * Sender);
    void __fastcall N80Click                (TObject * Sender);
    void __fastcall N81Click                (TObject * Sender);
    void __fastcall N82Click                (TObject * Sender);
    void __fastcall N83Click                (TObject * Sender);
    // void __fastcall N83Click                (TObject * Sender);
    void __fastcall N84Click                (TObject * Sender);
    void __fastcall N85Click                (TObject * Sender);
    // void __fastcall RxLoginDialog1CheckUser (
    //           TObject    * Sender,
    //     const AnsiString   UserName,
    //     const AnsiString   Password,
    //           bool       & AllowLogin
    //     );
    void __fastcall SpeedButton1Click       (TObject * Sender);
private:
    void __fastcall Open_PrivilegeForm (int n_menu);                            // процедура открыти€ формы дл€ формировани€ справок инвалидов,сирот,„јЁ—
    void __fastcall Open_SpisokForm    (int n_menu);                            // процедура открыти€ формы дл€ формировани€ списка
public:
    __fastcall TMainForm (TComponent * Owner);

    void __fastcall Create_Spisok ();
    void __fastcall Data_Refresh  ();                                           // переопределение даты и учебного года
    void __fastcall prikaz_search (int        n_menu  );                        // процедура поиска активной страницы на форме приказов
    bool __fastcall SearchChild   (AnsiString FormName);
    void __fastcall Spisok        ();
};

extern PACKAGE TMainForm * MainForm;

#endif  // MAIN_UNIT_H
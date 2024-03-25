#pragma once
#ifndef PEOPLE_VED_UNIT_H
#define PEOPLE_VED_UNIT_H


#include <AppEvnts.hpp>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <Data.DB.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
#include <StdCtrls.hpp>


class TPeopleVedForm
    : public TForm
{
__published:
    TApplicationEvents * ApplicationEvents1;

    TBitBtn            * BitBtn1;
    TBitBtn            * BitBtn3;

    TComboBox          * ComboBox3;

    TDBGrid            * DBGrid1;

    TDBLookupComboBox  * DBLookupComboBox1;

    TEdit              * Edit7;

    TLabel             * Label7;
    TLabel             * Label12;
    TLabel             * Label13;

    TPanel             * Panel1;
    TPanel             * Panel2;
    TPanel             * Panel4;

    TRadioGroup        * RadioGroup2;

    TSpeedButton       * SpeedButton1;


    void __fastcall ApplicationEvents1Message (
            tagMSG & Msg,
            bool   & Handled
        );
    void __fastcall BitBtn1Click              (TObject * Sender);
    void __fastcall BitBtn3Click              (TObject * Sender);
    void __fastcall ComboBox3Change           (TObject * Sender);
    void __fastcall DBLookupComboBox1Click    (TObject * Sender);
    void __fastcall Edit7KeyPress             (
            TObject * Sender,
            char    & Key
        );
    void __fastcall FormActivate              (TObject * Sender);
    void __fastcall FormClose                 (
            TObject      * Sender,
            TCloseAction & Action
        );
    void __fastcall RadioGroup2Click          (TObject * Sender);
    void __fastcall SpeedButton1Click         (TObject * Sender);
private:
public:
    __fastcall TPeopleVedForm (TComponent * Owner);
};

extern PACKAGE TPeopleVedForm * PeopleVedForm;

#endif  // PEOPLE_VED_UNIT_H
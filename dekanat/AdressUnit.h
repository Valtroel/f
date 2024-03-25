#pragma once
#ifndef ADRESS_UNIT_H
#define ADRESS_UNIT_H


#include <System.Classes.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.StdCtrls.hpp>


int extern local_id;


class TAdressForm
    : public TForm
{
__published:
    TBitBtn           * BitBtn1;

    TDBEdit           * DBEditFlat;
    TDBEdit           * DBEditHouse;
    TDBEdit           * DBEditPostcode;

    TDBLookupComboBox * DistrictDBLkCmbBx;
    TDBLookupComboBox * LocalityDBLkCmbBx;
    TDBLookupComboBox * StreetDBLkCmbBx;
    TDBLookupComboBox * Type_localityDBLkCmbBx;
    TDBLookupComboBox * Type_streetDBLkCmbBx;

    TLabel            * Label48;
    TLabel            * Label51;
    TLabel            * Label54;
    TLabel            * Label68;
    TLabel            * Label69;
    TLabel            * Label70;
    TLabel            * Label71;
    TLabel            * Label72;


    void __fastcall BitBtn1Click                     (TObject * Sender);
    void __fastcall DistrictDBLkCmbBxCloseUp         (TObject * Sender);
    void __fastcall DistrictDBLkCmbBxMouseDown       (
            TObject      * Sender,
            TMouseButton   Button,
            TShiftState    Shift,
            int            X,
            int            Y
        );
    void __fastcall LocalityDBLkCmbBxCloseUp         (TObject * Sender);
    void __fastcall LocalityDBLkCmbBxExit            (TObject * Sender);
    void __fastcall LocalityDBLkCmbBxMouseDown       (
            TObject      * Sender,
            TMouseButton   Button,
            TShiftState    Shift,
            int            X,
            int            Y
        );
    void __fastcall Type_localityDBLkCmbBxCloseUp    (TObject * Sender);
    void __fastcall Type_localityDBLkCmbBxExit       (TObject * Sender);
    void __fastcall Type_localityDBLkCmbBxMouseDown  (
            TObject      * Sender,
            TMouseButton   Button,
            TShiftState    Shift,
            int            X,
            int            Y
        );
    void __fastcall Type_localityDBLkCmbBxMouseEnter (TObject * Sender);
    void __fastcall Type_streetDBLkCmbBxCloseUp      (TObject * Sender);
    void __fastcall Type_streetDBLkCmbBxExit         (TObject * Sender);
private:
public:
    __fastcall TAdressForm (TComponent * Owner);

    String Adress;

    bool   AdressSave;
};

extern PACKAGE TAdressForm * AdressForm;

#endif  // ADRESS_UNIT_H
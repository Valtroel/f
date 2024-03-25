

#include <vcl.h>
#pragma hdrstop


#include "AdressUnit.h"
#include "DataModule.h"
#include "StudUnit.h"


#pragma package (smart_init)
#pragma resource "*.dfm"


TAdressForm * AdressForm;


int district_id,
    local_id,
    type_local_id,
    type_street_id;



// BitBtn1Click
// DistrictDBLkCmbBxCloseUp
// DistrictDBLkCmbBxMouseDown
// LocalityDBLkCmbBxCloseUp
// LocalityDBLkCmbBxExit
// LocalityDBLkCmbBxMouseDown
// Type_localityDBLkCmbBxCloseUp
// Type_localityDBLkCmbBxExit
// Type_localityDBLkCmbBxMouseDown
// Type_localityDBLkCmbBxMouseEnter
// Type_streetDBLkCmbBxCloseUp
// Type_streetDBLkCmbBxExit



__fastcall TAdressForm::TAdressForm (TComponent * Owner)
    : TForm (Owner) {
}


void __fastcall TAdressForm::DistrictDBLkCmbBxCloseUp (TObject *Sender) {
    if (district_id != DistrictDBLkCmbBx -> KeyValue) {
        Type_localityDBLkCmbBx -> KeyValue = 0;
        LocalityDBLkCmbBx -> KeyValue = 0;
        Type_streetDBLkCmbBx -> KeyValue = 0;
        StreetDBLkCmbBx -> KeyValue = 0;
    }
}


void __fastcall TAdressForm::DistrictDBLkCmbBxMouseDown (TObject *Sender,
    TMouseButton Button, TShiftState Shift, int X, int Y) {
    if (!DistrictDBLkCmbBx -> KeyValue == NULL) {
        district_id = DistrictDBLkCmbBx -> KeyValue;
    }
}


void __fastcall TAdressForm::Type_streetDBLkCmbBxCloseUp (TObject *Sender) {
    if (type_street_id != Type_streetDBLkCmbBx -> KeyValue) {

        StreetDBLkCmbBx -> KeyValue = 0;
    }
}


void __fastcall TAdressForm::Type_localityDBLkCmbBxMouseDown (TObject *Sender,
    TMouseButton Button, TShiftState Shift, int X, int Y) {
    type_local_id = Type_localityDBLkCmbBx -> KeyValue;

}


void __fastcall TAdressForm::Type_localityDBLkCmbBxMouseEnter (TObject *Sender) {
    DataModule1 -> QType_locality -> Close ();
    DataModule1 -> QType_locality -> Open ();
}


void __fastcall TAdressForm::Type_localityDBLkCmbBxCloseUp (TObject *Sender) {
    if (type_local_id != Type_localityDBLkCmbBx -> KeyValue) {
        LocalityDBLkCmbBx -> KeyValue = 0;
        Type_streetDBLkCmbBx -> KeyValue = 0;
        StreetDBLkCmbBx -> KeyValue = 0;
    }
}


void __fastcall TAdressForm::Type_localityDBLkCmbBxExit (TObject *Sender) {
    DataModule1 -> QLocality -> Close ();
    DataModule1 -> QLocality -> ParamByName ("DISTRICT") -> AsInteger =
        DistrictDBLkCmbBx -> KeyValue;
    DataModule1 -> QLocality -> ParamByName ("N_TYPE") -> AsInteger =
        Type_localityDBLkCmbBx -> KeyValue;
    DataModule1 -> QLocality -> Open ();
    if (DataModule1 -> PeopleFDQuery -> State == dsInsert) {
        LocalityDBLkCmbBx -> KeyValue = -1;
    }
}


void __fastcall TAdressForm::LocalityDBLkCmbBxCloseUp (TObject *Sender) {
    if (local_id != LocalityDBLkCmbBx -> KeyValue) {

        Type_streetDBLkCmbBx -> KeyValue = 0;
        StreetDBLkCmbBx -> KeyValue = 0;
    }
}


void __fastcall TAdressForm::LocalityDBLkCmbBxMouseDown (TObject *Sender,
    TMouseButton Button, TShiftState Shift, int X, int Y) {
    local_id = LocalityDBLkCmbBx -> KeyValue;
}


void __fastcall TAdressForm::LocalityDBLkCmbBxExit (TObject *Sender) {
    DataModule1 -> QType_street -> Close ();
    DataModule1 -> QType_street -> Open ();
    Type_streetDBLkCmbBx -> KeyValue = 1;
}


void __fastcall TAdressForm::BitBtn1Click (TObject *Sender) {
    if (DataModule1 -> RegionFDTableN_REGION -> Value != 5) {
        Adress = DataModule1 -> RegionFDTableTEXT_REGION -> Value + ", " +
            DataModule1 -> QDistrictNAME_DISTRICT -> Value + " р-н, " +
            DataModule1 -> QType_localitySHORT_TYPE_NAME -> Value + " " +
            DataModule1 -> QLocalityNAME_LOCALITY -> Value + ",";
    }
    else
        Adress = DataModule1 -> RegionFDTableTEXT_REGION -> Value + ", ";

    if (DataModule1 -> QType_streetSHORT_TYPE -> Value != "-") {
        Adress += DataModule1 -> QType_streetSHORT_TYPE -> Value + " " +
            DataModule1 -> QStreetNAME_IN_RUS -> Value;
    }

    if (DBEditHouse -> Text != "") {
        Adress += ", д. " + DataModule1 -> PeopleFDQueryHOUSE -> Value;
    }
    if (DBEditFlat -> Text != "") {
        Adress += ", кв. " + IntToStr (DataModule1 -> PeopleFDQueryFLAT -> Value);
    }
    if (DBEditPostcode -> Text != "") {
        Adress += ", " + IntToStr (DataModule1 -> PeopleFDQueryPOSTCODE -> Value);
    }
    AdressSave = true;
    Close ();
}

void __fastcall TAdressForm::Type_streetDBLkCmbBxExit (TObject *Sender)
{
type_street_id = Type_streetDBLkCmbBx -> KeyValue;
    DataModule1 -> QStreet -> Close ();
    DataModule1 -> QStreet -> ParamByName ("TYPE_STREET") -> AsInteger =
        Type_streetDBLkCmbBx -> KeyValue;
    if (StudForm -> DBLookupComboBox6 -> KeyValue == 5) {
        DataModule1 -> QStreet -> ParamByName ("ID_LOCALITY") -> AsInteger = 1;
    }
    else
        DataModule1 -> QStreet -> ParamByName ("ID_LOCALITY") -> AsInteger =
            LocalityDBLkCmbBx -> KeyValue;
    DataModule1 -> QStreet -> Open ();
    if (DataModule1 -> PeopleFDQuery -> State == dsInsert) {
        StreetDBLkCmbBx -> KeyValue = -1;
    }
}
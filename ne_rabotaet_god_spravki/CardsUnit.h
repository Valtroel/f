#pragma once
#ifndef CARDS_UNIT_H
#define CARDS_UNIT_H


#include <Data.DB.hpp>
#include <FireDAC.Comp.Client.hpp>
#include <FireDAC.Comp.DataSet.hpp>
#include <FireDAC.DApt.hpp>
#include <FireDAC.DApt.Intf.hpp>
#include <FireDAC.DatS.hpp>
#include <FireDAC.Phys.FB.hpp>
#include <FireDAC.Phys.FBDef.hpp>
#include <FireDAC.Phys.hpp>
#include <FireDAC.Phys.Intf.hpp>
#include <FireDAC.Stan.Async.hpp>
#include <FireDAC.Stan.Def.hpp>
#include <FireDAC.Stan.Error.hpp>
#include <FireDAC.Stan.Intf.hpp>
#include <FireDAC.Stan.Option.hpp>
#include <FireDAC.Stan.Param.hpp>
#include <FireDAC.Stan.Pool.hpp>
#include <FireDAC.UI.Intf.hpp>
#include <FireDAC.VCLUI.Wait.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.StdCtrls.hpp>


extern bool well;


class TCardsForm
    : public TForm
{
__published:
    void __fastcall Button1Click (TObject * Sender);
    void __fastcall FormCreate   (TObject * Sender);
private:
public:
    __fastcall TCardsForm (TComponent * Owner);

    void __fastcall SaveTrStud ();
    void __fastcall StateQ     ();
    void __fastcall UpStud     ();
};

extern PACKAGE TCardsForm * CardsForm;

#endif  // CARDS_UNIT_H
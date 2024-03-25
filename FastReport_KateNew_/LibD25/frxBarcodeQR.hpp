// CodeGear C++Builder
// Copyright (c) 1995, 2016 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxBarcodeQR.pas' rev: 32.00 (Windows)

#ifndef FrxbarcodeqrHPP
#define FrxbarcodeqrHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <Winapi.Messages.hpp>
#include <System.SysUtils.hpp>
#include <System.Types.hpp>
#include <System.StrUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <frxBarcode2DBase.hpp>
#include <frxDelphiZXingQRCode.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxbarcodeqr
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TfrxBarcodeQR;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TfrxBarcodeQR : public Frxbarcode2dbase::TfrxBarcode2DBase
{
	typedef Frxbarcode2dbase::TfrxBarcode2DBase inherited;
	
private:
	Frxdelphizxingqrcode::TDelphiZXingQRCode* FDelphiZXingQRCode;
	void __fastcall Generate(void);
	Frxdelphizxingqrcode::TQRCodeEncoding __fastcall GetEncoding(void);
	int __fastcall GetQuietZone(void);
	void __fastcall SetEncoding(const Frxdelphizxingqrcode::TQRCodeEncoding Value);
	void __fastcall SetQuietZone(const int Value);
	Frxdelphizxingqrcode::TQRErrorLevels __fastcall GetErrorLevels(void);
	void __fastcall SetErrorLevels(const Frxdelphizxingqrcode::TQRErrorLevels Value);
	int __fastcall GetPixelSize(void);
	void __fastcall SetPixelSize(int v);
	int __fastcall GetCodepage(void);
	void __fastcall SetCodepage(const int Value);
	
protected:
	virtual void __fastcall SetText(System::UnicodeString v);
	
public:
	__fastcall virtual TfrxBarcodeQR(void);
	__fastcall virtual ~TfrxBarcodeQR(void);
	virtual void __fastcall Assign(Frxbarcode2dbase::TfrxBarcode2DBase* src);
	
__published:
	__property Frxdelphizxingqrcode::TQRCodeEncoding Encoding = {read=GetEncoding, write=SetEncoding, nodefault};
	__property int QuietZone = {read=GetQuietZone, write=SetQuietZone, nodefault};
	__property Frxdelphizxingqrcode::TQRErrorLevels ErrorLevels = {read=GetErrorLevels, write=SetErrorLevels, nodefault};
	__property int PixelSize = {read=GetPixelSize, write=SetPixelSize, nodefault};
	__property int Codepage = {read=GetCodepage, write=SetCodepage, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Frxbarcodeqr */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXBARCODEQR)
using namespace Frxbarcodeqr;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxbarcodeqrHPP

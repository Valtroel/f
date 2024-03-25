// CodeGear C++Builder
// Copyright (c) 1995, 2016 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxBarcodeProperties.pas' rev: 32.00 (Windows)

#ifndef FrxbarcodepropertiesHPP
#define FrxbarcodepropertiesHPP

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
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <System.Types.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <frxClass.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <frxDesgn.hpp>
#include <frxBarcodePDF417.hpp>
#include <frxBarcodeDataMatrix.hpp>
#include <frxBarcodeQR.hpp>
#include <frxDelphiZXingQRCode.hpp>
#include <frxBarcode2DBase.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxbarcodeproperties
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TfrxBarcode2DProperties;
class DELPHICLASS TfrxPDF417Properties;
class DELPHICLASS TfrxDataMatrixProperties;
class DELPHICLASS TfrxQRProperties;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TfrxBarcode2DProperties : public System::Classes::TPersistent
{
	typedef System::Classes::TPersistent inherited;
	
private:
	System::Classes::TNotifyEvent FOnChange;
	
public:
	System::TObject* FWhose;
	void __fastcall Changed(void);
	virtual void __fastcall Assign(System::Classes::TPersistent* Source) = 0 ;
	void __fastcall SetWhose(System::TObject* w);
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TfrxBarcode2DProperties(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TfrxBarcode2DProperties(void) : System::Classes::TPersistent() { }
	
};


class PASCALIMPLEMENTATION TfrxPDF417Properties : public TfrxBarcode2DProperties
{
	typedef TfrxBarcode2DProperties inherited;
	
private:
	System::Extended __fastcall GetAspectRatio(void);
	int __fastcall GetColumns(void);
	int __fastcall GetRows(void);
	Frxbarcodepdf417::PDF417ErrorCorrection __fastcall GetErrorCorrection(void);
	int __fastcall GetCodePage(void);
	Frxbarcodepdf417::PDF417CompactionMode __fastcall GetCompactionMode(void);
	int __fastcall GetPixelWidth(void);
	int __fastcall GetPixelHeight(void);
	void __fastcall SetAspectRatio(System::Extended v);
	void __fastcall SetColumns(int v);
	void __fastcall SetRows(int v);
	void __fastcall SetErrorCorrection(Frxbarcodepdf417::PDF417ErrorCorrection v);
	void __fastcall SetCodePage(int v);
	void __fastcall SetCompactionMode(Frxbarcodepdf417::PDF417CompactionMode v);
	void __fastcall SetPixelWidth(int v);
	void __fastcall SetPixelHeight(int v);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property System::Extended AspectRatio = {read=GetAspectRatio, write=SetAspectRatio};
	__property int Columns = {read=GetColumns, write=SetColumns, nodefault};
	__property int Rows = {read=GetRows, write=SetRows, nodefault};
	__property Frxbarcodepdf417::PDF417ErrorCorrection ErrorCorrection = {read=GetErrorCorrection, write=SetErrorCorrection, nodefault};
	__property int CodePage = {read=GetCodePage, write=SetCodePage, nodefault};
	__property Frxbarcodepdf417::PDF417CompactionMode CompactionMode = {read=GetCompactionMode, write=SetCompactionMode, nodefault};
	__property int PixelWidth = {read=GetPixelWidth, write=SetPixelWidth, nodefault};
	__property int PixelHeight = {read=GetPixelHeight, write=SetPixelHeight, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TfrxPDF417Properties(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TfrxPDF417Properties(void) : TfrxBarcode2DProperties() { }
	
};


class PASCALIMPLEMENTATION TfrxDataMatrixProperties : public TfrxBarcode2DProperties
{
	typedef TfrxBarcode2DProperties inherited;
	
private:
	int __fastcall GetCodePage(void);
	int __fastcall GetPixelSize(void);
	Frxbarcodedatamatrix::DatamatrixSymbolSize __fastcall GetSymbolSize(void);
	Frxbarcodedatamatrix::DatamatrixEncoding __fastcall GetEncoding(void);
	void __fastcall SetCodePage(int v);
	void __fastcall SetPixelSize(int v);
	void __fastcall SetSymbolSize(Frxbarcodedatamatrix::DatamatrixSymbolSize v);
	void __fastcall SetEncoding(Frxbarcodedatamatrix::DatamatrixEncoding v);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property int CodePage = {read=GetCodePage, write=SetCodePage, nodefault};
	__property int PixelSize = {read=GetPixelSize, write=SetPixelSize, nodefault};
	__property Frxbarcodedatamatrix::DatamatrixSymbolSize SymbolSize = {read=GetSymbolSize, write=SetSymbolSize, nodefault};
	__property Frxbarcodedatamatrix::DatamatrixEncoding Encoding = {read=GetEncoding, write=SetEncoding, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TfrxDataMatrixProperties(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TfrxDataMatrixProperties(void) : TfrxBarcode2DProperties() { }
	
};


class PASCALIMPLEMENTATION TfrxQRProperties : public TfrxBarcode2DProperties
{
	typedef TfrxBarcode2DProperties inherited;
	
private:
	Frxdelphizxingqrcode::TQRCodeEncoding __fastcall GetEncoding(void);
	int __fastcall GetQuietZone(void);
	int __fastcall GetPixelSize(void);
	void __fastcall SetPixelSize(int v);
	void __fastcall SetEncoding(const Frxdelphizxingqrcode::TQRCodeEncoding Value);
	void __fastcall SetQuietZone(const int Value);
	Frxdelphizxingqrcode::TQRErrorLevels __fastcall GetErrorLevels(void);
	void __fastcall SetErrorLevels(const Frxdelphizxingqrcode::TQRErrorLevels Value);
	int __fastcall GetCodePage(void);
	void __fastcall SetCodePage(const int Value);
	
public:
	virtual void __fastcall Assign(System::Classes::TPersistent* Source);
	
__published:
	__property Frxdelphizxingqrcode::TQRCodeEncoding Encoding = {read=GetEncoding, write=SetEncoding, nodefault};
	__property int QuietZone = {read=GetQuietZone, write=SetQuietZone, nodefault};
	__property Frxdelphizxingqrcode::TQRErrorLevels ErrorLevels = {read=GetErrorLevels, write=SetErrorLevels, nodefault};
	__property int PixelSize = {read=GetPixelSize, write=SetPixelSize, nodefault};
	__property int CodePage = {read=GetCodePage, write=SetCodePage, nodefault};
public:
	/* TPersistent.Destroy */ inline __fastcall virtual ~TfrxQRProperties(void) { }
	
public:
	/* TObject.Create */ inline __fastcall TfrxQRProperties(void) : TfrxBarcode2DProperties() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Frxbarcodeproperties */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXBARCODEPROPERTIES)
using namespace Frxbarcodeproperties;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxbarcodepropertiesHPP

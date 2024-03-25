// CodeGear C++Builder
// Copyright (c) 1995, 2016 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxExportHelpers.pas' rev: 32.00 (Windows)

#ifndef FrxexporthelpersHPP
#define FrxexporthelpersHPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>
#include <SysInit.hpp>
#include <Winapi.Windows.hpp>
#include <System.Classes.hpp>
#include <Vcl.Graphics.hpp>
#include <frxClass.hpp>
#include <System.UITypes.hpp>
#include <frxCrypto.hpp>
#include <frxStorage.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxexporthelpers
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TfrxCSSStyle;
class DELPHICLASS TfrxCSS;
struct TfrxPictureInfo;
class DELPHICLASS TfrxPictureStorage;
class DELPHICLASS TfrxPicture;
//-- type declarations -------------------------------------------------------
#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxCSSStyle : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::UnicodeString operator[](System::UnicodeString Index) { return this->Style[Index]; }
	
private:
	System::Classes::TStrings* FKeys;
	System::Classes::TStrings* FValues;
	System::UnicodeString FName;
	void __fastcall SetStyle(System::UnicodeString Index, const System::UnicodeString Value);
	void __fastcall SetPrefixStyle(System::UnicodeString Index, const System::UnicodeString Value);
	System::UnicodeString __fastcall GetStyle(System::UnicodeString Index);
	
public:
	__fastcall TfrxCSSStyle(void);
	__fastcall virtual ~TfrxCSSStyle(void);
	TfrxCSSStyle* __fastcall This(void);
	int __fastcall Count(void);
	System::UnicodeString __fastcall Text(bool Formatted = false);
	void __fastcall AssignTo(TfrxCSSStyle* Dest);
	__property System::UnicodeString Style[System::UnicodeString Index] = {read=GetStyle, write=SetStyle/*, default*/};
	__property System::UnicodeString PrefixStyle[System::UnicodeString Index] = {write=SetPrefixStyle};
	__property System::UnicodeString Name = {read=FName, write=FName};
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxCSS : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	Frxstorage::TObjList* FStyles;
	System::Classes::TList* FStyleHashes;
	
protected:
	TfrxCSSStyle* __fastcall GetStyle(int i);
	int __fastcall GetHash(const System::UnicodeString s);
	System::UnicodeString __fastcall GetStyleName(int i);
	int __fastcall GetStylesCount(void);
	
public:
	__fastcall TfrxCSS(void);
	__fastcall virtual ~TfrxCSS(void);
	TfrxCSSStyle* __fastcall Style(const System::UnicodeString StyleName);
	System::UnicodeString __fastcall Add(TfrxCSSStyle* Style)/* overload */;
	TfrxCSSStyle* __fastcall Add(const System::UnicodeString StyleName)/* overload */;
	void __fastcall Save(System::Classes::TStream* Stream, bool Formatted);
};

#pragma pack(pop)

struct DECLSPEC_DRECORD TfrxPictureInfo
{
public:
	System::UnicodeString Extension;
	System::UnicodeString Mimetype;
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxPictureStorage : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	System::UnicodeString FWorkDir;
	System::UnicodeString FPrefix;
	System::Classes::TList* FHashes;
	
protected:
	int __fastcall GetHash(System::Classes::TMemoryStream* Stream);
	
public:
	__fastcall TfrxPictureStorage(const System::UnicodeString WorkDir, System::UnicodeString Prefix);
	__fastcall virtual ~TfrxPictureStorage(void);
	System::UnicodeString __fastcall Save(Vcl::Graphics::TGraphic* Pic);
	__classmethod TfrxPictureInfo __fastcall GetInfo(Vcl::Graphics::TGraphic* Pic);
};

#pragma pack(pop)

enum DECLSPEC_DENUM TfrxPictureFormat : unsigned char { pfPNG, pfEMF, pfBMP, pfJPG };

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxPicture : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	TfrxPictureFormat FFormat;
	Vcl::Graphics::TGraphic* FGraphic;
	Vcl::Graphics::TCanvas* FCanvas;
	Vcl::Graphics::TBitmap* FBitmap;
	
public:
	__fastcall TfrxPicture(TfrxPictureFormat Format, int Width, int Height);
	__fastcall virtual ~TfrxPicture(void);
	Vcl::Graphics::TGraphic* __fastcall Release(void);
	void __fastcall SetTransparentColor(System::Uitypes::TColor TransparentColor);
	void __fastcall FillColor(System::Uitypes::TColor Color);
	__property Vcl::Graphics::TCanvas* Canvas = {read=FCanvas};
};

#pragma pack(pop)

typedef bool __fastcall (__closure *TfrxExportHandler)(Frxclass::TfrxView* Obj);

//-- var, const, procedure ---------------------------------------------------
extern DELPHI_PACKAGE System::UnicodeString __fastcall StrFindAndReplace(const System::UnicodeString Source, const System::UnicodeString Dlm, System::UnicodeString *SFR, const int SFR_High);
extern DELPHI_PACKAGE bool __fastcall HasSpecialChars(const System::UnicodeString s);
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetBorderRadius(int Curve);
extern DELPHI_PACKAGE System::UnicodeString __fastcall GetColor(System::Uitypes::TColor Color);
extern DELPHI_PACKAGE System::UnicodeString __fastcall IfStr(bool Flag, const System::UnicodeString sTrue, System::UnicodeString sFalse = System::UnicodeString());
}	/* namespace Frxexporthelpers */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXEXPORTHELPERS)
using namespace Frxexporthelpers;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxexporthelpersHPP

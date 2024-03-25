// CodeGear C++Builder
// Copyright (c) 1995, 2016 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxExportHTMLDiv.pas' rev: 32.00 (Windows)

#ifndef FrxexporthtmldivHPP
#define FrxexporthtmldivHPP

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
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Winapi.ShellAPI.hpp>
#include <Vcl.Graphics.hpp>
#include <Vcl.ComCtrls.hpp>
#include <frxClass.hpp>
#include <frxCrypto.hpp>
#include <frxStorage.hpp>
#include <frxGradient.hpp>
#include <frxExportHelpers.hpp>
#include <System.UITypes.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxexporthtmldiv
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TfrxHTMLDivExportDialog;
class DELPHICLASS TfrxHTMLItem;
class DELPHICLASS TfrxHTMLItemQueue;
class DELPHICLASS TfrxBoundsGauge;
class DELPHICLASS TfrxHTMLDivExport;
class DELPHICLASS TfrxHTML5DivExport;
class DELPHICLASS TfrxHTML4DivExport;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TfrxHTMLDivExportDialog : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Stdctrls::TButton* OkB;
	Vcl::Stdctrls::TButton* CancelB;
	Vcl::Stdctrls::TGroupBox* GroupPageRange;
	Vcl::Stdctrls::TLabel* DescrL;
	Vcl::Stdctrls::TRadioButton* AllRB;
	Vcl::Stdctrls::TRadioButton* CurPageRB;
	Vcl::Stdctrls::TRadioButton* PageNumbersRB;
	Vcl::Stdctrls::TEdit* PageNumbersE;
	Vcl::Stdctrls::TGroupBox* gbOptions;
	Vcl::Stdctrls::TCheckBox* OpenCB;
	Vcl::Dialogs::TSaveDialog* sd;
	Vcl::Stdctrls::TGroupBox* GroupQuality;
	Vcl::Stdctrls::TLabel* PicturesL;
	Vcl::Stdctrls::TCheckBox* StylesCB;
	Vcl::Stdctrls::TCheckBox* UnifiedPicturesCB;
	Vcl::Stdctrls::TCheckBox* PicturesCB;
	Vcl::Stdctrls::TCheckBox* MultipageCB;
	Vcl::Stdctrls::TComboBox* PFormatCB;
	Vcl::Stdctrls::TCheckBox* FormattedCB;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall PageNumbersEChange(System::TObject* Sender);
	void __fastcall PageNumbersEKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrxHTMLDivExportDialog(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxHTMLDivExportDialog(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrxHTMLDivExportDialog(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxHTMLDivExportDialog(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TfrxHTMLItem : public System::TObject
{
	typedef System::TObject inherited;
	
public:
	System::UnicodeString operator[](System::UnicodeString Index) { return this->Prop[Index]; }
	
private:
	System::UnicodeString FName;
	System::Classes::TStrings* FKeys;
	System::Classes::TStrings* FValues;
	System::UnicodeString FValue;
	Frxstorage::TObjList* FChildren;
	System::Extended FLeft;
	System::Extended FTop;
	System::Extended FWidth;
	System::Extended FHeight;
	bool FLeftSet;
	bool FTopSet;
	bool FWidthSet;
	bool FHeightSet;
	Frxexporthelpers::TfrxCSSStyle* FStyle;
	System::UnicodeString FClass;
	void __fastcall SetProp(System::UnicodeString Index, const System::UnicodeString Value);
	Frxexporthelpers::TfrxCSSStyle* __fastcall GetStyle(void);
	void __fastcall SetLeft(System::Extended a);
	void __fastcall SetTop(System::Extended a);
	void __fastcall SetWidth(System::Extended a);
	void __fastcall SetHeight(System::Extended a);
	System::UnicodeString __fastcall GetProp(System::UnicodeString Index);
	
public:
	__fastcall TfrxHTMLItem(const System::UnicodeString Name);
	__fastcall virtual ~TfrxHTMLItem(void);
	TfrxHTMLItem* __fastcall This(void);
	System::UnicodeString __fastcall EscapeAttribute(const System::UnicodeString s);
	void __fastcall Save(System::Classes::TStream* Stream, bool Formatted);
	TfrxHTMLItem* __fastcall Add(const System::UnicodeString Tag)/* overload */;
	TfrxHTMLItem* __fastcall Add(TfrxHTMLItem* Item)/* overload */;
	void __fastcall AddCSSClass(const System::UnicodeString s);
	__property System::UnicodeString Prop[System::UnicodeString Index] = {read=GetProp, write=SetProp/*, default*/};
	__property System::UnicodeString Value = {write=FValue};
	__property System::UnicodeString Name = {write=FName};
	__property Frxexporthelpers::TfrxCSSStyle* Style = {read=GetStyle};
	__property System::Extended Left = {read=FLeft, write=SetLeft};
	__property System::Extended Top = {read=FTop, write=SetTop};
	__property System::Extended Width = {read=FWidth, write=SetWidth};
	__property System::Extended Height = {read=FHeight, write=SetHeight};
};


#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxHTMLItemQueue : public System::TObject
{
	typedef System::TObject inherited;
	
	
private:
	typedef System::DynamicArray<TfrxHTMLItem*> _TfrxHTMLItemQueue__1;
	
	
private:
	_TfrxHTMLItemQueue__1 FQueue;
	int FUsed;
	System::Classes::TStream* FStream;
	bool FFormatted;
	
protected:
	void __fastcall Flush(void);
	
public:
	__fastcall TfrxHTMLItemQueue(System::Classes::TStream* Stream, bool Formatted);
	__fastcall virtual ~TfrxHTMLItemQueue(void);
	void __fastcall Push(TfrxHTMLItem* Item);
	void __fastcall SetQueueLength(int n);
};

#pragma pack(pop)

#pragma pack(push,4)
class PASCALIMPLEMENTATION TfrxBoundsGauge : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	Frxclass::TfrxView* FObj;
	bool FBoundsSet;
	System::Types::TRect FBounds;
	System::Types::TRect FBorders;
	int FX;
	int FY;
	int FX1;
	int FY1;
	int FDX;
	int FDY;
	int FFrameWidth;
	void __fastcall SetObj(Frxclass::TfrxView* Obj);
	void __fastcall AddBounds(const System::Types::TRect &r);
	int __fastcall GetInnerWidth(void);
	int __fastcall GetInnerHeight(void);
	
protected:
	void __fastcall BeginDraw(void);
	void __fastcall DrawBackground(void);
	void __fastcall DrawFrame(void);
	void __fastcall DrawLine(int x1, int y1, int x2, int y2, int w, Frxclass::TfrxFrameType Side);
	
public:
	__property Frxclass::TfrxView* Obj = {read=FObj, write=SetObj};
	__property System::Types::TRect Bounds = {read=FBounds};
	__property System::Types::TRect Borders = {read=FBorders};
	__property int InnerWidth = {read=GetInnerWidth, nodefault};
	__property int InnerHeight = {read=GetInnerHeight, nodefault};
public:
	/* TObject.Create */ inline __fastcall TfrxBoundsGauge(void) : System::TObject() { }
	/* TObject.Destroy */ inline __fastcall virtual ~TfrxBoundsGauge(void) { }
	
};

#pragma pack(pop)

class PASCALIMPLEMENTATION TfrxHTMLDivExport : public Frxclass::TfrxCustomExportFilter
{
	typedef Frxclass::TfrxCustomExportFilter inherited;
	
	
private:
	typedef System::DynamicArray<Frxexporthelpers::TfrxExportHandler> _TfrxHTMLDivExport__1;
	
	
private:
	bool FOpenAfterExport;
	System::UnicodeString FTitle;
	bool FHTML5;
	bool FMultiPage;
	bool FFormatted;
	Frxexporthelpers::TfrxPictureFormat FPicFormat;
	bool FAllPictures;
	bool FUnifiedPictures;
	Frxexporthelpers::TfrxCSSStyle* FPageStyle;
	bool FNavigation;
	bool FExportAnchors;
	bool FEmbeddedPictures;
	bool FEmbeddedCSS;
	int FPictureTag;
	System::Classes::TStream* FCurrentHTMLFile;
	int FCurrentPage;
	Frxexporthelpers::TfrxCSS* FCSS;
	TfrxHTMLItemQueue* FQueue;
	Frxexporthelpers::TfrxPictureStorage* FPictures;
	_TfrxHTMLDivExport__1 FHandlers;
	TfrxBoundsGauge* FGauge;
	System::UnicodeString FPictureFolder;
	void __fastcall SetPicFormat(Frxexporthelpers::TfrxPictureFormat Fmt);
	Frxexporthelpers::TfrxCSSStyle* __fastcall GetPageStyle(void);
	bool __fastcall GetAnchor(System::UnicodeString &Page, const System::UnicodeString Name);
	System::UnicodeString __fastcall GetHRef(const System::UnicodeString URL);
	System::UnicodeString __fastcall GetCSSFileName(void);
	System::UnicodeString __fastcall GetCSSFilePath(void);
	void __fastcall SaveCSS(const System::UnicodeString FileName);
	void __fastcall PutsRaw(const System::AnsiString s);
	void __fastcall PutImg(Frxclass::TfrxView* Obj, Vcl::Graphics::TGraphic* Pic, bool WriteSize);
	void __fastcall RunExportsChain(Frxclass::TfrxView* Obj);
	void __fastcall StartHTML(void);
	void __fastcall EndHTML(void);
	bool __fastcall ExportTaggedView(Frxclass::TfrxView* Obj);
	bool __fastcall ExportAllPictures(Frxclass::TfrxView* Obj);
	bool __fastcall ExportMemo(Frxclass::TfrxView* Obj);
	bool __fastcall ExportPicture(Frxclass::TfrxView* Obj);
	bool __fastcall ExportRectangle(Frxclass::TfrxView* Obj);
	bool __fastcall ExportLine(Frxclass::TfrxView* Obj);
	bool __fastcall ExportShape(Frxclass::TfrxView* Obj);
	bool __fastcall ExportGradient(Frxclass::TfrxView* Obj);
	bool __fastcall ExportRich(Frxclass::TfrxView* Obj);
	bool __fastcall ExportAsPicture(Frxclass::TfrxView* Obj);
	void __fastcall SetPictureFolder(const System::UnicodeString Value);
	
protected:
	void __fastcall PutsA(const System::AnsiString s);
	void __fastcall Puts(const System::UnicodeString s)/* overload */;
	void __fastcall Puts(const System::UnicodeString Fmt, const System::TVarRec *Args, const int Args_High)/* overload */;
	TfrxHTMLItem* __fastcall AddTag(const System::UnicodeString Name);
	System::UnicodeString __fastcall LockStyle(Frxexporthelpers::TfrxCSSStyle* Style);
	TfrxHTMLItem* __fastcall CreateDiv(Frxclass::TfrxView* Obj, bool DrawFrame = true);
	TfrxHTMLItem* __fastcall CreateFrameDiv(Frxclass::TfrxView* Obj, bool DrawFrame = true);
	TfrxHTMLItem* __fastcall CreateFillDiv(Frxclass::TfrxView* Obj);
	void __fastcall FillFrameProps(Frxexporthelpers::TfrxCSSStyle* Style, Frxclass::TfrxFrame* Frame);
	void __fastcall FillGraduienProps(Frxexporthelpers::TfrxCSSStyle* Style, System::Uitypes::TColor BeginColor, System::Uitypes::TColor EndColor, Frxgradient::TfrxGradientStyle GradientStyle);
	System::UnicodeString __fastcall FilterHTML(const System::UnicodeString Text);
	System::UnicodeString __fastcall EscapeText(const System::UnicodeString s);
	System::UnicodeString __fastcall DoHyperLink(System::UnicodeString Text, Frxclass::TfrxView* Obj);
	void __fastcall DoExportAsPicture(Frxclass::TfrxView* Obj, bool Transparent, System::Uitypes::TColor TransparentColor = (System::Uitypes::TColor)(0x1fffffff));
	
public:
	__fastcall virtual TfrxHTMLDivExport(System::Classes::TComponent* AOwner);
	__fastcall virtual ~TfrxHTMLDivExport(void);
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
	virtual System::Uitypes::TModalResult __fastcall ShowModal(void);
	virtual bool __fastcall Start(void);
	virtual void __fastcall StartPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall ExportObject(Frxclass::TfrxComponent* Obj);
	virtual void __fastcall FinishPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall Finish(void);
	void __fastcall AttachHandler(Frxexporthelpers::TfrxExportHandler Handler);
	__property Frxexporthelpers::TfrxCSSStyle* PageStyle = {read=GetPageStyle};
	__property System::UnicodeString PictureFolder = {read=FPictureFolder, write=SetPictureFolder};
	
__published:
	__property OverwritePrompt;
	__property bool OpenAfterExport = {read=FOpenAfterExport, write=FOpenAfterExport, nodefault};
	__property System::UnicodeString Title = {read=FTitle, write=FTitle};
	__property bool HTML5 = {read=FHTML5, write=FHTML5, nodefault};
	__property bool MultiPage = {read=FMultiPage, write=FMultiPage, nodefault};
	__property bool Formatted = {read=FFormatted, write=FFormatted, nodefault};
	__property Frxexporthelpers::TfrxPictureFormat PictureFormat = {read=FPicFormat, write=SetPicFormat, nodefault};
	__property bool AllPictures = {read=FAllPictures, write=FAllPictures, nodefault};
	__property bool UnifiedPictures = {read=FUnifiedPictures, write=FUnifiedPictures, nodefault};
	__property bool EmbeddedPictures = {read=FEmbeddedPictures, write=FEmbeddedPictures, nodefault};
	__property bool Navigation = {read=FNavigation, write=FNavigation, nodefault};
	__property bool ExportAnchors = {read=FExportAnchors, write=FExportAnchors, nodefault};
	__property bool EmbeddedCSS = {read=FEmbeddedCSS, write=FEmbeddedCSS, nodefault};
	__property int PictureTag = {read=FPictureTag, write=FPictureTag, nodefault};
public:
	/* TfrxCustomExportFilter.CreateNoRegister */ inline __fastcall TfrxHTMLDivExport(void) : Frxclass::TfrxCustomExportFilter() { }
	
};


class PASCALIMPLEMENTATION TfrxHTML5DivExport : public TfrxHTMLDivExport
{
	typedef TfrxHTMLDivExport inherited;
	
public:
	__fastcall virtual TfrxHTML5DivExport(System::Classes::TComponent* AOwner);
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
public:
	/* TfrxHTMLDivExport.Destroy */ inline __fastcall virtual ~TfrxHTML5DivExport(void) { }
	
public:
	/* TfrxCustomExportFilter.CreateNoRegister */ inline __fastcall TfrxHTML5DivExport(void) : TfrxHTMLDivExport() { }
	
};


class PASCALIMPLEMENTATION TfrxHTML4DivExport : public TfrxHTMLDivExport
{
	typedef TfrxHTMLDivExport inherited;
	
public:
	__fastcall virtual TfrxHTML4DivExport(System::Classes::TComponent* AOwner);
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
public:
	/* TfrxHTMLDivExport.Destroy */ inline __fastcall virtual ~TfrxHTML4DivExport(void) { }
	
public:
	/* TfrxCustomExportFilter.CreateNoRegister */ inline __fastcall TfrxHTML4DivExport(void) : TfrxHTMLDivExport() { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Frxexporthtmldiv */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXEXPORTHTMLDIV)
using namespace Frxexporthtmldiv;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxexporthtmldivHPP

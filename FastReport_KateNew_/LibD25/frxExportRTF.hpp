// CodeGear C++Builder
// Copyright (c) 1995, 2016 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxExportRTF.pas' rev: 32.00 (Windows)

#ifndef FrxexportrtfHPP
#define FrxexportrtfHPP

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
#include <Vcl.Controls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <System.Win.ComObj.hpp>
#include <Vcl.Printers.hpp>
#include <frxClass.hpp>
#include <Winapi.ShellAPI.hpp>
#include <frxExportMatrix.hpp>
#include <System.Variants.hpp>
#include <frxProgress.hpp>
#include <Vcl.ComCtrls.hpp>
#include <frxGraphicUtils.hpp>
#include <frxImageConverter.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxexportrtf
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TfrxRTFExportDialog;
class DELPHICLASS TfrxRTFExport;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TfrxHeaderFooterMode : unsigned char { hfText, hfPrint, hfNone };

class PASCALIMPLEMENTATION TfrxRTFExportDialog : public Vcl::Forms::TForm
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
	Vcl::Stdctrls::TGroupBox* GroupQuality;
	Vcl::Stdctrls::TCheckBox* WCB;
	Vcl::Stdctrls::TCheckBox* PageBreaksCB;
	Vcl::Stdctrls::TCheckBox* PicturesCB;
	Vcl::Stdctrls::TCheckBox* OpenCB;
	Vcl::Dialogs::TSaveDialog* SaveDialog1;
	Vcl::Stdctrls::TCheckBox* ContinuousCB;
	Vcl::Stdctrls::TLabel* HeadFootL;
	Vcl::Stdctrls::TComboBox* PColontitulCB;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall PageNumbersEChange(System::TObject* Sender);
	void __fastcall PageNumbersEKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrxRTFExportDialog(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxRTFExportDialog(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrxRTFExportDialog(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxRTFExportDialog(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TfrxRTFExport : public Frxclass::TfrxCustomExportFilter
{
	typedef Frxclass::TfrxCustomExportFilter inherited;
	
private:
	System::Classes::TStringList* FColorTable;
	int FCurrentPage;
	System::Classes::TList* FDataList;
	bool FExportPageBreaks;
	bool FExportPictures;
	bool FFirstPage;
	System::Classes::TStringList* FFontTable;
	System::Classes::TStringList* FCharsetTable;
	Frxexportmatrix::TfrxIEMatrix* FMatrix;
	bool FOpenAfterExport;
	Frxprogress::TfrxProgress* FProgress;
	bool FWysiwyg;
	System::UnicodeString FCreator;
	TfrxHeaderFooterMode FHeaderFooterMode;
	bool FAutoSize;
	Frximageconverter::TfrxPictureType FPictureType;
	System::WideString __fastcall TruncReturns(const System::WideString Str);
	System::UnicodeString __fastcall GetRTFBorders(Frxexportmatrix::TfrxIEMStyle* const Style);
	System::UnicodeString __fastcall GetRTFColor(const unsigned c);
	System::UnicodeString __fastcall GetRTFFontStyle(const System::Uitypes::TFontStyles f);
	System::UnicodeString __fastcall GetRTFFontColor(const System::UnicodeString f);
	System::UnicodeString __fastcall GetRTFFontName(const System::UnicodeString f, const int charset);
	System::UnicodeString __fastcall GetRTFHAlignment(const Frxclass::TfrxHAlign HAlign);
	System::UnicodeString __fastcall GetRTFVAlignment(const Frxclass::TfrxVAlign VAlign);
	System::WideString __fastcall StrToRTFSlash(const System::WideString Value);
	System::UnicodeString __fastcall StrToRTFUnicodeEx(const System::WideString Value);
	System::UnicodeString __fastcall StrToRTFUnicode(const System::WideString Value);
	void __fastcall ExportPage(System::Classes::TStream* const Stream);
	void __fastcall PrepareExport(void);
	void __fastcall SaveGraphic(Vcl::Graphics::TGraphic* Graphic, System::Classes::TStream* Stream, System::Extended Width, System::Extended Height, Frximageconverter::TfrxPictureType PicType);
	
public:
	__fastcall virtual TfrxRTFExport(System::Classes::TComponent* AOwner);
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
	virtual System::Uitypes::TModalResult __fastcall ShowModal(void);
	virtual bool __fastcall Start(void);
	virtual void __fastcall Finish(void);
	virtual void __fastcall FinishPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall StartPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall ExportObject(Frxclass::TfrxComponent* Obj);
	
__published:
	__property Frximageconverter::TfrxPictureType PictureType = {read=FPictureType, write=FPictureType, nodefault};
	__property bool ExportPageBreaks = {read=FExportPageBreaks, write=FExportPageBreaks, default=1};
	__property bool ExportPictures = {read=FExportPictures, write=FExportPictures, default=1};
	__property bool OpenAfterExport = {read=FOpenAfterExport, write=FOpenAfterExport, default=0};
	__property bool Wysiwyg = {read=FWysiwyg, write=FWysiwyg, nodefault};
	__property System::UnicodeString Creator = {read=FCreator, write=FCreator};
	__property SuppressPageHeadersFooters;
	__property TfrxHeaderFooterMode HeaderFooterMode = {read=FHeaderFooterMode, write=FHeaderFooterMode, nodefault};
	__property bool AutoSize = {read=FAutoSize, write=FAutoSize, nodefault};
	__property OverwritePrompt;
public:
	/* TfrxCustomExportFilter.CreateNoRegister */ inline __fastcall TfrxRTFExport(void) : Frxclass::TfrxCustomExportFilter() { }
	/* TfrxCustomExportFilter.Destroy */ inline __fastcall virtual ~TfrxRTFExport(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Frxexportrtf */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXEXPORTRTF)
using namespace Frxexportrtf;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxexportrtfHPP

// CodeGear C++Builder
// Copyright (c) 1995, 2016 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxExportXLS.pas' rev: 32.00 (Windows)

#ifndef FrxexportxlsHPP
#define FrxexportxlsHPP

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
#include <Vcl.Printers.hpp>
#include <System.Win.ComObj.hpp>
#include <frxClass.hpp>
#include <frxProgress.hpp>
#include <frxExportMatrix.hpp>
#include <Vcl.Clipbrd.hpp>
#include <Winapi.ActiveX.hpp>
#include <System.Variants.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxexportxls
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TfrxXLSExportDialog;
class DELPHICLASS TfrxXLSExport;
class DELPHICLASS TfrxExcel;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TfrxXLSExportDialog : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Stdctrls::TButton* OkB;
	Vcl::Stdctrls::TButton* CancelB;
	Vcl::Dialogs::TSaveDialog* SaveDialog1;
	Vcl::Stdctrls::TGroupBox* GroupPageRange;
	Vcl::Stdctrls::TLabel* DescrL;
	Vcl::Stdctrls::TRadioButton* AllRB;
	Vcl::Stdctrls::TRadioButton* CurPageRB;
	Vcl::Stdctrls::TRadioButton* PageNumbersRB;
	Vcl::Stdctrls::TEdit* PageNumbersE;
	Vcl::Stdctrls::TGroupBox* GroupQuality;
	Vcl::Stdctrls::TCheckBox* MergeCB;
	Vcl::Stdctrls::TCheckBox* WCB;
	Vcl::Stdctrls::TCheckBox* ContinuousCB;
	Vcl::Stdctrls::TCheckBox* PicturesCB;
	Vcl::Stdctrls::TCheckBox* OpenExcelCB;
	Vcl::Stdctrls::TCheckBox* AsTextCB;
	Vcl::Stdctrls::TCheckBox* BackgrCB;
	Vcl::Stdctrls::TCheckBox* FastExpCB;
	Vcl::Stdctrls::TCheckBox* PageBreaksCB;
	Vcl::Stdctrls::TCheckBox* cbGrid;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall PageNumbersEChange(System::TObject* Sender);
	void __fastcall PageNumbersEKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrxXLSExportDialog(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxXLSExportDialog(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrxXLSExportDialog(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxXLSExportDialog(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TfrxXLSExport : public Frxclass::TfrxCustomExportFilter
{
	typedef Frxclass::TfrxCustomExportFilter inherited;
	
private:
	TfrxExcel* FExcel;
	bool FExportPictures;
	bool FExportStyles;
	bool FFirstPage;
	Frxexportmatrix::TfrxIEMatrix* FMatrix;
	bool FMergeCells;
	bool FOpenExcelAfterExport;
	System::Extended FPageBottom;
	System::Extended FPageLeft;
	System::Extended FPageRight;
	System::Extended FPageTop;
	System::Uitypes::TPrinterOrientation FPageOrientation;
	Frxprogress::TfrxProgress* FProgress;
	bool FWysiwyg;
	bool FAsText;
	bool FBackground;
	bool FFastExport;
	bool FpageBreaks;
	bool FEmptyLines;
	bool FExportEMF;
	bool FTruncateLongTexts;
	bool FGridLines;
	void __fastcall ExportPage_Fast(void);
	void __fastcall ExportPage(void);
	System::WideString __fastcall CleanReturns(const System::WideString Str);
	System::Byte __fastcall FrameTypesToByte(Frxclass::TfrxFrameTypes Value);
	int __fastcall GetNewIndex(System::Classes::TStrings* Strings, int ObjValue);
	System::Extended __fastcall GetObjWidth(Frxexportmatrix::TfrxIEMObject* Obj);
	System::Extended __fastcall GetObjHeight(Frxexportmatrix::TfrxIEMObject* Obj);
	
public:
	__fastcall virtual TfrxXLSExport(System::Classes::TComponent* AOwner);
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
	virtual System::Uitypes::TModalResult __fastcall ShowModal(void);
	virtual bool __fastcall Start(void);
	virtual void __fastcall Finish(void);
	virtual void __fastcall FinishPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall StartPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall ExportObject(Frxclass::TfrxComponent* Obj);
	
__published:
	__property bool ExportEMF = {read=FExportEMF, write=FExportEMF, nodefault};
	__property bool ExportStyles = {read=FExportStyles, write=FExportStyles, default=1};
	__property bool ExportPictures = {read=FExportPictures, write=FExportPictures, default=1};
	__property bool MergeCells = {read=FMergeCells, write=FMergeCells, default=1};
	__property bool OpenExcelAfterExport = {read=FOpenExcelAfterExport, write=FOpenExcelAfterExport, default=0};
	__property bool Wysiwyg = {read=FWysiwyg, write=FWysiwyg, default=1};
	__property bool AsText = {read=FAsText, write=FAsText, nodefault};
	__property bool Background = {read=FBackground, write=FBackground, nodefault};
	__property bool FastExport = {read=FFastExport, write=FFastExport, nodefault};
	__property bool PageBreaks = {read=FpageBreaks, write=FpageBreaks, nodefault};
	__property bool EmptyLines = {read=FEmptyLines, write=FEmptyLines, nodefault};
	__property SuppressPageHeadersFooters;
	__property OverwritePrompt;
	__property bool TruncateLongTexts = {read=FTruncateLongTexts, write=FTruncateLongTexts, default=1};
	__property bool GridLines = {read=FGridLines, write=FGridLines, default=1};
public:
	/* TfrxCustomExportFilter.CreateNoRegister */ inline __fastcall TfrxXLSExport(void) : Frxclass::TfrxCustomExportFilter() { }
	/* TfrxCustomExportFilter.Destroy */ inline __fastcall virtual ~TfrxXLSExport(void) { }
	
};


class PASCALIMPLEMENTATION TfrxExcel : public System::TObject
{
	typedef System::TObject inherited;
	
private:
	bool FIsOpened;
	bool FIsVisible;
	System::Variant Excel;
	System::Variant WorkBook;
	System::Variant WorkSheet;
	System::Variant Range;
	Frxclass::TfrxFrameTypes __fastcall ByteToFrameTypes(System::Byte Value);
	
protected:
	System::UnicodeString __fastcall IntToCoord(int X, int Y);
	System::UnicodeString __fastcall Pos2Str(int Pos);
	void __fastcall SetVisible(bool DoShow);
	void __fastcall ApplyStyles(System::Classes::TStrings* aRanges, System::Byte Kind, Frxprogress::TfrxProgress* aProgress);
	void __fastcall ApplyFrame(const System::UnicodeString RangeCoord, System::Byte aFrame);
	void __fastcall SetRowsSize(System::Classes::TStrings* aRanges, System::Currency *Sizes, const int Sizes_High, int MainSizeIndex, int RowsCount, Frxprogress::TfrxProgress* aProgress);
	void __fastcall ApplyStyle(const System::UnicodeString RangeCoord, int aStyle);
	void __fastcall ApplyFormats(System::Classes::TStringList* aRanges, Frxprogress::TfrxProgress* aProgress);
	void __fastcall ApplyFormat(const System::UnicodeString RangeCoord, const System::UnicodeString aFormat);
	
public:
	__fastcall TfrxExcel(void);
	__fastcall virtual ~TfrxExcel(void);
	void __fastcall MergeCells(void);
	void __fastcall SetCellFrame(Frxclass::TfrxFrameTypes Frame);
	void __fastcall SetRowSize(int y, System::Extended Size);
	void __fastcall OpenExcel(void);
	void __fastcall SetColSize(int x, System::Extended Size);
	void __fastcall SetPageMargin(System::Extended Left, System::Extended Right, System::Extended Top, System::Extended Bottom, System::Uitypes::TPrinterOrientation Orientation);
	void __fastcall SetRange(int x, int y, int dx, int dy);
	__property bool Visible = {read=FIsVisible, write=SetVisible, nodefault};
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Frxexportxls */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXEXPORTXLS)
using namespace Frxexportxls;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxexportxlsHPP

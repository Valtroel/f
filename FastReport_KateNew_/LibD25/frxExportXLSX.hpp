// CodeGear C++Builder
// Copyright (c) 1995, 2016 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxExportXLSX.pas' rev: 32.00 (Windows)

#ifndef FrxexportxlsxHPP
#define FrxexportxlsxHPP

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
#include <System.Types.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <frxClass.hpp>
#include <frxExportMatrix.hpp>
#include <Winapi.ShellAPI.hpp>
#include <Vcl.ComCtrls.hpp>
#include <frxZip.hpp>
#include <frxOfficeOpen.hpp>
#include <frxImageConverter.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxexportxlsx
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TfrxXLSXExportDialog;
class DELPHICLASS TfrxXLSXExport;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TfrxXLSXExportDialog : public Vcl::Forms::TForm
{
	typedef Vcl::Forms::TForm inherited;
	
__published:
	Vcl::Stdctrls::TButton* OkB;
	Vcl::Stdctrls::TButton* CancelB;
	Vcl::Dialogs::TSaveDialog* sd;
	Vcl::Stdctrls::TGroupBox* GroupPageRange;
	Vcl::Stdctrls::TLabel* DescrL;
	Vcl::Stdctrls::TRadioButton* AllRB;
	Vcl::Stdctrls::TRadioButton* CurPageRB;
	Vcl::Stdctrls::TRadioButton* PageNumbersRB;
	Vcl::Stdctrls::TEdit* PageNumbersE;
	Vcl::Stdctrls::TGroupBox* GroupOptions;
	Vcl::Stdctrls::TCheckBox* ContinuousCB;
	Vcl::Stdctrls::TGroupBox* SplitToSheetGB;
	Vcl::Stdctrls::TRadioButton* RPagesRB;
	Vcl::Stdctrls::TRadioButton* NotSplitRB;
	Vcl::Stdctrls::TRadioButton* RowsCountRB;
	Vcl::Stdctrls::TEdit* edChunk;
	Vcl::Stdctrls::TCheckBox* OpenCB;
	Vcl::Stdctrls::TCheckBox* PageBreaksCB;
	Vcl::Stdctrls::TCheckBox* WCB;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall PageNumbersEChange(System::TObject* Sender);
	void __fastcall PageNumbersEKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrxXLSXExportDialog(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxXLSXExportDialog(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrxXLSXExportDialog(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxXLSXExportDialog(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TfrxXLSXExport : public Frxclass::TfrxCustomExportFilter
{
	typedef Frxclass::TfrxCustomExportFilter inherited;
	
private:
	bool FExportPageBreaks;
	bool FEmptyLines;
	bool FOpenAfterExport;
	Frxexportmatrix::TfrxIEMatrix* FMatrix;
	System::UnicodeString FDocFolder;
	System::Classes::TStream* FContentTypes;
	System::Classes::TStream* FRels;
	System::Classes::TStream* FStyles;
	System::Classes::TStream* FWorkbook;
	System::Classes::TStream* FSharedStrings;
	System::Classes::TStream* FWorkbookRels;
	System::Classes::TStrings* FFonts;
	System::Classes::TStrings* FFills;
	System::Classes::TStrings* FBorders;
	System::Classes::TStrings* FCellStyleXfs;
	System::Classes::TStrings* FCellXfs;
	System::Classes::TList* FColors;
	System::Classes::TStrings* FNumFmts;
	System::Classes::TStrings* FStrings;
	int FStringsCount;
	bool FSingleSheet;
	int FChunkSize;
	Frxofficeopen::TfrxMap FLastPage;
	bool FWysiwyg;
	Frximageconverter::TfrxPictureType FPictureType;
	int __fastcall AddString(System::UnicodeString s);
	int __fastcall AddColor(System::Uitypes::TColor c);
	void __fastcall AddColors(const System::Uitypes::TColor *c, const int c_High);
	void __fastcall AddSheet(const Frxofficeopen::TfrxMap &m);
	void __fastcall ExportFormats(System::Classes::TStrings* FNumFmts);
	void __fastcall UpdateStyles(void);
	
public:
	__fastcall virtual TfrxXLSXExport(System::Classes::TComponent* Owner);
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
	virtual System::Uitypes::TModalResult __fastcall ShowModal(void);
	virtual bool __fastcall Start(void);
	virtual void __fastcall Finish(void);
	virtual void __fastcall FinishPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall ExportObject(Frxclass::TfrxComponent* Obj);
	
__published:
	__property int ChunkSize = {read=FChunkSize, write=FChunkSize, nodefault};
	__property bool EmptyLines = {read=FEmptyLines, write=FEmptyLines, default=1};
	__property bool ExportPageBreaks = {read=FExportPageBreaks, write=FExportPageBreaks, default=1};
	__property bool OpenAfterExport = {read=FOpenAfterExport, write=FOpenAfterExport, default=0};
	__property OverwritePrompt;
	__property Frximageconverter::TfrxPictureType PictureType = {read=FPictureType, write=FPictureType, nodefault};
	__property bool SingleSheet = {read=FSingleSheet, write=FSingleSheet, default=1};
	__property bool Wysiwyg = {read=FWysiwyg, write=FWysiwyg, default=1};
public:
	/* TfrxCustomExportFilter.CreateNoRegister */ inline __fastcall TfrxXLSXExport(void) : Frxclass::TfrxCustomExportFilter() { }
	/* TfrxCustomExportFilter.Destroy */ inline __fastcall virtual ~TfrxXLSXExport(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Frxexportxlsx */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXEXPORTXLSX)
using namespace Frxexportxlsx;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxexportxlsxHPP

// CodeGear C++Builder
// Copyright (c) 1995, 2016 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxExportXML.pas' rev: 32.00 (Windows)

#ifndef FrxexportxmlHPP
#define FrxexportxmlHPP

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
#include <Vcl.Printers.hpp>
#include <System.Win.ComObj.hpp>
#include <frxClass.hpp>
#include <frxExportMatrix.hpp>
#include <frxProgress.hpp>
#include <System.Variants.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxexportxml
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TfrxXMLExportDialog;
class DELPHICLASS TfrxXMLExport;
//-- type declarations -------------------------------------------------------
enum DECLSPEC_DENUM TfrxSplitToSheet : unsigned char { ssNotSplit, ssRPages, ssPrintOnPrev, ssRowsCount };

class PASCALIMPLEMENTATION TfrxXMLExportDialog : public Vcl::Forms::TForm
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
	Vcl::Stdctrls::TCheckBox* WCB;
	Vcl::Stdctrls::TCheckBox* ContinuousCB;
	Vcl::Stdctrls::TCheckBox* PageBreaksCB;
	Vcl::Stdctrls::TCheckBox* OpenExcelCB;
	Vcl::Stdctrls::TCheckBox* BackgrCB;
	Vcl::Stdctrls::TGroupBox* SplitToSheetGB;
	Vcl::Stdctrls::TRadioButton* RPagesRB;
	Vcl::Stdctrls::TRadioButton* PrintOnPrevRB;
	Vcl::Stdctrls::TRadioButton* RowsCountRB;
	Vcl::Stdctrls::TEdit* ERows;
	Vcl::Stdctrls::TRadioButton* NotSplitRB;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall PageNumbersEChange(System::TObject* Sender);
	void __fastcall PageNumbersEKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
	void __fastcall ERowsKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall ERowsChange(System::TObject* Sender);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrxXMLExportDialog(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxXMLExportDialog(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrxXMLExportDialog(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxXMLExportDialog(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TfrxXMLExport : public Frxclass::TfrxCustomExportFilter
{
	typedef Frxclass::TfrxCustomExportFilter inherited;
	
	
private:
	typedef System::DynamicArray<int> _TfrxXMLExport__1;
	
	typedef System::DynamicArray<System::Uitypes::TPrinterOrientation> _TfrxXMLExport__2;
	
	
private:
	bool FExportPageBreaks;
	bool FExportStyles;
	bool FFirstPage;
	Frxexportmatrix::TfrxIEMatrix* FMatrix;
	bool FOpenExcelAfterExport;
	System::Extended FPageBottom;
	System::Extended FPageLeft;
	System::Extended FPageRight;
	System::Extended FPageTop;
	System::Uitypes::TPrinterOrientation FPageOrientation;
	System::Classes::TStringList* FPaperNames;
	_TfrxXMLExport__1 FPaperSizes;
	_TfrxXMLExport__2 FPaperOrientations;
	Frxprogress::TfrxProgress* FProgress;
	bool FWysiwyg;
	bool FBackground;
	System::UnicodeString FCreator;
	bool FEmptyLines;
	int FRowsCount;
	TfrxSplitToSheet FSplit;
	void __fastcall ExportPage(System::Classes::TStream* Stream);
	System::UnicodeString __fastcall ChangeReturns(const System::UnicodeString Str);
	System::WideString __fastcall TruncReturns(const System::WideString Str);
	void __fastcall SetRowsCount(const int Value);
	
public:
	__fastcall virtual TfrxXMLExport(System::Classes::TComponent* AOwner);
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
	virtual System::Uitypes::TModalResult __fastcall ShowModal(void);
	virtual bool __fastcall Start(void);
	virtual void __fastcall Finish(void);
	virtual void __fastcall FinishPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall StartPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall ExportObject(Frxclass::TfrxComponent* Obj);
	
__published:
	__property bool ExportStyles = {read=FExportStyles, write=FExportStyles, default=1};
	__property bool ExportPageBreaks = {read=FExportPageBreaks, write=FExportPageBreaks, default=1};
	__property bool OpenExcelAfterExport = {read=FOpenExcelAfterExport, write=FOpenExcelAfterExport, default=0};
	__property bool Wysiwyg = {read=FWysiwyg, write=FWysiwyg, default=1};
	__property bool Background = {read=FBackground, write=FBackground, default=0};
	__property System::UnicodeString Creator = {read=FCreator, write=FCreator};
	__property bool EmptyLines = {read=FEmptyLines, write=FEmptyLines, nodefault};
	__property SuppressPageHeadersFooters;
	__property OverwritePrompt;
	__property int RowsCount = {read=FRowsCount, write=SetRowsCount, nodefault};
	__property TfrxSplitToSheet Split = {read=FSplit, write=FSplit, nodefault};
public:
	/* TfrxCustomExportFilter.CreateNoRegister */ inline __fastcall TfrxXMLExport(void) : Frxclass::TfrxCustomExportFilter() { }
	/* TfrxCustomExportFilter.Destroy */ inline __fastcall virtual ~TfrxXMLExport(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Frxexportxml */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXEXPORTXML)
using namespace Frxexportxml;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxexportxmlHPP

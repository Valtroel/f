﻿// CodeGear C++Builder
// Copyright (c) 1995, 2016 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxExportDOCX.pas' rev: 32.00 (Windows)

#ifndef FrxexportdocxHPP
#define FrxexportdocxHPP

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
#include <frxClass.hpp>
#include <Winapi.ShellAPI.hpp>
#include <Vcl.ComCtrls.hpp>
#include <frxZip.hpp>
#include <frxExportMatrix.hpp>
#include <frxImageConverter.hpp>
#include <System.UITypes.hpp>
#include <System.Types.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxexportdocx
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TfrxDOCXExportDialog;
struct TfrxDocxPage;
class DELPHICLASS TfrxDOCXExport;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TfrxDOCXExportDialog : public Vcl::Forms::TForm
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
	Vcl::Stdctrls::TCheckBox* OpenCB;
	void __fastcall FormCreate(System::TObject* Sender);
	void __fastcall PageNumbersEChange(System::TObject* Sender);
	void __fastcall PageNumbersEKeyPress(System::TObject* Sender, System::WideChar &Key);
	void __fastcall FormKeyDown(System::TObject* Sender, System::Word &Key, System::Classes::TShiftState Shift);
public:
	/* TCustomForm.Create */ inline __fastcall virtual TfrxDOCXExportDialog(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxDOCXExportDialog(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrxDOCXExportDialog(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxDOCXExportDialog(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


struct DECLSPEC_DRECORD TfrxDocxPage
{
public:
	int Width;
	int Height;
	System::Types::TRect Margins;
};


class PASCALIMPLEMENTATION TfrxDOCXExport : public Frxclass::TfrxCustomExportFilter
{
	typedef Frxclass::TfrxCustomExportFilter inherited;
	
private:
	bool FOpenAfterExport;
	System::UnicodeString FDocFolder;
	System::Classes::TStream* FDocument;
	System::Classes::TStream* FDocRels;
	Frxexportmatrix::TfrxIEMatrix* FMatrix;
	TfrxDocxPage FLastPage;
	int FPicNum;
	bool FFirstPage;
	Frximageconverter::TfrxPictureType FPictureType;
	System::UnicodeString __fastcall SubPath(const System::UnicodeString s);
	System::UnicodeString __fastcall SecPr(void);
	
public:
	__fastcall virtual TfrxDOCXExport(System::Classes::TComponent* Owner);
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
	virtual System::Uitypes::TModalResult __fastcall ShowModal(void);
	virtual bool __fastcall Start(void);
	virtual void __fastcall Finish(void);
	virtual void __fastcall StartPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall FinishPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall ExportObject(Frxclass::TfrxComponent* Obj);
	
__published:
	__property bool OpenAfterExport = {read=FOpenAfterExport, write=FOpenAfterExport, nodefault};
	__property OverwritePrompt;
	__property Frximageconverter::TfrxPictureType PictureType = {read=FPictureType, write=FPictureType, nodefault};
public:
	/* TfrxCustomExportFilter.CreateNoRegister */ inline __fastcall TfrxDOCXExport(void) : Frxclass::TfrxCustomExportFilter() { }
	/* TfrxCustomExportFilter.Destroy */ inline __fastcall virtual ~TfrxDOCXExport(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Frxexportdocx */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXEXPORTDOCX)
using namespace Frxexportdocx;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxexportdocxHPP

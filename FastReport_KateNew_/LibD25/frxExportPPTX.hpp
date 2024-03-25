// CodeGear C++Builder
// Copyright (c) 1995, 2016 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'frxExportPPTX.pas' rev: 32.00 (Windows)

#ifndef FrxexportpptxHPP
#define FrxexportpptxHPP

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
#include <frxImageConverter.hpp>
#include <System.UITypes.hpp>

//-- user supplied -----------------------------------------------------------

namespace Frxexportpptx
{
//-- forward type declarations -----------------------------------------------
class DELPHICLASS TfrxPPTXExportDialog;
class DELPHICLASS TfrxPPTXExport;
//-- type declarations -------------------------------------------------------
class PASCALIMPLEMENTATION TfrxPPTXExportDialog : public Vcl::Forms::TForm
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
	/* TCustomForm.Create */ inline __fastcall virtual TfrxPPTXExportDialog(System::Classes::TComponent* AOwner) : Vcl::Forms::TForm(AOwner) { }
	/* TCustomForm.CreateNew */ inline __fastcall virtual TfrxPPTXExportDialog(System::Classes::TComponent* AOwner, int Dummy) : Vcl::Forms::TForm(AOwner, Dummy) { }
	/* TCustomForm.Destroy */ inline __fastcall virtual ~TfrxPPTXExportDialog(void) { }
	
public:
	/* TWinControl.CreateParented */ inline __fastcall TfrxPPTXExportDialog(HWND ParentWindow) : Vcl::Forms::TForm(ParentWindow) { }
	
};


class PASCALIMPLEMENTATION TfrxPPTXExport : public Frxclass::TfrxCustomExportFilter
{
	typedef Frxclass::TfrxCustomExportFilter inherited;
	
private:
	bool FOpenAfterExport;
	System::UnicodeString FDocFolder;
	System::Classes::TStream* FContentTypes;
	System::Classes::TStream* FPresentation;
	System::Classes::TStream* FPresentationRels;
	System::Classes::TStream* FRels;
	System::Classes::TStream* FSlide;
	System::Classes::TStream* FSlideRels;
	int FSlideId;
	int FObjectId;
	Frxclass::TfrxReportPage* FPage;
	int FWidth;
	int FHeight;
	Frximageconverter::TfrxPictureType FPictureType;
	System::UnicodeString __fastcall SubPath(const System::UnicodeString s);
	void __fastcall AddTextBox(Frxclass::TfrxCustomMemoView* Obj);
	void __fastcall AddLine(Frxclass::TfrxFrameLine* Line, int x, int y, int dx, int dy);
	void __fastcall AddPicture(Frxclass::TfrxView* Obj);
	System::Types::TRect __fastcall GetObjRect(Frxclass::TfrxView* Obj);
	
public:
	__fastcall virtual TfrxPPTXExport(System::Classes::TComponent* Owner);
	__classmethod virtual System::UnicodeString __fastcall GetDescription();
	virtual System::Uitypes::TModalResult __fastcall ShowModal(void);
	virtual bool __fastcall Start(void);
	virtual void __fastcall Finish(void);
	virtual void __fastcall StartPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall FinishPage(Frxclass::TfrxReportPage* Page, int Index);
	virtual void __fastcall ExportObject(Frxclass::TfrxComponent* Obj);
	
__published:
	__property bool OpenAfterExport = {read=FOpenAfterExport, write=FOpenAfterExport, default=0};
	__property OverwritePrompt;
	__property Frximageconverter::TfrxPictureType PictureType = {read=FPictureType, write=FPictureType, nodefault};
public:
	/* TfrxCustomExportFilter.CreateNoRegister */ inline __fastcall TfrxPPTXExport(void) : Frxclass::TfrxCustomExportFilter() { }
	/* TfrxCustomExportFilter.Destroy */ inline __fastcall virtual ~TfrxPPTXExport(void) { }
	
};


//-- var, const, procedure ---------------------------------------------------
}	/* namespace Frxexportpptx */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_FRXEXPORTPPTX)
using namespace Frxexportpptx;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// FrxexportpptxHPP

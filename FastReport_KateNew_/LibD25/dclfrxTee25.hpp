// CodeGear C++Builder
// Copyright (c) 1995, 2016 by Embarcadero Technologies, Inc.
// All rights reserved

// (DO NOT EDIT: machine generated header) 'dclfrxTee25.dpk' rev: 32.00 (Windows)

#ifndef Dclfrxtee25HPP
#define Dclfrxtee25HPP

#pragma delphiheader begin
#pragma option push
#pragma option -w-      // All warnings off
#pragma option -Vx      // Zero-length empty class member 
#pragma pack(push,8)
#include <System.hpp>	// (rtl)
#include <SysInit.hpp>
#include <frxRegTee.hpp>
#include <Winapi.Windows.hpp>	// (rtl)
#include <Winapi.PsAPI.hpp>	// (rtl)
#include <System.Character.hpp>	// (rtl)
#include <System.Internal.ExcUtils.hpp>	// (rtl)
#include <System.SysUtils.hpp>	// (rtl)
#include <System.VarUtils.hpp>	// (rtl)
#include <System.Variants.hpp>	// (rtl)
#include <System.Math.hpp>	// (rtl)
#include <System.Rtti.hpp>	// (rtl)
#include <System.TypInfo.hpp>	// (rtl)
#include <System.Generics.Defaults.hpp>	// (rtl)
#include <System.Classes.hpp>	// (rtl)
#include <System.TimeSpan.hpp>	// (rtl)
#include <System.DateUtils.hpp>	// (rtl)
#include <System.IOUtils.hpp>	// (rtl)
#include <System.Win.Registry.hpp>	// (rtl)
#include <Vcl.Graphics.hpp>	// (vcl)
#include <System.Actions.hpp>	// (rtl)
#include <Vcl.ActnList.hpp>	// (vcl)
#include <System.HelpIntfs.hpp>	// (rtl)
#include <System.SyncObjs.hpp>	// (rtl)
#include <Winapi.UxTheme.hpp>	// (rtl)
#include <Vcl.GraphUtil.hpp>	// (vcl)
#include <Vcl.StdCtrls.hpp>	// (vcl)
#include <Winapi.ShellAPI.hpp>	// (rtl)
#include <Vcl.Printers.hpp>	// (vcl)
#include <Vcl.Clipbrd.hpp>	// (vcl)
#include <Vcl.ComCtrls.hpp>	// (vcl)
#include <Vcl.Dialogs.hpp>	// (vcl)
#include <Vcl.ExtCtrls.hpp>	// (vcl)
#include <Vcl.Themes.hpp>	// (vcl)
#include <System.AnsiStrings.hpp>	// (rtl)
#include <System.Win.ComObj.hpp>	// (rtl)
#include <Winapi.FlatSB.hpp>	// (rtl)
#include <Vcl.Forms.hpp>	// (vcl)
#include <Vcl.Menus.hpp>	// (vcl)
#include <Winapi.MsCTF.hpp>	// (rtl)
#include <Vcl.Controls.hpp>	// (vcl)
#include <IDEMessages.hpp>	// (designide)
#include <Vcl.CaptionedDockTree.hpp>	// (vcl)
#include <Vcl.DockTabSet.hpp>	// (vcl)
#include <PercentageDockTree.hpp>	// (designide)
#include <BrandingAPI.hpp>	// (designide)
#include <Vcl.Buttons.hpp>	// (vcl)
#include <Vcl.ExtDlgs.hpp>	// (vcl)
#include <Winapi.Mapi.hpp>	// (rtl)
#include <Vcl.ExtActns.hpp>	// (vcl)
#include <Vcl.ActnMenus.hpp>	// (vclactnband)
#include <Vcl.ActnMan.hpp>	// (vclactnband)
#include <Vcl.PlatformDefaultStyleActnCtrls.hpp>	// (vclactnband)
#include <BaseDock.hpp>	// (designide)
#include <DeskUtil.hpp>	// (designide)
#include <DeskForm.hpp>	// (designide)
#include <DockForm.hpp>	// (designide)
#include <Xml.Win.msxmldom.hpp>	// (xmlrtl)
#include <Xml.xmldom.hpp>	// (xmlrtl)
#include <ToolsAPI.hpp>	// (designide)
#include <Proxies.hpp>	// (designide)
#include <DesignEditors.hpp>	// (designide)
#include <frxChm.hpp>	// (frx25)
#include <fs_iconst.hpp>	// (fs25)
#include <frxRes.hpp>	// (frx25)
#include <fs_itools.hpp>	// (fs25)
#include <fs_iinterpreter.hpp>	// (fs25)
#include <frxDsgnIntf.hpp>	// (frx25)
#include <frxDMPClass.hpp>	// (frx25)
#include <frxPrinter.hpp>	// (frx25)
#include <frxSearchDialog.hpp>	// (frx25)
#include <frxPreview.hpp>	// (frx25)
#include <frxGraphicUtils.hpp>	// (frx25)
#include <frxrcClass.hpp>	// (frx25)
#include <fs_iclassesrtti.hpp>	// (fs25)
#include <fs_igraphicsrtti.hpp>	// (fs25)
#include <fs_iformsrtti.hpp>	// (fs25)
#include <Vcl.Imaging.jpeg.hpp>	// (vclimg)
#include <Vcl.Imaging.pngimage.hpp>	// (vclimg)
#include <frxClassRTTI.hpp>	// (frx25)
#include <fs_ipascal.hpp>	// (fs25)
#include <fs_icpp.hpp>	// (fs25)
#include <fs_ibasic.hpp>	// (fs25)
#include <fs_ijs.hpp>	// (fs25)
#include <fs_idialogsrtti.hpp>	// (fs25)
#include <fs_iinirtti.hpp>	// (fs25)
#include <frxClass.hpp>	// (frx25)
#include <VCLTee.TeeHtml.hpp>	// (tee)
#include <VCLTee.TeeConst.hpp>	// (tee)
#include <VCLTee.TeCanvas.hpp>	// (tee)
#include <VCLTee.TeeFilters.hpp>	// (tee)
#include <VCLTee.TeeProcs.hpp>	// (tee)
#include <VCLTee.TeEngine.hpp>	// (tee)
#include <VCLTee.Chart.hpp>	// (tee)
#include <VCLTee.TeeSpline.hpp>	// (tee)
#include <VCLTee.GanttCh.hpp>	// (tee)
#include <VCLTee.TeeShape.hpp>	// (tee)
#include <VCLTee.BubbleCh.hpp>	// (tee)
#include <VCLTee.ArrowCha.hpp>	// (tee)
#include <frxChartHelpers.hpp>	// (frxTee25)
#include <fs_ichartrtti.hpp>	// (fsTee25)
#include <frxChartRTTI.hpp>	// (frxTee25)
#include <frxEditFormat.hpp>	// (frx25)
#include <Vcl.OleCtnrs.hpp>	// (vcl)
#include <frxRichEdit.hpp>	// (frx25)
#include <frxUnicodeCtrls.hpp>	// (frx25)
#include <frxrcInsp.hpp>	// (frx25)
#include <Winapi.GDIPOBJ.hpp>	// (rtl)
#include <VCLTee.TeeGDIPlus.hpp>	// (tee)
#include <VCLTee.TeeGalleryPanel.hpp>	// (teeui)
#include <frxChartEditor.hpp>	// (frxTee25)
#include <frxChart.hpp>	// (frxTee25)
// PRG_EXT: .bpl
// OBJ_EXT: .obj

//-- user supplied -----------------------------------------------------------

namespace Dclfrxtee25
{
//-- forward type declarations -----------------------------------------------
//-- type declarations -------------------------------------------------------
//-- var, const, procedure ---------------------------------------------------
}	/* namespace Dclfrxtee25 */
#if !defined(DELPHIHEADER_NO_IMPLICIT_NAMESPACE_USE) && !defined(NO_USING_NAMESPACE_DCLFRXTEE25)
using namespace Dclfrxtee25;
#endif
#pragma pack(pop)
#pragma option pop

#pragma delphiheader end.
//-- end unit ----------------------------------------------------------------
#endif	// Dclfrxtee25HPP

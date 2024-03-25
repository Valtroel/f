{ This file was automatically created by Lazarus. Do not edit!
  This source is only used to compile and install the package.
 }

unit fr5_lazarus;

interface

uses
  frxClass, frxBarcode, frxPrinter, frxCtrls, frxUtils, frxDock, frxDBSet, 
  frxChBox, frxGradient, frxCross, frxDesgnCtrls, frxBarcod, frxDCtrl, 
  frxDesgn, frxPreview, frxXML, frxXMLSerializer, frxLazarusComponentEditors, 
  frxDelphiZXingQRCode, frxAbout, frxAggregate, frxBarcode2D, 
  frxBarcode2DBase, frxBarcode2DRTTI, frxBarcodeDataMatrix, frxBarcodeEditor, 
  frxBarcodePDF417, frxBarcodeProperties, frxBarcodeQR, frxBarcodeRTTI, 
  frxChBoxRTTI, frxChm, frxClassRTTI, frxCodeUtils, frxCollections, 
  frxConnEditor, frxConnItemEdit, frxConnWizard, frxCrossEditor, frxCrossRTTI, 
  frxCrypt, frxCustomDB, frxCustomDBEditor, frxCustomDBRTTI, frxCustomEditors, 
  frxDataTree, frxDCtrlRTTI, frxDesgnEditors, frxDesgnWorkspace, 
  frxDesgnWorkspace1, frxDialogForm, frxDMPClass, frxDsgnIntf, frxEditAliases, 
  frxEditDataBand, frxEditExpr, frxEditFill, frxEditFormat, frxEditFrame, 
  frxEditGroup, frxEditHighlight, frxEditHyperlink, frxEditMD, frxEditMemo, 
  frxEditOptions, frxEditPage, frxEditPicture, frxEditQueryParams, 
  frxEditReport, frxEditReportData, frxEditSQL, frxEditStrings, frxEditStyle, 
  frxEditSysMemo, frxEditTabOrder, frxEditVar, frxEngine, frxEvaluateForm, 
  frxGradientRTTI, frxGraphicUtils, frxGZip, frxInheritError, frxInsp, frxmd5, 
  frxNewItem, frxPassw, frxPictureCache, frxPopupForm, frxPreviewPages, 
  frxPreviewPageSettings, frxPrintDialog, frxProgress, frxrcClass, frxrcDesgn, 
  frxrcInsp, frxReportTree, frxRes, frxSearchDialog, frxStdWizard, frxSynMemo, 
  frxUnicodeCtrls, frxUnicodeUtils, frxVariables, frxWatchForm, frxZLib, 
  frxReg, LazarusPackageIntf;

implementation

procedure Register;
begin
  RegisterUnit('frxLazarusComponentEditors', 
    @frxLazarusComponentEditors.Register);
  RegisterUnit('frxReg', @frxReg.Register);
end;

initialization
  RegisterPackage('fr5_lazarus', @Register);
end.



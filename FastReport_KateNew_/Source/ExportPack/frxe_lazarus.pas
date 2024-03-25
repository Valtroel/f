{ This file was automatically created by Lazarus. Do not edit!
  This source is only used to compile and install the package.
 }

unit frxe_lazarus;

interface

uses
  frxExportImage, frxeReg, frxExportMatrix, frxExportHTML, frxExportHTMLDiv, 
  frxExportHelpers, frxCrypto, frxStorage, frxExportODF, frxExportPDFLaz, 
  LazarusPackageIntf;

implementation

procedure Register;
begin
  RegisterUnit('frxeReg', @frxeReg.Register);
end;

initialization
  RegisterPackage('frxe_lazarus', @Register);
end.

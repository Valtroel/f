{ This file was automatically created by Lazarus. Do not edit!
  This source is only used to compile and install the package.
 }

unit frxlazmysql;

interface

uses
  frxlazmysqlcomp, frxlazmysqleditor, frxlazmysqlrtti, LazarusPackageIntf;

implementation

procedure Register;
begin
  RegisterUnit('frxlazmysqlcomp', @frxlazmysqlcomp.Register);
end;

initialization
  RegisterPackage('frxlazmysql', @Register);
end.

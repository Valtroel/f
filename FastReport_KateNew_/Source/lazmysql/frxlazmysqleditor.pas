unit frxlazmysqleditor;

{$I frx.inc}

interface

implementation

uses
  Classes, SysUtils,
  Forms, Dialogs, frxlazmysqlcomp,
  frxCustomDB, frxDsgnIntf, frxRes, db, sqldb;

type

  { TfrxDatabaseNameProperty }

  TfrxDatabaseNameProperty = class(TfrxStringProperty)
  public
    function GetAttributes: TfrxPropertyAttributes; override;
    function Edit: Boolean; override;
  end;

  { TfrxDatabaseProperty }

  TfrxDatabaseProperty = class(TfrxComponentProperty)
  public
    function GetValue: String; override;
  end;

{ TfrxDatabaseProperty }

function TfrxDatabaseProperty.GetValue: String;
var
  db: TfrxLazMySQLDatabase;
begin
  db := TfrxLazMySQLDatabase(GetOrdValue);
  if db = nil then
  begin
    if (LazMySQLComponents <> nil) and (LazMySQLComponents.DefaultDatabase <> nil) then
      Result := LazMySQLComponents.DefaultDatabase.Name
    else
      Result := frxResources.Get('prNotAssigned');
  end
  else
    Result := inherited GetValue;
end;

function TfrxDatabaseNameProperty.GetAttributes: TfrxPropertyAttributes;
begin
  Result := [paDialog];
end;

function TfrxDatabaseNameProperty.Edit: Boolean;
var
  SaveConnected: Boolean;
begin
  with TOpenDialog.Create(nil) do
  begin
    InitialDir := GetCurrentDir;
    Filter := frxResources.Get('ftDB')  +
      frxResources.Get('ftAllFiles') + ' (*.*)|*.*';
    Result := Execute;
    if Result then
      with TfrxLazMySQLDatabase(Component).Database do
      begin
        SaveConnected := Connected;
        Connected := False;
        DatabaseName := FileName;
        Connected := SaveConnected;
      end;
    Free;
  end;
end;

initialization
  frxPropertyEditors.Register(TypeInfo(String), TfrxLazMySQLDataBase, 'DatabaseName',
    TfrxDataBaseNameProperty);
  frxPropertyEditors.Register(TypeInfo(TfrxLazMySQLDatabase), TfrxLazMySQLQuery, 'Database',
    TfrxDatabaseProperty);

end.


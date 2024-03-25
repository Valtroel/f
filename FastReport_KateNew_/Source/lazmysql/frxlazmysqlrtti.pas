unit frxlazmysqlrtti;

{$I frx.inc}

interface



implementation

uses
  Classes, SysUtils, Variants,
  fs_iinterpreter, frxlazmysqlcomp;

type

  { TFunctions }

  TFunctions = class(TfsRTTIModule)
  private
    function CallMethod(Instance: TObject; ClassType: TClass;
      const MethodName: String; Caller: TfsMethodHelper): Variant;
    function GetProp(Instance: TObject; ClassType: TClass;
      const PropName: String): Variant;
  public
    constructor Create(AScript: TfsScript); override;
  end;

{ TFunctions }

function TFunctions.CallMethod(Instance: TObject; ClassType: TClass;
  const MethodName: String; Caller: TfsMethodHelper): Variant;
begin
  Result := 0;

  if ClassType = TfrxLazMySQLQuery then
  begin
    if MethodName = 'EXECSQL' then
      TfrxLazMySQLQuery(Instance).Query.ExecSQL
  end;
end;

function TFunctions.GetProp(Instance: TObject; ClassType: TClass;
  const PropName: String): Variant;
begin
  Result := 0;

  if ClassType = TfrxLazMySQLDataBase then
  begin
    if PropName = 'DATABASE' then
      Result := frxInteger(TfrxLazMySQLDataBase(Instance).Database)
  end
  else if ClassType = TfrxLazMySQLQuery then
  begin
    if PropName = 'QUERY' then
      Result := frxInteger(TfrxLazMySQLQuery(Instance).Query)
  end
end;

constructor TFunctions.Create(AScript: TfsScript);
begin
  inherited Create(AScript);
  with AScript do
  begin
    with AddClass(TfrxLazMySQLDataBase, 'TfrxCustomDatabase') do
      AddProperty('Database', 'TSQLConnector', GetProp, nil);
    with AddClass(TfrxLazMySQLQuery, 'TfrxCustomQuery') do
    begin
      AddMethod('procedure ExecSQL', CallMethod);
      AddProperty('Query', 'TSQLQuery', GetProp, nil);
    end;
  end;
end;

initialization

  fsRTTIModules.Add(TFunctions);

finalization

  if fsRTTIModules <> nil then
    fsRTTIModules.Remove(TFunctions);



end.


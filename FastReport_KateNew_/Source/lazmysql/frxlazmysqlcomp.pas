unit frxlazmysqlcomp;

{$I frx.inc}

interface

uses
  Classes, SysUtils,
  frxClass, frxCustomDB, DB, sqldb,
  Variants, LResources,
  mysql57conn, mysql56conn, mysql55conn,
  mysql51conn, mysql50conn, mysql41conn, mysql40conn;

type

  { TfrxLazMySQLComponents }

  TfrxLazMySQLComponents = class(TfrxDBComponents)
  private
    FDefaultDatabase: TSQLConnector;
    FOldComponents: TfrxLazMySQLComponents;
  protected
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure SetDefaultDatabase(Value: TSQLConnector);
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    function GetDescription: String; override;
  published
    property DefaultDatabase: TSQLConnector read FDefaultDatabase write SetDefaultDatabase;
  end;

  { TfrxLazMySQLDataBase }

  TfrxLazMySQLDataBase = class(TfrxCustomDatabase)
  private
    FDataBase: TSQLConnector;
    FTransaction: TSqlTransaction;
    FMySQLVersion: string;
    function GetCharSet: string;
    function GetHostName: string;
    function GetPassword: string;
    function GetPort: cardinal;
    function GetRole: string;
    function GetUserName: string;
    procedure SetCharSet(AValue: string);
    procedure SetHostName(AValue: string);
    procedure SetMySQLVersion(AValue: string);
    procedure SetPassword(AValue: string);
    procedure SetPort(AValue: cardinal);
    procedure SetRole(AValue: string);
    procedure SetUserName(AValue: string);
  protected
    function GetConnected: Boolean; override;
    procedure SetConnected(Value: Boolean); override;
    function GetDatabaseName:string; override;
    procedure SetDatabaseName(const Value:string); override;
  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    class function GetDescription: String; override;
    property Database: TSQLConnector read FDatabase;
  published
    property CharSet: string read GetCharSet write SetCharSet;
    property MySQLVersion: string read FMySQLVersion write SetMySQLVersion;
    property DatabaseName;
    property HostName: string read GetHostName write SetHostName;
    property LoginPrompt;
    property Params;
    property Port:cardinal read GetPort write SetPort;
    property UserName:string read GetUserName  write SetUserName;
    property Password:string read GetPassword write SetPassword;
    property Role:string read GetRole write SetRole;
    property Connected;
  end;

  { TfrxLazMySQLQuery }

  TfrxLazMySQLQuery = class(TfrxCustomQuery)
  private
    FDatabase: TfrxLazMySQLDataBase;
    FQuery: TSqlQuery;
    procedure SetDatabase(const Value: TfrxLazMySQLDataBase);
  protected
    procedure Notification(AComponent: TComponent; Operation: TOperation); override;
    procedure SetMaster(const Value: TDataSource); override;
    procedure SetSQL(Value: TStrings); override;
    function GetSQL: TStrings; override;
  public
    constructor Create(AOwner: TComponent); override;
    constructor DesignCreate(AOwner: TComponent; Flags: Word); override;
    class function GetDescription: String; override;
    procedure BeforeStartReport; override;
    procedure UpdateParams; override;
    property Query: TSqlQuery read FQuery;
  published
    property Database: TfrxLazMySQLDataBase read FDatabase write SetDatabase;
  end;


var
  LazMySQLComponents: TfrxLazMySQLComponents;

procedure Register;

implementation

uses
  frxLazMySQLEditor,frxDsgnIntf,
  frxlazmysqlrtti,
  frxRes;

{ TfrxLazMySQLDataBase }

type
  THackCon = class(TSQLConnector);

procedure Register;
begin
  RegisterComponents('FastReport 5',[TfrxLazMySQLComponents]);
end;

{ TfrxLazMySQLQuery }

procedure TfrxLazMySQLQuery.SetDatabase(const Value: TfrxLazMySQLDataBase);
begin
  FDatabase := Value;

  if Value <> nil then
  begin
    FQuery.Database := Value.Database;
    FQuery.Transaction := Value.FTransaction;
  end
  else if LazMySQLComponents <> nil then
  begin
    FQuery.Database := LazMySQLComponents.DefaultDatabase;
    if Assigned(FQuery.Database) then
      FQuery.Transaction := LazMySQLComponents.DefaultDatabase.Transaction;
  end
  else
    FQuery.Database := nil;
  DBConnected := FQuery.Database <> nil;
end;

procedure TfrxLazMySQLQuery.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (Operation = opRemove) and (AComponent = FDatabase) then
    SetDatabase(nil);
end;

procedure TfrxLazMySQLQuery.SetMaster(const Value: TDataSource);
begin
  FQuery.DataSource := Value;
end;

procedure TfrxLazMySQLQuery.SetSQL(Value: TStrings);
begin
  FQuery.SQL := TStringList(Value);
end;

function TfrxLazMySQLQuery.GetSQL: TStrings;
begin
  Result := FQuery.SQL;
end;

constructor TfrxLazMySQLQuery.Create(AOwner: TComponent);
begin
  FQuery := TSqlQuery.Create(nil);
  Dataset := FQuery;
  SetDatabase(nil);
  inherited Create(AOwner);
end;

constructor TfrxLazMySQLQuery.DesignCreate(AOwner: TComponent; Flags: Word);
var
  i: Integer;
  l: TList;
begin
  inherited;
  l := Report.AllObjects;
  for i := 0 to l.Count - 1 do
    if TObject(l[i]) is TfrxLazMySQLDatabase then
    begin
      SetDatabase(TfrxLazMySQLDatabase(l[i]));
      break;
    end;
end;

class function TfrxLazMySQLQuery.GetDescription: String;
begin
  Result:='MySQL Query';
end;

procedure TfrxLazMySQLQuery.BeforeStartReport;
begin
  SetDatabase(FDatabase);
end;

procedure TfrxLazMySQLQuery.UpdateParams;
begin
  if Assigned(FQuery.Database) then
    frxParamsToTParams(Self, FQuery.Params);
end;

{ TfrxLazMySQLDataBase }

function TfrxLazMySQLDataBase.GetCharSet: string;
begin
  Result := FDatabase.CharSet;
end;

function TfrxLazMySQLDataBase.GetHostName: string;
begin
  Result := FDatabase.HostName;
end;

function TfrxLazMySQLDataBase.GetPassword: string;
begin
  Result := FDatabase.Password;
end;

function TfrxLazMySQLDataBase.GetPort: cardinal;
begin
  Result := THackCon(FDataBase).Port;
end;

function TfrxLazMySQLDataBase.GetRole: string;
begin
  Result := FDatabase.Role;
end;

function TfrxLazMySQLDataBase.GetUserName: string;
begin
  Result := FDatabase.UserName;
end;

procedure TfrxLazMySQLDataBase.SetCharSet(AValue: string);
begin
  FDatabase.CharSet:= AValue;
end;

procedure TfrxLazMySQLDataBase.SetHostName(AValue: string);
begin
  FDatabase.HostName:= AValue;
end;

procedure TfrxLazMySQLDataBase.SetMySQLVersion(AValue: string);
var
  s, s1: string;
begin
  s := Trim(AValue);

  if UpperCase(LeftStr(s,6)) = 'MYSQL ' then
    s1 := RightStr(s,3)
  else
  begin
    s1 := s;
    s := 'MySQL ' + s;
  end;
  if FMySQLVersion = s1 then
    Exit;
  FMySQLVersion := s1;
  FDataBase.ConnectorType := s;
end;

procedure TfrxLazMySQLDataBase.SetPassword(AValue: string);
begin
  FDatabase.Password := AValue;
end;

procedure TfrxLazMySQLDataBase.SetPort(AValue: cardinal);
begin
  THackCon(FDataBase).Port := AValue;
end;

procedure TfrxLazMySQLDataBase.SetRole(AValue: string);
begin
  FDatabase.Role := AValue;
end;

procedure TfrxLazMySQLDataBase.SetUserName(AValue: string);
begin
  FDatabase.UserName := AValue;
end;

function TfrxLazMySQLDataBase.GetConnected: Boolean;
begin
  Result:= FDatabase.Connected;
end;

procedure TfrxLazMySQLDataBase.SetConnected(Value: Boolean);
begin
  BeforeConnect(Value);
  FDatabase.Connected := Value;
  FTransaction.Active := Value;
end;

function TfrxLazMySQLDataBase.GetDatabaseName: string;
begin
  Result := FDatabase.DatabaseName;
end;

procedure TfrxLazMySQLDataBase.SetDatabaseName(const Value: string);
begin
  FDatabase.DatabaseName:= Value;
end;

constructor TfrxLazMySQLDataBase.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FDatabase := TSQLConnector.Create(nil);
  FTransaction := TSQLTransaction.Create(nil);
  FDatabase.Transaction := FTransaction;
  Component := FDatabase;
end;

destructor TfrxLazMySQLDataBase.Destroy;
begin
  FTransaction.Free;
  inherited Destroy;
end;

class function TfrxLazMySQLDataBase.GetDescription: String;
begin
  Result:=inherited GetDescription;
end;

{ TfrxLazMySQLComponents }

procedure TfrxLazMySQLComponents.Notification(AComponent: TComponent;
  Operation: TOperation);
begin
  inherited Notification(AComponent, Operation);
  if (AComponent = FDefaultDatabase) and (Operation = opRemove) then
    FDefaultDatabase := nil;
end;

procedure TfrxLazMySQLComponents.SetDefaultDatabase(Value: TSQLConnector);
begin
  if (Value <> nil) then
    Value.FreeNotification(Self);
  if FDefaultDatabase <> nil then
    FDefaultDatabase.RemoveFreeNotification(Self);
  FDefaultDatabase := Value;
end;

constructor TfrxLazMySQLComponents.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FOldComponents:= LazMySQLComponents;
  LazMySQLComponents := Self;
end;

destructor TfrxLazMySQLComponents.Destroy;
begin
  if LazMySQLComponents = Self then
    LazMySQLComponents := FOldComponents;
  inherited Destroy;
end;

function TfrxLazMySQLComponents.GetDescription: String;
begin
  Result:= 'MySQL';
end;

initialization

{$INCLUDE frxlazmysqlcomp.lrs}

  frxObjects.RegisterObject1(TfrxLazMySQLDataBase, nil, '', '', 0, 37);
  frxObjects.RegisterObject1(TfrxLazMySQLQuery, nil, '', '', 0, 39);

finalization
  frxObjects.UnRegister(TfrxLazMySQLDataBase);
  frxObjects.UnRegister(TfrxLazMySQLQuery);
end.

end.


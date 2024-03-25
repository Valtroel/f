
{******************************************}
{                                          }
{             FastReport v5.0              }
{         Helper classes for Exports       }
{                                          }
{         Copyright (c) 1998-2015          }
{           by Anton Khayrudinov           }
{             Fast Reports Inc.            }
{                                          }
{******************************************}

unit frxExportHelpers;

interface

{$I frx.inc}

uses
{$IFNDEF FPC}
  Windows,
{$ENDIF}
{$IFDEF FPC}
  LCLType, LCLIntf,
{$ENDIF}
  Classes,
  Graphics,
  frxClass,
{$IFDEF DELPHI16}
  System.UITypes,
{$ENDIF}
  frxCrypto,    // for hashing pictures and CSS styles
  frxStorage;   // for TObjList and TCachedStream

type
  { Represents a CSS style }

  TfrxCSSStyle = class
  private
    FKeys, FValues: TStrings;
    FName: string;

    procedure SetStyle(Index: string; const Value: string);
    procedure SetPrefixStyle(Index: string; const Value: string);
    function GetStyle(Index: string): string;

  public

    constructor Create;
    destructor Destroy; override;

    function This: TfrxCSSStyle;
    function Count: Integer;
    function Text(Formatted: Boolean = False): string;
    procedure AssignTo(Dest: TfrxCSSStyle);

    property Style[Index: string]: string read GetStyle write SetStyle; default;
    property PrefixStyle[Index: string]: string write SetPrefixStyle;
    property Name: string read FName write FName;
  end;

  { Represents a CSS (Cascading Style Sheet) with a list of CSS styles }

  TfrxCSS = class
    FStyles: TObjList;
    FStyleHashes: TList;

  protected

    function GetStyle(i: Integer): TfrxCSSStyle;
    function GetHash(const s: string): Integer;
    function GetStyleName(i: Integer): string;
    function GetStylesCount: Integer;

  public

    constructor Create;
    destructor Destroy; override;

    function Style(const StyleName: string): TfrxCSSStyle;
    function Add(Style: TfrxCSSStyle): string; overload;
    function Add(const StyleName: string): TfrxCSSStyle; overload;
    procedure Save(Stream: TStream; Formatted: Boolean);
  end;
  
    { Saves pictures and ensures that there will not be identical copies saved }

  TfrxPictureInfo = record
    Extension: string;
    Mimetype: string;
  end;

  TfrxPictureStorage = class
  private
    FWorkDir: string;
    FPrefix: string;
    FHashes: TList;
  protected
    function GetHash(Stream: TMemoryStream): Integer;
  public
    constructor Create(const WorkDir: string; Prefix: string = '');
    destructor Destroy; override;

    function Save(Pic: TGraphic): string;

    class function GetInfo(Pic: TGraphic): TfrxPictureInfo;
  end;

  { Generalised picture }

  TfrxPictureFormat = (pfPNG, {$IFNDEF FPC}pfEMF,{$ENDIF} pfBMP, pfJPG);

  TfrxPicture = class
  private
    FFormat: TfrxPictureFormat;
    FGraphic: TGraphic;
    FCanvas: TCanvas;
    FBitmap: TBitmap; // for TJPEGImage that doesn't provide a canvas
  public
    constructor Create(Format: TfrxPictureFormat; Width, Height: Integer);
    destructor Destroy; override;

    function Release: TGraphic;
    procedure SetTransparentColor(TransparentColor: TColor);
    procedure FillColor(Color: TColor);

    property Canvas: TCanvas read FCanvas;
  end;
  
  TfrxExportHandler = function(Obj: TfrxView): Boolean of object;
  
{ Utility routines }

function GetColor(Color: TColor): string;
function GetBorderRadius(Curve: Integer): string;
function IfStr(Flag: Boolean; const sTrue: string; sFalse: string = ''): string;
function HasSpecialChars(const s: string): Boolean;

function StrFindAndReplace(const Source, Dlm: string; SFR: array of string): string;

implementation

uses
  SysUtils,
{$IFNDEF FPC}
{$IFDEF Delphi12}
  pngimage,
{$ELSE}
  frxpngimage,
{$ENDIF}
  Jpeg,
{$ENDIF}
  frxUtils;


{ Utility routines }

function StrFindAndReplace(const Source, Dlm: string; SFR: array of string): string;

  function IsSplit(const Source, Dlm: string; out UpToDlm, AfterDlm: string): boolean;
  var
    p: integer;
  begin
    p := Pos(Dlm, Source);
    Result := p > 0;
    if Result then
    begin
      UpToDlm := Copy(Source, 1, p - 1);
      AfterDlm := Copy(Source, p + Length(Dlm), Length(Source) - (p + Length(Dlm)) + 1);
    end
    else
    begin
      UpToDlm := Source;
      AfterDlm := '';
    end;
  end;

var
  i: integer;
  Find, Replace, UpToDlm, AfterDlm, Rest: string;

begin
  Result := Source;

  for i := 0 to High(SFR) do
    if IsSplit(SFR[i], Dlm, Find, Replace) and (Find <> '') then
    begin
      Rest := Result;
      Result := '';

      while IsSplit(Rest, Find, UpToDlm, AfterDlm) do
      begin
        Result := Result + UpToDlm + Replace;
        Rest := AfterDlm;
      end;

      Result := Result + UpToDlm;
    end;

  Rest := Result;
  Result := '';
  for i := 1 to Length(Rest) do
    if Word(Rest[i]) < 32 then
      Result := Result + '&#' + IntToStr(Word(Rest[i])) + ';'
    else
      Result := Result + Rest[i];
end;

function HasSpecialChars(const s: string): Boolean;
var
  i: Integer;
begin
  Result := True;

  for i := 1 to Length(s) do
    case s[i] of
      '<', '>', '&': Exit;
      else if Word(S[i]) < 32 then
        Exit
    end;

  Result := False
end;

function GetBorderRadius(Curve: Integer): string;
begin
  if Curve < 1 then
    Result := GetBorderRadius(2)
  else
    Result := IntToStr(Curve * 4) + 'pt'
end;

function GetColor(Color: TColor): string;
begin
  case Color of
    clAqua:    Result := 'aqua';
    clBlack:   Result := 'black';
    clBlue:    Result := 'blue';
    clFuchsia: Result := 'fuchsia';
    clGray:    Result := 'gray';
    clGreen:   Result := 'green';
    clLime:    Result := 'lime';
    clLtGray:  Result := 'lightgray';
    clMaroon:  Result := 'maroon';
    clNavy:    Result := 'navy';
    clOlive:   Result := 'olive';
    clPurple:  Result := 'purple';
    clRed:     Result := 'red';
    clTeal:    Result := 'teal';
    clWhite:   Result := 'white';
    clYellow:  Result := 'yellow';

    clNone:    Result := 'transparent';
  else
    if Color and $ff000000 <> 0 then
      Result := GetColor(GetSysColor(Color and $ffffff))
    else
      Result := HTMLRGBColor(Color)
  end
end;

function IfStr(Flag: Boolean; const sTrue: string; sFalse: string = ''): string;
begin
  if Flag then
    Result := sTrue
  else
    Result := sFalse;
end;

{ TfrxPictureStorage }

constructor TfrxPictureStorage.Create(const WorkDir: string; Prefix: string = '');
begin
  FHashes := TList.Create;

  if (WorkDir = '') or (WorkDir[Length(WorkDir)] = PathDelim) then
    FWorkDir := WorkDir
  else
    FWorkDir := WorkDir + PathDelim;
  FPrefix := Prefix;
end;

destructor TfrxPictureStorage.Destroy;
begin
  FHashes.Free;
  inherited;
end;

class function TfrxPictureStorage.GetInfo(Pic: TGraphic): TfrxPictureInfo;
var
  cn: string;
begin
  cn := Pic.ClassName;

  with Result do
    if cn = 'TMetafile' then
    begin
      Extension := '.emf';
      Mimetype := 'image/metafile';
    end
    else if cn = 'TBitmap' then
    begin
      Extension := '.bmp';
      Mimetype := 'image/bitmap';
    end
    else if (cn = 'TPngImage') or (cn = {$IFNDEF FPC}'TPNGObject'
    {$ELSE}'TPortableNetworkGraphic'{$ENDIF}) then
    begin
      Extension := '.png';
      Mimetype := 'image/png';
    end
    else if cn = 'TJPEGImage' then
    begin
      Extension := '.jpg';
      Mimetype := 'image/jpeg';
    end
    else
    begin
      Extension := '.pic';
      Mimetype := 'image/unknown';
    end
end;

function TfrxPictureStorage.GetHash(Stream: TMemoryStream): Integer;
begin
  TCryptoHash.Hash('Jenkins', Result, SizeOf(Result), Stream.Memory^, Stream.Size)
end;

function TfrxPictureStorage.Save(Pic: TGraphic): string;
var
  Stream: TMemoryStream;
  Ext: string;
  Hash, i: Integer;
begin
  Stream := TMemoryStream.Create;
  Pic.SaveToStream(Stream);
  Ext := GetInfo(Pic).Extension;
  Hash := GetHash(Stream);

  i := FHashes.IndexOf(Pointer(Hash));

  try
    if i >= 0 then
      Result := FPrefix + IntToStr(i) + Ext
    else
    begin
      Result := FPrefix + IntToStr(FHashes.Count) + Ext;
      Stream.SaveToFile(FWorkDir + Result);
      FHashes.Add(Pointer(Hash));
    end
  finally
    Stream.Free;
  end;
end;

{ TfrxPicture }

constructor TfrxPicture.Create(Format: TfrxPictureFormat; Width, Height: Integer);
begin
  case Format of
    pfPNG:
      begin
        {$IFNDEF FPC}
        FGraphic := TPngObject.CreateBlank(COLOR_RGB, 8, Width, Height);
        FCanvas := TPngObject(FGraphic).Canvas;
        {$ELSE}
        FGraphic :=  TPortableNetworkGraphic.Create;
        FGraphic.Width := Width;
        FGraphic.Height := Height;
        FCanvas := TPortableNetworkGraphic(FGraphic).Canvas;
        {$ENDIF}
      end;
    {$IFNDEF FPC}
    pfEMF:
      begin
        FGraphic := TMetafile.Create;
        //FGraphic.SetSize(Width, Height);
        FGraphic.Width := Width;
        FGraphic.Height := Height;
        FCanvas := TMetafileCanvas.Create(TMetafile(FGraphic), 0);
      end;
    {$ENDIF}

    pfBMP:
      begin
        FGraphic := TBitmap.Create;
        FGraphic.Width := Width;
        FGraphic.Height := Height;
        //FGraphic.SetSize(Width, Height);
        FCanvas := TBitmap(FGraphic).Canvas;
      end;

    pfJPG:
      begin
        FGraphic := TJPEGImage.Create;
        FBitmap := TBitmap.Create;
        //FBitmap.SetSize(Width, Height);
        FBitmap.Width := Width;
        FBitmap.Height := Height;
        FCanvas := FBitmap.Canvas;
      end;

    else
      raise Exception.Create('Unknown picture format');
  end;

  FFormat := Format;
end;

destructor TfrxPicture.Destroy;
begin
  FGraphic.Free;
  inherited;
end;

procedure TfrxPicture.SetTransparentColor(TransparentColor: TColor);
begin
  if FFormat = pfPNG then
    (FGraphic as {$IFNDEF FPC}TPngObject{$ELSE}TPortableNetworkGraphic{$ENDIF}).TransparentColor := TransparentColor;
end;

procedure TfrxPicture.FillColor(Color: TColor);
begin
  Canvas.Brush.Color := Color;
  Canvas.FillRect(Canvas.ClipRect);
end;

function TfrxPicture.Release: TGraphic;
begin
  case FFormat of
    {$IFNDEF FPC}
    pfEMF:
      FCanvas.Free;
    {$ENDIF}
    pfJPG:
      begin
        FGraphic.Assign(FBitmap);
        FBitmap.Free;
      end;
  end;

  FCanvas := nil;
  Result := FGraphic;
end;

{ TfrxCSS }

constructor TfrxCSS.Create;
begin
  FStyles := TObjList.Create;
  FStyleHashes := TList.Create;
end;

destructor TfrxCSS.Destroy;
begin
  FStyles.Free;
  FStyleHashes.Free;
  inherited;
end;

function TfrxCSS.GetHash(const s: string): Integer;
begin
  if s = '' then
    Result := -1
  else
    TCryptoHash.Hash('Jenkins', Result, SizeOf(Result), s[1], Length(s)*SizeOf(s[1]))
end;

function TfrxCSS.GetStyle(i: Integer): TfrxCSSStyle;
begin
  if i < GetStylesCount then
    Result := TfrxCSSStyle(FStyles[i])
  else
    Result := nil
end;

function TfrxCSS.GetStyleName(i: Integer): string;
begin
  { There're two kinds of styles: with automatically generated names
    (added via Add(TfrxCSSStyle) and with specified names (added via
    Add(string)). This function returns a name for a style with
    automatically generated style. }

  if FStyleHashes[i] = nil then
    raise Exception.CreateFmt('Cannot generate style name for style #%d', [i]);

  Result := 's' + IntToStr(i)
end;

function TfrxCSS.GetStylesCount: Integer;
begin
  Result := FStyles.Count
end;

function TfrxCSS.Add(Style: TfrxCSSStyle): string;
var
  i: Integer;
  s: string;
  h: Integer;
begin
  s := Style.Text;
  h := GetHash(s);

  if h <> 0 then
    for i := 0 to GetStylesCount - 1 do
      if Integer(FStyleHashes[i]) = h then
        if GetStyle(i).Text = s then
        begin
          Style.Free;
          Result := GetStyleName(i);
          Exit;
        end;

  FStyles.Add(Style);
  FStyleHashes.Add(Pointer(h));

  Result := GetStyleName(GetStylesCount - 1);
  Style.Name := '.' + Result;
end;

function TfrxCSS.Add(const StyleName: string): TfrxCSSStyle;
begin
  Result := TfrxCSSStyle.Create;
  Result.Name := StyleName;

  FStyles.Add(Result);
  FStyleHashes.Add(nil); // zero hash
end;

procedure TfrxCSS.Save(Stream: TStream; Formatted: Boolean);

  function Encode(const s: string): string;
  begin
    Result := string(UTF8Encode(s))
  end;

  procedure Puts(const Text: string);
  var
    s: AnsiString;
  begin
    s := AnsiString(Text);
    Stream.Write(s[1], Length(s));
  end;

var
  i: Integer;
  Sep: string;
begin
  Sep := IfStr(Formatted, #13#10);

  for i := 0 to GetStylesCount - 1 do
    with GetStyle(i) do
      Puts(This.Name + Sep + '{' +
        Encode(This.Text(Formatted)) + Sep + '}' + Sep);
end;

function TfrxCSS.Style(const StyleName: string): TfrxCSSStyle;
var
  I: Integer;
begin
  for I := 0 to GetStylesCount - 1 do
    if GetStyle(I).Name = StyleName then
    begin
      Result := GetStyle(I);
      Exit;
    end;
  Result := TfrxCSSStyle.Create;
  Result.Name := StyleName;
  FStyles.Add(Result);
  FStyleHashes.Add(nil); // zero hash
end;

{ TfrxCSSStyle }

procedure TfrxCSSStyle.AssignTo(Dest: TfrxCSSStyle);
var
  i: Integer;
begin
  for i := 0 to Count - 1 do
    Dest[FKeys[i]] := FValues[i]
end;

constructor TfrxCSSStyle.Create;
begin
  FKeys := TStringList.Create;
  FValues := TStringList.Create;
end;

function TfrxCSSStyle.Count: Integer;
begin
  Result := FKeys.Count
end;

destructor TfrxCSSStyle.Destroy;
begin
  FKeys.Free;
  FValues.Free;
  inherited
end;

function TfrxCSSStyle.GetStyle(Index: string): string;
var
  i: Integer;
begin
  Result := '';
  if (Index <> '') then
  begin
    i := FKeys.IndexOf(Index);
    if i <> -1 then
      Result := FValues[i];
  end;
end;

procedure TfrxCSSStyle.SetPrefixStyle(Index: string; const Value: string);
begin
  if (Index <> '') and (Value <> '') then
  begin
    SetStyle(Index, Value);
    SetStyle('-webkit-' + Index, Value);
    SetStyle('-moz-' + Index, Value);
    SetStyle('-ms-' + Index, Value);
    SetStyle('-o-' + Index, Value);
  end;
end;

procedure TfrxCSSStyle.SetStyle(Index: string; const Value: string);
begin
  if (Index <> '') and (Value <> '') then
  begin
    FKeys.Add(Index);
    FValues.Add(Value);
  end;
end;

function TfrxCSSStyle.Text(Formatted: Boolean): string;
var
  i: Integer;
  function CheckSmall(const AFont: string): Boolean;
  begin
    Result := (Pos('8pt', AFont) > 0) or (Pos('7pt', AFont) > 0) or (Pos('9pt', AFont) > 0);

  end;
begin
  Result := '';
  for i := 0 to Count - 1 do
    if FValues[i] <> '' then
    begin
      // Костыль, чтоб текст не выходил за пределы. В Книге например.
      if SameText('font', FKeys[i]) and CheckSmall(FValues[i]) then
      begin
        Result := Result + IfStr(Formatted, #13#10#9) + 'line-height' +
        IfStr(Formatted, ': ', ':') + '110% !important';
        if Result[Length(Result)] <> ';' then
          Result := Result + ';';
      end;
      Result := Result + IfStr(Formatted, #13#10#9) + FKeys[i] +
      IfStr(Formatted, ': ', ':') + string(UTF8Encode(FValues[i]));
      if Result[Length(Result)] <> ';' then
        Result := Result + ';';
    end;
end;

function TfrxCSSStyle.This: TfrxCSSStyle;
begin
  Result := Self
end;

end.

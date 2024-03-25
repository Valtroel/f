{******************************************}
{                                          }
{             FastReport v5.0              }
{          Barcode Add-in object           }
{                                          }
{         Copyright (c) 1998-2014          }
{         by Alexander Tzyganenko,         }
{            Fast Reports Inc.             }
{                                          }
{******************************************}

unit frxBarcode2D;

interface

{$I frx.inc}

uses
{$IFDEF FPC}
  LCLType, LMessages, LazHelper, LCLIntf,
{$ELSE}
  Windows, Messages,
{$ENDIF}
  SysUtils, Classes, Graphics, Types, Controls,
  Forms, Dialogs,
  StdCtrls, Menus, frxClass, ExtCtrls, frxdesgn, frxBarcodePDF417,
  frxBarcodeDataMatrix, frxBarcodeQR, frxBarcode2DBase, frxBarcodeProperties,
  Variants;

type
  TfrxBarcode2DType = (bcCodePDF417, bcCodeDataMatrix, bcCodeQR);

  TfrxBarcode2DView = class(TfrxStretcheable)
  private

    FBarCode: TfrxBarcode2DBase;
    FBarType: TfrxBarcode2DType;
    FHAlign: TfrxHAlign;
    FProp: TfrxBarcode2DProperties;
    FExpression: String;
    procedure SetZoom(z: Extended);
    function GetZoom: Extended;
    procedure SetRotation(v: integer);
    function GetRotation: integer;
    procedure SetShowText(v: boolean);
    function GetShowText: boolean;
    procedure SetText(v: String);
    function GetText: string;
    procedure SetFontScaled(v: boolean);
    function GetFontScaled: boolean;
    procedure SetErrorText(v: string);
    function GetErrorText: string;
    procedure SetQuietZone(v: integer);
    function GetQuietZone: integer;

    procedure SetProp(v: TfrxBarcode2DProperties);
    procedure SetBarType(v: TfrxBarcode2DType);
  public

    constructor Create(AOwner: TComponent); override;
    constructor DesignCreate(AOwner: TComponent; Flags: Word); override;
    destructor Destroy; override;
    procedure Draw(Canvas: TCanvas; ScaleX, ScaleY, OffsetX,
      OffsetY: Extended); override;
    class function GetDescription: String; override;
    procedure GetData; override;
    function GetRealBounds: TfrxRect; override;
    function CalcHeight: Extended; override;
    function DrawPart: Extended; override;
  published
    property Expression: String read FExpression write FExpression;
    property BarType: TfrxBarcode2DType read FBarType write SetBarType;
    property BarProperties: TfrxBarcode2DProperties read FProp write SetProp;
    property BrushStyle;
    property Color;
    property Cursor;
    property DataField;
    property DataSet;
    property DataSetName;
    property Frame;
    property HAlign: TfrxHAlign read FHAlign write FHAlign default haLeft;
    property Rotation: integer read GetRotation write SetRotation;
    property ShowText: boolean read GetShowText write SetShowText;
    property TagStr;
    property Text: String read GetText write SetText;
    property URL;
    property Zoom: Extended read GetZoom write SetZoom;
    property Font;
    property FontScaled: boolean read GetFontScaled write SetFontScaled;
    property ErrorText: string read GetErrorText write SetErrorText;
    property QuietZone: integer read GetQuietZone write SetQuietZone;

  end;

implementation

uses
{$IFNDEF NO_EDITORS}
  frxBarcodeEditor,
{$ENDIF}
  frxRes, frxUtils, frxDsgnIntf, frxBarcode2DRTTI;

type
  TfrxBarcode2DPropertiesProperty = class(TfrxClassProperty)
  public
    function GetAttributes: TfrxPropertyAttributes; override;
  end;

  { TfrxBarcode2DView }

function TfrxBarcode2DView.CalcHeight: Extended;
var
  r: TfrxRect;
  h: Extended;
begin
  { 2D barcode may grow, so we need to emulate strechable object }
  h := Height;
  r := GetRealBounds;
  Result := r.Bottom - r.Top;
  Height := h;
end;

constructor TfrxBarcode2DView.Create(AOwner: TComponent);
begin
  inherited;
  FBarCode := TfrxBarcodePDF417.Create;
  FBarType := bcCodePDF417;
  FBarCode.Font.Assign(Font);
  Width := 0;
  Height := 0;
  FProp := TfrxPDF417Properties.Create;
  FProp.SetWhose(FBarCode);
  StretchMode := smActualHeight;
end;

constructor TfrxBarcode2DView.DesignCreate(AOwner: TComponent; Flags: Word);
begin
  inherited;
  BarType := TfrxBarcode2DType(Flags);
end;

destructor TfrxBarcode2DView.Destroy;
begin
  FBarCode.Free;
  FProp.Free;
  inherited Destroy;
end;

procedure TfrxBarcode2DView.SetProp(v: TfrxBarcode2DProperties);
begin
  FProp.Assign(v);
end;

procedure TfrxBarcode2DView.SetBarType(v: TfrxBarcode2DType);
begin
  if FBarType = v then
    exit;
  if v = bcCodePDF417 then
  begin
    FBarType := v;
    FBarCode.Free;
    FBarCode := TfrxBarcodePDF417.Create;
    FProp.Free;
    FProp := TfrxPDF417Properties.Create;
    FProp.SetWhose(FBarCode);
    if (Tfrxcomponent(self).Report <> nil) and
      (Tfrxcomponent(self).Report.Designer <> nil) then
      TfrxCustomDesigner(Tfrxcomponent(self).Report.Designer).UpdateInspector;
  end
  else if v = bcCodeDataMatrix then
  begin
    FBarType := v;
    FBarCode.Free;
    FBarCode := TfrxBarcodeDataMatrix.Create;
    FProp.Free;
    FProp := TfrxDataMatrixProperties.Create;
    FProp.SetWhose(FBarCode);
    if (Tfrxcomponent(self).Report <> nil) and
      (Tfrxcomponent(self).Report.Designer <> nil) then
      TfrxCustomDesigner(Tfrxcomponent(self).Report.Designer).UpdateInspector;
  end
  else if v = bcCodeQR then
  begin
    FBarType := v;
    FBarCode.Free;
    FBarCode := TfrxBarcodeQR.Create;
    FProp.Free;
    FProp := TfrxQRProperties.Create;
    FProp.SetWhose(FBarCode);
    if (Tfrxcomponent(self).Report <> nil) and
      (Tfrxcomponent(self).Report.Designer <> nil) then
      TfrxCustomDesigner(Tfrxcomponent(self).Report.Designer).UpdateInspector;
  end;
end;

procedure TfrxBarcode2DView.SetZoom(z: Extended);
begin
  FBarCode.Zoom := z;
end;

function TfrxBarcode2DView.GetZoom: Extended;
begin
  result := FBarCode.Zoom;
end;

procedure TfrxBarcode2DView.SetRotation(v: integer);
begin
  FBarCode.Rotation := v;
end;

function TfrxBarcode2DView.GetRotation: integer;
begin
  result := FBarCode.Rotation;
end;

procedure TfrxBarcode2DView.SetShowText(v: boolean);
begin
  FBarCode.ShowText := v;
end;

function TfrxBarcode2DView.GetShowText: boolean;
begin
  result := FBarCode.ShowText;
end;

procedure TfrxBarcode2DView.SetText(v: String);
begin
  FBarCode.Text := v;
end;

function TfrxBarcode2DView.GetText: string;
begin
  result := FBarCode.Text;
end;

procedure TfrxBarcode2DView.SetFontScaled(v: boolean);
begin
  FBarCode.FontScaled := v;
end;

function TfrxBarcode2DView.GetFontScaled: boolean;
begin
  result := FBarCode.FontScaled;
end;

procedure TfrxBarcode2DView.SetErrorText(v: string);
begin
  FBarCode.ErrorText := v;
end;

function TfrxBarcode2DView.GetErrorText: string;
begin
  result := FBarCode.ErrorText;
end;

procedure TfrxBarcode2DView.SetQuietZone(v: integer);
begin
  FBarCode.QuietZone := v;
end;

function TfrxBarcode2DView.GetQuietZone: integer;
begin
  result := FBarCode.QuietZone;
end;

procedure TfrxBarcode2DView.GetData;
begin
  inherited;
  if IsDataField then
    FBarCode.Text := VarToStr(DataSet.Value[DataField])
  else if FExpression <> '' then
    FBarCode.Text := VarToStr(Report.Calc(FExpression));
end;

class function TfrxBarcode2DView.GetDescription: String;
begin
  result := frxResources.Get('obBarC');
end;

procedure TfrxBarcode2DView.Draw(Canvas: TCanvas;
  ScaleX, ScaleY, OffsetX, OffsetY: Extended);
var

  w, h, tmp: Extended;
  scaledFontCorrX, scaledFontCorrY: integer;
  DrawRect: TRect;

begin
  case Round(Rotation) of
    0 .. 44:
      Rotation := 0;
    45 .. 135:
      Rotation := 90;
    136 .. 224:
      Rotation := 180;
    225 .. 315:
      Rotation := 270;
  else
    Rotation := 0;
  end;

  FBarCode.Font.Assign(Font);

  if Color = clNone then
    FBarCode.Color := clWhite
  else
    FBarCode.Color := Color;

  w := FBarCode.Width;
  h := FBarCode.Height;

  if FontScaled or (not ShowText) then
  begin
    scaledFontCorrX := 0;
    scaledFontCorrY := 0;
  end
  else
  begin
    scaledFontCorrY := FBarCode.GetFooterHeight;
    scaledFontCorrX := 0;
    if (Rotation = 90) or (Rotation = 270) then
    begin
      scaledFontCorrX := FBarCode.GetFooterHeight;
      scaledFontCorrY := 0;
    end;
  end;

  if (Rotation = 90) or (Rotation = 270) then
  begin
    tmp := w;
    w := h;
    h := tmp;
  end;

  Height := (h - scaledFontCorrY) * Zoom + scaledFontCorrY;
  Width := (w - scaledFontCorrX) * Zoom + scaledFontCorrX;
  if Frame.DropShadow then
  begin
    Height := Height + Round(Frame.ShadowWidth);
    Width := Width + Round(Frame.ShadowWidth);
  end;

  // if FHAlign = haRight then
  // Left := Left + SaveWidth - Width
  // else if FHAlign = haCenter then
  // Left := Left + (SaveWidth - Width) / 2;

  BeginDraw(Canvas, ScaleX, ScaleY, OffsetX, OffsetY);

  if FBarCode.ErrorText <> '' then
  begin
    with Canvas do
    begin
      Font.Name := 'Arial';
      Font.Size := Round(8 * ScaleY);
      Font.Color := clRed;
      Pen.Color := clBlack;
      DrawRect := Rect(FX + 2, FY + 2, FX1, FY1);
      DrawText(Handle, PChar(FBarCode.ErrorText), Length(FBarCode.ErrorText),
        DrawRect, DT_WORDBREAK);
      exit;
    end;
  end;

  DrawBackground;
  FBarCode.Draw2DBarcode(Canvas, FScaleX, FScaleY, FX, FY);
  DrawFrame;
end;

function TfrxBarcode2DView.DrawPart: Extended;
begin
  Result := Height;
end;

function TfrxBarcode2DView.GetRealBounds: TfrxRect;
var
  extra1, extra2: integer;
  bmp: TBitmap;
begin
  bmp := TBitmap.Create;
  Draw(bmp.Canvas, 1, 1, 0, 0);

  result := inherited GetRealBounds;
  extra1 := 0;
  extra2 := 0;

  (* if (Rotation = 0) or (Rotation = 180) then
    begin
    with bmp.Canvas do
    begin
    {Font.Name := 'Arial';
    Font.Size := 9;
    Font.Style := []; }
    Font.Assign(Self.Font);
    txtWidth := TextWidth(String(FBarcode.Text));
    if Width < txtWidth then
    begin
    extra1 := Round((txtWidth - Width) / 2) + 2;
    extra2 := extra1;
    end;
    end;
    end; *)

  case Rotation of
    0:
      begin
        result.Left := result.Left - extra1;
        result.Right := result.Right + extra2;
      end;
    90:
      begin
        result.Bottom := result.Bottom + extra1;
        result.Top := result.Top - extra2;
      end;
    180:
      begin
        result.Left := result.Left - extra2;
        result.Right := result.Right + extra1;
      end;
    270:
      begin
        result.Bottom := result.Bottom + extra2;
        result.Top := result.Top - extra1;
      end;
  end;

  bmp.Free;
end;

{ TfrxBarcode2DPropertiesProperty }

function TfrxBarcode2DPropertiesProperty.GetAttributes: TfrxPropertyAttributes;
begin
  result := [paSubProperties, paReadOnly]; // no multiselect!
end;

initialization
frxHideProperties(TfrxBarcode2DView, 'StretchMode');
frxPropertyEditors.Register(TypeInfo(TfrxBarcode2DProperties), nil, '',
  TfrxBarcode2DPropertiesProperty);

end.



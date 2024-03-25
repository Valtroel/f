unit frxExportPDFLaz;

{******************************************}
{                                          }
{             FastReport v5.0              }
{            PDF export filter             }
{                                          }
{         Copyright (c) 1998-2015          }
{          by Alexander Fediachov,         }
{             Fast Reports Inc.            }
{                                          }
{******************************************}
{      haBlock alignment improved by:      }
{              Nikolay Zverev              }
{            www.delphinotes.ru            }
{******************************************}



interface

{$I frx.inc}

uses
  {$IFDEF NONWINFPC}cwstring,{$ENDIF}
  SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  LCLType, LCLIntf, LazHelper,LazUTF8,
  StdCtrls, ExtCtrls, Printers, frxClass,
  ComCtrls, Variants, frxRC4, frxTrueTypeLaz
;

{$IFNDEF NONWINFPC}
function GetOutlineTextMetrics(_para1:HDC; _para2:UINT;
  _para3:Pointer):UINT;stdcall; external 'gdi32' name 'GetOutlineTextMetricsA';
{$ENDIF}

type

  {$IFDEF FPC}
  TList = TFPList;
  {$ENDIF}

  TRGBAWord = packed record
    Blue: Byte;
    Green: Byte;
    Red: Byte;
    Alpha: Byte;
  end;

  PRGBAWord = ^TRGBAWordArray;
  TRGBAWordArray = array[0..4095] of TRGBAWord;

  TfrxPDFEncBit = (ePrint, eModify, eCopy, eAnnot);
  TfrxPDFEncBits = set of TfrxPDFEncBit;

  TfrxPDFXObjectHash = array[0..15] of Byte; // MD5
  TfrxPDFXObject = record
    ObjId: Integer; // id that appears in 'id 0 R'
    Hash: TfrxPDFXObjectHash;
  end;



  TfrxPDFExportDialog = class(TForm)
    PageControl1: TPageControl;
    ExportPage: TTabSheet;
    InfoPage: TTabSheet;
    SecurityPage: TTabSheet;
    ViewerPage: TTabSheet;
    OkB: TButton;
    CancelB: TButton;
    SaveDialog1: TSaveDialog;
    OpenCB: TCheckBox;
    GroupQuality: TGroupBox;
    PDFACB: TCheckBox;
    EmbeddedCB: TCheckBox;
    PrintOptCB: TCheckBox;
    OutlineCB: TCheckBox;
    BackgrCB: TCheckBox;
    GroupPageRange: TGroupBox;
    DescrL: TLabel;
    AllRB: TRadioButton;
    CurPageRB: TRadioButton;
    PageNumbersRB: TRadioButton;
    PageNumbersE: TEdit;
    SecGB: TGroupBox;
    OwnPassL: TLabel;
    UserPassL: TLabel;
    OwnPassE: TEdit;
    UserPassE: TEdit;
    PermGB: TGroupBox;
    PrintCB: TCheckBox;
    ModCB: TCheckBox;
    CopyCB: TCheckBox;
    AnnotCB: TCheckBox;
    DocInfoGB: TGroupBox;
    TitleL: TLabel;
    TitleE: TEdit;
    AuthorE: TEdit;
    AuthorL: TLabel;
    SubjectL: TLabel;
    SubjectE: TEdit;
    KeywordsL: TLabel;
    KeywordsE: TEdit;
    CreatorE: TEdit;
    CreatorL: TLabel;
    ProducerL: TLabel;
    ProducerE: TEdit;
    ViewerGB: TGroupBox;
    HideToolbarCB: TCheckBox;
    HideMenubarCB: TCheckBox;
    HideWindowUICB: TCheckBox;
    FitWindowCB: TCheckBox;
    CenterWindowCB: TCheckBox;
    PrintScalingCB: TCheckBox;
    Quality: TEdit;
    Label2: TLabel;
    TransparentCB: TCheckBox;
    procedure FormCreate(Sender: TObject);
    procedure PageNumbersEChange(Sender: TObject);
    procedure PageNumbersEKeyPress(Sender: TObject; var Key: Char);
    procedure FormKeyDown(Sender: TObject; var Key: Word;
      Shift: TShiftState);
  end;

  { TfrxPDFFont }

  TfrxPDFFont = class
  private
    tempBitmap:TBitmap;
    TrueTypeTables: TrueTypeCollection;
    //procedure FillFSFonts;
    function GetGlyphIndices(text: WideString; glyphs: PWord;
      widths: PInteger; rtl: boolean): integer;
  public
    Index: Integer;
    ttf:  TrueTypeFont;
    Widths: TList;
    UsedAlphabet: TList;
    UsedAlphabetUnicode: TList;
    FComposedList: TList;
    TextMetric: {$IFDEF NONWINFPC}frxTrueTypeLaz.OutlineTextMetric
                           {$ELSE}LazHelper.OUTLINETEXTMETRICA {$ENDIF};
    Reference: Longint;
    Name: AnsiString;
    Saved: Boolean;
    PackFont: Boolean;
    SourceFont: TFont;
    FontData: TMemoryStream;
    FontDataSize: Longint;
    PDFdpi_divider: double;
    FDpiFX: double;
    //FSFonts:TStringList;
    LastRemappedStrWidth: Integer;
    LastRemappedStrSpacesCount: Integer;
    FSubstitutedFont: String;
    constructor Create(Font:TFont);
    destructor Destroy; override;
    procedure Cleanup;
    procedure FillOutlineTextMetrix;
    procedure GetFontFile;
    procedure PackTTFFont;
    function RemapString(str: WideString; rtl: Boolean): WideString;
    function GetFontName: AnsiString;
  end;

  { TfrxPDFOutlineNode }

  TfrxPDFOutlineNode = class
  public
    Number:     Integer;
    Dest:       Integer;  // Index to a page referred to by this outline node
    Top:        Integer;  // Position on the referred to page
    CountTree:  Integer;  // Number of all descendant nodes
    Count:      Integer;  // Number of all first-level descendants
    Title:      string;

    First:  TfrxPDFOutlineNode; // The first first-level descendant
    Last:   TfrxPDFOutlineNode; // The last first-level descendant
    Next:   TfrxPDFOutlineNode; // The next neighbouring node
    Prev:   TfrxPDFOutlineNode; // The previous neighbouring node
    Parent: TfrxPDFOutlineNode; // The parent node of this node

    constructor Create;
    destructor Destroy; override;
  end;

  TfrxPDFPage = class
  public
    Height: Double;
  end;

  TfrxPDFAnnot = class
  public
    Number: Integer;
    Rect: String;
    Hyperlink: String;
    DestPage: Integer;
    DestY: Integer;
  end;

  { TfrxPDFExport }

  TfrxPDFExport = class(TfrxCustomExportFilter)
  private
    FCompressed: Boolean;
    FEmbedded: Boolean;
    FEmbedProt: Boolean;
    FOpenAfterExport: Boolean;
    FPrintOpt: Boolean;
    FPages: TList;
    FOutline: Boolean;
    FQuality: Integer;
    FPreviewOutline: TfrxCustomOutline;
    FSubject: WideString;
    FAuthor: WideString;
    FBackground: Boolean;
    FCreator: WideString;
    FTags: Boolean;
    FProtection: Boolean;
    FUserPassword: AnsiString;
    FOwnerPassword: AnsiString;
    FProtectionFlags: TfrxPDFEncBits;
    FKeywords: WideString;
    FTitle: WideString;
    FProducer: WideString;
    FPrintScaling: Boolean;
    FFitWindow: Boolean;
    FHideMenubar: Boolean;
    FCenterWindow: Boolean;
    FHideWindowUI: Boolean;
    FHideToolbar: Boolean;
    FTransparency: Boolean;
    FSaveOriginalImages: Boolean;

    pdf: TStream;

    FRootNumber: longint;
    FPagesNumber: longint;
    FInfoNumber: longint;
    FStartXRef: longint;

    FFonts: TList;
    FPageFonts: TList;
    FXRef: TStringList;
    FPagesRef: TStringList;

    FSubstitutedFonts: TStringList;

    FWidth: Extended;
    FHeight: Extended;
    FMarginLeft: Extended;
    FMarginWoBottom: Extended;
    FMarginTop: Extended;

    FEncKey: AnsiString;
    FOPass: AnsiString;
    FUPass: AnsiString;

    FEncBits: Cardinal;
    FFileID: AnsiString;

    FDivider: Extended;
    FLastColor: TColor;
    FLastColorResult: String;

    OutStream: TMemoryStream;

    FXObjects: array of TfrxPDFXObject;
    FUsedXObjects: array of Integer; // XObjects' ids used within the current page
    FPicTotalSize: Cardinal;  // size occupied by all pictures

    { When an anchor is being added, two changes are made:

        - a link object is written to the document
        - a reference to the link object is added to /Annots field of the page

      FPageAnnots contains text of /Annots field.
      This stream is updated by WriteLink and its auxiliary routines. }

    FPageAnnots: TMemoryStream;
    FAnnots: TList;

    FPdfA: boolean;
    FMetaFileId: longint;
    FStructId: longint;
    FColorProfileId: longint;

    function PrepXrefPos(pos: Longint): String;
    function GetPDFDash(const LineStyle: TfrxFrameStyle; Width: Extended): String;
    procedure Write(Stream: TStream; const S: AnsiString);{$IFDEF Delphi12} overload;
    procedure Write(Stream: TStream; const S: String); overload;
{$ENDIF}
    procedure WriteLn(Stream: TStream; const S: AnsiString);{$IFDEF Delphi12} overload;
    procedure WriteLn(Stream: TStream; const S: String); overload;
{$ENDIF}
    function GetID: AnsiString;
    function CryptStr(Source: AnsiString; Key: AnsiString; Enc: Boolean; id: Integer): AnsiString;
    function CryptStream(Source: TStream; Target: TStream; Key: AnsiString; id: Integer): AnsiString;
    function PrepareString(const Text: WideString; Key: AnsiString; Enc: Boolean; id: Integer): AnsiString;
    function EscapeSpecialChar(TextStr: AnsiString): AnsiString;
    function StrToUTF16(const Value: WideString): AnsiString;
    function StrToUTF16H(const Value: WideString): AnsiString;
    function PMD52Str(p: Pointer): AnsiString;
    function PadPassword(Password: AnsiString): AnsiString;
    procedure PrepareKeys;
    procedure SetProtectionFlags(const Value: TfrxPDFEncBits);
    procedure Clear;
    procedure WriteFont(pdfFont: TfrxPDFFont);
    procedure AddObject(const Obj: TfrxView);
    function StrToHex(const Value: WideString): AnsiString;
    function StrToHexSp(const SourceStr, Value: WideString; SpaceAdjustment: Extended): AnsiString;
    function AddPage(Page: TfrxReportPage): TfrxPDFPage;
    function ObjNumber(FNumber: longint): String;
    function ObjNumberRef(FNumber: longint): String;
    function UpdateXRef: longint;
    function GetPDFColor(const Color: TColor): String;

    function FindXObject(const Hash: TfrxPDFXObjectHash): Integer;
    function AddXObject(Id: Integer; const Hash: TfrxPDFXObjectHash): Integer;
    procedure ClearXObject;
    procedure GetStreamHash(out Hash: TfrxPDFXObjectHash; S: TStream);

    procedure AddStructure;
    procedure AddMetaData;
    procedure AddColorProfile;
    procedure WritePDFStream(target: TStream; source: TMemoryStream; id: longint; compressed: Boolean;
      encrypted: Boolean; startingBrackets: Boolean; endingBrackets: Boolean; enableLength2: Boolean);
    procedure DrawFrameLine(Color: TColor; FrameStyle: TfrxFrameStyle; FrameWidth: extended;
                          LeftBegin, TopBegin, LeftEnd, TopEnd: string);

  public
    constructor Create(AOwner: TComponent); override;
    destructor Destroy; override;
    class function GetDescription: String; override;
    function ShowModal: TModalResult; override;
    function Start: Boolean; override;
    procedure ExportObject(Obj: TfrxComponent); override;
    procedure Finish; override;
    procedure StartPage(Page: TfrxReportPage; Index: Integer); override;
    procedure FinishPage(Page: TfrxReportPage; Index: Integer); override;
    property SaveOriginalImages: Boolean read FSaveOriginalImages write FSaveOriginalImages;
  published
    property Compressed: Boolean read FCompressed write FCompressed default True;
    property EmbeddedFonts: Boolean read FEmbedded write FEmbedded default False;
    property EmbedFontsIfProtected: Boolean read FEmbedProt write FEmbedProt default True;
    property OpenAfterExport: Boolean read FOpenAfterExport
      write FOpenAfterExport default False;
    property PrintOptimized: Boolean read FPrintOpt write FPrintOpt;
    property Outline: Boolean read FOutline write FOutline;
    property Background: Boolean read FBackground write FBackground;
    property HTMLTags: Boolean read FTags write FTags;
    property OverwritePrompt;
    property Quality: Integer read FQuality write FQuality;
    property Transparency: Boolean read FTransparency write FTransparency;

    property Title: WideString read FTitle write FTitle;
    property Author: WideString read FAuthor write FAuthor;
    property Subject: WideString read FSubject write FSubject;
    property Keywords: WideString read FKeywords write FKeywords;
    property Creator: WideString read FCreator write FCreator;
    property Producer: WideString read FProducer write FProducer;

    property UserPassword: AnsiString read FUserPassword write FUserPassword;
    property OwnerPassword: AnsiString read FOwnerPassword write FOwnerPassword;
    property ProtectionFlags: TfrxPDFEncBits read FProtectionFlags write SetProtectionFlags;

    property HideToolbar: Boolean read FHideToolbar write FHideToolbar;
    property HideMenubar: Boolean read FHideMenubar write FHideMenubar;
    property HideWindowUI: Boolean read FHideWindowUI write FHideWindowUI;
    property FitWindow: Boolean read FFitWindow write FFitWindow;
    property CenterWindow: Boolean read FCenterWindow write FCenterWindow;
    property PrintScaling: Boolean read FPrintScaling write FPrintScaling;
    property PdfA: Boolean read FPdfA write FPdfA;
  end;

//
{ Returns a color in PDF form. }

function PdfColor(Color: TColor): AnsiString;

{ Returns a pair of coordinates in PDF form. }

function PdfPoint(x, y: Double): AnsiString;

{ Moves the pen to the specified point. }

function PdfMove(x, y: Double): AnsiString;

{ Draws a line to the specified point. }

function PdfLine(x, y: Double): AnsiString;

{ Changes the current color. }

function PdfSetColor(Color: TColor): AnsiString;

{ Changes width of the line drawed by the pen.
  The width is measured in points (1/72 of an inch). }

function PdfSetLineWidth(Width: Double): AnsiString;

{ Changes the color of the pen. }

function PdfSetLineColor(Color: TColor): AnsiString;

{ Fills the latest contoured area. }

function PdfFill: AnsiString;

{ Fills a rectangle area. }

function PdfFillRect(Left, Bottom, Right, Top: Double; Color: TColor): AnsiString;

{ Returns either (...) or <...> sequence. }

function PdfString(const Str: WideString): AnsiString;

// list of fonts that do not have bold-italic versions and needs to be simulated
var
  frxPDFFontsNeedStyleSimulation: TStringList;

implementation

uses
  frxUtils,
  FileUtil,
  {$IFDEF NONWINFPC}process, UTF8Process,{$ENDIF}
  frxRes, frxrcExports, frxPreviewPages,
  frxGraphicUtils, frxMD5, frxGzip,
  SyncObjs, Math, frxXML, frxChBox,
  frxCrypto, frxPreview;

const
  PDF_VER = '1.5';
  PDF_DIVIDER = 0.75;
  PDF_MARG_DIVIDER = 0.05;
  PDF_PRINTOPT = 3;
  PDF_PK: array [ 1..32 ] of Byte =
    ( $28, $BF, $4E, $5E, $4E, $75, $8A, $41, $64, $00, $4E, $56, $FF, $FA, $01, $08,
      $2E, $2E, $00, $B6, $D0, $68, $3E, $80, $2F, $0C, $A9, $FE, $64, $53, $69, $7A );
  KAPPA1 = 1.5522847498;
  KAPPA2 = 2 - KAPPA1;

var
  pdfCS: TCriticalSection;
  {$IFDEF NONWINFPC}
  FSFonts:TStringList;
  {$ENDIF}

function PdfColor(Color: TColor): AnsiString;

  function c(x: Integer): AnsiString;
  begin
    if x < 1 then
      Result := '0'
    else if x > 254 then
      Result := '1'
    else
      Result := AnsiString('0.' + IntToStr(x * 100 shr 8));

    { Actually, Result = x * 100 div 255, but
      division by 255 works much slower then
      division by 256. }
  end;

var
r, g, b, rgb: Integer;
begin
  rgb := ColorToRGB(Color);

  r := rgb and $ff;
  g := rgb shr 8 and $ff;
  b := rgb shr 16 and $ff;

  Result := c(r) + ' ' + c(g) + ' ' + c(b);
end;

function PdfPoint(x, y: Double): AnsiString;
begin
  Result := AnsiString(frFloat2Str(x, 2) + ' ' + frFloat2Str(y, 2));
end;

function PdfMove(x, y: Double): AnsiString;
begin
  Result := PdfPoint(x, y) + ' m'#13#10;
end;

function PdfLine(x, y: Double): AnsiString;
begin
  Result := PdfPoint(x, y) + ' l'#13#10;
end;

function PdfSetColor(Color: TColor): AnsiString;
begin
  Result := PdfColor(Color) + ' rg'#13#10;
end;

function PdfSetLineWidth(Width: Double): AnsiString;
begin
  Result := AnsiString(frFloat2Str(Width, 2) + ' w'#13#10);
end;

function PdfSetLineColor(Color: TColor): AnsiString;
begin
  Result := PdfColor(Color) + ' RG'#13#10;
end;

function PdfFill: AnsiString;
begin
  Result := 'B'#13#10;
end;

function PdfFillRect(Left, Bottom, Right, Top: Double; Color: TColor
  ): AnsiString;
begin
  Result := PdfSetLineWidth(0) + PdfSetLineColor(Color) + PdfSetColor(Color) +
    PdfMove(Left, Bottom) + PdfLine(Right, Bottom) + PdfLine(Right, Top) +
    PdfLine(Left, Top) + PdfFill;
end;

function PdfString(const Str: WideString): AnsiString;
{ A string is literal if parentheses in it are balanced and all characters
  are within the printable ASCII characters set. }

function IsLiteralString(const s: WideString): Boolean;
var
  i: Integer;
  nop: Integer; // number of opened parentheses
begin
  Result := False;
  nop := 0;

  for i := 1 to Length(s) do
    if s[i] = '(' then
      Inc(nop)
    else if s[i] = ')' then
      if nop > 0 then
        Dec(nop)
      else
        Exit
    // printable ASCII characters are those with codes 32..126
    else if (Word(s[i]) < 32) or (Word(s[i]) > 126) then
      Exit;

  Result := nop = 0;
end;

function GetLiteralString(const s: WideString): AnsiString;
begin
  Result := '(' + AnsiString(s) + ')'
end;

function GetHexString(const s: WideString): AnsiString;
var
  i: Integer;
  hs: AnsiString;
begin
  SetLength(Result, 2 + Length(s) * 4);
  Result[1] := '<';
  Result[Length(Result)] := '>';

  for i := 1 to Length(s) do
  begin
    hs := AnsiString(IntToHex(Word(s[i]), 4));

    Result[i*4 - 3 + 1] := hs[1];
    Result[i*4 - 3 + 2] := hs[2];
    Result[i*4 - 3 + 3] := hs[3];
    Result[i*4 - 3 + 4] := hs[4];
  end;
end;

begin
if IsLiteralString(Str) then
  Result := GetLiteralString(Str)
else
  Result := GetHexString(Str)
end;


{$R *.lfm}
{$R frxExportPDFMetafile.RES}
{$R frxExportPDFProfile.RES}

{ TfrxPDFExport }

function TfrxPDFExport.PrepXrefPos(pos: Longint): String;
begin
  result := StringOfChar('0',  10 - Length(IntToStr(pos))) + IntToStr(pos)
end;

function TfrxPDFExport.GetPDFDash(const LineStyle: TfrxFrameStyle;
  Width: Extended): String;
var
  dash, dot: String;
begin
  if LineStyle = fsSolid then
    Result := '[] 0 d'
  else
  begin
    dash := frFloat2Str(Width * 6) + ' ';
    dot := frFloat2Str(Width * 2) + ' ';
    if LineStyle = fsDash then
      Result := '[' + dash + '] 0 d'
    else if LineStyle = fsDashDot then
      Result := '[' + dash + dash + dot + dash + '] 0 d'
    else if LineStyle = fsDashDotDot then
      Result := '[' + dash + dash + dot + dash + dot + dash + '] 0 d'
    else if LineStyle = fsDot then
      Result := '[' + dot + dash + '] 0 d'
    else
      Result := '[] 0 d';
  end;
end;

procedure TfrxPDFExport.Write(Stream: TStream; const S: AnsiString);
begin
  Stream.Write(S[1], Length(S));
end;

procedure TfrxPDFExport.WriteLn(Stream: TStream; const S: AnsiString);
var
  lb:string;
begin
  Stream.Write(S[1], Length(S));
  lb := #13#10;
{$IFDEF Delphi12}
  Stream.Write(AnsiChar(#13)+AnsiChar(#10), 2);
{$ELSE}
  Stream.Write(lb[1], 2);
{$ENDIF}

end;

function TfrxPDFExport.GetID: AnsiString;
var
  AGUID: TGUID;
  AGUIDString: widestring;
begin
  CreateGUID(AGUID);
  SetLength(AGUIDString, 39);
  Result := GUIDToString(AGUID);
  //StringFromGUID2(AGUID, PWideChar(AGUIDString), 39);
  //Result := AnsiString(PWideChar(AGUIDString));
  //MD5String(AnsiString(PWideChar(AGUIDString)));
end;
function TfrxPDFExport.CryptStr(Source: AnsiString; Key: AnsiString;
  Enc: Boolean; id: Integer): AnsiString;
var
  k: array [ 1..21 ] of Byte;
  rc4: TfrxRC4;
  s, s1, ss: AnsiString;
begin
  if Enc then
  begin
    rc4 := TfrxRC4.Create;
    try
      s := Key;
      FillChar(k, 21, 0);
      Move(s[1], k, 16);
      Move(id, k [17], 3);
      SetLength(s1, 21);
      MD5Buf(@k, 21, @s1[1]);
      ss := Source;
      SetLength(Result, Length(ss));
      rc4.Start(@s1[1], 16);
      rc4.Crypt(@ss[1], @Result[1], Length(ss));
      Result := EscapeSpecialChar(Result);
    finally
      rc4.Free;
    end;
  end
  else
    Result := EscapeSpecialChar(Source);
end;

function TfrxPDFExport.CryptStream(Source: TStream; Target: TStream;
  Key: AnsiString; id: Integer): AnsiString;
var
  s: AnsiString;
  k: array [ 1..21 ] of Byte;
  rc4: TfrxRC4;
  m1, m2: TMemoryStream;
begin
  FillChar(k, 21, 0);
  Move(Key[1], k, 16);
  Move(id, k[17], 3);
  SetLength(s, 16);
  MD5Buf(@k, 21, @s[1]);
  m1 := TMemoryStream.Create;
  m2 := TMemoryStream.Create;
  rc4 := TfrxRC4.Create;
  try
    m1.LoadFromStream(Source);
    m2.SetSize(m1.Size);
    rc4.Start(@s[1], 16);
    rc4.Crypt(m1.Memory, m2.Memory, m1.Size);
    m2.SaveToStream(Target);
  finally
    m1.Free;
    m2.Free;
    rc4.Free;
  end;
end;

function TfrxPDFExport.PrepareString(const Text: WideString; Key: AnsiString;
  Enc: Boolean; id: Integer): AnsiString;
begin
  if Enc then
    Result := '(' + CryptStr(StrToUTF16(Text), Key, Enc, id) + ')'
  else
    Result := '<' + StrToUTF16H(Text) + '>'
end;

function TfrxPDFExport.EscapeSpecialChar(TextStr: AnsiString): AnsiString;
var
  I: Integer;
begin
  Result := '';
  for I := 1 to Length ( TextStr ) do
    case TextStr [ I ] of
      '(': Result := Result + '\(';
      ')': Result := Result + '\)';
      '\': Result := Result + '\\';
      #13: Result := result + '\r';
      #10: Result := result + '\n';
    else
      Result := Result + AnsiChar(chr ( Ord ( textstr [ i ] ) ));
    end;
end;

function TfrxPDFExport.StrToUTF16(const Value: WideString): AnsiString;
var
  i: integer;
  pwc: ^Word;
begin
  result := #$FE + #$FF;
  for i := 1 to Length(Value) do
  begin
    pwc := @Value[i];
    result := result  + AnsiChar(pwc^ shr 8) + AnsiChar(pwc^ and $FF) ;
  end;
end;

function TfrxPDFExport.StrToUTF16H(const Value: WideString): AnsiString;
var
  i: integer;
  pwc: ^Word;
begin
  result := 'FEFF';
  for i := 1 to Length(Value) do
  begin
    pwc := @Value[i];
    result := result  + AnsiString(IntToHex(pwc^, 4));
  end;
end;

function TfrxPDFExport.PMD52Str(p: Pointer): AnsiString;
begin
  SetLength(Result, 16);
  Move(p^, Result[1], 16);
end;

function TfrxPDFExport.PadPassword(Password: AnsiString): AnsiString;
var
  i: Integer;
begin
  i := Length(Password);
  Result := Copy(Password, 1, i);
  SetLength(Result, 32);
  if i < 32 then
    Move(PDF_PK, Result[i + 1], 32 - i);
end;

procedure TfrxPDFExport.PrepareKeys;
var
  s, s1, p, p1, fid: AnsiString;
  i, j: Integer;
  rc4: TfrxRC4;
  md5: TfrxMD5;
begin
// OWNER KEY
  if FOwnerPassword = '' then
    FOwnerPassword := FUserPassword;
  p := PadPassword(FOwnerPassword);
  md5 := TfrxMD5.Create;
  try
    md5.Init;
    md5.Update(@p[1], 32);
    md5.Finalize;
    s := PMD52Str(md5.Digest);
    for i := 1 to 50 do
    begin
      md5.Init;
      md5.Update(@s[1], 16);
      md5.Finalize;
      s := PMD52Str(md5.Digest);
    end;
  finally
    md5.Free;
  end;

  rc4 := TfrxRC4.Create;
  try
    p := PadPassword(FUserPassword);
    SetLength(s1, 32);
    rc4.Start(@s[1], 16);
    rc4.Crypt(@p[1], @s1[1], 32);
    SetLength(p1, 16);
    for i := 1 to 19 do
    begin
      for j := 1 to 16 do
        p1[j] := AnsiChar(Byte(s[j]) xor i);
      rc4.Start(@p1[1], 16);
      rc4.Crypt(@s1[1], @s1[1], 32);
    end;
    FOPass := s1;
  finally
    rc4.Free;
  end;

// ENCRYPTION KEY
  p := PadPassword(FUserPassword);
  md5 := TfrxMD5.Create;
  try
    md5.Init;
    md5.Update(@p[1], 32);
    md5.Update(@FOPass[1], 32);
    md5.Update(@FEncBits, 4);
    fid := '';
    for i := 1 to 16 do
      fid := fid + AnsiChar(chr(Byte(StrToInt('$' + String(FFileID[i * 2 - 1] + FFileID[i * 2])))));
    md5.Update(@fid[1], 16);
    md5.Finalize;
    s := PMD52Str(md5.Digest);
    for i := 1 to 50 do
    begin
      md5.Init;
      md5.Update(@s[1], 16);
      md5.Finalize;
      s := PMD52Str(md5.Digest);
    end;
  finally
    md5.Free;
  end;
  FEncKey := s;

// USER KEY
  md5 := TfrxMD5.Create;
  try
    md5.Update(@PDF_PK, 32);
    md5.Update(@fid[1], 16);
    md5.Finalize;
    s := PMD52Str(md5.Digest);
    s1 := FEncKey;
    rc4 := TfrxRC4.Create;
    try
      rc4.Start(@s1[1], 16 );
      rc4.Crypt(@s[1], @s[1], 16 );
      SetLength(p1, 16);
      for i := 1 to 19 do
      begin
        for j := 1 to 16 do
           p1[j] := AnsiChar(Byte(s1[j]) xor i);
         rc4.Start(@p1[1], 16 );
         rc4.Crypt(@s[1], @s[1], 16 );
      end;
      FUPass := s;
    finally
      rc4.Free;
    end;
    SetLength(FUPass, 32);
    FillChar(FUPass[17], 16, 0);
  finally
    md5.Free;
  end;
end;

procedure TfrxPDFExport.SetProtectionFlags(const Value: TfrxPDFEncBits);
begin
  FProtectionFlags := Value;
  FEncBits := $FFFFFFC0;
  FEncBits := FEncBits + (Cardinal(ePrint in Value) shl 2 +
    Cardinal(eModify in Value) shl 3 +
    Cardinal(eCopy in Value) shl 4 +
    Cardinal(eAnnot in Value) shl 5);
end;

procedure TfrxPDFExport.Clear;
var
  i: Integer;
begin
  for i := 0 to FFonts.Count - 1 do
    TfrxPDFFont(FFonts[i]).Free;

  for i := 0 to FPages.Count - 1 do
    TObject(FPages[i]).Free;

  for i := 0 to FAnnots.Count - 1 do
    TObject(FAnnots[i]).Free;

  FPages.Clear;
  FFonts.Clear;
  FPageFonts.Clear;
  FXRef.Clear;
  FPageAnnots.Clear;
  FAnnots.Clear;
  FPagesRef.Clear;
end;

procedure TfrxPDFExport.WriteFont(pdfFont: TfrxPDFFont);
var
  fontFileId, descriptorId, toUnicodeId, cIDSystemInfoId, descendantFontId: Longint;
  fontName: String;
  i: Integer;
  memstream, fontstream, tounicode: TMemoryStream;
begin
  fontFileId := 0;
{$IFDEF Delphi12}
  fontName := String(pdfFont.GetFontName);
{$ELSE}
  fontName := pdfFont.GetFontName;
{$ENDIF}
  // embedded font
  if FEmbedded then
  begin
    fontFileId := UpdateXRef;
    WriteLn(pdf, ObjNumber(fontFileId));
// alman
    pdfFont.PackTTFFont;
    memstream := TMemoryStream.Create;
    fontstream := TMemoryStream.Create;
    fontstream.CopyFrom(pdfFont.FontData, pdfFont.FontData.Size);
    //fontstream.Write(pdfFont.FontData^, pdfFont.FontDataSize);
    fontstream.Position := 0;
    WritePDFStream(pdf, fontstream, fontFileId, FCompressed, FProtection, true, true, false);
  end;
  // descriptor
  descriptorId := UpdateXRef;
  WriteLn(pdf, ObjNumber(descriptorId));
  WriteLn(pdf, '<<');
  WriteLn(pdf, '/Type /FontDescriptor');
  WriteLn(pdf, '/FontName /' + fontName);
  //WriteLn(pdf, '/FontFamily /' + fontName);
  WriteLn(pdf, '/Flags 32');
  WriteLn(pdf, '/FontBBox [' + IntToStr(pdfFont.TextMetric.otmrcFontBox.left) + ' ' +
    IntToStr(pdfFont.TextMetric.otmrcFontBox.bottom) + ' ' +
    IntToStr(pdfFont.TextMetric.otmrcFontBox.right) + ' ' +
    IntToStr(pdfFont.TextMetric.otmrcFontBox.top) + ' ]');
  WriteLn(pdf, '/ItalicAngle ' + IntToStr(pdfFont.TextMetric.otmItalicAngle));
  WriteLn(pdf, '/Ascent ' + IntToStr(pdfFont.TextMetric.otmAscent));
  WriteLn(pdf, '/Descent ' + IntToStr(pdfFont.TextMetric.otmDescent));
  WriteLn(pdf, '/Leading ' + IntToStr(pdfFont.TextMetric.otmTextMetrics.tmInternalLeading));
  WriteLn(pdf, '/CapHeight ' + IntToStr(pdfFont.TextMetric.otmTextMetrics.tmHeight));
  WriteLn(pdf, '/StemV ' + IntToStr(50 + Round(sqr(pdfFont.TextMetric.otmTextMetrics.tmWeight / 65))));
  WriteLn(pdf, '/AvgWidth ' + IntToStr(pdfFont.TextMetric.otmTextMetrics.tmAveCharWidth));
  WriteLn(pdf, '/MxWidth ' + IntToStr(pdfFont.TextMetric.otmTextMetrics.tmMaxCharWidth));
  WriteLn(pdf, '/MissingWidth ' + IntToStr(pdfFont.TextMetric.otmTextMetrics.tmAveCharWidth));
  if FEmbedded then
      WriteLn(pdf, '/FontFile2 ' + ObjNumberRef(fontFileId));
  WriteLn(pdf, '>>');
  WriteLn(pdf, 'endobj');
  // ToUnicode
  toUnicodeId := UpdateXRef();
  WriteLn(pdf, ObjNumber(toUnicodeId));
  tounicode := TMemoryStream.Create;
    WriteLn(tounicode, '/CIDInit /ProcSet findresource begin');
    WriteLn(tounicode, '12 dict begin');
    WriteLn(tounicode, 'begincmap');
    WriteLn(tounicode, '/CIDSystemInfo');
    WriteLn(tounicode, '<< /Registry (Adobe)');
    WriteLn(tounicode, '/Ordering (UCS)');
    WriteLn(tounicode, '/Ordering (Identity)');
    WriteLn(tounicode, '/Supplement 0');
    WriteLn(tounicode, '>> def');
    Write(tounicode, '/CMapName /');
{$IFDEF Delphi12}
    Write(tounicode, StringReplace(pdfFont.GetFontName, AnsiString(','), AnsiString('+'), [rfReplaceAll]));
{$ELSE}
    Write(tounicode, StringReplace(pdfFont.GetFontName, ',', '+', [rfReplaceAll]));
{$ENDIF}
    WriteLn(tounicode, ' def');
    WriteLn(tounicode, '/CMapType 2 def');
    WriteLn(tounicode, '1 begincodespacerange');
    WriteLn(tounicode, '<0000> <FFFF>');
    WriteLn(tounicode, 'endcodespacerange');
    Write(tounicode, IntToStr(pdfFont.UsedAlphabet.Count));
    WriteLn(tounicode, ' beginbfchar');
    for i := 0 to pdfFont.UsedAlphabet.Count - 1 do
    begin
      Write(tounicode, '<');
      Write(tounicode, IntToHex(Word(pdfFont.UsedAlphabet[i]), 4));
      Write(tounicode, '> <');
      Write(tounicode, IntToHex(Word(pdfFont.UsedAlphabetUnicode[i]), 4));
      WriteLn(tounicode, '>');
    end;
    WriteLn(tounicode, 'endbfchar');
    WriteLn(tounicode, 'endcmap');
    WriteLn(tounicode, 'CMapName currentdict /CMap defineresource pop');
    WriteLn(tounicode, 'end');
    WriteLn(tounicode, 'end');
    tounicode.Position := 0;
    WritePDFStream(pdf, tounicode, toUnicodeId, FCompressed, FProtection, true, true, false);
  //CIDSystemInfo
  cIDSystemInfoId := UpdateXRef;
  WriteLn(pdf, ObjNumber(cIDSystemInfoId));
  WriteLn(pdf, '<<');
  WriteLn(pdf, '/Registry (Adobe) /Ordering (Identity) /Supplement 0');
  WriteLn(pdf, '>>');
  WriteLn(pdf, 'endobj');
  //DescendantFonts
  descendantFontId := UpdateXRef;
  WriteLn(pdf, ObjNumber(descendantFontId));
  WriteLn(pdf, '<<');
  WriteLn(pdf, '/Type /Font');
  WriteLn(pdf, '/Subtype /CIDFontType2');
  WriteLn(pdf, '/BaseFont /' + fontName);
  WriteLn(pdf, '/CIDToGIDMap /Identity');
  WriteLn(pdf, '/CIDSystemInfo ' + ObjNumberRef(cIDSystemInfoId));
  WriteLn(pdf, '/FontDescriptor ' + ObjNumberRef(descriptorId));

  Write(pdf, '/W [ ');
  for i := 0 to pdfFont.UsedAlphabet.Count - 1 do
    if pdfFont.Widths[i] <> Pointer(0) then
      Write(pdf, IntToStr(Word(pdfFont.UsedAlphabet[i])) + ' [' + IntToStr(Integer(pdfFont.Widths[i])) + '] ');
  WriteLn(pdf, ']');
  WriteLn(pdf, '>>');
  WriteLn(pdf, 'endobj');
  // main
  FXRef[pdfFont.Reference - 1] := PrepXrefPos(pdf.Position);
  WriteLn(pdf, ObjNumber(pdfFont.Reference));
  WriteLn(pdf, '<<');
  WriteLn(pdf, '/Type /Font');
  WriteLn(pdf, '/Subtype /Type0');
  WriteLn(pdf, '/BaseFont /' + fontName);
  WriteLn(pdf, '/Encoding /Identity-H');
  WriteLn(pdf, '/DescendantFonts [' + ObjNumberRef(descendantFontId) + ']');
  WriteLn(pdf, '/ToUnicode ' + ObjNumberRef(toUnicodeId));
  WriteLn(pdf, '>>');
  WriteLn(pdf, 'endobj');
end;

procedure TfrxPDFExport.AddObject(const Obj: TfrxView);
var
  FontIndex: Integer;
  x, y, dx, dy, fdx, fdy, PGap, FCharSpacing, ow, oh, kx, ky, dx1, dy1: Extended;
  PictObj: TfrxPictureView;
  i, iz: Integer;
  Jpg: TJPEGImage;
  s: AnsiString;
  Lines: TWideStrings;
  TempBitmap: TBitmap;
  TempMaskBitmap: TBitmap;
  TempMask8bitBitmap: TBitmap;
  TransparentColorMask: TColor;
  OldFrameWidth: Extended;
  TempColor: TColor;
  Left, Right, Top, Bottom, Width, Height: String;
  FUnderlinePosition: Double;
  FStrikeoutPosition: Double;
  FRealBounds: TfrxRect;
  FLineHeight: Extended;
  FLineWidth: Extended;
  FHeightWoMargin: Extended;
  pdfFont: TfrxPDFFont;
  textObj: TfrxCustomMemoView;
  bx, by, bx1, by1, wx1, wx2, wy1, wy2, gx1, gy1: Integer;
  FTextRect: TRect;
  angle, a_sin, a_cos, a_x, a_y: Extended;
  rx, ry: Extended;
  simulateBold, simulateItalic: Boolean;
{$IFDEF OLD_STYLE}
  su: WideString;
  BWidth, BHeight}: String;
{$ELSE}
  Iy, ix: Integer;
  dots:  PRGBAWord;
  MaskBytes:  array of byte;
  MaskSize:   Integer;
  XMaskHash:  TfrxPDFXObjectHash;
  MaskIndex:  Integer;
  XMaskId:    Integer;
{$ENDIF}
// PDF/A backport
  XObjectId: Integer;
  XObjectHash: TfrxPDFXObjectHash;
  XObjectStream: TStream;
  XMaskStream:  TStream;
  PicIndex: Integer;
  IsTransparent: Boolean;
  IsMasked: Boolean;
  RemappedStr: WideString;
  HWidth: Extended;
  SpaceAdjustment: Extended;

  function GetLeft(const Left: Extended): Extended;
  begin
    Result := FMarginLeft + Left * PDF_DIVIDER
  end;

  function GetTop(const Top: Extended): Extended;
  begin
    Result := FHeightWoMargin - Top * PDF_DIVIDER
  end;

  function GetVTextPos(const Top: Extended; const Height: Extended;
    const Align: TfrxVAlign; const Line: Integer = 0;
    const Count: Integer = 1): Extended;
  var
    i: Integer;
  begin
    if Line <= Count then
      i := Line
    else
      i := 0;
    if Align = vaBottom then
      Result := Top + Height - FLineHeight * (Count - i - 1)
    else if Align = vaCenter then
      Result := Top + (Height - (FLineHeight * Count)) / 2 + FLineHeight * (i + 1)
    else
      Result := Top + FLineHeight * (i + 1);
  end;

  function GetVTextPosR(const Height: Extended;
    const Align: TfrxVAlign; const Line: Integer = 0;
    const Count: Integer = 1): Extended;
  var
    i: Integer;
  begin
    if Line <= Count then
      i := Line
    else
      i := 0;
    if Align = vaBottom then
      Result := Height - FLineHeight * (Count - i - 1)
    else if Align = vaCenter then
      Result := -FLineHeight * Count / 2 + FLineHeight * (i + 1)
    else
      Result := - Height + FLineHeight * (i + 1);
  end;

  function GetHTextPos(const Left: Extended; const Width: Extended; const Text: WideString;
    const Align: TfrxHAlign; const rtl: Boolean): Extended;
  begin
    case Align of
      haLeft:   Result := Left;
      haRight:  Result := Left + Width - FLineWidth;
      haCenter: Result := Left + (Width - FLineWidth) / 2;
      haBlock:  if not rtl or (rtl and ((Width - FLineWidth)/Width < 0.05)) then
                  Result := Left
                else
                  Result := Left + Width - FLineWidth;
      else      Result := Left;
    end;
  end;

  function GetHTextPosR(const Width: Extended; const Text: WideString;
    const Align: TfrxHAlign): Extended;
  begin
    case Align of
      haRight:  Result := Width - FLineWidth;
      haCenter: Result := -FLineWidth / 2;
      else      Result := -Width;
    end;
  end;

  function CorrectFrameWidth(w: extended): extended;
  begin
    if w <= 1 then result := 0 else result := w;
  end;

  procedure DrawFrameLine(Color: TColor; FrameStyle: TfrxFrameStyle; FrameWidth: extended;
                          LeftBegin, TopBegin, LeftEnd, TopEnd: string);
  begin
    Write(OutStream, GetPDFColor(Color) + ' RG'#13#10);
    WriteLn(OutStream, GetPDFDash(FrameStyle, FrameWidth));
    Write(OutStream, frFloat2Str(FrameWidth * PDF_DIVIDER) + ' w'#13#10);
    Write(OutStream, LeftBegin + ' ' + TopBegin + ' m'#13#10 + LeftEnd + ' ' + TopEnd + ' l'#13#10'S'#13#10);
  end;

    procedure MakeUpFrames;
  var
     fRight, fBottom, dLeft, dRight,
     iLeft, iTop, ifRight, ifBottom, idLeft, idRight,
     oLeft, oTop, ofRight, ofBottom, odLeft, odRight: String;
     HaveDoubleFrame: Boolean;
  begin
    if (Obj.Frame.Typ <> []) and (Obj.Frame.Color <> clNone) then
    begin
      HaveDoubleFrame := ((Obj.Frame.LeftLine.Style = fsDouble) and (ftLeft in Obj.Frame.Typ)) or
                         ((Obj.Frame.RightLine.Style = fsDouble) and (ftRight in Obj.Frame.Typ)) or
                         ((Obj.Frame.TopLine.Style = fsDouble) and (ftTop in Obj.Frame.Typ)) or
                         ((Obj.Frame.BottomLine.Style = fsDouble) and (ftBottom in Obj.Frame.Typ));

      if HaveDoubleFrame then
        begin
          oLeft := frFloat2Str(GetLeft(Obj.AbsLeft - CorrectFrameWidth(Obj.Frame.LeftLine.Width) / 2));
          oTop := frFloat2Str(GetTop(Obj.AbsTop - CorrectFrameWidth(Obj.Frame.TopLine.Width) / 2));
          odLeft := frFloat2Str(GetLeft(Obj.AbsLeft - CorrectFrameWidth(Obj.Frame.LeftLine.Width)));

          iLeft := frFloat2Str(GetLeft(Obj.AbsLeft + CorrectFrameWidth(Obj.Frame.LeftLine.Width) / 2 + 2));
          iTop := frFloat2Str(GetTop(Obj.AbsTop + CorrectFrameWidth(Obj.Frame.TopLine.Width) / 2 + 2));
          idLeft := frFloat2Str(GetLeft(Obj.AbsLeft + 2));
        end;
      dLeft := frFloat2Str(GetLeft(Obj.AbsLeft - CorrectFrameWidth(Obj.Frame.LeftLine.Width) / 2));

      if Obj.Frame.DropShadow then
      begin
        if HaveDoubleFrame then
          begin
            odRight := frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Width - Obj.Frame.ShadowWidth));
            ofRight := frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Width - CorrectFrameWidth(Obj.Frame.RightLine.Width) / 2 - Obj.Frame.ShadowWidth));
            ofBottom := frFloat2Str(GetTop(Obj.AbsTop + Obj.Height - CorrectFrameWidth(Obj.Frame.BottomLine.Width) / 2 - Obj.Frame.ShadowWidth));

            idRight := frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Width - CorrectFrameWidth(Obj.Frame.RightLine.Width) - Obj.Frame.ShadowWidth - 2));
            ifRight := frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Width - CorrectFrameWidth(Obj.Frame.RightLine.Width) * 1.5 - Obj.Frame.ShadowWidth - 2));
            ifBottom := frFloat2Str(GetTop(Obj.AbsTop + Obj.Height - CorrectFrameWidth(Obj.Frame.BottomLine.Width) * 1.5 - Obj.Frame.ShadowWidth - 2));
          end;
        dRight := frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Width + CorrectFrameWidth(Obj.Frame.RightLine.Width) / 2 - Obj.Frame.ShadowWidth));
        fRight := frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Width - Obj.Frame.ShadowWidth));
        fBottom := frFloat2Str(GetTop(Obj.AbsTop + Obj.Height - Obj.Frame.ShadowWidth));
      end
      else
      begin
        if HaveDoubleFrame then
          begin
            odRight := frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Width + CorrectFrameWidth(Obj.Frame.RightLine.Width)));
            ofRight := frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Width + CorrectFrameWidth(Obj.Frame.RightLine.Width) / 2));
            ofBottom := frFloat2Str(GetTop(Obj.AbsTop + Obj.Height + CorrectFrameWidth(Obj.Frame.BottomLine.Width) / 2 ));

            idRight := frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Width - 2));
            ifRight := frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Width - CorrectFrameWidth(Obj.Frame.RightLine.Width) / 2 - 2));
            ifBottom := frFloat2Str(GetTop(Obj.AbsTop + Obj.Height - CorrectFrameWidth(Obj.Frame.BottomLine.Width) / 2 - 2));
          end;
        dRight := frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Width + CorrectFrameWidth(Obj.Frame.RightLine.Width) / 2));
        fRight := Right;
        fBottom := Bottom;
      end;

      if ftLeft in Obj.Frame.Typ then
      begin
        if (Obj.Frame.LeftLine.Style <> fsDouble ) then
          DrawFrameLine(Obj.Frame.LeftLine.Color, Obj.Frame.LeftLine.Style,
                        Obj.Frame.LeftLine.Width, Left, Top, Left, fBottom)
        else
          begin
            DrawFrameLine(Obj.Frame.LeftLine.Color, Obj.Frame.LeftLine.Style,
                          Obj.Frame.LeftLine.Width, oLeft, oTop, oLeft, ofBottom);
            DrawFrameLine(Obj.Frame.LeftLine.Color, Obj.Frame.LeftLine.Style,
                          Obj.Frame.LeftLine.Width, iLeft, iTop, iLeft, ifBottom);
          end;
      end;
      if ftRight in Obj.Frame.Typ then
      begin
        if (Obj.Frame.RightLine.Style <> fsDouble ) then
          DrawFrameLine(Obj.Frame.RightLine.Color, Obj.Frame.RightLine.Style,
                        Obj.Frame.RightLine.Width, fRight, Top, fRight, fBottom)
        else
          begin
            DrawFrameLine(Obj.Frame.RightLine.Color, Obj.Frame.RightLine.Style,
                          Obj.Frame.RightLine.Width, ofRight, oTop, ofRight, ofBottom);
            DrawFrameLine(Obj.Frame.RightLine.Color, Obj.Frame.RightLine.Style,
                          Obj.Frame.RightLine.Width, ifRight, iTop, ifRight, ifBottom);
          end;
      end;
      if ftTop in Obj.Frame.Typ then
      begin
        if (Obj.Frame.TopLine.Style <> fsDouble) then
          DrawFrameLine(Obj.Frame.TopLine.Color, Obj.Frame.TopLine.Style,
                        Obj.Frame.TopLine.Width, dLeft, Top, dRight, Top)
        else
          begin
            DrawFrameLine(Obj.Frame.TopLine.Color, Obj.Frame.TopLine.Style,
                          Obj.Frame.TopLine.Width, odLeft, oTop, odRight, oTop);
            DrawFrameLine(Obj.Frame.TopLine.Color, Obj.Frame.TopLine.Style,
                          Obj.Frame.TopLine.Width, idLeft, iTop, idRight, iTop);
          end;
      end;
      if ftBottom in Obj.Frame.Typ then
      begin
        if (Obj.Frame.BottomLine.Style <> fsDouble) then
          DrawFrameLine(Obj.Frame.BottomLine.Color, Obj.Frame.BottomLine.Style,
                        Obj.Frame.BottomLine.Width, dLeft, fBottom, dRight, fBottom)
        else
          begin
            DrawFrameLine(Obj.Frame.BottomLine.Color, Obj.Frame.BottomLine.Style,
                      Obj.Frame.BottomLine.Width, odLeft, ofBottom, odRight, ofBottom);
            DrawFrameLine(Obj.Frame.BottomLine.Color, Obj.Frame.BottomLine.Style,
                      Obj.Frame.BottomLine.Width, idLeft, ifBottom, idRight, ifBottom);
          end;
      end;
    end;
  end;

  function HTMLTags(const View: TfrxCustomMemoView): Boolean;
  begin
    if View.AllowHTMLTags then
      Result := FTags and (Pos('<' ,View.Memo.Text) > 0)
    else
      Result := False;
  end;

  function CheckOutPDFChars(const Str: WideString): WideString;
  var
    i: Integer;
  begin
    Result := '';
    for i := 1 to Length(Str) do
      if Str[i] = '\' then
        Result := Result + '\\'
      else if Str[i] = '(' then
        Result := Result + '\('
      else if Str[i] = ')' then
        Result := Result + '\)'
      else
        Result := Result + Str[i];
  end;

  procedure DrawArrow(Obj: TfrxCustomLineView; x1, y1, x2, y2: Extended);
  var
    k1, a, b, c, D: Double;
    xp, yp, x3, y3, x4, y4, ld, wd: Extended;
  begin
    wd := Obj.ArrowWidth * PDF_DIVIDER;
    ld := Obj.ArrowLength * PDF_DIVIDER;
    if abs(x2 - x1) > 0 then
    begin
      k1 := (y2 - y1) / (x2 - x1);
      a := Sqr(k1) + 1;
      b := 2 * (k1 * ((x2 * y1 - x1 * y2) / (x2 - x1) - y2) - x2);
      c := Sqr(x2) + Sqr(y2) - Sqr(ld) + Sqr((x2 * y1 - x1 * y2) / (x2 - x1)) -
        2 * y2 * (x2 * y1 - x1 * y2) / (x2 - x1);
      D := Sqr(b) - 4 * a * c;
      xp := (-b + Sqrt(D)) / (2 * a);
      if (xp > x1) and (xp > x2) or (xp < x1) and (xp < x2) then
        xp := (-b - Sqrt(D)) / (2 * a);
      yp := xp * k1 + (x2 * y1 - x1 * y2) / (x2 - x1);
      if y2 <> y1 then
      begin
        x3 := xp + wd * sin(ArcTan(k1));
        y3 := yp - wd * cos(ArcTan(k1));
        x4 := xp - wd * sin(ArcTan(k1));
        y4 := yp + wd * cos(ArcTan(k1));
      end
      else
      begin
        x3 := xp; y3 := yp - wd;
        x4 := xp; y4 := yp + wd;
      end;
    end
    else
    begin
      xp := x2;
      yp := y2 - ld;
      if (yp > y1) and (yp > y2) or (yp < y1) and (yp < y2) then
        yp := y2 + ld;
      x3 := xp - wd; y3 := yp;
      x4 := xp + wd; y4 := yp;
    end;
    WriteLn(OutStream, GetPDFDash(Obj.Frame.Style, Obj.Frame.Width));
    WriteLn(OutStream, frFloat2Str(x3) + ' ' + frFloat2Str(y3) + ' m'#13#10 +
      frFloat2Str(x2) + ' ' + frFloat2Str(y2) + ' l'#13#10 +
      frFloat2Str(x4) + ' ' + frFloat2Str(y4) + ' l');
    if Obj.ArrowSolid then
      WriteLn(OutStream, '1 j'#13#10 + GetPDFColor(Obj.Frame.Color) + ' rg'#13#10'b')
    else
      WriteLn(OutStream, 'S');
  end;

  function FontNeedsBoldItalicSimulation(Font: TFont): Boolean;
  begin
    if frxPDFFontsNeedStyleSimulation.IndexOf(Font.Name) <> -1 then
      Result := True
    else
      Result := False;
  end;

  function GetGlobalFont(const Font: TFont): TfrxPDFFont;
  var
    i: Integer;
    Font2: TFont;
    needBISimulation: Boolean;
  begin
    needBISimulation := FontNeedsBoldItalicSimulation(Font);
    i := 0;
    while i < FFonts.Count do
    begin
      Font2 := TfrxPDFFont(FFonts[i]).SourceFont;
      if (Font.Name = Font2.Name) and ((Font.Style = Font2.Style) or needBISimulation) then
        break;
      Inc(i)
    end;
    if i < FFonts.Count then
      result := TfrxPDFFont(FFonts[i])
    else
    begin
      result := TfrxPDFFont.Create(Font);
      result.FillOutlineTextMetrix();
      FFonts.Add(result);
{$IFDEF Delphi12}
      result.Name := AnsiString('/F' + IntToStr(FFonts.Count - 1));
{$ELSE}
      result.Name := '/F' + IntToStr(FFonts.Count - 1);
{$ENDIF}
    end;
  end;

  function GetObjFontNumber(const Font: TFont): integer;
  var
    i: Integer;
    Font2: TFont;
    needBISimulation: Boolean;
  begin
    needBISimulation := FontNeedsBoldItalicSimulation(Font);
    i := 0;
    while i < FPageFonts.Count do
    begin
      Font2 := TfrxPDFFont(FPageFonts[i]).SourceFont;
      if (Font.Name = Font2.Name) and ((Font.Style = Font2.Style) or needBISimulation) then
        break;
      Inc(i);
    end;
    if i < FPageFonts.Count then
      result := i
    else
    begin
      FPageFonts.Add(GetGlobalFont(Font));
      result := FPageFonts.Count - 1;
    end;
  end;

  procedure Cmd(const Args: string; const Name: string = '');
  begin
    if Name = '' then
      WriteLn(OutStream, Args)
    else if Args = '' then
      WriteLn(OutStream, Name)
    else
      WriteLn(OutStream, Args + ' ' + Name);
  end;

  function CmdCoords(x, y: Extended): string;
  begin
    Result := frFloat2Str(GetLeft(x)) + ' ' + frFloat2Str(GetTop(y));
  end;

  procedure CmdMove(x, y: Extended);
  begin
    Cmd(CmdCoords(x, y), 'm');
  end;

  procedure CmdLine(x, y: Extended);
  begin
    Cmd(CmdCoords(x, y), 'l');
  end;

  procedure CmdBezier(x1, y1, x2, y2, x3, y3: Extended);
  begin
    Cmd(CmdCoords(x1, y1) + ' ' + CmdCoords(x2, y2) + ' ' +
      CmdCoords(x3, y3), 'c');
  end;

  { Rounded rectangle can be drawed
    using the following PDF commands:

      - m - start a new path
      - v - add a bezier curve
      - l - add a straight line
      - S - stroke the path
      - B - fill and stroke the path }

  procedure WriteRoundedRect(RoundedRect: TfrxShapeView);
  var
    rad, rf, l, t, r, b, w, h: Extended;
  begin
    with RoundedRect do
    begin
      with Frame do
      begin
        Cmd(GetPDFDash(Style, Width));
        Cmd(GetPDFColor(Color), 'RG');
        Cmd(frFloat2Str(Width * PDF_DIVIDER), 'w');
      end;

      if Curve = 0 then
        rad := 2 * 3.74
      else
        rad := Curve * 3.74;

      rf := 0.5 * rad;
      l := AbsLeft;
      t := AbsTop;
      w := Width;
      h := Height;
      r := l + w;
      b := t + h;

      Cmd(GetPDFColor(Color), 'rg');
      CmdMove(l + rad, b);
      CmdLine(r - rad, b);
      CmdBezier(r - rf, b, r, b - rf, r, b - rad);  // right-bottom
      CmdLine(r, t + rad);
      CmdBezier(r, t + rf, r - rf, t, r - rad, t);  // right-top
      CmdLine(l + rad, t);
      CmdBezier(l + rf, t, l, t + rf, l, t + rad);  // left-top
      CmdLine(l, b - rad);
      CmdBezier(l, b - rf, l + rf, b, l + rad, b);  // left-bottom

      if Color = clNone then
        Cmd('', 'S')
      else
        Cmd('', 'B');
    end;
  end;

  { An extenral link is a URL like http://company.com/index.html }

  procedure WriteExternalLink(const URI: string);
  var
    ObjId: Integer;
    annot: TfrxPDFAnnot;
  begin
    ObjId := UpdateXRef;
    Writeln(FPageAnnots, ObjNumberRef(ObjId)); // for /Annots array in the page object

    annot := TfrxPDFAnnot.Create;
    annot.Number := ObjId;
    annot.Rect := Left + ' ' + Bottom + ' ' + Right + ' ' + Top;
    annot.Hyperlink := StringReplace(String(PdfString(WideString(URI))), '\', '\\', [rfReplaceAll]);
    FAnnots.Add(annot);
  end;

  { Writes an anchor to the PDF document. This kind
    of links make a jump to a specified location within
    the current document.

    Arguments:

      - Page  - an index of a page whither the anchor jumps
      - Pos   - a vertical position of the destination within the page }

  procedure WritePageAnchor(Page: Integer; Pos: Double);
  var
    ObjId: Integer;
    annot: TfrxPDFAnnot;
  begin
    ObjId := UpdateXRef;
    Writeln(FPageAnnots, ObjNumberRef(ObjId)); // for /Annots array in the page object

    annot := TfrxPDFAnnot.Create;
    annot.Number := ObjId;
    annot.Rect := Left + ' ' + Bottom + ' ' + Right + ' ' + Top;
    annot.DestPage := Page;
    annot.DestY := Round(GetTop(Pos));
    FAnnots.Add(annot);
  end;

  { Writes a link object to the PDF document }
  procedure WriteHyperLink(Hyperlink: TfrxHyperlink);
  var
    x: TfrxXMLItem;
  begin
    case Hyperlink.kind of
      hkAnchor :
        begin
          x := (Report.PreviewPages as TfrxPreviewPages).FindAnchor(Hyperlink.Value);
          if x <> nil then
            WritePageAnchor(StrToInt(x.Prop['page']), StrToFloat(x.Prop['top']));
        end;

      hkPageNumber:
        if StrToInt(Hyperlink.Value) <= Report.PreviewPages.Count then
          WritePageAnchor(StrToInt(Hyperlink.Value) - 1, 0.0)
        else
          WritePageAnchor(Report.PreviewPages.Count - 1, 0.0);

      hkURL: // Â äîêóìåíòíàöèè ïîêà íå îïèñàíî-íîÿ äóìàÿ-ýòî äëÿ ýòèõ ñëó÷àåâ...
        if length(Hyperlink.Value)>0 then
        WriteExternalLink(Hyperlink.Value)
    end;{case}
  end;

  procedure WriteLink(a: string);
  var
    x: TfrxXMLItem;
  begin
    if a = '' then Exit;

    { Anchors.

      This kind of links make a jump to a specified
      location within the current document. Anchors
      begin with '#' sign. }

    if a[1] = '#' then
    begin
      a := Copy(a, 2, Length(a) - 1);
      x := (Report.PreviewPages as TfrxPreviewPages).FindAnchor(a);

      if x <> nil then
        WritePageAnchor(StrToInt(x.Prop['page']), StrToFloat(x.Prop['top']));
    end

    { Page anchors.

      This kind of links make a jump to a
      specified page. }

    else if a[1] = '@' then
    begin
      a := Copy(a, 2, Length(a) - 1);
      WritePageAnchor(StrToInt(a) - 1, 0.0);
    end

    { Extenal links.

      An extenral link is a URL like http://company.com/index.html. }

    else
      WriteExternalLink(a)
  end;

  { Export checkbox }

  procedure ExportChebox(Obj: TfrxView);
  var
    cb: TfrxCheckBoxView;
    L:  Extended;
    T:  Extended;
    W:  Extended;
    H:  Extended;
    CS: Extended; //CheckSize
  begin
    cb := TfrxCheckBoxView(Obj);
    L := Obj.AbsLeft;
    T := Obj.AbsTop;
    H := Obj.Height;
    W := Obj.Width;
    if H > W then CS := W/2 else CS := H/2;

    WriteLn(OutStream, GetPDFDash( fsSolid, Obj.Frame.Width * 2));
    WriteLn(OutStream, GetPDFColor(TfrxCheckBoxView(Obj).CheckColor) + ' RG'#13#10 +
      frFloat2Str(Obj.Frame.Width * PDF_DIVIDER * 2) + ' w ' +
      GetPDFColor(Obj.Color) + ' rg');

    if cb.Checked then
      case cb.CheckStyle of
        csCross:
          WriteLn(OutStream,
            frFloat2Str(Obj.Frame.Width * PDF_DIVIDER * 6) + ' w 2 J ' +
            frFloat2Str(GetLeft(L+(W-CS)/2))   + ' ' + frFloat2Str(GetTop(T+(H-CS)/2))   + ' m ' +
            frFloat2Str(GetLeft(L+W-(W-CS)/2)) + ' ' + frFloat2Str(GetTop(T+H-(H-CS)/2)) + ' l ' +
            frFloat2Str(GetLeft(L+W-(W-CS)/2)) + ' ' + frFloat2Str(GetTop(T+(H-CS)/2))   + ' m ' +
            frFloat2Str(GetLeft(L+(W-CS)/2))   + ' ' + frFloat2Str(GetTop(T+H-(H-CS)/2)) + ' l ' );
        csCheck:
           WriteLn(OutStream,
            frFloat2Str(Obj.Frame.Width * PDF_DIVIDER * H / 10) + ' w 2 J ' +
            frFloat2Str(GetLeft(L + (W - CS) / 2)) + ' ' + frFloat2Str(GetTop(T + obj.Height / 2 )) + ' m ' +
            frFloat2Str(GetLeft(L + (W - CS) / 2 + CS / 3)) + ' ' + frFloat2Str(GetTop(T + H - (H - CS) / 2)) + ' l ' +
            frFloat2Str(GetLeft(L + (W - CS) / 2 + CS)) + ' ' + frFloat2Str(GetTop(T + (H - CS) / 2 - CS / 4 )) + ' l ' ) ;
        csLineCross:
          WriteLn(OutStream,
            frFloat2Str(GetLeft(L)) + ' ' + frFloat2Str(GetTop(T)) + ' m ' +
            frFloat2Str(GetLeft(L + W)) + ' ' + frFloat2Str(GetTop(T + H)) + ' l ' +
            frFloat2Str(GetLeft(L + W)) + ' ' + frFloat2Str(GetTop(T)) + ' m ' +
            frFloat2Str(GetLeft(L)) + ' ' + frFloat2Str(GetTop(T + H)) + ' l ' ) ;
        csPlus:
          WriteLn(OutStream,
            frFloat2Str(GetLeft(L + 4))            + ' ' + frFloat2Str(GetTop(T + obj.Height / 2 )) + ' m ' +
            frFloat2Str(GetLeft(L + W - 4)) + ' ' + frFloat2Str(GetTop(T + obj.Height / 2 )) + ' l ' +
            frFloat2Str(GetLeft(L + W / 2)) + ' ' + frFloat2Str(GetTop(T + 4)) + ' m ' +
            frFloat2Str(GetLeft(L + W / 2)) + ' ' + frFloat2Str(GetTop(T + obj.Height - 4)) + ' l ');
      end
    else
      case cb.UncheckStyle of
       usEmpty: ;
       usCross:
          WriteLn(OutStream,
            frFloat2Str(Obj.Frame.Width * PDF_DIVIDER * 6) + ' w 2 J ' +
            frFloat2Str(GetLeft(L+(W-CS)/2))   + ' ' + frFloat2Str(GetTop(T+(H-CS)/2))   + ' m ' +
            frFloat2Str(GetLeft(L+W-(W-CS)/2)) + ' ' + frFloat2Str(GetTop(T+H-(H-CS)/2)) + ' l ' +
            frFloat2Str(GetLeft(L+W-(W-CS)/2)) + ' ' + frFloat2Str(GetTop(T+(H-CS)/2))   + ' m ' +
            frFloat2Str(GetLeft(L+(W-CS)/2))   + ' ' + frFloat2Str(GetTop(T+H-(H-CS)/2)) + ' l ' );
       usLineCross:
          WriteLn(OutStream,
            frFloat2Str(GetLeft(L)) + ' ' + frFloat2Str(GetTop(T)) + ' m ' +
            frFloat2Str(GetLeft(L + W)) + ' ' + frFloat2Str(GetTop(T + H)) + ' l ' +
            frFloat2Str(GetLeft(L + W)) + ' ' + frFloat2Str(GetTop(T)) + ' m ' +
            frFloat2Str(GetLeft(L)) + ' ' + frFloat2Str(GetTop(T + H)) + ' l ');
       usMinus:
          WriteLn(OutStream,
            frFloat2Str(GetLeft(L + 4))    + ' ' + frFloat2Str(GetTop(T + obj.Height / 2 )) + ' m ' +
            frFloat2Str(GetLeft(L + W - 4)) + ' ' + frFloat2Str(GetTop(T + obj.Height / 2 )) + ' l ');
     end;
    if Obj.Color <> clNone then
      Write(OutStream, 'B'#13#10)
    else
      Write(OutStream, 'S'#13#10);

      if ftTop in Obj.Frame.Typ then
          begin
            Write(OutStream, GetPDFColor(Obj.Frame.TopLine.Color) + ' RG'#13#10);
            WriteLn(OutStream, GetPDFDash(Obj.Frame.TopLine.Style, Obj.Frame.TopLine.Width));
            Write(OutStream, frFloat2Str(Obj.Frame.TopLine.Width * PDF_DIVIDER) + ' w'#13#10);
            Write(OutStream, frFloat2Str(GetLeft(L)) + ' ' + frFloat2Str(GetTop(T)) + ' m'#13#10
             + frFloat2Str(GetLeft(L + W)) + ' ' + frFloat2Str(GetTop(T)) + ' l'#13#10'S'#13#10);
            if (Obj.Frame.TopLine.Style = fsDouble ) then begin
              Write   (OutStream, GetPDFColor(Obj.Frame.TopLine.Color) + ' RG'#13#10);
              WriteLn (OutStream, GetPDFDash(Obj.Frame.TopLine.Style, Obj.Frame.TopLine.Width));
              Write   (OutStream, frFloat2Str(Obj.Frame.TopLine.Width * PDF_DIVIDER) + ' w'#13#10);
              Write(OutStream, frFloat2Str(GetLeft(L - Obj.Frame.TopLine.Width - 2)) + ' ' + frFloat2Str(GetTop(T - Obj.Frame.TopLine.Width - 2)) + ' m'#13#10
              + frFloat2Str(GetLeft(L + W + Obj.Frame.TopLine.Width + 2)) + ' ' + frFloat2Str(GetTop(T - Obj.Frame.TopLine.Width - 2)) + ' l'#13#10'S'#13#10);
            end;
          end;
        if ftRight in Obj.Frame.Typ then
          begin
            Write(OutStream, GetPDFColor(Obj.Frame.RightLine.Color) + ' RG'#13#10);
            WriteLn(OutStream, GetPDFDash(Obj.Frame.RightLine.Style, Obj.Frame.RightLine.Width));
            Write(OutStream, frFloat2Str(Obj.Frame.RightLine.Width * PDF_DIVIDER) + ' w'#13#10);
            Write(OutStream, frFloat2Str(GetLeft(L + W)) + ' ' + frFloat2Str(GetTop(T)) + ' m'#13#10
             + frFloat2Str(GetLeft(L + W)) + ' ' + frFloat2Str(GetTop(T + H)) + ' l'#13#10'S'#13#10);
            if (Obj.Frame.RightLine.Style = fsDouble ) then begin
              Write   (OutStream, GetPDFColor(Obj.Frame.RightLine.Color) + ' RG'#13#10);
              WriteLn (OutStream, GetPDFDash(Obj.Frame.RightLine.Style, Obj.Frame.RightLine.Width));
              Write   (OutStream, frFloat2Str(Obj.Frame.RightLine.Width * PDF_DIVIDER) + ' w'#13#10);
              Write(OutStream, frFloat2Str(GetLeft(L + W + Obj.Frame.RightLine.Width + 2)) + ' ' + frFloat2Str(GetTop(T - Obj.Frame.RightLine.Width - 2)) + ' m'#13#10
              + frFloat2Str(GetLeft(L + W + Obj.Frame.RightLine.Width + 2)) + ' ' + frFloat2Str(GetTop(T + H + Obj.Frame.RightLine.Width + 2)) + ' l'#13#10'S'#13#10);
            end;
          end;
        if ftBottom in Obj.Frame.Typ then
          begin
            Write(OutStream, GetPDFColor(Obj.Frame.BottomLine.Color) + ' RG'#13#10);
            WriteLn(OutStream, GetPDFDash(Obj.Frame.BottomLine.Style, Obj.Frame.BottomLine.Width));
            Write(OutStream, frFloat2Str(Obj.Frame.BottomLine.Width * PDF_DIVIDER) + ' w'#13#10);
            Write(OutStream, frFloat2Str(GetLeft(L)) + ' ' + frFloat2Str(GetTop(T + H)) + ' m'#13#10
             + frFloat2Str(GetLeft(L + W)) + ' ' + frFloat2Str(GetTop(T + H)) + ' l'#13#10'S'#13#10);
            if (Obj.Frame.BottomLine.Style = fsDouble ) then begin
              Write   (OutStream, GetPDFColor(Obj.Frame.BottomLine.Color) + ' RG'#13#10);
              WriteLn (OutStream, GetPDFDash(Obj.Frame.BottomLine.Style, Obj.Frame.BottomLine.Width));
              Write   (OutStream, frFloat2Str(Obj.Frame.BottomLine.Width * PDF_DIVIDER) + ' w'#13#10);
              Write(OutStream, frFloat2Str(GetLeft(L - Obj.Frame.BottomLine.Width - 2)) + ' ' + frFloat2Str(GetTop(T + H + Obj.Frame.BottomLine.Width + 2)) + ' m'#13#10
              + frFloat2Str(GetLeft(L + W + Obj.Frame.BottomLine.Width + 2)) + ' ' + frFloat2Str(GetTop(T + H + Obj.Frame.BottomLine.Width + 2)) + ' l'#13#10'S'#13#10);
            end;
          end;
        if ftLeft in Obj.Frame.Typ then
          begin
            Write(OutStream, GetPDFColor(Obj.Frame.LeftLine.Color) + ' RG'#13#10);
            WriteLn(OutStream, GetPDFDash(Obj.Frame.LeftLine.Style, Obj.Frame.LeftLine.Width));
            Write(OutStream, frFloat2Str(Obj.Frame.LeftLine.Width * PDF_DIVIDER) + ' w'#13#10);
            Write(OutStream, frFloat2Str(GetLeft(L)) + ' ' + frFloat2Str(GetTop(T)) + ' m'#13#10
             + frFloat2Str(GetLeft(L)) + ' ' + frFloat2Str(GetTop(T + H)) + ' l'#13#10'S'#13#10);
            if (Obj.Frame.LeftLine.Style = fsDouble ) then begin
              Write   (OutStream, GetPDFColor(Obj.Frame.LeftLine.Color) + ' RG'#13#10);
              WriteLn (OutStream, GetPDFDash(Obj.Frame.LeftLine.Style, Obj.Frame.LeftLine.Width));
              Write   (OutStream, frFloat2Str(Obj.Frame.LeftLine.Width * PDF_DIVIDER) + ' w'#13#10);
              Write(OutStream, frFloat2Str(GetLeft(L - Obj.Frame.LeftLine.Width - 2)) + ' ' + frFloat2Str(GetTop(T - Obj.Frame.LeftLine.Width - 2)) + ' m'#13#10
              + frFloat2Str(GetLeft(L - Obj.Frame.LeftLine.Width - 2)) + ' ' + frFloat2Str(GetTop(T + H + Obj.Frame.LeftLine.Width + 2)) + ' l'#13#10'S'#13#10);
            end;
          end;

    if Obj.Color <> clNone then
      Write(OutStream, 'B'#13#10)
    else
      Write(OutStream, 'S'#13#10);

  end;

  function NeedSpaceAdjustment: Boolean;
    function IsEndOfParagraph: Boolean;
    begin
      if textObj.Lines.Count = Lines.Count then
        Result := True //i = Lines.Count - 1
      else
        Result := Integer(Lines.Objects[i]) and 2 <> 0;
    end;
  begin
    Result := (textObj.HAlign = haBlock) and not IsEndOfParagraph and
      (pdfFont.LastRemappedStrSpacesCount > 0);
    if not Result then
      Exit;
    FLineWidth := HWidth;
    SpaceAdjustment := pdfFont.LastRemappedStrWidth - (HWidth - textObj.GapX * 2 - textObj.CharSpacing * (Length(Lines[i]) - 1)) * PDF_DIVIDER * 1000 / textObj.Font.Size;
    SpaceAdjustment := SpaceAdjustment / pdfFont.LastRemappedStrSpacesCount;
  end;

begin
  FHeightWoMargin := FHeight - FMarginTop;

  Left := frFloat2Str(GetLeft(Obj.AbsLeft));
  Top := frFloat2Str(GetTop(Obj.AbsTop));
  Right := frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Width));
  Bottom := frFloat2Str(GetTop(Obj.AbsTop + Obj.Height));
  Width := frFloat2Str(Obj.Width * PDF_DIVIDER);
  Height := frFloat2Str(Obj.Height * PDF_DIVIDER);
  OldFrameWidth := 0;

  if Obj.Hyperlink.Value <> '' then
    WriteHyperLink( Obj.Hyperlink )
  else if Obj.URL <> '' then
    WriteLink(Obj.URL);

  { Memo object will be written to a pdf file as text if
    the following conditions are satisfied. All other
    memo objects will be saved as pictures:

      - brush style is "solid" or "clear"
      - "wordwrap" option is disabled
      - clipping is disabled
      - html formatting is disabled }

  if (Obj is TfrxCustomMemoView)
     and (TfrxCustomMemoView(Obj).BrushStyle in [bsSolid, bsClear])
     and not HTMLTags(TfrxCustomMemoView(Obj)) then
  begin
    // save clip to stack
    Write(OutStream, 'q'#13#10);
    Write(OutStream,  frFloat2Str(GetLeft(Obj.AbsLeft - Obj.Frame.Width)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop + Obj.Height + Obj.Frame.Width)) + ' ' +
      frFloat2Str((Obj.Width + Obj.Frame.Width * 2) * PDF_DIVIDER) + ' ' + frFloat2Str((Obj.Height + Obj.Frame.Width * 2) * PDF_DIVIDER) + ' re'#13#10'W'#13#10'n'#13#10);
    //ow := Obj.Width - Obj.Frame.ShadowWidth;
    //oh := Obj.Height - Obj.Frame.ShadowWidth;
    // Shadow
    if Obj.Frame.DropShadow then
    begin
      ow := Obj.Width - Obj.Frame.ShadowWidth;
      oh := Obj.Height - Obj.Frame.ShadowWidth;
      Width := frFloat2Str(ow * PDF_DIVIDER);
      Height := frFloat2Str(oh * PDF_DIVIDER);
      Right := frFloat2Str(GetLeft(Obj.AbsLeft + ow));
      Bottom := frFloat2Str(GetTop(Obj.AbsTop + oh));
      s := AnsiString(GetPDFColor(Obj.Frame.ShadowColor));
      Write(OutStream, s + ' rg'#13#10 + s + ' RG'#13#10 +
        AnsiString(frFloat2Str(GetLeft(Obj.AbsLeft + ow)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop + oh + Obj.Frame.ShadowWidth)) + ' ' +
        frFloat2Str(Obj.Frame.ShadowWidth * PDF_DIVIDER) + ' ' + frFloat2Str(oh * PDF_DIVIDER) + ' re'#13#10'B'#13#10 +
        frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Frame.ShadowWidth)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop + oh + Obj.Frame.ShadowWidth)) + ' ' +
        frFloat2Str(ow * PDF_DIVIDER) + ' ' + frFloat2Str(Obj.Frame.ShadowWidth * PDF_DIVIDER) + ' re'#13#10'B'#13#10));
    end
    else
    begin
      ow := Obj.Width;
      oh := Obj.Height;
    end;

    textObj := TfrxCustomMemoView(Obj);

    frxDrawText.Lock;
    pdfCS.Enter;
    try
      if textObj.Highlight.Active and
         Assigned(textObj.Highlight.Font) then
      begin
        textObj.Font.Assign(textObj.Highlight.Font);
        textObj.Color := textObj.Highlight.Color;
      end;
      frxDrawText.SetFont(textObj.Font);

      frxDrawText.SetOptions(textObj.WordWrap, textObj.AllowHTMLTags,
        textObj.RTLReading, textObj.WordBreak, textObj.Clipped, textObj.Wysiwyg,
        textObj.Rotation);

      frxDrawText.SetGaps(textObj.ParagraphGap, textObj.CharSpacing, textObj.LineSpacing);

      wx1 := Round((textObj.Frame.Width - 1) / 2);
      wx2 := Round(textObj.Frame.Width / 2);
      wy1 := Round((textObj.Frame.Width - 1) / 2);
      wy2 := Round(textObj.Frame.Width / 2);

      bx := Round(textObj.AbsLeft);
      by := Round(textObj.AbsTop);
      bx1 := Round(bx + textObj.Width);
      by1 := Round(by + textObj.Height);
      if ftLeft in textObj.Frame.Typ then
        Inc(bx, wx1);
      if ftRight in textObj.Frame.Typ then
        Dec(bx1, wx2);
      if ftTop in textObj.Frame.Typ then
        Inc(by, wy1);
      if ftBottom in textObj.Frame.Typ then
        Dec(by1, wy2);
      gx1 := Round(textObj.GapX);
      gy1 := Round(textObj.GapY);

      FTextRect := Rect(bx + gx1, by + gy1, bx1 - gx1 + 1, by1 - gy1 + 1);
      frxDrawText.SetDimensions(1, 1, 1, FTextRect, FTextRect);
      frxDrawText.SetText(textObj.Memo);
      {if textObj.Memo.Count = 1 then
        FLineHeight := frxDrawText.LineHeight - textObj.LineSpacing
      else}
        FLineHeight := frxDrawText.LineHeight;

      if textObj.Color <> clNone then
        Write(OutStream, GetPDFColor(textObj.Color) + ' rg'#13#10 + Left + ' ' + Bottom + ' ' +
          Width + ' ' + Height + ' re'#13#10'f'#13#10);
      // Frames
      MakeUpFrames;

      if TextObj.Rotation > 0 then
      begin
        Angle := TextObj.Rotation * Pi / 180;
        a_sin := Sin(Angle);
        a_cos := Cos(Angle);

        case TextObj.Rotation of
         90:
            begin
              a_x := GetLeft(TextObj.AbsLeft + (TextObj.Width + TextObj.Font.Size * 0.8) /2);
              a_y := GetTop(TextObj.AbsTop + TextObj.Height/2);
            end;
         180:
            begin
              a_x := GetLeft(TextObj.AbsLeft + (TextObj.Width + TextObj.Font.Size * 0.8) /2);
              if textObj.Memo.Count = 1 then
                a_y := GetTop(TextObj.AbsTop + TextObj.Height/2 - TextObj.GapY - 2)
              else
                a_y := GetTop(TextObj.AbsTop + TextObj.Height/2 - TextObj.GapY);
            end;
         270:
            begin
              a_x := GetLeft(TextObj.AbsLeft + (TextObj.Width - TextObj.Font.Size * 0.8) /2);
              a_y := GetTop(TextObj.AbsTop + TextObj.Height/2);
            end
          else
            begin
              case TextObj.Rotation of
                45..135, 225..315:
                  begin
                    rx := TextObj.Height;
                    ry := TextObj.Width;
                  end
                else
                  begin
                    rx := TextObj.Width;
                    ry := TextObj.Height;
                  end
              end;

              a_x := GetLeft(TextObj.AbsLeft + 0.5 * (rx * a_cos + ry * a_sin));
              a_y := GetTop(TextObj.AbsTop + 0.5 * (rx * a_sin + ry * a_cos));
            end
        end;

        WriteLn(OutStream, frFloat2Str(a_cos) + ' ' + frFloat2Str(a_sin) + ' ' +
          frFloat2Str(-a_sin) + ' ' + frFloat2Str(a_cos) + ' ' +
          frFloat2Str(a_x) + ' ' + frFloat2Str(a_y) + ' cm');
      end;

      if textObj.Underlines then
      begin
        iz := Trunc(textObj.Height / FLineHeight);
        for i:= 0 to iz - 1 do
        begin
          y := GetTop(textObj.AbsTop + textObj.GapY + 1 + FLineHeight * (i + 1) - textObj.LineSpacing);
          Write(OutStream, GetPDFColor(textObj.Frame.Color) + ' RG'#13#10 +
            frFloat2Str(textObj.Frame.Width * PDF_DIVIDER) + ' w'#13#10 +
            Left + ' ' + frFloat2Str(y) + ' m'#13#10 +
            Right + ' ' + frFloat2Str(y) + ' l'#13#10'S'#13#10);
        end;
      end;

{$IFDEF Delphi10}
      Lines := TfrxWideStrings.Create;
{$ELSE}
      Lines := TWideStrings.Create;
{$ENDIF}
      Lines.Text := frxDrawText.WrappedText;
      if Lines.Count > 0 then
      begin
        if textObj.Lines.Count <> Lines.Count then
        begin
          for i := 0 to Lines.Count - 1 do
            Lines.Objects[i] := frxDrawText.Text.Objects[i];
        end;
        FontIndex := GetObjFontNumber(textObj.Font);
        pdfFont := TfrxPDFFont(FPageFonts[FontIndex]);
        simulateBold := (fsBold in textObj.Font.Style) and FontNeedsBoldItalicSimulation(textObj.Font);
        simulateItalic := (fsItalic in textObj.Font.Style) and FontNeedsBoldItalicSimulation(textObj.Font);
{$IFDEF Delphi12}
        Write(OutStream, TfrxPDFFont(FFonts[FontIndex]).Name +
          AnsiString(' ' + IntToStr(textObj.Font.Size) + ' Tf'#13#10));
{$ELSE}
        Write(OutStream, TfrxPDFFont(FFonts[FontIndex]).Name +
          ' ' + IntToStr(textObj.Font.Size) + ' Tf'#13#10);
{$ENDIF}
        if textObj.Font.Color <> clNone then
          TempColor := textObj.Font.Color
        else
          TempColor := clBlack;
        Write(OutStream, GetPDFColor(TempColor) + ' rg'#13#10);
        FCharSpacing := textObj.CharSpacing * PDF_DIVIDER;
        if FCharSpacing <> 0 then
          Write(OutStream, frFloat2Str(FCharSpacing) + ' Tc'#13#10);

        // output lines of memo
        FUnderlinePosition := textObj.Font.Size * 0.12;
        FStrikeoutPosition := textObj.Font.Size * 0.28;
        frxDrawText.SetGaps(0, TfrxCustomMemoView(Obj).CharSpacing, TfrxCustomMemoView(Obj).LineSpacing);

        for i := 0 to Lines.Count - 1 do
        begin
          if textObj.Lines.Count <> Lines.Count then
          begin
            if Integer(Lines.Objects[i]) and 1 <> 0 then
              PGap := textObj.ParagraphGap
            else
              PGap := 0;
          end else
          if i = 0 then
            PGap := textObj.ParagraphGap
          else
            PGap := 0;

          if Length(Lines[i]) > 0 then
          begin
            // Text output
            if textObj.HAlign <> haRight then
              FCharSpacing := 0;

            RemappedStr := pdfFont.RemapString(UTF8ToUTF16(Lines[i]), textObj.RTLReading);
            if pdfFont.FSubstitutedFont <> '' then
              if FSubstitutedFonts.IndexOf(pdfFont.FSubstitutedFont) = -1 then
                FSubstitutedFonts.Add(pdfFont.FSubstitutedFont);
            FLineWidth := pdfFont.LastRemappedStrWidth / PDF_DIVIDER / 1000 * textObj.Font.Size;

            if textObj.Rotation > 0 then
            begin
              if ((textObj.Rotation >= 45) and (textObj.Rotation <= 135)) or
                ((textObj.Rotation >= 225 ) and (textObj.Rotation <= 315)) then
              begin
                rx := oh;
                ry := ow;
              end
              else
              begin
                rx := ow;
                ry := oh;
              end;
              HWidth := rx;
              x := -FCharSpacing * (Length(Lines[i]) - 1) + (GetHTextPosR(rx / 2, Lines[i], textObj.HAlign)) * PDF_DIVIDER;
              y := -(GetVTextPosR(ry / 2, textObj.VAlign, i, Lines.Count)) * PDF_DIVIDER + textObj.Font.Size * 0.4;
            end
            else
            begin
              HWidth := ow - textObj.GapX * 2 - PGap;
              x := -FCharSpacing * (Length(Lines[i]) - 1) + GetLeft(GetHTextPos(textObj.AbsLeft + textObj.GapX + PGap,
                HWidth, Lines[i], textObj.HAlign, textObj.RTLReading));
              y := GetTop(GetVTextPos(textObj.AbsTop + textObj.GapY - textObj.Font.Size * 0.1,
                oh - textObj.GapY * 2, textObj.VAlign, i, Lines.Count) - textObj.LineSpacing);
            end;

            Write(OutStream, 'BT'#13#10);
            Write(OutStream, frFloat2Str(x) + ' ' + frFloat2Str(y) + ' Td'#13#10);
            if simulateItalic then
            begin
              Write(OutStream, '1 0 0.3333 1 ');
              Write(OutStream, frFloat2Str(x) + ' ' + frFloat2Str(y) + ' Tm'#13#10);
            end;
            if simulateBold then
            begin
              Write(OutStream, '2 Tr ');
              Write(OutStream, frFloat2Str(textObj.Font.Size / 35.0));
              Write(OutStream, ' w ' + GetPDFColor(TempColor) + ' RG'#13#10);
            end;
            //if NeedSpaceAdjustment then
            //  Write(OutStream, '[<' + StrToHexSp(Lines[i], RemappedStr, SpaceAdjustment) + '>] TJ'#13#10'ET'#13#10)
            //else
              Write(OutStream, '<' + StrToHex(RemappedStr) + '> Tj'#13#10'ET'#13#10);
            if simulateBold then
              Write(OutStream, '0 Tr'#13#10);

            { underlined text }

            with textObj do
              if fsUnderline in Font.Style then
              begin
                Cmd('[] 0 d', '');
                Cmd(GetPDFColor(Font.Color), 'RG');
                Cmd(frFloat2Str(Font.Size * 0.08), 'w');
                Cmd(frFloat2Str(x) + ' ' + frFloat2Str(y - FUnderlinePosition), 'm');
                Cmd(frFloat2Str(x + FLineWidth * PDF_DIVIDER) + ' ' +
                  frFloat2Str(y - FUnderlinePosition), 'l');

                Cmd('', 'S');
              end;

            { struck out text }

            if fsStrikeout in (textObj.Font.Style) then
              Write(OutStream, GetPDFColor(textObj.Font.Color) + ' RG'#13#10 +
                frFloat2Str(textObj.Font.Size * 0.08) + ' w'#13#10 +
                frFloat2Str(x) + ' ' + frFloat2Str(y + FStrikeoutPosition) + ' m'#13#10 +
                frFloat2Str(x +  FLineWidth * PDF_DIVIDER) +
                ' ' + frFloat2Str(y + FStrikeoutPosition) + ' l'#13#10'S'#13#10);
          end;
        end;
      end;
    finally
      frxDrawText.Unlock;
      pdfCS.Leave;
    end;
    // restore clip
    Write(OutStream, 'Q'#13#10);
    Lines.Free;
  end
  // Lines
  else if Obj is TfrxCustomLineView then
  begin
    WriteLn(OutStream, GetPDFDash(Obj.Frame.Style, Obj.Frame.Width));
    Write(OutStream, GetPDFColor(Obj.Frame.Color) + ' RG'#13#10 +
      frFloat2Str(Obj.Frame.Width * PDF_DIVIDER) + ' w'#13#10 +
      Left + ' ' + Top + ' m'#13#10 +
      Right + ' ' + Bottom + ' l'#13#10'S'#13#10);
    if TfrxCustomLineView(Obj).ArrowStart then
      DrawArrow(TfrxCustomLineView(Obj), GetLeft(Obj.AbsLeft + Obj.Width), GetTop(Obj.AbsTop + Obj.Height), GetLeft(Obj.AbsLeft), GetTop(Obj.AbsTop));
    if TfrxCustomLineView(Obj).ArrowEnd then
      DrawArrow(TfrxCustomLineView(Obj), GetLeft(Obj.AbsLeft), GetTop(Obj.AbsTop), GetLeft(Obj.AbsLeft + Obj.Width), GetTop(Obj.AbsTop + Obj.Height));
  end
  // Rects
  else if (Obj is TfrxShapeView) and (TfrxShapeView(Obj).Shape = skRectangle) then
  begin
    WriteLn(OutStream, GetPDFDash(Obj.Frame.Style, Obj.Frame.Width));
    Write(OutStream, GetPDFColor(Obj.Frame.Color) + ' RG'#13#10 +
      frFloat2Str(Obj.Frame.Width * PDF_DIVIDER) + ' w'#13#10 +
      GetPDFColor(Obj.Color) + ' rg'#13#10 +
      Left + ' ' + Bottom + ' '#13#10 +
      Width + ' ' + Height + ' re'#13#10);
    if Obj.Color <> clNone then
      Write(OutStream, 'B'#13#10)
    else
      Write(OutStream, 'S'#13#10);
  end

  { Rounded rectangle }

  else if (Obj is TfrxShapeView) and (TfrxShapeView(Obj).Shape = skRoundRectangle) then
    WriteRoundedRect(TfrxShapeView(Obj))

  // Shape line 1
  else if (Obj is TfrxShapeView) and (TfrxShapeView(Obj).Shape = skDiagonal1) then
  begin
    WriteLn(OutStream, GetPDFDash(Obj.Frame.Style, Obj.Frame.Width));
    Write(OutStream, GetPDFColor(Obj.Frame.Color) + ' RG'#13#10 +
      frFloat2Str(Obj.Frame.Width * PDF_DIVIDER) + ' w'#13#10 +
      Left + ' ' + Bottom + ' m'#13#10 + Right + ' ' + Top + ' l'#13#10'S'#13#10)
  end
  // Shape line 2
  else if (Obj is TfrxShapeView) and (TfrxShapeView(Obj).Shape = skDiagonal2) then
  begin
    WriteLn(OutStream, GetPDFDash(Obj.Frame.Style, Obj.Frame.Width));
    Write(OutStream, GetPDFColor(Obj.Frame.Color) + ' RG'#13#10 +
      frFloat2Str(Obj.Frame.Width * PDF_DIVIDER) + ' w'#13#10 +
      Left + ' ' + Top + ' m'#13#10 + Right + ' ' + Bottom + ' l'#13#10'S'#13#10)
  end
  // Shape diamond
  else if (Obj is TfrxShapeView) and (TfrxShapeView(Obj).Shape = skDiamond) then
  begin
    WriteLn(OutStream, GetPDFDash(Obj.Frame.Style, Obj.Frame.Width));
    WriteLn(OutStream, GetPDFColor(Obj.Frame.Color) + ' RG'#13#10 +
      frFloat2Str(Obj.Frame.Width * PDF_DIVIDER) + ' w'#13#10 +
      GetPDFColor(Obj.Color) + ' rg');
    WriteLn(OutStream, frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Width / 2)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop)) + ' m ' +
      frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Width)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop + Obj.Height / 2)) + ' l ' +
      frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Width / 2)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop + Obj.Height)) + ' l ' +
      frFloat2Str(GetLeft(Obj.AbsLeft)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop + Obj.Height / 2)) + ' l ' +
      frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Width / 2)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop)) + ' l');
    if Obj.Color <> clNone then
      Write(OutStream, 'B'#13#10)
    else
      Write(OutStream, 'S'#13#10);
  end
  // Shape triangle
  else if (Obj is TfrxShapeView) and (TfrxShapeView(Obj).Shape = skTriangle) then
  begin
    WriteLn(OutStream, GetPDFDash(Obj.Frame.Style, Obj.Frame.Width));
    WriteLn(OutStream, GetPDFColor(Obj.Frame.Color) + ' RG'#13#10 +
      frFloat2Str(Obj.Frame.Width * PDF_DIVIDER) + ' w'#13#10 +
      GetPDFColor(Obj.Color) + ' rg');
    WriteLn(OutStream, frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Width / 2)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop)) + ' m ' +
      frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Width)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop + Obj.Height)) + ' l ' +
      frFloat2Str(GetLeft(Obj.AbsLeft)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop + Obj.Height)) + ' l ' +
      frFloat2Str(GetLeft(Obj.AbsLeft + Obj.Width / 2)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop)) + ' l');
    if Obj.Color <> clNone then
      Write(OutStream, 'B'#13#10)
    else
      Write(OutStream, 'S'#13#10);
  end
  // Shape ellipse
  else if (Obj is TfrxShapeView) and (TfrxShapeView(Obj).Shape = skEllipse) then
  begin
    WriteLn(OutStream, GetPDFDash(Obj.Frame.Style, Obj.Frame.Width));
    WriteLn(OutStream, GetPDFColor(Obj.Frame.Color) + ' RG'#13#10 +
      frFloat2Str(Obj.Frame.Width * PDF_DIVIDER) + ' w'#13#10 +
      GetPDFColor(Obj.Color) + ' rg');
    rx := Obj.Width / 2;
    ry := Obj.Height / 2;
    WriteLn(OutStream, frFloat2Str(GetLeft(Obj.AbsLeft + rx * 2)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop + ry)) + ' m');
    WriteLn(OutStream,
      frFloat2Str(GetLeft(Obj.AbsLeft + rx * 2)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop + ry * KAPPA1)) + ' ' +
      frFloat2Str(GetLeft(Obj.AbsLeft + rx * KAPPA1)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop + ry * 2)) + ' ' +
      frFloat2Str(GetLeft(Obj.AbsLeft + rx)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop + ry * 2)) + ' c');
    WriteLn(OutStream,
      frFloat2Str(GetLeft(Obj.AbsLeft + rx * KAPPA2)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop + ry * 2)) + ' ' +
      frFloat2Str(GetLeft(Obj.AbsLeft)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop + ry * KAPPA1)) + ' ' +
      frFloat2Str(GetLeft(Obj.AbsLeft)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop + ry)) + ' c');
    WriteLn(OutStream,
      frFloat2Str(GetLeft(Obj.AbsLeft)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop + ry * KAPPA2)) + ' ' +
      frFloat2Str(GetLeft(Obj.AbsLeft + rx * KAPPA2)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop)) + ' ' +
      frFloat2Str(GetLeft(Obj.AbsLeft + rx)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop)) + ' c');
    WriteLn(OutStream,
      frFloat2Str(GetLeft(Obj.AbsLeft + rx * KAPPA1)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop)) + ' ' +
      frFloat2Str(GetLeft(Obj.AbsLeft + rx * 2)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop + ry * KAPPA2)) + ' ' +
      frFloat2Str(GetLeft(Obj.AbsLeft + rx * 2)) + ' ' + frFloat2Str(GetTop(Obj.AbsTop + ry)) + ' c');
    if Obj.Color <> clNone then
      Write(OutStream, 'B'#13#10)
    else
      Write(OutStream, 'S'#13#10);
  end
  else if (Obj is TfrxCheckboxView) then ExportChebox(Obj)
  else
  // Bitmaps
{$IFNDEF OLD_STYLE}
  // Bitmaps
  if not ((Obj.Name = '_pagebackground') and (not Background)) and
     (Obj.Height > 0) and (Obj.Width > 0) then
  begin
    if Obj.Frame.Width > 0 then
    begin
      OldFrameWidth := Obj.Frame.Width;
      Obj.Frame.Width := 0;
    end;

    FRealBounds := Obj.GetRealBounds;
    dx := FRealBounds.Right - FRealBounds.Left;
    dy := FRealBounds.Bottom - FRealBounds.Top;

    if (dx = Obj.Width) or (Obj.AbsLeft = FRealBounds.Left) then
      fdx := 0
    else if (Obj.AbsLeft + Obj.Width) = FRealBounds.Right then
      fdx := (dx - Obj.Width)
    else
      fdx := (dx - Obj.Width) / 2;

    if (dy = Obj.Height) or (Obj.AbsTop = FRealBounds.Top) then
      fdy := 0
    else if (Obj.AbsTop + Obj.Height) = FRealBounds.Bottom then
      fdy := (dy - Obj.Height)
    else
      fdy := (dy - Obj.Height) / 2;

    if Obj is TfrxPictureView then
      if TfrxPictureView(Obj).Picture.Graphic = nil then
        begin
          MakeUpFrames;
          exit;
        end;

    if (dx < 1) or (dy < 1)  then
      begin
        MakeUpFrames;
        exit;
      end;

    TempBitmap := TBitmap.Create;

    try
      TempBitmap.PixelFormat := pf32bit; //pf24bit; //

      if (PrintOptimized or (Obj is TfrxCustomMemoView)) and (Obj.BrushStyle in [bsSolid, bsClear]) then
        i := PDF_PRINTOPT
      else
        i := 1;

      iz := 0;

      if (Obj.ClassName = 'TfrxBarCodeView') and not PrintOptimized then
      begin
        i := 2;
        iz := i;
      end;

      if obj is TfrxPictureView then
        begin
          PictObj := TfrxPictureView(obj);
          if (PictObj.Transparent and FTransparency) or PictObj.Center or (not FSaveOriginalImages) then
            begin
              TempBitmap.Width := Round(dx * i);// + i;
              TempBitmap.Height := Round(dy * i);// + i;
            end
          else
            begin
              if PictObj.Stretched then
                begin
                  TempBitmap.Width := PictObj.Picture.Width;
                  TempBitmap.Height := PictObj.Picture.Height;
                end
              else
                begin
                  if dx < PictObj.Picture.Width then
                    TempBitmap.Width := Round(dx * i)
                  else
                    TempBitmap.Width := PictObj.Picture.Width;
                  if dy < PictObj.Picture.Height then
                    TempBitmap.Height := Round(dy * i)
                  else
                    TempBitmap.Height := PictObj.Picture.Height;
                end;
            end;
        end
      else
        begin
          TempBitmap.Width := Round(dx * i);// + i;
          TempBitmap.Height := Round(dy * i);// + i;
        end;
      XMaskStream := nil;// warning x64 fix
      MaskSize := 0;
      XMaskId := -1;
      IsTransparent := False;
      TransparentColorMask := clWhite;
      IsTransparent := (Obj.Color = clNone) and FTransparency;
      IsMasked := IsTransparent;

      if Obj is TfrxPictureView then
      begin
        TransparentColorMask := PictObj.TransparentColor;
        IsTransparent := PictObj.Transparent and FTransparency;
        if PictObj.Picture.Graphic <> nil then
          if PictObj.Picture.Graphic.Empty then
            IsTransparent := IsTransparent and PictObj.Picture.Graphic.Transparent;
        IsMasked := (PictObj.TransparentColor <> clNone) and IsTransparent;
      end;

      if IsTransparent then
      begin
        TempBitmap.Canvas.Brush.Color := TransparentColorMask;
        TempBitmap.Canvas.FillRect(Rect(0, 0, TempBitmap.Width, TempBitmap.Height));
      end;
      // image dont have alpha chanel, try to create mask by trancparent color
      if IsMasked then
      begin
        TempMaskBitmap := TBitmap.Create;
        TempMaskBitmap.Width := TempBitmap.Width;
        TempMaskBitmap.Height := TempBitmap.Height;
        TempMaskBitmap.PixelFormat := pf32bit;
        TempMask8bitBitmap := TBitmap.Create;
        TempMask8bitBitmap.Width := TempBitmap.Width;
        TempMask8bitBitmap.Height := TempBitmap.Height;
        TempMask8bitBitmap.PixelFormat := pf8bit;
        try
          TempMaskBitmap.Canvas.Brush.Color := TransparentColorMask;
          TempMaskBitmap.Canvas.FillRect(Rect(0, 0, TempMaskBitmap.Width, TempMaskBitmap.Height));
          TempMask8bitBitmap.Canvas.Brush.Color := $FFFFFF;
          TempMask8bitBitmap.Canvas.FillRect(Rect(0, 0, TempMask8bitBitmap.Width, TempMask8bitBitmap.Height));
          // draw object like text in black/white chanel for mask
          Obj.DrawAsMask := True;
          Obj.Draw(TempMaskBitmap.Canvas, i, i, -Round((Obj.AbsLeft - fdx) * i) + iz, -Round((Obj.AbsTop - fdy)* i));
          Obj.DrawAsMask := False;
          TempMaskBitmap.Mask(TransparentColorMask);
          TempMask8bitBitmap.Canvas.CopyMode := cmSrcInvert;
          TempMask8bitBitmap.Canvas.Draw(0, 0, TempMaskBitmap);
          MaskSize := TempMask8bitBitmap.Height * TempMask8bitBitmap.Width;
          SetLength( MaskBytes, MaskSize );
          for iy := 0 to TempMask8bitBitmap.Height - 1 do
            Move(TempMask8bitBitmap.ScanLine[iy]^,
             MaskBytes[iy * TempMask8bitBitmap.Width], TempMask8bitBitmap.Width);
            //CopyMemory(@MaskBytes[iy * TempMask8bitBitmap.Width], TempMask8bitBitmap.ScanLine[iy], TempMask8bitBitmap.Width);
        except

        end;
      end;



      try
        if obj is TfrxPictureView then
          begin
            if (PictObj.Transparent and FTransparency) or PictObj.Center or (not FSaveOriginalImages) then
              Obj.Draw(TempBitmap.Canvas, i, i, -Round((Obj.AbsLeft - fdx) * i) + iz, -Round((Obj.AbsTop - fdy)* i))
          else
              TempBitmap.Canvas.Draw(0, 0, PictObj.Picture.Graphic);
              {PictObj.Draw(TempBitmap.Canvas, PictObj.Picture.Width/dx, PictObj.Picture.Height/dy,
                                              -Round((Obj.AbsLeft - fdx) * PictObj.Picture.Width/dx) + iz,
                                              -Round((Obj.AbsTop - fdy) * PictObj.Picture.Height/dy));}
          end
        else
          Obj.Draw(TempBitmap.Canvas, i, i, -Round((Obj.AbsLeft - fdx) * i) + iz, -Round((Obj.AbsTop - fdy)* i));
        // only for images with alpha chanel
        if(IsTransparent and not IsMasked) then
        begin
          MaskSize := TempBitmap.Height * TempBitmap.Width;
          SetLength( MaskBytes, MaskSize );
          for iy := 0 to TempBitmap.Height - 1 do
          begin
            dots := TempBitmap.ScanLine[iy];
            for ix := 0 to TempBitmap.Width - 1 do
              MaskBytes[ix + iy * TempBitmap.Width] := dots[ix].Alpha;
          end;
        end;

      except
        // charts throw exceptions when numbers are malformed
      end;


      { Write XObject with a picture inside }

      Jpg := TJPEGImage.Create;

      try
        if (Obj.ClassName = 'TfrxBarCodeView') or
           (Obj is TfrxCustomLineView) or
           (Obj is TfrxShapeView) then
        begin
          Jpg.PixelFormat := pf8Bit;
          Jpg.CompressionQuality := FQuality + 5;
        end
        else
        begin
          Jpg.PixelFormat := pf24Bit;
          Jpg.CompressionQuality := FQuality;
        end;

        Jpg.Assign(TempBitmap);
        XObjectStream := TMemoryStream.Create;
        XMaskStream := TMemoryStream.Create;
        try
          Jpg.SaveToStream(XObjectStream);
          // Prepare mask
          if IsTransparent then
          begin
            XMaskStream.Position := 0;
            XMaskStream.Write(Pointer(MaskBytes)^, MaskSize);

            XMaskStream.Position := 0;
            GetStreamHash(XMaskHash, XMaskStream);
            MaskIndex := FindXObject(XMaskHash);

              if MaskIndex < 0 then
              begin
                XMaskId := UpdateXRef;
                XObjectId := UpdateXRef;
                MaskIndex := AddXObject(XMaskId, XMaskHash);
                Writeln(pdf, ObjNumber(XMaskId));

                  WriteLn(pdf, '<< /Type /XObject');
                  WriteLn(pdf, '/Subtype /Image');
                  WriteLn(pdf, '/Width ' + IntToStr(TempBitmap.Width));
                  WriteLn(pdf, '/Height ' + IntToStr(TempBitmap.Height));
                  WriteLn(pdf, '/ColorSpace /DeviceGray/Matte[ 0 0 0] ');
                  WriteLn(pdf, '/BitsPerComponent 8');
                  WriteLn(pdf, '/Interpolate false');

                  //////////  NEED TO REPLACE

                  WriteLn(pdf, ' /Length ' + IntToStr(MaskSize) + ' >>');
                  WriteLn(pdf, 'stream');
                  if FProtection then
                    CryptStream(XMaskStream, pdf, FEncKey, XMaskId)
                  else
                    pdf.CopyFrom(XMaskStream, 0);

                  Write(pdf, #13#10'endstream'#13#10);
                  WriteLn(pdf, 'endobj');




              end;
            { hash should be calculated for Pic + Mask }
            XMaskStream.Position := XMaskStream.Size;
            XObjectStream.Position := 0;
            XMaskStream.CopyFrom(XObjectStream, 0);
            XMaskStream.Position := 0;
            XObjectStream.Position := 0;
            GetStreamHash(XObjectHash, XMaskStream);
            PicIndex := FindXObject(XObjectHash);
          end
          else
          begin
            XObjectStream.Position := 0;
            GetStreamHash(XObjectHash, XObjectStream);
            PicIndex := FindXObject(XObjectHash);
          end;

          if PicIndex < 0 then
          begin
            XObjectId := UpdateXRef;
            PicIndex := AddXObject(XObjectId, XObjectHash);

            Writeln(pdf, ObjNumber(XObjectId));
            Writeln(pdf, '<<');
            Writeln(pdf, '/Type /XObject');
            Writeln(pdf, '/Subtype /Image');
            Writeln(pdf, '/ColorSpace /DeviceRGB');
            Writeln(pdf, '/BitsPerComponent 8');
            Writeln(pdf, '/Filter /DCTDecode');
            Writeln(pdf, '/Width ' + IntToStr(Jpg.Width));
            Writeln(pdf, '/Height ' + IntToStr(Jpg.Height));
            if IsTransparent then
              WriteLn(pdf, '/SMask ' + ObjNumberRef(XMaskId));

            ///// NEED TO REPLACE

            Writeln(pdf, '/Length ' + IntToStr(XObjectStream.Size));
            Writeln(pdf, '>>');

            Write(pdf, 'stream'#13#10); // 'stream'#10 is also valid
            XObjectStream.Position := 0;
            if FProtection then
              CryptStream(XObjectStream, pdf, FEncKey, XObjectId)
            else
              pdf.CopyFrom(XObjectStream, 0);
            Write(pdf, #13#10'endstream'#13#10);
            Inc(FPicTotalSize, XObjectStream.Size);
            Writeln(pdf, 'endobj');



          end;
        finally
          XObjectStream.Free;
          XMaskStream.Free;
        end;
      finally
        Jpg.Free;
        if IsTransparent then
        begin
          SetLength(MaskBytes, 0);
          if IsMasked then
          begin
            TempMaskBitmap.Free;
            TempMask8bitBitmap.Free;
          end;
        end;
      end;
    finally
      TempBitmap.Free;
    end;

    { Reference to this XObject }

    SetLength(FUsedXObjects, Length(FUsedXObjects) + 1);
    FUsedXObjects[High(FUsedXObjects)] := PicIndex;

    dx1 := dx;
    dy1 := dy;

    if Obj is TfrxPictureView then
      begin
        if not PictObj.Center then
          begin
            if PictObj.KeepAspectRatio and PictObj.Stretched and FSaveOriginalImages then
              begin
                if PictObj.Picture.Width <> 0 then
                  kx := dx / PictObj.Picture.Width
                else
                  kx := 0;
                if PictObj.Picture.Height <> 0 then
                  ky := dy / PictObj.Picture.Height
                else
                  ky := 0;
                if kx < ky then
                  dy1 := PictObj.Picture.Height * kx
                else
                  dx1 := PictObj.Picture.Width * ky;
              end
            else
              if not PictObj.Stretched then
                begin
                  if dx > PictObj.Picture.Width then dx1 := PictObj.Picture.Width;
                  if dy > PictObj.Picture.Height then dy1 := PictObj.Picture.Height;
                end;
          end;
      end;
    Writeln(OutStream, 'q');
    Writeln(OutStream,
      frFloat2Str(dx1 * PDF_DIVIDER) + ' ' +
      '0 ' +
      '0 ' +
      frFloat2Str(dy1 * PDF_DIVIDER) + ' ' +
      frFloat2Str(GetLeft(Obj.AbsLeft - fdx)) + ' ' +
      frFloat2Str(GetTop(Obj.AbsTop - fdy + dy1)) + ' ' +
      'cm');
    Writeln(OutStream, '/Im' + IntToStr(PicIndex) + ' Do');
    Writeln(OUtStream, 'Q');

    if OldFrameWidth > 0 then
      Obj.Frame.Width := OldFrameWidth;

    MakeUpFrames;
  end;
{$ELSE}
  if not ((Obj.Name = '_pagebackground') and (not Background)) and
     (Obj.Height > 0) and (Obj.Width > 0) then
  begin
    if Obj.Frame.Width > 0 then
    begin
      OldFrameWidth := Obj.Frame.Width;
      Obj.Frame.Width := 0;
    end;

    FRealBounds := Obj.GetRealBounds;
    dx := FRealBounds.Right - FRealBounds.Left;
    dy := FRealBounds.Bottom - FRealBounds.Top;

    if (dx = Obj.Width) or (Obj.AbsLeft = FRealBounds.Left) then
      fdx := 0
    else if (Obj.AbsLeft + Obj.Width) = FRealBounds.Right then
      fdx := (dx - Obj.Width)
    else
      fdx := (dx - Obj.Width) / 2;

    if (dy = Obj.Height) or (Obj.AbsTop = FRealBounds.Top) then
      fdy := 0
    else if (Obj.AbsTop + Obj.Height) = FRealBounds.Bottom then
      fdy := (dy - Obj.Height)
    else
      fdy := (dy - Obj.Height) / 2;

    TempBitmap := TBitmap.Create;
    TempBitmap.PixelFormat := pf24bit;

    if (PrintOptimized or (Obj is TfrxCustomMemoView)) and (Obj.BrushStyle in [bsSolid, bsClear]) then
      i := PDF_PRINTOPT
    else
      i := 1;

    iz := 0;

    if (Obj.ClassName = 'TfrxBarCodeView') and not PrintOptimized then
    begin
      i := 2;
      iz := i;
    end;

    TempBitmap.Width := Round(dx * i) + i;
    TempBitmap.Height := Round(dy * i) + i;

    Obj.Draw(TempBitmap.Canvas, i, i, -Round((Obj.AbsLeft - fdx) * i) + iz, -Round((Obj.AbsTop - fdy)* i));

    if dx <> 0 then
      BWidth := frFloat2Str(dx * PDF_DIVIDER)
    else
      BWidth := '1';
    if dy <> 0 then
      BHeight := frFloat2Str(dy * PDF_DIVIDER)
    else
      BHeight := '1';

    Write(OutStream, 'q'#13#10 + BWidth + ' 0 0 ' + BHeight + ' ' +
      frFloat2Str(GetLeft(Obj.AbsLeft - fdx)) + ' ' +
      frFloat2Str(GetTop(Obj.AbsTop - fdy + dy)) + ' cm'#13#10'BI'#13#10 +
      '/W ' + IntToStr(TempBitmap.Width) + #13#10 +
      '/H ' + IntToStr(TempBitmap.Height) + #13#10'/CS /RGB'#13#10'/BPC 8'#13#10'/I true'#13#10'/F [/DCT]'#13#10'ID ');
    Jpg := TJPEGImage.Create;

    if (Obj.ClassName = 'TfrxBarCodeView') or
       (Obj is TfrxCustomLineView) or
       (Obj is TfrxShapeView) then
    begin
      Jpg.PixelFormat := jf8Bit;
      Jpg.CompressionQuality := FQuality+5; // 95;
    end
    else begin
      Jpg.PixelFormat := jf24Bit;
      Jpg.CompressionQuality := FQuality; //90;
    end;

    Jpg.Assign(TempBitmap);
    Jpg.SaveToStream(OutStream);
    Jpg.Free;

    Write(OutStream, #13#10'EI'#13#10'Q'#13#10);
    TempBitmap.Free;
    if OldFrameWidth > 0 then
      Obj.Frame.Width := OldFrameWidth;
    MakeUpFrames;
  end;
{$ENDIF}
end;

function TfrxPDFExport.StrToHex(const Value: WideString): AnsiString;
var
  i: integer;
begin
  result := '';
  for i := 1 to Length(Value) do
    result := result  + AnsiString(IntToHex(Word(Value[i]), 4));
end;

function TfrxPDFExport.StrToHexSp(const SourceStr, Value: WideString;
  SpaceAdjustment: Extended): AnsiString;
var
  i: integer;
  w: Integer;
  z: Extended;
begin
  result := '';
  z := 0;
  for i := 1 to Length(Value) do
  begin
    result := result + AnsiString(IntToHex(Word(Value[i]), 4));
    if SourceStr[i] = ' ' then
    begin
      w := Trunc(SpaceAdjustment);
      z := z + Frac(SpaceAdjustment);
      if z > 1 then
      begin
        Inc(w);
        z := Frac(z);
      end;
      if w <> 0 then
        result := result + AnsiString('>' + IntToStr(w) + '<');
    end;
  end;
end;

function TfrxPDFExport.AddPage(Page: TfrxReportPage): TfrxPDFPage;
var
  p: TfrxPDFPage;
begin
  p := TfrxPDFPage.Create;
  p.Height := Page.Height * PDF_DIVIDER;
  FPages.Add(p);
  Result := p;
end;

function TfrxPDFExport.ObjNumber(FNumber: longint): String;
begin
  result := IntToStr(FNumber) + ' 0 obj';
end;

function TfrxPDFExport.ObjNumberRef(FNumber: longint): String;
begin
  result := IntToStr(FNumber) + ' 0 R';
end;

function TfrxPDFExport.UpdateXRef: longint;
begin
  FXRef.Add(PrepXrefPos(pdf.Position));
  result := FXRef.Count;
end;

function TfrxPDFExport.GetPDFColor(const Color: TColor): String;
var
  TheRgbValue : TColorRef;
begin
  if Color = clBlack then
    Result := '0 0 0'
  else if Color = clWhite then
    Result := '1 1 1'
  else if Color = FLastColor then
    Result := FLastColorResult
  else begin
    TheRgbValue := ColorToRGB(Color);
    Result:= frFloat2Str(Byte(TheRGBValue) / 255) + ' ' +
      frFloat2Str(Byte(TheRGBValue shr 8) / 255) + ' ' +
      frFloat2Str(Byte(TheRGBValue shr 16) / 255);
    FLastColor := Color;
    FLastColorResult := Result;
  end;
end;

function TfrxPDFExport.FindXObject(const Hash: TfrxPDFXObjectHash): Integer;
begin
  for Result := 0 to High(FXObjects) do
    if CompareMem(@Hash, @FXObjects[Result].Hash, SizeOf(Hash)) then
      Exit;

  Result := -1;
end;

function TfrxPDFExport.AddXObject(Id: Integer; const Hash: TfrxPDFXObjectHash
  ): Integer;
var
  X: TfrxPDFXObject;
begin
  X.ObjId := Id;
  Move(Hash, X.Hash, SizeOf(Hash));
  SetLength(FXObjects, Length(FXObjects) + 1);
  FXObjects[High(FXObjects)] := X;
  Result := High(FXObjects);
end;

procedure TfrxPDFExport.ClearXObject;
var
  i:  Integer;
begin
  for i := 0 to High(FXObjects) do
  begin
    FXObjects[i].ObjId := 0;
    FillChar( FXObjects[i].Hash, Sizeof(TfrxPDFXObjectHash), 0 );
  end;
end;

procedure TfrxPDFExport.GetStreamHash(out Hash: TfrxPDFXObjectHash; S: TStream);
var
  H: TCryptoHash;
begin
  H := TCryptoMD5.Create;

  try
    H.Push(S);
    H.GetDigest(Hash[0], SizeOf(Hash));
  finally
    H.Free
  end;
end;

procedure TfrxPDFExport.AddStructure;
var
  roleMaps: longint;
begin
  roleMaps := UpdateXRef;
  WriteLn(pdf, ObjNumber(roleMaps));
  WriteLn(pdf, '<<'#13#10'/Footnote /Note'#13#10'/Endnote /Note'#13#10'/Textbox /Sect'#13#10'/Header /Sect');
  WriteLn(pdf, '/Footer /Sect'#13#10'/InlineShape /Sect'#13#10'/Annotation /Sect'#13#10'/Artifact /Sect');
  WriteLn(pdf, '/Workbook /Document'#13#10'/Worksheet /Part'#13#10'/Macrosheet /Part'#13#10'/Chartsheet /Part');
  WriteLn(pdf, '/Dialogsheet /Part'#13#10'/Slide /Part'#13#10'/Chart /Sect'#13#10'/Diagram /Figure'#13#10'>>'#13#10'endobj');
  FStructId := UpdateXRef;
  WriteLn(pdf, ObjNumber(FStructId));
  WriteLn(pdf, '<<'#13#10'/Type /StructTreeRoot');
  WriteLn(pdf, '/RoleMap ' + ObjNumberRef(roleMaps));
  // /ParentTree /K /ParentTreeNextKey
  WriteLn(pdf, '>>'#13#10'endobj');
end;

procedure TfrxPDFExport.AddMetaData;
var
  Res : TResourceStream;
  MemRes: TMemoryStream;
  meta_xml: AnsiString;
  current_time: String;
begin

  Res := TResourceStream.Create(hInstance, 'Metafile', RT_RCDATA);
  try
    SetLength(meta_xml, integer(Res.Size));
    Res.Read(meta_xml[1], Res.Size);
    current_time := FormatDateTime('yyyy-MM-dd', Now) + 'T' + FormatDateTime('HH:mm:ss+00:00', Now);

    // do prepare meta
    meta_xml := StringReplace(meta_xml, AnsiString('{0}'), AnsiString(UTF8Encode(FCreator)), [rfReplaceAll]);
    meta_xml := StringReplace(meta_xml, AnsiString('{1}'), AnsiString(UTF8Encode(FSubject)), [rfReplaceAll]);
    meta_xml := StringReplace(meta_xml, AnsiString('{2}'), AnsiString(UTF8Encode(FTitle)), [rfReplaceAll]);
    meta_xml := StringReplace(meta_xml, AnsiString('{3}'), AnsiString(current_time), [rfReplaceAll]);
    meta_xml := StringReplace(meta_xml, AnsiString('{4}'), AnsiString(UTF8Encode(FKeywords)), [rfReplaceAll]);
    meta_xml := StringReplace(meta_xml, AnsiString('{5}'), AnsiString(UTF8Encode(FProducer)), [rfReplaceAll]);
    meta_xml := StringReplace(meta_xml, AnsiString('{6}'), AnsiString(FFileID), [rfReplaceAll]);
    meta_xml := StringReplace(meta_xml, AnsiString('{7}'), AnsiString(FFileID), [rfReplaceAll]);
    // may be changed for another Pdf/A Compliance versions
    meta_xml := StringReplace(meta_xml, AnsiString('{8}'), AnsiString('2'), [rfReplaceAll]);
    meta_xml := StringReplace(meta_xml, AnsiString('{9}'), AnsiString('A'), [rfReplaceAll]);

    FMetaFileId := UpdateXRef();
    WriteLn(pdf, ObjNumber(FMetaFileId));
    WriteLn(pdf, '<< /Type /Metadata /Subtype /XML ');
    MemRes := TMemoryStream.Create;
    WriteLn(MemRes, meta_xml);
    MemRes.Position := 0;
    WritePDFStream(pdf, MemRes, FMetaFileId, false, FProtection, false, true, true);
  finally
    Res.Free;
  end;
end;

procedure TfrxPDFExport.AddColorProfile;
var
  FColorProfileStreamId: longint;
  Res : TResourceStream;
  MemRes: TMemoryStream;
begin
  // color profile stream
  FColorProfileStreamId := UpdateXRef;
  WriteLn(pdf, ObjNumber(FColorProfileStreamId));
  WriteLn(pdf, '<<');
  WriteLn(pdf, '/N 3');

  // get stream from resource and put it in PDF
  Res := TResourceStream.Create(hInstance, 'Profile', RT_RCDATA);
  try
    MemRes := TMemoryStream.Create;
    MemRes.LoadFromStream(Res);
    MemRes.Position := 0;
    WritePDFStream(pdf, MemRes, FColorProfileStreamId, FCompressed, FProtection, false, true, false);
  finally
    Res.Free;
  end;

  // color profile intent
  FColorProfileId := UpdateXRef;
  WriteLn(pdf, ObjNumber(FColorProfileId));
  WriteLn(pdf, '<<');
  WriteLn(pdf, '/Type /OutputIntent');
  WriteLn(pdf, '/S /GTS_PDFA1');
  WriteLn(pdf, '/OutputCondition (sRGB IEC61966-2.1)');
  WriteLn(pdf, '/OutputConditionIdentifier (sRGB IEC61966-2.1)');
  WriteLn(pdf, '/Info (sRGB IEC61966-2.1)');
  WriteLn(pdf, '/DestOutputProfile ' + ObjNumberRef(FColorProfileStreamId));
  WriteLn(pdf, '>>');
  WriteLn(pdf, 'endobj');
end;

procedure TfrxPDFExport.WritePDFStream(target: TStream; source: TMemoryStream;
  id: longint; compressed: Boolean; encrypted: Boolean;
  startingBrackets: Boolean; endingBrackets: Boolean; enableLength2: Boolean);
const
      CR:byte = 10;
var
    tempStream:   TMemoryStream;
begin
    if startingBrackets then
      Write(target, '<<');
    if enableLength2 then
      Write(target, '/Length ' + IntToStr(source.Size));
    if compressed then
    begin
      tempStream := TMemoryStream.Create;
      frxDeflateStream(source, tempStream, gzFastest);
      tempStream.Position := 0;
      if enableLength2 then
        Write(target, '/Length1 ' + IntToStr(tempStream.Size))
      else
        Write(target, '/Length ' + IntToStr(tempStream.Size));
      Write(target, '/Filter/FlateDecode');
    end
    else
      begin
        tempStream := source;
        Write(target, '/Length ' + IntToStr(tempStream.Size));
      end;
    if endingBrackets then
      WriteLn(target, '>>')
    else
      WriteLn(target, '');
    WriteLn(target, 'stream');
    if encrypted then
      CryptStream(tempStream, target, FEncKey, id)
    else
    begin
      target.CopyFrom(tempStream, tempStream.Size);
    end;
    target.Write (CR, 1);
    WriteLn(target, 'endstream');
    WriteLn(target, 'endobj');
    source.Free;
    if compressed then
      tempStream.Free;
end;

constructor TfrxPDFExport.Create(AOwner: TComponent);
begin
  inherited Create(AOwner);
  FPageAnnots := TMemoryStream.Create;
  FAnnots := TList.Create;
  FCompressed := True;
  FEmbedProt := True;
  FPrintOpt := False;
  FAuthor := 'FastReport';
  FSubject := 'FastReport PDF export';
  FBackground := False;
  FCreator := 'FastReport';
  FTags := True;
  FProtection := False;
  FUserPassword := '';
  FOwnerPassword := '';
  FProducer := '';
  FKeywords := '';
  FProtectionFlags := [ePrint, eModify, eCopy, eAnnot];
  FilterDesc := frxGet(8707);
  DefaultExt := frxGet(8708);
  FCreator := Application.Name;
  FPrintScaling := False;
  FFitWindow := False;
  FHideMenubar := False;
  FCenterWindow := False;
  FHideWindowUI := False;
  FHideToolbar := False;
  FSaveOriginalImages := True;

  FRootNumber := 0;
  FPagesNumber := 0;
  FInfoNumber := 0;
  FStartXRef := 0;

  FPages := TList.Create;
  FFonts := TList.Create;
  FPageFonts := TList.Create;
  FXRef := TStringList.Create;
  FPagesRef := TStringList.Create;
  FSubstitutedFonts := TStringList.Create;

  FMarginLeft := 0;
  FMarginWoBottom := 0;

  FEncKey := '';
  FOPass := '';
  FUPass := '';

  FEncBits := 0;

  FDivider := frxDrawText.DefPPI / frxDrawText.ScrPPI;
  FLastColor := clBlack;
  FLastColorResult := '0 0 0';

  FQuality := 95;
  FTransparency := False;

  FPdfA := False;
end;

destructor TfrxPDFExport.Destroy;
begin
  Clear;
  FPageAnnots.Free;
  FAnnots.Free;
  FFonts.Free;
  FPageFonts.Free;
  FXRef.Free;
  FPagesRef.Free;
  FPages.Free;
  FSubstitutedFonts.Free;
  inherited Destroy;
end;

class function TfrxPDFExport.GetDescription: String;
begin
  Result := frxResources.Get('PDFexport');
end;

function TfrxPDFExport.ShowModal: TModalResult;
var
  s: String;
begin
  if (FTitle = '') and Assigned(Report) then
    FTitle := Report.ReportOptions.Name;
  if not Assigned(Stream) then
  begin
    if Assigned(Report) then
      begin
        if Report.Preview <> nil then
          FOutline := TfrxPreview(Report.Preview).OutlineVisible
        else
          FOutline := Report.PreviewOptions.OutlineVisible;
      end
    else
      FOutline := True;
    with TfrxPDFExportDialog.Create(nil) do
    begin
      OpenCB.Visible := not SlaveExport;
      if OverwritePrompt then
        SaveDialog1.Options := SaveDialog1.Options + [ofOverwritePrompt];
      if SlaveExport then
        FOpenAfterExport := False;

      if (FileName = '') and (not SlaveExport) then
      begin
        s := ChangeFileExt(ExtractFileName(frxUnixPath2WinPath(Report.FileName)), SaveDialog1.DefaultExt);
        SaveDialog1.FileName := s;
      end
      else
        SaveDialog1.FileName := FileName;

      OpenCB.Checked := FOpenAfterExport;
      PDFACB.Checked := FPdfA;
      EmbeddedCB.Checked := FEmbedded;
      PrintOptCB.Checked := FPrintOpt;
      OutlineCB.Checked := FOutline;
      OutlineCB.Enabled := FOutline;
      BackgrCB.Checked := FBackground;
      Quality.Text := IntToStr(FQuality);

      if PageNumbers <> '' then
      begin
        PageNumbersE.Text := PageNumbers;
        PageNumbersRB.Checked := True;
      end;

      OwnPassE.Text := String(FOwnerPassword);
      UserPassE.Text := String(FUserPassword);
      PrintCB.Checked := ePrint in FProtectionFlags;
      CopyCB.Checked := eCopy in FProtectionFlags;
      ModCB.Checked := eModify in FProtectionFlags;
      AnnotCB.Checked := eAnnot in FProtectionFlags;

      TitleE.Text := FTitle;
      AuthorE.Text := FAuthor;
      SubjectE.Text := FSubject;
      KeywordsE.Text := FKeywords;
      CreatorE.Text := FCreator;
      ProducerE.Text := FProducer;

      PrintScalingCB.Checked := FPrintScaling;
      FitWindowCB.Checked := FFitWindow;
      HideMenubarCB.Checked := FHideMenubar;
      CenterWindowCB.Checked := FCenterWindow;
      HideWindowUICB.Checked := FHideWindowUI;
      HideToolbarCB.Checked := FHideToolbar;
      TransparentCB.Checked := FTransparency;

      Result := ShowModal;
      if Result = mrOk then
      begin
        FOwnerPassword := AnsiString(OwnPassE.Text);
        FUserPassword := AnsiString(UserPassE.Text);
        FProtectionFlags := [];
        if PrintCB.Checked then
          FProtectionFlags := FProtectionFlags + [ePrint];
        if CopyCB.Checked then
          FProtectionFlags := FProtectionFlags + [eCopy];
        if ModCB.Checked then
          FProtectionFlags := FProtectionFlags + [eModify];
        if AnnotCB.Checked then
          FProtectionFlags := FProtectionFlags + [eAnnot];
        SetProtectionFlags(FProtectionFlags);
        PageNumbers := '';
        CurPage := False;
        if CurPageRB.Checked then
          CurPage := True
        else if PageNumbersRB.Checked then
          PageNumbers := PageNumbersE.Text;

        FOpenAfterExport := OpenCB.Checked;
        FPdfA := PDFACB.Checked;
        FEmbedded := EmbeddedCB.Checked;
        FPrintOpt := PrintOptCB.Checked;
        FOutline := OutlineCB.Checked;
        FBackground := BackgrCB.Checked;
        FQuality := StrToInt(Quality.Text);

        FTitle := TitleE.Text;
        FAuthor := AuthorE.Text;
        FSubject := SubjectE.Text;
        FKeywords := KeywordsE.Text;
        FCreator := CreatorE.Text;
        FProducer := ProducerE.Text;

        FPrintScaling := PrintScalingCB.Checked;
        FFitWindow := FitWindowCB.Checked;
        FHideMenubar := HideMenubarCB.Checked;
        FCenterWindow := CenterWindowCB.Checked;
        FHideWindowUI := HideWindowUICB.Checked;
        FHideToolbar := HideToolbarCB.Checked;
        FTransparency := TransparentCB.Checked;

        if not SlaveExport then
        begin
          if DefaultPath <> '' then
            SaveDialog1.InitialDir := DefaultPath;
          if SaveDialog1.Execute then
            FileName := SaveDialog1.FileName
          else
            Result := mrCancel;
        end;
      end;
      Free;
    end;
  end else
    Result := mrOk;
end;

function TfrxPDFExport.Start: Boolean;
begin
  if SlaveExport and (FileName = '') then
  begin
    if Report.FileName <> '' then
      FileName := ChangeFileExt(GetTemporaryFolder + ExtractFileName(Report.FileName), frxGet(8708))
    else
      FileName := ChangeFileExt(GetTempFile, frxGet(8708))
  end;

  if (FileName <> '') or Assigned(Stream) then
  begin
    if (ExtractFilePath(FileName) = '') and (DefaultPath <> '') then
      FileName := DefaultPath + '\' + FileName;
    FProtection := (FOwnerPassword <> '') or (FUserPassword <> '');

    if FPdfA then
    begin
      FProtection := false;
      FEmbedded := true;
    end;

    if Assigned(Stream) then
      pdf := Stream
    else
      pdf := TFileStream.Create(FileName, fmCreate);
    Result := True;
    // start here
    Clear;
    FFileID := MD5String(GetID);
    if FProtection then
    begin
      PrepareKeys;
      FEmbedded := FEmbedProt or FEmbedded;
    end;

    if FOutline then
      FPreviewOutline := Report.PreviewPages.Outline;

    WriteLn(pdf, '%PDF-' + PDF_VER);
    // PDF/A unicode signature
    WriteLn(pdf, #37#226#227#207#211);
    UpdateXRef;
  end else
    Result := False;
end;

procedure TfrxPDFExport.ExportObject(Obj: TfrxComponent);
var v: TfrxView;
begin
  inherited;
  if (Obj is TfrxView) then
    begin
      v := TfrxView(Obj);
      if vsExport in v.Visibility then
        AddObject(v);
    end;
end;

procedure TfrxPDFExport.Finish;
var
  i: Integer;
  s: string;
  FInfoNumber, FRootNumber, FEncNumber: Longint;
  OutlineTree: TfrxPDFOutlineNode;
  pgN: TStringList;
  FOutlineObjId: Integer;

  function IsPageInRange(const PageN: Integer): Boolean;
  begin
    Result := (pgN.Count = 0) or (pgN.IndexOf(IntToStr(PageN + 1)) >= 0);
  end;

  { Converts TfrxCustomOutline to a tree of TfrxPDFOutlineNode nodes.
    The last argument represents the number of already added objects
    to FXRef. This value is needed to correctly assign object numbers
    to TfrxPDFOutlineNode nodes. }

  procedure PrepareOutline(Outline: TfrxCustomOutline; Node: TfrxPDFOutlineNode;
    ObjNum: Integer);
  var
    i: Integer;
    p: TfrxPDFOutlineNode;
    Prev: TfrxPDFOutlineNode;
    Text: string;
    Page, Top: Integer;
  begin
    Prev := nil;
    p := nil;

    for i := 0 to Outline.Count - 1 do
    begin
      Outline.GetItem(i, Text, Page, Top);
      if not IsPageInRange(Page) then
        Continue;

      p := TfrxPDFOutlineNode.Create;
      p.Title := Text;
      p.Dest := Page;
      p.Top := Top;
      p.Prev := Prev;

      Inc(ObjNum);
      p.Number := ObjNum;

      if Prev <> nil then
        Prev.Next := p
      else
        Node.First := p;

      Prev := p;
      p.Parent := Node;
      Outline.LevelDown(i);

      PrepareOutline(Outline, p, ObjNum);
      Inc(ObjNum, p.CountTree);

      Node.Count := Node.Count + 1;
      Node.CountTree := Node.CountTree + p.CountTree + 1;
      Outline.LevelUp;
    end;

    Node.Last := p;
  end;

  procedure WriteOutline(Node: TfrxPDFOutlineNode);
  var
    Page, y: Integer;
    Dest: string;
  begin
    { Actually, the following line of code does nothing:
      UpdateXRef returns a number that was predicted
      by PrepareOutline. }

    Node.Number := UpdateXRef;

    WriteLn(pdf, IntToStr(Node.Number) + ' 0 obj');
    WriteLn(pdf, '<<');
    WriteLn(pdf, '/Title ' + PrepareString(Node.Title, FEncKey, FProtection, Node.Number));
    WriteLn(pdf, '/Parent ' + ObjNumberRef(Node.Parent.Number));

    if Node.Prev <> nil then
      WriteLn(pdf, '/Prev ' + ObjNumberRef(Node.Prev.Number));

    if Node.Next <> nil then
      WriteLn(pdf, '/Next ' + ObjNumberRef(Node.Next.Number));

    if Node.First <> nil then
    begin
      WriteLn(pdf, '/First ' + ObjNumberRef(Node.First.Number));
      WriteLn(pdf, '/Last ' + ObjNumberRef(Node.Last.Number));
      WriteLn(pdf, '/Count ' + IntToStr(Node.Count));
    end;

    if IsPageInRange(Node.Dest) then
    begin
      if pgN.Count > 0 then
        Page := pgN.IndexOf(IntToStr(Node.Dest + 1))
      else
        Page := Node.Dest;
      if Page <> - 1 then
        begin
          y := Round(TfrxPDFPage(FPages[Page]).Height - Node.Top * PDF_DIVIDER);
          Dest := FPagesRef[Page];
          WriteLn(pdf, '/Dest [' + Dest + ' 0 R /XYZ 0 ' + IntToStr(y) + ' 0]');
        end
    end;

    WriteLn(pdf, '>>');
    WriteLn(pdf, 'endobj');

    if Node.First <> nil then
      WriteOutline(Node.First);

    if Node.Next <> nil then
      WriteOutline(Node.Next);
  end;

  procedure WriteAnnots;
  var
    i: Integer;
    annot: TfrxPDFAnnot;
  begin
    for i := 0 to FAnnots.Count - 1 do
    begin
      annot := TfrxPDFAnnot(FAnnots[i]);
      // fix xref position
      FXref[annot.Number - 1] := PrepXrefPos(pdf.Position);

      Writeln(pdf, ObjNumber(annot.Number));
      Writeln(pdf, '<<');
      Writeln(pdf, '/Type /Annot');
      Writeln(pdf, '/Subtype /Link');
      Writeln(pdf, '/Rect [' + annot.Rect + ']');

      if annot.Hyperlink <> '' then
      begin
        Writeln(pdf, '/BS << /W 0 >>');
        Writeln(pdf, '/A <<');
        if FProtection then
          Writeln(pdf, '/URI ' + '(' + CryptStr(Copy(annot.Hyperlink, 2, Length(annot.Hyperlink) - 2), FEncKey, FProtection, annot.Number) + ')')
        else
          Writeln(pdf, '/URI ' + annot.Hyperlink);
        Writeln(pdf, '/Type /Action');
        Writeln(pdf, '/S /URI');
        Writeln(pdf, '>>');
      end
      else
      begin
        Writeln(pdf, '/Border [16 16 0]');
        Writeln(pdf, '/Dest [' + FPagesRef[annot.DestPage] +
          ' 0 R /XYZ null ' + IntToStr(annot.DestY) + ' null]');
      end;

      Writeln(pdf, '>>');
      Writeln(pdf, 'endobj');
    end;
  end;

begin
  for i := 0 to FFonts.Count - 1 do
    WriteFont(TfrxPDFFont(FFonts[i]));

  FPagesNumber := 1;
  FXRef[0] := PrepXrefPos(pdf.Position);
  WriteLn(pdf, ObjNumber(FPagesNumber));
  WriteLn(pdf, '<<');
  WriteLn(pdf, '/Type /Pages');
  Write(pdf, '/Kids [');
  for i := 0 to FPagesRef.Count - 1 do
    Write(pdf, FPagesRef[i] + ' 0 R ');
  WriteLn(pdf, ']');
  WriteLn(pdf, '/Count ' + IntTOStr(FPagesRef.Count));
  WriteLn(pdf, '>>');
  WriteLn(pdf, 'endobj');

  // PDF/A
  if FPdfA then
  begin
    AddStructure;
    AddMetaData;
    AddColorProfile;
  end;

  FInfoNumber := UpdateXRef();
  WriteLn(pdf, ObjNumber(FInfoNumber));
  WriteLn(pdf, '<<');
  WriteLn(pdf, '/Title ' + PrepareString(FTitle, FEncKey, FProtection, FInfoNumber));
  WriteLn(pdf, '/Author ' + PrepareString(FAuthor, FEncKey, FProtection, FInfoNumber));
  WriteLn(pdf, '/Subject ' + PrepareString(FSubject, FEncKey, FProtection, FInfoNumber));
  {for i := 0 to FSubstitutedFonts.Count - 1 do
    FKeywords := FKeywords + FSubstitutedFonts[i] + ';';}
  WriteLn(pdf, '/Keywords ' + PrepareString(FKeywords, FEncKey, FProtection, FInfoNumber));
  WriteLn(pdf, '/Creator ' + PrepareString(FCreator, FEncKey, FProtection, FInfoNumber));
  WriteLn(pdf, '/Producer ' + PrepareString(FProducer, FEncKey, FProtection, FInfoNumber));
  s := 'D:' + FormatDateTime('yyyy', Now) + FormatDateTime('mm', Now) +
    FormatDateTime('dd', Now) + FormatDateTime('hh', Now) +
    FormatDateTime('nn', Now) + FormatDateTime('ss', Now);
  if FProtection then
  begin
    WriteLn(pdf, '/CreationDate ' + PrepareString(s, FEncKey, FProtection, FInfoNumber));
    WriteLn(pdf, '/ModDate ' + PrepareString(s, FEncKey, FProtection, FInfoNumber));
  end
  else
  begin
    WriteLn(pdf, '/CreationDate (' + s + ')');
    WriteLn(pdf, '/ModDate (' + s + ')');
  end;
  WriteLn(pdf, '>>');
  WriteLn(pdf, 'endobj');

  FEncNumber := 0; //remove warning
  if FProtection then
  begin
    FRootNumber := UpdateXRef;
    FEncNumber := FRootNumber;
    WriteLn(pdf, ObjNumber(FRootNumber));
    WriteLn(pdf, '<<');
    WriteLn(pdf, '/Filter /Standard' );
    WriteLn(pdf, '/V 2');
    WriteLn(pdf, '/R 3');
    WriteLn(pdf, '/Length 128');
    WriteLn(pdf, '/P ' + IntToStr(Integer(FEncBits)));
    WriteLn(pdf, '/O (' + EscapeSpecialChar(FOPass) + ')');
    WriteLn(pdf, '/U (' + EscapeSpecialChar(FUPass) + ')');
    WriteLn(pdf, '>>');
    WriteLn(pdf, 'endobj');
  end;

  { Write the document outline }

  OutlineTree := TfrxPDFOutlineNode.Create;
  pgN := TStringList.Create;
  FOutlineObjId := 0;

  if FOutline then
  begin
    frxParsePageNumbers(PageNumbers, pgN, Report.PreviewPages.Count);
    FPreviewOutline.LevelRoot;

    { PrepareOutline needs to know the exact number of objects
      that will be written before the first outline node object.
      The number of already written objects is FXRef.Count, and
      one object (/Type /Outlines) will be written before the first
      outline node. That's why PrepareOutline is given FXRef.Count + 1. }

    PrepareOutline(FPreviewOutline, OutlineTree, FXRef.Count + 1);
  end;

  if OutlineTree.CountTree > 0 then
  begin
    FOutlineObjId := UpdateXRef;
    OutlineTree.Number := FOutlineObjId;

    { It's important to write the /Outlines object first,
      because object numbers for outline nodes was calculated
      in assumption that /Outlines will be written first. }

    WriteLn(pdf, IntToStr(FOutlineObjId) + ' 0 obj');
    WriteLn(pdf, '<<');
    WriteLn(pdf, '/Type /Outlines');
    WriteLn(pdf, '/Count ' + IntToStr(OutlineTree.Count));
    WriteLn(pdf, '/First ' + ObjNumberRef(OutlineTree.First.Number));
    WriteLn(pdf, '/Last ' + ObjNumberRef(OutlineTree.Last.Number));
    WriteLn(pdf, '>>');
    WriteLn(pdf, 'endobj');

    { Write outline nodes }

    WriteOutline(OutlineTree.First);
  end;

  OutlineTree.Free;
  pgN.Free;

  { Write annots }
  if FAnnots.Count > 0 then
    WriteAnnots;

  { Write the catalog }

  FRootNumber := UpdateXRef;
  WriteLn(pdf, ObjNumber(FRootNumber));
  WriteLn(pdf, '<<');
  WriteLn(pdf, '/Type /Catalog');
  WriteLn(pdf, '/Version /' + PDF_VER);
  WriteLn(pdf, '/MarkInfo << /Marked true >>');
  WriteLn(pdf, '/Pages ' + ObjNumberRef(FPagesNumber));

  if FOutline then
    s := '/UseOutlines'
  else
    s := '/UseNone';

  WriteLn(pdf, '/PageMode ' + s);

  if FOutline then
    WriteLn(pdf, '/Outlines ' + ObjNumberRef(FOutlineObjId));

  if FPdfA then
  begin
    WriteLn(pdf, '/Metadata ' + ObjNumberRef(FMetaFileId));
    WriteLn(pdf, '/OutputIntents [ ' + ObjNumberRef(FColorProfileId) + ' ]');
    WriteLn(pdf, '/StructTreeRoot ' + ObjNumberRef(FStructId));
  end;

  WriteLn(pdf, '/ViewerPreferences <<');

  if FTitle <> '' then
    WriteLn(pdf, '/DisplayDocTitle true');
  if FHideToolbar then
    WriteLn(pdf, '/HideToolbar true');
  if FHideMenubar then
    WriteLn(pdf, '/HideMenubar true');
  if FHideWindowUI then
    WriteLn(pdf, '/HideWindowUI true');
  if FFitWindow then
    WriteLn(pdf, '/FitWindow true');
  if FCenterWindow then
    WriteLn(pdf, '/CenterWindow true');
  if not FPrintScaling then
    WriteLn(pdf, '/PrintScaling false');

  WriteLn(pdf, '>>');

  WriteLn(pdf, '>>');
  WriteLn(pdf, 'endobj');

  FStartXRef := pdf.Position;
  WriteLn(pdf, 'xref');
  WriteLn(pdf, '0 ' + IntToStr(FXRef.Count + 1));
  WriteLn(pdf, '0000000000 65535 f');
  for i := 0 to FXRef.Count - 1 do
    WriteLn(pdf, FXRef[i] + ' 00000 n');
  WriteLn(pdf, 'trailer');
  WriteLn(pdf, '<<');
  WriteLn(pdf, '/Size ' + IntToStr(FXRef.Count + 1));
  WriteLn(pdf, '/Root ' + ObjNumberRef(FRootNumber));
  WriteLn(pdf, '/Info ' + ObjNumberRef(FInfoNumber));
  WriteLn(pdf, '/ID [<' + FFileID + '><' + FFileID + '>]');
  if FProtection then
    WriteLn(pdf, '/Encrypt ' + IntToStr(FEncNumber) + ' 0 R');
  WriteLn(pdf, '>>');
  WriteLn(pdf, 'startxref');
  WriteLn(pdf, IntToStr(FStartXRef));
  WriteLn(pdf, '%%EOF');
  Clear;
  if not Assigned(Stream) then
    pdf.Free;
  if FOpenAfterExport and (not Assigned(Stream)) then
    //ShellExecute(GetDesktopWindow, 'open', PChar(FileName), nil, nil, SW_SHOW);
    OpenDocument(FileName);
end;

procedure TfrxPDFExport.DrawFrameLine(Color: TColor; FrameStyle: TfrxFrameStyle; FrameWidth: extended;
                          LeftBegin, TopBegin, LeftEnd, TopEnd: string);
begin
  Write(OutStream, GetPDFColor(Color) + ' RG'#13#10);
  WriteLn(OutStream, GetPDFDash(FrameStyle, FrameWidth));
  Write(OutStream, frFloat2Str(FrameWidth * PDF_DIVIDER) + ' w'#13#10);
  Write(OutStream, LeftBegin + ' ' + TopBegin + ' m'#13#10 + LeftEnd + ' ' + TopEnd + ' l'#13#10'S'#13#10);
end;

procedure TfrxPDFExport.StartPage(Page: TfrxReportPage; Index: Integer);
const
  mm2p: Double = 1.0 / 25.4 * 72; // millimeters to points
var Left, Top, Bottom, Right: extended;
begin
  SetLength(FUsedXObjects, 0);

  AddPage(Page);
  FWidth := Page.Width * PDF_DIVIDER;
  FHeight := Page.Height * PDF_DIVIDER;
  FMarginLeft := Page.LeftMargin * PDF_MARG_DIVIDER;
  FMarginTop := Page.TopMargin * PDF_MARG_DIVIDER;
  OutStream := TMemoryStream.Create;

  with Page do
    if Color <> clNone then
      Write(OutStream, PdfFillRect(LeftMargin * mm2p,
        BottomMargin * mm2p, FWidth - RightMargin * mm2p,
        FHeight - TopMargin * mm2p, Color));
    // Page frame here
  if (Page.Frame.Typ <> []) and (Page.Frame.Color <> clNone) then begin
    Left := Page.LeftMargin * fr01cm * PDF_DIVIDER;
    Top :=  (Page.Height - Page.TopMargin * fr01cm) * PDF_DIVIDER;
    Right := (Page.Width - Page.RightMargin * fr01cm) * PDF_DIVIDER;
    Bottom := Page.BottomMargin * fr01cm * PDF_DIVIDER;
    if ftLeft in Page.Frame.Typ then
      begin
        if (Page.Frame.LeftLine.Style <> fsDouble ) then
          DrawFrameLine(Page.Frame.LeftLine.Color, Page.Frame.LeftLine.Style,
                        Page.Frame.LeftLine.Width, frFloat2Str(Left), frFloat2Str(Top), frFloat2Str(Left), frFloat2Str(Bottom))
        else
          begin
            DrawFrameLine(Page.Frame.LeftLine.Color, Page.Frame.LeftLine.Style,
                          Page.Frame.LeftLine.Width,
                          frFloat2Str(Left - Page.Frame.LeftLine.Width * PDF_DIVIDER),
                          frFloat2Str(Top + Page.Frame.TopLine.Width * PDF_DIVIDER ),
                          frFloat2Str(Left - Page.Frame.LeftLine.Width * PDF_DIVIDER),
                          frFloat2Str(Bottom - Page.Frame.BottomLine.Width * PDF_DIVIDER));
            DrawFrameLine(Page.Frame.LeftLine.Color, Page.Frame.LeftLine.Style,
                          Page.Frame.LeftLine.Width,
                          frFloat2Str(Left + Page.Frame.LeftLine.Width * PDF_DIVIDER),
                          frFloat2Str(Top - Page.Frame.TopLine.Width * PDF_DIVIDER ),
                          frFloat2Str(Left + Page.Frame.LeftLine.Width * PDF_DIVIDER),
                          frFloat2Str(Bottom + Page.Frame.BottomLine.Width * PDF_DIVIDER));
          end;
      end;
      if ftRight in Page.Frame.Typ then
      begin
        if (Page.Frame.RightLine.Style <> fsDouble ) then
          DrawFrameLine(Page.Frame.RightLine.Color, Page.Frame.RightLine.Style,
                        Page.Frame.RightLine.Width, frFloat2Str(Right), frFloat2Str(Top), frFloat2Str(Right), frFloat2Str(Bottom))
        else
          begin
            DrawFrameLine(Page.Frame.RightLine.Color, Page.Frame.RightLine.Style,
                          Page.Frame.RightLine.Width,
                          frFloat2Str(Right - Page.Frame.RightLine.Width * PDF_DIVIDER),
                          frFloat2Str(Top - Page.Frame.TopLine.Width * PDF_DIVIDER ),
                          frFloat2Str(Right - Page.Frame.RightLine.Width * PDF_DIVIDER),
                          frFloat2Str(Bottom + Page.Frame.BottomLine.Width * PDF_DIVIDER));
            DrawFrameLine(Page.Frame.RightLine.Color, Page.Frame.RightLine.Style,
                          Page.Frame.RightLine.Width,
                          frFloat2Str(Right + Page.Frame.RightLine.Width * PDF_DIVIDER),
                          frFloat2Str(Top + Page.Frame.TopLine.Width * PDF_DIVIDER ),
                          frFloat2Str(Right + Page.Frame.RightLine.Width * PDF_DIVIDER),
                          frFloat2Str(Bottom - Page.Frame.BottomLine.Width * PDF_DIVIDER));
          end;
      end;
      if ftTop in Page.Frame.Typ then
      begin
        if (Page.Frame.TopLine.Style <> fsDouble) then
          DrawFrameLine(Page.Frame.TopLine.Color, Page.Frame.TopLine.Style,
                        Page.Frame.TopLine.Width, frFloat2Str(Left), frFloat2Str(Top), frFloat2Str(Right), frFloat2Str(Top))
        else
          begin
            DrawFrameLine(Page.Frame.TopLine.Color, Page.Frame.TopLine.Style,
                          Page.Frame.TopLine.Width,
                          frFloat2Str(Left - 1.5 * Page.Frame.LeftLine.Width * PDF_DIVIDER),
                          frFloat2Str(Top + Page.Frame.TopLine.Width * PDF_DIVIDER),
                          frFloat2Str(Right + 1.5 * Page.Frame.RightLine.Width * PDF_DIVIDER),
                          frFloat2Str(Top + Page.Frame.TopLine.Width * PDF_DIVIDER));
            DrawFrameLine(Page.Frame.TopLine.Color, Page.Frame.TopLine.Style,
                          Page.Frame.TopLine.Width,
                          frFloat2Str(Left + 0.5 * Page.Frame.LeftLine.Width * PDF_DIVIDER),
                          frFloat2Str(Top - Page.Frame.TopLine.Width * PDF_DIVIDER ),
                          frFloat2Str(Right - 0.5 * Page.Frame.RightLine.Width * PDF_DIVIDER),
                          frFloat2Str(Top - Page.Frame.TopLine.Width * PDF_DIVIDER));
          end;
      end;
      if ftBottom in Page.Frame.Typ then
      begin
        if (Page.Frame.BottomLine.Style <> fsDouble) then
          DrawFrameLine(Page.Frame.BottomLine.Color, Page.Frame.BottomLine.Style,
                        Page.Frame.BottomLine.Width, frFloat2Str(Left), frFloat2Str(Bottom), frFloat2Str(Right), frFloat2Str(Bottom))
        else
          begin
            DrawFrameLine(Page.Frame.BottomLine.Color, Page.Frame.BottomLine.Style,
                          Page.Frame.BottomLine.Width,
                          frFloat2Str(Left - 1.5 * Page.Frame.LeftLine.Width * PDF_DIVIDER),
                          frFloat2Str(Bottom - Page.Frame.BottomLine.Width * PDF_DIVIDER),
                          frFloat2Str(Right + 1.5 * Page.Frame.RightLine.Width * PDF_DIVIDER),
                          frFloat2Str(Bottom - Page.Frame.BottomLine.Width * PDF_DIVIDER));
            DrawFrameLine(Page.Frame.BottomLine.Color, Page.Frame.BottomLine.Style,
                          Page.Frame.BottomLine.Width,
                          frFloat2Str(Left + 0.5 * Page.Frame.LeftLine.Width * PDF_DIVIDER),
                          frFloat2Str(Bottom + Page.Frame.BottomLine.Width * PDF_DIVIDER ),
                          frFloat2Str(Right - 0.5 * Page.Frame.RightLine.Width * PDF_DIVIDER),
                          frFloat2Str(Bottom + Page.Frame.BottomLine.Width * PDF_DIVIDER));
          end;
      end;
    if Page.Color <> clNone then
      Write(OutStream, 'B'#13#10)
    else
      Write(OutStream, 'S'#13#10);
  end;
end;

procedure TfrxPDFExport.FinishPage(Page: TfrxReportPage; Index: Integer);
var
  FContentsPos, FPagePos: Integer;
  i: Integer;

  function GetLeft(const Left: Extended): Extended;
  begin
    Result := FMarginLeft + Left * PDF_DIVIDER
  end;

  function GetTop(const Top: Extended): Extended;
  begin
    Result := FHeight - FMarginTop - Top * PDF_DIVIDER
  end;

begin
// finish page
  FContentsPos := UpdateXRef();
  WriteLn(pdf, ObjNumber(FContentsPos));
  OutStream.Position := 0;
  WritePDFStream(pdf, OutStream, FContentsPos, FCompressed, FProtection, true, true, false);

  if FPageFonts.Count > 0 then
    for i := 0 to FPageFonts.Count - 1 do
      if not TfrxPDFFont(FPageFonts[i]).Saved then
      begin
        TfrxPDFFont(FPageFonts[i]).Reference := UpdateXRef;
        TfrxPDFFont(FPageFonts[i]).Saved := true;
      end;

  FPagePos := UpdateXRef();
  FPagesRef.Add(IntToStr(FPagePos));
  WriteLn(pdf, ObjNumber(FPagePos));
  WriteLn(pdf, '<<');
  WriteLn(pdf, '/Type /Page');
  WriteLn(pdf, '/Parent 1 0 R');
  WriteLn(pdf, '/MediaBox [0 0 ' + frFloat2Str(FWidth) +
    ' ' + frFloat2Str(FHeight) + ' ]');

  { Write the list of references
    to anchor objects }

  if FPageAnnots.Size > 0 then
  begin
    WriteLn(PDF, '/Annots [');
    FPageAnnots.Seek(0, soFromBeginning);
    PDF.CopyFrom(FPageAnnots, FPageAnnots.Size);
    WriteLn(PDF, ']');
    FPageAnnots.Clear;
  end;
  WriteLn(pdf, '/Group << /Type /Group /S /Transparency /CS /DeviceRGB >>');
  WriteLn(pdf, '/Resources <<');
  Write(pdf, '/Font << ');
  for i := 0 to FPageFonts.Count - 1 do
{$IFDEF Delphi12}
    Write(pdf, TfrxPDFFont(FPageFonts[i]).Name + AnsiString(' ' + ObjNumberRef(TfrxPDFFont(FPageFonts[i]).Reference) + ' '));
{$ELSE}
    Write(pdf, TfrxPDFFont(FPageFonts[i]).Name + ' ' + ObjNumberRef(TfrxPDFFont(FPageFonts[i]).Reference) + ' ');
{$ENDIF}
  WriteLn(pdf, '>>');
  if Length(FUsedXObjects) > 0 then
  begin
    Write(pdf, '/XObject << ');

    for i := 0 to High(FUsedXObjects) do
    begin
      Write(pdf, '/Im' + IntToStr(FUsedXObjects[i]) + ' ');
      Write(pdf, ObjNumberRef(FXObjects[FUsedXObjects[i]].ObjId) + ' ');
    end;

    Writeln(pdf, '>>');
  end;
  WriteLn(pdf, '/ProcSet [/PDF /Text /ImageC ]');
  WriteLn(pdf, '>>');
  WriteLn(pdf, '/Contents ' + ObjNumberRef(FContentsPos));
  WriteLn(pdf, '>>');
  WriteLn(pdf, 'endobj');
  { Clear piture cache }
  Self.ClearXObject;
end;

{ TfrxPDFOutlineNode }

constructor TfrxPDFOutlineNode.Create;
begin
  inherited;
  Dest := -1;
end;

destructor TfrxPDFOutlineNode.Destroy;
begin
  if Next <> nil then
    Next.Free;

  if First <> nil then
    First.Free;

  inherited Destroy;
end;

{ TfrxPDFFont }



function TfrxPDFFont.GetGlyphIndices(text: WideString; glyphs: PWord;
  widths: PInteger; rtl: boolean): integer;
var
  maxGlyphs: Integer;
  maxItems: Integer;
  i, j, len: Integer;
  tempGlyphs, g1, g2: PWord;
  tempWidths, w1, w2: PInteger;
  FName: String;
begin
  if text = '' then
    result := 0
  else
  begin
    maxGlyphs := Length(text) * 3;
    maxItems := Length(text) * 2;
    result := 0;
    g2 := glyphs;
    w2 := widths;
    tempGlyphs := GetMemory(SizeOf(Word) * maxGlyphs);
    tempWidths := GetMemory(SizeOf(Integer) * maxGlyphs);
    try
      FName := SourceFont.Name;
      if FName = 'default' then
        FName := Graphics.GetFontData(SourceFont.Handle).Name;
      if TFontStyle.fsBold in SourceFont.Style then FName := FName + ' Bold';
      if TFontStyle.fsItalic in SourceFont.Style then FName := FName + ' Italic';
      try
        len := TrueTypeTables.Item[FName].GetGlyphIndices(text, tempGlyphs, tempWidths, rtl, FComposedList);
      except
       FName := TrueTypeFont(TrueTypeTables.Fontcollection[0]).Names.Item[NameID_FullName];
       FName := RightStr(FName, Length(FName)-
         Pos(' - ', FName));
       len := TrueTypeTables.Item[FName].GetGlyphIndices(text, tempGlyphs, tempWidths, rtl, FComposedList);
      end;

      g1 := tempGlyphs;
      w1 := tempWidths;
      for j := 1 to len do
      begin
        g2^ := g1^;
        w2^ := w1^;
        Inc(g1);
        Inc(g2);
        Inc(w1);
        Inc(w2);
      end;
      Inc(result, len);
    finally
      FreeMemory(tempGlyphs);
      FreeMemory(tempWidths);
    end;
  end;
end;

constructor TfrxPDFFont.Create(Font: TFont);
var
  dpi:Integer;
begin
  SourceFont := TFont.Create;
  dpi := SourceFont.PixelsPerInch;
  SourceFont.Assign(Font);
  FDpiFX := 96 / dpi;
  PDFdpi_divider := 1 / (750 * FDpiFX);
  SourceFont.Size := Round(750 * FDpiFX);
  tempBitmap := TBitmap.Create;
  Widths := TList.Create;
  UsedAlphabet := TList.Create;
  UsedAlphabetUnicode := TList.Create;
  Saved := False;
  PackFont := True;
  FontDataSize := 0;
  FComposedList := TList.Create;
  FontData := TMemoryStream.Create;
  GetFontFile;
end;

destructor TfrxPDFFont.Destroy;
begin
  Cleanup;
  SourceFont.Free;
  Widths.Free;
  UsedAlphabet.Free;
  UsedAlphabetUnicode.Free;
  FComposedList.Free;
  FontData.Free;
  inherited Destroy;
end;

procedure TfrxPDFFont.Cleanup;
begin
  tempBitmap.Free;
  Widths.Clear;
  UsedAlphabet.Clear;
  UsedAlphabetUnicode.Clear;
  FComposedList.Clear;
  if FontData <> nil then
  begin
    FontData.Free;
    FontDataSize := 0;
    FontData := nil;
  end;
end;

procedure TfrxPDFFont.FillOutlineTextMetrix;
{$IFDEF NONWINFPC}
var
  i: Cardinal;
  FName: String;
begin
    FName := SourceFont.Name;
    if FName = 'default' then
      FName := GetFontData(SourceFont.Handle).Name;
    if TFontStyle.fsBold in SourceFont.Style  then FName := FName + ' Bold';
    if TFontStyle.fsItalic in SourceFont.Style then FName := FName + ' Italic';
   // try
      TrueTypeTables.Item[FName].GetOutlineTextMetrics(TextMetric);
  //  except
  //    TrueTypeTables.FamilyItem[SourceFont.Family].GetOutlineTextMetrics(TextMetric);
  //  end;
end;
{$ELSE}
var
  i: Cardinal;

begin
  tempBitmap.Canvas.Lock;
  try
    tempBitmap.Canvas.Font.Assign(SourceFont);
    i := GetOutlineTextMetrics(tempBitmap.Canvas.Handle, 0, nil);
    if i = 0 then
    begin
      tempBitmap.Canvas.Font.Name := 'Arial';
      i := GetOutlineTextMetrics(tempBitmap.Canvas.Handle, 0, nil);
    end;
    if i <> 0 then
    begin
      TextMetric := GetMemory(i);
      if TextMetric <> nil then
       GetOutlineTextMetrics(tempBitmap.Canvas.Handle, i, TextMetric);
    end;
  finally
    tempBitmap.Canvas.Unlock;
  end;
end;

{$ENDIF}


procedure TfrxPDFFont.GetFontFile;
{$IFDEF NONWINFPC}
var
  fn:string;
  SkipList: TList;

  function FontFileName(ASource:string):string;
  const
    cBold: array[0..1] of string = ('Bold', 'Medium');
    cReg: array[0..2] of string =('Regular','Book', 'Normal');
    cItalic: array[0..1] of string = ('Italic','Oblique');
  var
    fName, s, st, ssf, sty, sty1: string;
    I, L, j, k:Integer;
    IsBold, IsItalic, fBad: Boolean;
  begin
    Result := '';
    IsBold := False;
    IsItalic := False;
    ssf := ASource;
    if ssf = 'default' then
    begin
      ssf := GetFontData(SourceFont.Handle).Name;
      SourceFont.Name := ssf;
    end;

    IsBold := fsBold in SourceFont.Style;
    IsItalic := fsItalic in SourceFont.Style;
    for I := 0 to FSFonts.Count - 1 do
    begin
      L := UTF8Length(FSFonts[I]);
      st := FSFonts[I];
      fName := UTF8Copy(st, 1, UTF8Pos(':', st) - 1);
      if RightStr(fName,3) = 'pfb' then
        Continue;
      if FileIsSymlink(fName) then
        Continue;
      s := UTF8Copy(st, UTF8Pos(':',st) + 1,
        L - UTF8Pos(':', st));
      s := Trim(UTF8Copy(s,1, UTF8Pos(':',s)-1));
      sty := UTF8Copy(st, UTF8Pos('=', st) + 1, L);
      if UTF8Pos(Trim(s), ssf) > 0 then
      begin
        if IsBold and IsItalic then
        begin
          sty := StringReplace(sty, ' ','',[rfReplaceAll]);
          for j := 0 to Length(cBold) - 1 do
            for k := 0 to Length(cItalic) - 1 do
            begin
              sty1 := cBold[j] + cItalic[k];
              if UTF8Pos(sty1, sty) > 0 then
              begin
                Result := fName;
                Exit;
              end;
            end;
        end
        else if IsBold then
        begin
          fBad := False;
          for j := 0 to  Length(cBold) - 1 do
          begin
            if UTF8Pos(cBold[j], sty) > 0 then
            begin
              for k := 0 to Length(cItalic) - 1 do
                if  UTF8Pos(cItalic[k], sty) > 0 then
                begin
                  fBad := True;
                  Break;
                end;
              if fBad then
              begin
                fBad := False;
                Break;
              end
              else
              begin
                Result := fName;
                Exit;
              end;
            end;
          end;
        end
        else if IsItalic then
        begin
          fBad := False;
          for j := 0 to  Length(cItalic) - 1 do
          begin
            if UTF8Pos(cItalic[j], sty) > 0 then
            begin
              for k := 0 to Length(cBold) - 1 do
                if  UTF8Pos(cBold[k], sty) > 0 then
                begin
                  fBad := True;
                  Break;
                end;
              if fBad then
              begin
                fBad := False;
                Break;
              end
              else
              begin
                Result := fName;
                Exit;
              end;
            end;
          end;
        end
        else
        begin
          fBad := False;
          for j := 0 to Length(cReg) - 1 do
          begin
            if UTF8Pos(cReg[j], sty) > 0 then
            begin
              for k := 0 to Length(cBold) - 1 do
                if UTF8Pos(cBold[k], sty) > 0 then
                begin
                  fBad := True;
                  Break;
                end;
              if not fBad then
              for k := 0 to Length(cItalic) - 1 do
                if  UTF8Pos(cItalic[k], sty) > 0 then
                begin
                  fBad := True;
                  Break;
                end;
              if fBad then
              begin
                fBad := False;
                Break;
              end
              else
              begin
                Result := fName;
                Exit;
              end;
            end;
          end;
        end;
      end;
    end;
  end;

begin
  if ttf <> nil then Exit;
  
  while True do
  begin
    fn := FontFileName(SourceFont.Name);
    if fn <> '' then
      Break;
    SourceFont.Name := 'DejaVu Sans';
  end;

  begin
    FontData.LoadFromFile(fn);
    FontDataSize := FontData.Size;
    FontData.Position := 0;


    if Self.PackFont then
    begin
      FreeAndNil(Self.TrueTypeTables);
      TrueTypeTables := TrueTypeCollection.Create();
      TrueTypeTables.Initialize(FontData.Memory, FontData.Size);
      ttf := Self.TrueTypeTables.LoadFont( Self.SourceFont );
      if Assigned(ttf) then
        if ttf.SubstitutionName <> '' then
          FSubstitutedFont := ttf.SubstitutionName;
    end;
  end;
end;
{$ELSE}
var
  CollectionMode:   Cardinal;
  packed_font:      TByteArray;
begin
{$IFDEF DEBUG_WITH_FASTMM}
{$define FullDebugMode}
  ShowFastMMUsageTracker;
{$ENDIF}

  if ttf <> nil then Exit;

  packed_font := nil;
  tempBitmap.Canvas.Lock;
  try
    tempBitmap.Canvas.Font.Assign(SourceFont);
    CollectionMode := $66637474;
 {   if Assigned(FontData) then
      if FontDataSize > 0 then
      begin
        FreeMemory(FontData);
        FontDataSize := 0;
        FontData := nil;
      end; }
    FontDataSize := LazHelper.GetFontData(tempBitmap.Canvas.Handle, CollectionMode, 0, nil, 1);
    //if FontDataSize > 0 then
    begin
      if Cardinal(FontDataSize) = High(Cardinal) then
      begin
         CollectionMode := 0;
         FontDataSize := LazHelper.GetFontData(tempBitmap.Canvas.Handle, CollectionMode, 0, nil, 1);
         FontData.SetSize(FontDataSize);
         LazHelper.GetFontData(tempBitmap.Canvas.Handle, CollectionMode, 0, FontData.Memory, FontDataSize)
      end
      else
      begin
        FontData.SetSize(FontDataSize);
        LazHelper.GetFontData(tempBitmap.Canvas.Handle, CollectionMode, 0, FontData.Memory, FontDataSize)
      end;
      //FontData := GetMemory(FontDataSize);
      if FontData <> nil then
      begin
        if Self.PackFont then
        begin
          FreeAndNil(Self.TrueTypeTables);
          Self.TrueTypeTables := TrueTypeCollection.Create();
          Self.TrueTypeTables.Initialize( FontData.Memory, FontDataSize );
          ttf := Self.TrueTypeTables.LoadFont( Self.SourceFont );
          if Assigned(ttf) then
            if ttf.SubstitutionName <> '' then
              FSubstitutedFont := ttf.SubstitutionName;
          end;
        end
      else
        FontDataSize := 0;
    end;
  finally
    tempBitmap.Canvas.Unlock;
  end;
end;
{$ENDIF}

procedure TfrxPDFFont.PackTTFFont;
var
  packed_font: TByteArray;
  AUsedAlphabet: TList;
begin
  if (ttf <> nil) and Self.PackFont then
  begin
    AUsedAlphabet := TList.Create;
    AUsedAlphabet.Assign(UsedAlphabet, laOr, FComposedList);
    packed_font := Self.TrueTypeTables.PackFont( ttf , AUsedAlphabet );
    if packed_font <> nil then
    begin
      FontDataSize := Length(packed_font);
      FontData.Size := FontDataSize;
      FontData.Write(packed_font[0], FontDataSize);
      FontData.Position := 0;
      SetLength(packed_font, 0);
    end;
    AUsedAlphabet.Free;
  end;
end;

function TfrxPDFFont.RemapString(str: WideString; rtl: Boolean): WideString;
var
  maxGlyphs: Integer;
  g, g_: PWord;
  w, w_: PInteger;
  actualLength: Integer;
  i, j: Integer;
  c: Word;
  wc: WideChar;
begin
  LastRemappedStrWidth := 0;
  LastRemappedStrSpacesCount := 0;
  result := '';
  maxGlyphs := Length(str) * 3;
  g := GetMemory(SizeOf(Word) * maxGlyphs);
  w := GetMemory(SizeOf(Integer) * maxGlyphs);
  //tempBitmap.Canvas.Lock;
  try
    //tempBitmap.Canvas.Font.Assign(SourceFont);
    actualLength := GetGlyphIndices( str, g, w, rtl);
    g_ := g;
    w_ := w;
    for i := 0 to  actualLength - 1 do
    begin
      c := g_^;

      Inc(LastRemappedStrWidth, w_^);
      if actualLength = Length(str) then
      begin
        if rtl then
          j := actualLength - i
        else
          j := i + 1;
        if str[j] = ' ' then
          Inc(LastRemappedStrSpacesCount);
      end;

      if c = 667 then
        continue; { Arial Unicode $1f charcode }

      if UsedAlphabet.IndexOf(Pointer(c)) = -1 then
      begin
        UsedAlphabet.Add(Pointer(c));
        Widths.Add(Pointer(w_^));
        if actualLength = Length(str) then
        begin
          if rtl then
            j := actualLength - i
          else
            j := i + 1;
          UsedAlphabetUnicode.Add(Pointer(Word(str[j])));
        end
        else
         UsedAlphabetUnicode.Add(Pointer(TextMetric.otmTextMetrics.tmDefaultChar));
      end;
      wc := WideChar(c);
      result := result + wc;
      Inc(g_);
      Inc(w_);
    end;

  GetFontFile;
  finally
    FreeMemory(g);
    FreeMemory(w);
    //tempBitmap.Canvas.Unlock;
  end;
end;

function TfrxPDFFont.GetFontName: AnsiString;
var
  s: AnsiString;

  function HexEncode7F(Str: WideString): AnsiString;
  var
    AnStr: AnsiString;
    s: AnsiString;
    Index, Len: Integer;
  begin
    s := '';
    AnStr := AnsiString(Str);
    Len := Length(AnStr);
    Index := 0;
    while Index < Len do
    begin
      Index := Index + 1;
      if Byte(AnStr[Index]) > $7F then
        s := s + '#' + AnsiString(IntToHex(Byte(AnStr[Index]), 2))
      else
        s := s + AnsiString(AnStr[Index]);
    end;
    Result := s;
  end;

begin
  Result := SourceFont.Name;
  if Result = 'default' then
    Result := Graphics.GetFontData(SourceFont.Handle).Name;
  if (ttf <> nil) and (ttf.SubstitutionName <> '') then
      Result :=  AnsiString(ttf.FamilyName);
  Result := StringReplace(Result, AnsiString(' '), AnsiString('#20'), [rfReplaceAll]);
  Result := StringReplace(Result, AnsiString('('), AnsiString('#28'), [rfReplaceAll]);
  Result := StringReplace(Result, AnsiString(')'), AnsiString('#29'), [rfReplaceAll]);
  Result := StringReplace(Result, AnsiString('%'), AnsiString('#25'), [rfReplaceAll]);
  Result := StringReplace(Result, AnsiString('<'), AnsiString('#3C'), [rfReplaceAll]);
  Result := StringReplace(Result, AnsiString('>'), AnsiString('#3E'), [rfReplaceAll]);
  Result := StringReplace(Result, AnsiString('['), AnsiString('#5B'), [rfReplaceAll]);
  Result := StringReplace(Result, AnsiString(']'), AnsiString('#5D'), [rfReplaceAll]);
  Result := StringReplace(Result, AnsiString('{'), AnsiString('#7B'), [rfReplaceAll]);
  Result := StringReplace(Result, AnsiString('}'), AnsiString('#7D'), [rfReplaceAll]);
  Result := StringReplace(Result, AnsiString('/'), AnsiString('#2F'), [rfReplaceAll]);
  if frxPDFFontsNeedStyleSimulation.IndexOf(SourceFont.Name) = -1 then
  begin
    s := '';
    if fsBold in SourceFont.Style then
      s := s + 'Bold';
    if fsItalic in SourceFont.Style then
      s := s + 'Italic';
    if s <> '' then
      Result := Result + ',' + s;
  end;
  Result := HexEncode7F(Result);
end;

{ TfrxPDFExportDialog }

procedure TfrxPDFExportDialog.FormCreate(Sender: TObject);
begin
  Caption := frxGet(8700);
  OkB.Caption := frxGet(1);
  CancelB.Caption := frxGet(2);
  GroupPageRange.Caption := frxGet(7);
  AllRB.Caption := frxGet(3);
  CurPageRB.Caption := frxGet(4);
  PageNumbersRB.Caption := frxGet(5);
  DescrL.Caption := frxGet(9);
  GroupQuality.Caption := frxGet(8);
  PDFACB.Caption := frxGet(8701);
  EmbeddedCB.Caption := frxGet(8702);
  PrintOptCB.Caption := frxGet(8703);
  OutlineCB.Caption := frxGet(8704);
  BackgrCB.Caption := frxGet(8705);
  OpenCB.Caption := frxGet(8706);
  SaveDialog1.Filter := frxGet(8707);
  SaveDialog1.DefaultExt := frxGet(8708);

  ExportPage.Caption := frxGet(107);
  DocInfoGB.Caption := frxGet(8971);
  InfoPage.Caption := frxGet(8972);
  TitleL.Caption := frxGet(8973);
  AuthorL.Caption := frxGet(8974);
  SubjectL.Caption := frxGet(8975);
  KeywordsL.Caption := frxGet(8976);
  CreatorL.Caption := frxGet(8977);
  ProducerL.Caption := frxGet(8978);

  SecurityPage.Caption := frxGet(8962);
  SecGB.Caption := frxGet(8979);
  PermGB.Caption := frxGet(8980);
  OwnPassL.Caption := frxGet(8964);
  UserPassL.Caption := frxGet(8965);
  PrintCB.Caption := frxGet(8966);
  ModCB.Caption := frxGet(8967);
  CopyCB.Caption := frxGet(8968);
  AnnotCB.Caption := frxGet(8969);

  ViewerPage.Caption := frxGet(8981);
  ViewerGB.Caption := frxGet(8982);
  HideToolbarCB.Caption := frxGet(8983);
  HideMenubarCB.Caption := frxGet(8984);
  HideWindowUICB.Caption := frxGet(8985);
  FitWindowCB.Caption := frxGet(8986);
  CenterWindowCB.Caption := frxGet(8987);
  PrintScalingCB.Caption := frxGet(8988);

  if UseRightToLeftAlignment then
    FlipChildren(True);
end;

procedure TfrxPDFExportDialog.PageNumbersEChange(Sender: TObject);
begin
  PageNumbersRB.Checked := True;
end;

procedure TfrxPDFExportDialog.PageNumbersEKeyPress(Sender: TObject;
  var Key: Char);
begin
  case key of
    '0'..'9':;
    #8, '-', ',':;
  else
    key := #0;
  end;
end;

procedure TfrxPDFExportDialog.FormKeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
  if Key = VK_F1 then
    frxResources.Help(Self);
end;

{$IFDEF NONWINFPC}
procedure FillFSFonts;
const
  READ_BYTES = 2048;
var
  up:TProcessUTF8;
  ms:TMemoryStream;
  NumBytes: LongInt;
  BytesRead: LongInt;
begin
  FSFonts := TStringList.Create;
  ms := TMemoryStream.Create;
  up :=  TProcessUTF8.Create(nil);
  up.CommandLine:= FindDefaultExecutablePath('fc-list');
  up.Options:= up.Options + [poUsePipes];
  BytesRead := 0;
  up.Execute;
  while up.Running do
  begin
    ms.SetSize(BytesRead + READ_BYTES);
    NumBytes := up.Output.Read((ms.Memory + BytesRead)^, READ_BYTES);
    if NumBytes > 0 then
      Inc(BytesRead, NumBytes)
    else
      Sleep(100);
  end;
  repeat
    ms.SetSize(BytesRead + READ_BYTES);
    NumBytes := up.Output.Read((ms.Memory + BytesRead)^, READ_BYTES);
    if NumBytes > 0 then
       Inc(BytesRead, NumBytes);
  until NumBytes <= 0;
  ms.SetSize(BytesRead);
  FSFonts.LoadFromStream(ms);
  up.Free;
  ms.Free;
end;
{$ENDIF}

initialization
  pdfCS := TCriticalSection.Create;
  frxPDFFontsNeedStyleSimulation := TStringList.Create;
  frxPDFFontsNeedStyleSimulation.Add(#$FF2D#$FF33#$0020#$30B4#$30B7#$30C3#$30AF);
  frxPDFFontsNeedStyleSimulation.Add(#$FF2D#$FF33#$0020#$FF30#$30B4#$30B7#$30C3#$30AF);
  frxPDFFontsNeedStyleSimulation.Add(#$FF2D#$FF33#$0020#$660E#$671D);
  frxPDFFontsNeedStyleSimulation.Add(#$FF2D#$FF33#$0020#$FF30#$660E#$671D);
  frxPDFFontsNeedStyleSimulation.Add('MS UI Gothic');
  //frxPDFFontsNeedStyleSimulation.Add('Arial');
  frxPDFFontsNeedStyleSimulation.Add('Arial Black');
  //frxPDFFontsNeedStyleSimulation.Add('Arial Narrow');
  frxPDFFontsNeedStyleSimulation.Add('Arial Unicode MS');
  //frxPDFFontsNeedStyleSimulation.Add('Tahoma');
  {$IFDEF NONWINFPC}
  FillFSFonts;
  {$ENDIF}

finalization
  pdfCS.Free;
  frxPDFFontsNeedStyleSimulation.Free;
  {$IFDEF NONWINFPC}
  FSFonts.Free;
  {$ENDIF}
{$WARNINGS ON}



end.

unit frxTrueTypeLaz;

{$I frx.inc}

interface

uses
  Classes, SysUtils, Graphics;

type

  {$IFDEF FPC}
  TList = TFPList;
  {$ENDIF}


  TableEntry = packed record
      tag: Cardinal;
      checkSum: Cardinal;
      offset: Cardinal;
      length: Cardinal;
  end;

  { TrueTypeTable }

  TrueTypeTable = class
  private
    procedure ChangeEndian;
    function Get_TagLine: string;
    procedure Set_Length(AValue: Cardinal);
    procedure Set_Offset(AValue: Cardinal);
    function StoreTable(source_ptr: Pointer;
      destination_ptr: Pointer; output_offset: Cardinal): Cardinal;
  protected
    Entry: TableEntry;
    procedure Load(font: Pointer); virtual;
  public
    constructor Create(parent: TrueTypeTable); overload;
    constructor Create(Entry_Ptr: Pointer); overload;

    function Save(Font: Pointer; Offset: Cardinal): Cardinal; virtual;
    function StoreDescriptor(Descriptor_Ptr: Pointer): Pointer;

    property Length: Cardinal read Entry.length write Set_Length;
    property Offset: Cardinal read Entry.offset write Set_Offset;
    property CheckSum: Cardinal read Entry.checkSum write Entry.checkSum;
    property Tag: Cardinal read Entry.tag write Entry.tag;
    property TagLine: string read Get_TagLine;
  end;

type

  EncodingFormats = (ByteEncoding=0, HighByteMapping=2,
                     SegmentMapping=4, TrimmedTable=6);
  TSmallintArray = array of Smallint;
  TWordArray = array of Word;

  TSegmentMapping = packed record
    segCountX2: Word;
    searchRange: Word;
    entrySelector: Word;
    rangeShift: Word;
  end;

  Table_CMAP = packed record
    TableVersion: Word;
    NumSubTables: Word;
  end;

  Table_Encode = packed record
    Format: Word;
    Length: Word;
    Version: Word;
  end;

  Table_SUBMAP = packed record
    Platform: Word;
    EncodingID: Word;
    TableOffset: Cardinal;
  end;

  { CmapTableClass }

  CmapTableClass = class(TrueTypeTable)
  private
    endCount: TWordArray;
    GlyphIndexArray: TWordArray;
    idDelta: TSmallintArray;
    idRangeOffset: TWordArray;
    startCount: TWordArray;
    segment_count: Integer;
    function LoadCmapSegment(segment_ptr: Pointer;
      segment_count: Integer): TWordArray;
    function LoadSignedCmapSegment(segment_ptr: Pointer;
      segment_count: Integer): TSmallintArray;
  public
    constructor Create(src: TrueTypeTable);
    function GetGlyphIndex(ch: Word): Word;
    procedure LoadCmapTable(font: Pointer);
  end;

type

  FontHeader = packed record
    version: Cardinal;
    revision: Cardinal;
    checkSumAdjustment: Cardinal;
    magicNumber: Cardinal;
    flags: Word;
    unitsPerEm: Word;
    CreatedDateTime: UInt64;
    ModifiedDateTime: UInt64;
    xMin: Smallint;
    yMin: Smallint;
    xMax: Smallint;
    yMax: Smallint;
    macStyle: Word;
    lowestRecPPEM: Word;
    fontDirectionHint: Smallint;
    indexToLocFormat: Smallint;
    glyphDataFormat: Smallint;
  end;

  IndexToLoc = (IndexToLoc_LongType=1, IndexToLoc_ShortType=0);
  FontType = (FontType_TrueTypeCollection=$66637474,
    FontType_TrueTypeFontType=0, FontType_OpenTypeFontType);

  { FontHeaderClass }

  FontHeaderClass = class(TrueTypeTable)
  private
    font_header: FontHeader;
    procedure ChangeEndian;
    function get_indexToLocFormat: IndexToLoc;
  public
    //font_header: FontHeader;

    constructor Create(src: TrueTypeTable);
    procedure Load(font: Pointer); override;
    procedure SaveFontHeader(header_ptr: Pointer; CheckSum: Cardinal);

    property checkSumAdjustment: Cardinal write font_header.checkSumAdjustment;
    property Flags: Word read font_header.flags;

    property indexToLocFormat: IndexToLoc read get_indexToLocFormat;
    property unitsPerEm: Word read font_header.unitsPerEm;
  end;

type

  TIntegerList = TFPList;

  CompositeFlags = (ARG_1_AND_2_ARE_WORDS=$01,
                    ARGS_ARE_XY_VALUES=$02,
                    ROUND_XY_TO_GRID=$04,
                    WE_HAVE_A_SCALE=$08,
                    RESERVED=$10,
                    MORE_COMPONENTS=$20,
                    WE_HAVE_AN_X_AND_Y_SCALE=$40,
                    WE_HAVE_A_TWO_BY_TWO=$80,
                    WE_HAVE_INSTRUCTIONS=$100,
                    USE_MY_METRICS=$200,
                    OVERLAP_COMPOUND=$400,
                    SCALED_COMPONENT_OFFSET=$800,
                    UNSCALED_COMPONENT_OFFSET=$10000
                    );

  GlyphFlags = (ON_CURVE=$01,
                X_SHORT=$02,
                Y_SHORT=$04,
                REP=$08,
                X_POSITIVE=$10,
                X_SAME=$10,
                Y_POSITIVE=$20,
                Y_SAME=$20
                );

  CompositeGlyphHeader = packed record
    flags: Word;
    glyphIndex: Word;
  end;

  GlyphHeader = packed record
      numberOfContours: Smallint;
      xMin: Smallint;
      yMin: Smallint;
      xMax: Smallint;
      yMax: Smallint;
  end;

  { GlyphTableClass }

  GlyphTableClass = class(TrueTypeTable)
  private
    glyph_table_ptr: Pointer;
    function GetGlyphHeader(glyph_offset: Integer): GlyphHeader;
  public
    constructor Create(src: TrueTypeTable);
    destructor Destroy; override;

    function CheckGlyph(glyph_offset: Integer;
      glyph_size: Integer): TIntegerList;
    procedure Load(font: Pointer); override;
  end;

  GlyphPoint = class
  public
    end_of_contour: boolean;
    on_curve: boolean;
    x: Single;
    y: Single;
  end;

type

  FeatureRecord = packed record
    Feature: Word;
    FeatureTag: Cardinal;
  end;

  GSUB_Header = record
    Version: Cardinal;
    ScriptList: Word;
    FeatureList: Word;
    LookupList: Word;
  end;

  LangSysRecord = packed record
    LangSysTag: Cardinal;
    LangSys: Word;
  end;

  LangSysTable = packed record
    LookupOrder: Word;
    ReqFeatureIndex: Word;
    FeatureCount: Word;
  end;

  ScriptListRecord = packed record
    ScriptTag: Cardinal;
    ScriptOffset: Word;
  end;

  ScriptListTable = packed record
    CountScripts: Word;
  end;

  ScriptTable = packed record
    DefaultLangSys: Word;
    LangSysCount: Word;
  end;

  { GlyphSubstitutionClass }

  GlyphSubstitutionClass = class(TrueTypeTable)
  private
    header: GSUB_Header;
    procedure ChangeEndian;
  public
    constructor Create(src: TrueTypeTable);
    procedure Load(font: Pointer); override;
    function Save(font: Pointer; offset: Cardinal): Cardinal; override;
  end;

type

  HorizontalHeader = packed record
    Version: Cardinal;
    Ascender: Smallint;
    Descender: Smallint;
    LineGap: Smallint;
    advanceWidthMax: Word;
    minLeftSideBearing: Smallint;
    minRightSideBearing: Smallint;
    xMaxExtent: Smallint;
    caretSlopeRise: Smallint;
    caretSlopeRun: Smallint;
    reserved1: Smallint;
    reserved2: Smallint;
    reserved3: Smallint;
    reserved4: Smallint;
    reserved5: Smallint;
    metricDataFormat: Smallint;
    numberOfHMetrics: Word;
  end;

  { HorizontalHeaderClass }

  HorizontalHeaderClass = class(TrueTypeTable)
  private
    horizontal_header: HorizontalHeader;
    procedure ChangeEndian;
  public
    constructor Create(src: TrueTypeTable);
    procedure Load(font: Pointer); override;
    function Save(font: Pointer; offset: Cardinal): Cardinal; override;

    property Ascender: Smallint read horizontal_header.Ascender;
    property Descender: Smallint read horizontal_header.Descender;
    property LineGap: Smallint read horizontal_header.LineGap;
    property MaxWidth: Word read horizontal_header.advanceWidthMax;
    property NumberOfHMetrics: Word read horizontal_header.NumberOfHMetrics;
  end;

type

  longHorMetric = packed record
    advanceWidth: Word;
    lsb: Smallint;
  end;

  THorMetricArray = array of longHorMetric;

  { HorizontalMetrixClass }

  HorizontalMetrixClass = class(TrueTypeTable)
  private
    MetrixTable: THorMetricArray;
    function GetItem(index: Integer): longHorMetric;
  public
    NumberOfMetrics: Word;
    constructor Create(src: TrueTypeTable);
    procedure Load(font: Pointer); override;

    property Item[index: Integer]: longHorMetric read GetItem;
  end;

type

  TCardinalArray = array of Cardinal;

  { IndexToLocationClass }

  IndexToLocationClass = class(TrueTypeTable)
  private
    LongIndexToLocation: TCardinalArray;
    ShortIndexToLocation: TWordArray;
  public
    constructor Create(src: TrueTypeTable);
    function GetGlyph(i2l_idx: Word; font_header: FontHeaderClass;
      var location: Cardinal): Word;
    procedure LoadIndexToLocation(font: Pointer; font_header: FontHeaderClass);

    property Long: TCardinalArray read LongIndexToLocation;
    property Short: TWordArray read ShortIndexToLocation;
  end;

type

  CommonKerningHeader = packed record
    Coverage: Word;
    Length: Word;
    Version: Word;
  end;

  FormatZero = packed record
    entrySelector: Word;
    nPairs: Word;
    rangeShift: Word;
    searchRange: Word;
  end;

  FormatZeroPair = packed record
    key_value: Cardinal;
    value: Smallint;
  end;

  KerningTableHeader = packed record
    Version: Word;
    nTables: Word;
  end;

  { KerningSubtableClass }

  KerningSubtableClass = class
  private
    common_header: CommonKerningHeader;
    function get_Item(inx: Cardinal): Smallint;
  public
    constructor Create(kerning_table_ptr: Pointer);
    destructor Destroy; override;

    property Item[hash_value: Cardinal]: Smallint read get_Item;
    property Length: Word read common_header.Length;
  end;

  { KerningTableClass }

  KerningTableClass = class(TrueTypeTable)
  private
    kerning_table_header: KerningTableHeader;
    kerning_subtables_collection: TList;
    procedure ChangeEndian;
    function get_Item(idx: Cardinal): Smallint;
  public
    constructor Create(src: TrueTypeTable);
    destructor Destroy; override;
    procedure Load(font: Pointer); override;

    property Item[hash_value: Cardinal]: Smallint read get_Item;
  end;

type

  NameID = (NameID_CompatibleFull=$12, NameID_CopyrightNotice=0,
            NameID_Description=10, NameID_Designer=9,
            NameID_FamilyName=1, NameID_FullName=4, NameID_LicenseDescription=13,
            NameID_LicenseInfoURL=14, NameID_Manufacturer=8,
            NameID_PostscriptCID=20, NameID_PostscriptName=6,
            NameID_PreferredFamily=$10, NameID_PreferredSubFamily=$11,
            NameID_SampleText=$13, NameID_SubFamilyName=2,
            NameID_Trademark=7, NameID_UniqueID=3, NameID_URL_Designer=12,
            NameID_URL_Vendor=11, NameID_Version=5, NameID_WWS_Family_Name=$15,
            NameID_WWS_SubFamily_Name=$16);

  NamingTableHeader = packed record
    TableVersion: Word;
    Count: Word;
    stringOffset: Word;
  end;

  NamingRecord = packed record
    PlatformID: Word;
    EncodingID: Word;
    LanguageID: Word;
    NameID: Word;
    Length: Word;
    Offset: Word;
  end;

   { NameTableClass }

   NameTableClass = class(TrueTypeTable)
   private
     name_header: NamingTableHeader;
     namerecord_ptr: Pointer;
     string_storage_ptr: Pointer;
     procedure ChangeEndian;
     function  get_Item(Index: NameID): AnsiString;
   public
     constructor Create(src: TrueTypeTable);
     destructor Destroy; override;

     procedure Load(font: Pointer); override;
     property Item[Index: NameID]: AnsiString read get_Item;
   end;

type

  PostScript = packed record
    isFixedPitch: Cardinal;
    ItalicAngle: Integer;
    maxMemType1: Cardinal;
    maxMemType42: Cardinal;
    minMemType1: Cardinal;
    minMemType42: Cardinal;
    underlinePosition: Smallint;
    underlineThickness: Smallint;
    Version: Cardinal;
  end;

  { PostScriptClass }

  PostScriptClass = class(TrueTypeTable)
  private
    post_script: PostScript;
    procedure ChangeEndian;
  public
    constructor Create(src: TrueTypeTable);
    procedure Load(font: Pointer); override;
    function Save(font: Pointer; offset: Cardinal): Cardinal; override;

    property ItalicAngle: Integer read post_script.ItalicAngle;
  end;

type

  MaximumProfile = packed record
    maxComponentDepth: Word;
    maxComponentElements: Word;
    maxCompositeContours: Word;
    maxCompositePoints: Word;
    maxContours: Word;
    maxFunctionDefs: Word;
    maxInstructionDefs: Word;
    maxPoints: Word;
    maxSizeOfInstructions: Word;
    maxStackElements: Word;
    maxStorage: Word;
    maxTwilightPoints: Word;
    maxZones: Word;
    numGlyphs: Word;
    Version: Cardinal;
  end;

  { MaximumProfileClass }

  MaximumProfileClass = class(TrueTypeTable)
  private
    max_profile: MaximumProfile;
    procedure ChangeEndian;
  public
    constructor Create(src: TrueTypeTable);
    procedure Load(font: Pointer); override;
    function Save(font: Pointer; offset: Cardinal): Cardinal; override;
  end;

type

  TVendorID = packed array[0..3] of Byte;
  TPanoseArr   = packed array[0..9] of Byte;
  OS2WindowsMetrics = packed record
    Version: Word;         // version number 0x0004
    xAvgCharWidth: Smallint;
    usWeightClass: Word;
    usWidthClass: Word;
    fsType: Word;
    ySubscriptXSize: Smallint;
    ySubscriptYSize: Smallint;
    ySubscriptXOffset: Smallint;
    ySubscriptYOffset: Smallint;
    ySuperscriptXSize: Smallint;
    ySuperscriptYSize: Smallint;
    ySuperscriptXOffset: Smallint;
    ySuperscriptYOffset: Smallint;
    yStrikeoutSize: Smallint;
    yStrikeoutPosition: Smallint;
    sFamilyClass: Smallint;
    panose: TPanoseArr;
    ulUnicodeRange1: Cardinal;
    ulUnicodeRange2: Cardinal;
    ulUnicodeRange3: Cardinal;
    ulUnicodeRange4: Cardinal;
    achVendID: TVendorID;
    fsSelection: Word;
    usFirstCharIndex: Word;
    usLastCharIndex: Word;
    sTypoAscender: Smallint;
    sTypoDescender: Smallint;
    sTypoLineGap: Smallint;
    usWinAscent: Word;
    usWinDescent: Word;
    ulCodePageRange1: Cardinal;
    ulCodePageRange2: Cardinal;
    sxHeight: Smallint;
    sCapHeight: Smallint;
    usDefaultChar: Word;
    usBreakChar: Word;
    usMaxContext: Word;
  end;

  POS2WindowsMetrics = ^OS2WindowsMetrics;

  { OS2WindowsMetricsClass }

  OS2WindowsMetricsClass = class(TrueTypeTable)
  private
    win_metrix: POS2WindowsMetrics;
    function Get_AvgCharWidth: Smallint;
    function Get_Ascent: Word;
    function Get_BreakChar: Word;
    function Get_DefaultChar: Word;
    function Get_Descent: Word;
    function Get_FirstCharIndex: Word;
    function Get_LastCharIndex: Word;
    function Get_panose: TPanoseArr;
  public
    constructor Create(src: TrueTypeTable);
    destructor  Destroy; override;

    procedure Load(font: Pointer); override;
    function Save(font: Pointer; offset: Cardinal): Cardinal; override;

    property AvgCharWidth: Smallint read Get_AvgCharWidth;
    property Ascent: Word read Get_Ascent;
    property BreakChar: Word read Get_BreakChar;
    property DefaultChar: Word read Get_DefaultChar;
    property Descent: Word read Get_Descent;
    property FirstCharIndex: Word read Get_FirstCharIndex;
    property LastCharIndex: Word read Get_LastCharIndex;
    property Panose: TPanoseArr read Get_panose;
  end;

type

  { PreProgramClass }

  PreProgramClass = class(TrueTypeTable)
  private
    pre_program: Array of Byte;
  public
    constructor Create(src: TrueTypeTable);
    procedure Load(font: Pointer); override;
    function Save(font: Pointer; offset: Cardinal): Cardinal; override;
  end;

type

  PABC = ^TABC;
  _ABC = record
    abcA: Integer;
    abcB: LongWord;
    abcC: Integer;
  end;
  TABC = _ABC;
  ABC = _ABC;

  TPanose = packed record
    bFamilyType: Byte;
    bSerifStyle: Byte;
    bWeight: Byte;
    bProportion: Byte;
    bContrast: Byte;
    bStrokeVariation: Byte;
    bArmStyle: Byte;
    bLetterform: Byte;
    bMidline: Byte;
    bXHeight: Byte;
  end;

  PTextMetricA = ^TTextMetricA;
  PTextMetricW = ^TTextMetricW;
  PTextMetric = PTextMetricW;
  {$EXTERNALSYM tagTEXTMETRICA}
  tagTEXTMETRICA = record
    tmHeight: Longint;
    tmAscent: Longint;
    tmDescent: Longint;
    tmInternalLeading: Longint;
    tmExternalLeading: Longint;
    tmAveCharWidth: Longint;
    tmMaxCharWidth: Longint;
    tmWeight: Longint;
    tmOverhang: Longint;
    tmDigitizedAspectX: Longint;
    tmDigitizedAspectY: Longint;
    tmFirstChar: AnsiChar;
    tmLastChar: AnsiChar;
    tmDefaultChar: AnsiChar;
    tmBreakChar: AnsiChar;
    tmItalic: Byte;
    tmUnderlined: Byte;
    tmStruckOut: Byte;
    tmPitchAndFamily: Byte;
    tmCharSet: Byte;
  end;
  {$EXTERNALSYM tagTEXTMETRICW}
  tagTEXTMETRICW = record
    tmHeight: Longint;
    tmAscent: Longint;
    tmDescent: Longint;
    tmInternalLeading: Longint;
    tmExternalLeading: Longint;
    tmAveCharWidth: Longint;
    tmMaxCharWidth: Longint;
    tmWeight: Longint;
    tmOverhang: Longint;
    tmDigitizedAspectX: Longint;
    tmDigitizedAspectY: Longint;
    tmFirstChar: WideChar;
    tmLastChar: WideChar;
    tmDefaultChar: WideChar;
    tmBreakChar: WideChar;
    tmItalic: Byte;
    tmUnderlined: Byte;
    tmStruckOut: Byte;
    tmPitchAndFamily: Byte;
    tmCharSet: Byte;
  end;
  {$EXTERNALSYM tagTEXTMETRIC}
  tagTEXTMETRIC = tagTEXTMETRICW;
  TTextMetricA = tagTEXTMETRICA;
  TTextMetricW = tagTEXTMETRICW;
  TTextMetric = TTextMetricW;
  {$EXTERNALSYM TEXTMETRICA}
  TEXTMETRICA = tagTEXTMETRICA;
  {$EXTERNALSYM TEXTMETRICW}
  TEXTMETRICW = tagTEXTMETRICW;

  POutlineTextmetricA = ^TOutlineTextmetricA;
  POutlineTextmetricW = ^TOutlineTextmetricW;
  POutlineTextmetric = POutlineTextmetricW;
  {$EXTERNALSYM _OUTLINETEXTMETRICA}
  _OUTLINETEXTMETRICA = record
  public
    otmSize: LongWord;
    otmTextMetrics: TTextMetricA;
    otmFiller: Byte;
    otmPanoseNumber: TPanose;
    otmfsSelection: LongWord;
    otmfsType: LongWord;
    otmsCharSlopeRise: Integer;
    otmsCharSlopeRun: Integer;
    otmItalicAngle: Integer;
    otmEMSquare: LongWord;
    otmAscent: Integer;
    otmDescent: Integer;
    otmLineGap: LongWord;
    otmsCapEmHeight: LongWord;
    otmsXHeight: LongWord;
    otmrcFontBox: TRect;
    otmMacAscent: Integer;
    otmMacDescent: Integer;
    otmMacLineGap: LongWord;
    otmusMinimumPPEM: LongWord;
    otmptSubscriptSize: TPoint;
    otmptSubscriptOffset: TPoint;
    otmptSuperscriptSize: TPoint;
    otmptSuperscriptOffset: TPoint;
    otmsStrikeoutSize: LongWord;
    otmsStrikeoutPosition: Integer;
    otmsUnderscoreSize: Integer;
    otmsUnderscorePosition: Integer;
    otmpFamilyName: PAnsiChar; // Offset from the beginning of the structure
    otmpFaceName: PAnsiChar;   // Offset from the beginning of the structure
    otmpStyleName: PAnsiChar;  // Offset from the beginning of the structure
    otmpFullName: PAnsiChar;   // Offset from the beginning of the structure
  end;
  {$EXTERNALSYM _OUTLINETEXTMETRICW}
  _OUTLINETEXTMETRICW = record
  public
    otmSize: LongWord;
    otmTextMetrics: TTextMetricW;
    otmFiller: Byte;
    otmPanoseNumber: TPanose;
    otmfsSelection: LongWord;
    otmfsType: LongWord;
    otmsCharSlopeRise: Integer;
    otmsCharSlopeRun: Integer;
    otmItalicAngle: Integer;
    otmEMSquare: LongWord;
    otmAscent: Integer;
    otmDescent: Integer;
    otmLineGap: LongWord;
    otmsCapEmHeight: LongWord;
    otmsXHeight: LongWord;
    otmrcFontBox: TRect;
    otmMacAscent: Integer;
    otmMacDescent: Integer;
    otmMacLineGap: LongWord;
    otmusMinimumPPEM: LongWord;
    otmptSubscriptSize: TPoint;
    otmptSubscriptOffset: TPoint;
    otmptSuperscriptSize: TPoint;
    otmptSuperscriptOffset: TPoint;
    otmsStrikeoutSize: LongWord;
    otmsStrikeoutPosition: Integer;
    otmsUnderscoreSize: Integer;
    otmsUnderscorePosition: Integer;
    otmpFamilyName: PAnsiChar; // Offset from the beginning of the structure
    otmpFaceName: PAnsiChar;   // Offset from the beginning of the structure
    otmpStyleName: PAnsiChar;  // Offset from the beginning of the structure
    otmpFullName: PAnsiChar;   // Offset from the beginning of the structure
  end;
  {$EXTERNALSYM _OUTLINETEXTMETRIC}
  _OUTLINETEXTMETRIC = _OUTLINETEXTMETRICW;
  TOutlineTextmetricA = _OUTLINETEXTMETRICA;
  TOutlineTextmetricW = _OUTLINETEXTMETRICW;
  TOutlineTextmetric = TOutlineTextmetricW;
  {$EXTERNALSYM OUTLINETEXTMETRICA}
  OUTLINETEXTMETRICA = _OUTLINETEXTMETRICA;
  {$EXTERNALSYM OUTLINETEXTMETRICW}
  OUTLINETEXTMETRICW = _OUTLINETEXTMETRICW;
  {$EXTERNALSYM OUTLINETEXTMETRIC}
  OUTLINETEXTMETRIC = OUTLINETEXTMETRICW;

  ChecksumFaultAction = (IgnoreChecksum=0, ThrowException=1, Warn=2);

  TablesID = (CMAPID=$70616d63, ControlValueTableID=$20747663,
      DigitalSignatureID=$47495344, EmbedBitmapLocationID=$434c4245,
      EmbededBitmapDataID=$54444245, FontHeaderID=$64616568,
      FontProgramID=$6d677066, GlyphID=$66796c67,
      GlyphDefinitionID=$46454447, GlyphPositionID=$534f5047,
      GlyphSubstitutionID=$42555347, GridFittingAndScanConversionID=$70736167,
      HorizontakDeviceMetrixID=$786d6468, HorizontalHeaderID=$61656868,
      HorizontalMetrixID=$78746d68, IndexToLocationID=$61636f6c,
      JustificationID=$4654534a, KerningTableID=$6e72656b,
      LinearThresholdID=$4853544c, MaximumProfileID=$7078616d,
      NameIDN=$656d616e, OS2TableID=$322f534f, PCL5TableID=$544c4350,
      PostscriptID=$74736f70, PreProgramID=$70657270,
      VerticalDeviceMetrixID=$584d4456, VerticalMetrixID=$78746d76,
      VertivalMetrixHeaderID=$61656876);

  TByteArray = Array of Byte;
  TTagList = TList;

  TTableSortHelper = record
    Offset: Cardinal;
    TAG:    Cardinal;
  end;

  PTableSortHelper = ^TTableSortHelper;

  TableDirectory = packed record
    sfntversion: Cardinal;
    numTables: Word;
    searchRange: Word;
    entrySelector: Word;
    rangeShift: Word;
  end;

  { TrueTypeFont }

  TrueTypeFont = class
  private
    FIsLoaded: Boolean;
    beginfile_ptr: Pointer;
    cmap_table: CmapTableClass;
    dir: TableDirectory;
    font_header: FontHeaderClass;
    glyph_table: GlyphTableClass;
    gsub_table: GlyphSubstitutionClass;
    horizontal_header: HorizontalHeaderClass;
    horizontal_metrix_table: HorizontalMetrixClass;
    index_to_location: IndexToLocationClass;
    kerning_table: KerningTableClass;
    name_table: NameTableClass;
    postscript: PostScriptClass;
    profile: MaximumProfileClass;
    selector_ptr: Pointer;
    windows_metrix: OS2WindowsMetricsClass;
    preprogram_table: PreProgramClass;
    ListOfTables: TList;
    ListOfUsedGlyphs: TList;
    GlyphWidths: TIntegerList;
    Indices: TIntegerList;
    FSubstitutionName: String;
    procedure BuildGlyphIndexList(used_glyphs: TList;
      uniscribe: boolean; decompose: boolean;
      collate: boolean; use_kerning: boolean;
      var Indices: TIntegerlist; var GlyphWidths: TIntegerList;
      ComposedList: TList);
    function CalcTableChecksum(font: Pointer; entry: TrueTypeTable;
      debug: boolean): Cardinal;
    procedure CalculateFontChecksum(start_offset: Pointer; font_length: Cardinal);
    procedure ChangeEndian;
    procedure CheckTablesChecksum;
    function GetTablesOrder: TTagList;
    procedure LoadCoreTables;
    procedure LoadDescriptors(skip_array: TIntegerList);
    procedure ReorderGlyphTable(position: Pointer; uniscribe: boolean);
    procedure SaveDescriptors(position: Pointer);
    procedure set_UsedGlyphs(dict: TList);
    function get_GlyphWidth(glph: Integer): Cardinal;
    function get_Glyph(idx: Integer): Cardinal;
  public
    checksum_action: ChecksumFaultAction;
    constructor Create(bgn: Pointer; font: Pointer; action: ChecksumFaultAction);
    destructor Destroy; override;

    procedure AddCharacterToKeepList(ch: WideChar);
    procedure ParseSingleGlyph(idx: Word);
    function GetGlyphIndices(text: Widestring; glyphs: PWord; widths: PInteger;
      rtl: boolean; ComposedList: TList): Integer;
    procedure GetOutlineTextMetrics(var FTextMetric: OutlineTextMetric);
    function PackFont(translate_to: FontType; uniscribe: boolean): TByteArray;
    procedure PrepareFont(skip_list: TIntegerList);
    function GetFamilyName: String;

    property Names: NameTableClass read name_table;
    property UsedGlyphs: Tlist write set_UsedGlyphs;
    property Widths: TList read GlyphWidths;
    property Width[glph: Integer]: Cardinal read get_GlyphWidth;
    property Glyph[idx: Integer]: Cardinal read get_Glyph;
    property SubstitutionName: String read FSubstitutionName
      write FSubstitutionName;
    property FamilyName: String read GetFamilyName;
  end;


type

  TFontCollection = TList;
  TTCollectionHeader = packed record
    TTCTag: Cardinal;
    Version: Cardinal;
    numFonts: Cardinal;
  end;
  PTCollectionHeader = ^TTCollectionHeader;

  { TrueTypeCollection }

  TrueTypeCollection = class
  private
    fonts_collection: TFontCollection;
    function get_FontCollection: TFontCollection;
    function get_Item(FamilyName: string): TrueTypeFont;
  public
    constructor Create;
    destructor Destroy; override;

    procedure Initialize(FD: PAnsiChar; FontDataSize: Longint);
    function LoadFont( font: Tfont) : TrueTypeFont;
    function PackFont( ttf: TrueTypeFont; UsedAlphabet: TList) : TByteArray;

    property FontCollection: TFontCollection read get_FontCollection;
    property Item[FamilyName: string]: TrueTypeFont read get_Item;
  end;

const
  // You may put national font names here
  // but they should be represented in Unicode in form of 32 bit numbers
    Elements =12;
    Substitutes  : array  [1..Elements] of WideString = (
{
      'ＭＳ ゴシック',        'MS Gothic',
      'ＭＳ Ｐゴシック',     'MS PGothic',
      'ＭＳ 明朝',              'MS Mincho',
      'ＭＳ Ｐ明朝',           'MS PMincho',
      'メイリオ',               'Meiryo',
}
      #$FF2D#$FF33#$0020#$30B4#$30B7#$30C3#$30AF,
        'MS Gothic',
      #$FF2D#$FF33#$0020#$FF30#$30B4#$30B7#$30C3#$30AF,
        'MS PGothic',
      #$FF2D#$FF33#$0020#$660E#$671D,
        'MS Mincho',
      #$FF2D#$FF33#$0020#$FF30#$660E#$671D,
        'MS PMincho',
      #$30E1#$30A4#$30EA#$30AA,
        'Meiryo',
      'Tahoma Bold',
        'Tahoma Negreta'
    );




implementation

uses
  LConvEncoding, LazUTF8;

function TestName(NFont, Nm: string; AIsBold, AIsItalic:Boolean):Boolean;
const
   cBold: array[0..1] of string = ('Bold', 'Medium');
   cItalic: array[0..1] of string = ('Italic','Oblique');
var
  s:string;
  j,k:Integer;
begin
  Result := False;
  if AIsBold and AIsItalic then
  begin
    for j := 0 to Length(cBold) - 1 do
      for k := 0 to Length(cItalic) - 1 do
      begin
        s := NFont + ' ' + cBold[j] + ' ' + cItalic[k];
        if s = Nm then
        begin
          Result := True;
          Exit;
        end;
      end;
  end;
  if AIsBold then
  begin
    for j := 0 to  Length(cBold) - 1 do
    begin
      s := NFont + ' ' + cBold[j];
      if s = Nm then
      begin
        Result := True;
        Exit;
      end;
    end;
  end;
  if AIsItalic then
  begin
    for j := 0 to  Length(cItalic) - 1 do
    begin
      s := NFont + ' ' + cItalic[j];
      if s = Nm then
      begin
        Result := True;
        Exit;
      end;
    end;
  end;
  if NFont = Nm then
    Result := True;
end;

{ TrueTypeCollection }

function TrueTypeCollection.get_FontCollection: TFontCollection;
begin
  Result := fonts_collection;
end;

function TrueTypeCollection.get_Item(FamilyName: string): TrueTypeFont;
var
  font: TrueTypeFont;
  nt: NameTableClass;
  s,s1 : String;
  i:  Integer;
  fb, fi: Boolean;
begin
  fb := False;
  fi := False;
  Result := nil;

  if Pos(' Bold Italic', FamilyName) > 0 then
  begin
   s1 := LeftStr(FamilyName, Pos(' Bold Italic', FamilyName) - 1);
   fb := True; fi := True;
  end
  else if Pos(' Bold', FamilyName) > 0 then
  begin
    s1 := LeftStr(FamilyName, Pos(' Bold', FamilyName) - 1);
    fb := True;
  end
  else if Pos(' Italic', FamilyName) > 0 then
  begin
    s1 := LeftStr(FamilyName, Pos(' Italic', FamilyName) - 1);
    fi := True;
  end
  else
    s1 := FamilyName;

  for i := 0 to fonts_collection.Count - 1 do
  begin
    font := TrueTypeFont(fonts_collection[i]);
    nt := font.Names;
    s := nt.Item[NameID_FullName{NameID_UniqueID}];
    if TestName(s1,s, fb, fi) then
    begin
      Result := font;
      break
    end;
  end;
  if  Result = nil then raise Exception.Create('Font not found in collection');
end;

constructor TrueTypeCollection.Create;
begin
  self.fonts_collection := TFontCollection.Create;
end;

destructor TrueTypeCollection.Destroy;
var
  font: TrueTypeFont;
  i:  Integer;
begin
  for i := 0 to fonts_collection.Count - 1 do
  begin
    font := TrueTypeFont(fonts_collection[i]);
    font.Free;
  end;
  fonts_collection.Free;
  inherited Destroy;
end;

procedure TrueTypeCollection.Initialize(FD: PAnsiChar; FontDataSize: Longint);
var
  CollectionMode:   FontType;
  i: Cardinal;
  f: TrueTypeFont;
  pch: ^TTCollectionHeader;
  ch: TTCollectionHeader;
  subfont_table: ^Cardinal;
  subfont_idx: Cardinal;
  subfont_ptr: Pointer;
begin
  if (FD[0] = AnsiChar(0)) and (FD[1] = AnsiChar(1)) and (FD[2] = AnsiChar(0)) and (FD[3] = AnsiChar(0)) then
    CollectionMode := FontType_TrueTypeFontType
  else if (FD[0] = 't') and (FD[1] = 't') and (FD[2] = 'c') and (FD[3] = 'f') then
    CollectionMode := FontType_TrueTypeCollection
  else if (FD[0] = 'O') and (FD[1] = 'T') and (FD[2] = 'T') and (FD[3] = 'O') then
    CollectionMode := FontType_OpenTypeFontType
  else
    raise Exception.Create('TrueType font format error');

  if (CollectionMode = FontType_TrueTypeFontType) then
  begin
    f := TrueTypeFont.Create( Pointer(FD), Pointer(FD), Warn);
    self.fonts_collection.Add( f )
  end else if (CollectionMode = FontType_TrueTypeCollection) then
  begin
      pch := Pointer(FD);
      ch.TTCTag := SwapEndian(pch.TTCTag);
      ch.Version := SwapEndian(pch.Version);
      ch.numFonts :=  SwapEndian(pch.numFonts);
      case ch.Version of
      $10000: subfont_table :=  Pointer(pch) + 12 ; // Version 1
      $20000: subfont_table := Pointer(pch) + 12 ; // Version 2
      else raise Exception.Create('Unknown font collection version');
      end;

      i := 0;
      while i < ch.numFonts do
      begin
          subfont_idx := SwapEndian( subfont_table^ );
          subfont_ptr :=  FD + subfont_idx;
          f := TrueTypeFont.Create(FD, subfont_ptr, Warn);
          self.fonts_collection.Add( f );
          inc(i);
          inc( subfont_table, 1)
      end
  end
end;

function TrueTypeCollection.LoadFont(font: Tfont): TrueTypeFont;
var
  i:            Integer;
  skip_list:    TList;
  Transform:    WideString;
  Name:         WideString;
  s:            WideString;
  ttf:          TrueTypeFont;
  substituted:  Boolean;
begin
  Result := nil;
  if (self.fonts_collection.Count = 0) then
    Exit;
  skip_list := TList.Create;
  skip_list.Add( Pointer(TablesID.EmbedBitmapLocationID));
  skip_list.Add( Pointer(TablesID.EmbededBitmapDataID));
  skip_list.Add( Pointer(TablesID.HorizontakDeviceMetrixID));
  skip_list.Add( Pointer(TablesID.VerticalDeviceMetrixID));
  skip_list.Add( Pointer(TablesID.DigitalSignatureID));

  Name := font.Name;
  if Name = 'default' then
    Name := GetFontData(font.Handle).Name;
  i := 1;
  substituted := false;
  while i <= ((High(Substitutes)-Low(Substitutes)) ) do
  begin
    Transform := UTF8Encode(Substitutes[i]);
    if Transform = Name then
    begin
      Name := Substitutes[i+1];
      substituted := true;
      break;
    end;
    i := i + 2;
  end;

  {if substituted = False then begin
    if fsBold in font.Style   then Name := Name + ' Bold';
    if fsItalic in font.Style then Name := Name + ' Italic';
  end;}

  for i := 0 to Self.fonts_collection.Count - 1 do
  begin
    ttf := TrueTypeFont(Self.fonts_collection[i]);
    ttf.PrepareFont( skip_list );
    s := ttf.Names.Item[NameID_FullName];
    if not substituted then
    begin
      if TestName(Name, s, fsBold in font.Style, fsItalic in font.Style) then
      begin
        Result := ttf;
        Break;
      end;
    end
    else
    if s = Name then
    begin
      Result := ttf;
      break;
    end;
  end;
  if (Result = nil) and (Self.fonts_collection.Count > 0)  then
  begin
    TrueTypeFont(Self.fonts_collection[0]).SubstitutionName := Name + ' - ' + TrueTypeFont(Self.fonts_collection[0]).Names.Item[NameID_FullName];
    Result := TrueTypeFont(Self.fonts_collection[0]);
  end;

  skip_list.Free;
end;

function TrueTypeCollection.PackFont(ttf: TrueTypeFont; UsedAlphabet: TList
  ): TByteArray;
var
  j:          Integer;
  ch:         WideChar;
begin
  begin
    for j := 0 to UsedAlphabet.Count - 1 do
    begin
      ch := WideChar(UsedAlphabet[j]);
      ttf.AddCharacterToKeepList(ch);
    end;
    Result := ttf.PackFont(FontType_TrueTypeFontType, True );
  end;
end;

{ TrueTypeFont }

procedure TrueTypeFont.BuildGlyphIndexList(used_glyphs: TList;
  uniscribe: boolean; decompose: boolean; collate: boolean;
  use_kerning: boolean; var Indices: TIntegerlist;
  var GlyphWidths: TIntegerList; ComposedList: TList);
var
    location: Cardinal;
    composed_idx: Word;
    i, j, length, GlyphWidth: Integer;
    key, idx, next_idx: Word;
    hash_index: Cardinal;
    composed_indexes: TIntegerlist;
    new_key, kerning: Smallint;
begin
    Indices := TIntegerList.Create;
    GlyphWidths := TIntegerList.Create;
    i := 0;
    while ((i < used_glyphs.Count)) do
    begin
        key := Word(used_glyphs[i]);
        if uniscribe then idx := key else idx := self.cmap_table.GetGlyphIndex(key);
//            if (collate) then self.ListOfUsedGlyphs[key] := idx;
        length := self.index_to_location.GetGlyph(idx, self.font_header, location);
        if (length <> 0) then
        begin
          GlyphWidth := 0;
          composed_idx := $FFFF;

          if (not collate or (Indices.IndexOf(Pointer(idx)) = -1)) then
          begin
            //if composed_idx = $FFFF then
              Indices.Add( Pointer(idx));
            GlyphWidth := ((self.horizontal_metrix_table.Item[idx].advanceWidth * $3e8) div self.font_header.unitsPerEm);
            if (use_kerning and ((i < (used_glyphs.Count - 1)) and (self.kerning_table <> nil))) then
            begin
              new_key := Word(used_glyphs[i + 1]);
              if uniscribe then next_idx := new_key else next_idx :=  self.cmap_table.GetGlyphIndex(new_key);
              hash_index := Cardinal(idx or (next_idx shl $10));
              kerning := self.kerning_table.Item[hash_index];
              inc(GlyphWidth, ((kerning * $3e8) div self.font_header.unitsPerEm))
            end;
            GlyphWidths.Add(Pointer(GlyphWidth));
          end;

          composed_indexes := self.glyph_table.CheckGlyph(Cardinal(location), length);
          for j := 0 to composed_indexes.Count - 1 do
          begin
            composed_idx := Word(composed_indexes[j]);
            new_key := Indices.IndexOf(Pointer(composed_idx));
            if (not collate or (decompose and (new_key = -1))) then
            begin
              if ComposedList <> nil then
              begin
                if ComposedList.IndexOf(Pointer(composed_idx)) = -1 then
                  ComposedList.Add(Pointer(composed_idx))
              end
              else
                Indices.Add( Pointer(composed_idx));
              //GlyphWidth := ((self.horizontal_metrix_table.Item[composed_idx].advanceWidth * $3e8) div self.font_header.unitsPerEm);
//                if (use_kerning and ((i < (used_glyphs.Count - 1)) and (self.kerning_table <> nil))) then
//                begin
//                  new_key := Word(used_glyphs[i + 1]);
//                  if uniscribe then next_idx := new_key else next_idx :=  self.cmap_table.GetGlyphIndex(new_key);
//                  hash_index := Cardinal(composed_idx or (next_idx shl $10));
//                  kerning := self.kerning_table.Item[hash_index];
//                  inc(GlyphWidth, ((kerning * $3e8) div self.font_header.unitsPerEm))
//                end;
            //GlyphWidths.Add(Pointer(GlyphWidth))
            end;
          end;

        end
        else
        begin
          new_key := Indices.IndexOf(Pointer(idx));
          if ((key = $20) and (not collate or (new_key = -1))) then
          begin
            Indices.Add(Pointer(idx));
            j := (self.windows_metrix.AvgCharWidth * $3e8) div self.font_header.unitsPerEm;
            GlyphWidths.Add(Pointer(j))
          end;
        end;
        inc(i)
    end;
    used_glyphs.Free;
end;

function TrueTypeFont.CalcTableChecksum(font: Pointer; entry: TrueTypeTable;
  debug: boolean): Cardinal;
var
  Sum, Length, i: LongWord;
  Temp: ^LongWord;
  test: LongWord;
begin
  Sum := 0;
  Length := entry.length div 4;
  Temp := font + entry.offset ;
  i := 0;
  while ((i < Length)) do
  begin
      inc( Sum, SwapEndian( Temp^ ));
      Inc( Temp, 1 );
      Inc(i, 1)
  end;

  if entry.length mod 4 <> 0 then
  begin
    i := i*4;
    Test := $ffffffff;
    if i + 1 = entry.length then Test:= $ff000000;
    if i + 2 = entry.length then Test:= $ffff0000;
    if i + 3 = entry.length then Test:= $ffffff00;
    inc( Sum, (Test and SwapEndian( Temp^ )) );
  end;
  Result := Sum;
end;

procedure TrueTypeFont.CalculateFontChecksum(start_offset: Pointer;
  font_length: Cardinal);
var
  Sum, Length, i: LongWord;
  Temp: ^LongWord;
begin
    Sum := 0;
    length := font_length div 4;
    Temp := start_offset;
    i := 0;
    while ((i < length)) do
    begin
        Inc(Sum, SwapEndian( Temp^ ));
        Inc( Temp );
        Inc(i, 1)
    end;
    Sum := ($b1b0afba - Sum);
    font_header.SaveFontHeader(beginfile_ptr, Sum)
end;

procedure TrueTypeFont.ChangeEndian;
begin
  dir.sfntversion := SwapEndian(dir.sfntversion);
  dir.numTables := SwapEndian(dir.numTables);
  dir.searchRange := SwapEndian(dir.searchRange);
  dir.entrySelector := SwapEndian(dir.entrySelector);
  dir.rangeShift := SwapEndian(dir.rangeShift)
end;

procedure TrueTypeFont.CheckTablesChecksum;
var
  entry: TrueTypeTable;
  checksum: Cardinal;
  i:  Integer;
begin
  if (checksum_action <> IgnoreChecksum) then
    for i := 0 to ListOfTables.Count - 1 do
    try
      entry := ListOfTables.Items[i];
      checksum := CalcTableChecksum(beginfile_ptr, entry, false);
      if ( checksum <> entry.checkSum) then
        raise Exception.Create( String('Table ID "' + entry.TAGLINE + '" checksum error.' + IntToStr(checksum) + ' ' + IntToStr(entry.checkSum)))
      except
        on ex: Exception do
        begin
            if (checksum_action = ThrowException) then
                raise ex;
         //   if (Windows.MessageBox(GetDesktopWindow, PChar(ex.Message), PChar('Font table checksum error'), MB_YESNO) = 0) then
         //       raise ex
        end
      end
end;

function CompareOffsets(P1, P2: Pointer): Integer;
var
  V1, V2: Cardinal;
begin
  V1 := PTableSortHelper(P1).Offset;
  V2 := PTableSortHelper(P2).Offset;
  if V1 = V2 then begin
    Result :=  0;
  end else if V1 > V2 then begin
    Result :=  1;
  end else begin
    Result := -1;
  end;
end;

function TrueTypeFont.GetTablesOrder: TTagList;
var
  entry: TrueTypeTable;
  indexed_tags: TList;
  tables_positions: TList;
  i: Integer;
  helper: array[0..40] of TTableSortHelper;
  t: PTableSortHelper;
begin
  tables_positions := TList.Create;
  for i := 0 to ListOfTables.Count - 1 do
  begin
    entry := ListOfTables[i];
    helper[i].Offset := entry.offset;
    helper[i].Tag    := entry.tag;
    tables_positions.Add( @helper[i]);
  end;

  tables_positions.Sort(CompareOffsets);

  indexed_tags := TList.Create;
  for i := 0 to tables_positions.Count - 1 do
  begin
    t := tables_positions[i];
    indexed_tags.Add(Pointer(t.TAG))
  end;
  tables_positions.Free;
  Result := indexed_tags;
end;

procedure TrueTypeFont.LoadCoreTables;
var
  i : Integer;
  t : TrueTypeTable;
begin
  for i := 0 to ListOfTables.Count - 1 do
  begin
    t := ListOfTables[i];
    case TablesID(t.tag)  of
      FontHeaderID:  begin
        self.font_header := t as FontHeaderClass;
        self.font_header.Load(self.beginfile_ptr);
        end;
      MaximumProfileID: begin
        self.profile := t as MaximumProfileClass;
        self.profile.Load(self.beginfile_ptr);
      end;
      HorizontalHeaderID: begin
        self.horizontal_header := t as HorizontalHeaderClass;
        self.horizontal_header.Load(self.beginfile_ptr);
      end;
      PostscriptID: begin
        self.postscript := t as PostScriptClass;
        self.postscript.Load(self.beginfile_ptr)
      end;
      OS2TableID: begin
        self.windows_metrix := t as OS2WindowsMetricsClass;
        self.windows_metrix.Load(self.beginfile_ptr);
      end;
      IndexToLocationID: begin
        self.index_to_location := t as IndexToLocationClass;
        self.index_to_location.LoadIndexToLocation(self.beginfile_ptr, self.font_header);
      end;
      CMAPID: begin
        self.cmap_table := t as CmapTableClass;
        self.cmap_table.LoadCmapTable(self.beginfile_ptr);
      end;
      NameIDN:
      begin
        self.name_table := t as NameTableClass;
        self.name_table.Load(self.beginfile_ptr);
      end;
      GlyphID: begin
        self.glyph_table := t as GlyphTableClass;
        self.glyph_table.Load(self.beginfile_ptr);
      end;
      KerningTableID: begin
        self.kerning_table := t as KerningTableClass;
        self.kerning_table.Load(self.beginfile_ptr)
      end;
      GlyphSubstitutionID: begin
        self.gsub_table := t as GlyphSubstitutionClass;
        self.gsub_table.Load(self.beginfile_ptr)
      end;
      PreProgramID: begin
        self.preprogram_table := t as PreProgramClass;
        self.preprogram_table.Load(self.beginfile_ptr);
      end;
      HorizontalMetrixID: begin
        self.horizontal_metrix_table := t as HorizontalMetrixClass;
        self.horizontal_metrix_table.NumberOfMetrics := horizontal_header.NumberOfHMetrics;
        self.horizontal_metrix_table.Load(self.beginfile_ptr);
      end
  end;
  end;

end;

procedure TrueTypeFont.LoadDescriptors(skip_array: TIntegerList);
var
    parsed_table: TrueTypeTable;
    table: TrueTypeTable;
    i: Integer;
    tdir_ptr: ^TableDirectory;
    entry_ptr: ^TableEntry;
begin
    tdir_ptr := self.selector_ptr;
    self.dir.sfntversion := tdir_ptr.sfntversion;
    self.dir.numTables := tdir_ptr.numTables;
    self.dir.searchRange := tdir_ptr.searchRange;
    self.dir.entrySelector := tdir_ptr.entrySelector;
    self.dir.rangeShift := tdir_ptr.rangeShift;
    self.ChangeEndian;
    entry_ptr := selector_ptr + SizeOf(TableDirectory);
    i := 0;
    while ((i < self.dir.numTables)) do
    begin
        table := TrueTypeTable.Create(entry_ptr);
        if (skip_array.IndexOf( Pointer(table.tag)) = -1) then
        begin
            case ( TablesID(table.tag) ) of
                HorizontalHeaderID:
                    begin
                      parsed_table := HorizontalHeaderClass.Create(table);
                      table.Destroy;
                      end;
                FontHeaderID:
                    begin
                      parsed_table := FontHeaderClass.Create(table);
                      table.Destroy;
                    end;
                NameIDN:
                    begin
                      parsed_table := NameTableClass.Create(table);
                      table.Destroy;
                    end;
                OS2TableID:
                    begin
                      parsed_table := OS2WindowsMetricsClass.Create(table);
                      table.Destroy;
                      end;
                GlyphSubstitutionID:
                    begin
                      parsed_table := GlyphSubstitutionClass.Create(table);
                      table.Destroy;
                    end;
                IndexToLocationID:
                    begin
                      parsed_table := IndexToLocationClass.Create(table);
                      table.Destroy;
                    end;
                GlyphID:
                    begin
                      parsed_table := GlyphTableClass.Create(table);
                      table.Destroy;
                    end;
                KerningTableID:
                    begin
                      parsed_table := KerningTableClass.Create(table);
                      table.Destroy;
                    end;
                CMAPID:
                    begin
                      parsed_table := CmapTableClass.Create(table);
                      table.Destroy;
                    end;
                PostscriptID:
                    begin
                      parsed_table := PostScriptClass.Create(table);
                      table.Destroy;
                    end;
                HorizontalMetrixID:
                    begin
                      parsed_table := HorizontalMetrixClass.Create(table);
                      table.Destroy;
                    end;
                PreProgramID:
                    begin
                      parsed_table := PreProgramClass.Create(table);
                      table.Destroy;
                    end;
                MaximumProfileID:
                    begin
                      parsed_table := MaximumProfileClass.Create(table);
                      table.Destroy;
                    end;
                else
                    begin parsed_table := table; end;
              end;
            try
              self.ListOfTables.Add( parsed_table)
            except
            //    on ex: Exception do
            //      Windows.MessageBox(0, PChar(ex.Message), PChar('Font format error'), MB_YesNo)
            end
        end
        else begin
          table.Destroy;
        end;
        entry_ptr := Pointer(entry_ptr) + SizeOf(TableEntry);
        inc(i);
    end;
    self.dir.numTables := self.ListOfTables.Count
end;

function CompareTags(P1, P2: Pointer): Integer;
var
  V1, V2: Cardinal;
begin
  V1 := SwapEndian( PTableSortHelper(P1).TAG );
  V2 := SwapEndian( PTableSortHelper(P2).TAG );
  if V1 = V2 then begin
    Result :=  0;
  end else if V1 > V2 then begin
    Result :=  1;
  end else begin
    Result := -1;
  end;
end;

function ThisSort(Item1, Item2: Pointer): Integer;
begin
   if ( PtrUInt(Item1) < PtrUInt(Item2) ) then Result := -1
   else if (PtrUInt(Item1) > PtrUInt(Item2) )
   then Result := 1  else Result := 0;
end;


procedure TrueTypeFont.ReorderGlyphTable(position: Pointer; uniscribe: boolean);
var
    composite_indexes: TIntegerList;
    glyph_widths: TIntegerList;
    i,j: Integer;
    idx: Word;
    i2l_idx: Word;
    length: Word;
    glyph_table_size, location: Cardinal;
    LongIndexToLocation: TCardinalArray;
    ShortIndexToLocation: TWordArray;
    table_entry:  TrueTypeTable;
    out_index : Cardinal;
    sqz_index : Integer;
    glyph_table_ptr: ^Byte;
    glyph_ptr: ^Byte;
    SelectedGlyphs: Array of Byte;
    i2ll_ptr: ^Cardinal;
    i2ls_ptr: ^Smallint;
{$IFDEF DEBUG_STORE_PACKED_GLYPFS}
    out_ms: TMemoryStream;
{$ENDIF}
begin
    ShortIndexToLocation := self.index_to_location.Short;
    LongIndexToLocation := self.index_to_location.Long;
    self.ListOfUsedGlyphs.Sort(ThisSort);
        self.ListOfUsedGlyphs.Add(nil);
    self.BuildGlyphIndexList(self.ListOfUsedGlyphs, uniscribe, true, true,
      false, composite_indexes, glyph_widths, nil );
//        composite_indexes := Self.Indices;
    //composite_indexes := TList.Create;
   // for i := 0 to Self.Indices.Count - 1 do
    //  composite_indexes.Add(Self.Indices[i]);

    composite_indexes.Sort(ThisSort);
    glyph_table_size := 0;
    length := 0;
    location := 0;

    for i := 0 to composite_indexes.Count - 1 do
    begin
        idx := Integer(composite_indexes[i]);
        inc(glyph_table_size, self.index_to_location.GetGlyph(idx, self.font_header, location))
    end;

    table_entry := nil;
    for i := 0 to self.ListOfTables.Count - 1 do
    begin
      table_entry := self.ListOfTables[i];
      if table_entry.tag = Cardinal(GlyphID) then break;
    end;
    if table_entry = nil then
      raise Exception.Create('Glyph table not found');

    glyph_table_ptr := self.beginfile_ptr + (table_entry.offset);
    SetLength( SelectedGlyphs, glyph_table_size);
    out_index := 0;
    sqz_index := 0;

    for i := 0 to composite_indexes.Count - 1 do
    begin
      i2l_idx := Integer(composite_indexes[i]);
      length := self.index_to_location.GetGlyph(i2l_idx, self.font_header, location);
      case self.font_header.indexToLocFormat of
        IndexToLoc_ShortType:
            while ((sqz_index <= i2l_idx)) do
            begin
              ShortIndexToLocation[sqz_index] := Word((out_index div 2));
              inc(sqz_index);
            end;
        IndexToLoc_LongType:
            while ((sqz_index <= i2l_idx)) do
            begin
              LongIndexToLocation[sqz_index] := out_index;
              inc(sqz_index);
            end
        else
          raise Exception.Create('Unknown IndexToLoc value')
      end;
      if length <> 0 then
      begin
        glyph_ptr := Pointer(glyph_table_ptr) + location;
        for j:= 0 to length-1 do
        begin
          SelectedGlyphs[out_index + Cardinal(j)] := glyph_ptr^;
          Inc(glyph_ptr);
        end;
        Inc(out_index, length);
      end;
    end;

    glyph_table_ptr := self.beginfile_ptr + (table_entry.offset);
    if out_index > 0 then
      for i:= 0 to out_index do
      begin
        glyph_table_ptr^ := SelectedGlyphs[i];
        Inc(glyph_table_ptr);
      end;
    table_entry.length := out_index;



    SetLength( SelectedGlyphs, 0);
    SelectedGlyphs := nil;
    for i := 0 to self.ListOfTables.Count - 1 do
    begin
      table_entry := self.ListOfTables[i];
      if table_entry.tag = Cardinal(IndexToLocationID) then break;
    end;

    i := 0;
    case self.font_header.indexToLocFormat of
      IndexToLoc_ShortType:
      begin
        i2ls_ptr := self.beginfile_ptr + table_entry.offset;
        while (sqz_index < High(ShortIndexToLocation)) do
        begin
          ShortIndexToLocation[sqz_index] := Word((out_index div 2));
          inc(sqz_index)
        end;
        while (i < High(ShortIndexToLocation)) do
        begin
          i2ls_ptr^ :=  Smallint(SwapEndian(ShortIndexToLocation[i]));
          Inc(i2ls_ptr);
          inc(i)
        end;
      end;

      IndexToLoc_LongType:
      begin
        i2ll_ptr := self.beginfile_ptr + table_entry.offset;
        while (sqz_index <= High(LongIndexToLocation)) do
        begin
            LongIndexToLocation[sqz_index] := out_index;
            inc(sqz_index)
        end;
        while (i <= High(LongIndexToLocation)) do
        begin
          i2ll_ptr^ := Cardinal(SwapEndian(LongIndexToLocation[i]));
          Inc(i2ll_ptr);
          inc(i)
        end;
      end;
    end;
    table_entry.checkSum := self.CalcTableChecksum(self.beginfile_ptr, table_entry, false);
    for i := 0 to self.ListOfTables.Count - 1 do
    begin
      table_entry := self.ListOfTables[i];
      if table_entry.tag = Cardinal(GlyphID) then
      begin
        table_entry.checkSum := self.CalcTableChecksum(self.beginfile_ptr, table_entry, true );
        break;
      end;

    end;
  composite_indexes.Free;
end;

procedure TrueTypeFont.SaveDescriptors(position: Pointer);
var
  k, i: Integer;
  td_ptr: ^TableDirectory;
  descriptor_list: TList;
  tbls: Pointer;
  table:  TrueTypeTable;
  helper: array[0..40] of TTableSortHelper;
  desc: PTableSortHelper;
begin
    td_ptr := position;
    td_ptr.sfntversion := SwapEndian(self.dir.sfntversion);
    td_ptr.numTables := SwapEndian(self.dir.numTables);
    td_ptr.searchRange := SwapEndian(self.dir.searchRange);
    td_ptr.entrySelector := SwapEndian(self.dir.entrySelector);
    td_ptr.rangeShift := SwapEndian(self.dir.rangeShift);

    tbls := position + SizeOf(TableDirectory);
    descriptor_list := TList.Create;
    for i := 0 to self.ListOfTables.Count - 1 do
    begin
      table := self.ListOfTables[i];
      helper[i].Offset := table.offset;
      helper[i].Tag    := table.tag;
      descriptor_list.Add( @helper[i]);
    end;
    descriptor_list.Sort(CompareTags);

    for k := 0 to descriptor_list.Count - 1 do
    begin
      desc := descriptor_list[k];
      begin
        for i := 0 to self.ListOfTables.Count - 1 do
          begin
            table := self.ListOfTables[i];
            if table.tag = desc.TAG then
            begin
              tbls := table.StoreDescriptor(tbls);
              break;
            end;
          end;
{$IFDEF DEBUG_FONT_TAGS}
          Writeln(
            'Indexed tag ', TrueTypeTable(self.ListOfTables.Items[tag]).TAGLINE,
            ' Checksum ', IntToHex(TrueTypeTable(self.ListOfTables.Items[tag]).checkSum, 8),
            ' Size ', TrueTypeTable(self.ListOfTables.Items[tag]).length );
{$ENDIF}
      end;
    end;
    descriptor_list.Free;
end;

procedure TrueTypeFont.set_UsedGlyphs(dict: TList);
var
  i: Integer;
  key: Word;
begin
  ListOfUsedGlyphs.Clear;
//      key := Word(' ');
//      self.ListOfUsedGlyphs.Add(Pointer(key));
  for i := 0 to dict.Count - 1 do
  if Integer(Word(dict[i])) = Integer(dict[i]) then
  begin
    key := Word(dict[i]);
    if (ListOfUsedGlyphs.IndexOf(Pointer(key)) = -1) then
      ListOfUsedGlyphs.Add(Pointer(key))
  end
  else
    raise Exception.Create('Format error');
end;

function TrueTypeFont.get_GlyphWidth(glph: Integer): Cardinal;
var
  i: Integer;
  k: Integer;
begin
  for i := 0 to Indices.Count-1 do begin
    k := Integer(Indices[i]);
    if k = glph then begin
      Result := Cardinal(GlyphWidths[i]);
      Exit;
    end;
  end;
  result := 0; //  Self.windows_metrix.AvgCharWidth;
end;

function TrueTypeFont.get_Glyph(idx: Integer): Cardinal;
begin
  Result := Cardinal(Indices[idx]);
end;

constructor TrueTypeFont.Create(bgn: Pointer; font: Pointer;
  action: ChecksumFaultAction);
begin
  self.ListOfTables :=  TList.Create;
  self.ListOfUsedGlyphs := TList.Create;
//      self.ListOfUsedWidths := TList.Create;
  self.beginfile_ptr := bgn;
  self.selector_ptr := font;
  self.checksum_action := action;
  self.GlyphWidths := TIntegerList.Create;
  FSubstitutionName := '';
end;

destructor TrueTypeFont.Destroy;
var
  t:    TrueTypeTable;
  i: Integer;
begin
  for i := 0 to self.ListOfTables.Count - 1 do
  begin
    t := self.ListOfTables.Items[i];
    t.Free;
  end;
  self.ListOfTables.Clear;
  self.ListOfTables.Free;
  self.ListOfUsedGlyphs.Clear;
  self.ListOfUsedGlyphs.Free;
//      self.ListOfUsedWidths.Clear;
//      self.ListOfUsedWidths.Free;
  self.GlyphWidths.Clear;
  self.GlyphWidths.Free;
  if self.Indices <> nil then
    begin
      self.Indices.Clear;
      self.Indices.Free;
    end;
  inherited Destroy;
end;

procedure TrueTypeFont.AddCharacterToKeepList(ch: WideChar);
var
  key: Word;
begin
    key := Word(ch);
    if (ListOfUsedGlyphs.IndexOf(Pointer(key)) = -1) then
    begin
        ListOfUsedGlyphs.Add(Pointer(key));
    end;
end;

procedure TrueTypeFont.ParseSingleGlyph(idx: Word);
const
  collate   : Boolean = True;
  decompose : Boolean = False;
var
    location: Cardinal;
    composed_idx: Word;
    j, Length, GlyphWidth: Integer;
//        hash_index: Cardinal;
    composed_indexes: TIntegerlist;
    new_key: Smallint;
//        kerning: Smallint;
begin
  Length := index_to_location.GetGlyph(idx, self.font_header, location);
  if (Length <> 0) then
  begin
    composed_indexes := glyph_table.CheckGlyph(Cardinal(location), length);
    for j := 0 to composed_indexes.Count - 1 do
    begin
      composed_idx := Word(composed_indexes[j]);
      new_key := Indices.IndexOf(Pointer(composed_idx));
      if (not collate or (decompose and (new_key = -1))) then begin
        Indices.Add( Pointer(composed_idx));
        GlyphWidth := ((horizontal_metrix_table.Item[idx].advanceWidth * $3e8) div font_header.unitsPerEm);
        GlyphWidths.Add(Pointer(GlyphWidth))
      end;
    end;
    if (not collate or (Indices.IndexOf(Pointer(idx)) = -1)) then
    begin
      Indices.Add( Pointer(idx));
      GlyphWidth := ((horizontal_metrix_table.Item[idx].advanceWidth * $3e8) div font_header.unitsPerEm);
{
      if (use_kerning and ((i < (used_glyphs.Count - 1)) and (self.kerning_table <> nil))) then
      begin
        new_key := Word(used_glyphs[i + 1]);
        if uniscribe then next_idx := new_key else next_idx :=  self.cmap_table.GetGlyphIndex(new_key);
        hash_index := Cardinal(idx or (next_idx shl $10));
        kerning := self.kerning_table.Item[hash_index];
        inc(GlyphWidth, ((kerning * $3e8) div self.font_header.unitsPerEm))
      end;
}
      GlyphWidths.Add(Pointer(GlyphWidth))
    end;
    composed_indexes.Free;
  end
  else
  begin
    new_key := Indices.IndexOf(Pointer(idx));
    if ((idx = $3) and (not collate or (new_key = -1))) then
    begin
      Indices.Add(Pointer(idx));
      j := (windows_metrix.AvgCharWidth * $3e8) div font_header.unitsPerEm;
      GlyphWidths.Add(Pointer(j))
    end;
  end;
end;

function TrueTypeFont.GetGlyphIndices(text: Widestring; glyphs: PWord;
  widths: PInteger; rtl: boolean; ComposedList: TList): Integer;
var
    text_widths, text_as_array, IndexList: TIntegerList;
    ch: WideChar;
    I: Integer;
begin
    text_as_array := TIntegerList.Create;

    for ch in text do
    begin
        text_as_array.Add(PWord(ch))
    end;

    BuildGlyphIndexList(text_as_array, false, false, false, false, IndexList, text_widths, ComposedList);
    //glyphs := GetMemory(sizeof(Word) * IndexList.Count);
    for I := 0 to IndexList.Count - 1 do
    begin
      glyphs^ := Word(IndexList[I]);
      Inc(glyphs);
    end;
   // widths := GetMemory(sizeof(Integer) * text_widths.Count);
    for I := 0 to text_widths.Count - 1 do
    begin
      widths^ := Integer(text_widths[I]);
      Inc(widths);
    end;
    //widths := (text_widths.ToArray(typeof(Integer)) as Integer[]);
    //text_as_array.Free;

    //begin
        Result := IndexList.Count;
         IndexList.Free;
    text_widths.Free;
    //    exit
   // end
end;

procedure TrueTypeFont.GetOutlineTextMetrics(var FTextMetric: OutlineTextMetric
  );
begin
    FTextMetric.otmSize := $d4;
    FTextMetric.otmTextMetrics.tmHeight := (self.windows_metrix.Ascent + self.windows_metrix.Descent);
    FTextMetric.otmTextMetrics.tmAscent := self.windows_metrix.Ascent;
    FTextMetric.otmTextMetrics.tmDescent := self.windows_metrix.Descent;
    FTextMetric.otmTextMetrics.tmAveCharWidth := self.windows_metrix.AvgCharWidth;
    FTextMetric.otmTextMetrics.tmMaxCharWidth := self.horizontal_header.MaxWidth;
    FTextMetric.otmTextMetrics.tmFirstChar := WideChar(self.windows_metrix.FirstCharIndex);
    FTextMetric.otmTextMetrics.tmLastChar := WideChar(self.windows_metrix.LastCharIndex);
    FTextMetric.otmTextMetrics.tmDefaultChar := WideChar(self.windows_metrix.DefaultChar);
    FTextMetric.otmTextMetrics.tmBreakChar := WideChar(self.windows_metrix.BreakChar);
    FTextMetric.otmPanoseNumber.bFamilyType := self.windows_metrix.Panose[0];
    FTextMetric.otmPanoseNumber.bSerifStyle := self.windows_metrix.Panose[1];
    FTextMetric.otmPanoseNumber.bWeight := self.windows_metrix.Panose[2];
    FTextMetric.otmPanoseNumber.bProportion := self.windows_metrix.Panose[3];
    FTextMetric.otmPanoseNumber.bContrast := self.windows_metrix.Panose[4];
    FTextMetric.otmPanoseNumber.bStrokeVariation := self.windows_metrix.Panose[5];
//        FTextMetric.otmPanoseNumber.ArmStyle := self.windows_metrix.Panose[6];
    FTextMetric.otmPanoseNumber.bLetterform := self.windows_metrix.Panose[7];
    FTextMetric.otmPanoseNumber.bMidline := self.windows_metrix.Panose[8];
    FTextMetric.otmPanoseNumber.bXHeight := self.windows_metrix.Panose[9];
    FTextMetric.otmItalicAngle := ((self.postscript.ItalicAngle shr $10) * 10);
    FTextMetric.otmEMSquare := self.font_header.unitsPerEm;
    FTextMetric.otmAscent := self.horizontal_header.Ascender;
    FTextMetric.otmDescent := self.horizontal_header.Descender;
    if self.horizontal_header.LineGap > 0 then
      FTextMetric.otmLineGap := Cardinal(self.horizontal_header.LineGap)
    else
      FTextMetric.otmLineGap := 0;
    FTextMetric.otmpFamilyName := PAnsiChar(self.name_table.Item[NameID_FamilyName]);
    //FTextMetric.otmpFullName := PAnsiChar(self.name_table.Item[NameID.FullName])
end;

function TrueTypeFont.PackFont(translate_to: FontType; uniscribe: boolean
  ): TByteArray;
var
  indexed_tags: TTagList;
  current_offset: Cardinal;
  buff: TByteArray;
  i: Integer;
  j: Integer;
  ptr: ^Byte;
  table:  TrueTypeTable;
begin
    indexed_tags := self.GetTablesOrder;
    self.ReorderGlyphTable(self.beginfile_ptr, uniscribe);
    current_offset := Cardinal( 12 {SizeOf(FontHeaderClass.FontHeader)} + (self.dir.numTables * $10));
    for i := 0 to indexed_tags.Count - 1 do
      for j := 0 to self.ListOfTables.Count - 1 do
      begin
        table := self.ListOfTables[j];
        if table.tag = Cardinal(indexed_tags[i]) then
        begin
          current_offset := table.Save(self.beginfile_ptr, current_offset);
          if ((current_offset mod 4) <> 0) then
             raise Exception.Create('Align error');
        end;
      end;
    self.SaveDescriptors(self.beginfile_ptr);
    self.CalculateFontChecksum(self.beginfile_ptr, current_offset);
    SetLength( buff, current_offset );
    ptr := self.beginfile_ptr;
    for i:=0 to current_offset - 1 do
    begin
      buff[i] := ptr^;
      Inc(Ptr);
    end;
    indexed_tags.Free;
    Result := buff;
    buff := nil;
end;

procedure TrueTypeFont.PrepareFont(skip_list: TIntegerList);
begin
  self.LoadDescriptors(skip_list);
  self.LoadCoreTables;
  self.CheckTablesChecksum;
end;

function TrueTypeFont.GetFamilyName: String;
begin
  Result := string(name_table.Item[NameID_FamilyName]);
end;



{ TrueTypeTable }

procedure TrueTypeTable.ChangeEndian;
begin
  Entry.checkSum := SwapEndian(Entry.checkSum);
  Entry.offset := SwapEndian(Entry.offset);
  Entry.length := SwapEndian(Entry.length);
end;

function TrueTypeTable.Get_TagLine: string;
var
  s: string;
  c: char;
  tag: cardinal;
begin
  SetLength(s, 4);
  tag := entry.tag;
  c := Char(tag mod $100);
  tag := tag div $100;
  s[1] := c;
  c := Char(tag mod $100);
  tag := tag div $100;
  s[2] := c;
  c := Char(tag mod $100);
  tag := tag div $100;
  s[3] := c;
  c := Char(tag mod $100);
//      tag := tag div $100;
  s[4] := c;
  Result := s;
end;

procedure TrueTypeTable.Set_Length(AValue: Cardinal);
begin
  Entry.length:= AValue;
end;

procedure TrueTypeTable.Set_Offset(AValue: Cardinal);
begin
  Entry.offset := AValue;
end;

function TrueTypeTable.StoreTable(source_ptr: Pointer;
  destination_ptr: Pointer; output_offset: Cardinal): Cardinal;
var
  src, dst, buffer: Pointer;
  length: Integer;
begin
  length := Integer((Entry.length + 3) shr 2) shl 2;
  src := source_ptr + Entry.offset;
  dst := destination_ptr + output_offset;
  if (src <> dst) then
  begin
    GetMem(buffer, length);
    Move( src^, buffer^, length);
    Move( buffer^, dst^, length);
    FreeMem(buffer, length);
    Entry.offset := output_offset
  end;
    output_offset := Integer(output_offset) + length;
    Result := output_offset;
end;

procedure TrueTypeTable.Load(font: Pointer);
begin

end;

constructor TrueTypeTable.Create(parent: TrueTypeTable);
begin
  Entry := Parent.Entry;
end;

constructor TrueTypeTable.Create(Entry_Ptr: Pointer);
var
  table_ptr: ^TableEntry;
begin
    table_ptr := Entry_Ptr;
    Entry.checkSum := table_ptr.checkSum;
    Entry.length := table_ptr.length;
    Entry.offset := table_ptr.offset;
    Entry.tag := table_ptr.tag;
    ChangeEndian;
end;

function TrueTypeTable.Save(Font: Pointer; Offset: Cardinal): Cardinal;
begin
  Result := StoreTable(font, font, offset);
end;

function TrueTypeTable.StoreDescriptor(Descriptor_Ptr: Pointer): Pointer;
var
  table_ptr: ^TableEntry;
begin
  ChangeEndian;
  table_ptr := descriptor_ptr;
  table_ptr.checkSum := self.entry.checkSum;
  table_ptr.length := self.entry.length;
  table_ptr.offset := self.entry.offset;
  table_ptr.tag := self.entry.tag;
  ChangeEndian;
  Result := descriptor_ptr + SizeOf(TableEntry);
end;

{ CmapTableClass }

function CmapTableClass.LoadCmapSegment(segment_ptr: Pointer;
  segment_count: Integer): TWordArray;
var
  i: Integer;
  ptr: ^Word;
begin
  ptr := segment_ptr;
  SetLength(Result, segment_count);
  i := 0;
  while (i < segment_count) do
  begin
    Result[i] := SwapEndian(ptr^);
    Inc(i);
    Inc(ptr);
  end;
end;

function CmapTableClass.LoadSignedCmapSegment(segment_ptr: Pointer;
  segment_count: Integer): TSmallintArray;
var
  i: Integer;
  p : PWord;
begin
  SetLength(Result, segment_count);
  p := segment_ptr;
  i := 0;
  while ((i < segment_count)) do
  begin
    {$R-}
    Result[i] := SwapEndian(p^);
    {$R+}
    inc(i);
    inc(p);
  end;
end;

constructor CmapTableClass.Create(src: TrueTypeTable);
begin
  inherited Create(src);
end;

function CmapTableClass.GetGlyphIndex(ch: Word): Word;
var
  i,j: Integer;
  GlyphIDX: SmallInt;
begin
  GlyphIDX := 0;
  i := 0;
  while ((i < self.segment_count)) do
  begin
    if (endCount[i] >= ch) then
    begin
      if (startCount[i] > ch) then
      begin
        Result := GlyphIDX;
        Exit
      end;
      if (idRangeOffset[i] = 0) then
      begin
        Result := Word((ch + idDelta[i]) mod $10000);
        exit
      end;
      j := Word(((idRangeOffset[i] div 2) + (ch - startCount[i])) - (segment_count - i));
      begin
        Result := self.GlyphIndexArray[j];
        exit
      end
    end;
    inc(i)
  end;
  Result := GlyphIDX;
end;

procedure CmapTableClass.LoadCmapTable(font: Pointer);
var
  encode_ptr:           ^Table_Encode;
  encode:               Table_Encode;
  cmap:                 ^Table_CMAP;
  j,subtables_count:    Integer;
  submap:               Table_SUBMAP;
  submap_ptr:           ^Table_SUBMAP;
  segment:              TSegmentMapping;
  segment_ptr:          ^TSegmentMapping;
  index_array_size:     Cardinal;
begin
  cmap := font + entry.offset;
  subtables_count := SwapEndian(cmap.NumSubTables);
  submap_ptr :=  Pointer(cmap) + SizeOf(Table_CMAP);
  j := 0;
  while ((j < subtables_count)) do
  begin
//  submap := submap_ptr;
    submap.Platform := SwapEndian(submap_ptr.Platform);
    submap.EncodingID := SwapEndian(submap_ptr.EncodingID);
    submap.TableOffset := SwapEndian(submap_ptr.TableOffset);
    submap_ptr := Pointer(submap_ptr) + SizeOf(Table_SUBMAP);
    if ((submap.Platform = 3) and (submap.EncodingID = 1)) then
    begin
      encode_ptr := Pointer(cmap) + submap.TableOffset;
//    encode := encode_ptr;
      encode.Format := SwapEndian(encode_ptr.Format);
      encode.Length := SwapEndian(encode_ptr.Length);
      encode.Version := SwapEndian(encode_ptr.Version);
      case encode.Format of
        0:
        begin
          raise Exception.Create('TO DO: ByteEncoding cmap format not implemented')
        end;
//      1,3,5:
//      begin
//        continue;
//      end;
        2:
        begin
          raise Exception.Create('TO DO: HighByteMapping cmap format not implemented')
        end;
        4:
        begin
          segment_ptr := Pointer(encode_ptr) + SizeOf(Table_Encode);
//        segment := encode_ptr;
          segment.segCountX2 := SwapEndian(segment_ptr.segCountX2);
          segment.searchRange := SwapEndian(segment_ptr.searchRange);
          segment.entrySelector := SwapEndian(segment_ptr.entrySelector);
          segment.rangeShift := SwapEndian(segment_ptr.rangeShift);
          segment_count := (segment.segCountX2 div 2);

          encode_ptr := Pointer(segment_ptr) + SizeOf(TSegmentMapping);
          endCount := LoadCmapSegment(encode_ptr, segment_count);
          encode_ptr := Pointer(encode_ptr) + (segment.segCountX2 + 2);
          startCount := LoadCmapSegment(encode_ptr, segment_count);
          encode_ptr := Pointer(encode_ptr) + segment.segCountX2;
          idDelta := LoadSignedCmapSegment(encode_ptr, segment_count);
          encode_ptr := Pointer(encode_ptr) + segment.segCountX2;
          idRangeOffset := LoadCmapSegment(encode_ptr, segment_count);

          index_array_size := Cardinal((8 + (4 * segment_count)) * 2);
          index_array_size := ((inherited length - index_array_size) div 2);
          encode_ptr := Pointer(encode_ptr) + segment.segCountX2;

          GlyphIndexArray := LoadCmapSegment(encode_ptr, index_array_size);
        end;
        6:
        begin
          raise Exception.Create('TO DO: TrimmedTable cmap format not implemented')
        end;
      end
    end;
    inc(j);
    continue;
  end
end;

{ FontHeaderClass }

procedure FontHeaderClass.ChangeEndian;
begin
  font_header.indexToLocFormat := SwapEndian(font_header.indexToLocFormat);
  font_header.magicNumber := SwapEndian(font_header.magicNumber);
  font_header.unitsPerEm := SwapEndian(font_header.unitsPerEm);
  font_header.flags := SwapEndian(font_header.flags);
end;

function FontHeaderClass.get_indexToLocFormat: IndexToLoc;
begin
  Result := IndexToLoc(font_header.indexToLocFormat);
end;

constructor FontHeaderClass.Create(src: TrueTypeTable);
begin
  inherited Create(src);
end;

procedure FontHeaderClass.Load(font: Pointer);
var
  header: ^FontHeader;
begin
    header := font + self.entry.offset; //header_ptr;
    font_header.checkSumAdjustment := header.checkSumAdjustment;
    font_header.CreatedDateTime := header.CreatedDateTime;
    font_header.flags := header.flags;
    font_header.fontDirectionHint := header.fontDirectionHint;
    font_header.glyphDataFormat := header.glyphDataFormat;
    font_header.indexToLocFormat:= header.indexToLocFormat;
    font_header.lowestRecPPEM := header.lowestRecPPEM;
    font_header.macStyle := header.macStyle;
    font_header.magicNumber := header.magicNumber;
    font_header.ModifiedDateTime := header.ModifiedDateTime;
    font_header.revision := header.revision;
    font_header.unitsPerEm := header.unitsPerEm;
    font_header.version := header.version;
    font_header.xMax := header.xMax;
    font_header.xMin := header.xMin;
    font_header.yMax := header.yMax;
    font_header.yMin := header.yMin;
    ChangeEndian;

    header.checkSumAdjustment := 0;
end;

procedure FontHeaderClass.SaveFontHeader(header_ptr: Pointer; CheckSum: Cardinal
  );
var
  header: ^FontHeader;
begin
    ChangeEndian;
    header_ptr := header_ptr + self.entry.offset;
    header := header_ptr;

    font_header.checkSumAdjustment := SwapEndian(CheckSum);

    header.checkSumAdjustment := font_header.checkSumAdjustment;
    header.CreatedDateTime := font_header.CreatedDateTime;
    font_header.flags := header.flags;
    header.fontDirectionHint := font_header.fontDirectionHint;
    header.glyphDataFormat := font_header.glyphDataFormat;
    header.indexToLocFormat := font_header.indexToLocFormat;
    header.lowestRecPPEM := font_header.lowestRecPPEM;
    header.macStyle := font_header.macStyle;
    header.magicNumber := font_header.magicNumber;
    header.ModifiedDateTime := font_header.ModifiedDateTime;
    header.revision := font_header.revision;
    header.unitsPerEm := font_header.unitsPerEm;
    header.version := font_header.version;
    header.xMax := font_header.xMax;
    header.xMin := font_header.xMin;
    header.yMax := font_header.yMax;
    header.yMin := font_header.yMin;
    self.ChangeEndian
end;

{ GlyphTableClass }

function GlyphTableClass.GetGlyphHeader(glyph_offset: Integer): GlyphHeader;
var
  gheader: ^GlyphHeader;
begin
  gheader := glyph_table_ptr + glyph_offset;
  Result.numberOfContours := SwapEndian(gheader.numberOfContours);
  Result.xMax := SwapEndian(gheader.xMax);
  Result.yMax := SwapEndian(gheader.yMax);
  Result.xMin := SwapEndian(gheader.xMin);
  Result.yMin := SwapEndian(gheader.yMin);
end;

constructor GlyphTableClass.Create(src: TrueTypeTable);
begin
   inherited Create(src);
end;

destructor GlyphTableClass.Destroy;
begin
  inherited Destroy;
end;

function GlyphTableClass.CheckGlyph(glyph_offset: Integer; glyph_size: Integer
  ): TIntegerList;
var
  gheader: GlyphHeader;
  pcgh: ^CompositeGlyphHeader;
  cgh: CompositeGlyphHeader;
  CompositeIndexes: TIntegerlist;
  glyph_ptr: Pointer;
  composite_header_ptr: Pointer;
begin
  CompositeIndexes := TIntegerlist.Create;
  gheader := GetGlyphHeader(glyph_offset);

  glyph_ptr := glyph_table_ptr + glyph_offset;
  if (gheader.numberOfContours < 0) then
  begin
    composite_header_ptr := glyph_ptr + SizeOf(GlyphHeader);
    repeat
      pcgh := composite_header_ptr;
      cgh.flags := SwapEndian(pcgh.flags);
      cgh.glyphIndex := SwapEndian(pcgh.glyphIndex);
      CompositeIndexes.Add(Pointer(cgh.glyphIndex));
            // Skip
      composite_header_ptr := composite_header_ptr +
        SizeOf(CompositeGlyphHeader);
      if ((cgh.flags and 1) <> 0) then
        composite_header_ptr := composite_header_ptr + 4
      else
        composite_header_ptr := composite_header_ptr + 2;
      if ((cgh.flags and 8) <> 0) then
        composite_header_ptr :=  composite_header_ptr + 2
      else
        if ((cgh.flags and $40) <> 0) then
          composite_header_ptr := composite_header_ptr + 4
        else
          if ((cgh.flags and $80) <> 0) then
            composite_header_ptr := composite_header_ptr + 8;
    until ((cgh.flags and $20) = 0);
  end;
    Result := CompositeIndexes;
end;

procedure GlyphTableClass.Load(font: Pointer);
begin
  glyph_table_ptr := font + Entry.offset;
end;

procedure GlyphSubstitutionClass.ChangeEndian;
begin
  header.Version := SwapEndian(header.Version);
  header.ScriptList := SwapEndian(header.ScriptList);
  header.LookupList := SwapEndian(header.LookupList);
  header.FeatureList := SwapEndian(header.FeatureList)
end;

constructor GlyphSubstitutionClass.Create(src: TrueTypeTable);
begin
  inherited Create(src);
end;

procedure GlyphSubstitutionClass.Load(font: Pointer);
var
  gsub: ^GSUB_Header;
begin
    gsub := font + entry.offset;
    header.FeatureList :=  gsub.FeatureList;
    header.LookupList := gsub.LookupList;
    header.ScriptList := gsub.ScriptList;
    header.Version := gsub.Version;
    ChangeEndian
end;

function GlyphSubstitutionClass.Save(font: Pointer; offset: Cardinal): Cardinal;
begin
  Result:=inherited Save(font, offset);
end;

{ HorizontalHeaderClass }

procedure HorizontalHeaderClass.ChangeEndian;
begin
  horizontal_header.Version := SwapEndian(horizontal_header.Version);
  horizontal_header.Ascender := SwapEndian(horizontal_header.Ascender);
  horizontal_header.Descender := SwapEndian(horizontal_header.Descender);
  horizontal_header.LineGap := SwapEndian(horizontal_header.LineGap);
  horizontal_header.advanceWidthMax := SwapEndian(horizontal_header.advanceWidthMax);
  horizontal_header.minLeftSideBearing := SwapEndian(horizontal_header.minLeftSideBearing);
  horizontal_header.minRightSideBearing := SwapEndian(horizontal_header.minRightSideBearing);
  horizontal_header.xMaxExtent := SwapEndian(horizontal_header.xMaxExtent);
  horizontal_header.caretSlopeRise := SwapEndian(horizontal_header.caretSlopeRise);
  horizontal_header.caretSlopeRun := SwapEndian(horizontal_header.caretSlopeRun);
  horizontal_header.metricDataFormat := SwapEndian(horizontal_header.metricDataFormat);
  horizontal_header.numberOfHMetrics := SwapEndian(horizontal_header.numberOfHMetrics)
end;

constructor HorizontalHeaderClass.Create(src: TrueTypeTable);
begin
  inherited Create(src);
end;

procedure HorizontalHeaderClass.Load(font: Pointer);
var
  header: ^HorizontalHeader;
begin
  header := font + entry.offset;
  horizontal_header.advanceWidthMax := header.advanceWidthMax;
  horizontal_header.Ascender :=  header.Ascender;
  horizontal_header.caretSlopeRise := header.caretSlopeRise;
  horizontal_header.caretSlopeRun := header.caretSlopeRun;
  horizontal_header.Descender := header.Descender;
  horizontal_header.LineGap := header.LineGap;
  horizontal_header.metricDataFormat := header.metricDataFormat;
  horizontal_header.minLeftSideBearing := header.minLeftSideBearing;
  horizontal_header.minRightSideBearing := header.minRightSideBearing;
  horizontal_header.numberOfHMetrics := header.numberOfHMetrics;
  horizontal_header.reserved1 := header.reserved1;
  horizontal_header.reserved2 := header.reserved2;
  horizontal_header.reserved3 := header.reserved3;
  horizontal_header.reserved4 := header.reserved4;
  horizontal_header.reserved5 := header.reserved5;
  horizontal_header.Version  := header.Version;
  horizontal_header.xMaxExtent := header.xMaxExtent;
  ChangeEndian
end;

function HorizontalHeaderClass.Save(font: Pointer; offset: Cardinal): Cardinal;
var
  header: ^HorizontalHeader;
begin
    entry.offset := offset;
    ChangeEndian;
    header := font + entry.offset;
    header.advanceWidthMax := horizontal_header.advanceWidthMax;
    header.Ascender := horizontal_header.Ascender;
    header.caretSlopeRise := horizontal_header.caretSlopeRise;
    header.caretSlopeRun := horizontal_header.caretSlopeRun;
    header.Descender := horizontal_header.Descender;
    header.LineGap := horizontal_header.LineGap;
    header.metricDataFormat := horizontal_header.metricDataFormat;
    header.minLeftSideBearing := horizontal_header.minLeftSideBearing;
    header.minRightSideBearing := horizontal_header.minRightSideBearing;
    header.numberOfHMetrics := horizontal_header.numberOfHMetrics;
    header.reserved1 := horizontal_header.reserved1;
    header.reserved2 := horizontal_header.reserved2;
    header.reserved3 := horizontal_header.reserved3;
    header.reserved4 := horizontal_header.reserved4;
    header.reserved5 := horizontal_header.reserved5;
    header.Version := horizontal_header.Version;
    header.xMaxExtent := horizontal_header.xMaxExtent;
    ChangeEndian;
    Result := (offset + entry.length)
end;

{ HorizontalMetrixClass }

function HorizontalMetrixClass.GetItem(index: Integer): longHorMetric;
begin
  Result := MetrixTable[index];
end;

constructor HorizontalMetrixClass.Create(src: TrueTypeTable);
begin
  inherited Create(src);
end;

procedure HorizontalMetrixClass.Load(font: Pointer);
var
  h_metrix: ^longHorMetric;
  i: Integer;
begin

    SetLength(MetrixTable, NumberOfMetrics);
    h_metrix := font + entry.offset;
    i := 0;
    while ((i < NumberOfMetrics)) do
    begin
        MetrixTable[i].advanceWidth := SwapEndian( h_metrix.advanceWidth );
        MetrixTable[i].lsb := SwapEndian( h_metrix.lsb);
        Inc(h_metrix); // Check incremet size - must be record size
        inc(i)
    end
end;

{ IndexToLocationClass }

constructor IndexToLocationClass.Create(src: TrueTypeTable);
begin
  inherited Create(src);
  ShortIndexToLocation := nil;
  LongIndexToLocation := nil
end;

function IndexToLocationClass.GetGlyph(i2l_idx: Word;
  font_header: FontHeaderClass; var location: Cardinal): Word;
begin
  location := 0;
  case font_header.indexToLocFormat of
    IndexToLoc_ShortType:
    begin
      location := Cardinal(ShortIndexToLocation[i2l_idx] * 2);
      Result := Word(2 * (ShortIndexToLocation[(i2l_idx + 1)] - ShortIndexToLocation[i2l_idx]));
      exit
    end;
    IndexToLoc_LongType:
    begin
      location := LongIndexToLocation[i2l_idx];
      Result := Word(LongIndexToLocation[(i2l_idx + 1)] - LongIndexToLocation[i2l_idx]);
      exit
    end;
  end;
  Result := 0;
end;

procedure IndexToLocationClass.LoadIndexToLocation(font: Pointer;
  font_header: FontHeaderClass);
type
  TShortPtr =  ^Word;
  TLongPtr =   ^LongWord;
var
  count:      Integer;
  i:          Integer;
  short_ptr:  ^Word;
  long_ptr:   ^LongWord;
begin
  case font_header.indexToLocFormat of
    IndexToLoc_ShortType:
    begin
      count := entry.length div 2;
      SetLength(ShortIndexToLocation, count );
      short_ptr := font + entry.offset;
      i := 0;
      while (i < count) do
      begin
        ShortIndexToLocation[i] := SwapEndian( short_ptr^ );
        Inc(short_ptr);
        Inc(i)
      end;
    end;
    IndexToLoc_LongType:
    begin
      count := entry.length div 4;
      SetLength(LongIndexToLocation, count );
      long_ptr := font + entry.offset;
      i := 0;
      while (i < count) do
      begin
        LongIndexToLocation[i] := SwapEndian(long_ptr^);
        Inc(long_ptr);
        inc(i)
      end;
    end;
    else
      raise Exception.Create('Unsupported Index to Location format')
  end;
end;

{ KerningSubtableClass }

function KerningSubtableClass.get_Item(inx: Cardinal): Smallint;
begin
  Result := 0;
end;

constructor KerningSubtableClass.Create(kerning_table_ptr: Pointer);
begin

end;

destructor KerningSubtableClass.Destroy;
begin
  inherited Destroy;
end;

{ KerningTableClass }

procedure KerningTableClass.ChangeEndian;
begin
  kerning_table_header.nTables := SwapEndian(kerning_table_header.nTables)
end;

function KerningTableClass.get_Item(idx: Cardinal): Smallint;
var
  subtable: KerningSubtableClass;
begin
  subtable := kerning_subtables_collection[0];
  Result := subtable.Item[idx];
end;

constructor KerningTableClass.Create(src: TrueTypeTable);
begin
  inherited Create(src);
  kerning_subtables_collection := TList.Create;
end;

destructor KerningTableClass.Destroy;
var
  i : Integer;
  f : KerningSubtableClass;
begin
  for i := 0 to kerning_subtables_collection.Count - 1 do
  begin
    f := KerningSubtableClass(kerning_subtables_collection[i]);
    f.Free;
  end;
  kerning_subtables_collection.Free;
end;


procedure KerningTableClass.Load(font: Pointer);
var
   header: ^KerningTableHeader;
   i: Integer;
   subtable_ptr: Pointer;
   subtable: KerningSubtableClass;
begin
    header := font + entry.offset;
    kerning_table_header.nTables := header.nTables;
    ChangeEndian;

    subtable_ptr := Pointer(header) + SizeOf(KerningTableHeader);
    i := 0;
    while ((i < kerning_table_header.nTables)) do
    begin
        subtable := KerningSubtableClass.Create(subtable_ptr);
        kerning_subtables_collection.Add(subtable);
        subtable_ptr := subtable_ptr + subtable.Length;
        inc(i)
    end
end;

{ NameTableClass }

procedure NameTableClass.ChangeEndian;
begin
  name_header.Count := SwapEndian(name_header.Count);
  name_header.stringOffset := SwapEndian(name_header.stringOffset);
  name_header.TableVersion := SwapEndian(name_header.TableVersion);
end;

function NameTableClass.get_Item(Index: NameID): AnsiString;
var
  i,sz:  Integer;
  name_record_ptr: ^NamingRecord;
  name_rec: NamingRecord;
  string_ptr: Pointer;

  //p: PAnsiChar;

begin
  Result := '';
  name_record_ptr := namerecord_ptr;
  for i := 0 to name_header.Count do
  begin
    name_rec.PlatformID := SwapEndian(name_record_ptr.PlatformID);
    name_rec.EncodingID := SwapEndian(name_record_ptr.EncodingID);
    name_rec.LanguageID := SwapEndian(name_record_ptr.LanguageID);
    name_rec.NameID := SwapEndian(name_record_ptr.NameID);
    name_rec.Length := SwapEndian(name_record_ptr.Length);
    name_rec.Offset := SwapEndian(name_record_ptr.Offset);

    if (((name_rec.PlatformID = 3) and (name_rec.EncodingID = 1))
          or (name_rec.PlatformID = 0)) and (NameID(name_rec.NameID) = Index) then
    begin
      { Dirty dirty hack with +1 }
      string_ptr := string_storage_ptr + (name_rec.Offset + 1);
      //GetMem(p, name_rec.Length);
      Result := UTF16ToUTF8(PWideChar(string_ptr),name_rec.Length Div 2);
      //sz := WideCharToMultiByte( CP_ACP, 0, string_ptr, name_rec.Length Div 2, p, name_rec.Length, nil, nil);
      //Result := p;
      //if sz > 0 then SetLength(Result, sz);
      //FreeMem(p);
      Exit
    end;
    Inc(name_record_ptr);
  end;
end;

constructor NameTableClass.Create(src: TrueTypeTable);
begin
  inherited Create(src);
end;

destructor NameTableClass.Destroy;
begin
  inherited Destroy;
end;

procedure NameTableClass.Load(font: Pointer);
var
  pNTH:               ^NamingTableHeader;
begin
  pNTH :=  font + self.entry.offset ;
  name_header.TableVersion  := pNTH.TableVersion;
  name_header.stringOffset  := pNTH.stringOffset;
  name_header.Count         := pNTH.Count;
  ChangeEndian;
  namerecord_ptr := Pointer(NativeInt(pNTH) + SizeOf(NamingTableHeader));
  string_storage_ptr := Pointer(NativeInt(pNTH) + name_header.stringOffset);
end;

{ PostScriptClass }

procedure PostScriptClass.ChangeEndian;
begin
  post_script.Version := SwapEndian(post_script.Version);
  post_script.ItalicAngle := SwapEndian(post_script.ItalicAngle);
  post_script.underlinePosition := SwapEndian(post_script.underlinePosition);
  post_script.underlineThickness := SwapEndian(post_script.underlineThickness);
  post_script.isFixedPitch := SwapEndian(post_script.isFixedPitch);
  post_script.minMemType42 := SwapEndian(post_script.minMemType42);
  post_script.maxMemType42 := SwapEndian(post_script.maxMemType42);
  post_script.minMemType1 := SwapEndian(post_script.minMemType1);
  post_script.maxMemType1 := SwapEndian(post_script.maxMemType1)
end;

constructor PostScriptClass.Create(src: TrueTypeTable);
begin
  inherited Create(src);
end;

procedure PostScriptClass.Load(font: Pointer);
var
  p: ^PostScript;
begin
    p := font + entry.offset;
    post_script.Version := p.Version;
    post_script.ItalicAngle := p.ItalicAngle;
    post_script.underlinePosition := p.underlinePosition;
    post_script.underlineThickness := p.underlineThickness;
    post_script.isFixedPitch := p.isFixedPitch;
    post_script.minMemType42 := p.minMemType42;
    post_script.maxMemType42 := p.maxMemType42;
    post_script.minMemType1 := p.minMemType1;
    post_script.maxMemType1 := p.maxMemType1;
    ChangeEndian
end;

function PostScriptClass.Save(font: Pointer; offset: Cardinal): Cardinal;
var
  p: ^PostScript;
begin
    entry.offset := offset;
    post_script.Version := $30000;
    entry.length := SizeOf(PostScript);
    ChangeEndian;
    p := font + entry.offset;
    p.Version := post_script.Version;
    p.ItalicAngle := post_script.ItalicAngle;
    p.underlinePosition := post_script.underlinePosition;
    p.underlineThickness := post_script.underlineThickness;
    p.isFixedPitch := post_script.isFixedPitch;
    p.minMemType42 := post_script.minMemType42;
    p.maxMemType42 := post_script.maxMemType42;
    p.minMemType1 := post_script.minMemType1;
    p.maxMemType1 := post_script.maxMemType1;
    ChangeEndian;
    Result := offset + entry.length
end;

{ MaximumProfileClass }

procedure MaximumProfileClass.ChangeEndian;
begin
  max_profile.Version := SwapEndian(max_profile.Version);
  max_profile.numGlyphs := SwapEndian(max_profile.numGlyphs);
  max_profile.maxPoints := SwapEndian(max_profile.maxPoints);
  max_profile.maxContours := SwapEndian(max_profile.maxContours);
  max_profile.maxCompositePoints := SwapEndian(max_profile.maxCompositePoints);
  max_profile.maxCompositeContours := SwapEndian(max_profile.maxCompositeContours);
  max_profile.maxZones := SwapEndian(max_profile.maxZones);
  max_profile.maxTwilightPoints := SwapEndian(max_profile.maxTwilightPoints);
  max_profile.maxStorage := SwapEndian(max_profile.maxStorage);
  max_profile.maxFunctionDefs := SwapEndian(max_profile.maxFunctionDefs);
  max_profile.maxInstructionDefs := SwapEndian(max_profile.maxInstructionDefs);
  max_profile.maxStackElements := SwapEndian(max_profile.maxStackElements);
  max_profile.maxSizeOfInstructions := SwapEndian(max_profile.maxSizeOfInstructions);
  max_profile.maxComponentElements := SwapEndian(max_profile.maxComponentElements);
  max_profile.maxComponentDepth := SwapEndian(max_profile.maxComponentDepth)
end;

constructor MaximumProfileClass.Create(src: TrueTypeTable);
begin
  inherited Create(src);
end;

procedure MaximumProfileClass.Load(font: Pointer);
var
  max_p: ^MaximumProfile;
begin
    max_p := font + entry.offset;
    max_profile.Version := max_p.Version;
    max_profile.numGlyphs := max_p.numGlyphs;
    max_profile.maxPoints := max_p.maxPoints;
    max_profile.maxContours := max_p.maxContours;
    max_profile.maxCompositePoints := max_p.maxCompositePoints;
    max_profile.maxCompositeContours := max_p.maxCompositeContours;
    max_profile.maxZones := max_p.maxZones;
    max_profile.maxTwilightPoints := max_p.maxTwilightPoints;
    max_profile.maxStorage := max_p.maxStorage;
    max_profile.maxFunctionDefs := max_p.maxFunctionDefs;
    max_profile.maxInstructionDefs := max_p.maxInstructionDefs;
    max_profile.maxStackElements := max_p.maxStackElements;
    max_profile.maxSizeOfInstructions := max_p.maxSizeOfInstructions;
    max_profile.maxComponentElements := max_p.maxComponentElements;
    max_profile.maxComponentDepth := max_p.maxComponentDepth;
    ChangeEndian;
end;

function MaximumProfileClass.Save(font: Pointer; offset: Cardinal): Cardinal;
var
  max_p: ^MaximumProfile;
begin
    entry.offset := offset;
    ChangeEndian;
    max_p := font + entry.offset;
    max_p.Version := max_profile.Version;
    max_p.numGlyphs := max_profile.numGlyphs;
    max_p.maxPoints := max_profile.maxPoints;
    max_p.maxContours := max_profile.maxContours;
    max_p.maxCompositePoints := max_profile.maxCompositePoints;
    max_p.maxCompositeContours := max_profile.maxCompositeContours;
    max_p.maxZones := max_profile.maxZones;
    max_p.maxTwilightPoints := max_profile.maxTwilightPoints;
    max_p.maxStorage := max_profile.maxStorage;
    max_p.maxFunctionDefs := max_profile.maxFunctionDefs;
    max_p.maxInstructionDefs := max_profile.maxInstructionDefs;
    max_p.maxStackElements := max_profile.maxStackElements;
    max_p.maxSizeOfInstructions := max_profile.maxSizeOfInstructions;
    max_p.maxComponentElements := max_profile.maxComponentElements;
    max_p.maxComponentDepth := max_profile.maxComponentDepth;
    ChangeEndian;
    Result := offset + entry.length
end;

{ OS2WindowsMetricsClass }

function OS2WindowsMetricsClass.Get_AvgCharWidth: Smallint;
begin
  Result := win_metrix^.xAvgCharWidth;
end;

function OS2WindowsMetricsClass.Get_Ascent: Word;
begin
  Result := win_metrix^.usWinAscent;
end;

function OS2WindowsMetricsClass.Get_BreakChar: Word;
begin
  Result := win_metrix^.usBreakChar;
end;

function OS2WindowsMetricsClass.Get_DefaultChar: Word;
begin
  Result := win_metrix^.usDefaultChar;
end;

function OS2WindowsMetricsClass.Get_Descent: Word;
begin
  Result := win_metrix^.usWinDescent;
end;

function OS2WindowsMetricsClass.Get_FirstCharIndex: Word;
begin
  Result := win_metrix^.usFirstCharIndex;
end;

function OS2WindowsMetricsClass.Get_LastCharIndex: Word;
begin
  Result := win_metrix^.usLastCharIndex;
end;

function OS2WindowsMetricsClass.Get_panose: TPanoseArr;
begin
  Result := win_metrix^.Panose;
end;

constructor OS2WindowsMetricsClass.Create(src: TrueTypeTable);
begin
  inherited Create(src);
  win_metrix := AllocMem( SizeOf(OS2WindowsMetrics) );
end;

destructor OS2WindowsMetricsClass.Destroy;
begin
  FreeMem(win_metrix);
  inherited Destroy;
end;

procedure OS2WindowsMetricsClass.Load(font: Pointer);
var
   metrix: ^OS2WindowsMetrics;
 begin
     metrix := font + entry.offset ;
     win_metrix.Version := SwapEndian(metrix.Version);
     win_metrix.xAvgCharWidth := SwapEndian(metrix.xAvgCharWidth);
     win_metrix.usWeightClass := SwapEndian(metrix.usWeightClass);
     win_metrix.usWidthClass := SwapEndian(metrix.usWidthClass);
     win_metrix.fsType := SwapEndian(metrix.fsType);
     win_metrix.ySubscriptXSize := SwapEndian(metrix.ySubscriptXSize);
     win_metrix.ySubscriptYSize := SwapEndian(metrix.ySubscriptYSize);
     win_metrix.ySubscriptXOffset := SwapEndian(metrix.ySubscriptXOffset);
     win_metrix.ySubscriptYOffset := SwapEndian(metrix.ySubscriptYOffset);
     win_metrix.ySuperscriptXSize := SwapEndian(metrix.ySuperscriptXSize);
     win_metrix.ySuperscriptYSize := SwapEndian(metrix.ySuperscriptYSize);
     win_metrix.ySuperscriptXOffset := SwapEndian(metrix.ySuperscriptXOffset);
     win_metrix.ySuperscriptYOffset := SwapEndian(metrix.ySuperscriptYOffset);
     win_metrix.yStrikeoutSize := SwapEndian(metrix.yStrikeoutSize);
     win_metrix.yStrikeoutPosition := SwapEndian(metrix.yStrikeoutPosition);
     win_metrix.sFamilyClass := SwapEndian(metrix.sFamilyClass);
     win_metrix^.panose[0] := metrix^.panose[0];
     win_metrix^.panose[1] := metrix^.panose[1];
     win_metrix^.panose[2] := metrix^.panose[2];
     win_metrix^.panose[3] := metrix^.panose[3];
     win_metrix^.panose[4] := metrix^.panose[4];
     win_metrix^.panose[5] := metrix^.panose[5];
     win_metrix^.panose[6] := metrix^.panose[6];
     win_metrix^.panose[7] := metrix^.panose[7];
     win_metrix^.panose[8] := metrix^.panose[8];
     win_metrix^.panose[9] := metrix^.panose[9];

     win_metrix.ulUnicodeRange1 := SwapEndian(metrix.ulUnicodeRange1);
     win_metrix.ulUnicodeRange2 := SwapEndian(metrix.ulUnicodeRange2);
     win_metrix.ulUnicodeRange3 := SwapEndian(metrix.ulUnicodeRange3);
     win_metrix.ulUnicodeRange4 := SwapEndian(metrix.ulUnicodeRange4);
     win_metrix.fsSelection := SwapEndian(metrix.fsSelection);
     win_metrix.usFirstCharIndex := SwapEndian(metrix.usFirstCharIndex);
     win_metrix.usLastCharIndex := SwapEndian(metrix.usLastCharIndex);
     win_metrix.sTypoAscender := SwapEndian(metrix.sTypoAscender);
     win_metrix.sTypoDescender := SwapEndian(metrix.sTypoDescender);
     win_metrix.sTypoLineGap := SwapEndian(metrix.sTypoLineGap);
     win_metrix.usWinAscent := SwapEndian(metrix.usWinAscent);
     win_metrix.usWinDescent := SwapEndian(metrix.usWinDescent);
     win_metrix.ulCodePageRange1 := SwapEndian(metrix.ulCodePageRange1);
     win_metrix.ulCodePageRange1 := SwapEndian(metrix.ulCodePageRange2);
     win_metrix.sxHeight := SwapEndian(metrix.sxHeight);
     win_metrix.sCapHeight := SwapEndian(metrix.sCapHeight);
     win_metrix.usDefaultChar := SwapEndian(metrix.usDefaultChar);
     win_metrix.usBreakChar := SwapEndian(metrix.usBreakChar);
     win_metrix.usMaxContext := SwapEndian(metrix.usMaxContext);
 end;

function OS2WindowsMetricsClass.Save(font: Pointer; offset: Cardinal): Cardinal;
var
  metrix: ^OS2WindowsMetrics;
begin
    entry.offset := offset;
    metrix := font + entry.offset;
    metrix.Version := SwapEndian(win_metrix.Version);
    metrix.xAvgCharWidth := SwapEndian(win_metrix.xAvgCharWidth);
    metrix.usWeightClass :=SwapEndian(win_metrix.usWeightClass);
    metrix.usWidthClass := SwapEndian(win_metrix.usWidthClass);
    metrix.fsType := SwapEndian(win_metrix.fsType);
    metrix.ySubscriptXSize := SwapEndian(win_metrix.ySubscriptXSize);
    metrix.ySubscriptYSize := SwapEndian(win_metrix.ySubscriptYSize);
    metrix.ySubscriptXOffset := SwapEndian(win_metrix.ySubscriptXOffset);
    metrix.ySubscriptYOffset := SwapEndian(win_metrix.ySubscriptYOffset);
    metrix.ySuperscriptXSize := SwapEndian(win_metrix.ySuperscriptXSize);
    metrix.ySuperscriptYSize := SwapEndian(win_metrix.ySuperscriptYSize);
    metrix.ySuperscriptXOffset := SwapEndian(win_metrix.ySuperscriptXOffset);
    metrix.ySuperscriptYOffset := SwapEndian(win_metrix.ySuperscriptYOffset);
    metrix.yStrikeoutSize := SwapEndian(win_metrix.yStrikeoutSize);
    metrix.yStrikeoutPosition := SwapEndian(win_metrix.yStrikeoutPosition);
    metrix.sFamilyClass := SwapEndian(win_metrix.sFamilyClass);
    metrix^.panose[0] := win_metrix^.panose[0];
    metrix^.panose[1] := win_metrix^.panose[1];
    metrix^.panose[2] := win_metrix^.panose[2];
    metrix^.panose[3] := win_metrix^.panose[3];
    metrix^.panose[4] := win_metrix^.panose[4];
    metrix^.panose[5] := win_metrix^.panose[5];
    metrix^.panose[6] := win_metrix^.panose[6];
    metrix^.panose[7] := win_metrix^.panose[7];
    metrix^.panose[8] := win_metrix^.panose[8];
    metrix^.panose[9] := win_metrix^.panose[9];

    metrix.ulUnicodeRange1 := SwapEndian(win_metrix.ulUnicodeRange1);
    metrix.ulUnicodeRange2 := SwapEndian(win_metrix.ulUnicodeRange2);
    metrix.ulUnicodeRange3 := SwapEndian(win_metrix.ulUnicodeRange3);
    metrix.ulUnicodeRange4 := SwapEndian(win_metrix.ulUnicodeRange4);
    metrix.fsSelection := SwapEndian(win_metrix.fsSelection);
    metrix.usFirstCharIndex := SwapEndian(win_metrix.usFirstCharIndex);
    metrix.usLastCharIndex := SwapEndian(win_metrix.usLastCharIndex);
    metrix.sTypoAscender := SwapEndian(win_metrix.sTypoAscender);
    metrix.sTypoDescender := SwapEndian(win_metrix.sTypoDescender);
    metrix.sTypoLineGap := SwapEndian(win_metrix.sTypoLineGap);
    metrix.usWinAscent := SwapEndian(win_metrix.usWinAscent);
    metrix.usWinDescent := SwapEndian(win_metrix.usWinDescent);
    metrix.ulCodePageRange1 := SwapEndian(win_metrix.ulCodePageRange1);
    metrix.ulCodePageRange1 := SwapEndian(win_metrix.ulCodePageRange2);
    metrix.sxHeight := SwapEndian(win_metrix.sxHeight);
    metrix.sCapHeight := SwapEndian(win_metrix.sCapHeight);
    metrix.usDefaultChar := SwapEndian(win_metrix.usDefaultChar);
    metrix.usBreakChar := SwapEndian(win_metrix.usBreakChar);
    metrix.usMaxContext := SwapEndian(win_metrix.usMaxContext);
    Result := (offset + entry.length + 3) and $fffffffc;
end;

{ PreProgramClass }

constructor PreProgramClass.Create(src: TrueTypeTable);
begin
  inherited Create(src);
end;

procedure PreProgramClass.Load(font: Pointer);
var
  Tppr: ^Byte;
  i: Integer;
begin
  length := ((entry.length + 3) div 4) * 4;
  SetLength(pre_program, length);
  Tppr := font + self.entry.offset;
  for i := 0 to Length - 1 do
  begin
    pre_program[i] := Tppr^;
    Inc(Tppr);
  end;
end;

function PreProgramClass.Save(font: Pointer; offset: Cardinal): Cardinal;
var
  Tppr: ^Byte;
  i: Integer;
begin
  entry.offset := offset;
  Tppr := font + entry.offset;
  for i := 0 to Length - 1 do
  begin
    Tppr^ := pre_program[i];
    Inc(Tppr);
  end;
  Result := offset + Length;
end;




end.


object AdressForm: TAdressForm
  Left = 0
  Top = 0
  Caption = #1040#1076#1088#1077#1089
  ClientHeight = 149
  ClientWidth = 639
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label72: TLabel
    Left = 390
    Top = 92
    Width = 49
    Height = 13
    Caption = #1048#1085#1076#1077#1082#1089':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label70: TLabel
    Left = 408
    Top = 65
    Width = 31
    Height = 13
    Caption = #1044#1086#1084':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label71: TLabel
    Left = 511
    Top = 65
    Width = 61
    Height = 13
    Caption = #1050#1074#1072#1088#1090#1080#1088#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label69: TLabel
    Left = 397
    Top = 39
    Width = 42
    Height = 13
    Caption = #1059#1083#1080#1094#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label68: TLabel
    Left = 372
    Top = 12
    Width = 67
    Height = 13
    Caption = #1058#1080#1087' '#1091#1083#1080#1094#1099':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label54: TLabel
    Left = 17
    Top = 65
    Width = 116
    Height = 13
    Caption = #1053#1072#1089#1077#1083#1105#1085#1085#1099#1081' '#1087#1091#1085#1082#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label51: TLabel
    Left = 17
    Top = 39
    Width = 151
    Height = 13
    Caption = #1058#1080#1087' '#1085#1072#1089#1077#1083#1105#1085#1085#1086#1075#1086' '#1087#1091#1085#1082#1090#1072':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label48: TLabel
    Left = 17
    Top = 12
    Width = 41
    Height = 13
    Caption = #1056#1072#1081#1086#1085':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Type_streetDBLkCmbBx: TDBLookupComboBox
    Left = 445
    Top = 8
    Width = 182
    Height = 21
    DataField = 'TYPE_STREET'
    DataSource = DataModule1.DSAdress
    KeyField = 'ID'
    ListField = 'TYPE'
    ListSource = DataModule1.DSType_street
    TabOrder = 0
    OnCloseUp = Type_streetDBLkCmbBxCloseUp
    OnExit = Type_streetDBLkCmbBxExit
  end
  object StreetDBLkCmbBx: TDBLookupComboBox
    Left = 445
    Top = 35
    Width = 182
    Height = 21
    DataField = 'ID_STREET'
    DataSource = DataModule1.PeopleQSource
    KeyField = 'ID'
    ListField = 'NAME_IN_RUS'
    ListSource = DataModule1.DSStreet
    TabOrder = 1
  end
  object LocalityDBLkCmbBx: TDBLookupComboBox
    Left = 139
    Top = 62
    Width = 227
    Height = 21
    DataField = 'LOCAL_ID'
    DataSource = DataModule1.DSAdress
    KeyField = 'ID'
    ListField = 'NAME_LOCALITY'
    ListSource = DataModule1.DSLocality
    TabOrder = 2
    OnCloseUp = LocalityDBLkCmbBxCloseUp
    OnExit = LocalityDBLkCmbBxExit
    OnMouseDown = LocalityDBLkCmbBxMouseDown
  end
  object Type_localityDBLkCmbBx: TDBLookupComboBox
    Left = 184
    Top = 35
    Width = 182
    Height = 21
    DataField = 'N_TYPE'
    DataSource = DataModule1.DSAdress
    KeyField = 'N_TYPE'
    ListField = 'NAME_TYPE'
    ListSource = DataModule1.DSType_locality
    TabOrder = 3
    OnCloseUp = Type_localityDBLkCmbBxCloseUp
    OnExit = Type_localityDBLkCmbBxExit
    OnMouseDown = Type_localityDBLkCmbBxMouseDown
    OnMouseEnter = Type_localityDBLkCmbBxMouseEnter
  end
  object DistrictDBLkCmbBx: TDBLookupComboBox
    Left = 64
    Top = 8
    Width = 302
    Height = 21
    DataField = 'N_DISTRICT'
    DataSource = DataModule1.DSAdress
    KeyField = 'N_DISTRICT'
    ListField = 'NAME_DISTRICT'
    ListSource = DataModule1.DSDistrict
    TabOrder = 4
    OnCloseUp = DistrictDBLkCmbBxCloseUp
    OnMouseDown = DistrictDBLkCmbBxMouseDown
  end
  object DBEditHouse: TDBEdit
    Left = 445
    Top = 62
    Width = 45
    Height = 21
    DataField = 'HOUSE'
    DataSource = DataModule1.PeopleQSource
    TabOrder = 5
  end
  object DBEditFlat: TDBEdit
    Left = 578
    Top = 62
    Width = 49
    Height = 21
    DataField = 'FLAT'
    DataSource = DataModule1.PeopleQSource
    TabOrder = 6
  end
  object DBEditPostcode: TDBEdit
    Left = 445
    Top = 89
    Width = 65
    Height = 21
    DataField = 'POSTCODE'
    DataSource = DataModule1.PeopleQSource
    TabOrder = 7
  end
  object BitBtn1: TBitBtn
    Left = 552
    Top = 113
    Width = 75
    Height = 25
    Kind = bkOK
    NumGlyphs = 2
    TabOrder = 8
    OnClick = BitBtn1Click
  end
end

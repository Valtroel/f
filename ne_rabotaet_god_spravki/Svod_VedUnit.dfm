object Svod_Ved: TSvod_Ved
  Left = 302
  Top = 209
  Caption = #1057#1074#1086#1076#1085#1072#1103' '#1074#1077#1076#1086#1084#1086#1089#1090#1100
  ClientHeight = 167
  ClientWidth = 429
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 429
    Height = 120
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object Label4: TLabel
      Left = 7
      Top = 7
      Width = 59
      Height = 26
      Caption = #1060#1086#1088#1084#1072#13#10#1086#1073#1091#1095#1077#1085#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 7
      Top = 47
      Width = 46
      Height = 13
      Caption = #1043#1088#1091#1087#1087#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 7
      Top = 73
      Width = 148
      Height = 13
      Caption = #1044#1072#1090#1072' '#1074#1088#1091#1095#1077#1085#1080#1103' '#1076#1080#1087#1083#1086#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object ComboBox2: TComboBox
      Left = 78
      Top = 10
      Width = 98
      Height = 21
      Style = csDropDownList
      TabOrder = 0
      Items.Strings = (
        #1044#1085#1077#1074#1085#1072#1103
        #1047#1072#1086#1095#1085#1072#1103)
    end
    object Edit2: TEdit
      Left = 78
      Top = 43
      Width = 98
      Height = 21
      TabOrder = 1
    end
    object RadioGroup2: TRadioGroup
      Left = 269
      Top = 12
      Width = 132
      Height = 49
      Caption = #1057#1080#1089#1090#1077#1084#1072' '#1086#1094#1077#1085#1086#1082':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ItemIndex = 0
      Items.Strings = (
        '10 - '#1090#1080' '#1073#1072#1083#1100#1085#1072#1103
        ' 5  - '#1090#1080' '#1073#1072#1083#1100#1085#1072#1103)
      ParentFont = False
      TabOrder = 2
      OnClick = RadioGroup2Click
    end
    object DateTimePicker1: TDateTimePicker
      Left = 161
      Top = 67
      Width = 102
      Height = 21
      Date = 42648.455473981480000000
      Time = 42648.455473981480000000
      TabOrder = 3
      OnChange = DateTimePicker1Change
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 120
    Width = 429
    Height = 47
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    object BitBtn1: TBitBtn
      Left = 239
      Top = 9
      Width = 180
      Height = 27
      Cursor = crHandPoint
      Caption = #1042#1099#1093#1086#1076
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Kind = bkAbort
      NumGlyphs = 2
      ParentFont = False
      TabOrder = 1
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 21
      Top = 9
      Width = 180
      Height = 27
      Cursor = crHandPoint
      Caption = #1057#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100' '#1074' Excel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        4E010000424D4E01000000000000760000002800000012000000120000000100
        040000000000D800000000000000000000001000000010000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
        7777770000007777777777777777770000007777777777770007770000007444
        4400000006007700000074FFFF08880600080700000074F008000060EE070700
        000074FFFFF8060EE0047700000074F0088060EE00F47700000074FFFF060EE0
        00747700000074F00800EE0EE0047700000074FFFF0EE0F0EE047700000074F0
        080000F000047700000074FFFFFFFFFFFFF47700000074444444444444447700
        000074F444F444F444F477000000744444444444444477000000777777777777
        777777000000777777777777777777000000}
      ParentFont = False
      Spacing = 10
      TabOrder = 0
      OnClick = BitBtn2Click
    end
  end
end

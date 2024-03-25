object SpisokAllForm: TSpisokAllForm
  Left = 247
  Top = 167
  BorderIcons = [biSystemMenu, biMaximize]
  Caption = 'SpisokAllForm'
  ClientHeight = 285
  ClientWidth = 723
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poMainFormCenter
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 723
    Height = 89
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object RadioGroup2: TRadioGroup
      Left = 13
      Top = 8
      Width = 128
      Height = 70
      Caption = #1042#1080#1076' '#1086#1073#1091#1095#1077#1085#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        #1042#1089#1077
        #1044#1085#1077#1074#1085#1086#1077
        #1047#1072#1086#1095#1085#1086#1077)
      ParentFont = False
      TabOrder = 0
      OnClick = RadioGroup2Click
    end
    object RadioGroup3: TRadioGroup
      Left = 149
      Top = 8
      Width = 152
      Height = 70
      Caption = #1050#1091#1088#1089':'
      Columns = 3
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        '1'
        '2'
        '3'
        '4'
        '5'
        '6'
        #1042#1089#1077)
      ParentFont = False
      TabOrder = 1
      OnClick = RadioGroup2Click
    end
    object BitBtn1: TBitBtn
      Left = 568
      Top = 24
      Width = 121
      Height = 33
      Caption = #1042#1099#1087#1086#1083#1085#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        96010000424D9601000000000000760000002800000018000000180000000100
        0400000000002001000000000000000000001000000000000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        33333333333333338888888888888833333333000000000000000883333330BB
        BBBBBBBBBBBBB083333330B0000000000000B083333330B0F9FFFFFFFFF0B083
        333330B04444444444F0B033333330B0F9FFFFFFFFF0B393333330B0F9FFFFFF
        FFF0B399333330B044444444FFFFF399933330B0F9FFFFFFF9999999993330B0
        F9FFFFFFF9999999999330B044444444F9999999993330B0F9FFFFFFFFFFF399
        933330B0F9FFFFFFFFF0B399333330B04444444444F0B393333330B0F9FFFFFF
        FFF0B033333330B0F9FFFFFFFFF0B083333330B0F90000000FF0B083333330B0
        0007F7770000B083333330BBBBB07F70BBBBB033333333000000070000000333
        333333333330F770333333333333333333300000333333333333}
      ParentFont = False
      TabOrder = 2
      OnClick = BitBtn1Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 89
    Width = 723
    Height = 149
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    Visible = False
    object StringGrid1: TStringGrid
      Left = 2
      Top = 2
      Width = 719
      Height = 145
      Align = alClient
      FixedCols = 0
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goRowSizing, goColSizing, goRowMoving, goColMoving, goTabs]
      TabOrder = 0
      ColWidths = (
        268
        89
        89
        93
        82)
      RowHeights = (
        24
        24
        24
        24
        24)
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 238
    Width = 723
    Height = 47
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 2
    Visible = False
    object Label1: TLabel
      Left = 232
      Top = 16
      Width = 159
      Height = 16
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1079#1072#1087#1080#1089#1077#1081':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 406
      Top = 16
      Width = 5
      Height = 16
      Caption = ' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object BitBtn2: TBitBtn
      Left = 16
      Top = 6
      Width = 169
      Height = 33
      Caption = #1055#1077#1088#1077#1076#1072#1090#1100' '#1074' Excel'
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
      TabOrder = 0
      OnClick = BitBtn2Click
    end
  end
end

object NK_3Form: TNK_3Form
  Left = 345
  Top = 30
  BorderIcons = [biSystemMenu]
  Caption = 'NK_3Form'
  ClientHeight = 461
  ClientWidth = 784
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 784
    Height = 89
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object RadioGroup1: TRadioGroup
      Left = 16
      Top = 8
      Width = 140
      Height = 65
      Caption = #1060#1086#1088#1084#1072' '#1086#1073#1091#1095#1077#1085#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        #1044#1085#1077#1074#1085#1072#1103
        #1047#1072#1086#1095#1085#1072#1103)
      ParentFont = False
      TabOrder = 0
      OnClick = RadioGroup1Click
    end
    object RadioGroup2: TRadioGroup
      Left = 163
      Top = 8
      Width = 140
      Height = 65
      Caption = #1042#1099#1073#1086#1088' '#1087#1086' '#1082#1088#1080#1090#1077#1088#1080#1103#1084':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        #1055#1086' '#1092#1072#1082#1091#1083#1100#1090#1077#1090#1091
        #1055#1086' '#1082#1091#1088#1089#1072#1084)
      ParentFont = False
      TabOrder = 1
      OnClick = RadioGroup1Click
    end
    object BitBtn1: TBitBtn
      Left = 320
      Top = 8
      Width = 113
      Height = 33
      Hint = #1055#1086#1082#1072#1079#1072#1090#1100' '#1076#1072#1085#1085#1099#1077': '#1056#1072#1089#1087#1088#1077#1076#1077#1083#1077#1085#1080#1077' '#1089#1090#1091#1076#1077#1085#1090#1086#1074' '#1087#1086' '#1074#1086#1079#1088#1072#1089#1090#1091
      Caption = #1055#1086' '#1074#1086#1079#1088#1072#1089#1090#1091
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        66010000424D6601000000000000760000002800000014000000140000000100
        040000000000F000000000000000000000001000000000000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00774777771777
        7747777700007444444717444444777700007747777717777747777700007777
        7777177777777777000070000000000000007747000070788888078888807444
        000070F777780F7777807747000070F777780F7777807747000070F777780F77
        77807747000070F777780F7777807747000070FFFFF70FFFFF70777700007000
        0000000000001111000070788888078888807777000070F777780F7777807747
        000070F777780F7777807747000070F777780F7777807747000070F777780F77
        77807747000070FFFFF70FFFFF70744400007000000000000000774700007777
        77777777777777770000}
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      OnClick = BitBtn1Click
    end
    object BitBtn3: TBitBtn
      Left = 365
      Top = 48
      Width = 113
      Height = 33
      Hint = #1055#1086#1082#1072#1079#1072#1090#1100' '#1076#1072#1085#1085#1099#1077': '#1056#1072#1089#1087#1088#1077#1076#1077#1083#1077#1085#1080#1077' '#1089#1090#1091#1076#1077#1085#1090#1086#1074' '#1087#1086' '#1089#1087#1077#1094#1080#1072#1083#1100#1085#1086#1089#1090#1103#1084
      Caption = #1055#1086' '#1089#1087#1077#1094'-'#1090#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        66010000424D6601000000000000760000002800000014000000140000000100
        040000000000F000000000000000000000001000000000000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00774777771777
        7747777700007444444717444444777700007747777717777747777700007777
        7777177777777777000070000000000000007747000070788888078888807444
        000070F777780F7777807747000070F777780F7777807747000070F777780F77
        77807747000070F777780F7777807747000070FFFFF70FFFFF70777700007000
        0000000000001111000070788888078888807777000070F777780F7777807747
        000070F777780F7777807747000070F777780F7777807747000070F777780F77
        77807747000070FFFFF70FFFFF70744400007000000000000000774700007777
        77777777777777770000}
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 3
      OnClick = BitBtn3Click
    end
    object BitBtn4: TBitBtn
      Left = 442
      Top = 8
      Width = 116
      Height = 33
      Hint = #1055#1086#1082#1072#1079#1072#1090#1100' '#1076#1072#1085#1085#1099#1077': '#1056#1072#1089#1087#1088#1077#1076#1077#1083#1077#1085#1080#1077' '#1089#1090#1091#1076#1077#1085#1090#1086#1074' '#1087#1086' '#1092#1086#1088#1084#1077' '#1086#1087#1083#1072#1090#1099
      Caption = #1055#1086' '#1076#1086#1075#1086#1074#1086#1088#1091
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        66010000424D6601000000000000760000002800000014000000140000000100
        040000000000F000000000000000000000001000000000000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00774777771777
        7747777700007444444717444444777700007747777717777747777700007777
        7777177777777777000070000000000000007747000070788888078888807444
        000070F777780F7777807747000070F777780F7777807747000070F777780F77
        77807747000070F777780F7777807747000070FFFFF70FFFFF70777700007000
        0000000000001111000070788888078888807777000070F777780F7777807747
        000070F777780F7777807747000070F777780F7777807747000070F777780F77
        77807747000070FFFFF70FFFFF70744400007000000000000000774700007777
        77777777777777770000}
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 4
      OnClick = BitBtn4Click
    end
    object BitBtn5: TBitBtn
      Left = 487
      Top = 48
      Width = 113
      Height = 33
      Hint = #1055#1086#1082#1072#1079#1072#1090#1100' '#1076#1072#1085#1085#1099#1077': '#1056#1072#1089#1087#1088#1077#1076#1077#1083#1077#1085#1080#1077' '#1074#1099#1087#1091#1089#1082#1085#1080#1082#1086#1074' '#1087#1086' '#1089#1087#1077#1094#1080#1072#1083#1100#1085#1086#1089#1090#1103#1084
      Caption = #1042#1099#1087#1091#1089#1082#1085#1080#1082#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        66010000424D6601000000000000760000002800000014000000140000000100
        040000000000F000000000000000000000001000000000000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00774777771777
        7747777700007444444717444444777700007747777717777747777700007777
        7777177777777777000070000000000000007747000070788888078888807444
        000070F777780F7777807747000070F777780F7777807747000070F777780F77
        77807747000070F777780F7777807747000070FFFFF70FFFFF70777700007000
        0000000000001111000070788888078888807777000070F777780F7777807747
        000070F777780F7777807747000070F777780F7777807747000070F777780F77
        77807747000070FFFFF70FFFFF70744400007000000000000000774700007777
        77777777777777770000}
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 5
      OnClick = BitBtn5Click
    end
    object BitBtn6: TBitBtn
      Left = 542
      Top = 8
      Width = 113
      Height = 33
      Hint = 
        #1055#1086#1082#1072#1079#1072#1090#1100' '#1076#1072#1085#1085#1099#1077': '#1057#1090#1091#1076#1077#1085#1090#1099', '#1086#1073#1091#1095#1072#1102#1097#1080#1077#1089#1103' '#1085#1072' '#1091#1089#1083#1086#1074#1080#1103#1093' '#1094#1077#1083#1077#1074#1086#1081' '#1087#1086#1076#1075#1086 +
        #1090#1086#1074#1082#1080
      Caption = #1062#1077#1083#1077#1074#1080#1082#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        66010000424D6601000000000000760000002800000014000000140000000100
        040000000000F000000000000000000000001000000000000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00774777771777
        7747777700007444444717444444777700007747777717777747777700007777
        7777177777777777000070000000000000007747000070788888078888807444
        000070F777780F7777807747000070F777780F7777807747000070F777780F77
        77807747000070F777780F7777807747000070FFFFF70FFFFF70777700007000
        0000000000001111000070788888078888807777000070F777780F7777807747
        000070F777780F7777807747000070F777780F7777807747000070F777780F77
        77807747000070FFFFF70FFFFF70744400007000000000000000774700007777
        77777777777777770000}
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 6
      OnClick = BitBtn6Click
    end
    object BitBtn7: TBitBtn
      Left = 625
      Top = 48
      Width = 113
      Height = 33
      Hint = #1055#1086#1082#1072#1079#1072#1090#1100' '#1076#1072#1085#1085#1099#1077': '#1057#1090#1091#1076#1077#1085#1090#1099', '#1086#1073#1091#1095#1072#1102#1097#1080#1077#1089#1103' '#1087#1086' '#1089#1086#1082#1088#1072#1097#1077#1085#1085#1086#1081' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      Caption = #1042#1099#1073#1088#1072#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        66010000424D6601000000000000760000002800000014000000140000000100
        040000000000F000000000000000000000001000000000000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00774777771777
        7747777700007444444717444444777700007747777717777747777700007777
        7777177777777777000070000000000000007747000070788888078888807444
        000070F777780F7777807747000070F777780F7777807747000070F777780F77
        77807747000070F777780F7777807747000070FFFFF70FFFFF70777700007000
        0000000000001111000070788888078888807777000070F777780F7777807747
        000070F777780F7777807747000070F777780F7777807747000070F777780F77
        77807747000070FFFFF70FFFFF70744400007000000000000000774700007777
        77777777777777770000}
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 7
      OnClick = BitBtn7Click
    end
    object BitBtn8: TBitBtn
      Left = 662
      Top = 8
      Width = 113
      Height = 33
      Hint = #1055#1086#1082#1072#1079#1072#1090#1100' '#1076#1072#1085#1085#1099#1077': '#1057#1090#1091#1076#1077#1085#1090#1099', '#1086#1073#1091#1095#1072#1102#1097#1080#1077#1089#1103' '#1087#1086' '#1089#1086#1082#1088#1072#1097#1077#1085#1085#1086#1081' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
      Caption = #1055#1086' '#1085#1072#1087#1088#1072#1074#1083'.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        66010000424D6601000000000000760000002800000014000000140000000100
        040000000000F000000000000000000000001000000000000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00774777771777
        7747777700007444444717444444777700007747777717777747777700007777
        7777177777777777000070000000000000007747000070788888078888807444
        000070F777780F7777807747000070F777780F7777807747000070F777780F77
        77807747000070F777780F7777807747000070FFFFF70FFFFF70777700007000
        0000000000001111000070788888078888807777000070F777780F7777807747
        000070F777780F7777807747000070F777780F7777807747000070F777780F77
        77807747000070FFFFF70FFFFF70744400007000000000000000774700007777
        77777777777777770000}
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 8
      OnClick = BitBtn8Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 89
    Width = 784
    Height = 316
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    Visible = False
    object StringGrid1: TStringGrid
      Left = 2
      Top = 2
      Width = 780
      Height = 312
      Align = alClient
      ColCount = 11
      DefaultColWidth = 80
      RowCount = 11
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goColSizing]
      TabOrder = 0
      Visible = False
      ColWidths = (
        80
        80
        80
        80
        80
        80
        80
        80
        80
        80
        80)
      RowHeights = (
        24
        24
        24
        24
        24
        24
        24
        24
        24
        24
        24)
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 405
    Width = 784
    Height = 56
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 2
    Visible = False
    object BitBtn2: TBitBtn
      Left = 380
      Top = 12
      Width = 169
      Height = 33
      Hint = #1055#1077#1088#1077#1076#1072#1090#1100' '#1074#1099#1073#1088#1072#1085#1085#1099#1077' '#1076#1072#1085#1085#1099#1077' '#1074' Excel'
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
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnClick = BitBtn2Click
    end
    object CheckBox1: TCheckBox
      Left = 16
      Top = 20
      Width = 217
      Height = 17
      Caption = #1059#1095#1080#1090#1099#1074#1072#1090#1100' '#1087#1086#1083' '#1089#1090#1091#1076#1077#1085#1090#1072' ('#1052', '#1046')'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = CheckBox1Click
    end
  end
end
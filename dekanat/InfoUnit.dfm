object InfoForm: TInfoForm
  Left = 336
  Top = 173
  BorderIcons = [biSystemMenu]
  Caption = #1040#1074#1090#1086#1084#1072#1090#1080#1095#1077#1089#1082#1072#1103' '#1085#1091#1084#1077#1088#1072#1094#1080#1103' '#1079#1072#1095#1077#1090#1085#1099#1093' '#1082#1085#1080#1078#1077#1082
  ClientHeight = 315
  ClientWidth = 425
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 425
    Height = 224
    Align = alClient
    BevelInner = bvLowered
    TabOrder = 0
    object Label1: TLabel
      Left = 144
      Top = 93
      Width = 217
      Height = 13
      Caption = #1055#1086#1089#1083#1077#1076#1085#1080#1081' '#1085#1086#1084#1077#1088' '#1079#1072#1095#1077#1090#1085#1086#1081' '#1082#1085#1080#1078#1082#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label2: TLabel
      Left = 144
      Top = 120
      Width = 74
      Height = 13
      Caption = #1053#1072#1095#1072#1090#1100' '#1089' '#8470':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label3: TLabel
      Left = 144
      Top = 147
      Width = 208
      Height = 13
      Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1074#1099#1073#1088#1072#1085#1085#1099#1093' '#1089#1090#1091#1076#1077#1085#1090#1086#1074':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label4: TLabel
      Left = 376
      Top = 93
      Width = 39
      Height = 13
      Caption = 'Label4'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label5: TLabel
      Left = 376
      Top = 147
      Width = 39
      Height = 13
      Caption = 'Label5'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label6: TLabel
      Left = 144
      Top = 29
      Width = 133
      Height = 26
      Caption = #1042' '#1082#1072#1082#1086#1084' '#1091#1095#1077#1073#1085#1086#1084' '#1075#1086#1076#1091#13#10#1087#1086#1089#1090#1091#1087#1080#1083#1080' '#1089#1090#1091#1076#1077#1085#1090#1099':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object SpeedButton1: TSpeedButton
      Left = 376
      Top = 31
      Width = 23
      Height = 22
      Glyph.Data = {
        DE000000424DDE0000000000000076000000280000000D0000000D0000000100
        0400000000006800000074120000741200001000000000000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
        70007777077077777000777700700777700077770A00A077700000000AA0AA07
        70000AAAAAAA0AA070000AAAAAAAA0AA00000AAAAAAA0AA0700000000AA0AA07
        700077770A00A077700077770070077770007777077077777000777777777777
        7000}
      Visible = False
      OnClick = SpeedButton1Click
    end
    object RadioGroup1: TRadioGroup
      Left = 16
      Top = 16
      Width = 105
      Height = 49
      Caption = #1042#1080#1076' '#1086#1073#1091#1095#1077#1085#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        #1044#1085#1077#1074#1085#1086#1077
        #1047#1072#1086#1095#1085#1086#1077)
      ParentFont = False
      TabOrder = 0
      OnClick = RadioGroup1Click
    end
    object RadioGroup2: TRadioGroup
      Left = 16
      Top = 75
      Width = 105
      Height = 145
      Caption = #1042#1099#1073#1086#1088' '#1082#1091#1088#1089#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        '1 '#1082#1091#1088#1089
        '2 '#1082#1091#1088#1089
        '3 '#1082#1091#1088#1089
        '4 '#1082#1091#1088#1089
        '5 '#1082#1091#1088#1089)
      ParentFont = False
      TabOrder = 1
      Visible = False
      OnClick = RadioGroup2Click
    end
    object MaskEdit1: TMaskEdit
      Left = 289
      Top = 116
      Width = 44
      Height = 21
      EditMask = '\0\3\0000;_'
      MaxLength = 6
      TabOrder = 3
      Text = '030   '
      Visible = False
      OnExit = MaskEdit1Exit
    end
    object MaskEdit2: TMaskEdit
      Left = 289
      Top = 32
      Width = 33
      Height = 21
      EditMask = '!9999;1;_'
      MaxLength = 4
      TabOrder = 2
      Text = '    '
      Visible = False
      OnChange = MaskEdit2Change
    end
    object RadioGroup3: TRadioGroup
      Left = 144
      Top = 178
      Width = 257
      Height = 42
      Caption = #1055#1088#1086#1085#1091#1084#1077#1088#1086#1074#1072#1090#1100' '#1079#1072#1095#1077#1090#1082#1080' '#1089#1090#1091#1076#1077#1085#1090#1086#1074':'
      Columns = 2
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        #1042#1089#1077#1093
        #1042#1099#1073#1086#1088)
      ParentFont = False
      TabOrder = 4
      Visible = False
      OnClick = RadioGroup3Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 224
    Width = 425
    Height = 91
    Align = alBottom
    BevelInner = bvLowered
    TabOrder = 1
    object RadioGroup4: TRadioGroup
      Left = 6
      Top = 6
      Width = 419
      Height = 45
      Caption = #1055#1077#1088#1077#1076#1072#1090#1100' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1102' '#1074' MS Excel'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        #1042#1089#1077#1093' '#1089#1090#1091#1076#1077#1085#1090#1086#1074', '#1074#1099#1073#1088#1072#1085#1085#1086#1075#1086' '#1082#1091#1088#1089#1072
        #1058#1086#1083#1100#1082#1086' '#1089#1090#1091#1076#1077#1085#1090#1086#1074', '#1082#1086#1090#1086#1088#1099#1084' '#1089#1077#1081#1095#1072#1089' '#1076#1072#1083#1080' '#1085#1086#1084#1077#1088#1072' '#1079#1072#1095#1077#1090#1086#1082)
      ParentFont = False
      TabOrder = 2
      Visible = False
      OnClick = RadioGroup4Click
    end
    object BitBtn1: TBitBtn
      Left = 14
      Top = 13
      Width = 185
      Height = 30
      Caption = #1055#1088#1086#1085#1091#1084#1077#1088#1086#1074#1072#1090#1100' '#1079#1072#1095#1105#1090#1082#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        42010000424D4201000000000000760000002800000011000000110000000100
        040000000000CC00000000000000000000001000000010000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
        777770000000777770000000777770000000777770FFFFF07777700000007777
        70F111F0777770000000777770F1FFF0777770000000777770F111F077777000
        0000777770FFF1F0777770000000700000F11FF074477000000070FFF0FFFFF0
        74477000000070FF0000000077777000000070FF0FF0777774477000000070FF
        0FF0777774447000000070F00FF0777777744000000070FF0FF0777447744000
        000070FFFFF07774444440000000700000007777444470000000777777777777
        777770000000}
      ParentFont = False
      Spacing = 10
      TabOrder = 0
      Visible = False
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 230
      Top = 13
      Width = 185
      Height = 30
      Caption = #1055#1077#1088#1077#1076#1072#1090#1100' '#1074' Excel'
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
      TabOrder = 1
      Visible = False
      OnClick = BitBtn2Click
    end
    object BitBtn3: TBitBtn
      Left = 256
      Top = 57
      Width = 159
      Height = 25
      Caption = #1055#1077#1088#1077#1076#1072#1090#1100' '#1074' '#1058#1057#1054' '#1076#1072#1085#1085#1099#1077
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      Visible = False
      OnClick = BitBtn3Click
    end
  end
end

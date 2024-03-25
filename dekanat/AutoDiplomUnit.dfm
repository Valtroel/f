object AutoDiplomForm: TAutoDiplomForm
  Left = 201
  Top = 184
  BorderIcons = [biSystemMenu]
  Caption = #1040#1074#1090#1086#1084#1072#1090#1080#1095#1077#1089#1082#1072#1103' '#1075#1077#1085#1077#1088#1072#1094#1080#1103' '#1088#1077#1075#1080#1089#1090#1088#1072#1094#1080#1086#1085#1085#1086#1075#1086' '#1085#1086#1084#1077#1088#1072' '#1076#1080#1087#1083#1086#1084#1072
  ClientHeight = 299
  ClientWidth = 443
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
    Width = 443
    Height = 65
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object RadioGroup1: TRadioGroup
      Left = 16
      Top = 7
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
      Left = 144
      Top = 7
      Width = 105
      Height = 49
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        #1057#1087#1077#1094#1080#1072#1083#1080#1089#1090
        #1041#1072#1082#1072#1083#1072#1074#1088)
      ParentFont = False
      TabOrder = 1
      Visible = False
      OnClick = RadioGroup2Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 65
    Width = 443
    Height = 234
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    Visible = False
    object Label11: TLabel
      Left = 17
      Top = 163
      Width = 38
      Height = 13
      Caption = 'Label11'
      Visible = False
    end
    object Label12: TLabel
      Left = 326
      Top = 171
      Width = 94
      Height = 13
      Caption = #1074' '#1086#1090#1076#1077#1083#1100#1085#1091#1102' '#1082#1085#1080#1075#1091
    end
    object BitBtn1: TBitBtn
      Left = 14
      Top = 192
      Width = 185
      Height = 30
      Caption = #1057#1075#1077#1085#1077#1088#1080#1088#1086#1074#1072#1090#1100' '#1085#1086#1084#1077#1088
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
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 253
      Top = 190
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
      OnClick = BitBtn2Click
    end
    object Panel3: TPanel
      Left = 2
      Top = 2
      Width = 439
      Height = 145
      Align = alTop
      BevelInner = bvLowered
      TabOrder = 2
      object Label4: TLabel
        Left = 384
        Top = 40
        Width = 39
        Height = 13
        Caption = 'Label4'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label6: TLabel
        Left = 384
        Top = 64
        Width = 39
        Height = 13
        Caption = 'Label6'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label5: TLabel
        Left = 14
        Top = 64
        Width = 322
        Height = 13
        Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1076#1080#1087#1083#1086#1084#1086#1074' '#1073#1077#1079' '#1088#1077#1075#1080#1089#1090#1088#1072#1094#1080#1086#1085#1085#1086#1075#1086' '#1085#1086#1084#1077#1088#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label3: TLabel
        Left = 14
        Top = 40
        Width = 315
        Height = 13
        Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1076#1080#1087#1083#1086#1084#1086#1074' '#1089' '#1088#1077#1075#1080#1089#1090#1088#1072#1094#1080#1086#1085#1085#1099#1084' '#1085#1086#1084#1077#1088#1086#1084':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label2: TLabel
        Left = 384
        Top = 16
        Width = 39
        Height = 13
        Caption = 'Label2'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label1: TLabel
        Left = 14
        Top = 16
        Width = 264
        Height = 13
        Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1089#1090#1091#1076#1077#1085#1090#1086#1074' '#1085#1072' '#1074#1099#1087#1091#1089#1082#1085#1086#1084' '#1082#1091#1088#1089#1077':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label7: TLabel
        Left = 14
        Top = 88
        Width = 182
        Height = 13
        Caption = #1064#1072#1073#1083#1086#1085' '#1088#1077#1075#1080#1089#1090#1088#1072#1094#1080#1086#1085#1085#1086#1075#1086' '#1085#1086#1084#1077#1088#1072': '
      end
      object Label8: TLabel
        Left = 14
        Top = 112
        Width = 156
        Height = 13
        Caption = #1043#1077#1085#1077#1088#1072#1094#1080#1103' '#1085#1072#1095#1085#1077#1090#1089#1103' '#1089' '#1085#1086#1084#1077#1088#1072':'
      end
      object Label9: TLabel
        Left = 232
        Top = 88
        Width = 32
        Height = 13
        Caption = 'Label9'
      end
      object Label10: TLabel
        Left = 232
        Top = 112
        Width = 38
        Height = 13
        Caption = 'Label10'
      end
    end
    object CheckBox1: TCheckBox
      Left = 307
      Top = 156
      Width = 131
      Height = 17
      Caption = #1044#1080#1087#1083#1086#1084#1099' '#1089' '#1086#1090#1083#1080#1095#1080#1077#1084
      TabOrder = 3
    end
  end
end

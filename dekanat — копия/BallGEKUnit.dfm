object Ball_GEK: TBall_GEK
  Left = 398
  Top = 279
  BorderIcons = [biSystemMenu]
  Caption = #1055#1088#1086#1089#1090#1072#1074#1090#1077' '#1086#1094#1077#1085#1082#1091' '#1087#1086' '#1043#1086#1089'. '#1101#1082#1079#1072#1084#1077#1085#1091' '#1080#1083#1080' '#1076#1080#1087#1083#1086#1084#1091
  ClientHeight = 294
  ClientWidth = 416
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 416
    Height = 294
    Align = alClient
    TabOrder = 0
    object Label1: TLabel
      Left = 13
      Top = 112
      Width = 99
      Height = 13
      Caption = #1042#1074#1077#1076#1080#1090#1077' '#1086#1094#1077#1085#1082#1091':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 8
      Top = 264
      Width = 91
      Height = 13
      Caption = #1058#1077#1084#1072' '#1076#1080#1087#1083#1086#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -9
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object DBText1: TDBText
      Left = 13
      Top = 13
      Width = 203
      Height = 14
      DataField = 'FAM'
      DataSource = DM3.GEKResultSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText2: TDBText
      Left = 13
      Top = 33
      Width = 203
      Height = 13
      DataField = 'NAME'
      DataSource = DM3.GEKResultSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText3: TDBText
      Left = 13
      Top = 52
      Width = 203
      Height = 14
      DataField = 'OTCH'
      DataSource = DM3.GEKResultSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object RadioGroup1: TRadioGroup
      Left = 8
      Top = 126
      Width = 273
      Height = 107
      Columns = 2
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        #1053#1077#1091#1076#1086#1074#1083'.'
        #1059#1076#1086#1074#1083'.'
        #1061#1086#1088#1086#1096#1086
        #1054#1090#1083#1080#1095#1085#1086
        #1053#1077' '#1103#1074#1080#1083#1089#1103)
      ParentFont = False
      TabOrder = 2
    end
    object BitBtn1: TBitBtn
      Left = 305
      Top = 187
      Width = 105
      Height = 28
      Cursor = crHandPoint
      Hint = #1057#1086#1093#1088#1072#1085#1077#1085#1080#1077' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1072' '#1076#1083#1103#13#10#1074#1099#1073#1088#1072#1085#1085#1086#1075#1086' '#1089#1090#1091#1076#1077#1085#1090#1072
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        EE000000424DEE000000000000007600000028000000100000000F0000000100
        0400000000007800000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FF0000000000
        000FF0EE000000880E0FF0EE000000880E0FF0EE000000880E0FF0EE00000000
        0E0FF0EEEEEEEEEEEE0FF0EE00000000EE0FF0E0888888880E0FF0E088888888
        0E0FF0E0888888880E0FF0E0888888880E0FF0E088888888000FF0E088888888
        0F0FF00000000000000FFFFFFFFFFFFFFFFF}
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 4
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 305
      Top = 9
      Width = 105
      Height = 27
      Cursor = crHandPoint
      Caption = #1047#1072#1082#1088#1099#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Kind = bkCancel
      NumGlyphs = 2
      ParentFont = False
      TabOrder = 6
      OnClick = BitBtn2Click
    end
    object DBNavigator1: TDBNavigator
      Left = 306
      Top = 144
      Width = 104
      Height = 20
      Cursor = crHandPoint
      DataSource = DM3.GEKResultSource
      VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
      Flat = True
      Ctl3D = True
      Hints.Strings = (
        #1050' '#1087#1077#1088#1074#1086#1084#1091' '#1089#1090#1091#1076#1077#1085#1090#1091
        #1050' '#1087#1088#1077#1076#1099#1076#1091#1097#1077#1084#1091' '#1089#1090#1091#1076#1077#1085#1090#1091
        #1050' '#1089#1083#1077#1076#1091#1102#1097#1077#1084#1091' '#1089#1090#1091#1076#1077#1085#1090#1091
        #1050' '#1087#1086#1089#1083#1077#1076#1085#1077#1084#1091' '#1089#1090#1091#1076#1077#1085#1090#1091)
      ParentCtl3D = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 5
      OnClick = DBNavigator1Click
    end
    object RadioButton1: TRadioButton
      Left = 13
      Top = 75
      Width = 113
      Height = 17
      Caption = #1043#1086#1089'. '#1101#1082#1079#1072#1084#1077#1085
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = RadioButton1Click
    end
    object RadioButton2: TRadioButton
      Left = 141
      Top = 75
      Width = 113
      Height = 17
      Caption = #1044#1080#1087#1083#1086#1084
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = RadioButton2Click
    end
    object Memo1: TMemo
      Left = 104
      Top = 243
      Width = 307
      Height = 57
      Lines.Strings = (
        '')
      TabOrder = 3
      Visible = False
    end
    object RadioGroup2: TRadioGroup
      Left = 280
      Top = 75
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
      TabOrder = 7
      OnClick = RadioGroup2Click
    end
  end
end

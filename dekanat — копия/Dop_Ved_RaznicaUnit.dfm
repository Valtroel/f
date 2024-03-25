object Dop_Ved_RaznicaForm: TDop_Ved_RaznicaForm
  Left = 265
  Top = 163
  BorderIcons = [biSystemMenu]
  ClientHeight = 408
  ClientWidth = 557
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 557
    Height = 57
    Align = alTop
    BevelInner = bvLowered
    TabOrder = 0
    object Label7: TLabel
      Left = 10
      Top = 32
      Width = 61
      Height = 13
      Caption = #1060#1072#1084#1080#1083#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label12: TLabel
      Left = 10
      Top = 8
      Width = 250
      Height = 13
      Caption = #1042#1099#1073#1086#1088' '#1089#1090#1091#1076#1077#1085#1090#1072' '#1076#1083#1103' '#1083#1080#1082#1074#1080#1076#1072#1094#1080#1080' '#1088#1072#1079#1085#1080#1094#1099
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBLookupComboBox1: TDBLookupComboBox
      Left = 117
      Top = 28
      Width = 440
      Height = 21
      KeyField = 'NOMER'
      ListField = 'FIO'
      ListSource = DataModule1.Ved_Raznica_People_CaseSource
      TabOrder = 0
      OnCloseUp = DBLookupComboBox1CloseUp
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 57
    Width = 557
    Height = 262
    Align = alClient
    BevelInner = bvLowered
    TabOrder = 1
    Visible = False
    object Label1: TLabel
      Left = 9
      Top = 6
      Width = 85
      Height = 13
      Caption = #8470' '#1074#1077#1076#1086#1084#1086#1089#1090#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label8: TLabel
      Left = 10
      Top = 25
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
    object Label9: TLabel
      Left = 10
      Top = 93
      Width = 81
      Height = 13
      Alignment = taCenter
      Caption = #1059#1095#1077#1073#1085#1099#1081' '#1075#1086#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label10: TLabel
      Left = 162
      Top = 85
      Width = 16
      Height = 29
      Caption = #8212
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -25
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 10
      Top = 63
      Width = 56
      Height = 13
      Caption = #1057#1077#1084#1077#1089#1090#1088':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 10
      Top = 117
      Width = 78
      Height = 26
      Caption = #1044#1072#1090#1072' '#1074#1099#1076#1072#1095#1080#13#10#1074#1077#1076#1086#1084#1086#1089#1090#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 212
      Top = 117
      Width = 112
      Height = 26
      Caption = #1042#1077#1076#1086#1084#1086#1089#1090#1100#13#10#1076#1077#1081#1089#1090#1074#1080#1090#1077#1083#1100#1085#1072' '#1076#1086':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 10
      Top = 156
      Width = 84
      Height = 13
      Caption = #1069#1082#1079#1072#1084#1077#1085#1072#1090#1086#1088':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label11: TLabel
      Left = 116
      Top = 4
      Width = 56
      Height = 16
      Caption = 'Label11'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label15: TLabel
      Left = 10
      Top = 181
      Width = 103
      Height = 26
      Caption = #1050#1091#1088#1089' '#1083#1080#1082#1074#1080#1076#1072#1094#1080#1080#13#10#1088#1072#1079#1085#1080#1094#1099':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ComboBox2: TComboBox
      Left = 117
      Top = 28
      Width = 118
      Height = 21
      Style = csDropDownList
      TabOrder = 0
      Items.Strings = (
        #1044#1085#1077#1074#1085#1086#1077
        #1047#1072#1086#1095#1085#1086#1077)
    end
    object Edit5: TEdit
      Left = 117
      Top = 89
      Width = 41
      Height = 21
      TabOrder = 2
      OnExit = Edit5Exit
    end
    object Edit6: TEdit
      Left = 182
      Top = 89
      Width = 41
      Height = 21
      TabOrder = 3
    end
    object Edit3: TEdit
      Left = 117
      Top = 59
      Width = 40
      Height = 21
      TabOrder = 1
      OnExit = Edit3Exit
      OnKeyPress = Edit3KeyPress
    end
    object Edit1: TEdit
      Left = 117
      Top = 120
      Width = 65
      Height = 21
      ReadOnly = True
      TabOrder = 4
      OnClick = Edit1Click
    end
    object Edit2: TEdit
      Left = 335
      Top = 120
      Width = 65
      Height = 21
      ReadOnly = True
      TabOrder = 5
      OnClick = Edit2Click
    end
    object Panel5: TPanel
      Left = 10
      Top = 225
      Width = 121
      Height = 27
      Cursor = crHandPoint
      Caption = #1042#1099#1073#1088#1072#1090#1100' '#1087#1088#1077#1076#1084#1077#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 7
      OnClick = Panel5Click
    end
    object Edit8: TEdit
      Left = 117
      Top = 184
      Width = 40
      Height = 21
      ReadOnly = True
      TabOrder = 8
      OnKeyPress = Edit3KeyPress
    end
    object Edit7: TEdit
      Left = 117
      Top = 152
      Width = 157
      Height = 21
      TabOrder = 6
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 355
    Width = 557
    Height = 53
    Align = alBottom
    BevelInner = bvLowered
    TabOrder = 3
    Visible = False
    object BitBtn2: TBitBtn
      Left = 120
      Top = 10
      Width = 105
      Height = 34
      Cursor = crHandPoint
      Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074#1077#1076#1086#1084#1086#1089#1090#1100
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -9
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
      TabOrder = 0
      OnClick = BitBtn2Click
    end
    object BitBtn1: TBitBtn
      Left = 352
      Top = 10
      Width = 105
      Height = 34
      Cursor = crHandPoint
      Hint = #1047#1072#1082#1088#1099#1090#1100' '#1076#1072#1085#1085#1091#1102' '#1092#1086#1088#1084#1091
      Caption = #1054#1090#1084#1077#1085#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -9
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Kind = bkClose
      NumGlyphs = 2
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      OnClick = BitBtn1Click
    end
  end
  object Panel4: TPanel
    Left = 0
    Top = 319
    Width = 557
    Height = 36
    Align = alBottom
    BevelInner = bvLowered
    TabOrder = 2
    Visible = False
    object Label6: TLabel
      Left = 10
      Top = 12
      Width = 78
      Height = 13
      Caption = #1044#1080#1089#1094#1080#1087#1083#1080#1085#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ComboBox1: TComboBox
      Left = 117
      Top = 8
      Width = 440
      Height = 21
      TabOrder = 0
    end
  end
end

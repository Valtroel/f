object Vipusk_Stud: TVipusk_Stud
  Left = 369
  Top = 325
  BorderIcons = [biSystemMenu]
  Caption = #1042#1099#1087#1091#1089#1082' '#1089#1090#1091#1076#1077#1085#1090#1086#1074
  ClientHeight = 323
  ClientWidth = 528
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 276
    Width = 528
    Height = 47
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    Visible = False
    object BitBtn1: TBitBtn
      Left = 410
      Top = 9
      Width = 107
      Height = 30
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
      Left = 27
      Top = 9
      Width = 180
      Height = 30
      Cursor = crHandPoint
      Caption = #1042#1099#1087#1091#1089#1090#1080#1090#1100' '#1089#1090#1091#1076#1077#1085#1090#1086#1074
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        7E010000424D7E01000000000000760000002800000018000000160000000100
        0400000000000801000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00800000000000
        0000000000080777777777777777777777700F77777777777777777777700F88
        888888888888888887700F88888880000088888887700F8888800FFFFF008888
        87700F88880FFFFFFFFF088887700F8880FFFFFFFFFFF08887700F8880FF0FFF
        FFFFF08887700F880FFFF0FFFFFFFF0887700F880FFFFF0FFFFFFF0887700F88
        0FFFFFF000000F0887700F880FFFFFFFFFFFFF0887700F880FFFFFFFFFFFFF08
        87700F8880FFFFFFFFFFF08887700F8880FFFFFFFFFFF08887700F88880FFFF0
        FFFF088887700F8888800FFFFF00888887700F88888880000088888887700F88
        888888888888888887700FFFFFFFFFFFFFFFFFFFFF7080000000000000000000
        0008}
      ParentFont = False
      Spacing = 10
      TabOrder = 0
      OnClick = BitBtn2Click
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 528
    Height = 276
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    object Label4: TLabel
      Left = 7
      Top = 6
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
    object Label1: TLabel
      Left = 16
      Top = 120
      Width = 64
      Height = 13
      Caption = #1042#1085#1080#1084#1072#1085#1080#1077'!'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 16
      Top = 133
      Width = 158
      Height = 39
      Caption = 
        #1055#1086#1089#1083#1077' '#1074#1099#1087#1091#1089#1082#1072' '#1089#1090#1091#1076#1077#1085#1090#1086#1074#13#10#1087#1088#1086#1089#1084#1086#1090#1088#1077#1090#1100' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1102#13#10#1087#1086' '#1089#1090#1091#1076#1077#1085#1090#1091' '#1084#1086#1078 +
        #1085#1086' '#1073#1091#1076#1077#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 16
      Top = 172
      Width = 42
      Height = 13
      Caption = #1090#1086#1083#1100#1082#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 16
      Top = 185
      Width = 186
      Height = 13
      Caption = #1074' '#1089#1090#1091#1076#1077#1085#1095#1077#1089#1082#1086#1084' '#1086#1090#1076#1077#1083#1077' '#1082#1072#1076#1088#1086#1074
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ComboBox1: TComboBox
      Left = 78
      Top = 10
      Width = 139
      Height = 21
      Style = csDropDownList
      TabOrder = 0
      OnChange = ComboBox1Change
      Items.Strings = (
        #1044#1085#1077#1074#1085#1072#1103
        #1047#1072#1086#1095#1085#1072#1103)
    end
    object ProgressBar1: TProgressBar
      Left = 2
      Top = 258
      Width = 524
      Height = 16
      Align = alBottom
      TabOrder = 1
      Visible = False
    end
    object BitBtn31: TBitBtn
      Left = 78
      Top = 86
      Width = 139
      Height = 27
      Cursor = crHandPoint
      Caption = #1042#1099#1073#1088#1072#1090#1100' '#1089#1090#1091#1076#1077#1085#1090#1086#1074
      Default = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      OnClick = BitBtn31Click
    end
    object ListBox1: TListBox
      Left = 224
      Top = 2
      Width = 302
      Height = 256
      Align = alRight
      ItemHeight = 13
      TabOrder = 3
      Visible = False
    end
    object RadioGroup17: TRadioGroup
      Left = 8
      Top = 40
      Width = 209
      Height = 41
      Columns = 2
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -10
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        #1057#1087#1077#1094#1080#1072#1083#1080#1089#1090
        #1041#1072#1082#1072#1083#1072#1074#1088)
      ParentFont = False
      TabOrder = 4
      Visible = False
    end
  end
end

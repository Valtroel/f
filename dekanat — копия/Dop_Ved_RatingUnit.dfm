object Dop_Ved_RatingForm: TDop_Ved_RatingForm
  Left = 342
  Top = 320
  BorderIcons = [biSystemMenu]
  Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1074#1077#1076#1086#1084#1086#1089#1090#1080' '#1088#1077#1081#1090#1080#1085#1075#1072
  ClientHeight = 291
  ClientWidth = 467
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
  object Panel4: TPanel
    Left = 0
    Top = 241
    Width = 467
    Height = 50
    Align = alBottom
    BevelInner = bvLowered
    TabOrder = 0
    object BitBtn1: TBitBtn
      Left = 54
      Top = 10
      Width = 105
      Height = 33
      Cursor = crHandPoint
      Caption = 'OK'
      Default = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        DE010000424DDE01000000000000760000002800000024000000120000000100
        0400000000006801000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333333333330000333333333333333333333333F33333333333
        00003333344333333333333333388F3333333333000033334224333333333333
        338338F3333333330000333422224333333333333833338F3333333300003342
        222224333333333383333338F3333333000034222A22224333333338F338F333
        8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
        33333338F83338F338F33333000033A33333A222433333338333338F338F3333
        0000333333333A222433333333333338F338F33300003333333333A222433333
        333333338F338F33000033333333333A222433333333333338F338F300003333
        33333333A222433333333333338F338F00003333333333333A22433333333333
        3338F38F000033333333333333A223333333333333338F830000333333333333
        333A333333333333333338330000333333333333333333333333333333333333
        0000}
      NumGlyphs = 2
      ParentFont = False
      TabOrder = 0
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 295
      Top = 10
      Width = 105
      Height = 33
      Cursor = crHandPoint
      Caption = #1054#1090#1084#1077#1085#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Kind = bkClose
      NumGlyphs = 2
      ParentFont = False
      TabOrder = 1
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 467
    Height = 241
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    object Label1: TLabel
      Left = 19
      Top = 15
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
    object Label4: TLabel
      Left = 143
      Top = 13
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
    object Label3: TLabel
      Left = 19
      Top = 75
      Width = 63
      Height = 13
      Caption = #8470' '#1075#1088#1091#1087#1087#1099':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label7: TLabel
      Left = 19
      Top = 46
      Width = 105
      Height = 13
      Caption = #1060#1086#1088#1084#1072' '#1086#1073#1091#1095#1077#1085#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label8: TLabel
      Left = 19
      Top = 133
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
      Left = 19
      Top = 104
      Width = 68
      Height = 13
      Caption = #1055#1086#1083#1091#1075#1086#1076#1080#1077':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 19
      Top = 157
      Width = 174
      Height = 26
      Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1089#1087#1077#1094#1080#1072#1083#1100#1085#1086#1089#1090#1080#13#10'('#1089#1087#1077#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103')'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label6: TLabel
      Left = 19
      Top = 217
      Width = 53
      Height = 13
      Caption = #1050#1091#1088#1072#1090#1086#1088':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label9: TLabel
      Left = 19
      Top = 188
      Width = 82
      Height = 13
      Caption = #1044#1072#1090#1072' '#1074#1099#1076#1072#1095#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label10: TLabel
      Left = 265
      Top = 188
      Width = 73
      Height = 13
      Caption = #1044#1072#1090#1072' '#1089#1076#1072#1095#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Edit2: TEdit
      Left = 143
      Top = 71
      Width = 40
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnExit = Edit2Exit
    end
    object ComboBox2: TComboBox
      Left = 143
      Top = 42
      Width = 118
      Height = 21
      Style = csDropDownList
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ItemIndex = 0
      ParentFont = False
      TabOrder = 0
      Text = #1044#1085#1077#1074#1085#1086#1077
      Items.Strings = (
        #1044#1085#1077#1074#1085#1086#1077
        #1047#1072#1086#1095#1085#1086#1077)
    end
    object Edit3: TEdit
      Left = 143
      Top = 129
      Width = 40
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
    object Edit1: TEdit
      Left = 143
      Top = 100
      Width = 40
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnExit = Edit1Exit
    end
    object CheckBox2: TCheckBox
      Left = 19
      Top = 242
      Width = 330
      Height = 17
      Caption = #1057#1072#1084#1086#1089#1090#1086#1103#1090#1077#1083#1100#1085#1086' '#1074#1099#1073#1088#1072#1090#1100' '#1089#1090#1091#1076#1077#1085#1090#1086#1074' '#1074' '#1074#1077#1076#1086#1084#1086#1089#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
    end
    object Edit4: TEdit
      Left = 143
      Top = 213
      Width = 311
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
    end
    object ComboBox1: TComboBox
      Left = 205
      Top = 157
      Width = 249
      Height = 21
      Style = csDropDownList
      TabOrder = 4
    end
    object DateTimePicker1: TDateTimePicker
      Left = 107
      Top = 186
      Width = 101
      Height = 21
      Date = 42675.420516446760000000
      Time = 42675.420516446760000000
      TabOrder = 7
      OnChange = DateTimePicker1Change
    end
    object DateTimePicker2: TDateTimePicker
      Left = 344
      Top = 186
      Width = 101
      Height = 21
      Date = 42675.420516446760000000
      Time = 42675.420516446760000000
      TabOrder = 8
      OnChange = DateTimePicker2Change
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 467
    Height = 241
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 2
    Visible = False
    object Label11: TLabel
      Left = 19
      Top = 15
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
    object Label12: TLabel
      Left = 143
      Top = 46
      Width = 46
      Height = 13
      Caption = 'Label12'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label13: TLabel
      Left = 19
      Top = 75
      Width = 63
      Height = 13
      Caption = #8470' '#1075#1088#1091#1087#1087#1099':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label14: TLabel
      Left = 19
      Top = 46
      Width = 105
      Height = 13
      Caption = #1060#1086#1088#1084#1072' '#1086#1073#1091#1095#1077#1085#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label15: TLabel
      Left = 19
      Top = 133
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
    object Label16: TLabel
      Left = 19
      Top = 104
      Width = 68
      Height = 13
      Caption = #1055#1086#1083#1091#1075#1086#1076#1080#1077':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label17: TLabel
      Left = 19
      Top = 157
      Width = 174
      Height = 26
      Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1089#1087#1077#1094#1080#1072#1083#1100#1085#1086#1089#1090#1080#13#10'('#1089#1087#1077#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103')'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label18: TLabel
      Left = 19
      Top = 217
      Width = 53
      Height = 13
      Caption = #1050#1091#1088#1072#1090#1086#1088':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label19: TLabel
      Left = 19
      Top = 188
      Width = 82
      Height = 13
      Caption = #1044#1072#1090#1072' '#1074#1099#1076#1072#1095#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label20: TLabel
      Left = 265
      Top = 188
      Width = 73
      Height = 13
      Caption = #1044#1072#1090#1072' '#1089#1076#1072#1095#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText1: TDBText
      Left = 143
      Top = 15
      Width = 65
      Height = 17
      DataField = 'N_VEDOMOST_R'
      DataSource = DataModule1.Rating_GridSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText2: TDBText
      Left = 143
      Top = 73
      Width = 65
      Height = 17
      DataField = 'N_GROUP'
      DataSource = DataModule1.Rating_GridSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText3: TDBText
      Left = 143
      Top = 102
      Width = 65
      Height = 17
      DataField = 'SESSION'
      DataSource = DataModule1.Rating_GridSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText4: TDBText
      Left = 143
      Top = 131
      Width = 65
      Height = 17
      DataField = 'SEMESTR'
      DataSource = DataModule1.Rating_GridSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText5: TDBText
      Left = 205
      Top = 157
      Width = 65
      Height = 17
      DataField = 'SPECIAL'
      DataSource = DataModule1.Rating_GridSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Edit8: TEdit
      Left = 143
      Top = 213
      Width = 311
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object DateTimePicker3: TDateTimePicker
      Left = 107
      Top = 184
      Width = 92
      Height = 21
      Date = 42675.421122337960000000
      Time = 42675.421122337960000000
      TabOrder = 1
      OnChange = DateTimePicker3Change
    end
    object DateTimePicker4: TDateTimePicker
      Left = 344
      Top = 184
      Width = 92
      Height = 21
      Date = 42675.421122337960000000
      Time = 42675.421122337960000000
      TabOrder = 2
      OnChange = DateTimePicker4Change
    end
  end
end

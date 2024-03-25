object Ball_LikvidForm: TBall_LikvidForm
  Left = 317
  Top = 273
  BorderIcons = [biSystemMenu]
  Caption = 'Ball_LikvidForm'
  ClientHeight = 441
  ClientWidth = 495
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = RadioGroup2Click
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 495
    Height = 273
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object Label1: TLabel
      Left = 9
      Top = 11
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
      Top = 30
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
      Top = 68
      Width = 64
      Height = 13
      Alignment = taCenter
      Caption = #1047#1072' '#1091#1095'. '#1075#1086#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 10
      Top = 93
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
      Left = 263
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
    object Label6: TLabel
      Left = 10
      Top = 219
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
    object Label7: TLabel
      Left = 10
      Top = 243
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
    object DBText1: TDBText
      Left = 146
      Top = 11
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'N_VEDOMOST'
      DataSource = DataModule1.Ved_LikvidGridSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText2: TDBText
      Left = 146
      Top = 37
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'VID_EDU_PLAN1'
      DataSource = DataModule1.Ved_LikvidGridSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText3: TDBText
      Left = 146
      Top = 93
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'SEMESTR_VED'
      DataSource = DataModule1.Ved_LikvidGridSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText4: TDBText
      Left = 146
      Top = 188
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'KURS'
      DataSource = DataModule1.Ved_LikvidGridSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText5: TDBText
      Left = 146
      Top = 219
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'NAME_OBJECT'
      DataSource = DataModule1.Ved_LikvidGridSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText6: TDBText
      Left = 146
      Top = 243
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'FIO'
      DataSource = DataModule1.Ved_LikvidGridSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label10: TLabel
      Left = 146
      Top = 68
      Width = 46
      Height = 13
      Caption = 'Label10'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Edit3: TEdit
      Left = 146
      Top = 152
      Width = 157
      Height = 21
      TabOrder = 0
    end
    object DateTimePicker1: TDateTimePicker
      Left = 104
      Top = 125
      Width = 88
      Height = 21
      Date = 42671.413530682870000000
      Time = 42671.413530682870000000
      TabOrder = 1
      OnChange = DateTimePicker1Change
    end
    object DateTimePicker2: TDateTimePicker
      Left = 392
      Top = 122
      Width = 87
      Height = 21
      Date = 42671.413747870370000000
      Time = 42671.413747870370000000
      TabOrder = 2
      OnChange = DateTimePicker2Change
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 273
    Width = 495
    Height = 120
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    Visible = False
    ExplicitHeight = 104
    object Label11: TLabel
      Left = 10
      Top = 11
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
    object Label12: TLabel
      Left = 315
      Top = 86
      Width = 73
      Height = 13
      Caption = #1044#1072#1090#1072' '#1089#1076#1072#1095#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -9
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object RadioGroup2: TRadioGroup
      Left = 360
      Top = 18
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
      TabOrder = 0
      OnClick = RadioGroup2Click
    end
    object RadioGroup1: TRadioGroup
      Left = 10
      Top = 26
      Width = 217
      Height = 81
      Columns = 2
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
    end
    object DateTimePicker3: TDateTimePicker
      Left = 394
      Top = 77
      Width = 84
      Height = 21
      Date = 42671.414023298610000000
      Time = 42671.414023298610000000
      TabOrder = 2
      OnChange = DateTimePicker3Change
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 393
    Width = 495
    Height = 48
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 2
    ExplicitTop = 377
    object BitBtn1: TBitBtn
      Left = 104
      Top = 8
      Width = 105
      Height = 33
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Kind = bkOK
      NumGlyphs = 2
      ParentFont = False
      TabOrder = 0
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 301
      Top = 8
      Width = 105
      Height = 33
      Caption = #1047#1072#1082#1088#1099#1090#1100
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
end

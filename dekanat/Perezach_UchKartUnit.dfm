object Perezach_UchKartForm: TPerezach_UchKartForm
  Left = 444
  Top = 209
  BorderIcons = [biSystemMenu]
  Caption = #1055#1077#1088#1077#1079#1072#1095#1077#1090' '#1074#1099#1073#1088#1072#1085#1085#1086#1075#1086' '#1087#1088#1077#1076#1084#1077#1090#1072
  ClientHeight = 405
  ClientWidth = 475
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
    Width = 475
    Height = 137
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object DBText1: TDBText
      Left = 24
      Top = 6
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'FAM'
      DataSource = DataModule1.SpisocQSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText2: TDBText
      Left = 24
      Top = 22
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'NAME'
      DataSource = DataModule1.SpisocQSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText3: TDBText
      Left = 24
      Top = 38
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'OTCH'
      DataSource = DataModule1.SpisocQSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText4: TDBText
      Left = 121
      Top = 62
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'NAME_OBJECT'
      DataSource = DataModule1.Result_BallSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText5: TDBText
      Left = 121
      Top = 81
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'SEMESTR'
      DataSource = DataModule1.Result_BallSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText6: TDBText
      Left = 121
      Top = 99
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'RESULT1'
      DataSource = DataModule1.Result_BallSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label8: TLabel
      Left = 24
      Top = 62
      Width = 57
      Height = 13
      Caption = #1055#1088#1077#1076#1084#1077#1090':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label9: TLabel
      Left = 24
      Top = 81
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
    object Label10: TLabel
      Left = 24
      Top = 99
      Width = 49
      Height = 13
      Caption = #1054#1094#1077#1085#1082#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText7: TDBText
      Left = 121
      Top = 118
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'VID_EDU_PLAN1'
      DataSource = DataModule1.Result_BallSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText8: TDBText
      Left = 368
      Top = 99
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'N_FAC1'
      DataSource = DataModule1.Result_BallSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText9: TDBText
      Left = 368
      Top = 118
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'YEAR_PLAN1'
      DataSource = DataModule1.Result_BallSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label11: TLabel
      Left = 24
      Top = 118
      Width = 85
      Height = 13
      Caption = #1042#1080#1076' '#1086#1073#1091#1095#1077#1085#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label12: TLabel
      Left = 275
      Top = 99
      Width = 70
      Height = 13
      Caption = #1060#1072#1082#1091#1083#1100#1090#1077#1090':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label13: TLabel
      Left = 275
      Top = 118
      Width = 81
      Height = 13
      Caption = #1059#1095#1077#1073#1085#1099#1081' '#1075#1086#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 347
    Width = 475
    Height = 58
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    object BitBtn1: TBitBtn
      Left = 307
      Top = 16
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
      TabOrder = 0
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 80
      Top = 16
      Width = 105
      Height = 33
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        F2010000424DF201000000000000760000002800000024000000130000000100
        0400000000007C01000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333334433333
        3333333333388F3333333333000033334224333333333333338338F333333333
        0000333422224333333333333833338F33333333000033422222243333333333
        83333338F3333333000034222A22224333333338F33F33338F33333300003222
        A2A2224333333338F383F3338F33333300003A2A222A222433333338F8333F33
        38F33333000034A22222A22243333338833333F3338F333300004222A2222A22
        2433338F338F333F3338F3330000222A3A2224A22243338F3838F338F3338F33
        0000A2A333A2224A2224338F83338F338F3338F300003A33333A2224A2224338
        333338F338F3338F000033333333A2224A2243333333338F338F338F00003333
        33333A2224A2233333333338F338F83300003333333333A2224A333333333333
        8F338F33000033333333333A222433333333333338F338F30000333333333333
        A224333333333333338F38F300003333333333333A223333333333333338F8F3
        000033333333333333A3333333333333333383330000}
      ModalResult = 8
      NumGlyphs = 2
      ParentFont = False
      TabOrder = 1
      OnClick = BitBtn2Click
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 137
    Width = 475
    Height = 210
    Align = alClient
    BevelInner = bvLowered
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    object Label1: TLabel
      Left = 24
      Top = 75
      Width = 81
      Height = 13
      Caption = #1059#1095#1077#1073#1085#1099#1081' '#1075#1086#1076':'
    end
    object Label2: TLabel
      Left = 168
      Top = 75
      Width = 5
      Height = 13
      Caption = ' '
    end
    object Label3: TLabel
      Left = 24
      Top = 44
      Width = 56
      Height = 13
      Caption = #1057#1077#1084#1077#1089#1090#1088':'
    end
    object Label4: TLabel
      Left = 24
      Top = 13
      Width = 85
      Height = 13
      Caption = #1042#1080#1076' '#1086#1073#1091#1095#1077#1085#1080#1103':'
    end
    object Edit1: TEdit
      Left = 112
      Top = 71
      Width = 49
      Height = 21
      ReadOnly = True
      TabOrder = 2
      OnClick = Edit1Click
      OnKeyPress = Edit2KeyPress
    end
    object Edit2: TEdit
      Left = 112
      Top = 40
      Width = 33
      Height = 21
      TabOrder = 1
      OnExit = Edit2Exit
      OnKeyPress = Edit2KeyPress
    end
    object ComboBox1: TComboBox
      Left = 112
      Top = 9
      Width = 105
      Height = 21
      Style = csDropDownList
      TabOrder = 0
      OnChange = ComboBox1Change
      Items.Strings = (
        #1044#1085#1077#1074#1085#1086#1077
        #1047#1072#1086#1095#1085#1086#1077)
    end
    object BitBtn3: TBitBtn
      Left = 295
      Top = 63
      Width = 130
      Height = 33
      Caption = #1042#1099#1073#1086#1088' '#1087#1088#1077#1076#1084#1077#1090#1072
      TabOrder = 3
      OnClick = BitBtn3Click
    end
    object Panel4: TPanel
      Left = 2
      Top = 90
      Width = 471
      Height = 118
      Align = alBottom
      BevelInner = bvRaised
      BevelOuter = bvLowered
      Enabled = False
      TabOrder = 4
      object Label5: TLabel
        Left = 24
        Top = 16
        Width = 57
        Height = 13
        Caption = #1055#1088#1077#1076#1084#1077#1090':'
      end
      object Label6: TLabel
        Left = 225
        Top = 36
        Width = 107
        Height = 13
        Caption = #1044#1072#1090#1072' '#1087#1077#1088#1077#1079#1072#1095#1077#1090#1072':'
      end
      object Label7: TLabel
        Left = 225
        Top = 76
        Width = 181
        Height = 13
        Caption = #1054#1089#1085#1086#1074#1072#1085#1080#1077' '#1087#1086#1083#1091#1095#1077#1085#1080#1103' '#1086#1094#1077#1085#1082#1080':'
      end
      object DBLookupComboBox1: TDBLookupComboBox
        Left = 111
        Top = 12
        Width = 353
        Height = 21
        KeyField = 'N_PLAN'
        ListField = 'N_OBJECT1'
        ListSource = DataModule1.Edu_PlanQSource
        TabOrder = 0
      end
      object ComboBox2: TComboBox
        Left = 225
        Top = 89
        Width = 241
        Height = 21
        Style = csDropDownList
        TabOrder = 2
        Items.Strings = (
          #1054#1089#1085#1086#1074#1085#1072#1103' '#1074#1077#1076#1086#1084#1086#1089#1090#1100
          #1069#1082#1079'. '#1083#1080#1089#1090' '#1080#1083#1080' '#1076#1086#1087#1086#1083#1085#1080#1090'. '#1074#1077#1076#1086#1084#1086#1089#1090#1100
          #1044#1086#1089#1088#1086#1095#1085#1072#1103' '#1089#1076#1072#1095#1072
          #1051#1080#1082#1074#1080#1076#1072#1094#1080#1103' '#1088#1072#1079#1085#1080#1094#1099
          #1055#1077#1088#1077#1079#1072#1095#1077#1090' '#1089' '#1076'/'#1086' '#1085#1072' '#1079'/'#1086' '#1080#1083#1080' '#1085#1072#1086#1073#1086#1088#1086#1090
          #1055#1077#1088#1077#1079#1072#1095#1077#1090' '#1087#1088#1080' 2-'#1086#1084' '#1074'/'#1086
          #1055#1077#1088#1077#1079#1072#1095#1077#1090' '#1087#1088#1080' '#1087#1077#1088#1077#1074#1086#1076#1077'-'#1074#1086#1089#1089#1090#1072#1085#1086#1074#1083'. '#1080#1079' '#1076#1088'. '#1042#1059#1047#1072
          #1055#1077#1088#1077#1079#1072#1095#1077#1090' '#1087#1086#1089#1083#1077' '#1056#1059#1054#1056
          #1055#1077#1088#1077#1079#1072#1095#1077#1090' '#1089' '#1076#1088#1091#1075#1086#1075#1086' '#1092#1072#1082#1091#1083#1100#1090#1077#1090#1072
          #1055#1077#1088#1077#1079#1072#1095#1077#1090' '#1087#1086#1089#1083#1077' '#1055#1077#1076#1050#1086#1083#1083#1077#1076#1078#1072
          #1055#1077#1088#1077#1089#1076#1072#1095#1072
          #1055#1077#1088#1077#1079#1072#1095#1077#1090' '#1087#1086#1089#1083#1077' '#1048#1055#1050', '#1052#1050#1055
          #1055#1077#1088#1077#1079#1072#1095#1105#1090' '#1087#1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1077' "Erasmust"')
      end
      object RadioGroup2: TRadioGroup
        Left = 24
        Top = 46
        Width = 185
        Height = 66
        Caption = #1042' '#1082#1072#1082#1086#1081' '#1089#1080#1089#1090#1077#1084#1077' '#1086#1094#1077#1085#1082#1072':'
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
        TabOrder = 1
      end
      object DateTimePicker1: TDateTimePicker
        Left = 225
        Top = 55
        Width = 144
        Height = 21
        Date = 42648.492229375000000000
        Time = 42648.492229375000000000
        TabOrder = 3
        OnChange = DateTimePicker1Change
      end
    end
  end
end

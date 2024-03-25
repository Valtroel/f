object Add_UchKartForm: TAdd_UchKartForm
  Left = 270
  Top = 222
  BorderIcons = [biSystemMenu]
  Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1079#1072#1087#1080#1089#1077#1081' '#1074' '#1091#1095#1077#1073#1085#1091#1102' '#1082#1072#1088#1090#1086#1095#1082#1091' '#1089#1090#1091#1076#1077#1085#1090#1072
  ClientHeight = 390
  ClientWidth = 536
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  ShowHint = True
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 536
    Height = 57
    Align = alTop
    BevelInner = bvLowered
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
    object DBNavigator1: TDBNavigator
      Left = 349
      Top = 19
      Width = 160
      Height = 20
      DataSource = DataModule1.SpisocQSource
      VisibleButtons = [nbFirst, nbPrior, nbNext, nbLast]
      TabOrder = 0
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 57
    Width = 536
    Height = 283
    Align = alClient
    BevelInner = bvLowered
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    object Label1: TLabel
      Left = 24
      Top = 78
      Width = 81
      Height = 13
      Caption = #1059#1095#1077#1073#1085#1099#1081' '#1075#1086#1076':'
    end
    object Label2: TLabel
      Left = 168
      Top = 78
      Width = 5
      Height = 13
      Caption = ' '
    end
    object Label3: TLabel
      Left = 24
      Top = 48
      Width = 56
      Height = 13
      Caption = #1057#1077#1084#1077#1089#1090#1088':'
    end
    object Label4: TLabel
      Left = 24
      Top = 18
      Width = 85
      Height = 13
      Caption = #1042#1080#1076' '#1086#1073#1091#1095#1077#1085#1080#1103':'
    end
    object Edit1: TEdit
      Left = 112
      Top = 74
      Width = 49
      Height = 21
      ReadOnly = True
      TabOrder = 2
      OnClick = Edit1Click
    end
    object Edit2: TEdit
      Left = 112
      Top = 44
      Width = 33
      Height = 21
      TabOrder = 1
      OnExit = Edit2Exit
      OnKeyPress = Edit2KeyPress
    end
    object ComboBox1: TComboBox
      Left = 112
      Top = 14
      Width = 105
      Height = 21
      Style = csDropDownList
      TabOrder = 0
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
      Top = 93
      Width = 532
      Height = 188
      Align = alBottom
      BevelInner = bvRaised
      BevelOuter = bvLowered
      Enabled = False
      TabOrder = 4
      object Label5: TLabel
        Left = 9
        Top = 11
        Width = 57
        Height = 13
        Caption = #1055#1088#1077#1076#1084#1077#1090':'
      end
      object Label6: TLabel
        Left = 225
        Top = 84
        Width = 149
        Height = 13
        Caption = #1044#1072#1090#1072' '#1101#1082#1079#1072#1084#1077#1085#1072' ('#1079#1072#1095#1077#1090#1072'):'
      end
      object Label7: TLabel
        Left = 225
        Top = 134
        Width = 181
        Height = 13
        Caption = #1054#1089#1085#1086#1074#1072#1085#1080#1077' '#1087#1086#1083#1091#1095#1077#1085#1080#1103' '#1086#1094#1077#1085#1082#1080':'
      end
      object DBLookupComboBox1: TDBLookupComboBox
        Left = 80
        Top = 7
        Width = 457
        Height = 21
        KeyField = 'N_PLAN'
        ListField = 'NAME_PLAN'
        ListSource = DataModule1.Edu_PlanQSource
        TabOrder = 0
      end
      object RadioGroup1: TRadioGroup
        Left = 9
        Top = 77
        Width = 201
        Height = 103
        Caption = #1054#1094#1077#1085#1082#1072':'
        Columns = 2
        Items.Strings = (
          #1059#1076#1086#1074#1083'.'
          #1061#1086#1088#1086#1096#1086
          #1054#1090#1083#1080#1095#1085#1086
          #1047#1072#1095#1077#1090
          #1054#1089#1074#1086#1073#1086#1078#1076#1077#1085
          #1040#1090#1090#1077#1089#1090#1086#1074#1072#1085)
        TabOrder = 1
      end
      object ComboBox2: TComboBox
        Left = 225
        Top = 150
        Width = 312
        Height = 21
        Style = csDropDownList
        TabOrder = 3
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
          #1055#1077#1088#1077#1079#1072#1095#1077#1090' '#1087#1086#1089#1083#1077' '#1052#1050#1055', '#1048#1055#1050
          #1055#1077#1088#1077#1079#1072#1095#1105#1090' '#1087#1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1077' "Erasmus+"')
      end
      object RadioGroup2: TRadioGroup
        Left = 9
        Top = 34
        Width = 272
        Height = 39
        Caption = #1057#1080#1089#1090#1077#1084#1072' '#1086#1094#1077#1085#1086#1082':'
        Columns = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ItemIndex = 1
        Items.Strings = (
          '10 - '#1090#1080' '#1073#1072#1083#1100#1085#1072#1103
          ' 5  - '#1090#1080' '#1073#1072#1083#1100#1085#1072#1103)
        ParentFont = False
        TabOrder = 2
        OnClick = RadioGroup2Click
      end
      object DateTimePicker1: TDateTimePicker
        Left = 225
        Top = 107
        Width = 149
        Height = 21
        Date = 42635.707573206020000000
        Time = 42635.707573206020000000
        TabOrder = 4
        OnChange = DateTimePicker1Change
      end
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 340
    Width = 536
    Height = 50
    Align = alBottom
    BevelInner = bvLowered
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    object BitBtn1: TBitBtn
      Left = 80
      Top = 10
      Width = 105
      Height = 33
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
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
      TabOrder = 0
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 264
      Top = 10
      Width = 105
      Height = 33
      Caption = #1047#1072#1082#1088#1099#1090#1100
      Kind = bkClose
      NumGlyphs = 2
      TabOrder = 1
    end
  end
end

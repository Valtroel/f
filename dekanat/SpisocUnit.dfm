object SpisocForm: TSpisocForm
  Left = 263
  Top = 126
  Caption = #1048#1090#1086#1075#1086#1074#1072#1103' '#1091#1089#1087#1077#1074#1072#1077#1084#1086#1089#1090#1100' '#1089#1090#1091#1076#1077#1085#1090#1086#1074
  ClientHeight = 599
  ClientWidth = 718
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 503
    Width = 718
    Height = 96
    Align = alBottom
    BevelOuter = bvLowered
    TabOrder = 0
    object GroupBox2: TGroupBox
      Left = 8
      Top = 8
      Width = 489
      Height = 84
      Caption = #1055#1088#1086#1089#1084#1086#1090#1088' '#1091#1095#1077#1073#1085#1086#1081' '#1082#1072#1088#1090#1086#1095#1082#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      object CheckBox2: TCheckBox
        Left = 8
        Top = 20
        Width = 121
        Height = 17
        Caption = #1042#1089#1077' '#1089#1077#1084#1077#1089#1090#1088#1099
        Checked = True
        State = cbChecked
        TabOrder = 0
        OnClick = CheckBox2Click
      end
      object RadioGroup1: TRadioGroup
        Left = 200
        Top = 9
        Width = 177
        Height = 69
        Caption = #1042#1099#1073#1086#1088' '#1087#1086' '#1082#1091#1088#1089#1091':'
        Columns = 2
        Items.Strings = (
          'I '#1082#1091#1088#1089
          'II '#1082#1091#1088#1089
          'III '#1082#1091#1088#1089
          'IV '#1082#1091#1088#1089
          'V '#1082#1091#1088#1089
          'VI '#1082#1091#1088#1089)
        TabOrder = 1
        OnClick = RadioGroup1Click
      end
      object RadioGroup2: TRadioGroup
        Left = 395
        Top = 9
        Width = 70
        Height = 69
        Caption = #1057#1077#1084#1077#1089#1090#1088':'
        TabOrder = 2
        Visible = False
        OnClick = RadioGroup2Click
      end
    end
    object BitBtn1: TBitBtn
      Left = 559
      Top = 57
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
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 559
      Top = 8
      Width = 105
      Height = 33
      Caption = #1055#1077#1088#1077#1079#1072#1095#1077#1090
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
        7777700000007777770000000000700000007777770FFFFFFFF0700000007777
        770FFFFFFFF0700000007777770FFFFFFFF07000000088888800000000007000
        00008FFFFF0FCCCCCCC0700000008FFFFF0000000000700000008FFFFFFFF877
        7777700000008888888888888887700000008F88888888FFFF87700000008888
        888888FFFF8770000000777778FFFFFFFF877000000077777888888888877000
        0000777778F88888888770000000777778888888888770000000777777777777
        777770000000}
      ParentFont = False
      TabOrder = 2
      Visible = False
      OnClick = BitBtn2Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 227
    Width = 718
    Height = 276
    Align = alBottom
    BevelOuter = bvLowered
    TabOrder = 1
    object Label1: TLabel
      Left = 24
      Top = 5
      Width = 200
      Height = 13
      AutoSize = False
      Caption = ' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 24
      Top = 23
      Width = 200
      Height = 13
      AutoSize = False
      Caption = ' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 24
      Top = 40
      Width = 200
      Height = 13
      AutoSize = False
      Caption = ' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 237
      Top = 35
      Width = 214
      Height = 16
      Caption = #1059#1095#1077#1073#1085#1072#1103' '#1082#1072#1088#1090#1086#1095#1082#1072' '#1089#1090#1091#1076#1077#1085#1090#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBGrid2: TDBGrid
      Left = 1
      Top = 56
      Width = 716
      Height = 219
      Align = alBottom
      DataSource = DataModule1.Result_BallSource
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
      ReadOnly = True
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -10
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
      OnCellClick = DBGrid2CellClick
      OnDblClick = DBGrid2DblClick
      Columns = <
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'SEMESTR'
          Title.Alignment = taCenter
          Title.Caption = #1057#1077#1084#1077#1089#1090#1088
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 55
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NAME_OBJECT'
          Title.Alignment = taCenter
          Title.Caption = #1055#1088#1077#1076#1084#1077#1090
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 214
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'CLOCK_PLAN'
          Title.Alignment = taCenter
          Title.Caption = #1040#1091#1076'.'#1095#1072#1089#1086#1074
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 67
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'CLOCK_PLAN_ALL'
          Title.Caption = #1042#1089#1077#1075#1086' '#1095#1072#1089#1086#1074
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -10
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'RESULT1'
          Title.Alignment = taCenter
          Title.Caption = #1054#1094#1077#1085#1082#1072
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'DATE_RESULT'
          Title.Alignment = taCenter
          Title.Caption = #1044#1072#1090#1072
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 63
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'YEAR_PLAN1'
          Title.Alignment = taCenter
          Title.Caption = #1059#1095'. '#1075#1086#1076
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 58
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'N_FAC1'
          Title.Alignment = taCenter
          Title.Caption = #1060#1072#1082#1091#1083#1100#1090#1077#1090
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 72
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'VID_EDU_PLAN1'
          Title.Alignment = taCenter
          Title.Caption = #1042#1080#1076' '#1086#1073#1091#1095#1077#1085#1080#1103
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 89
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'STATUS_RESULT1'
          Title.Alignment = taCenter
          Title.Caption = #1057#1090#1072#1090#1091#1089' '#1086#1094#1077#1085#1082#1080
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Visible = True
        end>
    end
  end
  object DBGrid1: TDBGrid
    Left = 0
    Top = 97
    Width = 718
    Height = 130
    Align = alClient
    DataSource = DataModule1.SpisocQSource
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
    ReadOnly = True
    TabOrder = 2
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -10
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    OnCellClick = DBGrid1CellClick
    OnDblClick = DBGrid1DblClick
    Columns = <
      item
        Alignment = taCenter
        Color = clMenu
        Expanded = False
        FieldName = 'N_GROUP'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Title.Alignment = taCenter
        Title.Caption = #8470' '#1075#1088#1091#1087#1087#1099
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'MS Sans Serif'
        Title.Font.Style = [fsBold]
        Width = 77
        Visible = True
      end
      item
        Color = 16776176
        Expanded = False
        FieldName = 'FAM'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Title.Alignment = taCenter
        Title.Caption = #1060#1072#1084#1080#1083#1080#1103
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'MS Sans Serif'
        Title.Font.Style = [fsBold]
        Width = 162
        Visible = True
      end
      item
        Color = 16776176
        Expanded = False
        FieldName = 'NAME'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Title.Alignment = taCenter
        Title.Caption = #1048#1084#1103
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'MS Sans Serif'
        Title.Font.Style = [fsBold]
        Width = 161
        Visible = True
      end
      item
        Color = 16776176
        Expanded = False
        FieldName = 'OTCH'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Title.Alignment = taCenter
        Title.Caption = #1054#1090#1095#1077#1089#1090#1074#1086
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'MS Sans Serif'
        Title.Font.Style = [fsBold]
        Width = 156
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'VID_EDU1'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Title.Alignment = taCenter
        Title.Caption = #1042#1080#1076' '#1086#1073#1091#1095#1077#1085#1080#1103
        Title.Font.Charset = DEFAULT_CHARSET
        Title.Font.Color = clWindowText
        Title.Font.Height = -13
        Title.Font.Name = 'MS Sans Serif'
        Title.Font.Style = [fsBold]
        Width = 133
        Visible = True
      end>
  end
  object Panel3: TPanel
    Left = 0
    Top = 0
    Width = 718
    Height = 97
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 3
    object Label5: TLabel
      Left = 6
      Top = 3
      Width = 174
      Height = 13
      Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1092#1072#1084#1080#1083#1080#1080' '#1089#1090#1091#1076#1077#1085#1090#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 6
      Top = 17
      Width = 171
      Height = 21
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnChange = Edit1Change
    end
    object RG2: TRadioGroup
      Left = 440
      Top = 4
      Width = 125
      Height = 61
      Caption = #1060#1086#1088#1084#1072' '#1086#1073#1091#1095#1077#1085#1080#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -9
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ItemIndex = 0
      Items.Strings = (
        #1044#1085#1077#1074#1085#1072#1103
        #1047#1072#1086#1095#1085#1072#1103)
      ParentFont = False
      TabOrder = 1
      OnClick = RG2Click
    end
    object RG1: TRadioGroup
      Left = 572
      Top = 4
      Width = 146
      Height = 87
      Caption = #1042#1099#1073#1086#1088' '#1082#1091#1088#1089#1072
      Columns = 2
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
        '5 '#1082#1091#1088#1089
        '6 '#1082#1091#1088#1089)
      ParentFont = False
      TabOrder = 2
      OnClick = RG1Click
    end
    object CheckBox1: TCheckBox
      Left = 441
      Top = 77
      Width = 82
      Height = 14
      Caption = #1042#1089#1077' '#1082#1091#1088#1089#1099
      Checked = True
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -9
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      State = cbChecked
      TabOrder = 3
      OnClick = CheckBox1Click
    end
    object GroupBox1: TGroupBox
      Left = 187
      Top = 4
      Width = 241
      Height = 82
      Caption = #1042#1099#1073#1086#1088#1082#1072' '#1089#1090#1091#1076#1077#1085#1090#1086#1074' '#1087#1086' '#1085#1086#1084#1077#1088#1091' '#1075#1088#1091#1087#1087#1099
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      object Label47: TLabel
        Left = 9
        Top = 20
        Width = 137
        Height = 13
        Caption = #1042#1074#1077#1076#1080#1090#1077' '#1085#1086#1084#1077#1088' '#1075#1088#1091#1087#1087#1099
      end
      object Label10: TLabel
        Left = 9
        Top = 43
        Width = 85
        Height = 13
        Caption = #1042#1080#1076' '#1086#1073#1091#1095#1077#1085#1080#1103':'
      end
      object CheckBox3: TCheckBox
        Left = 7
        Top = 62
        Width = 169
        Height = 14
        Hint = #1055#1088#1080' '#1074#1082#1083#1102#1095#1077#1085#1080#1080' '#1087#1088#1086#1080#1089#1093#1086#1076#1080#1090' '#1074#1099#1073#1086#1088#1082#1072' '#1089#1090#1091#1076#1077#1085#1090#1086#1074' '#1079#1072#1076#1072#1085#1085#1086#1081' '#1075#1088#1091#1087#1087#1099
        Alignment = taLeftJustify
        Caption = #1042#1099#1073#1088#1072#1090#1100
        ParentShowHint = False
        ShowHint = True
        TabOrder = 2
        OnClick = CheckBox3Click
      end
      object Edit2: TEdit
        Left = 181
        Top = 16
        Width = 46
        Height = 21
        TabOrder = 0
        OnChange = Edit2Change
        OnKeyPress = Edit2KeyPress
      end
      object ComboBox4: TComboBox
        Left = 109
        Top = 40
        Width = 118
        Height = 21
        Style = csDropDownList
        TabOrder = 1
        OnChange = Edit2Change
        Items.Strings = (
          #1044#1085#1077#1074#1085#1086#1077
          #1047#1072#1086#1095#1085#1086#1077)
      end
    end
    object CheckBox4: TCheckBox
      Left = 6
      Top = 41
      Width = 180
      Height = 17
      Caption = #1054#1090#1095#1080#1089#1083#1077#1085#1085#1099#1077' '#1089#1090#1091#1076#1077#1085#1090#1099
      TabOrder = 5
      OnClick = CheckBox4Click
    end
    object CheckBox5: TCheckBox
      Left = 6
      Top = 55
      Width = 180
      Height = 17
      Caption = #1057#1090#1091#1076#1077#1085#1090#1099' '#1074' '#1072#1082#1072#1076#1077#1084'.'#1086#1090#1087#1091#1089#1082#1077
      TabOrder = 6
      OnClick = CheckBox5Click
    end
    object CheckBox6: TCheckBox
      Left = 6
      Top = 69
      Width = 180
      Height = 17
      Caption = #1057#1090#1091#1076#1077#1085#1090#1099' '#1087#1086#1074#1090'. '#1075#1086#1076#1072' '#1086#1073#1091#1095#1077#1085#1080#1103
      TabOrder = 7
      OnClick = CheckBox6Click
    end
  end
  object ApplicationEvents1: TApplicationEvents
    OnMessage = ApplicationEvents1Message
    Left = 168
    Top = 256
  end
end

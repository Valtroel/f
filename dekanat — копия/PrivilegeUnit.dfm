object PrivilegeForm: TPrivilegeForm
  Left = 212
  Top = 107
  BorderIcons = [biSystemMenu]
  ClientHeight = 437
  ClientWidth = 650
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 650
    Height = 185
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object RadioGroup1: TRadioGroup
      Left = 14
      Top = 2
      Width = 121
      Height = 66
      Caption = #1042#1099#1073#1086#1088':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077
        #1048#1079#1084#1077#1085#1077#1085#1080#1077
        #1055#1088#1086#1089#1084#1086#1090#1088)
      ParentFont = False
      TabOrder = 0
      OnClick = RadioGroup1Click
    end
    object DBGrid1: TDBGrid
      Left = 210
      Top = 2
      Width = 438
      Height = 181
      Align = alRight
      DataSource = DataModule1.Priv_AddSource
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
      ReadOnly = True
      TabOrder = 3
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
      Visible = False
      OnDblClick = DBGrid1DblClick
      Columns = <
        item
          Expanded = False
          FieldName = 'FAM'
          Title.Alignment = taCenter
          Title.Caption = #1060#1072#1084#1080#1083#1080#1103
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 77
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NAME'
          Title.Alignment = taCenter
          Title.Caption = #1048#1084#1103
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 65
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'OTCH'
          Title.Alignment = taCenter
          Title.Caption = #1054#1090#1095#1077#1089#1090#1074#1086
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 65
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'KURS'
          Title.Alignment = taCenter
          Title.Caption = #1050#1091#1088#1089
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 35
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'N_GROUP'
          Title.Alignment = taCenter
          Title.Caption = #8470' '#1075#1088'.'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'TEXT_PRIV'
          Title.Alignment = taCenter
          Title.Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 100
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'DOC_PRIV'
          Title.Alignment = taCenter
          Title.Caption = #1044#1086#1082#1091#1084#1077#1085#1090
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 100
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'UCH_GOD'
          Title.Alignment = taCenter
          Title.Caption = #1059#1095'.'#1075#1086#1076
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
          FieldName = 'DATA_C'
          Title.Alignment = taCenter
          Title.Caption = #1044#1072#1090#1072' '#1089'...'
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
          FieldName = 'DATA_PO'
          Title.Alignment = taCenter
          Title.Caption = #1044#1072#1090#1072' '#1087#1086'...'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'DESCRIBE'
          Title.Alignment = taCenter
          Title.Caption = #1055#1088#1080#1084#1077#1095#1077#1085#1080#1077
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 100
          Visible = True
        end>
    end
    object RadioGroup2: TRadioGroup
      Left = 14
      Top = 69
      Width = 121
      Height = 50
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
      TabOrder = 1
      Visible = False
      OnClick = RadioGroup2Click
    end
    object GroupBox1: TGroupBox
      Left = 14
      Top = 119
      Width = 195
      Height = 62
      Caption = #1050#1088#1080#1090#1077#1088#1080#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      Visible = False
      object Label2: TLabel
        Left = 146
        Top = 17
        Width = 35
        Height = 13
        Caption = '/2001'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object CheckBox1: TCheckBox
        Left = 8
        Top = 16
        Width = 85
        Height = 17
        Caption = #1047#1072' '#1091#1095'. '#1075#1086#1076
        TabOrder = 0
        OnClick = CheckBox1Click
      end
      object CheckBox2: TCheckBox
        Left = 8
        Top = 38
        Width = 85
        Height = 17
        Caption = #1047#1072' '#1076#1072#1090#1091
        TabOrder = 1
        OnClick = CheckBox1Click
      end
      object Edit1: TEdit
        Left = 91
        Top = 13
        Width = 37
        Height = 21
        ReadOnly = True
        TabOrder = 2
        Text = '2000'
      end
      object UpDown1: TUpDown
        Left = 128
        Top = 13
        Width = 15
        Height = 21
        Associate = Edit1
        Min = 2000
        Max = 3000
        Position = 2000
        TabOrder = 3
        Thousands = False
        OnClick = UpDown1Click
      end
      object DateTimePicker3: TDateTimePicker
        Left = 81
        Top = 40
        Width = 111
        Height = 21
        Date = 42648.462594074070000000
        Time = 42648.462594074070000000
        TabOrder = 4
        OnChange = DateTimePicker3Change
      end
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 185
    Width = 650
    Height = 48
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    Visible = False
    object Button1: TButton
      Left = 48
      Top = 8
      Width = 105
      Height = 33
      Caption = 'Button1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button3: TButton
      Left = 360
      Top = 8
      Width = 105
      Height = 33
      Caption = #1054#1090#1084#1077#1085#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      Visible = False
      OnClick = Button3Click
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 233
    Width = 650
    Height = 162
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 2
    Visible = False
    object Label3: TLabel
      Left = 344
      Top = 49
      Width = 160
      Height = 13
      Caption = #1057#1088#1086#1082' '#1076#1077#1081#1089#1090#1074#1080#1103' '#1076#1086#1082#1091#1084#1077#1085#1090#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 344
      Top = 68
      Width = 8
      Height = 13
      Caption = #1089
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 481
      Top = 68
      Width = 15
      Height = 13
      Caption = #1087#1086
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label6: TLabel
      Left = 32
      Top = 8
      Width = 96
      Height = 13
      Caption = #1060#1048#1054' '#1089#1090#1091#1076#1077#1085#1090#1072': '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object LabeledEdit1: TLabeledEdit
      Left = 32
      Top = 64
      Width = 281
      Height = 21
      EditLabel.Width = 67
      EditLabel.Height = 13
      EditLabel.Caption = #1050#1072#1090#1077#1075#1086#1088#1080#1103':'
      EditLabel.Font.Charset = DEFAULT_CHARSET
      EditLabel.Font.Color = clWindowText
      EditLabel.Font.Height = -11
      EditLabel.Font.Name = 'MS Sans Serif'
      EditLabel.Font.Style = [fsBold]
      EditLabel.ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      Text = #1057#1080#1088#1086#1090#1072
    end
    object LabeledEdit2: TLabeledEdit
      Left = 32
      Top = 102
      Width = 281
      Height = 21
      EditLabel.Width = 64
      EditLabel.Height = 13
      EditLabel.Caption = #1044#1086#1082#1091#1084#1077#1085#1090':'
      EditLabel.Font.Charset = DEFAULT_CHARSET
      EditLabel.Font.Color = clWindowText
      EditLabel.Font.Height = -11
      EditLabel.Font.Name = 'MS Sans Serif'
      EditLabel.Font.Style = [fsBold]
      EditLabel.ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      Text = #1057#1087#1088#1072#1074#1082#1072' '#8470' ___  '#1086#1090' _________'
    end
    object LabeledEdit3: TLabeledEdit
      Left = 32
      Top = 141
      Width = 281
      Height = 21
      EditLabel.Width = 78
      EditLabel.Height = 13
      EditLabel.Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077':'
      EditLabel.Font.Charset = DEFAULT_CHARSET
      EditLabel.Font.Color = clWindowText
      EditLabel.Font.Height = -11
      EditLabel.Font.Name = 'MS Sans Serif'
      EditLabel.Font.Style = [fsBold]
      EditLabel.ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
    end
    object DBLookupComboBox1: TDBLookupComboBox
      Left = 32
      Top = 23
      Width = 281
      Height = 21
      KeyField = 'NOMER'
      ListField = 'FIO'
      ListSource = DataModule1.People_SpravkiSource
      TabOrder = 0
    end
    object DateTimePicker1: TDateTimePicker
      Left = 358
      Top = 68
      Width = 107
      Height = 21
      Date = 42648.461517222230000000
      Time = 42648.461517222230000000
      TabOrder = 4
      OnChange = DateTimePicker1Change
    end
    object DateTimePicker2: TDateTimePicker
      Left = 502
      Top = 68
      Width = 99
      Height = 21
      Date = 42648.461712199070000000
      Time = 42648.461712199070000000
      TabOrder = 5
      OnChange = DateTimePicker2Change
    end
  end
  object Panel4: TPanel
    Left = 0
    Top = 395
    Width = 650
    Height = 42
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 3
    Visible = False
    object Button2: TButton
      Left = 48
      Top = 5
      Width = 105
      Height = 33
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = Button2Click
    end
  end
  object ApplicationEvents1: TApplicationEvents
    OnMessage = ApplicationEvents1Message
    Left = 168
    Top = 256
  end
end

object Prikaz_LikvidForm: TPrikaz_LikvidForm
  Left = 216
  Top = 99
  BorderIcons = [biSystemMenu, biMaximize]
  Caption = #1044#1086#1087#1091#1089#1082' '#1082' '#1083#1080#1082#1074#1080#1076#1072#1094#1080#1080' '#1088#1072#1079#1085#1080#1094#1099
  ClientHeight = 657
  ClientWidth = 605
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
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 605
    Height = 73
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object RadioGroup1: TRadioGroup
      Left = 8
      Top = 8
      Width = 289
      Height = 57
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        #1044#1072#1090#1100' '#1076#1086#1087#1091#1089#1082' '#1085#1072' '#1083#1080#1082#1074#1080#1076#1072#1094#1080#1102' '#1088#1072#1079#1085#1080#1094#1099
        #1048#1079#1084#1077#1085#1080#1090#1100' '#1087#1088#1080#1082#1072#1079' '#1085#1072' '#1083#1080#1082#1074#1080#1076#1072#1094#1080#1102' '#1088#1072#1079#1085#1080#1094#1099)
      ParentFont = False
      TabOrder = 0
      OnClick = RadioGroup1Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 406
    Width = 605
    Height = 200
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    Visible = False
    object DBGrid1: TDBGrid
      Left = 2
      Top = 2
      Width = 601
      Height = 101
      Align = alClient
      DataSource = DataModule1.LikvidSource
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
      ReadOnly = True
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
      Columns = <
        item
          Expanded = False
          FieldName = 'FIO'
          Title.Alignment = taCenter
          Title.Caption = #1060#1048#1054
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 150
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'PRIKAZ'
          Title.Alignment = taCenter
          Title.Caption = #1054#1089#1085#1086#1074#1072#1085#1080#1077
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 150
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'DATE_C'
          Title.Alignment = taCenter
          Title.Caption = #1076#1072#1090#1072' '#1089'...'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 57
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'DATE_PO'
          Title.Alignment = taCenter
          Title.Caption = #1076#1072#1090#1072' '#1087#1086'...'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 61
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'TEXT_LIKVID'
          Title.Alignment = taCenter
          Title.Caption = #1055#1088#1080#1095#1080#1085#1072
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 113
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'DESCRIBE'
          Title.Alignment = taCenter
          Title.Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1077
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 150
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'FAC_DO1'
          Title.Alignment = taCenter
          Title.Caption = #1060#1072#1082'-'#1090' '#1076#1086
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
          FieldName = 'FAC_PO1'
          Title.Alignment = taCenter
          Title.Caption = #1060#1072#1082'-'#1090' '#1087#1086#1089#1083#1077
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
          FieldName = 'VID_EDU_DO1'
          Title.Alignment = taCenter
          Title.Caption = #1042#1080#1076' '#1086#1073#1091#1095#1077#1085#1080#1103' '#1076#1086
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
          FieldName = 'VID_EDU_PO1'
          Title.Alignment = taCenter
          Title.Caption = #1042#1080#1076' '#1086#1073#1091#1095#1077#1085#1080#1103' '#1087#1086#1089#1083#1077
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'SPECIALIZ_DO1'
          Title.Alignment = taCenter
          Title.Caption = #1057#1087#1077#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103' '#1076#1086
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 150
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'SPECIALIZ_PO1'
          Title.Alignment = taCenter
          Title.Caption = #1057#1087#1077#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103' '#1087#1086#1089#1083#1077
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 150
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'KURS_DO'
          Title.Alignment = taCenter
          Title.Caption = #1050#1091#1088#1089' '#1076#1086
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
          FieldName = 'KURS_PO'
          Title.Alignment = taCenter
          Title.Caption = #1050#1091#1088#1089' '#1087#1086#1089#1083#1077
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
          FieldName = 'FOUND_DO1'
          Title.Alignment = taCenter
          Title.Caption = #1054#1089#1085#1086#1074#1072#1085#1080#1077' '#1076#1086
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 110
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'FOUND_PO1'
          Title.Alignment = taCenter
          Title.Caption = #1054#1089#1085#1086#1074#1072#1085#1080#1077' '#1087#1086#1089#1083#1077
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 110
          Visible = True
        end>
    end
    object Panel5: TPanel
      Left = 2
      Top = 103
      Width = 601
      Height = 95
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 1
      object Label8: TLabel
        Left = 10
        Top = 46
        Width = 80
        Height = 13
        Caption = #1055#1088#1086#1076#1083#1080#1090#1100' '#1087#1086':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        Visible = False
      end
      object Label6: TLabel
        Left = 10
        Top = 71
        Width = 70
        Height = 13
        Caption = #1054#1089#1085#1086#1074#1072#1085#1080#1077':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        Visible = False
      end
      object RadioGroup6: TRadioGroup
        Left = 4
        Top = 1
        Width = 597
        Height = 33
        Columns = 2
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Items.Strings = (
          #1048#1079#1084#1077#1085#1080#1090#1100' '#1085#1086#1084#1077#1088' '#1087#1088#1080#1082#1072#1079#1072
          #1055#1088#1086#1076#1083#1080#1090#1100' '#1083#1080#1082#1074#1080#1076#1072#1094#1080#1102' '#1088#1072#1079#1085#1080#1094#1099)
        ParentFont = False
        TabOrder = 0
        OnClick = RadioGroup6Click
      end
      object Edit2: TEdit
        Left = 104
        Top = 67
        Width = 465
        Height = 21
        TabOrder = 1
        Visible = False
      end
      object DateTimePicker3: TDateTimePicker
        Left = 104
        Top = 40
        Width = 109
        Height = 21
        Date = 42628.441626562500000000
        Time = 42628.441626562500000000
        TabOrder = 2
        OnChange = DateTimePicker3Change
      end
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 606
    Width = 605
    Height = 51
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 2
    Visible = False
    object BitBtn2: TBitBtn
      Left = 360
      Top = 9
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
    end
    object Button1: TButton
      Left = 102
      Top = 9
      Width = 105
      Height = 33
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
      OnClick = Button1Click
    end
  end
  object Panel6: TPanel
    Left = 0
    Top = 228
    Width = 605
    Height = 178
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 4
    Visible = False
    object GroupBox1: TGroupBox
      Left = 0
      Top = 0
      Width = 605
      Height = 176
      Align = alTop
      Caption = #1051#1080#1082#1074#1080#1076#1072#1094#1080#1103' '#1088#1072#1079#1085#1080#1094#1099':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      Visible = False
      object Label1: TLabel
        Left = 10
        Top = 31
        Width = 55
        Height = 13
        Caption = #1055#1088#1080#1095#1080#1085#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label2: TLabel
        Left = 10
        Top = 59
        Width = 70
        Height = 13
        Caption = #1054#1089#1085#1086#1074#1072#1085#1080#1077':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label3: TLabel
        Left = 10
        Top = 88
        Width = 96
        Height = 13
        Caption = #1057' '#1082#1072#1082#1086#1075#1086' '#1095#1080#1089#1083#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label4: TLabel
        Left = 258
        Top = 88
        Width = 19
        Height = 13
        Caption = #1087#1086':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label5: TLabel
        Left = 357
        Top = 123
        Width = 97
        Height = 13
        Caption = #1057#1087#1077#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object DBLookupComboBox2: TDBLookupComboBox
        Left = 125
        Top = 27
        Width = 370
        Height = 21
        KeyField = 'N_TYPE_LIKVID'
        ListField = 'TEXT_LIKVID'
        ListSource = DataModule1.Type_LikvidSource
        TabOrder = 0
      end
      object DBLookupComboBox3: TDBLookupComboBox
        Left = 357
        Top = 143
        Width = 236
        Height = 21
        KeyField = 'N_SPECIALIZ'
        ListField = 'SPECIAL'
        ListSource = DataModule1.SpecializQSource
        TabOrder = 2
      end
      object RadioGroup3: TRadioGroup
        Left = 8
        Top = 119
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
        TabOrder = 3
      end
      object RadioGroup4: TRadioGroup
        Left = 126
        Top = 119
        Width = 105
        Height = 49
        Caption = #1050#1091#1088#1089':'
        Columns = 3
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Items.Strings = (
          '1'
          '2'
          '3'
          '4'
          '5'
          '6')
        ParentFont = False
        TabOrder = 5
      end
      object RadioGroup5: TRadioGroup
        Left = 245
        Top = 119
        Width = 105
        Height = 49
        Caption = #1054#1073#1091#1095#1077#1085#1080#1077':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Items.Strings = (
          #1041#1102#1076#1078#1077#1090
          #1044#1086#1075#1086#1074#1086#1088)
        ParentFont = False
        TabOrder = 4
      end
      object Edit1: TEdit
        Left = 125
        Top = 55
        Width = 370
        Height = 21
        TabOrder = 1
        Text = #1055#1088#1080#1082#1072#1079' '#8470' '
      end
      object DateTimePicker1: TDateTimePicker
        Left = 125
        Top = 82
        Width = 117
        Height = 21
        Date = 42628.441626562500000000
        Time = 42628.441626562500000000
        TabOrder = 6
        OnChange = DateTimePicker1Change
      end
      object DateTimePicker2: TDateTimePicker
        Left = 300
        Top = 82
        Width = 109
        Height = 21
        Date = 42628.441626562500000000
        Time = 42628.441626562500000000
        TabOrder = 7
        OnChange = DateTimePicker2Change
      end
    end
  end
  object Panel4: TPanel
    Left = 0
    Top = 73
    Width = 605
    Height = 155
    Align = alTop
    BevelInner = bvLowered
    TabOrder = 3
    Visible = False
    object Label7: TLabel
      Left = 10
      Top = 128
      Width = 61
      Height = 13
      Caption = #1060#1072#1084#1080#1083#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label12: TLabel
      Left = 10
      Top = 80
      Width = 85
      Height = 13
      Caption = #1042#1080#1076' '#1086#1073#1091#1095#1077#1085#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label13: TLabel
      Left = 10
      Top = 104
      Width = 63
      Height = 13
      Caption = #8470' '#1075#1088#1091#1087#1087#1099':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label14: TLabel
      Left = 10
      Top = 56
      Width = 70
      Height = 13
      Caption = #1060#1072#1082#1091#1083#1100#1090#1077#1090':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object RadioGroup2: TRadioGroup
      Left = 8
      Top = 8
      Width = 593
      Height = 41
      Caption = #1042#1099#1073#1086#1088' '#1089#1090#1091#1076#1077#1085#1090#1072' '#1085#1072' '#1083#1080#1082#1074#1080#1076#1072#1094#1080#1102' '#1088#1072#1079#1085#1080#1094#1099':'
      Columns = 4
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        #1044#1077#1081#1089#1090#1074#1091#1102#1097#1080#1077
        #1054#1090#1095#1080#1089#1083#1077#1085#1085#1099#1077
        #1040#1082#1072#1076#1077#1084'. '#1086#1090#1087#1091#1089#1082
        #1055#1086#1074#1090'. '#1075#1086#1076' '#1086#1073#1091#1095#1077#1085#1080#1103)
      ParentFont = False
      TabOrder = 0
      OnClick = RadioGroup2Click
    end
    object DBLookupComboBox1: TDBLookupComboBox
      Left = 125
      Top = 124
      Width = 440
      Height = 21
      KeyField = 'NOMER'
      ListField = 'FIO'
      ListSource = DataModule1.People_CaseSource
      TabOrder = 5
      Visible = False
    end
    object ComboBox3: TComboBox
      Left = 125
      Top = 76
      Width = 118
      Height = 21
      Style = csDropDownList
      TabOrder = 2
      Visible = False
      Items.Strings = (
        #1044#1085#1077#1074#1085#1086#1077
        #1047#1072#1086#1095#1085#1086#1077)
    end
    object Edit7: TEdit
      Left = 125
      Top = 100
      Width = 65
      Height = 21
      TabOrder = 3
      Visible = False
      OnKeyPress = Edit7KeyPress
    end
    object ComboBox4: TComboBox
      Left = 125
      Top = 52
      Width = 118
      Height = 21
      Style = csDropDownList
      TabOrder = 1
      Visible = False
      Items.Strings = (
        #1057#1048#1080#1045
        #1052#1042#1057
        #1054#1060#1050#1080#1058
        #1048#1052#1057#1080#1058)
    end
    object BitBtn3: TBitBtn
      Left = 300
      Top = 86
      Width = 121
      Height = 27
      Caption = #1053#1072#1081#1090#1080' '#1089#1090#1091#1076#1077#1085#1090#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
      Visible = False
      OnClick = BitBtn3Click
    end
  end
end

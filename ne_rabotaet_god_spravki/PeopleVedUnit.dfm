object PeopleVedForm: TPeopleVedForm
  Left = 274
  Top = 176
  Caption = #1057#1087#1080#1089#1086#1082' '#1074#1089#1077#1093' '#1074#1099#1076#1072#1085#1085#1099#1093' '#1089#1090#1091#1076#1077#1085#1090#1091' '#1074#1077#1076#1086#1084#1086#1089#1090#1077#1081
  ClientHeight = 510
  ClientWidth = 794
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel4: TPanel
    Left = 0
    Top = 0
    Width = 794
    Height = 137
    Align = alTop
    BevelInner = bvLowered
    TabOrder = 0
    ExplicitWidth = 761
    object Label7: TLabel
      Left = 10
      Top = 106
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
      Top = 58
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
      Top = 82
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
    object RadioGroup2: TRadioGroup
      Left = 8
      Top = 8
      Width = 593
      Height = 41
      Caption = #1042#1099#1073#1086#1088' '#1089#1090#1091#1076#1077#1085#1090#1072':'
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
      Top = 102
      Width = 440
      Height = 21
      KeyField = 'NOMER'
      ListField = 'FIO'
      ListSource = DataModule1.People_CaseSource
      TabOrder = 4
      Visible = False
      OnClick = DBLookupComboBox1Click
    end
    object ComboBox3: TComboBox
      Left = 125
      Top = 54
      Width = 118
      Height = 21
      TabOrder = 1
      Visible = False
      OnChange = ComboBox3Change
      Items.Strings = (
        #1044#1085#1077#1074#1085#1086#1077
        #1047#1072#1086#1095#1085#1086#1077)
    end
    object Edit7: TEdit
      Left = 125
      Top = 78
      Width = 65
      Height = 21
      TabOrder = 2
      Visible = False
      OnChange = ComboBox3Change
      OnKeyPress = Edit7KeyPress
    end
    object BitBtn3: TBitBtn
      Left = 300
      Top = 64
      Width = 121
      Height = 27
      Caption = #1053#1072#1081#1090#1080' '#1089#1090#1091#1076#1077#1085#1090#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      Visible = False
      OnClick = BitBtn3Click
    end
  end
  object Panel1: TPanel
    Left = 0
    Top = 137
    Width = 794
    Height = 41
    Align = alTop
    BevelInner = bvLowered
    TabOrder = 1
    Visible = False
    ExplicitWidth = 761
    object SpeedButton1: TSpeedButton
      Left = 456
      Top = 8
      Width = 23
      Height = 22
      Hint = #1055#1077#1088#1077#1076#1072#1090#1100' '#1076#1072#1085#1085#1099#1077' '#1074' Excel'
      Glyph.Data = {
        4E010000424D4E01000000000000760000002800000012000000120000000100
        040000000000D800000000000000000000001000000010000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
        7777770000007777777777777777770000007777777777770007770000007444
        4400000006007700000074FFFF08880600080700000074F008000060EE070700
        000074FFFFF8060EE0047700000074F0088060EE00F47700000074FFFF060EE0
        00747700000074F00800EE0EE0047700000074FFFF0EE0F0EE047700000074F0
        080000F000047700000074FFFFFFFFFFFFF47700000074444444444444447700
        000074F444F444F444F477000000744444444444444477000000777777777777
        777777000000777777777777777777000000}
      ParentShowHint = False
      ShowHint = True
      OnClick = SpeedButton1Click
    end
    object BitBtn1: TBitBtn
      Left = 125
      Top = 8
      Width = 217
      Height = 25
      Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1074#1077#1076#1086#1084#1086#1089#1090#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = BitBtn1Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 178
    Width = 794
    Height = 332
    Align = alClient
    BevelInner = bvLowered
    TabOrder = 2
    Visible = False
    ExplicitWidth = 761
    ExplicitHeight = 293
    object DBGrid1: TDBGrid
      Left = 2
      Top = 2
      Width = 790
      Height = 328
      Align = alClient
      DataSource = DataModule1.People_VedSource
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
          Alignment = taCenter
          Expanded = False
          FieldName = 'SEMESTR_VED'
          Title.Alignment = taCenter
          Title.Caption = #1057#1077#1084'.'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 31
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'YEAR1'
          Title.Alignment = taCenter
          Title.Caption = #1059#1095'.'#1075#1086#1076
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
          FieldName = 'N_VEDOMOST'
          Title.Alignment = taCenter
          Title.Caption = #8470' '#1074#1077#1076'.'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 52
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
          Width = 109
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
          Width = 65
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'CLOCK_PLAN_ALL'
          Title.Caption = #1042#1089#1077#1075#1086' '#1095#1072#1089#1086#1074
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'ZACH_EXAM1'
          Title.Alignment = taCenter
          Title.Caption = #1042#1080#1076' '#1082#1086#1085#1090#1088#1086#1083#1103
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 64
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'FIO_EXAM'
          Title.Alignment = taCenter
          Title.Caption = #1060#1048#1054' '#1101#1082#1079#1072#1084#1077#1085#1072#1090#1086#1088#1072
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 126
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'BALL1'
          Title.Alignment = taCenter
          Title.Caption = #1054#1094#1077#1085#1082#1072
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
          FieldName = 'D_EXAM'
          Title.Alignment = taCenter
          Title.Caption = #1044#1072#1090#1072
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 87
          Visible = True
        end>
    end
  end
  object ApplicationEvents1: TApplicationEvents
    OnMessage = ApplicationEvents1Message
    Left = 168
    Top = 256
  end
end

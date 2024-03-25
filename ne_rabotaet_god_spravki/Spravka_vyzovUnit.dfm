object Spravka_vyzovForm: TSpravka_vyzovForm
  Left = 0
  Top = 0
  Caption = 'Spravka_vyzovForm'
  ClientHeight = 253
  ClientWidth = 533
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 24
    Top = 16
    Width = 72
    Height = 13
    Caption = #1044#1072#1090#1072' '#1074#1099#1076#1072#1095#1080':'
  end
  object Label2: TLabel
    Left = 24
    Top = 40
    Width = 13
    Height = 13
    Caption = #8470
  end
  object Label3: TLabel
    Left = 24
    Top = 104
    Width = 24
    Height = 13
    Caption = #1050#1091#1088#1089
  end
  object Label4: TLabel
    Left = 7
    Top = 199
    Width = 5
    Height = 13
    Caption = #1089
  end
  object Label5: TLabel
    Left = 123
    Top = 199
    Width = 12
    Height = 13
    Caption = #1087#1086
  end
  object Label6: TLabel
    Left = 160
    Top = 104
    Width = 52
    Height = 13
    Caption = #1085#1072' '#1087#1077#1088#1080#1086#1076
  end
  object Button1: TButton
    Left = 432
    Top = 191
    Width = 73
    Height = 25
    Caption = #1055#1077#1095#1072#1090#1100
    TabOrder = 0
    OnClick = Button1Click
  end
  object DateTimePicker1: TDateTimePicker
    Left = 102
    Top = 13
    Width = 99
    Height = 21
    Date = 42891.604134861110000000
    Time = 42891.604134861110000000
    TabOrder = 1
  end
  object Edit1: TEdit
    Left = 79
    Top = 35
    Width = 38
    Height = 21
    TabOrder = 2
    Text = '1'
  end
  object DBLookupListBox1: TDBLookupListBox
    Left = 79
    Top = 62
    Width = 59
    Height = 95
    KeyField = 'INC_GROUP'
    ListField = 'N_GROUP'
    ListSource = DataSource1
    TabOrder = 3
  end
  object DateTimePicker2: TDateTimePicker
    Left = 18
    Top = 191
    Width = 99
    Height = 21
    Date = 42891.604134861110000000
    Time = 42891.604134861110000000
    TabOrder = 4
  end
  object DateTimePicker3: TDateTimePicker
    Left = 141
    Top = 191
    Width = 99
    Height = 21
    Date = 42891.604134861110000000
    Time = 42891.604134861110000000
    TabOrder = 5
  end
  object ListBox1: TListBox
    Left = 54
    Top = 64
    Width = 19
    Height = 75
    ItemHeight = 13
    Items.Strings = (
      '1'
      '2'
      '3'
      '4'
      '5')
    TabOrder = 6
    OnClick = ListBox1Click
  end
  object ListBox2: TListBox
    Left = 218
    Top = 62
    Width = 305
    Height = 123
    ItemHeight = 13
    Items.Strings = (
      #1091#1089#1090#1072#1085#1086#1074#1086#1095#1085#1086#1081' '#1089#1077#1089#1089#1080#1080
      #1089#1076#1072#1095#1080' '#1101#1082#1079#1072#1084#1077#1085#1086#1074' '#1080' '#1079#1072#1095#1105#1090#1086#1074
      #1075#1086#1089#1091#1076#1072#1088#1089#1090#1074#1077#1085#1085#1099#1093' '#1101#1082#1079#1072#1084#1077#1085#1086#1074
      #1086#1073#1079#1086#1088#1085#1099#1093' '#1083#1077#1082#1094#1080#1081
      #1091#1095#1077#1073#1085#1086#1081' '#1087#1088#1072#1082#1090#1080#1082#1080' '#1087#1086' '#1083#1099#1078#1085#1086#1084#1091' '#1089#1087#1086#1088#1090#1091
      #1091#1095#1077#1073#1085#1086#1081' '#1087#1088#1072#1082#1090#1080#1082#1080' '#1087#1086' '#1090#1091#1088#1080#1079#1084#1091
      #1091#1095#1077#1073#1085#1086#1081' '#1087#1088#1072#1082#1090#1080#1082#1080
      #1087#1088#1086#1092#1077#1089#1089#1080#1086#1085#1072#1083#1100#1085#1086'-'#1086#1088#1080#1077#1085#1090#1080#1088#1086#1074#1072#1085#1085#1086#1081' '#1091#1095#1077#1073#1085#1086#1081' '#1087#1088#1072#1082#1090#1080#1082#1080
      #1087#1088#1086#1080#1079#1074#1086#1076#1089#1090#1074#1077#1085#1085#1086#1081' '#1087#1088#1072#1082#1090#1080#1082#1080)
    TabOrder = 7
  end
  object FDQuery1: TFDQuery
    CachedUpdates = True
    Connection = DataModule1.FDConnection1
    SQL.Strings = (
      
        'select increment_group.n_group, increment_group.inc_group from i' +
        'ncrement_group'
      '')
    Left = 232
    Top = 8
    object FDQuery1N_GROUP: TStringField
      FieldName = 'N_GROUP'
      Size = 10
    end
    object FDQuery1INC_GROUP: TSmallintField
      FieldName = 'INC_GROUP'
      Origin = 'INC_GROUP'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
  end
  object DataSource1: TDataSource
    DataSet = FDQuery1
    Left = 288
    Top = 8
  end
  object FDQuery2: TFDQuery
    Connection = DataModule1.FDConnection1
    SQL.Strings = (
      
        'select people.nomer, people.fam, people.name, people.otch from p' +
        'eople, increment_group'
      'where people.vid_edu = 1'
      'and people.inc_group = increment_group.inc_group'
      'and people.status_people = 1'
      'and increment_group.inc_group = :inc_group'
      'order by people.fam, people.name, people.otch')
    Left = 384
    Top = 8
    ParamData = <
      item
        Name = 'INC_GROUP'
        ParamType = ptInput
      end>
    object FDQuery2NOMER: TIntegerField
      FieldName = 'NOMER'
      Required = True
    end
    object FDQuery2FAM: TStringField
      FieldName = 'FAM'
      Required = True
      Size = 30
    end
    object FDQuery2NAME: TStringField
      FieldName = 'NAME'
      Required = True
      Size = 30
    end
    object FDQuery2OTCH: TStringField
      FieldName = 'OTCH'
      Required = True
      Size = 30
    end
  end
  object DataSource2: TDataSource
    DataSet = FDQuery2
    Left = 440
    Top = 8
  end
end

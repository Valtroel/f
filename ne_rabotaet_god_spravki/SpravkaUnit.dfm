﻿object SpravkaForm: TSpravkaForm
  Left = 0
  Top = 0
  Caption = #1057#1087#1088#1072#1074#1082#1072
  ClientHeight = 455
  ClientWidth = 728
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 234
    Top = 8
    Width = 15
    Height = 16
    Caption = #8470
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 24
    Top = 12
    Width = 48
    Height = 13
    Caption = #1060#1072#1084#1080#1083#1080#1103':'
  end
  object Label4: TLabel
    Left = 344
    Top = 8
    Width = 129
    Height = 13
    Caption = #1103#1074#1083#1103#1077#1090#1089#1103' '#1086#1073#1091#1095#1072#1102#1097#1080#1084#1089#1103' '#1089
  end
  object Label2: TLabel
    Left = 32
    Top = 396
    Width = 94
    Height = 13
    Caption = #1052#1077#1089#1090#1086' '#1090#1088#1077#1073#1086#1074#1072#1085#1080#1103
  end
  object Печать: TButton
    Left = 512
    Top = 310
    Width = 99
    Height = 31
    Caption = #1055#1077#1095#1072#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = ПечатьClick
  end
  object DBGrid1: TDBGrid
    Left = 24
    Top = 35
    Width = 449
    Height = 112
    DataSource = DataSource2
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'Tahoma'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'FAM'
        Title.Caption = #1060#1072#1084#1080#1083#1080#1103
        Width = 114
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'NAME'
        Title.Caption = #1048#1084#1103
        Width = 103
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'OTCH'
        Title.Caption = #1054#1090#1095#1077#1089#1090#1074#1086
        Width = 119
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'N_GROUP'
        Title.Caption = #8470' '#1075#1088#1091#1087#1087#1099
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'KURS'
        ImeName = #1082#1091#1088#1089
        Title.Caption = #1050#1091#1088#1089
        Width = 30
        Visible = True
      end>
  end
  object Edit1: TEdit
    Left = 78
    Top = 8
    Width = 137
    Height = 21
    TabOrder = 2
    OnChange = Edit1Change
  end
  object CheckBox1: TCheckBox
    Left = 24
    Top = 180
    Width = 297
    Height = 17
    Caption = #1055#1086#1083#1091#1095#1072#1077#1090' '#1087#1077#1088#1074#1086#1077' '#1074#1099#1089#1096#1077#1077' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1077'.'
    TabOrder = 3
    OnClick = CheckBox1Click
  end
  object CheckBox2: TCheckBox
    Left = 24
    Top = 203
    Width = 297
    Height = 17
    Caption = #1054#1073#1091#1095#1072#1077#1090#1089#1103' '#1079#1072' '#1086#1087#1083#1072#1090#1091' '#1080#1083#1080' '#1079#1072' '#1089#1095#1077#1090' '#1073#1102#1076#1078#1077#1090#1085#1099#1093' '#1089#1088#1077#1076#1089#1090#1074'.'
    TabOrder = 4
    OnClick = CheckBox2Click
  end
  object CheckBox3: TCheckBox
    Left = 24
    Top = 272
    Width = 297
    Height = 17
    Caption = #1055#1088#1080#1073#1083#1080#1079#1080#1090#1077#1083#1100#1085#1099#1081' '#1089#1088#1086#1082' '#1086#1082#1086#1085#1095#1072#1085#1080#1103' '#1091#1095#1077#1073#1085#1086#1075#1086' '#1079#1072#1074#1077#1076#1077#1085#1080#1103
    TabOrder = 5
    OnClick = CheckBox3Click
  end
  object CheckBox4: TCheckBox
    Left = 24
    Top = 249
    Width = 297
    Height = 17
    TabOrder = 6
    OnClick = CheckBox4Click
  end
  object Memo1: TMemo
    Left = 327
    Top = 153
    Width = 393
    Height = 129
    TabOrder = 7
  end
  object Edit2: TEdit
    Left = 255
    Top = 8
    Width = 83
    Height = 21
    TabOrder = 8
  end
  object Edit3: TEdit
    Left = 479
    Top = 8
    Width = 18
    Height = 21
    TabOrder = 9
    Text = '01'
  end
  object Edit4: TEdit
    Left = 503
    Top = 8
    Width = 60
    Height = 21
    TabOrder = 10
    Text = #1089#1077#1085#1090#1103#1073#1088#1103
  end
  object Edit5: TEdit
    Left = 569
    Top = 8
    Width = 32
    Height = 21
    TabOrder = 11
    Text = '2017'
  end
  object RadioGroup1: TRadioGroup
    Left = 24
    Top = 312
    Width = 161
    Height = 65
    Caption = #1055#1086#1076#1087#1080#1089#1100
    ItemIndex = 0
    Items.Strings = (
      #1044#1077#1082#1072#1085' '#1092#1072#1082#1091#1083#1100#1090#1077#1090#1072
      #1047#1072#1084'. '#1076#1077#1082#1072#1085#1072' '#1092#1072#1082#1091#1083#1100#1090#1077#1090#1072)
    TabOrder = 12
  end
  object CheckBox5: TCheckBox
    Left = 32
    Top = 373
    Width = 153
    Height = 17
    Caption = #1056#1077#1082#1090#1086#1088' '#1091#1085#1080#1074#1077#1088#1089#1080#1090#1077#1090#1072
    TabOrder = 13
  end
  object Edit6: TEdit
    Left = 191
    Top = 342
    Width = 138
    Height = 21
    TabOrder = 14
  end
  object Edit7: TEdit
    Left = 191
    Top = 369
    Width = 138
    Height = 21
    TabOrder = 15
    Text = #1057'. '#1041'. '#1056#1077#1087#1082#1080#1085
  end
  object Edit8: TEdit
    Left = 191
    Top = 315
    Width = 138
    Height = 21
    TabOrder = 16
  end
  object Memo2: TMemo
    Left = 144
    Top = 396
    Width = 273
    Height = 41
    TabOrder = 17
  end
  object Edit9: TEdit
    Left = 24
    Top = 153
    Width = 297
    Height = 21
    TabOrder = 18
  end
  object CheckBox6: TCheckBox
    Left = 24
    Top = 226
    Width = 297
    Height = 17
    Caption = #1040#1082#1072#1076#1077#1084#1080#1095#1077#1089#1082#1080#1081' '#1086#1090#1087#1091#1089#1082' '#1085#1077' '#1087#1088#1077#1076#1086#1089#1090#1072#1074#1083#1103#1083#1089#1103'.'
    TabOrder = 19
    OnClick = CheckBox6Click
  end
  object FDQuery1: TFDQuery
    Connection = DataModule1.FDConnection1
    SQL.Strings = (
      
        'select people.fam, people.name, people.otch, people.d_prikaz_inc' +
        'lude, people.n_group, people.kurs,'
      
        ' people.vid_edu, faculty.fac_rp, '#39'"'#39' || specializ.special_direct' +
        'ion || '#39'"'#39' AS SPECIAL_DIRECTION, specializ.special, faculty.dean' +
        ','
      
        ' people.N_PRIKAZ_INCLUDE, people.n_found, SPECIAL_DIRECTION.code' +
        '_spec_dir, people.nomer, CK.n_ck'
      'from people, faculty, specializ, SPECIAL_DIRECTION, CK'
      'where people.n_fac = faculty.n_fac'
      'and people.n_specializ = specializ.n_specializ'
      'and people.nomer = :nomer'
      'and SPECIAL_DIRECTION.n_spec_dir = specializ.n_spec_dir'
      'and CK.nomer = :nomer'
      ''
      '')
    Left = 584
    Top = 104
    ParamData = <
      item
        Name = 'NOMER'
        DataType = ftInteger
        ParamType = ptInput
        Value = 24474
      end>
    object FDQuery1FAM: TStringField
      FieldName = 'FAM'
      Origin = 'FAM'
      Required = True
      Size = 30
    end
    object FDQuery1NAME: TStringField
      FieldName = 'NAME'
      Origin = 'NAME'
      Required = True
      Size = 30
    end
    object FDQuery1OTCH: TStringField
      FieldName = 'OTCH'
      Origin = 'OTCH'
      Required = True
      Size = 30
    end
    object FDQuery1D_PRIKAZ_INCLUDE: TSQLTimeStampField
      FieldName = 'D_PRIKAZ_INCLUDE'
      Origin = 'D_PRIKAZ_INCLUDE'
    end
    object FDQuery1N_GROUP: TStringField
      FieldName = 'N_GROUP'
      Origin = 'N_GROUP'
      FixedChar = True
      Size = 3
    end
    object FDQuery1KURS: TSmallintField
      FieldName = 'KURS'
      Origin = 'KURS'
      Required = True
    end
    object FDQuery1VID_EDU: TSmallintField
      FieldName = 'VID_EDU'
      Origin = 'VID_EDU'
      Required = True
    end
    object FDQuery1SPECIAL_DIRECTION: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'SPECIAL_DIRECTION'
      Origin = 'SPECIAL_DIRECTION'
      ProviderFlags = []
      ReadOnly = True
      Size = 255
    end
    object FDQuery1SPECIAL: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'SPECIAL'
      Origin = 'SPECIAL'
      ProviderFlags = []
      ReadOnly = True
      Size = 80
    end
    object FDQuery1DEAN: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'DEAN'
      Origin = 'DEAN'
      ProviderFlags = []
      ReadOnly = True
      Size = 30
    end
    object FDQuery1N_PRIKAZ_INCLUDE: TSmallintField
      FieldName = 'N_PRIKAZ_INCLUDE'
      Origin = 'N_PRIKAZ_INCLUDE'
    end
    object FDQuery1N_FOUND: TSmallintField
      FieldName = 'N_FOUND'
      Origin = 'N_FOUND'
    end
    object FDQuery1CODE_SPEC_DIR: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'CODE_SPEC_DIR'
      Origin = 'CODE_SPEC_DIR'
      ProviderFlags = []
      ReadOnly = True
      Size = 30
    end
    object FDQuery1FAC_RP: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'FAC_RP'
      Origin = 'FAC_RP'
      ProviderFlags = []
      ReadOnly = True
      Size = 70
    end
    object FDQuery1NOMER: TIntegerField
      FieldName = 'NOMER'
      Origin = 'NOMER'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object FDQuery1N_CK: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'N_CK'
      Origin = 'N_CK'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object DataSource1: TDataSource
    DataSet = FDQuery1
    Left = 632
    Top = 104
  end
  object FDQuery2: TFDQuery
    Connection = DataModule1.FDConnection1
    SQL.Strings = (
      
        'select people.nomer, people.fam, people.name, people.otch, peopl' +
        'e.n_group, people.kurs, faculty.dean from people, faculty'
      'where (people.status_people = 1 or people.status_people = 3) '
      'and people.n_fac = :fac'
      'and people.n_fac = faculty.n_fac'
      'order by people.fam, people.name, people.otch')
    Left = 488
    Top = 104
    ParamData = <
      item
        Name = 'FAC'
        DataType = ftSmallint
        ParamType = ptInput
      end>
    object FDQuery2NOMER: TIntegerField
      FieldName = 'NOMER'
      Origin = 'NOMER'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object FDQuery2FAM: TStringField
      FieldName = 'FAM'
      Origin = 'FAM'
      Required = True
      Size = 30
    end
    object FDQuery2NAME: TStringField
      FieldName = 'NAME'
      Origin = 'NAME'
      Required = True
      Size = 30
    end
    object FDQuery2OTCH: TStringField
      FieldName = 'OTCH'
      Origin = 'OTCH'
      Required = True
      Size = 30
    end
    object FDQuery2N_GROUP: TStringField
      FieldName = 'N_GROUP'
      Origin = 'N_GROUP'
      FixedChar = True
      Size = 3
    end
    object FDQuery2KURS: TSmallintField
      FieldName = 'KURS'
      Origin = 'KURS'
      Required = True
    end
    object FDQuery2DEAN: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'DEAN'
      Origin = 'DEAN'
      ProviderFlags = []
      ReadOnly = True
      Size = 30
    end
  end
  object DataSource2: TDataSource
    DataSet = FDQuery2
    OnDataChange = DataSource2DataChange
    Left = 536
    Top = 104
  end
  object FDQuery3: TFDQuery
    Connection = DataModule1.FDConnection1
    SQL.Strings = (
      'select MAX(restore.d_prikaz_res), restore.nomer from restore'
      'where restore.vid_restore = 0'
      'and  restore.nomer = :nomer'
      'group by restore.nomer ')
    Left = 488
    Top = 32
    ParamData = <
      item
        Name = 'NOMER'
        DataType = ftInteger
        ParamType = ptInput
      end>
    object FDQuery3MAX: TSQLTimeStampField
      AutoGenerateValue = arDefault
      FieldName = 'MAX'
      Origin = '"MAX"'
      ProviderFlags = []
      ReadOnly = True
    end
    object FDQuery3NOMER: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'NOMER'
      Origin = 'NOMER'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object FDQuery4: TFDQuery
    Connection = DataModule1.FDConnection1
    SQL.Strings = (
      'select holiday.nomer, MAX(holiday.d_end_hol) from holiday'
      'where (holiday.type_hol = 3 or holiday.type_hol = 6)'
      'and holiday.nomer = :nomer '
      'group by holiday.nomer')
    Left = 536
    Top = 32
    ParamData = <
      item
        Name = 'NOMER'
        DataType = ftInteger
        ParamType = ptInput
      end>
    object FDQuery4NOMER: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'NOMER'
      Origin = 'NOMER'
      ProviderFlags = []
      ReadOnly = True
    end
    object FDQuery4MAX: TSQLTimeStampField
      AutoGenerateValue = arDefault
      FieldName = 'MAX'
      Origin = '"MAX"'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object FDQuery5: TFDQuery
    Connection = DataModule1.FDConnection1
    SQL.Strings = (
      'select count(holiday.nomer) from holiday'
      'where holiday.nomer = :nomer '
      'group by holiday.nomer')
    Left = 584
    Top = 32
    ParamData = <
      item
        Name = 'NOMER'
        DataType = ftInteger
        ParamType = ptInput
      end>
    object FDQuery5COUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = '"COUNT"'
      ProviderFlags = []
      ReadOnly = True
    end
  end
end

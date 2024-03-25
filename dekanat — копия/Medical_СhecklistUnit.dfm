object Medical_Checklist_Form: TMedical_Checklist_Form
  Left = 0
  Top = 0
  Caption = #1042#1088#1072#1095#1077#1073#1085#1086'-'#1082#1086#1085#1090#1088#1086#1083#1100#1085#1072#1103' '#1082#1072#1088#1090#1072
  ClientHeight = 129
  ClientWidth = 293
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object DBLookupListBox1: TDBLookupListBox
    Left = 8
    Top = 8
    Width = 65
    Height = 108
    KeyField = 'INC_GROUP'
    ListField = 'N_GROUP'
    ListSource = DataSource2
    TabOrder = 0
  end
  object Button1: TButton
    Left = 160
    Top = 80
    Width = 75
    Height = 25
    Caption = #1055#1077#1095#1072#1090#1100
    TabOrder = 1
    OnClick = Button1Click
  end
  object FDQuery1: TFDQuery
    Connection = DataModule1.FDConnection1
    SQL.Strings = (
      
        'select people.nomer, people.fam, people.name, people.otch, peopl' +
        'e.photo, faculty.fac1,'
      
        'people.n_group, people.data_r, people.pol, people.address, peopl' +
        'e.phone,'
      
        'people.name_educ, vid_sport.vid_sport, category.text_sport_categ' +
        'ory'
      'from people, vid_sport, category, sport, faculty'
      'where people.nomer = sport.nomer'
      'and sport.n_vid_sport = vid_sport.n_vid_sport'
      'and sport.sport_category = category.sport_category'
      'and faculty.n_fac = people.n_fac'
      'and people.inc_group = :inc_group'
      'and people.d_prikaz_include > :year')
    Left = 168
    Top = 8
    ParamData = <
      item
        Name = 'INC_GROUP'
        ParamType = ptInput
      end
      item
        Name = 'YEAR'
        ParamType = ptInput
      end>
    object FDQuery1NOMER: TIntegerField
      FieldName = 'NOMER'
      Origin = 'NOMER'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
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
    object FDQuery1PHOTO: TBlobField
      FieldName = 'PHOTO'
      Origin = 'PHOTO'
    end
    object FDQuery1N_GROUP: TStringField
      FieldName = 'N_GROUP'
      Origin = 'N_GROUP'
      FixedChar = True
      Size = 3
    end
    object FDQuery1DATA_R: TSQLTimeStampField
      FieldName = 'DATA_R'
      Origin = 'DATA_R'
      Required = True
    end
    object FDQuery1POL: TStringField
      FieldName = 'POL'
      Origin = 'POL'
      Required = True
      FixedChar = True
      Size = 1
    end
    object FDQuery1ADDRESS: TStringField
      FieldName = 'ADDRESS'
      Origin = 'ADDRESS'
      Required = True
      Size = 100
    end
    object FDQuery1PHONE: TStringField
      FieldName = 'PHONE'
      Origin = 'PHONE'
      Size = 30
    end
    object FDQuery1NAME_EDUC: TStringField
      FieldName = 'NAME_EDUC'
      Origin = 'NAME_EDUC'
      Required = True
      Size = 50
    end
    object FDQuery1VID_SPORT: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'VID_SPORT'
      Origin = 'VID_SPORT'
      ProviderFlags = []
      ReadOnly = True
      Size = 30
    end
    object FDQuery1TEXT_SPORT_CATEGORY: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'TEXT_SPORT_CATEGORY'
      Origin = 'TEXT_SPORT_CATEGORY'
      ProviderFlags = []
      ReadOnly = True
      Size = 50
    end
    object FDQuery1FAC1: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'FAC1'
      Origin = 'FAC1'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object DataSource1: TDataSource
    DataSet = FDQuery1
    Left = 224
    Top = 8
  end
  object FDQuery2: TFDQuery
    Connection = DataModule1.FDConnection1
    SQL.Strings = (
      
        'select increment_group.n_group, increment_group.inc_group from i' +
        'ncrement_group'
      'where increment_group.vid_edu = 0')
    Left = 48
    Top = 8
    object FDQuery2N_GROUP: TStringField
      FieldName = 'N_GROUP'
      Origin = 'N_GROUP'
      Size = 10
    end
    object FDQuery2INC_GROUP: TSmallintField
      FieldName = 'INC_GROUP'
      Origin = 'INC_GROUP'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
  end
  object DataSource2: TDataSource
    DataSet = FDQuery2
    Left = 104
    Top = 8
  end
end

object DM2: TDM2
  OldCreateOrder = False
  Height = 467
  Width = 1107
  object CategorySource: TDataSource
    DataSet = CategoryFDTable
    Left = 45
    Top = 56
  end
  object Cause_RestoreSource: TDataSource
    DataSet = Cause_RestoreFDTable
    Left = 528
    Top = 152
  end
  object Type_EncourageSource: TDataSource
    DataSet = Type_EncourageFDTable
    Left = 288
    Top = 152
  end
  object Type_PrikazSource: TDataSource
    DataSet = Type_PrikazFDTable
    Left = 1008
    Top = 152
  end
  object Vid_SportSource: TDataSource
    DataSet = Vid_SportFDTable
    Left = 776
    Top = 56
  end
  object Prikaz_KursSource: TDataSource
    DataSet = Prikaz_KursFDTable
    Left = 168
    Top = 152
  end
  object Cause_PassSource: TDataSource
    DataSet = Cause_PassFDTable
    Left = 888
    Top = 152
  end
  object Increment_GroupSource: TDataSource
    DataSet = Increment_GroupFDTable
    Left = 656
    Top = 56
  end
  object Object_PlanSource: TDataSource
    DataSet = Object_PlanFDTable
    Left = 48
    Top = 152
  end
  object Cause_HolidaySource: TDataSource
    DataSet = Cause_HolidayFDTable
    Left = 768
    Top = 152
  end
  object SpecializSource: TDataSource
    DataSet = SpecializFDTable
    Left = 296
    Top = 56
  end
  object SpecialitySource: TDataSource
    DataSet = SpecialityFDTable
    Left = 984
    Top = 56
  end
  object FacultySource: TDataSource
    DataSet = FacultyFDTable
    Left = 648
    Top = 152
  end
  object DataSourceQualification: TDataSource
    DataSet = QualificationFDTable
    Left = 536
    Top = 56
  end
  object FoundationSource: TDataSource
    DataSet = FoundationFDTable
    Left = 416
    Top = 56
  end
  object DataSource1: TDataSource
    DataSet = FDTable1
    Left = 408
    Top = 152
  end
  object Vid_SportFDTable: TFDTable
    AfterOpen = Vid_SportFDTableAfterOpen
    OnNewRecord = Vid_SportFDTableNewRecord
    CachedUpdates = True
    IndexFieldNames = 'VID_SPORT'
    Connection = DataModule1.FDConnection1
    UpdateOptions.UpdateTableName = 'VID_SPORT'
    TableName = 'VID_SPORT'
    Left = 776
    Top = 8
    object Vid_SportFDTableN_VID_SPORT: TSmallintField
      FieldName = 'N_VID_SPORT'
      Origin = 'N_VID_SPORT'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object Vid_SportFDTableVID_SPORT: TStringField
      FieldName = 'VID_SPORT'
      Origin = 'VID_SPORT'
      Required = True
      Size = 30
    end
  end
  object CategoryFDTable: TFDTable
    CachedUpdates = True
    IndexFieldNames = 'SPORT_CATEGORY'
    Connection = DataModule1.FDConnection1
    UpdateOptions.UpdateTableName = 'CATEGORY'
    TableName = 'CATEGORY'
    Left = 48
    Top = 8
    object CategoryFDTableSPORT_CATEGORY: TSmallintField
      FieldName = 'SPORT_CATEGORY'
      Origin = 'SPORT_CATEGORY'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object CategoryFDTableTEXT_SPORT_CATEGORY: TStringField
      FieldName = 'TEXT_SPORT_CATEGORY'
      Origin = 'TEXT_SPORT_CATEGORY'
      Size = 50
    end
  end
  object SpecializFDTable: TFDTable
    AfterOpen = SpecializFDTableAfterOpen
    OnNewRecord = SpecializFDTableNewRecord
    CachedUpdates = True
    IndexFieldNames = 'SPECIAL'
    Connection = DataModule1.FDConnection1
    UpdateOptions.UpdateTableName = 'SPECIALIZ'
    TableName = 'SPECIALIZ'
    Left = 296
    Top = 8
    object SpecializFDTableN_SPECIALIZ: TSmallintField
      FieldName = 'N_SPECIALIZ'
      Origin = 'N_SPECIALIZ'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object SpecializFDTableCODE_SPECIALIZ: TStringField
      FieldName = 'CODE_SPECIALIZ'
      Origin = 'CODE_SPECIALIZ'
      Required = True
      Size = 15
    end
    object SpecializFDTableSPECIAL: TStringField
      FieldName = 'SPECIAL'
      Origin = 'SPECIAL'
      Required = True
      Size = 80
    end
    object SpecializFDTableN_FAC: TSmallintField
      FieldName = 'N_FAC'
      Origin = 'N_FAC'
      Required = True
    end
    object SpecializFDTableN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
      Required = True
    end
    object SpecializFDTableSPECIAL_SKLON: TStringField
      FieldName = 'SPECIAL_SKLON'
      Origin = 'SPECIAL_SKLON'
      Size = 80
    end
    object SpecializFDTableSPECIAL_DIRECTION: TStringField
      FieldName = 'SPECIAL_DIRECTION'
      Origin = 'SPECIAL_DIRECTION'
      Size = 255
    end
    object SpecializFDTableN_SPEC_DIR: TIntegerField
      FieldName = 'N_SPEC_DIR'
      Origin = 'N_SPEC_DIR'
    end
  end
  object FoundationFDTable: TFDTable
    AfterOpen = FoundationFDTableAfterOpen
    OnNewRecord = FoundationFDTableNewRecord
    CachedUpdates = True
    IndexFieldNames = 'VID_FOUND'
    Connection = DataModule1.FDConnection1
    UpdateOptions.UpdateTableName = 'FOUNDATION'
    TableName = 'FOUNDATION'
    Left = 416
    Top = 8
    object FoundationFDTableN_FOUND: TSmallintField
      FieldName = 'N_FOUND'
      Origin = 'N_FOUND'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object FoundationFDTableVID_FOUND: TStringField
      FieldName = 'VID_FOUND'
      Origin = 'VID_FOUND'
      Size = 100
    end
  end
  object QualificationFDTable: TFDTable
    IndexFieldNames = 'NOMER_QU'
    Connection = DataModule1.FDConnection1
    UpdateOptions.UpdateTableName = 'QUALIFICATION'
    TableName = 'QUALIFICATION'
    Left = 536
    Top = 8
    object QualificationFDTableNOMER_QU: TSmallintField
      FieldName = 'NOMER_QU'
      Origin = 'NOMER_QU'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object QualificationFDTableNAME: TStringField
      FieldName = 'NAME'
      Origin = 'NAME'
      Size = 255
    end
    object QualificationFDTableDESCRIBE: TStringField
      FieldName = 'DESCRIBE'
      Origin = '"DESCRIBE"'
      Size = 255
    end
  end
  object Increment_GroupFDTable: TFDTable
    OnNewRecord = Increment_GroupFDTableNewRecord
    CachedUpdates = True
    IndexFieldNames = 'INC_GROUP'
    Connection = DataModule1.FDConnection1
    UpdateOptions.UpdateTableName = 'INCREMENT_GROUP'
    TableName = 'INCREMENT_GROUP'
    Left = 656
    Top = 8
    object Increment_GroupFDTableINC_GROUP: TSmallintField
      FieldName = 'INC_GROUP'
      Origin = 'INC_GROUP'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object Increment_GroupFDTableVID_EDU: TSmallintField
      FieldName = 'VID_EDU'
      Origin = 'VID_EDU'
    end
    object Increment_GroupFDTableGOD: TIntegerField
      FieldName = 'GOD'
      Origin = 'GOD'
    end
    object Increment_GroupFDTableN_GROUP: TStringField
      FieldName = 'N_GROUP'
      Origin = 'N_GROUP'
      Size = 10
    end
  end
  object Special_DirFDTable: TFDTable
    AfterOpen = Special_DirFDTableAfterOpen
    OnNewRecord = Special_DirFDTableNewRecord
    CachedUpdates = True
    IndexFieldNames = 'N_SPEC_DIR'
    Connection = DataModule1.FDConnection1
    UpdateOptions.UpdateTableName = 'SPECIAL_DIRECTION'
    TableName = 'SPECIAL_DIRECTION'
    Left = 896
    Top = 8
    object Special_DirFDTableN_SPEC_DIR: TIntegerField
      FieldName = 'N_SPEC_DIR'
      Origin = 'N_SPEC_DIR'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object Special_DirFDTableSPEC_DIR: TStringField
      FieldName = 'SPEC_DIR'
      Origin = 'SPEC_DIR'
      Size = 255
    end
    object Special_DirFDTableSPEC_DIR_FULL: TStringField
      FieldName = 'SPEC_DIR_FULL'
      Origin = 'SPEC_DIR_FULL'
      Size = 255
    end
    object Special_DirFDTableCODE_SPEC_DIR: TStringField
      FieldName = 'CODE_SPEC_DIR'
      Origin = 'CODE_SPEC_DIR'
      Size = 30
    end
    object Special_DirFDTableN_SPEC: TIntegerField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
      Required = True
    end
  end
  object SpecialityFDTable: TFDTable
    AfterOpen = SpecialityFDTableAfterOpen
    OnNewRecord = SpecialityFDTableNewRecord
    CachedUpdates = True
    IndexFieldNames = 'SPEC'
    Connection = DataModule1.FDConnection1
    UpdateOptions.UpdateTableName = 'SPECIALITY'
    TableName = 'SPECIALITY'
    Left = 984
    Top = 8
    object SpecialityFDTableN_SPEC: TSmallintField
      FieldName = 'N_SPEC'
      Origin = 'N_SPEC'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object SpecialityFDTableSPEC: TStringField
      FieldName = 'SPEC'
      Origin = 'SPEC'
      Required = True
      Size = 255
    end
    object SpecialityFDTableOLD_NUM: TSmallintField
      FieldName = 'OLD_NUM'
      Origin = 'OLD_NUM'
    end
    object SpecialityFDTableCODE_SPEC: TStringField
      FieldName = 'CODE_SPEC'
      Origin = 'CODE_SPEC'
      Required = True
      Size = 10
    end
  end
  object Object_PlanFDTable: TFDTable
    AfterOpen = Object_PlanFDTableAfterOpen
    OnNewRecord = Object_PlanFDTableNewRecord
    CachedUpdates = True
    IndexFieldNames = 'NAME_OBJECT'
    Connection = DataModule1.FDConnection1
    UpdateOptions.UpdateTableName = 'OBJECT_PLAN'
    TableName = 'OBJECT_PLAN'
    Left = 48
    Top = 104
    object Object_PlanFDTableN_OBJECT: TSmallintField
      FieldName = 'N_OBJECT'
      Origin = 'N_OBJECT'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object Object_PlanFDTableALL_CLOCK_PLAN: TSmallintField
      FieldName = 'ALL_CLOCK_PLAN'
      Origin = 'ALL_CLOCK_PLAN'
      Required = True
    end
    object Object_PlanFDTableNAME_OBJECT: TStringField
      FieldName = 'NAME_OBJECT'
      Origin = 'NAME_OBJECT'
      Size = 250
    end
    object Object_PlanFDTableINTEGR_MODUL: TSmallintField
      FieldName = 'INTEGR_MODUL'
      Origin = 'INTEGR_MODUL'
      Required = True
    end
    object Object_PlanFDTableSHORT_NAME: TStringField
      FieldName = 'SHORT_NAME'
      Origin = 'SHORT_NAME'
      Size = 64
    end
  end
  object Prikaz_KursFDTable: TFDTable
    AfterOpen = Prikaz_KursFDTableAfterOpen
    CachedUpdates = True
    IndexFieldNames = 'NOMER'
    Connection = DataModule1.FDConnection1
    UpdateOptions.UpdateTableName = 'PRIKAZ_KURS'
    TableName = 'PRIKAZ_KURS'
    Left = 168
    Top = 104
    object Prikaz_KursFDTableNOMER: TIntegerField
      FieldName = 'NOMER'
      Origin = 'NOMER'
    end
    object Prikaz_KursFDTableN_KURS: TSmallintField
      FieldName = 'N_KURS'
      Origin = 'N_KURS'
    end
    object Prikaz_KursFDTableD_PRIKAZ_KURS: TSQLTimeStampField
      FieldName = 'D_PRIKAZ_KURS'
      Origin = 'D_PRIKAZ_KURS'
    end
    object Prikaz_KursFDTableN_PRIKAZ_KURS: TSmallintField
      FieldName = 'N_PRIKAZ_KURS'
      Origin = 'N_PRIKAZ_KURS'
    end
    object Prikaz_KursFDTableN_FAC: TSmallintField
      FieldName = 'N_FAC'
      Origin = 'N_FAC'
    end
    object Prikaz_KursFDTableVID_EDU: TSmallintField
      FieldName = 'VID_EDU'
      Origin = 'VID_EDU'
    end
  end
  object Type_EncourageFDTable: TFDTable
    AfterOpen = Type_EncourageFDTableAfterOpen
    OnNewRecord = Type_EncourageFDTableNewRecord
    CachedUpdates = True
    IndexFieldNames = 'VID_EN'
    Connection = DataModule1.FDConnection1
    UpdateOptions.UpdateTableName = 'TYPE_ENCOURAGE'
    TableName = 'TYPE_ENCOURAGE'
    Left = 288
    Top = 104
    object Type_EncourageFDTableN_TYPE_EN: TSmallintField
      FieldName = 'N_TYPE_EN'
      Origin = 'N_TYPE_EN'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object Type_EncourageFDTableVID_EN: TStringField
      FieldName = 'VID_EN'
      Origin = 'VID_EN'
      Required = True
      Size = 50
    end
    object Type_EncourageFDTableTYPE_EN: TSmallintField
      FieldName = 'TYPE_EN'
      Origin = 'TYPE_EN'
    end
  end
  object FDTable1: TFDTable
    AfterOpen = FDTable1AfterOpen
    CachedUpdates = True
    Connection = DataModule1.FDConnection1
    UpdateOptions.UpdateTableName = 'PASSWORD_USER'
    TableName = 'PASSWORD_USER'
    Left = 408
    Top = 104
    object FDTable1USER_NAME: TStringField
      FieldName = 'USER_NAME'
      Origin = 'USER_NAME'
    end
    object FDTable1USER_PASSWORD: TStringField
      FieldName = 'USER_PASSWORD'
      Origin = 'USER_PASSWORD'
      Size = 12
    end
    object FDTable1N_FAC: TSmallintField
      FieldName = 'N_FAC'
      Origin = 'N_FAC'
    end
  end
  object Cause_RestoreFDTable: TFDTable
    AfterOpen = Cause_RestoreFDTableAfterOpen
    OnNewRecord = Cause_RestoreFDTableNewRecord
    CachedUpdates = True
    IndexFieldNames = 'CAUSE_RES'
    Connection = DataModule1.FDConnection1
    UpdateOptions.UpdateTableName = 'CAUSE_RESTORE'
    TableName = 'CAUSE_RESTORE'
    Left = 528
    Top = 104
    object Cause_RestoreFDTableN_CAUSE_RESTORE: TSmallintField
      FieldName = 'N_CAUSE_RESTORE'
      Origin = 'N_CAUSE_RESTORE'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object Cause_RestoreFDTableCAUSE_RES: TStringField
      FieldName = 'CAUSE_RES'
      Origin = 'CAUSE_RES'
      Size = 250
    end
  end
  object FacultyFDTable: TFDTable
    AfterOpen = FacultyFDTableAfterOpen
    OnNewRecord = FacultyFDTableNewRecord
    CachedUpdates = True
    IndexFieldNames = 'FAC'
    Connection = DataModule1.FDConnection1
    UpdateOptions.UpdateTableName = 'FACULTY'
    TableName = 'FACULTY'
    Left = 648
    Top = 104
    object FacultyFDTableN_FAC: TSmallintField
      FieldName = 'N_FAC'
      Origin = 'N_FAC'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object FacultyFDTableFAC: TStringField
      FieldName = 'FAC'
      Origin = 'FAC'
      Size = 70
    end
    object FacultyFDTableFAC1: TStringField
      FieldName = 'FAC1'
      Origin = 'FAC1'
      Required = True
    end
    object FacultyFDTableKOD_FAC: TSmallintField
      FieldName = 'KOD_FAC'
      Origin = 'KOD_FAC'
    end
    object FacultyFDTableDEAN: TStringField
      FieldName = 'DEAN'
      Origin = 'DEAN'
      Size = 30
    end
    object FacultyFDTableFAC_RP: TStringField
      FieldName = 'FAC_RP'
      Origin = 'FAC_RP'
      Size = 70
    end
    object FacultyFDTableFAC_PP: TStringField
      FieldName = 'FAC_PP'
      Origin = 'FAC_PP'
      Size = 70
    end
    object FacultyFDTableFAC2: TStringField
      FieldName = 'FAC2'
      Origin = 'FAC2'
      Size = 70
    end
  end
  object Cause_HolidayFDTable: TFDTable
    AfterOpen = Cause_HolidayFDTableAfterOpen
    OnNewRecord = Cause_HolidayFDTableNewRecord
    CachedUpdates = True
    IndexFieldNames = 'CAUSE_HOL'
    Connection = DataModule1.FDConnection1
    UpdateOptions.UpdateTableName = 'CAUSE_HOLIDAY'
    TableName = 'CAUSE_HOLIDAY'
    Left = 768
    Top = 104
    object Cause_HolidayFDTableN_HOL: TSmallintField
      FieldName = 'N_HOL'
      Origin = 'N_HOL'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object Cause_HolidayFDTableCAUSE_HOL: TStringField
      FieldName = 'CAUSE_HOL'
      Origin = 'CAUSE_HOL'
      Required = True
      Size = 60
    end
  end
  object Cause_PassFDTable: TFDTable
    AfterOpen = Cause_PassFDTableAfterOpen
    OnNewRecord = Cause_PassFDTableNewRecord
    CachedUpdates = True
    IndexFieldNames = 'N_CAUSE'
    Connection = DataModule1.FDConnection1
    UpdateOptions.UpdateTableName = 'CAUSE_PASS'
    TableName = 'CAUSE_PASS'
    Left = 888
    Top = 104
    object Cause_PassFDTableN_CAUSE: TSmallintField
      FieldName = 'N_CAUSE'
      Origin = 'N_CAUSE'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object Cause_PassFDTableCAUSE: TStringField
      FieldName = 'CAUSE'
      Origin = 'CAUSE'
      Size = 70
    end
  end
  object Type_PrikazFDTable: TFDTable
    OnNewRecord = Type_PrikazFDTableNewRecord
    CachedUpdates = True
    IndexFieldNames = 'N_TYPE'
    Connection = DataModule1.FDConnection1
    UpdateOptions.UpdateTableName = 'PUBLIC_TYPE_PRIKAZ'
    TableName = 'PUBLIC_TYPE_PRIKAZ'
    Left = 1008
    Top = 104
    object Type_PrikazFDTableN_TYPE: TSmallintField
      FieldName = 'N_TYPE'
      Origin = 'N_TYPE'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object Type_PrikazFDTableTYPE_PRIKAZ: TStringField
      FieldName = 'TYPE_PRIKAZ'
      Origin = 'TYPE_PRIKAZ'
      Size = 80
    end
  end
  object DSCountries_ocrb: TDataSource
    DataSet = Countries_ocrbTable
    Left = 48
    Top = 267
  end
  object Countries_ocrbTable: TFDTable
    CachedUpdates = True
    IndexFieldNames = 'SHORT_NAME'
    Connection = DataModule1.FDConnection1
    UpdateOptions.UpdateTableName = 'COUNTRIES_OCRB'
    TableName = 'COUNTRIES_OCRB'
    Left = 48
    Top = 211
    object Countries_ocrbTableDIGITAL_CODE: TIntegerField
      FieldName = 'DIGITAL_CODE'
      Origin = 'DIGITAL_CODE'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
    object Countries_ocrbTableSHORT_NAME: TStringField
      FieldName = 'SHORT_NAME'
      Origin = 'SHORT_NAME'
      Required = True
      Size = 60
    end
    object Countries_ocrbTableFULL_NAME: TStringField
      FieldName = 'FULL_NAME'
      Origin = 'FULL_NAME'
      Size = 150
    end
    object Countries_ocrbTableLETTER_CODE_2: TStringField
      FieldName = 'LETTER_CODE_2'
      Origin = 'LETTER_CODE_2'
      Required = True
      Size = 2
    end
    object Countries_ocrbTableLETTER_CODE_3: TStringField
      FieldName = 'LETTER_CODE_3'
      Origin = 'LETTER_CODE_3'
      Required = True
      Size = 3
    end
  end
end

object DM4: TDM4
  OldCreateOrder = False
  Height = 427
  Width = 593
  object TrStudQ: TFDQuery
    CachedUpdates = True
    UpdateObject = TrStudUp
    SQL.Strings = (
      'select '
      '    student_tr.rowguid,'
      '    student_tr.fam_tr,'
      '    student_tr.name_tr,'
      '    student_tr.otch_tr,'
      '    student_tr.active_student,'
      '    student_tr.id_fac,'
      '    student_tr.id_vid_edu,'
      '    student_tr.id_spec,'
      '    student_tr.id_kurs,'
      '    student_tr.id_stud_type,'
      '    student_tr.nom_z,'
      '    student_tr.pol,'
      '    student_tr.uch_year,'
      '    student_tr.date_end,'
      '    student_tr.date_zach,'
      '    student_tr.add_year,'
      '    student_tr.cityzenship,'
      '    student_tr.n_group,'
      '    student_tr.dekan,'
      '    student_tr.id_vuz,'
      '    pasport_tr.rowguid,'
      '    pasport_tr.personal_number,'
      '    pasport_tr.series,'
      '    pasport_tr.number,'
      '    pasport_tr.pasport,'
      '    pers_stud_tr.rowguid,'
      '    pers_stud_tr.login,'
      '    pers_stud_tr.e_mail'
      'from student_tr'
      
        '  left join pasport_tr on (student_tr.rowguid = pasport_tr.rowgu' +
        'id)'
      
        '  left join pers_stud_tr on (student_tr.rowguid = pers_stud_tr.r' +
        'owguid)')
    Left = 32
    Top = 64
    object TrStudQROWGUID: TIntegerField
      FieldName = 'ROWGUID'
      Origin = 'ROWGUID'
      Required = True
    end
    object TrStudQFAM_TR: TStringField
      FieldName = 'FAM_TR'
      Origin = 'FAM_TR'
      Required = True
      Size = 50
    end
    object TrStudQNAME_TR: TStringField
      FieldName = 'NAME_TR'
      Origin = 'NAME_TR'
      Size = 50
    end
    object TrStudQOTCH_TR: TStringField
      FieldName = 'OTCH_TR'
      Origin = 'OTCH_TR'
      Size = 50
    end
    object TrStudQACTIVE_STUDENT: TIntegerField
      FieldName = 'ACTIVE_STUDENT'
      Origin = 'ACTIVE_STUDENT'
      Required = True
    end
    object TrStudQID_FAC: TIntegerField
      FieldName = 'ID_FAC'
      Origin = 'ID_FAC'
      Required = True
    end
    object TrStudQID_VID_EDU: TIntegerField
      FieldName = 'ID_VID_EDU'
      Origin = 'ID_VID_EDU'
      Required = True
    end
    object TrStudQID_SPEC: TIntegerField
      FieldName = 'ID_SPEC'
      Origin = 'ID_SPEC'
      Required = True
    end
    object TrStudQID_KURS: TIntegerField
      FieldName = 'ID_KURS'
      Origin = 'ID_KURS'
      Required = True
    end
    object TrStudQID_STUD_TYPE: TIntegerField
      FieldName = 'ID_STUD_TYPE'
      Origin = 'ID_STUD_TYPE'
      Required = True
    end
    object TrStudQNOM_Z: TStringField
      FieldName = 'NOM_Z'
      Origin = 'NOM_Z'
      Required = True
      Size = 10
    end
    object TrStudQPOL: TIntegerField
      FieldName = 'POL'
      Origin = 'POL'
      Required = True
    end
    object TrStudQUCH_YEAR: TStringField
      FieldName = 'UCH_YEAR'
      Origin = 'UCH_YEAR'
      Required = True
      Size = 50
    end
    object TrStudQDATE_END: TSQLTimeStampField
      FieldName = 'DATE_END'
      Origin = 'DATE_END'
    end
    object TrStudQDATE_ZACH: TSQLTimeStampField
      FieldName = 'DATE_ZACH'
      Origin = 'DATE_ZACH'
    end
    object TrStudQADD_YEAR: TIntegerField
      FieldName = 'ADD_YEAR'
      Origin = 'ADD_YEAR'
    end
    object TrStudQCITYZENSHIP: TStringField
      FieldName = 'CITYZENSHIP'
      Origin = 'CITYZENSHIP'
      Size = 33
    end
    object TrStudQN_GROUP: TStringField
      FieldName = 'N_GROUP'
      Origin = 'N_GROUP'
      Required = True
      Size = 16
    end
    object TrStudQDEKAN: TIntegerField
      FieldName = 'DEKAN'
      Origin = 'DEKAN'
    end
    object TrStudQID_VUZ: TIntegerField
      FieldName = 'ID_VUZ'
      Origin = 'ID_VUZ'
    end
    object TrStudQROWGUID_1: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'ROWGUID_1'
      Origin = 'ROWGUID'
      ProviderFlags = []
      ReadOnly = True
    end
    object TrStudQPERSONAL_NUMBER: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'PERSONAL_NUMBER'
      Origin = 'PERSONAL_NUMBER'
      ProviderFlags = []
      ReadOnly = True
    end
    object TrStudQSERIES: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'SERIES'
      Origin = 'SERIES'
      ProviderFlags = []
      ReadOnly = True
      Size = 10
    end
    object TrStudQNUMBER: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'NUMBER'
      Origin = 'NUMBER'
      ProviderFlags = []
      ReadOnly = True
      Size = 10
    end
    object TrStudQPASPORT: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'PASPORT'
      Origin = 'PASPORT'
      ProviderFlags = []
      ReadOnly = True
    end
    object TrStudQROWGUID_2: TIntegerField
      AutoGenerateValue = arDefault
      FieldName = 'ROWGUID_2'
      Origin = 'ROWGUID'
      ProviderFlags = []
      ReadOnly = True
    end
    object TrStudQLOGIN: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'LOGIN'
      Origin = 'LOGIN'
      ProviderFlags = []
      ReadOnly = True
      Size = 40
    end
    object TrStudQE_MAIL: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'E_MAIL'
      Origin = 'E_MAIL'
      ProviderFlags = []
      ReadOnly = True
      Size = 40
    end
  end
  object TrStudQ_Count: TFDQuery
    SQL.Strings = (
      'select COUNT(student_tr.rowguid)'
      'from student_tr'
      
        '  left join pasport_tr on (student_tr.rowguid = pasport_tr.rowgu' +
        'id)'
      
        '  left join pers_stud_tr on (student_tr.rowguid = pers_stud_tr.r' +
        'owguid)')
    Left = 32
    Top = 120
    object TrStudQ_CountCOUNT: TLargeintField
      AutoGenerateValue = arDefault
      FieldName = 'COUNT'
      Origin = '"COUNT"'
      ProviderFlags = []
      ReadOnly = True
    end
  end
  object TrPasportQ: TFDQuery
    CachedUpdates = True
    SQL.Strings = (
      'select '
      '    pasport_tr.rowguid,'
      '    pasport_tr.personal_number,'
      '    pasport_tr.series,'
      '    pasport_tr.number,'
      '    pasport_tr.pasport'
      'from pasport_tr'
      'where rowguid=:rowguid')
    Left = 32
    Top = 176
    ParamData = <
      item
        Name = 'ROWGUID'
        DataType = ftInteger
        ParamType = ptInput
      end>
    object TrPasportQROWGUID: TIntegerField
      FieldName = 'ROWGUID'
      Origin = 'ROWGUID'
      Required = True
    end
    object TrPasportQPERSONAL_NUMBER: TStringField
      FieldName = 'PERSONAL_NUMBER'
      Origin = 'PERSONAL_NUMBER'
    end
    object TrPasportQSERIES: TStringField
      FieldName = 'SERIES'
      Origin = 'SERIES'
      Size = 10
    end
    object TrPasportQNUMBER: TStringField
      FieldName = 'NUMBER'
      Origin = 'NUMBER'
      Size = 10
    end
    object TrPasportQPASPORT: TStringField
      FieldName = 'PASPORT'
      Origin = 'PASPORT'
    end
  end
  object TrPersQ: TFDQuery
    CachedUpdates = True
    SQL.Strings = (
      'select '
      '    pers_stud_tr.rowguid,'
      '    pers_stud_tr.login,'
      '    pers_stud_tr.e_mail'
      'from pers_stud_tr'
      'where rowguid=:rowguid')
    Left = 32
    Top = 232
    ParamData = <
      item
        Name = 'ROWGUID'
        DataType = ftInteger
        ParamType = ptInput
      end>
    object TrPersQROWGUID: TIntegerField
      FieldName = 'ROWGUID'
      Origin = 'ROWGUID'
    end
    object TrPersQLOGIN: TStringField
      FieldName = 'LOGIN'
      Origin = 'LOGIN'
      Size = 40
    end
    object TrPersQE_MAIL: TStringField
      FieldName = 'E_MAIL'
      Origin = 'E_MAIL'
      Size = 40
    end
  end
  object VidEduQ: TFDQuery
    SQL.Strings = (
      'select '
      '    vid_edu_tr.id_vid_edu,'
      '    vid_edu_tr.vid_edu'
      'from vid_edu_tr')
    Left = 32
    Top = 288
  end
  object TrStudUp: TFDUpdateSQL
    InsertSQL.Strings = (
      'insert into student_tr'
      '  (ROWGUID, FAM_TR, NAME_TR, OTCH_TR, ACTIVE_STUDENT, ID_FAC, '
      'ID_VID_EDU, '
      
        '   ID_SPEC, ID_KURS, ID_STUD_TYPE, NOM_Z, POL, UCH_YEAR, DATE_EN' +
        'D, '
      'DATE_ZACH, '
      '   ADD_YEAR, CITYZENSHIP, N_GROUP, DEKAN, ID_VUZ)'
      'values'
      
        '  (:ROWGUID, :FAM_TR, :NAME_TR, :OTCH_TR, :ACTIVE_STUDENT, :ID_F' +
        'AC, '
      ':ID_VID_EDU, '
      
        '   :ID_SPEC, :ID_KURS, :ID_STUD_TYPE, :NOM_Z, :POL, :UCH_YEAR, :' +
        'DATE_END, '
      
        '   :DATE_ZACH, :ADD_YEAR, :CITYZENSHIP, :N_GROUP, :DEKAN, :ID_VU' +
        'Z)')
    ModifySQL.Strings = (
      'update student_tr'
      'set'
      '  ROWGUID = :ROWGUID,'
      '  FAM_TR = :FAM_TR,'
      '  NAME_TR = :NAME_TR,'
      '  OTCH_TR = :OTCH_TR,'
      '  ACTIVE_STUDENT = :ACTIVE_STUDENT,'
      '  ID_FAC = :ID_FAC,'
      '  ID_VID_EDU = :ID_VID_EDU,'
      '  ID_SPEC = :ID_SPEC,'
      '  ID_KURS = :ID_KURS,'
      '  ID_STUD_TYPE = :ID_STUD_TYPE,'
      '  NOM_Z = :NOM_Z,'
      '  POL = :POL,'
      '  UCH_YEAR = :UCH_YEAR,'
      '  DATE_END = :DATE_END,'
      '  DATE_ZACH = :DATE_ZACH,'
      '  ADD_YEAR = :ADD_YEAR,'
      '  CITYZENSHIP = :CITYZENSHIP,'
      '  N_GROUP = :N_GROUP,'
      '  DEKAN = :DEKAN,'
      '  ID_VUZ = :ID_VUZ'
      'where'
      '  ROWGUID = :OLD_ROWGUID')
    DeleteSQL.Strings = (
      'delete from student_tr'
      'where'
      '  ROWGUID = :OLD_ROWGUID')
    Left = 136
    Top = 64
  end
  object DataSource1: TDataSource
    DataSet = TrStudQ
    Left = 80
    Top = 64
  end
  object FDTable1: TFDTable
    CachedUpdates = True
    IndexFieldNames = 'IDPHOTOS'
    UpdateOptions.UpdateTableName = 'PHOTOS'
    TableName = 'PHOTOS'
    Left = 248
    Top = 120
    object FDTable1IDDATABASES: TIntegerField
      FieldName = 'IDDATABASES'
      Origin = 'IDDATABASES'
      Required = True
    end
    object FDTable1IDPERSON: TIntegerField
      FieldName = 'IDPERSON'
      Origin = 'IDPERSON'
      Required = True
    end
    object FDTable1PHOTO: TBlobField
      FieldName = 'PHOTO'
      Origin = 'PHOTO'
    end
    object FDTable1SIGNATURE: TBlobField
      FieldName = 'SIGNATURE'
      Origin = 'SIGNATURE'
    end
    object FDTable1EDITUSER: TStringField
      FieldName = 'EDITUSER'
      Origin = 'EDITUSER'
      Size = 128
    end
    object FDTable1EDITDATE: TSQLTimeStampField
      FieldName = 'EDITDATE'
      Origin = 'EDITDATE'
    end
    object FDTable1CREATEUSER: TStringField
      FieldName = 'CREATEUSER'
      Origin = 'CREATEUSER'
      Size = 128
    end
    object FDTable1CREATEDATE: TSQLTimeStampField
      FieldName = 'CREATEDATE'
      Origin = 'CREATEDATE'
    end
    object FDTable1IDPHOTOS: TIntegerField
      FieldName = 'IDPHOTOS'
      Origin = 'IDPHOTOS'
      ProviderFlags = [pfInUpdate, pfInWhere, pfInKey]
      Required = True
    end
  end
  object FDStoredProcPhotos: TFDStoredProc
    StoredProcName = 'GET_IDPHOTOS'
    Left = 352
    Top = 24
    ParamData = <
      item
        Position = 1
        Name = 'IDPERSON'
        DataType = ftInteger
        ParamType = ptInput
      end
      item
        Position = 2
        Name = 'PHOTO'
        ArrayType = atArray
        DataType = ftBlob
        ParamType = ptInput
      end
      item
        Position = 3
        Name = 'SIGNATURE'
        ArrayType = atArray
        DataType = ftBlob
        ParamType = ptInput
      end>
  end
  object FDConnectionCards_TR: TFDConnection
    Params.Strings = (
      'Database=D:/BGUFK/Cards/CARDSTRANSFER.GDB'
      'User_Name=DEVELOPER'
      'Password=abudfv544703'
      'Server=172.16.1.10'
      'CharacterSet=WIN1251'
      'DriverID=FB')
    LoginPrompt = False
    Left = 40
    Top = 16
  end
  object FDConnectionCards: TFDConnection
    Left = 272
    Top = 24
  end
end

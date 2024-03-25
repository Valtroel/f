object PasportForm: TPasportForm
  Left = 526
  Top = 250
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1055#1072#1089#1087#1086#1088#1090
  ClientHeight = 488
  ClientWidth = 285
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnActivate = FormActivate
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 57
    Width = 230
    Height = 431
    Align = alClient
    BevelInner = bvSpace
    BevelOuter = bvLowered
    TabOrder = 0
    Visible = False
    object Label15: TLabel
      Left = 10
      Top = 165
      Width = 99
      Height = 13
      Caption = #1056#1077#1075#1080#1086#1085'/'#1054#1073#1083#1072#1089#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label16: TLabel
      Left = 10
      Top = 208
      Width = 66
      Height = 13
      Caption = #1050#1077#1084' '#1074#1099#1076#1072#1085
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label17: TLabel
      Left = 10
      Top = 279
      Width = 78
      Height = 13
      Caption = #1044#1072#1090#1072' '#1074#1099#1076#1072#1095#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label11: TLabel
      Left = 10
      Top = 66
      Width = 37
      Height = 13
      Caption = #1057#1077#1088#1080#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label12: TLabel
      Left = 90
      Top = 66
      Width = 40
      Height = 13
      Caption = #1053#1086#1084#1077#1088
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label13: TLabel
      Left = 10
      Top = 116
      Width = 141
      Height = 13
      Caption = #1048#1076#1077#1085#1090#1080#1092#1080#1082#1072#1094#1080#1086#1085#1085#1099#1081' '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label14: TLabel
      Left = 10
      Top = 20
      Width = 90
      Height = 13
      Caption = #1042#1080#1076' '#1076#1086#1082#1091#1084#1077#1085#1090#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label18: TLabel
      Left = 119
      Top = 278
      Width = 89
      Height = 13
      Caption = #1057#1088#1086#1082' '#1076#1077#1081#1089#1090#1074#1080#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBEdit1: TDBEdit
      Left = 10
      Top = 82
      Width = 65
      Height = 21
      DataField = 'SERIES'
      DataSource = DataModule1.PasportDS
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ReadOnly = True
      TabOrder = 0
    end
    object DBEdit3: TDBEdit
      Left = 10
      Top = 132
      Width = 200
      Height = 21
      DataField = 'PERSONAL_NUMBER'
      DataSource = DataModule1.PasportDS
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ReadOnly = True
      TabOrder = 2
    end
    object DBEdit2: TDBEdit
      Left = 90
      Top = 82
      Width = 120
      Height = 21
      DataField = 'NUMBER'
      DataSource = DataModule1.PasportDS
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ReadOnly = True
      TabOrder = 1
    end
    object DBEdit6: TDBEdit
      Left = 10
      Top = 295
      Width = 90
      Height = 21
      DataField = 'DATE_GIVE'
      DataSource = DataModule1.PasportDS
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ReadOnly = True
      TabOrder = 3
    end
    object DBEdit7: TDBEdit
      Left = 120
      Top = 295
      Width = 90
      Height = 21
      DataField = 'DATE_VALID'
      DataSource = DataModule1.PasportDS
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ReadOnly = True
      TabOrder = 4
    end
    object Panel6: TPanel
      Left = 2
      Top = 388
      Width = 226
      Height = 41
      Align = alBottom
      BevelInner = bvRaised
      BevelOuter = bvLowered
      TabOrder = 5
      object BitBtn3: TBitBtn
        Left = 67
        Top = 8
        Width = 90
        Height = 25
        Kind = bkOK
        NumGlyphs = 2
        TabOrder = 0
      end
    end
    object DBMemo1: TDBMemo
      Left = 10
      Top = 223
      Width = 200
      Height = 50
      DataField = 'WHO_GIVE'
      DataSource = DataModule1.PasportDS
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ReadOnly = True
      TabOrder = 6
    end
    object DBLookupComboBox3: TDBLookupComboBox
      Left = 10
      Top = 35
      Width = 200
      Height = 21
      DataField = 'ID_TYPE'
      DataSource = DataModule1.PasportDS
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      KeyField = 'ID_TYPE'
      ListField = 'NAME_TYPE'
      ListSource = DataModule1.PasportTypeDS
      ParentFont = False
      ReadOnly = True
      TabOrder = 7
    end
    object DBLookupComboBox4: TDBLookupComboBox
      Left = 10
      Top = 179
      Width = 200
      Height = 21
      DataField = 'N_REGION'
      DataSource = DataModule1.PasportDS
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      KeyField = 'N_REGION'
      ListField = 'TEXT_REGION'
      ListSource = DataModule1.RegionSource
      ParentFont = False
      ReadOnly = True
      TabOrder = 8
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 57
    Width = 230
    Height = 431
    Align = alClient
    BevelInner = bvSpace
    BevelOuter = bvLowered
    TabOrder = 1
    Visible = False
    object Label1: TLabel
      Left = 2
      Top = 2
      Width = 226
      Height = 13
      Align = alTop
      Alignment = taCenter
      Caption = 'Label1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHotLight
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      ExplicitWidth = 39
    end
    object Label2: TLabel
      Left = 10
      Top = 19
      Width = 90
      Height = 13
      Caption = #1042#1080#1076' '#1076#1086#1082#1091#1084#1077#1085#1090#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 10
      Top = 62
      Width = 37
      Height = 13
      Caption = #1057#1077#1088#1080#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 90
      Top = 62
      Width = 40
      Height = 13
      Caption = #1053#1086#1084#1077#1088
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 10
      Top = 104
      Width = 141
      Height = 13
      Caption = #1048#1076#1077#1085#1090#1080#1092#1080#1082#1072#1094#1080#1086#1085#1085#1099#1081' '#8470
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label6: TLabel
      Left = 10
      Top = 145
      Width = 99
      Height = 13
      Caption = #1056#1077#1075#1080#1086#1085'/'#1054#1073#1083#1072#1089#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label9: TLabel
      Left = 119
      Top = 289
      Width = 89
      Height = 13
      Caption = #1057#1088#1086#1082' '#1076#1077#1081#1089#1090#1074#1080#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label8: TLabel
      Left = 10
      Top = 290
      Width = 78
      Height = 13
      Caption = #1044#1072#1090#1072' '#1074#1099#1076#1072#1095#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label7: TLabel
      Left = 10
      Top = 222
      Width = 66
      Height = 13
      Caption = #1050#1077#1084' '#1074#1099#1076#1072#1085
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label10: TLabel
      Left = 10
      Top = 185
      Width = 96
      Height = 13
      Caption = #1056#1072#1081#1086#1085' '#1075'.'#1052#1080#1085#1089#1082#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Panel4: TPanel
      Left = 2
      Top = 388
      Width = 226
      Height = 41
      Align = alBottom
      BevelInner = bvRaised
      BevelOuter = bvLowered
      TabOrder = 7
      object BitBtn1: TBitBtn
        Left = 10
        Top = 8
        Width = 90
        Height = 25
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Glyph.Data = {
          F6000000424DF600000000000000760000002800000010000000100000000100
          0400000000008000000000000000000000001000000010000000000000000000
          BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
          7777770000000000007770330770000330777033077000033077703307700003
          30777033000000033077703333333333307770330000000330777030FFFFFFF0
          30777030FCCCCFF030777030FFCCCFF030777037FCCCCFF000777077CCCFCFF0
          8077777CCC777700007777CCC77777777777777C777777777777}
        ParentFont = False
        TabOrder = 0
        OnClick = BitBtn1Click
      end
      object BitBtn2: TBitBtn
        Left = 115
        Top = 8
        Width = 90
        Height = 25
        Caption = #1054#1090#1084#1077#1085#1080#1090#1100
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
          777770000000777777777777777770000000777777777777770F700000007777
          0F777777777770000000777000F7777770F770000000777000F777770F777000
          00007777000F77700F777000000077777000F700F7777000000077777700000F
          7777700000007777777000F777777000000077777700000F7777700000007777
          7000F70F7777700000007770000F77700F7770000000770000F7777700F77000
          00007700F7777777700F70000000777777777777777770000000777777777777
          777770000000}
        ParentFont = False
        TabOrder = 1
        OnClick = BitBtn2Click
      end
    end
    object DBLookupComboBox1: TDBLookupComboBox
      Left = 10
      Top = 36
      Width = 200
      Height = 21
      KeyField = 'ID_TYPE'
      ListField = 'NAME_TYPE'
      ListSource = DataModule1.PasportTypeDS
      TabOrder = 0
    end
    object Edit1: TEdit
      Left = 10
      Top = 77
      Width = 65
      Height = 21
      MaxLength = 9
      TabOrder = 1
    end
    object Edit2: TEdit
      Left = 90
      Top = 77
      Width = 120
      Height = 21
      MaxLength = 29
      TabOrder = 2
      Text = 'Edit2'
      OnKeyPress = Edit2KeyPress
    end
    object Edit3: TEdit
      Left = 10
      Top = 120
      Width = 200
      Height = 21
      MaxLength = 14
      TabOrder = 3
      Text = 'Edit3'
    end
    object DBLookupComboBox2: TDBLookupComboBox
      Left = 10
      Top = 160
      Width = 200
      Height = 21
      KeyField = 'N_REGION'
      ListField = 'TEXT_REGION'
      ListSource = DataModule1.RegionSource
      TabOrder = 4
      OnCloseUp = DBLookupComboBox2CloseUp
      OnExit = DBLookupComboBox2Exit
    end
    object Memo1: TMemo
      Left = 11
      Top = 239
      Width = 200
      Height = 50
      MaxLength = 149
      TabOrder = 6
    end
    object ComboBox1: TComboBox
      Left = 10
      Top = 200
      Width = 200
      Height = 21
      Style = csDropDownList
      Enabled = False
      TabOrder = 5
      OnExit = ComboBox1Exit
    end
    object DateTimePicker1: TDateTimePicker
      Left = 10
      Top = 306
      Width = 92
      Height = 21
      Date = 40544.614482743050000000
      Time = 40544.614482743050000000
      TabOrder = 8
      OnChange = DateTimePicker1Change
    end
    object DateTimePicker2: TDateTimePicker
      Left = 119
      Top = 306
      Width = 92
      Height = 21
      Date = 44197.614680023150000000
      Time = 44197.614680023150000000
      TabOrder = 9
      OnChange = DateTimePicker2Change
    end
  end
  object Panel3: TPanel
    Left = 230
    Top = 57
    Width = 55
    Height = 431
    Align = alRight
    BevelInner = bvSpace
    BevelOuter = bvLowered
    TabOrder = 2
    object SpeedButton1: TSpeedButton
      Left = 14
      Top = 20
      Width = 30
      Height = 30
      Hint = #1044#1086#1073#1072#1074#1080#1090#1100
      Glyph.Data = {
        42010000424D4201000000000000760000002800000011000000110000000100
        040000000000CC00000000000000000000001000000010000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
        7777700000007777777777777777700000007777777774F77777700000007777
        7777444F77777000000077777774444F777770000000700000444F44F7777000
        000070FFF444F0744F777000000070F8884FF0774F777000000070FFFFFFF077
        74F77000000070F88888F077774F7000000070FFFFFFF0777774F000000070F8
        8777F07777774000000070FFFF00007777777000000070F88707077777777000
        000070FFFF007777777770000000700000077777777770000000777777777777
        777770000000}
      ParentShowHint = False
      ShowHint = True
      OnClick = SpeedButton1Click
    end
    object SpeedButton2: TSpeedButton
      Left = 14
      Top = 71
      Width = 30
      Height = 30
      Hint = #1048#1079#1084#1077#1085#1080#1090#1100
      Glyph.Data = {
        66010000424D6601000000000000760000002800000014000000140000000100
        040000000000F000000000000000000000001000000000000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
        77777777000077777777777777777777000077777771171177777777000078FF
        FFFFF1FFFFFFFFF70000780000000100000000F70000780FFFFFF1FFFFFFF0F7
        0000780FFFFFF1FFFFFFF0F70000780FCCCCF1FCCCCFF0F70000780FCFCCF1FC
        CFCCF0F70000780FCCCCF1FCCFCCF0F70000780FFFCCF1FCCFCCF0F70000780F
        CCCFF1FCCCCFF0F70000780FFFFFF1FCCFFFF0F70000780FFFFFF1FCCFFFF0F7
        0000780FFFFFF1FFFFFFF0F70000780000000100000000F70000788888888188
        8888888700007777777117117777777700007777777777777777777700007777
        77777777777777770000}
      ParentShowHint = False
      ShowHint = True
      OnClick = SpeedButton2Click
    end
    object SpeedButton3: TSpeedButton
      Left = 14
      Top = 122
      Width = 30
      Height = 30
      Hint = #1059#1076#1072#1083#1080#1090#1100
      Glyph.Data = {
        42010000424D4201000000000000760000002800000011000000110000000100
        040000000000CC00000000000000000000001000000000000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
        7777700000007777777777777777700000007799777774F77997700000007779
        9777444F997770000000777799744449977770000000700009944F99F7777000
        000070FFF499F9944F777000000070F8884999774F777000000070FFFFFF9077
        74F77000000070F888899977774F7000000070FFFF99F9977774F000000070F8
        8997F09977774000000070FF9900007997777000000070F99707077799777000
        00007099FF007777799770000000700000077777777770000000777777777777
        777770000000}
      ParentShowHint = False
      ShowHint = True
      OnClick = SpeedButton3Click
    end
  end
  object Panel5: TPanel
    Left = 0
    Top = 0
    Width = 285
    Height = 57
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 3
    object DBText1: TDBText
      Left = 11
      Top = 5
      Width = 200
      Height = 17
      DataField = 'FAM'
      DataSource = DataModule1.PeopleQSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHotLight
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText2: TDBText
      Left = 11
      Top = 21
      Width = 200
      Height = 17
      DataField = 'NAME'
      DataSource = DataModule1.PeopleQSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHotLight
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText3: TDBText
      Left = 11
      Top = 38
      Width = 200
      Height = 17
      DataField = 'OTCH'
      DataSource = DataModule1.PeopleQSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clHotLight
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
end

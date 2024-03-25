object Ved_GEK: TVed_GEK
  Left = 255
  Top = 218
  BorderIcons = [biSystemMenu, biMaximize]
  Caption = #1042#1077#1076#1086#1084#1086#1089#1090#1080' '#1075#1086#1089#1091#1076#1072#1088#1089#1090#1074#1077#1085#1085#1099#1093' '#1101#1082#1079#1072#1084#1077#1085#1086#1074
  ClientHeight = 393
  ClientWidth = 725
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
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
  object DBGrid2: TDBGrid
    Left = 0
    Top = 0
    Width = 519
    Height = 393
    Align = alClient
    DataSource = DM3.Ved_GEKSource
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
    ParentFont = False
    ReadOnly = True
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = [fsBold]
    Columns = <
      item
        Expanded = False
        FieldName = 'N_VEDOMOST'
        Title.Caption = #8470' '#1074#1077#1076#1086#1084#1086#1089#1090#1080
        Width = 40
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'D_VED'
        Title.Alignment = taCenter
        Title.Caption = #1044#1072#1090#1072
        Width = 58
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'N_GROUP_SP'
        Title.Alignment = taCenter
        Title.Caption = #8470' '#1075#1088'. '#1076#1083#1103' '#1043#1054#1057
        Width = 93
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'INC_GROUP'
        Title.Alignment = taCenter
        Title.Caption = #8470' '#1075#1088#1091#1087#1087#1099
        Width = 65
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'VID_EDU1'
        Title.Alignment = taCenter
        Title.Caption = #1074#1080#1076' '#1086#1073#1091#1095#1077#1085#1080#1103
        Width = 96
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'NAME_OBJECT'
        Title.Caption = #1053#1072#1080#1084#1077#1085#1086#1074#1072#1085#1080#1077' '#1087#1088#1077#1076#1084#1077#1090#1072
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'YEAR_PLAN'
        Title.Caption = #1043#1086#1076
        Visible = True
      end>
  end
  object Panel1: TPanel
    Left = 519
    Top = 0
    Width = 206
    Height = 393
    Align = alRight
    BevelOuter = bvLowered
    TabOrder = 1
    object Label3: TLabel
      Left = 3
      Top = 304
      Width = 9
      Height = 13
      Caption = 'C'
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -9
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 81
      Top = 304
      Width = 19
      Height = 13
      Caption = #1055#1054
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -9
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label8: TLabel
      Left = 15
      Top = 250
      Width = 63
      Height = 13
      Caption = #8470' '#1075#1088#1091#1087#1087#1099':'
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object BitBtn2: TBitBtn
      Left = 108
      Top = 328
      Width = 85
      Height = 25
      Cursor = crHandPoint
      Hint = #1060#1086#1088#1084#1080#1088#1086#1074#1072#1085#1080#1077' '#1074#1077#1076#1086#1084#1086#1089#1090#1080#13#10#1080' '#1087#1086#1076#1075#1086#1090#1086#1074#1082#1072' '#1082' '#1087#1077#1095#1072#1090#1080
      Caption = #1055#1077#1095#1072#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        EE000000424DEE000000000000007600000028000000100000000F0000000100
        0400000000007800000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FF0000000000
        0FFFF0888888888080FF000000000000080F0888888FFF88000F088888877788
        080F00000000000008800888888888808080F000000000080800FF0FFFFFFFF0
        8080FFF0F00000F0000FFFF0FFFFFFFF0FFFFFFF0F00000F0FFFFFFF0FFFFFFF
        F0FFFFFFF000000000FFFFFFFFFFFFFFFFFF}
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      Spacing = 10
      TabOrder = 0
      OnClick = BitBtn2Click
    end
    object BitBtn3: TBitBtn
      Left = 108
      Top = 363
      Width = 85
      Height = 24
      Cursor = crHandPoint
      Caption = #1042#1099#1093#1086#1076
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Kind = bkClose
      NumGlyphs = 2
      ParentFont = False
      Spacing = 10
      TabOrder = 1
      OnClick = BitBtn3Click
    end
    object Panel2: TPanel
      Left = 4
      Top = 7
      Width = 196
      Height = 122
      BevelInner = bvRaised
      BevelOuter = bvLowered
      TabOrder = 2
      object Label1: TLabel
        Left = 7
        Top = 32
        Width = 109
        Height = 26
        Alignment = taCenter
        Caption = #1069#1082#1079#1072#1084#1077#1085#1072#1094#1080#1086#1085#1085#1072#1103#13#10#1074#1077#1076#1086#1084#1086#1089#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label7: TLabel
        Left = 30
        Top = 4
        Width = 142
        Height = 13
        Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1074#1077#1076#1086#1084#1086#1089#1090#1080
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label2: TLabel
        Left = 7
        Top = 81
        Width = 78
        Height = 13
        Alignment = taCenter
        Caption = #1054#1095#1077#1088#1077#1076#1085#1086#1089#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object BitBtn1: TBitBtn
        Left = 156
        Top = 28
        Width = 24
        Height = 24
        Cursor = crHandPoint
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1086#1089#1085#1086#1074#1085#1091#1102' '#1074#1077#1076#1086#1084#1086#1089#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Glyph.Data = {
          EE000000424DEE000000000000007600000028000000100000000F0000000100
          04000000000078000000130B0000130B00001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888800000
          000088888880FFFFFFF088888880F00F00F088888880FFFFFFF088888880F00F
          00F088888880FFFFFFF088888884444444448800008444444444880BB0888888
          8888000BB000888888880BBBBBB0888888880BBBBBB088888888000BB0008888
          8888880BB088888888888800008888888888}
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 0
        OnClick = BitBtn1Click
      end
      object BitBtn6: TBitBtn
        Left = 156
        Top = 75
        Width = 24
        Height = 24
        Cursor = crHandPoint
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1086#1089#1085#1086#1074#1085#1091#1102' '#1074#1077#1076#1086#1084#1086#1089#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Glyph.Data = {
          EE000000424DEE000000000000007600000028000000100000000F0000000100
          04000000000078000000130B0000130B00001000000000000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888800000
          000088888880FFFFFFF088888880F00F00F088888880FFFFFFF088888880F00F
          00F088888880FFFFFFF088888884444444448800008444444444880BB0888888
          8888000BB000888888880BBBBBB0888888880BBBBBB088888888000BB0008888
          8888880BB088888888888800008888888888}
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        OnClick = BitBtn6Click
      end
    end
    object Edit1: TEdit
      Left = 15
      Top = 299
      Width = 64
      Height = 21
      Enabled = False
      TabOrder = 3
      OnEnter = Edit1Enter
    end
    object Edit2: TEdit
      Left = 102
      Top = 299
      Width = 64
      Height = 21
      Enabled = False
      TabOrder = 4
      OnEnter = Edit2Enter
    end
    object CheckBox1: TCheckBox
      Left = 13
      Top = 279
      Width = 163
      Height = 14
      Caption = #1042#1077#1076#1086#1084#1086#1089#1090#1080' '#1079#1072' '#1087#1077#1088#1080#1086#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -9
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 5
      OnClick = CheckBox1Click
    end
    object BitBtn4: TBitBtn
      Left = 171
      Top = 292
      Width = 30
      Height = 30
      Cursor = crHandPoint
      Enabled = False
      Glyph.Data = {
        7E010000424D7E01000000000000760000002800000018000000160000000100
        0400000000000801000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00800000000000
        0000000000080777777777777777777777700F77777777777777777777700F88
        888888888888888887700F88888880000088888887700F8888800FFFFF008888
        87700F88880FFFFFFFFF088887700F8880FFFFFFFFFFF08887700F8880FF0FFF
        FFFFF08887700F880FFFF0FFFFFFFF0887700F880FFFFF0FFFFFFF0887700F88
        0FFFFFF000000F0887700F880FFFFFFFFFFFFF0887700F880FFFFFFFFFFFFF08
        87700F8880FFFFFFFFFFF08887700F8880FFFFFFFFFFF08887700F88880FFFF0
        FFFF088887700F8888800FFFFF00888887700F88888880000088888887700F88
        888888888888888887700FFFFFFFFFFFFFFFFFFFFF7080000000000000000000
        0008}
      TabOrder = 6
      OnClick = BitBtn4Click
    end
    object BitBtn5: TBitBtn
      Left = 7
      Top = 364
      Width = 85
      Height = 24
      Cursor = crHandPoint
      Hint = #1059#1076#1072#1083#1080#1090#1100' '#1074#1099#1073#1088#1072#1085#1085#1091#1102' '#1074#1077#1076#1086#1084#1086#1089#1090#1100
      Caption = #1059#1076#1072#1083#1080#1090#1100
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
        7777700000007777777777177777700000007777777771177777100000007777
        7777711177717000000077777777771177117000000070000000000011577000
        0000707777777775117770000000707007007071511770000000707777777711
        771150000000704444445144447510000000774FFFFF15FFF47770000000774F
        00F00F00F47770000000774FFFFFFFFFF4777000000077444444444444777000
        0000774744744744747770000000774444444444447770000000777777777777
        777770000000}
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 7
      Visible = False
      OnClick = BitBtn5Click
    end
    object RadioGroup2: TRadioGroup
      Left = 4
      Top = 138
      Width = 197
      Height = 80
      Caption = #1055#1086' '#1074#1080#1076#1091' '#1086#1073#1091#1095#1077#1085#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ItemIndex = 0
      Items.Strings = (
        #1042#1089#1077
        #1044#1085#1077#1074#1085#1086#1075#1086
        #1047#1072#1086#1095#1085#1086#1075#1086)
      ParentFont = False
      TabOrder = 8
      OnClick = RadioGroup2Click
    end
    object CheckBox2: TCheckBox
      Left = 13
      Top = 227
      Width = 188
      Height = 14
      Caption = #1042#1077#1076#1086#1084#1086#1089#1090#1080' '#8470' '#1075#1088'.'#1076#1083#1103' '#1043#1054#1057#1072':'
      Enabled = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -9
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 9
      OnClick = CheckBox2Click
    end
    object BitBtn7: TBitBtn
      Left = 171
      Top = 241
      Width = 30
      Height = 30
      Cursor = crHandPoint
      Hint = #1053#1072#1078#1084#1080#1090#1077' '#1076#1083#1103' '#1087#1086#1082#1072#1079#1072' '#1074#1077#1076#1086#1084#1086#1089#1090#1077#1081' '#1087#1086' '#1074#1099#1073#1088#1072#1085#1085#1086#1081' '#1075#1088#1091#1087#1087#1077
      Enabled = False
      Glyph.Data = {
        7E010000424D7E01000000000000760000002800000018000000160000000100
        0400000000000801000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00800000000000
        0000000000080777777777777777777777700F77777777777777777777700F88
        888888888888888887700F88888880000088888887700F8888800FFFFF008888
        87700F88880FFFFFFFFF088887700F8880FFFFFFFFFFF08887700F8880FF0FFF
        FFFFF08887700F880FFFF0FFFFFFFF0887700F880FFFFF0FFFFFFF0887700F88
        0FFFFFF000000F0887700F880FFFFFFFFFFFFF0887700F880FFFFFFFFFFFFF08
        87700F8880FFFFFFFFFFF08887700F8880FFFFFFFFFFF08887700F88880FFFF0
        FFFF088887700F8888800FFFFF00888887700F88888880000088888887700F88
        888888888888888887700FFFFFFFFFFFFFFFFFFFFF7080000000000000000000
        0008}
      ParentShowHint = False
      ShowHint = True
      TabOrder = 10
      OnClick = BitBtn7Click
    end
    object Edit3: TEdit
      Left = 102
      Top = 246
      Width = 64
      Height = 21
      Enabled = False
      TabOrder = 11
    end
  end
  object ApplicationEvents1: TApplicationEvents
    OnMessage = ApplicationEvents1Message
    Left = 168
    Top = 256
  end
  object frxReport1: TfrxReport
    Version = '5.6.1'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 42648.459825023150000000
    ReportOptions.LastChange = 42648.459825023150000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 527
    Top = 328
    Datasets = <>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
    end
  end
end

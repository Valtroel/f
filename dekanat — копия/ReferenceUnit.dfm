object ReferenceForm: TReferenceForm
  Left = 0
  Top = 0
  Caption = 'ReferenceForm'
  ClientHeight = 299
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object frxPreview1: TfrxPreview
    Left = 0
    Top = 0
    Width = 635
    Height = 299
    Align = alClient
    OutlineVisible = True
    OutlineWidth = 121
    ThumbnailVisible = False
    UseReportHints = True
  end
  object frxReport1: TfrxReport
    Version = '5.6.1'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintMode = pmJoin
    PrintOptions.PrintOnSheet = 9
    ReportOptions.CreateDate = 42870.642741006900000000
    ReportOptions.LastChange = 42870.642741006900000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 96
    Top = 32
    Datasets = <
      item
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      PaperWidth = 148.000000000000000000
      PaperHeight = 210.000000000000000000
      PaperSize = 11
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      Duplex = dmSimplex
      object Rich1: TfrxRichView
        Top = 18.897650000000000000
        Width = 347.716760000000000000
        Height = 117.165430000000000000
        GapX = 2.000000000000000000
        GapY = 1.000000000000000000
        RichEdit = {
          7B5C727466315C616E73695C616E7369637067313235315C64656666305C6E6F
          7569636F6D7061745C6465666C616E67313034397B5C666F6E7474626C7B5C66
          305C666E696C5C66636861727365743230342054696D6573204E657720526F6D
          616E204359523B7D7B5C66315C666E696C5C6663686172736574302054696D65
          73204E657720526F6D616E3B7D7D0D0A7B5C2A5C67656E657261746F72205269
          6368656432302031302E302E31363239397D5C766965776B696E64345C756331
          200D0A5C706172645C66693834305C66305C667332305C2764305C2763355C27
          64315C2763665C2764335C2763315C2763625C2763385C2763615C276330205C
          2763315C2763355C2763625C2763305C2764305C2764335C2764315C2764635C
          7061720D0A0D0A5C706172645C667331345C7061720D0A0D0A5C706172645C66
          693336305C667332305C2763635C2763385C2763645C2763385C2764315C2764
          325C2763355C2764305C2764315C2764325C2763325C276365205C2764315C27
          63665C2763655C2764305C2764325C276330205C276338205C2764325C276433
          5C2764305C2763385C2763375C2763635C2763305C7061720D0A0D0A5C706172
          645C66693834305C2764305C2763355C2764315C2763665C2764335C2763315C
          2763625C2763385C2763615C276338205C2763315C2763355C2763625C276330
          5C2764305C2764335C2764315C2764635C7061720D0A0D0A5C706172645C6673
          31345C7061720D0A0D0A5C706172645C66692D38305C667332305C2764335C27
          64375C2764305C2763355C2763365C2763345C2763355C2763645C2763385C27
          6335205C2763655C2763315C2764305C2763305C2763375C2763655C2763325C
          2763305C2763645C2763385C276466205C66315C6C616E67313033335C276162
          5C66305C6C616E67313034395C2763315C2763355C2763625C2763655C276430
          5C2764335C2764315C2764315C2763615C2763385C2763395C7061720D0A0D0A
          5C706172645C66693338305C2763335C2763655C2764315C2764335C2763345C
          2763305C2764305C2764315C2764325C2763325C2763355C2763645C2763645C
          2764625C276339205C2764335C2763645C2763385C2763325C2763355C276430
          5C2764315C2763385C2764325C2763355C2764325C7061720D0A0D0A5C706172
          645C66693738305C2764345C2763385C2763375C2763385C2764375C2763355C
          2764315C2763615C2763655C276339205C2763615C2764335C2763625C276463
          5C2764325C2764335C2764305C2764625C66315C6C616E67313033335C276262
          5C66305C6C616E67313034395C7061720D0A7D0D0A00}
      end
      object Memo1: TfrxMemoView
        Left = 37.795300000000000000
        Top = 158.740260000000000000
        Width = 94.488250000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #8470)
        ParentFont = False
      end
      object Memo2: TfrxMemoView
        Left = 26.456710000000000000
        Top = 188.976500000000000000
        Width = 249.448980000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '220020 '#1075'. '#1052#1080#1085#1089#1082', '#1087#1088'. '#1055#1086#1073#1077#1076#1080#1090#1077#1083#1077#1081', 105')
        ParentFont = False
      end
      object Memo3: TfrxMemoView
        Left = 124.724490000000000000
        Top = 219.212740000000000000
        Width = 234.330860000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        Memo.UTF8W = (
          #1057' '#1055' '#1056' '#1040' '#1042' '#1050' '#1040' - '#1042' '#1067' '#1047' '#1054' '#1042)
        ParentFont = False
      end
      object Memo4: TfrxMemoView
        Left = 45.354360000000000000
        Top = 241.889920000000000000
        Width = 393.071120000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1057#1086#1075#1083#1072#1089#1085#1086' '#1089#1090'. 214 '#31#31'- 216 '#1058#1050' '#1056#1041' '#1087#1088#1077#1076#1086#1089#1090#1072#1074#1083#1103#1077#1090#1089#1103' '#1086#1090#1087#1091#1089#1082)
        ParentFont = False
      end
      object Memo5: TfrxMemoView
        Left = 15.118120000000000000
        Top = 268.346630000000000000
        Width = 449.764070000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        Memo.UTF8W = (
          
            '[<frxDBDataset1."FAM">] [<frxDBDataset1."NAME">] [<frxDBDataset1' +
            '."OTCH">]')
        ParentFont = False
      end
      object Memo6: TfrxMemoView
        Top = 306.141930000000000000
        Width = 68.031540000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1085#1072' '#1087#1077#1088#1080#1086#1076)
        ParentFont = False
      end
      object Memo7: TfrxMemoView
        Left = 186.315789480000000000
        Top = 362.884598420000000000
        Width = 140.684715260000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1091#1089#1090#1072#1085#1086#1074#1086#1095#1085#1086#1081' '#1089#1077#1089#1089#1080#1080',')
        ParentFont = False
      end
      object Memo8: TfrxMemoView
        Left = 68.031540000000000000
        Top = 306.141930000000000000
        Width = 173.858380000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1089#1076#1072#1095#1080' '#1101#1082#1079#1072#1084#1077#1085#1086#1074' '#1080' '#1079#1072#1095#1105#1090#1086#1074',')
        ParentFont = False
      end
      object Memo9: TfrxMemoView
        Left = -0.157390000000000000
        Top = 362.884598420000000000
        Width = 186.680597890000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1075#1086#1089#1091#1076#1072#1088#1089#1090#1074#1077#1085#1085#1099#1093' '#1101#1082#1079#1072#1084#1077#1085#1086#1074',')
        ParentFont = False
      end
      object Memo10: TfrxMemoView
        Left = 241.889920000000000000
        Top = 306.141930010000000000
        Width = 117.165430000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1086#1073#1079#1086#1088#1085#1099#1093' '#1083#1077#1082#1094#1080#1081',')
        ParentFont = False
      end
      object Memo12: TfrxMemoView
        Left = 178.430065950000000000
        Top = 381.284598410000000000
        Width = 143.622140000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '('#1085#1091#1078#1085#1086#1077' '#1087#1086#1076#1095#1077#1088#1082#1085#1091#1090#1086')')
        ParentFont = False
      end
      object Memo14: TfrxMemoView
        Top = 431.478401830000000000
        Width = 132.283550000000000000
        Height = 34.015770000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1052'.'#1055'.'
          #1091#1095#1077#1073#1085#1086#1075#1086' '#1079#1072#1074#1077#1076#1077#1085#1080#1103)
        ParentFont = False
      end
      object Memo15: TfrxMemoView
        Left = 192.756030000000000000
        Top = 431.478401830000000000
        Width = 291.023810000000000000
        Height = 37.795300000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1053#1072#1095#1072#1083#1100#1085#1080#1082' '#1091#1095#1077#1073#1085#1086#1075#1086' '#1079#1072#1074#1077#1076#1077#1085#1080#1103
          '('#1089#1086#1086#1090#1074#1077#1090#1089#1090#1074#1091#1102#1097#1077#1075#1086' '#1087#1086#1076#1088#1072#1079#1076#1077#1083#1077#1085#1080#1103')________')
        ParentFont = False
      end
      object Memo16: TfrxMemoView
        Left = 192.756030000000000000
        Top = 504.723381300000000000
        Width = 90.708720000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '('#1083#1080#1085#1080#1103' '#1086#1090#1088#1077#1079#1072')')
        ParentFont = False
      end
      object Memo17: TfrxMemoView
        Left = 56.692950000000000000
        Top = 533.044997090000000000
        Width = 374.173470000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        Memo.UTF8W = (
          #1057' '#1055' '#1056' '#1040' '#1042' '#1050' '#1040' - '#1055' '#1054' '#1044' '#1058' '#1042' '#1045' '#1056' '#1046' '#1044' '#1045' '#1053' '#1048' '#1045)
        ParentFont = False
      end
      object Line1: TfrxLineView
        Left = 52.913420000000000000
        Top = 173.858380000000000000
        Width = 147.401670000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line2: TfrxLineView
        Left = 15.118120000000000000
        Top = 287.244280000000000000
        Width = 449.764070000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line3: TfrxLineView
        Top = 504.723381300000000000
        Width = 480.000310000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo19: TfrxMemoView
        Left = 18.897650000000000000
        Top = 136.063080000000000000
        Width = 11.338590000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #171)
        ParentFont = False
      end
      object Line4: TfrxLineView
        Left = 26.456710000000000000
        Top = 151.181200000000000000
        Width = 34.015770000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo20: TfrxMemoView
        Left = 56.692950000000000000
        Top = 136.063080000000000000
        Width = 11.338590000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #187)
        ParentFont = False
      end
      object Line5: TfrxLineView
        Left = 66.141732280000000000
        Top = 151.181200000000000000
        Width = 124.724490000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo21: TfrxMemoView
        Left = 30.236240000000000000
        Top = 136.063080000000000000
        Width = 26.456710000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
      object Memo22: TfrxMemoView
        Left = 68.031540000000000000
        Top = 136.063080000000000000
        Width = 117.165430000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
      object Memo23: TfrxMemoView
        Left = 207.874150000000000000
        Top = 136.063080000000000000
        Width = 22.677180000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        VAlign = vaCenter
      end
      object Line6: TfrxLineView
        Left = 207.874150000000000000
        Top = 151.181200000000000000
        Width = 22.677180000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo25: TfrxMemoView
        Left = 230.551330000000000000
        Top = 136.063080000000000000
        Width = 15.118120000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1075'.')
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo24: TfrxMemoView
        Left = 154.960730000000000000
        Top = 287.244280000000000000
        Width = 147.401670000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '('#1092#1072#1084#1080#1083#1080#1103', '#1080#1084#1103', '#1086#1090#1095#1077#1089#1090#1074#1086')')
        ParentFont = False
      end
      object Memo26: TfrxMemoView
        Top = 405.021691830000000000
        Width = 22.677180000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1089' '#171)
        ParentFont = False
      end
      object Line7: TfrxLineView
        Left = 18.897650000000000000
        Top = 420.139811830000000000
        Width = 37.795300000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo27: TfrxMemoView
        Left = 56.692950000000000000
        Top = 405.021691830000000000
        Width = 11.338590000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #187)
        ParentFont = False
      end
      object Line8: TfrxLineView
        Left = 66.141732280000000000
        Top = 420.139811830000000000
        Width = 94.488250000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo30: TfrxMemoView
        Left = 22.677180000000000000
        Top = 405.021691830000000000
        Width = 34.015770000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
      object Memo31: TfrxMemoView
        Left = 68.031540000000000000
        Top = 405.021691830000000000
        Width = 90.708720000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
      object Memo32: TfrxMemoView
        Left = 177.637910000000000000
        Top = 405.021691830000000000
        Width = 18.897650000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        VAlign = vaCenter
      end
      object Line9: TfrxLineView
        Left = 177.637910000000000000
        Top = 420.139811830000000000
        Width = 18.897650000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo33: TfrxMemoView
        Left = 196.535560000000000000
        Top = 405.021691830000000000
        Width = 45.354360000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1075'. '#1087#1086' '#171' ')
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo34: TfrxMemoView
        Left = 275.905690000000000000
        Top = 405.021691830000000000
        Width = 11.338590000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #187)
        ParentFont = False
      end
      object Memo35: TfrxMemoView
        Left = 241.889920000000000000
        Top = 405.021691830000000000
        Width = 34.015770000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
      object Memo36: TfrxMemoView
        Left = 286.191648420000000000
        Top = 405.021691830000000000
        Width = 90.708720000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
      object Memo37: TfrxMemoView
        Left = 396.850650000000000000
        Top = 405.021691830000000000
        Width = 18.897650000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo38: TfrxMemoView
        Left = 415.748300000000000000
        Top = 405.021691830000000000
        Width = 15.118120000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1075'.')
        ParentFont = False
        VAlign = vaCenter
      end
      object Line10: TfrxLineView
        Left = 238.110390000000000000
        Top = 420.139811830000000000
        Width = 37.795300000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line11: TfrxLineView
        Left = 283.464750000000000000
        Top = 420.139811830000000000
        Width = 94.488250000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line12: TfrxLineView
        Left = 396.850650000000000000
        Top = 420.139811830000000000
        Width = 18.897650000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo13: TfrxMemoView
        Left = 419.527830000000000000
        Top = 465.494171830000000000
        Width = 60.472480000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '('#1087#1086#1076#1087#1080#1089#1100')')
        ParentFont = False
      end
      object Memo18: TfrxMemoView
        Top = 646.430897090000000000
        Width = 132.283550000000000000
        Height = 34.015770000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1052'.'#1055'.'
          #1091#1095#1077#1073#1085#1086#1075#1086' '#1079#1072#1074#1077#1076#1077#1085#1080#1103)
        ParentFont = False
      end
      object Memo28: TfrxMemoView
        Left = 192.756030000000000000
        Top = 646.430897090000000000
        Width = 291.023810000000000000
        Height = 37.795300000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1053#1072#1095#1072#1083#1100#1085#1080#1082' '#1091#1095#1077#1073#1085#1086#1075#1086' '#1079#1072#1074#1077#1076#1077#1085#1080#1103
          '('#1089#1086#1086#1090#1074#1077#1090#1089#1090#1074#1091#1102#1097#1077#1075#1086' '#1087#1086#1076#1088#1072#1079#1076#1077#1083#1077#1085#1080#1103')________')
        ParentFont = False
      end
      object Memo29: TfrxMemoView
        Left = 419.527830000000000000
        Top = 680.446667090000000000
        Width = 60.472480000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '('#1087#1086#1076#1087#1080#1089#1100')')
        ParentFont = False
      end
      object Memo39: TfrxMemoView
        Top = 563.281237090000000000
        Width = 83.149660000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1057#1090#1091#1076#1077#1085#1090'(-'#1082#1072')')
        ParentFont = False
      end
      object Memo40: TfrxMemoView
        Left = 192.756030000000000000
        Top = 582.178887090000000000
        Width = 162.519790000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '('#1092#1072#1084#1080#1083#1080#1103', '#1080#1084#1103', '#1086#1090#1095#1077#1089#1090#1074#1086')')
        ParentFont = False
      end
      object Line13: TfrxLineView
        Left = 83.149660000000000000
        Top = 582.178887090000000000
        Width = 396.850650000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo41: TfrxMemoView
        Top = 597.297007090000000000
        Width = 132.283550000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1055#1088#1080#1085#1103#1083'('#1072') '#1091#1095#1072#1089#1090#1080#1077' '#1074)
        ParentFont = False
      end
      object Line14: TfrxLineView
        Left = 132.283550000000000000
        Top = 616.194657090000000000
        Width = 351.496290000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo42: TfrxMemoView
        Top = 616.194657090000000000
        Width = 22.677180000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1089' '#171)
        ParentFont = False
      end
      object Memo43: TfrxMemoView
        Left = 56.692950000000000000
        Top = 616.194657090000000000
        Width = 11.338590000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #187)
        ParentFont = False
      end
      object Memo44: TfrxMemoView
        Left = 22.677180000000000000
        Top = 616.194657090000000000
        Width = 34.015770000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
      object Memo45: TfrxMemoView
        Left = 68.031540000000000000
        Top = 616.194657090000000000
        Width = 90.708720000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
      object Memo46: TfrxMemoView
        Left = 177.637910000000000000
        Top = 616.194657090000000000
        Width = 18.897650000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo47: TfrxMemoView
        Left = 196.535560000000000000
        Top = 616.194657090000000000
        Width = 45.354360000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1075'. '#1087#1086' '#171' ')
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo48: TfrxMemoView
        Left = 275.905690000000000000
        Top = 616.194657090000000000
        Width = 11.338590000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #187)
        ParentFont = False
      end
      object Memo49: TfrxMemoView
        Left = 241.889920000000000000
        Top = 616.194657090000000000
        Width = 34.015770000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
      object Memo50: TfrxMemoView
        Left = 287.244280000000000000
        Top = 616.194657090000000000
        Width = 90.708720000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
      object Memo51: TfrxMemoView
        Left = 396.850650000000000000
        Top = 616.194657090000000000
        Width = 18.897650000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo52: TfrxMemoView
        Left = 415.748300000000000000
        Top = 616.194657090000000000
        Width = 15.118120000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1075'.')
        ParentFont = False
        VAlign = vaCenter
      end
      object Line15: TfrxLineView
        Left = 18.897650000000000000
        Top = 631.312777090000000000
        Width = 37.795300000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line16: TfrxLineView
        Left = 64.252010000000000000
        Top = 631.312777090000000000
        Width = 94.488250000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line17: TfrxLineView
        Left = 177.637910000000000000
        Top = 631.312777090000000000
        Width = 18.897650000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line18: TfrxLineView
        Left = 238.110390000000000000
        Top = 631.312777090000000000
        Width = 37.795300000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line19: TfrxLineView
        Left = 283.464750000000000000
        Top = 631.312777090000000000
        Width = 94.488250000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line20: TfrxLineView
        Left = 396.850650000000000000
        Top = 631.312777090000000000
        Width = 18.897650000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo53: TfrxMemoView
        Left = 158.740260000000000000
        Top = 405.021691830000000000
        Width = 18.897650000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '20')
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo54: TfrxMemoView
        Left = 377.953000000000000000
        Top = 405.021691830000000000
        Width = 18.897650000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '20')
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo55: TfrxMemoView
        Left = 158.740260000000000000
        Top = 616.194657090000000000
        Width = 18.897650000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '20')
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo56: TfrxMemoView
        Left = 377.953000000000000000
        Top = 616.194657090000000000
        Width = 18.897650000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '20')
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo57: TfrxMemoView
        Left = 192.756030000000000000
        Top = 136.063080000000000000
        Width = 18.897650000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '20')
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo58: TfrxMemoView
        Left = 83.149660000000000000
        Top = 563.281237090000000000
        Width = 396.850650000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        Memo.UTF8W = (
          
            '[<frxDBDataset1."FAM">] [<frxDBDataset1."NAME">] [<frxDBDataset1' +
            '."OTCH">]')
        ParentFont = False
      end
      object Memo60: TfrxMemoView
        Top = 325.039580000000000000
        Width = 249.448980000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1091#1095#1077#1073#1085#1086#1081' '#1087#1088#1072#1082#1090#1080#1082#1080' '#1087#1086' '#1083#1099#1078#1085#1086#1084#1091' '#1089#1087#1086#1088#1090#1091',')
        ParentFont = False
      end
      object Memo11: TfrxMemoView
        Left = 249.448980000000000000
        Top = 325.039580000000000000
        Width = 196.535560000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1091#1095#1077#1073#1085#1086#1081' '#1087#1088#1072#1082#1090#1080#1082#1080' '#1087#1086' '#1090#1091#1088#1080#1079#1084#1091',')
        ParentFont = False
      end
      object Memo59: TfrxMemoView
        Left = 359.055350000000000000
        Top = 306.141930000000000000
        Width = 120.944960000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1091#1095#1077#1073#1085#1086#1081' '#1087#1088#1072#1082#1090#1080#1082#1080',')
        ParentFont = False
      end
      object Memo62: TfrxMemoView
        Top = 344.210526310000000000
        Width = 351.578947370000000000
        Height = 18.900000000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1087#1088#1086#1092#1077#1089#1089#1080#1086#1085#1072#1083#1100#1085#1086'-'#1086#1088#1080#1077#1085#1090#1080#1088#1086#1074#1072#1085#1085#1086#1081' '#1091#1095#1077#1073#1085#1086#1081' '#1087#1088#1072#1082#1090#1080#1082#1080',')
        ParentFont = False
      end
      object Memo61: TfrxMemoView
        Top = 381.395348840000000000
        Width = 177.880597890000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1087#1088#1086#1080#1079#1074#1086#1076#1089#1090#1074#1077#1085#1085#1086#1081' '#1087#1088#1072#1082#1090#1080#1082#1080)
        ParentFont = False
      end
      object Memo63: TfrxMemoView
        Left = 128.000000000000000000
        Top = 597.000000000000000000
        Width = 355.165430000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
    end
  end
  object frxReport2: TfrxReport
    Version = '5.6.1'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 42926.655111805600000000
    ReportOptions.LastChange = 42926.655111805600000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 320
    Top = 40
    Datasets = <
      item
      end
      item
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'Times New Roman'
      Font.Style = []
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      object Memo2: TfrxMemoView
        Left = 340.157700000000000000
        Top = 185.196970000000000000
        Width = 94.488250000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1057#1055#1056#1040#1042#1050#1040)
        ParentFont = False
      end
      object Memo3: TfrxMemoView
        Left = 196.535560000000000000
        Top = 211.653680000000000000
        Width = 370.393940000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1086' '#1090#1086#1084', '#1095#1090#1086' '#1075#1088#1072#1078#1076#1072#1085#1080#1085' '#1103#1074#1083#1103#1077#1090#1089#1103' '#1086#1073#1091#1095#1072#1102#1097#1080#1084#1089#1103)
        ParentFont = False
        VAlign = vaCenter
      end
      object Line1: TfrxLineView
        Left = 298.582870000000000000
        Top = 249.448980000000000000
        Width = 79.370130000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line2: TfrxLineView
        Left = 400.630180000000000000
        Top = 249.448980000000000000
        Width = 105.826840000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo4: TfrxMemoView
        Left = 381.732530000000000000
        Top = 234.330860000000000000
        Width = 18.897650000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -17
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #8470)
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo5: TfrxMemoView
        Left = 321.260050000000000000
        Top = 249.448980000000000000
        Width = 34.015770000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '('#1076#1072#1090#1072')')
        ParentFont = False
      end
      object Memo6: TfrxMemoView
        Left = 113.385900000000000000
        Top = 279.685220000000000000
        Width = 71.811070000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1042#1099#1076#1072#1085#1072)
        ParentFont = False
        VAlign = vaCenter
      end
      object Line3: TfrxLineView
        Left = 185.196970000000000000
        Top = 298.582870000000000000
        Width = 517.795253620000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo8: TfrxMemoView
        Left = 64.252010000000000000
        Top = 302.362204720000000000
        Width = 124.724490000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1074'   '#1090#1086#1084',   '#1095#1090#1086'   '#1089' ')
        ParentFont = False
        VAlign = vaCenter
      end
      object Line4: TfrxLineView
        Left = 204.094620000000000000
        Top = 317.480520000000000000
        Width = 26.456710000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line5: TfrxLineView
        Left = 241.889920000000000000
        Top = 317.480520000000000000
        Width = 86.929190000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line6: TfrxLineView
        Left = 340.157700000000000000
        Top = 317.480520000000000000
        Width = 41.574830000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo9: TfrxMemoView
        Left = 381.732530000000000000
        Top = 302.362204720000000000
        Width = 340.157700000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haBlock
        Memo.UTF8W = (
          #1075'.   '#1086#1085'   ('#1086#1085#1072')   '#1076#1077#1081#1089#1090#1074#1080#1090#1077#1083#1100#1085#1086'   '#1103#1074#1083#1103#1077#1090#1089#1103)
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo14: TfrxMemoView
        Left = 68.031540000000000000
        Top = 699.213050000000000000
        Width = 548.031850000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1057#1087#1088#1072#1074#1082#1072' '#1076#1077#1081#1089#1090#1074#1080#1090#1077#1083#1100#1085#1072' '#1096#1077#1089#1090#1100' '#1084#1077#1089#1103#1094#1077#1074' '#1089' '#1076#1072#1090#1099' '#1074#1099#1076#1072#1095#1080'.')
        ParentFont = False
      end
      object Memo19: TfrxMemoView
        Left = 185.196970000000000000
        Top = 279.685220000000000000
        Width = 517.795610000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          
            '[frxDBDataset2."FAM"] [frxDBDataset2."NAME"] [frxDBDataset2."OTC' +
            'H"]')
        ParentFont = False
        Formats = <
          item
          end
          item
          end
          item
          end>
      end
      object Memo20: TfrxMemoView
        Left = 204.094620000000000000
        Top = 302.362204720000000000
        Width = 26.456710000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo21: TfrxMemoView
        Left = 241.889920000000000000
        Top = 302.362204720000000000
        Width = 86.929190000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo22: TfrxMemoView
        Left = 340.157700000000000000
        Top = 302.362204720000000000
        Width = 41.574830000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo27: TfrxMemoView
        Left = 400.630180000000000000
        Top = 230.551330000000000000
        Width = 105.826840000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
      object SysMemo1: TfrxSysMemoView
        Left = 298.582870000000000000
        Top = 230.551330000000000000
        Width = 83.149660000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '[DATE]')
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo31: TfrxMemoView
        Left = 64.252010000000000000
        Top = 476.220455350000000000
        Width = 634.961040000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        LineSpacing = 10.000000000000000000
        ParentFont = False
      end
      object Memo32: TfrxMemoView
        Left = 64.252010000000000000
        Top = 498.897620710000000000
        Width = 634.961040000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        LineSpacing = 10.000000000000000000
        ParentFont = False
      end
      object Memo33: TfrxMemoView
        Left = 64.252010000000000000
        Top = 521.574786060000000000
        Width = 634.961040000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        LineSpacing = 10.000000000000000000
        ParentFont = False
      end
      object Memo34: TfrxMemoView
        Left = 64.252010000000000000
        Top = 544.251951420000000000
        Width = 634.961040000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        LineSpacing = 10.000000000000000000
        ParentFont = False
      end
      object Memo15: TfrxMemoView
        Left = 68.031540000000000000
        Top = 748.346940000000000000
        Width = 185.196970000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1044#1077#1082#1072#1085' '#1092#1072#1082#1091#1083#1100#1090#1077#1090#1072)
        ParentFont = False
      end
      object Line21: TfrxLineView
        Left = 253.228510000000000000
        Top = 771.024120000000000000
        Width = 132.283550000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line22: TfrxLineView
        Left = 529.134200000000000000
        Top = 767.244590000000000000
        Width = 151.181200000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo16: TfrxMemoView
        Left = 68.031540000000000000
        Top = 771.024120000000000000
        Width = 45.354360000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1052#1055)
        ParentFont = False
      end
      object Memo17: TfrxMemoView
        Left = 291.023810000000000000
        Top = 771.024120000000000000
        Width = 56.692950000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '('#1087#1086#1076#1087#1080#1089#1100')')
        ParentFont = False
      end
      object Memo18: TfrxMemoView
        Left = 548.031850000000000000
        Top = 767.244590000000000000
        Width = 117.165430000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '('#1080#1085#1080#1094#1080#1072#1083#1099', '#1092#1072#1084#1080#1083#1080#1103')')
        ParentFont = False
      end
      object Memo26: TfrxMemoView
        Left = 529.134200000000000000
        Top = 744.567410000000000000
        Width = 151.181200000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        Memo.UTF8W = (
          '[frxDBDataset2."DEAN"]')
        ParentFont = False
      end
      object Memo12: TfrxMemoView
        Left = 64.252010000000000000
        Top = 566.929116770000000000
        Width = 634.961040000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        LineSpacing = 10.000000000000000000
        ParentFont = False
      end
      object Memo35: TfrxMemoView
        Left = 64.252010000000000000
        Top = 589.606282130000000000
        Width = 634.961040000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        LineSpacing = 10.000000000000000000
        ParentFont = False
      end
      object Memo36: TfrxMemoView
        Left = 64.252010000000000000
        Top = 612.283447480000000000
        Width = 634.961040000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        LineSpacing = 10.000000000000000000
        ParentFont = False
      end
      object Memo28: TfrxMemoView
        Left = 64.252010000000000000
        Top = 453.543290000000000000
        Width = 634.961040000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        LineSpacing = 10.000000000000000000
        ParentFont = False
      end
      object Memo37: TfrxMemoView
        Left = 64.252010000000000000
        Top = 321.260050000000000000
        Width = 634.961040000000000000
        Height = 192.756030000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haBlock
        LineSpacing = 3.000000000000000000
        Memo.UTF8W = (
          
            #1086#1073#1091#1095#1072#1102#1097#1080#1084#1089#1103' [frxDBDataset2."N_GROUP"] '#1075#1088#1091#1087#1087#1099' [frxDBDataset2."KUR' +
            'S"] '#1082#1091#1088#1089#1072', [IIF(<frxDBDataset2."VID_EDU">=1,'#39#1079#1072#1086#1095#1085#1086#1081#39','#39#1076#1085#1077#1074#1085#1086#1081#39')' +
            '] '#1092#1086#1088#1084#1099' '#1087#1086#1083#1091#1095#1077#1085#1080#1103' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103' [frxDBDataset2."FAC_RP"], '#1085#1072#1087#1088#1072#1074#1083#1077 +
            #1085#1080#1077' '#1089#1087#1077#1094#1080#1072#1083#1100#1085#1086#1089#1090#1080' [frxDBDataset2."CODE_SPEC_DIR"] [IIF(<frxDBDat' +
            'aset2."SPECIAL_DIRECTION"> = null,<frxDBDataset2."SPECIAL">,<frx' +
            'DBDataset2."SPECIAL_DIRECTION">)], '#1091#1095#1088#1077#1078#1076#1077#1085#1080#1103' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103' "'#1041#1077#1083#1086#1088 +
            #1091#1089#1089#1082#1080#1081' '#1075#1086#1089#1091#1076#1072#1088#1089#1090#1074#1077#1085#1085#1099#1081' '#1091#1085#1080#1074#1077#1088#1089#1080#1090#1077#1090' '#1092#1080#1079#1080#1095#1077#1089#1082#1086#1081' '#1082#1091#1083#1100#1090#1091#1088#1099'".'
          '')
        ParentFont = False
        Formats = <
          item
          end
          item
          end
          item
          end
          item
          end
          item
          end
          item
          end>
      end
      object Memo42: TfrxMemoView
        Left = 400.630180000000000000
        Top = 90.708720000000000000
        Width = 298.582870000000000000
        Height = 94.488250000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
      object Memo1: TfrxMemoView
        Left = 64.252010000000000000
        Top = 634.961040000000000000
        Width = 634.961040000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        LineSpacing = 10.000000000000000000
        ParentFont = False
      end
    end
  end
  object frxReport3: TfrxReport
    Version = '5.6.1'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 42930.808039525470000000
    ReportOptions.LastChange = 42930.808039525470000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 408
    Top = 40
    Datasets = <
      item
      end>
    Variables = <>
    Style = <>
    object Data: TfrxDataPage
      Height = 1000.000000000000000000
      Width = 1000.000000000000000000
    end
    object Page1: TfrxReportPage
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -19
      Font.Name = 'Times New Roman'
      Font.Style = []
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      object Memo2: TfrxMemoView
        Left = 336.378170000000000000
        Top = 355.275820000000000000
        Width = 94.488250000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1057#1055#1056#1040#1042#1050#1040)
        ParentFont = False
      end
      object Memo3: TfrxMemoView
        Left = 192.756030000000000000
        Top = 381.732530000000000000
        Width = 370.393940000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1086' '#1090#1086#1084', '#1095#1090#1086' '#1075#1088#1072#1078#1076#1072#1085#1080#1085' '#1103#1074#1083#1103#1077#1090#1089#1103' '#1086#1073#1091#1095#1072#1102#1097#1080#1084#1089#1103)
        ParentFont = False
        VAlign = vaCenter
      end
      object Line1: TfrxLineView
        Left = 294.803340000000000000
        Top = 419.527830000000000000
        Width = 79.370130000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line2: TfrxLineView
        Left = 396.850650000000000000
        Top = 419.527830000000000000
        Width = 102.047310000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo4: TfrxMemoView
        Left = 377.953000000000000000
        Top = 404.409710000000000000
        Width = 18.897650000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -17
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #8470)
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo5: TfrxMemoView
        Left = 317.480520000000000000
        Top = 419.527830000000000000
        Width = 34.015770000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '('#1076#1072#1090#1072')')
        ParentFont = False
      end
      object Memo6: TfrxMemoView
        Left = 109.606370000000000000
        Top = 449.764070000000000000
        Width = 71.811070000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1042#1099#1076#1072#1085#1072)
        ParentFont = False
        VAlign = vaCenter
      end
      object Line3: TfrxLineView
        Left = 181.417440000000000000
        Top = 468.661720000000000000
        Width = 517.795253620000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo8: TfrxMemoView
        Left = 60.472480000000000000
        Top = 472.441054720000000000
        Width = 124.724490000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1074'   '#1090#1086#1084',   '#1095#1090#1086'   '#1089' ')
        ParentFont = False
        VAlign = vaCenter
      end
      object Line4: TfrxLineView
        Left = 200.315090000000000000
        Top = 487.559370000000000000
        Width = 26.456710000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line5: TfrxLineView
        Left = 238.110390000000000000
        Top = 487.559370000000000000
        Width = 86.929190000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line6: TfrxLineView
        Left = 336.378170000000000000
        Top = 487.559370000000000000
        Width = 41.574830000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo9: TfrxMemoView
        Left = 377.953000000000000000
        Top = 472.441054720000000000
        Width = 340.157700000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haBlock
        Memo.UTF8W = (
          #1075'.   '#1086#1085'   ('#1086#1085#1072')   '#1076#1077#1081#1089#1090#1074#1080#1090#1077#1083#1100#1085#1086'   '#1103#1074#1083#1103#1077#1090#1089#1103)
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo14: TfrxMemoView
        Left = 64.252010000000000000
        Top = 850.394250000000000000
        Width = 548.031850000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1057#1087#1088#1072#1074#1082#1072' '#1076#1077#1081#1089#1090#1074#1080#1090#1077#1083#1100#1085#1072' '#1096#1077#1089#1090#1100' '#1084#1077#1089#1103#1094#1077#1074' '#1089' '#1076#1072#1090#1099' '#1074#1099#1076#1072#1095#1080'.')
        ParentFont = False
      end
      object Memo19: TfrxMemoView
        Left = 181.417440000000000000
        Top = 449.764070000000000000
        Width = 517.795610000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          
            '[frxDBDataset2."FAM"] [frxDBDataset2."NAME"] [frxDBDataset2."OTC' +
            'H"]')
        ParentFont = False
        Formats = <
          item
          end
          item
          end
          item
          end>
      end
      object Memo20: TfrxMemoView
        Left = 200.315090000000000000
        Top = 472.441054720000000000
        Width = 26.456710000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo21: TfrxMemoView
        Left = 238.110390000000000000
        Top = 472.441054720000000000
        Width = 86.929190000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo22: TfrxMemoView
        Left = 336.378170000000000000
        Top = 472.441054720000000000
        Width = 41.574830000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo27: TfrxMemoView
        Left = 396.850650000000000000
        Top = 400.630180000000000000
        Width = 102.047310000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
      end
      object SysMemo1: TfrxSysMemoView
        Left = 294.803340000000000000
        Top = 400.630180000000000000
        Width = 83.149660000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '[DATE]')
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo31: TfrxMemoView
        Left = 60.472480000000000000
        Top = 646.299305350000000000
        Width = 638.740570000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        LineSpacing = 10.000000000000000000
        ParentFont = False
      end
      object Memo32: TfrxMemoView
        Left = 60.472480000000000000
        Top = 668.976470710000000000
        Width = 638.740570000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        LineSpacing = 10.000000000000000000
        ParentFont = False
      end
      object Memo33: TfrxMemoView
        Left = 60.472480000000000000
        Top = 691.653636060000000000
        Width = 638.740570000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        LineSpacing = 10.000000000000000000
        ParentFont = False
      end
      object Memo34: TfrxMemoView
        Left = 60.472480000000000000
        Top = 714.330801420000000000
        Width = 638.740570000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        LineSpacing = 10.000000000000000000
        ParentFont = False
      end
      object Memo15: TfrxMemoView
        Left = 64.252010000000000000
        Top = 899.528140000000000000
        Width = 185.196970000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1056#1077#1082#1090#1086#1088' '#1091#1085#1080#1074#1077#1088#1089#1080#1090#1077#1090#1072)
        ParentFont = False
      end
      object Line21: TfrxLineView
        Left = 249.448980000000000000
        Top = 922.205320000000000000
        Width = 132.283550000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line22: TfrxLineView
        Left = 525.354670000000000000
        Top = 918.425790000000000000
        Width = 151.181200000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo17: TfrxMemoView
        Left = 287.244280000000000000
        Top = 922.205320000000000000
        Width = 56.692950000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '('#1087#1086#1076#1087#1080#1089#1100')')
        ParentFont = False
      end
      object Memo18: TfrxMemoView
        Left = 544.252320000000000000
        Top = 918.425790000000000000
        Width = 117.165430000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '('#1080#1085#1080#1094#1080#1072#1083#1099', '#1092#1072#1084#1080#1083#1080#1103')')
        ParentFont = False
      end
      object Memo26: TfrxMemoView
        Left = 525.354670000000000000
        Top = 895.748610000000000000
        Width = 151.181200000000000000
        Height = 30.236240000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        Memo.UTF8W = (
          #1057'. '#1041'. '#1056#1077#1087#1082#1080#1085)
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo12: TfrxMemoView
        Left = 60.472480000000000000
        Top = 737.007966770000000000
        Width = 638.740570000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        LineSpacing = 10.000000000000000000
        ParentFont = False
      end
      object Memo35: TfrxMemoView
        Left = 60.472480000000000000
        Top = 759.685132130000000000
        Width = 638.740570000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        LineSpacing = 10.000000000000000000
        ParentFont = False
      end
      object Memo36: TfrxMemoView
        Left = 60.472480000000000000
        Top = 782.362297480000000000
        Width = 638.740570000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        LineSpacing = 10.000000000000000000
        ParentFont = False
      end
      object Memo28: TfrxMemoView
        Left = 60.472480000000000000
        Top = 623.622140000000000000
        Width = 638.740570000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        LineSpacing = 10.000000000000000000
        ParentFont = False
      end
      object Memo37: TfrxMemoView
        Left = 60.472480000000000000
        Top = 491.338900000000000000
        Width = 638.740570000000000000
        Height = 188.976500000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haBlock
        LineSpacing = 3.000000000000000000
        Memo.UTF8W = (
          
            #1086#1073#1091#1095#1072#1102#1097#1080#1084#1089#1103' [frxDBDataset2."N_GROUP"] '#1075#1088#1091#1087#1087#1099' [frxDBDataset2."KUR' +
            'S"] '#1082#1091#1088#1089#1072', [IIF(<frxDBDataset2."VID_EDU">=1,'#39#1079#1072#1086#1095#1085#1086#1081#39','#39#1076#1085#1077#1074#1085#1086#1081#39')' +
            '] '#1092#1086#1088#1084#1099' '#1087#1086#1083#1091#1095#1077#1085#1080#1103' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103' [frxDBDataset2."FAC_RP"], '#1085#1072#1087#1088#1072#1074#1083#1077 +
            #1085#1080#1077' '#1089#1087#1077#1094#1080#1072#1083#1100#1085#1086#1089#1090#1080' [frxDBDataset2."CODE_SPEC_DIR"] [IIF(<frxDBDat' +
            'aset2."SPECIAL_DIRECTION"> = null,<frxDBDataset2."SPECIAL">,<frx' +
            'DBDataset2."SPECIAL_DIRECTION">)], '#1091#1095#1088#1077#1078#1076#1077#1085#1080#1103' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103' "'#1041#1077#1083#1086#1088 +
            #1091#1089#1089#1082#1080#1081' '#1075#1086#1089#1091#1076#1072#1088#1089#1090#1074#1077#1085#1085#1099#1081' '#1091#1085#1080#1074#1077#1088#1089#1080#1090#1077#1090' '#1092#1080#1079#1080#1095#1077#1089#1082#1086#1081' '#1082#1091#1083#1100#1090#1091#1088#1099'".')
        ParentFont = False
        Formats = <
          item
          end
          item
          end
          item
          end
          item
          end
          item
          end
          item
          end>
      end
      object Memo41: TfrxMemoView
        Left = 64.252010000000000000
        Top = 963.780150000000000000
        Width = 200.315090000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1044#1077#1082#1072#1085' '#1092#1072#1082#1091#1083#1100#1090#1077#1090#1072)
        ParentFont = False
      end
      object Line7: TfrxLineView
        Left = 249.448980000000000000
        Top = 986.457330000000000000
        Width = 132.283550000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line8: TfrxLineView
        Left = 525.354670000000000000
        Top = 982.677800000000000000
        Width = 151.181200000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo7: TfrxMemoView
        Left = 64.252010000000000000
        Top = 986.457330000000000000
        Width = 45.354360000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1052#1055)
        ParentFont = False
      end
      object Memo10: TfrxMemoView
        Left = 287.244280000000000000
        Top = 986.457330000000000000
        Width = 56.692950000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '('#1087#1086#1076#1087#1080#1089#1100')')
        ParentFont = False
      end
      object Memo11: TfrxMemoView
        Left = 544.252320000000000000
        Top = 982.677800000000000000
        Width = 117.165430000000000000
        Height = 18.897650000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '('#1080#1085#1080#1094#1080#1072#1083#1099', '#1092#1072#1084#1080#1083#1080#1103')')
        ParentFont = False
      end
      object Memo13: TfrxMemoView
        Left = 525.354670000000000000
        Top = 960.000620000000000000
        Width = 151.181200000000000000
        Height = 30.236240000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        Memo.UTF8W = (
          '[frxDBDataset2."DEAN"]')
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo42: TfrxMemoView
        Left = 396.850650000000000000
        Top = 260.787570000000000000
        Width = 298.582870000000000000
        Height = 94.488250000000000000
      end
      object Memo1: TfrxMemoView
        Left = 60.472480000000000000
        Top = 805.039890000000000000
        Width = 638.740570000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -19
        Font.Name = 'Times New Roman'
        Font.Style = []
        LineSpacing = 10.000000000000000000
        ParentFont = False
      end
    end
  end
end

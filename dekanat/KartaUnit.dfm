object Medical_checklist_print_Form: TMedical_checklist_print_Form
  Left = 0
  Top = 0
  Caption = 'Medical_checklist_print_Form'
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
    Version = '5.3.14'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 42905.619091643520000000
    ReportOptions.LastChange = 42905.619091643520000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 152
    Top = 40
    Datasets = <
      item
        DataSet = frxDBDataset1
        DataSetName = 'frxDBDataset1'
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
      Font.Name = 'Arial'
      Font.Style = []
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      object Memo1: TfrxMemoView
        Left = 188.976500000000000000
        Width = 340.157700000000000000
        Height = 56.692950000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -21
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        HAlign = haCenter
        Memo.UTF8W = (
          #1042#1088#1072#1095#1077#1073#1085#1086'-'#1082#1086#1085#1090#1088#1086#1083#1100#1085#1072#1103' '#1082#1072#1088#1090#1072' '#1092#1080#1079#1082#1091#1083#1100#1090#1091#1088#1085#1080#1082#1072' '#1080' '#1089#1087#1086#1088#1090#1089#1084#1077#1085#1072)
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo2: TfrxMemoView
        Left = 117.165430000000000000
        Top = 109.606370000000000000
        Width = 109.606370000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        Memo.UTF8W = (
          #1044#1072#1090#1072' '#1079#1072#1087#1086#1083#1085#1077#1085#1080#1103)
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo3: TfrxMemoView
        Left = 427.086890000000000000
        Top = 109.606370000000000000
        Width = 94.488250000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        Memo.UTF8W = (
          #1042#1080#1076' '#1089#1087#1086#1088#1090#1072)
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo4: TfrxMemoView
        Left = 37.795300000000000000
        Top = 154.960730000000000000
        Width = 170.078850000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '1. '#1060#1072#1084#1080#1083#1080#1103', '#1080#1084#1103', '#1086#1090#1095#1077#1089#1090#1074#1086)
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo5: TfrxMemoView
        Left = 37.795300000000000000
        Top = 177.637910000000000000
        Width = 117.165430000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '2. '#1044#1072#1090#1072' '#1088#1086#1078#1076#1077#1085#1080#1103)
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo6: TfrxMemoView
        Left = 434.645950000000000000
        Top = 177.637910000000000000
        Width = 45.354360000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '3. '#1055#1086#1083)
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo8: TfrxMemoView
        Left = 377.953000000000000000
        Top = 222.992270000000000000
        Width = 56.692950000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        Memo.UTF8W = (
          #1090#1077#1083#1077#1092#1086#1085)
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo9: TfrxMemoView
        Left = 37.795300000000000000
        Top = 245.669450000000000000
        Width = 102.047310000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '5. '#1054#1073#1088#1072#1079#1086#1074#1072#1085#1080#1077)
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo10: TfrxMemoView
        Left = 37.795300000000000000
        Top = 268.346630000000000000
        Width = 185.196970000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '6. '#1055#1077#1088#1077#1085#1077#1089#1105#1085#1085#1099#1077': '#1072') '#1073#1086#1083#1077#1079#1085#1080)
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo11: TfrxMemoView
        Left = 37.795300000000000000
        Top = 359.055350000000000000
        Width = 68.031540000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1073') '#1090#1088#1072#1074#1084#1099)
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo12: TfrxMemoView
        Left = 37.795300000000000000
        Top = 404.409710000000000000
        Width = 79.370130000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1074') '#1086#1087#1077#1088#1072#1094#1080#1080)
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo13: TfrxMemoView
        Left = 37.795300000000000000
        Top = 449.764070000000000000
        Width = 64.252010000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '7. '#1056#1072#1079#1088#1103#1076)
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo14: TfrxMemoView
        Width = 188.976500000000000000
        Height = 45.354360000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        Memo.UTF8W = (
          #1041#1043#1059#1060#1050)
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo15: TfrxMemoView
        Top = 45.354360000000000000
        Width = 188.976500000000000000
        Height = 26.456695350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -21
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        Memo.UTF8W = (
          '[frxDBDataset1."FAC1"]')
        ParentFont = False
        VAlign = vaCenter
      end
      object Memo16: TfrxMemoView
        Top = 71.811070000000000000
        Width = 188.976500000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        Memo.UTF8W = (
          '[frxDBDataset1."N_GROUP"]')
        ParentFont = False
        VAlign = vaCenter
      end
      object Line1: TfrxLineView
        Left = 226.771800000000000000
        Top = 132.283550000000000000
        Width = 196.535560000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line2: TfrxLineView
        Left = 521.575140000000000000
        Top = 132.283550000000000000
        Width = 196.535560000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line3: TfrxLineView
        Left = 207.874150000000000000
        Top = 177.637910000000000000
        Width = 510.236550000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line4: TfrxLineView
        Left = 151.181200000000000000
        Top = 200.314953310000000000
        Width = 279.685220000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line5: TfrxLineView
        Left = 476.220780000000000000
        Top = 200.314953310000000000
        Width = 241.889920000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line6: TfrxLineView
        Left = 154.960629921259800000
        Top = 222.992118660000000000
        Width = 563.149606299212600000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line7: TfrxLineView
        Left = 37.795300000000000000
        Top = 245.669284020000000000
        Width = 340.157700000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line8: TfrxLineView
        Left = 434.645950000000000000
        Top = 245.669284020000000000
        Width = 283.464750000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line9: TfrxLineView
        Left = 136.063080000000000000
        Top = 268.346449370000000000
        Width = 582.047620000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line10: TfrxLineView
        Left = 219.212740000000000000
        Top = 291.023614720000000000
        Width = 498.897960000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line11: TfrxLineView
        Left = 37.795300000000000000
        Top = 313.700780080000000000
        Width = 680.315400000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line12: TfrxLineView
        Left = 37.795300000000000000
        Top = 336.377945430000000000
        Width = 680.315400000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line13: TfrxLineView
        Left = 102.047310000000000000
        Top = 381.732290790000000000
        Width = 616.063390000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line14: TfrxLineView
        Left = 37.795300000000000000
        Top = 404.409456140000000000
        Width = 680.315400000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line15: TfrxLineView
        Left = 117.165430000000000000
        Top = 427.086621500000000000
        Width = 600.945270000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line16: TfrxLineView
        Left = 37.795300000000000000
        Top = 449.763786850000000000
        Width = 680.315400000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line17: TfrxLineView
        Left = 98.267780000000000000
        Top = 472.440952200000000000
        Width = 619.842920000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line18: TfrxLineView
        Left = 37.795300000000000000
        Top = 359.055118110236200000
        Width = 680.315400000000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Memo18: TfrxMemoView
        Left = 521.575140000000000000
        Top = 109.606370000000000000
        Width = 196.535560000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        Memo.UTF8W = (
          '[frxDBDataset1."VID_SPORT"]')
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo19: TfrxMemoView
        Left = 207.874150000000000000
        Top = 154.960730000000000000
        Width = 510.236550000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -24
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        HAlign = haCenter
        Memo.UTF8W = (
          
            '[<frxDBDataset1."FAM">] [<frxDBDataset1."NAME">] [<frxDBDataset1' +
            '."OTCH">]')
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo20: TfrxMemoView
        Left = 154.960730000000000000
        Top = 177.637910000000000000
        Width = 279.685220000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        Memo.UTF8W = (
          '[frxDBDataset1."DATA_R"]')
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo21: TfrxMemoView
        Left = 480.000310000000000000
        Top = 177.637910000000000000
        Width = 238.110390000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        Memo.UTF8W = (
          '[frxDBDataset1."POL"]')
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo22: TfrxMemoView
        Left = 139.842610000000000000
        Top = 245.669450000000000000
        Width = 582.047620000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        Memo.UTF8W = (
          '[frxDBDataset1."NAME_EDUC"]')
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo23: TfrxMemoView
        Left = 102.047310000000000000
        Top = 449.764070000000000000
        Width = 616.063390000000000000
        Height = 22.677165350000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        Memo.UTF8W = (
          '[frxDBDataset1."TEXT_SPORT_CATEGORY"]')
        ParentFont = False
        VAlign = vaBottom
      end
      object SysMemo1: TfrxSysMemoView
        Left = 226.771800000000000000
        Top = 109.606370000000000000
        Width = 200.315090000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Arial'
        Font.Style = []
        HAlign = haCenter
        Memo.UTF8W = (
          '[DATE]')
        ParentFont = False
        VAlign = vaBottom
      end
      object Picture1: TfrxPictureView
        Left = 642.520100000000000000
        Width = 75.590551180000000000
        Height = 100.913385830000000000
        DataSet = frxDBDataset1
        DataSetName = 'frxDBDataset1'
        HightQuality = False
        Transparent = False
        TransparentColor = clWhite
      end
      object Memo17: TfrxMemoView
        Left = 434.645950000000000000
        Top = 222.992270000000000000
        Width = 283.464750000000000000
        Height = 22.677180000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        ParentFont = False
        VAlign = vaBottom
      end
      object Memo7: TfrxMemoView
        Left = 37.795300000000000000
        Top = 207.874150000000000000
        Width = 680.315400000000000000
        Height = 41.574830000000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -15
        Font.Name = 'Times New Roman'
        Font.Style = []
        LineSpacing = 6.000000000000000000
        Memo.UTF8W = (
          '')
        ParentFont = False
      end
    end
  end
  object frxDBDataset1: TfrxDBDataset
    UserName = 'frxDBDataset1'
    CloseDataSource = False
    FieldAliases.Strings = (
      'NOMER=NOMER'
      'FAM=FAM'
      'NAME=NAME'
      'OTCH=OTCH'
      'PHOTO=PHOTO'
      'N_GROUP=N_GROUP'
      'DATA_R=DATA_R'
      'POL=POL'
      'ADDRESS=ADDRESS'
      'PHONE=PHONE'
      'NAME_EDUC=NAME_EDUC'
      'VID_SPORT=VID_SPORT'
      'TEXT_SPORT_CATEGORY=TEXT_SPORT_CATEGORY'
      'FAC1=FAC1')
    DataSource = Medical_Checklist_Form.DataSource1
    BCDToCurrency = False
    Left = 80
    Top = 40
  end
end

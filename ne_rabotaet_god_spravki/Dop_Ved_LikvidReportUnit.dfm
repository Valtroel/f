object Dop_Ved_LikvidReportForm: TDop_Ved_LikvidReportForm
  Left = 363
  Top = 160
  Caption = ' '
  ClientHeight = 463
  ClientWidth = 915
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  Scaled = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object frxPreview1: TfrxPreview
    Left = -16
    Top = -32
    Width = 860
    Height = 873
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
    PrintOptions.PrintOnSheet = 0
    PrintOptions.ShowDialog = False
    ReportOptions.CreateDate = 42669.461347442100000000
    ReportOptions.LastChange = 42669.461347442100000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 24
    Top = 64
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
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      Duplex = dmVertical
      object Rich2: TfrxRichView
        Left = 75.590600000000000000
        Top = 427.086890000000000000
        Width = 619.842920000000000000
        Height = 37.795300000000000000
        GapX = 2.000000000000000000
        GapY = 1.000000000000000000
        RichEdit = {
          7B5C727466315C616E73695C616E7369637067313235315C64656666305C6E6F
          7569636F6D7061745C6465666C616E67313034397B5C666F6E7474626C7B5C66
          305C666E696C5C66636861727365743230342054696D6573204E657720526F6D
          616E204359523B7D7B5C66315C666E696C5C6663686172736574323034205461
          686F6D613B7D7D0D0A7B5C2A5C67656E657261746F7220526963686564323020
          31302E302E31363239397D5C766965776B696E64345C756331200D0A5C706172
          645C6669343438305C66305C66733234205B667278444244617461736574312E
          2246494F5F4558414D225D5C66315C667331365C7061720D0A7D0D0A00}
      end
      object Rich1: TfrxRichView
        Left = 75.590600000000000000
        Top = 339.023622050000000000
        Width = 622.866300390000000000
        Height = 58.582677170000000000
        GapX = 2.000000000000000000
        GapY = 1.000000000000000000
        RichEdit = {
          7B5C727466315C616E73695C616E7369637067313235315C64656666305C6E6F
          7569636F6D7061745C6465666C616E67313034397B5C666F6E7474626C7B5C66
          305C666E696C5C6663686172736574302054696D6573204E657720526F6D616E
          3B7D7B5C66315C666E696C5C6663686172736574323034205461686F6D613B7D
          7D0D0A7B5C2A5C67656E657261746F722052696368656432302031302E302E31
          363239397D5C766965776B696E64345C756331200D0A5C706172645C66693230
          5C6C69333834305C66305C667332345C6C616E6731303333205B667278444244
          617461736574312E224E414D455F4F424A454354225D5C66315C667332305C6C
          616E67313034395C7061720D0A7D0D0A00}
      end
      object Memo1: TfrxMemoView
        Left = 283.086662990000000000
        Width = 249.448831100000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1059#1063#1056#1045#1046#1044#1045#1053#1048#1045' '#1054#1041#1056#1040#1047#1054#1042#1040#1053#1048#1071)
        ParentFont = False
      end
      object Memo2: TfrxMemoView
        Left = 84.283513390000000000
        Top = 20.031496060000000000
        Width = 628.913385830000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #171#1041#1045#1051#1054#1056#1059#1057#1057#1050#1048#1049' '#1043#1054#1057#1059#1044#1040#1056#1057#1058#1042#1045#1053#1053#1067#1049' '#1059#1053#1048#1042#1045#1056#1057#1048#1058#1045#1058' '#1060#1048#1047#1048#1063#1045#1057#1050#1054#1049' '#1050#1059#1051#1068#1058#1059#1056#1067#187)
        ParentFont = False
      end
      object Memo3: TfrxMemoView
        Left = 88.063048270000000000
        Top = 44.220472440000000000
        Width = 718.488601500000000000
        Height = 20.031496060000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold, fsItalic, fsUnderline]
        Memo.UTF8W = (
          
            #1051#1080#1082#1074#1080#1076#1072#1094#1080#1103' '#1088#1072#1089#1093#1086#1078#1076#1077#1085#1080#1103' '#1089' '#1091#1095#1077#1073#1085#1099#1084' '#1087#1083#1072#1085#1086#1084' '#1079#1072' [frxDBDataset1."KURS"' +
            '] '#1082#1091#1088#1089' [IIF(<frxDBDataset1."VID_EDU_PLAN">=0,'#39#1076#1085#1077#1074#1085#1086#1081#39','#39#1079#1072#1086#1095#1085#1086#1081#39 +
            ')] '#1092#1086#1088#1084#1099' '#1087#1086#1083#1091#1095#1077#1085#1080#1103' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103)
        ParentFont = False
        Formats = <
          item
          end
          item
          end>
      end
      object Memo4: TfrxMemoView
        Left = 130.015777320000000000
        Top = 72.944881890000000000
        Width = 510.236318110000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        Memo.UTF8W = (
          
            #1047#1040#1063#1045#1058#1053#1054'-'#1069#1050#1047#1040#1052#1045#1053#1040#1062#1048#1054#1053#1053#1040#1071' '#1042#1045#1044#1054#1052#1054#1057#1058#1068' '#8470' [IIF(<frxDBDataset1."N_FAC">' +
            '=3,'#39'07/03-'#39','#39#39')][<frxDBDataset1."N_VEDOMOST">] ')
        ParentFont = False
        Formats = <
          item
          end
          item
          end>
      end
      object Memo5: TfrxMemoView
        Left = 244.535481890000000000
        Top = 92.976377950000000000
        Width = 306.897650000000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        Memo.UTF8W = (
          #1090#1077#1082#1091#1097#1077#1081' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1080' '#1074#1085#1077' '#1091#1095#1077#1073#1085#1086#1081' '#1075#1088#1091#1087#1087#1099)
        ParentFont = False
      end
      object Memo6: TfrxMemoView
        Left = 75.590600000000000000
        Top = 125.858267720000000000
        Width = 283.086619060000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1060#1086#1088#1084#1072' '#1087#1086#1083#1091#1095#1077#1085#1080#1103' '#1074#1099#1089#1096#1077#1075#1086' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103)
        ParentFont = False
      end
      object Memo7: TfrxMemoView
        Left = 405.921308660000000000
        Top = 124.724409450000000000
        Width = 127.748031500000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        Memo.UTF8W = (
          '[IIF(<frxDBDataset1."VID_EDU_PLAN">=0,'#39#1076#1085#1077#1074#1085#1072#1103#39','#39#1079#1072#1086#1095#1085#1072#1103#39')] ')
        ParentFont = False
      end
      object Memo8: TfrxMemoView
        Left = 75.590600000000000000
        Top = 150.803149610000000000
        Width = 292.535437950000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1057#1090#1091#1087#1077#1085#1100' '#1087#1086#1083#1091#1095#1077#1085#1080#1103' '#1074#1099#1089#1096#1077#1075#1086' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103)
        ParentFont = False
      end
      object Memo9: TfrxMemoView
        Left = 413.480363780000000000
        Top = 148.913385830000000000
        Width = 59.338587560000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        Memo.UTF8W = (
          #1087#1077#1088#1074#1072#1103)
        ParentFont = False
      end
      object Memo10: TfrxMemoView
        Left = 75.590600000000000000
        Top = 176.503937010000000000
        Width = 199.559064880000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1060#1086#1088#1084#1072' '#1090#1077#1082#1091#1097#1077#1081' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1080)
        ParentFont = False
      end
      object Memo11: TfrxMemoView
        Left = 382.866190550000000000
        Top = 172.724409450000000000
        Width = 76.724409450000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          
            '[IIF(<frxDBDataset1."ZACH_EXAM">=1,'#39#1079#1072#1095#1077#1090#39',IIF(<frxDBDataset1."Z' +
            'ACH_EXAM">=2,'#39#1101#1082#1079#1072#1084#1077#1085#39',IIF(<frxDBDataset1."ZACH_EXAM">=3,'#39#1076#1080#1092'.'#1079#1072 +
            #1095#1077#1090#39','#39#39')))]')
        ParentFont = False
      end
      object Memo12: TfrxMemoView
        Left = 75.590600000000000000
        Top = 204.472440940000000000
        Width = 222.614173230000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1058#1077#1082#1091#1097#1072#1103' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1103' '#1087#1088#1086#1074#1086#1076#1080#1090#1089#1103)
        ParentFont = False
      end
      object Memo13: TfrxMemoView
        Left = 313.700836220000000000
        Top = 203.338582680000000000
        Width = 240.000000000000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = [fsBold]
        Memo.UTF8W = (
          #1087#1077#1088#1074#1080#1095#1085#1086', '#1087#1086#1074#1090#1086#1088#1085#1086', '#1082#1086#1084#1080#1089#1089#1080#1077#1081)
        ParentFont = False
      end
      object Memo14: TfrxMemoView
        Left = 390.425245670000000000
        Top = 220.724409450000000000
        Width = 103.181119450000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '('#1087#1086#1076#1095#1077#1088#1082#1085#1091#1090#1100')')
        ParentFont = False
      end
      object Memo15: TfrxMemoView
        Left = 75.590600000000000000
        Top = 243.023622050000000000
        Width = 94.866144170000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1059#1095#1077#1073#1085#1099#1081' '#1075#1086#1076)
        ParentFont = False
      end
      object Memo16: TfrxMemoView
        Left = 217.700836220000000000
        Top = 240.000000000000000000
        Width = 76.724409450000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '[frxDBDataset1."YEAR_UCH"]/[<frxDBDataset1."YEAR_UCH">+1]')
        ParentFont = False
        Formats = <
          item
          end
          item
          end>
      end
      object Memo17: TfrxMemoView
        Left = 345.448867720000000000
        Top = 241.133858270000000000
        Width = 66.897642680000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1057#1077#1084#1077#1089#1090#1088)
        ParentFont = False
      end
      object Memo18: TfrxMemoView
        Left = 470.929182680000000000
        Top = 238.110236220000000000
        Width = 111.496062990000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '[frxDBDataset1."SEMESTR_VED"]')
        ParentFont = False
      end
      object Memo19: TfrxMemoView
        Left = 75.590600000000000000
        Top = 274.393700790000000000
        Width = 75.590553620000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1060#1072#1082#1091#1083#1100#1090#1077#1090)
        ParentFont = False
      end
      object Memo20: TfrxMemoView
        Left = 161.763684330000000000
        Top = 268.724409450000000000
        Width = 481.134156060000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        HAlign = haCenter
        Memo.UTF8W = (
          '[frxDBDataset1."FAC1"]')
        ParentFont = False
      end
      object Memo21: TfrxMemoView
        Left = 75.590600000000000000
        Top = 300.472440940000000000
        Width = 38.551181100000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1050#1091#1088#1089)
        ParentFont = False
      end
      object Memo22: TfrxMemoView
        Left = 134.173277170000000000
        Top = 299.338582680000000000
        Width = 20.031496060000000000
        Height = 19.275590550000000000
        Memo.UTF8W = (
          '[(Int((<frxDBDataset1."SEMESTR_VED">+1)/2))]')
      end
      object Memo23: TfrxMemoView
        Left = 194.645710790000000000
        Top = 299.338582680000000000
        Width = 51.779530000000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1075#1088#1091#1087#1087#1072)
        ParentFont = False
      end
      object Memo24: TfrxMemoView
        Left = 283.086662990000000000
        Top = 298.582677170000000000
        Width = 75.968503940000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '[frxDBDataset1."N_GROUP"]')
        ParentFont = False
      end
      object Memo25: TfrxMemoView
        Left = 405.921308660000000000
        Top = 298.582677170000000000
        Width = 144.755910390000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #8470' '#1079#1072#1095#1077#1090#1085#1086#1081' '#1082#1085#1080#1078#1082#1080)
        ParentFont = False
      end
      object Memo26: TfrxMemoView
        Left = 571.842568500000000000
        Top = 297.448818900000000000
        Width = 81.637795280000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '[frxDBDataset1."N_ZACHET"]')
        ParentFont = False
      end
      object Memo27: TfrxMemoView
        Left = 75.590600000000000000
        Top = 339.779530000000000000
        Width = 236.976387720000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1044#1080#1089#1094#1080#1087#1083#1080#1085#1072' ('#1085#1072#1079#1074#1072#1085#1080#1077' '#1087#1088#1072#1082#1090#1080#1082#1080')')
        ParentFont = False
      end
      object Memo28: TfrxMemoView
        Left = 75.590600000000000000
        Top = 400.251968500000000000
        Width = 352.251975830000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1042#1089#1077#1075#1086' '#1095#1072#1089#1086#1074' '#1087#1086' '#1076#1080#1089#1094#1080#1087#1083#1080#1085#1077' ('#1087#1088#1072#1082#1090#1080#1082#1077') '#1074' '#1089#1077#1084#1077#1089#1090#1088#1077)
        ParentFont = False
      end
      object Memo29: TfrxMemoView
        Left = 475.086653230000000000
        Top = 399.496062990000000000
        Width = 142.866141730000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          
            '[frxDBDataset1."CLOCK_PLAN_ALL"][IIF((<frxDBDataset1."YEAR_PLAN"' +
            '> - <frxDBDataset1."SEMESTR_VED">/2) >= 2012,'#39' ('#39'+(FloatToStr(<f' +
            'rxDBDataset1."CLOCK_PLAN">))+'#39' '#1079'.'#1077'.)'#39','#39#39')]')
        ParentFont = False
        Formats = <
          item
          end
          item
          end>
      end
      object Memo30: TfrxMemoView
        Left = 75.590600000000000000
        Top = 428.220472440000000000
        Width = 269.858267720000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1060#1072#1084#1080#1083#1080#1103', '#1080#1085#1080#1094#1080#1072#1083#1099' '#1087#1088#1077#1087#1086#1076#1072#1074#1072#1090#1077#1083#1103' ('#1077#1081')')
        ParentFont = False
      end
      object Memo32: TfrxMemoView
        Left = 75.590600000000000000
        Top = 476.976377950000000000
        Width = 251.338590000000000000
        Height = 21.165354330000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1060#1072#1084#1080#1083#1080#1103', '#1080#1085#1080#1094#1080#1072#1083#1099' '#1086#1073#1091#1095#1072#1102#1097#1077#1075#1086#1089#1103)
        ParentFont = False
      end
      object Memo33: TfrxMemoView
        Left = 339.401623620000000000
        Top = 476.220472440000000000
        Width = 283.086780160000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          
            '[frxDBDataset1."FAM"] [frxDBDataset1."NAME"] [frxDBDataset1."OTC' +
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
      object Memo34: TfrxMemoView
        Left = 75.590600000000000000
        Top = 506.834645670000000000
        Width = 179.149616060000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1044#1072#1090#1072' '#1074#1099#1076#1072#1095#1080' '#1074#1077#1076#1086#1084#1086#1089#1090#1080)
        ParentFont = False
      end
      object Memo35: TfrxMemoView
        Left = 379.086662990000000000
        Top = 503.055118110000000000
        Width = 164.031496060000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '[frxDBDataset1."D_VED"]')
        ParentFont = False
      end
      object Memo36: TfrxMemoView
        Left = 75.590600000000000000
        Top = 536.692913390000000000
        Width = 210.897645120000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1042#1077#1076#1086#1084#1086#1089#1090#1100' '#1076#1077#1081#1089#1090#1074#1080#1090#1077#1083#1100#1085#1072' '#1087#1086)
        ParentFont = False
      end
      object Memo37: TfrxMemoView
        Left = 379.086662990000000000
        Top = 534.803149610000000000
        Width = 76.724409450000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          
            '[IIF(<frxDBDataset1."END_D_EXAM"> <> null,<frxDBDataset1."END_D_' +
            'EXAM">,'#39'10 '#1076#1085#1077#1081#39')]')
        ParentFont = False
      end
      object Memo38: TfrxMemoView
        Left = 75.590600000000000000
        Top = 562.393700790000000000
        Width = 124.724253230000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1044#1077#1082#1072#1085' '#1092#1072#1082#1091#1083#1100#1090#1077#1090#1072)
        ParentFont = False
      end
      object Memo39: TfrxMemoView
        Left = 521.196899210000000000
        Top = 561.637795280000000000
        Width = 140.976419450000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '[frxDBDataset1."DEAN"]')
        ParentFont = False
      end
      object Memo40: TfrxMemoView
        Left = 290.645718110000000000
        Top = 580.913385830000000000
        Width = 72.944886770000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '('#1087#1086#1076#1087#1080#1089#1100')')
        ParentFont = False
      end
      object Memo41: TfrxMemoView
        Left = 518.173277170000000000
        Top = 581.669291340000000000
        Width = 154.204731730000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          '('#1080#1085#1080#1094#1080#1072#1083#1099', '#1092#1072#1084#1080#1083#1080#1103')')
        ParentFont = False
      end
      object Memo42: TfrxMemoView
        Left = 302.362251100000000000
        Top = 601.700789840000000000
        Width = 40.062997010000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1052'.'#1055'.')
        ParentFont = False
      end
      object Memo43: TfrxMemoView
        Left = 75.590600000000000000
        Top = 625.889763780000000000
        Width = 66.141732280000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1054#1090#1084#1077#1090#1082#1072)
        ParentFont = False
      end
      object Memo44: TfrxMemoView
        Left = 351.118159060000000000
        Top = 627.779527560000000000
        Width = 79.748031500000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1044#1072#1090#1072' '#1089#1076#1072#1095#1080)
        ParentFont = False
      end
      object Memo45: TfrxMemoView
        Left = 75.590600000000000000
        Top = 660.661417320000000000
        Width = 188.598442280000000000
        Height = 19.275590550000000000
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Memo.UTF8W = (
          #1055#1086#1076#1087#1080#1089#1100' '#1087#1088#1077#1087#1086#1076#1072#1074#1072#1090#1077#1083#1103' ('#1077#1081')')
        ParentFont = False
      end
      object Line1: TfrxLineView
        Left = 160.252017320000000000
        Top = 286.866141730000000000
        Width = 484.913385830000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line2: TfrxLineView
        Left = 260.031544880000000000
        Top = 521.196850390000000000
        Width = 331.086614170000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line3: TfrxLineView
        Left = 467.149655120000000000
        Top = 580.913385830000000000
        Width = 223.748031500000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line4: TfrxLineView
        Left = 551.811072440000000000
        Top = 316.724409450000000000
        Width = 139.086614170000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line5: TfrxLineView
        Left = 144.755954330000000000
        Top = 642.141732280000000000
        Width = 185.196850390000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line6: TfrxLineView
        Left = 382.866190550000000000
        Top = 167.055118110000000000
        Width = 116.031496060000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line7: TfrxLineView
        Left = 75.590600000000000000
        Top = 375.307086610000000000
        Width = 622.866141730000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line8: TfrxLineView
        Left = 374.929182680000000000
        Top = 142.866141730000000000
        Width = 123.968503940000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line9: TfrxLineView
        Left = 75.590600000000000000
        Top = 393.448818900000000000
        Width = 622.866144170000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line12: TfrxLineView
        Left = 290.645718110000000000
        Top = 554.078740160000000000
        Width = 300.472440940000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line14: TfrxLineView
        Left = 267.590600000000000000
        Top = 316.724409450000000000
        Width = 100.913385830000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line15: TfrxLineView
        Left = 121.700836220000000000
        Top = 320.503939450000000000
        Width = 46.866141730000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line16: TfrxLineView
        Left = 182.929182680000000000
        Top = 261.921262280000000000
        Width = 147.023622050000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line18: TfrxLineView
        Left = 339.401623620000000000
        Top = 494.362204720000000000
        Width = 284.976377950000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line24: TfrxLineView
        Left = 79.370130000000000000
        Top = 463.748031500000000000
        Width = 617.196850390000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line30: TfrxLineView
        Left = 452.031544880000000000
        Top = 642.141732280000000000
        Width = 208.251968500000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line40: TfrxLineView
        Left = 428.976426770000000000
        Top = 261.165356770000000000
        Width = 100.913385830000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line61: TfrxLineView
        Left = 372.283515830000000000
        Top = 445.606299210000000000
        Width = 325.417322830000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line80: TfrxLineView
        Left = 321.259891340000000000
        Top = 357.165354330000000000
        Width = 377.196850390000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line182: TfrxLineView
        Left = 290.645718110000000000
        Top = 192.000000000000000000
        Width = 254.362204720000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line192: TfrxLineView
        Left = 445.228395280000000000
        Top = 417.637795280000000000
        Width = 184.440979060000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line203: TfrxLineView
        Left = 267.590600000000000000
        Top = 676.913385830000000000
        Width = 261.921259840000000000
        Color = clBlack
        Frame.Typ = [ftTop]
      end
      object Line11: TfrxLineView
        Left = 222.992270000000000000
        Top = 582.047620000000000000
        Width = 223.748031500000000000
        Color = clBlack
        Frame.Typ = [ftTop]
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
    PrintOptions.ShowDialog = False
    ReportOptions.CreateDate = 42783.647229143520000000
    ReportOptions.LastChange = 42783.647229143520000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 136
    Top = 64
    Datasets = <
      item
        DataSet = frxDBDataset3
        DataSetName = 'frxDBDataset3'
      end>
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
      Duplex = dmVertical
      object ReportTitle1: TfrxReportTitle
        FillType = ftBrush
        Height = 472.441250000000000000
        Top = 16.000000000000000000
        Width = 718.110700000000000000
        object Rich1: TfrxRichView
          Left = 75.590600000000000000
          Top = 343.937230000000000000
          Width = 619.842920000000000000
          Height = 56.692950000000000000
          GapX = 2.000000000000000000
          GapY = 1.000000000000000000
          RichEdit = {
            7B5C727466315C616E73695C616E7369637067313235315C64656666305C6E6F
            7569636F6D7061745C6465666C616E67313034397B5C666F6E7474626C7B5C66
            305C666E696C5C66636861727365743230342054696D6573204E657720526F6D
            616E204359523B7D7B5C66315C666E696C5C6663686172736574302054696D65
            73204E657720526F6D616E3B7D7B5C66325C666E696C5C666368617273657432
            3034205461686F6D613B7D7D0D0A7B5C2A5C67656E657261746F722052696368
            656432302031302E302E31363239397D5C766965776B696E64345C756331200D
            0A5C706172645C6C69333534305C66305C66733234205B667278444244617461
            7365745C66315C6C616E673130333320335C66305C6C616E6731303439202E22
            4E414D455F4F424A454354225D5C66325C667331365C7061720D0A7D0D0A00}
        end
        object Memo7: TfrxMemoView
          Left = 267.968542990000000000
          Width = 241.889771100000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1059#1063#1056#1045#1046#1044#1045#1053#1048#1045' '#1054#1041#1056#1040#1047#1054#1042#1040#1053#1048#1071)
          ParentFont = False
        end
        object Memo8: TfrxMemoView
          Left = 76.724453390000000000
          Top = 20.031496060000000000
          Width = 628.913385830000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #171#1041#1045#1051#1054#1056#1059#1057#1057#1050#1048#1049' '#1043#1054#1057#1059#1044#1040#1056#1057#1058#1042#1045#1053#1053#1067#1049' '#1059#1053#1048#1042#1045#1056#1057#1048#1058#1045#1058' '#1060#1048#1047#1048#1063#1045#1057#1050#1054#1049' '#1050#1059#1051#1068#1058#1059#1056#1067#187)
          ParentFont = False
        end
        object Memo9: TfrxMemoView
          Left = 126.236247320000000000
          Top = 69.165351890000000000
          Width = 478.866141730000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            
              #1047#1040#1063#1045#1058#1053#1054'-'#1069#1050#1047#1040#1052#1045#1053#1040#1062#1048#1054#1053#1053#1040#1071' '#1042#1045#1044#1054#1052#1054#1057#1058#1068' '#8470' [IIF(<frxDBDataset3."N_FAC">' +
              '=3,'#39'07/03-'#39','#39#39')][<frxDBDataset3."N_VEDOMOST">] ')
          ParentFont = False
          Formats = <
            item
            end
            item
            end>
        end
        object Memo10: TfrxMemoView
          Left = 259.653601890000000000
          Top = 92.976377950000000000
          Width = 303.118120000000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            #1090#1077#1082#1091#1097#1077#1081' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1080' '#1074#1085#1077' '#1091#1095#1077#1073#1085#1086#1081' '#1075#1088#1091#1087#1087#1099)
          ParentFont = False
        end
        object Memo11: TfrxMemoView
          Left = 75.590600000000000000
          Top = 125.858267720000000000
          Width = 286.866149060000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1060#1086#1088#1084#1072' '#1087#1086#1083#1091#1095#1077#1085#1080#1103' '#1074#1099#1089#1096#1077#1075#1086' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103)
          ParentFont = False
        end
        object Memo12: TfrxMemoView
          Left = 75.590600000000000000
          Top = 149.669291340000000000
          Width = 292.535437950000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1057#1090#1091#1087#1077#1085#1100' '#1087#1086#1083#1091#1095#1077#1085#1080#1103' '#1074#1099#1089#1096#1077#1075#1086' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103)
          ParentFont = False
        end
        object Memo13: TfrxMemoView
          Left = 75.590600000000000000
          Top = 174.614173230000000000
          Width = 203.338594880000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1060#1086#1088#1084#1072' '#1090#1077#1082#1091#1097#1077#1081' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1080)
          ParentFont = False
        end
        object Memo15: TfrxMemoView
          Left = 75.590600000000000000
          Top = 249.448823780000000000
          Width = 102.425204170000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1059#1095#1077#1073#1085#1099#1081' '#1075#1086#1076)
          ParentFont = False
        end
        object Memo16: TfrxMemoView
          Left = 75.590600000000000000
          Top = 276.283469450000000000
          Width = 83.149613620000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1060#1072#1082#1091#1083#1100#1090#1077#1090)
          ParentFont = False
        end
        object Memo17: TfrxMemoView
          Left = 356.787457720000000000
          Top = 249.448823780000000000
          Width = 66.338582680000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1057#1077#1084#1077#1089#1090#1088)
          ParentFont = False
        end
        object Memo18: TfrxMemoView
          Left = 75.590600000000000000
          Top = 306.897642680000000000
          Width = 38.551181100000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1050#1091#1088#1089' ')
          ParentFont = False
        end
        object Memo19: TfrxMemoView
          Left = 240.000070790000000000
          Top = 306.897642680000000000
          Width = 55.559060000000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1075#1088#1091#1087#1087#1072)
          ParentFont = False
        end
        object Memo22: TfrxMemoView
          Left = 75.590600000000000000
          Top = 407.811028500000000000
          Width = 480.755995830000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            
              #1042#1089#1077#1075#1086' '#1095#1072#1089#1086#1074' ('#1079#1072#1095#1077#1090#1085#1099#1093' '#1077#1076#1080#1085#1080#1094') '#1087#1086' '#1076#1080#1089#1094#1080#1087#1083#1080#1085#1077' ('#1087#1088#1072#1082#1090#1080#1082#1077') '#1074' '#1089#1077#1084#1077#1089#1090#1088 +
              #1077)
          ParentFont = False
        end
        object Memo23: TfrxMemoView
          Left = 75.590600000000000000
          Top = 435.779532440000000000
          Width = 269.858267720000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1060#1072#1084#1080#1083#1080#1103', '#1080#1085#1080#1094#1080#1072#1083#1099' '#1087#1088#1077#1087#1086#1076#1072#1074#1072#1090#1077#1083#1103' ('#1077#1081') ')
          ParentFont = False
        end
        object Memo27: TfrxMemoView
          Left = 196.535584410000000000
          Top = 276.283469450000000000
          Width = 480.000310000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[<frxDBDataset3."FAC1">]')
          ParentFont = False
        end
        object Memo28: TfrxMemoView
          Left = 83.149635590000000000
          Top = 45.354360000000000000
          Width = 642.520100000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold, fsItalic, fsUnderline]
          Memo.UTF8W = (
            
              #1051#1080#1082#1074#1080#1076#1072#1094#1080#1103' '#1088#1072#1089#1093#1086#1078#1076#1077#1085#1080#1103' '#1089' '#1091#1095#1077#1073#1085#1099#1084' '#1087#1083#1072#1085#1086#1084' '#1079#1072' [frxDBDataset3."KURS"' +
              '] '#1082#1091#1088#1089' [IIF(<frxDBDataset3."VID_EDU_PLAN">=1,'#39#1079#1072#1086#1095#1085#1086#1081#39','#39#1076#1085#1077#1074#1085#1086#1081#39 +
              ')] '#1092#1086#1088#1084#1099' '#1087#1086#1083#1091#1095#1077#1085#1080#1103' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103)
          ParentFont = False
          Formats = <
            item
            end
            item
            end>
        end
        object Memo29: TfrxMemoView
          Left = 430.866444410000000000
          Top = 124.724490000000000000
          Width = 94.488250000000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            '[IIF(<frxDBDataset3."VID_EDU_PLAN">=0,'#39#1076#1085#1077#1074#1085#1072#1103#39','#39#1079#1072#1086#1095#1085#1072#1103#39')] ')
          ParentFont = False
        end
        object Memo30: TfrxMemoView
          Left = 170.078820710000000000
          Top = 306.141930000000000000
          Width = 34.015770000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[(Int((<frxDBDataset3."SEMESTR_VED">+1)/2))]')
          ParentFont = False
        end
        object Memo32: TfrxMemoView
          Left = 234.330767240000000000
          Top = 249.448980000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[<frxDBDataset3."YEAR_PLAN">]/[<frxDBDataset3."YEAR_PLAN">+1]')
          ParentFont = False
          Formats = <
            item
            end
            item
            end>
        end
        object Memo33: TfrxMemoView
          Left = 411.968794410000000000
          Top = 174.614173230000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            
              '[IIF(<frxDBDataset3."ZACH_EXAM">=1,'#39#1079#1072#1095#1077#1090#39',IIF(<frxDBDataset3."Z' +
              'ACH_EXAM">=2,'#39#1101#1082#1079#1072#1084#1077#1085#39',IIF(<frxDBDataset3."ZACH_EXAM">=3,'#39#1076#1080#1092'.'#1079#1072 +
              #1095#1077#1090#39','#39#39')))]')
          ParentFont = False
        end
        object Memo35: TfrxMemoView
          Left = 563.149994410000000000
          Top = 408.189240000000000000
          Width = 124.724490000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          HAlign = haCenter
          Memo.UTF8W = (
            
              '[frxDBDataset3."CLOCK_PLAN_ALL"][IIF((<frxDBDataset3."YEAR_PLAN"' +
              '> - <frxDBDataset3."SEMESTR_VED">/2) >= 2012,'#39' ('#39'+(FloatToStr(<f' +
              'rxDBDataset3."CLOCK_PLAN">))+'#39' '#1079'.'#1077'.)'#39','#39#39')]')
          ParentFont = False
          Formats = <
            item
            end
            item
            end>
        end
        object Line1: TfrxLineView
          Left = 194.267787320000000000
          Top = 298.204726850000000000
          Width = 484.913385830000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line5: TfrxLineView
          Left = 440.196896770000000000
          Top = 268.724416770000000000
          Width = 70.677145830000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line7: TfrxLineView
          Left = 155.716606220000000000
          Top = 328.062999450000000000
          Width = 46.866141730000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line10: TfrxLineView
          Left = 301.606370000000000000
          Top = 328.062999450000000000
          Width = 100.913385830000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line12: TfrxLineView
          Left = 368.503985830000000000
          Top = 453.165359210000000000
          Width = 327.685039370000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line15: TfrxLineView
          Left = 382.866214960000000000
          Top = 167.055118110000000000
          Width = 116.031496060000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line16: TfrxLineView
          Left = 412.724482680000000000
          Top = 142.866141730000000000
          Width = 123.968503940000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line17: TfrxLineView
          Left = 216.944952680000000000
          Top = 269.480322280000000000
          Width = 128.125972050000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line18: TfrxLineView
          Left = 79.370130000000000000
          Top = 382.866146610000000000
          Width = 620.598425200000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line19: TfrxLineView
          Left = 328.441018110000000000
          Top = 192.000000000000000000
          Width = 254.362204720000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line20: TfrxLineView
          Left = 309.921301340000000000
          Top = 364.724414330000000000
          Width = 390.047253860000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line23: TfrxLineView
          Left = 558.614295280000000000
          Top = 425.196855280000000000
          Width = 131.527559060000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Memo38: TfrxMemoView
          Left = 413.480388190000000000
          Top = 149.669291340000000000
          Width = 59.338587560000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            #1087#1077#1088#1074#1072#1103)
          ParentFont = False
        end
        object Memo39: TfrxMemoView
          Left = 75.590600000000000000
          Top = 343.937230000000000000
          Width = 234.330860000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          HAlign = haCenter
          Memo.UTF8W = (
            #1044#1080#1089#1094#1080#1087#1083#1080#1085#1072' ('#1085#1072#1079#1074#1072#1085#1080#1077' '#1087#1088#1072#1082#1090#1080#1082#1080')')
          ParentFont = False
        end
        object Line3: TfrxLineView
          Left = 79.370130000000000000
          Top = 400.630180000000000000
          Width = 620.598425200000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Memo51: TfrxMemoView
          Left = 442.205010000000000000
          Top = 249.448980000000000000
          Width = 64.252010000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset3."SEMESTR_VED"]')
          ParentFont = False
        end
        object Memo52: TfrxMemoView
          Left = 325.039580000000000000
          Top = 306.141930000000000000
          Width = 48.000000000000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[<frxDBDataset3."N_GROUP">]')
          ParentFont = False
        end
        object Memo53: TfrxMemoView
          Left = 385.512060000000000000
          Top = 434.645950000000000000
          Width = 180.283550000000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset3."FIO_EXAM"]')
          ParentFont = False
        end
        object Memo2: TfrxMemoView
          Left = 75.590600000000000000
          Top = 205.228478260000000000
          Width = 222.614173230000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1058#1077#1082#1091#1097#1072#1103' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1103' '#1087#1088#1086#1074#1086#1076#1080#1090#1089#1103)
          ParentFont = False
        end
        object Memo20: TfrxMemoView
          Left = 313.700836220000000000
          Top = 204.094620000000000000
          Width = 240.000000000000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            #1087#1077#1088#1074#1080#1095#1085#1086', '#1087#1086#1074#1090#1086#1088#1085#1086', '#1082#1086#1084#1080#1089#1089#1080#1077#1081)
          ParentFont = False
        end
        object Memo24: TfrxMemoView
          Left = 390.425245670000000000
          Top = 221.480446770000000000
          Width = 106.960649450000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '('#1087#1086#1076#1095#1077#1088#1082#1085#1091#1090#1100')')
          ParentFont = False
        end
      end
      object Header2: TfrxHeader
        FillType = ftBrush
        Height = 147.401670000000000000
        Top = 548.000000000000000000
        Width = 718.110700000000000000
        object Memo1: TfrxMemoView
          Left = 26.456710000000000000
          Width = 151.181126770000000000
          Height = 147.401587010000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #1060#1072#1084#1080#1083#1080#1103', '#1080#1085#1080#1094#1080#1072#1083#1099' '#1086#1073#1091#1095#1072#1102#1097#1077#1075#1086#1089#1103)
          ParentFont = False
        end
        object Memo21: TfrxMemoView
          Left = 177.637910000000000000
          Width = 64.251936770000000000
          Height = 147.401587010000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #8470' '#1079#1072#1095#1077#1090#1085#1086#1081' '#1082#1085#1080#1078#1082#1080)
          ParentFont = False
        end
        object Memo25: TfrxMemoView
          Left = 241.889920000000000000
          Width = 124.724416770000000000
          Height = 128.503949210000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #1054#1090#1084#1077#1090#1082#1072' '#1087#1086' '#1091#1095#1077#1073#1085#1086#1081' '#1076#1080#1089#1094#1080#1087#1083#1080#1085#1077' '#171'[frxDBDataset3."NAME_OBJECT_1"]'#187)
          ParentFont = False
        end
        object Memo26: TfrxMemoView
          Left = 366.614410000000000000
          Width = 124.724416770000000000
          Height = 128.503949210000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #1054#1090#1084#1077#1090#1082#1072' '#1087#1086' '#1091#1095#1077#1073#1085#1086#1081' '#1076#1080#1089#1094#1080#1087#1083#1080#1085#1077' '#171'[frxDBDataset3."NAME_OBJECT_2"]'#187)
          ParentFont = False
        end
        object Memo31: TfrxMemoView
          Left = 491.338900000000000000
          Width = 105.826766770000000000
          Height = 147.401587010000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #1054#1090#1084#1077#1090#1082#1072' '#1087#1086' '#1048#1052' '#1084#1086#1076#1091#1083#1102' [frxDBDataset3."NAME_OBJECT"]')
          ParentFont = False
        end
        object Memo34: TfrxMemoView
          Left = 597.165740000000000000
          Width = 120.944886770000000000
          Height = 147.401587010000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #1055#1086#1076#1087#1080#1089#1100' '#1087#1088#1077#1087#1086#1076#1072#1074#1072#1090#1077#1083#1103'('#1077#1081') '#1080' '#1076#1072#1090#1072)
          ParentFont = False
        end
        object Memo40: TfrxMemoView
          Left = 241.889920000000000000
          Top = 128.504020000000000000
          Width = 124.724490000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            '[Round(<frxDBDataset3."PERC_SUB_PLAN">*10)/10]')
          ParentFont = False
        end
        object Memo41: TfrxMemoView
          Left = 366.614410000000000000
          Top = 128.504020000000000000
          Width = 124.724490000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            '[Round(<frxDBDataset3."PERC_SUB_PLAN_1">*10)/10]')
          ParentFont = False
        end
        object Memo42: TfrxMemoView
          Width = 26.456710000000000000
          Height = 147.401670000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #8470#1087'/'#1087)
          ParentFont = False
        end
      end
      object MasterData2: TfrxMasterData
        FillType = ftBrush
        Height = 18.897637800000000000
        Top = 716.000000000000000000
        Width = 718.110700000000000000
        DataSet = Ved_ReportForm.frxDBDataset3
        DataSetName = 'frxDBDataset3'
        RowCount = 0
        object Memo36: TfrxMemoView
          Left = 26.456710000000000000
          Width = 151.181200000000000000
          Height = 18.897650000000000000
          DataSet = Ved_ReportForm.frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            
              '[frxDBDataset3."FAM"] [COPY(<frxDBDataset3."NAME">, 1, 1)].[COPY' +
              '(<frxDBDataset3."OTCH">, 1, 1)].')
          ParentFont = False
          Formats = <
            item
            end
            item
            end
            item
            end>
        end
        object Memo37: TfrxMemoView
          Left = 177.637910000000000000
          Width = 64.252010000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            '[frxDBDataset3."N_ZACHET"]')
          ParentFont = False
        end
        object Memo44: TfrxMemoView
          Left = 241.889920000000000000
          Width = 124.724490000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo45: TfrxMemoView
          Left = 366.614410000000000000
          Width = 124.724490000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo46: TfrxMemoView
          Left = 491.338900000000000000
          Width = 105.826840000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo47: TfrxMemoView
          Left = 597.165740000000000000
          Width = 120.944960000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo3: TfrxMemoView
          Width = 26.456710000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            '[Line]')
          ParentFont = False
        end
      end
      object Footer1: TfrxFooter
        FillType = ftBrush
        Height = 152.692898740000000000
        Top = 756.000000000000000000
        Width = 718.110700000000000000
        object Memo4: TfrxMemoView
          Left = 75.590600000000000000
          Top = 26.078771890000000000
          Width = 168.188976380000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1044#1072#1090#1072' '#1074#1099#1076#1072#1095#1080' '#1074#1077#1076#1086#1084#1086#1089#1090#1080)
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          Left = 357.165395830000000000
          Top = 24.944903860000000000
          Width = 86.929155830000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset3."D_VED"]')
          ParentFont = False
        end
        object Memo6: TfrxMemoView
          Left = 75.590600000000000000
          Top = 55.937029840000000000
          Width = 210.897645120000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1042#1077#1076#1086#1084#1086#1089#1090#1100' '#1076#1077#1081#1089#1090#1074#1080#1090#1077#1083#1100#1085#1072' '#1087#1086)
          ParentFont = False
        end
        object Memo14: TfrxMemoView
          Left = 357.165395830000000000
          Top = 49.889785750000000000
          Width = 87.685061340000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset3."END_D_EXAM"]')
          ParentFont = False
        end
        object Memo62: TfrxMemoView
          Left = 75.590600000000000000
          Top = 86.551203070000000000
          Width = 136.063006770000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1044#1077#1082#1072#1085' '#1092#1072#1082#1091#1083#1100#1090#1077#1090#1072)
          ParentFont = False
        end
        object Memo63: TfrxMemoView
          Left = 481.889802830000000000
          Top = 84.661439290000000000
          Width = 140.976419450000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset3."DEAN"]')
          ParentFont = False
        end
        object Memo64: TfrxMemoView
          Left = 274.015796850000000000
          Top = 105.826793620000000000
          Width = 75.590556060000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '('#1087#1086#1076#1087#1080#1089#1100')')
          ParentFont = False
        end
        object Memo65: TfrxMemoView
          Left = 482.645718110000000000
          Top = 104.692935350000000000
          Width = 157.228356220000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '('#1080#1085#1080#1094#1080#1072#1083#1099', '#1092#1072#1084#1080#1083#1080#1103')')
          ParentFont = False
        end
        object Memo66: TfrxMemoView
          Left = 286.866188110000000000
          Top = 125.102384170000000000
          Width = 45.732290790000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1052'. '#1055'.')
          ParentFont = False
        end
        object Line24: TfrxLineView
          Left = 260.031544880000000000
          Top = 44.220494410000000000
          Width = 277.417322830000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line25: TfrxLineView
          Left = 213.921308660000000000
          Top = 103.937029840000000000
          Width = 185.196850390000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line28: TfrxLineView
          Left = 428.976426770000000000
          Top = 103.937029840000000000
          Width = 254.362204720000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line29: TfrxLineView
          Left = 290.645718110000000000
          Top = 69.165376300000000000
          Width = 246.803149610000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
      end
    end
  end
  object FDQuery1: TFDQuery
    Active = True
    Connection = DataModule1.FDConnection1
    SQL.Strings = (
      
        'select  vedomost_likvid.kurs, vedomost_likvid.N_FAC, vedomost_li' +
        'kvid.N_VEDOMOST,  vedomost_likvid.SEMESTR_VED,  vedomost_likvid.' +
        'FIO_EXAM,  vedomost_likvid.END_D_EXAM,  vedomost_likvid.D_VED, C' +
        'AST(vedomost_likvid.N_GROUP AS varchar(3)) as N_GROUP, vedomost_' +
        'likvid.year_uch,'
      
        'EDU_PLAN.VID_EDU_PLAN, EDU_PLAN.CLOCK_PLAN_ALL, EDU_PLAN.CLOCK_P' +
        'LAN, edu_plan.zach_exam, edu_plan.year_plan,'
      'a.NAME_OBJECT,'
      
        'PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH, CAST(PEOPLE.N_ZACHET AS va' +
        'rchar(6)) as N_ZACHET,'
      'FACULTY.FAC1, FACULTY.DEAN'
      'from vedomost_likvid, EDU_PLAN'
      ', OBJECT_PLAN a'
      ', PEOPLE, FACULTY'
      'where vedomost_likvid.N_PLAN = EDU_PLAN.N_PLAN'
      'and EDU_PLAN.N_OBJECT = a.N_OBJECT'
      'and vedomost_likvid.nomer = PEOPLE.NOMER'
      'and EDU_PLAN.N_FAC = FACULTY.N_FAC'
      'and vedomost_likvid.N_VED = :N_VED')
    Left = 296
    Top = 56
    ParamData = <
      item
        Name = 'N_VED'
        DataType = ftInteger
        ParamType = ptInput
      end>
    object FDQuery1N_FAC: TSmallintField
      FieldName = 'N_FAC'
      Origin = 'N_FAC'
    end
    object FDQuery1N_VEDOMOST: TSmallintField
      FieldName = 'N_VEDOMOST'
      Origin = 'N_VEDOMOST'
    end
    object FDQuery1SEMESTR_VED: TSmallintField
      FieldName = 'SEMESTR_VED'
      Origin = 'SEMESTR_VED'
    end
    object FDQuery1FIO_EXAM: TStringField
      FieldName = 'FIO_EXAM'
      Origin = 'FIO_EXAM'
      Size = 40
    end
    object FDQuery1END_D_EXAM: TSQLTimeStampField
      FieldName = 'END_D_EXAM'
      Origin = 'END_D_EXAM'
    end
    object FDQuery1D_VED: TSQLTimeStampField
      FieldName = 'D_VED'
      Origin = 'D_VED'
    end
    object FDQuery1N_GROUP: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'N_GROUP'
      Origin = 'N_GROUP'
      ProviderFlags = []
      ReadOnly = True
      Size = 3
    end
    object FDQuery1YEAR_UCH: TSmallintField
      FieldName = 'YEAR_UCH'
      Origin = 'YEAR_UCH'
    end
    object FDQuery1VID_EDU_PLAN: TSmallintField
      AutoGenerateValue = arDefault
      FieldName = 'VID_EDU_PLAN'
      Origin = 'VID_EDU_PLAN'
      ProviderFlags = []
      ReadOnly = True
    end
    object FDQuery1CLOCK_PLAN_ALL: TSmallintField
      AutoGenerateValue = arDefault
      FieldName = 'CLOCK_PLAN_ALL'
      Origin = 'CLOCK_PLAN_ALL'
      ProviderFlags = []
      ReadOnly = True
    end
    object FDQuery1CLOCK_PLAN: TFloatField
      AutoGenerateValue = arDefault
      FieldName = 'CLOCK_PLAN'
      Origin = 'CLOCK_PLAN'
      ProviderFlags = []
      ReadOnly = True
    end
    object FDQuery1ZACH_EXAM: TSmallintField
      AutoGenerateValue = arDefault
      FieldName = 'ZACH_EXAM'
      Origin = 'ZACH_EXAM'
      ProviderFlags = []
      ReadOnly = True
    end
    object FDQuery1YEAR_PLAN: TSmallintField
      AutoGenerateValue = arDefault
      FieldName = 'YEAR_PLAN'
      Origin = 'YEAR_PLAN'
      ProviderFlags = []
      ReadOnly = True
    end
    object FDQuery1NAME_OBJECT: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'NAME_OBJECT'
      Origin = 'NAME_OBJECT'
      ProviderFlags = []
      ReadOnly = True
      Size = 250
    end
    object FDQuery1FAM: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'FAM'
      Origin = 'FAM'
      ProviderFlags = []
      ReadOnly = True
      Size = 30
    end
    object FDQuery1NAME: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'NAME'
      Origin = 'NAME'
      ProviderFlags = []
      ReadOnly = True
      Size = 30
    end
    object FDQuery1OTCH: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'OTCH'
      Origin = 'OTCH'
      ProviderFlags = []
      ReadOnly = True
      Size = 30
    end
    object FDQuery1N_ZACHET: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'N_ZACHET'
      Origin = 'N_ZACHET'
      ProviderFlags = []
      ReadOnly = True
      Size = 6
    end
    object FDQuery1FAC1: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'FAC1'
      Origin = 'FAC1'
      ProviderFlags = []
      ReadOnly = True
    end
    object FDQuery1KURS: TSmallintField
      FieldName = 'KURS'
      Origin = 'KURS'
    end
    object FDQuery1DEAN: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'DEAN'
      Origin = 'DEAN'
      ProviderFlags = []
      ReadOnly = True
      Size = 30
    end
  end
  object FDQuery3: TFDQuery
    Active = True
    Connection = DataModule1.FDConnection1
    SQL.Strings = (
      
        'select   vedomost_likvid.kurs, vedomost_likvid.N_FAC, vedomost_l' +
        'ikvid.N_VEDOMOST,  vedomost_likvid.SEMESTR_VED,  vedomost_likvid' +
        '.FIO_EXAM,  vedomost_likvid.END_D_EXAM,  vedomost_likvid.D_VED, ' +
        'CAST(vedomost_likvid.N_GROUP AS varchar(3)) as N_GROUP, vedomost' +
        '_likvid.year_uch,'
      
        'EDU_PLAN.VID_EDU_PLAN, EDU_PLAN.CLOCK_PLAN_ALL, EDU_PLAN.CLOCK_P' +
        'LAN, edu_plan.zach_exam, edu_plan.year_plan,'
      'a.NAME_OBJECT,'
      'y.PERC_SUB_PLAN, b.NAME_OBJECT,'
      'z.PERC_SUB_PLAN, c.NAME_OBJECT,'
      
        'PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH, CAST(PEOPLE.N_ZACHET AS va' +
        'rchar(6)) as N_ZACHET,'
      'FACULTY.FAC1, FACULTY.DEAN'
      'from vedomost_likvid, EDU_PLAN'
      ', OBJECT_PLAN a'
      ', SUB_EDU_PLAN y, OBJECT_PLAN b, SUB_EDU_PLAN z, OBJECT_PLAN c'
      ', PEOPLE, FACULTY'
      'where vedomost_likvid.N_PLAN = EDU_PLAN.N_PLAN'
      'and EDU_PLAN.N_OBJECT = a.N_OBJECT'
      'and EDU_PLAN.N_PLAN = y.N_PLAN_PARENT'
      'and EDU_PLAN.N_PLAN = z.N_PLAN_PARENT'
      'and y.N_OBJECT = b.N_OBJECT'
      'and z.N_OBJECT = c.N_OBJECT'
      'and vedomost_likvid.nomer = PEOPLE.NOMER'
      'and EDU_PLAN.N_FAC = FACULTY.N_FAC'
      'and y.N_PLAN <> z.N_PLAN'
      'and vedomost_likvid.N_VED = :N_VED')
    Left = 440
    Top = 56
    ParamData = <
      item
        Name = 'N_VED'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
      end>
    object FDQuery3N_FAC: TSmallintField
      FieldName = 'N_FAC'
      Origin = 'N_FAC'
    end
    object FDQuery3N_VEDOMOST: TSmallintField
      FieldName = 'N_VEDOMOST'
      Origin = 'N_VEDOMOST'
    end
    object FDQuery3SEMESTR_VED: TSmallintField
      FieldName = 'SEMESTR_VED'
      Origin = 'SEMESTR_VED'
    end
    object FDQuery3FIO_EXAM: TStringField
      FieldName = 'FIO_EXAM'
      Origin = 'FIO_EXAM'
      Size = 40
    end
    object FDQuery3END_D_EXAM: TSQLTimeStampField
      FieldName = 'END_D_EXAM'
      Origin = 'END_D_EXAM'
    end
    object FDQuery3D_VED: TSQLTimeStampField
      FieldName = 'D_VED'
      Origin = 'D_VED'
    end
    object FDQuery3N_GROUP: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'N_GROUP'
      Origin = 'N_GROUP'
      ProviderFlags = []
      ReadOnly = True
      Size = 3
    end
    object FDQuery3YEAR_UCH: TSmallintField
      FieldName = 'YEAR_UCH'
      Origin = 'YEAR_UCH'
    end
    object FDQuery3VID_EDU_PLAN: TSmallintField
      AutoGenerateValue = arDefault
      FieldName = 'VID_EDU_PLAN'
      Origin = 'VID_EDU_PLAN'
      ProviderFlags = []
      ReadOnly = True
    end
    object FDQuery3CLOCK_PLAN_ALL: TSmallintField
      AutoGenerateValue = arDefault
      FieldName = 'CLOCK_PLAN_ALL'
      Origin = 'CLOCK_PLAN_ALL'
      ProviderFlags = []
      ReadOnly = True
    end
    object FDQuery3CLOCK_PLAN: TFloatField
      AutoGenerateValue = arDefault
      FieldName = 'CLOCK_PLAN'
      Origin = 'CLOCK_PLAN'
      ProviderFlags = []
      ReadOnly = True
    end
    object FDQuery3ZACH_EXAM: TSmallintField
      AutoGenerateValue = arDefault
      FieldName = 'ZACH_EXAM'
      Origin = 'ZACH_EXAM'
      ProviderFlags = []
      ReadOnly = True
    end
    object FDQuery3YEAR_PLAN: TSmallintField
      AutoGenerateValue = arDefault
      FieldName = 'YEAR_PLAN'
      Origin = 'YEAR_PLAN'
      ProviderFlags = []
      ReadOnly = True
    end
    object FDQuery3NAME_OBJECT: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'NAME_OBJECT'
      Origin = 'NAME_OBJECT'
      ProviderFlags = []
      ReadOnly = True
      Size = 250
    end
    object FDQuery3PERC_SUB_PLAN: TSingleField
      AutoGenerateValue = arDefault
      FieldName = 'PERC_SUB_PLAN'
      Origin = 'PERC_SUB_PLAN'
      ProviderFlags = []
      ReadOnly = True
    end
    object FDQuery3NAME_OBJECT_1: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'NAME_OBJECT_1'
      Origin = 'NAME_OBJECT'
      ProviderFlags = []
      ReadOnly = True
      Size = 250
    end
    object FDQuery3PERC_SUB_PLAN_1: TSingleField
      AutoGenerateValue = arDefault
      FieldName = 'PERC_SUB_PLAN_1'
      Origin = 'PERC_SUB_PLAN'
      ProviderFlags = []
      ReadOnly = True
    end
    object FDQuery3NAME_OBJECT_2: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'NAME_OBJECT_2'
      Origin = 'NAME_OBJECT'
      ProviderFlags = []
      ReadOnly = True
      Size = 250
    end
    object FDQuery3FAM: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'FAM'
      Origin = 'FAM'
      ProviderFlags = []
      ReadOnly = True
      Size = 30
    end
    object FDQuery3NAME: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'NAME'
      Origin = 'NAME'
      ProviderFlags = []
      ReadOnly = True
      Size = 30
    end
    object FDQuery3OTCH: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'OTCH'
      Origin = 'OTCH'
      ProviderFlags = []
      ReadOnly = True
      Size = 30
    end
    object FDQuery3N_ZACHET: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'N_ZACHET'
      Origin = 'N_ZACHET'
      ProviderFlags = []
      ReadOnly = True
      Size = 6
    end
    object FDQuery3FAC1: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'FAC1'
      Origin = 'FAC1'
      ProviderFlags = []
      ReadOnly = True
    end
    object FDQuery3KURS: TSmallintField
      FieldName = 'KURS'
      Origin = 'KURS'
    end
    object FDQuery3DEAN: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'DEAN'
      Origin = 'DEAN'
      ProviderFlags = []
      ReadOnly = True
      Size = 30
    end
  end
  object DataSource1: TDataSource
    DataSet = FDQuery1
    Left = 296
    Top = 136
  end
  object DataSource3: TDataSource
    DataSet = FDQuery3
    Left = 440
    Top = 136
  end
  object FDQuery5: TFDQuery
    Connection = DataModule1.FDConnection1
    SQL.Strings = (
      
        'select count(sub_edu_plan.n_plan) from sub_edu_plan, edu_plan, v' +
        'edomost_likvid'
      'where sub_edu_plan.n_plan_parent = edu_plan.n_plan'
      'and edu_plan.n_plan = vedomost_likvid.n_plan'
      'and vedomost_likvid.n_ved = :n_ved')
    Left = 680
    Top = 88
    ParamData = <
      item
        Name = 'N_VED'
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
  object frxDBDataset1: TfrxDBDataset
    UserName = 'frxDBDataset1'
    CloseDataSource = False
    FieldAliases.Strings = (
      'N_FAC=N_FAC'
      'N_VEDOMOST=N_VEDOMOST'
      'SEMESTR_VED=SEMESTR_VED'
      'FIO_EXAM=FIO_EXAM'
      'END_D_EXAM=END_D_EXAM'
      'D_VED=D_VED'
      'N_GROUP=N_GROUP'
      'YEAR_UCH=YEAR_UCH'
      'VID_EDU_PLAN=VID_EDU_PLAN'
      'CLOCK_PLAN_ALL=CLOCK_PLAN_ALL'
      'CLOCK_PLAN=CLOCK_PLAN'
      'ZACH_EXAM=ZACH_EXAM'
      'YEAR_PLAN=YEAR_PLAN'
      'NAME_OBJECT=NAME_OBJECT'
      'FAM=FAM'
      'NAME=NAME'
      'OTCH=OTCH'
      'N_ZACHET=N_ZACHET'
      'FAC1=FAC1'
      'KURS=KURS'
      'DEAN=DEAN')
    DataSource = DataSource1
    BCDToCurrency = False
    Left = 296
    Top = 216
  end
  object frxDBDataset3: TfrxDBDataset
    UserName = 'frxDBDataset3'
    CloseDataSource = False
    DataSource = DataSource3
    BCDToCurrency = False
    Left = 440
    Top = 216
  end
end

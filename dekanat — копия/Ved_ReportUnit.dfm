object Ved_ReportForm: TVed_ReportForm
  Left = 601
  Top = 265
  Caption = ' '
  ClientHeight = 873
  ClientWidth = 820
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = True
  Scaled = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 16
  object frxPreview1: TfrxPreview
    Left = 0
    Top = 0
    Width = 820
    Height = 873
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
    PrintOptions.PrintOnSheet = 0
    PrintOptions.ShowDialog = False
    ReportOptions.CreateDate = 42649.375609629600000000
    ReportOptions.LastChange = 44922.596770752320000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 48
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
      PaperWidth = 210.000000000000000000
      PaperHeight = 297.000000000000000000
      PaperSize = 9
      LeftMargin = 10.000000000000000000
      RightMargin = 10.000000000000000000
      TopMargin = 10.000000000000000000
      BottomMargin = 10.000000000000000000
      Duplex = dmVertical
      VGuides.Strings = (
        '7,55906')
      object ReportTitle1: TfrxReportTitle
        FillType = ftBrush
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -16
        Font.Name = 'Times New Roman'
        Font.Style = []
        Height = 495.118586220000000000
        ParentFont = False
        Top = 16.000000000000000000
        Width = 718.110700000000000000
        object Memo7: TfrxMemoView
          Left = 241.511832990000000000
          Top = 3.779530000000000000
          Width = 257.007891100000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            #1059#1063#1056#1045#1046#1044#1045#1053#1048#1045' '#1054#1041#1056#1040#1047#1054#1042#1040#1053#1048#1071)
          ParentFont = False
        end
        object Memo8: TfrxMemoView
          Left = 42.708683390000000000
          Top = 23.811026060000000000
          Width = 674.267745830000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            #171#1041#1045#1051#1054#1056#1059#1057#1057#1050#1048#1049' '#1043#1054#1057#1059#1044#1040#1056#1057#1058#1042#1045#1053#1053#1067#1049' '#1059#1053#1048#1042#1045#1056#1057#1048#1058#1045#1058' '#1060#1048#1047#1048#1063#1045#1057#1050#1054#1049' '#1050#1059#1051#1068#1058#1059#1056#1067#187)
          ParentFont = False
        end
        object Memo9: TfrxMemoView
          Left = 148.913427320000000000
          Top = 76.724411890000000000
          Width = 478.866141730000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            
              #1047#1040#1063#1045#1058#1053#1054'-'#1069#1050#1047#1040#1052#1045#1053#1040#1062#1048#1054#1053#1053#1040#1071' '#1042#1045#1044#1054#1052#1054#1057#1058#1068' '#8470' [IIF(<frxDBDataset1."N_FAC">' +
              '=3,'#39'07/03-'#39','#39#39')][frxDBDataset1."N_VEDOMOST"] ')
          ParentFont = False
          Formats = <
            item
            end
            item
            end>
        end
        object Memo10: TfrxMemoView
          Left = 191.622061890000000000
          Top = 96.755907950000000000
          Width = 393.826840000000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            
              '[IIF((<frxDBDataset1."STATUS"> = 1),'#39#1090#1077#1082#1091#1097#1077#1081' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1080' '#1074#1085#1077' '#1091#1095#1077#1073 +
              #1085#1086#1081' '#1075#1088#1091#1087#1087#1099#39',IIF((<frxDBDataset1."STATUS"> = 3),'#39#1090#1077#1082#1091#1097#1077#1081' '#1072#1090#1090#1077#1089#1090#1072#1094 +
              #1080#1080' '#1074#1085#1077' '#1091#1095#1077#1073#1085#1086#1081' '#1075#1088#1091#1087#1087#1099#39','#39#1090#1077#1082#1091#1097#1077#1081' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1080' '#1091#1095#1077#1073#1085#1086#1081' '#1075#1088#1091#1087#1087#1099#39'))]')
          ParentFont = False
        end
        object Memo11: TfrxMemoView
          Left = 71.811070000000000000
          Top = 129.637797720000000000
          Width = 301.984269060000000000
          Height = 26.834650550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1060#1086#1088#1084#1072' '#1087#1086#1083#1091#1095#1077#1085#1080#1103' '#1074#1099#1089#1096#1077#1075#1086' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103)
          ParentFont = False
        end
        object Memo12: TfrxMemoView
          Left = 71.811070000000000000
          Top = 153.448821340000000000
          Width = 315.212617950000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1057#1090#1091#1087#1077#1085#1100' '#1087#1086#1083#1091#1095#1077#1085#1080#1103' '#1074#1099#1089#1096#1077#1075#1086' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103)
          ParentFont = False
        end
        object Memo13: TfrxMemoView
          Left = 71.811070000000000000
          Top = 178.393703230000000000
          Width = 214.677184880000000000
          Height = 26.834650550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1060#1086#1088#1084#1072' '#1090#1077#1082#1091#1097#1077#1081' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1080)
          ParentFont = False
        end
        object Memo28: TfrxMemoView
          Left = 42.958996640000000000
          Top = 45.354360000000000000
          Width = 675.350552630000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          HAlign = haCenter
          Memo.UTF8W = (
            
              '[IIF(<frxDBDataset1."N_FAC">=4,'#39#1060#1040#1050#1059#1051#1068#1058#1045#1058' '#1052#1045#1053#1045#1044#1046#1052#1045#1053#1058#1040' '#1057#1055#1054#1056#1058#1040', '#1058#1059 +
              #1056#1048#1047#1052#1040' '#1048' '#1043#1054#1057#1058#1045#1055#1056#1048#1048#1052#1057#1058#1042#1040#39','#39#39')] ')
          ParentFont = False
        end
        object Memo29: TfrxMemoView
          Left = 423.307384410000000000
          Top = 128.504020000000000000
          Width = 94.488250000000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            '[IIF(<frxDBDataset1."VID_EDU_PLAN">=0,'#39#1076#1085#1077#1074#1085#1072#1103#39','#39#1079#1072#1086#1095#1085#1072#1103#39')] ')
          ParentFont = False
        end
        object Memo33: TfrxMemoView
          Left = 374.173494410000000000
          Top = 178.393703230000000000
          Width = 94.488250000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            
              '[IIF(<frxDBDataset1."ZACH_EXAM">=1,'#39#1079#1072#1095#1077#1090#39',IIF(<frxDBDataset1."Z' +
              'ACH_EXAM">=2,'#39#1101#1082#1079#1072#1084#1077#1085#39',IIF(<frxDBDataset1."ZACH_EXAM">=3,'#39#1076#1080#1092'.'#1079#1072 +
              #1095#1077#1090#39','#39#39')))]')
          ParentFont = False
        end
        object Line15: TfrxLineView
          Left = 413.102454960000000000
          Top = 174.614178110000000000
          Width = 116.031496060000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line16: TfrxLineView
          Left = 408.944952680000000000
          Top = 150.425201730000000000
          Width = 123.968503940000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line19: TfrxLineView
          Left = 301.984308110000000000
          Top = 199.559060000000000000
          Width = 254.362204720000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Memo38: TfrxMemoView
          Left = 436.157568190000000000
          Top = 153.448821340000000000
          Width = 59.338587560000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            #1087#1077#1088#1074#1072#1103)
          ParentFont = False
        end
        object Memo21: TfrxMemoView
          Left = 71.811070000000000000
          Top = 204.094620000000000000
          Width = 253.228510000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1058#1077#1082#1091#1097#1072#1103' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1103' '#1087#1088#1086#1074#1086#1076#1080#1090#1089#1103)
          ParentFont = False
        end
        object Memo25: TfrxMemoView
          Left = 370.393940000000000000
          Top = 204.094620000000000000
          Width = 257.008040000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            #1087#1077#1088#1074#1080#1095#1085#1086', '#1087#1086#1074#1090#1086#1088#1085#1086', '#1082#1086#1084#1080#1089#1089#1080#1077#1081)
          ParentFont = False
        end
        object Memo26: TfrxMemoView
          Left = 453.543600000000000000
          Top = 222.992270000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '('#1087#1086#1076#1095#1077#1088#1082#1085#1091#1090#1100')')
          ParentFont = False
        end
        object Line4: TfrxLineView
          Left = 631.181510000000000000
          Top = 264.567256220000000000
          Width = 66.897615830000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Memo42: TfrxMemoView
          Left = 634.961040000000000000
          Top = 245.669606220000000000
          Width = 64.252010000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset1."N_ZACHET"]')
          ParentFont = False
        end
        object Memo15: TfrxMemoView
          Left = 71.811070000000000000
          Top = 245.669450000000000000
          Width = 106.204734170000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1059#1095#1077#1073#1085#1099#1081' '#1075#1086#1076)
          ParentFont = False
        end
        object Memo16: TfrxMemoView
          Left = 71.811070000000000000
          Top = 272.504095670000000000
          Width = 86.929143620000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1060#1072#1082#1091#1083#1100#1090#1077#1090)
          ParentFont = False
        end
        object Memo17: TfrxMemoView
          Left = 322.771687720000000000
          Top = 245.669450000000000000
          Width = 70.677172680000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1057#1077#1084#1077#1089#1090#1088)
          ParentFont = False
        end
        object Memo18: TfrxMemoView
          Left = 71.811070000000000000
          Top = 303.118268900000000000
          Width = 38.551181100000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1050#1091#1088#1089' ')
          ParentFont = False
        end
        object Memo19: TfrxMemoView
          Left = 205.984300790000000000
          Top = 303.118268900000000000
          Width = 55.559060000000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1075#1088#1091#1087#1087#1072)
          ParentFont = False
        end
        object Memo22: TfrxMemoView
          Left = 71.811070000000000000
          Top = 404.031654720000000000
          Width = 378.708685830000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1042#1089#1077#1075#1086' '#1095#1072#1089#1086#1074' '#1087#1086' '#1076#1080#1089#1094#1080#1087#1083#1080#1085#1077' ('#1087#1088#1072#1082#1090#1080#1082#1077') '#1074' '#1089#1077#1084#1077#1089#1090#1088#1077)
          ParentFont = False
        end
        object Memo23: TfrxMemoView
          Left = 71.811070000000000000
          Top = 432.000158660000000000
          Width = 307.653567720000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1060#1072#1084#1080#1083#1080#1103', '#1080#1085#1080#1094#1080#1072#1083#1099' '#1087#1088#1077#1087#1086#1076#1072#1074#1072#1090#1077#1083#1103' ('#1077#1081') ')
          ParentFont = False
        end
        object Memo27: TfrxMemoView
          Left = 219.212764410000000000
          Top = 272.504095670000000000
          Width = 158.740260000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset1."FAC1"]')
          ParentFont = False
        end
        object Memo30: TfrxMemoView
          Left = 136.063050710000000000
          Top = 302.362556220000000000
          Width = 41.574830000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[(Int((<frxDBDataset1."SEMESTR_VED">+1)/2))]')
          ParentFont = False
        end
        object Memo32: TfrxMemoView
          Left = 196.535467240000000000
          Top = 245.669606220000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[<frxDBDataset1."YEAR_PLAN">]/[<frxDBDataset1."YEAR_PLAN">+1]')
          ParentFont = False
          Formats = <
            item
            end
            item
            end>
        end
        object Rich1: TfrxRichView
          Left = 75.590600000000000000
          Top = 336.378326220000000000
          Width = 619.842920000000000000
          Height = 60.472480000000000000
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
            0A5C706172645C6669343134305C66305C66733236205B667278444244617461
            7365745C66315C6C616E673130333320315C66305C6C616E6731303439202E22
            4E414D455F4F424A454354225D5C66325C7061720D0A7D0D0A00}
        end
        object Line1: TfrxLineView
          Left = 175.370137320000000000
          Top = 294.425353070000000000
          Width = 518.929155830000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line5: TfrxLineView
          Left = 402.519716770000000000
          Top = 264.945042990000000000
          Width = 59.338555830000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line7: TfrxLineView
          Left = 121.700836220000000000
          Top = 324.283625670000000000
          Width = 46.866141730000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line12: TfrxLineView
          Left = 379.842575830000000000
          Top = 453.165515430000000000
          Width = 312.566919370000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line17: TfrxLineView
          Left = 179.149652680000000000
          Top = 265.700948500000000000
          Width = 131.905502050000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line18: TfrxLineView
          Left = 71.811070000000000000
          Top = 375.307242830000000000
          Width = 620.598425200000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line20: TfrxLineView
          Left = 340.157541340000000000
          Top = 357.165510550000000000
          Width = 352.251953860000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Memo39: TfrxMemoView
          Left = 71.811070000000000000
          Top = 336.378326220000000000
          Width = 249.448980000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          HAlign = haCenter
          Memo.UTF8W = (
            #1044#1080#1089#1094#1080#1087#1083#1080#1085#1072' ('#1085#1072#1079#1074#1072#1085#1080#1077' '#1087#1088#1072#1082#1090#1080#1082#1080')')
          ParentFont = False
        end
        object Memo48: TfrxMemoView
          Left = 71.811070000000000000
          Top = 464.882346220000000000
          Width = 216.944847720000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1044#1072#1090#1072' '#1087#1088#1086#1074#1077#1076#1077#1085#1080#1103' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1080)
          ParentFont = False
        end
        object Line2: TfrxLineView
          Left = 294.803340000000000000
          Top = 487.559526220000000000
          Width = 403.275639370000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Memo49: TfrxMemoView
          Left = 302.362400000000000000
          Top = 464.882346220000000000
          Width = 294.803340000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            
              '[IIF(<frxDBDataset1."ZACH_EXAM">=2,IIF(<frxDBDataset1."VID_EDU_P' +
              'LAN">=0,<frxDBDataset1."D_VED">,'#39' '#1089' '#39'+(DateToStr(<frxDBDataset1.' +
              '"D_VED">))+'#39' '#1087#1086' '#39'+(DateToStr(<frxDBDataset1."END_D_EXAM">))),'#39' '#1089 +
              ' '#39'+(DateToStr(<frxDBDataset1."D_VED">))+'#39' '#1087#1086' '#39'+(DateToStr(<frxDB' +
              'Dataset1."END_D_EXAM">)))]')
          ParentFont = False
        end
        object Line3: TfrxLineView
          Left = 71.811070000000000000
          Top = 393.071276220000000000
          Width = 620.598425200000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Memo51: TfrxMemoView
          Left = 415.748300000000000000
          Top = 245.669606220000000000
          Width = 56.692950000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset1."SEMESTR_VED"]')
          ParentFont = False
        end
        object Memo52: TfrxMemoView
          Left = 291.023810000000000000
          Top = 302.362556220000000000
          Width = 55.559060000000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset1."N_GROUP"]')
          ParentFont = False
        end
        object Memo53: TfrxMemoView
          Left = 377.953000000000000000
          Top = 430.866576220000000000
          Width = 312.567100000000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset1."FIO_EXAM"]')
          ParentFont = False
        end
        object Memo41: TfrxMemoView
          Left = 476.220780000000000000
          Top = 245.669606220000000000
          Width = 154.960730000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #8470' '#1079#1072#1095#1105#1090#1085#1086#1081' '#1082#1085#1080#1078#1082#1080)
          ParentFont = False
        end
        object Memo35: TfrxMemoView
          Left = 469.417889130000000000
          Top = 404.409710000000000000
          Width = 109.606370000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            
              '[<frxDBDataset1."CLOCK_PLAN_ALL">][IIF((<frxDBDataset1."YEAR_PLA' +
              'N"> - <frxDBDataset1."SEMESTR_VED">/2) >= 2012,'#39' ('#39'+(FloatToStr(' +
              '<frxDBDataset1."CLOCK_PLAN">))+'#39' '#1079'.'#1077'.)'#39','#39#39')]')
          ParentFont = False
          Formats = <
            item
            end
            item
            end>
        end
        object Line23: TfrxLineView
          Left = 449.764070000000000000
          Top = 425.196855280000000000
          Width = 146.645679060000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line6: TfrxLineView
          Left = 291.023810000000000000
          Top = 321.260050000000000000
          Width = 58.204731730000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
      end
      object MasterData1: TfrxMasterData
        FillType = ftBrush
        Height = 30.000000000000000000
        Top = 648.000000000000000000
        Width = 718.110700000000000000
        DataSet = frxDBDataset1
        DataSetName = 'frxDBDataset1'
        RowCount = 0
        object Memo36: TfrxMemoView
          Left = 34.020000000000000000
          Width = 199.994262590000000000
          Height = 30.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          Memo.UTF8W = (
            
              '[frxDBDataset1."FAM"] [COPY(<frxDBDataset1."NAME">, 1, 1)].[COPY' +
              '(<frxDBDataset1."OTCH">, 1, 1)].')
          ParentFont = False
          Formats = <
            item
            end
            item
            end
            item
            end>
        end
        object Memo24: TfrxMemoView
          Left = 234.330860000000000000
          Width = 71.811070000000000000
          Height = 30.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset1."N_ZACHET"]')
          ParentFont = False
        end
        object Memo55: TfrxMemoView
          Left = 306.141930000000000000
          Width = 136.063080000000000000
          Height = 30.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo56: TfrxMemoView
          Left = 442.205010000000000000
          Width = 124.724490000000000000
          Height = 30.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo57: TfrxMemoView
          Left = 566.929500000000000000
          Width = 151.181200000000000000
          Height = 30.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo1: TfrxMemoView
          Left = 7.559060000000000000
          Width = 26.456710000000000000
          Height = 30.000000000000000000
          DataSet = frxDBDataset1
          DataSetName = 'frxDBDataset1'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
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
        Height = 220.724438740000000000
        Top = 696.000000000000000000
        Width = 718.110700000000000000
        object Memo44: TfrxMemoView
          Left = 71.811070000000000000
          Top = 29.858301890000000000
          Width = 179.527566380000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1044#1072#1090#1072' '#1074#1099#1076#1072#1095#1080' '#1074#1077#1076#1086#1084#1086#1089#1090#1080)
          ParentFont = False
        end
        object Memo45: TfrxMemoView
          Left = 349.606335830000000000
          Top = 28.724433860000000000
          Width = 102.047275830000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset1."D_VED"]')
          ParentFont = False
        end
        object Memo46: TfrxMemoView
          Left = 71.811070000000000000
          Top = 55.937029840000000000
          Width = 222.236235120000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1042#1077#1076#1086#1084#1086#1089#1090#1100' '#1076#1077#1081#1089#1090#1074#1080#1090#1077#1083#1100#1085#1072' '#1087#1086)
          ParentFont = False
        end
        object Memo47: TfrxMemoView
          Left = 349.606335830000000000
          Top = 57.448845750000000000
          Width = 102.803181340000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset1."END_D_EXAM"]')
          ParentFont = False
        end
        object Memo62: TfrxMemoView
          Left = 71.811070000000000000
          Top = 90.330733070000000000
          Width = 136.063006770000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1044#1077#1082#1072#1085' '#1092#1072#1082#1091#1083#1100#1090#1077#1090#1072)
          ParentFont = False
        end
        object Memo63: TfrxMemoView
          Left = 478.110272830000000000
          Top = 88.440969290000000000
          Width = 144.755949450000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset1."DEAN"]')
          ParentFont = False
        end
        object Memo64: TfrxMemoView
          Left = 270.236266850000000000
          Top = 109.606323620000000000
          Width = 71.811026060000000000
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
          Left = 478.866188110000000000
          Top = 108.472465350000000000
          Width = 153.448826220000000000
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
          Left = 283.086658110000000000
          Top = 128.881914170000000000
          Width = 45.732290790000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1052'. '#1055'.')
          ParentFont = False
        end
        object Memo67: TfrxMemoView
          Left = 71.811070000000000000
          Top = 159.496087400000000000
          Width = 69.921264720000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1054#1090#1084#1077#1090#1082#1072)
          ParentFont = False
        end
        object Memo68: TfrxMemoView
          Left = 370.393747170000000000
          Top = 159.496087400000000000
          Width = 131.149618500000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1044#1072#1090#1072' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1080)
          ParentFont = False
        end
        object Memo69: TfrxMemoView
          Left = 71.811070000000000000
          Top = 193.889788190000000000
          Width = 212.787408900000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1055#1086#1076#1087#1080#1089#1100' '#1087#1088#1077#1087#1086#1076#1072#1074#1072#1090#1077#1083#1103'('#1077#1081')')
          ParentFont = False
        end
        object Line24: TfrxLineView
          Left = 256.252014880000000000
          Top = 48.000024410000000000
          Width = 277.417322830000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line25: TfrxLineView
          Left = 210.141778660000000000
          Top = 107.716559840000000000
          Width = 185.196850390000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line26: TfrxLineView
          Left = 145.889810160000000000
          Top = 174.992150390000000000
          Width = 200.692913390000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line27: TfrxLineView
          Left = 505.700841100000000000
          Top = 174.992150390000000000
          Width = 172.724409450000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line28: TfrxLineView
          Left = 425.196896770000000000
          Top = 107.716559840000000000
          Width = 254.362204720000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line29: TfrxLineView
          Left = 301.984308110000000000
          Top = 76.724436300000000000
          Width = 231.685029610000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line30: TfrxLineView
          Left = 290.645720550000000000
          Top = 213.165381180000000000
          Width = 355.275590550000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Memo70: TfrxMemoView
          Left = 71.811070000000000000
          Width = 272.126160000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1060#1072#1084#1080#1083#1080#1103', '#1080#1085#1080#1094#1080#1072#1083#1099' '#1086#1073#1091#1095#1072#1102#1097#1077#1075#1086#1089#1103)
          ParentFont = False
        end
        object Line31: TfrxLineView
          Left = 346.960683620000000000
          Top = 21.165356770000000000
          Width = 344.692913390000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Memo20: TfrxMemoView
          Left = 350.496290000000000000
          Width = 336.378170000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
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
      end
      object Header2: TfrxHeader
        FillType = ftBrush
        Height = 56.692913390000000000
        Top = 572.000000000000000000
        Width = 718.110700000000000000
        object Memo3: TfrxMemoView
          Left = 7.559060000000000000
          Width = 26.456710000000000000
          Height = 56.692913390000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #8470#1087'/'#1087)
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo4: TfrxMemoView
          Left = 34.020000000000000000
          Width = 199.994262590000000000
          Height = 56.692913390000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #1060#1072#1084#1080#1083#1080#1103', '#1080#1085#1080#1094#1080#1072#1083#1099' '#1086#1073#1091#1095#1072#1102#1097#1077#1075#1086#1089#1103)
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo5: TfrxMemoView
          Left = 234.330860000000000000
          Width = 71.811070000000000000
          Height = 56.692913390000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #8470' '#1079#1072#1095#1105#1090#1085#1086#1081' '#1082#1085#1080#1078#1082#1080)
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo6: TfrxMemoView
          Left = 306.141930000000000000
          Width = 136.063080000000000000
          Height = 56.692913390000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #1054#1090#1084#1077#1090#1082#1072' '#1086' '#1079#1072#1095#1105#1090#1077' ('#1079#1072#1095#1090#1077#1085#1086', '#1085#1077' '#1079#1072#1095#1090#1077#1085#1086')')
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo14: TfrxMemoView
          Left = 442.205010000000000000
          Width = 124.724490000000000000
          Height = 56.692913390000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #1054#1090#1084#1077#1090#1082#1072' '#1074' '#1073#1072#1083#1083#1072#1093)
          ParentFont = False
          VAlign = vaCenter
        end
        object Memo54: TfrxMemoView
          Left = 566.929500000000000000
          Width = 151.181200000000000000
          Height = 56.692913390000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #1055#1086#1076#1087#1080#1089#1100' '#1087#1088#1077#1087#1086#1076#1072#1074#1072#1090#1077#1083#1103' ('#1077#1081') '#1080' '#1076#1072#1090#1072'*')
          ParentFont = False
          VAlign = vaCenter
        end
      end
      object ReportSummary1: TfrxReportSummary
        FillType = ftBrush
        Height = 457.322641810000000000
        Top = 976.000000000000000000
        Width = 718.110700000000000000
        object Rich2: TfrxRichView
          Left = 18.897650000000000000
          Top = 45.354359999999900000
          Width = 718.110700000000000000
          Height = 408.188751810000000000
          GapX = 2.000000000000000000
          GapY = 1.000000000000000000
          RichEdit = {
            7B5C727466315C616E73695C616E7369637067313235315C64656666305C6E6F
            7569636F6D7061745C6465666C616E67313034397B5C666F6E7474626C7B5C66
            305C666E696C5C66636861727365743230342054696D6573204E657720526F6D
            616E204359523B7D7B5C66315C666E696C5C6663686172736574302054696D65
            73204E657720526F6D616E3B7D7D0D0A7B5C2A5C67656E657261746F72205269
            6368656432302031302E302E31363239397D5C766965776B696E64345C756331
            200D0A5C706172645C6C693534305C66305C667332365C2763345C2765355C27
            65615C2765305C276564202020205F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F
            5F5F5F5F5F5F5F202020202020205F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F
            5F5F5F5F5F5F5F5F5F5F5F5C667332325C7061720D0A5C66315C6C616E673130
            3333202020202020202020202020202020202020202020202020202020202020
            202020285C66305C6C616E67313034395C2765665C2765655C2765345C276566
            5C2765385C2766315C2766632920202020202020202020202020202020202020
            202020202020202020202020202020202020202020202020285C2765385C2765
            645C2765385C2766365C2765385C2765305C2765625C2766622C205C2766345C
            2765305C2765635C2765385C2765625C2765385C276666292020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020205C7061720D0A5C66315C66
            7332365C6C616E67313033332020202020202020202020202020202020202020
            2020202020202020202020202020202020205C66305C6C616E67313034395C27
            63632E5C2763662E202020202020202020202020202020202020202020202020
            5C7061720D0A5C66315C6C616E67313033335C7061720D0A5C66305C6C616E67
            313034395C2763615C2765655C2765625C2765385C2766375C2765355C276631
            5C2766325C2765325C276565205C2765655C2765315C2766335C2766375C2765
            305C2766655C2766395C2765385C2766355C2766315C2766662C205C2765665C
            2766305C2765385C2766315C2766335C2766325C2766315C2766325C2765325C
            2765655C2765325C2765305C2765325C2766385C2765385C276635205C276564
            5C276530205C2765305C2766325C2766325C2765355C2766315C2766325C2765
            305C2766365C2765385C276538205F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5C70
            61720D0A5C66315C6C616E67313033335C7061720D0A5C66305C6C616E673130
            34395C2763615C2765655C2765625C2765385C2766375C2765355C2766315C27
            66325C2765325C276565205C2765655C2765315C2766335C2766375C2765305C
            2766655C2766395C2765385C2766355C2766315C2766662C205C2765665C2765
            655C2765625C2766335C2766375C2765385C2765325C2766385C2765385C2766
            35205C2765655C2766325C2765635C2765355C2766325C2765615C2765382020
            205C7061720D0A5C66315C6C616E67313033335C7061720D0A313020285C6630
            5C6C616E67313034395C2765345C2765355C2766315C2766665C2766325C2766
            6329205F5F5F5F5F5F20203820285C2765325C2765655C2766315C2765355C27
            65635C2766632920205F5F5F5F5F5F2020203520285C2765665C2766665C2766
            325C2766632920202020205F5F5F5F5F5F5F20203320285C2766325C2766305C
            2765382920205F5F5F5F5F5F5F5C7061720D0A5C66315C6C616E67313033335C
            7061720D0A3920285C66305C6C616E67313034395C2765345C2765355C276532
            5C2766665C2766325C276663292020205F5F5F5F5F5F20203720285C2766315C
            2765355C2765635C276663292020202020205F5F5F5F5F5F20203420285C2766
            375C2765355C2766325C2766625C2766305C2765352920205F5F5F5F5F5F5F20
            203220285C2765345C2765325C2765302920205F5F5F5F5F5F5F5C7061720D0A
            5C66315C6C616E67313033332020202020202020202020202020202020202020
            202020202020205C7061720D0A2020202020202020202020205C66305C6C616E
            673130343920205C66315C6C616E67313033332020202020202020205C66305C
            6C616E673130343920205C66315C6C616E67313033332020205C66305C6C616E
            673130343920205C66315C6C616E673130333320202020202020202020362028
            5C66305C6C616E67313034395C2766385C2765355C2766315C2766325C276663
            29202020205F5F5F5F5F5F202020202020202020202020202020202020202020
            2020202020202020202020202020203120285C2765655C2765345C2765385C27
            65642920205F5F5F5F5F5F5C7061720D0A5C66315C6C616E6731303333202020
            202020202020202020202020205C7061720D0A5C66305C6C616E67313034395C
            2763615C2765655C2765625C2765385C2766375C2765355C2766315C2766325C
            2765325C276565205C2765655C2765315C2766335C2766375C2765305C276665
            5C2766395C2765385C2766355C2766315C2766662C205C2765645C276535205C
            2766665C2765325C2765385C2765325C2766385C2765385C2766355C2766315C
            276666205C2765645C276530205C2765305C2766325C2766325C2765355C2766
            315C2766325C2765305C2766365C2765385C2766655C7061720D0A5C66315C6C
            616E673130333320205C7061720D0A285C66305C6C616E67313034395C276532
            205C2766325C2765655C276563205C2766375C2765385C2766315C2765625C27
            6535205C2765645C276535205C2765345C2765655C2765665C2766335C276639
            5C2765355C2765645C2765645C2766625C276635205C276561205C2765305C27
            66325C2766325C2765355C2766315C2766325C2765305C2766365C2765385C27
            653829205F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5C7061720D0A5C6631
            5C6C616E67313033332020202020202020202020202020202020202020202020
            20202020202020202020202020202020202020202020202020202020205C7061
            720D0A5C7061720D0A5C66305C667332345C6C616E67313034395C7061720D0A
            7D0D0A00}
        end
        object Memo50: TfrxMemoView
          Left = 400.630180000000000000
          Top = 41.574830000000000000
          Width = 162.519790000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset1."DEAN"]')
          ParentFont = False
        end
        object Memo2: TfrxMemoView
          Left = 56.692910940000000000
          Top = 377.952877950000000000
          Width = 627.401980000000000000
          Height = 71.811070000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            ''
            ''
            
              '*'#1044#1072#1090#1072' '#1087#1088#1086#1089#1090#1072#1074#1083#1103#1077#1090#1089#1103' '#1074' '#1082#1072#1078#1076#1086#1081' '#1089#1090#1088#1086#1082#1077', '#1077#1089#1083#1080' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1103' '#1086#1073#1091#1095#1072#1102#1097#1080#1093#1089#1103 +
              ' '#1087#1088#1086#1074#1086#1076#1080#1083#1072#1089#1100' '#1085#1077' '#1074' '#1086#1076#1080#1085' '#1076#1077#1085#1100)
          ParentFont = False
        end
      end
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
      'STATUS=STATUS'
      'VID_EDU_PLAN=VID_EDU_PLAN'
      'CLOCK_PLAN_ALL=CLOCK_PLAN_ALL'
      'YEAR_PLAN=YEAR_PLAN'
      'CLOCK_PLAN=CLOCK_PLAN'
      'ZACH_EXAM=ZACH_EXAM'
      'NAME_OBJECT=NAME_OBJECT'
      'FAM=FAM'
      'NAME=NAME'
      'OTCH=OTCH'
      'N_ZACHET=N_ZACHET'
      'FAC1=FAC1'
      'N_GROUP=N_GROUP'
      'DEAN=DEAN')
    DataSource = DataSource1
    BCDToCurrency = False
    Left = 232
    Top = 136
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
    ReportOptions.CreateDate = 42774.595035925900000000
    ReportOptions.LastChange = 42774.595035925900000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 48
    Top = 88
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
        Height = 500.000000000000000000
        Top = 16.000000000000000000
        Width = 718.110700000000000000
        object Memo7: TfrxMemoView
          Left = 252.850422990000000000
          Top = 3.779530000000000000
          Width = 275.905541100000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            #1059#1063#1056#1045#1046#1044#1045#1053#1048#1045' '#1054#1041#1056#1040#1047#1054#1042#1040#1053#1048#1071)
          ParentFont = False
        end
        object Memo8: TfrxMemoView
          Left = 46.488213390000000000
          Top = 23.811026060000000000
          Width = 678.047275830000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            #171#1041#1045#1051#1054#1056#1059#1057#1057#1050#1048#1049' '#1043#1054#1057#1059#1044#1040#1056#1057#1058#1042#1045#1053#1053#1067#1049' '#1059#1053#1048#1042#1045#1056#1057#1048#1058#1045#1058' '#1060#1048#1047#1048#1063#1045#1057#1050#1054#1049' '#1050#1059#1051#1068#1058#1059#1056#1067#187)
          ParentFont = False
        end
        object Memo9: TfrxMemoView
          Left = 133.795307320000000000
          Top = 76.724411890000000000
          Width = 497.763791730000000000
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
          Left = 187.842531890000000000
          Top = 92.976377950000000000
          Width = 397.606370000000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            
              '[IIF((<frxDBDataset3."STATUS"> = 1),'#39#1090#1077#1082#1091#1097#1077#1081' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1080' '#1074#1085#1077' '#1091#1095#1077#1073 +
              #1085#1086#1081' '#1075#1088#1091#1087#1087#1099#39',IIF((<frxDBDataset3."STATUS"> = 3),'#39#1090#1077#1082#1091#1097#1077#1081' '#1072#1090#1090#1077#1089#1090#1072#1094 +
              #1080#1080' '#1074#1085#1077' '#1091#1095#1077#1073#1085#1086#1081' '#1075#1088#1091#1087#1087#1099#39','#39#1090#1077#1082#1091#1097#1077#1081' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1080' '#1091#1095#1077#1073#1085#1086#1081' '#1075#1088#1091#1087#1087#1099#39'))]')
          ParentFont = False
        end
        object Memo11: TfrxMemoView
          Left = 75.590600000000000000
          Top = 129.637797720000000000
          Width = 309.543329060000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1060#1086#1088#1084#1072' '#1087#1086#1083#1091#1095#1077#1085#1080#1103' '#1074#1099#1089#1096#1077#1075#1086' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103)
          ParentFont = False
        end
        object Memo12: TfrxMemoView
          Left = 75.590600000000000000
          Top = 153.448821340000000000
          Width = 315.212617950000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1057#1090#1091#1087#1077#1085#1100' '#1087#1086#1083#1091#1095#1077#1085#1080#1103' '#1074#1099#1089#1096#1077#1075#1086' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1103)
          ParentFont = False
        end
        object Memo13: TfrxMemoView
          Left = 75.590600000000000000
          Top = 178.393703230000000000
          Width = 210.897654880000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1060#1086#1088#1084#1072' '#1090#1077#1082#1091#1097#1077#1081' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1080)
          ParentFont = False
        end
        object Memo28: TfrxMemoView
          Left = 46.116891380000000000
          Top = 45.354360000000000000
          Width = 673.245289470000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          HAlign = haCenter
          Memo.UTF8W = (
            
              '[IIF(<frxDBDataset3."N_FAC">=4,'#39#1060#1040#1050#1059#1051#1068#1058#1045#1058' '#1052#1045#1053#1045#1044#1046#1052#1045#1053#1058#1040' '#1057#1055#1054#1056#1058#1040', '#1058#1059 +
              #1056#1048#1047#1052#1040' '#1048' '#1043#1054#1057#1058#1045#1055#1056#1048#1048#1052#1057#1058#1042#1040#39','#39#39')] ')
          ParentFont = False
        end
        object Memo29: TfrxMemoView
          Left = 430.866444410000000000
          Top = 128.504020000000000000
          Width = 94.488250000000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[IIF(<frxDBDataset3."VID_EDU_PLAN">=0,'#39#1076#1085#1077#1074#1085#1072#1103#39','#39#1079#1072#1086#1095#1085#1072#1103#39')] ')
          ParentFont = False
        end
        object Memo33: TfrxMemoView
          Left = 411.968794410000000000
          Top = 178.393703230000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            
              '[IIF(<frxDBDataset3."ZACH_EXAM">=1,'#39#1079#1072#1095#1077#1090#39',IIF(<frxDBDataset3."Z' +
              'ACH_EXAM">=2,'#39#1101#1082#1079#1072#1084#1077#1085#39',IIF(<frxDBDataset3."ZACH_EXAM">=3,'#39#1076#1080#1092'.'#1079#1072 +
              #1095#1077#1090#39','#39#39')))]')
          ParentFont = False
        end
        object Line15: TfrxLineView
          Left = 409.322924960000000000
          Top = 174.614178110000000000
          Width = 116.031496060000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line16: TfrxLineView
          Left = 412.724482680000000000
          Top = 150.425201730000000000
          Width = 123.968503940000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line19: TfrxLineView
          Left = 328.441018110000000000
          Top = 199.559060000000000000
          Width = 254.362204720000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Memo38: TfrxMemoView
          Left = 436.157568190000000000
          Top = 153.448821340000000000
          Width = 59.338587560000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            #1087#1077#1088#1074#1072#1103)
          ParentFont = False
        end
        object Memo24: TfrxMemoView
          Left = 75.590600000000000000
          Top = 204.094620000000000000
          Width = 268.346630000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1058#1077#1082#1091#1097#1072#1103' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1103' '#1087#1088#1086#1074#1086#1076#1080#1090#1089#1103)
          ParentFont = False
        end
        object Memo43: TfrxMemoView
          Left = 377.953000000000000000
          Top = 204.094620000000000000
          Width = 260.787570000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            #1087#1077#1088#1074#1080#1095#1085#1086', '#1087#1086#1074#1090#1086#1088#1085#1086', '#1082#1086#1084#1080#1089#1089#1080#1077#1081)
          ParentFont = False
        end
        object Memo54: TfrxMemoView
          Left = 461.102660000000000000
          Top = 222.992270000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '('#1087#1086#1076#1095#1077#1088#1082#1085#1091#1090#1100')')
          ParentFont = False
        end
        object Memo20: TfrxMemoView
          Left = 75.590600000000000000
          Top = 245.669450000000000000
          Width = 102.425204170000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1059#1095#1077#1073#1085#1099#1081' '#1075#1086#1076)
          ParentFont = False
        end
        object Memo27: TfrxMemoView
          Left = 75.590600000000000000
          Top = 272.504095670000000000
          Width = 86.929143620000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1060#1072#1082#1091#1083#1100#1090#1077#1090)
          ParentFont = False
        end
        object Memo55: TfrxMemoView
          Left = 345.448867720000000000
          Top = 245.669450000000000000
          Width = 82.015762680000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1057#1077#1084#1077#1089#1090#1088)
          ParentFont = False
        end
        object Memo56: TfrxMemoView
          Left = 75.590600000000000000
          Top = 303.118268900000000000
          Width = 38.551181100000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1050#1091#1088#1089' ')
          ParentFont = False
        end
        object Memo57: TfrxMemoView
          Left = 209.763830790000000000
          Top = 303.118268900000000000
          Width = 55.559060000000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1075#1088#1091#1087#1087#1072)
          ParentFont = False
        end
        object Memo58: TfrxMemoView
          Left = 75.590600000000000000
          Top = 404.031654720000000000
          Width = 374.929155830000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1042#1089#1077#1075#1086' '#1095#1072#1089#1086#1074' '#1087#1086' '#1076#1080#1089#1094#1080#1087#1083#1080#1085#1077' ('#1087#1088#1072#1082#1090#1080#1082#1077') '#1074' '#1089#1077#1084#1077#1089#1090#1088#1077)
          ParentFont = False
        end
        object Memo59: TfrxMemoView
          Left = 75.590600000000000000
          Top = 432.000158660000000000
          Width = 300.094507720000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1060#1072#1084#1080#1083#1080#1103', '#1080#1085#1080#1094#1080#1072#1083#1099' '#1087#1088#1077#1087#1086#1076#1072#1074#1072#1090#1077#1083#1103' ('#1077#1081') ')
          ParentFont = False
        end
        object Memo60: TfrxMemoView
          Left = 222.992294410000000000
          Top = 272.504095670000000000
          Width = 158.740260000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset3."FAC1"]')
          ParentFont = False
        end
        object Memo61: TfrxMemoView
          Left = 139.842580710000000000
          Top = 302.362556220000000000
          Width = 41.574830000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[(Int((<frxDBDataset3."SEMESTR_VED">+1)/2))]')
          ParentFont = False
        end
        object Memo67: TfrxMemoView
          Left = 196.535467240000000000
          Top = 245.669606220000000000
          Width = 117.165430000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
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
        object Rich3: TfrxRichView
          Left = 75.590600000000000000
          Top = 340.157856220000000000
          Width = 619.842920000000000000
          Height = 56.692950000000000000
          GapX = 2.000000000000000000
          GapY = 1.000000000000000000
          RichEdit = {
            7B5C727466315C616E73695C616E7369637067313235315C64656666305C6E6F
            7569636F6D7061745C6465666C616E67313034397B5C666F6E7474626C7B5C66
            305C666E696C5C66636861727365743230342054696D6573204E657720526F6D
            616E204359523B7D7B5C66315C666E696C5C6663686172736574323034205461
            686F6D613B7D7D0D0A7B5C2A5C67656E657261746F7220526963686564323020
            31302E302E31363239397D5C766965776B696E64345C756331200D0A5C706172
            645C6669343134305C66305C66733236205B667278444244617461736574332E
            224E414D455F4F424A454354225D5C66315C667331365C7061720D0A7D0D0A00}
        end
        object Line6: TfrxLineView
          Left = 164.031547320000000000
          Top = 294.425353070000000000
          Width = 484.913385830000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line8: TfrxLineView
          Left = 417.637836770000000000
          Top = 264.945042990000000000
          Width = 59.338555830000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line9: TfrxLineView
          Left = 125.480366220000000000
          Top = 324.283625670000000000
          Width = 46.866141730000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line11: TfrxLineView
          Left = 383.622105830000000000
          Top = 453.165515430000000000
          Width = 312.566919370000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line13: TfrxLineView
          Left = 186.708712680000000000
          Top = 265.700948500000000000
          Width = 131.905502050000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line14: TfrxLineView
          Left = 75.590600000000000000
          Top = 375.307242830000000000
          Width = 620.598425200000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Memo69: TfrxMemoView
          Left = 75.590600000000000000
          Top = 336.378326220000000000
          Width = 257.008040000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          HAlign = haCenter
          Memo.UTF8W = (
            #1044#1080#1089#1094#1080#1087#1083#1080#1085#1072' ('#1085#1072#1079#1074#1072#1085#1080#1077' '#1087#1088#1072#1082#1090#1080#1082#1080')')
          ParentFont = False
        end
        object Memo70: TfrxMemoView
          Left = 75.590600000000000000
          Top = 464.882346220000000000
          Width = 216.944847720000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1044#1072#1090#1072' '#1087#1088#1086#1074#1077#1076#1077#1085#1080#1103' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1080)
          ParentFont = False
        end
        object Line22: TfrxLineView
          Left = 287.244280000000000000
          Top = 487.559526220000000000
          Width = 414.614229370000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Memo71: TfrxMemoView
          Left = 306.141930000000000000
          Top = 464.882346220000000000
          Width = 389.291590000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            
              '[IIF(<frxDBDataset3."ZACH_EXAM">=2,IIF(<frxDBDataset3."VID_EDU_P' +
              'LAN">=0,<frxDBDataset3."D_VED">,'#39' '#1089' '#39'+(DateToStr(<frxDBDataset3.' +
              '"D_VED">))+'#39' '#1087#1086' '#39'+(DateToStr(<frxDBDataset3."END_D_EXAM">))),'#39' '#1089 +
              ' '#39'+(DateToStr(<frxDBDataset3."D_VED">))+'#39' '#1087#1086' '#39'+(DateToStr(<frxDB' +
              'Dataset3."END_D_EXAM">)))]')
          ParentFont = False
        end
        object Line26: TfrxLineView
          Left = 75.590600000000000000
          Top = 393.071276220000000000
          Width = 620.598425200000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Memo72: TfrxMemoView
          Left = 427.086890000000000000
          Top = 245.669606220000000000
          Width = 64.252010000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset3."SEMESTR_VED"]')
          ParentFont = False
        end
        object Memo73: TfrxMemoView
          Left = 294.803340000000000000
          Top = 302.362556220000000000
          Width = 44.220470000000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset3."N_GROUP"]')
          ParentFont = False
        end
        object Memo74: TfrxMemoView
          Left = 389.291590000000000000
          Top = 430.866576220000000000
          Width = 305.008040000000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset3."FIO_EXAM"]')
          ParentFont = False
        end
        object Line30: TfrxLineView
          Left = 294.803340000000000000
          Top = 325.039580000000000000
          Width = 46.866141730000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Memo35: TfrxMemoView
          Left = 506.457044410000000000
          Top = 404.409866220000000000
          Width = 124.724490000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = [fsBold]
          Memo.UTF8W = (
            
              '[<frxDBDataset3."CLOCK_PLAN_ALL">][IIF((<frxDBDataset3."YEAR_PLA' +
              'N"> - <frxDBDataset3."SEMESTR_VED">/2) >= 2012,'#39' ('#39'+(FloatToStr(' +
              '<frxDBDataset3."CLOCK_PLAN">))+'#39' '#1079'.'#1077'.)'#39','#39#39')]')
          ParentFont = False
          Formats = <
            item
            end
            item
            end>
        end
        object Line23: TfrxLineView
          Left = 501.921345280000000000
          Top = 425.197011500000000000
          Width = 131.527559060000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line1: TfrxLineView
          Left = 340.157700000000000000
          Top = 359.055350000000000000
          Width = 356.031325200000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
      end
      object Header2: TfrxHeader
        FillType = ftBrush
        Height = 150.078740160000000000
        Top = 576.000000000000000000
        Width = 718.110700000000000000
        object Memo1: TfrxMemoView
          Left = 26.629259260000000000
          Width = 165.540983810000000000
          Height = 150.000000000000000000
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
          Left = 191.970000000000000000
          Width = 65.810996770000000000
          Height = 150.000000000000000000
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
          Left = 257.780000000000000000
          Width = 110.000000000000000000
          Height = 130.000000000000000000
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
          Left = 367.780000000000000000
          Width = 110.000000000000000000
          Height = 130.000000000000000000
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
          Left = 477.779840000000000000
          Width = 110.220000000000000000
          Height = 150.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #1054#1090#1084#1077#1090#1082#1072' '#1087#1086' '#1086#1073#1103#1079#1072#1090#1077#1083#1100#1085#1086#1084#1091' '#1084#1086#1076#1091#1083#1102' [frxDBDataset3."NAME_OBJECT"]')
          ParentFont = False
        end
        object Memo34: TfrxMemoView
          Left = 588.000000000000000000
          Width = 130.000000000000000000
          Height = 150.000000000000000000
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
          Left = 257.780000000000000000
          Top = 130.000000000000000000
          Width = 110.000000000000000000
          Height = 20.000000000000000000
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
          Left = 367.780000000000000000
          Top = 130.000000000000000000
          Width = 110.000000000000000000
          Height = 20.000000000000000000
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
          Left = 0.169174820000000000
          Width = 26.460000000000000000
          Height = 150.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            #8470' '#1087'/'#1087)
          ParentFont = False
        end
        object Memo19: TfrxMemoView
          Left = 1058.268400000000000000
          Top = 2.929500000000000000
          Width = 162.519790000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          HAlign = haCenter
          Memo.UTF8W = (
            
              '[IIF(<frxDBDataset3."N_FAC">=1,'#39#1045'.'#1042'. '#1055#1083#1072#1085#1080#1076#1072#39',IIF(<frxDBDataset3' +
              '."N_FAC">=2,'#39#1048'.'#1048'. '#1043#1091#1089#1083#1080#1089#1090#1086#1074#1072#39',IIF(<frxDBDataset3."N_FAC">=3,'#39#1053'.'#1052 +
              '. '#1052#1072#1096#1072#1088#1089#1082#1072#1103#39','#39#1054'.'#1053'. '#1052#1080#1093#1072#1081#1083#1086#1074#1072#39')))]')
          ParentFont = False
        end
      end
      object MasterData2: TfrxMasterData
        FillType = ftBrush
        Height = 40.000000000000000000
        Top = 748.000000000000000000
        Width = 718.110700000000000000
        DataSet = frxDBDataset3
        DataSetName = 'frxDBDataset3'
        RowCount = 0
        object Memo36: TfrxMemoView
          Left = 25.885144080000000000
          Width = 166.281797780000000000
          Height = 40.000000000000000000
          DataSet = frxDBDataset3
          DataSetName = 'frxDBDataset3'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
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
          Left = 192.166941850000000000
          Width = 65.810000000000000000
          Height = 40.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset3."N_ZACHET"]')
          ParentFont = False
        end
        object Memo44: TfrxMemoView
          Left = 257.780000000000000000
          Width = 110.000000000000000000
          Height = 40.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo45: TfrxMemoView
          Left = 367.780000000000000000
          Width = 110.000000000000000000
          Height = 40.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo46: TfrxMemoView
          Left = 477.779840000000000000
          Width = 110.220000000000000000
          Height = 40.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo47: TfrxMemoView
          Left = 588.000000000000000000
          Width = 130.000000000000000000
          Height = 40.000000000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -16
          Font.Name = 'Times New Roman'
          Font.Style = []
          Frame.Typ = [ftLeft, ftRight, ftTop, ftBottom]
          ParentFont = False
        end
        object Memo3: TfrxMemoView
          Left = -0.571565920000000000
          Width = 26.456710000000000000
          Height = 40.000000000000000000
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
        Height = 156.094500390000000000
        Top = 808.000000000000000000
        Width = 718.110700000000000000
        object Memo6: TfrxMemoView
          Left = 75.590600000000000000
          Top = 33.259849840000000000
          Width = 218.456705120000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1042#1077#1076#1086#1084#1086#1089#1090#1100' '#1076#1077#1081#1089#1090#1074#1080#1090#1077#1083#1100#1085#1072' '#1087#1086)
          ParentFont = False
        end
        object Memo14: TfrxMemoView
          Left = 368.503985830000000000
          Top = 34.771665750000000000
          Width = 87.685061340000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset3."END_D_EXAM"]')
          ParentFont = False
        end
        object Memo62: TfrxMemoView
          Left = 75.590600000000000000
          Top = 63.874023070000000000
          Width = 139.842536770000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1044#1077#1082#1072#1085' '#1092#1072#1082#1091#1083#1100#1090#1077#1090#1072)
          ParentFont = False
        end
        object Memo63: TfrxMemoView
          Left = 481.889802830000000000
          Top = 65.763789290000000000
          Width = 140.976419450000000000
          Height = 23.055120550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset3."DEAN"]')
          ParentFont = False
        end
        object Memo64: TfrxMemoView
          Left = 274.015796850000000000
          Top = 86.929143620000000000
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
          Top = 85.795285350000000000
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
          Top = 106.204734170000000000
          Width = 45.732290790000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1052'. '#1055'.')
          ParentFont = False
        end
        object Memo68: TfrxMemoView
          Left = 374.173277170000000000
          Top = 133.039377400000000000
          Width = 127.370088500000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1044#1072#1090#1072' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1080)
          ParentFont = False
        end
        object Line24: TfrxLineView
          Left = 271.370134880000000000
          Top = 21.543314410000000000
          Width = 277.417322830000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line25: TfrxLineView
          Left = 213.921308660000000000
          Top = 85.039379840000000000
          Width = 185.196850390000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line27: TfrxLineView
          Left = 498.141781100000000000
          Top = 152.314970390000000000
          Width = 172.724409450000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line28: TfrxLineView
          Left = 428.976426770000000000
          Top = 85.039379840000000000
          Width = 254.362204720000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Line29: TfrxLineView
          Left = 301.984308110000000000
          Top = 54.047256300000000000
          Width = 246.803149610000000000
          Color = clBlack
          Frame.Typ = [ftTop]
        end
        object Memo4: TfrxMemoView
          Left = 75.590600000000000000
          Top = 3.401591889999960000
          Width = 187.086626380000000000
          Height = 19.275590550000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            #1044#1072#1090#1072' '#1074#1099#1076#1072#1095#1080' '#1074#1077#1076#1086#1084#1086#1089#1090#1080)
          ParentFont = False
        end
        object Memo15: TfrxMemoView
          Left = 366.614410000000000000
          Top = 3.779530000000000000
          Width = 94.488250000000000000
          Height = 22.677180000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            '[frxDBDataset3."D_VED"]')
          ParentFont = False
        end
        object Memo16: TfrxMemoView
          Left = 1092.284170000000000000
          Top = 117.165430000000000000
          Width = 162.519790000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          HAlign = haCenter
          Memo.UTF8W = (
            
              '[IIF(<frxDBDataset3."N_FAC">=1,'#39#1045'.'#1042'. '#1055#1083#1072#1085#1080#1076#1072#39',IIF(<frxDBDataset3' +
              '."N_FAC">=2,'#39#1048'.'#1048'. '#1043#1091#1089#1083#1080#1089#1090#1086#1074#1072#39',IIF(<frxDBDataset3."N_FAC">=3,'#39#1053'.'#1052 +
              '. '#1052#1072#1096#1072#1088#1089#1082#1072#1103#39','#39#1054'.'#1053'. '#1052#1080#1093#1072#1081#1083#1086#1074#1072#39')))]')
          ParentFont = False
        end
        object Memo18: TfrxMemoView
          Left = 952.441560000000000000
          Top = 75.590600000000100000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
        end
      end
      object ReportSummary1: TfrxReportSummary
        FillType = ftBrush
        Height = 457.322641810000000000
        Top = 1024.000000000000000000
        Width = 718.110700000000000000
        object Memo17: TfrxMemoView
          Left = 748.346900940000000000
          Top = 238.110267950000000000
          Width = 627.401980000000000000
          Height = 71.811070000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            ''
            ''
            
              '*'#1044#1072#1090#1072' '#1087#1088#1086#1089#1090#1072#1074#1083#1103#1077#1090#1089#1103' '#1074' '#1082#1072#1078#1076#1086#1081' '#1089#1090#1088#1086#1082#1077', '#1077#1089#1083#1080' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1103' '#1086#1073#1091#1095#1072#1102#1097#1080#1093#1089#1103 +
              ' '#1087#1088#1086#1074#1086#1076#1080#1083#1072#1089#1100' '#1085#1077' '#1074' '#1086#1076#1080#1085' '#1076#1077#1085#1100)
          ParentFont = False
        end
        object Rich2: TfrxRichView
          Left = 18.897650000000000000
          Top = 45.354360000000000000
          Width = 718.110700000000000000
          Height = 408.188751810000000000
          GapX = 2.000000000000000000
          GapY = 1.000000000000000000
          RichEdit = {
            7B5C727466315C616E73695C616E7369637067313235315C64656666305C6E6F
            7569636F6D7061745C6465666C616E67313034397B5C666F6E7474626C7B5C66
            305C666E696C5C66636861727365743230342054696D6573204E657720526F6D
            616E204359523B7D7B5C66315C666E696C5C6663686172736574302054696D65
            73204E657720526F6D616E3B7D7D0D0A7B5C2A5C67656E657261746F72205269
            6368656432302031302E302E31363239397D5C766965776B696E64345C756331
            200D0A5C706172645C6C693534305C66305C667332365C2763345C2765355C27
            65615C2765305C276564202020205F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F
            5F5F5F5F5F5F5F202020202020205F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F
            5F5F5F5F5F5F5F5F5F5F5F5C667332325C7061720D0A5C66315C6C616E673130
            3333202020202020202020202020202020202020202020202020202020202020
            202020285C66305C6C616E67313034395C2765665C2765655C2765345C276566
            5C2765385C2766315C2766632920202020202020202020202020202020202020
            202020202020202020202020202020202020202020202020285C2765385C2765
            645C2765385C2766365C2765385C2765305C2765625C2766622C205C2766345C
            2765305C2765635C2765385C2765625C2765385C276666292020202020202020
            2020202020202020202020202020202020202020202020202020202020202020
            2020202020202020202020202020202020202020205C7061720D0A5C66315C66
            7332365C6C616E67313033332020202020202020202020202020202020202020
            2020202020202020202020202020202020205C66305C6C616E67313034395C27
            63632E5C2763662E202020202020202020202020202020202020202020202020
            5C7061720D0A5C66315C6C616E67313033335C7061720D0A5C66305C6C616E67
            313034395C2763615C2765655C2765625C2765385C2766375C2765355C276631
            5C2766325C2765325C276565205C2765655C2765315C2766335C2766375C2765
            305C2766655C2766395C2765385C2766355C2766315C2766662C205C2765665C
            2766305C2765385C2766315C2766335C2766325C2766315C2766325C2765325C
            2765655C2765325C2765305C2765325C2766385C2765385C276635205C276564
            5C276530205C2765305C2766325C2766325C2765355C2766315C2766325C2765
            305C2766365C2765385C276538205F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5C70
            61720D0A5C66315C6C616E67313033335C7061720D0A5C66305C6C616E673130
            34395C2763615C2765655C2765625C2765385C2766375C2765355C2766315C27
            66325C2765325C276565205C2765655C2765315C2766335C2766375C2765305C
            2766655C2766395C2765385C2766355C2766315C2766662C205C2765665C2765
            655C2765625C2766335C2766375C2765385C2765325C2766385C2765385C2766
            35205C2765655C2766325C2765635C2765355C2766325C2765615C2765382020
            205C7061720D0A5C66315C6C616E67313033335C7061720D0A313020285C6630
            5C6C616E67313034395C2765345C2765355C2766315C2766665C2766325C2766
            6329205F5F5F5F5F5F20203820285C2765325C2765655C2766315C2765355C27
            65635C2766632920205F5F5F5F5F5F2020203520285C2765665C2766665C2766
            325C2766632920202020205F5F5F5F5F5F5F20203320285C2766325C2766305C
            2765382920205F5F5F5F5F5F5F5C7061720D0A5C66315C6C616E67313033335C
            7061720D0A3920285C66305C6C616E67313034395C2765345C2765355C276532
            5C2766665C2766325C276663292020205F5F5F5F5F5F20203720285C2766315C
            2765355C2765635C276663292020202020205F5F5F5F5F5F20203420285C2766
            375C2765355C2766325C2766625C2766305C2765352920205F5F5F5F5F5F5F20
            203220285C2765345C2765325C2765302920205F5F5F5F5F5F5F5C7061720D0A
            5C66315C6C616E67313033332020202020202020202020202020202020202020
            202020202020205C7061720D0A2020202020202020202020205C66305C6C616E
            673130343920205C66315C6C616E67313033332020202020202020205C66305C
            6C616E673130343920205C66315C6C616E67313033332020205C66305C6C616E
            673130343920205C66315C6C616E673130333320202020202020202020362028
            5C66305C6C616E67313034395C2766385C2765355C2766315C2766325C276663
            29202020205F5F5F5F5F5F202020202020202020202020202020202020202020
            2020202020202020202020202020203120285C2765655C2765345C2765385C27
            65642920205F5F5F5F5F5F5C7061720D0A5C66315C6C616E6731303333202020
            202020202020202020202020205C7061720D0A5C66305C6C616E67313034395C
            2763615C2765655C2765625C2765385C2766375C2765355C2766315C2766325C
            2765325C276565205C2765655C2765315C2766335C2766375C2765305C276665
            5C2766395C2765385C2766355C2766315C2766662C205C2765645C276535205C
            2766665C2765325C2765385C2765325C2766385C2765385C2766355C2766315C
            276666205C2765645C276530205C2765305C2766325C2766325C2765355C2766
            315C2766325C2765305C2766365C2765385C2766655C7061720D0A5C66315C6C
            616E673130333320205C7061720D0A285C66305C6C616E67313034395C276532
            205C2766325C2765655C276563205C2766375C2765385C2766315C2765625C27
            6535205C2765645C276535205C2765345C2765655C2765665C2766335C276639
            5C2765355C2765645C2765645C2766625C276635205C276561205C2765305C27
            66325C2766325C2765355C2766315C2766325C2765305C2766365C2765385C27
            653829205F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5C7061720D0A5C6631
            5C6C616E67313033332020202020202020202020202020202020202020202020
            20202020202020202020202020202020202020202020202020202020205C7061
            720D0A5C7061720D0A5C66305C667332345C6C616E67313034395C7061720D0A
            7D0D0A00}
        end
        object Memo50: TfrxMemoView
          Left = 400.630180000000000000
          Top = 41.574830000000000000
          Width = 162.519790000000000000
          Height = 18.897650000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -17
          Font.Name = 'Times New Roman'
          Font.Style = []
          HAlign = haCenter
          Memo.UTF8W = (
            '[frxDBDataset3."DEAN"]')
          ParentFont = False
        end
        object Memo2: TfrxMemoView
          Left = 56.692910940000000000
          Top = 377.952877950000000000
          Width = 627.401980000000000000
          Height = 71.811070000000000000
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Times New Roman'
          Font.Style = []
          Memo.UTF8W = (
            ''
            ''
            
              '*'#1044#1072#1090#1072' '#1087#1088#1086#1089#1090#1072#1074#1083#1103#1077#1090#1089#1103' '#1074' '#1082#1072#1078#1076#1086#1081' '#1089#1090#1088#1086#1082#1077', '#1077#1089#1083#1080' '#1072#1090#1090#1077#1089#1090#1072#1094#1080#1103' '#1086#1073#1091#1095#1072#1102#1097#1080#1093#1089#1103 +
              ' '#1087#1088#1086#1074#1086#1076#1080#1083#1072#1089#1100' '#1085#1077' '#1074' '#1086#1076#1080#1085' '#1076#1077#1085#1100)
          ParentFont = False
        end
        object Memo5: TfrxMemoView
          Left = 260.787570000000000000
          Width = 94.488250000000000000
          Height = 18.897650000000000000
        end
      end
      object Memo23: TfrxMemoView
        Left = 918.425790000000000000
        Top = 525.354670000000000000
        Width = 94.488250000000000000
        Height = 18.897650000000000000
      end
    end
  end
  object FDQuery1: TFDQuery
    Connection = DataModule1.FDConnection1
    SQL.Strings = (
      
        'select   VEDOMOST.N_FAC,  VEDOMOST.N_VEDOMOST,  VEDOMOST.SEMESTR' +
        '_VED,  VEDOMOST.FIO_EXAM,  VEDOMOST.END_D_EXAM,  VEDOMOST.D_VED,' +
        ' VEDOMOST.STATUS,'
      
        'EDU_PLAN.VID_EDU_PLAN, EDU_PLAN.CLOCK_PLAN_ALL, EDU_PLAN.YEAR_PL' +
        'AN, EDU_PLAN.CLOCK_PLAN, edu_plan.zach_exam,'
      'a.NAME_OBJECT,'
      
        'PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH, CAST(PEOPLE.N_ZACHET AS va' +
        'rchar(6)) as N_ZACHET, PEOPLE.N_GROUP,'
      'FACULTY.FAC1, FACULTY.DEAN'
      'from VEDOMOST, EDU_PLAN'
      ', OBJECT_PLAN a'
      ', EDU_CARD, PEOPLE, FACULTY'
      'where VEDOMOST.N_PLAN = EDU_PLAN.N_PLAN'
      'and EDU_PLAN.N_OBJECT = a.N_OBJECT'
      'and VEDOMOST.N_VED = EDU_CARD.N_VED'
      'and EDU_CARD.NOMER = PEOPLE.NOMER'
      'and EDU_PLAN.N_FAC = FACULTY.N_FAC'
      'and VEDOMOST.N_VED = :N_VED'
      ' AND (Vedomost.INVALID = 0)'
      'order by PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH')
    Left = 232
    Top = 40
    ParamData = <
      item
        Name = 'N_VED'
        DataType = ftInteger
        ParamType = ptInput
        Value = Null
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
    object FDQuery1STATUS: TSmallintField
      FieldName = 'STATUS'
      Origin = 'STATUS'
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
    object FDQuery1YEAR_PLAN: TSmallintField
      AutoGenerateValue = arDefault
      FieldName = 'YEAR_PLAN'
      Origin = 'YEAR_PLAN'
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
      Size = 10
    end
    object FDQuery1FAC1: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'FAC1'
      Origin = 'FAC1'
      ProviderFlags = []
      ReadOnly = True
    end
    object FDQuery1N_GROUP: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'N_GROUP'
      Origin = 'N_GROUP'
      ProviderFlags = []
      ReadOnly = True
      Size = 10
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
    Connection = DataModule1.FDConnection1
    SQL.Strings = (
      
        'select   VEDOMOST.N_FAC,  VEDOMOST.N_VEDOMOST,  VEDOMOST.SEMESTR' +
        '_VED,  VEDOMOST.FIO_EXAM,  VEDOMOST.END_D_EXAM,  VEDOMOST.D_VED,' +
        ' VEDOMOST.STATUS,'
      
        'EDU_PLAN.VID_EDU_PLAN, EDU_PLAN.CLOCK_PLAN_ALL, EDU_PLAN.YEAR_PL' +
        'AN, EDU_PLAN.CLOCK_PLAN, edu_plan.zach_exam,'
      'a.NAME_OBJECT,'
      'y.PERC_SUB_PLAN, b.NAME_OBJECT,'
      'z.PERC_SUB_PLAN, c.NAME_OBJECT,'
      
        'PEOPLE.FAM, PEOPLE.NAME, PEOPLE.OTCH, CAST(PEOPLE.N_ZACHET AS CH' +
        'AR(6)) as N_ZACHET, PEOPLE.N_GROUP,'
      'FACULTY.FAC1, FACULTY.DEAN'
      'from VEDOMOST, EDU_PLAN'
      ', OBJECT_PLAN a'
      ', SUB_EDU_PLAN y, OBJECT_PLAN b, SUB_EDU_PLAN z, OBJECT_PLAN c'
      ', EDU_CARD, PEOPLE, FACULTY'
      'where VEDOMOST.N_PLAN = EDU_PLAN.N_PLAN'
      'and EDU_PLAN.N_OBJECT = a.N_OBJECT'
      'and EDU_PLAN.N_PLAN = y.N_PLAN_PARENT'
      'and EDU_PLAN.N_PLAN = z.N_PLAN_PARENT'
      'and y.N_OBJECT = b.N_OBJECT'
      'and z.N_OBJECT = c.N_OBJECT'
      'and VEDOMOST.N_VED = EDU_CARD.N_VED'
      'and EDU_CARD.NOMER = PEOPLE.NOMER'
      'and EDU_PLAN.N_FAC = FACULTY.N_FAC'
      'and y.N_PLAN <> z.N_PLAN'
      'and VEDOMOST.N_VED = :N_VED'
      ' AND (Vedomost.INVALID = 0)'
      '')
    Left = 376
    Top = 40
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
    object FDQuery3STATUS: TSmallintField
      FieldName = 'STATUS'
      Origin = 'STATUS'
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
    object FDQuery3YEAR_PLAN: TSmallintField
      AutoGenerateValue = arDefault
      FieldName = 'YEAR_PLAN'
      Origin = 'YEAR_PLAN'
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
      FixedChar = True
      Size = 6
    end
    object FDQuery3FAC1: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'FAC1'
      Origin = 'FAC1'
      ProviderFlags = []
      ReadOnly = True
    end
    object FDQuery3N_GROUP: TStringField
      AutoGenerateValue = arDefault
      FieldName = 'N_GROUP'
      Origin = 'N_GROUP'
      ProviderFlags = []
      ReadOnly = True
      Size = 10
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
    Left = 232
    Top = 88
  end
  object DataSource3: TDataSource
    DataSet = FDQuery3
    Left = 376
    Top = 88
  end
  object frxDBDataset3: TfrxDBDataset
    UserName = 'frxDBDataset3'
    CloseDataSource = False
    FieldAliases.Strings = (
      'N_FAC=N_FAC'
      'N_VEDOMOST=N_VEDOMOST'
      'SEMESTR_VED=SEMESTR_VED'
      'FIO_EXAM=FIO_EXAM'
      'END_D_EXAM=END_D_EXAM'
      'D_VED=D_VED'
      'STATUS=STATUS'
      'VID_EDU_PLAN=VID_EDU_PLAN'
      'CLOCK_PLAN_ALL=CLOCK_PLAN_ALL'
      'YEAR_PLAN=YEAR_PLAN'
      'CLOCK_PLAN=CLOCK_PLAN'
      'ZACH_EXAM=ZACH_EXAM'
      'NAME_OBJECT=NAME_OBJECT'
      'PERC_SUB_PLAN=PERC_SUB_PLAN'
      'NAME_OBJECT_1=NAME_OBJECT_1'
      'PERC_SUB_PLAN_1=PERC_SUB_PLAN_1'
      'NAME_OBJECT_2=NAME_OBJECT_2'
      'FAM=FAM'
      'NAME=NAME'
      'OTCH=OTCH'
      'N_ZACHET=N_ZACHET'
      'FAC1=FAC1'
      'N_GROUP=N_GROUP'
      'DEAN=DEAN')
    DataSource = DataSource3
    BCDToCurrency = False
    Left = 376
    Top = 136
  end
  object FDQuery5: TFDQuery
    Connection = DataModule1.FDConnection1
    SQL.Strings = (
      
        'select count(sub_edu_plan.n_plan) from sub_edu_plan, edu_plan, v' +
        'edomost'
      'where sub_edu_plan.n_plan_parent = edu_plan.n_plan'
      'and edu_plan.n_plan = vedomost.n_plan'
      'and vedomost.n_ved = :n_ved'
      ' AND (Vedomost.INVALID = 0)')
    Left = 592
    Top = 56
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
end

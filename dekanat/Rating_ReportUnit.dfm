object Rating_ReportForm: TRating_ReportForm
  Left = 243
  Top = 22
  ClientHeight = 701
  ClientWidth = 963
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Scaled = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object frxReport1: TfrxReport
    Version = '4.15.10'
    DotMatrixReport = False
    IniFile = '\Software\Fast Reports'
    PreviewOptions.Buttons = [pbPrint, pbLoad, pbSave, pbExport, pbZoom, pbFind, pbOutline, pbPageSetup, pbTools, pbEdit, pbNavigator, pbExportQuick]
    PreviewOptions.Zoom = 1.000000000000000000
    PrintOptions.Printer = 'Default'
    PrintOptions.PrintOnSheet = 0
    ReportOptions.CreateDate = 42671.634948055560000000
    ReportOptions.LastChange = 42671.634948055560000000
    ScriptLanguage = 'PascalScript'
    ScriptText.Strings = (
      'begin'
      ''
      'end.')
    Left = 160
    Top = 56
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
      object ReportTitle1: TfrxReportTitle
        Height = 200.315090000000000000
        Top = 18.897650000000000000
        Width = 718.110700000000000000
        object Memo1: TfrxMemoView
          Left = 36.661417320000000000
          Top = 1.889763780000000000
          Width = 613.417322830000000000
          Height = 19.275590550000000000
          ShowHint = False
          Memo.UTF8W = (
            #1041#1045#1051#1054#1056#1059#1057#1057#1050#1048#1049' '#1043#1054#1057#1059#1044#1040#1056#1057#1058#1042#1045#1053#1053#1067#1049' '#1059#1053#1048#1042#1045#1056#1057#1048#1058#1045#1058' '#1060#1048#1047#1048#1063#1045#1057#1050#1054#1049' '#1050#1059#1051#1068#1058#1059#1056#1067)
        end
        object Memo2: TfrxMemoView
          Left = 271.748031500000000000
          Top = 27.968503940000000000
          Width = 145.889763780000000000
          Height = 21.921259840000000000
          ShowHint = False
          Memo.UTF8W = (
            #1042#1045#1044#1054#1052#1054#1057#1058#1068' '#8470' [frxDBDataset1."N_VEDOMOST_R"]')
        end
        object Memo3: TfrxMemoView
          Left = 155.338582680000000000
          Top = 46.110236220000000000
          Width = 377.952755910000000000
          Height = 21.921259840000000000
          ShowHint = False
          Memo.UTF8W = (
            #1088#1077#1081#1090#1080#1085#1075#1086#1074#1086#1081' '#1086#1094#1077#1085#1082#1080' '#1076#1077#1103#1090#1077#1083#1100#1085#1086#1089#1090#1080' '#1089#1090#1091#1076#1077#1085#1090#1086#1074)
        end
        object Memo4: TfrxMemoView
          Top = 92.976377950000000000
          Width = 77.858267720000000000
          Height = 18.141732280000000000
          ShowHint = False
          Memo.UTF8W = (
            #1060#1072#1082#1091#1083#1100#1090#1077#1090)
        end
        object Memo5: TfrxMemoView
          Left = 342.803149610000000000
          Top = 92.976377950000000000
          Width = 69.165354330000000000
          Height = 17.385826770000000000
          ShowHint = False
          Memo.UTF8W = (
            '[frxDBDataset1."SEMESTR"]')
        end
        object Memo6: TfrxMemoView
          Left = 94.110236220000000000
          Top = 92.976377950000000000
          Width = 36.661417320000000000
          Height = 19.275590550000000000
          ShowHint = False
          Memo.UTF8W = (
            '[frxDBDataset1."FAC1"]')
        end
        object Memo7: TfrxMemoView
          Left = 504.944881890000000000
          Top = 92.976377950000000000
          Width = 32.503937010000000000
          Height = 18.141732280000000000
          ShowHint = False
          Memo.UTF8W = (
            #1050#1091#1088#1089)
        end
        object Memo8: TfrxMemoView
          Left = 254.362204720000000000
          Top = 92.976377950000000000
          Width = 77.858267720000000000
          Height = 18.141732280000000000
          ShowHint = False
          Memo.UTF8W = (
            #1057#1077#1084#1077#1089#1090#1088)
        end
        object Memo9: TfrxMemoView
          Left = 561.637795280000000000
          Top = 92.976377950000000000
          Width = 20.031496060000000000
          Height = 17.385826770000000000
          ShowHint = False
          Memo.UTF8W = (
            '[Int((<frxDBDataset1."SEMESTR">+1))]')
        end
        object Memo10: TfrxMemoView
          Top = 116.031496060000000000
          Width = 49.133858270000000000
          Height = 18.141732280000000000
          ShowHint = False
          Memo.UTF8W = (
            #1043#1088#1091#1087#1087#1072)
        end
        object Memo11: TfrxMemoView
          Left = 94.110236220000000000
          Top = 116.031496060000000000
          Width = 69.921259840000000000
          Height = 19.275590550000000000
          ShowHint = False
          Memo.UTF8W = (
            '[<frxDBDataset1."N_GROUP">] [<frxDBDataset1."SPECIAL">]')
        end
        object Memo12: TfrxMemoView
          Top = 139.086614170000000000
          Width = 233.196850390000000000
          Height = 19.275590550000000000
          ShowHint = False
          Memo.UTF8W = (
            #1060#1072#1084#1080#1083#1080#1103', '#1080#1084#1103', '#1086#1090#1095#1077#1089#1090#1074#1086' '#1082#1091#1088#1072#1090#1086#1088#1072':')
        end
        object Memo14: TfrxMemoView
          Left = 136.440944880000000000
          Top = 168.944881890000000000
          Width = 302.740264880000000000
          Height = 18.141732280000000000
          ShowHint = False
          Memo.UTF8W = (
            
              #1044#1072#1090#1072' '#1079#1072#1087#1086#1083#1085#1077#1085#1080#1103': '#1089' [frxDBDataset1."D_VED"] '#1087#1086' [frxDBDataset1."EN' +
              'D_D_VED"]')
        end
        object Memo15: TfrxMemoView
          Left = 251.338582680000000000
          Top = 140.976377950000000000
          Width = 71.055118110000000000
          Height = 19.275590550000000000
          ShowHint = False
          Memo.UTF8W = (
            '[frxDBDataset1."CURATOR"]')
        end
        object Memo21: TfrxMemoView
          Left = 156.094390550000000000
          Top = 66.141732280000000000
          Width = 376.063189840000000000
          Height = 19.275590550000000000
          ShowHint = False
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clBlack
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold, fsItalic]
          Memo.UTF8W = (
            
              #1087#1086' '#1080#1090#1086#1075#1072#1084' [frxDBDataset1."SESSION"] '#1087#1086#1083#1091#1075#1086#1076#1080#1103' [frxDBDataset1."UC' +
              'H_GOD"] / [<frxDBDataset1."UCH_GOD">+1] '#1091#1095#1077#1073#1085#1086#1075#1086' '#1075#1086#1076#1072)
          ParentFont = False
        end
      end
      object Header1: TfrxHeader
        Height = 37.795300000000000000
        Top = 279.685220000000000000
        Width = 718.110700000000000000
        object Memo13: TfrxMemoView
          Left = 3.779530000000000000
          Width = 22.677180000000000000
          Height = 37.795300000000000000
          ShowHint = False
          Memo.UTF8W = (
            #8470' n/n')
        end
        object Memo16: TfrxMemoView
          Left = 26.456710000000000000
          Width = 570.709030000000000000
          Height = 41.574830000000000000
          ShowHint = False
          Memo.UTF8W = (
            #1060#1040#1052#1048#1051#1048#1071', '#1048#1052#1071', '#1054#1058#1063#1045#1057#1058#1042#1054)
        end
        object Memo17: TfrxMemoView
          Left = 597.165740000000000000
          Width = 120.944960000000000000
          Height = 34.015770000000000000
          ShowHint = False
          Memo.UTF8W = (
            #1054#1073#1097#1077#1077' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1073#1072#1083#1083#1086#1074' '#1079#1072' '#1089#1077#1084#1077#1089#1090#1088)
        end
      end
      object MasterData1: TfrxMasterData
        Height = 41.574830000000000000
        Top = 340.157700000000000000
        Width = 718.110700000000000000
        DataSet = frxDBDataset1
        DataSetName = 'frxDBDataset1'
        RowCount = 0
        object Memo18: TfrxMemoView
          Left = 593.386210000000000000
          Top = 3.779530000000000000
          Width = 120.944960000000000000
          Height = 34.015770000000000000
          ShowHint = False
        end
        object Memo19: TfrxMemoView
          Width = 22.677180000000000000
          Height = 37.795300000000000000
          ShowHint = False
          Memo.UTF8W = (
            '[Line]')
        end
        object Memo20: TfrxMemoView
          Left = 22.677180000000000000
          Width = 570.709030000000000000
          Height = 41.574830000000000000
          ShowHint = False
          Memo.UTF8W = (
            
              '[<frxDBDataset1."FAM">] [<frxDBDataset1."NAME">] [<frxDBDataset1' +
              '."OTCH">]')
        end
      end
      object Footer1: TfrxFooter
        Height = 79.370130000000000000
        Top = 404.409710000000000000
        Width = 718.110700000000000000
        object Rich1: TfrxRichView
          Width = 718.110700000000000000
          Height = 75.590600000000000000
          ShowHint = False
          GapX = 2.000000000000000000
          GapY = 1.000000000000000000
          RichEdit = {
            7B5C727466315C616E73695C616E7369637067313235315C64656666305C6E6F
            7569636F6D7061745C6465666C616E67313034397B5C666F6E7474626C7B5C66
            305C666E696C5C66636861727365743230347B5C2A5C666E616D652041726961
            6C3B7D417269616C204359523B7D7D0D0A7B5C2A5C67656E657261746F722052
            696368656432302031302E302E31303234307D5C766965776B696E64345C7563
            31200D0A5C706172645C625C66305C667332305C2763665C2765655C2765345C
            2765665C2765385C2766315C276663205C2765615C2766335C2766305C276530
            5C2766325C2765655C2766305C2765305F5F5F5F5F5F5F5F5F5F5F5F5F5F5F5F
            5F5F5F5F5F5F5C7061720D0A5C7061720D0A5C2763345C2765305C2766325C27
            6530205C2766315C2765345C2765305C2766375C276538205C2765325C276535
            5C2765345C2765355C2765325C2765655C2766315C2766325C2765385F5F5F5F
            5F5F5F5F5F5F5F5F5F5F5F5F5F5F5C7061720D0A7D0D0A00}
        end
      end
    end
  end
  object frxDBDataset1: TfrxDBDataset
    UserName = 'frxDBDataset1'
    CloseDataSource = False
    DataSet = DataModule1.Rating_ReportQuery
    BCDToCurrency = False
    Left = 256
    Top = 56
  end
end

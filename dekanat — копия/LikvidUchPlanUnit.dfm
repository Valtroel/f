object LikvidUchPlanForm: TLikvidUchPlanForm
  Left = 649
  Top = 89
  BorderIcons = [biSystemMenu]
  Caption = #1042#1099#1073#1086#1088' '#1091#1095#1077#1095#1085#1086#1075#1086' '#1087#1083#1072#1085#1072' '#1076#1083#1103' '#1083#1080#1082#1074#1080#1076#1072#1094#1080#1080' '#1088#1072#1079#1085#1086#1089#1090#1080
  ClientHeight = 395
  ClientWidth = 989
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poMainFormCenter
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 393
    Top = 89
    Height = 259
    ExplicitLeft = 481
    ExplicitTop = 95
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 989
    Height = 89
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object Label1: TLabel
      Left = 288
      Top = 18
      Width = 178
      Height = 13
      Caption = #1053#1072#1087#1088#1072#1074#1083#1077#1085#1080#1077' '#1089#1087#1077#1094#1080#1072#1083#1100#1085#1086#1089#1090#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object RadioGroup1: TRadioGroup
      Left = 16
      Top = 11
      Width = 121
      Height = 64
      Caption = #1060#1086#1088#1084#1072' '#1086#1073#1091#1095#1077#1085#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        #1044#1085#1077#1074#1085#1072#1103
        #1047#1072#1086#1095#1085#1072#1103)
      ParentFont = False
      TabOrder = 0
      OnClick = RadioGroup1Click
    end
    object RadioGroup2: TRadioGroup
      Left = 144
      Top = 11
      Width = 121
      Height = 64
      Caption = #1053#1072' '#1082#1072#1082#1086#1081' '#1082#1091#1088#1089':'
      Columns = 2
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        '1'
        '2'
        '3'
        '4'
        '5'
        '6')
      ParentFont = False
      TabOrder = 1
      Visible = False
      OnClick = RadioGroup2Click
    end
    object DBLookupComboBox1: TDBLookupComboBox
      Left = 288
      Top = 33
      Width = 321
      Height = 21
      KeyField = 'N_SPECIALIZ'
      ListField = 'SPECIAL'
      ListSource = DataModule1.SpecializQSource
      TabOrder = 2
      Visible = False
      OnClick = DBLookupComboBox1Click
    end
    object BitBtn1: TBitBtn
      Left = 623
      Top = 27
      Width = 105
      Height = 33
      Caption = #1042#1099#1073#1088#1072#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        96010000424D9601000000000000760000002800000018000000180000000100
        0400000000002001000000000000000000001000000000000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333333888888888888888333333330000000000000008833333
        30BBBBBBBBBBBBBBB083333330B8000000000008B083333330B0FFFFFFFFFFF0
        B08333334FB0F777777777F0B083333344F0FFFFFFFFFFF0B0833333444F7FFF
        FFFFFFF0B08334444444F7FF777777F0B083344444444F7FFFFFFFF0B0833444
        444444F7FFFFFFF0B083344444444F7FF77777F0B08334444444F7FFFFFFFFF0
        B0833333444F7FFFFFFFFFF0B083333344F0FF77777777F0B08333334FB0FFFF
        FFFFFFF0B083333330B0FFFFFFFFFFF0B083333330B0FF0000000FF0B0833333
        30B80007F7770008B083333330BBBBB07F70BBBBB03333333300000007000000
        0333333333333330F77033333333333333333330000033333333}
      ParentFont = False
      TabOrder = 3
      Visible = False
      OnClick = BitBtn1Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 89
    Width = 393
    Height = 259
    Align = alLeft
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    Visible = False
    object DBGrid1: TDBGrid
      Left = 2
      Top = 2
      Width = 389
      Height = 255
      Align = alClient
      DataSource = DM3.Svod_NadoSource
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
      ReadOnly = True
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
      OnDblClick = DBGrid1DblClick
      Columns = <
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'SEMESTR'
          Title.Alignment = taCenter
          Title.Caption = #1057#1077#1084#1077#1089#1090#1088
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 58
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NAME_OBJECT'
          Title.Alignment = taCenter
          Title.Caption = #1055#1088#1077#1076#1084#1077#1090
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 133
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'ZACH_EXAM1'
          Title.Alignment = taCenter
          Title.Caption = #1042#1080#1076' '#1082#1086#1085#1090#1088#1086#1083#1103
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 88
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'CLOCK_PLAN'
          Title.Alignment = taCenter
          Title.Caption = #1047#1072#1095'. '#1077#1076
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'CLOCK_PLAN_ALL'
          Title.Caption = #1042#1089#1077#1075#1086' '#1095#1072#1089#1086#1074
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'YEAR1'
          Title.Alignment = taCenter
          Title.Caption = #1059#1095'.'#1075#1086#1076
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Visible = True
        end>
    end
  end
  object Panel3: TPanel
    Left = 396
    Top = 89
    Width = 593
    Height = 259
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 2
    Visible = False
    object Panel5: TPanel
      Left = 2
      Top = 2
      Width = 31
      Height = 255
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 0
      object SpeedButton1: TSpeedButton
        Left = 4
        Top = 92
        Width = 23
        Height = 23
        Hint = #1042#1099#1073#1088#1072#1090#1100' '#1090#1077#1082#1091#1097#1091#1102' '#1079#1072#1087#1080#1089#1100
        Glyph.Data = {
          DE000000424DDE0000000000000076000000280000000D0000000D0000000100
          0400000000006800000000000000000000001000000010000000000000000000
          BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
          7000777777077777700077777700777770007777770607777000770000066077
          7000770666666607700077066666666070007706666666077000770000066077
          7000777777060777700077777700777770007777770777777000777777777777
          7000}
        ParentShowHint = False
        ShowHint = True
        Spacing = 0
        OnClick = SpeedButton1Click
      end
      object SpeedButton2: TSpeedButton
        Left = 4
        Top = 145
        Width = 23
        Height = 23
        Hint = #1042#1099#1073#1088#1072#1090#1100' '#1074#1089#1077' '#1079#1072#1087#1080#1089#1080
        Glyph.Data = {
          DE000000424DDE0000000000000076000000280000000D0000000D0000000100
          0400000000006800000000000000000000001000000010000000000000000000
          BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
          7000777707707777700077770070077770007777060060777000000006606607
          7000066666660660700006666666606600000666666606607000000006606607
          7000777706006077700077770070077770007777077077777000777777777777
          7000}
        ParentShowHint = False
        ShowHint = True
        Spacing = 0
        OnClick = SpeedButton2Click
      end
      object SpeedButton3: TSpeedButton
        Left = 4
        Top = 199
        Width = 23
        Height = 23
        Hint = #1059#1076#1072#1083#1080#1090#1100' '#1089#1090#1088#1086#1082#1091', '#1074' '#1082#1086#1090#1086#1088#1086#1081' '#1085#1072#1093#1086#1076#1080#1090#1089#1103' '#1082#1091#1088#1089#1086#1088
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
        ParentShowHint = False
        ShowHint = True
        Spacing = 0
        OnClick = SpeedButton3Click
      end
    end
    object Memo1: TMemo
      Left = 33
      Top = 2
      Width = 558
      Height = 255
      Align = alClient
      ScrollBars = ssBoth
      TabOrder = 1
    end
  end
  object Panel4: TPanel
    Left = 0
    Top = 348
    Width = 989
    Height = 47
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 3
    Visible = False
    object BitBtn2: TBitBtn
      Left = 40
      Top = 7
      Width = 105
      Height = 33
      Hint = #1055#1077#1088#1077#1076#1072#1090#1100' '#1074' Excel '#1074#1089#1077' '#1087#1088#1077#1076#1084#1077#1090#1099' '#1091#1095#1077#1073#1085#1086#1075#1086' '#1087#1083#1072#1085#1072' '#1079#1072' '#1074#1099#1073#1088#1072#1085#1085#1099#1081' '#1082#1091#1088#1089
      Caption = #1055#1077#1088#1077#1076#1072#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        4E010000424D4E01000000000000760000002800000012000000120000000100
        040000000000D800000000000000000000001000000010000000000000000000
        BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
        7777770000007777777777777777770000007777777777770007770000007444
        4400000006007700000074FFFF08880600080700000074F008000060EE070700
        000074FFFFF8060EE0047700000074F0088060EE00F47700000074FFFF060EE0
        00747700000074F00800EE0EE0047700000074FFFF0EE0F0EE047700000074F0
        080000F000047700000074FFFFFFFFFFFFF47700000074444444444444447700
        000074F444F444F444F477000000744444444444444477000000777777777777
        777777000000777777777777777777000000}
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnClick = BitBtn2Click
    end
    object BitBtn3: TBitBtn
      Left = 431
      Top = 7
      Width = 105
      Height = 33
      Hint = #1055#1077#1088#1077#1076#1072#1090#1100' '#1074' Word '#1074#1099#1073#1088#1072#1085#1085#1099#1077' '#1087#1088#1077#1076#1084#1077#1090#1099' '#1091#1095#1077#1073#1085#1086#1075#1086' '#1087#1083#1072#1085#1072
      Caption = #1055#1077#1088#1077#1076#1072#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        7E010000424D7E01000000000000760000002800000018000000160000000100
        0400000000000801000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00800000000000
        0000000000080777777777777777777777700F77777777777777777777700F88
        888888888888888887700F88888880008888888887700F888888066008888888
        87700F8888880660E088888887700F888880660EE000888887700F888880660E
        E0EE088887700F88880660EEE0EE088887700F88880660E0EEEE088887700F88
        80660EE0EEEE088887700F8880000E00EE0E088887700F8880666060EE0E0888
        87700F8888000000E00E088887700F8888880666060E088887700F8888888000
        000E088887700F88888888880660088887700F88888888888000088887700F88
        888888888888888887700FFFFFFFFFFFFFFFFFFFFF7080000000000000000000
        0008}
      Margin = 4
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      OnClick = BitBtn3Click
    end
    object BitBtn4: TBitBtn
      Left = 190
      Top = 6
      Width = 75
      Height = 25
      Caption = '2'
      TabOrder = 2
      OnClick = BitBtn4Click
    end
  end
end

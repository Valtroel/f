object VipusknikiForm: TVipusknikiForm
  Left = 239
  Top = 181
  BorderIcons = [biSystemMenu, biMaximize]
  Caption = #1057#1087#1080#1089#1086#1082' '#1074#1099#1087#1091#1089#1082#1085#1080#1082#1086#1074
  ClientHeight = 497
  ClientWidth = 1017
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
  OnActivate = FormActivate
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter2: TSplitter
    Left = 0
    Top = 350
    Width = 1017
    Height = 2
    Cursor = crVSplit
    Align = alBottom
    Color = clTeal
    ParentColor = False
    Visible = False
    ExplicitTop = 326
    ExplicitWidth = 692
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1017
    Height = 73
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object Label13: TLabel
      Left = 669
      Top = 14
      Width = 27
      Height = 13
      Caption = #1055#1091#1090#1100':'
    end
    object RadioGroup1: TRadioGroup
      Left = 16
      Top = 5
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
        #1047#1072#1086#1095#1085#1072#1103
        #1074#1089#1077)
      ParentFont = False
      TabOrder = 0
      OnClick = RadioGroup1Click
    end
    object BitBtn1: TBitBtn
      Left = 447
      Top = 21
      Width = 121
      Height = 33
      Hint = #1055#1086#1082#1072#1079#1072#1090#1100' '#1074#1099#1087#1091#1089#1082#1085#1080#1082#1086#1074' '#1087#1086' '#1074#1099#1073#1088#1072#1085#1085#1099#1084' '#1082#1088#1080#1090#1077#1088#1080#1103#1084
      Caption = #1055#1086#1082#1072#1079#1072#1090#1100
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
        33333333333333338888888888888833333333000000000000000883333330BB
        BBBBBBBBBBBBB083333330B0000000000000B083333330B0F9FFFFFFFFF0B083
        333330B04444444444F0B033333330B0F9FFFFFFFFF0B393333330B0F9FFFFFF
        FFF0B399333330B044444444FFFFF399933330B0F9FFFFFFF9999999993330B0
        F9FFFFFFF9999999999330B044444444F9999999993330B0F9FFFFFFFFFFF399
        933330B0F9FFFFFFFFF0B399333330B04444444444F0B393333330B0F9FFFFFF
        FFF0B033333330B0F9FFFFFFFFF0B083333330B0F90000000FF0B083333330B0
        0007F7770000B083333330BBBBB07F70BBBBB033333333000000070000000333
        333333333330F770333333333333333333300000333333333333}
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      OnClick = BitBtn1Click
    end
    object RadioGroup3: TRadioGroup
      Left = 143
      Top = 4
      Width = 107
      Height = 65
      Caption = #1055#1077#1088#1080#1086#1076' '#1074#1099#1073#1086#1088#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ItemIndex = 1
      Items.Strings = (
        #1047#1072' '#1087#1077#1088#1080#1086#1076
        #1047#1072' '#1075#1086#1076)
      ParentFont = False
      TabOrder = 2
      OnClick = RadioGroup3Click
    end
    object Panel10: TPanel
      Left = 256
      Top = 9
      Width = 163
      Height = 56
      TabOrder = 3
      object Label11: TLabel
        Left = 0
        Top = 33
        Width = 26
        Height = 13
        Caption = #1043#1086#1076':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        Visible = False
      end
      object Label12: TLabel
        Left = 17
        Top = 14
        Width = 8
        Height = 13
        Caption = #1089
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        Visible = False
      end
      object DateTimePicker3: TDateTimePicker
        Left = 31
        Top = 6
        Width = 129
        Height = 21
        Date = 43234.615653240740000000
        Time = 43234.615653240740000000
        TabOrder = 0
      end
      object DateTimePicker4: TDateTimePicker
        Left = 31
        Top = 33
        Width = 129
        Height = 21
        Date = 43234.615653240740000000
        Time = 43234.615653240740000000
        TabOrder = 1
      end
    end
    object Panel11: TPanel
      Left = 256
      Top = 13
      Width = 185
      Height = 56
      TabOrder = 4
      object Label8: TLabel
        Left = 0
        Top = 19
        Width = 128
        Height = 13
        Caption = #1043#1086#1076' '#1086#1082#1086#1085#1095#1072#1085#1080#1103' '#1042#1059#1047#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Edit4: TEdit
        Left = 129
        Top = 16
        Width = 37
        Height = 21
        ReadOnly = True
        TabOrder = 0
        Text = '2000'
      end
      object UpDown1: TUpDown
        Left = 166
        Top = 16
        Width = 15
        Height = 21
        Associate = Edit4
        Min = 2000
        Max = 3000
        Position = 2000
        TabOrder = 1
        Thousands = False
        OnClick = UpDown1Click
      end
    end
    object BitBtn3: TBitBtn
      Left = 574
      Top = 21
      Width = 89
      Height = 34
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
      TabOrder = 5
      OnClick = BitBtn3Click
    end
    object ProgressBar1: TProgressBar
      Left = 669
      Top = 38
      Width = 337
      Height = 27
      TabOrder = 6
    end
    object Edit7: TEdit
      Left = 702
      Top = 11
      Width = 223
      Height = 21
      TabOrder = 7
    end
    object Button1: TButton
      Left = 931
      Top = 9
      Width = 75
      Height = 25
      Caption = #1048#1079#1084#1077#1085#1080#1090#1100
      TabOrder = 8
      OnClick = Button1Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 73
    Width = 1017
    Height = 277
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    object DBGrid1: TDBGrid
      Left = 2
      Top = 2
      Width = 1013
      Height = 246
      Align = alClient
      DataSource = DM3.DSVipuskniki
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
      ReadOnly = True
      TabOrder = 1
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
      OnCellClick = DBGrid1CellClick
      OnDblClick = DBGrid1DblClick
      OnKeyDown = DBGrid1KeyDown
      OnKeyUp = DBGrid1KeyDown
      Columns = <
        item
          Expanded = False
          FieldName = 'FAM'
          Title.Alignment = taCenter
          Title.Caption = #1060#1072#1084#1080#1083#1080#1103
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 117
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'NAME'
          Title.Alignment = taCenter
          Title.Caption = #1048#1084#1103
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 67
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'OTCH'
          Title.Alignment = taCenter
          Title.Caption = #1054#1090#1095#1077#1089#1090#1074#1086
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 99
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'DATA1'
          Title.Alignment = taCenter
          Title.Caption = #1043#1086#1076' '#1087#1086#1089#1090#1091#1087#1083#1077#1085#1080#1103
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
          FieldName = 'D_PRIKAZ_KURS'
          Title.Alignment = taCenter
          Title.Caption = #1044#1072#1090#1072' '#1086#1082#1086#1085#1095#1072#1085#1080#1103
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 105
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'SPECIALIZ1'
          Title.Alignment = taCenter
          Title.Caption = #1057#1087#1077#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 277
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'SPEC1'
          Title.Alignment = taCenter
          Title.Caption = #1057#1087#1077#1094#1080#1072#1083#1100#1085#1086#1089#1090#1100
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 257
          Visible = True
        end>
    end
    object Panel8: TPanel
      Left = 2
      Top = 248
      Width = 1013
      Height = 27
      Align = alBottom
      BevelOuter = bvNone
      TabOrder = 0
      object Label7: TLabel
        Left = 9
        Top = 7
        Width = 117
        Height = 13
        Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1092#1072#1084#1080#1083#1080#1080':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object CheckBox1: TCheckBox
        Left = 448
        Top = 5
        Width = 234
        Height = 17
        Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1102' '#1087#1086' '#1076#1080#1087#1083#1086#1084#1091
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnClick = CheckBox1Click
      end
      object Edit3: TEdit
        Left = 128
        Top = 3
        Width = 289
        Height = 21
        TabOrder = 0
        OnChange = Edit3Change
      end
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 352
    Width = 1017
    Height = 145
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 2
    Visible = False
    object Panel4: TPanel
      Left = 331
      Top = 2
      Width = 684
      Height = 141
      Align = alClient
      BevelInner = bvLowered
      TabOrder = 1
      object Splitter1: TSplitter
        Left = 121
        Top = 2
        Width = 2
        Height = 137
        Color = clTeal
        ParentColor = False
      end
      object Panel5: TPanel
        Left = 123
        Top = 2
        Width = 36
        Height = 137
        Align = alLeft
        BevelInner = bvRaised
        BevelOuter = bvLowered
        TabOrder = 1
        object SpeedButton1: TSpeedButton
          Left = 7
          Top = 28
          Width = 23
          Height = 22
          Hint = #1055#1077#1088#1077#1085#1077#1089#1090#1080' '#1074#1074#1077#1088#1093
          Glyph.Data = {
            DE000000424DDE0000000000000076000000280000000D0000000D0000000100
            0400000000006800000000000000000000001000000010000000000000000000
            BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
            7000777777777777700077770000077770007777066607777000777706660777
            7000777706660777700070000666000070007706666666077000777066666077
            7000777706660777700077777060777770007777770777777000777777777777
            7000}
          ParentShowHint = False
          ShowHint = True
          OnClick = SpeedButton1Click
        end
        object SpeedButton2: TSpeedButton
          Left = 7
          Top = 49
          Width = 23
          Height = 22
          Hint = #1055#1077#1088#1077#1085#1077#1089#1090#1080' '#1074#1085#1080#1079
          Glyph.Data = {
            DE000000424DDE0000000000000076000000280000000D0000000D0000000100
            0400000000006800000000000000000000001000000010000000000000000000
            BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
            7000777777777777700077777707777770007777706077777000777706660777
            7000777066666077700077066666660770007000066600007000777706660777
            7000777706660777700077770666077770007777000007777000777777777777
            7000}
          ParentShowHint = False
          ShowHint = True
          OnClick = SpeedButton2Click
        end
        object SpeedButton3: TSpeedButton
          Left = 7
          Top = 87
          Width = 23
          Height = 22
          Hint = #1059#1073#1088#1072#1090#1100' '#1074#1099#1073#1088#1072#1085#1085#1086#1077
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
          OnClick = SpeedButton3Click
        end
        object SpeedButton4: TSpeedButton
          Left = 7
          Top = 108
          Width = 23
          Height = 22
          Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074#1099#1073#1088#1072#1085#1085#1086#1077
          Glyph.Data = {
            DE000000424DDE0000000000000076000000280000000D0000000D0000000100
            0400000000006800000000000000000000001000000010000000000000000000
            BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
            FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
            7000777777077777700077777007777770007777060777777000777066000007
            7000770666666607700070666666660770007706666666077000777066000007
            7000777706077777700077777007777770007777770777777000777777777777
            7000}
          ParentShowHint = False
          ShowHint = True
          OnClick = SpeedButton4Click
        end
      end
      object Panel6: TPanel
        Left = 2
        Top = 2
        Width = 119
        Height = 137
        Align = alLeft
        BevelOuter = bvNone
        TabOrder = 2
        object Label5: TLabel
          Left = 0
          Top = 0
          Width = 119
          Height = 13
          Align = alTop
          Alignment = taCenter
          Caption = #1042#1099#1073#1088#1072#1085#1085#1099#1077
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          ExplicitWidth = 69
        end
        object ListBox1: TListBox
          Left = 0
          Top = 13
          Width = 119
          Height = 124
          Align = alClient
          ItemHeight = 13
          TabOrder = 0
          OnDblClick = SpeedButton3Click
        end
      end
      object Panel7: TPanel
        Left = 159
        Top = 2
        Width = 523
        Height = 137
        Align = alClient
        BevelOuter = bvNone
        TabOrder = 0
        object Label6: TLabel
          Left = 0
          Top = 0
          Width = 523
          Height = 13
          Align = alTop
          Alignment = taCenter
          Caption = #1057#1087#1080#1089#1086#1082' '#1082#1074#1072#1083#1080#1092#1080#1082#1072#1094#1080#1081
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -11
          Font.Name = 'MS Sans Serif'
          Font.Style = [fsBold]
          ParentFont = False
          ExplicitWidth = 134
        end
        object ListBox2: TListBox
          Left = 0
          Top = 13
          Width = 523
          Height = 124
          Align = alClient
          ItemHeight = 13
          TabOrder = 0
          OnDblClick = SpeedButton4Click
        end
      end
    end
    object Panel9: TPanel
      Left = 2
      Top = 2
      Width = 329
      Height = 141
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 0
      OnCanResize = Panel9CanResize
      OnDblClick = Panel9DblClick
      object Label1: TLabel
        Left = 9
        Top = 5
        Width = 83
        Height = 13
        Caption = #8470' '#1087#1088#1086#1090#1086#1082#1086#1083#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label3: TLabel
        Left = 9
        Top = 27
        Width = 101
        Height = 13
        Caption = #1044#1072#1090#1072' '#1087#1088#1086#1090#1086#1082#1086#1083#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label2: TLabel
        Left = 9
        Top = 49
        Width = 64
        Height = 13
        Caption = #1044#1080#1087#1083#1086#1084' '#8470
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label4: TLabel
        Left = 9
        Top = 94
        Width = 89
        Height = 13
        Caption = #1044#1072#1090#1072' '#1074#1099#1087#1091#1089#1082#1072':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label9: TLabel
        Left = 129
        Top = 73
        Width = 37
        Height = 13
        Caption = #1057#1077#1088#1080#1103
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label10: TLabel
        Left = 213
        Top = 73
        Width = 13
        Height = 13
        Caption = #8470
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Edit2: TEdit
        Left = 128
        Top = 45
        Width = 193
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        ReadOnly = True
        TabOrder = 2
      end
      object Edit1: TEdit
        Left = 128
        Top = 1
        Width = 50
        Height = 21
        TabOrder = 0
        OnKeyPress = Edit1KeyPress
      end
      object BitBtn2: TBitBtn
        Left = 225
        Top = 104
        Width = 96
        Height = 33
        Hint = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1102' '#1087#1086' '#1076#1080#1087#1083#1086#1084#1091
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Glyph.Data = {
          66010000424D6601000000000000760000002800000014000000140000000100
          040000000000F000000000000000000000001000000010000000000000000000
          8000008000000080800080000000800080008080000080808000C0C0C0000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00888888888888
          88888888000088877777777777777778000088000000000000000778000080BF
          B0FFFFFFF0BFB078000080FBF0F00FFFF0FBF078000080BFB0F77FFFF0BFB078
          000080FBF0FFFFFFF0FBF078000080BFBF0000000FBFB078000080FBFBFBFBFB
          FBFBF078000080BFBFBFBFBFBFBFB078000080FBFBFBFBFBFBFBF078000080BF
          BFBFBFBFBFBFB078000080FBF000000000FBF078000080BF0FFFFFFFF0BFB078
          000080FB0FCCCCCCF0FBF078000080BF0FFFFFFFF0BFB078000080FB0FCCCCCC
          F0F0F078000080BF0FFFFFFFF0BFB08800008800000000000000088800008888
          88888888888888880000}
        ParentFont = False
        ParentShowHint = False
        ShowHint = True
        TabOrder = 1
        Visible = False
        OnClick = BitBtn2Click
      end
      object CheckBox2: TCheckBox
        Left = 9
        Top = 112
        Width = 193
        Height = 17
        Caption = #1054#1089#1090#1072#1074#1083#1103#1090#1100' '#1076#1072#1085#1085#1099#1077' '#1087#1088#1086#1090#1086#1082#1086#1083#1072
        TabOrder = 5
      end
      object Edit5: TEdit
        Left = 172
        Top = 69
        Width = 33
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
      object Edit6: TEdit
        Left = 232
        Top = 69
        Width = 89
        Height = 21
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        OnKeyPress = Edit1KeyPress
      end
      object DateTimePicker1: TDateTimePicker
        Left = 128
        Top = 23
        Width = 91
        Height = 21
        Date = 42639.426223495370000000
        Time = 42639.426223495370000000
        TabOrder = 6
        OnChange = DateTimePicker1Change
      end
      object DateTimePicker2: TDateTimePicker
        Left = 128
        Top = 92
        Width = 91
        Height = 21
        Date = 42639.426298506940000000
        Time = 42639.426298506940000000
        TabOrder = 7
        OnChange = DateTimePicker2Change
      end
    end
  end
  object ApplicationEvents1: TApplicationEvents
    OnMessage = ApplicationEvents1Message
    Left = 160
    Top = 200
  end
end

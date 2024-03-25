object Result_Ball_RatingForm: TResult_Ball_RatingForm
  Left = 136
  Top = 147
  BorderIcons = [biSystemMenu]
  Caption = #1056#1077#1081#1090#1080#1085#1075#1086#1074#1072#1103' '#1086#1094#1077#1085#1082#1072
  ClientHeight = 459
  ClientWidth = 544
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
    Top = 0
    Width = 544
    Height = 73
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    ExplicitWidth = 552
    object Label10: TLabel
      Left = 194
      Top = 36
      Width = 16
      Height = 29
      Caption = #8212
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -25
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label9: TLabel
      Left = 24
      Top = 44
      Width = 81
      Height = 13
      Alignment = taCenter
      Caption = #1059#1095#1077#1073#1085#1099#1081' '#1075#1086#1076':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 24
      Top = 15
      Width = 112
      Height = 13
      Caption = #1053#1086#1084#1077#1088' '#1074#1077#1076#1086#1084#1086#1089#1090#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 144
      Top = 11
      Width = 45
      Height = 21
      TabOrder = 0
      OnChange = Edit1Change
      OnKeyPress = Edit1KeyPress
    end
    object Edit2: TEdit
      Left = 144
      Top = 40
      Width = 45
      Height = 21
      TabOrder = 2
      OnChange = Edit1Change
      OnKeyPress = Edit2KeyPress
    end
    object BitBtn1: TBitBtn
      Left = 352
      Top = 20
      Width = 105
      Height = 33
      Caption = #1042#1099#1073#1088#1072#1090#1100
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
        7777700000007777777770000000000000007777777770FFFFFF000000007777
        777770F8888F000000007777777770FFFFFF000000007777777770F8888F0000
        00007444444440FFFFFF000000007488888880F8888F000000007477777770FF
        FFFF000000007470070070000000000000007477777777774777700000007470
        0700700747777000000074777777777747747000000074444444444447444000
        000074F44F44F44F477470000000744444444444477770000000777777777777
        777770000000}
      ParentFont = False
      Spacing = 15
      TabOrder = 1
      OnClick = BitBtn1Click
    end
    object Edit3: TEdit
      Left = 213
      Top = 40
      Width = 45
      Height = 21
      TabOrder = 3
      OnChange = Edit1Change
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 121
    Width = 544
    Height = 283
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    Visible = False
    ExplicitWidth = 552
    ExplicitHeight = 295
    object DBGrid1: TDBGrid
      Left = 2
      Top = 2
      Width = 548
      Height = 291
      Align = alClient
      DataSource = DataModule1.Rating_BallSource
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
      Columns = <
        item
          Expanded = False
          FieldName = 'FIO'
          ReadOnly = True
          Title.Alignment = taCenter
          Title.Caption = #1060#1072#1084#1080#1083#1080#1103', '#1048#1084#1103', '#1054#1090#1095#1077#1089#1090#1074#1086
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 355
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'BALL_R'
          Title.Alignment = taCenter
          Title.Caption = #1054#1073#1097#1077#1077' '#1082#1086#1083'-'#1074#1086' '#1073#1072#1083#1083#1086#1074
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 138
          Visible = True
        end>
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 404
    Width = 544
    Height = 55
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 2
    Visible = False
    ExplicitTop = 416
    ExplicitWidth = 552
    object BitBtn2: TBitBtn
      Left = 209
      Top = 11
      Width = 105
      Height = 33
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        5E060000424D5E06000000000000360400002800000018000000170000000100
        0800000000002802000000000000000000000001000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000C0DCC000F0C8
        A400000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000000000000
        000000000000000000000000000000000000F0FBFF00A4A0A000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00070707070707
        070707070707070707070707070707070707070707070707070704FF07070707
        0707070707070707070707070707070707040404FF0707070707070707070707
        07070707070707070404040404FF070707070707070707070707070707070704
        0404040404FF070707070707070707070707070707070404040404040404FF07
        070707070707070707070707070404040404FFFF040404FF0707070707070707
        070707070404040404FF0707070404FF07070707070707070707070704040404
        FF07070707070404FF0707070707070707070707070404FF0707070707070704
        04FF0707070707070707070707070707070707070707070704FF070707070707
        070707070707070707070707070707070704FF07070707070707070707070707
        0707070707070707070704FF0707070707070707070707070707070707070707
        07070704FF070707070707070707070707070707070707070707070704FF0707
        07070707000707000707000000070707070000000704FF070707070700070700
        070700070700070700070707070704FF07070707000707000707000707000707
        0007070707070704FF0707070000000007070000000707070007070707070707
        0407070700070700070700070700070700070707070707070707070700070700
        0707000707000707000707070707070707070707070000070707000000070707
        0700000007070707070707070707070707070707070707070707070707070707
        0707}
      ParentFont = False
      TabOrder = 0
      OnClick = BitBtn2Click
    end
  end
  object Panel4: TPanel
    Left = 0
    Top = 73
    Width = 544
    Height = 48
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 3
    Visible = False
    ExplicitWidth = 552
    object DBText1: TDBText
      Left = 68
      Top = 26
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'N_GROUP'
      DataSource = DataModule1.Rating_BallSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText2: TDBText
      Left = 226
      Top = 26
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'SPECIAL'
      DataSource = DataModule1.Rating_BallSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText3: TDBText
      Left = 68
      Top = 9
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'SEMESTR'
      DataSource = DataModule1.Rating_BallSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBText4: TDBText
      Left = 226
      Top = 9
      Width = 50
      Height = 13
      AutoSize = True
      DataField = 'SESSION'
      DataSource = DataModule1.Rating_BallSource
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 160
      Top = 9
      Width = 54
      Height = 13
      Caption = #1055#1086#1083#1091#1075#1086#1076#1080#1077
    end
    object Label3: TLabel
      Left = 16
      Top = 9
      Width = 44
      Height = 13
      Caption = #1057#1077#1084#1077#1089#1090#1088
    end
    object Label4: TLabel
      Left = 25
      Top = 26
      Width = 35
      Height = 13
      Caption = #1043#1088#1091#1087#1087#1072
    end
    object Label5: TLabel
      Left = 135
      Top = 26
      Width = 79
      Height = 13
      Caption = #1057#1087#1077#1094#1080#1072#1083#1080#1079#1072#1094#1080#1103
    end
  end
  object ApplicationEvents1: TApplicationEvents
    OnMessage = ApplicationEvents1Message
    Left = 168
    Top = 256
  end
end

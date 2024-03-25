object Ved_LikvidForm: TVed_LikvidForm
  Left = 199
  Top = 199
  BorderIcons = [biSystemMenu]
  ClientHeight = 436
  ClientWidth = 885
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
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 654
    Height = 436
    Align = alClient
    BevelOuter = bvLowered
    TabOrder = 0
    object DBGrid1: TDBGrid
      Left = 1
      Top = 1
      Width = 652
      Height = 434
      Align = alClient
      DataSource = DataModule1.Ved_LikvidGridSource
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
          FieldName = 'N_VEDOMOST'
          Title.Alignment = taCenter
          Title.Caption = #8470' '#1074#1077#1076
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 45
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'D_VED'
          Title.Alignment = taCenter
          Title.Caption = #1044#1072#1090#1072
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 59
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
          Width = 85
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'YEAR_PLAN'
          Title.Alignment = taCenter
          Title.Caption = #1047#1072' '#1091#1095'.'#1075#1086#1076
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 61
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'YEAR_UCH'
          Title.Alignment = taCenter
          Title.Caption = #1059#1095'.'#1075#1086#1076
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 59
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'SEMESTR_VED'
          Title.Alignment = taCenter
          Title.Caption = #1057#1077#1084#1077#1089#1090#1088
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 56
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'VID_EDU_PLAN1'
          Title.Alignment = taCenter
          Title.Caption = #1042#1080#1076' '#1086#1073#1091#1095#1077#1085#1080#1103
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'FIO'
          Title.Alignment = taCenter
          Title.Caption = #1060#1048#1054
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 138
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'KURS'
          Title.Alignment = taCenter
          Title.Caption = #1050#1091#1088#1089
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 40
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'BALL1'
          Title.Alignment = taCenter
          Title.Caption = #1041#1072#1083#1083
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 39
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'D_EXAM'
          Title.Alignment = taCenter
          Title.Caption = #1044#1072#1090#1072' '#1101#1082#1079'.'
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 78
          Visible = True
        end
        item
          Expanded = False
          FieldName = 'N_VED'
          Visible = False
        end>
    end
  end
  object Panel2: TPanel
    Left = 654
    Top = 0
    Width = 231
    Height = 436
    Align = alRight
    BevelOuter = bvLowered
    TabOrder = 1
    object Panel3: TPanel
      Left = 1
      Top = 1
      Width = 229
      Height = 56
      Align = alTop
      BevelInner = bvRaised
      BevelOuter = bvLowered
      TabOrder = 0
      object Label7: TLabel
        Left = 12
        Top = 19
        Width = 151
        Height = 26
        Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1074#1077#1076#1086#1084#1086#1089#1090#1080#13#10#1076#1083#1103' '#1083#1080#1082#1074#1080#1076#1072#1094#1080#1080' '#1088#1072#1079#1085#1080#1094#1099
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object SpeedButton3: TSpeedButton
        Left = 192
        Top = 19
        Width = 26
        Height = 26
        Cursor = crHandPoint
        Hint = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074#1077#1076#1086#1084#1086#1089#1090#1100#13#10#1076#1083#1103' '#1083#1080#1082#1074#1080#1076#1072#1094#1080#1080' '#1088#1072#1079#1085#1080#1094#1099
        Glyph.Data = {
          EE000000424DEE000000000000007600000028000000100000000F0000000100
          0400000000007800000000000000000000001000000000000000000000000000
          C00000C0000000C0C000C0000000C000C000C0C00000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00FFFFFFFFFF00
          00FFFFFFFFFFFF0BB0FFFFFFFFFF000BB000FFFFFFFF0BBBBBB0FFFFFFFF0BBB
          BBB0FFFFFFFF000BB000FFFFFFFFFF0BB0FF000000000F0000FF0FFFFFFF0FFF
          FFFF0F00F00F0FFFFFFF0FFFFFFF0FFFFFFF0F00F00F0FFFFFFF0FFFFFFF0FFF
          FFFF444444444FFFFFFF444444444FFFFFFF}
        ParentShowHint = False
        ShowHint = True
        OnClick = SpeedButton3Click
      end
    end
    object RadioGroup2: TRadioGroup
      Left = 1
      Top = 281
      Width = 229
      Height = 80
      Align = alTop
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
      TabOrder = 1
      OnClick = RadioGroup2Click
    end
    object BitBtn2: TBitBtn
      Left = 138
      Top = 367
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
      TabOrder = 2
      OnClick = BitBtn2Click
    end
    object GroupBox1: TGroupBox
      Left = 1
      Top = 57
      Width = 229
      Height = 224
      Align = alTop
      Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1074#1077#1076#1086#1084#1086#1089#1090#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      object Label3: TLabel
        Left = 9
        Top = 119
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
        Left = 95
        Top = 119
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
      object CheckBox2: TCheckBox
        Left = 9
        Top = 157
        Width = 97
        Height = 17
        Caption = #1055#1086' '#1089#1090#1091#1076#1077#1085#1090#1091':'
        TabOrder = 0
        OnClick = CheckBox2Click
      end
      object CheckBox1: TCheckBox
        Left = 9
        Top = 27
        Width = 188
        Height = 14
        Caption = #1042#1077#1076#1086#1084#1086#1089#1090#1080' '#1079#1072' '#1091#1095#1077#1073#1085#1099#1081' '#1075#1086#1076':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnClick = CheckBox1Click
      end
      object Edit1: TEdit
        Left = 21
        Top = 49
        Width = 64
        Height = 21
        Enabled = False
        TabOrder = 2
        OnClick = Edit1Click
        OnKeyPress = Edit1KeyPress
      end
      object BitBtn4: TBitBtn
        Left = 190
        Top = 44
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
        TabOrder = 3
        OnClick = BitBtn4Click
      end
      object CheckBox3: TCheckBox
        Left = 9
        Top = 88
        Width = 163
        Height = 14
        Caption = #1042#1077#1076#1086#1084#1086#1089#1090#1080' '#1079#1072' '#1087#1077#1088#1080#1086#1076':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -9
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
        OnClick = CheckBox3Click
      end
      object Edit2: TEdit
        Left = 21
        Top = 115
        Width = 75
        Height = 21
        Enabled = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 5
        OnClick = Edit2Click
      end
      object Edit3: TEdit
        Left = 113
        Top = 115
        Width = 75
        Height = 21
        Enabled = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = []
        ParentFont = False
        TabOrder = 6
        OnClick = Edit3Click
      end
      object BitBtn1: TBitBtn
        Left = 190
        Top = 110
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
        TabOrder = 7
        OnClick = BitBtn1Click
      end
      object DBLookupComboBox1: TDBLookupComboBox
        Left = 9
        Top = 182
        Width = 177
        Height = 21
        Enabled = False
        KeyField = 'NOMER'
        ListField = 'FIO'
        ListSource = DataModule1.Ved_Raznica_People_CaseSource
        TabOrder = 8
      end
      object BitBtn5: TBitBtn
        Left = 190
        Top = 177
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
        TabOrder = 9
        OnClick = BitBtn5Click
      end
    end
    object BitBtn3: TBitBtn
      Left = 138
      Top = 408
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
      TabOrder = 4
      OnClick = BitBtn3Click
    end
  end
  object ApplicationEvents1: TApplicationEvents
    OnMessage = ApplicationEvents1Message
    Left = 168
    Top = 256
  end
end

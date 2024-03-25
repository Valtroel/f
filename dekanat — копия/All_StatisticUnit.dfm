object All_StatisticForm: TAll_StatisticForm
  Left = 192
  Top = 116
  BorderIcons = [biSystemMenu]
  Caption = #1054#1073#1097#1072#1103' '#1089#1090#1072#1090#1080#1089#1090#1080#1082#1072' '#1087#1088#1086#1087#1091#1089#1082#1086#1074
  ClientHeight = 329
  ClientWidth = 698
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 698
    Height = 73
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object RadioGroup1: TRadioGroup
      Left = 24
      Top = 8
      Width = 249
      Height = 57
      Caption = #1042#1099#1073#1086#1088' '#1087#1086#1082#1072#1079#1072' '#1087#1077#1088#1080#1086#1076#1072' '#1087#1088#1086#1087#1091#1089#1082#1086#1074':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        #1052#1077#1089#1103#1094
        #1055#1088#1086#1080#1079#1074#1086#1083#1100#1085#1099#1081)
      ParentFont = False
      TabOrder = 0
      OnClick = RadioGroup1Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 73
    Width = 698
    Height = 209
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    Visible = False
    object Panel4: TPanel
      Left = 2
      Top = 2
      Width = 287
      Height = 205
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 0
      Visible = False
      object Label2: TLabel
        Left = 22
        Top = 8
        Width = 72
        Height = 16
        Caption = #1047#1072' '#1084#1077#1089#1103#1094':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label1: TLabel
        Left = 22
        Top = 33
        Width = 31
        Height = 16
        Caption = #1043#1086#1076':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label3: TLabel
        Left = 117
        Top = 33
        Width = 17
        Height = 16
        Caption = '20'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object ComboBox1: TComboBox
        Left = 117
        Top = 6
        Width = 118
        Height = 21
        Style = csDropDownList
        TabOrder = 0
        Items.Strings = (
          #1071#1085#1074#1072#1088#1100
          #1060#1077#1074#1088#1072#1083#1100
          #1052#1072#1088#1090
          #1040#1087#1088#1077#1083#1100
          #1052#1072#1081
          #1048#1102#1085#1100
          #1048#1102#1083#1100
          #1040#1074#1075#1091#1089#1090
          #1057#1077#1085#1090#1103#1073#1088#1100
          #1054#1082#1090#1103#1073#1088#1100
          #1053#1086#1103#1073#1088#1100
          #1044#1077#1082#1072#1073#1088#1100)
      end
      object MaskEdit1: TMaskEdit
        Left = 137
        Top = 33
        Width = 32
        Height = 22
        BorderStyle = bsNone
        Color = clMenu
        EditMask = '99;1;'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        MaxLength = 2
        ParentFont = False
        TabOrder = 1
        Text = '  '
      end
    end
    object Panel5: TPanel
      Left = 289
      Top = 2
      Width = 287
      Height = 205
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 1
      Visible = False
      object Label4: TLabel
        Left = 22
        Top = 8
        Width = 82
        Height = 16
        Caption = #1047#1072' '#1087#1077#1088#1080#1086#1076':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label5: TLabel
        Left = 22
        Top = 33
        Width = 13
        Height = 16
        Caption = #1089':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object Label6: TLabel
        Left = 149
        Top = 33
        Width = 23
        Height = 16
        Caption = #1087#1086':'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -15
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object DateTimePicker2: TDateTimePicker
        Left = 178
        Top = 33
        Width = 103
        Height = 21
        Date = 42648.448373379630000000
        Time = 42648.448373379630000000
        TabOrder = 0
        OnChange = DateTimePicker2Change
      end
      object DateTimePicker1: TDateTimePicker
        Left = 35
        Top = 33
        Width = 105
        Height = 21
        Date = 42648.449563194440000000
        Time = 42648.449563194440000000
        TabOrder = 1
        OnChange = DateTimePicker1Change
      end
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 282
    Width = 698
    Height = 47
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 2
    object Button1: TButton
      Left = 71
      Top = 7
      Width = 146
      Height = 33
      Cursor = crHandPoint
      Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1088#1077#1079#1091#1083#1100#1090#1072#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
      OnClick = Button1Click
    end
  end
end

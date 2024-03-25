object JournalForm: TJournalForm
  Left = 0
  Top = 0
  Caption = #1046#1091#1088#1085#1072#1083' '#1074#1077#1076#1086#1084#1086#1089#1090#1077#1081
  ClientHeight = 169
  ClientWidth = 322
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label3: TLabel
    Left = 147
    Top = 95
    Width = 9
    Height = 13
    Caption = 'C'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -9
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label4: TLabel
    Left = 225
    Top = 95
    Width = 19
    Height = 13
    Caption = #1055#1054
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -9
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object Label1: TLabel
    Left = 147
    Top = 63
    Width = 112
    Height = 13
    Caption = #1042#1077#1076#1086#1084#1086#1089#1090#1080' '#1079#1072' '#1087#1077#1088#1080#1086#1076':'
  end
  object Edit1: TEdit
    Left = 162
    Top = 87
    Width = 64
    Height = 21
    TabOrder = 0
  end
  object Edit2: TEdit
    Left = 246
    Top = 87
    Width = 64
    Height = 21
    TabOrder = 1
  end
  object RadioGroup1: TRadioGroup
    Left = 169
    Top = 8
    Width = 125
    Height = 49
    Caption = #1060#1086#1088#1084#1072' '#1086#1073#1091#1095#1077#1085#1080#1103
    Items.Strings = (
      #1076#1085#1077#1074#1085#1072#1103
      #1079#1072#1086#1095#1085#1072#1103)
    TabOrder = 2
  end
  object RadioGroup2: TRadioGroup
    Left = 8
    Top = 63
    Width = 124
    Height = 68
    Caption = #1050#1091#1088#1089
    Columns = 2
    Items.Strings = (
      '1'
      '2'
      '3'
      '4'
      '5')
    TabOrder = 3
  end
  object BitBtn1: TBitBtn
    Left = 120
    Top = 137
    Width = 75
    Height = 25
    Caption = #1055#1077#1095#1072#1090#1100
    TabOrder = 4
    OnClick = BitBtn1Click
  end
  object RadioGroup3: TRadioGroup
    Left = 8
    Top = 0
    Width = 155
    Height = 57
    Items.Strings = (
      #1086#1089#1085#1086#1074#1085#1072#1103
      #1101#1082#1079#1072#1084#1077#1085#1072#1094#1080#1086#1085#1085#1099#1081' '#1083#1080#1089#1090)
    TabOrder = 5
    OnClick = RadioGroup3Click
  end
end

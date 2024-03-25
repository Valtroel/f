object QueueForm: TQueueForm
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1089#1090#1091#1076#1077#1085#1090#1086#1074
  ClientHeight = 200
  ClientWidth = 207
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 21
    Width = 105
    Height = 13
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1089#1090#1091#1076#1077#1085#1090#1072':'
  end
  object DBLookupComboBox1: TDBLookupComboBox
    Left = 16
    Top = 40
    Width = 145
    Height = 21
    KeyField = 'CONCATENATION'
    ListField = 'CONCATENATION'
    ListSource = DataModule1.QueueDataSource1
    TabOrder = 0
  end
  object Добавить: TButton
    Left = 16
    Top = 152
    Width = 75
    Height = 25
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 1
    OnClick = ДобавитьClick
  end
  object BitBtn1: TBitBtn
    Left = 112
    Top = 152
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 2
    OnClick = BitBtn1Click
  end
end

object Stud_Pr_RestoreForm: TStud_Pr_RestoreForm
  Left = 328
  Top = 297
  BorderIcons = [biSystemMenu]
  Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1087#1088#1080#1082#1072#1079#1072' '#1086#1073' '#1086#1090#1095#1080#1089#1083#1077#1085#1080#1080
  ClientHeight = 245
  ClientWidth = 437
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 437
    Height = 204
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 113
      Width = 70
      Height = 13
      Caption = #8470' '#1087#1088#1080#1082#1072#1079#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 16
      Top = 145
      Width = 88
      Height = 13
      Caption = #1044#1072#1090#1072' '#1087#1088#1080#1082#1072#1079#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 16
      Top = 176
      Width = 78
      Height = 13
      Caption = #1055#1088#1080#1084#1077#1095#1072#1085#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 16
      Top = 75
      Width = 73
      Height = 26
      Caption = #1055#1088#1080#1095#1080#1085#1072#13#10#1086#1090#1095#1080#1089#1083#1077#1085#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object RadioGroup1: TRadioGroup
      Left = 8
      Top = 8
      Width = 209
      Height = 57
      Caption = #1042#1080#1076' '#1087#1088#1080#1082#1072#1079#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        #1054#1090#1095#1080#1089#1083#1077#1085
        #1055#1077#1088#1077#1074#1077#1076#1077#1085' '#1080#1079' '#1076#1088#1091#1075#1086#1075#1086' '#1042#1059#1047#1072)
      ParentFont = False
      TabOrder = 0
      Visible = False
      OnClick = RadioGroup1Click
    end
    object Edit1: TEdit
      Left = 107
      Top = 109
      Width = 100
      Height = 21
      TabOrder = 2
      OnKeyPress = Edit1KeyPress
    end
    object DBLookupComboBox1: TDBLookupComboBox
      Left = 107
      Top = 78
      Width = 330
      Height = 21
      KeyField = 'N_CAUSE_RESTORE'
      ListField = 'CAUSE_RES'
      ListSource = DM2.Cause_RestoreSource
      TabOrder = 1
    end
    object Edit2: TEdit
      Left = 107
      Top = 172
      Width = 330
      Height = 21
      TabOrder = 3
    end
    object DateTimePicker1: TDateTimePicker
      Left = 128
      Top = 136
      Width = 186
      Height = 21
      Date = 42627.688200648150000000
      Time = 42627.688200648150000000
      TabOrder = 4
      OnChange = DateTimePicker1Change
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 204
    Width = 437
    Height = 41
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    object BitBtn1: TBitBtn
      Left = 48
      Top = 4
      Width = 130
      Height = 33
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
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
        7777700000007777777777777777700000007777777774F77777700000007777
        7777444F77777000000077777774444F777770000000700000444F44F7777000
        000070FFF444F0744F777000000070F8884FF0774F777000000070FFFFFFF077
        74F77000000070F88888F077774F7000000070FFFFFFF0777774F000000070F8
        8777F07777774000000070FFFF00007777777000000070F88707077777777000
        000070FFFF007777777770000000700000077777777770000000777777777777
        777770000000}
      ParentFont = False
      Spacing = 10
      TabOrder = 0
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 268
      Top = 4
      Width = 130
      Height = 33
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
      TabOrder = 1
    end
  end
end

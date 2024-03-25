object DiplomForm: TDiplomForm
  Left = 462
  Top = 215
  BorderIcons = [biSystemMenu]
  Caption = #1060#1086#1088#1084#1080#1088#1086#1074#1072#1085#1080#1077' '#1074#1099#1087#1080#1089#1082#1080' '#1080#1083#1080' '#1089#1074#1086#1076#1085#1086#1081' '#1074#1077#1076#1086#1084#1086#1089#1090#1080
  ClientHeight = 261
  ClientWidth = 369
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
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 269
    Height = 174
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 148
      Width = 148
      Height = 13
      Caption = #1044#1072#1090#1072' '#1074#1088#1091#1095#1077#1085#1080#1103' '#1076#1080#1087#1083#1086#1084#1072':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object RadioGroup1: TRadioGroup
      Left = 8
      Top = 8
      Width = 130
      Height = 65
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
      Left = 152
      Top = 8
      Width = 113
      Height = 65
      Caption = #1050#1091#1088#1089':'
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
        '5')
      ParentFont = False
      TabOrder = 1
      Visible = False
      OnClick = RadioGroup2Click
    end
    object RadioGroup3: TRadioGroup
      Left = 8
      Top = 76
      Width = 130
      Height = 61
      Caption = #1057#1080#1089#1090#1077#1084#1072' '#1086#1094#1077#1085#1086#1082':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ItemIndex = 0
      Items.Strings = (
        '10 - '#1090#1080' '#1073#1072#1083#1100#1085#1072#1103
        ' 5  - '#1090#1080' '#1073#1072#1083#1100#1085#1072#1103)
      ParentFont = False
      TabOrder = 2
      Visible = False
      OnClick = RadioGroup3Click
    end
    object DateTimePicker1: TDateTimePicker
      Left = 169
      Top = 140
      Width = 89
      Height = 21
      Date = 42647.491040370370000000
      Time = 42647.491040370370000000
      TabOrder = 3
      Visible = False
      OnChange = DateTimePicker1Change
    end
  end
  object Panel2: TPanel
    Left = 269
    Top = 0
    Width = 100
    Height = 174
    Align = alRight
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    Visible = False
    object CheckListBox1: TCheckListBox
      Left = 0
      Top = 0
      Width = 99
      Height = 176
      ItemHeight = 13
      TabOrder = 0
      OnClick = CheckListBox1Click
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 174
    Width = 369
    Height = 87
    Align = alBottom
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 2
    Visible = False
    object BitBtn1: TBitBtn
      Left = 11
      Top = 47
      Width = 150
      Height = 33
      Hint = #1042#1099#1076#1072#1090#1100' '#1074' Excel '#1074#1099#1087#1080#1089#1082#1091' '#1082' '#1076#1080#1087#1083#1086#1084#1091
      Caption = #1042#1099#1087#1080#1089#1082#1072' '#1082' '#1076#1080#1087#1083#1086#1084#1091
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
        77777000000070000000007777777000000070FFFFFFF07777700000000070F7
        7777F07777000000000070F77777F07770007000000070F77780008700077000
        000070F7700FFF0000777000000070F708FFFF0807777000000070F80E000F07
        08777000000070F0EFEFEF0770777000000070F0F0000F077077700000007000
        EFEFFF0770777000000077780000000708777000000077770077777807777000
        0000777770077700777770000000777777800087777770000000777777777777
        777770000000}
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 0
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 11
      Top = 8
      Width = 150
      Height = 33
      Hint = #1042#1099#1076#1072#1090#1100' '#1074' Excel '#1089#1074#1086#1076#1085#1091#1102' '#1074#1077#1076#1086#1084#1086#1089#1090#1100
      Caption = #1057#1074#1086#1076#1085#1072#1103' '#1074#1077#1076#1086#1084#1086#1089#1090#1100
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
        7777700000007777777777777777700000007777777000000000700000007777
        7770FFFFFFF07000000077777770FCCCCCF07000000070000000FFFFFFF07000
        000070FFFFF0FCCCCCF07000000070FCCCC0FFFFFFF07000000070FFFFF0FCCF
        00007000000070FCCCC0FFFF0F077000000070FFFFF0FFFF00777000000070FC
        CF00000007777000000070FFFF0F077777777000000070FFFF00777777777000
        0000700000077777777770000000777777777777777770000000777777777777
        777770000000}
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 1
      OnClick = BitBtn2Click
    end
    object BitBtn3: TBitBtn
      Left = 167
      Top = 8
      Width = 190
      Height = 33
      Hint = #1042#1099#1076#1072#1090#1100' '#1074' Excel '#1089#1087#1080#1089#1086#1082' '#1085#1072' '#1088#1072#1089#1087#1088#1077#1076#1077#1083#1077#1085#1080#1077
      Caption = #1057#1087#1080#1089#1086#1082' '#1085#1072' '#1088#1072#1089#1087#1088#1077#1076#1077#1083#1077#1085#1080#1077
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        66010000424D6601000000000000760000002800000014000000140000000100
        040000000000F000000000000000000000001000000000000000000000000000
        8000008000000080800080000000800080008080000080808000C0C0C0000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00555555550000
        000000550000555555550FFFFFFFF0550000555555550FF00F00F05500005555
        55550FFFFFFFF0550000555555550F0000F0F0550000555555550FFFFFFFF055
        0000557000000007F00000550000550EEEEEEEE0F0FF05550000550E77777EE0
        F0F055550000550E7FFFFFE0F00555550000550E7FFFFFE0009555550000550E
        7FFFFFE0599955550000550E7FFFFFE0999995550000550E7FFFFFE999999955
        0000550E7FFFFFE0599955550000550700770070599955550000550E770077E0
        599955550000550EE7007EE99995555500005570000000075555555500005555
        55555555555555550000}
      ParentFont = False
      ParentShowHint = False
      ShowHint = True
      TabOrder = 2
      OnClick = BitBtn3Click
    end
  end
end

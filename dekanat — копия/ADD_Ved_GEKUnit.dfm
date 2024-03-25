object ADD_VedGEK: TADD_VedGEK
  Left = 389
  Top = 233
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #1042#1074#1086#1076' '#1101#1082#1079#1072#1084#1077#1085#1072#1094#1080#1086#1085#1085#1086#1081' '#1074#1077#1076#1086#1084#1086#1089#1090#1080' '#1085#1072' '#1043#1054#1057
  ClientHeight = 301
  ClientWidth = 543
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 543
    Height = 113
    Align = alTop
    BevelInner = bvLowered
    TabOrder = 0
    object Label8: TLabel
      Left = 271
      Top = 15
      Width = 65
      Height = 26
      Caption = #1044#1072#1090#1072#13#10#1074#1077#1076#1086#1084#1086#1089#1090#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label4: TLabel
      Left = 201
      Top = 23
      Width = 101
      Height = 13
      Caption = #1060#1086#1088#1084#1072' '#1086#1073#1091#1095#1077#1085#1080#1103
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 252
      Top = 47
      Width = 59
      Height = 13
      Caption = #8470' '#1075#1088#1091#1087#1087#1099
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label7: TLabel
      Left = 201
      Top = 53
      Width = 81
      Height = 13
      Caption = #8470' '#1074#1077#1076#1086#1084#1086#1089#1090#1080
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object ComboBox2: TComboBox
      Left = 314
      Top = 19
      Width = 100
      Height = 21
      MaxLength = 4
      TabOrder = 0
      OnChange = ComboBox2Change
      Items.Strings = (
        #1044#1085#1077#1074#1085#1072#1103
        #1047#1072#1086#1095#1085#1072#1103)
    end
    object Button2: TButton
      Left = 219
      Top = 82
      Width = 169
      Height = 25
      Caption = #1042#1099#1073#1088#1072#1090#1100' '#1087#1088#1077#1076#1084#1077#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      OnClick = Button1Click
    end
    object Edit5: TEdit
      Left = 314
      Top = 49
      Width = 100
      Height = 21
      MaxLength = 4
      TabOrder = 1
      OnKeyPress = Edit5KeyPress
    end
    object CheckListBox1: TCheckListBox
      Left = 0
      Top = 1
      Width = 121
      Height = 107
      ItemHeight = 13
      TabOrder = 3
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 113
    Width = 543
    Height = 136
    Align = alTop
    BevelInner = bvLowered
    Enabled = False
    TabOrder = 1
    ExplicitTop = 107
    object Label9: TLabel
      Left = 12
      Top = 7
      Width = 84
      Height = 13
      Caption = #1069#1082#1079#1072#1084#1077#1085#1072#1090#1086#1088':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      Visible = False
    end
    object Label3: TLabel
      Left = 12
      Top = 86
      Width = 60
      Height = 26
      Caption = #1044#1072#1090#1072' '#1043#1086#1089'.'#13#10#1101#1082#1079#1072#1084#1077#1085#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label6: TLabel
      Left = 12
      Top = 59
      Width = 53
      Height = 13
      AutoSize = False
      Caption = #1055#1088#1077#1076#1084#1077#1090
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 268
      Top = 86
      Width = 59
      Height = 26
      Caption = #1053#1072#1095#1072#1083#1086#13#10#1101#1082#1079#1072#1084#1077#1085#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label1: TLabel
      Left = 10
      Top = 19
      Width = 119
      Height = 26
      Caption = #8470' '#1075#1088#1091#1087#1087#1099' '#1076#1083#1103' '#1043#1054#1057#1072#13#10'('#1085#1072#1087#1088#1080#1084#1077#1088': 2) '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object DBLookupComboBox1: TDBLookupComboBox
      Left = 137
      Top = 55
      Width = 332
      Height = 21
      KeyField = 'N_PLAN'
      ListField = 'NAME_OBJECT'
      ListSource = DM3.Predmet_GEKSource
      TabOrder = 1
    end
    object Edit7: TEdit
      Left = 137
      Top = 3
      Width = 332
      Height = 21
      TabOrder = 2
      Visible = False
    end
    object MaskEdit2: TMaskEdit
      Left = 378
      Top = 89
      Width = 91
      Height = 21
      EditMask = '!90:00;1;_'
      MaxLength = 5
      TabOrder = 3
      Text = '  :  '
    end
    object Edit1: TEdit
      Left = 137
      Top = 22
      Width = 332
      Height = 21
      MaxLength = 255
      TabOrder = 0
    end
    object DateTimePicker2: TDateTimePicker
      Left = 96
      Top = 88
      Width = 109
      Height = 21
      Date = 42668.715337071760000000
      Time = 42668.715337071760000000
      TabOrder = 4
      OnChange = DateTimePicker2Change
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 249
    Width = 543
    Height = 52
    Align = alClient
    BevelInner = bvLowered
    TabOrder = 2
    object BitBtn1: TBitBtn
      Left = 38
      Top = 13
      Width = 167
      Height = 30
      Cursor = crHandPoint
      Caption = #1042#1099#1073#1088#1072#1090#1100' '#1089#1090#1091#1076#1077#1085#1090#1086#1074
      Default = True
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Glyph.Data = {
        DE010000424DDE01000000000000760000002800000024000000120000000100
        0400000000006801000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333333333330000333333333333333333333333F33333333333
        00003333344333333333333333388F3333333333000033334224333333333333
        338338F3333333330000333422224333333333333833338F3333333300003342
        222224333333333383333338F3333333000034222A22224333333338F338F333
        8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
        33333338F83338F338F33333000033A33333A222433333338333338F338F3333
        0000333333333A222433333333333338F338F33300003333333333A222433333
        333333338F338F33000033333333333A222433333333333338F338F300003333
        33333333A222433333333333338F338F00003333333333333A22433333333333
        3338F38F000033333333333333A223333333333333338F830000333333333333
        333A333333333333333338330000333333333333333333333333333333333333
        0000}
      NumGlyphs = 2
      ParentFont = False
      TabOrder = 0
      OnClick = BitBtn1Click
    end
    object BitBtn2: TBitBtn
      Left = 262
      Top = 13
      Width = 167
      Height = 30
      Cursor = crHandPoint
      Caption = #1054#1090#1084#1077#1085#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Kind = bkClose
      NumGlyphs = 2
      ParentFont = False
      TabOrder = 1
      OnClick = BitBtn2Click
    end
  end
end

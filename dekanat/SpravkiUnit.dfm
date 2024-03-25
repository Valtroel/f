object SpavkiForm: TSpavkiForm
  Left = 308
  Top = 171
  BorderIcons = [biSystemMenu]
  Caption = #1042#1099#1076#1072#1095#1072' '#1089#1087#1088#1072#1074#1086#1082' '#1089#1090#1091#1076#1077#1085#1090#1072#1084
  ClientHeight = 651
  ClientWidth = 882
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Visible = True
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 882
    Height = 121
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object DBGrid1: TDBGrid
      Left = 480
      Top = 2
      Width = 400
      Height = 117
      Align = alRight
      DataSource = DataModule1.People_SpravkiSource
      Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit]
      ReadOnly = True
      TabOrder = 0
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
      Visible = False
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
          Width = 119
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
          Width = 80
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
          Width = 66
          Visible = True
        end
        item
          Alignment = taCenter
          Expanded = False
          FieldName = 'N_GROUP'
          Title.Alignment = taCenter
          Title.Caption = #8470' '#1075#1088#1091#1087#1087#1099
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
          FieldName = 'KURS'
          Title.Alignment = taCenter
          Title.Caption = #1050#1091#1088#1089
          Title.Font.Charset = DEFAULT_CHARSET
          Title.Font.Color = clWindowText
          Title.Font.Height = -11
          Title.Font.Name = 'MS Sans Serif'
          Title.Font.Style = [fsBold]
          Width = 34
          Visible = True
        end>
    end
    object RadioGroup1: TRadioGroup
      Left = 8
      Top = 8
      Width = 137
      Height = 57
      Caption = #1042#1080#1076' '#1086#1073#1091#1095#1077#1085#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      Items.Strings = (
        #1044#1085#1077#1074#1085#1086#1077
        #1047#1072#1086#1095#1085#1086#1077)
      ParentFont = False
      TabOrder = 1
      OnClick = RadioGroup1Click
    end
    object LabeledEdit1: TLabeledEdit
      Left = 152
      Top = 21
      Width = 137
      Height = 21
      EditLabel.Width = 113
      EditLabel.Height = 13
      EditLabel.Caption = #1055#1086#1080#1089#1082' '#1087#1086' '#1092#1072#1084#1080#1083#1080#1080
      EditLabel.Font.Charset = DEFAULT_CHARSET
      EditLabel.Font.Color = clWindowText
      EditLabel.Font.Height = -11
      EditLabel.Font.Name = 'MS Sans Serif'
      EditLabel.Font.Style = [fsBold]
      EditLabel.ParentFont = False
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      Visible = False
      OnChange = LabeledEdit1Change
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 121
    Width = 882
    Height = 280
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 1
    Visible = False
    object Label1: TLabel
      Left = 11
      Top = 8
      Width = 168
      Height = 13
      Caption = #1052#1077#1089#1090#1086' '#1090#1088#1077#1073#1086#1074#1072#1085#1080#1103' '#1089#1087#1088#1072#1074#1082#1080':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Memo1: TMemo
      Left = 54
      Top = 25
      Width = 184
      Height = 25
      Lines.Strings = (
        #1087#1086' '#1084#1077#1089#1090#1091' '#1088#1072#1073#1086#1090#1099' '#1088#1086#1076#1080#1090#1077#1083#1077#1081'.')
      TabOrder = 0
    end
    object Memo2: TMemo
      Left = 54
      Top = 55
      Width = 184
      Height = 25
      Lines.Strings = (
        #1087#1086' '#1084#1077#1089#1090#1091' '#1088#1072#1073#1086#1090#1099'.')
      TabOrder = 1
    end
    object Memo3: TMemo
      Left = 54
      Top = 85
      Width = 184
      Height = 25
      Lines.Strings = (
        #1087#1086' '#1084#1077#1089#1090#1091' '#1090#1088#1077#1073#1086#1074#1072#1085#1080#1103'.')
      TabOrder = 2
    end
    object CheckBox1: TCheckBox
      Left = 32
      Top = 29
      Width = 20
      Height = 17
      TabOrder = 3
    end
    object CheckBox2: TCheckBox
      Left = 32
      Top = 59
      Width = 20
      Height = 17
      TabOrder = 4
    end
    object CheckBox3: TCheckBox
      Left = 32
      Top = 89
      Width = 20
      Height = 17
      TabOrder = 5
    end
    object Memo7: TMemo
      Left = 284
      Top = 85
      Width = 184
      Height = 25
      Lines.Strings = (
        #1074' '#1091#1095#1077#1073#1085#1086#1077' '#1079#1072#1074#1077#1076#1077#1085#1080#1077'.')
      TabOrder = 6
    end
    object CheckBox7: TCheckBox
      Left = 262
      Top = 89
      Width = 20
      Height = 17
      TabOrder = 7
    end
    object CheckBox6: TCheckBox
      Left = 262
      Top = 59
      Width = 20
      Height = 17
      TabOrder = 8
    end
    object Memo6: TMemo
      Left = 284
      Top = 55
      Width = 184
      Height = 25
      Lines.Strings = (
        #1074' '#1073#1091#1093#1075#1072#1083#1090#1077#1088#1080#1102'.')
      TabOrder = 9
    end
    object Memo5: TMemo
      Left = 284
      Top = 25
      Width = 184
      Height = 25
      Lines.Strings = (
        #1074' '#1046#1050#1061', '#1046#1069#1057'.')
      TabOrder = 10
    end
    object CheckBox5: TCheckBox
      Left = 262
      Top = 29
      Width = 20
      Height = 17
      TabOrder = 11
    end
    object Memo4: TMemo
      Left = 54
      Top = 115
      Width = 184
      Height = 25
      Lines.Strings = (
        #1087#1086' '#1084#1077#1089#1090#1091' '#1078#1080#1090#1077#1083#1100#1089#1090#1074#1072'.')
      TabOrder = 12
    end
    object CheckBox4: TCheckBox
      Left = 32
      Top = 119
      Width = 20
      Height = 17
      TabOrder = 13
    end
    object Memo8: TMemo
      Left = 284
      Top = 115
      Width = 184
      Height = 25
      Lines.Strings = (
        #1074' '#1089#1090#1091#1076#1077#1085#1095#1077#1089#1082#1086#1077' '#1073#1102#1088#1086' '#1091#1089#1083#1091#1075'.')
      TabOrder = 14
    end
    object CheckBox8: TCheckBox
      Left = 262
      Top = 119
      Width = 21
      Height = 17
      TabOrder = 15
    end
    object Memo17: TMemo
      Left = 398
      Top = 161
      Width = 125
      Height = 25
      Lines.Strings = (
        #1074' '#1056#1059#1042#1044' ')
      TabOrder = 16
    end
    object Memo18: TMemo
      Left = 398
      Top = 191
      Width = 125
      Height = 25
      Lines.Strings = (
        #1074' '#1072#1076#1084#1080#1085#1080#1089#1090#1088#1072#1094#1080#1102' ')
      TabOrder = 17
    end
    object Memo19: TMemo
      Left = 398
      Top = 221
      Width = 125
      Height = 25
      Lines.Strings = (
        #1074' '#1089#1077#1083#1100#1089#1082#1080#1081' '#1089#1086#1074#1077#1090'.')
      TabOrder = 18
    end
    object CheckBox17: TCheckBox
      Left = 376
      Top = 165
      Width = 20
      Height = 17
      TabOrder = 19
      OnClick = CheckBox17Click
    end
    object CheckBox18: TCheckBox
      Left = 376
      Top = 195
      Width = 20
      Height = 17
      TabOrder = 20
      OnClick = CheckBox18Click
    end
    object CheckBox19: TCheckBox
      Left = 376
      Top = 225
      Width = 20
      Height = 17
      TabOrder = 21
    end
    object Memo12: TMemo
      Left = 521
      Top = 115
      Width = 184
      Height = 25
      Lines.Strings = (
        #1074' '#1087#1086#1089#1086#1083#1100#1089#1090#1074#1086'.')
      TabOrder = 22
    end
    object CheckBox12: TCheckBox
      Left = 494
      Top = 119
      Width = 20
      Height = 17
      TabOrder = 23
    end
    object Memo13: TMemo
      Left = 54
      Top = 161
      Width = 307
      Height = 25
      Lines.Strings = (
        #1074' '#1094#1077#1085#1090#1088' '#1087#1086' '#1085#1072#1095#1080#1089#1083#1077#1085#1080#1102' '#1080' '#1074#1099#1087#1083#1072#1090#1077' '#1087#1077#1085#1089#1080#1081' '#1080' '#1087#1086#1089#1086#1073#1080#1081'.')
      TabOrder = 24
    end
    object Memo14: TMemo
      Left = 54
      Top = 191
      Width = 307
      Height = 25
      Lines.Strings = (
        #1074' '#1094#1077#1085#1090#1088' '#1089#1086#1094#1080#1072#1083#1100#1085#1086#1081' '#1079#1072#1085#1103#1090#1086#1089#1090#1080' '#1084#1086#1083#1086#1076#1077#1078#1080'.')
      TabOrder = 25
    end
    object Memo15: TMemo
      Left = 54
      Top = 221
      Width = 307
      Height = 25
      Lines.Strings = (
        #1074' '#1073#1080#1083#1077#1090#1085#1099#1077' '#1082#1072#1089#1089#1099'.')
      TabOrder = 26
    end
    object CheckBox13: TCheckBox
      Left = 32
      Top = 165
      Width = 20
      Height = 17
      TabOrder = 27
    end
    object CheckBox14: TCheckBox
      Left = 32
      Top = 195
      Width = 20
      Height = 17
      TabOrder = 28
    end
    object CheckBox15: TCheckBox
      Left = 32
      Top = 225
      Width = 20
      Height = 17
      TabOrder = 29
    end
    object Memo16: TMemo
      Left = 54
      Top = 251
      Width = 307
      Height = 25
      Lines.Strings = (
        #1074' '#1083#1077#1090#1085#1080#1081' '#1086#1079#1076#1086#1088#1086#1074#1080#1090#1077#1083#1100#1085#1099#1081' '#1083#1072#1075#1077#1088#1100'.')
      TabOrder = 30
    end
    object CheckBox16: TCheckBox
      Left = 32
      Top = 255
      Width = 20
      Height = 17
      TabOrder = 31
    end
    object Memo9: TMemo
      Left = 521
      Top = 25
      Width = 184
      Height = 25
      Lines.Strings = (
        #1074' '#1075#1086#1088#1074#1086#1076#1086#1082#1072#1085#1072#1083'.')
      TabOrder = 32
    end
    object Memo10: TMemo
      Left = 521
      Top = 55
      Width = 184
      Height = 25
      Lines.Strings = (
        #1074' '#1075#1086#1088#1075#1072#1079'.')
      TabOrder = 33
    end
    object Memo11: TMemo
      Left = 521
      Top = 85
      Width = 184
      Height = 25
      Lines.Strings = (
        #1074' '#1089#1091#1076'.')
      TabOrder = 34
    end
    object CheckBox9: TCheckBox
      Left = 494
      Top = 29
      Width = 20
      Height = 17
      TabOrder = 35
    end
    object CheckBox10: TCheckBox
      Left = 494
      Top = 59
      Width = 20
      Height = 17
      TabOrder = 36
    end
    object CheckBox11: TCheckBox
      Left = 494
      Top = 89
      Width = 20
      Height = 17
      TabOrder = 37
    end
    object Memo20: TMemo
      Left = 398
      Top = 251
      Width = 307
      Height = 25
      Lines.Strings = (
        '')
      TabOrder = 38
    end
    object CheckBox20: TCheckBox
      Left = 376
      Top = 255
      Width = 20
      Height = 17
      TabOrder = 39
    end
    object ComboBox1: TComboBox
      Left = 538
      Top = 163
      Width = 167
      Height = 21
      Style = csDropDownList
      TabOrder = 40
      Visible = False
      Items.Strings = (
        #1062#1077#1085#1090#1088#1072#1083#1100#1085#1086#1077
        #1057#1086#1074#1077#1090#1089#1082#1086#1077
        #1054#1082#1090#1103#1073#1088#1100#1089#1082#1086#1077
        #1055#1072#1088#1090#1080#1079#1072#1085#1089#1082#1086#1077
        #1060#1088#1091#1085#1079#1077#1085#1089#1082#1086#1077
        #1055#1077#1088#1074#1086#1084#1072#1081#1089#1082#1086#1077
        #1052#1086#1089#1082#1086#1074#1089#1082#1086#1077
        #1051#1077#1085#1080#1085#1089#1082#1086#1077
        #1047#1072#1074#1086#1076#1089#1082#1086#1077
        #1043#1086#1088#1086#1076#1089#1082#1086#1077
        #1052#1080#1085#1089#1082#1086#1075#1086' '#1088'-'#1085#1072)
    end
    object ComboBox2: TComboBox
      Left = 538
      Top = 193
      Width = 167
      Height = 21
      Style = csDropDownList
      TabOrder = 41
      Visible = False
      Items.Strings = (
        #1062#1077#1085#1090#1088#1072#1083#1100#1085#1086#1075#1086' '#1088#1072#1081#1086#1085#1072
        #1057#1086#1074#1077#1090#1089#1082#1086#1075#1086' '#1088#1072#1081#1086#1085#1072
        #1054#1082#1090#1103#1073#1088#1100#1089#1082#1086#1075#1086' '#1088#1072#1081#1086#1085#1072
        #1055#1072#1088#1090#1080#1079#1072#1085#1089#1082#1086#1075#1086' '#1088#1072#1081#1086#1085#1072
        #1060#1088#1091#1085#1079#1077#1085#1089#1082#1086#1075#1086' '#1088#1072#1081#1086#1085#1072
        #1055#1077#1088#1074#1086#1084#1072#1081#1089#1082#1086#1075#1086' '#1088#1072#1081#1086#1085#1072
        #1052#1086#1089#1082#1086#1074#1089#1082#1086#1075#1086' '#1088#1072#1081#1086#1085#1072
        #1051#1077#1085#1080#1085#1089#1082#1086#1075#1086' '#1088#1072#1081#1086#1085#1072
        #1047#1072#1074#1086#1076#1089#1082#1086#1075#1086' '#1088#1072#1081#1086#1085#1072)
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 401
    Width = 882
    Height = 144
    Align = alTop
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 2
    Visible = False
    object Label2: TLabel
      Left = 11
      Top = 8
      Width = 183
      Height = 13
      Caption = #1044#1086#1087#1086#1083#1085#1080#1090#1077#1083#1100#1085#1072#1103' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103':'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object CheckBox21: TCheckBox
      Left = 32
      Top = 29
      Width = 20
      Height = 17
      TabOrder = 0
    end
    object Memo21: TMemo
      Left = 54
      Top = 25
      Width = 307
      Height = 25
      Lines.Strings = (
        #1055#1086#1083#1091#1095#1072#1077#1090' '#1087#1077#1088#1074#1086#1077' '#1074#1099#1089#1096#1077#1077' '#1086#1073#1088#1072#1079#1086#1074#1072#1085#1080#1077'.')
      TabOrder = 1
    end
    object CheckBox22: TCheckBox
      Left = 32
      Top = 59
      Width = 20
      Height = 17
      TabOrder = 2
    end
    object Memo22: TMemo
      Left = 54
      Top = 55
      Width = 307
      Height = 25
      Lines.Strings = (
        #1054#1073#1091#1095#1072#1077#1090#1089#1103' '#1079#1072' '#1086#1087#1083#1072#1090#1091' '#1080#1083#1080' '#1079#1072' '#1089#1095#1077#1090' '#1073#1102#1076#1078#1077#1090#1085#1099#1093' '#1089#1088#1077#1076#1089#1090#1074'.')
      TabOrder = 3
    end
    object CheckBox23: TCheckBox
      Left = 32
      Top = 89
      Width = 20
      Height = 17
      TabOrder = 4
    end
    object Memo23: TMemo
      Left = 54
      Top = 85
      Width = 307
      Height = 25
      Lines.Strings = (
        #1055#1088#1080#1073#1083#1080#1079#1080#1090#1077#1083#1100#1085#1099#1081' '#1089#1088#1086#1082' '#1086#1082#1086#1085#1095#1072#1085#1080#1103' '#1091#1095#1077#1073#1085#1086#1075#1086' '#1079#1072#1074#1077#1076#1077#1085#1080#1103' ')
      TabOrder = 5
    end
    object Memo24: TMemo
      Left = 54
      Top = 115
      Width = 307
      Height = 25
      Lines.Strings = (
        #1047#1072#1095#1080#1089#1083#1077#1085' '#1087#1088#1080#1082#1072#1079#1086#1084' '#1086#1090'  '#8470'  '#1089#1090'.')
      TabOrder = 6
    end
    object CheckBox24: TCheckBox
      Left = 32
      Top = 119
      Width = 20
      Height = 17
      TabOrder = 7
    end
  end
  object Panel4: TPanel
    Left = 0
    Top = 545
    Width = 882
    Height = 106
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 3
    Visible = False
    object Button1: TButton
      Left = 87
      Top = 8
      Width = 146
      Height = 33
      Caption = #1055#1077#1088#1077#1076#1072#1090#1100' '#1074' Word'
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
  object ApplicationEvents1: TApplicationEvents
    OnMessage = ApplicationEvents1Message
    Left = 168
    Top = 256
  end
end

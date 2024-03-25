object PasswordDlg: TPasswordDlg
  Left = 245
  Top = 108
  BorderStyle = bsDialog
  Caption = 'Password Dialog'
  ClientHeight = 129
  ClientWidth = 228
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 49
    Width = 86
    Height = 13
    Caption = #1074#1074#1077#1076#1080#1090#1077' '#1087#1072#1088#1086#1083#1100':'
  end
  object Label2: TLabel
    Left = 12
    Top = 4
    Width = 79
    Height = 13
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1083#1086#1075#1080#1085':'
  end
  object LogPassForm: TEdit
    Left = 8
    Top = 68
    Width = 217
    Height = 21
    PasswordChar = '*'
    TabOrder = 0
  end
  object OKBtn: TButton
    Left = 70
    Top = 99
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 1
    OnClick = OKBtnClick
  end
  object CancelBtn: TButton
    Left = 151
    Top = 99
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 2
    OnClick = CancelBtnClick
  end
  object login: TEdit
    Left = 8
    Top = 22
    Width = 217
    Height = 21
    PasswordChar = '*'
    TabOrder = 3
  end
end

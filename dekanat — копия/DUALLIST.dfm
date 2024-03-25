object DualListDlg: TDualListDlg
  Left = 250
  Top = 108
  BorderStyle = bsDialog
  Caption = 'Choices Dialog'
  ClientHeight = 333
  ClientWidth = 522
  Color = clBtnFace
  ParentFont = True
  OldCreateOrder = True
  Position = poScreenCenter
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object SrcLabel: TLabel
    Left = 8
    Top = 8
    Width = 145
    Height = 16
    AutoSize = False
    Caption = 'Source List:'
  end
  object DstLabel: TLabel
    Left = 280
    Top = 8
    Width = 145
    Height = 16
    AutoSize = False
    Caption = 'Destination List:'
  end
  object IncludeBtn: TSpeedButton
    Left = 250
    Top = 34
    Width = 24
    Height = 24
    Caption = '>'
    OnClick = IncludeBtnClick
  end
  object IncAllBtn: TSpeedButton
    Left = 250
    Top = 64
    Width = 24
    Height = 24
    Caption = '>>'
    OnClick = IncAllBtnClick
  end
  object ExcludeBtn: TSpeedButton
    Left = 250
    Top = 96
    Width = 24
    Height = 24
    Caption = '<'
    Enabled = False
    OnClick = ExcludeBtnClick
  end
  object ExAllBtn: TSpeedButton
    Left = 250
    Top = 128
    Width = 24
    Height = 24
    Caption = '<<'
    Enabled = False
    OnClick = ExcAllBtnClick
  end
  object OKBtn: TButton
    Left = 270
    Top = 300
    Width = 75
    Height = 25
    Caption = 'OK'
    Default = True
    ModalResult = 1
    TabOrder = 2
    OnClick = OKBtnClick
  end
  object CancelBtn: TButton
    Left = 350
    Top = 300
    Width = 75
    Height = 25
    Cancel = True
    Caption = 'Cancel'
    ModalResult = 2
    TabOrder = 3
    OnClick = CancelBtnClick
  end
  object HelpBtn: TButton
    Left = 431
    Top = 300
    Width = 75
    Height = 25
    Caption = 'Help'
    TabOrder = 4
    Visible = False
  end
  object SrcList: TListBox
    Left = 8
    Top = 24
    Width = 236
    Height = 270
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    MultiSelect = True
    ParentFont = False
    ScrollWidth = 1
    Sorted = True
    TabOrder = 0
    OnDblClick = SrcListDblClick
  end
  object DstList: TListBox
    Left = 280
    Top = 24
    Width = 234
    Height = 270
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    MultiSelect = True
    ParentFont = False
    ScrollWidth = 1
    TabOrder = 1
    OnDblClick = DstListDblClick
  end
end

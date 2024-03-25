object Raspred_StateForm: TRaspred_StateForm
  Left = 264
  Top = 136
  ClientHeight = 561
  ClientWidth = 782
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poScreenCenter
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel2: TPanel
    Left = 0
    Top = 0
    Width = 782
    Height = 561
    Align = alClient
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 0
    object Panel6: TPanel
      Left = 2
      Top = 2
      Width = 778
      Height = 56
      Align = alTop
      ParentColor = True
      TabOrder = 0
      object GroupBox2: TGroupBox
        Left = 8
        Top = 1
        Width = 281
        Height = 51
        HelpContext = 70
        Caption = #1055#1086#1080#1089#1082' '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object Edit6: TEdit
          Left = 6
          Top = 15
          Width = 267
          Height = 21
          TabOrder = 0
          OnChange = Edit6Change
        end
      end
      object BitBtn8: TBitBtn
        Left = 298
        Top = 10
        Width = 85
        Height = 25
        Caption = 'Excel'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'MS Sans Serif'
        Font.Style = [fsBold]
        Glyph.Data = {
          4E010000424D4E01000000000000760000002800000012000000120000000100
          040000000000D800000000000000000000001000000010000000000000000000
          BF0000BF000000BFBF00BF000000BF00BF00BFBF0000C0C0C000808080000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00777777777777
          7777770000007777777777777777770000007777777777770007770000007444
          4400000006007700000074FFFF08880600080700000074F008000060EE070700
          000074FFFFF8060EE0047700000074F0088060EE00F47700000074FFFF060EE0
          00747700000074F00800EE0EE0047700000074FFFF0EE0F0EE047700000074F0
          080000F000047700000074FFFFFFFFFFFFF47700000074444444444444447700
          000074F444F444F444F477000000744444444444444477000000777777777777
          777777000000777777777777777777000000}
        ParentFont = False
        TabOrder = 1
        OnClick = BitBtn8Click
      end
    end
    object DBGrid1: TDBGrid
      Left = 16
      Top = 72
      Width = 753
      Height = 473
      TabOrder = 1
      TitleFont.Charset = DEFAULT_CHARSET
      TitleFont.Color = clWindowText
      TitleFont.Height = -11
      TitleFont.Name = 'MS Sans Serif'
      TitleFont.Style = []
    end
  end
end

object ConstrucaoLines: TConstrucaoLines
  Left = 100
  Top = 100
  BorderIcons = [biSystemMenu]
  BorderStyle = bsDialog
  BorderWidth = 3
  Caption = 'Constru'#231'ao de Linhas'
  ClientHeight = 280
  ClientWidth = 627
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  PixelsPerInch = 96
  TextHeight = 13
  object LTitulo: TLabel
    Left = 179
    Top = 6
    Width = 227
    Height = 29
    Caption = 'Constru'#231#227'o de Linhas'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Panel1: TPanel
    Left = 63
    Top = 48
    Width = 513
    Height = 210
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 0
    object LMPonto: TLabel
      Left = 231
      Top = 40
      Width = 61
      Height = 19
      Caption = 'LMPonto'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlue
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object LLPonto: TLabel
      Left = 231
      Top = 94
      Width = 57
      Height = 19
      Caption = 'LLPonto'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clFuchsia
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object LXo: TLabel
      Left = 24
      Top = 28
      Width = 18
      Height = 19
      Caption = 'Xo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object LYo: TLabel
      Left = 24
      Top = 68
      Width = 19
      Height = 19
      Caption = 'Yo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object LZo: TLabel
      Left = 24
      Top = 108
      Width = 18
      Height = 19
      Caption = 'Zo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object EdtXo: TEdit
      Left = 59
      Top = 24
      Width = 121
      Height = 27
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      Text = '0,0'
    end
    object EdtYo: TEdit
      Left = 59
      Top = 65
      Width = 121
      Height = 27
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      Text = '0,0'
    end
    object EdtZo: TEdit
      Left = 59
      Top = 105
      Width = 121
      Height = 27
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      Text = '0,0'
    end
    object BConstruirLine: TButton
      Left = 231
      Top = 147
      Width = 89
      Height = 41
      Caption = 'Line'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = BConstruirLineClick
    end
    object Cores: TColorBox
      Left = 24
      Top = 154
      Width = 156
      Height = 36
      Style = [cbStandardColors]
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ItemHeight = 30
      ParentFont = False
      ParentShowHint = False
      ShowHint = False
      TabOrder = 4
    end
  end
end

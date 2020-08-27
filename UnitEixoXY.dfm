object EixoXY: TEixoXY
  Left = 0
  Top = 0
  Cursor = crCross
  Caption = 'EixoXY'
  ClientHeight = 723
  ClientWidth = 1284
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -16
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PopupMenu = PMEixoXY
  WindowState = wsMaximized
  OnMouseDown = FormMouseDown
  OnMouseMove = FormMouseMove
  PixelsPerInch = 96
  TextHeight = 19
  object Teste: TLabel
    Left = 368
    Top = 248
    Width = 45
    Height = 23
    Caption = 'Teste'
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object DrawCursor: TLabel
    Left = 168
    Top = 208
    Width = 84
    Height = 19
    Caption = 'DrawCursor'
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 1284
    Height = 145
    Align = alTop
    Caption = 'Panel1'
    ShowCaption = False
    TabOrder = 0
    object Panel2: TPanel
      Left = 415
      Top = 12
      Width = 146
      Height = 126
      Caption = 'Panel2'
      ShowCaption = False
      TabOrder = 0
      object RGLine: TRadioGroup
        Left = 17
        Top = 7
        Width = 120
        Height = 107
        Caption = 'RGLine'
        TabOrder = 0
      end
      object Line: TRadioButton
        Left = 29
        Top = 41
        Width = 70
        Height = 17
        Caption = 'Line'
        TabOrder = 1
        OnClick = LineClick
      end
      object Cancela_Line: TRadioButton
        Left = 29
        Top = 70
        Width = 82
        Height = 17
        Caption = 'Cancela'
        Checked = True
        TabOrder = 2
        TabStop = True
      end
    end
    object Panel3: TPanel
      Left = 248
      Top = 16
      Width = 145
      Height = 122
      Caption = 'Panel3'
      ShowCaption = False
      TabOrder = 1
      object ButtonEixo_Zo: TButton
        Left = 32
        Top = 1
        Width = 102
        Height = 37
        Caption = 'EixoZo'
        Default = True
        Style = bsCommandLink
        TabOrder = 0
        OnClick = ButtonEixo_ZoClick
      end
      object BEixoYo: TButton
        Left = 32
        Top = 39
        Width = 102
        Height = 37
        Caption = 'BEixoYo'
        Style = bsCommandLink
        TabOrder = 1
        OnClick = BEixoYoClick
      end
      object BEixoXo: TButton
        Left = 32
        Top = 78
        Width = 102
        Height = 37
        Caption = 'BEixoXo'
        Style = bsCommandLink
        TabOrder = 2
        OnClick = BEixoXoClick
      end
    end
    object Panel4: TPanel
      Left = 6
      Top = 12
      Width = 246
      Height = 126
      Caption = 'Panel4'
      ShowCaption = False
      TabOrder = 2
      object Cores: TColorBox
        Left = 8
        Top = 82
        Width = 231
        Height = 36
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -24
        Font.Name = 'Tahoma'
        Font.Style = []
        ItemHeight = 30
        ParentFont = False
        TabOrder = 0
      end
      object BDiminuir: TButton
        Left = 134
        Top = 24
        Width = 105
        Height = 37
        Caption = 'BDiminuir'
        Default = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        Style = bsCommandLink
        TabOrder = 1
        OnClick = BDiminuirClick
      end
      object BAumentar: TButton
        Left = 8
        Top = 22
        Width = 105
        Height = 37
        Caption = 'BAumentar'
        Default = True
        Style = bsCommandLink
        TabOrder = 2
        OnClick = BAumentarClick
      end
    end
    object Panel5: TPanel
      Left = 567
      Top = 12
      Width = 602
      Height = 126
      Caption = 'Panel5'
      ShowCaption = False
      TabOrder = 3
      object RGVisao: TRadioGroup
        Left = 16
        Top = -3
        Width = 193
        Height = 113
        Caption = 'RGVisao'
        TabOrder = 0
      end
      object RBVisaoXoZ: TRadioButton
        Left = 48
        Top = 52
        Width = 113
        Height = 17
        Caption = 'RBVisaoXoZ'
        TabOrder = 1
        OnClick = RBVisaoXoZClick
      end
      object RBVisaoXoY: TRadioButton
        Left = 48
        Top = 24
        Width = 113
        Height = 17
        Caption = 'RBVisaoXoY'
        Checked = True
        TabOrder = 2
        TabStop = True
        OnClick = RBVisaoXoYClick
      end
      object RBVisaoYoZ: TRadioButton
        Left = 48
        Top = 81
        Width = 113
        Height = 17
        Caption = 'RBVisaoYoZ'
        TabOrder = 3
        OnClick = RBVisaoYoZClick
      end
      object EdtXo: TEdit
        Left = 224
        Top = 12
        Width = 121
        Height = 27
        Enabled = False
        TabOrder = 4
        Text = '0,0'
      end
      object EdtYo: TEdit
        Left = 224
        Top = 45
        Width = 121
        Height = 27
        Enabled = False
        TabOrder = 5
        Text = '0,0'
      end
      object EdtZo: TEdit
        Left = 224
        Top = 78
        Width = 121
        Height = 27
        TabOrder = 6
        Text = '0,0'
      end
      object BtnAbrir: TButton
        Left = 409
        Top = 67
        Width = 97
        Height = 49
        Caption = 'BtnAbrir'
        TabOrder = 7
        OnClick = BtnAbrirClick
      end
      object BtnSalvar: TButton
        Left = 409
        Top = 12
        Width = 97
        Height = 49
        Caption = 'BtnSalvar'
        TabOrder = 8
        OnClick = BtnSalvarClick
      end
    end
  end
  object Tempo_Eixo: TTimer
    Interval = 30
    OnTimer = Tempo_EixoTimer
    Left = 208
    Top = 392
  end
  object Tempo_Draw: TTimer
    Interval = 24
    OnTimer = Tempo_DrawTimer
    Left = 216
    Top = 296
  end
  object PMEixoXY: TPopupMenu
    Left = 632
    Top = 368
    object ConstruirLinha1: TMenuItem
      Caption = 'Construir Linha'
      OnClick = ConstruirLinha1Click
    end
    object PElipse: TMenuItem
      Caption = 'Construir Elipses'
      OnClick = PElipseClick
    end
  end
  object DlgSalvar: TSaveDialog
    DefaultExt = 'DEN'
    Filter = 'desenhos EixoXY_64(*DEN)|*.DEN'
    Left = 80
    Top = 320
  end
  object DlgAbrir: TOpenDialog
    Filter = 'Desenho EixoXY_64|*.DEN'
    Left = 504
    Top = 192
  end
end

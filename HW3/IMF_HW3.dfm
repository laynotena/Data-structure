object Form1: TForm1
  Left = 0
  Top = 0
  Align = alClient
  Caption = 'Form1'
  ClientHeight = 656
  ClientWidth = 747
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 0
    Top = 137
    Width = 747
    Height = 13
    Cursor = crVSplit
    Align = alTop
    ExplicitTop = 124
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 747
    Height = 137
    Align = alTop
    TabOrder = 0
    ExplicitTop = -6
    object Label1: TLabel
      Left = 56
      Top = 4
      Width = 96
      Height = 23
      Caption = 'Square size :'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 56
      Top = 55
      Width = 111
      Height = 23
      Caption = '5 <= size <= 21'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
    end
    object Button1: TButton
      Left = 56
      Top = 84
      Width = 121
      Height = 33
      Caption = 'Magic Square'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = Button1Click
    end
    object Edit1: TEdit
      Left = 56
      Top = 28
      Width = 121
      Height = 21
      TabOrder = 1
      Text = '7'
    end
    object GroupBox1: TGroupBox
      Left = 491
      Top = 16
      Width = 233
      Height = 89
      Caption = 'Move Direction'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      object RadioButton1: TRadioButton
        Left = 3
        Top = 23
        Width = 86
        Height = 28
        Caption = 'Left - Up'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 0
      end
      object RadioButton2: TRadioButton
        Left = 110
        Top = 20
        Width = 100
        Height = 32
        Caption = 'Right - Up'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 1
      end
      object RadioButton3: TRadioButton
        Left = 3
        Top = 57
        Width = 101
        Height = 24
        Caption = 'Left - Down'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 2
      end
      object RadioButton4: TRadioButton
        Left = 110
        Top = 53
        Width = 132
        Height = 31
        Caption = 'Right - Down'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Tahoma'
        Font.Style = []
        ParentFont = False
        TabOrder = 3
      end
    end
    object GroupBox2: TGroupBox
      Left = 224
      Top = 13
      Width = 229
      Height = 92
      Caption = 'Start '
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      object RadioButton5: TRadioButton
        Left = 80
        Top = 19
        Width = 58
        Height = 40
        Caption = 'Top'
        TabOrder = 0
      end
      object RadioButton6: TRadioButton
        Left = 3
        Top = 38
        Width = 62
        Height = 24
        Caption = 'Left'
        TabOrder = 1
      end
      object RadioButton7: TRadioButton
        Left = 149
        Top = 35
        Width = 60
        Height = 24
        Caption = 'Right'
        TabOrder = 2
      end
      object RadioButton8: TRadioButton
        Left = 80
        Top = 61
        Width = 81
        Height = 25
        Caption = 'Buttom'
        TabOrder = 3
      end
    end
  end
  object PageControl1: TPageControl
    Left = 0
    Top = 150
    Width = 747
    Height = 506
    ActivePage = TabSheet4
    Align = alClient
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'Not Aligned'
      object Memo1: TMemo
        Left = 0
        Top = 0
        Width = 739
        Height = 478
        Align = alClient
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Aligned'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 739
        Height = 478
        Align = alClient
        Lines.Strings = (
          'Memo2')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object TabSheet3: TTabSheet
      Caption = 'RichEdit'
      ImageIndex = 2
      object RichEdit1: TRichEdit
        Left = 0
        Top = 0
        Width = 739
        Height = 478
        Align = alClient
        Font.Charset = CHINESEBIG5_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Consolas'
        Font.Style = []
        Lines.Strings = (
          'RichEdit1')
        ParentFont = False
        ScrollBars = ssVertical
        TabOrder = 0
        Zoom = 100
      end
    end
    object TabSheet4: TTabSheet
      Caption = 'StringGrid'
      ImageIndex = 3
      object StringGrid1: TStringGrid
        Left = 0
        Top = 0
        Width = 739
        Height = 478
        Align = alClient
        TabOrder = 0
      end
    end
  end
end
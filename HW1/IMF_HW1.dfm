object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Selection vs. Bubble sorts by Jessica.C  2019/09/25 Ver.1.0'
  ClientHeight = 493
  ClientWidth = 927
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -9
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 11
  object Label1: TLabel
    Left = 138
    Top = 27
    Width = 20
    Height = 19
    Caption = 'n ='
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 92
    Top = 58
    Width = 49
    Height = 19
    Caption = 'range ='
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 728
    Top = 51
    Width = 51
    Height = 19
    Caption = 'target ='
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = []
    ParentFont = False
  end
  object Button1: TButton
    Left = 30
    Top = 86
    Width = 187
    Height = 43
    Caption = 'Generate Random Numbers'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Edit1: TEdit
    Left = 162
    Top = 24
    Width = 55
    Height = 27
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Text = '10'
  end
  object Memo1: TMemo
    Left = 30
    Top = 135
    Width = 187
    Height = 350
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Calibri'
    Font.Style = []
    Lines.Strings = (
      'Memo1')
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 2
  end
  object Edit2: TEdit
    Left = 144
    Top = 56
    Width = 73
    Height = 27
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    Text = '1000'
  end
  object Button2: TButton
    Left = 258
    Top = 84
    Width = 183
    Height = 42
    Caption = 'Selection Sort'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button2Click
  end
  object Memo2: TMemo
    Left = 258
    Top = 132
    Width = 183
    Height = 353
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Calibri'
    Font.Style = []
    Lines.Strings = (
      'Memo2')
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 5
  end
  object CheckBox1: TCheckBox
    Left = 266
    Top = 24
    Width = 97
    Height = 20
    Caption = 'Echo print'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Calibri'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
  end
  object Memo3: TMemo
    Left = 480
    Top = 132
    Width = 193
    Height = 353
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Calibri'
    Font.Style = []
    Lines.Strings = (
      'Memo3')
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 7
  end
  object Button3: TButton
    Left = 480
    Top = 84
    Width = 193
    Height = 42
    Caption = 'Bubble Sort'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    OnClick = Button3Click
  end
  object Memo4: TMemo
    Left = 712
    Top = 132
    Width = 195
    Height = 353
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Calibri'
    Font.Style = []
    Lines.Strings = (
      'Memo4')
    ParentFont = False
    ScrollBars = ssVertical
    TabOrder = 9
  end
  object Button4: TButton
    Left = 712
    Top = 84
    Width = 195
    Height = 42
    Caption = 'Binary Search'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = []
    ParentFont = False
    TabOrder = 10
    OnClick = Button4Click
  end
  object CheckBox2: TCheckBox
    Left = 266
    Top = 52
    Width = 97
    Height = 17
    Caption = 'Self-check'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Calibri'
    Font.Style = []
    ParentFont = False
    TabOrder = 11
  end
  object Edit3: TEdit
    Left = 785
    Top = 48
    Width = 121
    Height = 27
    DoubleBuffered = False
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Calibri'
    Font.Style = []
    ParentDoubleBuffered = False
    ParentFont = False
    TabOrder = 12
    Text = '200'
  end
end
object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 477
  ClientWidth = 707
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
    Left = 185
    Top = 0
    Height = 477
    ExplicitLeft = 200
    ExplicitTop = 304
    ExplicitHeight = 100
  end
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 185
    Height = 477
    Align = alLeft
    TabOrder = 0
    object PageControl2: TPageControl
      Left = 1
      Top = 1
      Width = 183
      Height = 209
      ActivePage = TabSheet8
      Align = alTop
      TabOrder = 0
      object TabSheet3: TTabSheet
        Caption = 'Permute"ABC"'
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object Label1: TLabel
          Left = 14
          Top = 3
          Width = 26
          Height = 23
          Caption = 'k = '
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
        end
        object Label2: TLabel
          Left = 13
          Top = 32
          Width = 27
          Height = 23
          Caption = 'n = '
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
        end
        object Label3: TLabel
          Left = 9
          Top = 66
          Width = 62
          Height = 23
          Caption = ' (n <= 9)'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
        end
        object Edit1: TEdit
          Left = 46
          Top = 5
          Width = 121
          Height = 21
          TabOrder = 0
          Text = '0'
        end
        object Edit2: TEdit
          Left = 46
          Top = 36
          Width = 121
          Height = 21
          TabOrder = 1
          Text = '3'
        end
        object Button1: TButton
          Left = 9
          Top = 115
          Width = 153
          Height = 41
          Caption = 'Permutations'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = Button1Click
        end
      end
      object TabSheet4: TTabSheet
        Caption = 'arbitrary input'
        ImageIndex = 1
        ExplicitLeft = 0
        ExplicitTop = 0
        ExplicitWidth = 0
        ExplicitHeight = 0
        object Label4: TLabel
          Left = 3
          Top = 3
          Width = 53
          Height = 23
          Caption = 'string :'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
        end
        object Label5: TLabel
          Left = 32
          Top = 32
          Width = 26
          Height = 23
          Caption = 'k = '
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
        end
        object Edit3: TEdit
          Left = 64
          Top = 3
          Width = 97
          Height = 21
          TabOrder = 0
          Text = 'abcde'
        end
        object Edit4: TEdit
          Left = 64
          Top = 36
          Width = 97
          Height = 21
          TabOrder = 1
          Text = '0'
        end
        object Button2: TButton
          Left = 16
          Top = 69
          Width = 140
          Height = 41
          Caption = 'PermStr'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
          OnClick = Button2Click
        end
        object Button3: TButton
          Left = 16
          Top = 123
          Width = 140
          Height = 46
          Caption = 'PermChar'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
          TabOrder = 3
          OnClick = Button3Click
        end
      end
      object TabSheet8: TTabSheet
        Caption = 'Towers of Honoi'
        ImageIndex = 2
        object Label6: TLabel
          Left = 8
          Top = 7
          Width = 137
          Height = 23
          Caption = 'Number of Disks :'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
        end
        object Edit5: TEdit
          Left = 6
          Top = 37
          Width = 151
          Height = 21
          TabOrder = 0
          Text = '3'
        end
        object Button4: TButton
          Left = 9
          Top = 98
          Width = 151
          Height = 46
          Caption = 'Towers of Honoi'
          Font.Charset = ANSI_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Calibri'
          Font.Style = []
          ParentFont = False
          TabOrder = 1
          OnClick = Button4Click
        end
      end
    end
    object CheckBox1: TCheckBox
      Left = 101
      Top = 216
      Width = 81
      Height = 25
      Caption = 'Tracing'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Calibri'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
  end
  object PageControl1: TPageControl
    Left = 188
    Top = 0
    Width = 519
    Height = 477
    ActivePage = TabSheet2
    Align = alClient
    TabOrder = 1
    object TabSheet1: TTabSheet
      Caption = 'Permutations / Hanoi'
      ExplicitLeft = 0
      ExplicitTop = 0
      ExplicitWidth = 0
      ExplicitHeight = 0
      object Memo1: TMemo
        Left = 56
        Top = 24
        Width = 385
        Height = 401
        Lines.Strings = (
          'Memo1')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
    object TabSheet2: TTabSheet
      Caption = 'Permutation Tracing'
      ImageIndex = 1
      object Memo2: TMemo
        Left = 0
        Top = 0
        Width = 511
        Height = 449
        Align = alClient
        Lines.Strings = (
          'Memo2')
        ScrollBars = ssVertical
        TabOrder = 0
      end
    end
  end
end

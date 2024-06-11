object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 532
  ClientWidth = 621
  Color = cl3DLight
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object tlabel: TLabel
    Left = 16
    Top = 35
    Width = 28
    Height = 15
    Caption = 'Tytu'#322':'
  end
  object rlabel: TLabel
    Left = 213
    Top = 35
    Width = 42
    Height = 15
    Caption = 'Re'#380'yser:'
  end
  object tlabel2: TLabel
    Left = 417
    Top = 35
    Width = 47
    Height = 15
    Caption = 'Gatunek:'
  end
  object rlabel2: TLabel
    Left = 213
    Top = 93
    Width = 70
    Height = 15
    Caption = 'Rok wydania:'
  end
  object slabel: TLabel
    Left = 472
    Top = 223
    Width = 101
    Height = 15
    Caption = 'Sortowanie wed'#322'ug'
  end
  object Label7: TLabel
    Left = 17
    Top = 8
    Width = 61
    Height = 15
    Caption = 'FILMOTEKA'
  end
  object title: TEdit
    Left = 16
    Top = 56
    Width = 185
    Height = 23
    TabOrder = 0
  end
  object director: TEdit
    Left = 213
    Top = 56
    Width = 185
    Height = 23
    TabOrder = 1
  end
  object year: TEdit
    Left = 213
    Top = 122
    Width = 185
    Height = 23
    NumbersOnly = True
    TabOrder = 2
  end
  object save: TButton
    Left = 17
    Top = 181
    Width = 185
    Height = 25
    Caption = 'ZAPISZ'
    TabOrder = 3
    OnClick = saveClick
  end
  object list: TListBox
    Left = 17
    Top = 223
    Width = 416
    Height = 279
    ItemHeight = 15
    TabOrder = 4
  end
  object edit: TButton
    Left = 475
    Top = 105
    Width = 114
    Height = 25
    Caption = 'EDYTUJ'
    TabOrder = 5
    OnClick = editClick
  end
  object del: TButton
    Left = 475
    Top = 136
    Width = 113
    Height = 25
    Caption = 'USU'#323
    TabOrder = 6
    OnClick = delClick
  end
  object genre: TComboBox
    Left = 417
    Top = 56
    Width = 185
    Height = 23
    ItemIndex = 0
    TabOrder = 7
    Text = 'Komedia'
    Items.Strings = (
      'Komedia'
      'Dramat'
      'Western'
      'Horror'
      'Musical'
      'Thriller'
      'Film sensacyjny'
      'Krymina'#322
      'Science fiction')
  end
  object clear: TButton
    Left = 464
    Top = 477
    Width = 125
    Height = 25
    Caption = 'RESET BAZY'
    TabOrder = 8
    OnClick = clearAllClick
  end
  object sorting: TComboBox
    Left = 466
    Top = 244
    Width = 123
    Height = 23
    ItemIndex = 0
    TabOrder = 9
    Text = 'tytu'#322'u'
    OnChange = sortingChange
    Items.Strings = (
      'tytu'#322'u'
      'roku')
  end
  object stan: TRadioGroup
    Left = 17
    Top = 85
    Width = 185
    Height = 76
    Caption = 'Stan Wypo'#380'yczenia: '
    ItemIndex = 0
    Items.Strings = (
      'Tak'
      'Nie')
    TabOrder = 10
  end
end

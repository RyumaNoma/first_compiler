# First Compiler
- I confirmed that this compiler worked on gcc.
- This is first compiler I made. If you want to point out about my program or README.md's English, please make issue or pull request.

- I made this compiler to deepen understanding my school's lesson.

- gcc上で動作することを確認しています。
- このレポジトリは私が作った初めてのコンパイラです。プログラムやREADME.mdについて指摘したい点があれば、イシューまたはプルリクエストをたててください。
- 学校の授業の理解を深めるためにこのコンパイラを作っています。

# Index
- [Lexical Analysis](#lexical-analysis)
    - [How to Use](#how-to-use)
    - [Kinds of Token and Keyword](#kinds-of-token-and-keyword)

# Lexical Analysis
- convert words of a text file to tokens.
- output tokens on text file.
- this program can analyze up to 128 words.

- テキストファイルの文字列をトークン列に変換します。
- トークン列をテキストファイルに出力します。
- 128単語まで解析を行うことができます。

## How to Use
Put a text file (a.txt) to analyze in lexical analysis directory.And, input follow commands in lexical analysis directory.

テキストファイルをlexical analysisディレクトリにおいてください。そして、以下のコマンドをlexical analysisディレクトリ内で入力してください。

```gcc -o word main.c word.c```

```./word a.txt```

## Kinds of Token and Keyword
Tokens and keywords define on `enum TOKEN(lexical analysis/word.h)` and `char token_names(lexical analysis/word.c)`

Keywords are same with a C language.

`enum TOKEN(lexical analysis/word.h)` と `char token_names(lexical analysis/word.c)`において定義されているトークンとキーワードの種類です。

キーワードはC言語と同じです。

|Token Name|Symbol|
|:-:|:-:|
|error|undefined symbol or end of file|
|white space| (space) \| \t \| \n|
|identifier|alphabet{alphabet \| digit}|
|number|digit { digit }|
|semi colon|;|
|equal|=|
|equal equal|==|
|bigger|>|
|bigger equal|>=|
|smaller|<|
|smaller equal|<=|
|left parenthsis|(|
|right parenthsis|)|
|plus|+|
|minus|-|
|asterisk|\*|
|slash|/|
|comment start|/\*|
|comment end|\*/|
|percent|%|
|single quotation|'|
|double quotation|"|

|Keywords|||||
|:-:|:-:|:-:|:-:|:-:|:-:|
|auto|break|case|char|const|continue|
|default|do|double|else|enum|extern|
|float|for|goto|if|int|long|
|register|return|short|signed|sizeof|static|
|struct|switch|typedef|union|unsigned|void|
|volatile|while|
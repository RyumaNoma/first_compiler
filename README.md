# First Compiler
- I confirmed that this compiler worked on gcc.
- This is first compiler I made. If you want to point out about my program or README.md's English, please make issue or pull request.

- I made this compiler to deepen understanding my school's lesson.
- Update frequency of README.md and repository are low.

## Lexical Analysis
- convert words of a text file to tokens.
- output tokens on console.
- this program can analyze up to 128 words.

### How to Use
Put a text file (a.txt) to analyze in lexical analysis directory.And, input follow commands in lexical analysis directory.

```gcc -o word main.c word.c```

```./word a.txt```

### Kinds of Token
tokens define on `enum TOKEN(lexical analysis/word.h)` and `char token_names(lexical analysis/word.c)`
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

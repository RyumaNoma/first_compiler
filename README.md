# First Compiler
- I confirmed this compiler on gcc.
- This is first compiler I made. If you want to point out about my program or README.md's English, please make issue or pull request.

I made this compiler to deepen understanding my school's lesson.

## Lexical Analysis
- convert words of `./lexical analysis/a.txt` to tokens.
- output tokens on console.
- this program can analyze up to 128 words.

### How to Use
Input follow commands in lexical analysis directory.

```gcc -o word main.c word.c```

```./word a.txt```

### Kinds of Token
tokens define on `enum TOKEN(lexical analysis/word.h)` and `char token_names(lexical analysis/word.c)`
|Token Name|Symbol|
|:-:|:-:|
|error|end of file|
|white space| (space) \| \t \| \n|
|identifier|alphabet{alphabet \| digit}|
|number|digit|

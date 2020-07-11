#pragma once

#include <stdio.h>
#include <ctype.h>

#define Alphabet "abcdefghijklmnopqrstuvwxyz"
#define Digit "0123456789"
#define WhiteSpace "\t\n "
#define Semicol ";"
#define Eq "="
#define Big ">"
//#define Bigeq ">="
#define Small "<"
//#define Smalleq "<="
//#define Eqeq "=="
#define Lpar "("
#define Rpar ")"
#define Plus "+"
#define Minus "-"
#define Aster "*"
#define Slash "/"
//#define Comst "/*"
//#define Comend "*/"
#define Percent "%"
#define Singlequ "'"
#define Doublequ "\""
#define SOF '\0'

typedef enum
{
	ERROR,
	WHITESPACE,
	ID,
	NUM,
	SEMICOL,
	EQ,
	EQEQ,
	BIG,
	BIGEQ,
	SMALL,
	SMALLEQ,
	LPAR,
	RPAR,
	PLUS,
	MINUS,
	ASTER,
	SLASH,
	COMST,
	COMEND,
	PERCENT,
	SINGLEQU,
	DOUBLEQU,
} TOKEN;

extern const char token_names[][50];

int char_pos(char key, char* char_group);
TOKEN get_token(FILE* fp, char* first_char);
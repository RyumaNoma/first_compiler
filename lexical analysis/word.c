#include "word.h"
#include <ctype.h>

#define TRUE 1
#define FALSE 0

//•¶Žš—ñchar_group‚Ì’†‚É•¶Žškey‚ª‚ ‚é‚©‚ð”»•Ê‚·‚é
//‚ ‚é‚È‚çA“Y‚¦Žš‚ð•Ô‚·
int char_pos(char key, char* char_group)
{
	int index = 0;
	
	while(char_group[index] != '\0')
	{
		if(key == char_group[index])
		{
			return index;
		}
		
		index ++;
	}
	
	return -1;
}

int is_same(char* terget, char* keyword)
{
	int flag = TRUE;
	
	while(*terget && *keyword)
	{
		if(*terget++ != *keyword++)
		{
			flag = FALSE;
			break;
		}
	}
	
	return flag;
}

TOKEN get_token(FILE* fp, char* first_char)
{
	char c;
	char last_char;
	char word[128];
	int idx = 0;
		
	if(*first_char == SOF)
	{
		c = fgetc(fp);
	}
	else
	{
		c = *first_char;
	}
	
	
	// first character
	if(char_pos(c, WhiteSpace) >= 0)
	{
		*first_char = fgetc(fp);
		return WHITESPACE;
	}
	else if(char_pos(c, Digit) >= 0)
	{
		goto num;
	}
	else if(char_pos(tolower(c), Alphabet) >= 0)
	{
		word[idx++] = c;
		goto id;
	}
	else if(char_pos(c, Semicol) >= 0)
	{
		*first_char = fgetc(fp);
		return SEMICOL;
	}
	else if(char_pos(c, Eq) >= 0)
	{
		goto eq;
	}
	else if(char_pos(c, Big) >= 0)
	{
		goto eq;
	}
	else if(char_pos(c, Small) >= 0)
	{
		goto eq;
	}
	else if(char_pos(c, Lpar) >= 0)
	{
		*first_char = fgetc(fp);
		return LPAR;
	}
	else if(char_pos(c, Rpar) >= 0)
	{
		*first_char = fgetc(fp);
		return RPAR;
	}
	else if(char_pos(c, Plus) >= 0)
	{
		*first_char = fgetc(fp);
		return PLUS;
	}
	else if(char_pos(c, Minus) >= 0)
	{
		*first_char = fgetc(fp);
		return MINUS;
	}
	else if(char_pos(c, Aster) >= 0)
	{
		goto aster;
	}
	else if(char_pos(c, Slash) >= 0)
	{
		goto slash;
	}
	else if(char_pos(c, Percent) >= 0)
	{
		*first_char = fgetc(fp);
		return PERCENT;
	}
	else if(char_pos(c, Singlequ) >= 0)
	{
		*first_char = fgetc(fp);
		return SINGLEQU;
	}
	else if(char_pos(c, Doublequ) >= 0)
	{
		*first_char = fgetc(fp);
		return DOUBLEQU;
	}
	else
	{
		*first_char = fgetc(fp);
		return ERROR;
	}
num:
	c = fgetc(fp);
	if(char_pos(c, Digit) >= 0)
	{
		goto num;
	}
	else
	{
		*first_char = c;
		return NUM;
	}
id:
	c = fgetc(fp);
	if(char_pos(c, Digit) >= 0)
	{
		word[idx++] = c;
		goto id;
	}
	else if(char_pos(tolower(c), Alphabet) >= 0)
	{
		word[idx++] = tolower(c);
		goto id;
	}
	else
	{
		*first_char = c;
		return get_keyword(word);
	}
eq:
	last_char = c;
	c = fgetc(fp);
	
	if(char_pos(c, Eq) >= 0)
	{
		if(char_pos(last_char, Eq) >= 0)
		{
			*first_char = fgetc(fp);
			return EQEQ;
		}
		else if(char_pos(last_char, Big) >= 0)
		{
			*first_char = fgetc(fp);
			return BIGEQ;
		}
		else if(char_pos(last_char, Small) >= 0)
		{
			*first_char = fgetc(fp);
			return SMALLEQ;
		}
	}
	else
	{
		*first_char = c;
		return EQ;
	}
slash:
	c = fgetc(fp);
	if(char_pos(c, Aster) >= 0)
	{
		*first_char = fgetc(fp);
		return COMST;
	}
	else
	{
		*first_char = c;
		return SLASH;
	}
aster:
	c = fgetc(fp);
	if(char_pos(c, Slash) >= 0)
	{
		*first_char = fgetc(fp);
		return COMEND;
	}
	else
	{
		*first_char = c;
		return ASTER;
	}
}

TOKEN get_keyword(char* word)
{
	//printf("word : %s\n", word);
	
	TOKEN keyword_tokens[32] = 
	{
		AUTO,
		BREAK,
		CASE,
		CHAR,
		CONST,
		CONTINUE,
		DEFAULT,
		DO,
		DOUBLE,
		ELSE,
		ENUM,
		EXTERN,
		FLOAT,
		FOR,
		GOTO,
		IF,
		INT,
		LONG,
		REGISTER,
		RETURN,
		SHORT,
		SIGNED,
		SIZEOF,
		STATIC,
		STRUCT,
		SWITCH,
		TYPEDEF,
		UNION,
		UNSIGNED,
		VOID,
		VOLATILE,
		WHILE
	};
	
	char keywords[32][50] = 
	{
		"auto",
		"break",
		"case",
		"char",
		"const",
		"continue",
		"default",
		"do",
		"double",
		"else",
		"enum",
		"extern",
		"float",
		"for",
		"goto",
		"if",
		"int",
		"long",
		"register",
		"return",
		"short",
		"signed",
		"sizeof",
		"static",
		"struct",
		"switch",
		"typedef",
		"union",
		"unsigned",
		"void",
		"volatile",
		"while"
	};
	
	for(int i=0; i<32; i++)
	{
		if(is_same(word, keywords[i]))
		{
			return keyword_tokens[i];
		}
	}
	
	return ID;
}
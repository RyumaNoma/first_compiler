#include "word.h"

const char token_names[][50] = 
{
	"error",
	"white space",
	"identifier",
	"number",
	"semi colon",
	"equal",
	"equal equal",
	"bigger",
	"bigger equal",
	"smaller",
	"smaller equal",
	"left parenthsis",
	"right parenthsis",
	"plus",
	"minus",
	"asterisk",
	"slash",
	"comment start",
	"comment end",
	"percent",
	"single quotation",
	"double quotation"
};

// key: target character
// char_group: group of character

// return integer
// return >= 0 : char_group includes key
// return == -1: char_group does not include key
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

// fp: file stream
// first_char: target word's first character

// return TOKEN (define at word.h)
// ID: the word is identifier
TOKEN get_token(FILE* fp, char* first_char)
{
	char c;
	char last_char;
		
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
	else if(char_pos(c, Alphabet) >= 0)
	{
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
		*first_char = c;
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
		goto id;
	}
	else if(char_pos(c, Alphabet) >= 0)
	{
		goto id;
	}
	else
	{
		*first_char = c;
		return ID;
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
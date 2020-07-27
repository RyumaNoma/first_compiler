#include <stdio.h>
#include "word.h"

int main(int args_num, char** args)
{
	
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
		"percent",
		"single quotation",
		"double quotation",
		"comment start",
		"comment end",
		
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

	FILE* fp;
	fp = fopen(args[1], "r");
	
	if(fp == NULL)
	{
		printf("error : %s does not exist.\n", args[1]);
		return 0;
	}
	
	TOKEN tokens[128];
	for(int i=0; i<128; i++) tokens[i] = ERROR;
	int idx = 0;
	TOKEN state;
	
	int count = 0;
	
	char first_char = SOF;
	do
	{
		state = get_token(fp, &first_char);
		tokens[idx++] = state;
		count++;
	}
	while(count <= 128);
	
	
	for(int i = 0; i < 128; i++)
	{		
		printf("%s\n", token_names[tokens[i]]);
	}
	printf("%s\n", token_names[tokens[12]]);
	
	fclose(fp);
	return 0;
}
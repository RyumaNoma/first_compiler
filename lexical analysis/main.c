#include <stdio.h>
#include "word.h"

int main(int args_num, char** args)
{
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
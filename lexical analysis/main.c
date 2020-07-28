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

	fclose(fp);
	
	// output to text file
	FILE* output_file_stream;
	if ((output_file_stream = fopen("lexical_analysis.txt", "w")) == NULL)
	{
		printf("error : can not open output_file_stream\n");
		return 0;
	}

	for(int i = 0; i < 128; i++)
	{
		fprintf(output_file_stream, "%s\n", token_names[tokens[i]]);
	}

	fclose(output_file_stream);

	return 0;
}
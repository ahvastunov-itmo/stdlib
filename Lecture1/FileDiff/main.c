#include <stdio.h>




int main(int argv, char** argc)
{
	if(argv < 3)
	{
		printf("Bad input format\n");
		printf("Use: FileDiff.exe first_file_path second_file_path");
		return 1;
	}
	
	char* firstFilePath = argc[1];
	char* secondFilePath = argc[2];
	
	FILE* firstStream = fopen(firstFilePath, "r");
	if(firstStream == NULL)
	{
		printf("Can not open file %s", firstFilePath);
		return 1;
	}
	
	FILE* secondStream = fopen(secondFilePath, "r");
	if(secondStream == NULL)
	{
		printf("Can not open file %s", secondFilePath);
		fclose(firstStream);
		return 1;
	}

	int symbolNumber = 1 ;
	
	int	firstFileSymbol = fgetc(firstStream);	
	int	secondFileSymbol = fgetc(secondStream);	
	
	while(firstFileSymbol != EOF && secondFileSymbol != EOF && firstFileSymbol == secondFileSymbol)
	{
		symbolNumber++;
		firstFileSymbol = fgetc(firstStream);	
		secondFileSymbol = fgetc(secondStream);	
	}
	
	fclose(firstStream);
	fclose(secondStream);
	
	if(firstFileSymbol == EOF && secondFileSymbol == EOF)
		printf("Two file are equal");
	else
		printf("Number of first different symbol is: %d", symbolNumber);
	
	return 0;
}

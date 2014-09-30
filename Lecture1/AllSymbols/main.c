#include <stdio.h>


int main (int argv, char** argc)
{
	if(argv < 2)
	{
		printf("Please, specify input file");
		return 1;
	}
	
	char* path = argc[1];
	FILE* stream = fopen(path, "r");
	if(stream == NULL)
	{
		printf("Can not open file %s", path);
		return 1;
	}
	
	fseek(stream, 0, SEEK_END);
	int symbolCount = ftell(stream);
	
	fclose(stream);
	
	printf("File contains %d symbols", symbolCount);
	
	return 0;
}
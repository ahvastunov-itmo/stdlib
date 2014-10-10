#include <stdio.h>


int saveName(const char * filePath, const char* name)
{
	FILE* stream = fopen(filePath, "w");
	if(stream == NULL)
	{
		printf("Can not open or create file %s for writing", filePath);
		return 1;
	}
	fprintf(stream, "My name is %s", name);
	
	fclose(stream);
	
	return 0;
}

int readName(const char * filePath, char* name)
{
	FILE* stream = fopen(filePath, "r");
	if(stream == NULL)
	{
		printf("Can not open file %s", filePath);
		return 1;
	}
	fseek(stream, 0, SEEK_END);
  	int fileSize = 	ftell(stream);
	
	if(fileSize < 11)
	{
		printf("Bad file %s format", filePath);
		fclose(stream);
		return 1;
		
	}
	
	fseek(stream, 11, SEEK_SET);
	fgets(name, fileSize - 10, stream);
	
	fclose(stream);
	
	return 0;
}



int main(int argc, char** argv)
{
	const char* path = "temp.dat";
	char name[40];
	
	printf("Enter your name:");
	gets(name);
	
	if(saveName(path, name) != 0)
		return 1;
	
	char readedName[40];
	
	if(readName(path, readedName) != 0)
		return 1;
	
	remove(path);
	
	printf("Name: %s", readedName);
	
	return 0;
}

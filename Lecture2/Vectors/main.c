#include <stdio.h>
#include <math.h>
#include "vec.h"



struct SVector vectors[10];

int parseVector(FILE* stream, int index)
{
	float x, y, z;
	
	if(fscanf(stream, "(%f,%f,%f)\n", &x, &y, &z) != 3)
	{	
		printf("Bad file format at line: %d", index + 1);
		return 1;
	}
	
	vectors[index] = MakeVector(x,y,z);
	
	return 0;
}


int parseFile(const char * path)
{
	FILE* stream = fopen(path, "r");
	
	if(stream == NULL)
	{
		printf("Can not open file %s\n", path);
		return 1;
	}
	
	for(int i = 0; i < 10; ++i)
	{
		if(parseVector(stream, i) != 0)
		{
			fclose(stream);
			return 1;
		}
	}
	
	fclose(stream);
	
	return 0;
}

struct SVector GetSumVector()
{
	struct SVector vectorSum = MakeVector(0,0,0);
	
	for(int i = 0; i < 10; ++i)
		vectorSum = VectorAddition(vectorSum, vectors[i]);
	
	return vectorSum;
}

void FirstTask(struct SVector rVector)
{
	float length = LengthOfVector(rVector);
	printf("Length of sum vector is: %f\n", length);
}

void SecondTask(struct SVector rVector)
{
	float scalarMult = rVector.y;
	double angle = acos(scalarMult/(LengthOfVector(rVector)));
	
	printf("Angle between vector and Y axis is %f\n", angle*180/3.14);
}


void ThirdTask(struct SVector rVector)
{

}


int main (int argv, char** argc)
{
	
	if(argv < 2)
	{
		printf("Please, specify input file");
		printf("Usage, vectors.exe data_file");
		return 1;
	}
	
	const char* path = argc[1];
	parseFile(path);
	
	struct SVector resultVector = GetSumVector();
	
	FirstTask(resultVector);
	
	printf("--------------------------------------\n");
	
	SecondTask(resultVector);
	
	printf("--------------------------------------\n");
	
	ThirdTask(resultVector);
	
	return 0;
}
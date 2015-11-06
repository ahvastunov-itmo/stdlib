// Vector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>


struct  SVector
{	
	int x;
	int y;
	int z;
};

double VectorLength(const SVector v)
{	
	return sqrt(pow(v.x, 2.0) + pow(v.y, 2.0) + pow(v.z, 2.0));
}


SVector MakeVector(int x, int y, int z){
	SVector result;
	result.x = x;
	result.y = y;
	result.z = z;

	return result;
}

SVector AdditionalVectors(const SVector v1, const SVector v2)
{
	return MakeVector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

double Angle(const SVector v1, const SVector v2)
{
	double l1 = VectorLength(v1);
	double l2 = VectorLength(v2);

	double scalMult = v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;

	if (l1 == 0 || l2 == 0)
		return NAN;

	return acos(scalMult / (l1*l2));
}

SVector ReadVector(FILE * stream){
	int x, y, z;

	if (fscanf(stream, "(%d,%d,%d)", &x, &y, &z) > 0){
		return MakeVector(x, y, z);
	}

	return MakeVector(NAN, NAN, NAN);
}

SVector FirstTask(const SVector v[10])
{
	printf("First task\n");

	SVector result = v[0];

	for (int i = 0; i < 10; ++i){
		result = AdditionalVectors(result, v[i]);
	}

	printf("Length %d", VectorLength(result));

	printf("-------------------------");

	return result;
}

void SecondTask(const SVector v)
{
	printf("Second Task\n");

	double angle = Angle(v, MakeVector(0, 1, 0));

	printf("Angle between result and Y is: %f", 180 * angle / M_PI);

	printf("-------------------------");
}

void ThirdTask(const SVector res, const char* path)
{
	FILE* stream = fopen(path, "r");
	if (stream == NULL){
		printf("Can't open file %s", path);
		return;
	}

	int x, y, z;
	SVector second = ReadVector(stream);
	fclose(stream);

	double angle = Angle(second, res);

	printf("Angle %f", angle);
}


int _tmain(int argc, _TCHAR* argv[])
{
	SVector vectors[10];

	if (argc < 3){
		printf("No input files!");
		return 1;
	}

	FILE *stream = fopen(argv[1], "r");
	if (stream == NULL){
		printf("Can't open file %s", argv[1]);
		return 1;
	}

	for (int i = 0; i < 10; ++i){
		vectors[i] = ReadVector(stream);
	}

	fclose(stream);
	
	SVector res = FirstTask(vectors);
	SecondTask(res);
	ThirdTask(res, argv[2]);

	return 0;
}


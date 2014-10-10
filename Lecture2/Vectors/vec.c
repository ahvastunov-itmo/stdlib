#include <math.h>
#include "vec.h"

float LengthOfVector(struct SVector v)
{
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

struct SVector MakeVector(float x, float y, float z)
{
	struct SVector vec;
	vec.x = x;
	vec.y = y;
	vec.z = z;
	
	return vec;
}

struct SVector VectorAddition (struct SVector first, struct SVector second)
{
	struct SVector result;
	
	result.x = first.x + second.x;
	result.y = first.y + second.y;
	result.z = first.z + second.z;
	
	return result;
}


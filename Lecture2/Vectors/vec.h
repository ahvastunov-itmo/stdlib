
struct SVector 
{
	float x;
	float y; 
	float z;
};


float LengthOfVector(struct SVector v);

struct SVector MakeVector(float x, float y, float z);

struct SVector VectorAddition (struct SVector first, struct SVector second);
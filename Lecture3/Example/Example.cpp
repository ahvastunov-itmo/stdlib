// Example.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>

struct SDate{
	int day;
	int month;
	int year;
};


int dateComparer(const void * first, const void * second){
	const SDate * firstData = (const SDate *)first;
	const SDate * secondData = (const SDate *)second;

	if (firstData->year != secondData->year)
		return firstData->year - secondData->year;

	if (firstData->month != secondData->month)
		return firstData->month - secondData->month;

	if (firstData->day != secondData->day)
		return firstData->day - secondData->day;
}


int _tmain(int argc, _TCHAR* argv[])
{
	SDate dates[20];

	if (argc < 2){
		printf("No file path to open");
		return 1;
	}
	FILE* fileStream = fopen(argv[1], "r");

	if (fileStream == NULL){
		printf("Cannot open file %s", argv[1]);
		return 1;
	}

	char buff[200];
	char * endPtr;
	for (int i = 0; i < 20; ++i){
		fgets(buff, 200, fileStream);
		dates[i].day = strtol(buff, &endPtr, 10);
		dates[i].month = strtol(endPtr+1, &endPtr, 10);
		dates[i].year = strtol(endPtr+1, &endPtr, 10);
	}

	fclose(fileStream);

	qsort(dates, 20, sizeof(SDate), dateComparer);

	for (int i = 0; i < 20; ++i){
		printf("%02d.%02d.%d\n", dates[i].day, dates[i].month, dates[i].year);
	}

	return 0;
}


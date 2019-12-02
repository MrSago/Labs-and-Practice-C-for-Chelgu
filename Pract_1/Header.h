#ifndef HEADER_H
#define HEADER_H

#include "stdio.h"
#include "stdlib.h"
#include "locale.h"
#include "time.h"

#define RANDOM rand()%201 - 100

typedef struct __array {
	int *arr;
	size_t size;
}Array;

Array RandomArray(void);
void PrintArray(Array __mass);
void SortArray(Array __mass);
void FreeArray(Array __mass);

#endif
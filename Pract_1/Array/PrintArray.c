#include "../Header.h"


void PrintArray(Array __mass)
{
	for (size_t i = 0; i < __mass.size; ++i)
	{
		printf("%d ", __mass.arr[i]);
	}
	printf("\n");
}
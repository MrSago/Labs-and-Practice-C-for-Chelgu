#include "../Header.h"

void FreeArray(Array __mass)
{
	free(__mass.arr);
}
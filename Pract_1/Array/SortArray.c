#include "../Header.h"


void SortArray(Array __mass)
{
	for (size_t i = 0; i < __mass.size - 1; ++i)
	{
		for (size_t j = 0; j < __mass.size - i - 1; ++j)
		{
			if (__mass.arr[j] > __mass.arr[j + 1])
			{
				int tmp = __mass.arr[j];
				__mass.arr[j] = __mass.arr[j + 1];
				__mass.arr[j + 1] = tmp;
			}
		}
	}
}
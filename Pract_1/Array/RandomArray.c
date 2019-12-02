#include "../Header.h"


Array RandomArray(void)
{
	Array __new;

	scanf_s("%llu", &__new.size);
	__new.arr = (int*)malloc(__new.size * sizeof(int));
	if (__new.arr == NULL) exit(EXIT_FAILURE);

	for (size_t i = 0; i < __new.size; ++i)
	{
		__new.arr[i] = RANDOM;
	}

	return __new;
}
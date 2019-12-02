#include "../Header.h"


/*PrintNumber version 1.1*/
void PrintNumber(char *number, size_t size)
{
	--size;
	while (size != 0)
	{
		--size;
		printf("%c", number[size]);
	}
}
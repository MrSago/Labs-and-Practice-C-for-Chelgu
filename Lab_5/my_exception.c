#include "./main.h"
#pragma warning(disable:6031)

int my_exception(int code)
{
	printf("Program call exception with code: %d\n", code);
	printf("Press any key to continue...");
	_getch();
	return (code);
}

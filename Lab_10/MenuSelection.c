#include "Header.h"


int MenuSelection(void)
{
	errno_t err;
	int select;


	err = scanf_s("%d", &select);

	if (err == 0)
	{
		select = -1;
	}

	for (char tmp = 0; tmp != 10; /*empty*/)
	{
		scanf_s("%c", &tmp, 1);
	}


	return select;
}
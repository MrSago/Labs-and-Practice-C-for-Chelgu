#include "Header.h"


errno_t FileCheck(FILE **file, const char filename[], const char mode[])
{
	errno_t err;

	err = fopen_s(file, filename, mode);

	if (err != 0 || *file == NULL)
	{
		return EFOPEN;
	}
	else
	{
		return SUCCESS;
	}
}
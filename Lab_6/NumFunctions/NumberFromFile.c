#include "../Header.h"


char *NumberFromFile(char filename[], size_t *size)
{
	char *number;
	FILE *file;
	char tmp;
	size_t size_tmp;
	errno_t err;


	err = FileCheck(&file, filename, "r");
	if (err == EFOPEN)
	{
		number = NULL;
		*size = 0;

		return number;
	}

	while (!feof(file))
	{
		fscanf_s(file, "%c", &tmp, 1);
		++*size;
	}
	rewind(file);

	number = (char*)malloc(*size * sizeof(char));
	if (number == NULL)
	{
		exit(EXIT_FAILURE);
	}

	size_tmp = *size;
	number[*size - 1] = 0;

	for (char tmp; size_tmp - 1 > 0; --size_tmp)
	{
		fscanf_s(file, "%c", &tmp, 1);
		number[size_tmp - 2] = tmp;
	}

	fclose(file);


	return number;
}
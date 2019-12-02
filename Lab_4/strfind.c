#include "main.h"

size_t strfind(char* str, char* find)
{
	size_t count = 0;
	size_t tmp_count;
	size_t str_size = 0;
	size_t find_size = 0;
	size_t i, j;


	for (i = 0; find[i] != 0; ++i)
	{
		++find_size;
	}

	for (i = 0; str[i] != 0; ++i)
	{
		++str_size;
	}

	for (i = 0; i < str_size; ++i)
	{
		tmp_count = 0;

		for (j = 0; j < find_size; ++j)
		{
			if (find[j] == str[i + j])
			{
				++tmp_count;
			}
			else
			{
				break;
			}
		}

		if (tmp_count == find_size)
		{
			++count;
		}
	}

	return (count);
}

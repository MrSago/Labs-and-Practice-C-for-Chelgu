#include "Header.h"
#include <string.h>

int my_pow (int a, const unsigned n); //a^n

int ScanINT(void)
{
	int res = 0;
	char *str = ScanString();
	size_t str_len = strlen(str);
	int sign = 0;

	if (str[0] == '-') sign = -1;

	for (size_t i = 0 - sign; i < str_len; ++i)
	{
		if (str[i] < '0' || str[i] > '9')
			return 0;
	}

	if (str_len + sign > 10)
	{
		if (sign == -1) return INT_MIN;
		else return INT_MAX;
	}

	for (size_t i = str_len; i > 0 - sign; --i)
	{
		size_t index = i - 1;
		if (str[str_len - index - 1 - sign] < '0' || str[str_len - index - 1 - sign] > '9')
			return 0;

		int power = my_pow(10, (unsigned)(index + sign));

		if ((str[str_len - index - 1 - sign] - '0') <= INT_MAX / power)
		{
			if (res <= INT_MAX - (str[str_len - index - 1 - sign] - '0') * power)
				res += (str[str_len - index - 1 - sign] - '0') * power;
			else
			{
				if (sign == -1) return INT_MIN;
				else return INT_MAX;
			}
		}
		else
		{
			if (sign == -1) return INT_MIN;
			else return INT_MAX;
		}
	}

	if (sign == -1) res *= (-1);

	return res;
}
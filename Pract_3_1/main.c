#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#include "windows.h"

#define STRINGS_COUNT   50
#define MAX_STRING_SIZE 3


void GenerateRandomString(char *str, unsigned int max_size)
{
	unsigned int size = 2 + rand() % (max_size - 2);

	str[0] = 'A' + (rand() % ('Z' - 'A' + 1));
	for (unsigned int i = 1; i < size; ++i)
	{
		str[i] = 'a' + (rand() % ('z' - 'a' + 1));
	}
	str[size] = 0;
}


void GenerateRandomStrings(char strings[][MAX_STRING_SIZE])
{
	unsigned int size = (unsigned)rand() % (STRINGS_COUNT - 2);

	for (unsigned int i = 0; i < size; ++i)
	{
		GenerateRandomString(strings[i], MAX_STRING_SIZE);
	}
	strings[size + 1][0] = 0;
}

void PrintStrings(char strings[][MAX_STRING_SIZE])
{
	for (unsigned int i = 0; strings[i + 1][0] != 0; ++i)
	{
		printf("%s\n", strings[i]);
	}
}


void SortStrings(char strings[][MAX_STRING_SIZE])
{
	for (unsigned int i = 0; strings[i + 1][0] != 0; ++i)
	{
		for (unsigned int j = 0; strings[j + 1][0] != 0; ++j)
		{
			if (strcmp((char*)strings[j], (char*)strings[j + 1]) > 0)
			{
				strcpy_s(strings[STRINGS_COUNT - 1], MAX_STRING_SIZE, strings[j]);
				strcpy_s(strings[j], sizeof(strings[j]), strings[j + 1]);
				strcpy_s(strings[j + 1], MAX_STRING_SIZE, strings[STRINGS_COUNT - 1]);
			}
		}
	}
}


int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));
	HANDLE hCons = GetStdHandle(STD_OUTPUT_HANDLE);
	char strings[STRINGS_COUNT][MAX_STRING_SIZE];

	GenerateRandomStrings(strings);
	SetConsoleTextAttribute(hCons, (WORD)((0 << 4) | 2));
	printf("Source strings:\n");
	PrintStrings(strings);
	printf("\n\n");

	SortStrings(strings);
	SetConsoleTextAttribute(hCons, (WORD)((0 << 4) | 1));
	printf("Sort strings:\n");
	PrintStrings(strings);

	return 0;
}
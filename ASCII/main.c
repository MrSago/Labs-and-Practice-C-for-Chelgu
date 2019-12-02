#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <conio.h>
#pragma warning(disable:6031)

int main(int argc, char** argv, char** envp)
{
	const char* FNAME = { "ASCII.txt" };
	FILE* file;
	int i;


	printf("Full ASCII table:\n");
	
	if (fopen_s(&file, FNAME, "w") == 0 && file != (FILE*)NULL)
	{
		fprintf_s(file, "Full ASCII table:\n");

		for (i = CHAR_MIN; i <= CHAR_MAX; ++i)
		{
			printf("Symbol with num:	%d = '%c'\n", i, (char)i);
			fprintf_s(file, "Symbol with num:	%d = '%c'\n", i, (char)i);
		}

		printf("Result has written to file: ASCII.txt\n");
		fclose(file);
	}
	else
	{
		for (i = CHAR_MIN; i <= CHAR_MAX; ++i)
		{
			printf("Symbol with num : %d = '%c'\n", i, (char)i);
		}

		printf("Can't write result in file!\n");
	}

	_getch();
	return (0);
}

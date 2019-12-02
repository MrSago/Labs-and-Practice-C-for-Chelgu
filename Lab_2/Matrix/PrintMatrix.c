#include "./../main.h"

void PrintMatrix(Matrix matrix)
{
	size_t i, j;
	

	for (i = 0; i < matrix->strings; ++i)
	{
		printf("|");
		for (j = 0; j < matrix->columns; ++j)
		{
			printf("%3d ", matrix->buf[i][j]);
		}
		printf("|\n");
	}

	return;
}

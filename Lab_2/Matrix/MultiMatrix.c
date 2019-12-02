#include "./../main.h"
#pragma warning(disable:6385)
#pragma warning(disable:6386)

retcode_t MultiMatrix(Matrix* ptrRes, Matrix first, Matrix second)
{
	Matrix mul;
	size_t i, j, k;
	int tmp;
	*ptrRes = (Matrix)NULL;


	printf("Check matrix size: %c(%llu x %llu) and %c%c(%llu x %llu):",
		FILENAME_A[0], first->strings, first->columns, -38, FILENAME_B[0], second->strings, second->columns);

	if (first->columns != second->strings)
	{
		printf(" incorrect size!\n");
		return (EINCORMATR);
	}
	else
	{
		printf(" OK!\n");
	}

	mul = (Matrix)malloc(sizeof(struct __matrix));
	if (mul == (Matrix)NULL)
	{
		printf("Error allocate memory!\n");
		return (EMALLOC);
	}

	mul->strings = first->strings;
	mul->columns = second->columns;

	mul->buf = (int**)malloc(mul->strings * sizeof(int*));
	if (mul->buf == (int**)NULL)
	{
		printf("Error allocate memory!\n");
		free(mul);
		return (EMALLOC);
	}

	for (i = 0; i < mul->strings; ++i)
	{
		mul->buf[i] = (int*)malloc(mul->columns * sizeof(int));
		if (mul->buf[i] == (int*)NULL)
		{
			printf("Error allocate memory!\n");
			for (k = 0; k < i; ++k)
			{
				free(mul->buf[k]);
			}
			free(mul->buf);
			free(mul);
			return (EMALLOC);
		}
	}

	printf("Matrix C(%llu x %llu) = %c * %c%c\n",
		first->strings, second->columns, FILENAME_A[0], -38, FILENAME_B[0]);

	for (i = 0; i < mul->strings; ++i)
	{
		printf("|");
		for (j = 0; j < mul->columns; ++j)
		{
			tmp = 0;
			for (k = 0; k < mul->strings; ++k)
			{
				tmp += first->buf[i][k] * second->buf[k][j];
			}
			mul->buf[i][j] = tmp;
			printf("%3d ", tmp);
		}
		printf("|\n");
	}

	*ptrRes = mul;
	return (SUCCESS);
}

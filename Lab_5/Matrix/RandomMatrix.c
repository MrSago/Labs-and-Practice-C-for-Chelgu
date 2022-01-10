#include "./../main.h"

#define RANDOM ((rand() % 19) - 9)
#define RANGE "[-9, 9]"

retcode_t RandomMatrix(Matrix* ptrMatrix)
{
	Matrix matrix;
	errno_t err;
	size_t i, j, k;
	*ptrMatrix = (Matrix)NULL;
	srand((unsigned)time(NULL));


	matrix = (Matrix)malloc(sizeof(struct __matrix));
	if (matrix == (Matrix)NULL)
	{
		return (EMALLOC);
	}

	while (1)
	{
		printf("������� ����������� ���������� �������: ");
		if ((err = scanf_s("%llu", &matrix->strings)) != 0 && matrix->strings > 0)
		{
			for (char tmp = 0;
				(err = scanf_s("%c", &tmp, 1)) == EOF || tmp != '\n';
				/*empty*/);
			break;
		}
		else
		{
			for (char tmp = 0;
				tmp != '\n';
				scanf_s("%c", &tmp, 1));
			printf("������������ ������ �������!\n\n");
			continue;
		}
	}

	matrix->columns = matrix->strings;

	printf("�������� �������� %s\n������� R(%llu x %llu):\n",
		RANGE, matrix->strings, matrix->columns);

	matrix->buf = (int**)malloc(matrix->strings * sizeof(int*));
	if (matrix->buf == (int**)NULL)
	{
		free(matrix);
		return (EMALLOC);
	}

	for (i = 0; i < matrix->strings; ++i)
	{
		printf("|");
		matrix->buf[i] = (int*)malloc(matrix->columns * sizeof(int));
		if (matrix->buf[i] == (int*)NULL)
		{
			for (k = 0; k < i; ++k)
			{
				free(matrix->buf[k]);
			}
			free(matrix->buf);
			free(matrix);
			return (EMALLOC);
		}
		for (j = 0; j < matrix->columns; ++j)
		{
			matrix->buf[i][j] = RANDOM;
			printf("%3d ", matrix->buf[i][j]);
		}
		printf("|\n");
	}

	*ptrMatrix = matrix;
	return (SUCCESS);
}
#include "./../main.h"
#pragma warning(disable:6385)
#pragma warning(disable:6386)

retcode_t CheckMatrix(FILE* file, size_t* ptrStr, size_t* ptrCol);
retcode_t MatrixSize(FILE* file, size_t* ptrStr, size_t* ptrCol);

retcode_t GetMatrixFromFile(Matrix* ptrMatrix, const char* filename)
{
	retcode_t code;
	Matrix matrix;
	size_t str, col;
	FILE* file;
	size_t i, j, k;
	*ptrMatrix = (Matrix)NULL;


	if (fopen_s(&file, filename, "r") != 0 || file == (FILE*)NULL)
	{
		printf("Error open file to read: %s\n", filename);
		return (EFOPEN);
	}
	else
	{
		printf("Success file open: %s!\n", filename);
	}

	printf("Check matrix...");
	code = CheckMatrix(file, &str, &col);
	if (code != SUCCESS)
	{
		printf("\nIncorrect matrix!\n");
		fclose(file);
		return (code);
	}
	else
	{
		printf(" OK!\n");
	}

	matrix = (Matrix)malloc(sizeof(struct __matrix));
	if (matrix == (Matrix)NULL)
	{
		printf("Error allocate memory!\n");
		fclose(file);
		return (EMALLOC);
	}

	matrix->strings = str;
	matrix->columns = col;

	matrix->buf = (int**)malloc(matrix->strings * sizeof(int*));
	if (matrix->buf == (int**)NULL)
	{
		printf("Error allocate memory!\n");
		free(matrix);
		fclose(file);
		return (EMALLOC);
	}
	else
	{
		printf("Matrix %c(%llu x %llu):\n", filename[0], matrix->strings, matrix->columns);
	}

	for (i = 0; i < matrix->strings; ++i)
	{
		printf("|");
		matrix->buf[i] = (int*)malloc(matrix->columns * sizeof(int));
		if (matrix->buf[i] == (int*)NULL)
		{
			printf("Error allocate memory!\n");
			for (k = 0; k < i; ++k)
			{
				free(matrix->buf[k]);
			}
			free(matrix->buf);
			free(matrix);
			fclose(file);
			return (EMALLOC);
		}
		else
		{
			for (j = 0; j < matrix->columns; ++j)
			{
				fscanf_s(file, "%d", &matrix->buf[i][j]);
				printf("%3d ", matrix->buf[i][j]);
			}
			printf("|\n");
		}
	}

	fclose(file);
	*ptrMatrix = matrix;
	return (SUCCESS);
}

retcode_t CheckMatrix(FILE* file, size_t* ptrStr, size_t* ptrCol)
{
	retcode_t code;
	char tmp;
	size_t tStr = 0, tCol = 0;
	(*ptrStr) = 0;
	(*ptrCol) = 0;


	code = MatrixSize(file, ptrStr, ptrCol);
	if (code != SUCCESS)
	{
		return (code);
	}

	while ((tmp = fgetc(file)) != EOF)
	{
		tCol = 0;

		do
		{
			if ((tmp < '0' || tmp > '9') && tmp != '-')
			{
				if (tmp == ' ')
				{
					++tCol;
				}
				else
				{
					return (EINCORMATR);
				}
			}

		} while ((tmp = fgetc(file)) != '\n');

		if ((tCol + 1) != (*ptrCol))
		{
			return (EINCORMATR);
		}

		++tStr;
	}

	if (tStr != (*ptrStr))
	{
		return (EINCORMATR);
	}

	rewind(file);
	return (SUCCESS);
}

retcode_t MatrixSize(FILE* file, size_t* ptrStr, size_t* ptrCol)
{
	char tmp;


	while ((tmp = fgetc(file)) != '\n')
	{
		if ((tmp < '0' || tmp > '9') && tmp != '-')
		{
			if (tmp == ' ')
			{
				++(*ptrCol);
			}
			else
			{
				return (EINCORMATR);
			}
		}
	}

	++(*ptrStr);
	++(*ptrCol);

	while ((tmp = fgetc(file)) != EOF)
	{
		if (tmp == '\n')
		{
			++(*ptrStr);
		}
	}

	rewind(file);
	return (SUCCESS);
}

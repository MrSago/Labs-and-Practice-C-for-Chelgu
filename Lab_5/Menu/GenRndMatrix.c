#include "./../main.h"

retcode_t GenRndMatrix()
{
	retcode_t code;
	Matrix matrix;
	long long det;
	clock_t start, stop;


	code = RandomMatrix(&matrix);
	if (code != SUCCESS)
	{
		return (code);
	}

	printf("��������� ������������...");

	start = clock();
	det = DetMatrix(matrix->buf, matrix->strings);
	stop = clock();

	printf("\ndet[R] = %lli\n����� ����������: %.3f ���.\n",
		det, (stop - start) / (float)CLOCKS_PER_SEC);

	FreeMatrix(&matrix);
	return (SUCCESS);
}
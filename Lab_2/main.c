#include "./main.h"
#pragma warning(disable:6031)

int main(int argc, char** argv, char** envp)
{
	retcode_t code;
	Matrix A, B, TB, A_TB;


	code = GetMatrixFromFile(&A, FILENAME_A);
	if (code != SUCCESS)
	{
		return (my_exception(code));
	}

	code = GetMatrixFromFile(&B, FILENAME_B);
	if (code != SUCCESS)
	{
		return (my_exception(code));
	}

	code = TransMatrix(&TB, B);
	if (code != SUCCESS)
	{
		return (my_exception(code));
	}

	FreeMatrix(&B);

	code = MultiMatrix(&A_TB, A, TB);
	if (code != SUCCESS)
	{
		return (my_exception(code));
	}

	FreeMatrix(&A);
	FreeMatrix(&TB);
	FreeMatrix(&A_TB);

	printf("\nPress any key to continue...");
	_getch();
	return (SUCCESS);
}

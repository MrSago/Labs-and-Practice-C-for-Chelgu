#include "main.h"

int main(int argc, char** argv, char** envp)
{
	retcode_t code = SUCCESS;
	setlocale(LC_ALL, "Rus");


	while (1)
	{
		printf("Программа для вычисления определителя матрицы\n\nВыбери опцию:\n1.Ввести матрицу вручную\n2.Ввести из файла\n3.Сгенерировать матрицу\n0.Выйти из программы\n");

		switch (_getch())
		{
		case '1':
			system("cls");
			code = ManuallyMatrix();
			break;

		case '2':
			system("cls");
			code = FileMatrix();
			break;

		case '3':
			system("cls");
			code = GenRndMatrix();
			break;

		case '0':
			system("cls");
			return (SUCCESS);

		default:
			printf("\nОшибка! Такой опции не существует!\n");
			break;
		}

		if (code != SUCCESS && code != EFOPEN && code != EINCORMATR)
		{
			return (my_exception(code));
		}
		else
		{
			system("pause");
			system("cls");
		}
	}

	return (code);
}

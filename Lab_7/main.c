#include "Header.h"


int main()
{
	setlocale(LC_ALL, "Rus");


	printf(WELCOME);

	while (1)
	{
		switch (MenuSelection())
		{
		case 1:
			system("cls");
			StringBruteForce();
			system("pause");
			system("cls");
			break;

		case 2:
			system("cls");
			FullBruteForce(FILENAME_REPORT);
			system("pause");
			system("cls");
			break;

		case 0:
			return 0;

		default:
			printf("Ошибка! Такой опции не существует!\n\n");
			break;
		}
	}
}
#include "Header.h"

extern void DelInfo(Students Group);

int main()
{
	srand((unsigned)time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Students MK101 = (Students)malloc(sizeof(Student));
	if (MK101 == NULL)
	{
		exit(EXIT_FAILURE);
	}
	else
	{
		MK101->info = NULL;
		MK101->count = 0;
	}


	printf(WELCOME);

	while (1)
	{
		printf(MENU);

		switch (MenuSelection())
		{
		case 1:
			system("cls");
			AddStudent(MK101);
			system("pause");
			system("cls");
			break;

		case 2:
			system("cls");
			RandomStudent(MK101);
			system("pause");
			system("cls");
			break;

		case 3:
			system("cls");
			DelStudent(MK101);
			system("pause");
			system("cls");
			break;

		case 4:
			system("cls");
			PrintStudents(MK101);
			system("pause");
			system("cls");
			break;

		case 5:
			system("cls");
			ReadFromFileStudents(MK101);
			system("pause");
			system("cls");
			break;

		case 6:
			system("cls");
			ReadFromBinFileStudents(MK101);
			system("pause");
			system("cls");
			break;

		case 7:
			system("cls");
			WriteInFileStudents(MK101);
			system("pause");
			system("cls");
			break;

		case 8:
			system("cls");
			WriteInBinFileStudents(MK101);
			system("pause");
			system("cls");
			break;

		case 9:
			system("cls");
			NiceStudents(MK101);
			system("pause");
			system("cls");
			break;

		case 10:
			system("cls");
			DelNotNiceStudents(MK101);
			system("pause");
			system("cls");
			break;

		case 0:
			DelInfo(MK101);
			free(MK101);
			return SUCCESS;

		default:
			printf("Ошибка! Такой опции не существует!\n\n");
			break;
		}
	}
}
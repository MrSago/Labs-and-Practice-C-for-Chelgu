#include "Header.h"
#include "stdint.h"

void FunctionsExample(void)
{
	int a;
	int p;
	char *num = NULL;

	//my_atoi
	printf("Пример функции my_atoi\n");

	printf("Введите число(char*): ");
	num = ScanString();

	printf("Введите систему счистления: ");
	p = ScanINT();

	printf("Пример использования функции my_atoi: (char*)%s -> (int)%d\n\n\n", num, my_atoi(num, p));
	if (num != NULL)
	{
		free(num);
		num = NULL;
	}



	//my_itoa
	printf("Пример функции my_itoa\n");

	printf("Введите число(int): ");
	a = ScanINT();

	printf("Введите систему счистления: ");
	p = ScanINT();

	printf("Пример использования функции my_itoa: ");
	my_itoa(&num, a, p);
	printf("\n");
	if (num != NULL)
	{
		free(num);
		num = NULL;
	}
}
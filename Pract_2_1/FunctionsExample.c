#include "Header.h"
#include "stdint.h"

void FunctionsExample(void)
{
	int a;
	int p;
	char *num = NULL;

	//my_atoi
	printf("������ ������� my_atoi\n");

	printf("������� �����(char*): ");
	num = ScanString();

	printf("������� ������� ����������: ");
	p = ScanINT();

	printf("������ ������������� ������� my_atoi: (char*)%s -> (int)%d\n\n\n", num, my_atoi(num, p));
	if (num != NULL)
	{
		free(num);
		num = NULL;
	}



	//my_itoa
	printf("������ ������� my_itoa\n");

	printf("������� �����(int): ");
	a = ScanINT();

	printf("������� ������� ����������: ");
	p = ScanINT();

	printf("������ ������������� ������� my_itoa: ");
	my_itoa(&num, a, p);
	printf("\n");
	if (num != NULL)
	{
		free(num);
		num = NULL;
	}
}
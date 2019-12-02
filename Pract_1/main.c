#include "Header.h"


int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "rus");

	Array mass;
	clock_t start, stop;

	printf("������� ���-�� ��������� �����: ");
	mass = RandomArray();

	printf("�������� ������ �����: ");
	PrintArray(mass);

	start = clock();
	SortArray(mass);
	stop = clock();

	printf("��������������� ������ �����: ");
	PrintArray(mass);

	printf("����� ����������: %.3f ���.\n", (stop - start) / (double)CLOCKS_PER_SEC);

	FreeArray(mass);
	system("pause");
	return 0;
}
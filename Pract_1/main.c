#include "Header.h"


int main()
{
	srand((unsigned)time(NULL));
	setlocale(LC_ALL, "rus");

	Array mass;
	clock_t start, stop;

	printf("Введите кол-во рандомных чисел: ");
	mass = RandomArray();

	printf("Исходный массив чисел: ");
	PrintArray(mass);

	start = clock();
	SortArray(mass);
	stop = clock();

	printf("Отсортированный массив чисел: ");
	PrintArray(mass);

	printf("Время сортировки: %.3f сек.\n", (stop - start) / (double)CLOCKS_PER_SEC);

	FreeArray(mass);
	system("pause");
	return 0;
}
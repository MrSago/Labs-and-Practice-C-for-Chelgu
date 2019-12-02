#include "Header.h"


void StringBruteForce(void)
{
	FILE *file;
	clock_t start, stop;
	char *string;
	unsigned int result;


	printf("������� ������: ");
	string = ScanString();
	result = HashRot13(string);

	printf("��������� ���������� �������: %d\n���� ����� ����� �������� � ����: Result.txt\n\n������ ��������:\n", result);

	start = clock();
	BruteForce(result, string, FILENAME_RESULT);
	stop = clock();

	free(string);

	printf("������� ��������!\n����� ����������: %.3f ���.\n", (stop - start) / (float)CLOCKS_PER_SEC);

	fopen_s(&file, "Result.txt", "a");
	fprintf_s(file, "����� ����������: %.3f ���.\n", (stop - start) / (float)CLOCKS_PER_SEC);
	fclose(file);
}
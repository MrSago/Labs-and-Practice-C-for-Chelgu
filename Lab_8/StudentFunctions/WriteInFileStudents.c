#include "../Header.h"


void WriteInFileStudents(Students Group)
{
	errno_t err;
	FILE *file;
	char *filename;


	if (Group->info == NULL || Group->count == 0)
	{
		printf("������ ����!\n");
		return;
	}

	printf("������� ��� ����� ��� ����������: ");
	filename = ScanString();

	err = FileCheck(&file, filename, "w");
	if (err == EFOPEN)
	{
		printf("�� ���� ������� ����: %s\n", filename);
		free(filename);
		return;
	}
	else
	{
		printf("���� %s ������� ������!\n", filename);
		free(filename);
	}

	fprintf_s(file, "���������� �������: %llu\n\n", Group->count);

	for (size_t i = 0; i < Group->count; ++i)
	{
		fprintf_s(file, LIST, i + 1, Group->info[i].LastName, Group->info[i].FirstName, Group->info[i].Age,
			Group->info[i].Object.Informatika, Group->info[i].Object.Algebra, Group->info[i].Object.Matanaliz, Group->info[i].Object.Fizika);
	}

	fclose(file);


	printf("������ ��������� ������� ��������!\n\n");
}
#include "../Header.h"


void AddStudent(Students Group)
{
	Info *NewStudent;
	size_t index;


	if (Group->info == NULL || Group->count == 0)
	{
		Group->count = 1;

		NewStudent = (Info*)malloc(sizeof(Info));
		if (NewStudent == NULL)
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		Group->count++;

		NewStudent = (Info*)realloc(Group->info, Group->count * sizeof(Info));
		if (NewStudent == NULL)
		{
			exit(EXIT_FAILURE);
		}
	}

	index = Group->count - 1;
	

	printf("������� ������� ��������: ");
	NewStudent[index].LastName = ScanString();

	printf("������� ��� ��������: ");
	NewStudent[index].FirstName = ScanString();

	printf("������� ������� ��������: ");
	scanf_s("%hhu", &NewStudent[index].Age);

	printf("������� ������ ��������\n�����������: ");
	scanf_s("%hhu", &NewStudent[index].Object.Informatika);

	printf("�������: ");
	scanf_s("%hhu", &NewStudent[index].Object.Algebra);

	printf("���.������: ");
	scanf_s("%hhu", &NewStudent[index].Object.Matanaliz);

	printf("������: ");
	scanf_s("%hhu", &NewStudent[index].Object.Fizika);

	
	Group->info = NewStudent;
	printf("������� ������� ��������!\n");
}
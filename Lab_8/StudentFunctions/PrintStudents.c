#include "../Header.h"


void PrintStudents(Students Group)
{
	if (Group->count == 0)
	{
		printf("Список пуст!\n");
		return;
	}

	printf("Список студентов:\n\n");

	for (size_t i = 0; i < Group->count; ++i)
	{
		printf(LIST, i + 1, Group->info[i].LastName, Group->info[i].FirstName, Group->info[i].Age,
			Group->info[i].Object.Informatika, Group->info[i].Object.Algebra, Group->info[i].Object.Matanaliz, Group->info[i].Object.Fizika);
	}
}
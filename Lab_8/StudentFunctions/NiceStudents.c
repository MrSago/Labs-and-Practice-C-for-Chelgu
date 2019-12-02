#include "../Header.h"


void NiceStudents(Students Group)
{
	if (Group->count == 0)
	{
		printf("—писок пуст!\n");
		return;
	}

	printf("—писок успевающих студентов (средн€€ оценка выше 3):\n\n");

	for (size_t i = 0; i < Group->count; ++i)
	{
		if ((double)NICE_MARKS < (double)4)
		{
			continue;
		}

		printf(LIST, i + 1, Group->info[i].LastName, Group->info[i].FirstName, Group->info[i].Age,
			Group->info[i].Object.Informatika, Group->info[i].Object.Algebra, Group->info[i].Object.Matanaliz, Group->info[i].Object.Fizika);
	}
}
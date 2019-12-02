#include "../Header.h"

extern void MemIndexInfoFree(Students Group, size_t del_index);

void DelNotNiceStudents(Students Group)
{
	Info *NewInfo;
	size_t nice_count = 0, del_count = 0;
	size_t *nice_index, *del_index, *tmp_index;


	if (Group->count == 0)
	{
		printf("Список пуст!\n");
		return;
	}


	nice_index = (size_t*)malloc(sizeof(size_t));
	if (nice_index == NULL)
	{
		exit(EXIT_FAILURE);
	}

	del_index = (size_t*)malloc(sizeof(size_t));
	if (del_index == NULL)
	{
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i < Group->count; ++i)
	{
		if ((double)NICE_MARKS > (double)3)
		{
			tmp_index = (size_t*)realloc(nice_index, (nice_count + 1) * sizeof(size_t));
			if (tmp_index == NULL)
			{
				exit(EXIT_FAILURE);
			}

			nice_index = tmp_index;
			nice_index[nice_count] = i;
			++nice_count;
		}
		else
		{
			tmp_index = (size_t*)realloc(del_index, (del_count + 1) * sizeof(size_t));
			if (tmp_index == NULL)
			{
				exit(EXIT_FAILURE);
			}

			del_index = tmp_index;
			del_index[del_count] = i;
			++del_count;
		}
	}

	NewInfo = (Info*)malloc(nice_count * sizeof(Info));
	if (NewInfo == NULL)
	{
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i < nice_count; ++i)
	{
		NewInfo[i].LastName = Group->info[nice_index[i]].LastName;
		NewInfo[i].FirstName = Group->info[nice_index[i]].FirstName;
		NewInfo[i].Age = Group->info[nice_index[i]].Age;
		NewInfo[i].Object.Informatika = Group->info[nice_index[i]].Object.Informatika;
		NewInfo[i].Object.Algebra = Group->info[nice_index[i]].Object.Algebra;
		NewInfo[i].Object.Matanaliz = Group->info[nice_index[i]].Object.Matanaliz;
		NewInfo[i].Object.Fizika = Group->info[nice_index[i]].Object.Fizika;
	}

	for (size_t i = 0; i < del_count; ++i)
	{
		MemIndexInfoFree(Group, del_index[i]);
	}

	free(Group->info);
	free(nice_index);
	free(del_index);

	Group->info = NewInfo;
	Group->count = nice_count;

	PrintStudents(Group);
	printf("Неуспевающие студенты удалены!\n\n");
}
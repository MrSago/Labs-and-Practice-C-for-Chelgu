#include "../Header.h"


void WriteInFileStudents(Students Group)
{
	errno_t err;
	FILE *file;
	char *filename;


	if (Group->info == NULL || Group->count == 0)
	{
		printf("Список пуст!\n");
		return;
	}

	printf("Введите имя файла для сохранения: ");
	filename = ScanString();

	err = FileCheck(&file, filename, "w");
	if (err == EFOPEN)
	{
		printf("Не могу открыть файл: %s\n", filename);
		free(filename);
		return;
	}
	else
	{
		printf("Файл %s успешно открыт!\n", filename);
		free(filename);
	}

	fprintf_s(file, "Количество записей: %llu\n\n", Group->count);

	for (size_t i = 0; i < Group->count; ++i)
	{
		fprintf_s(file, LIST, i + 1, Group->info[i].LastName, Group->info[i].FirstName, Group->info[i].Age,
			Group->info[i].Object.Informatika, Group->info[i].Object.Algebra, Group->info[i].Object.Matanaliz, Group->info[i].Object.Fizika);
	}

	fclose(file);


	printf("Список студентов успешно сохранен!\n\n");
}
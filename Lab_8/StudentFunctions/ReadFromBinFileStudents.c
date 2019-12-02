#include "../Header.h"

extern void DelInfo(Students Group);

void ReadFromBinFileStudents(Students Group)
{
	Info *NewInfo;
	errno_t err;
	FILE *file;
	size_t strsize;
	char *filename;


	printf("Введите имя бинарного файла для загрузки: ");
	filename = ScanString();

	err = FileCheck(&file, filename, "rb");
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

	if (Group->info != NULL && Group->count > 0)
	{
		DelInfo(Group);
	}

	fread_s(&Group->count, sizeof(size_t), sizeof(size_t), 1, file);

	NewInfo = (Info*)malloc(Group->count * sizeof(Info));
	if (NewInfo == NULL)
	{
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i < Group->count; ++i)
	{
		/*LastName*/
		fread_s(&strsize, sizeof(size_t), sizeof(size_t), 1, file);
		NewInfo[i].LastName = (char*)malloc((strsize + 1) * sizeof(char));
		if (NewInfo[i].LastName == NULL)
		{
			exit(EXIT_FAILURE);
		}
		fread_s(NewInfo[i].LastName, strsize * sizeof(char), sizeof(char), strsize, file);
		NewInfo[i].LastName[strsize] = 0;

		/*FirstName*/
		fread_s(&strsize, sizeof(size_t), sizeof(size_t), 1, file);
		NewInfo[i].FirstName = (char*)malloc((strsize + 1) * sizeof(char));
		if (NewInfo[i].FirstName == NULL)
		{
			exit(EXIT_FAILURE);
		}
		fread_s(NewInfo[i].FirstName, strsize * sizeof(char), sizeof(char), strsize, file);
		NewInfo[i].FirstName[strsize] = 0;

		/*Age*/
		fread_s(&NewInfo[i].Age, sizeof(uint8_t), sizeof(uint8_t), 1, file);

		/*Objects*/
		fread_s(&NewInfo[i].Object.Informatika, sizeof(uint8_t), sizeof(uint8_t), 1, file);
		fread_s(&NewInfo[i].Object.Algebra, sizeof(uint8_t), sizeof(uint8_t), 1, file);
		fread_s(&NewInfo[i].Object.Matanaliz, sizeof(uint8_t), sizeof(uint8_t), 1, file);
		fread_s(&NewInfo[i].Object.Fizika, sizeof(uint8_t), sizeof(uint8_t), 1, file);
	}

	fclose(file);


	Group->info = NewInfo;
	PrintStudents(Group);
}
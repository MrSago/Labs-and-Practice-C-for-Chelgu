#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

#pragma warning(disable:6031)

#define FNAME "book.txt"

int compare(const void* a, const void* b)
{
	return (*(int*)a - *(int*)b);
}

int main(int argc, char** argv, char** envp)
{
	FILE* file;
	size_t str_count = 0, current_count = 0;
	size_t* chars_count;
	size_t* chars_count_s;
	char** strings;
	char tmp;


	setlocale(LC_ALL, "Rus");

	if (fopen_s(&file, FNAME, "r") != 0 || file == (FILE*)NULL)
	{
		printf("Error open file to read: %s\n", FNAME);
		_getch();
		return (-1);
	}
	else
	{
		printf("Open file success: %s!\n", FNAME);
	}

	/*Считаем кол-во строк и кол-во символов в строке*/
	chars_count = (size_t*)malloc((str_count + 1) * sizeof(size_t));
	if (chars_count == (size_t*)NULL)
	{
		printf("Error allocate memory!\n");
		_getch();
		return (-1);
	}

	while (fscanf_s(file, "%c", &tmp, 1) != EOF)
	{
		++current_count;

		if (tmp == '\n' || feof(file))
		{
			++current_count;
			chars_count[str_count] = current_count;
			current_count = 0;
			++str_count;

			/*Увеличим массив с кол-вом символов с приходом новой строки*/
			size_t* pTmp = (size_t*)realloc(chars_count, (str_count + 1) * sizeof(size_t));
			if (pTmp == (size_t*)NULL)
			{
				printf("Error allocate memory!\n");
				_getch();
				return (-1);
			}
			else
			{
				chars_count = pTmp;
			}
		}
	}

	rewind(file); //Переход в начало файла

	/*Создаем массив и копируем в него текст из файла*/
	strings = (char**)malloc(str_count * sizeof(char*));
	if (strings == (char**)NULL)
	{
		printf("Error allocate memory!\n");
		_getch();
		return (-1);
	}

	for (size_t i = 0; i < str_count; ++i)
	{
		strings[i] = (char*)malloc(chars_count[i] * sizeof(char));
		if (strings[i] == (char*)NULL)
		{
			printf("Error allocate memory!\n");
			_getch();
			return (-1);
		}
		else
		{
			for (size_t j = 0; j < chars_count[i] - 1; ++j)
			{
				strings[i][j] = fgetc(file);
			}
			strings[i][chars_count[i] - 1] = 0;
		}
	}

	fclose(file); //Закрываем ненужный файл

	/*Сохраняем копию массива с кол-вом символов*/
	chars_count_s = (size_t*)malloc(str_count * sizeof(size_t));
	if (chars_count_s == (size_t*)NULL)
	{
		printf("Error allocate memory!\n");
		_getch();
		return (-1);
	}

	for (size_t i = 0; i < str_count; ++i)
	{
		chars_count_s[i] = chars_count[i];
	}

	qsort(chars_count, str_count, sizeof(size_t), compare); //Сортировка

	/*Сравниваем отсортированный массив со старым и выводим эту строчку*/
	for (size_t i = 0; i < str_count; ++i)
	{
		for (size_t j = 0; j < str_count; ++j)
		{
			if (chars_count[i] == chars_count_s[j])
			{
				printf("%s", strings[j]);
			}
		}
	}

	for (size_t i = 0; i < str_count; ++i)
	{
		free(strings[i]);
	}
	free(strings);
	free(chars_count);
	free(chars_count_s);

	printf("\nPress any key to continue...");
	_getch();
	return 0;
}

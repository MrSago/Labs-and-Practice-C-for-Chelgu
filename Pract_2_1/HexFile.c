#include "Header.h"


void HexFile()
{
	FILE *file;
	char *filename;

	printf("Введите имя файла: ");
	filename = ScanString();

	fopen_s(&file, filename, "rb");
	if (file == NULL)
	{
		exit(EXIT_FAILURE);
	}

	free(filename);

	printf("Содержимое файла в шестнадцатиричной виде:\n");
	for (unsigned char tmp[1]; !feof(file); /*empty*/)
	{
		fread_s(tmp, sizeof(unsigned char), sizeof(unsigned char), 1, file);
		printf("%02X ", tmp[0]);
	}
}
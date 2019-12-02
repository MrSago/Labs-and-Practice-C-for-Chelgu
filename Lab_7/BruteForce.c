#include "Header.h"


void BruteForce(unsigned int result, char *string, char filename[])
{
	FILE *file;

	fopen_s(&file, filename, "a");
	fprintf_s(file, "Строка: %s\nРезультат выполнения функции: %d\nНачало перебора:\n", string, result);
	fclose(file);

	char str1[2], str2[3], str3[4], str4[5], str5[6];

	str1[1] = 0;
	str2[2] = 0;
	str3[3] = 0;
	str4[4] = 0;
	str5[5] = 0;


	//1
	for (char i = -64; i <= 122; ++i)
	{
		if (i == 0)
			i = 48;
		else if (i == 58)
			i = 65;
		else if (i == 91)
			i = 97;
		str1[0] = i;
		if (result == HashRot13(str1))
		{
			printf("Коллизия: %s\n", str1);

			fopen_s(&file, filename, "a");
			fprintf_s(file, "Коллизия: %s\n", str1);
			fclose(file);
		}
	}

	//2
	for (char i = -64; i <= 122; ++i)
	{
		if (i == 0)
			i = 48;
		else if (i == 58)
			i = 65;
		else if (i == 91)
			i = 97;
		for (char j = -64; j <= 122; ++j)
		{
			if (j == 0)
				j = 48;
			else if (j == 58)
				j = 65;
			else if (j == 91)
				j = 97;
			str2[0] = i;
			str2[1] = j;
			if (result == HashRot13(str2))
			{
				printf("Коллизия: %s\n", str2);

				fopen_s(&file, filename, "a");
				fprintf_s(file, "Коллизия: %s\n", str2);
				fclose(file);
			}
		}
	}

	//3
	for (char i = -64; i <= 122; ++i)
	{
		if (i == 0)
			i = 48;
		else if (i == 58)
			i = 65;
		else if (i == 91)
			i = 97;
		for (char j = -64; j <= 122; ++j)
		{
			if (j == 0)
				j = 48;
			else if (j == 58)
				j = 65;
			else if (j == 91)
				j = 97;
			for (char m = -64; m <= 122; ++m)
			{
				if (m == 0)
					m = 48;
				else if (m == 58)
					m = 65;
				else if (m == 91)
					m = 97;
				str3[0] = i;
				str3[1] = j;
				str3[2] = m;
				if (result == HashRot13(str3))
				{
					printf("Коллизия: %s\n", str3);

					fopen_s(&file, filename, "a");
					fprintf_s(file, "Коллизия: %s\n", str3);
					fclose(file);
				}
			}
		}
	}

	//4
	for (char i = -64; i <= 122; ++i)
	{
		if (i == 0)
			i = 48;
		else if (i == 58)
			i = 65;
		else if (i == 91)
			i = 97;
		for (char j = -64; j <= 122; ++j)
		{
			if (j == 0)
				j = 48;
			else if (j == 58)
				j = 65;
			else if (j == 91)
				j = 97;
			for (char m = -64; m <= 122; ++m)
			{
				if (m == 0)
					m = 48;
				else if (m == 58)
					m = 65;
				else if (m == 91)
					m = 97;
				for (char n = -64; n <= 122; ++n)
				{
					if (n == 0)
						n = 48;
					else if (n == 58)
						n = 65;
					else if (n == 91)
						n = 97;
					str4[0] = i;
					str4[1] = j;
					str4[2] = m;
					str4[3] = n;
					if (result == HashRot13(str4))
					{
						printf("Коллизия: %s\n", str4);

						fopen_s(&file, filename, "a");
						fprintf_s(file, "Коллизия: %s\n", str4);
						fclose(file);
					}
				}
			}
		}
	}

	//5
	for (char i = -64; i <= 122; ++i)
	{
		if (i == 0)
			i = 48;
		else if (i == 58)
			i = 65;
		else if (i == 91)
			i = 97;
		for (char j = -64; j <= 122; ++j)
		{
			if (j == 0)
				j = 48;
			else if (j == 58)
				j = 65;
			else if (j == 91)
				j = 97;
			for (char m = -64; m <= 122; ++m)
			{
				if (m == 0)
					m = 48;
				else if (m == 58)
					m = 65;
				else if (m == 91)
					m = 97;
				for (char n = -64; n <= 122; ++n)
				{
					if (n == 0)
						n = 48;
					else if (n == 58)
						n = 65;
					else if (n == 91)
						n = 97;
					for (char s = -64; s <= 122; ++s)
					{
						if (s == 0)
							s = 48;
						else if (s == 58)
							s = 65;
						else if (s == 91)
							s = 97;
						str5[0] = i;
						str5[1] = j;
						str5[2] = m;
						str5[3] = n;
						str5[4] = s;
						if (result == HashRot13(str5))
						{
							printf("Коллизия: %s\n", str5);

							fopen_s(&file, filename, "a");
							fprintf_s(file, "Коллизия: %s\n", str5);
							fclose(file);
						}
					}
				}
			}
		}
	}
	fopen_s(&file, filename, "a");
	fprintf(file, "Конец перебора!\n\n");
	fclose(file);
}
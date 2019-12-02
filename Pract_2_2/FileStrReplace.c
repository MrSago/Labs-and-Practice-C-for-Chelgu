#include "Header.h"


void FileStrReplace(char *fin, char *fout, char *rstr, char *str)
{
	errno_t err;
	FILE *input;
	FILE *output;
	size_t rstr_size;
	size_t str_size;
	char c;

	err = FileCheck(&input, fin, "r");
	if (err != SUCCESS) exit(err);

	err = FileCheck(&output, fout, "w");
	if (err != SUCCESS) exit(err);

	rstr_size = strlen(rstr);
	str_size = strlen(str);

	do
	{
		c = fgetc(input);
		if (feof(input))
		{
			goto closefile;
		}
		else if (rstr[0] != c)
		{
			fputc(c, output);
			continue;
		}
		else
		{
			size_t j;

			for (j = 1; j < rstr_size; ++j)
			{
				c = fgetc(input);
				if (feof(input))
				{
					fseek(input, -(long)j, SEEK_CUR);
					for (size_t k = 0; k < j; ++k)
					{
						c = fgetc(input);
						fputc(c, output);
					}

					goto closefile;
				}
				else if (rstr[j] != c)
				{
					break;
				}
			}

			if (j == rstr_size)
			{
				fwrite(str, sizeof(char), str_size, output);
			}
			else
			{
				fseek(input, -(long)j - 1, SEEK_CUR);
				c = fgetc(input);
				fputc(c, output);
			}
		}

	} while (!feof(input));

closefile:
	fclose(input);
	fclose(output);
	return;
}
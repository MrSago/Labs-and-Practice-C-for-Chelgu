#include "Header.h"


void GenerateRandomString(char *out, size_t size, char *alph, size_t sizeAlph)
{
	for (size_t i = 0; i < size; ++i)
	{
		out[i] = alph[rand() % sizeAlph];
	}
	out[size] = 0;
}

char *GenerateRandomPassword(size_t passwordLength, char *alph)
{
	char *pass = (char*)malloc((passwordLength + 1) * sizeof(char));
	if (pass == NULL) exit(EXIT_FAILURE);

	GenerateRandomString(pass, passwordLength, alph, strlen(alph));

	return pass;
}
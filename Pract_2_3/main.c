#include "Header.h"


int main(int argc, char **argv)
{
	srand((unsigned)time(NULL));
	char *password;
	char *outAlph;
	size_t lenPass;

	ParseArgv(argc, argv, &lenPass, &outAlph);
	printf("Alphabet: %s\nPassword Length: %llu\n", outAlph, lenPass);

	password = GenerateRandomPassword(lenPass, outAlph);
	printf("Your generated password: %s", password);

	free(password);
	return 0;
}
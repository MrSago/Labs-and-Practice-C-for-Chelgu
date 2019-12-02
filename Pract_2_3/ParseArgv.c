#include "Header.h"


char *concat(char *s1, char *s2)
{
	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);

	char *result = malloc(len1 + len2 + 1);
	if (result == NULL) exit(EXIT_FAILURE);

	memcpy(result, s1, len1);
	memcpy(result + len1, s2, len2 + 1);

	return result;
}

void ParseArgv(int argc, char **argv, size_t *outPasswordLength, char **outAlph)
{
	if (argc <= 1)
	{
		printf(SYNTAX);
		exit(0);
	}

	bool n_Check = false,
		 a_Check = false,
		 m_Check = false,
		 M_Check = false,
		 C_Check = false;

	size_t minLength, maxLength;
	*outPasswordLength = 0;
	*outAlph = NULL;

	for (int i = 1; i < argc; ++i)
	{
		if (!strcmp(argv[i], "-n") && n_Check == false)	//arg -n
		{
			if (m_Check != false || M_Check != false)
			{
				printf("not compatible agruments: -n -m -M");
				exit(0);
			}
			if (argv[i + 1] == NULL)
			{
				printf("unknown arguments!");
				exit(0);
			}
			if (argv[i + 1][0] == '-')
			{
				printf("not correct arguments: -n");
				exit(0);
			}

			*outPasswordLength = _atoi64((char*)argv[i + 1]);
			if (*outPasswordLength == 0)
			{
				printf("not correct arguemnts: -m");
				exit(0);
			}
			n_Check = true;
			++i;
			continue;
		}
		if (!strcmp(argv[i], "-a") && a_Check == false)	//arg -a
		{
			if (C_Check != false)
			{
				printf("not compatible agruments: -a -C");
				exit(0);
			}
			if (argv[i + 1] == NULL)
			{
				printf("unknown arguments!");
				exit(0);
			}

			*outAlph = (char*)argv[i + 1];
			a_Check = true;
			++i;
			continue;
		}
		if (!strcmp(argv[i], "-m") && m_Check == false)	//arg -m
		{
			if (n_Check != false)
			{
				printf("not compatible agruments: -n -m -M");
				exit(0);
			}
			if (argv[i + 1] == NULL)
			{
				printf("unknown arguments!");
				exit(0);
			}
			if (argv[i + 1][0] == '-')
			{
				printf("not correct arguments: -m");
				exit(0);
			}

			minLength = _atoi64((char*)argv[i + 1]);
			if (minLength == 0)
			{
				printf("not correct arguemnts: -m");
				exit(0);
			}
			m_Check = true;
			++i;
			continue;
		}
		if (!strcmp(argv[i], "-M") && M_Check == false)	//arg -M
		{
			if (n_Check != false)
			{
				printf("not compatible agruments: -n -m -M");
				exit(0);
			}
			if (argv[i + 1] == NULL)
			{
				printf("unknown arguments!");
				exit(0);
			}
			if (argv[i + 1][0] == '-')
			{
				printf("not correct arguments: -M");
				exit(0);
			}

			maxLength = _atoi64((char*)argv[i + 1]);
			if (maxLength == 0)
			{
				printf("not correct arguemnts: -M");
				exit(0);
			}
			M_Check = true;
			++i;
			continue;
		}
		if (strstr(argv[i], "-C") && C_Check == false)	//arg -C[aADS]
		{
			if (a_Check != false)
			{
				printf("not compatible agruments: -a -C");
				exit(0);
			}
			if (argv[i][2] != '[' || argv[i][3] == 0)
			{
				printf("unknown arguments!");
				exit(0);
			}

			bool a_AlphCheck = false,
				 A_AlphCheck = false,
				 D_AlphCheck = false,
				 S_AlphCheck = false;

			for (int k = 3; argv[i][k] != ']' && argv[i][k] != 0; ++k)
			{
				switch (argv[i][k])
				{
				case 'a':
					if (a_AlphCheck != false)
					{
						break;
					}
					else
					{
						a_AlphCheck = true;
					}

					if (*outAlph == NULL)
					{
						*outAlph = ARG_a;
					}
					else
					{
						*outAlph = concat(*outAlph, ARG_a);
					}

					break;

				case 'A':
					if (A_AlphCheck != false)
					{
						break;
					}
					else
					{
						A_AlphCheck = true;
					}

					if (*outAlph == NULL)
					{
						*outAlph = ARG_A;
					}
					else
					{
						*outAlph = concat(*outAlph, ARG_A);
					}

					break;

				case 'D':
					if (D_AlphCheck != false)
					{
						break;
					}
					else
					{
						D_AlphCheck = true;
					}

					if (*outAlph == NULL)
					{
						*outAlph = ARG_D;
					}
					else
					{
						*outAlph = concat(*outAlph, ARG_D);
					}

					break;

				case 'S':
					if (S_AlphCheck != false)
					{
						break;
					}
					else
					{
						S_AlphCheck = true;
					}

					if (*outAlph == NULL)
					{
						*outAlph = ARG_S;
					}
					else
					{
						*outAlph = concat(*outAlph, ARG_S);
					}

					break;
				}
			}
			C_Check = true;
		}
	}

	if (minLength > maxLength)
	{
		printf("not correct arguemnts: -m -M");
		exit(0);
	}

	if (m_Check == true && M_Check == true)
	{
		*outPasswordLength = minLength + (rand() % (maxLength - minLength + 1));
	}

	if (*outPasswordLength == 0 || *outAlph == NULL)
	{
		printf("few arguments!");
		exit(0);
	}
}
#include "./main.h"
#pragma warning(disable:6031)

int main(int argc, char** argv, char** envp)
{
	setlocale(LC_ALL, "Rus");

	char* str = "Вышел Петя на пенек и скушал пирожок, а пирожок был не простым, пирожок был золотым";
	char* find = "ро";

	printf("str = %s\n", str);
	printf("find = %s\n", find);
	printf("%llu\n", strfind(str, find));

	printf("\nPress any key to continue...");
	_getch();
	return (0);
}

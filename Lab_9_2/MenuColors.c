#include "Header.h"


void MenuColors(int *color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Black));
	printf("0  - Black\n");
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Blue));
	printf("1  - Blue\n");
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Green));
	printf("2  - Green\n");
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Cyan));
	printf("3  - Cyan\n");
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Red));
	printf("4  - Red\n");
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Magenta));
	printf("5  - Magenta\n");
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Brown));
	printf("6  - Brown\n");
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | LightGray));
	printf("7  - LightGray\n");
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | DarkGray));
	printf("8  - DarkGray\n");
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | LightBlue));
	printf("9  - LightBlue\n");
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | LightGreen));
	printf("10 - LightGreen\n");
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | LightCyan));
	printf("11 - LightCyan\n");
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | LightRed));
	printf("12 - LightRed\n");
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | LightMagenta));
	printf("13 - LightMagenta\n");
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | Yellow));
	printf("14 - Yellow\n");
	SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | White));
	printf("15 - White\n");

	while (1)
	{
		printf("Выберите цвет: ");

		switch (MenuSelection())
		{
		case Black:
			*color = Black;
			return;

		case Blue:
			*color = Blue;
			return;

		case Green:
			*color = Green;
			return;

		case Cyan:
			*color = Cyan;
			return;

		case Red:
			*color = Red;
			return;

		case Magenta:
			*color = Magenta;
			return;

		case Brown:
			*color = Brown;
			return;

		case LightGray:
			*color = LightGray;
			return;

		case DarkGray:
			*color = DarkGray;
			return;

		case LightBlue:
			*color = LightBlue;
			return;

		case LightGreen:
			*color = LightGreen;
			return;

		case LightCyan:
			*color = LightCyan;
			return;

		case LightRed:
			*color = LightRed;
			return;

		case LightMagenta:
			*color = LightMagenta;
			return;

		case Yellow:
			*color = Yellow;
			return;

		case White:
			*color = White;
			return;

		default:
			printf("Ошибка! Нет такого цвета в списке!\n");
			break;
		}
	}
}
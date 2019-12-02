#include "Header.h"


void PaintSnow(COORD start)
{
	clrscr();

	gotoxy(start.X, start.Y - 1);
	puts("*");

	gotoxy(start.X, start.Y + 1);
	puts("*");

	gotoxy(start.X - 1, start.Y);
	puts("*");

	gotoxy(start.X + 1, start.Y);
	puts("*");

	gotoxy(start.X, start.Y);
	puts("*");
}
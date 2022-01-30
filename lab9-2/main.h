#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define GREETINGS "Welcome to Hacker v2.0\n"
#define STR_SIZE 300
#define CONSOLE_HEIGHT 9000

enum ConsoleColor {
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};

void MenuColors(int* color);
int MenuSelection();
char* RandomString(size_t str_size);
char* ScanString();

void setconsolesize(int x, int y);
void hidecursor();
void clrscr();
void gotoxy(int column, int row);

#endif

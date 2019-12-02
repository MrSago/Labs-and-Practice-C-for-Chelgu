#ifndef HEADER_H
#define HEADER_H

#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "conio.h"
#include "windows.h"
#include "time.h"

#define MOVE_RANDOM (1 + (rand() % 4))
#define MOVE_UP 1
#define MOVE_DOWN 2
#define MOVE_LEFT 3
#define MOVE_RIGHT 4

#define SPEED_UP 43
#define SPEED_DOWN 45

void setconsolesize(int x, int y);
void hidecursor();
void clrscr();
void gotoxy(int column, int row);

void PaintSnow(COORD start);
#endif //HEADER_H
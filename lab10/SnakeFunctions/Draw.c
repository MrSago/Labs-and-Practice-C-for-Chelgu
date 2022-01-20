
#include "../Header.h"

void setconsolesize(int x, int y) {
    HANDLE hCons;
    COORD crd;
    SMALL_RECT rct;
    crd.X = (short)x + 1;
    crd.Y = (short)y + 1;
    rct.Left = 0;
    rct.Top = 0;
    rct.Right = x;
    rct.Bottom = y;
    hCons = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(hCons, crd);
    SetConsoleWindowInfo(hCons, 1, &rct);
}

void hidecursor() {
    HANDLE hCons;
    CONSOLE_CURSOR_INFO cci;
    hCons = GetStdHandle(STD_OUTPUT_HANDLE);
    cci.dwSize = 1;
    cci.bVisible = 0;
    SetConsoleCursorInfo(hCons, &cci);
}

void clrscr() {
    HANDLE hCons;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD crd;
    int len;
    DWORD bRet;
    short x, y;
    char space = 0x20;
    hCons = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hCons, &csbi);
    x = csbi.dwSize.X;
    y = csbi.dwSize.Y;
    len = (int)x * y;
    crd.X = 0;
    crd.Y = 0;
    FillConsoleOutputCharacter(hCons, space, len, crd, &bRet);
}

void gotoxy(int column, int row) {
    HANDLE hCons;
    COORD crd;
    hCons = GetStdHandle(STD_OUTPUT_HANDLE);
    crd.X = (short)column;
    crd.Y = (short)row;
    SetConsoleCursorPosition(hCons, crd);
}



#include "main.h"

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    char *string;
    DWORD delay;
    int color;

    srand((unsigned)time(NULL));
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    clrscr();

    SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | White));
    printf(GREETINGS);
    printf("¬ведите задержку в мс: ");
    scanf_s("%lu", &delay);

    MenuColors(&color);
    SetConsoleTextAttribute(hConsole, (WORD)((Black << 4) | color));

    clrscr();
    hidecursor();
    setconsolesize(STR_SIZE, CONSOLE_HEIGHT);
    gotoxy(0, 49);

    while (1) {
        string = RandomString(STR_SIZE);
        printf("%s\n", string);
        free(string);
        Sleep(delay);
    }

    return 0;
}

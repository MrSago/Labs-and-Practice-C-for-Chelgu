
#include "../Header.h"

void WorldGraphics() {
    extern WORLD World;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const char str[] = "Your Score: ";
    BOOL ColorBarrier = FALSE, ColorSnake = FALSE;
    SHORT i, j;

    system("cls");
    system("color 20");

    if (World.Size.X < 14)
        setconsolesize(14, World.Size.Y);
    else
        setconsolesize(World.Size.X, World.Size.Y);

    for (i = 0; i < World.Size.Y; ++i) {
        for (j = 0; j < World.Size.X; ++j) {
            switch (World.buf[i][j]) {
                case WORLD_BARRIER:
                    gotoxy(j, i);
                    if (ColorBarrier == FALSE) {
                        SetConsoleTextAttribute(hConsole,
                                                (WORD)((Green << 4) | Black));
                        ColorBarrier = TRUE;
                        ColorSnake = FALSE;
                    }
                    putchar(GRAPHIC_BARRIER);
                    break;

                case WORLD_SPACE:
                    break;

                case SNAKE_TAIL:
                    gotoxy(j, i);
                    if (ColorSnake == FALSE) {
                        SetConsoleTextAttribute(hConsole,
                                                (WORD)((Green << 4) | Magenta));
                        ColorBarrier = FALSE;
                        ColorSnake = TRUE;
                    }
                    putchar(GRAPHIC_SNAKE_TAIL);
                    break;

                case SNAKE_HEAD:
                    gotoxy(j, i);
                    if (ColorSnake == FALSE) {
                        SetConsoleTextAttribute(hConsole,
                                                (WORD)((Green << 4) | Magenta));
                        ColorBarrier = FALSE;
                        ColorSnake = TRUE;
                    }
                    printf("%c", GRAPHIC_SNAKE_HEAD);
                    break;
            }
        }
    }

    SetConsoleTextAttribute(hConsole, (WORD)((Green << 4) | Yellow));
    gotoxy(0, World.Size.Y);
    printf("%s", str);
    ScoreGraphics();
}

void SnakeGraphics() {
    extern SNAKE Snake;
    extern OPTIONS SnakeOptions;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    size_t i;

    gotoxy(Snake.CoordsHead.X, Snake.CoordsHead.Y);
    SetConsoleTextAttribute(hConsole, (WORD)((Green << 4) | Magenta));
    printf("%c", GRAPHIC_SNAKE_HEAD);

    gotoxy(SnakeOptions.SaveCoords.X, SnakeOptions.SaveCoords.Y);
    putchar(GRAPHIC_SPACE);
    for (i = 0; i < Snake.Lenght - 1; ++i) {
        gotoxy(Snake.CoordsTail[i].X, Snake.CoordsTail[i].Y);
        putchar(GRAPHIC_SNAKE_TAIL);
    }
}

void AppleGraphics(COORD Apple) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoxy(Apple.X, Apple.Y);
    SetConsoleTextAttribute(hConsole, (WORD)((Green << 4) | Red));
    putchar(GRAPHIC_APPLE);
}

void ScoreGraphics() {
    extern WORLD World;
    extern OPTIONS SnakeOptions;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    gotoxy(12, World.Size.Y);
    SetConsoleTextAttribute(hConsole, (WORD)((Green << 4) | LightCyan));
    printf("%llu", SnakeOptions.Score);
}



#include "Header.h"

WORLD World;
SNAKE Snake;
OPTIONS SnakeOptions;

int main() {
    srand((unsigned)time(NULL));
    setlocale(LC_ALL, "Rus");
    setconsolesize(42, 7);
    hidecursor();
    system("cls");
    system("color 0A");

    if (!sndPlaySound(SOUND_WELCOME, SND_ASYNC | SND_NODEFAULT)) {
        system("cls");
        printf(SNAKE_PLAY_SOUND, SOUND_WELCOME);
        system("pause");
        exit(ERR_PLAY_SOUND);
    }

    printf(SNAKE_VERSION);
    printf(SNAKE_WELCOME);

    while (1) {
        printf(SNAKE_MAIN_MENU);
        switch (MenuSelection()) {
            case 1:
                SnakeWorldSize();
                SnakeDifficult();
                SnakeWorldGen();
                SnakeKB();
                break;

            case 2:
                break;

            case 0:
                system("cls");
                system("color 0F");
                setconsolesize(120, 30);
                return 0;

            default:
                printf("��� ����� �����!\n\n");
                break;
        }
    }

    return 0;
}


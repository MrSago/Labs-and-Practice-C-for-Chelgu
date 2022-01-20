
#include "../Header.h"

void SnakeKB() {
    extern SNAKE Snake;
    extern OPTIONS SnakeOptions;
    int key;

    if (!sndPlaySound(SOUND_BACKGROUND, SND_ASYNC | SND_LOOP | SND_NODEFAULT)) {
        system("cls");
        printf(SNAKE_PLAY_SOUND, SOUND_BACKGROUND);
        system("pause");
        exit(ERR_PLAY_SOUND);
    }

    while (!_kbhit()) {
        Sleep(1);
    }

    while (1) {
        Sleep(SnakeOptions.Delay);

        if (_kbhit()) {
            key = _getch();
            key = _getch();

            switch (key) {
                case ARROW_UP:
                    if (Snake.Look != LOOK_UP && Snake.Look != LOOK_DOWN) {
                        Snake.Look = LOOK_UP;
                    }
                    break;

                case ARROW_DOWN:
                    if (Snake.Look != LOOK_DOWN && Snake.Look != LOOK_UP) {
                        Snake.Look = LOOK_DOWN;
                    }
                    break;

                case ARROW_LEFT:
                    if (Snake.Look != LOOK_LEFT && Snake.Look != LOOK_RIGHT) {
                        Snake.Look = LOOK_LEFT;
                    }
                    break;

                case ARROW_RIGHT:
                    if (Snake.Look != LOOK_RIGHT && Snake.Look != LOOK_LEFT) {
                        Snake.Look = LOOK_RIGHT;
                    }
                    break;

                default:
                    break;
            }
        }

        if (SnakeMove() == GAME_OVER) {
            SnakeGameOver();
            return;
        } else {
            SnakeGraphics();
        }
    }
}


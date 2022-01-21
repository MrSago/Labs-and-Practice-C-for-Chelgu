
#include "../Header.h"

BOOL SnakeMove() {
    extern WORLD World;
    extern SNAKE Snake;
    extern OPTIONS SnakeOptions;
    COORD tmp_coord, *tmp_tail;
    size_t i;

    SnakeOptions.SaveCoords.X = Snake.CoordsHead.X;
    SnakeOptions.SaveCoords.Y = Snake.CoordsHead.Y;

    switch (Snake.Look) {
        case LOOK_UP:
            if (World.buf[Snake.CoordsHead.Y - SNAKE_STEP]
                         [Snake.CoordsHead.X] == WORLD_BARRIER ||
                World.buf[Snake.CoordsHead.Y - SNAKE_STEP]
                         [Snake.CoordsHead.X] == SNAKE_TAIL) {
                return GAME_OVER;
            }

            if (World.buf[Snake.CoordsHead.Y - SNAKE_STEP]
                         [Snake.CoordsHead.X] == WORLD_APPLE) {
                SnakeOptions.Score += SnakeOptions.Multiply;
                ++Snake.Lenght;

                AppleGen();
                printf("\a");
                ScoreGraphics();

                tmp_tail = (COORD*)realloc(Snake.CoordsTail,
                                           (Snake.Lenght - 1) * sizeof(COORD));

                if (tmp_tail == NULL) {
                    system("cls");
                    printf(SNAKE_ALLOC_MEMORY);
                    system("pause");
                    exit(ERR_ALLOC_MEMORY);
                }

                Snake.CoordsTail = tmp_tail;

                Snake.CoordsTail[Snake.Lenght - 2].X =
                    Snake.CoordsTail[Snake.Lenght - 3].X;
                Snake.CoordsTail[Snake.Lenght - 2].Y =
                    Snake.CoordsTail[Snake.Lenght - 3].Y;
            }

            Snake.CoordsHead.Y -= SNAKE_STEP;
            World.buf[Snake.CoordsHead.Y][Snake.CoordsHead.X] = SNAKE_HEAD;

            break;

        case LOOK_DOWN:
            if (World.buf[Snake.CoordsHead.Y + SNAKE_STEP]
                         [Snake.CoordsHead.X] == WORLD_BARRIER ||
                World.buf[Snake.CoordsHead.Y + SNAKE_STEP]
                         [Snake.CoordsHead.X] == SNAKE_TAIL) {
                return GAME_OVER;
            }

            if (World.buf[Snake.CoordsHead.Y + SNAKE_STEP]
                         [Snake.CoordsHead.X] == WORLD_APPLE) {
                SnakeOptions.Score += SnakeOptions.Multiply;
                ++Snake.Lenght;

                AppleGen();
                printf("\a");
                ScoreGraphics();

                tmp_tail = (COORD*)realloc(Snake.CoordsTail,
                                           (Snake.Lenght - 1) * sizeof(COORD));

                if (tmp_tail == NULL) {
                    system("cls");
                    printf(SNAKE_ALLOC_MEMORY);
                    system("pause");
                    exit(ERR_ALLOC_MEMORY);
                }

                Snake.CoordsTail = tmp_tail;

                Snake.CoordsTail[Snake.Lenght - 2].X =
                    Snake.CoordsTail[Snake.Lenght - 3].X;
                Snake.CoordsTail[Snake.Lenght - 2].Y =
                    Snake.CoordsTail[Snake.Lenght - 3].Y;
            }

            Snake.CoordsHead.Y += SNAKE_STEP;
            World.buf[Snake.CoordsHead.Y][Snake.CoordsHead.X] = SNAKE_HEAD;

            break;

        case LOOK_LEFT:
            if (World.buf[Snake.CoordsHead.Y]
                         [Snake.CoordsHead.X - SNAKE_STEP] == WORLD_BARRIER ||
                World.buf[Snake.CoordsHead.Y]
                         [Snake.CoordsHead.X - SNAKE_STEP] == SNAKE_TAIL) {
                return GAME_OVER;
            }

            if (World.buf[Snake.CoordsHead.Y]
                         [Snake.CoordsHead.X - SNAKE_STEP] == WORLD_APPLE) {
                SnakeOptions.Score += SnakeOptions.Multiply;
                ++Snake.Lenght;

                AppleGen();
                printf("\a");
                ScoreGraphics();

                tmp_tail = (COORD*)realloc(Snake.CoordsTail,
                                           (Snake.Lenght - 1) * sizeof(COORD));

                if (tmp_tail == NULL) {
                    system("cls");
                    printf(SNAKE_ALLOC_MEMORY);
                    system("pause");
                    exit(ERR_ALLOC_MEMORY);
                }

                Snake.CoordsTail = tmp_tail;

                Snake.CoordsTail[Snake.Lenght - 2].X =
                    Snake.CoordsTail[Snake.Lenght - 3].X;
                Snake.CoordsTail[Snake.Lenght - 2].Y =
                    Snake.CoordsTail[Snake.Lenght - 3].Y;
            }

            Snake.CoordsHead.X -= SNAKE_STEP;
            World.buf[Snake.CoordsHead.Y][Snake.CoordsHead.X] = SNAKE_HEAD;

            break;

        case LOOK_RIGHT:
            if (World.buf[Snake.CoordsHead.Y]
                         [Snake.CoordsHead.X + SNAKE_STEP] == WORLD_BARRIER ||
                World.buf[Snake.CoordsHead.Y]
                         [Snake.CoordsHead.X + SNAKE_STEP] == SNAKE_TAIL) {
                return GAME_OVER;
            }

            if (World.buf[Snake.CoordsHead.Y]
                         [Snake.CoordsHead.X + SNAKE_STEP] == WORLD_APPLE) {
                SnakeOptions.Score += SnakeOptions.Multiply;
                ++Snake.Lenght;

                AppleGen();
                printf("\a");
                ScoreGraphics();

                tmp_tail = (COORD*)realloc(Snake.CoordsTail,
                                           (Snake.Lenght - 1) * sizeof(COORD));

                if (tmp_tail == NULL) {
                    system("cls");
                    printf(SNAKE_ALLOC_MEMORY);
                    system("pause");
                    exit(ERR_ALLOC_MEMORY);
                }

                Snake.CoordsTail = tmp_tail;

                Snake.CoordsTail[Snake.Lenght - 2].X =
                    Snake.CoordsTail[Snake.Lenght - 3].X;
                Snake.CoordsTail[Snake.Lenght - 2].Y =
                    Snake.CoordsTail[Snake.Lenght - 3].Y;
            }

            Snake.CoordsHead.X += SNAKE_STEP;
            World.buf[Snake.CoordsHead.Y][Snake.CoordsHead.X] = SNAKE_HEAD;

            break;
    }

    for (i = 0; i < Snake.Lenght - 2; ++i) {
        World.buf[SnakeOptions.SaveCoords.Y][SnakeOptions.SaveCoords.X] =
            SNAKE_TAIL;

        tmp_coord.X = SnakeOptions.SaveCoords.X;
        tmp_coord.Y = SnakeOptions.SaveCoords.Y;

        SnakeOptions.SaveCoords.X = Snake.CoordsTail[i].X;
        SnakeOptions.SaveCoords.Y = Snake.CoordsTail[i].Y;

        Snake.CoordsTail[i].X = tmp_coord.X;
        Snake.CoordsTail[i].Y = tmp_coord.Y;
    }

    World.buf[Snake.CoordsTail[Snake.Lenght - 2].Y]
             [Snake.CoordsTail[Snake.Lenght - 2].X] = WORLD_SPACE;
    World.buf[SnakeOptions.SaveCoords.Y][SnakeOptions.SaveCoords.X] =
        SNAKE_TAIL;

    tmp_coord.X = SnakeOptions.SaveCoords.X;
    tmp_coord.Y = SnakeOptions.SaveCoords.Y;

    SnakeOptions.SaveCoords.X = Snake.CoordsTail[Snake.Lenght - 2].X;
    SnakeOptions.SaveCoords.Y = Snake.CoordsTail[Snake.Lenght - 2].Y;

    Snake.CoordsTail[Snake.Lenght - 2].X = tmp_coord.X;
    Snake.CoordsTail[Snake.Lenght - 2].Y = tmp_coord.Y;

    return GAME_CONTINUE;
}


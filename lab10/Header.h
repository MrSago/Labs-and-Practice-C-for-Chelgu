#ifndef HEADER_H
#define HEADER_H

/*---------------Includes-------------*/
#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "locale.h"
#include "time.h"
#include "windows.h"
#include "conio.h"
#include "mmsystem.h"
#pragma comment (lib, "Winmm.lib")
/*------------------------------------*/

/*---------------Options--------------*/
#define SNAKE_VERSION "Snake v1.0"
#define SNAKE_WELCOME "\nДобро пожаловать в змейку!\n\n"
#define SNAKE_MAIN_MENU "Выбери тип игры:\n1.Ручная змейка\n2.Автоматическая змейка\n0.Выйти из игры\n"
#define SNAKE_DIF_MENU "Выберите сложность:\n1.Легко(x1 Score Multipl.)\n2.Средне(x2 Score Multipl.)\n3.Сложно(x5 Score Multipl.)\n"
#define SNAKE_PLAY_SOUND "Can not play sound: %s\n"
#define SNAKE_ALLOC_MEMORY "Can not allocate memory!\n"
#define SOUND_WELCOME "sound/Harp.wav"
#define SOUND_BARRIER "sound/klick.wav"
#define SOUND_LOOSE "sound/loser.wav"
#define SOUND_BACKGROUND "sound/bg.wav"
#define SNAKE_START_SIZE 3
#define GAME_OVER TRUE
#define GAME_CONTINUE FALSE
#define SNAKE_STEP 1
/*------------------------------------*/

/*-----------Arrows keyboard----------*/
#define ARROW_UP 72
#define ARROW_DOWN 80
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
/*------------------------------------*/

/*------------Graphics chars----------*/
#define GRAPHIC_BARRIER '#'
#define GRAPHIC_SPACE ' '
#define GRAPHIC_SNAKE_TAIL 'O'
#define GRAPHIC_SNAKE_HEAD -92
#define GRAPHIC_APPLE '@'
/*------------------------------------*/

/*---------------Errors---------------*/
#define ERR_ALLOC_MEMORY -1
#define ERR_PLAY_SOUND -2
/*------------------------------------*/

/*------------List of colors----------*/
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
/*------------------------------------*/

/*---------New types for Snake--------*/
typedef enum __ScoreMultiply {
    SM_X1 = 1,
    SM_X2 = 2,
    SM_X5 = 5
} ScoreMultiply;

typedef enum __ScoreDelay {
    SD_X1 = 200,
    SD_X2 = 150,
    SD_X5 = 100
} ScoreDelay;

typedef enum __SnakeLook {
    LOOK_UP = -1,
    LOOK_DOWN = 1,
    LOOK_LEFT = -2,
    LOOK_RIGHT = 2
} SnakeLook;

/*World's objects in memory*/
typedef enum __WorldObjs {

    /*Snake struct*/
    SNAKE_HEAD = 8,
    SNAKE_TAIL = 2,

    /*World structures*/
    WORLD_BARRIER = -1,
    WORLD_APPLE = 1,
    WORLD_SPACE = 0

} WorldObjs;
/*------------------------------------*/

/*--------Typedefs and structs--------*/
typedef struct __World {
    WorldObjs **buf;
    COORD Size;
} WORLD;

typedef struct __Snake {
    COORD CoordsHead;
    COORD *CoordsTail;
    size_t Lenght;
    SnakeLook Look;
} SNAKE;

typedef struct __Options {
    COORD SaveCoords;
    ScoreDelay Delay;
    uint64_t Score;
    ScoreMultiply Multiply;
} OPTIONS;
/*------------------------------------*/

/*--------------Functions-------------*/
/*Menu functions*/
int MenuSelection();
void SnakeKB();
void SnakeAI();

/*World functions*/
void SnakeWorldGen();
void WorldMemAlloc();
void WorldBarrierGen();
void FreeSpaceGen();
void BarriersGen();
void SnakeGen();
void AppleGen();

/*Snake functions*/
BOOL SnakeMove();
void SnakeDifficult();
void SnakeWorldSize();
void SnakeGameOver();

/*Graphics functions*/
void WorldGraphics();
void SnakeGraphics();
void AppleGraphics(COORD Apple);
void ScoreGraphics();

/*Draw functions*/
void setconsolesize(int x, int y);
void hidecursor();
void clrscr();
void gotoxy(int column, int row);
/*------------------------------------*/

#endif


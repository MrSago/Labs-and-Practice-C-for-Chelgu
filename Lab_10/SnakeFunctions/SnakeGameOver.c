#include "../Header.h"


void SnakeGameOver()
{
	extern WORLD World;
	extern OPTIONS SnakeOptions;
	extern SNAKE Snake;

	if (!sndPlaySound(SOUND_BARRIER, SND_SYNC | SND_NODEFAULT))
	{
		system("cls");
		printf(SNAKE_PLAY_SOUND, SOUND_BARRIER);
		system("pause");
		exit(ERR_PLAY_SOUND);
	}

	system("cls");
	system("color 0A");
	setconsolesize(42, 7);
	printf("Game Over!\nYour Score: %llu\n", SnakeOptions.Score);

	for (SHORT i = 0; i < World.Size.Y; ++i)
		free(World.buf[i]);

	free(World.buf);
	free(Snake.CoordsTail);

	World.Size.X = 0; Snake.CoordsHead.X = 0;
	World.Size.Y = 0; Snake.CoordsHead.Y = 0;
	Snake.Lenght = 0;
	Snake.Look = 0;
	SnakeOptions.Score = 0;

	if (!sndPlaySound(SOUND_LOOSE, SND_SYNC | SND_NODEFAULT))
	{
		system("cls");
		printf(SNAKE_PLAY_SOUND, SOUND_LOOSE);
		system("pause");
		exit(ERR_PLAY_SOUND);
	}

	system("pause");
	system("cls");
}
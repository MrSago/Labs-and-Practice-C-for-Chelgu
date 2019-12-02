#include "../Header.h"


void SnakeDifficult()
{
	extern OPTIONS SnakeOptions;

	while (1)
	{
		printf(SNAKE_DIF_MENU);

		switch (MenuSelection())
		{
		case 1:
			SnakeOptions.Delay = SD_X1;
			SnakeOptions.Multiply = SM_X1;
			return;

		case 2:
			SnakeOptions.Delay = SD_X2;
			SnakeOptions.Multiply = SM_X2;
			return;

		case 3:
			SnakeOptions.Delay = SD_X5;
			SnakeOptions.Multiply = SM_X5;
			return;

		default:
			break;
		}
	}
}
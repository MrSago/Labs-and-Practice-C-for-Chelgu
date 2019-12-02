#include "../Header.h"


void SnakeWorldSize()
{
	extern WORLD World;
	SHORT size;

	do
	{
		system("cls");
		printf("¬ведите размер пол€ (мин. 10x10): ");
		size = MenuSelection();
	} while (size < 10);

	World.Size.X = size;
	World.Size.Y = size;
}
#include "../Header.h"


void SnakeWorldGen()
{
	WorldMemAlloc();		//Memory allocate for the World
	WorldBarrierGen();		//Gen World's Barrier
	FreeSpaceGen();			//Gen Free space
	BarriersGen();			//Gen Barriers
	SnakeGen();				//Gen Snake in the World
	WorldGraphics();		//World Graphics
	AppleGen();				//Gen Apple in the World
}


void WorldMemAlloc()
{
	extern WORLD World;

	World.buf = (WorldObjs**)malloc(World.Size.Y * sizeof(WorldObjs*));

	if (World.buf == NULL)
	{
		system("cls");
		printf(SNAKE_ALLOC_MEMORY);
		system("pause");
		exit(ERR_ALLOC_MEMORY);
	}

	for (SHORT i = 0; i < World.Size.Y; ++i)
	{
		World.buf[i] = (WorldObjs*)malloc(World.Size.X * sizeof(WorldObjs));

		if (World.buf[i] == NULL)
		{
			system("cls");
			printf(SNAKE_ALLOC_MEMORY);
			system("pause");
			exit(ERR_ALLOC_MEMORY);
		}
	}
}
void WorldBarrierGen()
{
	extern WORLD World;
	
	/*Y - coords*/
	for (SHORT i = 0; i < World.Size.Y; ++i)
	{
		World.buf[i][0] = WORLD_BARRIER;
		World.buf[World.Size.Y - 1 - i][World.Size.X - 1] = WORLD_BARRIER;
	}

	/*X - coords*/
	for (SHORT i = 0; i < World.Size.X; ++i)	
	{
		World.buf[0][i] = WORLD_BARRIER;
		World.buf[World.Size.Y - 1][World.Size.X - 1 - i] = WORLD_BARRIER;
	}
}
void FreeSpaceGen()
{
	extern WORLD World;

	for (SHORT i = 1; i < World.Size.Y - 1; ++i)
	{
		for (SHORT j = 1; j < World.Size.X - 1; ++j)
		{
			World.buf[i][j] = WORLD_SPACE;
		}
	}
}
void BarriersGen()
{
	extern WORLD World;
	extern OPTIONS SnakeOptions;
	COORD current;
	size_t count;

	switch (SnakeOptions.Multiply)
	{
	case SM_X1:
		count = (World.Size.X * World.Size.Y) / 100;
		break;

	case SM_X2:
		count = (World.Size.X * World.Size.Y) / 50;
		break;

	case SM_X5:
		count = (World.Size.X * World.Size.Y) / 30;
		break;
	}

	for (size_t i = 1; i < count + 1; ++i)
	{
		do
		{
			current.X = 2 + (rand() % (World.Size.X - 3));
			current.Y = 2 + (rand() % (World.Size.Y - 3));
		} while (World.buf[current.Y][current.X] != WORLD_SPACE);

		if (World.buf[current.Y - 1][current.X - 1] != WORLD_SPACE ||
			World.buf[current.Y - 1][current.X] != WORLD_SPACE ||
			World.buf[current.Y - 1][current.X + 1] != WORLD_SPACE ||
			World.buf[current.Y - 1][current.X + 2] != WORLD_SPACE ||
			World.buf[current.Y][current.X - 1] != WORLD_SPACE ||
			World.buf[current.Y][current.X] != WORLD_SPACE ||
			World.buf[current.Y][current.X + 1] != WORLD_SPACE ||
			World.buf[current.Y][current.X + 2] != WORLD_SPACE ||
			World.buf[current.Y + 1][current.X - 1] != WORLD_SPACE ||
			World.buf[current.Y + 1][current.X] != WORLD_SPACE ||
			World.buf[current.Y + 1][current.X + 1] != WORLD_SPACE ||
			World.buf[current.Y + 1][current.X + 2] != WORLD_SPACE ||
			World.buf[current.Y + 2][current.X - 1] != WORLD_SPACE ||
			World.buf[current.Y + 2][current.X] != WORLD_SPACE ||
			World.buf[current.Y + 2][current.X + 1] != WORLD_SPACE ||
			World.buf[current.Y + 2][current.X + 2] != WORLD_SPACE)
		{
			--i;
			continue;
		}

		switch (rand() % 4)
		{
		case 0:
			World.buf[current.Y][current.X] = WORLD_BARRIER;
			World.buf[current.Y][current.X + 1] = WORLD_BARRIER;
			World.buf[current.Y + 1][current.X] = WORLD_BARRIER;
			continue;

		case 1:
			World.buf[current.Y][current.X + 1] = WORLD_BARRIER;
			World.buf[current.Y][current.X] = WORLD_BARRIER;
			World.buf[current.Y + 1][current.X + 1] = WORLD_BARRIER;
			continue;

		case 2:
			World.buf[current.Y + 1][current.X + 1] = WORLD_BARRIER;
			World.buf[current.Y + 1][current.X] = WORLD_BARRIER;
			World.buf[current.Y][current.X + 1] = WORLD_BARRIER;
			continue;

		case 3:
			World.buf[current.Y + 1][current.X] = WORLD_BARRIER;
			World.buf[current.Y][current.X] = WORLD_BARRIER;
			World.buf[current.Y + 1][current.X + 1] = WORLD_BARRIER;
			continue;

		default:
			--i;
			break;
		}
	}
}
void SnakeGen()
{
	extern WORLD World;
	extern SNAKE Snake;
	COORD tmp;
	BOOL check = FALSE;

	Snake.Lenght = SNAKE_START_SIZE;
	Snake.CoordsTail = (COORD*)malloc((SNAKE_START_SIZE - 1) * sizeof(COORD));

	if (Snake.CoordsTail == NULL)
	{
		system("cls");
		printf(SNAKE_ALLOC_MEMORY);
		system("pause");
		exit(ERR_ALLOC_MEMORY);
	}

	do
	{
		Snake.CoordsHead.X = 1 + (rand() % (World.Size.X - 2));
		Snake.CoordsHead.Y = 1 + (rand() % (World.Size.Y - 2));
	}
	while (World.buf[Snake.CoordsHead.Y][Snake.CoordsHead.X] != WORLD_SPACE);

	World.buf[Snake.CoordsHead.Y][Snake.CoordsHead.X] = SNAKE_HEAD;

	tmp.X = Snake.CoordsHead.X;
	tmp.Y = Snake.CoordsHead.Y;

	for (SHORT i = 1; i < SNAKE_START_SIZE; ++i)
	{
		switch (rand() % 4)
		{
		case 0:
			if (World.buf[tmp.Y - 1][tmp.X] == WORLD_SPACE)
			{
				Snake.CoordsTail[i - 1].X = tmp.X;
				Snake.CoordsTail[i - 1].Y = tmp.Y - 1;
				World.buf[Snake.CoordsTail[i - 1].Y][Snake.CoordsTail[i - 1].X] = SNAKE_TAIL;

				tmp.X = Snake.CoordsTail[i - 1].X;
				tmp.Y = Snake.CoordsTail[i - 1].Y;

				if (check == FALSE)
				{
					Snake.Look = LOOK_DOWN;
					check = TRUE;
				}

				break;
			}

		case 1:
			if (World.buf[tmp.Y + 1][tmp.X] == WORLD_SPACE)
			{
				Snake.CoordsTail[i - 1].X = tmp.X;
				Snake.CoordsTail[i - 1].Y = tmp.Y + 1;
				World.buf[Snake.CoordsTail[i - 1].Y][Snake.CoordsTail[i - 1].X] = SNAKE_TAIL;

				tmp.X = Snake.CoordsTail[i - 1].X;
				tmp.Y = Snake.CoordsTail[i - 1].Y;

				if (check == FALSE)
				{
					Snake.Look = LOOK_UP;
					check = TRUE;
				}

				break;
			}

		case 2:
			if (World.buf[tmp.Y][tmp.X - 1] == WORLD_SPACE)
			{
				Snake.CoordsTail[i - 1].X = tmp.X - 1;
				Snake.CoordsTail[i - 1].Y = tmp.Y;
				World.buf[Snake.CoordsTail[i - 1].Y][Snake.CoordsTail[i - 1].X] = SNAKE_TAIL;

				tmp.X = Snake.CoordsTail[i - 1].X;
				tmp.Y = Snake.CoordsTail[i - 1].Y;

				if (check == FALSE)
				{
					Snake.Look = LOOK_RIGHT;
					check = TRUE;
				}

				break;
			}

		case 3:
			if (World.buf[tmp.Y][tmp.X + 1] == WORLD_SPACE)
			{
				Snake.CoordsTail[i - 1].X = tmp.X + 1;
				Snake.CoordsTail[i - 1].Y = tmp.Y;
				World.buf[Snake.CoordsTail[i - 1].Y][Snake.CoordsTail[i - 1].X] = SNAKE_TAIL;

				tmp.X = Snake.CoordsTail[i - 1].X;
				tmp.Y = Snake.CoordsTail[i - 1].Y;

				if (check == FALSE)
				{
					Snake.Look = LOOK_LEFT;
					check = TRUE;
				}

				break;
			}

		default:
			--i;
			break;
		}
	}
}
void AppleGen()
{
	extern WORLD World;
	COORD Apple;

	while (1)
	{
		Apple.X = 1 + (rand() % (World.Size.X - 2));
		Apple.Y = 1 + (rand() % (World.Size.Y - 2));

		if (World.buf[Apple.Y][Apple.X] == WORLD_SPACE)
		{
			World.buf[Apple.Y][Apple.X] = WORLD_APPLE;
			AppleGraphics(Apple);
			break;
		}
	}
}
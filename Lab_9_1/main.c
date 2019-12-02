#include "Header.h"


void main()
{
	srand((unsigned)time(NULL));
	setconsolesize(60, 30);
	hidecursor();

	int key, speed = 200;
	COORD current;


	current.X = 30;
	current.Y = 15;

	PaintSnow(current);

	while (1)
	{
		Sleep(50 + speed);

		if (_kbhit())
		{
			key = _getch();

			switch (key)
			{
			case SPEED_DOWN:
				if (speed <= 400)
				{
					speed += 50;
				}
				break;

			case SPEED_UP:
				if (speed > 0)
				{
					speed -= 50;
				}
				break;
			}
		}

		switch (MOVE_RANDOM)
		{
		case MOVE_UP:
			if ((current.Y - 2) < 1)
				continue;
			--current.Y;
			PaintSnow(current);
			continue;

		case MOVE_DOWN:
			if ((current.Y + 2) > 29)
				continue;
			++current.Y;
			PaintSnow(current);
			continue;

		case MOVE_LEFT:
			if ((current.X - 2) < 1)
				continue;
			--current.X;
			PaintSnow(current);
			continue;

		case MOVE_RIGHT:
			if ((current.X + 2) > 59)
				continue;
			++current.X;
			PaintSnow(current);
			continue;
		}
	}
}
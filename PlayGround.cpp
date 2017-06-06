#include "PlayGround.h"

PlayGround::PlayGround(int sizeX, int sizeY) :
	itsSizeX(sizeX),
	itsSizeY(sizeY)
{
	srand(time(NULL));
	player = Snake(sizeX / 2, sizeY / 2, rand()%4, 3);
	do
	{
		goal.newPlace(rand()%itsSizeX, rand()%itsSizeY);
	} while (player[0].X == goal.pos.X && player[0].Y == goal.pos.Y);
	matrix = new char*[itsSizeX];
	for (int x = 0; x < itsSizeX; x++)
		matrix[x] = new char[itsSizeY];
	clear();
}

PlayGround::~PlayGround()
{
	for (int x = 0; x < itsSizeX; x++)
		delete[] matrix[x];
	delete[] matrix;
}

void PlayGround::update()
{
	// 'h' - snake head
	// 's' - snake body
	// 'f' - food
	clear();
	//draw food
	matrix[goal.pos.X][goal.pos.Y] = 'f';
	//draw snake
	for (int i = 1; i < player.getSize(); i++)
		matrix[player[i].X][player[i].Y] = 's';
	matrix[player[0].X][player[0].Y] = 'h';
}

void PlayGround::step()
{
	player.move();
	if (player[0].X < 0)
		player.setHead(itsSizeX - 1, player[0].Y);
	else if (player[0].X >= itsSizeX)
		player.setHead(0, player[0].Y);
	else if (player[0].Y < 0)
		player.setHead(player[0].X, itsSizeY - 1);
	else if (player[0].Y >= itsSizeY)
		player.setHead(player[0].X, 0);

	//player[0] == coordFood->player.addBlock();
	if (player[0].X == goal.pos.X && player[0].Y == goal.pos.Y)
	{
		player.addBlock();
		bool quit = true;;
		do
		{
			quit = true;
			goal.newPlace(rand() % itsSizeX, rand() % itsSizeY);
			for (int i = 0; i < player.getSize(); i++)
			{
				if (player[i].X == goal.pos.X && player[i].Y == goal.pos.Y)
				{
					quit = false;
					break;
				}
			}
		} while (!quit);
	}

	for (int i = 1; i < player.getSize(); i++)
	{
		if (Coordinates(player[0].X, player[0].Y) == Coordinates(player[i].X, player[i].Y))
		{
			//GameOver! Tuch to tail.
			exit(0);
		}
	}
}

void PlayGround::clear()
{
	for (int x = 0; x < itsSizeX; x++)
		for (int y = 0; y < itsSizeY; y++)
			matrix[x][y] = ' ';
}
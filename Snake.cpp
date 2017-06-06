#include "Snake.h"

Snake::Snake(int startPosX, int startPosY, int startDirection, int startSize) :
	direction(startDirection),
	size(startSize),
	turn(false)
{
	chain.push_back(Coordinates(startPosX, startPosY));
	for (int i = 1; i < startSize; i++)
		switch (direction)
		{
		case 0://up
			chain.push_back(Coordinates(startPosX, startPosY-1));
			break;
		case 1://right
			chain.push_back(Coordinates(startPosX-1, startPosY));
			break;
		case 2://down
			chain.push_back(Coordinates(startPosX, startPosY+1));
			break;
		case 3://left
			chain.push_back(Coordinates(startPosX+1, startPosY));
			break;
		default:
			break;
		}
}

Snake::~Snake()
{
	chain.clear();
}

void Snake::addBlock()
{
	chain.push_back(Coordinates(chain[chain.size() - 1]));
	size++;
}

void Snake::move()
{
	for (int i = chain.size() - 1; i > 0; i--)
		chain[i] = chain[i - 1];
	switch (direction)
	{
	case 0://up
		chain[0].Y++;
		break;
	case 1://right
		chain[0].X++;
		break;
	case 2://down
		chain[0].Y--;
		break;
	case 3://left
		chain[0].X--;
		break;
	default:
		break;
	}
}

const Coordinates& Snake::operator[](int idx) const
{
	if (idx < 0)
		return chain[0];
	if (idx >= chain.size())
		return chain[chain.size() - 1];
	return chain[idx];
}

void Snake::setHead(int x, int y)
{
	chain[0] = Coordinates(x, y);
}

int Snake::getSize() const
{
	return size;
}

int Snake::getDirection() const
{
	return direction;
}

void Snake::setDirection(int dir)
{
	direction = dir;
}

bool Snake::getTurn() const
{
	return turn;
}

void Snake::setTurn(bool t)
{
	turn = t;
}
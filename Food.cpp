#include "Food.h"

Food::Food(int x, int y):
	pos(x, y)
{}

Food::~Food()
{}

void Food::newPlace(int x, int y)
{
	pos.X = x;
	pos.Y = y;
}
#pragma once
#include <vector>
#include "Coordinates.h"

class Snake
{
public:
	Snake(int startPosX = 0, int startPosY = 0, int startDirection = 0, int startSize = 3);
	~Snake();
	void addBlock();
	void move();
	const Coordinates& operator[](int) const;
	void setHead(int x, int y);
	int getSize() const;
	int getDirection() const;
	void setDirection(int);
	bool getTurn() const;
	void setTurn(bool);
private:
	std::vector<Coordinates> chain;
	int size;
	int direction;
	bool turn;
};
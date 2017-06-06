#pragma once
#include <GL\freeglut.h>
#include <ctime>
#include "Snake.h"
#include "Food.h"

class PlayGround
{
public:
	PlayGround(int, int);
	~PlayGround();
	void update();
	void step();
	friend void display();
	friend void timer(int);
	friend void keyboard(int, int, int);
private:
	void clear();
	int itsSizeX;
	int itsSizeY;
	char ** matrix;
	Snake player;
	Food goal;
};
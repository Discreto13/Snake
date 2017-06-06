#pragma once
#include "Coordinates.h"

class Food
{
public:
	Food(int = 0, int = 0);
	~Food();
	void newPlace(int, int);
	Coordinates pos;

private:
};

//Feature: "bigFood: public Food"
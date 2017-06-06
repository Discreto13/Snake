#pragma once
class Coordinates
{
public:
	Coordinates(int x, int y) : X(x), Y(y) {}
	bool operator==(Coordinates s) { if (X == s.X && Y == s.Y) return 1; else return 0; };
	int X;
	int Y;
};
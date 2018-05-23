#pragma once

#ifndef GAME_H_
#define GAME_H_

#include "LinkedList.h"



class MyPoint {
public:
	MyPoint();
	MyPoint(int x, int y);
	~MyPoint();

	inline bool operator==(MyPoint &p);

	int x;
	int y;
};


inline MyPoint::MyPoint()
{
}

inline MyPoint::MyPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}

inline MyPoint::~MyPoint()
{
}

inline bool MyPoint::operator==(MyPoint & p)
{
	if (this->x == p.x && this->y == p.y) {
		return true;
	}
	return false;
}



class Game
{

public:
	enum {
		EASY = 8,
		NORMAL = 10,
		DIFFICULT = 16,
	};

	enum direction {
		UP, DOWN, LEFT, RIGHT
	};


	int ** map;

	LinkedList<MyPoint> *path;

	MyPoint start;
	MyPoint end;


private:

	int difficulty;

	int images;

	int grade;

	int restCount;

	bool hasFound = false;
	int lines = 0;

public:
	Game();
	~Game();
	int getDifficulty();
	void setDifficulty(int d);

	void reCreateMap();

	MyPoint getTip();

	bool judge();

	void createMap();

private:

	bool DFS(MyPoint p, int direction);
};

#endif
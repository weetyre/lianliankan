#pragma once

#ifndef GAME_H_
#define GAME_H_

#include "LinkedList.h"


enum direction {
	Null, UP, DOWN, LEFT, RIGHT
};


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


	int ** map;

	LinkedList<MyPoint> *path;

	MyPoint start;
	MyPoint end;


private:

	int difficulty;

	int images;

	int grade;

	int restCount;

	bool flag = false;
	int lines = 0;

public:
	Game();
	~Game();

	void setDifficulty(int d);

	void reCreateMap();

	MyPoint getTip();

private:
	void createMap();

	void findPath();

	bool DFS(MyPoint p, int direction);
};

#endif
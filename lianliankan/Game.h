#pragma once

#ifndef GAME_H_
#define GAME_H_

#include "LinkedList.h"


enum direction {
	UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3
};

class MyVector {
public:
	MyVector();
	MyVector(int weight, int direction);
	~MyVector();

	int weight = 0;
	int dirct = 0;
};
inline MyVector::MyVector() {};
inline MyVector::MyVector(int weight, int direction) : weight(weight), dirct(direction) {}
inline MyVector::~MyVector() {}


class MyPoint {
public:
	MyPoint();
	MyPoint(int x, int y);
	~MyPoint();

	inline bool operator==(MyPoint &p);

	int x;
	int y;
};

inline MyPoint::MyPoint() {}

inline MyPoint::MyPoint(int x, int y)
{
	this->x = x;
	this->y = y;
}

inline MyPoint::~MyPoint() {}

inline bool MyPoint::operator==(MyPoint & p)
{
	return (this->x == p.x && this->y == p.y);
}


class Game
{
public:
	enum {
		EASY = 8,
		NORMAL = 10,
		DIFFICULT = 16,
	};


	int ** map = nullptr;

	LinkedList<MyPoint> *path;

	MyPoint start;
	MyPoint end;

	int restCount;
	int grade;


private:
	int **visited = nullptr;

	MyVector *dirct;

	int difficulty;

	int images;

	bool hasFound = false;

public:
	Game();
	~Game();

	int getDifficulty();
	void setDifficulty(int d);

	void initeMap();

	void resetMap();

	MyPoint getTip();

	bool judge(MyPoint start, MyPoint end);

private:

	bool DFS(MyPoint p, int direction);

	void randomMapWithSource(int * source);

	void reInitVisited();

	void reNewMap();

	void deleteMap();

	void printMap();
};

#endif
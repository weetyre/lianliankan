#pragma once
#ifndef PATH_H_
#define PATH_H_

#include "LinkedList.h"
#include <cstdlib>

#define LEFT 0
#define UP 1
#define RIGHT 2
#define Down 3

#define _IsIndex(i) ((i % d -1) > -1) && (i - d > -1) && (i % d + 1 < d) && (i + d < d * d)

//class Point {
//public:
//	Point();
//	Point(int x, int y);
//	~Point();
//
//	int x;
//	int y;
//};

struct nextPoint {
	int index;
	int direction;
};

class Path {
public:
	Path();
	Path(int *matrix, int dimension, int start, int end);
	~Path();

	Path &operator= (const Path &p);

	int operator() (int i) const;

	Path &getPath();

	Path &findPath();
	Path & findPath(int v, int direction);

public:
	int *matrix;
	int d;
	int start;
	int end;
	int lines = 0;
	//int length;

	LinkedList<int> *path;

private:
};

#endif
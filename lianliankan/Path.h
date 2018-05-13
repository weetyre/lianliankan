#pragma once
#ifndef PATH_H_
#define PATH_H_

#include "LinkedList.h"

class Point {
public:
	Point();
	Point(int x, int y);
	~Point();

	int x;
	int y;
};

class Path {
public:
	Path();
	Path(int *matrix, int dimension, int start, int end);
	~Path();

	Path &operator= (const Path &p);

	Point operator() (int i) const;

	Path &getPath();

	Path &findPath();
	Path & findPath(int v);

public:
	int *matrix;
	int dimensionOfMatrix;
	int start;
	int end;
	LinkedList<Point> *path;

private:
};

#endif
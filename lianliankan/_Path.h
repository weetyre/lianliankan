#pragma once
#ifndef _PATH_H_
#define _PATH_H_

#include "LinkedList.h"
#include "stdafx.h"

class Point {
public:
	Point();
	Point(int x, int y);
	~Point();

	int x;
	int y;
};

class _Path {
public:
	_Path();
	_Path(int *matrix, int dimension, int start, int end);
	~_Path();

	_Path &operator= (const _Path &p);

	Point operator() (int i) const;

	_Path &getPath();

	_Path &findPath();
	_Path & findPath(int v);

public:
	int *matrix;
	int dimensionOfMatrix;
	int start;
	int end;

	int length;
	LinkedList<Point> *path;

private:
};

#endif
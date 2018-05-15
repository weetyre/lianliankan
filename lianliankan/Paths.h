#pragma once
#ifndef PATHS_H_
#define PATHS_H_

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

class Paths
{
public:
	Paths();
	~Paths();
	Paths(int *matrix, int dimension, int start, int end);

	Paths &operator= (const Paths &p);

	Point operator() (int i) const;

	Paths &getPath();

	Paths &findPath();
	Paths & findPath(int v);

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
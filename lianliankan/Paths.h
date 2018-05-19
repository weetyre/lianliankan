#pragma once
#ifndef PATHS_H_
#define PATHS_H_

#include "LinkedList.h"
#include "stdafx.h"


class Paths
{
public:
	Paths();
	~Paths();
	Paths(int *matrix, int dimension, int start, int end);

	Paths &operator= (Paths &p);

	int operator() (int i) const;

	Paths &getPath();

	Paths &findPath();
	Paths & findPath(int v);

public:
	int *matrix;
	int dimensionOfMatrix;
	int start;
	int end;

	int lineCount = 0;
	int length;
	LinkedList<int> *path;

private:
};

#endif
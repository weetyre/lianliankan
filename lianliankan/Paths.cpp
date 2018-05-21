#include "stdafx.h"
#include "Paths.h"


Paths::Paths()
{
	path = new LinkedList<int>();
}

Paths::Paths(int * matrix, int dimension, int start, int end) :matrix(matrix), d(dimension),
start(start), end(end)
{
	this->matrix = new int[d * d];
	memcpy(this->matrix, matrix, d * d);

	length = 0;
	path = new LinkedList<int>();
}

Paths::~Paths()
{
	delete path;
}

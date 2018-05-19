#include "stdafx.h"
#include "Paths.h"


Paths::Paths()
{
	path = new LinkedList<int>();
}

Paths::Paths(int * matrix, int dimension, int start, int end) :matrix(matrix), dimensionOfMatrix(dimension),
start(start), end(end)
{
	length = 0;
	path = new LinkedList<int>();
}

Paths::~Paths()
{
	delete path;
}

Paths & Paths::operator=(Paths & p)
{
	this->dimensionOfMatrix = p.dimensionOfMatrix;

	return p;
}

int Paths::operator()(int i) const
{
	return path->get(i);
}
//
//Paths & Paths::getPath()
//{
//	// TODO: �ڴ˴����� return ���
//	return *this;
//}
//
//Paths & Paths::findPath()
//{
//	// TODO: �ڴ˴����� return ���
//}
//
//Paths & Paths::findPath(int v)
//{
//	// TODO: �ڴ˴����� return ���
//}

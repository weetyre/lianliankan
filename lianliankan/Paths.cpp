#include "stdafx.h"
#include "Paths.h"


Paths::Paths()
{
	path = new LinkedList<Point>();
}

Paths::Paths(int * matrix, int dimension, int start, int end) :matrix(matrix), dimensionOfMatrix(dimension),
start(start), end(end)
{
	length = 0;
	path = new LinkedList<Point>();
}

Paths::~Paths()
{
	delete path;
}

Paths & Paths::operator=(const Paths & p)
{
	// TODO: 在此处插入 return 语句

}

Point Paths::operator()(int i) const
{
	return path->get(i);
}

Paths & Paths::getPath()
{
	// TODO: 在此处插入 return 语句
	return *this;
}

Paths & Paths::findPath()
{
	// TODO: 在此处插入 return 语句
}

Paths & Paths::findPath(int v)
{
	// TODO: 在此处插入 return 语句
}

Point::Point(int x, int y) :x(x), y(y)
{

}

Point::~Point()
{
}

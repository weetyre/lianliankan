#include "Path.h"

Path::Path()
{
	path = new LinkedList<Point>();
}

Path::Path(int * matrix, int dimension, int start, int end):matrix(matrix), dimensionOfMatrix(dimension),
															start(start), end(end)
{
	path = new LinkedList<Point>();
}

Path::~Path()
{
}

Path & Path::operator=(const Path & p)
{
	// TODO: 在此处插入 return 语句
}

Point Path::operator()(int i) const
{
	return path->get(i);
}

Path & Path::getPath()
{
	// TODO: 在此处插入 return 语句
}

Path & Path::findPath()
{
	// TODO: 在此处插入 return 语句
}

Path & Path::findPath(int v)
{
	// TODO: 在此处插入 return 语句
}

Point::Point(int x, int y):x(x),y(y)
{

}

Point::~Point()
{
}

#include "Path.h"

Path::Path()
{
	path = new LinkedList<Point>();
}

Path::Path(int * matrix, int dimension, int start, int end):matrix(matrix), dimensionOfMatrix(dimension),
															start(start), end(end)
{
	length = 0;
	path = new LinkedList<Point>();
}

Path::~Path()
{
	delete path;
}

Path & Path::operator=(const Path & p)
{
	// TODO: �ڴ˴����� return ���
}

Point Path::operator()(int i) const
{
	return path->get(i);
}

Path & Path::getPath()
{
	// TODO: �ڴ˴����� return ���
}

Path & Path::findPath()
{
	// TODO: �ڴ˴����� return ���
}

Path & Path::findPath(int v, )
{
	// TODO: �ڴ˴����� return ���
}

Point::Point(int x, int y):x(x),y(y)
{

}

Point::~Point()
{
}

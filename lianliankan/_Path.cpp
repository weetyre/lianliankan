#include "Path.h"

Path::Path()
{
	path = new LinkedList<int>();
}

Path::Path(int * matrix, int dimension, int start, int end):matrix(matrix), d(dimension),
															start(start), end(end)
{
	this->matrix = new int[d];
	memcpy(this->matrix, matrix, dimension * dimension);

	//length = 0;
	path = new LinkedList<int>();
}

Path::~Path()
{
	delete[] matrix;
	delete path;
}

Path & Path::operator=(const Path & p)
{
	// TODO: 在此处插入 return 语句
}

int Path::operator()(int i) const
{
	return path->get(i);
}

Path & Path::getPath()
{
	// TODO: 在此处插入 return 语句
}

Path & Path::findPath()
{
	LinkedList<nextPoint> paths;
	paths.add(nextPoint{start,-1});
	/*for (int i = 0; i < 4; i++) {
		if(_IsIndex())
	}*/
}

Path & Path::findPath(int v, int direction)
{
	// TODO: 在此处插入 return 语句
}

//Point::Point(int x, int y):x(x),y(y)
//{
//
//}
//
//Point::~Point()
//{
//}

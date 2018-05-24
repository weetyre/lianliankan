#include "stdafx.h"
#include "Game.h"
#include "time.h"
#include <iostream>
#include <algorithm>
#include <thread>

using namespace std;

#define _IsNIndex(x,y) ((x > difficulty + 1) || (x < 0) || (y > difficulty + 1) || (y < 0))


Game::Game()
{
	path = new LinkedList<MyPoint>();
	dirct = new MyVector[4];
}


Game::~Game()
{
	deleteMap();
	delete[] dirct;
	delete path;
}

void Game::setDifficulty(int d)
{
	deleteMap();

	difficulty = EASY;

	switch (d)
	{
	case EASY:
		images = EASY;
		break;
	case NORMAL:
		images = NORMAL;
		break;
	case DIFFICULT:
		images = DIFFICULT;
		break;

	default:
		break;
	}

	reNewMap();
}
int Game::getDifficulty()
{
	return difficulty;
}

/*
 * 搜索全图，如果找到可消去的两点返回 true；否则 false
 * 如果 true，用 game.path.getFirst() and game.path.getLast() 获取两个点
 */
bool Game::getTip()
{
	for (int i = 1; i < difficulty + 1; i++) {
		for (int j = 1; j < difficulty + 1; j++) {
			for (int m = i; m < difficulty + 1; m++) {
				for (int n = j + 1; j < difficulty + 1; n++) {
					if (judge(MyPoint(j, i), MyPoint(n, m))) {
						return true;
					}
				}
			}
		}
	}
}

/*
 * 重排 Map
 */
void Game::resetMap()
{
	int *s = new int[difficulty * difficulty];
	int k = 0;
	for (int i = 1; i < difficulty + 1; i++) {
		for (int j = 1; j < difficulty + 1; j++) {
			s[k] = map[i][j];
			k++;
		}
	}

	randomMapWithSource(s);
	delete[] s;
}

//after choose the difficulty, before start the game, initial the map
void Game::initeMap()
{
	int *b = new int[difficulty * difficulty];
	int i, j;
	for (i = 0; i < difficulty * difficulty; i += images) {
		for (j = 0; j < images; j++) {
			b[i + j] = i / images + 1;
		}
	}

	randomMapWithSource(b);
	delete[] b;
}

/*
* if there is a path from vertex start to vertex end, return true and you can get the path by varOfGame.path
*/
bool Game::judge(MyPoint start, MyPoint end)
{
	//如果不同图片（对应数字不同） || 其中有空的图片（对应零）
	if (map[start.y][start.x] != map[end.y][end.x] || map[start.y][start.x] == 0 || map[end.y][end.x] == 0) {
		return false;
	}

	reInitVisited();
	this->start = start;
	this->end = end;
	hasFound = false;
	path->clear();

	sortDirection(start, end);

	path->add(start);
	//从 start 点开始，根据 方向优先队列 四个方向依次搜索路径
	for (int i = 0; i < 4; i++) {
		if (DFS(getPointByDirct(start, dirct[i].dirct), dirct[i].dirct)) {
			return true;
		}
	}

	return false;
}

/*
 * 深度优先找
 */
bool Game::DFS(MyPoint p, int direction)
{
	if (hasFound) {  //has found the path
		return true;
	}
	//the num of lines is greater than 3 or index is illegal 
	if (path->getSize() > 3 || _IsNIndex(p.x, p.y)) {
		return false;
	}
	//we find it
	if (p == end) {
		hasFound = true;
		path->add(p);
		return true;
	}
	//此处有图片
	if (visited[p.y][p.x] != 0) {
		return false;
	}
	visited[p.y][p.x] = -1;

	printMap();

	//重新构造队列
	sortDirection(p, end);

	//根据 方向优先队列 依次深搜
	for (int i = 0; i < 4; i++) {
		if (direction == dirct[i].dirct) {
			DFS(getPointByDirct(p, dirct[i].dirct), dirct[i].dirct);
			visited[p.y][p.x] = 0;

			//MyPoint t = getPointByDirct(getPointByDirct(p, dirct[i].dirct), dirct[i].dirct);
			//if (!_IsNIndex(t.x, t.y) && visited[t.y][t.x] == 0) {
			//	visited[t.y][t.x] = -1;
			//}
		}
		else {
			path->add(p);  //add 拐点 to path
			if (!DFS(getPointByDirct(p, dirct[i].dirct), dirct[i].dirct)) {
				path->removeLast();
			}
		}
		if (hasFound) {
			return true;
		}
	}

	return false;
}

/*
 * 以最适宜的 方向 构造一个优先队列
 */
void Game::sortDirection(MyPoint start, MyPoint end)
{
	dirct[0].weight = dirct[1].weight = dirct[2].weight = dirct[3].weight = 0;
	dirct[0].dirct = UP; dirct[1].dirct = DOWN; dirct[2].dirct = LEFT;  dirct[3].dirct = RIGHT;

	int dx = end.x - start.x;
	int dy = end.y - start.y;
	if (abs(dx) < abs(dy)) {
		dirct[0].weight = dirct[1].weight += 1;
	}
	else if (abs(dx) > abs(dy)) {
		dirct[2].weight = dirct[3].weight += 1;
	}
	else {
		dirct[0].weight = dirct[1].weight = dirct[2].weight = dirct[3].weight += 1;
	}

	if (dx > 0) {
		dirct[3].weight++;
		dirct[2].weight -= 2;
	}
	else {
		dirct[2].weight++;
		dirct[3].weight -= 2;
	}
	if (dy > 0) {
		dirct[1].weight++;
		dirct[0].weight -= 2;
	}
	else {
		dirct[0].weight++;
		dirct[1].weight -= 2;
	}

	for (int i = 1; i < 4; i++) {
		MyVector key;
		key = dirct[i];

		int j = i - 1;
		for (; j >= 0 && key.weight > dirct[j].weight; j--) {
			dirct[j + 1] = dirct[j];
		}
		dirct[j + 1] = key;
	}
}

/*
 * get a point around p by a direction
 */
MyPoint Game::getPointByDirct(MyPoint p, int d)
{
	switch (d) {
	case 0:
		return MyPoint(p.x, p.y - 1);
		break;
	case 1:
		return MyPoint(p.x, p.y + 1);
		break;
	case 2:
		return MyPoint(p.x - 1, p.y);
		break;
	case 3:
		return MyPoint(p.x + 1, p.y);
		break;
	default:
		return MyPoint();
		break;
	}
}

/*
 * 重新排列并随机化 source 数组并 copy 到 map
 */
void Game::randomMapWithSource(int * source)
{
	//random_shuffle()用来对一个元素序列进行重新排序（随机的）andom_shuffle()有两个参数，第一个参数是指向序列首元素的迭代器，第二个参数则指向序列最后一个元素的下一个位置
	srand((unsigned)time(NULL));
	std::random_shuffle(source, source + difficulty * difficulty);

	int k = 0, i, j;
	//initial map = {0}
	for (i = 0; i < difficulty + 2; i++) {
		for (j = 0; j < difficulty + 2; j++) {
			map[i][j] = 0;

		}
	}
	//map[1 to difficulty+1][1 to difficulty+1] = source[0 to difficulty][0 to difficulty]
	for (i = 1; i < difficulty + 1; i++) {
		for (j = 1; j < difficulty + 1; j++) {
			map[i][j] = source[k];
			k++;
		}
	}
}

/*
 * 重新初始化 visited 数组
 */
void Game::reInitVisited()
{
	for (int i = 0; i < difficulty + 2; i++) {
		for (int j = 0; j < difficulty + 2; j++) {
			visited[i][j] = map[i][j];
		}
	}
}

/*
 * 重新创建 map
 */
void Game::reNewMap()
{
	map = new int*[difficulty + 2];
	for (int i = 0; i < difficulty + 2; i++) {
		map[i] = new int[(difficulty + 2)];
	}
	visited = new int*[difficulty + 2];
	for (int i = 0; i < difficulty + 2; i++) {
		visited[i] = new int[(difficulty + 2)];
	}
}

void Game::deleteMap()
{
	if (map != nullptr) {
		for (int i = 0; i < difficulty + 2; i++) {
			delete[] map[i];
		}
	}
	if (visited != nullptr) {
		for (int i = 0; i < difficulty + 2; i++) {
			delete[] visited[i];
		}
	}
}

void Game::printMap()
{
	for (int i = 0; i < difficulty + 2; i++) {
		for (int j = 0; j < difficulty + 2; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

#include "stdafx.h"
#include "Game.h"
#include "time.h"
#include <iostream>
#include <algorithm>

using namespace std;

#define _IsNIndex(x,y) (x > difficulty + 1) || (x < 0) || (y > difficulty + 1) || (y < 0)


Game::Game()
{
	path = new LinkedList<MyPoint>();
}


Game::~Game()
{
	for (int i = 0; i < difficulty + 2; i++) {
		delete[] map[i];
	}
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
	reInitMap();
}
int Game::getDifficulty()
{
	return difficulty;
}

void Game::reCreateMap()
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

MyPoint Game::getTip()
{
	return MyPoint();
}

//after choose the difficulty, before start the game, create the map
void Game::createMap()
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

	this->start = start;
	this->end = end;
	hasFound = false;
	path->clear();
	reInitVisited();

	path->add(start);
	//从 start 点开始，上下左右四个方向依次搜索路径
	if (DFS(MyPoint(start.x, start.y - 1), UP)) {
		return true;
	}
	else if (DFS(MyPoint(start.x, start.y + 1), DOWN)) {
		return true;
	}
	else if (DFS(MyPoint(start.x - 1, start.y), LEFT)) {
		return true;
	}
	else if (DFS(MyPoint(start.x + 1, start.y), RIGHT)) {
		return true;
	}
	else {
		return false;
	}
}

bool Game::DFS(MyPoint p, int direction)
{
	printMap();

	if (hasFound) {  //has found the path
		return true;
	}
	//the num of lines is greater than 3 or is not a legal index
	if (path->getSize() > 3 || _IsNIndex(p.x, p.y)) {
		return false;
	}
	//we find it
	if (p == end) {
		hasFound = true;
		path->add(p);
		return true;
	}

	if (visited[p.y][p.x] != 0) {
		return false;
	}
	visited[p.y][p.x] = -1;

	//search up
	if (direction == UP) {
		DFS(MyPoint(p.x, p.y - 1), UP);
		visited[p.y][p.x] = 0;
	}
	else {
		path->add(p);  //add 拐点 to path
		if (!DFS(MyPoint(p.x, p.y - 1), UP)) {
			path->removeLast();
		}
	}
	if (hasFound) {
		return true;
	}

	//search left
	if (direction == LEFT) {
		DFS(MyPoint(p.x - 1, p.y), LEFT);
		visited[p.y][p.x] = 0;
	}
	else {
		path->add(p);
		if (!DFS(MyPoint(p.x - 1, p.y), LEFT)) {
			path->removeLast();
		}
	}
	if (hasFound) {
		return true;
	}

	//search down
	if (direction == DOWN) {
		DFS(MyPoint(p.x, p.y + 1), DOWN);
		visited[p.y][p.x] = 0;
	}
	else {
		path->add(p);
		if (!DFS(MyPoint(p.x, p.y + 1), DOWN)) {
			path->removeLast();
		}
	}
	if (hasFound) {
		return true;
	}

	//search RIGHT
	if (direction == RIGHT) {
		DFS(MyPoint(p.x + 1, p.y), RIGHT);
		visited[p.y][p.x] = 0;
	}
	else {
		path->add(p);
		if (!DFS(MyPoint(p.x + 1, p.y), RIGHT)) {
			path->removeLast();
		}
	}
	if (hasFound) {
		return true;
	}

	return false;
}

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
	// copy array source to map
	for (i = 1; i <= difficulty; i++) {
		for (j = 1; j <= difficulty; j++) {
			map[i][j] = source[k];
			k++;
		}
	}
}

void Game::reInitVisited()
{
	for (int i = 0; i < difficulty + 2; i++) {
		for (int j = 0; j < difficulty + 2; j++) {
			visited[i][j] = map[i][j];
		}
	}
}

void Game::reInitMap()
{
	map = new int*[difficulty + 2];
	for (int i = 0; i < difficulty + 2; i++) {
		map[i] = new int[(difficulty + 2)];
	}
	visited = new int*[difficulty + 2];
	for (int i = 0; i < difficulty + 2; i++) {
		visited[i] = new int[(difficulty + 2)];
		memcpy(visited[i], map[i], difficulty + 2);
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
	//for (int i = 0; i < difficulty + 2; i++) {
	//	for (int j = 0; j < difficulty + 2; j++) {
	//		cout << map[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	cout << endl;
	cout << "visited" << endl;
	for (int i = 0; i < difficulty + 2; i++) {
		for (int j = 0; j < difficulty + 2; j++) {
			cout << visited[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

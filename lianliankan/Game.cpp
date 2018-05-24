﻿#include "stdafx.h"
#include "Game.h"
#include "time.h"
#include <iostream>
#include <algorithm>

using namespace std;

#define _IsNIndex(x,y) (x > difficulty + 1) || (x < 0) || (y > difficulty + 1) || (y < 0)


Game::Game()
{
	//new a 2D array, map[difficulty + 2][difficulty + 2]( image is at map[1 to difficulty][1 to difficulty] )
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
	map = new int*[difficulty+2];
	for (int i = 0; i < difficulty + 2; i++) {
		map[i] = new int[(difficulty + 2)];
	}
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
	if (map[start.x][start.y] != map[end.x][end.y] || map[start.x][start.y] == 0 || map[end.x][end.y] == 0) {
		return false;
	}

	this->start = start;
	this->end = end;
	hasFound = false;
	path->clear();

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
}

void Game::randomMapWithSource(int * source)
{
	//random_shuffle()用来对一个元素序列进行重新排序（随机的）andom_shuffle()有两个参数，第一个参数是指向序列首元素的迭代器，第二个参数则指向序列最后一个元素的下一个位置
	srand((unsigned)time(NULL));
	std::random_shuffle(source, source + difficulty * difficulty);

	int k = 0, i, j;
	for (int i = 0; i < difficulty + 2; i++)
	{
		memset(map[i], 0, difficulty + 2);
	}

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
		memcpy(visited[i], map[i], difficulty + 2);
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
	for (int i = 0; i < difficulty + 2; i++) {
		for (int j = 0; j < difficulty + 2; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

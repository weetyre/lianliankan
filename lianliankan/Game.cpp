#include "stdafx.h"
#include "Game.h"
#include "time.h"
#include <iostream>
#include <algorithm>

using namespace std;

#define _IsNIndex(x,y) (x > difficulty + 1) || (x < 0) || (y > difficulty + 1) || (y < 0)


Game::Game()
{

}


Game::~Game()
{
	for (int i = 0; i < difficulty; i++) {
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
}
int Game::getDifficulty()
{
	return difficulty;
}

//after choose the difficulty, before start the game, create the map
void Game::createMap()
{
	int i, j;
	//new a 2D array, map[difficulty + 2][difficulty + 2]( image is at map[1 to difficulty][1 to difficulty] )
	for (i = 0; i < difficulty + 2; i++) {
		map[i] = new int[(difficulty + 2)];
	}

	int *b = new int[difficulty * difficulty];
	for (i = 0; i < difficulty * difficulty; i += images) {
		for (j = 0; j < images; j++) {
			b[i + j] = i / images + 1;
		}
	}

	//random_shuffle()用来对一个元素序列进行重新排序（随机的）
	srand((unsigned)time(NULL));
	std::random_shuffle(b, b + difficulty * difficulty);

	int k = 0;
	memset(map, 0, sizeof(map));
	for (i = 1; i <= difficulty; i++) {
		for (j = 1; j <= difficulty; j++) {
			map[i][j] = b[k];
			k++;
		}
	}

	delete[] b;
}

bool Game::findPath()
{
	if (map[start.x][start.y] != map[end.x][end.y] || map[start.x][start.y] == 0 || map[end.x][end.y] == 0) {
		return false;
	}

	lines = 0;
	hasFound = false;
	path->clear();

	path->add(start);

	for (int i = 0; i < 4; i++) {
		if (DFS(MyPoint(start.x, start.y - 1), i)) {
			return true;
		}
	}

	//return DFS(MyPoint(start.x, start.y - 1), UP);
}

bool Game::DFS(MyPoint p, int direction)
{
	path->add(p);
	if (hasFound) {  //has found the path
		return true;
	}
	//the num of lines is greater than 3 or is not a legal index
	if (lines > 3 || _IsNIndex(p.x, p.y)) {
		return false;
	}
	//we find it
	if (p == end && lines < 4) {
		hasFound = true;
		return true;
	}
	if (map[p.x][p.y] != 0) {
		return false;
	}

	//search up
	if (direction == UP) {
		if (!DFS(MyPoint(p.x, p.y - 1), UP)) {
			path->removeLast();
		}
	}
	else {
		lines++;
		if (!DFS(MyPoint(p.x, p.y - 1), UP)) {
			path->removeLast();
		}
		lines--;
	}
	if (hasFound) {
		return true;
	}

	//search left
	if (direction == LEFT) {
		if (!DFS(MyPoint(p.x - 1, p.y), LEFT)) {
			path->removeLast();
		}
	}
	else {
		lines++;
		if (!DFS(MyPoint(p.x - 1, p.y), LEFT)) {
			path->removeLast();
		}
		lines--;
	}
	if (hasFound) {
		return true;
	}

	//search down
	if (direction == DOWN) {
		if (!DFS(MyPoint(p.x, p.y + 1), DOWN)) {
			path->removeLast();
		}
	}
	else {
		lines++;
		if (!DFS(MyPoint(p.x, p.y + 1), DOWN)) {
			path->removeLast();
		}
		lines--;
	}
	if (hasFound) {
		return true;
	}

	//search RIGHT
	if (direction == RIGHT) {
		if (!DFS(MyPoint(p.x + 1, p.y), RIGHT)) {
			path->removeLast();
		}
	}
	else {
		lines++;
		if (!DFS(MyPoint(p.x + 1, p.y), RIGHT)) {
			path->removeLast();
		}
		lines--;
	}
	if (hasFound) {
		return true;
	}
}

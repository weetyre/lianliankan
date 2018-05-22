#pragma once
#ifndef USER_H_
#define USER_H_

#include <string>
#include "LinkedList.h"

using namespace std;

class User
{
public:
	User();
	User(string n);
	~User();

	string recordAt(int i);

private:
	string name;

	LinkedList<string> records;


};

#endif
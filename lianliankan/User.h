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
	User(long id, string n);
	~User();

	string recordAt(int i);

private:
	string name;

	long id;

	static long idCount;

	LinkedList<string> records;

public:

	string setName(string n);

	void addRecord(string record);

	static long setIdCount(long c);

	static User createUser(string name);
};

#endif
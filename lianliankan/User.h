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
	User(string name, string password);
	User(long id, string password);
	User(long id, string password, string name);
	~User();

	string recordAt(int i);

private:
	string name;
	string password;
	long id;

	static long idCount;

	LinkedList<string> records;

public:

	string setName(string n);

	string setPassword(string p);

	void addRecord(string record);

	static long setIdCount(long c);

	static User createUser(string name);
};

#endif
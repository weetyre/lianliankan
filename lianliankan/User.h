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
	User(int id, string password);
	User(int id, string password, string name);
	~User();

	string recordAt(int i);

private:
	string name;
	string password;
	int id;

	static int idCount;

	LinkedList<string> records;

public:

	int getId();

	string getName();

	string setName(string n);

	string setPassword(string p);

	int setId(int i);

	void addRecord(string record);

	static int setIdCount(int c);

	static User createUser(string name, string p);
};

#endif
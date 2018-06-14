#pragma once
#ifndef USER_H_
#define USER_H_

#include <string>
#include "LinkedList.h"

using namespace std;

class Record {
public:
	Record();
	Record(string s, int score, string mode_);
	~Record();


	string info;
	int score;
	string mode_;
	int getScore();
	bool isLargerThan(Record r);
	string toString();
};

class User
{
public:
	User();
	User(string name, string password);
	User(int id, string password);
	User(int id, string password, string name);
	~User();

	Record recordAt(int i);

private:
	string name;
	string password;
	int id;

	static int idCount;

	LinkedList<Record> records;

public:

	int getId();

	string getName();

	string setName(string n);

	string setPassword(string p);

	int setId(int i);
	int getRecordLength();
	void addRecord(Record record);

	static int setIdCount(int c);

	static User createUser(string name, string p);
};

#endif
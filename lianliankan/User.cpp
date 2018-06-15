#include "stdafx.h"
#include "User.h"
#include <stdlib.h>

int User::idCount = 0;

User::User()
{
}

User::User(string name, string password):name(name), password(password)
{
}

User::User(int id, string password): password(password),id(id)
{

}

User::User(int id, string password, string name):name(name), password(password), id(id)
{
}

User::~User()
{
}

Record User::recordAt(int i)
{
	return records.get(i);
}

int User::getId()
{
	return id;
}

string User::getName()
{
	return name;
}

string User::setName(string n)
{
	return name = n;
}

string User::setPassword(string p)
{
	return password = p;
}

int User::setId(int i)
{
	return id = i;
}

int User::getRecordLength()
{
	return records.getSize();
}

void User::addRecord(Record record)
{
	records.add(record);
}

int User::setIdCount(int c)
{
	return idCount = c;
}

User User::createUser(string name, string p)
{
	return User(idCount++, p, name);
}

Record::Record()
{
}

Record::Record(string s, int score, string mode_):info(s), score(score),mode_(mode_)
{
}

Record::~Record()
{
}

int Record::getScore()
{
	return score;
}

string Record::getMode()
{
	return mode_;
}

string Record::getInfo()
{
	return info;
}

bool Record::isLargerThan(Record r)
{
	return this->score > r.score;
}

string Record::toString()
{
	char s[10];
	return info + string(itoa(score, s, 10));
}

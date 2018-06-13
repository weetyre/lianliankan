#include "stdafx.h"
#include "User.h"


User::User()
{

}

User::User(long id, string n):name(n),id(id)
{

}


User::~User()
{
}

string User::recordAt(int i)
{
	return records.get(i);
}

string User::setName(string n)
{
	return name = n;
}

void User::addRecord(string record)
{
	records.add(record);
}

long User::setIdCount(long c)
{
	return idCount = c;
}

User User::createUser(string name)
{
	return User(idCount++, name);
}

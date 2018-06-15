#include "stdafx.h"
#include "User.h"

long User::idCount = 0;
User::User()
{
}

User::User(string name, string password):name(name), password(password)
{
}

User::User(long id, string password): password(password),id(id)
{

}

User::User(long id, string password, string name):name(name), password(password), id(id)
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

string User::setPassword(string p)
{
	return password = p;
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

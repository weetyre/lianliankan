#include "stdafx.h"
#include "User.h"

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

string User::recordAt(int i)
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

void User::addRecord(string record)
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

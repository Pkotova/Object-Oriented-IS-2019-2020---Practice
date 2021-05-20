#include "User.h"

void User::copy(const User& other)
{
	setName(other.name);
	setPassword(other.password);
	this->isAdmin = other.isAdmin;
}

void User::destroy()
{
	delete[]this->name;
	delete[]this->password;
}

User::User() 
{
	setName("user");
	setPassword("admin");
	this->isAdmin = 0;
}

User::User(const User& other)
{
	copy(other);
}

User& User::operator=(const User& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

User::~User()
{
	destroy();
}

void User::setName(const char* newname)
{
	if (newname != nullptr)
	{
		this->name = new char[strlen(newname) + 1];
		strcpy_s(this->name, strlen(newname) + 1, newname);
	}
}

void User::setPassword(const char* password)
{
	if (password != nullptr)
	{
		this->password = new char[strlen(password) + 1];
		strcpy_s(this->password, strlen(password) + 1, password);
	}
}

const char* User::getName() const
{
	return this->name;
}

const char* User::getPassword() const
{
	return this->password;
}

bool User::getIsAdmin() const
{
	return this->isAdmin;
}

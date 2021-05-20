#pragma once
#include<iostream>
class User
{
private:
	char* name;
	char* password;
	bool isAdmin;
	void copy(const User& other);
	void destroy();
public:
	User();
	User(const User& other);
	User& operator=(const User& other);
	~User();
	void setName(const char* newname);
	void setPassword(const char* password);
	const char* getName()const;
	const char* getPassword()const;
	bool getIsAdmin() const;
};


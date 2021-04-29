#pragma once
#include "User.h"
#include "LinkedList.cpp"

class UsersRepository
{
private:
	char filePath[50];
	int GetNextId();
public:
	UsersRepository(char filePath[50]);
	~UsersRepository();

	void Add(User* user);
	void Update(User* user);
	void Delete(User* user);
	User* GetById(int id);
	LinkedList<User>* GetAll();
	User* GetByUsernameAndPassword(char username[20], char password[20]);
};


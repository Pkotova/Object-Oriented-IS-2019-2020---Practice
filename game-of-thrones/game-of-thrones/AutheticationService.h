#pragma once
#include"User.h"
class AutheticationService
{
private:
	static User* loggedUser;
public:
	static User* getLoggedUser();
	static void Authenticate(const char* name, const char* password);
};


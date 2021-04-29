#pragma once
#include "User.h"

class AuthenticationService
{
private:
	static User* loggedUser;

	AuthenticationService();
public:
	static User* getLoggedUser();
	static void Authenticate(char username[20], char password[20]);
	
	~AuthenticationService();
};


#include "stdafx.h"

#include "User.h"
#include "UsersRepository.h"
#include "AuthenticationService.h"

User* AuthenticationService::loggedUser = NULL;

AuthenticationService::AuthenticationService()
{

}

User * AuthenticationService::getLoggedUser()
{
	return AuthenticationService::loggedUser;
}

void AuthenticationService::Authenticate(char username[20], char password[20])
{
	UsersRepository* repo = new UsersRepository("users.txt");
	User* user = repo->GetByUsernameAndPassword(username, password);

	AuthenticationService::loggedUser = user;
}

AuthenticationService::~AuthenticationService()
{
}

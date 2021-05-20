#include "AutheticationService.h"

User* AutheticationService::loggedUser = nullptr;

User* AutheticationService::getLoggedUser()
{
	return AutheticationService::loggedUser;
}

void AutheticationService::Authenticate(const char* name, const char* password)
{
	//UserRepository ur;
	//User * user = ur->getByUserNameAndPassword(name,password);
    User* user = new User(); // name = user, password = user;
	AutheticationService::loggedUser = user;
}

#include "stdafx.h"
#include "iostream"
#include "User.h"
#include "UsersRepository.h"
#include "LoginView.h"
#include "ContactManagementView.h"
#include "AuthenticationService.h"
#include "AdministrationView.h"

using namespace std;

int main()
{
	LoginView loginView;
	loginView.Run();

	if (AuthenticationService::getLoggedUser() != NULL &&
		AuthenticationService::getLoggedUser()->getIsAdmin() == 1)
	{
		AdministrationView adminView;
		adminView.Run();
	}
	else
	{
		ContactManagementView clientView;
		clientView.Run();
	}

	return 0;
}


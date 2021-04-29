#include "stdafx.h"
#include "iostream"

#include "LoginView.h"
#include "AuthenticationService.h"

using namespace std;

LoginView::LoginView()
{
}

LoginView::~LoginView()
{
}

void LoginView::Run()
{
	while (true)
	{
		system("cls");

		char username[20];
		cout << "Username: ";
		cin.getline(username, 20);

		char password[20];
		cout << "Password: ";
		cin.getline(password, 20);

		AuthenticationService::Authenticate(username, password);

		if (AuthenticationService::getLoggedUser() != NULL)
			break;
	}
}

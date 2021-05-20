#include "LoginView.h"
#include<iostream>
void LoginView::run()
{
	char* username = new char[32];
	std::cout << "Username:";
	std::cin.get();
	std::cin.getline(username, 32);

	char* password = new char[32];
	std::cout << "Password:";
	std::cin.getline(password, 32);
	system("cls");
	AutheticationService::Authenticate(username, password);
	if (AutheticationService::getLoggedUser() != nullptr)
		return;

	delete[] username;
	delete[] password;
}

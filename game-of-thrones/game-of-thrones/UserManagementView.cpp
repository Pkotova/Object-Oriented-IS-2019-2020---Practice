#include "UserManagementView.h"
#include "HouseRepository.h"
#include<iostream>
void UserManagementView::run()
{
	std::cout << "----------------" << std::endl;
	std::cout << "	WELCOME" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "Make a choice:" << std::endl;
	std::cout << "1. Create your own house! " << std::endl;
	std::cout << "2. Play the GAME OF THRONES! " << std::endl;
	std::cout << "3. Exit! " << std::endl;
	int k;
	std::cout << ">> ";
	std::cin >> k;
	switch (k)
	{
	case 1: createHouse(); break;
	//case 2: play(); break;
	case 3: quit(); break;
	default: std::cout << " SORRY UNCAUGHT MISTAKE! " << std::endl;
		break;
	}
}

void UserManagementView::createHouse()
{
	HouseRepository hr; //filepath=houses.txt
	House newHouse;
	char* buffer = new char[32];

	std::cout << "Name: ";
	std::cin.get();
	std::cin.getline(buffer, 32);
	newHouse.setName(buffer);

	std::cout << "Location: ";
	std::cin.getline(buffer, 32);
	newHouse.setLocation(buffer);

	std::cout << "House words: ";
	std::cin.getline(buffer, 32);
	newHouse.setHouseWords(buffer);

	hr.add(newHouse);

	delete[] buffer;
}

void UserManagementView::quit()
{
	system("cls");
	std::cout << "THANK YOU! BBYE" << std::endl;
	exit(1);
}

#include "stdafx.h"
#include "UserManagementView.h"
#include "UsersRepository.h"
#include "User.h"
#include "Enumerators.h"
#include "iostream"

using namespace std;

UserManagementView::UserManagementView()
{
}

UserManagementView::~UserManagementView()
{
}

CRUDMenuItems UserManagementView::RenderMenu()
{
	while (true)
	{
		cout << "User Management" << endl
			<< "[A]dd" << endl
			<< "[L]ist" << endl
			<< "[E]dit" << endl
			<< "[D]elete" << endl
			<< "E[x]it" << endl
			<< ">";

		char choice[2];
		cin.getline(choice, 2);

		switch (toupper(choice[0]))
		{
			case 'A':
			{
				return CRUDMenuItems::Add;
			}
			case 'L':
			{
				return CRUDMenuItems::List;
			}
			case 'E':
			{
				return CRUDMenuItems::Edit;
			}
			case 'D':
			{
				return CRUDMenuItems::Delete;
			}
			case 'X':
			{
				return CRUDMenuItems::Exit;
			}
		}
	}
}

void UserManagementView::Add()
{
	system("cls");

	User* user = new User();
	char buffer[20];

	cout << "Add User" << endl;
	
	cout << "Username: ";
	cin.getline(buffer, 20);
	user->setUsername(buffer);

	cout << "Password: ";
	cin.getline(buffer, 20);
	user->setPassword(buffer);

	cout << "First Name: ";
	cin.getline(buffer, 20);
	user->setFirstName(buffer);

	cout << "Last Name: ";
	cin.getline(buffer, 20);
	user->setLastName(buffer);

	cout << "Is Admin: ";
	cin.getline(buffer, 20);
	user->setIsAdmin(atoi(buffer));

	UsersRepository* repo = new UsersRepository("users.txt");
	repo->Add(user);

	delete repo;

	system("pause");
}

void UserManagementView::List()
{
	system("cls");

	UsersRepository* repo = new UsersRepository("users.txt");
	LinkedList<User>* items = repo->GetAll();

	cout << "List Users" << endl;
	for (int i = 0; i < items->Count(); i++)
	{
		cout << "###################" << endl
			<< "Id: " << items->getItemAt(i)->getId() << endl
			<< "Username: " << items->getItemAt(i)->getUsername() << endl
			<< "First Name: " << items->getItemAt(i)->getFirstName() << endl
			<< "Last Name: " << items->getItemAt(i)->getLastName() << endl
			<< "Is Admin: " << items->getItemAt(i)->getIsAdmin() << endl;
	}

	delete items;
	delete repo;

	system("pause");
}

void UserManagementView::Edit()
{
	system("cls");

	char buffer[20];
	cout << "Editing User" << endl;
	cout << "Id: ";
	cin.getline(buffer, 20);
	int id = atoi(buffer);

	UsersRepository* repo = new UsersRepository("users.txt");
	User* user = repo->GetById(id);
	
	system("cls");

	cout << "Username (" << user->getUsername() << "): ";
	cin.getline(buffer, 20);
	user->setUsername(buffer);

	cout << "Password (" << user->getPassword() << "): ";
	cin.getline(buffer, 20);
	user->setPassword(buffer);

	cout << "First Name (" << user->getFirstName() << "): ";
	cin.getline(buffer, 20);
	user->setFirstName(buffer);

	cout << "Last Name (" << user->getLastName() << "): ";
	cin.getline(buffer, 20);
	user->setLastName(buffer);

	cout << "Is Admin (" << user->getIsAdmin() << "): ";
	cin.getline(buffer, 20);
	user->setIsAdmin(atoi(buffer));

	repo->Update(user);

	delete user;
	delete repo;

	system("pause");
}

void UserManagementView::Delete()
{
	system("cls");

	char buffer[20];
	cout << "Deleting User" << endl;
	cout << "Id: ";
	cin.getline(buffer, 20);
	int id = atoi(buffer);

	UsersRepository* repo = new UsersRepository("users.txt");
	User* user = repo->GetById(id);

	system("cls");
	repo->Delete(user);

	cout << "Item deleted." << endl;
	
	delete user;
	delete repo;

	system("pause");
}

void UserManagementView::Run()
{
	while (true)
	{
		system("cls");
		CRUDMenuItems choice = RenderMenu();

		switch (choice)
		{
			case CRUDMenuItems::List:
			{
				List();
				break;
			}
			case CRUDMenuItems::Add:
			{
				Add();
				break;
			}
			case CRUDMenuItems::Edit:
			{
				Edit();
				break;
			}
			case CRUDMenuItems::Delete:
			{
				Delete();
				break;
			}
			case CRUDMenuItems::Exit:
			{
				return;
			}
			default:
			{
				cout << "Invalid choice";
				continue;
			}
		}
	}
}
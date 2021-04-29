#include "stdafx.h"
#include "AuthenticationService.h"
#include "ContactManagementView.h"
#include "PhoneManagementView.h"
#include "ContactsRepository.h"
#include "User.h"
#include "Enumerators.h"
#include "iostream"

using namespace std;

ContactManagementView::ContactManagementView()
{
}

ContactManagementView::~ContactManagementView()
{
}

CRUDMenuItems ContactManagementView::RenderMenu()
{
	while (true)
	{
		cout << "Contact Management" << endl
			<< "[A]dd" << endl
			<< "[L]ist" << endl
			<< "[V]iew" << endl
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
		case 'V':
		{
			return CRUDMenuItems::CustomMenuItem1;
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

void ContactManagementView::Add()
{
	system("cls");

	Contact* item = new Contact();
	char buffer[20];

	cout << "Add Contact" << endl;

	item->setUserId(AuthenticationService::getLoggedUser()->getId());

	cout << "First Name: ";
	cin.getline(buffer, 20);
	item->setFirstName(buffer);

	cout << "Last Name: ";
	cin.getline(buffer, 20);
	item->setLastName(buffer);

	ContactsRepository* repo = new ContactsRepository("contacts.txt");
	repo->Add(item);

	delete repo;

	system("pause");
}

void ContactManagementView::List()
{
	system("cls");

	ContactsRepository* repo = new ContactsRepository("contacts.txt");
	LinkedList<Contact>* items = repo->GetAll(AuthenticationService::getLoggedUser()->getId());

	cout << "List Contacts" << endl;
	for (int i = 0; i < items->Count(); i++)
	{
		cout << "###################" << endl
			<< "Id: " << items->getItemAt(i)->getId() << endl
			<< "User Id: " << items->getItemAt(i)->getUserId() << endl
			<< "First Name: " << items->getItemAt(i)->getFirstName() << endl
			<< "Last Name: " << items->getItemAt(i)->getLastName() << endl;
	}

	delete items;
	delete repo;

	system("pause");
}

void ContactManagementView::View()
{
	system("cls");

	char buffer[20];
	cout << "Editing Contact" << endl;
	cout << "Id: ";
	cin.getline(buffer, 20);
	int id = atoi(buffer);

	ContactsRepository* repo = new ContactsRepository("contacts.txt");
	Contact* item = repo->GetById(id);

	system("cls");

	PhoneManagementView view(item);
	view.Run();

	delete repo;
	delete item;
}

void ContactManagementView::Edit()
{
	system("cls");

	char buffer[20];
	cout << "Editing Contact" << endl;
	cout << "Id: ";
	cin.getline(buffer, 20);
	int id = atoi(buffer);

	ContactsRepository* repo = new ContactsRepository("contacts.txt");
	Contact* item = repo->GetById(id);

	system("cls");

	cout << "First Name (" << item->getFirstName() << "): ";
	cin.getline(buffer, 20);
	item->setFirstName(buffer);

	cout << "Last Name (" << item->getLastName() << "): ";
	cin.getline(buffer, 20);
	item->setLastName(buffer);

	repo->Update(item);

	delete item;
	delete repo;

	system("pause");
}

void ContactManagementView::Delete()
{
	system("cls");

	char buffer[20];
	cout << "Deleting Contact" << endl;
	cout << "Id: ";
	cin.getline(buffer, 20);
	int id = atoi(buffer);

	ContactsRepository* repo = new ContactsRepository("contacts.txt");
	Contact* item = repo->GetById(id);

	system("cls");
	repo->Delete(item);

	cout << "Item deleted." << endl;

	delete item;
	delete repo;

	system("pause");
}

void ContactManagementView::Run()
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
		case CRUDMenuItems::CustomMenuItem1:
		{
			View();
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
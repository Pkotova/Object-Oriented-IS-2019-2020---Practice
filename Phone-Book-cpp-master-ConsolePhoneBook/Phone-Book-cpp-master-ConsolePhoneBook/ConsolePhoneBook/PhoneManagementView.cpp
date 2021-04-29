#include "stdafx.h"
#include "AuthenticationService.h"
#include "PhoneManagementView.h"
#include "PhonesRepository.h"
#include "User.h"
#include "Enumerators.h"
#include "iostream"

using namespace std;

PhoneManagementView::PhoneManagementView(Contact* parentContact)
{
	this->parentContact = parentContact;
}

PhoneManagementView::~PhoneManagementView()
{
}

CRUDMenuItems PhoneManagementView::RenderMenu()
{
	while (true)
	{
		cout << "Contact Info" << endl
			<< "First Name: " << this->parentContact->getFirstName() << endl
			<< "Last Name: " << this->parentContact->getLastName() << endl;

		cout << "Phone Management" << endl
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

void PhoneManagementView::Add()
{
	system("cls");

	Phone* item = new Phone();
	char buffer[20];

	cout << "Add Phone" << endl;

	item->setContactId(this->parentContact->getId());

	cout << "Phone number: ";
	cin.getline(buffer, 20);
	item->setPhoneNumber(buffer);

	PhonesRepository* repo = new PhonesRepository("phones.txt");
	repo->Add(item);

	delete repo;

	system("pause");
}

void PhoneManagementView::List()
{
	system("cls");

	PhonesRepository* repo = new PhonesRepository("phones.txt");
	LinkedList<Phone>* items = repo->GetAll(this->parentContact->getId());

	cout << "List Phones" << endl;
	for (int i = 0; i < items->Count(); i++)
	{
		cout << "###################" << endl
			<< "Id: " << items->getItemAt(i)->getId() << endl
			<< "Contact Id: " << items->getItemAt(i)->getContactId() << endl
			<< "Phone number: " << items->getItemAt(i)->getPhoneNumber() << endl;
	}

	delete items;
	delete repo;

	system("pause");
}

void PhoneManagementView::Edit()
{
	system("cls");

	char buffer[20];
	cout << "Editing Phone" << endl;
	cout << "Id: ";
	cin.getline(buffer, 20);
	int id = atoi(buffer);

	PhonesRepository* repo = new PhonesRepository("phones.txt");
	Phone* item = repo->GetById(id);

	system("cls");

	cout << "Phone number (" << item->getPhoneNumber() << "): ";
	cin.getline(buffer, 20);
	item->setPhoneNumber(buffer);

	repo->Update(item);

	delete item;
	delete repo;

	system("pause");
}

void PhoneManagementView::Delete()
{
	system("cls");

	char buffer[20];
	cout << "Deleting Phone" << endl;
	cout << "Id: ";
	cin.getline(buffer, 20);
	int id = atoi(buffer);

	PhonesRepository* repo = new PhonesRepository("phones.txt");
	Phone* item = repo->GetById(id);

	system("cls");
	repo->Delete(item);

	cout << "Item deleted." << endl;

	delete item;
	delete repo;

	system("pause");
}

void PhoneManagementView::Run()
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
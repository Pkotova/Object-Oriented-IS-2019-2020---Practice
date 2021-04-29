#include "stdafx.h"
#include "string.h"
#include "fstream"

#include "ContactsRepository.h"

using namespace std;

int ContactsRepository::GetNextId()
{
	int nextId = 0;

	ifstream in(this->filePath);

	Contact* result = NULL;
	Contact* contact = new Contact();
	char buffer[20];

	while (!in.eof())
	{
		in.getline(buffer, 20);
		contact->setId(atoi(buffer));

		in.getline(buffer, 20);
		contact->setUserId(atoi(buffer));

		in.getline(buffer, 20);
		contact->setFirstName(buffer);

		in.getline(buffer, 20);
		contact->setLastName(buffer);

		if (contact->getId() > nextId)
			nextId = contact->getId();
	}

	in.close();

	return nextId + 1;
}

ContactsRepository::ContactsRepository(char filePath[50])
{
	strcpy_s(this->filePath, 50, filePath);
}

ContactsRepository::~ContactsRepository()
{

}

void ContactsRepository::Add(Contact * contact)
{
	ofstream out(this->filePath, ios::app);

	int id = GetNextId();
	contact->setId(id);

	out << contact->getId() << endl
		<< contact->getUserId() << endl
		<< contact->getFirstName() << endl
		<< contact->getLastName() << endl;

	out.close();
}

void ContactsRepository::Update(Contact * contact)
{
	ifstream in(this->filePath);
	ofstream out("temp.txt", ios::app);

	Contact* result = NULL;
	Contact* item = new Contact();
	char buffer[20];

	while (!in.eof())
	{
		in.getline(buffer, 20);
		item->setId(atoi(buffer));

		in.getline(buffer, 20);
		item->setUserId(atoi(buffer));

		in.getline(buffer, 20);
		item->setFirstName(buffer);

		in.getline(buffer, 20);
		item->setLastName(buffer);

		if (!in.eof() && item->getId() != contact->getId())
		{
			out << item->getId() << endl
				<< item->getUserId() << endl
				<< item->getFirstName() << endl
				<< item->getLastName() << endl;
		}
		else if (!in.eof() && item->getId() == contact->getId())
		{
			out << contact->getId() << endl
				<< contact->getUserId() << endl
				<< contact->getFirstName() << endl
				<< contact->getLastName() << endl;
		}
	}

	in.close();
	out.close();

	remove(this->filePath);
	rename("temp.txt", this->filePath);
}

void ContactsRepository::Delete(Contact * contact)
{
	ifstream in(this->filePath);
	ofstream out("temp.txt", ios::app);

	Contact* result = NULL;
	Contact* item = new Contact();
	char buffer[20];

	while (!in.eof())
	{
		in.getline(buffer, 20);
		item->setId(atoi(buffer));

		in.getline(buffer, 20);
		item->setUserId(atoi(buffer));

		in.getline(buffer, 20);
		item->setFirstName(buffer);

		in.getline(buffer, 20);
		item->setLastName(buffer);

		if (!in.eof() && item->getId() != contact->getId())
		{
			out << item->getId() << endl
				<< item->getUserId() << endl
				<< item->getFirstName() << endl
				<< item->getLastName() << endl;
		}
	}

	in.close();
	out.close();

	remove(this->filePath);
	rename("temp.txt", this->filePath);
}

Contact * ContactsRepository::GetById(int id)
{
	ifstream in(this->filePath);

	Contact* result = NULL;
	Contact* contact = new Contact();
	char buffer[20];

	while (!in.eof())
	{
		in.getline(buffer, 20);
		contact->setId(atoi(buffer));

		in.getline(buffer, 20);
		contact->setUserId(atoi(buffer));

		in.getline(buffer, 20);
		contact->setFirstName(buffer);

		in.getline(buffer, 20);
		contact->setLastName(buffer);

		if (contact->getId() == id)
		{
			result = contact;
			break;
		}
	}

	in.close();

	return result;
}

LinkedList<Contact>* ContactsRepository::GetAll()
{
	LinkedList<Contact>* result = new LinkedList<Contact>();

	ifstream in(this->filePath);

	Contact* contact = NULL;
	char buffer[20];

	while (!in.eof())
	{
		contact = new Contact();

		in.getline(buffer, 20);
		contact->setId(atoi(buffer));

		in.getline(buffer, 20);
		contact->setUserId(atoi(buffer));

		in.getline(buffer, 20);
		contact->setFirstName(buffer);

		in.getline(buffer, 20);
		contact->setLastName(buffer);

		result->Add(contact);
	}

	in.close();

	if (result->Count() > 0)
		result->RemoveAt(result->Count() - 1);

	return result;
}

LinkedList<Contact>* ContactsRepository::GetAll(int parentId)
{
	LinkedList<Contact>* result = new LinkedList<Contact>();

	ifstream in(this->filePath);

	Contact* contact = NULL;
	char buffer[20];

	while (!in.eof())
	{
		contact = new Contact();

		in.getline(buffer, 20);
		contact->setId(atoi(buffer));

		in.getline(buffer, 20);
		contact->setUserId(atoi(buffer));

		in.getline(buffer, 20);
		contact->setFirstName(buffer);

		in.getline(buffer, 20);
		contact->setLastName(buffer);

		if (contact->getUserId() == parentId)
			result->Add(contact);
	}

	in.close();

	return result;
}

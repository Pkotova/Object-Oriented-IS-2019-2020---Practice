#include "stdafx.h"
#include "string.h"
#include "fstream"

#include "PhonesRepository.h"

using namespace std;

int PhonesRepository::GetNextId()
{
	int nextId = 0;

	ifstream in(this->filePath);

	Phone* result = NULL;
	Phone* phone = new Phone();
	char buffer[20];

	while (!in.eof())
	{
		in.getline(buffer, 20);
		phone->setId(atoi(buffer));

		in.getline(buffer, 20);
		phone->setContactId(atoi(buffer));

		in.getline(buffer, 20);
		phone->setPhoneNumber(buffer);

		if (phone->getId() > nextId)
			nextId = phone->getId();
	}

	in.close();

	return nextId + 1;
}

PhonesRepository::PhonesRepository(char filePath[50])
{
	strcpy_s(this->filePath, 50, filePath);
}

PhonesRepository::~PhonesRepository()
{

}

void PhonesRepository::Add(Phone * phone)
{
	ofstream out(this->filePath, ios::app);

	int id = GetNextId();
	phone->setId(id);

	out << phone->getId() << endl
		<< phone->getContactId() << endl
		<< phone->getPhoneNumber() << endl;

	out.close();
}

void PhonesRepository::Update(Phone * phone)
{
	ifstream in(this->filePath);
	ofstream out("temp.txt", ios::app);

	Phone* result = NULL;
	Phone* item = new Phone();
	char buffer[20];

	while (!in.eof())
	{
		in.getline(buffer, 20);
		item->setId(atoi(buffer));

		in.getline(buffer, 20);
		item->setContactId(atoi(buffer));

		in.getline(buffer, 20);
		item->setPhoneNumber(buffer);

		if (!in.eof() && item->getId() != phone->getId())
		{
			out << item->getId() << endl
				<< item->getContactId() << endl
				<< item->getPhoneNumber() << endl;
		}
		else if (!in.eof() && item->getId() == phone->getId())
		{
			out << phone->getId() << endl
				<< phone->getContactId() << endl
				<< phone->getPhoneNumber() << endl;
		}
	}

	in.close();
	out.close();

	remove(this->filePath);
	rename("temp.txt", this->filePath);
}

void PhonesRepository::Delete(Phone * phone)
{
	ifstream in(this->filePath);
	ofstream out("temp.txt", ios::app);

	Phone* result = NULL;
	Phone* item = new Phone();
	char buffer[20];

	while (!in.eof())
	{
		in.getline(buffer, 20);
		item->setId(atoi(buffer));

		in.getline(buffer, 20);
		item->setContactId(atoi(buffer));

		in.getline(buffer, 20);
		item->setPhoneNumber(buffer);

		if (!in.eof() && item->getId() != phone->getId())
		{
			out << item->getId() << endl
				<< item->getContactId() << endl
				<< item->getPhoneNumber() << endl;
		}
	}

	in.close();
	out.close();

	remove(this->filePath);
	rename("temp.txt", this->filePath);
}

Phone * PhonesRepository::GetById(int id)
{
	ifstream in(this->filePath);

	Phone* result = NULL;
	Phone* phone = new Phone();
	char buffer[20];

	while (!in.eof())
	{
		in.getline(buffer, 20);
		phone->setId(atoi(buffer));

		in.getline(buffer, 20);
		phone->setContactId(atoi(buffer));

		in.getline(buffer, 20);
		phone->setPhoneNumber(buffer);

		if (phone->getId() == id)
		{
			result = phone;
			break;
		}
	}

	in.close();

	return result;
}

LinkedList<Phone>* PhonesRepository::GetAll()
{
	LinkedList<Phone>* result = new LinkedList<Phone>();

	ifstream in(this->filePath);

	Phone* phone = NULL;
	char buffer[20];

	while (!in.eof())
	{
		phone = new Phone();

		in.getline(buffer, 20);
		phone->setId(atoi(buffer));

		in.getline(buffer, 20);
		phone->setContactId(atoi(buffer));

		in.getline(buffer, 20);
		phone->setPhoneNumber(buffer);

		result->Add(phone);
	}

	in.close();

	if (result->Count() > 0)
		result->RemoveAt(result->Count() - 1);

	return result;
}

LinkedList<Phone>* PhonesRepository::GetAll(int parentId)
{
	LinkedList<Phone>* result = new LinkedList<Phone>();

	ifstream in(this->filePath);

	Phone* phone = NULL;
	char buffer[20];

	while (!in.eof())
	{
		phone = new Phone();

		in.getline(buffer, 20);
		phone->setId(atoi(buffer));

		in.getline(buffer, 20);
		phone->setContactId(atoi(buffer));

		in.getline(buffer, 20);
		phone->setPhoneNumber(buffer);

		if (phone->getContactId() == parentId)
			result->Add(phone);
	}

	in.close();

	return result;
}

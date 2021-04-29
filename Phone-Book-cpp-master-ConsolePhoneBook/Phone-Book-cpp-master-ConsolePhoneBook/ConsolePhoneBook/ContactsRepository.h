#pragma once
#include "Contact.h"
#include "LinkedList.cpp"

class ContactsRepository
{
private:
	char filePath[50];

	int GetNextId();
public:
	ContactsRepository(char filePath[50]);
	~ContactsRepository();

	void Add(Contact* contact);
	void Update(Contact* contact);
	void Delete(Contact* contact);
	Contact* GetById(int id);
	LinkedList<Contact>* GetAll();
	LinkedList<Contact>* GetAll(int parentId);
};


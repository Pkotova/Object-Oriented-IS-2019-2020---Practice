#pragma once
#include "Phone.h"
#include "LinkedList.cpp"

class PhonesRepository
{
private:
	char filePath[50];
	int GetNextId();
public:
	PhonesRepository(char filePath[50]);
	~PhonesRepository();

	void Add(Phone* phone);
	void Update(Phone* phone);
	void Delete(Phone* phone);
	Phone* GetById(int id);
	LinkedList<Phone>* GetAll();
	LinkedList<Phone>* GetAll(int parentId);
};
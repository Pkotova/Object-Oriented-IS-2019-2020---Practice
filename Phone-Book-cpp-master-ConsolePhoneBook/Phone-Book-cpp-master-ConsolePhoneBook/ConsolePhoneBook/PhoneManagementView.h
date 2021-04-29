#pragma once
#include "Enumerators.h"
#include "Contact.h"

class PhoneManagementView
{
private:
	Contact* parentContact;

public:
	PhoneManagementView(Contact* parentContact);
	~PhoneManagementView();

	CRUDMenuItems RenderMenu();

	void Add();
	void List();
	void Edit();
	void Delete();
	void Run();
};


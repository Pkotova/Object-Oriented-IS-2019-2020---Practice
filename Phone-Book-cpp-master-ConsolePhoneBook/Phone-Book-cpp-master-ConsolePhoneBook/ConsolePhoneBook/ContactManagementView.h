#pragma once
#include "Enumerators.h"

class ContactManagementView
{
public:
	ContactManagementView();
	~ContactManagementView();

	CRUDMenuItems RenderMenu();

	void Add();
	void List();
	void View();
	void Edit();
	void Delete();
	void Run();
};


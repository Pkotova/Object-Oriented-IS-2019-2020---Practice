#pragma once
#include "Enumerators.h"

class UserManagementView
{
public:
	UserManagementView();
	~UserManagementView();

	CRUDMenuItems RenderMenu();

	void Add();
	void List();
	void Edit();
	void Delete();
	void Run();
};


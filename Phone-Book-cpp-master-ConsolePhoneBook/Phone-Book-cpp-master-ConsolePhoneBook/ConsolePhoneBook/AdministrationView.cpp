#include "stdafx.h"
#include "AdministrationView.h"
#include "UserManagementView.h"
#include "ContactManagementView.h"
#include "iostream"

using namespace std;

AdministrationView::AdministrationView()
{
}


AdministrationView::~AdministrationView()
{
}

void AdministrationView::Run()
{
	while (true)
	{
		system("cls");
		cout << "[U]ser Management" << endl
			 << "[C]ontacts Management" << endl
			 << "E[x]it" << endl
			 << ">";

		char choice[2];
		cin.getline(choice, 2);

		switch (toupper(choice[0]))
		{
			case 'U':
			{
				UserManagementView view;
				view.Run();

				break;
			}
			case 'C':
			{
				ContactManagementView view;
				view.Run();

				break;
			}
			case 'X':
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

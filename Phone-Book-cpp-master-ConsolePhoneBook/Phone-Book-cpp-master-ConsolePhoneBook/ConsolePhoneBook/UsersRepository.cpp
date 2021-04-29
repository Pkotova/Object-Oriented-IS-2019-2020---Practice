#include "stdafx.h"
#include "string.h"
#include "fstream"
#include "UsersRepository.h"

using namespace std;

int UsersRepository::GetNextId()
{
	int nextId = 0;

	ifstream in(this->filePath);

	User* result = NULL;
	User* user = new User();
	char buffer[20];

	while (!in.eof())
	{
		in.getline(buffer, 20);
		user->setId(atoi(buffer));

		in.getline(buffer, 20);
		user->setUsername(buffer);

		in.getline(buffer, 20);
		user->setPassword(buffer);

		in.getline(buffer, 20);
		user->setFirstName(buffer);

		in.getline(buffer, 20);
		user->setLastName(buffer);

		in.getline(buffer, 20);
		user->setIsAdmin(atoi(buffer));

		if (user->getId() > nextId)
			nextId = user->getId();
	}

	in.close();

	return nextId + 1;
}

UsersRepository::UsersRepository(char filePath[50])
{
	strcpy_s(this->filePath, 50, filePath);
}

UsersRepository::~UsersRepository()
{

}

void UsersRepository::Add(User * user)
{
	ofstream out(this->filePath, ios::app);

	int id = GetNextId();
	user->setId(id);

	out << user->getId() << endl
		<< user->getUsername() << endl
		<< user->getPassword() << endl
		<< user->getFirstName() << endl
		<< user->getLastName() << endl
		<< user->getIsAdmin() << endl;

	out.close();
}

void UsersRepository::Update(User * user)
{
	ifstream in(this->filePath);
	ofstream out("temp.txt", ios::app);

	User* result = NULL;
	User* item = new User();
	char buffer[20];

	while (!in.eof())
	{
		in.getline(buffer, 20);
		item->setId(atoi(buffer));

		in.getline(buffer, 20);
		item->setUsername(buffer);

		in.getline(buffer, 20);
		item->setPassword(buffer);

		in.getline(buffer, 20);
		item->setFirstName(buffer);

		in.getline(buffer, 20);
		item->setLastName(buffer);

		in.getline(buffer, 20);
		item->setIsAdmin(atoi(buffer));

		if (!in.eof() && item->getId() != user->getId())
		{
			out << item->getId() << endl
				<< item->getUsername() << endl
				<< item->getPassword() << endl
				<< item->getFirstName() << endl
				<< item->getLastName() << endl
				<< item->getIsAdmin() << endl;
		}
		else if (!in.eof() && item->getId() == user->getId())
		{
			out << user->getId() << endl
				<< user->getUsername() << endl
				<< user->getPassword() << endl
				<< user->getFirstName() << endl
				<< user->getLastName() << endl
				<< item->getIsAdmin() << endl;
		}
	}

	in.close();
	out.close();

	remove(this->filePath);
	rename("temp.txt", this->filePath);
}

void UsersRepository::Delete(User * user)
{
	ifstream in(this->filePath);
	ofstream out("temp.txt", ios::app);

	User* result = NULL;
	User* item = new User();
	char buffer[20];

	while (!in.eof())
	{
		in.getline(buffer, 20);
		item->setId(atoi(buffer));

		in.getline(buffer, 20);
		item->setUsername(buffer);

		in.getline(buffer, 20);
		item->setPassword(buffer);

		in.getline(buffer, 20);
		item->setFirstName(buffer);

		in.getline(buffer, 20);
		item->setLastName(buffer);

		in.getline(buffer, 20);
		item->setIsAdmin(atoi(buffer));

		if (!in.eof() && item->getId() != user->getId())
		{
			out << item->getId() << endl
				<< item->getUsername() << endl
				<< item->getPassword() << endl
				<< item->getFirstName() << endl
				<< item->getLastName() << endl
				<< item->getIsAdmin() << endl;
		}
	}

	in.close();
	out.close();

	remove(this->filePath);
	rename("temp.txt", this->filePath);
}

User * UsersRepository::GetById(int id)
{
	ifstream in(this->filePath);
	
	User* result = NULL;
	User* user = new User();
	char buffer[20];

	while (!in.eof())
	{
		in.getline(buffer, 20);
		user->setId(atoi(buffer));

		in.getline(buffer, 20);
		user->setUsername(buffer);

		in.getline(buffer, 20);
		user->setPassword(buffer);

		in.getline(buffer, 20);
		user->setFirstName(buffer);

		in.getline(buffer, 20);
		user->setLastName(buffer);

		in.getline(buffer, 20);
		user->setIsAdmin(atoi(buffer));

		if (user->getId() == id)
		{
			result = user;
			break;
		}
	}

	in.close();

	return result;
}

LinkedList<User>* UsersRepository::GetAll()
{
	LinkedList<User>* result = new LinkedList<User>();

	ifstream in(this->filePath);

	User* user = NULL;
	char buffer[20];

	while (!in.eof())
	{
		user = new User();

		in.getline(buffer, 20);
		user->setId(atoi(buffer));

		in.getline(buffer, 20);
		user->setUsername(buffer);

		in.getline(buffer, 20);
		user->setPassword(buffer);

		in.getline(buffer, 20);
		user->setFirstName(buffer);

		in.getline(buffer, 20);
		user->setLastName(buffer);

		in.getline(buffer, 20);
		user->setIsAdmin(atoi(buffer));

		result->Add(user);
	}

	in.close();

	if (result->Count() > 0)
		result->RemoveAt(result->Count() - 1);

	return result;
}

User * UsersRepository::GetByUsernameAndPassword(char username[20], char password[20])
{
	ifstream in(this->filePath);

	User* result = NULL;
	User* user = new User();
	char buffer[20];

	while (!in.eof())
	{
		in.getline(buffer, 20);
		user->setId(atoi(buffer));

		in.getline(buffer, 20);
		user->setUsername(buffer);

		in.getline(buffer, 20);
		user->setPassword(buffer);

		in.getline(buffer, 20);
		user->setFirstName(buffer);

		in.getline(buffer, 20);
		user->setLastName(buffer);

		in.getline(buffer, 20);
		user->setIsAdmin(atoi(buffer));

		if (strcmp(user->getUsername(), username) == 0 &&
			strcmp(user->getPassword(), password) == 0)
		{
			result = user;
			break;
		}
	}

	in.close();

	return result;
}

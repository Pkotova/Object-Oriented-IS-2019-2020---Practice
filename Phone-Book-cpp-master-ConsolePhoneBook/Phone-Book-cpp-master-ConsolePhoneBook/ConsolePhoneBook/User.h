#pragma once
class User
{
private:
	int id;
	char username[20];
	char password[20];
	char firstName[20];
	char lastName[20];
	int isAdmin;

public:
	void setId(int id);
	int getId();

	void setUsername(char username[20]);
	char* getUsername();

	void setPassword(char password[20]);
	char* getPassword();

	void setFirstName(char firstName[20]);
	char* getFirstName();

	void setLastName(char lastName[20]);
	char* getLastName();

	void setIsAdmin(int isAdmin);
	int getIsAdmin();
};
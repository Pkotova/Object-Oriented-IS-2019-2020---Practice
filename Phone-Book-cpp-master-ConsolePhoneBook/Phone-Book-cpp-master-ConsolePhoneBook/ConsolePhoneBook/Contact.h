#pragma once
class Contact
{
private:
	int id;
	int userId;
	char firstName[20];
	char lastName[20];

public:
	void setId(int id);
	int getId();

	void setUserId(int userId);
	int getUserId();

	void setFirstName(char firstName[20]);
	char* getFirstName();

	void setLastName(char lastName[20]);
	char* getLastName();
};
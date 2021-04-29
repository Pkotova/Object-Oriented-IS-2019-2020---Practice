#pragma once
class Phone
{
private:
	int id;
	int contactId;
	char phoneNumber[20];

public:
	void setId(int id);
	int getId();

	void setContactId(int contactId);
	int getContactId();

	void setPhoneNumber(char phoneNumber[20]);
	char* getPhoneNumber();
};


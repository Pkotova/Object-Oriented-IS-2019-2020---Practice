#include "stdafx.h"
#include "string.h"
#include "Phone.h"

void Phone::setId(int id)
{
	this->id = id;
}

int Phone::getId()
{
	return this->id;
}

void Phone::setContactId(int contactId)
{
	this->contactId = contactId;
}

int Phone::getContactId()
{
	return this->contactId;
}

void Phone::setPhoneNumber(char phoneNumber[20])
{
	strcpy_s(this->phoneNumber, 20, phoneNumber);
}

char* Phone::getPhoneNumber()
{
	return this->phoneNumber;
}

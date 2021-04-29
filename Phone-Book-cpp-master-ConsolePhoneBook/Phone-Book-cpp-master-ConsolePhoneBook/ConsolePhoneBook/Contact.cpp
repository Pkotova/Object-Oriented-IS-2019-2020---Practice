#include "stdafx.h"
#include "string.h"
#include "Contact.h"

void Contact::setId(int id)
{
	this->id = id;
}

int Contact::getId()
{
	return this->id;
}

void Contact::setUserId(int userId)
{
	this->userId = userId;
}

int Contact::getUserId()
{
	return this->userId;
}

void Contact::setFirstName(char firstName[20])
{
	strcpy_s(this->firstName, 20, firstName);
}

char* Contact::getFirstName()
{
	return this->firstName;
}

void Contact::setLastName(char lastName[20])
{
	strcpy_s(this->lastName, 20, lastName);
}

char* Contact::getLastName()
{
	return this->lastName;
}
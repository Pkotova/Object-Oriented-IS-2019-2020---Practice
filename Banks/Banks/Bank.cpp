#include "Bank.h"

void Bank::destroy()
{
	std::cout << "Memory empty!" << std::endl;
	delete[] name;
	delete[] centralLocation;
}

void Bank::copy(const Bank& bank)
{
	setId(bank.id);
	setName(bank.name);
	setCentralLocation(bank.centralLocation);
	setManager(bank.manager);
}

Bank::Bank() : name(nullptr), centralLocation(nullptr)
{
	Manager defaultManager;
	setId(0);
	setName("Default");
	setCentralLocation("Default");
	setManager(defaultManager);
}

Bank::Bank(const Bank& bank) 
{
	copy(bank);
}

Bank& Bank::operator=(const Bank& bank)
{
	if (this != &bank)
	{
		copy(bank);
	}
	return *this;
}

Bank::Bank(int newId, const char* newName, const char* newCentralLocation, Manager& newManager)
	: name(nullptr), centralLocation(nullptr)
{
	setId(newId);
	setName(newName);
	setCentralLocation(newCentralLocation);
	setManager(newManager);
}

Bank::~Bank()
{
	destroy();
}

void Bank::setId(int newId)
{
	this->id = newId;
}

int Bank::getId() const
{
	return this->id;
}

void Bank::setName(const char* newName)
{
	if (newName != NULL)
	{
		delete[] this->name;
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}
}

const char* Bank::getName() const
{
	return this->name;
}

void Bank::setCentralLocation(const char* newCentralLocation)
{
	if (newCentralLocation != NULL)
	{
		delete[] this->centralLocation;
		this->centralLocation = new char[strlen(newCentralLocation) + 1];
		strcpy_s(this->centralLocation, strlen(newCentralLocation) + 1, newCentralLocation);
	}
}

const char* Bank::getCentalLocation() const
{
	return this->centralLocation;
}

void Bank::setManager(const Manager& newManager)
{
	this->manager = newManager;
}

const Manager& Bank::getManager() const
{
	return this->manager;
}

std::ostream& operator<<(std::ostream& out, const Bank& bank)
{
	out << " Id: " << bank.id << std::endl
		<< "Name: " << bank.name << std::endl
		<< "Central location: " << bank.centralLocation << std::endl
		<< "Manager" << bank.manager << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Bank& bank)
{
	std::cout << "Id: ";
	in >> bank.id;
	std::cout << "Name: ";
	in >> bank.name;
	std::cout << "Location: ";
	in >> bank.centralLocation;
	std::cout << "Manager: ";
	in >> bank.manager;

	return in;
}

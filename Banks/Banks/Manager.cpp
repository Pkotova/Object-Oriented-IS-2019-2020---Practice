#include "Manager.h"

Manager::Manager()
{
	setId(0);
	setName("Default");
	setLastName("Default");
	setAge(25);
}

Manager::Manager(int newId, const char* newName, const char* newLastName, int newAge)
{
	setId(newId);
	setName(newName);
	setLastName(newLastName);
	setAge(newAge);
}

//Manager& Manager::operator=(const Manager& other)
//{
//if (this != &other)
//	{
//		setId(other.id);
//		setName(other.name);
//		setLastName(other.lastName);
//		setAge(other.age);
//	}
//	
//	return *this;
//}

Manager::~Manager()
{
	std::cout << "Manager deleted!" << std::endl;
}

void Manager::setId(int newId)
{
	this->id = newId;
}

int Manager::getId() const
{
	return this->age;
}

void Manager::setName(const char* newName)
{
	strcpy_s(this->name, 32, newName);
}

const char* Manager::getName() const
{
	return this->name;
}

void Manager::setLastName(const char* newLastName)
{
	strcpy_s(this->lastName, 32, newLastName);
}

const char* Manager::getLastName() const
{
	return this->lastName;
}

void Manager::setAge(int newAge)
{
	this->age = newAge;
}

int Manager::getAge() const
{
	return this->age;
}

std::ostream& operator<<(std::ostream& out, const Manager& manager)
{
	out << " Id: " << manager.id << std::endl
		<< "Name: " << manager.name << std::endl
		<< "Last Name: " << manager.lastName << std::endl
		<< "Age: " << manager.age << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Manager& manager)
{
	std::cout << "Id: ";
	in >> manager.id;
	std::cout << "Name: ";
	in >> manager.name;
	std::cout << "Last Name: ";
	in >> manager.lastName;
	std::cout << "Age: ";
	in >> manager.age;

	return in;
}

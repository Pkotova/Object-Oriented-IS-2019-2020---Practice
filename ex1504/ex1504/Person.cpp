#include "Person.h"

void Person::copy(const Person& other)
{
	this->setName(other.name);
	this->setAge(other.age);
	this->setGender(other.gender);
}

void Person::destroy()
{
	delete[] this->name;
}

Person::Person() : name(nullptr)
{
	this->setName("Default Default");
	this->setAge(18);
	this->setGender(' ');
}

Person::Person(const Person& other)
{
	this->copy(other);
}

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		//destroy();
		copy(other);
	}
	return *this;
}

Person::~Person()
{
	destroy();
}

void Person::setName(const char* newName)
{
	if (newName != nullptr)
	{
		//destroy();
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}
}

void Person::setAge(size_t newAge)
{
	this->age = newAge;
}

void Person::setGender(char newGender)
{
	this->gender = newGender;
}

const char* Person::getName() const
{
	return this->name;
}

size_t Person::getAge() const
{
	return this->age;
}

char Person::getGender() const
{
	return this->gender;
}

void Person::print() const
{
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Age: " << this->age << std::endl;
	std::cout << "Gender: " << this->gender << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Person& other)
{
	out << "Name: " << other.name << std::endl;
	out << "Age: " << other.age << std::endl;
	out << "Gender: " << other.gender << std::endl;

	return out;
}

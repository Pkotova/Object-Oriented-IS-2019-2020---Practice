#include "Person.h"
#include<iostream>
#include<cstring>
#include<regex>
void Person::copy(const Person& other)
{
	setName(other.name);
	setAge(other.age);
	setIsStudent(other.isStudent);
}
void Person::erase()
{
	delete[] this->name;
}
Person::Person()
{
	this->setName("Dafault Default");
	this->age = 18;
	this->age = 1;
}

Person::Person(const char* name, size_t age, bool isStudent)
{
	this->setName(name);
	this->setAge(age);
	this->setIsStudent(isStudent);
}

Person::Person(const Person& other)
{
	this->copy(other);
}

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

Person::~Person()
{
	this->erase();
}

void Person::setName(const char* newName)
{
	if (newName != nullptr)
	{
		//this->erase();
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}
}

void Person::setAge(size_t age)
{
	(age < 18) ? this->age = 18 : this->age = age;
}

void Person::setIsStudent(bool newIsStudent)
{
	this->isStudent = newIsStudent;
}

const char* Person::getName() const
{
	return this->name;
}

size_t Person::getAge() const
{
	return this->age;
}

bool Person::getIsStudent() const
{
	return this->isStudent;
}

void Person::print() const
{
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Age: " << this->age << std::endl;
	std::cout << "Is student: "<<std::boolalpha << this->isStudent << std::endl;
}
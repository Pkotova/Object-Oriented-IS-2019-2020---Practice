#include "Character.h"
#include<cstring>
#include<iostream>
void Character::copy(const Character& other)
{
	setName(other.name);
	setAge(other.age);
	setSex(other.sex);
}

void Character::destroy()
{
	delete[]this->name;
}

Character::Character() : Character("default default", 20, 'f')
{}

Character::Character(const Character & other)
{
	copy(other);
}

Character::Character(const char* newName, size_t newAge, char newSex)
{
	setName(newName);
	setAge(newAge);
	setSex(newSex);
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		//destroy();
		copy(other);
	}
	return *this;
}
Character::~Character()
{
	destroy();
}
void Character::setName(const char* newName)
{
	if (newName != nullptr)
	{
		delete[]this->name;
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}
}

const char* Character::getName() const
{
	return this->name;
}

void Character::setAge(size_t newAge)
{
	(newAge > 0) ? this->age = newAge : this->age = 10;
}

size_t Character::getAge() const
{
	return this->age;
}

void Character::setSex(char newSex)
{
	(newSex == 'M' || newSex == 'F' || 
		newSex == 'm' || newSex == 'f') 
		? this->sex = newSex 
		: this->sex = 'm';
}

char Character::getSex() const
{
	return this->sex;
}

void Character::show() const
{
	std::cout << "- " << this->name;
	std::cout << ", Age: " << this->age;
	std::cout << ", Score: " << getScore() << std::endl;
}
void Character::print() const
{
	std::cout << "- " << this->name << std::endl;
	std::cout << "- Age: " << this->age << std::endl;
	std::cout << "- Sex: " << this->sex << std::endl;
	std::cout << "- Score: " << getScore() << std::endl;
}
bool Character::operator==(const Character& other)const
{
	return strcmp(this->name, other.name) == 0;
}


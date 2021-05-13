#include "Knight.h"
#include<cstring>
#include<iostream>
void Knight::copy(const Knight& other)
{
	setName(other.name);
	setAge(other.age);
	setSex(other.sex);
	setTitle(other.title);
	setKillings(other.killings);
}

void Knight::destroy()
{
	delete[] this->title;
}

Knight::Knight() : Character()
{
	setTitle("default");
	setKillings(0);
}

Knight::Knight(const Knight& other)
{
	copy(other);
}

Knight::Knight(const char* newName, size_t newAge, const char newSex, const char* newTitle, size_t newKillings)
	: Character(newName,newAge, newSex)
{
	setTitle(newTitle);
	setKillings(newKillings);
}

Knight& Knight::operator=(const Knight& other)
{
	if (this != &other)
	{
		//destroy();
		copy(other);
	}
	return *this;
}

Knight::~Knight()
{
	destroy();
}

void Knight::setTitle(const char* newTitle)
{
	if (newTitle != nullptr)
	{
		delete[]this->title;
		this->title = new char[strlen(newTitle) + 1];
		strcpy_s(this->title, strlen(newTitle) + 1, newTitle);
	}
}

const char* Knight::getTitle() const
{
	return this->title;
}

void Knight::setKillings(size_t newKillings)
{
	(newKillings > 0) ? this->killings = newKillings : this->killings = 5;
}

size_t Knight::getKillings() const
{
	return this->killings;
}

Knight* Knight::clone() const
{
	return new Knight(*this);
}

int Knight::getScore() const
{
	return this->killings * 10;;
}

void Knight::print() const
{
	std::cout << std::endl;
	std::cout << "	 KNIGHT: " << std::endl;
	std::cout << "--------------------------------" << std::endl;
	std::cout << "- " << this->title << " " << this->name << std::endl;
	std::cout << "- Age: " << this->age << std::endl;
	std::cout << "- Sex: " << this->sex << std::endl;
	std::cout << "- Score: " << getScore() << std::endl;
	std::cout << "-   Title: " << this->title << std::endl;
	std::cout << "-   Body count: " << this->killings << std::endl;
}
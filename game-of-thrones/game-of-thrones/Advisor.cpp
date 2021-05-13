#include "Advisor.h"
#include <iostream>
Advisor::Advisor() : Advisor("Default", 0, 'm', false, false)
{}

Advisor::Advisor(const char* newName, size_t newAge, char newSex, bool newIsMaester, bool newIsHand)
	:Character(newName,newAge,newSex)
{
	setIsMaister(newIsMaester);
	setIsHand(newIsHand);
}

void Advisor::setIsMaister(bool newIsMaester)
{
	this->isMaester = newIsMaester;
}

void Advisor::setIsHand(bool newIsHand)
{
	this->isHand = newIsHand;
}

bool Advisor::getIsMaister() const
{
	return this->isMaester;
}

bool Advisor::getIsHand() const
{
	return this->isHand;
}

Advisor* Advisor::clone() const
{
	return new Advisor(*this);
}

int Advisor::getScore() const
{
	return (this->isHand && this->isMaester) ? 50 : 25;
}

void Advisor::print() const
{
	std::cout << std::endl;
	std::cout << "	ADVISOR: " << std::endl;
	std::cout << "------------------------------" << std::endl;
	std::cout << "- " << this->name << std::endl;
	std::cout << "- Age: " << this->age << std::endl;
	std::cout << "- Sex: " << this->sex << std::endl;
	std::cout << "- Score: " << getScore() << std::endl;
	std::cout << "-	 Is hand: " << std::boolalpha << this->isHand << std::endl;
	std::cout << "-	 Is maester: " << std::boolalpha << this->isMaester << std::endl;
}

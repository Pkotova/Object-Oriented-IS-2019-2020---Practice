#pragma once
#include "Character.h"
class Advisor : public Character
{
private:
	bool isMaester;
	bool isHand;
public:

	Advisor();
	Advisor(const char* newName, size_t newAge, char newSex, bool newIsMaester, bool newIsHand);

	void setIsMaister(bool newIsMaester);
	void setIsHand(bool newIsHand);

	bool getIsMaister()const;
	bool getIsHand()const;

	Advisor* clone()const;
	int getScore()const;

	void print()const;
};


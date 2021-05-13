#pragma once
#include"Character.h"
class Ruler : public Character
{
private:
	size_t numberOfChildren;
	bool hasSat; // has sat on the Iron Throne

public:
	Ruler();
	Ruler(const char* newName, size_t newAge, char newSex, size_t newNumberOfChildren, bool newHasSat);

	void setNumberOfChildren(size_t newNumberOfChildren);
	void SethasSat(bool newHasSat);

	unsigned int getNumberOfChildren()const;
	bool getHasSat()const;

	Ruler* clone()const;
	int getScore()const;
	void print()const;
};
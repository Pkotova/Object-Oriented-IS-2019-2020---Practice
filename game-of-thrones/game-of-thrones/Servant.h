#pragma once
#include "Character.h"
class Servant : public Character
{
private:
	bool isBetrayer;
public:
	Servant();
	Servant(const char*, size_t, char, bool);

	void setIsBetrayer(bool);
	bool getIsBetrayer()const;

	Servant* clone() const;
	int getScore()const;
	void print()const;
};
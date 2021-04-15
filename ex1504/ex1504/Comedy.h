#pragma once
#include"Film.h"
class Comedy : public Film
{
private:
	bool isRomantic;
public:
	Comedy();
	Comedy(const char* title, size_t year,
		Vector<Actor> cast,int yearsRestrictions,
		bool newIsRomantic);
	Comedy(Film f, bool newIsRomantic);
	void setIsRomantic(bool newIsRomantic);
	bool getIsRomantic() const;

	friend std::ostream& operator<<(std::ostream& out, const Comedy& other);

};


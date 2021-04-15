#include "Comedy.h"

Comedy::Comedy() : Film()
{
	setIsRomantic(0);
}

Comedy::Comedy(const char* title, size_t year, Vector<Actor> cast, int yearsRestriction, bool newIsRomantic)
{
	setTitle(title);
	setYear(year);
	setCast(cast);
	setYearsRestriction(yearsRestriction);
	setIsRomantic(newIsRomantic);
}

Comedy::Comedy(Film f, bool newIsRomantic)
{
	setTitle(f.getTitle());
	setYear(f.getYear());
	setCast(f.getCast());
	setYearsRestriction(f.getYearsRestriction());
	setIsRomantic(newIsRomantic);
}

void Comedy::setIsRomantic(bool newIsRomantic)
{
	this->isRomantic = newIsRomantic;
}

bool Comedy::getIsRomantic() const
{
	return this->isRomantic;
}

std::ostream& operator<<(std::ostream& out, const Comedy& other)
{
	out << "Title: " << other.title << std::endl;
	out << "Year: " << other.year << std::endl;
	out << "Cast: " << std::endl;
	out << "==================" << std::endl;
	for (size_t i = 0; i < other.cast.getSize(); i++)
	{
		out << other.cast[i] << std::endl;
	}
	out << "==================" << std::endl;
	out << "Years restiction (over) : " << other.yearsRestiction << std::endl;
	out << "Is it romantic?: " << other.isRomantic << std::endl;
	return out;
}

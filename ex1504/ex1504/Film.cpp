#include "Film.h"

void Film::copy(const Film& other)
{
	setTitle(other.title);
	setYear(other.year);
	setCast(other.cast);
	setYearsRestriction(other.yearsRestiction);
}

void Film::destroy()
{
	delete[] this->title;
}

Film::Film() : Film("Default", 1900,Vector<Actor>::Vector<Actor>(),16)
{}

Film::Film(const char* newTitle, size_t newYear, 
	Vector<Actor> newCast, int newYearsRestriction)
	:title(nullptr)
{
	setTitle(newTitle);
	setYear(newYear);
	setCast(newCast);
	setYearsRestriction(newYearsRestriction);
}

Film::Film(const Film& other)
{
	copy(other);
}

Film& Film::operator=(const Film& other)
{
	if (this != &other)
	{
	//	destroy();
		copy(other);
	}
	return *this;
}

Film::~Film()
{
	destroy();
}

void Film::setTitle(const char* newTitle)
{
	if (newTitle != nullptr)
	{
		//destroy();
		this->title = new char[strlen(newTitle) + 1];
		strcpy_s(this->title, strlen(newTitle) + 1, newTitle);
	}
}

void Film::setYear(size_t newYear)
{
	(newYear > 2021) ? this->year = 2021 : this->year = newYear;
}

void Film::setCast(Vector<Actor> newCast)
{
	this->cast = newCast;
}

void Film::setYearsRestriction(int newYearsRestriction)
{
	(newYearsRestriction > 18) ? 
			this->yearsRestiction = 18 
		: this->yearsRestiction = newYearsRestriction;
}

const char* Film::getTitle() const
{
	return this->title;
}

size_t Film::getYear() const
{
	return this->year;
}

const Vector<Actor>& Film::getCast() const
{
	return cast;
}

int Film::getYearsRestriction() const
{
	return this->yearsRestiction;
}

std::ostream& operator<<(std::ostream& out, const Film& other)
{
	out << "Title: " << other.title << std::endl;
	out << "Year: " << other.year << std::endl;
	out << "Cast: " << std::endl;
	out << "==================" << std::endl;
	for (size_t i = 0; i < other.cast.getSize(); i++)
	{
		out<<other.cast[i]<<std::endl;
	}
	out << "==================" << std::endl;
	out << "Years restiction (over) : " << other.yearsRestiction << std::endl;
	
	return out;
}

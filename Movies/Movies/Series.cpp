#include "Series.h"

void Series::copy(const Series& series) 
{
	Movie::copy(series);
	setMainCharacter(series.mainCharacter);
}

void Series::destroy()
{
	delete[] mainCharacter;
}

Series::Series() : Movie("Default", 0, "Default Default", 0), mainCharacter(nullptr)
{
	setMainCharacter("Default Default");
}

Series& Series::operator=(const Series& series)
{
	if (&series != this)
	{
		//Movie::operator=(series);
		copy(series);
	}
	return *this;
}

Series::Series(const Series& series)
{
	copy(series);
}

Series::~Series()
{
	destroy();
}

void Series::setMainCharacter(const char* newMainCharacter)
{
	if (newMainCharacter != NULL)
	{
		delete[] this->mainCharacter;
		this->mainCharacter = new char[strlen(newMainCharacter) + 1];
		strcpy_s(this->mainCharacter, strlen(newMainCharacter) + 1, newMainCharacter);
	}
}

const char* Series::getMainCharacter() const
{
	return this->mainCharacter;
}

std::ostream& operator<<(std::ostream& out, const Series& series)
{
	out << "Title: " << series.title << std::endl
		<< "Length(in minutes)" << series.length << std::endl
		<< "Director: " << series.director << std::endl
		<< "Budget: " << series.budget << std::endl
		<< "Main character" << series.mainCharacter << std::endl;
	return out;
}

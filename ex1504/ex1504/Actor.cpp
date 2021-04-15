#include "Actor.h"

Actor::Actor() : Person()
{
	/*
	* this->setName("Default Default");
	* this->setAge(18);
	* this->setGender(' ');
	*/
	setHasAward(1);
	setFilms(1);
}

Actor::Actor(const char* newName, size_t newAge, char newGender, bool newHasAward, int newFilms)
{
	setName(newName);
	setAge(newAge);
	setGender(newGender);
	setHasAward(newHasAward);
	setFilms(newFilms);
}

void Actor::setHasAward(bool newHasAward)
{
	this->hasAward = newHasAward;
}

void Actor::setFilms(int newFilms)
{
	(newFilms < 0) ? this->films = 1 : this->films = newFilms;
}

bool Actor::getHasAward() const
{
	return this->hasAward;
}

int Actor::getFilms() const
{
	return this->films;
}

std::ostream& operator<<(std::ostream& out, const Actor& other)
{
	out << "Name: " << other.name << std::endl;
	out << "Age: " << other.age << std::endl;
	out << "Gender: " << other.gender << std::endl;
	out << "Has awards: " <<std::boolalpha <<other.hasAward << std::endl;
	out << "How many films: " << other.films << std::endl;
	return out;
}

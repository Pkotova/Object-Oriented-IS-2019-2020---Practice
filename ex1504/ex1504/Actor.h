#pragma once
#include"Person.h"
class Actor : public Person
{
private:
	/*
	* char* name;
	* size_t age;
	* char gender; // F,M ... 
	* void copy(const Person& other);
	* void destroy();
	*/
	bool hasAward;
	int films;

public:
	Actor();
	Actor(const char* newName, size_t newAge, char newGender,bool newHasAward, int newFilms);
	void setHasAward(bool newHasAward);
	void setFilms(int newFilms);

	bool getHasAward()const;
	int getFilms()const;
	friend std::ostream& operator<<(std::ostream& out, const Actor& other);
};


#pragma once
#include"Actor.h"
#include"Vector.h"
class Film
{
protected:

	char* title;
	size_t year;
	Vector<Actor> cast;
	int yearsRestiction;

	void copy(const Film& other);
	void destroy();
public:
	Film();
	Film(const char* newTitle, size_t newYear, Vector<Actor> newCast, int newYearsRestriction);
	Film(const Film& other);
	Film& operator=(const Film& other);
	~Film();

	void setTitle(const char* newTitle);
	void setYear( size_t newYear);
	void setCast(Vector<Actor> newCast);
	void setYearsRestriction(int newYearsRestriction);

	const char* getTitle()const;
	size_t getYear()const;
	const Vector<Actor>& getCast()const;
	int getYearsRestriction()const;

	 friend std::ostream& operator<<(std::ostream& out, const Film& other);

};


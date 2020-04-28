#pragma once
#include<iostream>

class Movie
{
protected:

	char* title;
	double length;
	char* director;
	double budget;

	void copy(const Movie& movie);
	void destroy();

public:

	Movie();
	Movie(const Movie& movie);
	Movie& operator=(const Movie& other);
	Movie(const char* newTitle, double newLength, const char* newDirector, double newBudget);
	~Movie();

	void setTitle(const char* newTitle);
	const char* getTitle() const;

	void setLength(double newLength);
	double getLength()const;

	void setDirector(const char* newDirector);
	const char* getDirector() const;

	void setBudget(double newBudget);
	double getBudget()const;

	friend std::ostream& operator<<(std::ostream& out, const Movie& movie);
	friend std::istream& operator>>(std::istream& in,  Movie& movie);
};


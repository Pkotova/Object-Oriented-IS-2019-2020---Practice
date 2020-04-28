#include "Movie.h"
#include<iostream>
void Movie::copy(const Movie& movie)
{
	setTitle(movie.title);
	setLength(movie.length);
	setDirector(movie.director);
	setBudget(movie.budget);
}

void Movie::destroy()
{
	std::cout << "Deleted! " << std::endl;
	delete[] this->title;
	delete[] this->director;
}

Movie::Movie() : Movie("Default", 0, "Defaut Default", 0)
{}

Movie::Movie(const Movie& movie)
{
	copy(movie);
}

Movie& Movie::operator=(const Movie& other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}

Movie::Movie(const char* newTitle, double newLength, const char* newDirector, double newBudget) 
	: title(nullptr), director(nullptr)
{
	setTitle(newTitle);
	setLength(newLength);
	setDirector(newDirector);
	setBudget(newBudget);
}

Movie::~Movie()
{
	destroy();
}

void Movie::setTitle(const char* newTitle)
{
	if (newTitle != NULL)
	{
		delete[] this->title;
		this->title = new char[strlen(newTitle) + 1];
		strcpy_s(this->title, strlen(newTitle) + 1, newTitle);
	}
}

const char* Movie::getTitle() const
{
	return this->title;
}

void Movie::setLength(double newLength)
{
	(newLength > 0) ? this->length = newLength : this->length = 60;
}

double Movie::getLength() const
{
	return this->length;
}

void Movie::setDirector(const char* newDirector)
{
	if (newDirector != NULL)
	{
		delete[] this->director;
		this->director = new char[strlen(newDirector) + 1];
		strcpy_s(this->director, strlen(newDirector) + 1, newDirector);
	}
}

const char* Movie::getDirector() const
{
	return this->director;
}

void Movie::setBudget(double newBudget)
{
	(newBudget > 0) ? this->budget = newBudget: this->budget = 20000;
}

double Movie::getBudget() const
{
	return this->budget;
}

std::ostream& operator<<(std::ostream& out, const Movie& movie)
{
	out << "Title: " << movie.title << std::endl
		<< "Length(in minutes)" << movie.length << std::endl
		<< "Director: " << movie.director << std::endl
		<< "Budget: " << movie.budget << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Movie& movie)
{
	std::cout << "Title: ";
	in >> movie.title;

	std::cout << "Length: ";
	in >> movie.length;

	std::cout << "Director: ";
	in >> movie.director;

	std::cout << "Budget: ";
	in >> movie.budget;

	return in;
}

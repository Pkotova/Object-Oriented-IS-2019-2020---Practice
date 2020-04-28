#include "Cartoon.h"

Cartoon::Cartoon() : Movie("Default", 0, "Defaut Default", 0)
{
	setFramesPerSecond(0);
}

Cartoon::Cartoon(const char* newTitle, double newLength, const char* newDirector,
	double newBudget, int newFramesPerSecond)
	: Movie(newTitle, newLength, newDirector, newBudget)
{
	setFramesPerSecond(newFramesPerSecond);
}

void Cartoon::setFramesPerSecond(int newFramesPerSecond)
{
	(newFramesPerSecond > 0) ? this->framesPerSecond = newFramesPerSecond : this->framesPerSecond = 0;
}

int Cartoon::getFramesPerSecond() const
{
	return this->framesPerSecond;
}

std::ostream& operator<<(std::ostream& out, const Cartoon& cartoon)
{
	out << "Title: " << cartoon.title << std::endl
		<< "Length(in minutes)" << cartoon.length << std::endl
		<< "Director: " << cartoon.director << std::endl
		<< "Budget: " << cartoon.budget << std::endl
		<< "Frames Per Second: " << cartoon.framesPerSecond << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Cartoon& cartoon)
{
	std::cout << "Title: ";
	in >> cartoon.title;

	std::cout << "Length: ";
	in >> cartoon.length;

	std::cout << "Director: ";
	in >> cartoon.director;

	std::cout << "Budget: ";
	in >> cartoon.budget;

	std::cout << "Frames per second: ";
	in >> cartoon.framesPerSecond;

	return in;
}
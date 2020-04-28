#include "Action.h"

Action::Action() : Movie("Default", 0, "Defaut Default", 0)
{
	setPg(16);
}

Action::Action(const char* newTitle, double newLength, const char* newDirector, 
	double newBudget,int newPg)
	:Movie(newTitle,newLength,newDirector,newBudget)
{
	setPg(newPg);
}

void Action::setPg(int newPg)
{
	(newPg > 0) ? this->pG = newPg : this->pG = 16;
}

int Action::getPg() const
{
	return this->pG;
}

std::ostream& operator<<(std::ostream& out, const Action& actionFilm)
{
	out << "Title: " << actionFilm.title << std::endl
		<< "Length(in minutes)" << actionFilm.length << std::endl
		<< "Director: " << actionFilm.director << std::endl
		<< "Budget: " << actionFilm.budget << std::endl
		<< "PG: " << actionFilm.pG << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, Action& actionFilm)
{
	std::cout << "Title: ";
	in >> actionFilm.title;

	std::cout << "Length: ";
	in >> actionFilm.length;

	std::cout << "Director: ";
	in >> actionFilm.director;

	std::cout << "Budget: ";
	in >> actionFilm.budget;

	std::cout << "PG: ";
	in >> actionFilm.pG;

	return in;
}

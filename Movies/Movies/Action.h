#pragma once
#include"Movie.h"
class Action : public Movie
{
private:

	int pG;

public:
	Action();
	Action(const char* newTitle, double newLength, const char* newDirector, 
		double newBudget,int newPg);
	
	void setPg(int newPg);
	int getPg()const;

	friend std::ostream& operator<<(std::ostream& out, const Action& actionFilm);
	friend std::istream& operator>>(std::istream& in, Action& actionFilm);
};


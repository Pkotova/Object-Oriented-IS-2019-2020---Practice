#pragma once
#include"Movie.h"

class Cartoon : public Movie
{
private:

	int framesPerSecond;

public:

	Cartoon();
	Cartoon(const char* newTitle, double newLength, const char* newDirector,
		double newBudget, int newFramesPerSecond);

	void setFramesPerSecond(int newFramesPerSecond);
	int getFramesPerSecond()const;

	friend std::ostream& operator<<(std::ostream& out, const Cartoon& cartoon);
	friend std::istream& operator>>(std::istream& in, Cartoon& cartoon);
};


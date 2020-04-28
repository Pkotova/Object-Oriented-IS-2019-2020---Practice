#pragma once
#include"Movie.h"
class Series : public Movie
{
private:

	char* mainCharacter;

	void copy(const Series& series);
	void destroy();

public:

	Series();
	Series& operator=(const Series& series);
	Series(const Series& series);
	~Series();

	void setMainCharacter(const char* newMainCharacter);
	const char* getMainCharacter()const;

	friend std::ostream& operator<<(std::ostream& out, const Series& series);
	friend std::istream& operator>>(std::istream& in, Series& series);
};


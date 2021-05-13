#pragma once
#include"Character.h"
class Knight : public Character
{
private:
	char* title;
	size_t killings;

	void copy(const Knight& other);
	void destroy();
public:

	Knight();
	Knight(const Knight& other);
	Knight(const char* newName, size_t newAge, const char newSex, const char* newTitle, size_t newKillings);
	Knight& operator=(const Knight& other);
	~Knight();

	void setTitle(const char* newTitle);
	const char* getTitle()const;

	void setKillings(size_t newKillings);
	size_t getKillings()const;

	Knight* clone() const;
	int getScore()const;
	void print()const;

};


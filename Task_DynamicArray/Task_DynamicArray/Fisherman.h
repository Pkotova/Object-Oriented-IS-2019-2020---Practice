#pragma once
#include"Fish.h"
class Fisherman
{
private:
	int id;
	char* name;
	int age;
	Fish* caughtFish;
	
	int size;
	int capacity;

	void resizeUp();
	void resizeDown();

	void copy(const Fisherman& other);
	void destroy();

	
public:

	Fisherman();
	Fisherman(const Fisherman& other);
	Fisherman& operator=(const Fisherman& other);
	~Fisherman();

	Fisherman(const char* newName, int newAge, Fish* newCaughtFish, const int& newSize, const int& newCapacity);

	void setName(const char* newName);
	const char* getName()const;

	void setAge(int newAge);
	int getAge()const;

	void setSize(int newSize);
	int getSize()const;

	void setCapacity(int newCapacity);
	int getCapacity()const;

	void addFish(const Fish& fish);
	void removeFish(const int& index);

	Fish* getAllFish()const;

	friend std::ostream& operator<<(std::ostream& out, const Fisherman& current);
	friend std::istream& operator>>(std::istream& in, Fisherman& current);

};


#pragma once
#include"Person.h"
#include"Vector.h"
class Faculty
{
private:

	Vector<Person> people;
	
public:
	Faculty(Vector<Person> other);
	void sort();
	void oldest();
	void students();
	void print();
};


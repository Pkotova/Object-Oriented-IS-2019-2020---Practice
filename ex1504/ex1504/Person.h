#pragma once
#include<iostream>
class Person
{
protected: 
	char* name;
	size_t age;
	char gender; // F,M ... 
	void copy(const Person& other);
	void destroy();
public:
	Person();
	Person(const Person& other);
	Person& operator=(const Person& other);
	~Person();

	void setName(const char* newName);
	void setAge(size_t newAge);
	void setGender(char newGender); // _ = private

	const char* getName()const;
	size_t getAge()const;
	char getGender()const; 

	void print()const;

	friend std::ostream& operator<<(std::ostream& out, const Person& other);
};


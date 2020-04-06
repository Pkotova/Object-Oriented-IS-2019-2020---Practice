#pragma once
#include<iostream>

class Manager
{
	// Manager m;
	// Manager m2;
	// m = m2;
private:

	int id;
	char name[32];
	char lastName[32];
	int age;

	// dynamic memory
	//big 4
	// functions destroy() copy()
public: 

	Manager();
	Manager(int newId, const char* newName, const char* lastName, int newAge);
	//Manager& operator=(const Manager& other);
	~Manager();

	void setId(int newId);
	int getId()const;

	void setName(const char* newName);
	const char* getName() const;

	void setLastName(const char* newLastName);
	const char* getLastName() const;

	void setAge(int newAge);
	int getAge()const;

	friend std::ostream& operator<<(std::ostream& out, const Manager& manager);
	friend std::istream& operator>>(std::istream& in, Manager& manager);
};


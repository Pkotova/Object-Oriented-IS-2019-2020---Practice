#pragma once
#include"Manager.h"
#include <iostream>
class Bank
{
private:
	int id;
	char* name;
	char* centralLocation;
	Manager manager;

	void destroy();
	void copy(const Bank& bank);

public:
	//big 4
	Bank();
	Bank(const Bank& bank);
	Bank& operator=(const Bank& bank);
	Bank(int newId, const char* newName, const char* newCentralLocation, Manager& newManager);
	~Bank();

	void setId(int newId);
	int getId()const;

	void setName(const char* newName);
	const char* getName()const;

	void setCentralLocation(const char* newCentralLocation);
	const char* getCentalLocation()const;
	
	void setManager( const Manager& newManager);
	const Manager& getManager()const;

	friend std::ostream& operator<<(std::ostream& out, const Bank& bank);
	friend std::istream& operator>>(std::istream& out,  Bank& bank);
};

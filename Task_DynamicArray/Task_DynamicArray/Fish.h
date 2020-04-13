#pragma once
#include<iostream>

class Fish
{
private: 
	char* type;
	double weight;
	double price; //per kilo

	void copy(const Fish& other);
	void destroy();

public:

	Fish();
	Fish(const Fish& other);
	Fish& operator=(const Fish& other);
	~Fish();

	Fish(const char* newType, double newWeight, double newPrice);

	void setType(const char* newType);
	const char* getType()const;

	void setWeight(double newWeight);
	double getWeight() const;

	void setPrice(double newPrice);
	double getPrice()const;

	friend std::ostream& operator<<(std::ostream& out, const Fish& current);
	friend std::istream& operator>>(std::istream& in, Fish& current);
};


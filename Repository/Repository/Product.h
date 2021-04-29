#pragma once
#include<iostream>
class Product
{
private:
	char* name;
	size_t quantity;
	double price;

	void copy(const Product& other);
	void destroy();
public:
	Product();
	Product(const char* newName, size_t newQuantity, double newPrice);
	Product(const Product& other);
	Product& operator=(const Product& other);
	~Product();

	void setName(const char* newName);
	const char* getName()const;

	void setQuantity(size_t newQuantity);
	size_t getQuantity()const;

	void setPrice(double newPrice);
	double getPrice()const;

	void print() const;
	friend std::ostream& operator<<(std::ostream& out, const Product& other);
};


#include "Product.h"

void Product::copy(const Product& other)
{
	setName(other.name);
	setQuantity(other.quantity);
	setPrice(other.price);
}

void Product::destroy()
{
	delete[] this->name;
}

Product::Product()
{
	setName("Default");
	setQuantity(0);
	setPrice(0.0);
}

Product::Product(const char* newName, size_t newQuantity, double newPrice)
{
	setName(newName);
	setQuantity(newQuantity);
	setPrice(newPrice);
}

Product::Product(const Product& other)
{
	copy(other);
}

Product& Product::operator=(const Product& other)
{
	if (this != &other)
	{
		//destroy();
		copy(other);
	}
	return *this;
}

Product::~Product()
{
	destroy();
}

void Product::setName(const char* newName)
{
	if (newName != nullptr)
	{
		//destroy();
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}
}

const char* Product::getName() const
{
	return this->name;
}

void Product::setQuantity(size_t newQuantity)
{
	this->quantity = newQuantity;
}

size_t Product::getQuantity() const
{
	return this->quantity;
}

void Product::setPrice(double newPrice)
{
	this->price = newPrice;
}

double Product::getPrice() const
{
	return this->price;
}

void Product::print() const
{
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Quantity: " << this->quantity << std::endl;
	std::cout << "Price: " << this->price << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Product& other)
{
	out << "Name: " << other.name << std::endl;
	out << "Quantity: " << other.quantity << std::endl;
	out << "Price: " << other.price << std::endl;

	return out;
}

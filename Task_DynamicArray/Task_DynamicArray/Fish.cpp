#include "Fish.h"
void Fish::copy(const Fish& other)
{
	setType(other.type);
	setWeight(other.weight);
	setPrice(other.price);
}
void Fish::destroy()
{
	delete[] type;
}

Fish::Fish() : Fish("default", 0.0, 0.0)
{}

Fish::Fish(const Fish & other)
{
	copy(other);
}

Fish& Fish::operator=(const Fish& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

Fish::~Fish()
{
	destroy();
}

Fish::Fish(const char* newType, double newWeight, double newPrice) : type(nullptr)
{
	setType(newType);
	setWeight(newWeight);
	setPrice(newPrice);
}

void Fish::setType(const char* newType)
{
	if (newType != NULL)
	{
		delete[] this->type;
		this->type = new char[strlen(newType) + 1];
		strcpy_s(this->type, strlen(newType) + 1, newType);
	}
}

const char* Fish::getType() const
{
	return this->type;
}

void Fish::setWeight(double newWeight)
{
	this->weight = newWeight;
}

double Fish::getWeight() const
{
	return this->weight;
}

void Fish::setPrice(double newPrice)
{
	this->price = newPrice;
}

double Fish::getPrice() const
{
	return this->price;
}

std::ostream& operator<<(std::ostream& out, const Fish& current)
{
	out << "Type: " << current.type << std::endl
		<< "Weigh: " << current.weight << std::endl
		<< "Price: " << current.price << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, Fish& current)
{
	std::cout << "Type: ";
	in.sync();
	in.getline(current.type, 32);

	std::cout << "Weight: ";
	in >> current.weight;

	std::cout << "Price: ";
	in >> current.price;
	
	return in;
}


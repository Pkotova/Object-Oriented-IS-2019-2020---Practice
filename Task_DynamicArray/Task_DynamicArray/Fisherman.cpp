#include "Fisherman.h"

void Fisherman::resizeUp()
{
	this->capacity *= 2;
	//4 -> 8
	Fish* temp = new Fish[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		temp[i] = this->caughtFish[i];
	}

	destroy();
	this->caughtFish = temp;
}

void Fisherman::resizeDown()
{

	this->capacity /= 2;
	//8 -> 4
	if (this->size < this->capacity)
	{
		Fish* temp = new Fish[this->capacity];
		for (int i = 0; i < this->size; i++)
		{
			temp[i] = this->caughtFish[i];
		}

		delete[]caughtFish;
		this->caughtFish = temp;
	}
	
}

void Fisherman::copy(const Fisherman& other)
{
	setName(other.name);
	setAge(other.age);
	setSize(other.size);
	setCapacity(other.capacity);
	this->caughtFish = new Fish[this->capacity];

	for (int i = 0; i < other.size; i++)
	{
		this->caughtFish[i] = other.caughtFish[i];
	}
}

void Fisherman::destroy()
{
	delete[] name;
	delete[] caughtFish;
}

Fisherman::Fisherman() : name(nullptr)
{
	setName("Default");
	setAge(15);
	setSize(0);
	setCapacity(4);
	this->caughtFish = new Fish[this->capacity];
}

Fisherman::Fisherman(const Fisherman& other)
{
	copy(other);
}

Fisherman& Fisherman::operator=(const Fisherman& other)
{
	if (this != &other)
	{
		delete[] caughtFish;
		copy(other);
	}

	return *this;
}

Fisherman::~Fisherman()
{
	destroy();
}

Fisherman::Fisherman(const char* newName, int newAge, Fish* newCaughtFish, const int& newSize, const int& newCapacity) : name(nullptr)
{
	setName(newName);
	setAge(newAge);
	setSize(newSize);
	setCapacity(newCapacity);
	this->caughtFish = newCaughtFish;
}

void Fisherman::setName(const char* newName)
{
	if (newName != NULL)
	{
		delete[] this->name;
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}
}

const char* Fisherman::getName() const
{
	return this->name;
}

void Fisherman::setAge(int newAge)
{
	(newAge > 0) ? this->age = newAge : this->age = 15;
}

int Fisherman::getAge() const
{
	return this->age;
}

void Fisherman::setSize(int newSize)
{
	(newSize > 0) ? this->size = newSize : this->size = 0;
}

int Fisherman::getSize() const
{
	return this->size;
}

void Fisherman::setCapacity(int newCapacity)
{
	(newCapacity > 0) ? this->capacity = newCapacity : this->capacity = 0;
}

int Fisherman::getCapacity() const
{
	return this->capacity;
}

void Fisherman::addFish(const Fish& fish)
{
	if (this->size == this->capacity)
	{
		resizeUp();
	}
	this->caughtFish[size] = fish;
	size++;
}

void Fisherman::removeFish(const int& index)
{
	if (index < 0 || index > size -1)
	{
		return;
	}

	for (int i = index; i < this->size - 1; i++)
	{
		this->caughtFish[i] = this->caughtFish[i + 1];
	}
	size--;
	resizeDown();
}

Fish* Fisherman::getAllFish() const
{
	return this->caughtFish;
}

std::ostream& operator<<(std::ostream& out, const Fisherman& current)
{
	out << "Name: " << current.name << std::endl
		<< "Age: " << current.age << std::endl;
	for (int i = 0; i < current.size; i++)
	{
		out << current.caughtFish[i];
	}

	return out;
}

std::istream& operator>>(std::istream& in, Fisherman& current)
{
	std::cout << "Name: ";
	in.get();
	in.getline(current.name, 32);

	std::cout << "Age: ";
	in >> current.age;

	for (int i = 0; i < current.size; i++)
	{
		in >> current.caughtFish[i];
	}

	return in;
}


#include "Interpreted.h"
void Interpreted::copy(const Interpreted& other)
{
	ProgrammingLanguage::copy(other);
	setType(other.type);
}

void Interpreted::destroy()
{
	//ProgrammingLanguage::destroy();
	delete[] this->type;
}
Interpreted::Interpreted() : ProgrammingLanguage("Default", 1980, "Default Default", "Default", "Hello World", 0)
{
	setType("Default");
}
Interpreted::Interpreted(const Interpreted& other)
{
	copy(other);
}
Interpreted::Interpreted(const char* newName, size_t newYear, const char* newAuthor, const char* newParadigm, const char* newHelloWorld, size_t newTime, const char* newType)
	:ProgrammingLanguage(newName, newYear, newAuthor, newParadigm, newHelloWorld, newTime)
{
	setType(newType);
}

Interpreted& Interpreted::operator=(const Interpreted& other)
{
	if (this != &other)
	{
		copy(other);
	}

	return *this;
}
Interpreted::~Interpreted()
{
	destroy();
}
void Interpreted::setType(const char* newType)
{
	if (newType != nullptr)
	{
		delete[] this->type;
		this->type = new char[strlen(newType) + 1];
		strcpy_s(this->type, strlen(newType) + 1, newType);
	}
}
const char* Interpreted::getType() const
{
	return this->type;
}

Interpreted* Interpreted::clone() const
{
	return new Interpreted(*this);
}

std::istream& operator>>(std::istream& in, Interpreted& current)
{
	char input[512];

	std::cout << "Name: ";
	in.getline(input, 512);
	current.setName(input);

	std::cout << "Year: ";
	in >> current.year;

	std::cout << "Author: ";
	in.get();
	in.getline(input, 512);
	current.setAuthor(input);

	std::cout << "Paradigm: ";
	in.getline(input, 512);
	current.setPardigm(input);

	std::cout << "Hello World: ";
	in.getline(input, 512);
	current.setHelloWorld(input);

	std::cout << "Time: ";
	in >> current.time;

	std::cout << "Type: ";
	in.get();
	in.getline(input, 512);
	current.setType(input);

	return in;
}

std::ostream& operator<<(std::ostream& out, const Interpreted& current)
{
	out << "Name: " << current.name << std::endl
		<< "Year: " << current.year << std::endl
		<< "Author: " << current.author << std::endl
		<< "Paradigm: " << current.paradigm << std::endl
		<< "Hello World code: " << current.helloWorld << std::endl
		<< "Time: " << current.time << std::endl
		<< "Type: " << current.type << std::endl;

	return out;
}

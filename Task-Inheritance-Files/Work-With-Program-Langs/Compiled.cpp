#include "Compiled.h"

void Compiled::copy(const Compiled& other)
{
	ProgrammingLanguage::copy(other);
	setIDE(other.IDE);
	setlastVersion(other.lastVersion);
}

void Compiled::destroy()
{
	delete[] this->IDE;
	delete[] this->lastVersion;
}

Compiled::Compiled() : ProgrammingLanguage("Default", 1980, "Default Default", "Default", "Hello World", 0)
{
	setIDE("Default");
	setlastVersion("0.0.1");
}

Compiled::Compiled(const char* newName, size_t newYear, const char* newAuthor, const char* newParadigm, const char* newHelloWorld, size_t newTime, const char* newIDE, const char* newLastVersion)
	:ProgrammingLanguage(newName, newYear, newAuthor, newParadigm, newHelloWorld, newTime)
{
	setIDE(newIDE);
	setlastVersion(newLastVersion);
}

Compiled::Compiled(const Compiled& other)
{
	copy(other);
}

Compiled& Compiled::operator=(const Compiled& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

Compiled::~Compiled()
{
	destroy();
}

void Compiled::setIDE(const char* newIDE)
{
	if (newIDE != nullptr)
	{
		delete[] this->IDE;
		this->IDE = new char[strlen(newIDE) + 1];
		strcpy_s(this->IDE, strlen(newIDE) + 1, newIDE);
	}
}

const char* Compiled::getIDE() const
{
	return this->IDE;
}

void Compiled::setlastVersion(const char* newlastVersion)
{
	if (newlastVersion != nullptr)
	{
		delete[] this->lastVersion;
		this->lastVersion = new char[strlen(newlastVersion) + 1];
		strcpy_s(this->lastVersion, strlen(newlastVersion) + 1, newlastVersion);
	}
}

const char* Compiled::getlastVersion() const
{
	return this->lastVersion;
}

Compiled* Compiled::clone() const
{
	return new Compiled(*this);
}

std::istream& operator>>(std::istream& in, Compiled& current)
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

	std::cout << "IDE: ";
	in.get();
	in.getline(input, 512);
	current.setIDE(input);

	std::cout << "Last Version: ";
	in.getline(input, 512);
	current.setlastVersion(input);

	return in;
}

std::ostream& operator<<(std::ostream& out, const Compiled& current)
{
	out << "Name: " << current.name << std::endl
		<< "Year: " << current.year << std::endl
		<< "Author: " << current.author << std::endl
		<< "Paradigm: " << current.paradigm << std::endl
		<< "Hello World code: " << current.helloWorld << std::endl
		<< "Time: " << current.time << std::endl
		<< "IDE: " << current.IDE << std::endl
		<< "Last version: " << current.lastVersion << std::endl;

	return out;
}

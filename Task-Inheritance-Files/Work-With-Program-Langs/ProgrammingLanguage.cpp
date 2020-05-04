#include "ProgrammingLanguage.h"

void ProgrammingLanguage::copy(const ProgrammingLanguage& other)
{
	setName(other.name);
	setYear(other.year);
	setAuthor(other.author);
	setPardigm(other.paradigm);
	setHelloWorld(other.helloWorld);
	setTime(other.time);
}

void ProgrammingLanguage::destroy()
{
	delete[] this->name;
	delete[] this->author;
	delete[] this->paradigm;
	delete[] this->helloWorld;

}

ProgrammingLanguage::ProgrammingLanguage() : name(nullptr), author(nullptr), paradigm(nullptr), helloWorld(nullptr)				
{
	this->setName("Default");
	this->setYear(1989);
	this->setAuthor("Default");
	this->setPardigm("Default");
	this->setHelloWorld("Hello");
	this->setTime(7);
}

ProgrammingLanguage::ProgrammingLanguage(const ProgrammingLanguage& other)
{
	copy(other);
}

ProgrammingLanguage::ProgrammingLanguage(const char* newName, size_t newYear, const char* newAuthor, 
										const char* newParadigm, const char* newHelloWorld, 
										size_t newTime) 
					: name(nullptr),author(nullptr),paradigm(nullptr),helloWorld(nullptr)
{
	this->setName(newName);
	this->setYear(newYear);
	this->setAuthor(newAuthor);
	this->setPardigm(newParadigm);
	this->setHelloWorld(newHelloWorld);
	this->setTime(newTime);
}

ProgrammingLanguage& ProgrammingLanguage::operator=(const ProgrammingLanguage& other)
{
	if (this != &other )
	{
		copy(other);
	}
	return *this;
}

ProgrammingLanguage::~ProgrammingLanguage()
{
	destroy();
}

void ProgrammingLanguage::setName(const char* newName)
{
	if (newName != NULL)
	{
		//delete[] this->name;
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}
}

const char* ProgrammingLanguage::getName() const
{
	return this->name;
}

void ProgrammingLanguage::setYear(size_t newYear)
{
	(newYear >= 1943 && newYear <= 2020) ? this->year = newYear : this->year = 1943;
}

size_t ProgrammingLanguage::getYear() const
{
	return this->year;
}

void ProgrammingLanguage::setAuthor(const char* newAuthor)
{
	if (newAuthor != nullptr)
	{
		//delete[] this->author;
		this->author = new char[strlen(newAuthor) + 1];
		strcpy_s(this->author, strlen(newAuthor) + 1, newAuthor);
	}
}

const char* ProgrammingLanguage::getAuthor() const
{
	return this->author;
}

void ProgrammingLanguage::setPardigm(const char* newParadigm)
{
	if (newParadigm != nullptr)
	{
		//delete[] this->paradigm;
		this->paradigm = new char[strlen(newParadigm) + 1];
		strcpy_s(this->paradigm, strlen(newParadigm) + 1, newParadigm);
	}
}

const char* ProgrammingLanguage::getParadigm() const
{
	return this->paradigm;
}

void ProgrammingLanguage::setHelloWorld(const char* code)
{
	if (code != nullptr)
	{
		//delete[] this->helloWorld;
		this->helloWorld = new char[strlen(code) + 1];
		strcpy_s(this->helloWorld, strlen(code) + 1, code);
	}
}

const char* ProgrammingLanguage::getHelloWorld() const
{
	return this->helloWorld;
}

void ProgrammingLanguage::setTime(size_t newTime)
{
	(newTime > 0) ? this->time = newTime : this->time = 7;
}

size_t ProgrammingLanguage::getTime() const
{
	return this->time;
}
void ProgrammingLanguage::edit(const char* newCode)
{
	setHelloWorld(newCode);
}


std::istream& operator>>(std::istream& in, ProgrammingLanguage& current)
{
	char input[512];

	std::cout << "Name: ";
	in.get();
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

	return in;
}

std::ostream& operator<<(std::ostream& out, const ProgrammingLanguage& current)
{
	out << "Name: " << current.name << std::endl
		<< "Year: " << current.year << std::endl
		<< "Author: " << current.author << std::endl
		<< "Paradigm: " << current.paradigm << std::endl
		<< "Hello World code: " << current.helloWorld << std::endl
		<< "Time: " << current.time << std::endl;

	return out;
}

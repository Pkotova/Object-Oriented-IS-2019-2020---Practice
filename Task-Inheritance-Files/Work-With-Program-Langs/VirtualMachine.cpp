#include "VirtualMachine.h"

void VirtualMachine::copy(const VirtualMachine& other)
{
	ProgrammingLanguage::copy(other);
	setVirualMachine(other.virtualMachine);
}

void VirtualMachine::destroy()
{
	delete[] this->virtualMachine;
}

VirtualMachine::VirtualMachine() : ProgrammingLanguage("Default", 1980, "Default Default", "Default", "Hello World", 0)
{
	setVirualMachine("Default");
}

VirtualMachine::VirtualMachine(const VirtualMachine& other)
{
	copy(other);
}

VirtualMachine::VirtualMachine(const char* newName, size_t newYear, const char* newAuthor, 
	const char* newParadigm, const char* newHelloWorld, size_t newTime, const char* newVirtualMachine)
	:ProgrammingLanguage(newName, newYear, newAuthor, newParadigm, newHelloWorld, newTime)
{
	setVirualMachine(newVirtualMachine);
}

VirtualMachine& VirtualMachine::operator=(const VirtualMachine& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

VirtualMachine::~VirtualMachine()
{
	destroy();
}

void VirtualMachine::setVirualMachine(const char* newVirtualMachine)
{
	if (newVirtualMachine != nullptr)
	{
		delete[] this->virtualMachine; // or calling destroy()
		this->virtualMachine = new char[strlen(newVirtualMachine) + 1];
		strcpy_s(this->virtualMachine, strlen(newVirtualMachine) + 1, newVirtualMachine);
	}
}

const char* VirtualMachine::getVirtualMachine() const
{
	return this->virtualMachine;
}

VirtualMachine* VirtualMachine::clone() const
{
	return new VirtualMachine(*this);
}

std::istream& operator>>(std::istream& in, VirtualMachine& current)
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

	std::cout << "Virtual Machine: ";
	in.get();
	in.getline(input, 512);
	current.setVirualMachine(input);

	return in;
}

std::ostream& operator<<(std::ostream& out, const VirtualMachine& current)
{
	out << "Name: " << current.name << std::endl
		<< "Year: " << current.year << std::endl
		<< "Author: " << current.author << std::endl
		<< "Paradigm: " << current.paradigm << std::endl
		<< "Hello World code: " << current.helloWorld << std::endl
		<< "Time: " << current.time << std::endl
		<< "Virtual Machine: " << current.virtualMachine << std::endl;
	return out;
}

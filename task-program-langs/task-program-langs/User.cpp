#include "User.h"
#include<fstream>
#include<cstring>
#include "Validators.h"

void User::copy(const User& other)
{
	setName(other.name);
	setAge(other.age);
	setProgrammingLanguages(other.languages);

}

void User::destroy()
{
	delete[] this->name;
}


User::User() : name(nullptr)
{
	setName("Default Default");
	setAge(18);
	this->languages = Vector<ProgrammingLanguage*>::Vector<ProgrammingLanguage*>();

}
User::User(const User& other)
{
	copy(other);
}
User::User(const char* newName, size_t newAge)
{
	setName(newName);
	setAge(newAge);
	this->languages = Vector<ProgrammingLanguage*>::Vector<ProgrammingLanguage*>();
}
User::User(const char* newName, size_t newAge, Vector<ProgrammingLanguage*> newProgrammingLanguages)
{
	setName(newName);
	setAge(newAge);
	setProgrammingLanguages(newProgrammingLanguages);
	
}
User& User::operator=(const User& other)
{
	if (this != &other)
	{
		copy(other);
	}
	return *this;
}

User::~User()
{
	destroy();
}
void User::setName(const char* newName)
{
	if (isValidName(newName))
	{
		if (newName != nullptr)
		{
			//delete[] this->name;
			this->name = new char[strlen(newName) + 1];
			strcpy_s(this->name, strlen(newName) + 1, newName);
		}
	}
	else {
		std::cout << "Not valid name! " << std::endl;
	}

}

const char* User::getName() const
{
	return this->name;
}

void User::setAge(size_t newAge)
{
	(newAge >= 7) ? this->age = newAge : this->age = 7;
}

size_t User::getAge() const
{
	return this->age;
}

void User::setProgrammingLanguages(Vector<ProgrammingLanguage*> languages)
{
	for (size_t i = 0; i < languages.getSize(); i++)
	{
		this->languages.push(languages[i]->clone()); // deep copy
	}
}
Vector<ProgrammingLanguage*> User::getProgrammingLanguages()
{
	return this->languages;
}

void User::addLanguage(ProgrammingLanguage& language)
{
	this->languages.push(&language);
}

void User::removeLanguage(int index)
{
	// 
}

int User::calculateTime() const
{
	int time = 0;
	for (size_t i = 0; i < this->languages.getSize(); i++)
	{
		time += languages[i]->getTime();
	}
	return time;
}

std::istream& operator>>(std::istream& in, User& current)
{
	char input[254];

	std::cout << "Name: ";
	in.sync();
	in.getline(input, 254);
	current.setName(input);

	std::cout << "Age: ";
	in >> current.age;

	

	return in;
}

std::ostream& operator<<(std::ostream& out, const User& current)
{
	out << "Name: " << current.name << std::endl
		<< "Age: " << current.age << std::endl;
	if (current.languages.isEmpty())
	{
		std::cout << "No languages added! " << std::endl;
	}
	else {
		for (size_t i = 0; i < current.languages.getSize(); i++)
		{
			out << *current.languages[i];
		}
	}

	return out;
}


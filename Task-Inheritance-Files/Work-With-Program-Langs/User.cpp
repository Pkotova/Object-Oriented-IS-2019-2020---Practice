#include "User.h"
#include<fstream>

void User::resizeUp()
{
	this->capacity *= 2;
	ProgrammingLanguage* temp = new ProgrammingLanguage[this->capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		temp[i] = this->languages[i];
	}

	destroy();
	this->languages = temp;
}

void User::resizeDown()
{
	this->capacity /= 2;
	//8 -> 4
	if (this->size < this->capacity)
	{
		ProgrammingLanguage* temp = new ProgrammingLanguage[this->capacity];
		for (size_t i = 0; i < this->size; i++)
		{
			temp[i] = this->languages[i];
		}

		delete[]languages;
		this->languages = temp;
	}
}

void User::copy(const User& other)
{
	setName(other.name);
	setAge(other.age);
	setFilePath(other.filepath);
	setSize(other.size);
	setCapacity(other.capacity);
	setProgrammingLanguages(other.languages);
}

void User::destroy()
{
	delete[] this->name;
	delete[] this->filepath;
	delete[] this->languages;
}

User::User() : name(nullptr),filepath(nullptr)
{
	setName("Default Default");
	setAge(18);
	setFilePath("users.txt");
	setSize(0);
	setCapacity(8);
	this->languages = new ProgrammingLanguage[this->capacity];
}

User::User(const User& other)
{
	copy(other);
}

User::User(const char* newName, size_t newAge)
{
	setName(newName);
	setAge(newAge);
	setFilePath("users.txt");
	setSize(0);
	setCapacity(8);
	this->languages = new ProgrammingLanguage[this->capacity];
}

User::User(const char* newName, size_t newAge, ProgrammingLanguage* newProgrammingLanguages, const size_t& newSize, const size_t& newCapacity, const char* newFilepath)
{
	setName(newName);
	setAge(newAge);
	setFilePath(newFilepath);
	setSize(newSize);
	setCapacity(newCapacity);
	setProgrammingLanguages(newProgrammingLanguages);
}

User& User::operator=(const User& other)
{
	if (this!=&other)
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
	if (newName != nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
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

void User::setProgrammingLanguages(ProgrammingLanguage* languages)
{
	if (languages != nullptr)
	{
		delete[] this->languages;
		this->languages = new ProgrammingLanguage[this->capacity];
		for (size_t i = 0; i < size; i++)
		{
			this->languages[i] = languages[i];
		}

	}
}

ProgrammingLanguage* User::getProgrammingLanguages() const
{
	return this->languages;
}

void User::setFilePath(const char* filepath)
{
	if (filepath != nullptr)
	{
		delete[] this->filepath;
		this->filepath = new char[strlen(filepath) + 1];
		strcpy_s(this->filepath, strlen(filepath) + 1, filepath);
	}
}

const char* User::getFilepath() const
{
	return this->filepath;
}

bool User::isEmpty() const
{
	return (this -> size == 0);
}

void User::setSize(size_t newSize)
{
	this->size = newSize;
}

size_t User::getSize() const
{
	return this->size;
}

void User::setCapacity(size_t newCapacity)
{
	this->capacity = newCapacity;
}

size_t User::getCapacity() const
{
	return this->capacity;
}

void User::addLanguage(const ProgrammingLanguage &language)
{
	if (this->size == this->capacity)
	{
		resizeUp();
	}
	this->languages[size] = language;
	size++;
}

void User::removeLanguage(const char* languageName)
{	
	size_t index = 0;
	for (size_t i = 0; i < this->size; i++)
	{
		if (strcmp(this->languages[i].getName(),languageName) == 0)
		{
			index = i;
		}
	}
	for (size_t i = index; i < this->size - 1; i++)
	{
		this->languages[i] = this->languages[i + 1];
	}
	size--;
	resizeDown();
}

int User::calculateTime() const
{
	int time = 0;
	for (size_t i = 0; i < size; i++)
	{
		time += languages[i].getTime();
	}
	return time;
}

void User::save()
{
	std::fstream out(this->filepath,std::ios::app);

	out << "Name: " <<this->name << std::endl
		<< "Age: " << this->age << std::endl
		<< "Languages: " << std::endl;
	for (size_t i = 0; i < this->size; i++)
	{
		out << this->languages[i];
	}

	out.close();
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
		<< "Age: " << current.age << std::endl
		<< "Languages: " << std::endl;
	for (size_t i = 0; i < current.size; i++)
	{
		out << current.languages[i];
	}
	out << "Filepath: " << current.filepath << std::endl;
	return out;
}

#include "File.h"
#include<cstring>
#include<iostream>
#include<iomanip>
void File::copy(const File& other)
{
	setName(other.name);
	setDateModified(other.dateModified);
	setType(other.typeOfFile);
	setSize(other.size);
}

void File::destroy()
{
	delete[]this->name;
	delete[]this->dateModified;
}

File::File()
{
	setName("default.txt");
	setDateModified("01.01.2000");
	setType(type::undef);
	setSize(0);
}

File::File(const File& other)
{
	copy(other);
}

File::File(const char* name, const char* date, type type, size_t size)
{
	setName(name);
	setDateModified(date);
	setType(type);
	setSize(size);
}

File& File::operator=(const File& other)
{
	if (this != &other)
	{
		//destroy();
		copy(other);
	}
	return *this;
}

File::~File()
{
}

void File::setName(const char* _name)
{
	if (_name != nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(_name) + 1];
		strcpy_s(this->name, strlen(_name) + 1, _name);
	}
}

const char* File::getName() const
{
	return this->name;
}

void File::setDateModified(const char* _datemodified)
{
	if (_datemodified != nullptr)
	{
		delete[] this->dateModified;
		this->dateModified = new char[strlen(_datemodified) + 1];
		strcpy_s(this->dateModified, strlen(_datemodified) + 1, _datemodified);
	}
}

const char* File::getDateModified() const
{
	return this->dateModified;
}

void File::setType(type _type)
{
	this->typeOfFile = _type;
}

type File::getType() const
{
	return this->typeOfFile;
}

void File::setSize(size_t _size)
{
	this->size = _size;
}

size_t File::getSize() const
{
	return this->size;
}

void File::print()
{
	std::cout << name << std::setw(5) << " | "
		<< dateModified  <<" | ";
	switch (typeOfFile)
	{
	case undef:
		std::cout << "Undefined | ";
		break;
	case archive:
		std::cout << "Archive | ";
		break;
	case shortcut:
		std::cout << "Shortcut | ";
		break;
	case project:
		std::cout << "Project | ";
		break;
	case text_file:
		std::cout << "Text file | ";
		break;
	case script:
		std::cout << "Script | ";
		break;
	case sound_and_music:
		std::cout << "Sound  | ";
		break;
	case data_and_database:
		std::cout << "Data | ";
		break;
	case email:
		std::cout << "Email | ";
		break;
	case executable:
		std::cout << "Application | ";
		break;
	case font:
		std::cout << "Font | ";
		break;
	case image:
		std::cout << "Image | ";
		break;
	case internet_related:
		std::cout << "WEB | ";
		break;
	case presentation:
		std::cout << "Presentation | ";
		break;
	case programming:
		std::cout << "Programming language file | ";
		break;
	case spreadsheet:
		std::cout << "Spreadsheet | ";
		break;
	case system_related:
		std::cout << "System related | ";
		break;
	case video:
		std::cout << "Video | ";
		break;
	default:
		break;
	}
	std::cout << size << "KB  " << std::endl;
	std::cout << "--------------------------------------------------------------" << std::endl;
}

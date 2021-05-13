#pragma once
#include"TypeOfFile.h"
class File
{
private:
	char* name;
	char* dateModified;
	type typeOfFile;
	size_t size;

	void copy(const File& other);
	void destroy();

public:
	File();
	File(const File& other);
	File(const char* name, const char* date, type type, size_t size);
	File& operator=(const File& other);
	~File();

	void setName(const char* _name);
	const char* getName()const;

	void setDateModified(const char* _datemodified);
	const char* getDateModified()const;

	void setType( type _type);
	type getType()const;

	void setSize(size_t _size);
	size_t getSize()const;

	void print();
};


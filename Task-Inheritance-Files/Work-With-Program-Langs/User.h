#pragma once
#include"ProgrammingLanguage.h"
class User
{
private:
	char* name;
	size_t age;
	ProgrammingLanguage* languages;

	char* filepath;

	size_t capacity;
	size_t size;

	void resizeUp();
	void resizeDown();

	void copy(const User& other);
	void destroy();
public:

	User();
	User(const User& other);
	User(const char* newName, size_t newAge);
	User(const char* newName, size_t newAge, 
		ProgrammingLanguage* newProgrammingLanguages,
		const size_t& newSize, const size_t& newCapacity, const char* newFilepath);
	User& operator=(const User& other);
	~User();

	void setName(const char* newName);
	const char* getName() const;

	void setAge(size_t newAge);
	size_t getAge()const;

	void setProgrammingLanguages(ProgrammingLanguage* languages);
	ProgrammingLanguage* getProgrammingLanguages()const;

	void setFilePath(const char* filepath);
	const char* getFilepath()const;

	bool isEmpty() const;

	void setSize(size_t newSize);
	size_t getSize()const;

	void setCapacity(size_t newCapacity);
	size_t getCapacity()const;

	void addLanguage(const ProgrammingLanguage& language);
	void removeLanguage(const char* languageName);

	int calculateTime() const;

	friend std::istream& operator>>(std::istream& in, User& current);
	friend std::ostream& operator<<(std::ostream& out, const User& current);

	void save();
};


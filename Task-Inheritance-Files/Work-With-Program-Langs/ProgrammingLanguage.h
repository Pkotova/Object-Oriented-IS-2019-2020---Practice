#pragma once
#include <iostream>
class ProgrammingLanguage
{
protected:

	char* name;
	size_t year;
	char* author;
	char* paradigm;
	char* helloWorld;
	size_t time;

	void copy(const ProgrammingLanguage& other);
	void destroy();

public:

	ProgrammingLanguage();
	ProgrammingLanguage(const ProgrammingLanguage& programmingLanguage);
	ProgrammingLanguage(const char* newName, size_t newYear, const char* newAuthor, 
						const char* newParadigm, const char* newHelloWorld,
						size_t newTime);
	ProgrammingLanguage& operator= (const ProgrammingLanguage& other);
	virtual ~ProgrammingLanguage() = 0;

	void setName(const char* newName);
	const char* getName()const;

	void setYear(size_t newYear);
	size_t getYear()const;

	void setAuthor(const char* newAuthor);
	const char* getAuthor() const;

	void setPardigm(const char* newParadigm);
	const char* getParadigm() const;

	void setHelloWorld(const char* code);
	const char* getHelloWorld()const;

	void setTime(size_t newTime);
	size_t getTime()const;

	void edit(const char* newCode);

	virtual ProgrammingLanguage* clone() const = 0;

	friend std::istream& operator>>(std::istream& in, ProgrammingLanguage& current);
	friend std::ostream& operator<<(std::ostream& out, const ProgrammingLanguage& current);
};


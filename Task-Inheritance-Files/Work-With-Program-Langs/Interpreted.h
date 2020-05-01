#pragma once
#include"ProgrammingLanguage.h"
class Interpreted : public ProgrammingLanguage
{
private:
	char* type;
	void copy(const Interpreted& other);
	void destroy();
public:
	Interpreted();
	Interpreted(const Interpreted& other);
	Interpreted(const char* newName, size_t newYear, const char* newAuthor,
		const char* newParadigm, const char* newHelloWorld,
		size_t newTime, const char* newType);
	Interpreted& operator=(const Interpreted& other);
	~Interpreted();

	void setType(const char* newType);
	const char* getType()const;

	friend std::istream& operator>>(std::istream& in, Interpreted& current);
	friend std::ostream& operator<<(std::ostream& out, const Interpreted& current);
};


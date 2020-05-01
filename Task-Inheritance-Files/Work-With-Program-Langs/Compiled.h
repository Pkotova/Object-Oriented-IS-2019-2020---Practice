#pragma once
#include"ProgrammingLanguage.h"
class Compiled : public ProgrammingLanguage
{
private:
	char* IDE;
	char* lastVersion;

	void copy(const Compiled& other);
	void destroy();
public:
	Compiled();
	Compiled(const char* newName, size_t newYear, const char* newAuthor,
		const char* newParadigm, const char* newHelloWorld,
		size_t newTime, const char* newIDE, const char* newLastVersion);
	Compiled(const Compiled& other);
	Compiled& operator=(const Compiled& other);
	~Compiled();

	void setIDE(const char* newIDE);
	const char* getIDE()const;

	void setlastVersion(const char* newlastVersion);
	const char* getlastVersion()const;

	friend std::istream& operator>>(std::istream& in, Compiled& current);
	friend std::ostream& operator<<(std::ostream& out, const Compiled& current);

};


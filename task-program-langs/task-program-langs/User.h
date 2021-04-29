#pragma once
#include"Vector.h"
#include"ProgrammingLanguage.h"

class User
{
private:
	char* name; // two names, ', - ; Mathias d'Arras, Hector Sausage-Heusen, Kalin Georgiev
	size_t age;
	Vector<ProgrammingLanguage*> languages;

	void copy(const User& other);
	void destroy();
public:
	User();
	User(const User& other);
	User(const char* newName, size_t newAge);
	User(const char* newName, size_t newAge,Vector<ProgrammingLanguage*> newProgrammingLanguages);
	User& operator=(const User& other);
	~User();

	void setName(const char* newName);
	const char* getName() const;

	void setAge(size_t newAge);
	size_t getAge()const;

	void setProgrammingLanguages(Vector<ProgrammingLanguage*> languages);
	Vector<ProgrammingLanguage*> getProgrammingLanguages();

	void addLanguage(ProgrammingLanguage& language);
	void removeLanguage(int index);

	int calculateTime() const;

	friend std::istream& operator>>(std::istream& in, User& current);
	friend std::ostream& operator<<(std::ostream& out, const User& current);
};


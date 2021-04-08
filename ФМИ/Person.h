#pragma once
class Person
{
private:

	char* name; // regex!?
	size_t age; // < 18
	bool isStudent; // 1 = student, 0 = other..
	void copy(const Person& other);
	void erase();

public:

	Person();
	Person(const char* name, size_t age, bool isStudent);
	Person(const Person& other);
	Person& operator=(const Person& other);
	~Person();

	void setName(const char* newName);
	void setAge(size_t age);
	void setIsStudent(bool newIsStudent);

	const char* getName()const;
	size_t getAge() const;
	bool getIsStudent()const;
	void print()const;
};


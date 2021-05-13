#pragma once
class Character
{
protected:
	char* name;
	size_t age;
	char sex;
	
	void copy(const Character& other);
	void destroy();

public:
	Character();
	Character(const Character& other);
	Character(const char* newName, size_t newAge, char newSex);
	Character& operator= (const Character& other);
	virtual ~Character() = 0;

	void setName(const char* newName);
	const char* getName()const;

	void setAge(size_t newAge);
	size_t getAge()const;

	void setSex(char newSex);
	char getSex()const;

	void show()const;
	virtual int getScore()const = 0;
	virtual void print() const = 0;
	virtual Character* clone() const = 0;

	bool operator==(const Character& other) const;
};
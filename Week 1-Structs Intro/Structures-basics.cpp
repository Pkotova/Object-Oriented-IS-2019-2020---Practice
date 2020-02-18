#include "pch.h"
#include <iostream>
#include<cstring>

//we dont use using namespace std anymore
//we use std::cin,std::cout,std::endl instead

struct Subject
{
private: //incapsulation, hidden from the user 
	//fields
	int id;
	int amountOfStudent;
	double credits;

public: //public part, methods etc.
	//we declarate setters and getters for all of the fields
	//we can call 'setters & getters' mutators(мутатори)
	void setId(int newId) 
		//it is possible to define the methods here (when methods are few)
		//but i dont recomment this way, just to know! 
	{
		this->id = newId;
	}
	int getId()const
	{
		return (this->id);
	}

	void setAmountOfStudents(int newAmountOfStudents);
	int getAmountOfStudents()const; 
	//we usually use const with getters, we will understand why and 
	//what it means soon 

	void setCredits(double newCredits);
	double getCredits()const;
};

void Subject::setAmountOfStudents(int newAmountOfStudents)
{
	this->amountOfStudent = newAmountOfStudents;
}
int Subject::getAmountOfStudents()const
{
	return (this->amountOfStudent);
}
void Subject::setCredits(double newCredits)
{
	this->credits = newCredits;
}
double Subject::getCredits()const
{
	return (this->credits);
}

int main()
{
//static object. Instance of type Subject(struct)
	Subject s1;

	//you can use variables for parameters
	int id, amountOfStudents;
	char profesor;
	
	//never forget the user interface
	std::cout << "Input ID: ";
	std::cin >> id;
	s1.setId(id); //setting the value of (s1.id) with a value entered from the keyboard

	std::cout << "Input Amount of students: ";
	std::cin >> amountOfStudents;
	s1.setAmountOfStudents(amountOfStudents);

	//you can use const parameters like this
	s1.setCredits(5.5); 

	// we can display the result by using std::cout and getters and .
	std::cout << "Subject 1: " << std::endl;
	std::cout << "ID:" << s1.getId() << std::endl;
	std::cout << "Amount of Students:" << s1.getAmountOfStudents() << std::endl;
	std::cout << "Credits:" << s1.getCredits() << std::endl;

//dynamic object. Instance of type Subject(struct)
	Subject* s2 = new Subject; // 'new'is used when we use dynamic memory
	//another possible way
	Subject* s3;
	s3 = new Subject;
	//when we use pointers, we use '->' instead of '.'
	s2->setId(3);
	s2->setAmountOfStudents(100);
	s2->setCredits(7);

	// we can display the result by using std::cout and getters and ->
	std::cout << "Subject 2: " << std::endl;
	std::cout << "ID:"<< s2->getId() << std::endl;
	std::cout << "Amount of Students:" << s2->getAmountOfStudents() << std::endl;
	std::cout << "Credits:" << s2->getCredits() << std::endl;

	// if we try to display the data of s3(we have not initialized it!)
	// we will recieve random value from the dynamic memory,
	// because we haven't default constructor yet! 
	// sooon <3
	std::cout << s3->getId() << std::endl; 

//IT IS ABOSULETY NESSECARRY TO DELETE USED DYNAMIC MEMORY (s2,s3)
	delete s2;
	delete s3;

	//if there are any questions DM me <3 
	// love. Petya <3
}


#pragma once
#include<iostream>
#include"Enumerators.h"

class MyProject
{
private:
	//data - fields

	int id;
	char* projectName;
	int amountOfContributors;
	char* teamName;
	char* projectManager;
	status projectStatus;

	//we are using enum
	//https://en.cppreference.com/w/cpp/language/enum 
	//read more here

public:
	/*canonical representation or BIG FOUR
												- default constructor
												- copy constructor
												- Copy assignment operator (operator=)
												- destructor
	*/
	MyProject();										//default constructor, we all know <3
	MyProject(const MyProject& other);					// copy constructor
	MyProject& operator=(const MyProject& other);		// operator=
	~MyProject();										// destructor - sintax: ~className 

	MyProject(int newId, const char* newProjectName, int newAmountOfContributors,			//general purpose constructor
		const char* newTeamName, const char* newProjectManager, status newProjectStatus);

	//setters & getters
	void setId(int newId);
	int getId()const;

	void setProjectName(const char* newProjectName);
	const char* getProjectName()const;

	void setAmountOfContributors(int newAmountOfContributors);
	int getAmountOfContributors()const;

	void setTeamName(const char* newTeamName);
	const char* getTeamName()const;

	void setProjectManager(const char* newProjectManager);
	const char* getProjectManager()const;

	void setProjectStatus(status newStatus);
	status getProjectStatus()const;

	//overloading I/O operators (>>,<<)
	friend std::ostream& operator<<(std::ostream& out, const MyProject& other);
	friend std::istream& operator>>(std::istream& in, MyProject& other);

	/* friend functions
			friend function can be given special grant to access private and protected members.
	*/
};


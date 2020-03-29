#include<cstring>
#include "MyProject.h"

MyProject::MyProject() : projectName(nullptr),teamName(nullptr),projectManager(nullptr)
{
//set default values for each field
	setId(0);
	setProjectName("Default Project");
	setAmountOfContributors(0);
	setTeamName("Default TeamName");
	setProjectManager("Default Default");
	setProjectStatus(inDefault);
}

MyProject::MyProject(const MyProject& other)
{
	this->setId(other.id);
	this->setProjectName(other.projectName);
	this->setAmountOfContributors(other.amountOfContributors);
	this->setTeamName(other.teamName);
	this->setProjectManager(other.projectManager);
	this->setProjectStatus(other.projectStatus);
}

MyProject& MyProject::operator=(const MyProject& other)
{
	if (this != &other)
	{
		this->setId(other.id);
		this->setProjectName(other.projectName);
		this->setAmountOfContributors(other.amountOfContributors);
		this->setTeamName(other.teamName);
		this->setProjectManager(other.projectManager);
		this->setProjectStatus(other.projectStatus);
	}
	return *this;
}

MyProject::~MyProject()
{
	std::cout << "Memory released" << std::endl; // just to know where the destructor is called. ; 
	delete[] this->teamName;
	delete[] this->projectName;
	delete[] this->projectManager;
}

MyProject::MyProject(int newId, const char* newProjectName, int newAmountOfContributors, 
					const char* newTeamName, const char* newProjectManager, status newProjectStatus)
					: projectName(nullptr), teamName(nullptr), projectManager(nullptr)
{
	this->setId(newId);
	this->setProjectName(newProjectName);
	this->setAmountOfContributors(newAmountOfContributors);
	this->setTeamName(newTeamName);
	this->setProjectManager(newProjectManager);
	this->setProjectStatus(newProjectStatus);
}

void MyProject::setId(int newId)
{
	this->id = newId;
}

int MyProject::getId() const
{
	return this->id;
}

void MyProject::setProjectName(const char* newProjectName)
{
	if (newProjectName != NULL) {
		delete[] this->projectName;
		this->projectName = new char[strlen(newProjectName) + 1];
		strcpy_s(this->projectName, strlen(newProjectName) + 1, newProjectName);
	}
}

const char* MyProject::getProjectName() const
{
	return this->projectName;
}

void MyProject::setAmountOfContributors(int newAmountOfContributors)
{
	this->amountOfContributors = newAmountOfContributors;
}

int MyProject::getAmountOfContributors() const
{
	return this->amountOfContributors;
}

void MyProject::setTeamName(const char* newTeamName)
{
	if (newTeamName != NULL) {
		delete[] this->teamName;
		this->teamName = new char[strlen(newTeamName) + 1];
		strcpy_s(this->teamName, strlen(newTeamName) + 1,newTeamName);
	}
}

const char* MyProject::getTeamName() const
{
	return this->teamName;
}

void MyProject::setProjectManager(const char* newProjectManager)
{
	if (newProjectManager != NULL) {
		delete[] this->projectManager;
		this->projectManager = new char[strlen(newProjectManager) + 1];
		strcpy_s(this->projectManager, strlen(newProjectManager) + 1,newProjectManager);
	}
}

const char* MyProject::getProjectManager() const
{
	return this->projectManager;
}

void MyProject::setProjectStatus(status newProjectStatus)
{
	switch (newProjectStatus) //this way each number corresponse for each status
	{
		case 0:
		{
			this->projectStatus = inDefault;
			break;
		}
		case 1:
		{
			this->projectStatus = inDesign;
			break;
		}
			
		case 2:
		{
			this->projectStatus = inVisualization;
			break;
		}
			
		case 3:
		{

			this->projectStatus = inDeveloping;
			break;
		}
		case 4:
		{
			this->projectStatus = inProduction;
			break;
		}
			
		case 5:
		{

			this->projectStatus = done;
			break;
		}
		default:
		{
			std::cout << "Wrong!";
			break;
		};
	}
}

status MyProject::getProjectStatus() const
{
	return this->projectStatus;
}

std::ostream& operator<<(std::ostream& out, const MyProject& current)
{
	out << "ID: " << current.id << std::endl
		<< "Project Name: " << current.projectName << std::endl
		<< "Amount contributors: " << current.amountOfContributors << std::endl
		<< "Team name: " << current.teamName << std::endl
		<< "Project manager: " << current.projectManager << std::endl
		<< "Status: " << current.projectStatus << std::endl;

	return out;
}

std::istream& operator>>(std::istream& in, MyProject& current)
{
	int status; 
	std::cout << "Id: ";
	in >> current.id;

	std::cout << "Project name: ";
	in.get();
	in.getline(current.projectName, 128);

	std::cout << "Amount of contributors: ";
	in >> current.amountOfContributors;

	std::cout << "Team name: ";
	in.get();
	in.getline(current.teamName, 128);

	std::cout << "Project manager: ";
	in.get();
	in.getline(current.projectManager, 128);

	std::cout << "Status: (inDesign, inVisualization, inDeveloping, inProduction, done) ";
	in >> status;

	switch (status)
	{
		case 0:
		{
			current.setProjectStatus(inDefault);
			break;
		}

		case 1:
		{
			current.setProjectStatus(inDesign);
			break;
		}

		case 2:
		{
			current.setProjectStatus(inVisualization);
			break;
		}

		case 3:
		{
			current.setProjectStatus(inDeveloping);
			break;
		}

		case 4:
		{
			current.setProjectStatus(inProduction);
			break;
		}

		case 5:
		{
			current.setProjectStatus(done);
			break;
		}

		default:
		{
			std::cout << "Wrong!";
			break;
		};
	}

	return in;
}
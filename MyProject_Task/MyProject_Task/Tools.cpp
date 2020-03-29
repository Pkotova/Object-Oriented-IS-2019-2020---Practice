#include"Tools.h";
#include"Enumerators.h";

MyProject& merge(MyProject& other, MyProject& another, const char* newTeamName)
{
	MyProject* newProject = new MyProject();

	int contributorsInNewProject = other.getAmountOfContributors() + another.getAmountOfContributors();
	int idOfNewProject = other.getAmountOfContributors() + another.getAmountOfContributors();

	newProject->setId(idOfNewProject);
	newProject->setAmountOfContributors(contributorsInNewProject);

	newProject->setProjectManager(another.getProjectManager());

	newProject->setProjectName(other.getProjectName());

	newProject->setTeamName(newTeamName);
	newProject->setProjectStatus(inDefault);

	return *newProject;
}

MyProject& hasTheMostContributors(MyProject* projects, int size)
{
	MyProject hasMostContributors = projects[0];
	for (size_t i = 0; i < i; i++)
	{
		if (projects[i].getAmountOfContributors() > hasMostContributors.getAmountOfContributors())
		{
			hasMostContributors = projects[i];
		}
	}
	return hasMostContributors;
}

void swap(MyProject* other, MyProject* another)
{
	MyProject temp = *other;
	*other = *another;
	*another = temp;
}
//for sorting we use array of pointer because its much better to 
// swap only pointer rather than whole blocks of memory

void sort(MyProject** projects, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (projects[j]->getAmountOfContributors() < projects[j + 1]->getAmountOfContributors())
			{
				swap(projects[j], projects[j + 1]);
			}
		}
	}
}

MyProject& merge(MyProject& other, MyProject& another, const char* newTeamName)
{
	MyProject* newProject = new MyProject();

	int contributorsInNewProject = other.getAmountOfContributors() + another.getAmountOfContributors();
	int idOfNewProject = other.getAmountOfContributors() + another.getAmountOfContributors();

	newProject->setId(idOfNewProject);
	newProject->setAmountOfContributors(contributorsInNewProject);

	newProject->setProjectManager(another.getProjectManager());

	newProject->setProjectName(other.getProjectName());

	newProject->setTeamName(newTeamName);
	newProject->setProjectStatus(inDefault);

	return *newProject;
}

MyProject& hasTheMostContributors(MyProject* projects, int size)
{
	MyProject hasMostContributors = projects[0];
	for (size_t i = 0; i < i; i++)
	{
		if (projects[i].getAmountOfContributors() > hasMostContributors.getAmountOfContributors())
		{
			hasMostContributors = projects[i];
		}
	}
	return hasMostContributors;
}

void swap(MyProject* other, MyProject* another)
{
	MyProject temp = *other;
	*other = *another;
	*another = temp;
}
//for sorting we use array of pointer because its much better to 
// swap only pointer rather than whole blocks of memory

void sort(MyProject** projects, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (projects[j]->getAmountOfContributors() < projects[j + 1]->getAmountOfContributors())
			{
				swap(projects[j], projects[j + 1]);
			}
		}
	}
}

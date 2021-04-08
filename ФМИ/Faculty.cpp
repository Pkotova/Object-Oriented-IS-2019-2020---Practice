#include "Faculty.h"

Faculty::Faculty(Vector<Person> other)
{
	this->people = other;
}

void Faculty::sort()
{
	for (size_t i = 0; i < people.getSize() - 1; i++)
	{
		for (size_t j = 0; j < people.getSize() - 1 - i; j++)
		{
			if (strcmp(people[j].getName(), people[j + 1].getName()) > 0)
			{
				Person temp = people[j];
				people[j] = people[j + 1];
				people[j + 1] = temp;
			}
		}
	}
}

void Faculty::oldest()
{
	int max = people[0].getAge();
	Person p; 
	for (size_t i = 0; i < people.getSize(); i++)
	{
		if (max < people[i].getAge())
		{
			max = people[i].getAge();
			p = people[i];
		}
	}

	p.print();
}

void Faculty::students()
{
	for (size_t i = 0; i < people.getSize(); i++)
	{
		if (people[i].getIsStudent())
		{
			people[i].print();
		}
	}
}

void Faculty::print()
{
	for (size_t i = 0; i < people.getSize(); i++)
	{
		people[i].print();
	}
}

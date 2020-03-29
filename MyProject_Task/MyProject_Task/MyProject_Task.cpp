#include <iostream>
#include"MyProject.h"
#include"Enumerators.h"
#include"Tools.h";

int main()
{

	// default constructor
	MyProject defaultProject;
	//    std::cout << defaultProject;    //usage of Output operator for object

	// general purpose constructor (With parameters)
	MyProject project1(1, "The game has end", 6, "Incredibles", "Kaloyan Todorov", inDesign);

	// copy constructor
	MyProject project2(project1); //project 2 now has the same values as project1

// operator= 
	MyProject project3(3, "Spin the bottle", 7, "Power", "Krasimir Cvetkov", inDeveloping);
	MyProject project4 = project3; //project 4 has the same values as project3

	MyProject project5(3, "Pink Pong", 3, "Flower", "Mitko", inProduction);
	MyProject* projects[3];

	/*   for (size_t i = 0; i < 3; i++)
		{
			 std::cin >> projects[i];
		}
	*/
	projects[0] = &project1;
	projects[1] = &project4;
	projects[2] = &project5;

	std::cout << merge(*projects[0], *projects[2], "Fast and furious");

	//you can also create new object and assign the "merged" one  like this
	MyProject* newProject = new MyProject();
	newProject = &merge(*projects[0], *projects[2], "Fast and furious");

	//and then just print the newProject;
	std::cout << *newProject;
	std::cout << "____________________" << std::endl;

	//descending sorting 
	sort(projects, 3);
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << *projects[i];
	}
	// if you want to delete any object you call the destructor
	// after finishing the program you have to be sure that all of the used dynamic memory is free
}


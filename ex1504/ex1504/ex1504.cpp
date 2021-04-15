#include <iostream>

#include"Comedy.h"

int main()
{
		Actor a("Emilia Clark", 35, 'f', 1, 10),
			a1("Jim Carry", 40, 'm', 0, 30),
			a2("Arnold Swartzeneger", 50, 'm', 1, 15),
			a3("Tom Holand", 43, 'm', 0, 5);
		Vector<Actor> cast;
		cast.push(a);
		cast.push(a1);
		cast.push(a2);
		cast.push(a3);

		Film f("Heroes", 2000, cast, 10);
		f.setTitle("Incredible");
		Comedy c(f, 0);

		std::cout << c << std::endl;	
}


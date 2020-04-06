// Banks.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include"Bank.h"
#include"Manager.h"

int main()
{
    Bank b;

    Manager m(1, " Kaloyan", "Todorov", 30);

    Bank b1(1, "RaiffBank", "Wien", m);

    b.setManager(m);
    //std::cout << b.getManager();
   /* std::cout << b;
    std::cout << b1;*/
    Bank b3(b1);
  //  std::cout << b3;

    Bank b4;
    std::cin >> b4;
    std::cout << b4;

    Bank* banks = new Bank[2];
    for (size_t i = 0; i < 2; i++)
    {
        std::cin >> banks[i];
        std::cout << std::endl;
        std::cout << banks[i];
    }

}


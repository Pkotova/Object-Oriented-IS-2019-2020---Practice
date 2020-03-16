#include <iostream>
#include "Medicine.h"
#include"Templates.cpp"
using std::cout;
using std::cin;
using std::endl;

const int amount = 5;

int main()
{
   /* Medicine medicine1;
    medicine1.input();
    medicine1.output();
    */
   Medicine medicines[amount];
    for (size_t i = 0; i < amount; i++)
    {
        medicines[i].input();
        cin.get();
    }

    for (size_t i = 0; i < amount; i++)
    {
        medicines[i].output();
    }

   cout<< larger(medicines[1].getMg(), medicines[2].getMg());
}


#include <iostream>
#include "Medicine.h"
#include"Templates.cpp"


using std::cout;
using std::cin;
using std::endl;

const int amount = 5;

int main()
{
    Medicine* m = new Medicine();
    Medicine* m1 = new Medicine(450);
   
    m1->setPrice(4.5);
     m1->output();
}


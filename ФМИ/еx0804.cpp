#include <iostream>
#include"Vector.h"
#include"Person.h"
#include"Faculty.h"
int main()
{
    //Vector<int> v;
    //v.push(2);
    //v.push(5);
    //v.push(102);
    //v.push(533);
    //v.push(52);
    //v.push(235);
    //v.pop();
    //v.print();
    //std::cout <<v[3] << std::endl;
    //std::cout <<std::boolalpha<<v.isEmpty() << std::endl;

    Person p("Ivan Ivanov", 23, 1),
        p2("Georgi Nizamov", 45, 0),
        p3("Milko Takev", 102, 0),
        p4("Evgenia Velikova", 50, 0), 
        p5("Vladimir Dimitrov", 20, 1);

    Vector<Person> v;
    v.push(p);
    v.push(p2);
    v.push(p3);
    v.push(p4);
    v.push(p5);
    Faculty f(v);

    f.sort();
   //f.students();
    f.print();
    //f.oldest();
}

#include"Medicine.h"
#include<cstring>
template<typename T>
T larger(T fieldA, T fieldB)
{
	return operator>(fieldA > fieldB) ? fieldA : fieldB;
}

bool operator>(Medicine m1, Medicine m2) 
{
	return (m1.getMg() > m2.getMg() && m1.getPrice > m2.getPrice() && (strcmp(m1.getName(), m2.getName()))) ? true : false;
}
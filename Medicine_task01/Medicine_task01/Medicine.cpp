#include "Medicine.h"
#include <cstring>
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void Medicine::setName(char newName[32])
{
	strcpy_s(this->name, 32, newName);
}

const char* Medicine::getName() const
{
	return this->name;
}

void Medicine::setMg(int newMg)
{
	this->mg = newMg;
}

int Medicine::getMg() const
{
	return this->mg;
}

void Medicine::setPrice(double newPrice)
{
	this->price = newPrice;
}

double Medicine::getPrice() const
{
	return this->price;
}

void Medicine::input()
{
	cout << "Input name: ";
	cin.getline(this->name, 32);
	cout << "Input Mg: ";
	cin >> this->mg;
	cout << "Input price: ";
	cin >> this->price;
}
void Medicine::output()const
{
	cout << "Name: " << this->name << endl;
	cout << "Mg: " << this->mg << endl;
	cout << "Price: " << this->price << endl;
}
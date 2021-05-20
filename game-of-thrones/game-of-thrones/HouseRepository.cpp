#include "HouseRepository.h"
#include<iostream>
#include<fstream>
void HouseRepository::copy(const HouseRepository& other)
{
    setFilepath(other.filepath);
}

void HouseRepository::destroy()
{
    delete[] this->filepath;
}

HouseRepository::HouseRepository()
{
    setFilepath("houses.txt");
}

HouseRepository::HouseRepository(const HouseRepository& other)
{
    copy(other);
}

HouseRepository& HouseRepository::operator=(const HouseRepository& other)
{
    if (this != &other)
    {
        copy(other);
    }
    return *this;
}

HouseRepository::~HouseRepository()
{
    destroy();
}

void HouseRepository::setFilepath(const char* newFilepath)
{
    if (newFilepath != nullptr)
    {
        this->filepath = new char[strlen(newFilepath) + 1];
        strcpy_s(this->filepath, strlen(newFilepath) + 1, newFilepath);
    }
}

void HouseRepository::add(House& house)
{
    std::ofstream out(this->filepath, std::ios::app);
    out << house.getName() << std::endl
        << house.getLocation() << std::endl
        << house.getHouseWords() << std::endl;
    
    out.close();
}

void HouseRepository::update(House& house)
{
    //
}

void HouseRepository::remove(House& house)
{
    //
}


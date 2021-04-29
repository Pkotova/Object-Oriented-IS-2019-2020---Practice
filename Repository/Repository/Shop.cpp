#include "Shop.h"

void Shop::copy(const Shop& other)
{
	setName(other.name);
	setAddress(other.address);
	setOwner(other.owner);
	setInventory(other.inventory);
}

void Shop::destroy()
{
	delete[]this->name;
	delete[]this->address;
	delete[]this->owner;
}

Shop::Shop()
{
	setName("Default ltd");
	setAddress("Default st. 00");
	setOwner("Default Default");
	setInventory(Vector<Product>::Vector<Product>());
}

Shop::Shop(const Shop& other)
{
	copy(other);

}

Shop& Shop::operator=(const Shop& other)
{
	if (this != &other)
	{
		//destroy();
		copy(other);
	}
	return *this;
}

Shop::~Shop()
{
	destroy();
}

void Shop::setName(const char* newName)
{
	if (newName != nullptr)
	{
		delete[] this->name;
		this->name = new char[strlen(newName) + 1];
		strcpy_s(this->name, strlen(newName) + 1, newName);
	}
}


const char* Shop::getName() const
{
	return this->name;
}

void Shop::setAddress(const char* newAddress)
{
	if (newAddress != nullptr)
	{
		delete[] this->address;
		this->address = new char[strlen(newAddress) + 1];
		strcpy_s(this->address, strlen(newAddress) + 1, newAddress);
	}
}

const char* Shop::getAddress() const
{
	return this->address;
}

void Shop::setOwner(const char* newOwner)
{
	if (newOwner != nullptr)
	{
		delete[] this->owner;
		this->owner = new char[strlen(newOwner) + 1];
		strcpy_s(this->owner, strlen(newOwner) + 1, newOwner);
	}
}

const char* Shop::getOwner() const
{
	return this->owner;
}

void Shop::setInventory(const Vector<Product>& newInventory)
{
	this->inventory = newInventory;
}

const Vector<Product>& Shop::getInventory() const
{
	return this->inventory;
}

std::ostream& operator<<(std::ostream& out, const Shop& other)
{
	out << "-----------------------" << std::endl;
	out << "|        MY SHOP      |" << std::endl;
	out << "-----------------------" << std::endl;
	out << "Name: " << other.name << std::endl;
	out << "Address: " << other.address << std::endl;
	out << "Ownew: " << other.owner << std::endl;
	out << "-----------------------" << std::endl;
	out << "|        INVENTORY     |" << std::endl;

	for (size_t i = 0; i < other.inventory.getSize(); i++)
	{
		out << "-----------------------" << std::endl;
		other.inventory[i].print();
	}
	out << "-----------------------" << std::endl;
	return out;
}

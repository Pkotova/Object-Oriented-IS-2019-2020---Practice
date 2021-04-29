#pragma once
#include"Vector.h"
#include"Product.h"
class Shop
{
private:
	char* name;
	char* address;
	char* owner;
	Vector<Product> inventory;

	void copy(const Shop& other);
	void destroy();
public:
	Shop();
	Shop(const Shop& other);
	Shop& operator= (const Shop& other);
	~Shop();

	void setName(const char* newName);
	const char* getName() const;

	void setAddress(const char* newAddress);
	const char* getAddress() const;

	void setOwner(const char* newOwner);
	const char* getOwner() const;

	void setInventory(const Vector<Product>& newInventory);
	const Vector<Product>& getInventory()const;

	friend std::ostream& operator<<(std::ostream& out, const Shop& other);
};


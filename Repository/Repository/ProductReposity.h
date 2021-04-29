#pragma once
#include"Product.h"
#include"Vector.h"
class ProductReposity
{
private:

	char* filepath;// filename products.txt
	void copy(const ProductReposity& other);
	void destroy();

public:

	ProductReposity();
	ProductReposity(const ProductReposity& other);
	ProductReposity& operator=(const ProductReposity& other);
	~ProductReposity();

	void setFilepath(const char* newFilepath);
	const char* getFilepath()const;

	void add(Product& product); 
	void update(Product* product);
	void deleteProduct(Product* product);
	Product& getByName(const char* name); // part of the READ functiona ?  
	Vector<Product>* getAll(); // READ 
};


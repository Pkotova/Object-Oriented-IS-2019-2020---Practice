#include "ProductReposity.h"
#include<fstream>
#include<ctime>

void ProductReposity::copy(const ProductReposity& other)
{
    setFilepath(other.filepath);
}

void ProductReposity::destroy()
{
    delete[] this->filepath;
}

ProductReposity::ProductReposity()
{
    setFilepath("products.txt");
}

ProductReposity::ProductReposity(const ProductReposity& other)
{
    copy(other);
}

ProductReposity& ProductReposity::operator=(const ProductReposity& other)
{
    if (this!= &other)
    {
        copy(other);
    }
    return *this;
}

ProductReposity::~ProductReposity()
{
    destroy();
}

void ProductReposity::setFilepath(const char* newFilepath)
{
    if (newFilepath != nullptr)
    {
        //destroy();
        this->filepath = new char[strlen(newFilepath) + 1];
        strcpy_s(this->filepath, strlen(newFilepath) + 1, newFilepath);
    }
}

const char* ProductReposity::getFilepath() const
{
    return this->filepath;
}

void ProductReposity::add(Product& product)
{
    std::ofstream out(this->filepath, std::ios::app); // writing
    out << product.getName() << std::endl
        << product.getQuantity() << std::endl
        << product.getPrice() << std::endl;
    out.close();
}

void ProductReposity::update(Product* product)
{
    std::ifstream in(this->filepath); // отварям products.txt
    std::ofstream out("temp.txt", std::ios::app);// създаваме и отваряме файл temp.txt

    Product* item = new Product();
    char buffer[20];
    while (!in.eof())
    {
        in.getline(buffer, 20);
        item->setName(buffer);

        in.getline(buffer, 20); // buffer = "10" , atoi(buffer) = 10;
        item->setQuantity(atoi(buffer));

        in.getline(buffer, 20); // buffer = "1.2" , atof(buffer) = 1.2;
        item->setPrice(atof(buffer));

        if (!in.eof() && strcmp(item->getName(), product->getName()) != 0)
        {
            out << item->getName() << std::endl
                << item->getQuantity() << std::endl
                << item->getPrice() << std::endl;
        }
        else if (!in.eof() && strcmp(item->getName(), product->getName()) == 0)
        {
            out << product->getName() << std::endl
                << product->getQuantity() << std::endl
                << product->getPrice() << std::endl;
        }
    }
    in.close();
    out.close();
    remove(this->filepath);
    rename("temp.txt", this->filepath);
}

void ProductReposity::deleteProduct(Product* product)
{
    //1. създавам temp.txt
    //2. прехвърлям всички обекти от products.txt, без product
    //3. изтривам старият products.txt
    //4. преименувам temp.txt => products.txt
  
    std::ifstream in(this->filepath); // отварям products.txt
    std::ofstream out("temp.txt", std::ios::app);// създаваме и отваряме файл temp.txt

    Product* item = new Product();
    char buffer[20];
    while (!in.eof())
    {
        in.getline(buffer, 20);
        item->setName(buffer);

        in.getline(buffer, 20); // buffer = "10" , atoi(buffer) = 10;
        item->setQuantity(atoi(buffer));

        in.getline(buffer, 20); // buffer = "1.2" , atof(buffer) = 1.2;
        item->setPrice(atof(buffer));

        if (!in.eof() && strcmp(item->getName(),product->getName())!= 0)
        {
            out << item->getName() << std::endl
                << item->getQuantity() << std::endl
                << item->getPrice() << std::endl;
        }
    }
    in.close();
    out.close();
     remove(this->filepath);
    rename("temp.txt", this->filepath);
}

Product& ProductReposity::getByName(const char* name)
{
    std::ifstream in(this->filepath);
    Product* result = nullptr;
    Product* product = new Product();
    char buffer[20];
    while (!in.eof())
    {
        in.getline(buffer, 20);
        product->setName(buffer);

        in.getline(buffer, 20); // buffer = "10" , atoi(buffer) = 10;
        product->setQuantity(atoi(buffer)); 

        in.getline(buffer, 20); // buffer = "1.2" , atof(buffer) = 1.2;
        product->setPrice(atof(buffer)); 

        if (strcmp(product->getName(), name) == 0)
        {
            result = product;
            //break;
        }
    }
    return *result;
}

Vector<Product>* ProductReposity::getAll()
{
    Vector<Product>* result = new Vector<Product>();
    std::ifstream in(this->filepath);
    Product* product = nullptr;
    char buffer[20];
    while (!in.eof())
    {
        product = new Product();

        in.getline(buffer, 20);
        product->setName(buffer);

        in.getline(buffer, 20); // buffer = "10" , atoi(buffer) = 10;
        product->setQuantity(atoi(buffer));

        in.getline(buffer, 20); // buffer = "1.2" , atof(buffer) = 1.2;
        product->setPrice(atof(buffer));

        result->push(*product);
    }
    in.close();
    return result;
}

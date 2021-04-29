#include <iostream>
#include"Product.h"
#include"Shop.h"
#include"ProductReposity.h"
int main()
{
	Product p1("Milk", 10, 1.2),
		p2("Bread", 5, 1.0),
		p3("Butter", 12, 3.40);
	Vector<Product> v1;
	v1.push(p1);
	v1.push(p2);
	v1.push(p3);
	Shop s;
	s.setInventory(v1);
	//std::cout << s << std::endl;

	ProductReposity pr;
	pr.add(p1);
	pr.add(p2);
	pr.add(p3);
	p1.setQuantity(0);
	//pr.update(&p1);
	pr.deleteProduct(&p2);
	//std::cout << pr.getByName("Bread") << std::endl;
	//pr.getAll()->print();

	//Shop s1; 
	//s1.setInventory(*(pr.getAll()));
	//std::cout << s1 << std::endl;

}

#pragma once
class Medicine
{
private:

	char name[32];
	int mg;
	double price;

public:

	void setName(char newName[32]);
	const char* getName() const;

	void setMg(int newMg);
	int getMg() const;

	void setPrice(double newPrice);
	double getPrice() const;

	void input();
	void output()const;
};


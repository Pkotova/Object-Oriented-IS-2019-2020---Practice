#pragma once
#include "House.h"
class HouseRepository
{
private:
	char* filepath;
	void copy(const HouseRepository& other);
	void destroy();
public:
	HouseRepository();
	HouseRepository(const HouseRepository& other);
	HouseRepository& operator=(const HouseRepository& other);
	~HouseRepository();

	void setFilepath(const char* newFilepath);
	
	void add(House& house);
	void update(House& house);
	void remove(House& house);
	House& getByName(const char* name);
	House** getAll(); 
};


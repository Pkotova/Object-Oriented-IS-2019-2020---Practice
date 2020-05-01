#pragma once
#include"ProgrammingLanguage.h"
class VirtualMachine : public ProgrammingLanguage
{
private: 
	char* virtualMachine;
	void copy(const VirtualMachine& other);
	void destroy();
public:
	VirtualMachine();
	VirtualMachine(const VirtualMachine& other);
	VirtualMachine(const char* newName, size_t newYear, const char* newAuthor,
		const char* newParadigm, const char* newHelloWorld,
		size_t newTime, const char* newVirtualMachine);
	VirtualMachine& operator=(const VirtualMachine& other);
	~VirtualMachine();

	void setVirualMachine(const char* newVirtualMachine);
	const char* getVirtualMachine()const;

	friend std::istream& operator>>(std::istream& in, VirtualMachine& current);
	friend std::ostream& operator<<(std::ostream& out, const VirtualMachine& current);
};


#include"Validators.h"
bool isValidName(const char* name)
{
	//two names, ' and - are allowed 
	//Hector Sausage-Hausen
	//Mathias d'Arras
	const std::regex pattern("^([a-zA-Z]{2,}\\s[a-zA-z]{1,}'?-?[a-zA-Z]{2,}\\s?([a-zA-Z]{1,})?)");
	return regex_match(name, pattern);
}
#pragma once
#include<regex>

bool isValidColorCode(std::string code) 
{
    const std::regex pattern("^#([A-Fa-f0-9]{6}|[A-Fa-f0-9]{3})");
    return regex_match(code, pattern);
}
bool isValidBarCode(std::string code)
{
    //EAN 
    const std::regex pattern("[A-Z0-9]{13}");
    return regex_match(code, pattern);
}
bool isValidZipCode(std::string code)
{
    //Bulgarian zip codes
    const std::regex pattern("[0-9]{4}");
    return regex_match(code, pattern);
}
bool isValidCarCode(std::string code)
{
    //Bulgarian car codes
    const std::regex pattern("[A-Z]{1,2}[0-9]{4}[A-Z]{1,2}");
    return regex_match(code, pattern);
}

#pragma once
#include<regex>

//blank spaces are not allowed
bool isValidEmailContainsAt(std::string email) //containts @
{
    //email that cointains only letters (uppercase and lowercase) and @
    const std::regex pattern("(\\w+)@(\\w+)");
    return regex_match(email, pattern);

    // match: p@p
}
bool isValidEmailContainsAtAndDomain(std::string email) //containts @
{
    //email that cointains only letters (uppercase and lowercase) and @ and email domain
    const std::regex pattern("(\\w+)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);

    // match: uni@sofia.bg
}
bool isValidEmailContainsSpecialSymbols(std::string email) //containts @
{
    //email that cointains only letters (uppercase and lowercase) and @ and email domain and -,_ or .
    const std::regex pattern("(\\w+)(\\.|-|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);

    // match: uni-sofia@sofia.bg
}
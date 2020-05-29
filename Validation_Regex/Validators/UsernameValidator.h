#pragma once
#include<regex>

// avoid blank spaces
bool isValidUsernameNoSpaces(std::string username)
{
    //username that cointains only letters (uppercase and lowercase)
    const std::regex pattern("[a-zA-Z]\s+");
    return regex_match(username, pattern); 
}

//-- blank spaces are allowed
bool isValidUsernameUppercaseAndLowercase(std::string username)
{
//username that cointains only letters (uppercase and lowercase)
    const std::regex pattern("[a-zA-Z]+");
    return regex_match(username, pattern);
}

bool isValidUsernameLowercase(std::string username)
{
    //username that cointains only lowercase letters
    const std::regex pattern("[a-z]+");
    return regex_match(username, pattern);
}
bool isValidUsernameUppercase(std::string username)
{
    //username that cointains only uppercase letters
    const std::regex pattern("[A-Z]+");
    return regex_match(username, pattern);
}
bool isValidUsernameDigits(std::string username)
{
    //username that cointains only digits
    const std::regex pattern("[0-9]+");
    return regex_match(username, pattern);
}
bool isValidUsernameDigitsAndLetters(std::string username)
{
    //username that cointains only uppercase, lowercase letters and digits
    const std::regex pattern("[a-zA-Z0-9]+");
    return regex_match(username, pattern);
}
bool isValidUsernameDigitsAndLettersWithRange(std::string username)
{
    //username that cointains only uppercase, lowercase letters and digits with a certain amount of characters
    const std::regex pattern("[a-zA-z0-9]{5,16}");
    //you choice the range, the example is between 5 and 16 characters
    return regex_match(username, pattern);
}

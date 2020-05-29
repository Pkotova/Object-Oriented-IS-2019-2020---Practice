#pragma once
#include<regex>

//blank spaces are not allowed
bool isValidPhoneNumberOnlyNumbers(std::string phoneNumber) 
{
    const std::regex pattern("[0-9]+");
    return regex_match(phoneNumber, pattern);

}
bool isValidPhoneNumberOnly10Numbers(std::string phoneNumber)
{
    const std::regex pattern("[0-9]{10}");
    return regex_match(phoneNumber, pattern);

}
bool isValidPhoneNumberStartsWith08(std::string phoneNumber)
{
    const std::regex pattern("^08[0-9]{8}");
    return regex_match(phoneNumber, pattern);
}
bool isValidPhoneNumberStartsWithPlus359(std::string phoneNumber)
{
    const std::regex pattern("^(\\+359)[0-9]{9}");
    return regex_match(phoneNumber, pattern);
}


// Validators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"UsernameValidator.h"
#include"EmailValidator.h"
#include"PhoneNumberValidator.h"
#include "CodesValidators.h"
int main()
{
//username validation
/*
    std::string username;
    std::cout << "Input username: ";
    std::cin >> username;
    std::cout << std::endl << "Username validation:  " << std::endl << std::endl;
    std::cout << std::boolalpha << "Uppercase and lowercase without blank spaces: " << isValidUsernameNoSpaces(username) << std::endl;
    std::cout << std::boolalpha << "Uppercase and lowercase: " << isValidUsernameUppercaseAndLowercase(username) << std::endl;
    std::cout << std::boolalpha << "Lowercase only: " << isValidUsernameLowercase(username) << std::endl;
    std::cout << std::boolalpha << "Uppercase only: " << isValidUsernameUppercase(username) << std::endl;
    std::cout << std::boolalpha << "Digits only: " << isValidUsernameDigits(username) << std::endl;
    std::cout << std::boolalpha << "Digits and letters (uppercase and lowercase): " << isValidUsernameDigitsAndLetters(username) << std::endl;
    std::cout << std::boolalpha << "Digits and letters (uppercase and lowercase) with range for amount of symbols [5-16]: " 
                                << isValidUsernameDigitsAndLettersWithRange(username)<< std::endl<<std::endl;
*/

/*
// password validations are the same

// email validation
    std::string email;
    std::cout << "Input email: ";
    std::cin >> email;
    std::cout << std::endl << "Email validation:  " << std::endl << std::endl;
    std::cout << std::boolalpha << "Contains @ and domain name: " << isValidEmailContainsAt(email) << std::endl;
    std::cout << std::boolalpha << "Contains @ domain and extension: " << isValidEmailContainsAtAndDomain(email) << std::endl;
    std::cout << std::boolalpha << "Contains @ domain and extension and -, _ or . : " << isValidEmailContainsSpecialSymbols(email) << std::endl;
  */  

/*
 // phone number validations 
    std::string phoneNumber;
    std::cout << "Input phone number: ";
    std::cin >> phoneNumber;
    std::cout << std::endl << "Phone number validation:  " << std::endl << std::endl;
    std::cout << std::boolalpha << "Contains only numbers: " << isValidPhoneNumberOnlyNumbers(phoneNumber) << std::endl;
    std::cout << std::boolalpha << "Contains exactly 10 numbers: " << isValidPhoneNumberOnly10Numbers(phoneNumber) << std::endl;
    std::cout << std::boolalpha << "Contains starts with 08 numbers: " << isValidPhoneNumberStartsWith08(phoneNumber) << std::endl;
    std::cout << std::boolalpha << "Contains starts with +359 numbers: " << isValidPhoneNumberStartsWithPlus359(phoneNumber) << std::endl;

*/
// code validations 
    std::string code;
    std::cout << "Input code: ";
    std::cin >> code;
    std::cout << std::boolalpha << "Color code: " << isValidColorCode(code) << std::endl;
    std::cout << std::boolalpha << "Bar code: " << isValidBarCode(code) << std::endl;
    std::cout << std::boolalpha << "ZIP code: " << isValidZipCode(code) << std::endl;
    std::cout << std::boolalpha << "Car code: " << isValidCarCode(code) << std::endl;



}

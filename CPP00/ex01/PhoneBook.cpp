#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    current_index = 0;
    total_contacts = 0;
}
PhoneBook::~PhoneBook()
{
	std::cout << "You closed the PhoneBook and everything is lost! Nooooooo!" << std::endl;
}

void PhoneBook::addContact()
{
    Contact contact;
    std::string input;

    // First Name
    do {
        std::cout << "Enter First Name: ";
        std::getline(std::cin, input);
    } while (input.empty()); // nicht leer lassen
    contact.setFirstName(input);
    do {
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, input);
    } while (input.empty());
    contact.setLastName(input);

    // Nickname
    do {
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, input);
    } while (input.empty());
    contact.setNickname(input);

    // Phone Number
    do {
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, input);
    } while (input.empty());
    contact.setPhoneNumber(input);

    // Darkest Secret
    do {
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, input);
    } while (input.empty());
    contact.setDarkestSecret(input);

    // Jetzt Contact ins PhoneBook speichern
    contacts[current_index] = contact;
    current_index = (current_index + 1) % 8;
    if (total_contacts < 8)
        total_contacts++;
}

void PhoneBook::searchContact()
{
	int 		i = 0;
	std::string	s;


	std::cout << "     index|first name| last name|  nickname" << std::endl;
	while (i < total_contacts)
	{
		std::cout << std::setw(10) << i;
		std::cout << '|';
		s = contacts[i].getFirstName();
		if (s.length() > 10)
			s = s.substr(0, 9) + '.';
		std::cout << std::setw(10) << s;
		std::cout << '|';
		s = contacts[i].getLastName();
		if (s.length() > 10)
			s = s.substr(0, 9) + '.';
		std::cout << std::setw(10) << s;
		std::cout << '|';
		s = contacts[i].getNickname();
		if (s.length() > 10)
			s = s.substr(0, 9) + '.';
		std::cout << std::setw(10) << s << std::endl;
		i++;
	}

	std::string input;

	while (true)
	{
	    bool isNumber = true;
		
		std::cout << "Enter existing index to display contact: ";
		std::getline(std::cin, input);
		for (size_t j = 0; j < input.length(); j++)
		{
			if (!std::isdigit(input[j]))
			{
				isNumber = false;
				break;
			}
		}

		if (!isNumber)
		{
			std::cout << "Invalid index!" << std::endl;
			continue;
		}
		i = std::atoi(input.c_str());
		if (i < 0 || i >= total_contacts)
    	    std::cout << "Invalid index!" << std::endl;
		else
		{
			std::cout << contacts[i].getFirstName() << std::endl;
			std::cout << contacts[i].getLastName() << std::endl;
			std::cout << contacts[i].getNickname() << std::endl;
			std::cout << contacts[i].getPhoneNumber() << std::endl;
			std::cout << contacts[i].getDarkestSecret() << std::endl;
			break;
		}
	}
}

int PhoneBook::getTotalContacts() const
{
    return total_contacts;
}
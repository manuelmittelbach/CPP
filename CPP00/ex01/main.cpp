#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	PhoneBook	pb;
	std::string	command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);
		if (command == "ADD")
			pb.addContact();
		else if (command == "SEARCH")
		{
			if (pb.getTotalContacts() == 0)
			{
				std::cout << "There are no contacts in the PhoneBook!" << std::endl;
				continue;
			}
			pb.searchContact();
		}
		else if (command == "EXIT")
			break;
	}
	return (0);
}
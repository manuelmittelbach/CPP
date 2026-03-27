#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "Default constructor called for WrongCat\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "Copy constructor called for WrongCat\n";
}

WrongCat& WrongCat::operator=(const WrongCat& other) 
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	std::cout << "Copy assignment operator called for WrongCat\n";
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor called for WrongCat\n";
}

void WrongCat::makeSound() const
{
	std::cout << "miao\n";
}

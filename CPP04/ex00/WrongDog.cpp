#include <iostream>
#include "WrongDog.hpp"

WrongDog::WrongDog()
{
	type = "WrongDog";
	std::cout << "Default constructor called for WrongDog\n";
}

WrongDog::WrongDog(const WrongDog& other) : WrongAnimal(other)
{
	std::cout << "Copy constructor called for WrongDog\n";
}

WrongDog& WrongDog::operator=(const WrongDog& other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	std::cout << "Copy assignment operator called for WrongDog\n";
	return *this;
}

WrongDog::~WrongDog()
{
	std::cout << "Destructor called for WrongDog\n";
}

void WrongDog::makeSound() const
{
	std::cout << "woof\n";
}

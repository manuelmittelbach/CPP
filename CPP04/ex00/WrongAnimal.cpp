#include <iostream>
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	type = "undefined type";
	std::cout << "Default constructor called for WrongAnimal\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	this->type = other.type;
	std::cout << "Copy constructor called for WrongAnimal\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Copy assignment operator called for WrongAnimal\n";
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor called for WrongAnimal\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << "undefined WrongAnimal sound\n";
}

std::string WrongAnimal::getType() const
{
	return type;
}

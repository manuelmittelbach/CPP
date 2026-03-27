#include <iostream>
#include "Animal.hpp"

Animal::Animal()
{
	type = "undefined type";
	std::cout << "Default constructor called for Animal\n";
}

Animal::Animal(const Animal& other)
{
	this->type = other.type;
	std::cout << "Copy constructor called for Animal\n";
}

Animal& Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	std::cout << "Copy assignment operator called for Animal\n";
	return *this;
}

Animal::~Animal()
{
	std::cout << "Destructor called for Animal\n";
}

std::string Animal::getType() const
{
	return type;
}

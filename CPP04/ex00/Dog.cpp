#include <iostream>
#include "Dog.hpp"

Dog::Dog()
{
	type = "Dog";
	std::cout << "Default constructor called for Dog\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Copy constructor called for Dog\n";
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Copy assignment operator called for Dog\n";
	return *this;
}

Dog::~Dog()
{
	std::cout << "Destructor called for Dog\n";
}

void Dog::makeSound() const
{
	std::cout << "woof\n";
}

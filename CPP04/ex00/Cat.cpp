#include <iostream>
#include "Cat.hpp"

Cat::Cat()
{
	type = "Cat";
	std::cout << "Default constructor called for Cat\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Copy constructor called for Cat\n";
}

Cat& Cat::operator=(const Cat& other) 
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	std::cout << "Copy assignment operator called for Cat\n";
	return *this;
}

Cat::~Cat()
{
	std::cout << "Destructor called for Cat\n";
}

void Cat::makeSound() const
{
	std::cout << "miao\n";
}

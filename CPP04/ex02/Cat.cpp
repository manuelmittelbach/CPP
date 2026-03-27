#include <iostream>
#include "Cat.hpp"

Cat::Cat() : brain(new Brain())
{
	type = "Cat";
	std::cout << "Default constructor called for Cat\n";
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Copy constructor called for Cat\n";
}

Cat& Cat::operator=(const Cat& other) 
{
	if (this != &other)
	{
		Animal::operator=(other);
		*this->brain = *other.brain;
	}
	std::cout << "Copy assignment operator called for Cat\n";
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Destructor called for Cat\n";
}

void Cat::makeSound() const
{
	std::cout << "miao\n";
}

std::string Cat::getIdea(int i) const
{
	return brain->getIdea(i);
}

void Cat::setIdea(int i, const std::string& idea)
{
	brain->setIdea(i, idea);
}
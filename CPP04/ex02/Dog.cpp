#include <iostream>
#include "Dog.hpp"

Dog::Dog() : brain(new Brain())
{
	type = "Dog";
	std::cout << "Default constructor called for Dog\n";
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain))
{
	std::cout << "Copy constructor called for Dog\n";
}

Dog& Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		*this->brain = *other.brain;
	}
	std::cout << "Copy assignment operator called for Dog\n";
	return *this;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Destructor called for Dog\n";
}

void Dog::makeSound() const
{
	std::cout << "woof\n";
}

std::string Dog::getIdea(int i) const
{
	return brain->getIdea(i);
}

void Dog::setIdea(int i, const std::string& idea)
{
	brain->setIdea(i, idea);
}

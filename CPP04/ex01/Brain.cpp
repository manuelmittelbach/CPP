#include <iostream>
#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "empty idea";
	std::cout << "Default constructor called for Brain\n";
}

Brain::Brain(const Brain& other)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
	std::cout << "Copy constructor called for Brain\n";
}

Brain& Brain::operator=(const Brain& other) 
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	std::cout << "Copy assignment operator called for Brain\n";
	return *this;
}

Brain::~Brain()
{
	std::cout << "Destructor called for Brain\n";
}

void Brain::setIdea(int i, const std::string& idea)
{
	if (i >= 0 && i < 100)
		ideas[i] = idea;
}

std::string Brain::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return ideas[i];
	return "";
}


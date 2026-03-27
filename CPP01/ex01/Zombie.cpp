#include "Zombie.hpp"
#include <iostream>

void Zombie::setName(std::string name)
{
	this->name = name;
}

Zombie::Zombie() {}

void Zombie::announce ( void )
{
	std::cout << name
		      << ": BraiiiiiiinnnzzzZ..."
			  << std:: endl;
}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed" << std:: endl;
}

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name) : name(name)
{
}

void Zombie::announce ( void )
{
	std::cout << name
		      << ": BraiiiiiiinnnzzzZ..."
			  << std:: endl;
}

Zombie::~Zombie()
{
    std::cout << name << " is destroyed\n";
}
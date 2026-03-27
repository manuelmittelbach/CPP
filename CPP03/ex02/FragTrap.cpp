#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	HitPoints = 100;
    EnergyPoints = 100;
    AttackDamage = 30;

	std::cout << "FragTrap default constructor called for " << Name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called for " << Name << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    if (this == &other) // self-assignment check
        return *this;

	ClapTrap::operator=(other);

	std::cout << "FragTrap copy assignment operator called for " << Name << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << Name << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << Name << " requests a high five!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (HitPoints <= 0)
    {
        std::cout << "FragTrap " << Name << " is too damaged to attack!" << std::endl;
        return;
    }
    if (EnergyPoints <= 0)
    {
        std::cout << "FragTrap " << Name << " has no energy to attack!" << std::endl;
        return;
    }
    EnergyPoints--;
    std::cout << "FragTrap " << Name 
              << " attacks " << target 
              << ", causing " << AttackDamage 
              << " points of damage!" << std::endl;
}

void FragTrap::takeDamage(unsigned int amount)
{
    if (amount >= (unsigned int)HitPoints)
        HitPoints = 0;
    else
        HitPoints -= amount;

    std::cout << "FragTrap " << Name 
              << " takes " << amount 
              << " points of damage and has now " << HitPoints 
              << " HitPoints" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
    if (HitPoints <= 0)
    {
        std::cout << "FragTrap " << Name << " is too damaged to repair itself!" << std::endl;
        return;
    }
    if (EnergyPoints <= 0)
    {
        std::cout << "FragTrap " << Name << " has no energy to repair itself!" << std::endl;
        return;
    }

    HitPoints += amount;
    EnergyPoints--;

    std::cout << "FragTrap " << Name
              << " repairs itself and gains "
              << amount 
			  << " HitPoints. Now "
			  << Name 
			  << " has "
              << HitPoints 
			  << " HitPoints." 
			  << std::endl;
}

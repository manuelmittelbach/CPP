#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;

	std::cout << "ScavTrap default constructor called for " << Name << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	HitPoints = 100;
    EnergyPoints = 50;
    AttackDamage = 20;

	std::cout << "ScavTrap constructor called for " << Name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called for " << Name << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this == &other) // self-assignment check
    {
        return *this;
    }
	ClapTrap::operator=(other);

	std::cout << "ScavTrap copy assignment operator called for " << Name << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << Name << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << Name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (HitPoints <= 0)
    {
        std::cout << "ScavTrap " << Name << " is too damaged to attack!" << std::endl;
        return;
    }
    if (EnergyPoints <= 0)
    {
        std::cout << "ScavTrap " << Name << " has no energy to attack!" << std::endl;
        return;
    }
    EnergyPoints--;
    std::cout << "ScavTrap " << Name 
              << " attacks " << target 
              << ", causing " << AttackDamage 
              << " points of damage!" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount)
{
    if (amount >= (unsigned int)HitPoints)
        HitPoints = 0;
    else
        HitPoints -= amount;

    std::cout << "ScavTrap " << Name 
              << " takes " << amount 
              << " points of damage and has now " << HitPoints 
              << " HitPoints" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
    if (HitPoints <= 0)
    {
        std::cout << "ScavTrap " << Name << " is too damaged to repair itself!" << std::endl;
        return;
    }
    if (EnergyPoints <= 0)
    {
        std::cout << "ScavTrap " << Name << " has no energy to repair itself!" << std::endl;
        return;
    }

    HitPoints += amount;
    EnergyPoints--;

    std::cout << "ScavTrap " << Name
              << " repairs itself and gains "
              << amount 
			  << " HitPoints. Now "
			  << Name 
			  << " has "
              << HitPoints 
			  << " HitPoints." 
			  << std::endl;
}

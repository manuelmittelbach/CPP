#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap()
    : Name("unknown"), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
    std::cout << "ClapTrap default constructor called for " << Name << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
    : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0)
{
	std::cout << "ClapTrap constructor called for " << Name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << Name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	this->AttackDamage = other.AttackDamage;
	this->EnergyPoints = other.EnergyPoints;
	this->HitPoints = other.HitPoints;
	this->Name = other.Name;

	std::cout << "ClapTrap copy constructor called for " << Name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this == &other)
        return *this;
		
	this->AttackDamage = other.AttackDamage;
	this->EnergyPoints = other.EnergyPoints;
	this->HitPoints = other.HitPoints;
	this->Name = other.Name;

	std::cout << "ClapTrap copy assignment operator called for " << Name << std::endl;

	return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (HitPoints <= 0)
    {
        std::cout << "ClapTrap " << Name << " is too damaged to attack!" << std::endl;
        return;
    }
    if (EnergyPoints <= 0)
    {
        std::cout << "ClapTrap " << Name << " has no energy to attack!" << std::endl;
        return;
    }
    EnergyPoints--;
    std::cout << "ClapTrap " << Name 
              << " attacks " << target 
              << ", causing " << AttackDamage 
              << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= (unsigned int)HitPoints)
        HitPoints = 0;
    else
        HitPoints -= amount;

    std::cout << "ClapTrap " << Name 
              << " takes " << amount 
              << " points of damage and has now " << HitPoints 
              << " HitPoints" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (HitPoints <= 0)
    {
        std::cout << "ClapTrap " << Name << " is too damaged to repair itself!" << std::endl;
        return;
    }
    if (EnergyPoints <= 0)
    {
        std::cout << "ClapTrap " << Name << " has no energy to repair itself!" << std::endl;
        return;
    }

    HitPoints += amount;
    EnergyPoints--;

    std::cout << "ClapTrap " << Name
              << " repairs itself and gains "
              << amount 
			  << " HitPoints. Now "
			  << Name 
			  << " has "
              << HitPoints 
			  << " HitPoints." 
			  << std::endl;
}

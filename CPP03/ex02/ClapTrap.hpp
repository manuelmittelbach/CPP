#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <string> 

class ClapTrap
{
protected: 
	std::string Name;
	int	HitPoints;
	int	EnergyPoints;
	int	AttackDamage;
public:
	ClapTrap();
	ClapTrap(const std::string& Name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	virtual ~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
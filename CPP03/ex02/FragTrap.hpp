#ifndef FRAGTRAP_CPP
#define FRAGTRAP_CPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:	
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	~FragTrap();
	void highFivesGuys(void);
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif
#ifndef HUMAN_A
#define HUMAN_A

# include <string>
# include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon& weapon;
public:
	HumanA( std::string name, Weapon& weapon );
	void attack();
};

#endif

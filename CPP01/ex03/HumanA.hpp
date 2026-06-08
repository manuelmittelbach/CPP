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
	void attack();
	HumanA( std::string name, Weapon& weapon );
};

#endif

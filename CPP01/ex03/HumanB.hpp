#ifndef HUMAN_B
#define HUMAN_B

# include <string>
# include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon* weapon;
public:
	void attack();
	HumanB(std::string name);
	void setWeapon(Weapon& weapon);
};

#endif

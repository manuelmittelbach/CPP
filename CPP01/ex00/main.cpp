#include "Zombie.hpp"

int main(void)
{
	Zombie* z1;

	randomChump("Manu");
	z1 = newZombie("Lukas");
	z1->announce();

	delete z1;
	return (0);
}
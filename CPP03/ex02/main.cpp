#include "FragTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Creating ClapTraps ---" << std::endl;
    ClapTrap alpha("Alpha");
    ClapTrap beta("Beta");

    std::cout << "\n--- Creating FragTraps ---" << std::endl;
    FragTrap blaster("Blaster");
    FragTrap destroyer("Destroyer");

    std::cout << "\n--- Testing attack ---" << std::endl;
    alpha.attack("TargetDummy");
    beta.attack("AnotherTarget");
	destroyer.takeDamage(100);
    destroyer.attack("Invader");
    blaster.attack("EnemyBot");

    std::cout << "\n--- Testing takeDamage ---" << std::endl;
    alpha.takeDamage(5);
    destroyer.takeDamage(40);

    std::cout << "\n--- Testing beRepaired ---" << std::endl;
    alpha.beRepaired(5);
    destroyer.beRepaired(20);

    std::cout << "\n--- Testing FragTrap special ability ---" << std::endl;
    blaster.highFivesGuys();
    destroyer.highFivesGuys();

    std::cout << "\n--- Testing energy depletion ---" << std::endl;
    for (int i = 0; i < 105; ++i)
        blaster.attack("TrainingDummy"); // Will eventually hit 0 energy

    blaster.beRepaired(10); // Should fail if no energy left

    std::cout << "\n--- End of tests ---" << std::endl;
    return 0;
}

#include "ScavTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Creating ClapTraps ---" << std::endl;
    ClapTrap alpha("Alpha");
    ClapTrap beta("Beta");

    std::cout << "\n--- Creating ScavTraps ---" << std::endl;
    ScavTrap guardian("Guardian");
    ScavTrap sentinel("Sentinel");

    std::cout << "\n--- Testing attack ---" << std::endl;
    alpha.attack("TargetDummy");
    beta.attack("AnotherTarget");
    guardian.takeDamage(100);
    guardian.attack("EnemyBot");
    sentinel.attack("Invader");

    std::cout << "\n--- Testing takeDamage ---" << std::endl;
    alpha.takeDamage(5);
    sentinel.takeDamage(7);

    std::cout << "\n--- Testing beRepaired ---" << std::endl;
    alpha.beRepaired(5);
    guardian.beRepaired(1);

    std::cout << "\n--- Testing ScavTrap special ability ---" << std::endl;
    guardian.guardGate();
    sentinel.guardGate();

    std::cout << "\n--- Testing energy depletion ---" << std::endl;
    for (int i = 0; i < 50; ++i)
        sentinel.attack("Dummy"); // Will eventually hit 0 energy

    sentinel.beRepaired(10); // Should fail if no energy left

    std::cout << "\n--- End of tests ---" << std::endl;
    return 0;
}
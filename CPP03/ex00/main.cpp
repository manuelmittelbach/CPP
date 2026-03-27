#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    std::cout << "--- Creating ClapTraps ---\n";
    ClapTrap clap1("Alpha");
    ClapTrap clap2("Beta");

    std::cout << "\n--- Testing attack ---\n";
    clap1.attack("TargetDummy");
    clap1.attack("AnotherTarget");
    clap2.takeDamage(10);
    clap2.attack("EnemyBot");

    std::cout << "\n--- Testing takeDamage ---\n";
    clap1.takeDamage(5);
    clap1.takeDamage(7);  // Should reduce HP to 0

    std::cout << "\n--- Testing beRepaired ---\n";
    clap1.beRepaired(4);  // Should fail because HP is 0
    clap2.beRepaired(5);

    std::cout << "\n--- Testing energy depletion ---\n";
    // Reduce energy of clap2 to 0
    for (int i = 0; i < 10; i++)
        clap2.attack("Dummy");

    clap2.beRepaired(2); // Should fail because energy is 0

    std::cout << "\n--- End of tests ---\n";

    return 0;
}
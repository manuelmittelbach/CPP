#include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie* horde = zombieHorde(N, "Peter");

    delete[] horde;  // Zerstört alle Zombies in der Horde
    return 0;
}
#include <string>
#include <iostream>
#include "Harl.hpp"

void Harl::debug() {
    std::cout << "DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void Harl::info() {
    std::cout << "INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::warning() {
    std::cout << "WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n";
}

void Harl::error() {
    std::cout << "ERROR: This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::filter(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    void (Harl::*functions[4])() = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

	int idx = -1;
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            idx = i;
        }
    }

	switch (idx)
	{
		case 0: (this->*functions[0])(); [[fallthrough]];
		case 1: (this->*functions[1])(); [[fallthrough]];
		case 2: (this->*functions[2])(); [[fallthrough]];
		case 3: (this->*functions[3])(); break;
		default: std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}
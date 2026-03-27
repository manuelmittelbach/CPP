#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;

    std::cout << "Testing DEBUG level:\n";
    harl.complain("DEBUG");
    std::cout << "\n";

    std::cout << "Testing INFO level:\n";
    harl.complain("INFO");
    std::cout << "\n";

    std::cout << "Testing WARNING level:\n";
    harl.complain("WARNING");
    std::cout << "\n";

    std::cout << "Testing ERROR level:\n";
    harl.complain("ERROR");
    std::cout << "\n";

    std::cout << "Testing unknown level:\n";
    harl.complain("SILLY");
    std::cout << "\n";

    return 0;
}
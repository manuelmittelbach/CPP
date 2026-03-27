#include "Harl.hpp"
#include <iostream>

int main(int argc, char** argv) {
    Harl harl;

	if (argc != 2)
	{
		std::cerr << "Usage: ./harlFilter <LEVEL>\n";
		return (1);
	}
	harl.filter(argv[1]);
}
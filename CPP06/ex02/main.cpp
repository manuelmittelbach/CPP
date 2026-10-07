#include "Identify.hpp"
#include <iostream>

int main(void)
{
	for (int i = 0; i < 6; i++)
	{
		Base *p = generate();

		std::cout << "Object #" << i << std::endl;
		std::cout << "  identify(pointer)  : ";
		identify(p);
		std::cout << "  identify(reference): ";
		identify(*p);
		std::cout << "-----------------------" << std::endl;

		delete p;
	}
	return 0;
}

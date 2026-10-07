#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	std::cout << "===== 1. Create and print valid Bureaucrats =====" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);     // highest grade
		Bureaucrat intern("Intern", 150); // lowest grade
		std::cout << boss << std::endl;
		std::cout << intern << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "===== 2. Invalid grades (constructor throws) =====" << std::endl;
	try
	{
		Bureaucrat tooHigh("TooHigh", 0); // < 1
		std::cout << tooHigh << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error while creating: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat tooLow("TooLow", 151); // > 150
		std::cout << tooLow << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error while creating: " << e.what() << std::endl;
	}

	std::cout << std::endl << "===== 3. increment / decrement =====" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 3);
		std::cout << bob << std::endl;
		bob.increment(); // 3 -> 2 (higher)
		std::cout << "after increment: " << bob << std::endl;
		bob.decrement(); // 2 -> 3 (lower)
		bob.decrement(); // 3 -> 4
		std::cout << "after 2x decrement: " << bob << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "===== 4. Exceeding the limits (throws) =====" << std::endl;
	try
	{
		Bureaucrat top("Top", 1);
		std::cout << top << std::endl;
		top.increment(); // cannot go higher than 1 -> GradeTooHighException
	}
	catch (std::exception &e)
	{
		std::cout << "Error while incrementing: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bottom("Bottom", 150);
		std::cout << bottom << std::endl;
		bottom.decrement(); // cannot go lower than 150 -> GradeTooLowException
	}
	catch (std::exception &e)
	{
		std::cout << "Error while decrementing: " << e.what() << std::endl;
	}

	std::cout << std::endl << "===== 5. Copy constructor & operator= =====" << std::endl;
	try
	{
		Bureaucrat original("Original", 42);
		Bureaucrat copy(original);   // copy constructor
		Bureaucrat assigned;         // default
		assigned = original;         // operator=
		std::cout << "original: " << original << std::endl;
		std::cout << "copy:     " << copy << std::endl;
		std::cout << "assigned: " << assigned << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}

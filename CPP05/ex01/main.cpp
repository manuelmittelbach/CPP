#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main(void)
{
	std::cout << "===== 1. Create and print a valid Form =====" << std::endl;
	try
	{
		Form taxes("taxes", 50, 25);
		std::cout << taxes << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "===== 2. Invalid grades (constructor throws) =====" << std::endl;
	try
	{
		Form tooHigh("invalid-high", 0, 50); // sign_grade < 1
		std::cout << tooHigh << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error while creating: " << e.what() << std::endl;
	}
	try
	{
		Form tooLow("invalid-low", 50, 200); // execution_grade > 150
		std::cout << tooLow << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error while creating: " << e.what() << std::endl;
	}

	std::cout << std::endl << "===== 3. Bureaucrat with a high grade signs =====" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1); // grade 1 = highest
		Form contract("contract", 42, 10);
		std::cout << "Before: " << contract << std::endl;
		boss.signForm(contract);
		std::cout << "After:  " << contract << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "===== 4. Bureaucrat with a grade too low =====" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150); // grade 150 = lowest
		Form secret("secret", 5, 1);      // requires at least grade 5
		std::cout << "Before: " << secret << std::endl;
		intern.signForm(secret);          // should fail
		std::cout << "After:  " << secret << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl << "===== 5. Edge case: grade exactly equal =====" << std::endl;
	try
	{
		Bureaucrat clerk("Clerk", 42);
		Form form42("form42", 42, 42); // clerk has exactly the required grade
		clerk.signForm(form42);
		std::cout << form42 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}

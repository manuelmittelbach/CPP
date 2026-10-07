#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
	srand(time(NULL)); // seed the random generator once (for RobotomyRequestForm)

	std::cout << "===== 1. Create and print forms =====" << std::endl;
	try
	{
		ShrubberyCreationForm shrub("home");
		RobotomyRequestForm robot("Bender");
		PresidentialPardonForm pardon("Arthur");
		std::cout << shrub << std::endl;
		std::cout << robot << std::endl;
		std::cout << pardon << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl
			  << "===== 2. execute() WITHOUT a signature (throws NotSigned) =====" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("garden");
		boss.executeForm(shrub); // not signed -> executeForm reports the error
	}
	catch (std::exception &e)
	{
		std::cout << "Error during execute: " << e.what() << std::endl;
	}

	std::cout << std::endl
			  << "===== 3. Sign + execute() with a high grade (success) =====" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1); // highest grade -> may do anything
		ShrubberyCreationForm shrub("home");
		boss.signForm(shrub);
		boss.executeForm(shrub); // creates the file home_shrubbery
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl
			  << "===== 4. Signing OK, but execute with a grade too low =====" << std::endl;
	try
	{
		// PresidentialPardonForm: sign 25, exec 5
		// Grade 20: may sign (20 <= 25), but may NOT execute (20 > 5)
		Bureaucrat clerk("Clerk", 20);
		PresidentialPardonForm pardon("Ford");
		clerk.signForm(pardon);  // signing works
		clerk.executeForm(pardon); // execute -> grade too low, reported by executeForm
	}
	catch (std::exception &e)
	{
		std::cout << "Error during execute: " << e.what() << std::endl;
	}

	std::cout << std::endl
			  << "===== 5. Execute RobotomyRequestForm several times (50% chance) =====" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm robot("Marvin");
		boss.signForm(robot);
		for (int i = 0; i < 5; i++)
			boss.executeForm(robot);
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout << std::endl
			  << "===== 6. Polymorphism: AForm* pointing to concrete forms =====" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		AForm *forms[3];
		forms[0] = new ShrubberyCreationForm("park");
		forms[1] = new RobotomyRequestForm("R2D2");
		forms[2] = new PresidentialPardonForm("Trillian");
		for (int i = 0; i < 3; i++)
		{
			boss.signForm(*forms[i]);
			boss.executeForm(*forms[i]); // calls the correct execute() thanks to virtual
			std::cout << *forms[i] << std::endl;
		}
		for (int i = 0; i < 3; i++)
			delete forms[i]; // virtual destructor -> clean teardown
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}

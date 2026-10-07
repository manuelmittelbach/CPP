#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// One small builder per form type. Each one just news up its form.
// Kept file-local (static) because nothing outside this file needs them.
static AForm *makeShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *makeRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

static AForm *makePresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

Intern::Intern()
{
}

Intern::Intern(const Intern &source)
{
	(void)source;
}

Intern &Intern::operator=(const Intern &source)
{
	(void)source;
	return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string &formname, const std::string &formtarget)
{
	// Parallel arrays: names[i] is built by builders[i].
	// This avoids a forest of if / else if and stays easy to extend.
	std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"};
	AForm *(*builders[3])(const std::string &) = {
		&makeShrubbery,
		&makeRobotomy,
		&makePresidential};

	for (int i = 0; i < 3; i++)
	{
		if (names[i] == formname)
		{
			std::cout << "Intern creates " << formname << std::endl;
			return builders[i](formtarget);
		}
	}
	std::cout << "Error: form \"" << formname << "\" does not exist" << std::endl;
	return NULL;
}

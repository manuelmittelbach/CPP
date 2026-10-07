#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &source);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &source);
	~ShrubberyCreationForm();
	void execute(Bureaucrat const &executor) const;
};

#endif

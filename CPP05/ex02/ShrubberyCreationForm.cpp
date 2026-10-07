#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("unknown_target")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &source) : AForm(source), target(source.target)
{
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &source)
{
	if (this != &source)
		AForm::operator=(source);
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSignature_given() == false)
		throw NotSignedException();
	if (executor.getGrade() > this->getExecution_grade())
		throw GradeTooLowException();

	std::ofstream file((this->target + "_shrubbery").c_str());
	if (!file.is_open())
	{
		std::cout << "Error: could not create file " << this->target << "_shrubbery" << std::endl;
		return;
	}
	file << "       ###\n"
			"      #####\n"
			"     #######\n"
			"    #########\n"
			"       ###\n"
			"       ###\n"
			"\n"
			"        ^\n"
			"       ^^^\n"
			"      ^^^^^\n"
			"     ^^^^^^^\n"
			"        |\n"
			"        |\n";
	file.close();
}

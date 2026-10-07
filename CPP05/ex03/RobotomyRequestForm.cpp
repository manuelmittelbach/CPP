#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("unknown_target")
{
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &source) : AForm(source), target(source.target)
{
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &source)
{
	if (this != &source)
		AForm::operator=(source);
	return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getSignature_given() == false)
		throw NotSignedException();
	if (executor.getGrade() > this->getExecution_grade())
		throw GradeTooLowException();
	std::cout << "Bzzzzzztdrrrrrrtakaka" << std::endl;
	if (rand() % 2 == 0)
		std::cout << this->target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "the robotomy of " << this->target << " failed" << std::endl;
}

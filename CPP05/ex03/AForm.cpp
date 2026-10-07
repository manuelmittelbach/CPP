#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("unknown name"), signature_given(0), sign_grade(1), execution_grade(1)
{
}

AForm::AForm(const std::string name, const int sign_grade, const int execution_grade) : name(name), signature_given(0), sign_grade(sign_grade), execution_grade(execution_grade)
{
	if (sign_grade < 1 || execution_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || execution_grade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &source) : name(source.name), signature_given(source.signature_given), sign_grade(source.sign_grade), execution_grade(source.execution_grade)
{
}

AForm &AForm::operator=(const AForm &source)
{
	this->signature_given = source.signature_given;
	return *this;
}

AForm::~AForm()
{
}

std::string AForm::getName() const
{
	return this->name;
}
bool AForm::getSignature_given() const
{
	return this->signature_given;
}
int AForm::getSign_grade() const
{
	return this->sign_grade;
}
int AForm::getExecution_grade() const
{
	return this->execution_grade;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "form is not signed";
}

void AForm::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() > this->sign_grade)
		throw GradeTooLowException();
	else if (obj.getGrade() <= this->sign_grade)
		signature_given = 1;
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
	os << "Form \"" << obj.getName() << "\", signed: "
	   << (obj.getSignature_given() ? "yes" : "no")
	   << ", sign grade: " << obj.getSign_grade()
	   << ", exec grade: " << obj.getExecution_grade();
	return os;
}

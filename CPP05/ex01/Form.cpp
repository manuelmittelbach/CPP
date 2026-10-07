#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("unknown name"), signature_given(0), sign_grade(1), execution_grade(1)
{
}

Form::Form(const std::string name, const int sign_grade, const int execution_grade) : name(name), signature_given(0), sign_grade(sign_grade), execution_grade(execution_grade)
{
	if (sign_grade < 1 || execution_grade < 1)
		throw GradeTooHighException();
	if (sign_grade > 150 || execution_grade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &source) : name(source.name), signature_given(source.signature_given), sign_grade(source.sign_grade), execution_grade(source.execution_grade)
{
}

Form &Form::operator=(const Form &source)
{
	this->signature_given = source.signature_given;
	return *this;
}

Form::~Form()
{
}

std::string Form::getName() const
{
	return this->name;
}
bool Form::getSignature_given() const
{
	return this->signature_given;
}
int Form::getSign_grade() const
{
	return this->sign_grade;
}
int Form::getExecution_grade() const
{
	return this->execution_grade;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

void Form::beSigned(const Bureaucrat &obj)
{
	if (obj.getGrade() > this->sign_grade)
		throw GradeTooLowException();
	else if (obj.getGrade() <= this->sign_grade)
		signature_given = 1;
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << "Form \"" << obj.getName() << "\", signed: "
	   << (obj.getSignature_given() ? "yes" : "no")
	   << ", sign grade: " << obj.getSign_grade()
	   << ", exec grade: " << obj.getExecution_grade();
	return os;
}
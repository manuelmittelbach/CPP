#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const Bureaucrat &source) : name(source.name), grade(source.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &source)
{
	this->grade = source.grade;
	return *this;
}

Bureaucrat::Bureaucrat() : name("unknown name"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < 1)
	{
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		throw GradeTooLowException();
	}
	else
		this->grade = grade;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

Bureaucrat::~Bureaucrat()
{
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

void Bureaucrat::increment()
{
	if (this->grade == 1)
		throw GradeTooHighException();
	else
		this->grade -= 1;
}
void Bureaucrat::decrement()
{
	if (this->grade == 150)
		throw GradeTooLowException();
	else
		this->grade += 1;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return os;
}

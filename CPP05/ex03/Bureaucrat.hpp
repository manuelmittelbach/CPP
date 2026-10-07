#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>

class AForm;

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &source);
	void increment();
	void decrement();
	Bureaucrat &operator=(const Bureaucrat &source);
	std::string getName() const;
	int getGrade() const;
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	void signForm(AForm &obj) const;
	void executeForm(AForm const &form) const;
};
std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif

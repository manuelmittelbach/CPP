#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool signature_given;
	const int sign_grade;
	const int execution_grade;

public:
	Form();
	Form(const std::string name, const int sign_grade, const int execution_grade);
	Form(const Form &source);
	Form &operator=(const Form &source);
	~Form();

	std::string getName() const;
	bool getSignature_given() const;
	int getSign_grade() const;
	int getExecution_grade() const;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw(); // noexcept
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw(); // noexcept
	};
	void beSigned(const Bureaucrat &obj);
};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif
#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool signature_given;
	const int sign_grade;
	const int execution_grade;

public:
	AForm();
	AForm(const std::string name, const int sign_grade, const int execution_grade);
	AForm(const AForm &source);
	AForm &operator=(const AForm &source);
	virtual ~AForm();

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
	class NotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw(); // noexcept
	};
	void beSigned(const Bureaucrat &obj);
	virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);

#endif

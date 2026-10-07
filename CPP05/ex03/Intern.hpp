#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern &source);
	Intern &operator=(const Intern &source);
	~Intern();

	AForm *makeForm(const std::string &formname, const std::string &formtarget);
};

#endif

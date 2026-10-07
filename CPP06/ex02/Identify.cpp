#include "Identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

/*
** Randomly instantiate A, B or C and return it through a Base pointer.
** We seed the random generator only once, the first time we are called.
*/
Base *generate(void)
{
	static bool seeded = false;

	if (!seeded)
	{
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		seeded = true;
	}

	switch (std::rand() % 3)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

/*
** Pointer version.
** dynamic_cast on a POINTER returns a valid pointer if the object really
** is of the target type, or NULL otherwise. So we simply try each type.
*/
void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

/*
** Reference version.
** Using a pointer here is forbidden, so we cannot rely on the NULL trick.
** dynamic_cast on a REFERENCE throws std::bad_cast when the object is not
** of the target type, so we probe each type inside a try/catch.
** We catch by std::exception& (from <exception>) so we never have to
** include the forbidden <typeinfo> header where std::bad_cast lives.
*/
void identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (std::exception &) {}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (std::exception &) {}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (std::exception &) {}

	std::cout << "Unknown" << std::endl;
}

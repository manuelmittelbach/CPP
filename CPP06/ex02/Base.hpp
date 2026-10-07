#ifndef BASE_HPP
#define BASE_HPP

/*
** A polymorphic base class: it has a public virtual destructor.
** The "virtual" is what enables dynamic_cast to work on Base pointers
** and references (a class needs at least one virtual function to be
** polymorphic).
*/
class Base
{
public:
	virtual ~Base();
};

#endif

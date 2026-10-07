#ifndef DATA_HPP
#define DATA_HPP

#include <string>

/*
** A non-empty data structure (it has data members), as required by the
** subject. Its content is arbitrary: it only exists so we have a real
** object whose address we can serialize and deserialize.
*/
struct Data
{
	int			id;
	std::string	name;
	double		value;
};

#endif

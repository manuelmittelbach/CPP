#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed()
{
	fixedPointNumberValue = 0;
	std::cout << "Default constructor called\n";

}

Fixed::Fixed(const Fixed& other)
{
	fixedPointNumberValue = other.fixedPointNumberValue;
	std::cout << "Copy constructor called\n";
}

Fixed& Fixed::operator=(const Fixed& other)
{
    if (this != &other) {  // Self-Assignment Check
        fixedPointNumberValue = other.fixedPointNumberValue;
    }
	std::cout << "Copy assignment operator called\n";
    return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return fixedPointNumberValue;
}

void Fixed::setRawBits( int const raw )
{
	fixedPointNumberValue = raw;
}
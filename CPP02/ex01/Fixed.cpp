#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
{
	fixedPointNumberValue = 0;
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int input)
{
	this->fixedPointNumberValue = input << fractionalBits;
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float f)
{
	this->fixedPointNumberValue = roundf(f * (1 << fractionalBits));
	std::cout << "Float constructor called\n";
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

float Fixed::toFloat( void ) const
{
	return (float)fixedPointNumberValue / (1 << fractionalBits);
}

int Fixed::toInt( void ) const
{
	return this->fixedPointNumberValue >> this->fractionalBits;
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

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return os;
}
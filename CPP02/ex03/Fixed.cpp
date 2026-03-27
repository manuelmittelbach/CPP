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

bool Fixed::operator>(const Fixed& other) const
{
    if (this->fixedPointNumberValue > other.fixedPointNumberValue)
		return true;
	else
		return false;
}

bool Fixed::operator<(const Fixed& other) const
{
    if (this->fixedPointNumberValue < other.fixedPointNumberValue)
		return true;
	else
		return false;
}

bool Fixed::operator>=(const Fixed& other) const
{
    if (this->fixedPointNumberValue >= other.fixedPointNumberValue)
		return true;
	else
		return false;
}

bool Fixed::operator<=(const Fixed& other) const
{
    if (this->fixedPointNumberValue <= other.fixedPointNumberValue)
		return true;
	else
		return false;
}

bool Fixed::operator==(const Fixed& other) const
{
    if (this->fixedPointNumberValue == other.fixedPointNumberValue)
		return true;
	else
		return false;
}

bool Fixed::operator!=(const Fixed& other) const
{
    if (this->fixedPointNumberValue != other.fixedPointNumberValue)
		return true;
	else
		return false;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	int i = this->fixedPointNumberValue + other.fixedPointNumberValue;
	Fixed output;
	output.fixedPointNumberValue = i;
	return output;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	int i = this->fixedPointNumberValue - other.fixedPointNumberValue;
	Fixed output;
	output.fixedPointNumberValue = i;
	return output;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed result;

    // 1. Mit großem Typ multiplizieren, um Overflow zu vermeiden
    long long tmp = (long long)this->fixedPointNumberValue * other.fixedPointNumberValue;

    // 2. Runterskalieren
    tmp = tmp >> this->fractionalBits;

    // 3. Ergebnis in das Fixed-Objekt speichern
    result.fixedPointNumberValue = (int)tmp;

    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed result;

    // 1. Hochskalieren, um die Fixed-Point Präzision zu behalten
    long long tmp = ((long long)this->fixedPointNumberValue << fractionalBits) / other.fixedPointNumberValue;

    // 2. Ergebnis speichern
    result.fixedPointNumberValue = (int)tmp;

    return result;
}

Fixed& Fixed::operator++()
{
	this->fixedPointNumberValue++;
	return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed old = *this;
    this->fixedPointNumberValue++;
    return old;
}

Fixed& Fixed::operator--()
{
	this->fixedPointNumberValue--;
	return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed old = *this;
    this->fixedPointNumberValue--;
    return old;
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

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a.fixedPointNumberValue < b.fixedPointNumberValue)
		return a;
	else 
		return b; 
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.fixedPointNumberValue < b.fixedPointNumberValue)
		return a;
	else 
		return b; 
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a.fixedPointNumberValue > b.fixedPointNumberValue)
		return a;
	else 
		return b; 
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.fixedPointNumberValue > b.fixedPointNumberValue)
		return a;
	else 
		return b; 
}

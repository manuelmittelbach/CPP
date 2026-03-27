#ifndef FIXED_HPP
#define FIXED_HPP

# include <ostream>
class Fixed
{
private:
	int fixedPointNumberValue;
	static const int fractionalBits = 8;
public:
	Fixed();
	Fixed(const int input);
	Fixed(const float f);
	Fixed(const Fixed& other);
	~Fixed();
	Fixed& operator=(const Fixed& other);
	float toFloat( void ) const;
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
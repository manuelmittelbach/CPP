#ifndef FIXED_HPP
#define FIXED_HPP

# include <ostream>
class Fixed
{
private:
	int fixedPointNumberValue;
	static const int fractionalBits = 8; // static means that this variable belongs to all objects of the class!
public:
	Fixed();
	Fixed(const int input); //const means: constructor doesnt change parameter!
	Fixed(const float f);
	Fixed(const Fixed& other);
	~Fixed();
	Fixed& operator=(const Fixed& other);
	float toFloat( void ) const; //const means: function doesnt change object!
	int toInt( void ) const;
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif
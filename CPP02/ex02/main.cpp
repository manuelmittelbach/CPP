#include "Fixed.hpp"
#include <iostream>

int main() {

    std::cout << "subject_tests:\n" << std::endl;
		Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << "\nmy_tests:\n" << std::endl;

	std::cout << "=== Constructors & Assignment ===" << std::endl;
    Fixed first;
    Fixed second(10);
    Fixed third(42.42f);
    Fixed fourth(second);
    first = Fixed(1234.4321f);

    std::cout << "first: " << first << std::endl;
    std::cout << "second: " << second << std::endl;
    std::cout << "third: " << third << std::endl;
    std::cout << "fourth: " << fourth << std::endl;

    std::cout << "\n=== Comparison Operators ===" << std::endl;
    std::cout << std::boolalpha; // print true/false
    std::cout << "first > second: " << (first > second) << std::endl;
    std::cout << "second < third: " << (second < third) << std::endl;
    std::cout << "second >= fourth: " << (second >= fourth) << std::endl;
    std::cout << "second <= fourth: " << (second <= fourth) << std::endl;
    std::cout << "second == fourth: " << (second == fourth) << std::endl;
    std::cout << "first != third: " << (first != third) << std::endl;

    std::cout << "\n=== Arithmetic Operators ===" << std::endl;
    Fixed sum = second + third;
    Fixed diff = third - second;
    Fixed prod = second * Fixed(2.5f);
    Fixed quot = third / Fixed(2);

    std::cout << "second + third: " << sum << std::endl;
    std::cout << "third - second: " << diff << std::endl;
    std::cout << "second * 2.5: " << prod << std::endl;
    std::cout << "third / 2: " << quot << std::endl;

    std::cout << "\n=== Increment/Decrement ===" << std::endl;
    Fixed counter;
    std::cout << "counter: " << counter << std::endl;
    std::cout << "++counter: " << ++counter << std::endl;
    std::cout << "counter: " << counter << std::endl;
    std::cout << "counter++: " << counter++ << std::endl;
    std::cout << "counter: " << counter << std::endl;
    std::cout << "--counter: " << --counter << std::endl;
    std::cout << "counter: " << counter << std::endl;
    std::cout << "counter--: " << counter-- << std::endl;
    std::cout << "counter: " << counter << std::endl;

    std::cout << "\n=== Min/Max Functions ===" << std::endl;
    Fixed& minRef = Fixed::min(first, second);
    const Fixed& minConst = Fixed::min(third, fourth);
    Fixed& maxRef = Fixed::max(first, second);
    const Fixed& maxConst = Fixed::max(third, fourth);

    std::cout << "min(first, second): " << minRef << std::endl;
    std::cout << "min(third, fourth): " << minConst << std::endl;
    std::cout << "max(first, second): " << maxRef << std::endl;
    std::cout << "max(third, fourth): " << maxConst << std::endl;

    std::cout << "\n=== Raw Bits / Conversion ===" << std::endl;
    std::cout << "first raw bits: " << first.getRawBits() << std::endl;
    std::cout << "first toInt(): " << first.toInt() << std::endl;
    std::cout << "first toFloat(): " << first.toFloat() << std::endl;
}
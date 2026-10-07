#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <climits>
#include <limits>
#include <cctype>
#include <sstream>

/*
** Special value codes used to keep track of the pseudo-literals.
** NONE    -> a regular, finite value
** NAN_V   -> nan / nanf
** POSINF  -> +inf / +inff
** NEGINF  -> -inf / -inff
*/
enum e_special
{
	NONE,
	NAN_V,
	POSINF,
	NEGINF
};

/* Orthodox Canonical Form (kept private, never used). */
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

/* ------------------------- type detection helpers ------------------------- */

static bool isCharLiteral(const std::string &s)
{
	// A single non-digit character, e.g. 'a' passed as: a
	if (s.length() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])))
		return true;
	// The quoted form, e.g. 'a'
	if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
		return true;
	return false;
}

static bool isIntLiteral(const std::string &s)
{
	size_t i = 0;

	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i == s.length())
		return false;
	while (i < s.length())
	{
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
		i++;
	}
	return true;
}

static bool isFloatLiteral(const std::string &s)
{
	if (s.length() < 2 || s[s.length() - 1] != 'f')
		return false;

	// Strip the trailing 'f' and validate the rest as a double.
	std::string body = s.substr(0, s.length() - 1);
	size_t i = 0;
	bool digit = false;
	bool dot = false;

	if (body[i] == '+' || body[i] == '-')
		i++;
	while (i < body.length())
	{
		if (std::isdigit(static_cast<unsigned char>(body[i])))
			digit = true;
		else if (body[i] == '.' && !dot)
			dot = true;
		else
			return false;
		i++;
	}
	return digit && dot;
}

static bool isDoubleLiteral(const std::string &s)
{
	size_t i = 0;
	bool digit = false;
	bool dot = false;

	if (s[i] == '+' || s[i] == '-')
		i++;
	while (i < s.length())
	{
		if (std::isdigit(static_cast<unsigned char>(s[i])))
			digit = true;
		else if (s[i] == '.' && !dot)
			dot = true;
		else
			return false;
		i++;
	}
	return digit && dot;
}

/* ------------------------------ printers --------------------------------- */

/*
** Turn a finite floating-point value into a string, making sure a whole
** number keeps a decimal part (42 -> "42.0"). We only add ".0" when the
** default formatting produced neither a dot nor a scientific exponent,
** so large numbers like 2.14748e+09 stay untouched.
*/
static std::string formatReal(double value)
{
	std::ostringstream oss;

	oss << value;
	std::string out = oss.str();
	if (out.find('.') == std::string::npos && out.find('e') == std::string::npos
		&& out.find('E') == std::string::npos)
		out += ".0";
	return out;
}

static void printChar(double value, int special)
{
	std::cout << "char: ";
	if (special != NONE || value < 0 || value > 127)
		std::cout << "impossible";
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(value) << "'";
	std::cout << std::endl;
}

static void printInt(double value, int special)
{
	std::cout << "int: ";
	if (special != NONE
		|| value < static_cast<double>(INT_MIN)
		|| value > static_cast<double>(INT_MAX))
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(value);
	std::cout << std::endl;
}

static void printFloat(double value, int special)
{
	std::cout << "float: ";
	if (special == NAN_V)
		std::cout << "nanf";
	else if (special == POSINF)
		std::cout << "+inff";
	else if (special == NEGINF)
		std::cout << "-inff";
	else
		std::cout << formatReal(static_cast<double>(static_cast<float>(value))) << "f";
	std::cout << std::endl;
}

static void printDouble(double value, int special)
{
	std::cout << "double: ";
	if (special == NAN_V)
		std::cout << "nan";
	else if (special == POSINF)
		std::cout << "+inf";
	else if (special == NEGINF)
		std::cout << "-inf";
	else
		std::cout << formatReal(value);
	std::cout << std::endl;
}

static void printImpossible()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

/* ------------------------------- convert --------------------------------- */

void ScalarConverter::convert(const std::string &literal)
{
	int special = NONE;
	double value = 0.0;

	if (literal == "nan" || literal == "nanf")
		special = NAN_V;
	else if (literal == "+inf" || literal == "+inff")
		special = POSINF;
	else if (literal == "-inf" || literal == "-inff")
		special = NEGINF;
	else if (isCharLiteral(literal))
	{
		char c = (literal.length() == 3) ? literal[1] : literal[0];
		value = static_cast<double>(c);
	}
	else if (isIntLiteral(literal) || isFloatLiteral(literal) || isDoubleLiteral(literal))
		value = std::strtod(literal.c_str(), NULL);
	else
	{
		printImpossible();
		return;
	}

	printChar(value, special);
	printInt(value, special);
	printFloat(value, special);
	printDouble(value, special);
}

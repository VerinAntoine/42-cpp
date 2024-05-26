#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <sys/errno.h>

static void convert(char c)
{
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << (int) c << std::endl;
	std::cout << "float: " << (int) c << ".0f" << std::endl;
	std::cout << "double: " << (int) c << ".0" << std::endl;
}

static void convert(int i)
{
	std::cout << "char: ";
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
		std::cout << "impossible" << std::endl;
	else if (isprint(i))
		std::cout << (char) i << std::endl;
	else
		std::cout << "non displayable" << std::endl;
	
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << i << ".0f" << std::endl;
	std::cout << "double: " << i << ".0" << std::endl;
}

static void convert(float f)
{
	std::cout << "char: ";
	if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max() || f - (int) f != 0)
		std::cout << "impossible" << std::endl;
	else if (isprint(f))
		std::cout << (char) f << std::endl;
	else
		std::cout << "non displayable" << std::endl;
	
	std::cout << "int: ";
	if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << (int) f << std::endl;
	
	std::cout << "float: " << f;
	if (f - (int) f == 0)
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;

	double d = f;
	std::cout << "double: " << d;
	if (d - (int) d == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

static void convert(double d)
{
	std::cout << "char: ";
	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max() || d - (int) d != 0)
		std::cout << "impossible" << std::endl;
	else if (isprint(d))
		std::cout << (char) d << std::endl;
	else
		std::cout << "non displayable" << std::endl;
	
	std::cout << "int: ";
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "impossible" << std::endl;
	else
		std::cout << (int) d << std::endl;
	
	std::cout << "float: ";
	if (d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max())
		std::cout << "impossible" << std::endl;
	else
	{
		float f = d;
		std::cout << f;
		if (f - (int) f == 0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}

	std::cout << "double: " << d;
	if (d - (int) d == 0)
		std::cout << ".0";
	std::cout << std::endl;
}

static void convertPseudo(const std::string &literal)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	std::cout << "float: ";
	if (literal == "-inf" || literal == "-inff")
		std::cout << "-inff";
	else if (literal == "+inf" || literal == "+inff")
		std::cout << "+inff";
	else
		std::cout << "nanf";
	std::cout << std::endl;

	std::cout << "double: ";
	if (literal == "-inf" || literal == "-inff")
		std::cout << "-inf";
	else if (literal == "+inf" || literal == "+inff")
		std::cout << "+inf";
	else
		std::cout << "nan";
	std::cout << std::endl;
}

static void fromChar(const std::string &literal)
{
	if (literal.size() == 1 && isalpha(literal[0]))
		convert((char) literal[0]);
}

static void fromInt(const std::string &literal)
{
	if (literal.size() == 0)
		return ;
	for (size_t i = literal[0] == '-' ? 1 : 0; i < literal.size(); i++)
	{
		if (!isdigit(literal[i]))
			return ;
	}

	char *end;
	long i = strtol(literal.c_str(), &end, 10);
	if (*end != 0 || i > 2147483647 || i < -2147483648 || literal.size() > 11)
		return ;
	convert((int) i);
}

static void fromFloat(const std::string &literal)
{
	if (literal.find('.') == std::string::npos)
		return ;
	if (literal.find('f') == std::string::npos)
		return ;

	char *end;
	float f = strtof(literal.c_str(), &end);
	if (errno == ERANGE || *end != 'f' || *(end + 1) != 0)
		return ;
	convert(f);
}

static void fromDouble(const std::string &literal)
{
	if (literal.find('.') == std::string::npos)
		return ;
	
	char *end;
	double d = strtod(literal.c_str(), &end);
	if (errno == ERANGE || *end != 0)
		return ;
	convert(d);
}

static void fromPseudo(const std::string &literal)
{
	if (!(literal == "-inff" || literal == "+inff" || literal == "-inf" || literal == "+inf" || literal == "nan"))
		return ;
	convertPseudo(literal);
}

void ScalarConverter::convert(const std::string &literal)
{
	fromChar(literal);
	fromInt(literal);
	fromFloat(literal);
	fromDouble(literal);
	fromPseudo(literal);
}

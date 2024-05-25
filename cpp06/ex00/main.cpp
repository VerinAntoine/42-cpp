#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
	if (argc != 2)
		std::cout << argv[0] << " <literal>" << std::endl;
	ScalarConverter::convert(argv[1]);

	// ScalarConverter a;

	return 0;
}

#include "RPN.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << argv[0] << " <input>" << std::endl;
		return 1;
	}

	try {
		RPN rpn;
		std::cout << rpn.process(argv[1]) << std::endl;
	} catch (RPN::InvalidInputException &e) {
		std::cout << "invalid input" << std::endl;
	}

	return 0;
}

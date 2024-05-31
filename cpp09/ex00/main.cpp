#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << argv[0] << " <file>" << std::endl;
		return 1;
	}

	try {
		BitcoinExchange exchange(argv[1]);
	} catch(BitcoinExchange::InvalidFileException &e) {
		std::cout << "invalid file" << std::endl;
	}

	return 0;
}

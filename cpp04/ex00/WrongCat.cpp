#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal()
{
	*this = other;
	std::cout << "WrongCat copied" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructed" << std::endl;
}

void WrongCat::makeSound()
{
	std::cout << "MIAOU" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat& other)
{
	(void) other;
	return *this;
}

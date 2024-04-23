#include "Cat.hpp"

Cat::Cat(): Animal()
{
	this->type = "Cat";
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other): Animal()
{
	*this = other;
	std::cout << "Cat copied" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destructed" << std::endl;
}

void Cat::makeSound()
{
	std::cout << "MIAOU" << std::endl;
}

Cat &Cat::operator=(const Cat& other)
{
	(void) other;
	return *this;
}

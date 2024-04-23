#include "Cat.hpp"

Cat::Cat(): Animal()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(const Cat& other): Animal()
{
	*this = other;
	std::cout << "Cat copied" << std::endl;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructed" << std::endl;
}

void Cat::makeSound()
{
	std::cout << "MIAOU" << std::endl;
}

Cat &Cat::operator=(const Cat& other)
{
	if (this == &other)
		return *this;
	delete this->brain;
	this->brain = other.brain;
	return *this;
}
